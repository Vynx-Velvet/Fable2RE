# Conversion progress

<!-- written by tools/progress.py from tracked files: do not edit by hand -->

As of **2026-10-20**, **15.2%** of Lionhead's game functions are human-readable C++ in this repository (readable code with every name): 6,274 of 41,186, 2.2% of the game's code by size. Another 1,266 are readable code whose names are still to give, and 1,884 are rewrites that behave exactly like the original but still work through the CPU registers. Fable2RE rebuilds the game as readable C++ ([direction](project-direction.md)); this page counts how far that has come.

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="images/progress-dark.svg">
  <img alt="15.2% of Lionhead's game functions are readable C++ with every name (6,274 of 41,186), as of 2026-10-20" src="images/progress-light.svg" width="860">
</picture>

## Lionhead's game code

The game and engine code and its start-up initialisers: the code Lionhead wrote.

| Kind | Functions | Share | Code bytes | Share |
|---|---:|---:|---:|---:|
| Readable C++ with every name | 6,217 | 15.1% | 265,224 | 2.2% |
| Readable C++, written by hand | 57 | 0.1% | 5,080 | 0.0% |
| Readable C++, names still to do | 1,266 | 3.1% | 39,484 | 0.3% |
| Rewritten, still at machine level | 1,884 | 4.6% | 372,380 | 3.1% |
| Machine-translated C++, exact and tested | 30,470 | 74.0% | 11,193,272 | 91.8% |
| Recompiled only | 1,292 | 3.1% | 323,876 | 2.7% |
| **Total** | **41,186** | | **12,199,316** | |

Of the 9,367 reviewed rewrites, 5,900 are look-alikes that carry the reviewed rewrite of their group's representative with their own values (see what is counted, below).

## What the rewrites still need

Each reviewed rewrite that is not readable C++ with every name yet, by what it still has (`python tools/rewrite/readability.py`; a function can have several):

| Still has | Functions | Step that removes it |
|---|---:|---|
| address | 2,199 | naming (the global) |
| cpu state | 1,884 | readable form: values passed as arguments, not through the CPU registers |
| field offset | 1,743 | naming (the field, in the class model) |
| stack frame | 1,491 | readable form: the frame bookkeeping in the generated entry, not in the body |
| unnamed callee | 878 | naming (the callee) |
| machine variable name | 510 | naming (variables and parameters) |
| unnamed function | 492 | naming |
| placeholder name | 143 |  |

## The whole executable

Every function of `default.xex`, by area ([scope](../research/catalog/scope.tsv)). Middleware and system libraries are not reconstructed as readable code; they are to be replaced by native PC equivalents ([roadmap](roadmap.md)).

| Area | Functions | Human-readable | Names to do | Machine-level rewrite | Machine-translated | Recompiled only |
|---|---:|---:|---:|---:|---:|---:|
| Game and engine code | 32,344 | 417 (1.3%) | 506 (1.6%) | 1,378 (4.3%) | 28,751 (88.9%) | 1,292 (4.0%) |
| Start-up initialisers | 8,842 | 5,857 (66.2%) | 760 (8.6%) | 506 (5.7%) | 1,719 (19.4%) | 0 (0.0%) |
| Middleware libraries | 11,437 | 0 (0.0%) | 0 (0.0%) | 0 (0.0%) | 11,231 (98.2%) | 206 (1.8%) |
| System libraries | 7,059 | 0 (0.0%) | 0 (0.0%) | 0 (0.0%) | 6,434 (91.1%) | 625 (8.9%) |
| Unidentified code | 1,179 | 0 (0.0%) | 0 (0.0%) | 0 (0.0%) | 1,138 (96.5%) | 41 (3.5%) |
| **All** | **60,861** | **6,274** (10.3%) | | | | |

## Names

The shared naming dictionary ([research/names](../research/names/README.md)) that every translation and every readable module uses.

| Names | Count |
|---|---:|
| Game functions with a name | 9,000 (21.9%) |
| Function names | 9,950 |
| Class names | 487 |
| Field names | 940 |
| Local variable names | 8,455 |

