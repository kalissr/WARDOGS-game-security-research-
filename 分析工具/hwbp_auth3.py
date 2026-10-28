#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
hwbp_auth3.py — Windows 硬件调试断点 (Dr0-Dr7) 抓取 KR loader auth3 解密明文
================================================================================
原理:
  Agent T 审计 (anti_debug_audit.txt [D3]) 证实: loader 无任何 CONTEXT 调试寄存器
  检测 (GetThreadContext(self) 0 命中), 且 ring3 无法读写 DR 寄存器 (特权指令),
  VMP 也不可能直接清 DR → 硬件断点是当前唯一安全的观测手段。
  本脚本不注入、不 inline hook、不改一个字节的目标内存, 纯寄存器级观测。

断点分配:
  DR0 = user32!MessageBoxW 入口 (执行)   —— 黑名单/过期弹窗必经之路,
         x64 调用约定: RCX=hWnd, RDX=lpText, R8=lpCaption, R9=uType
         → 命中瞬间直接读 RDX/R8 得弹窗全文, [RSP]=VMP 段内返回地址。
  DR1 = 主模块 base + RVA 0x617ad0 (执行) —— 退出码计算器入口。
  DR2 = 可选 (--write-addr), 数据写断点 (观察解密缓冲被写入的瞬间)。

时序说明 ("等 auth_web 请求" 的等效实现):
  硬件断点只在地址被访问时触发, 提前武装零副作用; 而所有新线程 (含 auth worker
  线程) 都会报告 CREATE_THREAD_DEBUG_EVENT, 我们在每个新线程上重新武装同一组 DR。
  因此在 user32 加载后立即武装 = 与"等 auth_web 时再武装"完全等效, 且无竞态。

堆缓冲地址漂移对策:
  历史观测解密缓冲 W 位于低地址堆 (0x595f10 / 0x6d6520 / 0x6d6a70 / 0x6d6fc0),
  会话间会漂移。断点命中时:
    1) 定点 dump 全部历史地址 ±512B;
    2) VirtualQueryEx 全扫低地址堆 0x100000-0x4000000, 整体 dump 到 bin + map,
       并提取 UTF-16LE / ASCII 字符串 (JSON 字段名 / 中文判定语), 兜底定位漂移后
       的明文副本 (已知应有 3 份)。

输出:
  hwbp_result.txt            — 命中记录 (寄存器/栈/字符串/判定字段线索)
  hwbp_heap_dump_hit<N>.bin  — 低地址堆原始快照 (离线分析)
  hwbp_heap_map_hit<N>.txt   — bin 内各 region 的 VA 映射表
  hwbp_strings_hit<N>.txt    — 全量提取字符串 (带 VA)
