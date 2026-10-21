// C_8200BB18 (vtable 0x8200BB18): methods of the class as readable C++.
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

uint64_t C_8200BB18_ForEach(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t argument) {
	if (!UseLiftedCode(90, 0x82C29BB0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = argument; __imp__sub_82C29BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C29BB0);
	return List_ForEachWithArgument(ctx, base, arg1 + 16, argument);
}
PROMOTED_ENTRY(90, sub_82C29BB0, 0x82C29BB0) { ctx.r3.u64 = C_8200BB18_ForEach(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C29BC0(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C29BC0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C29BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C29BC0);
	return n_sub_82C50458(ctx, base, arg1 + 16, arg2);
}
PROMOTED_ENTRY(90, sub_82C29BC0, 0x82C29BC0) { ctx.r3.u64 = n_sub_82C29BC0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C29BC8(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C29BC8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C29BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C29BC8);
	return n_sub_82C50798(ctx, base, arg1 + 16, arg2);
}
PROMOTED_ENTRY(90, sub_82C29BC8, 0x82C29BC8) { ctx.r3.u64 = n_sub_82C29BC8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C2E2C8(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C2E2C8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C2E2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C2E2C8);
	return n_sub_82C4FC00(ctx, base, arg1 + 16, arg2);
}
PROMOTED_ENTRY(90, sub_82C2E2C8, 0x82C2E2C8) { ctx.r3.u64 = n_sub_82C2E2C8(ctx, base, ctx.r3.u64, ctx.r4.u64); }
