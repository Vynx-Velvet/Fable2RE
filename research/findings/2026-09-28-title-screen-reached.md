# The faithful build reaches the Fable II title screen (2026-09-28)

## Summary

With the clean codegen config (see `2026-09-28-foreign-config-root-cause.md`), no game
hooks, and three runtime fixes in `Fable2Recomp/src/main.cpp`, the recompiled
`Fable2.exe` now boots the real game code all the way to the title screen:

| Time after launch | What the window shows |
|---|---|
| ~12 s | Microsoft Game Studios logo |
| ~20-30 s | Lionhead Studios hand-drawn intro |
| ~40 s | "FABLE II - Press A to start" over the animated title tree |

Debug overlay at the title screen: ~300-385 draws/frame, 4.6-5.6k verts, TexCache 51-141,
PipeCache 36-82. Bink videos (`data/art/videos/*.bik`) decode and play through the
recompiled decoder.

Captured with `tools/run_with_screenshots.ps1 -Seconds 125 -Tag shots2 -At 8,12,...,120`
(frames in `Fable2Recomp/out/build/win-amd64-debug/runs/shot_shots2_*.png`).

## What it took after the config fix

1. `config.kernel_init = rex::kernel::InitializeKernel` in the RuntimeConfig. Without it no
   xboxkrnl/xam kernel modules exist and `NetDll_XNetStartup` (called from a C++ static
   initializer) asserts in `GetKernelModule("xam.xex")`.
2. `InputSystem::AttachWindow(window)` after the window is created, exactly as
   `rex_app.cpp` does. Without it the SDL driver's events/gamepad subsystems are never
   initialised and the first `XamInputGetState` poll asserts.
3. Debug-CRT `assert()` routed to stderr (`_set_error_mode(_OUT_TO_STDERR)` +
   `_CrtSetReportMode`). In a WIN32 GUI app the default modal box silently parks the guest
   thread and the run looks like a hang.
4. SDK: `ResolveTailJumpThunk` in `function_dispatcher.cpp` (8-byte `b __imp__KeTlsAlloc`
   thunk at 0x82CAC3C8 that has no .pdata entry), `phase_register.cpp` skipping imports
   with address 0, `sdl_input_driver.cpp` returning `X_ERROR_DEVICE_NOT_CONNECTED` instead
   of asserting when no window is attached.

## Thread picture at the title screen (from `~*kb` under cdb)

GameThread pumps `XNotifyGetNext` / critical sections; "3D Engine" (sub_8236C520) runs the
render-state flush loop sub_82237378; "GPU Commands" executes `DRAW_INDX_2` packets and
`WAIT_REG_MEM`; XrnmThread, Texture Streamer, Cloth Simulation, VFS Request
Manager/Finalizer, Permanent Bank Mounter and Front end audio loading all exist and match
the Xenia thread list in `xenia_debug.log`. The tail of the kernel trace is the game's
async reader re-issuing the same three `NtReadFile` completions (IOSB 0x4218B1B8/1CC/1E0)
which is normal streaming, not a stall.

## Open issues

- One run stalled on the Lionhead logo with the overlay counters frozen (Dispatch 29421 at
  both 40 s and 55 s) while the next run got to the title screen. Intermittent; use
  `tools/stack_snapshots.ps1 -At 15,45` (two snapshots of the same process) when it recurs.
- `XFileSectorInformation` is a stub (110 calls during boot); harmless so far.
- `CommandProcessor::WriteRegister index out of bounds: 28685` warning once per boot.
- Keyboard input needs `mnk_mode = true` in `Fable2.toml` (Space = A, Esc = Start). The
  SDL driver only handles gamepads.

## Tooling added

(2026-10-12: the screenshot and key-press scripts below were retired. They focused the game window and injected
desktop input; `tools/autotest.py` now drives the game from inside its own process.)

- `tools/screenshot.ps1` - PrintWindow capture of the game window (works when occluded).
- `tools/run_with_screenshots.ps1` - bounded run with screenshots and key presses at
  offsets (`-Keys '45:Space'`).
- `tools/send_key.ps1` - focus the game window and press a key.
- `tools/stack_snapshots.ps1` - attach cdb several times to one process and dump stacks.

## Follow-up: why Fable2.toml never applied (found 2026-09-28 14:00)

