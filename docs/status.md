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
- *Second DeepSeek round (2026-10-17).* 491 more functions rewritten with the promotion check and promoted into
  48 modules; 237 of them reviewed before the model account ran out (2 demoted), so 1,441 of 1,695 promoted
  functions are recorded OK and the other 254 wait for review. All 1,695 pass the strict re-check; the build with
  them passes the menu, load and play checks
  ([round](../research/findings/2026-10-17-deepseek-round-491.md)).
- *Look-alike copies (2026-10-18/19).* 37 representatives of look-alike groups (rewritten in Freebuff agent
  sessions, reviewed by Claude; 17 more sent back) were carried over to 5,900 other members of their groups by
  `tools/rewrite/copy_lookalikes.py`. All 5,937 pass the strict check and are promoted; a sampled review of the
  copies (three per group, 108) found every one right, so 7,378 of 7,632 promoted functions are recorded OK. The
  build with them passes the menu, load and play checks (one load run crashed while closing, as one run did on
  2026-10-15 before them; two more load runs closed cleanly)
  ([finding](../research/findings/2026-10-18-lookalike-functions.md)).
- *Readability measured (2026-10-19).* Passing the check and a review says a rewrite behaves like the original,
  not that a person can read it, and most cannot yet be read: of the 7,378 reviewed rewrites, 4,294 still pass
  values through the CPU registers (`ctx.r11 = ...`) or keep the stack-frame bookkeeping, and nearly all the rest
  still call functions and use globals, variables or fields known only by address or offset. Progress now counts
  as human-readable only readable C++ with every name (`tools/rewrite/readability.py`): 88 functions, 0.2%, not
  the 18.1% published earlier the same day, which counted every reviewed rewrite. The same day: the start-up and
  shut-down functions of global strings named after their global (4,014), the readable form (register code the
  analysis shows unneeded removed, the frame and atexit in documented helpers; 3,410 functions, each re-checked)
  and a naming step (1,475 variable names in modules; function and field names into the dictionary, applied with
  the next re-lift): 4,072 of the 7,378 reviewed rewrites are readable C++ with every name, 10.0% of the game's
  functions with the hand-written ones. Build and game checks (menu, load, play) pass
  ([finding](../research/findings/2026-10-19-readability-levels.md)).
- *Correction (2026-10-20).* The readable form of 2026-10-19 dropped register hand-overs whose value was a frame
  address or a variable, and (its first run) hand-overs before a call through a pointer: 362 promoted functions,
  published in that day's progress. One of them, `CBoneDriverGroup_ApplyTransformToBoneDrivers`, handed
  `BoneDriver_Update` stale pointers and crashed Havok 8 s after Continue on the save the game writes at New Game
  start; the strict check cannot see a dropped hand-over of a frame address (its stand-in callees read nothing),
  and the game checks did not reach that code. Found with `tools/lift/bisect_crash.py` (13 runs); the rule is
  fixed, 359 of the 362 are written again with it and pass the strict check, 3 are demoted. The game checks now
  include `newgame` (the prologue through the intro cutscene) and `resume` (Continue on the New Game-start save);
  the suite of five passes. The count of readable, named functions is unchanged, 15.2%
  ([finding](../research/findings/2026-10-20-prologue-and-continue-crash.md)).
- *Reviews before the next look-alike promotion (2026-10-20, evening; no new game build yet).* The 91 look-alike
  representatives of the Freebuff packets 0292-0300 and 0308/0309 (standing for 2,534 look-alikes) were reviewed
  and corrected by review agents and checked again: 86 corrected in place (comments and names mostly, three
  behaviour faults), 5 good, none sent back. The promotion step's own "cleaner form" had the same hole as the
  readable form (hand-overs of variables dropped when other statements separate them from their call): 58
  promoted functions were affected, 55 are written again with the fixed rule and pass the strict check, 1 was a
  false alarm, 2 were already fixed; the 3 functions demoted in the morning are promoted again from their reviewed
  texts. The 254 functions of the 2026-10-17 DeepSeek round that had no review are now reviewed (24 agents, one
  per module): 109 corrected for behaviour (dropped hand-overs, 64-bit values cut to 32, missing floating-point
  mode switches, atomic counts made plain), 115 for names only, 30 good; every correction passes the strict
  check, so all 9,624 promoted functions are recorded OK
  ([finding](../research/findings/2026-10-20-freebuff-reps-review-and-cleaner-form.md)).
- *Second look-alike promotion (night of 2026-10-20/21).* The 91 reviewed representatives were copied to 2,434
  look-alikes (`copy_lookalikes.py`, strict check on every copy, none failing; 100 members refused for literals
  with several meanings or a shape apart; 40 refusals lifted by renaming variables the reviewers had named after
  a callee, 26 by a copier fix: declared constants were aligned by address order, which crosses between
  look-alikes, and showed only where a rewrite had folded a page base and an offset). 2,524 functions promoted in
  five chunks, a sampled review of 264 copies by eight agents found every one right, and all 12,148 promoted
  functions are recorded OK. The build with everything of the day (the repaired 55, the re-promoted 3, the 224
  corrected, the 2,524 new) passes menu, load, play and newgame; the resume check plays through and the process
  crashes while closing, in three runs of three, as it did in both runs on the afternoon build before any of
  these changes: an open teardown crash after a Continue, not a regression of the promotion
  ([finding](../research/findings/2026-10-20-freebuff-reps-review-and-cleaner-form.md)).
- *Checks.* Game checks can no longer pass without snapshots or on an earlier run's log; mod tools target the
  script bank the game mounts (`gamescripts_r.bnk`).

**Fable2RE is a working development port in transition toward whole-game readable C++ and a fully native PC runtime.** Windows x64 and the targeted GOTY disc executable (media ID 716F0A0D) are the current development baseline. Other editions, platforms, and complete playthrough compatibility are not established by these notes.

| Area | Evidence and current state | Remaining validation / work |
|---|---|---|
| Gameplay baseline | September/October findings record title-screen and in-world play | Repeatable regression coverage, full playthrough and save/load validation |
| Readable C++ | Health, combat, entity/handle, tuning, and debug modules exist under `src/game/` (57 functions by hand); 12,148 reviewed rewrites in the published modules ([process](promoted-code.md)); of the 7,378 measured on 2026-10-19, 4,072 are readable C++ with every name, 1,421 readable with names still to give and 1,885 still at machine level (CPU registers in the code) ([levels](../research/findings/2026-10-19-readability-levels.md)); the 2,524 copies of 2026-10-21 and the 254 reviewed that day are not measured yet | The readable form (no CPU registers in the body), then naming; whole-game reconstruction |
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
