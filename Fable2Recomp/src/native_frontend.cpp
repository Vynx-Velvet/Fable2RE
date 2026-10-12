/**
 * @file        src/native_frontend.cpp
 * @brief       Native D3D12 rendering in-game (step 3, milestone 3).
 *
 * With native_renderer=true the game's Xbox D3D calls (hooked in d3d_probe.cpp) drive the native
 * renderer (native/renderer.cpp) directly, the same way Fable2Replay drives it from a capture:
 * before each call the device object is snapshotted, after it the command bytes the call wrote
 * give the microcode actually loaded (D3D patches shaders per draw), per-tile predication and a few
 * constants; then the call is executed natively. The emulated command processor only services
 * synchronization (gpu_native_frontend): it skips draws, resolves and presentation.
 *
 * Guest memory -> GPU: a SharedMemory (the SDK's page-watch coherency) uploads the pages draws
 * read on demand, and the same watches invalidate cached textures when the game rewrites them.
 */
#include <chrono>
#include "d3d_hooks.h"

#include "../native/png.h"
#include "../native/renderer.h"

#include <rex/cvar.h>
#include <rex/filesystem.h>
#include <rex/logging.h>
#include <rex/ppc.h>
#include <rex/runtime.h>
#include <rex/system/xmemory.h>
#include <rex/system/xthread.h>
#include <rex/system/kernel_state.h>
#include <rex/graphics/graphics_system.h>
#include <rex/graphics/shared_memory.h>
#include <rex/hash.h>
#include <rex/ui/d3d12/d3d12_presenter.h>
#include <rex/ui/d3d12/d3d12_provider.h>

#include <windows.h>
#include <dbghelp.h>
#include <io.h>

#include <algorithm>
#include <condition_variable>
#include <deque>
#include <thread>
#include <atomic>
#include <filesystem>
#include <functional>
#include <map>
#include <array>
#include <cstring>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include <fmt/format.h>

REXCVAR_DEFINE_BOOL(native_trace_rolling, false, "Render",
                    "Native renderer diagnostics: trace every frame to a rolling file; F10 keeps the trace of "
                    "the frame on screen when pressed (native_snapshots/trace_<frame>_onscreen.txt). Slow.");

REXCVAR_DEFINE_BOOL(native_skip_d3d_flush, true, "Render",
                    "Native renderer: skip the Xbox D3D library's constant/register/fetch-constant command "
                    "writers inside draws (the renderer reads that state from the device directly)");

REXCVAR_DEFINE_BOOL(native_render_thread, true, "Render",
                    "Native renderer: run it on its own thread (the game's D3D calls only record what to draw; "
                    "GPU fences complete when the renderer has executed the work)");
REXCVAR_DEFINE_INT32(native_render_frames_ahead, 1, "Render",
                     "With native_render_thread: frames the game may run ahead of the renderer (game and renderer "
                     "work in parallel). 0 = the game's swap returns once the renderer finished the frame. While "
                     "the game rewrites textures from the CPU every frame (Bink videos) the renderer switches to 0 "
                     "by itself for a while (the video player relies on it)");
REXCVAR_DEFINE_BOOL(native_async_pipelines, true, "Render",
                    "Native renderer: compile pipeline states on background threads (draws whose pipeline is not "
                    "ready after native_pipeline_wait_ms appear a moment later instead of freezing the game)");
REXCVAR_DEFINE_INT32(native_pipeline_wait_ms, 8, "Render",
                     "Native renderer: how long draws may wait in total per frame for pipelines still compiling");
REXCVAR_DEFINE_BOOL(native_draw_profile, false, "Render",
                    "Native renderer: time the sections of every draw (perf log 'draw sections'; slows drawing)");
REXCVAR_DEFINE_BOOL(native_state_cache, true, "Render",
                    "Native renderer: skip command list state calls that would not change anything");
REXCVAR_DEFINE_BOOL(native_realtime_shadows, true, "Render",
                    "Native renderer: build the shadow mask from this frame's depth (depth pre-pass) instead "
                    "of the previous frame's, as the console does");

REXCVAR_DEFINE_BOOL(native_occlusion_queries, false, "Render",
                    "Native renderer: answer the game's occlusion queries with real GPU sample counts "
                    "(experimental). Off: every query reports visible, like the emulated GPU path.");

REXCVAR_DEFINE_BOOL(native_renderer, false, "Render",
                    "Render with the native D3D12 renderer driven by the game's D3D calls instead of the "
                    "emulated GPU command processor (experimental)");

using namespace d3dhooks;

namespace {

rex::memory::Memory* Mem() {
  auto* rt = rex::Runtime::instance();
  return rt ? rt->memory() : nullptr;
}

uint32_t BE32(const uint8_t* p) {
  return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) | p[3];
}

float BEF(const uint8_t* p) {
  uint32_t v = BE32(p);
  float f;
  std::memcpy(&f, &v, 4);
  return f;
}

// ---------------------------------------------------------------------------------------------
// Guest memory -> native renderer

// Upload accounting: bytes uploaded while arming texture watches (the texture's pages are made valid
// in the GPU copy of guest memory, which the textures themselves never read).
thread_local bool t_arming_watch = false;
std::atomic<uint64_t> g_watch_upload_bytes{0};

class NativeSharedMemory final : public rex::graphics::SharedMemory {
 public:
  NativeSharedMemory(rex::memory::Memory& memory, native::Renderer& renderer)
      : SharedMemory(memory), renderer_(renderer) {
    InitializeCommon();
  }
  ~NativeSharedMemory() override { ShutdownCommon(); }

 protected:
  bool UploadRanges(const std::vector<std::pair<uint32_t, uint32_t>>& upload_page_ranges) override {
    const uint32_t log2 = page_size_log2();
    for (const auto& [first_page, page_count] : upload_page_ranges) {
      uint32_t start = first_page << log2, length = page_count << log2;
      MakeRangeValid(start, length, false);
      if (t_arming_watch) g_watch_upload_bytes.fetch_add(length, std::memory_order_relaxed);
      renderer_.UploadPhysical(start, memory().TranslatePhysical<const uint8_t*>(start), length);
    }
    return true;
  }

 private:
  native::Renderer& renderer_;
};

class LiveMemory final : public native::GuestMemory {
 public:
  explicit LiveMemory(rex::memory::Memory& memory) : memory_(memory) {}
  void set_shared(NativeSharedMemory* shared) { shared_ = shared; }

  const uint8_t* Physical(uint32_t addr, uint32_t size) const override {
    if (uint64_t(addr) + size > 0x20000000ull) return nullptr;
    return memory_.physical_membase() + addr;
  }
  const uint8_t* Virtual(uint32_t addr, uint32_t size) const override {
    (void)size;
    return addr ? memory_.TranslateVirtual<const uint8_t*>(addr) : nullptr;
  }
  void RequestRange(uint32_t physical, uint32_t size) const override {
    if (shared_ && size) shared_->RequestRange(physical & 0x1FFFFFFF, size);
  }
  void UploadNow(uint32_t physical, uint32_t size) const override {
    physical &= 0x1FFFFFFF;
    if (renderer_ && size && uint64_t(physical) + size <= 0x20000000ull)
      renderer_->UploadPhysical(physical, memory_.physical_membase() + physical, size);
  }
  void set_renderer(native::Renderer* r) { renderer_ = r; }
  void GpuWroteRange(uint32_t physical, uint32_t size) const override {
    if (shared_ && size) shared_->RangeWrittenByGpu(physical & 0x1FFFFFFF, size);
  }
  void WatchRange(uint32_t physical, uint32_t size, std::shared_ptr<std::atomic<bool>> invalidated) const override {
    if (!shared_ || !size) return;
    physical &= 0x1FFFFFFF;
    // Watches only fire for pages the shared memory considers valid (protected).
    t_arming_watch = true;
    shared_->RequestRange(physical, size);
    t_arming_watch = false;
    // The flag must outlive the watch (the cached texture may be dropped first).
    keep_alive_.emplace(invalidated.get(), invalidated);
    shared_->WatchMemoryRange(
        physical, size,
        [](const std::unique_lock<std::recursive_mutex>&, void*, void* data, uint64_t, bool) {
          static_cast<std::atomic<bool>*>(data)->store(true, std::memory_order_release);
        },
        nullptr, invalidated.get(), 0);
  }

 private:
  rex::memory::Memory& memory_;
  NativeSharedMemory* shared_ = nullptr;
  native::Renderer* renderer_ = nullptr;
  mutable std::unordered_map<const void*, std::shared_ptr<std::atomic<bool>>> keep_alive_;
};

// ---------------------------------------------------------------------------------------------
// Frontend state (all D3D calls come from the game's render thread)

// Shader microcode as the GPU loads it (big-endian dwords), interned by content: loads, recorded
// draws and the renderer share one immutable copy, and the renderer gets the content hash it would
// otherwise compute per draw. D3D patches vertex shaders per draw, but the patched variants repeat;
// the pool holds each variant once (never freed: a few thousand of a few KB at most). Only the
// recording side (hooked D3D calls, serialized by g_call_mutex) inserts.
struct Ucode {
  const uint32_t* data = nullptr;
  uint32_t dwords = 0;
  uint64_t hash = 0;
  bool empty() const { return !data; }
};
Ucode InternUcode(const uint8_t* src, uint32_t dwords) {
  static std::unordered_map<uint64_t, std::unique_ptr<std::vector<uint32_t>>> pool;
  uint64_t hash = XXH3_64bits(src, size_t(dwords) * 4);
  auto& slot = pool[hash];
  if (!slot)
    slot = std::make_unique<std::vector<uint32_t>>(reinterpret_cast<const uint32_t*>(src),
                                                   reinterpret_cast<const uint32_t*>(src) + dwords);
  return {slot->data(), uint32_t(slot->size()), hash};
}
struct LoadedShaders {
  Ucode vs, ps;
};

struct Frontend {
  bool initialized = false, failed = false;
  std::unique_ptr<native::Renderer> renderer;
  std::unique_ptr<LiveMemory> mem;
  std::unique_ptr<NativeSharedMemory> shared;
  // Process exit: the runtime (guest memory, GPU device) is already gone when static destructors
  // run, so these are intentionally not torn down.
  ~Frontend() {
    (void)renderer.release();
    (void)mem.release();
    (void)shared.release();
  }
  bool constants_initialized = false;

  // Before-call snapshot.
  std::vector<uint8_t> device;  // device object (big-endian)
  uint32_t r[8] = {};           // r3..r10
  double f1 = 0;
  uint32_t sp = 0;
  uint32_t put_before = 0, last_put = 0;
  // Command buffer segment switches (sub_821E8D20) since the current range started: the valid
  // (start, end] pieces of the old segments. The bytes between a segment's end and the next segment
  // are not commands (stale data from earlier laps) and must not be parsed.
  std::vector<std::pair<uint32_t, uint32_t>> pieces;
  std::vector<uint8_t> piece_buf;

  LoadedShaders loaded;
  uint32_t bin_mask = 0xFFFFFFFFu;
  native::ShaderState shaders;

  // Begin*Vertices: drawn once the game has written the data (at the next hooked call).
  bool pending_up = false;
  native::DrawArgs up_args;
  std::vector<uint8_t> up_device;
  LoadedShaders up_shaders;

  uint64_t frames = 0;
  uint64_t gaps_lost = 0;
} g;

// The command bytes written since `from` up to `to` (put pointers: bytes (from, to]), across any
// segment switches recorded meanwhile. Null if there are none.
const uint8_t* GatherCommands(uint32_t from, uint32_t to, uint32_t* size) {
  *size = 0;
  if (g.pieces.empty()) {
    if (!from || to <= from || to - from >= (1u << 20)) return nullptr;
    *size = to - from;
    return g.mem->Virtual(from + 4, to - from);
  }
  g.piece_buf.clear();
  auto append = [&](uint32_t a, uint32_t b) {
    if (!a || b <= a || b - a >= (1u << 20)) return;
    if (const uint8_t* p = g.mem->Virtual(a + 4, b - a)) g.piece_buf.insert(g.piece_buf.end(), p, p + (b - a));
  };
  for (const auto& pc : g.pieces) append(pc.first, pc.second);
  g.pieces.clear();
  append(from, to);
  *size = uint32_t(g.piece_buf.size());
  return g.piece_buf.empty() ? nullptr : g.piece_buf.data();
}

// ---------------------------------------------------------------------------------------------
// Render thread. The game's D3D calls record commands; the renderer executes them in order on its
// own thread, like a GPU consuming a command buffer. Commands carry everything read from guest memory
// that the game may change afterwards (device state, shader microcode, immediate-mode vertex data,
// constant values); resources the game protects with GPU fences (vertex buffers, textures) are read
// when executed - the native GPU sync completes those fences only once the renderer got there.

struct Cmd {
  enum Type : uint8_t { kDraw, kClear, kResolve, kConst, kFetch, kShaders, kGpuSync, kCall };
  Type type = kCall;
  uint32_t seq = 0;
  // Device snapshot as a delta against the previous snapshot (the renderer thread keeps its device
  // view up to date in command order): the changed 64-byte chunks of the parts the renderer reads -
  // dirty masks [0, 48), fetch constants [1152, 1920), bool/loop constants, register blocks and object
  // pointers [10112, 12704) - as {offset u16, size u8, 0, bytes}, plus the dirty float-constant groups
  // (offset + 64 bytes each). Consecutive draws change a few registers, not the 3.4 KB.
  std::vector<uint8_t> delta, groups;
  native::ShaderState shaders;
  native::DrawArgs draw;  // (microcode pointers are interned, see Ucode)
  std::vector<uint8_t> up_vertex, up_index;
  native::ClearArgs clear;
  native::ResolveArgs resolve;
  uint32_t reg = 0, shadow = 0, vs_obj = 0, ps_obj = 0;
  bool has_flow = false;
  uint8_t flow[160];
  std::vector<uint32_t> values;  // constants / ring dwords
  std::function<void()> fn;
  // Guest D3D objects the command references (surfaces, index buffer, resolve destination):
  // {address, 64 bytes} each. The game creates some of them per frame and reuses the memory, so the
  // renderer must see them as they were when the call was made.
  std::vector<uint8_t> objects;
};

// The renderer thread's view of guest memory: D3D objects as recorded by the commands executed so far,
// live memory for everything else (data the game protects with GPU fences).
class WorkerMemory final : public native::GuestMemory {
 public:
  explicit WorkerMemory(const native::GuestMemory& live) : live_(live) {}
  const uint8_t* Physical(uint32_t addr, uint32_t size) const override { return live_.Physical(addr, size); }
  const uint8_t* Virtual(uint32_t addr, uint32_t size) const override {
    if (addr >= lo_ && addr < hi_) {
      if (last_ != objects_.end() && addr >= last_->first && uint64_t(addr) + size <= uint64_t(last_->first) + 64)
        return last_->second.data() + (addr - last_->first);
      auto it = objects_.upper_bound(addr);
      if (it != objects_.begin()) {
        --it;
        if (addr >= it->first && uint64_t(addr) + size <= uint64_t(it->first) + 64) {
          last_ = it;
          return it->second.data() + (addr - it->first);
        }
      }
    }
    return live_.Virtual(addr, size);
  }
  void RequestRange(uint32_t physical, uint32_t size) const override { live_.RequestRange(physical, size); }
  void UploadNow(uint32_t physical, uint32_t size) const override { live_.UploadNow(physical, size); }
  void WatchRange(uint32_t physical, uint32_t size, std::shared_ptr<std::atomic<bool>> invalidated) const override {
    live_.WatchRange(physical, size, std::move(invalidated));
  }
  void GpuWroteRange(uint32_t physical, uint32_t size) const override { live_.GpuWroteRange(physical, size); }
  void Apply(const std::vector<uint8_t>& objects) {
    // Consecutive draws nearly always reference the same objects: apply only when they differ.
    if (objects == last_applied_) return;
    last_applied_ = objects;
    for (size_t i = 0; i + 68 <= objects.size(); i += 68) {
      uint32_t addr;
      std::memcpy(&addr, &objects[i], 4);
      std::memcpy(objects_[addr].data(), &objects[i + 4], 64);
      lo_ = std::min(lo_, addr);
      hi_ = std::max(hi_, addr + 64);
    }
  }
  void Clear() {
    objects_.clear();
    last_applied_.clear();
    last_ = objects_.end();
    lo_ = UINT32_MAX;
    hi_ = 0;
  }

 private:
  const native::GuestMemory& live_;
  std::map<uint32_t, std::array<uint8_t, 64>> objects_;
  mutable std::map<uint32_t, std::array<uint8_t, 64>>::const_iterator last_ = objects_.end();
  uint32_t lo_ = UINT32_MAX, hi_ = 0;  // address range of the recorded objects
  std::vector<uint8_t> last_applied_;
};
std::unique_ptr<WorkerMemory> g_wmem;

void ExecuteCmd(Cmd& c);

class RenderThread {
 public:
  bool active() const { return active_; }
  void Start() {
    active_ = true;
    // A guest-capable thread: GPU interrupts (the game's GPU callbacks) run right on it.
    auto* rt = rex::Runtime::instance();
    thread_ = new rex::system::object_ref<rex::system::XHostThread>(new rex::system::XHostThread(
        rt->kernel_state(), 256 * 1024, 0, [this] {
          Main();
          return 0;
        }));
    (*thread_)->set_name("Native Renderer");
    (*thread_)->Create();
  }
  // Begin returns a command to fill (under the queue lock); End queues it (or runs it right away
  // without the thread).
  Cmd& Begin(Cmd::Type type) {
    if (!active_) {
      inline_.type = type;
      inline_.objects.clear();
      return inline_;
    }
    mutex_.lock();
    if (pending_used_ == pending_.size()) pending_.emplace_back();
    Cmd& c = pending_[pending_used_++];
    c.type = type;
    c.objects.clear();
    return c;
  }
  void End() {
    if (!active_) {
      ExecuteCmd(inline_);
      return;
    }
    mutex_.unlock();
    // Wake the renderer only when it sleeps: notifying on every command cost the game's render thread
    // a kernel call per draw while the renderer was busy anyway. (sleeping_ is set under the lock before
    // the renderer waits, so a command queued after that sees it.)
    if (sleeping_.load(std::memory_order_acquire)) work_cv_.notify_one();
  }
  void Call(std::function<void()> fn) {
    Cmd& c = Begin(Cmd::kCall);
    c.fn = std::move(fn);
    End();
  }
  // Frame accounting: the game may run at most `max_ahead` frames ahead of the renderer.
  void FrameQueued(uint32_t max_ahead) {
    if (!active_) return;
    if (lockstep_frames_.load(std::memory_order_acquire) > 0) max_ahead = 0;
    ++frames_queued_;
    Call([this] {
      frames_done_.fetch_add(1, std::memory_order_release);
      done_cv_.notify_all();
    });
    std::unique_lock<std::mutex> l(done_mutex_);
    done_cv_.wait(l, [&] { return frames_queued_ - frames_done_.load(std::memory_order_acquire) <= max_ahead; });
  }
  // Blocks until everything queued so far has executed.
  void Drain() {
    if (!active_) return;
    std::atomic<bool> done{false};
    Call([&] {
      done = true;
      done_cv_.notify_all();
    });
    std::unique_lock<std::mutex> l(done_mutex_);
    done_cv_.wait(l, [&] { return done.load(); });
  }
  uint64_t busy_us() const { return busy_us_.load(std::memory_order_relaxed); }
  // Frames for which the game's swap waits for the renderer regardless of native_render_frames_ahead
  // (set by the renderer while the game rewrites textures from the CPU every frame, e.g. videos).
  void RequestLockstep(int frames) { lockstep_frames_.store(frames, std::memory_order_release); }
  void LockstepFrameDone() {
    int v = lockstep_frames_.load(std::memory_order_acquire);
    if (v > 0) lockstep_frames_.store(v - 1, std::memory_order_release);
  }
  bool lockstep() const { return lockstep_frames_.load(std::memory_order_acquire) > 0; }

 private:
  void Main() {
    SetThreadDescription(GetCurrentThread(), L"Native Renderer");
    NativeGpuSync_RunInterruptsOnThisThread();
    Sampler_PinRenderThread(GetCurrentThreadId());  // the profiler samples the renderer from now on
    for (;;) {
      size_t n;
      {
        std::unique_lock<std::mutex> l(mutex_);
        if (!pending_used_) {
          sleeping_.store(true, std::memory_order_release);
          work_cv_.wait(l, [&] { return pending_used_ > 0; });
          sleeping_.store(false, std::memory_order_release);
        }
        std::swap(pending_, running_);
        n = pending_used_;
        pending_used_ = 0;
      }
      auto t0 = std::chrono::steady_clock::now();
      for (size_t i = 0; i < n; ++i) ExecuteCmd(running_[i]);
      busy_us_.fetch_add(uint64_t(std::chrono::duration_cast<std::chrono::microseconds>(
                                      std::chrono::steady_clock::now() - t0)
                                      .count()),
                         std::memory_order_relaxed);
    }
  }
  bool active_ = false;
  // (Never released: at process exit the kernel is gone before static destructors run.)
  rex::system::object_ref<rex::system::XHostThread>* thread_ = nullptr;
  std::mutex mutex_;
  std::condition_variable work_cv_;
  std::vector<Cmd> pending_, running_;
  size_t pending_used_ = 0;
  Cmd inline_;
  uint64_t frames_queued_ = 0;
  std::atomic<uint64_t> frames_done_{0};
  std::mutex done_mutex_;
  std::condition_variable done_cv_;
  std::atomic<uint64_t> busy_us_{0};
  std::atomic<bool> sleeping_{false};
  std::atomic<int> lockstep_frames_{0};
};
RenderThread g_rt;
std::atomic<uint64_t> g_lockstep_swaps{0};  // swaps that waited for the renderer (video lockstep)
uint32_t g_record_seq = 0;  // call sequence number on the recording side (trace correlation)
std::vector<uint8_t> g_worker_device(native::dev::kSize);  // the renderer thread's device view
// The recording side's copy of what the renderer thread's view will be once the commands recorded
// so far have executed (the base the snapshot deltas are taken against).
std::vector<uint8_t> g_record_device(native::dev::kSize);

void CaptureObject(Cmd& c, uint32_t addr) {
  if (!addr) return;
  const uint8_t* p = g.mem->Virtual(addr, 64);
  if (!p) return;
  size_t n = c.objects.size();
  c.objects.resize(n + 68);
  std::memcpy(&c.objects[n], &addr, 4);
  std::memcpy(&c.objects[n + 4], p, 64);
}

constexpr uint32_t kDeviceReadEnd = native::dev::kVertexShader + 8;  // last device field the renderer reads

void SnapshotDevice(Cmd& c, const uint8_t* d) {
  using namespace native::dev;
  c.objects.clear();
  for (uint32_t i = 0; i < 4; ++i) CaptureObject(c, BE32(d + kRenderTargets + i * 4));
  CaptureObject(c, BE32(d + kDepthStencil));
  CaptureObject(c, BE32(d + kIndexBuffer));
  c.delta.clear();
  uint8_t* rec = g_record_device.data();
  auto diff = [&](uint32_t begin, uint32_t end) {
    for (uint32_t off = begin; off < end; off += 64) {
      uint32_t n = std::min<uint32_t>(64, end - off);
      if (std::memcmp(rec + off, d + off, n) == 0) continue;
      std::memcpy(rec + off, d + off, n);
      size_t at = c.delta.size();
      c.delta.resize(at + 4 + n);
      c.delta[at] = uint8_t(off);
      c.delta[at + 1] = uint8_t(off >> 8);
      c.delta[at + 2] = uint8_t(n);
      c.delta[at + 3] = 0;
      std::memcpy(&c.delta[at + 4], d + off, n);
    }
  };
  diff(0, 48);
  diff(kFetchConstants, kVsFloatConstants);
  diff(kBoolLoopConstants, kDeviceReadEnd);
  c.groups.clear();
  for (uint32_t bank = 0; bank < 2; ++bank) {
    uint64_t mask = (uint64_t(BE32(d + bank * 8)) << 32) | BE32(d + bank * 8 + 4);
    uint32_t base_off = bank ? kPsFloatConstants : kVsFloatConstants;
    while (mask) {
      uint32_t group = uint32_t(__builtin_clzll(mask));
      mask &= ~(1ull << (63 - group));
      uint32_t off = base_off + group * 64;
      c.groups.push_back(uint8_t(off));
      c.groups.push_back(uint8_t(off >> 8));
      c.groups.insert(c.groups.end(), d + off, d + off + 64);
    }
  }
}

const uint8_t* ApplyDevice(const Cmd& c) {
  using namespace native::dev;
  uint8_t* w = g_worker_device.data();
  for (size_t i = 0; i + 4 <= c.delta.size();) {
    uint32_t off = c.delta[i] | (uint32_t(c.delta[i + 1]) << 8), n = c.delta[i + 2];
    std::memcpy(w + off, &c.delta[i + 4], n);
    i += 4 + n;
  }
  for (size_t i = 0; i + 66 <= c.groups.size(); i += 66) {
    uint32_t off = c.groups[i] | (uint32_t(c.groups[i + 1]) << 8);
    std::memcpy(w + off, &c.groups[i + 2], 64);
  }
  return w;
}

void RecordDraw(const uint8_t* device, const native::ShaderState& shaders, const native::DrawArgs& a) {
  Cmd& c = g_rt.Begin(Cmd::kDraw);
  SnapshotDevice(c, device);
  c.shaders = shaders;
  c.draw = a;
  c.up_vertex.clear();
  c.up_index.clear();
  if (a.up_vertex_fetch) {
    // Immediate-mode data lives in the command buffer, reused once the GPU is past it: copy it.
    if (const uint8_t* q = g.mem->Physical(a.up_vertex_physical & 0x1FFFFFFF, a.up_vertex_bytes))
      c.up_vertex.assign(q, q + a.up_vertex_bytes);
    if (a.kind == native::DrawArgs::kIndexed && a.index_physical) {
      uint32_t isz = a.index_32bit ? 4 : 2;
      if (const uint8_t* q = g.mem->Physical((a.index_physical + a.start * isz) & 0x1FFFFFFF, a.count * isz))
        c.up_index.assign(q, q + a.count * isz);
    }
  }
  c.seq = g_record_seq;
  g_rt.End();
}

void RecordConstants(uint32_t reg, const uint32_t* values, uint32_t count) {
  Cmd& c = g_rt.Begin(Cmd::kConst);
  c.reg = reg;
  c.values.assign(values, values + count);
  g_rt.End();
}

void RecordFetchConstant(uint32_t reg, uint32_t value, const uint8_t* device_be) {
  if (reg < 0x4800 || reg >= 0x48C0) return;
  Cmd& c = g_rt.Begin(Cmd::kFetch);
  c.reg = reg;
  c.values.assign(1, value);
  c.shadow = BE32(device_be + native::dev::kFetchConstants + (reg - 0x4800) * 4);
  g_rt.End();
}

uint64_t g_cmd_us[8] = {};  // renderer thread time per command type (statistics)

void ExecuteCmdTimed(Cmd& c);

double TscPerMicrosecond() {
  static const double value = [] {
    LARGE_INTEGER f, a, b;
    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&a);
    uint64_t t0 = __rdtsc();
    Sleep(20);
    QueryPerformanceCounter(&b);
    uint64_t t1 = __rdtsc();
    return double(t1 - t0) / (double(b.QuadPart - a.QuadPart) * 1e6 / double(f.QuadPart));
  }();
  return value;
}

uint64_t g_cmd_ticks[8] = {};

void ExecuteCmd(Cmd& c) {
  uint64_t t0 = __rdtsc();
  ExecuteCmdTimed(c);
  g_cmd_ticks[c.type] += __rdtsc() - t0;
  g_cmd_us[c.type] = uint64_t(double(g_cmd_ticks[c.type]) / TscPerMicrosecond());
}

void ExecuteCmdTimed(Cmd& c) {
  auto& R = *g.renderer;
  auto& mem = *g_wmem;
  if (!c.objects.empty()) g_wmem->Apply(c.objects);
  switch (c.type) {
    case Cmd::kDraw: {
      R.debug_seq = c.seq;
      native::DrawArgs a = c.draw;
      a.up_vertex_data = c.up_vertex.empty() ? nullptr : c.up_vertex.data();
      a.up_index_data = c.up_index.empty() ? nullptr : c.up_index.data();
      R.Draw(mem, ApplyDevice(c), c.shaders, a);
      break;
    }
    case Cmd::kClear:
      R.debug_seq = c.seq;
      R.Clear(mem, ApplyDevice(c), c.clear);
      break;
    case Cmd::kResolve:
      R.debug_seq = c.seq;
      R.Resolve(mem, ApplyDevice(c), c.resolve);
      break;
    case Cmd::kConst:
      R.WriteConstants(c.reg, c.values.data(), uint32_t(c.values.size()));
      break;
    case Cmd::kFetch:
      R.WriteFetchConstant(c.reg, c.values[0], c.shadow);
      break;
    case Cmd::kShaders:
      R.LoadShadersWithFlow(mem, c.vs_obj, c.ps_obj, c.has_flow ? c.flow : nullptr);
      break;
    case Cmd::kGpuSync:
      NativeGpuSync_Execute(c.values, c.reg);
      break;
    case Cmd::kCall:
      if (c.fn) c.fn();
      c.fn = nullptr;
      break;
  }
}

LONG WINAPI NativeCrashFilter(EXCEPTION_POINTERS* info);

bool Initialize() {
  auto* rt = rex::Runtime::instance();
  auto* gs = rt ? static_cast<rex::graphics::GraphicsSystem*>(rt->graphics_system()) : nullptr;
  auto* provider = gs ? dynamic_cast<rex::ui::d3d12::D3D12Provider*>(gs->provider()) : nullptr;
  if (!provider || !Mem()) {
    REXLOG_ERROR("native renderer: no D3D12 provider - falling back to the emulated GPU");
    return false;
  }
  g.renderer = std::make_unique<native::Renderer>();
  if (!g.renderer->Initialize(provider->GetDevice(), provider->GetDirectQueue())) {
    REXLOG_ERROR("native renderer: initialization failed - falling back to the emulated GPU");
    g.renderer.reset();
    return false;
  }
  g.mem = std::make_unique<LiveMemory>(*Mem());
  g.shared = std::make_unique<NativeSharedMemory>(*Mem(), *g.renderer);
  g.mem->set_shared(g.shared.get());
  g.mem->set_renderer(g.renderer.get());
  g_wmem = std::make_unique<WorkerMemory>(*g.mem);
  // Pipelines compile in the background and persist across runs (no hitches when new areas stream in).
  g.renderer->async_pipelines = REXCVAR_GET(native_async_pipelines);
  g.renderer->pipeline_wait_ms = float(REXCVAR_GET(native_pipeline_wait_ms));
  {
    auto cache = rex::filesystem::GetExecutableFolder() / "cache";
    std::error_code ec;
    std::filesystem::create_directories(cache, ec);
    g.renderer->SetPipelineCache((cache / "native_pipelines.bin").string());
  }
  g.device.resize(native::dev::kSize);
  // The command processor now only services synchronization; host occlusion queries need the
  // emulated draws, so queries report the fake "visible" sample count.
  rex::cvar::SetFlagByName("gpu_native_frontend", "true");
  rex::cvar::SetFlagByName("occlusion_query_enable", "false");
  // The renderer answers the game's occlusion queries (see OnQueryEvent): the command processor must
  // not write its placeholder counts into the result structs.
  if (REXCVAR_GET(native_occlusion_queries)) rex::cvar::SetFlagByName("query_occlusion_fake_sample_count", "-1");
  g.renderer->BeginFrame();
  SetUnhandledExceptionFilter(NativeCrashFilter);
  NativeGpuSync_Start();
  if (REXCVAR_GET(native_render_thread) && !REXCVAR_GET(native_occlusion_queries)) {
    g_rt.Start();
    REXLOG_INFO("native renderer: running on its own thread");
  }
  REXLOG_INFO("native renderer: active (emulated GPU drawing disabled)");
  return true;
}

void LogRejectedLoad(const char* what, uint32_t header, uint32_t w1, uint32_t dwords) {
  static std::atomic<uint32_t> n{0};
  if (n.fetch_add(1) < 16)
    REXLOG_WARN("native renderer: rejected {} packet (header {:08X}, {:08X}, {} dwords)", what, header, w1, dwords);
}

