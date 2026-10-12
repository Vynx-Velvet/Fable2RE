# Re-scope and a faster plan (2026-10-05)

## Why

After two days of naming rounds, 7% of all functions and 8% of all variables had meaningful names. Three causes:

1. About half of the functions are not Fable's own code (see the table below), and the naming agents were
   being fed Havok, audio-library and graphics-library internals.
2. Readability was added one label at a time, each needing apply, test and build.
3. Work ran serially, one experiment per 30-60 minute cycle.

## Decisions (user, 2026-10-05)

1. First priority: fully human-readable, clean code for Fable 2's own game code.
2. After that, remove the non-native layers one at a time.
3. End goal: replace the Xbox Live layer with self-hosted online servers, to bring back the Xbox Live player
   orbs and the rest of the online features as they used to be.

Library insides are out of the readable-code scope. Xbox system libraries get replaced on PC. Havok, Kynapse
and Scaleform stay as library code, named from their RTTI.

## Scope map

`research/catalog/scope.tsv` assigns every address range of the default.xex to a category, with the evidence
for each range. `tools/lift/scope.py` reads it (`python tools/lift/scope.py` prints the counts).

| Category | Functions | Named | What |
|---|---|---|---|
| game | 32,243 | 11.0% | Lionhead game and engine code: the readable-code target |
| game-static | 8,842 | 0% | compiler-generated start-up and shut-down functions of global objects |
| library | 11,433 | 6.2% | Havok, Kynapse, Scaleform GFx, image and XML readers |
| system | 6,665 | 2.0% | Xbox audio library, C runtime, Direct3D, shader compiler, import thunks |
| unknown | 1,179 | 0.8% | four ranges not identified yet |

Ranges are 64 KB-granular where no exact boundary is known; each row of scope.tsv carries a confidence. The
audio block 82C40000-82C60000 is marked system with medium confidence: its classes (CXAudioStreamSource,
CWaveSound, CAudioEngineCore) look like the Xbox audio library, but Lionhead audio classes may sit among them.

Ranges that matter for the online end goal, all in game scope:

- 82EE0000: game host, pub games, cross-title content (CGameHost).
- 82FF0000: web services, photo submission, online tasks.
- 82C70000-82C80000: sockets, in the engine support block.

The naming batch generators (`make_batches.py`, `make_class_batches.py`) now offer game code only
(`--all-code` restores the old behaviour).

## Name source found through the map: global string objects

The game-static range holds about 5,600 start-up functions. Each constructs one global object and registers its
destructor. 2,080 of them build a global string object from a text constant, and those texts are the game's own
property and definition names (DamageAmount, StartTimeInSeconds, CParticleEmitterType).
`tools/naming/global_strings.py` reads address and text out of them into `research/names/globals.tsv`.
Game code references these globals 3,664 times in 696 functions where the address is already folded to a
constant. More references are hidden behind split high/low address halves.

Side finding: in those functions the readable pass names the high half of an address as if it were a string
(`str_RoperMinimap` for 0x820B0000, where the real text is at 0x820B0000 - 28788). The halves stay separate
because the conservative register hand-over keeps the high half alive across the call. These are the "bogus
string names" the naming agents reported. Folding needs the register-traffic work (item 2 below).

## Plan from here

1. Whole-program type propagation: class types for arguments, return values and fields, not only for a
   method's own object, so field accesses and variable names come out typed across the game code.
2. Precise interfaces for calls through pointers (per-vtable-slot signatures), which removes most of the
   register traffic and lets address halves fold.
3. Mechanical name sources before agent rounds: global strings (above), serialisation code that pairs a name
   with a field, and script bindings carried into the functions they call.
4. Verified rewrites of whole classes by agents, accepted or rejected by the differential tester. A pilot on
   one class comes first; pass rate and cost per function are unknown.

## Measured the same day: class-type propagation is not the lever

Implemented: `typefacts.collect_flow` (how values move between variables, calls, returns and fields; written
to tools/lift/cache/flow by `lift.py --facts`), `typeflow.py` (propagates class types from method objects and
in-place constructions through copies, call arguments, return values and object fields), and inline member
access through any typed variable in `fields.py` (off by default: LIFT_TYPES=1).

Result on the first 10,947 game functions (119,277 constant-offset access sites through variables):

| Where the accessed pointer comes from | Share of sites | Typed after propagation |
|---|---|---|
| a variable assigned more than once (loops, merged paths) | 32.4% | 0% |
| the first argument | 19.8% | 25.8% |
| loaded from a field of another object | 16.8% | 0% |
| a call result | 12.2% | 4.6% |
| computed (arithmetic, globals, stack) | 9.9% | 0.3% |
| another argument | 8.9% | 1.3% |

