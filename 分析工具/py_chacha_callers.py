# -*- coding: utf-8 -*-
"""
ChaCha 调用者静态扫描（纯 Python，无 IDA）
在脱壳 dump 中找:
 1. 所有 RIP 相对 LEA/MOV 指向 chacha_init 及相关函数
 2. MOV r64, imm64 装载函数地址
 3. 8 字节数据指针出现
 4. E8/E9 直接调用对照（验证映射）
 5. 0x9E3779B1 黄金比例常量全部出现
 6. 引用者函数头(向上找 CC 填充) + 前 200 字节 + 立即数提取
输出: chacha_callers.txt
"""
import struct, re, sys, io

DUMP = r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\KR-撤离版\KR_脱壳dump.exe"
OUT  = r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\分析工作区\chacha_callers.txt"
IMAGE_BASE = 0x140000000

data = open(DUMP, "rb").read()
N = len(data)

# ---- 节表 (由 py_pe_probe.py 探测结果; 此 dump raw off == RVA) ----
SECS = [  # (va_start, va_end, name, is_code)
    (0x140001000, 0x140A01000, "seg000(.text)", True),
    (0x140A01000, 0x141101000, "seg001(壳/VM)", True),
    (0x141101000, 0x145C3A000, "seg002(数据)", False),
    (0x145C3A000, 0x145C71000, "seg003", False),
    (0x145C71000, 0x145C72000, "seg004", False),
    (0x145C72000, 0x145CD9000, "seg005", False),
    (0x145CD9000, 0x145CE2000, ".reloc", False),
    (0x145CE2000, 0x145CE3000, ".rsrc", False),
    (0x145CE3000, 0x146143250, "seg008", False),
]
def sec_of(va):
    for s, e, n, c in SECS:
        if s <= va < e: return n, c
    return "PE头/未知", False

def off2va(o): return IMAGE_BASE + o
def va2off(v): return v - IMAGE_BASE

R64  = ['rax','rcx','rdx','rbx','rsp','rbp','rsi','rdi']
R64X = ['r8','r9','r10','r11','r12','r13','r14','r15']

# ---- 目标函数表 ----
TARGETS = {
    0x140329150: "chacha_init",
    0x140329A60: "chacha_ctr_nonce",
    0x14032A050: "chacha_xor_apply",
    0x14032D8B0: "chacha_setctr(sub_14032D8B0)",
    0x140328020: "chacha_wrap1(sub_140328020)",
    0x140328230: "chacha_wrap2(sub_140328230)",
    0x140328650: "chacha_wrap3(sub_140328650)",
    0x140328C20: "chacha_wrap4(sub_140328C20)",
}

KNOWN_FUNCS = {  # IDA 已知函数头, 用于对照
    0x140328020: "sub_140328020 (wrap1: init+ctr_nonce+xor)",
    0x140328230: "sub_140328230 (wrap2: init+setctr+xor)",
    0x140328650: "sub_140328650 (wrap3)",
    0x140328C20: "sub_140328C20 (wrap4)",
    0x140329150: "chacha_init",
    0x140329A60: "chacha_ctr_nonce",
    0x14032A050: "chacha_xor_apply",
    0x14032D8B0: "sub_14032D8B0",
}

# ============ 1. RIP 相对 LEA/MOV (REX + op + modrm(00rrr101) + disp32) ============
OPN = {0x8D: "lea", 0x8B: "mov-load", 0x89: "mov-store"}
rip_refs = []  # (instr_off, len, mnem, regname, disp, target_va, tname)
pat = re.compile(rb'[\x48\x4c\x49\x4d][\x8d\x8b\x89][\x05\x0d\x15\x1d\x25\x2d\x35\x3d]')
for m in pat.finditer(data):
    p = m.start()
    if p + 7 > N: continue
    rex, op, modrm = data[p], data[p+1], data[p+2]
    disp = struct.unpack_from("<i", data, p+3)[0]
    tgt = off2va(p) + 7 + disp
    if tgt in TARGETS:
        reg = ((modrm >> 3) & 7) + (8 if rex & 4 else 0)
        rn = (R64X if rex & 4 else R64)[(modrm >> 3) & 7]
        rip_refs.append((p, 7, OPN[op], rn, disp, tgt, TARGETS[tgt]))