================================================================================
"""

import argparse
import ctypes
import datetime
import os
import re
import signal
import struct
import subprocess
import sys
import threading
import time
from ctypes import wintypes

# ---------------------------------------------------------------- 基础常量 ----
kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)
psapi    = ctypes.WinDLL("psapi",    use_last_error=True)

DEBUG_PROCESS             = 0x00000001
DEBUG_ONLY_THIS_PROCESS   = 0x00000002
INFINITE                  = 0xFFFFFFFF

DBG_CONTINUE              = 0x00010002
DBG_EXCEPTION_NOT_HANDLED = 0x80010001

# DEBUG_EVENT codes
EXCEPTION_DEBUG_EVENT      = 1
CREATE_THREAD_DEBUG_EVENT  = 2
CREATE_PROCESS_DEBUG_EVENT = 3
EXIT_THREAD_DEBUG_EVENT    = 4
LOAD_DLL_DEBUG_EVENT       = 5
UNLOAD_DLL_DEBUG_EVENT     = 6
OUTPUT_DEBUG_STRING_EVENT  = 7
EXIT_PROCESS_DEBUG_EVENT   = 8
RIP_EVENT                  = 9

STATUS_BREAKPOINT    = 0x80000003
STATUS_SINGLE_STEP   = 0x80000004
STATUS_ACCESS_VIOLATION = 0xC0000005

EXCEPTION_MAXIMUM_PARAMETERS = 15

# page protection (readable)
PAGE_READABLE = {0x02, 0x04, 0x08, 0x20, 0x40, 0x80}  # RO / RW / WC / ER / ERW / WCM
MEM_COMMIT = 0x1000

TH32CS_SNAPTHREAD = 0x00000004

# CONTEXT_AMD64 flag combos
CONTEXT_AMD64          = 0x00100000
CONTEXT_CONTROL        = CONTEXT_AMD64 | 0x00000001
CONTEXT_INTEGER        = CONTEXT_AMD64 | 0x00000002
CONTEXT_SEGMENTS       = CONTEXT_AMD64 | 0x00000004
CONTEXT_FLOATING_POINT = CONTEXT_AMD64 | 0x00000008
CONTEXT_DEBUG_REGISTERS= CONTEXT_AMD64 | 0x00000010
CONTEXT_FULL           = (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)

# DR7 helper: rw: 0=exec 1=write 3=rw ; ln: 0=1B 1=2B 2=8B 3=4B (exec 必须 0)
def build_dr7(slots):
    v = 0
    for i, slot in enumerate(slots):
        if slot is None:
            continue
        rw, ln = slot
        v |= (1 << (2 * i))            # Li  local enable
        v |= (rw & 3) << (16 + 4 * i)  # R/Wi
        v |= (ln & 3) << (18 + 4 * i)  # LENi
    return v

# ---------------------------------------------------------------- 结构体 ----
class STARTUPINFOW(ctypes.Structure):
    _fields_ = [("cb", wintypes.DWORD),
                ("lpReserved", wintypes.LPWSTR),
                ("lpDesktop", wintypes.LPWSTR),
                ("lpTitle", wintypes.LPWSTR),
                ("dwX", wintypes.DWORD),
                ("dwY", wintypes.DWORD),
                ("dwXSize", wintypes.DWORD),
                ("dwYSize", wintypes.DWORD),
                ("dwXCountChars", wintypes.DWORD),
                ("dwYCountChars", wintypes.DWORD),
                ("dwFillAttribute", wintypes.DWORD),
                ("dwFlags", wintypes.DWORD),
                ("wShowWindow", wintypes.WORD),
                ("cbReserved2", wintypes.WORD),
                ("lpReserved2", ctypes.c_void_p),
                ("hStdInput", wintypes.HANDLE),
                ("hStdOutput", wintypes.HANDLE),
                ("hStdError", wintypes.HANDLE)]

class PROCESS_INFORMATION(ctypes.Structure):
    _fields_ = [("hProcess", wintypes.HANDLE),
                ("hThread", wintypes.HANDLE),
                ("dwProcessId", wintypes.DWORD),
                ("dwThreadId", wintypes.DWORD)]

class EXCEPTION_RECORD64(ctypes.Structure):
    _fields_ = [("ExceptionCode", wintypes.DWORD),
                ("ExceptionFlags", wintypes.DWORD),
                ("ExceptionRecord", ctypes.c_void_p),
                ("ExceptionAddress", ctypes.c_void_p),
                ("NumberParameters", wintypes.DWORD),
                ("__pad", wintypes.DWORD),
                ("ExceptionInformation", ctypes.c_uint64 * EXCEPTION_MAXIMUM_PARAMETERS)]

class EXCEPTION_DEBUG_INFO(ctypes.Structure):
    _fields_ = [("ExceptionRecord", EXCEPTION_RECORD64),
                ("dwFirstChance", wintypes.DWORD)]

class CREATE_THREAD_DEBUG_INFO(ctypes.Structure):
    _fields_ = [("hThread", wintypes.HANDLE),
                ("lpThreadLocalBase", ctypes.c_void_p),
                ("lpStartAddress", ctypes.c_void_p)]

class CREATE_PROCESS_DEBUG_INFO(ctypes.Structure):
    _fields_ = [("hFile", wintypes.HANDLE),
                ("hProcess", wintypes.HANDLE),
                ("hThread", wintypes.HANDLE),
                ("lpBaseOfImage", ctypes.c_void_p),
                ("dwDebugInfoFileOffset", wintypes.DWORD),
                ("nDebugInfoSize", wintypes.DWORD),
                ("lpThreadLocalBase", ctypes.c_void_p),
                ("lpStartAddress", ctypes.c_void_p),
                ("lpImageName", ctypes.c_void_p),
                ("fUnicode", wintypes.WORD)]

class EXIT_THREAD_DEBUG_INFO(ctypes.Structure):
    _fields_ = [("dwExitCode", wintypes.DWORD)]

class EXIT_PROCESS_DEBUG_INFO(ctypes.Structure):
    _fields_ = [("dwExitCode", wintypes.DWORD)]

class LOAD_DLL_DEBUG_INFO(ctypes.Structure):
    _fields_ = [("hFile", wintypes.HANDLE),
                ("lpBaseOfDll", ctypes.c_void_p),
                ("dwDebugInfoFileOffset", wintypes.DWORD),
                ("nDebugInfoSize", wintypes.DWORD),
                ("lpImageName", ctypes.c_void_p),
                ("fUnicode", wintypes.WORD)]

class UNLOAD_DLL_DEBUG_INFO(ctypes.Structure):
    _fields_ = [("lpBaseOfDll", ctypes.c_void_p)]

class OUTPUT_DEBUG_STRING_INFO(ctypes.Structure):
    _fields_ = [("lpDebugStringData", ctypes.c_void_p),
                ("fUnicode", wintypes.WORD),
                ("wDebugStringLength", wintypes.WORD)]

class RIP_INFO(ctypes.Structure):
    _fields_ = [("dwError", wintypes.DWORD),
                ("dwType", wintypes.DWORD)]

class _DEBUG_UNION(ctypes.Union):
    _fields_ = [("Exception", EXCEPTION_DEBUG_INFO),
                ("CreateThread", CREATE_THREAD_DEBUG_INFO),
                ("CreateProcessInfo", CREATE_PROCESS_DEBUG_INFO),
                ("ExitThread", EXIT_THREAD_DEBUG_INFO),
                ("ExitProcess", EXIT_PROCESS_DEBUG_INFO),
                ("LoadDll", LOAD_DLL_DEBUG_INFO),
                ("UnloadDll", UNLOAD_DLL_DEBUG_INFO),
                ("DebugString", OUTPUT_DEBUG_STRING_INFO),
                ("RipInfo", RIP_INFO)]

class DEBUG_EVENT(ctypes.Structure):
    _fields_ = [("dwDebugEventCode", wintypes.DWORD),
                ("dwProcessId", wintypes.DWORD),
                ("dwThreadId", wintypes.DWORD),
                ("u", _DEBUG_UNION)]

# --- x64 CONTEXT (总长 0x4D0, 偏移必须与 winnt.h 一致) ---
class M128A(ctypes.Structure):
    _fields_ = [("Low", ctypes.c_uint64), ("High", ctypes.c_int64)]

class XSAVE_FORMAT(ctypes.Structure):
    _fields_ = [("ControlWord", wintypes.WORD), ("StatusWord", wintypes.WORD),
                ("TagByte", ctypes.c_ubyte * 8),
                ("ErrorOpcode", wintypes.WORD),
                ("ErrorOffset", wintypes.DWORD),
                ("ErrorSelector", wintypes.WORD), ("Reserved", wintypes.WORD),
                ("DataOffset", wintypes.DWORD),
                ("DataSelector", wintypes.WORD), ("Reserved1", wintypes.WORD),
                ("MxCsr", wintypes.DWORD), ("MxCsr_Mask", wintypes.DWORD),
                ("FloatRegisters", M128A * 8),
                ("XmmRegisters", M128A * 16),
                ("Reserved4", ctypes.c_ubyte * 96)]

class CONTEXT(ctypes.Structure):
    _fields_ = [
        ("P1Home", ctypes.c_uint64), ("P2Home", ctypes.c_uint64),
        ("P3Home", ctypes.c_uint64), ("P4Home", ctypes.c_uint64),
        ("P5Home", ctypes.c_uint64), ("P6Home", ctypes.c_uint64),
        ("ContextFlags", wintypes.DWORD),          # 0x030
        ("MxCsr", wintypes.DWORD),                 # 0x034
        ("SegCs", wintypes.WORD), ("SegDs", wintypes.WORD),
        ("SegEs", wintypes.WORD), ("SegFs", wintypes.WORD),
        ("SegGs", wintypes.WORD), ("SegSs", wintypes.WORD),
        ("EFlags", wintypes.DWORD),                # 0x044
        ("Dr0", ctypes.c_uint64),                  # 0x048
        ("Dr1", ctypes.c_uint64),                  # 0x050
        ("Dr2", ctypes.c_uint64),                  # 0x058
        ("Dr3", ctypes.c_uint64),                  # 0x060
        ("Dr6", ctypes.c_uint64),                  # 0x068
        ("Dr7", ctypes.c_uint64),                  # 0x070
        ("Rax", ctypes.c_uint64), ("Rcx", ctypes.c_uint64),
        ("Rdx", ctypes.c_uint64), ("Rbx", ctypes.c_uint64),
        ("Rsp", ctypes.c_uint64), ("Rbp", ctypes.c_uint64),
        ("Rsi", ctypes.c_uint64), ("Rdi", ctypes.c_uint64),
        ("R8",  ctypes.c_uint64), ("R9",  ctypes.c_uint64),
        ("R10", ctypes.c_uint64), ("R11", ctypes.c_uint64),
        ("R12", ctypes.c_uint64), ("R13", ctypes.c_uint64),
        ("R14", ctypes.c_uint64), ("R15", ctypes.c_uint64),
        ("Rip", ctypes.c_uint64),                  # 0x0F8
        ("FltSave", XSAVE_FORMAT),                 # 0x100
        ("VectorRegister", M128A * 26),            # 0x300
        ("VectorControl", ctypes.c_uint64),
        ("DebugControl", ctypes.c_uint64),
        ("LastBranchToRip", ctypes.c_uint64),
        ("LastBranchFromRip", ctypes.c_uint64),
        ("LastExceptionToRip", ctypes.c_uint64),
        ("LastExceptionFromRip", ctypes.c_uint64),
    ]

assert ctypes.sizeof(DEBUG_EVENT) == 176, f"DEBUG_EVENT size {ctypes.sizeof(DEBUG_EVENT)}"
# 注意: FltSave 尾部与 winnt.h 有 8 字节 pad 差异 (0x4D8 vs 0x4D0), 但内核消费的
# Dr0-Dr7 (0x48-0x77) / GPR (0x78-0xF7) / Rip (0xF8) 均在 0x100 之前, 偏移完全一致;
# FltSave 容量 0x208 >= 0x200 也容纳内核写入, 无碍。
assert ctypes.sizeof(CONTEXT) >= 0x4D0 and \
       (CONTEXT.Dr0.offset, CONTEXT.Rip.offset, CONTEXT.Rsp.offset) == (0x48, 0xF8, 0x98), \
       f"CONTEXT layout bad: size={hex(ctypes.sizeof(CONTEXT))} " \
       f"Dr0={hex(CONTEXT.Dr0.offset)} Rip={hex(CONTEXT.Rip.offset)}"

class THREADENTRY32(ctypes.Structure):
    _fields_ = [("dwSize", wintypes.DWORD),
                ("cntUsage", wintypes.DWORD),
                ("th32ThreadID", wintypes.DWORD),
                ("th32OwnerProcessID", wintypes.DWORD),
                ("tpDeltaPri", ctypes.c_long),
                ("tpPri", ctypes.c_long)]

# ---------------------------------------------------------------- 日志 ----
class Log:
    def __init__(self, path):
        self.fh = open(path, "w", encoding="utf-8", errors="replace")
        self.lock = threading.Lock()
    def w(self, s=""):
        with self.lock:
            try:
                sys.stdout.write(s + "\n")
                sys.stdout.flush()
            except Exception:
                pass
            self.fh.write(s + "\n")
            self.fh.flush()
    def close(self):
        self.fh.close()

# ---------------------------------------------------------------- 工具 ----
def hexdump(buf, base, width=16):
    out = []
    for off in range(0, len(buf), width):
        chunk = buf[off:off + width]
        hx = " ".join(f"{b:02X}" for b in chunk)
        asc = "".join(chr(b) if 0x20 <= b < 0x7F else "." for b in chunk)
        out.append(f"  {base + off:012X}  {hx:<{width*3}} {asc}")
    return "\n".join(out)

def sym(arm, base, base_hi):
    """VA → RVA 标注 (落在主模块内时)"""
    if base and base <= arm < base_hi:
        return f" (exe+0x{arm - base:X})"
    return ""

# ---------------------------------------------------------------- 主调试器 ----
class HwbpDebugger:
    def __init__(self, args, log: Log):
        self.args = args
        self.log = log
        self.hProcess = None
        self.pid = None
        self.image_base = None
        self.image_size = 0x7000000          # dump 实测 ~112MB 内视为主模块
        self.rva_exit_calc = args.rva2
        self.msgbox_w = None                # user32!MessageBoxW VA (同会话系统 DLL 基址一致)
        self.dr_slots = [None, None, None, None]  # (rw, ln) per DR
        self.dr_names = ["", "", "", ""]
        self.hit_counts = {}
        self.hit_dumped = set()
        self.stop_evt = threading.Event()
        self.exit_code = None
        self.dll_seen = {}
        self.known_heap_addrs = [0x595f10, 0x6d6520, 0x6d6a70, 0x6d6fc0]
        self.start_time = time.time()

    # ---------- 目标进程内存原语 ----------
    def rpm(self, addr, size):
        buf = ctypes.create_string_buffer(size)
        got = ctypes.c_size_t(0)
        ok = kernel32.ReadProcessMemory(self.hProcess, ctypes.c_void_p(addr),
                                        buf, size, ctypes.byref(got))
        return buf.raw[:got.value] if ok and got.value else b""

    def read_wstr(self, addr, maxc=512):
        if not addr:
            return None
        raw = self.rpm(addr, maxc * 2)
        if not raw:
            return None
        out = []
        for i in range(0, len(raw) - 1, 2):
            ch = raw[i] | (raw[i + 1] << 8)
            if ch == 0:
                break
            out.append(chr(ch))
        return "".join(out)

    def readable(self, addr):
        mbi = MEMORY_BASIC_INFORMATION()
        got = ctypes.windll.kernel32.VirtualQueryEx(self.hProcess,
                                                    ctypes.c_void_p(addr),
                                                    ctypes.byref(mbi),
                                                    ctypes.sizeof(mbi))
        if not got:
            return False
        return (mbi.State == MEM_COMMIT and
                (mbi.Protect & 0xFF) in PAGE_READABLE)

    # ---------- DR 武装 ----------
    def recompute_dr7(self):
        return build_dr7(self.dr_slots)

    def arm_thread(self, hThread, label=""):
        """在线程上写入当前 DR 配置 (线程需处于挂起态: 调试事件线程/已 Suspend)"""
        ctx = CONTEXT()
        ctx.ContextFlags = CONTEXT_AMD64 | CONTEXT_DEBUG_REGISTERS
        addrs = [self.msgbox_w,
                 (self.image_base + self.rva_exit_calc) if self.image_base else None,
                 (self.args.write_addr if self.args.write_addr else None),
                 None]
        for i, a in enumerate(addrs):
            if a:
                setattr(ctx, f"Dr{i}", a)
                self.dr_slots[i] = (1, self.args.write_len) if i == 2 else (0, 0)
                if not self.dr_names[i]:
                    self.dr_names[i] = (f"WRITE@{a:#x}" if i == 2 else
                                        ("MessageBoxW" if i == 0 else f"exe+0x{self.rva_exit_calc:X}"))
        ctx.Dr7 = self.recompute_dr7()
        if not kernel32.SetThreadContext(hThread, ctypes.byref(ctx)):
            self.log.w(f"[!!] SetThreadContext 失败 err={ctypes.get_last_error()} ({label})")
            return False
        # 回读验证
        chk = CONTEXT()
        chk.ContextFlags = CONTEXT_AMD64 | CONTEXT_DEBUG_REGISTERS
        ok = kernel32.GetThreadContext(hThread, ctypes.byref(chk))
        got = f"Dr0={chk.Dr0:#x} Dr1={chk.Dr1:#x} Dr2={chk.Dr2:#x} Dr7={chk.Dr7:#x}" if ok else "回读失败"
        self.log.w(f"[DR] 武装线程 h={hThread:#x} {label} → {got}")
        return True

    def freeze_all_threads(self, exclude_tid):
        """断点命中后冻结目标进程其余线程, 保证堆快照原子性。返回 [(tid,h)]"""
        frozen = []
        snap = kernel32.CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0)
        if snap == ctypes.c_void_p(-1).value or snap == -1:
            return frozen
        te = THREADENTRY32()
        te.dwSize = ctypes.sizeof(te)
        ok = kernel32.Thread32First(snap, ctypes.byref(te))
        while ok:
            if te.th32OwnerProcessID == self.pid and te.th32ThreadID != exclude_tid:
                h = kernel32.OpenThread(0x0002 | 0x1000, False, te.th32ThreadID)  # SUSPEND_RESUME|QUERY
                if h:
                    prev = kernel32.SuspendThread(h)
                    if prev != 0xFFFFFFFF:
                        frozen.append((te.th32ThreadID, h))
                    else:
                        kernel32.CloseHandle(h)
            ok = kernel32.Thread32Next(snap, ctypes.byref(te))
        kernel32.CloseHandle(snap)
        return frozen

    def thaw_all(self, frozen):
        for tid, h in frozen:
            kernel32.ResumeThread(h)
            kernel32.CloseHandle(h)

    # ---------- DLL 名解析 ----------
    def dll_name_from_event(self, ev):
        """lpImageName 双重间接: 目标VA → 字符串指针 → 字符串"""
        info = ev.u.LoadDll
        try:
            if info.lpImageName:
                ptrbuf = ctypes.create_string_buffer(8)
                got = ctypes.c_size_t(0)
                if kernel32.ReadProcessMemory(self.hProcess, ctypes.c_void_p(info.lpImageName),
                                              ptrbuf, 8, ctypes.byref(got)) and got.value == 8:
                    strptr = struct.unpack("<Q", ptrbuf.raw)[0]
                    if strptr:
                        raw = self.rpm(strptr, 1048)
                        if raw:
                            if info.fUnicode:
                                return raw.decode("utf-16-le", errors="ignore").split("\x00")[0]
                            return raw.split(b"\x00")[0].decode("ascii", errors="ignore")
        except Exception:
            pass
        # 备用: PSAPI GetModuleFileNameExW
        buf = ctypes.create_unicode_buffer(2048)
        if psapi.GetModuleFileNameExW(self.hProcess, ctypes.c_void_p(info.lpBaseOfDll or 0),
                                      buf, 2048):
            return buf.value
        return None

    # ---------- 事件处理 ----------
    def on_create_process(self, ev):
        info = ev.u.CreateProcessInfo
        self.hProcess = info.hProcess
        self.pid = ev.dwProcessId
        self.image_base = info.lpBaseOfImage or 0
        self.log.w(f"[P] CREATE_PROCESS pid={self.pid} 主模块基址={self.image_base:#x} "
                   f"线程 tid={ev.dwThreadId}")
        # 系统 DLL 在同一次引导会话内基址全局一致 → 调试器进程 GetProcAddress 的
        # 结果即目标进程内 VA。立即武装主线程 (断点提前武装零副作用)。
        try:
            u32 = ctypes.WinDLL("user32")
            self.msgbox_w = ctypes.cast(u32.MessageBoxW, ctypes.c_void_p).value
        except Exception as e:
            self.log.w(f"[!!] 取 MessageBoxW 地址失败: {e}")
        self.log.w(f"[DR] 计划: DR0={self.msgbox_w:#x} (MessageBoxW, exec)  "
                   f"DR1={self.image_base + self.rva_exit_calc:#x} (exe+0x{self.rva_exit_calc:X}, exec)"
                   + (f"  DR2={self.args.write_addr:#x} (write,{1 << self.args.write_len}B)"
                      if self.args.write_addr else ""))
        if info.hThread:
            self.arm_thread(info.hThread, "主线程")
        # 验证: user32 是否已在目标进程映射 (此刻通常还没有, 壳未跑)
        if self.msgbox_w and not self.readable(self.msgbox_w):
            self.log.w("[i] user32 尚未映射 (壳未运行) — VA 由系统会话基址保证, 无碍")

    def on_load_dll(self, ev):
        info = ev.u.LoadDll
        name = self.dll_name_from_event(ev)
        base = info.lpBaseOfDll or 0
        if name:
            self.dll_seen[base] = name
        short = os.path.basename(name or "?")
        if short.lower() in ("user32.dll", "user32.dll."):
            self.log.w(f"[DLL] user32.dll base={base:#x}")
            if self.msgbox_w and base <= self.msgbox_w < base + 0x200000:
                # 交叉验证: 解析目标进程内导出表确认 MessageBoxW RVA
                target = self.resolve_export(base, b"MessageBoxW")
                if target:
                    agree = "== 与调试器侧一致" if target == self.msgbox_w else "!! 不一致, 采用导出表值"
                    self.log.w(f"[DLL] 导出表验证: user32!MessageBoxW = {target:#x} {agree}")
                    self.msgbox_w = target
        if info.hFile:
            kernel32.CloseHandle(info.hFile)

    def resolve_export(self, dll_base, func_name: bytes):
        """解析目标进程内已映射 DLL 的导出表, 返回函数 VA (失败返回 None)"""
        try:
            dos = self.rpm(dll_base, 0x40)
            if dos[:2] != b"MZ":
                return None
            e_lfanew = struct.unpack("<I", dos[0x3C:0x40])[0]
            hdr = self.rpm(dll_base + e_lfanew, 0x18 + 0x70 + 4)
            if hdr[:4] != b"PE\x00\x00":
                return None
            exp_rva = struct.unpack("<I", hdr[0x18 + 0x70:0x18 + 0x74])[0]
            if not exp_rva:
                return None
            ed = self.rpm(dll_base + exp_rva, 0x28)
            n_names = struct.unpack("<I", ed[0x18:0x1C])[0]
            rva_names = struct.unpack("<I", ed[0x20:0x24])[0]
            rva_ords  = struct.unpack("<I", ed[0x24:0x28])[0]
            rva_funcs = struct.unpack("<I", ed[0x1C:0x20])[0]
            names_blob = self.rpm(dll_base + rva_names, n_names * 8)
            for i in range(n_names):
                nrva = struct.unpack("<Q", names_blob[i * 8:(i + 1) * 8])[0]
                s = self.rpm(dll_base + nrva, 40).split(b"\x00")[0]
                if s == func_name:
                    ob = self.rpm(dll_base + rva_ords + i * 2, 2)
                    ordinal = struct.unpack("<H", ob)[0]
                    fb = self.rpm(dll_base + rva_funcs + ordinal * 4, 4)
                    return dll_base + struct.unpack("<I", fb)[0]
        except Exception:
            pass
        return None

    def on_create_thread(self, ev):
        info = ev.u.CreateThread
        self.log.w(f"[T] CREATE_THREAD tid={ev.dwThreadId} start={info.lpStartAddress:#x}"
                   f"{sym(info.lpStartAddress or 0, self.image_base, self.image_base + self.image_size)}")
        if info.hThread:
            self.arm_thread(info.hThread, f"新线程 tid={ev.dwThreadId}")

    def which_bp(self, dr6, addr):
        for i in range(4):
            if dr6 & (1 << i):
                return i
        return None

    def on_exception(self, ev):
        rec = ev.u.Exception.ExceptionRecord
        first = ev.u.Exception.dwFirstChance
        code = rec.ExceptionCode & 0xFFFFFFFF
        addr = rec.ExceptionAddress or 0

        if code == STATUS_BREAKPOINT:
            # 初始断点(壳入口前) 或目标自身 int3 → 交给目标 SEH (除非首次系统断点)
            self.log.w(f"[X] int3 @ {addr:#x} first={first} → "
                       + ("DBG_CONTINUE (系统初始断点)" if first else "NOT_HANDLED"))
            return DBG_CONTINUE if first else DBG_EXCEPTION_NOT_HANDLED

        if code == STATUS_SINGLE_STEP:
            # ---- VMP 异常驱动 VM 洪泛识别 (实测: VMP 用 DR0 驱动变异流) ----
            # 触发地址不是我们设的断点地址 → 是 VMP 自身 #DB, 静默快速放行。
            our_addrs = {a for a in (self.msgbox_w,
                                     (self.image_base + self.rva_exit_calc) if self.image_base else None,
                                     self.args.write_addr) if a}
            if addr not in our_addrs:
                self.flood_n = getattr(self, "flood_n", 0) + 1
                if self.flood_n == 1 or self.flood_n % 20000 == 0:
                    self.log.w(f"[~] VMP #DB 洪泛 (非我方断点, 静默放行) 累计 {self.flood_n} 次 "
                               f"@ {addr:#x} tid={ev.dwThreadId}")
                return DBG_CONTINUE
            ctx = self.get_ctx_now(ev.dwThreadId)
            dr6 = ctx.Dr6 if ctx else 0
            idx = self.which_bp(dr6, addr)
            name = self.dr_names[idx] if (idx is not None and idx < 4) else "?"
            key = (idx, addr)
            n = self.hit_counts.get(key, 0) + 1
            self.hit_counts[key] = n
            self.log.w(f"[★] 硬件断点命中 #{n}: DR{idx} ({name}) @ {addr:#x}"
                       f"{sym(addr, self.image_base, self.image_base + self.image_size)}"
                       f" tid={ev.dwThreadId} Dr6={dr6:#x}")
            if n <= self.args.max_hits and key not in self.hit_dumped:
                self.hit_dumped.add(key)
                try:
                    self.dump_hit(idx, ev.dwThreadId, ctx, n)
                except Exception as e:
                    import traceback
                    self.log.w(f"[!!] dump 异常: {e}\n{traceback.format_exc()}")
            return DBG_CONTINUE  # RF 由恢复机制豁免一条指令, 不会死循环

        # 其余异常全部交还目标 (VMP 大量使用 SEH, 吞掉会破坏解密流程)
        self.log.w(f"[X] 异常 code={code & 0xFFFFFFFF:#010x} @ {addr:#x}"
                   f" first={first} → NOT_HANDLED (交还目标 SEH)")
        return DBG_EXCEPTION_NOT_HANDLED

    def get_ctx_now(self, tid):
        h = kernel32.OpenThread(0x0008 | 0x1000, False, tid)  # GET_CONTEXT|QUERY
        if not h:
            return None
        ctx = CONTEXT()
        ctx.ContextFlags = CONTEXT_FULL | CONTEXT_DEBUG_REGISTERS
        ok = kernel32.GetThreadContext(h, ctypes.byref(ctx))
        kernel32.CloseHandle(h)
        return ctx if ok else None

    # ---------- 命中 dump ----------
    def dump_hit(self, bp_idx, tid, ctx, hit_no):
        tag = f"hit{hit_no}"
        base = self.image_base
        if ctx is None:
            ctx = self.get_ctx_now(tid)
        if ctx is None:
            self.log.w("[!!] 取上下文失败, 仅 dump 内存")
            return

        self.log.w("  ---- 寄存器 ----")
        line = []
        for n in ["Rax","Rcx","Rdx","Rbx","Rsp","Rbp","Rsi","Rdi",
                  "R8","R9","R10","R11","R12","R13","R14","R15","Rip","EFlags"]:
            v = getattr(ctx, n)
            mark = sym(v, base, base + self.image_size)
            line.append(f"{n}={v:#018x}{mark}")
        self.log.w("  " + "\n  ".join(line))
        self.log.w(f"  Dr0={ctx.Dr0:#x} Dr1={ctx.Dr1:#x} Dr2={ctx.Dr2:#x} Dr3={ctx.Dr3:#x} "
                   f"Dr6={ctx.Dr6:#x} Dr7={ctx.Dr7:#x}")

        # 冻结其余线程 → 原子快照
        frozen = self.freeze_all_threads(tid)
        self.log.w(f"  [i] 已冻结 {len(frozen)} 个其余线程, 快照开始")
        try:
            # 1) MessageBoxW 参数字符串 (RDX=lpText, R8=lpCaption)
            for rn, label in (("Rdx", "lpText"), ("R8", "lpCaption")):
                v = getattr(ctx, rn)
                s = self.read_wstr(v)
                if s:
                    self.log.w(f"  [{rn} {label}] = {s!r}")

            # 2) 栈: RSP 起 32 个 QWORD + 顶部 256B
            self.log.w(f"  ---- 调用栈 QWORD @ RSP={ctx.Rsp:#x} ----")
            raw = self.rpm(ctx.Rsp, 32 * 8)
            for i in range(len(raw) // 8):
                q = struct.unpack("<Q", raw[i*8:(i+1)*8])[0]
                mark = sym(q, base, base + self.image_size)
                extra = ""
                if i == 0 and self.readable(q) and base and base <= q < base + self.image_size:
                    extra = " ← MessageBoxW 返回点"
                self.log.w(f"   [RSP+{i*8:#05x}] = {q:#018x}{mark}{extra}")
            self.log.w("  ---- 栈顶 256B ----")
            self.log.w(hexdump(self.rpm(ctx.Rsp, 256), ctx.Rsp))

            # 3) RIP / 断点地址处指令字节
            rip_raw = self.rpm(ctx.Rip, 48)
            self.log.w(f"  ---- RIP={ctx.Rip:#x} 处 48B ----")
            self.log.w(hexdump(rip_raw, ctx.Rip))

            # 4) 历史堆解密缓冲定点 dump (±512B)
            for ha in self.known_heap_addrs:
                if self.readable(ha):
                    blob = self.rpm(ha, 0x400)
                    self.log.w(f"  ---- 历史解密缓冲 {ha:#x} (512B) ----")
                    self.log.w(hexdump(blob, ha))
                else:
                    self.log.w(f"  历史解密缓冲 {ha:#x}: 本会话不可读 (地址已漂移)")

            # 5) 低地址堆全扫描 → bin + map + 字符串
            self.scan_low_heap(tag)
        finally:
            self.thaw_all(frozen)
            self.log.w("  [i] 快照结束, 已恢复线程运行")

    def scan_low_heap(self, tag):
        lo, hi = self.args.scan_lo, self.args.scan_hi
        bindir = self.args.outdir
        binpath = os.path.join(bindir, f"hwbp_heap_dump_{tag}.bin")
        mappath = os.path.join(bindir, f"hwbp_heap_map_{tag}.txt")
        strpath = os.path.join(bindir, f"hwbp_strings_{tag}.txt")

        mbi = MEMORY_BASIC_INFORMATION()
        regions = []
        addr = lo
        while addr < hi:
            got = ctypes.windll.kernel32.VirtualQueryEx(self.hProcess, ctypes.c_void_p(addr),
                                                        ctypes.byref(mbi), ctypes.sizeof(mbi))
            if not got:
                addr += 0x1000
                continue
            rsize = mbi.RegionSize
            if mbi.State == MEM_COMMIT and (mbi.Protect & 0xFF) in PAGE_READABLE:
                regions.append((addr, rsize, mbi.Protect))
            addr += rsize
        total = sum(r[1] for r in regions)
        self.log.w(f"  [heap] 低地址堆 {lo:#x}-{hi:#x}: {len(regions)} 个可读 region, "
                   f"共 {total/1024/1024:.2f} MB → {os.path.basename(binpath)}")
        with open(binpath, "wb") as fb, open(mappath, "w", encoding="utf-8") as fm:
            fm.write(f"# 低地址堆映射 (tag={tag}) VA区间 → bin偏移\n")
            off = 0
            allbuf = []
            for rbase, rsize, prot in regions:
                data = self.rpm(rbase, rsize)
                if not data:
                    continue
                fb.write(data)
                fm.write(f"{rbase:#012x}-{rbase+len(data):#012x} prot={prot:#x} bin_off={off:#x} size={len(data):#x}\n")
                allbuf.append((rbase, data))
                off += len(data)
            # 全量字符串提取
            ascii_re = re.compile(rb"[\x20-\x7e]{5,}")
            u16_ascii_re = re.compile(rb"(?:[\x20-\x7e]\x00){5,}")
            u16_cjk_re = re.compile(rb"(?:[\x20-\x7e]\x00|[\x00-\xff][\x4e-\x9f]|"
                                    rb"[\x00-\xff]\x30|[\x00-\xef]\xff){4,}")
            KEY = ("expire", "expiry", "black", "ban", "status", "hwid", "license",
                   "msg", "code", "auth", "sign", "token", "vip", "level", "card",
                   "time", "date", "json", "ret", "result", "data")
            KEY_CN = ("黑名单", "过期", "到期", "禁止", "封禁", "卡密", "会员", "验证",
                      "失败", "成功", "授权", "机器", "设备")
            n_as = n_u = 0
            with open(strpath, "w", encoding="utf-8", errors="replace") as fs:
                for rbase, data in allbuf:
                    # 中文优先 (判定语)
                    for m in u16_cjk_re.finditer(data):
                        try:
                            s = m.group().decode("utf-16-le", errors="ignore")
                        except Exception:
                            continue
                        if len(s) >= 4 and sum('\u4e00' <= c <= '\u9fff' for c in s) > 0:
                            va = rbase + m.start()
                            fs.write(f"[U16-CJK] {va:#012x} {s!r}\n")
                            n_u += 1
                    for m in u16_ascii_re.finditer(data):
                        s = m.group().decode("utf-16-le")
                        va = rbase + m.start()
                        low = s.lower()
                        hot = any(k in low for k in KEY)
                        if hot:
                            fs.write(f"[U16-KEY] {va:#012x} {s!r}\n")
                        n_as += 1
                    for m in ascii_re.finditer(data):
                        s = m.group().decode("ascii")
                        va = rbase + m.start()
                        low = s.lower()
                        if any(k in low for k in KEY) and not s.startswith("??"):
                            fs.write(f"[ASCI-KEY] {va:#012x} {s!r}\n")
                fs.write(f"\n# 统计: 中文串 {n_u}, ASCII 串 {n_as} (仅关键字命中写出行; "
                         f"全量原文见 {os.path.basename(binpath)})\n")
        self.log.w(f"  [heap] 字符串提取 → {os.path.basename(strpath)} "
                   f"(关键字命中已列出; 中文字段/JSON 字段名即判定字段候选)")

    # ---------- 调试主循环 ----------
    def run(self):
        si = STARTUPINFOW()
        si.cb = ctypes.sizeof(si)
        pi = PROCESS_INFORMATION()
        flags = DEBUG_ONLY_THIS_PROCESS
        self.log.w("=" * 88)
        self.log.w(f" hwbp_auth3 — 硬件断点观测 auth3 明文   {datetime.datetime.now()}")
        self.log.w(f" 目标: {self.args.exe}")
        self.log.w(f" 断点: DR0=user32!MessageBoxW(exec)  DR1=exe+0x{self.rva_exit_calc:X}(exec)"
                   + (f"  DR2={self.args.write_addr:#x}(write)" if self.args.write_addr else ""))
        self.log.w("=" * 88)

        ok = kernel32.CreateProcessW(self.args.exe, None, None, None, False,
                                     flags, None, self.args.workdir,
                                     ctypes.byref(si), ctypes.byref(pi))
        if not ok:
            self.log.w(f"[!!] CreateProcessW 失败 err={ctypes.get_last_error()}")
            return 2
        kernel32.CloseHandle(pi.hProcess)
        kernel32.CloseHandle(pi.hThread)
        self.log.w(f"[P] 已以 DEBUG_ONLY_THIS_PROCESS 启动 pid={pi.dwProcessId}")

        ev = DEBUG_EVENT()
        watchdog = threading.Thread(target=self._watchdog, daemon=True)
        watchdog.start()
        while not self.stop_evt.is_set():
            if not kernel32.WaitForDebugEvent(ctypes.byref(ev), INFINITE):
                err = ctypes.get_last_error()
                if self.stop_evt.is_set():
                    break
                self.log.w(f"[!!] WaitForDebugEvent 失败 err={err}")
                break
            code = ev.dwDebugEventCode
            cont = DBG_CONTINUE
            if code == CREATE_PROCESS_DEBUG_EVENT:
                self.on_create_process(ev)
            elif code == LOAD_DLL_DEBUG_EVENT:
                self.on_load_dll(ev)
            elif code == UNLOAD_DLL_DEBUG_EVENT:
                pass
            elif code == CREATE_THREAD_DEBUG_EVENT:
                self.on_create_thread(ev)
            elif code == EXIT_THREAD_DEBUG_EVENT:
                self.log.w(f"[T] EXIT_THREAD tid={ev.dwThreadId} code={ev.u.ExitThread.dwExitCode:#x}")
            elif code == EXIT_PROCESS_DEBUG_EVENT:
                self.exit_code = ev.u.ExitProcess.dwExitCode
                self.log.w(f"[P] EXIT_PROCESS 退出码={self.exit_code:#x} "
                           f"({'= 1: 黑名单/授权拒绝路径确认' if self.exit_code == 1 else ''})")
                kernel32.ContinueDebugEvent(ev.dwProcessId, ev.dwThreadId, DBG_CONTINUE)
                break
            elif code == EXCEPTION_DEBUG_EVENT:
                cont = self.on_exception(ev)
            elif code == OUTPUT_DEBUG_STRING_EVENT:
                info = ev.u.DebugString
                raw = self.rpm(info.lpDebugStringData or 0, info.wDebugStringLength)
                txt = raw.decode("utf-16-le", "replace") if info.fUnicode else raw.decode("gbk", "replace")
                self.log.w(f"[dbgstr] {txt!r}")
            elif code == RIP_EVENT:
                self.log.w(f"[RIP] err={ev.u.RipInfo.dwError:#x} type={ev.u.RipInfo.dwType}")
            if not kernel32.ContinueDebugEvent(ev.dwProcessId, ev.dwThreadId, cont):
                self.log.w(f"[!!] ContinueDebugEvent 失败 err={ctypes.get_last_error()}")
                break
        self.summary()
        return 0

    def _watchdog(self):
        deadline = self.start_time + self.args.timeout
        while time.time() < deadline and not self.stop_evt.is_set():
            time.sleep(1)
        if not self.stop_evt.is_set() and self.exit_code is None:
            self.log.w(f"[T] 超时 {self.args.timeout}s → 终止目标进程收尾 (弹窗无人点击属预期)")
            if self.pid:
                kernel32.TerminateProcess(self.hProcess, 0xDEAD)
            self.stop_evt.set()
            time.sleep(2)
            os._exit(0)

    def summary(self):
        self.log.w("")
        self.log.w("=" * 88)
        self.log.w(" 会话汇总")
        self.log.w(f"   运行时长   : {time.time() - self.start_time:.1f}s")
        self.log.w(f"   退出码     : {self.exit_code}")
        self.log.w(f"   断点命中   : " + (", ".join(
            f"DR{i}@{a:#x}×{n}" for (i, a), n in sorted(self.hit_counts.items())) or "无"))
        self.log.w(f"   加载 DLL   : {len(self.dll_seen)} 个")
        self.log.w("   产物       : hwbp_result.txt / hwbp_heap_dump_hit*.bin / hwbp_heap_map_hit*.txt")
        self.log.w("                / hwbp_strings_hit*.txt")
        self.log.w("   判定字段   : 查 hwbp_strings_hit*.txt 中 [U16-CJK]/[U16-KEY]/[ASCI-KEY] 行,")
        self.log.w("                JSON 键名 (expire/blacklist/status/level...) 即服务端判定字段;")
        self.log.w("                解密缓冲 3 份副本对照 hwbp_heap_dump_hit*.bin 的 0x595f10 定点 dump。")
        self.log.w("=" * 88)

# MEMORY_BASIC_INFORMATION 需在 readable 前定义 (x64: 32 字节结构)
class MEMORY_BASIC_INFORMATION(ctypes.Structure):
    _fields_ = [("BaseAddress", ctypes.c_void_p),
                ("AllocationBase", ctypes.c_void_p),
                ("AllocationProtect", wintypes.DWORD),
                ("__pad1", wintypes.DWORD),
                ("RegionSize", ctypes.c_size_t),
                ("State", wintypes.DWORD),
                ("Protect", wintypes.DWORD),
                ("Type", wintypes.DWORD),
                ("__pad2", wintypes.DWORD)]

# ---------------------------------------------------------------- 入口 ----
# ==== 轮询模式 (推荐, 见下) ====
#
# 实测结论 (2026-10-28 hwbp 模式首跑):
#   VMP 将 DR0 用作【异常驱动 VM 的派发寄存器】—— 每 VM 微操作把下条指令地址
#   写入 DR0 (per-thread, Dr7=0x501), 靠 #DB 异常驱动控制流 (RIP 落在壳 RWX
#   工作区, eb XX 变异流)。调试器全程首抓 #DB: Python 处理 ~2.7 万事件/秒,
#   40 秒 107 万次命中仍停留在公共控件初始化阶段, 远未到 auth3; 且 VMP 会
#   覆盖任意 DR 槽位, 硬件断点无法与之共存。
#   → 硬件断点保留为 --hwbp 备用模式 (加洪泛识别); 抓明文用 --poll 轮询:
#     正常启动 + 外部 ReadProcessMemory 周期扫堆, 零检测面、零干扰。
#     弹窗出现后 ExitProcess 前进程阻塞在 MessageBoxW, 堆中明文 (3 份副本)
#     仍存活, 有充足窗口抓取 (mitm/ks_session_meta.txt 已验证此路径可行)。

class Poller:
    # auth3 应答明文特征: JSON 判定字段 (165B 体) + 中文判定语 (UTF-16LE)
    JSON_KEYS = [b"expire", b"black", b'"status"', b'"hwid"', b'"level"',
                 b'"msg"', b'"code"', b'"result"', b'"sign"', b'"vip"',
                 b'"end_time"', b'"endtim"', b'"ban"']
    CN_TOKENS = {                       # UTF-16LE
        "黑名单": "黑名单".encode("utf-16-le"),
        "过期":   "过期".encode("utf-16-le"),
        "到期":   "到期".encode("utf-16-le"),
        "禁止":   "禁止".encode("utf-16-le"),
        "封禁":   "封禁".encode("utf-16-le"),
        "验证失败": "验证失败".encode("utf-16-le"),
    }

    def __init__(self, args, log: Log):
        self.args = args
        self.log = log
        self.hProcess = None
        self.pid = None
        self.stop_evt = threading.Event()
        self.start_time = time.time()
        self.dumped_rounds = set()
        self.json_hits = {}   # va -> round

    def rpm(self, addr, size):
        buf = ctypes.create_string_buffer(size)
        got = ctypes.c_size_t(0)
        ok = kernel32.ReadProcessMemory(self.hProcess, ctypes.c_void_p(addr),
                                        buf, size, ctypes.byref(got))
        return buf.raw[:got.value] if ok and got.value else b""

    def scan_round(self, rnd):
        lo, hi = self.args.scan_lo, self.args.scan_hi
        mbi = MEMORY_BASIC_INFORMATION()
        regions, addr = [], lo
        while addr < hi:
            if not ctypes.windll.kernel32.VirtualQueryEx(
                    self.hProcess, ctypes.c_void_p(addr), ctypes.byref(mbi),
                    ctypes.sizeof(mbi)):
                addr += 0x1000
                continue
            if mbi.State == MEM_COMMIT and (mbi.Protect & 0xFF) in PAGE_READABLE:
                regions.append((addr, mbi.RegionSize))
            addr += mbi.RegionSize
        total = 0
        found = []
        for rbase, rsize in regions:
            data = self.rpm(rbase, rsize)
            if not data:
                continue
            total += len(data)
            # 1) JSON 判定字段 (ASCII)
            for key in self.JSON_KEYS:
                start = 0
                while True:
                    i = data.find(key, start)
                    if i < 0:
                        break
                    # 仅报 JSON 语境: 键前 2 字节内有 '{' 或 '"' 的窗口
                    ctx = data[max(0, i - 64):i + 192]
                    if b"{" in ctx[:80] or key in (b"expire", b"black"):
                        va = rbase + i
                        if va not in self.json_hits:
                            self.json_hits[va] = rnd
                            found.append((va, key, ctx))
                    start = i + 1
            # 2) 中文判定语 (UTF-16LE)
            for name, token in self.CN_TOKENS.items():
                start = 0
                while True:
                    i = data.find(token, start)
                    if i < 0:
                        break
                    va = rbase + i
                    if va not in self.json_hits:
                        self.json_hits[va] = rnd
                        found.append((va, f"U16:{name}".encode(), data[max(0, i - 96):i + 224]))
                    start = i + 1
        self.log.w(f"[poll #{rnd}] 区域 {len(regions)} 个 / {total/1048576:.1f} MB 扫描完成, "
                   f"累计特征命中 {len(self.json_hits)}")
        for va, key, ctx in found:
            self.log.w(f"  [HIT] {va:#x} key={key!r}")
            self.log.w(self._ctx_dump(ctx, va))
        return found

    def _ctx_dump(self, ctx, va):
        # ctx 从 va-偏移 开始, 对齐后 hexdump
        return "\n".join(
            f"  {va - (va % 16) + i:012X}  " + " ".join(f"{b:02X}" for b in ctx[i:i+16]) +
            "  " + "".join(chr(b) if 0x20 <= b < 0x7F else "." for b in ctx[i:i+16])
            for i in range(0, len(ctx) - 15, 16))

    def full_snapshot(self, rnd):
        bindir = self.args.outdir
        binpath = os.path.join(bindir, f"hwbp_heap_dump_hit{rnd}.bin")
        mappath = os.path.join(bindir, f"hwbp_heap_map_hit{rnd}.txt")
        strpath = os.path.join(bindir, f"hwbp_strings_hit{rnd}.txt")
        lo, hi = self.args.scan_lo, self.args.scan_hi
        mbi = MEMORY_BASIC_INFORMATION()
        regions, addr = [], lo
        while addr < hi:
            if not ctypes.windll.kernel32.VirtualQueryEx(
                    self.hProcess, ctypes.c_void_p(addr), ctypes.byref(mbi),
                    ctypes.sizeof(mbi)):
                addr += 0x1000
                continue
            if mbi.State == MEM_COMMIT and (mbi.Protect & 0xFF) in PAGE_READABLE:
                regions.append((addr, mbi.RegionSize))
            addr += mbi.RegionSize
        self.log.w(f"[snap] 全量快照 {len(regions)} 区域 → {os.path.basename(binpath)}")
        ascii_re = re.compile(rb"[\x20-\x7e]{6,}")
        u16_re = re.compile(rb"(?:[\x20-\x7e]\x00){5,}")
        u16_cjk_re = re.compile(rb"(?:[\x20-\x7e]\x00|[\x00-\xff][\x4e-\x9f]|"
                                rb"[\x00-\xff]\x30|[\x00-\xef]\xff){4,}")
        KEY = ("expire", "expiry", "black", "ban", "status", "hwid", "license",
               "msg", "code", "auth", "sign", "token", "vip", "level", "card",
               "json", "ret", "result", "remain", "day", "time", "date")
        with open(binpath, "wb") as fb, open(mappath, "w", encoding="utf-8") as fm, \
             open(strpath, "w", encoding="utf-8", errors="replace") as fs:
            fm.write(f"# 低地址堆映射 (round={rnd})\n")
            off = 0
            for rbase, rsize in regions:
                data = self.rpm(rbase, rsize)
                if not data:
                    continue
                fb.write(data)
                fm.write(f"{rbase:#012x}-{rbase+len(data):#012x} bin_off={off:#x} size={len(data):#x}\n")
                for m in u16_cjk_re.finditer(data):
                    try:
                        s = m.group().decode("utf-16-le", errors="ignore")
                    except Exception:
                        continue
                    if len(s) >= 4 and any("\u4e00" <= c <= "\u9fff" for c in s):
                        fs.write(f"[U16-CJK] {rbase + m.start():#012x} {s!r}\n")
                for m in u16_re.finditer(data):
                    s = m.group().decode("utf-16-le")
                    if any(k in s.lower() for k in KEY):
                        fs.write(f"[U16-KEY] {rbase + m.start():#012x} {s!r}\n")
                for m in ascii_re.finditer(data):
                    s = m.group().decode("ascii")
                    if any(k in s.lower() for k in KEY):
                        fs.write(f"[ASCI-KEY] {rbase + m.start():#012x} {s!r}\n")
                off += len(data)
        self.log.w(f"[snap] 字符串提取 → {os.path.basename(strpath)}")

    def alive(self):
        code = wintypes.DWORD()
        if not kernel32.GetExitCodeProcess(self.hProcess, ctypes.byref(code)):
            return False
        return code.value == 259  # STILL_ACTIVE

    def run(self):
        si = STARTUPINFOW()
        si.cb = ctypes.sizeof(si)
        pi = PROCESS_INFORMATION()
        self.log.w("=" * 88)
        self.log.w(f" hwbp_auth3 — POLL 轮询抓取 auth3 明文   {datetime.datetime.now()}")
        self.log.w(f" 目标: {self.args.exe}")
        self.log.w(f" 扫描: {self.args.scan_lo:#x}-{self.args.scan_hi:#x} 每 {self.args.poll_interval}s 一轮")
        self.log.w("=" * 88)
        ok = kernel32.CreateProcessW(self.args.exe, None, None, None, False,
                                     0, None, self.args.workdir,
                                     ctypes.byref(si), ctypes.byref(pi))
        if not ok:
            self.log.w(f"[!!] CreateProcessW 失败 err={ctypes.get_last_error()}")
            return 2
        self.hProcess = pi.hProcess
        self.pid = pi.dwProcessId
        kernel32.CloseHandle(pi.hThread)
        self.log.w(f"[P] 正常启动 pid={self.pid} (不调试, 零干扰)")

        exit_code = None
        rnd = 0
        last_hit_round = -1
        while time.time() - self.start_time < self.args.timeout:
            if not self.alive():
                code = wintypes.DWORD()
                kernel32.GetExitCodeProcess(self.hProcess, ctypes.byref(code))
                exit_code = code.value
                self.log.w(f"[P] 进程退出 code={exit_code:#x}")
                # 退出前最后一轮扫描 (退出瞬间堆仍可能可读)
                try:
                    self.scan_round(rnd + 1)
                except Exception:
                    pass
                break
            rnd += 1
            try:
                found = self.scan_round(rnd)
            except Exception as e:
                self.log.w(f"[!!] 扫描异常: {e}")
                found = []
            ks_new = any(r == rnd for r, _ in getattr(self, "ks_hits", {}).values())
            if (found or ks_new) and rnd - last_hit_round >= 1:
                last_hit_round = rnd
                try:
                    self.full_snapshot(rnd)
                except Exception as e:
                    self.log.w(f"[!!] 快照异常: {e}")
            time.sleep(self.args.poll_interval)

        if exit_code is None:
            self.log.w("[T] 超时 → 终止目标收尾")
            kernel32.TerminateProcess(self.hProcess, 0xDEAD)
        self.log.w("")
        self.log.w("=" * 88)
        self.log.w(" POLL 会话汇总")
        self.log.w(f"   轮数: {rnd}   特征命中 VA 数: {len(self.json_hits)}   退出码: {exit_code}")
        for va, r in sorted(self.json_hits.items()):
            self.log.w(f"     {va:#012x} (round {r})")
        self.log.w("   产物: hwbp_heap_dump_hit*.bin + hwbp_heap_map_hit*.txt + hwbp_strings_hit*.txt")
        self.log.w("   判定字段: 在 strings 文件 [ASCI-KEY]/[U16-KEY] 中找 JSON 键名与取值,")
        self.log.w("             结合 bin 中命中 VA ±512B 的 165B JSON 体 (auth3 应答明文)。")
        self.log.w("=" * 88)
        return 0


# ==== 深度轮询 (--mode deep): 增量 diff + KS 反推 ====
#
# auth3 应答 = [32B 明文头][165B 体], 体明文 = 密文 ^ KS (固定垫, 三方验证)。
# KS 已知 (mitm/ks_real.bin, 与 ks_session_meta.txt 一致) → 对内存任意 165B
# 窗口做 X ^ KS: 结果若为可读 JSON/文本, 该窗口即 auth3 判定现场
# (解密前密文与解密后明文均可识别)。numpy 向量化, 轮间只扫增量 region。
try:
    import numpy as np
except ImportError:
    np = None

def _load_ks():
    p = os.path.join(os.path.dirname(os.path.abspath(__file__)), "mitm", "ks_real.bin")
    return open(p, "rb").read() if os.path.exists(p) else b""

class DeepPoller(Poller):
    """增量 diff + KS 反推扫描"""
    WIN = 165
    PROBE = 48

    def __init__(self, args, log):
        super().__init__(args, log)
        self.prev = {}
        self.ks = _load_ks()
        self.ks_hits = {}
        self.max_addr = 0x70000000

    def _regions(self):
        mbi = MEMORY_BASIC_INFORMATION()
        out, addr = [], 0x10000
        while addr < self.max_addr:
            if not ctypes.windll.kernel32.VirtualQueryEx(
                    self.hProcess, ctypes.c_void_p(addr), ctypes.byref(mbi),
                    ctypes.sizeof(mbi)):
                addr += 0x1000
                continue
            if (mbi.State == MEM_COMMIT and mbi.Type == 0x20000 and
                    (mbi.Protect & 0xFF) in PAGE_READABLE):
                out.append((mbi.BaseAddress or addr, mbi.RegionSize))
            addr += mbi.RegionSize
        return out

    def ks_scan(self, data, base, rnd):
        if not self.ks or np is None or len(data) < self.WIN:
            return
        arr = np.frombuffer(data, dtype=np.uint8)
        ks = np.frombuffer(self.ks, dtype=np.uint8)
        n = len(arr) - self.WIN
        if n <= 0:
            return
        probe = self.PROBE
        CH = 1 << 21
        for s in range(0, n, CH):
            e = min(n, s + CH)
            hi = min(len(arr), e + probe - 1)
            if hi - s < probe:
                continue
            blk = np.lib.stride_tricks.sliding_window_view(arr[s:hi], probe)
            xor = blk ^ ks[:probe]
            pr = ((xor >= 0x20) & (xor < 0x7F)).mean(axis=1)
            for j in np.nonzero(pr > 0.90)[0]:
                i = s + int(j)
                full = bytes(a ^ b for a, b in zip(data[i:i + self.WIN], self.ks))
                marks = sum(full.count(x) for x in (b"{", b"}", b'"', b":", b","))
                if marks >= 6:
                    va = base + i
                    if va not in self.ks_hits:
                        self.ks_hits[va] = (rnd, full)
                        txt = "".join(chr(b) if 0x20 <= b < 0x7F else "·" for b in full)
                        self.log.w(f"  [KS-HIT] {va:#x} (rnd {rnd}) 165B:")
                        self.log.w("    " + full.hex())
                        self.log.w(f"    {txt!r}")

    def scan_round(self, rnd):
        regions = self._regions()
        new_or_changed = []
        cur = {}
        total_mb = 0
        for rbase, rsize in regions:
            data = self.rpm(rbase, rsize)
            if not data:
                continue
            total_mb += len(data)
            h = hash(data)
            cur[rbase] = (len(data), h)
            if rbase not in self.prev or self.prev[rbase] != (len(data), h):
                new_or_changed.append((rbase, data))
        self.prev = cur
        hits = []
        for rbase, data in new_or_changed:
            self.ks_scan(data, rbase, rnd)
            for key in self.JSON_KEYS:
                i = data.find(key)
                while i >= 0:
                    ctx = data[max(0, i - 64):i + 192]
                    if b"{" in ctx[:80]:
                        va = rbase + i
                        if va not in self.json_hits:
                            self.json_hits[va] = rnd
                            hits.append((va, key, ctx))
                    i = data.find(key, i + 1)
        self.log.w(f"[deep #{rnd}] 私有内存 {len(regions)} 区域 / {total_mb/1048576:.0f} MB, "
                   f"增量 {len(new_or_changed)} 区域, KS命中 {len(self.ks_hits)}, 特征命中 {len(self.json_hits)}")
        for va, key, ctx in hits:
            self.log.w(f"  [HIT] {va:#x} key={key!r}")
            self.log.w(self._ctx_dump(ctx, va))
        return hits

    def run(self):
        # 复用 Poller.run, 但扫描入口是本类 scan_round (多态), 快照沿用父类
        return super().run()


def main():
    ap = argparse.ArgumentParser(description="硬件断点抓 auth3 明文")
    ap.add_argument("--exe", default=r"C:\Users\<SANITIZED>\Desktop\KR\wq7iw02606g581.exe")
    ap.add_argument("--workdir", default=r"C:\Users\<SANITIZED>\Desktop\KR")
    ap.add_argument("--outdir", default=r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\分析工作区")
    ap.add_argument("--rva2", type=lambda x: int(x, 0), default=0x617ad0,
                    help="第二执行断点 RVA (退出码计算器)")
    ap.add_argument("--write-addr", type=lambda x: int(x, 0), default=None,
                    help="可选 DR2 数据写断点地址 (堆解密缓冲)")
    ap.add_argument("--write-len", type=int, default=3, choices=(0, 1, 2, 3),
                    help="写断点长度编码 0=1B 1=2B 2=8B 3=4B")
    ap.add_argument("--timeout", type=int, default=260, help="总超时秒数")
    ap.add_argument("--max-hits", type=int, default=8, help="每断点最大 dump 次数")
    ap.add_argument("--scan-lo", type=lambda x: int(x, 0), default=0x100000)
    ap.add_argument("--scan-hi", type=lambda x: int(x, 0), default=0x4000000)
    ap.add_argument("--mode", choices=("poll", "hwbp", "deep"), default="poll",
                    help="poll=轮询扫堆(低址); deep=增量diff+KS反推全私有内存(推荐); "
                         "hwbp=硬件断点(备用, VMP 用 DR0 驱动 VM 无法共存)")
    ap.add_argument("--poll-interval", type=float, default=2.0)
    args = ap.parse_args()

    sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    os.makedirs(args.outdir, exist_ok=True)
    log = Log(os.path.join(args.outdir, "hwbp_result.txt"))

    if args.mode == "deep":
        dbg = DeepPoller(args, log)
    elif args.mode == "poll":
        dbg = Poller(args, log)
    else:
        dbg = HwbpDebugger(args, log)

    def _sigint(a, b):
        log.w("[T] Ctrl+C → 终止目标进程收尾")
        if getattr(dbg, "hProcess", None) and getattr(dbg, "pid", None):
            kernel32.TerminateProcess(dbg.hProcess, 0xDEAD)
        if hasattr(dbg, "stop_evt"):
            dbg.stop_evt.set()
        time.sleep(1)
        os._exit(0)
    signal.signal(signal.SIGINT, _sigint)

    try:
        rc = dbg.run()
    finally:
        log.close()
    sys.exit(rc)

if __name__ == "__main__":
    main()
