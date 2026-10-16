# Current project status

Documentation reviewed: **2026-10-11**. This overview is based on source inspection and the linked research records; it does not represent a new full-game test run.

**Update 2026-10-05 (automated runs on the development machine, GOTY disc executable, media ID 716F0A0D):** 58,908 of about 60,360
functions are lifted to structured C++ with real signatures and each passes the differential tester; 992 fail or
cannot be compared and stay recompiled, and the 3,403 functions of the XAudio2 library range run recompiled by
switch. The unattended menu, save-load and two-minute play checks pass on that build. The naming dictionary
(`research/names/`) holds 4,396 functions, 467 classes, 845 fields and 4,781 local variables; about 7% of
functions and 8% of variables carry a meaningful name. No compatibility layer has been removed yet. Details:
[plan and position](../research/findings/2026-10-04-full-native-plan.md),
[readable-form cycle](../research/findings/2026-10-05-readable-cycle-regressions.md).

**Update 2026-10-07:** 1,233 game functions now run as model-written readable C++ accepted by the relaxed
differential check on four input profiles (`Fable2Recomp/rewritten/`, local), with menu, save-load and play checks
passing on that build; 83 rewrites are revoked and queued again with the checker's reason. Two harness faults
that had wrongly revoked 297 correct rewrites were found and fixed
([record](../research/findings/2026-10-07-difftest-wrapped-pointer-timeouts.md)). The dictionary holds 6,085
function names. Revoke / re-check / restore / retry steps: [parallel work](parallel-work.md).

**Update 2026-10-12 (fresh setups; publishing):** a fresh clone set up end to end from the disc reaches the title
screen ([record](../research/findings/2026-10-12-fresh-clone-end-to-end.md)). The class model now ships
(`research/lift/class_model.json.gz`, structure only), so a new setup lifts exactly the text the verification
manifest records and skips the 25-minute facts pass; checked on the 368 functions that differed before, not yet
in a whole setup. `tools/publish.py` publishes progress (research data, docs, reviewed promoted modules) with
every check in one command ([publishing](publishing.md)). The names of the game's global string objects, which
are its text, are no longer shipped: the setup writes them (step `globals`,
[record](../research/findings/2026-10-12-global-names-local.md)).

**Update 2026-10-10/11 (toolchain for fresh users; no new game build):**
- *Setup.* `tools/setup_all.ps1` now runs every step of the development pipeline: executable identification
  (`tools/xex_info.py`), extraction, codegen, the decrypted image, the class model, declarations and bridges, the
  lift, a filter that keeps only functions whose lifted text matches a tester-verified hash
  (`research/lift/verified.json.gz`: 57,690 functions), the default settings file and the build. Each step is
  stamped on its inputs and resumable. Implemented and checked step by step; run end to end from a fresh clone on
  2026-10-12 ([record](../research/findings/2026-10-12-fresh-clone-end-to-end.md)). Setup previously rejected every
  real disc: its only accepted hash belonged to a 100 MiB over-read copy
  ([record](../research/findings/2026-10-10-executable-identity.md)).
- *Settings.* `Fable2Recomp/config/Fable2.default.toml` (installed beside the exe when none exists) carries the
  configuration the automated checks use; the XAudio2 library range is now kept recompiled by default in code.
  Reference: [settings](settings.md).
- *Promoted readable code.* The review of the 1,210 promoted functions is recorded (2026-10-15: 1,206 OK, 935
  of them fixed, 4 demoted); the stricter check (native call, registers callers read, passed-through arguments)
  passes all 1,206, and the build with them passes the menu, load and play checks
  ([record](../research/findings/2026-10-15-promoted-review-recorded.md)). The repository holds the modules
  without the game's text (`Fable2Recomp/promoted/`); setup step `promoted` renders them from your copy, checked
  byte for byte against the published SHA-256.
- *Checks.* Game checks can no longer pass without snapshots or on an earlier run's log; mod tools target the
  script bank the game mounts (`gamescripts_r.bnk`).

**Fable2RE is a working development port in transition toward whole-game readable C++ and a fully native PC runtime.** Windows x64 and the targeted GOTY disc executable (media ID 716F0A0D) are the current development baseline. Other editions, platforms, and complete playthrough compatibility are not established by these notes.

| Area | Evidence and current state | Remaining validation / work |
|---|---|---|
| Gameplay baseline | September/October findings record title-screen and in-world play | Repeatable regression coverage, full playthrough and save/load validation |
| Readable C++ | Health, combat, entity/handle, tuning, and debug modules exist under `src/game/`; 1,206 reviewed model rewrites in 76 class modules, re-checked, built, game-checked and published without the game's text ([process](promoted-code.md)) | More modules (review, record, check, publish); whole-game reconstruction |
| Automatic lifting | Lifter and fallback controls exist; [guide](lifted-code.md) records broad function coverage | Coverage counts are generation-specific and do not measure semantic readability or full-game correctness |
| Rendering | Native D3D12 renderer, frontend, and GPU synchronization exist | Remaining packet/memory/shader dependencies; shader failures recorded on October 2 |
| Debug tools | F2 menu, Lua bridge, original-menu gate, and replacement displays implemented; about 30 commands and WinterShrine loading were reported working | Verify each command; some retail bindings are absent or empty |
| Mods | Archive/text tools, tuning overrides, native SDK and loader exist; archive round trips and apply/restore checks recorded | Broader in-game coverage and stable plugin/content interfaces |
| Local setup | `tools/setup_all.ps1` runs the whole pipeline with stamped, resumable steps and a tester-verified function filter; `tools/requirements.txt` | A first end-to-end run on a fresh machine (`tools/test_fresh_clone.ps1`, [audit](initial-commit-audit.md)) |
| Native platform services | Some functionality replaced; ReXGlue remains linked | Native audio/input/pacing/resources and removal of remaining console assumptions |

## Important limits

- The original Lionhead menu is **not yet verified as fully functional**. A menu entry can run without producing an effect when the retail implementation was removed.
- Automatic lifting and ahead-of-time compilation are **not completion of readable source reconstruction**.
- The runtime is Windows-only; there is no Linux build.
- Performance figures in research notes apply to the recorded hardware, scene, build, and settings. They are not release guarantees.
- The setup script is not a finished installer. It has run end to end once, from a fresh clone on the development machine, not yet on a machine without the toolchain. See [build caveats](building.md).

## Supporting records

- [Title screen reached](../research/findings/2026-09-28-title-screen-reached.md).
- [Native subsystem inventory](../research/findings/2026-10-01-native-roadmap.md) and [command processor work](../research/findings/2026-10-01-retiring-the-command-processor.md).
- [Debug menu and Lua investigation](../research/findings/2026-10-02-lua-debug-menu.md).
- [Decompilation and modding progress](../research/findings/2026-10-02-decomp-and-modding.md), including which builds were tested and which were not.
- [Area performance observations](../research/findings/2026-10-02-area-perf.md).

Keep implementation and verification separate when updating this page. Record the executable revision, build, scenario, and result before promoting a feature to validated status.
