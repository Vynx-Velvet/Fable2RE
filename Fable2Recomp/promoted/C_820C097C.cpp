// C_820C097C (vtable 0x820C097C): methods of the class as readable C++.
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

uint64_t n_sub_82584E08(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t source) {
	constexpr int32_t g_820C097C = int32_t(0x820C097C);
	if (!UseLiftedCode(35, 0x82584E08)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = source; __imp__sub_82584E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82584E08);
	uint32_t stack = ctx.r1.u64;
	C_820C097C* c = GameObject<C_820C097C>(base, cAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = source;
	uint32_t copy = operator_new(ctx, base, 8);
	uint64_t vtable = 0;
	if (copy != 0) {
		vtable = g_820C097C;
		STORE32(copy, 0x820A8208u);
		STORE32(copy + 4, LOAD32((uint32_t)source + 4));
		STORE32(copy, (uint32_t)vtable);
	}
	c->vtable = copy;
	if (copy != 0) {
		ctx.r8.u64 = vtable;
		SharedPtr_CreateControlBlock(ctx, base, cAddr);
	} else {
		c->m_4 = 0u;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return cAddr;
}
PROMOTED_ENTRY(35, sub_82584E08, 0x82584E08) { ctx.r3.u64 = n_sub_82584E08(ctx, base, ctx.r3.u64, ctx.r4.u64); }
