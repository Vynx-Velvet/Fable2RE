# Fable2RE Porting Status

> **Historical log, not current status.** July findings were superseded by the September configuration investigation and subsequent work. Read [current status](../docs/status.md) and the [research index](../research/README.md). Counts and blockers below describe earlier builds only.

> Last updated: 2026-07-09

## Summary

| Category | Count | Native | Emulated | Stubbed |
|---|---|---|---|---|
| **Application Host** | 1 | ✅ Native | — | — |
| **Heap Allocator** | 1 | ✅ Native | — | — |
| **RTL Heap Hooks** | 3 | ✅ Native | — | — |
| **Lock Primitives** | 2 | ⚠️ NOP Stubs | — | — |
| **Render Bootstrap** | 1 | ⚠️ Partial | — | — |
| **IO Completion** | 1 | ⚠️ Hack | — | — |
| **File Sector Info** | 1 | ✅ Native | — | — |
| **Generated Game Code** | ~61,360 | ~830 rex_* | ~60,530 sub_* | — |
| **Branch Targets (code+data)** | 798 | — | — | 🔴 Codegen misses |
| **Split-use targets** | 426 | — | — | 🔴 Mid-function entry points |
| **Xam UI APIs** | 3 | ✅ Native | — | — |
| **Xam User APIs** | 2 | ✅ Native | — | — |
| **Xam Voice APIs** | 1 | ✅ Native | — | — |
| **NetDll APIs** | 6 | ✅ Native | — | — |
| **XNet APIs** | 1 | ✅ Native | — | — |
| **Io APIs** | 7 | ✅ Native | — | — |
| **Ob APIs** | 2 | ✅ Native | — | — |
| **Rtl APIs** | 1 | ✅ Native | — | — |
| **Critical Missing** | 1 | ✅ Fixed | — | — |

## Legend

- ✅ Native — Fully implemented in portable C++
- ⚠️ Partial/Hack — Works but needs improvement
- 🔴 Stubbed — Returns 0/success; game logic not executed
- — Not applicable

## SDK Infrastructure (Available, Needs Wiring)

The ReXGlue SDK provides these subsystems already. They need hooks from game code:

| Subsystem | SDK Module | Wiring Status |
|---|---|---|
| Thread create/suspend/resume | `KernelState` / `XThread` | 🔴 Not wired |
| Events, semaphores, mutexes | `XObject` dispatch | 🔴 Not wired |
| TLS management | `KernelState` TLS slots | ⚠️ Partially wired |
| Timer objects | `KernelState` timers | 🔴 Not wired |
| D3D12/Vulkan backend | `GraphicsSystem` | ✅ Wired (PM4 submission) |
| Audio (SDL + XMA) | `SDLAudioSystem` + `XMA*` | 🔴 Not wired |
| Input (SDL + XInput) | `InputSystem` | 🔴 Not wired |
| File I/O | `FileSystem` devices | 🔴 Not wired |
| Networking | `rex/net/` | 🔴 Not wired |

## Stub Categories

### Code Segment Stubs (1,345 addresses, 0x82xxxxxx)
Functions in the game's code that the codegen couldn't translate. Many are:
- Import thunks (small trampolines, 8-20 bytes)
- Functions in sections not mapped in config
- Tail-called functions not detected by function scanner
- Functions that need explicit entries in `Fable2_config.toml`

### Data Segment Stubs (358 addresses, 0x83xxxxxx)
Addresses in the data segment, likely:
- Function pointers in vtables or dispatch tables
- Callback registrations not followed during codegen
- Init/exit handler lists (many `rex__initp_eh_hooks_*` at 0x832Bxxxx)

### Xbox 360 API Stubs (22, manually declared)
These are `REX_STUB(__imp__*)` declarations for Xbox 360 system APIs.

## Progress Tracking

- **2026-07-09 (Phase 0)**: Fixed critical blocker — `rex_lhGameThreadInit` (0x822EA228)
  - Game now boots past initialization crash
  - Reaches game loop, GPU initializes, swap chain active
  - Result: Game runs indefinitely without crashing (was immediate crash)

