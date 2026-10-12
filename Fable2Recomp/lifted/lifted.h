// Support for lifted game code (Fable2Recomp/lifted/lifted.*.cpp, produced by tools/lift/lift.py).
//
// Each lifted function replaces the recompiled one of the same name (sub_XXXXXXXX). Registers are
// local variables; the PPCContext is only read/written at the function boundary and around calls,
// so other code (recompiled, lifted or hand-written) sees exactly what the original produced.
// The cvar lifted_code = false switches every lifted function back to the recompiled original.
#pragma once

#include "generated/Fable2_init.h"

#include <atomic>
#include <type_traits>
#include <cstddef>

#include <cstring>

namespace f2 {
// Diagnostics: a call through a null pointer from lifted code names the lifted function.
[[noreturn]] void LiftedNullCall(const char* function, uint32_t lr_hint);
}  // namespace f2

// (lifted code: same as the recompiler's REX_CALL_INDIRECT_FUNC, plus the null check above)
#undef REX_CALL_INDIRECT_FUNC
#define REX_CALL_INDIRECT_FUNC(x)                                                          \
  do {                                                                                     \
    uint32_t rex_indirect_target_ = (uint32_t)(x);                                         \
    if (!rex_indirect_target_) [[unlikely]] f2::LiftedNullCall(__func__, 0);               \
    PPCFunc* rex_indirect_func_;                                                           \
    if ((uint32_t)(rex_indirect_target_ - REX_CODE_BASE) <                                 \
        REX_CODE_SIZE + REX_THUNK_RESERVE_SIZE) [[likely]] {                               \
      rex_indirect_func_ = REX_LOOKUP_FUNC(base, rex_indirect_target_);                    \
    } else {                                                                               \
      rex_indirect_func_ = nullptr;                                                        \
    }                                                                                      \
    if (!rex_indirect_func_) [[unlikely]] {                                                \
      ctx.last_indirect_target = rex_indirect_target_;                                     \
      rex_indirect_func_ = rex::runtime::ResolveIndirectFunction(rex_indirect_target_);    \
    }                                                                                      \
    rex_indirect_func_(ctx, base);                                                         \
  } while (0)

namespace f2 {
extern std::atomic<bool> g_lifted_enabled;
extern std::atomic<bool> g_lifted_file_on[512];
extern std::atomic<bool> g_lifted_ranges_active;
bool LiftedRangeDisabled(uint32_t address);

// Is the lifted version of a function (from generated file `file`, at `address`) switched on?
inline bool LiftedOn(int file, uint32_t address) {
  return g_lifted_enabled.load(std::memory_order_relaxed) && g_lifted_file_on[file].load(std::memory_order_relaxed) &&
         !(g_lifted_ranges_active.load(std::memory_order_relaxed) && LiftedRangeDisabled(address));
}

// ---- Game memory (big-endian, guest addresses). Functions, so an address is evaluated once. ----
inline uint8_t ld8(uint8_t* base, uint32_t a) { return REX_LOAD_U8(a); }
inline uint16_t ld16(uint8_t* base, uint32_t a) { return REX_LOAD_U16(a); }
inline uint32_t ld32(uint8_t* base, uint32_t a) { return REX_LOAD_U32(a); }
inline uint64_t ld64(uint8_t* base, uint32_t a) { return REX_LOAD_U64(a); }
inline void st8(uint8_t* base, uint32_t a, uint8_t v) { REX_STORE_U8(a, v); }
inline void st16(uint8_t* base, uint32_t a, uint16_t v) { REX_STORE_U16(a, v); }
inline void st32(uint8_t* base, uint32_t a, uint32_t v) { REX_STORE_U32(a, v); }
inline void st64(uint8_t* base, uint32_t a, uint64_t v) { REX_STORE_U64(a, v); }
inline uint8_t* raw(uint8_t* base, uint32_t a) { return REX_RAW_ADDR(a); }

inline float as_f32(uint32_t v) { float f; std::memcpy(&f, &v, 4); return f; }
inline uint32_t as_u32(float f) { uint32_t v; std::memcpy(&v, &f, 4); return v; }
inline double as_f64(uint64_t v) { double f; std::memcpy(&f, &v, 8); return f; }
inline uint64_t as_u64(double f) { uint64_t v; std::memcpy(&v, &f, 8); return v; }

// 16-byte vector load/store with the guest's byte order (lvx / stvx).
inline simde__m128i vload(uint8_t* base, uint32_t ea) {
  return simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)),
                               simde_mm_load_si128((simde__m128i*)VectorMaskL));
}
inline void vstore(uint8_t* base, uint32_t ea, simde__m128i v) {
  simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea),
                       simde_mm_shuffle_epi8(v, simde_mm_load_si128((simde__m128i*)VectorMaskL)));
}
}  // namespace f2

#define LOAD8(a) f2::ld8(base, (a))
#define LOAD16(a) f2::ld16(base, (a))
#define LOAD32(a) f2::ld32(base, (a))
#define LOAD64(a) f2::ld64(base, (a))
#define STORE8(a, v) f2::st8(base, (a), (v))
#define STORE16(a, v) f2::st16(base, (a), (v))
#define STORE32(a, v) f2::st32(base, (a), (v))
#define STORE64(a, v) f2::st64(base, (a), (v))
#define RAW(a) f2::raw(base, (a))
#define LOAD_F32(a) f2::as_f32(LOAD32(a))
#define STORE_F32(a, v) STORE32((a), f2::as_u32(v))
#define LOAD_F64(a) f2::as_f64(LOAD64(a))
#define STORE_F64(a, v) STORE64((a), f2::as_u64(v))
#define AS_F32(x) f2::as_f32(x)
#define AS_U32(x) f2::as_u32(x)
// Vector registers: integer (V8) / float (VF) views, and assignment.
#define V8(r) simde_mm_load_si128((simde__m128i*)(r).u8)
#define VF(r) simde_mm_load_ps((r).f32)
#define SET_V8(r, x) simde_mm_store_si128((simde__m128i*)(r).u8, (x))
#define SET_VF(r, x) simde_mm_store_ps((r).f32, (x))
#define VLOAD(ea) f2::vload(base, (ea))
#define VSTORE(ea, x) f2::vstore(base, (ea), (x))

// Bring-up diagnostics: each thread keeps the guest addresses of the lifted functions it is running;
// a crash prints them (lifted_switch.cpp), so a misbehaving lifted function names itself.
namespace f2 {
struct LiftedStack {
  uint32_t addr[256];
  uint32_t depth;
};
extern thread_local LiftedStack t_lifted_stack;
struct LiftedFrame {
  explicit LiftedFrame(uint32_t a) {
    auto& s = t_lifted_stack;
    if (s.depth < 256) s.addr[s.depth] = a;
    ++s.depth;
  }
  ~LiftedFrame() { --t_lifted_stack.depth; }
};
}  // namespace f2

// ---- Classes (tools/lift/classes.py -> classes.h) ---------------------------------------------------
namespace f2 {
// A big-endian value in game memory: reads and writes convert, like LOAD32 / STORE32 at its address.
template <typename T>
struct Be {
  T raw;
  operator T() const {
    if constexpr (sizeof(T) == 2) {
      uint16_t v; std::memcpy(&v, &raw, 2); v = __builtin_bswap16(v); T r; std::memcpy(&r, &v, 2); return r;
    } else if constexpr (sizeof(T) == 4) {
      uint32_t v; std::memcpy(&v, &raw, 4); v = __builtin_bswap32(v); T r; std::memcpy(&r, &v, 4); return r;
    } else {
      uint64_t v; std::memcpy(&v, &raw, 8); v = __builtin_bswap64(v); T r; std::memcpy(&r, &v, 8); return r;
    }
  }
  // (any number converts the way a store of that width did: wrap-around to T)
  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U> && !std::is_same_v<U, T>>>
  Be& operator=(U x) { return *this = static_cast<T>(x); }
  Be& operator=(T x) {
    if constexpr (sizeof(T) == 2) {
      uint16_t v; std::memcpy(&v, &x, 2); v = __builtin_bswap16(v); std::memcpy(&raw, &v, 2);
    } else if constexpr (sizeof(T) == 4) {
      uint32_t v; std::memcpy(&v, &x, 4); v = __builtin_bswap32(v); std::memcpy(&raw, &v, 4);
    } else {
      uint64_t v; std::memcpy(&v, &x, 8); v = __builtin_bswap64(v); std::memcpy(&raw, &v, 8);
    }
    return *this;
  }
};
}  // namespace f2
// (the struct definitions: each lifted file carries the ones it uses - tools/lift/chunks.py; all of them
// together are in lifted/classes.h)
// The object a guest pointer refers to, and assignment to one of its members (the value converts like the
// argument of STORE8/16/32/64 did).
#define F2_OBJ(Class, pointer) (reinterpret_cast<Class*>(RAW(pointer)))
#define F2_SET(member, value) ((member) = static_cast<decltype(f2::plain(member))>(value))
namespace f2 {
template <typename T> T plain(const Be<T>&);
inline uint8_t plain(const uint8_t&);
}  // namespace f2

