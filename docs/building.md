# Building the port

[Documentation index](README.md) · [Lifted code](lifted-code.md) · [Settings](settings.md) · [Installer plan](installer-plan.md) · [Status](status.md)

One command turns your own Fable II disc image into the native Windows build: recompiled code, the readable lifted C++ that replaces it function by function, and `Fable2.exe`. The repository ships tools, our own source code and facts about the executable (hashes, register analysis, names, test verdicts). Everything derived from the game is produced on your machine from your copy, and it stays there.

**Status, 2026-10-12:** `tools/setup_all.ps1` implements every step below. It has not been run end to end anywhere yet. What was checked:

- Each step's commands, against the arguments of the scripts it calls.
- The step logic (which steps run, what they record, the advice when a file is missing), in a scratch workspace with a recording stand-in for Python.
- On the development machine, only the `verify` step and the image decryption.
- The `extract` step's CMake arguments, by building `tools/extract-xiso` with Clang and Ninja into a scratch folder.
- In a fresh clone of the committed repository, its submodules fetched from their public URLs (2026-10-12): `verify`, `extract` and `stage` on the development machine's disc image, 3 minutes in all (`tools/test_fresh_clone.ps1 -To stage`). The steps from `toolchain` on have not run in a fresh clone yet.

Fixed 2026-10-11, not yet run in a full setup: `difftest/make_skip.py --manifest` used to refuse a freshly extracted disc, because it compared the whole-file hash of the 21 MB `default.xex` (`88c4ef2e...`) with the 100 MiB copy the manifest was made from (`39f0c8cd...`). It now identifies the executable as `tools/lift/bundle.py` does, so both count as the same executable. See also the [installer plan](installer-plan.md).

## What you need

- **Your own disc image** of the Game of the Year disc. `tools/xex_info.py <default.xex>` identifies the executable. The supported one is 21,217,280 bytes with SHA-256 `88c4ef2e...`. A copy that an older extractor padded to 100 MiB (`39f0c8cd...`) is the same executable and is accepted too.
- **This repository with its submodules**: `git submodule update --init --recursive` fetches the public ReXGlue SDK release (with its third-party libraries) and `tools/extract-xiso`. The project's changes to the SDK are `patches/rexglue-sdk.patch`; the setup's toolchain step applies them (`python tools/sdk_patch.py status` shows the state).
- **Windows x64** with:
  - Git (it fetches the submodules, and `tools/sdk_patch.py` applies the SDK patch with it)
  - Visual Studio Build Tools (C++ tools and a Windows SDK)
  - LLVM/Clang 20 or newer
  - CMake 3.29 or newer
  - Ninja
  - Python 3.12 or newer with the packages in `tools/requirements.txt` (`python -m pip install -r tools/requirements.txt`: `cryptography` for the image step, `Pillow` and `numpy` for the game checks)
- **Disk space**:
  - disc image: 7.3 GB
  - extracted files: about the same again
  - `Fable2Recomp/generated`: about 300 MB
  - `Fable2Recomp/lifted`: about 260 MB
  - the release build tree

The `toolchain` step checks that the commands exist (Git, CMake, Ninja, Clang), the Python version, the packages of `tools/requirements.txt` (`cryptography`, `Pillow`, `numpy`) and that the Visual Studio installer is there. It does not check the versions of the other tools, or that the Visual Studio C++ tools and a Windows SDK are installed: the SDK build fails without them. The `stage` step runs Python earlier (`tools/xex_info.py`). Like `toolchain`, it first checks that `python` really runs and is 3.12 or newer. On Windows 10 and 11, `python` can be the Microsoft Store alias, which only prints "Python was not found".

## One command

```powershell
powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -Iso 'D:\Games\Fable II.iso'
```

Each step records its inputs and its outputs in `tools/.setup/<step>.json` when it finishes. The next run skips every step whose inputs are unchanged and whose outputs are still there. After a `git pull`, run the same command without `-Iso`; only what the update affects runs again. The full output goes to `tools/.setup/setup.log`. The tools run at below-normal priority, so the machine stays usable.

| Step | What it does | Output | Time on the development machine (8 threads) |
|------|--------------|--------|----------------------|
| `verify` | The image exists and has an Xbox 360 file system | - | seconds |
| `extract` | `tools/extract-xiso` (built with CMake on first use) | `iso/extracted/` | disk-bound, not timed |
| `stage` | `default.xex` must be the supported executable (`tools/xex_info.py`). Copies it and links the data with a junction (no 7 GB copy) | `Fable2Recomp/assets/game/` | seconds |
| `toolchain` | Checks the tools. Builds the ReXGlue SDK (`rexglue.exe`) on the first run and when the SDK checkout moved | `rexglue-sdk/out/install/win-amd64/bin/rexglue.exe` | first SDK build not timed |
| `codegen` | `rexglue codegen Fable2_config.toml`: the game recompiled instruction by instruction | `Fable2Recomp/generated/` | 195 s |
| `image` | `tools/xex_decrypt.py`. The result must match the reference image hash | `research/decomp/default_image.bin` | about 12 s |
| `classes` | Class model: from the shipped model (`classes.py --bundle`), or computed here (`lift.py --facts`, then `classes.py --facts`; see `-Classes`) | `tools/lift/cache/classes.json`, `structs.json`, `Fable2Recomp/lifted/classes.h` (computed: also `tools/lift/cache/facts`) | shipped: 2 s; computed: facts about 25 min, and a rename re-runs only `classes.py` |
| `decls` | `native_gen.py`: native entry points and bridges | `Fable2Recomp/lifted/native_decls.h`, `native_bridges.N.cpp` | not timed |
| `globals` | `tools/naming/global_strings.py`: names the game's global string objects after their text. The names are the game's own text, so they are written here, never shipped | `research/decomp/global_names.tsv` | 33 s |
| `promoted` | `tools/rewrite/promoted_text.py render`: the reviewed readable modules, which the repository holds without the game's text (`Fable2Recomp/promoted/`), written out with the text from your copy. Every file must match the SHA-256 it was published with ([promoted code](promoted-code.md)) | `Fable2Recomp/src/game/promoted/` | seconds |
| `lift` | `apply_names.py --init` records the names the lift uses. Then `lift.py --all`, after which only tested functions stay lifted (below) | `Fable2Recomp/lifted/lifted.N.K.cpp`, `tools/lift/cache/applied_names.json` | 9.5 to 27.6 min for the lift, plus about 3 min for the test filter |
| `config` | Installs `Fable2.toml` from [the template](settings.md) and stages `assets/game` beside the exe. Never overwrites | `Fable2Recomp/out/build/<preset>/` | seconds |
| `build` | `tools/build.ps1 -Preset win-amd64-release -Target Fable2`. Always runs; ninja compiles only what changed | `Fable2Recomp/out/build/win-amd64-release/Fable2.exe` | first build: about 2 hours (estimated). Incremental release builds: 30 to 41 min |
| `check` | Only with `-Check`. `tools/autotest.py --scenario menu` boots to the main menu, takes a snapshot and exits. Unattended, with no desktop input | `build/autotest/setup_menu/summary.txt` | about 80 s |

About these times:

- Codegen: from its log on 2026-10-02.
- Image: measured while the machine was busy.
- Facts: from the files' timestamps of the 2026-10-05 run.
- Lift and incremental builds: the range of the development machine's runs.
- Test filter: hashing 57,712 functions with 3 jobs took 167 s.
- The first-build figure is an estimate. Ninja's log adds up to 13.5 hours of compile jobs (7.3 h lifted chunks, 2.5 h generated files), and the build runs 8 at a time. It was never timed as one run.

### Which lifted functions stay lifted

The tester compiles the lifted and the recompiled form of a function and compares them on recorded inputs. A lifted function is kept only if it was tested in exactly the form this machine produced. `-Tested` chooses where the verdicts come from:

- `manifest` (default on a fresh machine): the shipped verdicts in `research/lift/verified.json.gz`. The file holds only hashes and verdict classes, no code. The tool is `tools/lift/difftest/make_skip.py --manifest`. Its list is written to `tools/lift/cache/manifest_skip.txt`; the tracked `tools/lift/skip.txt` is left alone, so `git pull` keeps working. Every function whose text is not exactly a version that tested OK goes back to its recompiled original.
- `status` (default once `tools/lift/difftest/results/status.json` exists): this machine's own tester results. `make_skip.py` writes `tools/lift/skip.txt`.
- `tester`: runs the tester on every function whose text changed (`tools/lift/update.ps1`), then drops the failures. It needs a built release tree, so a fresh machine runs it only after a first `build`.
- `none`: keeps every lifted function except `tools/lift/overridden.txt`. These functions are untested; this mode is for developers only.

The manifest's hashes are of the text the development machine lifted, and that text depends on its class model. The class model therefore ships too: `research/lift/class_model.json.gz` holds its structure (vtables, base classes, constructors, the class of each function's `this`, field offsets and sizes; no names, no code). `-Classes` chooses where the model comes from:

- `auto` (default): the shipped model with `-Tested manifest`, when it fits this executable and typeflow is off; otherwise computed here.
- `shipped`: `classes.py --bundle`. Names come from the naming dictionary and, for the rest, from RTTI in your own image. Seconds.
- `facts`: computed here, `lift.py --facts` (about 25 minutes) and `classes.py --facts`. The development machine (`-Tested status`) does this.

## Options

```powershell
# What would run, and which inputs changed (runs nothing)
powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -DryRun

# Re-run steps although they are up to date ("all" = every step in the range)
powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -Force lift
powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -From codegen -Force all

# Only part of the pipeline: start at a step, stop after one
powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -From image -To lift

# Also boot the game once at the end (closes a running Fable2.exe first)
powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -Check
```

- `-From <step>` starts at that step. Earlier steps are neither run nor checked, and every step from there on still runs only when its inputs changed. Before 2026-10-10, `-From` also forced those steps; that now takes `-Force all`. To run one step again although nothing changed, use `-From <step> -Force <step>`. The error message gives this command when a later step finds that step's output missing.
- `-To <step>` stops after that step.
- `-Force` takes a comma list of steps, or `all`.
- `-Preset` picks another build preset. `-Jobs` sets the number of `lift.py` and `make_skip.py` worker processes (default: the processor count, at most 8).

### What counts as a step's inputs

Hashes of file contents. `tools/.setup/hashes.json` caches each hash by file size and modification time.

- `classes` and `lift`:
  - the generated sources
  - the analysis in use (`tools/lift/cache/*.pkl` when this machine computed it, else the shipped `research/lift/summaries.json.gz`)
  - the decrypted image
  - the lifter's Python sources (every module the entry script imports, found by scanning `tools/lift`)
  - `LIFT_*` environment variables
- `lift` also:
  - `research/names/*.tsv` and `research/catalog/functions.tsv`
  - `tools/lift/overridden.txt`
  - the promoted modules (`Fable2Recomp/src/game/promoted/*.cpp`, rendered by `promoted`; the lifted files leave their functions out)
  - local rewrites (`Fable2Recomp/rewritten/`)
  - the class model
  - the verdict source (manifest or `status.json`)
- Computed here, the `facts` part of `classes` leaves out names. A rename re-runs `classes.py`, not the 25-minute facts pass.
- A step's own outputs count too. When one is missing, the step runs again. `stage`, `codegen` and `image` record their output's hash, so a changed output also counts. The outputs are:
  - `iso/extracted/default.xex` (`extract`)
  - the staged `default.xex` (`stage`)
  - `generated/` (`codegen`)
  - the decrypted image (`image`)
  - `classes.json`, `structs.json` and `classes.h` (`classes`)
  - `native_decls.h` (`decls`)
  - the rendered modules in `src/game/promoted/` (`promoted`)
  - at least one lifted chunk (`lift`)
  - `Fable2.toml` and `assets/game/default.xex` beside the exe (`config`)

  A deleted `Fable2.toml` is therefore installed again from the template on the next run.

Renames made in `research/names` but not yet applied are applied first, by `tools/lift/apply_names.py`, which also updates the promoted modules. The record keeps the inputs as they were when the step's work began, after those renames. A rename made while a long step runs therefore still counts as a change on the next run.

