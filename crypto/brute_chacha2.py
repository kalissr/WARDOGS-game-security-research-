#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ChaCha20 内嵌密钥滑窗暴破（优化版）：用已恢复的 ks_G2.bin 前 8 字节作判据。
零拷贝滑窗（as_strided）+ 词级比较。
用法: python brute_chacha2.py <目标二进制> [packed|full] [起始变体索引]
自测: python brute_chacha2.py --selftest
"""
import sys, struct
import numpy as np

KS = open(r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\KR-撤离版\crypto\ks_G2.bin", "rb").read()
TGT0 = KS[:8]
TGT_W = np.frombuffer(TGT0, dtype="<u4").astype(np.uint32)  # 2 个目标词
keyid = bytes.fromhex("4f5b87eb")
ts_le = struct.pack("<I", 0x64ed03b6)

def n12(*parts):
    b = b"".join(parts)
    return (b + b"\x00" * 12)[:12]

NONCES = {
    "zero":      bytes(12),
    "keyid+z8":  n12(keyid),
    "z8+keyid":  n12(b"\x00"*8, keyid),
    "keyid*3":   keyid*3,
    "keyid+ts":  n12(keyid, ts_le),
    "ts+keyid":  n12(ts_le, keyid),
    "keyid+keyid+z4": n12(keyid, keyid),
    "ts+z8":     n12(ts_le),
    "z4+ts":     n12(b"\x00"*4, ts_le),
    "keyid+z4+ts": n12(keyid, b"\x00"*4, ts_le),
}
PACKED = ["zero", "keyid+z8", "z8+keyid", "keyid*3", "keyid+ts", "ts+keyid"]

def rotl(x, n):
    return (np.left_shift(x, n) | np.right_shift(x, 32 - n)).astype(np.uint32)

def qr(s, a, b, c, d):
    s[:, a] = s[:, a] + s[:, b]; s[:, d] = rotl(s[:, d] ^ s[:, a], 16)
    s[:, c] = s[:, c] + s[:, d]; s[:, b] = rotl(s[:, b] ^ s[:, c], 12)
    s[:, a] = s[:, a] + s[:, b]; s[:, d] = rotl(s[:, d] ^ s[:, a], 8)
    s[:, c] = s[:, c] + s[:, d]; s[:, b] = rotl(s[:, b] ^ s[:, c], 7)

def first_words(kw, nw, counter, out_w0, out_w1):
    N = kw.shape[0]
    x = np.empty((N, 16), dtype=np.uint32)
    x[:, 0] = 0x61707865; x[:, 1] = 0x3320646E
    x[:, 2] = 0x79622D32; x[:, 3] = 0x6B206574
    x[:, 4:12] = kw
    x[:, 12] = np.uint32(counter)
    x[:, 13] = nw[0]; x[:, 14] = nw[1]; x[:, 15] = nw[2]
    s = x.copy()
    for _ in range(10):
        qr(s, 0, 4, 8, 12); qr(s, 1, 5, 9, 13); qr(s, 2, 6, 10, 14); qr(s, 3, 7, 11, 15)
        qr(s, 0, 5, 10, 15); qr(s, 1, 6, 11, 12); qr(s, 2, 7, 8, 13); qr(s, 3, 4, 9, 14)
    out_w0[:] = s[:, 0] + x[:, 0]
    out_w1[:] = s[:, 1] + x[:, 1]

def selftest():
    from cryptography.hazmat.primitives.ciphers import Cipher, algorithms
    key = bytes(range(32)); blob = bytes(range(16))
    ref = Cipher(algorithms.ChaCha20(key, blob), None).encryptor().update(b"\x00" * 8)
    kw = np.frombuffer(key, dtype="<u4").astype(np.uint32).reshape(1, 8)
    nw = np.frombuffer(blob[4:16], dtype="<u4").astype(np.uint32)
    w0 = np.zeros(1, np.uint32); w1 = np.zeros(1, np.uint32)
    first_words(kw, nw, int.from_bytes(blob[:4], "little"), w0, w1)
    got = struct.pack("<II", int(w0[0]), int(w1[0]))
    print("selftest:", "OK" if got == ref else f"FAIL {got.hex()}!={ref.hex()}")
    return got == ref

def main():
    target = sys.argv[1]
    names = PACKED if len(sys.argv) < 3 or sys.argv[2] != "full" else list(NONCES)
    start = int(sys.argv[3]) if len(sys.argv) > 3 else 0
    raw = open(target, "rb").read()
    words = np.frombuffer(raw, dtype="<u4").astype(np.uint32)
    n_win = len(words) - 7
    print(f"目标 {target}: {len(raw):,}B, 词窗口 {n_win:,}, 变体 {len(names)} (从#{start} 起)")
    CH = 1 << 20
    hits = []
    for vi, name in enumerate(names):
        if vi < start:
            continue
        nw = np.frombuffer(NONCES[name], dtype="<u4").astype(np.uint32)
        for ctr in (0, 1):
            w0 = np.empty(CH, np.uint32); w1 = np.empty(CH, np.uint32)
            found = None
            for base in range(0, n_win, CH):
                m = min(CH, n_win - base)
                # 零拷贝滑窗: 每 4 字节步进的 8 词窗口（字节级步进4 → 只测 4 字节对齐位；
                # 若密钥按字节任意对齐需将 words 改为字节移位版本，先跑对齐版）
                kw = np.lib.stride_tricks.as_strided(
                    words[base:base + m + 7], shape=(m, 8), strides=(4, 4))
                first_words(kw, nw, ctr, w0[:m], w1[:m])
                eq = (w0[:m] == TGT_W[0]) & (w1[:m] == TGT_W[1])
                if eq.any():
                    found = int(np.nonzero(eq)[0][0]) + base
                    break
            tag = f"nonce={name} ctr={ctr}"
            if found is not None:
                key = words[found:found+8].tobytes()
                print(f"  ✓✓✓ 命中 词偏移#{found} (字节{found*4:#x}) key={key.hex()}  {tag}")
                hits.append((found, key.hex(), name, ctr))
            else:
                print(f"  ✗ {tag}", flush=True)
    print("结果:", hits if hits else "未命中")

if __name__ == "__main__":
    if sys.argv[1] == "--selftest":
        sys.exit(0 if selftest() else 1)
    main()
