# Review of 91 look-alike representatives, a second hand-over hole, and the unreviewed 254 (2026-10-20, evening)

## Question

What is still needed before the next large promotion (the look-alike groups of the Freebuff packets 0292-0300
and the sent-back representatives of 0308/0309), and is the rest of the promoted code sound after the morning's
finding ([the dropped hand-overs](2026-10-20-prologue-and-continue-crash.md))?

## The representatives, reviewed and corrected by agents

The 11 packets hold 91 representatives (one of them, `sub_822F6F58`, had failed the promotion check in its
Freebuff session) that stand for about 2,550 look-alikes still on the lifter's code. Eleven review agents
(Claude, one per packet; brief in `build/rewrite/review_2026-10-20/BRIEF.md`) read every answer against its
exact lifted code and the look-alike rules, corrected the answers in place, and ran the promotion check on the
packet again; eleven further agents, one per packet and without the first's notes, then tried to refute the
faithfulness of the corrected answers path by path.

| Verdict | Representatives |
|---|---:|
| FIXED in review (corrected, check passed again) | 86 |
| GOOD | 5 |
| FIX / REDO (sent back) | 0 |

Every packet's `results.txt` is OK for every function, `sub_822F6F58` included (the reviewer found the cause:
after a `ppc_trap` on the last iterator's container the lifted code still tests the node against the head and
clears the tree, which the answer skipped). The second pass raised no faithfulness doubt on any of the 91; it
raised naming notes on 9 (register names in comments, two placeholder names), which were applied, the packet
with the two renames checked again. The verdicts and notes: `build/rewrite/review_lookalikes.tsv` (local).

What the first pass corrected, as on 2026-10-18: comments that invented game meanings (handler registrars,
schedulers, attribute keys, teardown hooks) or quoted the text of string constants; names built from one
representative's string or class (`handRight`, `cFleeAgent`, `applicationName`); lifter noise left in
(`compare6`, `rotateleft32(byte, 3)`, `r6Carry`); three answers that were the lifted code renamed (rewritten as
the component lookup they are). Behaviour faults found by reading: a zero hand-over where the lifted code hands
over the span on an empty search; a 64-bit null test for a 32-bit one; a value narrowed before a call. The
originals are kept in `build/rewrite/review/originals/<packet>/`.

One function of packet 0295 (`sub_82445490`) lost its answer file after its session's check; it is not in the
review and the packet goes back to the next Freebuff session for that function alone.

## A second hole of the same kind, in the promotion step

`promote.py build` has its own "cleaner form": before the strict check it drops a register hand-over
(`ctx.rN = x;`) that no call or return follows directly. That rule has the hole found this morning in the
readable-form pass: a hand-over of a frame address or a variable that other statements separate from its call
was dropped, and the check cannot see it (its stand-in callees read nothing). Re-promoting the three functions
demoted this morning showed it: the cleaner form dropped exactly the `r5`-`r9` hand-overs before
`n_sub_82392C88` in `sub_82610E70` that the 2026-10-17 review had restored.

Measured over every promoted function against its accepted rewrite (`build/rewrite/promote/sources/`, the text
before the cleaner form; the fixed rule run on it, its register writes compared with the module's): 58 functions
in 38 modules lacked such writes, among them `sub_82175EF8` (`CPhysicsRigidBodyEntity`), which hands seven
frame addresses and three doubles to `n_sub_82D7B818`. Repair: the rule in `promote.py` now drops only a
literal or constexpr value (`plain_value`, the same rule as `readable_form.temporary`); each of the 58 was
rebuilt from its accepted rewrite with the fixed rule and the readable form, the renames made since carried
over, and verified with the strict check: 55 written, 2 were the morning's re-promoted functions already fixed,
1 (`sub_828B9788`) was a false alarm (a hand-over of a variable that only ever holds 0, with a later review fix
the rebuild would have lost) and stays as it is.

The three demoted functions are promoted again from their reviewed texts (`sub_82610E70`, `sub_82610FB0`,
`sub_827D1090`; strict check OK), so no reviewed rewrite is back on the lifter's code.

## The 254 promoted functions without a review

The second DeepSeek round of 2026-10-17 left 254 promoted functions in 24 modules without a review row when the
model account ran out. Twenty-four review agents (Claude, one per module; brief and task files under
`build/rewrite/review_2026-10-20_deepseek/`, local) read each function against its exact lifted code, wrote a
verdict and, where needed, a corrected text, and verified every correction with the strict check before handing
it over; `promote.py record` checked the 224 corrections again and wrote them into the modules.

| Verdict | Functions |
|---|---:|
| FIX, behaviour (the text did not do what the lifted code does on some path) | 109 |
| FIX, names and noise only (behaviour matched) | 115 |
| OK | 30 |
| DEMOTE | 0 |

All 254 are recorded OK in `REVIEW.tsv` (9,624 of 9,624 promoted functions now have a row; none needs attention).
What the behaviour fixes put back, by kind (a function can have several):

| Fault | Functions |
|---|---:|
| Register hand-overs dropped before a call (parameters, variables, frame addresses, values the callee passes on) | 80 |
| 64-bit values cut to 32 bits, or constants zero-extended where the lifted code sign-extends them | 38 |
| Floating-point mode switches (`fpscr.disableFlushMode`) left out | 15 |
| A field read once where the lifted code reads it again after a call | 15 |
| Carry / condition-register state not carried | 14 |
| Atomic reference-count updates (reserved load, conditional store) made plain loads and stores | 9 |

The dropped hand-overs are the same fault as the morning's and the cleaner form's, here in texts the model wrote
on 2026-10-17 before either pass existed: the strict check does not see a hand-over whose value is not an entry
argument, so the model's omissions passed too. The names-only corrections are what the 2026-10-18 review found in
the Freebuff answers: locals named from the text of string constants, vtables and page bases named as game
objects (`emptyPath`, `listSentinel`, `memoryManager`), register names (`savedR10`, `reg9`), lifter noise
(`rotateleft32`, carry arithmetic), and three functions that were the lifted code renamed. One remark to keep: in
`CFilePath` the constant `0x82007B2C` is the vtable of the find-handle holder on the stack, not a state value.

## The copy run (the same night)

`copy_lookalikes.py` over the 11 packets, strict check on every copy (about 1.5 s a copy with 4 jobs; the
whole run 75 minutes):

| | Members |
|---|---:|
| Copies that pass the strict check | 2,434 |
| Refused by the copier, a name built from the representative's own values | 40, then copied after a rename |
| Refused or wrong because of a copier fault (below) | 26, then copied after the fix |
| Refused: a literal with several values in the look-alike, a value the model worked out, a shape apart | 100 |
| Copies that fail the check | 0 |

The 40 renames: five reviewers had named a variable after the representative's callee (`tree`, `hintTree`,
`iterator`, `hintNode` next to `Tree_DestroySubtree`, `RbTree_IteratorIncrement`); the copier rightly refuses a
name made from a value the member does not share. Renamed to neutral words (`container`, `hintOwner`, `cursor`,
`hintPosition`), the packets checked again (all OK), the members copied.

