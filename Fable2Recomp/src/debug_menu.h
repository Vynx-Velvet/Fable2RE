// Native ImGui front end for the game's shipped debug menu. See src/debug_menu.cpp.
#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <rex/ui/imgui_dialog.h>

class DebugMenuDialog : public rex::ui::ImGuiDialog {
 public:
  // startup_dir: <game>/data/scripts/Startup (holds DebugMenu.txt, DebugMenuLevelList.txt)
  DebugMenuDialog(rex::ui::ImGuiDrawer* imgui_drawer, std::filesystem::path startup_dir);

  // The dialog lives for the whole session so toggle/slider states survive F2.
  bool visible() const { return visible_; }
  void set_visible(bool v) {
    focus_on_show_ = v && !visible_;
    visible_ = v;
  }

 protected:
  void OnDraw(ImGuiIO& io) override;

 private:
  struct Item {
    std::string code, label;
    std::vector<Item> children;
    bool has_toggle = false, toggle_next = true;
    bool has_slider = false, slider_float = false;
    float slider_min = 0, slider_max = 1, slider_value = 0, slider_step = 1;
    void Init();
    std::string Expand() const;
  };

  static std::vector<Item> LoadMenuFile(const std::filesystem::path& path);
  void DrawItems(std::vector<Item>& items);
  void Run(const std::string& code);
  void DrawTuning();

  std::filesystem::path startup_dir_;
  std::vector<Item> menu_, levels_;
  std::vector<std::string> log_;
  size_t last_log_size_ = 0;
  bool visible_ = true, focus_on_show_ = true;
  char input_[1024] = {};
  char tuning_filter_[64] = {};
};
