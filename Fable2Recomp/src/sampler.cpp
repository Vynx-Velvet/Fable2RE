/**
 * @file        src/sampler.cpp
 *
 * @brief       In-process sampling profiler for one named thread.
 *
 *              Every cpu_sampler_interval_us it suspends the target thread just
 *              long enough to copy its register context, resumes it, then unwinds
 *              the copied context with RtlVirtualUnwind (no debugger, no pauses
 *              the player can notice). Every 10 s it logs the hottest leaf and
 *              inclusive addresses as module+offset; tools/symbolize_samples.py
 *              turns those into function names with llvm-symbolizer and the PDB.
 *
 *              Enable with cpu_sampler_thread = "GPU Commands" in Fable2.toml.
 */

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <tlhelp32.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include <fmt/format.h>
#include <rex/cvar.h>
#include <rex/logging.h>

REXCVAR_DEFINE_STRING(cpu_sampler_thread, "", "Debug",
                      "Name (SetThreadDescription) of a thread to sample-profile in process; the "
                      "hottest module+offset addresses are logged every 10 s.");
REXCVAR_DEFINE_INT32(cpu_sampler_interval_us, 1000, "Debug", "Sampling interval in microseconds.");

namespace {

struct Hist {
  std::unordered_map<uint64_t, uint32_t> self, inclusive;
  uint32_t samples = 0, unwound = 0;
};

// Stack accesses through calls that fail cleanly (clang's __try only catches faults raised inside
// called functions; a direct read of a bad stack slot crashed the process).
bool ReadSlot(uint64_t address, uint64_t* value) {
  SIZE_T got = 0;
  return ReadProcessMemory(GetCurrentProcess(), reinterpret_cast<LPCVOID>(address), value, 8, &got) && got == 8;
}

__declspec(noinline) bool SafeUnwind(DWORD64 image_base, PRUNTIME_FUNCTION fn, CONTEXT* ctx) {
  __try {
    PVOID handler_data = nullptr;
    DWORD64 establisher = 0;
    RtlVirtualUnwind(UNW_FLAG_NHANDLER, image_base, ctx->Rip, fn, ctx, &handler_data, &establisher, nullptr);
    return true;
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    return false;
  }
}

HANDLE FindThreadByDescription(const std::wstring& wanted) {
  HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
  if (snap == INVALID_HANDLE_VALUE) return nullptr;
  THREADENTRY32 te{};
  te.dwSize = sizeof(te);
  HANDLE found = nullptr;
  DWORD pid = GetCurrentProcessId();
  for (BOOL ok = Thread32First(snap, &te); ok && !found; ok = Thread32Next(snap, &te)) {
    if (te.th32OwnerProcessID != pid) continue;
    HANDLE h = OpenThread(THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME | THREAD_QUERY_INFORMATION, FALSE,
                          te.th32ThreadID);
    if (!h) continue;
    PWSTR desc = nullptr;
    if (SUCCEEDED(GetThreadDescription(h, &desc)) && desc) {
      if (std::wstring(desc).rfind(wanted, 0) == 0) found = h;  // prefix: names end in the handle
      LocalFree(desc);
    }
    if (!found) CloseHandle(h);
  }
  CloseHandle(snap);
  return found;
}

std::string Describe(uint64_t addr) {
  HMODULE mod = nullptr;
  if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                         reinterpret_cast<LPCSTR>(addr), &mod) && mod) {
    char path[MAX_PATH];
    DWORD n = GetModuleFileNameA(mod, path, MAX_PATH);
    std::string name = n ? std::string(path) : "?";
    size_t slash = name.find_last_of("\\/");
    if (slash != std::string::npos) name = name.substr(slash + 1);
    return fmt::format("{}+0x{:x}", name, addr - reinterpret_cast<uint64_t>(mod));
  }
  return fmt::format("0x{:x}", addr);
}

std::string Top(const std::unordered_map<uint64_t, uint32_t>& m, size_t n, uint32_t total) {
  std::vector<std::pair<uint64_t, uint32_t>> v(m.begin(), m.end());
  std::partial_sort(v.begin(), v.begin() + std::min(n, v.size()), v.end(),
                    [](auto& a, auto& b) { return a.second > b.second; });
  std::string out;
  for (size_t i = 0; i < std::min(n, v.size()); ++i) {
    out += fmt::format(" {}={:.1f}%", Describe(v[i].first), 100.0 * v[i].second / std::max(1u, total));
  }
  return out;
}

void SamplerMain() {
  std::string name = REXCVAR_GET(cpu_sampler_thread);
  std::wstring wanted(name.begin(), name.end());
  HANDLE target = nullptr;
  while (!target) {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    target = FindThreadByDescription(wanted);
  }
  REXLOG_INFO("Sampler: profiling thread '{}' every {} us", name, REXCVAR_GET(cpu_sampler_interval_us));
  const auto interval = std::chrono::microseconds(std::max(200, REXCVAR_GET(cpu_sampler_interval_us)));
  Hist hist;
  auto last_report = std::chrono::steady_clock::now();
  for (;;) {
    std::this_thread::sleep_for(interval);
    CONTEXT ctx{};
    ctx.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
    if (SuspendThread(target) == DWORD(-1)) break;
    BOOL got = GetThreadContext(target, &ctx);
    ResumeThread(target);
    if (!got) continue;
    ++hist.samples;
    ++hist.self[ctx.Rip];
    // Unwind the copy after resuming: never hold the target suspended while
    // touching loader structures.
    uint64_t seen[24];
    int depth = 0;
    seen[depth++] = ctx.Rip;
    for (int i = 0; i < 20 && ctx.Rip; ++i) {
      DWORD64 image_base = 0;
      PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(ctx.Rip, &image_base, nullptr);
      if (!fn) {
        // Leaf function without unwind info: return address is at RSP.
        uint64_t ret = 0;
        if (!ReadSlot(ctx.Rsp, &ret)) break;
        ctx.Rip = ret;
        ctx.Rsp += 8;
      } else if (!SafeUnwind(image_base, fn, &ctx)) {
        break;
      }
      if (!ctx.Rip || depth >= 24) break;
      seen[depth++] = ctx.Rip;
    }
    if (depth > 1) ++hist.unwound;
    // Inclusive: count each distinct frame address once per sample.
    for (int i = 0; i < depth; ++i) {
      bool dup = false;
      for (int j = 0; j < i; ++j) dup |= seen[j] == seen[i];
      if (!dup) ++hist.inclusive[seen[i]];
    }
    auto now = std::chrono::steady_clock::now();
    if (now - last_report >= std::chrono::seconds(10)) {
      last_report = now;
      REXLOG_INFO("Sampler 10s '{}': {} samples ({} unwound) | self:{}", name, hist.samples, hist.unwound,
                  Top(hist.self, 24, hist.samples));
      REXLOG_INFO("Sampler 10s '{}': inclusive:{}", name, Top(hist.inclusive, 32, hist.samples));
      hist = Hist{};
    }
  }
}

}  // namespace

void StartCpuSampler() {
  if (REXCVAR_GET(cpu_sampler_thread).empty()) return;
  std::thread(SamplerMain).detach();
}
