#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ChaCha20 内嵌密钥滑窗暴破：用已恢复的 ks_G2.bin 作判据。
对目标二进制每个偏移取 32B 作 key，配合 nonce 候选，比对 keystream 前 8 字节。
用法: python brute_chacha.py <目标二进制> [nonce变体集: packed|full]
"""
import sys, struct
import numpy as np

KS = open(r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\KR-撤离版\crypto\ks_G2.bin", "rb").read()
TARGET0 = KS[:8]
keyid = bytes.fromhex("4f5b87eb")
ts_le = struct.pack("<I", 0x64ed03b6)

def n12(*parts):
    b = b"".join(parts)
    return (b + b"\x00" * 12)[:12]

PACKED_NONCES = {  # nonce12 -> 名字（counter=0 与 1 两个变体）
    "zero":      bytes(12),
    "keyid+z8":  n12(keyid),
    "z8+keyid":  n12(b"\x00"*8, keyid),
    "keyid*3":   keyid*3,
    "keyid+ts":  n12(keyid, ts_le),
    "ts+keyid":  n12(ts_le, keyid),
}
FULL_NONCES = dict(PACKED_NONCES)
FULL_NONCES.update({
    "keyid+keyid+z4": n12(keyid, keyid),
    "ts+z8":          n12(ts_le),
    "z4+ts":          n12(b"\x00"*4, ts_le),
    "keyid+z4+ts":    n12(keyid, b"\x00"*4, ts_le),
})

def rotl(x, n):
    return (np.left_shift(x, n) | np.right_shift(x, 32 - n)).astype(np.uint32)

def qr(s, a, b, c, d):
    s[:, a] = s[:, a] + s[:, b]; s[:, d] = rotl(s[:, d] ^ s[:, a], 16)
    s[:, c] = s[:, c] + s[:, d]; s[:, b] = rotl(s[:, b] ^ s[:, c], 12)
    s[:, a] = s[:, a] + s[:, b]; s[:, d] = rotl(s[:, d] ^ s[:, a], 8)
    s[:, c] = s[:, c] + s[:, d]; s[:, b] = rotl(s[:, b] ^ s[:, c], 7)

def chacha_first8(k_words, nonce_words, counter):
    """k_words: (N,8) uint32; nonce_words: (3,) uint32 -> keystream 前8B (N,8字节)"""
    N = k_words.shape[0]
    x = np.empty((N, 16), dtype=np.uint32)
    x[:, 0] = 0x61707865; x[:, 1] = 0x3320646E
    x[:, 2] = 0x79622D32; x[:, 3] = 0x6B206574
    x[:, 4:12] = k_words
    x[:, 12] = np.uint32(counter)
    x[:, 13] = nonce_words[0]; x[:, 14] = nonce_words[1]; x[:, 15] = nonce_words[2]
    s = x.copy()
    for _ in range(10):
        qr(s, 0, 4, 8, 12); qr(s, 1, 5, 9, 13); qr(s, 2, 6, 10, 14); qr(s, 3, 7, 11, 15)
        qr(s, 0, 5, 10, 15); qr(s, 1, 6, 11, 12); qr(s, 2, 7, 8, 13); qr(s, 3, 4, 9, 14)
    out = (s + x).astype(np.uint32)
    w0 = out[:, 0]; w1 = out[:, 1]
    b = np.empty((N, 8), dtype=np.uint8)
    b[:, 0:4] = (w0 & 0xFF).astype(np.uint8)[:, None]
    b[:, 1] = ((w0 >> 8) & 0xFF).astype(np.uint8); b[:, 2] = ((w0 >> 16) & 0xFF).astype(np.uint8)
    b[:, 3] = ((w0 >> 24) & 0xFF).astype(np.uint8)
    b[:, 4] = (w1 & 0xFF).astype(np.uint8); b[:, 5] = ((w1 >> 8) & 0xFF).astype(np.uint8)
    b[:, 6] = ((w1 >> 16) & 0xFF).astype(np.uint8); b[:, 7] = ((w1 >> 24) & 0xFF).astype(np.uint8)
    return b

def main():
    target = sys.argv[1]
    variants = FULL_NONCES if (len(sys.argv) > 2 and sys.argv[2] == "full") else PACKED_NONCES
    data = np.frombuffer(open(target, "rb").read(), dtype=np.uint8)
    n_win = len(data) - 32 + 1
    target_arr = np.frombuffer(TARGET0, dtype=np.uint8)
    print(f"目标: {target}  窗口数: {n_win:,}  nonce 变体: {len(variants)} × counter 0/1")
    hits = []
    CH = 1 << 20
    for name, nonce in variants.items():
        nw = np.frombuffer(nonce, dtype="<u4").astype(np.uint32)
        for ctr in (0, 1):
            found = None
            for base in range(0, n_win, CH):
                m = min(CH, n_win - base)
                # 滑窗 key 词: (m, 8) —— 从 32 字节窗口读 8 个 LE32
                idx = np.arange(m)[:, None] + np.arange(32)[None, :]
                win = data[idx]  # (m,32) uint8
                kw = win.reshape(m, 8, 4).copy().view(np.uint8).reshape(m, 32)
                kw = kw.view("<u4").astype(np.uint32)  # (m,8)
                out8 = chacha_first8(kw, nw, ctr)
                eq = (out8 == target_arr).all(axis=1)
                if eq.any():
                    off = int(np.nonzero(eq)[0][0]) + base
                    found = off
                    break
                del idx, win, kw, out8, eq
            tag = f"nonce={name} ctr={ctr}"
            if found is not None:
                key = bytes(data[found:found+32])
                print(f"  ✓✓✓ 命中 @{found:#x} key={key.hex()}  {tag}")
                hits.append((found, key.hex(), name, ctr))
            else:
                print(f"  ✗ {tag}")
    print("结果:", hits if hits else "未命中")

if __name__ == "__main__":
    main()
