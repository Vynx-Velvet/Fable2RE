// C_82001A64 (vtable 0x82001A64): methods of the class as readable C++.
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

uint64_t n_sub_8229ECE0(CpuState& ctx, uint8_t* base, uint64_t sourceObject, uint64_t destination) {
	if (!UseLiftedCode(11, 0x8229ECE0)) { ctx.r3.u64 = sourceObject; ctx.r4.u64 = destination; __imp__sub_8229ECE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229ECE0);
	return Object_Clone(ctx, base, destination, sourceObject);
}
PROMOTED_ENTRY(11, sub_8229ECE0, 0x8229ECE0) { ctx.r3.u64 = n_sub_8229ECE0(ctx, base, ctx.r3.u64, ctx.r4.u64); }
