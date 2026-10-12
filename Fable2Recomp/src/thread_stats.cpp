/**
 * @file        src/thread_stats.cpp
 * @brief       Per-thread CPU load, logged every 5 s (cvar thread_cpu_stats).
 *
 *              Lists the busiest named threads of the process (game threads carry their guest names,
 *              e.g. "Texture Streamer (F80000C4)") with the share of one core each used over the
 *              period, so stalls can be attributed to the thread doing the work (streaming, game
 *              logic, audio, the native renderer).
 */
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <tlhelp32.h>

#include <algorithm>
#include <chrono>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include <fmt/format.h>
#include <rex/cvar.h>
#include <rex/logging.h>

REXCVAR_DEFINE_BOOL(thread_cpu_stats, true, "Debug", "Log the busiest threads' CPU load every 5 s");

namespace {

uint64_t FileTime(const FILETIME& t) { return (uint64_t(t.dwHighDateTime) << 32) | t.dwLowDateTime; }

void StatsMain() {
  struct Last {
    uint64_t cpu = 0;
  };
  std::unordered_map<DWORD, Last> last;
  DWORD pid = GetCurrentProcessId();
  auto period_start = std::chrono::steady_clock::now();
  for (;;) {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    auto now = std::chrono::steady_clock::now();
    double period_100ns = std::chrono::duration<double>(now - period_start).count() * 1e7;
    period_start = now;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snap == INVALID_HANDLE_VALUE) continue;
    THREADENTRY32 te{};
    te.dwSize = sizeof(te);
    std::vector<std::pair<double, std::string>> rows;
    double total = 0;
    for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
      if (te.th32OwnerProcessID != pid) continue;
      HANDLE h = OpenThread(THREAD_QUERY_LIMITED_INFORMATION, FALSE, te.th32ThreadID);
      if (!h) continue;
      FILETIME c, e, k, u;
      if (GetThreadTimes(h, &c, &e, &k, &u)) {
        uint64_t cpu = FileTime(k) + FileTime(u);
        auto& l = last[te.th32ThreadID];
        if (l.cpu) {
          double share = (cpu - l.cpu) / period_100ns * 100.0;
          total += share;
          if (share >= 3.0) {
            std::string name = fmt::format("tid {}", te.th32ThreadID);
            PWSTR desc = nullptr;
            if (SUCCEEDED(GetThreadDescription(h, &desc)) && desc) {
              if (desc[0]) {
                std::wstring w(desc);
                name.assign(w.begin(), w.end());
              }
              LocalFree(desc);
            }
            rows.push_back({share, name});
          }
        }
        l.cpu = cpu;
      }
      CloseHandle(h);
    }
    CloseHandle(snap);
    if (rows.empty()) continue;
    std::sort(rows.rbegin(), rows.rend());
    std::string out;
    for (size_t i = 0; i < rows.size() && i < 10; ++i) out += fmt::format(" | {} {:.0f}%", rows[i].second, rows[i].first);
    REXLOG_INFO("Thread CPU 5s (100% = one core, process total {:.0f}%):{}", total, out);
  }
}

}  // namespace

void StartThreadStats() {
  if (!REXCVAR_GET(thread_cpu_stats)) return;
  std::thread(StatsMain).detach();
}
