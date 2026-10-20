// CLogbookMenuScreen (vtable 0x820C04C4): methods of the class as readable C++.
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

uint64_t CLogbookMenuScreen_GetList(CpuState& ctx, uint8_t* base, uint64_t logbookMenuScreen) {
	if (!UseLiftedCode(4, 0x821F51E8)) { ctx.r3.u64 = logbookMenuScreen; __imp__sub_821F51E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821F51E8);
	logbookMenuScreen = (int64_t)logbookMenuScreen + 32;
	return logbookMenuScreen;
}
PROMOTED_ENTRY(4, sub_821F51E8, 0x821F51E8) { ctx.r3.u64 = CLogbookMenuScreen_GetList(ctx, base, ctx.r3.u64); }
