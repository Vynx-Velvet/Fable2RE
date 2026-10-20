// hkpListShape (vtable 0x82002180): methods of the class as readable C++.
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

uint64_t hkpListShape_IsChildEnabled(CpuState& ctx, uint8_t* base, uint32_t listShape, uint32_t childIndex) {
	if (!UseLiftedCode(9, 0x82269880)) { ctx.r3.u64 = listShape; ctx.r4.u64 = childIndex; __imp__sub_82269880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82269880);
	uint64_t isEnabled{};
	uint32_t defaultEnabled{};
	uint64_t bitMask{};
	uint64_t wordValue{};
	if (childIndex < 256) {
		bitMask = childIndex & 0x1F;
		wordValue = childIndex >> 5;
		wordValue = (int64_t)wordValue + 16;
		wordValue = (uint32_t)wordValue << 2;
		wordValue = LOAD32((uint32_t)wordValue + listShape);
		bitMask = (uint8_t)bitMask & 0x20 ? 0 : 1u << ((uint8_t)bitMask & 0x3F);
		isEnabled = bitMask & wordValue;
		return isEnabled;
	}
	defaultEnabled = 1;
	return defaultEnabled;
}
PROMOTED_ENTRY(9, sub_82269880, 0x82269880) { ctx.r3.u64 = hkpListShape_IsChildEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }
