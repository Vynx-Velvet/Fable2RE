// CTextureRenderer (vtable 0x82002634): methods of the class as readable C++.
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

uint64_t CTextureRenderer_Apply(CpuState& ctx, uint8_t* base, uint32_t textureRendererAddr) {
	constexpr uint32_t deviceGlobal = 0x8336019Cu;
	constexpr uint32_t packetHeader = 0xC0006000u;
	if (!UseLiftedCode(10, 0x8227CDD0)) { ctx.r3.u64 = textureRendererAddr; __imp__sub_8227CDD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8227CDD0);
	uint32_t stack = ctx.r1.u64;
	CTextureRenderer* textureRenderer = GameObject<CTextureRenderer>(base, textureRendererAddr);
	stack = PushStackFrame(base, stack, 144);

	uint32_t device = LOAD32(deviceGlobal);
	STORE64(device + 8, LOAD64(device + 8) & 0x3FFFFFFFFFFFFFFFull);
	device = LOAD32(deviceGlobal);
	uint64_t deviceFlags = LOAD64(device);
	uint64_t clearedFlags = deviceFlags & ~(1ull << 53);
	STORE64(device, clearedFlags);

	// These four values are handed on to the calls; after each pass of the loop they hold what its last callee
	// left in those registers.
	uint64_t description = textureRenderer->m_description;
	uint64_t targetCount = LOAD32(uint32_t(description) + 20);
	if (uint32_t(targetCount) > 0) {
		uint32_t targetIndex = 0;
		uint32_t targetSlotAddr = textureRendererAddr + 44;
		do {
			const uint32_t shift = targetIndex * 2;
			const uint64_t targetBit = (shift & 0x20) ? 0 : 2u << (shift & 0x1F);
			const uint32_t deviceForState = LOAD32(deviceGlobal);
			ctx.r1.u64 = stack;
			ctx.r5.u64 = targetCount;
			ctx.r6.u64 = description;
			ctx.r8.u64 = deviceFlags;
			n_sub_822655B0(ctx, base, deviceForState, targetBit, clearedFlags);

			const uint32_t deviceForTarget = LOAD32(deviceGlobal);
			const uint64_t targetData = uint64_t(LOAD32(targetSlotAddr)) + 8;
			n_sub_8227CFC8(ctx, base, deviceForTarget, 1, 0, 4, targetData, 0);
			targetCount = ctx.r5.u64;
			description = ctx.r6.u64;
			clearedFlags = ctx.r7.u64;
			deviceFlags = ctx.r8.u64;
			targetIndex++;
			targetSlotAddr += 4;
		} while (targetIndex < LOAD32(uint32_t(textureRenderer->m_description) + 20));
	}

	device = LOAD32(deviceGlobal);
	uint32_t oldStateByte = LOAD8(device + 10940);
	uint32_t bufferEnd = LOAD32(device + 56);
	uint32_t writePtr = LOAD32(device + 48);
	uint32_t stateByte = oldStateByte & 0xFFFFFFFE;
	STORE32(device + 12716, 1);
	STORE32(device + 12708, 0x15555555);
	STORE8(device + 10940, uint8_t(stateByte));
	STORE32(device + 12712, 0);
	STORE32(device + 10932, 0x15555555);
	STORE32(device + 10936, 0);
	if (writePtr > bufferEnd) {
		ctx.r1.u64 = stack;
		ctx.r5.u64 = targetCount;
		ctx.r6.u64 = description;
		ctx.r8.u64 = stateByte;
		ctx.r9.u64 = bufferEnd;
		ctx.r10.u64 = oldStateByte;
		writePtr = KickOffCommandBuffer(ctx, base, device, clearedFlags);
	}
	STORE32(writePtr + 4, packetHeader);
	uint32_t packetValue = LOAD32(device + 12708);
	STORE32(writePtr + 8, packetValue);
	STORE32(device + 48, writePtr + 8);

	uint32_t deviceForConstants = LOAD32(deviceGlobal);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = packetValue;
	ctx.r10.u64 = packetHeader;
	n_sub_8227CFC8(ctx, base, deviceForConstants, 1, 4, 4, uint64_t(textureRenderer->m_40) + 8, 0);
	deviceForConstants = LOAD32(deviceGlobal);
	n_sub_8227CFC8(ctx, base, deviceForConstants, 0, 40, 4, uint64_t(textureRenderer->m_40) + 8, 0);

	device = LOAD32(deviceGlobal);
	oldStateByte = LOAD8(device + 10940);
	bufferEnd = LOAD32(device + 56);
	writePtr = LOAD32(device + 48);
	stateByte = oldStateByte & 0xFFFFFFFE;
	STORE32(device + 12716, 1);
	STORE32(device + 12708, 0x2AAAAAAA);
	STORE8(device + 10940, uint8_t(stateByte));
	STORE32(device + 12712, 0);
	STORE32(device + 10932, 0x2AAAAAAA);
	STORE32(device + 10936, 0);
	if (writePtr > bufferEnd) {
		ctx.r5.u64 = stateByte;
		ctx.r6.u64 = bufferEnd;
		ctx.r8.u64 = 0x2AAA0000;
		writePtr = KickOffCommandBuffer(ctx, base, device, oldStateByte);
	}
	STORE32(writePtr + 4, packetHeader);
	packetValue = LOAD32(device + 12708);
	STORE32(writePtr + 8, packetValue);
	STORE32(device + 48, writePtr + 8);

	deviceForConstants = LOAD32(deviceGlobal);
	ctx.r9.u64 = packetValue;
	ctx.r10.u64 = packetHeader;
	n_sub_8227CFC8(ctx, base, deviceForConstants, 1, 4, 4, uint64_t(textureRenderer->m_40) + 8, 4);
	deviceForConstants = LOAD32(deviceGlobal);
	n_sub_8227CFC8(ctx, base, deviceForConstants, 0, 40, 4, uint64_t(textureRenderer->m_40) + 8, 4);

	const uint32_t deviceForState = LOAD32(deviceGlobal);
	const uint64_t result = n_sub_822655B0(ctx, base, deviceForState, 0, ctx.r7.u64);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(10, sub_8227CDD0, 0x8227CDD0) { ctx.r3.u64 = CTextureRenderer_Apply(ctx, base, ctx.r3.u32); }

uint64_t CTextureRenderer_Render(CpuState& ctx, uint8_t* base, uint64_t textureRendererAddr, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr uint32_t resourceRefVtable = 0x820F1D6Cu;
	constexpr uint32_t deviceGlobal = 0x8336019Cu;
	constexpr uint32_t modeFlagAddr = 0x83496EF6u;
	constexpr uint32_t floatArgumentAddr = 0x820994C0u;
	constexpr uint32_t packetHeader = 0xC0006000u;
	if (!UseLiftedCode(10, 0x822872D0)) { ctx.r3.u64 = textureRendererAddr; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_822872D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822872D0);
	uint32_t stack = ctx.r1.u64;
	CTextureRenderer* textureRenderer = GameObject<CTextureRenderer>(base, textureRendererAddr);
	stack = PushStackFrame(base, stack, 160);

	// a copy of the resource reference at +0xC, made on the stack for the render-target call
	const uint32_t renderTarget = textureRenderer->m_10;
	const uint32_t renderTargetData = textureRenderer->m_14;
	STORE32(stack + 80, resourceRefVtable);
	STORE32(stack + 84, renderTarget);
	STORE32(stack + 88, renderTargetData);
	if (renderTarget != 0) {
		ctx.r1.u64 = stack;
		D3DResource_AddRef(ctx, base, renderTarget);
	}
	ctx.r1.u64 = stack;
	GfxDevice_SetRenderTargetResource(ctx, base, uint64_t(stack) + 80, forwardedArg1, forwardedArg2);
	GfxDevice_SetDepthStencilResource(ctx, base, textureRendererAddr + 24, ctx.r7.u64, ctx.r8.u64);

	if (int32_t(LOAD32(uint32_t(textureRenderer->m_description) + 20)) <= 1) {
		ctx.fpscr.disableFlushMode();
		ctx.f1.f64 = double(LOAD_F32(floatArgumentAddr));
		n_sub_821E27C8(ctx, base, uint32_t(textureRendererAddr + 8));
		const uint64_t result = CTextureRenderer_Apply(ctx, base, textureRendererAddr);
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		return result;
	}

	const uint32_t description = textureRenderer->m_description;
	ctx.fpscr.disableFlushMode();
	const double floatArgument = double(LOAD_F32(floatArgumentAddr));
	const uint32_t descriptionByte = LOAD8(description + 104);
	const uint32_t targetCount = LOAD32(description + 20);
	n_sub_821A17A8(ctx, base, targetCount, description + 24, descriptionByte, textureRendererAddr + 8, floatArgument);

	// The calls at the end are handed what the packet writing below, or the calls before it, leave in registers.
	uint64_t carriedValue1 = ctx.r6.u64;
	uint64_t lastArgument = ctx.r7.u64;
	const uint32_t modeFlag = LOAD8(modeFlagAddr);
	const uint32_t device = LOAD32(deviceGlobal);
	uint64_t carriedValue2 = modeFlag;
	uint64_t carriedValue3 = 0;
	uint32_t writePtr = 0;
	if (modeFlag != 0) {
		const uint32_t stateBlock = LOAD32(device + 13516);
		const uint32_t oldStateBlockFlags = LOAD32(stateBlock + 108);
		const uint64_t newStateBlockFlags = uint64_t(oldStateBlockFlags) | 64;
		STORE32(stateBlock + 108, uint32_t(newStateBlockFlags));
		const uint32_t bufferEnd = LOAD32(device + 56);
		writePtr = LOAD32(device + 48);
		const uint32_t oldStateByte = LOAD8(device + 10940);
		const uint32_t stateByte = oldStateByte & 0xFFFFFFFE;
		STORE32(device + 12716, 1);
		STORE8(device + 10940, uint8_t(stateByte));
		STORE32(device + 12708, 1);
		STORE32(device + 12712, 0);
		STORE32(device + 10932, 1);
		STORE32(device + 10936, 0);
		if (writePtr > bufferEnd) {
			ctx.r6.u64 = stateByte;
			ctx.r8.u64 = bufferEnd;
			ctx.r9.u64 = newStateBlockFlags;
			ctx.r10.u64 = oldStateBlockFlags;
			writePtr = KickOffCommandBuffer(ctx, base, device, oldStateByte);
		}
		carriedValue3 = 0xFFFFFFFFC0006000ull;
		carriedValue2 = 0xFFFFFFFFC0006100ull;
		STORE32(writePtr + 4, packetHeader);
		lastArgument = LOAD32(device + 12708);
		STORE32(writePtr + 8, uint32_t(lastArgument));
		STORE32(writePtr + 12, 0xC0006100u);
		carriedValue1 = LOAD32(device + 12712);
		STORE32(writePtr + 16, uint32_t(carriedValue1));
		writePtr += 16;
	} else {
		const uint32_t bufferEnd = LOAD32(device + 56);
		writePtr = LOAD32(device + 48);
		const uint32_t stateByte = LOAD8(device + 10940) & 0xFFFFFFFE;
		STORE32(device + 12716, 1);
		STORE32(device + 12708, 1);
		STORE8(device + 10940, uint8_t(stateByte));
		STORE32(device + 12712, 0);
		STORE32(device + 10932, 1);
		STORE32(device + 10936, 0);
		if (writePtr > bufferEnd) {
			ctx.r8.u64 = carriedValue2;
			ctx.r9.u64 = stateByte;
			ctx.r10.u64 = bufferEnd;
			writePtr = KickOffCommandBuffer(ctx, base, device, ctx.r7.u64);
			carriedValue1 = ctx.r6.u64;
			lastArgument = ctx.r7.u64;
			carriedValue2 = ctx.r8.u64;
		}
		STORE32(writePtr + 4, packetHeader);
		carriedValue3 = LOAD32(device + 12708);
		STORE32(writePtr + 8, uint32_t(carriedValue3));
		writePtr += 8;
	}

	const uint32_t modeFlagNow = LOAD8(modeFlagAddr);
	STORE32(device + 48, writePtr);
	const uint32_t deviceNow = LOAD32(deviceGlobal);
	ctx.r6.u64 = carriedValue1;
	ctx.r8.u64 = carriedValue2;
	if (modeFlagNow != 0) {
		ctx.r9.u64 = carriedValue3;
		n_sub_82B9B5D0(ctx, base, deviceNow, 0, 0, lastArgument);
	} else {
		n_sub_822655B0(ctx, base, deviceNow, 0, lastArgument);
	}
	const uint64_t result = CTextureRenderer_Apply(ctx, base, textureRendererAddr);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(10, sub_822872D0, 0x822872D0) { ctx.r3.u64 = CTextureRenderer_Render(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CTextureRenderer_ApplyWithFlags(CpuState& ctx, uint8_t* base, uint64_t textureRendererAddr) {
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	if (!UseLiftedCode(11, 0x822AA060)) { ctx.r3.u64 = textureRendererAddr; __imp__sub_822AA060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822AA060);
	GameStackFrame stackFrame(ctx, base, 96);

	// Set state flags on the renderer/device: upper two bits and bit 53.
	uint32_t devicePtr = LOAD32(uint32_t(g_83360000) + 412);
	uint64_t highFlags = LOAD64(devicePtr + 8);
	uint64_t newHighFlags = highFlags | 0xC000000000000000ull;
	STORE64(devicePtr + 8, newHighFlags);

	devicePtr = LOAD32(uint32_t(g_83360000) + 412);
	uint64_t flags = LOAD64(devicePtr);
	uint64_t newFlags = flags | 0x0020000000000000ull;
	STORE64(devicePtr, newFlags);
	ctx.r3.u64 = textureRendererAddr;
	ctx.r6.u64 = newFlags;
	ctx.r8.u64 = newHighFlags;
	ctx.r9.u64 = highFlags;
	CTextureRenderer_FlushRenderState(ctx, base, flags);

	return CTextureRenderer_Apply(ctx, base, textureRendererAddr);
}
PROMOTED_ENTRY(11, sub_822AA060, 0x822AA060) { ctx.r3.u64 = CTextureRenderer_ApplyWithFlags(ctx, base, ctx.r3.u64); }

void CTextureRenderer_SetRenderState(CpuState& ctx, uint8_t* base) {
	constexpr uint32_t deviceGlobal = 0x8336019Cu;
	if (!UseLiftedCode(11, 0x822AA0C8)) { __imp__sub_822AA0C8(ctx, base); return; }
	LiftedFrame frame(0x822AA0C8);
	// sets the device bits that CTextureRenderer_Apply clears
	uint32_t device = LOAD32(deviceGlobal);
	STORE64(device + 8, LOAD64(device + 8) | 0xC000000000000000ull);
	device = LOAD32(deviceGlobal);
	STORE64(device, LOAD64(device) | (1ull << 53));
}
PROMOTED_ENTRY(11, sub_822AA0C8, 0x822AA0C8) { CTextureRenderer_SetRenderState(ctx, base); }

uint32_t CTextureRenderer_FlushRenderState(CpuState& ctx, uint8_t* base, uint64_t renderStateFlags) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr uint32_t deviceGlobal = 0x8336019Cu;
	constexpr uint32_t flushFlagAddr = 0x83496EF4u;
	constexpr uint32_t pushCondition1Addr = 0x83496EEEu;
	constexpr uint32_t pushCondition2Addr = 0x834970CCu;
	if (!UseLiftedCode(11, 0x822AA5A0)) { ctx.r7.u64 = renderStateFlags; __imp__sub_822AA5A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822AA5A0);
	GameStackFrame stackFrame(ctx, base, 96);

	STORE8(flushFlagAddr, uint8_t(1));
	ctx.r7.u64 = renderStateFlags;
	ctx.r10.u64 = uint32_t(g_83490000);
	GameRenderStateFlush(ctx, base);

	const uint32_t device = LOAD32(deviceGlobal);
	ctx.r4.u64 = 0;
	uint64_t result = n_sub_821C64E8(ctx, base, device, ctx.r7.u64);

	const uint32_t pushCondition1 = LOAD8(pushCondition1Addr);
	uint64_t handedBack = pushCondition1;
	if (pushCondition1 != 0) {
		const uint32_t pushCondition2 = LOAD8(pushCondition2Addr);
		if (pushCondition2 != 0) {
			const uint32_t deviceNow = LOAD32(deviceGlobal);
			result = deviceNow;
			if ((LOAD32(deviceNow + 10916) & 0x3000) != 0) {
				ctx.r8.u64 = pushCondition1;
				ctx.r9.u64 = pushCondition2;
				result = CommandBuffer_PushStateCommand(ctx, base, deviceNow, 0, ctx.r7.u64);
				handedBack = ctx.r8.u64;
			}
		}
	}
	ctx.r8.u64 = handedBack;
	return result;
}
PROMOTED_ENTRY(11, sub_822AA5A0, 0x822AA5A0) { ctx.r3.u64 = CTextureRenderer_FlushRenderState(ctx, base, ctx.r7.u64); }

uint64_t CTextureRenderer_ResolveRenderTarget(CpuState& ctx, uint8_t* base, uint64_t textureRendererAddr, uint64_t renderTarget) {
	constexpr uint32_t deviceGlobal = 0x8336019Cu;
	constexpr uint32_t resolveFloatAddr = 0x820994B4u;
	if (!UseLiftedCode(12, 0x822C40C0)) { ctx.r3.u64 = textureRendererAddr; ctx.r4.u64 = renderTarget; __imp__sub_822C40C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822C40C0);
	uint32_t stack = ctx.r1.u64;
	CTextureRenderer* textureRenderer = GameObject<CTextureRenderer>(base, textureRendererAddr);
	uint64_t result = textureRendererAddr;
	uint64_t secondResult = renderTarget;
	stack = PushStackFrame(base, stack, 128);

	if (int32_t(LOAD32(uint32_t(textureRenderer->m_description) + 20)) > 1) {
		ctx.r1.u64 = stack;
		result = n_sub_821A2E00(ctx, base, renderTarget, 0);
		secondResult = ctx.r4.u64;
	} else if (LOAD32(uint32_t(renderTarget) + 4) != 0) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = textureRendererAddr;
		ctx.r4.u64 = renderTarget;
		n_sub_82232298(ctx, base);
		const uint32_t destination = LOAD32(uint32_t(renderTarget) + 4);
		STORE32(stack + 100, 0);
		STORE32(stack + 92, 0);
		ctx.fpscr.disableFlushMode();
		const double resolveFloat = double(LOAD_F32(resolveFloatAddr));
		const uint32_t device = LOAD32(deviceGlobal);
		ctx.r9.u64 = 0;
		result = D3DDevice_Resolve(ctx, base, device, 0, 0, destination, 0, 0, 0, resolveFloat);
		secondResult = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(12, sub_822C40C0, 0x822C40C0) { ctx.r3.u64 = CTextureRenderer_ResolveRenderTarget(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_822C9378  [4 bytes]
uint64_t CTextureRenderer_SetStateValue(CpuState& ctx, uint8_t* base, uint64_t stateValue) {
	if (!UseLiftedCode(12, 0x822C9378)) { ctx.r7.u64 = stateValue; __imp__sub_822C9378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822C9378);
	return RenderingDevice_SetStateValue(ctx, base, stateValue);
}
PROMOTED_ENTRY(12, sub_822C9378, 0x822C9378) { ctx.r3.u64 = CTextureRenderer_SetStateValue(ctx, base, ctx.r7.u64); }

void CTextureRenderer_SetColor(CpuState& ctx, uint8_t* base, uint32_t textureRendererAddr, uint32_t colorPointer) {
	if (!UseLiftedCode(85, 0x82B84990)) { ctx.r3.u64 = textureRendererAddr; ctx.r4.u64 = colorPointer; __imp__sub_82B84990(ctx, base); return; }
	LiftedFrame frame(0x82B84990);
	CTextureRenderer* textureRenderer = GameObject<CTextureRenderer>(base, textureRendererAddr);
	textureRenderer->m_colorR = LOAD8(colorPointer);
	textureRenderer->m_colorG = LOAD8(colorPointer + 1);
	textureRenderer->m_colorB = LOAD8(colorPointer + 2);
	textureRenderer->m_colorA = LOAD8(colorPointer + 3);
}
PROMOTED_ENTRY(85, sub_82B84990, 0x82B84990) { CTextureRenderer_SetColor(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CTextureRenderer_Construct(CpuState& ctx, uint8_t* base, uint64_t textureRendererAddr, uint32_t colorPointer, uint64_t descriptionIndex) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	constexpr uint32_t textureRendererVtable = 0x82002634u;
	constexpr uint32_t resourceRefVtable = 0x820F1D6Cu;
	constexpr uint32_t descriptionTable = 0x834BDCF8u;
	constexpr int32_t nameFormat = int32_t(0x820FA6F4);
	if (!UseLiftedCode(85, 0x82B849B8)) { ctx.r3.u64 = textureRendererAddr; ctx.r4.u64 = colorPointer; ctx.r5.u64 = descriptionIndex; __imp__sub_82B849B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B849B8);
	uint32_t stack = ctx.r1.u64;
	const uint32_t reservationMsr = uint32_t(ctx.r13.u64);
	CTextureRenderer* textureRenderer = GameObject<CTextureRenderer>(base, textureRendererAddr);
	stack = PushStackFrame(base, stack, 176);

	textureRenderer->vtable = textureRendererVtable;
	const uint8_t colorA = LOAD8(colorPointer + 3);
	const uint8_t colorR = LOAD8(colorPointer);
	const uint8_t colorG = LOAD8(colorPointer + 1);
	textureRenderer->m_colorB = LOAD8(colorPointer + 2);
	textureRenderer->m_colorG = colorG;
	textureRenderer->m_colorR = colorR;
	textureRenderer->m_colorA = colorA;
	textureRenderer->m_C = resourceRefVtable;
	textureRenderer->m_10 = 0;
	textureRenderer->m_14 = 0;
	textureRenderer->m_18 = resourceRefVtable;
	textureRenderer->m_1C = 0;
	textureRenderer->m_20 = 0;
	textureRenderer->m_2C = 0;
	textureRenderer->m_30 = 0;
	textureRenderer->m_34 = 0;
	textureRenderer->m_38 = 0;
	textureRenderer->m_3C = 0;
	textureRenderer->m_40 = 0;
	textureRenderer->m_description = descriptionTable + uint32_t(descriptionIndex * 108);

	// an empty string for the name, counted in the global string count (atomic increment)
	STORE32(stack + 128, 0);
	const uint32_t stringCountAddr = uint32_t(g_83496EB8);
	bool stored = false;
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		const uint32_t previousMsr = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = reservationMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(stringCountAddr);
		const uint32_t newCount = __builtin_bswap32(ctx.reserved.u32) + 1;
		stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(stringCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = previousMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!stored);

	const uint32_t description = textureRenderer->m_description;
	const uint32_t nameObject = LOAD32(description);
	uint64_t nameText = g_8209003F;
	if (nameObject != 0) {
		nameText = LOAD32(nameObject);
	}
	const uint32_t width = LOAD32(description + 4);
	const uint32_t height = LOAD32(description + 8);
	const uint32_t targetCount = LOAD32(description + 20);
	ctx.r1.u64 = stack;
	ctx.r11.u64 = description;
	// the last two arguments are the values the original leaves in those registers: the count's address and a page base
	CCharString_AssignFormatted(ctx, base, uint64_t(stack) + 128, nameFormat, width, height, nameText, targetCount, g_83496EB8, str_TXT_82100000_B_);
	CTextureRenderer_CreateTargets(ctx, base, uint32_t(textureRendererAddr));
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 128);

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return textureRendererAddr;
}
PROMOTED_ENTRY(85, sub_82B849B8, 0x82B849B8) { ctx.r3.u64 = CTextureRenderer_Construct(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint64_t CTextureRenderer_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t textureRendererAddr, uint64_t deleteFlags, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	if (!UseLiftedCode(85, 0x82B84AC8)) { ctx.r3.u64 = textureRendererAddr; ctx.r4.u64 = deleteFlags; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82B84AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B84AC8);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CTextureRenderer_Destructor(ctx, base, textureRendererAddr, forwardedArg1, forwardedArg2);
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, textureRendererAddr);
	}
	return textureRendererAddr;
}
PROMOTED_ENTRY(85, sub_82B84AC8, 0x82B84AC8) { ctx.r3.u64 = CTextureRenderer_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CTextureRenderer_Reconfigure(CpuState& ctx, uint8_t* base, uint64_t textureRendererAddr, uint64_t sizeAddr, uint32_t scaleMode) {
	if (!UseLiftedCode(85, 0x82B84F88)) { ctx.r3.u64 = textureRendererAddr; ctx.r4.u64 = sizeAddr; ctx.r5.u64 = scaleMode; __imp__sub_82B84F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B84F88);
	CTextureRenderer* textureRenderer = GameObject<CTextureRenderer>(base, textureRendererAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t result = CTextureRenderer_UpdateDescription(ctx, base, textureRenderer->m_description, sizeAddr, scaleMode);
	if (uint8_t(result) != 0) {
		result = CTextureRenderer_CreateTargets(ctx, base, textureRendererAddr);
	}
	return result;
}
PROMOTED_ENTRY(85, sub_82B84F88, 0x82B84F88) { ctx.r3.u64 = CTextureRenderer_Reconfigure(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }
