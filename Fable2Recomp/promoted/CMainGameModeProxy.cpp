// CMainGameModeProxy (vtable 0x820A69F0): methods of the class as readable C++.
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

uint64_t CMainGameModeProxy_GetMainGameMode(CpuState& ctx, uint8_t* base, uint32_t mainGameModeProxyAddr) {
	if (!UseLiftedCode(17, 0x82356328)) { ctx.r3.u64 = mainGameModeProxyAddr; __imp__sub_82356328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82356328);
	uint32_t mainGameMode{};
	CMainGameModeProxy* mainGameModeProxy = GameObject<CMainGameModeProxy>(base, mainGameModeProxyAddr);
	mainGameMode = LOAD32(uint32_t(mainGameModeProxy->m_pImpl) + 24);
	return mainGameMode;
}
PROMOTED_ENTRY(17, sub_82356328, 0x82356328) { ctx.r3.u64 = CMainGameModeProxy_GetMainGameMode(ctx, base, ctx.r3.u32); }

uint64_t CMainGameModeProxy_GetMainGameModeState(CpuState& ctx, uint8_t* base, uint32_t mainGameModeProxyAddr) {
	if (!UseLiftedCode(17, 0x82356338)) { ctx.r3.u64 = mainGameModeProxyAddr; __imp__sub_82356338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82356338);
	uint32_t mainGameModeState{};
	CMainGameModeProxy* mainGameModeProxy = GameObject<CMainGameModeProxy>(base, mainGameModeProxyAddr);
	mainGameModeState = LOAD32(uint32_t(mainGameModeProxy->m_pImpl) + 28);
	return mainGameModeState;
}
PROMOTED_ENTRY(17, sub_82356338, 0x82356338) { ctx.r3.u64 = CMainGameModeProxy_GetMainGameModeState(ctx, base, ctx.r3.u32); }
