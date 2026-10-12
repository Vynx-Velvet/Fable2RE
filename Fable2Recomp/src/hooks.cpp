/**
 * @file        src/hooks.cpp
 *
 * @brief       Native hook implementations for Xbox 360 kernel/XAM APIs.
 *
 *              Replaces REX_STUB declarations with proper native implementations
 *              that return valid Xbox error codes, allowing the game to proceed
 *              without Xbox Live infrastructure.
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 *              All rights reserved. (ReXGlue project template, via Fable2Recomp)
 *              Copyright (c) 2026 Fable2RE Contributors (the hook implementations)
 *
 * @license     BSD 3-Clause License
 *              Full license text: rexglue-sdk/LICENSE.
 */

#include <cstdint>
#include <chrono>
#include <string>
#include <algorithm>
#include <fmt/format.h>

#include "generated/Fable2_init.h"

#include <rex/hook.h>
#include <rex/thread.h>
#include <immintrin.h>
#include <rex/ppc.h>
#include <rex/logging.h>

// Xbox 360 status codes (matching XBOX kernel definitions)
static constexpr uint32_t kXErrorSuccess = 0;
static constexpr uint32_t kXErrorFailed  = 0x8007065B;

// Fable 2 title ID: 0x4D5307F1
static constexpr uint32_t kFable2TitleID = 0x4D5307F1;

// Default user profile values
static constexpr uint32_t kMembershipTierGold = 3;
static constexpr uint32_t kCountryUS          = 103;

// NOTE: the upstream "GetFileSectorInfo" hook on sub_82CC7BB8 was removed on
// 2026-09-28: 0x82CC7BB8 is not a function start in this XEX (it is inside
// 0x82CC7888-0x82CC7E48); the address came from a different build's symbols.

// ============================================================================
// XAM UI Functions — return success (no Xbox 360 UI overlays)
// ============================================================================

REX_HOOK_RAW(__imp__XamShowAchievementsUI) {
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__XamShowGamerCardUIForXUID) {
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__XamShowMarketplaceUI) {
    ctx.r3.u64 = kXErrorSuccess;
}

// ============================================================================
// XAM User Functions
// ============================================================================

REX_HOOK_RAW(__imp__XamUserGetMembershipTierFromXUID) {
    ctx.r3.u64 = kMembershipTierGold;
}

REX_HOOK_RAW(__imp__XamUserGetOnlineCountryFromXUID) {
    ctx.r3.u64 = kCountryUS;
}

// ============================================================================
// XAM Voice — no-op (no voice chat support)
// ============================================================================

REX_HOOK_RAW(__imp__XamVoiceSubmitPacket) {
    ctx.r3.u64 = kXErrorSuccess;
}

// ============================================================================
// Networking (XNet / NetDll) — offline mode
// ============================================================================

REX_HOOK_RAW(__imp__XNetLogonGetTitleID) {
    uint32_t out_ptr = static_cast<uint32_t>(ctx.r3.u64);
    if (out_ptr) {
        REX_STORE_U32(out_ptr, kFable2TitleID);
    }
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__NetDll_WSAGetOverlappedResult) {
    ctx.r3.u64 = kXErrorFailed;
}

REX_HOOK_RAW(__imp__NetDll_XNetRegisterKey) {
    ctx.r3.u64 = kXErrorFailed;
}

REX_HOOK_RAW(__imp__NetDll_XNetUnregisterKey) {
    ctx.r3.u64 = kXErrorFailed;
}

REX_HOOK_RAW(__imp__NetDll_XNetUnregisterInAddr) {
    ctx.r3.u64 = kXErrorFailed;
}

REX_HOOK_RAW(__imp__NetDll_XNetConnect) {
    ctx.r3.u64 = kXErrorFailed;
}

REX_HOOK_RAW(__imp__NetDll_XNetGetConnectStatus) {
    ctx.r3.u64 = kXErrorFailed;
}

// ============================================================================
// I/O Functions
// ============================================================================

REX_HOOK_RAW(__imp__IoInvalidDeviceRequest) {
    ctx.r3.u64 = kXErrorFailed;
}

REX_HOOK_RAW(__imp__IoDeleteDevice) {
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__IoCompleteRequest) {
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__IoCheckShareAccess) {
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__IoRemoveShareAccess) {
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__IoSetShareAccess) {
    ctx.r3.u64 = kXErrorSuccess;
}

