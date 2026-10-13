# Plan: building the port on the user's PC (no game code on GitHub)

[Documentation index](README.md) · [Build guide](building.md) · [Roadmap](roadmap.md)

**Status, 2026-10-10:** `tools/setup_all.ps1` implements the whole pipeline. It goes from the disc image to the lifted, tested, readable build, with an optional game check. It has **not yet been run end to end anywhere**. Each step's commands were checked against the real scripts' arguments. The step logic was tested in a scratch workspace with a recording stand-in for Python. Its `verify` step and the image decryption were run on the development machine's own copy. `tools/extract-xiso` was built with the `extract` step's CMake arguments (Clang, Ninja) into a scratch folder. On 2026-10-12 a fresh clone of the committed repository ran `verify`, `extract` and `stage`; the later steps have not run in a fresh clone. The manifest filter's refusal of a freshly extracted `default.xex` is fixed (2026-10-11, [build guide](building.md)). Dependency pinning, published reference hashes of the outputs, and the graphical installer remain to do. The [build guide](building.md) is the user-facing description.

The intended public distribution contains only tools, our own code and factual metadata. Everything derived from the
game (recompiled code, lifted readable code, extracted data) is produced on each user's machine
from their own disc. Goal: a small Tauri app where the user picks their ISO and gets the exact
same port we build.

## Order of work

1. **Prove the lifted build** - whole game lifted (`docs/lifted-code.md`), built, played with the
   bisect switches available. Fix lifter passes until the lifted build behaves like the recompiled
   one.
2. **Harden the pipeline** - `tools/setup_all.ps1 -Iso <path>`: every step below. Implemented:
   - resumable: each step records the content hashes of its real inputs, as they were when its work began, and
     its outputs. It is skipped when the inputs are unchanged and the outputs are still there
   - `-From`, `-To` and `-Force` to run part of the pipeline
   - `-DryRun` reports which steps would run and why
   - one log
   - the tested-function filter from the shipped verification manifest

   To do: a first fresh-machine run.
3. **Pin and verify** - pin every input (SDK commit, toolchain versions, lifter + ANALYSIS_VERSION,
   research/lift/summaries.json.gz, research/lift/verified.json.gz) and publish SHA-256 lists of the files each step must produce
   (hashes are not code). The pipeline compares and reports "identical to the reference build" or
   the exact differences. Done so far:
   - the decrypted image is checked against its reference hash
   - the executable is identified by `tools/xex_info.py`
4. **Tauri app** - Rust backend that runs the pipeline steps with progress, disk-space checks,
   retry/resume and readable errors; small web UI (pick ISO, choose install folder, progress,
   open log, launch).

## Pipeline steps

Times are from the development machine (8 threads) unless marked. "Implemented" means written and checked as described in the status note above, not yet verified on a fresh machine.

| # | Step | Output | Notes | State |
|---|------|--------|-------|-------|
| 1 | Verify ISO | - | Looks for the Xbox 360 file system in the image (seconds). The executable is identified after extraction | implemented |
| 2 | Extract | `iso/extracted/` | `tools/extract-xiso` (C, built with CMake on first use; with Clang it needs `-DWIN32`); not timed | implemented; the build was checked in a scratch folder |
| 3 | Stage | `Fable2Recomp/assets/game/` | `tools/xex_info.py` identifies `default.xex` (a copy padded to 100 MiB is accepted). Data is linked with a junction | implemented |
| 4 | Toolchain | LLVM/Clang 20+, CMake 3.29+, Ninja, Python 3.12+ with `tools/requirements.txt`, VS Build Tools; `rexglue.exe` | Checks only that the tools exist. Builds the SDK on first use and when its checkout moves. VS via Microsoft's installer (the user accepts its licence); investigate clang + xwin/mingw to avoid it | implemented (checks) |
| 5 | Recompile | `Fable2Recomp/generated/` | `rexglue codegen Fable2_config.toml`: 195 s (log of 2026-10-02) | implemented |
| 6 | Image | `research/decomp/default_image.bin` | `tools/xex_decrypt.py`, about 12 s; checked against the reference image hash | implemented |
| 7 | Class model | `tools/lift/cache/classes.json`, `lifted/classes.h` | From the shipped model `research/lift/class_model.json.gz` (`classes.py --bundle`, 2 s); computed here: `lift.py --facts` (about 25 min, 2026-10-05 run), then `classes.py --facts` | implemented |
| 8 | Declarations | `lifted/native_decls.h`, `native_bridges.N.cpp` | `native_gen.py`; not timed | implemented |
| 8b | Global names | `research/decomp/global_names.tsv` | `tools/naming/global_strings.py`, 33 s: the game's global string objects named after their text (local, never shipped) | implemented |
| 9 | Lift | `Fable2Recomp/lifted/` | `apply_names.py --init`, then `lift.py --all` with the shipped analysis: 9.5 to 27.6 min. Filter: `difftest/make_skip.py --manifest`, hashing about 3 min. Then the drop pass | implemented; manifest filter fixed 2026-10-11 for a freshly extracted `default.xex` (not yet run in a full setup) |
| 10 | Mod/research data (optional) | `extracted/` | `tools/bnk.py`, `tools/babel.py` | not in the script |
| 11 | Settings and runtime folder | `out/build/<preset>/Fable2.toml`, `assets/game/` | Settings from the shipped template; existing files are never overwritten | implemented |
| 12 | Build | `Fable2.exe` | `tools/build.ps1 -Preset win-amd64-release`. Incremental release builds take 30 to 41 min. A first build is estimated at about 2 hours: ninja's log adds up to 13.5 h of compile jobs run 8 at a time; never timed as one run | implemented |
| 13 | Game check (optional) | `build/autotest/setup_menu/` | `tools/autotest.py --scenario menu`, about 80 s, no desktop input | implemented |
| 14 | Install | install folder | exe, Fable2.toml, mods/, saves location, shortcut | not started |

Ship prebuilt where it is ours (SDK runtime DLL, native renderer, mod loader) so users only compile
the game-derived sources.

## Open questions

- XEX decryption: use the SDK's own loader (part of the open-source ReXGlue project) rather than a
  tool of ours; legal review.
- SDK version: the project pins ReXGlue v0.8.0 plus `patches/rexglue-sdk.patch` (14 of its fixes are backported from later
  ReXGlue releases). Moving to v0.10.0 or newer means rebasing the patch ([patches](../patches/README.md)).
- Other regions/versions: hash table per version; summaries bundle and verification manifest per executable.
- How closely does a fresh lift reproduce the tested text? The manifest helps only for functions whose lifted text
  is identical to the tested text. The first fresh run's `matched OK` count answers this.