A workspace whose earlier steps were done by hand has no records. A plain run there would start with codegen and recompile the whole game. Start such a workspace at a later step with `-From image`. Its first run also includes the 25-minute facts pass, because the `classes` step has no record yet.

`tools/lift/verify_and_build.ps1` is the development machine's lifter-wide cycle: `setup_all.ps1 -From lift -To build -Force lift -Tested tester`. It does not refresh the class model or the native declarations. A new class model changes the structs that every lifted chunk carries, so refresh it with a separate run, overnight: `setup_all.ps1 -From classes -To build -Tested tester`.

## The same by hand

From the repository root, with `$env:REXSDK` set to `rexglue-sdk`:

```powershell
tools/extract-xiso/build/extract-xiso.exe -x -d iso/extracted 'D:\Games\Fable II.iso'   # options before the image
python tools/xex_info.py iso/extracted/default.xex                                     # exit 0 or 4: supported
Copy-Item iso/extracted/default.xex Fable2Recomp/assets/game/default.xex
New-Item -ItemType Junction -Path Fable2Recomp/assets/game/data -Target iso/extracted/data
powershell -File tools/build.ps1 -Sdk                                                  # rexglue.exe
Push-Location Fable2Recomp; & ../rexglue-sdk/out/install/win-amd64/bin/rexglue.exe codegen Fable2_config.toml; Pop-Location
python tools/xex_decrypt.py Fable2Recomp/assets/game/default.xex research/decomp/default_image.bin
```

Then, from `tools/lift` (the [lifting guide](lifted-code.md) explains each command):

```powershell
python bundle.py check                     # the shipped analysis fits this default.xex
python classes.py --bundle                 # class model from the shipped one, lifted/classes.h
                                           # (computed instead: python lift.py --facts, then python classes.py --facts)
python native_gen.py                       # native declarations and bridges
python apply_names.py --init               # the names the lift uses (before it: a rename during the lift stays pending)
python lift.py --all --skip overridden.txt
python difftest/make_skip.py --manifest ../../research/lift/verified.json.gz --out cache/manifest_skip.txt
python lift.py --funcs cache/manifest_skip.txt --skip cache/manifest_skip.txt
```

Finally, from the root:

```powershell
cmake -DSRC=Fable2Recomp/config/Fable2.default.toml -DDST=Fable2Recomp/out/build/win-amd64-release/Fable2.toml -P Fable2Recomp/config/install_default_config.cmake
powershell -File tools/build.ps1 -Preset win-amd64-release -Target Fable2
```

`tools/build.ps1` ends with `exit`. Run it in its own PowerShell process, as above, never with `&` inside another script. It runs the build in a job object, so an interrupted build leaves no compiler processes behind. Do not build the SDK while a codegen runs.

## Where things go

| Path | Contents | Tracked by git |
|------|----------|----------------|
| `iso/extracted/` | the extracted disc | no |
| `Fable2Recomp/assets/game/` | `default.xex` and the `data` junction used by codegen and the bundle check | no |
| `Fable2Recomp/generated/` | recompiled code | no |
| `research/decomp/` | `default_image.bin` (the decrypted executable image), `function_strings.tsv` and `global_names.tsv` (text from the executable, for the naming tools and the lift) | no |
| `tools/lift/cache/` | facts, class model, analysis caches, `manifest_skip.txt`, `applied_names.json` | no |
| `Fable2Recomp/lifted/` | `lifted.N.K.cpp`, `classes.h`, `native_decls.h`, `native_bridges.N.cpp`, `lift_report.txt` (`lifted.h` is tracked) | no |
| `Fable2Recomp/out/build/<preset>/` | `Fable2.exe`, `build.log`, `Fable2.toml`, `assets/game/` (game files and saves), `fable2.log` | no |
| `tools/.setup/` | step records, `setup.log`, hash cache | no |
| `build/autotest/` | `-Check` results | no |

## Known limitations

