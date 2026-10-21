// CRenderViewPass (vtable 0x820052E8): methods of the class as readable C++.
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

uint32_t CRenderViewPass_RenderDebugGeometry(CpuState& ctx, uint8_t* base, uint64_t renderContext) {
	if (!UseLiftedCode(1, 0x821A58C0)) { ctx.r4.u64 = renderContext; __imp__sub_821A58C0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821A58C0);
	// Records of the state block: value +4, mask +8, queued byte +20, log page number (from 1) +21.
	constexpr uint32_t stateBlock = 0x834C0000u - 16224;
	constexpr uint32_t logPages = 0x834B8090u;
	constexpr uint32_t changeQueue = 0x83490BF0u;
	constexpr uint32_t changeQueueCountAddress = 0x83390000u + 1000;
	constexpr uint32_t newValueAddress = 0x83316EF4u + 8;
	constexpr uint32_t floatConstants = 0x820994B4u;   // 0.0f, 0.5f, 1.0f, 1.0f
	constexpr uint32_t deviceSlot = 0x8336019Cu;
	constexpr uint32_t vertexConstantBlockMaskAddress = 0x83491598u;
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	// State record +120 takes the value at newValueAddress: when it changes, its old value goes into its log page
	// (unless the record's mask already has bits of the page's mask) and the record into the change queue once.
	const uint32_t record = stateBlock + 120;
	const uint32_t newValue = LOAD32(newValueAddress);
	const uint32_t logPage = LOAD8(record + 21) * 8200u + logPages - 8200u;
	if (LOAD32(record + 4) != newValue) {
		const uint32_t pageMask = LOAD32(logPage + 8192);
		const uint32_t recordMask = LOAD32(record + 8);
		if ((pageMask & recordMask) == 0) {
			const uint32_t entryOffset = LOAD32(logPage + 8196) << 3;
			STORE32(record + 8, pageMask | recordMask);
			STORE32(logPage + entryOffset, record);
			STORE32(logPage + (LOAD32(logPage + 8196) << 3) + 4, LOAD32(record + 4));
			STORE32(logPage + 8196, LOAD32(logPage + 8196) + 1);
		}
		const uint8_t queued = LOAD8(record + 20);
		STORE32(record + 4, newValue);
		if (queued == 0) {
			STORE8(record + 20, 1);
			const uint32_t queueCount = LOAD32(changeQueueCountAddress);
			STORE32(changeQueueCountAddress, queueCount + 1);
			STORE32(changeQueue + (queueCount << 2), record);
		}
	}

	// Vectors put together in the frame from 0.0 and 1.0 (lanes 0..3): (1, 0, 0, 1) for Weather_UpdateSnowFlake,
	// and (0, 1, ...) and (0, ...), which the original leaves for the calls that hand them on.
	ctx.fpscr.disableFlushMode();
	const float zero = LOAD_F32(floatConstants);
	const float one = LOAD_F32(floatConstants + 12);
	auto loadVectorLeft = [&](uint32_t address) {
		PPCVRegister value{};
		SET_V8(value, simde_mm_shuffle_epi8(
			simde_mm_load_si128((simde__m128i*)RAW(address & ~0xF)),
			simde_mm_load_si128((simde__m128i*)&VectorMaskL[(address & 0xF) * 16])));
		return value;
	};
	STORE_F32(stack + 80, zero);
	PPCVRegister zeroOne = loadVectorLeft(stack + 80);
	STORE_F32(stack + 80, one);
	STORE_F32(stack + 84, one);
	const uint64_t vertexConstantBlocks = LOAD64(vertexConstantBlockMaskAddress);
	PPCVRegister oneFirst = loadVectorLeft(stack + 84);
	SET_VF(zeroOne, simde_mm_blend_ps(VF(zeroOne), simde_mm_permute_ps(VF(oneFirst), 57), 4));
	STORE_F32(stack + 84, zero);
	PPCVRegister zeroFirst = loadVectorLeft(stack + 84);
	PPCVRegister oneZeroZeroOne = loadVectorLeft(stack + 80);
	SET_VF(oneZeroZeroOne, simde_mm_blend_ps(VF(oneZeroZeroOne), simde_mm_permute_ps(VF(zeroFirst), 57), 4));
	SET_VF(oneZeroZeroOne, simde_mm_blend_ps(VF(oneZeroZeroOne), simde_mm_permute_ps(VF(zeroOne), 78), 3));

	// The vertex constant block c0..c3 (bit 63) from the four vectors at +1712 of the render context.
	ctx.r1.u64 = stack;
	const uint64_t constantBlock0 = uint64_t(1) << 63;
	if ((vertexConstantBlocks & constantBlock0) != 0) {
		ctx.v12 = zeroFirst;
		ctx.v13 = zeroOne;
		n_sub_8221A9B0(ctx, base, LOAD32(deviceSlot), 0, renderContext + 1712, 4, constantBlock0);
		zeroFirst = ctx.v12;
		zeroOne = ctx.v13;
	}

	ctx.v1 = oneZeroZeroOne;
	Weather_UpdateSnowFlake(ctx, base, 405);
	ctx.v12 = zeroFirst;
	ctx.v13 = zeroOne;
	uint32_t result = Debug_DrawFlaggedVertices(ctx, base, 63);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_821A58C0, 0x821A58C0) { ctx.r3.u64 = CRenderViewPass_RenderDebugGeometry(ctx, base, ctx.r4.u64); }

