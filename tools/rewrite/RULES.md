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
- Real names for variables, for what the code shows a value is: from the callees' names, class and field
  names, `g_` names and `research/names` (`targetEntity`, `stringLength`, `isVisible`). Do not invent game
  features (shops, trading, crimes, quests, prices): when the purpose is not visible, name the value by its
  place (`member44`, `componentType100`, `entryCount`). A wrong meaning is worse than none. The same holds for
  comments and for `// name:` proposals.
- Never use the game's text in names or comments: no identifier or comment built from the text of a `str_`
  constant or of a string in the Ghidra listing. Refer to a string by its `str_` constant only.
- A constant address stored at offset 0 of an object or of an embedded member (typical in constructors and
  destructors) is a vtable, not a state value; `research/names/classes.tsv` names many of them.
- Drop register hand-overs (`ctx.rN = ...`, `x = ctx.rN`) that the checker does not demand. A hand-over you
  keep stays exactly as the lifted code has it (same value, same sign extension, right before its call), a
  value read back (`x = ctx.rN`) stays right after the same call, and you add none of your own. Keep
  `ctx.r1.u64 = stack;` before calls that use the game stack, on every path, and keep the stack frame if any
  stack memory is used (addresses of stack temporaries handed to calls must stay the same offsets). Every
  store into a stack slot whose address goes to a call stays, both words of an 8-byte value included.
- Remove the lifter's noise: compare/flag machinery (`compare6.compare(...)`, `flags.ca`: write the signed or
  unsigned comparison itself), `(clz(x) >> 5) & 1` (that is `x == 0`), `rotateleft32(x, 0)`, a rotate of a
  value whose top bits are clear (`__builtin_rotateleft32(byte, 3)` is `byte << 3`), gotos to the next line,
  unused or hoisted locals, `const uint32_t zero = 0` and names for a plain 0 argument, register names as
  variable names (`tailR6`, `r10Scratch`); fold constants (`9961472 | 38527` is `9999999`). One statement per
  line.
- Typed field access (`obj->m_XX`) where the class is known; otherwise LOAD/STORE with a named address variable.
  Keep every typed access the lifted code already has (do not turn `orb->m_14` into `LOAD32(orbAddr + 20)`).
- A virtual call reads `object`, its `vtable` (`LOAD32(object)`) and the `method` (`LOAD32(vtable + k)`): name
  the three that way unless the class names the method. Do not reuse a parameter variable for another value.
- Simplify arithmetic the lifter spelled out (`(int64_t)(uint64_t)x + 4` is `x + 4` when the value is 32-bit);
  keep 32-bit wraparound where the game relies on it (`uint32_t`).
- Structured control flow instead of gotos where it reads better; early returns are fine.
- No comments that restate the code, and none about the tools, the packet or the grouping; one comment where
  the intent is not obvious.
- Never guess behaviour from Ghidra alone: when the two disagree, the lifted code is right.
- Keep every load in a chain: `LOAD32(LOAD32(p + 76) + 76)` reads a pointer at p+76 and then a field of the
  object it points to. Collapsing it into `LOAD32(p + 76 + 76)` is a different address. The checker runs
  with dense test memory precisely to catch this; a function that only passes on sparse memory is wrong.
- Keep every `ppc_trap(...)` check with its condition (the original's iterator and range checks), and keep
  each load on the same side of a call as in the lifted code (the callee may change that memory): a value
  the lifted code reads after a call is read again after it, never reused from before. The checker seldom
  reaches a trap and its stand-in callees write no memory, so it cannot show either mistake.
- When you turn gotos into structured code, every path must make the same calls in the same order and set
  the same values as the lifted path. Watch the exits: the exact-match exit of a search (`found = 1; goto
  L;`), early `goto` exits that return, and branches on particular ids or states. The checker's test inputs
  rarely reach these paths, so a passed check proves nothing about them: walk each one against the lifted code.
- A value the lifted code assigns before a `goto` still holds at its label. When a later call can fail (an
  allocation returning 0) and its failure path jumps ahead, what was set before that call stays set there: walk
  the path where the first step succeeds and a later one fails.
- Keep the signedness and width of every comparison (a key moved into a named constant stays `int32_t` when
  the lifted comparison is signed; `(uint32_t)x != 0` stays 32-bit), and use one variable per lifted value that
  ends up in a register hand-over, named for the value it holds (`oldBytesRead`, not `r8Carry`). A callee
  result or register read-back the lifted code keeps as `uint64_t` stays `uint64_t` where it goes on whole
  into a call argument or a hand-over.
- One exit path where you can: do not write the register hand-back out once per branch. Every exit runs the
  epilogue (`PopStackFrame` and `ctx.r1.u64 = stack;`), and on every path the function returns what the lifted
  code returns there: track each assignment to the lifted return variable (`arg1 = Call(...)` late in a path
  is the return value).
- A trap is the negation of the lifted code's skip condition, `if (!(a && b)) ppc_trap(...)`, never a
  simplified variant. A `LOAD64` value stays `uint64_t` up to its `STORE64`.
- The test memory makes the index table at +140 non-zero and the stand-in callees write nothing, so the
  binary-search branches, "found" paths and anything behind a value a callee fills in are never run by the
  checker: read those against the lifted code line by line. Nor does the checker compare the function's own
  stack frame: a store into a record on the stack whose address goes to a call is never checked, so keep every
  one the lifted code makes, at the same offset.
- "Class of the first argument" is inferred and can be wrong: when the function's own name or use says
  otherwise (a `CCharString_*` function), follow the code and do not use that class's fields.

Patterns that recur in this game (recognise them; keep every path of them):
- Component lookup on an entity: a presence bit in a word near +36..+48 of the entity, then either a slot via
  the byte table at +140 or a binary search (lower bound) over the sorted (type id, pointer) array between
  +72 and +76; the result is the pointer of the matching entry, or the end entry's. Name it as a lookup of
  component type N. The presence bit of component type N is bit N % 32 of the word at +36 + 4 * (N / 32).
- Static initialisers: a constructor (often `CCharString_ConstructFromCStr`) into a global, then
  `n_sub_82CA3700(function address)`: the global is constructed and the function at that address, which
  releases it, is registered to run at exit (`n_sub_82CA3700` is atexit: 0, or -1 on failure). An r8 value
  handed to it is only passed through. The short functions that call one function on a global are such
  release functions.
- Empty string construction inlined: an atomic increment loop on the global string count at
  `g_83490000 + 28344` and a store of 0 into a slot; it pairs with `CCharString_ReleaseAndDecGlobalCount...`
  on that slot at the end.
- `g_820F0000 + 5732` (0x820F1664) is the EntityHandle vtable: `{that, 0}` stored at a stack slot is a
  temporary empty EntityHandle.
- Deleting destructor: the destructor's work, a base-class vtable stored at +0, then `HandleTarget_Free` of
  the object when bit 0 of the second argument is set; the second argument is the delete flags.

Do not touch any other file. Do not run builds of the game. Check your answers with
`python tools/rewrite/check.py <packet>` and fix what it reports until every function is OK or you have a
specific reason it cannot be (write that reason into `build/rewrite/answers/<packet>/notes.txt`).
