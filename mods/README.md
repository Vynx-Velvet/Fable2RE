# Mods

See [making mods](../docs/making-mods.md) for text, tuning, and native plugins, and [contributing](../CONTRIBUTING.md) for distribution guidance. The examples below describe local editing.

Each folder here is one mod. Folders starting with `_` are disabled.

    mods/<ModName>/gamescripts_r/<path in the bank>  replaces/adds a game script in data/gamescripts_r.bnk
    mods/<ModName>/guiscripts/<path in the bank>     replaces/adds a GUI script in data/guiscripts.bnk
    mods/<ModName>/data/<path>                       replaces/adds a loose file under data/
    mods/<ModName>/text/<language>.txt               changes/adds game text lines
    mods/<ModName>/tuning.toml                       tuning values  -> <exe folder>/mods/<ModName>/
    mods/<ModName>/native/*.dll                      C++ plugins    -> <exe folder>/mods/<ModName>/native/

Game scripts go under `gamescripts_r/`, not `gamescripts/`. `data/startup.vfsconfig` mounts
`gamescripts_r.bnk`, so a change to `gamescripts.bnk` would never be read; `tools/mods.py` refuses
such a folder.

Get the game's files to edit (from your own copy):

    python tools/bnk.py extract <game>/data/gamescripts.bnk extracted/gamescripts --decompile
    python tools/bnk.py extract <game>/data/guiscripts.bnk  extracted/guiscripts  --decompile

`gamescripts.bnk` is extracted only as a reading aid. It holds the same compiled scripts as
`gamescripts_r.bnk` plus debug information, so it decompiles with the original local names. The two
banks' code is identical apart from that debug information (all 476 compiled chunks compared).
`*.src.lua` files are the decompiled scripts. Copy one into your mod under the same path below
`gamescripts_r/` (or `guiscripts/`), named `<name>.lua` (without `.src`), and edit it. The game
compiles Lua source at load time. `--decompile` needs Java (`JAVA_HOME` or `java` on PATH) and
`tools/thirdparty/unluac.jar`: download unluac from https://sourceforge.net/projects/unluac/ (by tehtmi, MIT
licence) and save the jar there. It is not part of this repository.

Install / remove:

    python tools/mods.py list       # what each mod changes, and conflicts between mods
    python tools/mods.py check      # validates against the game; changes nothing
    python tools/mods.py apply      # backs originals up as *.orig, builds the modded files
    python tools/mods.py restore    # puts the originals back, byte for byte

Mods are applied in alphabetical order. When two mods change the same file, string or tuning value,
the later mod wins, and `list`/`check`/`apply` print a conflicts table. `--strict` makes them exit
with status 1 when there are conflicts (`apply` then changes nothing). Pass `--game <folder with data/>`
and `--exe-dir <folder of Fable2.exe>` when the game or the executable is not the release build's
default, and pass the same option to `restore`: the record of what `apply` changed is kept in the game
folder it used.

Never redistribute extracted files or modified copies of original scripts. Everything below a mod's
`gamescripts_r/`, `guiscripts/` (any bank folder), `data/` or `text/` folder comes from your game.
The repository's `.gitignore` ignores every folder one level inside a mod (`mods/<Mod>/<folder>/`)
except `native/`, so a plain `git add` leaves them out; a forced add still stages them. Run
`python tools/validate_commit.py` before you commit; it fails on such staged
paths (and on `*.src.lua`, `*.babel`, `*.vfsconfig` anywhere). It is not installed as a Git hook.
Share original content or tooling that applies edits to the user's own files locally (see
`_Example_ModLoadTest/make_example.py`).
