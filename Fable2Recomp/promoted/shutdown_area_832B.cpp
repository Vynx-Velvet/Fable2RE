// Shut-down destructors of global objects at 0x832Bxxxx, as readable C++.
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

uint64_t n_sub_832B0020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334CB4 = int32_t(0x83334CB4);
	if (!UseLiftedCode(146, 0x832B0020)) { __imp__sub_832B0020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0020);
	return n_sub_82C08B20(ctx, base, g_83334CB4);
}
PROMOTED_ENTRY(146, sub_832B0020, 0x832B0020) { ctx.r3.u64 = n_sub_832B0020(ctx, base); }

uint64_t n_sub_832B0030(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334CF0 = int32_t(0x83334CF0);
	if (!UseLiftedCode(146, 0x832B0030)) { __imp__sub_832B0030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0030);
	return n_sub_82C08B20(ctx, base, g_83334CF0);
}
PROMOTED_ENTRY(146, sub_832B0030, 0x832B0030) { ctx.r3.u64 = n_sub_832B0030(ctx, base); }

uint64_t n_sub_832B0040(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D38_G_ = int32_t(0x83334D38);
	if (!UseLiftedCode(146, 0x832B0040)) { __imp__sub_832B0040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0040);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D38_G_);
}
PROMOTED_ENTRY(146, sub_832B0040, 0x832B0040) { ctx.r3.u64 = n_sub_832B0040(ctx, base); }

uint64_t n_sub_832B0050(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D3C_G_ = int32_t(0x83334D3C);
	if (!UseLiftedCode(146, 0x832B0050)) { __imp__sub_832B0050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0050);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D3C_G_);
}
PROMOTED_ENTRY(146, sub_832B0050, 0x832B0050) { ctx.r3.u64 = n_sub_832B0050(ctx, base); }

uint64_t n_sub_832B0060(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D40_G_ = int32_t(0x83334D40);
	if (!UseLiftedCode(146, 0x832B0060)) { __imp__sub_832B0060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0060);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D40_G_);
}
PROMOTED_ENTRY(146, sub_832B0060, 0x832B0060) { ctx.r3.u64 = n_sub_832B0060(ctx, base); }

uint64_t n_sub_832B0070(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D44_G_ = int32_t(0x83334D44);
	if (!UseLiftedCode(146, 0x832B0070)) { __imp__sub_832B0070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0070);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D44_G_);
}
PROMOTED_ENTRY(146, sub_832B0070, 0x832B0070) { ctx.r3.u64 = n_sub_832B0070(ctx, base); }

uint64_t n_sub_832B0080(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D48_G_ = int32_t(0x83334D48);
	if (!UseLiftedCode(146, 0x832B0080)) { __imp__sub_832B0080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0080);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D48_G_);
}
PROMOTED_ENTRY(146, sub_832B0080, 0x832B0080) { ctx.r3.u64 = n_sub_832B0080(ctx, base); }

uint64_t n_sub_832B0090(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D4C_G_ = int32_t(0x83334D4C);
	if (!UseLiftedCode(146, 0x832B0090)) { __imp__sub_832B0090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0090);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D4C_G_);
}
PROMOTED_ENTRY(146, sub_832B0090, 0x832B0090) { ctx.r3.u64 = n_sub_832B0090(ctx, base); }

uint64_t n_sub_832B00A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D50_G_ = int32_t(0x83334D50);
	if (!UseLiftedCode(146, 0x832B00A0)) { __imp__sub_832B00A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D50_G_);
}
PROMOTED_ENTRY(146, sub_832B00A0, 0x832B00A0) { ctx.r3.u64 = n_sub_832B00A0(ctx, base); }

uint64_t n_sub_832B00B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D54_G_ = int32_t(0x83334D54);
	if (!UseLiftedCode(146, 0x832B00B0)) { __imp__sub_832B00B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00B0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D54_G_);
}
PROMOTED_ENTRY(146, sub_832B00B0, 0x832B00B0) { ctx.r3.u64 = n_sub_832B00B0(ctx, base); }

uint64_t n_sub_832B00C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D58_G_ = int32_t(0x83334D58);
	if (!UseLiftedCode(146, 0x832B00C0)) { __imp__sub_832B00C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00C0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D58_G_);
}
PROMOTED_ENTRY(146, sub_832B00C0, 0x832B00C0) { ctx.r3.u64 = n_sub_832B00C0(ctx, base); }

