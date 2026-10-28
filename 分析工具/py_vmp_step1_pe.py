# -*- coding: utf-8 -*-
"""Step 1: Parse PE headers of the unpacked dump, confirm RVA->file offset mapping."""
import struct, sys

DUMP = r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\KR-撤离版\KR_脱壳dump.exe"

with open(DUMP, "rb") as f:
    data = f.read(0x1000)

e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
assert data[e_lfanew:e_lfanew+4] == b"PE\0\0", "not a PE"
machine, nsec, _, _, _, optsz, chars = struct.unpack_from("<HHIIIHH", data, e_lfanew+4)
opt_off = e_lfanew + 24
magic = struct.unpack_from("<H", data, opt_off)[0]
image_base = struct.unpack_from("<Q", data, opt_off+24)[0] if magic == 0x20B else struct.unpack_from("<I", data, opt_off+28)[0]
ep_rva = struct.unpack_from("<I", data, opt_off+16)[0]
image_size = struct.unpack_from("<I", data, opt_off+56)[0]

print(f"machine=0x{machine:X} nsec={nsec} magic=0x{magic:X}")
print(f"ImageBase=0x{image_base:X} EP_RVA=0x{ep_rva:X} SizeOfImage=0x{image_size:X}")

sec_off = opt_off + optsz
sections = []
print(f"{'Name':10s} {'VirtAddr':>10s} {'VirtSize':>10s} {'RawPtr':>10s} {'RawSize':>10s} {'Char':>10s}")
for i in range(nsec):
    o = sec_off + i*40
    name = data[o:o+8].rstrip(b"\0").decode(errors="replace")
    vs, va, rs, rp = struct.unpack_from("<IIII", data, o+8)
    ch = struct.unpack_from("<I", data, o+36)[0]
    sections.append((name, va, vs, rp, rs, ch))
    print(f"{name:10s} 0x{va:08X} 0x{vs:08X} 0x{rp:08X} 0x{rs:08X} 0x{ch:08X}")

import os
fsize = os.path.getsize(DUMP)
print(f"\nfile size = 0x{fsize:X} ({fsize})")

def rva_to_off(rva):
    for name, va, vs, rp, rs, ch in sections:
        if va <= rva < va + max(vs, rs):
            delta = rva - va
            if delta < rs:
                return rp + delta, name
            return None, name  # virtual only
    return None, "?"

# verify key RVAs
for rva in (0x5CA1900, 0x5CA1C67, 0x5CA1CA1, 0x617AD0, 0x5C954FA, 0x5C72000):
    off, sec = rva_to_off(rva)
    print(f"RVA 0x{rva:X} -> file off 0x{off:X} ({sec})" if off is not None else f"RVA 0x{rva:X} -> NOT MAPPED raw ({sec})")

# Save section table for later steps
with open(r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\分析工作区\pe_sections.txt", "w") as f:
    f.write(f"ImageBase=0x{image_base:X}\nEP_RVA=0x{ep_rva:X}\n")
    for name, va, vs, rp, rs, ch in sections:
        f.write(f"{name}\t0x{va:X}\t0x{vs:X}\t0x{rp:X}\t0x{rs:X}\t0x{ch:X}\n")
print("\nsection table saved.")
