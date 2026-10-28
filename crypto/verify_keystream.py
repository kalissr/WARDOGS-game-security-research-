#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
WARDOGS KR 撤离版 — cache 密钥流重用验证与恢复脚本（本地可复现）
语料: C:\\Users\\<SANITIZED>\\Desktop\\KR\\cache\\*.bin（12 个加密 blob，2026-10-19 / 10-26 两批）

已确认事实（2026-10-27）:
  - 载荷 = glTF 2.0 GLB 三维地图模型（generator: glTF-Transform v4.x），非 PE
  - 文件格式 = [14B 头][密钥流 XOR 加密的 GLB[14:]]
  - 头部: [0:4) keyid  [4:8) 构建时间戳 LE32  [8:12) 逐文件序列号(不参与密钥流)
         [12:14) 2 字节标志
  - 密钥流按 keyid 分组共用；G2 组 6,257,266B 完整密钥流已恢复，
    四文件重叠区 100.000% 一致（见 crypto/ks_G2.bin, crypto/decrypted_G2/）

用法:
  python verify_keystream.py                      # 统计验证（熵/零率/头部/组聚类）
  python verify_keystream.py --recover <dump目录> # 从内存明文 dump 恢复新组密钥流
     dump 目录约定: <name>.bin(密文在 cache) 与 mem_*.bin(明文) 尺寸自动配对，
     自动差分对齐（明文对零游程位置 = 密文对位置 + 0x60 的映射）
