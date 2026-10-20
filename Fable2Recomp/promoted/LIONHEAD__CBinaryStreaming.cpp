// LIONHEAD__CBinaryStreaming (vtable 0x8200E69C): methods of the class as readable C++.
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

uint64_t LIONHEAD__CBinaryStreaming_GetBufferData(CpuState& ctx, uint8_t* base, uint64_t stream) {
	if (!UseLiftedCode(93, 0x82C81010)) { ctx.r3.u64 = stream; __imp__sub_82C81010(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C81010);
	uint64_t buffer{};
	stream = (int64_t)stream + 4;
	buffer = CBinaryStreaming_GetBuffer(ctx, base, stream);
	return buffer;
}
PROMOTED_ENTRY(93, sub_82C81010, 0x82C81010) { ctx.r3.u64 = LIONHEAD__CBinaryStreaming_GetBufferData(ctx, base, ctx.r3.u64); }
