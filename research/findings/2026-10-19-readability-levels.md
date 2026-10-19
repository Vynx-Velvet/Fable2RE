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

## The same day: names for the start-up and shut-down functions, and the readable form

**Names after the global (`tools/rewrite/name_globals.py`).** Of the start-up and shut-down functions of global
strings, 2,050 do nothing but release one global (`CCharString_ReleaseAndDecGlobalCountA`) and 1,964 nothing but
construct one from its text and register its release at exit. Where the global has a name (made on every machine
from its own copy: `research/decomp/global_names.tsv`), they are named `Destroy_<global>` and
`Construct_<global>`. The names live in the promoted modules only: the lifted code reaches these functions through
pointers, and the weak native bridges (`native_bridges.N.cpp`) reach them through their entries, so nothing else
changes. The repository holds such a name with a reference in place of the global's name
(`Destroy_TXT_<address>_G_`: `promoted_text.py` now encodes a text-named global inside a longer name and its leak
check finds one that is not encoded); every setup renders the same name from its own copy.

**The readable form (`tools/rewrite/readable_form.py`).** Mechanical steps, each where it keeps what the strict
check compares, and every changed function checked again (profiles 0-5, the registers callers read):

- a register write goes when, in the straight-line code after it, the register is written again or changed by a
  call before anything reads it (summaries `mods`, `rin`, a read of `ctx.rN`, a return with the register among
  the function's `outputs`); a callee that only passes a register on (`fwd`) does not read a leftover temporary
  (a constant or an address), as the check itself treats it; a branch, a label or a call through a pointer
  leaves the write in place;
- the frame of a body that keeps nothing on the game's stack is one line, `GameStackFrame stackFrame(ctx, base,
  N);` (`Fable2Recomp/lifted/readable_support.h`: pushed where declared, popped on every return, as the original
  did; not used before a tail call made after the pop);
- atexit called with the r8 it was handed (the C runtime's own convention) is `RegisterAtExit(ctx, base, f)`,
  which calls it through its entry with r3 set and r8 as it is;
- a 64 KiB page base plus an offset handed to a call is named after what is at that address: the function
  (`Destroy_g_X_address`) or the string (the lifter's `str_` name, often fixing a misleading one: the page base
  itself was named after whatever string happened to start the page).

Result: 3,599 functions changed (516 in a first module, 3,083 in the rest), 3,330 passed the strict check and were
written (the other 269 keep their form;
most wrote a register before a call through a pointer, which the first version did not treat as a reader). The
build succeeds and the game checks pass (menu, load, play; no teardown crash, no critical log lines). A start-up
function now reads:

```cpp
uint64_t Construct_TXT_834985C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985C4_G_ = int32_t(0x834985C4);
	constexpr int32_t str_TXT_820BD244_B_ = int32_t(0x820BD244);
	constexpr int32_t Destroy_TXT_834985C4_G__address = int32_t(0x832A30F8);
	if (!UseLiftedCode(143, 0x83250030)) { __imp__sub_83250030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250030);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C4_G_, str_TXT_820BD244_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985C4_G__address);
}
```

(the published form; on a machine with the game, each reference is the global's or the string's name).

Levels of the 7,378 published functions after both: **4,070 named** (was 31), 1,423 readable with names still
to give, 1,885 still at machine level. A name made from an offset or a position (`flag144`, `GetField8`,
`GetByte31`, `unk10`) now counts as a placeholder (225 functions have one).

## The naming step (`tools/rewrite/name_pass.py`)

A packet per module holds the text of its functions that still miss names and, for each function they call
without a name, an excerpt of that callee's own code (the lifted text, or its module text), so a callee is named
from what it does. The model answers in the naming pipeline's lines (`F` function, `M` field, `L` variable or
parameter). `collect` keeps only medium and high confidence (a guess misleads: a wrong name is worse than none)
and refuses names made from an offset or a position (`GetField8`, `GetByte31`, `SetObjectByte171`, `flag144`);
variable and parameter names of promoted functions go straight into their modules (a rename inside one function,
refused when the name is already used there), everything else through `tools/naming/merge.py` into
`research/names/` (it rejects names that clash or would replace an entry of equal or higher confidence).

Run of 2026-10-19 (DeepSeek `deepseek-flash`, effort low, 476 packets for 3,442 functions): USD 2.35 (2.9 M
tokens in, 3.6 M out, of which 3.3 M reasoning).

| | Lines |
|---|---:|
| refused, low confidence | 1,790 |
| refused, made from an offset | 86 |
| variable and parameter renames applied in modules (971 functions) | 1,475 |
| added to the dictionary: functions / fields / locals of lifted callees | 3,347 / 1,241 / 1,882 |
| rejected by `merge.py` (clash, existing name of equal or higher confidence, invalid) | 1,013 |

The dictionary names take effect with `tools/lift/apply_names.py`, which re-lifts and re-tests what they affect,
and `promote.py sync`, which writes them into the modules (a long cycle: run with the whole-game work at night).
A name that keeps its global's address (`DestroyGlobalList_8349AD9C`) counts as an address, not a name, until the
global is named.

After the naming step and a second readable-form pass (calls through a pointer now count as readers: 141
functions tried again, 80 passed), the build succeeds and the game checks pass again (menu, load, play; no
teardown crash). Published levels: **4,072 named**, 1,421 readable, 1,885 at machine level; with the 57
hand-written functions, 4,129 of 41,186 game functions (10.0%) are readable C++ with every name. Placeholder
variable names are left in 510 functions (was 1,037).

Left for the next steps: the dictionary names (applied with the next re-lift and re-test, then `promote.py sync`
and a new naming round over what is still unnamed), names for globals (a published dictionary of globals does not
exist yet: 2,088 functions still use one by address), field access through the class model instead of raw offsets
(1,608 functions), and the 1,885 functions whose register code the analysis cannot show to be unneeded (a model
rewrite with the analysis' facts, or a more precise analysis of registers that are only saved and restored).