uint64_t n_sub_832B00D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D5C_G_ = int32_t(0x83334D5C);
	if (!UseLiftedCode(146, 0x832B00D0)) { __imp__sub_832B00D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00D0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D5C_G_);
}
PROMOTED_ENTRY(146, sub_832B00D0, 0x832B00D0) { ctx.r3.u64 = n_sub_832B00D0(ctx, base); }

uint64_t n_sub_832B00E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D60_G_ = int32_t(0x83334D60);
	if (!UseLiftedCode(146, 0x832B00E0)) { __imp__sub_832B00E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D60_G_);
}
PROMOTED_ENTRY(146, sub_832B00E0, 0x832B00E0) { ctx.r3.u64 = n_sub_832B00E0(ctx, base); }

uint64_t n_sub_832B00F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D64_G_ = int32_t(0x83334D64);
	if (!UseLiftedCode(146, 0x832B00F0)) { __imp__sub_832B00F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B00F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D64_G_);
}
PROMOTED_ENTRY(146, sub_832B00F0, 0x832B00F0) { ctx.r3.u64 = n_sub_832B00F0(ctx, base); }

uint64_t n_sub_832B0100(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D68_G_ = int32_t(0x83334D68);
	if (!UseLiftedCode(146, 0x832B0100)) { __imp__sub_832B0100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0100);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D68_G_);
}
PROMOTED_ENTRY(146, sub_832B0100, 0x832B0100) { ctx.r3.u64 = n_sub_832B0100(ctx, base); }

uint64_t n_sub_832B0110(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D6C_G_ = int32_t(0x83334D6C);
	if (!UseLiftedCode(146, 0x832B0110)) { __imp__sub_832B0110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0110);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D6C_G_);
}
PROMOTED_ENTRY(146, sub_832B0110, 0x832B0110) { ctx.r3.u64 = n_sub_832B0110(ctx, base); }

uint64_t n_sub_832B0120(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D70_G_ = int32_t(0x83334D70);
	if (!UseLiftedCode(146, 0x832B0120)) { __imp__sub_832B0120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0120);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D70_G_);
}
PROMOTED_ENTRY(146, sub_832B0120, 0x832B0120) { ctx.r3.u64 = n_sub_832B0120(ctx, base); }

uint64_t n_sub_832B0130(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D74_G_ = int32_t(0x83334D74);
	if (!UseLiftedCode(146, 0x832B0130)) { __imp__sub_832B0130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0130);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D74_G_);
}
PROMOTED_ENTRY(146, sub_832B0130, 0x832B0130) { ctx.r3.u64 = n_sub_832B0130(ctx, base); }

uint64_t n_sub_832B0140(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D78_G_ = int32_t(0x83334D78);
	if (!UseLiftedCode(146, 0x832B0140)) { __imp__sub_832B0140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0140);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D78_G_);
}
PROMOTED_ENTRY(146, sub_832B0140, 0x832B0140) { ctx.r3.u64 = n_sub_832B0140(ctx, base); }

uint64_t n_sub_832B0150(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D7C_G_ = int32_t(0x83334D7C);
	if (!UseLiftedCode(146, 0x832B0150)) { __imp__sub_832B0150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0150);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D7C_G_);
}
PROMOTED_ENTRY(146, sub_832B0150, 0x832B0150) { ctx.r3.u64 = n_sub_832B0150(ctx, base); }

uint64_t n_sub_832B0160(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D80_G_ = int32_t(0x83334D80);
	if (!UseLiftedCode(146, 0x832B0160)) { __imp__sub_832B0160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0160);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D80_G_);
}
PROMOTED_ENTRY(146, sub_832B0160, 0x832B0160) { ctx.r3.u64 = n_sub_832B0160(ctx, base); }

uint64_t n_sub_832B0170(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D84_G_ = int32_t(0x83334D84);
	if (!UseLiftedCode(146, 0x832B0170)) { __imp__sub_832B0170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0170);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D84_G_);
}
PROMOTED_ENTRY(146, sub_832B0170, 0x832B0170) { ctx.r3.u64 = n_sub_832B0170(ctx, base); }

