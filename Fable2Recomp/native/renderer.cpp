#include "renderer.h"

#include <d3dcompiler.h>

#include <rex/graphics/d3d12/pipeline_cache.h>
#include <rex/graphics/d3d12/shader.h>
#include <rex/graphics/pipeline/shader/dxbc_translator.h>
#include <rex/graphics/pipeline/texture/util.h>
#include <rex/graphics/register_file.h>
#include <rex/graphics/registers.h>
#include <rex/graphics/util/draw.h>
#include <rex/graphics/xenos.h>
#include <rex/hash.h>
#include <rex/string/buffer.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <string_view>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <deque>
#include <unordered_set>

// The SDK's precompiled tessellation stages (vertex shader passing the patch / control point index
// and the hull shaders for each tessellation mode); the guest vertex shader is the domain shader.
namespace native_tess_shaders {
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/adaptive_quad_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/adaptive_triangle_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/continuous_quad_1cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/continuous_quad_4cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/continuous_triangle_1cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/continuous_triangle_3cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/discrete_quad_1cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/discrete_quad_4cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/discrete_triangle_1cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/discrete_triangle_3cp_hs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/tessellation_adaptive_vs.h"
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/tessellation_indexed_vs.h"
// Depth-only pixel shader converting depth to the 20e4 representation (D24FS8 depth buffers).
#include "../../rexglue-sdk/src/graphics/shaders/bytecode/d3d12_5_1/float24_truncate_ps.h"
}  // namespace native_tess_shaders

namespace native {

namespace gfx = rex::graphics;
namespace xenos = gfx::xenos;
namespace reg = gfx::reg;
namespace draw_util = gfx::draw_util;
using gfx::DxbcShaderTranslator;
using gfx::RegisterFile;
using gfx::d3d12::D3D12Shader;
using namespace rex::graphics;  // XE_GPU_REG_* register indices

namespace {

// reg::RB_COLOR_INFO::rt_register_indices / RB_BLENDCONTROL (static data is not exported by the
// runtime DLL).
constexpr uint32_t kColorInfoRegs[4] = {0x2001, 0x2003, 0x2004, 0x2005};
constexpr uint32_t kBlendControlRegs[4] = {0x2201, 0x2209, 0x220A, 0x220B};

uint32_t BE32(const uint8_t* p) {
  return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) | p[3];
}
float BEF(const uint8_t* p) {
  uint32_t v = BE32(p);
  float f;
  std::memcpy(&f, &v, 4);
  return f;
}

uint64_t HashBytes(const void* data, size_t size) { return XXH3_64bits(data, size); }

DXGI_FORMAT ColorFormat(xenos::ColorRenderTargetFormat f) {
  switch (f) {
    case xenos::ColorRenderTargetFormat::k_8_8_8_8:
    case xenos::ColorRenderTargetFormat::k_8_8_8_8_GAMMA:
      return DXGI_FORMAT_R8G8B8A8_UNORM;
    case xenos::ColorRenderTargetFormat::k_2_10_10_10:
    case xenos::ColorRenderTargetFormat::k_2_10_10_10_AS_10_10_10_10:
      return DXGI_FORMAT_R10G10B10A2_UNORM;
    case xenos::ColorRenderTargetFormat::k_2_10_10_10_FLOAT:
    case xenos::ColorRenderTargetFormat::k_2_10_10_10_FLOAT_AS_16_16_16_16:
    case xenos::ColorRenderTargetFormat::k_16_16_16_16_FLOAT:
      return DXGI_FORMAT_R16G16B16A16_FLOAT;
    case xenos::ColorRenderTargetFormat::k_16_16:
      return DXGI_FORMAT_R16G16_SNORM;
    case xenos::ColorRenderTargetFormat::k_16_16_16_16:
      return DXGI_FORMAT_R16G16B16A16_SNORM;
    case xenos::ColorRenderTargetFormat::k_16_16_FLOAT:
      return DXGI_FORMAT_R16G16_FLOAT;
    case xenos::ColorRenderTargetFormat::k_32_FLOAT:
      return DXGI_FORMAT_R32_FLOAT;
    case xenos::ColorRenderTargetFormat::k_32_32_FLOAT:
      return DXGI_FORMAT_R32G32_FLOAT;
    default:
      return DXGI_FORMAT_R8G8B8A8_UNORM;
  }
}

DXGI_FORMAT DepthFormat(xenos::DepthRenderTargetFormat f) {
  return f == xenos::DepthRenderTargetFormat::kD24FS8 ? DXGI_FORMAT_D32_FLOAT_S8X24_UINT
                                                      : DXGI_FORMAT_D24_UNORM_S8_UINT;
}
DXGI_FORMAT DepthTypeless(DXGI_FORMAT f) {
  return f == DXGI_FORMAT_D32_FLOAT_S8X24_UINT ? DXGI_FORMAT_R32G8X24_TYPELESS : DXGI_FORMAT_R24G8_TYPELESS;
}
DXGI_FORMAT DepthSrv(DXGI_FORMAT f) {
  return f == DXGI_FORMAT_D32_FLOAT_S8X24_UINT ? DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
                                               : DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
}

D3D12_BLEND BlendFactor(uint32_t f, bool alpha) {
  static const D3D12_BLEND kColor[17] = {
      D3D12_BLEND_ZERO,        D3D12_BLEND_ONE,           D3D12_BLEND_ZERO,           D3D12_BLEND_ZERO,
      D3D12_BLEND_SRC_COLOR,   D3D12_BLEND_INV_SRC_COLOR, D3D12_BLEND_SRC_ALPHA,      D3D12_BLEND_INV_SRC_ALPHA,
      D3D12_BLEND_DEST_COLOR,  D3D12_BLEND_INV_DEST_COLOR, D3D12_BLEND_DEST_ALPHA,    D3D12_BLEND_INV_DEST_ALPHA,
      D3D12_BLEND_BLEND_FACTOR, D3D12_BLEND_INV_BLEND_FACTOR, D3D12_BLEND_BLEND_FACTOR, D3D12_BLEND_INV_BLEND_FACTOR,
      D3D12_BLEND_SRC_ALPHA_SAT};
  static const D3D12_BLEND kAlpha[17] = {
      D3D12_BLEND_ZERO,        D3D12_BLEND_ONE,           D3D12_BLEND_ZERO,           D3D12_BLEND_ZERO,
      D3D12_BLEND_SRC_ALPHA,   D3D12_BLEND_INV_SRC_ALPHA, D3D12_BLEND_SRC_ALPHA,      D3D12_BLEND_INV_SRC_ALPHA,
      D3D12_BLEND_DEST_ALPHA,  D3D12_BLEND_INV_DEST_ALPHA, D3D12_BLEND_DEST_ALPHA,    D3D12_BLEND_INV_DEST_ALPHA,
      D3D12_BLEND_BLEND_FACTOR, D3D12_BLEND_INV_BLEND_FACTOR, D3D12_BLEND_BLEND_FACTOR, D3D12_BLEND_INV_BLEND_FACTOR,
      D3D12_BLEND_SRC_ALPHA_SAT};
  return f < 17 ? (alpha ? kAlpha[f] : kColor[f]) : D3D12_BLEND_ZERO;
}
D3D12_BLEND_OP BlendOp(uint32_t op) {
  static const D3D12_BLEND_OP k[8] = {D3D12_BLEND_OP_ADD, D3D12_BLEND_OP_SUBTRACT, D3D12_BLEND_OP_MIN,
                                      D3D12_BLEND_OP_MAX, D3D12_BLEND_OP_REV_SUBTRACT, D3D12_BLEND_OP_ADD,
                                      D3D12_BLEND_OP_ADD, D3D12_BLEND_OP_ADD};
  return k[op & 7];
}
D3D12_COMPARISON_FUNC CompareFunc(xenos::CompareFunction f) {
  static const D3D12_COMPARISON_FUNC k[8] = {
      D3D12_COMPARISON_FUNC_NEVER,        D3D12_COMPARISON_FUNC_LESS,    D3D12_COMPARISON_FUNC_EQUAL,
      D3D12_COMPARISON_FUNC_LESS_EQUAL,   D3D12_COMPARISON_FUNC_GREATER, D3D12_COMPARISON_FUNC_NOT_EQUAL,
      D3D12_COMPARISON_FUNC_GREATER_EQUAL, D3D12_COMPARISON_FUNC_ALWAYS};
  return k[uint32_t(f) & 7];
}
D3D12_STENCIL_OP StencilOp(xenos::StencilOp op) {
  static const D3D12_STENCIL_OP k[8] = {D3D12_STENCIL_OP_KEEP,     D3D12_STENCIL_OP_ZERO,
                                        D3D12_STENCIL_OP_REPLACE,  D3D12_STENCIL_OP_INCR_SAT,
                                        D3D12_STENCIL_OP_DECR_SAT, D3D12_STENCIL_OP_INVERT,
                                        D3D12_STENCIL_OP_INCR,     D3D12_STENCIL_OP_DECR};
  return k[uint32_t(op) & 7];
}

D3D12_TEXTURE_ADDRESS_MODE AddressMode(xenos::ClampMode m) {
  switch (m) {
    case xenos::ClampMode::kRepeat:
      return D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    case xenos::ClampMode::kMirroredRepeat:
      return D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
    case xenos::ClampMode::kClampToEdge:
      return D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    case xenos::ClampMode::kMirrorClampToEdge:
      return D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE;
    default:
      return D3D12_TEXTURE_ADDRESS_MODE_BORDER;
  }
}

// Fullscreen-triangle blit used by Resolve (and debug readback): copies a rectangle of a source
// texture (optionally multisampled / depth) into a render target of any format.
const char kBlitHlsl[] = R"(
cbuffer c : register(b0) { int2 src_origin; int2 dst_origin; float scale; uint sample_mode; uint2 pad; };
Texture2D<float4> src : register(t0);
Texture2DMS<float4> src_ms : register(t1);
void vs(uint id : SV_VertexID, out float4 pos : SV_Position) {
  float2 uv = float2((id << 1) & 2, id & 2);
  pos = float4(uv * float2(2, -2) + float2(-1, 1), 0, 1);
}
float4 ps(float4 pos : SV_Position) : SV_Target {
  int2 p = int2(pos.xy) - dst_origin + src_origin;
  float4 v;
  if (sample_mode == 0) v = src.Load(int3(p, 0));
  else if (sample_mode == 1) v = src_ms.Load(p, 0);
  else v = (src_ms.Load(p, 0) + src_ms.Load(p, 1)) * 0.5;
  return v * scale;
}
)";

}  // namespace

struct Renderer::PassItem {
  int kind = 0;  // 0 draw, 1 clear, 2 resolve
  uint32_t seq = 0;
  std::vector<uint8_t> device;
  ShaderState shaders;
  DrawArgs args;
  std::vector<uint32_t> vs_code, ps_code;
  std::vector<uint8_t> up_vertex, up_index;
  uint32_t up_index_physical = 0;
  ClearArgs clear;
  ResolveArgs resolve;
  // Constant file changes since the previous recorded draw: {block index u16, 16 dwords} per changed
  // 64-byte block (the first draw of a section starts from Impl::items_const_base).
  std::vector<uint32_t> const_delta;
  std::vector<uint8_t> overlay_list;
  std::vector<std::pair<uint32_t, uint32_t>> overlay;  // (value, shadow) of the listed entries
  std::shared_ptr<void> packet;  // Impl::DrawPacket recorded by the depth pre-pass
};

struct Renderer::Impl {
  ID3D12Device* device = nullptr;
  ID3D12CommandQueue* queue = nullptr;
  ComPtr<ID3D12CommandAllocator> allocator;  // (unused; per-slot allocators below)
  // Command list state set by the last draw (redundant calls are skipped: the driver does real work
  // for each, e.g. a root signature change rebinds everything). Invalidated by anything else that
  // records state (blits, new command lists).
  struct StateCache {
    bool valid = false;
    ID3D12RootSignature* root = nullptr;
    ID3D12PipelineState* pso = nullptr;
    D3D_PRIMITIVE_TOPOLOGY topology = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;
    D3D12_VIEWPORT viewport{};
    D3D12_RECT scissor{};
    float blend[4] = {};
    UINT stencil_ref = ~0u;
    UINT rt_count = ~0u;
    D3D12_CPU_DESCRIPTOR_HANDLE rtvs[4]{};
    D3D12_CPU_DESCRIPTOR_HANDLE dsv{};
    bool has_ds = false;
    D3D12_INDEX_BUFFER_VIEW ibv{};
    uint64_t tables[5] = {};  // root parameters 5.. (shared memory, textures, samplers)
    D3D12_GPU_VIRTUAL_ADDRESS cbs[5] = {};  // root parameters 0..4 (constant buffers)
  } state;
  uint64_t shared_gpu_va = 0;
  // Bumped when recorded command list data (upload ring, view heap, sampler heap) is recycled.
  uint64_t submit_epoch = 0, sampler_epoch = 0;
  // A draw's command list state, as recorded: the depth pre-pass keeps it so the main pass can issue
  // the same draw into the real render targets without preparing it again (see RunDeferred).
  struct DrawPacket {
    bool valid = false;
    uint64_t submit_epoch = 0, sampler_epoch = 0;
    uint32_t rt_count = 0;
    D3D12_CPU_DESCRIPTOR_HANDLE rtvs[4]{};
    uint32_t rt_key[4] = {};  // 0: hole (null view)
    DXGI_FORMAT rt_format[4] = {};
    uint32_t ds_key = 0;
    DXGI_FORMAT ds_format = DXGI_FORMAT_UNKNOWN;
    D3D12_CPU_DESCRIPTOR_HANDLE dsv{};
    bool has_ds = false;
    uint32_t width = 0, height = 0, samples = 1;
    D3D12_VIEWPORT viewport{};
    D3D12_RECT scissor{};
    float blend[4] = {};
    UINT stencil_ref = 0;
    ID3D12PipelineState* pso = nullptr;
    ID3D12RootSignature* root = nullptr;
    D3D12_GPU_VIRTUAL_ADDRESS cb[5] = {};
    uint32_t table_count = 0;
    D3D12_GPU_DESCRIPTOR_HANDLE tables[5]{};
    D3D_PRIMITIVE_TOPOLOGY topology = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;
    bool indexed = false;
    D3D12_INDEX_BUFFER_VIEW ibv{};
    uint32_t count = 0, start = 0;
    std::vector<std::pair<void*, ID3D12Resource*>> textures;  // (Texture*, its resource then)
  };
  DrawPacket* capture_packet = nullptr;  // the pre-pass draw being recorded
  void EmitDraw(const DrawPacket& pk, bool memexport, bool state_cache) {
    Transition(shared.Get(), shared_state,
               memexport ? D3D12_RESOURCE_STATE_UNORDERED_ACCESS
                         : D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE | D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE |
                               D3D12_RESOURCE_STATE_INDEX_BUFFER);
    auto& st = state;
    if (!state_cache) st.valid = false;  // (diagnostics: re-set all state on every draw)
    const bool fresh = !st.valid;
    st.valid = true;
    {
      bool rt_same = !fresh && st.rt_count == pk.rt_count && st.has_ds == pk.has_ds && (!pk.has_ds || st.dsv.ptr == pk.dsv.ptr);
      for (uint32_t i = 0; rt_same && i < pk.rt_count; ++i) rt_same = st.rtvs[i].ptr == pk.rtvs[i].ptr;
      if (!rt_same) {
        list->OMSetRenderTargets(pk.rt_count, pk.rt_count ? pk.rtvs : nullptr, FALSE, pk.has_ds ? &pk.dsv : nullptr);
        st.rt_count = pk.rt_count;
        for (uint32_t i = 0; i < pk.rt_count; ++i) st.rtvs[i] = pk.rtvs[i];
        st.has_ds = pk.has_ds;
        st.dsv = pk.has_ds ? pk.dsv : D3D12_CPU_DESCRIPTOR_HANDLE{};
      }
    }
    if (fresh || std::memcmp(&st.viewport, &pk.viewport, sizeof(pk.viewport))) {
      list->RSSetViewports(1, &pk.viewport);
      st.viewport = pk.viewport;
    }
    if (fresh || std::memcmp(&st.scissor, &pk.scissor, sizeof(pk.scissor))) {
      list->RSSetScissorRects(1, &pk.scissor);
      st.scissor = pk.scissor;
    }
    if (fresh || std::memcmp(st.blend, pk.blend, sizeof(pk.blend))) {
      list->OMSetBlendFactor(pk.blend);
      std::memcpy(st.blend, pk.blend, sizeof(pk.blend));
    }
    if (fresh || st.stencil_ref != pk.stencil_ref) {
      list->OMSetStencilRef(pk.stencil_ref);
      st.stencil_ref = pk.stencil_ref;
    }
    if (fresh || st.pso != pk.pso) {
      list->SetPipelineState(pk.pso);
      st.pso = pk.pso;
    }
    if (fresh || st.root != pk.root) {
      list->SetGraphicsRootSignature(pk.root);
      st.root = pk.root;
      for (auto& t : st.tables) t = 0;
      for (auto& c : st.cbs) c = 0;
    }
    for (uint32_t i = 0; i < 5; ++i) {
      if (st.cbs[i] != pk.cb[i]) {
        list->SetGraphicsRootConstantBufferView(i, pk.cb[i]);
        st.cbs[i] = pk.cb[i];
      }
    }
    for (uint32_t i = 0; i < pk.table_count; ++i) {
      if (st.tables[i] != pk.tables[i].ptr) {
        list->SetGraphicsRootDescriptorTable(5 + i, pk.tables[i]);
        st.tables[i] = pk.tables[i].ptr;
      }
    }
    if (fresh || st.topology != pk.topology) {
      list->IASetPrimitiveTopology(pk.topology);
      st.topology = pk.topology;
    }
    if (pk.indexed) {
      if (fresh || std::memcmp(&st.ibv, &pk.ibv, sizeof(pk.ibv))) {
        list->IASetIndexBuffer(&pk.ibv);
        st.ibv = pk.ibv;
      }
      list->DrawIndexedInstanced(pk.count, 1, 0, 0, 0);
    } else {
      list->DrawInstanced(pk.count, 1, pk.start, 0);
    }
  }
  // Submissions in flight: each slot has its own allocator, upload ring half, view heap range and
  // retired-resource list, reused once the GPU has passed the slot's fence. The CPU records the next
  // frame while the GPU executes the previous one.
  static constexpr uint32_t kSlots = 2;
  struct Slot {
    ComPtr<ID3D12CommandAllocator> allocator;
    uint64_t fence = 0;
    std::vector<ComPtr<ID3D12Resource>> retired;
  };
  Slot slots[kSlots];
  uint32_t slot = 0;
  ComPtr<ID3D12GraphicsCommandList> list;
  ComPtr<ID3D12Fence> fence;
  uint64_t fence_value = 0;
  HANDLE fence_event = nullptr;
  bool recording = false;

  // Guest physical memory mirror.
  static constexpr uint64_t kSharedSize = 0x20000000;
  ComPtr<ID3D12Resource> shared;
  D3D12_RESOURCE_STATES shared_state = D3D12_RESOURCE_STATE_COPY_DEST;

  // Upload ring (constants + memory updates), reset every frame.
  static constexpr uint64_t kUploadSize = 256ull << 20;
  static constexpr uint64_t kUploadSlotSize = kUploadSize / 2;  // per in-flight submission
  ComPtr<ID3D12Resource> upload;
  uint8_t* upload_cpu = nullptr;
  uint64_t upload_offset = 0;

  // Descriptor heaps.
  ComPtr<ID3D12DescriptorHeap> view_heap, sampler_heap, rtv_heap, dsv_heap;
  uint32_t view_inc = 0, sampler_inc = 0, rtv_inc = 0, dsv_inc = 0;
  uint32_t view_next = 0, rtv_next = 0, dsv_next = 0;
  // Texture SRV tables written in the current submission, by binding content (consecutive draws
  // mostly bind the same textures; the view heap region stays valid until the submission ends).
  std::unordered_map<uint64_t, uint32_t> srv_tables;
  // Texture tables by the raw fetch constants of the bindings (see bind_textures): reused without
  // looking the textures up while none of them was rewritten or replaced. Per submission.
  struct Texture;
  struct FastTable {
    uint32_t table;
    uint64_t epoch, resolve_generation;
    std::vector<std::pair<Texture*, uint32_t>> textures;  // (texture, guest base) per binding
  };
  std::unordered_map<uint64_t, FastTable> fast_tables;
  uint64_t resolve_generation = 0;  // bumped when a resolved texture gets a new host resource
  static constexpr uint32_t kViewHeapSize = 262144, kSamplerHeapSize = 2048;
  static constexpr uint32_t kPersistentViews = 16;  // [0] shared SRV, [1] shared UAV, null SRVs at 2..4
  static constexpr uint32_t kViewSlotSize = (kViewHeapSize - kPersistentViews) / kSlots;
  uint32_t ViewSlotBegin() const { return kPersistentViews + slot * kViewSlotSize; }
  uint32_t ViewSlotEnd() const { return ViewSlotBegin() + kViewSlotSize; }
  uint32_t sampler_next = 0;
  std::unordered_map<uint64_t, uint32_t> sampler_tables;  // hash of sampler descs -> heap index
  // Sampler tables by their inputs (bindings + fetch constant words), skipping the descriptor build.
  std::unordered_map<uint64_t, D3D12_GPU_DESCRIPTOR_HANDLE> sampler_input_tables;

  // Shaders.
  std::unique_ptr<DxbcShaderTranslator> translator;
  rex::string::StringBuffer disasm;
  std::unordered_map<uint64_t, std::unique_ptr<D3D12Shader>> shaders;

  // Root signatures by (vs tex, vs samp, ps tex, ps samp).
  std::unordered_map<uint32_t, ComPtr<ID3D12RootSignature>> root_signatures;
  // Pipelines by description hash (session-local key: includes shader object pointers).
  struct PipelineJob;
  struct PipelineEntry {
    ComPtr<ID3D12PipelineState> pso;
    std::atomic<int> state{0};  // 0 compiling, 1 ready, 2 failed
    std::atomic<bool> claimed{false};   // a compile thread took it
    std::atomic<bool> expedited{false};  // moved to the front of the queue by a draw
    std::shared_ptr<PipelineJob> job;    // until compiled
    std::mutex job_mutex;
  };
  // Time draws may still spend waiting for pipelines this frame (reset at the frame's end).
  int64_t pipeline_wait_left_us = 0;
  std::unordered_map<uint64_t, std::shared_ptr<PipelineEntry>> pipelines;
  // The same entries by a stable key (hash of the shader bytecode and all state): shared with the
  // pipelines compiled from the disk cache at startup.
  std::mutex stable_mutex;
  std::unordered_map<uint64_t, std::shared_ptr<PipelineEntry>> pipelines_by_stable;
  // Background compilation.
  std::mutex compile_mutex;
  std::condition_variable compile_cv;
  std::deque<std::function<void()>> compile_jobs;
  std::vector<std::thread> compile_threads;
  std::atomic<uint64_t> pipelines_created_async{0}, pipelines_failed_async{0}, pipeline_us_async{0};
  // Disk cache.
  std::string pipeline_cache_path;
  std::mutex cache_file_mutex;
  std::unordered_set<uint64_t> cached_on_disk;
  std::mutex root_mutex;
  std::unordered_map<uint64_t, std::vector<uint32_t>> geometry_shaders;

  struct RenderTarget {
    ComPtr<ID3D12Resource> resource;
    DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN;
    bool depth = false;
    uint32_t width = 0, height = 0, samples = 1;
    D3D12_CPU_DESCRIPTOR_HANDLE view{};
    D3D12_RESOURCE_STATES state = D3D12_RESOURCE_STATE_COMMON;
    int32_t slot = -1;  // index in the RTV or DSV heap
  };
  std::unordered_map<uint32_t, RenderTarget> render_targets;
  std::vector<int32_t> free_rtv, free_dsv;
  static constexpr uint32_t kRtvHeapSize = 4096, kDsvHeapSize = 1024;  // by guest surface address

  struct Texture {
    ComPtr<ID3D12Resource> resource;
    DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN;
    uint32_t swizzle = 0;
    xenos::DataDimension dimension{};
    uint32_t width = 0, height = 0, array_size = 1, mips = 1;
    D3D12_RESOURCE_STATES state = D3D12_RESOURCE_STATE_COMMON;
    bool failed = false;
    // Resolved with RB_COPY_DEST_INFO's red/blue swap: guest memory (and this copy) hold the channels
    // swapped relative to the render target; the display scan-out swaps them back.
    bool red_blue_swapped = false;
    // Resolved copies: made from a depth buffer, and in which frame (see Renderer::Draw).
    bool from_depth = false;
    uint64_t resolve_frame = 0;
    // Set (from any thread) when the CPU writes guest memory this texture was decoded from.
    std::shared_ptr<std::atomic<bool>> stale;
    // Guest memory the texture was decoded from and its content hash: watches are page-granular, so
    // a write next to the texture also fires; the hash tells whether the texture itself changed.
    std::vector<std::pair<uint32_t, uint32_t>> source_ranges;
    uint64_t source_hash = 0;
    // CPU rewrites in nearby frames: a texture rewritten again and again is animated from the CPU
    // (video planes); one rewritten once is streaming.
    uint64_t last_rewrite_frame = 0;
    uint32_t rewrite_streak = 0;
  };
  std::unordered_map<uint64_t, Texture> textures;    // by fetch constant key
  std::unordered_map<uint32_t, Texture> resolved;    // by guest base address (host RT copies)
  std::unordered_map<uint64_t, Texture> resolved_pool;  // parked copies by (address, format, size)

  // Resolve blit.
  ComPtr<ID3D12RootSignature> blit_root;
  ComPtr<ID3DBlob> blit_vs, blit_ps;
  std::unordered_map<uint32_t, ComPtr<ID3D12PipelineState>> blit_pipelines;  // by DXGI format

