# Identified Fable II (GOTY disc, media ID 716F0A0D) guest functions

Addresses are in the recompiled `default.xex` (image 0x82000000-0x83620000). Names are
ours; evidence is how each was identified. Hooked functions live in
`Fable2Recomp/src/hooks.cpp`.

| Address | Name | Role / evidence | Hooked |
|---|---|---|---|
| 0x82B9BF90 | RingBufferPoll | D3D runtime GPU-progress poll: 8x db16cyc, compares saved vs current read pointer, 5000-tick hang check; called in a loop from RingBufferWait | yes: pause + yield before original |
| 0x82242628 | RingBufferWait | waits for ring-buffer space (obj+10896 = RPTR address, +10908 = ring size), loops on RingBufferPoll | no |
| 0x82B9CD68 | SwapFrame | the only caller of `VdSwap` | no |
| 0x82242ED0 | FrameUpdateHuge | 27k-instruction function called by 0x8225DC40; loads 1/30 as a default step | no |
| 0x82CD7EA0 | ReverbXapo::SetParameters | vtable 0x82013E18 (+52 IXAPOParameters) | log |
| 0x82CD7788 | ReverbXapo::ProcessQuantum | applies pending flags (+188 wet/dry via +184, +189 native block at +52, +190 I3DL2 at +136) then DSP `sub_82CD6010` (256 frames) | log, kill switch |
| 0x82CD7960 | ReverbXapo::Validate/LockForProcess | 6 channels, 48000 Hz | no |
| 0x82CDF788 | ReverbParams::Set(index, value) | 0 = whole 48-byte I3DL2 block, 1..12 one field | log |
| 0x82CDF4F8 | ReverbConvertI3DL2ToNative | uses log10 (0x821B1580), constants 1000.0f @0x820F8738, -4.0 @0x82014DD8 | no |
| 0x82CDD6D0 | ReverbNativeDefaults | RearDelay 5, Position 6, PositionMatrix 27, diffusion 8, EQ 4/6, RoomSize 100 | no |
| 0x82CDDB68 | ReverbSetWetDry | obj+92 = f1 * 0.01 | log, forced 0 |
| 0x82CDDB80 | ReverbXapo::ApplyNative | 84-byte native block to delay-line coefficients; sample rate at DSP-object+88, wet at +92 | log, gains forced -100 dB |
| 0x82C161D8 | ReverbZoneTableSchema | column names ZoneId, Room, RoomHF, ..., HFReference, WetDryMix (strings 0x8200AFB8-0x8200B084) | no |
| 0x829F8728 | AudioManager::SetEnvironmentalReverb(id) | called with the region property `RegionEnvironmentalReverb` (string 0x820A6718) by 0x822B4D70 / 0x8234B378; never observed firing in town (why the reverb ran on XAudio2 defaults) | log |
| 0x821B1580 | log10f | CRT | no |
| 0x8234E0B0 | Region::GetProperty(name) | returns property value for a name string | no |
| 0x82200688 | String::Construct | temp string from literal, used before lookups | no |

Kernel imports the game uses for timing/video: VdSwap, VdSetGraphicsInterruptCallback,
VdEnableRingBufferRPtrWriteBack, VdInitializeRingBuffer, KeQueryPerformanceFrequency,
KeQuerySystemTime, KeDelayExecutionThread, NtYieldExecution, KeWaitForSingleObject,
NtWaitForSingleObjectEx, XGetVideoMode.

Thread names (SetThreadDescription, guest handle in parentheses): "GameThread (F800002C)",
"3D Engine (F80000E4/E8)" render thread, "Texture Streamer (F80000C4/C8)", "(F8000048)"
audio engine worker, "Cloth Simulation", "XMA Decoder", "VFS - Request Manager/Finalizer";
host: "GPU Commands", "GPU Submit", "GPU VSync", "Audio Worker", "D3D12 Pipelines".

## Xbox D3D runtime (D3D9LTCG), see research/findings/2026-09-30-d3d-runtime-map.md

Device pointer globals: `*(0x8336019C)` == `*(0x83496F14)`. Counted by `src/d3d_probe.cpp` (d3d_probe cvar).

| Address | Name | Role / evidence | Hooked |
|---|---|---|---|
| 0x8221E0F0 | D3DDevice_DrawIndexedVertices | dirty-state flush + VGT_INDX_OFFSET + predicated DRAW_INDX; ~70% of draws | probe |
| 0x82207C30 | D3DDevice_DrawIndexedVertices (LTCG copy) | same packet shape, 1 caller | probe |
| 0x8221C518 | D3DDevice_DrawVertices | auto-index DRAW_INDX (initiator 0x80) | probe |
| 0x8221C9C8 | Draw2DRectList | auto-index prim 0x12 (2D copy rect list), 1 caller | probe |
| 0x82217EE8 | DrawIndexedVerticesUP (likely) | inline vertex data, fetch const 0x48BA | probe |
| 0x822060A0 | DrawVerticesUP (likely) | inline vertex data | probe |
| 0x822069C0 | D3DDevice_Resolve | Flags r4 .. pClearColor r10, ClearZ f1 | probe |
| 0x8222B948 | D3DDevice_Clear (likely) | Z in f1 | probe |
| 0x8221B140 | FlushDirtyShaders | IM_LOAD / SQ_PROGRAM_CNTL | probe |
| 0x822155E0 | FlushDirtyRenderStates | register block writes | probe |
| 0x8221C908 | WriteDirtyRegisterRuns | (mask, register, shadow) -> type-0 packets | no |
| 0x8221DF98 | WriteDirtyFloatConstants | (mask, 0x4000/0x4400, shadow) | no |
| 0x8221D2E0 | WriteDirtyFetchConstants | shadow at device+1152 | no |
| 0x82213C10 | ReserveCommandSpace | put +48 / limit +52 | no |
| 0x821E8D20 | KickOffCommandBuffer | called when put > limit | no |
| 0x82B9BA58 | InitRingBuffer | VdInitializeRingBuffer, ME_INIT | no |
| 0x82BA0220 | InitEngines | VdInitializeEngines, interrupt callback | no |
| 0x8221E5D0 | GameRenderStateFlush | game-side cache, calls device handler tables before each draw | probe |
| 0x821FC1F0 | D3DResource_Release | refcount at +4 | no |

## Game loop, Lua and the debug menu, see research/findings/2026-10-02-lua-debug-menu.md

| Address | Name | Role / evidence | Hooked |
|---|---|---|---|
| 0x822EA928 | GameThreadMain | init sub_822F27C0, mode loop sub_822F47F8, shutdown sub_822F4690 | yes: dev_debug_menu |
| 0x82355460 | MainGameLoop | loops until component+92; per-iteration bl sub_8229A9D8 at return address 0x82355590 | no |
| 0x8229A9D8 | (per-frame callee) | used as the between-frames safe point | yes: Lua bridge |
| 0x82354BB8 | MainGameMode::Start | registers debug quests, creates debug menu if 0x833194D0 == 0 | no |
| 0x82692230 / 0x82692048 | DebugMenu::Update / ::HandleInput | gated by byte 0x833194D0 (1 in retail) | no |
| 0x824154F0 | RunLuaFile(L, String* path, String* err) | | no |
| 0x824155C8 | RunLuaBuffer(L, buf, len, String* chunk, String* err) | lua_load + pcall, returns 1/0 | called by bridge |
| 0x82A1EE10 | lua_load | | no |
| 0x8222CF18 / 0x82214F08 | String::Construct(out, cstr, -1) / String::Destroy | | called by bridge |
