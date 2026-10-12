// Differential test of lifted functions against their recompiled originals (tools/lift/difftest).
//
// For every function of one generated file: run the original (__imp__sub_X) and the lifted version
// (sub_X with lifted code on) from the same register state, against the same synthetic guest memory
// (every address holds deterministic data), with every call to another function replaced by a
// recording stub. Then compare what is observable: memory contents, the arguments of each call, the
// registers the function returns (outputs) and the callee-saved registers it must preserve.
//
//   difftest_N.exe [first-address]      prints MISMATCH lines and a summary
#include <rex/ppc/context.h>

#include <windows.h>
#include <xmmintrin.h>

#include <atomic>
#include <cinttypes>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <thread>
#include <vector>

#include "difftest.h"

// ---- what the lifted objects expect (normally in src/game/lifted_switch.cpp) ----------------------
namespace f2 {
std::atomic<bool> g_lifted_enabled{false};
std::atomic<bool> g_lifted_file_on[512];
std::atomic<bool> g_lifted_ranges_active{false};
bool LiftedRangeDisabled(uint32_t) { return false; }
[[noreturn]] void LiftedNullCall(const char*, uint32_t) { RaiseException(0xE0F20001, 0, 0, nullptr); for (;;) {} }
struct LiftedStack {
  uint32_t addr[256];
  uint32_t depth;
};
thread_local LiftedStack t_lifted_stack{};
}  // namespace f2

// Indirect calls to addresses outside the code range go through the runtime's resolver: here they
// reach the recording stub as well (the real resolver needs the whole runtime).
extern "C" void f2t_IndirectStub(PPCContext& ctx, uint8_t* base);
namespace rex::runtime {
PPCFunc* ResolveIndirectFunction(uint32_t target) {
  if (target == 0) RaiseException(0xE0F20001, 0, 0, nullptr);  // (same outcome as the lifted code's null check)
  return &f2t_IndirectStub;
}
}  // namespace rex::runtime

