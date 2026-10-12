// Fable II debug displays that Lionhead compiled out of the retail game, re-implemented natively.
//
// The Lua bindings still exist and store their flags (see game/tuning: DrawGameFPS 0x8349695F,
// DrawSafeArea 0x83496968, DrawBuildVersion 0x83496969), but nothing in the retail executable reads
// them. This overlay reads the same flags and draws what the development build drew:
//   Debug.SetDrawGameFPS(true)      frame rate and frame time
//   Debug.SetDrawBuildVersion(true) build string
//   Debug.SetDrawSafeArea(true)     title-safe (80%) and action-safe (90%) frames
#include "game/debug/debug_overlay.h"

#include <fable2/sdk.h>

#include <imgui.h>

#include <chrono>
#include <deque>

namespace f2::debug {
namespace {
constexpr uint32_t kDrawGameFPS = 0x8349695F;
constexpr uint32_t kDrawSafeArea = 0x83496968;
constexpr uint32_t kDrawBuildVersion = 0x83496969;

bool Flag(uint32_t address) { return f2::g_base && *f2::At<uint8_t>(address) != 0; }
}  // namespace

DebugOverlay::DebugOverlay(rex::ui::ImGuiDrawer* drawer) : ImGuiDialog(drawer) {}

void DebugOverlay::OnDraw(ImGuiIO& io) {
  const bool fps = Flag(kDrawGameFPS), safe = Flag(kDrawSafeArea), build = Flag(kDrawBuildVersion);
  if (!fps && !safe && !build) return;
  ImDrawList* dl = ImGui::GetForegroundDrawList();
  const ImVec2 size = io.DisplaySize;
  if (safe) {
    for (float pct : {0.9f, 0.8f}) {
      float mx = size.x * (1 - pct) / 2, my = size.y * (1 - pct) / 2;
      dl->AddRect(ImVec2(mx, my), ImVec2(size.x - mx, size.y - my),
                  pct > 0.85f ? IM_COL32(255, 220, 0, 200) : IM_COL32(255, 60, 60, 200), 0, 0, 2.0f);
    }
  }
  float y = size.y * 0.05f + 4;
  const float x = size.x * 0.05f + 4;
  if (fps) {
    // Frame time from the presented frames (the overlay draws once per presented frame).
    auto now = std::chrono::steady_clock::now();
    frames_.push_back(now);
    while (frames_.size() > 2 && now - frames_.front() > std::chrono::seconds(1)) frames_.pop_front();
    double span = frames_.size() > 1 ? std::chrono::duration<double>(frames_.back() - frames_.front()).count() : 0;
    double rate = span > 0 ? (frames_.size() - 1) / span : 0;
    char text[64];
    std::snprintf(text, sizeof(text), "FPS %.1f  (%.1f ms)", rate, rate > 0 ? 1000.0 / rate : 0.0);
    dl->AddText(ImVec2(x + 1, y + 1), IM_COL32(0, 0, 0, 220), text);
    dl->AddText(ImVec2(x, y), rate >= 55 ? IM_COL32(120, 255, 120, 255)
                              : rate >= 28 ? IM_COL32(255, 220, 80, 255)
                                           : IM_COL32(255, 90, 90, 255), text);
    y += ImGui::GetTextLineHeightWithSpacing();
  }
  if (build) {
    const char* text = "Fable II (TU1) - Fable2RE PC build " __DATE__;
    dl->AddText(ImVec2(x + 1, y + 1), IM_COL32(0, 0, 0, 220), text);
    dl->AddText(ImVec2(x, y), IM_COL32(255, 255, 255, 255), text);
  }
}

}  // namespace f2::debug
