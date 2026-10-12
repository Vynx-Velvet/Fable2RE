/**
 * @file        src/d3d_capture.cpp
 * @brief       D3D-level frame capture for the native renderer (step 3, milestone 1).
 *
 * F9 (bind_d3d_capture) requests a capture. At the end of the next Swap the capture starts:
 *   captures/<timestamp>/memory.bin + memory_index.txt  all committed guest memory
 *                                                        (virtual 0..0x9FFFFFFF, physical 512 MB)
 *   captures/<timestamp>/events.bin                      one record per hooked D3D call
 *   captures/<timestamp>/summary.txt                     the same, one readable line each
 * and it stops after d3d_capture_frames Swaps. The game keeps running its own D3D code; the
 * capture only reads. Record format (little-endian host):
 *   EventHeader, then blob_count x {BlobHeader, bytes}
 * Blob kinds: 1 device chunk (addr = device offset), 2 guest virtual memory, 3 physical memory,
 *   4 command bytes this call wrote (addr = guest virtual start), 5 UP data (virtual),
 *   6 command bytes written since the previous hooked call (inlined D3D code in the game).
 */
#include "generated/Fable2_init.h"
#include "d3d_hooks.h"

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/ppc.h>
#include <rex/runtime.h>
#include <rex/system/xmemory.h>
#include <rex/filesystem.h>
#include <rex/graphics/command_processor.h>
#include <rex/graphics/graphics_system.h>
#include <rex/ui/presenter.h>

#include "../native/png.h"

#include <windows.h>

#include <algorithm>
#include <atomic>
#include <mutex>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <string>
#include <unordered_set>
#include <thread>
#include <vector>

#include <fmt/format.h>

REXCVAR_DEFINE_INT32(d3d_capture_frames, 1, "Debug", "Frames recorded per D3D frame capture (F9)")
    .range(1, 60);

using namespace d3dhooks;

namespace {

constexpr uint32_t kDeviceSize = 16384;  // device object incl. shadows and bookkeeping (< 15 KB used)
constexpr uint32_t kChunk = 64;

struct EventHeader {
  uint32_t magic;  // 'EVT1'
  uint32_t fn;
  uint32_t phase;  // 0 = before the original ran, 1 = after
  uint32_t seq;
  uint32_t r[8];   // r3..r10
  double f1;
  uint32_t sp;     // caller stack pointer (r1 at entry)
  uint32_t frame;
  uint32_t blob_count;
  uint32_t reserved;
};
struct BlobHeader {
  uint32_t kind;
  uint32_t addr;
  uint32_t size;
  uint32_t reserved;
};
struct Blob {
  uint32_t kind, addr;
  std::vector<uint8_t> data;
};

enum State { kIdle, kRequested, kRecording };
std::atomic<int> g_state{kIdle};
// Frames rendered with readback_resolve=full before recording starts, so the frame-start memory dump
// holds the previous frame's real resolve results (the emulated GPU otherwise keeps them GPU-side).
constexpr int kArmFrames = 3;
int g_arm_frames = 0;
std::string g_readback_before;
std::vector<uint32_t> g_resolve_dests;  // destination texture objects resolved during the capture
// Every guest Swap seen (all frames, not only captured ones): matched against the command processor's
// swap count to find the captured frame's resolves in the command processor's timeline.
std::atomic<uint64_t> g_cpu_swaps{0};
uint64_t g_capture_cpu_swap = 0;
struct ObservedResolve {
  uint64_t cp_swap;
  uint32_t address;
  std::vector<uint8_t> data;
};
std::mutex g_observed_mutex;
std::vector<ObservedResolve> g_observed;
size_t g_observed_bytes = 0;

// Command processor thread: a resolve result just read back into guest memory.
void OnResolveReadback(uint32_t address, const uint8_t* data, uint32_t length, uint64_t cp_swap) {
  std::lock_guard<std::mutex> lock(g_observed_mutex);
  if (g_observed_bytes + length > (768u << 20)) return;
  g_observed.push_back({cp_swap, address, std::vector<uint8_t>(data, data + length)});
  g_observed_bytes += length;
}

struct Capture {
  std::filesystem::path dir;
  FILE* events = nullptr;
  FILE* summary = nullptr;
  uint32_t seq = 0;
  uint32_t frame = 0;
  std::vector<uint8_t> dev_prev;
  std::unordered_set<uint64_t> seen;  // dedupe of captured ranges (addr, size, hash)
  uint32_t put_before = 0;
  uint32_t last_put = 0;  // put pointer after the previous hooked call (0 = unknown)
  bool in_call = false;   // between a recorded call's before and after events
  // Valid (start, end] pieces of command buffer segments left by segment switches (sub_821E8D20)
  // since the current range started; the bytes between segments are not commands.
  std::vector<std::pair<uint32_t, uint32_t>> pieces;
  uint64_t gap_bytes = 0, gap_skipped = 0;
  uint32_t sp_before = 0;
  uint32_t args_before[8] = {};
  // Begin*Vertices data is written by the caller after the call returns: copy it at the next event.
  struct PendingUP {
    uint32_t addr, size;
  };
  std::vector<PendingUP> pending_up;
  uint64_t bytes_events = 0;
  // Time spent per part (microseconds), to find what makes a capture slow.
  uint64_t us_before = 0, us_after = 0, us_streams = 0, us_scan = 0, us_write = 0, us_device = 0;
} g_cap;

struct ScopedUs {
  uint64_t& acc;
  std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
  explicit ScopedUs(uint64_t& a) : acc(a) {}
  ~ScopedUs() {
    acc += uint64_t(
        std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
  }
};

rex::memory::Memory* Mem() {
  auto* rt = rex::Runtime::instance();
  return rt ? rt->memory() : nullptr;
}

uint32_t BE32(const uint8_t* p) {
  return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) | p[3];
}
uint32_t Load32(uint32_t guest) {
  auto* m = Mem();
  return guest ? BE32(m->TranslateVirtual(guest)) : 0;
}

// Word-at-a-time hash (the byte-wise FNV version made a capture take minutes).
uint64_t Hash(const uint8_t* p, size_t n) {
  uint64_t h = 0x9E3779B97F4A7C15ull ^ n;
  size_t i = 0;
  for (; i + 8 <= n; i += 8) {
    uint64_t v;
    std::memcpy(&v, p + i, 8);
    h = (h ^ v) * 0xFF51AFD7ED558CCDull;
    h ^= h >> 29;
  }
  for (; i < n; ++i) h = (h ^ p[i]) * 0x100000001B3ull;
  return h;
}

bool Readable(const void* p, size_t n) {
  MEMORY_BASIC_INFORMATION mbi;
  const uint8_t* q = static_cast<const uint8_t*>(p);
  const uint8_t* end = q + n;
  while (q < end) {
    if (!VirtualQuery(q, &mbi, sizeof(mbi))) return false;
    if (mbi.State != MEM_COMMIT || (mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD))) return false;
    q = static_cast<const uint8_t*>(mbi.BaseAddress) + mbi.RegionSize;
  }
  return true;
}

// Guest virtual range, deduplicated by (addr, size, contents).
void AddVirtual(std::vector<Blob>& blobs, uint32_t kind, uint32_t addr, uint32_t size, bool dedupe = true) {
  if (!addr || !size || size > (4u << 20)) return;
  const uint8_t* p = Mem()->TranslateVirtual(addr);
  if (!Readable(p, size)) return;
  if (dedupe) {
    uint64_t key = Hash(p, size) ^ (uint64_t(addr) << 32) ^ size;
    if (!g_cap.seen.insert(key).second) return;
  }
  blobs.push_back({kind, addr, std::vector<uint8_t>(p, p + size)});
}

void AddPhysical(std::vector<Blob>& blobs, uint32_t addr, uint32_t size) {
  if (!size || size > (4u << 20) || (addr & 0x1FFFFFFF) + uint64_t(size) > 0x20000000) return;
  // Physical memory is one committed mapping: no VirtualQuery here (it was ~1 ms per call and made
  // a one-frame capture take 5 minutes).
  const uint8_t* p = Mem()->TranslatePhysical(addr);
  uint64_t key = Hash(p, size) ^ (uint64_t(addr | 0x80000000u) << 32) ^ size;
  if (!g_cap.seen.insert(key).second) return;
  blobs.push_back({3, addr & 0x1FFFFFFF, std::vector<uint8_t>(p, p + size)});
}

void AddDeviceDelta(std::vector<Blob>& blobs, uint32_t dev) {
  ScopedUs t(g_cap.us_device);
  const uint8_t* p = Mem()->TranslateVirtual(dev);
  if (g_cap.dev_prev.size() != kDeviceSize) {
    g_cap.dev_prev.assign(kDeviceSize, 0);
    blobs.push_back({1, 0, std::vector<uint8_t>(p, p + kDeviceSize)});
    std::memcpy(g_cap.dev_prev.data(), p, kDeviceSize);
    return;
  }
  for (uint32_t off = 0; off < kDeviceSize; off += kChunk) {
    if (std::memcmp(p + off, g_cap.dev_prev.data() + off, kChunk)) {
      blobs.push_back({1, off, std::vector<uint8_t>(p + off, p + off + kChunk)});
      std::memcpy(g_cap.dev_prev.data() + off, p + off, kChunk);
    }
  }
}

// Vertex fetch constants in the fetch shadow (device+1152, 32 slots x 3 vertex fetches).
void AddVertexStreams(std::vector<Blob>& blobs, uint32_t dev) {
  ScopedUs t(g_cap.us_streams);
  const uint8_t* f = Mem()->TranslateVirtual(dev + 1152);
  for (uint32_t i = 0; i < 96; ++i) {
    uint32_t d0 = BE32(f + i * 8), d1 = BE32(f + i * 8 + 4);
    if ((d0 & 3) != 3) continue;
    uint32_t addr = d0 & ~3u, size = ((d1 >> 2) & 0xFFFFFF) * 4;
    // Static buffers are in the frame-start memory dump; per-draw copies only for small
    // (typically dynamic) streams.
    if (size && size <= (64u << 10)) AddPhysical(blobs, addr, size);
  }
}

// Shader microcode / constants / indirect buffers referenced by command bytes.
void ScanCommands(std::vector<Blob>& blobs, const uint8_t* p, uint32_t n, int depth = 0) {
  ScopedUs t(g_cap.us_scan);
  for (uint32_t i = 0; i + 4 <= n; i += 4) {
    uint32_t h = BE32(p + i);
    if ((h >> 30) == 0) {
      // Register writes: vertex fetch constants the draw call writes itself (stream sources, e.g.
      // fetch 95) bypass the device's fetch shadow, so their buffers are recorded here.
      uint32_t cnt = ((h >> 16) & 0x3FFF) + 1, base = h & 0x7FFF;
      if (!((h >> 15) & 1) && base + cnt > 0x4800 && base < 0x48C0)
        for (uint32_t k = 0; k + 1 < cnt && i + 8 + k * 4 <= n; ++k) {
          uint32_t reg = base + k;
          if (reg < 0x4800 || reg >= 0x48C0 || ((reg - 0x4800) % 6) % 2) continue;
          uint32_t d0 = BE32(p + i + 4 + k * 4), d1 = BE32(p + i + 8 + k * 4);
          if ((d0 & 3) == 3) AddPhysical(blobs, d0 & ~3u, ((d1 >> 2) & 0xFFFFFF) * 4);
        }
      i += cnt * 4;
      continue;
    }
    if ((h >> 30) != 3) continue;
    uint32_t op = (h >> 8) & 0x7F, count = ((h >> 16) & 0x3FFF) + 1;
    if (op == 0x27 && i + 12 <= n) {  // IM_LOAD: addr|type, size (dwords)
      uint32_t a = BE32(p + i + 4) & ~3u, s = BE32(p + i + 8) * 4;
      AddPhysical(blobs, a, s);
    } else if (op == 0x2F && i + 16 <= n) {  // LOAD_ALU_CONSTANT: addr, offset, size (dwords)
      uint32_t a = BE32(p + i + 4) & ~3u, s = (BE32(p + i + 12) & 0xFFF) * 4;
      AddPhysical(blobs, a, s);
    } else if ((op == 0x3F || op == 0x37) && i + 12 <= n && depth < 2) {  // INDIRECT_BUFFER: addr, size
      uint32_t a = BE32(p + i + 4) & 0x1FFFFFFC, s = (BE32(p + i + 8) & 0xFFFFF) * 4;
      if (s && s <= (1u << 20)) {
        const uint8_t* q = Mem()->TranslatePhysical(a);
        if (Readable(q, s)) {
          size_t before = blobs.size();
          AddPhysical(blobs, a, s);
          if (blobs.size() != before) ScanCommands(blobs, q, s, depth + 1);
        }
      }
    }
    i += count * 4;
  }
}

void WriteEvent(int fn, uint32_t phase, PPCContext& ctx, std::vector<Blob>& blobs) {
  ScopedUs t(g_cap.us_write);
  EventHeader h{};
  h.magic = 0x31545645;  // 'EVT1'
  h.fn = uint32_t(fn);
  h.phase = phase;
  h.seq = g_cap.seq++;
  const uint32_t regs[8] = {ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                            ctx.r7.u32, ctx.r8.u32, ctx.r9.u32, ctx.r10.u32};
  std::memcpy(h.r, phase ? g_cap.args_before : regs, sizeof(h.r));
  if (phase) h.r[0] = ctx.r3.u32;  // return value after the call
  h.f1 = ctx.f1.f64;
  h.sp = phase ? g_cap.sp_before : ctx.r1.u32;
  h.frame = g_cap.frame;
  h.blob_count = uint32_t(blobs.size());
  fwrite(&h, sizeof(h), 1, g_cap.events);
  g_cap.bytes_events += sizeof(h);
  for (auto& b : blobs) {
    BlobHeader bh{b.kind, b.addr, uint32_t(b.data.size()), 0};
    fwrite(&bh, sizeof(bh), 1, g_cap.events);
    fwrite(b.data.data(), 1, b.data.size(), g_cap.events);
    g_cap.bytes_events += sizeof(bh) + b.data.size();
  }
  std::string line = fmt::format("{:6} f{} {} {} r3={:08X} r4={:08X} r5={:08X} r6={:08X} r7={:08X} r8={:08X} "
                                 "r9={:08X} r10={:08X} f1={:.4f} blobs={}",
                                 h.seq, h.frame, kFnNames[fn], phase ? "after" : "before", h.r[0], h.r[1], h.r[2],
                                 h.r[3], h.r[4], h.r[5], h.r[6], h.r[7], h.f1, blobs.size());
  if (!phase && fn <= kDrawIndexed2) {
    uint32_t dev = ctx.r3.u32;
    line += fmt::format(" rt0={:08X} ds={:08X} vs={:08X} ps={:08X} decl={:08X} ib={:08X}", Load32(dev + 12440),
                        Load32(dev + 12456), Load32(dev + 12696), Load32(dev + 12692), Load32(dev + 11820),
                        Load32(dev + 12436));
  }
  fprintf(g_cap.summary, "%s\n", line.c_str());
}

void DumpMemory() {
  auto* m = Mem();
  FILE* bin = _wfopen((g_cap.dir / "memory.bin").c_str(), L"wb");
  FILE* idx = _wfopen((g_cap.dir / "memory_index.txt").c_str(), L"w");
  if (!bin || !idx) return;
  fprintf(idx, "# space guest_addr size file_offset (P = physical, V = virtual below 0xA0000000)\n");
  fprintf(idx, "# view offsets: A0000000->%llX C0000000->%llX E0000000->%llX (host - physical_membase)\n",
          (long long)(m->TranslateVirtual(0xA0000000) - m->physical_membase()),
          (long long)(m->TranslateVirtual(0xC0000000) - m->physical_membase()),
          (long long)(m->TranslateVirtual(0xE0000000) - m->physical_membase()));
  uint64_t offset = 0, skipped = 0;
  auto dump = [&](char space, uint8_t* host_base, uint64_t guest_base, uint64_t len) {
    uint8_t* p = host_base;
    uint8_t* end = host_base + len;
    MEMORY_BASIC_INFORMATION mbi;
    while (p < end && VirtualQuery(p, &mbi, sizeof(mbi))) {
      uint8_t* rb = static_cast<uint8_t*>(mbi.BaseAddress);
      uint8_t* re = std::min(end, rb + mbi.RegionSize);
      uint8_t* rs = std::max(p, rb);
      if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD))) {
        uint64_t n = uint64_t(re - rs);
        fwrite(rs, 1, n, bin);
        fprintf(idx, "%c %08llX %llX %llX\n", space, (unsigned long long)(guest_base + (rs - host_base)),
                (unsigned long long)n, (unsigned long long)offset);
        offset += n;
      } else if (mbi.State == MEM_COMMIT) {
        skipped += uint64_t(re - rs);
      }
      p = re;
    }
  };
  dump('V', m->virtual_membase(), 0, 0xA0000000ull);
  dump('P', m->physical_membase(), 0, 0x20000000ull);
  fclose(bin);
  fclose(idx);
  REXLOG_INFO("D3D capture: memory dump {} MB ({} MB committed but not readable, skipped)", offset >> 20,
              skipped >> 20);
}

void Start() {
  auto now = std::time(nullptr);
  std::tm tm{};
  localtime_s(&tm, &now);
  char name[64];
  std::strftime(name, sizeof(name), "%Y%m%d_%H%M%S", &tm);
  g_cap.dir = rex::filesystem::GetExecutableFolder() / "captures" / name;
  std::error_code ec;
  std::filesystem::create_directories(g_cap.dir, ec);
  REXLOG_INFO("D3D capture: starting in {}", g_cap.dir.string());
  auto t0 = std::chrono::steady_clock::now();
  DumpMemory();
  g_cap.events = _wfopen((g_cap.dir / "events.bin").c_str(), L"wb");
  g_cap.summary = _wfopen((g_cap.dir / "summary.txt").c_str(), L"w");
  g_cap.seq = 0;
  g_cap.frame = 0;
  g_cap.dev_prev.clear();
  g_cap.seen.clear();
  g_cap.pending_up.clear();
  g_resolve_dests.clear();
  {
    std::lock_guard<std::mutex> lock(g_observed_mutex);
    g_observed.clear();
    g_observed_bytes = 0;
  }
  g_capture_cpu_swap = g_cpu_swaps.load();
  rex::graphics::SetResolveObserver(&OnResolveReadback);
  g_cap.bytes_events = 0;
  g_cap.last_put = 0;
  g_cap.gap_bytes = g_cap.gap_skipped = 0;
  g_cap.us_before = g_cap.us_after = g_cap.us_streams = g_cap.us_scan = g_cap.us_write = g_cap.us_device = 0;
  REXLOG_INFO("D3D capture: memory dumped in {} ms, recording {} frame(s)",
              std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t0).count(),
              REXCVAR_GET(d3d_capture_frames));
  g_state = (g_cap.events && g_cap.summary) ? kRecording : kIdle;
  g_cap.pieces.clear();
  g_cap.in_call = false;
  if (g_state == kRecording && NativeFrontend_Active()) NativeFrontend_RequestCaptureSnapshot(g_cap.dir.string());
}

// The emulated renderer's image of the captured frame, as a reference for the native renderer.
// Called on the render thread right after the frame's Swap: waiting here lets the command
// processor finish and present exactly this frame (the game cannot submit the next one meanwhile).
void SaveReferenceImage() {
  auto* rt = rex::Runtime::instance();
  auto* gs = rt ? static_cast<rex::graphics::GraphicsSystem*>(rt->graphics_system()) : nullptr;
  if (!gs || !gs->presenter()) return;
  std::this_thread::sleep_for(std::chrono::milliseconds(400));
  rex::ui::RawImage img;
  if (!gs->presenter()->CaptureGuestOutput(img) || !img.width) {
    REXLOG_WARN("D3D capture: could not capture the guest output for the reference image");
    return;
  }
  std::vector<uint8_t> rgba(size_t(img.width) * img.height * 4);
  for (uint32_t y = 0; y < img.height; ++y) {
    const uint8_t* src = img.data.data() + y * img.stride;
    uint8_t* dst = rgba.data() + size_t(y) * img.width * 4;
    for (uint32_t x = 0; x < img.width; ++x) {
      dst[x * 4 + 0] = src[x * 4 + 0];
      dst[x * 4 + 1] = src[x * 4 + 1];
      dst[x * 4 + 2] = src[x * 4 + 2];
      dst[x * 4 + 3] = 255;
    }
  }
  native::WritePng((g_cap.dir / "reference.png").string(), rgba.data(), img.width, img.height);
  REXLOG_INFO("D3D capture: reference image {}x{} saved", img.width, img.height);
}

// Reference contents of every texture resolved during the capture, as the emulated GPU wrote them
// back (readback_resolve=full), taken after the reference image wait: resolve_ref/<base>.bin plus
// index.txt lines "texture_object fetch0..fetch5 base bytes". Ground truth for the native
// renderer's intermediate passes (a later frame of the same scene, since the game keeps running).
void SaveResolveReferences() {
  auto dir = g_cap.dir / "resolve_ref";
  std::error_code ec;
  std::filesystem::create_directories(dir, ec);
  FILE* idx = _wfopen((dir / "index.txt").c_str(), L"w");
  if (!idx) return;
  for (uint32_t tex : g_resolve_dests) {
    uint32_t f[6];
    for (uint32_t i = 0; i < 6; ++i) f[i] = Load32(tex + 28 + 4 * i);
    uint32_t base = (f[1] >> 12) << 12;
    // Generous size bound: 2D size from the fetch constant, 32x32-aligned, up to 16 bytes/texel.
    uint32_t w = (f[2] & 0x1FFF) + 1, h = ((f[2] >> 13) & 0x1FFF) + 1;
    uint32_t bytes = std::min<uint32_t>(((w + 31) & ~31u) * ((h + 31) & ~31u) * 16, 32u << 20);
    uint32_t phys = base >= 0xA0000000 ? ((base & 0x1FFFFFFF) + (base >= 0xE0000000 ? 0x1000 : 0)) : base;
    auto* m = Mem();
    const uint8_t* p = m->physical_membase() + phys;
    if (phys + uint64_t(bytes) > 0x20000000ull || !Readable(p, bytes)) continue;
    char name[32];
    std::snprintf(name, sizeof(name), "%08X.bin", phys);
    if (FILE* out = _wfopen((dir / name).c_str(), L"wb")) {
      fwrite(p, 1, bytes, out);
      fclose(out);
    }
    std::fprintf(idx, "%08X %08X %08X %08X %08X %08X %08X %08X %u\n", tex, f[0], f[1], f[2], f[3], f[4], f[5], phys,
                 bytes);
  }
  fclose(idx);
  REXLOG_INFO("D3D capture: {} resolve references saved", g_resolve_dests.size());
  // Every resolve the command processor executed while recording, in order (resolve_seq/):
  // index.txt lines "n cp_swap address bytes", data in <n>.bin. The frame the capture recorded is
  // the one executed after command-processor swap number `capture_cpu_swap` (first line).
  rex::graphics::SetResolveObserver(nullptr);
  auto seq_dir = g_cap.dir / "resolve_seq";
  std::filesystem::create_directories(seq_dir, ec);
  std::lock_guard<std::mutex> lock(g_observed_mutex);
  if (FILE* sidx = _wfopen((seq_dir / "index.txt").c_str(), L"w")) {
    std::fprintf(sidx, "capture_cpu_swap %llu\n", (unsigned long long)g_capture_cpu_swap);
    for (size_t n = 0; n < g_observed.size(); ++n) {
      const auto& o = g_observed[n];
      std::fprintf(sidx, "%zu %llu %08X %zu\n", n, (unsigned long long)o.cp_swap, o.address, o.data.size());
      char name[32];
      std::snprintf(name, sizeof(name), "%zu.bin", n);
      if (FILE* out = _wfopen((seq_dir / name).c_str(), L"wb")) {
        fwrite(o.data.data(), 1, o.data.size(), out);
        fclose(out);
      }
    }
    fclose(sidx);
  }
  REXLOG_INFO("D3D capture: {} resolves observed on the command processor ({} MB)", g_observed.size(),
              g_observed_bytes >> 20);
  g_observed.clear();
  g_observed_bytes = 0;
}

void Stop() {
  SaveReferenceImage();
  SaveResolveReferences();
  rex::cvar::SetFlagByName("readback_resolve", g_readback_before.empty() ? "none" : g_readback_before);
  REXLOG_INFO("D3D capture: time (ms) before={} after={} streams={} scan={} write={} device={}",
              g_cap.us_before / 1000, g_cap.us_after / 1000, g_cap.us_streams / 1000, g_cap.us_scan / 1000,
              g_cap.us_write / 1000, g_cap.us_device / 1000);
  if (g_cap.events) fclose(g_cap.events);
  if (g_cap.summary) fclose(g_cap.summary);
  g_cap.events = g_cap.summary = nullptr;
  REXLOG_INFO("D3D capture: done, {} events, {} MB of event data ({} KB written between hooked calls, {} "
              "segment switches) in {}",
              g_cap.seq, g_cap.bytes_events >> 20, g_cap.gap_bytes >> 10, g_cap.gap_skipped, g_cap.dir.string());
  g_state = kIdle;
}

bool Recorded(int fn) { return fn != kCommitShaders && fn != kCommitRS && fn != kGameStateFlush; }

}  // namespace

