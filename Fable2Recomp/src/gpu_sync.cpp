/**
 * @file        src/gpu_sync.cpp
 * @brief       Native GPU synchronisation: replaces the emulated command processor.
 *
 * With the native renderer, every draw, clear and resolve is executed when the game calls the D3D
 * function, so the GPU command stream the game's D3D runtime still writes carries nothing left to
 * render. What the game does depend on are its CPU-visible effects, which this module performs
 * directly when the game hands the commands to the "GPU" (its CP_RB_WPTR write), on the same thread:
 *
 *  - ring read pointer write-back: everything submitted is consumed at once, so every D3D fence
 *    (fences are ring positions) has passed;
 *  - GPU->CPU callbacks: D3D's InsertCallback path (sub_821F5F20) writes {cpu mask, function,
 *    argument} through the scratch registers into its mailbox, then raises an interrupt; the
 *    interrupt is delivered to the game's handler (sub_82B9B8D8) on a host interrupt thread, which
 *    calls the function and clears the mailbox;
 *  - memory writes: EVENT_WRITE_SHD (frame / vblank counters, fences), MEM_WRITE, REG_TO_MEM,
 *    COND_WRITE, EVENT_WRITE_EXT (screen extents: whole screen), EVENT_WRITE_ZPD (occlusion
 *    queries: reported visible unless the renderer answers them);
 *  - the swap counter.
 *
 * Commands are only scanned for those packets: rendering packets are skipped by their headers.
 * The SDK's command processor stays idle (nothing is ever submitted to it).
 *
 * The packet semantics follow the command processor of Xenia (github.com/xenia-project/xenia, BSD)
 * as adapted in ReXGlue (BSD 3-Clause); this module is its own implementation of their effects.
 */
#include "generated/Fable2_init.h"
#include "d3d_hooks.h"

#include <rex/hook.h>
#include <rex/ppc.h>

#include <rex/cvar.h>
#include <rex/graphics/command_processor.h>
#include <rex/graphics/graphics_system.h>
#include <rex/logging.h>
#include <rex/runtime.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xthread.h>

#include <windows.h>

#include <fmt/format.h>

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

REXCVAR_DEFINE_BOOL(native_gpu_sync, true, "Render",
                    "With the native renderer: perform the GPU command stream's synchronisation effects natively "
                    "and stop feeding the emulated command processor");
REXCVAR_DEFINE_INT32(native_gpu_sync_diag, 0, "Render",
                     "Log this many native GPU sync events (packets, interrupts, fence waits) for diagnosis");
REXCVAR_DECLARE(int32_t, query_occlusion_fake_sample_count);

