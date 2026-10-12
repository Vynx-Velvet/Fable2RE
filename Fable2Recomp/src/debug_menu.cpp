/**
 * @file        src/debug_menu.cpp
 *
 * @brief       Native ImGui front end for Lionhead's shipped debug menu.
 *
 *              Reads the game's own menu definitions (data/scripts/Startup/
 *              DebugMenu.txt and DebugMenuLevelList.txt) and runs the selected
 *              entries as Lua through src/lua_bridge.cpp, plus a free-form Lua prompt.
 *
 *              File format: one entry per line, nesting by leading tabs,
 *              `"<lua>", "<label>"`; an empty <lua> starts a submenu. Placeholders
 *              in <lua>: `[toggle:true|false]` / `[toggle]` (alternating bool, the
 *              first use sends `true` only for [toggle:true]) and `[min:max:default:step:isFloat]` (slider;
 *              the label's `[slider]` shows the value).
 *
 * @copyright   Copyright (c) 2026 Fable2RE Contributors
 *              SPDX-License-Identifier: MIT
 */

#include "debug_menu.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#include <imgui.h>

#include <rex/logging.h>

#include "game/tuning/tuning.h"
#include "lua_bridge.h"

#include <rex/filesystem.h>

namespace {

// Pulls the next double-quoted field from `line` at `pos`; backslash escapes are
// kept verbatim because the text is Lua source.
bool NextQuoted(const std::string& line, size_t& pos, std::string& out) {
  size_t start = line.find('"', pos);
  if (start == std::string::npos) return false;
  out.clear();
  for (size_t i = start + 1; i < line.size(); ++i) {
    char c = line[i];
    if (c == '\\' && i + 1 < line.size()) {
      out += c;
      out += line[++i];
      continue;
    }
    if (c == '"') {
      pos = i + 1;
      return true;
    }
    out += c;
  }
  return false;
}

const std::regex kToggleRe(R"(\[toggle(?::(true|false))?\])");
const std::regex kSliderRe(R"(\[(-?[0-9.]+):(-?[0-9.]+):(-?[0-9.]+):(-?[0-9.]+):(true|false)\])");

}  // namespace

void DebugMenuDialog::Item::Init() {
  std::smatch m;
  if (std::regex_search(code, m, kToggleRe)) {
    has_toggle = true;
    // Lionhead's convention: [toggle:true] = off by default, first use sends true;
    // [toggle:false] and bare [toggle] = on by default (GUI, lightmaps, shadows),
    // first use sends false.
    toggle_next = m[1].matched && m[1].str() == "true";
  }
  if (std::regex_search(code, m, kSliderRe)) {
    has_slider = true;
    slider_min = std::stof(m[1].str());
    slider_max = std::stof(m[2].str());
    slider_value = std::stof(m[3].str());
    slider_step = std::stof(m[4].str());
    slider_float = m[5].str() == "true";
  }
}

std::string DebugMenuDialog::Item::Expand() const {
  std::string out = code;
  if (has_toggle) out = std::regex_replace(out, kToggleRe, toggle_next ? "true" : "false");
  if (has_slider) {
    char buf[32];
    if (slider_float) std::snprintf(buf, sizeof(buf), "%g", slider_value);
    else std::snprintf(buf, sizeof(buf), "%d", static_cast<int>(slider_value));
    out = std::regex_replace(out, kSliderRe, buf);
  }
  return out;
}

std::vector<DebugMenuDialog::Item> DebugMenuDialog::LoadMenuFile(const std::filesystem::path& path) {
  std::vector<Item> roots;
  std::ifstream in(path);
  if (!in) {
    REXLOG_WARN("debug_menu: cannot open {}", path.string());
    return roots;
  }
  // stack[d] = children vector receiving entries at depth d
  std::vector<std::vector<Item>*> stack{&roots};
  std::string line;
  while (std::getline(in, line)) {
    if (!line.empty() && line.back() == '\r') line.pop_back();
    size_t depth = 0;
    while (depth < line.size() && line[depth] == '\t') ++depth;
    size_t pos = depth;
    Item item;
    if (!NextQuoted(line, pos, item.code) || !NextQuoted(line, pos, item.label)) continue;
    item.Init();
    depth = std::min(depth, stack.size() - 1);
    stack.resize(depth + 1);
    auto* parent = stack.back();
    parent->push_back(std::move(item));
    if (parent->back().code.empty()) stack.push_back(&parent->back().children);
  }
  return roots;
}

