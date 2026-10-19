// BreakablePiece (vtable 0x820F3A2C): methods of the class as readable C++.
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

uint64_t n_sub_82A3D630(CpuState& ctx, uint8_t* base, uint64_t breakablePiece, uint64_t ringAllocator) {
	if (!UseLiftedCode(74, 0x82A3D630)) { ctx.r3.u64 = breakablePiece; ctx.r4.u64 = ringAllocator; __imp__sub_82A3D630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A3D630);
	return n_sub_82A3D640(ctx, base, ringAllocator, breakablePiece);
}
PROMOTED_ENTRY(74, sub_82A3D630, 0x82A3D630) { ctx.r3.u64 = n_sub_82A3D630(ctx, base, ctx.r3.u64, ctx.r4.u64); }
