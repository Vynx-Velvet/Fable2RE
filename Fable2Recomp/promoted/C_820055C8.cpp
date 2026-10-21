// C_820055C8 (vtable 0x820055C8): methods of the class as readable C++.
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

uint64_t n_sub_828C24A0(CpuState& ctx, uint8_t* base, uint64_t holder, uint64_t arg2) {
	if (!UseLiftedCode(62, 0x828C24A0)) { ctx.r3.u64 = holder; ctx.r4.u64 = arg2; __imp__sub_828C24A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828C24A0);
	uint32_t stack = ctx.r1.u64;
	C_820055C8* c = GameObject<C_820055C8>(base, holder);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	uint64_t allocation = operator_new(ctx, base, 132);
	uint64_t newObject = 0;
	if ((uint32_t)allocation != 0) {
		newObject = n_sub_828C2518(ctx, base, allocation, arg2);
	}
	C_820F1270_Clone(ctx, base, holder, newObject);
	uint32_t heldObject = c->vtable;
	if (heldObject != 0) {
		Vector_Clear12(ctx, base, heldObject);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return holder;
}
PROMOTED_ENTRY(62, sub_828C24A0, 0x828C24A0) { ctx.r3.u64 = n_sub_828C24A0(ctx, base, ctx.r3.u64, ctx.r4.u64); }
