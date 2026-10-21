// CECPhysicsSimulationKeyframed (vtable 0x82007110): methods of the class as readable C++.
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

uint64_t CECPhysicsSimulationKeyframed_Update(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr, uint64_t arg2, double deltaTime) {
	constexpr int32_t g_82000F94 = int32_t(0x82000F94);
	if (!UseLiftedCode(5, 0x821FC858)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; ctx.r4.u64 = arg2; ctx.f1.f64 = deltaTime; __imp__sub_821FC858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821FC858);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);
	stack = PushStackFrame(base, stack, 128);

	// The virtual at vtable offset 92 is called twice: its result is first tested
	// for null, then fetched again and used as an object.
	uint32_t getInnerFn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 92);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationKeyframedAddr;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = getInnerFn;
	ctx.f1.f64 = deltaTime;
	REX_CALL_INDIRECT_FUNC(getInnerFn);

	if (ctx.r3.u32 != 0) {
		uint32_t getInnerAgainFn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 92);
		ctx.r3.u64 = physicsSimulationKeyframedAddr;
		ctx.r10.u64 = getInnerAgainFn;
		REX_CALL_INDIRECT_FUNC(getInnerAgainFn);
		uint32_t innerObject = ctx.r3.u32;

		uint32_t innerVtable = LOAD32(innerObject);
		ctx.fpscr.disableFlushMode();
		uint32_t method48 = LOAD32(innerVtable + 48);
		ctx.r4.u64 = arg2;
		ctx.r8.u64 = method48;
		ctx.r9.u64 = innerVtable;
		ctx.f1.f64 = deltaTime;
		REX_CALL_INDIRECT_FUNC(method48);
	}

	// A temporary C_82000F94 object {vtable, m_4 = 0} on the stack goes to sub_82202E90.
	uint32_t entity = physicsSimulationKeyframed->m_4;
	uint64_t tempObjectVtable = g_82000F94;
	STORE8(stack + 84, uint8_t(0));
	STORE32(stack + 80, (uint32_t)tempObjectVtable);
	// state the callee may pass on
	ctx.r9.u64 = tempObjectVtable;
	uint64_t result = Entity_NotifyEvent(ctx, base, entity, (uint64_t)stack + 80);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(5, sub_821FC858, 0x821FC858) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_Update(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.f1.f64); }

