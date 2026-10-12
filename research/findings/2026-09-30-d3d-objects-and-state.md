# Xbox D3D objects and per-draw state (step 2 of the native renderer)

Date: 2026-09-30. Builds on `2026-09-30-d3d-runtime-map.md` (functions, device shadow, dirty
masks) and `research/symbols/d3d_state_handlers.md` (every render/sampler state decoded to the
register field it writes). Everything here is from static analysis of the recompiled code;
addresses are guest functions.

The question this answers: at the moment the game calls a draw, where does a native renderer
find each piece of state, without parsing the GPU command stream?

## Current bindings in the device

| Device field | Contents | Set by |
|---|---|---|
| +12440 + 4*i (i = 0..3) | render target surface i (D3DSurface*) | SetRenderTarget `82286508(dev, i, surf)` |
| +12456 | depth/stencil surface | SetDepthStencilSurface `82264550(dev, surf)` |
| +12436 | index buffer (D3DIndexBuffer*) | SetIndices (inlined) |
| +11820 | vertex declaration | SetVertexDeclaration `822225C8`, inlined in ~50 game functions |
| +12692 | pixel shader (D3DPixelShader*) | SetPixelShader `82208CE8` |
| +12696 | vertex shader (D3DVertexShader*) | SetVertexShader `822324E0` |
| +1152 + 24*s | texture fetch constant for sampler s (6 dwords); vertex fetch constants share this space | SetTexture / SetStreamSource (inlined), SetSamplerState table |
| +1920 / +6016 | VS / PS float constants (256 vec4 each) | SetVertex/PixelShaderConstantF (inlined) |
| +10112 | boolean constants | |
| +10368.. | register shadow (render state, viewport, scissor, EDRAM surface info...) | render-state table |

Dirty masks (+0..+32) say what changed since the last draw; a native renderer can use them the
same way to skip re-validation (see the dirty-mask table in the runtime map).

## Resources

**D3DBaseTexture / D3DSurface / buffers** (XDK common header):
+0 Common (type and flags), +4 ReferenceCount, +8 Fence, +12 ReadFence, +16 Identifier,
+20 BaseFlush, +24 MipFlush.

- Texture: +28..+51 = the 6-dword Xenos texture fetch constant (xe_gpu_texture_fetch_t: format,
  base address >> 12, size, tiling, swizzle, mip address). Swap copies it from the front buffer;
  Resolve reads dwords 2 and 5 of the destination.
- Surface (render target / depth): +28 = the RB_COLOR_INFO / RB_DEPTH_INFO word (EDRAM base and
  format), +32 = HiZ info (copied to RB_HIZCONTROL and device+10560).
- Index buffer: +0 bit 31 = 32-bit indices, +24 = index data address.
- Vertex buffers are described only by the vertex fetch constants in the fetch shadow.

## Shaders

**Pixel shader** (`ps = dev[+12692]`):
- `hdr = ps + *(ps+64)`; microcode address = `*(ps+24) + hdr[+40]`, size in bytes = `hdr[+44]`.
- `hdr[+48]`, `hdr[+52]` are OR-ed into SQ_PROGRAM_CNTL / SQ_CONTEXT_MISC (shadow +10528/+10532);
  `hdr[+64]` goes to shadow +10536 (0x2182 SQ_INTERPOLATOR_CNTL).
- Loaded with IM_LOAD (0xC0012700, shader type 1).

**Vertex shader** (`vs = dev[+12696]`):
- Xbox D3D patches a vertex shader's vfetch instructions per vertex declaration, so a VS has
  several *bindings*. Binding i: `rec = vs + *(vs + (i+112)*8)`; microcode address =
  `*(vs+32) + rec[+872]`, size = `rec[+876]` bytes; per-binding fence at `vs + i*416 + 64`.
- `sub_821F75E8(dev, vs, decl, flag)` finds an existing binding for the current declaration;
  `sub_821DFDE0` creates one (patching). The flush `sub_8221B140` picks the binding at draw time.