// ============================================================================
// Object Manager Functions
// ============================================================================

REX_HOOK_RAW(__imp__ObReferenceObject) {
    ctx.r3.u64 = kXErrorSuccess;
}

REX_HOOK_RAW(__imp__ObIsTitleObject) {
    ctx.r3.u64 = 0;  // FALSE — not a title object
}

// ============================================================================
// RTL Functions
// ============================================================================

REX_HOOK_RAW(__imp__RtlUpcaseUnicodeChar) {
    wchar_t ch = static_cast<wchar_t>(ctx.r3.u64 & 0xFFFF);
    if (ch >= L'a' && ch <= L'z') {
        ch = ch - L'a' + L'A';
    }
    ctx.r3.u64 = static_cast<uint32_t>(ch);
}

// ============================================================================
// Performance shims (behaviour-preserving)
// ============================================================================

// sub_82B9BF90 is the D3D runtime's GPU-progress poll: 8x db16cyc (a 16-cycle
// Xenon pause hint the codegen emits as nothing), then a check whether the
// ring-buffer read pointer advanced, with a 5000-tick hang check. The render
// thread ("3D Engine") calls it in a tight loop from sub_82242628 while waiting
// for ring-buffer space, burning a full core and the hyperthread sibling of the
// host command-processor thread it is waiting for. Add a real pause + yield in
// front of the original body (the generated body stays reachable as __imp__).
REX_HOOK_RAW(sub_82B9BF90) {
    static bool announced = false;
    if (!announced) {
        announced = true;
        REXLOG_INFO("hooks: sub_82B9BF90 override active (hook binding verified)");
    }
    for (int i = 0; i < 64; ++i) _mm_pause();
    rex::thread::MaybeYield();
    __imp__sub_82B9BF90(ctx, base);
}

// ============================================================================
// Environmental reverb (XAudio2FX reverb XAPO statically linked into the title)
//
// sub_82CDF788  reverb object SetParameter(index, value): index 0 copies a whole
//               I3DL2 parameter block (48 bytes: Room, RoomHF, RoomRolloffFactor,
//               DecayTime, DecayHFRatio, Reflections, ReflectionsDelay, Reverb,
//               ReverbDelay, Diffusion, Density, HFReference), 1..12 set one field.
// sub_82CDF4F8  ReverbConvertI3DL2ToNative (r4 = I3DL2 block, r5 = native block).
// sub_82CDDB68  sets the wet/dry mix: obj+92 = f1 (percent) * 0.01.
// sub_82CDDB80  applies a native parameter block (r4, 84 bytes) to the XAPO.
//
// The hooks log every parameter change (audio_reverb_log) and, with
// audio_reverb_disable, silence the wet path (gains -100 dB, wet/dry 0) so the
// effect can be isolated without touching the game's data.
// ============================================================================

#include <rex/cvar.h>
#include <atomic>
#include <cstring>

REXCVAR_DEFINE_BOOL(audio_reverb_disable, false, "Audio",
                    "Silence the title's environmental reverb (XAudio2FX reverb): reflections and "
                    "reverb gain forced to -100 dB and the wet/dry mix to 0 whenever the game "
                    "applies reverb parameters.");
REXCVAR_DEFINE_BOOL(audio_reverb_log, true, "Audio",
                    "Log the environmental reverb parameters whenever the game changes them.");

namespace {
inline float GuestF32(uint8_t* base, uint32_t addr) {
    uint32_t u = REX_LOAD_U32(addr);
    float f;
    std::memcpy(&f, &u, sizeof(f));
    return f;
}
inline void GuestStoreF32(uint8_t* base, uint32_t addr, float f) {
    uint32_t u;
    std::memcpy(&u, &f, sizeof(u));
    REX_STORE_U32(addr, u);
}
inline uint64_t GuestHash(uint8_t* base, uint32_t addr, uint32_t bytes) {
    uint64_t h = 1469598103934665603ull;
    for (uint32_t i = 0; i < bytes; i += 4) {
        h ^= REX_LOAD_U32(addr + i);
        h *= 1099511628211ull;
    }
    return h;
}
std::atomic<uint32_t> g_reverb_set_calls{0}, g_reverb_apply_calls{0};
uint64_t g_reverb_last_i3dl2_hash = 0, g_reverb_last_native_hash = 0;
}  // namespace

