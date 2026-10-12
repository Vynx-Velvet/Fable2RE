# Readable-pass whole-game cycle: regressions and fixes (2026-10-05)

The overnight cycle (tools/lift/full_cycle.ps1, log build/full_cycle_readable.log) lifted all 59,909 functions
with the readable pass (tools/lift/readable.py) and the context-sync reduction (passes.drop_redundant_sync)
for the first time. After 13k tested functions, 68 were new mismatches. None of them was on the earlier skip list.

## Cause 1: a variable written by a macro statement kept counting as "already in the context" (48 of 68)

`drop_redundant_sync` tracks which context registers already hold which variable. It forgot the pairing on
an assignment (`x = ...`), but not on other statements that write a variable. The vector macros are such
statements: `SET_V8(v1, perm(...))` writes `v1` through a macro call. The flush `ctx.v1 = v1` before the next
call was then dropped as redundant, so the callee saw the old vector (example: sub_821A5080, second call to
sub_822B3D70).

Fix (passes.py): a non-assignment statement makes every variable it mentions unknown. It clears everything
when it touches `ctx` itself, except a call, whose context effects come from the callee summary. An `asm` item
now clears the state as well. With the fix, 48 of the 68 lift differently. They re-test in the next
incremental round.

## The other 20

- 13 change with the sync pass only by dead reloads that nothing reads (`r5_12 = ctx.r5.u64;` and similar).
  The pass cannot have changed their behaviour. Some report "timeout in one version only" or callee-saved
  registers after a tail call. They get re-tested on their own; if they still differ, the tester is the next
  suspect, not the lifter.
- 7 have the same text with or without the pass. The readable rewrite (copy propagation in readable._tidy) is
  the next candidate. Until it is understood, make_skip keeps them recompiled.

## Cause 2: the readable text did not compile (865 functions marked BUILD FAILED)

The tester compiles 128 functions per unit, so one bad function marks the whole unit as failed. Seven units
failed, and the causes were few:

- **Local named `frame`.** A local got the name `frame` from a callee and collided with `LiftedFrame frame`.
- **Object variable named after its class.** For `hkp3AxisSweep* hkp3AxisSweep = GameObject<hkp3AxisSweep>(...)`,
  the object name derived from an RTTI class name was the class name itself.
- **`stderr` as a local name.** It is a C runtime macro.
- **Copy-propagation chain in `_tidy`.** `x -> local75` and `local75 -> arg1` were both accepted in one round.
  Substitution is a single pass, so `x` became the removed `local75`, which was then undeclared.

Fixes (readable.py):

- Every identifier already in the code (types, functions, fields, macros) and every helper the rewrite adds
  counts as taken.
- An object name that equals a taken name gets `Object` appended.
- C runtime and Windows header macro names are reserved.
- `_tidy` skips a copy whose target is already another copy's source in the same round.

After re-lifting the 865 functions, none failed to build and 30 have real problems (mismatches and timeouts).

## Result of the second cycle (04:02-05:05)

The second cycle (build/full_cycle_readable2.log, UTF-16) carried both fixes and the merged names (2,420
functions, 242 classes, 777 fields at the time).

- Changed functions tested: 2,420, with 66 problems.
- Profile re-tests: 124 more functions compared, with 2 problems.
- Skip list: 991 problem functions, back to the ~990 baseline before the readable pass.

The whole game is now in the readable form with no net loss of lifted functions.

The tester (difftest/run.py) now halves a batch that fails to compile until the failing function is found. Before
this change, one bad function marked all 128 in its unit BUILD FAILED.

## Main build and game checks (05:05-07:20)

- **Build failed: missing struct definitions.** chunks.structs_for found a chunk's classes only through
  `F2_OBJ(Class, ...)`, but readable chunks write `GameObject<Class>(...)`, so they carried no struct
  definitions. The tester includes the whole classes.h and never noticed. Fixed (both forms).
- **Build failed: prototype names out of step.** 337 function names were merged during the cycle. The drop
  step then wrote prototypes under the new names while the lifted text still used the old ones.
  Rule: no dictionary changes while a cycle or update runs.
- **Load and play crashed: null function call from 0x82C6AB4C.** auto_bisect found sub_82B71388 in 16 runs. It
  makes a dynamic stack allocation (alloca_probe, then `stwux r1`). The readable pass dropped every
  `r1 = ea;` as if it were part of a fixed PushStackFrame, so the stack pointer kept its old value. Fix: only
  the link store and stack update right after a recognised `ea = -N + r1` are folded; any other frame change
  stays (`stack = frameAddr;`). The differential test had passed it, because its inputs never took that path
  in a way that showed.
- The menu check passed on the build with names applied.

## Readable-text cleanups made at the same time

- `f2_entry_vN` (saved on entry and restored on return, 266 functions) became `savedVN`.
- Parameters the body keeps in a register-typed variable were printed as `f2_in`. They are now `floatArg2`,
  and the register variable is `floatArg2Reg` (24 functions).
- A function whose own address is also a constant in its body kept a raw `F2_NATIVE_ENTER`, because the
  constant substitution ran first. That line is now exempt from the substitution.

## Local-variable names in the dictionary

- readable.rewrite records which register variable each readable name stands for (readable.VARMAP).
- lift.py writes this per generated file to tools/lift/cache/varmap/<idx>.json.
- research/names/locals.tsv (function, variable, name, confidence, basis) is keyed by the register variable.
  A name therefore stays attached when the mechanical numbering (local1, local2, ...) shifts.
- merge.py accepts `L <function> <variable as shown> <new name> ...` answer lines. apply_names.py re-lifts only
  the functions whose locals changed.
- `make_batches.py --locals` offers named functions that still have generic variables.