namespace {

using rex::graphics::GraphicsSystem;

constexpr uint32_t kScratchUmsk = 0x01DC, kScratchAddr = 0x01DD, kScratchReg0 = 0x0578;
constexpr uint32_t kCoherStatusHost = 0x0A31, kSampleCountAddr = 0x2325;

struct Sync {
  GraphicsSystem* gs = nullptr;
  rex::memory::Memory* mem = nullptr;
  std::mutex mutex;
  uint32_t read_index = 0;  // dwords
  // Predicated tiling: the same command buffer runs once per screen tile; packets with the predicate
  // bit only execute when BIN_SELECT & BIN_MASK != 0 (e.g. D3D's callbacks run in one tile only).
  uint64_t bin_mask = 0xFFFFFFFFull, bin_select = 0xFFFFFFFFull;
  std::vector<uint32_t> ring_copy;
  // Interrupt delivery (a host thread with guest state, like the hardware's interrupt).
  std::mutex irq_mutex;
  std::condition_variable irq_cv;
  std::deque<uint32_t> irq_queue;  // cpu numbers
  uint64_t irq_raised = 0, irq_delivered = 0;
  // (Never released: at process exit the kernel is gone before static destructors run.)
  rex::system::object_ref<rex::system::XHostThread>* irq_thread = nullptr;
  // Statistics.
  std::atomic<uint64_t> submits{0}, packets{0}, waits_timed_out{0};
  std::atomic<int> diag_left{0};  // detailed log lines of sync events left (native_gpu_sync_diag)
  // The game has stopped (window closing / guest thread ended): no more commands or interrupts. The renderer
  // can still hold submitted buffers then, and an interrupt into the torn-down guest crashed the process on
  // exit (ExecuteInterrupt on freed thread state, 2026-10-05).
  std::atomic<bool> stopped{false};
} g;

template <typename... Args>
void Diag(fmt::format_string<Args...> f, Args&&... args) {
  if (g.diag_left.fetch_sub(1, std::memory_order_relaxed) > 0)
    REXLOG_INFO("native gpu sync: {}", fmt::format(f, std::forward<Args>(args)...));
}

inline uint32_t Load(const uint8_t* p) {
  uint32_t v;
  std::memcpy(&v, p, 4);
  return _byteswap_ulong(v);
}

uint8_t* Phys(uint32_t address, uint32_t size = 4) {
  address &= 0x1FFFFFFF;
  if (uint64_t(address) + size > 0x20000000ull) return nullptr;
  return g.mem->TranslatePhysical<uint8_t*>(address);
}

// Xenos endian swap of a 32-bit value (address bits 0..1 of the guest pointer).
uint32_t GpuSwap(uint32_t v, uint32_t endian) {
  switch (endian & 3) {
    case 1:  // 8in16
      return ((v & 0x00FF00FFu) << 8) | ((v & 0xFF00FF00u) >> 8);
    case 2:  // 8in32
      return _byteswap_ulong(v);
    case 3:  // 16in32
      return (v << 16) | (v >> 16);
    default:
      return v;
  }
}

uint32_t ReadMemory(uint32_t address) {
  uint8_t* p = Phys(address & ~3u);
  if (!p) return 0;
  uint32_t raw;
  std::memcpy(&raw, p, 4);
  return GpuSwap(raw, address & 3);
}

void WriteMemory(uint32_t address, uint32_t value) {
  uint8_t* p = Phys(address & ~3u);
  if (!p) return;
  uint32_t raw = GpuSwap(value, address & 3);
  std::memcpy(p, &raw, 4);
}

uint32_t& Reg(uint32_t index) { return g.gs->register_file()->values[index]; }

void WriteRegister(uint32_t index, uint32_t value) {
  if (index >= rex::graphics::RegisterFile::kRegisterCount) return;
  // (COHER_STATUS_HOST: coherency requests complete immediately.)
  if (index == kCoherStatusHost) value &= 0x7FFFFFFFu;
  const_cast<volatile uint32_t&>(Reg(index)) = value;
  if (index >= kScratchReg0 && index < kScratchReg0 + 8 || index == kScratchUmsk || index == kScratchAddr)
    Diag("reg {:04X} = {:08X} (umsk {:08X} addr {:08X})", index, value, Reg(kScratchUmsk), Reg(kScratchAddr));
  if (index >= kScratchReg0 && index < kScratchReg0 + 8) {
    uint32_t n = index - kScratchReg0;
    if ((Reg(kScratchUmsk) >> n) & 1) {
      // Scratch register write-back (memory big-endian, like the GPU's).
      if (uint8_t* p = Phys(Reg(kScratchAddr) + n * 4)) {
        uint32_t be = _byteswap_ulong(value);
        std::memcpy(p, &be, 4);
      }
    }
  }
}

thread_local bool t_inline_interrupts = false;

void RaiseInterrupt(uint32_t cpu) {
  if (g.stopped.load()) return;
  if (t_inline_interrupts) {
    // Delivered right here (the renderer thread is a guest thread): no round trip to another thread.
    {
      std::lock_guard<std::mutex> lock(g.irq_mutex);
      ++g.irq_raised;
      ++g.irq_delivered;
    }
    g.gs->DispatchInterruptCallback(1, cpu);
    return;
  }
  {
    std::lock_guard<std::mutex> lock(g.irq_mutex);
    g.irq_queue.push_back(cpu);
    ++g.irq_raised;
  }
  g.irq_cv.notify_one();
}

int InterruptThread() {
  for (;;) {
    uint32_t cpu;
    {
      std::unique_lock<std::mutex> lock(g.irq_mutex);
      g.irq_cv.wait(lock, [] { return !g.irq_queue.empty(); });
      cpu = g.irq_queue.front();
      g.irq_queue.pop_front();
    }
    if (g.stopped.load()) continue;
    uint32_t mb = Reg(kScratchAddr);
    Diag("interrupt cpu {} -> handler; mailbox {:08X}: mask {:08X} fn {:08X} arg {:08X}", cpu, mb, ReadMemory(mb | 2),
         ReadMemory((mb + 16) | 2), ReadMemory((mb + 20) | 2));
    g.gs->DispatchInterruptCallback(1, cpu);
    Diag("interrupt cpu {} handled; mailbox mask now {:08X}", cpu, ReadMemory(mb | 2));
    std::lock_guard<std::mutex> lock(g.irq_mutex);
    ++g.irq_delivered;
  }
}

bool Compare(uint32_t func, uint32_t value, uint32_t mask, uint32_t ref) {
  value &= mask;
  switch (func & 7) {
    case 1: return value < ref;
    case 2: return value <= ref;
    case 3: return value == ref;
    case 4: return value != ref;
    case 5: return value >= ref;
    case 6: return value > ref;
    case 7: return true;
    default: return false;
  }
}

// WAIT_REG_MEM: the GPU waits until a register or memory value matches. Memory waits are on values
// another guest thread writes (the interrupt handler clearing D3D's callback mailbox): wait for it,
// bounded, so a wait on something only this thread will write later cannot hang the game.
void WaitRegMem(const uint8_t* d) {
  uint32_t info = Load(d), poll = Load(d + 4), ref = Load(d + 8), mask = Load(d + 12);
  bool memory = (info & 0x10) != 0;
  Diag("WAIT_REG_MEM {} {:08X} func {} ref {:08X} mask {:08X} now {:08X}", memory ? "mem" : "reg", poll, info & 7, ref,
       mask, memory ? ReadMemory(poll) : Reg(poll & 0x1FFF));
  if (!memory) return;  // registers: only COHER_STATUS_HOST (coherency is immediate here)
  auto t0 = std::chrono::steady_clock::now();
  for (uint32_t spins = 0; !Compare(info, ReadMemory(poll), mask, ref); ++spins) {
    if (spins < 64) {
      YieldProcessor();
    } else {
      SwitchToThread();
      if (std::chrono::steady_clock::now() - t0 > std::chrono::milliseconds(100)) {
        if (g.waits_timed_out.fetch_add(1) < 16)
          REXLOG_WARN("native gpu sync: wait on memory {:08X} (value {:08X} mask {:08X} func {} ref {:08X}) timed out",
                      poll, ReadMemory(poll), mask, info & 7, ref);
        return;
      }
    }
  }
}

void ExecuteBuffer(const uint8_t* p, size_t n, int depth);

void ExecutePacket3(uint32_t op, const uint8_t* d, uint32_t count, int depth) {
  switch (op) {
    case 0x60:  // SET_BIN_MASK_LO
      g.bin_mask = (g.bin_mask & 0xFFFFFFFF00000000ull) | Load(d);
      break;
    case 0x61:  // SET_BIN_MASK_HI
      g.bin_mask = (g.bin_mask & 0xFFFFFFFFull) | (uint64_t(Load(d)) << 32);
      break;
    case 0x62:  // SET_BIN_SELECT_LO
      g.bin_select = (g.bin_select & 0xFFFFFFFF00000000ull) | Load(d);
      break;
    case 0x63:  // SET_BIN_SELECT_HI
      g.bin_select = (g.bin_select & 0xFFFFFFFFull) | (uint64_t(Load(d)) << 32);
      break;
    case 0x50:  // SET_BIN_MASK
      if (count >= 2) g.bin_mask = (uint64_t(Load(d)) << 32) | Load(d + 4);
      break;
    case 0x51:  // SET_BIN_SELECT
      if (count >= 2) g.bin_select = (uint64_t(Load(d)) << 32) | Load(d + 4);
      break;
    case 0x37:  // INDIRECT_BUFFER_PFD
    case 0x3F: {  // INDIRECT_BUFFER
      if (count < 2 || depth > 2) break;
      uint32_t address = Load(d) & 0x1FFFFFFF, length = Load(d + 4) & 0xFFFFF;
      if (const uint8_t* ib = Phys(address, length * 4)) ExecuteBuffer(ib, length, depth + 1);
      break;
    }
    case 0x54: {  // INTERRUPT
      uint32_t mask = Load(d);
      Diag("INTERRUPT mask {:08X}", mask);
      for (uint32_t cpu = 0; cpu < 6; ++cpu)
        if (mask & (1u << cpu)) RaiseInterrupt(cpu);
      break;
    }
    case 0x3C:  // WAIT_REG_MEM
      if (count >= 5) WaitRegMem(d);
      break;
    case 0x64:  // XE_SWAP (VdSwap's token): the frame counter
      g.gs->IncrementGpuCounter();
      break;
    case 0x21: {  // REG_RMW
      if (count < 3) break;
      uint32_t info = Load(d), and_mask = Load(d + 4), or_mask = Load(d + 8);
      uint32_t value = Reg(info & 0x1FFF);
      value &= (info >> 31) ? Reg(and_mask & 0x1FFF) : and_mask;
      value |= ((info >> 30) & 1) ? Reg(or_mask & 0x1FFF) : or_mask;
      Diag("REG_RMW {:04X} = {:08X}", info & 0x1FFF, value);
      WriteRegister(info & 0x1FFF, value);
      break;
    }
    case 0x3D: {  // MEM_WRITE
      uint32_t address = Load(d);
      Diag("MEM_WRITE {:08X} x{} = {:08X}", address, count - 1, count > 1 ? Load(d + 4) : 0);
      for (uint32_t i = 1; i < count; ++i, address += 4) WriteMemory(address, Load(d + i * 4));
      break;
    }
    case 0x3E:  // REG_TO_MEM
      if (count >= 2) {
        Diag("REG_TO_MEM {:04X} ({:08X}) -> {:08X}", Load(d) & 0x1FFF, Reg(Load(d) & 0x1FFF), Load(d + 4));
        WriteMemory(Load(d + 4), Reg(Load(d) & 0x1FFF));
      }
      break;
    case 0x45: {  // COND_WRITE
      if (count < 6) break;
      uint32_t info = Load(d), poll = Load(d + 4), ref = Load(d + 8), mask = Load(d + 12);
      uint32_t target = Load(d + 16), data = Load(d + 20);
      uint32_t value = (info & 0x10) ? ReadMemory(poll) : Reg(poll & 0x1FFF);
      Diag("COND_WRITE poll {:08X} value {:08X} -> {:08X} = {:08X} ({})", poll, value, target, data,
           Compare(info, value, mask, ref) ? "written" : "not written");
      if (Compare(info, value, mask, ref)) {
        if (info & 0x100)
          WriteMemory(target, data);
        else
          WriteRegister(target & 0x1FFF, data);
      }
      break;
    }
    case 0x58: {  // EVENT_WRITE_SHD: value (or the frame counter) to memory
      if (count < 3) break;
      uint32_t initiator = Load(d), address = Load(d + 4), value = Load(d + 8);
      if (initiator >> 31) value = g.gs->gpu_counter();
      Diag("EVENT_WRITE_SHD {:08X} = {:08X} (initiator {:08X})", address, value, initiator);
      WriteMemory(address, value);
      break;
    }
    case 0x5A: {  // EVENT_WRITE_EXT: screen extents of the previous draws (whole screen)
      if (count < 2) break;
      uint32_t address = Load(d + 4) & ~3u;
      static const uint16_t extents[6] = {0, 8192 >> 3, 0, 8192 >> 3, 0, 1};
      if (uint8_t* q = Phys(address, sizeof(extents)))
        for (int i = 0; i < 6; ++i) {
          q[i * 2] = uint8_t(extents[i] >> 8);
          q[i * 2 + 1] = uint8_t(extents[i]);
        }
      break;
    }
    case 0x5B: {  // EVENT_WRITE_ZPD: occlusion query begin / end
      int32_t fake = REXCVAR_GET(query_occlusion_fake_sample_count);
      if (fake < 0) break;  // the native renderer answers queries itself
      uint8_t* q = Phys(Reg(kSampleCountAddr), 32);
      if (!q) break;
      // D3D marks an ended query's struct with 0xFFFFFEED (the struct is little-endian).
      uint32_t v[8];
      std::memcpy(v, q, 32);
      const uint32_t kFinished = 0xEDFEFFFFu;
      bool end = v[2] == kFinished || v[3] == kFinished || v[4] == kFinished || v[5] == kFinished;
      std::memset(v, 0, sizeof(v));
      if (end) v[0] = v[4] = uint32_t(fake);  // Total_A, ZPass_A
      std::memcpy(q, v, 32);
      break;
    }
    default:
      break;
  }
}

void ExecuteBuffer(const uint8_t* p, size_t n, int depth) {
  for (size_t i = 0; i < n;) {
    uint32_t h = Load(p + i * 4);
    g.packets.fetch_add(1, std::memory_order_relaxed);
    switch (h >> 30) {
      case 0: {  // register writes: only CP-side registers matter here
        uint32_t count = ((h >> 16) & 0x3FFF) + 1, base = h & 0x7FFF;
        bool one_reg = (h >> 15) & 1;
        if (base < 0x2000 || (base <= kSampleCountAddr && (one_reg || base + count > kSampleCountAddr))) {
          for (uint32_t k = 0; k < count && i + 1 + k < n; ++k) {
            uint32_t r = one_reg ? base : base + k;
            if (r < 0x2000 || r == kSampleCountAddr) WriteRegister(r, Load(p + (i + 1 + k) * 4));
          }
        }
        i += 1 + count;
        break;
      }
      case 1: {  // two register writes
        if (i + 2 < n) {
          uint32_t ra = h & 0x7FF, rb = (h >> 11) & 0x7FF;
          WriteRegister(ra, Load(p + (i + 1) * 4));
          WriteRegister(rb, Load(p + (i + 2) * 4));
        }
        i += 3;
        break;
      }
      case 2:
        ++i;
        break;
      default: {
        uint32_t count = ((h >> 16) & 0x3FFF) + 1, op = (h >> 8) & 0x7F;
        if (i + 1 + count > n) return;
        // Predicated packets run only for the selected tiles (never a predicated swap).
        bool skip = (h & 1) && (!(g.bin_select & g.bin_mask) || op == 0x64);
        if (!skip) ExecutePacket3(op, p + (i + 1) * 4, count, depth);
        i += 1 + count;
        break;
      }
    }
  }
}

void WriteBackReadPointer(uint32_t index) {
  if (uint32_t wb = g.gs->read_ptr_writeback_ptr()) {
    if (uint8_t* q = Phys(wb)) {
      uint32_t be = _byteswap_ulong(index);
      std::memcpy(q, &be, 4);
    }
  }
}

void OnRingWrite(uint32_t write_index) {
  std::lock_guard<std::mutex> lock(g.mutex);
  uint32_t size = g.gs->ring_buffer_size() / 4;
  const uint8_t* ring = Phys(g.gs->ring_buffer_ptr(), size * 4);
  std::vector<uint32_t> commands;
  if (ring && size && write_index < size && write_index != g.read_index) {
    // The new commands, unwrapped (the indirect buffers they reference stay valid until the read
    // pointer has passed them).
    for (uint32_t i = g.read_index; i != write_index; i = (i + 1) % size)
      commands.push_back(*reinterpret_cast<const uint32_t*>(ring + i * 4));
  }
  g.read_index = write_index;
  // With the renderer on its own thread, the effects happen when it gets there (fences then mean
  // "the renderer has executed this"); otherwise now.
  if (!NativeFrontend_QueueGpuSync(commands, write_index)) NativeGpuSync_Execute(commands, write_index);
}

}  // namespace