# 无 REX 变体 (32位操作数, len=6)
pat2 = re.compile(rb'[\x8d\x8b\x89][\x05\x0d\x15\x1d\x25\x2d\x35\x3d]')
for m in pat2.finditer(data):
    p = m.start()
    if p < 1 or 0x40 <= data[p-1] <= 0x4F:  # 跳过带 REX 的(已在上面)
        continue
    if p + 6 > N: continue
    op, modrm = data[p], data[p+1]
    disp = struct.unpack_from("<i", data, p+2)[0]
    tgt = off2va(p) + 6 + disp
    if tgt in TARGETS:
        rn = R64[(modrm >> 3) & 7] + "(32)"
        rip_refs.append((p, 6, OPN[op] + "32", rn, disp, tgt, TARGETS[tgt]))

# ============ 2. MOV r64, imm64 + 3. 8字节数据指针 ============
imm64_refs = []   # (instr_off, regname, target, tname)
data_ptrs = []    # (off, target, tname, context_is_code)
for t, tname in TARGETS.items():
    needle = struct.pack("<Q", t)
    pos = data.find(needle)
    while pos != -1:
        if pos >= 2 and data[pos-2] in (0x48, 0x49) and 0xB8 <= data[pos-1] <= 0xBF:
            reg = (pos-1)  # opcode byte
            regidx = data[pos-1] - 0xB8 + (8 if data[pos-2] == 0x49 else 0)
            rn = (R64X if data[pos-2] == 0x49 else R64)[data[pos-1] - 0xB8]
            imm64_refs.append((pos - 2, rn, t, tname))
        else:
            va = off2va(pos)
            _, is_code = sec_of(va)
            data_ptrs.append((pos, t, tname, is_code))
        pos = data.find(needle, pos + 1)

# RVA 形式 4 字节指针 (50 91 32 40) - 仅对 chacha_init 检查
rva4_hits = []
needle4 = struct.pack("<I", 0x40329150)
pos = data.find(needle4)
while pos != -1:
    rva4_hits.append(pos)
    pos = data.find(needle4, pos + 1)

# ============ 4. E8/E9 rel32 直接调用/跳转对照 ============
call_refs = []  # (off, opcode, target, tname)
for m in re.finditer(rb'[\xe8\xe9]', data):
    p = m.start()
    if p + 5 > N: continue
    rel = struct.unpack_from("<i", data, p+1)[0]
    tgt = off2va(p) + 5 + rel
    if tgt in TARGETS:
        call_refs.append((p, data[p], tgt, TARGETS[tgt]))

# ============ 函数头识别 (向上找 CC 填充) ============
FILL = (0xCC, 0x90)
def find_func_start(off, maxback=0x6000):
    lo = max(1, off - maxback)
    i = off - 1
    while i >= lo + 1:
        if data[i] == 0xCC and data[i-1] == 0xCC:
            j = i + 1
            while j < N and data[j] in FILL: j += 1
            return j
        i -= 1
    # 退化: ret(C3/C2) 后跟至少 2 字节填充
    i = off - 1
    while i >= lo:
        if data[i] == 0xC3 or data[i] == 0xC2:
            j = i + 3 if data[i] == 0xC2 else i + 1
            k = j
            while k < N and data[k] in FILL: k += 1
            if k - j >= 2 and k < off:
                return k
        i -= 1
    return None

def hexdump(va, off, size):
    lines = []
    chunk = data[off:off+size]
    for i in range(0, len(chunk), 16):
        row = chunk[i:i+16]
        lines.append("  %016X: %s" % (va + i, " ".join("%02X" % b for b in row)))
    return "\n".join(lines)

KNOWN_CONSTS = {
    0x9E3779B9: "FNV/xxHash 黄金比例",
    0x9E3779B1: "黄金比例(TEA/密钥派生)",
    0x61C88647: "TEA delta(负)",
    0x9E3779B97F4A7C15: "64位黄金比例",
    0xC2B2AE3D: "murmur 常量",
    0x27D4EB2F: "murmur3 常量",
    0x85EBCA6B: "xxhash 常量",
}

def extract_consts(off, size=200):
    """提取函数前 size 字节里的 mov r32/r64, imm 立即数"""
    out = []
    i = 0
    end = min(size, N - off - 10)
    code = data[off:off+size]
    n = len(code)
    i = 0
    while i < n - 5:
        b = code[i]
        if b == 0x41 and 0xB8 <= (code[i+1] if i+1 < n else 0) <= 0xBF and i + 6 <= n:
            imm = struct.unpack_from("<I", code, i+2)[0]
            out.append((i, "mov r%dd, 0x%08X" % (code[i+1]-0xB8+8, imm), imm)); i += 6; continue
        if 0xB8 <= b <= 0xBF and i + 5 <= n:
            imm = struct.unpack_from("<I", code, i+1)[0]
            out.append((i, "mov %s, 0x%08X" % (["eax","ecx","edx","ebx","esp","ebp","esi","edi"][b-0xB8], imm), imm)); i += 5; continue
        if b == 0x48 and 0xB8 <= (code[i+1] if i+1 < n else 0) <= 0xBF and i + 10 <= n:
            imm = struct.unpack_from("<Q", code, i+2)[0]
            out.append((i, "movabs %s, 0x%016X" % (R64[code[i+1]-0xB8], imm), imm)); i += 10; continue
        i += 1
    return out