## History

A row for every day the numbers changed in this repository (rows before 2026-10-19 measured again with the readability levels of their published modules).

| Date | Human-readable | Share | Names to do | Machine-level rewrite | By hand | Machine-translated | Recompiled only | Named in the dictionary |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| 2026-10-20 | 6,274 | 15.2% | 1,266 | 1,884 | 57 | 30,470 | 1,292 | 9,000 |
| 2026-10-19 | 6,274 | 15.2% | 1,268 | 1,885 | 57 | 30,722 | 1,037 | 9,000 |
| 2026-10-17 | 71 | 0.2% | 133 | 1,294 | 57 | 38,651 | 1,037 | 5,232 |
| 2026-10-15 | 71 | 0.2% | 121 | 1,071 | 57 | 38,886 | 1,037 | 5,232 |

## What is counted

- **Readable C++ with every name.** A language model rewrote the lifter's exact code for the function; it passes a strict differential check against the original on six input profiles, a review, a build and the game checks ([promoted code](promoted-code.md)). A look-alike (code the same as another function's apart from its addresses, numbers and callees) can instead carry its group representative's reviewed rewrite with its own values ([look-alikes](../research/findings/2026-10-18-lookalike-functions.md)). Its level is measured by `tools/rewrite/readability.py` on the published text: plain C++ (no CPU registers or stack-frame bookkeeping in its body) in which every name says what it is: the function, the functions it calls, globals, variables, parameters and fields (no `n_sub_82CA3700`, `g_832A0000 + 12536`, `arg1`, `LOAD32(self + 144)` or `self->m_1C`).
- **Readable C++, written by hand.** Written by hand for this port and checked against the original ([conversion guide](conversion-guide.md)).
- **Readable C++, names still to do.** A language model rewrote the lifter's exact code for the function; it passes a strict differential check against the original on six input profiles, a review, a build and the game checks ([promoted code](promoted-code.md)). A look-alike (code the same as another function's apart from its addresses, numbers and callees) can instead carry its group representative's reviewed rewrite with its own values ([look-alikes](../research/findings/2026-10-18-lookalike-functions.md)). Its level is measured by `tools/rewrite/readability.py` on the published text: plain C++ without CPU registers or stack-frame bookkeeping, but with names still to give (the function, its callees, globals, variables or fields still carry addresses or the lifter's names). Naming them is the next step.
- **Rewritten, still at machine level.** A language model rewrote the lifter's exact code for the function; it passes a strict differential check against the original on six input profiles, a review, a build and the game checks ([promoted code](promoted-code.md)). A look-alike (code the same as another function's apart from its addresses, numbers and callees) can instead carry its group representative's reviewed rewrite with its own values ([look-alikes](../research/findings/2026-10-18-lookalike-functions.md)). Its level is measured by `tools/rewrite/readability.py` on the published text: its body still hands values to and from the recompiled code through the CPU registers (`ctx.r3`, `ctx.f1`, ...) or keeps the stack-frame bookkeeping: checked and reviewed for behaviour, but still at the level of the machine.
- **Machine-translated C++, exact and tested.** The lifter's structured C++ with real signatures and every name the dictionary knows. It is exact (the differential tester compares it with the original), but mechanical to read ([lifted code](lifted-code.md)).
- **Recompiled only.** Runs as ReXGlue's instruction-by-instruction recompilation, because no translated form of it has passed the tester yet.

Every function of the executable counts once, in its most finished form. Only files in this repository count: the catalog (`research/catalog/`), the published modules (`Fable2Recomp/promoted/`), the hand-written replacements (`Fable2Recomp/src/game/`), the verification manifest (`research/lift/verified.json.gz`) and the dictionary (`research/names/`). Work on a development machine that is not published yet (rewrites waiting for review, newer tester results) counts once it is. `python tools/progress.py` updates this page, the chart and the README; `--check` (run by the CI and by `tools/publish.py`) fails when they are out of date.