uint64_t CECPhysicsSimulationKeyframed_GetPosition(CpuState& ctx, uint8_t* base, uint64_t positionOut, uint64_t self) {
	if (!UseLiftedCode(5, 0x8220BA78)) { ctx.r3.u64 = positionOut; ctx.r4.u64 = self; __imp__sub_8220BA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8220BA78);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister shuffledValue{};
	PPCVRegister splatted{};
	PPCVRegister channelMask{};
	PPCVRegister outputValue{};
	stack = PushStackFrame(base, stack, 112);

	uint32_t sourceSimulation = LOAD32((uint32_t)self + 0x20);
	if (sourceSimulation != 0) {
		uint32_t getPositionFn = LOAD32(LOAD32(sourceSimulation) + 0x10);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = positionOut;
		ctx.r4.u64 = sourceSimulation;
		ctx.r10.u64 = getPositionFn;
		REX_CALL_INDIRECT_FUNC(getPositionFn);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return positionOut;
	}

	// No source simulation: splat the float constant at 0x820994C0 to all four lanes
	// and mask the result with the vector at 0x820991C0.
	ctx.fpscr.disableFlushMode();
	uint32_t defaultValueSlot = stack + 80;
	STORE_F32(defaultValueSlot, float(double(LOAD_F32(0x820994C0u))));
	SET_V8(shuffledValue, simde_mm_shuffle_epi8(
		simde_mm_load_si128((simde__m128i*)RAW(defaultValueSlot & ~0xF)),
		simde_mm_load_si128((simde__m128i*)&VectorMaskL[(defaultValueSlot & 0xF) * 16])));
	SET_V8(splatted, simde_mm_shuffle_epi32(V8(shuffledValue), 0xFF));
	SET_V8(channelMask, VLOAD(0x820991C0u & ~0xF));
	SET_V8(outputValue, simde_mm_and_si128(V8(splatted), V8(channelMask)));
	VSTORE((uint32_t)positionOut & ~0xF, V8(outputValue));

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call (0 here: the empty source pointer)
	ctx.r4.u64 = sourceSimulation;
	return positionOut;
}
PROMOTED_ENTRY(5, sub_8220BA78, 0x8220BA78) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_GetPosition(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECPhysicsSimulationKeyframed_SetPosition(CpuState& ctx, uint8_t* base, uint64_t vectorOut, uint64_t self) {
	if (!UseLiftedCode(5, 0x8220DEE8)) { ctx.r3.u64 = vectorOut; ctx.r4.u64 = self; __imp__sub_8220DEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8220DEE8);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister zeroVector{};
	stack = PushStackFrame(base, stack, 96);

	// With a source object at +0x20, its virtual at offset 12 fills vectorOut;
	// otherwise vectorOut is zeroed.
	uint32_t source = LOAD32((uint32_t)self + 0x20);
	if (source != 0) {
		uint32_t sourceVectorFn = LOAD32(LOAD32(source) + 12);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = vectorOut;
		ctx.r4.u64 = source;
		ctx.r10.u64 = sourceVectorFn;
		REX_CALL_INDIRECT_FUNC(sourceVectorFn);
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return vectorOut;
	}

	SET_V8(zeroVector, simde_mm_set1_epi32(int(0x0)));
	VSTORE((uint32_t)vectorOut & ~0xF, V8(zeroVector));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r4 after the call (0 here: the empty source pointer)
	ctx.r4.u64 = source;
	return vectorOut;
}
PROMOTED_ENTRY(5, sub_8220DEE8, 0x8220DEE8) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_SetPosition(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Forwards to the virtual at vtable offset 52 of the object at +32.
uint64_t n_sub_82241468(CpuState& ctx, uint8_t* base, uint64_t self) {
	if (!UseLiftedCode(7, 0x82241468)) { ctx.r3.u64 = self; __imp__sub_82241468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82241468);
	uint32_t source = LOAD32((uint32_t)self + 32);
	uint32_t sourceMethod = LOAD32(LOAD32(source) + 52);
	ctx.r3.u64 = source;
	ctx.r10.u64 = sourceMethod;
	REX_CALL_INDIRECT_FUNC(sourceMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(7, sub_82241468, 0x82241468) { ctx.r3.u64 = n_sub_82241468(ctx, base, ctx.r3.u64); }

uint64_t CECPhysicsSimulationKeyframed_ToggleEntityHandle(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr, uint64_t entityHandle, uint64_t mode) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(11, 0x822A8A10)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; ctx.r4.u64 = entityHandle; ctx.r5.u64 = mode; __imp__sub_822A8A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822A8A10);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);
	stack = PushStackFrame(base, stack, 144);

	// Get the entity handle object for this entity (virtual call, vtable slot 92).
	uint32_t findHandleFn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 92);
	callTarget.u64 = (uint64_t)findHandleFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationKeyframedAddr;
	ctx.r4.u64 = entityHandle;
	ctx.r5.u64 = mode;
	ctx.r10.u64 = findHandleFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint64_t result = ctx.r3.u64;
	uint64_t handleObj = result;
	if ((uint32_t)handleObj != 0) {
		CECPhysicsSimulationKeyframed_CleanupEntityHandles(ctx, base, physicsSimulationKeyframedAddr);
		uint32_t handleObjVtable = LOAD32((uint32_t)handleObj);
		uint64_t handleBuf = (int64_t)(uint64_t)stack + 80;

		if ((uint32_t(mode) & 0xFF) != 0) {
			// Virtual call (vtable slot 80), then remove the handle from the list and release it.
			uint32_t slot80Fn = LOAD32(handleObjVtable + 80);
			callTarget.u64 = (uint64_t)slot80Fn;
			ctx.r3.u64 = handleObj;
			ctx.r4.u64 = entityHandle;
			ctx.r10.u64 = slot80Fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint64_t handleVtable = (int64_t)g_820F0000 + 5732;
			uint32_t zero = 0;
			STORE32(stack + 84, zero);
			STORE32(stack + 80, (uint32_t)handleVtable);
			ctx.r7.u64 = handleVtable;
			ctx.r8.u64 = zero;
			EntityHandle_SetTarget(ctx, base, handleBuf, entityHandle);
			EntityHandleList_Remove_822A8BC8(ctx, base, (int64_t)physicsSimulationKeyframedAddr + 56, handleBuf);

			uint32_t vtableBase = (uint32_t)g_820F0000;
			uint32_t releaseVtable = (int32_t)vtableBase + 5732;
			STORE32(stack + 80, releaseVtable);
			uint64_t released = EntityHandle_Release(ctx, base, handleBuf);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return released;
		}

		// Virtual call (vtable slot 76) that drops the list entries owned by this handle.
		uint32_t slot76Fn = LOAD32(handleObjVtable + 76);
		callTarget.u64 = (uint64_t)slot76Fn;
		ctx.r3.u64 = handleObj;
		ctx.r4.u64 = entityHandle;
		ctx.r10.u64 = slot76Fn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;

		uint32_t listEnd = physicsSimulationKeyframed->m_3C;
		uint32_t listHead = (int64_t)physicsSimulationKeyframedAddr + 56;
		uint32_t foundEnd = listEnd;
		uint32_t loopEnd = listEnd;
		uint32_t currentNode = LOAD32(listEnd);

		// Two iterators {container, node} kept in the stack scratch slot.
		STORE32(stack + 80, listHead);
		STORE32(stack + 84, currentNode);
		STORE32(stack + 88, listHead);
		STORE32(stack + 92, currentNode);
		uint64_t iterA = LOAD64(stack + 80);
		uint64_t iterB = LOAD64(stack + 88);
		STORE64(stack + 88, iterB);
		STORE64(stack + 80, iterA);

		while (currentNode != loopEnd) {
			uint32_t nodeRef = LOAD32(currentNode + 12);
			uint64_t nodeHandle = (uint64_t)currentNode + 8;
			uint32_t matchedId = 0;
			if (nodeRef != 0) {
				uint32_t refId = LOAD32(nodeRef);
				if (refId != 0) {
					matchedId = refId;
				} else {
					result = EntityHandle_Release(ctx, base, nodeHandle);
					iterA = ctx.r7.u64;
					iterB = ctx.r8.u64;
					listEnd = ctx.r9.u32;
				}
			}
			if (matchedId == (uint32_t)entityHandle) break;
			currentNode = LOAD32(currentNode);
		}

		if (listHead != LOAD32(stack + 88)) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t iterHead = LOAD32(stack + 80);
		if (iterHead == 0 || iterHead != listHead) {
			ppc_trap(ctx, base, 22);
		}

		// Entity was not in the list yet: insert a new handle node for it.
		if (currentNode == foundEnd) {
			uint64_t handleVtable = g_820F1664;
			uint32_t zero = 0;
			STORE32(stack + 84, zero);
			STORE32(stack + 80, (uint32_t)handleVtable);
			ctx.r7.u64 = iterA;
			ctx.r8.u64 = iterB;
			ctx.r9.u64 = handleVtable;
			ctx.r10.u64 = zero;
			EntityHandle_SetTarget(ctx, base, handleBuf, entityHandle);

			uint32_t listHeadNext = LOAD32(listHead + 4);
			STORE32(stack + 88, listHead);
			STORE32(stack + 92, listHeadNext);
			uint64_t node = LOAD64(stack + 88);
			ctx.r8.u64 = listHeadNext;
			List_InsertNodeWithCopyConstruct(ctx, base, listHead, node, handleBuf);

			uint32_t vtableBase = (uint32_t)g_820F0000;
			uint32_t releaseVtable = (int32_t)vtableBase + 5732;
			STORE32(stack + 80, releaseVtable);
			result = EntityHandle_Release(ctx, base, handleBuf);
		}
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(11, sub_822A8A10, 0x822A8A10) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_ToggleEntityHandle(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_822A8CA0(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr) {
	if (!UseLiftedCode(11, 0x822A8CA0)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; __imp__sub_822A8CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822A8CA0);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister incomingV1 = ctx.v1;
	PPCVRegister callerV127 = ctx.v127;
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);

	// The caller's v127 is spilled below the frame; the original then keeps the
	// incoming v1 in v127 and hands it back in v1 to the calls below.
	VSTORE((stack + 0xFFFFFFE0u) & ~0xF, V8(callerV127));
	stack = PushStackFrame(base, stack, 112);

	// The virtual at vtable offset 92 is called twice: its result is first tested
	// for null, then fetched again and used as an object.
	uint32_t getInnerFn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 92);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationKeyframedAddr;
	ctx.r10.u64 = getInnerFn;
	REX_CALL_INDIRECT_FUNC(getInnerFn);

	if (ctx.r3.u32 != 0) {
		uint32_t getInnerAgainFn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 92);
		ctx.r3.u64 = physicsSimulationKeyframedAddr;
		ctx.r10.u64 = getInnerAgainFn;
		REX_CALL_INDIRECT_FUNC(getInnerAgainFn);

		uint32_t innerObject = ctx.r3.u32;
		uint32_t innerVtable = LOAD32(innerObject);
		uint32_t method28 = LOAD32(innerVtable + 28);
		ctx.r8.u64 = method28;
		ctx.r9.u64 = innerVtable;
		ctx.v1 = incomingV1;
		REX_CALL_INDIRECT_FUNC(method28);
	}

	ctx.v1 = incomingV1;
	uint64_t result = CECPhysicsSimpleLight_Enable(ctx, base, physicsSimulationKeyframedAddr);

	stack = PopStackFrame(stack, 112);
	// callers read r0 after the call (the original's offset of the v127 spill slot)
	ctx.r0.u64 = 0xFFFFFFE0;
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(11, sub_822A8CA0, 0x822A8CA0) { ctx.r3.u64 = n_sub_822A8CA0(ctx, base, ctx.r3.u64); }

// sub_822CAAF0  [248 bytes]
uint32_t CECPhysicsSimulationKeyframed_CleanupEntityHandles(CpuState& ctx, uint8_t* base, uint64_t simulation) {
	if (!UseLiftedCode(12, 0x822CAAF0)) { ctx.r3.u64 = simulation; __imp__sub_822CAAF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822CAAF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// The handle list sits at +56; its word at +4 is the end node of the circular list.
	uint32_t initialEndNode = LOAD32((uint32_t)simulation + 60);
	uint64_t list = (int64_t)simulation + 56;
	uint32_t listAddr = (uint32_t)list;
	// Checked iterator {list, node} at stack + 80.
	uint32_t iterList = listAddr;
	STORE32(stack + 80, iterList);
	uint32_t node = LOAD32(initialEndNode);
	STORE32(stack + 84, node);
	uint32_t result = (uint32_t)simulation;

	for (;;) {
		uint32_t endNode = LOAD32(listAddr + 4);
		if (iterList == 0 || iterList != listAddr) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == endNode) break;
		if (iterList == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(iterList + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		// A node is kept only when its handle's entity has bit 0x40 set at +144.
		uint32_t controlBlock = LOAD32(node + 12);
		uint64_t nodeHandle = (uint64_t)node + 8;
		result = (uint32_t)nodeHandle;
		bool keepNode = false;
		if (controlBlock != 0) {
			uint32_t entity = LOAD32(controlBlock);
			if (entity == 0) {
				ctx.r1.u64 = stack;
				result = (uint32_t)EntityHandle_Release(ctx, base, nodeHandle);
			} else {
				keepNode = (LOAD8(entity + 144) & 0x40) != 0;
			}
		}

		if (keepNode) {
			if (node == LOAD32(iterList + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			node = LOAD32(node);
			STORE32(stack + 84, node);
			continue;
		}

		uint64_t iterator = LOAD64(stack + 80);
		ctx.r1.u64 = stack;
		result = (uint32_t)EntityHandleList_EraseNode(ctx, base, (int64_t)(uint64_t)stack + 88, list, iterator);
		STORE64(stack + 80, LOAD64(result));
		node = LOAD32(stack + 84);
		iterList = LOAD32(stack + 80);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(12, sub_822CAAF0, 0x822CAAF0) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_CleanupEntityHandles(ctx, base, ctx.r3.u64); }

// sub_826869E8  [20 bytes]
// Forwards to the virtual at vtable offset 40 of the object at +32.
uint64_t n_sub_826869E8(CpuState& ctx, uint8_t* base, uint64_t self) {
	if (!UseLiftedCode(43, 0x826869E8)) { ctx.r3.u64 = self; __imp__sub_826869E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826869E8);
	uint32_t source = LOAD32((uint32_t)self + 32);
	uint32_t sourceMethod = LOAD32(LOAD32(source) + 40);
	ctx.r3.u64 = source;
	ctx.r10.u64 = sourceMethod;
	REX_CALL_INDIRECT_FUNC(sourceMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(43, sub_826869E8, 0x826869E8) { ctx.r3.u64 = n_sub_826869E8(ctx, base, ctx.r3.u64); }

// Forwards to virtual slot 0x2C of the simulation object held in m_20 (tail call).
uint64_t n_sub_82686A00(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr) {
	if (!UseLiftedCode(43, 0x82686A00)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; __imp__sub_82686A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82686A00);
	uint32_t sourceSimulation = LOAD32((uint32_t)physicsSimulationKeyframedAddr + 0x20);
	uint32_t method = LOAD32(LOAD32(sourceSimulation) + 0x2C);
	ctx.r3.u64 = sourceSimulation;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(43, sub_82686A00, 0x82686A00) { ctx.r3.u64 = n_sub_82686A00(ctx, base, ctx.r3.u64); }

// Forwards to virtual slot 0x24 of the simulation object held in m_20, passing
// resultOut as the result buffer; returns resultOut.
uint64_t n_sub_82686A18(CpuState& ctx, uint8_t* base, uint64_t resultOut, uint64_t physicsSimulationKeyframedAddr) {
	if (!UseLiftedCode(43, 0x82686A18)) { ctx.r3.u64 = resultOut; ctx.r4.u64 = physicsSimulationKeyframedAddr; __imp__sub_82686A18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82686A18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t sourceSimulation = LOAD32((uint32_t)physicsSimulationKeyframedAddr + 0x20);
	uint32_t method = LOAD32(LOAD32(sourceSimulation) + 0x24);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = resultOut;
	ctx.r4.u64 = sourceSimulation;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return resultOut;
}
PROMOTED_ENTRY(43, sub_82686A18, 0x82686A18) { ctx.r3.u64 = n_sub_82686A18(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Reads two 16-byte values through virtual slots 64 and 68, runs n_sub_82686BB8,
// then passes the values back through virtual slots 100 and 104.
uint64_t n_sub_82686A58(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr) {
	if (!UseLiftedCode(43, 0x82686A58)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; __imp__sub_82686A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82686A58);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);

	stack = PushStackFrame(base, stack, 128);
	uint32_t vectorBuffer = stack + 96;
	uint32_t valueBuffer = stack + 80;

	uint32_t readVectorFn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 64);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = vectorBuffer;
	ctx.r4.u64 = physicsSimulationKeyframedAddr;
	ctx.r10.u64 = readVectorFn;
	REX_CALL_INDIRECT_FUNC(readVectorFn);

	uint32_t vtable = physicsSimulationKeyframed->vtable;
	uint32_t readValueFn = LOAD32(vtable + 68);
	ctx.r3.u64 = valueBuffer;
	ctx.r4.u64 = physicsSimulationKeyframedAddr;
	// state the callee may pass on
	ctx.r8.u64 = readValueFn;
	ctx.r9.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(readValueFn);

	n_sub_82686BB8(ctx, base, physicsSimulationKeyframedAddr);

	vtable = physicsSimulationKeyframed->vtable;
	PPCVRegister vectorValue{};
	SET_V8(vectorValue, VLOAD(vectorBuffer & ~0xF));
	uint32_t writeVectorFn = LOAD32(vtable + 100);
	ctx.r3.u64 = physicsSimulationKeyframedAddr;
	ctx.v1 = vectorValue;
	// state the callee may pass on
	ctx.r5.u64 = writeVectorFn;
	ctx.r6.u64 = vtable;
	ctx.r7.u64 = vectorBuffer;
	REX_CALL_INDIRECT_FUNC(writeVectorFn);

	// The 16-byte value goes over by value in r4 (first 8 bytes) and r5 (last 8 bytes).
	uint64_t valueFirstHalf = LOAD64(valueBuffer + 0);
	uint64_t valueSecondHalf = LOAD64(valueBuffer + 8);
	uint32_t writeValueFn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 104);
	ctx.r3.u64 = physicsSimulationKeyframedAddr;
	ctx.r4.u64 = valueFirstHalf;
	ctx.r5.u64 = valueSecondHalf;
	ctx.r10.u64 = writeValueFn;
	REX_CALL_INDIRECT_FUNC(writeValueFn);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(43, sub_82686A58, 0x82686A58) { ctx.r3.u64 = n_sub_82686A58(ctx, base, ctx.r3.u64); }

// Resolves every 8-byte key in the list held through the shared handle m_44 and
// hands each result whose byte +144 has bit 0x40 set to virtual slot 152; then
// releases the handle and clears m_44.
uint64_t CECPhysicsSimulationKeyframed_ResolveKeyList(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(43, 0x82687050)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; __imp__sub_82687050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687050);
	uint32_t stack = ctx.r1.u64;
	// r4 as it stands when SharedHandle_Release is called (handed over below)
	uint64_t r4AtRelease = ctx.r4.u64;
	PPCXERRegister flags = ctx.xer;
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t result = physicsSimulationKeyframedAddr;
	uint32_t keyList = physicsSimulationKeyframed->m_44;
	if (keyList != 0) {
		// keys lie between the list's begin (+4) and end (+8) pointers
		uint64_t byteSize = (uint64_t)LOAD32(keyList + 8) - (uint64_t)LOAD32(keyList + 4);
		flags.ca = (int32_t)byteSize < 0 & ((uint32_t)byteSize & 0x7) != 0;
		int32_t keyCount = (int32_t)byteSize >> 3;
		if (keyCount != 0) {
			uint32_t index = 0;
			uint64_t keyOffset = 0;
			do {
				uint64_t keyAddr = (uint64_t)LOAD32(keyList + 4) + keyOffset;
				uint32_t registryOwner = LOAD32(LOAD32(LOAD32((uint32_t)g_83490000 + 26912) + 12) + 88);
				uint32_t registrySlots = LOAD32(registryOwner + 4);
				uint32_t registry = LOAD32(registrySlots);
				// state the callee may pass on
				ctx.r1.u64 = stack;
				ctx.xer.ca = flags.ca;
				uint64_t found = EntityManager_LookupEntity(ctx, base, registry, keyAddr);
				r4AtRelease = found;
				if ((uint32_t)found != 0 && (LOAD8((uint32_t)found + 144) & 0x40) != 0) {
					uint32_t slot152Fn = LOAD32(uint32_t(physicsSimulationKeyframed->vtable) + 152);
					ctx.r3.u64 = physicsSimulationKeyframedAddr;
					ctx.r4.u64 = found;
					ctx.r5.u64 = 0;
					ctx.r10.u64 = slot152Fn;
					REX_CALL_INDIRECT_FUNC(slot152Fn);
					r4AtRelease = ctx.r4.u64;
				}
				keyList = physicsSimulationKeyframed->m_44;
				index++;
				keyOffset += 8;
				byteSize = (uint64_t)LOAD32(keyList + 8) - (uint64_t)LOAD32(keyList + 4);
				flags.ca = (int32_t)byteSize < 0 & ((uint32_t)byteSize & 0x7) != 0;
				keyCount = (int32_t)byteSize >> 3;
			} while (index < (uint32_t)keyCount);
		}
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = r4AtRelease;
		ctx.r7.u64 = (uint64_t)(int64_t)keyCount;
		ctx.r8.u64 = byteSize;
		ctx.xer.ca = flags.ca;
		result = SharedHandle_Release(ctx, base, physicsSimulationKeyframedAddr + 68);
		physicsSimulationKeyframed->m_44 = 0u;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82687050, 0x82687050) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_ResolveKeyList(ctx, base, ctx.r3.u64); }

uint64_t CECPhysicsSimulationKeyframed_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameResult) {
	constexpr int32_t str_TXT_820BC28C_B_ = int32_t(0x820BC28C);
	if (!UseLiftedCode(68, 0x82991A48)) { ctx.r3.u64 = classNameResult; __imp__sub_82991A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82991A48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameResult, str_TXT_820BC28C_B_, -1);
	return classNameResult;
}
PROMOTED_ENTRY(68, sub_82991A48, 0x82991A48) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_GetClassName(ctx, base, ctx.r3.u64); }

// Scalar deleting destructor (vtable slot 0): releases the owned handles and
// m_58, runs C_820B7540_Cleanup on the object, and frees the object itself when bit 0
// of deleteFlags is set.
uint64_t CECPhysicsSimulationKeyframed_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(68, 0x82991A88)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82991A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82991A88);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);
	stack = PushStackFrame(base, stack, 112);

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = deleteFlags;
	SharedHandle_Release(ctx, base, physicsSimulationKeyframedAddr + 96);
	List_ClearRefCountedHandleNodes(ctx, base, physicsSimulationKeyframedAddr + 84);

	uint32_t ownedAllocation = physicsSimulationKeyframed->m_58;
	HandleTarget_Free(ctx, base, ownedAllocation);
	physicsSimulationKeyframed->m_58 = 0u;

	C_820B7540_Cleanup(ctx, base, physicsSimulationKeyframedAddr);

	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, physicsSimulationKeyframedAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return physicsSimulationKeyframedAddr;
}
PROMOTED_ENTRY(68, sub_82991A88, 0x82991A88) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82991FC0(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr) {
	if (!UseLiftedCode(68, 0x82991FC0)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; __imp__sub_82991FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82991FC0);
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);
	physicsSimulationKeyframed->m_68 = 5u;
	return n_sub_82231A10(ctx, base, physicsSimulationKeyframedAddr);
}
PROMOTED_ENTRY(68, sub_82991FC0, 0x82991FC0) { ctx.r3.u64 = n_sub_82991FC0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82991FD0(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(68, 0x82991FD0)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82991FD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82991FD0);
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);
	physicsSimulationKeyframed->m_68 = 5u;
	return n_sub_821E53D0(ctx, base, physicsSimulationKeyframedAddr, arg2, arg3);
}
PROMOTED_ENTRY(68, sub_82991FD0, 0x82991FD0) { ctx.r3.u64 = n_sub_82991FD0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// Asks the object at +124 of the entity (virtual slot +92) for an entity; if that entity has a physics
// component, a nonzero flag pushes this simulation's handle target (m_60) onto the component's entity-handle
// list (sub_82702338), a zero flag passes it to sub_82702428 instead.
uint32_t CECPhysicsSimulationKeyframed_TogglePhysicsComponentHandle(CpuState& ctx, uint8_t* base, uint32_t physicsSimulationKeyframedAddr, uint64_t entityAddr, uint64_t addFlag) {
	if (!UseLiftedCode(68, 0x82991FE0)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; ctx.r4.u64 = entityAddr; ctx.r5.u64 = addFlag; __imp__sub_82991FE0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82991FE0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECPhysicsSimulationKeyframed* physicsSimulationKeyframed = GameObject<CECPhysicsSimulationKeyframed>(base, physicsSimulationKeyframedAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t memberObjectAddr = LOAD32((uint32_t)entityAddr + 124);
	bool addTarget = ((uint32_t)addFlag & 0xFF) != 0;
	uint32_t physicsComponentOut = stack + 80;
	STORE32(physicsComponentOut, 0u);

	uint32_t vtableAddr = LOAD32(memberObjectAddr);
	uint32_t virtualFnAddr = LOAD32(vtableAddr + 92);
	callTarget.u64 = virtualFnAddr;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = memberObjectAddr;
	ctx.r4.u64 = entityAddr;
	ctx.r5.u64 = addFlag;
	ctx.r9.u64 = virtualFnAddr;
	ctx.r10.u64 = vtableAddr;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t physicsOwnerAddr = ctx.r3.u64;

	uint64_t result = physicsOwnerAddr;
	if ((uint32_t)physicsOwnerAddr != 0) {
		result = Entity_GetPhysicsComponent(ctx, base, physicsOwnerAddr, physicsComponentOut);
		if (((uint32_t)result & 0xFF) != 0) {
			uint32_t physicsComponent = LOAD32(physicsComponentOut);
			uint32_t handleTarget = physicsSimulationKeyframed->m_60;
			if (addTarget) {
				result = PhysicsComponent_AddEntityHandle(ctx, base, physicsComponent, handleTarget);
			} else {
				result = PhysicsComponent_RemoveEntityHandle(ctx, base, physicsComponent, handleTarget);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(68, sub_82991FE0, 0x82991FE0) { ctx.r3.u64 = CECPhysicsSimulationKeyframed_TogglePhysicsComponentHandle(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

// sub_82992118  [4 bytes]
uint64_t n_sub_82992118(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationKeyframedAddr) {
	if (!UseLiftedCode(68, 0x82992118)) { ctx.r3.u64 = physicsSimulationKeyframedAddr; __imp__sub_82992118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82992118);
	return n_sub_82992070(ctx, base, physicsSimulationKeyframedAddr);
}
PROMOTED_ENTRY(68, sub_82992118, 0x82992118) { ctx.r3.u64 = n_sub_82992118(ctx, base, ctx.r3.u64); }
