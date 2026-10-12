// Run Lua text in the game's own Lua VM. See src/lua_bridge.cpp.
#pragma once

#include <string>

struct LuaBridgeResult {
  std::string code;
  bool ok = false;
  std::string message;
};

// Thread-safe: queue a chunk; it runs on GameThread at the next main-loop iteration.
void LuaBridge_Queue(std::string code);
// True once the in-game main loop has run with a valid lua_State.
bool LuaBridge_IsReady();
// Thread-safe: pop the oldest finished chunk.
bool LuaBridge_PopResult(LuaBridgeResult& out);
