// C_820CBD08 (vtable 0x820CBD08): methods of the class as readable C++.
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

// sub_826A54F0  [100 bytes]
uint64_t C_820CBD6C_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t flags) {
	if (!UseLiftedCode(44, 0x826A54F0)) { ctx.r3.u64 = object; ctx.r4.u64 = flags; __imp__sub_826A54F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826A54F0);
	// Deleting destructor: releases the shared handles at +248 and +240, runs n_sub_8248F828 on the object, and
	// frees the object when bit 0 of flags (the delete flag) is set.
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flags;
	SharedHandle_Release(ctx, base, object + 248);
	SharedHandle_Release(ctx, base, object + 240);
	n_sub_8248F828(ctx, base, object);
	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(44, sub_826A54F0, 0x826A54F0) { ctx.r3.u64 = C_820CBD6C_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
