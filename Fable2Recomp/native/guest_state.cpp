#include "guest_state.h"

#include <cstring>

#include <rex/graphics/register_file.h>
#include <rex/graphics/registers.h>

namespace native {

using rex::graphics::RegisterFile;
using namespace rex::graphics;  // XE_GPU_REG_* register indices

namespace {

uint32_t BE32(const uint8_t* p) {
  uint32_t v;
  std::memcpy(&v, p, 4);
  return __builtin_bswap32(v);
}

// Register-shadow blocks: device offset, first register, register count (exact sizes from the
// dirty-mask extraction in D3DDevice_DrawIndexedVertices).
struct Block {
  uint32_t offset, reg, count;
};
constexpr Block kBlocks[] = {
    {10368, 0x2000, 16}, {10444, 0x2100, 21}, {10528, 0x2180, 5}, {10548, 0x2200, 12},
    {10596, 0x2280, 21}, {10680, 0x2300, 38}, {10832, 0x2380, 8},
    {dev::kFetchConstants, 0x4800, 192},
    // (Float and bool/loop constants: the renderer keeps its own constant file, merged from the
    // shadow's dirty groups per draw, and overwrites these registers with it.)
};

// Vertex shader binding for GpuLoadShaders: 0 with a pixel shader, else a flag of the object.
uint32_t VertexBinding(const GuestMemory& mem, const ShaderState& s) {
  if (s.pixel_shader) return 0;
  return (mem.Load32(s.vertex_shader + 872) >> 4) & 1;
}

}  // namespace

bool GetPixelShaderCode(const GuestMemory& mem, uint32_t ps, ShaderCode* out) {
  if (!ps) return false;
  uint32_t hdr = ps + mem.Load32(ps + 64);
  uint32_t addr = GuestMemory::VirtualToPhysical(mem.Load32(ps + 24) + mem.Load32(hdr + 40));
  uint32_t size = mem.Load32(hdr + 44);
  const uint8_t* p = size ? mem.Physical(addr, size) : nullptr;
  if (!p) return false;
  *out = {addr, size / 4, reinterpret_cast<const uint32_t*>(p)};
  return true;
}

bool GetVertexShaderCode(const GuestMemory& mem, uint32_t vs, uint32_t binding, ShaderCode* out) {
  if (!vs) return false;
  uint32_t rec = vs + mem.Load32(vs + (binding + 112) * 8);
  uint32_t addr = GuestMemory::VirtualToPhysical(mem.Load32(vs + 32) + mem.Load32(rec + 872));
  uint32_t size = mem.Load32(rec + 876);
  const uint8_t* p = size ? mem.Physical(addr, size) : nullptr;
  if (!p) return false;
  *out = {addr, size / 4, reinterpret_cast<const uint32_t*>(p)};
  return true;
}

void FillShaderRegisters(const GuestMemory& mem, const ShaderState& s, RegisterFile& regs) {
  if (!s.vertex_shader) return;
  uint32_t program_cntl = 0, context_misc = 0, interpolator_cntl = 0, mode = 5;
  if (s.pixel_shader) {
    uint32_t hdr = s.pixel_shader + mem.Load32(s.pixel_shader + 64);
    program_cntl = mem.Load32(hdr + 48);
    context_misc = mem.Load32(hdr + 52);
    interpolator_cntl = mem.Load32(hdr + 64);
    mode = 4;
  }
  uint32_t binding = VertexBinding(mem, s);
  uint32_t rec = s.vertex_shader + mem.Load32(s.vertex_shader + (binding + 112) * 8);
  program_cntl |= mem.Load32(rec + 880);
  context_misc |= mem.Load32(rec + 884);
  regs.values[XE_GPU_REG_SQ_PROGRAM_CNTL] = program_cntl;
  regs.values[XE_GPU_REG_SQ_CONTEXT_MISC] = context_misc;
  regs.values[XE_GPU_REG_SQ_INTERPOLATOR_CNTL] = interpolator_cntl;
  regs.values[XE_GPU_REG_RB_MODECONTROL] = (regs.values[XE_GPU_REG_RB_MODECONTROL] & ~7u) | mode;
}

void FillRegisters(const uint8_t* device_be, RegisterFile& regs) {
  for (const Block& b : kBlocks) {
    for (uint32_t i = 0; i < b.count; ++i) {
      regs.values[b.reg + i] = BE32(device_be + b.offset + i * 4);
    }
  }
  // Window offset / window scissor are written per predicated-tiling tile straight into the
  // command stream (not shadowed). The native renderer draws the whole frame at once: no offset,
  // unlimited window scissor (the screen scissor from the shadow still applies).
  regs.values[XE_GPU_REG_PA_SC_WINDOW_OFFSET] = 0;
  regs.values[XE_GPU_REG_PA_SC_WINDOW_SCISSOR_TL] = 0;
  regs.values[XE_GPU_REG_PA_SC_WINDOW_SCISSOR_BR] = (0x3FFFu << 16) | 0x3FFFu;
}

}  // namespace native
