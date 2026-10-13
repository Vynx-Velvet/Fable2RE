# Global string names: generated locally, not shipped

Date: 2026-10-12. Owner decision: game text stays out of the repository and is rebuilt on the user's machine, as
for the catalog's string column the same morning ([audit](../../docs/initial-commit-audit.md)).

## What it was

`research/names/globals.tsv` held 2,080 rows: the game's global string objects, each with its address, a name, the
text it is built from, and a basis. The texts are the game's property, definition and UI element names,
up to 78 characters. Every row was mechanical:
`tools/naming/global_strings.py` wrote all of them, and every name is `g_` plus the text with other characters
turned into underscores (60 characters at most), so dropping only the text column would have left the same text
in the names. The whole table therefore left the repository.

## How it is rebuilt

The lifted text carries these names (`readable.py` prints `g_<Text>` instead of `g_<address>`), and the
verification manifest's hashes were taken from text that carried them, so a setup has to write exactly this table
before the lift. `global_strings.py` used to read the start-up functions out of the lifted files, which only exist
after the lift. It now lifts the 8,842 game-static functions (`research/catalog/scope.tsv`) in memory and reads
the same two addresses out of each (the global and its text), then names them as before. It writes
`research/decomp/global_names.tsv` (ignored); `readable.py` reads it from there. Setup step `globals`, between
`decls` and `lift`, runs it (33 seconds).

A table from `research/symbols/func_db.json` constants and the image alone was tried first: it matched 2,050 of
the 2,080 rows, so the lifted form is kept.

## Checks

- Development tree: the new script's table is byte-identical to the committed `globals.tsv` (36 s, 8 processes).
- Fresh clone with no names file: byte-identical as well, through the setup step (33 s).
- 40 functions chosen at random among the 4,979 lifted functions that print a global's name, lifted again with
  the names from the new file: text identical to the existing lifted files.
- `tools/validate_commit.py` refuses `research/names/globals.tsv`.

The table was in the first four pushed commits (private repository). Removing it from those needs a history
rewrite.