# ============ 5. 0x9E3779B1 搜索 ============
def find_all(needle):
    r, pos = [], data.find(needle)
    while pos != -1:
        r.append(pos); pos = data.find(needle, pos+1)
    return r

gr_b1 = find_all(struct.pack("<I", 0x9E3779B1))
gr_b9 = find_all(struct.pack("<I", 0x9E3779B9))
gr_64 = find_all(struct.pack("<Q", 0x9E3779B97F4A7C15))

# ============ 输出 ============
buf = io.StringIO()
W = buf.write

W("=" * 78 + "\n")
W(" ChaCha 调用者静态扫描 — 纯 Python 二进制分析 (无 IDA)\n")
W(" dump: KR_脱壳dump.exe  大小=0x%X  image_base=0x%X\n" % (N, IMAGE_BASE))
W(" 主目标: chacha_init = 0x140329150 ('expand 32-byte k' 常量 @0x1403AB1B0)\n")
W("=" * 78 + "\n\n")

# ---- 第一部分: 指向 chacha_init 的代码引用 ----
def emit_code_ref(idx, off, ilen, desc, extra=""):
    va = off2va(off)
    sec, is_code = sec_of(va)
    W("--- 引用 #%d %s @ 0x%X (文件偏移 0x%X) [%s] ---\n" % (idx, desc, va, off, sec))
    W("  指令字节: %s\n" % " ".join("%02X" % b for b in data[max(0,off-6):off+ilen+8]))
    if extra: W("  %s\n" % extra)
    fs = find_func_start(off) if is_code else None
    if fs is not None:
        fva = off2va(fs)
        kn = KNOWN_FUNCS.get(fva, "")
        W("  所在函数头: 0x%X %s\n" % (fva, ("= " + kn) if kn else "(IDA 未知的函数, 由 CC 填充定位)"))
        W("  函数前 200 字节:\n")
        W(hexdump(fva, fs, 200) + "\n")
        consts = extract_consts(fs, 200)
        if consts:
            W("  函数头 200 字节内立即数:\n")
            for ci, cdesc, cval in consts[:24]:
                tag = KNOWN_CONSTS.get(cval, "")
                W("    +%03X  %s %s\n" % (ci, cdesc, (" <-- " + tag) if tag else ""))
        W("\n")
        return fva
    else:
        W("  (未能定位函数头 — 可能位于数据/VM 字节码区)\n\n")
        return None

W("【第一部分】RIP 相对 LEA/MOV 引用 chacha_init (0x140329150)\n")
W("共 %d 条:\n\n" % sum(1 for r in rip_refs if r[5] == 0x140329150))
i = 0
init_func_hits = {}
for (p, ilen, mnem, rn, disp, tgt, tname) in rip_refs:
    if tgt != 0x140329150: continue
    i += 1
    fva = emit_code_ref(i, p, ilen, "%s %s, [rip%+d] -> %s" % (mnem, rn, disp, tname),
                        "disp32=%+d (0x%X), 指令尾=0x%X" % (disp, disp & 0xFFFFFFFF, off2va(p)+ilen))
    if fva: init_func_hits[fva] = init_func_hits.get(fva, 0) + 1

W("\n【第二部分】RIP 相对 LEA/MOV 引用其他 ChaCha 家族函数\n")
others = [r for r in rip_refs if r[5] != 0x140329150]
W("共 %d 条:\n\n" % len(others))
for (p, ilen, mnem, rn, disp, tgt, tname) in others:
    va = off2va(p)
    fs = find_func_start(p)
    fs_s = ("函数头 0x%X" % off2va(fs)) if fs is not None else "函数头未定位"
    W("  @0x%X  %s %s,[rip%+d] -> %s (0x%X)  | %s\n" % (va, mnem, rn, disp, tname, tgt, fs_s))

W("\n【第三部分】MOV r64, imm64 直接装载函数地址\n")
if not imm64_refs: W("  (无)\n")
for (p, rn, t, tname) in imm64_refs:
    va = off2va(p)
    emit_code_ref(len(imm64_refs), p, 10, "movabs %s, 0x%X -> %s" % (rn, t, tname))

