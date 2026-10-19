# Look-alike functions: converting repeated code by copying one rewrite (2026-10-18)

## Question

A large share of the game's unconverted functions are the same code with different addresses, numbers and
names (compiler-generated destructors, template instances, start-up initialisers). Can one readable rewrite
per group be carried over to the rest mechanically, so that a model writes one function and the project gains
many, and what stands in the way?

## Measurement

Grouping: every lifted Lionhead function's text with its own name, the functions it calls, classes, fields,
globals, strings, labels, numbers and every identifier that appears in fewer than 200 functions abstracted
(keywords, types, the memory macros and common callees stay; prototype `shapes3.py`, four minutes for the whole
game, output in `build/rewrite/shapes/`). Two functions in one group differ only in the abstracted values.

| Area | Groups (2+ unconverted) | Functions | Of all game functions | Code bytes | Of the game's code |
|---|---:|---:|---:|---:|---:|
| Game and engine code | 1,405 | 8,050 | 19.5% | 1,619,236 | 13.3% |
| Start-up initialisers | 172 | 6,303 | 15.3% | 275,584 | 2.3% |
| **Both** | **1,577** | **14,353** | **34.8%** | **1,894,820** | **15.5%** |
| of them in groups of 10 or more | 148 | 10,176 | 24.7% | 1,173,396 | 9.6% |

(Of 41,186 game functions and 12,199,316 bytes; converted on 2026-10-17: 1,498, 3.6%.) A first grouping that
left names and named locals in the text found 12,208 (the 2026-10-17 estimate, 11,567, also counted that way):
the flag getters, for example, each have a name of their own and fell into groups of one.

What the big groups are:

- Start-up initialisers: global strings. 2,322 functions each release one global string at shut-down
  (`CCharString_ReleaseAndDecGlobalCountA`); groups of 591, 583, 295, 175, 140, 131, 110 ... each construct one
  (`CCharString_ConstructFromCStr`) and register its release for the exit. The readable form is one or two
  calls each: many functions, little code (2.3% of the bytes).
- Game code: Lua method registrations (five groups, about 900 functions of about 227 lines, one per C++ method
  bound for the scripts), deleting destructors (265: destructor, then free when flag 1 is set), functions that
  return a constant (225), empty functions (171), flag-bit getters, and about 1,400 smaller groups.

Functions already converted are no longer in the lifted files (promoted into modules), so their look-alikes
were found through the lifted text the packets keep: with the first grouping, 929 unconverted look-alikes of 31
promoted functions (groups of 280 empty functions, 265 deleting destructors, 74, 60, 54, ...). Hardly any other
look-alike has a converted member: packets were made per class, and look-alikes are in other classes.

## Copying (prototype)

`copier.py` (scratch prototype): the representative's lifted text and the look-alike's are aligned token by
token, which maps every value of the representative to the look-alike's; the rewrite gets the look-alike's
value wherever it uses one of the representative's (numbers in either spelling, names, the function's own name
also when it was renamed after the conversion), the look-alike's own `constexpr` lines (with their string
comments) and none of the representative's comments. A value that maps to two different values (a number used
in two roles of which only one changes) is ambiguous: such a rewrite is not copied. Each copy then takes the
promotion check (`check.py --outputs`, profiles 0-5, `--jobs 4`), like every model answer.

| Trial | Look-alikes | Copied | Promotion check |
|---|---:|---:|---|
| 3 accepted answers (Freebuff packets 0221, 0223) | 29 | 29 | 29 OK (142 s) |
| 31 promoted, reviewed functions | 929 | 917 (5 ambiguous numbers, 7 missing data) | 743 OK, 174 fail (1,673 s) |

The 917 by what the copy contains:

| Copy | Copies | Check |
|---|---:|---|
| Only names from its own lifted text | 719 | 719 OK |
| Also a parameter name with the representative's class in it (`targetingPlayerAddr`) | 24 | 24 OK |
| Fields read through the representative's class (`GameObject<CECTargetingPlayer>`, introduced by the model) | 140 | 140 fail (other offsets) |
| A call under the callee's name given after the conversion (the lifted text has `n_sub_X`) | 34 | 34 fail (call not mapped) |

Every failure has one of two causes, and the check caught every one. A copy whose rewrite uses only names that
its lifted text has is right every time in this trial.

## What stands in the way

- Names from the representative's class. The look-alikes are almost never in the same class (of the 929: 1 in
  the same class, 491 in another, 437 in no known class). Typed field access through the representative's class
  fails the check (the field offsets differ) or, where an offset happens to match, would be a wrong type the
  check cannot see. Parameter names with the class in them pass and mislead. Names that fit only the
  representative without its class in them (`screen`, `elementBuilder`) are not found by the audit at all.