  RegisterFile regs;
  // GPU constant registers 0x4000..0x4927 (float VS/PS, fetch, bool/loop), host-endian.
  static constexpr uint32_t kConstBase = 0x4000, kConstCount = 0x928;
  uint32_t constants[kConstCount] = {};
  bool constants_initialized = false;
  Stats* stats = nullptr;
  // Resources replaced while the current command list may still reference them; released after
  // the GPU has finished the list.
  std::vector<ComPtr<ID3D12Resource>> retired;
  std::vector<uint32_t> probe_seqs;
  struct FetchOverlay {
    uint32_t value, shadow;
  };
  // Overlaid fetch constant registers (0x4800 + index), see WriteFetchConstants: a fixed table plus
  // the list of active entries (walked on every draw).
  FetchOverlay fetch_overlay[192] = {};
  bool fetch_overlay_active[192] = {};
  std::vector<uint8_t> fetch_overlay_list;
  // Real-time depth (see renderer.h).
  uint64_t frame_index = 1;
  std::vector<Renderer::PassItem> items;  // recorded calls (pool: entries keep their capacity)
  size_t items_used = 0;
  // Constant file when the first recorded draw of the section was recorded, and as of the latest
  // recorded draw (the base of the next draw's delta).
  bool items_const_valid = false;
  uint32_t items_const_base[kConstCount] = {};
  uint32_t items_const_last[kConstCount] = {};
  void ResetItems() {
    items_used = 0;
    items_const_valid = false;
  }
  bool pass_has_plain_draw = false;    // a draw not reading earlier-frame depth came first
  uint32_t pass_prev_depth_base = 0;   // earlier-frame depth texture the pass reads
  uint32_t last_draw_prev_depth = 0;   // set while binding the current draw's textures
  bool deferring = false;              // recording instead of drawing
  uint32_t defer_depth = 0;            // depth texture whose resolve ends the deferred section
  const GuestMemory* defer_mem = nullptr;
  bool replaying = false;
  void NotePrevDepthBase(const Texture* t, uint32_t base) {
    if (t && t->from_depth && t->resolve_frame < frame_index) last_draw_prev_depth = base;
  }
  void NotePrevDepth(const Texture* t, const xenos::xe_gpu_texture_fetch_t& fetch) {
    if (!t || !t->from_depth || t->resolve_frame >= frame_index) return;
    uint32_t tb = uint32_t(fetch.base_address) << 12;
    if (tb >= 0xA0000000) tb = GuestMemory::VirtualToPhysical(tb);
    last_draw_prev_depth = tb;
  }
  ComPtr<ID3D12Resource> present_tmp;  // PresentFrontbuffer's format-conversion target
  struct History {
    Texture tex;
    uint32_t frame = 0;
    bool valid = false;
  };
  History history[Renderer::kHistoryFrames];
  // Occlusion queries: heap + persistently mapped readback (one uint64 per query).
  static constexpr uint32_t kQueries = 1024;
  ComPtr<ID3D12QueryHeap> query_heap;
  ComPtr<ID3D12Resource> query_readback;
  const uint64_t* query_map = nullptr;
  uint32_t query_next = 0;
  int32_t active_query = -1;
  std::vector<uint32_t> queries_resolved;  // resolved in the current command list
  uint64_t query_fence[kQueries] = {};
  void EndActiveQuery() {
    if (active_query < 0) return;
    uint32_t i = uint32_t(active_query);
    list->EndQuery(query_heap.Get(), D3D12_QUERY_TYPE_OCCLUSION, i);
    list->ResolveQueryData(query_heap.Get(), D3D12_QUERY_TYPE_OCCLUSION, i, 1, query_readback.Get(), uint64_t(i) * 8);
    queries_resolved.push_back(i);
    active_query = -1;
  }
  uint32_t history_next = 0;
  D3D12_RESOURCE_STATES present_tmp_state = D3D12_RESOURCE_STATE_COMMON;  // debug pixel probe: draw seq per probe texel

  // ---------------------------------------------------------------------------------------------

  void Transition(ID3D12Resource* r, D3D12_RESOURCE_STATES& state, D3D12_RESOURCE_STATES to) {
    if (state == to) return;
    D3D12_RESOURCE_BARRIER b{};
    b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    b.Transition.pResource = r;
    b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    b.Transition.StateBefore = state;
    b.Transition.StateAfter = to;
    list->ResourceBarrier(1, &b);
    state = to;
  }