- **2026-07-09 (Phase 1)**: Categorized 1,703 stubs by address range
  - 1,345 code segment (0x82xxxxxx) — game functions not translated by codegen
  - 358 data segment (0x83xxxxxx) — function pointers / vtable entries
  - Created PORTING_STATUS.md with comprehensive tracking

- **2026-07-09 (Phase 3)**: Native XAM/API implementations in `src/hooks_xam.cpp`
  - Replaced 22 `REX_STUB` declarations with proper `REX_HOOK_RAW` implementations
  - XAM UI: Returns success (no-op)
  - Networking: Returns offline status with Fable 2 title ID
  - I/O: Returns proper Xbox error codes
  - RTL: Proper Unicode uppercase implementation
  - Code organized in dedicated `hooks_xam.cpp` for maintainability
  - (Later merged into `src/hooks.cpp`; the unused `hooks_xam.cpp` and `hooks_render.cpp` were removed on
    2026-10-12.)

- **2026-07-09 (Phase 7+)**: Stub analysis and cleanup
  - Identified 1,384 false stubs: intra-function `goto` labels already handled in generated code
  - Found 426 "split-use" addresses: intra-function labels ALSO called as functions from other functions
  - These 426 need FunctionDispatcher entries — codegen can't create mid-function entry points
  - Regenerated `_stubs_gen.inc` with correct 798 addresses (split-use + truly missing)
  - Down from 1,703 → 798 (53% reduction, all genuine needs)

- **2026-07-09 (Phase 4)**: Render pipeline fixes
  - Fixed VdSwap width/height: game D3D init passes garbage (1×1), now defaults to 1280×720
  - Corrected big-endian display issue in VdSwap debug output
  - VdSwap now writes valid PM4_XE_SWAP packets with correct dimensions
  - GPU command processor receives and processes frame commands
  - Window created and visible (1280×720)

### Current State (2026-07-09)

**Game boots and runs stably**, window opens at 1280×720. The game loop runs, GPU initializes, and the swap chain activates. Two VdSwap calls complete during init with correct dimensions.

**What's blocking visible output**: The Lua engine initialization (`rex_lhGameThreadInit`, 0x822EA228) is stubbed. Without Lua scripts, the game has no logic driving frame rendering — no menus, no UI, no game world. The game loop runs but doesn't produce render commands during gameplay.

**Next steps to get the game working**:
1. Implement `rex_lhGameThreadInit` — read PPC code from XEX at 0x822EA228, translate to C++
2. Implement Lua engine functions (lhCreateLuaState, lhEngineInit, etc.)
3. Fix D3D front buffer allocation (currently uses dummy 0xD0000000)
4. Wire audio/input subsystems

## Known Runtime Issues

1. `[DISPATCH] GetFunction(0x822EA228) = NOT FOUND!` — still appears during XEX loading (null in dispatch table), but caught by NULLDISP at call time
2. `[VEH-AV]` — access violations being caught by VEH handler (memory page faulting, not crashes)
3. GPU worker waits for first command — eventually receives it
4. Threads created with `start=0x00000000` — null entry points (threading stubs)
5. No rendering output visible — PM4 commands submitted but not fully processed
6. Lock/unlock are NOPs — no real synchronization

---

## 2026-09-28 update: root cause of "no rendering" found

Everything above the line describes work done against generated code that was
structurally broken by the codegen config. See
`../research/findings/2026-09-28-foreign-config-root-cause.md` for the full analysis.

- `Fable2_config.toml`'s 946 `[functions]` entries (789 named) and the setjmp/longjmp
  addresses come from a different build of the game; 906 of them are not function
  starts in this XEX. They split real functions and caused the "unresolved branch",
  "split-use" and "missing target" problems, as well as the CRT `_lock` recursion.
- The July boot hooks stubbed `main()` itself (sub_822EA8C0), so the game thread that
  drives rendering was never created.
- New baseline: no game-function overrides (`src/heap.cpp`), a dispatcher fallback for
  `b`-thunks in the SDK, a cleaned config (`Fable2_config_clean.toml`) and a full
  regeneration into `generated_new/` for swap-in.
- Build/run only through `tools/build.ps1`, `tools/run_game.ps1`, `tools/run_in_job.ps1`
  (job-object wrapped; no more zombie clang.exe).
