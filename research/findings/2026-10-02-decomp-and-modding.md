# Decompilation and modding foundation (2026-10-02)

Goal (user): people turn their own Fable II (360) copy into a fully customizable PC port - UI,
menus, text, combat, debug features and renderer as readable, modifiable C++ and data.

## Distribution model
Everything game-derived is generated locally from the user's disc: recompiled code
(`Fable2Recomp/generated`), Ghidra exports (`research/decomp`), extracted/decompiled scripts
(`extracted/`). The project ships only tools, build scripts, hand-written replacement code and mods
made of the modder's own files.

## What exists now
| Piece | Where | Status |
|---|---|---|
| Ghidra project + full decompile export | `tools/ghidra/`, `research/decomp/` | 60,734 functions seeded, 24,200 strings; export: ~60.9k functions, 5 failed |
| `.bnk` archives (list/extract/pack) | `tools/bnk.py` | format decoded (multi-chunk files, 32 KB blocks); repack verified byte-identical for guiscripts (270) and gamescripts (554) |
| Lua scripts -> source | `tools/bnk.py extract --decompile` (unluac, `tools/thirdparty/unluac.jar`) | 587/587 chunks decompiled; gamescripts carry debug info (real local names), most GUI scripts do not |
| Mods | `tools/mods.py`, `mods/README.md` | apply/restore verified on a copy; example mod `mods/_Example_ModLoadTest` (disabled) - needs an in-game test |
| Lua binding -> C++ map | `tools/find_lua_bindings.py`, `research/symbols/lua_bindings.tsv` | 1,037 bindings |

## Formats learned
- `.bnk`: header {u32 block 0x8000, u32, u8, u32 dir comp size, u32 dir size, zlib dir}; dir entries
  {u32 name len, name, u32 offset, u32 size, u32 comp size, u32 chunk count N, N x u32 chunk size};
  data at the first block boundary; chunk k of a file at file start + k*0x8000, every chunk but the
  last filling the block exactly (the game reads fixed 32 KB blocks); each chunk a sync-flushed zlib
  stream.
- Lua: 5.1 bytecode (`LuaQ`, little-endian header, 4-byte float numbers). The game's loader compiles
  source too (the F2 console relies on it), so mods ship plain `.lua` text.
- GUI: Anark GameFace middleware. Each screen = `.bgf` + `.bsg` + `.fac` (binary, not yet decoded) +
  Lua logic (`scripts/gameface/**`, `art/gui/gameface/*.lua`). The front end controller defines a
  `Debug` slide (FrontEnd.SLIDE.Debug = 7) that retail never shows.
- Text: `language/<lang>/text/book.babel` - table of ~56,000 12-byte entries (id, ?, offset/size)
  then compressed blocks (366 zlib streams). Not yet decoded.

## Why debug options fail
- "nil value": the binding was removed from retail (`Debug.EngineConfig`, `GameVersion.SetDLC*`).
- "ok" but no effect: the binding still exists but the code that would act on it was compiled out:
  `SetDrawGameFPS` (0x823A5918) stores byte 0x8349695F and nothing reads it; `SetDrawBuildVersion`
  stores 0x83496969 likewise; 15 bindings (e.g. `ProfileEngine`) point at the empty function
  0x829CE870 (`blr`). These must be re-implemented natively.

## Subsystem anchors (from lua_bindings.tsv)
| Subsystem | Registrar | Notes |
|---|---|---|
| Debug | sub_823ADF80 (349 bindings) | god modes, draw toggles, teleport, spawn |
| GUI | sub_82908E20 (102) | message boxes, headline text, intermission/info screens |
| Combat | sub_8242A5F0 (spells, 39), sub_82795108 (projectiles / close attack), sub_82487B00 + sub_8268CA18 (hittable / damageable), sub_82986420 (targeting), sub_8265AE40 (bullets), sub_82879778 (combat comments) | |
| Camera | sub_82425680 | free camera, tracking |
| Startup / gameflow | sub_823577C0 (42) | initial world/level/save names |
| Renderer | D3D map (research/findings/2026-09-30-d3d-runtime-map.md), sub_825DA0A0 | native renderer already replaces the GPU side |
| AI pathfinding | Kynapse middleware class registrations 0x8325xxxx-0x8329xxxx | |

## Conversion approach (next)
1. Guest-interop layer for hand-written C++: big-endian value types (`be<T>`), typed guest pointers,
   calling guest functions from native code (the Lua bridge already does this by hand).
2. Name everything we know inside Ghidra (Lua binding names, D3D map) and re-export, so call sites
   read as names.