// Parses command bytes the game's D3D code wrote, in order: bin mask (predicated tiling), shader
// microcode loads, and - when `constants` - constant loads that apply to tile 0. Returns true if a
// predicated constant load in them belongs to another tile only.
// ---------------------------------------------------------------------------------------------
// Occlusion queries. The game brackets draws with EVENT_WRITE_ZPD packets (RB_SAMPLE_COUNT_ADDR =
// its xe_gpu_depth_sample_counts struct); D3D marks a query ended by writing 0xFFFFFEED into it and
// the GPU replaces that with the sample counts. The renderer runs a host occlusion query over the
// bracketed draws; a background thread writes the count into the struct once the GPU has passed the
// query's fence, so nothing waits on the GPU mid-frame. (The command processor's placeholder counts
// are switched off in native mode; it would otherwise report every query as visible.)
struct PendingQuery {
  uint32_t address, index;
  uint64_t fence;
};
// (never destroyed: the render thread can still execute commands while the process exits and the static
// destructors have run - notifying a destroyed condition variable crashed on closing, 2026-10-06)
std::mutex& g_query_mutex = *new std::mutex;
std::condition_variable& g_query_cv = *new std::condition_variable;
std::deque<PendingQuery>& g_query_pending = *new std::deque<PendingQuery>;
uint32_t g_sample_count_addr = 0;
uint32_t g_active_query_addr = 0, g_active_query_index = UINT32_MAX;

void WriteQueryResult(uint32_t address, uint64_t samples) {
  uint8_t* p = g.mem ? const_cast<uint8_t*>(g.mem->Physical(address, 32)) : nullptr;
  if (!p) return;
  uint32_t v[8] = {};
  v[0] = v[4] = samples > 0xFFFFFFFFull ? 0xFFFFFFFFu : uint32_t(samples);  // Total_A, ZPass_A (little-endian)
  std::memcpy(p, v, 32);
}

void QueryThread() {
  HANDLE event = CreateEvent(nullptr, FALSE, FALSE, nullptr);
  for (;;) {
    PendingQuery q;
    {
      std::unique_lock<std::mutex> lock(g_query_mutex);
      g_query_cv.wait(lock, [] { return !g_query_pending.empty(); });
      q = g_query_pending.front();
    }
    g.renderer->WaitFence(q.fence, event);
    uint64_t samples = 0;
    if (!g.renderer->OcclusionQueryResult(q.index, q.fence, &samples)) samples = 1000;
    WriteQueryResult(q.address, samples);
    std::lock_guard<std::mutex> lock(g_query_mutex);
    g_query_pending.pop_front();
  }
}

bool QueryEnded(uint32_t address) {
  const uint8_t* p = g.mem->Physical(address, 32);
  if (!p) return false;
  for (uint32_t off : {8u, 12u, 16u, 20u})  // ZFail_A/B, ZPass_A/B
    if (p[off] == 0xFF && p[off + 1] == 0xFF && p[off + 2] == 0xFE && p[off + 3] == 0xED) return true;
  return false;
}

// Each query has two structs: ZPD at the begin struct (counts snapshot at the start) and later at the
// end struct, which D3D marks with 0xFFFFFEED when it issues the end; the game takes end - begin. So
// a begin zeroes its struct and starts a host query over the following draws, and an end writes the
// host count into its struct (from the query thread, once the GPU is done).
void OnQueryEvent() {
  uint32_t address = g_sample_count_addr & 0x1FFFFFFF;
  if (!address) return;
  if (!REXCVAR_GET(native_occlusion_queries)) return;  // the command processor reports them visible
  // Begin structs sit at +0x20 in each query's 64-byte block, end structs at +0 (D3D marks the end
  // struct with 0xFFFFFEED, but not necessarily before this parse).
  bool is_end = !(address & 0x20) || QueryEnded(address);
  if (is_end) {
    if (g_active_query_index == UINT32_MAX) {
      WriteQueryResult(address, 1000);  // no begin seen (e.g. before the renderer started): visible
      return;
    }
    uint32_t index = g_active_query_index;
    g_active_query_index = UINT32_MAX;
    uint64_t fence = g.renderer->EndOcclusionQuery(index);
    if (!fence) {
      WriteQueryResult(address, 1000);
      return;
    }
    static bool thread_started = false;
    if (!thread_started) {
      thread_started = true;
      std::thread(QueryThread).detach();
    }
    std::lock_guard<std::mutex> lock(g_query_mutex);
    g_query_pending.push_back({address, index, fence});
    g_query_cv.notify_one();
    return;
  }
  // Begin: the snapshot at the start of the query is zero (the host query counts from here).
  WriteQueryResult(address, 0);
  if (g_active_query_index != UINT32_MAX) g.renderer->EndOcclusionQuery(g_active_query_index);  // unpaired
  g_active_query_index = g.renderer->BeginOcclusionQuery();
  g_active_query_addr = address;
}

