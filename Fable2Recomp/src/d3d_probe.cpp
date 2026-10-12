/**
 * @file        src/d3d_probe.cpp
 * @brief       Hooks on the statically linked Xbox D3D (D3D9LTCG) functions identified in
 *              research/findings/2026-09-30-d3d-runtime-map.md.
 *
 * Every hooked function still runs its original generated body (__imp__sub_X), so behaviour
 * is unchanged. The hooks feed:
 *  - d3d_probe = true: a "D3D probe 5s" line with call counts every 5 s, and a one-time dump of
 *    the device's handler tables (device+64 .. device+1152) on the first draw;
 *  - the frame capture (src/d3d_capture.cpp), when one is running.
 */
#include "generated/Fable2_init.h"
#include "d3d_hooks.h"

#include <rex/cvar.h>
#include <rex/hook.h>
#include <rex/logging.h>
#include <rex/ppc.h>

#include <windows.h>

#include <atomic>
#include <chrono>
#include <cstdint>
#include <string>

#include <fmt/format.h>

REXCVAR_DEFINE_BOOL(d3d_probe, false, "Debug",
                    "Count calls to the identified Xbox D3D runtime functions and log every 5 s");

namespace d3dhooks {
const char* const kFnNames[kCount] = {"DrawIndexedVertices", "DrawVertices", "BeginIndexedVertices",
                                      "BeginVertices", "DrawRect2D", "DrawIndexedVertices2", "Resolve",
                                      "ClearF", "Swap", "CommitShaders", "CommitRenderStates",
                                      "GameStateFlush", "GpuLoadShaders", "GpuLoadShaderConstantF4"};
}  // namespace d3dhooks

namespace {

using namespace d3dhooks;

std::atomic<uint64_t> g_calls[kCount];
std::atomic<uint64_t> g_prim[32];          // DrawIndexed/Draw primitive types
std::atomic<uint64_t> g_dev_mismatch{0};   // r3 != *(kDevicePtrA)
std::atomic<uint64_t> g_dev2_mismatch{0};  // r3 != *(kDevicePtrB)
std::atomic<uint64_t> g_resolve_flags_or{0};
std::atomic<bool> g_tables_dumped{false};

void MaybeReport() {
  static std::atomic<int64_t> last{0};
  int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now().time_since_epoch())
                    .count();
  int64_t prev = last.load(std::memory_order_relaxed);
  if (prev == 0) {
    last.store(now, std::memory_order_relaxed);
    return;
  }
  if (now - prev < 5000 || !last.compare_exchange_strong(prev, now)) return;
  std::string s;
  for (int i = 0; i < kCount; ++i) {
    s += fmt::format(" {}={}", kFnNames[i], g_calls[i].exchange(0, std::memory_order_relaxed));
  }
  std::string prims;
  for (int i = 0; i < 32; ++i) {
    uint64_t n = g_prim[i].exchange(0, std::memory_order_relaxed);
    if (n) prims += fmt::format(" {}:{}", i, n);
  }
  REXLOG_INFO("D3D probe 5s:{} | prims{} | dev!=A:{} dev!=B:{} resolve_flags_or={:08X}", s, prims,
              g_dev_mismatch.exchange(0), g_dev2_mismatch.exchange(0), g_resolve_flags_or.exchange(0));
}

void DumpTables(uint8_t* base, uint32_t dev) {
  std::string s;
  for (uint32_t off = 64; off < 1152; off += 4) {
    uint32_t v = REX_LOAD_U32(dev + off);
    if (v >= 0x82000000 && v < 0x83400000) s += fmt::format(" +{}={:08X}", off, v);
  }
  REXLOG_INFO("D3D probe: device {:08X} (A={:08X} B={:08X}) code pointers in +64..+1152:{}", dev,
              REX_LOAD_U32(kDevicePtrA), REX_LOAD_U32(kDevicePtrB), s);
}