REX_HOOK_RAW(sub_82CDF788) {
    const uint32_t index = ctx.r4.u32;
    const uint32_t value_ptr = ctx.r5.u32;
    const uint32_t calls = g_reverb_set_calls.fetch_add(1, std::memory_order_relaxed) + 1;
    if (REXCVAR_GET(audio_reverb_log)) {
        if (index == 0) {
            uint64_t h = GuestHash(base, value_ptr, 48);
            if (h != g_reverb_last_i3dl2_hash) {
                g_reverb_last_i3dl2_hash = h;
                REXLOG_INFO("Reverb I3DL2 set #{}: Room={} RoomHF={} Rolloff={:.2f} DecayTime={:.2f} "
                            "DecayHFRatio={:.2f} Reflections={} ReflectionsDelay={:.3f} Reverb={} "
                            "ReverbDelay={:.3f} Diffusion={:.1f} Density={:.1f} HFReference={:.0f}",
                            calls, (int32_t)REX_LOAD_U32(value_ptr + 0), (int32_t)REX_LOAD_U32(value_ptr + 4),
                            GuestF32(base, value_ptr + 8), GuestF32(base, value_ptr + 12),
                            GuestF32(base, value_ptr + 16), (int32_t)REX_LOAD_U32(value_ptr + 20),
                            GuestF32(base, value_ptr + 24), (int32_t)REX_LOAD_U32(value_ptr + 28),
                            GuestF32(base, value_ptr + 32), GuestF32(base, value_ptr + 36),
                            GuestF32(base, value_ptr + 40), GuestF32(base, value_ptr + 44));
            }
        } else {
            REXLOG_INFO("Reverb I3DL2 set #{}: field {} = {} / {:.4f}", calls, index,
                        (int32_t)REX_LOAD_U32(value_ptr), GuestF32(base, value_ptr));
        }
    }
    __imp__sub_82CDF788(ctx, base);
}

REX_HOOK_RAW(sub_82CDDB68) {
    if (REXCVAR_GET(audio_reverb_log)) {
        REXLOG_INFO("Reverb wet/dry mix set: {:.1f}%", ctx.f1.f64);
    }
    if (REXCVAR_GET(audio_reverb_disable)) {
        ctx.f1.f64 = 0.0;
    }
    __imp__sub_82CDDB68(ctx, base);
}

REX_HOOK_RAW(sub_82CDDB80) {
    const uint32_t obj = ctx.r3.u32;
    const uint32_t p = ctx.r4.u32;
    const uint32_t calls = g_reverb_apply_calls.fetch_add(1, std::memory_order_relaxed) + 1;
    if (REXCVAR_GET(audio_reverb_log)) {
        uint64_t h = GuestHash(base, p, 84) ^ REX_LOAD_U32(obj + 92);
        if (h != g_reverb_last_native_hash) {
            g_reverb_last_native_hash = h;
            REXLOG_INFO("Reverb apply #{}: ReflectionsDelay={}ms ReverbDelay={}ms Position=({},{}) "
                        "PositionMatrix=({},{}) Diffusion=({},{}) LowEQ=({},{}) HighEQ=({},{}) "
                        "RearDelay={} RoomFilterFreq={:.0f} RoomFilterMain={:.2f}dB RoomFilterHF={:.2f}dB "
                        "ReflectionsGain={:.2f}dB ReverbGain={:.2f}dB DecayTime={:.2f}s Density={:.1f} "
                        "RoomSize={:.1f} wetdry={:.3f} rate={:.0f}",
                        calls, REX_LOAD_U32(p + 0), REX_LOAD_U32(p + 4), REX_LOAD_U32(p + 8),
                        REX_LOAD_U32(p + 12), REX_LOAD_U32(p + 16), REX_LOAD_U32(p + 20),
                        REX_LOAD_U32(p + 24), REX_LOAD_U32(p + 28), REX_LOAD_U32(p + 32),
                        REX_LOAD_U32(p + 36), REX_LOAD_U32(p + 40), REX_LOAD_U32(p + 44),
                        REX_LOAD_U32(p + 48), GuestF32(base, p + 52), GuestF32(base, p + 56),
                        GuestF32(base, p + 60), GuestF32(base, p + 64), GuestF32(base, p + 68),
                        GuestF32(base, p + 72), GuestF32(base, p + 76), GuestF32(base, p + 80),
                        GuestF32(base, obj + 92), GuestF32(base, obj + 88));
        }
    }
    if (REXCVAR_GET(audio_reverb_disable)) {
        GuestStoreF32(base, p + 64, -100.0f);  // ReflectionsGain
        GuestStoreF32(base, p + 68, -100.0f);  // ReverbGain
        GuestStoreF32(base, obj + 92, 0.0f);   // wet/dry mix
    }
    __imp__sub_82CDDB80(ctx, base);
}