void NativeGpuSync_RunInterruptsOnThisThread() { t_inline_interrupts = true; }

void NativeGpuSync_Stop() { g.stopped.store(true); }

void NativeGpuSync_Execute(std::vector<uint32_t>& commands, uint32_t write_index) {
  if (g.stopped.load()) return;
  if (!commands.empty()) {
    if (g.submits.load() < 40) Diag("submit: {} dwords up to {}", commands.size(), write_index);
    ExecuteBuffer(reinterpret_cast<const uint8_t*>(commands.data()), commands.size(), 0);
    g.submits.fetch_add(1, std::memory_order_relaxed);
  }
  WriteBackReadPointer(write_index);
}


std::string NativeGpuSync_Stats();

bool NativeGpuSync_Start() {
  static bool started = false;
  if (started) return true;
  if (!REXCVAR_GET(native_gpu_sync)) return false;
  auto* rt = rex::Runtime::instance();
  g.gs = rt ? static_cast<GraphicsSystem*>(rt->graphics_system()) : nullptr;
  g.mem = rt ? rt->memory() : nullptr;
  if (!g.gs || !g.mem) return false;
  auto* cp = g.gs->command_processor();
  started = true;
  g.diag_left = REXCVAR_GET(native_gpu_sync_diag);
  g.irq_thread = new rex::system::object_ref<rex::system::XHostThread>(
      new rex::system::XHostThread(g.gs->kernel_state(), 128 * 1024, 0, [] { return InterruptThread(); }));
  (*g.irq_thread)->set_name("GPU Interrupts (native)");
  (*g.irq_thread)->Create();
  if (cp) {
    // Take the ring over once the command processor has caught up with what was submitted so far.
    auto t0 = std::chrono::steady_clock::now();
    while (cp->read_ptr_index() != cp->write_ptr_index()) {
      if (std::chrono::steady_clock::now() - t0 > std::chrono::seconds(2)) {
        REXLOG_WARN("native gpu sync: command processor busy - taking the ring over anyway");
        break;
      }
      SwitchToThread();
    }
    uint32_t w = cp->write_ptr_index();
    g.read_index = g.gs->ring_buffer_size() && w < g.gs->ring_buffer_size() / 4 ? w : 0;
  }
  g.gs->SetRingWriteHandler([](uint32_t write_index) { OnRingWrite(write_index); });
  REXLOG_INFO("native gpu sync: active - GPU commands are consumed natively ({})",
              cp ? "the emulated command processor exists but receives no more commands"
                 : "no emulated command processor");
  return true;
}

