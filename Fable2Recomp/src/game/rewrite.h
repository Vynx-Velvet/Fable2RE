// Registering hand-written replacements of game functions, switchable per module at run time.
//
//   F2_REWRITE("combat.health", sub_8268BD90, Modify);   // Modify: plain C++ types (see REX_HOOK)
//
// replaces the recompiled sub_8268BD90 with Modify unless the module is listed in the cvar
//   rewrites_disabled = "combat.health,tuning"
// (Fable2.toml or the console), in which case the original recompiled code (__imp__sub_...) runs.
// Use it to check a rewrite against the original in game and to bisect regressions.
#pragma once

#include <rex/hook.h>
#include <rex/ppc.h>
#include <rex/ppc/function.h>

#include <fable2/sdk.h>

#include <atomic>
#include <tuple>
#include <type_traits>

namespace f2 {
// A module of rewrites ("combat.health"): enabled unless listed in the rewrites_disabled cvar. The
// flag is updated when the cvar changes, so the check in every rewritten call is one relaxed load.
struct RewriteModule {
  const char* name;
  std::atomic<bool> enabled{true};
};
RewriteModule* GetRewriteModule(const char* module);  // stable pointer, created on first use
inline bool RewriteEnabled(const RewriteModule* m) { return m->enabled.load(std::memory_order_relaxed); }
bool RewriteEnabled(const char* module);
// Re-reads rewrites_disabled (called once the configuration is loaded; cvar changes call it too).
void RefreshRewrites();
// Registers a function for the status listing (F2 menu / log).
void RegisterRewrite(const char* module, const char* function, uint32_t guest_address);

// The register context of the game code running on this thread right now (set by the F2_REWRITE
// wrappers and by f2::Call), so calls back into the game put their stack frame below the live stack.
// (rex::ppc::GuestToHostFunction uses the thread's outermost context instead, which overlaps live
// frames as soon as game code called from a rewrite calls another rewrite that calls the game.)
inline thread_local PPCContext* t_current_ctx = nullptr;
struct CurrentContext {
  PPCContext* previous;
  explicit CurrentContext(PPCContext& ctx) : previous(t_current_ctx) { t_current_ctx = &ctx; }
  ~CurrentContext() { t_current_ctx = previous; }
};

// Calls a recompiled game function from hand-written code: f2::Call<uint32_t>(sub_8222C210, arg, ...).
// Arguments go to r3.. (integers, guest addresses) and f1.. (float/double) like the game's own calls.
template <class Ret, class... Args>
Ret Call(PPCFunc* fn, Args... args) {
  PPCContext* current = t_current_ctx;
  PPCContext call{};
  call.r1 = current->r1;
  call.r1.u32 -= 0x70;  // linkage area + parameter save of the caller's frame
  call.r13 = current->r13;
  call.fpscr = current->fpscr;
  auto tuple = std::make_tuple(args...);
  rex::ppc::_translate_args_to_guest(call, f2::g_base, tuple);
  {
    CurrentContext scope(call);
    fn(call, f2::g_base);
  }
  current->fpscr = call.fpscr;
  if constexpr (std::is_void_v<Ret>) {
    return;
  } else if constexpr (std::is_floating_point_v<Ret>) {
    return static_cast<Ret>(call.f1.f64);
  } else {
    return static_cast<Ret>(call.r3.u64);
  }
}
// The recompiled function at a guest address (virtual calls: f2::CallAt(vtable[n], ...)).
PPCFunc* GuestFunction(uint32_t guest_address);
template <class Ret, class... Args>
Ret CallAt(uint32_t guest_address, Args... args) {
  return Call<Ret>(GuestFunction(guest_address), args...);
}

// Space on the game thread's stack for out-parameters of calls into game code:
//   f2::GuestStackBuffer out(16);  f2::CallAt<void>(fn, out.address(), obj);  out.As<Vec4>()
// Calls made while it lives put their frames below it.
class GuestStackBuffer {
 public:
  explicit GuestStackBuffer(uint32_t size) : ctx_(t_current_ctx), saved_r1_(ctx_->r1.u32) {
    address_ = (saved_r1_ - 0x70 - size) & ~15u;
    ctx_->r1.u32 = address_;
  }
  ~GuestStackBuffer() { ctx_->r1.u32 = saved_r1_; }
  GuestStackBuffer(const GuestStackBuffer&) = delete;
  GuestStackBuffer& operator=(const GuestStackBuffer&) = delete;
  uint32_t address() const { return address_; }
  template <class T>
  T* As() const { return At<T>(address_); }

 private:
  PPCContext* ctx_;
  uint32_t saved_r1_;
  uint32_t address_;
};
}  // namespace f2

#define F2_REWRITE_IMPL(module, sub, fn, addr)                                                   \
  extern "C" void __imp__##sub(PPCContext& ctx, uint8_t* base);                                \
  static f2::RewriteModule* const f2_rewrite_module_##sub = f2::GetRewriteModule(module);     \
  extern "C" REX_FUNC(sub) {                                                                   \
    f2::CurrentContext f2_scope(ctx);                                                          \
    if (f2::RewriteEnabled(f2_rewrite_module_##sub))                                           \
      rex::ppc::HostToGuestFunction<fn>(ctx, base);                                            \
    else __imp__##sub(ctx, base);                                                              \
  }                                                                                            \
  static const bool f2_rewrite_registered_##sub = (f2::RegisterRewrite(module, #fn, addr), true);

// F2_REWRITE(module, sub_XXXXXXXX, function)
#define F2_REWRITE(module, sub, fn) F2_REWRITE_IMPL(module, sub, fn, f2_rewrite_address(#sub))

// (Guest address from "sub_XXXXXXXX".)
constexpr uint32_t f2_rewrite_address(const char* name) {
  uint32_t v = 0;
  for (const char* p = name + 4; *p; ++p) v = v * 16 + uint32_t(*p <= '9' ? *p - '0' : (*p | 0x20) - 'a' + 10);
  return v;
}
