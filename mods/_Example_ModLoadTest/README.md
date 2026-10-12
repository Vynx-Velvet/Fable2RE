# Example: does a script mod load?

A disabled example (the leading `_` disables it) that adds one Lua function, `Fable2RE_ModTest()`, to the game's
`postscriptsloaded.lua`. If the function exists in game, the script mod pipeline works end to end.

Only the authored parts are in the repository: `modtest.lua` (the function) and `make_example.py`.
The script itself is built from your own copy and stays local:

    python mods/_Example_ModLoadTest/make_example.py [--game <folder that contains data/>]

This writes `gamescripts_r/scripts/miscellaneous/saveload/postscriptsloaded.lua`: the game's script
decompiled to source, followed by `modtest.lua`. It needs Java and `tools/thirdparty/unluac.jar`.
This folder's `.gitignore` keeps every subfolder (the generated `gamescripts_r/`) out of `git add`;
`python tools/validate_commit.py` fails if it is staged anyway.

- The folder is `gamescripts_r/` because `data/startup.vfsconfig` mounts `gamescripts_r.bnk`. A
  `gamescripts/` folder would change `gamescripts.bnk`, which the game never mounts, so
  `tools/mods.py` refuses it.
- The decompile is taken from `gamescripts.bnk` because it decompiles with the original local
  names. Apart from debug information its compiled code is identical to `gamescripts_r.bnk`'s (all
  476 compiled chunks compared), so either source gives the same script.

To try it: rename the folder to `Example_ModLoadTest`, run `python tools/mods.py apply`, start the
game, load a save, press F2 and run `Fable2RE_ModTest()`. "ok" means the modded script loaded; a
"nil value" error means it did not. `python tools/mods.py restore` undoes the change. This in-game
test has not been run yet.
