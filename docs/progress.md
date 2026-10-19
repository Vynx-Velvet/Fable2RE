# Conversion progress

<!-- written by tools/progress.py from tracked files: do not edit by hand -->

As of **2026-10-19**, **18.1%** of Lionhead's game functions are human-readable C++ in this repository: 7,435 of 41,186, 4.7% of the game's code by size. Fable2RE rebuilds the game as readable C++ ([direction](project-direction.md)); this page counts how far that has come.

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="images/progress-dark.svg">
  <img alt="18.1% of Lionhead's game functions are human-readable C++ (7,435 of 41,186), as of 2026-10-19" src="images/progress-light.svg" width="860">
</picture>

## Lionhead's game code

The game and engine code and its start-up initialisers: the code Lionhead wrote.

| Kind | Functions | Share | Code bytes | Share |
|---|---:|---:|---:|---:|
| Human-readable C++, reviewed | 7,378 | 17.9% | 569,304 | 4.7% |
| Human-readable C++, written by hand | 57 | 0.1% | 5,080 | 0.0% |
| Machine-translated C++, exact and tested | 32,714 | 79.4% | 11,361,776 | 93.1% |
| Recompiled only | 1,037 | 2.5% | 263,156 | 2.2% |
| **Total** | **41,186** | | **12,199,316** | |

Of the reviewed functions, 5,900 are look-alikes that carry the reviewed rewrite of their group's representative with their own values (see what is counted, below).

## The whole executable

Every function of `default.xex`, by area ([scope](../research/catalog/scope.tsv)). Middleware and system libraries are not reconstructed as readable code; they are to be replaced by native PC equivalents ([roadmap](roadmap.md)).

| Area | Functions | Human-readable | Machine-translated | Recompiled only |
|---|---:|---:|---:|---:|
| Game and engine code | 32,344 | 2,120 (6.6%) | 29,187 (90.2%) | 1,037 (3.2%) |
| Start-up initialisers | 8,842 | 5,315 (60.1%) | 3,527 (39.9%) | 0 (0.0%) |
| Middleware libraries | 11,437 | 0 (0.0%) | 11,231 (98.2%) | 206 (1.8%) |
| System libraries | 7,059 | 0 (0.0%) | 6,435 (91.2%) | 624 (8.8%) |
| Unidentified code | 1,179 | 0 (0.0%) | 1,138 (96.5%) | 41 (3.5%) |
| **All** | **60,861** | **7,435** (12.2%) | | |

## Names

The shared naming dictionary ([research/names](../research/names/README.md)) that every translation and every readable module uses.

| Names | Count |
|---|---:|
| Game functions with a name | 5,232 (12.7%) |
| Function names | 6,085 |
| Class names | 487 |
| Field names | 940 |
| Local variable names | 5,873 |

## History

A row for every day the numbers changed in this repository.

| Date | Human-readable | Share | Reviewed | By hand | Machine-translated | Recompiled only | Named |
|---|---:|---:|---:|---:|---:|---:|---:|
| 2026-10-19 | 7,435 | 18.1% | 7,378 | 57 | 32,714 | 1,037 | 5,232 |
| 2026-10-17 | 1,498 | 3.6% | 1,441 | 57 | 38,651 | 1,037 | 5,232 |
| 2026-10-15 | 1,263 | 3.1% | 1,206 | 57 | 38,886 | 1,037 | 5,232 |

## What is counted

- **Human-readable C++, reviewed.** A language model rewrote the lifter's exact code for the function into readable C++; it passes a strict differential check against the original on six input profiles, a review, a build and the game checks ([promoted code](promoted-code.md)). A look-alike (code the same as another function's apart from its addresses, numbers and callees) can instead carry its group representative's reviewed rewrite with its own values; it passes the same check, and its review record names the representative ([look-alikes](../research/findings/2026-10-18-lookalike-functions.md)).
- **Human-readable C++, written by hand.** Written by hand for this port and checked against the original ([conversion guide](conversion-guide.md)).
- **Machine-translated C++, exact and tested.** The lifter's structured C++ with real signatures and every name the dictionary knows. It is exact (the differential tester compares it with the original), but mechanical to read ([lifted code](lifted-code.md)).
- **Recompiled only.** Runs as ReXGlue's instruction-by-instruction recompilation, because no translated form of it has passed the tester yet.

Every function of the executable counts once, in its most finished form. Only files in this repository count: the catalog (`research/catalog/`), the published modules (`Fable2Recomp/promoted/`), the hand-written replacements (`Fable2Recomp/src/game/`), the verification manifest (`research/lift/verified.json.gz`) and the dictionary (`research/names/`). Work on a development machine that is not published yet (rewrites waiting for review, newer tester results) counts once it is. `python tools/progress.py` updates this page, the chart and the README; `--check` (run by the CI and by `tools/publish.py`) fails when they are out of date.
