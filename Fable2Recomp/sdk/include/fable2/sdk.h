// Fable II PC SDK - helpers for hand-written C++ that replaces or extends the recompiled game code.
//
// Game memory is the Xbox 360's: 32-bit guest addresses, big-endian values. Readable code describes
// game objects as structs of rex::be<T> fields and f2::gptr<T> pointers laid over that memory:
//
//   struct Creature {                 // (example layout)
//     f2::gptr<CreatureVtbl> vtable;  // +0x00
//     rex::be<uint32_t> flags;        // +0x04
//     rex::be<float> health;          // +0x08
//   };
//   Creature* c = f2::At<Creature>(address);
//   if (c->health < 10.0f) c->health = 100.0f;      // byte-swapped transparently
//
// Replacing a game function (built-in modules, link time):
//   static void SetDrawGameFPS(bool on) { ... }      // plain C++ types, marshalled from registers
//   REX_HOOK(sub_823A5918, SetDrawGameFPS);           // the game now calls SetDrawGameFPS
// or with full register access:
//   REX_HOOK_RAW(sub_823A5918) { ...; __imp__sub_823A5918(ctx, base); }   // (__imp__ = original)
//
// Calling a game function from built-in hand-written code (on a game thread):
//   uint32_t r = f2::Call<uint32_t>(sub_8222CF18, out_addr, text_addr, -1);   (src/game/rewrite.h)
// Plugins call the pointer they got from Fable2ModApi::find_function / hook_function with a
// PPCContext whose r1 lies below the caller's stack frame.
//
// Plugin DLLs replace functions at run time instead (see fable2/mod_api.h).
#pragma once

#include <rex/ppc/context.h>
#include <rex/types.h>

#include <cstdint>
#include <cstring>
#include <string_view>

namespace f2 {

// Host address of guest memory address 0 (set by the game before any mod code runs; plugins get it
// from Fable2ModApi::guest_base).
inline uint8_t* g_base = nullptr;
inline uint8_t* Base() { return g_base; }

// Host pointer for a guest address. (Windows hosts map the physical ranges at 0xE0000000+ 4 KB
// higher, like the recompiled code's REX_PHYS_HOST_OFFSET.)
inline uint8_t* HostPtr(uint32_t guest) {
  return g_base + guest + (guest >= 0xE0000000u ? 0x1000u : 0u);
}
template <class T>
inline T* At(uint32_t guest) {
  return guest ? reinterpret_cast<T*>(HostPtr(guest)) : nullptr;
}
// Guest address of a host pointer into game memory.
inline uint32_t GuestAddress(const void* host) {
  return host ? uint32_t(reinterpret_cast<const uint8_t*>(host) - g_base) : 0;
}

// A 32-bit guest pointer as stored inside game memory (big-endian address).
template <class T>
struct gptr {
  rex::be<uint32_t> address;

  uint32_t addr() const { return address; }
  T* get() const { return At<T>(address); }
  T* operator->() const { return get(); }
  T& operator*() const { return *get(); }
  explicit operator bool() const { return address.get() != 0; }
  gptr& operator=(const T* p) {
    address = GuestAddress(p);
    return *this;
  }
};
static_assert(sizeof(gptr<int>) == 4);

// NUL-terminated string in game memory.
inline std::string_view CString(uint32_t guest) {
  if (!guest) return {};
  return reinterpret_cast<const char*>(HostPtr(guest));
}

// Padding helper for partially known structs: f2::pad<0x24> unknown_04;
template <size_t N>
struct pad {
  uint8_t bytes[N];
};

}  // namespace f2

// Layout checks for game structs: F2_OFFSET(Creature, health, 0x08);
#define F2_OFFSET(type, field, offset) static_assert(offsetof(type, field) == (offset), #type "::" #field)
#define F2_SIZE(type, size) static_assert(sizeof(type) == (size), #type " size")