namespace f2t {
static uint8_t* g_base = nullptr;
static constexpr uint64_t kGuestSpan = 0x100002000ull;
static constexpr uint32_t kPage = 0x1000;
static constexpr uint32_t kStackTop = 0x70000000;
static constexpr uint32_t kTableLo = 0x83620000, kTableHi = 0x83620000 + 0x2300000;
static std::set<uint32_t> g_committed;  // guest page addresses
// Host pages touched past the guest's 4 GB (a typed pointer to an object at 0xFFFFFFxx plus a field offset, or
// the gap page below the 0xE0000000 shift): the original wraps such an address in 32 bits, the lifted code's
// GameObject<T>* does not. They are filled like the wrapped guest page so both read the same values.
static std::set<uint64_t> g_alias;  // host offsets of those pages
static thread_local bool t_in_test = false;

static uint64_t HostOf(uint32_t g) { return uint64_t(g) + (g >= 0xE0000000u ? 0x1000u : 0u); }
static uint32_t GuestOf(uint64_t hoff) { return uint32_t(hoff >= 0xE0001000ull ? hoff - 0x1000 : hoff); }

static uint32_t Mix(uint64_t x) {
  x ^= x >> 33; x *= 0xff51afd7ed558ccdull; x ^= x >> 33; x *= 0xc4ceb9fe1a85ec53ull; x ^= x >> 33;
  return uint32_t(x);
}
// Deterministic content of the guest word at a (4-aligned): plausible code/data addresses, small
// integers and raw bits.
// 0: sparse memory, sparse arguments; 1: dense; 2: all-zero memory, pointer arguments (loops over counts and
// lists end at once); 3: small numbers and a few pointers
static int g_profile = 0;
static bool g_relaxed = false;  // tools/rewrite: 32-bit arithmetic artefacts in call arguments are not differences
static uint32_t WordAt(uint32_t a) {
  uint32_t h = Mix(a * 0x9E3779B97F4A7C15ull + 12345);
  if (g_profile == 2) return 0;
  if (g_profile == 3) {
    switch (h & 7) {
      case 0: return 0x40000000u + ((h >> 4) & 0x00FFFFF0u);
      case 1: return 1;
      case 2: return 2;
      case 3: return (h >> 4) & 0x3;
      default: return 0;
    }
  }
  if (g_profile >= 4) {
    // mixed (tools/rewrite): dense values with a share of zero words that differs per profile, so branches on
    // "is this field zero" run both ways across the profiles (4: half zero, 5: a quarter, 6: three quarters)
    uint32_t z = Mix(a * 0x9E3779B97F4A7C15ull + uint64_t(g_profile) * 7919u);
    unsigned zero_pct = g_profile == 4 ? 50 : g_profile == 5 ? 25 : 75;
    if (z % 100 < zero_pct) return 0;
  }
  if (g_profile == 1 || g_profile >= 4) {
    // dense: most words are pointers, flags, small numbers or floats, so the paths behind "if (p->x)" run
    switch (h & 15) {
      case 0: return 0x82170000u + ((h >> 4) % (0x1152A3Cu / 4)) * 4;
      case 1: case 2: case 3: case 4: case 5: return 0x40000000u + ((h >> 4) & 0x00FFFFF0u);
      case 6: case 7: case 8: return (h >> 4) & 0x7;
      case 9: return (h >> 4) & 0xFF;
      case 10: return h;
      case 11: return 0x3F800000u + ((h >> 4) & 0x00FFFFFFu);  // a float between 1 and 4
      case 12: return 0xFFFFFFFFu;
      default: return 0;
    }
  }
  // mostly zero (lists end, counts are small, pointers are null) so loops finish
  switch (h & 15) {
    case 0: return 0x82170000u + ((h >> 4) % (0x1152A3Cu / 4)) * 4;  // code address (function pointers)
    case 1: case 2: return 0x40000000u + ((h >> 4) & 0x00FFFFF0u);    // heap-like address
    case 3: case 4: return (h >> 4) & 0x7;                             // small integer
    case 5: return h;
    default: return 0;
  }
}
extern "C" void f2t_IndirectStub(PPCContext& ctx, uint8_t* base);

static void FillPageAt(uint8_t* p, uint32_t g) {
  if (g >= kTableLo && g < kTableHi) {
    // function table of the recompiled code (REX_LOOKUP_FUNC): every entry -> the indirect-call stub
    auto* e = reinterpret_cast<void**>(p);
    for (uint32_t i = 0; i < kPage / 8; ++i) e[i] = reinterpret_cast<void*>(&f2t_IndirectStub);
    return;
  }
  for (uint32_t i = 0; i < kPage; i += 4) {
    uint32_t v = WordAt(g + i);
    v = _byteswap_ulong(v);
    std::memcpy(p + i, &v, 4);
  }
}

static LONG WINAPI Veh(EXCEPTION_POINTERS* e);

// ---- per-run recording -------------------------------------------------------------------------
struct CallRec {
  uint32_t callee;
  std::vector<uint64_t> values;
  // registers the callee only passes on (CalleeInfo::gfwd/ffwd): register (0-31 r, 32-63 f), value, and
  // whether the value is still the one the function under test was entered with (a passed-through argument)
  std::vector<uint8_t> fwd_reg;
  std::vector<uint64_t> fwd_val;
  std::vector<uint8_t> fwd_entry;
  bool operator==(const CallRec& o) const { return callee == o.callee && values == o.values; }
};
struct RunResult {
  std::vector<CallRec> calls;
  uint32_t exception = 0;  // 0 = returned
  bool timeout = false;
  PPCContext ctx;
  std::map<uint32_t, std::vector<uint8_t>> pages;  // final contents of the pages it touched
};
static thread_local RunResult* t_run = nullptr;
static thread_local const PPCContext* t_entry = nullptr;  // the state the run started with
static thread_local uint32_t t_call_count = 0;
static thread_local uint64_t t_bail_rsp = 0;
static constexpr size_t kMaxCalls = 64;

[[noreturn]] static void BailOut() { ExitThread(1); }

void OnCall(const CalleeInfo& c, PPCContext& ctx) {
  RunResult* r = t_run;
  if (!r) return;
  CallRec rec;
  rec.callee = c.addr;
  // integer arguments (32 or 64 bits as the callee reads them), float and vector arguments
  for (int i = 0; i < 32; ++i)
    if ((c.gin >> i) & 1) rec.values.push_back(((c.gwide >> i) & 1) ? Gpr(ctx, i).u64 : Gpr(ctx, i).u32);
  for (int i = 0; i < 32; ++i)
    if ((c.fin >> i) & 1) rec.values.push_back(Fpr(ctx, i).u64);
  for (int i = 0; i < 64; ++i)
    if ((c.vin >> i) & 1) {
      rec.values.push_back(Vr(ctx, i).u64[0]);
      rec.values.push_back(Vr(ctx, i).u64[1]);
    }
  if ((c.gfwd | c.ffwd) && t_entry) {
    for (int i = 0; i < 32; ++i)
      if (((c.gfwd & ~c.gin) >> i) & 1) {
        rec.fwd_reg.push_back(uint8_t(i));
        rec.fwd_val.push_back(Gpr(ctx, i).u64);
        rec.fwd_entry.push_back(Gpr(ctx, i).u32 == Gpr(const_cast<PPCContext&>(*t_entry), i).u32 &&
                                Gpr(const_cast<PPCContext&>(*t_entry), i).u32 != 0);
      }
    for (int i = 0; i < 32; ++i)
      if (((c.ffwd & ~c.fin) >> i) & 1) {
        rec.fwd_reg.push_back(uint8_t(32 + i));
        rec.fwd_val.push_back(Fpr(ctx, i).u64);
        rec.fwd_entry.push_back(Fpr(ctx, i).u64 == Fpr(const_cast<PPCContext&>(*t_entry), i).u64 &&
                                Fpr(const_cast<PPCContext&>(*t_entry), i).u64 != 0);
      }
  }
  r->calls.push_back(std::move(rec));
  // results: every register the callee may change gets a deterministic value
  uint32_t k = ++t_call_count;
  for (int i = 0; i < 32; ++i)
    if ((c.gmod >> i) & 1) {
      uint32_t v = Mix((uint64_t(c.addr) << 20) ^ (k << 8) ^ i);
      // mixed profiles (tools/rewrite): the result register is a small number half the time, so code that
      // compares a call's result with a constant (a kind, a state, an error code) takes both ways
      if (g_profile >= 4 && i == 3 && (Mix(v ^ (uint64_t(g_profile) << 40)) & 1)) v &= 15;
      Gpr(ctx, i).u64 = v;
    }
  for (int i = 0; i < 32; ++i)
    if ((c.fmod >> i) & 1) Fpr(ctx, i).f64 = double(Mix((uint64_t(c.addr) << 21) ^ (k << 8) ^ i) % 10000) / 7.0;
  for (int i = 0; i < 64; ++i)
    if ((c.vmod >> i) & 1) {
      Vr(ctx, i).u64[0] = Mix(c.addr ^ (k << 9) ^ (i << 1));
      Vr(ctx, i).u64[1] = Mix(c.addr ^ (k << 9) ^ (i << 1) ^ 1);
    }
  for (int f = 0; f < 8; ++f)
    if ((c.crmod >> (4 * f)) & 0xF) {
      uint32_t b = Mix(c.addr ^ (k << 10) ^ f);
      auto& cr = Cr(ctx, f);
      cr.lt = b & 1; cr.gt = (b >> 1) & 1; cr.eq = (b >> 2) & 1; cr.so = 0;
    }
  if (c.xermod) ctx.xer.ca = Mix(c.addr ^ k) & 1;
  if (r->calls.size() >= kMaxCalls) {
    // enough to compare; stop here (both versions stop at the same call)
    r->exception = 0xE0F2FFFF;
    BailOut();
  }
}

extern "C" void f2t_IndirectStub(PPCContext& ctx, uint8_t*) { OnCall(kIndirectCallee, ctx); }

// ---- guest memory --------------------------------------------------------------------------------
static void ResetMemory() {
  for (uint32_t g : g_committed) VirtualFree(g_base + HostOf(g), kPage, MEM_DECOMMIT);
  for (uint64_t hoff : g_alias) VirtualFree(g_base + hoff, kPage, MEM_DECOMMIT);
  g_committed.clear();
  g_alias.clear();
}

static LONG WINAPI Veh(EXCEPTION_POINTERS* e) {
  auto* rec = e->ExceptionRecord;
  if (rec->ExceptionCode == EXCEPTION_ACCESS_VIOLATION && rec->NumberParameters >= 2) {
    auto addr = reinterpret_cast<uint8_t*>(rec->ExceptionInformation[1]);
    if (addr >= g_base && addr < g_base + kGuestSpan) {
      uint64_t hoff = uint64_t(addr - g_base) & ~uint64_t(kPage - 1);
      uint32_t g = GuestOf(hoff);
      // the page that faulted is committed (not the guest page it stands for: past 4 GB they differ)
      if (VirtualAlloc(g_base + hoff, kPage, MEM_COMMIT, PAGE_READWRITE)) {
        if (HostOf(g) == hoff) g_committed.insert(g); else g_alias.insert(hoff);
        FillPageAt(g_base + hoff, g);
        return EXCEPTION_CONTINUE_EXECUTION;
      }
    }
  }
  if (t_in_test && t_run) {
    // anything else inside a test run (game assertion traps, host faults): record it and end the run
    t_run->exception = rec->ExceptionCode;
    e->ContextRecord->Rip = reinterpret_cast<DWORD64>(&BailOut);
    e->ContextRecord->Rsp = (t_bail_rsp & ~0xFull) - 8;
    return EXCEPTION_CONTINUE_EXECUTION;
  }
  return EXCEPTION_CONTINUE_SEARCH;
}

static PPCContext InitialContext(uint32_t seed) {
  PPCContext c{};
  for (int i = 0; i < 32; ++i) Gpr(c, i).u64 = WordAt(seed * 131 + i * 4 + 0x40000000u);
  if (g_profile == 2 || g_profile == 3) {
    // arguments: object pointers (r3..r10), small counts elsewhere
    for (int i = 0; i < 32; ++i) {
      uint32_t h = Mix(uint64_t(seed) * 977 + i);
      Gpr(c, i).u64 = (i >= 3 && i <= 10 && (h & 3)) ? 0x40000000u + ((h >> 4) & 0x00FFFFF0u) : ((h >> 8) & 3);
    }
  }
  if (g_profile == 1 || g_profile >= 4) {
    // arguments: mostly object pointers, some numbers
    for (int i = 0; i < 32; ++i) {
      uint32_t h = Mix(uint64_t(seed) * 977 + i);
      uint32_t v;
      switch (h & 7) {
        case 0: case 1: case 2: case 3: v = 0x40000000u + ((h >> 4) & 0x00FFFFF0u); break;
        case 4: v = (h >> 4) & 0xFF; break;
        case 5: v = h; break;
        case 6: v = 0; break;
        default: v = 0u - ((h >> 4) & 0xFF); break;
      }
      Gpr(c, i).u64 = v;
    }
  }
  c.r1.u64 = kStackTop - 0x200;
  c.r2.u64 = 0;
  c.r13.u64 = 0x7E000000;
  for (int i = 0; i < 32; ++i) Fpr(c, i).f64 = double(Mix(seed * 7 + i) % 20000) / 13.0 - 500.0;
  for (int i = 0; i < 64; ++i) {
    Vr(c, i).u64[0] = Mix(seed ^ (i * 2));
    Vr(c, i).u64[1] = Mix(seed ^ (i * 2 + 1));
  }
  for (int f = 0; f < 8; ++f) {
    uint32_t b = Mix(seed + f * 17);
    Cr(c, f).lt = b & 1; Cr(c, f).gt = (b >> 1) & 1; Cr(c, f).eq = (b >> 2) & 1; Cr(c, f).so = 0;
  }
  c.xer.so = 0; c.xer.ov = 0; c.xer.ca = Mix(seed) & 1;
  c.fpscr.csr = 0x1F80;  // host MXCSR as the game runs it: floating-point exceptions masked
  return c;
}

struct Job {
  PPCFunc* fn;
  PPCContext ctx;
  RunResult* result;
  bool lifted;
  const PPCContext* entry = nullptr;
};

static DWORD WINAPI Worker(void* p) {
  auto* job = static_cast<Job*>(p);
  volatile uint64_t marker = 0;
  t_bail_rsp = reinterpret_cast<uint64_t>(&marker) - 256;
  t_run = job->result;
  t_entry = job->entry;
  t_call_count = 0;
  t_in_test = true;
  _mm_setcsr(0x1F80);
  f2::g_lifted_enabled.store(job->lifted);
  job->fn(job->ctx, g_base);
  job->result->ctx = job->ctx;
  t_in_test = false;
  return 0;
}

static bool Recorded(uint32_t g) {
  if (g >= kStackTop - 0x01000000u && g < kStackTop) return false;  // the function's own stack frames
  return g < kTableLo || g >= kTableHi;
}

static void Snapshot(RunResult& r) {
  for (uint32_t g : g_committed) {
    if (!Recorded(g)) continue;
    uint8_t* p = g_base + HostOf(g);
    r.pages[g].assign(p, p + kPage);
  }
  for (uint64_t hoff : g_alias) {
    // writes through a wrapped pointer count as writes to the guest page it stands for
    uint32_t g = GuestOf(hoff);
    if (!Recorded(g)) continue;
    std::vector<uint8_t> fill(kPage);
    FillPageAt(fill.data(), g);
    auto& page = r.pages[g];
    if (page.empty()) page = fill;
    const uint8_t* p = g_base + hoff;
    for (uint32_t i = 0; i < kPage; ++i)
      if (p[i] != fill[i]) page[i] = p[i];
  }
}

static RunResult Run(PPCFunc* fn, const PPCContext& init, bool lifted) {
  RunResult r;
  ResetMemory();
  Job job{fn, init, &r, lifted};
  job.entry = &init;
  job.result->ctx = init;
  HANDLE h = CreateThread(nullptr, 8 << 20, Worker, &job, 0, nullptr);
  // A run is over time when the thread itself has used 500 ms of CPU, not when 500 ms of wall-clock time
  // passed: on a loaded machine (parallel batches, a build) a starved thread looked like an endless loop.
  for (;;) {
    if (WaitForSingleObject(h, 100) != WAIT_TIMEOUT) break;
    FILETIME c, e, k, u;
    uint64_t cpu = 0;
    if (GetThreadTimes(h, &c, &e, &k, &u)) {
      cpu = ((uint64_t(k.dwHighDateTime) << 32 | k.dwLowDateTime) + (uint64_t(u.dwHighDateTime) << 32 | u.dwLowDateTime)) / 10000;
    }
    if (cpu >= 500) {
      TerminateThread(h, 2);
      WaitForSingleObject(h, INFINITE);
      r.timeout = true;
      break;
    }
  }
  CloseHandle(h);
  if (r.exception == 0 && !r.timeout) r.ctx = job.ctx;
  Snapshot(r);
  return r;
}

static std::vector<uint8_t> PageContent(const RunResult& r, uint32_t g) {
  auto it = r.pages.find(g);
  if (it != r.pages.end()) return it->second;
  std::vector<uint8_t> v(kPage);
  for (uint32_t i = 0; i < kPage; i += 4) {
    uint32_t w = _byteswap_ulong(WordAt(g + i));
    std::memcpy(&v[i], &w, 4);
  }
  return v;
}

// Relaxed comparison of one call: equal, or integer arguments that differ only in a carry into bit 32 or in
// the sign extension of a 32-bit value (the original keeps 64-bit registers, a rewrite uses uint32_t / int32_t;
// the game's C code is 32-bit). A 64-bit value truncated to 32 bits still differs.
static bool SameArgs32(const CallRec& a, const CallRec& b) {
  if (a.callee != b.callee || a.values.size() != b.values.size()) return false;
  for (size_t k = 0; k < a.values.size(); ++k) {
    uint64_t x = a.values[k], y = b.values[k];
    if (x == y) continue;
    if (uint32_t(x) != uint32_t(y)) return false;
    uint32_t hx = uint32_t(x >> 32), hy = uint32_t(y >> 32);
    auto small = [](uint32_t h) { return h == 0 || h == 1 || h == 0xFFFFFFFFu; };
    if (!small(hx) || !small(hy)) return false;
  }
  return true;
}

static std::string Compare(const TestFunc& f, RunResult& a, RunResult& b, const PPCContext& init) {
  if (a.timeout || b.timeout)
    return a.timeout && b.timeout ? "" : a.timeout ? "timeout in one version only (the original)"
                                                   : "timeout in one version only (the lifted / rewritten)";
  if (a.exception != b.exception) {
    char buf[96];
    snprintf(buf, sizeof buf, "outcome differs: original exc %08X, lifted exc %08X", a.exception, b.exception);
    return buf;
  }
  size_t n = std::min(a.calls.size(), b.calls.size());
  for (size_t i = 0; i < n; ++i)
    if (!(a.calls[i] == b.calls[i]) && !(g_relaxed && SameArgs32(a.calls[i], b.calls[i]))) {
      char buf[160];
      snprintf(buf, sizeof buf, "call #%zu differs: original -> %08X, lifted -> %08X", i, a.calls[i].callee,
               b.calls[i].callee);
      std::string s = buf;
      if (a.calls[i].callee == b.calls[i].callee) {
        for (size_t k = 0; k < std::min(a.calls[i].values.size(), b.calls[i].values.size()); ++k)
          if (a.calls[i].values[k] != b.calls[i].values[k]) {
            snprintf(buf, sizeof buf, " (argument value #%zu: %" PRIX64 " vs %" PRIX64 ")", k, a.calls[i].values[k],
                     b.calls[i].values[k]);
            s += buf;
            break;
          }
      }
      return s;
    }
  // arguments passed through: where the original hands a callee that only passes it on (to a call through a
  // pointer or an import) the value it was itself entered with, the other version must hand over the same
  // (low 32 bits); a leftover temporary in such a register is not compared
  for (size_t i = 0; i < n; ++i) {
    const CallRec &x = a.calls[i], &y = b.calls[i];
    for (size_t k = 0; k < x.fwd_reg.size() && k < y.fwd_reg.size(); ++k) {
      if (!x.fwd_entry[k]) continue;
      bool fpr = x.fwd_reg[k] >= 32;
      if (fpr ? x.fwd_val[k] != y.fwd_val[k] : uint32_t(x.fwd_val[k]) != uint32_t(y.fwd_val[k])) {
        char buf[200];
        snprintf(buf, sizeof buf, "call #%zu (%08X): %c%d passed through to the callee differs: %" PRIX64 " vs %" PRIX64,
                 i, x.callee, fpr ? 'f' : 'r', x.fwd_reg[k] % 32, x.fwd_val[k], y.fwd_val[k]);
        return buf;
      }
    }
  }
  if (a.calls.size() != b.calls.size()) return "different number of calls";
  std::set<uint32_t> pages;
  for (auto& [g, _] : a.pages) pages.insert(g);
  for (auto& [g, _] : b.pages) pages.insert(g);
  for (uint32_t g : pages)
    if (PageContent(a, g) != PageContent(b, g)) {
      auto pa = PageContent(a, g), pb = PageContent(b, g);
      size_t k = 0;
      while (k < kPage && pa[k] == pb[k]) ++k;
      char buf[160];
      size_t k8 = k & ~size_t(3);
      snprintf(buf, sizeof buf, "memory differs at %08X: original %02X%02X%02X%02X, lifted %02X%02X%02X%02X",
               g + uint32_t(k), pa[k8], pa[k8 + 1], pa[k8 + 2], pa[k8 + 3], pb[k8], pb[k8 + 1], pb[k8 + 2], pb[k8 + 3]);
      return buf;
    }
  if (a.exception == 0) {
    // results the callers read, and preserved registers
    for (int i = 0; i < 32; ++i) {
      bool out = (f.gout >> i) & 1, pres = i >= 14 || i == 1 || i == 2 || i == 13;
      if (!out && !pres) continue;
      uint64_t x = Gpr(a.ctx, i).u64, y = Gpr(b.ctx, i).u64;
      bool wide = pres || ((f.gwide >> i) & 1);
      if (wide ? x != y : uint32_t(x) != uint32_t(y)) {
        char buf[96];
        snprintf(buf, sizeof buf, "r%d after return: %" PRIX64 " vs %" PRIX64, i, x, y);
        return buf;
      }
    }
    for (int i = 0; i < 32; ++i) {
      bool out = (f.fout >> i) & 1, pres = i >= 14;
      if ((out || pres) && Fpr(a.ctx, i).u64 != Fpr(b.ctx, i).u64) {
        char buf[64];
        snprintf(buf, sizeof buf, "f%d after return differs", i);
        return buf;
      }
    }
    for (int fld = 0; fld < 8; ++fld)
      if ((f.crout >> (4 * fld)) & 0xF) {
        auto& x = Cr(a.ctx, fld);
        auto& y = Cr(b.ctx, fld);
        uint32_t m = (f.crout >> (4 * fld)) & 0xF;
        if (((m & 1) && x.lt != y.lt) || ((m & 2) && x.gt != y.gt) || ((m & 4) && x.eq != y.eq)) {
          char buf[64];
          snprintf(buf, sizeof buf, "cr%d after return differs", fld);
          return buf;
        }
      }
  }
  (void)init;
  return "";
}
}  // namespace f2t

