# Promoted code: the review is recorded (2026-10-15)

## Question

Can the review of the 1,210 promoted functions (76 modules) be finished with a cheap model doing the bulk and a
second reviewer looking only at what it lists, and what does that second look find?

## How it ran

- **Earlier review** (2026-10-10, Claude): verdicts for 939 functions, 579 of them confirmed by a second Claude
  reviewer, then stopped at the usage limit. All 1,210 module texts were still unchanged on 2026-10-13, so
  `tools/rewrite/review_api.py prepare` took it over: the 579 confirmed verdicts stood (their fixes were only
  checked), 360 single verdicts went to the model for verification, 271 functions got a full review.
- **Model** (`review_api.py run`, DeepSeek `deepseek-flash`, chunks of up to five functions, every fix checked
  with `check.py --outputs` on six profiles and sent back with the checker's line when it failed): 338 chunks,
  about 2.1 million input and 7.3 million output tokens (mostly the model's own reasoning), about four hours
  of run time over two days (two runs were stopped by Claude Code when the machine ran low on memory;
  `run` resumed where they stopped).
- **Second review** (Claude, of `escalate.tsv`): 39 functions.

## What the second review found

| Listed because | Functions | Outcome |
|---|---|---|
| model could not settle it | 3 | demoted (below) |
| model disagreed with a single earlier verdict | 5 | model right in 2; the earlier fix taken in 3, all for leftovers (a redundant register copy with a made-up name, a trailing `return;`, two dead carry updates the model had added), none for behaviour |
| one-in-ten sample of the model's own verdicts | 31 | 29 accepted as they were; 2 fixed by the second reviewer |

The two sample fixes (`sub_82C83BF0`, `sub_82C83F68`, `CStructuredWriter`) remove stores that reset a stack
string after it was freed, right before the frame is dropped: the original only frees it. Nothing can observe
those stores (the frame is dropped right after them, and the strict check passes with them), but they are
dead code under checklist item 4. No sampled verdict was wrong about behaviour.

Two of the three unsettled functions were large (`sub_824686C8`, `sub_82769578`): `deepseek-flash` spent its
whole output limit on reasoning in every round and never answered. Never cap its `max_tokens`; for such
functions a stronger model or a smaller chunk is the next step.

## The three demoted functions: the lifter, not the rewrite

`CECGraphicAppearanceMorph` `sub_824686C8`, `CECOpinionReaction` `sub_82769578` and `sub_82769838`: the earlier
fixes follow the lifter's exact output on every path, yet fail the strict check on one register the callers
read after the return. The lifter's own exact output fails it identically:

```
sub_824686C8  MISMATCH: r7 after return: 1 vs 0 [profile 4]
sub_82769578  MISMATCH: r9 after return: 66EE0E6F vs 0 [profile 4]
sub_82769838  MISMATCH: r9 after return: 214D9D0F vs 9A [profile 5]
```

So the lifter's model of what these functions leave in r7/r9 differs from the recompiled original on some
inputs: all three hand registers to callees and read them back (`CECGraphicAppearance_ForEach`,
`n_sub_8260B008`, `SharedHandle_Release`) around a lock loop or a sorted-table search. Not investigated further.
They are demoted (`promote.py record`, verdict DEMOTE): back to the lifter, text kept locally as revoked.
Open question for the lifter: which instruction's register effect it models differently there.

## Result

`promote.py record --dir build/rewrite/review_api --reviewer claude+deepseek-flash`: 935 fixes applied, 4
functions demoted (the three above and one the earlier review demoted), 1,206 of 1,206 module functions recorded
OK in `Fable2Recomp/src/game/promoted/REVIEW.tsv`. `record` cut notes at 300 characters and could leave a
trailing space, which the publishing whitespace check refused; it now trims them (and `review_api.py collect`
too).

## Checks of the recorded modules (2026-10-15, the same evening)

- `promote.py check`: 1,206 of 1,206 functions OK on every profile. The first pass, run while the game build
  had every core busy, reported two functions as `CRASH ... the test process died (exit FFFFFFFF)`: that is the
  tester's 300-second limit for a whole test program (`difftest/run.py` stops it and blames the function it
  was on), not a crash. Both passed alone twice; their two results were cleared and the check run again.
  Open: the tester should report that case as a time-out, and `promote.py` should not keep such a verdict for
  the next run.
- `tools/lift/update.ps1 -Build`: the four demoted functions passed the exact differential test (0 problems),
  nothing was dropped, the build (1,439 steps: the previous `Fable2.exe` dated from 2026-10-07) succeeded.
- `tools/autotest.py --suite`: menu OK, load OK, play OK, no teardown crash, no critical log lines.

## Held back: names made from game text

Publishing is held back anyway. The lifter names a string constant after its text (`str_<Text>`) and a global
after the text it is built from (`g_<Text>`, local table `research/decomp/global_names.tsv`), and the modules
keep those names: 294 different `str_` names and 14 such `g_` names in 47 of the 76 modules (tuning keys, text
identifiers, class names, a development path). Game text stays out of the repository (2026-10-12, the same
reasoning that took `globals.tsv` out), so `tools/validate_commit.py` now refuses these names in a promoted
module (address form `str_820E0F10` / `g_83496920` is fine), and `tools/publish.py` holds those 47 modules
back. The review notes in `REVIEW.tsv` have the same problem in a few rows (three `str_` names, one property
name read from the image).

Next: a published form of the modules with address names for these constants (a local overlay can keep the
text names for reading), and review notes checked against the local text tables before they are published.