// ----------------------------------------------------------------------------
// Reverb XAPO entry points (vtable at 0x82013E18):
//   sub_82CD7EA0  IXAPOParameters::SetParameters(this, pParams, size) - queues a
//                 parameter block and raises one of the flags below.
//   sub_82CD7788  per-quantum entry: applies pending updates (flags +188 wet/dry
//                 via +184, +189 native block at +52, +190 I3DL2 block at +136)
//                 and then runs the DSP (sub_82CD6010, 256 frames).
// The first diagnostic run showed none of the parameter hooks firing, so these
// two tell whether the effect runs at all and whether it is ever configured.
// ----------------------------------------------------------------------------

namespace {
std::atomic<uint32_t> g_reverb_quantum_calls{0}, g_reverb_setparams_calls{0};
std::atomic<uint32_t> g_hooks_active_logged{0};
uint64_t g_reverb_last_quantum_log_ms = 0;

inline uint64_t NowMs() {
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count());
}

void LogReverbObject(uint8_t* base, uint32_t obj, const char* why) {
    const uint32_t p = obj + 52;  // current native block
    REXLOG_INFO("Reverb object ({}): quanta={} setparams={} flags wet={} native={} i3dl2={} rate={:.0f} wetdry={:.3f} | "
                "native: ReflectionsDelay={}ms ReverbDelay={}ms ReflectionsGain={:.2f}dB ReverbGain={:.2f}dB "
                "DecayTime={:.2f}s Density={:.1f} RoomFilterMain={:.2f}dB RoomFilterHF={:.2f}dB RoomFilterFreq={:.0f} "
                "Diffusion=({},{}) RoomSize={:.1f} | i3dl2: Room={} RoomHF={} DecayTime={:.2f} Reverb={} Reflections={}",
                why, g_reverb_quantum_calls.load(), g_reverb_setparams_calls.load(), REX_LOAD_U8(obj + 188),
                REX_LOAD_U8(obj + 189), REX_LOAD_U8(obj + 190), GuestF32(base, obj + 88), GuestF32(base, obj + 92),
                REX_LOAD_U32(p + 0), REX_LOAD_U32(p + 4), GuestF32(base, p + 64), GuestF32(base, p + 68),
                GuestF32(base, p + 72), GuestF32(base, p + 76), GuestF32(base, p + 56), GuestF32(base, p + 60),
                GuestF32(base, p + 52), REX_LOAD_U32(p + 24), REX_LOAD_U32(p + 28), GuestF32(base, p + 80),
                (int32_t)REX_LOAD_U32(obj + 136), (int32_t)REX_LOAD_U32(obj + 140), GuestF32(base, obj + 148),
                (int32_t)REX_LOAD_U32(obj + 164), (int32_t)REX_LOAD_U32(obj + 156));
}
}  // namespace

REX_HOOK_RAW(sub_82CD7EA0) {
    const uint32_t p = ctx.r4.u32, size = ctx.r5.u32;
    const uint32_t calls = g_reverb_setparams_calls.fetch_add(1, std::memory_order_relaxed) + 1;
    if (REXCVAR_GET(audio_reverb_log) && (calls <= 3)) {
        std::string words;
        for (uint32_t i = 0; i < std::min<uint32_t>(size, 96); i += 4) {
            words += fmt::format(" {:08X}", REX_LOAD_U32(p + i));
        }
        REXLOG_INFO("Reverb SetParameters #{}: size={} data:{}", calls, size, words);
    }
    __imp__sub_82CD7EA0(ctx, base);
}

