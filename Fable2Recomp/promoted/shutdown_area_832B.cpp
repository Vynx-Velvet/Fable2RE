// Shut-down destructors of global objects at 0x832Bxxxx, as readable C++.
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
#include "lifted/readable_support.h"

uint64_t Global83334CB4_DestroyHandleTargetList(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334CB4 = int32_t(0x83334CB4);
	if (!UseLiftedCode(146, 0x832B0020)) { __imp__sub_832B0020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0020);
	return DestroyHandleTargetList(ctx, base, g_83334CB4);
}
PROMOTED_ENTRY(146, sub_832B0020, 0x832B0020) { ctx.r3.u64 = Global83334CB4_DestroyHandleTargetList(ctx, base); }

uint64_t Global83334CF0_DestroyHandleTargetList(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334CF0 = int32_t(0x83334CF0);
	if (!UseLiftedCode(146, 0x832B0030)) { __imp__sub_832B0030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0030);
	return DestroyHandleTargetList(ctx, base, g_83334CF0);
}
PROMOTED_ENTRY(146, sub_832B0030, 0x832B0030) { ctx.r3.u64 = Global83334CF0_DestroyHandleTargetList(ctx, base); }

uint64_t Destroy_TXT_83334D38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D38_G_ = int32_t(0x83334D38);
	if (!UseLiftedCode(146, 0x832B0040)) { __imp__sub_832B0040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0040);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D38_G_);
}
PROMOTED_ENTRY(146, sub_832B0040, 0x832B0040) { ctx.r3.u64 = Destroy_TXT_83334D38_G_(ctx, base); }

uint64_t Destroy_TXT_83334D3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D3C_G_ = int32_t(0x83334D3C);
	if (!UseLiftedCode(146, 0x832B0050)) { __imp__sub_832B0050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0050);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D3C_G_);
}
PROMOTED_ENTRY(146, sub_832B0050, 0x832B0050) { ctx.r3.u64 = Destroy_TXT_83334D3C_G_(ctx, base); }

uint64_t Destroy_TXT_83334D40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D40_G_ = int32_t(0x83334D40);
	if (!UseLiftedCode(146, 0x832B0060)) { __imp__sub_832B0060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0060);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D40_G_);
}
PROMOTED_ENTRY(146, sub_832B0060, 0x832B0060) { ctx.r3.u64 = Destroy_TXT_83334D40_G_(ctx, base); }

uint64_t Destroy_TXT_83334D44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D44_G_ = int32_t(0x83334D44);
	if (!UseLiftedCode(146, 0x832B0070)) { __imp__sub_832B0070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0070);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D44_G_);
}
PROMOTED_ENTRY(146, sub_832B0070, 0x832B0070) { ctx.r3.u64 = Destroy_TXT_83334D44_G_(ctx, base); }

uint64_t Destroy_TXT_83334D48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D48_G_ = int32_t(0x83334D48);
	if (!UseLiftedCode(146, 0x832B0080)) { __imp__sub_832B0080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0080);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D48_G_);
}
PROMOTED_ENTRY(146, sub_832B0080, 0x832B0080) { ctx.r3.u64 = Destroy_TXT_83334D48_G_(ctx, base); }

uint64_t Destroy_TXT_83334D4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D4C_G_ = int32_t(0x83334D4C);
	if (!UseLiftedCode(146, 0x832B0090)) { __imp__sub_832B0090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0090);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D4C_G_);
}
PROMOTED_ENTRY(146, sub_832B0090, 0x832B0090) { ctx.r3.u64 = Destroy_TXT_83334D4C_G_(ctx, base); }

uint64_t Destroy_TXT_83334D50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D50_G_ = int32_t(0x83334D50);
	if (!UseLiftedCode(146, 0x832B00A0)) { __imp__sub_832B00A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D50_G_);
}
PROMOTED_ENTRY(146, sub_832B00A0, 0x832B00A0) { ctx.r3.u64 = Destroy_TXT_83334D50_G_(ctx, base); }

uint64_t Destroy_TXT_83334D54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D54_G_ = int32_t(0x83334D54);
	if (!UseLiftedCode(146, 0x832B00B0)) { __imp__sub_832B00B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00B0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D54_G_);
}
PROMOTED_ENTRY(146, sub_832B00B0, 0x832B00B0) { ctx.r3.u64 = Destroy_TXT_83334D54_G_(ctx, base); }

uint64_t Destroy_TXT_83334D58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D58_G_ = int32_t(0x83334D58);
	if (!UseLiftedCode(146, 0x832B00C0)) { __imp__sub_832B00C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00C0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D58_G_);
}
PROMOTED_ENTRY(146, sub_832B00C0, 0x832B00C0) { ctx.r3.u64 = Destroy_TXT_83334D58_G_(ctx, base); }

uint64_t Destroy_TXT_83334D5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D5C_G_ = int32_t(0x83334D5C);
	if (!UseLiftedCode(146, 0x832B00D0)) { __imp__sub_832B00D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00D0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D5C_G_);
}
PROMOTED_ENTRY(146, sub_832B00D0, 0x832B00D0) { ctx.r3.u64 = Destroy_TXT_83334D5C_G_(ctx, base); }

uint64_t Destroy_TXT_83334D60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D60_G_ = int32_t(0x83334D60);
	if (!UseLiftedCode(146, 0x832B00E0)) { __imp__sub_832B00E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D60_G_);
}
PROMOTED_ENTRY(146, sub_832B00E0, 0x832B00E0) { ctx.r3.u64 = Destroy_TXT_83334D60_G_(ctx, base); }

uint64_t Destroy_TXT_83334D64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D64_G_ = int32_t(0x83334D64);
	if (!UseLiftedCode(146, 0x832B00F0)) { __imp__sub_832B00F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D64_G_);
}
PROMOTED_ENTRY(146, sub_832B00F0, 0x832B00F0) { ctx.r3.u64 = Destroy_TXT_83334D64_G_(ctx, base); }

