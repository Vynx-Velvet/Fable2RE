# Fable2RE — reverse-engineering, hooking and profiling guide

[Documentation index](README.md) | [Current status](status.md) | [Build guide](building.md)

This developer guide includes September 28-29 measurements from the earlier runtime. Its command-processor bottlenecks and performance figures are historical; consult current status and the October findings for subsequent native-renderer work.

This is the working toolkit for changing how the game plays, behaves and runs.
Everything below was built and used during the audio-echo and frame-rate work of
2026-09-28/29; the tools live in `tools/`, the hooks in `Fable2Recomp/src/hooks.cpp`.

## 1. Builds and configs

| Preset | Exe | Use |
|---|---|---|
| `win-amd64-release` | `Fable2Recomp/out/build/win-amd64-release/Fable2.exe` | playing, quickest |
| `win-amd64-relwithdebinfo` | `.../win-amd64-relwithdebinfo/Fable2.exe` | profiling (PDBs, in-process sampler) |

Build with `tools/build.ps1 -Preset <preset> -Target Fable2` (job object, kills orphan
clang). The runtime DLL (`rexruntime*.dll`) is compiled from `rexglue-sdk/` sources by the
same build; if `Fable2Recomp/out/build/<preset>/rexruntime*.dll` is older than
`rexglue-sdk/out/win-amd64/rexruntime*.dll`, copy it over.

Runtime settings are flat keys in `Fable2.toml` next to the exe (no `[tables]`). Keys that
matter for gameplay work:

| Key | Meaning |
|---|---|
| `vsync` | true = 60 Hz guest vblank; false = vblank every 1 ms (uncapped, for measuring) |
| `vblank_rate_hz` | 0 = video mode rate; 120 makes the game's two-vblank pacing target 60 fps |
| `occlusion_query_enable` | false: no blocking GPU round trip per query (keep false until async queries exist) |
| `audio_reverb_disable` | true: silences the game's environmental reverb (the "cave" echo) |
| `audio_reverb_log` | logs reverb parameter traffic |
| `cpu_sampler_thread` | comma list of thread-name substrings to sample-profile (relwithdebinfo) |
| `log_level` | `debug` gives the 5 s GPU/CP statistics lines |

## 2. Reading the game

* `tools/xex_decrypt.py iso/extracted/default.xex out.bin` — flat decrypted image at
  0x82000000. Search it for strings and constants (float bit patterns, e.g. 1/30 =
  0x3D088889) with Python.
* `tools/find_addr_refs.py 0x8200B084 [...] [--any]` — which generated functions
  (`Fable2Recomp/generated/Fable2_recomp.N.cpp`) reference those addresses, by pairing
  `lis` values with `addi`/load offsets inside each function. This is how a string or a
  constant leads to the code that uses it.
* Generated code keeps the PPC disassembly as comments (`// lwz r11,0(r30)`), so a
  function can be read like an IDA listing: `DEFINE_REX_FUNC(sub_XXXXXXXX)`.
* Callers: `rg -l "sub_XXXXXXXX" Fable2Recomp/generated -g "*.cpp"`.
* Virtual tables live in `.rdata`; search the image for a function's big-endian address to
  find its vtable and neighbours (see the reverb XAPO example in
  `research/findings/2026-09-28-reverb-echo-and-draw-fastpath.md`).

## 3. Changing the game: hooks

Every guest function `sub_X` is a weak alias of `__imp__sub_X`. A strong definition in
`Fable2Recomp/src/hooks.cpp` replaces it; the original stays callable:

```cpp
REX_HOOK_RAW(sub_82CDDB68) {          // ctx = PPC registers, base = guest memory
    if (REXCVAR_GET(audio_reverb_disable)) ctx.f1.f64 = 0.0;   // change an argument
    __imp__sub_82CDDB68(ctx, base);   // run the original (or don't)
}
```

* Arguments: r3..r10 integer/pointer, f1..f13 float; return value r3 / f1.
* Guest memory: `REX_LOAD_U32(addr)` / `REX_STORE_U32(addr, v)` (big-endian aware),
  helpers `GuestF32` / `GuestStoreF32` in hooks.cpp.
* Cvars can be defined in the exe (`REXCVAR_DEFINE_BOOL(...)`) and read with
  `REXCVAR_GET`; they load from `Fable2.toml`.
* Kernel imports (`__imp__XamShowAchievementsUI` etc.) are hooked the same way.
* Verify binding: the log line `hooks: sub_82B9BF90 override active` is printed by the
  ring-poll hook on first call.

## 4. Measuring

* `GPU 5s stats` (swaps, fps, draws, skipped), `CP thread 5s` (idle vs exec, packets),
  `Draw stage ms per 5s` (per-stage CPU inside IssueDraw), `Fence waits per 5s`, `Fault 5s
  stats` — all `[debug]` lines in `fable2.log`. Grep:
  `rg "GPU 5s stats|CP thread 5s|Draw stage" fable2.log`.