void D3DCapture_Request() {
  int expected = kIdle;
  if (g_state.compare_exchange_strong(expected, kRequested)) {
    g_readback_before = rex::cvar::GetFlagByName("readback_resolve");
    rex::cvar::SetFlagByName("readback_resolve", "full");
    g_arm_frames = kArmFrames;
    REXLOG_INFO("D3D capture: requested (resolve readback on, starts in {} frames)", kArmFrames);
  }
}

// Command bytes (from, to] plus the segment pieces recorded since `from` was set.
std::vector<uint8_t> GatherCommandBytes(uint32_t from, uint32_t to) {
  std::vector<uint8_t> out;
  auto append = [&](uint32_t a, uint32_t b) {
    if (!a || b <= a || b - a >= (1u << 20)) return;
    const uint8_t* p = Mem()->TranslateVirtual(a + 4);
    if (Readable(p, b - a)) out.insert(out.end(), p, p + (b - a));
  };
  for (const auto& pc : g_cap.pieces) append(pc.first, pc.second);
  g_cap.pieces.clear();
  append(from, to);
  return out;
}

void D3DCapture_SegmentSwitch(uint32_t device, bool after) {
  if (g_state != kRecording || !device) return;
  uint32_t put = Load32(device + 48);
  uint32_t& start = g_cap.in_call ? g_cap.put_before : g_cap.last_put;
  if (!after) {
    if (start && put > start && put - start < (1u << 20)) g_cap.pieces.push_back({start, put});
  } else {
    start = put;
  }
}

bool D3DCapture_Active() { return g_state.load(std::memory_order_relaxed) != kIdle; }

void D3DCapture_Before(int fn, PPCContext& ctx, uint8_t* base) {
  (void)base;
  if (g_state != kRecording || !Recorded(fn)) return;
  ScopedUs timer(g_cap.us_before);
  uint32_t dev = ctx.r3.u32;
  std::vector<Blob> blobs;
  // Data the game wrote into space returned by Begin*Vertices since the last event.
  for (auto& up : g_cap.pending_up) AddVirtual(blobs, 5, up.addr, up.size, false);
  g_cap.pending_up.clear();
  AddDeviceDelta(blobs, dev);
  // Commands the game wrote itself (LTCG-inlined D3D code) since the previous hooked call.
  {
    uint32_t put = Load32(dev + 48);
    bool had_pieces = !g_cap.pieces.empty();
    std::vector<uint8_t> bytes = GatherCommandBytes(g_cap.last_put, put);
    if (!bytes.empty()) {
      ScanCommands(blobs, bytes.data(), uint32_t(bytes.size()));
      g_cap.gap_bytes += bytes.size();
      blobs.push_back({6, g_cap.last_put + 4, std::move(bytes)});
    } else if (g_cap.last_put && put != g_cap.last_put && !had_pieces) {
      ++g_cap.gap_skipped;  // segment switch (kick-off) in between
    }
  }
  switch (fn) {
    case kDrawIndexed:
    case kDrawIndexed2: {
      uint32_t ib = Load32(dev + 12436);
      if (ib) {
        uint32_t flags = Load32(ib), addr = Load32(ib + 24);
        uint32_t isz = (flags & 0x80000000u) ? 4 : 2;
        AddVirtual(blobs, 2, ib, 32);
        AddVirtual(blobs, 2, addr + ctx.r6.u32 * isz, ctx.r7.u32 * isz);
      }
      [[fallthrough]];
    }
    case kDraw:
    case kDrawRect2D:
    case kBeginIndexedUP:
    case kBeginUP:
      AddVertexStreams(blobs, dev);
      for (uint32_t i = 0; i < 5; ++i) AddVirtual(blobs, 2, Load32(dev + 12440 + 4 * i), 64);  // RT0-3, DS
      AddVirtual(blobs, 2, Load32(dev + 12692), 2048);                                       // PS object
      AddVirtual(blobs, 2, Load32(dev + 12696), 2048);                                       // VS object
      AddVirtual(blobs, 2, Load32(dev + 11820), 256);                                        // vertex decl
      break;
    case kResolve:
      if (ctx.r6.u32 && std::find(g_resolve_dests.begin(), g_resolve_dests.end(), ctx.r6.u32) == g_resolve_dests.end())
        g_resolve_dests.push_back(ctx.r6.u32);
      AddVirtual(blobs, 2, ctx.r5.u32, 16);   // source rect
      AddVirtual(blobs, 2, ctx.r6.u32, 64);   // destination texture header
      AddVirtual(blobs, 2, ctx.r7.u32, 8);    // destination point
      AddVirtual(blobs, 2, ctx.r10.u32, 16);  // clear colour
      AddVirtual(blobs, 2, ctx.r1.u32 + 80, 32, false);  // stack arguments (stencil, parameters)
      for (uint32_t i = 0; i < 5; ++i) AddVirtual(blobs, 2, Load32(dev + 12440 + 4 * i), 64);
      break;
    case kClear:
      AddVirtual(blobs, 2, ctx.r5.u32, 16);  // rect
      AddVirtual(blobs, 2, ctx.r6.u32, 16);  // colour
      for (uint32_t i = 0; i < 5; ++i) AddVirtual(blobs, 2, Load32(dev + 12440 + 4 * i), 64);
      break;
    case kGpuLoadShaders:
      AddVirtual(blobs, 2, ctx.r4.u32, 2048);  // vertex shader object
      AddVirtual(blobs, 2, ctx.r5.u32, 2048);  // pixel shader object
      AddVirtual(blobs, 2, ctx.r6.u32, 160);   // flow (bool/loop) constant block, changes during the frame
      break;
    case kGpuLoadConstants: {
      // Constant data straight from a D3D constant buffer object (data address at +24).
      uint32_t data = Load32(ctx.r7.u32 + 24) + ctx.r8.u32 * 16;
      AddVirtual(blobs, 2, ctx.r7.u32, 32);
      AddVirtual(blobs, 2, data, ctx.r6.u32 * 16, false);
      break;
    }
    case kSwap:
      AddVirtual(blobs, 2, ctx.r4.u32, 64);  // front buffer texture
      AddVirtual(blobs, 2, ctx.r5.u32, 64);  // parameters
      break;
    default:
      break;
  }
  g_cap.put_before = Load32(dev + 48);
  g_cap.in_call = true;
  g_cap.sp_before = ctx.r1.u32;
  const uint32_t regs[8] = {ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                            ctx.r7.u32, ctx.r8.u32, ctx.r9.u32, ctx.r10.u32};
  std::memcpy(g_cap.args_before, regs, sizeof(regs));
  WriteEvent(fn, 0, ctx, blobs);
}

