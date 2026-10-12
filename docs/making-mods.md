# Making Fable II mods

[Documentation index](README.md) · [Debug tools](debug-menu.md) · [Current status](status.md)

These tools are a development foundation for comprehensive modding. Individual features need broader in-game validation. Commands run from the workspace root.

Mods live in `mods/<ModName>/` at the repository root (folders starting with `_` are disabled).
`python tools/mods.py apply` installs every enabled mod; `python tools/mods.py restore` puts the
originals back. `python tools/mods.py list` shows what each mod changes and where mods conflict.
`python tools/mods.py check` validates the mods against the game without changing anything.

A mod writes to two places, because `Fable2.exe` reads them from two places:

| Option | Default | Receives |
|---|---|---|
| `--game <folder>` | `<exe dir>/assets/game` (what the exe uses without `--game_directory`) | bank files, loose `data/` files, text |
| `--exe-dir <folder>` | `Fable2Recomp/out/build/win-amd64-release` | `mods/<ModName>/tuning.toml` and `mods/<ModName>/native/*.dll` beside the exe (`src/modding/mod_loader.cpp`) |

Pass both when you run a different build or keep the game elsewhere. `restore` finds the record of
what `apply` changed in the game folder, so give it the same `--game`, or the same `--exe-dir` when
`apply` was given only `--exe-dir` (the game folder defaults to `<exe dir>/assets/game`). It reads the
executable folder from that record. Without a record at that place `restore` prints `nothing to
restore` and the folder it looked in.

Share original content, not extracted files or modified copies of original scripts. The editing examples below are for local experiments; use original content or local patch tooling for distribution. See [contributing](../CONTRIBUTING.md). The repository's `.gitignore` ignores every folder one level inside a mod (`mods/<Mod>/<folder>/`) except `native/`, so a plain `git add` leaves your mods' game-derived folders out; a forced add still stages them. Run `python tools/validate_commit.py` before committing: it checks the Git index and fails on anything staged below a mod's bank, `data/` or `text/` folders, plus `*.src.lua`, `*.babel` and `*.vfsconfig` files. It is a manual check, not a Git hook.

## What a mod can contain

| In the mod folder | What it changes | Get the originals with |
|---|---|---|
| `gamescripts_r/<path>` (e.g. `gamescripts_r/scripts/miscellaneous/saveload/postscriptsloaded.lua`) | a game script inside `data/gamescripts_r.bnk` (quests, AI, game flow) | `python tools/bnk.py extract <game>/data/gamescripts.bnk extracted/gamescripts --decompile` (reading aid, see below) |
| `guiscripts/<path>` (e.g. `guiscripts/scripts/gameface/menu/menulib.lua`) | a GUI script or layout inside `data/guiscripts.bnk` | `python tools/bnk.py extract <game>/data/guiscripts.bnk extracted/guiscripts --decompile` |
| `data/<path>` | a loose file under `data/` (e.g. `scripts/Startup/DebugMenu.txt`) | the game folder |
| `text/<language>.txt` | lines of game text: `<id><TAB><text>` | `python tools/babel.py export <game>/data/language/en-uk/text/book.babel extracted/text/en-uk.txt` |
| `tuning.toml` | the game's tuning values (combat, magic, experience orbs, movement, physics, debug switches) | `research/catalog/tuning.tsv`, or the F2 menu's Tuning tab |
| `native/*.dll` | C++ plugins that replace or extend any game function | `Fable2Recomp/sdk` |

Any other folder at the top of a mod names a bank (`<name>/` changes `data/<name>.bnk`), except
`__pycache__` and folders starting with `.` (`.git`, `.vscode`), which are skipped. Other files at the
top (a README, plugin sources) are not installed. Bank and language names are case-insensitive:
`GameScripts_R/` in one mod and `gamescripts_r/` in another build the same bank together. A mod with
nothing to install gets a warning.

### Scripts (quests, AI, menus, HUD)