  // Suballocates upload memory for the current submission: the main ring, then overflow buffers
  // (kept alive until the submission completes) - never a mid-draw flush, which would recycle memory
  // and descriptors the draw being recorded already references.
  bool Upload(const void* data, uint64_t size, uint64_t align, D3D12_GPU_VIRTUAL_ADDRESS* gpu, uint64_t* offset_out,
              ID3D12Resource** resource_out = nullptr, uint8_t** cpu_out = nullptr) {
    ID3D12Resource* res = upload.Get();
    uint8_t* cpu = upload_cpu;
    uint64_t off = (upload_offset + align - 1) & ~(align - 1);
    if (off + size <= kUploadSlotSize) {
      upload_offset = off + size;
      off += uint64_t(slot) * kUploadSlotSize;
    } else {
      off = (overflow_offset + align - 1) & ~(align - 1);
      if (!overflow || off + size > overflow_size) {
        if (overflow) retired.push_back(overflow);
        overflow.Reset();
        overflow_size = std::max<uint64_t>(64ull << 20, size + align);
        D3D12_RESOURCE_DESC bd{};
        bd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
        bd.Width = overflow_size;
        bd.Height = 1;
        bd.DepthOrArraySize = 1;
        bd.MipLevels = 1;
        bd.SampleDesc.Count = 1;
        bd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
        D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_UPLOAD};
        if (FAILED(device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &bd, D3D12_RESOURCE_STATE_GENERIC_READ,
                                                   nullptr, IID_PPV_ARGS(&overflow)))) {
          overflow.Reset();
          return false;
        }
        D3D12_RANGE none{0, 0};
        overflow->Map(0, &none, reinterpret_cast<void**>(&overflow_cpu));
        off = 0;
      }
      overflow_offset = off + size;
      res = overflow.Get();
      cpu = overflow_cpu;
    }
    if (data) std::memcpy(cpu + off, data, size);
    if (gpu) *gpu = res->GetGPUVirtualAddress() + off;
    if (offset_out) *offset_out = off;
    if (resource_out) *resource_out = res;
    if (cpu_out) *cpu_out = cpu;
    return true;
  }
  // Constant buffer uploads that repeat the previous draw's bytes for the same slot reuse its memory
  // (valid for the rest of the submission), so the root argument does not change either.
  struct DedupSlot {
    std::vector<uint8_t> bytes;
    D3D12_GPU_VIRTUAL_ADDRESS gpu = 0;
    uint64_t epoch = ~0ull;
  };
  DedupSlot dedup[5];
  void UploadDedup(int id, const void* data, uint32_t size, D3D12_GPU_VIRTUAL_ADDRESS* gpu) {
    DedupSlot& d = dedup[id];
    if (d.epoch == submit_epoch && d.bytes.size() == size && std::memcmp(d.bytes.data(), data, size) == 0) {
      *gpu = d.gpu;
      return;
    }
    Upload(data, size, 256, gpu, nullptr);
    d.bytes.assign(static_cast<const uint8_t*>(data), static_cast<const uint8_t*>(data) + size);
    d.gpu = *gpu;
    d.epoch = submit_epoch;
  }
  ComPtr<ID3D12Resource> overflow;
  uint8_t* overflow_cpu = nullptr;
  uint64_t overflow_size = 0, overflow_offset = 0;
  uint64_t sampler_tables_used = 0;  // sampler descriptors allocated in the current submission

  D3D12_CPU_DESCRIPTOR_HANDLE ViewCpu(uint32_t i) const {
    auto h = view_heap->GetCPUDescriptorHandleForHeapStart();
    h.ptr += size_t(i) * view_inc;
    return h;
  }
  D3D12_GPU_DESCRIPTOR_HANDLE ViewGpu(uint32_t i) const {
    auto h = view_heap->GetGPUDescriptorHandleForHeapStart();
    h.ptr += uint64_t(i) * view_inc;
    return h;
  }

  void EnsureRecording() {
    if (recording) return;
    state.valid = false;
    // (After a Flush the slot's allocator still backs submitted lists: append, don't reset.)
    if (!continue_slot) slots[slot].allocator->Reset();
    continue_slot = false;
    list->Reset(slots[slot].allocator.Get(), nullptr);
    ID3D12DescriptorHeap* heaps[] = {view_heap.Get(), sampler_heap.Get()};
    list->SetDescriptorHeaps(2, heaps);
    recording = true;
  }

  void WaitForFence(uint64_t value) {
    if (fence->GetCompletedValue() >= value) return;
    auto t0 = std::chrono::steady_clock::now();
    fence->SetEventOnCompletion(value, fence_event);
    WaitForSingleObject(fence_event, INFINITE);
    stats->wait_us += uint64_t(
        std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
  }

  // Submits the recorded work. With `wait`, blocks until the GPU has finished everything (readbacks,
  // heap recycling); otherwise moves on to the next slot, waiting only for that slot's previous use.
  void Submit(bool wait) {
    if (!recording) return;
    EndActiveQuery();  // queries cannot span command lists (the count so far is reported)
    list->Close();
    ID3D12CommandList* lists[] = {list.Get()};
    queue->ExecuteCommandLists(1, lists);
    queue->Signal(fence.Get(), ++fence_value);
    ++stats->submits;
    recording = false;
    Slot& done = slots[slot];
    done.fence = fence_value;
    for (uint32_t q : queries_resolved) query_fence[q] = fence_value;
    queries_resolved.clear();
    for (auto& r : retired) done.retired.push_back(std::move(r));
    retired.clear();
    if (overflow) done.retired.push_back(overflow);
    overflow.Reset();
    overflow_offset = overflow_size = 0;
    if (wait) {
      WaitForFence(fence_value);
      for (auto& sl : slots) sl.retired.clear();
    }
    slot = (slot + 1) % kSlots;
    WaitForFence(slots[slot].fence);
    slots[slot].retired.clear();
    upload_offset = 0;
    view_next = ViewSlotBegin();
    ++submit_epoch;
    srv_tables.clear();
    fast_tables.clear();
    sampler_tables_used = 0;
  }
  void SubmitAndWait() { Submit(true); }

  // Submits the work recorded so far and keeps recording into the same slot (its upload ring and
  // view heap ranges keep growing; no wait). For results needed before the frame ends.
  bool continue_slot = false;
  void Flush() {
    if (!recording) return;
    EndActiveQuery();
    list->Close();
    ID3D12CommandList* lists[] = {list.Get()};
    queue->ExecuteCommandLists(1, lists);
    queue->Signal(fence.Get(), ++fence_value);
    ++stats->submits;
    for (uint32_t q : queries_resolved) query_fence[q] = fence_value;
    queries_resolved.clear();
    recording = false;
    continue_slot = true;
  }

  // ---------------------------------------------------------------------------------------------
  // Shaders

  D3D12Shader* GetShader(const ShaderCode& code, xenos::ShaderType type, uint64_t known_hash = 0) {
    uint64_t hash = (known_hash ? known_hash : HashBytes(code.ucode, size_t(code.dword_count) * 4)) ^
                    (uint64_t(type) << 63);
    auto it = shaders.find(hash);
    if (it != shaders.end()) return it->second.get();
    auto s = std::make_unique<D3D12Shader>(type, hash, code.ucode, code.dword_count);
    try {
      s->AnalyzeUcode(disasm);
    } catch (...) {
      // Not valid microcode (e.g. a misidentified load): remember it as unusable.
      ++stats->shaders_failed;
      shaders.emplace(hash, nullptr);
      return nullptr;
    }
    return shaders.emplace(hash, std::move(s)).first->second.get();
  }

  D3D12Shader::D3D12Translation* Translate(D3D12Shader* s, uint64_t modification) {
    bool is_new = false;
    auto* t = static_cast<D3D12Shader::D3D12Translation*>(s->GetOrCreateTranslation(modification, &is_new));
    if (!t->is_translated()) {
      auto t0 = std::chrono::steady_clock::now();
      struct Timer {
        std::chrono::steady_clock::time_point t0;
        uint64_t& acc;
        ~Timer() {
          acc += uint64_t(
              std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
        }
      } timer{t0, stats->translate_us};
      if (translator->TranslateAnalyzedShader(*t) && t->is_valid()) {
        ++stats->shaders_translated;
      } else {
        ++stats->shaders_failed;
      }
    }
    return t->is_valid() ? t : nullptr;
  }

  // ---------------------------------------------------------------------------------------------
  // Pipeline compilation (background threads) and the persistent pipeline cache

  // A pipeline description with its shader bytecode owned (for background compilation and the cache).
  struct PipelineJob {
    D3D12_GRAPHICS_PIPELINE_STATE_DESC desc{};
    uint32_t root_key = 0;
    std::vector<uint8_t> blobs[5];  // VS, PS, DS, HS, GS
    uint64_t stable = 0;
    void Own(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& d) {
      desc = d;
      const D3D12_SHADER_BYTECODE* in[5] = {&d.VS, &d.PS, &d.DS, &d.HS, &d.GS};
      for (int i = 0; i < 5; ++i) {
        const uint8_t* p = static_cast<const uint8_t*>(in[i]->pShaderBytecode);
        blobs[i].assign(p, p + (p ? in[i]->BytecodeLength : 0));
      }
      Point();
    }
    void Point() {
      D3D12_SHADER_BYTECODE* out[5] = {&desc.VS, &desc.PS, &desc.DS, &desc.HS, &desc.GS};
      for (int i = 0; i < 5; ++i) *out[i] = {blobs[i].empty() ? nullptr : blobs[i].data(), blobs[i].size()};
    }
    // Hash of everything but pointers.
    uint64_t StableKey() const {
      D3D12_GRAPHICS_PIPELINE_STATE_DESC d = desc;
      d.pRootSignature = nullptr;
      d.VS = d.PS = d.DS = d.HS = d.GS = {};
      d.StreamOutput = {};
      d.InputLayout = {};
      d.CachedPSO = {};
      uint64_t h = HashBytes(&d, sizeof(d)) ^ (uint64_t(root_key) * 0x9E3779B97F4A7C15ull);
      for (int i = 0; i < 5; ++i)
        h = h * 31 + (blobs[i].empty() ? 0 : HashBytes(blobs[i].data(), blobs[i].size())) + i;
      return h;
    }
  };

  void StartCompileThreads() {
    if (!compile_threads.empty()) return;
    unsigned n = std::max(2u, std::min(4u, std::thread::hardware_concurrency() / 4));
    for (unsigned i = 0; i < n; ++i)
      compile_threads.emplace_back([this] {
        SetThreadDescription(GetCurrentThread(), L"Native Pipeline Compiler");
        SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);
        for (;;) {
          std::function<void()> job;
          {
            std::unique_lock<std::mutex> l(compile_mutex);
            compile_cv.wait(l, [this] { return !compile_jobs.empty(); });
            job = std::move(compile_jobs.front());
            compile_jobs.pop_front();
          }
          job();
        }
      });
    for (auto& t : compile_threads) t.detach();
  }

  void Compile(const std::shared_ptr<PipelineJob>& job, const std::shared_ptr<PipelineEntry>& entry, bool store) {
    if (entry->claimed.exchange(true)) return;  // (queued twice: expedited by a draw)
    {
      std::lock_guard<std::mutex> l(entry->job_mutex);
      entry->job.reset();
    }
    auto t0 = std::chrono::steady_clock::now();
    job->desc.pRootSignature = GetRootSignatureByKey(job->root_key);
    ComPtr<ID3D12PipelineState> p;
    HRESULT hr = job->desc.pRootSignature ? device->CreateGraphicsPipelineState(&job->desc, IID_PPV_ARGS(&p)) : E_FAIL;
    pipeline_us_async += uint64_t(
        std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
    if (FAILED(hr)) {
      ++pipelines_failed_async;
      entry->state.store(2, std::memory_order_release);
      return;
    }
    entry->pso = p;
    entry->state.store(1, std::memory_order_release);
    ++pipelines_created_async;
    if (store) StoreToDisk(*job);
  }

  // Cache file: records of {u32 magic, u64 stable key, u32 root key, desc (pointers zeroed), 5 x (u32
  // size, bytes)}.
  static constexpr uint32_t kCacheMagic = 0x50534F31;  // "PSO1"
  void StoreToDisk(const PipelineJob& job) {
    if (pipeline_cache_path.empty()) return;
    std::lock_guard<std::mutex> l(cache_file_mutex);
    if (!cached_on_disk.insert(job.stable).second) return;
    FILE* f = std::fopen(pipeline_cache_path.c_str(), "ab");
    if (!f) return;
    D3D12_GRAPHICS_PIPELINE_STATE_DESC d = job.desc;
    d.pRootSignature = nullptr;
    d.VS = d.PS = d.DS = d.HS = d.GS = {};
    std::fwrite(&kCacheMagic, 4, 1, f);
    std::fwrite(&job.stable, 8, 1, f);
    std::fwrite(&job.root_key, 4, 1, f);
    std::fwrite(&d, sizeof(d), 1, f);
    for (const auto& b : job.blobs) {
      uint32_t n = uint32_t(b.size());
      std::fwrite(&n, 4, 1, f);
      if (n) std::fwrite(b.data(), 1, n, f);
    }
    std::fclose(f);
  }

  void LoadDiskCache() {
    FILE* f = std::fopen(pipeline_cache_path.c_str(), "rb");
    if (!f) return;
    uint32_t loaded = 0;
    for (;;) {
      auto job = std::make_shared<PipelineJob>();
      uint32_t magic = 0;
      if (std::fread(&magic, 4, 1, f) != 1 || magic != kCacheMagic) break;
      if (std::fread(&job->stable, 8, 1, f) != 1 || std::fread(&job->root_key, 4, 1, f) != 1 ||
          std::fread(&job->desc, sizeof(job->desc), 1, f) != 1)
        break;
      bool ok = true;
      for (auto& b : job->blobs) {
        uint32_t n = 0;
        if (std::fread(&n, 4, 1, f) != 1 || n > (16u << 20)) {
          ok = false;
          break;
        }
        b.resize(n);
        if (n && std::fread(b.data(), 1, n, f) != n) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
      job->Point();
      auto entry = std::make_shared<PipelineEntry>();
      entry->job = job;
      {
        std::lock_guard<std::mutex> l(stable_mutex);
        if (!pipelines_by_stable.emplace(job->stable, entry).second) continue;
      }
      {
        std::lock_guard<std::mutex> l(cache_file_mutex);
        cached_on_disk.insert(job->stable);
      }
      {
        std::lock_guard<std::mutex> l(compile_mutex);
        compile_jobs.push_back([this, job, entry] { Compile(job, entry, false); });
      }
      compile_cv.notify_one();
      ++loaded;
    }
    std::fclose(f);
    std::fprintf(stderr, "native renderer: compiling %u cached pipelines in the background\n", loaded);
  }

  // A draw needs this pipeline now: compile it next (ahead of the cache warm-up).
  void Expedite(const std::shared_ptr<PipelineEntry>& entry) {
    if (entry->claimed.load() || entry->expedited.exchange(true)) return;
    std::shared_ptr<PipelineJob> job;
    {
      std::lock_guard<std::mutex> l(entry->job_mutex);
      job = entry->job;
    }
    if (!job) return;
    {
      std::lock_guard<std::mutex> l(compile_mutex);
      compile_jobs.push_front([this, job, entry] { Compile(job, entry, true); });
    }
    compile_cv.notify_one();
  }

  // The pipeline for a description: an existing entry (also one compiled from the disk cache), or a
  // new one compiled now (synchronously) or on the compile threads.
  std::shared_ptr<PipelineEntry> RequestPipeline(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& d, uint32_t root_key,
                                                 bool async) {
    auto job = std::make_shared<PipelineJob>();
    job->root_key = root_key;
    job->Own(d);
    job->stable = job->StableKey();
    std::shared_ptr<PipelineEntry> entry;
    {
      std::lock_guard<std::mutex> l(stable_mutex);
      auto it = pipelines_by_stable.find(job->stable);
      if (it != pipelines_by_stable.end()) return it->second;
      entry = std::make_shared<PipelineEntry>();
      entry->job = job;
      pipelines_by_stable.emplace(job->stable, entry);
    }
    if (async) {
      StartCompileThreads();
      {
        std::lock_guard<std::mutex> l(compile_mutex);
        compile_jobs.push_front([this, job, entry] { Compile(job, entry, true); });  // ahead of cache warm-up
      }
      compile_cv.notify_one();
    } else {
      Compile(job, entry, true);
    }
    return entry;
  }

  // ---------------------------------------------------------------------------------------------
  // Root signatures (bindful layout of the DXBC translator)

  static uint32_t RootKey(uint32_t vs_tex, uint32_t vs_samp, uint32_t ps_tex, uint32_t ps_samp, bool tessellated) {
    return vs_tex | (vs_samp << 8) | (ps_tex << 16) | ((ps_samp & 0x7F) << 24) | (tessellated ? 1u << 31 : 0);
  }
  ID3D12RootSignature* GetRootSignatureByKey(uint32_t key) {
    return GetRootSignature(key & 0xFF, (key >> 8) & 0xFF, (key >> 16) & 0xFF, (key >> 24) & 0x7F, (key >> 31) != 0);
  }
  ID3D12RootSignature* GetRootSignature(uint32_t vs_tex, uint32_t vs_samp, uint32_t ps_tex, uint32_t ps_samp,
                                        bool tessellated) {
    // (Also called from the pipeline cache loader thread.)
    std::lock_guard<std::mutex> root_lock(root_mutex);
    uint32_t key = RootKey(vs_tex, vs_samp, ps_tex, ps_samp, tessellated);
    const D3D12_SHADER_VISIBILITY vertex_vis =
        tessellated ? D3D12_SHADER_VISIBILITY_DOMAIN : D3D12_SHADER_VISIBILITY_VERTEX;
    auto it = root_signatures.find(key);
    if (it != root_signatures.end()) return it->second.Get();
    std::vector<D3D12_ROOT_PARAMETER> params;
    auto cbv = [&](uint32_t reg, D3D12_SHADER_VISIBILITY vis) {
      D3D12_ROOT_PARAMETER p{};
      p.ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
      p.Descriptor.ShaderRegister = reg;
      p.ShaderVisibility = vis;
      params.push_back(p);
    };
    // Same order as D3D12CommandProcessor's bindful root signature.
    cbv(uint32_t(DxbcShaderTranslator::CbufferRegister::kFetchConstants), D3D12_SHADER_VISIBILITY_ALL);
    cbv(uint32_t(DxbcShaderTranslator::CbufferRegister::kFloatConstants), vertex_vis);
    cbv(uint32_t(DxbcShaderTranslator::CbufferRegister::kFloatConstants), D3D12_SHADER_VISIBILITY_PIXEL);
    cbv(uint32_t(DxbcShaderTranslator::CbufferRegister::kSystemConstants), D3D12_SHADER_VISIBILITY_ALL);
    cbv(uint32_t(DxbcShaderTranslator::CbufferRegister::kBoolLoopConstants), D3D12_SHADER_VISIBILITY_ALL);
    D3D12_DESCRIPTOR_RANGE shared_ranges[2]{};
    shared_ranges[0].RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
    shared_ranges[0].NumDescriptors = 1;
    shared_ranges[0].BaseShaderRegister = uint32_t(DxbcShaderTranslator::SRVMainRegister::kSharedMemory);
    shared_ranges[0].RegisterSpace = uint32_t(DxbcShaderTranslator::SRVSpace::kMain);
    shared_ranges[0].OffsetInDescriptorsFromTableStart = 0;
    shared_ranges[1].RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
    shared_ranges[1].NumDescriptors = 1;
    shared_ranges[1].BaseShaderRegister = uint32_t(DxbcShaderTranslator::UAVRegister::kSharedMemory);
    shared_ranges[1].OffsetInDescriptorsFromTableStart = 1;
    {
      D3D12_ROOT_PARAMETER p{};
      p.ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
      p.DescriptorTable.NumDescriptorRanges = 2;
      p.DescriptorTable.pDescriptorRanges = shared_ranges;
      p.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
      params.push_back(p);
    }
    D3D12_DESCRIPTOR_RANGE ranges[4]{};
    auto table = [&](int i, D3D12_DESCRIPTOR_RANGE_TYPE type, uint32_t count, uint32_t base_reg, uint32_t space,
                     D3D12_SHADER_VISIBILITY vis) {
      ranges[i].RangeType = type;
      ranges[i].NumDescriptors = count;
      ranges[i].BaseShaderRegister = base_reg;
      ranges[i].RegisterSpace = space;
      ranges[i].OffsetInDescriptorsFromTableStart = 0;
      D3D12_ROOT_PARAMETER p{};
      p.ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
      p.DescriptorTable.NumDescriptorRanges = 1;
      p.DescriptorTable.pDescriptorRanges = &ranges[i];
      p.ShaderVisibility = vis;
      params.push_back(p);
    };
    const uint32_t tex_reg = uint32_t(DxbcShaderTranslator::SRVMainRegister::kBindfulTexturesStart);
    const uint32_t tex_space = uint32_t(DxbcShaderTranslator::SRVSpace::kMain);
    if (ps_tex) table(0, D3D12_DESCRIPTOR_RANGE_TYPE_SRV, ps_tex, tex_reg, tex_space, D3D12_SHADER_VISIBILITY_PIXEL);
    if (ps_samp) table(1, D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER, ps_samp, 0, 0, D3D12_SHADER_VISIBILITY_PIXEL);
    if (vs_tex) table(2, D3D12_DESCRIPTOR_RANGE_TYPE_SRV, vs_tex, tex_reg, tex_space, vertex_vis);
    if (vs_samp) table(3, D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER, vs_samp, 0, 0, vertex_vis);
    D3D12_ROOT_SIGNATURE_DESC desc{};
    desc.NumParameters = UINT(params.size());
    desc.pParameters = params.data();
    desc.Flags = D3D12_ROOT_SIGNATURE_FLAG_NONE;
    ComPtr<ID3DBlob> blob, err;
    if (FAILED(D3D12SerializeRootSignature(&desc, D3D_ROOT_SIGNATURE_VERSION_1, &blob, &err))) {
      std::fprintf(stderr, "root signature: %s\n", err ? (const char*)err->GetBufferPointer() : "?");
      return nullptr;
    }
    ComPtr<ID3D12RootSignature> rs;
    device->CreateRootSignature(0, blob->GetBufferPointer(), blob->GetBufferSize(), IID_PPV_ARGS(&rs));
    root_signatures[key] = rs;
    return rs.Get();
  }

  // ---------------------------------------------------------------------------------------------
  // Render targets

  // D3DSurface +36: high 16 bits = (width - 1) * 4, low 16 bits = (height - 1) * 8. With predicated
  // tiling this is one tile; the full frame height comes from the viewport.
  static void SurfaceSize(const GuestMemory& mem, uint32_t surface, uint32_t* w, uint32_t* h) {
    uint32_t v = mem.Load32(surface + 36);
    *w = (v >> 16) / 4 + 1;
    *h = (v & 0xFFFF) / 8 + 1;
  }

  // Host render targets are keyed by where the surface lives in EDRAM (D3DSurface +28: EDRAM base and
  // format, as RB_COLOR_INFO / RB_DEPTH_INFO; +24 bits 16-17: MSAA), not by the surface object: the
  // game creates new surface objects every frame for the same EDRAM, and a recycled object address
  // must not bring back another pass's content. (On the console, surfaces sharing EDRAM also share
  // their contents.)
  static inline thread_local bool rt_private = false;
  static uint32_t RtKey(const GuestMemory& mem, uint32_t surface, bool depth) {
    if (!surface) return 0;
    static const bool by_object = std::getenv("NATIVE_RT_KEY_OBJECT") != nullptr;  // (diagnostics)
    if (by_object) return surface;
    uint32_t info = mem.Load32(surface + 28), si = mem.Load32(surface + 24);
    // Re-run passes draw into their own render targets (the EDRAM they used is in use again by then).
    return 0x80000000u | (rt_private ? 1u << 27 : 0) | (depth ? 1u << 30 : 0) | ((si >> 16) & 3) << 28 | ((info >> 16) & 0xF) << 12 | (info & 0xFFF);
  }

  RenderTarget* GetRenderTarget(uint32_t surface, DXGI_FORMAT format, bool depth, uint32_t width, uint32_t height,
                                uint32_t samples) {
    auto& rt = render_targets[surface];
    if (rt.resource && rt.format == format && rt.samples == samples && rt.width >= width && rt.height >= height)
      return &rt;
    width = std::max(width, rt.width);
    height = std::max(height, rt.height);
    RenderTarget old = rt;
    if (old.resource) retired.push_back(old.resource);
    state.valid = false;  // the RTV/DSV slot may be rewritten for the new resource
    // Descriptor slot: reuse the replaced target's slot when the kind matches (RTV/DSV heaps are
    // CPU-only and command lists copy the descriptor when recorded, so rewriting it is safe).
    int32_t slot = -1;
    if (old.resource) {
      if (old.depth == depth) slot = old.slot;
      else (old.depth ? free_dsv : free_rtv).push_back(old.slot);
    }
    rt = RenderTarget{};
    D3D12_RESOURCE_DESC d{};
    d.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    d.Width = width;
    d.Height = height;
    d.DepthOrArraySize = 1;
    d.MipLevels = 1;
    d.Format = depth ? DepthTypeless(format) : format;
    d.SampleDesc.Count = samples;
    d.Flags = depth ? D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL : D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
    D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_DEFAULT};
    D3D12_CLEAR_VALUE cv{};
    cv.Format = format;
    if (depth) cv.DepthStencil.Depth = 1.0f;
    if (FAILED(device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &d, D3D12_RESOURCE_STATE_COMMON, &cv,
                                               IID_PPV_ARGS(&rt.resource)))) {
      if (slot >= 0) (depth ? free_dsv : free_rtv).push_back(slot);
      render_targets.erase(surface);
      return nullptr;
    }
    rt.format = format;
    rt.depth = depth;
    rt.width = width;
    rt.height = height;
    rt.samples = samples;
    rt.state = D3D12_RESOURCE_STATE_COMMON;
    if (slot < 0) {
      auto& free_list = depth ? free_dsv : free_rtv;
      if (!free_list.empty()) {
        slot = free_list.back();
        free_list.pop_back();
      } else {
        uint32_t& next = depth ? dsv_next : rtv_next;
        // RTV slots 4094/4095 are the null view and the blit scratch view.
        if (next >= (depth ? kDsvHeapSize : kRtvHeapSize - 2)) {
          render_targets.erase(surface);
          return nullptr;
        }
        slot = int32_t(next++);
      }
    }
    rt.slot = slot;
    if (depth) {
      rt.view = dsv_heap->GetCPUDescriptorHandleForHeapStart();
      rt.view.ptr += size_t(slot) * dsv_inc;
      D3D12_DEPTH_STENCIL_VIEW_DESC vd{};
      vd.Format = format;
      vd.ViewDimension = samples > 1 ? D3D12_DSV_DIMENSION_TEXTURE2DMS : D3D12_DSV_DIMENSION_TEXTURE2D;
      device->CreateDepthStencilView(rt.resource.Get(), &vd, rt.view);
    } else {
      rt.view = rtv_heap->GetCPUDescriptorHandleForHeapStart();
      rt.view.ptr += size_t(slot) * rtv_inc;
      D3D12_RENDER_TARGET_VIEW_DESC vd{};
      vd.Format = format;
      vd.ViewDimension = samples > 1 ? D3D12_RTV_DIMENSION_TEXTURE2DMS : D3D12_RTV_DIMENSION_TEXTURE2D;
      device->CreateRenderTargetView(rt.resource.Get(), &vd, rt.view);
    }
    // Keep the contents when a target grows (same format and sample count only).
    if (old.resource && old.format == format && old.samples == samples && samples == 1) {
      Transition(old.resource.Get(), old.state, D3D12_RESOURCE_STATE_COPY_SOURCE);
      Transition(rt.resource.Get(), rt.state, D3D12_RESOURCE_STATE_COPY_DEST);
      D3D12_TEXTURE_COPY_LOCATION src{old.resource.Get(), D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX, {}}, dst{};
      dst.pResource = rt.resource.Get();
      dst.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
      D3D12_BOX box{0, 0, 0, old.width, old.height, 1};
      list->CopyTextureRegion(&dst, 0, 0, 0, &src, &box);
    }
    return &rt;
  }

  // ---------------------------------------------------------------------------------------------
  // Textures

  static uint64_t TextureKey(const xenos::xe_gpu_texture_fetch_t& f) {
    uint32_t d[6] = {f.dword_0, f.dword_1, f.dword_2, f.dword_3 & 0x1FFF /* format bits, not filters */, f.dword_4,
                     f.dword_5};
    d[0] &= ~(0x7u << 10 | 0x7u << 13 | 0x7u << 16);  // clamp modes are sampler state
    d[4] &= 0x3C;                                      // only mip_min_level matters for the resource
    d[3] = f.dword_3 & 0x1;                            // num_format
    return HashBytes(d, sizeof(d));
  }

  static uint64_t HashSource(const GuestMemory& mem, const std::vector<std::pair<uint32_t, uint32_t>>& ranges) {
    uint64_t h = 0x9E3779B97F4A7C15ull;
    for (const auto& r : ranges) {
      const uint8_t* p = mem.Physical(r.first, r.second);
      h = (h * 0x100000001B3ull) ^ (p ? HashBytes(p, r.second) : 0);
    }
    return h;
  }

  // Arms the CPU-write watches of a decoded texture. The memory is hashed again after arming: a write
  // between the decode and the arming (which the watch cannot see) marks the texture stale at once.
  static void ArmTextureWatch(const GuestMemory& mem, Texture& t) {
    t.stale->store(false, std::memory_order_release);
    for (const auto& r : t.source_ranges) mem.WatchRange(r.first, r.second, t.stale);
    if (HashSource(mem, t.source_ranges) != t.source_hash) t.stale->store(true, std::memory_order_release);
  }

  uint64_t texture_epoch = 0;  // bumped when a cached texture entry is removed (pointers to it die)
  Texture* GetTexture(const GuestMemory& mem, const xenos::xe_gpu_texture_fetch_t& fetch) {
    uint32_t base = uint32_t(fetch.base_address) << 12;
    if (base >= 0xA0000000) base = GuestMemory::VirtualToPhysical(base);
    auto rit = resolved.find(base);
    if (rit != resolved.end() && rit->second.stale && rit->second.stale->load(std::memory_order_acquire)) {
      ++stats->resolved_stale;
      if (rit->second.resource) retired.push_back(rit->second.resource);
      resolved.erase(rit);
      ++texture_epoch;
      rit = resolved.end();
    }
    if (rit != resolved.end()) {
      rit->second.swizzle = gfx::TextureCache::GuestToHostSwizzle(fetch.swizzle, GetHostFormat(fetch.format).swizzle);
      return &rit->second;
    }
    uint64_t key = TextureKey(fetch);
    auto it = textures.find(key);
    if (it != textures.end() && it->second.stale && it->second.stale->load(std::memory_order_acquire) &&
        !it->second.source_ranges.empty()) {
      auto t0 = std::chrono::steady_clock::now();
      if (HashSource(mem, it->second.source_ranges) == it->second.source_hash) {
        // A neighbouring write on a shared page: the texture's own bytes are unchanged.
        ++stats->textures_revalidated;
        ArmTextureWatch(mem, it->second);
      }
      stats->revalidate_us += uint64_t(
          std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
    }
    if (it != textures.end() && it->second.stale && it->second.stale->load(std::memory_order_acquire) &&
        !it->second.failed && it->second.resource) {
      // The texture's memory was rewritten: decode it again into the same host texture when the
      // shape is unchanged (allocating GPU memory is far more expensive than the upload).
      DecodedTexture dec;
      auto t0 = std::chrono::steady_clock::now();
      if (DecodeTexture(mem, fetch, &dec) && SameShape(dec, it->second) && UploadTexture(dec, it->second)) {
        stats->texture_us += uint64_t(
            std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
        ++stats->textures_stale;
        ++stats->textures_reuploaded;
        Texture& t = it->second;
        if (frame_index - t.last_rewrite_frame <= 3) {
          if (++t.rewrite_streak >= 2) ++stats->textures_animated;
        } else {
          t.rewrite_streak = 0;
        }
        t.last_rewrite_frame = frame_index;
        t.swizzle = gfx::TextureCache::GuestToHostSwizzle(fetch.swizzle, GetHostFormat(fetch.format).swizzle);
        t.source_ranges = dec.source_ranges;
        t.source_hash = HashSource(mem, t.source_ranges);
        ArmTextureWatch(mem, t);
        srv_tables.clear();
    fast_tables.clear();  // (tables are keyed by resource, which is unchanged; contents changed)
        return &t;
      }
    }
    if (it != textures.end() && it->second.stale && it->second.stale->load(std::memory_order_acquire)) {
      ++stats->textures_stale;
      if (it->second.resource) retired.push_back(it->second.resource);
      textures.erase(it);
      ++texture_epoch;
      it = textures.end();
    }
    if (it != textures.end()) {
      if (it->second.failed) return nullptr;
      // The swizzle is per binding (not part of the cache key): the same texture data is fetched with
      // different component orders by different shaders.
      it->second.swizzle = gfx::TextureCache::GuestToHostSwizzle(fetch.swizzle, GetHostFormat(fetch.format).swizzle);
      return &it->second;
    }
    Texture& t = textures[key];
    DecodedTexture dec;
    auto t0 = std::chrono::steady_clock::now();
    bool ok = DecodeTexture(mem, fetch, &dec) && CreateTexture(dec, t);
    stats->texture_us += uint64_t(
        std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
    if (!ok) {
      t.failed = true;
      ++stats->textures_failed;
      return nullptr;
    }
    t.stale = std::make_shared<std::atomic<bool>>(false);
    t.source_ranges = dec.source_ranges;
    t.source_hash = HashSource(mem, t.source_ranges);
    ArmTextureWatch(mem, t);
    ++stats->textures_created;
    stats->last_created_base = base;
    stats->last_created_format = uint32_t(fetch.format);
    stats->last_created_width = dec.width;
    return &t;
  }

  // Creates a host texture from decoded guest data and records its upload.
  bool CreateTexture(const DecodedTexture& dec, Texture& t) {
    D3D12_RESOURCE_DESC d{};
    d.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    d.Width = dec.width;
    d.Height = dec.height;
    d.DepthOrArraySize = UINT16(dec.array_size);
    d.MipLevels = UINT16(dec.mip_levels);
    d.Format = dec.format;
    d.SampleDesc.Count = 1;
    // Block-compressed textures need 4-aligned base dimensions.
    if (dec.format >= DXGI_FORMAT_BC1_TYPELESS && dec.format <= DXGI_FORMAT_BC5_SNORM) {
      d.Width = (d.Width + 3) & ~3ull;
      d.Height = (d.Height + 3) & ~3u;
    }
    D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_DEFAULT};
    if (FAILED(device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &d, D3D12_RESOURCE_STATE_COPY_DEST,
                                               nullptr, IID_PPV_ARGS(&t.resource)))) {
      return false;
    }
    t.format = dec.format;
    t.swizzle = dec.swizzle;
    t.dimension = dec.dimension;
    t.width = uint32_t(d.Width);
    t.height = d.Height;
    t.array_size = dec.array_size;
    t.mips = dec.mip_levels;
    t.state = D3D12_RESOURCE_STATE_COPY_DEST;
    ++stats->textures_allocated;
    return UploadTexture(dec, t);
  }

  // Whether a decoded texture fits an existing host texture (same shape and format).
  static bool SameShape(const DecodedTexture& dec, const Texture& t) {
    uint32_t w = dec.width, h = dec.height;
    if (dec.format >= DXGI_FORMAT_BC1_TYPELESS && dec.format <= DXGI_FORMAT_BC5_SNORM) {
      w = (w + 3) & ~3u;
      h = (h + 3) & ~3u;
    }
    return t.resource && t.format == dec.format && t.width == w && t.height == h && t.array_size == dec.array_size &&
           t.mips == dec.mip_levels;
  }

  // Uploads decoded data into the texture (its state becomes COPY_DEST; the transition barrier makes
  // earlier GPU reads of the old contents finish first, including work of submissions in flight).
  bool UploadTexture(const DecodedTexture& dec, Texture& t) {
    Transition(t.resource.Get(), t.state, D3D12_RESOURCE_STATE_COPY_DEST);
    D3D12_RESOURCE_DESC d = t.resource->GetDesc();
    // Upload every subresource through the upload ring.
    uint32_t sub_count = dec.array_size * dec.mip_levels;
    std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT> fp(sub_count);
    std::vector<UINT> rows(sub_count);
    std::vector<UINT64> row_bytes(sub_count);
    UINT64 total = 0;
    device->GetCopyableFootprints(&d, 0, sub_count, 0, fp.data(), rows.data(), row_bytes.data(), &total);
    uint64_t base_off;
    ID3D12Resource* up_res = nullptr;
    uint8_t* up_cpu = nullptr;
    if (!Upload(nullptr, total, D3D12_TEXTURE_DATA_PLACEMENT_ALIGNMENT, nullptr, &base_off, &up_res, &up_cpu))
      return false;
    for (uint32_t i = 0; i < sub_count; ++i) {
      const auto& sub = dec.subresources[i];
      uint8_t* dst = up_cpu + base_off + fp[i].Offset;
      uint32_t copy_rows = std::min<uint32_t>(rows[i], sub.rows);
      uint32_t copy_bytes = uint32_t(std::min<uint64_t>(row_bytes[i], sub.row_pitch));
      for (uint32_t r = 0; r < copy_rows; ++r) {
        std::memcpy(dst + size_t(r) * fp[i].Footprint.RowPitch, sub.data.data() + size_t(r) * sub.row_pitch,
                    copy_bytes);
      }
      D3D12_TEXTURE_COPY_LOCATION src{}, dstl{};
      src.pResource = up_res;
      src.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
      src.PlacedFootprint = fp[i];
      src.PlacedFootprint.Offset += base_off;
      dstl.pResource = t.resource.Get();
      dstl.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
      dstl.SubresourceIndex = i;
      list->CopyTextureRegion(&dstl, 0, 0, 0, &src, nullptr);
    }
    return true;
  }

  void WriteTextureSrv(uint32_t slot, Texture* t, xenos::FetchOpDimension dim) {
    D3D12_SHADER_RESOURCE_VIEW_DESC sd{};
    uint32_t swz = t ? t->swizzle : 0;
    // 3 bits per component, same encoding as D3D12 (0-3 components, 4 = 0, 5 = 1).
    sd.Shader4ComponentMapping = D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING(swz & 7, (swz >> 3) & 7, (swz >> 6) & 7,
                                                                         (swz >> 9) & 7);
    sd.Format = t ? t->format : DXGI_FORMAT_R8G8B8A8_UNORM;
    if (t && t->format == DXGI_FORMAT_D32_FLOAT_S8X24_UINT) sd.Format = DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS;
    switch (dim) {
      case xenos::FetchOpDimension::kCube:
        sd.ViewDimension = D3D12_SRV_DIMENSION_TEXTURECUBE;
        sd.TextureCube.MipLevels = t ? t->mips : 1;
        if (t && t->array_size < 6) t = nullptr;
        break;
      case xenos::FetchOpDimension::k3DOrStacked:
        sd.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE3D;
        sd.Texture3D.MipLevels = 1;
        t = nullptr;  // 3D textures not decoded yet
        break;
      default:
        sd.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2DARRAY;
        sd.Texture2DArray.MipLevels = t ? t->mips : 1;
        sd.Texture2DArray.ArraySize = t ? t->array_size : 1;
        break;
    }
    if (!t) sd.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    device->CreateShaderResourceView(t ? t->resource.Get() : nullptr, &sd, ViewCpu(slot));
  }

  D3D12_SAMPLER_DESC SamplerDesc(const xenos::xe_gpu_texture_fetch_t& f,
                                 const gfx::DxbcShader::SamplerBinding& b) {
    auto filter = [](xenos::TextureFilter binding, xenos::TextureFilter fetch) {
      return binding == xenos::TextureFilter::kUseFetchConst ? fetch : binding;
    };
    xenos::TextureFilter mag = filter(b.mag_filter, f.mag_filter), min = filter(b.min_filter, f.min_filter),
                         mip = filter(b.mip_filter, f.mip_filter);
    xenos::AnisoFilter aniso =
        b.aniso_filter == xenos::AnisoFilter::kUseFetchConst ? f.aniso_filter : b.aniso_filter;
    D3D12_SAMPLER_DESC s{};
    if (aniso != xenos::AnisoFilter::kDisabled && uint32_t(aniso) <= 5) {
      s.Filter = D3D12_FILTER_ANISOTROPIC;
      s.MaxAnisotropy = 1u << (uint32_t(aniso) - 1);
    } else {
      bool mag_l = mag == xenos::TextureFilter::kLinear, min_l = min == xenos::TextureFilter::kLinear,
           mip_l = mip == xenos::TextureFilter::kLinear;
      s.Filter = D3D12_ENCODE_BASIC_FILTER(min_l ? D3D12_FILTER_TYPE_LINEAR : D3D12_FILTER_TYPE_POINT,
                                           mag_l ? D3D12_FILTER_TYPE_LINEAR : D3D12_FILTER_TYPE_POINT,
                                           mip_l ? D3D12_FILTER_TYPE_LINEAR : D3D12_FILTER_TYPE_POINT,
                                           D3D12_FILTER_REDUCTION_TYPE_STANDARD);
      s.MaxAnisotropy = 1;
    }
    xenos::ClampMode cx, cy, cz;
    gfx::texture_util::GetClampModesForDimension(f, cx, cy, cz);
    s.AddressU = AddressMode(cx);
    s.AddressV = AddressMode(cy);
    s.AddressW = AddressMode(cz);
    s.MipLODBias = float(int32_t(f.lod_bias) ) / 32.0f;
    s.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
    float bc = f.border_color == xenos::BorderColor::k_ABGR_White ? 1.0f : 0.0f;
    s.BorderColor[0] = s.BorderColor[1] = s.BorderColor[2] = bc;
    s.BorderColor[3] = f.border_color == xenos::BorderColor::k_ABGR_Black ? 1.0f : bc;
    s.MinLOD = float(f.mip_min_level);
    s.MaxLOD = mip == xenos::TextureFilter::kBaseMap ? float(f.mip_min_level) : float(f.mip_max_level);
    static const bool base_only = std::getenv("NATIVE_DEBUG_MIP0") != nullptr;
    if (base_only) s.MinLOD = s.MaxLOD = 0.0f;
    return s;
  }

  // Sampler tables are deduplicated (the shader-visible sampler heap only has 2048 entries).
  bool SamplerTable(const std::vector<D3D12_SAMPLER_DESC>& descs, D3D12_GPU_DESCRIPTOR_HANDLE* out) {
    uint64_t h = HashBytes(descs.data(), descs.size() * sizeof(D3D12_SAMPLER_DESC));
    auto it = sampler_tables.find(h);
    uint32_t index;
    if (it != sampler_tables.end()) {
      index = it->second;
    } else {
      if (sampler_next + descs.size() > kSamplerHeapSize) {
        // Heap full: everything recorded so far must finish before entries are reused.
        SubmitAndWait();
        EnsureRecording();
        sampler_tables.clear();
        sampler_input_tables.clear();
        sampler_next = 0;
        ++sampler_epoch;
      }
      index = sampler_next;
      sampler_next += uint32_t(descs.size());
      sampler_tables_used += descs.size();
      auto cpu = sampler_heap->GetCPUDescriptorHandleForHeapStart();
      for (size_t i = 0; i < descs.size(); ++i) {
        D3D12_CPU_DESCRIPTOR_HANDLE hnd = cpu;
        hnd.ptr += size_t(index + i) * sampler_inc;
        device->CreateSampler(&descs[i], hnd);
      }
      sampler_tables[h] = index;
    }
    *out = sampler_heap->GetGPUDescriptorHandleForHeapStart();
    out->ptr += uint64_t(index) * sampler_inc;
    return true;
  }

  // ---------------------------------------------------------------------------------------------
  // Blit (Resolve)

  bool InitBlit() {
    ComPtr<ID3DBlob> err;
    if (FAILED(D3DCompile(kBlitHlsl, sizeof(kBlitHlsl) - 1, "blit", nullptr, nullptr, "vs", "vs_5_0", 0, 0,
                          &blit_vs, &err)) ||
        FAILED(D3DCompile(kBlitHlsl, sizeof(kBlitHlsl) - 1, "blit", nullptr, nullptr, "ps", "ps_5_0", 0, 0,
                          &blit_ps, &err))) {
      std::fprintf(stderr, "blit shader: %s\n", err ? (const char*)err->GetBufferPointer() : "?");
      return false;
    }
    D3D12_DESCRIPTOR_RANGE range{D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 2, 0, 0, 0};
    D3D12_ROOT_PARAMETER p[2]{};
    p[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
    p[0].Constants.Num32BitValues = 8;
    p[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
    p[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    p[1].DescriptorTable.NumDescriptorRanges = 1;
    p[1].DescriptorTable.pDescriptorRanges = &range;
    p[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
    D3D12_ROOT_SIGNATURE_DESC rd{2, p, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_NONE};
    ComPtr<ID3DBlob> blob;
    if (FAILED(D3D12SerializeRootSignature(&rd, D3D_ROOT_SIGNATURE_VERSION_1, &blob, &err))) return false;
    return SUCCEEDED(device->CreateRootSignature(0, blob->GetBufferPointer(), blob->GetBufferSize(),
                                                 IID_PPV_ARGS(&blit_root)));
  }

  ID3D12PipelineState* BlitPipeline(DXGI_FORMAT format) {
    auto it = blit_pipelines.find(format);
    if (it != blit_pipelines.end()) return it->second.Get();
    D3D12_GRAPHICS_PIPELINE_STATE_DESC d{};
    d.pRootSignature = blit_root.Get();
    d.VS = {blit_vs->GetBufferPointer(), blit_vs->GetBufferSize()};
    d.PS = {blit_ps->GetBufferPointer(), blit_ps->GetBufferSize()};
    d.BlendState.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    d.SampleMask = UINT_MAX;
    d.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
    d.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
    d.RasterizerState.DepthClipEnable = TRUE;
    d.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    d.NumRenderTargets = 1;
    d.RTVFormats[0] = format;
    d.SampleDesc.Count = 1;
    ComPtr<ID3D12PipelineState> pso;
    device->CreateGraphicsPipelineState(&d, IID_PPV_ARGS(&pso));
    blit_pipelines[format] = pso;
    return pso.Get();
  }

  // Copies src (RT or texture) rect -> dst texture at dst origin, converting formats in the shader.
  void Blit(ID3D12Resource* src, D3D12_RESOURCE_STATES& src_state, DXGI_FORMAT src_srv_format, uint32_t src_samples,
            bool fragment0, int32_t sx, int32_t sy, ID3D12Resource* dst, D3D12_RESOURCE_STATES& dst_state,
            DXGI_FORMAT dst_format, int32_t dx, int32_t dy, uint32_t w, uint32_t h, float scale,
            bool swap_red_blue = false) {
    ID3D12PipelineState* pso = BlitPipeline(dst_format);
    if (!pso || !w || !h) return;
    Transition(src, src_state, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
    Transition(dst, dst_state, D3D12_RESOURCE_STATE_RENDER_TARGET);
    uint32_t table = view_next;
    view_next += 2;
    D3D12_SHADER_RESOURCE_VIEW_DESC sd{};
    sd.Format = src_srv_format;
    sd.Shader4ComponentMapping = swap_red_blue ? D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING(2, 1, 0, 3)
                                               : D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    sd.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
    sd.Texture2D.MipLevels = 1;
    device->CreateShaderResourceView(src_samples > 1 ? nullptr : src, &sd, ViewCpu(table));
    sd.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2DMS;
    device->CreateShaderResourceView(src_samples > 1 ? src : nullptr, &sd, ViewCpu(table + 1));
    // Temporary RTV for the destination.
    D3D12_CPU_DESCRIPTOR_HANDLE rtv = rtv_heap->GetCPUDescriptorHandleForHeapStart();
    rtv.ptr += size_t(4095) * rtv_inc;  // scratch slot
    D3D12_RENDER_TARGET_VIEW_DESC rd{};
    rd.Format = dst_format;
    rd.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
    device->CreateRenderTargetView(dst, &rd, rtv);
    list->OMSetRenderTargets(1, &rtv, FALSE, nullptr);
    list->SetPipelineState(pso);
    list->SetGraphicsRootSignature(blit_root.Get());
    uint32_t consts[8] = {uint32_t(sx), uint32_t(sy), uint32_t(dx), uint32_t(dy), 0,
                          src_samples > 1 ? (fragment0 ? 1u : 2u) : 0u, 0, 0};
    std::memcpy(&consts[4], &scale, 4);
    list->SetGraphicsRoot32BitConstants(0, 8, consts, 0);
    list->SetGraphicsRootDescriptorTable(1, ViewGpu(table));
    D3D12_VIEWPORT vp{float(dx), float(dy), float(w), float(h), 0, 1};
    D3D12_RECT sc{dx, dy, LONG(dx + w), LONG(dy + h)};
    list->RSSetViewports(1, &vp);
    list->RSSetScissorRects(1, &sc);
    list->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    list->DrawInstanced(3, 1, 0, 0);
    state.valid = false;
  }
};

// =================================================================================================

Renderer::Renderer() : impl_(std::make_unique<Impl>()) { impl_->stats = &stats_; }
Renderer::~Renderer() {
  if (impl_->fence_event) CloseHandle(impl_->fence_event);
}

bool Renderer::Initialize(ID3D12Device* device, ID3D12CommandQueue* queue) {
  Impl& m = *impl_;
  m.device = device;
  m.queue = queue;
  if (FAILED(device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m.allocator))) ||
      FAILED(device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m.allocator.Get(), nullptr,
                                       IID_PPV_ARGS(&m.list))) ||
      FAILED(device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m.fence)))) {
    return false;
  }
  m.list->Close();
  for (auto& sl : m.slots)
    if (FAILED(device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&sl.allocator))))
      return false;
  m.fence_event = CreateEvent(nullptr, FALSE, FALSE, nullptr);

  D3D12_HEAP_PROPERTIES def{D3D12_HEAP_TYPE_DEFAULT}, up{D3D12_HEAP_TYPE_UPLOAD};
  D3D12_RESOURCE_DESC bd{};
  bd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
  bd.Width = Impl::kSharedSize;
  bd.Height = 1;
  bd.DepthOrArraySize = 1;
  bd.MipLevels = 1;
  bd.SampleDesc.Count = 1;
  bd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
  bd.Flags = D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS;
  if (FAILED(device->CreateCommittedResource(&def, D3D12_HEAP_FLAG_NONE, &bd, D3D12_RESOURCE_STATE_COPY_DEST, nullptr,
                                             IID_PPV_ARGS(&m.shared))))
    return false;
  bd.Width = Impl::kUploadSize;
  bd.Flags = D3D12_RESOURCE_FLAG_NONE;
  if (FAILED(device->CreateCommittedResource(&up, D3D12_HEAP_FLAG_NONE, &bd, D3D12_RESOURCE_STATE_GENERIC_READ,
                                             nullptr, IID_PPV_ARGS(&m.upload))))
    return false;
  D3D12_RANGE none{0, 0};
  m.upload->Map(0, &none, reinterpret_cast<void**>(&m.upload_cpu));

  auto heap = [&](D3D12_DESCRIPTOR_HEAP_TYPE type, uint32_t n, bool visible, ComPtr<ID3D12DescriptorHeap>& out) {
    D3D12_DESCRIPTOR_HEAP_DESC d{type, n,
                                 visible ? D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE : D3D12_DESCRIPTOR_HEAP_FLAG_NONE, 0};
    return SUCCEEDED(device->CreateDescriptorHeap(&d, IID_PPV_ARGS(&out)));
  };
  if (!heap(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, Impl::kViewHeapSize, true, m.view_heap) ||
      !heap(D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER, Impl::kSamplerHeapSize, true, m.sampler_heap) ||
      !heap(D3D12_DESCRIPTOR_HEAP_TYPE_RTV, Impl::kRtvHeapSize, false, m.rtv_heap) ||
      !heap(D3D12_DESCRIPTOR_HEAP_TYPE_DSV, Impl::kDsvHeapSize, false, m.dsv_heap))
    return false;
  m.view_inc = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
  m.sampler_inc = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER);
  m.rtv_inc = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
  m.dsv_inc = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
  m.view_next = m.ViewSlotBegin();

  // Shared memory views at [0] (raw SRV) and [1] (raw UAV).
  D3D12_SHADER_RESOURCE_VIEW_DESC sd{};
  sd.Format = DXGI_FORMAT_R32_TYPELESS;
  sd.ViewDimension = D3D12_SRV_DIMENSION_BUFFER;
  sd.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
  sd.Buffer.NumElements = UINT(Impl::kSharedSize / 4);
  sd.Buffer.Flags = D3D12_BUFFER_SRV_FLAG_RAW;
  device->CreateShaderResourceView(m.shared.Get(), &sd, m.ViewCpu(0));
  D3D12_UNORDERED_ACCESS_VIEW_DESC ud{};
  ud.Format = DXGI_FORMAT_R32_TYPELESS;
  ud.ViewDimension = D3D12_UAV_DIMENSION_BUFFER;
  ud.Buffer.NumElements = UINT(Impl::kSharedSize / 4);
  ud.Buffer.Flags = D3D12_BUFFER_UAV_FLAG_RAW;
  device->CreateUnorderedAccessView(m.shared.Get(), nullptr, &ud, m.ViewCpu(1));

  m.translator = std::make_unique<DxbcShaderTranslator>(rex::ui::GraphicsProvider::GpuVendorID::kNvidia,
                                                        /*bindless_resources_used=*/false, /*edram_rov_used=*/false);
  return m.InitBlit();
}