"""
import os, sys, math, itertools

CACHE = r"C:\Users\<SANITIZED>\Desktop\KR\cache"
KEYSTREAM_DIR = os.path.dirname(os.path.abspath(__file__))

GROUPS = {
    "G1-1019(小)":  ["6F7lrDX.bin", "XnznHyt.bin", "j05Qk3zi03.bin", "pfdF4gili.bin"],
    "G2-1019(地图)": ["7qYhz1e.bin", "rP3h.bin", "sOnRH.bin", "zS39m.bin"],
    "G3-1026(大)":  ["01UHvMX.bin", "N8ww1h.bin", "ktZzEPg5O.bin", "mktfZ5EB.bin"],
}
HDR_LEN = 0x0e          # 密文起点
DUMP_PREFIX = 0x60      # mem dump 中 GLB 魔数固定前缀
DUMP_PAYLOAD = 0x6e     # dump 内与 cache[0x0e] 对齐的位置（= 0x60 + 0x0e）

def entropy(b):
    if not b:
        return 0.0
    cnt = [0] * 256
    for x in b:
        cnt[x] += 1
    n = len(b)
    return -sum((c / n) * math.log2(c / n) for c in cnt if c)

def zero_runs(a, b, minlen, limit):
    n = min(len(a), len(b), limit)
    x = bytes(p ^ q for p, q in zip(a[:n], b[:n]))
    runs, cur, start = [], 0, 0
    for i, byte in enumerate(x):
        if byte == 0:
            if cur == 0:
                start = i
            cur += 1
        else:
            if cur >= minlen:
                runs.append((start, cur))
            cur = 0
    if cur >= minlen:
        runs.append((start, cur))
    return runs

def stats(files):
    print(f"[1] 语料 {len(files)} 个文件，熵(前64KB) ≈ 8.0，无块结构 → 流密码(XOR流)")
    for n in sorted(files):
        print(f"    {n:16s} {len(files[n]):>10,}B  H={entropy(files[n][:65536]):.4f}")

    print("\n[2] 两两 XOR 零字节率（随机基线 0.39%）—— 组内抬升 = 密钥流重用")
    for g, ns in GROUPS.items():
        print(f"    -- {g}")
        for a, b in itertools.combinations(ns, 2):
            if a not in files or b not in files:
                continue
            da, db = files[a], files[b]
            n = min(len(da), len(db))
            x = bytes(p ^ q for p, q in zip(da[:n], db[:n]))
            runs = zero_runs(da, db, 16, 8192)
            top = ", ".join(f"0x{s:x}(+{l})" for s, l in runs[:4])
            print(f"    {a:15s}^{b:15s} zero={x.count(0)/n*100:6.2f}%  runs≥16: {top or '无'}")

    print("\n[3] 头部 14 字节结构（keyid = 密钥流分组依据）")
    for g, ns in GROUPS.items():
        print(f"    -- {g}")
        for n in ns:
            if n in files:
                h = files[n][:HDR_LEN + 2]
                print(f"    {n:15s} keyid={h[:4].hex()} ts=0x{int.from_bytes(h[4:8],'little'):08x} "
                      f"serial={h[8:12].hex()} flags={h[12:14].hex()} (密文自{HDR_LEN:#x}起)")

def recover(dump_dir):
    """从黄金采集/cache_解密dump 风格的内存明文恢复密钥流（差分对齐法）"""
    files = {n: open(os.path.join(CACHE, n), "rb").read()
             for n in os.listdir(CACHE) if n.endswith(".bin")}
    dumps = {n: open(os.path.join(dump_dir, n), "rb").read()
             for n in os.listdir(dump_dir) if n.endswith(".bin")}
    # 尺寸配对: dump 大小 ≈ cache 大小（+0.1% 内）
    matched = []
    for cn, c in sorted(files.items()):
        for dn, d in sorted(dumps.items()):
            if 0 < len(d) - len(c) < len(c) * 0.002 and d.find(b"glTF", 0, 0x100) >= 0:
                matched.append((cn, dn))
                break
    if not matched:
        print("未找到可配对的 dump（需含 glTF 魔数且尺寸与 cache 相差 <0.2%）")
        return
    print(f"[配对] {matched}")
    # 对齐: 明文对零游程位置 = 密文对位置 + (dump_prefix + HDR_LEN - 0) 的映射
    ks_all = {}
    for cn, dn in matched:
        c, d = files[cn], dumps[dn]
        g = d.find(b"glTF", 0, 0x100)
        n = min(len(c) - HDR_LEN, len(d) - (g + HDR_LEN))
        if n <= 0:
            continue
        ks_all[cn] = bytes(p ^ q for p, q in zip(c[HDR_LEN:], d[g + HDR_LEN:g + HDR_LEN + n]))
    if len(ks_all) >= 2:
        print("[一致性] ", end="")
        for a, b in itertools.combinations(ks_all, 2):
            n = min(len(ks_all[a]), len(ks_all[b]))
            same = sum(1 for x, y in zip(ks_all[a], ks_all[b]) if x == y)
            print(f"{a}~{b}: {same/n*100:.3f}% ", end="")
        print()
    if ks_all:
        best = max(ks_all, key=lambda k: len(ks_all[k]))
        ks = ks_all[best]
        out = os.path.join(KEYSTREAM_DIR, f"ks_{best.split('.')[0]}.bin")
        open(out, "wb").write(ks)
        print(f"[输出] {out} ({len(ks):,}B)  基于 {best}")
        print("[解密验证] ", end="")
        import struct
        for cn, dn in matched:
            if cn not in ks_all:
                continue
            c, d = files[cn], dumps[dn]
            g = d.find(b"glTF", 0, 0x100)
            body = bytes(p ^ q for p, q in zip(c[HDR_LEN:], ks[:len(c) - HDR_LEN]))
            glb = d[g:g + HDR_LEN] + body
            magic, _, total = struct.unpack("<4sII", glb[:12])
            print(f"{cn}: magic={magic} len{'✓' if total == len(glb) else '✗'} ", end="")
        print()

if __name__ == "__main__":
    if len(sys.argv) >= 3 and sys.argv[1] == "--recover":
        recover(sys.argv[2])
    else:
        files = {n: open(os.path.join(CACHE, n), "rb").read()
                 for n in os.listdir(CACHE) if n.endswith(".bin")}
        stats(files)
        print("\n[结论] 组内密钥流重用（G1 全文件 6-15% 零率; G2 已 100% 全文件实证并恢复完整流）；")
        print("       密钥流按 keyid 分组, [8:12) serial 不参与; KS=C^P, 见 KEYSTREAM-PoC.md")
