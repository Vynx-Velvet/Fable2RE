# Promoted code: model rewrites as published source

`Fable2Recomp/src/game/promoted/` holds game functions reconstructed as readable C++, one module per class.
They are replacement code in the sense of [CONTRIBUTING](../CONTRIBUTING.md): authored for this project,
checked against the original and reviewed. Machine output that has not gone through these steps (the
lifter's files, `Fable2Recomp/rewritten/`, answers of the rewrite runners) stays local.

The repository holds them in `Fable2Recomp/promoted/`, without the game's text, and setup writes them to
`src/game/promoted/` from your own copy ([below](#without-the-games-text)), the same text byte for byte as on
the machine that published them.

**Publication state (2026-10-15): reviewed, checked and published without the game's text.** The 1,210
promoted functions (76 modules) are reviewed: 1,206 recorded OK in `REVIEW.tsv` (935 of them with a fix), 4
demoted; the re-check passes all 1,206, the build succeeds and the game checks (menu, load, play) pass
([finding](../research/findings/2026-10-15-promoted-review-recorded.md)). A module is published once every
function in it is recorded OK, re-checked, built and game-checked; `tools/validate_commit.py` refuses a module
without its review records or with names made from game text.

## Without the game's text

The lifter names some things after the game's own text (`tools/lift/readable.py`): a string constant after its
text (`str_PieceName`), a local after the constant it holds (`pieceName`), a global after the text it is built
from (`research/decomp/global_names.tsv`, written by setup). The modules keep those names, and comments and
review notes mention them. Game text stays out of the repository, so `tools/rewrite/promoted_text.py publish`
writes the published form with each such span replaced by a reference to the string's address in the image:

| Reference | Stands for |
|---|---|
| `TXT_<address>_B_` | the text part of the constant's name as the lifter writes it (`str_TXT_820E0F10_B_` is `str_` + it) |
| `TXT_<address>_W_` | the same without the lifter's 48-character limit |
| `TXT_<address>_L_` | a local named after the constant (lower camel case) |
| `TXT_<address>_R_` | the text itself |
| `TXT_<address>_G_` | the global's name |

A reference is valid inside a name, so the published form still compiles. `publish` refuses a module whose
form does not render back to exactly the same text, or that still shows text of its constants (a name a model
gave a constant by hand cannot be rendered: use the lifter's name). It records the SHA-256 of every local file in
`Fable2Recomp/promoted/manifest.tsv`.

Setup step `promoted` (`promoted_text.py render`, after `image` and `globals`, before `lift`, which leaves the
modules' functions out) writes the modules back to `src/game/promoted/` with the text from your copy and checks
each against its recorded SHA-256. A module you changed after the last render is kept (`render --force`
replaces it). `promoted_text.py check` checks the published form; `tools/publish.py` runs `publish` before it
stages anything and `check` among its checks. `src/game/promoted/` is ignored by git, and
`tools/validate_commit.py` refuses it if it is staged anyway.

## How a function gets here

1. **Rewrite.** A language model rewrites the lifter's exact code for one function into readable C++
   (`tools/rewrite/`, mostly DeepSeek `deepseek-flash` through `run_api.py`; the packet each function came
   from is in `Fable2Recomp/rewritten/manifest.tsv`, local). Input: the user's own copy, lifted locally.
2. **Differential check.** `tools/rewrite/check.py` runs the rewrite and the recompiled original on the same
   inputs (six input profiles: sparse, dense, zero, small numbers, three mixed) and compares memory writes,
   calls with their arguments and the return value
   ([relaxed mode](../research/findings/2026-10-07-difftest-wrapped-pointer-timeouts.md)). Since 2026-10-16
   `run_api.py` checks with the promotion check of step 4 and feeds its failures back to the model.
3. **Game checks.** The build with the rewrite runs the menu, save-load and play scenarios
   (`tools/autotest.py`).
4. **Promotion** (`tools/rewrite/promote.py build`). Names in effect are written into the source; comments
   quoting game text are removed; register hand-overs no callee reads are dropped; every function is checked
   again on all six profiles, in its cleaned form where that passes. Passing functions go into their class's
   module and the lifter leaves them out of its generated files from then on. Since 2026-10-10 every check in
   this step and after it is stricter than the rewrite runner's: the function is called as lifted code calls
   it (arguments natively, their registers in the CPU state stale), and it must leave the registers its
   callers read and pass its own arguments through to callees as the original does
   ([finding](../research/findings/2026-10-10-native-call-check.md)).
5. **Review** (below). A function that fails review is fixed and re-checked, or demoted
   (`promote.py demote sub_X --reason "..."`: back to the lifter, text kept locally as revoked).

What a module still depends on is generated locally from the user's copy by the lifter: class layouts
(`lifted/classes.h`), function declarations (`lifted/native_decls.h`) and `lifted/lifted.h` (published,
the vocabulary of the lifted code: `GameObject<T>`, `LOAD32`, `PushStackFrame`, `UseLiftedCode`).

## Review

`python tools/rewrite/promote.py review` writes one packet per module to `build/rewrite/review/` (local:
it contains the lifter's output): each function's module text next to the lifter's exact output, with
static flags where the two differ in callees, game addresses, depth of dependent loads, registers set for
the callers at a return, or floating-point mode switches (paths and state the differential check may not
have reached). The reviewer works through this checklist:

<!-- checklist -->
**Checklist (per function):**

1. Same behaviour as the lifter's exact output on every path: the same calls in the same order with the
   same arguments, the same memory writes, the same return value. Pay most attention to the flagged
   differences and to chains of dependent loads (`LOAD32(LOAD32(p + 8) + 4)` must not become one load).
   Arguments include the values the lifter hands over through the CPU state before a call
   (`ctx.rN.u64 = x;`): a callee may pass them on to a call through a pointer. Registers the lifter sets
   right before a return are read by callers and must be set the same way on every return path. A load
   stays on the same side of a call as in the lifter's output: the callee may write that memory, and the
   differential check cannot show it (its stand-in callees write nothing). Keep
   floating-point mode switches (`ctx.fpscr`), traps, 32-bit wraparound and signed/unsigned comparisons.
2. Names say what the code does; a name that contradicts the code is a defect (wrong is worse than none).
3. Comments are true and do not restate the code; no quoted game text, no pasted decompiler output.
4. No dead or leftover code that hides what the function does (unused variables, empty blocks left by
   removed hand-overs, casts that change nothing).

Verdict per function: OK, FIX (with the exact change) or DEMOTE (with the reason).
<!-- /checklist -->

Verdicts go to `<dir>/verdicts/<Module>.tsv` (`sub_X<TAB>OK|FIX|DEMOTE<TAB>note`, one line for every function of
every module) and fixes to `<dir>/fixes/sub_X.cpp` (the whole function, starting from the module text, ending in
its unchanged `PROMOTED_ENTRY` line). `python tools/rewrite/promote.py record --dir <dir> --reviewer <who>` applies
them: fixes are checked again (a fix that fails is reported and left out), demoted functions return to the lifter,
and `Fable2Recomp/src/game/promoted/REVIEW.tsv` (published with the modules) records every function reviewed OK
with reviewer and date. Then `promote.py check` over all modules, a build and the game checks. A module is
published when every function in it is recorded OK. `record --partial` records a review that did not reach every
function (for example when the model account ran out): the functions without a verdict get no row, and
`promoted_text.py publish` leaves each module that still has one exactly as it was published before, file and
manifest row, until a later round reviews the rest.

**Look-alike copies** (since 2026-10-19). A function that is the same code as a reviewed representative of its
look-alike group, with its own addresses, numbers and names, gets the representative's rewrite with its own values
(`tools/rewrite/copy_lookalikes.py`) and the same strict check as any rewrite. Such copies are recorded as copies
of their representative (reviewer `lookalike-copy+claude`, note `copy of sub_X ...`) after a sampled review: three
per group, each read against its own lifted text
([finding](../research/findings/2026-10-18-lookalike-functions.md)).

**Reviewing with a model, in tiers** (`tools/rewrite/review_api.py`, since 2026-10-13). A cheap model does the
bulk; a second reviewer looks only at what it lists:

```
python tools/api_keys.py set deepseek                 # once (docs/parallel-work.md#api-keys)
python tools/rewrite/review_api.py prepare            # work list from the modules as they are now
python tools/rewrite/review_api.py run --jobs 4       # DeepSeek deepseek-flash by default; restartable
python tools/rewrite/review_api.py status
python tools/rewrite/review_api.py collect            # verdicts/, fixes/, escalate.tsv
```

- `prepare` leaves out every function whose review `REVIEW.tsv` records for the text it has now (since
  2026-10-16; the digests are kept locally in `build/rewrite/promote/reviewed_texts.json`, started from the
  published modules). `collect` lists those as `RECORDED` and `record` keeps their rows, so a new round costs
  only the new or changed functions. `prepare --all` reviews everything again.
- `prepare` takes over an earlier review in the form above (default `build/rewrite/review_2026-10-10`, with
  `verified.txt` naming the verdicts a second reviewer confirmed) for functions whose module text is unchanged:
  confirmed verdicts stand and their fixes are only checked; single verdicts are verified by the model, which
  sees the earlier verdict, note and fix; the rest get a full review.
- `run --effort none|low` asks the model for less hidden reasoning, which DeepSeek bills as output
  ([API keys](parallel-work.md#api-keys)); without it the provider's default applies.
- `run` sends each chunk (up to five functions of one module) with the checklist, the static flags, the result of
  the strict check, the module text and the lifter's exact output. Every fix is checked as `record` checks it
  (`check.py --outputs`, six profiles); a failing fix, an OK for a function that fails the check, or an answer
  in the wrong form goes back to the model with the checker's line and a hint (three rounds by default).
- `collect` writes `verdicts/<Module>.tsv` and lists in `escalate.tsv` what the second reviewer must look at:
  functions the model could not settle, its demotions, its disagreements with a single earlier verdict, and one
  in ten of the functions it decided alone. It also leaves the fixes' check results where `record` reuses them.
- Then the second review of `escalate.tsv`: corrections go into `verdicts/` and `fixes/`, or into a decisions file
  that `review_api.py second DECISIONS` applies (`sub_X<TAB>OK|MODEL|FIX|DEMOTE<TAB>note`: the module text is right,
  the model is right, the reviewer's own fix in `second_fixes/sub_X.cpp`, or back to the lifter), and
  `promote.py record --dir build/rewrite/review_api --reviewer <who>`.

## Names

Modules are written with the names applied to the lifted code (`promote.py build` refuses to run while the
dictionary has unapplied changes). `tools/lift/apply_names.py` records the names the modules use before it
applies new ones and brings the modules to the new names afterwards (`promote.py sync`), renaming a module
file when its class gets a name. A field name used by several classes is not renamed automatically (the
build then reports it). A function or class without a name appears in its address form (`n_sub_8323A788`,
`C_82004098`).

## What is still left in them

`python tools/rewrite/promote.py lint` counts, per module, what a later pass should clean: register
hand-overs still needed by callees that take arguments through the CPU state, values read back from
registers, raw loads and stores where no class layout is known yet, parameters without names, calls to
functions without names, and calls through pointers. These are behaviour-preserving leftovers of the
mechanical lift, not defects; they shrink as types and names improve.
