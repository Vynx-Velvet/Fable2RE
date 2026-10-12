# Fresh clone, end to end: from the disc image to the title screen

Date: 2026-10-12. Commit tested: the initial commit (`tools/test_fresh_clone.ps1`, release blocker 4 in
[the audit](../../docs/initial-commit-audit.md)).

## What ran

`tools/test_fresh_clone.ps1` cloned the repository with `--no-local` (committed files only), checked out the
submodules from their public URLs, and ran `tools/setup_all.ps1 -Check` on a real disc image (the Game of the Year
disc, media ID `716F0A0D`). Machine: Windows 10, 8 logical CPUs, 32 GB, Clang 22.1.7, CMake 3.29.2, Ninja 1.12.0,
Python 3.14. The same machine as development, so the toolchain was already installed; the clone had no build
output, caches or local data of the development tree. Temporary files went to the clone (`.tmp`), not the system
drive.

| Step | Time |
|---|---|
| `verify`, `extract`, `stage` (earlier the same day) | 3 min |
| `toolchain` (SDK patch, SDK build) | 23 min |
| `codegen` | 4 min |
| `image` (decryption, function strings; earlier the same day) | under 1 min |
| `classes` | 22 min |
| `decls` | 5 s |
| `lift` (with the manifest filter) | 23 min |
| `config` | 0 s |
| `build` (game, release) | 60 min |
| `check` (`autotest.py --scenario menu`) | 50 s |
| total from `toolchain` | 2.2 h |

Disk: 11 GB for the clone with its extracted disc, lifted code and build.

**Result: OK.** The game built from the clone started, reached the title screen (screenshot mean luma 117; the shot and
its two follow-up frames all rated ok), played audio (20 of 21 two-second periods not silent), wrote no critical
log lines and exited with code 0 after 47 s.

## The lift and the verification manifest

The lift lifted 59,908 functions and left 42 recompiled. `make_skip.py --manifest` then kept 57,321 of them
(identical hash and verdict OK) and returned 3,000 to the recompiled original:

| | fresh clone | development tree |
|---|---|---|
| matched OK | 57,321 | 57,689 |
| hash differs | 371 | 0 |
| not in manifest | 1,233 | 23 |
| manifest verdict not OK | 983 | 0 |
| overridden | 413 | 413 |
| skip list | 3,000 | 1,422 |

(Development tree: the same command against its own lifted output, written to a scratch file.)

- **Not in manifest, 1,210 of 1,233:** exactly the functions of the promoted modules
  (`Fable2Recomp/src/game/promoted/`), which are not committed. In the development tree those modules define the
  functions, so they were never lifted or tested; in a clone without them they are lifted, unknown to the manifest
  and left recompiled. Intended. The other 23 are the development tree's local rewrites.
- **Hash differs, 371:** the class model. The development tree's class-recovery facts (`tools/lift/cache/facts`)
  were collected on 2026-10-05 and its class model built on 2026-10-07; `lift.py` changed after that (last on
  2026-10-10). The clone collects the facts with the current `lift.py`, and its model gives a `this` class to 216
  more functions and a different one to 185. Of the 368 functions that the development tree has verified in their
  old form, 354 are functions whose `this` assignment changed: their lifted text changes, the hash no longer
  matches, and they safely stay recompiled.

So a new user gets 368 fewer lifted functions than the development tree (0.6%), with no loss of correctness. To
close the gap, refresh the class model in the development tree, lift, retest and export the manifest again (a
whole-game cycle, overnight); new setups then match the manifest again.

## Other observations

- The SDK configures with the warning `rex_compute_version: no v* tag reachable from HEAD` and calls itself
  `0.8.0.0-dev.unknown`: the pinned commit is the "Release v0.8.0" commit on ReXGlue's main branch, not the
  `v0.8.0` tag. Harmless.
- `test_fresh_clone.ps1` used `Tee-Object`, which in Windows PowerShell 5.1 appends UTF-16 to the UTF-8 log; it
  now writes the setup's lines as UTF-8.
- Not covered: a machine without the toolchain installed, other disc images, and anything beyond the menu
  scenario.