- Callees named after the representative was converted: the copier has to translate names through the naming
  dictionary (`research/names/functions.tsv`) to addresses before mapping.
- Copying with the improved grouping has to use the same tokens (every identifier), or values the grouping
  abstracted stay the representative's.
- Checking time: 917 copies in 93 test programs took 28 minutes with four jobs (about 1.8 s per function): all
  14,353 would be about seven hours, an overnight run.

For new groups the class problem is avoided at the source: the representative's packet says that the code is
shared by N functions in these classes and that names and field access must fit all of them (raw `LOAD`/
`STORE` where the classes differ). For copies of existing rewrites: names translated through the dictionary,
class words in names replaced by the look-alike's class or a neutral word, typed access through another class
turned back into `LOAD`/`STORE` at the field's offset (or such copies left to their own conversion).

## Pipeline

1. `tools/rewrite/lookalikes.py` (done 2026-10-18): the groups (lifted files plus the packets' lifted text of
   converted functions) in `build/rewrite/lookalikes.json`; 1,592 groups, 14,374 unconverted look-alikes (a group
   can mix game and start-up code, so the per-area counts differ slightly from the table above).
2. `make_packets.py --representatives` (done 2026-10-18): one function per group of ten or more without a
   converted member, largest groups first, at the front of the queue, with extra rules (keep the lifted code's
   numbers and callee names, names by role, no class types or `// name:` lines; packets leave out the class line
   and inferred types). First round: 129 representatives in 15 packets (0286-0300) for 129 groups, 8,624
   functions, 1,122,812 bytes (20.9% of game functions, 9.2% of the code). Converted like any packet (Freebuff
   sessions, `run_api.py`).
3. `tools/rewrite/copy_lookalikes.py` (done 2026-10-18): the copies of the representatives a review approved
   (GOOD, MINOR or FIXED in `build/rewrite/review_lookalikes.tsv`), checked like answers (`check.py --dir`,
   `--outputs`, profiles 0-5) in batches of 150, between which an agent session's checks get their turn; the OK
   copies collect in `build/rewrite/answers/copies_<packet>/`, which `apply.py` takes like any answer
   directory, and `copies.tsv` there gives each member's outcome. Beyond the prototype: a whole address
   (`g_820A0000 + 1148`) maps as one value (one 64 KiB page base of the representative can be two bases of a
   member, while the address maps to one); a number with several values in the member takes the value of the
   lifted place whose surrounding code it has (places matched clearly are claimed first, a number whose code
   changed takes what the unclaimed places agree on); the member's own constexpr, `UseLiftedCode` and
   `LiftedFrame` lines; refusals for a number the lifted code does not have (a worked-out constant), a class
   type or field it does not have, and a name made from one of the representative's own values.
4. Review (done 2026-10-19): a copy differs from its reviewed representative only in values the check verifies,
   so it is recorded as a copy of its representative (`REVIEW.tsv` reviewer `lookalike-copy+claude`, note
   `copy of sub_X ...`) after the strict check and a sampled review: three promoted copies per group (first,
   middle and last by address), each read against its own lifted text by a Claude review agent. Reviewing every
   copy like a model answer would cost about what the 2026-10-17 review cost per function (USD 2 for 254) times
   14,000. The progress page counts copies in their own sentence.

## First representatives (Freebuff, 2026-10-18)

Freebuff (GLM 5.3, agent sessions) wrote packets 0286-0288 in about 25 minutes each: 27 representatives
whose groups hold 6,685 functions, all passing the promotion check. Three Claude review agents read them like
the earlier round (`2026-10-18-freebuff-review.md`), each with the lifted code of three other members of every
group (`build/rewrite/review/<packet>_siblings.md`) to judge the copies too.

| Verdict | Representatives | Functions in their groups |
|---|---:|---:|
| GOOD | 3 | 2,634 |
| MINOR | 7 | 735 |
| FIXED (comments and names fixed in review, checked again) | 8 | 1,992 |
| FIX (a code change) | 6 | 1,065 |
| REDO | 3 | 259 |

The 18 approved representatives stand for 5,361 functions. What review found:

- Static initialisers (12 representatives, 2,462 functions): exact code, invented comments ("key string", "class
  table", "look-alike family"). `n_sub_82CA3700` is atexit (`-(n_sub_82CA35F8(f) == 0)`) and the function it
  gets releases the global constructed just before. Fixed in review; the copier drops comments anyway.
- Lua binders (4 representatives, 846 functions): the same unfaithful path in all four. When the second
  allocation fails, the lifted code has already set the userdata object to the first one; the answers set it
  only on success. Uint64 allocation results narrowed to 32 bits.
- Two representatives (219 functions) drop a store into a record on the stack whose address goes to a call.
  The checker cannot see it: the tester leaves the function's own stack frames out of the memory comparison
  (`Recorded`, `tools/lift/difftest/driver.cpp`) and the stand-in callees read nothing. A text check (every
  lifted `STORE(stack + K)` offset in the answer) is not precise enough: of 633 accepted answers with stack
  stores, 64 lack such an offset as text, and the first one looked at stores through a named address
  (`tempHandle + 4`) instead. The fix belongs in the tester: at each call, compare the bytes behind every
  argument that points into the caller's frame.
- Component lookups (3 representatives, 259 functions): the lifted code renamed (flag machinery, rotates,
  register-named variables), sent back as REDO.

The 9 FIX and REDO representatives went back in `lookalike_review` packets at the front of the queue, with the
look-alike rules and the review notes; their answers are revoked. `RULES.md` gained the static initialiser
pattern, the presence-bit formula of the component lookup (bit N % 32 of the word at +36 + 4 * (N / 32),
checked on types 49 and 87), the goto rule for values set before a call that can fail, uint64 values, more
lifter noise and the stack-frame gap.

The next three packets (0289-0291, 27 representatives, 874 functions) went the same way: 19 approved (624
functions: 4 GOOD, 3 MINOR, 12 FIXED, comments and names fixed in review), 8 sent back (250 functions) in packet
0309: component lookups that kept the lifter's flag machinery (readability only, behaviour right), and three
answers that narrow a 64-bit value or widen a 32-bit null test. In all, 37 of 54 representatives are approved,
for 5,985 functions.

Copier trial on all 27 representatives (copies written, not checked): 6,655 of the 6,658 other members copied;
3 refused (a number the surrounding code does not settle, in a REDO representative). The value-only mapping of
the prototype refused 730 of them (page bases and the small numbers 4 and 8 with several values; in the Lua
binders the 16-byte object comes in two layouts). Checked trial, four members per representative: 107 of 107
copies OK.

## First copies promoted (2026-10-18/19)

The 37 approved representatives of packets 0286-0291 and their copies: 5,900 copies made and checked (strict
check, batches of 150, four jobs, about an hour in all), 0 failures; 48 members refused (30 of them in the
`sub_82C021B8` group, whose representative passes its two arguments in the order of the minority). `apply.py`
took all 5,937 into the lifted chunks, `promote.py build` (chunks of 600) checked both forms again: 5,937 pass
on every profile, all promoted, into the class modules of their functions or, without a class, into
`free_functions` and the modules of the start-up and shut-down areas (`startup_area_<page>`,
`shutdown_area_<page>`, from the game-static ranges of `scope.py`). The promotion was stopped once for low
memory (the machine, not the job: other programs held most of it) and resumed where it was.

Sampled review: 108 copies of 36 groups (one approved group has no copy left: all its members were refused),
four Claude review agents, each copy against its own lifted text (behaviour on every path, the checker's blind
spots included; every value its own; names; the entry lines; comments): 108 OK, 0 MINOR, 0 WRONG. Notes:

- The lifter names a 64 KiB page base after the string that happens to sit at it (`str_...` for
  `0x820B0000`), also where the code reaches other strings at large offsets from it. Lifter naming, in the
  representative and the copies' own lifted text alike; a fix belongs in `tools/lift/readable.py`.
- The string-release loops (`sub_832A2308` group, 28 functions) leave out the lifted `ctx.xer.ca = flags.ca`
  before each call: the carry bit is not preserved across calls on PowerPC, so no callee reads it.

Recorded: 37 representatives (reviewer `claude`) and 5,900 copies (`lookalike-copy+claude`), with
`promote.py record --partial`: 7,378 of 7,632 promoted functions recorded OK (the other 254 wait for the review
of the 2026-10-17 round).

Build and game checks: `update.ps1 -Build` (no lifted function needed a test again; about half an hour), then
`autotest.py --suite`: menu OK, load OK but crashed while closing (0xC0000005), play OK, no critical log lines.
Two more load runs closed cleanly. The ledger has one earlier teardown crash in 15 runs (play, 2026-10-15,
before these functions), so this one is counted as the known intermittent teardown fault; the shut-down
functions among the copies run exactly then, so a repeated crash while closing would point at them first.

Estimates (not yet run): the 148 groups of 10 or more need 148 rewrites (about ten Freebuff hours, or about
USD 2 of DeepSeek) for up to 10,176 functions; all 1,577 groups need 1,577 rewrites for up to 14,353. The 743
copies that passed are a first batch now; with the two fixes above, most of the other 174 should follow.
