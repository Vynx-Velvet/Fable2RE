// C_8200BA44 (vtable 0x8200BA44): methods of the class as readable C++.
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

uint64_t GetSimpleVariations(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D70_G_ = int32_t(0x83334D70);
	if (!UseLiftedCode(90, 0x82C27FA0)) { __imp__sub_82C27FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C27FA0);
	return TXT_83334D70_G_;
}
PROMOTED_ENTRY(90, sub_82C27FA0, 0x82C27FA0) { ctx.r3.u64 = GetSimpleVariations(ctx, base); }