void Renderer::UploadPhysical(uint32_t addr, const uint8_t* data, uint32_t size) {
  Impl& m = *impl_;
  if (!size || uint64_t(addr) + size > Impl::kSharedSize) return;
  m.EnsureRecording();
  stats_.upload_bytes += size;
  while (size) {
    uint32_t chunk = std::min<uint32_t>(size, 64u << 20);
    uint64_t off;
    ID3D12Resource* src = nullptr;
    if (!m.Upload(data, chunk, 16, nullptr, &off, &src)) return;
    m.Transition(m.shared.Get(), m.shared_state, D3D12_RESOURCE_STATE_COPY_DEST);
    m.list->CopyBufferRegion(m.shared.Get(), addr, src, off, chunk);
    addr += chunk;
    data += chunk;
    size -= chunk;
  }
}

void Renderer::BeginFrame() { impl_->EnsureRecording(); }

void Renderer::InitConstants(const uint8_t* device_be) {
  Impl& m = *impl_;
  for (uint32_t r = 0; r < Impl::kConstCount; ++r) {
    uint32_t reg = Impl::kConstBase + r;
    uint32_t off = reg < 0x4400 ? dev::kVsFloatConstants + (reg - 0x4000) * 4
                 : reg < 0x4800 ? dev::kPsFloatConstants + (reg - 0x4400) * 4
                 : reg < 0x4900 ? dev::kFetchConstants + (reg - 0x4800) * 4
                                : dev::kBoolLoopConstants + (reg - 0x4900) * 4;
    m.constants[r] = BE32(device_be + off);
  }
  m.constants_initialized = true;
}

void Renderer::WriteConstants(uint32_t reg, const uint32_t* values, uint32_t count) {
  Impl& m = *impl_;
  for (uint32_t i = 0; i < count; ++i) {
    uint32_t r = reg + i;
    if (r >= Impl::kConstBase && r < Impl::kConstBase + Impl::kConstCount) m.constants[r - Impl::kConstBase] = values[i];
  }
}

void Renderer::LoadShaderConstantsF4(const GuestMemory& mem, uint32_t bank, uint32_t start, uint32_t count,
                                     uint32_t buffer, uint32_t offset) {
  uint32_t src = GuestMemory::VirtualToPhysical(mem.Load32(buffer + 24) + offset * 16);
  const uint8_t* p = mem.Physical(src, count * 16);
  if (!p) return;
  uint32_t reg = 0x4000 + ((bank << 8) + start) * 4;
  std::vector<uint32_t> v(count * 4);
  for (uint32_t i = 0; i < count * 4; ++i) v[i] = BE32(p + i * 4);
  WriteConstants(reg, v.data(), count * 4);
}

// sub_82221CB0: a shader's literal constants. Float constants are loaded from the shader data;
// bool/loop constants are patched into a 160-byte block (inline copies, then and/or masks) that
// GpuLoadShaders then writes to the bool/loop registers.
static void ApplyShaderLiterals(const GuestMemory& mem, uint32_t list_base, uint32_t data_base, uint32_t binding,
                                Renderer& r, uint8_t* flow /* 160 bytes, big-endian */) {
  uint32_t off = mem.Load32(list_base + binding * 8 + 20);
  if (!off) return;
  uint32_t hdr = list_base + off;
  uint32_t p = hdr + 20, end = p + mem.Load32(hdr + 16);
  auto u16 = [&](uint32_t a) {
    const uint8_t* q = mem.Virtual(a, 2);
    return q ? uint32_t((q[0] << 8) | q[1]) : 0u;
  };
  // Pass 1: float constants.
  while (p < end) {
    uint32_t dst = u16(p), count = u16(p + 2);
    p += 4;
    if (!count) break;
    uint32_t src = GuestMemory::VirtualToPhysical(data_base + mem.Load32(p));
    p += 4;
    if (const uint8_t* s = mem.Physical(src, count * 4)) {
      std::vector<uint32_t> v(count);
      for (uint32_t i = 0; i < count; ++i) v[i] = BE32(s + i * 4);
      r.WriteConstants(0x4000 + dst * 4, v.data(), count);
    }
  }
  if (!flow) return;
  // Pass 2: inline copies into the flow block.
  while (p < end) {
    uint32_t dst = u16(p), count = u16(p + 2);
    p += 4;
    if (!count) break;
    uint32_t bytes = count * 4;
    const uint8_t* s = mem.Virtual(p, bytes);
    if (s && dst >= 8960 && dst - 8960 + bytes <= 160) std::memcpy(flow + (dst - 8960), s, bytes);
    p += bytes;
  }
  // Pass 3: and/or masks.
  while (p < end) {
    uint32_t dst = u16(p), count = u16(p + 2);
    p += 4;
    if (!count) break;
    for (uint32_t k = 0; k < count && p + 8 <= end; k += 2, p += 8) {
      uint32_t o = dst - 8960 + (k / 2) * 4;
      if (dst < 8960 || o + 4 > 160) continue;
      uint32_t v = BE32(flow + o);
      v = (v & mem.Load32(p)) | mem.Load32(p + 4);
      flow[o] = uint8_t(v >> 24), flow[o + 1] = uint8_t(v >> 16), flow[o + 2] = uint8_t(v >> 8), flow[o + 3] = uint8_t(v);
    }
  }
}

void Renderer::LoadShaders(const GuestMemory& mem, uint32_t vs, uint32_t ps, uint32_t flow_constants) {
  LoadShadersWithFlow(mem, vs, ps, flow_constants ? mem.Virtual(flow_constants, 160) : nullptr);
}

void Renderer::LoadShadersWithFlow(const GuestMemory& mem, uint32_t vs, uint32_t ps, const uint8_t* flow_in) {
  Impl& m = *impl_;
  uint8_t flow[160];
  bool have_flow = false;
  if (flow_in) {
    std::memcpy(flow, flow_in, 160);
    have_flow = true;
  }
  // GpuLoadShaders only writes the bool/loop block when a shader declares flow constants
  // (VS binding record +888 | PS header +56).
  uint32_t flow_flags = 0;
  if (vs) {
    uint32_t binding = ps ? 0 : ((mem.Load32(vs + 872) >> 4) & 1);
    uint32_t rec = vs + mem.Load32(vs + (binding + 112) * 8);
    flow_flags |= mem.Load32(rec + 888);
    ApplyShaderLiterals(mem, vs + 872, mem.Load32(vs + 32), binding, *this, have_flow ? flow : nullptr);
  }
  if (ps) {
    flow_flags |= mem.Load32(ps + mem.Load32(ps + 64) + 56);
    ApplyShaderLiterals(mem, ps + 40, mem.Load32(ps + 24), 0, *this, have_flow ? flow : nullptr);
  }
  if (have_flow && flow_flags) {
    uint32_t v[40];
    for (uint32_t i = 0; i < 40; ++i) v[i] = BE32(flow + i * 4);
    WriteConstants(0x4900, v, 40);
  }
  (void)m;
}

void Renderer::WriteFetchConstant(uint32_t reg, uint32_t value, uint32_t shadow) {
  Impl& m = *impl_;
  if (reg < 0x4800 || reg >= 0x48C0) return;
  uint32_t k = reg - 0x4800;
  m.fetch_overlay[k] = {value, shadow};
  if (!m.fetch_overlay_active[k]) {
    m.fetch_overlay_active[k] = true;
    m.fetch_overlay_list.push_back(uint8_t(k));
  }
}

void Renderer::WriteFetchConstants(uint32_t reg, const uint32_t* values, uint32_t count, const uint8_t* device_be) {
  Impl& m = *impl_;
  for (uint32_t i = 0; i < count; ++i) {
    uint32_t r = reg + i;
    if (r < 0x4800 || r >= 0x48C0) continue;
    uint32_t k = r - 0x4800;
    m.fetch_overlay[k] = {values[i], BE32(device_be + dev::kFetchConstants + k * 4)};
    if (!m.fetch_overlay_active[k]) {
      m.fetch_overlay_active[k] = true;
      m.fetch_overlay_list.push_back(uint8_t(k));
    }
  }
}

void Renderer::SetPipelineCache(const std::string& path) {
  Impl& m = *impl_;
  m.pipeline_cache_path = path;
  if (path.empty()) return;
  m.StartCompileThreads();
  std::thread([&m] { m.LoadDiskCache(); }).detach();
}

void Renderer::EndFrame() {
  Impl& m = *impl_;
  m.pipeline_wait_left_us = int64_t(pipeline_wait_ms * 1000);
  stats_.pipelines_created = uint32_t(m.pipelines_created_async.load());
  stats_.pipelines_failed = uint32_t(m.pipelines_failed_async.load());
  stats_.pipeline_us = m.pipeline_us_async.load();
  FlushDeferred();
  m.Submit(false);
  ++m.frame_index;
  m.ResetItems();
  m.pass_has_plain_draw = false;
  m.pass_prev_depth_base = 0;
}

Renderer::PassItem& Renderer::RecordItem(int kind, const uint8_t* device_be) {
  Impl& m = *impl_;
  if (m.items_used == m.items.size()) m.items.emplace_back();
  PassItem& it = m.items[m.items_used++];
  it.kind = kind;
  it.seq = debug_seq;
  it.device.resize(dev::kSize);
  // The renderer reads the header (dirty masks, fetch constants) and the register/object fields; the
  // float constants come from its own constant file (kept per draw below).
  std::memcpy(it.device.data(), device_be, 48);
  std::memcpy(it.device.data() + dev::kFetchConstants, device_be + dev::kFetchConstants,
              dev::kVsFloatConstants - dev::kFetchConstants);
  std::memcpy(it.device.data() + dev::kBoolLoopConstants, device_be + dev::kBoolLoopConstants,
              dev::kVertexShader + 8 - dev::kBoolLoopConstants);
  return it;
}

void Renderer::RecordDraw(const GuestMemory& mem, const uint8_t* device_be, const ShaderState& shaders,
                          const DrawArgs& args) {
  Impl& m = *impl_;
  PassItem& it = RecordItem(0, device_be);
  if (it.packet) static_cast<Impl::DrawPacket*>(it.packet.get())->valid = false;
  it.shaders = shaders;
  it.args = args;
  it.vs_code.clear();
  it.ps_code.clear();
  it.up_vertex.clear();
  it.up_index.clear();
  // (Interned microcode - a hash given - outlives the pass: keep the pointer.)
  if (args.vs_ucode && !args.vs_hash) it.vs_code.assign(args.vs_ucode, args.vs_ucode + args.vs_ucode_dwords);
  if (args.ps_ucode && !args.ps_hash) it.ps_code.assign(args.ps_ucode, args.ps_ucode + args.ps_ucode_dwords);
  // Vertices / indices in the command buffer (the buffer is reused once the GPU is past it).
  if (args.up_vertex_fetch && args.up_vertex_bytes) {
    const uint8_t* p = args.up_vertex_data ? args.up_vertex_data : mem.Physical(args.up_vertex_physical, args.up_vertex_bytes);
    if (p) it.up_vertex.assign(p, p + args.up_vertex_bytes);
  }
  if (args.up_vertex_fetch && args.kind == DrawArgs::kIndexed && args.index_physical) {
    uint32_t isz = args.index_32bit ? 4 : 2;
    it.up_index_physical = args.index_physical + args.start * isz;
    const uint8_t* p = args.up_index_data ? args.up_index_data : mem.Physical(it.up_index_physical, args.count * isz);
    if (p) it.up_index.assign(p, p + args.count * isz);
  }
  it.args.up_vertex_data = it.args.up_index_data = nullptr;
  it.const_delta.clear();
  if (!m.items_const_valid) {
    std::memcpy(m.items_const_base, m.constants, sizeof(m.constants));
    std::memcpy(m.items_const_last, m.constants, sizeof(m.constants));
    m.items_const_valid = true;
  } else {
    for (uint32_t b = 0; b * 16 < Impl::kConstCount; ++b) {
      uint32_t first = b * 16, n = std::min<uint32_t>(16, Impl::kConstCount - first);
      if (std::memcmp(&m.items_const_last[first], &m.constants[first], n * 4) == 0) continue;
      std::memcpy(&m.items_const_last[first], &m.constants[first], n * 4);
      it.const_delta.push_back(b);
      it.const_delta.insert(it.const_delta.end(), &m.constants[first], &m.constants[first] + n);
    }
  }
  it.overlay_list = m.fetch_overlay_list;
  it.overlay.clear();
  for (uint8_t k : m.fetch_overlay_list) it.overlay.push_back({m.fetch_overlay[k].value, m.fetch_overlay[k].shadow});
}

void Renderer::BeginConstReplay() {
  Impl& m = *impl_;
  if (m.items_const_valid) std::memcpy(m.constants, m.items_const_base, sizeof(m.constants));
}

void Renderer::ApplyConstDelta(const PassItem& it) {
  Impl& m = *impl_;
  for (size_t i = 0; i < it.const_delta.size();) {
    uint32_t first = it.const_delta[i] * 16, n = std::min<uint32_t>(16, Impl::kConstCount - first);
    std::memcpy(&m.constants[first], &it.const_delta[i + 1], n * 4);
    i += 1 + n;
  }
}

void Renderer::RunItem(const GuestMemory& mem, PassItem& it) {
  Impl& m = *impl_;
  uint32_t seq = debug_seq;
  debug_seq = it.seq;
  switch (it.kind) {
    case 0: {
      // (m.constants: RunDeferred applied this draw's constant delta.)
      for (uint8_t k : m.fetch_overlay_list) m.fetch_overlay_active[k] = false;
      m.fetch_overlay_list = it.overlay_list;
      for (size_t i = 0; i < it.overlay_list.size(); ++i) {
        uint8_t k = it.overlay_list[i];
        m.fetch_overlay[k] = {it.overlay[i].first, it.overlay[i].second};
        m.fetch_overlay_active[k] = true;
      }
      DrawArgs a = it.args;  // (interned microcode pointers are kept; copied microcode is used instead)
      if (!it.vs_code.empty()) a.vs_ucode = it.vs_code.data();
      else if (!a.vs_hash) a.vs_ucode = nullptr;
      if (!it.ps_code.empty()) a.ps_ucode = it.ps_code.data();
      else if (!a.ps_hash) a.ps_ucode = nullptr;
      if (!it.up_vertex.empty()) UploadPhysical(a.up_vertex_physical, it.up_vertex.data(), uint32_t(it.up_vertex.size()));
      if (!it.up_index.empty()) UploadPhysical(it.up_index_physical, it.up_index.data(), uint32_t(it.up_index.size()));
      DrawInternal(mem, it.device.data(), it.shaders, a);
      break;
    }
    case 1:
      ClearInternal(mem, it.device.data(), it.clear);
      break;
    case 2:
      ResolveInternal(mem, it.device.data(), it.resolve);
      break;
  }
  debug_seq = seq;
}

bool Renderer::ReplayPacket(PassItem& it) {
  Impl& m = *impl_;
  auto& pk = *static_cast<Impl::DrawPacket*>(it.packet.get());
  if (!pk.valid || pk.submit_epoch != m.submit_epoch || pk.sampler_epoch != m.sampler_epoch || !m.recording)
    return false;
  for (auto& [tp, res] : pk.textures)
    if (static_cast<Impl::Texture*>(tp)->resource.Get() != res) return false;
  // The real render targets (the pre-pass drew into private ones of the same shape).
  Impl::RenderTarget* rts[4] = {};
  for (uint32_t i = 0; i < pk.rt_count; ++i) {
    if (!pk.rt_key[i]) continue;
    auto f = m.render_targets.find(pk.rt_key[i]);
    if (f == m.render_targets.end() || !f->second.resource || f->second.format != pk.rt_format[i] ||
        f->second.samples != pk.samples || f->second.width < pk.width || f->second.height < pk.height)
      return false;
    rts[i] = &f->second;
  }
  Impl::RenderTarget* ds = nullptr;
  if (pk.has_ds) {
    auto f = m.render_targets.find(pk.ds_key);
    if (f == m.render_targets.end() || !f->second.resource || f->second.format != pk.ds_format ||
        f->second.samples != pk.samples || f->second.width < pk.width || f->second.height < pk.height)
      return false;
    ds = &f->second;
  }
  if (!it.up_vertex.empty())
    UploadPhysical(it.args.up_vertex_physical, it.up_vertex.data(), uint32_t(it.up_vertex.size()));
  if (!it.up_index.empty()) UploadPhysical(it.up_index_physical, it.up_index.data(), uint32_t(it.up_index.size()));
  if (!m.recording) return false;  // (an upload submitted the list: the recorded data is gone)
  for (auto& [tp, res] : pk.textures) {
    auto* t = static_cast<Impl::Texture*>(tp);
    m.Transition(t->resource.Get(), t->state, D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE);
  }
  Impl::DrawPacket real = pk;
  real.textures.clear();
  for (uint32_t i = 0; i < pk.rt_count; ++i) {
    if (!rts[i]) continue;
    m.Transition(rts[i]->resource.Get(), rts[i]->state, D3D12_RESOURCE_STATE_RENDER_TARGET);
    real.rtvs[i] = rts[i]->view;
  }
  if (ds) {
    m.Transition(ds->resource.Get(), ds->state, D3D12_RESOURCE_STATE_DEPTH_WRITE);
    real.dsv = ds->view;
  }
  m.EmitDraw(real, false, state_cache);
  ++stats_.draws;
  ++packets_replayed;
  return true;
}

void Renderer::RunDeferred(const uint8_t* resolve_device, const ResolveArgs* depth_resolve) {
  Impl& m = *impl_;
  if (!m.deferring) return;
  m.deferring = false;
  const GuestMemory& mem = *m.defer_mem;
  // The constant file / overlays as the game left them after the last recorded call.
  std::vector<uint32_t> saved_constants(m.constants, m.constants + Impl::kConstCount);
  std::vector<uint8_t> saved_overlay_list = m.fetch_overlay_list;
  std::vector<Impl::FetchOverlay> saved_overlay(m.fetch_overlay, m.fetch_overlay + 192);
  bool saved_active[192];
  std::memcpy(saved_active, m.fetch_overlay_active, sizeof(saved_active));
  m.replaying = true;
  if (depth_resolve) {
    // Depth pre-pass: the recorded draws into the scene depth buffer, drawn into a private copy of it
    // (the recorded calls have not touched the real one yet, so it holds the state they start from).
    uint32_t ds_surface = BE32(resolve_device + dev::kDepthStencil);
    auto rit = ds_surface ? m.render_targets.find(Impl::RtKey(mem, ds_surface, true)) : m.render_targets.end();
    if (rit != m.render_targets.end() && rit->second.resource) {
      Impl::RenderTarget& real = rit->second;
      Impl::rt_private = true;
      Impl::RenderTarget* priv =
          m.GetRenderTarget(Impl::RtKey(mem, ds_surface, true), real.format, true, real.width, real.height, real.samples);
      if (priv && priv->resource && priv->width == real.width && priv->height == real.height) {
        m.Transition(real.resource.Get(), real.state, D3D12_RESOURCE_STATE_COPY_SOURCE);
        m.Transition(priv->resource.Get(), priv->state, D3D12_RESOURCE_STATE_COPY_DEST);
        m.list->CopyResource(priv->resource.Get(), real.resource.Get());
        m.state.valid = false;
        BeginConstReplay();
        for (size_t i = 0; i < m.items_used; ++i) {
          PassItem& it = m.items[i];
          if (it.kind == 0) ApplyConstDelta(it);
          if (it.kind == 2 || BE32(it.device.data() + dev::kDepthStencil) != ds_surface) continue;
          if (it.kind == 0) {
            ++prepass_draws;
            if (!it.packet) it.packet = std::make_shared<Impl::DrawPacket>();
            m.capture_packet = static_cast<Impl::DrawPacket*>(it.packet.get());
            m.capture_packet->valid = false;
          }
          RunItem(mem, it);
          if (m.capture_packet) m.capture_packet->valid &= m.capture_packet->pso != nullptr;
          m.capture_packet = nullptr;
        }
        ResolveArgs pre = *depth_resolve;
        pre.flags &= ~0x300u;  // no clears
        ResolveInternal(mem, resolve_device, pre);
        ++passes_rerun;
      }
      Impl::rt_private = false;
      m.state.valid = false;
    }
  }
  uint64_t reused = packets_replayed;
  BeginConstReplay();
  for (size_t i = 0; i < m.items_used; ++i) {
    PassItem& it = m.items[i];
    if (it.kind == 0) ApplyConstDelta(it);
    if (it.kind == 0 && it.packet && ReplayPacket(it)) continue;
    RunItem(mem, it);
  }
  if (debug_trace)
    std::fprintf(TraceOut(), "[seq %u] deferred calls: %llu of %zu issued again from the pre-pass\n", debug_seq,
                 (unsigned long long)(packets_replayed - reused), m.items_used);
  m.replaying = false;
  m.ResetItems();
  std::memcpy(m.constants, saved_constants.data(), Impl::kConstCount * 4);
  m.fetch_overlay_list = saved_overlay_list;
  std::copy(saved_overlay.begin(), saved_overlay.end(), m.fetch_overlay);
  std::memcpy(m.fetch_overlay_active, saved_active, sizeof(saved_active));
}

