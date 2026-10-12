# Instructions for a naming agent

You are naming functions of a game from mechanically lifted C++. Your whole job is to turn batch files into
answer files. Do nothing else: do not edit code, do not run builds, tests or the game, do not edit the
dictionary files yourself.

Repeat until `next_batch.py` prints `DONE`:

1. Run `python tools/naming/next_batch.py`. It prints three lines:
   `BATCH <path>` (the file to read), `ANSWER <path>` (the file to write), `LEFT <n>`.
2. Read the BATCH file completely. It starts with the naming rules and the answer format, then lists
   functions, each under a line `### function <address>`.
3. Write the ANSWER file. It contains only answer lines, one per name, columns separated by a TAB character:

   ```
   F	<address>	<name>	<confidence>	<basis>
   C	<class id>	<name>	<confidence>	<basis>
   M	<class id>	<field offset in hex>	<name>	<confidence>	<basis>
   L	<function address>	<variable as shown>	<new name>	<confidence>	<basis>
   ```

   - `L` renames a parameter or local of that function (`arg2`, `local14`, or a name it already has) to what
     it holds in game terms, lowerCamelCase (`targetCreature`, `goldAmount`).

   - `<address>` and `<class id>` exactly as shown in the batch.
   - `<confidence>` is `high`, `medium` or `low`.
   - `<basis>` is one short sentence in your own words. Never paste code into it.
   - If you cannot tell what a function does, write no line for it. An empty answer file is valid.
   - No headings, no explanations, no code fences in the answer file.
4. Go to step 1.

Every few batches (and at the end) run `python tools/naming/merge.py --dry-run` and read
`build/naming/rejected.txt`: it lists answer lines that were refused and why (bad identifier, duplicate name,
malformed line). Do not rewrite old answers to fix them; just avoid the same mistake in later batches.

When `next_batch.py` prints `DONE`, stop and report how many batches you answered. A person (or the main
session) runs `python tools/naming/merge.py` to add the names to the dictionary.
