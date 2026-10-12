# Plan: whole game as readable native C++, no compatibility layer

Goal (user, 2026-10-04): every piece of game code as human-readable C++ running natively on PC, with nothing left
of Xenia, ReXGlue or the Xbox 360 environment. This file is the phase plan and the current position; update it
when a gate is passed. Status words: *implemented* (code exists), *built*, *verified* (automated run passed).

## Priorities and scope (user, 2026-10-05)

1. Readable, clean code for the game's own code first: 32,243 functions (`research/catalog/scope.tsv`,
   category game), not the insides of Havok, Kynapse, Scaleform or the Xbox system libraries.
2. Then the layers (Phase C), one at a time.
3. End goal: self-hosted online servers in place of Xbox Live (player orbs and the other online features).

Reasons and the faster plan: 2026-10-05-scope-and-faster-plan.md.

## How every step is checked

- `tools/lift/difftest/run.py` (+ `--profile 1`): lifted function vs recompiled original on synthetic inputs.
- `tools/autotest.py --scenario menu|load`: boots the real game unattended, scripted pad input inside the
  process, snapshots (noise score, viewed by the agent), log scan. Reference = same run with `lifted_code=false`.
- `tools/lift/auto_bisect.py LO HI --scenario .. --check ..`: finds the function behind a behaviour difference.
- Builds are incremental: `tools/lift/update.ps1 -Funcs .. -Build` (chunked lifted files, per-function status).

## Phase A - the lifted build behaves like the recompiled one

Gate: menu + load + several minutes of play identical to the reference, with every function lifted.

Lifter bugs found by bisection so far (all fixed in `tools/lift/passes.py`):
1. compare dropped before an unconditional jump to code reading it (sub_82BC8DD0, menu options missing)
2. inlining moved an expression past a write to its operand after a previous inlining (sub_82B8C1C8, textures)
3. compare dropped although a jump on another condition leads to code reading it (sub_822065F0, load hang)

4. not a translation bug: hand-written hooks read standard argument registers the original callee never read
   (native renderer draw hook reads r4 of sub_8221C9C8; caller sub_8221FD60 did not hand r4 over -> terrain
   missing). Rule added to the whole-game analysis: callees in `overridden.txt` read all set-up ABI arguments
   (`summarize.hooked_extra`, ANALYSIS_VERSION 6).

How the last three were found without reading code: `auto_bisect.py` (function) -> `pass_bisect.py` (which
lifter pass / which single change; "plain translation bad" means the register hand-off) -> `LIFT_SYNC=calls,ret`
and `sync_bisect.py` (which register).

Verified 2026-10-04 04:30 (autotest `menu` and `load`, snapshots compared with the `lifted_code=false` run):
main menu, menu options, character select, Continue -> save loads -> gameplay frame with terrain, characters,
HUD. All lifted except the audio library and the functions below.

Open:
- XAudio2 library 82C40000-82CF8E10 runs recompiled (null vtable call on level load, cutscene hang when lifted)
- tester status (difftest/results/status.json): 59,472 OK, 152 mismatch, 276 time out (not compared),
  9 crash; those 437 stay recompiled, 42 more cannot be lifted at all. Each mismatch is an offline repro of a
  lifter bug (classes: register after return 73, memory 17, call arguments 25, one-sided timeout 11)
- `play` scenario (2 min of stick movement, camera, attacks, pause menu after the load) passes on the lifted
  build: no crash, hang or corruption in 2 runs (2026-10-04 05:00). Runs are not repeatable frame for frame
  (two reference runs differ as much as reference vs lifted), so this is a crash/corruption check, not an
  equivalence proof; equivalence rests on the differential tester.
- intermittent access violation when the process closes (exit code C0000005), also to be checked unlifted
- idea: compile the lifted files with locals left uninitialised and `-Wsometimes-uninitialized` as a static
  check for "value read on a path that never set it" (bug classes 1 and 3)

## Phase B - meaning: real functions, names, types

