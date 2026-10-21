// C_8200BAF0 (vtable 0x8200BAF0): methods of the class as readable C++.
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

uint64_t SequenceEntries_Get(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D78_G_ = int32_t(0x83334D78);
	if (!UseLiftedCode(90, 0x82C29540)) { __imp__sub_82C29540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C29540);
	return TXT_83334D78_G_;
}
PROMOTED_ENTRY(90, sub_82C29540, 0x82C29540) { ctx.r3.u64 = SequenceEntries_Get(ctx, base); }

uint64_t C_8200BAF0_Constructor(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(90, 0x82C2A388)) { ctx.r3.u64 = object; ctx.r4.u64 = arg2; ctx.r6.u64 = arg3; __imp__sub_82C2A388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C2A388);
	return C_8200BAF0_BaseConstructor(ctx, base, arg2, (int64_t)object + 4, arg3);
}
PROMOTED_ENTRY(90, sub_82C2A388, 0x82C2A388) { ctx.r3.u64 = C_8200BAF0_Constructor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }
