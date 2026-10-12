/**
 * @file        src/modding/mod_loader.cpp
 *
 * @brief       Native mods: loads plugin DLLs from <exe>/mods/<ModName>/native/*.dll and lets them
 *              replace any recompiled game function at run time (MinHook detours on the host
 *              functions listed in PPCFuncMappings), see sdk/include/fable2/mod_api.h.
 *
 * @copyright   Copyright (c) 2026 Fable2RE Contributors
 *              SPDX-License-Identifier: MIT
 */

#include "modding/mod_loader.h"

#include <fable2/mod_api.h>
#include <fable2/sdk.h>

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/ppc/context.h>

#include <MinHook.h>

#include <windows.h>

#include <algorithm>
#include <filesystem>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include "game/rewrite.h"
namespace f2 { void RefreshLiftedSwitch(); }
#include "game/tuning/tuning.h"
#include "lua_bridge.h"

REXCVAR_DEFINE_BOOL(mods_native, true, "Mods",
                    "Load native mod DLLs from <exe folder>/mods/<ModName>/native/ at startup");

namespace {

struct LoadedMod {
  std::string name, directory;
  HMODULE module = nullptr;
  Fable2ModApi api{};
};

std::mutex g_mutex;
bool g_minhook_ready = false;
// Guest address -> host function as it is now (after replacements).
std::unordered_map<uint32_t, PPCFunc*> g_functions;
// Guest address -> the host function originally compiled for it (the MinHook target).
std::unordered_map<uint32_t, PPCFunc*> g_targets;
std::vector<std::unique_ptr<LoadedMod>> g_mods;
thread_local const LoadedMod* t_current_mod = nullptr;

void BuildFunctionTable() {
  if (!g_functions.empty()) return;
  for (const PPCFuncMapping* m = PPCFuncMappings; m->guest; ++m) {
    g_functions.emplace(uint32_t(m->guest), m->host);
    g_targets.emplace(uint32_t(m->guest), m->host);
  }
}

Fable2GuestFunction ApiFindFunction(uint32_t guest_address) {
  std::lock_guard<std::mutex> lock(g_mutex);
  auto it = g_functions.find(guest_address);
  return it == g_functions.end() ? nullptr : reinterpret_cast<Fable2GuestFunction>(it->second);
}

int ApiHookFunction(uint32_t guest_address, Fable2GuestFunction replacement, Fable2GuestFunction* original) {
  if (!replacement) return 1;
  std::lock_guard<std::mutex> lock(g_mutex);
  auto t = g_targets.find(guest_address);
  if (t == g_targets.end()) {
    REXLOG_WARN("mods: {} tried to hook unknown function {:08X}", t_current_mod ? t_current_mod->name : "?",
                guest_address);
    return 2;
  }
  // Chained replacements: MinHook detours the original target once; later mods detour the earlier
  // replacement's trampoline target instead, i.e. hook what currently runs.
  PPCFunc* current = g_functions[guest_address];
  void* trampoline = nullptr;
  void* target = reinterpret_cast<void*>(current == t->second ? t->second : current);
  MH_STATUS st = MH_CreateHook(target, reinterpret_cast<void*>(replacement), &trampoline);
  if (st == MH_OK) st = MH_EnableHook(target);
  if (st != MH_OK) {
    REXLOG_ERROR("mods: hooking {:08X} for {} failed: {}", guest_address, t_current_mod ? t_current_mod->name : "?",
                 MH_StatusToString(st));
    return 3;
  }
  if (original) *original = reinterpret_cast<Fable2GuestFunction>(trampoline);
  g_functions[guest_address] = reinterpret_cast<PPCFunc*>(replacement);
  REXLOG_INFO("mods: {} replaced function {:08X}", t_current_mod ? t_current_mod->name : "?", guest_address);
  return 0;
}

void ApiLog(int level, const char* text) {
  const std::string& mod = t_current_mod ? t_current_mod->name : std::string("mod");
  switch (level) {
    case FABLE2_LOG_DEBUG: REXLOG_DEBUG("[{}] {}", mod, text ? text : ""); break;
    case FABLE2_LOG_WARN: REXLOG_WARN("[{}] {}", mod, text ? text : ""); break;
    case FABLE2_LOG_ERROR: REXLOG_ERROR("[{}] {}", mod, text ? text : ""); break;
    default: REXLOG_INFO("[{}] {}", mod, text ? text : ""); break;
  }
}

void ApiQueueLua(const char* code) {
  if (code) LuaBridge_Queue(code);
}

}  // namespace

