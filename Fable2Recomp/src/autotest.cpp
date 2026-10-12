// Automated test runs: see autotest.h.
#include "autotest.h"

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include <rex/cvar.h>
#include <rex/input/input.h>
#include <rex/input/input_driver.h>
#include <rex/input/input_system.h>
#include <rex/logging.h>

void NativeFrontend_RequestSnapshot();

namespace {
using namespace rex;
using namespace rex::input;

bool g_active = false;
std::string g_script;
std::atomic<uint16_t> g_buttons{0};
std::atomic<uint32_t> g_packet{1};
std::atomic<int16_t> g_lx{0}, g_ly{0}, g_rx{0}, g_ry{0};  // sticks (held until the script changes them)
std::atomic<uint8_t> g_lt{0}, g_rt{0};                    // triggers

// A controller for user 0 whose buttons the script sets.
class ScriptedPad final : public InputDriver {
 public:
  ScriptedPad() : InputDriver(nullptr, 0) {}
  X_STATUS Setup() override { return X_STATUS_SUCCESS; }
  X_RESULT GetCapabilities(uint32_t user_index, uint32_t, X_INPUT_CAPABILITIES* out_caps) override {
    if (user_index != 0) return X_ERROR_DEVICE_NOT_CONNECTED;
    if (out_caps) {
      std::memset(out_caps, 0, sizeof(*out_caps));
      out_caps->type = 0x01;
      out_caps->sub_type = 0x01;
      out_caps->gamepad.buttons = 0xFFFF;
      out_caps->gamepad.left_trigger = 0xFF;
      out_caps->gamepad.right_trigger = 0xFF;
      out_caps->gamepad.thumb_lx = int16_t(0x7FFF);
      out_caps->gamepad.thumb_ly = int16_t(0x7FFF);
      out_caps->gamepad.thumb_rx = int16_t(0x7FFF);
      out_caps->gamepad.thumb_ry = int16_t(0x7FFF);
    }
    return X_ERROR_SUCCESS;
  }
  X_RESULT GetState(uint32_t user_index, X_INPUT_STATE* out_state) override {
    if (user_index != 0) return X_ERROR_DEVICE_NOT_CONNECTED;
    if (out_state) {
      std::memset(out_state, 0, sizeof(*out_state));
      out_state->packet_number = g_packet.load();
      out_state->gamepad.buttons = g_buttons.load();
      out_state->gamepad.thumb_lx = g_lx.load();
      out_state->gamepad.thumb_ly = g_ly.load();
      out_state->gamepad.thumb_rx = g_rx.load();
      out_state->gamepad.thumb_ry = g_ry.load();
      out_state->gamepad.left_trigger = g_lt.load();
      out_state->gamepad.right_trigger = g_rt.load();
    }
    return X_ERROR_SUCCESS;
  }
  X_RESULT SetState(uint32_t user_index, X_INPUT_VIBRATION*) override {
    return user_index == 0 ? X_ERROR_SUCCESS : X_ERROR_DEVICE_NOT_CONNECTED;
  }
  X_RESULT GetKeystroke(uint32_t user_index, uint32_t, X_INPUT_KEYSTROKE*) override {
    return user_index == 0 ? X_ERROR_EMPTY : X_ERROR_DEVICE_NOT_CONNECTED;
  }
};

uint16_t ButtonMask(const std::string& name) {
  static const struct { const char* name; uint16_t mask; } kButtons[] = {
      {"A", X_INPUT_GAMEPAD_A}, {"B", X_INPUT_GAMEPAD_B}, {"X", X_INPUT_GAMEPAD_X}, {"Y", X_INPUT_GAMEPAD_Y},
      {"START", X_INPUT_GAMEPAD_START}, {"BACK", X_INPUT_GAMEPAD_BACK},
      {"UP", X_INPUT_GAMEPAD_DPAD_UP}, {"DOWN", X_INPUT_GAMEPAD_DPAD_DOWN},
      {"LEFT", X_INPUT_GAMEPAD_DPAD_LEFT}, {"RIGHT", X_INPUT_GAMEPAD_DPAD_RIGHT},
      {"LB", X_INPUT_GAMEPAD_LEFT_SHOULDER}, {"RB", X_INPUT_GAMEPAD_RIGHT_SHOULDER},
  };
  for (const auto& b : kButtons)
    if (name == b.name) return b.mask;
  return 0;
}

void SetButtons(uint16_t mask) {
  g_buttons.store(mask);
  g_packet.fetch_add(1);
}

void RunScript(HWND window) {
  using clock = std::chrono::steady_clock;
  auto start = clock::now();
  auto seconds = [&] { return std::chrono::duration<double>(clock::now() - start).count(); };
  std::stringstream script(g_script);
  std::string command;
  while (std::getline(script, command, ';')) {
    std::stringstream words(command);
    std::string verb, arg;
    words >> verb >> arg;
    if (verb.empty()) continue;
    if (verb == "at") {
      double t = std::atof(arg.c_str());
      while (seconds() < t) std::this_thread::sleep_for(std::chrono::milliseconds(20));
    } else if (verb == "wait") {
      std::this_thread::sleep_for(std::chrono::milliseconds(int(std::atof(arg.c_str()) * 1000)));
    } else if (verb == "press") {
      int ms = 200;
      words >> ms;
      uint16_t mask = ButtonMask(arg);
      REXLOG_INFO("autotest: {:.1f} s press {}", seconds(), arg);
      SetButtons(mask);
      std::this_thread::sleep_for(std::chrono::milliseconds(ms));
      SetButtons(0);
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
    } else if (verb == "stick" || verb == "rstick") {
      // stick <x> <y>: -1..1 each, held until the next stick command (stick 0 0 releases)
      double x = std::atof(arg.c_str()), y = 0;
      words >> y;
      auto to_axis = [](double v) { return int16_t(std::max(-1.0, std::min(1.0, v)) * 32767); };
      REXLOG_INFO("autotest: {:.1f} s {} {} {}", seconds(), verb, x, y);
      (verb == "stick" ? g_lx : g_rx).store(to_axis(x));
      (verb == "stick" ? g_ly : g_ry).store(to_axis(y));
      g_packet.fetch_add(1);
    } else if (verb == "lt" || verb == "rt") {
      // lt/rt <0..1>: trigger, held
      (verb == "lt" ? g_lt : g_rt).store(uint8_t(std::max(0.0, std::min(1.0, std::atof(arg.c_str()))) * 255));
      g_packet.fetch_add(1);
    } else if (verb == "shot") {
      REXLOG_INFO("autotest: {:.1f} s shot", seconds());
      NativeFrontend_RequestSnapshot();
      std::this_thread::sleep_for(std::chrono::milliseconds(700));
    } else if (verb == "exit") {
      REXLOG_INFO("autotest: {:.1f} s exit", seconds());
      PostMessageW(window, WM_CLOSE, 0, 0);
      return;
    } else {
      REXLOG_ERROR("autotest: unknown command '{}'", command);
    }
  }
  REXLOG_INFO("autotest: script finished");
}
}  // namespace

void AutoTest_Init() {
  if (const char* cvars = std::getenv("F2_CVARS")) {
    std::stringstream list(cvars);
    std::string item;
    while (std::getline(list, item, ';')) {
      auto eq = item.find('=');
      if (eq == std::string::npos) continue;
      rex::cvar::SetFlagByName(item.substr(0, eq), item.substr(eq + 1));
    }
  }
  if (const char* script = std::getenv("F2_AUTOTEST")) {
    g_script = script;
    g_active = !g_script.empty();
  }
  if (g_active) rex::cvar::SetFlagByName("audio_mute", "true");  // (unattended runs stay silent)
}

bool AutoTest_Active() { return g_active; }

void AutoTest_Start(rex::input::InputSystem* input, void* window, void* previous_foreground) {
  if (!g_active) return;
  HWND hwnd = static_cast<HWND>(window);
  // Stay out of the way: behind the other windows, focus back where it was.
  SetWindowPos(hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
  if (previous_foreground) SetForegroundWindow(static_cast<HWND>(previous_foreground));
  if (input) input->AddDriver(std::make_unique<ScriptedPad>());
  REXLOG_INFO("autotest: script '{}'", g_script);
  std::thread(RunScript, hwnd).detach();
}
