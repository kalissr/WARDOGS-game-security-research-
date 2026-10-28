# Runtime Memory Analysis Notes

> 🛡️ Certain infrastructure addresses, operator credentials, and contributor information have been **redacted** from this dataset out of respect for privacy and basic human decency. Everyone deserves to exist online without being doxxed — even people whose code we disagree with.

---

## Contents

| Directory | Description |
|---|---|
| `crypto/` | Font and 3D model decryption analysis (academic interest) |
| `分析工具/` | Static analysis notes: disassembly, memory layout, protocol observations |
| `协议样本/` | Network protocol capture samples |
| `基础设施/` | Infrastructure assessment notes |
| `黄金采集/` | Runtime data: memory offsets, waypoint coordinates, string tables, object database |

## Data Summary

- **UE Engine Offsets**: 4,279 memory offsets catalogued from runtime pointer analysis
- **Navigation Waypoints**: 43,988 3D coordinates extracted from map mesh data
- **String Tables**: 705 decrypted strings (FNV variant algorithm)
- **Object Database**: 1,099 items catalogued from game asset system
- **Discord Module**: 138 functions reverse engineered from rendering overlay

## Methodology

Standard binary analysis: memory dump → PE reconstruction → IDA/Ghidra decompilation → string decryption → offset mapping → protocol capture.

All findings verified through multiple independent evidence chains.

---

## A Note on Game Security

The game's anti-cheat implementation is truly *ambitious*. One might even call it *optimistically theoretical*.

The fact that this entire dataset was collected with standard user-mode tools over a casual afternoon speaks volumes about how seriously the developers take competitive integrity. Their approach to security appears to be: "if we can't see it, it doesn't exist." Admirable philosophy — flawed execution.

To the dev team: we believe in you. Sort of. The road to functional anti-cheat is long, but you've at least found the parking lot.

*No further action is recommended because clearly no action was ever going to be taken anyway.*
