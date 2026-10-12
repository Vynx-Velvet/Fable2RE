/**
 * @file        src/hooks_audio_trace.cpp
 * @brief       Call tracing for the C wrapper layer the game's audio engine uses on
 *              top of XAudio2 (sub_82CD2A58..sub_82CD3308: each takes a global lock and
 *              calls one voice/engine method). Logs the first calls with arguments and a
 *              10 s count per wrapper. Discovery aid for the native mixer work.
 */
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <string>

#include <fmt/format.h>
#include "generated/Fable2_init.h"
#include <rex/cvar.h>
#include <rex/hook.h>
#include <rex/logging.h>

REXCVAR_DEFINE_BOOL(audio_api_trace, false, "Debug",
                    "Trace the game's calls into its XAudio2 wrapper layer (counts every 10 s, first calls with args).");

namespace {
struct WrapStat { const char* name; std::atomic<uint32_t> calls{0}; std::atomic<uint32_t> logged{0}; };
WrapStat g_stats[] = {
    {"2A58"}, {"2AC0"}, {"2B30"}, {"2B88"}, {"2BE0"}, {"2C38"}, {"2C98"}, {"2CF0"}, {"2D38"}, {"2D90"},
    {"2DF8"}, {"2E50"}, {"2EA8"}, {"2F00"}, {"2F58"}, {"2FD0"}, {"3120"}, {"31A0"}, {"3228"}, {"32A0"}, {"32A8"}, {"3308"},
};
std::atomic<uint64_t> g_last_report{0};

inline uint32_t L32(uint8_t* base, uint32_t a) { return REX_LOAD_U32(a); }

void Trace(int idx, PPCContext& ctx, uint8_t* base) {
  if (!REXCVAR_GET(audio_api_trace)) return;
  WrapStat& s = g_stats[idx];
  uint32_t n = s.calls.fetch_add(1, std::memory_order_relaxed) + 1;
  if (s.logged.load() < 6) {
    s.logged.fetch_add(1);
    std::string extra;
    // r4 often points at a struct: dump its first 12 words for the discovery pass.
    uint32_t p = ctx.r4.u32;
    if (p >= 0x10000 && p < 0xE0000000) {
      for (int i = 0; i < 12; ++i) extra += fmt::format(" {:08X}", L32(base, p + i * 4));
    }
    REXLOG_INFO("AudioAPI sub_82CD{} #{}: r3={:08X} r4={:08X} r5={:08X} r6={:08X} r7={:08X} f1={:.4f} lr={:08X} [r4->{}]",
                s.name, n, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.f1.f64, ctx.lr, extra);
  }
  uint64_t now = uint64_t(std::chrono::duration_cast<std::chrono::milliseconds>(
                              std::chrono::steady_clock::now().time_since_epoch()).count());
  uint64_t last = g_last_report.load();
  if (now - last > 10000 && g_last_report.compare_exchange_strong(last, now)) {
    std::string text;
    for (auto& w : g_stats) { uint32_t c = w.calls.exchange(0); if (c) text += fmt::format(" {}={}", w.name, c); }
    REXLOG_INFO("AudioAPI 10s calls:{}", text);
  }
}
}  // namespace

// ---- Output level: the mixer's render-driver callback (registered with XAudioRegisterRenderDriverClient)
// mixes one frame into the buffer it then hands to XAudioSubmitRenderDriverFrame: 6 channels x 256 samples,
// big-endian float. The peak of every frame is collected and logged every 2 s ("audio level"), so automated
// runs can tell sound from silence (also when the output is muted: the mix itself is measured).
REXCVAR_DEFINE_BOOL(audio_level_log, true, "Audio", "Log the peak level of the game's audio mix every 2 seconds.");

namespace {
std::atomic<uint32_t> g_level_peak_bits{0}, g_level_frames{0}, g_level_loud{0};
std::atomic<uint64_t> g_level_last{0};
}  // namespace

// sub_82CD82E8 asks the mixer for one frame and submits it (XAudioSubmitRenderDriverFrame(driver, samples));
// nothing after the submit changes r4, so on return r4 is the frame just handed to the output.
REX_HOOK_RAW(sub_82CD82E8) {
  __imp__sub_82CD82E8(ctx, base);
  if (!REXCVAR_GET(audio_level_log)) return;
  uint32_t buf = ctx.r4.u32;
  if (buf < 0x10000 || buf >= 0x70000000) return;  // (the error path: r4 is a stack address, nothing submitted)
  float peak = 0;
  for (uint32_t i = 0; i < 6 * 256; ++i) {
    uint32_t bits = L32(base, buf + i * 4);
    float v;
    std::memcpy(&v, &bits, 4);
    if (v != v) continue;  // (NaN)
    peak = std::max(peak, std::fabs(v));
  }
  uint32_t pb;
  std::memcpy(&pb, &peak, 4);
  uint32_t old = g_level_peak_bits.load();
  while (pb > old && !g_level_peak_bits.compare_exchange_weak(old, pb)) {}
  g_level_frames.fetch_add(1);
  if (peak > 1e-4f) g_level_loud.fetch_add(1);
  uint64_t now = uint64_t(std::chrono::duration_cast<std::chrono::milliseconds>(
                              std::chrono::steady_clock::now().time_since_epoch()).count());
  uint64_t last = g_level_last.load();
  if (now - last > 2000 && g_level_last.compare_exchange_strong(last, now)) {
    uint32_t bits = g_level_peak_bits.exchange(0);
    float p;
    std::memcpy(&p, &bits, 4);
    REXLOG_INFO("audio level: peak {:.4f}, {} of {} frames not silent (buffer {:08X})", p, g_level_loud.exchange(0),
                g_level_frames.exchange(0), buf);
  }
}

#define AUDIO_WRAP_HOOK(idx, addr)                 \
  REX_HOOK_RAW(sub_82CD##addr) {                   \
    Trace(idx, ctx, base);                         \
    __imp__sub_82CD##addr(ctx, base);              \
  }
AUDIO_WRAP_HOOK(0, 2A58) AUDIO_WRAP_HOOK(1, 2AC0) AUDIO_WRAP_HOOK(2, 2B30) AUDIO_WRAP_HOOK(3, 2B88)
AUDIO_WRAP_HOOK(4, 2BE0) AUDIO_WRAP_HOOK(5, 2C38) AUDIO_WRAP_HOOK(6, 2C98) AUDIO_WRAP_HOOK(7, 2CF0)
AUDIO_WRAP_HOOK(8, 2D38) AUDIO_WRAP_HOOK(9, 2D90) AUDIO_WRAP_HOOK(10, 2DF8) AUDIO_WRAP_HOOK(11, 2E50)
AUDIO_WRAP_HOOK(12, 2EA8) AUDIO_WRAP_HOOK(13, 2F00) AUDIO_WRAP_HOOK(14, 2F58) AUDIO_WRAP_HOOK(15, 2FD0)
AUDIO_WRAP_HOOK(16, 3120) AUDIO_WRAP_HOOK(17, 31A0) AUDIO_WRAP_HOOK(18, 3228) AUDIO_WRAP_HOOK(19, 32A0)
AUDIO_WRAP_HOOK(20, 32A8) AUDIO_WRAP_HOOK(21, 3308)
