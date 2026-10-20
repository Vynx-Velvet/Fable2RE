// C_8200B3D4 (vtable 0x8200B3D4): methods of the class as readable C++.
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

uint64_t Speech_GetWaveforms(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D38_G_ = int32_t(0x83334D38);
	if (!UseLiftedCode(90, 0x82C1E350)) { __imp__sub_82C1E350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C1E350);
	return TXT_83334D38_G_;
}
PROMOTED_ENTRY(90, sub_82C1E350, 0x82C1E350) { ctx.r3.u64 = Speech_GetWaveforms(ctx, base); }
