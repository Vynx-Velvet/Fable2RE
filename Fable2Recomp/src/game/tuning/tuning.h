// Fable II tuning values: the globals the game's Lua setters write (Debug.SetFlourishDamage,
// Combat.SetCloseAttackMaxRange, ...) - combat, magic, experience orbs, hero movement, physics limits,
// debug switches. Table: tuning_table.inc (tools/convert/gen_tuning.py). The setters themselves are
// replaced by readable C++ in tuning.cpp.
//
// Mods override values with <exe folder>/mods/<Mod>/tuning.toml:
//     [tuning]
//     FlourishDamage = 2.5
//     HeroSprintingEnabled = false
// An override is applied at startup and kept: the game's own scripts cannot change it afterwards.
#pragma once

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace f2::tuning {

enum class Type { kBool, kU8, kU32, kFloat };

struct Entry {
  const char* name;
  uint32_t address;  // guest address of the value
  Type type;
  uint32_t setter;   // guest address of the Lua setter function
  const char* lua;   // Lua binding that sets it
};

const std::vector<Entry>& Entries();
const Entry* Find(const std::string& name);

double Get(const Entry& e);
// Writes the value now (live). With `keep`, it also becomes an override the game cannot change.
void Set(const Entry& e, double value, bool keep);
void ClearOverride(const Entry& e);
bool IsOverridden(const Entry& e);

// Loads every mods/*/tuning.toml under `game_folder` (the folder of the executable; alphabetical; later mods win).
void LoadOverrides(const std::filesystem::path& game_folder);
// Writes the current overrides as a tuning.toml.
bool SaveOverrides(const std::filesystem::path& file);

}  // namespace f2::tuning
