# Settings reference (Fable2.toml)

[Documentation index](README.md) | [Current status](status.md) | [Build guide](building.md)

Fable2RE reads its runtime settings from `Fable2.toml` beside `Fable2.exe`. The project ships a template,
[`Fable2Recomp/config/Fable2.default.toml`](../Fable2Recomp/config/Fable2.default.toml). It holds the settings that the
automated checks ran with, without the developer diagnostics. This page lists every key in the template, what it
does, its compiled default and the evidence behind the template value. It also lists the main keys left out of the
template and the known issues that affect settings.

Status words follow the [project plan](../research/findings/2026-10-04-full-native-plan.md): *implemented* (code
exists), *built*, and *verified* (an automated run passed with the setting active). *Manual* means only hand-played
or scripted sessions outside the automated checks exercised the setting.

## Where settings come from

- **The build installs the template.** After each link of the `Fable2` target, a post-build step
  (`Fable2Recomp/config/install_default_config.cmake`) copies the template to `Fable2.toml` beside the exe **only
  if that file does not exist yet**. The `config` step of `tools/setup_all.ps1` does the same before it builds.
  Neither overwrites an existing `Fable2.toml`, whether that holds your edits, a developer's hand-written settings
  or a file saved by the F4 overlay. To get the shipped defaults back, delete `Fable2.toml` and do one of these:
  copy `Fable2Recomp/config/Fable2.default.toml` to `Fable2.toml` beside the exe; run
  `cmake -DSRC=Fable2Recomp/config/Fable2.default.toml -DDST=<exe folder>/Fable2.toml -P Fable2Recomp/config/install_default_config.cmake`;
  or run `powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -From config -To config -Force config`.
  A plain rebuild does not restore the file: the post-build step runs only when the exe is relinked, and
  `setup_all.ps1` skips its `config` step while the template and its other inputs are unchanged.
- **Without any `Fable2.toml`, the compiled defaults apply:** the emulated Xbox GPU instead of the native renderer,
  the "cave" echo, 30 fps and no keyboard. A copied exe with no settings file gets these defaults. The lifted-code
  fallback is the only setting whose compiled default is already safe: `lifted_disable_ranges` defaults to the
  XAudio2 library range.
- **Format.** The file uses flat `key = value` pairs, one per setting (cvar) name. Do not use `[sections]`: the
  loader turns `[t] k` into the name `t_k`. Unknown names are skipped. The warning
  `Config: unknown cvar '<name>'` is written before the log file opens, so it appears only in a debugger's output
  (for example DebugView), not in `fable2.log`. A TOML syntax error makes the game ignore the whole file, also
  without a line in `fable2.log`, which still says `Loaded config:` because it checks only that the file exists. To
  confirm that your file took effect, check the `cvars: log_level=... mnk_mode=...` line near the top of
  `fable2.log`.
- **Precedence (later wins).** The game first applies command-line `--name=value` arguments and `REX_<NAME>`
  environment variables (for example `REX_VBLANK_RATE_HZ`), then `Fable2.toml`, then `F2_CVARS` (unattended test
  runs, `src/autotest.cpp`). `src/main.cpp` loads the file after the command line, so **a key present in
  `Fable2.toml` cannot be overridden from the command line**. Edit the file instead.
- **F4 settings overlay.** The overlay's "Save to config" button rewrites `Fable2.toml` with only the values that
  differ from the compiled defaults. Comments are dropped, and so are keys equal to a compiled default; the
  compiled default then applies, so the game behaves the same. One exception matters to tools: while
  `lifted_disable_ranges` holds its default `82C40000-82CF8E10`, the saved file loses that line. Add it back before
  using `tools/lift/bisect_ranges.py`, which rewrites that line and stops with an `AssertionError` when it is
  missing. The commented template stays in `Fable2Recomp/config/`.

## What "verified" covers

