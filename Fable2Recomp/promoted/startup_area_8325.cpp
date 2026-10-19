// Start-up initialisers of global objects (they register property and definition names) at
// 0x8325xxxx, as readable C++.
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

uint64_t n_sub_83250030(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985C4_G_ = int32_t(0x834985C4);
	if (!UseLiftedCode(143, 0x83250030)) { __imp__sub_83250030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250030);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C4_G_, (int64_t)str_TXT_820C0000_B_ - 11708, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250030, 0x83250030) { ctx.r3.u64 = n_sub_83250030(ctx, base); }

uint64_t n_sub_83250070(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985C8_G_ = int32_t(0x834985C8);
	if (!UseLiftedCode(143, 0x83250070)) { __imp__sub_83250070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250070);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C8_G_, (int64_t)str_TXT_820B0000_B_ - 28788, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250070, 0x83250070) { ctx.r3.u64 = n_sub_83250070(ctx, base); }

uint64_t n_sub_832500B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985CC_G_ = int32_t(0x834985CC);
	if (!UseLiftedCode(143, 0x832500B0)) { __imp__sub_832500B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832500B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985CC_G_, (int64_t)str_TXT_820B0000_B_ - 28780, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832500B0, 0x832500B0) { ctx.r3.u64 = n_sub_832500B0(ctx, base); }

uint64_t n_sub_832500F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985D0_G_ = int32_t(0x834985D0);
	if (!UseLiftedCode(143, 0x832500F0)) { __imp__sub_832500F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832500F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985D0_G_, (int64_t)str_TXT_820C0000_B_ - 11700, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832500F0, 0x832500F0) { ctx.r3.u64 = n_sub_832500F0(ctx, base); }

uint64_t n_sub_83250130(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985D4_G_ = int32_t(0x834985D4);
	if (!UseLiftedCode(143, 0x83250130)) { __imp__sub_83250130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250130);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985D4_G_, (int64_t)str_TXT_820C0000_B_ - 9868, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250130, 0x83250130) { ctx.r3.u64 = n_sub_83250130(ctx, base); }

uint64_t n_sub_83250170(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985D8_G_ = int32_t(0x834985D8);
	if (!UseLiftedCode(143, 0x83250170)) { __imp__sub_83250170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250170);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985D8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250170, 0x83250170) { ctx.r3.u64 = n_sub_83250170(ctx, base); }

uint64_t n_sub_832501B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985DC_G_ = int32_t(0x834985DC);
	if (!UseLiftedCode(143, 0x832501B0)) { __imp__sub_832501B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832501B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985DC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832501B0, 0x832501B0) { ctx.r3.u64 = n_sub_832501B0(ctx, base); }

uint64_t n_sub_832501F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985E0_G_ = int32_t(0x834985E0);
	if (!UseLiftedCode(143, 0x832501F0)) { __imp__sub_832501F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832501F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985E0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832501F0, 0x832501F0) { ctx.r3.u64 = n_sub_832501F0(ctx, base); }

uint64_t n_sub_83250230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985E4_G_ = int32_t(0x834985E4);
	if (!UseLiftedCode(143, 0x83250230)) { __imp__sub_83250230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985E4_G_, (int64_t)str_TXT_820C0000_B_ - 9012, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250230, 0x83250230) { ctx.r3.u64 = n_sub_83250230(ctx, base); }

uint64_t n_sub_83250270(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985E8_G_ = int32_t(0x834985E8);
	if (!UseLiftedCode(143, 0x83250270)) { __imp__sub_83250270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250270);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985E8_G_, (int64_t)str_TXT_820C0000_B_ - 9004, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250270, 0x83250270) { ctx.r3.u64 = n_sub_83250270(ctx, base); }

uint64_t n_sub_832502B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985EC_G_ = int32_t(0x834985EC);
	if (!UseLiftedCode(143, 0x832502B0)) { __imp__sub_832502B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832502B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985EC_G_, (int64_t)str_TXT_820C0000_B_ - 8996, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832502B0, 0x832502B0) { ctx.r3.u64 = n_sub_832502B0(ctx, base); }

uint64_t n_sub_832502F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985F0_G_ = int32_t(0x834985F0);
	if (!UseLiftedCode(143, 0x832502F0)) { __imp__sub_832502F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832502F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985F0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832502F0, 0x832502F0) { ctx.r3.u64 = n_sub_832502F0(ctx, base); }

uint64_t n_sub_83250330(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985F4_G_ = int32_t(0x834985F4);
	if (!UseLiftedCode(143, 0x83250330)) { __imp__sub_83250330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250330);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985F4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250330, 0x83250330) { ctx.r3.u64 = n_sub_83250330(ctx, base); }

uint64_t n_sub_83250370(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985F8_G_ = int32_t(0x834985F8);
	if (!UseLiftedCode(143, 0x83250370)) { __imp__sub_83250370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250370);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985F8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250370, 0x83250370) { ctx.r3.u64 = n_sub_83250370(ctx, base); }

uint64_t n_sub_832503B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985FC_G_ = int32_t(0x834985FC);
	if (!UseLiftedCode(143, 0x832503B0)) { __imp__sub_832503B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832503B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985FC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832503B0, 0x832503B0) { ctx.r3.u64 = n_sub_832503B0(ctx, base); }

uint64_t n_sub_832503F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498600_G_ = int32_t(0x83498600);
	if (!UseLiftedCode(143, 0x832503F0)) { __imp__sub_832503F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832503F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498600_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832503F0, 0x832503F0) { ctx.r3.u64 = n_sub_832503F0(ctx, base); }

uint64_t n_sub_83250430(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498604_G_ = int32_t(0x83498604);
	if (!UseLiftedCode(143, 0x83250430)) { __imp__sub_83250430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250430);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498604_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250430, 0x83250430) { ctx.r3.u64 = n_sub_83250430(ctx, base); }

uint64_t n_sub_83250470(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498608_G_ = int32_t(0x83498608);
	if (!UseLiftedCode(143, 0x83250470)) { __imp__sub_83250470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250470);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498608_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250470, 0x83250470) { ctx.r3.u64 = n_sub_83250470(ctx, base); }

uint64_t n_sub_832504B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349860C_G_ = int32_t(0x8349860C);
	if (!UseLiftedCode(143, 0x832504B0)) { __imp__sub_832504B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832504B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349860C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832504B0, 0x832504B0) { ctx.r3.u64 = n_sub_832504B0(ctx, base); }

uint64_t n_sub_832504F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498610_G_ = int32_t(0x83498610);
	if (!UseLiftedCode(143, 0x832504F0)) { __imp__sub_832504F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832504F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498610_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832504F0, 0x832504F0) { ctx.r3.u64 = n_sub_832504F0(ctx, base); }

uint64_t n_sub_83250530(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_83498614 = int32_t(0x83498614);
	if (!UseLiftedCode(143, 0x83250530)) { __imp__sub_83250530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250530);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_83498614, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250530, 0x83250530) { ctx.r3.u64 = n_sub_83250530(ctx, base); }

uint64_t n_sub_832505A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498624_G_ = int32_t(0x83498624);
	if (!UseLiftedCode(143, 0x832505A8)) { __imp__sub_832505A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832505A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498624_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832505A8, 0x832505A8) { ctx.r3.u64 = n_sub_832505A8(ctx, base); }

uint64_t n_sub_832505E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498628_G_ = int32_t(0x83498628);
	if (!UseLiftedCode(143, 0x832505E8)) { __imp__sub_832505E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832505E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498628_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832505E8, 0x832505E8) { ctx.r3.u64 = n_sub_832505E8(ctx, base); }

uint64_t n_sub_83250628(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349862C_G_ = int32_t(0x8349862C);
	if (!UseLiftedCode(143, 0x83250628)) { __imp__sub_83250628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250628);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349862C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250628, 0x83250628) { ctx.r3.u64 = n_sub_83250628(ctx, base); }

uint64_t n_sub_832507B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498648_G_ = int32_t(0x83498648);
	if (!UseLiftedCode(143, 0x832507B8)) { __imp__sub_832507B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832507B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498648_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832507B8, 0x832507B8) { ctx.r3.u64 = n_sub_832507B8(ctx, base); }

uint64_t n_sub_832507F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349864C_G_ = int32_t(0x8349864C);
	if (!UseLiftedCode(143, 0x832507F8)) { __imp__sub_832507F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832507F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349864C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832507F8, 0x832507F8) { ctx.r3.u64 = n_sub_832507F8(ctx, base); }

uint64_t n_sub_83250838(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498650_G_ = int32_t(0x83498650);
	if (!UseLiftedCode(143, 0x83250838)) { __imp__sub_83250838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250838);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498650_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250838, 0x83250838) { ctx.r3.u64 = n_sub_83250838(ctx, base); }

uint64_t n_sub_83250888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986A0_G_ = int32_t(0x834986A0);
	if (!UseLiftedCode(143, 0x83250888)) { __imp__sub_83250888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986A0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250888, 0x83250888) { ctx.r3.u64 = n_sub_83250888(ctx, base); }

uint64_t n_sub_832508C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986A4_G_ = int32_t(0x834986A4);
	if (!UseLiftedCode(143, 0x832508C8)) { __imp__sub_832508C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832508C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986A4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832508C8, 0x832508C8) { ctx.r3.u64 = n_sub_832508C8(ctx, base); }

uint64_t n_sub_83250908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986A8_G_ = int32_t(0x834986A8);
	if (!UseLiftedCode(143, 0x83250908)) { __imp__sub_83250908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986A8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250908, 0x83250908) { ctx.r3.u64 = n_sub_83250908(ctx, base); }

uint64_t n_sub_83250948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986AC_G_ = int32_t(0x834986AC);
	if (!UseLiftedCode(143, 0x83250948)) { __imp__sub_83250948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986AC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250948, 0x83250948) { ctx.r3.u64 = n_sub_83250948(ctx, base); }

uint64_t n_sub_83250988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986B0_G_ = int32_t(0x834986B0);
	if (!UseLiftedCode(143, 0x83250988)) { __imp__sub_83250988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986B0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250988, 0x83250988) { ctx.r3.u64 = n_sub_83250988(ctx, base); }

uint64_t n_sub_832509C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986B4_G_ = int32_t(0x834986B4);
	if (!UseLiftedCode(143, 0x832509C8)) { __imp__sub_832509C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832509C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986B4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832509C8, 0x832509C8) { ctx.r3.u64 = n_sub_832509C8(ctx, base); }

uint64_t n_sub_83250B90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986D4_G_ = int32_t(0x834986D4);
	if (!UseLiftedCode(143, 0x83250B90)) { __imp__sub_83250B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250B90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986D4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250B90, 0x83250B90) { ctx.r3.u64 = n_sub_83250B90(ctx, base); }

uint64_t n_sub_83250BD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986D8_G_ = int32_t(0x834986D8);
	if (!UseLiftedCode(143, 0x83250BD0)) { __imp__sub_83250BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250BD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986D8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250BD0, 0x83250BD0) { ctx.r3.u64 = n_sub_83250BD0(ctx, base); }

uint64_t n_sub_83250C10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986DC_G_ = int32_t(0x834986DC);
	if (!UseLiftedCode(143, 0x83250C10)) { __imp__sub_83250C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250C10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986DC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250C10, 0x83250C10) { ctx.r3.u64 = n_sub_83250C10(ctx, base); }

uint64_t n_sub_83250C50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986E0_G_ = int32_t(0x834986E0);
	if (!UseLiftedCode(143, 0x83250C50)) { __imp__sub_83250C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250C50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986E0_G_, (int64_t)str_TXT_820C0000_B_ - 4292, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250C50, 0x83250C50) { ctx.r3.u64 = n_sub_83250C50(ctx, base); }

uint64_t n_sub_83250C90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986E4_G_ = int32_t(0x834986E4);
	if (!UseLiftedCode(143, 0x83250C90)) { __imp__sub_83250C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250C90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986E4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250C90, 0x83250C90) { ctx.r3.u64 = n_sub_83250C90(ctx, base); }

uint64_t n_sub_83250CD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986E8_G_ = int32_t(0x834986E8);
	if (!UseLiftedCode(143, 0x83250CD0)) { __imp__sub_83250CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250CD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986E8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250CD0, 0x83250CD0) { ctx.r3.u64 = n_sub_83250CD0(ctx, base); }

uint64_t n_sub_83250D10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986EC_G_ = int32_t(0x834986EC);
	if (!UseLiftedCode(143, 0x83250D10)) { __imp__sub_83250D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250D10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986EC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250D10, 0x83250D10) { ctx.r3.u64 = n_sub_83250D10(ctx, base); }

uint64_t n_sub_83250D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986F4_G_ = int32_t(0x834986F4);
	if (!UseLiftedCode(143, 0x83250D88)) { __imp__sub_83250D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986F4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250D88, 0x83250D88) { ctx.r3.u64 = n_sub_83250D88(ctx, base); }

uint64_t n_sub_83250DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986F8_G_ = int32_t(0x834986F8);
	if (!UseLiftedCode(143, 0x83250DC8)) { __imp__sub_83250DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986F8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250DC8, 0x83250DC8) { ctx.r3.u64 = n_sub_83250DC8(ctx, base); }

uint64_t n_sub_83250E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834986FC_G_ = int32_t(0x834986FC);
	if (!UseLiftedCode(143, 0x83250E08)) { __imp__sub_83250E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834986FC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250E08, 0x83250E08) { ctx.r3.u64 = n_sub_83250E08(ctx, base); }

uint64_t n_sub_83250E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_83498700 = int32_t(0x83498700);
	if (!UseLiftedCode(143, 0x83250E48)) { __imp__sub_83250E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, g_83498700, (int64_t)str_TXT_820B0000_B_ + 11652, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250E48, 0x83250E48) { ctx.r3.u64 = n_sub_83250E48(ctx, base); }

uint64_t n_sub_83250E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_83498704 = int32_t(0x83498704);
	if (!UseLiftedCode(143, 0x83250E88)) { __imp__sub_83250E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, g_83498704, (int64_t)str_TXT_820B0000_B_ + 11656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250E88, 0x83250E88) { ctx.r3.u64 = n_sub_83250E88(ctx, base); }

uint64_t n_sub_83250EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498708_G_ = int32_t(0x83498708);
	if (!UseLiftedCode(143, 0x83250EC8)) { __imp__sub_83250EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250EC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498708_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250EC8, 0x83250EC8) { ctx.r3.u64 = n_sub_83250EC8(ctx, base); }

uint64_t n_sub_83250F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349870C_G_ = int32_t(0x8349870C);
	if (!UseLiftedCode(143, 0x83250F08)) { __imp__sub_83250F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349870C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250F08, 0x83250F08) { ctx.r3.u64 = n_sub_83250F08(ctx, base); }

uint64_t n_sub_83250F48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498710_G_ = int32_t(0x83498710);
	if (!UseLiftedCode(143, 0x83250F48)) { __imp__sub_83250F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250F48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498710_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250F48, 0x83250F48) { ctx.r3.u64 = n_sub_83250F48(ctx, base); }

uint64_t n_sub_83250F88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498714_G_ = int32_t(0x83498714);
	if (!UseLiftedCode(143, 0x83250F88)) { __imp__sub_83250F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250F88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498714_G_, (int64_t)str_TXT_820C0000_B_ - 2400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250F88, 0x83250F88) { ctx.r3.u64 = n_sub_83250F88(ctx, base); }

uint64_t n_sub_83250FC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498718_G_ = int32_t(0x83498718);
	if (!UseLiftedCode(143, 0x83250FC8)) { __imp__sub_83250FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250FC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498718_G_, (int64_t)str_TXT_820C0000_B_ - 2376, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83250FC8, 0x83250FC8) { ctx.r3.u64 = n_sub_83250FC8(ctx, base); }

uint64_t n_sub_83251008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349871C_G_ = int32_t(0x8349871C);
	if (!UseLiftedCode(143, 0x83251008)) { __imp__sub_83251008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349871C_G_, (int64_t)str_TXT_820C0000_B_ - 2352, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251008, 0x83251008) { ctx.r3.u64 = n_sub_83251008(ctx, base); }

uint64_t n_sub_83251048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498720_G_ = int32_t(0x83498720);
	if (!UseLiftedCode(143, 0x83251048)) { __imp__sub_83251048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498720_G_, (int64_t)str_TXT_820C0000_B_ - 2328, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251048, 0x83251048) { ctx.r3.u64 = n_sub_83251048(ctx, base); }

uint64_t n_sub_83251088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498724_G_ = int32_t(0x83498724);
	if (!UseLiftedCode(143, 0x83251088)) { __imp__sub_83251088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498724_G_, (int64_t)str_TXT_820C0000_B_ - 2304, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251088, 0x83251088) { ctx.r3.u64 = n_sub_83251088(ctx, base); }

uint64_t n_sub_832510C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498728_G_ = int32_t(0x83498728);
	if (!UseLiftedCode(143, 0x832510C8)) { __imp__sub_832510C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832510C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498728_G_, (int64_t)str_TXT_820C0000_B_ - 2284, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832510C8, 0x832510C8) { ctx.r3.u64 = n_sub_832510C8(ctx, base); }

uint64_t n_sub_83251108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349872C_G_ = int32_t(0x8349872C);
	if (!UseLiftedCode(143, 0x83251108)) { __imp__sub_83251108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349872C_G_, (int64_t)str_TXT_820C0000_B_ - 2264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251108, 0x83251108) { ctx.r3.u64 = n_sub_83251108(ctx, base); }

uint64_t n_sub_83251148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498730_G_ = int32_t(0x83498730);
	if (!UseLiftedCode(143, 0x83251148)) { __imp__sub_83251148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498730_G_, (int64_t)str_TXT_820C0000_B_ - 2248, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251148, 0x83251148) { ctx.r3.u64 = n_sub_83251148(ctx, base); }

uint64_t n_sub_83251188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498734_G_ = int32_t(0x83498734);
	if (!UseLiftedCode(143, 0x83251188)) { __imp__sub_83251188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498734_G_, (int64_t)str_TXT_820C0000_B_ - 2224, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251188, 0x83251188) { ctx.r3.u64 = n_sub_83251188(ctx, base); }

uint64_t n_sub_832511C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498738_G_ = int32_t(0x83498738);
	if (!UseLiftedCode(143, 0x832511C8)) { __imp__sub_832511C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832511C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498738_G_, (int64_t)str_TXT_820C0000_B_ - 2200, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832511C8, 0x832511C8) { ctx.r3.u64 = n_sub_832511C8(ctx, base); }

uint64_t n_sub_83251208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349873C_G_ = int32_t(0x8349873C);
	if (!UseLiftedCode(143, 0x83251208)) { __imp__sub_83251208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349873C_G_, (int64_t)str_TXT_820C0000_B_ - 2176, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251208, 0x83251208) { ctx.r3.u64 = n_sub_83251208(ctx, base); }

uint64_t n_sub_83251248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498740_G_ = int32_t(0x83498740);
	if (!UseLiftedCode(143, 0x83251248)) { __imp__sub_83251248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251248);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498740_G_, (int64_t)str_TXT_820C0000_B_ - 2156, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251248, 0x83251248) { ctx.r3.u64 = n_sub_83251248(ctx, base); }

uint64_t n_sub_83251288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498744_G_ = int32_t(0x83498744);
	if (!UseLiftedCode(143, 0x83251288)) { __imp__sub_83251288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498744_G_, (int64_t)str_TXT_820C0000_B_ - 2128, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251288, 0x83251288) { ctx.r3.u64 = n_sub_83251288(ctx, base); }

uint64_t n_sub_832512C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498748_G_ = int32_t(0x83498748);
	if (!UseLiftedCode(143, 0x832512C8)) { __imp__sub_832512C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832512C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498748_G_, (int64_t)str_TXT_820C0000_B_ - 2104, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832512C8, 0x832512C8) { ctx.r3.u64 = n_sub_832512C8(ctx, base); }

uint64_t n_sub_83251308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349874C_G_ = int32_t(0x8349874C);
	if (!UseLiftedCode(143, 0x83251308)) { __imp__sub_83251308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349874C_G_, (int64_t)str_TXT_820C0000_B_ - 2084, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251308, 0x83251308) { ctx.r3.u64 = n_sub_83251308(ctx, base); }

uint64_t n_sub_83251348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498750_G_ = int32_t(0x83498750);
	if (!UseLiftedCode(143, 0x83251348)) { __imp__sub_83251348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498750_G_, (int64_t)str_TXT_820C0000_B_ - 2064, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251348, 0x83251348) { ctx.r3.u64 = n_sub_83251348(ctx, base); }

uint64_t n_sub_83251388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498754_G_ = int32_t(0x83498754);
	if (!UseLiftedCode(143, 0x83251388)) { __imp__sub_83251388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498754_G_, (int64_t)str_TXT_820C0000_B_ - 2044, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251388, 0x83251388) { ctx.r3.u64 = n_sub_83251388(ctx, base); }

uint64_t n_sub_832513C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498758_G_ = int32_t(0x83498758);
	if (!UseLiftedCode(143, 0x832513C8)) { __imp__sub_832513C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832513C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498758_G_, (int64_t)str_TXT_820C0000_B_ - 2024, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832513C8, 0x832513C8) { ctx.r3.u64 = n_sub_832513C8(ctx, base); }

uint64_t n_sub_83251408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349875C_G_ = int32_t(0x8349875C);
	if (!UseLiftedCode(143, 0x83251408)) { __imp__sub_83251408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349875C_G_, (int64_t)str_TXT_820C0000_B_ - 2008, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251408, 0x83251408) { ctx.r3.u64 = n_sub_83251408(ctx, base); }

uint64_t n_sub_83251448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498760_G_ = int32_t(0x83498760);
	if (!UseLiftedCode(143, 0x83251448)) { __imp__sub_83251448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498760_G_, (int64_t)str_TXT_820C0000_B_ - 1992, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251448, 0x83251448) { ctx.r3.u64 = n_sub_83251448(ctx, base); }

uint64_t n_sub_83251488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498764_G_ = int32_t(0x83498764);
	if (!UseLiftedCode(143, 0x83251488)) { __imp__sub_83251488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498764_G_, (int64_t)str_TXT_820C0000_B_ - 1972, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251488, 0x83251488) { ctx.r3.u64 = n_sub_83251488(ctx, base); }