uint64_t Destroy_TXT_83334D68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D68_G_ = int32_t(0x83334D68);
	if (!UseLiftedCode(146, 0x832B0100)) { __imp__sub_832B0100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0100);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D68_G_);
}
PROMOTED_ENTRY(146, sub_832B0100, 0x832B0100) { ctx.r3.u64 = Destroy_TXT_83334D68_G_(ctx, base); }

uint64_t Destroy_TXT_83334D6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D6C_G_ = int32_t(0x83334D6C);
	if (!UseLiftedCode(146, 0x832B0110)) { __imp__sub_832B0110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0110);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D6C_G_);
}
PROMOTED_ENTRY(146, sub_832B0110, 0x832B0110) { ctx.r3.u64 = Destroy_TXT_83334D6C_G_(ctx, base); }

uint64_t Destroy_TXT_83334D70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D70_G_ = int32_t(0x83334D70);
	if (!UseLiftedCode(146, 0x832B0120)) { __imp__sub_832B0120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0120);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D70_G_);
}
PROMOTED_ENTRY(146, sub_832B0120, 0x832B0120) { ctx.r3.u64 = Destroy_TXT_83334D70_G_(ctx, base); }

uint64_t Destroy_TXT_83334D74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D74_G_ = int32_t(0x83334D74);
	if (!UseLiftedCode(146, 0x832B0130)) { __imp__sub_832B0130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0130);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D74_G_);
}
PROMOTED_ENTRY(146, sub_832B0130, 0x832B0130) { ctx.r3.u64 = Destroy_TXT_83334D74_G_(ctx, base); }

uint64_t Destroy_TXT_83334D78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D78_G_ = int32_t(0x83334D78);
	if (!UseLiftedCode(146, 0x832B0140)) { __imp__sub_832B0140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0140);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D78_G_);
}
PROMOTED_ENTRY(146, sub_832B0140, 0x832B0140) { ctx.r3.u64 = Destroy_TXT_83334D78_G_(ctx, base); }

uint64_t Destroy_TXT_83334D7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D7C_G_ = int32_t(0x83334D7C);
	if (!UseLiftedCode(146, 0x832B0150)) { __imp__sub_832B0150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0150);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D7C_G_);
}
PROMOTED_ENTRY(146, sub_832B0150, 0x832B0150) { ctx.r3.u64 = Destroy_TXT_83334D7C_G_(ctx, base); }

uint64_t Destroy_TXT_83334D80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D80_G_ = int32_t(0x83334D80);
	if (!UseLiftedCode(146, 0x832B0160)) { __imp__sub_832B0160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0160);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D80_G_);
}
PROMOTED_ENTRY(146, sub_832B0160, 0x832B0160) { ctx.r3.u64 = Destroy_TXT_83334D80_G_(ctx, base); }

uint64_t Destroy_TXT_83334D84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D84_G_ = int32_t(0x83334D84);
	if (!UseLiftedCode(146, 0x832B0170)) { __imp__sub_832B0170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0170);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D84_G_);
}
PROMOTED_ENTRY(146, sub_832B0170, 0x832B0170) { ctx.r3.u64 = Destroy_TXT_83334D84_G_(ctx, base); }

uint64_t Destroy_TXT_83334D88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D88_G_ = int32_t(0x83334D88);
	if (!UseLiftedCode(146, 0x832B0180)) { __imp__sub_832B0180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0180);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D88_G_);
}
PROMOTED_ENTRY(146, sub_832B0180, 0x832B0180) { ctx.r3.u64 = Destroy_TXT_83334D88_G_(ctx, base); }

uint64_t Destroy_TXT_83334D8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D8C_G_ = int32_t(0x83334D8C);
	if (!UseLiftedCode(146, 0x832B0190)) { __imp__sub_832B0190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0190);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D8C_G_);
}
PROMOTED_ENTRY(146, sub_832B0190, 0x832B0190) { ctx.r3.u64 = Destroy_TXT_83334D8C_G_(ctx, base); }

uint64_t Destroy_TXT_83334D90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D90_G_ = int32_t(0x83334D90);
	if (!UseLiftedCode(146, 0x832B01A0)) { __imp__sub_832B01A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D90_G_);
}
PROMOTED_ENTRY(146, sub_832B01A0, 0x832B01A0) { ctx.r3.u64 = Destroy_TXT_83334D90_G_(ctx, base); }

uint64_t Destroy_TXT_83334D94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D94_G_ = int32_t(0x83334D94);
	if (!UseLiftedCode(146, 0x832B01B0)) { __imp__sub_832B01B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01B0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D94_G_);
}
PROMOTED_ENTRY(146, sub_832B01B0, 0x832B01B0) { ctx.r3.u64 = Destroy_TXT_83334D94_G_(ctx, base); }

uint64_t Destroy_TXT_83334D98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D98_G_ = int32_t(0x83334D98);
	if (!UseLiftedCode(146, 0x832B01C0)) { __imp__sub_832B01C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01C0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D98_G_);
}
PROMOTED_ENTRY(146, sub_832B01C0, 0x832B01C0) { ctx.r3.u64 = Destroy_TXT_83334D98_G_(ctx, base); }

uint64_t Destroy_TXT_83334D9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D9C_G_ = int32_t(0x83334D9C);
	if (!UseLiftedCode(146, 0x832B01D0)) { __imp__sub_832B01D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01D0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D9C_G_);
}
PROMOTED_ENTRY(146, sub_832B01D0, 0x832B01D0) { ctx.r3.u64 = Destroy_TXT_83334D9C_G_(ctx, base); }

uint64_t Destroy_TXT_83334DA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DA0_G_ = int32_t(0x83334DA0);
	if (!UseLiftedCode(146, 0x832B01E0)) { __imp__sub_832B01E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DA0_G_);
}
PROMOTED_ENTRY(146, sub_832B01E0, 0x832B01E0) { ctx.r3.u64 = Destroy_TXT_83334DA0_G_(ctx, base); }