DebugMenuDialog::DebugMenuDialog(rex::ui::ImGuiDrawer* imgui_drawer, std::filesystem::path startup_dir)
    : ImGuiDialog(imgui_drawer), startup_dir_(std::move(startup_dir)) {
  menu_ = LoadMenuFile(startup_dir_ / "DebugMenu.txt");
  levels_ = LoadMenuFile(startup_dir_ / "DebugMenuLevelList.txt");
  REXLOG_INFO("debug_menu: {} top-level menu entries, {} level entries from {}", menu_.size(),
              levels_.size(), startup_dir_.string());
}

void DebugMenuDialog::Run(const std::string& code) {
  log_.push_back("> " + code);
  LuaBridge_Queue(code);
}

void DebugMenuDialog::DrawItems(std::vector<Item>& items) {
  for (auto& item : items) {
    ImGui::PushID(&item);
    if (item.code.empty()) {
      if (ImGui::TreeNode(item.label.c_str())) {
        DrawItems(item.children);
        ImGui::TreePop();
      }
    } else if (item.has_slider) {
      ImGui::SetNextItemWidth(160);
      if (item.slider_float) {
        ImGui::SliderFloat("##v", &item.slider_value, item.slider_min, item.slider_max, "%.2f");
      } else {
        int v = static_cast<int>(item.slider_value);
        if (ImGui::SliderInt("##v", &v, static_cast<int>(item.slider_min), static_cast<int>(item.slider_max)))
          item.slider_value = static_cast<float>(v);
      }
      ImGui::SameLine();
      if (ImGui::Button(item.label.c_str())) Run(item.Expand());
    } else if (item.has_toggle) {
      bool on = !item.toggle_next;  // state after the last click
      if (ImGui::Checkbox(item.label.c_str(), &on)) {
        Run(item.Expand());
        item.toggle_next = !item.toggle_next;
      }
    } else if (ImGui::Selectable(item.label.c_str())) {
      Run(item.Expand());
    }
    if (!item.code.empty() && ImGui::IsItemHovered()) ImGui::SetTooltip("%s", item.code.c_str());
    ImGui::PopID();
  }
}

// Live tuning values (src/game/tuning): edit while playing; "pin" keeps a value against the game's
// own scripts; Save writes the pinned values as a mod (mods/LiveTuning/tuning.toml).
void DebugMenuDialog::DrawTuning() {
  namespace tu = f2::tuning;
  ImGui::SetNextItemWidth(220);
  ImGui::InputTextWithHint("##tfilter", "filter (e.g. Strafe, Orb, Spell)", tuning_filter_, sizeof(tuning_filter_));
  ImGui::SameLine();
  if (ImGui::Button("Save pinned as mod")) {
    auto file = rex::filesystem::GetExecutableFolder() / "mods" / "LiveTuning" / "tuning.toml";
    bool ok = tu::SaveOverrides(file);
    log_.push_back(ok ? "tuning saved to " + file.string() : "tuning: could not write " + file.string());
  }
  ImGui::BeginChild("tuning", ImVec2(0, -ImGui::GetFrameHeightWithSpacing() * 7));
  std::string filter = tuning_filter_;
  for (auto& c : filter) c = char(std::tolower(static_cast<unsigned char>(c)));
  for (const auto& e : tu::Entries()) {
    std::string name = e.name;
    std::string lower = name;
    for (auto& c : lower) c = char(std::tolower(static_cast<unsigned char>(c)));
    if (!filter.empty() && lower.find(filter) == std::string::npos) continue;
    ImGui::PushID(&e);
    bool pinned = tu::IsOverridden(e);
    if (ImGui::Checkbox("##pin", &pinned)) {
      if (pinned) tu::Set(e, tu::Get(e), true);
      else tu::ClearOverride(e);
    }
    if (ImGui::IsItemHovered()) ImGui::SetTooltip("pin: keep this value even when the game's scripts set it");
    ImGui::SameLine();
    double v = tu::Get(e);
    ImGui::SetNextItemWidth(140);
    bool changed = false;
    switch (e.type) {
      case tu::Type::kBool: {
        bool b = v != 0;
        changed = ImGui::Checkbox(e.name, &b);
        v = b ? 1 : 0;
        break;
      }
      case tu::Type::kFloat: {
        float f = float(v);
        changed = ImGui::DragFloat(e.name, &f, std::max(0.001f, std::fabs(f) * 0.01f));
        v = f;
        break;
      }
      default: {
        int i = int(v);
        changed = ImGui::InputInt(e.name, &i);
        v = i;
        break;
      }
    }
    if (changed) tu::Set(e, v, pinned);
    if (ImGui::IsItemHovered()) ImGui::SetTooltip("%s  (0x%08X)", e.lua, e.address);
    ImGui::PopID();
  }
  ImGui::EndChild();
}

