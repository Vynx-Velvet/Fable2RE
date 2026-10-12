// Native mod loader (plugin DLLs) and run-time function replacement. See src/modding/mod_loader.cpp.
#pragma once

#include <cstdint>
#include <filesystem>

#include <rex/ppc/context.h>

// Sets f2::g_base, prepares run-time hooking and loads <game_folder>/mods/*/native/*.dll.
// Call once, before the game's main thread starts.
void ModLoader_Initialize(const std::filesystem::path& game_folder, uint8_t* guest_base);

// Run-time replacement of a game function for built-in code (plugins use Fable2ModApi).
bool ModLoader_HookFunction(uint32_t guest_address, PPCFunc* replacement, PPCFunc** original);
