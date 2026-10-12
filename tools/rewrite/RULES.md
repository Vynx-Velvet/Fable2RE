You are rewriting functions of the game Fable II (Xbox 360, 2008, Lionhead Studios) from mechanically lifted
C++ into clean, human-readable C++ that behaves the same. Each function below comes as the exact lifted code
(what runs today) and, when available, Ghidra's decompilation of the same machine code (easier to read, but
not exact: Ghidra gets tail calls and some arithmetic wrong - the lifted code is the truth).

## What the lifted code means

- Game memory is a byte array `base`; game addresses are 32-bit. `LOAD32(a)` / `STORE32(a, v)` (also 8, 16,
  64, F32, F64) read and write big-endian values at game address `a`.
- `GameObject<Class>(base, addr)->m_XX` is a field of the object at `addr`; `Class* obj = GameObject<Class>(base,
  addr);` makes a typed view. Fields are `BigEndian<T>` and convert on access. Layouts are in
  `Fable2Recomp/lifted/classes.h`; a field you need that is not there is accessed with LOAD/STORE.
- `ctx` is the CPU state the recompiled code still passes around: `ctx.rN` / `ctx.fN` / `ctx.vN` registers,
  `ctx.r1` the game stack pointer. `stack = PushStackFrame(base, stack, N)` / `PopStackFrame` make the
  function's stack frame (game stack, not the C++ stack).
- Calls look like `Result = Callee(ctx, base, arg1, arg2, ...)`: the arguments are the callee's real parameters.
  Lines like `ctx.r5.u64 = x;` right before a call hand over a value through the register file; lines like
  `x = ctx.r7.u64;` after a call read a register back. Most of them are redundant.
- `str_Xxx` constants are game strings (the text is in the comment), `g_...` constants are game globals.
- `UseLiftedCode(...)` / `LiftedFrame` at the top switch to the original code when lifting is disabled.
  `CPU_STATE_ENTRY(sub_X, 0x...) { ... }` at the end is the entry used by code that still passes the CPU state.

## What you write

One file per function, `build/rewrite/answers/<packet>/sub_X.cpp`, containing the whole function:

0. If the function has no real name yet (it is called `n_sub_XXXXXXXX`), a first line proposing one:
   `// name: ClassName_WhatItDoes` (a C++ identifier, `Class_Method` style, only when the code makes the
   purpose clear; leave the line out otherwise). The definition itself keeps its `n_sub_` name.
1. The first line of the definition (`T Name(CpuState& ctx, uint8_t* base, ...) {`) **copied exactly** from the
   lifted code. Parameter names may change, nothing else.
2. The `if (!UseLiftedCode(...)) { ... }` line and the `LiftedFrame frame(...)` line copied exactly.
3. Your body.
4. The closing `}` and the `CPU_STATE_ENTRY(...)` line copied exactly (with the new parameter names if you
   renamed them).

The body must do exactly what the lifted code does, in this sense (it is what the checker compares):
- the same memory writes (addresses and values), in whatever order;
- the same calls, in the same order, with the same argument values - including values a callee takes
  through `ctx` (the checker tells you when a callee needed one: "argument value differs");
- the same return value.

Within that, make it readable:
- Real names for variables: what the value is in game terms (`targetEntity`, `goldAmount`, `isVisible`).
- Drop register hand-overs (`ctx.rN = ...`, `x = ctx.rN`) that the checker does not demand. Keep
  `ctx.r1.u64 = stack;` before calls that use the game stack, and keep the stack frame if any stack memory is
  used (addresses of stack temporaries handed to calls must stay the same offsets).
- Typed field access (`obj->m_XX`) where the class is known; otherwise LOAD/STORE with a named address variable.
- Simplify arithmetic the lifter spelled out (`(int64_t)(uint64_t)x + 4` is `x + 4` when the value is 32-bit);
  keep 32-bit wraparound where the game relies on it (`uint32_t`).
- Structured control flow instead of gotos where it reads better; early returns are fine.
- No comments that restate the code; one comment where the intent is not obvious.
- Never guess behaviour from Ghidra alone: when the two disagree, the lifted code is right.
- Keep every load in a chain: `LOAD32(LOAD32(p + 76) + 76)` reads a pointer at p+76 and then a field of the
  object it points to. Collapsing it into `LOAD32(p + 76 + 76)` is a different address. The checker runs
  with dense test memory precisely to catch this; a function that only passes on sparse memory is wrong.

Do not touch any other file. Do not run builds of the game. Check your answers with
`python tools/rewrite/check.py <packet>` and fix what it reports until every function is OK or you have a
specific reason it cannot be (write that reason into `build/rewrite/answers/<packet>/notes.txt`).
