# DeepSeek conversion round: 491 more functions promoted (2026-10-16/17)

## Question

How far does one DeepSeek account balance take the conversion of lifted functions into reviewed readable C++
(rewrite, promotion, review, game checks), and what does a round find that the tools should catch earlier?

## Changes before the round (tools/rewrite)

- `run_api.py` checks answers with the promotion check (`check.py --outputs`, profiles 0-5) instead of the plain
  relaxed one, and feeds its failures back to the model, so what it accepts promotes as it is. The 2026-10-07
  run had stopped on "Insufficient Balance" and left 123 packets (1,111 functions) without answers but marked
  done: the runner now stops at HTTP 401/402 without marking the packet done (`stopped.txt`; `next_packet.py`
  offers it again, the answers already written are kept). New: `--workers N` (packets at a time, checks take
  turns), the balance after every packet on api.deepseek.com, `--keep-balance X`.
- An answer that is the lifted code unchanged passes the check because it is the same code. One of the earlier
  rounds' promoted functions (461 lines) had been accepted like that; the review replaced it. The runner now
  counts an answer with 90% of its lines unchanged (functions over 15 lines) as `NOT REWRITTEN` and sends it
  back. Four answers of this round's first leg (run before the guard) were caught afterwards and not applied.
- `review_api.py prepare` leaves out the functions whose review `REVIEW.tsv` records for their current text
  (digests: `build/rewrite/promote/reviewed_texts.json`, started from the published modules); `collect` lists
  them as `RECORDED`, `promote.py record` keeps their rows. A round pays only for new or changed functions.
- `review_api.py prepare` read the strict check's results only from `promote.py check`, so every function
  promoted since then counted as failing it, and the model's OK verdicts would all have been refused. It now
  also takes `promote.py build`'s results for the same text.
- `promote.py record --partial` records a review that did not reach every function. `promoted_text.py publish`
  leaves a module with a function not yet reviewed OK exactly as it was published (file and manifest row):
  before, such a module was held back by `publish.py` while `manifest.tsv` carried its new hash, so a fresh
  clone would have failed to render it. `review_api.py second` applies a second reviewer's decisions.

## The round

| Step | Result |
|---|---|
| Rewrite (`run_api.py --workers 3 --jobs 6`, deepseek-flash) | 49 packets, 512 functions: 495 accepted by the promotion check, 4 of them the lifted code unchanged; 491 applied. 3.1 M input / 10.5 M output tokens, USD 6.37 (1.3 cents per accepted function), 2 h 36 min |
| Promotion (`promote.py build`) | 491 of 491 pass profiles 0-5 (27 in the cleaner form) into 48 modules; the 23 older rewrites that failed it before fail again |
| Build, game checks | `update.ps1 -Build` 12 min; menu, load and play OK, no teardown crash |
| Review (`review_api.py run`, deepseek-flash) | 60 of 123 chunks before the balance ran out: 237 functions, 140 OK, 95 FIX, 2 DEMOTE; 0.8 M / 3.2 M tokens, USD 1.91 (0.8 cents per function) |
| Second review (Claude, `escalate.tsv`) | 22 functions: 11 OK as they were, 6 model verdicts confirmed (4 fixes, 2 demotions), 5 own fixes |
| Record (`record --partial`) | 1,441 of 1,695 module functions recorded OK (1,206 before); 254 wait for review |

## What the second review found

- **A load moved across a call.** Two functions read an object field before a call where the original reads it
  after (`sub_8252DD08`, fixed by the second reviewer; `sub_827EB570`, found by the model). The differential
  check cannot show this: its stand-in callees write no memory, so a callee that changes the field never
  happens in the test.
- **Dropped trap checks.** The two demoted functions (`sub_82855578`, `sub_82856F80`) leave out all of the
  original's iterator `ppc_trap` checks (12 and 3); every call matches. The test inputs seldom reach a trap.
- **Register hand-overs.** Four model fixes put back what the original hands to a later call through
  registers: values it reads back after a virtual call, or saves at entry (`sub_82B48EB8`, `sub_82703860`,
  `sub_822D50B8`, `sub_82495320`).
- **Names.** Three own fixes are names only, and a fourth renames on top of a model fix: a variable named after
  text it does not hold (it holds the strings' shared base address), names the code does not support, and two
  locals whose names carried a string constant's text in a form the publish check does not recognise (it finds
  the text in a name only in the same case, or as the lifter's own local).

`tools/rewrite/RULES.md` (the rewrite prompt) and the review checklist (`docs/promoted-code.md`) now name the
first two.

## Cost: hidden reasoning

`deepseek-flash` thinks before it answers unless the request turns that off, at high effort by default, and
bills the reasoning as output tokens. The tools never turned it off. The round's 705 rewrite requests produced
10.5 M output tokens, about 15,000 per request, while the 509 answers the round kept come to 1.25 MB of code,
about 700 tokens each (3.5 characters per token). Even with every fix-round answer counted at that size, the
code is under 5% of the output paid for: more than 95% was reasoning. The review is similar (3.2 M output
tokens for 60 chunks, about 53,000 per chunk of up to five functions).

The price list explains the bill: output costs USD 0.60 per million tokens off-peak (1.20 at peak), a cached
prompt token USD 0.003 per million, so 10.5 M output tokens off-peak are USD 6.30 of the round's USD 6.37
(api-docs.deepseek.com, Models & Pricing, read 2026-10-17; peak hours 01:00-04:00 and 06:00-10:00 UTC on
weekdays). The same page lists DeepSeek-V4.1-Flash-1017 as the model now behind the name `deepseek-flash`;
which version answered this round is not recorded.
Thinking mode also ignores the temperature, so the tools' 0.2 (rewrite) and 0.1 (review) had no effect.

DeepSeek takes `{"thinking": {"type": "disabled"}}` to turn the reasoning off and `reasoning_effort`
(`low`, `high`, `max`) to set its effort (Thinking Mode page). `run_api.py`, `review_api.py` and
`tools/naming/run_local.py` now take `--effort none|low|high|max` (`tools/model_api.py`; without it nothing is
sent, as before), ask for a 32,768-token output limit without thinking (DeepSeek's default then is 8K), and
count the reasoning and cached tokens the provider reports.

### Pilot: the same 18 functions at three efforts

Packets `0212_CGameLoopBase` and `0213_CECSpacialAwareness` (18 functions, 2,272 lifted lines: larger than the
average function) were rewritten three times, one run after another, with `run_api.py --effort E --packets 2
--workers 2 --jobs 6` and the promotion check (Saturday 2026-10-17, off-peak prices). Each run's answers are in
`build/rewrite/pilot_effort_2026-10-17/<effort>/`.

| Effort | Accepted | Fix requests | Output tokens (reasoning) | Cost | Per accepted function | Minutes |
|---|---|---|---|---|---|---|
| none | 9 of 18 | 28 | 81,772 (0) | USD 0.06 | 0.66 cents | 12 |
| low | 18 of 18 | 7 | 307,558 (271,946) | USD 0.20 | 1.09 cents | 10 |
| high (the default so far) | 18 of 18 | 7 | 404,358 (371,572) | USD 0.25 | 1.40 cents | 12 |

Readability, measured on the accepted answers (lines of the body left exactly as the lifter wrote them; locals
still named `localNN`; gotos): without reasoning 65% of the lines were unchanged, with low effort 37%, with high
32%. On the 9 functions all three runs accepted, the lifter's 165 `localNN` names became 114 (none), 71 (low)
and 66 (high), its 12 gotos 7, 2 and 0. The answers without reasoning that failed failed for real (memory
writes, a register a callee reads, a build error) and three fix rounds hardly helped (5 of 9 accepted after the
first check and after the last); one was the lifted code unchanged (`NOT REWRITTEN`), and one accepted answer
kept 78% of the lifted lines, under that guard's 90%.

So reasoning is what does the rewriting: without it the model accepts half as many functions and leaves the
ones it passes close to the lifted code. Low effort passes everything high passes here, at about a fifth less
cost and slightly less cleanup. Reasoning stays most of the output at low effort (88%). The effort setting is
therefore a modest saving, not the large one the token counts suggested; the cheaper paths are the structural
ones (start-up initialisers by template, one rewrite per repeated code shape, small functions batched).
The review at low effort is not measured yet. The high-effort answers were kept as the packets' answers.

## Open

- **Names that spell game text.** The rewrite packets include Ghidra's decompilation with string literals, so a
  model can name a variable after text that no constant of the function explains (a string at a computed
  address), and `promoted_text.py` cannot encode or flag it. A local scan of the published modules finds 56
  distinct identifiers (outside the names dictionary) equal to the identifier form of some string in the image;
  nearly all are ordinary code vocabulary that also occurs as a string (`lowerBound`, `lengthSquared`). Whether
  such coincidences are acceptable, and whether model-chosen names derived from text should be refused, is the
  owner's decision (2026-10-12: game text stays out of the repository).
- 254 functions of this round wait for review (about USD 2 at this round's rate). Of the 122 modules, 98 are
  reviewed throughout (23 of them new); the other 24 (one of them published before) stay as published until
  then. The queue holds 74 waiting packets (599 functions); about 38,000 game functions were
  never offered. At this round's rates a function costs about 2 cents (rewrite and review), most of it hidden
  reasoning ([above](#cost-hidden-reasoning)); low effort saves about a fifth of the rewrite cost, no reasoning
  does not rewrite well enough.
- Retries: the 4 `NOT REWRITTEN` functions (`build/rewrite/not_rewritten_2026-10-16.txt`), the 23 rewrites that
  fail promotion, the 2 demoted functions.