uint64_t n_sub_832514C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498768_G_ = int32_t(0x83498768);
	if (!UseLiftedCode(143, 0x832514C8)) { __imp__sub_832514C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832514C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498768_G_, (int64_t)str_TXT_820C0000_B_ - 1940, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832514C8, 0x832514C8) { ctx.r3.u64 = n_sub_832514C8(ctx, base); }

uint64_t n_sub_83251508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349876C_G_ = int32_t(0x8349876C);
	if (!UseLiftedCode(143, 0x83251508)) { __imp__sub_83251508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349876C_G_, (int64_t)str_TXT_820C0000_B_ - 1920, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251508, 0x83251508) { ctx.r3.u64 = n_sub_83251508(ctx, base); }

uint64_t n_sub_83251548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498770_G_ = int32_t(0x83498770);
	if (!UseLiftedCode(143, 0x83251548)) { __imp__sub_83251548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498770_G_, (int64_t)str_TXT_820C0000_B_ - 1900, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251548, 0x83251548) { ctx.r3.u64 = n_sub_83251548(ctx, base); }

uint64_t n_sub_83251588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498774_G_ = int32_t(0x83498774);
	if (!UseLiftedCode(143, 0x83251588)) { __imp__sub_83251588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498774_G_, (int64_t)str_TXT_820C0000_B_ - 1876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251588, 0x83251588) { ctx.r3.u64 = n_sub_83251588(ctx, base); }

uint64_t n_sub_832515C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498778_G_ = int32_t(0x83498778);
	if (!UseLiftedCode(143, 0x832515C8)) { __imp__sub_832515C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832515C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498778_G_, (int64_t)str_TXT_820C0000_B_ - 1900, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832515C8, 0x832515C8) { ctx.r3.u64 = n_sub_832515C8(ctx, base); }

uint64_t n_sub_83251608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349877C_G_ = int32_t(0x8349877C);
	if (!UseLiftedCode(143, 0x83251608)) { __imp__sub_83251608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349877C_G_, (int64_t)str_TXT_820C0000_B_ - 1876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251608, 0x83251608) { ctx.r3.u64 = n_sub_83251608(ctx, base); }

uint64_t n_sub_83251648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498780_G_ = int32_t(0x83498780);
	if (!UseLiftedCode(143, 0x83251648)) { __imp__sub_83251648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251648);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498780_G_, (int64_t)str_TXT_820C0000_B_ - 2264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251648, 0x83251648) { ctx.r3.u64 = n_sub_83251648(ctx, base); }

uint64_t n_sub_83251688(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498784_G_ = int32_t(0x83498784);
	if (!UseLiftedCode(143, 0x83251688)) { __imp__sub_83251688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251688);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498784_G_, (int64_t)str_TXT_820C0000_B_ - 2248, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251688, 0x83251688) { ctx.r3.u64 = n_sub_83251688(ctx, base); }

uint64_t n_sub_832516C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498788_G_ = int32_t(0x83498788);
	if (!UseLiftedCode(143, 0x832516C8)) { __imp__sub_832516C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832516C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498788_G_, (int64_t)str_TXT_820C0000_B_ - 1852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832516C8, 0x832516C8) { ctx.r3.u64 = n_sub_832516C8(ctx, base); }

uint64_t n_sub_83251708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349878C_G_ = int32_t(0x8349878C);
	if (!UseLiftedCode(143, 0x83251708)) { __imp__sub_83251708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349878C_G_, (int64_t)str_TXT_820C0000_B_ - 1832, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251708, 0x83251708) { ctx.r3.u64 = n_sub_83251708(ctx, base); }

uint64_t n_sub_83251748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498790_G_ = int32_t(0x83498790);
	if (!UseLiftedCode(143, 0x83251748)) { __imp__sub_83251748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498790_G_, (int64_t)str_TXT_820C0000_B_ - 1808, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251748, 0x83251748) { ctx.r3.u64 = n_sub_83251748(ctx, base); }

uint64_t n_sub_83251788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498794_G_ = int32_t(0x83498794);
	if (!UseLiftedCode(143, 0x83251788)) { __imp__sub_83251788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498794_G_, (int64_t)str_TXT_820C0000_B_ - 1784, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251788, 0x83251788) { ctx.r3.u64 = n_sub_83251788(ctx, base); }

uint64_t n_sub_832517C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498798_G_ = int32_t(0x83498798);
	if (!UseLiftedCode(143, 0x832517C8)) { __imp__sub_832517C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832517C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498798_G_, (int64_t)str_TXT_820C0000_B_ - 1760, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832517C8, 0x832517C8) { ctx.r3.u64 = n_sub_832517C8(ctx, base); }

uint64_t n_sub_83251808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349879C_G_ = int32_t(0x8349879C);
	if (!UseLiftedCode(143, 0x83251808)) { __imp__sub_83251808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349879C_G_, (int64_t)str_TXT_820C0000_B_ - 1744, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251808, 0x83251808) { ctx.r3.u64 = n_sub_83251808(ctx, base); }

uint64_t n_sub_83251848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987A0_G_ = int32_t(0x834987A0);
	if (!UseLiftedCode(143, 0x83251848)) { __imp__sub_83251848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987A0_G_, (int64_t)str_TXT_820C0000_B_ - 1716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251848, 0x83251848) { ctx.r3.u64 = n_sub_83251848(ctx, base); }

uint64_t n_sub_83251888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987A4_G_ = int32_t(0x834987A4);
	if (!UseLiftedCode(143, 0x83251888)) { __imp__sub_83251888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987A4_G_, (int64_t)str_TXT_820C0000_B_ - 2264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251888, 0x83251888) { ctx.r3.u64 = n_sub_83251888(ctx, base); }

uint64_t n_sub_832518C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987A8_G_ = int32_t(0x834987A8);
	if (!UseLiftedCode(143, 0x832518C8)) { __imp__sub_832518C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832518C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987A8_G_, (int64_t)str_TXT_820C0000_B_ - 1688, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832518C8, 0x832518C8) { ctx.r3.u64 = n_sub_832518C8(ctx, base); }

uint64_t n_sub_83251908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987AC_G_ = int32_t(0x834987AC);
	if (!UseLiftedCode(143, 0x83251908)) { __imp__sub_83251908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987AC_G_, (int64_t)str_TXT_820C0000_B_ - 2248, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 13984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251908, 0x83251908) { ctx.r3.u64 = n_sub_83251908(ctx, base); }

uint64_t n_sub_83251948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987B0_G_ = int32_t(0x834987B0);
	if (!UseLiftedCode(143, 0x83251948)) { __imp__sub_83251948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987B0_G_, (int64_t)str_TXT_820C0000_B_ - 1660, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251948, 0x83251948) { ctx.r3.u64 = n_sub_83251948(ctx, base); }

uint64_t n_sub_83251988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987B4_G_ = int32_t(0x834987B4);
	if (!UseLiftedCode(143, 0x83251988)) { __imp__sub_83251988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987B4_G_, (int64_t)str_TXT_820C0000_B_ - 1624, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251988, 0x83251988) { ctx.r3.u64 = n_sub_83251988(ctx, base); }

uint64_t n_sub_832519C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987B8_G_ = int32_t(0x834987B8);
	if (!UseLiftedCode(143, 0x832519C8)) { __imp__sub_832519C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832519C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987B8_G_, (int64_t)str_TXT_820C0000_B_ - 1600, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832519C8, 0x832519C8) { ctx.r3.u64 = n_sub_832519C8(ctx, base); }

uint64_t n_sub_83251A08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987BC_G_ = int32_t(0x834987BC);
	if (!UseLiftedCode(143, 0x83251A08)) { __imp__sub_83251A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251A08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987BC_G_, (int64_t)str_TXT_820C0000_B_ - 1572, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251A08, 0x83251A08) { ctx.r3.u64 = n_sub_83251A08(ctx, base); }

uint64_t n_sub_83251A48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987C0_G_ = int32_t(0x834987C0);
	if (!UseLiftedCode(143, 0x83251A48)) { __imp__sub_83251A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251A48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987C0_G_, (int64_t)str_TXT_820C0000_B_ - 1540, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251A48, 0x83251A48) { ctx.r3.u64 = n_sub_83251A48(ctx, base); }

uint64_t n_sub_83251A88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987C4_G_ = int32_t(0x834987C4);
	if (!UseLiftedCode(143, 0x83251A88)) { __imp__sub_83251A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251A88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987C4_G_, (int64_t)str_TXT_820C0000_B_ - 1516, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251A88, 0x83251A88) { ctx.r3.u64 = n_sub_83251A88(ctx, base); }

uint64_t n_sub_83251AC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987C8_G_ = int32_t(0x834987C8);
	if (!UseLiftedCode(143, 0x83251AC8)) { __imp__sub_83251AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251AC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987C8_G_, (int64_t)str_TXT_820C0000_B_ - 1488, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251AC8, 0x83251AC8) { ctx.r3.u64 = n_sub_83251AC8(ctx, base); }

uint64_t n_sub_83251B08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987CC_G_ = int32_t(0x834987CC);
	if (!UseLiftedCode(143, 0x83251B08)) { __imp__sub_83251B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251B08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987CC_G_, (int64_t)str_TXT_820C0000_B_ - 1460, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251B08, 0x83251B08) { ctx.r3.u64 = n_sub_83251B08(ctx, base); }

uint64_t n_sub_83251B48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987D0_G_ = int32_t(0x834987D0);
	if (!UseLiftedCode(143, 0x83251B48)) { __imp__sub_83251B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251B48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987D0_G_, (int64_t)str_TXT_820C0000_B_ - 1428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251B48, 0x83251B48) { ctx.r3.u64 = n_sub_83251B48(ctx, base); }

uint64_t n_sub_83251B88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987D4_G_ = int32_t(0x834987D4);
	if (!UseLiftedCode(143, 0x83251B88)) { __imp__sub_83251B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251B88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987D4_G_, (int64_t)str_TXT_820C0000_B_ - 1400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251B88, 0x83251B88) { ctx.r3.u64 = n_sub_83251B88(ctx, base); }

uint64_t n_sub_83251BC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987D8_G_ = int32_t(0x834987D8);
	if (!UseLiftedCode(143, 0x83251BC8)) { __imp__sub_83251BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251BC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987D8_G_, (int64_t)str_TXT_820C0000_B_ - 1376, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251BC8, 0x83251BC8) { ctx.r3.u64 = n_sub_83251BC8(ctx, base); }

uint64_t n_sub_83251C08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987DC_G_ = int32_t(0x834987DC);
	if (!UseLiftedCode(143, 0x83251C08)) { __imp__sub_83251C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251C08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987DC_G_, (int64_t)str_TXT_820C0000_B_ - 1352, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251C08, 0x83251C08) { ctx.r3.u64 = n_sub_83251C08(ctx, base); }

uint64_t n_sub_83251C48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987E0_G_ = int32_t(0x834987E0);
	if (!UseLiftedCode(143, 0x83251C48)) { __imp__sub_83251C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251C48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987E0_G_, (int64_t)str_TXT_820C0000_B_ - 1328, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251C48, 0x83251C48) { ctx.r3.u64 = n_sub_83251C48(ctx, base); }

uint64_t n_sub_83251C88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987E4_G_ = int32_t(0x834987E4);
	if (!UseLiftedCode(143, 0x83251C88)) { __imp__sub_83251C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251C88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987E4_G_, (int64_t)str_TXT_820C0000_B_ - 2264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251C88, 0x83251C88) { ctx.r3.u64 = n_sub_83251C88(ctx, base); }

uint64_t n_sub_83251CC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987E8_G_ = int32_t(0x834987E8);
	if (!UseLiftedCode(143, 0x83251CC8)) { __imp__sub_83251CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251CC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987E8_G_, (int64_t)str_TXT_820C0000_B_ - 2248, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251CC8, 0x83251CC8) { ctx.r3.u64 = n_sub_83251CC8(ctx, base); }

uint64_t n_sub_83251D08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987EC_G_ = int32_t(0x834987EC);
	if (!UseLiftedCode(143, 0x83251D08)) { __imp__sub_83251D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251D08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987EC_G_, (int64_t)str_TXT_820C0000_B_ - 1292, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251D08, 0x83251D08) { ctx.r3.u64 = n_sub_83251D08(ctx, base); }

uint64_t n_sub_83251D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987F0_G_ = int32_t(0x834987F0);
	if (!UseLiftedCode(143, 0x83251D48)) { __imp__sub_83251D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251D48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987F0_G_, (int64_t)str_TXT_820C0000_B_ - 1260, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251D48, 0x83251D48) { ctx.r3.u64 = n_sub_83251D48(ctx, base); }

uint64_t n_sub_83251D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987F4_G_ = int32_t(0x834987F4);
	if (!UseLiftedCode(143, 0x83251D88)) { __imp__sub_83251D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987F4_G_, (int64_t)str_TXT_820C0000_B_ - 1228, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251D88, 0x83251D88) { ctx.r3.u64 = n_sub_83251D88(ctx, base); }

uint64_t n_sub_83251DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987F8_G_ = int32_t(0x834987F8);
	if (!UseLiftedCode(143, 0x83251DC8)) { __imp__sub_83251DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987F8_G_, (int64_t)str_TXT_820C0000_B_ - 1200, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251DC8, 0x83251DC8) { ctx.r3.u64 = n_sub_83251DC8(ctx, base); }

uint64_t n_sub_83251E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834987FC_G_ = int32_t(0x834987FC);
	if (!UseLiftedCode(143, 0x83251E08)) { __imp__sub_83251E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834987FC_G_, (int64_t)str_TXT_820C0000_B_ - 1172, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251E08, 0x83251E08) { ctx.r3.u64 = n_sub_83251E08(ctx, base); }

uint64_t n_sub_83251E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498800_G_ = int32_t(0x83498800);
	if (!UseLiftedCode(143, 0x83251E48)) { __imp__sub_83251E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251E48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498800_G_, (int64_t)str_TXT_820C0000_B_ - 1140, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251E48, 0x83251E48) { ctx.r3.u64 = n_sub_83251E48(ctx, base); }

uint64_t n_sub_83251E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498804_G_ = int32_t(0x83498804);
	if (!UseLiftedCode(143, 0x83251E88)) { __imp__sub_83251E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498804_G_, (int64_t)str_TXT_820C0000_B_ - 1120, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251E88, 0x83251E88) { ctx.r3.u64 = n_sub_83251E88(ctx, base); }

uint64_t n_sub_83251EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498808_G_ = int32_t(0x83498808);
	if (!UseLiftedCode(143, 0x83251EC8)) { __imp__sub_83251EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251EC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498808_G_, (int64_t)str_TXT_820C0000_B_ - 1100, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251EC8, 0x83251EC8) { ctx.r3.u64 = n_sub_83251EC8(ctx, base); }

uint64_t n_sub_83251F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349880C_G_ = int32_t(0x8349880C);
	if (!UseLiftedCode(143, 0x83251F08)) { __imp__sub_83251F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349880C_G_, (int64_t)str_TXT_820C0000_B_ - 1068, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251F08, 0x83251F08) { ctx.r3.u64 = n_sub_83251F08(ctx, base); }

uint64_t n_sub_83251F48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498810_G_ = int32_t(0x83498810);
	if (!UseLiftedCode(143, 0x83251F48)) { __imp__sub_83251F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251F48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498810_G_, (int64_t)str_TXT_820C0000_B_ - 1044, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251F48, 0x83251F48) { ctx.r3.u64 = n_sub_83251F48(ctx, base); }

uint64_t n_sub_83251F88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498814_G_ = int32_t(0x83498814);
	if (!UseLiftedCode(143, 0x83251F88)) { __imp__sub_83251F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251F88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498814_G_, (int64_t)str_TXT_820C0000_B_ - 1020, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251F88, 0x83251F88) { ctx.r3.u64 = n_sub_83251F88(ctx, base); }

uint64_t n_sub_83251FC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498818_G_ = int32_t(0x83498818);
	if (!UseLiftedCode(143, 0x83251FC8)) { __imp__sub_83251FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251FC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498818_G_, (int64_t)str_TXT_820C0000_B_ - 992, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83251FC8, 0x83251FC8) { ctx.r3.u64 = n_sub_83251FC8(ctx, base); }

uint64_t n_sub_83252008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349881C_G_ = int32_t(0x8349881C);
	if (!UseLiftedCode(143, 0x83252008)) { __imp__sub_83252008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349881C_G_, (int64_t)str_TXT_820C0000_B_ - 960, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252008, 0x83252008) { ctx.r3.u64 = n_sub_83252008(ctx, base); }

uint64_t n_sub_83252048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498820_G_ = int32_t(0x83498820);
	if (!UseLiftedCode(143, 0x83252048)) { __imp__sub_83252048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498820_G_, (int64_t)str_TXT_820C0000_B_ - 928, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252048, 0x83252048) { ctx.r3.u64 = n_sub_83252048(ctx, base); }

uint64_t n_sub_83252088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498824_G_ = int32_t(0x83498824);
	if (!UseLiftedCode(143, 0x83252088)) { __imp__sub_83252088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498824_G_, (int64_t)str_TXT_820C0000_B_ - 900, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252088, 0x83252088) { ctx.r3.u64 = n_sub_83252088(ctx, base); }

uint64_t n_sub_832520C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498828_G_ = int32_t(0x83498828);
	if (!UseLiftedCode(143, 0x832520C8)) { __imp__sub_832520C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832520C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498828_G_, (int64_t)str_TXT_820C0000_B_ - 876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832520C8, 0x832520C8) { ctx.r3.u64 = n_sub_832520C8(ctx, base); }

uint64_t n_sub_83252108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349882C_G_ = int32_t(0x8349882C);
	if (!UseLiftedCode(143, 0x83252108)) { __imp__sub_83252108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349882C_G_, (int64_t)str_TXT_820C0000_B_ - 860, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252108, 0x83252108) { ctx.r3.u64 = n_sub_83252108(ctx, base); }

uint64_t n_sub_83252148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498830_G_ = int32_t(0x83498830);
	if (!UseLiftedCode(143, 0x83252148)) { __imp__sub_83252148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498830_G_, (int64_t)str_TXT_820C0000_B_ - 828, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252148, 0x83252148) { ctx.r3.u64 = n_sub_83252148(ctx, base); }

uint64_t n_sub_83252188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498834_G_ = int32_t(0x83498834);
	if (!UseLiftedCode(143, 0x83252188)) { __imp__sub_83252188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498834_G_, (int64_t)str_TXT_820C0000_B_ - 800, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252188, 0x83252188) { ctx.r3.u64 = n_sub_83252188(ctx, base); }

uint64_t n_sub_832521C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498838_G_ = int32_t(0x83498838);
	if (!UseLiftedCode(143, 0x832521C8)) { __imp__sub_832521C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832521C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498838_G_, (int64_t)str_TXT_820C0000_B_ - 1900, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832521C8, 0x832521C8) { ctx.r3.u64 = n_sub_832521C8(ctx, base); }

uint64_t n_sub_83252208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349883C_G_ = int32_t(0x8349883C);
	if (!UseLiftedCode(143, 0x83252208)) { __imp__sub_83252208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349883C_G_, (int64_t)str_TXT_820C0000_B_ - 1876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252208, 0x83252208) { ctx.r3.u64 = n_sub_83252208(ctx, base); }

uint64_t n_sub_83252248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498840_G_ = int32_t(0x83498840);
	if (!UseLiftedCode(143, 0x83252248)) { __imp__sub_83252248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252248);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498840_G_, (int64_t)str_TXT_820C0000_B_ - 1900, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252248, 0x83252248) { ctx.r3.u64 = n_sub_83252248(ctx, base); }

uint64_t n_sub_83252288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498844_G_ = int32_t(0x83498844);
	if (!UseLiftedCode(143, 0x83252288)) { __imp__sub_83252288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498844_G_, (int64_t)str_TXT_820C0000_B_ - 1876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252288, 0x83252288) { ctx.r3.u64 = n_sub_83252288(ctx, base); }

uint64_t n_sub_832522C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498848_G_ = int32_t(0x83498848);
	if (!UseLiftedCode(143, 0x832522C8)) { __imp__sub_832522C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832522C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498848_G_, (int64_t)str_TXT_820C0000_B_ - 2264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832522C8, 0x832522C8) { ctx.r3.u64 = n_sub_832522C8(ctx, base); }

uint64_t n_sub_83252308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349884C_G_ = int32_t(0x8349884C);
	if (!UseLiftedCode(143, 0x83252308)) { __imp__sub_83252308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349884C_G_, (int64_t)str_TXT_820C0000_B_ - 2248, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252308, 0x83252308) { ctx.r3.u64 = n_sub_83252308(ctx, base); }

uint64_t n_sub_83252348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498850_G_ = int32_t(0x83498850);
	if (!UseLiftedCode(143, 0x83252348)) { __imp__sub_83252348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498850_G_, (int64_t)str_TXT_820C0000_B_ - 772, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252348, 0x83252348) { ctx.r3.u64 = n_sub_83252348(ctx, base); }

uint64_t n_sub_83252388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498854_G_ = int32_t(0x83498854);
	if (!UseLiftedCode(143, 0x83252388)) { __imp__sub_83252388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498854_G_, (int64_t)str_TXT_820C0000_B_ - 772, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252388, 0x83252388) { ctx.r3.u64 = n_sub_83252388(ctx, base); }

uint64_t n_sub_832523C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498858_G_ = int32_t(0x83498858);
	if (!UseLiftedCode(143, 0x832523C8)) { __imp__sub_832523C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832523C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498858_G_, (int64_t)str_TXT_820C0000_B_ - 756, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832523C8, 0x832523C8) { ctx.r3.u64 = n_sub_832523C8(ctx, base); }

uint64_t n_sub_83252408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349885C_G_ = int32_t(0x8349885C);
	if (!UseLiftedCode(143, 0x83252408)) { __imp__sub_83252408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349885C_G_, (int64_t)str_TXT_820C0000_B_ - 736, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252408, 0x83252408) { ctx.r3.u64 = n_sub_83252408(ctx, base); }

uint64_t n_sub_83252448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498860_G_ = int32_t(0x83498860);
	if (!UseLiftedCode(143, 0x83252448)) { __imp__sub_83252448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498860_G_, (int64_t)str_TXT_820C0000_B_ - 720, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252448, 0x83252448) { ctx.r3.u64 = n_sub_83252448(ctx, base); }

