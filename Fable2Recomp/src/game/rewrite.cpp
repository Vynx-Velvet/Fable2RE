// Run-time switch for hand-written replacements (see rewrite.h).
#include "game/rewrite.h"

#include "generated/Fable2_init.h"

#include <rex/cvar.h>
#include <rex/logging.h>

#include <cstring>
#include <deque>
#include <mutex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

REXCVAR_DEFINE_STRING(rewrites_disabled, "", "Mods",
                      "Comma-separated modules of hand-written game code to switch back to the original "
                      "recompiled functions (e.g. \"combat.health,tuning\"); see src/game/rewrite.h");

namespace f2 {
namespace {
struct State {
  std::mutex mutex;
  std::deque<RewriteModule> modules;  // (deque: addresses stay valid)
  std::string last_value;
  bool callback_registered = false;
  std::vector<std::pair<std::string, std::string>> registered;  // (module, function)
};
State& S() {
  static State s;
  return s;
}

std::set<std::string> ParseList(const std::string& value) {
  std::set<std::string> out;
  std::stringstream ss(value);
  std::string item;
  while (std::getline(ss, item, ',')) {
    while (!item.empty() && item.front() == ' ') item.erase(item.begin());
    while (!item.empty() && item.back() == ' ') item.pop_back();
    if (!item.empty()) out.insert(item);
  }
  return out;
}

// (Called with the mutex held.)
void Apply(State& s, const std::string& value) {
  std::set<std::string> disabled = ParseList(value);
  for (RewriteModule& m : s.modules) m.enabled.store(disabled.count(m.name) == 0, std::memory_order_relaxed);
  if (value != s.last_value) {
    s.last_value = value;
    REXLOG_INFO("rewrites: disabled modules: {}", value.empty() ? "(none)" : value);
  }
}
}  // namespace

RewriteModule* GetRewriteModule(const char* module) {
  State& s = S();
  std::lock_guard<std::mutex> lock(s.mutex);
  for (RewriteModule& m : s.modules)
    if (std::strcmp(m.name, module) == 0) return &m;
  RewriteModule& m = s.modules.emplace_back();
  m.name = module;
  return &m;
}

PPCFunc* GuestFunction(uint32_t guest_address) {
  // As the recompiled code's REX_CALL_INDIRECT_FUNC: the function table after the image, then the
  // runtime's lookup across modules.
  uint8_t* base = f2::g_base;
  PPCFunc* fn = nullptr;
  if (uint32_t(guest_address - REX_CODE_BASE) < REX_CODE_SIZE + REX_THUNK_RESERVE_SIZE)
    fn = REX_LOOKUP_FUNC(base, guest_address);
  if (!fn) fn = rex::runtime::ResolveIndirectFunction(guest_address);
  return fn;
}

bool RewriteEnabled(const char* module) { return RewriteEnabled(GetRewriteModule(module)); }

void RefreshRewrites() {
  State& s = S();
  std::lock_guard<std::mutex> lock(s.mutex);
  if (!s.callback_registered) {
    s.callback_registered = true;
    rex::cvar::RegisterChangeCallback("rewrites_disabled", [](std::string_view, std::string_view value) {
      State& s = S();
      std::lock_guard<std::mutex> lock(s.mutex);
      Apply(s, std::string(value));
    });
  }
  Apply(s, REXCVAR_GET(rewrites_disabled));
}

void RegisterRewrite(const char* module, const char* function, uint32_t guest_address) {
  (void)guest_address;
  State& s = S();
  std::lock_guard<std::mutex> lock(s.mutex);
  s.registered.emplace_back(module, function);
}

}  // namespace f2
