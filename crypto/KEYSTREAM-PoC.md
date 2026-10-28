# KEYSTREAM-PoC — <PRODUCT> <TARGET_APP> cache 加密体系密钥流重用（v2）

> v2（2026-10-27）：利用 `黄金采集/cache_解密dump/` 的运行时内存明文，**完整恢复 G2 组
> 6,257,266 字节密钥流并离线解密该组全部 4 个文件**；载荷确认为 glTF 三维地图（修正 v1
> 的 PE 假设）。v1 基于统计的证据链保留，全部结论升级为实证。

## 0. 与既有报告的关系（诚实性声明）

| 声称来源 | 内容 | 本机核查 |
|---|---|---|
| 原专项②报告 | GitHub 仓库 183 文件共用 1 条密钥流 | 仓库/样本不存在，不可复核；本地语料为**按 keyid 分组、每组一条** |
| 原专项②报告 | KPA 交叉解密 DOS stub + MZ | 载荷实为 **glTF GLB**（非 PE），原验证系循环论证且模板错误 |
| 本 PoC v1 | PE@0x0e 假设 | 已修正（GLB@0x0e）；密钥流重用结论不变，且已升级为全文件实证 |
| 专项④报告 | 前端 bundle Wa/Qa、pluginlist.json 71 项、ddragon 13.10.1 等 | 前端 bundle/pluginlist/GitHub 克隆**均不在本机**，六条证据链全部不可复核 |

## 1. 语料与分组

`C:\Users\<SANITIZED>\Desktop\<TARGET>\cache\*.bin`，12 个文件，头 14 字节 = 明文元数据：

| 组 | 文件 | 尺寸 | keyid | 用途（已实证/推断） |
|---|---|---|---|---|
| G1 | 6F7lrDX/XnznHyt/j05Qk3zi03/pfdF4gili | 39-412KB | `2836d3ad` | 小资产（物品库等，1099 条物品数据） |
| G2 | 7qYhz1e/rP3h/sOnRH/zS39m | 2.5-6.3MB | `4f5b87eb` | **四张地图 glTF 模型（已解密）** |
| G3 | 01UHvMX/N8ww1h/ktZzEPg5O/mktfZ5EB | 5.5-11.5MB | `7f739e9c` | 10-26 新批大文件（待明文） |

头部字段：`[0:4) keyid（选密钥流） [4:8) 构建时间戳 LE32 [8:12) 逐文件序列号
[12:14) 标志`。**序列号逐文件变化但密钥流不变**（G2 四文件序列号互不相同、流却
100% 一致）→ nonce/IV 形同虚设的直接实证。

## 2. 文件格式（实证）

```
cache file = [14B 明文头] + [ KS[i] ^ GLB[14+i] ]
GLB = glTF 2.0 二进制，generator = glTF-Transform v4.x
内存 dump 中 GLB 对象头固定 0x60 字节前缀，payload 与 cache[0x0e] 对齐于 dump[0x6e]
```

## 3. 证据链

### 3.1 统计层（v1，仍成立）
- 12 文件熵 ≈ 8.0，无块结构。
- G1 组内两两 XOR 零率 6.05%–15.56%（基线 0.39%）；G2 组内 1.28%–2.92% 且头部
  [0x0e:0x9d) 143B、[0x9e:0xdd) 63B 一致游程；跨组全部基线、零命中。

### 3.2 实证层（v2 新增，决定性）
1. **配对**：`黄金采集/cache_解密dump/` 四个 mem dump 尺寸与 G2 四文件相差 <0.06%，
   且 glTF 魔数均在 0x60。
2. **差分对齐**：明文对的长零游程位置 = 密文对位置 + 0x60（含 0x9d/0xfd 一字节
   变体的精确对应）→ `cache[0x0e+i] ↔ dump[0x6e+i]`。
3. **密钥流提取与一致性**：`KS = C ^ P` 逐文件提取，四文件重叠区
   **100.000% 一致**（最大 6,257,266B，最小重叠 2,498,434B）。
4. **结构性验证（非循环）**：用共识流解密重建 4 个 GLB，magic=glTF、version=2、
   **总长字段与文件长度 4/4 精确相等**、JSON 块可读且以 `{"asset":{"generator":
   "glTF-Transform v4` 开头。错误密钥流不可能同时满足四个独立结构约束。
