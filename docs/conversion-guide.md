# Converting Fable II to hand-written C++

[Documentation index](README.md) · [Contributing](../CONTRIBUTING.md) · [Current status](status.md)

The working baseline translates Xbox 360 code into C++ under `Fable2Recomp/generated`.
It retains a guest-machine model; compilation alone does not establish correct or complete
coverage. Conversion replaces functions incrementally with readable C++, using the baseline
for comparison and module switches for fallback. Keeping the game working at each step is the
validation goal, not an automatic property of a rewrite.

Everything game-derived (recompiled code, Ghidra output, extracted scripts) is generated locally
from your own copy of the game and is never shared. What the project shares is the hand-written
code, the tools and the knowledge (names, structs, notes).

## 1. Set up the references (once, ~1 hour)

    python tools/build_func_db.py                     # function database of the recompiled code
    python tools/ghidra/make_inputs.py                # inputs for Ghidra
    powershell tools/ghidra/run_ghidra.ps1 -Import
    powershell tools/ghidra/run_ghidra.ps1 -Export    # research/decomp/c (raw Ghidra output)
    python tools/find_lua_bindings.py research/decomp/default_image.bin
    python tools/catalog/find_lua_reg_arrays.py
    python tools/catalog/lua_tables.py
    python tools/catalog/build_catalog.py             # research/catalog + research/decomp/named
    python tools/catalog/find_component_bindings.py   # (then build_catalog.py again)

- `research/catalog/functions.tsv`: every function with its best name, library, Lua binding,
  callers/callees, decompilation location and conversion status. `summary.md` has totals. The strings each
  function references are text from the game, so they are not in it: `research/decomp/function_strings.tsv`,
  local, written by the setup (`tools/catalog/function_strings.py`). So are the names of the game's global string
  objects, which are their text: `research/decomp/global_names.tsv` (`tools/naming/global_strings.py`).
- `research/decomp/named/decomp_XXXX.c`: Ghidra's decompilation with names, string literals and
  globals filled in - the readable reference you work from.
- `research/symbols/`: Lua bindings, enums, component types, tuning values, hand-verified names.

## 2. Pick something and understand it

Good starting points are Lua bindings (`Lua_<Table>_<Name>` in the catalog): their purpose is known
from the scripts that call them (`extracted/gamescripts/**/*.src.lua`).

Read the named decompilation, then **check it against the recompiled instructions** - the
decompiler is a reading aid, not ground truth. The `// insn` comments in
`Fable2Recomp/generated/Fable2_recomp.*.cpp` (found via `research/symbols/func_db.json`: file and
line per function) are the original PowerPC. Example: Ghidra showed `Health.SetAsInvulnerable` as a
large function; the instructions are 7 (store a flag, call one helper).

Calling convention: integer/pointer arguments in r3..r10, floating-point in f1..f13, result in r3
or f1. Pointers are 32-bit guest addresses; values in memory are big-endian.

## 3. Write the C++

Start a module (or add to one) with the scaffolder, which writes the catalog facts, a reminder not to copy reference code, and a stub:

    python tools/convert/new_module.py combat health 8268BD90

Then write it properly - see `Fable2Recomp/src/game/combat/health.cpp` for a complete example:

```cpp
#include "game/combat/health.h"      // structs over game memory
#include "generated/Fable2_init.h"   // sub_XXXXXXXX declarations (for calls into game code)
#include "game/rewrite.h"

// r3 = this, f1 = amount, r5 = attacker (r4 unused): plain C++ parameters, filled from the
// registers in order (integers r3.., floats f1..).
void Modify(uint32_t self, uint32_t, uint32_t attacker, float amount) { ... }

F2_REWRITE("combat.health", sub_8268BD90, Modify)
```

- **Game memory** - describe objects as structs of `rex::be<T>` (big-endian values) and
  `f2::gptr<T>` (32-bit guest pointers); check offsets with `F2_OFFSET`. Get one with
  `f2::At<T>(address)`. Shared structs live in `src/game/core/` (e.g. `Entity` and its
  `GetComponent`).
- **Virtual calls and out-parameters** - `f2::CallAt<Ret>(guest_address, ...)` calls through a
  function pointer read from game memory (vtables); `f2::GuestStackBuffer buf(16)` reserves game
  stack space for results the callee writes (`buf.address()`, `buf.As<T>()`). See
  `Combat.GetCanFight` in `src/game/combat/combat.cpp`.
- **Calling game code that is not rewritten yet** - `f2::Call<Ret>(sub_X, args...)` (`game/rewrite.h`). Do not use `rex::ppc::GuestToHostFunction` from rewrites: it builds its stack frame from the thread's outermost context and corrupts the stack when rewrites and game code call each other in a chain.
- **Registering** - `F2_REWRITE("<module>", sub_X, Function)`. The module name lets anyone switch it
  off: `rewrites_disabled = "combat.health"` in Fable2.toml falls back to the original code.
- **Full register access** when the plain form does not fit: `REX_HOOK_RAW(sub_X) { ... }`, with the
  original available as `__imp__sub_X(ctx, base)`.
- New `.cpp` files under `src/game/` are built automatically.

## 4. Check it

- Build (`tools/build.ps1 -Preset win-amd64-release -Target Fable2`) and play the code path.
- For functions whose effects stay inside known memory, compare against the original in game with
  `f2::VerifyCall` (`sdk/include/fable2/verify.h`): it runs both and logs differences.
- If something misbehaves, disable the module with `rewrites_disabled` and compare.

## 5. Record it

    python tools/convert/mark.py rewritten Fable2Recomp/src/game/combat/health.cpp 8268BD90 ...
    python tools/catalog/build_catalog.py

Statuses: `draft` (stub calling the original), `rewritten` (no call to the original left),
`verified` (checked in game). Add names you discover to `research/catalog/names_manual.tsv`
(`address<TAB>name`) and component types to `research/symbols/components.tsv`; the catalog and the
named decompilation pick them up.

## What is where

| Area | Status | Where |
|---|---|---|
| Game baseline | generated C++ reference; coverage depends on codegen | `Fable2Recomp/generated` |
| Tuning values (300 setters: combat, magic, orbs, movement, physics, debug switches) | rewritten | `src/game/tuning` |
| Health component (Modify, getters, invulnerable / can't-die) | rewritten | `src/game/combat/health.cpp` |
| Combat component (44 of 60 methods: fields, enrage, regroup radii, hit history, waypoint, can-fight) | rewritten | `src/game/combat/combat.cpp` |
| Entity / component lookup, entity handles (weak refs) | readable core / rewritten | `src/game/core/entity.h`, `src/game/core/handle.cpp` |
| Debug displays compiled out of retail (FPS, build version, safe area) | re-implemented | `src/game/debug` |
| Renderer (GPU side) | native D3D12 | `native/`, `src/native_frontend.cpp` |
| Middleware (Havok, Kynapse, GameFace, Lua, CRT, XAudio2, Bink) | recompiled | catalog `library` column |

Middleware is third-party code: the long-term plan is to replace it with PC equivalents (Lua 5.1,
zlib, the native renderer/audio already started) rather than hand-convert it.