uint64_t Destroy_TXT_83334DA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DA4_G_ = int32_t(0x83334DA4);
	if (!UseLiftedCode(146, 0x832B01F0)) { __imp__sub_832B01F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DA4_G_);
}
PROMOTED_ENTRY(146, sub_832B01F0, 0x832B01F0) { ctx.r3.u64 = Destroy_TXT_83334DA4_G_(ctx, base); }

uint64_t Destroy_TXT_83334DA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DA8_G_ = int32_t(0x83334DA8);
	if (!UseLiftedCode(146, 0x832B0200)) { __imp__sub_832B0200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0200);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DA8_G_);
}
PROMOTED_ENTRY(146, sub_832B0200, 0x832B0200) { ctx.r3.u64 = Destroy_TXT_83334DA8_G_(ctx, base); }

uint64_t Destroy_TXT_83334DAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DAC_G_ = int32_t(0x83334DAC);
	if (!UseLiftedCode(146, 0x832B0210)) { __imp__sub_832B0210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0210);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DAC_G_);
}
PROMOTED_ENTRY(146, sub_832B0210, 0x832B0210) { ctx.r3.u64 = Destroy_TXT_83334DAC_G_(ctx, base); }

uint64_t Destroy_TXT_83334DB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DB0_G_ = int32_t(0x83334DB0);
	if (!UseLiftedCode(146, 0x832B0220)) { __imp__sub_832B0220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0220);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DB0_G_);
}
PROMOTED_ENTRY(146, sub_832B0220, 0x832B0220) { ctx.r3.u64 = Destroy_TXT_83334DB0_G_(ctx, base); }

uint64_t Destroy_TXT_83334DB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DB4_G_ = int32_t(0x83334DB4);
	if (!UseLiftedCode(146, 0x832B0230)) { __imp__sub_832B0230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0230);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DB4_G_);
}
PROMOTED_ENTRY(146, sub_832B0230, 0x832B0230) { ctx.r3.u64 = Destroy_TXT_83334DB4_G_(ctx, base); }

uint64_t Destroy_TXT_83334DB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DB8_G_ = int32_t(0x83334DB8);
	if (!UseLiftedCode(146, 0x832B0240)) { __imp__sub_832B0240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0240);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DB8_G_);
}
PROMOTED_ENTRY(146, sub_832B0240, 0x832B0240) { ctx.r3.u64 = Destroy_TXT_83334DB8_G_(ctx, base); }

uint64_t Destroy_TXT_83334DBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DBC_G_ = int32_t(0x83334DBC);
	if (!UseLiftedCode(146, 0x832B0250)) { __imp__sub_832B0250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0250);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DBC_G_);
}
PROMOTED_ENTRY(146, sub_832B0250, 0x832B0250) { ctx.r3.u64 = Destroy_TXT_83334DBC_G_(ctx, base); }

uint64_t Destroy_TXT_83334DC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DC0_G_ = int32_t(0x83334DC0);
	if (!UseLiftedCode(146, 0x832B0260)) { __imp__sub_832B0260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0260);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DC0_G_);
}
PROMOTED_ENTRY(146, sub_832B0260, 0x832B0260) { ctx.r3.u64 = Destroy_TXT_83334DC0_G_(ctx, base); }

uint64_t Destroy_TXT_83334DC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DC4_G_ = int32_t(0x83334DC4);
	if (!UseLiftedCode(146, 0x832B0270)) { __imp__sub_832B0270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0270);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DC4_G_);
}
PROMOTED_ENTRY(146, sub_832B0270, 0x832B0270) { ctx.r3.u64 = Destroy_TXT_83334DC4_G_(ctx, base); }

uint64_t Destroy_TXT_83334DD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DD4_G_ = int32_t(0x83334DD4);
	if (!UseLiftedCode(146, 0x832B0280)) { __imp__sub_832B0280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0280);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DD4_G_);
}
PROMOTED_ENTRY(146, sub_832B0280, 0x832B0280) { ctx.r3.u64 = Destroy_TXT_83334DD4_G_(ctx, base); }

uint64_t Destroy_TXT_83334DD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DD8_G_ = int32_t(0x83334DD8);
	if (!UseLiftedCode(146, 0x832B0290)) { __imp__sub_832B0290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0290);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DD8_G_);
}
PROMOTED_ENTRY(146, sub_832B0290, 0x832B0290) { ctx.r3.u64 = Destroy_TXT_83334DD8_G_(ctx, base); }

uint64_t Destroy_TXT_83334DDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DDC_G_ = int32_t(0x83334DDC);
	if (!UseLiftedCode(146, 0x832B02A0)) { __imp__sub_832B02A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DDC_G_);
}
PROMOTED_ENTRY(146, sub_832B02A0, 0x832B02A0) { ctx.r3.u64 = Destroy_TXT_83334DDC_G_(ctx, base); }

uint64_t Destroy_TXT_83334DE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DE0_G_ = int32_t(0x83334DE0);
	if (!UseLiftedCode(146, 0x832B02B0)) { __imp__sub_832B02B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02B0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DE0_G_);
}
PROMOTED_ENTRY(146, sub_832B02B0, 0x832B02B0) { ctx.r3.u64 = Destroy_TXT_83334DE0_G_(ctx, base); }

uint64_t Destroy_TXT_83334DE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DE4_G_ = int32_t(0x83334DE4);
	if (!UseLiftedCode(146, 0x832B02C0)) { __imp__sub_832B02C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02C0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DE4_G_);
}
PROMOTED_ENTRY(146, sub_832B02C0, 0x832B02C0) { ctx.r3.u64 = Destroy_TXT_83334DE4_G_(ctx, base); }

