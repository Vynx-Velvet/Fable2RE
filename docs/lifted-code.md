# Automatically lifted C++

[Documentation index](README.md) · [Architecture](architecture.md) · [Current status](status.md)

Automatic lifting is an intermediate representation, not completion of whole-game readable C++ reconstruction. It retains guest-memory assumptions and often register names or raw offsets. Counts below describe a particular generation, not verified gameplay coverage.

`Fable2Recomp/generated` is the game recompiled instruction by instruction, aiming to preserve behavior; every
line is a register operation on a context structure (`ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);`).
The **lifter** (`tools/lift/`) turns that into ordinary C++ for every function it can
(`Fable2Recomp/lifted/lifted.N.K.cpp`), which the build uses instead. Its shape, as an invented illustration (not a
function of the game; the real output stays on your machine):

```cpp
// sub_82000000 = Example_IsReady (a name from the dictionary)  [64 bytes]
F2_LIFTED(sub_82000000, 0x82000000) {
	uint32_t r31 = r3;
	if (LOAD8(r31 + 8) != 0) {
		r4 = LOAD32(LOAD32(r31 + 4) + 16);
		...
	}
	r3 = LOAD8(r31 + 12);
	...
```

It is the starting point for hand-written code (docs/conversion-guide.md): names, structs and
comments are added on top of it, function by function, while the game keeps running.

Everything in `lifted/` is generated locally from your own copy of the game: do not
distribute it, regenerate it.

## Regenerating

On a fresh machine, `tools/setup_all.ps1` does all of it. Its steps `image`, `classes`, `decls` and `lift` produce
the lifted code, and the [build guide](building.md) describes each step and its cost. To re-run only this part:

    powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -From image -To lift

The same by hand. The image comes first, from the repository root:

    python tools/xex_decrypt.py Fable2Recomp/assets/game/default.xex research/decomp/default_image.bin

Then from `tools/lift`, in this order:

    python bundle.py check                      # is the shipped analysis valid for your default.xex?
    python classes.py --bundle                  # cache/classes.json, cache/structs.json, lifted/classes.h from the
                                                # shipped model (or: lift.py --facts, about 25 min, then classes.py --facts)
    python native_gen.py                        # lifted/native_decls.h, lifted/native_bridges.N.cpp
    python apply_names.py --init                # record the naming dictionary the lift will use
    python lift.py --all --skip overridden.txt  # every function, 9.5 to 27.6 min on the development machine
    python difftest/make_skip.py --manifest ../../research/lift/verified.json.gz --out cache/manifest_skip.txt
    python lift.py --funcs cache/manifest_skip.txt --skip cache/manifest_skip.txt

`apply_names.py --init` comes before the lift. A rename made in `research/names` while the lift runs then stays
pending, and the next `apply_names.py` applies it. Recorded after the lift, it would count as applied although the
lifted code does not have it.

What each command needs:

- `lift.py --facts` and `lift.py --all`: the generated code, the analysis and the decrypted image
  (`readable.py` reads the game strings the readable form refers to).
- `classes.py --bundle`: the shipped model (`research/lift/class_model.json.gz`), the image (class names from RTTI)
  and the naming dictionary. `classes.py --facts`: the facts, the image, `research/symbols/func_db.json` and the
  dictionary. Without an option, `classes.py` rebuilds from the source the current `cache/classes.json` came from
  (a rename). Each lifted chunk carries the structs it uses, from `cache/structs.json`.
- `native_gen.py`: only the analysis and the names. The promoted source modules (`Fable2Recomp/src/game/promoted`)
  include `classes.h` and `native_decls.h`, so both must exist before a build.

The output is split into chunk files, `lifted/lifted.<file>.<chunk>.cpp` (64 functions of generated
file `<file>` each, by position, so a function never moves), and everything after the first run is
incremental:

    tools/lift/update.ps1 -Funcs sub_82B4D300,sub_821DCC90 -Build   # or -Funcs list.txt

re-lifts only those functions (seconds), rewrites only the chunk files whose text changed,
differential-tests only functions whose lifted text changed since their last test
(`tools/lift/difftest/results/status.json`), drops any that fail back to the recompiled version,
and ninja recompiles only the changed chunks. The pieces can be run alone:
`lift.py --funcs ...`, `difftest/run.py [--funcs ...] [--all] [--failed]`, `difftest/make_skip.py`.
After a lifter-wide change, `tools/lift/verify_and_build.ps1` runs `setup_all.ps1 -From lift -To build -Force lift
-Tested tester`. That is the whole lift, a test of everything whose text changed, the drop of the failures and
the build. It does not refresh the class model (`lift.py --facts`, about 25 minutes, and `classes.py`) or the
native declarations (`native_gen.py`). A new class model changes the structs that every lifted chunk carries, so
it means a retest and recompile across the game. Refresh them on purpose, overnight, with
`setup_all.ps1 -From classes -To build -Tested tester`, and publish the new class model with the manifest
(`python tools/publish.py --refresh`, [publishing](publishing.md)). Renames in `research/names` reach the lifted code through `python tools/lift/apply_names.py`. It
re-lifts only the affected functions and updates the promoted modules. `setup_all.ps1` runs it before writing
anything with the new names.

### The shipped class model

`research/lift/class_model.json.gz` is the class model the development machine lifted and tested with, as
structure only: each vtable's functions, base classes, constructors, the class of each function's `this`, and per
field offset the access sizes and counts. It holds no names, no code and no text. A setup that uses it
(`classes.py --bundle`) builds the same `classes.json`, `structs.json` and `classes.h` as the development machine,
so its lift gives the text the verification manifest records, and it skips the 25-minute facts pass. Without it,
a fresh setup's model differed for 401 functions and 368 tested functions stayed recompiled
([record](../research/findings/2026-10-12-fresh-clone-end-to-end.md)).

    python classes.py --export    # write it from the facts; refused unless it is the structure in cache/classes.json
    python classes.py --verify    # is the shipped model the structure in cache/classes.json?
    python classes.py --check     # does it fit this machine's default.xex?

The model and the manifest are a pair: export both after a class-model refresh, lift and test
(`python tools/publish.py --refresh`). The analysis is deterministic: the same facts give the same model.

### Tested functions without running the tester

The differential tester's verdicts ship as `research/lift/verified.json.gz`. For each function, the file holds two
things and no code:

- the hash of the lifted text the function was tested on (`tools/lift/difftest/run.py` `block_hash`, which leaves
  out dictionary names and local variable names, so a rename does not invalidate it)
- the verdict class: OK, UNTESTED, MISMATCH, CRASH or BUILD FAILED

Like `summaries.json.gz`, the file is tied to the `default.xex` and the analysis version. Local rewrites accepted
in relaxed mode (`OK [relaxed]`) are not included.

`difftest/make_skip.py --manifest ... --out FILE` lists three groups:

- `overridden.txt`
- every lifted function whose text is not exactly a version that tested OK
- the manifest's known problem functions

The drop pass `lift.py --funcs FILE --skip FILE` returns them to their recompiled originals. `make_skip.py` exits
with code 2 when the manifest belongs to another executable or analysis version.

`setup_all.ps1` writes the list to `tools/lift/cache/manifest_skip.txt`. That leaves the tracked
`tools/lift/skip.txt`, the tester's own list, unmodified.

For maintainers: after tester runs, `python difftest/make_skip.py --export-manifest` regenerates the manifest.
The output is deterministic (fixed gzip header, one function per line), so an unchanged export gives an
identical file. Without arguments, `make_skip.py` still writes `tools/lift/skip.txt` from
`difftest/results/status.json`.

### The whole-game analysis

The lifter needs a whole-game register analysis. It ships with the project
(`research/lift/summaries.json.gz`: per function address, bit masks of the registers it reads,
changes and returns - facts, no code) and is used when it was computed from the same
executable (see `tools/xex_info.py`) with the same analysis rules (`ANALYSIS_VERSION` in
`tools/lift/summarize.py`). Otherwise, or after changing the analysis, compute it yourself from
`tools/lift`, in this order. All results are cached in `tools/lift/cache`, and the image step must have run first:

    python vtables.py           # cache/vtables.pkl: vtable slots (reads the decrypted image, func_db.json)
    python address_taken.py     # cache/address_taken.pkl: functions callable through pointers (image too)
    python summarize.py         # cache/summaries.pkl, about 30 min (generated code + both files above)
    python signatures.py        # cache/signatures.pkl: native signatures (reads summaries.pkl)
    python bundle.py export     # maintainers: refresh the shipped file (bump ANALYSIS_VERSION first
                                # if the rules changed)

