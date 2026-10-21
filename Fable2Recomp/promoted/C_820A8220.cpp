// C_820A8220 (vtable 0x820A8220): methods of the class as readable C++.
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

// sub_8237D750  [148 bytes]
// Makes a heap copy of the 8-byte object at source (the base vtable, the source's +4 word, then the
// object's own vtable) and stores it into the shared pointer at +0 with a new control block; when the
// allocation fails, both words of the shared pointer are cleared.
uint64_t C_820A8220_AssignCopy(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t source) {
	constexpr int32_t g_820A8220 = int32_t(0x820A8220);
	if (!UseLiftedCode(18, 0x8237D750)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = source; __imp__sub_8237D750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8237D750);
	uint32_t stack = ctx.r1.u64;
	C_820A8220* c = GameObject<C_820A8220>(base, cAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = source;
	uint32_t copy = operator_new(ctx, base, 8);
	uint64_t vtable = 0;
	if (copy != 0) {
		vtable = g_820A8220;
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
PROMOTED_ENTRY(18, sub_8237D750, 0x8237D750) { ctx.r3.u64 = C_820A8220_AssignCopy(ctx, base, ctx.r3.u64, ctx.r4.u64); }