void Renderer::Draw(const GuestMemory& mem, const uint8_t* device_be, const ShaderState& shaders, const DrawArgs& args) {
  Impl& m = *impl_;
  if (m.deferring) {
    UpdateDrawConstants(mem, device_be);
    RecordDraw(mem, device_be, shaders, args);
    if (m.items_used > 20000) FlushDeferred();  // (something other than the expected frame layout)
    return;
  }
  m.last_draw_prev_depth = 0;
  DrawInternal(mem, device_be, shaders, args);
  if (!realtime_depth_passes) return;
  if (!m.last_draw_prev_depth && !m.pass_prev_depth_base) {
    m.pass_has_plain_draw = true;
    return;
  }
  if (m.pass_has_plain_draw) return;  // a pass that also draws other things is left as it is
  if (m.last_draw_prev_depth) m.pass_prev_depth_base = m.last_draw_prev_depth;
  RecordDraw(mem, device_be, shaders, args);
}

void Renderer::Clear(const GuestMemory& mem, const uint8_t* device_be, const ClearArgs& args) {
  Impl& m = *impl_;
  if (!m.deferring) ClearInternal(mem, device_be, args);
  if (!realtime_depth_passes || (!m.deferring && m.pass_has_plain_draw)) return;
  RecordItem(1, device_be).clear = args;
}

void Renderer::Resolve(const GuestMemory& mem, const uint8_t* device_be, const ResolveArgs& args) {
  Impl& m = *impl_;
  uint32_t base = 0;
  if (args.dest_texture)
    if (const uint8_t* f = mem.Virtual(args.dest_texture + 28, 24)) {
      base = (BE32(f + 4) >> 12) << 12;
      if (base >= 0xA0000000) base = GuestMemory::VirtualToPhysical(base);
    }
  if (m.deferring) {
    if ((args.flags & 7) == 4 && base == m.defer_depth) {
      if (debug_trace)
        std::fprintf(TraceOut(), "[seq %u] depth %08X resolved: depth pre-pass and %zu deferred calls\n", debug_seq,
                     base, m.items_used);
      RunDeferred(device_be, &args);
      ResolveInternal(mem, device_be, args);
    } else {
      RecordItem(2, device_be).resolve = args;
    }
    return;
  }
  ResolveInternal(mem, device_be, args);
  if (!realtime_depth_passes) return;
  if (m.pass_prev_depth_base && !m.pass_has_plain_draw) {
    // A pass that read an earlier frame's depth (the shadow mask): defer the frame from here (the pass
    // included) until that depth is resolved again.
    RecordItem(2, device_be).resolve = args;
    m.deferring = true;
    m.defer_depth = m.pass_prev_depth_base;
    m.defer_mem = &mem;
    if (debug_trace)
      std::fprintf(TraceOut(), "[seq %u] pass read earlier-frame depth %08X: deferring until it is resolved\n",
                   debug_seq, m.defer_depth);
  } else {
    m.ResetItems();
  }
  m.pass_has_plain_draw = false;
  m.pass_prev_depth_base = 0;
}

void Renderer::PushFrameHistory(uint32_t base_address, uint32_t frame) {
  FlushDeferred();
  Impl& m = *impl_;
  auto it = m.resolved.find(base_address);
  if (it == m.resolved.end() || !it->second.resource) return;
  Impl::Texture& src = it->second;
  auto& h = m.history[m.history_next];
  if (!h.tex.resource || h.tex.width != src.width || h.tex.height != src.height || h.tex.format != src.format) {
    if (h.tex.resource) m.retired.push_back(h.tex.resource);
    h.tex = Impl::Texture{};
    D3D12_RESOURCE_DESC rd = src.resource->GetDesc();
    rd.Flags = D3D12_RESOURCE_FLAG_NONE;
    D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_DEFAULT};
    if (FAILED(m.device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &rd, D3D12_RESOURCE_STATE_COPY_DEST, nullptr,
                                                 IID_PPV_ARGS(&h.tex.resource))))
      return;
    h.tex.format = src.format;
    h.tex.width = src.width;
    h.tex.height = src.height;
    h.tex.state = D3D12_RESOURCE_STATE_COPY_DEST;
  }
  m.EnsureRecording();
  m.Transition(src.resource.Get(), src.state, D3D12_RESOURCE_STATE_COPY_SOURCE);
  m.Transition(h.tex.resource.Get(), h.tex.state, D3D12_RESOURCE_STATE_COPY_DEST);
  m.list->CopyResource(h.tex.resource.Get(), src.resource.Get());
  h.tex.red_blue_swapped = src.red_blue_swapped;
  h.frame = frame;
  h.valid = true;
  m.history_next = (m.history_next + 1) % kHistoryFrames;
}

uint32_t Renderer::BeginOcclusionQuery() {
  Impl& m = *impl_;
  FlushDeferred();
  if (!m.query_heap) {
    D3D12_QUERY_HEAP_DESC qd{D3D12_QUERY_HEAP_TYPE_OCCLUSION, Impl::kQueries, 0};
    if (FAILED(m.device->CreateQueryHeap(&qd, IID_PPV_ARGS(&m.query_heap)))) return UINT32_MAX;
    D3D12_RESOURCE_DESC bd{};
    bd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    bd.Width = Impl::kQueries * 8;
    bd.Height = 1;
    bd.DepthOrArraySize = 1;
    bd.MipLevels = 1;
    bd.SampleDesc.Count = 1;
    bd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_READBACK};
    void* map = nullptr;
    D3D12_RANGE range{0, Impl::kQueries * 8};
    if (FAILED(m.device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &bd, D3D12_RESOURCE_STATE_COPY_DEST, nullptr,
                                                 IID_PPV_ARGS(&m.query_readback))) ||
        FAILED(m.query_readback->Map(0, &range, &map))) {
      m.query_heap.Reset();
      m.query_readback.Reset();
      return UINT32_MAX;
    }
    m.query_map = static_cast<const uint64_t*>(map);
  }
  m.EnsureRecording();
  m.EndActiveQuery();
  uint32_t i = m.query_next++ % Impl::kQueries;
  m.query_fence[i] = UINT64_MAX;  // pending
  m.list->BeginQuery(m.query_heap.Get(), D3D12_QUERY_TYPE_OCCLUSION, i);
  m.active_query = int32_t(i);
  return i;
}

uint64_t Renderer::EndOcclusionQuery(uint32_t index) {
  Impl& m = *impl_;
  FlushDeferred();
  if (index >= Impl::kQueries || !m.query_heap) return 0;
  if (m.active_query == int32_t(index)) {
    m.EndActiveQuery();
    m.Flush();  // make the result reachable without waiting for the end of the frame
  }
  uint64_t f = m.query_fence[index];
  return f == UINT64_MAX ? 0 : f;
}

bool Renderer::OcclusionQueryResult(uint32_t index, uint64_t fence, uint64_t* samples) const {
  const Impl& m = *impl_;
  if (!m.query_map || index >= Impl::kQueries || m.fence->GetCompletedValue() < fence) return false;
  *samples = m.query_map[index];
  return true;
}

void Renderer::WaitFence(uint64_t fence, void* event_handle) const {
  const Impl& m = *impl_;
  if (m.fence->GetCompletedValue() >= fence) return;
  m.fence->SetEventOnCompletion(fence, static_cast<HANDLE>(event_handle));
  WaitForSingleObject(static_cast<HANDLE>(event_handle), INFINITE);
}

void Renderer::DropTextureCache() {
  Impl& m = *impl_;
  FlushDeferred();
  for (auto& [k, t] : m.textures)
    if (t.resource) m.retired.push_back(t.resource);
  m.textures.clear();
  ++m.texture_epoch;
  m.srv_tables.clear();
  m.fast_tables.clear();
  m.state.valid = false;
}

std::vector<Renderer::HistoryFrame> Renderer::FrameHistory() const {
  const Impl& m = *impl_;
  std::vector<HistoryFrame> out;
  for (uint32_t i = 0; i < kHistoryFrames; ++i) {
    const auto& h = m.history[(m.history_next + i) % kHistoryFrames];
    if (h.valid) out.push_back({h.frame, h.tex.resource.Get(), h.tex.red_blue_swapped});
  }
  return out;
}

bool Renderer::IsResolvedRedBlueSwapped(uint32_t base_address) const {
  auto it = impl_->resolved.find(base_address);
  return it != impl_->resolved.end() && it->second.red_blue_swapped;
}

ID3D12Resource* Renderer::GetResolvedTexture(uint32_t base_address) const {
  auto it = impl_->resolved.find(base_address);
  return it == impl_->resolved.end() ? nullptr : it->second.resource.Get();
}

std::vector<std::pair<uint32_t, ID3D12Resource*>> Renderer::ResolvedTextures() const {
  std::vector<std::pair<uint32_t, ID3D12Resource*>> out;
  for (auto& [k, t] : impl_->resolved) out.push_back({k, t.resource.Get()});
  return out;
}

std::vector<std::pair<uint32_t, ID3D12Resource*>> Renderer::RenderTargets() const {
  std::vector<std::pair<uint32_t, ID3D12Resource*>> out;
  for (auto& [k, rt] : impl_->render_targets) out.push_back({k, rt.resource.Get()});
  return out;
}

// -------------------------------------------------------------------------------------------------

// Per-section CPU time of Draw (QueryPerformanceCounter ticks), for the perf log.
namespace {
const char* const kDrawSectionNames[13] = {"setup",     "shadercode", "livememory",    "constants",
                                           "primitive", "rendertargets", "pipeline", "floatconst",
                                           "sysconst",  "textures",   "record",        "overlay+shaderregs", "samplers"};
uint64_t g_draw_section_ticks[13] = {};
bool g_draw_profile_enabled = false;
struct DrawProfiler {
  int cur = 0;
  LARGE_INTEGER last;
  DrawProfiler() {
    if (g_draw_profile_enabled) QueryPerformanceCounter(&last);
  }
  void Mark(int next) {
    if (!g_draw_profile_enabled) return;
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    g_draw_section_ticks[cur] += uint64_t(now.QuadPart - last.QuadPart);
    last = now;
    cur = next;
  }
  ~DrawProfiler() { Mark(0); }
};
}  // namespace

void Renderer::EnableDrawProfile(bool enable) { g_draw_profile_enabled = enable; }

std::string Renderer::DrawProfile(bool reset) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  std::string out;
  for (int i = 0; i < 13; ++i) {
    char buf[64];
    std::snprintf(buf, sizeof(buf), "%s%s %.2f", i ? ", " : "", kDrawSectionNames[i],
                  double(g_draw_section_ticks[i]) * 1000.0 / double(freq.QuadPart));
    out += buf;
    if (reset) g_draw_section_ticks[i] = 0;
  }
  return out;
}

void Renderer::UpdateDrawConstants(const GuestMemory& mem, const uint8_t* device_be) {
  Impl& m = *impl_;
  // Directly written fetch constants stay while the device's shadow copy is unchanged since.
  {
    size_t keep = 0;
    for (size_t i = 0; i < m.fetch_overlay_list.size(); ++i) {
      uint32_t k = m.fetch_overlay_list[i];
      if (BE32(device_be + dev::kFetchConstants + k * 4) != m.fetch_overlay[k].shadow) {
        m.fetch_overlay_active[k] = false;
        continue;
      }
      m.fetch_overlay_list[keep++] = uint8_t(k);
    }
    m.fetch_overlay_list.resize(keep);
  }
  uint32_t dev_vs = BE32(device_be + dev::kVertexShader), dev_ps = BE32(device_be + dev::kPixelShader);
  {
    auto be64 = [&](uint32_t off) { return (uint64_t(BE32(device_be + off)) << 32) | BE32(device_be + off + 4); };
    auto shadow = [&](uint32_t reg) { return BE32(device_be + (reg < 0x4400 ? dev::kVsFloatConstants + (reg - 0x4000) * 4
                                                           : reg < 0x4800 ? dev::kPsFloatConstants + (reg - 0x4400) * 4
                                                           : reg < 0x4900 ? dev::kFetchConstants + (reg - 0x4800) * 4
                                                                          : dev::kBoolLoopConstants + (reg - 0x4900) * 4)); };
    if (!m.constants_initialized) {
      for (uint32_t r = 0; r < Impl::kConstCount; ++r) m.constants[r] = shadow(Impl::kConstBase + r);
      m.constants_initialized = true;
    }
    // Float constants: 64-bit masks at +0 (VS) and +8 (PS), MSB = group 0, 4 vec4 per group.
    for (uint32_t bank = 0; bank < 2; ++bank) {
      uint64_t mask = be64(bank * 8);
      for (uint32_t g = 0; g < 64; ++g) {
        if (!(mask & (1ull << (63 - g)))) continue;
        uint32_t reg0 = 0x4000 + bank * 0x400 + g * 16;
        for (uint32_t i = 0; i < 16; ++i) m.constants[reg0 - Impl::kConstBase + i] = shadow(reg0 + i);
      }
    }
    // Bool + loop constants (40 dwords from +10112): bit 56 of the mask at +32.
    if (be64(32) & (1ull << 56))
      for (uint32_t i = 0; i < 40; ++i) m.constants[0x900 + i] = shadow(0x4900 + i);
    // D3D-managed shaders (SetVertexShader/SetPixelShader) load their literals at the shader flush.
    if (debug_trace)
      std::fprintf(TraceOut(), "[seq %u] consts dirty16 %016llX dev_vs %08X dev_ps %08X\n", debug_seq,
                   (unsigned long long)be64(16), dev_vs, dev_ps);
    if (dev_vs && (be64(16) & (0xFull << 17))) LoadShaders(mem, dev_vs, dev_ps, 0);
  }
}