`lift.py`, `native_gen.py` and the tester use `cache/summaries.pkl` and `cache/signatures.pkl` whenever they
exist. The verification manifest belongs to the shipped analysis: with your own, run the tester
(`setup_all.ps1 -Tested tester -Force lift`, after a first build).

### The differential tester

`tools/lift/difftest/run.py` is also used by `tools/rewrite/check.py` and `promote.py`.

It finds clang++ in this order:

1. `LLVM_ROOT`, `LLVM_DIR`, `LLVM_PATH` or `LLVM_INSTALL_DIR`: the LLVM install folder, its bin folder, or
   `lib/cmake/llvm`
2. the `clang++` on `PATH`
3. `C:\Program Files\LLVM\bin\clang++.exe`

It needs:

- the codegen output
- the lifted output, `lifted/native_decls.h`, the bridges and `lifted/classes.h`
- the configured and built release tree (`tools/build.ps1 -Preset win-amd64-release -Target Fable2`): its
  `rexglue-sdk/include`, `rexruntime.dll` and the SDK import libraries in `rexglue-sdk/out/win-amd64`

At startup it names anything missing and the step that makes it. Whole-game summaries come from
`cache/summaries.pkl` when this machine computed them, otherwise from the shipped bundle.

`overridden.txt` lists functions replaced by hand-written code (F2_REWRITE / REX_HOOK); they are
not lifted. Regenerate it after adding rewrites (llvm-nm of the src objects, see the file's history).
Functions promoted into reviewed source modules (`Fable2Recomp/src/game/promoted`, [promoted code](promoted-code.md))
are left out of the lifted files automatically.

## How transformations aim to preserve behavior

The lifter never re-implements PowerPC semantics: it starts from the recompiler's own C++
statements (parsed by `cparse.py`, which reproduces all 5.5 million statements of the game
byte-for-byte) and is designed to apply transformations that preserve observable values. This design still requires validation against the original behavior:

1. **Registers become local variables.** The context is only read and written at the function
   boundary and around calls. Which registers a call needs, may change and returns is computed
   for the whole game (`summarize.py`) - the Xbox 360 compiler's link-time code generation keeps
   values in "volatile" registers across calls to functions it knows leave them alone, so the
   standard calling convention is not enough. Calls through pointers use the union of everything
   any address-taken function (vtable entry, callback) needs (`address_taken.py`). Callee-saved
   registers are trusted to be preserved by every callee, as the compiler guarantees.
2. **Prologues/epilogues go** (`frame.py`): saving and restoring callee-saved registers and the
   link register is unnecessary once they are locals - only removed where the stack slot is used
   by nothing else.
3. **Types** (`typer.py`): a register whose upper 32 bits nobody reads becomes `uint32_t`
   (game code is 32-bit); a floating-point register used only as a double becomes `double`.
   "Nobody" includes callees and callers (whole-game demand analysis).
4. **Compares fold into conditions, single-use temporaries inline, dead stores go**
   (`passes.py`) - never across stores or calls for expressions that read memory, never across
   FPU-mode switches for floating-point expressions.
5. **Idioms get short names** (`sugar.py`, macros in `lifted/lifted.h`): `LOAD32(a)`,
   `STORE_F32(a, v)`, `VLOAD(ea)`, shifts instead of the recompiler's rotate-and-mask, folded
   constants.
6. **Gotos become if/else/while/do-while** (`structure.py`) where the layout allows; the rest stay
   gotos (still valid C++).

## Switching it off (finding problems)

In `Fable2.toml` (or the console):

    lifted_code = false                          # everything back to the recompiled originals
    lifted_disable_files = "12,52"               # only functions from generated/Fable2_recomp.12/.52.cpp
    # only functions in these address ranges (the first range is the default: keep it)
    lifted_disable_ranges = "82C40000-82CF8E10,82790000-827A0000"

`lifted_disable_ranges` defaults to `82C40000-82CF8E10` (the XAudio2 library, which crashes on level load when
lifted). A value you set replaces the default, so include that range ([settings](settings.md)). Keep the value on
a line of its own, with no comment after it.

If something behaves differently with lifted code, halve the enabled set until the culprit
function is found, then report it (or fix the lifter pass responsible and regenerate).

## Status

- Lifted: every function the parser and analyses accept (60,320 of 60,362; the rest - setjmp
  users and a few unusual constructs - stay recompiled).
- Readability is decompiler-level: register names (`r31`), raw offsets (`LOAD8(r31 + 133)`).
  Hand conversion (src/game/) turns that into named structs and functions.
