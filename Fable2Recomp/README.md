# Fable2RE runtime

This tree contains the game application for **Fable2RE / Fable2Reimagined**, an open-source effort to build a fully native PC port from the user's own Xbox 360 copy, with readable whole-game C++, comprehensive mods, and restored Lionhead debug functionality.

**Those are goals, not a claim of completion.** The current Windows development build combines generated and lifted code, readable replacements, native rendering, and remaining ReXGlue services.

- [Project README](../README.md)
- [Current status](../docs/status.md)
- [Build instructions](../docs/building.md)
- [Architecture](../docs/architecture.md)
- [Modding](../docs/making-mods.md) and [debug tools](../docs/debug-menu.md)
- [Contributing](../CONTRIBUTING.md)

This directory is a folder of the Fable2RE repository; the links lead to its documentation.

## Source map

| Path | Purpose |
|---|---|
| `src/game/` | Readable game-system replacements |
| `native/` | Native renderer |
| `src/native_frontend.cpp`, `src/gpu_sync.cpp` | Renderer integration and synchronization |
| `src/debug_menu.cpp`, `src/lua_bridge.cpp` | F2 interface and Lua bridge |
| `src/modding/`, `sdk/` | Native mod loader and SDK |
| `generated/`, `lifted/` | Locally produced game-derived sources |
| `Fable2_config.toml` | Active codegen input |

The [legacy porting log](PORTING_STATUS.md) preserves early findings and is not the current feature matrix.

## Provenance

This tree originated from [Fable2Recomp/Fable2Recomp](https://github.com/Fable2Recomp/Fable2Recomp) and uses [ReXGlue](https://github.com/rexglue/rexglue-sdk). Its folder name reflects that upstream foundation. Preserve the existing [MIT license and attribution](LICENSE), plus third-party notices.

Fable2RE and [Himdo/Fable-2-Recomp](https://github.com/himdo/Fable-2-Recomp) are separate projects using ReXGlue, with distinct development directions. Shared tooling does not make this tree a fork of Himdo's project. Generated game code, inherited integration code, and Fable2RE's subsequent development have different provenance; see [shared foundations and source ancestry](../docs/project-direction.md).
