// C_82006E90 (vtable 0x82006E90): methods of the class as readable C++.
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

uint64_t C_82006E90_GetType(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83499170 = int32_t(0x83499170);
	if (!UseLiftedCode(9, 0x82267568)) { __imp__sub_82267568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82267568);
	return g_83499170;
}
PROMOTED_ENTRY(9, sub_82267568, 0x82267568) { ctx.r3.u64 = C_82006E90_GetType(ctx, base); }