W("\n【第四部分】8 字节数据指针 (函数地址作为表项)\n")
if not data_ptrs: W("  (无 — dump 中无任何 8 字节直接指针表项)\n")
for (p, t, tname, is_code) in data_ptrs:
    va = off2va(p)
    sec, _ = sec_of(va)
    ctx = data[max(0,p-16):p+24]
    W("  @0x%X [%s] -> %s (0x%X)\n" % (va, sec, tname, t))
    W("    上下文: %s\n" % ctx.hex(" "))

W("\n【第四部分B】低32位 0x40329150 (RVA 式引用) 出现 %d 处:\n" % len(rva4_hits))
for p in rva4_hits[:40]:
    va = off2va(p)
    sec, _ = sec_of(va)
    # 排除本身就是 imm64 指针前 4 字节的情况
    tag = ""
    if data[p+4:p+8] == b"\x01\x00\x00\x00": tag = "(是 imm64/8字节指针的低半)"
    W("  @0x%X [%s] %s\n" % (va, sec, tag))

W("\n【第五部分】直接 CALL/JMP (E8/E9 rel32) 对照 — 验证与 IDA 一致\n")
for (p, op, tgt, tname) in sorted(call_refs):
    va = off2va(p)
    kind = "call" if op == 0xE8 else "jmp"
    fs = find_func_start(p)
    fs_s = ("sub_%X" % off2va(fs)) if fs is not None else "?"
    W("  %s @0x%X -> %s (0x%X)  所在函数 %s\n" % (kind, va, tname, tgt, fs_s))

W("\n" + "=" * 78 + "\n")
W("【第六部分】0x9E3779B1 黄金比例常量扫描\n")
W("  0x9E3779B1 出现 %d 处\n" % len(gr_b1))
W("  0x9E3779B9 出现 %d 处 (FNV-1/xxHash 黄金比例)\n" % len(gr_b9))
W("  0x9E3779B97F4A7C15 出现 %d 处 (64 位黄金比例)\n\n" % len(gr_64))

gr_funcs = {}
for p in gr_b1:
    va = off2va(p)
    sec, is_code = sec_of(va)
    ctx = data[max(0,p-8):p+28]
    # 判断是否 imm32: 前一字节 B8-BF(mov r32,imm) 或 41 B8-BF 或 05(add eax) 等
    prev = data[p-1]
    how = ""
    if 0xB8 <= prev <= 0xBF: how = "mov r32,imm32"
    elif prev == 0x41 and 0xB8 <= data[p-2] <= 0xBF: how = "mov r8d-r15d,imm32"
    elif prev == 0x05: how = "add eax,imm32"
    elif prev == 0x3D: how = "cmp eax,imm32"
    W("  @0x%X [%s] %s\n" % (va, sec, how))
    W("    上下文: %s\n" % ctx.hex(" "))
    if is_code:
        fs = find_func_start(p)
        if fs is not None:
            fva = off2va(fs)
            W("    所在函数头: 0x%X\n" % fva)
            gr_funcs[fva] = gr_funcs.get(fva, 0) + 1
    W("\n")

W("  附: 0x9E3779B9 出现位置: %s\n\n" % (", ".join("0x%X" % off2va(p) for p in gr_b9[:20]) or "无"))

W("=" * 78 + "\n")
W("【第七部分】结论汇总\n")
W("  指向 chacha_init 的 RIP 相对 LEA/MOV 引用者函数(去重):\n")
for fva, cnt in sorted(init_func_hits.items()):
    kn = KNOWN_FUNCS.get(fva, "")
    W("    0x%X  ×%d  %s\n" % (fva, cnt, kn))
W("\n  含 0x9E3779B1 的函数(密钥派生候选, 去重):\n")
if not gr_funcs: W("    (代码节中无)\n")
for fva, cnt in sorted(gr_funcs.items()):
    W("    0x%X  ×%d\n" % (fva, cnt))
W("\n")

txt = buf.getvalue()
open(OUT, "w", encoding="utf-8").write(txt)
print("written:", OUT, len(txt), "chars")

# stdout 摘要
print("\n--- 摘要 ---")
print("rip->chacha_init:", sum(1 for r in rip_refs if r[5]==0x140329150))
print("rip->others:", len(others))
print("imm64 refs:", len(imm64_refs))
print("data ptrs:", len(data_ptrs))
print("rva4 hits:", len(rva4_hits))
print("call/jmp refs:", len(call_refs))
print("9E3779B1:", len(gr_b1), " 9E3779B9:", len(gr_b9), " 64bit:", len(gr_64))