Fable2Recomp/CMakeLists.txt (SDK-generated template) linked `rex::core rex::system
rex::kernel rex::graphics rex::ui`. `rex::system`/`rex::kernel` are aliases of the shared
`rexruntime` DLL, but `rex::core`, `rex::graphics` and `rex::ui` are OBJECT libraries that are
*also* compiled into that DLL. The link line for Fable2.exe therefore contained
`cvar.cpp.obj`, `logging.cpp.obj`, the whole graphics system, etc. next to `rexruntimed.lib`:

- two cvar registries: `rex::cvar::LoadConfig` (exe copy) knew `log_level` but reported
  `unknown cvar 'mnk_mode'` (registered only inside the DLL by the input driver);
- two logging registries: exe-side categories honoured the config (GPU trace flood) while
  DLL-side code (input, audio) logged at the compiled-in default and never reached fable2.log;
- REXCVAR_GET(log_noisy) inside the DLL stayed false, so no kernel import traces.

Fix: link only `rex::runtime` (+ dlmalloc). REXCVAR_GET expands to an exported accessor
function, and the exe-side sources (rex_app.cpp, windowed_app_main_win.cpp, main.cpp) make
no ImGui/SDL calls, so nothing private to the DLL is needed. Symptom to remember: a cvar that
"does not take effect" or a log category that ignores log_level means a duplicated SDK object
in the host.

Diagnostics added meanwhile (kept, debug level): XamInputGetCapabilities/GetState first calls
and button-mask changes in xam_input.cpp; MnK key-down and focus events in
mnk_input_driver.cpp. The MnK driver did receive the Space key with focus=true; only
`enabled` (mnk_mode) was false.

## After the link fix (2026-09-28 14:08): main menu and New Game

With Fable2.exe linked only against rex::runtime, `Config: mnk_mode = true` is applied and the
MnK driver reports Space as A (`XamInputGetState user=0 -> 0x0 buttons=0x1000`). Scripted run
`tools/run_with_screenshots.ps1 -Cdb -Seconds 110 -Tag key6 -At ... -Keys '60:Space','78:Space'`:

| Time | Screen |
|---|---|
| 45 s | Title, "Press A to start" |
| 64 s | Main menu: New Game / Downloadable Content / Language / Subtitles (A cursor on New Game) |
| 78 s | New Game: XamShowDeviceSelectorUI (headless), save enumeration (`save:\saveuid.bin` missing, fresh profile), XGIUserSetContextEx presence contexts |
| 105 s | "Loading Bowerstone Old Town" loading screen with the Rose render and snow particles |

No new stubs or errors during the flow; the level load creates the expected EDRAM render
targets (1280x1024 2xMSAA colour/depth, 640x1024 4xMSAA depth, shadow-map style 80x8192 /
320x8192 targets).

## Cave echo, random glitches, freeze-with-pop-in (user report 2026-09-28 ~15:40)

**Audio "everyone in a cave":** SDK v0.8.0's 5.1-to-stereo fold
(`include/rex/audio/conversion.h`) added the surround channels at full gain (and had
bl/br swapped): `L = (fl + bl + 0.5 fc) / 2.5`. The game's XAudio mix puts the reverb/ambience
bus mostly on the rear channels, so a stereo device heard the reverb louder than the dry signal.
Upstream fixed it in 4c31fcc (ITU-style fold: 0.707 centre/surround, LFE dropped, clamp). Also
cherry-picked five XMA decoder fixes (loop wraps emitting garbage / dropping frames, MDCT tail
on context reuse, ffmpeg flush on release, inline decode of kicked contexts).

**Random visual glitches / pop-in:** `async_shader_compilation=true` (default) makes the D3D12
command processor skip draws whose pipeline is still compiling, so meshes flicker in and out
while new materials appear. Set to `false` in Fable2.toml (compile synchronously). To make that a
one-time cost, main.cpp now enables persistent shader/pipeline storage (`cache/` next to the exe,
same sequence as ReXApp: PrepareModuleLaunch -> InitializeShaderStorage -> Resume). Also
cherry-picked 6124b36 (single-buffered page valid flags: fixes stale CPU->GPU page refresh),
8e6baae, acb88c3.