- Run end to end once, from a fresh clone on the development machine (2026-10-12: 2.2 hours from the SDK build to the title screen, [record](../research/findings/2026-10-12-fresh-clone-end-to-end.md)); not yet on a machine without the toolchain. Check the `matched OK` count that `make_skip.py` prints. The manifest helps only when this machine's lifted text matches the text that was tested; anything else safely falls back to the recompiled original. That run matched 57,321 functions; 371 more stayed recompiled because the development tree's class model is older than the lifter. Since then the class model ships (`-Classes`, above), and a new setup lifts the tested text.
- `verify` and `extract` run before the `toolchain` check. `extract` checks only for CMake, which it needs to build extract-xiso. With Ninja and Clang on PATH it builds with Clang and defines `WIN32`, which extract-xiso's bundled `getopt` needs. Clang defines only `_WIN32`.
- `codegen` records a hash of `generated/` as its output. A hand edit there makes the next run generate the code again. The `lift` step checks only that lifted chunks exist, not their content.
- The `extract` record uses the image's path, size and modification time, not a hash of all 7 GB.
- The shipped analysis and the manifest belong to one executable and one set of analysis rules. When `bundle.py check` fails, setup stops and names the scripts that compute the analysis locally (see [lifted code](lifted-code.md#the-whole-game-analysis)). With a local analysis the manifest does not apply: use `-Tested tester` after a first build.
- The `tester` mode needs the configured and built release tree, so it cannot be the first run's mode.
- The SDK's revision counts as a toolchain input; its uncommitted changes do not.

## Launch and configuration

By default the application looks for `assets/game/` beside the executable. The `config` step stages it there. `--game_directory` names another **assets parent**, beneath which the game appends `game` and `update`:

```powershell
$fableAssets = (Resolve-Path 'Fable2Recomp/assets').Path
& './Fable2Recomp/out/build/win-amd64-release/Fable2.exe' --game_directory "$fableAssets"
```

`Fable2.toml` beside the executable holds flat runtime keys. When no `Fable2.toml` exists there, the `config` step installs the shipped template `Fable2Recomp/config/Fable2.default.toml`; the first link of the `Fable2` target does the same. The template sets:

- the native renderer
- keyboard and mouse
- a 60 fps target
- the reverb workaround
- lifted code, with the XAudio2 range left recompiled

An existing file is never overwritten. The [settings reference](settings.md) lists every key with its compiled default and verification status. `Fable2.toml` is not the source-tree `Fable2_config.toml` that codegen reads. See also [debug tools](debug-menu.md) and [rewrite controls](conversion-guide.md).

For a bounded diagnostic run:

```powershell
powershell -File tools/run_game.ps1 -Preset win-amd64-release -Seconds 120 -Tag baseline
```

The harness closes any running `Fable2` processes and ends the run after the requested time. Use a backed-up test save. Captures are written under the preset's `runs/` directory.

For mods, point `tools/mods.py --game` at the game folder in use (default: the release build's `assets/game/`) and `--exe-dir` at the folder of the `Fable2.exe` you run (default `Fable2Recomp/out/build/win-amd64-release`): `tuning.toml` files and native plugins go to `<exe dir>/mods/<Mod>/`. `restore` needs only `--game`. See [making mods](making-mods.md).

### Game checks

`tools/autotest.py` boots the game unattended (scripted pad input inside the process, snapshots, log scan) and is the runtime check every change goes through:

```powershell
python tools/autotest.py --suite            # menu, load, play, newgame, resume in order; stops at the first failure
python tools/autotest.py --scenario menu    # one scenario (newgame: the prologue through the intro cutscene;
                                            # resume: Continue on the save the game writes at New Game start)
python tools/autotest.py --make-golden      # once: your current save slot becomes the known-good save load/play start from
python tools/autotest.py --make-golden --scenario resume   # once, after a newgame run: that save becomes resume's
python -m unittest discover -s tools/tests  # the checker's own tests (seconds, no game)
```

A run passes only with every requested snapshot present and not blank, and only the log lines written by that launch are read. Exit codes: 0 = OK or `OK_EXIT_CRASH` (the known crash while closing), 1 = problem or the game did not start, 2 = setup error (for example no golden save), 3 = `OK_EXIT_CRASH` under `--strict-exit`. Every run appends a line to `build/validation/ledger.jsonl` (scenario, result, executable hash, repository revisions, settings hash). `tools/lift/full_cycle.ps1` stops at the first game check that fails.