uint64_t Destroy_TXT_83334DE8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DE8_G_ = int32_t(0x83334DE8);
	if (!UseLiftedCode(146, 0x832B02D0)) { __imp__sub_832B02D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02D0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DE8_G_);
}
PROMOTED_ENTRY(146, sub_832B02D0, 0x832B02D0) { ctx.r3.u64 = Destroy_TXT_83334DE8_G_(ctx, base); }

uint64_t Destroy_TXT_83334DEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DEC_G_ = int32_t(0x83334DEC);
	if (!UseLiftedCode(146, 0x832B02E0)) { __imp__sub_832B02E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DEC_G_);
}
PROMOTED_ENTRY(146, sub_832B02E0, 0x832B02E0) { ctx.r3.u64 = Destroy_TXT_83334DEC_G_(ctx, base); }

uint64_t Destroy_TXT_83334DF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DF0_G_ = int32_t(0x83334DF0);
	if (!UseLiftedCode(146, 0x832B02F0)) { __imp__sub_832B02F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DF0_G_);
}
PROMOTED_ENTRY(146, sub_832B02F0, 0x832B02F0) { ctx.r3.u64 = Destroy_TXT_83334DF0_G_(ctx, base); }

uint64_t Destroy_TXT_83334DF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DF4_G_ = int32_t(0x83334DF4);
	if (!UseLiftedCode(146, 0x832B0300)) { __imp__sub_832B0300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0300);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DF4_G_);
}
PROMOTED_ENTRY(146, sub_832B0300, 0x832B0300) { ctx.r3.u64 = Destroy_TXT_83334DF4_G_(ctx, base); }

uint64_t Destroy_TXT_83334DF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DF8_G_ = int32_t(0x83334DF8);
	if (!UseLiftedCode(146, 0x832B0310)) { __imp__sub_832B0310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0310);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DF8_G_);
}
PROMOTED_ENTRY(146, sub_832B0310, 0x832B0310) { ctx.r3.u64 = Destroy_TXT_83334DF8_G_(ctx, base); }

uint64_t Destroy_TXT_83334DFC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DFC_G_ = int32_t(0x83334DFC);
	if (!UseLiftedCode(146, 0x832B0320)) { __imp__sub_832B0320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0320);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DFC_G_);
}
PROMOTED_ENTRY(146, sub_832B0320, 0x832B0320) { ctx.r3.u64 = Destroy_TXT_83334DFC_G_(ctx, base); }

uint64_t Destroy_TXT_83334E00_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E00_G_ = int32_t(0x83334E00);
	if (!UseLiftedCode(146, 0x832B0330)) { __imp__sub_832B0330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0330);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E00_G_);
}
PROMOTED_ENTRY(146, sub_832B0330, 0x832B0330) { ctx.r3.u64 = Destroy_TXT_83334E00_G_(ctx, base); }

uint64_t Destroy_TXT_83334E04_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E04_G_ = int32_t(0x83334E04);
	if (!UseLiftedCode(146, 0x832B0340)) { __imp__sub_832B0340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0340);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E04_G_);
}
PROMOTED_ENTRY(146, sub_832B0340, 0x832B0340) { ctx.r3.u64 = Destroy_TXT_83334E04_G_(ctx, base); }

uint64_t Destroy_TXT_83334E08_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E08_G_ = int32_t(0x83334E08);
	if (!UseLiftedCode(146, 0x832B0350)) { __imp__sub_832B0350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0350);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E08_G_);
}
PROMOTED_ENTRY(146, sub_832B0350, 0x832B0350) { ctx.r3.u64 = Destroy_TXT_83334E08_G_(ctx, base); }

uint64_t Destroy_TXT_83334E18_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E18_G_ = int32_t(0x83334E18);
	if (!UseLiftedCode(146, 0x832B0360)) { __imp__sub_832B0360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0360);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E18_G_);
}
PROMOTED_ENTRY(146, sub_832B0360, 0x832B0360) { ctx.r3.u64 = Destroy_TXT_83334E18_G_(ctx, base); }

uint64_t Destroy_TXT_83334E1C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E1C_G_ = int32_t(0x83334E1C);
	if (!UseLiftedCode(146, 0x832B0370)) { __imp__sub_832B0370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0370);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E1C_G_);
}
PROMOTED_ENTRY(146, sub_832B0370, 0x832B0370) { ctx.r3.u64 = Destroy_TXT_83334E1C_G_(ctx, base); }

uint64_t Global83334E20_DestroyHandleTargetLinkedList(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334E20 = int32_t(0x83334E20);
	if (!UseLiftedCode(146, 0x832B0380)) { __imp__sub_832B0380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0380);
	return DestroyHandleTargetLinkedList(ctx, base, g_83334E20);
}
PROMOTED_ENTRY(146, sub_832B0380, 0x832B0380) { ctx.r3.u64 = Global83334E20_DestroyHandleTargetLinkedList(ctx, base); }

uint64_t Destroy_TXT_83334E48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E48_G_ = int32_t(0x83334E48);
	if (!UseLiftedCode(146, 0x832B0390)) { __imp__sub_832B0390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0390);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E48_G_);
}
PROMOTED_ENTRY(146, sub_832B0390, 0x832B0390) { ctx.r3.u64 = Destroy_TXT_83334E48_G_(ctx, base); }

uint64_t Destroy_TXT_83334E4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E4C_G_ = int32_t(0x83334E4C);
	if (!UseLiftedCode(146, 0x832B03A0)) { __imp__sub_832B03A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B03A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E4C_G_);
}
PROMOTED_ENTRY(146, sub_832B03A0, 0x832B03A0) { ctx.r3.u64 = Destroy_TXT_83334E4C_G_(ctx, base); }

uint64_t n_sub_832B0460(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334F48 = int32_t(0x83334F48);
	if (!UseLiftedCode(146, 0x832B0460)) { __imp__sub_832B0460(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0460);
	return CallFlourishChargeTimeTwice(ctx, base, g_83334F48);
}
PROMOTED_ENTRY(146, sub_832B0460, 0x832B0460) { ctx.r3.u64 = n_sub_832B0460(ctx, base); }

uint64_t Global833357C8_ReleaseCCharString(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833357C8 = int32_t(0x833357C8);
	if (!UseLiftedCode(146, 0x832B04E0)) { __imp__sub_832B04E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B04E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, g_833357C8);
}
PROMOTED_ENTRY(146, sub_832B04E0, 0x832B04E0) { ctx.r3.u64 = Global833357C8_ReleaseCCharString(ctx, base); }

uint64_t Global833357C4_ReleaseCCharString(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833357C4 = int32_t(0x833357C4);
	if (!UseLiftedCode(146, 0x832B04F0)) { __imp__sub_832B04F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B04F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, g_833357C4);
}
PROMOTED_ENTRY(146, sub_832B04F0, 0x832B04F0) { ctx.r3.u64 = Global833357C4_ReleaseCCharString(ctx, base); }

uint64_t Global832EE794_DestroyVirtualFileSystem(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832EE794 = int32_t(0x832EE794);
	if (!UseLiftedCode(146, 0x832B05D8)) { __imp__sub_832B05D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B05D8);
	return CVirtualFileSystem_Destructor(ctx, base, g_832EE794);
}
PROMOTED_ENTRY(146, sub_832B05D8, 0x832B05D8) { ctx.r3.u64 = Global832EE794_DestroyVirtualFileSystem(ctx, base); }

uint64_t n_sub_832B0770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83337008 = int32_t(0x83337008);
	if (!UseLiftedCode(146, 0x832B0770)) { __imp__sub_832B0770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0770);
	uint64_t object = g_83337008;
	return AtomicDecrementGlobalCounter(ctx, base);
}
PROMOTED_ENTRY(146, sub_832B0770, 0x832B0770) { ctx.r3.u64 = n_sub_832B0770(ctx, base); }

uint64_t n_sub_832B0780(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83337054 = int32_t(0x83337054);
	if (!UseLiftedCode(146, 0x832B0780)) { __imp__sub_832B0780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0780);
	uint64_t object = g_83337054;
	return AtomicDecrementGlobalCounter(ctx, base);
}
PROMOTED_ENTRY(146, sub_832B0780, 0x832B0780) { ctx.r3.u64 = n_sub_832B0780(ctx, base); }

uint64_t Global83337055_RunAtExitCallbacks(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83337055 = int32_t(0x83337055);
	if (!UseLiftedCode(146, 0x832B0790)) { __imp__sub_832B0790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0790);
	uint64_t object = g_83337055;
	ctx.r3.u64 = object;
	return RunRegisteredAtExitFunctions(ctx, base);
}
PROMOTED_ENTRY(146, sub_832B0790, 0x832B0790) { ctx.r3.u64 = Global83337055_RunAtExitCallbacks(ctx, base); }

// sub_832B0B60  [20 bytes]
void n_sub_832B0B60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0B60)) { __imp__sub_832B0B60(ctx, base); return; }
	LiftedFrame frame(0x832B0B60);
	uint32_t globalObject = uint32_t(g_83340000) - 9840;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0B60, 0x832B0B60) { n_sub_832B0B60(ctx, base); }

void n_sub_832B0BA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0BA8)) { __imp__sub_832B0BA8(ctx, base); return; }
	LiftedFrame frame(0x832B0BA8);
	uint32_t globalObject = uint32_t(g_83340000) - 7976;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0BA8, 0x832B0BA8) { n_sub_832B0BA8(ctx, base); }

void n_sub_832B0BC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0BC0)) { __imp__sub_832B0BC0(ctx, base); return; }
	LiftedFrame frame(0x832B0BC0);
	uint32_t globalObject = uint32_t(g_83340000) - 6944;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0BC0, 0x832B0BC0) { n_sub_832B0BC0(ctx, base); }

void n_sub_832B0BD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0BD8)) { __imp__sub_832B0BD8(ctx, base); return; }
	LiftedFrame frame(0x832B0BD8);
	uint32_t globalObject = uint32_t(g_83340000) - 4880;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0BD8, 0x832B0BD8) { n_sub_832B0BD8(ctx, base); }

void n_sub_832B0BF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0BF0)) { __imp__sub_832B0BF0(ctx, base); return; }
	LiftedFrame frame(0x832B0BF0);
	uint32_t globalObject = uint32_t(g_83340000) - 5912;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0BF0, 0x832B0BF0) { n_sub_832B0BF0(ctx, base); }

void n_sub_832B0C08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0C08)) { __imp__sub_832B0C08(ctx, base); return; }
	LiftedFrame frame(0x832B0C08);
	uint32_t globalObject = uint32_t(g_83340000) - 3848;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0C08, 0x832B0C08) { n_sub_832B0C08(ctx, base); }

void n_sub_832B0C20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0C20)) { __imp__sub_832B0C20(ctx, base); return; }
	LiftedFrame frame(0x832B0C20);
	uint32_t globalObject = uint32_t(g_83340000) - 2816;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0C20, 0x832B0C20) { n_sub_832B0C20(ctx, base); }

void n_sub_832B0C38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0C38)) { __imp__sub_832B0C38(ctx, base); return; }
	LiftedFrame frame(0x832B0C38);
	uint32_t globalObject = uint32_t(g_83340000) - 1784;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0C38, 0x832B0C38) { n_sub_832B0C38(ctx, base); }

void n_sub_832B0C70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0C70)) { __imp__sub_832B0C70(ctx, base); return; }
	LiftedFrame frame(0x832B0C70);
	uint32_t globalObject = uint32_t(g_83340000) - 440;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0C70, 0x832B0C70) { n_sub_832B0C70(ctx, base); }

// sub_832B0C88  [20 bytes]
void n_sub_832B0C88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0C88)) { __imp__sub_832B0C88(ctx, base); return; }
	LiftedFrame frame(0x832B0C88);
	uint32_t globalObject = g_83340000 + 592;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0C88, 0x832B0C88) { n_sub_832B0C88(ctx, base); }