3. Per subsystem: decompile -> define structs -> readable C++ module under `Fable2Recomp/src/game/<subsystem>/`
   replacing the recompiled functions through `REX_HOOK_RAW` (one function at a time, testable).
   Order: debug (re-implement compiled-out features), GUI/menus, combat, renderer.
4. Data: decode `book.babel` (text), the GameFace `.bgf/.bsg/.fac` layouts.

## Progress 2026-10-02 evening (all built, release 21:45; nothing below tested in game yet)

Foundation for converting the whole game:
- Modding SDK `Fable2Recomp/sdk/include/fable2/` (sdk.h: f2::gptr/At/HostPtr over game memory;
  mod_api.h: C plugin ABI; verify.h: original-vs-rewrite checker), plugin loader
  `src/modding/mod_loader.cpp` (MinHook runtime replacement of any PPCFuncMappings entry, chained;
  loads <exe>/mods/*/native/*.dll before the game starts), example plugin `sdk/examples/hello_mod`.
- `src/game/rewrite.h`: F2_REWRITE(module, sub_X, Fn) with run-time switch (cvar rewrites_disabled)
  and f2::Call<Ret>(sub_X, args...) - calls into game code from rewrites with the frame below the
  *current* context (rex::ppc::GuestToHostFunction uses the outermost context: unsafe for chains).
- Catalog: tools/catalog/build_catalog.py -> research/catalog/functions.tsv (+summary.md) and
  research/decomp/named (Ghidra output with names, string literals, g_ globals). Library ranges:
  CRT 0x82CA-0x82CC, XAudio2 0x82CD-0x82CE, Havok 0x82D4-0x82E6, Kynapse 0x82E7-0x82EC.
- Bindings: 1,037 direct + 534 luaL_Reg arrays (incl. an ActionScript runtime and two Lua stdlibs) +
  448 component methods (Player 105, Stats 68, Combat 60, Health 15, ...): tools/find_lua_bindings.py,
  tools/catalog/find_lua_reg_arrays.py, tools/catalog/find_component_bindings.py; enums:
  tools/catalog/find_enums.py (C++-side) + plain-Lua enum scripts in gamescripts/scripts/miscellaneous.
- Conversion tools: tools/convert/new_module.py (scaffold), tools/convert/mark.py (status),
  tools/convert/gen_tuning.py; docs/conversion-guide.md.

Rewritten so far (311 functions):
- 300 tuning setters (`src/game/tuning`, generated from exact `lis/st/blr` instruction patterns) +
  mods/*/tuning.toml overrides (pinned) + F2 menu Tuning tab.
- Health component (`src/game/combat/health.cpp`): Modify (full damage/heal logic), getters,
  SetAsInvulnerable, SetCantDie. Entity/component lookup in `src/game/core/entity.h`
  (component bits +0x24..+0x40, sorted slots +0x48/+0x4C, index table +0x8C).
- Debug displays compiled out of retail re-implemented (`src/game/debug/debug_overlay.cpp`).
Data tools: tools/babel.py (game text, round trip identical), text mods, tuning mods, native mods
in tools/mods.py; docs/making-mods.md.
Lesson: Ghidra mis-decompiles tail calls (SetAsInvulnerable showed 6 extra calls) - always confirm
against the recompiled `// insn` comments.

## Progress 2026-10-02 late (release 22:44; not yet tested in game)
- Test of the 21:45 build (22:07-22:18): no crash; ~30 debug commands ok; LoadLevel WinterShrine ok.
  Reaver Beach median 58 fps (was 42) but p10 22 fps: video lockstep was on 100% of the time in 81
  of the 5 s samples - it fired on any CPU texture rewrite (streaming). Now it triggers only for a
  texture re-uploaded again within 3 frames, twice (Stats::textures_animated, i.e. video planes).
- The rewrite switch was a mutex + clock read + set lookup per call; now one relaxed atomic load
  (RewriteModule, updated by the rewrites_disabled cvar change callback / RefreshRewrites at start).
- New SDK helpers: f2::CallAt (call via guest function pointer), f2::GuestStackBuffer.
- core.handle: EntityHandle {vtable, target -> {entity, refcount}}; Get (sub_825575C8) and Release
  (sub_821940C8) rewritten.
- combat.combat / combat.hits: CombatComponent layout (src/game/combat/combat.h) and 44 methods.
  Hit history = ring buffer at +0x114 of HitRecord* {handle, frame +8, damage +0x14, type +0x18},
  newest first; seconds -> frames via the double at 0x83319510 (ticks per second). GetCanFight's
  tether check is horizontal (x, y mask at 0x82099150). Component 0x5B gets SetIsAttacking.
- Pre-existing, unrelated: "Shader translation fatal error: Unknown ALU vector/scalar operation"
  (833 lines in fable2.log since 2026-10-02 00:32) - some shaders fail to translate; to look at.