void Renderer::DrawInternal(const GuestMemory& mem, const uint8_t* device_be, const ShaderState& shader_state,
                            const DrawArgs& in_args) {
  DrawArgs args = in_args;
  Impl& m = *impl_;
  // Descriptor heaps nearly used up by this submission: flush now, before this draw allocates
  // anything (descriptors of recorded draws must stay intact until they execute).
  if (m.recording && m.view_next > m.ViewSlotEnd() - 4096) m.Submit(false);
  if (m.sampler_next > Impl::kSamplerHeapSize - 128) {
    // Deduplicated sampler tables persist across submissions; recycle the heap between draws.
    m.SubmitAndWait();
    m.sampler_tables.clear();
    m.sampler_input_tables.clear();
    m.sampler_next = 0;
    ++m.sampler_epoch;
  }
  m.EnsureRecording();
  // Constant file and fetch overlays for this draw (a re-run draw has them restored already).
  if (!m.replaying) UpdateDrawConstants(mem, device_be);
  RegisterFile& regs = m.regs;
  auto skip = [&](const char* why) {
    ++stats_.draws_skipped;
    ++stats_.skip_reasons[why];
  };
  ++stats_.draws;
  DrawProfiler draw_prof;

  FillRegisters(device_be, regs);
  if (args.tessellated && args.kind == DrawArgs::kIndexed && !args.index_physical &&
      regs.Get<reg::VGT_HOS_CNTL>().tess_mode == xenos::TessellationMode::kAdaptive) {
    // DrawIndexedTessellatedPrimitive in adaptive mode (sub_82207C30): the count is in patches and
    // the index buffer holds four 32-bit float edge factors per patch (start is in dwords).
    args.count *= 4;
    args.index_32bit = true;
  }
  draw_prof.Mark(11);  // -> fillregs
  // Directly written fetch constants, while the device's shadow copy is unchanged since.
  {
    for (uint8_t k : m.fetch_overlay_list) regs.values[0x4800 + k] = m.fetch_overlay[k].value;
  }
  // Shaders: the device's own fields (SetVertexShader/SetPixelShader path) win when set.
  ShaderState ss = shader_state;
  uint32_t dev_vs = BE32(device_be + dev::kVertexShader), dev_ps = BE32(device_be + dev::kPixelShader);
  if (dev_vs) {
    ss.vertex_shader = dev_vs;
    ss.pixel_shader = dev_ps;
  }
  // SQ_PROGRAM_CNTL / SQ_CONTEXT_MISC / SQ_INTERPOLATOR_CNTL / RB_MODECONTROL are computed from the
  // shader objects when shaders are loaded (GpuLoadShaders, or the shader flush inside the draw for
  // D3D-managed shaders), so the pre-call shadow does not have them.
  FillShaderRegisters(mem, ss, regs);
  // Per-draw registers D3D writes directly into the command stream.
  reg::VGT_DRAW_INITIATOR init{};
  init.prim_type = xenos::PrimitiveType(args.prim & 0x3F);
  init.source_select = args.kind == DrawArgs::kAuto ? xenos::SourceSelect::kAutoIndex : xenos::SourceSelect::kDMA;
  init.index_size = args.index_32bit ? xenos::IndexFormat::kInt32 : xenos::IndexFormat::kInt16;
  init.num_indices = args.count;
  if (args.tessellated) {
    init.major_mode = xenos::MajorMode::kExplicit;
    // D3D enables the tessellator inside the draw call (not in the pre-call shadow).
    reg::VGT_OUTPUT_PATH_CNTL path;
    path.value = regs.values[XE_GPU_REG_VGT_OUTPUT_PATH_CNTL];
    path.path_select = xenos::VGTOutputPath::kTessellationEnable;
    regs.values[XE_GPU_REG_VGT_OUTPUT_PATH_CNTL] = path.value;
  }
  regs.values[XE_GPU_REG_VGT_DRAW_INITIATOR] = init.value;
  regs.values[XE_GPU_REG_VGT_INDX_OFFSET] = args.base_vertex;
  if (args.up_vertex_fetch) {
    // Begin*Vertices writes fetch slot 31 (registers 0x48BA..0x48BF): four zero dwords, then vertex
    // fetch 95 = (address | type 3, size in dwords << 2 | k8in32 | 0x10000000).
    for (uint32_t i = 0; i < 4; ++i) regs.values[0x48BA + i] = 0;
    regs.values[0x48BE] = (args.up_vertex_physical & ~3u) | 3;
    regs.values[0x48BF] = 0x10000000u | ((args.up_vertex_bytes / 4) << 2) | uint32_t(xenos::Endian::k8in32);
  }

  draw_prof.Mark(1);  // -> shadercode
  // Shader microcode.
  ShaderCode vs_code, ps_code;
  uint32_t binding = ss.pixel_shader ? 0 : ((mem.Load32(ss.vertex_shader + 872) >> 4) & 1);
  if (args.vs_ucode && args.vs_ucode_dwords) {
    vs_code = {0, args.vs_ucode_dwords, args.vs_ucode};
  } else if (!GetVertexShaderCode(mem, ss.vertex_shader, dev_vs ? 0 : binding, &vs_code)) {
    return skip("no vertex shader");
  }
  bool has_ps = false;
  if (ss.pixel_shader) {
    if (args.ps_ucode && args.ps_ucode_dwords) {
      ps_code = {0, args.ps_ucode_dwords, args.ps_ucode};
      has_ps = true;
    } else {
      has_ps = GetPixelShaderCode(mem, ss.pixel_shader, &ps_code);
    }
  }
  D3D12Shader* vs = m.GetShader(vs_code, xenos::ShaderType::kVertex,
                                (args.vs_ucode && args.vs_ucode_dwords) ? args.vs_hash : 0);
  if (!vs) return skip("invalid vertex shader microcode");
  if (debug_trace)
    std::fprintf(TraceOut(), "[seq %u] vs obj %08X code %08X dwords %u w9 %08X | ps obj %08X code %08X dwords %u\n", debug_seq,
                 ss.vertex_shader, vs_code.physical, vs_code.dword_count,
                 vs_code.dword_count > 9 ? BE32(reinterpret_cast<const uint8_t*>(vs_code.ucode + 9)) : 0, ss.pixel_shader,
                 has_ps ? ps_code.physical : 0, has_ps ? ps_code.dword_count : 0);
  D3D12Shader* ps = has_ps ? m.GetShader(ps_code, xenos::ShaderType::kPixel,
                                          (args.ps_ucode && args.ps_ucode_dwords) ? args.ps_hash : 0)
                           : nullptr;
  if (ps && debug_ps_patch_hash && ps->ucode_data_hash() == debug_ps_patch_hash &&
      debug_ps_patch_instr * 3 + 2 < ps_code.dword_count) {
    static std::vector<uint32_t> patched;
    patched.assign(ps_code.ucode, ps_code.ucode + ps_code.dword_count);
    auto put = [&](uint32_t i, uint32_t v) {  // big-endian like the guest microcode
      patched[i] = (v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24);
    };
    uint32_t base = debug_ps_patch_instr * 3, r = debug_ps_patch_reg & 0x3F;
    put(base + 0, 0xC80F8000u);                          // vector dest oC0.xyzw (export), scalar retain_prev
    put(base + 1, 0);                                     // identity swizzles
    put(base + 2, 0xE2000000u | (r << 16) | (r << 8));    // max rR, rR
    ps_code.ucode = patched.data();
    ps = m.GetShader(ps_code, xenos::ShaderType::kPixel);
  }
  if (has_ps && !ps) return skip("invalid pixel shader microcode");
  draw_prof.Mark(2);  // -> livememory
  // Memory export: shaders writing guest memory (eA/eM, e.g. Fable II's per-frame compute-style point
  // draws whose results later draws fetch as vertex data). The writes go to the GPU copy of guest
  // memory (the shared memory UAV); the destinations are marked GPU-written so CPU-side uploads do not
  // overwrite them until the CPU itself writes there.
  const bool memexport = vs->memexport_eM_written() || (ps && ps->memexport_eM_written());
  std::vector<draw_util::MemExportRange> memexport_ranges;
  if (memexport) {
    draw_util::AddMemExportRanges(regs, *vs, memexport_ranges);
    if (ps) draw_util::AddMemExportRanges(regs, *ps, memexport_ranges);
    for (const auto& r : memexport_ranges) mem.RequestRange(r.base_address_dwords << 2, r.size_bytes);
    if (debug_trace)
      for (const auto& r : memexport_ranges)
        std::fprintf(TraceOut(), "[seq %u]   memexport to %08X size %u\n", debug_seq, r.base_address_dwords << 2,
                     r.size_bytes);
    if (args.kind == DrawArgs::kIndexed) return skip("memexport indexed draw (index buffer in UAV state)");
    ++stats_.skip_reasons["(info) memexport draw"];
  }
  // Live memory: bring the renderer's GPU copy of the vertex data up to date (before any per-draw
  // descriptor allocation - an upload may submit the command list).
  for (const auto& vb : vs->vertex_bindings()) {
    auto vf = regs.GetVertexFetch(vb.fetch_constant);
    if (vf.type == xenos::FetchConstantType::kVertex && vf.size)
      mem.RequestRange(uint32_t(vf.address) << 2, uint32_t(vf.size) << 2);
  }
  if (args.up_vertex_fetch && !m.replaying) {
    if (args.up_vertex_data)
      UploadPhysical(args.up_vertex_physical & 0x1FFFFFFF, args.up_vertex_data, args.up_vertex_bytes);
    else
      mem.UploadNow(args.up_vertex_physical, args.up_vertex_bytes);
  }
  if (args.kind == DrawArgs::kIndexed) {
    uint32_t ib_phys = args.index_physical, isz = args.index_32bit ? 4 : 2;
    if (!ib_phys) {
      uint32_t ib = BE32(device_be + dev::kIndexBuffer);
      if (ib) {
        isz = (args.index_32bit || (mem.Load32(ib) & 0x80000000u)) ? 4 : 2;
        ib_phys = GuestMemory::VirtualToPhysical(mem.Load32(ib + 24));
      }
    }
    if (ib_phys) {
      if (args.up_vertex_fetch) {
        if (!m.replaying) {
          if (args.up_index_data && args.index_physical)
            UploadPhysical((ib_phys + args.start * isz) & 0x1FFFFFFF, args.up_index_data, args.count * isz);
          else
            mem.UploadNow(ib_phys + args.start * isz, args.count * isz);
        }
      } else mem.RequestRange(ib_phys + args.start * isz, args.count * isz);
    }
  }
  if (!debug_shader_dir.empty()) {
    // Microcode disassembly of each shader object, once (named by guest object address).
    static std::unordered_map<uint64_t, bool> dumped;
    auto dump = [&](uint32_t obj, D3D12Shader* sh, const char* kind) {
      if (!sh || dumped[sh->ucode_data_hash()]) return;
      dumped[sh->ucode_data_hash()] = true;
      char name[64];
      std::snprintf(name, sizeof(name), "/%s_%016llX.txt", kind, (unsigned long long)sh->ucode_data_hash());
      if (FILE* f = std::fopen((debug_shader_dir + name).c_str(), "wb")) {
        std::fwrite(sh->ucode_disassembly().data(), 1, sh->ucode_disassembly().size(), f);
        std::fclose(f);
      }
    };
    dump(shader_state.vertex_shader, vs, "vs");
    dump(shader_state.pixel_shader, ps, "ps");
  }

  draw_prof.Mark(3);  // -> constants
  // Constants: bring the constant file up to date with what D3D's flush uploads for this draw (dirty
  // groups of the device shadow), then use it for the float and bool/loop constants.
  {
    std::memcpy(&regs.values[0x4000], m.constants, 0x800 * 4);
    std::memcpy(&regs.values[0x4900], &m.constants[0x900], 40 * 4);
  }

  if (!debug_dump_all_path.empty()) {
    static FILE* all = std::fopen(debug_dump_all_path.c_str(), "wb");
    if (all) {
      std::fwrite(&debug_seq, 4, 1, all);
      std::fwrite(&regs.values[0x2000], 4, 0x2A00, all);
    }
  }
  if (debug_dump_draw && stats_.draws == debug_dump_draw) {
    if (FILE* f = std::fopen(debug_dump_path.c_str(), "wb")) {
      std::fwrite(&regs.values[0x2000], 4, 0x2A00, f);
      std::fclose(f);
    }
  }

  draw_prof.Mark(4);  // -> primitive
  // Primitive handling.
  xenos::PrimitiveType prim = init.prim_type;
  D3D_PRIMITIVE_TOPOLOGY topology;
  D3D12_PRIMITIVE_TOPOLOGY_TYPE topology_type;
  uint32_t gs_type = 0;  // PipelineCache::PipelineGeometryShader
  using HostVS = gfx::Shader::HostVertexShaderType;
  HostVS host_vs_type = HostVS::kVertex;
  xenos::TessellationMode tess_mode = regs.Get<reg::VGT_HOS_CNTL>().tess_mode;
  if (args.tessellated) {
    bool adaptive = tess_mode == xenos::TessellationMode::kAdaptive;
    topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH;
    switch (prim) {
      case xenos::PrimitiveType::kQuadPatch:
        host_vs_type = HostVS::kQuadDomainPatchIndexed;
        topology = adaptive ? D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST
                            : D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST;
        break;
      case xenos::PrimitiveType::kTrianglePatch:
        host_vs_type = HostVS::kTriangleDomainPatchIndexed;
        topology = adaptive ? D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST
                            : D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST;
        break;
      case xenos::PrimitiveType::kTriangleList:
        host_vs_type = HostVS::kTriangleDomainCPIndexed;
        topology = D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST;
        break;
      case xenos::PrimitiveType::kQuadList:
        host_vs_type = HostVS::kQuadDomainCPIndexed;
        topology = D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST;
        break;
      default:
        return skip("unsupported tessellated primitive");
    }
  } else switch (prim) {
    case xenos::PrimitiveType::kPointList:
      topology = D3D_PRIMITIVE_TOPOLOGY_POINTLIST;
      topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT;
      gs_type = 1;
      break;
    case xenos::PrimitiveType::kLineList:
      topology = D3D_PRIMITIVE_TOPOLOGY_LINELIST;
      topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE;
      break;
    case xenos::PrimitiveType::kLineStrip:
      topology = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP;
      topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE;
      break;
    case xenos::PrimitiveType::kTriangleList:
      topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
      topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
      break;
    case xenos::PrimitiveType::kTriangleStrip:
      topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
      topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
      break;
    case xenos::PrimitiveType::k2DCopyRectListV0:
    case xenos::PrimitiveType::k2DCopyRectListV1:
    case xenos::PrimitiveType::k2DCopyRectListV2:
    case xenos::PrimitiveType::k2DCopyRectListV3:
    case xenos::PrimitiveType::k2DFillRectList:
      // Explicit-major-mode 2D copy/fill rectangles (D3D's EDRAM/HiZ housekeeping via sub_8221C9C8).
      // The emulated path never drew these either; nothing visible depends on them.
      return skip("2D copy rect list");
    case xenos::PrimitiveType::kRectangleList:
      topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
      topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
      gs_type = 2;
      init.prim_type = xenos::PrimitiveType::kRectangleList;
      regs.values[XE_GPU_REG_VGT_DRAW_INITIATOR] = init.value;
      break;
    case xenos::PrimitiveType::kQuadList:
      topology = D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ;
      topology_type = D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE;
      gs_type = 3;
      break;
    default:
      return skip("unsupported primitive");
  }
  bool primitive_polygonal = draw_util::IsPrimitivePolygonal(regs);

  // Depth / colour usage.
  reg::RB_DEPTHCONTROL depth_control = draw_util::GetNormalizedDepthControl(regs);
  uint32_t color_mask = ps ? draw_util::GetNormalizedColorMask(regs, ps->writes_color_targets()) : 0;
  auto surface_info = regs.Get<reg::RB_SURFACE_INFO>();
  uint32_t samples = debug_no_msaa ? 1
                     : surface_info.msaa_samples == xenos::MsaaSamples::k4X   ? 4
                     : surface_info.msaa_samples == xenos::MsaaSamples::k2X ? 2
                                                                            : 1;

  // Interpolators and shader modifications (as PipelineCache::GetCurrent*ShaderModification).
  uint32_t ps_param_gen_pos = UINT32_MAX;
  uint32_t interpolator_mask =
      ps ? (vs->writes_interpolators() &
            ps->GetInterpolatorInputMask(regs.Get<reg::SQ_PROGRAM_CNTL>(), regs.Get<reg::SQ_CONTEXT_MISC>(),
                                         ps_param_gen_pos))
         : 0;
  DxbcShaderTranslator::Modification vs_mod(m.translator->GetDefaultVertexShaderModification(
      vs->GetDynamicAddressableRegisterCount(regs.Get<reg::SQ_PROGRAM_CNTL>().vs_num_reg), host_vs_type));
  vs_mod.vertex.interpolator_mask = interpolator_mask;
  auto clip_cntl = regs.Get<reg::PA_CL_CLIP_CNTL>();
  uint32_t ucp = clip_cntl.clip_disable ? 0 : clip_cntl.ucp_ena;
  vs_mod.vertex.user_clip_plane_count = __builtin_popcount(ucp);
  vs_mod.vertex.user_clip_plane_cull = uint32_t(ucp && clip_cntl.ucp_cull_only_ena);
  vs_mod.vertex.point_ps_ucp_mode = clip_cntl.ps_ucp_mode;
  vs_mod.vertex.vertex_kill_and =
      uint32_t((vs->writes_point_size_edge_flag_kill_vertex() & 0b100) && !clip_cntl.vtx_kill_or);
  vs_mod.vertex.output_point_size = uint32_t((vs->writes_point_size_edge_flag_kill_vertex() & 0b001) &&
                                             prim == xenos::PrimitiveType::kPointList);
  static const bool depth_float24_enabled = std::getenv("NATIVE_DEPTH_FLOAT24") != nullptr;
  // D24FS8 depth as 20e4 in the pixel shader (experimental, NATIVE_DEPTH_FLOAT24=1): the SDK's
  // command processor - the reference - keeps full precision while drawing, so this is off.
  const bool depth_float24 = (depth_control.z_enable || depth_control.stencil_enable) &&
                             regs.Get<reg::RB_DEPTH_INFO>().depth_format == xenos::DepthRenderTargetFormat::kD24FS8 &&
                             !debug_no_depth && depth_float24_enabled;
  DxbcShaderTranslator::Modification ps_mod(0);
  if (ps) {
    ps_mod = DxbcShaderTranslator::Modification(m.translator->GetDefaultPixelShaderModification(
        ps->GetDynamicAddressableRegisterCount(regs.Get<reg::SQ_PROGRAM_CNTL>().ps_num_reg)));
    ps_mod.pixel.interpolator_mask = interpolator_mask;
    ps_mod.pixel.interpolators_centroid =
        interpolator_mask & ~xenos::GetInterpolatorSamplingPattern(
                                surface_info.msaa_samples, regs.Get<reg::SQ_CONTEXT_MISC>().sc_sample_cntl,
                                regs.Get<reg::SQ_INTERPOLATOR_CNTL>().sampling_pattern);
    if (ps_param_gen_pos < xenos::kMaxInterpolators) {
      ps_mod.pixel.param_gen_enable = 1;
      ps_mod.pixel.param_gen_interpolator = ps_param_gen_pos;
      ps_mod.pixel.param_gen_point = uint32_t(prim == xenos::PrimitiveType::kPointList);
    }
    using DepthStencilMode = DxbcShaderTranslator::Modification::DepthStencilMode;
    ps_mod.pixel.depth_stencil_mode =
        depth_float24 ? DepthStencilMode::kFloat24Truncating
        : (ps->implicit_early_z_write_allowed() &&
           (!ps->writes_color_target(0) || !draw_util::DoesCoverageDependOnAlpha(regs.Get<reg::RB_COLORCONTROL>())))
            ? DepthStencilMode::kEarlyHint
            : DepthStencilMode::kNoModifiers;
  }
  auto* vs_t = m.Translate(vs, vs_mod.value);
  auto* ps_t = ps ? m.Translate(ps, ps_mod.value) : nullptr;
  if (!vs_t || (ps && !ps_t)) return skip("shader translation failed");

  draw_prof.Mark(5);  // -> rendertargets
  // Render targets.
  D3D12_CPU_DESCRIPTOR_HANDLE rtvs[4];
  DXGI_FORMAT rt_formats[4] = {};
  uint32_t rt_count = 0;
  uint32_t width = std::max<uint32_t>(surface_info.surface_pitch, 1);
  draw_util::ViewportInfo vp;
  bool ps_writes_depth = ps && ps->writes_depth();
  draw_util::GetHostViewportInfo(regs, 1, 1, true, D3D12_VIEWPORT_BOUNDS_MAX, D3D12_VIEWPORT_BOUNDS_MAX, true,
                                 depth_control, depth_float24, false, ps_writes_depth, vp);
  draw_util::Scissor scissor;
  draw_util::GetScissor(regs, scissor);
  uint32_t height = std::max(vp.xy_offset[1] + vp.xy_extent[1], 16u);
  width = std::max(width, vp.xy_offset[0] + vp.xy_extent[0]);
  // D3D12 requires the bound render targets and depth buffer to have equal dimensions: size them all
  // to the union of the viewport, their guest surface sizes and their current host sizes.
  uint32_t common_w = width, common_h = height;
  {
    auto include = [&](uint32_t surface) {
      if (!surface) return;
      uint32_t sw, sh;
      Impl::SurfaceSize(mem, surface, &sw, &sh);
      common_w = std::max(common_w, sw);
      common_h = std::max(common_h, sh);
      auto it = m.render_targets.find(Impl::RtKey(mem, surface, surface == BE32(device_be + dev::kDepthStencil)));
      if (it != m.render_targets.end() && it->second.resource) {
        common_w = std::max(common_w, it->second.width);
        common_h = std::max(common_h, it->second.height);
      }
    };
    for (uint32_t i = 0; i < 4; ++i)
      if ((color_mask >> (i * 4)) & 0xF) include(BE32(device_be + dev::kRenderTargets + 4 * i));
    if (depth_control.z_enable || depth_control.stencil_enable) include(BE32(device_be + dev::kDepthStencil));
    common_w = std::min(common_w, 4096u);
    common_h = std::min(common_h, 4096u);
  }
  auto surface_extent = [&](uint32_t surface, uint32_t* w, uint32_t* h) {
    (void)surface;
    *w = common_w;
    *h = common_h;
  };
  Impl::DrawPacket pk_local;
  Impl::DrawPacket& pk = m.capture_packet ? *m.capture_packet : pk_local;
  pk.valid = false;
  pk.textures.clear();
  pk.width = common_w;
  pk.height = common_h;
  pk.samples = samples;
  for (uint32_t i = 0; i < 4; ++i) pk.rt_key[i] = 0;
  Impl::RenderTarget* bound_rts[4] = {};
  for (uint32_t i = 0; i < 4; ++i) {
    if (!((color_mask >> (i * 4)) & 0xF)) continue;
    uint32_t surface = BE32(device_be + dev::kRenderTargets + 4 * i);
    if (!surface) continue;
    auto color_info = regs.Get<reg::RB_COLOR_INFO>(kColorInfoRegs[i]);
    DXGI_FORMAT f = ColorFormat(color_info.color_format);
    uint32_t rw, rh;
    surface_extent(surface, &rw, &rh);
    uint32_t rt_key = Impl::RtKey(mem, surface, false);
    auto* rt = m.GetRenderTarget(rt_key, f, false, rw, rh, samples);
    if (!rt) continue;
    pk.rt_key[i] = rt_key & ~(1u << 27);
    pk.rt_format[i] = f;
    m.Transition(rt->resource.Get(), rt->state, D3D12_RESOURCE_STATE_RENDER_TARGET);
    // Render targets must be contiguous from 0 in D3D12; unused slots get a null view.
    while (rt_count < i) {
      rt_formats[rt_count] = DXGI_FORMAT_UNKNOWN;
      rtvs[rt_count] = rt->view;  // replaced below
      ++rt_count;
    }
    rt_formats[i] = f;
    rtvs[i] = rt->view;
    bound_rts[i] = rt;
    rt_count = i + 1;
  }
  bool depth_used = depth_control.z_enable || depth_control.stencil_enable;
  Impl::RenderTarget* ds = nullptr;
  DXGI_FORMAT ds_format = DXGI_FORMAT_UNKNOWN;
  pk.ds_key = 0;
  uint32_t ds_surface = BE32(device_be + dev::kDepthStencil);
  if (depth_used && ds_surface) {
    ds_format = DepthFormat(regs.Get<reg::RB_DEPTH_INFO>().depth_format);
    uint32_t dw, dh;
    surface_extent(ds_surface, &dw, &dh);
    pk.ds_key = Impl::RtKey(mem, ds_surface, true);
    ds = m.GetRenderTarget(pk.ds_key, ds_format, true, dw, dh, samples);
    pk.ds_key &= ~(1u << 27);
    pk.ds_format = ds_format;
    if (ds) m.Transition(ds->resource.Get(), ds->state, D3D12_RESOURCE_STATE_DEPTH_WRITE);
  }
  if (!rt_count && !ds) {
    if (!ps && !depth_used) return skip("no output");
    return skip("no bound render target");
  }
  if (debug_trace) {
    std::fprintf(TraceOut(), "[seq %u] draw prim %u count %u%s rt %08X/%08X/%08X/%08X mask %04X ds %08X z %u%u st %u vs %016llX ps %016llX%s",
                 debug_seq, unsigned(prim), args.count, args.tessellated ? " tess" : "",
                 BE32(device_be + dev::kRenderTargets), BE32(device_be + dev::kRenderTargets + 4),
                 BE32(device_be + dev::kRenderTargets + 8), BE32(device_be + dev::kRenderTargets + 12), color_mask,
                 ds ? ds_surface : 0, uint32_t(depth_control.z_enable), uint32_t(depth_control.z_write_enable),
                 uint32_t(depth_control.stencil_enable), (unsigned long long)vs->ucode_data_hash(),
                 ps ? (unsigned long long)ps->ucode_data_hash() : 0ull, "\n");
    std::fprintf(TraceOut(),
                 "[seq %u]   viewport offset %d,%d extent %u,%u ndc scale %g,%g,%g offset %g,%g,%g common %ux%u "
                 "vte %08X vport %08X %08X %08X %08X window_offset %08X scissor %d,%d-%d,%d\n",
                 debug_seq, vp.xy_offset[0], vp.xy_offset[1], vp.xy_extent[0], vp.xy_extent[1], vp.ndc_scale[0],
                 vp.ndc_scale[1], vp.ndc_scale[2], vp.ndc_offset[0], vp.ndc_offset[1], vp.ndc_offset[2], common_w,
                 common_h, regs.values[XE_GPU_REG_PA_CL_VTE_CNTL], regs.values[XE_GPU_REG_PA_CL_VPORT_XSCALE],
                 regs.values[XE_GPU_REG_PA_CL_VPORT_XOFFSET], regs.values[XE_GPU_REG_PA_CL_VPORT_YSCALE],
                 regs.values[XE_GPU_REG_PA_CL_VPORT_YOFFSET], regs.values[XE_GPU_REG_PA_SC_WINDOW_OFFSET],
                 int(scissor.offset[0]), int(scissor.offset[1]), int(scissor.offset[0] + scissor.extent[0]),
                 int(scissor.offset[1] + scissor.extent[1]));
    if (args.up_vertex_fetch && args.up_vertex_bytes) {
      if (const uint8_t* q = mem.Physical(args.up_vertex_physical, std::min<uint32_t>(args.up_vertex_bytes, 32))) {
        std::fprintf(TraceOut(), "[seq %u]   up data %08X:", debug_seq, args.up_vertex_physical);
        for (uint32_t i = 0; i + 4 <= std::min<uint32_t>(args.up_vertex_bytes, 32); i += 4) {
          uint32_t v = BE32(q + i);
          float f;
          std::memcpy(&f, &v, 4);
          std::fprintf(TraceOut(), " %g", f);
        }
        std::fprintf(TraceOut(), "\n");
      }
    }
  }
  // Fill holes with the first bound view's slot formats set to UNKNOWN (needs a real null RTV).
  for (uint32_t i = 0; i < rt_count; ++i) {
    if (!bound_rts[i]) {
      rt_formats[i] = DXGI_FORMAT_UNKNOWN;
      D3D12_CPU_DESCRIPTOR_HANDLE nh = m.rtv_heap->GetCPUDescriptorHandleForHeapStart();
      nh.ptr += size_t(4094) * m.rtv_inc;
      D3D12_RENDER_TARGET_VIEW_DESC nd{};
      nd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
      nd.ViewDimension = samples > 1 ? D3D12_RTV_DIMENSION_TEXTURE2DMS : D3D12_RTV_DIMENSION_TEXTURE2D;
      m.device->CreateRenderTargetView(nullptr, &nd, nh);
      rtvs[i] = nh;
    }
  }

  draw_prof.Mark(6);  // -> pipeline
  // Pipeline.
  const auto& vs_tex = vs->GetTextureBindingsAfterTranslation();
  const auto& vs_samp = vs->GetSamplerBindingsAfterTranslation();
  static const std::vector<gfx::DxbcShader::TextureBinding> kNoTex;
  static const std::vector<gfx::DxbcShader::SamplerBinding> kNoSamp;
  const auto& ps_tex = ps ? ps->GetTextureBindingsAfterTranslation() : kNoTex;
  const auto& ps_samp = ps ? ps->GetSamplerBindingsAfterTranslation() : kNoSamp;
  ID3D12RootSignature* root = m.GetRootSignature(uint32_t(vs_tex.size()), uint32_t(vs_samp.size()),
                                                 uint32_t(ps_tex.size()), uint32_t(ps_samp.size()), args.tessellated);
  if (!root) return skip("root signature");

  struct PipelineKey {
    const void* vs;
    const void* ps;
    const void* root;
    uint32_t gs, topology_type, samples, rt_count;
    DXGI_FORMAT rt[4], ds;
    uint32_t blend[4], write_mask;
    uint32_t cull, front_ccw, fill_wire, depth_clip;
    int32_t depth_bias;
    float slope;
    uint32_t depth_func, depth_write, stencil_enable, stencil_ops, stencil_masks;
    uint32_t strip_cut;
    uint32_t host_vs_type, tess_mode;
    uint32_t float24_depth_only;
  } key{};
  key.float24_depth_only = (!ps_t && depth_float24) ? 1 : 0;
  key.host_vs_type = uint32_t(host_vs_type);
  key.tess_mode = args.tessellated ? uint32_t(tess_mode) : 0;
  key.vs = vs_t;
  key.ps = ps_t;
  key.root = root;
  key.gs = gs_type;
  key.topology_type = topology_type;
  key.samples = samples;
  key.rt_count = rt_count;
  for (uint32_t i = 0; i < 4; ++i) {
    key.rt[i] = i < rt_count ? rt_formats[i] : DXGI_FORMAT_UNKNOWN;
    key.blend[i] = regs.values[kBlendControlRegs[i]] & 0x1FFF1FFF;
  }
  key.write_mask = color_mask;
  auto sc_mode = regs.Get<reg::PA_SU_SC_MODE_CNTL>();
  if (primitive_polygonal) {
    key.front_ccw = sc_mode.face == 0;
    if (sc_mode.cull_front && sc_mode.cull_back) return skip("both faces culled");
    key.cull = sc_mode.cull_front ? 1 : sc_mode.cull_back ? 2 : 0;
    if (debug_no_cull) key.cull = 0;
    if (sc_mode.poly_mode == xenos::PolygonModeEnable::kDualMode &&
        ((!sc_mode.cull_front && sc_mode.polymode_front_ptype != xenos::PolygonType::kTriangles) ||
         (!sc_mode.cull_back && sc_mode.polymode_back_ptype != xenos::PolygonType::kTriangles)))
      key.fill_wire = 1;
  }
  key.depth_clip = !clip_cntl.clip_disable && !debug_no_clip;
  if (ds) {
    float offset, offset_scale;
    draw_util::GetPreferredFacePolygonOffset(regs, primitive_polygonal, offset_scale, offset);
    key.depth_bias = draw_util::GetD3D10IntegerPolygonOffset(regs.Get<reg::RB_DEPTH_INFO>().depth_format, offset);
    key.slope = offset_scale * xenos::kPolygonOffsetScaleSubpixelUnit;
    key.ds = ds_format;
    key.depth_func = depth_control.z_enable ? uint32_t(depth_control.zfunc) : uint32_t(xenos::CompareFunction::kAlways);
    if (debug_no_depth || (debug_nodepth_seq && debug_seq == debug_nodepth_seq))
      key.depth_func = uint32_t(xenos::CompareFunction::kAlways);
    key.depth_write = depth_control.z_enable && depth_control.z_write_enable;
    key.stencil_enable = depth_control.stencil_enable;
    key.stencil_ops = (depth_control.value >> 8) & 0xFFFFFF;
    auto srm = regs.Get<reg::RB_STENCILREFMASK>();
    key.stencil_masks = (srm.stencilmask << 8) | srm.stencilwritemask;
  }
  key.strip_cut = regs.Get<reg::PA_SU_SC_MODE_CNTL>().multi_prim_ib_ena ? 1 : 0;
  uint64_t pkey = HashBytes(&key, sizeof(key));
  ID3D12PipelineState* pso = nullptr;
  Impl::PipelineEntry* pipeline = nullptr;
  std::shared_ptr<Impl::PipelineEntry> pipeline_ref;
  auto pit = m.pipelines.find(pkey);
  if (pit != m.pipelines.end()) {
    pipeline_ref = pit->second;
    pipeline = pipeline_ref.get();
  } else {
    D3D12_GRAPHICS_PIPELINE_STATE_DESC d{};
    d.pRootSignature = root;
    if (args.tessellated) {
      namespace ts = native_tess_shaders;
      if (tess_mode == xenos::TessellationMode::kAdaptive)
        d.VS = {ts::tessellation_adaptive_vs, sizeof(ts::tessellation_adaptive_vs)};
      else
        d.VS = {ts::tessellation_indexed_vs, sizeof(ts::tessellation_indexed_vs)};
      D3D12_SHADER_BYTECODE hs{};
      switch (tess_mode) {
        case xenos::TessellationMode::kDiscrete:
          hs = host_vs_type == HostVS::kTriangleDomainCPIndexed ? D3D12_SHADER_BYTECODE{ts::discrete_triangle_3cp_hs, sizeof(ts::discrete_triangle_3cp_hs)}
             : host_vs_type == HostVS::kTriangleDomainPatchIndexed ? D3D12_SHADER_BYTECODE{ts::discrete_triangle_1cp_hs, sizeof(ts::discrete_triangle_1cp_hs)}
             : host_vs_type == HostVS::kQuadDomainCPIndexed ? D3D12_SHADER_BYTECODE{ts::discrete_quad_4cp_hs, sizeof(ts::discrete_quad_4cp_hs)}
             : D3D12_SHADER_BYTECODE{ts::discrete_quad_1cp_hs, sizeof(ts::discrete_quad_1cp_hs)};
          break;
        case xenos::TessellationMode::kContinuous:
          hs = host_vs_type == HostVS::kTriangleDomainCPIndexed ? D3D12_SHADER_BYTECODE{ts::continuous_triangle_3cp_hs, sizeof(ts::continuous_triangle_3cp_hs)}
             : host_vs_type == HostVS::kTriangleDomainPatchIndexed ? D3D12_SHADER_BYTECODE{ts::continuous_triangle_1cp_hs, sizeof(ts::continuous_triangle_1cp_hs)}
             : host_vs_type == HostVS::kQuadDomainCPIndexed ? D3D12_SHADER_BYTECODE{ts::continuous_quad_4cp_hs, sizeof(ts::continuous_quad_4cp_hs)}
             : D3D12_SHADER_BYTECODE{ts::continuous_quad_1cp_hs, sizeof(ts::continuous_quad_1cp_hs)};
          break;
        default:
          hs = host_vs_type == HostVS::kTriangleDomainPatchIndexed
                   ? D3D12_SHADER_BYTECODE{ts::adaptive_triangle_hs, sizeof(ts::adaptive_triangle_hs)}
                   : D3D12_SHADER_BYTECODE{ts::adaptive_quad_hs, sizeof(ts::adaptive_quad_hs)};
          break;
      }
      d.HS = hs;
      d.DS = {vs_t->translated_binary().data(), vs_t->translated_binary().size()};
    } else {
      d.VS = {vs_t->translated_binary().data(), vs_t->translated_binary().size()};
    }
    if (ps_t) {
      d.PS = {ps_t->translated_binary().data(), ps_t->translated_binary().size()};
    } else if (key.float24_depth_only) {
      d.PS = {native_tess_shaders::float24_truncate_ps, sizeof(native_tess_shaders::float24_truncate_ps)};
    }
    std::vector<uint32_t>* gs_code = nullptr;
    if (gs_type) {
      uint64_t gkey = (uint64_t(gs_type) << 60) ^ vs_mod.value ^ (ps_mod.value * 31);
      auto git = m.geometry_shaders.find(gkey);
      if (git == m.geometry_shaders.end())
        git = m.geometry_shaders
                  .emplace(gkey, gfx::d3d12::PipelineCache::BuildPrimitiveGeometryShader(gs_type, vs_mod.value,
                                                                                         ps_mod.value))
                  .first;
      gs_code = &git->second;
      if (!gs_code->empty()) d.GS = {gs_code->data(), gs_code->size() * 4};
    }
    d.BlendState.IndependentBlendEnable = TRUE;
    for (uint32_t i = 0; i < rt_count; ++i) {
      auto& rtb = d.BlendState.RenderTarget[i];
      uint32_t wm = (color_mask >> (i * 4)) & 0xF;
      rtb.RenderTargetWriteMask = UINT8(wm);
      reg::RB_BLENDCONTROL bc;
      bc.value = regs.values[kBlendControlRegs[i]];
      D3D12_BLEND src = BlendFactor(uint32_t(bc.color_srcblend), false),
                  dst = BlendFactor(uint32_t(bc.color_destblend), false),
                  srca = BlendFactor(uint32_t(bc.alpha_srcblend), true),
                  dsta = BlendFactor(uint32_t(bc.alpha_destblend), true);
      D3D12_BLEND_OP op = BlendOp(uint32_t(bc.color_comb_fcn)), opa = BlendOp(uint32_t(bc.alpha_comb_fcn));
      bool enable = wm && !(src == D3D12_BLEND_ONE && dst == D3D12_BLEND_ZERO && op == D3D12_BLEND_OP_ADD &&
                            srca == D3D12_BLEND_ONE && dsta == D3D12_BLEND_ZERO && opa == D3D12_BLEND_OP_ADD);
      rtb.BlendEnable = enable;
      rtb.SrcBlend = src;
      rtb.DestBlend = dst;
      rtb.BlendOp = op;
      rtb.SrcBlendAlpha = srca;
      rtb.DestBlendAlpha = dsta;
      rtb.BlendOpAlpha = opa;
      if (op == D3D12_BLEND_OP_MIN || op == D3D12_BLEND_OP_MAX) {
        rtb.SrcBlend = rtb.DestBlend = D3D12_BLEND_ONE;
      }
      if (opa == D3D12_BLEND_OP_MIN || opa == D3D12_BLEND_OP_MAX) {
        rtb.SrcBlendAlpha = rtb.DestBlendAlpha = D3D12_BLEND_ONE;
      }
    }
    d.SampleMask = UINT_MAX;
    d.RasterizerState.FillMode = key.fill_wire ? D3D12_FILL_MODE_WIREFRAME : D3D12_FILL_MODE_SOLID;
    d.RasterizerState.CullMode = key.cull == 1 ? D3D12_CULL_MODE_FRONT : key.cull == 2 ? D3D12_CULL_MODE_BACK
                                                                                        : D3D12_CULL_MODE_NONE;
    d.RasterizerState.FrontCounterClockwise = key.front_ccw;
    d.RasterizerState.DepthBias = key.depth_bias;
    d.RasterizerState.SlopeScaledDepthBias = key.slope;
    d.RasterizerState.DepthClipEnable = key.depth_clip;
    d.RasterizerState.MultisampleEnable = samples > 1;
    if (ds) {
      d.DepthStencilState.DepthEnable = key.depth_func != uint32_t(xenos::CompareFunction::kAlways) || key.depth_write;
      d.DepthStencilState.DepthWriteMask = key.depth_write ? D3D12_DEPTH_WRITE_MASK_ALL : D3D12_DEPTH_WRITE_MASK_ZERO;
      d.DepthStencilState.DepthFunc = CompareFunc(xenos::CompareFunction(key.depth_func));
      d.DepthStencilState.StencilEnable = key.stencil_enable;
      auto srm = regs.Get<reg::RB_STENCILREFMASK>();
      d.DepthStencilState.StencilReadMask = UINT8(srm.stencilmask);
      d.DepthStencilState.StencilWriteMask = UINT8(srm.stencilwritemask);
      d.DepthStencilState.FrontFace = {StencilOp(depth_control.stencilfail), StencilOp(depth_control.stencilzfail),
                                       StencilOp(depth_control.stencilzpass), CompareFunc(depth_control.stencilfunc)};
      if (depth_control.backface_enable && primitive_polygonal) {
        d.DepthStencilState.BackFace = {StencilOp(depth_control.stencilfail_bf),
                                        StencilOp(depth_control.stencilzfail_bf),
                                        StencilOp(depth_control.stencilzpass_bf),
                                        CompareFunc(depth_control.stencilfunc_bf)};
      } else {
        d.DepthStencilState.BackFace = d.DepthStencilState.FrontFace;
      }
      d.DSVFormat = ds_format;
    }
    d.IBStripCutValue = key.strip_cut ? (args.index_32bit ? D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF
                                                          : D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF)
                                      : D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED;
    d.PrimitiveTopologyType = topology_type;
    d.NumRenderTargets = rt_count;
    for (uint32_t i = 0; i < rt_count; ++i) d.RTVFormats[i] = rt_formats[i];
    d.SampleDesc.Count = samples;
    uint32_t root_key = Impl::RootKey(uint32_t(vs_tex.size()), uint32_t(vs_samp.size()), uint32_t(ps_tex.size()),
                                      uint32_t(ps_samp.size()), args.tessellated);
    auto entry = m.RequestPipeline(d, root_key, async_pipelines);
    m.pipelines[pkey] = entry;
    pipeline_ref = entry;
    pipeline = entry.get();
  }
  int pipeline_state = pipeline->state.load(std::memory_order_acquire);
  if (pipeline_state == 0) {
    // Compiling in the background: move it to the front, wait while this frame's wait budget lasts,
    // else leave this draw out (it appears once ready).
    m.Expedite(pipeline_ref);
    if (m.pipeline_wait_left_us > 0) {
      auto t0 = std::chrono::steady_clock::now();
      auto deadline = t0 + std::chrono::microseconds(m.pipeline_wait_left_us);
      while ((pipeline_state = pipeline->state.load(std::memory_order_acquire)) == 0 &&
             std::chrono::steady_clock::now() < deadline)
        std::this_thread::yield();
      m.pipeline_wait_left_us -= std::chrono::duration_cast<std::chrono::microseconds>(
                                     std::chrono::steady_clock::now() - t0)
                                     .count();
    }
    if (pipeline_state == 0) return skip("pipeline compiling");
  }
  if (pipeline_state != 1) return skip("pipeline creation failed");
  pso = pipeline->pso.Get();

  // ---- Constants ----
  draw_prof.Mark(7);  // -> floatconst
  // Float constants packed by each shader's constant map.
  // (Traced, with the bool constants, for large point-list draws: procedural particles like snow.)
  const bool trace_consts = debug_trace && prim == xenos::PrimitiveType::kPointList && args.count >= 1024;
  if (trace_consts)
    std::fprintf(TraceOut(), "[seq %u]   bools %08X %08X %08X %08X %08X %08X %08X %08X\n", debug_seq,
                 regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031], regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031 + 1],
                 regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031 + 2], regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031 + 3],
                 regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031 + 4], regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031 + 5],
                 regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031 + 6], regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031 + 7]);
  auto pack_floats = [&](D3D12Shader* s, uint32_t base_reg, D3D12_GPU_VIRTUAL_ADDRESS* gpu) {
    const auto& map = s->constant_register_map();
    uint32_t n = std::max<uint32_t>(map.float_count, 1);
    static thread_local std::vector<uint32_t> buf;
    buf.assign(size_t(n) * 4, 0);
    uint32_t k = 0;
    for (uint32_t i = 0; i < 4; ++i) {
      uint64_t bits = map.float_bitmap[i];
      while (bits) {
        uint32_t b = uint32_t(__builtin_ctzll(bits));
        bits &= bits - 1;
        if (k < n) std::memcpy(&buf[size_t(k) * 4], &regs.values[base_reg + (i << 8) + (b << 2)], 16);
        if (trace_consts) {
          const uint32_t* c = &regs.values[base_reg + (i << 8) + (b << 2)];
          float f[4];
          std::memcpy(f, c, 16);
          std::fprintf(TraceOut(), "[seq %u]   %s c%u = %g %g %g %g\n", debug_seq,
                       base_reg == XE_GPU_REG_SHADER_CONSTANT_000_X ? "vs" : "ps", (i << 6) + b, f[0], f[1], f[2], f[3]);
        }
        ++k;
      }
    }
    m.UploadDedup(base_reg == XE_GPU_REG_SHADER_CONSTANT_000_X ? 1 : 2, buf.data(), uint32_t(buf.size() * 4), gpu);
  };
  D3D12_GPU_VIRTUAL_ADDRESS cb_float_vs, cb_float_ps, cb_fetch, cb_bool, cb_sys;
  pack_floats(vs, XE_GPU_REG_SHADER_CONSTANT_000_X, &cb_float_vs);
  if (ps) {
    pack_floats(ps, XE_GPU_REG_SHADER_CONSTANT_256_X, &cb_float_ps);
  } else {
    uint32_t zero[4] = {};
    m.UploadDedup(2, zero, 16, &cb_float_ps);
  }
  m.UploadDedup(0, &regs.values[XE_GPU_REG_SHADER_CONSTANT_FETCH_00_0], 32 * 6 * 4, &cb_fetch);
  m.UploadDedup(4, &regs.values[XE_GPU_REG_SHADER_CONSTANT_BOOL_000_031], (8 + 32) * 4, &cb_bool);

  draw_prof.Mark(8);  // -> sysconst
  // System constants (host render target path subset of UpdateSystemConstantValues).
  DxbcShaderTranslator::SystemConstants sys{};
  {
    auto vte = regs.Get<reg::PA_CL_VTE_CNTL>();
    uint32_t flags = 0;
    if (vte.vtx_xy_fmt) flags |= DxbcShaderTranslator::kSysFlag_XYDividedByW;
    if (vte.vtx_z_fmt) flags |= DxbcShaderTranslator::kSysFlag_ZDividedByW;
    if (vte.vtx_w0_fmt) flags |= DxbcShaderTranslator::kSysFlag_WNotReciprocal;
    if (primitive_polygonal) flags |= DxbcShaderTranslator::kSysFlag_PrimitivePolygonal;
    if (draw_util::IsPrimitiveLine(regs)) flags |= DxbcShaderTranslator::kSysFlag_PrimitiveLine;
    auto depth_info = regs.Get<reg::RB_DEPTH_INFO>();
    if (depth_info.depth_format == xenos::DepthRenderTargetFormat::kD24FS8)
      flags |= DxbcShaderTranslator::kSysFlag_DepthFloat24;
    auto colorcontrol = regs.Get<reg::RB_COLORCONTROL>();
    xenos::CompareFunction alpha_func =
        colorcontrol.alpha_test_enable ? colorcontrol.alpha_func : xenos::CompareFunction::kAlways;
    if (debug_no_alpha_test) alpha_func = xenos::CompareFunction::kAlways;
    flags |= uint32_t(alpha_func) << DxbcShaderTranslator::kSysFlag_AlphaPassIfLess_Shift;
    for (uint32_t i = 0; i < 4; ++i) {
      auto ci = regs.Get<reg::RB_COLOR_INFO>(kColorInfoRegs[i]);
      if (ci.color_format == xenos::ColorRenderTargetFormat::k_8_8_8_8_GAMMA)
        flags |= DxbcShaderTranslator::kSysFlag_ConvertColor0ToGamma << i;
      int32_t bias = ci.color_exp_bias;
      if (ci.color_format == xenos::ColorRenderTargetFormat::k_16_16 ||
          ci.color_format == xenos::ColorRenderTargetFormat::k_16_16_16_16)
        bias -= 5;
      uint32_t scale_bits = uint32_t(0x3F800000 + (bias << 23));
      std::memcpy(&sys.color_exp_bias[i], &scale_bits, 4);
    }
    if (memexport) flags |= DxbcShaderTranslator::kSysFlag_SharedMemoryIsUAV;
    sys.flags = flags;
    sys.tessellation_factor_range_min = regs.Get<float>(XE_GPU_REG_VGT_HOS_MIN_TESS_LEVEL) + 1.0f;
    sys.tessellation_factor_range_max = regs.Get<float>(XE_GPU_REG_VGT_HOS_MAX_TESS_LEVEL) + 1.0f;
    // Adaptive draws (the ground's depth prepass, factors all 1.0 in the index buffer) must produce
    // the same surface as the continuous colour pass drawn at the maximum level, or the colour pass
    // fails its GEQUAL test against the prepass. The emulated GPU tessellates them at the maximum
    // level (verified against its depth resolve), so do the same.
    if (args.tessellated && tess_mode == xenos::TessellationMode::kAdaptive)
      sys.tessellation_factor_range_min = sys.tessellation_factor_range_max;
    // Index format: the Begin*Vertices override, else the device's index buffer (its +0 flags).
    // Index endianness: the Begin*Vertices override, else the device index buffer's own (format
    // dword bits 29..30, which D3D copies into the draw packet even when it forces 32-bit indices
    // for adaptive tessellation factors).
    xenos::Endian index_endian = args.index_32bit ? xenos::Endian::k8in32 : xenos::Endian::k8in16;
    if (args.kind == DrawArgs::kIndexed && !args.index_physical) {
      uint32_t ib = BE32(device_be + dev::kIndexBuffer);
      if (ib) index_endian = xenos::Endian((mem.Load32(ib) >> 29) & 3);
    }
    sys.vertex_index_endian = args.kind == DrawArgs::kAuto ? xenos::Endian::kNone : index_endian;
    sys.vertex_index_offset = args.base_vertex;
    sys.vertex_index_min = regs.Get<reg::VGT_MIN_VTX_INDX>().min_indx;
    sys.vertex_index_max = regs.Get<reg::VGT_MAX_VTX_INDX>().max_indx;
    if (!clip_cntl.clip_disable) {
      float* w = sys.user_clip_planes[0];
      for (uint32_t i = 0; i < 6; ++i) {
        if (!(clip_cntl.ucp_ena & (1u << i))) continue;
        std::memcpy(w, &regs.values[XE_GPU_REG_PA_CL_UCP_0_X + i * 4], 16);
        w += 4;
      }
    }
    for (uint32_t i = 0; i < 3; ++i) {
      sys.ndc_scale[i] = vp.ndc_scale[i];
      sys.ndc_offset[i] = vp.ndc_offset[i];
    }
    if (prim == xenos::PrimitiveType::kPointList) {
      auto minmax = regs.Get<reg::PA_SU_POINT_MINMAX>();
      auto size = regs.Get<reg::PA_SU_POINT_SIZE>();
      sys.point_vertex_diameter_min = float(minmax.min_size) * (2.0f / 16.0f);
      sys.point_vertex_diameter_max = float(minmax.max_size) * (2.0f / 16.0f);
      sys.point_constant_diameter[0] = float(size.width) * (2.0f / 16.0f);
      sys.point_constant_diameter[1] = float(size.height) * (2.0f / 16.0f);
      sys.point_screen_diameter_to_ndc_radius[0] = 1.0f / std::max(vp.xy_extent[0], 1u);
      sys.point_screen_diameter_to_ndc_radius[1] = 1.0f / std::max(vp.xy_extent[1], 1u);
    }
    uint32_t used_textures = vs->GetUsedTextureMaskAfterTranslation() |
                             (ps ? ps->GetUsedTextureMaskAfterTranslation() : 0);
    for (uint32_t i = 0; i < 32; ++i) {
      if (!(used_textures & (1u << i))) continue;
      uint8_t signs = gfx::texture_util::SwizzleSigns(regs.GetTextureFetch(i));
      sys.texture_swizzled_signs[i >> 2] |= uint32_t(signs) << ((i & 3) * 8);
    }
    sys.sample_count_log2[0] = surface_info.msaa_samples >= xenos::MsaaSamples::k4X ? 1 : 0;
    sys.sample_count_log2[1] = surface_info.msaa_samples >= xenos::MsaaSamples::k2X ? 1 : 0;
    sys.alpha_test_reference = regs.Get<float>(XE_GPU_REG_RB_ALPHA_REF);
    sys.alpha_to_mask = colorcontrol.alpha_to_mask_enable ? (colorcontrol.value >> 24) | (1 << 8) : 0;
  }
  m.UploadDedup(3, &sys, uint32_t(sizeof(sys)), &cb_sys);

  // ---- Textures and samplers ----
  draw_prof.Mark(9);  // -> textures
  auto bind_textures = [&](const std::vector<gfx::DxbcShader::TextureBinding>& tex, uint32_t* table_out) {
    if (tex.empty()) return;
    size_t n = std::min<size_t>(tex.size(), 32);
    // Fast path: the same fetch constants (and binding dimensions) as an earlier draw of this
    // submission, none of the textures rewritten by the game or replaced since: the same table.
    uint64_t fast_key = 0;
    if (!debug_trace && tex.size() <= 32) {
      uint32_t raw[7 * 32];
      for (size_t i = 0; i < n; ++i) {
        std::memcpy(&raw[i * 7], &regs.values[0x4800 + tex[i].fetch_constant * 6], 24);
        raw[i * 7 + 6] = uint32_t(tex[i].dimension) | (tex[i].fetch_constant << 8);
      }
      fast_key = HashBytes(raw, n * 7 * sizeof(uint32_t)) ^ (uint64_t(n) << 56);
      auto f = m.fast_tables.find(fast_key);
      if (f != m.fast_tables.end() && f->second.epoch == m.texture_epoch &&
          f->second.resolve_generation == m.resolve_generation) {
        bool fresh = true;
        for (auto& [t, base] : f->second.textures)
          if (t && t->stale && t->stale->load(std::memory_order_acquire)) fresh = false;
        if (fresh) {
          for (auto& [t, base] : f->second.textures) {
            if (!t) continue;
            m.NotePrevDepthBase(t, base);
            m.Transition(t->resource.Get(), t->state, D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE);
            if (m.capture_packet) pk.textures.push_back({t, t->resource.Get()});
          }
          *table_out = f->second.table;
          return;
        }
      }
    }
    // Resolve the textures first; reuse an identical table written earlier in this submission.
    uint64_t key_words[3 * 32];
    Impl::Texture* found_t[32];
    xenos::xe_gpu_texture_fetch_t found_f[32];
    const uint64_t epoch = m.texture_epoch;
    for (size_t i = 0; i < n; ++i) {
      auto fetch = regs.GetTextureFetch(tex[i].fetch_constant);
      Impl::Texture* t = nullptr;
      if (fetch.type == xenos::FetchConstantType::kTexture) t = m.GetTexture(mem, fetch);
      found_t[i] = t;
      found_f[i] = fetch;
      m.NotePrevDepth(t, fetch);
      if (!t || (tex[i].dimension == xenos::FetchOpDimension::kCube && t->array_size < 6) ||
          tex[i].dimension == xenos::FetchOpDimension::k3DOrStacked) {
        const char* why = fetch.type != xenos::FetchConstantType::kTexture ? "null texture: fetch not a texture"
                          : !t ? "null texture: decode failed"
                          : tex[i].dimension == xenos::FetchOpDimension::k3DOrStacked ? "null texture: 3D/stacked binding"
                                                                                       : "null texture: cube mismatch";
        ++stats_.skip_reasons[why];
      }
      key_words[i * 3] = t ? uint64_t(reinterpret_cast<uintptr_t>(t->resource.Get())) : 0;
      key_words[i * 3 + 1] = t ? (uint64_t(t->swizzle) | uint64_t(t->format) << 32) : 0;
      key_words[i * 3 + 2] = uint64_t(tex[i].dimension) | (t ? uint64_t(t->mips) << 8 | uint64_t(t->array_size) << 16 : 0);
    }
    uint64_t table_key = HashBytes(key_words, n * 3 * sizeof(uint64_t)) ^ n;
    // The textures found above, unless a later lookup removed an entry an earlier one returned (then
    // they are looked up again). The swizzle is per binding, so it is set again for each.
    const bool reuse = m.texture_epoch == epoch && tex.size() <= 32;
    auto remember = [&](uint32_t table) {
      if (!fast_key || !reuse) return;
      auto& e = m.fast_tables[fast_key];
      e.table = table;
      e.epoch = m.texture_epoch;
      e.resolve_generation = m.resolve_generation;
      e.textures.clear();
      for (size_t i = 0; i < n; ++i) {
        uint32_t base = uint32_t(found_f[i].base_address) << 12;
        if (base >= 0xA0000000) base = GuestMemory::VirtualToPhysical(base);
        e.textures.push_back({found_t[i], base});
      }
    };
    auto lookup = [&](size_t i, const xenos::xe_gpu_texture_fetch_t& fetch) -> Impl::Texture* {
      if (!reuse) return fetch.type == xenos::FetchConstantType::kTexture ? m.GetTexture(mem, fetch) : nullptr;
      Impl::Texture* t = found_t[i];
      if (t) t->swizzle = gfx::TextureCache::GuestToHostSwizzle(fetch.swizzle, GetHostFormat(fetch.format).swizzle);
      return t;
    };
    if (!debug_trace) {
      auto found = m.srv_tables.find(table_key);
      if (found != m.srv_tables.end()) {
        for (size_t i = 0; i < n; ++i) {
          Impl::Texture* t = lookup(i, reuse ? found_f[i] : regs.GetTextureFetch(tex[i].fetch_constant));
          if (t) {
            m.Transition(t->resource.Get(), t->state, D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE);
            if (m.capture_packet) pk.textures.push_back({t, t->resource.Get()});
          }
        }
        *table_out = found->second;
        remember(found->second);
        return;
      }
    }
    uint32_t table = m.view_next;
    m.view_next += uint32_t(tex.size());
    m.srv_tables[table_key] = table;
    for (size_t i = 0; i < tex.size(); ++i) {
      auto fetch = reuse ? found_f[i] : regs.GetTextureFetch(tex[i].fetch_constant);
      Impl::Texture* t = lookup(i, fetch);
      if (debug_trace && fetch.type == xenos::FetchConstantType::kTexture) {
        uint32_t tb = uint32_t(fetch.base_address) << 12;
        if (tb >= 0xA0000000) tb = GuestMemory::VirtualToPhysical(tb);
        bool is_resolved = m.resolved.count(tb) != 0;
          std::fprintf(TraceOut(), "[seq %u]   samples %s %08X as fmt %u (stored dxgi %d) fetch %u exp %d signs %u%u%u%u\n",
                       debug_seq, is_resolved ? "resolved" : "memory  ", tb, uint32_t(fetch.format), t ? int(t->format) : -1, tex[i].fetch_constant,
                       int(fetch.exp_adjust), uint32_t(fetch.sign_x), uint32_t(fetch.sign_y), uint32_t(fetch.sign_z),
                       uint32_t(fetch.sign_w));
      }
      if (t) {
        m.Transition(t->resource.Get(), t->state, D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE);
        if (m.capture_packet) pk.textures.push_back({t, t->resource.Get()});
      }
      m.WriteTextureSrv(table + uint32_t(i), t, tex[i].dimension);
    }
    *table_out = table;
    remember(table);
  };
  auto sampler_descs = [&](const std::vector<gfx::DxbcShader::SamplerBinding>& samp) {
    std::vector<D3D12_SAMPLER_DESC> out;
    for (auto& b : samp) out.push_back(m.SamplerDesc(regs.GetTextureFetch(b.fetch_constant), b));
    return out;
  };
  uint32_t ps_tex_table = 0, vs_tex_table = 0;
  bind_textures(ps_tex, &ps_tex_table);
  bind_textures(vs_tex, &vs_tex_table);
  draw_prof.Mark(12);  // -> samplers
  D3D12_GPU_DESCRIPTOR_HANDLE ps_samp_table{}, vs_samp_table{};
  auto sampler_table = [&](const std::vector<gfx::DxbcShader::SamplerBinding>& samp, D3D12_GPU_DESCRIPTOR_HANDLE* out) {
    uint32_t words[16 * 11];
    size_t n = std::min<size_t>(samp.size(), 16), w = 0;
    for (size_t i = 0; i < n; ++i) {
      const auto& b = samp[i];
      words[w++] = b.fetch_constant;
      words[w++] = uint32_t(b.mag_filter) | uint32_t(b.min_filter) << 8 | uint32_t(b.mip_filter) << 16 |
                   uint32_t(b.aniso_filter) << 24;
      for (uint32_t d = 0; d < 6; ++d) words[w++] = regs.values[0x4800 + b.fetch_constant * 6 + d];
    }
    uint64_t key = HashBytes(words, w * 4) ^ (uint64_t(samp.size()) << 56);
    if (samp.size() <= 16) {
      auto it = m.sampler_input_tables.find(key);
      if (it != m.sampler_input_tables.end()) {
        *out = it->second;
        return;
      }
    }
    // (SamplerTable may recycle the heap, clearing the input cache; the new entry is still valid.)
    m.SamplerTable(sampler_descs(samp), out);
    if (samp.size() <= 16) m.sampler_input_tables[key] = *out;
  };
  if (!ps_samp.empty()) sampler_table(ps_samp, &ps_samp_table);
  if (!vs_samp.empty()) sampler_table(vs_samp, &vs_samp_table);

  // ---- Record ----
  pk.rt_count = rt_count;
  for (uint32_t i = 0; i < rt_count; ++i) pk.rtvs[i] = rtvs[i];
  pk.has_ds = ds != nullptr;
  pk.dsv = ds ? ds->view : D3D12_CPU_DESCRIPTOR_HANDLE{};
  pk.viewport = {float(vp.xy_offset[0]), float(vp.xy_offset[1]), float(vp.xy_extent[0]), float(vp.xy_extent[1]),
                 vp.z_min, vp.z_max};
  pk.scissor = {LONG(scissor.offset[0]), LONG(scissor.offset[1]), LONG(scissor.offset[0] + scissor.extent[0]),
                LONG(scissor.offset[1] + scissor.extent[1])};
  pk.blend[0] = regs.Get<float>(XE_GPU_REG_RB_BLEND_RED);
  pk.blend[1] = regs.Get<float>(XE_GPU_REG_RB_BLEND_GREEN);
  pk.blend[2] = regs.Get<float>(XE_GPU_REG_RB_BLEND_BLUE);
  pk.blend[3] = regs.Get<float>(XE_GPU_REG_RB_BLEND_ALPHA);
  pk.stencil_ref = regs.Get<reg::RB_STENCILREFMASK>().stencilref;
  pk.pso = pso;
  pk.root = root;
  pk.cb[0] = cb_fetch;
  pk.cb[1] = cb_float_vs;
  pk.cb[2] = cb_float_ps;
  pk.cb[3] = cb_sys;
  pk.cb[4] = cb_bool;
  pk.table_count = 0;
  pk.tables[pk.table_count++] = m.ViewGpu(0);
  if (!ps_tex.empty()) pk.tables[pk.table_count++] = m.ViewGpu(ps_tex_table);
  if (!ps_samp.empty()) pk.tables[pk.table_count++] = ps_samp_table;
  if (!vs_tex.empty()) pk.tables[pk.table_count++] = m.ViewGpu(vs_tex_table);
  if (!vs_samp.empty()) pk.tables[pk.table_count++] = vs_samp_table;
  pk.topology = topology;
  pk.indexed = args.kind == DrawArgs::kIndexed;
  pk.count = args.count;
  pk.start = args.start;
  if (pk.indexed) {
    uint32_t index_phys = args.index_physical;
    bool is32 = args.index_32bit;
    if (!index_phys) {
      uint32_t ib = BE32(device_be + dev::kIndexBuffer);
      if (!ib) return skip("no index buffer");
      is32 = args.index_32bit || (mem.Load32(ib) & 0x80000000u) != 0;
      index_phys = GuestMemory::VirtualToPhysical(mem.Load32(ib + 24));
    }
    uint32_t isz = is32 ? 4 : 2;
    if (!m.shared_gpu_va) m.shared_gpu_va = m.shared->GetGPUVirtualAddress();
    pk.ibv.BufferLocation = m.shared_gpu_va + index_phys + uint64_t(args.start) * isz;
    pk.ibv.SizeInBytes = args.count * isz;
    pk.ibv.Format = is32 ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
  }
  draw_prof.Mark(10);  // -> record
  m.EmitDraw(pk, memexport, state_cache);
  pk.valid = !memexport;
  pk.submit_epoch = m.submit_epoch;
  pk.sampler_epoch = m.sampler_epoch;
  if (memexport) {
    D3D12_RESOURCE_BARRIER uav{};
    uav.Type = D3D12_RESOURCE_BARRIER_TYPE_UAV;
    uav.UAV.pResource = m.shared.Get();
    m.list->ResourceBarrier(1, &uav);
    for (const auto& r : memexport_ranges) mem.GpuWroteRange(r.base_address_dwords << 2, r.size_bytes);
  }
  const bool probe_depth = ds && BE32(device_be + dev::kDepthStencil) == debug_probe_surface;
  if (debug_probe_x >= 0 && ((bound_rts[0] && BE32(device_be + dev::kRenderTargets) == debug_probe_surface) ||
                             probe_depth) && m.probe_seqs.size() < 4096) {
    constexpr uint32_t kProbeKey = 0xFFFFE000u;
    auto& pt = m.resolved[kProbeKey];
    if (!pt.resource) {
      D3D12_RESOURCE_DESC rd{};
      rd.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
      rd.Width = 4096;
      rd.Height = 1;
      rd.DepthOrArraySize = 1;
      rd.MipLevels = 1;
      rd.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
      rd.SampleDesc.Count = 1;
      rd.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
      D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_DEFAULT};
      m.device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &rd, D3D12_RESOURCE_STATE_COMMON, nullptr,
                                        IID_PPV_ARGS(&pt.resource));
      pt.format = rd.Format;
      pt.width = 4096;
      pt.height = 1;
      pt.state = D3D12_RESOURCE_STATE_COMMON;
    }
    Impl::RenderTarget* rt0 = probe_depth ? ds : bound_rts[0];
    m.Blit(rt0->resource.Get(), rt0->state, probe_depth ? DepthSrv(rt0->format) : rt0->format, rt0->samples, true,
           debug_probe_x, debug_probe_y,
           pt.resource.Get(), pt.state, DXGI_FORMAT_R32G32B32A32_FLOAT, int32_t(m.probe_seqs.size()), 0, 1, 1, 1.0f);
    m.probe_seqs.push_back(debug_seq);
  }
}

