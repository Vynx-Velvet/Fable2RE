# Rewriting lifted functions into clean C++ (instructions for a model)

You turn mechanically lifted functions of Fable II into readable C++ that behaves identically, one packet at a
time, and check each answer with the project's tester. Do nothing else: do not edit code outside
`build/rewrite/answers/`, do not run builds of the game, do not change packets.

Loop:

1. `python tools/rewrite/next_packet.py` prints a packet name and its file (or `DONE`: stop).
2. Read the packet file completely. It starts with the rules (RULES.md) and lists the functions with their
   exact lifted code and Ghidra's decompilation.
3. For every function write `build/rewrite/answers/<packet>/sub_X.cpp` as the rules say (definition line,
   UseLiftedCode and LiftedFrame lines, your body, closing brace, CPU_STATE_ENTRY line).
4. `python tools/rewrite/check.py <packet>` - one line per function:
   - `OK`: identical behaviour.
   - `BUILD FAILED ...`: fix the compile error it shows.
   - `call #k differs ... argument value #j`: the k-th call (0-based) of the function gets a different
     argument; j counts the registers the callee reads (r3.. then f1.. then v1..). Usually a value the callee
     takes through `ctx` that you dropped, or an argument computed differently.
   - `memory differs at ...`: a store with a different address or value.
   - `r3 after return` / `f1 after return`: a different return value.
   - `timeout` / `CRASH`: the test inputs are synthetic; if the original also times out it is reported as
     untested, not as a failure.
   Fix and re-check until all are OK. If one cannot be made to pass, say why in
   `build/rewrite/answers/<packet>/notes.txt` and move on.
5. Go to 1.

Keep the body honest: no behaviour from Ghidra that the lifted code does not have. Readability comes from
names, typed field access, dropped register noise and straightforward control flow, not from changing what
the function does.
