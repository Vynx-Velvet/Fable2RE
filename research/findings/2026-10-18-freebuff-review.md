# Review of the first Freebuff rewrites (2026-10-18)

## Question

The first Freebuff agent sessions (2026-10-17/18, packets 0214-0223) left 90 rewrites that all pass the
promotion check (`agent_check.py`: `check.py --outputs`, profiles 0-5, and the `NOT REWRITTEN` guard). How good
are they where the check cannot look: paths the test inputs never reach, names, comments, game text?

## Method

Five review agents (Claude), two packets each, read every answer against its lifted code (the packet's
"Lifted (exact)" section) and judged: faithfulness the check cannot see (traps, loads across calls, load
chains, rarely taken branches, return values, register hand-overs), readability, names and comments, game
text. Verdicts: GOOD, MINOR (faithful, small issues), FIX (a concrete change), REDO (not a real rewrite, or
unfaithful). Four of the behaviour findings were checked by hand against the lifted code; all four were right.
The verdicts with their notes: `build/rewrite/review_freebuff_2026-10-18.tsv` (local).

## Results

| Packet | GOOD | MINOR | FIX | REDO |
|---|---:|---:|---:|---:|
| 0214_CECSwimming | 3 | 2 | 4 | 0 |
| 0215_CECCreature | 2 | 2 | 5 | 0 |
| 0216_CECAIBrain | 1 | 5 | 3 | 0 |
| 0217_CBufferedReadStream | 1 | 1 | 5 | 2 |
| 0218_CLookAtComponent | 1 | 2 | 3 | 3 |
| 0219_CECExperience | 1 | 2 | 6 | 0 |
| 0220_CECExperienceOrb | 0 | 1 | 4 | 4 |
| 0221_CECAugmentable | 1 | 4 | 3 | 1 |
| 0222_CLogbookMenuScreen | 0 | 3 | 5 | 1 |
| 0223_CPayFineScreen | 0 | 3 | 6 | 0 |
| **All 90** | **10** | **25** | **44** | **11** |

21 answers do something other than the lifted code on a path the check does not run. The kinds:

- A search's exact-match exit without the flag the lifted code sets before its `goto` (four functions of one
  class), or a "key greater" exit that skips the end-entry fallback. The test memory never holds the key.
- Early exits: a `goto` that returns turned into a fall-through (extra calls), a return without the epilogue
  (`ctx.r1` left 192 bytes low for the recompiled caller), a dropped call on a branch for one state value.
- Return values: the last call's result on a path not returned (three functions).
- Loads moved across calls: a field or a whole global pointer chain the lifted code reads again after a call,
  reused from before it. The stand-in callees write no memory, so the check cannot see it.
- Register hand-overs moved across their call, missing on a restructured path (`ctx.r1`, `ctx.r8`), or added.
- One trap condition simplified wrongly; a `LOAD64` value passed through `uint32_t` before its `STORE64`; a
  stack slot's second word not stored; one collapsed load chain inside a call argument; signedness and width
  of comparisons changed.

Readability and names, in most answers: invented game meanings in names and comments (shops, trading, crime,
tickets, flight, speed) that the code does not show and that other functions of the same class contradict;
names and comments built from the game's text (string constants, also strings only Ghidra shows); typed field
access the lifted code had turned back into raw `LOAD`/`STORE`; vtables taken for state values; lifter noise
left (flag and register machinery, `clz` idioms, register-named variables); three answers that are the lifted
code renamed (the length and all gotos kept). The two functions the model spent three hours on are exact but no
more readable than the lifted code.

One gap outside the answers: the publish step (`promoted_text.py`, `DISTINCT = 8`) replaces a game string
shorter than eight characters only where it is used as a name, so a comment quoting a short string would be
published.

## Changes

- `tools/rewrite/RULES.md`: names and comments only from what the code shows (callees, classes, `g_` names,
  `research/names`), otherwise names by place; no game text in names or comments; vtable stores; hand-overs
  exactly as lifted or dropped; loads after calls read again; every path of a restructured `goto` (search
  exits, early returns, return values, the epilogue on every exit); traps as the negation of the skip
  condition; widths and signedness; typed fields the lifted code has stay; the object/vtable/method chain; the
  recurring patterns (component lookup, inlined empty string construction, the EntityHandle vtable, deleting
  destructors); which paths the checker never runs. The waiting packets were rewritten with it
  (`make_packets.py --refresh`, which now keeps look-alike and review notes).
- The `NOT REWRITTEN` guard (`run_api.py`, used by `agent_check.py`) also refuses an answer that keeps the lifted
  code's length (90%) and three quarters of its gotos (at least three): 5 of the 1,832 accepted answers would
  have been refused, the three of this review and two that the 2026-10-15 review had already replaced.
- The 55 FIX and REDO answers are revoked (`results.txt`: `REVOKED: review 2026-10-18 ...`, the old verdicts in
  `results_before_review.txt`) and sent back: `make_packets.py --review` made packets 0301-0307 with each
  function's review note and its earlier answer (start from it for FIX, afresh for REDO), queued after the
  look-alike packets. The 35 GOOD and MINOR answers stay accepted; their MINOR notes are for the regular review.

## Conclusions

The promotion check is necessary, not sufficient, for this model: about a quarter of its checked answers were
wrong on paths the synthetic inputs never reach, and most names needed correcting. Every Freebuff round needs
this kind of review before its answers are applied, and look-alike representatives most of all, since a wrong
representative is copied to its whole group.
