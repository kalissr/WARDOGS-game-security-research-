# -*- coding: utf-8 -*-
"""Stage D: robust restart-scanning for handler bodies + dispatcher web stats."""
import capstone, struct
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
from capstone.x86 import *
from capstone import CS_GRP_JUMP, CS_GRP_CALL

DUMP = r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\KR-撤离版\KR_脱壳dump.exe"
OUT  = r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\分析工作区\vmp_disasm_auth3.txt"
BASE = 0x140000000
VMP1_LO, VMP1_HI = 0x5C72000, 0x5CD847C

with open(DUMP, "rb") as f:
    whole = f.read()
md = Cs(CS_ARCH_X86, CS_MODE_64); md.detail = True
out = open(OUT, "a", encoding="utf-8")
def W(s=""): out.write(s + "\n")
def hdr(t):
    W(); W("=" * 100); W("## " + t); W("=" * 100)

def fmt(ins):
    rva = ins.address - BASE
    tgt = ""
    if ins.group(CS_GRP_JUMP) or ins.group(CS_GRP_CALL):
        if len(ins.operands) == 1 and ins.operands[0].type == X86_OP_IMM:
            t = ins.operands[0].imm - BASE
            cls = "VM" if VMP1_LO <= t < VMP1_HI else "NAT"
            tgt = f"  -> 0x{t:X} [{cls}]"
    return f"  0x{rva:08X}  {ins.bytes.hex().upper():26s} {ins.mnemonic:7s} {ins.op_str}{tgt}"

def dis_robust(rva_start, nbytes, max_ins=60):
    """Linear scan that skips invalid bytes (1-byte step) instead of aborting."""
    res = []
    pos, va = 0, BASE + rva_start
    code = whole[rva_start:rva_start+nbytes]
    while pos < len(code) and len(res) < max_ins:
        got = False
        for ins in md.disasm(code[pos:], va + pos):
            res.append(ins)
            pos = ins.address - BASE + ins.size - rva_start
            got = True
            if len(res) >= max_ins: break
        if not got:
            pos += 1
    return res

hdr("【区域19R】dispatcher 间接表验证 (robust 重扫 0x5C91000-0x5C9D000)")
mem_jumps = []
for ins in dis_robust(0x5C91000, 0xC000, max_ins=200000):
    if (ins.group(CS_GRP_JUMP) or ins.group(CS_GRP_CALL)) and len(ins.operands) == 1 and ins.operands[0].type == X86_OP_MEM:
        op = ins.operands[0]
        if op.mem.index != 0:
            mem_jumps.append(f"  0x{ins.address-BASE:08X}: {ins.mnemonic} {ins.op_str}")
W(f"# [reg+reg*scale] 型间接 jmp/call: {len(mem_jumps)} 处")
for ln in mem_jumps[:30]: W(ln)
W("# (0 处 = VMP 此配置无 opcode 派发表, 派发=加密 VIP 数据 + handler 链尾互跳)")

hdr("【区域19S】vmp1 变异 Web 统计 (robust 重扫全段)")
targets = {} ; cnt_call = cnt_jmp = cnt_jcc = 0
for ins in dis_robust(0x5C72000, 0x5CD847C - 0x5C72000, max_ins=500000):
    if ins.group(CS_GRP_CALL) and len(ins.operands)==1 and ins.operands[0].type==X86_OP_IMM:
        cnt_call += 1
        t = ins.operands[0].imm - BASE
        if VMP1_LO <= t < VMP1_HI: targets[t] = targets.get(t,0)+1
    elif ins.group(CS_GRP_JUMP):
        if ins.mnemonic == "jmp" and len(ins.operands)==1 and ins.operands[0].type==X86_OP_IMM:
            cnt_jmp += 1
            t = ins.operands[0].imm - BASE
            if VMP1_LO <= t < VMP1_HI: targets[t] = targets.get(t,0)+1
        else:
            cnt_jcc += 1
W(f"# call rel32: {cnt_call}, jmp rel32: {cnt_jmp}, 条件 jcc: {cnt_jcc}")
W(f"# 指向 vmp1 内部的不同目标: {len(targets)} 个节点")
top = sorted(targets.items(), key=lambda kv: -kv[1])[:20]
W("# 入度最高的 20 个 handler 节点:")
for t, c in top:
    W(f"    0x{t:X}  <- {c} 条边")

hdr("【区域10R】弹窗路径全部 VM handler 入口主体 (robust, 每个 40 条)")
targets2 = [0x5C746DB,0x5C759CA,0x5C7357C,0x5C77E42,0x5C74666,0x5C82FA9,0x5C752CE,0x5C754F2,
            0x5C73C8B,0x5C7C863,0x5C73096,0x5C75235,0x5C75009,0x5C72414,0x5C77E1D,0x5C72B01,
            0x5C7264C,0x5C7A3E0,0x5C77238,0x5C80560,0x5C750FC,0x5C74B86,0x5C75AF9,0x5C741BE,
            0x5C9B7E8,0x5C93C8B,0x5C9356F,0x5C99C89]
for t in sorted(set(targets2)):
    W(f"\n  --- handler 0x{t:X} ---")
    for ins in dis_robust(t, 0x70, max_ins=22):
        W(fmt(ins))

hdr("【区域22】判定链核心 handler 主体: 0x5C9C5FE → 0x5C91B20 → ... (robust 深追)")
def follow_robust(start, hops=10, body_ins=30):
    rva = start
    for h in range(hops):
        ins_list = dis_robust(rva, 0x10, 3)
        if not ins_list: break
        first = ins_list[0]
        if first.mnemonic == "jmp" and len(first.operands)==1 and first.operands[0].type==X86_OP_IMM:
            t = first.operands[0].imm - BASE
            W(f"  [跳{h+1}] 0x{rva:X} jmp -> 0x{t:X}")
            if not (VMP1_LO <= t < VMP1_HI) or t == rva: return
            rva = t
        else:
            W(f"  [终点] 0x{rva:X} handler 主体:")
            for ins in dis_robust(rva, 0x110, body_ins):
                W(fmt(ins))
            return
W("  == 0x5C951EE 链 (RFLAGS 消费者) ==")
follow_robust(0x5C951EE)
W()
W("  == 0x5C791FC 链 (判定 handler, 含常量 0x3D22B75) ==")
W("  0x5C791FC: mov [rsp],0x3D22B75 ; call 0x5C99853 (fetch-handler) — 已确认")
W("  == 0x5C99853 链 (fetch/decode handler) ==")
follow_robust(0x5C99853)
W()
W("  == 0x5C750FC (弹窗后 handler) ==")
follow_robust(0x5C750FC)
W()
W("  == 0x5C74544 (0x617AD0 失败码计算器调用的 VM 入口) ==")
follow_robust(0x5C74544)

out.close()
print("stage D done")
