// CRenderEffectInstance (vtable 0x82002B44): methods of the class as readable C++.
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

uint64_t CRenderEffectInstance_UpdateResourceBinding(CpuState& ctx, uint8_t* base, uint64_t renderEffectInstanceAddr, uint64_t effectInstance, uint64_t forwardedArgument) {
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	constexpr uint32_t rendererAddress = 0x8336019C;
	constexpr uint32_t renderPathFlagAddress = 0x83496EF6;
	constexpr uint32_t C_820F1D70_vtable = 0x820F1D70;
	if (!UseLiftedCode(0, 0x8217B4C0)) { ctx.r3.u64 = renderEffectInstanceAddr; ctx.r7.u64 = effectInstance; ctx.r8.u64 = forwardedArgument; __imp__sub_8217B4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8217B4C0);
	CRenderEffectInstance* renderEffectInstance = GameObject<CRenderEffectInstance>(base, renderEffectInstanceAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	const uint32_t renderer = LOAD32(rendererAddress);
	uint64_t result;
	ctx.r8.u64 = forwardedArgument;
	if (LOAD8(renderPathFlagAddress) != 0) {
		result = n_sub_82B9B5D0(ctx, base, renderer, 0, 0, effectInstance);
	} else {
		result = n_sub_822655B0(ctx, base, renderer, 0, effectInstance);
	}

	const uint32_t pendingBindFlag = uint32_t(g_834C0000) - 5711;
	if (LOAD8(pendingBindFlag) != 0) {
		// A new 20-byte block (three zero words, then a C_820F1D70 member at +12) replaces the shared one at +208.
		const uint64_t newBlock = operator_new(ctx, base, 20);
		uint64_t sharedBlock = 0;
		if ((uint32_t)newBlock != 0) {
			STORE32((uint32_t)newBlock + 16, 0);
			sharedBlock = newBlock;
			STORE32((uint32_t)newBlock + 12, C_820F1D70_vtable);
			STORE32((uint32_t)newBlock, 0);
			STORE32((uint32_t)newBlock + 4, 0);
			STORE32((uint32_t)newBlock + 8, 0);
		}
		CRenderEffectInstance_SharedPtrReset(ctx, base, renderEffectInstanceAddr + 208, sharedBlock);

		const uint32_t sharedResourceHandle = renderEffectInstance->m_sharedResourceHandle;
		result = n_sub_82A465C8(ctx, base, sharedResourceHandle, renderEffectInstanceAddr + 144, ctx.r8.u64);
		STORE8(pendingBindFlag, 0);
	}
	return result;
}
PROMOTED_ENTRY(0, sub_8217B4C0, 0x8217B4C0) { ctx.r3.u64 = CRenderEffectInstance_UpdateResourceBinding(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CRenderEffectInstance_Submit(CpuState& ctx, uint8_t* base, uint64_t effectInstance) {
	constexpr uint32_t rendererAddress = 0x8336019C;
	constexpr uint32_t renderPathFlagAddress = 0x83496EF6;
	if (!UseLiftedCode(0, 0x8217DAB0)) { ctx.r7.u64 = effectInstance; __imp__sub_8217DAB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8217DAB0);
	const uint32_t renderer = LOAD32(rendererAddress);
	if (LOAD8(renderPathFlagAddress) != 0) {
		return n_sub_82B9B5D0(ctx, base, renderer, 0, 0, effectInstance);
	}
	return n_sub_822655B0(ctx, base, renderer, 0, effectInstance);
}
PROMOTED_ENTRY(0, sub_8217DAB0, 0x8217DAB0) { ctx.r3.u64 = CRenderEffectInstance_Submit(ctx, base, ctx.r7.u64); }

uint64_t CRenderEffectInstance_RenderWithPriority(CpuState& ctx, uint8_t* base, uint64_t renderEffectInstanceAddr, uint64_t renderSettings, uint64_t transformOwner, uint32_t transformSource, uint32_t particleEntityRef) {
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(1, 0x821A1F80)) { ctx.r3.u64 = renderEffectInstanceAddr; ctx.r4.u64 = renderSettings; ctx.r5.u64 = transformOwner; ctx.r6.u64 = transformSource; ctx.r7.u64 = particleEntityRef; __imp__sub_821A1F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821A1F80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	if (LOAD32(renderSettings + 76) == 1) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = renderEffectInstanceAddr;
		const uint64_t matrixResult = Matrix4x4_FromTransform(ctx, base, transformOwner, transformSource);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return matrixResult;
	}

	// Render's ninth argument (on the stack): the slot's entry of a table, or the default entry.
	const uint32_t slotIndex = LOAD32(LOAD32(transformSource + 52));
	uint32_t stackObject;
	if ((int32_t)slotIndex >= 0) {
		stackObject = LOAD32(LOAD32(LOAD32(LOAD32(transformSource + 60) + 28) + 88) + (slotIndex << 2));
	} else {
		stackObject = LOAD32(uint32_t(g_834A0000) + 21784);
	}
	const uint32_t transformData = LOAD32(transformSource + 4);
	const uint32_t slotTableOwner = LOAD32(transformSource + 28);
	const uint64_t sourceTransform = uint64_t(transformData) + 336;
	STORE32(stack + 84, stackObject);
	ctx.r1.u64 = stack;
	CRenderEffectInstance_Render(ctx, base, renderEffectInstanceAddr, renderSettings, transformOwner, transformSource, slotTableOwner, transformData, sourceTransform, particleEntityRef);

	// 1, unless a linked state is reached: then whether its top four bits equal the settings' word at +84.
	uint64_t result = 1;
	if (LOAD32(renderSettings + 76) != 1) {
		const uint32_t linked = LOAD32(renderSettings + 92);
		if (linked != 0) {
			const uint32_t linkedState = LOAD32(linked + 16);
			if (linkedState != 0) {
				result = (LOAD32(linkedState + 24) >> 28) == LOAD32(renderSettings + 84);
			}
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_821A1F80, 0x821A1F80) { ctx.r3.u64 = CRenderEffectInstance_RenderWithPriority(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u32, ctx.r7.u32); }

uint32_t CRenderEffectInstance_Render(CpuState& ctx, uint8_t* base, uint32_t renderEffectInstanceAddr, uint32_t renderSettings, uint64_t transformOwner, uint32_t transformSource, uint32_t slotTableOwner, uint32_t transformData, uint64_t sourceTransform, uint32_t particleEntityRef) {
	constexpr int32_t g_82099200 = int32_t(0x82099200);
	constexpr int32_t g_83316EAC = int32_t(0x83316EAC);
	constexpr int32_t g_83390000 = int32_t(0x83390000);
	constexpr int32_t g_83490BF0 = int32_t(0x83490BF0);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	constexpr int32_t g_834B8090 = int32_t(0x834B8090);
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	if (!UseLiftedCode(1, 0x821A5080)) { ctx.r3.u64 = renderEffectInstanceAddr; ctx.r4.u64 = renderSettings; ctx.r5.u64 = transformOwner; ctx.r6.u64 = transformSource; ctx.r7.u64 = slotTableOwner; ctx.r8.u64 = transformData; ctx.r9.u64 = sourceTransform; ctx.r10.u64 = particleEntityRef; __imp__sub_821A5080(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821A5080);
	const uint32_t permuteControlAddress = uint32_t(g_82099200);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	// Two vectors, each a permute of two of the instance's 16-byte blocks (+80 with +96, then +112 with +128),
	// go out with GPU_SubmitCommand (228, then 210).
	PPCVRegister block{};
	PPCVRegister nextBlock{};
	PPCVRegister permuteControl{};
	PPCVRegister payload{};
	uint32_t nextBlockAddress = renderEffectInstanceAddr + 96;
	SET_V8(nextBlock, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(nextBlockAddress & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(nextBlockAddress & 0xF) * 16])));
	SET_V8(block, VLOAD((renderEffectInstanceAddr + 80) & ~0xF));
	SET_V8(permuteControl, VLOAD(permuteControlAddress & ~0xF));
	SET_V8(payload, rex::ppc::simde_mm_perm_epi8_(V8(block), V8(nextBlock), V8(permuteControl)));
	ctx.r1.u64 = stack;
	ctx.r9.u64 = 80;   // the original leaves the block offset there
	ctx.v1 = payload;
	GPU_SubmitCommand(ctx, base, 228);

	SET_V8(permuteControl, VLOAD(permuteControlAddress & ~0xF));
	nextBlockAddress = renderEffectInstanceAddr + 128;
	SET_V8(nextBlock, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(nextBlockAddress & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(nextBlockAddress & 0xF) * 16])));
	SET_V8(block, VLOAD((renderEffectInstanceAddr + 112) & ~0xF));
	SET_V8(payload, rex::ppc::simde_mm_perm_epi8_(V8(block), V8(nextBlock), V8(permuteControl)));
	ctx.v1 = payload;
	GPU_SubmitCommand(ctx, base, 210);

	// The value the virtual call gets in r9: what GPU_SubmitCommand leaves there, or the slot's byte offset.
	uint64_t handedOnValue = ctx.r9.u64;
	const uint32_t rangeBegin = LOAD32(transformData + 200);
	const uint32_t slotIndex = LOAD32(LOAD32(transformSource + 52));
	uint32_t rangeEntry;
	if (((LOAD32(transformData + 204) - rangeBegin) & 0xFFFFFFF0u) != 0) {
		rangeEntry = (slotIndex << 4) + rangeBegin;
	} else {
		uint32_t tableEntry;
		if ((int32_t)slotIndex >= 0) {
			handedOnValue = slotIndex << 2;
			tableEntry = LOAD32(LOAD32(slotTableOwner + 88) + (slotIndex << 2));
		} else {
			tableEntry = LOAD32(uint32_t(g_834A0000) + 21784);
		}
		rangeEntry = tableEntry + 16;
	}

	// Method +44 of the object handed on the stack (the ninth argument, in the caller's frame).
	const uint32_t stackObject = LOAD32(stack + 244);
	const uint32_t entryValue = LOAD32(rangeEntry + 4);
	const uint32_t vtable = LOAD32(stackObject);
	const uint32_t method = LOAD32(vtable + 44);
	PPCRegister callTarget{};
	callTarget.u64 = method;
	ctx.r3.u64 = stackObject;
	ctx.r4.u64 = entryValue;
	ctx.r5.u64 = transformOwner;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = handedOnValue;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	if (LOAD32(renderSettings + 84) == 1) {
		// Records of the state block: value +4, mask +8, queued byte +20, log page number (from 1) +21. Before a
		// record's value changes, its old value goes into its log page (unless the record's mask already has bits
		// of the page's mask) and the record goes into the change queue once.
		const uint32_t stateBlock = uint32_t(g_834C0000) - 16224;
		const uint32_t recordA = stateBlock + 240;
		const uint32_t recordB = stateBlock + 264;
		const uint32_t recordC = stateBlock + 168;
		const uint32_t logPages = uint32_t(g_834B8090);
		const uint32_t queueCountAddress = uint32_t(g_83390000) + 1000;
		const uint32_t changeQueue = uint32_t(g_83490BF0);
		const uint32_t stampAddress = uint32_t(g_83316EAC) + 4;
		auto logOldValue = [&](uint32_t record) -> bool {
			const uint32_t page = LOAD8(record + 21) * 8200u + logPages - 8200u;
			const uint32_t pageMask = LOAD32(page + 8192);
			const uint32_t recordMask = LOAD32(record + 8);
			if ((pageMask & recordMask) != 0) {
				return false;
			}
			const uint32_t entryOffset = LOAD32(page + 8196) << 3;
			STORE32(record + 8, pageMask | recordMask);
			STORE32(page + entryOffset, record);
			STORE32(page + (LOAD32(page + 8196) << 3) + 4, LOAD32(record + 4));
			STORE32(page + 8196, LOAD32(page + 8196) + 1);
			return true;
		};
		auto queueRecord = [&](uint32_t record, uint32_t slot) {
			STORE8(record + 20, 1);
			STORE32(queueCountAddress, slot + 1);
			STORE32(changeQueue + (slot << 2), record);
		};

		// Records A and B take the current stamp, record C the value 1.
		uint32_t stamp = LOAD32(stampAddress);
		uint32_t queueCount;
		if (LOAD32(recordA + 4) != stamp) {
			const uint32_t newStamp = stamp;
			if (logOldValue(recordA)) {
				stamp = LOAD32(stampAddress);
			}
			const bool queuedA = LOAD8(recordA + 20) != 0;
			STORE32(recordA + 4, newStamp);
			queueCount = LOAD32(queueCountAddress);
			if (!queuedA) {
				queueRecord(recordA, queueCount);
				queueCount = queueCount + 1;
			}
		} else {
			queueCount = LOAD32(queueCountAddress);
		}

		if (LOAD32(recordB + 4) != stamp) {
			logOldValue(recordB);
			const bool queuedB = LOAD8(recordB + 20) != 0;
			STORE32(recordB + 4, stamp);
			if (!queuedB) {
				queueRecord(recordB, queueCount);
				queueCount = queueCount + 1;
			}
		}

		if (LOAD32(recordC + 4) != 1) {
			logOldValue(recordC);
			const bool queuedC = LOAD8(recordC + 20) != 0;
			STORE32(recordC + 4, 1);
			if (!queuedC) {
				queueRecord(recordC, queueCount);
			}
		}
	}

	ctx.r3.u64 = renderEffectInstanceAddr;
	CRenderEffectInstance_UpdateParticle(ctx, base, renderSettings, particleEntityRef);
	ctx.r3.u64 = renderEffectInstanceAddr;
	const uint32_t result = CRenderEffectInstance_ApplyTransform(ctx, base, uint32_t(transformOwner), sourceTransform);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_821A5080, 0x821A5080) { ctx.r3.u64 = CRenderEffectInstance_Render(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u64, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32, ctx.r9.u64, ctx.r10.u32); }

uint32_t CRenderEffectInstance_ApplyTransform(CpuState& ctx, uint8_t* base, uint32_t transformOwner, uint64_t sourceTransform) {
	constexpr int32_t g_820994B4 = int32_t(0x820994B4);
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	constexpr int32_t g_834C3564 = int32_t(0x834C3564);
	constexpr uint32_t fourthRowMaskAddress = 0x820991C0;
	constexpr uint32_t describedObjectAddress = 0x834A5D7C;
	constexpr uint32_t blockMaskAddress = 0x83491598;
	if (!UseLiftedCode(2, 0x821B4898)) { ctx.r4.u64 = transformOwner; ctx.r5.u64 = sourceTransform; __imp__sub_821B4898(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821B4898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 384);
	const uint32_t constants = uint32_t(g_820994B4);
	const uint32_t rendererAddress = uint32_t(g_83360000) + 412;
	const uint32_t source = uint32_t(sourceTransform);
	const uint32_t rows = stack + 96;
	const uint32_t finalMatrix = stack + 160;
	const uint32_t product = stack + 224;

	// The source's three rows and, as the fourth, the float constant at +12 splatted and masked (at stack + 96),
	// times the owner's matrix at +1712.
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(double(LOAD_F32(constants + 12))));
	const uint32_t constantAddress = stack + 80;
	PPCVRegister constantVector{};
	PPCVRegister fourthRow{};
	PPCVRegister row0{};
	PPCVRegister row1{};
	PPCVRegister row2{};
	SET_V8(constantVector, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(constantAddress & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(constantAddress & 0xF) * 16])));
	SET_V8(fourthRow, simde_mm_and_si128(simde_mm_shuffle_epi32(V8(constantVector), 0xFF), VLOAD(fourthRowMaskAddress & ~0xF)));
	SET_V8(row2, VLOAD((source + 32) & ~0xF));
	SET_V8(row0, VLOAD(source & ~0xF));
	SET_V8(row1, VLOAD((source + 16) & ~0xF));
	VSTORE(rows & ~0xF, V8(row0));
	VSTORE((rows + 16) & ~0xF, V8(row1));
	VSTORE((rows + 32) & ~0xF, V8(row2));
	VSTORE((rows + 48) & ~0xF, V8(fourthRow));
	ctx.r1.u64 = stack;
	Matrix4x4_Multiply(ctx, base, product, transformOwner + 1712, rows);
	for (uint32_t offset = 0; offset < 64; offset += 8) {
		STORE64(finalMatrix + offset, LOAD64(product + offset));
	}

	// Returned: the last of the product's address, the transposed matrix's address and the renderer.
	uint32_t result = product;
	if (LOAD8(transformOwner + 1795) != 0) {
		// A float pair made once from the constant at +0.
		const uint32_t pairGuardAddress = uint32_t(g_834C0000) + 13676;
		const uint32_t floatPair = uint32_t(g_834C3564);
		const uint32_t pairGuard = LOAD32(pairGuardAddress);
		if ((pairGuard & 1) == 0) {
			ctx.fpscr.disableFlushMode();
			const float pairValue = float(double(LOAD_F32(constants)));
			STORE_F32(floatPair, pairValue);
			STORE_F32(floatPair + 4, pairValue);
			STORE32(pairGuardAddress, pairGuard | 1);
		}

		// n_sub_821F9F40 writes a description of the object at 0x834A5D7C over the rows; its words at +24 and +28
		// go to stack + 80 for Matrix4x4_MultiplyMatrices with the pair, and the transposed result is the matrix.
		n_sub_821F9F40(ctx, base, LOAD32(describedObjectAddress), rows);
		const uint32_t descriptionWord28 = LOAD32(rows + 28);
		const uint64_t pairBits = LOAD64(floatPair);
		STORE32(stack + 80, LOAD32(rows + 24));
		STORE32(stack + 84, descriptionWord28);
		const uint64_t combined = Matrix4x4_MultiplyMatrices(ctx, base, product, stack + 80, pairBits);
		result = uint32_t(Matrix4x4_Transpose_82270C80(ctx, base, stack + 288, combined));
		for (uint32_t offset = 0; offset < 64; offset += 8) {
			STORE64(finalMatrix + offset, LOAD64(result + offset));
		}
	}

	const uint64_t blockMask = LOAD64(blockMaskAddress);
	const uint64_t firstBlockBit = uint64_t(1) << 63;
	const uint64_t secondBlockBit = uint64_t(1) << 62;
	if ((blockMask & firstBlockBit) != 0) {
		const uint32_t renderer = LOAD32(rendererAddress);
		result = renderer;
		n_sub_8221A9B0(ctx, base, renderer, 0, finalMatrix, 4, firstBlockBit);
	}
	if ((blockMask & secondBlockBit) != 0) {
		const uint32_t renderer = LOAD32(rendererAddress);
		result = renderer;
		n_sub_8221A9B0(ctx, base, renderer, 4, sourceTransform, 3, secondBlockBit);
	}
	stack = PopStackFrame(stack, 384);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(2, sub_821B4898, 0x821B4898) { ctx.r3.u64 = CRenderEffectInstance_ApplyTransform(ctx, base, ctx.r4.u32, ctx.r5.u64); }