uint64_t n_sub_83252488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498864_G_ = int32_t(0x83498864);
	if (!UseLiftedCode(143, 0x83252488)) { __imp__sub_83252488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498864_G_, (int64_t)str_TXT_820C0000_B_ - 700, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252488, 0x83252488) { ctx.r3.u64 = n_sub_83252488(ctx, base); }

uint64_t n_sub_832524C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498868_G_ = int32_t(0x83498868);
	if (!UseLiftedCode(143, 0x832524C8)) { __imp__sub_832524C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832524C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498868_G_, (int64_t)str_TXT_820C0000_B_ - 680, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832524C8, 0x832524C8) { ctx.r3.u64 = n_sub_832524C8(ctx, base); }

uint64_t n_sub_83252508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349886C_G_ = int32_t(0x8349886C);
	if (!UseLiftedCode(143, 0x83252508)) { __imp__sub_83252508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349886C_G_, (int64_t)str_TXT_820C0000_B_ - 660, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252508, 0x83252508) { ctx.r3.u64 = n_sub_83252508(ctx, base); }

uint64_t n_sub_83252548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498870_G_ = int32_t(0x83498870);
	if (!UseLiftedCode(143, 0x83252548)) { __imp__sub_83252548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498870_G_, (int64_t)str_TXT_820C0000_B_ - 636, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252548, 0x83252548) { ctx.r3.u64 = n_sub_83252548(ctx, base); }

uint64_t n_sub_83252588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498874_G_ = int32_t(0x83498874);
	if (!UseLiftedCode(143, 0x83252588)) { __imp__sub_83252588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498874_G_, (int64_t)str_TXT_820C0000_B_ - 608, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252588, 0x83252588) { ctx.r3.u64 = n_sub_83252588(ctx, base); }

uint64_t n_sub_832525C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498878_G_ = int32_t(0x83498878);
	if (!UseLiftedCode(143, 0x832525C8)) { __imp__sub_832525C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832525C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498878_G_, (int64_t)str_TXT_820C0000_B_ - 580, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832525C8, 0x832525C8) { ctx.r3.u64 = n_sub_832525C8(ctx, base); }

uint64_t n_sub_83252608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349887C_G_ = int32_t(0x8349887C);
	if (!UseLiftedCode(143, 0x83252608)) { __imp__sub_83252608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349887C_G_, (int64_t)str_TXT_820C0000_B_ - 552, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252608, 0x83252608) { ctx.r3.u64 = n_sub_83252608(ctx, base); }

uint64_t n_sub_83252648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498880_G_ = int32_t(0x83498880);
	if (!UseLiftedCode(143, 0x83252648)) { __imp__sub_83252648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252648);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498880_G_, (int64_t)str_TXT_820B0000_B_ - 6076, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252648, 0x83252648) { ctx.r3.u64 = n_sub_83252648(ctx, base); }

uint64_t n_sub_83252688(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498884_G_ = int32_t(0x83498884);
	if (!UseLiftedCode(143, 0x83252688)) { __imp__sub_83252688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252688);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498884_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252688, 0x83252688) { ctx.r3.u64 = n_sub_83252688(ctx, base); }

uint64_t n_sub_832526C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498888_G_ = int32_t(0x83498888);
	if (!UseLiftedCode(143, 0x832526C8)) { __imp__sub_832526C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832526C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498888_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832526C8, 0x832526C8) { ctx.r3.u64 = n_sub_832526C8(ctx, base); }

uint64_t n_sub_83252708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349888C_G_ = int32_t(0x8349888C);
	if (!UseLiftedCode(143, 0x83252708)) { __imp__sub_83252708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349888C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252708, 0x83252708) { ctx.r3.u64 = n_sub_83252708(ctx, base); }

uint64_t n_sub_83252BE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834988E4_G_ = int32_t(0x834988E4);
	if (!UseLiftedCode(143, 0x83252BE0)) { __imp__sub_83252BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252BE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834988E4_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252BE0, 0x83252BE0) { ctx.r3.u64 = n_sub_83252BE0(ctx, base); }

uint64_t n_sub_83252C20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834988E8_G_ = int32_t(0x834988E8);
	if (!UseLiftedCode(143, 0x83252C20)) { __imp__sub_83252C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252C20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834988E8_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252C20, 0x83252C20) { ctx.r3.u64 = n_sub_83252C20(ctx, base); }

uint64_t n_sub_83252C60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834988EC_G_ = int32_t(0x834988EC);
	if (!UseLiftedCode(143, 0x83252C60)) { __imp__sub_83252C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252C60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834988EC_G_, (int64_t)str_TXT_820C0000_B_ - 424, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252C60, 0x83252C60) { ctx.r3.u64 = n_sub_83252C60(ctx, base); }

uint64_t n_sub_83252CA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834988F0_G_ = int32_t(0x834988F0);
	if (!UseLiftedCode(143, 0x83252CA0)) { __imp__sub_83252CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252CA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834988F0_G_, (int64_t)str_TXT_820C0000_B_ - 356, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252CA0, 0x83252CA0) { ctx.r3.u64 = n_sub_83252CA0(ctx, base); }

uint64_t n_sub_83252CE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834988F4_G_ = int32_t(0x834988F4);
	if (!UseLiftedCode(143, 0x83252CE0)) { __imp__sub_83252CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252CE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834988F4_G_, (int64_t)str_TXT_820C0000_B_ - 308, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252CE0, 0x83252CE0) { ctx.r3.u64 = n_sub_83252CE0(ctx, base); }

uint64_t n_sub_83252D20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834988F8_G_ = int32_t(0x834988F8);
	if (!UseLiftedCode(143, 0x83252D20)) { __imp__sub_83252D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252D20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834988F8_G_, (int64_t)str_TXT_820C0000_B_ - 292, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252D20, 0x83252D20) { ctx.r3.u64 = n_sub_83252D20(ctx, base); }

uint64_t n_sub_83252D60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834988FC_G_ = int32_t(0x834988FC);
	if (!UseLiftedCode(143, 0x83252D60)) { __imp__sub_83252D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252D60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834988FC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 14992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252D60, 0x83252D60) { ctx.r3.u64 = n_sub_83252D60(ctx, base); }

uint64_t n_sub_83252DA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498900_G_ = int32_t(0x83498900);
	if (!UseLiftedCode(143, 0x83252DA0)) { __imp__sub_83252DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252DA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498900_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252DA0, 0x83252DA0) { ctx.r3.u64 = n_sub_83252DA0(ctx, base); }

uint64_t n_sub_83252DE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498904_G_ = int32_t(0x83498904);
	if (!UseLiftedCode(143, 0x83252DE0)) { __imp__sub_83252DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252DE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498904_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83252DE0, 0x83252DE0) { ctx.r3.u64 = n_sub_83252DE0(ctx, base); }

uint64_t n_sub_832532B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349895C_G_ = int32_t(0x8349895C);
	if (!UseLiftedCode(143, 0x832532B8)) { __imp__sub_832532B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832532B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349895C_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832532B8, 0x832532B8) { ctx.r3.u64 = n_sub_832532B8(ctx, base); }

// sub_832532F8  [64 bytes]
uint64_t n_sub_832532F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498960_G_ = int32_t(0x83498960);
	if (!UseLiftedCode(143, 0x832532F8)) { __imp__sub_832532F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832532F8);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498960_G_, (int64_t)str_TXT_820C0000_B_ + 680, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832532F8, 0x832532F8) { ctx.r3.u64 = n_sub_832532F8(ctx, base); }

uint64_t n_sub_83253338(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498964_G_ = int32_t(0x83498964);
	if (!UseLiftedCode(143, 0x83253338)) { __imp__sub_83253338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253338);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498964_G_, (int64_t)str_TXT_820C0000_B_ + 724, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253338, 0x83253338) { ctx.r3.u64 = n_sub_83253338(ctx, base); }

uint64_t n_sub_83253B00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A3C_G_ = int32_t(0x83498A3C);
	if (!UseLiftedCode(143, 0x83253B00)) { __imp__sub_83253B00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253B00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A3C_G_, (int64_t)str_TXT_820C0000_B_ - 308, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253B00, 0x83253B00) { ctx.r3.u64 = n_sub_83253B00(ctx, base); }

uint64_t n_sub_83253B40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A40_G_ = int32_t(0x83498A40);
	if (!UseLiftedCode(143, 0x83253B40)) { __imp__sub_83253B40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253B40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A40_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253B40, 0x83253B40) { ctx.r3.u64 = n_sub_83253B40(ctx, base); }

uint64_t n_sub_83253B80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A44_G_ = int32_t(0x83498A44);
	if (!UseLiftedCode(143, 0x83253B80)) { __imp__sub_83253B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253B80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A44_G_, (int64_t)str_TXT_820C0000_B_ + 820, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253B80, 0x83253B80) { ctx.r3.u64 = n_sub_83253B80(ctx, base); }

uint64_t n_sub_83253BC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A48_G_ = int32_t(0x83498A48);
	if (!UseLiftedCode(143, 0x83253BC0)) { __imp__sub_83253BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253BC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A48_G_, (int64_t)str_TXT_820C0000_B_ + 856, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253BC0, 0x83253BC0) { ctx.r3.u64 = n_sub_83253BC0(ctx, base); }

uint64_t n_sub_83253C00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A4C_G_ = int32_t(0x83498A4C);
	if (!UseLiftedCode(143, 0x83253C00)) { __imp__sub_83253C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253C00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A4C_G_, (int64_t)str_TXT_820C0000_B_ + 892, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253C00, 0x83253C00) { ctx.r3.u64 = n_sub_83253C00(ctx, base); }

uint64_t n_sub_83253C40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A50_G_ = int32_t(0x83498A50);
	if (!UseLiftedCode(143, 0x83253C40)) { __imp__sub_83253C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253C40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A50_G_, (int64_t)str_TXT_820C0000_B_ + 936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253C40, 0x83253C40) { ctx.r3.u64 = n_sub_83253C40(ctx, base); }

uint64_t n_sub_83253C80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A54_G_ = int32_t(0x83498A54);
	if (!UseLiftedCode(143, 0x83253C80)) { __imp__sub_83253C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253C80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A54_G_, (int64_t)str_TXT_820C0000_B_ + 968, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253C80, 0x83253C80) { ctx.r3.u64 = n_sub_83253C80(ctx, base); }

uint64_t n_sub_83253CC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A58_G_ = int32_t(0x83498A58);
	if (!UseLiftedCode(143, 0x83253CC0)) { __imp__sub_83253CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253CC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A58_G_, (int64_t)str_TXT_820C0000_B_ + 1000, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253CC0, 0x83253CC0) { ctx.r3.u64 = n_sub_83253CC0(ctx, base); }

uint64_t n_sub_83253D00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A5C_G_ = int32_t(0x83498A5C);
	if (!UseLiftedCode(143, 0x83253D00)) { __imp__sub_83253D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253D00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A5C_G_, (int64_t)str_TXT_820C0000_B_ + 1040, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253D00, 0x83253D00) { ctx.r3.u64 = n_sub_83253D00(ctx, base); }

uint64_t n_sub_83253D40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A60_G_ = int32_t(0x83498A60);
	if (!UseLiftedCode(143, 0x83253D40)) { __imp__sub_83253D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253D40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A60_G_, (int64_t)str_TXT_820C0000_B_ + 1084, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253D40, 0x83253D40) { ctx.r3.u64 = n_sub_83253D40(ctx, base); }

uint64_t n_sub_83253D80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498A64_G_ = int32_t(0x83498A64);
	if (!UseLiftedCode(143, 0x83253D80)) { __imp__sub_83253D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253D80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A64_G_, (int64_t)str_TXT_820C0000_B_ + 1116, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83253D80, 0x83253D80) { ctx.r3.u64 = n_sub_83253D80(ctx, base); }

uint64_t n_sub_83254258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498ABC_G_ = int32_t(0x83498ABC);
	if (!UseLiftedCode(143, 0x83254258)) { __imp__sub_83254258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254258);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498ABC_G_, (int64_t)str_TXT_820C0000_B_ + 1264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254258, 0x83254258) { ctx.r3.u64 = n_sub_83254258(ctx, base); }

uint64_t n_sub_83254298(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498AC0_G_ = int32_t(0x83498AC0);
	if (!UseLiftedCode(143, 0x83254298)) { __imp__sub_83254298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254298);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AC0_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254298, 0x83254298) { ctx.r3.u64 = n_sub_83254298(ctx, base); }

uint64_t n_sub_832542D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498AC4_G_ = int32_t(0x83498AC4);
	if (!UseLiftedCode(143, 0x832542D8)) { __imp__sub_832542D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832542D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AC4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832542D8, 0x832542D8) { ctx.r3.u64 = n_sub_832542D8(ctx, base); }

uint64_t n_sub_83254318(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498AC8_G_ = int32_t(0x83498AC8);
	if (!UseLiftedCode(143, 0x83254318)) { __imp__sub_83254318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254318);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AC8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254318, 0x83254318) { ctx.r3.u64 = n_sub_83254318(ctx, base); }

uint64_t n_sub_83254358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498ACC_G_ = int32_t(0x83498ACC);
	if (!UseLiftedCode(143, 0x83254358)) { __imp__sub_83254358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498ACC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254358, 0x83254358) { ctx.r3.u64 = n_sub_83254358(ctx, base); }

uint64_t n_sub_83254398(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498AD0_G_ = int32_t(0x83498AD0);
	if (!UseLiftedCode(143, 0x83254398)) { __imp__sub_83254398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254398);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AD0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254398, 0x83254398) { ctx.r3.u64 = n_sub_83254398(ctx, base); }

uint64_t n_sub_832543D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498AD4_G_ = int32_t(0x83498AD4);
	if (!UseLiftedCode(143, 0x832543D8)) { __imp__sub_832543D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832543D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AD4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832543D8, 0x832543D8) { ctx.r3.u64 = n_sub_832543D8(ctx, base); }

uint64_t n_sub_83254418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498AD8_G_ = int32_t(0x83498AD8);
	if (!UseLiftedCode(143, 0x83254418)) { __imp__sub_83254418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254418);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AD8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254418, 0x83254418) { ctx.r3.u64 = n_sub_83254418(ctx, base); }

uint64_t n_sub_83254848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B24_G_ = int32_t(0x83498B24);
	if (!UseLiftedCode(143, 0x83254848)) { __imp__sub_83254848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B24_G_, (int64_t)str_TXT_820C0000_B_ + 1572, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254848, 0x83254848) { ctx.r3.u64 = n_sub_83254848(ctx, base); }

uint64_t n_sub_83254888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B28_G_ = int32_t(0x83498B28);
	if (!UseLiftedCode(143, 0x83254888)) { __imp__sub_83254888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B28_G_, (int64_t)str_TXT_820C0000_B_ + 1608, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254888, 0x83254888) { ctx.r3.u64 = n_sub_83254888(ctx, base); }

uint64_t n_sub_832548C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B2C_G_ = int32_t(0x83498B2C);
	if (!UseLiftedCode(143, 0x832548C8)) { __imp__sub_832548C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832548C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B2C_G_, (int64_t)str_TXT_820C0000_B_ + 1644, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832548C8, 0x832548C8) { ctx.r3.u64 = n_sub_832548C8(ctx, base); }

uint64_t n_sub_83254908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B30_G_ = int32_t(0x83498B30);
	if (!UseLiftedCode(143, 0x83254908)) { __imp__sub_83254908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B30_G_, (int64_t)str_TXT_820B0000_B_ + 10212, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254908, 0x83254908) { ctx.r3.u64 = n_sub_83254908(ctx, base); }

uint64_t n_sub_83254948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B34_G_ = int32_t(0x83498B34);
	if (!UseLiftedCode(143, 0x83254948)) { __imp__sub_83254948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B34_G_, (int64_t)str_TXT_820B0000_B_ + 10240, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254948, 0x83254948) { ctx.r3.u64 = n_sub_83254948(ctx, base); }

uint64_t n_sub_83254988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B38_G_ = int32_t(0x83498B38);
	if (!UseLiftedCode(143, 0x83254988)) { __imp__sub_83254988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B38_G_, (int64_t)str_TXT_820C0000_B_ + 1676, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254988, 0x83254988) { ctx.r3.u64 = n_sub_83254988(ctx, base); }

uint64_t n_sub_832549C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B3C_G_ = int32_t(0x83498B3C);
	if (!UseLiftedCode(143, 0x832549C8)) { __imp__sub_832549C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832549C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B3C_G_, (int64_t)str_TXT_820C0000_B_ + 1708, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832549C8, 0x832549C8) { ctx.r3.u64 = n_sub_832549C8(ctx, base); }

uint64_t n_sub_83254A08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B40_G_ = int32_t(0x83498B40);
	if (!UseLiftedCode(143, 0x83254A08)) { __imp__sub_83254A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254A08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B40_G_, (int64_t)str_TXT_820C0000_B_ + 1736, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254A08, 0x83254A08) { ctx.r3.u64 = n_sub_83254A08(ctx, base); }

uint64_t n_sub_83254A48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B44_G_ = int32_t(0x83498B44);
	if (!UseLiftedCode(143, 0x83254A48)) { __imp__sub_83254A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254A48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B44_G_, (int64_t)str_TXT_820C0000_B_ + 1764, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254A48, 0x83254A48) { ctx.r3.u64 = n_sub_83254A48(ctx, base); }

uint64_t n_sub_83254A88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B48_G_ = int32_t(0x83498B48);
	if (!UseLiftedCode(143, 0x83254A88)) { __imp__sub_83254A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254A88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B48_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254A88, 0x83254A88) { ctx.r3.u64 = n_sub_83254A88(ctx, base); }

uint64_t n_sub_83254AC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B4C_G_ = int32_t(0x83498B4C);
	if (!UseLiftedCode(143, 0x83254AC8)) { __imp__sub_83254AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254AC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B4C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254AC8, 0x83254AC8) { ctx.r3.u64 = n_sub_83254AC8(ctx, base); }

uint64_t n_sub_83254B08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B50_G_ = int32_t(0x83498B50);
	if (!UseLiftedCode(143, 0x83254B08)) { __imp__sub_83254B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254B08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B50_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254B08, 0x83254B08) { ctx.r3.u64 = n_sub_83254B08(ctx, base); }

uint64_t n_sub_83254B48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B54_G_ = int32_t(0x83498B54);
	if (!UseLiftedCode(143, 0x83254B48)) { __imp__sub_83254B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254B48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B54_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254B48, 0x83254B48) { ctx.r3.u64 = n_sub_83254B48(ctx, base); }

uint64_t n_sub_83254BF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B60_G_ = int32_t(0x83498B60);
	if (!UseLiftedCode(143, 0x83254BF8)) { __imp__sub_83254BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254BF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B60_G_, (int64_t)str_TXT_820C0000_B_ + 2484, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254BF8, 0x83254BF8) { ctx.r3.u64 = n_sub_83254BF8(ctx, base); }

uint64_t n_sub_83254C38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B64_G_ = int32_t(0x83498B64);
	if (!UseLiftedCode(143, 0x83254C38)) { __imp__sub_83254C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254C38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B64_G_, (int64_t)str_TXT_820C0000_B_ + 2500, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254C38, 0x83254C38) { ctx.r3.u64 = n_sub_83254C38(ctx, base); }

uint64_t n_sub_83254C78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B68_G_ = int32_t(0x83498B68);
	if (!UseLiftedCode(143, 0x83254C78)) { __imp__sub_83254C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254C78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B68_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254C78, 0x83254C78) { ctx.r3.u64 = n_sub_83254C78(ctx, base); }

uint64_t n_sub_83254CB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B6C_G_ = int32_t(0x83498B6C);
	if (!UseLiftedCode(143, 0x83254CB8)) { __imp__sub_83254CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254CB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B6C_G_, (int64_t)str_TXT_820B0000_B_ - 3652, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254CB8, 0x83254CB8) { ctx.r3.u64 = n_sub_83254CB8(ctx, base); }

uint64_t n_sub_83254CF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B70_G_ = int32_t(0x83498B70);
	if (!UseLiftedCode(143, 0x83254CF8)) { __imp__sub_83254CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254CF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B70_G_, (int64_t)str_TXT_820C0000_B_ + 2560, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254CF8, 0x83254CF8) { ctx.r3.u64 = n_sub_83254CF8(ctx, base); }

uint64_t n_sub_83254D38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B74_G_ = int32_t(0x83498B74);
	if (!UseLiftedCode(143, 0x83254D38)) { __imp__sub_83254D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254D38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B74_G_, (int64_t)str_TXT_820C0000_B_ + 2584, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254D38, 0x83254D38) { ctx.r3.u64 = n_sub_83254D38(ctx, base); }

uint64_t n_sub_83254D78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B78_G_ = int32_t(0x83498B78);
	if (!UseLiftedCode(143, 0x83254D78)) { __imp__sub_83254D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254D78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B78_G_, (int64_t)str_TXT_820C0000_B_ + 2616, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254D78, 0x83254D78) { ctx.r3.u64 = n_sub_83254D78(ctx, base); }

uint64_t n_sub_83254DB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B7C_G_ = int32_t(0x83498B7C);
	if (!UseLiftedCode(143, 0x83254DB8)) { __imp__sub_83254DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254DB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B7C_G_, (int64_t)str_TXT_820C0000_B_ + 2652, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254DB8, 0x83254DB8) { ctx.r3.u64 = n_sub_83254DB8(ctx, base); }

uint64_t n_sub_83254DF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B80_G_ = int32_t(0x83498B80);
	if (!UseLiftedCode(143, 0x83254DF8)) { __imp__sub_83254DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254DF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B80_G_, (int64_t)str_TXT_820C0000_B_ + 2664, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254DF8, 0x83254DF8) { ctx.r3.u64 = n_sub_83254DF8(ctx, base); }

uint64_t n_sub_83254E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B84_G_ = int32_t(0x83498B84);
	if (!UseLiftedCode(143, 0x83254E38)) { __imp__sub_83254E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254E38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B84_G_, (int64_t)str_TXT_820C0000_B_ + 2676, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254E38, 0x83254E38) { ctx.r3.u64 = n_sub_83254E38(ctx, base); }

uint64_t n_sub_83254E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B88_G_ = int32_t(0x83498B88);
	if (!UseLiftedCode(143, 0x83254E78)) { __imp__sub_83254E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B88_G_, (int64_t)str_TXT_820C0000_B_ + 2684, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254E78, 0x83254E78) { ctx.r3.u64 = n_sub_83254E78(ctx, base); }

uint64_t n_sub_83254EB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B8C_G_ = int32_t(0x83498B8C);
	if (!UseLiftedCode(143, 0x83254EB8)) { __imp__sub_83254EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B8C_G_, (int64_t)str_TXT_820C0000_B_ + 2684, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 15984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254EB8, 0x83254EB8) { ctx.r3.u64 = n_sub_83254EB8(ctx, base); }

uint64_t n_sub_83254EF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B90_G_ = int32_t(0x83498B90);
	if (!UseLiftedCode(143, 0x83254EF8)) { __imp__sub_83254EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254EF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B90_G_, (int64_t)str_TXT_820C0000_B_ + 2716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254EF8, 0x83254EF8) { ctx.r3.u64 = n_sub_83254EF8(ctx, base); }

uint64_t n_sub_83254F38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B94_G_ = int32_t(0x83498B94);
	if (!UseLiftedCode(143, 0x83254F38)) { __imp__sub_83254F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B94_G_, (int64_t)str_TXT_820C0000_B_ + 2748, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254F38, 0x83254F38) { ctx.r3.u64 = n_sub_83254F38(ctx, base); }

uint64_t n_sub_83254F78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B98_G_ = int32_t(0x83498B98);
	if (!UseLiftedCode(143, 0x83254F78)) { __imp__sub_83254F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254F78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B98_G_, (int64_t)str_TXT_820C0000_B_ + 2784, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254F78, 0x83254F78) { ctx.r3.u64 = n_sub_83254F78(ctx, base); }

uint64_t n_sub_83254FB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498B9C_G_ = int32_t(0x83498B9C);
	if (!UseLiftedCode(143, 0x83254FB8)) { __imp__sub_83254FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254FB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B9C_G_, (int64_t)str_TXT_820C0000_B_ + 2820, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254FB8, 0x83254FB8) { ctx.r3.u64 = n_sub_83254FB8(ctx, base); }

uint64_t n_sub_83254FF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BA0_G_ = int32_t(0x83498BA0);
	if (!UseLiftedCode(143, 0x83254FF8)) { __imp__sub_83254FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254FF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BA0_G_, (int64_t)str_TXT_820C0000_B_ + 2856, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83254FF8, 0x83254FF8) { ctx.r3.u64 = n_sub_83254FF8(ctx, base); }

uint64_t n_sub_83255038(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BA4_G_ = int32_t(0x83498BA4);
	if (!UseLiftedCode(143, 0x83255038)) { __imp__sub_83255038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BA4_G_, (int64_t)str_TXT_820C0000_B_ + 2868, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255038, 0x83255038) { ctx.r3.u64 = n_sub_83255038(ctx, base); }

uint64_t n_sub_83255078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BA8_G_ = int32_t(0x83498BA8);
	if (!UseLiftedCode(143, 0x83255078)) { __imp__sub_83255078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BA8_G_, (int64_t)str_TXT_820C0000_B_ + 2896, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255078, 0x83255078) { ctx.r3.u64 = n_sub_83255078(ctx, base); }

uint64_t n_sub_832550B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BAC_G_ = int32_t(0x83498BAC);
	if (!UseLiftedCode(143, 0x832550B8)) { __imp__sub_832550B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832550B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BAC_G_, (int64_t)str_TXT_820C0000_B_ + 2916, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832550B8, 0x832550B8) { ctx.r3.u64 = n_sub_832550B8(ctx, base); }

uint64_t n_sub_832550F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BB0_G_ = int32_t(0x83498BB0);
	if (!UseLiftedCode(143, 0x832550F8)) { __imp__sub_832550F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832550F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BB0_G_, (int64_t)str_TXT_820C0000_B_ + 1736, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832550F8, 0x832550F8) { ctx.r3.u64 = n_sub_832550F8(ctx, base); }

uint64_t n_sub_83255138(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BB4_G_ = int32_t(0x83498BB4);
	if (!UseLiftedCode(143, 0x83255138)) { __imp__sub_83255138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255138);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BB4_G_, (int64_t)str_TXT_820C0000_B_ + 2856, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255138, 0x83255138) { ctx.r3.u64 = n_sub_83255138(ctx, base); }

uint64_t n_sub_83255178(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BB8_G_ = int32_t(0x83498BB8);
	if (!UseLiftedCode(143, 0x83255178)) { __imp__sub_83255178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255178);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BB8_G_, (int64_t)str_TXT_820C0000_B_ + 2944, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255178, 0x83255178) { ctx.r3.u64 = n_sub_83255178(ctx, base); }

uint64_t n_sub_832551B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BBC_G_ = int32_t(0x83498BBC);
	if (!UseLiftedCode(143, 0x832551B8)) { __imp__sub_832551B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832551B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BBC_G_, (int64_t)g_82000000 + 9516, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832551B8, 0x832551B8) { ctx.r3.u64 = n_sub_832551B8(ctx, base); }

uint64_t n_sub_832551F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BC0_G_ = int32_t(0x83498BC0);
	if (!UseLiftedCode(143, 0x832551F8)) { __imp__sub_832551F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832551F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BC0_G_, (int64_t)str_TXT_820B0000_B_ - 29716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832551F8, 0x832551F8) { ctx.r3.u64 = n_sub_832551F8(ctx, base); }

uint64_t n_sub_83255238(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BC4_G_ = int32_t(0x83498BC4);
	if (!UseLiftedCode(143, 0x83255238)) { __imp__sub_83255238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255238);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BC4_G_, (int64_t)str_TXT_820B0000_B_ - 29772, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255238, 0x83255238) { ctx.r3.u64 = n_sub_83255238(ctx, base); }

uint64_t n_sub_83255278(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BC8_G_ = int32_t(0x83498BC8);
	if (!UseLiftedCode(143, 0x83255278)) { __imp__sub_83255278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255278);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BC8_G_, (int64_t)str_TXT_820B0000_B_ - 29744, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255278, 0x83255278) { ctx.r3.u64 = n_sub_83255278(ctx, base); }

uint64_t n_sub_832552B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498BCC_G_ = int32_t(0x83498BCC);
	if (!UseLiftedCode(143, 0x832552B8)) { __imp__sub_832552B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832552B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BCC_G_, (int64_t)str_TXT_820C0000_B_ + 2976, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832552B8, 0x832552B8) { ctx.r3.u64 = n_sub_832552B8(ctx, base); }

uint64_t n_sub_83255790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C24_G_ = int32_t(0x83498C24);
	if (!UseLiftedCode(143, 0x83255790)) { __imp__sub_83255790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255790);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C24_G_, (int64_t)str_TXT_820C0000_B_ - 308, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255790, 0x83255790) { ctx.r3.u64 = n_sub_83255790(ctx, base); }

uint64_t n_sub_832557D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C28_G_ = int32_t(0x83498C28);
	if (!UseLiftedCode(143, 0x832557D0)) { __imp__sub_832557D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832557D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C28_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832557D0, 0x832557D0) { ctx.r3.u64 = n_sub_832557D0(ctx, base); }

uint64_t n_sub_83255810(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C2C_G_ = int32_t(0x83498C2C);
	if (!UseLiftedCode(143, 0x83255810)) { __imp__sub_83255810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255810);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C2C_G_, (int64_t)str_TXT_820C0000_B_ + 3468, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255810, 0x83255810) { ctx.r3.u64 = n_sub_83255810(ctx, base); }

uint64_t n_sub_83255850(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C30_G_ = int32_t(0x83498C30);
	if (!UseLiftedCode(143, 0x83255850)) { __imp__sub_83255850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255850);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C30_G_, (int64_t)str_TXT_820C0000_B_ + 3528, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255850, 0x83255850) { ctx.r3.u64 = n_sub_83255850(ctx, base); }

uint64_t n_sub_83255890(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C34_G_ = int32_t(0x83498C34);
	if (!UseLiftedCode(143, 0x83255890)) { __imp__sub_83255890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255890);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C34_G_, (int64_t)str_TXT_820C0000_B_ + 3580, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255890, 0x83255890) { ctx.r3.u64 = n_sub_83255890(ctx, base); }

uint64_t n_sub_832558D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C38_G_ = int32_t(0x83498C38);
	if (!UseLiftedCode(143, 0x832558D0)) { __imp__sub_832558D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832558D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C38_G_, (int64_t)str_TXT_820C0000_B_ + 3640, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832558D0, 0x832558D0) { ctx.r3.u64 = n_sub_832558D0(ctx, base); }

uint64_t n_sub_83255910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C3C_G_ = int32_t(0x83498C3C);
	if (!UseLiftedCode(143, 0x83255910)) { __imp__sub_83255910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C3C_G_, (int64_t)str_TXT_820C0000_B_ + 3692, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255910, 0x83255910) { ctx.r3.u64 = n_sub_83255910(ctx, base); }

uint64_t n_sub_83255DE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C94_G_ = int32_t(0x83498C94);
	if (!UseLiftedCode(143, 0x83255DE8)) { __imp__sub_83255DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255DE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C94_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255DE8, 0x83255DE8) { ctx.r3.u64 = n_sub_83255DE8(ctx, base); }

uint64_t n_sub_83255E28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C98_G_ = int32_t(0x83498C98);
	if (!UseLiftedCode(143, 0x83255E28)) { __imp__sub_83255E28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255E28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C98_G_, (int64_t)str_TXT_820C0000_B_ + 3924, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255E28, 0x83255E28) { ctx.r3.u64 = n_sub_83255E28(ctx, base); }

uint64_t n_sub_83255E68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498C9C_G_ = int32_t(0x83498C9C);
	if (!UseLiftedCode(143, 0x83255E68)) { __imp__sub_83255E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255E68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C9C_G_, (int64_t)str_TXT_820C0000_B_ + 3960, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83255E68, 0x83255E68) { ctx.r3.u64 = n_sub_83255E68(ctx, base); }

uint64_t n_sub_83256340(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498CF4_G_ = int32_t(0x83498CF4);
	if (!UseLiftedCode(143, 0x83256340)) { __imp__sub_83256340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256340);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498CF4_G_, (int64_t)str_TXT_820C0000_B_ - 308, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256340, 0x83256340) { ctx.r3.u64 = n_sub_83256340(ctx, base); }

uint64_t n_sub_83256380(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498CF8_G_ = int32_t(0x83498CF8);
	if (!UseLiftedCode(143, 0x83256380)) { __imp__sub_83256380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256380);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498CF8_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256380, 0x83256380) { ctx.r3.u64 = n_sub_83256380(ctx, base); }

uint64_t n_sub_832568C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498D58_G_ = int32_t(0x83498D58);
	if (!UseLiftedCode(143, 0x832568C8)) { __imp__sub_832568C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832568C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498D58_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832568C8, 0x832568C8) { ctx.r3.u64 = n_sub_832568C8(ctx, base); }

uint64_t n_sub_83256908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498D5C_G_ = int32_t(0x83498D5C);
	if (!UseLiftedCode(143, 0x83256908)) { __imp__sub_83256908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498D5C_G_, (int64_t)str_TXT_820C0000_B_ + 3960, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256908, 0x83256908) { ctx.r3.u64 = n_sub_83256908(ctx, base); }

uint64_t n_sub_83256DE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DB4_G_ = int32_t(0x83498DB4);
	if (!UseLiftedCode(143, 0x83256DE0)) { __imp__sub_83256DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256DE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DB4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256DE0, 0x83256DE0) { ctx.r3.u64 = n_sub_83256DE0(ctx, base); }

uint64_t n_sub_83256E20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DB8_G_ = int32_t(0x83498DB8);
	if (!UseLiftedCode(143, 0x83256E20)) { __imp__sub_83256E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256E20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DB8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256E20, 0x83256E20) { ctx.r3.u64 = n_sub_83256E20(ctx, base); }

uint64_t n_sub_83256E60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DBC_G_ = int32_t(0x83498DBC);
	if (!UseLiftedCode(143, 0x83256E60)) { __imp__sub_83256E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256E60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DBC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256E60, 0x83256E60) { ctx.r3.u64 = n_sub_83256E60(ctx, base); }

uint64_t n_sub_83256EA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DC0_G_ = int32_t(0x83498DC0);
	if (!UseLiftedCode(143, 0x83256EA0)) { __imp__sub_83256EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256EA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DC0_G_, (int64_t)str_TXT_820C0000_B_ + 6464, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256EA0, 0x83256EA0) { ctx.r3.u64 = n_sub_83256EA0(ctx, base); }

uint64_t n_sub_83256EE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DC4_G_ = int32_t(0x83498DC4);
	if (!UseLiftedCode(143, 0x83256EE0)) { __imp__sub_83256EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256EE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DC4_G_, (int64_t)str_TXT_820C0000_B_ + 6476, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256EE0, 0x83256EE0) { ctx.r3.u64 = n_sub_83256EE0(ctx, base); }

uint64_t n_sub_83256F20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DC8_G_ = int32_t(0x83498DC8);
	if (!UseLiftedCode(143, 0x83256F20)) { __imp__sub_83256F20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256F20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DC8_G_, (int64_t)str_TXT_820C0000_B_ + 6548, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256F20, 0x83256F20) { ctx.r3.u64 = n_sub_83256F20(ctx, base); }

uint64_t n_sub_83256F60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DCC_G_ = int32_t(0x83498DCC);
	if (!UseLiftedCode(143, 0x83256F60)) { __imp__sub_83256F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256F60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DCC_G_, (int64_t)str_TXT_820C0000_B_ + 6560, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256F60, 0x83256F60) { ctx.r3.u64 = n_sub_83256F60(ctx, base); }

uint64_t n_sub_83256FA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DD0_G_ = int32_t(0x83498DD0);
	if (!UseLiftedCode(143, 0x83256FA0)) { __imp__sub_83256FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256FA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DD0_G_, (int64_t)str_TXT_820C0000_B_ + 6576, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256FA0, 0x83256FA0) { ctx.r3.u64 = n_sub_83256FA0(ctx, base); }

uint64_t n_sub_83256FE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DD4_G_ = int32_t(0x83498DD4);
	if (!UseLiftedCode(143, 0x83256FE0)) { __imp__sub_83256FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256FE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DD4_G_, (int64_t)str_TXT_820B0000_B_ - 17088, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83256FE0, 0x83256FE0) { ctx.r3.u64 = n_sub_83256FE0(ctx, base); }

uint64_t n_sub_83257020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498DD8_G_ = int32_t(0x83498DD8);
	if (!UseLiftedCode(143, 0x83257020)) { __imp__sub_83257020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257020);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DD8_G_, (int64_t)str_TXT_820B0000_B_ - 17080, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257020, 0x83257020) { ctx.r3.u64 = n_sub_83257020(ctx, base); }

uint64_t n_sub_83257558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E44_G_ = int32_t(0x83498E44);
	if (!UseLiftedCode(143, 0x83257558)) { __imp__sub_83257558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E44_G_, (int64_t)str_TXT_820C0000_B_ + 6752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257558, 0x83257558) { ctx.r3.u64 = n_sub_83257558(ctx, base); }

uint64_t n_sub_83257598(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E48_G_ = int32_t(0x83498E48);
	if (!UseLiftedCode(143, 0x83257598)) { __imp__sub_83257598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257598);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E48_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257598, 0x83257598) { ctx.r3.u64 = n_sub_83257598(ctx, base); }

uint64_t n_sub_832575D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E4C_G_ = int32_t(0x83498E4C);
	if (!UseLiftedCode(143, 0x832575D8)) { __imp__sub_832575D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832575D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E4C_G_, (int64_t)str_TXT_820C0000_B_ + 6780, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832575D8, 0x832575D8) { ctx.r3.u64 = n_sub_832575D8(ctx, base); }

uint64_t n_sub_83257618(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E50_G_ = int32_t(0x83498E50);
	if (!UseLiftedCode(143, 0x83257618)) { __imp__sub_83257618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257618);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E50_G_, (int64_t)str_TXT_820C0000_B_ + 6840, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257618, 0x83257618) { ctx.r3.u64 = n_sub_83257618(ctx, base); }

uint64_t n_sub_83257658(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E54_G_ = int32_t(0x83498E54);
	if (!UseLiftedCode(143, 0x83257658)) { __imp__sub_83257658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257658);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E54_G_, (int64_t)str_TXT_820C0000_B_ + 6876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257658, 0x83257658) { ctx.r3.u64 = n_sub_83257658(ctx, base); }

uint64_t n_sub_83257698(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E58_G_ = int32_t(0x83498E58);
	if (!UseLiftedCode(143, 0x83257698)) { __imp__sub_83257698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257698);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E58_G_, (int64_t)str_TXT_820C0000_B_ + 6912, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257698, 0x83257698) { ctx.r3.u64 = n_sub_83257698(ctx, base); }

uint64_t n_sub_832576D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E5C_G_ = int32_t(0x83498E5C);
	if (!UseLiftedCode(143, 0x832576D8)) { __imp__sub_832576D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832576D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E5C_G_, (int64_t)str_TXT_820C0000_B_ + 6944, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832576D8, 0x832576D8) { ctx.r3.u64 = n_sub_832576D8(ctx, base); }

uint64_t n_sub_83257718(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E60_G_ = int32_t(0x83498E60);
	if (!UseLiftedCode(143, 0x83257718)) { __imp__sub_83257718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257718);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E60_G_, (int64_t)str_TXT_820C0000_B_ + 6976, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257718, 0x83257718) { ctx.r3.u64 = n_sub_83257718(ctx, base); }

uint64_t n_sub_83257758(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E64_G_ = int32_t(0x83498E64);
	if (!UseLiftedCode(143, 0x83257758)) { __imp__sub_83257758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257758);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E64_G_, (int64_t)str_TXT_820C0000_B_ + 7020, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257758, 0x83257758) { ctx.r3.u64 = n_sub_83257758(ctx, base); }

uint64_t n_sub_83257798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E68_G_ = int32_t(0x83498E68);
	if (!UseLiftedCode(143, 0x83257798)) { __imp__sub_83257798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257798);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E68_G_, (int64_t)str_TXT_820C0000_B_ + 7064, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257798, 0x83257798) { ctx.r3.u64 = n_sub_83257798(ctx, base); }

uint64_t n_sub_832577D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E6C_G_ = int32_t(0x83498E6C);
	if (!UseLiftedCode(143, 0x832577D8)) { __imp__sub_832577D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832577D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E6C_G_, (int64_t)str_TXT_820C0000_B_ + 7108, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832577D8, 0x832577D8) { ctx.r3.u64 = n_sub_832577D8(ctx, base); }

uint64_t n_sub_83257818(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E70_G_ = int32_t(0x83498E70);
	if (!UseLiftedCode(143, 0x83257818)) { __imp__sub_83257818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257818);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E70_G_, (int64_t)str_TXT_820C0000_B_ + 7148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257818, 0x83257818) { ctx.r3.u64 = n_sub_83257818(ctx, base); }

uint64_t n_sub_83257858(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E74_G_ = int32_t(0x83498E74);
	if (!UseLiftedCode(143, 0x83257858)) { __imp__sub_83257858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257858);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E74_G_, (int64_t)str_TXT_820C0000_B_ + 7188, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257858, 0x83257858) { ctx.r3.u64 = n_sub_83257858(ctx, base); }

uint64_t n_sub_83257898(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E78_G_ = int32_t(0x83498E78);
	if (!UseLiftedCode(143, 0x83257898)) { __imp__sub_83257898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E78_G_, (int64_t)str_TXT_820C0000_B_ + 7232, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257898, 0x83257898) { ctx.r3.u64 = n_sub_83257898(ctx, base); }

uint64_t n_sub_832578D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E7C_G_ = int32_t(0x83498E7C);
	if (!UseLiftedCode(143, 0x832578D8)) { __imp__sub_832578D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832578D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E7C_G_, (int64_t)str_TXT_820C0000_B_ + 7276, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832578D8, 0x832578D8) { ctx.r3.u64 = n_sub_832578D8(ctx, base); }

uint64_t n_sub_83257918(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498E80_G_ = int32_t(0x83498E80);
	if (!UseLiftedCode(143, 0x83257918)) { __imp__sub_83257918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257918);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E80_G_, (int64_t)str_TXT_820C0000_B_ + 1264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257918, 0x83257918) { ctx.r3.u64 = n_sub_83257918(ctx, base); }

uint64_t n_sub_83257DF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498ED8_G_ = int32_t(0x83498ED8);
	if (!UseLiftedCode(143, 0x83257DF0)) { __imp__sub_83257DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257DF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498ED8_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83257DF0, 0x83257DF0) { ctx.r3.u64 = n_sub_83257DF0(ctx, base); }

uint64_t n_sub_832582C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F30_G_ = int32_t(0x83498F30);
	if (!UseLiftedCode(143, 0x832582C8)) { __imp__sub_832582C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832582C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F30_G_, (int64_t)str_TXT_820C0000_B_ - 308, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832582C8, 0x832582C8) { ctx.r3.u64 = n_sub_832582C8(ctx, base); }

uint64_t n_sub_83258308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F34_G_ = int32_t(0x83498F34);
	if (!UseLiftedCode(143, 0x83258308)) { __imp__sub_83258308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F34_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258308, 0x83258308) { ctx.r3.u64 = n_sub_83258308(ctx, base); }

uint64_t n_sub_83258348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F38_G_ = int32_t(0x83498F38);
	if (!UseLiftedCode(143, 0x83258348)) { __imp__sub_83258348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F38_G_, (int64_t)str_TXT_820C0000_B_ + 7716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258348, 0x83258348) { ctx.r3.u64 = n_sub_83258348(ctx, base); }

uint64_t n_sub_83258388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F3C_G_ = int32_t(0x83498F3C);
	if (!UseLiftedCode(143, 0x83258388)) { __imp__sub_83258388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F3C_G_, (int64_t)str_TXT_820C0000_B_ + 7752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258388, 0x83258388) { ctx.r3.u64 = n_sub_83258388(ctx, base); }

uint64_t n_sub_832583C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F40_G_ = int32_t(0x83498F40);
	if (!UseLiftedCode(143, 0x832583C8)) { __imp__sub_832583C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832583C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F40_G_, (int64_t)str_TXT_820C0000_B_ + 7784, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832583C8, 0x832583C8) { ctx.r3.u64 = n_sub_832583C8(ctx, base); }

uint64_t n_sub_83258408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F44_G_ = int32_t(0x83498F44);
	if (!UseLiftedCode(143, 0x83258408)) { __imp__sub_83258408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F44_G_, (int64_t)str_TXT_820C0000_B_ + 7816, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 16992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258408, 0x83258408) { ctx.r3.u64 = n_sub_83258408(ctx, base); }

uint64_t n_sub_83258448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F48_G_ = int32_t(0x83498F48);
	if (!UseLiftedCode(143, 0x83258448)) { __imp__sub_83258448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F48_G_, (int64_t)str_TXT_820C0000_B_ + 7852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258448, 0x83258448) { ctx.r3.u64 = n_sub_83258448(ctx, base); }

uint64_t n_sub_83258488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F4C_G_ = int32_t(0x83498F4C);
	if (!UseLiftedCode(143, 0x83258488)) { __imp__sub_83258488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F4C_G_, (int64_t)str_TXT_820C0000_B_ + 8932, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258488, 0x83258488) { ctx.r3.u64 = n_sub_83258488(ctx, base); }

uint64_t n_sub_832584C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F50_G_ = int32_t(0x83498F50);
	if (!UseLiftedCode(143, 0x832584C8)) { __imp__sub_832584C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832584C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F50_G_, (int64_t)str_TXT_820C0000_B_ + 8972, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832584C8, 0x832584C8) { ctx.r3.u64 = n_sub_832584C8(ctx, base); }

uint64_t n_sub_83258508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F54_G_ = int32_t(0x83498F54);
	if (!UseLiftedCode(143, 0x83258508)) { __imp__sub_83258508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F54_G_, (int64_t)str_TXT_820C0000_B_ + 9000, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258508, 0x83258508) { ctx.r3.u64 = n_sub_83258508(ctx, base); }

uint64_t n_sub_83258548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F58_G_ = int32_t(0x83498F58);
	if (!UseLiftedCode(143, 0x83258548)) { __imp__sub_83258548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F58_G_, (int64_t)str_TXT_820C0000_B_ + 12588, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258548, 0x83258548) { ctx.r3.u64 = n_sub_83258548(ctx, base); }

uint64_t n_sub_83258588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F5C_G_ = int32_t(0x83498F5C);
	if (!UseLiftedCode(143, 0x83258588)) { __imp__sub_83258588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F5C_G_, (int64_t)str_TXT_820C0000_B_ + 13808, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258588, 0x83258588) { ctx.r3.u64 = n_sub_83258588(ctx, base); }

uint64_t n_sub_832585C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F60_G_ = int32_t(0x83498F60);
	if (!UseLiftedCode(143, 0x832585C8)) { __imp__sub_832585C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832585C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F60_G_, (int64_t)str_TXT_820C0000_B_ + 13816, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832585C8, 0x832585C8) { ctx.r3.u64 = n_sub_832585C8(ctx, base); }

uint64_t n_sub_83258608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F64_G_ = int32_t(0x83498F64);
	if (!UseLiftedCode(143, 0x83258608)) { __imp__sub_83258608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F64_G_, (int64_t)str_TXT_820C0000_B_ + 13832, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258608, 0x83258608) { ctx.r3.u64 = n_sub_83258608(ctx, base); }

uint64_t n_sub_832586D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F74_G_ = int32_t(0x83498F74);
	if (!UseLiftedCode(143, 0x832586D8)) { __imp__sub_832586D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832586D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F74_G_, (int64_t)str_TXT_820C0000_B_ + 22340, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832586D8, 0x832586D8) { ctx.r3.u64 = n_sub_832586D8(ctx, base); }

uint64_t n_sub_83258718(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F78_G_ = int32_t(0x83498F78);
	if (!UseLiftedCode(143, 0x83258718)) { __imp__sub_83258718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258718);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F78_G_, (int64_t)str_TXT_820C0000_B_ + 22348, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258718, 0x83258718) { ctx.r3.u64 = n_sub_83258718(ctx, base); }

uint64_t n_sub_83258758(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F7C_G_ = int32_t(0x83498F7C);
	if (!UseLiftedCode(143, 0x83258758)) { __imp__sub_83258758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258758);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F7C_G_, (int64_t)str_TXT_820C0000_B_ + 22356, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258758, 0x83258758) { ctx.r3.u64 = n_sub_83258758(ctx, base); }

uint64_t n_sub_83258798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F80_G_ = int32_t(0x83498F80);
	if (!UseLiftedCode(143, 0x83258798)) { __imp__sub_83258798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258798);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F80_G_, (int64_t)str_TXT_820C0000_B_ + 22364, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258798, 0x83258798) { ctx.r3.u64 = n_sub_83258798(ctx, base); }

uint64_t n_sub_832587D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F84_G_ = int32_t(0x83498F84);
	if (!UseLiftedCode(143, 0x832587D8)) { __imp__sub_832587D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832587D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F84_G_, (int64_t)str_TXT_820C0000_B_ + 22372, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832587D8, 0x832587D8) { ctx.r3.u64 = n_sub_832587D8(ctx, base); }

uint64_t n_sub_83258818(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F88_G_ = int32_t(0x83498F88);
	if (!UseLiftedCode(143, 0x83258818)) { __imp__sub_83258818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258818);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F88_G_, (int64_t)str_TXT_820C0000_B_ + 22380, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258818, 0x83258818) { ctx.r3.u64 = n_sub_83258818(ctx, base); }

uint64_t n_sub_83258858(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F8C_G_ = int32_t(0x83498F8C);
	if (!UseLiftedCode(143, 0x83258858)) { __imp__sub_83258858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258858);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F8C_G_, (int64_t)str_TXT_820C0000_B_ + 22388, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258858, 0x83258858) { ctx.r3.u64 = n_sub_83258858(ctx, base); }

uint64_t n_sub_83258898(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F90_G_ = int32_t(0x83498F90);
	if (!UseLiftedCode(143, 0x83258898)) { __imp__sub_83258898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F90_G_, (int64_t)str_TXT_820C0000_B_ + 22396, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258898, 0x83258898) { ctx.r3.u64 = n_sub_83258898(ctx, base); }

uint64_t n_sub_832588D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F94_G_ = int32_t(0x83498F94);
	if (!UseLiftedCode(143, 0x832588D8)) { __imp__sub_832588D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832588D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F94_G_, (int64_t)str_TXT_820C0000_B_ + 22412, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832588D8, 0x832588D8) { ctx.r3.u64 = n_sub_832588D8(ctx, base); }

uint64_t n_sub_83258918(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F98_G_ = int32_t(0x83498F98);
	if (!UseLiftedCode(143, 0x83258918)) { __imp__sub_83258918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258918);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F98_G_, (int64_t)str_TXT_820C0000_B_ + 22428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258918, 0x83258918) { ctx.r3.u64 = n_sub_83258918(ctx, base); }

uint64_t n_sub_83258958(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498F9C_G_ = int32_t(0x83498F9C);
	if (!UseLiftedCode(143, 0x83258958)) { __imp__sub_83258958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258958);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F9C_G_, (int64_t)str_TXT_820C0000_B_ + 22436, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258958, 0x83258958) { ctx.r3.u64 = n_sub_83258958(ctx, base); }

uint64_t n_sub_83258998(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FA0_G_ = int32_t(0x83498FA0);
	if (!UseLiftedCode(143, 0x83258998)) { __imp__sub_83258998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258998);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FA0_G_, (int64_t)str_TXT_820C0000_B_ + 22444, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258998, 0x83258998) { ctx.r3.u64 = n_sub_83258998(ctx, base); }

uint64_t n_sub_832589D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FA4_G_ = int32_t(0x83498FA4);
	if (!UseLiftedCode(143, 0x832589D8)) { __imp__sub_832589D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832589D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FA4_G_, (int64_t)str_TXT_820C0000_B_ + 22456, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832589D8, 0x832589D8) { ctx.r3.u64 = n_sub_832589D8(ctx, base); }

uint64_t n_sub_83258A18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FA8_G_ = int32_t(0x83498FA8);
	if (!UseLiftedCode(143, 0x83258A18)) { __imp__sub_83258A18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258A18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FA8_G_, (int64_t)g_820A0000 + 25268, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258A18, 0x83258A18) { ctx.r3.u64 = n_sub_83258A18(ctx, base); }

uint64_t n_sub_83258A58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FAC_G_ = int32_t(0x83498FAC);
	if (!UseLiftedCode(143, 0x83258A58)) { __imp__sub_83258A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258A58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FAC_G_, (int64_t)str_TXT_820C0000_B_ + 22464, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258A58, 0x83258A58) { ctx.r3.u64 = n_sub_83258A58(ctx, base); }

uint64_t n_sub_83258A98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FB0_G_ = int32_t(0x83498FB0);
	if (!UseLiftedCode(143, 0x83258A98)) { __imp__sub_83258A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258A98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FB0_G_, (int64_t)str_TXT_820B0000_B_ - 32620, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258A98, 0x83258A98) { ctx.r3.u64 = n_sub_83258A98(ctx, base); }

uint64_t n_sub_83258AD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FB4_G_ = int32_t(0x83498FB4);
	if (!UseLiftedCode(143, 0x83258AD8)) { __imp__sub_83258AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258AD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FB4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258AD8, 0x83258AD8) { ctx.r3.u64 = n_sub_83258AD8(ctx, base); }

uint64_t n_sub_83258B18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FB8_G_ = int32_t(0x83498FB8);
	if (!UseLiftedCode(143, 0x83258B18)) { __imp__sub_83258B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258B18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FB8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258B18, 0x83258B18) { ctx.r3.u64 = n_sub_83258B18(ctx, base); }

uint64_t n_sub_83258B58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FBC_G_ = int32_t(0x83498FBC);
	if (!UseLiftedCode(143, 0x83258B58)) { __imp__sub_83258B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258B58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FBC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258B58, 0x83258B58) { ctx.r3.u64 = n_sub_83258B58(ctx, base); }

uint64_t n_sub_83258C50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FDC_G_ = int32_t(0x83498FDC);
	if (!UseLiftedCode(143, 0x83258C50)) { __imp__sub_83258C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258C50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FDC_G_, (int64_t)str_TXT_820C0000_B_ + 26184, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258C50, 0x83258C50) { ctx.r3.u64 = n_sub_83258C50(ctx, base); }

uint64_t n_sub_83258C90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FE0_G_ = int32_t(0x83498FE0);
	if (!UseLiftedCode(143, 0x83258C90)) { __imp__sub_83258C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258C90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FE0_G_, (int64_t)str_TXT_820C0000_B_ + 26208, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258C90, 0x83258C90) { ctx.r3.u64 = n_sub_83258C90(ctx, base); }

uint64_t n_sub_83258CD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FE4_G_ = int32_t(0x83498FE4);
	if (!UseLiftedCode(143, 0x83258CD0)) { __imp__sub_83258CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258CD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FE4_G_, (int64_t)str_TXT_820C0000_B_ + 26228, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258CD0, 0x83258CD0) { ctx.r3.u64 = n_sub_83258CD0(ctx, base); }

uint64_t n_sub_83258D10(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83258D10)) { ctx.r8.u64 = arg1; __imp__sub_83258D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258D10);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17840, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83258D10, 0x83258D10) { ctx.r3.u64 = n_sub_83258D10(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83258D20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FF0_G_ = int32_t(0x83498FF0);
	if (!UseLiftedCode(143, 0x83258D20)) { __imp__sub_83258D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258D20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FF0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258D20, 0x83258D20) { ctx.r3.u64 = n_sub_83258D20(ctx, base); }

uint64_t n_sub_83258D60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FF4_G_ = int32_t(0x83498FF4);
	if (!UseLiftedCode(143, 0x83258D60)) { __imp__sub_83258D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258D60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FF4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258D60, 0x83258D60) { ctx.r3.u64 = n_sub_83258D60(ctx, base); }

uint64_t n_sub_83258DA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FF8_G_ = int32_t(0x83498FF8);
	if (!UseLiftedCode(143, 0x83258DA0)) { __imp__sub_83258DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258DA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FF8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258DA0, 0x83258DA0) { ctx.r3.u64 = n_sub_83258DA0(ctx, base); }

uint64_t n_sub_83258DE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498FFC_G_ = int32_t(0x83498FFC);
	if (!UseLiftedCode(143, 0x83258DE0)) { __imp__sub_83258DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258DE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FFC_G_, (int64_t)str_TXT_820C0000_B_ + 27512, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258DE0, 0x83258DE0) { ctx.r3.u64 = n_sub_83258DE0(ctx, base); }

uint64_t n_sub_83258E20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83499000_G_ = int32_t(0x83499000);
	if (!UseLiftedCode(143, 0x83258E20)) { __imp__sub_83258E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258E20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83499000_G_, (int64_t)str_TXT_820C0000_B_ + 29108, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258E20, 0x83258E20) { ctx.r3.u64 = n_sub_83258E20(ctx, base); }

uint64_t n_sub_83258E60(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83258E60)) { ctx.r8.u64 = arg1; __imp__sub_83258E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258E60);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 17936, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83258E60, 0x83258E60) { ctx.r3.u64 = n_sub_83258E60(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83259960(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AA40_G_ = int32_t(0x8349AA40);
	if (!UseLiftedCode(143, 0x83259960)) { __imp__sub_83259960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259960);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA40_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259960, 0x83259960) { ctx.r3.u64 = n_sub_83259960(ctx, base); }

uint64_t n_sub_832599A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AA44_G_ = int32_t(0x8349AA44);
	if (!UseLiftedCode(143, 0x832599A0)) { __imp__sub_832599A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832599A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA44_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832599A0, 0x832599A0) { ctx.r3.u64 = n_sub_832599A0(ctx, base); }

uint64_t n_sub_832599E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AA48_G_ = int32_t(0x8349AA48);
	if (!UseLiftedCode(143, 0x832599E0)) { __imp__sub_832599E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832599E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA48_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832599E0, 0x832599E0) { ctx.r3.u64 = n_sub_832599E0(ctx, base); }

uint64_t n_sub_83259A20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AA4C_G_ = int32_t(0x8349AA4C);
	if (!UseLiftedCode(143, 0x83259A20)) { __imp__sub_83259A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259A20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA4C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259A20, 0x83259A20) { ctx.r3.u64 = n_sub_83259A20(ctx, base); }

uint64_t n_sub_83259A60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AA50_G_ = int32_t(0x8349AA50);
	if (!UseLiftedCode(143, 0x83259A60)) { __imp__sub_83259A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259A60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA50_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259A60, 0x83259A60) { ctx.r3.u64 = n_sub_83259A60(ctx, base); }

uint64_t n_sub_83259AA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AA54_G_ = int32_t(0x8349AA54);
	if (!UseLiftedCode(143, 0x83259AA0)) { __imp__sub_83259AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259AA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA54_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259AA0, 0x83259AA0) { ctx.r3.u64 = n_sub_83259AA0(ctx, base); }

uint64_t n_sub_83259B38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83259B38)) { ctx.r8.u64 = arg1; __imp__sub_83259B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259B38);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19192, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83259B38, 0x83259B38) { ctx.r3.u64 = n_sub_83259B38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83259B60(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83259B60)) { ctx.r8.u64 = arg1; __imp__sub_83259B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259B60);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19208, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83259B60, 0x83259B60) { ctx.r3.u64 = n_sub_83259B60(ctx, base, ctx.r8.u64); }

// sub_83259BD0  [64 bytes]
uint64_t n_sub_83259BD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD2C_G_ = int32_t(0x8349AD2C);
	if (!UseLiftedCode(143, 0x83259BD0)) { __imp__sub_83259BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259BD0);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD2C_G_, (int64_t)str_TXT_820D0000_B_ - 25864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259BD0, 0x83259BD0) { ctx.r3.u64 = n_sub_83259BD0(ctx, base); }

uint64_t n_sub_83259C88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD5C_G_ = int32_t(0x8349AD5C);
	if (!UseLiftedCode(143, 0x83259C88)) { __imp__sub_83259C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259C88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD5C_G_, (int64_t)str_TXT_820D0000_B_ - 25032, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259C88, 0x83259C88) { ctx.r3.u64 = n_sub_83259C88(ctx, base); }

uint64_t n_sub_83259CC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD80_G_ = int32_t(0x8349AD80);
	if (!UseLiftedCode(143, 0x83259CC8)) { __imp__sub_83259CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259CC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD80_G_, (int64_t)str_TXT_820D0000_B_ - 25020, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259CC8, 0x83259CC8) { ctx.r3.u64 = n_sub_83259CC8(ctx, base); }

uint64_t n_sub_83259D08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD84_G_ = int32_t(0x8349AD84);
	if (!UseLiftedCode(143, 0x83259D08)) { __imp__sub_83259D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259D08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD84_G_, (int64_t)str_TXT_820D0000_B_ - 25012, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259D08, 0x83259D08) { ctx.r3.u64 = n_sub_83259D08(ctx, base); }

uint64_t n_sub_83259D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD88_G_ = int32_t(0x8349AD88);
	if (!UseLiftedCode(143, 0x83259D48)) { __imp__sub_83259D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259D48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD88_G_, (int64_t)str_TXT_820D0000_B_ - 25004, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259D48, 0x83259D48) { ctx.r3.u64 = n_sub_83259D48(ctx, base); }

uint64_t n_sub_83259D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD8C_G_ = int32_t(0x8349AD8C);
	if (!UseLiftedCode(143, 0x83259D88)) { __imp__sub_83259D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD8C_G_, (int64_t)str_TXT_820D0000_B_ - 24988, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259D88, 0x83259D88) { ctx.r3.u64 = n_sub_83259D88(ctx, base); }

uint64_t n_sub_83259DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD90_G_ = int32_t(0x8349AD90);
	if (!UseLiftedCode(143, 0x83259DC8)) { __imp__sub_83259DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD90_G_, (int64_t)str_TXT_820D0000_B_ - 24968, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259DC8, 0x83259DC8) { ctx.r3.u64 = n_sub_83259DC8(ctx, base); }

uint64_t n_sub_83259E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD94_G_ = int32_t(0x8349AD94);
	if (!UseLiftedCode(143, 0x83259E08)) { __imp__sub_83259E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD94_G_, (int64_t)str_TXT_820D0000_B_ - 24948, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259E08, 0x83259E08) { ctx.r3.u64 = n_sub_83259E08(ctx, base); }

uint64_t n_sub_83259E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AD98_G_ = int32_t(0x8349AD98);
	if (!UseLiftedCode(143, 0x83259E48)) { __imp__sub_83259E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259E48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD98_G_, (int64_t)str_TXT_820D0000_B_ - 24928, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259E48, 0x83259E48) { ctx.r3.u64 = n_sub_83259E48(ctx, base); }