bool Renderer::DebugProbeResults(std::vector<std::pair<uint32_t, std::array<float, 4>>>* out) {
  Impl& m = *impl_;
  auto it = m.resolved.find(0xFFFFE000u);
  if (it == m.resolved.end()) return false;
  std::vector<uint8_t> rgba;
  std::vector<float> raw;
  uint32_t w, h;
  if (!ReadbackRGBA8(it->second.resource.Get(), &rgba, &w, &h, &raw)) return false;
  out->clear();
  for (size_t i = 0; i < m.probe_seqs.size(); ++i)
    out->push_back({m.probe_seqs[i], {raw[i * 4], raw[i * 4 + 1], raw[i * 4 + 2], raw[i * 4 + 3]}});
  return true;
}

// -------------------------------------------------------------------------------------------------

void Renderer::ClearInternal(const GuestMemory& mem, const uint8_t* device_be, const ClearArgs& args) {
  Impl& m = *impl_;
  m.EnsureRecording();
  ++stats_.clears;
  FillRegisters(device_be, m.regs);
  auto surface_info = m.regs.Get<reg::RB_SURFACE_INFO>();
  uint32_t samples = debug_no_msaa ? 1
                     : surface_info.msaa_samples == xenos::MsaaSamples::k4X   ? 4
                     : surface_info.msaa_samples == xenos::MsaaSamples::k2X ? 2
                                                                            : 1;
  D3D12_RECT rect{args.x1, args.y1, args.x2, args.y2};
  if (debug_trace)
    std::fprintf(TraceOut(), "[seq %u] clear flags %X rt0 %08X ds %08X color %g %g %g %g z %g st %u rect %d %d,%d-%d,%d"
                 "\n", debug_seq, args.flags, BE32(device_be + dev::kRenderTargets), BE32(device_be + dev::kDepthStencil),
                 args.color[0], args.color[1], args.color[2], args.color[3], args.z, args.stencil, int(args.has_rect),
                 args.x1, args.y1, args.x2, args.y2);
  for (uint32_t i = 0; i < 4; ++i) {
    if (!(args.flags & (1u << i))) continue;
    uint32_t surface = BE32(device_be + dev::kRenderTargets + 4 * i);
    if (!surface) continue;
    auto ci = m.regs.Get<reg::RB_COLOR_INFO>(kColorInfoRegs[i]);
    uint32_t w, h;
    Impl::SurfaceSize(mem, surface, &w, &h);
    if (args.has_rect) {
      w = std::max(w, uint32_t(std::max(args.x2, 1)));
      h = std::max(h, uint32_t(std::max(args.y2, 1)));
    }
    auto* rt = m.GetRenderTarget(Impl::RtKey(mem, surface, false), ColorFormat(ci.color_format), false, w, h, samples);
    if (!rt) continue;
    m.Transition(rt->resource.Get(), rt->state, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m.list->ClearRenderTargetView(rt->view, args.color, args.has_rect ? 1 : 0, args.has_rect ? &rect : nullptr);
  }
  if (args.flags & 0x30) {
    uint32_t surface = BE32(device_be + dev::kDepthStencil);
    if (surface) {
      DXGI_FORMAT f = DepthFormat(m.regs.Get<reg::RB_DEPTH_INFO>().depth_format);
      uint32_t w, h;
      Impl::SurfaceSize(mem, surface, &w, &h);
      if (args.has_rect) {
        w = std::max(w, uint32_t(std::max(args.x2, 1)));
        h = std::max(h, uint32_t(std::max(args.y2, 1)));
      }
      auto* ds = m.GetRenderTarget(Impl::RtKey(mem, surface, true), f, true, w, h, samples);
      if (ds) {
        m.Transition(ds->resource.Get(), ds->state, D3D12_RESOURCE_STATE_DEPTH_WRITE);
        D3D12_CLEAR_FLAGS cf = D3D12_CLEAR_FLAGS(((args.flags & 0x10) ? D3D12_CLEAR_FLAG_DEPTH : 0) |
                                                 ((args.flags & 0x20) ? D3D12_CLEAR_FLAG_STENCIL : 0));
        m.list->ClearDepthStencilView(ds->view, cf, args.z, UINT8(args.stencil), args.has_rect ? 1 : 0,
                                      args.has_rect ? &rect : nullptr);
      }
    }
  }
}

uint32_t FindRegisterWrite(const uint8_t* p, size_t n_bytes, uint32_t reg, uint32_t fallback) {
  size_t n = n_bytes / 4;
  for (size_t i = 0; i < n;) {
    uint32_t h = BE32(p + i * 4), type = h >> 30;
    if (type == 0) {
      uint32_t cnt = ((h >> 16) & 0x3FFF) + 1, base = h & 0x7FFF;
      bool one_reg = (h >> 15) & 1;
      for (uint32_t k = 0; k < cnt && i + 1 + k < n; ++k)
        if ((one_reg ? base : base + k) == reg) return BE32(p + (i + 1 + k) * 4);
      i += 1 + cnt;
    } else if (type == 3) {
      i += 2 + ((h >> 16) & 0x3FFF);
    } else {
      ++i;
    }
  }
  return fallback;
}

void Renderer::ResolveInternal(const GuestMemory& mem, const uint8_t* device_be, const ResolveArgs& args) {
  Impl& m = *impl_;
  m.EnsureRecording();
  ++stats_.resolves;
  uint32_t source = args.flags & 7;
  uint32_t surface = BE32(device_be + (source == 4 ? dev::kDepthStencil : dev::kRenderTargets + 4 * source));
  auto rit = surface ? m.render_targets.find(Impl::RtKey(mem, surface, source == 4)) : m.render_targets.end();
  Impl::RenderTarget* rt = rit == m.render_targets.end() ? nullptr : &rit->second;

  if (rt && args.dest_texture) {
    // Destination texture: its fetch constant (object +28) gives address, format and size.
    const uint8_t* f = mem.Virtual(args.dest_texture + 28, 24);
    if (f) {
      xenos::xe_gpu_texture_fetch_t fetch;
      uint32_t* d = &fetch.dword_0;
      for (uint32_t i = 0; i < 6; ++i) d[i] = BE32(f + i * 4);
      // The texture object's own fetch constant holds a virtual (0xA/0xC/0xE-range) address; the copy
      // D3D binds in the device holds the physical one. Key resolved textures by physical address.
      uint32_t base = uint32_t(fetch.base_address) << 12;
      if (base >= 0xA0000000) base = GuestMemory::VirtualToPhysical(base);
      uint32_t w1, h1, d1, bp, mp, mmin, mmax;
      gfx::texture_util::GetSubresourcesFromFetchConstant(fetch, &w1, &h1, &d1, &bp, &mp, &mmin, &mmax);
      HostFormat hf = GetHostFormat(fetch.format);
      DXGI_FORMAT dst_format = hf.dxgi;
      if (dst_format == DXGI_FORMAT_UNKNOWN || (dst_format >= DXGI_FORMAT_BC1_TYPELESS && dst_format <= DXGI_FORMAT_BC5_SNORM))
        dst_format = DXGI_FORMAT_R16G16B16A16_FLOAT;
      auto& t = m.resolved[base];
      // Exactly the destination texture's size: guest memory is reused for textures of other sizes
      // (e.g. a 1280-wide loading screen, then the 1120-wide scene), and sampling uses the whole copy.
      if (!t.resource || t.format != dst_format || t.width != w1 + 1 || t.height != h1 + 1) {
        ++m.resolve_generation;  // (texture tables referencing the old copy are not reused)
        // The game alternates sizes/formats at the same address within a frame (e.g. 280x180 and
        // 560x360 bloom targets): park the current copy and reuse a parked one of the wanted shape
        // instead of allocating GPU memory every time.
        auto pool_key = [base](DXGI_FORMAT f, uint32_t w, uint32_t h) {
          return uint64_t(base) ^ (uint64_t(f) << 32) ^ (uint64_t(w) << 40) ^ (uint64_t(h) << 52);
        };
        if (t.resource) {
          auto& parked = m.resolved_pool[pool_key(t.format, t.width, t.height)];
          if (parked.resource) m.retired.push_back(parked.resource);
          parked = std::move(t);
        }
        t = Impl::Texture{};
        auto pit = m.resolved_pool.find(pool_key(dst_format, w1 + 1, h1 + 1));
        if (pit != m.resolved_pool.end() && pit->second.resource) {
          t = std::move(pit->second);
          m.resolved_pool.erase(pit);
        }
        if (m.resolved_pool.size() > 256) {  // bound the parked copies
          for (auto& [k, v] : m.resolved_pool)
            if (v.resource) m.retired.push_back(v.resource);
          m.resolved_pool.clear();
        }
      }
      if (!t.resource) {
        t = Impl::Texture{};
        D3D12_RESOURCE_DESC rd{};
        rd.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
        rd.Width = w1 + 1;
        rd.Height = h1 + 1;
        rd.DepthOrArraySize = 1;
        rd.MipLevels = 1;
        rd.Format = dst_format;
        rd.SampleDesc.Count = 1;
        rd.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
        D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_DEFAULT};
        m.device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &rd, D3D12_RESOURCE_STATE_COMMON, nullptr,
                                          IID_PPV_ARGS(&t.resource));
        t.format = dst_format;
        t.width = w1 + 1;
        t.height = h1 + 1;
        t.dimension = xenos::DataDimension::k2DOrStacked;
        t.state = D3D12_RESOURCE_STATE_COMMON;
      }
      t.swizzle = gfx::TextureCache::GuestToHostSwizzle(fetch.swizzle, hf.swizzle);
      // Live memory: if the CPU later writes this texture's guest memory (reused for other data), the
      // resolved copy is dropped and the texture is decoded from memory again.
      if (!t.stale || t.stale->load(std::memory_order_acquire)) {
        t.stale = std::make_shared<std::atomic<bool>>(false);
        const gfx::FormatInfo* fi = gfx::FormatInfo::Get(fetch.format);
        uint32_t bpp = fi ? std::max<uint32_t>(fi->bits_per_pixel / 8, 1) : 4;
        uint32_t bytes = ((w1 + 32) & ~31u) * ((h1 + 32) & ~31u) * bpp;
        mem.WatchRange(base, bytes, t.stale);
      }
      int32_t sx = 0, sy = 0;
      uint32_t w = t.width, h = t.height;
      if (args.has_source_rect) {
        sx = args.src_x1;
        sy = args.src_y1;
        w = uint32_t(std::max(args.src_x2 - args.src_x1, 0));
        h = uint32_t(std::max(args.src_y2 - args.src_y1, 0));
      }
      w = std::min(w, t.width - std::min<uint32_t>(args.dest_x, t.width));
      h = std::min(h, t.height - std::min<uint32_t>(args.dest_y, t.height));
      int32_t exp_bias = int32_t(args.flags << 10) >> 26;  // bits 16..21, signed
      float scale = std::ldexp(1.0f, exp_bias);
      DXGI_FORMAT srv = rt->depth ? DepthSrv(rt->format) : rt->format;
      if (debug_trace)
        std::fprintf(TraceOut(),
                     "[seq %u] resolve src %u surface %08X (dxgi %d %ux%u x%u) -> tex %08X fmt %u (dxgi %d %ux%u) "
                     "rect %d,%d-%d,%d dst %d,%d exp %d flags %08X dest_info %08X\n",
                     debug_seq, source, surface, int(rt->format), rt->width, rt->height, rt->samples, base,
                     uint32_t(fetch.format), int(dst_format), t.width, t.height, args.src_x1, args.src_y1, args.src_x2,
                     args.src_y2, args.dest_x, args.dest_y, exp_bias, args.flags, args.copy_dest_info);
      if (t.resource)
        m.Blit(rt->resource.Get(), rt->state, srv, rt->samples, (args.flags & 0x10) != 0, sx, sy, t.resource.Get(),
               t.state, dst_format, args.dest_x, args.dest_y, w, h, scale,
               !rt->depth && (args.copy_dest_info & (1u << 24)) != 0);
      t.red_blue_swapped = !rt->depth && (args.copy_dest_info & (1u << 24)) != 0;
      t.from_depth = rt->depth;
      t.resolve_frame = m.frame_index;
    }
  }
  // Clears after the copy. With predicated tiling the game resolves (and clears) one tile at a time;
  // on the console that only touches the tile's EDRAM, so only the resolved rectangle is cleared here.
  D3D12_RECT clear_rect{args.src_x1, args.src_y1, args.src_x2, args.src_y2};
  const D3D12_RECT* clear_rects = args.has_source_rect ? &clear_rect : nullptr;
  UINT clear_rect_count = args.has_source_rect ? 1 : 0;
  if (rt && (args.flags & 0x100) && !rt->depth) {
    m.Transition(rt->resource.Get(), rt->state, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m.list->ClearRenderTargetView(rt->view, args.clear_color, clear_rect_count, clear_rects);
  }
  if (args.flags & 0x200) {
    uint32_t ds_surface = BE32(device_be + dev::kDepthStencil);
    auto dit = m.render_targets.find(Impl::RtKey(mem, ds_surface, true));
    if (dit != m.render_targets.end() && dit->second.depth) {
      auto& ds = dit->second;
      m.Transition(ds.resource.Get(), ds.state, D3D12_RESOURCE_STATE_DEPTH_WRITE);
      m.list->ClearDepthStencilView(ds.view, D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, args.clear_z,
                                    UINT8(args.clear_stencil), clear_rect_count, clear_rects);
    }
  }
}