uint64_t n_sub_832B0180(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D88_G_ = int32_t(0x83334D88);
	if (!UseLiftedCode(146, 0x832B0180)) { __imp__sub_832B0180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0180);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D88_G_);
}
PROMOTED_ENTRY(146, sub_832B0180, 0x832B0180) { ctx.r3.u64 = n_sub_832B0180(ctx, base); }

uint64_t n_sub_832B0190(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D8C_G_ = int32_t(0x83334D8C);
	if (!UseLiftedCode(146, 0x832B0190)) { __imp__sub_832B0190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0190);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D8C_G_);
}
PROMOTED_ENTRY(146, sub_832B0190, 0x832B0190) { ctx.r3.u64 = n_sub_832B0190(ctx, base); }

uint64_t n_sub_832B01A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D90_G_ = int32_t(0x83334D90);
	if (!UseLiftedCode(146, 0x832B01A0)) { __imp__sub_832B01A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D90_G_);
}
PROMOTED_ENTRY(146, sub_832B01A0, 0x832B01A0) { ctx.r3.u64 = n_sub_832B01A0(ctx, base); }

uint64_t n_sub_832B01B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D94_G_ = int32_t(0x83334D94);
	if (!UseLiftedCode(146, 0x832B01B0)) { __imp__sub_832B01B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01B0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D94_G_);
}
PROMOTED_ENTRY(146, sub_832B01B0, 0x832B01B0) { ctx.r3.u64 = n_sub_832B01B0(ctx, base); }

uint64_t n_sub_832B01C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D98_G_ = int32_t(0x83334D98);
	if (!UseLiftedCode(146, 0x832B01C0)) { __imp__sub_832B01C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01C0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D98_G_);
}
PROMOTED_ENTRY(146, sub_832B01C0, 0x832B01C0) { ctx.r3.u64 = n_sub_832B01C0(ctx, base); }

uint64_t n_sub_832B01D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D9C_G_ = int32_t(0x83334D9C);
	if (!UseLiftedCode(146, 0x832B01D0)) { __imp__sub_832B01D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01D0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334D9C_G_);
}
PROMOTED_ENTRY(146, sub_832B01D0, 0x832B01D0) { ctx.r3.u64 = n_sub_832B01D0(ctx, base); }

uint64_t n_sub_832B01E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DA0_G_ = int32_t(0x83334DA0);
	if (!UseLiftedCode(146, 0x832B01E0)) { __imp__sub_832B01E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DA0_G_);
}
PROMOTED_ENTRY(146, sub_832B01E0, 0x832B01E0) { ctx.r3.u64 = n_sub_832B01E0(ctx, base); }

uint64_t n_sub_832B01F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DA4_G_ = int32_t(0x83334DA4);
	if (!UseLiftedCode(146, 0x832B01F0)) { __imp__sub_832B01F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B01F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DA4_G_);
}
PROMOTED_ENTRY(146, sub_832B01F0, 0x832B01F0) { ctx.r3.u64 = n_sub_832B01F0(ctx, base); }

uint64_t n_sub_832B0200(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DA8_G_ = int32_t(0x83334DA8);
	if (!UseLiftedCode(146, 0x832B0200)) { __imp__sub_832B0200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0200);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DA8_G_);
}
PROMOTED_ENTRY(146, sub_832B0200, 0x832B0200) { ctx.r3.u64 = n_sub_832B0200(ctx, base); }

uint64_t n_sub_832B0210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DAC_G_ = int32_t(0x83334DAC);
	if (!UseLiftedCode(146, 0x832B0210)) { __imp__sub_832B0210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0210);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DAC_G_);
}
PROMOTED_ENTRY(146, sub_832B0210, 0x832B0210) { ctx.r3.u64 = n_sub_832B0210(ctx, base); }

uint64_t n_sub_832B0220(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DB0_G_ = int32_t(0x83334DB0);
	if (!UseLiftedCode(146, 0x832B0220)) { __imp__sub_832B0220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0220);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DB0_G_);
}
PROMOTED_ENTRY(146, sub_832B0220, 0x832B0220) { ctx.r3.u64 = n_sub_832B0220(ctx, base); }

uint64_t n_sub_832B0230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DB4_G_ = int32_t(0x83334DB4);
	if (!UseLiftedCode(146, 0x832B0230)) { __imp__sub_832B0230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0230);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DB4_G_);
}
PROMOTED_ENTRY(146, sub_832B0230, 0x832B0230) { ctx.r3.u64 = n_sub_832B0230(ctx, base); }