* In-process sampler (`Fable2Recomp/src/sampler.cpp`, relwithdebinfo): set
  `cpu_sampler_thread = "GPU Commands,3D Engine,GameThread,Texture Streamer,(F8000048)"`;
  it logs `Sampler 10s '<thread>'` lines with function-folded module+offset percentages.
  `python tools/symbolize_samples.py fable2.log Fable2Recomp/out/build/win-amd64-relwithdebinfo --thread "3D Engine" --top 40`
  resolves them with llvm-symbolizer (guest functions come out as `sub_XXXXXXXX`).
* `tools/thread_cpu.ps1 -Seconds 20` — per-thread CPU of the running game (which thread is
  the limit).
* `tools/analyze_audio_dump.py` + `audio_dump_raw` — sample-exact 5.1 output analysis.
* Do not sample with cdb (`sample_thread.ps1`) during play: each attach pauses the game.

## 5. What is known about frame pacing (for the 60 fps work)

* The game waits on vblank events from `VdSetGraphicsInterruptCallback`; with 60 Hz vblanks
  it renders at 30 fps (two vblanks per frame). `vsync=false` (1 ms vblanks) showed the
  title screen at 100 fps and town at whatever the CPU allows, so the game is not
  hard-locked to 30; `vblank_rate_hz = 120` is the clean way to ask for 60.
* The swap is issued from `sub_82B9CD68` (calls `VdSwap`); the render thread waits for
  ring-buffer space in `sub_82242628` via the poll `sub_82B9BF90` (hooked: pause+yield).
* 1/30 and 1/60 constants: `sub_82242ED0` (27k instructions, called from `sub_8225DC40`,
  file 8) uses 1/30 as a default step; other users listed by
  `tools/find_addr_refs.py 0x82000b84 0x82000a9c 0x8209e30c --any`.
* Whether simulation speed is tied to the frame count or to measured time is NOT yet
  established. First experiment: `vblank_rate_hz = 120` in a light scene (title/menu) and
  watch animation speed.

## 6. Where the CPU goes (i7-4770K, Bowerstone, 2026-09-29)

Command processor (host, one thread) ~57% of a core after the fast paths, async submit
and disabled query stalls; guest render thread 94%, game thread 91%, texture streamer 87%,
audio worker (F8000048) 79%: the recompiled game threads are now the limit at 24–30 fps.
Next steps are in `research/findings/`: check the streamer/audio
worker for spin-polling, reduce host overhead inside guest code (page-protect faults,
kernel calls), then codegen quality.

## 7. Status after the 2026-09-29 optimisation pass

Open streets in Bowerstone: 48–58 fps with `vblank_rate_hz = 120`. Dense crowds: 13–34
fps. In crowds the machine is saturated by the recompiled game threads (render thread
~96% of a core, game thread ~83%, the game's XAudio2 software mixer ~85%, command
processor ~58%, texture streamer ~30% real work), about four cores of demand on a
four-core CPU. Host-side fixes done in this pass: async GPU submission, occlusion-query
stalls removed, type-0/float-constant register fast paths, 1 ms timer period, yield and
poll back-offs, user-mode mutex. What is left is the speed of the recompiled code itself
(codegen quality in rexglue: volatile byte-swapped memory accesses with a physical-offset
test per access, double-precision emulation of single-precision FP, register file in
memory) or reducing what the game asks for per frame (crowd density, LOD, audio voices)
through hooks and data changes.

## 8. Audio engine findings (2026-09-29 evening)

The game talks to XAudio2 through C wrappers `sub_82CD2A58`..`sub_82CD3308` (global lock +
one vtable method each; tracing hooks in `src/hooks_audio_trace.cpp`, `audio_api_trace`).
XAudio2's own mixing is <2% of the audio thread. The dominant cost was `sub_82C60180`, a
per-sample TPDF-dither + noise-shaping requantiser (LCG `sub_82C627E0`, FIR `sub_82C62548`,
rounding `sub_82C60140`) applied to the float mix; `audio_native_requantizer` replaces it with
a native clamp+copy (audio thread 85% -> 48% of a core in a crowd, 44% -> 13% on the title
screen). Remaining audio-thread cost: memcpy ~10%, reverb XAPO `sub_82CD6010` ~6%, a long tail.

## 9. Build optimisation level (important)

Until 2026-09-29 the `win-amd64-release` preset compiled with no `-O` flag at all
(`CMAKE_CXX_FLAGS_RELEASE` was empty in the cache): the generated game code and the runtime
DLL ran unoptimised. The preset now sets `-O2 -DNDEBUG`. After any reconfigure, verify with
`rg -m 1 "FLAGS = " Fable2Recomp/out/build/win-amd64-release/build.ninja` that `-O2` is present.
