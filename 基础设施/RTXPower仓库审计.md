# <VENDOR> 分发仓库深度审计报告（<REPO>）

> 审计时间：2026-10-27 深夜 | 方法：GitHub API + raw CDN 全量清单拉取 + 跨时代差分
> 语料：584 个树条目、186 个清单 json（186/186 拉取成功）、跨时代样本 4 个
> 关联：conv-10 归档（此前样本）+ 本审计新证据

## 一、仓库全貌

| 项 | 值 |
|---|---|
| 体积/条目 | 2,093 MB / 584 条（truncated=false，全量） |
| 构成 | 183 个 .dll（1,597MB）+ 185 个 .json 清单 + 52 png + 26 wav + 6 dds + 1 ttf |
| core/ | 112 个 `<32hex>/` 目录，每个 = RTXCore.dll + rtxcore.json(114B) |
| plugins/ | 71 个 dll + 71 个 sidecar json + pluginlist.json(8.4KB) |
| resources/ | 86 个未加密媒体（resourcelist.json 校验一致） |
| 提交 | 263 个：2023-07-02 "the first commit" → 2026-01-09，消息=LOL 版本号 |

## 二、清单结构（验证神谕正式入档）

```json
pluginlist.json 条目: {"filename","hash","orighash"}
rtxcore.json:         {"filename":"RTXCore.dll","hash","orighash"}
sidecar:              {"fileName","name","plugin_type","supported":[英雄ID],"updateTime"}
```

- **hash = 密文 MD5**（三方实证：归档 core1.dll = core/0012386a…/json.hash；
  归档/main/清单三方一致的 AuroraOrbwalker.dll = e4853929…）
- **orighash = 原版明文 MD5**，共 71+112=183 个 —— 任何未来完整解密的终验器
- pluginlist ↔ 目录 71/71 严格一致，无隐藏/孤儿文件
- sidecar updateTime 有 2024-02 值（BGX.dll=1707002732）→ 仓库清单仍在维护，
  与前端 bundle 2023 冻结数据互补（不矛盾：两套数据源）

## 三、历史深审（本轮新增，此前无人查过）

1. **加密自第一天存在**：首提交（2023-07-02）插件/core 头部即密文（16B 头+流），
   无明文窗口。
2. **无明文原件混入**：现存文件 MD5 与全部 183 个 orighash 零匹配（自比对干净）。
3. **★ 密钥流 2.5 年全长恒定（决定性）**：
   - AuroraOrbwalker 首提交(378,384B) vs main(380,298B)：全重叠 XOR 零率 **99.99%**
     （[0x10:0x80)/[0x400:+) 均 100%，仅 [0x80:0x400) Rich/链接器区 97.43%）
   - BenAIO 首提交 vs 当前：**99.99%**
   - 首提交插件/core 与当前 main 的 [0x10:0x40) 48B 逐位相同
   - 含义：**任一时点恢复的密钥流可解全部 263 个提交里的全部 295 个二进制**，
     含早已过期的历史卡密构建
4. **产品演化路径**：core 从 3.7MB(2023-07) → 13.6MB(2026)；插件几乎冻结
   （2.5 年只追加 ~2KB）→ 开发投入全在自研 core，插件生态确系搬运。

## 四、"完整突破"判定

| 路线 | 本轮结论 |
|---|---|
| 仓库内明文泄漏 | ✗ 排除（首提交即加密 + 自比对干净） |
| orighash 外部匹配（原版公开可得的假设） | ✗ **前提比原报告更弱**：71 个 orighash 无任何公开索引；BGX/Aurora 系付费私有渠道分发（elitepvpers/memoryhackers 均为讨论帖无直链），搜到的下载面仅限私域 |
| 纯密码学 | ✗ 信息论边界（~0.1%）不变 |
| **运行时 dump（推荐）** | ✓ 唯一确定路径：客户端跑一次 + Frida 挂解密点/dump 已解密 core；13.6MB 明文 → 全历史 295 个文件离线可解 → orighash 终验 |

## 五、新增证据文件

```
rtx-audit/
├── rtx_tree.json                  全量目录树（584 条含尺寸）
├── commits_p1-3.json              263 个提交全量元数据
├── first_tree.json                首提交目录树（209 条）
├── manifests/                     186 个清单（pluginlist + 112 rtxcore + 71 sidecar + resourcelist）
├── bin/                           跨时代样本（首提交×2 + main×2）
└── 仓库审计报告.md                本文件
```

## 六、给后续执行者的一句话

密钥流恒定已全长实证、验证神谕（orighash）已入档、仓库侧攻击面已穷尽——
**突破点不在仓库，在客户端运行时**。dump 一份已解密产物（任何时代、插件或 core 均可，
越长越好），`KS = cipher ^ plaintext`，183 个 orighash 逐个验真。