void n_sub_832B0CA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0CA0)) { __imp__sub_832B0CA0(ctx, base); return; }
	LiftedFrame frame(0x832B0CA0);
	uint32_t globalObject = g_83340000 + 1624;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0CA0, 0x832B0CA0) { n_sub_832B0CA0(ctx, base); }

void n_sub_832B0CD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0CD0)) { __imp__sub_832B0CD0(ctx, base); return; }
	LiftedFrame frame(0x832B0CD0);
	uint32_t globalObject = g_83340000 + 2664;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0CD0, 0x832B0CD0) { n_sub_832B0CD0(ctx, base); }

void n_sub_832B0CE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0CE8)) { __imp__sub_832B0CE8(ctx, base); return; }
	LiftedFrame frame(0x832B0CE8);
	uint32_t globalObject = g_83340000 + 3984;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0CE8, 0x832B0CE8) { n_sub_832B0CE8(ctx, base); }

void n_sub_832B0D18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0D18)) { __imp__sub_832B0D18(ctx, base); return; }
	LiftedFrame frame(0x832B0D18);
	uint32_t globalObject = g_83340000 + 5016;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0D18, 0x832B0D18) { n_sub_832B0D18(ctx, base); }

void n_sub_832B0D78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0D78)) { __imp__sub_832B0D78(ctx, base); return; }
	LiftedFrame frame(0x832B0D78);
	uint32_t globalObject = g_83340000 + 6880;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0D78, 0x832B0D78) { n_sub_832B0D78(ctx, base); }

void n_sub_832B0DF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0DF0)) { __imp__sub_832B0DF0(ctx, base); return; }
	LiftedFrame frame(0x832B0DF0);
	uint32_t globalObject = g_83340000 + 9296;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0DF0, 0x832B0DF0) { n_sub_832B0DF0(ctx, base); }

void n_sub_832B0E20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0E20)) { __imp__sub_832B0E20(ctx, base); return; }
	LiftedFrame frame(0x832B0E20);
	uint32_t globalObject = g_83340000 + 10328;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0E20, 0x832B0E20) { n_sub_832B0E20(ctx, base); }

void n_sub_832B0F28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B0F28)) { __imp__sub_832B0F28(ctx, base); return; }
	LiftedFrame frame(0x832B0F28);
	uint32_t globalObject = g_83340000 + 19672;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B0F28, 0x832B0F28) { n_sub_832B0F28(ctx, base); }

void n_sub_832B1018(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B1018)) { __imp__sub_832B1018(ctx, base); return; }
	LiftedFrame frame(0x832B1018);
	uint32_t globalObject = g_83340000 + 25408;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1018, 0x832B1018) { n_sub_832B1018(ctx, base); }

void n_sub_832B10D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B10D8)) { __imp__sub_832B10D8(ctx, base); return; }
	LiftedFrame frame(0x832B10D8);
	uint32_t globalObject = g_83340000 + 28648;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B10D8, 0x832B10D8) { n_sub_832B10D8(ctx, base); }

void n_sub_832B1138(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B1138)) { __imp__sub_832B1138(ctx, base); return; }
	LiftedFrame frame(0x832B1138);
	uint32_t globalObject = g_83340000 + 30584;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1138, 0x832B1138) { n_sub_832B1138(ctx, base); }

void n_sub_832B1168(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B1168)) { __imp__sub_832B1168(ctx, base); return; }
	LiftedFrame frame(0x832B1168);
	uint32_t globalObject = g_83340000 + 32656;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1168, 0x832B1168) { n_sub_832B1168(ctx, base); }

void n_sub_832B1180(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83340000 = int32_t(0x83340000);
	if (!UseLiftedCode(146, 0x832B1180)) { __imp__sub_832B1180(ctx, base); return; }
	LiftedFrame frame(0x832B1180);
	uint32_t globalObject = g_83340000 + 31624;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1180, 0x832B1180) { n_sub_832B1180(ctx, base); }

uint64_t Global833484C0_Destructor(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833484C0 = int32_t(0x833484C0);
	if (!UseLiftedCode(146, 0x832B1198)) { __imp__sub_832B1198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1198);
	return n_sub_82E7E4F8(ctx, base, g_833484C0);
}
PROMOTED_ENTRY(146, sub_832B1198, 0x832B1198) { ctx.r3.u64 = Global833484C0_Destructor(ctx, base); }

void n_sub_832B1220(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1220)) { __imp__sub_832B1220(ctx, base); return; }
	LiftedFrame frame(0x832B1220);
	uint32_t globalObject = uint32_t(g_83350000) - 31368;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1220, 0x832B1220) { n_sub_832B1220(ctx, base); }

void n_sub_832B13D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B13D0)) { __imp__sub_832B13D0(ctx, base); return; }
	LiftedFrame frame(0x832B13D0);
	uint32_t globalObject = uint32_t(g_83350000) - 14872;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B13D0, 0x832B13D0) { n_sub_832B13D0(ctx, base); }

void n_sub_832B13E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B13E8)) { __imp__sub_832B13E8(ctx, base); return; }
	LiftedFrame frame(0x832B13E8);
	uint32_t globalObject = uint32_t(g_83350000) - 15904;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B13E8, 0x832B13E8) { n_sub_832B13E8(ctx, base); }

void n_sub_832B1400(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1400)) { __imp__sub_832B1400(ctx, base); return; }
	LiftedFrame frame(0x832B1400);
	uint32_t globalObject = uint32_t(g_83350000) - 16936;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1400, 0x832B1400) { n_sub_832B1400(ctx, base); }

void n_sub_832B1418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1418)) { __imp__sub_832B1418(ctx, base); return; }
	LiftedFrame frame(0x832B1418);
	uint32_t globalObject = uint32_t(g_83350000) - 17968;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1418, 0x832B1418) { n_sub_832B1418(ctx, base); }