**Freezes:** shader/pipeline creation bursts (up to 100 pipelines in 5 s) are the visible hitches;
the persistent cache removes them after the first visit. Steady-state fps (8-20 in the town) is
bound by the host GPU command processor thread (the game's render thread spins in
sub_82242628 waiting for the ring-buffer read pointer). Profiling that thread is the next step
(win-amd64-relwithdebinfo has symbols; tools/run_with_screenshots.ps1 -Snapshots +
tools/aggregate_stacks.py).

SDK now lives on branch `fable2-local` (local patches committed as 06c60f0, then the cherry-picks,
then 2dbfef5 adapting PrepareForTraceDownload). Upstream v0.10.0 commits not taken: build-system
(precompiled headers, rexgpu-xenos plugin split), Vulkan/MoltenVK, string/platform refactors.

## Performance investigation (2026-09-28 16:00-16:35)

Measurements (release build, town, Bowerstone Old Town, i7-4770K 4c/8t + RTX 2070):
- `vsync=true` shows 30 fps in the swap counter but the game presents duplicates; uncapped
  (`vsync=false`) the real rate in town is 11-17 fps. Intro videos run 60-118 fps uncapped.
- GPU 3D engine utilisation 7-19% (Get-Counter): the host GPU is nearly idle.
- Host "GPU Commands" thread idle ~50% (80 one-shot cdb samples); the game's render thread
  ("3D Engine", sub_8236C520) spins in sub_82242628 on the ring-buffer RPTR writeback, the
  SDK wrote that pointer back only once per submitted range -> serialised handshake. Fixed in
  command_processor.cpp (writeback after every packet). Alone: no fps change in town.
- ~2800 memexport draws per 5 s in town; `readback_memexport=true` (SDK default) copied every one
  back to the CPU with fence syncs (fast path falls back to a full GPU drain when the previous
  submission is incomplete). `readback_memexport=false` (Xenia default): readbacks 0, town
  ~10% faster, one stretch 23 fps vs 12.
- All-thread samples: an unnamed guest worker (handle F8000048, started from sub_82CDB248, hot in
  sub_82C5xxxx-82C6xxxx) is running in 7/8 samples, GameThread 5/8, Texture Streamer 4/8, render
  thread 3/8, host CP 5/8: the 4 physical cores are saturated. The write-watch mechanism adds
  ~600 page faults/s + VirtualProtect calls on the CP thread.
- Sampling itself costs ~0.5 s per cdb attach; fps numbers taken while sampling are invalid.

Tools: tools/sample_thread.ps1 (one-shot cdb per sample, -AllThreads), tools/thread_activity.py,
tools/thread_cpu.ps1 (per-thread CPU % with thread descriptions), tools/summarize_run.py (5 s
stats: GPU swaps, audio callback, SDL queue, XMA, memexport, faults).

## 16:40-17:00: what did and did not help; fast test recipe

- Per-packet RPTR writeback: no fps change. `readback_memexport=false`: ~10%. Pause+yield hook on
  the D3D GPU-progress poll (sub_82B9BF90, whose 8x db16cyc the codegen emitted as nothing; the
  codegen now emits REX_PAUSE() for a future regen): no fps change.
- Per-thread CPU (relwithdebinfo, town): 3D Engine 85%, GameThread 83%, GPU Commands 83%, XACT
  engine worker (F8000048) 38%; GPU 3D engine 7-19% busy. The host command processor thread is
  100% busy in real per-draw work (IssueDraw: pipeline state lookups, UpdateBindings, texture
  cache lookups, WriteRegister); render thread waits on it, game thread waits on the render thread.
  => the SDK's D3D12 command processor per-draw CPU cost is the frame-rate limit on an i7-4770K.
- Uncapped town fps 11-17 (release); `vsync=true` fakes 30 by duplicate presents.
- Intro videos skip with A; "Continue" from the autosave loads Bowerstone directly:
  `tools/run_town.ps1` (Space 6/12/18/26 s, Down 30 s, Space 33 s) -> in-game by ~80 s.
- Audio: XACT + XAudio2 reverb ("RegionEnvironmentalReverb" per region) run as recompiled code on
  the F8000048 worker; the dump's dialogue window shows fixed 22.4/33/55.5 ms echo lags. Whether the
  console sounds the same needs a Xenia listen (user) or a loopback capture (Virtual Audio Cable
  "Line 1" exists on this machine).
