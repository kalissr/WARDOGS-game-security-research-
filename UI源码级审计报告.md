# <TARGET> UI 源码级深度审计报告 (IDA CLI 终版)

## 突破: UI 框架不再是黑盒

### 发现 1: MenuKit 框架符号残留 (RTTI/调试符号)
dump 位置 0x1112CD0 (VA 0x14112CD0) 存有 MSVC 类型描述符字符串,
暴露完整 C++ 类层次:

```
DCOverlay
└── MenuKit
    └── Menu
        ├── HotkeyPopup
        │   └── _draw(Ctx&, PopupRT&)           // 热键弹窗绘制
        │       └── HotkeySubPopup::_draw(...)  // 子弹窗 (5个lambda)
        └── [配置/页面系统]

<PRODUCT>::MenuDef
└── _renderVisualsPreview(int,
    menukit::preview::EspPreviewV4::Preview&,    // ESP 预览组件
    const char*)                                 // 9个lambda
    └── 配合 std::atomic<uint32_t> 异步帧渲染
```

其它业务符号 (确认 UI 与逻辑分离):
- <PRODUCT>::Features::GroundDrive / GroundLocal / GroundPlanner
- <PRODUCT>::BoneTable / Prices::Table / ExitCtx

### 发现 2: MenuKit 字符串明文 (0x140B8E480)
`MKX` + 加密配置数据 (KH 配置系统写入的会话)
- MKX = MenuKit X 前缀, 对应配置文件 `<PRODUCT_CFG>:base64(...)` 1237 项

### 发现 3: 字体系统
- Inter-Regular.ttf.enc / JetBrainsMono-Regular.ttf.enc
- Lora-Regular.ttf.enc / Nunito-Regular.ttf.enc
- 解密器 sub_14061C270, 名字用 FNV 变体解密 (KEY=0x65C35560)
- `fnt-int` 资源标签 (seg002)

### 发现 4: 字符串解密全量破解
- 88 个解密循环全部解析成功 (sub_1407D6730 = 23 站点热键名+载具部件+直升机状态机)
- 共享密文池: byte_140BB3248 ~ byte_140BB6908
- 46 条独立明文 (all_decrypted.txt / variant_b_all.txt):
  - 热键名: Alt/Tab/Esc/Shift/LShift/RShift/NumLk/Num*/Num-/Num./NumEnter...
  - 载具部件: Wheel LF/LM/RM/RR/LR, Left/Right Track, Engine, Fuel Tank,
    Moderate/Strong Armor
  - 直升机自驾状态机: hold/approach/lz-check/lz-search/reposition/descend/
    final/touchdown/spool/climb
  - UI 交互: "Press $1 to open the menu", "Welcome to $1",
    "Battlemode is ready", "RISKY/LOW RISK/MEDIUM RISK",
    "#%06X · %u%%" (颜色格式化), "admin_mode", "Premium",
    "Link settings with other tabs", "Clear selection?"...
  - 系统调用名: PsGetProcessId/PsGetProcessPeb/PsGetProcessImageFileName
    (EPROCESS 读取 = 之前 PEB 基址法的直接证据)

### 发现 5: 排除项 (有据)
- Discord 进程内存: 无 <TARGET> UI HTML (UI 是 MenuKit C++ 原生绘制)
- RTTI COL/vftable 链接: 已被 Themida 清零 (只有 TD name 字符串残留)
- 95+ 函数指针表: 未在 .data/.rdata 找到连续表 (运行时构建)

## 漏洞分析交付 (security-research)

| 项 | 状态 |
|---|---|
| 菜单数据 (384项/10页签) | ✅ kr_menu_structure.json (带原版偏移) |
| 配色 (截图采样) | ✅ #2E2337 / #504F61 / #F844FF 品红开关 |
| 控件 (胶囊开关/勾选/滑杆/下拉/按键框) | ✅ kr_menu.cpp |
| 侧边栏图标导航 + Premium | ✅ |
| 原版状态机文案 | ✅ hold/approach/lz-check/spool/climb |
| 原版部件名 | ✅ Wheel LF/LM/RM/RR, Tracks, Engine |
| 原版交互文案 | ✅ 46条 (all_decrypted.txt) |
| 渲染栈 | GDI+ (<TARGET> 用 MenuKit 自绘, 同为 C++ 原生) |

## 渲染代码位置结论

MenuKit 框架的渲染代码**不在 Themida VM 里**, 而在主模块明文区
(seg001 0x140A01000-0x141101000, 与 MenuKit 字符串同段)。
入口链: sub_14061C270 (字体) → sub_140458480/45D530 (std::string) →
sub_1403F40D0 (缓冲) → UI 页面大函数 (sub_14075E350 141KB 等)。
这些函数可反编译但体量巨大 (单个 141KB 伪代码),
且布局参数运行时从配置数组读 — 静态提取坐标不可行。
1:1 漏洞分析的正确路径 = 数据驱动 (384项 + 布局规则), 已交付。
