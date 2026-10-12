# Promoted code: checking what the relaxed comparison could not see (2026-10-10)

## Question

The relaxed differential check (`tools/rewrite/check.py`, 2026-10-07) accepts a rewritten function when it makes
the same memory writes, the same calls with the arguments the callees really read (`rin`), and returns the same
value. A partial review of the promoted modules on 2026-10-08 (358 functions in 27 modules, never recorded)
returned FIX for 164 of them, most often to put back a register value the lifter's exact output leaves for its
callers ("restore ctx.r4 on return") or a register hand-over before a call. Were those real defects the checker
cannot see, or reviewer caution?

## What the checker did not compare

1. **Registers the callers read after the return.** The whole-game analysis lists them per function
   (`summaries 'outputs'`; for `CBufferedFile_SeekTo` r3, r4 and f1). The lifted callers read them back
   (`x = ctx.r4.u64` after the call). The relaxed mode compared only the native return value.
2. **The native call.** The tester entered a function through its CPU-state entry, which takes the arguments
   from `ctx` and leaves them there. Lifted code calls the native function directly: the arguments travel as C++
   parameters and their registers in `ctx` hold stale values. A rewrite that leaves r4 for its callers only by
   *not touching* `ctx.r4` therefore passed the check and still hands a stale value to a native caller. The
   lifter's exact output writes such registers back explicitly at the return (`ctx.r4.u64 = arg2;`).
3. **Arguments passed through.** A callee that only passes a register on to a call through a pointer or an
   import (summaries `fwd`, not `rin`) was never compared, so a dropped hand-over of a real pass-through
   argument went unnoticed.

## Change (tools/lift/difftest, tools/rewrite)

`run.py --relaxed --outputs` (`check.py --outputs`; `promote.py` always uses it; build directory
`difftest/build_relaxed_out`):

- the entry reads its argument registers and then overwrites them with poison values before calling the
  function (`_native_call_entry`): the state a direct call from lifted code leaves;
- after the return, the registers in `outputs` are compared (low 32 bits, like the relaxed arguments);
- at every call, a register the callee only passes on is compared when the original still holds the non-zero
  value it was entered with there (an argument passed through). A leftover temporary is not compared, and a
  zero entry value is not taken as evidence of passing through (the sparse profiles made zeros coincide).

The plain relaxed mode used by the cheap-model rewrite runner is unchanged.

`check.py` also deletes earlier `results*.txt` before a run: when the tester failed to build, the previous
run's verdicts were read back and reported as current (seen once during this work).

The review packets (`promote.py review`) gained two static flags: registers the lifted code sets for its
callers at a return that the module text does not set, and missing `ctx.fpscr` mode switches.

## Validation

- `CBufferedFile` module (13 functions): the lifter's exact output passes the new mode on profiles 0-5;
  the promoted versions fail exactly in the four functions the 2026-10-08 reviewer had fixed by putting back
  `ctx.r4` at the return (`r4 after return: 0 vs D5AD0000D5AD0004` and similar). Before the zero-value rule, a
  fifth function failed on a pass-through comparison where both values were zero by coincidence.
- Static flags over all 1,210 promoted functions: 334 functions drop a return write-back, 76 drop
  floating-point mode switches.

## Full re-check of the promoted modules

`promote.py check` over all 76 modules (profiles 0-5, the new mode; 2026-10-10 16:27-18:16, below-normal
priority while the machine was in use):

| Result | Functions |
|---|---|
| OK | 821 |
| a register callers read differs after the return | 261 |
| an argument passed through to a callee differs | 111 |
| another call argument differs | 17 |

282 of the 389 failures are functions promoted in the "cleaner" form, whose hand-overs before calls and
returns `promote.py` had dropped automatically (55% of the 514 cleaner-form functions, against 15% of the
696 kept in their written form). `drop_handovers` now keeps hand-overs that a call or a return follows.

## A second tester fault found on the way

`tools/lift/lift.py signatures()` set its cache to `{}` before loading it. In a `--relaxed` run with several
jobs, a thread that asked while another was loading got the empty table, `native_sig()` returned None, and
that batch compared no return value at all. Fixed with a lock (the table is published only when loaded). The
`--outputs` mode does not use `native_sig()` and was not affected; rewrites accepted earlier by `check.py`
with `--jobs 2` or more may not have had their return value compared, and the promoted ones among them are
re-checked in the new mode anyway.

## Consequence

The 2026-10-08 "restore on return" fixes were real defects for native callers, not caution. Promotion and the
review now use the new mode; the full re-check of the modules and the review itself are recorded in
`docs/promoted-code.md` and `Fable2Recomp/src/game/promoted/REVIEW.tsv` once done.

Open: a hand-over of a *computed* value to a callee that only passes it on (not a pass-through of the
function's own argument) is still not compared; the analysis treats imports as reading every argument
register, which makes `fwd` large. Giving imports their real argument counts would make a full `fwd`
comparison practical (whole-game analysis: overnight).