uint64_t n_sub_8325A098(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8325A098)) { ctx.r8.u64 = arg1; __imp__sub_8325A098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A098);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19648, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8325A098, 0x8325A098) { ctx.r3.u64 = n_sub_8325A098(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325A180(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349ADDC_G_ = int32_t(0x8349ADDC);
	if (!UseLiftedCode(143, 0x8325A180)) { __imp__sub_8325A180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A180);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349ADDC_G_, (int64_t)str_TXT_820D0000_B_ - 25864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A180, 0x8325A180) { ctx.r3.u64 = n_sub_8325A180(ctx, base); }

uint64_t n_sub_8325A1C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8325A1C0)) { ctx.r8.u64 = arg1; __imp__sub_8325A1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A1C0);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19896, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8325A1C0, 0x8325A1C0) { ctx.r3.u64 = n_sub_8325A1C0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325A1D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE18_G_ = int32_t(0x8349AE18);
	if (!UseLiftedCode(143, 0x8325A1D0)) { __imp__sub_8325A1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A1D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE18_G_, (int64_t)str_TXT_820C0000_B_ + 22264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A1D0, 0x8325A1D0) { ctx.r3.u64 = n_sub_8325A1D0(ctx, base); }

uint64_t n_sub_8325A210(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8325A210)) { ctx.r8.u64 = arg1; __imp__sub_8325A210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A210);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 19928, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8325A210, 0x8325A210) { ctx.r3.u64 = n_sub_8325A210(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325A220(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8325A220)) { ctx.r8.u64 = arg1; __imp__sub_8325A220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A220);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20032, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8325A220, 0x8325A220) { ctx.r3.u64 = n_sub_8325A220(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325A230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE3C_G_ = int32_t(0x8349AE3C);
	if (!UseLiftedCode(143, 0x8325A230)) { __imp__sub_8325A230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE3C_G_, (int64_t)str_TXT_820D0000_B_ - 22584, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A230, 0x8325A230) { ctx.r3.u64 = n_sub_8325A230(ctx, base); }

uint64_t n_sub_8325A270(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE40_G_ = int32_t(0x8349AE40);
	if (!UseLiftedCode(143, 0x8325A270)) { __imp__sub_8325A270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A270);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE40_G_, (int64_t)str_TXT_820D0000_B_ - 21668, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A270, 0x8325A270) { ctx.r3.u64 = n_sub_8325A270(ctx, base); }

uint64_t n_sub_8325A2B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE44_G_ = int32_t(0x8349AE44);
	if (!UseLiftedCode(143, 0x8325A2B0)) { __imp__sub_8325A2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A2B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE44_G_, (int64_t)str_TXT_820B0000_B_ - 32620, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A2B0, 0x8325A2B0) { ctx.r3.u64 = n_sub_8325A2B0(ctx, base); }

uint64_t n_sub_8325A2F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE48_G_ = int32_t(0x8349AE48);
	if (!UseLiftedCode(143, 0x8325A2F0)) { __imp__sub_8325A2F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A2F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE48_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A2F0, 0x8325A2F0) { ctx.r3.u64 = n_sub_8325A2F0(ctx, base); }

uint64_t n_sub_8325A330(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE4C_G_ = int32_t(0x8349AE4C);
	if (!UseLiftedCode(143, 0x8325A330)) { __imp__sub_8325A330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A330);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE4C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A330, 0x8325A330) { ctx.r3.u64 = n_sub_8325A330(ctx, base); }

uint64_t n_sub_8325A370(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE50_G_ = int32_t(0x8349AE50);
	if (!UseLiftedCode(143, 0x8325A370)) { __imp__sub_8325A370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A370);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE50_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A370, 0x8325A370) { ctx.r3.u64 = n_sub_8325A370(ctx, base); }

uint64_t n_sub_8325A3B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8325A3B0)) { ctx.r8.u64 = arg1; __imp__sub_8325A3B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A3B0);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20232, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8325A3B0, 0x8325A3B0) { ctx.r3.u64 = n_sub_8325A3B0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325A3C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE68_G_ = int32_t(0x8349AE68);
	if (!UseLiftedCode(143, 0x8325A3C0)) { __imp__sub_8325A3C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A3C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE68_G_, (int64_t)str_TXT_820D0000_B_ - 18164, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A3C0, 0x8325A3C0) { ctx.r3.u64 = n_sub_8325A3C0(ctx, base); }

uint64_t n_sub_8325A400(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE6C_G_ = int32_t(0x8349AE6C);
	if (!UseLiftedCode(143, 0x8325A400)) { __imp__sub_8325A400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A400);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE6C_G_, (int64_t)g_82000000 + 3608, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A400, 0x8325A400) { ctx.r3.u64 = n_sub_8325A400(ctx, base); }

uint64_t n_sub_8325A440(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE70_G_ = int32_t(0x8349AE70);
	if (!UseLiftedCode(143, 0x8325A440)) { __imp__sub_8325A440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A440);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE70_G_, (int64_t)str_TXT_820D0000_B_ - 18144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A440, 0x8325A440) { ctx.r3.u64 = n_sub_8325A440(ctx, base); }

uint64_t n_sub_8325A480(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE74_G_ = int32_t(0x8349AE74);
	if (!UseLiftedCode(143, 0x8325A480)) { __imp__sub_8325A480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A480);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE74_G_, (int64_t)str_TXT_820D0000_B_ - 18108, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A480, 0x8325A480) { ctx.r3.u64 = n_sub_8325A480(ctx, base); }

uint64_t n_sub_8325A4C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE78_G_ = int32_t(0x8349AE78);
	if (!UseLiftedCode(143, 0x8325A4C0)) { __imp__sub_8325A4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A4C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE78_G_, (int64_t)str_TXT_820D0000_B_ - 18076, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A4C0, 0x8325A4C0) { ctx.r3.u64 = n_sub_8325A4C0(ctx, base); }

uint64_t n_sub_8325A500(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE7C_G_ = int32_t(0x8349AE7C);
	if (!UseLiftedCode(143, 0x8325A500)) { __imp__sub_8325A500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A500);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE7C_G_, (int64_t)str_TXT_820D0000_B_ - 18020, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A500, 0x8325A500) { ctx.r3.u64 = n_sub_8325A500(ctx, base); }

uint64_t n_sub_8325A540(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE80_G_ = int32_t(0x8349AE80);
	if (!UseLiftedCode(143, 0x8325A540)) { __imp__sub_8325A540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A540);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE80_G_, (int64_t)str_TXT_820D0000_B_ - 17984, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A540, 0x8325A540) { ctx.r3.u64 = n_sub_8325A540(ctx, base); }

uint64_t n_sub_8325A580(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE84_G_ = int32_t(0x8349AE84);
	if (!UseLiftedCode(143, 0x8325A580)) { __imp__sub_8325A580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A580);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE84_G_, (int64_t)str_TXT_820D0000_B_ - 17936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A580, 0x8325A580) { ctx.r3.u64 = n_sub_8325A580(ctx, base); }

uint64_t n_sub_8325A5C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE88_G_ = int32_t(0x8349AE88);
	if (!UseLiftedCode(143, 0x8325A5C0)) { __imp__sub_8325A5C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A5C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE88_G_, (int64_t)str_TXT_820D0000_B_ - 17888, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A5C0, 0x8325A5C0) { ctx.r3.u64 = n_sub_8325A5C0(ctx, base); }

uint64_t n_sub_8325A600(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE8C_G_ = int32_t(0x8349AE8C);
	if (!UseLiftedCode(143, 0x8325A600)) { __imp__sub_8325A600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A600);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE8C_G_, (int64_t)str_TXT_820D0000_B_ - 17852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A600, 0x8325A600) { ctx.r3.u64 = n_sub_8325A600(ctx, base); }

uint64_t n_sub_8325A640(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE90_G_ = int32_t(0x8349AE90);
	if (!UseLiftedCode(143, 0x8325A640)) { __imp__sub_8325A640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A640);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE90_G_, (int64_t)str_TXT_820D0000_B_ - 17808, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A640, 0x8325A640) { ctx.r3.u64 = n_sub_8325A640(ctx, base); }

uint64_t n_sub_8325A680(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE94_G_ = int32_t(0x8349AE94);
	if (!UseLiftedCode(143, 0x8325A680)) { __imp__sub_8325A680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A680);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE94_G_, (int64_t)str_TXT_820D0000_B_ - 17744, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A680, 0x8325A680) { ctx.r3.u64 = n_sub_8325A680(ctx, base); }

uint64_t n_sub_8325A6C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE98_G_ = int32_t(0x8349AE98);
	if (!UseLiftedCode(143, 0x8325A6C0)) { __imp__sub_8325A6C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A6C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE98_G_, (int64_t)str_TXT_820B0000_B_ - 29220, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A6C0, 0x8325A6C0) { ctx.r3.u64 = n_sub_8325A6C0(ctx, base); }

uint64_t n_sub_8325A700(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AE9C_G_ = int32_t(0x8349AE9C);
	if (!UseLiftedCode(143, 0x8325A700)) { __imp__sub_8325A700(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A700);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE9C_G_, (int64_t)str_TXT_820B0000_B_ - 29208, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A700, 0x8325A700) { ctx.r3.u64 = n_sub_8325A700(ctx, base); }

uint64_t n_sub_8325A740(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEA0_G_ = int32_t(0x8349AEA0);
	if (!UseLiftedCode(143, 0x8325A740)) { __imp__sub_8325A740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A740);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEA0_G_, (int64_t)str_TXT_820B0000_B_ - 16424, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A740, 0x8325A740) { ctx.r3.u64 = n_sub_8325A740(ctx, base); }

uint64_t n_sub_8325A780(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEA4_G_ = int32_t(0x8349AEA4);
	if (!UseLiftedCode(143, 0x8325A780)) { __imp__sub_8325A780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A780);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEA4_G_, (int64_t)str_TXT_820B0000_B_ - 16464, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A780, 0x8325A780) { ctx.r3.u64 = n_sub_8325A780(ctx, base); }

uint64_t n_sub_8325A7C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEA8_G_ = int32_t(0x8349AEA8);
	if (!UseLiftedCode(143, 0x8325A7C0)) { __imp__sub_8325A7C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A7C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEA8_G_, (int64_t)str_TXT_820B0000_B_ - 16440, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A7C0, 0x8325A7C0) { ctx.r3.u64 = n_sub_8325A7C0(ctx, base); }

uint64_t n_sub_8325A800(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEAC_G_ = int32_t(0x8349AEAC);
	if (!UseLiftedCode(143, 0x8325A800)) { __imp__sub_8325A800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A800);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEAC_G_, (int64_t)str_TXT_820D0000_B_ - 17684, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A800, 0x8325A800) { ctx.r3.u64 = n_sub_8325A800(ctx, base); }

uint64_t n_sub_8325A840(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEB0_G_ = int32_t(0x8349AEB0);
	if (!UseLiftedCode(143, 0x8325A840)) { __imp__sub_8325A840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A840);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEB0_G_, (int64_t)str_TXT_820D0000_B_ - 17672, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A840, 0x8325A840) { ctx.r3.u64 = n_sub_8325A840(ctx, base); }

uint64_t n_sub_8325A880(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEB4_G_ = int32_t(0x8349AEB4);
	if (!UseLiftedCode(143, 0x8325A880)) { __imp__sub_8325A880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A880);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEB4_G_, (int64_t)str_TXT_820D0000_B_ - 17660, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A880, 0x8325A880) { ctx.r3.u64 = n_sub_8325A880(ctx, base); }

uint64_t n_sub_8325A8C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEB8_G_ = int32_t(0x8349AEB8);
	if (!UseLiftedCode(143, 0x8325A8C0)) { __imp__sub_8325A8C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A8C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEB8_G_, (int64_t)str_TXT_820D0000_B_ - 17648, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A8C0, 0x8325A8C0) { ctx.r3.u64 = n_sub_8325A8C0(ctx, base); }

uint64_t n_sub_8325A900(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEBC_G_ = int32_t(0x8349AEBC);
	if (!UseLiftedCode(143, 0x8325A900)) { __imp__sub_8325A900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A900);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEBC_G_, (int64_t)str_TXT_820D0000_B_ - 17636, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A900, 0x8325A900) { ctx.r3.u64 = n_sub_8325A900(ctx, base); }

uint64_t n_sub_8325A940(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AEC0_G_ = int32_t(0x8349AEC0);
	if (!UseLiftedCode(143, 0x8325A940)) { __imp__sub_8325A940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A940);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEC0_G_, (int64_t)str_TXT_820D0000_B_ - 17612, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A940, 0x8325A940) { ctx.r3.u64 = n_sub_8325A940(ctx, base); }

uint64_t n_sub_8325A9F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AED0_G_ = int32_t(0x8349AED0);
	if (!UseLiftedCode(143, 0x8325A9F0)) { __imp__sub_8325A9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A9F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AED0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A9F0, 0x8325A9F0) { ctx.r3.u64 = n_sub_8325A9F0(ctx, base); }

uint64_t n_sub_8325AA30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AED4_G_ = int32_t(0x8349AED4);
	if (!UseLiftedCode(143, 0x8325AA30)) { __imp__sub_8325AA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AA30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AED4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325AA30, 0x8325AA30) { ctx.r3.u64 = n_sub_8325AA30(ctx, base); }

uint64_t n_sub_8325AA70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AED8_G_ = int32_t(0x8349AED8);
	if (!UseLiftedCode(143, 0x8325AA70)) { __imp__sub_8325AA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AA70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AED8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 20752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325AA70, 0x8325AA70) { ctx.r3.u64 = n_sub_8325AA70(ctx, base); }

uint64_t n_sub_8325ADF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AF98_G_ = int32_t(0x8349AF98);
	if (!UseLiftedCode(143, 0x8325ADF0)) { __imp__sub_8325ADF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ADF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AF98_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325ADF0, 0x8325ADF0) { ctx.r3.u64 = n_sub_8325ADF0(ctx, base); }

uint64_t n_sub_8325AE30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AF9C_G_ = int32_t(0x8349AF9C);
	if (!UseLiftedCode(143, 0x8325AE30)) { __imp__sub_8325AE30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AE30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AF9C_G_, (int64_t)str_TXT_820D0000_B_ - 12160, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325AE30, 0x8325AE30) { ctx.r3.u64 = n_sub_8325AE30(ctx, base); }

uint64_t n_sub_8325AF18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AFAC_G_ = int32_t(0x8349AFAC);
	if (!UseLiftedCode(143, 0x8325AF18)) { __imp__sub_8325AF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AF18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AFAC_G_, (int64_t)str_TXT_820D0000_B_ - 12084, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325AF18, 0x8325AF18) { ctx.r3.u64 = n_sub_8325AF18(ctx, base); }

uint64_t n_sub_8325AF58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349AFB0_G_ = int32_t(0x8349AFB0);
	if (!UseLiftedCode(143, 0x8325AF58)) { __imp__sub_8325AF58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AF58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AFB0_G_, (int64_t)str_TXT_820D0000_B_ - 12052, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325AF58, 0x8325AF58) { ctx.r3.u64 = n_sub_8325AF58(ctx, base); }

uint64_t n_sub_8325B758(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B038_G_ = int32_t(0x8349B038);
	if (!UseLiftedCode(143, 0x8325B758)) { __imp__sub_8325B758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B758);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B038_G_, (int64_t)str_TXT_820D0000_B_ - 11868, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325B758, 0x8325B758) { ctx.r3.u64 = n_sub_8325B758(ctx, base); }

uint64_t n_sub_8325B798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B03C_G_ = int32_t(0x8349B03C);
	if (!UseLiftedCode(143, 0x8325B798)) { __imp__sub_8325B798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B798);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B03C_G_, (int64_t)str_TXT_820B0000_B_ + 17852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325B798, 0x8325B798) { ctx.r3.u64 = n_sub_8325B798(ctx, base); }

uint64_t n_sub_8325B7D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B040_G_ = int32_t(0x8349B040);
	if (!UseLiftedCode(143, 0x8325B7D8)) { __imp__sub_8325B7D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B7D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B040_G_, (int64_t)str_TXT_820B0000_B_ + 17864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325B7D8, 0x8325B7D8) { ctx.r3.u64 = n_sub_8325B7D8(ctx, base); }

uint64_t n_sub_8325B818(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B044_G_ = int32_t(0x8349B044);
	if (!UseLiftedCode(143, 0x8325B818)) { __imp__sub_8325B818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B818);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B044_G_, (int64_t)str_TXT_820D0000_B_ - 12052, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325B818, 0x8325B818) { ctx.r3.u64 = n_sub_8325B818(ctx, base); }

uint64_t n_sub_8325BB68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B088_G_ = int32_t(0x8349B088);
	if (!UseLiftedCode(143, 0x8325BB68)) { __imp__sub_8325BB68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BB68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B088_G_, (int64_t)str_TXT_820C0000_B_ - 308, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BB68, 0x8325BB68) { ctx.r3.u64 = n_sub_8325BB68(ctx, base); }

uint64_t n_sub_8325BBA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B08C_G_ = int32_t(0x8349B08C);
	if (!UseLiftedCode(143, 0x8325BBA8)) { __imp__sub_8325BBA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BBA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B08C_G_, (int64_t)str_TXT_820D0000_B_ - 11828, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BBA8, 0x8325BBA8) { ctx.r3.u64 = n_sub_8325BBA8(ctx, base); }

uint64_t n_sub_8325BBE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B090_G_ = int32_t(0x8349B090);
	if (!UseLiftedCode(143, 0x8325BBE8)) { __imp__sub_8325BBE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BBE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B090_G_, (int64_t)str_TXT_820D0000_B_ - 11796, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BBE8, 0x8325BBE8) { ctx.r3.u64 = n_sub_8325BBE8(ctx, base); }

uint64_t n_sub_8325BC28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B094_G_ = int32_t(0x8349B094);
	if (!UseLiftedCode(143, 0x8325BC28)) { __imp__sub_8325BC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BC28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B094_G_, (int64_t)str_TXT_820D0000_B_ - 11760, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BC28, 0x8325BC28) { ctx.r3.u64 = n_sub_8325BC28(ctx, base); }

uint64_t n_sub_8325BC68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B098_G_ = int32_t(0x8349B098);
	if (!UseLiftedCode(143, 0x8325BC68)) { __imp__sub_8325BC68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BC68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B098_G_, (int64_t)str_TXT_820B0000_B_ - 32420, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BC68, 0x8325BC68) { ctx.r3.u64 = n_sub_8325BC68(ctx, base); }

uint64_t n_sub_8325BCA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B09C_G_ = int32_t(0x8349B09C);
	if (!UseLiftedCode(143, 0x8325BCA8)) { __imp__sub_8325BCA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BCA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B09C_G_, (int64_t)str_TXT_820D0000_B_ - 11724, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BCA8, 0x8325BCA8) { ctx.r3.u64 = n_sub_8325BCA8(ctx, base); }

uint64_t n_sub_8325BCE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0A0_G_ = int32_t(0x8349B0A0);
	if (!UseLiftedCode(143, 0x8325BCE8)) { __imp__sub_8325BCE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BCE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0A0_G_, (int64_t)str_TXT_820D0000_B_ - 11692, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BCE8, 0x8325BCE8) { ctx.r3.u64 = n_sub_8325BCE8(ctx, base); }

uint64_t n_sub_8325BD28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0A4_G_ = int32_t(0x8349B0A4);
	if (!UseLiftedCode(143, 0x8325BD28)) { __imp__sub_8325BD28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BD28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0A4_G_, (int64_t)str_TXT_820D0000_B_ - 11660, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BD28, 0x8325BD28) { ctx.r3.u64 = n_sub_8325BD28(ctx, base); }

uint64_t n_sub_8325BD68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0A8_G_ = int32_t(0x8349B0A8);
	if (!UseLiftedCode(143, 0x8325BD68)) { __imp__sub_8325BD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BD68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0A8_G_, (int64_t)str_TXT_820D0000_B_ - 11624, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BD68, 0x8325BD68) { ctx.r3.u64 = n_sub_8325BD68(ctx, base); }

uint64_t n_sub_8325BDA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0AC_G_ = int32_t(0x8349B0AC);
	if (!UseLiftedCode(143, 0x8325BDA8)) { __imp__sub_8325BDA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BDA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0AC_G_, (int64_t)str_TXT_820B0000_B_ + 19820, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BDA8, 0x8325BDA8) { ctx.r3.u64 = n_sub_8325BDA8(ctx, base); }

uint64_t n_sub_8325BDE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0B0_G_ = int32_t(0x8349B0B0);
	if (!UseLiftedCode(143, 0x8325BDE8)) { __imp__sub_8325BDE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BDE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0B0_G_, (int64_t)str_TXT_820B0000_B_ + 19580, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BDE8, 0x8325BDE8) { ctx.r3.u64 = n_sub_8325BDE8(ctx, base); }

uint64_t n_sub_8325BE28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0B4_G_ = int32_t(0x8349B0B4);
	if (!UseLiftedCode(143, 0x8325BE28)) { __imp__sub_8325BE28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BE28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0B4_G_, (int64_t)str_TXT_820D0000_B_ - 11592, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BE28, 0x8325BE28) { ctx.r3.u64 = n_sub_8325BE28(ctx, base); }

uint64_t n_sub_8325BE68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0B8_G_ = int32_t(0x8349B0B8);
	if (!UseLiftedCode(143, 0x8325BE68)) { __imp__sub_8325BE68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BE68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0B8_G_, (int64_t)str_TXT_820D0000_B_ - 11552, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BE68, 0x8325BE68) { ctx.r3.u64 = n_sub_8325BE68(ctx, base); }

uint64_t n_sub_8325BEA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0BC_G_ = int32_t(0x8349B0BC);
	if (!UseLiftedCode(143, 0x8325BEA8)) { __imp__sub_8325BEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BEA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0BC_G_, (int64_t)str_TXT_820D0000_B_ - 11536, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BEA8, 0x8325BEA8) { ctx.r3.u64 = n_sub_8325BEA8(ctx, base); }

uint64_t n_sub_8325BEE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0C0_G_ = int32_t(0x8349B0C0);
	if (!UseLiftedCode(143, 0x8325BEE8)) { __imp__sub_8325BEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BEE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0C0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BEE8, 0x8325BEE8) { ctx.r3.u64 = n_sub_8325BEE8(ctx, base); }

uint64_t n_sub_8325BF28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0C4_G_ = int32_t(0x8349B0C4);
	if (!UseLiftedCode(143, 0x8325BF28)) { __imp__sub_8325BF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BF28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0C4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BF28, 0x8325BF28) { ctx.r3.u64 = n_sub_8325BF28(ctx, base); }

uint64_t n_sub_8325BF68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0C8_G_ = int32_t(0x8349B0C8);
	if (!UseLiftedCode(143, 0x8325BF68)) { __imp__sub_8325BF68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BF68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0C8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BF68, 0x8325BF68) { ctx.r3.u64 = n_sub_8325BF68(ctx, base); }

uint64_t n_sub_8325BFA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0CC_G_ = int32_t(0x8349B0CC);
	if (!UseLiftedCode(143, 0x8325BFA8)) { __imp__sub_8325BFA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BFA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0CC_G_, (int64_t)str_TXT_820D0000_B_ - 10936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BFA8, 0x8325BFA8) { ctx.r3.u64 = n_sub_8325BFA8(ctx, base); }

uint64_t n_sub_8325BFE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0D0_G_ = int32_t(0x8349B0D0);
	if (!UseLiftedCode(143, 0x8325BFE8)) { __imp__sub_8325BFE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BFE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0D0_G_, (int64_t)str_TXT_820D0000_B_ - 10920, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325BFE8, 0x8325BFE8) { ctx.r3.u64 = n_sub_8325BFE8(ctx, base); }

uint64_t n_sub_8325C028(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0D4_G_ = int32_t(0x8349B0D4);
	if (!UseLiftedCode(143, 0x8325C028)) { __imp__sub_8325C028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C028);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0D4_G_, (int64_t)str_TXT_820D0000_B_ - 12052, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C028, 0x8325C028) { ctx.r3.u64 = n_sub_8325C028(ctx, base); }

uint64_t n_sub_8325C068(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0D8_G_ = int32_t(0x8349B0D8);
	if (!UseLiftedCode(143, 0x8325C068)) { __imp__sub_8325C068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C068);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0D8_G_, (int64_t)str_TXT_820D0000_B_ - 10904, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C068, 0x8325C068) { ctx.r3.u64 = n_sub_8325C068(ctx, base); }

uint64_t n_sub_8325C0A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0DC_G_ = int32_t(0x8349B0DC);
	if (!UseLiftedCode(143, 0x8325C0A8)) { __imp__sub_8325C0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C0A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0DC_G_, (int64_t)str_TXT_820D0000_B_ - 10888, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C0A8, 0x8325C0A8) { ctx.r3.u64 = n_sub_8325C0A8(ctx, base); }

uint64_t n_sub_8325C0E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0E0_G_ = int32_t(0x8349B0E0);
	if (!UseLiftedCode(143, 0x8325C0E8)) { __imp__sub_8325C0E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C0E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0E0_G_, (int64_t)str_TXT_820D0000_B_ - 10864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C0E8, 0x8325C0E8) { ctx.r3.u64 = n_sub_8325C0E8(ctx, base); }

uint64_t n_sub_8325C128(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0E4_G_ = int32_t(0x8349B0E4);
	if (!UseLiftedCode(143, 0x8325C128)) { __imp__sub_8325C128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C128);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0E4_G_, (int64_t)str_TXT_820D0000_B_ - 10844, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C128, 0x8325C128) { ctx.r3.u64 = n_sub_8325C128(ctx, base); }

uint64_t n_sub_8325C2E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0F0_G_ = int32_t(0x8349B0F0);
	if (!UseLiftedCode(143, 0x8325C2E8)) { __imp__sub_8325C2E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C2E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0F0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C2E8, 0x8325C2E8) { ctx.r3.u64 = n_sub_8325C2E8(ctx, base); }

uint64_t n_sub_8325C328(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0F4_G_ = int32_t(0x8349B0F4);
	if (!UseLiftedCode(143, 0x8325C328)) { __imp__sub_8325C328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C328);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0F4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C328, 0x8325C328) { ctx.r3.u64 = n_sub_8325C328(ctx, base); }

uint64_t n_sub_8325C368(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0F8_G_ = int32_t(0x8349B0F8);
	if (!UseLiftedCode(143, 0x8325C368)) { __imp__sub_8325C368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C368);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0F8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C368, 0x8325C368) { ctx.r3.u64 = n_sub_8325C368(ctx, base); }

uint64_t n_sub_8325C3A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B0FC_G_ = int32_t(0x8349B0FC);
	if (!UseLiftedCode(143, 0x8325C3A8)) { __imp__sub_8325C3A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C3A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0FC_G_, (int64_t)str_TXT_820D0000_B_ - 10016, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C3A8, 0x8325C3A8) { ctx.r3.u64 = n_sub_8325C3A8(ctx, base); }

uint64_t n_sub_8325C3E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B100_G_ = int32_t(0x8349B100);
	if (!UseLiftedCode(143, 0x8325C3E8)) { __imp__sub_8325C3E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C3E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B100_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C3E8, 0x8325C3E8) { ctx.r3.u64 = n_sub_8325C3E8(ctx, base); }

uint64_t n_sub_8325C428(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B104_G_ = int32_t(0x8349B104);
	if (!UseLiftedCode(143, 0x8325C428)) { __imp__sub_8325C428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C428);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B104_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C428, 0x8325C428) { ctx.r3.u64 = n_sub_8325C428(ctx, base); }

uint64_t n_sub_8325C468(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B108_G_ = int32_t(0x8349B108);
	if (!UseLiftedCode(143, 0x8325C468)) { __imp__sub_8325C468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C468);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B108_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C468, 0x8325C468) { ctx.r3.u64 = n_sub_8325C468(ctx, base); }

uint64_t n_sub_8325C4A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B10C_G_ = int32_t(0x8349B10C);
	if (!UseLiftedCode(143, 0x8325C4A8)) { __imp__sub_8325C4A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C4A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B10C_G_, (int64_t)str_TXT_820D0000_B_ - 8476, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C4A8, 0x8325C4A8) { ctx.r3.u64 = n_sub_8325C4A8(ctx, base); }

uint64_t n_sub_8325C4E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B110_G_ = int32_t(0x8349B110);
	if (!UseLiftedCode(143, 0x8325C4E8)) { __imp__sub_8325C4E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C4E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B110_G_, (int64_t)str_TXT_820D0000_B_ - 8448, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C4E8, 0x8325C4E8) { ctx.r3.u64 = n_sub_8325C4E8(ctx, base); }

uint64_t n_sub_8325C528(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B114_G_ = int32_t(0x8349B114);
	if (!UseLiftedCode(143, 0x8325C528)) { __imp__sub_8325C528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C528);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B114_G_, (int64_t)str_TXT_820D0000_B_ - 8420, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C528, 0x8325C528) { ctx.r3.u64 = n_sub_8325C528(ctx, base); }

uint64_t n_sub_8325C568(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B118_G_ = int32_t(0x8349B118);
	if (!UseLiftedCode(143, 0x8325C568)) { __imp__sub_8325C568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C568);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B118_G_, (int64_t)str_TXT_820D0000_B_ - 8388, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C568, 0x8325C568) { ctx.r3.u64 = n_sub_8325C568(ctx, base); }

uint64_t n_sub_8325C5A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B11C_G_ = int32_t(0x8349B11C);
	if (!UseLiftedCode(143, 0x8325C5A8)) { __imp__sub_8325C5A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C5A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B11C_G_, (int64_t)str_TXT_820D0000_B_ - 8356, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C5A8, 0x8325C5A8) { ctx.r3.u64 = n_sub_8325C5A8(ctx, base); }

uint64_t n_sub_8325C5E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B120_G_ = int32_t(0x8349B120);
	if (!UseLiftedCode(143, 0x8325C5E8)) { __imp__sub_8325C5E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C5E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B120_G_, (int64_t)str_TXT_820D0000_B_ - 8328, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C5E8, 0x8325C5E8) { ctx.r3.u64 = n_sub_8325C5E8(ctx, base); }

uint64_t n_sub_8325C628(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B124_G_ = int32_t(0x8349B124);
	if (!UseLiftedCode(143, 0x8325C628)) { __imp__sub_8325C628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C628);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B124_G_, (int64_t)str_TXT_820D0000_B_ - 8300, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 21992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C628, 0x8325C628) { ctx.r3.u64 = n_sub_8325C628(ctx, base); }

uint64_t n_sub_8325C668(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8325C668)) { ctx.r8.u64 = arg1; __imp__sub_8325C668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C668);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22008, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8325C668, 0x8325C668) { ctx.r3.u64 = n_sub_8325C668(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325C678(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B130_G_ = int32_t(0x8349B130);
	if (!UseLiftedCode(143, 0x8325C678)) { __imp__sub_8325C678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C678);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B130_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C678, 0x8325C678) { ctx.r3.u64 = n_sub_8325C678(ctx, base); }

uint64_t n_sub_8325C6B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B134_G_ = int32_t(0x8349B134);
	if (!UseLiftedCode(143, 0x8325C6B8)) { __imp__sub_8325C6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C6B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B134_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C6B8, 0x8325C6B8) { ctx.r3.u64 = n_sub_8325C6B8(ctx, base); }

uint64_t n_sub_8325C6F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B138_G_ = int32_t(0x8349B138);
	if (!UseLiftedCode(143, 0x8325C6F8)) { __imp__sub_8325C6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C6F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B138_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C6F8, 0x8325C6F8) { ctx.r3.u64 = n_sub_8325C6F8(ctx, base); }

uint64_t n_sub_8325C738(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B13C_G_ = int32_t(0x8349B13C);
	if (!UseLiftedCode(143, 0x8325C738)) { __imp__sub_8325C738(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C738);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B13C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C738, 0x8325C738) { ctx.r3.u64 = n_sub_8325C738(ctx, base); }

uint64_t n_sub_8325C778(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B140_G_ = int32_t(0x8349B140);
	if (!UseLiftedCode(143, 0x8325C778)) { __imp__sub_8325C778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C778);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B140_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C778, 0x8325C778) { ctx.r3.u64 = n_sub_8325C778(ctx, base); }

uint64_t n_sub_8325C7B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B144_G_ = int32_t(0x8349B144);
	if (!UseLiftedCode(143, 0x8325C7B8)) { __imp__sub_8325C7B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C7B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B144_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C7B8, 0x8325C7B8) { ctx.r3.u64 = n_sub_8325C7B8(ctx, base); }

uint64_t n_sub_8325C7F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B148_G_ = int32_t(0x8349B148);
	if (!UseLiftedCode(143, 0x8325C7F8)) { __imp__sub_8325C7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C7F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B148_G_, (int64_t)str_TXT_820D0000_B_ - 6584, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C7F8, 0x8325C7F8) { ctx.r3.u64 = n_sub_8325C7F8(ctx, base); }

uint64_t n_sub_8325C838(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B14C_G_ = int32_t(0x8349B14C);
	if (!UseLiftedCode(143, 0x8325C838)) { __imp__sub_8325C838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C838);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B14C_G_, (int64_t)str_TXT_820D0000_B_ - 6576, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C838, 0x8325C838) { ctx.r3.u64 = n_sub_8325C838(ctx, base); }

uint64_t n_sub_8325C878(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B150_G_ = int32_t(0x8349B150);
	if (!UseLiftedCode(143, 0x8325C878)) { __imp__sub_8325C878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C878);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B150_G_, (int64_t)str_TXT_820D0000_B_ - 6572, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C878, 0x8325C878) { ctx.r3.u64 = n_sub_8325C878(ctx, base); }

uint64_t n_sub_8325C8B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B154_G_ = int32_t(0x8349B154);
	if (!UseLiftedCode(143, 0x8325C8B8)) { __imp__sub_8325C8B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C8B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B154_G_, (int64_t)str_TXT_820D0000_B_ - 6560, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C8B8, 0x8325C8B8) { ctx.r3.u64 = n_sub_8325C8B8(ctx, base); }

uint64_t n_sub_8325C8F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B158_G_ = int32_t(0x8349B158);
	if (!UseLiftedCode(143, 0x8325C8F8)) { __imp__sub_8325C8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C8F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B158_G_, (int64_t)str_TXT_820D0000_B_ - 6552, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C8F8, 0x8325C8F8) { ctx.r3.u64 = n_sub_8325C8F8(ctx, base); }

uint64_t n_sub_8325C938(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B15C_G_ = int32_t(0x8349B15C);
	if (!UseLiftedCode(143, 0x8325C938)) { __imp__sub_8325C938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C938);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B15C_G_, (int64_t)str_TXT_820D0000_B_ - 6544, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C938, 0x8325C938) { ctx.r3.u64 = n_sub_8325C938(ctx, base); }

uint64_t n_sub_8325C978(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B160_G_ = int32_t(0x8349B160);
	if (!UseLiftedCode(143, 0x8325C978)) { __imp__sub_8325C978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C978);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B160_G_, (int64_t)str_TXT_820D0000_B_ - 6532, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C978, 0x8325C978) { ctx.r3.u64 = n_sub_8325C978(ctx, base); }

uint64_t n_sub_8325C9B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B164_G_ = int32_t(0x8349B164);
	if (!UseLiftedCode(143, 0x8325C9B8)) { __imp__sub_8325C9B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C9B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B164_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C9B8, 0x8325C9B8) { ctx.r3.u64 = n_sub_8325C9B8(ctx, base); }

uint64_t n_sub_8325C9F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B168_G_ = int32_t(0x8349B168);
	if (!UseLiftedCode(143, 0x8325C9F8)) { __imp__sub_8325C9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C9F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B168_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325C9F8, 0x8325C9F8) { ctx.r3.u64 = n_sub_8325C9F8(ctx, base); }

uint64_t n_sub_8325CA38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B16C_G_ = int32_t(0x8349B16C);
	if (!UseLiftedCode(143, 0x8325CA38)) { __imp__sub_8325CA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CA38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B16C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CA38, 0x8325CA38) { ctx.r3.u64 = n_sub_8325CA38(ctx, base); }

uint64_t n_sub_8325CA78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B170_G_ = int32_t(0x8349B170);
	if (!UseLiftedCode(143, 0x8325CA78)) { __imp__sub_8325CA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B170_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CA78, 0x8325CA78) { ctx.r3.u64 = n_sub_8325CA78(ctx, base); }

uint64_t n_sub_8325CAB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B174_G_ = int32_t(0x8349B174);
	if (!UseLiftedCode(143, 0x8325CAB8)) { __imp__sub_8325CAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CAB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B174_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CAB8, 0x8325CAB8) { ctx.r3.u64 = n_sub_8325CAB8(ctx, base); }

uint64_t n_sub_8325CAF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B178_G_ = int32_t(0x8349B178);
	if (!UseLiftedCode(143, 0x8325CAF8)) { __imp__sub_8325CAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CAF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B178_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CAF8, 0x8325CAF8) { ctx.r3.u64 = n_sub_8325CAF8(ctx, base); }

uint64_t n_sub_8325CB38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	if (!UseLiftedCode(143, 0x8325CB38)) { __imp__sub_8325CB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CB38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B17C_G_, (int64_t)str_TXT_820D0000_B_ - 5344, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CB38, 0x8325CB38) { ctx.r3.u64 = n_sub_8325CB38(ctx, base); }

uint64_t n_sub_8325CE40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1A4_G_ = int32_t(0x8349B1A4);
	if (!UseLiftedCode(143, 0x8325CE40)) { __imp__sub_8325CE40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CE40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1A4_G_, (int64_t)str_TXT_820D0000_B_ - 5212, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CE40, 0x8325CE40) { ctx.r3.u64 = n_sub_8325CE40(ctx, base); }

uint64_t n_sub_8325CED8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1AC_G_ = int32_t(0x8349B1AC);
	if (!UseLiftedCode(143, 0x8325CED8)) { __imp__sub_8325CED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CED8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1AC_G_, (int64_t)str_TXT_820D0000_B_ - 5188, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CED8, 0x8325CED8) { ctx.r3.u64 = n_sub_8325CED8(ctx, base); }

uint64_t n_sub_8325D100(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1C8_G_ = int32_t(0x8349B1C8);
	if (!UseLiftedCode(143, 0x8325D100)) { __imp__sub_8325D100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D100);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1C8_G_, (int64_t)str_TXT_820D0000_B_ - 5132, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D100, 0x8325D100) { ctx.r3.u64 = n_sub_8325D100(ctx, base); }

uint64_t n_sub_8325D140(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1CC_G_ = int32_t(0x8349B1CC);
	if (!UseLiftedCode(143, 0x8325D140)) { __imp__sub_8325D140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D140);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1CC_G_, (int64_t)str_TXT_820D0000_B_ - 5116, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D140, 0x8325D140) { ctx.r3.u64 = n_sub_8325D140(ctx, base); }

uint64_t n_sub_8325D370(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1E4_G_ = int32_t(0x8349B1E4);
	if (!UseLiftedCode(143, 0x8325D370)) { __imp__sub_8325D370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D370);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1E4_G_, (int64_t)str_TXT_820D0000_B_ - 5052, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D370, 0x8325D370) { ctx.r3.u64 = n_sub_8325D370(ctx, base); }

uint64_t n_sub_8325D4B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1F4_G_ = int32_t(0x8349B1F4);
	if (!UseLiftedCode(143, 0x8325D4B8)) { __imp__sub_8325D4B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D4B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1F4_G_, (int64_t)str_TXT_820D0000_B_ - 5012, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D4B8, 0x8325D4B8) { ctx.r3.u64 = n_sub_8325D4B8(ctx, base); }

uint64_t n_sub_8325D4F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1F8_G_ = int32_t(0x8349B1F8);
	if (!UseLiftedCode(143, 0x8325D4F8)) { __imp__sub_8325D4F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D4F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1F8_G_, (int64_t)str_TXT_820D0000_B_ - 4996, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D4F8, 0x8325D4F8) { ctx.r3.u64 = n_sub_8325D4F8(ctx, base); }

uint64_t n_sub_8325D538(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1FC_G_ = int32_t(0x8349B1FC);
	if (!UseLiftedCode(143, 0x8325D538)) { __imp__sub_8325D538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D538);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1FC_G_, (int64_t)str_TXT_820D0000_B_ - 4976, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D538, 0x8325D538) { ctx.r3.u64 = n_sub_8325D538(ctx, base); }

uint64_t n_sub_8325D628(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B208_G_ = int32_t(0x8349B208);
	if (!UseLiftedCode(143, 0x8325D628)) { __imp__sub_8325D628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D628);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B208_G_, (int64_t)str_TXT_820D0000_B_ - 4944, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 22992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D628, 0x8325D628) { ctx.r3.u64 = n_sub_8325D628(ctx, base); }

uint64_t n_sub_8325D668(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B20C_G_ = int32_t(0x8349B20C);
	if (!UseLiftedCode(143, 0x8325D668)) { __imp__sub_8325D668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D668);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B20C_G_, (int64_t)str_TXT_820C0000_B_ - 15700, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D668, 0x8325D668) { ctx.r3.u64 = n_sub_8325D668(ctx, base); }

uint64_t n_sub_8325D6A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B210_G_ = int32_t(0x8349B210);
	if (!UseLiftedCode(143, 0x8325D6A8)) { __imp__sub_8325D6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D6A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B210_G_, (int64_t)str_TXT_820D0000_B_ - 4924, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D6A8, 0x8325D6A8) { ctx.r3.u64 = n_sub_8325D6A8(ctx, base); }

uint64_t n_sub_8325D6E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B214_G_ = int32_t(0x8349B214);
	if (!UseLiftedCode(143, 0x8325D6E8)) { __imp__sub_8325D6E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D6E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B214_G_, (int64_t)str_TXT_820D0000_B_ - 4892, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D6E8, 0x8325D6E8) { ctx.r3.u64 = n_sub_8325D6E8(ctx, base); }

uint64_t n_sub_8325D728(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B218_G_ = int32_t(0x8349B218);
	if (!UseLiftedCode(143, 0x8325D728)) { __imp__sub_8325D728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D728);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B218_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D728, 0x8325D728) { ctx.r3.u64 = n_sub_8325D728(ctx, base); }

uint64_t n_sub_8325D768(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B21C_G_ = int32_t(0x8349B21C);
	if (!UseLiftedCode(143, 0x8325D768)) { __imp__sub_8325D768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D768);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B21C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D768, 0x8325D768) { ctx.r3.u64 = n_sub_8325D768(ctx, base); }

uint64_t n_sub_8325D7A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B220_G_ = int32_t(0x8349B220);
	if (!UseLiftedCode(143, 0x8325D7A8)) { __imp__sub_8325D7A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D7A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B220_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D7A8, 0x8325D7A8) { ctx.r3.u64 = n_sub_8325D7A8(ctx, base); }

uint64_t n_sub_8325D7E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8325D7E8)) { ctx.r8.u64 = arg1; __imp__sub_8325D7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D7E8);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23104, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8325D7E8, 0x8325D7E8) { ctx.r3.u64 = n_sub_8325D7E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325D7F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B234_G_ = int32_t(0x8349B234);
	if (!UseLiftedCode(143, 0x8325D7F8)) { __imp__sub_8325D7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D7F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B234_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D7F8, 0x8325D7F8) { ctx.r3.u64 = n_sub_8325D7F8(ctx, base); }

uint64_t n_sub_8325D838(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B238_G_ = int32_t(0x8349B238);
	if (!UseLiftedCode(143, 0x8325D838)) { __imp__sub_8325D838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D838);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B238_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D838, 0x8325D838) { ctx.r3.u64 = n_sub_8325D838(ctx, base); }

uint64_t n_sub_8325D878(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B23C_G_ = int32_t(0x8349B23C);
	if (!UseLiftedCode(143, 0x8325D878)) { __imp__sub_8325D878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D878);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B23C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D878, 0x8325D878) { ctx.r3.u64 = n_sub_8325D878(ctx, base); }

uint64_t n_sub_8325D8B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B240_G_ = int32_t(0x8349B240);
	if (!UseLiftedCode(143, 0x8325D8B8)) { __imp__sub_8325D8B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D8B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B240_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D8B8, 0x8325D8B8) { ctx.r3.u64 = n_sub_8325D8B8(ctx, base); }

uint64_t n_sub_8325D8F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B244_G_ = int32_t(0x8349B244);
	if (!UseLiftedCode(143, 0x8325D8F8)) { __imp__sub_8325D8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D8F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B244_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D8F8, 0x8325D8F8) { ctx.r3.u64 = n_sub_8325D8F8(ctx, base); }

uint64_t n_sub_8325D938(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B248_G_ = int32_t(0x8349B248);
	if (!UseLiftedCode(143, 0x8325D938)) { __imp__sub_8325D938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D938);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B248_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D938, 0x8325D938) { ctx.r3.u64 = n_sub_8325D938(ctx, base); }

uint64_t n_sub_8325D978(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B24C_G_ = int32_t(0x8349B24C);
	if (!UseLiftedCode(143, 0x8325D978)) { __imp__sub_8325D978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D978);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B24C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D978, 0x8325D978) { ctx.r3.u64 = n_sub_8325D978(ctx, base); }

uint64_t n_sub_8325D9B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B250_G_ = int32_t(0x8349B250);
	if (!UseLiftedCode(143, 0x8325D9B8)) { __imp__sub_8325D9B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D9B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B250_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D9B8, 0x8325D9B8) { ctx.r3.u64 = n_sub_8325D9B8(ctx, base); }

uint64_t n_sub_8325D9F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B254_G_ = int32_t(0x8349B254);
	if (!UseLiftedCode(143, 0x8325D9F8)) { __imp__sub_8325D9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D9F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B254_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D9F8, 0x8325D9F8) { ctx.r3.u64 = n_sub_8325D9F8(ctx, base); }

uint64_t n_sub_8325DA38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B258_G_ = int32_t(0x8349B258);
	if (!UseLiftedCode(143, 0x8325DA38)) { __imp__sub_8325DA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DA38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B258_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DA38, 0x8325DA38) { ctx.r3.u64 = n_sub_8325DA38(ctx, base); }

uint64_t n_sub_8325DA78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B25C_G_ = int32_t(0x8349B25C);
	if (!UseLiftedCode(143, 0x8325DA78)) { __imp__sub_8325DA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B25C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DA78, 0x8325DA78) { ctx.r3.u64 = n_sub_8325DA78(ctx, base); }

uint64_t n_sub_8325DAB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B260_G_ = int32_t(0x8349B260);
	if (!UseLiftedCode(143, 0x8325DAB8)) { __imp__sub_8325DAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DAB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B260_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DAB8, 0x8325DAB8) { ctx.r3.u64 = n_sub_8325DAB8(ctx, base); }

uint64_t n_sub_8325DAF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B264_G_ = int32_t(0x8349B264);
	if (!UseLiftedCode(143, 0x8325DAF8)) { __imp__sub_8325DAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DAF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B264_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DAF8, 0x8325DAF8) { ctx.r3.u64 = n_sub_8325DAF8(ctx, base); }

uint64_t n_sub_8325DB38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B268_G_ = int32_t(0x8349B268);
	if (!UseLiftedCode(143, 0x8325DB38)) { __imp__sub_8325DB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DB38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B268_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DB38, 0x8325DB38) { ctx.r3.u64 = n_sub_8325DB38(ctx, base); }

uint64_t n_sub_8325DB78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B26C_G_ = int32_t(0x8349B26C);
	if (!UseLiftedCode(143, 0x8325DB78)) { __imp__sub_8325DB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DB78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B26C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DB78, 0x8325DB78) { ctx.r3.u64 = n_sub_8325DB78(ctx, base); }

uint64_t n_sub_8325DD78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B290_G_ = int32_t(0x8349B290);
	if (!UseLiftedCode(143, 0x8325DD78)) { __imp__sub_8325DD78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DD78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B290_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DD78, 0x8325DD78) { ctx.r3.u64 = n_sub_8325DD78(ctx, base); }

uint64_t n_sub_8325DDB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B294_G_ = int32_t(0x8349B294);
	if (!UseLiftedCode(143, 0x8325DDB8)) { __imp__sub_8325DDB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DDB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B294_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DDB8, 0x8325DDB8) { ctx.r3.u64 = n_sub_8325DDB8(ctx, base); }

uint64_t n_sub_8325DDF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B298_G_ = int32_t(0x8349B298);
	if (!UseLiftedCode(143, 0x8325DDF8)) { __imp__sub_8325DDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DDF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B298_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DDF8, 0x8325DDF8) { ctx.r3.u64 = n_sub_8325DDF8(ctx, base); }

uint64_t n_sub_8325DF88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2B4_G_ = int32_t(0x8349B2B4);
	if (!UseLiftedCode(143, 0x8325DF88)) { __imp__sub_8325DF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DF88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2B4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DF88, 0x8325DF88) { ctx.r3.u64 = n_sub_8325DF88(ctx, base); }

uint64_t n_sub_8325DFC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2B8_G_ = int32_t(0x8349B2B8);
	if (!UseLiftedCode(143, 0x8325DFC8)) { __imp__sub_8325DFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DFC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2B8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325DFC8, 0x8325DFC8) { ctx.r3.u64 = n_sub_8325DFC8(ctx, base); }

uint64_t n_sub_8325E008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2BC_G_ = int32_t(0x8349B2BC);
	if (!UseLiftedCode(143, 0x8325E008)) { __imp__sub_8325E008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2BC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E008, 0x8325E008) { ctx.r3.u64 = n_sub_8325E008(ctx, base); }

uint64_t n_sub_8325E0B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2C8_G_ = int32_t(0x8349B2C8);
	if (!UseLiftedCode(143, 0x8325E0B8)) { __imp__sub_8325E0B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E0B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2C8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E0B8, 0x8325E0B8) { ctx.r3.u64 = n_sub_8325E0B8(ctx, base); }

uint64_t n_sub_8325E0F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2CC_G_ = int32_t(0x8349B2CC);
	if (!UseLiftedCode(143, 0x8325E0F8)) { __imp__sub_8325E0F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E0F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2CC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E0F8, 0x8325E0F8) { ctx.r3.u64 = n_sub_8325E0F8(ctx, base); }

uint64_t n_sub_8325E138(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2D0_G_ = int32_t(0x8349B2D0);
	if (!UseLiftedCode(143, 0x8325E138)) { __imp__sub_8325E138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E138);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2D0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E138, 0x8325E138) { ctx.r3.u64 = n_sub_8325E138(ctx, base); }

uint64_t n_sub_8325E290(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2E8_G_ = int32_t(0x8349B2E8);
	if (!UseLiftedCode(143, 0x8325E290)) { __imp__sub_8325E290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E290);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2E8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E290, 0x8325E290) { ctx.r3.u64 = n_sub_8325E290(ctx, base); }

uint64_t n_sub_8325E2D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2EC_G_ = int32_t(0x8349B2EC);
	if (!UseLiftedCode(143, 0x8325E2D0)) { __imp__sub_8325E2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E2D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2EC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E2D0, 0x8325E2D0) { ctx.r3.u64 = n_sub_8325E2D0(ctx, base); }

uint64_t n_sub_8325E310(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2F0_G_ = int32_t(0x8349B2F0);
	if (!UseLiftedCode(143, 0x8325E310)) { __imp__sub_8325E310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E310);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2F0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E310, 0x8325E310) { ctx.r3.u64 = n_sub_8325E310(ctx, base); }

uint64_t n_sub_8325E350(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2F4_G_ = int32_t(0x8349B2F4);
	if (!UseLiftedCode(143, 0x8325E350)) { __imp__sub_8325E350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E350);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2F4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E350, 0x8325E350) { ctx.r3.u64 = n_sub_8325E350(ctx, base); }

uint64_t n_sub_8325E390(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2F8_G_ = int32_t(0x8349B2F8);
	if (!UseLiftedCode(143, 0x8325E390)) { __imp__sub_8325E390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E390);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2F8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E390, 0x8325E390) { ctx.r3.u64 = n_sub_8325E390(ctx, base); }

uint64_t n_sub_8325E3D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B2FC_G_ = int32_t(0x8349B2FC);
	if (!UseLiftedCode(143, 0x8325E3D0)) { __imp__sub_8325E3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E3D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2FC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E3D0, 0x8325E3D0) { ctx.r3.u64 = n_sub_8325E3D0(ctx, base); }

uint64_t n_sub_8325E410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B300_G_ = int32_t(0x8349B300);
	if (!UseLiftedCode(143, 0x8325E410)) { __imp__sub_8325E410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E410);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B300_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E410, 0x8325E410) { ctx.r3.u64 = n_sub_8325E410(ctx, base); }