void DebugMenuDialog::OnDraw(ImGuiIO& io) {
  if (!visible_) return;
  LuaBridgeResult r;
  while (LuaBridge_PopResult(r)) log_.push_back(r.ok ? "  ok" : "  FAILED: " + r.message);
  if (log_.size() > 200) log_.erase(log_.begin(), log_.begin() + (log_.size() - 200));

  ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowSize(ImVec2(520, io.DisplaySize.y * 0.8f), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowBgAlpha(0.88f);
  if (focus_on_show_) {
    ImGui::SetNextWindowFocus();
    focus_on_show_ = false;
  }
  if (!ImGui::Begin("Fable II Debug Menu (F2)", nullptr, ImGuiWindowFlags_NoCollapse)) {
    ImGui::End();
    return;
  }
  if (LuaBridge_IsReady()) ImGui::TextColored(ImVec4(0.4f, 1, 0.4f, 1), "Lua: ready (runs between frames)");
  else ImGui::TextColored(ImVec4(1, 0.8f, 0.3f, 1), "Lua: no game Lua state found yet (load a save first)");

  if (ImGui::BeginTabBar("tabs")) {
    if (ImGui::BeginTabItem("Debug Menu")) {
      ImGui::BeginChild("menu", ImVec2(0, -ImGui::GetFrameHeightWithSpacing() * 7));
      DrawItems(menu_);
      ImGui::EndChild();
      ImGui::EndTabItem();
    }
    if (ImGui::BeginTabItem("Levels")) {
      ImGui::BeginChild("levels", ImVec2(0, -ImGui::GetFrameHeightWithSpacing() * 7));
      DrawItems(levels_);
      ImGui::EndChild();
      ImGui::EndTabItem();
    }
    if (ImGui::BeginTabItem("Tuning")) {
      DrawTuning();
      ImGui::EndTabItem();
    }
    ImGui::EndTabBar();
  }

  ImGui::Separator();
  ImGui::BeginChild("log", ImVec2(0, -ImGui::GetFrameHeightWithSpacing() * 1.2f), false,
                    ImGuiWindowFlags_HorizontalScrollbar);
  for (auto& l : log_) ImGui::TextUnformatted(l.c_str());
  if (log_.size() != last_log_size_) {
    ImGui::SetScrollHereY(1.0f);
    last_log_size_ = log_.size();
  }
  ImGui::EndChild();

  ImGui::SetNextItemWidth(-60);
  bool submit = ImGui::InputText("##lua", input_, sizeof(input_), ImGuiInputTextFlags_EnterReturnsTrue);
  ImGui::SameLine();
  submit |= ImGui::Button("Run");
  if (submit && input_[0]) {
    Run(input_);
    input_[0] = 0;
    ImGui::SetKeyboardFocusHere(-1);
  }
  ImGui::End();
}
