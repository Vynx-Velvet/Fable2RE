/* Fable II PC - native mod (plugin DLL) interface.
 *
 * A plugin is a DLL in <exe folder>/mods/<ModName>/native/ exporting
 *
 *     extern "C" __declspec(dllexport) int Fable2Mod_Load(const Fable2ModApi* api);
 *
 * called once at startup, before any game code runs (return 0 on success). From there it can replace
 * any of the game's ~60,000 functions (by guest address, as listed in the decompilation index), call
 * the original, read and write game memory (see fable2/sdk.h) and run Lua in the game.
 *
 * Replacement functions have the recompiled code's signature: void fn(PPCContext& ctx, uint8_t* base)
 * - arguments in ctx.r3..r10 / ctx.f1..f13, results in ctx.r3 / ctx.f1.
 *
 * Plugins are built against the same SDK headers as the game (rexglue include directory +
 * Fable2Recomp/sdk/include) so PPCContext matches; the API itself is plain C and versioned.
 */
#ifndef FABLE2_MOD_API_H
#define FABLE2_MOD_API_H

#include <stdint.h>

#ifdef __cplusplus
struct PPCContext;
extern "C" {
#else
typedef struct PPCContext PPCContext;
#endif

#define FABLE2_MOD_API_VERSION 1

/* Same calling convention as the recompiled functions (PPCFunc). */
typedef void (*Fable2GuestFunction)(PPCContext* ctx, uint8_t* base);

enum Fable2LogLevel { FABLE2_LOG_DEBUG = 0, FABLE2_LOG_INFO = 1, FABLE2_LOG_WARN = 2, FABLE2_LOG_ERROR = 3 };

typedef struct Fable2ModApi {
  uint32_t version;     /* FABLE2_MOD_API_VERSION */
  uint32_t size;        /* sizeof(Fable2ModApi) - fields are only ever appended */
  uint8_t* guest_base;  /* host address of guest address 0 (f2::g_base) */

  /* The native function implementing the game function at `guest_address` (current, i.e. after
   * other mods' replacements), or NULL if there is none. */
  Fable2GuestFunction (*find_function)(uint32_t guest_address);

  /* Replaces the game function at `guest_address` with `replacement` for every caller (direct and
   * indirect). `original` (optional) receives a callable pointer to what ran before (the original
   * or an earlier mod's replacement). Returns 0 on success. */
  int (*hook_function)(uint32_t guest_address, Fable2GuestFunction replacement, Fable2GuestFunction* original);

  /* Writes to the game log (fable2.log), prefixed with the mod's name. */
  void (*log)(int level, const char* text);

  /* Runs Lua text in the game's Lua state between frames (as the F2 console does). */
  void (*queue_lua)(const char* code);

  /* Absolute path of this mod's folder (<exe folder>/mods/<ModName>), UTF-8. */
  const char* mod_directory;
  /* The mod's folder name. */
  const char* mod_name;
} Fable2ModApi;

typedef int (*Fable2ModLoadFn)(const Fable2ModApi* api);

#ifdef __cplusplus
}
#endif

#endif /* FABLE2_MOD_API_H */