uint64_t n_sub_8325E450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B304_G_ = int32_t(0x8349B304);
	if (!UseLiftedCode(143, 0x8325E450)) { __imp__sub_8325E450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B304_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E450, 0x8325E450) { ctx.r3.u64 = n_sub_8325E450(ctx, base); }

uint64_t n_sub_8325E490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B308_G_ = int32_t(0x8349B308);
	if (!UseLiftedCode(143, 0x8325E490)) { __imp__sub_8325E490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B308_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E490, 0x8325E490) { ctx.r3.u64 = n_sub_8325E490(ctx, base); }

uint64_t n_sub_8325E7C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B370_G_ = int32_t(0x8349B370);
	if (!UseLiftedCode(143, 0x8325E7C8)) { __imp__sub_8325E7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E7C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B370_G_, (int64_t)str_TXT_820C0000_B_ - 14164, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E7C8, 0x8325E7C8) { ctx.r3.u64 = n_sub_8325E7C8(ctx, base); }

// sub_8325E808  [64 bytes]
uint64_t n_sub_8325E808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B374_G_ = int32_t(0x8349B374);
	if (!UseLiftedCode(143, 0x8325E808)) { __imp__sub_8325E808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E808);
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B374_G_, (int64_t)str_TXT_820D0000_B_ + 5144, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E808, 0x8325E808) { ctx.r3.u64 = n_sub_8325E808(ctx, base); }

