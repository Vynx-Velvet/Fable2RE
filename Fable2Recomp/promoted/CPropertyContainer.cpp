// CPropertyContainer (vtable 0x820F19A4): methods of the class as readable C++.
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

// sub_82A12060  [80 bytes]
uint64_t CPropertyContainer_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(73, 0x82A12060)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82A12060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A12060);
	uint32_t stack = ctx.r1.u64;
	uint64_t object = arg1;
	uint32_t deleteFlags = arg2;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CPropertyContainer_Destruct(ctx, base, arg1);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(73, sub_82A12060, 0x82A12060) { ctx.r3.u64 = CPropertyContainer_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_83217AF0  [4 bytes]
void n_sub_83217AF0(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83217AF0)) { __imp__sub_83217AF0(ctx, base); return; }
	LiftedFrame frame(0x83217AF0);
}
PROMOTED_ENTRY(141, sub_83217AF0, 0x83217AF0) { n_sub_83217AF0(ctx, base); }

uint64_t n_sub_83217AF8(CpuState& ctx, uint8_t* base, uint64_t container) {
	if (!UseLiftedCode(141, 0x83217AF8)) { ctx.r3.u64 = container; __imp__sub_83217AF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83217AF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t header = LOAD32((uint32_t)container + 32);
	uint32_t endNode = (uint32_t)container + 28;
	STORE32(stack + 80, endNode);
	STORE32(stack + 84, LOAD32(header));
	STORE64(stack + 80, LOAD64(stack + 80));

	uint64_t iterator = (uint64_t)stack + 80;
	uint64_t result = container;
	for (;;) {
		uint32_t currentNode = LOAD32(stack + 80);
		if (currentNode == 0 || currentNode != endNode) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t headerTarget = LOAD32(stack + 84);
		if (headerTarget == header)
			break;
		if (currentNode == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (headerTarget == LOAD32(currentNode + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		result = iterator;
		ctx.r1.u64 = stack;
		StdMapIterator_Increment_Node17(ctx, base, iterator);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_83217AF8, 0x83217AF8) { ctx.r3.u64 = n_sub_83217AF8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_83217CC8(CpuState& ctx, uint8_t* base, uint64_t propertyContainerAddr, uint64_t objectAddr, uint64_t flags) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(141, 0x83217CC8)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = objectAddr; ctx.r5.u64 = flags; __imp__sub_83217CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83217CC8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);

	stack = PushStackFrame(base, stack, 128);
	const bool raiseEvents = (flags & 0xFF) != 0;
	const uint64_t source = objectAddr;
	uint64_t result = 1;

	if (raiseEvents) {
		uint32_t callbackManager = LOAD32(uint32_t(g_834A0000) - 6592);
		uint64_t eventId = (callbackManager == 0) ? uint64_t(g_8209003F) : uint64_t(LOAD32(callbackManager));
		uint32_t handler = LOAD32(LOAD32((uint32_t)source) + 4);
		callTarget.u64 = handler;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = source;
		ctx.r4.u64 = eventId;
		ctx.r5.u64 = flags;
		ctx.r10.u64 = handler;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		objectAddr = ctx.r4.u64;
		flags = ctx.r5.u64;
	}

	if ((uint32_t)result & 0xFF) {
		uint32_t tempValueAddr = stack + 80;
		STORE32(tempValueAddr, uint32_t(propertyContainer->m_4));
		ctx.r1.u64 = stack;
		ctx.r5.u64 = flags;
		n_sub_83217C28(ctx, base, source, tempValueAddr);

		uint32_t vtable = propertyContainer->vtable;
		uint32_t handler = LOAD32(vtable + 36);
		callTarget.u64 = handler;
		ctx.r3.u64 = propertyContainerAddr;
		ctx.r4.u64 = source;
		ctx.r9.u64 = handler;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		objectAddr = ctx.r4.u64;
		flags = ctx.r5.u64;
	}

	if (raiseEvents) {
		uint32_t handler = LOAD32(LOAD32((uint32_t)source) + 12);
		callTarget.u64 = handler;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = source;
		ctx.r4.u64 = objectAddr;
		ctx.r5.u64 = flags;
		ctx.r10.u64 = handler;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		objectAddr = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = objectAddr;
	return result;
}
PROMOTED_ENTRY(141, sub_83217CC8, 0x83217CC8) { ctx.r3.u64 = n_sub_83217CC8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_83217D80(CpuState& ctx, uint8_t* base, uint64_t propertyContainerAddr, uint64_t target, uint64_t arg3, uint64_t arg4, uint64_t flags) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(141, 0x83217D80)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = target; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = flags; __imp__sub_83217D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83217D80);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);

	stack = PushStackFrame(base, stack, 144);

	// The flag is latched up front: later reads of `flags` come from the callee registers.
	const uint32_t flagsByte = uint32_t(flags) & 0xFF;
	const uint64_t savedTarget = target;
	const uint64_t savedArg3 = arg3;
	const uint64_t savedArg4 = arg4;
	uint64_t result = 1;

	if (flagsByte != 0) {
		uint32_t typeRegistry = LOAD32(uint32_t(g_834A0000) - 6592);
		uint64_t typeDesc = (typeRegistry == 0) ? uint64_t(g_8209003F) : uint64_t(LOAD32(typeRegistry));
		uint32_t virtualFn = LOAD32(LOAD32(uint32_t(target)) + 4);
		callTarget.u64 = virtualFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = target;
		ctx.r4.u64 = typeDesc;
		ctx.r5.u64 = arg3;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = flags;
		ctx.r10.u64 = virtualFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		target = ctx.r4.u64;
		arg3 = ctx.r5.u64;
		arg4 = ctx.r6.u64;
		flags = ctx.r7.u64;
	}
	if ((uint32_t(result) & 0xFF) != 0) {
		const uint64_t stackBuffer = uint64_t(stack) + 80;
		ctx.r1.u64 = stack;
		ctx.r5.u64 = arg3;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = flags;
		n_sub_83217B90(ctx, base, savedTarget, stackBuffer);

		uint32_t virtualFn = LOAD32(uint32_t(propertyContainer->vtable) + 32);
		callTarget.u64 = virtualFn;
		ctx.r3.u64 = propertyContainerAddr;
		ctx.r4.u64 = savedTarget;
		ctx.r5.u64 = savedArg3;
		ctx.r6.u64 = savedArg4;
		ctx.r10.u64 = virtualFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		target = ctx.r4.u64;
		arg3 = ctx.r5.u64;
		arg4 = ctx.r6.u64;
		flags = ctx.r7.u64;
	}
	if (flagsByte != 0) {
		uint32_t virtualFn = LOAD32(LOAD32(uint32_t(savedTarget)) + 12);
		callTarget.u64 = virtualFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = savedTarget;
		ctx.r4.u64 = target;
		ctx.r5.u64 = arg3;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = flags;
		ctx.r10.u64 = virtualFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		target = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = target;
	return result;
}
PROMOTED_ENTRY(141, sub_83217D80, 0x83217D80) { ctx.r3.u64 = n_sub_83217D80(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

// sub_83217FA8  [364 bytes]
uint64_t CPropertyContainer_WriteBinary(CpuState& ctx, uint8_t* base, uint32_t propertyContainerAddr, uint64_t outStream) {
	if (!UseLiftedCode(141, 0x83217FA8)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = outStream; __imp__sub_83217FA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83217FA8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);

	stack = PushStackFrame(base, stack, 160);

	ctx.r1.u64 = stack;
	BinaryStream_WriteUInt32(ctx, base, outStream, 3);
	uint32_t entryCount = propertyContainer->m_entryCount;
	BinaryStream_WriteUInt32(ctx, base, outStream, entryCount);

	// r8/r9 holding slots the compiler kept live across the stream writes
	uint64_t carryR8 = ctx.r8.u64;
	uint64_t carryR9{};

	uint32_t entriesHead = propertyContainer->m_entriesHead;
	uint32_t sentinelNode = propertyContainerAddr + 12;

	// iterator over the entry map: {node owning the tree header, current entry node}
	STORE32(stack + 88, sentinelNode);
	STORE32(stack + 92, LOAD32(entriesHead));
	carryR9 = LOAD64(stack + 88);

	for (;;) {
		uint32_t iteratorOwner = LOAD32(stack + 88);
		if (iteratorOwner == 0 || iteratorOwner != sentinelNode) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t current = LOAD32(stack + 92);
		if (current == entriesHead) {
			break;
		}
		if (current == LOAD32(sentinelNode + 4)) {
			ppc_trap(ctx, base, 22);
		}

		// entry key
		bool swapBytes = LOAD8((uint32_t)outStream + 8) != 0;
		STORE32(stack + 80, LOAD32(current + 12));
		if (swapBytes) {
			uint8_t byte1 = LOAD8(stack + 81);
			carryR9 = LOAD8(stack + 83);
			carryR8 = LOAD8(stack + 82);
			STORE8(stack + 83, LOAD8(stack + 80));
			STORE8(stack + 82, byte1);
			STORE8(stack + 80, (uint8_t)carryR9);
			STORE8(stack + 81, (uint8_t)carryR8);
		}

		uint32_t keySize = 4;
		uint32_t keyAddr = stack + 80;
		uint32_t writeKey = LOAD32(LOAD32((uint32_t)outStream) + 16);
		callTarget.u64 = writeKey;
		ctx.r3.u64 = outStream;
		ctx.r4.u64 = keyAddr;
		ctx.r5.u64 = keySize;
		ctx.r8.u64 = carryR8;
		ctx.r9.u64 = carryR9;
		ctx.r10.u64 = writeKey;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// entry value
		uint32_t endSentinel = LOAD32(sentinelNode + 4);
		if (current == endSentinel) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t propertyValue = LOAD32(current + 16);
		uint32_t writeValue = LOAD32(LOAD32(propertyValue) + 12);
		callTarget.u64 = writeValue;
		ctx.r3.u64 = propertyValue;
		ctx.r4.u64 = outStream;
		ctx.r5.u64 = 0;
		ctx.r9.u64 = endSentinel;
		ctx.r10.u64 = writeValue;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		carryR8 = ctx.r8.u64;
		StdMapIterator_Increment_Node25(ctx, base, stack + 88);
		carryR9 = ctx.r9.u64;
	}

	// trailing field
	STORE32(stack + 80, (uint32_t)propertyContainer->m_4);
	if (LOAD8((uint32_t)outStream + 8) != 0) {
		uint8_t byte1 = LOAD8(stack + 81);
		carryR9 = LOAD8(stack + 83);
		carryR8 = LOAD8(stack + 82);
		STORE8(stack + 83, LOAD8(stack + 80));
		STORE8(stack + 82, byte1);
		STORE8(stack + 80, (uint8_t)carryR9);
		STORE8(stack + 81, (uint8_t)carryR8);
	}

	uint32_t trailerSize = 4;
	uint32_t trailerAddr = stack + 80;
	uint32_t writeTrailer = LOAD32(LOAD32((uint32_t)outStream) + 16);
	callTarget.u64 = writeTrailer;
	ctx.r3.u64 = outStream;
	ctx.r4.u64 = trailerAddr;
	ctx.r5.u64 = trailerSize;
	ctx.r8.u64 = carryR8;
	ctx.r9.u64 = carryR9;
	ctx.r10.u64 = writeTrailer;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(141, sub_83217FA8, 0x83217FA8) { ctx.r3.u64 = CPropertyContainer_WriteBinary(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPropertyContainer_Save(CpuState& ctx, uint8_t* base, uint32_t propertyContainerAddr, uint64_t saveStream) {
	if (!UseLiftedCode(141, 0x83218118)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = saveStream; __imp__sub_83218118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83218118);
	uint32_t stack = ctx.r1.u64;
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);

	stack = PushStackFrame(base, stack, 176);

	// A type descriptor is reached through a global pointer; while that global
	// is still unset the shared default descriptor stands in for it.
	constexpr uint32_t kDefaultDescriptor = 0x8209003F;
	constexpr uint32_t kDescriptorGlobalA = 0x8349E64C;
	constexpr uint32_t kDescriptorGlobalB = 0x8349E658;
	constexpr uint32_t kDescriptorGlobalN = 0x8349E650;
	constexpr uint32_t kDescriptorGlobalK = 0x8349E654;

	uint32_t streamVtable = LOAD32((uint32_t)saveStream);
	PPCRegister callTarget{};
	uint32_t holder = LOAD32(kDescriptorGlobalA);
	uint32_t descriptor = holder != 0 ? LOAD32(holder) : kDefaultDescriptor;
	uint32_t beginFn = LOAD32(streamVtable + 4);
	uint32_t endFn;

	callTarget.u64 = (uint64_t)beginFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = saveStream;
	ctx.r4.u64 = descriptor;
	ctx.r10.u64 = beginFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t saveRequested = ctx.r3.u32 & 0xFF;

	if (saveRequested != 0) {
		holder = LOAD32(kDescriptorGlobalB);
		descriptor = holder != 0 ? LOAD32(holder) : kDefaultDescriptor;

		beginFn = LOAD32(streamVtable + 4);
		callTarget.u64 = (uint64_t)beginFn;
		ctx.r3.u64 = saveStream;
		ctx.r4.u64 = descriptor;
		ctx.r9.u64 = saveRequested;
		ctx.r10.u64 = beginFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t flags = ctx.r3.u32 & 0xFF;

		if (flags != 0) {
			STORE32(stack + 80, 3u);
			holder = LOAD32(kDescriptorGlobalB);
			descriptor = holder != 0 ? LOAD32(holder) : kDefaultDescriptor;
			ctx.r4.u64 = descriptor;
			ctx.r9.u64 = flags;
			IStream_SerializeU32(ctx, base, saveStream, stack + 80);

			endFn = LOAD32(streamVtable + 12);
			callTarget.u64 = (uint64_t)endFn;
			ctx.r3.u64 = saveStream;
			ctx.r10.u64 = endFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			flags = ctx.r9.u64;
		}

		STORE32(stack + 84, propertyContainer->m_entryCount);
		holder = LOAD32(kDescriptorGlobalN);
		descriptor = holder != 0 ? LOAD32(holder) : kDefaultDescriptor;
		ctx.r4.u64 = descriptor;
		ctx.r9.u64 = flags;
		n_sub_82A08FC8(ctx, base, saveStream, stack + 84);

		// Walk the container's entry map from its leftmost node up to the
		// header node (_Myhead), which doubles as end().
		uint32_t mapAddress = propertyContainerAddr + 12;
		uint32_t mapHead = propertyContainer->m_entriesHead;
		STORE32(stack + 96, mapAddress);
		STORE32(stack + 100, LOAD32(mapHead));
		uint64_t iteratorValue = LOAD64(stack + 96);

		for (;;) {
			uint32_t iteratorOwner = LOAD32(stack + 96);
			if (iteratorOwner == 0 || iteratorOwner != mapAddress) {
				ppc_trap(ctx, base, 22);
			}
			uint32_t node = LOAD32(stack + 100);
			if (node == mapHead) {
				break;
			}
			if (iteratorOwner == 0) {
				ppc_trap(ctx, base, 22);
			}
			if (node == LOAD32(iteratorOwner + 4)) {
				ppc_trap(ctx, base, 22);
			}

			STORE32(stack + 88, LOAD32(node + 12));
			holder = LOAD32(kDescriptorGlobalK);
			descriptor = holder != 0 ? LOAD32(holder) : kDefaultDescriptor;
			ctx.r4.u64 = descriptor;
			ctx.r9.u64 = iteratorValue;
			n_sub_82A08FC8(ctx, base, saveStream, stack + 88);

			if (node == LOAD32(iteratorOwner + 4)) {
				ppc_trap(ctx, base, 22);
			}
			uint32_t element = LOAD32(node + 16);
			uint32_t saveFn = LOAD32(LOAD32(element) + 20);
			callTarget.u64 = (uint64_t)saveFn;
			ctx.r3.u64 = element;
			ctx.r4.u64 = saveStream;
			ctx.r5.u64 = 0;
			ctx.r10.u64 = saveFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			StdMapIterator_Increment_Node25(ctx, base, stack + 96);
			iteratorValue = ctx.r9.u64;
		}

		ctx.r5.u64 = 0;
		CRegistrableThing_SaveId(ctx, base, propertyContainerAddr, saveStream);

		endFn = LOAD32(streamVtable + 12);
		callTarget.u64 = (uint64_t)endFn;
		ctx.r3.u64 = saveStream;
		ctx.r10.u64 = endFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(141, sub_83218118, 0x83218118) { ctx.r3.u64 = CPropertyContainer_Save(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t n_sub_83218300(CpuState& ctx, uint8_t* base, uint64_t propertyContainerAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(141, 0x83218300)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_83218300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83218300);
	uint32_t stack = ctx.r1.u64;
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	n_sub_83217EC8(ctx, base, arg2, stack + 80);
	uint32_t vtable = propertyContainer->vtable;
	uint32_t functionPtr = LOAD32(vtable + 24);
	ctx.r3.u64 = propertyContainerAddr;
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r10.u64 = functionPtr;
	REX_CALL_INDIRECT_FUNC(functionPtr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(141, sub_83218300, 0x83218300) { ctx.r3.u64 = n_sub_83218300(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint32_t CPropertyContainer_Clear(CpuState& ctx, uint8_t* base, uint32_t propertyContainerAddr) {
	if (!UseLiftedCode(141, 0x83218350)) { ctx.r3.u64 = propertyContainerAddr; __imp__sub_83218350(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83218350);
	uint32_t stack = ctx.r1.u64;
	uint32_t mapHeader;
	uint32_t entryNode;
	uint32_t destroyResult;
	uint32_t rootNode;
	uint32_t rootNodeCopy;
	uint32_t rootNodeCopy2;
	uint32_t zero = 0;
	uint64_t iterator;
	uint32_t subtree;
	uint32_t currentNode;
	uint32_t nextNode;
	uint32_t entriesHead;
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);

	stack = PushStackFrame(base, stack, 128);
	mapHeader = propertyContainerAddr + 0xC;
	STORE32(stack + 88, mapHeader);
	entriesHead = propertyContainer->m_entriesHead;
	STORE32(stack + 92, LOAD32(entriesHead));
	iterator = LOAD64(stack + 88);
	STORE64(stack + 88, iterator);

	for (;;) {
		currentNode = LOAD32(stack + 88);
		if (currentNode == 0 || currentNode != mapHeader) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		nextNode = LOAD32(stack + 92);
		if (nextNode == entriesHead) break;

		if (currentNode == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (nextNode == LOAD32(currentNode + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		STORE32(stack + 80, propertyContainerAddr);
		nextNode = LOAD32(nextNode + 16);
		entryNode = nextNode + 4;
		ctx.r1.u64 = stack;
		ctx.r9.u64 = iterator;
		n_sub_82A14AE0(ctx, base, entryNode, stack + 80);
		StdMapIterator_Increment_Node25(ctx, base, stack + 88);
		iterator = ctx.r9.u64;
	}

	subtree = LOAD32(LOAD32(mapHeader + 4) + 4);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = iterator;
	destroyResult = StdMapSharedHandle_DestroySubtree(ctx, base, mapHeader, subtree);

	rootNode = LOAD32(mapHeader + 4);
	STORE32(rootNode + 4, rootNode);
	rootNodeCopy = LOAD32(mapHeader + 4);
	STORE32(mapHeader + 8, zero);
	STORE32(rootNodeCopy, rootNodeCopy);
	rootNodeCopy2 = LOAD32(mapHeader + 4);
	STORE32(rootNodeCopy2 + 8, rootNodeCopy2);
	propertyContainer->m_18 = zero;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = rootNodeCopy2;
	ctx.r9.u64 = rootNodeCopy;
	return destroyResult;
}
PROMOTED_ENTRY(141, sub_83218350, 0x83218350) { ctx.r3.u64 = CPropertyContainer_Clear(ctx, base, ctx.r3.u32); }

uint32_t n_sub_83218598(CpuState& ctx, uint8_t* base, uint64_t propertyContainerAddr, uint64_t sourceHandle) {
	if (!UseLiftedCode(141, 0x83218598)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = sourceHandle; __imp__sub_83218598(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83218598);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 144);

	// Take a copy of the shared handle held by the caller into a stack temporary.
	uint32_t sourceObject = LOAD32(sourceHandle);
	uint32_t cloneHandle = LOAD32(LOAD32(sourceObject) + 4);
	callTarget.u64 = (uint64_t)cloneHandle;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = sourceObject;
	ctx.r4.u64 = sourceHandle;
	ctx.r10.u64 = cloneHandle;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t tempHandle = ctx.r3.u32;
	STORE32(stack + 80, tempHandle);

	// Bind the copy to the property container's handle slot at offset 0xC.
	uint64_t handleSlot = n_sub_82A120B0(ctx, base, propertyContainerAddr + 12, stack + 80);
	uint32_t object = LOAD32(sourceHandle);
	uint32_t refCount = LOAD32(sourceHandle + 4);
	uint64_t previousRefCount = LOAD32((uint32_t)handleSlot + 4);
	if ((uint32_t)previousRefCount != refCount) {
		ctx.r9.u64 = previousRefCount;
		SharedHandle_Release(ctx, base, handleSlot);
		previousRefCount = ctx.r9.u64;
		STORE32((uint32_t)handleSlot, object);
		STORE32((uint32_t)handleSlot + 4, refCount);
		if (refCount != 0) {
			STORE32(refCount, LOAD32(refCount) + 1);
		}
	}

	// Tell the container's owner that its handle changed.
	uint32_t currentObject = LOAD32(sourceHandle);
	uint32_t notifyChange = LOAD32(LOAD32(currentObject) + 4);
	callTarget.u64 = (uint64_t)notifyChange;
	ctx.r3.u64 = currentObject;
	ctx.r9.u64 = previousRefCount;
	ctx.r10.u64 = notifyChange;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t changeResult = ctx.r3.u64;

	uint32_t flags = LOAD32(propertyContainerAddr + 0x18);
	uint64_t newFlags = changeResult | (uint64_t)flags;
	STORE32(propertyContainerAddr + 0x18, (uint32_t)newFlags);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = newFlags;
	ctx.r9.u64 = flags;
	return (uint32_t)changeResult;
}
PROMOTED_ENTRY(141, sub_83218598, 0x83218598) { ctx.r3.u64 = n_sub_83218598(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CPropertyContainer_Load(CpuState& ctx, uint8_t* base, uint64_t propertyContainerAddr, uint64_t loadStream) {
	if (!UseLiftedCode(141, 0x83218630)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = loadStream; __imp__sub_83218630(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83218630);

	// vtable pointers of the property classes this loader knows how to instantiate
	constexpr uint32_t kVtableType1 = 0x820F19CCu;
	constexpr uint32_t kVtableType64 = 0x820F1BE8u;
	constexpr uint32_t kVtableType128 = 0x820F1C18u;
	constexpr uint32_t kVtableType256 = 0x820F1C30u;
	constexpr uint32_t kVtableType512 = 0x820F1C48u;
	constexpr uint32_t kVtableType4096 = 0x820F19FCu;

	uint32_t stack = ctx.r1.u64;
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);
	stack = PushStackFrame(base, stack, 240);
	ctx.r1.u64 = stack;

	// stack + 80: entry count, stack + 84: type code of the current entry,
	// stack + 88: handle owning the property being loaded
	STORE32(stack + 80, propertyContainer->m_entryCount);

	uint32_t result = IStream_SerializeU32(ctx, base, loadStream, stack + 80);

	auto createTaggedProperty = [&](uint32_t size, uint32_t vtable, uint32_t typeTag) -> uint32_t {
		uint32_t property = operator_new(ctx, base, size);
		if (property == 0) {
			return 0;
		}
		C_820F1B88_Construct(ctx, base, property);
		STORE32(property, vtable);
		STORE32(property + 16, typeTag);
		return property;
	};

	for (int32_t i = 0; i < (int32_t)LOAD32(stack + 80); i++) {
		STORE32(stack + 88, 0);
		STORE32(stack + 92, 0);
		IStream_SerializeU32(ctx, base, loadStream, stack + 84);

		uint32_t propertyTypeCode = LOAD32(stack + 84);
		uint32_t property = 0;
		bool knownType = true;
		switch (propertyTypeCode) {
		case 1: {
			property = operator_new(ctx, base, 16);
			if (property != 0) {
				C_820F1B88_Construct(ctx, base, property);
				STORE32(property, kVtableType1);
			}
			break;
		}
		case 2: {
			property = operator_new(ctx, base, 20);
			if (property != 0) {
				property = n_sub_83215D98(ctx, base, property);
			}
			break;
		}
		case 4: {
			property = operator_new(ctx, base, 32);
			if (property != 0) {
				property = n_sub_83215BF0(ctx, base, property);
			}
			break;
		}
		case 16: {
			property = operator_new(ctx, base, 44);
			if (property != 0) {
				property = n_sub_83215D18(ctx, base, property);
			}
			break;
		}
		case 32: {
			property = operator_new(ctx, base, 24);
			if (property != 0) {
				property = n_sub_83215CB8(ctx, base, property);
			}
			break;
		}
		case 64:
			property = createTaggedProperty(20, kVtableType64, 4);
			break;
		case 128:
			property = createTaggedProperty(20, kVtableType128, 1);
			break;
		case 256:
			property = createTaggedProperty(20, kVtableType256, 5);
			break;
		case 512:
			property = createTaggedProperty(20, kVtableType512, 0);
			break;
		case 1024: {
			property = operator_new(ctx, base, 28);
			if (property != 0) {
				property = n_sub_83215A80(ctx, base, property);
			}
			break;
		}
		case 2048: {
			property = operator_new(ctx, base, 20);
			if (property != 0) {
				property = n_sub_83215A28(ctx, base, property);
			}
			break;
		}
		case 4096:
			property = createTaggedProperty(20, kVtableType4096, 1);
			break;
		default:
			knownType = false;
			break;
		}

		if (knownType) {
			SharedPtr_ResetWithPointerE(ctx, base, stack + 88, property);
		}

		// let the property read its own data from the stream
		uint32_t propertyObject = LOAD32(stack + 88);
		uint32_t propertyLoadFn = LOAD32(LOAD32(propertyObject) + 20);
		PPCRegister callTarget{};
		callTarget.u64 = propertyLoadFn;
		ctx.r3.u64 = propertyObject;
		ctx.r4.u64 = loadStream;
		ctx.r5.u64 = 0;
		ctx.r10.u64 = propertyLoadFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		n_sub_83218598(ctx, base, propertyContainerAddr, stack + 88);
		result = SharedHandle_Release(ctx, base, stack + 88);
	}

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_83218630, 0x83218630) { ctx.r3.u64 = CPropertyContainer_Load(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CPropertyContainer_Destruct(CpuState& ctx, uint8_t* base, uint64_t propertyContainerAddr) {
	if (!UseLiftedCode(141, 0x83218A40)) { ctx.r3.u64 = propertyContainerAddr; __imp__sub_83218A40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83218A40);
	uint32_t stack = ctx.r1.u64;
	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t entriesHeader = propertyContainerAddr + 12;
	uint32_t secondHeader = propertyContainerAddr + 28;

	propertyContainer->vtable = 0x820F19A4u;

	uint32_t entriesRoot = LOAD32(uint32_t(propertyContainer->m_entriesHead) + 4);
	ctx.r1.u64 = stack;
	StdMapSharedHandle_DestroySubtree(ctx, base, entriesHeader, entriesRoot);

	uint32_t entriesHead = propertyContainer->m_entriesHead;
	propertyContainer->m_entryCount = 0;
	STORE32(entriesHead + 4, entriesHead);
	STORE32(entriesHead, entriesHead);
	STORE32(entriesHead + 8, entriesHead);

	uint32_t secondRoot = LOAD32(uint32_t(propertyContainer->m_secondHead) + 4);
	PropertyMap_EraseSubtree(ctx, base, secondHeader, secondRoot);

	uint32_t secondHead = propertyContainer->m_secondHead;
	propertyContainer->m_secondCount = 0;
	STORE32(secondHead + 4, secondHead);
	STORE32(secondHead, secondHead);
	STORE32(secondHead + 8, secondHead);

	n_sub_8233DD70(ctx, base, secondHeader);
	uint32_t result = n_sub_82A12668(ctx, base, entriesHeader);

	propertyContainer->vtable = 0x820F1A5Cu;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_83218A40, 0x83218A40) { ctx.r3.u64 = CPropertyContainer_Destruct(ctx, base, ctx.r3.u64); }

uint64_t n_sub_83219DF8(CpuState& ctx, uint8_t* base, uint64_t propertyContainerAddr, uint64_t stream, uint64_t notifyFlag, uint64_t entityId) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(141, 0x83219DF8)) { ctx.r3.u64 = propertyContainerAddr; ctx.r4.u64 = stream; ctx.r5.u64 = notifyFlag; ctx.r6.u64 = entityId; __imp__sub_83219DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83219DF8);
	uint32_t stack = ctx.r1.u64;

	CPropertyContainer* propertyContainer = GameObject<CPropertyContainer>(base, propertyContainerAddr);
	uint32_t streamAddr = (uint32_t)stream;
	const uint32_t globalBase = uint32_t(g_834A0000);

	stack = PushStackFrame(base, stack, 144);
	const uint32_t versionAddr = stack + 80;

	// Whatever object the singleton pointer points at, else the built-in default.
	PPCRegister callTarget{};
	uint32_t singletonPtr = LOAD32(0x8349E64Cu);
	uint64_t singleton = g_8209003F;
	if (singletonPtr != 0) {
		singleton = LOAD32(singletonPtr);
	}

	uint32_t streamBeginRead = LOAD32(LOAD32(streamAddr) + 4);
	callTarget.u64 = streamBeginRead;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = stream;
	ctx.r4.u64 = singleton;
	ctx.r5.u64 = notifyFlag;
	ctx.r6.u64 = entityId;
	ctx.r10.u64 = streamBeginRead;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	if ((ctx.r3.u32 & 0xFF) != 0) {
		CPropertyContainer_Clear(ctx, base, propertyContainerAddr);

		uint64_t singleton2 = g_8209003F;
		STORE32(versionAddr, 0u);
		uint32_t singletonPtr2 = LOAD32(globalBase - 6568);
		if (singletonPtr2 != 0) {
			singleton2 = LOAD32(singletonPtr2);
		}

		uint32_t streamHasData = LOAD32(LOAD32(streamAddr) + 4);
		callTarget.u64 = streamHasData;
		ctx.r3.u64 = stream;
		ctx.r4.u64 = singleton2;
		ctx.r10.u64 = streamHasData;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t hasData = ctx.r3.u32 & 0xFF;
		if (hasData != 0) {
			uint64_t singleton3 = g_8209003F;
			uint32_t singletonPtr3 = LOAD32(globalBase - 6568);
			if (singletonPtr3 != 0) {
				singleton3 = LOAD32(singletonPtr3);
			}
			IStream_SerializeU32(ctx, base, stream, versionAddr);

			uint32_t streamEndRead = LOAD32(LOAD32(streamAddr) + 12);
			callTarget.u64 = streamEndRead;
			ctx.r3.u64 = stream;
			ctx.r10.u64 = streamEndRead;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint32_t version = LOAD32(versionAddr);
			if ((int32_t)version == 1) {
				CPropertyContainer_Load(ctx, base, propertyContainerAddr, stream);
			} else {
				n_sub_83219588(ctx, base, propertyContainerAddr, stream, version);
			}
		} else {
			STORE32(versionAddr, 1u);
			CPropertyContainer_Load(ctx, base, propertyContainerAddr, stream);
		}

		// the callee reads the entity id and the two extra flags from r5/r6/r7,
		// not from the argument registers
		ctx.r5.u64 = 0;
		ctx.r6.u64 = entityId;
		ctx.r7.u64 = 0;
		CRegistrableThing_LoadId(ctx, base, propertyContainerAddr, stream);

		uint32_t streamEndRead2 = LOAD32(LOAD32(streamAddr) + 12);
		callTarget.u64 = streamEndRead2;
		ctx.r3.u64 = stream;
		ctx.r10.u64 = streamEndRead2;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t notify = (uint32_t)notifyFlag & 0xFF;
		if (notify != 0) {
			uint32_t containerLoaded = LOAD32(uint32_t(propertyContainer->vtable) + 20);
			callTarget.u64 = containerLoaded;
			ctx.r3.u64 = propertyContainerAddr;
			ctx.r9.u64 = notify;
			ctx.r10.u64 = containerLoaded;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(141, sub_83219DF8, 0x83219DF8) { ctx.r3.u64 = n_sub_83219DF8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }
