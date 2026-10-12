// Native renderer: CPU decoding of Xbox 360 textures (untiling, endian swap, format mapping)
// into host (DXGI) texture data. Done once per texture, when it is first used.
#pragma once

#include <dxgiformat.h>

#include <cstdint>
#include <vector>

#include <rex/graphics/xenos.h>

namespace native {

class GuestMemory;

struct HostFormat {
  DXGI_FORMAT dxgi = DXGI_FORMAT_UNKNOWN;
  // Swizzle of the host format relative to the guest components (XE_GPU_TEXTURE_SWIZZLE_*).
  uint32_t swizzle = 0;
  // Special CPU conversion (0 = plain copy of blocks).
  enum Convert : uint32_t { kCopy, kDxt3aToR8, kFloat24ToR32 } convert = kCopy;
};

// Host format for a guest texture format; dxgi == UNKNOWN if unsupported.
HostFormat GetHostFormat(rex::graphics::xenos::TextureFormat format);

struct DecodedTexture {
  DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN;
  uint32_t swizzle = 0;  // host SRV component mapping (3 bits per component)
  rex::graphics::xenos::DataDimension dimension{};
  uint32_t width = 0, height = 0, array_size = 1, mip_levels = 1;
  struct Subresource {
    uint32_t width, height;     // texels
    uint32_t row_pitch;         // bytes per row of blocks in `data`
    uint32_t rows;              // rows of blocks
    std::vector<uint8_t> data;
  };
  std::vector<Subresource> subresources;  // D3D12 order: mip-major within each array slice
  uint32_t base_address = 0;              // guest physical, for identification
  std::vector<std::pair<uint32_t, uint32_t>> source_ranges;  // guest physical ranges read (address, size)
};

// Decodes the texture a fetch constant (host-endian) describes. Returns false if the format
// or dimension is unsupported or the memory is not available.
bool DecodeTexture(const GuestMemory& mem, const rex::graphics::xenos::xe_gpu_texture_fetch_t& fetch,
                   DecodedTexture* out);

}  // namespace native