int main(int argc, char** argv) {
  using namespace f2t;
  g_base = static_cast<uint8_t*>(VirtualAlloc(nullptr, kGuestSpan, MEM_RESERVE, PAGE_NOACCESS));
  if (!g_base) {
    printf("cannot reserve guest memory\n");
    return 2;
  }
  for (auto& x : f2::g_lifted_file_on) x.store(true);
  AddVectoredExceptionHandler(1, Veh);
  uint32_t first = argc > 1 ? uint32_t(strtoul(argv[1], nullptr, 16)) : 0;
  g_profile = argc > 2 ? atoi(argv[2]) : 0;
  g_relaxed = argc > 3 && atoi(argv[3]) != 0;
  const uint32_t seeds = (g_profile == 1 || g_profile >= 4) ? 8 : 3, seed_base = uint32_t(g_profile) * 1000;
  int tested = 0, mismatched = 0, timeouts = 0, trapped = 0;
  for (size_t i = 0; i < kTestCount; ++i) {
    const TestFunc& f = kTests[i];
    if (f.addr < first) continue;
    printf("TEST %08X\n", f.addr);
    fflush(stdout);
    std::string why;
    for (uint32_t seed = 1; seed <= seeds && why.empty(); ++seed) {
      PPCContext init = InitialContext((seed + seed_base) * 7919 + f.addr);
      RunResult a = Run(f.original, init, false);
      RunResult b = Run(f.lifted, init, true);
      if (a.timeout || b.timeout) {
        // a killed thread may hold the recompiled code's global lock: report and start a fresh process
        if (!(a.timeout && b.timeout))
          printf("MISMATCH sub_%08X: timeout in one version only (%s)\n", f.addr,
                 a.timeout ? "the original" : "the lifted / rewritten");
        printf("RESTART %08X\n", f.addr);
        fflush(stdout);
        ExitProcess(3);
      }
      if (a.exception && a.exception == b.exception) ++trapped;
      why = Compare(f, a, b, init);
    }
    ++tested;
    if (!why.empty()) {
      ++mismatched;
      printf("MISMATCH sub_%08X: %s\n", f.addr, why.c_str());
      fflush(stdout);
    }
  }
  printf("tested %d functions: %d mismatches, %d timeouts, %d runs ended by a trap/limit in both\n", tested,
         mismatched, timeouts, trapped);
  return 0;
}
