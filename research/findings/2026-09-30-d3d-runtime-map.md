# Xbox D3D runtime map (step 1 of the native renderer)

Date: 2026-09-30. Goal: find the game's statically linked Direct3D so a native D3D12
renderer can replace the emulated GPU path (PM4 command stream -> Xenia-derived command
processor -> EDRAM emulation).

## How D3D is linked

XEX static libraries: `D3D9LTCG 2.0.7645.1`, `XGRAPHC`, `D3DX9` (XDK 7645). LTCG = the
link-time-code-generation build of Xbox D3D, so small D3D API calls (SetRenderState,
SetTexture, SetShaderConstant...) are inlined into the game's renderer and only write the
device's shadow state + dirty bits. The large functions (draws, Resolve, Clear, the
dirty-state flush) remain real functions.

Consequence for the native renderer: hook the **draw / Resolve / Clear / Swap** functions and
read all state from the **device shadow** at that moment. No need to hook setters, and no
PM4 stream needs to be produced or parsed.

## Device object

One device, pointed to by two globals that always hold the same value (verified at runtime):
`*(0x8336019C)` and `*(0x83496F14)` (= 0x44142480 in the verified run). Layout:

| Offset | Contents | Evidence |
|---|---|---|
| +0 .. +40 | 5 x u64 dirty masks (+0 VS consts, +8 PS consts, +16 register blocks / shaders, +24 fetch consts + blocks, +32 misc blocks) | read + cleared in every draw |
| +48 | command buffer write pointer (put) | `stwu x,4(put)` then `stw put,48(dev)` |
| +52, +56 | command buffer limits (block flush / kickoff) | compared before writing |
| +64 .. ~+548 | SetRenderState handler table (function pointers) | called via `bctrl` from sub_8221E680 |
| +468 .. | SetSamplerState handler table | same, second base |
| +1152 | fetch constant shadow: 32 x 6 dwords (register 0x4800) | sub_8221D2E0 |
| +1920 | vertex shader float constants, 256 x vec4 (register 0x4000) | sub_8221DF98 |
| +6016 | pixel shader float constants, 256 x vec4 (register 0x4400) | sub_8221DF98 |
| +10112 | bool/loop constants (register 0x4900) | sub_8221C908 |
| +10368 | register shadow 0x2000.. (RB_SURFACE_INFO, render target / depth setup) | sub_8221C908 |
| +10444 | register shadow 0x2100.. | " |
| +10528 | register shadow 0x2180.. (SQ program control / shaders) | " |
| +10548 | register shadow 0x2200.. | " |
| +10596 | register shadow 0x2280.. | " |
| +10680 | register shadow 0x2300.. | " |
| +10832 | register shadow 0x2380.. | " |
| +10940 | flags byte (bit 0 = predicated/tiled path) | draws |
| +12187 | index into a byte table at +12122 (draw initiator bits) | draws |
| +13248..+13260 | secondary (tiling/predication) buffer put/limit | draws |

### Dirty masks -> register blocks (exact, from the mask extraction in DrawIndexedVertices)

Each block is flushed MSB-first: the highest mask bit of the field is the block's first register.