The unattended checks (`tools/autotest.py --scenario menu|load|play`, also run by `tools/lift/full_cycle.ps1`)
start the release build with no setting overrides, so they use the `Fable2.toml` in
`Fable2Recomp/out/build/win-amd64-release/`. On the development machine that file was last changed on 2026-10-04 at
00:27, before every recorded pass:

- 2026-10-04: menu, save-load and play ([plan](../research/findings/2026-10-04-full-native-plan.md));
- 2026-10-05 and 2026-10-07: menu, save-load and play ([status](status.md)).

The logs of the 2026-10-07 runs show the settings in effect: `native renderer: active`,
`GPU command processor not created`, `native gpu sync: active`, `MnK input driver initialized` and
`lifted code: on, ranges off: 82C40000-82CF8E10`.

The checks cover:

- booting and the menus;
- loading a save;
- about two minutes of scripted controller play (movement, camera, attacks and the pause menu);
- snapshots scored for scrambled frames;
- a log scan for critical lines;
- a check that the game produces sound.

They do **not** cover keyboard and mouse input (the script drives a virtual controller), frame rate, audio quality,
fullscreen or long play sessions.

## Keys in the template

### Input: keyboard and mouse

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `mnk_mode` | Keyboard and mouse act as controller 1 ([bindings](#key-bindings)) | `false` | `true` | Driver active in the verified runs. Keys exercised manually on the September build: Space as A through the menus and New Game ([title screen finding](../research/findings/2026-09-28-title-screen-reached.md)) |
| `mnk_sensitivity` | Mouse-to-right-stick sensitivity (0.01 to 10) | `1.0` | `1.0` | Manual |
| `mnk_invert_y` | Invert mouse Y (camera pitch) | `false` | `false` | Manual |
| `mnk_raw_input` | Raw (unaccelerated) mouse motion for the camera | `true` | `true` | Manual |
| `mnk_mouse_deadzone` | Stick deflection added to any mouse motion so small movements clear the game's stick deadzone (0 to 0.9) | `0.25` | `0.25` | Manual |
| `mnk_mouse_smoothing` | Smoothing between polls (0 = raw, up to 0.95) | `0.3` | `0.3` | Manual |
| `mnk_mouse_exponent` | Response curve for mouse speed (0.2 to 3; below 1 boosts small movements) | `1.0` | `1.0` | Manual |
| `keybind_walk` | Key held to walk instead of run | `"Control"` | `"Control"` | Manual |
| `mnk_walk_scale` | Left-stick deflection while walking (0.1 to 1) | `0.45` | `0.45` | Manual |

### Window

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `window_width`, `window_height` | Window client size at startup. The game renders 1280x720 and is scaled to fit | `1600`, `900` (`src/main.cpp`) | `1600`, `900` | Verified (window size of the checked runs) |
| `fullscreen` | Start fullscreen. F11 or Alt+Enter toggles it while playing | `false` | `false` | Implemented (`src/main.cpp`); not covered by the checks |

### Frame pacing

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `vblank_rate_hz` | Guest vblank interrupt rate. The game draws one frame every two vblanks: `0` (the 60 Hz video mode) gives the console's 30 fps; `120` targets 60 fps | `0` | `120` | Verified as a setting: the checks pass with it. Game speed at 60 fps is **not established** ([known issues](#known-issues-that-affect-settings)) |
| `vsync` | Pace on the vblank. `false` fires a vblank every 1 ms, which runs uncapped and is meant for measurements only | `true` | `true` | Verified |

### Rendering

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `native_renderer` | Native D3D12 renderer driven by the game's D3D calls. `false` = the emulated Xbox GPU | `false` | `true` | Verified ([native roadmap](../research/findings/2026-10-01-native-roadmap.md)) |
| `gpu_command_processor` | Create the emulated GPU command processor. `src/main.cpp` forces it back on when `native_renderer = false`, so the fallback needs only one key changed | `true` | `false` | Verified (`native_gpu_sync` handles synchronisation; [CP retirement](../research/findings/2026-10-01-retiring-the-command-processor.md)) |
| `native_render_thread` | The native renderer runs on its own thread, in parallel with the game | `true` | `true` | Verified |
| `native_state_cache` | Skip render-state calls that would not change anything | `true` | `true` | Verified |
| `native_skip_d3d_flush` | Skip the Xbox D3D library's command-buffer writers inside draws; the renderer reads the device state directly | `true` | `true` | Verified ([CP retirement](../research/findings/2026-10-01-retiring-the-command-processor.md), plan step 1) |
| `native_occlusion_queries` | Real GPU occlusion-query results. `false` = every query reports "visible", like the emulated path | `false` | `false` | Verified with `false`. `true` is unverified |

### Emulated GPU (only with `native_renderer = false`)

These keys have no effect while the native renderer is on, because the emulated command processor is not created.
The template keeps the values of the checked configuration so that switching `native_renderer` off gives the known
fallback. The emulated path has not been checked with the current lifted build.

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `async_shader_compilation` | `true` skips draws whose pipeline is still compiling, so objects flicker and pop in. `false` compiles first: a one-time hitch, then the cache serves later runs | `true` | `false` | Manual, September 2026 (emulated path) |
| `readback_memexport` | CPU readback of every memexport draw (about 40 per frame, each a GPU sync) | `true` | `false` | Manual, September 2026 |
| `occlusion_query_enable` | Real host occlusion queries. Each stalls on a GPU fence, thousands per frame | `true` | `false` | Manual, September 2026 ([hooking guide](modding-guide.md) section 1). The native renderer also forces it off |

### Audio

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `audio_reverb_disable` | Silences the game's environmental reverb (an XAudio2FX reverb inside the game, [reverb finding](../research/findings/2026-09-28-reverb-echo-and-draw-fastpath.md)). The development notes trace the "cave" echo to this effect running on its default parameters (100% wet), because the game's zone parameters never reach it; that conclusion has no findings record yet | `false` | `true` | Active in the verified runs, which passed the no-sound check. Echo removal confirmed by ear on 2026-09-28. A workaround: see [known issues](#known-issues-that-affect-settings) |
| `xconfig_audio_flags` | Audio output setting reported to the game: `0` = stereo only (drier mix, no surround reverb buses), `65537` (0x00010001) = surround capable | `65537` | `0` | Active in the verified runs; its effect on the mix has not been measured. It did not cause or cure the echo |

### Lifted (readable) game code

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `lifted_code` | Run the lifted, readable C++ wherever it exists. `false` = the recompiled originals everywhere, used to compare behaviour ([lifted code](lifted-code.md)) | `true` | `true` | Verified. Project rule: keep it on by default |
| `lifted_disable_ranges` | Guest address ranges whose lifted functions run recompiled: comma-separated hex `lo-hi` pairs or single addresses. **A value you set replaces the default, so keep `82C40000-82CF8E10` in it** | `"82C40000-82CF8E10"` | `"82C40000-82CF8E10"` | Verified. Lifted, the XAudio2 library makes a null vtable call on level load and hangs cutscenes ([plan](../research/findings/2026-10-04-full-native-plan.md), Phase A "Open") |

Keep `lifted_disable_ranges = "..."` on a line of its own, with no comment after the value.
`tools/lift/bisect_ranges.py` rewrites exactly that line. An F4 "Save to config" removes the line while it holds
the default ([F4 settings overlay](#where-settings-come-from)); add it back before bisecting.

### Logging

| Key | Effect | Code default | Template | Status |
|---|---|---|---|---|
| `audio_reverb_log` | Log the reverb parameters whenever the game changes them | `true` | `false` | Logging only; the verified runs had it on |
| `thread_cpu_stats` | Log the busiest threads' CPU load every 5 s | `true` | `false` | Logging only; the verified runs had it on |
| `audio_level_log` | Log the audio mix's peak level every 2 s | `true` | `true` | Kept on: `tools/autotest.py` reads these lines for its no-sound check |

## Key bindings

With `mnk_mode = true`, these defaults apply (`rexglue-sdk/src/input/mnk/mnk_input_driver.cpp`). The mouse moves
the right stick (the camera). Each binding is a key such as `keybind_a = "Space"`. A binding accepts several keys
separated by `|` (for example `"E|Enter"`) and the mouse names `LMB`, `RMB`, `MMB`, `Mouse4`, `Mouse5`, `WheelUp`
and `WheelDown`. These keys are not in the template; add a line to change one.

| Controller | Key | Setting |
|---|---|---|
| A / B / X / Y | Space / Shift / R / E | `keybind_a`, `keybind_b`, `keybind_x`, `keybind_y` |
| Left stick | W A S D, press C | `keybind_lstick_up` / `_down` / `_left` / `_right`, `keybind_lstick_press` |
| Right stick press | Middle mouse button | `keybind_rstick_press` |
| Left / right trigger | Right / left mouse button | `keybind_left_trigger`, `keybind_right_trigger` |
| Left / right shoulder | Q / F | `keybind_left_shoulder`, `keybind_right_shoulder` |
| D-pad | Arrow keys | `keybind_dpad_up` / `_down` / `_left` / `_right` |
| Start / Back | Escape / Tab | `keybind_start`, `keybind_back` |
| Walk modifier | Control | `keybind_walk` |

## Keys not in the template

The compiled default applies to each of these unless you add the key.

| Key | Code default | Why it is left out |
|---|---|---|
| `resolution_scale`, `anisotropic_override` | `1`, `3` | They affect only the emulated GPU's texture cache, which the native renderer does not create. The native renderer takes anisotropic filtering from the game's own sampler settings (`native/renderer.cpp`), so these keys do nothing with the template |
| `native_render_frames_ahead`, `native_realtime_shadows`, `native_async_pipelines`, `native_pipeline_wait_ms`, `native_gpu_sync` | `1`, `true`, `true`, `8`, `true` | Native renderer tuning. The verified runs used these defaults ([area performance](../research/findings/2026-10-02-area-perf.md)) |
| `audio_stereo_fold` | `true` | Folds the game's 5.1 mix to stereo. Keep it on with headsets that expose a virtual 7.1 endpoint, which otherwise spatialise the rear and reverb channels into an echo. Set `false` for real 5.1/7.1 speakers |
| `audio_mute`, `input_backend`, `mnk_user_index` | `false`, `"sdl"`, `0` | Ordinary options. The SDL backend handles gamepads, and the keyboard driver feeds controller slot 0 |
| `mods_native` | `true` | Loads native mod DLLs from `<exe folder>/mods/<Mod>/native/*.dll` (installed by `tools/mods.py apply`; [making mods](making-mods.md)) |
| `rewrites_disabled`, `lifted_disable_files` | `""` | Switch hand-written or lifted code back to the originals when looking for a problem ([C++ conversion](conversion-guide.md), [lifted code](lifted-code.md)) |
| `dev_debug_menu` | `false` | Re-enables Lionhead's in-engine debug menu. Not yet verified as fully functional ([debug menu](debug-menu.md)) |
| `log_level`, `log_noisy`, `log_max_file_size_mb`, `log_max_files` | `"info"`, `false`, `5`, `20` | Logging. Developers use `log_level = "debug"` for the 5 s statistics lines ([hooking guide](modding-guide.md) section 4) |
| `profile_sampler`, `native_draw_profile`, `d3d_probe`, `cpu_sampler_thread`, `cpu_sampler_interval_us`, `trace_indirect_calls`, `trace_indirect_lo`, `trace_indirect_hi`, `audio_api_trace` | off / empty | Profilers and tracers. Each costs frame time and fills the log |
| `audio_dump_raw`, `dump_shaders`, `native_trace_rolling`, `d3d12_debug`, `d3d12_break_on_error` | off / empty | Dumps and debug layers for investigations; slow |
| `protect_zero` | `false` | Low-level memory protection; the verified runs used the default |

## Known issues that affect settings

- **Crash when the game closes.** An intermittent access violation (exit code `C0000005`) can occur while the
  process shuts down, after the game itself has stopped. It is open: recorded 2026-10-04 and still listed as a next
  step ([plan](../research/findings/2026-10-04-full-native-plan.md)). No setting is known to cause or avoid it.
  `tools/autotest.py` records it as its own result class, `OK_EXIT_CRASH` (exit code 0, or 3 with
  `--strict-exit`), counted in the run summary and the ledger (`build/validation/ledger.jsonl`); a hang after the
  exit step counts the same way.
- **Save truncation on a forced kill.** Ending the process while the game writes its autosave can truncate the
  save. On the development machine, on 2026-09-28, a scripted session that was killed at its time limit left
  `Hero000/mainsave.bin` cut to 131,072 bytes. "Continue" then crashed about 47 s into loading. Close the window
  normally and give the game time to finish saving; do not end it from Task Manager; back up your saves.
  `tools/run_game.ps1` therefore asks the window to close and waits 8 s before it kills the process, and
  `tools/autotest.py` restores a known-good save before the `load` and `play` runs (it refuses to run them without
  one: create it from your own save slot with `python tools/autotest.py --make-golden`, and it backs up the slot it
  replaces). There is no findings record for this yet; the
  evidence is the comment in `tools/run_game.ps1`.
- **Game speed at 60 fps is not established.** `vblank_rate_hz = 120` doubles the guest vblank rate. Nobody has
  measured whether the game's simulation follows the frame count or measured time
  ([hooking guide](modding-guide.md) section 5). Where the CPU cannot keep up, the frame rate stays below 60: towns
  ran at about 23 fps on the development machine on 2026-10-02
  ([area performance](../research/findings/2026-10-02-area-perf.md)). If animation or game speed looks wrong, set
  `vblank_rate_hz = 0` for the console's 30 fps pacing, and report what you saw.
- **The cave-echo fix is a workaround.** `audio_reverb_disable = true` removes all environmental reverb, including
  where the game intends it. The proper fix, feeding the reverb the game's zone parameters, is open
  ([reverb finding](../research/findings/2026-09-28-reverb-echo-and-draw-fastpath.md)).
- **The XAudio2 library cannot run lifted.** Lifted, it crashes on level load and hangs cutscenes, so it always runs
  recompiled through `lifted_disable_ranges`. The native audio mixer planned in Phase C1 of the
  [plan](../research/findings/2026-10-04-full-native-plan.md) removes this exception.
- **Command-line overrides lose to the file.** Because `Fable2.toml` is loaded after the command line, a
  `--lifted_disable_ranges=...` argument has no effect while the file sets that key. This also applies to the one
  `tools/lift/bisect_lifted.py` passes. To override a key for one test run, use `F2_CVARS` (as `tools/autotest.py`
  and `tools/lift/auto_bisect.py` do) or edit the file.

## For developers

- The template is the reference configuration for fresh machines: the `config` step of `tools/setup_all.ps1`
  installs it beside the release preset's exe before the `build` step, and the `Fable2` target's post-build step
  installs it after a link when `Fable2.toml` is still missing. Change it when a setting is verified in a new
  configuration, and update this page with the evidence.
- The development machine's hand-written `out/build/*/Fable2.toml` files are not touched. Each build folder installs
  the template only when its own `Fable2.toml` is missing.
- `Fable2Recomp/CMakeLists.txt` is marked as managed by the SDK's `rexglue migrate`. If a migration rewrites it,
  restore the `POST_BUILD` block that calls `config/install_default_config.cmake`.