uint32_t CRenderEffectInstance_UpdateParticle(CpuState& ctx, uint8_t* base, uint32_t renderSettings, uint32_t particleEntityRef) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr uint32_t variantPermuteAddress = 0x820991F0;
	if (!UseLiftedCode(2, 0x821B4A50)) { ctx.r4.u64 = renderSettings; ctx.r5.u64 = particleEntityRef; __imp__sub_821B4A50(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821B4A50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	const uint32_t constants = uint32_t(g_820A0000) - 19232;   // 0x8209B4E0

	// A vector of the bytes from an address to the end of its 16-byte block, zero-filled.
	auto loadToBlockEnd = [&](uint32_t address) -> simde__m128i {
		return simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(address & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(address & 0xF) * 16]));
	};

	// Weather_UpdateParticle's vector (x, y, z, w) is the float constants at +0, +368, -8224 and -8236, put together
	// in the frame; with a nonzero variant (the settings' word at +84) it goes through the permute at 0x820991F0
	// with the -8236 constant.
	ctx.fpscr.disableFlushMode();
	const float xValue = LOAD_F32(constants);
	STORE_F32(stack + 80, xValue);
	const float zValue = LOAD_F32(constants - 8224);
	const float wValue = LOAD_F32(constants - 8236);
	STORE_F32(stack + 88, wValue);
	STORE_F32(stack + 84, zValue);
	PPCVRegister wSource{};
	PPCVRegister ySource{};
	PPCVRegister parameters{};
	PPCVRegister zwSource{};
	SET_V8(wSource, loadToBlockEnd(stack + 88));
	const float yValue = LOAD_F32(constants + 368);
	const uint32_t variant = LOAD32(renderSettings + 84);
	STORE_F32(stack + 88, yValue);
	SET_V8(ySource, loadToBlockEnd(stack + 88));
	SET_V8(parameters, loadToBlockEnd(stack + 80));
	SET_V8(zwSource, loadToBlockEnd(stack + 84));
	SET_VF(zwSource, simde_mm_blend_ps(VF(zwSource), simde_mm_permute_ps(VF(wSource), 57), 4));
	SET_VF(parameters, simde_mm_blend_ps(VF(parameters), simde_mm_permute_ps(VF(ySource), 57), 4));
	SET_VF(parameters, simde_mm_blend_ps(VF(parameters), simde_mm_permute_ps(VF(zwSource), 78), 3));
	if (variant != 0) {
		STORE_F32(stack + 88, wValue);
		SET_V8(zwSource, loadToBlockEnd(stack + 88));
		PPCVRegister variantControl{};
		SET_V8(variantControl, VLOAD(variantPermuteAddress & ~0xF));
		SET_V8(parameters, rex::ppc::simde_mm_perm_epi8_(V8(parameters), V8(zwSource), V8(variantControl)));
	}
	ctx.r1.u64 = stack;
	ctx.v1 = parameters;
	uint32_t result = Weather_UpdateParticle(ctx, base, 11);

	if (particleEntityRef != 0) {
		const uint32_t entryTable = LOAD32(particleEntityRef + 16);
		if (entryTable != 0) {
			const uint32_t variantIndex = LOAD32(renderSettings + 84) + 3;
			const uint32_t entity = LOAD32(particleEntityRef);
			const uint32_t entry = LOAD32((variantIndex << 2) + entryTable);
			ctx.v12 = ySource;
			ctx.v13 = zwSource;
			result = Weather_UpdateParticleEntity(ctx, base, entity, entry);
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(2, sub_821B4A50, 0x821B4A50) { ctx.r3.u64 = CRenderEffectInstance_UpdateParticle(ctx, base, ctx.r4.u32, ctx.r5.u32); }

uint64_t CRenderEffectInstance_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t renderEffectInstanceAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(82, 0x82B235C0)) { ctx.r3.u64 = renderEffectInstanceAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82B235C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B235C0);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CRenderEffectInstance_Destructor(ctx, base, renderEffectInstanceAddr);
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, renderEffectInstanceAddr);
	}
	return renderEffectInstanceAddr;
}
PROMOTED_ENTRY(82, sub_82B235C0, 0x82B235C0) { ctx.r3.u64 = CRenderEffectInstance_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CRenderEffectInstance_Destructor(CpuState& ctx, uint8_t* base, uint64_t renderEffectInstanceAddr) {
	constexpr uint32_t renderEffectInstanceVtable = 0x82002B44;
	constexpr uint32_t baseClassVtable = 0x820F825C;   // C_820F825C
	if (!UseLiftedCode(82, 0x82B23610)) { ctx.r3.u64 = renderEffectInstanceAddr; __imp__sub_82B23610(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B23610);
	CRenderEffectInstance* renderEffectInstance = GameObject<CRenderEffectInstance>(base, renderEffectInstanceAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	renderEffectInstance->vtable = renderEffectInstanceVtable;
	SharedHandle_Release(ctx, base, renderEffectInstanceAddr + 208);
	renderEffectInstance->vtable = baseClassVtable;
	DynamicArray_Destroy(ctx, base, uint32_t(renderEffectInstanceAddr + 16));
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, renderEffectInstanceAddr + 4);
}
PROMOTED_ENTRY(82, sub_82B23610, 0x82B23610) { ctx.r3.u64 = CRenderEffectInstance_Destructor(ctx, base, ctx.r3.u64); }

uint64_t CRenderEffectInstance_Clone(CpuState& ctx, uint8_t* base, uint64_t renderEffectInstanceAddr) {
	constexpr uint32_t renderEffectInstanceVtable = 0x82002B44;
	if (!UseLiftedCode(82, 0x82B23668)) { ctx.r3.u64 = renderEffectInstanceAddr; __imp__sub_82B23668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B23668);
	const uint32_t savedMsr = ctx.r13.u64;
	CRenderEffectInstance* renderEffectInstance = GameObject<CRenderEffectInstance>(base, renderEffectInstanceAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	const uint64_t clonedInstance = operator_new(ctx, base, 224);
	if ((uint32_t)clonedInstance == 0) {
		return 0;
	}
	CRenderEffectInstance* clone = GameObject<CRenderEffectInstance>(base, clonedInstance);
	C_820F825C_CopyConstructor(ctx, base, clonedInstance, renderEffectInstanceAddr);
	clone->vtable = renderEffectInstanceVtable;
	memcpy(ctx, base, clonedInstance + 64, renderEffectInstanceAddr + 64, 80);
	memcpy(ctx, base, clonedInstance + 144, renderEffectInstanceAddr + 144, 64);
	clone->m_sharedResourceHandle = uint32_t(renderEffectInstance->m_sharedResourceHandle);
	const uint32_t refCountAddress = renderEffectInstance->m_sharedResourceRefCount;
	clone->m_sharedResourceRefCount = refCountAddress;
	if (refCountAddress != 0) {
		// Atomic increment of the shared reference count (the original's reserved load and conditional store).
		PPCCRRegister casResult{};
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t lockMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddress);
			uint32_t incremented = __builtin_bswap32(ctx.reserved.u32) + 1;
			casResult.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddress)), ctx.reserved.s32, __builtin_bswap32(incremented));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!casResult.eq);
	}
	clone->m_D8 = uint32_t(renderEffectInstance->m_D8);
	return clonedInstance;
}
PROMOTED_ENTRY(82, sub_82B23668, 0x82B23668) { ctx.r3.u64 = CRenderEffectInstance_Clone(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82B23BA0(CpuState& ctx, uint8_t* base, uint64_t renderEffectInstanceAddr) {
	if (!UseLiftedCode(82, 0x82B23BA0)) { ctx.r3.u64 = renderEffectInstanceAddr; __imp__sub_82B23BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B23BA0);
	CRenderEffectInstance* renderEffectInstance = GameObject<CRenderEffectInstance>(base, renderEffectInstanceAddr);
	uint32_t virtualFunction = LOAD32(uint32_t(renderEffectInstance->vtable) + 16);
	PPCRegister callTarget{};
	callTarget.u64 = virtualFunction;
	ctx.r3.u64 = renderEffectInstanceAddr;
	ctx.r10.u64 = virtualFunction;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(82, sub_82B23BA0, 0x82B23BA0) { ctx.r3.u64 = n_sub_82B23BA0(ctx, base, ctx.r3.u64); }

uint64_t CRenderEffectInstance_ResetTree(CpuState& ctx, uint8_t* base, uint32_t renderEffectInstanceAddr) {
	if (!UseLiftedCode(82, 0x82B23BB0)) { ctx.r3.u64 = renderEffectInstanceAddr; __imp__sub_82B23BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B23BB0);
	uint32_t stack = ctx.r1.u64;
	CRenderEffectInstance* renderEffectInstance = GameObject<CRenderEffectInstance>(base, renderEffectInstanceAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	RbTree_CreateHeadNode(ctx, base, stack + 80);
	uint32_t treeRoot = RbTree_Clone(ctx, base, stack + 80);
	renderEffectInstance->m_D8 = treeRoot;
	uint64_t result = RbTree_Destroy(ctx, base, stack + 80);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(82, sub_82B23BB0, 0x82B23BB0) { ctx.r3.u64 = CRenderEffectInstance_ResetTree(ctx, base, ctx.r3.u32); }

uint64_t Matrix4x4_FromTransform(CpuState& ctx, uint8_t* base, uint32_t transformOwner, uint32_t transformSource) {
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	constexpr int32_t g_83390000 = int32_t(0x83390000);
	constexpr int32_t g_834B8090 = int32_t(0x834B8090);
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	constexpr uint32_t fourthRowConstantAddress = 0x820994C0;
	constexpr uint32_t fourthRowMaskAddress = 0x820991C0;
	constexpr uint32_t blockMaskAddress = 0x83491598;
	constexpr uint32_t changeQueue = 0x83490BF0;
	if (!UseLiftedCode(82, 0x82B23BF8)) { ctx.r4.u64 = transformOwner; ctx.r5.u64 = transformSource; __imp__sub_82B23BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B23BF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 256);
	const uint64_t sourceTransform = uint64_t(LOAD32(transformSource + 4)) + 336;
	const uint32_t source = uint32_t(sourceTransform);
	const uint32_t rows = stack + 96;
	const uint32_t product = stack + 160;

	// The source's three rows and, as the fourth, the float constant splatted and masked (at stack + 96), times
	// the owner's matrix at +1712; the product goes back over the rows.
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(double(LOAD_F32(fourthRowConstantAddress))));
	const uint32_t constantAddress = stack + 80;
	PPCVRegister constantVector{};
	PPCVRegister fourthRow{};
	PPCVRegister row0{};
	PPCVRegister row1{};
	PPCVRegister row2{};
	SET_V8(constantVector, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(constantAddress & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(constantAddress & 0xF) * 16])));
	SET_V8(fourthRow, simde_mm_and_si128(simde_mm_shuffle_epi32(V8(constantVector), 0xFF), VLOAD(fourthRowMaskAddress & ~0xF)));
	SET_V8(row2, VLOAD((source + 32) & ~0xF));
	SET_V8(row0, VLOAD(source & ~0xF));
	SET_V8(row1, VLOAD((source + 16) & ~0xF));
	VSTORE(rows & ~0xF, V8(row0));
	VSTORE((rows + 16) & ~0xF, V8(row1));
	VSTORE((rows + 32) & ~0xF, V8(row2));
	VSTORE((rows + 48) & ~0xF, V8(fourthRow));
	ctx.r1.u64 = stack;
	Matrix4x4_Multiply(ctx, base, product, transformOwner + 1712, rows);
	for (uint32_t offset = 0; offset < 64; offset += 8) {
		STORE64(rows + offset, LOAD64(product + offset));
	}

	const uint32_t rendererAddress = uint32_t(g_83360000) + 412;
	const uint64_t blockMask = LOAD64(blockMaskAddress);
	const uint64_t firstBlockBit = uint64_t(1) << 63;
	const uint64_t secondBlockBit = uint64_t(1) << 62;
	// n_sub_822209A0 takes what the original leaves in r3: the product's address, or the renderer last loaded.
	uint32_t productOrRenderer = product;
	if ((blockMask & firstBlockBit) != 0) {
		productOrRenderer = LOAD32(rendererAddress);
		n_sub_8221A9B0(ctx, base, productOrRenderer, 0, rows, 4, firstBlockBit);
	}
	if ((blockMask & secondBlockBit) != 0) {
		productOrRenderer = LOAD32(rendererAddress);
		n_sub_8221A9B0(ctx, base, productOrRenderer, 4, sourceTransform, 3, secondBlockBit);
	}
	ctx.r3.u64 = productOrRenderer;
	n_sub_822209A0(ctx, base);

	// The state block's record at +192 (value +4, mask +8, queued byte +20, log page number (from 1) +21) goes to 0:
	// its old value into its log page unless the record's mask already has bits of the page's mask, and the record
	// into the change queue once.
	const uint32_t record = uint32_t(g_834C0000) - 16224 + 192;
	if (LOAD32(record + 4) != 0) {
		const uint32_t page = LOAD8(record + 21) * 8200u + uint32_t(g_834B8090) - 8200u;
		const uint32_t pageMask = LOAD32(page + 8192);
		const uint32_t recordMask = LOAD32(record + 8);
		if ((pageMask & recordMask) == 0) {
			const uint32_t entryOffset = LOAD32(page + 8196) << 3;
			STORE32(record + 8, pageMask | recordMask);
			STORE32(page + entryOffset, record);
			STORE32(page + (LOAD32(page + 8196) << 3) + 4, LOAD32(record + 4));
			STORE32(page + 8196, LOAD32(page + 8196) + 1);
		}
		const uint8_t queued = LOAD8(record + 20);
		STORE32(record + 4, 0);
		if (queued == 0) {
			const uint32_t queueCountAddress = uint32_t(g_83390000) + 1000;
			STORE8(record + 20, 1);
			const uint32_t slot = LOAD32(queueCountAddress);
			STORE32(queueCountAddress, slot + 1);
			STORE32(changeQueue + (slot << 2), record);
		}
	}
	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(82, sub_82B23BF8, 0x82B23BF8) { ctx.r3.u64 = Matrix4x4_FromTransform(ctx, base, ctx.r4.u32, ctx.r5.u32); }