| Mask | Bits (LSB numbering) | Flushed by | Registers | Shadow |
|---|---|---|---|---|
| +0 | 0..63 | 8221DF98 | VS float constants 0x4000.., 4 vec4 per bit (256 vec4) | +1920 |
| +8 | 0..63 | 8221DF98 | PS float constants 0x4400.. | +6016 |
| +16 | 0..11 | 8221C908 | 0x2200..0x220B (RB_DEPTHCONTROL, RB_BLENDCONTROL0, RB_COLORCONTROL, RB_HIZCONTROL, PA_CL_CLIP_CNTL, PA_SU_SC_MODE_CNTL, PA_CL_VTE_CNTL, ..., RB_BLENDCONTROL1..3) | +10548 |
| +16 | 12..16 | 8221C908 | 0x2180..0x2184 (SQ_PROGRAM_CNTL, SQ_CONTEXT_MISC, SQ_INTERPOLATOR_CNTL, SQ_WRAPPING_0/1) | +10528 |
| +16 | 17..20 | 8221B140 | shaders (vertex/pixel program, IM_LOAD) | |
| +16 | 21..41 | 8221C908 | 0x2100..0x2114 (VGT_MAX/MIN_VTX_INDX, VGT_INDX_OFFSET, VGT_MULTI_PRIM_IB_RESET_INDX, RB_COLOR_MASK, RB_BLEND_RGBA, RB_STENCILREFMASK(_BF), PA_CL_VPORT_*...) | +10444 |
| +16 | 42..57 | 8221C908 | 0x2000..0x200F (RB_SURFACE_INFO, RB_COLOR_INFO, RB_DEPTH_INFO, RB_COLOR1..3_INFO, 0x2006..0x200D, PA_SC_SCREEN_SCISSOR_TL/BR) | +10368 |
| +16 | other bits | 822155E0 | render-state derived blocks | |
| +24 | 32..63 | 8221D2E0 | fetch constants 0..31 (6 dwords each, register 0x4800 + 6*i) | +1152 |
| +24 | 34..54 | 8221C908 | 0x2280..0x2294 (PA_SU_POINT_SIZE/MINMAX, PA_SU_LINE_CNTL, VGT_HOS_*...) | +10596 |
| +32 | 0..37 | 8221C908 | 0x2300..0x2325 (PA_SC_LINE_CNTL, PA_SC_AA_CONFIG, PA_SU_VTX_CNTL, PA_CL_GB_*, PA_SC_AA_MASK, ...) | +10680 |
| +32 | 38..45 | 8221C908 | 0x2380..0x2387 | +10832 |
| +32 | 49..54 | 822B3E40 | 6 user clip planes (PA_CL_UCP) | |
| +32 | 56 | 8221C908 | 0x4900..0x4907 boolean constants | +10112 |

Per-state handlers (render state and sampler state), decoded to register fields, are in
`research/symbols/d3d_state_handlers.md`.

The table dump from the verified run (device+64..+1152 code pointers) is in
`Fable2Recomp/out/build/win-amd64-release/runs/user_probe1.log` ("D3D probe: device").

## Functions

Counts are from the user's town session (release build, `d3d_probe = true`), per 5 s, ~40 fps.

| Address | Name | Args (r3 = device) | Calls / 5 s in town | Status |
|---|---|---|---|---|
| 8221E0F0 | D3DDevice_DrawIndexedVertices | r4 prim, r5 base vertex, r6 start index, r7 index count | 300k-400k | confirmed |
| 82207C30 | D3DDevice_DrawIndexedVertices (second LTCG copy) | same packet shape | 6k-20k | confirmed draw, 1 caller (sub_82A82F10) |
| 8221C518 | D3DDevice_DrawVertices | r4 prim, r5 start vertex, r6 vertex count | 26k-53k | confirmed (menu: QuadList UI) |
| 8221C9C8 | 2D rect-list draw (prim 0x12 k2DCopyRectListV2, explicit major mode) | | 46k-89k | confirmed draw, 1 caller (sub_8221FD60) |
| 82217EE8 | D3DDevice_BeginIndexedVertices | r4 prim, r5 base, r6 numVerts, r7 indexCount, r8 index fmt, r9 stride, r10 ppIndexData, [sp] ppVertexData; returns E_OUTOFMEMORY (0x8007000E) on failure; bookkeeping at +13444..+13460 | 8k-17k | confirmed |
| 822060A0 | D3DDevice_BeginVertices | | 2k-6k | confirmed |
| (inlined) | EndVertices / EndIndexedVertices | `put = dev[+13444]` after the caller's memcpy into the returned space | | confirmed |
| 8222E168 | DrawIndexedVerticesUP (Begin + 2 memcpy + End) | | | confirmed |
| 82265C98 | DrawVerticesUP (Begin + memcpy + End) | | | confirmed |
| 8220A528 | game helper: indexed UP draw of triangle lists (26 callers) | | | confirmed |
| 822069C0 | D3DDevice_Resolve | r4 Flags, r5 pSourceRect, r6 pDestTexture, r7 pDestPoint, r8 DestLevel, r9 slice, r10 pClearColor, f1 ClearZ | 4.5k-11k (~30 per frame) | confirmed (flags seen: 0x314) |
| 8222B948 | D3DDevice_ClearF | r4 Flags, r5 pRect (4 dwords), r6 pColor (D3DVECTOR4*, null ok), f1 Z, r8 Stencil | 2.5k-5k | confirmed |
| 821E2BA0 | Clear wrapper (7 callers, only calls ClearF) | | | confirmed |
| 822A5F80 | D3DDevice_BeginTiling | f1 ClearZ; stores tile rects at +12720..+12744, sets +10940 bit 0, clears through 821E2BA0 | | confirmed |
| 8227F0B0 | D3DDevice_EndTiling | r4 resolve flags .. r10, f1 ClearZ; Resolves per surface, clears +10940 bit 0 | | confirmed |
| 822655B0 | D3DDevice_SetPredication (likely) | r4 = predication mask (0 = off) | | likely |
| 82B9CD68 | D3DDevice_Swap | r4 pFrontBuffer (copies its 24-byte fetch constant from +28), r5 parameters | = frames | confirmed |
| 82B69488 / 82B69D00 | game Present paths (Resolve front buffer + Swap) | | | likely |
| 8221B140 | flush dirty shaders (IM_LOAD, SQ_PROGRAM_CNTL) | r4 dirty mask | ~1/3 of draws | likely |
| 822155E0 | flush dirty render-state block | r4 mask, r5 = dev[10560] | ~1/4 of draws | likely |
| 8221C908 | write dirty register run(s) from shadow | r4 mask, r5 register, r6 shadow | per draw | confirmed |
| 8221DF98 | write dirty float constants (4 vec4 per mask bit) | r4 mask, r5 0x4000/0x4400, r6 shadow | per draw | confirmed |
| 8221D2E0 | write dirty fetch constants (shadow +1152) | r4 mask | per draw | confirmed |
| 82213C10 | reserve N dwords in the command buffer | r4 = dwords | | confirmed |
| 821E8D20 | kick off / flush command buffer segment | | | confirmed |
| 82242628 / 82B9BF90 | wait for ring space / GPU progress poll | | | known before |
| 82B9BA58 | ring buffer setup (VdInitializeRingBuffer, ME_INIT) | | once | confirmed |
| 82BA0220 | engine init (VdInitializeEngines, interrupt callback) | | once | confirmed |
| 8221E5D0 | game-side render-state cache flush (calls D3D handler tables), called before every draw | | = draws | game code |
| 821FC1F0 | D3D resource Release (refcount at +4) | | | confirmed |

