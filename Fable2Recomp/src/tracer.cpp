/**
 * @file        src/tracer.cpp
 * @brief       Indirect (vtable) call tracer: histogram of calls whose target lies
 *              inside a guest address window (default: the audio library) made from
 *              outside it. Used to discover the API surface a subsystem exposes to the
 *              game, e.g. XAudio2 voice/engine methods, before replacing it natively.
 */
#include <atomic>
#include <chrono>
#include <cstdint>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include <fmt/format.h>
#include <rex/cvar.h>
#include <rex/logging.h>

REXCVAR_DEFINE_BOOL(trace_indirect_calls, false, "Debug",
                    "Log a histogram of guest indirect calls into [trace_indirect_lo, trace_indirect_hi) "
                    "from callers outside that window, every 10 s.");
REXCVAR_DEFINE_UINT32(trace_indirect_lo, 0x82C40000u, "Debug", "Window start (guest address).");
REXCVAR_DEFINE_UINT32(trace_indirect_hi, 0x82CF0000u, "Debug", "Window end (guest address, exclusive).");

extern "C" bool rex_trace_indirect_enabled = false;

namespace {
struct Entry {
  uint64_t count = 0;
  uint32_t callers[3] = {};
  uint32_t caller_count = 0;
};
std::mutex g_mutex;
std::unordered_map<uint32_t, Entry> g_hist;
std::chrono::steady_clock::time_point g_last_report;
uint32_t g_lo = 0, g_hi = 0;
}  // namespace

extern "C" void rex_trace_indirect(uint32_t target, uint32_t lr) {
  if (target < g_lo || target >= g_hi || (lr >= g_lo && lr < g_hi)) return;
  std::lock_guard<std::mutex> lock(g_mutex);
  Entry& e = g_hist[target];
  ++e.count;
  if (e.caller_count < 3) {
    bool seen = false;
    for (uint32_t i = 0; i < e.caller_count; ++i) seen |= e.callers[i] == lr;
    if (!seen) e.callers[e.caller_count++] = lr;
  }
  auto now = std::chrono::steady_clock::now();
  if (now - g_last_report >= std::chrono::seconds(10)) {
    g_last_report = now;
    std::vector<std::pair<uint32_t, Entry>> rows(g_hist.begin(), g_hist.end());
    std::sort(rows.begin(), rows.end(), [](auto& a, auto& b) { return a.second.count > b.second.count; });
    std::string text;
    for (size_t i = 0; i < rows.size() && i < 60; ++i) {
      text += fmt::format(" {:08X}x{}[", rows[i].first, rows[i].second.count);
      for (uint32_t c = 0; c < rows[i].second.caller_count; ++c) text += fmt::format("{}{:08X}", c ? "," : "", rows[i].second.callers[c]);
      text += "]";
    }
    REXLOG_INFO("Indirect calls into {:08X}-{:08X} (10 s, {} targets):{}", g_lo, g_hi, rows.size(), text);
    g_hist.clear();
  }
}

void StartIndirectTracer() {
  g_lo = REXCVAR_GET(trace_indirect_lo);
  g_hi = REXCVAR_GET(trace_indirect_hi);
  g_last_report = std::chrono::steady_clock::now();
  rex_trace_indirect_enabled = REXCVAR_GET(trace_indirect_calls);
}
