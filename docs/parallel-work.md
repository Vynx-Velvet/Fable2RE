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
| Rewrite lifted functions into clean C++ | `tools/rewrite/AGENT.md` | `build/rewrite/packets/*.md` (queue: `build/rewrite/queue.txt`) | `build/rewrite/answers/<packet>/sub_X.cpp` | `python tools/rewrite/check.py <packet>` |
| Name functions, classes, fields, locals | `tools/naming/AGENT.md` | `build/naming/batches/*.md` | `build/naming/answers/*.tsv` | `python tools/naming/merge.py --dry-run` |

`tools/rewrite/run_worker.ps1` keeps a worker going on a CLI that runs one-shot sessions (`-p`): it starts a new
session with the same instruction whenever the previous one ends, until the queue is done.

A suitable prompt for it: "Read tools/rewrite/AGENT.md and follow it until it prints DONE." Several copies can
run at once: `next_packet.py` hands each one a different packet (it marks a packet as taken by creating its
answer directory).

Rules for it, which the instruction files repeat: it writes only under `build/rewrite/answers/` or
`build/naming/answers/`; it never edits `tools/`, `Fable2Recomp/`, `research/`; it never builds or runs the
game. The checkers use their own build directory (`tools/lift/difftest/build_relaxed`), so they do not collide
with the main session's tester.

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
