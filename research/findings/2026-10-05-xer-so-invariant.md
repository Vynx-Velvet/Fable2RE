# XER summary-overflow bits are always 0 (2026-10-05)

## Fact

Nothing in the game sets XER[SO] or XER[OV]:

- The recompiled code (Fable2Recomp/generated) writes `ctx.xer.so` / `ctx.xer.ov` in exactly one place. That
  is a `mtxer r6` in Fable2_recomp.94.cpp (around line 70883), inside a routine that reloads the whole CPU
  state from a saved context: r14-r31, f-registers, fpscr, lr, cr, xer and ctr from offsets 136-544 of the
  structure in r4. The value it restores is whatever an earlier capture read, so it can only be non-zero if
  the bits were already set.
- No overflow-recording ("o") instruction forms occur in the game. The recompiler would emit
  `ctx.xer.so = ...` for them, and no such line exists outside that one restore.
- Threads start with XER zeroed, and the differential tester's driver also starts every test with
  `xer.so = xer.ov = 0` (difftest/driver.cpp).

So `so` and `ov` are 0 at every point of execution. An integer compare copies XER[SO] into the SO bit of its
CR field, and that bit is therefore 0 as well. Floating-point compares set CR.SO for "unordered" from their
own operands, not from XER, so this fact does not affect them.

## Use in the lifter

The lifted code treats `xer.so` / `xer.ov` as registers. A caller therefore:

- reloads them after every call that may change XER (the callee changes `xer.ca`, so the whole XER counts as
  modified);
- hands them back at its return.

These reloads are about 205,000 lines of the lifted output (`flags.so = ctx.xer.so;` / `flags.ov = ...`).

`summarize.apply_invariants` / `summarize.call_summary` remove the two bits from every function's inputs,
changes and outputs. A function's copy of `xer.so` / `xer.ov` (read once on entry) then stays valid across
calls. Nothing else changes: the bits are still read on entry and still copied into compare results.

Switch: `LIFT_XER_SO=0` turns the invariant on. While it is new, the default is off
(`summarize.XER_INVARIANT_DEFAULT = '1'`). It is switched on with a whole-game cycle (overnight rule), because
it changes the text of most functions.

The one deviation would be a restore of a context whose saved XER has SO set. Nothing in the game can create
one.