Primitive types seen (Xenos enum): 6 TriangleStrip (~90%), 4 TriangleList, 1 PointList,
13 QuadList (UI).

## Resource headers

D3DBaseTexture / D3DSurface (XDK layout, confirmed by Swap/Resolve reads): +0 Common (type/flags),
+4 ReferenceCount, +8 Fence, +12 ReadFence, +16 Identifier, +20 BaseFlush, +24 MipFlush,
+28..+51 Format = the 6-dword Xenos texture fetch constant (xe_gpu_texture_fetch_t).

## Predicated tiling

Fable II renders through BeginTiling/EndTiling (EDRAM is 10 MB). Commands between them are
recorded once; the secondary buffer at +13248 records draw positions for per-tile predication.
A native renderer sees every draw call exactly once and renders the full frame once, so tiling
can be ignored (EndTiling's Resolves are still real copies).

## Tooling added

- `tools/build_func_db.py`: parses the generated C++ (which keeps the PPC disassembly as comments)
  into `research/symbols/func_db.json`: callers/callees, imports, constants, struct offsets per function.
- `tools/asm.py <addr>...`: prints a function's disassembly with addresses.
- `tools/region_stats.py <lo> <hi>`: per-function stats (packet writes, device fields) for an address range.
- `tools/grep_funcs.py <regex>`: grep the disassembly, report containing functions.
- `tools/decode_handlers.py`: decodes the device's state-handler tables into register fields.
- `Fable2Recomp/src/d3d_probe.cpp`: wraps the functions above (original behaviour kept) and logs
  "D3D probe 5s" counts with `d3d_probe = true`.

## Open items for step 2

- Shader objects: find where the device stores the current vertex/pixel shader pointers (read by
  sub_8221B140) and the shader object layout (microcode pointer/size) for offline translation.
- Texture objects: D3DBaseTexture header layout (Resolve reads +36/+48 of the dest texture); fetch
  constants in the shadow already describe bound textures.
- Render targets / depth: the 0x2000 register shadow (+10368) holds RB_SURFACE_INFO/COLOR_INFO/DEPTH_INFO,
  i.e. EDRAM placement; the native renderer maps these to real render targets.
