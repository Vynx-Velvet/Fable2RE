// Fable2Replay: offline replayer for D3D frame captures (native renderer development).
//
//   Fable2Replay <capture dir> [--out <dir>] [--no-rect2d] [--debug-layer]
//
// Replays a captured frame through the native D3D12 renderer (native/renderer.*): every D3D call
// of the frame in order, state from the captured device object. Writes the Swap front buffer,
// every resolved texture and every render target as PNGs into the output directory.
#include "capture.h"
#include "../src/d3d_hooks.h"
#include "../native/png.h"
#include "../native/renderer.h"
#include "sampler.h"

#include <d3d12.h>
#include <dxgi1_4.h>
#include <wrl/client.h>

#include <chrono>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include <map>
#include <string>
#include <vector>

using namespace replay;
using Microsoft::WRL::ComPtr;

namespace {

class CaptureMemory : public native::GuestMemory {
 public:
  explicit CaptureMemory(const Capture& cap) : cap_(cap) {}
  const uint8_t* Physical(uint32_t addr, uint32_t size) const override { return cap_.Physical(addr, size); }
  const uint8_t* Virtual(uint32_t addr, uint32_t size) const override { return cap_.Virtual(addr, size); }

 private:
  const Capture& cap_;
};

// One reference resolve dump (capture resolve_ref/<phys>.bin) as guest memory.
class BlobMemory : public native::GuestMemory {
 public:
  BlobMemory(uint32_t base, std::vector<uint8_t> data) : base_(base), data_(std::move(data)) {}
  const uint8_t* Physical(uint32_t addr, uint32_t size) const override {
    if (addr < base_ || uint64_t(addr - base_) + size > data_.size()) return nullptr;
    return data_.data() + (addr - base_);
  }
  const uint8_t* Virtual(uint32_t addr, uint32_t size) const override {
    return addr >= 0xA0000000 ? Physical(VirtualToPhysical(addr), size) : nullptr;
  }

 private:
  uint32_t base_;
  std::vector<uint8_t> data_;
};

// Guest physical memory image built from the capture's command-processor resolve readbacks.
class RefMemory : public native::GuestMemory {
 public:
  RefMemory() : data_(size_t(0x20000000)) {}
  void Write(uint32_t addr, const std::vector<uint8_t>& bytes) {
    if (uint64_t(addr) + bytes.size() <= data_.size()) std::memcpy(data_.data() + addr, bytes.data(), bytes.size());
  }
  const uint8_t* Physical(uint32_t addr, uint32_t size) const override {
    return uint64_t(addr) + size <= data_.size() ? data_.data() + addr : nullptr;
  }
  const uint8_t* Virtual(uint32_t addr, uint32_t size) const override {
    return addr >= 0xA0000000 ? Physical(VirtualToPhysical(addr), size) : nullptr;
  }

 private:
  std::vector<uint8_t> data_;
};

// The captured frame's resolves as the emulated GPU produced them (capture resolve_seq/), in order.
struct ResolveRef {
  uint32_t address = 0;
  std::string file;
  bool used = false;
};
std::vector<ResolveRef> LoadResolveSequence(const std::filesystem::path& capture_dir, size_t expected) {
  std::vector<ResolveRef> out;
  auto dir = capture_dir / "resolve_seq";
  FILE* f = std::fopen((dir / "index.txt").string().c_str(), "r");
  if (!f) return out;
  unsigned long long cpu_swap = 0;
  if (std::fscanf(f, "capture_cpu_swap %llu", &cpu_swap) != 1) {
    std::fclose(f);
    return out;
  }
  std::map<unsigned long long, std::vector<ResolveRef>> by_swap;
  unsigned long long n, cp;
  unsigned addr;
  size_t bytes;
  while (std::fscanf(f, "%llu %llu %x %zu", &n, &cp, &addr, &bytes) == 4)
    by_swap[cp].push_back({addr, (dir / (std::to_string(n) + ".bin")).string(), false});
  std::fclose(f);
  // The frame after command-processor swap `cpu_swap`; fall back to a neighbour whose resolve
  // count matches the capture's if the swap counters are offset.
  for (long long d : {0ll, 1ll, -1ll, 2ll}) {
    auto it = by_swap.find(cpu_swap + d);
    if (it == by_swap.end()) continue;
    if (d == 0 || it->second.size() == expected) {
      std::printf("resolve references: command-processor frame %llu (%zu resolves, capture has %zu)\n",
                  cpu_swap + d, it->second.size(), expected);
      return it->second;
    }
  }
  return out;
}

float BEF(const uint8_t* p) {
  uint32_t v = BE32(p);
  float f;
  std::memcpy(&f, &v, 4);
  return f;
}

}  // namespace

int main(int argc, char** argv) {
  if (argc < 2) {
    std::fprintf(stderr, "usage: Fable2Replay <capture dir> [--out <dir>] [--no-rect2d] [--debug-layer]\n");
    return 1;
  }
  std::filesystem::path out_dir = std::filesystem::path(argv[1]) / "replay";
  int pass_count = 2;
  bool rect2d = true, debug_layer = false, warmup = true, memory_shaders = false, raw_dump = false;
  bool sample_cpu = false;  // --sample: sampling profile of the steady-state passes
  ReplaySampler sampler;
  uint32_t limit = UINT32_MAX, skip_prim = UINT32_MAX, only_draw = 0;
  bool no_up = false, no_resolve = false, no_clear = false;
  uint32_t stop_seq = UINT32_MAX, skip_seq = UINT32_MAX;
  for (int i = 2; i < argc; ++i) {
    if (!std::strcmp(argv[i], "--out") && i + 1 < argc) out_dir = argv[++i];
    if (!std::strcmp(argv[i], "--no-rect2d")) rect2d = false;
    if (!std::strcmp(argv[i], "--skip-seq") && i + 1 < argc) skip_seq = uint32_t(std::stoul(argv[++i]));
    if (!std::strcmp(argv[i], "--no-warmup")) warmup = false;
    if (!std::strcmp(argv[i], "--passes") && i + 1 < argc) pass_count = std::stoi(argv[++i]);
    if (!std::strcmp(argv[i], "--memory-shaders")) memory_shaders = true;
    if (!std::strcmp(argv[i], "--raw")) raw_dump = true;
    if (!std::strcmp(argv[i], "--sample")) sample_cpu = true;
    if (!std::strcmp(argv[i], "--debug-layer")) debug_layer = true;
    if (!std::strcmp(argv[i], "--no-up")) no_up = true;
    if (!std::strcmp(argv[i], "--stop-seq") && i + 1 < argc) stop_seq = uint32_t(std::stoul(argv[++i]));
    if (!std::strcmp(argv[i], "--no-resolve")) no_resolve = true;
    if (!std::strcmp(argv[i], "--no-clear")) no_clear = true;
    if (!std::strcmp(argv[i], "--skip-draw") && i + 1 < argc) only_draw = uint32_t(std::stoul(argv[++i]));
    if (!std::strcmp(argv[i], "--limit") && i + 1 < argc) limit = uint32_t(std::stoul(argv[++i]));
    if (!std::strcmp(argv[i], "--skip-prim") && i + 1 < argc) skip_prim = uint32_t(std::stoul(argv[++i], nullptr, 0));
  }
  std::filesystem::create_directories(out_dir);
  setvbuf(stdout, nullptr, _IONBF, 0);

  auto t0 = std::chrono::steady_clock::now();
  Capture cap;
  std::string err;
  if (!cap.Load(argv[1], &err)) {
    std::fprintf(stderr, "load failed: %s\n", err.c_str());
    return 1;
  }
  std::printf("%zu events, device %08X\n", cap.events().size(), cap.device_address());

  {
    // DRED: breadcrumbs + page fault info if the device is removed.
    ComPtr<ID3D12DeviceRemovedExtendedDataSettings> dred;
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&dred)))) {
      dred->SetAutoBreadcrumbsEnablement(D3D12_DRED_ENABLEMENT_FORCED_ON);
      dred->SetPageFaultEnablement(D3D12_DRED_ENABLEMENT_FORCED_ON);
    }
  }
  if (debug_layer) {
    ComPtr<ID3D12Debug> dbg;
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&dbg)))) dbg->EnableDebugLayer();
  }
  ComPtr<ID3D12Device> device;
  if (FAILED(D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device)))) {
    std::fprintf(stderr, "D3D12CreateDevice failed\n");
    return 1;
  }
  D3D12_COMMAND_QUEUE_DESC qd{D3D12_COMMAND_LIST_TYPE_DIRECT};
  ComPtr<ID3D12CommandQueue> queue;
  device->CreateCommandQueue(&qd, IID_PPV_ARGS(&queue));

  native::Renderer renderer;
  if (!renderer.Initialize(device.Get(), queue.Get())) {
    std::fprintf(stderr, "renderer init failed\n");
    return 1;
  }
  uint32_t dump_seq = UINT32_MAX;
  for (int i = 2; i < argc; ++i) {
    if (!std::strcmp(argv[i], "--no-depth")) renderer.debug_no_depth = true;
    if (!std::strcmp(argv[i], "--trace")) renderer.debug_trace = true;
    if (!std::strcmp(argv[i], "--profile")) native::Renderer::EnableDrawProfile(true);
    if (!std::strcmp(argv[i], "--prev-depth-shadows")) renderer.realtime_depth_passes = false;
    if (!std::strcmp(argv[i], "--nodepth-seq") && i + 1 < argc) renderer.debug_nodepth_seq = uint32_t(std::stoul(argv[++i]));
    if (!std::strcmp(argv[i], "--ps-patch") && i + 1 < argc) {
      // --ps-patch HASH,INSTR,REG (hash hex as in --dump-shaders file names)
      unsigned long long hsh = 0;
      unsigned instr = 0, reg = 0;
      if (std::sscanf(argv[++i], "%llx,%u,%u", &hsh, &instr, &reg) == 3) {
        renderer.debug_ps_patch_hash = hsh;
        renderer.debug_ps_patch_instr = instr;
        renderer.debug_ps_patch_reg = reg;
      }
    }
    if (!std::strcmp(argv[i], "--probe") && i + 1 < argc) {
      // --probe SURFACE,X,Y (hex surface address)
      unsigned surf = 0;
      int px = -1, py = -1;
      if (std::sscanf(argv[++i], "%x,%d,%d", &surf, &px, &py) == 3) {
        renderer.debug_probe_surface = surf;
        renderer.debug_probe_x = px;
        renderer.debug_probe_y = py;
      }
    }
    if (!std::strcmp(argv[i], "--dump-shaders")) {
      std::filesystem::create_directories(out_dir / "shaders");
      renderer.debug_shader_dir = (out_dir / "shaders").string();
    }
    if (!std::strcmp(argv[i], "--no-cull")) renderer.debug_no_cull = true;
    if (!std::strcmp(argv[i], "--no-msaa")) renderer.debug_no_msaa = true;
    if (!std::strcmp(argv[i], "--no-alpha-test")) renderer.debug_no_alpha_test = true;
    if (!std::strcmp(argv[i], "--no-clip")) renderer.debug_no_clip = true;
    if (!std::strcmp(argv[i], "--dump-all")) renderer.debug_dump_all_path = (out_dir / "all_draw_regs.bin").string();
    if (!std::strcmp(argv[i], "--dump-seq") && i + 1 < argc) {
      dump_seq = uint32_t(std::stoul(argv[++i]));
      renderer.debug_dump_path = (out_dir / "draw_regs.bin").string();
    }
  }
  // --patch ADDR=VALUE: overwrite a big-endian guest physical dword before replaying (debugging, e.g.
  // replacing a shader instruction to export an intermediate value).
  for (int i = 2; i + 1 < argc; ++i) {
    if (std::strcmp(argv[i], "--patch")) continue;
    std::string arg = argv[i + 1];
    size_t eq = arg.find('=');
    if (eq == std::string::npos) continue;
    uint32_t addr = uint32_t(std::stoul(arg.substr(0, eq), nullptr, 16));
    uint32_t value = uint32_t(std::stoul(arg.substr(eq + 1), nullptr, 16));
    if (uint8_t* p = const_cast<uint8_t*>(cap.Physical(addr, 4))) {
      p[0] = uint8_t(value >> 24), p[1] = uint8_t(value >> 16), p[2] = uint8_t(value >> 8), p[3] = uint8_t(value);
      std::printf("patched %08X = %08X\n", addr, value);
    }
  }
  CaptureMemory mem(cap);
  // Guest physical memory as of the frame start.
  renderer.BeginFrame();
  renderer.UploadPhysical(0, cap.Physical(0, 0x20000000), 0x20000000);

  native::ShaderState shaders;
  // Begin*Vertices draws run once their data arrives (the next event's UP blobs).
  bool pending_up = false;
  native::DrawArgs up_args;
  std::vector<uint8_t> up_device;
  uint32_t up_seq = 0;
  uint32_t swap_front = 0;

  auto upload_blobs = [&](const Event& e) {
    for (const Blob& b : e.blobs) {
      if (b.kind == kBlobPhysical) {
        renderer.UploadPhysical(b.addr, b.data.data(), uint32_t(b.data.size()));
      } else if ((b.kind == kBlobUpData || b.kind == kBlobVirtual) && b.addr >= 0xA0000000) {
        renderer.UploadPhysical(Capture::VirtualToPhysical(b.addr), b.data.data(), uint32_t(b.data.size()));
      }
    }
  };

  // Constant loads the game wrote directly into the command buffer between hooked calls
  // (GpuLoadShaderConstantF4, not hooked in this capture version): replay them in order.
  uint32_t bin_mask = 0xFFFFFFFFu;  // current SET_BIN_MASK_LO (see scan_predication)
  struct {
    bool valid = false;
    uint32_t reg = 0, count = 0;
  } tile0_load;  // last per-tile constant load for tile 0 (see kGpuLoadConstants)
  auto apply_gap_constants = [&](const Event& e, uint32_t kind, bool fetch_only = false) {
    for (const Blob& b : e.blobs) {
      if (b.kind != kind) continue;
      uint32_t local_mask = bin_mask;
      const uint8_t* p = b.data.data();
      size_t n = b.data.size() / 4;
      for (size_t i = 0; i < n;) {
        uint32_t h = BE32(p + i * 4), type = h >> 30;
        if (type == 0) {
          // Register writes; fetch constants the game writes directly bypass the device shadow.
          uint32_t cnt = ((h >> 16) & 0x3FFF) + 1, base = h & 0x7FFF;
          bool one_reg = (h >> 15) & 1;
          for (uint32_t k = 0; k < cnt && i + 1 + k < n; ++k) {
            uint32_t r = one_reg ? base : base + k;
            if (r >= 0x4800 && r < 0x48C0) {
              uint32_t v = BE32(p + (i + 1 + k) * 4);
              renderer.WriteFetchConstants(r, &v, 1, cap.device());
            }
          }
          i += 1 + cnt;
          continue;
        }
        if (type != 3) {
          ++i;
          continue;
        }
        uint32_t count = ((h >> 16) & 0x3FFF) + 1, op = (h >> 8) & 0x7F;
        if (op == 0x60 && i + 1 < n) local_mask = BE32(p + (i + 1) * 4);
        if (!fetch_only && (h & 1) && (op == 0x2F || op == 0x2D) && i + 1 < n) {
          // Predicated constant load: keep tile 0's value of a per-tile pair (see kGpuLoadConstants).
          uint32_t ot = BE32(p + (i + (op == 0x2F ? 2 : 1)) * 4);
          uint32_t key_reg = ot & 0xFFFFFF, key_count = op == 0x2F ? (i + 3 < n ? BE32(p + (i + 3) * 4) & 0xFFF : 0) : count;
          if (local_mask & 3u) {
            tile0_load = {true, key_reg | 0x80000000u, key_count};
          } else if (tile0_load.valid && tile0_load.reg == (key_reg | 0x80000000u) && tile0_load.count == key_count) {
            i += 1 + count;
            continue;
          }
        }
        auto base_for = [](uint32_t offset_type) -> uint32_t {
          uint32_t index = offset_type & 0x7FF, t = (offset_type >> 16) & 0xFF;
          return t == 0 ? 0x4000 + index : t == 2 ? 0x4900 + index : t == 3 ? 0x4908 + index : 0;
        };
        if (op == 0x2D && i + 1 < n && count >= 2 && ((BE32(p + (i + 1) * 4) >> 16) & 0xFF) == 1) {
          // SET_CONSTANT into fetch constants.
          uint32_t reg = 0x4800 + (BE32(p + (i + 1) * 4) & 0x7FF);
          if (i + 1 + count <= n) {
            std::vector<uint32_t> v(count - 1);
            for (uint32_t k = 0; k + 1 < count; ++k) v[k] = BE32(p + (i + 2 + k) * 4);
            renderer.WriteFetchConstants(reg, v.data(), count - 1, cap.device());
          }
        } else if (fetch_only) {
        } else if (op == 0x2F && i + 3 < n) {  // LOAD_ALU_CONSTANT
          uint32_t addr = BE32(p + (i + 1) * 4) & 0x3FFFFFFF, reg = base_for(BE32(p + (i + 2) * 4));
          uint32_t dwords = BE32(p + (i + 3) * 4) & 0xFFF;
          const uint8_t* src = cap.Physical(addr, dwords * 4);
          if (reg && src) {
            std::vector<uint32_t> v(dwords);
            for (uint32_t k = 0; k < dwords; ++k) v[k] = BE32(src + k * 4);
            renderer.WriteConstants(reg, v.data(), dwords);
          }
        } else if (op == 0x2D && i + 1 < n && count >= 2) {  // SET_CONSTANT
          uint32_t reg = base_for(BE32(p + (i + 1) * 4));
          if (reg && i + 1 + count <= n) {
            std::vector<uint32_t> v(count - 1);
            for (uint32_t k = 0; k + 1 < count; ++k) v[k] = BE32(p + (i + 2 + k) * 4);
            renderer.WriteConstants(reg, v.data(), count - 1);
          }
        }
        i += 1 + count;
      }
    }
  };

  // The game samples some resolve results a frame later (e.g. the shadow-mask pass reads the
  // previous frame's scene depth). The capture's memory never contains resolve output (the emulated
  // GPU keeps it in its own copy), so a warm-up pass replays the frame once to produce those
  // textures and the second pass is the one written out.
  size_t capture_resolves = 0;
  for (const Event& ev : cap.events())
    if (ev.phase == 0 && ev.fn == d3dhooks::kResolve && ev.r[3]) ++capture_resolves;
  std::vector<ResolveRef> resolve_refs = LoadResolveSequence(argv[1], capture_resolves);
  std::unique_ptr<RefMemory> ref_mem;
  if (!resolve_refs.empty()) ref_mem = std::make_unique<RefMemory>();
  size_t resolve_index = 0;
  const int passes = warmup ? std::max(2, pass_count) : 1;
  const bool trace = renderer.debug_trace;
  const std::string dump_all_path = renderer.debug_dump_all_path, shader_dir = renderer.debug_shader_dir;
  const uint32_t final_dump_seq = dump_seq;
  // Per-pass wall time (pass 0 also translates shaders and creates pipelines; later passes are
  // the steady-state cost of rendering this frame; each pass ends with EndFrame, which waits for the GPU).
  auto pass_t = std::chrono::steady_clock::now();
  std::vector<double> pass_ms, endframe_ms;  // endframe: submit + wait for the GPU
  auto end_pass = [&] {
    auto now = std::chrono::steady_clock::now();
    pass_ms.push_back(std::chrono::duration<double, std::milli>(now - pass_t).count());
    std::printf("pass %zu: %.2f ms (of which EndFrame submit+GPU wait %.2f ms)\n", pass_ms.size() - 1, pass_ms.back(),
                endframe_ms.empty() ? 0.0 : endframe_ms.back());
    pass_t = std::chrono::steady_clock::now();
  };
  for (int pass = 0; pass < passes; ++pass) {
  if (pass) end_pass();
  if (pass == 2) {
    renderer.DrawProfile(true);  // steady-state sections only (passes 2..)
    if (sample_cpu) {
      HANDLE self = nullptr;
      DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &self, 0, FALSE,
                      DUPLICATE_SAME_ACCESS);
      sampler.Start(self);
      sampler.Resume();
    }
  }
  const bool final_pass = pass + 1 == passes;
  renderer.debug_trace = trace && final_pass;
  renderer.debug_dump_all_path = final_pass ? dump_all_path : std::string();
  renderer.debug_shader_dir = final_pass ? shader_dir : std::string();
  dump_seq = final_pass ? final_dump_seq : ~0u;
  if (final_pass) renderer.ResetStats();
  pending_up = false;
  // Shader microcode the GPU would run: the last IM_LOAD (from memory) / IM_LOAD_IMMEDIATE (inline,
  // e.g. D3D's per-draw patched vertex shaders) of each type, in command order.
  struct LoadedShaders {
    std::vector<uint32_t> vs, ps;  // big-endian dwords
  } loaded;
  auto apply_loads = [&](const Event& ev, uint32_t kind, LoadedShaders& out) {
    for (const Blob& b : ev.blobs) {
      if (b.kind != kind) continue;
      const uint8_t* p = b.data.data();
      size_t n = b.data.size() / 4;
      for (size_t i = 0; i < n;) {
        uint32_t h = BE32(p + i * 4), type = h >> 30;
        if (type == 0) {
          i += 2 + ((h >> 16) & 0x3FFF);
          continue;
        }
        if (type != 3) {
          ++i;
          continue;
        }
        uint32_t count = ((h >> 16) & 0x3FFF) + 1, op = (h >> 8) & 0x7F;
        if (op == 0x27 && i + 2 < n) {  // IM_LOAD: address | shader type, start << 16 | size
          uint32_t w1 = BE32(p + (i + 1) * 4), w2 = BE32(p + (i + 2) * 4);
          uint32_t dwords = w2 & 0xFFFF;
          if (const uint8_t* src = cap.Physical(w1 & ~3u, dwords * 4)) {
            auto& dst = (w1 & 3) == 0 ? out.vs : out.ps;
            dst.assign(reinterpret_cast<const uint32_t*>(src), reinterpret_cast<const uint32_t*>(src) + dwords);
          }
        } else if (op == 0x2B && i + 2 < n) {  // IM_LOAD_IMMEDIATE: shader type, start << 16 | size, code
          uint32_t w1 = BE32(p + (i + 1) * 4), w2 = BE32(p + (i + 2) * 4);
          uint32_t dwords = std::min<uint32_t>(w2 & 0xFFFF, uint32_t(n - (i + 3)));
          auto& dst = (w1 & 3) == 0 ? out.vs : out.ps;
          const uint32_t* src = reinterpret_cast<const uint32_t*>(p + (i + 3) * 4);
          dst.assign(src, src + dwords);
        }
        i += 1 + count;
      }
    }
  };
  // Predicated tiling: the console renders the scene in screen tiles and D3D predicates per-tile
  // packets with a bin mask (SET_BIN_MASK_LO, op 0x60; two bits per tile, tile 0 = bits 0-1). The
  // native renderer draws the whole frame at once with no window offset, which is tile 0's view:
  // per-tile state (e.g. screen-position constants offset by the tile origin) must take tile 0's value.
  // Scans command bytes, updating bin_mask; returns true if a predicated LOAD_ALU_CONSTANT /
  // SET_CONSTANT in them is excluded from tile 0.
  // Returns 0 if there is no predicated constant load, 1 if one applies to tile 0, 2 if one only
  // applies to other tiles.
  auto scan_predication = [&](const Event& ev, uint32_t kind) {
    int status = 0;
    for (const Blob& b : ev.blobs) {
      if (b.kind != kind) continue;
      const uint8_t* p = b.data.data();
      size_t n = b.data.size() / 4;
      for (size_t i = 0; i < n;) {
        uint32_t h = BE32(p + i * 4), type = h >> 30;
        if (type == 0) {
          i += 2 + ((h >> 16) & 0x3FFF);
          continue;
        }
        if (type != 3) {
          ++i;
          continue;
        }
        uint32_t count = ((h >> 16) & 0x3FFF) + 1, op = (h >> 8) & 0x7F;
        if (op == 0x60 && i + 1 < n) bin_mask = BE32(p + (i + 1) * 4);
        if ((op == 0x2F || op == 0x2D) && (h & 1)) status = (bin_mask & 3u) ? 1 : 2;
        i += 1 + count;
      }
    }
    return status;
  };
  // The shaders of the draw issued by call event `ev` (phase 0): the loads so far plus the ones the
  // call itself emits (its after event's command bytes).
  LoadedShaders draw_shaders, up_shaders;
  auto shaders_for_call = [&](const Event& ev) {
    draw_shaders = loaded;
    const Event* next = &ev + 1;
    if (next < cap.events().data() + cap.events().size() && next->phase == 1) {
      apply_loads(*next, kBlobCommands, draw_shaders);
      // The draw call writes its vertex stream fetch constants itself (from the device's stream
      // sources, not the fetch shadow) before the draw packet.
      apply_gap_constants(*next, kBlobCommands, true);
      // Buffers referenced by the call's own packets (recorded after it returned; the CPU wrote them
      // before the call): needed by this draw.
      for (const Blob& b : next->blobs)
        if (b.kind == kBlobPhysical) renderer.UploadPhysical(b.addr, b.data.data(), uint32_t(b.data.size()));
    }
  };
  auto attach = [&](native::DrawArgs& a, const LoadedShaders& l) {
    if (memory_shaders) return;
    if (!l.vs.empty()) a.vs_ucode = l.vs.data(), a.vs_ucode_dwords = uint32_t(l.vs.size());
    if (!l.ps.empty()) a.ps_ucode = l.ps.data(), a.ps_ucode_dwords = uint32_t(l.ps.size());
  };

  uint32_t draw_calls = 0;
  bool constants_initialized = false;
  for (const Event& e : cap.events()) {
    if (draw_calls >= limit || e.seq >= stop_seq) break;
    cap.Apply(e);
    if (!constants_initialized) {
      renderer.InitConstants(cap.device());
      constants_initialized = true;
    }
    if (e.phase == 0) apply_gap_constants(e, kBlobGapCommands);
    apply_loads(e, e.phase == 0 ? kBlobGapCommands : kBlobCommands, loaded);
    int load_predication = 0;
    if (e.phase == 0) {
      scan_predication(e, kBlobGapCommands);
      // The call's own packets (after event): does its constant load belong to another tile?
      const Event* next = &e + 1;
      if (next < cap.events().data() + cap.events().size() && next->phase == 1) {
        uint32_t saved = bin_mask;
        load_predication = scan_predication(*next, kBlobCommands);
        bin_mask = saved;
      }
    } else {
      scan_predication(e, kBlobCommands);
    }
    if (e.phase == 0 && e.fn <= d3dhooks::kDrawIndexed2) shaders_for_call(e);
    // The flow-constant block GpuLoadShaders reads is game memory changed during the frame (only its
    // frame-start contents are in this capture): take the bool/loop values from the call's own output.
    if (e.phase == 1) apply_gap_constants(e, kBlobCommands, e.fn != d3dhooks::kGpuLoadShaders);
    if (e.phase == 0 && (e.fn <= d3dhooks::kDrawIndexed2)) {
      tile0_load.valid = false;
      ++draw_calls;
      if (e.r[1] == skip_prim || draw_calls == only_draw || e.seq == skip_seq) continue;
    }
    upload_blobs(e);
    if (e.phase != 0) continue;
    if (e.seq == dump_seq) renderer.debug_dump_draw = renderer.stats().draws + 1;
    if (pending_up) {
      // The UP data blobs of this event: vertex data first, then indices.
      std::vector<const Blob*> up;
      for (const Blob& b : e.blobs)
        if (b.kind == kBlobUpData) up.push_back(&b);
      if (!up.empty()) {
        up_args.up_vertex_physical = Capture::VirtualToPhysical(up[0]->addr);
        up_args.up_vertex_bytes = uint32_t(up[0]->data.size());
        if (up_args.kind == native::DrawArgs::kIndexed && up.size() > 1)
          up_args.index_physical = Capture::VirtualToPhysical(up[1]->addr);
        renderer.debug_seq = up_seq;
        attach(up_args, up_shaders);
        if (!no_up && (up_args.kind == native::DrawArgs::kAuto || up_args.index_physical))
          renderer.Draw(mem, up_device.data(), shaders, up_args);
      }
      pending_up = false;
    }
    const uint32_t* r = e.r;  // r3..r10
    renderer.debug_seq = e.seq;
    switch (e.fn) {
      case d3dhooks::kGpuLoadShaders:
        shaders.vertex_shader = r[1];
        shaders.pixel_shader = r[2];
        renderer.LoadShaders(mem, r[1], r[2], r[3]);
        break;
      case d3dhooks::kDrawIndexed: {
        native::DrawArgs a;
        a.kind = native::DrawArgs::kIndexed;
        a.prim = r[1];
        a.base_vertex = r[2];
        a.start = r[3];
        a.count = r[4];
        attach(a, draw_shaders);
        renderer.Draw(mem, cap.device(), shaders, a);
        break;
      }
      case d3dhooks::kDrawIndexed2: {
        // D3DDevice_DrawIndexedTessellatedPrimitive(dev, prim, ?, start index, patch count)
        native::DrawArgs a;
        a.kind = native::DrawArgs::kIndexed;
        a.tessellated = true;
        a.prim = r[1];
        a.start = r[3];
        a.count = r[4];
        attach(a, draw_shaders);
        renderer.Draw(mem, cap.device(), shaders, a);
        break;
      }
      case d3dhooks::kDraw: {
        native::DrawArgs a;
        a.kind = native::DrawArgs::kAuto;
        a.prim = r[1];
        a.base_vertex = r[2];  // D3DDevice_DrawVertices writes the start vertex to VGT_INDX_OFFSET
        a.start = 0;
        a.count = r[3];
        attach(a, draw_shaders);
        renderer.Draw(mem, cap.device(), shaders, a);
        break;
      }
      case d3dhooks::kDrawRect2D: {
        // D3DDevice_DrawTessellatedPrimitive(dev, prim, start, count): auto-indexed patches.
        if (!rect2d) break;
        native::DrawArgs a;
        a.kind = native::DrawArgs::kAuto;
        a.tessellated = true;
        a.prim = r[1];
        a.base_vertex = r[2];
        a.count = r[3];
        attach(a, draw_shaders);
        renderer.Draw(mem, cap.device(), shaders, a);
        break;
      }
      case d3dhooks::kBeginIndexedUP:
      case d3dhooks::kBeginUP: {
        up_args = native::DrawArgs{};
        up_args.prim = r[1];
        up_args.up_vertex_fetch = true;
        if (e.fn == d3dhooks::kBeginIndexedUP) {
          up_args.kind = native::DrawArgs::kIndexed;
          up_args.base_vertex = r[2];
          up_args.count = r[4];
          up_args.index_32bit = (r[5] & 4) != 0;
        } else {
          up_args.kind = native::DrawArgs::kAuto;
          up_args.count = r[2];
        }
        up_device.assign(cap.device(), cap.device() + Capture::kDeviceSize);
        up_shaders = draw_shaders;
        up_seq = e.seq;
        pending_up = true;
        break;
      }
      case d3dhooks::kClear: {
        native::ClearArgs a;
        a.flags = r[1];
        if (const uint8_t* rect = r[2] ? cap.Virtual(r[2], 16) : nullptr) {
          a.has_rect = true;
          a.x1 = int32_t(BE32(rect));
          a.y1 = int32_t(BE32(rect + 4));
          a.x2 = int32_t(BE32(rect + 8));
          a.y2 = int32_t(BE32(rect + 12));
        }
        if (const uint8_t* c = r[3] ? cap.Virtual(r[3], 16) : nullptr)
          for (int i = 0; i < 4; ++i) a.color[i] = BEF(c + i * 4);
        a.z = float(e.f1);
        a.stencil = r[5];
        if (!no_clear) renderer.Clear(mem, cap.device(), a);
        break;
      }
      case d3dhooks::kResolve: {
        native::ResolveArgs a;
        a.flags = r[1];
        if (const uint8_t* rect = r[2] ? cap.Virtual(r[2], 16) : nullptr) {
          a.has_source_rect = true;
          a.src_x1 = int32_t(BE32(rect));
          a.src_y1 = int32_t(BE32(rect + 4));
          a.src_x2 = int32_t(BE32(rect + 8));
          a.src_y2 = int32_t(BE32(rect + 12));
        }
        a.dest_texture = r[3];
        if (const uint8_t* pt = r[4] ? cap.Virtual(r[4], 8) : nullptr) {
          a.dest_x = int32_t(BE32(pt));
          a.dest_y = int32_t(BE32(pt + 4));
        }
        a.dest_level = r[5];
        if (const uint8_t* c = r[7] ? cap.Virtual(r[7], 16) : nullptr)
          for (int i = 0; i < 4; ++i) a.clear_color[i] = BEF(c + i * 4);
        a.clear_z = float(e.f1);
        if (const uint8_t* s = cap.Virtual(e.sp + 84, 4)) a.clear_stencil = BE32(s);
        {
          const Event* next = &e + 1;
          if (next < cap.events().data() + cap.events().size() && next->phase == 1)
            for (const Blob& b : next->blobs)
              if (b.kind == kBlobCommands)
                a.copy_dest_info = native::FindRegisterWrite(b.data.data(), b.data.size(), 0x231B, a.copy_dest_info);
        }
        if (!no_resolve) renderer.Resolve(mem, cap.device(), a);
        if (final_pass && ref_mem && a.dest_texture && resolve_index < resolve_refs.size()) {
          // Pair by destination: the command processor may execute tiled (predicated) resolves in a
          // different order than the calls. Take the next unused reference whose written range
          // starts at this destination.
          uint32_t want_base = 0;
          if (const uint8_t* fp0 = cap.Virtual(a.dest_texture + 28, 24)) {
            want_base = (BE32(fp0 + 4) >> 12) << 12;
            if (want_base >= 0xA0000000) want_base = Capture::VirtualToPhysical(want_base);
          }
          size_t pick = resolve_refs.size();
          for (size_t k = 0; k < resolve_refs.size(); ++k)
            if (!resolve_refs[k].used && resolve_refs[k].address == want_base) {
              pick = k;
              break;
            }
          if (pick == resolve_refs.size()) pick = std::min(resolve_index, resolve_refs.size() - 1);
          ++resolve_index;
          resolve_refs[pick].used = true;
          const ResolveRef& ref = resolve_refs[pick];
          std::vector<uint8_t> bytes;
          if (FILE* bf = std::fopen(ref.file.c_str(), "rb")) {
            std::fseek(bf, 0, SEEK_END);
            bytes.resize(size_t(std::ftell(bf)));
            std::fseek(bf, 0, SEEK_SET);
            bytes.resize(std::fread(bytes.data(), 1, bytes.size(), bf));
            std::fclose(bf);
          }
          ref_mem->Write(ref.address, bytes);
          uint32_t f[6] = {};
          if (const uint8_t* fp = cap.Virtual(a.dest_texture + 28, 24))
            for (int i = 0; i < 6; ++i) f[i] = BE32(fp + i * 4);
          uint32_t base = (f[1] >> 12) << 12;
          if (base >= 0xA0000000) base = Capture::VirtualToPhysical(base);
          f[1] = (f[1] & 0xFFFu) | base;
          if (f[5] >> 12) f[5] = (f[5] & 0xFFFu) | native::GuestMemory::VirtualToPhysical(f[5] & ~0xFFFu);
          std::vector<uint8_t> want, got;
          uint32_t ww = 0, wh = 0, gw = 0, gh = 0;
          double mae = -1;
          std::vector<float> want_raw;
          bool ok_ref = renderer.DecodeReference(*ref_mem, f, &want, &ww, &wh, &want_raw);
          if (ok_ref && std::getenv("NATIVE_CMP_ALL")) {
            // Raw reference values (RGBA float) and the replay's, for numeric checks.
            std::vector<uint8_t> tmp;
            std::vector<float> got_raw;
            uint32_t rw = 0, rh = 0;
            if (auto* r2 = renderer.GetResolvedTexture(base)) renderer.ReadbackRGBA8(r2, &tmp, &rw, &rh, &got_raw);
            char nm[96];
            std::snprintf(nm, sizeof(nm), "raw_%02zu_%08X_%ux%u_ref.f32", resolve_index - 1, base, ww, wh);
            if (FILE* rf = std::fopen((out_dir / nm).string().c_str(), "wb")) {
              std::fwrite(want_raw.data(), 4, want_raw.size(), rf);
              std::fclose(rf);
            }
            std::snprintf(nm, sizeof(nm), "raw_%02zu_%08X_%ux%u_ours.f32", resolve_index - 1, base, rw, rh);
            if (FILE* rf = std::fopen((out_dir / nm).string().c_str(), "wb")) {
              std::fwrite(got_raw.data(), 4, got_raw.size(), rf);
              std::fclose(rf);
            }
          }
          auto* res = renderer.GetResolvedTexture(base);
          if (ok_ref && res && renderer.ReadbackRGBA8(res, &got, &gw, &gh)) {
            uint64_t sum = 0, cnt = 0;
            for (uint32_t y = 0; y < std::min(wh, gh); ++y)
              for (uint32_t x = 0; x < std::min(ww, gw); ++x)
                for (uint32_t c = 0; c < 3; ++c, ++cnt)
                  sum += uint64_t(std::abs(int(want[(size_t(y) * ww + x) * 4 + c]) - int(got[(size_t(y) * gw + x) * 4 + c])));
            mae = cnt ? double(sum) / double(cnt) : -1;
            if (mae > (std::getenv("NATIVE_CMP_ALL") ? -1.0 : 2.0)) {
              // Side by side: reference (left) and replay (right).
              uint32_t h = std::min(wh, gh), w = ww + gw;
              std::vector<uint8_t> pair(size_t(w) * h * 4);
              for (uint32_t y = 0; y < h; ++y) {
                std::memcpy(&pair[size_t(y) * w * 4], &want[size_t(y) * ww * 4], size_t(ww) * 4);
                std::memcpy(&pair[(size_t(y) * w + ww) * 4], &got[size_t(y) * gw * 4], size_t(gw) * 4);
              }
              for (size_t i = 3; i < pair.size(); i += 4) pair[i] = 255;
              char name[64];
              std::snprintf(name, sizeof(name), "cmp_%02zu_seq%u_%08X.png", resolve_index - 1, e.seq, base);
              native::WritePng((out_dir / name).string(), pair.data(), w, h);
            }
          }
          std::printf("resolve #%zu seq %u -> %08X fmt %u %ux%u (ref written %08X+%zu): mean abs diff %.2f%s\n",
                      resolve_index - 1, e.seq, base, f[1] & 0x3F, ww, wh, ref.address, bytes.size(), mae,
                      ok_ref ? "" : " (reference decode failed)");
        }
        break;
      }
      case d3dhooks::kGpuLoadConstants:
      {
        // Per-tile constants come as a pair: a load predicated for tile 0, then the same registers
        // for another tile - the native renderer (tile 0's view) keeps the first. A load predicated
        // only for other tiles without such a pair (an object visible only there) still applies.
        uint32_t reg = (r[1] << 8) + r[2];
        bool skip_load = load_predication == 2 && tile0_load.valid && tile0_load.reg == reg && tile0_load.count == r[3];
        if (!skip_load) renderer.LoadShaderConstantsF4(mem, r[1], r[2], r[3], r[4], r[5]);
        if (load_predication == 1) tile0_load = {true, reg, r[3]};
        else if (load_predication == 0) tile0_load.valid = false;
      }
        break;
      case d3dhooks::kSwap:
        swap_front = r[1];
        break;
      default:
        break;
    }
  }
  if (!final_pass) {
    auto te = std::chrono::steady_clock::now();
    renderer.EndFrame();
    endframe_ms.push_back(std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - te).count());
    renderer.BeginFrame();
  }
  }  // passes
  {
    auto te = std::chrono::steady_clock::now();
    renderer.EndFrame();
    endframe_ms.push_back(std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - te).count());
  }
  end_pass();
  if (HRESULT reason = device->GetDeviceRemovedReason(); FAILED(reason))
  {
    std::printf("DEVICE REMOVED: %08X\n", unsigned(reason));
    ComPtr<ID3D12DeviceRemovedExtendedData> dred;
    if (SUCCEEDED(device.As(&dred))) {
      D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT bc{};
      if (SUCCEEDED(dred->GetAutoBreadcrumbsOutput(&bc))) {
        for (auto* n = bc.pHeadAutoBreadcrumbNode; n; n = n->pNext) {
          uint32_t done = n->pLastBreadcrumbValue ? *n->pLastBreadcrumbValue : 0;
          std::printf("  breadcrumbs: %u of %u ops completed\n", done, n->BreadcrumbCount);
          for (uint32_t i = done > 3 ? done - 3 : 0; i < std::min(n->BreadcrumbCount, done + 4); ++i)
            std::printf("    op %u: %d%s\n", i, int(n->pCommandHistory[i]), i == done ? "  <-- first not completed" : "");
        }
      }
      D3D12_DRED_PAGE_FAULT_OUTPUT pf{};
      if (SUCCEEDED(dred->GetPageFaultAllocationOutput(&pf)))
        std::printf("  page fault VA %llX\n", (unsigned long long)pf.PageFaultVA);
    }
  }
  auto print_debug_messages = [&]() {
    ComPtr<ID3D12InfoQueue> iq;
    if (FAILED(device.As(&iq))) return;
    std::map<std::string, uint32_t> counts;
    for (UINT64 i = 0, n = iq->GetNumStoredMessages(); i < n; ++i) {
      SIZE_T len = 0;
      iq->GetMessage(i, nullptr, &len);
      std::vector<uint8_t> buf(len);
      auto* msg = reinterpret_cast<D3D12_MESSAGE*>(buf.data());
      if (SUCCEEDED(iq->GetMessage(i, msg, &len)) && msg->Severity <= D3D12_MESSAGE_SEVERITY_WARNING)
        ++counts[std::string(msg->pDescription, std::min<size_t>(msg->DescriptionByteLength, 400))];
    }
    iq->ClearStoredMessages();
    for (auto& [text, n] : counts) std::printf("  [d3d12 x%u] %s\n", n, text.c_str());
  };
  if (renderer.debug_probe_x >= 0) {
    std::vector<std::pair<uint32_t, std::array<float, 4>>> probe;
    if (renderer.DebugProbeResults(&probe)) {
      std::array<float, 4> prev{};
      for (auto& [seq, v] : probe) {
        bool changed = v != prev;
        std::printf("probe seq %u: %.4f %.4f %.4f %.4f%s\n", seq, v[0], v[1], v[2], v[3], changed ? "  *" : "");
        prev = v;
      }
    }
  }
  if (sample_cpu) {
    sampler.Pause();
    sampler.Stop();
    sampler.Report();
  }
  if (pass_ms.size() > 2) {
    std::vector<double> steady(pass_ms.begin() + 1, pass_ms.end());
    std::sort(steady.begin(), steady.end());
    std::printf("steady-state pass: median %.2f ms, min %.2f ms over %zu passes\n", steady[steady.size() / 2],
                steady.front(), steady.size());
  }
  if (debug_layer) print_debug_messages();
  auto t1 = std::chrono::steady_clock::now();

  std::printf("draw profile (ms, passes 2..): %s\n", renderer.DrawProfile(false).c_str());
  const auto& st = renderer.stats();
  std::printf("draws %u (skipped %u), clears %u, resolves %u\n", st.draws, st.draws_skipped, st.clears, st.resolves);
  for (auto& [why, n] : st.skip_reasons) std::printf("  skipped: %s x%u\n", why.c_str(), n);
  std::printf("shaders translated %u failed %u, pipelines %u failed %u, textures %u failed %u\n",
              st.shaders_translated, st.shaders_failed, st.pipelines_created, st.pipelines_failed,
              st.textures_created, st.textures_failed);
  std::printf("replay took %lld ms\n",
              (long long)std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count());

  auto dump = [&](ID3D12Resource* res, const std::string& name) {
    std::vector<uint8_t> rgba;
    uint32_t w, h;
    if (renderer.ReadbackRGBA8(res, &rgba, &w, &h)) {
      for (size_t i = 3; i < rgba.size(); i += 4) rgba[i] = 255;  // show colour regardless of alpha
      native::WritePng((out_dir / name).string(), rgba.data(), w, h);
    }
  };
  if (swap_front) {
    if (const uint8_t* f = cap.Virtual(swap_front + 28, 24)) {
      uint32_t base = (BE32(f + 4) >> 12) << 12;
      if (base >= 0xA0000000) base = Capture::VirtualToPhysical(base);
      if (auto* res = renderer.GetResolvedTexture(base)) {
        dump(res, "frontbuffer.png");
        std::printf("front buffer %08X -> %s\n", base, (out_dir / "frontbuffer.png").string().c_str());
      } else {
        std::printf("front buffer %08X was not produced by a resolve\n", base);
      }
    }
  }
  if (debug_layer) print_debug_messages();
  for (auto& [base, res] : renderer.ResolvedTextures()) {
    char name[64];
    std::snprintf(name, sizeof(name), "resolved_%08X.png", base);
    dump(res, name);
    if (raw_dump) {
      // Raw RGBA values (through a 16-bit float copy) for numeric checks.
      std::vector<uint8_t> rgba;
      std::vector<float> raw;
      uint32_t w = 0, h = 0;
      if (renderer.ReadbackRGBA8(res, &rgba, &w, &h, &raw)) {
        std::snprintf(name, sizeof(name), "resolved_%08X_%ux%u.f32", base, w, h);
        if (FILE* f = std::fopen((out_dir / name).string().c_str(), "wb")) {
          std::fwrite(raw.data(), 4, raw.size(), f);
          std::fclose(f);
        }
      }
    }
  }
  // Reference resolve results from the capture (readback of the emulated GPU): decode each and write
  // ref_<base>.png next to the replay's resolved_<base>.png, with the mean absolute difference.
  {
    std::filesystem::path ref_dir = std::filesystem::path(argv[1]) / "resolve_ref";
    if (FILE* idx = std::fopen((ref_dir / "index.txt").string().c_str(), "r")) {
      uint32_t tex, f[6], phys, bytes;
      while (std::fscanf(idx, "%x %x %x %x %x %x %x %x %u", &tex, &f[0], &f[1], &f[2], &f[3], &f[4], &f[5], &phys,
                         &bytes) == 9) {
        char name[64];
        std::snprintf(name, sizeof(name), "%08X.bin", phys);
        std::vector<uint8_t> data(bytes);
        FILE* bf = std::fopen((ref_dir / name).string().c_str(), "rb");
        if (!bf) continue;
        size_t got = std::fread(data.data(), 1, bytes, bf);
        std::fclose(bf);
        data.resize(got);
        BlobMemory bm(phys, std::move(data));
        // The fetch constant is stored with the texture object's virtual base; point it at the dump.
        f[1] = (f[1] & 0xFFFu) | phys;
        if (f[5] >> 12) f[5] = (f[5] & 0xFFFu) | native::GuestMemory::VirtualToPhysical(f[5] & ~0xFFFu);
        std::vector<uint8_t> ref;
        uint32_t w = 0, h = 0;
        if (!renderer.DecodeReference(bm, f, &ref, &w, &h)) {
          std::printf("reference %08X: decode failed (format %u)\n", phys, f[1] & 0x3F);
          continue;
        }
        for (size_t i = 3; i < ref.size(); i += 4) ref[i] = 255;
        std::snprintf(name, sizeof(name), "ref_%08X.png", phys);
        native::WritePng((out_dir / name).string(), ref.data(), w, h);
        double mae = -1;
        if (auto* res = renderer.GetResolvedTexture(phys)) {
          std::vector<uint8_t> mine;
          uint32_t mw = 0, mh = 0;
          if (renderer.ReadbackRGBA8(res, &mine, &mw, &mh)) {
            uint64_t sum = 0, n = 0;
            for (uint32_t y = 0; y < std::min(h, mh); ++y)
              for (uint32_t x = 0; x < std::min(w, mw); ++x)
                for (uint32_t c = 0; c < 3; ++c, ++n)
                  sum += uint64_t(std::abs(int(ref[(size_t(y) * w + x) * 4 + c]) - int(mine[(size_t(y) * mw + x) * 4 + c])));
            mae = n ? double(sum) / double(n) : -1;
          }
        }
        std::printf("reference %08X %ux%u format %u: mean abs diff vs replay %.2f\n", phys, w, h, f[1] & 0x3F, mae);
      }
      std::fclose(idx);
    }
  }
  for (auto& [surface, res] : renderer.RenderTargets()) {
    char name[64];
    std::snprintf(name, sizeof(name), "rt_%08X.png", surface);
    dump(res, name);
    if (raw_dump) {
      std::vector<uint8_t> rgba;
      std::vector<float> raw;
      uint32_t w = 0, h = 0;
      if (renderer.ReadbackRGBA8(res, &rgba, &w, &h, &raw)) {
        std::snprintf(name, sizeof(name), "rt_%08X_%ux%u.f32", surface, w, h);
        if (FILE* f = std::fopen((out_dir / name).string().c_str(), "wb")) {
          std::fwrite(raw.data(), 4, raw.size(), f);
          std::fclose(f);
        }
      }
    }
  }
  return 0;
}
