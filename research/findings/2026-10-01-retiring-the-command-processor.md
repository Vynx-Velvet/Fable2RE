# Retiring the emulated command processor and the Xbox D3D command path (items 1 + 2)

Date: 2026-10-01. Native renderer is live in game; this note records what is left of the
emulated GPU path and the plan to remove it.

## What the command processor (CP) still does in native mode

Draws and resolves are skipped (`gpu_native_frontend`). Per frame (capture 20261001_120803)
the remaining packets with CPU-visible effects are:

| Packet | Count/frame | Effect the game depends on |
|---|---|---|
| WAIT_REG_MEM reg 0x0A31 (COHER_STATUS_HOST) & 0x80000000 == 0 | ~70 | none (always true) |
| WAIT_REG_MEM mem 0x1FC83000.. == value, INTERRUPT, WAIT mem == 0 | ~2-4 | D3D GPU->CPU callback handshake: mailbox {source, fn 82B9F730, arg}; the interrupt runs the D3D interrupt callback, which clears the mailbox |
| INTERRUPT | 4 | GraphicsSystem::DispatchInterruptCallback(1, cpu) |
| EVENT_WRITE_EXT (0x5A) | ~750 | fake screen extents written to memory |
| EVENT_WRITE_ZPD (0x5B) | ~170 | occlusion queries (CP fake: end struct ZPass_A = 1000) |
| XE_SWAP (0x64) | 1 | swap counter |
| type-0 SCRATCH_REG0-7 (with SCRATCH_UMSK) | ? | fence values written back to memory |

Interrupt callbacks must run on an XThread (DispatchInterruptCallback uses the current thread's
guest state), not inside a D3D call on the render thread.

## Occlusion queries

Each query has a begin struct (block + 0x20) and an end struct (block + 0); D3D marks the end
struct 0xFFFFFEED, the game computes end - begin. The marker is not always present when the
frontend parses the packet (detecting begin/end by marker at parse time culled whole buildings).
Default: CP fake ("visible"), as in the emulated path. Real host queries:
`native_occlusion_queries` (begin/end by address bit 5), unverified.

## Cost (profiler, town)

D3D's own flush + packet writing is ~3-5% of the render thread; the native frontend/renderer is
~50%. Removing the Xbox command path is about architecture (no PM4 in the rendering path, no
parsing bugs), not speed.

## Plan

1. (done, `native_skip_d3d_flush`) Inside draws, skip D3D's pure shadow->command writers:
   8221DF98 (float constants), 8221C908 (register runs), 8221D2E0 (fetch constants),
   822B3E40 (clip planes). Resolve/Clear keep them (copy-destination setup is read from them).
2. Shader flush 8221B140 natively: VS microcode from the shader object, patched for the vertex
   declaration by the game's own patch routine (sub_82B9D618, called by 821DFDE0 on a copy in the
   command buffer) into a private cache; vertex-stream fetch constants (slots 30/31) from the
   device's stream sources. Then no IM_LOAD packets and no call-byte parsing for shaders.
3. Draw packets: skip the original draw functions entirely (state bookkeeping: clear dirty masks,
   tiling predication buffer at +13248 not needed).
4. Sync natively: D3D callback/fence/swap functions hooked at API level; fences complete when
   the D3D12 GPU passes them. Then the CP has nothing left: stop its thread.