5. **组隔离**：KS_G2 施于 G1/G3 输出乱码 → 每组独立流，与 3.1 跨组零命中一致。
6. **流性质**：KS 熵 7.9998、256B–64KB 周期检验均为随机基线 0.39% → 无短周期
   伪随机流，与工作区 AES-NI 动态痕迹（aes_trace.txt / kr_aesni*.js）吻合，
   推测 AES-CTR 类固定 nonce 实现（对攻击面而言 primitive 无关紧要：固定流）。

### 3.3 密钥流生成器识别（v3 新增，2026-10-27 深夜）

用完整 6.26MB 密钥流作判据排除弱构造（全部未命中）：

- 哈希扩展派生：MD5/SHA1/SHA256 × {keyid, ts, keyid+ts, …} 种子 × 独立/CTR 模式 ✗
- MT19937：直接状态恢复（LE/BE 字打包，前 624 词反 temper 后预测后续）✗
- 种子直推：MT/xorshift32/MSVC rand/minstd/splitmix64 × {keyid,ts,xor,…} 及
  0–65535 小种子暴破 ✗
- xorshift32/64 相邻词递推一致性（常用参数组）✗
- LCG 全状态输出求解（解出 a=0xfc6c78e/c=0xde850baf 不自洽）✗
- AES-CTR / ChaCha20 结构化猜测（keyid/ts 派生 key×nonce 组合）✗

**结论**：流由带密钥的 CSPRNG 生成，无法从头部字段或流本身反推——密钥只能取自
loader 内部。**loader 内已定位完整 ChaCha20 实现**（反编译
`KR_功能实现_反编译_13387函数.c`：sub_140329150 = init，"expand 32-byte k" +
key 32B；sub_140329A60 = counter/nonce 设置；sub_14032A050 = 流 XOR；二进制内
另有两处 ChaCha 常量表与 AES Te/Td 表）→ cache 加密几乎确定为 ChaCha20，
密钥内嵌于 `wq7iw02606g581.exe`（明文 PE）或其脱壳映像。
`brute_chacha.py`：numpy 向量化滑窗密钥暴破（自测对 RFC 8439 向量 + cryptography
库双向校验通过），命中即三组全部离线可解、无需任何外部明文。

### 3.4 跨产品线对照（conv-10 归档，<VENDOR> GitHub 分发语料）

同一运营方另一条产品线（<AUTH_API> / LOL 插件）的加密为**另一套部署**：
[16B 头][流加密 PE@0x10]、密钥流**全库统一一条**（71/71 插件实证），
与 <TARGET> cache 的 per-keyid 分组不同。两线共性：固定密钥流 XOR 重用。
详见 `C:\Users\<SANITIZED>\Downloads\555\extracted\conv-10\VERIFICATION-交叉复核.md`。

## 4. 交付物

```
crypto/ks_G2.bin                 G2 组完整密钥流 6,257,266B（四文件 100% 共识）
crypto/decrypted_G2/*.glb        四张地图完整 GLB（离线解密产物）
crypto/verify_keystream.py       统计验证 + --recover 模式（对新组重放同样方法）
```

## 5. 解密路线图（G1/G3 收尾）

1. **重放本方法**：游戏内加载对应资产时用黄金采集同款 ReadProcessMemory dump
   （方法已验证），`python verify_keystream.py --recover <dump目录>` 自动配对、
   对齐、提取、验证。
2. **loader 逆向**（一劳永逸）：逆向 `wq7iw02606g581.exe` 的 keyid→流派生
   （KR_IDA数据库.i64 已就绪；工作区已有 AES 调用点定位痕迹），可离线生成任意组
   密钥流，不依赖任何明文。
3. 观察项：G3 首文件用 KS_G2 解出的前几字节呈 `00000100 00000000 d042` 的整齐
   模式，提示 G3 流与 G2 流**前若干字节可能相同随后分叉**（CTR 结构线索），
   逆向派生函数时可作校验点。

## 6. 危害定性（不变，且加强）

加密是该业务（卡密 3–20 美元/天）对 cache 资产（三维地图/物品库，自研数据）的
唯一保护。密钥流按组固定重用：**本 PoC 已把"任一明文泄露=全组泄露"从推论变成
成品——G2 组已整体离线可解**。keyid 明文存放、序列号不参与流派生，运营方无法
通过轮换序列号止损，只能整体换 keyid 并重发全量资产。
