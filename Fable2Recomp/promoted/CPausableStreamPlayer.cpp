// CPausableStreamPlayer (vtable 0x8200C150): methods of the class as readable C++.
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

uint64_t CPausableStreamPlayer_IsFinished(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr) {
	if (!UseLiftedCode(90, 0x82C34170)) { ctx.r3.u64 = pausableStreamPlayerAddr; __imp__sub_82C34170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C34170);
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	if (player->m_IsStopped == 0) {
		return 0;
	}
	uint32_t inner = player->m_Inner;
	if (inner == 0) {
		return 1;
	}
	uint32_t vtable = LOAD32(inner);
	uint32_t method = LOAD32(vtable);
	ctx.r3.u64 = inner;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(90, sub_82C34170, 0x82C34170) { ctx.r3.u64 = CPausableStreamPlayer_IsFinished(ctx, base, ctx.r3.u64); }

uint64_t CPausableStreamPlayer_Resume(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr) {
	if (!UseLiftedCode(90, 0x82C341A8)) { ctx.r3.u64 = pausableStreamPlayerAddr; __imp__sub_82C341A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C341A8);
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t result = pausableStreamPlayerAddr;
	if (player->m_IsPaused != 0) {
		uint32_t inner = player->m_Inner;
		result = inner;
		if (inner != 0) {
			uint32_t vtable = LOAD32(inner);
			uint32_t resumeMethod = LOAD32(vtable + 20);
			ctx.r3.u64 = inner;
			ctx.r10.u64 = resumeMethod;
			REX_CALL_INDIRECT_FUNC(resumeMethod);
			result = ctx.r3.u64;
		}
		player->m_IsPaused = 0;
	}
	return result;
}
PROMOTED_ENTRY(90, sub_82C341A8, 0x82C341A8) { ctx.r3.u64 = CPausableStreamPlayer_Resume(ctx, base, ctx.r3.u64); }

uint64_t CPausableStreamPlayer_Pause(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr) {
	if (!UseLiftedCode(90, 0x82C34200)) { ctx.r3.u64 = pausableStreamPlayerAddr; __imp__sub_82C34200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C34200);
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t result = pausableStreamPlayerAddr;
	if (player->m_IsPaused == 0) {
		uint32_t inner = player->m_Inner;
		result = inner;
		if (inner != 0) {
			uint32_t vtable = LOAD32(inner);
			uint32_t pauseMethod = LOAD32(vtable + 24);
			ctx.r3.u64 = inner;
			ctx.r10.u64 = pauseMethod;
			REX_CALL_INDIRECT_FUNC(pauseMethod);
			result = ctx.r3.u64;
		}
		player->m_IsPaused = 1;
	}
	return result;
}
PROMOTED_ENTRY(90, sub_82C34200, 0x82C34200) { ctx.r3.u64 = CPausableStreamPlayer_Pause(ctx, base, ctx.r3.u64); }

uint64_t CPausableStreamPlayer_Stop(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr, uint32_t stopMode) {
	if (!UseLiftedCode(90, 0x82C34258)) { ctx.r3.u64 = pausableStreamPlayerAddr; ctx.r5.u64 = stopMode; __imp__sub_82C34258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C34258);
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	uint64_t result = pausableStreamPlayerAddr;
	if ((int32_t)stopMode != 1 && player->m_IsStopped == 0) {
		uint32_t inner = player->m_Inner;
		player->m_IsStopped = 1;
		result = inner;
		if (inner != 0) {
			uint32_t vtable = LOAD32(inner);
			uint32_t stopMethod = LOAD32(vtable + 32);
			ctx.r3.u64 = inner;
			ctx.r5.u64 = 0;
			ctx.r10.u64 = stopMethod;
			REX_CALL_INDIRECT_FUNC(stopMethod);
			uint32_t innerPointerAddr = uint32_t(pausableStreamPlayerAddr + 48);
			result = OwnedPtr_Reset(ctx, base, innerPointerAddr);
			player->m_38 = 0;
			player->m_3C = 0;
		}
	}
	return result;
}
PROMOTED_ENTRY(90, sub_82C34258, 0x82C34258) { ctx.r3.u64 = CPausableStreamPlayer_Stop(ctx, base, ctx.r3.u64, ctx.r5.u32); }

uint64_t CPausableStreamPlayer_SetSource(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr, uint64_t source) {
	if (!UseLiftedCode(90, 0x82C342E0)) { ctx.r3.u64 = pausableStreamPlayerAddr; ctx.r4.u64 = source; __imp__sub_82C342E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C342E0);
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	uint64_t refList = pausableStreamPlayerAddr + 4;
	RefPtrList_Add(ctx, base, refList, source);
	uint32_t inner = player->m_Inner;
	uint64_t result = inner;
	if (inner != 0) {
		uint32_t vtable = LOAD32(inner);
		uint32_t method = LOAD32(vtable + 4);
		ctx.r3.u64 = inner;
		ctx.r4.u64 = source;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		result = ctx.r3.u64;
	}
	return result;
}
PROMOTED_ENTRY(90, sub_82C342E0, 0x82C342E0) { ctx.r3.u64 = CPausableStreamPlayer_SetSource(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPausableStreamPlayer_RemoveSource(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr, uint64_t source) {
	if (!UseLiftedCode(90, 0x82C34340)) { ctx.r3.u64 = pausableStreamPlayerAddr; ctx.r4.u64 = source; __imp__sub_82C34340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C34340);
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	uint64_t refList = pausableStreamPlayerAddr + 4;
	uint64_t result = RefPtrList_Remove(ctx, base, refList, source);
	uint32_t inner = player->m_Inner;
	if (inner == 0) {
		// As in the original machine code: only without an inner object is its method called, read through the
		// null pointer and with a null object.
		uint32_t vtable = LOAD32(inner);
		uint32_t method = LOAD32(vtable + 8);
		ctx.r3.u64 = 0;
		ctx.r4.u64 = source;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		result = ctx.r3.u64;
	}
	return result;
}
PROMOTED_ENTRY(90, sub_82C34340, 0x82C34340) { ctx.r3.u64 = CPausableStreamPlayer_RemoveSource(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPausableStreamPlayer_PlayLayer(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr, uint64_t source, uint64_t layerHandle) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(90, 0x82C34440)) { ctx.r3.u64 = pausableStreamPlayerAddr; ctx.r4.u64 = source; ctx.r5.u64 = layerHandle; __imp__sub_82C34440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C34440);
	uint32_t stack = ctx.r1.u64;
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	stack = PushStackFrame(base, stack, 240);
	// The key of the layer map lookup is kept in the caller's parameter area.
	uint32_t layerKeyAddr = stack + 276;
	STORE32(layerKeyAddr, (uint32_t)layerHandle);
	uint32_t innerPointerAddr = uint32_t(pausableStreamPlayerAddr + 48);
	uint32_t inner = player->m_Inner;
	// The original leaves these comparison values in the argument registers of the calls below.
	uint64_t layerDifference = (uint64_t)player->m_3C - layerHandle;
	uint64_t innerIsNull = inner == 0 ? 1 : 0;
	uint64_t layerDifferenceLeadingZeros = (uint32_t)layerDifference == 0 ? 32 : __builtin_clz((uint32_t)layerDifference);
	uint64_t hasInner = innerIsNull ^ 1;
	uint64_t isSameLayer = (uint32_t)layerDifference == 0 ? 1 : 0;
	bool layerChanged = (uint32_t)layerDifference != 0;
	uint64_t result = 1;
	uint64_t sourceAfterCall = source;

	if (inner != 0) {
		uint32_t vtable = LOAD32(inner);
		uint32_t method = LOAD32(vtable);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = inner;
		ctx.r4.u64 = source;
		ctx.r5.u64 = isSameLayer;
		ctx.r6.u64 = hasInner;
		ctx.r7.u64 = layerDifferenceLeadingZeros;
		ctx.r8.u64 = innerIsNull;
		ctx.r9.u64 = layerDifference;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		result = ctx.r3.u64;
		sourceAfterCall = ctx.r4.u64;
		isSameLayer = ctx.r5.u64;
		hasInner = ctx.r6.u64;
		layerDifferenceLeadingZeros = ctx.r7.u64;
		innerIsNull = ctx.r8.u64;
		layerDifference = ctx.r9.u64;
	}

	if (inner != 0 && (result & 0xFF) != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = sourceAfterCall;
		ctx.r5.u64 = isSameLayer;
		ctx.r6.u64 = hasInner;
		ctx.r7.u64 = layerDifferenceLeadingZeros;
		ctx.r8.u64 = innerIsNull;
		ctx.r9.u64 = layerDifference;
		result = OwnedPtr_Reset(ctx, base, innerPointerAddr);
		hasInner = ctx.r6.u64;
		layerDifferenceLeadingZeros = ctx.r7.u64;
		innerIsNull = ctx.r8.u64;
		layerDifference = ctx.r9.u64;
		uint32_t currentEntry = player->m_38;
		if (currentEntry != 0) {
			STORE32(currentEntry + 4, 0);
			player->m_38 = 0;
		}
		player->m_40 = uint32_t(player->m_18);
	} else if (layerChanged) {
		uint32_t limit = player->m_1C;
		uint32_t countdownBefore = player->m_40;
		// (the original leaves this value in r9 for the stop call below)
		layerDifference = countdownBefore;
		if (countdownBefore > limit) {
			player->m_40 = limit;
		}
	} else if ((result & 0xFF) == 0) {
		stack = PopStackFrame(stack, 240);
		ctx.r1.u64 = stack;
		return result;
	}

	ctx.r1.u64 = stack;
	ctx.r3.u64 = result;
	uint64_t global832D5FE4 = GetGlobalAddress832D5FE4(ctx, base);
	uint32_t step = LOAD32((uint32_t)global832D5FE4 + 4);
	uint32_t countdown = player->m_40;
	if (countdown >= step) {
		player->m_40 = countdown - step;
		stack = PopStackFrame(stack, 240);
		ctx.r1.u64 = stack;
		return global832D5FE4;
	}

	uint64_t oldInner = LOAD32(innerPointerAddr);
	if ((uint32_t)oldInner != 0) {
		uint32_t member20 = player->m_20;
		uint32_t vtable = LOAD32((uint32_t)oldInner);
		uint32_t stopMethod = LOAD32(vtable + 32);
		ctx.r3.u64 = oldInner;
		ctx.r4.u64 = member20;
		ctx.r5.u64 = 0;
		ctx.r6.u64 = hasInner;
		ctx.r7.u64 = layerDifferenceLeadingZeros;
		ctx.r8.u64 = innerIsNull;
		ctx.r9.u64 = layerDifference;
		ctx.r10.u64 = stopMethod;
		REX_CALL_INDIRECT_FUNC(stopMethod);
		oldInner = OwnedPtr_Reset(ctx, base, innerPointerAddr);
		hasInner = ctx.r6.u64;
		innerIsNull = ctx.r8.u64;
		player->m_38 = 0;
	}

	if (player->m_IsPaused != 0) {
		player->m_3C = 0xFFFFFFFFu;
		stack = PopStackFrame(stack, 240);
		ctx.r1.u64 = stack;
		return oldInner;
	}

	// The layer map (a std::map from layer handle to a two-word entry): the iterator is {map, node}.
	uint32_t layerMap = uint32_t(pausableStreamPlayerAddr + 36);
	uint32_t iteratorAddr = stack + 80;
	result = (uint64_t)stack + 80;
	ctx.r8.u64 = innerIsNull;
	StdMap_FindIterator_U32Key(ctx, base, iteratorAddr, layerMap, layerKeyAddr);
	uint32_t iteratorMap = LOAD32(iteratorAddr);
	uint32_t mapHead = player->m_28;
	if (!(iteratorMap != 0 && iteratorMap == layerMap)) {
		ppc_trap(ctx, base, 22);
	}
	uint32_t foundNode = LOAD32(iteratorAddr + 4);
	if (foundNode != mapHead) {
		if (iteratorMap == 0) {
			ppc_trap(ctx, base, 22);
		}
		if (foundNode == LOAD32(iteratorMap + 4)) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t layerEntry = foundNode + 16;
		uint32_t params = stack + 96;
		ctx.r5.u64 = (uint64_t)stack + 276;
		ctx.r6.u64 = hasInner;
		CCharString_Constructor(ctx, base, params);
		LayerEntry_SetValues(ctx, base, params, 0, LOAD32(layerEntry));
		n_sub_82BFC880(ctx, base, params, LOAD32(layerEntry + 4));
		LayerEntry_SetField32(ctx, base, params, 6);

		// The source makes the new inner object from the parameters; its pointer comes back in the slot at stack + 80.
		uint32_t newInnerSlot = stack + 80;
		uint32_t sourceVtable = LOAD32((uint32_t)source);
		uint32_t createMethod = LOAD32(sourceVtable + 12);
		ctx.r3.u64 = newInnerSlot;
		ctx.r4.u64 = source;
		ctx.r5.u64 = (uint64_t)stack + 96;
		ctx.r10.u64 = createMethod;
		REX_CALL_INDIRECT_FUNC(createMethod);
		uint64_t returnedPointer = ctx.r3.u64;
		RefPtr_Assign(ctx, base, innerPointerAddr, returnedPointer);
		OwnedPtr_Reset(ctx, base, newInnerSlot);

		if (LOAD32(innerPointerAddr) != 0) {
			LayerManager_RegisterChild(ctx, base, pausableStreamPlayerAddr + 4, innerPointerAddr);
			if (LOAD32(layerEntry + 4) != 0) {
				uint32_t innerObject = LOAD32(innerPointerAddr);
				uint32_t innerVtable = LOAD32(innerObject);
				ctx.fpscr.disableFlushMode();
				double firstValue = double(LOAD_F32(0x82000C0Cu));
				uint32_t method = LOAD32(innerVtable + 12);
				ctx.r3.u64 = innerObject;
				ctx.r5.u64 = 0;
				ctx.r9.u64 = method;
				ctx.r10.u64 = innerVtable;
				ctx.f1.f64 = firstValue;
				REX_CALL_INDIRECT_FUNC(method);

				innerObject = LOAD32(innerPointerAddr);
				uint32_t member20 = player->m_20;
				innerVtable = LOAD32(innerObject);
				ctx.fpscr.disableFlushMode();
				double secondValue = double(LOAD_F32(0x82000C08u));
				method = LOAD32(innerVtable + 12);
				ctx.r3.u64 = innerObject;
				ctx.r5.u64 = member20;
				ctx.r6.u64 = method;
				ctx.r7.u64 = innerVtable;
				ctx.r8.s64 = g_82000000;
				ctx.f1.f64 = secondValue;
				REX_CALL_INDIRECT_FUNC(method);
			}
		}
		player->m_38 = layerEntry;
		result = CCharString_ReleaseMember(ctx, base, params);
	}

	uint32_t innerAfter = LOAD32(innerPointerAddr);
	player->m_3C = (uint32_t)layerHandle;
	if (innerAfter != 0) {
		player->m_40 = uint32_t(player->m_1C);
	} else {
		player->m_40 = 0xFFFFFFFFu;
	}
	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C34440, 0x82C34440) { ctx.r3.u64 = CPausableStreamPlayer_PlayLayer(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CPausableStreamPlayer_Play(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr, uint64_t source) {
	if (!UseLiftedCode(90, 0x82C346F0)) { ctx.r3.u64 = pausableStreamPlayerAddr; ctx.r4.u64 = source; __imp__sub_82C346F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C346F0);
	uint32_t stack = ctx.r1.u64;
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	stack = PushStackFrame(base, stack, 176);
	uint64_t result = pausableStreamPlayerAddr;
	// r4 as the original leaves it for the caller: the source, or what the last call left there.
	uint64_t secondResult = source;

	if (player->m_IsStopped == 0) {
		// The source fills a record at stack + 96.
		uint32_t sourceRecord = stack + 96;
		uint32_t sourceVtable = LOAD32((uint32_t)source);
		uint32_t fillMethod = LOAD32(sourceVtable + 44);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = source;
		ctx.r4.u64 = (uint64_t)stack + 96;
		ctx.r10.u64 = fillMethod;
		REX_CALL_INDIRECT_FUNC(fillMethod);
		result = ctx.r3.u64;
		secondResult = ctx.r4.u64;

		if ((result & 0xFF) != 0) {
			if (player->m_38 != 0 && player->m_IsPaused == 0) {
				uint32_t global832D5FE4 = GetGlobalAddress832D5FE4(ctx, base);
				uint32_t currentEntry = player->m_38;
				uint32_t entryCounter = LOAD32(currentEntry + 4);
				STORE32(currentEntry + 4, LOAD32(global832D5FE4 + 4) + entryCounter);
			}

			// Words 0 and 2 of the source's record go to the create call as one 8-byte argument (stack + 80).
			ctx.fpscr.disableFlushMode();
			double recordValue0 = double(LOAD_F32(sourceRecord));
			STORE_F32(stack + 80, float(recordValue0));
			double recordValue2 = double(LOAD_F32(sourceRecord + 8));
			uint32_t createRecord = stack + 112;
			STORE32(createRecord, 0xFFFFFFFFu);
			STORE32(createRecord + 4, 0xFFFFFFFFu);
			STORE_F32(stack + 84, float(recordValue2));
			double defaultValue = double(LOAD_F32(0x82000C0Cu));
			STORE32(createRecord + 28, 0u);
			STORE_F32(createRecord + 8, float(defaultValue));
			STORE_F32(createRecord + 12, float(defaultValue));
			STORE_F32(createRecord + 16, float(defaultValue));
			STORE_F32(createRecord + 20, float(defaultValue));
			STORE_F32(createRecord + 24, float(defaultValue));
			uint32_t soundManager = player->m_14;
			uint64_t recordPair = LOAD64(stack + 80);
			uint32_t created = SoundManager_CreateSound(ctx, base, soundManager, recordPair, (uint64_t)stack + 112);
			uint64_t layerHandle = LOAD32(createRecord + 4);
			if ((created & 0xFF) == 0) {
				layerHandle = uint64_t(int64_t(-1));
			}
			result = CPausableStreamPlayer_PlayLayer(ctx, base, pausableStreamPlayerAddr, source, layerHandle);
			secondResult = ctx.r4.u64;
		}
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(90, sub_82C346F0, 0x82C346F0) { ctx.r3.u64 = CPausableStreamPlayer_Play(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CPausableStreamPlayer_Destructor(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr) {
	constexpr int32_t CPausableStreamPlayer_vtable = int32_t(0x8200C150);
	if (!UseLiftedCode(90, 0x82C347E0)) { ctx.r3.u64 = pausableStreamPlayerAddr; __imp__sub_82C347E0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C347E0);
	uint32_t stack = ctx.r1.u64;
	CPausableStreamPlayer* player = GameObject<CPausableStreamPlayer>(base, pausableStreamPlayerAddr);
	stack = PushStackFrame(base, stack, 128);
	// The original keeps the vtable address (sign-extended) in r9 through the calls through pointers below.
	uint64_t vtableAddress = uint64_t(int64_t(CPausableStreamPlayer_vtable));
	uint32_t wasStopped = player->m_IsStopped;
	player->vtable = (uint32_t)vtableAddress;

	if (wasStopped == 0) {
		uint32_t inner = player->m_Inner;
		player->m_IsStopped = 1;
		if (inner != 0) {
			uint32_t vtable = LOAD32(inner);
			uint32_t stopMethod = LOAD32(vtable + 32);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = inner;
			ctx.r4.u64 = 0;
			ctx.r5.u64 = 0;
			ctx.r9.u64 = vtableAddress;
			ctx.r10.u64 = stopMethod;
			REX_CALL_INDIRECT_FUNC(stopMethod);
			OwnedPtr_Reset(ctx, base, uint32_t(pausableStreamPlayerAddr + 48));
			vtableAddress = ctx.r9.u64;
			player->m_38 = 0;
			player->m_3C = 0;
		}
	}

	// The inner pointer's second word (m_34) holds its reference: released, then both words cleared.
	uint32_t innerReference = player->m_34;
	if (innerReference != 0) {
		uint32_t referenceVtable = LOAD32(innerReference);
		uint32_t releaseMethod = LOAD32(referenceVtable + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = innerReference;
		ctx.r9.u64 = vtableAddress;
		ctx.r10.u64 = releaseMethod;
		REX_CALL_INDIRECT_FUNC(releaseMethod);
	}
	player->m_34 = 0;
	player->m_Inner = 0;

	// Clear the layer map (a std::map, head node at +40): erase from begin {map, first word of the head}
	// to end {map, head}, then free the head node.
	uint32_t layerMap = uint32_t(pausableStreamPlayerAddr + 36);
	uint32_t iteratorAddr = stack + 80;
	uint32_t mapHead = player->m_28;
	STORE32(iteratorAddr, layerMap);
	STORE32(iteratorAddr + 4, mapHead);
	uint64_t endIterator = LOAD64(iteratorAddr);
	uint32_t firstNode = LOAD32(mapHead);
	STORE32(iteratorAddr, layerMap);
	STORE32(iteratorAddr + 4, firstNode);
	uint64_t beginIterator = LOAD64(iteratorAddr);
	ctx.r1.u64 = stack;
	StdMap_Remove(ctx, base, iteratorAddr, layerMap, beginIterator, endIterator);
	uint32_t headToFree = player->m_28;
	HandleTarget_FreeThunk(ctx, base, headToFree);
	player->m_28 = 0;
	player->m_2C = 0;

	RefPtrList_Destructor(ctx, base, pausableStreamPlayerAddr + 4);
	uint32_t thisAddr = (uint32_t)pausableStreamPlayerAddr;
	C_8200A34C_Destructor(ctx, base, thisAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return thisAddr;
}
PROMOTED_ENTRY(90, sub_82C347E0, 0x82C347E0) { ctx.r3.u64 = CPausableStreamPlayer_Destructor(ctx, base, ctx.r3.u64); }

uint64_t CPausableStreamPlayer_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t pausableStreamPlayerAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(90, 0x82C348C8)) { ctx.r3.u64 = pausableStreamPlayerAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82C348C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C348C8);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CPausableStreamPlayer_Destructor(ctx, base, pausableStreamPlayerAddr);
	if ((deleteFlags & 1) != 0) {
		HandleTarget_FreeThunk(ctx, base, pausableStreamPlayerAddr);
	}
	return pausableStreamPlayerAddr;
}
PROMOTED_ENTRY(90, sub_82C348C8, 0x82C348C8) { ctx.r3.u64 = CPausableStreamPlayer_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