REX_HOOK_RAW(sub_82CD7788) {
    const uint32_t obj = ctx.r3.u32;
    const uint32_t calls = g_reverb_quantum_calls.fetch_add(1, std::memory_order_relaxed) + 1;
    if (REXCVAR_GET(audio_reverb_disable)) {
        // Kill switch: keep the wet/dry mix at zero and, once, push silent gains
        // through the normal apply path so the delay-line coefficients follow.
        static bool forced = false;
        if (!forced) {
            forced = true;
            GuestStoreF32(base, obj + 52 + 64, -100.0f);
            GuestStoreF32(base, obj + 52 + 68, -100.0f);
            REX_STORE_U8(obj + 189, 1);
        }
        GuestStoreF32(base, obj + 92, 0.0f);
    }
    if (REXCVAR_GET(audio_reverb_log)) {
        uint64_t now = NowMs();
        if (calls == 1 || now - g_reverb_last_quantum_log_ms > 10000) {
            g_reverb_last_quantum_log_ms = now;
            LogReverbObject(base, obj, calls == 1 ? "first quantum" : "periodic");
        }
    }
    __imp__sub_82CD7788(ctx, base);
}

// sub_829F8728: audio manager "set environmental reverb" (r4 = zone/reverb id
// read from the region property RegionEnvironmentalReverb). Logged to see
// whether the game ever asks for a zone reverb in our runtime.
REX_HOOK_RAW(sub_829F8728) {
    static std::atomic<uint32_t> calls{0};
    const uint32_t n = calls.fetch_add(1, std::memory_order_relaxed) + 1;
    if (REXCVAR_GET(audio_reverb_log) && (n <= 50 || (n % 200) == 0)) {
        REXLOG_INFO("Reverb zone request #{}: id={} (0x{:08X}) mgr=0x{:08X}", n, (int32_t)ctx.r4.u32, ctx.r4.u32, ctx.r3.u32);
    }
    __imp__sub_829F8728(ctx, base);
}

// ============================================================================
// Game audio engine: per-block requantizer (sub_82C60180)
//
// For each channel k (count at obj+0): in = *(r4 + 4k), out = *(r5 + 4k),
// r6 = samples. When obj+52 is zero it just copies in -> out (sub_82C605D8).
// Otherwise, per sample: two LCG draws (sub_82C627E0) for TPDF dither, round to
// a 1/obj+72 grid (sub_82C60140), feed the quantisation error through a scalar
// FIR (sub_82C62548, obj+56 selects it) and clamp to [-1, 1-lsb]. That is a
// 16-bit noise-shaping quantiser applied to a float mix that the host mixes in
// float anyway: it was the single hottest guest function on the audio thread.
// The native version clamps and copies (the grid/dither are inaudible).
// ============================================================================

REXCVAR_DEFINE_BOOL(audio_native_requantizer, true, "Audio",
                    "Replace the game's per-sample dither/noise-shaping requantiser with a native clamp+copy.");

REX_HOOK_RAW(sub_82C60180) {
    const uint32_t obj = ctx.r3.u32;
    const uint32_t in_ptrs = ctx.r4.u32, out_ptrs = ctx.r5.u32;
    const int32_t samples = static_cast<int32_t>(ctx.r6.u32);
    const int32_t channels = static_cast<int32_t>(REX_LOAD_U32(obj + 0));
    if (!REXCVAR_GET(audio_native_requantizer) || REX_LOAD_U32(obj + 52) == 0 || samples <= 0 ||
        channels <= 0 || channels > 16) {
        __imp__sub_82C60180(ctx, base);
        return;
    }
    uint64_t scale_bits = REX_LOAD_U64(obj + 72);
    double scale;
    std::memcpy(&scale, &scale_bits, sizeof(scale));
    const float hi = scale > 1.0 ? float(1.0 - 1.0 / scale) : 1.0f;
    const float lo = -1.0f;
    for (int32_t k = 0; k < channels; ++k) {
        const uint32_t in = REX_LOAD_U32(in_ptrs + 4 * k);
        const uint32_t out = REX_LOAD_U32(out_ptrs + 4 * k);
        if (!in || !out) continue;
        for (int32_t i = 0; i < samples; ++i) {
            float v = GuestF32(base, in + 4 * i);
            v = v < lo ? lo : (v > hi ? hi : v);
            GuestStoreF32(base, out + 4 * i, v);
        }
    }
}
