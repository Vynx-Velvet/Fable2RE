// C_820E1648 (vtable 0x820E1648): methods of the class as readable C++.
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

uint64_t n_sub_828C2A38(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t flags) {
	if (!UseLiftedCode(62, 0x828C2A38)) { ctx.r3.u64 = object; ctx.r4.u64 = flags; __imp__sub_828C2A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828C2A38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flags;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, object + 132);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, object + 84);
	HandleHolder_Dtor(ctx, base, object);
	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(62, sub_828C2A38, 0x828C2A38) { ctx.r3.u64 = n_sub_828C2A38(ctx, base, ctx.r3.u64, ctx.r4.u64); }
