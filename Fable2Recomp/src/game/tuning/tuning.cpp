// Fable II tuning values - readable C++ replacing the game's tuning setters (see tuning.h).
//
// Every setter in tuning_table.inc was, in the original game, exactly
//     lis rA,HI ; st{b,w,fs} r3/f1,LO(rA) ; blr
// i.e. "store the argument into one global". Here each becomes a named C++ function storing into a
// named value - unless a mod pinned that value, in which case the mod's value is kept.
#include "game/tuning/tuning.h"

#include <fable2/sdk.h>

#include "generated/Fable2_init.h"
#include "game/rewrite.h"

#include <rex/hook.h>
#include <rex/logging.h>
#include <rex/ppc.h>

#include <toml++/toml.hpp>

#include <algorithm>
#include <atomic>
#include <cmath>
#include <fstream>
#include <mutex>
#include <unordered_map>

namespace f2::tuning {
namespace {

// Storage type in game memory for each table type (bools are bytes).
template <class T>
struct Storage {
  using type = T;
};
template <>
struct Storage<bool> {
  using type = uint8_t;
};

template <class T>
constexpr Type TypeOf() {
  if constexpr (std::is_same_v<T, bool>) return Type::kBool;
  else if constexpr (std::is_same_v<T, uint8_t>) return Type::kU8;
  else if constexpr (std::is_same_v<T, uint32_t>) return Type::kU32;
  else return Type::kFloat;
}

// Pinned values (by guest address): written by mods, re-applied on every game write.
std::mutex g_mutex;
std::unordered_map<uint32_t, double> g_overrides;

bool Override(uint32_t address, double* value) {
  std::lock_guard<std::mutex> lock(g_mutex);
  auto it = g_overrides.find(address);
  if (it == g_overrides.end()) return false;
  *value = it->second;
  return true;
}

template <class S>
void Store(uint32_t address, S value) {
  if constexpr (sizeof(S) == 1) {
    *f2::At<uint8_t>(address) = value;
  } else {
    *f2::At<rex::be<S>>(address) = value;
  }
}

template <class S>
S Load(uint32_t address) {
  if constexpr (sizeof(S) == 1) {
    return *f2::At<uint8_t>(address);
  } else {
    return *f2::At<rex::be<S>>(address);
  }
}

}  // namespace

// ---- The setters, rewritten: one named function per tuning value -------------------------------
#define X(Name, address, T, setter, lua)                                          \
  static void Set##Name(Storage<T>::type value) {                                  \
    double pinned;                                                                 \
    if (Override(address, &pinned)) value = static_cast<Storage<T>::type>(pinned); \
    Store<Storage<T>::type>(address, value);                                       \
  }                                                                                \
  F2_REWRITE("tuning", sub_##setter, Set##Name)
#include "game/tuning/tuning_table.inc"
#undef X

const std::vector<Entry>& Entries() {
  static const std::vector<Entry> entries = {
#define X(Name, address, T, setter, lua) {#Name, address, TypeOf<T>(), 0x##setter, lua},
#include "game/tuning/tuning_table.inc"
#undef X
  };
  return entries;
}

const Entry* Find(const std::string& name) {
  for (const auto& e : Entries())
    if (name == e.name) return &e;
  return nullptr;
}

double Get(const Entry& e) {
  switch (e.type) {
    case Type::kBool:
    case Type::kU8: return Load<uint8_t>(e.address);
    case Type::kU32: return Load<uint32_t>(e.address);
    case Type::kFloat: return Load<float>(e.address);
  }
  return 0;
}

void Set(const Entry& e, double value, bool keep) {
  if (keep) {
    std::lock_guard<std::mutex> lock(g_mutex);
    g_overrides[e.address] = value;
  }
  switch (e.type) {
    case Type::kBool: Store<uint8_t>(e.address, value != 0 ? 1 : 0); break;
    case Type::kU8: Store<uint8_t>(e.address, static_cast<uint8_t>(value)); break;
    case Type::kU32: Store<uint32_t>(e.address, static_cast<uint32_t>(value)); break;
    case Type::kFloat: Store<float>(e.address, static_cast<float>(value)); break;
  }
}

void ClearOverride(const Entry& e) {
  std::lock_guard<std::mutex> lock(g_mutex);
  g_overrides.erase(e.address);
}

bool IsOverridden(const Entry& e) {
  std::lock_guard<std::mutex> lock(g_mutex);
  return g_overrides.count(e.address) != 0;
}

void LoadOverrides(const std::filesystem::path& game_folder) {
  std::error_code ec;
  auto mods = game_folder / "mods";
  if (!std::filesystem::is_directory(mods, ec)) return;
  std::vector<std::filesystem::path> files;
  for (auto& d : std::filesystem::directory_iterator(mods, ec)) {
    auto f = d.path() / "tuning.toml";
    if (d.is_directory() && d.path().filename().string().rfind('_', 0) != 0 && std::filesystem::exists(f, ec))
      files.push_back(f);
  }
  std::sort(files.begin(), files.end());
  for (auto& f : files) {
    try {
      auto tbl = toml::parse_file(f.string());
      auto* section = tbl["tuning"].as_table();
      if (!section) continue;
      int n = 0;
      for (auto& [key, node] : *section) {
        const Entry* e = Find(std::string(key.str()));
        if (!e) {
          REXLOG_WARN("tuning: {}: unknown value '{}'", f.string(), std::string(key.str()));
          continue;
        }
        double v;
        if (auto b = node.value<bool>()) v = *b ? 1 : 0;
        else if (auto d = node.value<double>()) v = *d;
        else continue;
        Set(*e, v, true);
        ++n;
      }
      REXLOG_INFO("tuning: {} values from {}", n, f.string());
    } catch (const toml::parse_error& err) {
      REXLOG_ERROR("tuning: {}: {}", f.string(), std::string(err.description()));
    }
  }
}

bool SaveOverrides(const std::filesystem::path& file) {
  std::error_code ec;
  std::filesystem::create_directories(file.parent_path(), ec);
  std::ofstream out(file);
  if (!out) return false;
  out << "# Fable II tuning overrides (written by the F2 menu's Tuning tab).\n[tuning]\n";
  std::lock_guard<std::mutex> lock(g_mutex);
  for (const auto& e : Entries()) {
    auto it = g_overrides.find(e.address);
    if (it == g_overrides.end()) continue;
    if (e.type == Type::kBool) out << e.name << " = " << (it->second != 0 ? "true" : "false") << "\n";
    else out << e.name << " = " << it->second << "\n";
  }
  return true;
}

}  // namespace f2::tuning