inline void Before(Fn fn, PPCContext& ctx, uint8_t* base) {
  if (D3DCapture_Active()) D3DCapture_Before(fn, ctx, base);
  NativeFrontend_Before(fn, ctx, base);
  if (!REXCVAR_GET(d3d_probe)) return;
  g_calls[fn].fetch_add(1, std::memory_order_relaxed);
  if (fn <= kDrawIndexed2) {
    uint32_t dev = ctx.r3.u32;
    if (REX_LOAD_U32(kDevicePtrA) != dev) g_dev_mismatch.fetch_add(1, std::memory_order_relaxed);
    if (REX_LOAD_U32(kDevicePtrB) != dev) g_dev2_mismatch.fetch_add(1, std::memory_order_relaxed);
    if (fn == kDrawIndexed || fn == kDraw) g_prim[ctx.r4.u32 & 31].fetch_add(1, std::memory_order_relaxed);
    if (!g_tables_dumped.exchange(true)) DumpTables(base, dev);
  }
  if (fn == kResolve) g_resolve_flags_or.fetch_or(ctx.r4.u32, std::memory_order_relaxed);
  MaybeReport();
}

}  // namespace

// Item 2, step 1: inside draw calls the native renderer reads constants, registers and fetch
// constants straight from the device shadow, so D3D's command writers for them (pure copies of the
// shadow into the command buffer) are skipped. Resolve / Clear keep them (the renderer reads the
// copy-destination setup from their commands).
thread_local bool t_in_draw = false;
#define D3D_FLUSH_SKIP(addr)                                       \
  REX_HOOK_RAW(sub_##addr) {                                       \
    if (t_in_draw && NativeFrontend_SkipStateFlush()) {            \
      ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 48); /* unchanged put */ \
      return;                                                      \
    }                                                              \
    __imp__sub_##addr(ctx, base);                                  \
  }

D3D_FLUSH_SKIP(8221DF98)  // dirty float constants
D3D_FLUSH_SKIP(8221C908)  // dirty register runs
D3D_FLUSH_SKIP(8221D2E0)  // dirty fetch constants
D3D_FLUSH_SKIP(822B3E40)  // user clip planes
D3D_FLUSH_SKIP(8222BFF8)  // shader literal constants (the renderer loads them from the shader objects)

#define D3D_HOOK(addr, fn)                                         \
  REX_HOOK_RAW(sub_##addr) {                                       \
    if (fn == kSwap) Sampler_SetRenderThread(GetCurrentThreadId()); \
    Before(fn, ctx, base);                                         \
    if (fn <= kDrawIndexed2) t_in_draw = true;                     \
    __imp__sub_##addr(ctx, base);                                  \
    t_in_draw = false;                                             \
    if (fn == kSwap || D3DCapture_Active()) D3DCapture_After(fn, ctx, base); \
    NativeFrontend_After(fn, ctx, base);                             \
  }

// Command buffer segment switch (D3D "make space"): the native frontend must not parse the bytes
// between the end of the old segment and the start of the new one.
REX_HOOK_RAW(sub_821E8D20) {
  uint32_t device = ctx.r3.u32;
  NativeFrontend_SegmentSwitch(device, false);
  D3DCapture_SegmentSwitch(device, false);
  __imp__sub_821E8D20(ctx, base);
  NativeFrontend_SegmentSwitch(device, true);
  D3DCapture_SegmentSwitch(device, true);
}

D3D_HOOK(8221E0F0, kDrawIndexed)
D3D_HOOK(8221C518, kDraw)
D3D_HOOK(82217EE8, kBeginIndexedUP)
D3D_HOOK(822060A0, kBeginUP)
D3D_HOOK(8221C9C8, kDrawRect2D)
D3D_HOOK(82207C30, kDrawIndexed2)
D3D_HOOK(822069C0, kResolve)
D3D_HOOK(8222B948, kClear)
D3D_HOOK(82B9CD68, kSwap)
D3D_HOOK(8221B140, kCommitShaders)
D3D_HOOK(822155E0, kCommitRS)
D3D_HOOK(8221E5D0, kGameStateFlush)
D3D_HOOK(82221978, kGpuLoadShaders)
D3D_HOOK(8227CFC8, kGpuLoadConstants)
