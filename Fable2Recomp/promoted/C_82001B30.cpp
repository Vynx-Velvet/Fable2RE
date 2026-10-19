// C_82001B30 (vtable 0x82001B30): methods of the class as readable C++.
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

uint64_t C_82001B30_GetType(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8334E2D4 = int32_t(0x8334E2D4);
	if (!UseLiftedCode(9, 0x82267C88)) { __imp__sub_82267C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82267C88);
	return g_8334E2D4;
}
PROMOTED_ENTRY(9, sub_82267C88, 0x82267C88) { ctx.r3.u64 = C_82001B30_GetType(ctx, base); }
