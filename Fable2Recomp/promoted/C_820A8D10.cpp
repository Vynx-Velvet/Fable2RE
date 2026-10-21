// C_820A8D10 (vtable 0x820A8D10): methods of the class as readable C++.
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

// sub_8250B7D0  [96 bytes]
// Deleting destructor: releases the string at +32, stores the base-class vtable and frees the
// object when bit 0 of the delete flags is set.
uint64_t n_sub_8250B7D0(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(31, 0x8250B7D0)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_8250B7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8250B7D0);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, object + 32);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(31, sub_8250B7D0, 0x8250B7D0) { ctx.r3.u64 = n_sub_8250B7D0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8264BBD0(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(41, 0x8264BBD0)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_8264BBD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8264BBD0);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	PtrVector8_ClearAndFree(ctx, base, object + 12);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(41, sub_8264BBD0, 0x8264BBD0) { ctx.r3.u64 = n_sub_8264BBD0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8287C8A0(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(60, 0x8287C8A0)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_8287C8A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8287C8A0);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	HandleList_Clear_82799248(ctx, base, object + 40);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(60, sub_8287C8A0, 0x8287C8A0) { ctx.r3.u64 = n_sub_8287C8A0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_829400E0(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(66, 0x829400E0)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_829400E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829400E0);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, object + 16);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(66, sub_829400E0, 0x829400E0) { ctx.r3.u64 = n_sub_829400E0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82956590(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(67, 0x82956590)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_82956590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82956590);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	SharedHandle_Release(ctx, base, object + 12);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(67, sub_82956590, 0x82956590) { ctx.r3.u64 = n_sub_82956590(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82966500(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(67, 0x82966500)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_82966500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82966500);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	SharedHandle_Release(ctx, base, object + 72);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(67, sub_82966500, 0x82966500) { ctx.r3.u64 = n_sub_82966500(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8297FA70(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(68, 0x8297FA70)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_8297FA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297FA70);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, object + 28);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(68, sub_8297FA70, 0x8297FA70) { ctx.r3.u64 = n_sub_8297FA70(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82981218(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(68, 0x82981218)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_82981218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82981218);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, object + 36);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(68, sub_82981218, 0x82981218) { ctx.r3.u64 = n_sub_82981218(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82982930(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(68, 0x82982930)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_82982930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82982930);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, object + 12);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(68, sub_82982930, 0x82982930) { ctx.r3.u64 = n_sub_82982930(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8299C1D8(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(69, 0x8299C1D8)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_8299C1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C1D8);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	SharedHandle_Release(ctx, base, object + 16);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(69, sub_8299C1D8, 0x8299C1D8) { ctx.r3.u64 = n_sub_8299C1D8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8299C928(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(69, 0x8299C928)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_8299C928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C928);
	uint32_t stack = ctx.r1.u64;
	C_820A8D10* c = GameObject<C_820A8D10>(base, object);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	SharedHandle_Release(ctx, base, object + 108);
	c->vtable = 0x820A8D10u;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(69, sub_8299C928, 0x8299C928) { ctx.r3.u64 = n_sub_8299C928(ctx, base, ctx.r3.u64, ctx.r4.u64); }