- `vs + *(vs+896) + 872` = current program header (flags at +0, SQ bits at +8/+12).

**Embedded (literal) constants** (`sub_8222BFF8(dev, hdr+40, base)`): the program header at
+20 holds an offset to a list of `{u16 dword offset in the ALU constant space, u16 dword count,
u32 data offset from the shader base}`. They are loaded straight into the GPU constant space
with LOAD_ALU_CONSTANT and are **not** in the device shadow, so the native renderer has to
overlay them on the shadow constants for draws that use the shader.

## Render targets and EDRAM

The game renders to EDRAM surfaces (RB_COLOR_INFO/RB_DEPTH_INFO give EDRAM base and format,
RB_SURFACE_INFO the pitch/MSAA) and copies them to textures with Resolve
(`822069C0`, ~30 per frame). A native renderer:
- maps each surface object (`dev[+12440+4i]`, `dev[+12456]`) to a host render target sized from
  the surface/viewport, instead of placing it in a 10 MB EDRAM model;
- implements Resolve as a copy/resolve from that host render target into the host texture that
  backs the destination D3DBaseTexture (its fetch constant gives address and format);
- ignores predicated tiling (BeginTiling/EndTiling): each draw call happens once.

## Draw-time procedure for a native renderer (summary)

At DrawIndexedVertices / DrawVertices / 2D rect draw / Begin*Vertices+End:
1. Render targets: `dev[+12440..+12456]` surfaces -> host RTVs/DSV.
2. Shaders: PS microcode from `dev[+12692]`, VS microcode from the binding chosen for
   `dev[+11820]`; translate once per microcode hash (offline cache).
3. Constants: shadow +1920/+6016 overlaid with the shaders' embedded constants; bool/loop +10112.
4. Textures/samplers: fetch shadow +1152 (texture address/format/size/tiling + sampler fields).
5. Vertex/index input: vertex fetch constants in the same shadow; index buffer `dev[+12436]`
   (UP draws: the data the caller copied into the space returned by Begin*Vertices).
6. Fixed-function state: register shadow +10368.. (depth/stencil, blend, cull, colour mask,
   viewport, scissor), field meanings in d3d_state_handlers.md.

## Open items

- VS binding selection: confirm which binding index the flush picks (to read the right microcode
  without re-running the flush), or call sub_821F75E8 from the host.
- D3DSurface size fields (width/height/MSAA) and RB_SURFACE_INFO source.
- Resolve source-rect / destination-point / format conversion details.

## GPU synchronisation (what the game waits on)

- Fences are **ring-buffer positions**. `sub_82242628(dev, fence, ...)` waits until the ring
  read pointer (read through the writeback pointer at dev+10896; ring size at dev+10908) has
  moved past `fence`, polling with `sub_82B9BF90`. Resource fences (+8 Fence, +12 ReadFence) and
  command-buffer space waits all go through it.
- `sub_821F61D0` = lock a resource for CPU access: waits on its fence, then queues a cache
  coherency request (COHER_SIZE/BASE/STATUS_HOST, registers 0xA2F..0xA31, + WAIT_REG_MEM).
- `sub_821E8D20` / `sub_821E8B98` = kick off: closes the current command segment, appends an
  INDIRECT_BUFFER reference to the primary ring (or to the tiling list at +13368 when predicated
  tiling is active) and starts a new 32-byte aligned segment (dev+14928 = segment start).
- `sub_822195E8` = query Issue (type 9 occlusion via 82219418 / EVENT_WRITE_ZPD, type 10 event:
  EVENT_WRITE 25 + flag); results come back through memory writes.
- Swap: `sub_82B9CD68` -> VdSwap (kernel) with the front buffer's fetch constant.

Consequence for a native renderer that executes each draw when it is called: GPU work is
complete as soon as the call returns, so the read-pointer writeback can simply be kept equal to
the write position (every fence passes immediately), query results written when the query ends,
and Swap presents directly. No command processor is needed for synchronisation.