The copier fault: 23 copies failed the check with one wrong call argument, a function address. The copier
aligned the representative's and the member's `constexpr` declarations by position, and the declarations are in
address order, which two look-alikes do not share: `g_82540000` (fifth of the representative) was paired with
`g_82647850` (fifth of the member), while the code's own use of the bare base was paired right. The wrong pair
only came into play where the rewrite had folded a bare base and an offset the lifted code keeps apart
(`local = g_82540000; ... local + 19848` written as `(int64_t)g_82540000 + 19848`): a whole address the lifted
code does not have, so the copier mapped its parts one by one, the base through the crossed declaration. The same
crossing made three string constants look as if they had "several values" (refused). Fix in `copy_lookalikes.py`:
declarations are left out of the alignment (every declared value is aligned where the code uses it), and a folded
base + offset is mapped as the bare base plus the number. Every copy passing the check before the fix is
unaffected (the check compares every call argument on six profiles, and these 23 were exactly the copies it
caught); the 26 copied after the fix pass it.

Promotion: 2,524 functions (91 representatives, 2,434 copies, minus one promoted earlier) in five chunks, every
one passing the strict check in both forms; the fixed cleaner form dropped 119 literal hand-overs in 46 functions
of the first chunk and nothing of any other kind.

Sampled review of the copies, as on 2026-10-19: three promoted copies per group (first, middle and last by
address: 264 copies of 89 groups; two approved groups have no copy left), each next to the member's exact lifted
text kept before apply, read by eight agents (`build/rewrite/review_lookalike_copies_2026-10-20/`): 264 OK, 0
problems. The agents diffed the copies against their siblings and the lifted texts against each other, so every
value the copier changed had to change the same way on both sides; they checked the component type ids, presence
words and bits, record words, allocation sizes, vtable slots, callee order and the hand-overs before indirect
calls. Two remarks on representatives, not copies: `sub_8264F1C8` hands `Component_HashTypeName` the owner cut
to 32 bits where the lifted code hands the whole register (passes the check: the value is an address), and the
group of `sub_832866E0` drops the literal `r9`/`r10` hand-overs before `RegisterAtExit` as the rule allows.
Recorded: the 91 representatives (reviewer `claude`) and the 2,434 copies (`lookalike-copy+claude`), so all
12,148 promoted functions have an OK row.

The first build failed on one module: the review fixes of `CSceneEntity` use the readable form's `GameStackFrame`
and the module header lacked `readable_support.h`; `promote.py record` now completes a module's includes, the
include added by hand this once.

## Bookkeeping found on the way

- `promote.py sync` (names from the dictionary into the modules) did not carry the digests of reviewed texts
  (`build/rewrite/promote/reviewed_texts.json`) over to the renamed texts, so `review_api.py prepare` counted
  2,894 functions as unreviewed where REVIEW.tsv records 254 without a row. The publish check reads REVIEW.tsv,
  so nothing wrong was published; `sync` now carries the digests.
- `tools/lift/skip.txt` gained 6 functions on 2026-10-20 (tester failures after the names re-lift) and
  `name_pass.py` the rule that field names are not taken from the model; both uncommitted until now.

## Build and game checks

The build with everything of the day (the 55 repaired, the 3 re-promoted, the 224 corrected, the 2,524 new)
compiles (after the include above) and runs the suite of five: menu OK, load OK, play OK, newgame OK, resume
OK_EXIT_CRASH, that is the resumed game plays through its check and the process crashes while closing
(0xC0000005). Two reruns of resume closed the same way. The ledger shows the same result for the two resume runs
on the afternoon build of 2026-10-20 (16:15 and 16:27, the build with the morning's repair and none of tonight's
changes): the crash at exit after a Continue is older than this promotion and stays open (the load check has
shown the same teardown crash now and then since 2026-10-15; `tools/lift/bisect_crash.py` could narrow it when
it is worth a few hours).

## What remains

- The crash while closing after a resumed game (above).
- The 100 members the copier refuses (literals the representative uses in two roles, values the model worked
  out, a shape apart): a rewrite of their own, or a representative written with distinct constants.
- One function of packet 0295 (`sub_82445490`) without an answer, and the review packets 0301-0307, both
  Freebuff's.
- Two remarks from the copy review on representatives: `sub_8264F1C8` (an address cut to 32 bits before a
  call) and the group of `sub_832866E0` (literal `r9`/`r10` hand-overs dropped before `RegisterAtExit`).
