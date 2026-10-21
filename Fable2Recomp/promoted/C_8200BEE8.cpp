// C_8200BEE8 (vtable 0x8200BEE8): methods of the class as readable C++.
//
// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md).Each function was written
// by a language model from the lifter's exact code for the user's own copy and accepted by the differential
// checker on input profiles 0-5 (tools/rewrite/check.py --outputs).Review and game-check status per function:
// REVIEW.tsv in this directory and docs/status.md.A function keeps the address of the original
// (PROMOTED_ENTRY) and its fallback to the recompiled original (UseLiftedCode).
// Layouts and declarations come from the lifter, generated locally (lifted/classes.h, native_decls.h).
#include "lifted/lifted.h"
#include "lifted/classes.h"
#include "lifted/native_decls.h"

uint64_t GetChannelMachine(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DAC_G_ = int32_t(0x83334DAC);
	if (!UseLiftedCode(90, 0x82C30630)) { __imp__sub_82C30630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C30630);
	return TXT_83334DAC_G_;
}
PROMOTED_ENTRY(90, sub_82C30630, 0x82C30630) { ctx.r3.u64 = GetChannelMachine(ctx, base); }

uint64_t n_sub_82C30958(CpuState& ctx, uint8_t* base, uint64_t object) {
	constexpr int32_t g_83330000 = int32_t(0x83330000);
	if (!UseLiftedCode(90, 0x82C30958)) { ctx.r4.u64 = object; __imp__sub_82C30958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C30958);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t vtable = LOAD32((uint32_t)object);
	uint64_t globalAddress = (int64_t)g_83330000 + 19876;
	uint32_t method = LOAD32(vtable + 4);
	PPCRegister callTarget{};
	callTarget.u64 = method;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = object;
	ctx.r4.u64 = globalAddress;
	ctx.r9.u64 = method;
	ctx.r10.s64 = g_83330000;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;
	if ((uint32_t)result != 0) {
		result = LOAD32((uint32_t)result + 12);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C30958, 0x82C30958) { ctx.r3.u64 = n_sub_82C30958(ctx, base, ctx.r4.u64); }
