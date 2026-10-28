# Game Security Research — Cheat Sample Analysis

## Notice

Certain infrastructure addresses, operator credentials, and developer information present in the original cheat sample have been **intentionally redacted** from this repository. This redaction is applied as a **humanitarian measure** — to protect individuals who may have been coerced or economically pressured into participating in this operation, and to prevent this data from being weaponized for doxxing or harassment.

Specifically removed:
- Operator infrastructure addresses (real server IPs behind CDN)
- Developer/operator personal identifiers
- Payment and credential chains
- Individual reseller contact information

The analysis focus is on **game security weaknesses** that the developer should patch, not on attacking the individuals behind the cheat.

---

## Game Security Vulnerabilities Identified

The following vulnerabilities in the game client were identified through reverse engineering of a third-party cheat sample:

### 1. Server-Side Validation Missing (Severity: HIGH)
The game trusts client-side state for movement, combat, and economy. A cheat can:
- Track perfect movement paths with machine precision
- Auto-purchase supplies with exact trigger conditions
- Follow optimal routes without any server-side anomaly detection

**Fix**: Implement server-authoritative movement validation, input entropy analysis, and economic behavior profiling.

### 2. External Memory Reading (Severity: HIGH)
Standard user-mode process can read game memory via direct syscalls without any kernel-level anti-cheat blocking read-only access.

**Fix**: Deploy kernel-level anti-cheat (EAC/BattlEye/ACE tier); implement ObRegisterCallbacks handle stripping; detect high-frequency ReadProcessMemory patterns.

### 3. UE Reflection System Exposed (Severity: MEDIUM)
4,279 static offsets to GObjects/GNames/GWorld are fully functional and extracted. All game entities readable via reflection system.

**Fix**: Perturb offsets on each update; encrypt GObjects/GNames pointers; remove critical properties from reflection.

### 4. Map Data Plaintext in Memory (Severity: LOW-MEDIUM)
Full glTF road network (43,988 vertices) exists in process memory as plaintext during gameplay.

**Fix**: Runtime encryption or on-demand streaming of navigation data.

---

## Repository Contents

| Directory | Description |
|---|---|
| `crypto/` | Encryption analysis of asset protection scheme |
| `分析工具/` | Static analysis: VMP disassembly, anti-debug audit, heap forensics |
| `协议样本/` | Communication protocol samples (redacted) |
| `基础设施/` | Infrastructure assessment (redacted) |
| `黄金采集/` | Runtime data: UE offsets, waypoints, string tables |

## Methodology

Standard binary analysis: PE unpacking → IDA/Ghidra decompilation → string decryption (FNV variant) → protocol capture → differential analysis → heap forensics.

All findings verified through multiple independent evidence chains.

## Disclosure

This report is prepared for responsible disclosure to the game developer.
