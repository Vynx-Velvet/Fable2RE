// Fable II PC SDK - checking a hand-written rewrite against the original recompiled function.
//
//   REX_HOOK_RAW(sub_823A5918) {
//     f2::VerifyCall("Debug.SetDrawGameFPS", ctx, base, __imp__sub_823A5918, SetDrawGameFPS_Native,
//                    {{0x8349695F, 1}});
//   }
//
// The original runs first on a copy of the registers; the listed guest memory ranges are then put
// back to their state before the call and the rewrite runs on the real registers. Result registers
// (r3, f1) and the ranges are compared and mismatches logged (the rewrite's results are kept).
//
// Only valid for functions whose side effects stay inside the listed ranges: anything else the
// original does (allocations, calls with side effects, I/O) happens twice. Use it while a rewrite is
// being checked, then call the rewrite directly.
#pragma once

#include <rex/logging.h>
#include <rex/ppc/context.h>

#include <atomic>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <utility>
#include <vector>

#include "fable2/sdk.h"

namespace f2 {

struct VerifyRange {
  uint32_t address, size;
};

template <class Rewrite>
inline void VerifyCall(const char* name, PPCContext& ctx, uint8_t* base, PPCFunc* original, Rewrite rewrite,
                       std::initializer_list<VerifyRange> ranges, int max_reports = 8) {
  static std::atomic<int> reports{0};
  static std::atomic<uint64_t> calls{0};
  std::vector<std::vector<uint8_t>> before, after_original;
  for (const auto& r : ranges) {
    const uint8_t* p = HostPtr(r.address);
    before.emplace_back(p, p + r.size);
  }
  PPCContext reference = ctx;
  original(reference, base);
  for (const auto& r : ranges) {
    uint8_t* p = HostPtr(r.address);
    after_original.emplace_back(p, p + r.size);
  }
  size_t i = 0;
  for (const auto& r : ranges) std::memcpy(HostPtr(r.address), before[i++].data(), r.size);
  rewrite(ctx, base);
  uint64_t n = calls.fetch_add(1) + 1;
  bool regs_differ = reference.r3.u64 != ctx.r3.u64 || reference.f1.u64 != ctx.f1.u64;
  i = 0;
  for (const auto& r : ranges) {
    const uint8_t* now = HostPtr(r.address);
    const auto& want = after_original[i++];
    for (uint32_t k = 0; k < r.size; ++k) {
      if (now[k] != want[k]) {
        if (reports.fetch_add(1) < max_reports)
          REXLOG_WARN("verify {}: call {} memory {:08X} = {:02X}, original wrote {:02X}", name, n, r.address + k,
                      now[k], want[k]);
        break;
      }
    }
  }
  if (regs_differ && reports.fetch_add(1) < max_reports)
    REXLOG_WARN("verify {}: call {} r3 {:X} / f1 {} - original r3 {:X} / f1 {}", name, n, ctx.r3.u64, ctx.f1.f64,
                reference.r3.u64, reference.f1.f64);
  if (n == 1 || (n & (n - 1)) == 0)  // 1, 2, 4, 8, ... : progress without flooding the log
    REXLOG_INFO("verify {}: {} calls checked, {} mismatches reported", name, n, reports.load());
}

}  // namespace f2