bool ModLoader_HookFunction(uint32_t guest_address, PPCFunc* replacement, PPCFunc** original) {
  if (!g_minhook_ready) return false;
  return ApiHookFunction(guest_address, reinterpret_cast<Fable2GuestFunction>(replacement),
                         reinterpret_cast<Fable2GuestFunction*>(original)) == 0;
}

void ModLoader_Initialize(const std::filesystem::path& game_folder, uint8_t* guest_base) {
  f2::g_base = guest_base;
  BuildFunctionTable();
  if (MH_Initialize() == MH_OK) g_minhook_ready = true;
  f2::RefreshRewrites();                   // rewrites_disabled from the loaded configuration
  f2::RefreshLiftedSwitch();               // lifted_code
  f2::tuning::LoadOverrides(game_folder);  // mods/*/tuning.toml
  if (!REXCVAR_GET(mods_native)) return;
  std::error_code ec;
  auto mods_dir = game_folder / "mods";
  if (!std::filesystem::is_directory(mods_dir, ec)) return;
  std::vector<std::filesystem::path> mod_dirs;
  for (auto& e : std::filesystem::directory_iterator(mods_dir, ec))
    if (e.is_directory() && e.path().filename().string().rfind('_', 0) != 0) mod_dirs.push_back(e.path());
  std::sort(mod_dirs.begin(), mod_dirs.end());
  for (auto& dir : mod_dirs) {
    auto native = dir / "native";
    if (!std::filesystem::is_directory(native, ec)) continue;
    std::vector<std::filesystem::path> dlls;
    for (auto& f : std::filesystem::directory_iterator(native, ec))
      if (f.path().extension() == ".dll") dlls.push_back(f.path());
    std::sort(dlls.begin(), dlls.end());
    for (auto& dll : dlls) {
      auto mod = std::make_unique<LoadedMod>();
      mod->name = dir.filename().string();
      mod->directory = dir.string();
      mod->module = LoadLibraryW(dll.wstring().c_str());
      if (!mod->module) {
        REXLOG_ERROR("mods: cannot load {} (error {})", dll.string(), GetLastError());
        continue;
      }
      auto load = reinterpret_cast<Fable2ModLoadFn>(GetProcAddress(mod->module, "Fable2Mod_Load"));
      if (!load) {
        REXLOG_ERROR("mods: {} has no Fable2Mod_Load export", dll.string());
        FreeLibrary(mod->module);
        continue;
      }
      Fable2ModApi& api = mod->api;
      api.version = FABLE2_MOD_API_VERSION;
      api.size = sizeof(Fable2ModApi);
      api.guest_base = guest_base;
      api.find_function = ApiFindFunction;
      api.hook_function = ApiHookFunction;
      api.log = ApiLog;
      api.queue_lua = ApiQueueLua;
      api.mod_directory = mod->directory.c_str();
      api.mod_name = mod->name.c_str();
      t_current_mod = mod.get();
      int rc = load(&api);
      t_current_mod = nullptr;
      if (rc != 0) {
        REXLOG_ERROR("mods: {} ({}) failed to load: {}", mod->name, dll.filename().string(), rc);
        continue;
      }
      REXLOG_INFO("mods: loaded {} ({})", mod->name, dll.filename().string());
      g_mods.push_back(std::move(mod));
    }
  }
}