uint64_t n_sub_832B0240(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DB8_G_ = int32_t(0x83334DB8);
	if (!UseLiftedCode(146, 0x832B0240)) { __imp__sub_832B0240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0240);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DB8_G_);
}
PROMOTED_ENTRY(146, sub_832B0240, 0x832B0240) { ctx.r3.u64 = n_sub_832B0240(ctx, base); }

uint64_t n_sub_832B0250(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DBC_G_ = int32_t(0x83334DBC);
	if (!UseLiftedCode(146, 0x832B0250)) { __imp__sub_832B0250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0250);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DBC_G_);
}
PROMOTED_ENTRY(146, sub_832B0250, 0x832B0250) { ctx.r3.u64 = n_sub_832B0250(ctx, base); }

uint64_t n_sub_832B0260(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DC0_G_ = int32_t(0x83334DC0);
	if (!UseLiftedCode(146, 0x832B0260)) { __imp__sub_832B0260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0260);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DC0_G_);
}
PROMOTED_ENTRY(146, sub_832B0260, 0x832B0260) { ctx.r3.u64 = n_sub_832B0260(ctx, base); }

uint64_t n_sub_832B0270(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DC4_G_ = int32_t(0x83334DC4);
	if (!UseLiftedCode(146, 0x832B0270)) { __imp__sub_832B0270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0270);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DC4_G_);
}
PROMOTED_ENTRY(146, sub_832B0270, 0x832B0270) { ctx.r3.u64 = n_sub_832B0270(ctx, base); }

uint64_t n_sub_832B0280(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DD4_G_ = int32_t(0x83334DD4);
	if (!UseLiftedCode(146, 0x832B0280)) { __imp__sub_832B0280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0280);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DD4_G_);
}
PROMOTED_ENTRY(146, sub_832B0280, 0x832B0280) { ctx.r3.u64 = n_sub_832B0280(ctx, base); }

uint64_t n_sub_832B0290(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DD8_G_ = int32_t(0x83334DD8);
	if (!UseLiftedCode(146, 0x832B0290)) { __imp__sub_832B0290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0290);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DD8_G_);
}
PROMOTED_ENTRY(146, sub_832B0290, 0x832B0290) { ctx.r3.u64 = n_sub_832B0290(ctx, base); }

uint64_t n_sub_832B02A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DDC_G_ = int32_t(0x83334DDC);
	if (!UseLiftedCode(146, 0x832B02A0)) { __imp__sub_832B02A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DDC_G_);
}
PROMOTED_ENTRY(146, sub_832B02A0, 0x832B02A0) { ctx.r3.u64 = n_sub_832B02A0(ctx, base); }

uint64_t n_sub_832B02B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DE0_G_ = int32_t(0x83334DE0);
	if (!UseLiftedCode(146, 0x832B02B0)) { __imp__sub_832B02B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02B0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DE0_G_);
}
PROMOTED_ENTRY(146, sub_832B02B0, 0x832B02B0) { ctx.r3.u64 = n_sub_832B02B0(ctx, base); }

uint64_t n_sub_832B02C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DE4_G_ = int32_t(0x83334DE4);
	if (!UseLiftedCode(146, 0x832B02C0)) { __imp__sub_832B02C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02C0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DE4_G_);
}
PROMOTED_ENTRY(146, sub_832B02C0, 0x832B02C0) { ctx.r3.u64 = n_sub_832B02C0(ctx, base); }

uint64_t n_sub_832B02D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DE8_G_ = int32_t(0x83334DE8);
	if (!UseLiftedCode(146, 0x832B02D0)) { __imp__sub_832B02D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02D0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DE8_G_);
}
PROMOTED_ENTRY(146, sub_832B02D0, 0x832B02D0) { ctx.r3.u64 = n_sub_832B02D0(ctx, base); }

uint64_t n_sub_832B02E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DEC_G_ = int32_t(0x83334DEC);
	if (!UseLiftedCode(146, 0x832B02E0)) { __imp__sub_832B02E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DEC_G_);
}
PROMOTED_ENTRY(146, sub_832B02E0, 0x832B02E0) { ctx.r3.u64 = n_sub_832B02E0(ctx, base); }

