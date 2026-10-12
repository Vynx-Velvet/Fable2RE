# Roadmap: removing every remaining emulation layer

Date: 2026-10-01. Direction from the project owner: Fable II must run natively on PC hardware, with
no emulation layer anywhere, fixing the 360 version's problems along the way (e.g. real-time
shadows instead of the previous frame's depth).

## Inventory (what still emulates the Xbox 360)

| # | Layer | Today | Native replacement |
|---|---|---|---|
| G1 | GPU command processor (PM4 interpreter thread) | **Done 2026-10-01 (`native_gpu_sync`)**: only sync effects were left (interrupt/callback mailbox, event and fence writes, queries, swap counter); now done natively by `src/gpu_sync.cpp` on the submitting thread, with a host interrupt thread. The SDK CP gets no commands. | — |
| G3 | (see below) | **Done 2026-10-01**: `gpu_command_processor = false` - the SDK's emulated GPU backend is not created; native sync starts before the guest runs. | � |
| R | Renderer on the game's render thread | **2026-10-01**: `native_render_thread` - hooks record commands (device snapshot head/tail/dirty constant groups, ucode, UP data, constant writes, GPU sync points); the renderer thread executes them; GPU sync effects (fences, callbacks) happen when the renderer reaches them. | � |
| G2 | Xbox D3D runtime writing PM4 for every call | Still runs; the frontend parses its packets for shader loads, constants, fetch constants, bin masks | Hook the D3D API natively (no original bodies): state from the device shadow, shaders from the shader objects (VS patching for vertex declarations via the game's own patch routine into a private cache), no command buffer use |
| G3 | SDK GPU backend still created (EDRAM buffer, texture cache, shared memory, pipeline cache of the emulated D3D12 CP) | Idle but allocated | Don't create the emulated CP backend at all; keep only the D3D12 device/presenter |
| G4 | Guest-memory GPU mirror with page-protection watches (Xenia SharedMemory) for vertex/index data and texture invalidation | Native renderer uses it | Resource-level tracking of the game's vertex/index buffers and textures (D3D Lock/Unlock + game allocators), native D3D12 buffers |
| G5 | Shader translation at runtime (Xenos microcode -> DXBC on first use) | SDK translator in-process | Offline translation of all of the game's shaders + persistent pipeline cache (no hitches) |
| G6 | Texture decode (tiled big-endian Xbox formats) at runtime | Native renderer decodes on first use | Decode once, cache converted textures on disk |
| A1 | XMA "hardware" decoder (APU emulation) and the audio driver HLE | SDK apu | Decode XMA with a native decoder at the XAudio2 API boundary; game voices -> host XAudio2 voices |
| P1 | Vblank interrupt timer (`vblank_rate_hz`), frame pacing | SDK vsync worker | Pace by the host swap chain (vsync/unlocked), no fake vblank |
| P2 | Input through the XInput HLE | SDK HLE | Native XInput / raw mouse+keyboard directly |
| K | Kernel / XAM (threads, files, events, memory) | HLE reimplementation in native code | Already native code; trim to what Fable II calls |
| C | Game code: recompiled PPC with big-endian guest memory and PPC register context | Static recompilation (native x64, no interpreter/JIT) | Only removable by decompiling functions to native C++; done function-by-function where it matters (hot paths, bug fixes) |

## Order

1. G1 (done), G2, G3 — finish the GPU: no PM4 anywhere, the emulated backend not created.
2. G4, G5, G6 — native resources and offline shaders (also the main remaining CPU cost per draw).
3. P1 — native frame pacing (needed for > 30/60 fps).
4. A1 — native audio.
5. P2, K — input/kernel trimming.
6. C — native C++ replacements of game functions, driven by profiles and bugs.

## G1 notes (native GPU sync)

- Takeover: at native renderer start, wait until the CP has consumed the ring, then
  `GraphicsSystem::SetRingWriteHandler` routes CP_RB_WPTR writes to `OnRingWrite`.
- `OnRingWrite` scans the new ring range and its indirect buffers by packet headers and performs:
  scratch register write-back (D3D callback mailbox at SCRATCH_ADDR: +0 cpu mask, +16 function,
  +20 argument), INTERRUPT -> interrupt thread -> game handler sub_82B9B8D8 (calls the function,
  clears the cpu bit), WAIT_REG_MEM on memory (bounded wait for the interrupt thread), REG_RMW,
  MEM_WRITE, REG_TO_MEM, COND_WRITE, EVENT_WRITE_SHD (counter or value), EVENT_WRITE_EXT (whole
  screen), EVENT_WRITE_ZPD (fake "visible" unless native queries), XE_SWAP (frame counter). Then the
  read pointer write-back = write pointer.
- Producers (tools/find_pm4_writers.py): INTERRUPT + mailbox waits sub_821F5F20; ZPD sub_82219418;
  query issue sub_822195E8 (MEM_WRITE, EVENT_WRITE_EXT); EVENT_WRITE_SHD sub_822981F0,
  sub_82B9CD68 (Swap), sub_82B9E610, sub_82BA8170; COND_WRITE sub_82B9E048, sub_82B9E140; REG_TO_MEM
  sub_82B99C10; REG_RMW sub_82B9C9D8, sub_82B9CD68, sub_82B9F958. These are the targets for G2.

## G1 lessons

- Predicated tiling: segments run once per tile; packets with the predicate bit must only run when
  BIN_SELECT & BIN_MASK != 0. Ignoring it double-fired D3D callbacks; the game's frame throttle in its
  present routine sub_82B69488 (GPU timestamp callback sub_82B89A78, reader sub_82B89960) then waited
  forever (white screen after the loading screen).
- D3D fence values here are written by EVENT_WRITE_SHD into the area *dev+10896 points to, not the
  CP read pointer alone.