Propagation added about 10% on top of the accesses already typed through a method's own object. About 6% of
all sites end up typed. The seeds are too sparse: only classes with a vtable have an identity, and only inside
their own virtual methods. Most game data is reached through plain pointers that never pass through such a
method.

Conclusion: types have to be inferred from structure, not from class identity. Every pointer variable gets a
struct type from how it is accessed, and types are unified along copies, calls, returns and field loads and
stores (the flow facts above already record these). Class identities then become names for some of the
inferred structs. The known risk is over-unification through generic helpers (allocators, containers, copy
routines), which has to be detected and cut.

## What blocks clean code, in dependency order

1. **Interfaces of calls through pointers.** One global summary stands for every call through a pointer (the
   union over all address-taken functions). It makes almost every function "read" 12 or more registers, which
   is the source of the register traffic (25% of lines), of unfolded address halves, and of the differential
   tester demanding register hand-overs a clean rewrite would not make. Fix: resolve each call site to its
   vtable slot and summarise per slot. Until this is done, agent rewrites cannot be verified, because the
   tester would reject code that leaves out the redundant hand-overs.
2. **Structural type inference** (above).
3. Then mechanical names and verified rewrites on top of both.

## Register hand-overs: four measurements and what went in (same evening)

Starting point: the median function counted as reading 37 registers (every argument register), and 24.5% of
the lifted lines in a 447-function sample of game code were hand-overs between locals and the CPU state.

| Idea | Result |
|---|---|
| Virtual calls read only what the functions in their vtable slot read (`experiments/slot_inputs.py`) | no change: 16,514 address-taken functions are in no known vtable and must count as targets of every slot |
| The same without those functions (not sound; an upper bound) | no change: 5,221 calls through plain pointers still read everything, and that spreads |
| Bound the arguments by what every direct call site supplies (`experiments/arity_inputs.py`) | median 37 to 34: 28,141 functions have no direct call site to learn from |
| Split inputs into really read and may be passed on (`experiments/forward_inputs.py`) | really read: median 6-8 registers |

The fourth is now in the analysis (`summarize.py`, ANALYSIS_VERSION 7, tables `rin` and `fwd`):

- `rin(f)`: what f's code and the functions it calls directly really read.
- `fwd(f)`: argument registers that may still hold their entry value at a call with unknown arguments (through
  a pointer, an import, hand-written code), directly or through a direct callee.
- A direct call of f reads `rin(f) | (fwd(f) & ready(site))`. `ready(site)` is the set the analysis already
  used for calls through pointers: registers written since the last call that may have destroyed them,
  received from the caller, or (new, for this mask only) standard result registers of the previous call.
  A register that an earlier call destroyed and nobody wrote since cannot be an argument.

Accepted gap: a result returned by a custom convention in an argument register other than the standard result
registers, handed on untouched through a function that only forwards it to a call through a pointer.

Check before the whole-game run: the 447 sample functions re-lifted with the new analysis went from 14,688
to 13,083 hand-over lines (24.5% to 22.6% of lines). In the differential tester, 441 are identical and 6
timed out (not compared), with no mismatch. Outputs shrank too (mean 16.6 to 11.6 registers per function).

What is left in the sample's 13,083 hand-over lines:

- writes of argument registers before calls: 2,834;
- XER reads after calls: 2,745 (1,710 of them the always-zero SO/OV bits, removed by the invariant);
- integer reads after calls: 1,231; float: 668; vector: 599; condition registers: 932;
- the stack pointer before every call: 1,085;
- other uses of the state (call arguments taken from it, return values, FP mode): 1,878.

Also measured: of the 27,808 address-taken functions, none really reads f8-f13, v9 or v11, and only 2 to 13
read f4-f7. Using that needs an assumption about imports and hand-written hooks (that they take at most
r3-r10 and f1-f4), because they are called with unknown arguments too. It would remove about 4% of the
hand-over lines. Not done.

Conclusion: register-level analysis cannot remove the rest. What is left is "this register might be an
argument of whatever this pointer call reaches", and that needs the target, which needs the object's type.
The stack pointer and condition-register hand-overs go away only when callees stop taking them from the
shared state (Phase C).

## 2026-10-06: the verified-rewrite pipeline is running

tools/rewrite (make_packets, check, apply, run_api) with the differential tester's relaxed mode: 162 functions
rewritten by deepseek-flash so far, 145 accepted (90%), 127 applied to the build after this morning's naming
round, built, game checks OK. Rewrites are stored in address form (n_sub_X, C_key) and fields keep an alias
under their offset name (union in classes.h), so later names cannot break them. Rewritten functions are exempt
from the strict tester and the skip list. Second exit-crash flavour fixed (a destroyed condition variable used
by the render thread at exit). The dictionary: 5,579 functions, 483 classes, 901 fields, 5,863 locals.
Inferred types (structflow.py) are shown in the packets as "T-numbers" with fields and class identity.