The lifted code is structured but still speaks registers and offsets. Steps, each an automatic pass over all
functions plus hand work on top, verified by Phase A's checks:
1. real signatures: arguments and return values instead of the context structure, direct calls
2. classes from the 3,501 vtables: `this` types, field offsets -> named struct fields (per-class layout files)
3. names: Lua binding map, strings/asserts, Ghidra export, propagation through call graph
4. hand refinement of subsystems (docs/conversion-guide.md), starting with the ones the mods need

### B1 design: native signatures with a residual context (decided 2026-10-04)

Measured with the current whole-game analysis: 44,732 of 60,557 functions have 12+ "input" registers and
20,954 have 12+ "outputs" - safe for keeping the context in sync, useless as signatures (arguments passed
through to calls through pointers count as inputs of everything above them).

So signatures use a second, precise set per function, and the context stays as a side channel for the rest:
- P(f) = registers f's own instructions read before writing, plus P of the functions it calls directly
  (fixpoint). Calls through pointers add nothing to P.
- f is emitted as a real function `T n_sub_X(P...)` returning r3 or f1 when the summary says callers read it;
  `F2_LIFTED(sub_X)` becomes a wrapper (context -> arguments -> context) used by recompiled code, hooks and
  calls through pointers, so those stay exactly as they are (and stay safe).
- A direct call from lifted code passes P(callee) as arguments (the local variable if it has one, else the
  context value). Everything else the conservative analysis wants handed over still goes through the context
  (flush/reload as today). In the lifter: params start "dirty" (not in the context), a native call defines
  its result register locally, flush/reload sets lose the registers passed natively.
- Sound by construction: caller and callee both derive the argument list from P(callee).
- The fallback switch stays: the native function calls the recompiled one through the context when
  lifted code is off for it (bisection keeps working).
- Later: per-vtable-slot argument sets (vtables.py) to make calls through pointers native too; shrinking the
  residual context use to nothing is the entry condition of Phase C5.

