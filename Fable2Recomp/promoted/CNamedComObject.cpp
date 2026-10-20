// CNamedComObject (vtable 0x8200E374): methods of the class as readable C++.
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

uint64_t CNamedComObject_GetValue(CpuState& ctx, uint8_t* base, uint32_t namedComObjectAddr, uint32_t outValue) {
	if (!UseLiftedCode(92, 0x82C78E48)) { ctx.r3.u64 = namedComObjectAddr; ctx.r4.u64 = outValue; __imp__sub_82C78E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C78E48);
	uint32_t result{};
	uint32_t namedComObjectValue{};
	CNamedComObject* namedComObject = GameObject<CNamedComObject>(base, namedComObjectAddr);
	namedComObjectValue = namedComObject->m_value;
	result = 0;
	STORE32(outValue, namedComObjectValue);
	return result;
}
PROMOTED_ENTRY(92, sub_82C78E48, 0x82C78E48) { ctx.r3.u64 = CNamedComObject_GetValue(ctx, base, ctx.r3.u32, ctx.r4.u32); }