void D3DCapture_After(int fn, PPCContext& ctx, uint8_t* base) {
  (void)base;
  if (fn == kSwap) {
    g_cpu_swaps.fetch_add(1);
    if (g_state == kRequested) {
      if (--g_arm_frames <= 0) Start();
      return;
    }
  }
  if (g_state != kRecording || !Recorded(fn)) return;
  ScopedUs timer(g_cap.us_after);
  uint32_t dev = g_cap.args_before[0];
  std::vector<Blob> blobs;
  // Command bytes the call wrote (put pointer pre-increments: bytes are (put_before, put_after]).
  uint32_t put = Load32(dev + 48);
  g_cap.in_call = false;
  {
    uint32_t start = g_cap.put_before + 4;
    std::vector<uint8_t> bytes = GatherCommandBytes(g_cap.put_before, put);
    if (!bytes.empty()) {
      ScanCommands(blobs, bytes.data(), uint32_t(bytes.size()));
      blobs.push_back({4, start, std::move(bytes)});
    }
  }
  g_cap.last_put = put;
  if (fn == kBeginIndexedUP && ctx.r3.u32 == 0) {
    uint32_t idx_ptr = Load32(g_cap.args_before[7]);            // *ppIndexData (r10)
    uint32_t vtx_ptr = Load32(Load32(g_cap.sp_before + 84));    // *ppVertexData (9th argument)
    uint32_t verts = g_cap.args_before[3], stride = g_cap.args_before[6];
    uint32_t indices = g_cap.args_before[4], isz = (g_cap.args_before[5] & 4) ? 4 : 2;
    g_cap.pending_up.push_back({vtx_ptr, verts * stride});
    g_cap.pending_up.push_back({idx_ptr, indices * isz});
  } else if (fn == kBeginUP && ctx.r3.u32) {
    g_cap.pending_up.push_back({ctx.r3.u32, g_cap.args_before[2] * g_cap.args_before[3]});
  }
  WriteEvent(fn, 1, ctx, blobs);
  if (fn == kSwap && ++g_cap.frame >= uint32_t(REXCVAR_GET(d3d_capture_frames))) Stop();
}
