// Native D3D12 renderer for Fable II's Xbox D3D calls.
//
// Driven at the Xbox D3D API level (draw / clear / resolve / swap calls of the statically linked
// D3D9LTCG runtime) with the state read from the D3D device object - no GPU command stream is
// parsed and no EDRAM is emulated: every guest render target surface is a real host render
// target, textures are decoded once from guest memory, Resolve is a GPU copy, and shaders are the
// guest microcode translated to DXBC (SDK DxbcShaderTranslator, render-target output path).
#pragma once

#include "guest_state.h"
#include "texture_decode.h"

#include <d3d12.h>
#include <wrl/client.h>

#include <array>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace rex::graphics {
class RegisterFile;
class DxbcShaderTranslator;
namespace d3d12 {
class D3D12Shader;
}
}  // namespace rex::graphics

namespace native {

using Microsoft::WRL::ComPtr;

struct DrawArgs {
  enum Kind { kIndexed, kAuto } kind = kIndexed;
  uint32_t prim = 0;         // xenos::PrimitiveType
  uint32_t base_vertex = 0;  // VGT_INDX_OFFSET
  uint32_t start = 0;        // first index / vertex
  uint32_t count = 0;        // index / vertex count
  // Index buffer override (UP draws: indices in the command buffer). 0 = device index buffer.
  uint32_t index_physical = 0;
  bool index_32bit = false;
  // D3DDevice_DrawTessellatedPrimitive / DrawIndexedTessellatedPrimitive: prim is a patch type
  // (0x11 triangle patch, 0x12 quad patch) or a triangle/quad list, drawn through the tessellator.
  bool tessellated = false;
  // Microcode actually loaded for this draw (big-endian dwords), when known. D3D patches D3D-managed
  // vertex shaders per draw (vertex declaration fetch formats, VS->PS export linkage; sub_821DFDE0)
  // and loads the patched copy inline, so the shader object's own microcode is not what runs.
  const uint32_t* vs_ucode = nullptr;
  uint32_t vs_ucode_dwords = 0;
  const uint32_t* ps_ucode = nullptr;
  uint32_t ps_ucode_dwords = 0;
  // XXH3 of the vs_ucode / ps_ucode bytes when the caller has it (0: unknown). A non-zero hash also
  // promises that the microcode stays valid and unchanged for the renderer's lifetime (interned by
  // the caller): the shader lookup skips hashing it and deferred draws keep the pointer.
  uint64_t vs_hash = 0, ps_hash = 0;
  // Vertex fetch override for UP draws (fetch constant 95 = slot 31 dwords 4..5).
  bool up_vertex_fetch = false;
  uint32_t up_vertex_physical = 0, up_vertex_bytes = 0;
  // The UP vertex / index bytes as the game wrote them, when the caller copied them (the renderer
  // runs later on its own thread, when the command buffer may hold other data): used instead of
  // reading guest memory. Index data covers the drawn range only.
  const uint8_t* up_vertex_data = nullptr;
  const uint8_t* up_index_data = nullptr;
};

struct ResolveArgs {
  uint32_t flags = 0;
  bool has_source_rect = false;
  int32_t src_x1 = 0, src_y1 = 0, src_x2 = 0, src_y2 = 0;
  uint32_t dest_texture = 0;  // guest D3DBaseTexture*, 0 = none
  int32_t dest_x = 0, dest_y = 0;
  uint32_t dest_level = 0;
  float clear_color[4] = {};
  float clear_z = 0;
  uint32_t clear_stencil = 0;
  // RB_COPY_DEST_INFO the call wrote into its command bytes (bit 24: red/blue swap of the copy).
  uint32_t copy_dest_info = 0;
};

// Value of the first type-0 write to register `reg` in PM4 command bytes (big-endian), or `fallback`.
uint32_t FindRegisterWrite(const uint8_t* p, size_t n_bytes, uint32_t reg, uint32_t fallback);

struct ClearArgs {
  uint32_t flags = 0;
  bool has_rect = false;
  int32_t x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  float color[4] = {};
  float z = 0;
  uint32_t stencil = 0;
};

struct Stats {
  uint32_t draws = 0, draws_skipped = 0, clears = 0, resolves = 0;
  uint32_t textures_created = 0, textures_failed = 0, pipelines_created = 0, pipelines_failed = 0;
  uint32_t shaders_translated = 0, shaders_failed = 0;
  // Cost counters (cumulative): GPU submissions, time blocked on the GPU, bytes uploaded to the
  // guest memory mirror, time decoding textures.
  uint64_t submits = 0, wait_us = 0, upload_bytes = 0, texture_us = 0;
  // Textures dropped because the CPU wrote their guest memory (decoded / resolved copies).
  uint64_t textures_stale = 0, resolved_stale = 0, textures_revalidated = 0;
  uint64_t textures_allocated = 0, textures_reuploaded = 0;
  // Re-uploads of textures the CPU keeps rewriting frame after frame (videos), see GetTexture.
  uint64_t textures_animated = 0;
  // Time creating things the first time they are used (hitches): shader translation, pipeline state
  // compilation, and re-hashing textures whose pages the CPU wrote.
  uint64_t translate_us = 0, pipeline_us = 0, revalidate_us = 0;  // GPU texture allocations / in-place re-uploads
  // Most recently re-created texture (guest base address, format, width) for diagnosis.
  uint32_t last_created_base = 0, last_created_format = 0, last_created_width = 0;
  std::unordered_map<std::string, uint32_t> skip_reasons;
};

class Renderer {
 public:
  Renderer();
  ~Renderer();

  bool Initialize(ID3D12Device* device, ID3D12CommandQueue* queue);

  // Guest physical memory mirror on the GPU (vertex fetch reads it). The replayer uploads the whole
  // frame-start dump, then every range that changes.
  void UploadPhysical(uint32_t addr, const uint8_t* data, uint32_t size);

  void BeginFrame();

  // GPU constant registers are the union of D3D's shadow flushes and direct loads; these keep the
  // renderer's constant file in call order.
  // D3DDevice_GpuLoadShaders(dev, vs, ps, flow_constants): shader literals + bool/loop constants.
  void LoadShaders(const GuestMemory& mem, uint32_t vertex_shader, uint32_t pixel_shader, uint32_t flow_constants);
  // The same with the 160-byte bool/loop block already copied (big-endian), or null.
  void LoadShadersWithFlow(const GuestMemory& mem, uint32_t vertex_shader, uint32_t pixel_shader, const uint8_t* flow);
  // D3DDevice_GpuLoadShaderConstantF4(dev, bank, start, count, buffer, offset).
  void LoadShaderConstantsF4(const GuestMemory& mem, uint32_t bank, uint32_t start, uint32_t count, uint32_t buffer,
                             uint32_t offset);
  // Initializes the constant file from the device shadow (once, before the first call of a session).
  void InitConstants(const uint8_t* device_be);
  // Raw constant write (register index 0x4000.., host-endian values), e.g. inline SET_CONSTANT data.
  void WriteConstants(uint32_t reg, const uint32_t* values, uint32_t count);
  // Fetch constants (registers 0x4800..0x48BF) the game wrote straight into the command stream,
  // bypassing the device's shadow copy. They apply to draws until D3D changes the shadow copy of the
  // same register (device_be: the device object at the time of the write).
  void WriteFetchConstants(uint32_t reg, const uint32_t* values, uint32_t count, const uint8_t* device_be);
  // One overlaid fetch constant dword with the device shadow value it was written against.
  void WriteFetchConstant(uint32_t reg, uint32_t value, uint32_t shadow);
  // Real-time depth (realtime_depth_passes): a pass reading a depth texture resolved in an earlier
  // frame (Fable II's screen-space shadow mask reads the previous frame's scene depth, then lights
  // the scene with it) starts a deferred section: the following calls are recorded until the scene
  // depth is resolved into that texture. Then the recorded scene draws are first drawn into a private
  // copy of the depth buffer (depth pre-pass), that depth is resolved into the texture, and the
  // recorded calls run in order - the shadow mask is built from this frame's depth.
  void Draw(const GuestMemory& mem, const uint8_t* device_be, const ShaderState& shaders, const DrawArgs& args);
  void Clear(const GuestMemory& mem, const uint8_t* device_be, const ClearArgs& args);
  void Resolve(const GuestMemory& mem, const uint8_t* device_be, const ResolveArgs& args);
  bool realtime_depth_passes = true;
  // Pipeline states compile on background threads; draws wait for pipelines still compiling for at
  // most `pipeline_wait_ms` in total per frame, after that they are skipped (drawn from a later frame
  // on). Off: compile synchronously (replayer, exact output).
  bool async_pipelines = false;
  float pipeline_wait_ms = 4.0f;
  // Persistent pipeline cache: every pipeline is appended to this file and all of them are compiled
  // again in the background at startup (so new areas do not hitch on the next run). Empty: none.
  void SetPipelineCache(const std::string& path);
  uint64_t passes_rerun = 0, prepass_draws = 0, packets_replayed = 0;  // statistics
  // Ends the frame: executes the recorded work and waits for it.
  void EndFrame();

  // Copies the resolved front buffer (guest texture at `base_address`) into `dst` (R10G10B10A2_UNORM,
  // in `dst_state` on entry and exit, e.g. the presenter's guest output) and submits the work to the
  // queue. Returns false if there is no such resolved texture.
  bool PresentFrontbuffer(uint32_t base_address, ID3D12Resource* dst, D3D12_RESOURCE_STATES dst_state);
  // Occlusion queries (the game's ZPASS sample counting, e.g. visibility of lamp flares and light
  // shafts). Begin/End bracket the draws in between; End submits the recorded work (no wait) and
  // returns the fence value after which OcclusionQueryResult is valid. Returns UINT32_MAX / 0 when
  // queries are unavailable.
  uint32_t BeginOcclusionQuery();
  uint64_t EndOcclusionQuery(uint32_t index);
  // Thread-safe: whether the GPU has passed `fence`, and the query's sample count if so.
  bool OcclusionQueryResult(uint32_t index, uint64_t fence, uint64_t* samples) const;
  // Thread-safe: blocks until the GPU passes `fence` (using the caller's own event).
  void WaitFence(uint64_t fence, void* event_handle) const;

  // Diagnostics (F8): drops every texture decoded from guest memory (decoded again on next use).
  void DropTextureCache();

  // Frame history (retroactive capture): copies the resolved texture at `base_address` into a GPU-side
  // ring of the last `kHistoryFrames` presented frames (no readback, no wait), tagged with `frame`.
  static constexpr uint32_t kHistoryFrames = 64;
  void PushFrameHistory(uint32_t base_address, uint32_t frame);
  // The ring's frames, oldest first: (frame number, texture, red/blue swapped).
  struct HistoryFrame {
    uint32_t frame;
    ID3D12Resource* resource;
    bool red_blue_swapped;
  };
  std::vector<HistoryFrame> FrameHistory() const;
  // Host texture holding the guest texture at `base_address` if it was produced by a Resolve.
  ID3D12Resource* GetResolvedTexture(uint32_t base_address) const;
  // Whether that texture was resolved with the red/blue swap (display order is swapped back).
  bool IsResolvedRedBlueSwapped(uint32_t base_address) const;
  // Reads a 2D texture/render target back as 8-bit RGBA (tone-clamped), for debugging/PNG output.
  bool ReadbackRGBA8(ID3D12Resource* resource, std::vector<uint8_t>* rgba, uint32_t* width, uint32_t* height,
                    std::vector<float>* raw_rgba = nullptr);
  // Decodes a guest texture (fetch constant dwords, host-endian) from `mem` and reads it back like
  // ReadbackRGBA8 (for comparing reference resolve results).
  bool DecodeReference(const GuestMemory& mem, const uint32_t fetch_dwords[6], std::vector<uint8_t>* rgba,
                       uint32_t* width, uint32_t* height, std::vector<float>* raw_rgba = nullptr);
  // Render target resources by guest surface address (for debugging).
  std::vector<std::pair<uint32_t, ID3D12Resource*>> RenderTargets() const;
  // Resolve destinations by guest base address.
  std::vector<std::pair<uint32_t, ID3D12Resource*>> ResolvedTextures() const;

  const Stats& stats() const { return stats_; }
  // Milliseconds spent in each section of Draw since the last reset.
  std::string DrawProfile(bool reset);
  static void EnableDrawProfile(bool enable);  // per-draw section timing (costs ~13 clock reads per draw)
  void ResetStats() { stats_ = Stats{}; }

  // Debug switches (replayer).
  bool debug_no_depth = false, debug_no_cull = false, debug_no_msaa = false, debug_no_alpha_test = false,
       debug_no_clip = false;
  // Writes the register view (0x2000..0x4A00, host-endian) of draw number `debug_dump_draw` (1-based).
  uint32_t debug_dump_draw = 0;
  std::string debug_dump_path;
  // With a path set, every draw appends {seq, registers 0x2000..0x4A00} to this file.
  std::string debug_dump_all_path;
  uint32_t debug_seq = 0;
  bool debug_trace = false;
  bool state_cache = true;  // skip redundant command list state calls
  FILE* debug_trace_file = nullptr;  // trace output (stderr when null)
  FILE* TraceOut() const { return debug_trace_file ? debug_trace_file : stderr; }
  std::string debug_shader_dir;
  // Pixel probe: after every draw into render target surface `debug_probe_surface`, sample 0 of pixel
  // (debug_probe_x, debug_probe_y) is copied aside; DebugProbeResults returns {seq, rgba} per draw.
  // Pixel shader debugging: in the shader with this microcode hash, ALU instruction `instr` is replaced
  // by "max oC0, rREG, rREG" (exports a temporary register as the color).
  uint64_t debug_ps_patch_hash = 0;
  uint32_t debug_ps_patch_instr = 0, debug_ps_patch_reg = 0;
  uint32_t debug_nodepth_seq = 0;  // depth test off for the draw with this seq
  uint32_t debug_probe_surface = 0;
  int32_t debug_probe_x = -1, debug_probe_y = -1;
  bool DebugProbeResults(std::vector<std::pair<uint32_t, std::array<float, 4>>>* out);  // writes each shader's microcode disassembly here  // logs resolves / texture bindings to stderr

 private:
  void DrawInternal(const GuestMemory& mem, const uint8_t* device_be, const ShaderState& shaders, const DrawArgs& args);
  void ClearInternal(const GuestMemory& mem, const uint8_t* device_be, const ClearArgs& args);
  void ResolveInternal(const GuestMemory& mem, const uint8_t* device_be, const ResolveArgs& args);
  void UpdateDrawConstants(const GuestMemory& mem, const uint8_t* device_be);
  struct PassItem;
  PassItem& RecordItem(int kind, const uint8_t* device_be);
  void RecordDraw(const GuestMemory& mem, const uint8_t* device_be, const ShaderState& shaders, const DrawArgs& args);
  void RunItem(const GuestMemory& mem, PassItem& it);
  void BeginConstReplay();                      // constant file = the recorded section's start
  void ApplyConstDelta(const PassItem& it);     // + one recorded draw's changes
  bool ReplayPacket(PassItem& it);  // issues a pre-pass draw again into the real targets
  // Runs the deferred section (with the depth pre-pass when `depth_resolve` is given).
  void RunDeferred(const uint8_t* resolve_device, const ResolveArgs* depth_resolve);
  void FlushDeferred() { RunDeferred(nullptr, nullptr); }
  struct Impl;
  std::unique_ptr<Impl> impl_;
  Stats stats_;
};

}  // namespace native