Fable II's gameplay and UI logic is Lua. `--decompile` turns every compiled script into readable
source next to it (`*.src.lua`). It needs Java and [unluac](https://sourceforge.net/projects/unluac/), saved as
`tools/thirdparty/unluac.jar` (not part of this repository). To change one, copy it into your mod under the same path with the
`.src` dropped (`menulib.src.lua` -> `menulib.lua`) and edit it: the game compiles Lua source when it
loads it. Quest and AI scripts keep their original variable names; most GUI scripts were compiled
without them and decompile with placeholder names (`L1_2`) but work the same.

**Game scripts belong in `gamescripts_r/`.** The data folder ships two script banks with the same 554
paths:

- `data/startup.vfsconfig` mounts `gamescripts_r.bnk` (together with `guiscripts.bnk` and
  `skeletalmorphs.bnk` at the top level) and never names `gamescripts.bnk`. The executable has no
  `gamescripts` string either. A change to `gamescripts.bnk` is therefore never read, and
  `tools/mods.py` refuses a `gamescripts/` folder.
- `gamescripts.bnk` is worth extracting as a reading aid. It is the same scripts compiled with debug
  information, so it decompiles with the original local names. All 476 compiled chunks have
  identical instructions, constants and nested functions in both banks; only line and local-name
  information differs. Of the other 78 files, 76 scripts (`scripts/miscellaneous`, mostly enum
  tables) are stored as plain source in `gamescripts.bnk` and compiled in `gamescripts_r.bnk`; two
  `.txt` files are identical. A `.src.lua` decompiled from `gamescripts.bnk` is therefore a valid
  starting point for a `gamescripts_r/` file.

This conclusion is static: it comes from the vfsconfig, the executable's strings and a comparison of
the banks. The in-game confirmation is `mods/_Example_ModLoadTest` (see its README), which has not
been run yet.

Test changes live first: F2 opens the debug menu with a Lua prompt that runs code in the game.

`check` and `apply` catch the usual ways a script change silently does nothing:

- a bank that no vfsconfig mounts (`--allow-unmounted` overrides this except for `gamescripts`;
  `levels.bnk` and `streaming.bnk` are read by the game without being listed, and `tools/bnk.py`
  cannot rewrite them anyway);
- a `*.src.lua` name (the game loads `<name>.lua`);
- a path the bank does not contain. It is added as a new file, which only a script that asks for
  that exact path will load; you get a warning;
- a loose `data/` file that also exists inside a mounted bank. Which copy the game reads is not
  established, so you get a warning.

### Text

    00031C2A	Welcome to Bowerstone!

One string per line, id first, then a TAB; `\n` for line breaks. A line that starts with an id but
has no TAB (an editor turned it into spaces) is an error rather than a skipped line; put notes on lines
starting with `#`. An id the game already has changes that string.
An id it does not have adds a new string. The entry is inserted in id order, because the table is
sorted, and every other table in `book.babel` refers to strings by id. `check` lists new ids so a
mistyped id is visible. Whether a new string appears in game depends on the script that asks for
its id; this has not been tested in game. Several mods can change text; when two set the same id
differently the later mod (alphabetical) wins and it is listed as a conflict.

### Tuning

    [tuning]
    FlourishDamage = 2.5
    HeroSprintingEnabled = true
    QuickCastTimeSecs = 0.2

Names are listed in `research/catalog/tuning.tsv` (300 values); `check` warns about names that are
not in it (the game ignores them). `apply` installs the file as `<exe dir>/mods/<ModName>/tuning.toml`.
That is where the game reads it, and it applies those files in folder-name order, so later folders
win. A tuning value from a mod is pinned: the game's own scripts cannot change it afterwards. In game,
F2 -> Tuning shows every value live; tick "pin" to keep a value and "Save pinned as mod" writes
`mods/LiveTuning/tuning.toml` next to the game executable. `list`, `check` and `apply` read every
`tuning.toml` already in `<exe dir>/mods` that `tools/mods.py` did not install, and include it in the
conflicts table when it sets a value a mod also sets. A folder there that shares its name with an
enabled mod counts too, unless that mod has its own `tuning.toml` (which `apply` installs over it).

### Native plugins

A DLL exporting `Fable2Mod_Load(const Fable2ModApi*)` (see `Fable2Recomp/sdk/include/fable2/mod_api.h`
and the example `Fable2Recomp/sdk/examples/hello_mod`). It can replace any game function by address
(`api->hook_function`, the original stays callable), read and write game memory
(`fable2/sdk.h`), log, and run Lua. Function addresses and names: `research/catalog/functions.tsv`;
readable code to understand them: `research/decomp/named`. `apply` copies `native/*` to
`<exe dir>/mods/<ModName>/native/`. A build writes the DLL into the build folder (the CMake target
`Fable2ExampleMod` writes `HelloMod.dll` beside `Fable2.exe`), so copy it into the mod's `native/`
first; DLLs are not tracked by Git, and a mod without one gets a "nothing to install" warning.
`api->log` tags lines with the mod's folder name only while `Fable2Mod_Load` runs; lines logged later
from a hook carry the tag `[mod]`. The loader loads only names ending in lower-case `.dll`, and
only while `mods_native` is true (the default). Hooks from several plugins on the same function
chain at run time, so they are not listed as conflicts.

## Conflicts

`list`, `check` and `apply` print a table of every bank file, data file, string id and tuning value
that more than one mod changes differently, with the mod that wins. Tuning files already in
`<exe dir>/mods` that `tools/mods.py` did not install take part (see Tuning). Identical changes are
not conflicts. `--strict` makes `list`, `check` and `apply` exit with status 1 on any conflict, and
`apply` then changes nothing.

## Apply and restore

`apply` checks everything first and changes nothing if a check fails. Then it undoes the previous
apply, backs up every file it replaces as `<file>.orig`, and writes the new files. Every file and
folder it touches, in the game folder and the exe folder, is recorded in
`<game>/fable2re_mods_state.json`, before the file is touched. `restore` moves each original back
(byte for byte, timestamps included), deletes the files and empty folders `apply` created, and
removes the record. A file you edited after `apply` is kept as `<file>.after-mods` rather than lost.
Backups and markers left by the older `tools/mods.py` (`*.orig`, `*.modadded`,
`.installed_by_mods_py`) are restored the old way when no record exists.

If you moved or renamed the game folder after `apply`, run `restore --game <new folder>`: the
recorded paths are taken relative to where the record is now. The executable folder moves with it
when the game was inside it (the default `<exe dir>/assets/game`); otherwise the recorded executable
folder is used, or `--exe-dir` when the recorded one no longer exists. If the record is unreadable
(for example, truncated), `check`, `apply` and `restore` stop without changing anything and list the
`*.orig` backups to put back by hand.

## Rewritten game code

Parts of the game are being rewritten as readable C++ (`Fable2Recomp/src/game`, see
`docs/conversion-guide.md`). If you suspect a rewrite misbehaves, switch it back to the original
in `Fable2.toml`:

    rewrites_disabled = "combat.health,tuning"