uint64_t CRenderViewPass_UpdateBlend(CpuState& ctx, uint8_t* base, uint64_t renderViewPassAddr, uint64_t renderContext) {
	if (!UseLiftedCode(3, 0x821C7EE0)) { ctx.r3.u64 = renderViewPassAddr; ctx.r4.u64 = renderContext; __imp__sub_821C7EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821C7EE0);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr uint32_t C_82001118_vtable = 0x82001118u;
	constexpr uint32_t minimumValueAddress = 0x82099AE0u;   // 1.0e-4f
	constexpr uint32_t floatZeroAddress = 0x820994B4u;      // 0.0f
	constexpr uint32_t nodeHeapAddress = 0x83490000u + 27876;
	constexpr uint32_t nodeSequenceAddress = 0x83490000u + 27872;
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	// The float at +128 of the render data (the object at +20 of the context's object at +4), read through a
	// vector copy in the frame.
	const double minimumValue = double(LOAD_F32(minimumValueAddress));
	const uint32_t renderData = LOAD32(LOAD32(uint32_t(renderContext) + 4) + 20);
	PPCVRegister dataVector{};
	SET_V8(dataVector, VLOAD((renderData + 128u) & ~0xFu));
	VSTORE((stack + 80u) & ~0xFu, V8(dataVector));
	const double value = double(LOAD_F32(stack + 80));

	// A 32-byte C_82001118 node owned by this pass, with the next sequence number at +24 and the flag at +28.
	auto initializeNode = [&](uint32_t node, uint8_t flag) {
		const uint32_t sequence = LOAD32(nodeSequenceAddress);
		STORE32(node + 4, uint32_t(renderViewPassAddr));
		STORE32(node + 8, 0);
		STORE32(node + 12, 0);
		STORE32(node + 16, 0);
		STORE32(node + 24, sequence);
		STORE32(node + 20, 0);
		STORE32(nodeSequenceAddress, sequence + 1);
		STORE32(node, C_82001118_vtable);
		STORE8(node + 28, flag);
	};

	uint64_t result = renderViewPassAddr;
	uint64_t handedBackValue = renderContext;   // (the original hands back in r4 what the last call leaves there)
	if (value > minimumValue) {
		// Two nodes (flag 0, then 1) for the lists at +728 and +784 of the context's first object.
		ctx.r1.u64 = stack;
		ctx.r8.s64 = g_820A0000;
		ctx.f13.f64 = value;
		const uint32_t firstNode = Memory_Allocate_82BE4BF8(ctx, base, LOAD32(nodeHeapAddress), 32);
		if (firstNode != 0) {
			initializeNode(firstNode, 0);
		}
		ctx.fpscr.disableFlushMode();
		const double zero = double(LOAD_F32(floatZeroAddress));
		n_sub_8222C308(ctx, base, uint64_t(LOAD32(uint32_t(renderContext))) + 728, firstNode, zero);

		const uint64_t secondNode = Memory_Allocate_82BE4BF8(ctx, base, LOAD32(nodeHeapAddress), 32);
		if (uint32_t(secondNode) != 0) {
			initializeNode(uint32_t(secondNode), 1);
		}
		ctx.fpscr.disableFlushMode();
		result = n_sub_8222C308(ctx, base, uint64_t(LOAD32(uint32_t(renderContext))) + 784, uint32_t(secondNode), zero);
		handedBackValue = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = handedBackValue;
	return result;
}
PROMOTED_ENTRY(3, sub_821C7EE0, 0x821C7EE0) { ctx.r3.u64 = CRenderViewPass_UpdateBlend(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CRenderViewPass_Render(CpuState& ctx, uint8_t* base, uint64_t renderViewPassAddr, uint32_t renderContext, uint32_t renderParams) {
	if (!UseLiftedCode(3, 0x821DB590)) { ctx.r3.u64 = renderViewPassAddr; ctx.r4.u64 = renderContext; ctx.r5.u64 = renderParams; __imp__sub_821DB590(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821DB590);
	constexpr uint32_t floatZeroAddress = 0x820994B4u;   // 0.0f
	constexpr uint32_t deviceSlot = 0x8336019Cu;
	constexpr uint32_t streamSettingsHolder = 0x834BDBC0u;
	constexpr uint32_t useRenderParamsFlag = 0x8335CA12u;
	constexpr uint32_t pixelConstantBlockMaskAddress = 0x83491590u;
	constexpr uint32_t xyzThenWPermute = 0x82099200u;   // bytes 0..11 of the first vector, 0..3 of the second
	CRenderViewPass* renderViewPass = GameObject<CRenderViewPass>(base, renderViewPassAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);

	// Two { float, handle } records at stack + 96, each { 0.0, 0 }, for n_sub_821D08C0 to fill.
	ctx.fpscr.disableFlushMode();
	const float zero = LOAD_F32(floatZeroAddress);
	const uint32_t records = stack + 96;
	STORE_F32(records, zero);
	STORE32(records + 4, 0);
	STORE_F32(records + 8, zero);
	STORE32(records + 12, 0);
	ctx.r1.u64 = stack;
	n_sub_821D08C0(ctx, base, renderViewPass->m_14 + 16, 1, records, 2);

	// Each record's handle goes to a vertex declaration slot (+272, +276) through a copy at stack + 80.
	const uint64_t firstDeclarationSlot = renderViewPassAddr + 272;
	STORE32(stack + 80, LOAD32(records + 4));
	VertexDeclaration_Set(ctx, base, uint32_t(firstDeclarationSlot), stack + 80);
	const uint64_t secondDeclarationSlot = renderViewPassAddr + 276;
	STORE32(stack + 80, LOAD32(records + 12));
	VertexDeclaration_Set(ctx, base, uint32_t(secondDeclarationSlot), stack + 80);
	ctx.r4.u64 = 0;
	const uint32_t firstStream = VertexDeclaration_GetStream(ctx, base, firstDeclarationSlot);
	ctx.r4.u64 = 0;
	const uint32_t secondStream = VertexDeclaration_GetStream(ctx, base, secondDeclarationSlot);

	// The stream numbers at +2676 and +2688 of the object held at streamSettingsHolder (negative: none) take the
	// streams' data (+4), with the stream's bit (bit 31 - number of a 32-bit mask). The original leaves 1 in r9,
	// then what the first call leaves there, and GraphicsDevice_SetStreamSource hands it on.
	const uint64_t topBit = uint64_t(1) << 63;
	uint64_t handedOnValue = 1;
	uint32_t streamSettings = LOAD32(streamSettingsHolder + 4);
	const uint32_t firstStreamNumber = LOAD32(streamSettings + 2676);
	if ((int32_t)firstStreamNumber >= 0) {
		const uint32_t device = LOAD32(deviceSlot);
		const uint32_t streamData = LOAD32(firstStream + 4);
		const uint32_t shift = firstStreamNumber + 32;
		const uint64_t streamBit = (shift & 0x40) ? 0 : topBit >> (shift & 0x7F);
		ctx.r9.u64 = handedOnValue;
		GraphicsDevice_SetStreamSource(ctx, base, device, firstStreamNumber, streamData, streamBit);
		handedOnValue = ctx.r9.u64;
		streamSettings = LOAD32(streamSettingsHolder + 4);
	}
	const uint32_t secondStreamNumber = LOAD32(streamSettings + 2688);
	if ((int32_t)secondStreamNumber >= 0) {
		const uint32_t device = LOAD32(deviceSlot);
		const uint32_t streamData = LOAD32(secondStream + 4);
		const uint32_t shift = secondStreamNumber + 32;
		const uint64_t streamBit = (shift & 0x40) ? 0 : topBit >> (shift & 0x7F);
		ctx.r9.u64 = handedOnValue;
		GraphicsDevice_SetStreamSource(ctx, base, device, secondStreamNumber, streamData, streamBit);
	}

	ctx.fpscr.disableFlushMode();
	double propertyValue = double(LOAD_F32(records + 8));
	World_SetRegionProperty(ctx, base, 225, propertyValue);
	SetGlobalVectorFromBytes(ctx, base, 1, 1);
	if (LOAD8(renderContext + 1802) == 0) {
		if (renderParams != 0 && LOAD8(useRenderParamsFlag) != 0) {
			ctx.f1.f64 = propertyValue;
			n_sub_82A7A8A8(ctx, base, renderParams, renderContext);
		} else {
			n_sub_8226E048(ctx, base);
		}
	}
	ctx.fpscr.disableFlushMode();
	propertyValue = double(renderViewPass->m_4C);
	World_SetRegionProperty(ctx, base, 266, propertyValue);
	ctx.fpscr.disableFlushMode();
	propertyValue = double(renderViewPass->m_50);
	const uint32_t result = World_SetRegionProperty(ctx, base, 265, propertyValue);

	// Pixel constant c19 = (x, y, z of the render context's vector at +1680, 0.0) when its block (bit 59:
	// c16..c19) is in the mask; the vector is put together in the frame at stack + 96.
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, LOAD_F32(floatZeroAddress));
	const uint64_t pixelConstantBlocks = LOAD64(pixelConstantBlockMaskAddress);
	const uint32_t zeroAddress = stack + 80;
	PPCVRegister zeroLane{};
	SET_V8(zeroLane, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(zeroAddress & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(zeroAddress & 0xF) * 16])));
	PPCVRegister contextVector{};
	SET_V8(contextVector, VLOAD((renderContext + 1680u) & ~0xF));
	PPCVRegister permuteControl{};
	SET_V8(permuteControl, VLOAD(xyzThenWPermute & ~0xF));
	PPCVRegister constantValue{};
	SET_V8(constantValue, rex::ppc::simde_mm_perm_epi8_(V8(contextVector), V8(zeroLane), V8(permuteControl)));
	VSTORE((stack + 96) & ~0xF, V8(constantValue));
	const uint64_t constantBlock4 = uint64_t(1) << 59;
	if ((pixelConstantBlocks & constantBlock4) != 0) {
		const uint32_t device = LOAD32(deviceSlot);
		const float z = LOAD_F32(stack + 104);
		const float y = LOAD_F32(stack + 100);
		const float w = LOAD_F32(stack + 108);
		STORE_F32(device + 6320, LOAD_F32(stack + 96));
		STORE_F32(device + 6328, z);
		STORE_F32(device + 6324, y);
		STORE_F32(device + 6332, w);
		STORE64(device + 8, LOAD64(device + 8) | constantBlock4);
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = propertyValue;
	return result;
}
PROMOTED_ENTRY(3, sub_821DB590, 0x821DB590) { ctx.r3.u64 = CRenderViewPass_Render(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32); }

uint32_t CRenderViewPass_RenderEntities(CpuState& ctx, uint8_t* base, uint64_t renderViewPassAddr, uint64_t renderContext, uint32_t renderParams) {
	if (!UseLiftedCode(9, 0x82267818)) { ctx.r3.u64 = renderViewPassAddr; ctx.r4.u64 = renderContext; ctx.r5.u64 = renderParams; __imp__sub_82267818(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82267818);
	constexpr uint32_t floatZeroAddress = 0x820994B4u;   // 0.0f
	constexpr int32_t FloatField4Greater_address = int32_t(0x8218D9E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);
	ctx.r1.u64 = stack;

	// A pointer vector in the frame at stack + 96 (begin +100, end +104, capacity end +108) collects the sub-passes
	// to draw; PtrVector_InsertGrow and Vector_Sort take { 0, pointer } iterators from stack + 80 and stack + 96.
	const uint32_t list = stack + 96;
	const uint32_t listBeginAddr = stack + 100;
	const uint32_t listEndAddr = stack + 104;
	const uint32_t listCapacityEndAddr = stack + 108;
	const uint32_t iterator = stack + 80;
	uint32_t listBegin = 0;
	uint64_t listEnd = 0;
	STORE32(listCapacityEndAddr, 0);
	STORE32(listBeginAddr, listBegin);
	STORE32(listEndAddr, uint32_t(listEnd));
	const double zero = double(LOAD_F32(floatZeroAddress));

	// What the original leaves in r8 and r9 for Vector_Sort, which hands both on to the comparator: what the last
	// call left there, or the list's entry count and byte size before the last addition, or word +64 of the last
	// sub-pass.
	uint64_t handedOnCount = ctx.r8.u64;
	uint64_t handedOnValue = 0;

	// Each of the four sub-passes (+256) updates its render data; one with a word at +64 and a float at +0 above
	// zero joins the list.
	uint64_t subPassSlot = renderViewPassAddr + 256;
	for (uint64_t index = 0; uint32_t(index) < 4; ++index, subPassSlot += 4) {
		const uint32_t renderData = LOAD32(LOAD32(uint32_t(renderContext) + 4) + 20) + 16;
		Entity_UpdateRenderData(ctx, base, LOAD32(uint32_t(subPassSlot)), renderData, index);
		handedOnCount = ctx.r8.u64;
		const uint32_t subPass = LOAD32(uint32_t(subPassSlot));
		handedOnValue = LOAD32(subPass + 64);
		bool isDrawn = false;
		if (uint32_t(handedOnValue) != 0) {
			ctx.fpscr.disableFlushMode();
			isDrawn = double(LOAD_F32(subPass)) > zero;
		}
		if (!isDrawn) {
			continue;
		}
		const uint32_t capacity = listBegin == 0 ? 0 : uint32_t(int32_t(LOAD32(listCapacityEndAddr) - listBegin) >> 2);
		handedOnValue = listEnd - listBegin;
		handedOnCount = uint64_t(int64_t(int32_t(handedOnValue) >> 2));
		if (uint32_t(handedOnCount) < capacity) {
			STORE32(uint32_t(listEnd), subPass);
			listEnd += 4;
			STORE32(listEndAddr, uint32_t(listEnd));
		} else {
			STORE32(iterator + 4, uint32_t(listEnd));
			STORE32(iterator, 0);
			PtrVector_InsertGrow(ctx, base, list, LOAD64(iterator), subPassSlot);
			handedOnCount = ctx.r8.u64;
			handedOnValue = ctx.r9.u64;
			listEnd = LOAD32(listEndAddr);
			listBegin = LOAD32(listBeginAddr);
		}
	}

	// Sorted by the float at +4 (largest first), then drawn in that order.
	const uint32_t listBytes = uint32_t(listEnd) - listBegin;
	STORE32(iterator + 4, uint32_t(listEnd));
	STORE32(listBeginAddr, listBegin);
	uint32_t remaining = uint32_t(int32_t(listBytes) >> 2);
	STORE32(iterator, 0);
	STORE32(list, 0);
	const uint64_t sortEnd = LOAD64(iterator);
	const uint64_t sortBegin = LOAD64(list);
	ctx.r8.u64 = handedOnCount;
	ctx.r9.u64 = handedOnValue;
	uint32_t result = Vector_Sort(ctx, base, sortBegin, sortEnd, remaining, uint64_t(int64_t(FloatField4Greater_address)));
	if (remaining != 0) {
		uint32_t cursor = listBegin;
		do {
			result = Entity_Render(ctx, base, LOAD32(cursor), renderContext, renderParams);
			--remaining;
			cursor += 4;
		} while (remaining != 0);
	}
	if (listBegin != 0) {
		result = HandleTarget_Free(ctx, base, listBegin);
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(9, sub_82267818, 0x82267818) { ctx.r3.u64 = CRenderViewPass_RenderEntities(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CRenderViewPass_RenderView(CpuState& ctx, uint8_t* base, uint64_t renderViewPassAddr, uint64_t renderContext) {
	if (!UseLiftedCode(10, 0x8228EBA8)) { ctx.r3.u64 = renderViewPassAddr; ctx.r4.u64 = renderContext; __imp__sub_8228EBA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8228EBA8);
	// The two render pools (RenderPool_Pop, RenderPool_CleanupAll): 1024 entries of 8 bytes, a bit word (+8192)
	// and the entry count (+8196) each.
	constexpr uint32_t firstRenderPool = 0x834B8090u;
	constexpr uint32_t secondRenderPool = firstRenderPool + 8200;
	constexpr uint32_t pushedEntryValue = 0x834BDB70u;
	constexpr uint32_t renderViewStartedFlag = 0x833214CCu;
	CRenderViewPass* renderViewPass = GameObject<CRenderViewPass>(base, renderViewPassAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	// Push an entry and a 0 bit on both pools; the record at stack + 80 has RenderPool_CleanupAll pop them.
	const uint32_t firstCount = LOAD32(firstRenderPool + 8196);
	STORE8(stack + 80, 1);
	STORE8(renderViewStartedFlag, 1);
	STORE32(firstRenderPool + (firstCount << 3), pushedEntryValue);
	const uint32_t firstBits = LOAD32(firstRenderPool + 8192);
	const uint32_t secondEntryOffset = LOAD32(secondRenderPool + 8196) << 3;
	STORE32(firstRenderPool + 8196, LOAD32(firstRenderPool + 8196) + 1);
	STORE32(firstRenderPool + 8192, firstBits << 1);
	STORE32(secondRenderPool + secondEntryOffset, pushedEntryValue);
	const uint32_t secondCount = LOAD32(secondRenderPool + 8196);
	const uint32_t secondBits = LOAD32(secondRenderPool + 8192);
	STORE32(secondRenderPool + 8192, secondBits << 1);
	STORE32(secondRenderPool + 8196, secondCount + 1);

	if (LOAD8(uint32_t(renderContext) + 1798) != 0) {
		ctx.r1.u64 = stack;
		CRenderViewPass_ExecuteRender(ctx, base, renderViewPassAddr, renderContext, 0);
	} else {
		// When the context's word +1788 is 2, the pass renders with what n_sub_82295E50 makes of m_14 and the
		// context's vector at +1680 (copied to stack + 96), and the four sub-passes (+256) update their render data.
		uint32_t renderParams = 0;
		if (LOAD32(uint32_t(renderContext) + 1788) == 2) {
			PPCVRegister contextVector{};
			SET_V8(contextVector, VLOAD((uint32_t(renderContext) + 1680u) & ~0xFu));
			VSTORE((stack + 96) & ~0xFu, V8(contextVector));
			ctx.r1.u64 = stack;
			renderParams = n_sub_82295E50(ctx, base, renderViewPass->m_14, stack + 96);
			CRenderViewPass_ExecuteRender(ctx, base, renderViewPassAddr, renderContext, renderParams);
			n_sub_821D3928(ctx, base, uint32_t(renderViewPassAddr) + 208, renderContext);
			n_sub_821C4FB8(ctx, base, renderContext);
			uint32_t subPassSlot = uint32_t(renderViewPassAddr) + 256;
			for (uint64_t index = 0; uint32_t(index) < 4; ++index, subPassSlot += 4) {
				const uint32_t renderData = LOAD32(LOAD32(uint32_t(renderContext) + 4) + 20) + 16;
				Entity_UpdateRenderData(ctx, base, LOAD32(subPassSlot), renderData, index);
			}
		}
		ctx.r1.u64 = stack;
		CRenderViewPass_RenderEntities(ctx, base, renderViewPassAddr, renderContext, renderParams);
	}
	const uint64_t result = RenderPool_CleanupAll(ctx, base, stack + 80);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(10, sub_8228EBA8, 0x8228EBA8) { ctx.r3.u64 = CRenderViewPass_RenderView(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CRenderViewPass_ExecuteRender(CpuState& ctx, uint8_t* base, uint64_t renderViewPass, uint64_t renderContext, uint32_t renderParams) {
	if (!UseLiftedCode(11, 0x8229B1E0)) { ctx.r3.u64 = renderViewPass; ctx.r4.u64 = renderContext; ctx.r5.u64 = renderParams; __imp__sub_8229B1E0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8229B1E0);
	// The two render pools (RenderPool_Pop, RenderPool_CleanupAll): 1024 entries of 8 bytes, a bit word (+8192)
	// and the entry count (+8196) each; they are also the log pages of the state block's records (value +4,
	// mask +8, queued byte +20, log page number (from 1) +21).
	constexpr uint32_t firstRenderPool = 0x834B8090u;
	constexpr uint32_t secondRenderPool = firstRenderPool + 8200;
	constexpr uint32_t pushedEntryValue = 0x834BDB70u;
	constexpr uint32_t stateBlock = 0x834C0000u - 16224;
	constexpr uint32_t changeQueue = 0x83490BF0u;
	constexpr uint32_t changeQueueCountAddress = 0x83390000u + 1000;
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Push an entry and a 0 bit on both pools; the record at stack + 80 has RenderPool_CleanupAll pop them.
	const uint32_t firstCount = LOAD32(firstRenderPool + 8196);
	STORE8(stack + 80, 1);
	STORE32(firstRenderPool + (firstCount << 3), pushedEntryValue);
	const uint32_t secondEntryOffset = LOAD32(secondRenderPool + 8196) << 3;
	const uint32_t firstCountNow = LOAD32(firstRenderPool + 8196);
	const uint32_t firstBits = LOAD32(firstRenderPool + 8192);
	STORE32(firstRenderPool + 8196, firstCountNow + 1);
	STORE32(firstRenderPool + 8192, firstBits << 1);
	STORE32(secondRenderPool + secondEntryOffset, pushedEntryValue);

	// State record +48 goes to 0: when it changes, its old value goes into its log page (unless the record's mask
	// already has bits of the page's mask) and the record into the change queue once.
	const uint32_t record = stateBlock + 48;
	const uint32_t secondBits = LOAD32(secondRenderPool + 8192);
	const uint32_t oldValue = LOAD32(record + 4);
	const uint32_t secondCount = LOAD32(secondRenderPool + 8196);
	const uint32_t logPage = LOAD8(record + 21) * 8200u + firstRenderPool - 8200u;
	STORE32(secondRenderPool + 8196, secondCount + 1);
	STORE32(secondRenderPool + 8192, secondBits << 1);
	if (oldValue != 0) {
		const uint32_t pageMask = LOAD32(logPage + 8192);
		const uint32_t recordMask = LOAD32(record + 8);
		if ((pageMask & recordMask) == 0) {
			const uint32_t entryOffset = LOAD32(logPage + 8196) << 3;
			STORE32(record + 8, pageMask | recordMask);
			STORE32(logPage + entryOffset, record);
			STORE32(logPage + (LOAD32(logPage + 8196) << 3) + 4, LOAD32(record + 4));
			STORE32(logPage + 8196, LOAD32(logPage + 8196) + 1);
		}
		const uint8_t queued = LOAD8(record + 20);
		STORE32(record + 4, 0);
		if (queued == 0) {
			STORE8(record + 20, 1);
			const uint32_t queueCount = LOAD32(changeQueueCountAddress);
			STORE32(changeQueueCountAddress, queueCount + 1);
			STORE32(changeQueue + (queueCount << 2), record);
		}
	}

	ctx.r1.u64 = stack;
	n_sub_82B16690(ctx, base, uint32_t(renderContext));
	Graphics_SetRenderState132(ctx, base, 132);
	Graphics_SetRenderState133(ctx, base, 133);
	CRenderViewPass_Render(ctx, base, renderViewPass, uint32_t(renderContext), renderParams);
	CRenderViewPass_RenderDebugGeometry(ctx, base, renderContext);
	const uint32_t result = RenderPool_CleanupAll(ctx, base, stack + 80);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(11, sub_8229B1E0, 0x8229B1E0) { ctx.r3.u64 = CRenderViewPass_ExecuteRender(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CRenderViewPass_RenderSubPasses(CpuState& ctx, uint8_t* base, uint32_t renderViewPass, uint64_t renderContext) {
	if (!UseLiftedCode(11, 0x822A0AC0)) { ctx.r3.u64 = renderViewPass; ctx.r4.u64 = renderContext; __imp__sub_822A0AC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822A0AC0);
	// The two render pools (RenderPool_Pop, RenderPool_CleanupAll): 1024 entries of 8 bytes, a bit word (+8192)
	// and the entry count (+8196) each.
	constexpr uint32_t firstRenderPool = 0x834B8090u;
	constexpr uint32_t secondRenderPool = firstRenderPool + 8200;
	constexpr uint32_t pushedEntryValue = 0x834BDB70u;
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Push an entry and a 0 bit on both pools; the record at stack + 80 has RenderPool_CleanupAll pop them.
	const uint64_t firstEntryOffset = LOAD32(firstRenderPool + 8196) << 3;
	STORE8(stack + 80, 1);
	STORE32(firstRenderPool + uint32_t(firstEntryOffset), pushedEntryValue);
	const uint32_t firstBits = LOAD32(firstRenderPool + 8192);
	const uint32_t secondEntryOffset = LOAD32(secondRenderPool + 8196) << 3;
	STORE32(firstRenderPool + 8196, LOAD32(firstRenderPool + 8196) + 1);
	STORE32(firstRenderPool + 8192, firstBits << 1);
	STORE32(secondRenderPool + secondEntryOffset, pushedEntryValue);
	const uint32_t secondCount = LOAD32(secondRenderPool + 8196);
	const uint32_t secondBits = LOAD32(secondRenderPool + 8192);
	STORE32(secondRenderPool + 8192, secondBits << 1);
	STORE32(secondRenderPool + 8196, secondCount + 1);

	// When the context's word +1788 is 2, the members at +144 and +208 render.
	if (LOAD32(uint32_t(renderContext) + 1788) == 2) {
		ctx.r1.u64 = stack;
		n_sub_8227DBA0(ctx, base, renderViewPass + 144, renderContext);
		n_sub_821D5478(ctx, base, renderViewPass + 208, renderContext);
	} else {
		// (the original hands the first pool's entry offset back in r4; RenderPool_CleanupAll leaves it there when
		// nothing was logged)
		ctx.r4.u64 = firstEntryOffset;
	}
	ctx.r1.u64 = stack;
	const uint64_t result = RenderPool_CleanupAll(ctx, base, stack + 80);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(11, sub_822A0AC0, 0x822A0AC0) { ctx.r3.u64 = CRenderViewPass_RenderSubPasses(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CRenderViewPass_HandleMessage(CpuState& ctx, uint8_t* base, uint32_t renderViewPassAddr, uint64_t message) {
	if (!UseLiftedCode(12, 0x822BCEB0)) { ctx.r3.u64 = renderViewPassAddr; ctx.r4.u64 = message; __imp__sub_822BCEB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822BCEB0);
	CRenderViewPass* renderViewPass = GameObject<CRenderViewPass>(base, renderViewPassAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	// Method 1 of the message returns its type id; a type-29 message carries two vectors (+16, +32), copied to
	// the pass's blocks at +96 and +112 and again at +160 and +208, and the value (+48) kept in m_MessageValue.
	const uint32_t vtable = LOAD32(uint32_t(message));
	const uint32_t method = LOAD32(vtable + 4);
	ctx.r3.u64 = message;
	ctx.r4.u64 = message;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	const uint64_t messageType = ctx.r3.u64;
	if (int32_t(messageType) == 29) {
		const uint32_t firstVector = uint32_t(message) + 16;
		const uint32_t secondVector = uint32_t(message) + 32;
		PPCVRegister block{};
		SET_V8(block, VLOAD(firstVector & ~0xF));
		VSTORE((renderViewPassAddr + 96u) & ~0xF, V8(block));
		SET_V8(block, VLOAD(secondVector & ~0xF));
		VSTORE((renderViewPassAddr + 112u) & ~0xF, V8(block));
		SET_V8(block, VLOAD(firstVector & ~0xF));
		VSTORE((renderViewPassAddr + 160u) & ~0xF, V8(block));
		SET_V8(block, VLOAD(secondVector & ~0xF));
		VSTORE((renderViewPassAddr + 208u) & ~0xF, V8(block));
		renderViewPass->m_MessageValue = LOAD32(uint32_t(message) + 48);
	}
	return messageType;
}
PROMOTED_ENTRY(12, sub_822BCEB0, 0x822BCEB0) { ctx.r3.u64 = CRenderViewPass_HandleMessage(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CRenderViewPass_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t renderViewPassAddr, uint64_t deleteFlags, uint64_t forwardedValue) {
	if (!UseLiftedCode(75, 0x82A5FA08)) { ctx.r3.u64 = renderViewPassAddr; ctx.r4.u64 = deleteFlags; ctx.r8.u64 = forwardedValue; __imp__sub_82A5FA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A5FA08);
	GameStackFrame stackFrame(ctx, base, 112);

	ctx.r4.u64 = deleteFlags;   // (the destructor hands it on)
	CRenderViewPass_Destructor(ctx, base, renderViewPassAddr, forwardedValue);
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, renderViewPassAddr);
	}
	return renderViewPassAddr;
}
PROMOTED_ENTRY(75, sub_82A5FA08, 0x82A5FA08) { ctx.r3.u64 = CRenderViewPass_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint32_t CRenderViewPass_Destructor(CpuState& ctx, uint8_t* base, uint64_t renderViewPassAddr, uint64_t forwardedValue) {
	if (!UseLiftedCode(75, 0x82A5FA58)) { ctx.r3.u64 = renderViewPassAddr; ctx.r8.u64 = forwardedValue; __imp__sub_82A5FA58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A5FA58);
	constexpr int32_t CRenderViewPass_vtable = int32_t(0x820052E8);
	CRenderViewPass* renderViewPass = GameObject<CRenderViewPass>(base, renderViewPassAddr);
	// (the original writes r13 into the machine state to keep interrupts off around each reference-count decrement)
	const uint32_t interruptsOffState = ctx.r13.u32;
	GameStackFrame stackFrame(ctx, base, 112);

	// What the original leaves in r9 and r10 for the member destructors, which hand both on: r9 as it came or as
	// the last call left it, or the address of the last reference count decremented; r10 the vtable address, what
	// the last call left, or the machine state saved around the last decrement.
	uint64_t handedOnAddress = ctx.r9.u64;
	uint64_t handedOnState = uint64_t(int64_t(CRenderViewPass_vtable));
	renderViewPass->vtable = uint32_t(CRenderViewPass_vtable);

	// The four sub-passes (+256) are destroyed and freed.
	uint32_t subPassSlot = uint32_t(renderViewPassAddr) + 256;
	for (int i = 0; i < 4; ++i, subPassSlot += 4) {
		const uint32_t subPass = LOAD32(subPassSlot);
		if (subPass != 0) {
			ctx.r4.u64 = 1;   // (delete flags)
			ctx.r8.u64 = forwardedValue;
			CRenderViewPass_SubObject_Destruct(ctx, base, subPass);
			forwardedValue = ctx.r8.u64;
			handedOnAddress = ctx.r9.u64;
			handedOnState = ctx.r10.u64;
		}
	}

	// One reference of a reference-counted object (count at +4) released atomically; method 1 of the object runs
	// when the count reaches 0.
	auto releaseReference = [&](uint32_t object) {
		const uint32_t refCountAddress = object + 4;
		int32_t remaining;
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			handedOnState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = interruptsOffState & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			const uint32_t rawCount = *(uint32_t*)RAW(refCountAddress);
			remaining = (int32_t)__builtin_bswap32(rawCount) - 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddress)), rawCount, __builtin_bswap32(uint32_t(remaining)));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)handedOnState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		handedOnAddress = uint64_t(object) + 4;
		if (remaining == 0) {
			const uint32_t vtable = LOAD32(object);
			const uint32_t method = LOAD32(vtable + 4);
			ctx.r3.u64 = object;
			ctx.r8.u64 = forwardedValue;
			ctx.r9.u64 = handedOnAddress;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
			forwardedValue = ctx.r8.u64;
			handedOnAddress = ctx.r9.u64;
			handedOnState = ctx.r10.u64;
		}
	};

	const uint32_t member114 = renderViewPass->m_114;
	if (member114 != 0) {
		releaseReference(member114);
		renderViewPass->m_114 = 0;
	}
	const uint32_t member110 = renderViewPass->m_110;
	if (member110 != 0) {
		releaseReference(member110);
		renderViewPass->m_110 = 0;
	}

	ctx.r9.u64 = handedOnAddress;
	ctx.r10.u64 = handedOnState;
	CRenderViewPass_MemberD0_Destructor(ctx, base, uint32_t(renderViewPassAddr) + 208, forwardedValue);
	forwardedValue = ctx.r8.u64;
	CRenderViewPass_Member90_Destructor(ctx, base, uint32_t(renderViewPassAddr) + 144, forwardedValue);
	return C_820F63C8_Destructor(ctx, base, renderViewPassAddr);
}
PROMOTED_ENTRY(75, sub_82A5FA58, 0x82A5FA58) { ctx.r3.u64 = CRenderViewPass_Destructor(ctx, base, ctx.r3.u64, ctx.r8.u64); }