uint64_t n_sub_832B02F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DF0_G_ = int32_t(0x83334DF0);
	if (!UseLiftedCode(146, 0x832B02F0)) { __imp__sub_832B02F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B02F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DF0_G_);
}
PROMOTED_ENTRY(146, sub_832B02F0, 0x832B02F0) { ctx.r3.u64 = n_sub_832B02F0(ctx, base); }

uint64_t n_sub_832B0300(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DF4_G_ = int32_t(0x83334DF4);
	if (!UseLiftedCode(146, 0x832B0300)) { __imp__sub_832B0300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0300);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DF4_G_);
}
PROMOTED_ENTRY(146, sub_832B0300, 0x832B0300) { ctx.r3.u64 = n_sub_832B0300(ctx, base); }

uint64_t n_sub_832B0310(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DF8_G_ = int32_t(0x83334DF8);
	if (!UseLiftedCode(146, 0x832B0310)) { __imp__sub_832B0310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0310);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DF8_G_);
}
PROMOTED_ENTRY(146, sub_832B0310, 0x832B0310) { ctx.r3.u64 = n_sub_832B0310(ctx, base); }

uint64_t n_sub_832B0320(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334DFC_G_ = int32_t(0x83334DFC);
	if (!UseLiftedCode(146, 0x832B0320)) { __imp__sub_832B0320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0320);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334DFC_G_);
}
PROMOTED_ENTRY(146, sub_832B0320, 0x832B0320) { ctx.r3.u64 = n_sub_832B0320(ctx, base); }

uint64_t n_sub_832B0330(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E00_G_ = int32_t(0x83334E00);
	if (!UseLiftedCode(146, 0x832B0330)) { __imp__sub_832B0330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0330);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E00_G_);
}
PROMOTED_ENTRY(146, sub_832B0330, 0x832B0330) { ctx.r3.u64 = n_sub_832B0330(ctx, base); }

uint64_t n_sub_832B0340(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E04_G_ = int32_t(0x83334E04);
	if (!UseLiftedCode(146, 0x832B0340)) { __imp__sub_832B0340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0340);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E04_G_);
}
PROMOTED_ENTRY(146, sub_832B0340, 0x832B0340) { ctx.r3.u64 = n_sub_832B0340(ctx, base); }

uint64_t n_sub_832B0350(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E08_G_ = int32_t(0x83334E08);
	if (!UseLiftedCode(146, 0x832B0350)) { __imp__sub_832B0350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0350);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E08_G_);
}
PROMOTED_ENTRY(146, sub_832B0350, 0x832B0350) { ctx.r3.u64 = n_sub_832B0350(ctx, base); }

uint64_t n_sub_832B0360(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E18_G_ = int32_t(0x83334E18);
	if (!UseLiftedCode(146, 0x832B0360)) { __imp__sub_832B0360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0360);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E18_G_);
}
PROMOTED_ENTRY(146, sub_832B0360, 0x832B0360) { ctx.r3.u64 = n_sub_832B0360(ctx, base); }

uint64_t n_sub_832B0370(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E1C_G_ = int32_t(0x83334E1C);
	if (!UseLiftedCode(146, 0x832B0370)) { __imp__sub_832B0370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0370);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E1C_G_);
}
PROMOTED_ENTRY(146, sub_832B0370, 0x832B0370) { ctx.r3.u64 = n_sub_832B0370(ctx, base); }

uint64_t n_sub_832B0380(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334E20 = int32_t(0x83334E20);
	if (!UseLiftedCode(146, 0x832B0380)) { __imp__sub_832B0380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0380);
	return n_sub_82B45680(ctx, base, g_83334E20);
}
PROMOTED_ENTRY(146, sub_832B0380, 0x832B0380) { ctx.r3.u64 = n_sub_832B0380(ctx, base); }

uint64_t n_sub_832B0390(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E48_G_ = int32_t(0x83334E48);
	if (!UseLiftedCode(146, 0x832B0390)) { __imp__sub_832B0390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0390);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E48_G_);
}
PROMOTED_ENTRY(146, sub_832B0390, 0x832B0390) { ctx.r3.u64 = n_sub_832B0390(ctx, base); }

