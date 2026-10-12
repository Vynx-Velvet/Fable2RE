// Shared ids for the hooked Xbox D3D (D3D9LTCG) functions.
// Map and layouts: research/findings/2026-09-30-d3d-runtime-map.md and
// research/findings/2026-09-30-d3d-objects-and-state.md.
#pragma once

#include <string>
#include <vector>

#include <cstdint>

struct PPCContext;

namespace d3dhooks {

enum Fn : int {
  kDrawIndexed,      // sub_8221E0F0 D3DDevice_DrawIndexedVertices(dev, prim, base, start, count)
  kDraw,             // sub_8221C518 D3DDevice_DrawVertices(dev, prim, start, count)
  kBeginIndexedUP,   // sub_82217EE8 D3DDevice_BeginIndexedVertices
  kBeginUP,          // sub_822060A0 D3DDevice_BeginVertices(dev, prim, count, stride) -> ptr
  kDrawRect2D,       // sub_8221C9C8 2D rect-list draw
  kDrawIndexed2,     // sub_82207C30 second LTCG copy of DrawIndexedVertices
  kResolve,          // sub_822069C0 D3DDevice_Resolve
  kClear,            // sub_8222B948 D3DDevice_ClearF(dev, flags, rect, color, z, stencil)
  kSwap,             // sub_82B9CD68 D3DDevice_Swap(dev, frontbuffer, params)
  kCommitShaders,    // sub_8221B140
  kCommitRS,         // sub_822155E0
  kGameStateFlush,   // sub_8221E5D0
  kGpuLoadShaders,   // sub_82221978 D3DDevice_GpuLoadShaders(dev, vs, ps, ...): IM_LOAD written directly
  kGpuLoadConstants, // sub_8227CFC8 GpuLoadShaderConstantF4(dev, bank, start, count, buffer, offset)
  kCount
};

extern const char* const kFnNames[kCount];

// Guest device-pointer globals (always equal at runtime).
constexpr uint32_t kDevicePtrA = 0x8336019C;
constexpr uint32_t kDevicePtrB = 0x83496F14;

}  // namespace d3dhooks

// Frame capture (src/d3d_capture.cpp).
void D3DCapture_Request();
bool D3DCapture_Active();
void D3DCapture_Before(int fn, PPCContext& ctx, uint8_t* base);
void D3DCapture_After(int fn, PPCContext& ctx, uint8_t* base);
void D3DCapture_SegmentSwitch(uint32_t device, bool after);

// Native GPU synchronisation (src/gpu_sync.cpp): takes the ring buffer over from the emulated
// command processor. Returns false if it stays with the command processor.
bool NativeGpuSync_Start();
std::string NativeGpuSync_Stats();
// Performs the effects of submitted GPU commands (`commands`: the ring's new dwords) and writes the
// read pointer back as `write_index`.
void NativeGpuSync_Execute(std::vector<uint32_t>& commands, uint32_t write_index);
// GPU interrupts raised by commands executed on the calling (guest-capable) thread are delivered on
// it directly instead of through the interrupt thread.
void NativeGpuSync_RunInterruptsOnThisThread();
// The game is stopping: submitted commands and GPU interrupts are dropped from now on.
void NativeGpuSync_Stop();
// Queues that on the native renderer's thread (returns false when it does not run on its own thread).
bool NativeFrontend_QueueGpuSync(std::vector<uint32_t>& commands, uint32_t write_index);

// Native renderer frontend (src/native_frontend.cpp).
bool NativeFrontend_Active();
void NativeFrontend_Before(int fn, PPCContext& ctx, uint8_t* base);
void NativeFrontend_After(int fn, PPCContext& ctx, uint8_t* base);
void NativeFrontend_SegmentSwitch(uint32_t device, bool after);
// Whether D3D's state-to-command writers may be skipped inside draws (native renderer active).
bool NativeFrontend_SkipStateFlush();
// Sampling profiler (src/sampler.cpp, cvar profile_sampler): the thread issuing D3D calls.
void Sampler_SetRenderThread(uint32_t tid);
void Sampler_PinRenderThread(uint32_t tid);
// Saves the native renderer's image of the frame ending at the next-but-one swap into `dir` (F9
// captures: the live result next to the recorded calls, to compare with the replayer).
void NativeFrontend_RequestCaptureSnapshot(const std::string& dir);