// ---- Native entry points -----------------------------------------------------------------------
// A lifted function with a real signature:
//   uint32_t F2_NATIVE(sub_X)(F2_ENV, uint32_t r3, double f1) { F2_NATIVE_ENTER(...); ... return r3_2; }
//   F2_LIFTED(sub_X, 0x...) { ctx.r3.u64 = F2_NATIVE(sub_X)(ctx, base, ctx.r3.u32, ctx.f1.f64); }
// Lifted code calls n_sub_X(ctx, base, args...) directly; everything else (recompiled code, hooks, calls
// through pointers) still enters through sub_X(ctx, base). F2_ENV is what is left of the register context:
// registers the signature does not cover yet travel through it. Each lifted file declares the functions it
// calls; native_bridges.*.cpp (tools/lift/native_gen.py) give the not-lifted ones a body.
#define F2_ENV [[maybe_unused]] PPCContext& __restrict ctx, [[maybe_unused]] uint8_t* base
#ifndef F2_NATIVE
#define F2_NATIVE(name) n_##name
#endif
// A function that has a name in the naming dictionary (research/names) is defined under that name.
#ifndef F2_NAMED
#define F2_NAMED(name) name
#endif
// First statement of a native function: with lifted code switched off for it, run the recompiled original
// (SET writes the arguments to the context, RESULT reads the result back).
#define F2_NATIVE_ENTER(name, address, SET, RESULT)                                          if (!f2::LiftedOn(F2_LIFTED_FILE, address)) [[unlikely]] {                                   SET;                                                                                       __imp__##name(ctx, base);                                                                  return RESULT;                                                                           }                                                                                          f2::LiftedFrame f2_frame(address)

// ---- Words the readable lifted code uses ----------------------------------------------------------
// The CPU state still handed between functions for what their signatures do not cover yet.
using CpuState = PPCContext;
// A value stored big-endian in game memory (reads and writes convert).
template <typename T>
using BigEndian = f2::Be<T>;
// The game object at a game address.
template <typename T>
inline T* GameObject(uint8_t* base, uint32_t address) { return reinterpret_cast<T*>(RAW(address)); }
// The game's stack: a frame of `size` bytes below the current one, linked to it (as the original code did).
inline uint32_t PushStackFrame(uint8_t* base, uint32_t stack, uint32_t size) {
  uint32_t frame = stack - size;
  STORE32(frame, stack);
  return frame;
}
inline uint32_t PopStackFrame(uint32_t stack, uint32_t size) { return stack + size; }
// Whether the lifted version of a function runs (lifted_code / lifted_disable_* switches).
inline bool UseLiftedCode(int file, uint32_t address) { return f2::LiftedOn(file, address); }
using LiftedFrame = f2::LiftedFrame;

// F2_LIFTED(sub_XXXXXXXX, 0xXXXXXXXX) { ... }   (each lifted.N.cpp defines F2_LIFTED_FILE = N)
#define F2_LIFTED(name, address) F2_LIFTED_IN(F2_LIFTED_FILE, name, address)
#define F2_LIFTED_IN(file, name, address)                                                  \
  static inline void f2_lifted_##name(PPCContext& __restrict ctx, uint8_t* base);         \
  extern "C" REX_FUNC(name) {                                                              \
    if (f2::LiftedOn(file, address)) [[likely]] {                                          \
      f2::LiftedFrame f2_frame(address);                                                   \
      f2_lifted_##name(ctx, base);                                                         \
    } else {                                                                               \
      __imp__##name(ctx, base);                                                            \
    }                                                                                      \
  }                                                                                        \
  static inline void f2_lifted_##name([[maybe_unused]] PPCContext& __restrict ctx, uint8_t* base)

// How code that still passes the whole CPU state (recompiled code, hooks, calls through pointers) enters a
// lifted function: the body takes the arguments out of the state, calls the function and puts its result back.
//   CPU_STATE_ENTRY(sub_X, 0x...) { ctx.r3.u64 = Name(ctx, base, ctx.r3.u32); }
#define CPU_STATE_ENTRY(name, address) F2_LIFTED(name, address)
// The same for a function that lives in a source module (Fable2Recomp/src/game/promoted/, tools/rewrite/promote.py)
// instead of a lifted file: `file` is the generated file it came from, whose switch (lifted_disable_files) it
// still follows.
#define PROMOTED_ENTRY(file, name, address) F2_LIFTED_IN(file, name, address)
// The generated file a chunk of lifted code comes from (its switch: lifted_disable_files).
#if defined(LIFTED_FILE_INDEX) && !defined(F2_LIFTED_FILE)
#define F2_LIFTED_FILE LIFTED_FILE_INDEX
#endif
