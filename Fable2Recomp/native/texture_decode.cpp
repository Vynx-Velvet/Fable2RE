#include "texture_decode.h"

#include "guest_state.h"

#include <rex/graphics/pipeline/texture/cache.h>
#include <rex/graphics/pipeline/texture/info.h>
#include <rex/graphics/pipeline/texture/util.h>

#include <algorithm>
#include <cstring>

namespace native {

namespace xenos = rex::graphics::xenos;
namespace texture_util = rex::graphics::texture_util;
using rex::graphics::FormatInfo;
using xenos::TextureFormat;

HostFormat GetHostFormat(TextureFormat format) {
  using S = uint32_t;
  const S rgba = xenos::XE_GPU_TEXTURE_SWIZZLE_RGBA, rrrr = xenos::XE_GPU_TEXTURE_SWIZZLE_RRRR,
          rggg = xenos::XE_GPU_TEXTURE_SWIZZLE_RGGG;
  switch (format) {
    case TextureFormat::k_8:
    case TextureFormat::k_8_A:
      return {DXGI_FORMAT_R8_UNORM, rrrr};
    case TextureFormat::k_8_8:
      return {DXGI_FORMAT_R8G8_UNORM, rggg};
    case TextureFormat::k_8_8_8_8:
    case TextureFormat::k_8_8_8_8_AS_16_16_16_16:
      return {DXGI_FORMAT_R8G8B8A8_UNORM, rgba};
    case TextureFormat::k_2_10_10_10:
    case TextureFormat::k_2_10_10_10_AS_16_16_16_16:
      return {DXGI_FORMAT_R10G10B10A2_UNORM, rgba};
    case TextureFormat::k_10_11_11:
    case TextureFormat::k_10_11_11_AS_16_16_16_16:
      return {DXGI_FORMAT_UNKNOWN, rgba};
    case TextureFormat::k_DXT1:
    case TextureFormat::k_DXT1_AS_16_16_16_16:
      return {DXGI_FORMAT_BC1_UNORM, rgba};
    case TextureFormat::k_DXT2_3:
    case TextureFormat::k_DXT2_3_AS_16_16_16_16:
      return {DXGI_FORMAT_BC2_UNORM, rgba};
    case TextureFormat::k_DXT4_5:
    case TextureFormat::k_DXT4_5_AS_16_16_16_16:
      return {DXGI_FORMAT_BC3_UNORM, rgba};
    case TextureFormat::k_DXN:
      return {DXGI_FORMAT_BC5_UNORM, rggg};
    case TextureFormat::k_DXT5A:
      return {DXGI_FORMAT_BC4_UNORM, rrrr};
    case TextureFormat::k_DXT3A:
      return {DXGI_FORMAT_R8_UNORM, rrrr, HostFormat::kDxt3aToR8};
    case TextureFormat::k_16:
      return {DXGI_FORMAT_R16_UNORM, rrrr};
    case TextureFormat::k_16_16:
      return {DXGI_FORMAT_R16G16_UNORM, rggg};
    case TextureFormat::k_16_16_16_16:
      return {DXGI_FORMAT_R16G16B16A16_UNORM, rgba};
    case TextureFormat::k_16_EXPAND:
    case TextureFormat::k_16_FLOAT:
      return {DXGI_FORMAT_R16_FLOAT, rrrr};
    case TextureFormat::k_16_16_EXPAND:
    case TextureFormat::k_16_16_FLOAT:
      return {DXGI_FORMAT_R16G16_FLOAT, rggg};
    case TextureFormat::k_16_16_16_16_EXPAND:
    case TextureFormat::k_16_16_16_16_FLOAT:
      return {DXGI_FORMAT_R16G16B16A16_FLOAT, rgba};
    case TextureFormat::k_32_FLOAT:
      return {DXGI_FORMAT_R32_FLOAT, rrrr};
    case TextureFormat::k_32_32_FLOAT:
      return {DXGI_FORMAT_R32G32_FLOAT, rggg};
    case TextureFormat::k_32_32_32_32_FLOAT:
      return {DXGI_FORMAT_R32G32B32A32_FLOAT, rgba};
    case TextureFormat::k_24_8:
    case TextureFormat::k_24_8_FLOAT:
      return {DXGI_FORMAT_R32_FLOAT, rrrr, HostFormat::kFloat24ToR32};
    default:
      return {};
  }
}

namespace {

void SwapBlock(uint8_t* p, uint32_t bytes, xenos::Endian endian) {
  switch (endian) {
    case xenos::Endian::k8in16:
      for (uint32_t i = 0; i + 1 < bytes; i += 2) std::swap(p[i], p[i + 1]);
      break;
    case xenos::Endian::k8in32:
      for (uint32_t i = 0; i + 3 < bytes; i += 4) {
        std::swap(p[i], p[i + 3]);
        std::swap(p[i + 1], p[i + 2]);
      }
      break;
    case xenos::Endian::k16in32:
      for (uint32_t i = 0; i + 3 < bytes; i += 4) {
        std::swap(p[i], p[i + 2]);
        std::swap(p[i + 1], p[i + 3]);
      }
      break;
    default:
      break;
  }
}

// DXT3A: 4x4 block of 4-bit alpha (8 bytes) -> 16 R8 texels.
void Dxt3aToR8(const uint8_t* block, uint8_t* dst, uint32_t dst_pitch) {
  for (uint32_t y = 0; y < 4; ++y) {
    uint16_t row = uint16_t(block[y * 2]) | (uint16_t(block[y * 2 + 1]) << 8);
    for (uint32_t x = 0; x < 4; ++x) {
      uint32_t a = (row >> (x * 4)) & 0xF;
      dst[y * dst_pitch + x] = uint8_t(a * 17);
    }
  }
}

}  // namespace

bool DecodeTexture(const GuestMemory& mem, const xenos::xe_gpu_texture_fetch_t& fetch, DecodedTexture* out) {
  HostFormat host = GetHostFormat(fetch.format);
  const FormatInfo* info = FormatInfo::Get(fetch.format);
  if (host.dxgi == DXGI_FORMAT_UNKNOWN || !info) return false;
  if (fetch.dimension == xenos::DataDimension::k3D) return false;  // not needed by Fable II yet

  uint32_t w1, h1, d1, base_page, mip_page, mip_min, mip_max;
  texture_util::GetSubresourcesFromFetchConstant(fetch, &w1, &h1, &d1, &base_page, &mip_page, &mip_min,
                                                 &mip_max);
  uint32_t width = w1 + 1, height = h1 + 1, array_size = d1 + 1;
  if (!base_page) return false;
  uint32_t max_level = mip_page ? mip_max : 0;
  auto layout = texture_util::GetGuestTextureLayout(fetch.dimension, fetch.pitch, width, height, array_size,
                                                    fetch.tiled, fetch.format, fetch.packed_mips, true, max_level);

  const uint32_t bw = info->block_width, bh = info->block_height, bpb = info->bytes_per_block();
  const uint32_t bpb_log2 = bpb >= 16 ? 4 : bpb >= 8 ? 3 : bpb >= 4 ? 2 : bpb >= 2 ? 1 : 0;
  const bool r8_out = host.convert == HostFormat::kDxt3aToR8;
  const bool depth_out = host.convert == HostFormat::kFloat24ToR32;

  out->format = host.dxgi;
  out->swizzle = rex::graphics::TextureCache::GuestToHostSwizzle(fetch.swizzle, host.swizzle);
  out->dimension = fetch.dimension;
  out->width = width;
  out->height = height;
  out->array_size = array_size;
  out->mip_levels = max_level + 1;
  out->base_address = base_page << 12;
  out->subresources.clear();
  out->source_ranges.clear();
  out->subresources.resize(size_t(array_size) * out->mip_levels);

  for (uint32_t level = 0; level <= max_level; ++level) {
    const auto& lv = level ? layout.mips[level] : layout.base;
    uint32_t level_base = level ? (mip_page << 12) + layout.mip_offsets_bytes[level] : (base_page << 12);
    uint32_t lw = std::max(width >> level, 1u), lh = std::max(height >> level, 1u);
    uint32_t bx_count = (lw + bw - 1) / bw, by_count = (lh + bh - 1) / bh;
    // Packed mip tail: small levels live inside the packed level's storage at an offset.
    uint32_t ox = 0, oy = 0, oz = 0;
    if (fetch.packed_mips && layout.packed_level != UINT32_MAX && level >= layout.packed_level) {
      texture_util::GetPackedMipOffset(width, height, 1, fetch.format, level, ox, oy, oz);
      const uint32_t pl = layout.packed_level;
      level_base = pl ? (mip_page << 12) + layout.mip_offsets_bytes[pl] : (base_page << 12);
    }
    const auto& storage = (fetch.packed_mips && layout.packed_level != UINT32_MAX && level >= layout.packed_level)
                              ? (layout.packed_level ? layout.mips[layout.packed_level] : layout.base)
                              : lv;
    const uint32_t row_pitch_blocks = storage.row_pitch_bytes / bpb;
    const uint32_t level_bytes = storage.level_data_extent_bytes ? storage.level_data_extent_bytes : storage.row_pitch_bytes;
    const uint8_t* src_all = mem.Physical(level_base, level_bytes);
    if (!src_all) return false;
    out->source_ranges.push_back({level_base, level_bytes});

    for (uint32_t slice = 0; slice < array_size; ++slice) {
      auto& sub = out->subresources[size_t(slice) * out->mip_levels + level];
      sub.width = lw;
      sub.height = lh;
      if (r8_out) {
        sub.row_pitch = bx_count * 4;
        sub.rows = by_count * 4;
      } else if (depth_out) {
        sub.row_pitch = lw * 4;
        sub.rows = lh;
      } else {
        sub.row_pitch = bx_count * bpb;
        sub.rows = by_count;
      }
      sub.data.assign(size_t(sub.row_pitch) * sub.rows, 0);
      const uint8_t* src = src_all + size_t(slice) * storage.array_slice_stride_bytes;
      uint8_t tmp[16];
      for (uint32_t by = 0; by < by_count; ++by) {
        for (uint32_t bx = 0; bx < bx_count; ++bx) {
          int32_t off;
          if (fetch.tiled) {
            off = texture_util::GetTiledOffset2D(int32_t(bx + ox), int32_t(by + oy), row_pitch_blocks, bpb_log2);
          } else {
            off = int32_t((by + oy) * storage.row_pitch_bytes + (bx + ox) * bpb);
          }
          if (off < 0 || uint32_t(off) + bpb > storage.array_slice_stride_bytes + storage.level_data_extent_bytes)
            continue;
          std::memcpy(tmp, src + off, bpb);
          SwapBlock(tmp, bpb, fetch.endianness);
          if (r8_out) {
            Dxt3aToR8(tmp, sub.data.data() + size_t(by) * 4 * sub.row_pitch + bx * 4, sub.row_pitch);
          } else if (depth_out) {
            uint32_t v;
            std::memcpy(&v, tmp, 4);
            float f = xenos::Float20e4To32(v >> 8);
            std::memcpy(sub.data.data() + size_t(by) * sub.row_pitch + bx * 4, &f, 4);
          } else {
            std::memcpy(sub.data.data() + size_t(by) * sub.row_pitch + size_t(bx) * bpb, tmp, bpb);
          }
        }
      }
    }
  }
  return true;
}

}  // namespace native
