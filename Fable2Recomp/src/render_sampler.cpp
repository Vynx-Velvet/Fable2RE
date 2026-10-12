// In-process sampling profiler (cvar profile_sampler): samples the instruction pointer of the native
// renderer thread and of the game's render thread (the thread issuing D3D calls) about 1000 times a
// second each and logs the hottest functions and source lines every 10 seconds, resolved through
// Fable2.pdb (public symbols cover the recompiled sub_XXXXXXXX functions; the runtime and system DLLs
// resolve through their own PDBs/exports).
#include <rex/cvar.h>
#include <rex/logging.h>

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <dbghelp.h>
#include <mmsystem.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include <fmt/format.h>

REXCVAR_DEFINE_BOOL(profile_sampler, false, "Render",
                    "Sample the render threads ~1000x/s and log the hottest functions every 10 s");

namespace {
// Two targets: the native renderer's own thread (pinned) and the game's render thread that issues
// the D3D calls ("3D Engine": recompiled game code plus the recording hooks).
std::atomic<uint32_t> g_target_tid{0};
std::atomic<uint32_t> g_game_render_tid{0};
std::atomic<bool> g_started{false};

// Stack reads of the sampled thread can fault (it keeps running after the context copy); these
// helpers keep every access in a call that fails cleanly (clang's __try only catches faults raised
// inside called functions).
bool ReadStackSlot(uint64_t address, uint64_t* value) {
  SIZE_T got = 0;
  return ReadProcessMemory(GetCurrentProcess(), reinterpret_cast<LPCVOID>(address), value, 8, &got) && got == 8;
}

__declspec(noinline) bool SafeVirtualUnwind(DWORD64 image_base, PRUNTIME_FUNCTION fn, CONTEXT* ctx) {
  __try {
    PVOID handler_data = nullptr;
    DWORD64 establisher = 0;
    RtlVirtualUnwind(UNW_FLAG_NHANDLER, image_base, ctx->Rip, fn, ctx, &handler_data, &establisher, nullptr);
    return true;
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    return false;
  }
}

std::string Symbolize(HANDLE process, uint64_t address) {
  alignas(SYMBOL_INFO) char buffer[sizeof(SYMBOL_INFO) + 256];
  auto* sym = reinterpret_cast<SYMBOL_INFO*>(buffer);
  sym->SizeOfStruct = sizeof(SYMBOL_INFO);
  sym->MaxNameLen = 255;
  DWORD64 displacement = 0;
  IMAGEHLP_MODULE64 mod{};
  mod.SizeOfStruct = sizeof(mod);
  std::string module = SymGetModuleInfo64(process, address, &mod) ? mod.ModuleName : "?";
  if (SymFromAddr(process, address, &displacement, sym)) return module + "!" + sym->Name;
  return module + "!" + fmt::format("{:X}", address);
}

// Source line of an address ("file.cpp:123"), empty without line information.
std::string SourceLine(HANDLE process, uint64_t address) {
  IMAGEHLP_LINE64 line{};
  line.SizeOfStruct = sizeof(line);
  DWORD displacement = 0;
  if (!SymGetLineFromAddr64(process, address, &displacement, &line) || !line.FileName) return {};
  std::string file = line.FileName;
  size_t slash = file.find_last_of("/\\");
  if (slash != std::string::npos) file = file.substr(slash + 1);
  return fmt::format("{}:{}", file, line.LineNumber);
}

struct Target {
  const char* label;
  uint32_t thread_id = 0;
  HANDLE thread = nullptr;
  std::unordered_map<uint64_t, uint32_t> by_address, inclusive;
  struct PairHash {
    size_t operator()(const std::pair<uint64_t, uint64_t>& p) const {
      return std::hash<uint64_t>()(p.first * 31 + p.second);
    }
  };
  std::unordered_map<std::pair<uint64_t, uint64_t>, uint32_t, PairHash> leaf_caller;
  uint32_t samples = 0;

  void Sample(uint32_t tid) {
    if (!tid) return;
    if (tid != thread_id) {
      if (thread) CloseHandle(thread);
      thread = OpenThread(THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT | THREAD_QUERY_INFORMATION, FALSE, tid);
      thread_id = tid;
      by_address.clear();
      inclusive.clear();
      leaf_caller.clear();
      samples = 0;
    }
    if (!thread) return;
    if (SuspendThread(thread) == DWORD(-1)) return;
    CONTEXT ctx{};
    ctx.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
    bool ok = GetThreadContext(thread, &ctx) != 0;
    ResumeThread(thread);
    if (!ok) return;
    ++by_address[ctx.Rip];
    ++samples;
    // Unwind the copied context (after resuming) for inclusive time.
    uint64_t seen[32];
    int depth = 0;
    seen[depth++] = ctx.Rip;
    for (int i = 0; i < 30 && ctx.Rip; ++i) {
      DWORD64 image_base = 0;
      PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(ctx.Rip, &image_base, nullptr);
      if (!fn) {
        uint64_t ret = 0;
        if (!ReadStackSlot(ctx.Rsp, &ret)) break;
        ctx.Rip = ret;
        ctx.Rsp += 8;
      } else if (!SafeVirtualUnwind(image_base, fn, &ctx)) {
        break;
      }
      if (!ctx.Rip || depth >= 32) break;
      seen[depth++] = ctx.Rip;
    }
    for (int i = 0; i < depth; ++i) inclusive[seen[i]]++;
    if (depth > 1) ++leaf_caller[{seen[0], seen[1]}];
  }

