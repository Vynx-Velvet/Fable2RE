# Lionhead's debug menu, Lua console and level loading survive in retail (2026-10-02)

## Context

Goal: custom debug menus, level loading, modding. The game's machine code is already
fully recompiled (regen #7: 60,707 functions, 0 REX_FATAL sites), so "porting" is not the
blocker. The blocker is knowing *where* to plug in. This note shows the retail XEX
ships the developer tooling that we can drive directly.

## What ships in retail

- The gameplay layer is **Lua 5.1 (LuaPlus)**: compiled big-endian `LuaQ` chunks in
  `data/scripts/**`, `gamescripts.bnk`, `guiscripts.bnk`.
- `data/scripts/Startup/DebugMenu.txt` (835 lines): Lionhead's full debug menu, written as
  `"<lua>", "<label>"` lines nested by tabs. Examples: `Debug.SetUseFreeCamera`,
  `Debug.SetHeroGodMode`, `Debug.SetHeroLevel([0:11:0:1:false], true)`,
  `Debug.CreateEntityByHero(...)`, `Debug.MakeGameGoFast`, `Debug.SetDrawGameFPS`.
- `data/scripts/Startup/DebugMenuLevelList.txt`: `Debug.LoadLevel('Albion', '<level>', '<start marker>')`
  for every region, including the DLC levels.
- `scenarios.list`: every level path plus its scenarios (e.g. `albion\brightwood` →
  `chapter3bigfarm`, `chapter3abandonedfarm`).
- Strings for the C++ Lua bindings: `LoadLevel`, `ReloadCurrentLevel`, `IsLevelLoading`,
  `TeleportToPosition`, `SetHeroGodMode`, `AddConsoleKeyShortcut`, `AddLuaDebugKeyFunc`,
  `StartupConsoleScript.lua`, `AddOptionalStartupConsoleScript`, `IsReleaseBuild`,
  `lhlua_debugger` / `LuaDebuggerService-1.0` (remote Lua debugger).
- Template files show the intended extension point: `MyDebugMenu_Template.txt`.

## Key addresses

| Address | What | Evidence |
|---|---|---|
| 0x822EA928 | GameThread entry: init `sub_822F27C0`, mode loop `sub_822F47F8`, shutdown `sub_822F4690` | thread name "GameThread" |
| 0x822F47F8 | Game-mode state machine: `mode->vtbl[3]` Update returns the next mode; byte 0x83496927 picks the first mode | |
| 0x82356180 | Main game mode ctor: vtable 0x820A69F0, stores `this` in 0x83496928, creates 200-byte component at +12 | |
| 0x82354BB8 | Mode Start (vtbl[1] → sub_82356310): registers debug quests; **creates the 188-byte debug menu object only if byte 0x833194D0 == 0** | |
| 0x82355460 | In-game main loop (runs until component+92 is set). Calls `sub_8229A9D8(component+136, 0)` every iteration from **return address 0x82355590**; calls the debug menu update `sub_82692230(component+140)` only if 0x833194D0 == 0 | |
| 0x82355BE0 | Component input handler: forwards to debug menu input `sub_82692048` if +132 == 0 and 0x833194D0 == 0 | |
| 0x82692048 | Debug menu input state machine (states 0..6) | |
| 0x826928F8 | Builds the level list menu from `DebugMenuLevelList.txt` / `Debug.LoadLevel('` | string refs |
| 0x826948D8 | Debug menu action that **sets 0x833194D0 = 1** (turns the menu off) | only writer |
| **0x833194D0** | byte "debug menu disabled": **1 in the shipped image** | static data |
| 0x83496920 | root object; main `lua_State* = *(*(*(*(*(0x83496920)+12)+120)+4)+0)` | sub_823ADB60 |
| 0x823ADB60 | reload a Lua console script (`HeroLocomotionStates.lua`) | string refs |
| 0x824154F0 | `RunLuaFile(L, String* path, String* errName) -> bool` | opens a stream, calls ↓ |
| **0x824155C8** | `RunLuaBuffer(L, const char* buf, int len, String* chunkName, String* errName) -> 1/0` | `lua_load` + `pcall` |
| 0x82A1EE10 | `lua_load(L, reader, data, chunkname)`; string reader 0x82A1FF68 | |
| 0x8219A8E8 | `luaD_pcall`-style protected call (f_call 0x82A1ED48) | |
| 0x8222CF18 | `String::Construct(String*, const char*, int len = -1)` (5,200 callers) | |
| 0x82214F08 | `String::Destroy(String*)` (5,600 callers) | |
| 0x82229208 / 0x822279A0 / 0x8219AB28 / 0x82A1EC08 | `lua_rawgeti(L, LUA_REGISTRYINDEX=-10000, ref)` / `lua_newuserdata` / `lua_pushcclosure` / `lua_setfield` | binding registration in sub_8233CFC8 |

A Lua `TValue` is 8 bytes (`L->top` at L+8; bindings pop with `top -= 8`).

## What was built

- `Fable2Recomp/src/lua_bridge.cpp`: hooks `sub_8229A9D8`. When `ctx.lr == 0x82355590`
  (the main loop's call site, GameThread, between frames) it runs queued Lua text through
  `sub_824155C8`, using the guest stack for the two `String` handles and the text. It also
  logs once the `lua_State` and the gate bytes. Cvar `dev_debug_menu` (default off) clears
  0x833194D0 in a `sub_822EA928` hook, which re-enables Lionhead's own in-engine menu.
- `Fable2Recomp/src/debug_menu.cpp`: F2 ImGui window. It parses `DebugMenu.txt` and
  `DebugMenuLevelList.txt` (toggles, sliders, submenus), runs the selected entries through
  the bridge, and has a free-form Lua prompt.

## Runtime corrections (2026-10-02 17:45, from the user's logs)

- 0x82355460 is the **front-end/loading** mode loop only. In game, the in-game mode
  (vtable 0x820A7E40, Update thunk 0x82378C78) loops in **sub_823784A0**, which calls
  sub_8229A9D8(this+92, 1) per iteration from return address **0x82378578**.
- The static lua_State chain from 0x83496920 is wrong (0x83496920 stays 0). Debug.* bindings are
  registered via lua_setfield on GameThread on L=0x4F640220 in that run (a second state,
  0x4F100220, is created earlier). The bridge now captures L when `SetHeroGodMode` is set.
- Scanning global_State for mainthread gave inconsistent results; dropped.
- Bridge guard now: thread == the thread that registered Debug.*, and L->ci == L->base_ci
  (lua_State +20 / +40, no Lua call in progress), at any sub_8229A9D8 call site.

## Open questions / next steps

1. Runtime check: the bridge must log `lua_State != 0` in game, and `Debug.SetDrawGameFPS(true)`
   must do something visible. If the `Debug` table is not registered in release, look for
   its registration (strings at 0x820a9xxx-0x820aaxxx are the `Debug.*` method names) and
   whether it is gated by 0x833194D0 / `IsReleaseBuild`.
2. Lua `print` output and error text: capture them, either by hooking the error path in
   `sub_824155C8` (error string at `top-8` → `+16`) or by redefining `print` from the bridge.
3. Decompile the `.bnk` script archives (zlib-compressed; LuaQ 5.1 big-endian), so the
   quest/AI scripts become editable and readable (luadec/unluac after an endian swap).
4. `dev_debug_menu = true`: check what the menu's input mapping is on the pad (state
   machine `sub_82692048`, event codes 28/102 from `sub_828413D0`) and whether the dev init
   paths in `sub_822F27C0` / `sub_822F33B8` behave.

## Second test round (2026-10-02 17:45-17:52)

- Commands work. The per-frame site that actually runs in game is **0x82276E4C**
  (sub_82276C30, caller sub_8233D6F8); the front-end (0x82355590) and in-game-mode
  (0x82378578) sites stop being hit once the world is running.
- Toggle convention in DebugMenu.txt: `[toggle:true]` = off by default, first use sends true;
  `[toggle:false]` and bare `[toggle]` = on by default (SetDrawGUI, lightmaps, shadows, dog
  targetable), first use sends false. Sending true first for `Debug.SetDrawGUI([toggle])`
  left the GUI (and pause menu) hidden.
- `Debug.CreateTheElevenStagesOfTrolls()` crashed 3 s later with
  `Call to invalid or unregistered function at guest address 0x82DDC4D8`: a 7-instruction
  vtable thunk with no .pdata entry that codegen never emitted. tools/find_gap_functions.py
  found 34 such functions between emitted functions (vtable thunks, tail-call stubs, small
  leaves) and 11 config entries whose size covered only the first instruction(s). All were added
  to / fixed in Fable2_config.toml for regen #8 (backup of regen #7 in Fable2Recomp/generated_regen7).