bool ParseCommands(const uint8_t* p, size_t n_bytes, LoadedShaders& loads, bool constants,
                   const uint8_t* device_be = nullptr, bool events = false) {
  auto& m = *g.mem;
  bool excluded = false;
  size_t n = n_bytes / 4;
  for (size_t i = 0; i < n;) {
    uint32_t h = BE32(p + i * 4), type = h >> 30;
    if (type == 0) {
      // Register writes; fetch constants the game writes directly bypass the device shadow.
      uint32_t cnt = ((h >> 16) & 0x3FFF) + 1, base = h & 0x7FFF;
      bool one_reg = (h >> 15) & 1;
      if (events)
        for (uint32_t k = 0; k < cnt && i + 1 + k < n; ++k)
          if ((one_reg ? base : base + k) == 0x2325) g_sample_count_addr = BE32(p + (i + 1 + k) * 4);  // RB_SAMPLE_COUNT_ADDR
      if (device_be)
        for (uint32_t k = 0; k < cnt && i + 1 + k < n; ++k) {
          uint32_t r = one_reg ? base : base + k;
          if (r >= 0x4800 && r < 0x48C0) {
            RecordFetchConstant(r, BE32(p + (i + 1 + k) * 4), device_be);
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
    bool other_tile = (h & 1) && !(g.bin_mask & 3u);
    if (op == 0x5B && events && !other_tile) {  // EVENT_WRITE_ZPD: occlusion query begin / end
      OnQueryEvent();
    } else if (op == 0x60 && i + 1 < n) {
      g.bin_mask = BE32(p + (i + 1) * 4);
    } else if (op == 0x27 && i + 2 < n) {  // IM_LOAD: address | type, start << 16 | size
      uint32_t w1 = BE32(p + (i + 1) * 4), dwords = BE32(p + (i + 2) * 4) & 0xFFFF;
      // (Xenos instruction memory: 4096 instructions of 3 dwords; e.g. Fable II's snow vertex shader is
      // 1899 dwords, so a smaller limit drops real loads and the draw runs with the previous shader.)
      if (count != 2 || (w1 & 3) > 1 || !dwords || dwords > 3 * 4096 || (w1 & ~3u) >= 0x20000000u) {
        LogRejectedLoad("IM_LOAD", h, w1, dwords);
      } else if (const uint8_t* src = m.Physical(w1 & ~3u, dwords * 4)) {
        ((w1 & 3) == 0 ? loads.vs : loads.ps) = InternUcode(src, dwords);
      }
    } else if (op == 0x2B && i + 2 < n) {  // IM_LOAD_IMMEDIATE: type, start << 16 | size, code
      uint32_t w1 = BE32(p + (i + 1) * 4);
      uint32_t dwords = BE32(p + (i + 2) * 4) & 0xFFFF;
      if (w1 > 1 || !dwords || dwords + 2 != count || i + 3 + dwords > n) {
        LogRejectedLoad("IM_LOAD_IMMEDIATE", h, w1, dwords);
      } else {
        (w1 == 0 ? loads.vs : loads.ps) = InternUcode(p + (i + 3) * 4, dwords);
      }
    } else if (op == 0x2D && i + 1 < n && count >= 2 && ((BE32(p + (i + 1) * 4) >> 16) & 0xFF) == 1) {
      if (!other_tile && device_be && i + 1 + count <= n) {  // SET_CONSTANT into fetch constants
        uint32_t reg = 0x4800 + (BE32(p + (i + 1) * 4) & 0x7FF);
        for (uint32_t k = 0; k + 1 < count; ++k) RecordFetchConstant(reg + k, BE32(p + (i + 2 + k) * 4), device_be);
      }
    } else if (op == 0x2F || op == 0x2D) {
      if (other_tile) {
        excluded = true;
      } else if (constants) {
        auto base_for = [](uint32_t offset_type) -> uint32_t {
          uint32_t index = offset_type & 0x7FF, t = (offset_type >> 16) & 0xFF;
          return t == 0 ? 0x4000 + index : t == 2 ? 0x4900 + index : t == 3 ? 0x4908 + index : 0;
        };
        if (op == 0x2F && i + 3 < n) {  // LOAD_ALU_CONSTANT
          uint32_t addr = BE32(p + (i + 1) * 4) & 0x3FFFFFFF, reg = base_for(BE32(p + (i + 2) * 4));
          uint32_t dwords = BE32(p + (i + 3) * 4) & 0xFFF;
          const uint8_t* src = m.Physical(addr, dwords * 4);
          if (reg && src) {
            std::vector<uint32_t> v(dwords);
            for (uint32_t k = 0; k < dwords; ++k) v[k] = BE32(src + k * 4);
            RecordConstants(reg, v.data(), dwords);
          }
        } else if (op == 0x2D && i + 1 < n && count >= 2 && i + 1 + count <= n) {  // SET_CONSTANT
          uint32_t reg = base_for(BE32(p + (i + 1) * 4));
          if (reg) {
            std::vector<uint32_t> v(count - 1);
            for (uint32_t k = 0; k + 1 < count; ++k) v[k] = BE32(p + (i + 2 + k) * 4);
            RecordConstants(reg, v.data(), count - 1);
          }
        }
      }
    }
    i += 1 + count;
  }
  return excluded;
}

void Attach(native::DrawArgs& a, const LoadedShaders& l) {
  if (!l.vs.empty()) a.vs_ucode = l.vs.data, a.vs_ucode_dwords = l.vs.dwords, a.vs_hash = l.vs.hash;
  if (!l.ps.empty()) a.ps_ucode = l.ps.data, a.ps_ucode_dwords = l.ps.dwords, a.ps_hash = l.ps.hash;
}

void FlushPendingUP() {
  if (!g.pending_up) return;
  g.pending_up = false;
  if (g.up_args.kind == native::DrawArgs::kIndexed && !g.up_args.index_physical) return;
  Attach(g.up_args, g.up_shaders);
  RecordDraw(g.up_device.data(), g.shaders, g.up_args);
}

void Present(uint32_t frontbuffer_texture) {
  auto* rt = rex::Runtime::instance();
  auto* gs = rt ? static_cast<rex::graphics::GraphicsSystem*>(rt->graphics_system()) : nullptr;
  auto* presenter = gs ? gs->presenter() : nullptr;
  if (!presenter || !frontbuffer_texture) return;
  const uint8_t* f = g.mem->Virtual(frontbuffer_texture + 28, 24);
  if (!f) return;
  uint32_t base = (BE32(f + 4) >> 12) << 12;
  if (base >= 0xA0000000) base = native::GuestMemory::VirtualToPhysical(base);
  ID3D12Resource* tex = g.renderer->GetResolvedTexture(base);
  if (!tex) return;
  D3D12_RESOURCE_DESC d = tex->GetDesc();
  uint32_t w = uint32_t(d.Width), h = d.Height;
  presenter->RefreshGuestOutput(w, h, 16, 9, [&](rex::ui::Presenter::GuestOutputRefreshContext& context) -> bool {
    auto& d3d12_context = static_cast<rex::ui::d3d12::D3D12Presenter::D3D12GuestOutputRefreshContext&>(context);
    context.SetIs8bpc(true);
    return g.renderer->PresentFrontbuffer(base, d3d12_context.resource_uav_capable(),
                                          rex::ui::d3d12::D3D12Presenter::kGuestOutputInternalState);
  });
}

// Frame-end diagnostics: device removal, and (with the SDK's d3d12_debug layer on) the debug
// layer's messages, deduplicated, so invalid API use shows up in the log instead of as a driver crash.
void CheckDevice() {
  auto* rt = rex::Runtime::instance();
  auto* gs = rt ? static_cast<rex::graphics::GraphicsSystem*>(rt->graphics_system()) : nullptr;
  auto* provider = gs ? dynamic_cast<rex::ui::d3d12::D3D12Provider*>(gs->provider()) : nullptr;
  if (!provider) return;
  ID3D12Device* device = provider->GetDevice();
  HRESULT removed = device->GetDeviceRemovedReason();
  if (FAILED(removed)) {
    static bool logged = false;
    if (!logged) {
      logged = true;
      REXLOG_ERROR("native renderer: D3D12 device removed ({:08X}) at frame {}", uint32_t(removed), g.frames);
    }
  }
  Microsoft::WRL::ComPtr<ID3D12InfoQueue> iq;
  if (FAILED(device->QueryInterface(IID_PPV_ARGS(&iq)))) return;
  static std::unordered_map<std::string, uint64_t> seen;
  for (UINT64 i = 0, n = iq->GetNumStoredMessages(); i < n; ++i) {
    SIZE_T len = 0;
    iq->GetMessage(i, nullptr, &len);
    std::vector<uint8_t> buf(len);
    auto* msg = reinterpret_cast<D3D12_MESSAGE*>(buf.data());
    if (FAILED(iq->GetMessage(i, msg, &len)) || msg->Severity > D3D12_MESSAGE_SEVERITY_WARNING) continue;
    std::string text(msg->pDescription, std::min<size_t>(msg->DescriptionByteLength, 500));
    if (seen[text]++ == 0) REXLOG_WARN("native renderer: [d3d12] {}", text);
  }
  iq->ClearStoredMessages();
}

// Last-resort crash handler (installed while the native renderer is active): logs the D3D12 debug
// layer's pending messages (with d3d12_debug=true and d3d12_break_on_error=true the invalid call
// itself raises the exception) and writes fable2_native_crash.dmp next to the executable.
LONG WINAPI NativeCrashFilter(EXCEPTION_POINTERS* info) {
  static std::atomic<bool> once{false};
  if (once.exchange(true)) return EXCEPTION_CONTINUE_SEARCH;
  REXLOG_ERROR("native renderer: unhandled exception {:08X} at {}", uint32_t(info->ExceptionRecord->ExceptionCode),
               info->ExceptionRecord->ExceptionAddress);
  auto* rt = rex::Runtime::instance();
  auto* gs = rt ? static_cast<rex::graphics::GraphicsSystem*>(rt->graphics_system()) : nullptr;
  auto* provider = gs ? dynamic_cast<rex::ui::d3d12::D3D12Provider*>(gs->provider()) : nullptr;
  Microsoft::WRL::ComPtr<ID3D12InfoQueue> iq;
  if (provider && SUCCEEDED(provider->GetDevice()->QueryInterface(IID_PPV_ARGS(&iq)))) {
    UINT64 n = iq->GetNumStoredMessages();
    for (UINT64 i = n > 20 ? n - 20 : 0; i < n; ++i) {
      SIZE_T len = 0;
      iq->GetMessage(i, nullptr, &len);
      std::vector<uint8_t> buf(len);
      auto* msg = reinterpret_cast<D3D12_MESSAGE*>(buf.data());
      if (SUCCEEDED(iq->GetMessage(i, msg, &len)))
        REXLOG_ERROR("native renderer: [d3d12] {}", std::string(msg->pDescription, msg->DescriptionByteLength));
    }
  }
  wchar_t path[MAX_PATH];
  DWORD n = GetModuleFileNameW(nullptr, path, MAX_PATH);
  while (n && path[n - 1] != L'\\') --n;
  wcscpy_s(path + n, MAX_PATH - n, L"fable2_native_crash.dmp");
  HANDLE file = CreateFileW(path, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
  if (file != INVALID_HANDLE_VALUE) {
    MINIDUMP_EXCEPTION_INFORMATION mei{GetCurrentThreadId(), info, FALSE};
    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file,
                      MINIDUMP_TYPE(MiniDumpWithThreadInfo | MiniDumpWithIndirectlyReferencedMemory), &mei, nullptr,
                      nullptr);
    CloseHandle(file);
    REXLOG_ERROR("native renderer: crash dump written to fable2_native_crash.dmp");
  }
  return EXCEPTION_CONTINUE_SEARCH;
}

bool Active() {
  if (!REXCVAR_GET(native_renderer) || g.failed) return false;
  if (!g.initialized) {
    g.initialized = true;
    if (!Initialize()) {
      g.failed = true;
      return false;
    }
  }
  return true;
}

}  // namespace

bool NativeFrontend_Active() { return Active(); }

namespace {
// GPU sync points submitted inside a hooked D3D call (the call kicked its own command buffer off):
// queued after the call's own commands, which are recorded when it returns - the renderer must have
// executed a draw before the fences covering it pass.
std::vector<std::pair<std::vector<uint32_t>, uint32_t>> g_syncs_in_call;
bool InCallOnThisThread();

void QueueSync(std::vector<uint32_t>& commands, uint32_t write_index) {
  Cmd& c = g_rt.Begin(Cmd::kGpuSync);
  c.values.swap(commands);
  c.reg = write_index;
  g_rt.End();
}

void FlushSyncsInCall() {
  for (auto& [commands, index] : g_syncs_in_call) QueueSync(commands, index);
  g_syncs_in_call.clear();
}
}  // namespace

bool NativeFrontend_QueueGpuSync(std::vector<uint32_t>& commands, uint32_t write_index) {
  if (!g_rt.active()) return false;
  if (InCallOnThisThread()) {
    g_syncs_in_call.emplace_back(std::move(commands), write_index);
    return true;
  }
  QueueSync(commands, write_index);
  return true;
}
bool NativeFrontend_SkipStateFlush() { return Active() && REXCVAR_GET(native_skip_d3d_flush); }

namespace {
uint64_t g_segment_switches = 0;  // command buffer segment switches seen (sub_821E8D20)
uint64_t g_hook_us = 0;
uint64_t g_hook_fn_us[64] = {};  // After-hook time per D3D function
uint64_t g_before_us = 0;        // Before-hook time (gap parsing, pending UP draws, device snapshot)  // time spent inside the native frontend's hooks (serialized by g_call_mutex)
std::atomic<bool> g_snapshot_requested{false};
uint32_t g_snapshot_count = 0;

// Saves the presented frame to native_snapshots/<n>.png (F10, and automatically now and then).
void SaveSnapshot(uint32_t frontbuffer_texture, const std::filesystem::path* burst_dir = nullptr) {
  const uint8_t* f = g.mem->Virtual(frontbuffer_texture + 28, 24);
  if (!f) return;
  uint32_t base = (BE32(f + 4) >> 12) << 12;
  if (base >= 0xA0000000) base = native::GuestMemory::VirtualToPhysical(base);
  ID3D12Resource* tex = g.renderer->GetResolvedTexture(base);
  if (!tex) return;
  std::vector<uint8_t> rgba;
  uint32_t w = 0, h = 0;
  if (!g.renderer->ReadbackRGBA8(tex, &rgba, &w, &h)) return;
  bool swapped = g.renderer->IsResolvedRedBlueSwapped(base);
  for (size_t i = 0; i + 3 < rgba.size(); i += 4) {
    if (swapped) std::swap(rgba[i], rgba[i + 2]);
    rgba[i + 3] = 255;
  }
  auto dir = burst_dir ? *burst_dir : rex::filesystem::GetExecutableFolder() / "native_snapshots";
  std::error_code ec;
  std::filesystem::create_directories(dir, ec);
  auto path = dir / fmt::format("frame_{:06}.png", g.frames);
  native::WritePng(path.string(), rgba.data(), w, h);
  if (!burst_dir) REXLOG_INFO("native renderer: snapshot {}", path.string());
}
}  // namespace

// Frame trace (F10): the renderer's debug trace (draws, resolves, clears, texture bindings) of one
// whole frame, written to native_snapshots/trace_<frame>.txt by pointing stderr at that file.
namespace {
int g_trace_fd_saved = -1;
int g_trace_frames_left = 0;
FILE* g_trace_file = nullptr;

void StartFrameTrace() {
  auto dir = rex::filesystem::GetExecutableFolder() / "native_snapshots";
  std::error_code ec;
  std::filesystem::create_directories(dir, ec);
  auto path = dir / fmt::format("trace_{:06}.txt", g.frames);
  g_trace_file = std::fopen(path.string().c_str(), "w");
  if (!g_trace_file) return;
  g_trace_fd_saved = 1;  // tracing
  g.renderer->debug_trace_file = g_trace_file;
  g.renderer->debug_trace = true;
  REXLOG_INFO("native renderer: tracing frame {} to {}", g.frames, path.string());
}

void StopFrameTrace(uint32_t frontbuffer_texture) {
  g.renderer->debug_trace = false;
  g.renderer->debug_trace_file = nullptr;
  g_trace_fd_saved = -1;
  std::fclose(g_trace_file);
  g_trace_file = nullptr;
  SaveSnapshot(frontbuffer_texture);  // the traced frame
}
}  // namespace

void NativeFrontend_RequestSnapshot() { g_snapshot_requested = true; }

// F6: record every frame for a few seconds - a snapshot and a full trace of each frame - into
// native_snapshots/burst_<frame>/ (frame_N.png is the image the calls in trace_N.txt produced).
namespace {
std::atomic<bool> g_burst_requested{false};
bool g_burst_active = false;
std::chrono::steady_clock::time_point g_burst_end;
std::filesystem::path g_burst_dir;
FILE* g_burst_trace = nullptr;
constexpr int kBurstSeconds = 8;

void BurstFrame(uint32_t frontbuffer_texture) {
  auto& R = *g.renderer;
  if (g_burst_trace) {
    R.debug_trace = false;
    R.debug_trace_file = nullptr;
    std::fclose(g_burst_trace);
    g_burst_trace = nullptr;
    SaveSnapshot(frontbuffer_texture, &g_burst_dir);  // the frame the closed trace describes
  }
  if (g_burst_requested.exchange(false) && !g_burst_active) {
    g_burst_active = true;
    g_burst_end = std::chrono::steady_clock::now() + std::chrono::seconds(kBurstSeconds);
    g_burst_dir = rex::filesystem::GetExecutableFolder() / "native_snapshots" / fmt::format("burst_{:06}", g.frames);
    std::error_code ec;
    std::filesystem::create_directories(g_burst_dir, ec);
    REXLOG_INFO("native renderer: recording every frame for {} s to {}", kBurstSeconds, g_burst_dir.string());
  }
  if (!g_burst_active) return;
  if (std::chrono::steady_clock::now() >= g_burst_end) {
    g_burst_active = false;
    REXLOG_INFO("native renderer: frame recording finished ({})", g_burst_dir.string());
    return;
  }
  // Trace the next frame (g.frames is incremented after this swap).
  g_burst_trace = std::fopen((g_burst_dir / fmt::format("trace_{:06}.txt", g.frames + 1)).string().c_str(), "w");
  if (g_burst_trace) {
    R.debug_trace_file = g_burst_trace;
    R.debug_trace = true;
  }
}
}  // namespace

void NativeFrontend_RequestBurst() { g_burst_requested = true; }

// F6: save the frames of the last few seconds (kept on the GPU every frame at no visible cost, so
// timing-dependent glitches still happen) to native_snapshots/history_<frame>/.
namespace {
std::atomic<bool> g_history_requested{false};

void SaveFrameHistory() {
  auto& R = *g.renderer;
  auto dir = rex::filesystem::GetExecutableFolder() / "native_snapshots" / fmt::format("history_{:06}", g.frames);
  std::error_code ec;
  std::filesystem::create_directories(dir, ec);
  uint32_t saved = 0;
  for (const auto& h : R.FrameHistory()) {
    std::vector<uint8_t> rgba;
    uint32_t w = 0, hgt = 0;
    if (!R.ReadbackRGBA8(h.resource, &rgba, &w, &hgt)) continue;
    for (size_t i = 0; i + 3 < rgba.size(); i += 4) {
      if (h.red_blue_swapped) std::swap(rgba[i], rgba[i + 2]);
      rgba[i + 3] = 255;
    }
    native::WritePng((dir / fmt::format("frame_{:06}.png", h.frame)).string(), rgba.data(), w, hgt);
    ++saved;
  }
  REXLOG_INFO("native renderer: saved the last {} frames to {}", saved, dir.string());
}
}  // namespace

void NativeFrontend_RequestHistory() { g_history_requested = true; }

// F8 (diagnostics): forget everything cached from guest memory - the GPU copy of guest memory is
// re-uploaded on use and textures are decoded again. If missing objects reappear, a CPU write was
// not noticed by the memory watches.
namespace {
std::atomic<bool> g_invalidate_requested{false};
}
void NativeFrontend_RequestInvalidate() { g_invalidate_requested = true; }

namespace {
int g_capture_snapshot_delay = 0;
std::filesystem::path g_capture_snapshot_dir;
}  // namespace

void NativeFrontend_RequestCaptureSnapshot(const std::string& dir) {
  // (Called from the swap's after-hook on the render thread, inside the frontend's call lock.)
  g_capture_snapshot_dir = dir;
  // The capture starts in this swap's after-hook (before the frontend's): this swap ends the frame
  // before the recorded one, the next one (d3d_capture_frames = 1) ends the recorded frame.
  g_capture_snapshot_delay = 2;
}

// The game issues D3D calls from more than one thread (the loading screen renders from its own
// thread). The frontend keeps one device snapshot per call, so a whole call - before hook, the
// original, after hook - is serialized; a thread entering while another is mid-call is logged.
namespace {
std::recursive_mutex g_call_mutex;
std::atomic<uint32_t> g_call_thread{0};
uint32_t g_call_depth = 0;
bool InCallOnThisThread() {
  return g_call_depth > 0 && g_call_thread.load(std::memory_order_acquire) == GetCurrentThreadId();
}
}  // namespace

// Command buffer segment switch (sub_821E8D20, called inside D3D calls or from inlined D3D code when
// the current segment is full): remember the valid end of the old segment, continue at the new one.
void NativeFrontend_SegmentSwitch(uint32_t device, bool after) {
  if (!Active() || !device) return;
  std::lock_guard<std::recursive_mutex> lock(g_call_mutex);
  const uint8_t* d = g.mem->Virtual(device + 48, 4);
  if (!d) return;
  uint32_t put = BE32(d);
  bool in_call = g_call_depth > 0 && g_call_thread.load(std::memory_order_acquire) == GetCurrentThreadId();
  uint32_t& start = in_call ? g.put_before : g.last_put;
  if (!after) {
    ++g_segment_switches;
    if (start && put > start && put - start < (1u << 20)) g.pieces.push_back({start, put});
  } else {
    start = put;
  }
}

void NativeFrontend_Before(int fn, PPCContext& ctx, uint8_t* base) {
  (void)base;
  if (fn == kCommitShaders || fn == kCommitRS || fn == kGameStateFlush || !Active()) return;
  auto hook_t0 = std::chrono::steady_clock::now();
  struct HookTimer {
    std::chrono::steady_clock::time_point t0;
    ~HookTimer() {
      g_hook_us += uint64_t(
          std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
    }
  } hook_timer{hook_t0};
  struct BeforeTimer {
    std::chrono::steady_clock::time_point t0;
    ~BeforeTimer() {
      g_before_us += uint64_t(
          std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
    }
  } before_timer{hook_t0};
  uint32_t tid = GetCurrentThreadId();
  uint32_t owner = g_call_thread.load(std::memory_order_acquire);
  if (owner && owner != tid) {
    static std::atomic<uint32_t> reported{0};
    if (reported.fetch_add(1) < 8)
      REXLOG_WARN("native renderer: D3D call {} on thread {} while thread {} is inside a call - serializing",
                  kFnNames[fn], tid, owner);
  }
  g_call_mutex.lock();
  g_call_thread.store(tid, std::memory_order_release);
  if (++g_call_depth > 1) {
    static bool nested_logged = false;
    if (!nested_logged) {
      nested_logged = true;
      REXLOG_WARN("native renderer: nested hooked D3D call {}", kFnNames[fn]);
    }
  }
  uint32_t dev = ctx.r3.u32;
  const uint8_t* dev_mem = g.mem->Virtual(dev, native::dev::kSize);
  if (!dev_mem) return;
  if (!g.constants_initialized) {
    std::vector<uint8_t> copy(dev_mem, dev_mem + native::dev::kSize);
    std::memcpy(g_record_device.data(), copy.data(), copy.size());  // (delta base == worker view)
    g_rt.Call([copy] {
      g.renderer->InitConstants(copy.data());
      std::memcpy(g_worker_device.data(), copy.data(), copy.size());
    });
    g.constants_initialized = true;
  }
  // Commands the game wrote itself (inlined D3D code) since the previous hooked call.
  uint32_t put = BE32(dev_mem + 48);
  uint32_t gap_size = 0;
  if (const uint8_t* p = GatherCommands(g.last_put, put, &gap_size)) {
    ParseCommands(p, gap_size, g.loaded, true, dev_mem, true);
  } else if (g.last_put && put != g.last_put) {
    ++g.gaps_lost;  // command buffer wrapped between hooked calls: these packets were not seen
  }
  // A Begin*Vertices draw whose data the game has written by now.
  FlushPendingUP();
  {
    // Device snapshot: refresh only what can have changed - everything except the float constants,
    // plus the constant groups the dirty masks (+0 VS, +8 PS; MSB = group 0, 4 vec4 = 64 bytes per
    // group) mark. Copying the whole 16 KB device on every D3D call was ~5% of the render thread.
    static bool snapshot_full = false;
    uint8_t* d = g.device.data();
    if (!snapshot_full) {
      std::memcpy(d, dev_mem, native::dev::kSize);
      snapshot_full = true;
    } else {
      std::memcpy(d, dev_mem, native::dev::kVsFloatConstants);
      for (uint32_t bank = 0; bank < 2; ++bank) {
        uint64_t mask = (uint64_t(BE32(dev_mem + bank * 8)) << 32) | BE32(dev_mem + bank * 8 + 4);
        uint32_t base_off = bank ? native::dev::kPsFloatConstants : native::dev::kVsFloatConstants;
        while (mask) {
          uint32_t group = uint32_t(__builtin_clzll(mask));
          mask &= ~(1ull << (63 - group));
          std::memcpy(d + base_off + group * 64, dev_mem + base_off + group * 64, 64);
        }
      }
      std::memcpy(d + native::dev::kBoolLoopConstants, dev_mem + native::dev::kBoolLoopConstants,
                  kDeviceReadEnd - native::dev::kBoolLoopConstants);  // (nothing past it is read)
    }
  }
  const uint32_t regs[8] = {ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32,
                            ctx.r7.u32, ctx.r8.u32, ctx.r9.u32, ctx.r10.u32};
  std::memcpy(g.r, regs, sizeof(regs));
  g.f1 = ctx.f1.f64;
  g.sp = ctx.r1.u32;
  g.put_before = put;
}

void NativeFrontend_After(int fn, PPCContext& ctx, uint8_t* base) {
  (void)base;
  if (fn == kCommitShaders || fn == kCommitRS || fn == kGameStateFlush || !Active()) return;
  struct HookTimer {
    int fn;
    std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
    ~HookTimer() {
      uint64_t us = uint64_t(
          std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - t0).count());
      g_hook_us += us;
      if (fn >= 0 && fn < 64) g_hook_fn_us[fn] += us;
    }
  } hook_timer{fn};
  struct Unlock {
    ~Unlock() {
      if (--g_call_depth == 0) g_call_thread.store(0, std::memory_order_release);
      g_call_mutex.unlock();
    }
  } unlock;
  auto& mem = *g.mem;
  const uint32_t* r = g.r;
  const uint8_t* dev_before = g.device.data();
  uint32_t put = 0;
  if (const uint8_t* d = mem.Virtual(r[0] + 48, 4)) put = BE32(d);
  // This call's own command bytes: the shaders it loads (for its draw) and whether its constant
  // load belongs to another tile.
  LoadedShaders call_shaders = g.loaded;
  bool excluded_from_tile0 = false;
  uint32_t call_size = 0;
  const uint8_t* call_bytes = GatherCommands(g.put_before, put, &call_size);
  uint32_t mask_before = g.bin_mask;
  // (Also applies the vertex stream fetch constants the call writes before its draw packet.)
  if (call_bytes) excluded_from_tile0 = ParseCommands(call_bytes, call_size, call_shaders, false, dev_before);
  g.bin_mask = mask_before;

  ++g_record_seq;
  switch (fn) {
    case kGpuLoadShaders:
      g.shaders.vertex_shader = r[1];
      g.shaders.pixel_shader = r[2];
      {
        Cmd& c = g_rt.Begin(Cmd::kShaders);
        c.vs_obj = r[1];
        c.ps_obj = r[2];
        const uint8_t* flow = r[3] ? mem.Virtual(r[3], 160) : nullptr;
        c.has_flow = flow != nullptr;
        if (flow) std::memcpy(c.flow, flow, 160);
        g_rt.End();
      }
      break;
    case kGpuLoadConstants:
      if (!excluded_from_tile0) {
        // GpuLoadShaderConstantF4(dev, bank, start, count, buffer, offset): the values now.
        uint32_t src = native::GuestMemory::VirtualToPhysical(mem.Load32(r[4] + 24) + r[5] * 16);
        if (const uint8_t* q = mem.Physical(src, r[3] * 16)) {
          std::vector<uint32_t> v(r[3] * 4);
          for (uint32_t i = 0; i < r[3] * 4; ++i) v[i] = BE32(q + i * 4);
          RecordConstants(0x4000 + ((r[1] << 8) + r[2]) * 4, v.data(), r[3] * 4);
        }
      }
      break;
    case kDrawIndexed:
    case kDrawIndexed2:
    case kDraw:
    case kDrawRect2D: {
      native::DrawArgs a;
      a.prim = r[1];
      if (fn == kDrawIndexed) {
        a.kind = native::DrawArgs::kIndexed;
        a.base_vertex = r[2];
        a.start = r[3];
        a.count = r[4];
      } else if (fn == kDrawIndexed2) {  // DrawIndexedTessellatedPrimitive
        a.kind = native::DrawArgs::kIndexed;
        a.tessellated = true;
        a.start = r[3];
        a.count = r[4];
      } else if (fn == kDraw) {  // start vertex goes to VGT_INDX_OFFSET
        a.kind = native::DrawArgs::kAuto;
        a.base_vertex = r[2];
        a.count = r[3];
      } else {  // DrawTessellatedPrimitive
        a.kind = native::DrawArgs::kAuto;
        a.tessellated = true;
        a.base_vertex = r[2];
        a.count = r[3];
      }
      Attach(a, call_shaders);
      RecordDraw(dev_before, g.shaders, a);
      break;
    }
    case kBeginIndexedUP:
    case kBeginUP: {
      native::DrawArgs a;
      a.prim = r[1];
      a.up_vertex_fetch = true;
      uint32_t vtx = 0, vtx_bytes = 0;
      if (fn == kBeginIndexedUP) {
        if (ctx.r3.u32 != 0) break;  // failed
        a.kind = native::DrawArgs::kIndexed;
        a.base_vertex = r[2];
        a.count = r[4];
        a.index_32bit = (r[5] & 4) != 0;
        uint32_t idx_ptr = 0;
        if (const uint8_t* q = mem.Virtual(r[7], 4)) idx_ptr = BE32(q);                 // *ppIndexData (r10)
        if (const uint8_t* q = mem.Virtual(g.sp + 84, 4))                                // ppVertexData
          if (const uint8_t* q2 = mem.Virtual(BE32(q), 4)) vtx = BE32(q2);
        vtx_bytes = r[3] * r[6];
        a.index_physical = idx_ptr ? native::GuestMemory::VirtualToPhysical(idx_ptr) : 0;
        // (uploaded when the draw is issued, once the game has written the indices)
      } else {
        vtx = ctx.r3.u32;  // returned vertex pointer
        if (!vtx) break;
        a.kind = native::DrawArgs::kAuto;
        a.count = r[2];
        vtx_bytes = r[2] * r[3];
      }
      a.up_vertex_physical = native::GuestMemory::VirtualToPhysical(vtx);
      a.up_vertex_bytes = vtx_bytes;
      g.up_args = a;
      g.up_device.assign(dev_before, dev_before + native::dev::kSize);
      g.up_shaders = call_shaders;
      g.pending_up = true;
      break;
    }
    case kClear: {
      native::ClearArgs a;
      a.flags = r[1];
      if (const uint8_t* rect = r[2] ? mem.Virtual(r[2], 16) : nullptr) {
        a.has_rect = true;
        a.x1 = int32_t(BE32(rect));
        a.y1 = int32_t(BE32(rect + 4));
        a.x2 = int32_t(BE32(rect + 8));
        a.y2 = int32_t(BE32(rect + 12));
      }
      if (const uint8_t* c = r[3] ? mem.Virtual(r[3], 16) : nullptr)
        for (int i = 0; i < 4; ++i) a.color[i] = BEF(c + i * 4);
      a.z = float(g.f1);
      a.stencil = r[5];
      Cmd& c = g_rt.Begin(Cmd::kClear);
      SnapshotDevice(c, dev_before);
      c.clear = a;
      c.seq = g_record_seq;
      g_rt.End();
      break;
    }
    case kResolve: {
      native::ResolveArgs a;
      a.flags = r[1];
      if (const uint8_t* rect = r[2] ? mem.Virtual(r[2], 16) : nullptr) {
        a.has_source_rect = true;
        a.src_x1 = int32_t(BE32(rect));
        a.src_y1 = int32_t(BE32(rect + 4));
        a.src_x2 = int32_t(BE32(rect + 8));
        a.src_y2 = int32_t(BE32(rect + 12));
      }
      a.dest_texture = r[3];
      if (const uint8_t* pt = r[4] ? mem.Virtual(r[4], 8) : nullptr) {
        a.dest_x = int32_t(BE32(pt));
        a.dest_y = int32_t(BE32(pt + 4));
      }
      a.dest_level = r[5];
      if (const uint8_t* c = r[7] ? mem.Virtual(r[7], 16) : nullptr)
        for (int i = 0; i < 4; ++i) a.clear_color[i] = BEF(c + i * 4);
      a.clear_z = float(g.f1);
      if (const uint8_t* s = mem.Virtual(g.sp + 84, 4)) a.clear_stencil = BE32(s);
      if (call_bytes) a.copy_dest_info = native::FindRegisterWrite(call_bytes, call_size, 0x231B, 0);
      Cmd& c = g_rt.Begin(Cmd::kResolve);
      SnapshotDevice(c, dev_before);
      c.resolve = a;
      CaptureObject(c, a.dest_texture);
      c.seq = g_record_seq;
      g_rt.End();
      break;
    }
    case kSwap: {
      FlushPendingUP();
      // The frame's end runs on the renderer thread, after the frame's draws.
      uint32_t frontbuffer = r[1];
      uint64_t hook_us = g_hook_us, before_us = g_before_us;
      uint64_t hook_fn_us[64];
      std::memcpy(hook_fn_us, g_hook_fn_us, sizeof(hook_fn_us));
      g_rt.Call([frontbuffer, hook_us, before_us, hook_fn_us]() mutable {
      auto& R = *g.renderer;
      auto& mem = *g_wmem;
      const uint32_t r[2] = {0, frontbuffer};
      const uint64_t g_hook_us = hook_us, g_before_us = before_us;
      const uint64_t* g_hook_fn_us = hook_fn_us;
      // F6 history copy, recorded before the present so it goes out in the same submission.
      if (const uint8_t* f = mem.Virtual(r[1] + 28, 24)) {
        uint32_t fb = (BE32(f + 4) >> 12) << 12;
        if (fb >= 0xA0000000) fb = native::GuestMemory::VirtualToPhysical(fb);
        R.PushFrameHistory(fb, g.frames);
      }
      Present(r[1]);
      if (g_history_requested.exchange(false)) SaveFrameHistory();
      if (g_invalidate_requested.exchange(false)) {
        if (g.shared) g.shared->InvalidateAllPages();
        R.DropTextureCache();
        REXLOG_INFO("native renderer: F8 - dropped the guest memory copy and all decoded textures (frame {})", g.frames);
      }
      if (g_capture_snapshot_delay > 0 && --g_capture_snapshot_delay == 0) {
        SaveSnapshot(r[1], &g_capture_snapshot_dir);
        // Every resolved texture of the live frame (shadow maps, depth copies, light / bloom buffers):
        // compared with the replayer's resolved_<base>.png of the same capture to find where the live
        // renderer diverges.
        {
          auto live_dir = g_capture_snapshot_dir / "live";
          std::error_code ec;
          std::filesystem::create_directories(live_dir, ec);
          uint32_t n = 0;
          for (auto& [base, res] : R.ResolvedTextures()) {
            std::vector<uint8_t> rgba;
            uint32_t w = 0, hgt = 0;
            if (!R.ReadbackRGBA8(res, &rgba, &w, &hgt)) continue;
            for (size_t i = 3; i < rgba.size(); i += 4) rgba[i] = 255;
            native::WritePng((live_dir / fmt::format("resolved_{:08X}.png", base)).string(), rgba.data(), w, hgt);
            ++n;
          }
          REXLOG_INFO("native renderer: saved {} live resolved textures to {}", n, live_dir.string());
        }
        REXLOG_INFO("native renderer: saved the live image of the captured frame to {}", g_capture_snapshot_dir.string());
      }
      if (g_burst_active || g_burst_requested.load()) {
        BurstFrame(r[1]);
      } else if (REXCVAR_GET(native_trace_rolling)) {
        // Rolling trace: the file holds this frame's calls; F10 keeps it next to the snapshot.
        auto dir = rex::filesystem::GetExecutableFolder() / "native_snapshots";
        auto rolling = dir / "rolling_trace.txt";
        if (g_trace_file) {
          R.debug_trace = false;
          R.debug_trace_file = nullptr;
          std::fclose(g_trace_file);
          g_trace_file = nullptr;
        }
        if (g_snapshot_requested.exchange(false)) {
          ++g_snapshot_count;
          SaveSnapshot(r[1]);
          std::error_code ec;
          std::filesystem::copy_file(rolling, dir / fmt::format("trace_{:06}_onscreen.txt", g.frames),
                                     std::filesystem::copy_options::overwrite_existing, ec);
          REXLOG_INFO("native renderer: kept trace of on-screen frame {}", g.frames);
        }
        std::error_code ec;
        std::filesystem::create_directories(dir, ec);
        g_trace_file = std::fopen(rolling.string().c_str(), "w");
        if (g_trace_file) {
          R.debug_trace_file = g_trace_file;
          R.debug_trace = true;
        }
      } else if (g_trace_fd_saved >= 0) {
        StopFrameTrace(r[1]);
        if (g_trace_frames_left > 0) {  // F10 traces two consecutive frames (flicker comparison)
          --g_trace_frames_left;
          StartFrameTrace();
        }
      }
      if (g_snapshot_requested.exchange(false)) {
        ++g_snapshot_count;
        SaveSnapshot(r[1]);
        g_trace_frames_left = 1;
        StartFrameTrace();  // F10: also trace the next frames' calls
      }
      R.state_cache = REXCVAR_GET(native_state_cache);
      R.realtime_depth_passes = REXCVAR_GET(native_realtime_shadows);
      native::Renderer::EnableDrawProfile(REXCVAR_GET(native_draw_profile));
      {
        // Hitch attribution: frames where the renderer took long, and what it was creating.
        static uint64_t last_cmd_total = 0;
        static native::Stats lf{};
        uint64_t cmd_total = 0;
        for (uint64_t v : g_cmd_us) cmd_total += v;
        const auto& st = R.stats();
        uint64_t frame_us = cmd_total - last_cmd_total;
        static auto last_frame_end = std::chrono::steady_clock::now();
        auto frame_end = std::chrono::steady_clock::now();
        double wall_ms = std::chrono::duration<double, std::milli>(frame_end - last_frame_end).count();
        last_frame_end = frame_end;
        if (last_cmd_total && frame_us <= 50000 && wall_ms > 80)
          REXLOG_INFO("native renderer hitch: frame {} took {:.1f} ms but the renderer only {:.1f} ms (the game's own "
                      "work, or waits)", g.frames, wall_ms, frame_us / 1000.0);
        if (last_cmd_total && frame_us > 50000) {
          REXLOG_INFO("native renderer hitch: frame {} renderer {:.1f} ms | shaders translated {} ({:.1f} ms), pipelines "
                      "{} ({:.1f} ms), textures created {} / re-uploaded {} (decode+upload {:.1f} ms), re-hashed {:.1f} "
                      "ms, uploads {} KB, draws {}",
                      g.frames, frame_us / 1000.0, st.shaders_translated - lf.shaders_translated,
                      (st.translate_us - lf.translate_us) / 1000.0, st.pipelines_created - lf.pipelines_created,
                      (st.pipeline_us - lf.pipeline_us) / 1000.0, st.textures_created - lf.textures_created,
                      st.textures_reuploaded - lf.textures_reuploaded, (st.texture_us - lf.texture_us) / 1000.0,
                      (st.revalidate_us - lf.revalidate_us) / 1000.0, (st.upload_bytes - lf.upload_bytes) / 1024,
                      st.draws - lf.draws);
        }
        last_cmd_total = cmd_total;
        lf.shaders_translated = st.shaders_translated;
        lf.translate_us = st.translate_us;
        lf.pipelines_created = st.pipelines_created;
        lf.pipeline_us = st.pipeline_us;
        lf.textures_created = st.textures_created;
        lf.textures_reuploaded = st.textures_reuploaded;
        lf.texture_us = st.texture_us;
        lf.revalidate_us = st.revalidate_us;
        lf.upload_bytes = st.upload_bytes;
        lf.draws = st.draws;
      }
      {
        // Textures the CPU keeps rewriting frame after frame (Bink video planes): the video player
        // assumes the GPU finished the frame when its swap returns, so run in lockstep while that goes
        // on. (One-off rewrites - texture streaming in game - do not need it.)
        static uint64_t last_stale = 0;
        uint64_t stale = R.stats().textures_animated;
        if (stale != last_stale) g_rt.RequestLockstep(60);
        else g_rt.LockstepFrameDone();
        last_stale = stale;
      }
      R.EndFrame();
      g_wmem->Clear();
      CheckDevice();
      R.BeginFrame();
      ++g.frames;
      {
        // Cost breakdown every 120 frames (per-frame averages over the period).
        static std::chrono::steady_clock::time_point period_start = std::chrono::steady_clock::now();
        static uint32_t period_frames = 0;
        static native::Stats last{};
        static uint64_t last_hook_us = 0;
        if (++period_frames == 120) {
          const auto& st = R.stats();
          double wall_ms =
              std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - period_start).count();
          double n = period_frames;
          static uint64_t last_busy = 0, last_cmd[8] = {};
          static const char* kCmdNames[8] = {"draw", "clear", "resolve", "const", "fetch", "shaders", "gpu-sync", "frame/other"};
          std::string per_type;
          for (int i = 0; i < 8; ++i) {
            per_type += fmt::format(" {} {:.1f}", kCmdNames[i], (g_cmd_us[i] - last_cmd[i]) / 1000.0 / n);
            last_cmd[i] = g_cmd_us[i];
          }
          static uint64_t last_lockstep = 0;
          uint64_t lockstep = g_lockstep_swaps.load(std::memory_order_relaxed);
          REXLOG_INFO("native renderer perf: renderer thread busy {:.1f} ms per frame:{} | lockstep swaps {:.0f}%",
                      (g_rt.busy_us() - last_busy) / 1000.0 / n, per_type, 100.0 * double(lockstep - last_lockstep) / n);
          last_lockstep = lockstep;
          last_busy = g_rt.busy_us();
          REXLOG_INFO("native renderer perf: {:.1f} fps | per frame: wall {:.1f} ms, in hooks {:.1f} ms, GPU wait "
                      "{:.1f} ms, submits {:.1f}, uploads {:.0f} KB, texture decode {:.1f} ms ({:.1f} new), draws "
                      "{:.0f}",
                      n * 1000.0 / wall_ms, wall_ms / n, (g_hook_us - last_hook_us) / 1000.0 / n,
                      (st.wait_us - last.wait_us) / 1000.0 / n, (st.submits - last.submits) / n,
                      (st.upload_bytes - last.upload_bytes) / 1024.0 / n, (st.texture_us - last.texture_us) / 1000.0 / n,
                      (st.textures_created - last.textures_created) / n, (st.draws - last.draws) / n);
          last.wait_us = st.wait_us;
          last.submits = st.submits;
          last.upload_bytes = st.upload_bytes;
          last.texture_us = st.texture_us;
          last.textures_created = st.textures_created;
          last.draws = st.draws;
          last_hook_us = g_hook_us;
          {
            // Where the hook time went: Before hooks, and the After hooks by function (top 4).
            static uint64_t last_fn[64] = {}, last_before = 0;
            std::vector<std::pair<uint64_t, int>> by_fn;
            for (int i = 0; i < 64; ++i) {
              if (g_hook_fn_us[i] != last_fn[i]) by_fn.push_back({g_hook_fn_us[i] - last_fn[i], i});
              last_fn[i] = g_hook_fn_us[i];
            }
            std::sort(by_fn.rbegin(), by_fn.rend());
            std::string top;
            for (size_t i = 0; i < by_fn.size() && i < 4; ++i)
              top += fmt::format(" {} {:.2f}",
                                 by_fn[i].second < kCount ? kFnNames[by_fn[i].second] : "?",
                                 by_fn[i].first / 1000.0 / n);
            REXLOG_INFO("native renderer perf: hook ms per frame: before {:.2f} | after:{} | segment switches {}",
                        (g_before_us - last_before) / 1000.0 / n, top, g_segment_switches);
            last_before = g_before_us;
            REXLOG_INFO("native renderer perf: draw sections ms per frame (x{}): {}", period_frames,
                        R.DrawProfile(true));
            static uint64_t last_tex_stale = 0, last_res_stale = 0;
            static uint64_t last_reval = 0, last_watch_upload = 0;
            uint64_t watch_upload = g_watch_upload_bytes.load();
            static uint64_t last_alloc = 0, last_reup = 0;
            REXLOG_INFO("native renderer perf: per frame: texture GPU allocations {:.1f}, in-place re-uploads {:.1f}",
                        (st.textures_allocated - last_alloc) / n, (st.textures_reuploaded - last_reup) / n);
            last_alloc = st.textures_allocated;
            last_reup = st.textures_reuploaded;
            REXLOG_INFO("native renderer perf: native GPU sync (totals): {}", NativeGpuSync_Stats());
            static uint64_t last_prepass = 0, last_rerun = 0, last_packets = 0;
            REXLOG_INFO("native renderer perf: per frame: real-time shadow passes {:.2f}, depth pre-pass draws {:.1f} "
                        "(reused by the main pass {:.1f})",
                        (R.passes_rerun - last_rerun) / n, (R.prepass_draws - last_prepass) / n,
                        (R.packets_replayed - last_packets) / n);
            last_packets = R.packets_replayed;
            last_rerun = R.passes_rerun;
            last_prepass = R.prepass_draws;
            REXLOG_INFO("native renderer perf: per frame: {:.0f} KB of the uploads were for texture watches",
                        (watch_upload - last_watch_upload) / 1024.0 / n);
            last_watch_upload = watch_upload;
            REXLOG_INFO("native renderer perf: per frame: textures invalidated by CPU writes {:.1f} (kept, bytes "
                        "unchanged: {:.1f}), resolved copies invalidated {:.1f}; last created texture {:08X} fmt {} "
                        "width {}",
                        (st.textures_stale - last_tex_stale) / n, (st.textures_revalidated - last_reval) / n,
                        (st.resolved_stale - last_res_stale) / n,
                        st.last_created_base, st.last_created_format, st.last_created_width);
            last_tex_stale = st.textures_stale;
            last_reval = st.textures_revalidated;
            last_res_stale = st.resolved_stale;
          }
          period_frames = 0;
          period_start = std::chrono::steady_clock::now();
        }
      }
      if (g.frames == 1 || g.frames % 600 == 0) {
        const auto& st = R.stats();
        REXLOG_INFO("native renderer: frame {} draws {} skipped {} textures {} (failed {}) shaders {} (failed {}) "
                    "pipelines {} (failed {}) render targets {} lost gaps {}",
                    g.frames, st.draws, st.draws_skipped, st.textures_created, st.textures_failed,
                    st.shaders_translated, st.shaders_failed, st.pipelines_created, st.pipelines_failed,
                    R.RenderTargets().size(), g.gaps_lost);
      }
      });
      // The game's swap returns once the renderer is at most native_render_frames_ahead frames behind.
      if (g_rt.lockstep()) g_lockstep_swaps.fetch_add(1, std::memory_order_relaxed);
      g_rt.FrameQueued(uint32_t(std::max(0, REXCVAR_GET(native_render_frames_ahead))));
      break;
    }
    default:
      break;
  }
  // The call's own packets, after its draw: loads and bin mask persist; the GpuLoadShaders flow
  // (bool/loop) constants come from its output.
  if (call_bytes)
    ParseCommands(call_bytes, call_size, g.loaded, fn == kGpuLoadShaders, mem.Virtual(r[0], native::dev::kSize), true);
  g.last_put = put;
  FlushSyncsInCall();
}
