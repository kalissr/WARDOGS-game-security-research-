import sys, struct
import numpy as np
import brute_chacha2 as bc

target = r"C:\Users\<SANITIZED>\Desktop\WARDOGS功能\KR-撤离版\KR_脱壳dump.exe"
raw = open(target, 'rb').read()
words = np.frombuffer(raw, dtype='<u4').astype(np.uint32)
n_win = len(words) - 7
CH = 1 << 22
print(f"dump: {len(raw):,}B, 窗口 {n_win:,}, 大块 {CH:,}", flush=True)
# 最优先的 keyid-nonce 变体 + 8B-nonce 布局补一个
bc.NONCES["z4+keyid+z4"] = (b"\x00"*4 + bc.keyid + b"\x00"*4)[:12]
sel = ["keyid+z8", "z8+keyid"]
hits = []
for name in sel:
    nw = np.frombuffer(bc.NONCES[name], dtype='<u4').astype(np.uint32)
    for ctr in (0, 1):
        w0 = np.empty(CH, np.uint32); w1 = np.empty(CH, np.uint32)
        found = None
        for base in range(0, n_win, CH):
            m = min(CH, n_win - base)
            kw = np.lib.stride_tricks.as_strided(words[base:base+m+7], shape=(m, 8), strides=(4, 4))
            bc.first_words(kw, nw, ctr, w0[:m], w1[:m])
            eq = (w0[:m] == bc.TGT_W[0]) & (w1[:m] == bc.TGT_W[1])
            if eq.any():
                found = int(np.nonzero(eq)[0][0]) + base
                break
        if found is not None:
            key = words[found:found+8].tobytes()
            print(f"✓✓✓ 命中 词#{found} 字节{found*4:#x} key={key.hex()} nonce={name} ctr={ctr}", flush=True)
            hits.append(found)
        else:
            print(f"✗ nonce={name} ctr={ctr}", flush=True)
print("结果:", hits if hits else "未命中")
