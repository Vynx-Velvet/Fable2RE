/**
 * @file        src/heap.cpp
 * @brief       Native heap arena + hook registration for Fable2RE.
 *
 *              Faithful-baseline configuration: the recompiled game code runs
 *              its own allocators, CRT init, thread creation and render loop.
 *              No guest functions are replaced here. The dlmalloc arena is
 *              kept available for future native replacements but is unused
 *              until a hook is added.
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com> (via Fable2Recomp)
 *              Copyright (c) 2026 Fable2RE Contributors
 * @license     BSD 3-Clause License; full license text: rexglue-sdk/LICENSE.
 */

#include "heap.h"

#include <cstdio>
#include <cstring>

#include <dlmalloc.h>

#include "generated/Fable2_init.h"

#include <rex/hook.h>
#include <rex/ppc.h>
#include <rex/runtime.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xmemory.h>
#include <rex/logging.h>

namespace lh {

constexpr uint32_t kHeapSize = 64 * 1024 * 1024;

mspace g_mspace = nullptr;
uint8_t* g_membase = nullptr;
uint32_t g_arena_base = 0;
uint32_t g_arena_end = 0;

bool InitNativeHeap() {
    auto* mem = rex::system::kernel_memory();
    if (!mem) { REXLOG_ERROR("InitNativeHeap: null memory"); return false; }
    g_membase = mem->virtual_membase();
    uint32_t guest_base = mem->SystemHeapAlloc(kHeapSize);
    if (!guest_base) { REXLOG_ERROR("InitNativeHeap: alloc failed"); return false; }
    uint8_t* host_base = mem->TranslateVirtual<uint8_t*>(guest_base);
    g_arena_base = guest_base;
    g_arena_end = guest_base + kHeapSize;
    REXLOG_INFO("InitNativeHeap: 0x{:08X}-0x{:08X} host={} {}MB", g_arena_base, g_arena_end,
                (void*)host_base, kHeapSize / (1024 * 1024));
    g_mspace = create_mspace_with_base(host_base, kHeapSize, 1);
    if (!g_mspace) {
        REXLOG_ERROR("InitNativeHeap: mspace failed");
        mem->SystemHeapFree(guest_base);
        return false;
    }
    mspace_set_footprint_limit(g_mspace, kHeapSize);
    REXLOG_INFO("InitNativeHeap: ready");
    return true;
}

// Diagnostic: walk the CRT static-initializer tables that sub_82CC1990 will
// call through (bctrl) and report every entry the dispatcher cannot resolve,
// with the first guest instructions at that address so the entry can be
// classified (tail thunk, mid-function label, never-emitted function...).
// Reports only; it does not register anything except what the SDK's own
// tail-thunk fallback aliases.
static void AuditStaticInitTables() {
    auto* rt = rex::Runtime::instance();
    if (!rt || !rt->function_dispatcher() || !rt->memory()) return;
    auto* dp = rt->function_dispatcher();
    uint8_t* base = rt->memory()->virtual_membase();
    auto ld = [&](uint32_t a) { return __builtin_bswap32(*reinterpret_cast<uint32_t*>(base + a)); };

    struct Range { uint32_t begin, end; const char* name; };
    const Range ranges[] = {
        { 0x832D0010u, 0x832D5DC8u, "static-init table" },
        { 0x832D5DCCu, 0x832D5DDCu, "worker-init table" },
    };
    int total = 0, missing = 0, aliased = 0;
    for (const auto& r : ranges) {
        for (uint32_t a = r.begin; a < r.end; a += 4) {
            uint32_t fp = ld(a);
            if (fp == 0) continue;
            total++;
            if (fp < 0x82000000u || fp >= 0x83620000u) {
                fprintf(stderr, "[AUDIT] %s [%08X] = %08X (outside image)\n", r.name, a, fp);
                missing++;
                continue;
            }
            if (dp->GetFunction(fp)) continue;
            // Let the SDK try its tail-jump thunk aliasing.
            rex::runtime::ResolveIndirectFunction(fp);
            if (dp->GetFunction(fp)) { aliased++; continue; }
            missing++;
            fprintf(stderr, "[AUDIT] %s [%08X] = %08X UNRESOLVED  insn: %08X %08X %08X %08X\n",
                    r.name, a, fp, ld(fp), ld(fp + 4), ld(fp + 8), ld(fp + 12));
        }
    }
    fprintf(stderr, "[AUDIT] init tables: %d entries, %d aliased via tail thunk, %d unresolved\n",
            total, aliased, missing);
    fflush(stderr);
}

}  // namespace lh

// 0x82CB6EE0 (48 bytes) is in the CRT worker-init table (0x832D5DD8) but the
// codegen never emitted it (no .pdata entry, only referenced through a data
// pointer). Hand-translated from the guest bytes dumped under cdb:
//   lis r11,0x834F ; lwz r10,0x74CC(r11) ; cmpwi cr6,r10,0 ; bne cr6,done
//   li r9,1 ; stw r9,0x74CC(r11)        ; li r10,-3 ; stw r10,0x6AF4(r8=0x8333xxxx)
//   done: li r3,0 ; blr
REX_HOOK_RAW(fable2_crt_init_82CB6EE0) {
    if (REX_LOAD_U32(0x834F74CCu) == 0) {
        REX_STORE_U32(0x834F74CCu, 1u);
        REX_STORE_U32(0x83336AF4u, 0xFFFFFFFDu);
    }
    ctx.r3.u64 = 0;
}

namespace lh {

void RegisterHooks() {
    // Faithful baseline: only functions the codegen failed to emit are
    // supplied here, as literal translations of the guest bytes.
    // Static hooks (REX_HOOK / REX_HOOK_RAW in hooks.cpp) are linked in by
    // symbol name and need no registration here.
    REXLOG_INFO("RegisterHooks: faithful baseline");
    if (auto* rt = rex::Runtime::instance(); rt && rt->function_dispatcher()) {
        auto* dp = rt->function_dispatcher();
        if (!dp->GetFunction(0x82CB6EE0u)) dp->SetFunction(0x82CB6EE0u, fable2_crt_init_82CB6EE0);
    }
    AuditStaticInitTables();
}

}  // namespace lh
