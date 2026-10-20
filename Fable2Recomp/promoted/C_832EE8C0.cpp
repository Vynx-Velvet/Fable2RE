// C_832EE8C0 (vtable 0x832EE8C0): methods of the class as readable C++.
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

uint64_t Heap_Alloc(CpuState& ctx, uint8_t* base, uint64_t size) {
	if (!UseLiftedCode(6, 0x8221F3F0)) { ctx.r3.u64 = size; __imp__sub_8221F3F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8221F3F0);
	uint64_t fromSizeClass{};
	fromSizeClass = Heap_AllocFromSizeClass(ctx, base, size);
	return fromSizeClass;
}
PROMOTED_ENTRY(6, sub_8221F3F0, 0x8221F3F0) { ctx.r3.u64 = Heap_Alloc(ctx, base, ctx.r3.u64); }
