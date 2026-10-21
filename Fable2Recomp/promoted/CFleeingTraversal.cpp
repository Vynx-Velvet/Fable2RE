// CFleeingTraversal (vtable 0x820C78F0): methods of the class as readable C++.
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

uint32_t CFleeingTraversal_Ctor(CpuState& ctx, uint8_t* base, uint32_t fleeingTraversalAddr) {
	if (!UseLiftedCode(40, 0x82624598)) { ctx.r3.u64 = fleeingTraversalAddr; __imp__sub_82624598(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82624598);
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	CFleeingTraversal_InitBase(ctx, base, fleeingTraversalAddr);
	fleeingTraversal->m_18 = 0;
	ctx.fpscr.disableFlushMode();
	double initialValue = double(LOAD_F32(0x82000BE0u));
	fleeingTraversal->vtable = 0x820C78F0u;
	fleeingTraversal->m_1C = float(initialValue);
	fleeingTraversal->m_20 = float(initialValue);
	fleeingTraversal->m_24 = 0;
	fleeingTraversal->m_28 = 0;
	fleeingTraversal->m_2C = 0;
	fleeingTraversal->m_30 = 0;
	fleeingTraversal->m_34 = 0;
	fleeingTraversal->m_38 = 0;
	fleeingTraversal->m_3C = 0;
	fleeingTraversal->m_40 = 0;
	fleeingTraversal->m_44 = 0;
	fleeingTraversal->m_48 = 0;
	fleeingTraversal->m_10 = uint8_t(1);
	return fleeingTraversalAddr;
}
PROMOTED_ENTRY(40, sub_82624598, 0x82624598) { ctx.r3.u64 = CFleeingTraversal_Ctor(ctx, base, ctx.r3.u32); }

uint64_t CFleeingTraversal_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t fleeingTraversalAddr, uint64_t deleteFlags) {
	constexpr int32_t CFleeingTraversal_vtable = int32_t(0x820C78F0);
	constexpr int32_t baseVtablePage = int32_t(0x820D0000);
	constexpr uint32_t freeFunctionPointer = 0x832FD974u;
	if (!UseLiftedCode(40, 0x82624620)) { ctx.r3.u64 = fleeingTraversalAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82624620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82624620);
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	fleeingTraversal->vtable = CFleeingTraversal_vtable;
	ctx.r4.u64 = deleteFlags;
	ctx.r10.s64 = CFleeingTraversal_vtable;
	CFleeingTraversal_Cleanup(ctx, base, fleeingTraversalAddr);
	uint32_t freeFlag = uint32_t(deleteFlags) & 0x1;
	int64_t baseVtable = int64_t(baseVtablePage) - 30984;
	fleeingTraversal->vtable = uint32_t(baseVtable);
	if (freeFlag != 0) {
		uint32_t freeFunction = LOAD32(freeFunctionPointer);
		ctx.r3.u64 = fleeingTraversalAddr;
		ctx.r7.u64 = uint64_t(baseVtable);
		ctx.r8.u64 = freeFlag;
		ctx.r9.s64 = baseVtablePage;
		ctx.r10.u64 = freeFunction;
		REX_CALL_INDIRECT_FUNC(freeFunction);
	}
	return fleeingTraversalAddr;
}
PROMOTED_ENTRY(40, sub_82624620, 0x82624620) { ctx.r3.u64 = CFleeingTraversal_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CFleeingTraversal_CanFlee(CpuState& ctx, uint8_t* base, uint64_t fleeingTraversalAddr, uint64_t objectList) {
	if (!UseLiftedCode(40, 0x826246E0)) { ctx.r3.u64 = fleeingTraversalAddr; ctx.r5.u64 = objectList; __imp__sub_826246E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826246E0);
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	uint32_t vtable = fleeingTraversal->vtable;
	uint32_t method = LOAD32(vtable + 4);
	ctx.r3.u64 = fleeingTraversalAddr;
	ctx.r5.u64 = objectList;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	bool accepted = (ctx.r3.u32 & 0xFF) != 0;
	uint64_t secondResult = ctx.r4.u64;

	uint32_t result = 0;
	if (accepted) {
		if (fleeingTraversal->m_30 != 0) {
			result = 1;
		} else {
			// No entries yet: size them for the largest count among the objects of the list.
			secondResult = 0;
			uint64_t largestCount = 0;
			uint32_t list = uint32_t(objectList);
			uint32_t objectCount = list != 0 ? LOAD32(list + 8) : 0;
			if (objectCount != 0) {
				uint64_t cursor = LOAD32(list + 4);
				uint64_t remaining = objectCount;
				do {
					uint32_t object = LOAD32(uint32_t(cursor));
					if (object != 0) {
						uint32_t objectInfo = LOAD32(object + 132);
						if (objectInfo != 0) {
							uint32_t count = LOAD32(objectInfo + 20);
							if (count > uint32_t(largestCount)) {
								largestCount = count;
							}
						}
					}
					remaining = remaining - 1;
					cursor = cursor + 4;
				} while (uint32_t(remaining) != 0);
				if (uint32_t(largestCount) != 0) {
					ctx.r9.u64 = remaining;
					ctx.r10.u64 = cursor;
					CFleeingTraversal_SetEntryCount(ctx, base, fleeingTraversalAddr, largestCount);
					secondResult = ctx.r4.u64;
					result = 1;
				}
			}
		}
	}

	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(40, sub_826246E0, 0x826246E0) { ctx.r3.u64 = CFleeingTraversal_CanFlee(ctx, base, ctx.r3.u64, ctx.r5.u64); }

uint64_t CFleeingTraversal_SetProperty(CpuState& ctx, uint8_t* base, uint64_t fleeingTraversalAddr, uint64_t attribute, uint64_t parserArgument) {
	constexpr int32_t str_TXT_820C78C0_B_ = int32_t(0x820C78C0);
	constexpr int32_t str_TXT_820C78D8_B_ = int32_t(0x820C78D8);
	constexpr int32_t str_TXT_820C78E4_B_ = int32_t(0x820C78E4);
	constexpr uint32_t scaleSourcePointer = 0x8333FD30u;
	constexpr uint32_t defaultScaleAddress = 0x820994C0u;
	if (!UseLiftedCode(40, 0x826247B0)) { ctx.r3.u64 = fleeingTraversalAddr; ctx.r4.u64 = attribute; ctx.r8.u64 = parserArgument; __imp__sub_826247B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826247B0);
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	uint64_t attributeName = Lua_Shard_GetCurrentStance(ctx, base, attribute);
	if (uint32_t(stricmp(ctx, base, str_TXT_820C78C0_B_, attributeName)) == 0) {
		uint64_t text = C_820F9F34_GetString(ctx, base, attribute);
		uint64_t entryCount = String_ParseInt(ctx, base, text, parserArgument);
		CFleeingTraversal_SetEntryCount(ctx, base, fleeingTraversalAddr, entryCount);
		return 1;
	}

	attributeName = Lua_Shard_GetCurrentStance(ctx, base, attribute);
	if (uint32_t(stricmp(ctx, base, str_TXT_820C78D8_B_, attributeName)) == 0) {
		uint32_t scaleSource = LOAD32(scaleSourcePointer);
		ctx.fpscr.disableFlushMode();
		double scale = scaleSource != 0 ? double(LOAD_F32(scaleSource + 12)) : double(LOAD_F32(defaultScaleAddress));
		uint64_t text = C_820F9F34_GetString(ctx, base, attribute);
		String_ParseFloat(ctx, base, text, parserArgument);
		double parsed = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		double value = double(float(parsed));
		fleeingTraversal->m_20 = float(value * scale);
		return 1;
	}

	attributeName = Lua_Shard_GetCurrentStance(ctx, base, attribute);
	if (uint32_t(stricmp(ctx, base, str_TXT_820C78E4_B_, attributeName)) == 0) {
		uint64_t text = C_820F9F34_GetString(ctx, base, attribute);
		String_ParseFloat(ctx, base, text, parserArgument);
		double parsed = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		fleeingTraversal->m_1C = float(parsed);
		return 1;
	}

	return n_sub_82E85D08(ctx, base, fleeingTraversalAddr, attribute);
}
PROMOTED_ENTRY(40, sub_826247B0, 0x826247B0) { ctx.r3.u64 = CFleeingTraversal_SetProperty(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CFleeingTraversal_Reset(CpuState& ctx, uint8_t* base, uint64_t fleeingTraversalAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr uint32_t initialValueAddress = 0x82000BE0u;
	constexpr uint32_t firstEntryValueAddress = 0x820994B4u;
	constexpr uint32_t listPosition_vtable = 0x820C7958u;
	constexpr uint32_t positionBase_vtable = 0x820C86F8u;
	if (!UseLiftedCode(40, 0x826248D8)) { ctx.r3.u64 = fleeingTraversalAddr; __imp__sub_826248D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826248D8);
	uint32_t stack = ctx.r1.u64;
	uint64_t secondResult = ctx.r4.u64;
	uint64_t result = fleeingTraversalAddr;
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	stack = PushStackFrame(base, stack, 144);

	// A list (m_34, m_3C) links its nodes from +8 through node +20, keeps its spare nodes from +16, its last node
	// at +12 and its node count at +20; a node holds two values at +8 and +12 and an in-use byte at +24.
	auto clearNodeValues = [&](uint32_t list) {
		for (uint32_t node = LOAD32(list + 8); node != 0; node = LOAD32(node + 20)) {
			STORE32(node + 12, 0);
			STORE32(node + 8, 0);
		}
	};
	auto moveAllNodesToSpares = [&](uint32_t list) {
		if (LOAD32(list + 8) != 0) {
			uint32_t next;
			do {
				STORE8(LOAD32(list + 8) + 24, 0);
				uint32_t node = LOAD32(list + 8);
				next = LOAD32(node + 20);
				STORE32(node + 20, LOAD32(list + 16));
				STORE32(list + 16, LOAD32(list + 8));
				STORE32(list + 8, next);
			} while (next != 0);
		}
		STORE32(list + 12, 0);
		STORE32(list + 20, 0);
	};

	fleeingTraversal->m_10 = 0;
	clearNodeValues(fleeingTraversal->m_3C);
	moveAllNodesToSpares(fleeingTraversal->m_3C);
	clearNodeValues(fleeingTraversal->m_34);
	moveAllNodesToSpares(fleeingTraversal->m_34);

	// Per entry: a position in each list (8 bytes: vtable, node) and two float values.
	for (uint32_t index = 0; index < fleeingTraversal->m_30; index++) {
		STORE32(fleeingTraversal->m_38 + index * 8 + 4, 0);
	}
	for (uint32_t index = 0; index < fleeingTraversal->m_30; index++) {
		STORE32(fleeingTraversal->m_40 + index * 8 + 4, 0);
	}
	ctx.fpscr.disableFlushMode();
	double initialValue = double(LOAD_F32(initialValueAddress));
	for (uint32_t index = 0; index < fleeingTraversal->m_30; index++) {
		STORE_F32(fleeingTraversal->m_48 + index * 4, float(initialValue));
	}
	for (uint32_t index = 0; index < fleeingTraversal->m_30; index++) {
		STORE_F32(fleeingTraversal->m_44 + index * 4, float(initialValue));
	}

	uint32_t initialRecord = fleeingTraversal->m_18;
	if (initialRecord != 0) {
		// Insert {initialRecord, 0} at the end of the m_34 list (position: no node) and keep its position.
		STORE32(stack + 104, positionBase_vtable);
		STORE32(stack + 108, initialRecord);
		STORE32(stack + 112, 0);
		STORE32(stack + 88, listPosition_vtable);
		STORE32(stack + 92, 0);
		uint32_t initialIndex = LOAD32(initialRecord);
		uint32_t insertedPosition = stack + 96;
		ctx.r1.u64 = stack;
		n_sub_82625AE0(ctx, base, insertedPosition, fleeingTraversal->m_34, stack + 104, stack + 88);
		uint32_t positions = fleeingTraversal->m_38;
		secondResult = LOAD32(insertedPosition + 4);
		STORE32(positions + (initialIndex << 3) + 4, uint32_t(secondResult));

		uint32_t record = fleeingTraversal->m_18;
		uint32_t entryValues = fleeingTraversal->m_44;
		ctx.fpscr.disableFlushMode();
		double firstEntryValue = double(LOAD_F32(firstEntryValueAddress));
		STORE32(stack + 96, positionBase_vtable);
		STORE_F32(entryValues + (LOAD32(record) << 2), float(firstEntryValue));
		uint32_t callbackObject = fleeingTraversal->m_28;
		result = callbackObject;
		STORE_F32(stack + 80, float(firstEntryValue));
		if (callbackObject != 0) {
			uint32_t currentRecord = fleeingTraversal->m_18;
			uint32_t member2C = fleeingTraversal->m_2C;
			uint32_t vtable = LOAD32(callbackObject);
			uint32_t method = LOAD32(vtable + 4);
			ctx.r3.u64 = callbackObject;
			ctx.r4.u64 = member2C;
			ctx.r5.u64 = currentRecord;
			ctx.r6.u64 = uint64_t(stack) + 80;
			ctx.r7.u64 = entryValues;
			ctx.r8.u64 = record;
			ctx.r9.s64 = g_820A0000;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
			result = ctx.r3.u64;
			secondResult = ctx.r4.u64;
		}
		ctx.fpscr.disableFlushMode();
		double score = double(LOAD_F32(stack + 80));
		STORE_F32(fleeingTraversal->m_48 + (LOAD32(fleeingTraversal->m_18) << 2), float(score));
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(40, sub_826248D8, 0x826248D8) { ctx.r3.u64 = CFleeingTraversal_Reset(ctx, base, ctx.r3.u64); }

uint32_t CFleeingTraversal_Cleanup(CpuState& ctx, uint8_t* base, uint32_t fleeingTraversalAddr) {
	constexpr uint32_t freeFunctionPointer = 0x832FD974u;
	if (!UseLiftedCode(40, 0x82624B98)) { ctx.r3.u64 = fleeingTraversalAddr; __imp__sub_82624B98(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82624B98);
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	// The two lists: deleting destructor (vtable slot 0) with delete flags 1.
	auto deleteList = [&](uint32_t list) {
		uint32_t vtable = LOAD32(list);
		uint32_t deletingDestructor = LOAD32(vtable);
		ctx.r3.u64 = list;
		ctx.r4.u64 = 1;
		ctx.r10.u64 = deletingDestructor;
		REX_CALL_INDIRECT_FUNC(deletingDestructor);
	};
	// The two position arrays, allocated with their element count in the word before them: the elements'
	// deleting destructor with flags 3 (array, free) when the count is not 0, else only the block is freed.
	auto deleteArray = [&](uint32_t array) {
		uint32_t elementCount = LOAD32(array - 4);
		uint64_t block = uint64_t(array) - 4;
		if (int32_t(elementCount) != 0) {
			uint32_t vtable = LOAD32(array);
			uint32_t deletingDestructor = LOAD32(vtable);
			ctx.r3.u64 = array;
			ctx.r4.u64 = 3;
			ctx.r9.u64 = deletingDestructor;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(deletingDestructor);
		} else {
			ctx.r10.u64 = elementCount;
			HandleTarget_Free(ctx, base, block);
		}
	};

	uint32_t list = fleeingTraversal->m_34;
	if (list != 0) {
		deleteList(list);
		fleeingTraversal->m_34 = 0;
	}
	list = fleeingTraversal->m_3C;
	if (list != 0) {
		deleteList(list);
		fleeingTraversal->m_3C = 0;
	}
	uint32_t positions = fleeingTraversal->m_38;
	if (positions != 0) {
		deleteArray(positions);
		fleeingTraversal->m_38 = 0;
	}
	positions = fleeingTraversal->m_40;
	if (positions != 0) {
		deleteArray(positions);
		fleeingTraversal->m_40 = 0;
	}

	uint32_t entryValues = fleeingTraversal->m_44;
	if (entryValues != 0) {
		uint32_t freeFunction = LOAD32(freeFunctionPointer);
		ctx.r3.u64 = entryValues;
		REX_CALL_INDIRECT_FUNC(freeFunction);
		fleeingTraversal->m_44 = 0;
	}
	uint64_t result = fleeingTraversal->m_48;
	if (uint32_t(result) != 0) {
		uint32_t freeFunction = LOAD32(freeFunctionPointer);
		ctx.r3.u64 = result;
		REX_CALL_INDIRECT_FUNC(freeFunction);
		result = ctx.r3.u64;
		fleeingTraversal->m_48 = 0;
	}
	return uint32_t(result);
}
PROMOTED_ENTRY(40, sub_82624B98, 0x82624B98) { ctx.r3.u64 = CFleeingTraversal_Cleanup(ctx, base, ctx.r3.u32); }

uint32_t CFleeingTraversal_SetEntryCount(CpuState& ctx, uint8_t* base, uint64_t fleeingTraversalAddr, uint64_t entryCount) {
	constexpr uint32_t listPosition_vtable = 0x820C7958u;
	if (!UseLiftedCode(40, 0x82624CB8)) { ctx.r3.u64 = fleeingTraversalAddr; ctx.r4.u64 = entryCount; __imp__sub_82624CB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82624CB8);
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	GameStackFrame stackFrame(ctx, base, 144);

	uint64_t count = entryCount;
	if (uint32_t(count) == 0) {
		count = 1;
	}
	uint64_t updateArgument = entryCount;

	if (uint32_t(count) != fleeingTraversal->m_30) {
		ctx.r4.u64 = entryCount;
		CFleeingTraversal_Cleanup(ctx, base, uint32_t(fleeingTraversalAddr));
		fleeingTraversal->m_30 = uint32_t(count);

		uint32_t listMemory = uint32_t(CGameObject_AllocateID(ctx, base, 28));
		fleeingTraversal->m_34 = listMemory != 0 ? n_sub_82625918(ctx, base, listMemory, count) : 0;
		listMemory = uint32_t(CGameObject_AllocateID(ctx, base, 28));
		fleeingTraversal->m_3C = listMemory != 0 ? n_sub_82625918(ctx, base, listMemory, count) : 0;

		// A position array: the element count, then `count` positions (vtable, no node).
		uint64_t positionArrayBytes = ~0ull;
		if (uint32_t(count) <= 0x1FFFFFFFu) {
			positionArrayBytes = uint64_t(uint32_t(count) << 3) + 4;
		}
		auto fillPositionArray = [&](uint64_t block) {
			STORE32(uint32_t(block), uint32_t(count));
			uint32_t position = uint32_t(block + 4);
			for (int32_t remaining = int32_t(uint32_t(count) - 1); remaining >= 0; remaining--) {
				STORE32(position, listPosition_vtable);
				STORE32(position + 4, 0);
				position += 8;
			}
		};

		// The original leaves the array's address (or, when the allocation failed, the allocator's own value)
		// in place for the next allocation.
		uint64_t block = CGameObject_AllocateID(ctx, base, positionArrayBytes);
		uint64_t positions = ctx.r9.u64;
		if (uint32_t(block) != 0) {
			fillPositionArray(block);
			positions = block + 4;
			fleeingTraversal->m_38 = uint32_t(positions);
		} else {
			fleeingTraversal->m_38 = 0;
		}
		ctx.r9.u64 = positions;
		block = CGameObject_AllocateID(ctx, base, positionArrayBytes);
		positions = ctx.r9.u64;
		if (uint32_t(block) != 0) {
			fillPositionArray(block);
			positions = block + 4;
			fleeingTraversal->m_40 = uint32_t(positions);
		} else {
			fleeingTraversal->m_40 = 0;
		}

		uint64_t valueArrayBytes = uint32_t(count) <= 0x3FFFFFFFu ? uint64_t(uint32_t(count) << 2) : ~0ull;
		ctx.r9.u64 = positions;
		fleeingTraversal->m_44 = uint32_t(CGameObject_AllocateID(ctx, base, valueArrayBytes));
		uint32_t scores = uint32_t(CGameObject_AllocateID(ctx, base, valueArrayBytes));
		updateArgument = ctx.r4.u64;
		fleeingTraversal->m_48 = scores;
	}

	uint32_t vtable = fleeingTraversal->vtable;
	uint32_t method = LOAD32(vtable + 24);
	ctx.r3.u64 = fleeingTraversalAddr;
	ctx.r4.u64 = updateArgument;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u32;
}
PROMOTED_ENTRY(40, sub_82624CB8, 0x82624CB8) { ctx.r3.u64 = CFleeingTraversal_SetEntryCount(ctx, base, ctx.r3.u64, ctx.r4.u64); }

void ClearFleeingTraversalGlobalFlag(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(40, 0x82624F58)) { __imp__sub_82624F58(ctx, base); return; }
	LiftedFrame frame(0x82624F58);
	constexpr uint32_t globalFlagAddress = 0x833209F4u;
	if (LOAD8(globalFlagAddress) != 0) {
		STORE8(globalFlagAddress, uint8_t(0));
	}
}
PROMOTED_ENTRY(40, sub_82624F58, 0x82624F58) { ClearFleeingTraversalGlobalFlag(ctx, base); }

uint64_t CFleeingTraversal_PopEntry(CpuState& ctx, uint8_t* base, uint32_t fleeingTraversalAddr) {
	constexpr int32_t g_820C793C = int32_t(0x820C793C);
	constexpr int32_t g_820C86F8 = int32_t(0x820C86F8);
	constexpr uint32_t listPosition_vtable = 0x820C7958u;
	if (!UseLiftedCode(40, 0x82624F78)) { ctx.r3.u64 = fleeingTraversalAddr; __imp__sub_82624F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82624F78);
	uint32_t stack = ctx.r1.u64;
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	stack = PushStackFrame(base, stack, 160);

	uint32_t firstNode = LOAD32(fleeingTraversal->m_34 + 8);
	if (firstNode == 0) {
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		return 0;
	}
	uint32_t record = LOAD32(firstNode + 8);
	uint32_t recordIndex = LOAD32(record);
	uint64_t sourcePositionAddr = uint64_t(recordIndex << 3) + uint64_t(fleeingTraversal->m_38);
	uint32_t sourceNode = LOAD32(uint32_t(sourcePositionAddr) + 4);

	// A C_820C793C object {vtable, record, this} on the stack, handed by address.
	STORE32(stack + 96, uint32_t(g_820C793C));
	STORE32(stack + 100, record);
	STORE32(stack + 104, fleeingTraversalAddr);
	ctx.r1.u64 = stack;
	ctx.r7.u64 = sourcePositionAddr;
	ctx.r8.u64 = recordIndex;
	ctx.r9.s64 = g_820C793C;
	n_sub_826243D8(ctx, base, uint64_t(stack) + 96, record);
	STORE32(stack + 96, uint32_t(g_820C86F8));

	// Insert the node's two values at the end of the m_3C list (position: no node) and keep its position.
	STORE32(stack + 80, listPosition_vtable);
	STORE32(stack + 84, 0);
	uint32_t targetList = fleeingTraversal->m_3C;
	uint32_t targetIndex = LOAD32(record);
	uint32_t insertedPosition = stack + 88;
	n_sub_82625AE0(ctx, base, insertedPosition, targetList, sourceNode + 4, stack + 80);
	STORE32((targetIndex << 3) + fleeingTraversal->m_40 + 4, LOAD32(insertedPosition + 4));

	// Remove the node from the m_34 list and clear its position there.
	uint32_t sourcePositions = fleeingTraversal->m_38;
	uint32_t sourceList = fleeingTraversal->m_34;
	STORE32(stack + 88, uint32_t(g_820C86F8));
	uint64_t removedPosition = uint64_t(LOAD32(record) << 3) + uint64_t(sourcePositions);
	LinkedList_Remove(ctx, base, sourceList, uint32_t(removedPosition));
	STORE32((LOAD32(record) << 3) + fleeingTraversal->m_38 + 4, 0);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = removedPosition;
	return record;
}
PROMOTED_ENTRY(40, sub_82624F78, 0x82624F78) { ctx.r3.u64 = CFleeingTraversal_PopEntry(ctx, base, ctx.r3.u32); }

uint64_t CFleeingTraversal_PopAndMoveEntry(CpuState& ctx, uint8_t* base, uint32_t fleeingTraversalAddr) {
	constexpr int32_t g_820C86F8 = int32_t(0x820C86F8);
	constexpr uint32_t C_820C793C_vtable = 0x820C793Cu;
	if (!UseLiftedCode(40, 0x82625068)) { ctx.r3.u64 = fleeingTraversalAddr; __imp__sub_82625068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82625068);
	uint32_t stack = ctx.r1.u64;
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	stack = PushStackFrame(base, stack, 160);

	uint32_t firstNode = LOAD32(fleeingTraversal->m_34 + 8);
	if (firstNode == 0) {
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		return 0;
	}
	uint32_t record = LOAD32(firstNode + 8);

	// A C_820C793C object {vtable, record, this} on the stack, handed by address.
	STORE32(stack + 88, C_820C793C_vtable);
	STORE32(stack + 92, record);
	STORE32(stack + 96, fleeingTraversalAddr);
	ctx.r1.u64 = stack;
	n_sub_826243D8(ctx, base, uint64_t(stack) + 88, record);
	STORE32(stack + 88, uint32_t(g_820C86F8));

	// Insert the node's two values into the m_3C list in score order and keep its position.
	uint32_t recordIndex = LOAD32(record);
	uint32_t sourceNode = LOAD32((recordIndex << 3) + fleeingTraversal->m_38 + 4);
	uint32_t nodeValues = sourceNode + 4;
	uint32_t insertedPosition = LinkedList_InsertSorted(ctx, base, stack + 80, fleeingTraversalAddr, fleeingTraversal->m_3C, nodeValues);
	STORE32((recordIndex << 3) + fleeingTraversal->m_40 + 4, LOAD32(insertedPosition + 4));

	// Remove the node from the m_34 list and clear its position there.
	STORE32(stack + 80, uint32_t(g_820C86F8));
	uint32_t sourcePositions = fleeingTraversal->m_38;
	uint32_t sourceList = fleeingTraversal->m_34;
	LinkedList_Remove(ctx, base, sourceList, (LOAD32(record) << 3) + sourcePositions);
	STORE32((LOAD32(record) << 3) + fleeingTraversal->m_38 + 4, 0);

	uint32_t secondValue = LOAD32(nodeValues + 8);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = 0;
	return secondValue;
}
PROMOTED_ENTRY(40, sub_82625068, 0x82625068) { ctx.r3.u64 = CFleeingTraversal_PopAndMoveEntry(ctx, base, ctx.r3.u32); }

uint64_t CFleeingTraversal_DebugDraw(CpuState& ctx, uint8_t* base, uint64_t fleeingTraversalAddr) {
	constexpr uint32_t drawLineHookPointer = 0x832FD9C8u;
	constexpr uint32_t drawPointHookPointer = 0x832FD9CCu;
	if (!UseLiftedCode(40, 0x82625750)) { ctx.r3.u64 = fleeingTraversalAddr; __imp__sub_82625750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82625750);
	uint64_t result = fleeingTraversalAddr;
	// The original leaves this value for the point hook: the caller's, then what the last hook left or the
	// owner of the last node's segment.
	uint64_t leftoverValue = ctx.r9.u64;
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	GameStackFrame stackFrame(ctx, base, 144);

	// Each node of a list: the point at +4 of its record (+8) and, when it has a segment (+12: index, owner), a
	// line between the points at +4 of two of the owner's 20-byte records (+24), chosen by its tables at +56 and +60.
	auto drawList = [&](uint32_t list, uint32_t pointRed, uint32_t pointGreen, uint32_t pointBlue,
	                    uint32_t lineRed, uint32_t lineGreen, uint32_t lineBlue) {
		for (uint32_t node = LOAD32(list + 8); node != 0; node = LOAD32(node + 20)) {
			uint32_t drawPoint = LOAD32(drawPointHookPointer);
			if (drawPoint != 0) {
				ctx.r3.u64 = uint64_t(LOAD32(node + 8)) + 4;
				ctx.r4.u64 = pointRed;
				ctx.r5.u64 = pointGreen;
				ctx.r6.u64 = pointBlue;
				ctx.r9.u64 = leftoverValue;
				ctx.r10.u64 = drawPoint;
				REX_CALL_INDIRECT_FUNC(drawPoint);
				result = ctx.r3.u64;
				leftoverValue = ctx.r9.u64;
			}
			uint32_t segment = LOAD32(node + 12);
			if (segment != 0) {
				uint32_t owner = LOAD32(segment + 4);
				leftoverValue = owner;
				uint32_t drawLine = LOAD32(drawLineHookPointer);
				if (drawLine != 0) {
					uint32_t segmentIndex = LOAD32(segment);
					uint32_t records = LOAD32(owner + 24);
					uint32_t startIndex = LOAD32(LOAD32(owner + 56) + segmentIndex * 4);
					uint32_t endIndex = LOAD32(LOAD32(owner + 60) + segmentIndex * 4);
					uint64_t startRecord = uint64_t(startIndex * 20) + records;
					uint64_t endRecord = uint64_t(endIndex * 20) + records;
					ctx.r3.u64 = startRecord + 4;
					ctx.r4.u64 = endRecord + 4;
					ctx.r5.u64 = lineRed;
					ctx.r6.u64 = lineGreen;
					ctx.r7.u64 = lineBlue;
					ctx.r8.u64 = records;
					ctx.r9.u64 = records;
					ctx.r10.u64 = endRecord;
					REX_CALL_INDIRECT_FUNC(drawLine);
					result = ctx.r3.u64;
					leftoverValue = ctx.r9.u64;
				}
			}
		}
	};

	drawList(fleeingTraversal->m_34, 92, 255, 92, 128, 255, 128);
	drawList(fleeingTraversal->m_3C, 255, 92, 92, 255, 128, 128);
	return result;
}
PROMOTED_ENTRY(40, sub_82625750, 0x82625750) { ctx.r3.u64 = CFleeingTraversal_DebugDraw(ctx, base, ctx.r3.u64); }

uint64_t CFleeingTraversal_CallVirtualMethod36(CpuState& ctx, uint8_t* base, uint64_t fleeingTraversalAddr) {
	if (!UseLiftedCode(89, 0x82C010C0)) { ctx.r3.u64 = fleeingTraversalAddr; __imp__sub_82C010C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C010C0);
	CFleeingTraversal* fleeingTraversal = GameObject<CFleeingTraversal>(base, fleeingTraversalAddr);
	uint32_t virtualMethod = LOAD32(uint32_t(fleeingTraversal->vtable) + 36);
	ctx.r3.u64 = fleeingTraversalAddr;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C010C0, 0x82C010C0) { ctx.r3.u64 = CFleeingTraversal_CallVirtualMethod36(ctx, base, ctx.r3.u64); }