void n_sub_832B1430(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1430)) { __imp__sub_832B1430(ctx, base); return; }
	LiftedFrame frame(0x832B1430);
	uint32_t globalObject = uint32_t(g_83350000) - 19000;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1430, 0x832B1430) { n_sub_832B1430(ctx, base); }

void n_sub_832B1448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1448)) { __imp__sub_832B1448(ctx, base); return; }
	LiftedFrame frame(0x832B1448);
	uint32_t globalObject = uint32_t(g_83350000) - 20032;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1448, 0x832B1448) { n_sub_832B1448(ctx, base); }

void n_sub_832B1460(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1460)) { __imp__sub_832B1460(ctx, base); return; }
	LiftedFrame frame(0x832B1460);
	uint32_t globalObject = uint32_t(g_83350000) - 21064;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1460, 0x832B1460) { n_sub_832B1460(ctx, base); }

void n_sub_832B1478(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1478)) { __imp__sub_832B1478(ctx, base); return; }
	LiftedFrame frame(0x832B1478);
	uint32_t globalObject = uint32_t(g_83350000) - 22096;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1478, 0x832B1478) { n_sub_832B1478(ctx, base); }

void n_sub_832B1490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B1490)) { __imp__sub_832B1490(ctx, base); return; }
	LiftedFrame frame(0x832B1490);
	uint32_t globalObject = uint32_t(g_83350000) - 23128;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B1490, 0x832B1490) { n_sub_832B1490(ctx, base); }

void n_sub_832B14A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B14A8)) { __imp__sub_832B14A8(ctx, base); return; }
	LiftedFrame frame(0x832B14A8);
	uint32_t globalObject = uint32_t(g_83350000) - 24160;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B14A8, 0x832B14A8) { n_sub_832B14A8(ctx, base); }

void n_sub_832B14C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83350000 = int32_t(0x83350000);
	if (!UseLiftedCode(146, 0x832B14C0)) { __imp__sub_832B14C0(ctx, base); return; }
	LiftedFrame frame(0x832B14C0);
	uint32_t globalObject = uint32_t(g_83350000) - 25192;
	STORE32(globalObject + 1024, 0u);
}
PROMOTED_ENTRY(146, sub_832B14C0, 0x832B14C0) { n_sub_832B14C0(ctx, base); }

uint64_t Global833593D0_Destructor(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833593D0 = int32_t(0x833593D0);
	if (!UseLiftedCode(146, 0x832B19B0)) { __imp__sub_832B19B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B19B0);
	return C_8203D270_Destructor(ctx, base, g_833593D0);
}
PROMOTED_ENTRY(146, sub_832B19B0, 0x832B19B0) { ctx.r3.u64 = Global833593D0_Destructor(ctx, base); }

// sub_832B1CB0  [40 bytes]
// Release function for the global at g_83359698, registered atexit: tears it down with
// n_sub_82FFCB18 and returns its address.
uint64_t n_sub_832B1CB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83359698 = int32_t(0x83359698);
	if (!UseLiftedCode(146, 0x832B1CB0)) { __imp__sub_832B1CB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1CB0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_83359698;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1CB0, 0x832B1CB0) { ctx.r3.u64 = n_sub_832B1CB0(ctx, base); }

