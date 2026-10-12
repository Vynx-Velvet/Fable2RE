# Ghidra decompilation of Fable II (from your own copy)

Readable C-like reference for every function of `default.xex`, used to rewrite subsystems as
hand-written C++. Everything generated here is derived from the game: it stays local
(`research/decomp/`) and is never distributed.

## Requirements
- Ghidra 12 (`$env:GHIDRA_HOME` set to its folder, or its `support` folder on PATH)
- JDK 21+ (`$env:JAVA_HOME`, default `C:/Program Files/Java/jdk-23`)
- The extracted `iso/extracted/default.xex` and a regenerated `Fable2Recomp/generated/` tree

## Steps
    python tools/build_func_db.py                 # function database of the generated code
    python tools/ghidra/make_inputs.py            # decrypted image, functions.tsv, strings.tsv
    powershell tools/ghidra/run_ghidra.ps1 -Import   # project research/decomp/ghidra/Fable2 (~3 min)
    powershell tools/ghidra/run_ghidra.ps1 -Export   # research/decomp/c/decomp_XXXX.c + index.tsv (~40 min, 6 threads)

`-Export -Limit 500` decompiles only the first 500 functions (quick check).

## What you get
- `research/decomp/c/decomp_XXXX.c`: one file per 64 KB of code (`XXXX` = upper address bits),
  each function introduced by `// ---- name @ ADDRESS (bytes)`.
- `research/decomp/c/index.tsv`: entry, name, file, line, status - find any function quickly.
- The Ghidra project itself (`research/decomp/ghidra/Fable2.gpr`): open it in the Ghidra GUI to
  browse, rename and retype interactively (GhidraMCP can connect Claude to the running GUI).

## Known limits
- Language `PowerPC:BE:64:A2ALT-32addr` has no Xbox 360 VMX128 instructions (e.g. `lvlx`, opcode-4
  VMX128 forms): those decode as errors ("Unable to resolve constructor") and the decompiler leaves
  gaps there. Vector math code is affected; game logic mostly is not.
- Registers are 64-bit, pointers 32-bit: expect `ulonglong`/`undefined8` noise until types are
  applied.
- Names come from `research/symbols/*.md` (function tables) and the recompiler (`sub_ADDRESS`);
  `research/symbols/lua_bindings.tsv` (tools/find_lua_bindings.py) names the C++ behind each Lua
  binding.