uint64_t n_sub_832B03A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334E4C_G_ = int32_t(0x83334E4C);
	if (!UseLiftedCode(146, 0x832B03A0)) { __imp__sub_832B03A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B03A0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83334E4C_G_);
}
PROMOTED_ENTRY(146, sub_832B03A0, 0x832B03A0) { ctx.r3.u64 = n_sub_832B03A0(ctx, base); }

uint64_t n_sub_832B0460(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83334F48 = int32_t(0x83334F48);
	if (!UseLiftedCode(146, 0x832B0460)) { __imp__sub_832B0460(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0460);
	return n_sub_82C03BF0(ctx, base, g_83334F48);
}
PROMOTED_ENTRY(146, sub_832B0460, 0x832B0460) { ctx.r3.u64 = n_sub_832B0460(ctx, base); }

uint64_t n_sub_832B04E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833357C8 = int32_t(0x833357C8);
	if (!UseLiftedCode(146, 0x832B04E0)) { __imp__sub_832B04E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B04E0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, g_833357C8);
}
PROMOTED_ENTRY(146, sub_832B04E0, 0x832B04E0) { ctx.r3.u64 = n_sub_832B04E0(ctx, base); }

uint64_t n_sub_832B04F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833357C4 = int32_t(0x833357C4);
	if (!UseLiftedCode(146, 0x832B04F0)) { __imp__sub_832B04F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B04F0);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, g_833357C4);
}
PROMOTED_ENTRY(146, sub_832B04F0, 0x832B04F0) { ctx.r3.u64 = n_sub_832B04F0(ctx, base); }

uint64_t n_sub_832B05D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832EE794 = int32_t(0x832EE794);
	if (!UseLiftedCode(146, 0x832B05D8)) { __imp__sub_832B05D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B05D8);
	return n_sub_82C725A8(ctx, base, g_832EE794);
}
PROMOTED_ENTRY(146, sub_832B05D8, 0x832B05D8) { ctx.r3.u64 = n_sub_832B05D8(ctx, base); }

uint64_t n_sub_832B0770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83337008 = int32_t(0x83337008);
	if (!UseLiftedCode(146, 0x832B0770)) { __imp__sub_832B0770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0770);
	uint64_t object = g_83337008;
	ctx.r3.u64 = object;
	uint64_t result = n_sub_82CD1F60(ctx, base);
	return result;
}
PROMOTED_ENTRY(146, sub_832B0770, 0x832B0770) { ctx.r3.u64 = n_sub_832B0770(ctx, base); }

uint64_t n_sub_832B0780(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83337054 = int32_t(0x83337054);
	if (!UseLiftedCode(146, 0x832B0780)) { __imp__sub_832B0780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0780);
	uint64_t object = g_83337054;
	ctx.r3.u64 = object;
	uint64_t result = n_sub_82CD1F60(ctx, base);
	return result;
}
PROMOTED_ENTRY(146, sub_832B0780, 0x832B0780) { ctx.r3.u64 = n_sub_832B0780(ctx, base); }

uint64_t n_sub_832B0790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83337055 = int32_t(0x83337055);
	if (!UseLiftedCode(146, 0x832B0790)) { __imp__sub_832B0790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B0790);
	uint64_t object = g_83337055;
	ctx.r3.u64 = object;
	uint64_t result = n_sub_82CD25C8(ctx, base);
	return result;
}
PROMOTED_ENTRY(146, sub_832B0790, 0x832B0790) { ctx.r3.u64 = n_sub_832B0790(ctx, base); }

uint64_t n_sub_832B1198(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833484C0 = int32_t(0x833484C0);
	if (!UseLiftedCode(146, 0x832B1198)) { __imp__sub_832B1198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B1198);
	return n_sub_82E7E4F8(ctx, base, g_833484C0);
}
PROMOTED_ENTRY(146, sub_832B1198, 0x832B1198) { ctx.r3.u64 = n_sub_832B1198(ctx, base); }

uint64_t n_sub_832B19B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833593D0 = int32_t(0x833593D0);
	if (!UseLiftedCode(146, 0x832B19B0)) { __imp__sub_832B19B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832B19B0);
	return n_sub_82EF9118(ctx, base, g_833593D0);
}
PROMOTED_ENTRY(146, sub_832B19B0, 0x832B19B0) { ctx.r3.u64 = n_sub_832B19B0(ctx, base); }