std::string NativeGpuSync_Stats() {
  uint64_t raised, delivered;
  {
    std::lock_guard<std::mutex> lock(g.irq_mutex);
    raised = g.irq_raised;
    delivered = g.irq_delivered;
  }
  return fmt::format("submits {}, packets scanned {}, interrupts {} ({} delivered), wait timeouts {}",
                     g.submits.load(), g.packets.load(), raised, delivered, g.waits_timed_out.load());
}

// D3D's GPU fence wait (sub_82242628(dev, fence, ...)): passes once the ring read position written
// back (*dev[10896]) has moved past `fence` (positions relative to dev[10908]). Logged when it waits.
REX_HOOK_RAW(sub_82242628) {
  uint32_t dev = ctx.r3.u32, fence = ctx.r4.u32;
  uint32_t wb = REX_LOAD_U32(dev + 10896), pos = REX_LOAD_U32(dev + 10908);
  uint32_t rptr = wb ? REX_LOAD_U32(wb) : 0;
  bool passed = (pos - fence) >= (pos - rptr);
  auto t0 = std::chrono::steady_clock::now();
  __imp__sub_82242628(ctx, base);
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t0).count();
  if (!passed || ms > 50)
    Diag("fence wait: fence {:08X} pos {:08X} rptr {:08X} (writeback {:08X}, ring read index {}) -> {} ms, rptr now {:08X}",
         fence, pos, rptr, wb, g.read_index, ms, wb ? REX_LOAD_U32(wb) : 0);
}