uint64_t n_sub_8325E848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B378_G_ = int32_t(0x8349B378);
	if (!UseLiftedCode(143, 0x8325E848)) { __imp__sub_8325E848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B378_G_, (int64_t)str_TXT_820D0000_B_ + 5156, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E848, 0x8325E848) { ctx.r3.u64 = n_sub_8325E848(ctx, base); }

uint64_t n_sub_8325E888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B37C_G_ = int32_t(0x8349B37C);
	if (!UseLiftedCode(143, 0x8325E888)) { __imp__sub_8325E888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B37C_G_, (int64_t)str_TXT_820D0000_B_ + 5172, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E888, 0x8325E888) { ctx.r3.u64 = n_sub_8325E888(ctx, base); }

uint64_t n_sub_8325E8C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B380_G_ = int32_t(0x8349B380);
	if (!UseLiftedCode(143, 0x8325E8C8)) { __imp__sub_8325E8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E8C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B380_G_, (int64_t)str_TXT_820D0000_B_ + 5188, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E8C8, 0x8325E8C8) { ctx.r3.u64 = n_sub_8325E8C8(ctx, base); }

uint64_t n_sub_8325E908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B384_G_ = int32_t(0x8349B384);
	if (!UseLiftedCode(143, 0x8325E908)) { __imp__sub_8325E908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B384_G_, (int64_t)str_TXT_820B0000_B_ + 30568, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E908, 0x8325E908) { ctx.r3.u64 = n_sub_8325E908(ctx, base); }

uint64_t n_sub_8325E948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B388_G_ = int32_t(0x8349B388);
	if (!UseLiftedCode(143, 0x8325E948)) { __imp__sub_8325E948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B388_G_, (int64_t)str_TXT_820B0000_B_ + 30404, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E948, 0x8325E948) { ctx.r3.u64 = n_sub_8325E948(ctx, base); }

uint64_t n_sub_8325E988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B38C_G_ = int32_t(0x8349B38C);
	if (!UseLiftedCode(143, 0x8325E988)) { __imp__sub_8325E988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B38C_G_, (int64_t)str_TXT_820B0000_B_ + 30424, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E988, 0x8325E988) { ctx.r3.u64 = n_sub_8325E988(ctx, base); }

uint64_t n_sub_8325E9C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B390_G_ = int32_t(0x8349B390);
	if (!UseLiftedCode(143, 0x8325E9C8)) { __imp__sub_8325E9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E9C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B390_G_, (int64_t)str_TXT_820C0000_B_ - 7456, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E9C8, 0x8325E9C8) { ctx.r3.u64 = n_sub_8325E9C8(ctx, base); }

uint64_t n_sub_8325EA08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B394_G_ = int32_t(0x8349B394);
	if (!UseLiftedCode(143, 0x8325EA08)) { __imp__sub_8325EA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EA08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B394_G_, (int64_t)g_82000000 + 5040, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EA08, 0x8325EA08) { ctx.r3.u64 = n_sub_8325EA08(ctx, base); }

uint64_t n_sub_8325EA48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B398_G_ = int32_t(0x8349B398);
	if (!UseLiftedCode(143, 0x8325EA48)) { __imp__sub_8325EA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EA48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B398_G_, (int64_t)g_82000000 + 5024, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EA48, 0x8325EA48) { ctx.r3.u64 = n_sub_8325EA48(ctx, base); }

uint64_t n_sub_8325EA88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B39C_G_ = int32_t(0x8349B39C);
	if (!UseLiftedCode(143, 0x8325EA88)) { __imp__sub_8325EA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EA88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B39C_G_, (int64_t)str_TXT_820D0000_B_ + 5204, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EA88, 0x8325EA88) { ctx.r3.u64 = n_sub_8325EA88(ctx, base); }

uint64_t n_sub_8325EAC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3A0_G_ = int32_t(0x8349B3A0);
	if (!UseLiftedCode(143, 0x8325EAC8)) { __imp__sub_8325EAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EAC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A0_G_, (int64_t)str_TXT_820D0000_B_ + 5224, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EAC8, 0x8325EAC8) { ctx.r3.u64 = n_sub_8325EAC8(ctx, base); }

uint64_t n_sub_8325EB08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3A4_G_ = int32_t(0x8349B3A4);
	if (!UseLiftedCode(143, 0x8325EB08)) { __imp__sub_8325EB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A4_G_, (int64_t)str_TXT_820D0000_B_ + 5244, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 23984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EB08, 0x8325EB08) { ctx.r3.u64 = n_sub_8325EB08(ctx, base); }

uint64_t n_sub_8325EB48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3A8_G_ = int32_t(0x8349B3A8);
	if (!UseLiftedCode(143, 0x8325EB48)) { __imp__sub_8325EB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A8_G_, (int64_t)str_TXT_820D0000_B_ + 5264, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EB48, 0x8325EB48) { ctx.r3.u64 = n_sub_8325EB48(ctx, base); }

uint64_t n_sub_8325EB88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3AC_G_ = int32_t(0x8349B3AC);
	if (!UseLiftedCode(143, 0x8325EB88)) { __imp__sub_8325EB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3AC_G_, (int64_t)str_TXT_820D0000_B_ + 5284, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EB88, 0x8325EB88) { ctx.r3.u64 = n_sub_8325EB88(ctx, base); }

uint64_t n_sub_8325EBC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3B0_G_ = int32_t(0x8349B3B0);
	if (!UseLiftedCode(143, 0x8325EBC8)) { __imp__sub_8325EBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EBC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B0_G_, (int64_t)str_TXT_820D0000_B_ + 5304, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EBC8, 0x8325EBC8) { ctx.r3.u64 = n_sub_8325EBC8(ctx, base); }

uint64_t n_sub_8325EC08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3B4_G_ = int32_t(0x8349B3B4);
	if (!UseLiftedCode(143, 0x8325EC08)) { __imp__sub_8325EC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B4_G_, (int64_t)str_TXT_820D0000_B_ + 5320, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EC08, 0x8325EC08) { ctx.r3.u64 = n_sub_8325EC08(ctx, base); }

uint64_t n_sub_8325EC48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3B8_G_ = int32_t(0x8349B3B8);
	if (!UseLiftedCode(143, 0x8325EC48)) { __imp__sub_8325EC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B8_G_, (int64_t)str_TXT_820D0000_B_ + 5336, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EC48, 0x8325EC48) { ctx.r3.u64 = n_sub_8325EC48(ctx, base); }

uint64_t n_sub_8325EC88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3BC_G_ = int32_t(0x8349B3BC);
	if (!UseLiftedCode(143, 0x8325EC88)) { __imp__sub_8325EC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3BC_G_, (int64_t)str_TXT_820D0000_B_ + 5352, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EC88, 0x8325EC88) { ctx.r3.u64 = n_sub_8325EC88(ctx, base); }

uint64_t n_sub_8325ECC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3C0_G_ = int32_t(0x8349B3C0);
	if (!UseLiftedCode(143, 0x8325ECC8)) { __imp__sub_8325ECC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ECC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C0_G_, (int64_t)str_TXT_820D0000_B_ + 5368, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325ECC8, 0x8325ECC8) { ctx.r3.u64 = n_sub_8325ECC8(ctx, base); }

uint64_t n_sub_8325ED08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3C4_G_ = int32_t(0x8349B3C4);
	if (!UseLiftedCode(143, 0x8325ED08)) { __imp__sub_8325ED08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C4_G_, (int64_t)str_TXT_820D0000_B_ + 5388, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325ED08, 0x8325ED08) { ctx.r3.u64 = n_sub_8325ED08(ctx, base); }

uint64_t n_sub_8325ED48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3C8_G_ = int32_t(0x8349B3C8);
	if (!UseLiftedCode(143, 0x8325ED48)) { __imp__sub_8325ED48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C8_G_, (int64_t)str_TXT_820D0000_B_ + 5408, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325ED48, 0x8325ED48) { ctx.r3.u64 = n_sub_8325ED48(ctx, base); }

uint64_t n_sub_8325ED88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3CC_G_ = int32_t(0x8349B3CC);
	if (!UseLiftedCode(143, 0x8325ED88)) { __imp__sub_8325ED88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3CC_G_, (int64_t)str_TXT_820D0000_B_ + 5428, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325ED88, 0x8325ED88) { ctx.r3.u64 = n_sub_8325ED88(ctx, base); }

uint64_t n_sub_8325EDC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3D0_G_ = int32_t(0x8349B3D0);
	if (!UseLiftedCode(143, 0x8325EDC8)) { __imp__sub_8325EDC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EDC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D0_G_, (int64_t)str_TXT_820D0000_B_ + 5448, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EDC8, 0x8325EDC8) { ctx.r3.u64 = n_sub_8325EDC8(ctx, base); }

uint64_t n_sub_8325EE08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3D4_G_ = int32_t(0x8349B3D4);
	if (!UseLiftedCode(143, 0x8325EE08)) { __imp__sub_8325EE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D4_G_, (int64_t)str_TXT_820D0000_B_ + 5468, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EE08, 0x8325EE08) { ctx.r3.u64 = n_sub_8325EE08(ctx, base); }

uint64_t n_sub_8325EE48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3D8_G_ = int32_t(0x8349B3D8);
	if (!UseLiftedCode(143, 0x8325EE48)) { __imp__sub_8325EE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D8_G_, (int64_t)str_TXT_820D0000_B_ + 5488, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EE48, 0x8325EE48) { ctx.r3.u64 = n_sub_8325EE48(ctx, base); }

uint64_t n_sub_8325EE88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3DC_G_ = int32_t(0x8349B3DC);
	if (!UseLiftedCode(143, 0x8325EE88)) { __imp__sub_8325EE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3DC_G_, (int64_t)str_TXT_820D0000_B_ + 5504, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EE88, 0x8325EE88) { ctx.r3.u64 = n_sub_8325EE88(ctx, base); }

uint64_t n_sub_8325EEC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3E0_G_ = int32_t(0x8349B3E0);
	if (!UseLiftedCode(143, 0x8325EEC8)) { __imp__sub_8325EEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EEC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E0_G_, (int64_t)str_TXT_820D0000_B_ + 5520, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EEC8, 0x8325EEC8) { ctx.r3.u64 = n_sub_8325EEC8(ctx, base); }

uint64_t n_sub_8325EF08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3E4_G_ = int32_t(0x8349B3E4);
	if (!UseLiftedCode(143, 0x8325EF08)) { __imp__sub_8325EF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E4_G_, (int64_t)str_TXT_820D0000_B_ + 5536, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EF08, 0x8325EF08) { ctx.r3.u64 = n_sub_8325EF08(ctx, base); }

uint64_t n_sub_8325EF48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3E8_G_ = int32_t(0x8349B3E8);
	if (!UseLiftedCode(143, 0x8325EF48)) { __imp__sub_8325EF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E8_G_, (int64_t)str_TXT_820D0000_B_ + 5552, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EF48, 0x8325EF48) { ctx.r3.u64 = n_sub_8325EF48(ctx, base); }

uint64_t n_sub_8325EF88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3EC_G_ = int32_t(0x8349B3EC);
	if (!UseLiftedCode(143, 0x8325EF88)) { __imp__sub_8325EF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3EC_G_, (int64_t)str_TXT_820D0000_B_ + 5572, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EF88, 0x8325EF88) { ctx.r3.u64 = n_sub_8325EF88(ctx, base); }

uint64_t n_sub_8325EFC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3F0_G_ = int32_t(0x8349B3F0);
	if (!UseLiftedCode(143, 0x8325EFC8)) { __imp__sub_8325EFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EFC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3F0_G_, (int64_t)str_TXT_820D0000_B_ + 5588, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325EFC8, 0x8325EFC8) { ctx.r3.u64 = n_sub_8325EFC8(ctx, base); }

uint64_t n_sub_8325F008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3F4_G_ = int32_t(0x8349B3F4);
	if (!UseLiftedCode(143, 0x8325F008)) { __imp__sub_8325F008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3F4_G_, (int64_t)str_TXT_820D0000_B_ + 5596, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325F008, 0x8325F008) { ctx.r3.u64 = n_sub_8325F008(ctx, base); }

uint64_t n_sub_8325F048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3F8_G_ = int32_t(0x8349B3F8);
	if (!UseLiftedCode(143, 0x8325F048)) { __imp__sub_8325F048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B3F8_G_, (int64_t)g_82000000 + 22128, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325F048, 0x8325F048) { ctx.r3.u64 = n_sub_8325F048(ctx, base); }

uint64_t n_sub_8325F088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B3FC_G_ = int32_t(0x8349B3FC);
	if (!UseLiftedCode(143, 0x8325F088)) { __imp__sub_8325F088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B3FC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325F088, 0x8325F088) { ctx.r3.u64 = n_sub_8325F088(ctx, base); }

uint64_t n_sub_8325F0C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B400_G_ = int32_t(0x8349B400);
	if (!UseLiftedCode(143, 0x8325F0C8)) { __imp__sub_8325F0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F0C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B400_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325F0C8, 0x8325F0C8) { ctx.r3.u64 = n_sub_8325F0C8(ctx, base); }

uint64_t n_sub_8325F108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B404_G_ = int32_t(0x8349B404);
	if (!UseLiftedCode(143, 0x8325F108)) { __imp__sub_8325F108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B404_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325F108, 0x8325F108) { ctx.r3.u64 = n_sub_8325F108(ctx, base); }

uint64_t n_sub_8325FCD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B4E4_G_ = int32_t(0x8349B4E4);
	if (!UseLiftedCode(143, 0x8325FCD8)) { __imp__sub_8325FCD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FCD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B4E4_G_, (int64_t)str_TXT_820B0000_B_ + 30568, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FCD8, 0x8325FCD8) { ctx.r3.u64 = n_sub_8325FCD8(ctx, base); }

uint64_t n_sub_8325FDD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B500_G_ = int32_t(0x8349B500);
	if (!UseLiftedCode(143, 0x8325FDD8)) { __imp__sub_8325FDD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FDD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B500_G_, (int64_t)str_TXT_820D0000_B_ + 5572, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FDD8, 0x8325FDD8) { ctx.r3.u64 = n_sub_8325FDD8(ctx, base); }

uint64_t n_sub_8325FE18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B504_G_ = int32_t(0x8349B504);
	if (!UseLiftedCode(143, 0x8325FE18)) { __imp__sub_8325FE18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B504_G_, (int64_t)str_TXT_820D0000_B_ + 21768, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FE18, 0x8325FE18) { ctx.r3.u64 = n_sub_8325FE18(ctx, base); }

uint64_t n_sub_8325FE58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B508_G_ = int32_t(0x8349B508);
	if (!UseLiftedCode(143, 0x8325FE58)) { __imp__sub_8325FE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B508_G_, (int64_t)str_TXT_820D0000_B_ + 21792, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FE58, 0x8325FE58) { ctx.r3.u64 = n_sub_8325FE58(ctx, base); }

uint64_t n_sub_8325FE98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B50C_G_ = int32_t(0x8349B50C);
	if (!UseLiftedCode(143, 0x8325FE98)) { __imp__sub_8325FE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B50C_G_, (int64_t)str_TXT_820D0000_B_ + 21816, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FE98, 0x8325FE98) { ctx.r3.u64 = n_sub_8325FE98(ctx, base); }

uint64_t n_sub_8325FED8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B510_G_ = int32_t(0x8349B510);
	if (!UseLiftedCode(143, 0x8325FED8)) { __imp__sub_8325FED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FED8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B510_G_, (int64_t)str_TXT_820D0000_B_ + 21840, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FED8, 0x8325FED8) { ctx.r3.u64 = n_sub_8325FED8(ctx, base); }

uint64_t n_sub_8325FF18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B514_G_ = int32_t(0x8349B514);
	if (!UseLiftedCode(143, 0x8325FF18)) { __imp__sub_8325FF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FF18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B514_G_, (int64_t)str_TXT_820D0000_B_ + 21876, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FF18, 0x8325FF18) { ctx.r3.u64 = n_sub_8325FF18(ctx, base); }
