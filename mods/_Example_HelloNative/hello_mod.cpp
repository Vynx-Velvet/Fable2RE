// Example native mod: replaces the C++ behind the Lua binding Debug.SetDrawGameFPS (guest function
// 0x823A5918, see research/symbols/lua_bindings.tsv) - logs every call and runs the original.
//
// Build: target Fable2ExampleMod (CMake). It compiles Fable2Recomp/sdk/examples/hello_mod/hello_mod.cpp
// (the same code as this file) and writes HelloMod.dll into the build folder (beside Fable2.exe), not
// into this folder. Install: copy <build folder>/HelloMod.dll into this folder's native/ (create it;
// DLLs are not tracked by Git), rename this folder to Example_HelloNative and run
// `python tools/mods.py apply`, which copies native/HelloMod.dll to <exe folder>/mods/Example_HelloNative/native/
// (Fable2.exe loads mods/<Mod>/native/*.dll beside itself, not from the game folder). Without the DLL
// in native/, list/check/apply warn that the mod has nothing to install.
// fable2.log at startup: "[Example_HelloNative] hello from a native mod" (during Fable2Mod_Load the log
// tag is the mod's folder name). In game: F2 -> Debug.SetDrawGameFPS(true) -> fable2.log shows
// "[mod] Debug.SetDrawGameFPS(1)": calls made later, from a hook, are logged with the generic tag "mod"
// (src/modding/mod_loader.cpp sets the current mod only while Fable2Mod_Load runs).
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
