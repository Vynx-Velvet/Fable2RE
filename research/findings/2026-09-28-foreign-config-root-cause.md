# Why the recompiled Fable 2 never reached rendering (2026-09-27/28)

## Summary

The generated C++ was produced from a codegen config whose function table does not
belong to this executable. `Fable2Recomp/Fable2_config.toml` (upstream commit
`1e259111`, "Port refii src/thirdparty and config updates") carries 946 `[functions]`
entries, 789 of them named (`rex_doexit`, `rex__amsg_exit`, `rex_lhGameThreadInit`, ...)
with explicit sizes, plus `longjmp_address = 0x82CAFA30` and `setjmp_address = 0x83006C90`.

Checked against the .pdata table of the XEX actually loaded by the runtime
(`tools/audit_config_functions.py` on a cdb memory dump of 0x82000000-0x83620000):

| Classification | Count | Meaning |
|---|---|---|
| INSIDE a real function | 853 | bogus entry that splits a function in two |
| ORPHAN, implausible bytes | 53 | bogus |
| ORPHAN, plausible start | 14 | small trampolines added in July, real |
| Real .pdata start | 26 | real, but every stated `size` disagrees with .pdata |

Both setjmp/longjmp addresses are mid-function as well.

Because config entries have CONFIG authority in the codegen, every bogus address became
a function boundary. Consequences seen in the old `generated/` tree:

- 973 `REX_FATAL("Unresolved branch/call ...")` sites (805 after the July Python fix-ups),
  351 unique targets.
- The "798 missing targets / 426 split-use" lists in PORTING_STATUS.md.
- Concrete runtime failure in the faithful baseline: `_lock` (sub_82CAFF48) has its
  acquire label 0x82CAFF88 registered as a function named `rex__cexit`, so the codegen
  turned `bne cr6, acquire` into a tail call into a fake function. Together with
  `_mtinitlocknum` (0x82CAFE08, misnamed `rex_doexit`) that produced infinite
  `_lock -> _mtinitlocknum -> _lock` recursion during C++ static init.
- Upstream's `sub_82CC7BB8` "GetFileSectorInfo" hook is also mid-function
  (inside 0x82CC7888-0x82CC7E48).

## What the July hooks did

All of `src/heap.cpp`'s boot hooks were workarounds for the symptoms above, and one of
them stubbed **main() itself** (`REX_HOOK_RAW(sub_822EA8C0) { r3 = 0 }`), so the real
game thread (created by main at 0x822EA928) was never started. The colored-square
"native render loop" replaced the game rather than running it.

## Verified boot path (this XEX)

- `xstart` 0x82CBB970: CRT init, `_mtinit` (sub_82CAC798), static initializers
  (sub_82CC1990 over 0x832D0010-0x832D5DC8), then `main` = sub_822EA8C0(argc, argv, 0).
- `main`: `_beginthreadex(start=0x822EA928, stack=256K)`, then waits on the handle forever.
- Thread wrapper: ExCreateThread(start=0x82CA3430) -> sub_82CA3388 -> bctrl to ptd+84.
- CRT TLS table at 0x833368FC: [0x82CAC3C8 (`b __imp__KeTlsAlloc`, 8 bytes, no .pdata),
  KeTlsGetValue, KeTlsSetValue, KeTlsFree thunks].
- Worker-init table entry 0x82CB6EE0 (48 bytes, no .pdata) sets two CRT globals.
- longjmp = 0x82CA9260, setjmp = 0x83000200 (asm routine, no .pdata).

## Fix

1. `Fable2_config_clean.toml`: no names, no sizes from the foreign list; only the two
   verified tiny functions and ten verified trampolines. Original kept as
   `Fable2_config.toml.foreign_symbols`.
2. `fable2_manifest_new.toml` with the verified setjmp/longjmp addresses; regen into
   `generated_new/`, then swap.
3. Runtime safety net in `rexglue-sdk/src/system/function_dispatcher.cpp`
   (`ResolveTailJumpThunk`): an indirect call to an unregistered address that holds an
   unconditional `b` is aliased to its target instead of aborting.
4. `src/heap.cpp`: faithful baseline (no game-function overrides) plus an init-table
   audit that reports unresolved entries with their guest bytes at startup.
5. Debug CRT abort dialog disabled in `src/main.cpp` so crashed runs exit instead of hang.

## Tooling

- `tools/build.ps1`, `tools/run_game.ps1`, `tools/run_in_job.ps1`: everything runs inside
  a kill-on-close Job Object; interrupted builds no longer leave zombie `clang.exe`.
- `tools/kill_orphan_clang.ps1`: reaps leftovers from older sessions.
- `tools/audit_config_functions.py`: validates config entries against the image.
- cdb scripts under `out/build/win-amd64-debug/runs/` capture the SDK's OutputDebugString
  log channel, break on abort, and dump guest memory (guest addr + 0x100000000).

## Progress after the clean regeneration (2026-09-28, later)

- Regen with the clean config: 152 files, 60,707 functions, **0** unresolved-branch sites.
  Two follow-ups were needed: the codegen emitted a `{ 0x0, __imp__KeQueryInterruptTime }`
  mapping entry (the runtime stops at address 0, so nothing was registered; now skipped in
  `phase_register.cpp`), and `main.cpp` never set `RuntimeConfig.kernel_init`, so the
  xboxkrnl/xam/xbdm kernel modules and XAM app dispatch were never created
  (`NetDll_XNetStartup` asserted on `GetKernelModule("xam.xex")`).
- A debug-CRT `assert()` in this WIN32 app opens a modal dialog that silently parks the
  guest thread; `main.cpp` now routes asserts/aborts to stderr, and
  `tools/stack_snapshot.ps1` attaches cdb after N seconds to dump all stacks.
- With those fixed the game's real `main()` runs, creates **GameThread** (0x822EA928) and
  an XRNM thread, registers XAM notify listeners and the XAudio render client, and tries
  to open `D:\lhdebug.log`. The next stop was a 24-byte vtable method (0x82CD8650) that
  discovery missed: its vtable lives in the .rdata region *below* .text.
- `tools/find_missing_functions.py` scans the image for pointer/lis-addi targets that are
  not in the mapping table and look like function starts; 154 such entries were added to
  `Fable2_config.toml` (168 total) for the next regeneration.
