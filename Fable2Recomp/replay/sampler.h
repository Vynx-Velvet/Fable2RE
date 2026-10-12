// Minimal in-process sampling profiler for the replayer (--sample): samples one thread's
// instruction pointer and its first callers, symbolizes with dbghelp at the end.
#pragma once

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <dbghelp.h>
#include <timeapi.h>

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

class ReplaySampler {
 public:
  // Starts sampling `target` (a real thread handle) every `interval_us`, paused until Resume().
  void Start(HANDLE target, int interval_us = 500) {
    target_ = target;
    thread_ = std::thread([this, interval_us] {
      timeBeginPeriod(1);
      while (!stop_) {
        if (running_) Sample();
        std::this_thread::sleep_for(std::chrono::microseconds(interval_us));
      }
    });
  }
  void Resume() { running_ = true; }
  void Pause() { running_ = false; }
  void Stop() {
    stop_ = true;
    if (thread_.joinable()) thread_.join();
  }
  void Report(size_t top = 40) {
    HANDLE proc = GetCurrentProcess();
    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
    SymInitialize(proc, nullptr, TRUE);
    auto name = [&](uint64_t a) -> std::string {
      alignas(SYMBOL_INFO) char buf[sizeof(SYMBOL_INFO) + 512];
      auto* s = reinterpret_cast<SYMBOL_INFO*>(buf);
      s->SizeOfStruct = sizeof(SYMBOL_INFO);
      s->MaxNameLen = 511;
      DWORD64 disp = 0;
      if (SymFromAddr(proc, a, &disp, s)) return std::string(s->Name, std::min<size_t>(s->NameLen, 160));
      char hex[32];
      std::snprintf(hex, sizeof(hex), "0x%llx", (unsigned long long)a);
      return hex;
    };
    // Aggregate by function name (self = leaf, incl = anywhere in the first frames).
    std::unordered_map<std::string, uint32_t> self, incl;
    for (auto& [a, n] : self_) self[name(a)] += n;
    for (auto& [a, n] : incl_) incl[name(a)] += n;
    auto print = [&](const char* title, std::unordered_map<std::string, uint32_t>& m) {
      std::vector<std::pair<uint32_t, std::string>> v;
      for (auto& [k, n] : m) v.push_back({n, k});
      std::sort(v.rbegin(), v.rend());
      std::printf("sampler %s (%u samples):\n", title, samples_);
      for (size_t i = 0; i < v.size() && i < top; ++i)
        std::printf("  %5.1f%%  %s\n", 100.0 * v[i].first / std::max(1u, samples_), v[i].second.c_str());
    };
    print("self", self);
    print("inclusive (8 frames)", incl);
    SymCleanup(proc);
  }

 private:
  void Sample() {
    // Nothing between Suspend and Resume may allocate or take locks the target could hold
    // (heap lock): fixed buffers only.
    uint64_t frames[9];
    int n = 0;
    if (SuspendThread(target_) == DWORD(-1)) return;
    CONTEXT ctx{};
    ctx.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
    if (GetThreadContext(target_, &ctx)) {
      frames[n++] = ctx.Rip;
      for (int depth = 0; depth < 8; ++depth) {
        DWORD64 image_base = 0;
        PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(ctx.Rip, &image_base, nullptr);
        if (!fn) break;
        PVOID handler = nullptr;
        DWORD64 establisher = 0;
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, image_base, ctx.Rip, fn, &ctx, &handler, &establisher, nullptr);
        if (!ctx.Rip) break;
        frames[n++] = ctx.Rip;
      }
    }
    ResumeThread(target_);
    if (!n) return;
    ++samples_;
    ++self_[Func(frames[0])];
    uint64_t seen[9];
    int nseen = 0;
    for (int i = 0; i < n; ++i) {
      uint64_t fa = Func(frames[i]);
      if (std::find(seen, seen + nseen, fa) != seen + nseen) continue;
      seen[nseen++] = fa;
      ++incl_[fa];
    }
  }
  // Function start for an address (so samples aggregate per function before symbolizing).
  static uint64_t Func(uint64_t pc) {
    DWORD64 image_base = 0;
    if (PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, &image_base, nullptr)) return image_base + fn->BeginAddress;
    return pc;
  }
  HANDLE target_ = nullptr;
  std::thread thread_;
  std::atomic<bool> running_{false}, stop_{false};
  uint32_t samples_ = 0;
  std::unordered_map<uint64_t, uint32_t> self_, incl_;
};