B1 status (2026-10-04 07:30): implemented. `tools/lift/signatures.py` (precise parameters: 0-4 for 54,000 of
60,557 functions, r3 result for 46,443), lift.py/emit.py emit `T n_sub_X(F2_ENV, args)` + the `F2_LIFTED`
wrapper, direct calls pass arguments (`r3_10 = n_sub_82A81620(ctx, base, r3_9, r7_15, f1, f2);`),
`tools/lift/native_gen.py` writes `lifted/native_decls.h` and weak bridges `lifted/native_bridges.N.cpp`
for callees without a lifted body, the tester links the bridges so every call still reaches its recording
stubs. First 272 functions: 268 identical in the tester, 4 loop timeouts. Whole-game run:
`tools/lift/full_cycle.ps1` (lift all, test all, profiles 2/3 for loops, drop failures, build, game checks).
Verified 2026-10-04 10:10 (`full_cycle.ps1`): whole game re-lifted in the native form; 58,934 functions pass
the tester (profiles 0, 2, 3) and are in the build; 975 stay recompiled (844 not comparable, 120 mismatch,
11 crash); game checks menu / load / play OK. Two bugs of the first version fixed on the way: callee-saved
registers must not be native parameters (a bridge would leave the caller's copy in the context changed), and
a native result counts as written by the call for liveness and argument set-up.
2026-10-04 12:25: results returned natively whenever callers read r3 (no "written on every path" condition:
a return hands back the register's current value); signatures shipped in the bundle (`sig_params`,
`sig_ret`). 58,932 functions lifted and verified, game checks OK. `return ctx.r3` left in 2,573 places
(value produced by a callee without a native result on that path).
Note for long runs: a background job is cut after 2 hours; `full_cycle.ps1` is resumable (tests only what
changed, ninja continues), so run the build and the game checks as a second job when that happens.
Names available for B3: 2,001 of 60,861 functions (1,446 Lua bindings), RTTI for 425 types (mostly Havok);
the rest must be derived (vtable/class structure, Lua API, strings, usage).
Still to do for B1: ship signatures in the bundle (`bundle.py`), vector/condition registers as parameters,
float results when r3 is also reported, per-vtable-slot signatures for calls through pointers.

### B2 status (2026-10-04 13:30): first version implemented

- `lift.py --facts` + `typefacts.py`: per function, the variables holding `this` (r3 at entry, unchanged),
  constant-offset accesses through them, callees that get `this` passed on, vtable constants stored at +0.
- `classes.py`: 3,501 classes from vtables (455 named by RTTI, mostly Havok), 653 with a constructor or
  destructor found, 221 with a base; `this` typed for 15,562 functions (12,019 vtable members / constructors,
  3,543 by propagation through calls); 18,379 fields in 2,416 classes -> `lifted/classes.h` (packed structs,
  `f2::Be<T>` members, offsets asserted) and `cache/classes.json`. 32% of all accesses through a first
  argument are in typed functions.
- `fields.py` (lifter pass): `LOAD32(this + 0x7C)` -> `self->m_7C`, `STORE32(...)` -> `F2_SET(self->m_7C, v)`,
  `auto* self = F2_OBJ(Class, r3);` at the top. Same address and value as before; first class (60 methods)
  identical in the tester.
- Gotcha: member names like `_C2` are reserved and collide with CRT macros -> padding is `pad_XX`.
- To do: constructors whose vtable constant is not stored directly (only 653 of 3,501 found), types of
  non-`this` pointers (arguments, fields that hold objects, return values), base-class layouts shared with
  derived classes, plain assignment instead of F2_SET, class and member names.

B2 correction (2026-10-04 14:30): the first member-access build crashed at boot. A call result reuses the
argument register's variable name (`r3 = n_sub_X(...)`), and that variable was still treated as `this`.
`typefacts.this_aliases` now counts values read back after calls as writes; if the argument's variable is
reused, only copies made at the top of the function are aliases. Facts and class model recomputed
(15,538 typed functions); menu / load / play OK at 16:20, 58,936 functions verified, 9,225 use `self->`.

### B3 status (2026-10-04 16:30): naming dictionary

- `research/names/{functions,classes,fields}.tsv` + README: the published dictionary (labels and one-line
  reasons, no code), keyed by address / vtable / offset for the exact default.xex.
- `tools/lift/names.py` loads it; the lifter prints dictionary names for functions (`F2_NAMED(name)` at the
  definition, plain name at calls), `classes.py` for classes and fields. Each lifted file declares the
  functions it calls, so a new name only recompiles the files that mention it.
- Pilot by hand: 58 functions (19 of them the embedded Lua 5.1 runtime, identified exactly), class
  CECSpellManager with 3 fields. About 45k tokens for 58 functions.
- `tools/naming/make_batches.py` / `merge.py`: file-based pipeline for a cheaper model (user decision
  2026-10-04: naming is not to be done with Claude usage). Round 1 with `--anchors-only` offers 913 functions.
- Catalog labels to re-check: the address named Lua_Combat_SetFlourishChargeTime looks like a shared empty
  stub; `Lua_Inventory_Set*Name` look like a settings table, not the inventory.

### B3 progress (2026-10-05 00:40)

Naming with Sonnet subagents (user request, at most 5 at a time): 3 function rounds (anchors-only:
484 / 263 / ~190 names, yield falling 54% -> 23%), then class packets (`tools/naming/make_class_batches.py`,
one class with its fields and methods per packet: ~200-270 names plus ~30 classes and ~100-150 fields per
40 batches). Dictionary: 1,935 functions, 140 classes, 501 fields. All applied (`apply_names.py`),
re-tested (tester hash ignores names, so only renamed definitions are re-tested), compiled; menu / load /
play OK, 58,936 functions lifted. Lesson: two applies at once left 752 functions inconsistent -> lock in
apply_names.py. Next: smaller classes (1,400 left) and the ~57,000 unnamed functions, lower yield.

## Queued for the next overnight cycle

Rule (user, 2026-10-04): whole-game cycles run only overnight / when the user is away. Daytime: minutes only.
Start with `powershell -ExecutionPolicy Bypass -File tools/lift/full_cycle.ps1` (resumable, below-normal priority).

- (nothing queued. The one-time recompile ran on the user's request: finished 2026-10-04 21:02, menu / load /
  play OK, no crash on closing in these three runs. Class, field and function renames are incremental now.)
- Names merged from the naming model: `python tools/lift/apply_names.py` then `update.ps1 -Build`.
- (add lifter changes here as they are prepared and spot-checked during the day)
- 2026-10-05: XER SO/OV invariant (2026-10-05-xer-so-invariant.md). Set `XER_INVARIANT_DEFAULT = '0'` in
  tools/lift/summarize.py, then run full_cycle.ps1. It removes about 205k reload lines; spot-checked on 3
  functions (text only).
- 2026-10-05: wrapper rename `F2_LIFTED` -> `CPU_STATE_ENTRY` and chunk header `LIFTED_FILE_INDEX`:
  `python tools/lift/patches/2026-10-05-cpu-state-entry.py` before the cycle (applied; the one-off patch scripts
  were removed on 2026-10-12). The tools already accept both
  spellings, and the hash treats them as one (no re-test), but every chunk recompiles.
- 2026-10-05: global string objects named in the readable text (`research/names/globals.tsv`, read by
  readable.py; `g_83498350` becomes `g_HeroSave`). Names of declared constants only, so no re-test.
- 2026-10-05: inputs split into real reads and forwarded arguments (summarize.py, ANALYSIS_VERSION 7; the new
  cache/summaries.pkl is already computed, the old one is cache/summaries.before_fwd.pkl). About 11% fewer
  hand-over lines on a 447-function sample, 441 identical in the tester and 6 timeouts. Changes the text of
  most functions, so the cycle re-tests nearly everything.
- Not queued: class-type propagation (`LIFT_TYPES=1`). It is implemented but adds little (see
  2026-10-05-scope-and-faster-plan.md), and structural inference replaces it.
- Done during the day (no cycle needed): the test hash ignores variable names, and all results were migrated.
  Renames now re-test only functions whose code changed.

## Phase C - remove the layers (each replaced part verified against the reference run)

1. audio: native mixer instead of the recompiled XAudio2 library (also removes the Phase A audio exception)
2. graphics: game code calls the native renderer directly instead of writing Xbox command buffers
3. kernel/XAM imports: files, threads, sync, input, saves -> direct Windows/C++ calls
4. memory: host pointers and little-endian data instead of the 4 GB big-endian guest space. Needs Phase B
   types for every structure and endian conversion in the asset loaders; this is the last layer.
5. drop PPCContext and the ReXGlue runtime from the link.

## Position

2026-10-04: Phase A. Automated test loop in place; menu and save load verified against the reference.
Tester mismatches left: ~120, mostly artefacts (exits the compiler knew never return; clock readers; NaN
payloads); 4 typing bugs. 2026-10-04 07:30: Phase B1 (native signatures) implemented, whole-game cycle running.

2026-10-05 07:40: the whole game is lifted in the readable form (readable.py): game-term variable names, no
F2_ macros in function bodies. 58,909 functions are lifted, and 992 problem functions stay recompiled (the
same count as before the readable form). Dictionary: 2,757 functions, 243 classes, 777 fields, 4,100 locals
(locals keyed by register variable via cache/varmap). The menu, save-load and play checks pass on this build.
Fixes and the remaining questions are in 2026-10-05-readable-cycle-regressions.md.
Next steps:
- import the catalog's Lua binding names (about 1,450) once they are checked;
- further function rounds after names apply (the yield is down to about 2-5 per batch);
- fewer residual ctx syncs;
- the F2_LIFTED wrapper macro;
- the exit crash.
