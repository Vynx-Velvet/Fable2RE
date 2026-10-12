# Structural type inference: first whole-game results (2026-10-05 evening)

Goal: a struct type for every pointer the game code uses, so that field accesses print as members, variables
take names from their types, and virtual calls get their targets (which is what removes the remaining
register hand-overs). Class-identity propagation alone reached 7% of the accesses
(2026-10-05-scope-and-faster-plan.md); this is the replacement.

## Pieces

- `tools/lift/flowfacts2.py`: per function, how values move - copies, `x = y + k`, constant addresses,
  32-bit loads and stores (also to absolute addresses), vtable stores, constant-offset accesses with size and
  float-ness, direct calls with their arguments (locals handed over, and entry registers still untouched) and
  result variable, virtual calls with the object they are made on, returns. Runs the lifter's own pipeline, so
  variable names match the lifted code. Whole game: 148 files, about 45 minutes at 3 jobs
  (`cache/flow2/*.jsonl`).
- `tools/lift/structflow.py`: union-find over type nodes; a pointer node owns a struct (offset -> field node,
  sizes, class tags); unifying two pointers merges their structs field by field; `x = y + k` is the object
  embedded at k (stepping through an array when x is y); globals are fields of one global space.
  Guards against over-unification: no merge of unrelated classes or of layouts that mostly disagree
  (blamed on the function the edge came through); generic functions (blamed, pass-through helpers called from
  40+ places, and functions whose callers pass unrelated classes) are replayed per call site with fresh
  variables, and everything called from such a copy is copied too. Three passes, about 3 minutes.

## Numbers (478,463 constant-offset access sites through variables, whole game)

| | class-identity propagation | structural, pass 1 (every edge shared) | structural, final |
|---|---|---|---|
| sites in a struct with a class identity | 7.1% | 46% | 26.7% |
| sites in a struct used by 5+ functions | - | 41% | 25.9% |
| sites in a struct used by one function only | - | 52% | 63.1% |
| largest struct's share of all sites | - | 9% (a blob) | 4.8% |
| virtual calls (28,366) whose object has a known class | - | 51% | 20.2% |

The shared-edge pass glues: one struct took 9% of all sites, tagged with a trivial class. Causes found:
operator new, lua_newuserdata and the heap allocator (every allocated object through one result type), a
4-byte tail-call stub with 4,498 callers, and - the one that mattered - a per-call-site copy of a generic
function still calling a *shared* allocator, which re-joined all the copies. With copies isolated, the largest
structs are plausible singletons: the Direct3D device (3,767 functions), the game loop, the Havok world,
the GFx stream.

The price is fragmentation: 63% of the sites now sit in a struct only one function uses. Known missing
connections: constant addresses in variables assigned more than once (the split address halves), stack
temporaries (`stack + k` is skipped), constant pointer arguments to callees (global objects), functions too
big to copy per call site (their callers stay unconnected), entry variables that are reassigned.

The "classes it can be" figure for virtual calls (median 1) is not to be trusted yet: only 223 base-class
relations are known, so derived classes are mostly invisible.

## Next

1. Connect the missing flows above and measure the three shares again; the target is most sites in shared,
   identified structs with no blob.
2. Decide the printed form: typed views (`Class* player = GameObject<Class>(base, playerAddr)`) for
   parameters and single-assignment variables, inline views elsewhere; anonymous structs get stable ids
   (hash of their layout) so names can be attached in the dictionary.
3. Devirtualise with the class hierarchy once bases are known more completely, then re-measure the
   register hand-overs.
