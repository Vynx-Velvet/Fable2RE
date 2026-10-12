# Lionhead debug menu and developer tools

**Full restoration is a project goal. Current tools expose and restore parts of the original functionality; not every command is implemented or verified.**

## Two interfaces

| Interface | Implementation | Current use |
|---|---|---|
| Fable2RE developer window | `Fable2Recomp/src/debug_menu.cpp` | F2 opens an ImGui window that reads the original menu definitions, queues Lua commands, and provides a Lua prompt and tuning controls |
| Original Lionhead in-engine menu | Original game code, enabled through `src/lua_bridge.cpp` | `dev_debug_menu = true` clears the retail disable gate; original input and full behavior need validation |

The original definitions come from your extracted `data/scripts/Startup/DebugMenu.txt` and `DebugMenuLevelList.txt`. Fable2RE reads these locally; the public project should not bundle the extracted files.

## Trying the tools

Use a development build with your game data staged as described in the [build guide](building.md). Press **F2** for the project window. It runs commands through the game's Lua environment; world-dependent commands require the appropriate game state.

To experiment with Lionhead's own menu, set this flat key in `Fable2.toml` beside the executable and restart:

```toml
dev_debug_menu = true
```

That flag enables an original code path; it does not restore missing functions or establish a working controller mapping. Use a backed-up test save when testing spawning, teleportation, or level changes.

## Restoration status

October 2 research records roughly 30 working debug commands and successful WinterShrine level loading. It also identifies absent Lua bindings, empty retail functions, and flags with no remaining reader. For example, invoking an FPS-display setter can succeed while displaying nothing in the original retail code. Native replacement displays exist under `src/game/debug/`; that is separate from validating every menu command.

For each restoration, record the menu label and Lua command, target executable, original implementation or missing binding, replacement source, test scenario, and visible outcome. Keep untested entries and intentional extensions identifiable. The goal is functioning tools, not only the appearance of the original menu.

See the [menu investigation](../research/findings/2026-10-02-lua-debug-menu.md) and [follow-up findings](../research/findings/2026-10-02-decomp-and-modding.md).
