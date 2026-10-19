// Helpers that keep machine-level details out of the bodies of the readable (promoted) functions
// (docs/promoted-code.md: readability levels; tools/rewrite/readable_form.py writes code that uses them).
// Each helper does exactly what the code it replaces did, so the strict check compares the same behaviour.
#pragma once
#include "lifted/lifted.h"

// The function's own frame on the game's stack, as the original code made it: pushed where it is declared and
// popped when the function returns (on every return path). Callees that still run as recompiled code keep their
// frames below it. Replaces PushStackFrame / PopStackFrame around a body that keeps nothing in the frame.
class GameStackFrame {
 public:
  GameStackFrame(CpuState& ctx, uint8_t* base, uint32_t size) : ctx_(ctx), caller_(uint32_t(ctx.r1.u64)) {
    ctx.r1.u64 = PushStackFrame(base, caller_, size);
  }
  ~GameStackFrame() { ctx_.r1.u64 = caller_; }   // (PopStackFrame(frame, size): the caller's stack pointer)
  GameStackFrame(const GameStackFrame&) = delete;
  GameStackFrame& operator=(const GameStackFrame&) = delete;

 private:
  CpuState& ctx_;
  uint32_t caller_;
};

// The C runtime's atexit (sub_82CA3700): registers the function at the game address `function` to run when the
// game exits, and returns 0, or -1 when it cannot. By the runtime's own register convention it also takes the
// value in r8 and hands it on unchanged, so a caller leaves r8 as it finds it: the call goes through the
// function's entry with r3 set and every other register as it is.
inline uint64_t RegisterAtExit(CpuState& ctx, uint8_t* base, uint32_t function) {
  ctx.r3.u64 = function;
  sub_82CA3700(ctx, base);
  return ctx.r3.u64;
}
