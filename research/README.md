# Research index

These are dated observations from specific executables and builds. Later findings can correct earlier conclusions. See [current status](../docs/status.md) and the [conversion guide](../docs/conversion-guide.md).

| Date | Investigation |
|---|---|
| 2026-10-12 | [Global string names: generated locally, not shipped](findings/2026-10-12-global-names-local.md) |
| 2026-10-12 | [Fresh clone, end to end: from the disc image to the title screen](findings/2026-10-12-fresh-clone-end-to-end.md) |
| 2026-10-10 | [The supported executable: identity, the 100 MiB over-read, no title update](findings/2026-10-10-executable-identity.md) |
| 2026-10-10 | [Promoted code: the native-call check](findings/2026-10-10-native-call-check.md) |
| 2026-10-07 | [Differential tester: wrapped-pointer timeouts](findings/2026-10-07-difftest-wrapped-pointer-timeouts.md) |
| 2026-10-05 | [Readable-pass cycle: regressions and fixes](findings/2026-10-05-readable-cycle-regressions.md) |
| 2026-10-05 | [Re-scope and a faster plan](findings/2026-10-05-scope-and-faster-plan.md) |
| 2026-10-05 | [Structural type inference](findings/2026-10-05-structural-types.md) |
| 2026-10-05 | [XER summary-overflow invariant](findings/2026-10-05-xer-so-invariant.md) |
| 2026-10-04 | [Whole game as readable native C++](findings/2026-10-04-full-native-plan.md) |
| 2026-10-02 | [Decompilation and modding](findings/2026-10-02-decomp-and-modding.md) |
| 2026-10-02 | [Debug menu and Lua](findings/2026-10-02-lua-debug-menu.md) |
| 2026-10-02 | [Area performance](findings/2026-10-02-area-perf.md) |
| 2026-10-01 | [Native subsystem inventory](findings/2026-10-01-native-roadmap.md) |
| 2026-10-01 | [Retiring the command processor](findings/2026-10-01-retiring-the-command-processor.md) |
| 2026-09-30 | [D3D runtime map](findings/2026-09-30-d3d-runtime-map.md) |
| 2026-09-30 | [D3D objects and state](findings/2026-09-30-d3d-objects-and-state.md) |
| 2026-09-28 | [Title screen reached](findings/2026-09-28-title-screen-reached.md) |
| 2026-09-28 | [Foreign configuration root cause](findings/2026-09-28-foreign-config-root-cause.md) |
| 2026-09-28 | [Reverb and draw fast paths](findings/2026-09-28-reverb-echo-and-draw-fastpath.md) |

`symbols/` and `catalog/` hold recovered names, layouts, and conversion metadata. Counts depend on the generation used and are not a percentage-complete metric. `decomp/` holds local game-derived exports and stays local.

New findings should record the executable/build, question, addresses or tools, observations, validation, remaining uncertainty, and older conclusions superseded. Publish factual descriptions and project-authored tools, not extracted content.