bool Renderer::PresentFrontbuffer(uint32_t base_address, ID3D12Resource* dst, D3D12_RESOURCE_STATES dst_state) {
  Impl& m = *impl_;
  FlushDeferred();
  auto it = m.resolved.find(base_address);
  if (it == m.resolved.end() || !it->second.resource || !dst) return false;
  Impl::Texture& src = it->second;
  D3D12_RESOURCE_DESC dd = dst->GetDesc();
  m.EnsureRecording();
  // Format conversion into an intermediate render target of the destination's format, then a copy
  // (the presenter's texture only allows UAV access).
  if (!m.present_tmp || m.present_tmp->GetDesc().Width != dd.Width || m.present_tmp->GetDesc().Height != dd.Height) {
    if (m.present_tmp) m.retired.push_back(m.present_tmp);
    m.present_tmp.Reset();
    D3D12_RESOURCE_DESC td{};
    td.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    td.Width = dd.Width;
    td.Height = dd.Height;
    td.DepthOrArraySize = 1;
    td.MipLevels = 1;
    td.Format = dd.Format;
    td.SampleDesc.Count = 1;
    td.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
    D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_DEFAULT};
    if (FAILED(m.device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &td, D3D12_RESOURCE_STATE_COMMON, nullptr,
                                                 IID_PPV_ARGS(&m.present_tmp))))
      return false;
    m.present_tmp_state = D3D12_RESOURCE_STATE_COMMON;
  }
  uint32_t w = std::min<uint32_t>(uint32_t(dd.Width), src.width), h = std::min<uint32_t>(dd.Height, src.height);
  m.Blit(src.resource.Get(), src.state, src.format, 1, true, 0, 0, m.present_tmp.Get(), m.present_tmp_state, dd.Format,
         0, 0, w, h, 1.0f, src.red_blue_swapped);
  m.Transition(m.present_tmp.Get(), m.present_tmp_state, D3D12_RESOURCE_STATE_COPY_SOURCE);
  D3D12_RESOURCE_STATES ds = dst_state;
  m.Transition(dst, ds, D3D12_RESOURCE_STATE_COPY_DEST);
  D3D12_TEXTURE_COPY_LOCATION from{m.present_tmp.Get(), D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX, {}},
      to{dst, D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX, {}};
  m.list->CopyTextureRegion(&to, 0, 0, 0, &from, nullptr);
  m.Transition(dst, ds, dst_state);
  m.Submit(false);  // same queue as the presenter: ordered without waiting
  return true;
}

bool Renderer::DecodeReference(const GuestMemory& mem, const uint32_t fetch_dwords[6], std::vector<uint8_t>* rgba,
                               uint32_t* width, uint32_t* height, std::vector<float>* raw_rgba) {
  Impl& m = *impl_;
  xenos::xe_gpu_texture_fetch_t fetch;
  std::memcpy(&fetch.dword_0, fetch_dwords, 24);
  DecodedTexture dec;
  if (!DecodeTexture(mem, fetch, &dec)) return false;
  m.EnsureRecording();
  // Parked in the resolved map under an unused key so the readback finds its resource state.
  constexpr uint32_t kKey = 0xFFFFF000u;
  auto& t = m.resolved[kKey];
  t = Impl::Texture{};
  bool ok = m.CreateTexture(dec, t) && ReadbackRGBA8(t.resource.Get(), rgba, width, height, raw_rgba);
  m.retired.push_back(t.resource);
  m.resolved.erase(kKey);
  ++m.texture_epoch;
  return ok;
}

// -------------------------------------------------------------------------------------------------

bool Renderer::ReadbackRGBA8(ID3D12Resource* resource, std::vector<uint8_t>* rgba, uint32_t* width,
                             uint32_t* height, std::vector<float>* raw_rgba) {
  Impl& m = *impl_;
  if (!resource) return false;
  D3D12_RESOURCE_DESC rd = resource->GetDesc();
  // Blit into a single-sampled RGBA16F target, then copy that to a readback buffer.
  D3D12_RESOURCE_DESC td{};
  td.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
  td.Width = rd.Width;
  td.Height = rd.Height;
  td.DepthOrArraySize = 1;
  td.MipLevels = 1;
  td.Format = DXGI_FORMAT_R16G16B16A16_FLOAT;
  td.SampleDesc.Count = 1;
  td.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
  D3D12_HEAP_PROPERTIES hp{D3D12_HEAP_TYPE_DEFAULT}, rbp{D3D12_HEAP_TYPE_READBACK};
  ComPtr<ID3D12Resource> tmp, rb;
  if (FAILED(m.device->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &td, D3D12_RESOURCE_STATE_COMMON, nullptr,
                                               IID_PPV_ARGS(&tmp))))
    return false;
  D3D12_PLACED_SUBRESOURCE_FOOTPRINT fp;
  UINT64 total;
  m.device->GetCopyableFootprints(&td, 0, 1, 0, &fp, nullptr, nullptr, &total);
  D3D12_RESOURCE_DESC bd{};
  bd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
  bd.Width = total;
  bd.Height = 1;
  bd.DepthOrArraySize = 1;
  bd.MipLevels = 1;
  bd.SampleDesc.Count = 1;
  bd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
  if (FAILED(m.device->CreateCommittedResource(&rbp, D3D12_HEAP_FLAG_NONE, &bd, D3D12_RESOURCE_STATE_COPY_DEST,
                                               nullptr, IID_PPV_ARGS(&rb))))
    return false;
  m.EnsureRecording();
  // Find the tracked state of the source.
  D3D12_RESOURCE_STATES dummy_state = D3D12_RESOURCE_STATE_COMMON;
  D3D12_RESOURCE_STATES* src_state = &dummy_state;
  DXGI_FORMAT srv = rd.Format;
  for (auto& [k, rt] : m.render_targets)
    if (rt.resource.Get() == resource) {
      src_state = &rt.state;
      srv = rt.depth ? DepthSrv(rt.format) : rt.format;
    }
  for (auto& [k, t] : m.resolved)
    if (t.resource.Get() == resource) src_state = &t.state;
  for (auto& h : m.history)
    if (h.tex.resource.Get() == resource) src_state = &h.tex.state;
  D3D12_RESOURCE_STATES tmp_state = D3D12_RESOURCE_STATE_COMMON;
  m.Blit(resource, *src_state, srv, rd.SampleDesc.Count, true, 0, 0, tmp.Get(), tmp_state,
         DXGI_FORMAT_R16G16B16A16_FLOAT, 0, 0, uint32_t(rd.Width), rd.Height, 1.0f);
  m.Transition(tmp.Get(), tmp_state, D3D12_RESOURCE_STATE_COPY_SOURCE);
  D3D12_TEXTURE_COPY_LOCATION src{tmp.Get(), D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX, {}}, dst{};
  src.SubresourceIndex = 0;
  dst.pResource = rb.Get();
  dst.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
  dst.PlacedFootprint = fp;
  m.list->CopyTextureRegion(&dst, 0, 0, 0, &src, nullptr);
  m.SubmitAndWait();
  uint8_t* p = nullptr;
  D3D12_RANGE r{0, SIZE_T(total)};
  if (FAILED(rb->Map(0, &r, reinterpret_cast<void**>(&p))) || !p) {
    std::fprintf(stderr, "readback failed (device removed reason %08X)\n",
                 unsigned(m.device->GetDeviceRemovedReason()));
    return false;
  }
  *width = uint32_t(rd.Width);
  *height = rd.Height;
  rgba->resize(size_t(*width) * *height * 4);
  if (raw_rgba) raw_rgba->resize(size_t(*width) * *height * 4);
  auto half = [](uint16_t h) {
    uint32_t s = (h >> 15) & 1, e = (h >> 10) & 0x1F, f = h & 0x3FF;
    float v = e == 0 ? std::ldexp(float(f), -24) : e == 31 ? 65504.0f : std::ldexp(float(f | 0x400), int(e) - 25);
    return s ? -v : v;
  };
  for (uint32_t y = 0; y < *height; ++y) {
    const uint16_t* row = reinterpret_cast<const uint16_t*>(p + fp.Offset + size_t(y) * fp.Footprint.RowPitch);
    for (uint32_t x = 0; x < *width; ++x) {
      for (uint32_t c = 0; c < 4; ++c) {
        float v = half(row[x * 4 + c]);
        if (raw_rgba) (*raw_rgba)[(size_t(y) * *width + x) * 4 + c] = v;
        v = std::min(std::max(v, 0.0f), 1.0f);
        (*rgba)[(size_t(y) * *width + x) * 4 + c] = uint8_t(std::lround(v * 255.0f));
      }
    }
  }
  rb->Unmap(0, nullptr);
  return true;
}

}  // namespace native
