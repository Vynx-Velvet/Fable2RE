# Conversion progress

<!-- written by tools/progress.py from tracked files: do not edit by hand -->

As of **2026-10-15**, **3.1%** of Lionhead's game functions are human-readable C++ in this repository: 1,263 of 41,186, 2.2% of the game's code by size. Fable2RE rebuilds the game as readable C++ ([direction](project-direction.md)); this page counts how far that has come.

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="images/progress-dark.svg">
  <img alt="3.1% of Lionhead's game functions are human-readable C++ (1,263 of 41,186), as of 2026-10-15" src="images/progress-light.svg" width="860">
</picture>

## Lionhead's game code

The game and engine code and its start-up initialisers: the code Lionhead wrote.

| Kind | Functions | Share | Code bytes | Share |
|---|---:|---:|---:|---:|
| Human-readable C++, reviewed | 1,206 | 2.9% | 264,308 | 2.2% |
| Human-readable C++, written by hand | 57 | 0.1% | 5,080 | 0.0% |
| Machine-translated C++, exact and tested | 38,886 | 94.4% | 11,666,772 | 95.6% |
| Recompiled only | 1,037 | 2.5% | 263,156 | 2.2% |
| **Total** | **41,186** | | **12,199,316** | |

## The whole executable

Every function of `default.xex`, by area ([scope](../research/catalog/scope.tsv)). Middleware and system libraries are not reconstructed as readable code; they are to be replaced by native PC equivalents ([roadmap](roadmap.md)).

| Area | Functions | Human-readable | Machine-translated | Recompiled only |
|---|---:|---:|---:|---:|
| Game and engine code | 32,344 | 1,263 (3.9%) | 30,044 (92.9%) | 1,037 (3.2%) |
| Start-up initialisers | 8,842 | 0 (0.0%) | 8,842 (100.0%) | 0 (0.0%) |
| Middleware libraries | 11,437 | 0 (0.0%) | 11,231 (98.2%) | 206 (1.8%) |
| System libraries | 7,059 | 0 (0.0%) | 6,435 (91.2%) | 624 (8.8%) |
| Unidentified code | 1,179 | 0 (0.0%) | 1,138 (96.5%) | 41 (3.5%) |
| **All** | **60,861** | **1,263** (2.1%) | | |

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
| 2026-10-15 | 1,263 | 3.1% | 1,206 | 57 | 38,886 | 1,037 | 5,232 |

## What is counted

- **Human-readable C++, reviewed.** A language model rewrote the lifter's exact code for the function into readable C++; it passes a strict differential check against the original on six input profiles, a review, a build and the game checks ([promoted code](promoted-code.md)).
- **Human-readable C++, written by hand.** Written by hand for this port and checked against the original ([conversion guide](conversion-guide.md)).
- **Machine-translated C++, exact and tested.** The lifter's structured C++ with real signatures and every name the dictionary knows. It is exact (the differential tester compares it with the original), but mechanical to read ([lifted code](lifted-code.md)).
- **Recompiled only.** Runs as ReXGlue's instruction-by-instruction recompilation, because no translated form of it has passed the tester yet.

Every function of the executable counts once, in its most finished form. Only files in this repository count: the catalog (`research/catalog/`), the published modules (`Fable2Recomp/promoted/`), the hand-written replacements (`Fable2Recomp/src/game/`), the verification manifest (`research/lift/verified.json.gz`) and the dictionary (`research/names/`). Work on a development machine that is not published yet (rewrites waiting for review, newer tester results) counts once it is. `python tools/progress.py` updates this page, the chart and the README; `--check` (run by the CI and by `tools/publish.py`) fails when they are out of date.