  void Report(HANDLE process) {
    if (!samples) return;
    std::unordered_map<std::string, uint32_t> by_symbol, by_module, incl_symbol, by_line;
    std::unordered_map<uint64_t, std::string> names;
    auto name_of = [&](uint64_t a) -> const std::string& {
      auto it = names.find(a);
      if (it == names.end()) it = names.emplace(a, Symbolize(process, a)).first;
      return it->second;
    };
    for (const auto& [address, count] : by_address) {
      const std::string& name = name_of(address);
      by_symbol[name] += count;
      by_module[name.substr(0, name.find('!'))] += count;
      // Hot source lines of our own code (where inside a function the time goes).
      if (name.rfind("Fable2!", 0) == 0) {
        std::string line = SourceLine(process, address);
        if (!line.empty()) by_line[line + "  " + name.substr(7, 60)] += count;
      }
    }
    // (Inclusive per function: a function appearing at several return addresses of one stack is
    // counted per address - an upper bound for recursive code.)
    for (const auto& [address, count] : inclusive) incl_symbol[name_of(address)] += count;
    auto top = [](const std::unordered_map<std::string, uint32_t>& m, size_t n) {
      std::vector<std::pair<uint32_t, std::string>> v;
      for (const auto& [k, c] : m) v.push_back({c, k});
      std::sort(v.rbegin(), v.rend());
      if (v.size() > n) v.resize(n);
      return v;
    };
    std::string modules;
    for (const auto& [c, k] : top(by_module, 8)) modules += fmt::format(" {} {:.1f}%", k, 100.0 * c / samples);
    REXLOG_INFO("profile: {} samples of {} thread {}; modules:{}", samples, label, thread_id, modules);
    for (const auto& [c, k] : top(by_symbol, 40)) REXLOG_INFO("profile:   self {:5.1f}%  {}", 100.0 * c / samples, k);
    for (const auto& [c, k] : top(incl_symbol, 60))
      REXLOG_INFO("profile:   incl {:5.1f}%  {}", 100.0 * c / samples, k);
    {
      // Hot leaf functions by caller (who calls memchr, memmove, ...).
      std::unordered_map<std::string, uint32_t> pairs;
      for (const auto& [pc, count] : leaf_caller) pairs[name_of(pc.first) + "  <-  " + name_of(pc.second)] += count;
      for (const auto& [c, k] : top(pairs, 30)) REXLOG_INFO("profile:   from {:5.1f}%  {}", 100.0 * c / samples, k);
    }
    for (const auto& [c, k] : top(by_line, 30)) REXLOG_INFO("profile:   line {:5.1f}%  {}", 100.0 * c / samples, k);
    by_address.clear();
    inclusive.clear();
    leaf_caller.clear();
    samples = 0;
  }
};

void SamplerThread() {
  HANDLE process = GetCurrentProcess();
  SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
  SymInitialize(process, nullptr, TRUE);
  timeBeginPeriod(1);
  Target renderer{"render"}, game{"game render (3D Engine)"};
  auto period_start = std::chrono::steady_clock::now();
  for (;;) {
    Sleep(1);
    if (!REXCVAR_GET(profile_sampler)) continue;
    uint32_t tid = g_target_tid.load(std::memory_order_relaxed);
    uint32_t game_tid = g_game_render_tid.load(std::memory_order_relaxed);
    renderer.Sample(tid);
    if (game_tid && game_tid != tid) game.Sample(game_tid);
    if (std::chrono::steady_clock::now() - period_start < std::chrono::seconds(10)) continue;
    period_start = std::chrono::steady_clock::now();
    renderer.Report(process);
    game.Report(process);
  }
}
}  // namespace

// Called from the D3D hooks with the render thread's id; starts the sampler on first use.
void Sampler_SetRenderThread(uint32_t tid);
static std::atomic<bool> g_sampler_pinned{false};
// The native renderer's own thread: profiled instead of the game thread that calls D3D (which is
// then profiled as the second target).
void Sampler_PinRenderThread(uint32_t tid) {
  g_sampler_pinned = false;
  Sampler_SetRenderThread(tid);
  g_sampler_pinned = true;
}

void Sampler_SetRenderThread(uint32_t tid) {
  if (g_sampler_pinned.load()) {
    if (tid != g_target_tid.load(std::memory_order_relaxed)) g_game_render_tid.store(tid, std::memory_order_relaxed);
    return;
  }
  g_target_tid.store(tid, std::memory_order_relaxed);
  if (!g_started.exchange(true)) std::thread(SamplerThread).detach();
}
