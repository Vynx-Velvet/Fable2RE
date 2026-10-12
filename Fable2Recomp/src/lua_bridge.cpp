/**
 * @file        src/lua_bridge.cpp
 *
 * @brief       Run Lua text inside the game's own Lua VM (game thread, between frames).
 *
 *              Fable II's gameplay layer is Lua 5.1 (LuaPlus). Lionhead's debug API
 *              (Debug.LoadLevel, Debug.SetHeroGodMode, Debug.SetUseFreeCamera, ...)
 *              and the debug menu definitions (data/scripts/Startup/DebugMenu.txt,
 *              DebugMenuLevelList.txt) still ship in retail. This bridge is the one
 *              primitive the native debug menu (src/debug_menu.cpp) needs.
 *
 *              Map (research/findings/2026-10-02-lua-debug-menu.md):
 *                sub_822EA928  GameThread entry -> sub_822F47F8 mode loop
 *                sub_82355460  in-game main loop; calls sub_8229A9D8(component+136, 0)
 *                              once per iteration from return address 0x82355590
 *                sub_824154F0  RunLuaFile(lua_State* L, String* path, String* errName) -> bool
 *                              (used by sub_823ADB60 to run console scripts): opens the
 *                              file, then calls
 *                sub_824155C8  RunLuaBuffer(L, const char* buf, int len, String* chunkName,
 *                              String* errName) -> 1 ok / 0 error: lua_load (sub_82A1EE10,
 *                              string reader sub_82A1FF68) + protected call (sub_8219A8E8)
 *                sub_8222CF18  String::Construct(String* out, const char* s, int len = -1)
 *                sub_82214F08  String::Destroy(String*)
 *                main lua_State = *(*(*(*(*(0x83496920)+12)+120)+4)+0) per sub_823ADB60
 *                              (static reading; logged for checking, not relied on)
 *                sub_82A1EC08  lua_setfield(L, idx, const char* k) - every C binding is
 *                              registered through it; used to find the state that owns
 *                              the Debug.* functions
 *                sub_82BC55B8  lua_settop(L, idx) - RunLuaBuffer's last call; the error
 *                              message is still at top-1 when it fails
 *                lua_State: +8 top, +12 base, +16 global_State; TValue = 8 bytes
 *                              (value, tt at +4; LUA_TSTRING 4, LUA_TTHREAD 8); TString
 *                              text at +16
 *
 * @copyright   Copyright (c) 2026 Fable2RE Contributors
 *              SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <chrono>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <tuple>
#include <vector>

#include <fmt/format.h>

#include "generated/Fable2_init.h"

#include <rex/cvar.h>
#include <rex/hook.h>
#include <rex/ppc.h>
#include <rex/logging.h>

#include "lua_bridge.h"

namespace {

constexpr uint32_t kGameRoot = 0x83496920;          // root object; Lua state chain starts here
constexpr uint32_t kDebugMenuDisable = 0x833194D0;  // byte: nonzero skips the debug menu update/input
constexpr uint32_t kGameFlagsBase = 0x83496924;     // bytes +2 (0x83496926) / +3 (0x83496927) read by the menu / mode loop
constexpr size_t kMaxChunk = 16 * 1024;

std::mutex g_mutex;
std::deque<std::string> g_pending;
std::chrono::steady_clock::time_point g_pending_since;  // when g_pending became non-empty
std::deque<LuaBridgeResult> g_results;
bool g_ready = false;

// Written and read on guest threads only.
std::atomic<uint32_t> g_debug_state{0};  // state the Debug.* bindings were registered on
std::thread::id g_debug_thread;          // guest thread that registered them (GameThread)
bool g_in_chunk = false;                 // GameThread only
uint32_t g_chunk_state = 0;
std::string g_last_error;

void PushResult(LuaBridgeResult r) {
  std::lock_guard<std::mutex> lock(g_mutex);
  if (g_results.size() >= 256) g_results.pop_front();
  g_results.push_back(std::move(r));
}

bool Plausible(uint32_t p) { return p >= 0x1000 && p < 0xF0000000u && (p & 3) == 0; }

std::string ChainString(uint8_t* base) {
  std::string out = fmt::format("{:08X}", REX_LOAD_U32(kGameRoot));
  uint32_t p = REX_LOAD_U32(kGameRoot);
  for (uint32_t off : {12u, 120u, 4u, 0u}) {
    if (!Plausible(p)) break;
    p = REX_LOAD_U32(p + off);
    out += fmt::format(" ->+{} {:08X}", off, p);
  }
  return out;
}

// No Lua call in progress on L: L->ci == L->base_ci (lua_State +20 / +40).
bool LuaIdle(uint8_t* base, uint32_t L) { return REX_LOAD_U32(L + 20) == REX_LOAD_U32(L + 40); }

std::string TopString(uint8_t* base, uint32_t L) {
  const uint32_t top = REX_LOAD_U32(L + 8);
  if (!Plausible(top)) return {};
  if (REX_LOAD_U32(top - 8 + 4) != 4) return {};
  const uint32_t ts = REX_LOAD_U32(top - 8);
  if (!Plausible(ts)) return {};
  const uint32_t len = std::min<uint32_t>(REX_LOAD_U32(ts + 12), 2000);
  return std::string(reinterpret_cast<const char*>(base + ts + 16), len);
}

// Runs one chunk with the guest stack as scratch space. Called with the
// context of a guest call boundary, so only the registers restored below matter.
bool RunChunk(PPCContext& ctx, uint8_t* base, uint32_t L, const std::string& code) {
  const PPCContext saved = ctx;

  static const char kName[] = "Fable2RE debug console";
  const uint32_t old_sp = ctx.r1.u32;
  const uint32_t text_size = static_cast<uint32_t>(code.size()) + 1;
  const uint32_t frame_size = (0x100 + text_size + sizeof(kName) + 15) & ~15u;
  const uint32_t sp = old_sp - frame_size;
  const uint32_t str_chunk = sp + 0x80;  // String handles (4 bytes each)
  const uint32_t str_name = sp + 0x84;
  const uint32_t name_text = sp + 0x90;
  const uint32_t code_text = name_text + sizeof(kName);

  std::memcpy(base + name_text, kName, sizeof(kName));
  std::memcpy(base + code_text, code.c_str(), text_size);
  REX_STORE_U32(sp, old_sp);  // back chain
  REX_STORE_U32(str_chunk, 0);
  REX_STORE_U32(str_name, 0);
  ctx.r1.u64 = sp;

  ctx.r3.u64 = str_chunk; ctx.r4.u64 = name_text; ctx.r5.s64 = -1;
  sub_8222CF18(ctx, base);
  ctx.r3.u64 = str_name; ctx.r4.u64 = name_text; ctx.r5.s64 = -1;
  sub_8222CF18(ctx, base);

  ctx.r3.u64 = L; ctx.r4.u64 = code_text; ctx.r5.u64 = text_size - 1;
  ctx.r6.u64 = str_chunk; ctx.r7.u64 = str_name;
  g_last_error.clear();
  g_chunk_state = L;
  g_in_chunk = true;
  sub_824155C8(ctx, base);
  g_in_chunk = false;
  const bool ok = ctx.r3.u32 != 0;

  ctx.r3.u64 = str_chunk;
  sub_82214F08(ctx, base);
  ctx.r3.u64 = str_name;
  sub_82214F08(ctx, base);

  ctx = saved;
  return ok;
}

}  // namespace

REXCVAR_DEFINE_BOOL(dev_debug_menu, false, "Debug",
                    "Re-enable Lionhead's in-engine debug menu: clears the 'debug menu disabled' "
                    "byte (0x833194D0, 1 in the shipped image) before the game thread initialises.");

void LuaBridge_Queue(std::string code) {
  if (code.empty()) return;
  if (code.size() > kMaxChunk) {
    PushResult({std::move(code), false, "chunk too large (16 KiB max)"});
    return;
  }
  std::lock_guard<std::mutex> lock(g_mutex);
  if (g_pending.empty()) g_pending_since = std::chrono::steady_clock::now();
  g_pending.push_back(std::move(code));
}

bool LuaBridge_IsReady() {
  std::lock_guard<std::mutex> lock(g_mutex);
  return g_ready;
}

bool LuaBridge_PopResult(LuaBridgeResult& out) {
  std::lock_guard<std::mutex> lock(g_mutex);
  if (g_results.empty()) return false;
  out = std::move(g_results.front());
  g_results.pop_front();
  return true;
}

// GameThread entry (sub_822EA928): runs before the engine init (sub_822F27C0)
// and before the debug menu object would be created (sub_82354BB8).
REX_HOOK_RAW(sub_822EA928) {
  if (REXCVAR_GET(dev_debug_menu)) {
    REX_STORE_U8(kDebugMenuDisable, 0);
    REXLOG_INFO("lua_bridge: dev_debug_menu on, cleared 0x{:08X}", kDebugMenuDisable);
  }
  __imp__sub_822EA928(ctx, base);
}

// sub_8229A9D8 is called once per iteration by the front-end loop (sub_82355460,
// return address 0x82355590), the in-game mode (sub_823784A0, 0x82378578) and
// sub_82276C30. Queued chunks run at whichever site comes first on the thread
// that registered Debug.*, and only while that Lua state is idle.
REX_HOOK_RAW(sub_8229A9D8) {
  const uint32_t L = g_debug_state.load();
  const uint32_t site = static_cast<uint32_t>(ctx.lr);
  {
    // Diagnostics: if chunks wait > 5 s, list which sites/threads reach this hook.
    static std::mutex stats_mutex;
    static std::vector<std::tuple<uint32_t, std::thread::id, uint64_t>> stats;
    static auto last_dump = std::chrono::steady_clock::now();
    std::lock_guard<std::mutex> lock(stats_mutex);
    bool found = false;
    for (auto& [s_site, s_tid, s_count] : stats)
      if (s_site == site && s_tid == std::this_thread::get_id()) { ++s_count; found = true; }
    if (!found && stats.size() < 32) stats.emplace_back(site, std::this_thread::get_id(), 1);
    const auto now = std::chrono::steady_clock::now();
    size_t pending;
    std::chrono::steady_clock::time_point since;
    { std::lock_guard<std::mutex> l2(g_mutex); pending = g_pending.size(); since = g_pending_since; }
    if (pending && now - since > std::chrono::seconds(5) && now - last_dump > std::chrono::seconds(5)) {
      last_dump = now;
      std::string list;
      for (auto& [s_site, s_tid, s_count] : stats)
        list += fmt::format(" [0x{:08X} {}thread x{}]", s_site, s_tid == g_debug_thread ? "Debug " : "other ", s_count);
      REXLOG_WARN("lua_bridge: {} chunk(s) still queued; L=0x{:08X} idle={}; sites:{}", pending, L,
                  L ? LuaIdle(base, L) : false, list);
    }
  }
  if (L && std::this_thread::get_id() == g_debug_thread) {
    static uint32_t logged_sites[4];
    static int nlogged = 0;
    bool known = false;
    for (int i = 0; i < nlogged; ++i) known |= logged_sites[i] == site;
    if (!known && nlogged < 4) {
      logged_sites[nlogged++] = site;
      REXLOG_INFO("lua_bridge: per-frame site 0x{:08X} active on the Debug.* thread, L=0x{:08X} idle={} "
                  "debug_menu_disable={} chain {}",
                  site, L, LuaIdle(base, L), REX_LOAD_U8(kDebugMenuDisable), ChainString(base));
    }
    std::deque<std::string> batch;
    {
      std::lock_guard<std::mutex> lock(g_mutex);
      g_ready = true;
      if (LuaIdle(base, L)) batch.swap(g_pending);
    }
    for (auto& code : batch) {
      const bool ok = RunChunk(ctx, base, L, code);
      std::string msg = ok ? "ok" : (g_last_error.empty() ? "error (no message)" : g_last_error);
      REXLOG_INFO("lua_bridge: [site 0x{:08X}] {} -> {}", site, code, msg);
      PushResult({std::move(code), ok, std::move(msg)});
    }
  }
  __imp__sub_8229A9D8(ctx, base);
}

// lua_setfield(L, idx, k): note every state the game registers bindings on and
// the one that receives the Debug.* functions.
REX_HOOK_RAW(sub_82A1EC08) {
  const uint32_t L = ctx.r3.u32;
  static uint32_t seen[8];
  static int nseen = 0;
  bool known = false;
  for (int i = 0; i < nseen; ++i) known |= seen[i] == L;
  if (!known && nseen < 8) {
    seen[nseen++] = L;
    REXLOG_INFO("lua_bridge: lua_setfield on new state L=0x{:08X} first key '{}'", L,
                reinterpret_cast<const char*>(base + ctx.r5.u32));
  }
  const char* key = reinterpret_cast<const char*>(base + ctx.r5.u32);
  if (std::strcmp(key, "SetHeroGodMode") == 0 && g_debug_state.load() != L) {
    g_debug_thread = std::this_thread::get_id();
    g_debug_state = L;
    REXLOG_INFO("lua_bridge: Debug.* bindings registered on L=0x{:08X}; commands will run there", L);
  }
  __imp__sub_82A1EC08(ctx, base);
}

// lua_settop: inside our chunk the last call is RunLuaBuffer's error cleanup,
// with the error message still at top-1.
REX_HOOK_RAW(sub_82BC55B8) {
  if (g_in_chunk && ctx.r3.u32 == g_chunk_state) {
    std::string e = TopString(base, ctx.r3.u32);
    if (!e.empty()) g_last_error = std::move(e);
  }
  __imp__sub_82BC55B8(ctx, base);
}
