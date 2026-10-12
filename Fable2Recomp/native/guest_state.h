// Native renderer: guest (Xbox D3D) state as seen at a draw call.
//
// All GPU state lives in the D3D device object's shadow (research/findings/2026-09-30-d3d-*.md).
// FillRegisters() turns that shadow into a host-endian register view so the SDK's draw_util
// helpers (viewport, scissor, normalized depth/colour masks) can be reused, and so the
// translated shaders get their constant buffers in the layout they expect.
#pragma once

#include <atomic>
#include <cstdint>
#include <memory>

namespace rex::graphics {
class RegisterFile;
}

namespace native {

// Guest memory access (big-endian contents). Implemented by the replayer (capture) and by the
// in-game renderer (live memory).
class GuestMemory {
 public:
  virtual ~GuestMemory() = default;
  virtual const uint8_t* Physical(uint32_t addr, uint32_t size) const = 0;
  virtual const uint8_t* Virtual(uint32_t addr, uint32_t size) const = 0;
  // Live memory only (in-game renderer): makes the renderer's GPU copy of a physical range current
  // before a draw reads it (vertex/index data), and reports CPU writes to ranges a cached object was
  // built from (textures) by setting *invalidated. The replayer uploads everything itself.
  virtual void RequestRange(uint32_t physical, uint32_t size) const {}
  // Live memory only: uploads a range unconditionally without watching it (transient data such as
  // Begin*Vertices data, written once into reused memory).
  virtual void UploadNow(uint32_t physical, uint32_t size) const {}
  virtual void WatchRange(uint32_t physical, uint32_t size, std::shared_ptr<std::atomic<bool>> invalidated) const {}
  // The GPU wrote this range of its guest memory copy (memory export): CPU-side data there is older.
  virtual void GpuWroteRange(uint32_t physical, uint32_t size) const {}

  uint32_t Load32(uint32_t vaddr) const {
    const uint8_t* p = Virtual(vaddr, 4);
    return p ? (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) | p[3] : 0;
  }
  static uint32_t VirtualToPhysical(uint32_t vaddr) {
    return (vaddr & 0x1FFFFFFF) + (vaddr >= 0xE0000000 ? 0x1000 : 0);
  }
};

// Device object offsets (see the findings docs).
namespace dev {
constexpr uint32_t kFetchConstants = 1152;     // 32 x 6 dwords, register 0x4800
constexpr uint32_t kVsFloatConstants = 1920;   // 256 x vec4, register 0x4000
constexpr uint32_t kPsFloatConstants = 6016;   // 256 x vec4, register 0x4400
constexpr uint32_t kBoolLoopConstants = 10112; // register 0x4900 (8 bool + 32 loop dwords)
constexpr uint32_t kRenderTargets = 12440;     // 4 x D3DSurface*
constexpr uint32_t kDepthStencil = 12456;      // D3DSurface*
constexpr uint32_t kIndexBuffer = 12436;       // D3DIndexBuffer*
constexpr uint32_t kVertexDeclaration = 11820;
constexpr uint32_t kPixelShader = 12692;
constexpr uint32_t kVertexShader = 12696;
constexpr uint32_t kSize = 16384;
}  // namespace dev

// Shaders loaded directly with D3DDevice_GpuLoadShaders (most of Fable II's draws) or through
// the device's SetVertexShader/SetPixelShader fields.
struct ShaderState {
  uint32_t vertex_shader = 0;  // guest object address
  uint32_t pixel_shader = 0;   // 0 = depth-only
};

struct ShaderCode {
  uint32_t physical = 0;
  uint32_t dword_count = 0;
  const uint32_t* ucode = nullptr;  // big-endian guest dwords
};

bool GetPixelShaderCode(const GuestMemory& mem, uint32_t ps, ShaderCode* out);
bool GetVertexShaderCode(const GuestMemory& mem, uint32_t vs, uint32_t binding, ShaderCode* out);

// Registers GpuLoadShaders / the shader flush write directly (not in the device shadow):
// SQ_PROGRAM_CNTL, SQ_CONTEXT_MISC, SQ_INTERPOLATOR_CNTL, computed from the shader objects.
void FillShaderRegisters(const GuestMemory& mem, const ShaderState& shaders, rex::graphics::RegisterFile& regs);

// Copies the device shadow (big-endian, kSize bytes) into the register file (host-endian).
void FillRegisters(const uint8_t* device_be, rex::graphics::RegisterFile& regs);

}  // namespace native
