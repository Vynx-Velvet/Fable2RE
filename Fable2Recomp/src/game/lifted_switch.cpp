// Run-time switches for the lifted game code (lifted/lifted.h).
//
//   lifted_code = false                    every function runs its recompiled original
//   lifted_disable_files = "12,52"         ... only for functions from generated/Fable2_recomp.12.cpp / .52.cpp
//   lifted_disable_ranges = "82C40000-82CF8E10,82790000-827A0000,821B23F8"
//                                          ... only for functions in these guest address ranges
// (to find a lifted function that misbehaves: halve the set until the problem goes away).
// The compiled default of lifted_disable_ranges keeps the XAudio2 library (82C40000-82CF8E10) recompiled, so a
// build without Fable2.toml is safe; a value set in Fable2.toml replaces it, so keep that range in any value
// you set (docs/settings.md).
#include <rex/cvar.h>
#include <fmt/format.h>
#include <windows.h>
#include <rex/logging.h>

#include <atomic>
#include <cstdlib>
#include <mutex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

REXCVAR_DEFINE_BOOL(lifted_code, true, "Mods",
                    "Run the lifted (readable) C++ of the game code where it exists; false = the recompiled "
                    "originals everywhere (for comparing behaviour)");
REXCVAR_DEFINE_STRING(lifted_disable_files, "", "Mods",
                      "Comma-separated generated file numbers whose lifted functions fall back to the recompiled code");
// Default: the XAudio2 library and its mixer routines. Lifted, they make a null vtable call on level load and
// hang cutscenes (research/findings/2026-10-04-full-native-plan.md), so they always run recompiled.
REXCVAR_DEFINE_STRING(lifted_disable_ranges, "82C40000-82CF8E10", "Mods",
                      "Comma-separated guest address ranges (hex, lo-hi or single addresses) whose lifted functions "
                      "fall back to the recompiled code (default: the XAudio2 library, which crashes when lifted)");

namespace f2 {
std::atomic<bool> g_lifted_enabled{true};
std::atomic<bool> g_lifted_file_on[512];
std::atomic<bool> g_lifted_ranges_active{false};

namespace {
std::mutex g_mutex;
std::vector<std::pair<uint32_t, uint32_t>> g_ranges;  // (guarded by g_mutex; copied into g_snapshot)
std::atomic<const std::vector<std::pair<uint32_t, uint32_t>>*> g_snapshot{nullptr};

std::vector<std::string> Split(const std::string& v) {
  std::vector<std::string> out;
  std::stringstream ss(v);
  std::string item;
  while (std::getline(ss, item, ',')) {
    while (!item.empty() && item.front() == ' ') item.erase(item.begin());
    while (!item.empty() && item.back() == ' ') item.pop_back();
    if (!item.empty()) out.push_back(item);
  }
  return out;
}

void Apply() {
  g_lifted_enabled.store(REXCVAR_GET(lifted_code), std::memory_order_relaxed);
  for (auto& f : g_lifted_file_on) f.store(true, std::memory_order_relaxed);
  for (const auto& s : Split(REXCVAR_GET(lifted_disable_files))) {
    int i = std::atoi(s.c_str());
    if (i >= 0 && i < 512) g_lifted_file_on[i].store(false, std::memory_order_relaxed);
  }
  auto* ranges = new std::vector<std::pair<uint32_t, uint32_t>>();
  for (const auto& s : Split(REXCVAR_GET(lifted_disable_ranges))) {
    auto dash = s.find('-');
    uint32_t lo = uint32_t(std::strtoul(s.substr(0, dash).c_str(), nullptr, 16));
    uint32_t hi = dash == std::string::npos ? lo + 1 : uint32_t(std::strtoul(s.substr(dash + 1).c_str(), nullptr, 16));
    ranges->emplace_back(lo, hi);
  }
  g_lifted_ranges_active.store(!ranges->empty(), std::memory_order_relaxed);
  g_snapshot.store(ranges, std::memory_order_release);  // (old snapshots are leaked on purpose: readers may hold them)
  REXLOG_INFO("lifted code: {}{}{}", REXCVAR_GET(lifted_code) ? "on" : "off",
              REXCVAR_GET(lifted_disable_files).empty() ? "" : ", files off: " + REXCVAR_GET(lifted_disable_files),
              REXCVAR_GET(lifted_disable_ranges).empty() ? "" : ", ranges off: " + REXCVAR_GET(lifted_disable_ranges));
}

struct Init {
  Init() {
    for (auto& f : g_lifted_file_on) f.store(true, std::memory_order_relaxed);
    for (const char* name : {"lifted_code", "lifted_disable_files", "lifted_disable_ranges"})
      rex::cvar::RegisterChangeCallback(name, [](std::string_view, std::string_view) {
        std::lock_guard<std::mutex> lock(g_mutex);
        Apply();
      });
  }
} init;
}  // namespace

bool LiftedRangeDisabled(uint32_t address) {
  const auto* r = g_snapshot.load(std::memory_order_acquire);
  if (!r) return false;
  for (const auto& [lo, hi] : *r)
    if (address >= lo && address < hi) return true;
  return false;
}

struct LiftedStack {
  uint32_t addr[256];
  uint32_t depth;
};
thread_local LiftedStack t_lifted_stack{};

namespace {
LPTOP_LEVEL_EXCEPTION_FILTER g_previous_filter = nullptr;

void LogLiftedStack(const char* why) {
  const auto& s = t_lifted_stack;
  std::string text;
  uint32_t n = s.depth < 256 ? s.depth : 256;
  for (uint32_t i = n; i > 0 && n - i < 24; --i) text += fmt::format(" {:08X}", s.addr[i - 1]);
  REXLOG_CRITICAL("lifted code: {} - lifted functions running on this thread (innermost first):{}", why,
                  text.empty() ? " (none)" : text);
}

LONG WINAPI CrashFilter(EXCEPTION_POINTERS* info) {
  LogLiftedStack(fmt::format("crash 0x{:08X} at {}", info->ExceptionRecord->ExceptionCode,
                             info->ExceptionRecord->ExceptionAddress)
                     .c_str());
  return g_previous_filter ? g_previous_filter(info) : EXCEPTION_CONTINUE_SEARCH;
}
}  // namespace

[[noreturn]] void LiftedNullCall(const char* function, uint32_t) {
  LogLiftedStack("call through a null pointer");
  REXLOG_CRITICAL("lifted code: call through a null pointer in {} - switch this function off with "
                  "lifted_disable_ranges and report it", function ? function : "?");
  std::abort();
}

// Called once the configuration is loaded (mod loader start-up).
void RefreshLiftedSwitch() {
  std::lock_guard<std::mutex> lock(g_mutex);
  Apply();
  static bool installed = false;
  if (!installed) {
    installed = true;
    g_previous_filter = SetUnhandledExceptionFilter(CrashFilter);
  }
}
}  // namespace f2
