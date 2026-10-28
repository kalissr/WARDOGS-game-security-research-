# <TARGET_APP> 完整逆向交付

> 28 个并行 Agent · 72 小时 · 加密破解 + 协议还原 + 基础设施全图 + 绕过框架

## 🔥 最新成果（先读）

- **全案总结报告.md** — 28 Agent 完整战报（加密切碎+协议还原+基础设施+绕过）
- **crypto/KEYSTREAM-PoC.md** — cache 密钥流恢复 PoC（v3）
- **基础设施/资产清单.md** — 全部服务器/域名/分发渠道/后台接口
- **分析工具/vmp_analysis_report.txt** — VMP 判定链还原（常量 0x3D22B75）

## 代码(32.4MB 伪代码)
- KR_功能实现_反编译_13387函数.c   IDA 主反编译(26MB)
- Ghidra补编_1050函数.c            修复 IDA 失败的函数
- Ghidra补编_功能区300函数.c        ESP/驾驶/障碍核心逻辑
- 注入模块_反编译_138函数.c         Discord 渲染模块
- KR_IDA数据库.i64                  可交互分析(660MB)
- 注入模块_IDA库.i64                Discord 模块(21MB)
- KR_脱壳dump.exe                   运行时内存 dump(101MB)

## 加密破解 crypto/
- ks_G1.bin / ks_G2.bin / ks_G3.bin   密钥流（12/12 cache 可解）
- decrypted_G1/ decrypted_G2/          解密后的字体和地图
- verify_keystream.py                  统计验证 + --recover 模式
- brute_chacha.py / brute_chacha2.py   ChaCha 密钥暴破工具
- KEYSTREAM-PoC.md                     完整 PoC 文档

## Frida 脚本 Frida脚本/ (23 个)
- kr_nuke_v2.js             ★ 驻留桩（进程永不死，GC 修复版）
- kr_final_bypass.js        ★ 全合一绕过（驻留+重定向+ChaCha+NOP）
- kr_redirect_mitm.js       MITM 流量重定向
- kr_chacha_keydump.js      ChaCha 三钩密钥捕获
- kr_ban_bypass.js          用户态 HWID 伪造
- kr_full_spoof.js          全量身份伪造
- kr_patch_auth3.js         三层 auth3 补丁方案
- kr_filetrace.js           文件访问追踪
- kr_exit_trace.js          退出点追踪
- ... (14 more)

## MITM 中间人 MITM/ (7 代演进)
- mitm_nuke2.py             ★ auth_web 伪造 + auth3 转发
- mitm_final.py             终极版（--ks 切换密钥垫）
- forge_auth3.py            auth3 成功应答生成器
- mitm_combo.py             四模式攻击（标记/断连/链式/假设）
- ks_session.bin            auth3 应答密钥流 (165B, 四方验证)
- cert.pem / key.pem        自签 TLS 证书

## 分析工具 分析工具/
- hwbp_auth3.py             硬件断点调试器 (hwbp/poll/deep)
- vmp_disasm_auth3.txt      VMP 完整反汇编 (210KB, 3024 行)
- vmp_analysis_report.txt   判定常量 0x3D22B75 + 完整判定链
- anti_debug_audit.txt      反调试机制审计
- self_protection_analysis.txt  自我保护机制分析
- heap_forensics.txt        堆取证报告
- chacha_trace_result.txt   ChaCha 调用链追踪

## 协议样本 协议样本/
- req714_unique.txt         卡密 <REDACTED-A> 的 auth3 请求 (714B)
- req714_oldkey.txt         卡密 <REDACTED-B> 的 auth3 请求
- auth3_newkey.hex          77090 条请求记录

## 基础设施 基础设施/
- 资产清单.md               ★ 全部服务器/域名/分发渠道
- <VENDOR>       GitHub 仓库深度审计 (263 提交/183 文件)
- VERIFICATION-交叉复核.md  交付物交叉复核
- keystream_bank_hdr.json   71 插件钥流库 (727B)
- rtx_tree.json             仓库全量目录树 (584 条)

## 数据(全部验证过)
- 解密字符串_全量.txt               705 条(逐字节验证)
- 解密cache_物品库.json             1,099 条中文物品
- glTF网格顶点.json                 43,988 个 3D 坐标
- UE偏移表_修正版.json              4,279 个偏移
- 黄金采集/cache_解密dump/          内存解密 dump(含 G2 四地图明文)

## 鉴权协议(完整还原)

```
auth_web (明文 JSON) → MITM 可伪造终身卡 ✅
auth3 (逐会话 ChaCha20 加密) → 判定签名 0x3D22B75 ⛔
黑名单触发器 = 父进程路径上报 (Frida spawn = Python → 自动拉黑)
黑名单存储 = Cloudflare KV (无源站可打)
```

## 架构
外部型作弊(不注入游戏):
  syscall(NtReadVM/NtWriteVM) 读游戏
  → <TARGET> 主进程(逻辑)
  → 跨进程写 31 处
  → Discord 渲染(ESP/菜单)

## 下一步
1. 分销 hwidreset (5 分钟解封) → 全链路跑通
2. hwbp_auth3.py deep 模式逆向 VM 状态推导
3. 换物理机 → 指纹自然改变
