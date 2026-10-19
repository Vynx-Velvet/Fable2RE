# Readability levels: what "human-readable" counted, and what it counts now (2026-10-19)

## Question

The progress published on 2026-10-19 (commit `d66723c`) said 18.1% of Lionhead's game functions were
human-readable C++: every promoted function counted, because each passes the strict check against the original
and a review. Reading the published modules says otherwise. A typical start-up initialiser:

```cpp
uint64_t n_sub_83250030(CpuState& ctx, uint8_t* base) {
	...
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C4_G_, (int64_t)str_TXT_820C0000_B_ - 11708, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
```

It constructs one global string and registers its release to run at exit: three lines when written for a
reader. How many promoted functions can a person actually read?

## The bar (`tools/rewrite/readability.py`)

Measured on the published text (`Fable2Recomp/promoted/`, so every clone and the CI get the same numbers), per
function, without the fallback, frame-marker and `constexpr` lines and without comments:

| Level | Holds when |
|---|---|
| rewrite | the body still uses the CPU state (`ctx.r11`, `ctx.f1`, `ctx.xer`, ...) or the stack-frame bookkeeping (`PushStackFrame`, `PopStackFrame`) |
| readable | no CPU state and no frame bookkeeping, but a name is missing: the function's own (`n_sub_X`), a callee's (`n_sub_X(`), a global's (`g_832A0000`, a page base plus an offset, a literal `0x8xxxxxxx`), a variable's or parameter's (`local12`, `arg1`, `r31`), a field's (`LOAD32(self + 144)`, `self->m_1C`) |
| named | neither: plain C++ in which every name says what it is |

A global named after its text (`TXT_..._G_`, rendered locally to the lifter's name from the game's string) counts
as named. Whether a name is *right* is not measured (a review question); whether there is one is.

## Measurement (published modules, 2026-10-19)

| Source | Functions | named | readable | rewrite | CPU state | frame | unnamed function | unnamed callee | address | machine variable | field offset |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| DeepSeek rounds (2026-10-10/17) | 1,441 | 14 | 133 | 1,294 | 1,294 | 1,201 | 962 | 796 | 664 | 404 | 1,034 |
| Look-alike copies | 5,900 | 17 | 2,911 | 2,972 | 2,972 | 2,696 | 5,817 | 2,965 | 3,364 | 623 | 561 |
| Look-alike representatives | 37 | 0 | 9 | 28 | 28 | 25 | 33 | 27 | 26 | 12 | 13 |
| **All** | **7,378** | **31** | **3,053** | **4,294** | | | | | | | |

With the 57 functions written by hand: **88 of 41,186 game functions (0.2%) are readable C++ with every name**,
not 7,435 (18.1%). The earlier rows of the history, measured again the same way: 2026-10-15 14 named (of 1,206
reviewed), 2026-10-17 14 (of 1,441).

Most used missing names (functions using each): `n_sub_82CA3700` 2,544 (the at-exit registration of the
start-up initialisers); page bases `g_832A0000` 1,403, `g_832B0000` 1,141, `g_820A0000` 808, `g_820E0000` 516
(each a page base plus an offset that is really one function's or one string's address); `n_sub_82D4F620` 120.

## Why the rewrites look like this

- **The CPU state is the interface to the rest of the program.** A promoted function's callers and callees are
  still lifted or recompiled code, which passes values through the registers. The whole-game analysis lists for
  each function the registers its callers read after the return and the registers a callee passes on
  (`research/findings/2026-10-10-native-call-check.md`), and the strict check compares them, so a rewrite keeps
  those writes. The models were told to keep every hand-over before a call and every write-back before a return
  (the safe rule after the 2026-10-10 re-check), so they also keep writes that nothing reads (`ctx.r9` and
  `ctx.r11` above).
- **The stack frame** is kept because a callee may use the memory below it and because records on the stack are
  passed by address; a function that keeps nothing on its stack does not need one.
- **Names come from the dictionary**, which names 12.7% of the game's functions; the rest keep their address.
  The look-alike rules asked for the lifter's names, so that one rewrite fits every member.
- **Review asked whether a rewrite behaves like the original, not whether it can be read.** The progress page
  counted the first as the second.

## Change

- `tools/progress.py` counts six kinds: readable with every name, by hand (both human-readable, the headline),
  readable with names still to do, rewrite still at machine level, machine-translated, recompiled. The README
  block, chart and `docs/progress.md` (with a table of what the rewrites still need) follow; the history has the
  three new columns and its earlier rows were measured again.
- `docs/promoted-code.md` describes the levels; `docs/status.md` corrects the claim.

## Next

1. The readable form, mechanically where the analysis allows it: drop register writes that no callee reads
   or passes on and that no caller reads after the return; move write-backs that equal an entry argument into
   the generated entry; drop the frame of a function that keeps nothing on its stack. Each function checked
   again (strict check, profiles 0-5). What is left goes to a model with the analysis' facts.
2. Naming: page base plus offset resolved to the function or string at that address; the at-exit
   registration and the start-up/shut-down functions named after what they construct and release; then
   functions, globals, variables and fields by a model (the naming pipeline, `tools/naming/`), applied to every
   module.
3. Review and progress: the readability level in every review packet and in the publish summary; a function
   counts as human-readable only at the named level.
