# Patches to third-party code

## `rexglue-sdk.patch`

The changes the project's SDK has over the public [ReXGlue SDK](https://github.com/rexglue/rexglue-sdk) release it
pins. The `rexglue-sdk/` submodule points at the **v0.8.0** release commit on ReXGlue's `main` branch (`e8ce24fa73cd`,
"Release v0.8.0", 2026-05-16; the `v0.8.0` tag itself names `2bdb97f`, four release commits earlier). This patch,
applied to its working tree, gives the SDK the project builds with. It is source text only (59 files): fixes
backported from later ReXGlue releases (below) and Fable2RE's own changes (the codegen, kernel, GPU command processor
and synchronisation hooks the native renderer uses, audio fixes, keyboard and mouse input, diagnostics, build fixes
such as building libmspack from its real sources).

### Backported from ReXGlue (by their authors, released in v0.9.0/v0.10.0)

| Upstream commit | Author | Change |
|---|---|---|
| `29eaa8a` | Tom | fix(audio): decode kicked XMA contexts inline instead of blocking on the worker sweep |
| `e5c3554` | Tom | fix(audio): XMA loop wraps emitted garbage and dropped the loop-end frame |
| `a7638a5` | Tom | fix(audio): flush ffmpeg buffers on context release |
| `f24299f` | Tom | fix(audio): XMA loop wraps silenced the loop's last 192 samples |
| `f96d31a` | Tom | fix(audio): drop the previous wave's MDCT tail when a context is recycled |
| `3b5ef8a` | Tom | feat(audio): add StereoFold and master gain output-mix API |
| `4c31fcc` | Tom | fix(audio): correct the 5.1 to stereo fold and honor output gain |
| `6fe41ab` | Tom | feat(audio): drive the output stage from the StereoFold API |
| `2c35c40` | Tom | feat(audio): add a per-slot output matrix for surround devices |
| `f5c8521` | David | fix(audio): defer timer resolution policy to SDL |
| `0e4e996` | Tom | fix(audio): drain the worker thread before falling back to terminating it |
| `acb88c3` | bomabomabomaboma | fix(GPU): Fix mantissa placement in CPU 7e3to32 |
| `8e6baae` | bomabomabomaboma | fix(gpu): Update outdated ZPD sentinel pairwise assumption |
| `6124b36` | Tom | fix(gpu): drop the double-buffered page valid flags so frame-end refresh is coherent |

Moving the pin to a ReXGlue release that contains them makes these entries part of the base instead.

| Command | What it does |
|---|---|
| `python tools/sdk_patch.py status` | Checkout at v0.8.0? Patch applied? Working tree matches the patch? |
| `python tools/sdk_patch.py apply` | Applies the patch (`tools/setup_all.ps1` runs this before building the SDK) |
| `python tools/sdk_patch.py export` | Rewrites the patch from the working tree after you change SDK sources |

The patch keeps ReXGlue's licence and attribution: it modifies files of that project, which stays the source of
the SDK. Changes that are useful beyond Fable2RE are candidates for pull requests to ReXGlue. A newer ReXGlue
release is adopted by checking it out in `rexglue-sdk/`, applying the patch, resolving conflicts, updating `BASE`
in `tools/sdk_patch.py` and exporting again ([contributor workflows](../docs/contributor-workflows.md)).
