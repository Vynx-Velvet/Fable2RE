# Rewriting lifted functions into clean C++ (instructions for a model)

You turn mechanically lifted functions of Fable II into readable C++ that behaves identically, one packet at a
time, and check each answer with the project's tester. Do nothing else: do not edit code outside
`build/rewrite/answers/`, do not run builds of the game, do not change packets.

You may be working inside a session of limited length (for example a one-hour agent session). That is fine:
every answer file you write is kept, and the next session goes on with the packet you were on. So write each
function's file as soon as it is finished, and keep going until the session ends or there is no packet left.

Loop:

1. `python tools/rewrite/next_packet.py --agent` prints a packet name and its file (or `DONE`: stop). When it
   says "resumed", an earlier session started this packet: look at the answer files already in
   `build/rewrite/answers/<packet>/` and at its `results.txt`, if there is one, and go on from there.
2. Read the packet file completely. It starts with the rules (RULES.md) and lists the functions with their
   exact lifted code and Ghidra's decompilation. A look-alike packet (`NNNN_lookalikes`) has a section of extra
   rules after them: each of its functions stands for a group of functions with the same code, and your
   rewrite is copied to all of them, so follow those rules exactly.
3. For every function write `build/rewrite/answers/<packet>/sub_X.cpp` as the rules say (definition line,
   UseLiftedCode and LiftedFrame lines, your body, closing brace, CPU_STATE_ENTRY line). Write them all before
   checking: one check builds and tests the whole packet and takes a minute or more.
4. `python tools/rewrite/agent_check.py <packet>` prints one line per function, with a hint for each failure:
   - `OK`: identical behaviour.
   - `NOT REWRITTEN`: the answer is still the lifted code. Rewrite it as the rules say.
   - `BUILD FAILED ...` / `INVALID`: fix the compile error it shows, keep the required lines exactly.
   - `call #k differs ... argument value #j`: the k-th call (0-based) of the function gets a different
     argument; j counts the registers the callee reads (r3.. then f1.. then v1..). Usually a value the callee
     takes through `ctx` that you dropped, or an argument computed differently.
   - `memory differs at ...`: a store with a different address or value.
   - `r3 after return` / `f1 after return`: a different return value. Another register (`r4 after return`):
     callers read it, so leave in it what the lifted code leaves there.
   - `timeout` / `CRASH`: the test inputs are synthetic; if the original also times out it is reported as
     untested, not as a failure.
   Fix only what failed and check again. The check ends a packet by itself: a function that failed three
   checks, or a packet that still fails after 15 minutes of fixing, is left for a later pass (it says
   "The packet counts as done"). Then go on with the next packet: a finished packet is worth more than one
   hard function. Do not write scripts, simulators or tests of your own to find a difference; when the hint
   does not show it, leave the function (`python tools/rewrite/agent_check.py <packet> --done` ends the
   packet at once).
5. Go to 1.

Use `agent_check.py`, not `check.py` directly: it runs the stricter check the project promotes with, and only
its results count.

Keep the body honest: no behaviour from Ghidra that the lifted code does not have. Readability comes from
names, typed field access, dropped register noise and straightforward control flow, not from changing what
the function does.
