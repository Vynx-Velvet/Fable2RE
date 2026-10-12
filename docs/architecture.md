# Architecture and source layout

Fable2RE currently combines three forms of game code with native subsystems and ReXGlue services. The target architecture replaces the remaining console-specific execution model with readable C++ and PC APIs.

## Code reconstruction stages

| Stage | Location | Meaning |
|---|---|---|
| Recompiled reference | `Fable2Recomp/generated/` | PPC instructions translated into C++ locally; retains registers and guest-memory semantics |
| Automatically lifted code | `Fable2Recomp/lifted/` | Transformation passes simplify generated functions; address-based names and raw offsets can remain |
| Readable replacements | `Fable2Recomp/src/game/` | Named functions, types, and systems reconstructed and reviewed by contributors |

These stages coexist. `F2_REWRITE` registers replacements with module-level fallback through `rewrites_disabled`. Lifted code has separate fallback controls. Passing a build or accepting a function in the lifter does not establish equivalent behavior. See [conversion](conversion-guide.md) and [lifting](lifted-code.md).

## Runtime boundaries

The native D3D12 renderer lives in `Fable2Recomp/native/`, with game-facing integration in `src/native_frontend.cpp` and synchronization in `src/gpu_sync.cpp`. Native rendering does not imply every Xbox graphics dependency is gone: packet parsing, guest memory, shader translation, and resource conversion remain part of the transition.

The Lua bridge and F2 interface live in `src/lua_bridge.cpp` and `src/debug_menu.cpp`. Native plugins use `sdk/include/fable2/` and `src/modding/`. ReXGlue still supplies code generation and runtime infrastructure. Xenia is also available as a separate research reference; the project does not launch it as the CPU engine for its statically compiled executable.

Online and creator features should depend on readable, versioned Fable2RE interfaces rather than embedding service-provider or file-format details in gameplay code. The intended boundaries are described in [online and expansion architecture](online-and-modding-architecture.md).

## Workspace map

| Path | Purpose |
|---|---|
| `Fable2Recomp/` | Game application, generated/lifted code (local), replacements, renderer, and mod SDK; a folder of this repository |
| `rexglue-sdk/` | Code generator and runtime: the public ReXGlue v0.8.0 submodule with `patches/rexglue-sdk.patch` applied |
| `tools/` | Build/run wrappers, setup pipeline, asset tools, lifting, conversion, and analysis |
| `docs/` | Maintained guides and project status |
| `research/findings/` | Dated investigations and validation records |
| `research/symbols/`, `research/catalog/` | Function names, layouts, bindings, and conversion metadata |
| `research/decomp/` | Local executable images and decompiler output |
| `iso/`, `extracted/` | User-supplied disc data and local extraction output |
| `mods/` | Author-created mods; names beginning with `_` are disabled |
| `xenia/` | Local research emulator files |

The workspace is one Git repository. The runtime (`Fable2Recomp/`) is a folder of it; until 2026-10-11 it was a separate repository, whose history stays with the project's maintainers. `rexglue-sdk/` is the public ReXGlue release the project builds on (v0.8.0), pinned as a submodule; every change the project makes to it lives in `patches/rexglue-sdk.patch`, which `tools/setup_all.ps1` applies. After changing SDK sources, run `python tools/sdk_patch.py export` and commit the patch; never commit the submodule at another revision (`tools/validate_commit.py` refuses it). The disc extractor (`tools/extract-xiso`) and the SDK's third-party libraries are submodules from their public repositories.

The current runtime CMake configuration requests **C++23**. The active codegen configuration is `Fable2Recomp/Fable2_config.toml`; older notes referring to `Fable-2_config.toml` describe an earlier setup.