// sub_832B1CD8  [40 bytes]
// Release function of the global at g_8335968C, registered with atexit: releases it with n_sub_82FFD370
// (the incoming value is handed on as the second argument) and returns that call's result.
uint64_t n_sub_832B1CD8(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_8335968C = int32_t(0x8335968C);
	if (!UseLiftedCode(146, 0x832B1CD8)) { ctx.r8.u64 = forwarded; __imp__sub_832B1CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1CD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_8335968C;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1CD8, 0x832B1CD8) { ctx.r3.u64 = n_sub_832B1CD8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1D00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833596C8 = int32_t(0x833596C8);
	if (!UseLiftedCode(146, 0x832B1D00)) { __imp__sub_832B1D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1D00);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833596C8;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1D00, 0x832B1D00) { ctx.r3.u64 = n_sub_832B1D00(ctx, base); }

uint64_t n_sub_832B1D28(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_833596BC = int32_t(0x833596BC);
	if (!UseLiftedCode(146, 0x832B1D28)) { ctx.r8.u64 = forwarded; __imp__sub_832B1D28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1D28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833596BC;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1D28, 0x832B1D28) { ctx.r3.u64 = n_sub_832B1D28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1D50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833596F8 = int32_t(0x833596F8);
	if (!UseLiftedCode(146, 0x832B1D50)) { __imp__sub_832B1D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1D50);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833596F8;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1D50, 0x832B1D50) { ctx.r3.u64 = n_sub_832B1D50(ctx, base); }

uint64_t n_sub_832B1D78(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_833596EC = int32_t(0x833596EC);
	if (!UseLiftedCode(146, 0x832B1D78)) { ctx.r8.u64 = forwarded; __imp__sub_832B1D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1D78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833596EC;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1D78, 0x832B1D78) { ctx.r3.u64 = n_sub_832B1D78(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1DA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83359768 = int32_t(0x83359768);
	if (!UseLiftedCode(146, 0x832B1DA0)) { __imp__sub_832B1DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1DA0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_83359768;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1DA0, 0x832B1DA0) { ctx.r3.u64 = n_sub_832B1DA0(ctx, base); }

uint64_t n_sub_832B1DC8(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_8335975C = int32_t(0x8335975C);
	if (!UseLiftedCode(146, 0x832B1DC8)) { ctx.r8.u64 = forwarded; __imp__sub_832B1DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_8335975C;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1DC8, 0x832B1DC8) { ctx.r3.u64 = n_sub_832B1DC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1DF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83359828 = int32_t(0x83359828);
	if (!UseLiftedCode(146, 0x832B1DF0)) { __imp__sub_832B1DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1DF0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_83359828;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1DF0, 0x832B1DF0) { ctx.r3.u64 = n_sub_832B1DF0(ctx, base); }

uint64_t n_sub_832B1E18(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_8335981C = int32_t(0x8335981C);
	if (!UseLiftedCode(146, 0x832B1E18)) { ctx.r8.u64 = forwarded; __imp__sub_832B1E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1E18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_8335981C;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1E18, 0x832B1E18) { ctx.r3.u64 = n_sub_832B1E18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1E40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833597F8 = int32_t(0x833597F8);
	if (!UseLiftedCode(146, 0x832B1E40)) { __imp__sub_832B1E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1E40);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833597F8;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1E40, 0x832B1E40) { ctx.r3.u64 = n_sub_832B1E40(ctx, base); }

uint64_t n_sub_832B1E68(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_833597EC = int32_t(0x833597EC);
	if (!UseLiftedCode(146, 0x832B1E68)) { ctx.r8.u64 = forwarded; __imp__sub_832B1E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1E68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833597EC;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1E68, 0x832B1E68) { ctx.r3.u64 = n_sub_832B1E68(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1E90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833597C8 = int32_t(0x833597C8);
	if (!UseLiftedCode(146, 0x832B1E90)) { __imp__sub_832B1E90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1E90);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833597C8;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1E90, 0x832B1E90) { ctx.r3.u64 = n_sub_832B1E90(ctx, base); }

uint64_t n_sub_832B1EB8(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_833597BC = int32_t(0x833597BC);
	if (!UseLiftedCode(146, 0x832B1EB8)) { ctx.r8.u64 = forwarded; __imp__sub_832B1EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833597BC;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1EB8, 0x832B1EB8) { ctx.r3.u64 = n_sub_832B1EB8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1EE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83359798 = int32_t(0x83359798);
	if (!UseLiftedCode(146, 0x832B1EE0)) { __imp__sub_832B1EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1EE0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_83359798;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1EE0, 0x832B1EE0) { ctx.r3.u64 = n_sub_832B1EE0(ctx, base); }

uint64_t n_sub_832B1F08(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_8335978C = int32_t(0x8335978C);
	if (!UseLiftedCode(146, 0x832B1F08)) { ctx.r8.u64 = forwarded; __imp__sub_832B1F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_8335978C;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1F08, 0x832B1F08) { ctx.r3.u64 = n_sub_832B1F08(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1F30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8335985C = int32_t(0x8335985C);
	if (!UseLiftedCode(146, 0x832B1F30)) { __imp__sub_832B1F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1F30);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_8335985C;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1F30, 0x832B1F30) { ctx.r3.u64 = n_sub_832B1F30(ctx, base); }

uint64_t n_sub_832B1F58(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_83359850 = int32_t(0x83359850);
	if (!UseLiftedCode(146, 0x832B1F58)) { ctx.r8.u64 = forwarded; __imp__sub_832B1F58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1F58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_83359850;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1F58, 0x832B1F58) { ctx.r3.u64 = n_sub_832B1F58(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1F80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8335988C = int32_t(0x8335988C);
	if (!UseLiftedCode(146, 0x832B1F80)) { __imp__sub_832B1F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1F80);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_8335988C;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1F80, 0x832B1F80) { ctx.r3.u64 = n_sub_832B1F80(ctx, base); }

uint64_t n_sub_832B1FA8(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_83359880 = int32_t(0x83359880);
	if (!UseLiftedCode(146, 0x832B1FA8)) { ctx.r8.u64 = forwarded; __imp__sub_832B1FA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1FA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_83359880;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1FA8, 0x832B1FA8) { ctx.r3.u64 = n_sub_832B1FA8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B1FD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833598EC = int32_t(0x833598EC);
	if (!UseLiftedCode(146, 0x832B1FD0)) { __imp__sub_832B1FD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1FD0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833598EC;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B1FD0, 0x832B1FD0) { ctx.r3.u64 = n_sub_832B1FD0(ctx, base); }

uint64_t n_sub_832B1FF8(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_833598E0 = int32_t(0x833598E0);
	if (!UseLiftedCode(146, 0x832B1FF8)) { ctx.r8.u64 = forwarded; __imp__sub_832B1FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1FF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833598E0;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B1FF8, 0x832B1FF8) { ctx.r3.u64 = n_sub_832B1FF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B2020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833598BC = int32_t(0x833598BC);
	if (!UseLiftedCode(146, 0x832B2020)) { __imp__sub_832B2020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B2020);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833598BC;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B2020, 0x832B2020) { ctx.r3.u64 = n_sub_832B2020(ctx, base); }

uint64_t n_sub_832B2048(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_833598B0 = int32_t(0x833598B0);
	if (!UseLiftedCode(146, 0x832B2048)) { ctx.r8.u64 = forwarded; __imp__sub_832B2048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B2048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_833598B0;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFD370(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B2048, 0x832B2048) { ctx.r3.u64 = n_sub_832B2048(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832B2098(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8335996C = int32_t(0x8335996C);
	if (!UseLiftedCode(146, 0x832B2098)) { __imp__sub_832B2098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B2098);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_8335996C;
	ctx.r1.u64 = stack;
	n_sub_82FFCB18(ctx, base, object);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(146, sub_832B2098, 0x832B2098) { ctx.r3.u64 = n_sub_832B2098(ctx, base); }

uint64_t n_sub_832B20C0(CpuState& ctx, uint8_t* base, uint64_t forwarded) {
	constexpr int32_t g_83359990 = int32_t(0x83359990);
	if (!UseLiftedCode(146, 0x832B20C0)) { ctx.r8.u64 = forwarded; __imp__sub_832B20C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B20C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t object = g_83359990;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFF7B0(ctx, base, object, forwarded);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(146, sub_832B20C0, 0x832B20C0) { ctx.r3.u64 = n_sub_832B20C0(ctx, base, ctx.r8.u64); }
