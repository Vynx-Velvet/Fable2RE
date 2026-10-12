// Example native mod: replaces the C++ behind the Lua binding Debug.SetDrawGameFPS (guest function
// 0x823A5918, see research/symbols/lua_bindings.tsv) - logs every call and runs the original.
//
// Build: target Fable2ExampleMod (CMake). Install: copy HelloMod.dll to
// <exe folder>/mods/HelloMod/native/ (the folder of Fable2.exe). In game: F2 -> Debug.SetDrawGameFPS(true) -> fable2.log shows
// "[HelloMod] Debug.SetDrawGameFPS(1)".
#include <fable2/mod_api.h>
#include <fable2/sdk.h>

#include <cstdio>

namespace {
const Fable2ModApi* g_api = nullptr;
Fable2GuestFunction g_original = nullptr;

// Same signature as every recompiled function: arguments in ctx.r3.., result in ctx.r3.
void SetDrawGameFPS(PPCContext* ctx, uint8_t* base) {
  char text[96];
  std::snprintf(text, sizeof(text), "Debug.SetDrawGameFPS(%u)", ctx->r3.u32 & 0xFF);
  g_api->log(FABLE2_LOG_INFO, text);
  g_original(ctx, base);  // the game's own code (stores the flag)
}
}  // namespace

extern "C" __declspec(dllexport) int Fable2Mod_Load(const Fable2ModApi* api) {
  if (api->version < 1) return 1;
  g_api = api;
  f2::g_base = api->guest_base;
  if (api->hook_function(0x823A5918, SetDrawGameFPS, &g_original) != 0) return 2;
  api->log(FABLE2_LOG_INFO, "hello from a native mod");
  return 0;
}
