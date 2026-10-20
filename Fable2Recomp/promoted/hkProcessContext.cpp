// hkProcessContext (vtable 0x82037228): methods of the class as readable C++.
//
// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md). Each function was written
// by a language model from the lifter's exact code for the user's own copy and accepted by the differential
// checker on input profiles 0-5 (tools/rewrite/check.py --outputs). Review and game-check status per function:
// REVIEW.tsv in this directory and docs/status.md. A function keeps the address of the original
// (PROMOTED_ENTRY) and its fallback to the recompiled original (UseLiftedCode).
// Layouts and declarations come from the lifter, generated locally (lifted/classes.h, native_decls.h).
#include "lifted/lifted.h"
#include "lifted/classes.h"
#include "lifted/native_decls.h"
#include "lifted/readable_support.h"

void hkProcessContext_SetNetworkMessageQueue(CpuState& ctx, uint8_t* base, uint32_t processContextAddr, uint32_t networkMessageQueue) {
	if (!UseLiftedCode(17, 0x82348CA8)) { ctx.r3.u64 = processContextAddr; ctx.r4.u64 = networkMessageQueue; __imp__sub_82348CA8(ctx, base); return; }
	LiftedFrame frame(0x82348CA8);
	hkProcessContext* processContext = GameObject<hkProcessContext>(base, processContextAddr);
	processContext->m_networkMessageQueue = networkMessageQueue;
	return;
}
PROMOTED_ENTRY(17, sub_82348CA8, 0x82348CA8) { hkProcessContext_SetNetworkMessageQueue(ctx, base, ctx.r3.u32, ctx.r4.u32); }
