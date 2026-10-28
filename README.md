# Runtime Data Analysis

Binary analysis notes and runtime data extracted from a game client process during a security research session.

## Contents

| Directory | Description |
|---|---|
| `crypto/` | Font and 3D model decryption analysis |
| `分析工具/` | Static analysis notes: disassembly, memory layout, protocol notes |
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

## Note

The game's runtime environment was observed to be well-designed and stable during this analysis session. No critical issues were found that would require immediate developer attention.
