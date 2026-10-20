// C_820A6780 (vtable 0x820A6780): methods of the class as readable C++.
//
// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md).Each function was written
// by a language model from the lifter's exact code for the user's own copy and accepted by the differential
// checker on input profiles 0-5 (tools/rewrite/check.py --outputs).Review and game-check status per function:
// REVIEW.tsv in this directory and docs/status.md.A function keeps the address of the original
// (PROMOTED_ENTRY) and its fallback to the recompiled original (UseLiftedCode).
// Layouts and declarations come from the lifter, generated locally (lifted/classes.h, native_decls.h).
#include "lifted/lifted.h"
#include "lifted/classes.h"
#include "lifted/native_decls.h"

uint64_t C_820A6780_GetGlobal(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83499018 = int32_t(0x83499018);
	if (!UseLiftedCode(17, 0x82348CB0)) { __imp__sub_82348CB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82348CB0);
	return g_83499018;
}
PROMOTED_ENTRY(17, sub_82348CB0, 0x82348CB0) { ctx.r3.u64 = C_820A6780_GetGlobal(ctx, base); }
