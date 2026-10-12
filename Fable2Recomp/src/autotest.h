// Automated test runs (tools/autotest.py): scripted controller input fed straight to the game, frame
// snapshots and a clean exit, without touching the desktop's keyboard, mouse or focus.
//
// Environment (unset = normal play, nothing here is active):
//   F2_AUTOTEST   script, commands separated by ';' :
//                   at <s>            wait until <s> seconds after start
//                   wait <s>          wait <s> seconds
//                   press <button> [ms]   A B X Y START BACK UP DOWN LEFT RIGHT LB RB (default 200 ms)
//                   stick <x> <y>     left stick, -1..1 each, held until changed (rstick: right stick)
//                   lt <0..1> / rt <0..1>   triggers, held until changed
//                   shot              save the next presented frame (native_snapshots/frame_<n>.png)
//                   exit              close the game
//   F2_CVARS      "name=value;name=value": cvars set after Fable2.toml is loaded (they win over the file)
#pragma once

namespace rex::input { class InputSystem; }

// Reads the environment, applies F2_CVARS. Call after the configuration file is loaded.
void AutoTest_Init();
bool AutoTest_Active();
// Adds the scripted controller and starts the script. window/previous_foreground are HWNDs (the game
// window goes behind the other windows and focus returns to previous_foreground).
void AutoTest_Start(rex::input::InputSystem* input, void* window, void* previous_foreground);
