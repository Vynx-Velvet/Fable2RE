// CModelRenderer (vtable 0x82001E5C): methods of the class as readable C++.
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

uint32_t CModelRenderer_InitializeEffect(CpuState& ctx, uint8_t* base, uint32_t modelRendererAddr, uint64_t renderContext, uint32_t effect) {
	constexpr uint32_t defaultEffectDefinitionSlot = 0x834A5518;
	if (!UseLiftedCode(5, 0x822093E8)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = renderContext; ctx.r5.u64 = effect; __imp__sub_822093E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822093E8);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	GameStackFrame stackFrame(ctx, base, 144);

	// The effect definition: entry (+60 of m_34) of the table at +88 of m_1C, or the default definition.
	int32_t definitionIndex = int32_t(LOAD32(uint32_t(modelRenderer->m_34) + 60));
	uint32_t effectDefinition;
	if (definitionIndex >= 0) {
		effectDefinition = LOAD32(LOAD32(uint32_t(modelRenderer->m_1C) + 88) + (uint32_t(definitionIndex) << 2));
	} else {
		effectDefinition = LOAD32(defaultEffectDefinitionSlot);
	}
	STORE32(effect + 28, LOAD32(LOAD32(effectDefinition + 176) + 8));

	uint32_t resourceMode = modelRenderer->m_24;
	uint32_t result;
	if (LOAD8(uint32_t(renderContext) + 1796) != 0) {
		result = CModelRenderer_GetRenderResource(ctx, base, modelRendererAddr);
		STORE32(effect + 4, result);
		STORE32(effect + 48, resourceMode);

		// Bits 1, 2 and 4 of the first word of the definition's first 180-byte element, when it has one.
		uint32_t elementsBegin = LOAD32(effectDefinition + 20);
		bool hasElement = int32_t(LOAD32(effectDefinition + 24) - elementsBegin) / 180 != 0;
		uint32_t firstElementFlags = hasElement ? LOAD32(elementsBegin) : 0;
		STORE8(effect + 32, (firstElementFlags >> 1) & 1);
		STORE8(effect + 33, (firstElementFlags >> 2) & 1);
		STORE8(effect + 80, 0);
		STORE32(effect + 76, 0);
		STORE8(effect + 35, (firstElementFlags >> 4) & 1);
		STORE8(effect + 82, 1);
	} else {
		uint32_t resourceDescriptor = CModelRenderer_GetRenderResource(ctx, base, modelRendererAddr);
		Effect_InitializeFromDefinition(ctx, base, effect, effectDefinition, resourceDescriptor, resourceMode, 0);
		result = n_sub_82222BD0(ctx, base, effect, renderContext, modelRenderer->m_4);
	}

	if (modelRenderer->m_3E != 0) {
		STORE8(effect + 81, 1);
	}
	return result;
}
PROMOTED_ENTRY(5, sub_822093E8, 0x822093E8) { ctx.r3.u64 = CModelRenderer_InitializeEffect(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint32_t CModelRenderer_UpdateDistance(CpuState& ctx, uint8_t* base, uint32_t modelRendererAddr, uint32_t renderContext) {
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr uint32_t deviceSlot = uint32_t(g_83360000) + 412;
	constexpr uint32_t pixelConstantBlockMaskAddress = uint32_t(g_83490000) + 5520;
	constexpr uint32_t fillValueAddress = 0x820994B4;
	if (!UseLiftedCode(5, 0x8220B4B8)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = renderContext; __imp__sub_8220B4B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8220B4B8);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);

	// The distance between the vector at +320 of m_4 (zero when the render context's byte +1796 is set) and the
	// vector at +80 of the context's object at +4.
	PPCVRegister modelPosition{};
	SET_V8(modelPosition, VLOAD((uint32_t(modelRenderer->m_4) + 320u) & ~0xF));
	if (LOAD8(renderContext + 1796) != 0) {
		SET_V8(modelPosition, simde_mm_setzero_si128());
	}
	PPCVRegister referencePosition{};
	SET_V8(referencePosition, VLOAD((LOAD32(renderContext + 4) + 80u) & ~0xF));
	PPCVRegister offset{};
	ctx.fpscr.enableFlushMode();
	SET_VF(offset, simde_mm_sub_ps(VF(referencePosition), VF(modelPosition)));
	ctx.fpscr.disableFlushModeUnconditional();
	double fillValue = double(LOAD_F32(fillValueAddress));
	PPCVRegister lengthSquared{};
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(lengthSquared, simde_mm_dp_ps(VF(offset), VF(offset), 0xEF));
	uint64_t pixelConstantBlocks = LOAD64(pixelConstantBlockMaskAddress);
	ctx.fpscr.disableFlushModeUnconditional();
	float distance = float(sqrt(double(simde_mm_cvtss_f32(VF(lengthSquared)))));

	// Pixel-shader constant c16 = (distance, fill, fill, fill) when its block (bit 59: c16..c19) is in the mask.
	const uint64_t constantBlock4 = uint64_t(1) << 59;
	if ((pixelConstantBlocks & constantBlock4) != 0) {
		uint32_t device = LOAD32(deviceSlot);
		STORE_F32(device + 6272, distance);
		STORE_F32(device + 6276, float(fillValue));
		STORE_F32(device + 6280, float(fillValue));
		STORE_F32(device + 6284, float(fillValue));
		STORE64(device + 8, LOAD64(device + 8) | constantBlock4);
	}
	// (the original returns the page base it addressed the mask with)
	return uint32_t(g_83490000);
}
PROMOTED_ENTRY(5, sub_8220B4B8, 0x8220B4B8) { ctx.r3.u64 = CModelRenderer_UpdateDistance(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CModelRenderer_RenderWithEffect(CpuState& ctx, uint8_t* base, uint64_t modelRendererAddr, uint32_t effectDefinition, uint64_t renderContext) {
	// The two render pools (RenderPool_Pop, RenderPool_CleanupAll): 1024 entries of 8 bytes, a bit word (+8192)
	// and the entry count (+8196) each.
	constexpr int32_t firstRenderPool = int32_t(0x834B8090);
	constexpr int32_t secondRenderPool = firstRenderPool + 8200;
	constexpr uint32_t pushedEntryValue = 0x834BDB70;
	constexpr uint32_t effectDescriptors = 0x834A0ECC;
	if (!UseLiftedCode(5, 0x82214850)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = effectDefinition; ctx.r5.u64 = renderContext; __imp__sub_82214850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82214850);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 256);

	// Push an entry and a 0 bit on both pools; the record at stack + 80 tracks them.
	uint32_t firstCount = LOAD32(uint32_t(firstRenderPool) + 8196);
	STORE8(stack + 80, 1);
	STORE32(uint32_t(firstRenderPool) + (firstCount << 3), pushedEntryValue);
	uint32_t secondCount = LOAD32(uint32_t(secondRenderPool) + 8196);
	STORE32(uint32_t(firstRenderPool) + 8196, LOAD32(uint32_t(firstRenderPool) + 8196) + 1);
	STORE32(uint32_t(firstRenderPool) + 8192, LOAD32(uint32_t(firstRenderPool) + 8192) << 1);
	STORE32(uint32_t(secondRenderPool) + (secondCount << 3), pushedEntryValue);
	STORE32(uint32_t(secondRenderPool) + 8192, LOAD32(uint32_t(secondRenderPool) + 8192) << 1);
	STORE32(uint32_t(secondRenderPool) + 8196, LOAD32(uint32_t(secondRenderPool) + 8196) + 1);

	// The second descriptor when the definition's first 180-byte element has bit 5 set.
	uint32_t elementsBegin = LOAD32(effectDefinition + 20);
	bool firstElementBit5 = int32_t(LOAD32(effectDefinition + 24) - elementsBegin) / 180 != 0 && ((LOAD32(elementsBegin) >> 5) & 1) != 0;
	uint32_t effect = stack + 96;
	ctx.r1.u64 = stack;
	C_Unknown_InitializeFromDescriptor(ctx, base, effect, effectDefinition, effectDescriptors + (firstElementBit5 ? 20 : 0));

	CModelRenderer_InitializeEffect(ctx, base, uint32_t(modelRendererAddr), renderContext, effect);
	CModelRenderer_UpdateTransform(ctx, base, uint32_t(modelRendererAddr), uint32_t(renderContext));
	CModelRenderer_UpdateDistance(ctx, base, uint32_t(modelRendererAddr), uint32_t(renderContext));

	uint32_t vtable = modelRenderer->vtable;
	uint32_t method = LOAD32(vtable + 20);
	ctx.r3.u64 = modelRendererAddr;
	ctx.r5.u64 = method;
	ctx.r6.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(method);

	uint32_t renderResult = CModelRenderer_RenderEffect(ctx, base, modelRendererAddr, effect, modelRenderer->m_30, renderContext);
	ctx.r3.u64 = renderResult;
	n_sub_821F6DA0(ctx, base);

	if (LOAD8(stack + 201) != 0) {
		STORE8(stack + 201, 0);
		RenderPool_Pop(ctx, base, secondRenderPool);
	}
	if (LOAD8(stack + 200) != 0) {
		STORE8(stack + 200, 0);
		RenderPool_Pop(ctx, base, firstRenderPool);
	}
	uint64_t result = RenderPool_CleanupAll(ctx, base, stack + 80);

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(5, sub_82214850, 0x82214850) { ctx.r3.u64 = CModelRenderer_RenderWithEffect(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint32_t CModelRenderer_UpdateTransform(CpuState& ctx, uint8_t* base, uint32_t modelRendererAddr, uint32_t renderContext) {
	// Lane masks: each keeps one lane of a vector (the masks of rows 0, 1, 2 and 3 of the matrix built below).
	constexpr uint32_t xLaneMask = 0x82099190;
	constexpr uint32_t yLaneMask = 0x820991A0;
	constexpr uint32_t zLaneMask = 0x820991B0;
	constexpr uint32_t wLaneMask = 0x820991C0;
	constexpr uint32_t diagonalValueAddress = 0x820994C0;
	if (!UseLiftedCode(6, 0x82218F88)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = renderContext; __imp__sub_82218F88(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82218F88);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 288);

	// The three rows (48 bytes at +336 of m_4), or diagonal rows when the render context's byte +1796 is set.
	uint32_t rows = stack + 96;
	uint32_t rowSource = uint32_t(modelRenderer->m_4) + 336;
	for (uint32_t offset = 0; offset < 48; offset += 8) {
		STORE64(rows + offset, LOAD64(rowSource + offset));
	}
	ctx.fpscr.disableFlushMode();
	double diagonalValue = double(LOAD_F32(diagonalValueAddress));
	if (LOAD8(renderContext + 1796) != 0) {
		STORE_F32(stack + 80, float(diagonalValue));
		STORE_F32(stack + 84, float(diagonalValue));
		STORE_F32(stack + 88, float(diagonalValue));
		uint32_t row2Address = stack + 80;
		uint32_t row0Address = stack + 84;
		uint32_t row1Address = stack + 88;
		PPCVRegister row0Value{};
		PPCVRegister row1Value{};
		PPCVRegister row2Value{};
		SET_V8(row2Value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(row2Address & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(row2Address & 0xF) * 16])));
		SET_V8(row0Value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(row0Address & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(row0Address & 0xF) * 16])));
		SET_V8(row1Value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(row1Address & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(row1Address & 0xF) * 16])));
		PPCVRegister diagonalRow0{};
		PPCVRegister diagonalRow1{};
		PPCVRegister diagonalRow2{};
		SET_V8(diagonalRow0, simde_mm_and_si128(V8(row0Value), VLOAD(xLaneMask & ~0xF)));
		SET_V8(diagonalRow1, simde_mm_and_si128(simde_mm_shuffle_epi32(V8(row1Value), 0xFF), VLOAD(yLaneMask & ~0xF)));
		SET_V8(diagonalRow2, simde_mm_and_si128(simde_mm_shuffle_epi32(V8(row2Value), 0xFF), VLOAD(zLaneMask & ~0xF)));
		VSTORE((stack + 96) & ~0xF, V8(diagonalRow0));
		VSTORE((stack + 112) & ~0xF, V8(diagonalRow1));
		VSTORE((stack + 128) & ~0xF, V8(diagonalRow2));
	}

	// The 4x4 matrix at stack + 144: the three rows and row 3 (the diagonal value in lane w), times the
	// render context's matrix at +1712.
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(diagonalValue));
	uint32_t row3Address = stack + 80;
	PPCVRegister row3Value{};
	SET_V8(row3Value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(row3Address & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(row3Address & 0xF) * 16])));
	PPCVRegister row3{};
	SET_V8(row3, simde_mm_and_si128(simde_mm_shuffle_epi32(V8(row3Value), 0xFF), VLOAD(wLaneMask & ~0xF)));
	PPCVRegister row0{};
	PPCVRegister row1{};
	PPCVRegister row2{};
	SET_V8(row0, VLOAD((stack + 96) & ~0xF));
	SET_V8(row2, VLOAD((stack + 128) & ~0xF));
	SET_V8(row1, VLOAD((stack + 112) & ~0xF));
	uint32_t matrix = stack + 144;
	VSTORE(matrix & ~0xF, V8(row0));
	VSTORE((stack + 160) & ~0xF, V8(row1));
	VSTORE((stack + 176) & ~0xF, V8(row2));
	VSTORE((stack + 192) & ~0xF, V8(row3));
	uint32_t product = stack + 208;
	ctx.r1.u64 = stack;
	Matrix4x4_Multiply(ctx, base, product, renderContext + 1712, matrix);
	for (uint32_t offset = 0; offset < 64; offset += 8) {
		STORE64(matrix + offset, LOAD64(product + offset));
	}

	uint32_t result = CModelRenderer_UpdateScale(ctx, base, modelRendererAddr, rows, matrix);
	stack = PopStackFrame(stack, 288);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(6, sub_82218F88, 0x82218F88) { ctx.r3.u64 = CModelRenderer_UpdateTransform(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CModelRenderer_RenderDescriptor(CpuState& ctx, uint8_t* base, uint64_t modelRendererAddr, uint32_t effectDefinition, uint64_t renderContext) {
	// The two render pools (RenderPool_Pop, RenderPool_CleanupAll): 1024 entries of 8 bytes, a bit word (+8192)
	// and the entry count (+8196) each.
	constexpr int32_t firstRenderPool = int32_t(0x834B8090);
	constexpr int32_t secondRenderPool = firstRenderPool + 8200;
	constexpr uint32_t pushedEntryValue = 0x834BDB70;
	constexpr uint32_t effectDescriptors = 0x834A0ECC;
	constexpr uint32_t defaultResourceDescriptor = 0x834A0E68;
	if (!UseLiftedCode(6, 0x822190F8)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = effectDefinition; ctx.r5.u64 = renderContext; __imp__sub_822190F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822190F8);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 272);

	// Push an entry and a 0 bit on both pools; the record at stack + 80 tracks them.
	uint32_t firstCount = LOAD32(uint32_t(firstRenderPool) + 8196);
	STORE8(stack + 80, 1);
	STORE32(uint32_t(firstRenderPool) + (firstCount << 3), pushedEntryValue);
	uint32_t secondCount = LOAD32(uint32_t(secondRenderPool) + 8196);
	STORE32(uint32_t(firstRenderPool) + 8196, LOAD32(uint32_t(firstRenderPool) + 8196) + 1);
	STORE32(uint32_t(firstRenderPool) + 8192, LOAD32(uint32_t(firstRenderPool) + 8192) << 1);
	STORE32(uint32_t(secondRenderPool) + (secondCount << 3), pushedEntryValue);
	STORE32(uint32_t(secondRenderPool) + 8192, LOAD32(uint32_t(secondRenderPool) + 8192) << 1);
	STORE32(uint32_t(secondRenderPool) + 8196, LOAD32(uint32_t(secondRenderPool) + 8196) + 1);

	// The second descriptor when the definition's first 180-byte element has bit 5 set.
	uint32_t elementsBegin = LOAD32(effectDefinition + 20);
	bool firstElementBit5 = int32_t(LOAD32(effectDefinition + 24) - elementsBegin) / 180 != 0 && ((LOAD32(elementsBegin) >> 5) & 1) != 0;
	uint32_t effect = stack + 96;
	ctx.r1.u64 = stack;
	C_Unknown_InitializeFromDescriptor(ctx, base, effect, effectDefinition, effectDescriptors + (firstElementBit5 ? 20 : 0));

	// Fields InitializeEffect also sets (+4: here the default resource descriptor, +76, +82), and byte +81 when
	// m_3E or the element bit (read again after the call) is set.
	bool member3ESet = modelRenderer->m_3E != 0;
	STORE32(effect + 76, 1);
	STORE8(effect + 82, 1);
	STORE32(effect + 4, defaultResourceDescriptor);
	if (!member3ESet) {
		uint32_t currentBegin = LOAD32(effectDefinition + 20);
		firstElementBit5 = int32_t(LOAD32(effectDefinition + 24) - currentBegin) / 180 != 0 && ((LOAD32(LOAD32(effectDefinition + 20)) >> 5) & 1) != 0;
	}
	if (member3ESet || firstElementBit5) {
		STORE8(effect + 81, 1);
	}

	CModelRenderer_UpdateTransform(ctx, base, uint32_t(modelRendererAddr), uint32_t(renderContext));
	CModelRenderer_UpdateDistance(ctx, base, uint32_t(modelRendererAddr), uint32_t(renderContext));
	CModelRenderer_RenderEffect(ctx, base, modelRendererAddr, effect, modelRenderer->m_30, renderContext);

	if (LOAD8(stack + 201) != 0) {
		STORE8(stack + 201, 0);
		RenderPool_Pop(ctx, base, secondRenderPool);
	}
	if (LOAD8(stack + 200) != 0) {
		STORE8(stack + 200, 0);
		RenderPool_Pop(ctx, base, firstRenderPool);
	}
	uint64_t result = RenderPool_CleanupAll(ctx, base, stack + 80);

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(6, sub_822190F8, 0x822190F8) { ctx.r3.u64 = CModelRenderer_RenderDescriptor(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint32_t CModelRenderer_UpdateScale(CpuState& ctx, uint8_t* base, uint32_t modelRendererAddr, uint64_t rows, uint64_t matrix) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	constexpr uint32_t deviceSlot = uint32_t(g_83360000) + 412;
	constexpr uint32_t vertexConstantBlockMaskAddress = 0x83491598;
	constexpr uint32_t xLaneMask = 0x82099190;
	constexpr uint32_t yLaneMask = 0x820991A0;
	constexpr uint32_t zLaneMask = 0x820991B0;
	constexpr uint32_t numeratorAddress = 0x820994C0;
	constexpr uint32_t permuteControlAddress = uint32_t(g_820A0000 - 28160);
	if (!UseLiftedCode(6, 0x8221AA90)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = rows; ctx.r5.u64 = matrix; __imp__sub_8221AA90(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8221AA90);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	uint32_t stack = PushStackFrame(base, ctx.r1.u32, 160);

	// Vertex-shader constants c0..c3 from the matrix and c4..c6 from the three rows, each when its block bit
	// (63: c0..c3, 62: c4..c7) is in the mask.
	const uint64_t constantBlock0 = uint64_t(1) << 63;
	const uint64_t constantBlock1 = uint64_t(1) << 62;
	uint64_t vertexConstantBlocks = LOAD64(vertexConstantBlockMaskAddress);
	if ((vertexConstantBlocks & constantBlock0) != 0) {
		ctx.r1.u64 = stack;
		n_sub_8221A9B0(ctx, base, LOAD32(deviceSlot), 0, matrix, 4, constantBlock0);
	}
	bool setsBlock1 = (vertexConstantBlocks & constantBlock1) != 0;
	if (setsBlock1) {
		ctx.r1.u64 = stack;
		n_sub_8221A9B0(ctx, base, LOAD32(deviceSlot), 4, rows, 3, constantBlock1);
	}

	// The vector (w of row 0, w of row 1, w of row 2, numerator / length of the vector at +336 of m_4) at stack + 96.
	PPCVRegister row0W{};
	PPCVRegister row1W{};
	PPCVRegister row2W{};
	PPCVRegister lengthSquared{};
	SET_V8(row0W, simde_mm_shuffle_epi32(VLOAD(uint32_t(rows) & ~0xF), 0x0));
	SET_V8(lengthSquared, VLOAD((uint32_t(modelRenderer->m_4) + 336u) & ~0xF));
	ctx.fpscr.enableFlushMode();
	SET_VF(lengthSquared, simde_mm_dp_ps(VF(lengthSquared), VF(lengthSquared), 0xEF));
	SET_V8(row1W, simde_mm_shuffle_epi32(VLOAD((uint32_t(rows) + 16u) & ~0xF), 0x0));
	SET_V8(row2W, simde_mm_shuffle_epi32(VLOAD((uint32_t(rows) + 32u) & ~0xF), 0x0));
	SET_V8(row0W, simde_mm_and_si128(V8(row0W), VLOAD(xLaneMask & ~0xF)));
	SET_V8(row1W, simde_mm_and_si128(V8(row1W), VLOAD(yLaneMask & ~0xF)));
	SET_V8(row2W, simde_mm_and_si128(V8(row2W), VLOAD(zLaneMask & ~0xF)));
	PPCVRegister rows01W{};
	SET_V8(rows01W, simde_mm_or_si128(V8(row0W), V8(row1W)));
	ctx.fpscr.disableFlushModeUnconditional();
	double numerator = double(LOAD_F32(numeratorAddress));
	uint32_t vectorAddress = stack + 96;
	VSTORE(vectorAddress & ~0xF, V8(lengthSquared));
	double length = double(float(sqrt(double(LOAD_F32(vectorAddress)))));
	PPCVRegister wColumn{};
	SET_V8(wColumn, simde_mm_or_si128(V8(row2W), V8(rows01W)));
	double scale = double(float(numerator / length));
	STORE_F32(stack + 80, float(scale));
	uint32_t scaleAddress = stack + 80;
	PPCVRegister scaleVector{};
	SET_V8(scaleVector, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scaleAddress & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scaleAddress & 0xF) * 16])));
	PPCVRegister constant7{};
	SET_V8(constant7, rex::ppc::simde_mm_perm_epi8_(V8(wColumn), V8(scaleVector), VLOAD(permuteControlAddress & ~0xF)));
	VSTORE(vectorAddress & ~0xF, V8(constant7));

	// That vector is c7 (block 1, with c4..c6).
	if (setsBlock1) {
		uint32_t device = LOAD32(deviceSlot);
		STORE_F32(device + 2032, LOAD_F32(stack + 96));
		STORE_F32(device + 2036, LOAD_F32(stack + 100));
		STORE_F32(device + 2040, LOAD_F32(stack + 104));
		STORE_F32(device + 2044, LOAD_F32(stack + 108));
		STORE64(device, LOAD64(device) | constantBlock1);
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// (the original leaves these in r6, v1, v2, v3 and v31 for its callers)
	ctx.r6.s64 = g_820A0000;
	ctx.v1 = wColumn;
	ctx.v2 = rows01W;
	ctx.v3 = row2W;
	ctx.v31 = scaleVector;
	return vectorAddress;
}
PROMOTED_ENTRY(6, sub_8221AA90, 0x8221AA90) { ctx.r3.u64 = CModelRenderer_UpdateScale(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint32_t CModelRenderer_DrawBatches(CpuState& ctx, uint8_t* base, uint32_t modelRendererAddr, uint64_t renderContext, uint32_t materialRecords) {
	constexpr uint32_t g_820067A8 = 0x820067A8u;
	constexpr uint32_t g_83360000 = 0x83360000u;
	constexpr uint32_t deviceSlot = g_83360000 + 412;
	// Per primitive type: the multiplier and the addend that turn a primitive count into an index count.
	constexpr uint32_t indexCountTable = g_820067A8;
	constexpr uint32_t scaledThresholdAddress = 0x8209E848;
	constexpr uint32_t thresholdAddress = 0x820F6B84;
	if (!UseLiftedCode(6, 0x8221BCC8)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = renderContext; ctx.r5.u64 = materialRecords; __imp__sub_8221BCC8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8221BCC8);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	// (f12 and f13 go on to GetBatchList as this leaves them; where it sets neither, the caller's values)
	double scaledSelectionValue = ctx.f12.f64;
	double comparedValue = ctx.f13.f64;
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 192);

	// Which batch list (0, 1 or 2) of the renderer data: chosen by the render context's mode and the value at +480 of m_4.
	uint32_t contextMode = LOAD32(uint32_t(renderContext) + 1788);
	ctx.fpscr.disableFlushMode();
	double selectionValue = double(LOAD_F32(uint32_t(modelRenderer->m_4) + 480));
	uint32_t batchListIndex;
	if (int32_t(contextMode) == 2) {
		comparedValue = double(LOAD_F32(LOAD32(uint32_t(renderContext) + 4) + 188));
		scaledSelectionValue = double(float(comparedValue * selectionValue));
		batchListIndex = scaledSelectionValue > double(LOAD_F32(scaledThresholdAddress)) ? 1 : 0;
	} else if (int32_t(contextMode) == 0) {
		batchListIndex = 2;
	} else {
		ctx.fpscr.disableFlushMode();
		comparedValue = double(LOAD_F32(thresholdAddress));
		batchListIndex = selectionValue > comparedValue ? 2 : 0;
	}

	uint32_t rendererData = modelRenderer->m_34;
	ctx.r1.u64 = stack;
	ctx.f12.f64 = scaledSelectionValue;
	ctx.f13.f64 = comparedValue;
	uint32_t batchList = CModelRenderer_GetBatchList(ctx, base, modelRendererAddr, rendererData, batchListIndex);
	// A value the callees take and leave in r7, handed on from call to call.
	uint64_t forwardedValue = ctx.r7.u64;
	uint32_t result = batchList;

	// 64-byte batches: material index (+4), strip flag (+10), primitive count (+12), start index (+16).
	int32_t batchCount = int32_t(LOAD32(batchList + 8) - LOAD32(batchList + 4)) >> 6;
	uint32_t lastMaterialIndex = 0xFFFFFFFF;
	for (uint32_t batchOffset = 0; batchCount > 0; --batchCount, batchOffset += 64) {
		uint32_t batch = batchOffset + LOAD32(batchList + 4);
		uint32_t materialIndex = LOAD32(batch + 4);
		// The material index, or the result of the material set-up (and of FlushBatch), goes to the state flush.
		uint32_t flushArgument = materialIndex;
		if (int32_t(materialIndex) != int32_t(lastMaterialIndex)) {
			lastMaterialIndex = materialIndex;
			if (LOAD8(uint32_t(renderContext) + 1802) != 0) {
				n_sub_82A97068(ctx, base, materialIndex);
			}
			uint32_t material = CModelRenderer_GetBatchMaterial(ctx, base, rendererData);
			uint64_t recordOffset = uint64_t(LOAD32(batch + 4)) * 180;
			uint32_t materialVtable = LOAD32(material);
			uint32_t setupMethod = LOAD32(materialVtable + 44);
			ctx.r3.u64 = material;
			ctx.r4.u64 = recordOffset + LOAD32(materialRecords + 4);
			ctx.r5.u64 = renderContext;
			ctx.r6.u64 = 0;
			ctx.r8.u64 = setupMethod;
			ctx.r9.u64 = materialVtable;
			ctx.r10.u64 = recordOffset;
			REX_CALL_INDIRECT_FUNC(setupMethod);
			flushArgument = ctx.r3.u32;
			forwardedValue = LOAD8(uint32_t(renderContext) + 1802);
			if (uint32_t(forwardedValue) != 0) {
				ctx.r7.u64 = forwardedValue;
				flushArgument = CModelRenderer_FlushBatch(ctx, base);
				forwardedValue = ctx.r7.u64;
			}
		}

		uint32_t stripFlag = LOAD8(batch + 10);
		int32_t primitiveCount = int32_t(LOAD32(batch + 12));
		uint32_t startIndex = LOAD32(batch + 16);
		uint64_t negatedStripFlag = 0 - uint64_t(stripFlag);
		uint64_t stripMask = stripFlag == 0 ? 0 : ~uint64_t(0);
		// Primitive type 4, or 6 with the strip flag.
		uint32_t primitiveType = (uint32_t(stripMask) & 2) + 4;
		ctx.r3.u64 = flushArgument;
		ctx.r7.u64 = forwardedValue;
		ctx.r9.u64 = stripMask;
		ctx.r10.u64 = negatedStripFlag;
		GameRenderStateFlush(ctx, base);

		uint32_t tableEntryOffset = primitiveType << 3;
		uint32_t device = LOAD32(deviceSlot);
		uint32_t indexMultiplier = LOAD32(indexCountTable + tableEntryOffset);
		uint32_t indexAddend = LOAD32(indexCountTable + tableEntryOffset + 4);
		uint64_t indexCount = uint64_t(int64_t(int32_t(indexMultiplier)) * int64_t(primitiveCount)) + indexAddend;
		ctx.r8.u64 = tableEntryOffset;
		ctx.r10.u64 = indexAddend;
		result = D3DDevice_DrawIndexedVertices_8221E0F0(ctx, base, device, primitiveType, 0, startIndex, indexCount);
		forwardedValue = ctx.r7.u64;
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(6, sub_8221BCC8, 0x8221BCC8) { ctx.r3.u64 = CModelRenderer_DrawBatches(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint32_t CModelRenderer_RenderEffect(CpuState& ctx, uint8_t* base, uint64_t modelRendererAddr, uint64_t effect, uint64_t materialRecords, uint64_t renderContext) {
	constexpr int32_t g_834B8090 = int32_t(0x834B8090);
	constexpr int32_t secondRenderPool = g_834B8090 + 8200;
	constexpr uint32_t deviceSlot = 0x8336019C;
	if (!UseLiftedCode(6, 0x8221F170)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = effect; ctx.r5.u64 = materialRecords; ctx.r6.u64 = renderContext; __imp__sub_8221F170(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8221F170);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	GameStackFrame stackFrame(ctx, base, 144);

	if (LOAD8(uint32_t(effect) + 82) == 0) {
		return uint32_t(modelRendererAddr);
	}

	uint32_t rendererData = modelRenderer->m_34;
	n_sub_82220D38(ctx, base, 0, rendererData + 76, 0, 0);
	// The resource in the slot at +88 of the renderer data: its data 8 bytes in, or 0 without one.
	uint32_t resourceSlot = rendererData + 88;
	uint64_t resourceData = 0;
	if (resourceSlot != 0) {
		uint32_t resource = LOAD32(resourceSlot);
		if (resource != 0) {
			resourceData = uint64_t(resource) + 8;
		}
	}
	n_sub_8219CCD8(ctx, base, LOAD32(deviceSlot), resourceData);
	Resource_StartLoading(ctx, base, effect, modelRenderer->m_2C);

	// Draw passes until Resource_IsLoaded reports the effect loaded; a single pass when the render context's
	// byte +1802 is set.
	uint32_t isLoaded;
	do {
		n_sub_82220788(ctx, base, effect, uint32_t(renderContext));

		uint32_t effectObject = LOAD32(uint32_t(effect));
		uint32_t preDrawMethod = LOAD32(LOAD32(effectObject) + 32);
		ctx.r3.u64 = effectObject;
		ctx.r4.u64 = effect;
		ctx.r5.u64 = renderContext;
		ctx.r6.u64 = modelRendererAddr;
		ctx.r7.u64 = LOAD32(uint32_t(effect) + 92);
		ctx.r10.u64 = preDrawMethod;
		REX_CALL_INDIRECT_FUNC(preDrawMethod);

		if (LOAD8(uint32_t(renderContext) + 1802) != 0) {
			n_sub_82B193E0(ctx, base, uint32_t(effect));
		} else {
			ctx.r9.u64 = 0;
			n_sub_82220908(ctx, base, uint32_t(effect));
		}
		if (LOAD8(uint32_t(renderContext) + 1802) == 0) {
			CModelRenderer_CullBatches(ctx, base, uint32_t(effect), renderContext, uint32_t(modelRenderer->m_4) + 80, ctx.r7.u64);
		}
		CModelRenderer_DrawBatches(ctx, base, uint32_t(modelRendererAddr), renderContext, uint32_t(materialRecords));

		uint32_t effectObjectAfter = LOAD32(uint32_t(effect));
		uint32_t postDrawMethod = LOAD32(LOAD32(effectObjectAfter) + 40);
		ctx.r3.u64 = effectObjectAfter;
		ctx.r4.u64 = effect;
		ctx.r10.u64 = postDrawMethod;
		REX_CALL_INDIRECT_FUNC(postDrawMethod);

		STORE32(uint32_t(effect) + 84, LOAD32(uint32_t(effect) + 84) + 1);
		ctx.r3.u64 = uint32_t(effect);
		n_sub_8221F5C8(ctx, base);
		STORE8(uint32_t(effect) + 105, 0);
		RenderPool_Pop(ctx, base, secondRenderPool);
		isLoaded = Resource_IsLoaded(ctx, base, uint32_t(effect)) & 0xFF;
	} while (isLoaded == 0 && LOAD8(uint32_t(renderContext) + 1802) == 0);

	ctx.r8.u64 = isLoaded;
	return n_sub_8221F6A8(ctx, base, uint32_t(effect));
}
PROMOTED_ENTRY(6, sub_8221F170, 0x8221F170) { ctx.r3.u64 = CModelRenderer_RenderEffect(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CModelRenderer_SubmitNode(CpuState& ctx, uint8_t* base, uint64_t modelRendererAddr, uint64_t renderContext) {
	constexpr uint32_t defaultEffectDefinitionSlot = 0x834A5518;
	if (!UseLiftedCode(6, 0x8221F2E0)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = renderContext; __imp__sub_8221F2E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8221F2E0);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);

	uint32_t contextMode = LOAD32(uint32_t(renderContext) + 1788);
	bool rendersWithDefaultDescriptor = contextMode == 0 || contextMode == 1 || contextMode == 7;

	// The effect definition: entry (+60 of m_34) of the table at +88 of m_1C, or the default definition.
	int32_t definitionIndex = int32_t(LOAD32(uint32_t(modelRenderer->m_34) + 60));
	uint32_t effectDefinition;
	if (definitionIndex >= 0) {
		effectDefinition = LOAD32(LOAD32(uint32_t(modelRenderer->m_1C) + 88) + (uint32_t(definitionIndex) << 2));
	} else {
		effectDefinition = LOAD32(defaultEffectDefinitionSlot);
	}

	if (rendersWithDefaultDescriptor) {
		return CModelRenderer_RenderDescriptor(ctx, base, modelRendererAddr, effectDefinition, renderContext);
	}
	return CModelRenderer_RenderWithEffect(ctx, base, modelRendererAddr, effectDefinition, renderContext);
}
PROMOTED_ENTRY(6, sub_8221F2E0, 0x8221F2E0) { ctx.r3.u64 = CModelRenderer_SubmitNode(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CModelRenderer_GetBatchList(CpuState& ctx, uint8_t* base, uint32_t modelRendererAddr, uint64_t rendererData, uint32_t batchListIndex) {
	if (!UseLiftedCode(6, 0x8222CDD8)) { ctx.r3.u64 = modelRendererAddr; ctx.r4.u64 = rendererData; ctx.r5.u64 = batchListIndex; __imp__sub_8222CDD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8222CDD8);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	GameStackFrame stackFrame(ctx, base, 96);

	// 16-byte batch lists: from +12 of the renderer data, or from its entry in the batch table at +224 of m_4.
	uint32_t batchListOffset = batchListIndex << 4;
	uint32_t batchTable = LOAD32(uint32_t(modelRenderer->m_4) + 224);
	if (batchTable == 0) {
		ctx.r4.u64 = rendererData;
		return batchListOffset + rendererData + 12;
	}
	uint64_t tableEntry = BatchTable_Find(ctx, base, batchTable, modelRenderer->m_1C, LOAD32(uint32_t(rendererData) + 8));
	return tableEntry + batchListOffset;
}
PROMOTED_ENTRY(6, sub_8222CDD8, 0x8222CDD8) { ctx.r3.u64 = CModelRenderer_GetBatchList(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint64_t n_sub_822383D0(CpuState& ctx, uint8_t* base, uint64_t modelRendererAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr uint32_t vertexConstantBlockMaskAddress = uint32_t(g_83490000) + 5528;
	constexpr uint32_t deviceSlot = 0x8336019C;
	if (!UseLiftedCode(7, 0x822383D0)) { ctx.r3.u64 = modelRendererAddr; __imp__sub_822383D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822383D0);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);

	// m_40: 16-byte vectors with their count at +192.
	uint32_t vectorBuffer = modelRenderer->m_40;
	if (vectorBuffer == 0) {
		return modelRendererAddr;
	}
	int32_t vectorCount = int32_t(LOAD32(vectorBuffer + 192));
	if (vectorCount <= 0) {
		return modelRendererAddr;
	}
	// Bit 56: the block of vertex constants c28..c31.
	if ((LOAD64(vertexConstantBlockMaskAddress) & (uint64_t(1) << 56)) == 0) {
		return modelRendererAddr;
	}

	// The vectors go to c28 on: one block bit per four constants, from bit 56 down to the block of the last one.
	uint64_t lastBlockOffset = ((((uint32_t(vectorCount) + 27) >> 2) - 7) & 0x7F);
	if (lastBlockOffset > 63) {
		lastBlockOffset = 63;
	}
	uint64_t blockBits = __builtin_rotateleft64(uint64_t(INT64_MIN >> lastBlockOffset), 57) & 0x01FFFFFFFFFFFFFF;
	uint32_t device = LOAD32(deviceSlot);
	n_sub_8221A9B0(ctx, base, device, 28, vectorBuffer, uint32_t(vectorCount), blockBits);
	return device;
}
PROMOTED_ENTRY(7, sub_822383D0, 0x822383D0) { ctx.r3.u64 = n_sub_822383D0(ctx, base, ctx.r3.u64); }

uint32_t CModelRenderer_GetRenderResource(CpuState& ctx, uint8_t* base, uint32_t modelRendererAddr) {
	// Resource descriptors, 20 bytes each from 0x834A0E54.
	constexpr uint32_t g_834A0E68 = 0x834A0E68;
	constexpr uint32_t mode1Descriptor = 0x834A0E54;
	constexpr uint32_t mode3Descriptor = 0x834A0EB8;
	if (!UseLiftedCode(13, 0x822D8060)) { ctx.r3.u64 = modelRendererAddr; __imp__sub_822D8060(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822D8060);
	CModelRenderer* modelRenderer = GameObject<CModelRenderer>(base, modelRendererAddr);
	GameStackFrame stackFrame(ctx, base, 96);

	uint32_t rendererData = modelRenderer->m_34;
	uint32_t resourceMode = modelRenderer->m_24;
	if (resourceMode == 1) {
		n_sub_82220D38(ctx, base, 1, LOAD32(uint32_t(modelRenderer->m_4) + 516), LOAD32(rendererData + 140), 0);
		return mode1Descriptor;
	}
	if (resourceMode == 2) {
		uint32_t descriptorIndex = LOAD32(rendererData + 124);
		n_sub_82220D38(ctx, base, 1, rendererData + 100, 0, 0);
		return g_834A0E68 + descriptorIndex * 20;
	}
	if (resourceMode == 3) {
		n_sub_82220D38(ctx, base, 1, LOAD32(uint32_t(modelRenderer->m_1C) + 212), LOAD32(rendererData + 144), 0);
		return mode3Descriptor;
	}
	return g_834A0E68;
}
PROMOTED_ENTRY(13, sub_822D8060, 0x822D8060) { ctx.r3.u64 = CModelRenderer_GetRenderResource(ctx, base, ctx.r3.u32); }
