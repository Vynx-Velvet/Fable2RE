# Working in parallel: a second CLI on cheaper models

Two agents can work on the project at the same time without getting in each other's way:

- **the second CLI (cheaper models)**: bulk work that comes with its own checker, so no judgement about the
  project is needed - rewriting functions into clean C++, naming;
- **the main session**: the lifter, the tester, analyses, applying results to the build, game checks.

## What the second CLI runs

Start it in the repository root. Give it one of these instruction files as its task; each one is a loop that
takes the next packet, answers it, checks the answer with a script and goes on:

| Task | Instructions | Takes | Writes | Checker |
|---|---|---|---|---|
| Rewrite lifted functions into clean C++ | `tools/rewrite/AGENT.md` | `build/rewrite/packets/*.md` (queue: `build/rewrite/queue.txt`) | `build/rewrite/answers/<packet>/sub_X.cpp` | `python tools/rewrite/agent_check.py <packet>` |
| Name functions, classes, fields, locals | `tools/naming/AGENT.md` | `build/naming/batches/*.md` | `build/naming/answers/*.tsv` | `python tools/naming/merge.py --dry-run` |

`tools/rewrite/run_worker.ps1` keeps a worker going on a CLI that runs one-shot sessions (`-p`): it starts a new
session with the same instruction whenever the previous one ends, until the queue is done (not for a CLI whose
terms require a person to start each session, such as [Freebuff](#free-hour-sessions-freebuff)).

A suitable prompt for it: "Read tools/rewrite/AGENT.md and follow it until it prints DONE." Several copies can
run at once: `next_packet.py` hands each one a different packet (it marks a packet as taken by creating its
answer directory). An agent takes packets with `next_packet.py --agent` (since 2026-10-17): a packet a session
left unfinished, because the session ended, goes to the next agent session once nothing in it has changed for 10
minutes, with the answers already written. `agent_check.py` is the check `run_api.py` makes (the promotion
check, six profiles, and the `NOT REWRITTEN` guard), with a hint per failure; `--done` records in `notes.txt`
what still fails, and the packet counts as done. It also ends a packet by itself (since 2026-10-18), when every
failing function has failed three checks or after 15 minutes of fixing (`checks.log` in the answer directory):
in the first Freebuff sessions six or seven of a packet's nine functions passed within minutes and the last
two or three took from half an hour to three hours. The functions left that way wait for a later pass.

Rules for it, which the instruction files repeat: it writes only under `build/rewrite/answers/` or
`build/naming/answers/`; it never edits `tools/`, `Fable2Recomp/`, `research/`; it never builds or runs the
game. The checkers use their own build directories (`tools/lift/difftest/build_relaxed`, `build_relaxed_out`), so
they do not collide with the main session's tester, and they take turns with each other across processes
(`build/rewrite/check.lock`, since 2026-10-17): an agent session can run while `run_api.py`, `promote.py` or
`review_api.py` checks, and each check waits for the one before.

### Free hour sessions (Freebuff)

[Freebuff](https://freebuff.com) is a free, ad-supported agent CLI; its free use comes in one-hour sessions, with
DeepSeek V4 Pro as the default model while the day's premium sessions last and V4 Flash after them (its README,
version 0.0.150, read 2026-10-17). Inside its sessions it can run the rewrite loop at no cost. In the repository
root:

```
freebuff
```

and as the session's first message: "Read tools/rewrite/AGENT.md and follow it until the session ends or it
prints DONE."

- Start each session yourself and stay with it while it runs. Freebuff's terms (the version in effect from
  2026-11-12, read 2026-10-17) allow the automation Freebuff performs inside a session a person started; they do
  not allow scripts, bots or wrappers that start or operate it, or calls to its servers from other software. The
  project's tools never start or drive Freebuff.
- A session that ends in the middle of a packet loses nothing: the next session's `next_packet.py --agent` goes
  on with that packet (or, when the session starts sooner than 10 minutes after the last one, takes a new
  packet and comes back to the unfinished one after it).
- The accepted answers go on like `run_api.py`'s: `apply.py`, `promote.py build`, the review. A session can run
  while `run_api.py` works on other packets.
- Look-alike packets first (since 2026-10-18): `python tools/rewrite/lookalikes.py` groups the functions whose
  code is the same apart from names, addresses and numbers, and `python tools/rewrite/make_packets.py
  --representatives --per-packet 9` puts one function per group of ten or more at the front of the queue
  (`NNNN_lookalikes`, with extra rules: the rewrite is copied to the whole group). The first 129 stand for 8,624
  functions ([findings](../research/findings/2026-10-18-lookalike-functions.md)). Each representative is
  reviewed before it is copied (verdicts in `build/rewrite/review_lookalikes.tsv`); `make_packets.py --review`
  sends the rejected ones back as `NNNN_lookalike_review` packets at the front of the queue, and
  `python tools/rewrite/copy_lookalikes.py NNNN_lookalikes` copies the approved ones and checks every copy
  (about 3 seconds a copy; batches leave room for a session's checks).
- Data: Freebuff uses prompts, code and files to provide the service and may analyse prompts and messages to
  personalise ads; some models may keep submissions for training (its README). The packets contain game code
  lifted from your copy.

## API keys

Without an agent CLI, `tools/rewrite/run_api.py` (rewrites), `tools/rewrite/review_api.py` (the review of the
promoted modules, [promoted code](promoted-code.md#review)) and `tools/naming/run_local.py --allow-remote`
(naming) send each packet or batch to a hosted model themselves, over the OpenAI chat-completions protocol. Store
the provider's key once per user account; every new terminal finds it:

```
python tools/api_keys.py set deepseek               # paste the key at the prompt (it is not shown)
python tools/api_keys.py set deepseek --clipboard   # or copy the key, then take it from the clipboard
python tools/api_keys.py list                       # stored keys, last four characters only
python tools/rewrite/run_api.py --list-models       # the key works: the models it may use
python tools/rewrite/run_api.py --model <model> --jobs 4
python tools/rewrite/run_api.py --workers 3 --jobs 6 --keep-balance 3.5   # three packets at a time
python tools/rewrite/run_api.py --effort low --workers 3 --jobs 6        # less hidden reasoning (cheaper)
```

`run_api.py` (2026-10-16) checks answers as `promote.py` does (six profiles, the registers callers read after
the return; `--quick` for the older relaxed check), so what it accepts can be promoted as it is. An answer that
is still the lifted code (90% of its lines unchanged, for functions over 15 lines) passes that check because it
is the same code, so it counts as `NOT REWRITTEN` and goes back to the model. With
`--workers N` it works on N packets at a time; their checks take turns. On `api.deepseek.com` it shows the
account balance after every packet and, with `--keep-balance X`, takes no new packet below X (money left for
the review). When the provider refuses the key or the balance runs out (HTTP 401/402) it stops at once: the
packet is not marked done, and the next run offers it again without asking again for the answers it has.

**Thinking effort** (2026-10-17). DeepSeek's models think before they answer, at high effort unless the request
says otherwise, and the hidden reasoning is billed as output: in the 2026-10-16/17 rewrite round more than 95%
of the output tokens paid for were reasoning
([finding](../research/findings/2026-10-17-deepseek-round-491.md#cost-hidden-reasoning)). The three tools take
`--effort none|low|high|max` (`tools/model_api.py`); without it they send nothing and the provider's default
applies. With `--effort none` they ask for an output limit of 32,768 tokens (DeepSeek's default without
thinking is 8K, short for a long function); `--max-tokens N` sets another. `run_api.py` reports a reply cut off
at the limit instead of checking it. Their token counts show how much of the output was reasoning and how much
of the prompt came from the provider's cache. DeepSeek charges half outside 01:00-04:00 and 06:00-10:00 UTC on
weekdays (api-docs.deepseek.com, Models & Pricing, read 2026-10-17).

A pilot on the same 18 functions ([finding](../research/findings/2026-10-17-deepseek-round-491.md#pilot-the-same-18-functions-at-three-efforts))
found `--effort none` unsuitable for rewrites (half the functions accepted, and those left close to the lifted
code) and `--effort low` as good as the default `high` on acceptance at about a fifth less cost, with slightly
less cleanup.

- The key is kept outside the repository, so no commit can include it: on Windows in
  `%APPDATA%\Fable2RE\api_keys.json`, encrypted for your Windows account (it cannot be read by another account
  or on another machine); elsewhere in `~/.config/fable2re/api_keys.json`, readable by you only.
- The tools choose the key by the URL (`api.deepseek.com`: `deepseek`, `openrouter.ai`: `openrouter`) or by
  `--key NAME`. The stored key comes first, so an old key left in an environment variable does not shadow a
  new one; the variable (`DEEPSEEK_API_KEY`, `OPENROUTER_API_KEY`) counts only when no key is stored.
  `--api-key-env VAR` uses that variable first.
- A new key replaces the old one: `set` again. `remove deepseek` deletes it.
- Never paste a key into a chat, an issue or a file in the repository. `publish.py` refuses staged changes that
  contain a stored key, and `validate_commit.py` anything shaped like one (`sk-...`).

## What the main session does with the results

- Rewrites: `python tools/rewrite/apply.py` copies accepted functions (`OK` in `results.txt`) to
  `Fable2Recomp/rewritten/` and into their chunks; the lifter keeps a rewritten function in place of its own
  output from then on (`chunks.py`), and the strict tester records it as accepted in relaxed mode. Then
  `tools/lift/update.ps1 -Build` and the game checks. First batch (12 functions) applied 2026-10-06: build
  31 s, menu / load / play OK.
- Publishing rewrites: `python tools/rewrite/promote.py build` moves applied rewrites that pass all six
  input profiles into source modules (`Fable2Recomp/src/game/promoted/<Class>.cpp`), then `promote.py
  review` makes the review packets; see [promoted code](promoted-code.md).
- A rewrite the game or a later check shows wrong: `python tools/rewrite/revoke.py sub_X --reason "..."`
  (or `--from-results FILE` for every non-OK line) puts the lifter's output back and keeps the file as
  `sub_X.cpp.revoked`. Re-checking revoked files later (`check.py --dir`) and `restore.py --from-results`
  put the ones that pass back; `make_packets.py --retry` offers the rest to the cheap model again with the
  checker's reason as a warning (a function already rewritten again is not retried).
- Names: `python tools/naming/merge.py`, then `python tools/lift/apply_names.py` and
  `tools/lift/update.ps1 -Build`.

## Making work

- Rewrite packets: `python tools/rewrite/make_packets.py --limit 400` (game code only, named classes first;
  `--class KEY` for one class, `--funcs file` for a list). Each run appends to the queue.
- Naming batches: `python tools/naming/make_batches.py` (functions), `make_class_batches.py` (classes with
  their fields and methods), `make_batches.py --locals` (local variables).

## Correctness model of the rewrites

The checker compares a rewritten function with the original on synthetic inputs: the same memory writes, the
same calls with the arguments the callees really read, the same return value. It does not demand the register
state the original leaves behind, which is what lets the rewrite drop the register hand-overs. A wrong guess
about a value a callee takes through the CPU state shows up as a failing check; one that only matters on a
path the synthetic inputs do not reach shows up in the game checks, and `tools/lift/auto_bisect.py` finds the
function. The exact lifted build stays as the reference.
