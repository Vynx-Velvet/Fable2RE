# The prologue, a crash on Continue, and 362 promoted functions with dropped hand-overs (2026-10-20)

## Question

After the 2026-10-19 publish (readable form, naming) the user's New Game runs went wrong: a camera that kept
going into the void with no intro cutscene, a crash on Continue, choppy play on the emulated GPU with "AI
positioning issues". Which of these are faults of the port, which of them come from last night's changes, and
what reproduces them?

## What the runs were (from the logs)

Every run's key presses are in the log (`MnK: key down`), so what each manual run did can be read back:

| Run | Keys at the main menu | Was | Outcome |
|---|---|---|---|
| 13:35, 13:38 | Space, Down/Up/Down, Enter or Space | Continue on the save of 21:40 | crash in Havok 8 s after loading |
| 13:41 (all our code off, native renderer) | Space, Down, Space | Continue on the same save | void, no cutscene (the prologue never starts; no speech loads) |
| 13:48 (emulated GPU) | Space, Down, Up, Space, Left, Space | New Game | played (choppy) |
| 13:51 (emulated GPU, our code off) | | New Game | played |
| 14:02 (emulated GPU, promoted game code off) | Space, Space, Space, Left, Space; Esc, Esc, Space | New Game, Start pressed around the end of the video | judged broken 26 s after the video; the cutscene's speech loaded at 184 s, after the user had closed it |

Four of the six broken or doubtful runs were **Continue on the save of 21:40**, and that save is one the game
writes itself: at New Game start, right after the character is chosen and before the video (seen again in a
scripted run: the save-device dialog and the `Save:` links appear 64 s in). The remaining doubtful run (14:02)
was on the emulated GPU, at 30 fps with stalls, with the Start button pressed twice around the end of the video.

**Scripted New Game runs** (`tools/autotest.py --scenario newgame`, added today: A, New Game, a direction and A on
the character cards, then snapshots through the video, the zoom and the cutscene): 8 of 8 passed with the native
renderer, with and without A presses during the video and the cutscene, choosing the boy or the girl, with audio
muted or on. The prologue works; the video, the zoom at about 135 s and the intro cutscene at the brazier from
about 160 s all render (`build/autotest/newgame_*`).

## The crash on Continue, bisected

Continue on a save written at New Game start crashes 8 s after loading, every time: Havok's convex-list shape
iterates its child shapes and one is null (`n_sub_82DB4880`; with that function on the recompiled original the
original crashes at the same place: the data is wrong, not that function). The save written by a scripted run
crashes the same way, so the save is normal and the loader is at fault.

`tools/lift/bisect_crash.py` (new): per run, half of a suspect address interval runs on the recompiled original
(`lifted_disable_ranges` through `F2_CVARS`, the config file untouched), the Continue script through
`F2_AUTOTEST`, and the run's log decides (the crash line, or the script's snapshot). 13 halvings over the 55,661
lifted and promoted functions, about 25 minutes, one function: **`sub_82272E28`,
`CBoneDriverGroup_ApplyTransformToBoneDrivers`**, promoted, reviewed OK on 2026-10-15.

Its reviewed text (the module as published before 2026-10-19, and the lifter's exact text) hands
`BoneDriver_Update` five values through registers before the call: `ctx.r4 = stack + 144` (the rotation matrix
just built on the frame), `r5 = stack + 128` (scale), `r6 = stack + 112` (rotation), `r7 = stack + 96`
(translation), `r8 = children`, and `ctx.r9 = boneDriver` before `hkRotation_SetFromQuaternion`. The text after
the readable-form pass of 2026-10-19 has none of them. `BoneDriver_Update` reads those addresses (the whole-game
analysis lists r4-r8 as passed on), so it got stale pointers and wrote the bone drivers' physics objects wrong;
the convex list shape with a null child is the damage, found later.

## Why the pass dropped them, and why nothing caught it

`tools/rewrite/readable_form.py` dropped a write to a register the callee only passes on (`fwd`) when the value
was a "leftover temporary": anything not built from the function's parameters. A frame address (`stack + 144`)
is not built from a parameter, so it counted as a temporary. Its first run also did not treat a call through a
pointer (`REX_CALL_INDIRECT_FUNC`) as a reader of every register (that rule came in only for the retry over the
141 functions that had failed the check).

The strict check cannot see either: its stand-in callees read nothing, and a register the callee passes on is
compared only when it holds an argument the function was entered with. A frame address never is one. The game
checks (menu, load, play on a mid-game save) do not reach the bone drivers from a prologue-start save. The
sampled review of the pass's output (2026-10-19) compared the promoted text with the lifted text and did not
flag the missing hand-overs either: the same blind spot, read by a person.

**362 promoted functions** lack register writes that the corrected rule keeps (the pass run again with the
corrected rule on each function's text from before the pass, its register writes compared with the module's;
`build/rewrite/affected_writes.tsv`), 50 of them for the indirect-call rule. They were published to GitHub in
PR #3 on 2026-10-19 (`cc93267`): the published `CBoneDriverGroup` module has 60 register writes against 70
before the pass.

## Repair

- `readable_form.py`: a write to a passed-on register is dropped only when its value is a literal or a
  `constexpr` address; a call through a pointer reads every register (both in the rule, the docstring and
  `RULES.md`'s terms).
- The 362: the pass with the corrected rule run again on each function's text from before it, the renames made
  since carried over (312 by token alignment with the current text, which the old rule's output has to reproduce
  exactly; 50 through the dictionary's address form and the naming round's recorded variable renames), every
  result through the strict check: 359 pass and are written, 3 fail it (`sub_82610E70`, `sub_82610FB0`,
  `sub_827D1090`: the re-derivation is not faithful) and are demoted to the lifter's exact code until promoted
  again from their reviewed rewrite.
- Checks: `tools/autotest.py` gains `newgame` (the prologue through the cutscene) and `resume` (Continue on the
  save the game writes at New Game start, with its own reference save `runs/save_golden_newgame`, made with
  `--make-golden --scenario resume`); both are in the suite that a publish runs. The scripted runner lets a run
  keep audio on (`F2_CVARS="audio_mute=false"`).

## Other findings on the way

- The game's own debug log: every run tries to open `D:\lhdebug.log` and is refused (the game data device is
  read-only); `allow_game_relative_writes=true` would let the game write it. Not used yet.
- The native renderer logs up to 16 rejected shader-load packets in every run (the cap is reached in the title
  phase); they are noise from the command-stream scan, not a signal.
- The shader-translation errors and the timed-out GPU memory wait seen only in the broken 13:41 run were
  consequences of the corrupted state, not causes.
- "Weird visual bugs" and choppiness were on the emulated Xbox GPU, the slow reference path, used only to tell
  the renderer apart. The "AI positioning issues" were reported after a 71 s run that did not reach the prologue's
  gameplay; what was seen is not known. With the repaired code, the user's own New Game run decides.
