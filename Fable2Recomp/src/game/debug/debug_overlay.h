// Native re-implementation of Fable II's compiled-out debug displays (see debug_overlay.cpp).
#pragma once

#include <chrono>
#include <deque>

#include <rex/ui/imgui_dialog.h>

namespace f2::debug {

class DebugOverlay : public rex::ui::ImGuiDialog {
 public:
  explicit DebugOverlay(rex::ui::ImGuiDrawer* drawer);

 protected:
  void OnDraw(ImGuiIO& io) override;

 private:
  std::deque<std::chrono::steady_clock::time_point> frames_;
};

}  // namespace f2::debug
