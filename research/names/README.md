# Naming dictionary

Names for the functions, classes and fields of Fable II, applied by the lifter when it generates
the readable C++ from a user's own copy of the game. The dictionary contains labels and short notes written
for this project; it contains no game code.

All files are for one executable: the Fable II Game of the Year disc `default.xex` with media ID `716F0A0D` and
SHA-256 `88c4ef2e18e65409444d1b068eff921d1f7e180a5ae64edc64ba6b0872372662`. That hash covers the executable's
true extent, the bytes its XEX header accounts for. `python tools/xex_info.py <default.xex>` prints both values for
your copy.

An older extract left a 104,857,600-byte (100 MiB) copy: the same executable followed by unrelated data, with
whole-file SHA-256 `39f0c8cdd2ba3486ba347e8e6646a783b2b372c874b21d762e455349185627d5`. It is accepted as an
alias. The shipped lifter analysis `research/lift/summaries.json.gz` records the alias, and
`python tools/lift/bundle.py check` accepts either file.

| File | Key | Columns |
|---|---|---|
| `functions.tsv` | function address | `address  name  confidence  basis` |
| `classes.tsv` | vtable address | `vtable  name  confidence  basis` |
| `fields.tsv` | vtable address + offset | `vtable  offset  name  confidence  basis` |
| `globals.tsv` | global address | `address  name  text  basis` |
| `locals.tsv` | function address + generated variable | `function  variable  name  confidence  basis` |

- `name` is a C++ identifier, unique within its file (fields: within the class).
- `confidence`: `high` (identified from a public API or an exact anchor), `medium` (clear from use), `low`
  (a plausible reading; expect renames).
- `basis`: one line in our own words saying why. Never decompiled code.
- A name only labels code; it never changes what the generated code does. The differential tester and the
  game checks run on the generated code as before.

Small, evidence-backed pull requests are welcome. Follow [contributor workflows](../../docs/contributor-workflows.md), preserve the tab-separated headers, and run `python tools/validate_metadata.py` before submitting.

How names are found (pilot, 2026-10-04): start from anchors - Lua script bindings (`Lua_<Class>_<Method>`),
class-name strings used for component lookup, public library APIs the game embeds (Lua 5.1, the C++ runtime) -
and name what those call, bottom-up. `tools/lift/names.py` loads the dictionary; `lift.py`, `native_gen.py`
and `classes.py` apply it.
