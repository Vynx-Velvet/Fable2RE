// CECTrigger (vtable 0x820033C8): methods of the class as readable C++.
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

uint64_t CECTrigger_HasEntity(CpuState& ctx, uint8_t* base, uint32_t triggerAddr, uint64_t entityHandle) {
	if (!UseLiftedCode(0, 0x8218AE80)) { ctx.r3.u64 = triggerAddr; ctx.r4.u64 = entityHandle; __imp__sub_8218AE80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218AE80);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	stack = PushStackFrame(base, stack, 112);

	const uint32_t handleToFind = (uint32_t)entityHandle;
	// r4 as callers see it after the return: the handle argument, or what the last release left there
	uint64_t callerR4 = entityHandle;
	uint64_t found = 0;
	uint32_t entry = LOAD32(uint32_t(trigger->m_38));

	while (entry != uint32_t(trigger->m_38)) {
		uint32_t entityRef = LOAD32(entry + 12);
		uint32_t entryHandle = 0;
		if (entityRef != 0) {
			entryHandle = LOAD32(entityRef);
			if (entryHandle == 0) {
				// the entry's entity is gone: release the handle it still keeps alive
				ctx.r1.u64 = stack;
				// state the callee may pass on
				EntityHandle_Release(ctx, base, (uint64_t)entry + 8);
				callerR4 = ctx.r4.u64;
			}
		}
		if (handleToFind == entryHandle) {
			found = 1;
			break;
		}
		// the release above may have changed the list: advancing from its end is an error
		if (entry == uint32_t(trigger->m_38)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		entry = LOAD32(entry);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;  // callers read r4 after the call
	return found;
}
PROMOTED_ENTRY(0, sub_8218AE80, 0x8218AE80) { ctx.r3.u64 = CECTrigger_HasEntity(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t CECTrigger_RemoveDarkAreaEntities(CpuState& ctx, uint8_t* base, uint64_t triggerAddr) {
	constexpr int32_t str_TXT_820E0F10_B_ = int32_t(0x820E0F10);
	if (!UseLiftedCode(0, 0x8218AF28)) { ctx.r3.u64 = triggerAddr; __imp__sub_8218AF28(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8218AF28);
	uint32_t stack = ctx.r1.u64;

	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	stack = PushStackFrame(base, stack, 192);

	// The trigger's entity handle list starts at +52; m_38 (+56) points to its end node, whose
	// next pointer is the first entry. stack+88/92 hold the iterator, read and written as one
	// big-endian 64 bit value (list in the high half, current node in the low half).
	const uint64_t listAddr = (int64_t)triggerAddr + 52;
	STORE32(stack + 80, (uint32_t)triggerAddr + 20);
	uint32_t listEnd = trigger->m_38;
	uint32_t iterList = (uint32_t)listAddr;
	STORE32(stack + 88, iterList);
	uint32_t node = LOAD32(listEnd);
	uint32_t result = (uint32_t)triggerAddr;

	STORE32(stack + 92, node);
	for (;;) {
		uint32_t currentEnd = LOAD32((uint32_t)listAddr + 4);
		if (iterList == 0 || iterList != (uint32_t)listAddr) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == currentEnd) break;
		// dereferencing the iterator: it must belong to a list and not be at its end
		if (iterList == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(iterList + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		// Node payload: an entity handle at +8; its second word (node+12) points to the cell
		// holding the entity, which is 0 once the entity is gone.
		uint32_t entityCell = LOAD32(node + 12);
		uint32_t entity = 0;
		if (entityCell != 0) {
			entity = LOAD32(entityCell);
			if (entity == 0) {
				ctx.r1.u64 = stack;
				ctx.r10.u64 = 0;  // state the callee may pass on
				EntityHandle_Release(ctx, base, (uint64_t)node + 8);
			}
		}

		ctx.r1.u64 = stack;
		result = CECTrigger_IsEntityInVolume(ctx, base, stack + 80, entity);
		if ((result & 0xFF) != 0) {
			if (node == LOAD32(iterList + 4)) {
				ppc_trap(ctx, base, 22);
			}
			node = LOAD32(node);
			STORE32(stack + 92, node);
			continue;
		}

		uint64_t idHolder = Component_GetId(ctx, base, stack + 96, triggerAddr);
		const uint64_t fnvOffsetBasis = (uint64_t)(int64_t)-2128871424 | 40389;
		uint64_t fieldHash = String_HashFnv1(ctx, base, (uint64_t)(int64_t)str_TXT_820E0F10_B_, fnvOffsetBasis);
		ctx.r4.u64 = fnvOffsetBasis;  // state the callee may pass on
		uint64_t idRef = IdRef_Get(ctx, base, idHolder);
		ctx.r7.u64 = fieldHash;  // state the callee may pass on
		uint32_t field = GameDB_FindFieldValueByKey(ctx, base, idRef, fieldHash, stack + 84);
		// r9 handed to the calls below: as the lookup left it, or whether the field value is 0
		uint64_t r9State = ctx.r9.u64;
		bool fieldSet = false;
		if (field != 0) {
			uint32_t fieldValue = LOAD32(field);
			r9State = (fieldValue == 0) ? 1 : 0;
			fieldSet = fieldValue != 0;
		}

		if (fieldSet) {
			if (node == LOAD32(iterList + 4)) {
				ppc_trap(ctx, base, 22);
			}
			uint32_t cell = LOAD32(node + 12);
			uint32_t currentEntity = 0;
			if (cell != 0) {
				currentEntity = LOAD32(cell);
				if (currentEntity == 0) {
					// state the callee may pass on
					EntityHandle_Release(ctx, base, (uint64_t)node + 8);
					r9State = ctx.r9.u64;
				}
			}
			// the callee reads r3 from the CPU state; r9 is state it may pass on
			n_sub_828BA620(ctx, base, currentEntity);
			r9State = ctx.r9.u64;
		}

		uint64_t iterPair = LOAD64(stack + 88);
		ctx.r9.u64 = r9State;  // state the callee may pass on
		result = EntityHandleList_EraseNode(ctx, base, stack + 104, listAddr, iterPair);
		STORE64(stack + 88, LOAD64(result));
		node = LOAD32(stack + 92);
		iterList = LOAD32(stack + 88);
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(0, sub_8218AF28, 0x8218AF28) { ctx.r3.u64 = CECTrigger_RemoveDarkAreaEntities(ctx, base, ctx.r3.u64); }

uint64_t CECTrigger_AddEntityFromHandleVector(CpuState& ctx, uint8_t* base, uint64_t triggerAddr) {
	if (!UseLiftedCode(0, 0x8218B0D0)) { ctx.r3.u64 = triggerAddr; __imp__sub_8218B0D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218B0D0);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t triggerContext = stack + 80;
	STORE32(triggerContext, uint32_t(triggerAddr + 20));

	// m_28/m_2C: begin/end of an array of 8-byte entity handles
	uint64_t result = triggerAddr;
	for (uint32_t i = 0, elementOffset = 0;; i++, elementOffset += 8) {
		uint32_t handlesBegin = trigger->m_28;
		if (handlesBegin == 0) break;
		uint32_t handlesEnd = trigger->m_2C;
		uint64_t byteSpan = (uint64_t)handlesEnd - handlesBegin;
		bool shiftCarry = ((int32_t)byteSpan < 0) & (((uint32_t)byteSpan & 0x7) != 0);
		if (i >= uint32_t((int32_t)byteSpan >> 3)) break;

		// bounds check of the element access, which re-reads the array start
		uint32_t checkedBegin = trigger->m_28;
		if (checkedBegin != 0) {
			byteSpan = (uint64_t)handlesEnd - checkedBegin;
			shiftCarry = ((int32_t)byteSpan < 0) & (((uint32_t)byteSpan & 0x7) != 0);
		}
		if (checkedBegin == 0 || i >= uint32_t((int32_t)byteSpan >> 3)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		// state the release and the lookup may pass on: r9 = byte span, xer.ca = carry of its shift
		// (the lookup gets them as the release left them when it runs)
		ctx.r9.u64 = byteSpan;
		ctx.xer.ca = shiftCarry;

		uint64_t elementAddr = (uint64_t)elementOffset + checkedBegin;
		uint32_t handlePtr = LOAD32((uint32_t)elementAddr + 4);
		uint64_t entityId = 0;
		if (handlePtr != 0) {
			uint32_t id = LOAD32(handlePtr);
			if (id != 0) {
				entityId = id;
			} else {
				ctx.r1.u64 = stack;
				ctx.r10.u64 = 0;  // state the callee may pass on
				EntityHandle_Release(ctx, base, elementAddr);
			}
		}

		ctx.r1.u64 = stack;
		result = CECTrigger_HasEntity(ctx, base, triggerAddr, entityId);
		if ((uint32_t(result) & 0xFF) == 0) {
			result = CECTrigger_IsEntityInVolume(ctx, base, triggerContext, entityId);
			if ((uint32_t(result) & 0xFF) != 0) {
				result = CECTrigger_AddEntity(ctx, base, triggerAddr, entityId);
				break;
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(0, sub_8218B0D0, 0x8218B0D0) { ctx.r3.u64 = CECTrigger_AddEntityFromHandleVector(ctx, base, ctx.r3.u64); }

uint64_t CECTrigger_UpdateEntityState(CpuState& ctx, uint8_t* base, uint64_t triggerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(0, 0x8218B1B0)) { ctx.r3.u64 = triggerAddr; __imp__sub_8218B1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218B1B0);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	uint64_t result = triggerAddr;

	stack = PushStackFrame(base, stack, 112);

	if (trigger->m_41 != 0) {
		ctx.r1.u64 = stack;
		EntityManager_RemoveInvalidEntities(ctx, base, triggerAddr);
		CECTrigger_RemoveDarkAreaEntities(ctx, base, triggerAddr);

		if (trigger->m_40 != 0) {
			result = CECTrigger_AddEntityFromHandleVector(ctx, base, triggerAddr);
		} else {
			// the search argument is a stack slot holding the address of the trigger's +20 member
			STORE32(stack + 80, (uint32_t)triggerAddr + 20);

			uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
			uint32_t rootChild = LOAD32(globalRoot + 12);
			uint32_t table = LOAD32(rootChild + 88);
			uint32_t tableSlot = LOAD32(table + 4);
			uint32_t searchObject = LOAD32(tableSlot + 12);

			// state the callee may pass on
			ctx.r7.u64 = tableSlot;
			ctx.r8.u64 = table;
			ctx.r9.u64 = rootChild;
			result = GameObject_FindEntityByContext(ctx, base, searchObject, stack + 80);

			const uint64_t foundEntity = result;
			if ((uint32_t)foundEntity != 0 && (LOAD8((uint32_t)foundEntity + 144) & 64) != 0) {
				result = CECTrigger_HasEntity(ctx, base, triggerAddr, foundEntity);
				if (((uint32_t)result & 0xFF) == 0) {
					result = CECTrigger_AddEntity(ctx, base, triggerAddr, foundEntity);
				}
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(0, sub_8218B1B0, 0x8218B1B0) { ctx.r3.u64 = CECTrigger_UpdateEntityState(ctx, base, ctx.r3.u64); }

uint64_t CECTrigger_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8ABC_B_ = int32_t(0x820C8ABC);
	if (!UseLiftedCode(62, 0x828B8888)) { ctx.r3.u64 = classNameString; __imp__sub_828B8888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B8888);
	uint32_t stack = ctx.r1.u64;
	uint64_t cStr = str_TXT_820C8ABC_B_;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, cStr, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(62, sub_828B8888, 0x828B8888) { ctx.r3.u64 = CECTrigger_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECTrigger_InitializeFromRecord(CpuState& ctx, uint8_t* base, uint64_t triggerAddr, uint64_t dbRecord) {
	constexpr int32_t str_TXT_820E0EA4_B_ = int32_t(0x820E0EA4);
	if (!UseLiftedCode(62, 0x828B8E48)) { ctx.r3.u64 = triggerAddr; ctx.r4.u64 = dbRecord; __imp__sub_828B8E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B8E48);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t subObject = trigger->m_4;
	ctx.r1.u64 = stack;
	uint64_t result = CECDoor_UpdateOpenStateForEntity(ctx, base, subObject, triggerAddr);
	subObject = trigger->m_4;
	STORE8(subObject + 144, uint8_t(LOAD8(subObject + 144) | 1));
	if ((uint32_t)dbRecord != 0) {
		uint64_t fieldHash = String_HashFnv1(ctx, base, str_TXT_820E0EA4_B_, 0xFFFFFFFF811C9DC5ULL);
		uint32_t primitiveTypeField = GameDB_FindFieldValue(ctx, base, dbRecord, fieldHash, 5);
		uint32_t TXT_820E0EA4_L_;
		if (primitiveTypeField != 0) {
			TXT_820E0EA4_L_ = LOAD32(primitiveTypeField);
		} else {
			TXT_820E0EA4_L_ = 0xFFFFFFFF;
		}
		uint64_t entry = operator_new(ctx, base, 36);
		if ((uint32_t)entry != 0) {
			STORE32((uint32_t)entry, TXT_820E0EA4_L_);
			STORE32((uint32_t)entry + 8, 0);
			STORE32((uint32_t)entry + 12, 0);
			STORE32((uint32_t)entry + 16, 0);
			STORE32((uint32_t)entry + 24, 0);
			STORE32((uint32_t)entry + 28, 0);
			STORE32((uint32_t)entry + 32, 0);
		} else {
			entry = 0;
		}
		result = SharedHandle_Assign_828BAE58(ctx, base, triggerAddr + 12, entry);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(62, sub_828B8E48, 0x828B8E48) { ctx.r3.u64 = CECTrigger_InitializeFromRecord(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECTrigger_LoadTriggerData(CpuState& ctx, uint8_t* base, uint64_t triggerAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_828BB170 = int32_t(0x828BB170);
	if (!UseLiftedCode(62, 0x828B9408)) { ctx.r3.u64 = triggerAddr; __imp__sub_828B9408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B9408);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	// r4 and xer.ca handed to the final release: as on entry unless the work below changes them
	uint64_t r4State = ctx.r4.u64;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 192);

	// The pointer at +12 (m_C) leads to an object with two arrays of 8-byte elements
	// (begin/end at +8/+12 and +24/+28); it is released and cleared at the end.
	const uint64_t dataSlot = (int64_t)triggerAddr + 12;
	// first word of the handle built on the game stack, written when it is set up and again before its release
	const uint32_t handleVtable = uint32_t(g_820F1664);

	if (LOAD32((uint32_t)dataSlot) != 0) {
		ctx.r1.u64 = stack;
		uint64_t allocation = operator_new(ctx, base, 64);
		uint64_t r9State = ctx.r9.u64;
		flags.ca = ctx.xer.ca;
		uint32_t newObject = 0;
		if ((uint32_t)allocation != 0) {
			uint32_t linkedObject = trigger->m_4;
			uint32_t dataFirstWord = LOAD32(LOAD32((uint32_t)dataSlot));
			newObject = TriggerData_Construct(ctx, base, allocation, linkedObject, dataFirstWord);
			r9State = ctx.r9.u64;
			flags.ca = ctx.xer.ca;
		}
		STORE32(stack + 80, newObject);

		// stack+80/84: the new object and its 12-byte count block {1, function 0x828BB170, object}
		uint32_t countBlock = 0;
		if (newObject != 0) {
			countBlock = (uint32_t)operator_new(ctx, base, 12);
			r9State = ctx.r9.u64;
			flags.ca = ctx.xer.ca;
			if (countBlock != 0) {
				STORE32(countBlock + 8, newObject);
				STORE32(stack + 84, countBlock);
				r9State = (uint64_t)(int64_t)g_828BB170;
				STORE32(countBlock, 1);
				STORE32(countBlock + 4, uint32_t(g_828BB170));
			}
		}
		if (countBlock == 0) {
			STORE32(stack + 84, 0);
		}

		ctx.r9.u64 = r9State;  // state the callee may pass on
		SharedPtrVector_PushBack(ctx, base, triggerAddr + 20, stack + 80);
		flags.ca = ctx.xer.ca;
		SharedHandle_Release(ctx, base, stack + 80);
		r9State = ctx.r9.u64;
		flags.ca = ctx.xer.ca;

		uint32_t data = LOAD32((uint32_t)dataSlot);
		uint32_t firstBegin = LOAD32(data + 8);
		uint64_t firstCount = 0;
		if (firstBegin != 0) {
			uint64_t byteSpan = (uint64_t)LOAD32(data + 12) - firstBegin;
			flags.ca = ((int32_t)byteSpan < 0) & (((uint32_t)byteSpan & 0x7) != 0);
			firstCount = (uint64_t)(int64_t)((int32_t)byteSpan >> 3);
			r9State = byteSpan;
		}

		const uint64_t handleVectorAddr = (int64_t)triggerAddr + 36;
		// state the callee may pass on
		ctx.r9.u64 = r9State;
		ctx.xer.ca = flags.ca;
		EntityHandleVector_Clear(ctx, base, handleVectorAddr);
		flags.ca = ctx.xer.ca;
		EntityHandleVector_Reserve(ctx, base, handleVectorAddr, firstCount, ctx.r8.u64);
		r4State = ctx.r4.u64;
		flags.ca = ctx.xer.ca;

		// r6/r7/r8 handed to the lookups start as this chain of objects and then follow
		// what the calls leave in them
		uint64_t r8State = LOAD32(LOAD32(0x83496920u) + 12);
		uint64_t r7State = LOAD32((uint32_t)r8State + 88);
		uint64_t r6State = LOAD32((uint32_t)r7State + 4);
		const uint32_t lookupContext = LOAD32((uint32_t)r6State);

		// first array: elements that resolve to an entity with bit 0x40 set at +144 go to the handle vector at +36
		if ((int32_t)firstCount > 0) {
			uint32_t i = 0;
			uint64_t offset = 0;
			do {
				uint32_t dataNow = LOAD32((uint32_t)dataSlot);
				uint32_t begin = LOAD32(dataNow + 8);
				uint64_t r10State = dataNow;
				if (begin != 0) {
					uint64_t byteSpan = (uint64_t)LOAD32(dataNow + 12) - begin;
					flags.ca = ((int32_t)byteSpan < 0) & (((uint32_t)byteSpan & 0x7) != 0);
					r10State = (uint64_t)(int64_t)((int32_t)byteSpan >> 3);
				}
				if (begin == 0 || i >= (uint32_t)r10State) {
					ppc_trap(ctx, base, 22);
				}

				// state the callee may pass on
				ctx.xer.ca = flags.ca;
				uint64_t entity = EntityManager_LookupEntity(ctx, base, lookupContext, offset + begin);
				r6State = ctx.r6.u64;
				r7State = ctx.r7.u64;
				r8State = ctx.r8.u64;
				r4State = entity;

				uint32_t flagBit = 0;
				if ((uint32_t)entity != 0) {
					flagBit = LOAD8((uint32_t)entity + 144) & 64;
				}
				if (flagBit != 0) {
					STORE32(stack + 80, handleVtable);
					STORE32(stack + 84, 0);
					ctx.r10.u64 = flagBit;  // state the callee may pass on
					EntityHandle_SetTarget(ctx, base, stack + 80, entity);
					flags.ca = ctx.xer.ca;
					EntityHandleVector_PushBack(ctx, base, handleVectorAddr, stack + 80);
					flags.ca = ctx.xer.ca;
					STORE32(stack + 80, handleVtable);
					EntityHandle_Release(ctx, base, stack + 80);
					r4State = ctx.r4.u64;
					r6State = ctx.r6.u64;
					r7State = ctx.r7.u64;
					r8State = ctx.r8.u64;
					flags.ca = ctx.xer.ca;
					STORE32(stack + 84, 0);
				}
				i = i + 1;
				offset = offset + 8;
			} while ((int32_t)i < (int32_t)firstCount);
		}

		const uint64_t entityListAddr = (int64_t)triggerAddr + 52;
		// state the callee may pass on
		List_ClearRefCountedHandleNodes(ctx, base, entityListAddr);
		r4State = ctx.r4.u64;
		flags.ca = ctx.xer.ca;

		data = LOAD32((uint32_t)dataSlot);
		uint32_t secondBegin = LOAD32(data + 24);
		uint64_t secondCount = 0;
		if (secondBegin != 0) {
			uint64_t byteSpan = (uint64_t)LOAD32(data + 28) - secondBegin;
			flags.ca = ((int32_t)byteSpan < 0) & (((uint32_t)byteSpan & 0x7) != 0);
			secondCount = (uint64_t)(int64_t)((int32_t)byteSpan >> 3);
		}

		// second array: elements that resolve to such an entity are inserted into the entity list at +52
		if ((int32_t)secondCount > 0) {
			uint32_t j = 0;
			uint64_t offset = 0;
			do {
				uint32_t dataNow = LOAD32((uint32_t)dataSlot);
				uint32_t begin = LOAD32(dataNow + 24);
				uint64_t r10State = dataNow;
				if (begin != 0) {
					uint64_t byteSpan = (uint64_t)LOAD32(dataNow + 28) - begin;
					flags.ca = ((int32_t)byteSpan < 0) & (((uint32_t)byteSpan & 0x7) != 0);
					r10State = (uint64_t)(int64_t)((int32_t)byteSpan >> 3);
				}
				if (begin == 0 || j >= (uint32_t)r10State) {
					ppc_trap(ctx, base, 22);
				}

				// state the callee may pass on
				ctx.xer.ca = flags.ca;
				uint64_t entity = EntityManager_LookupEntity(ctx, base, lookupContext, offset + begin);
				r4State = entity;

				uint32_t flagBit = 0;
				if ((uint32_t)entity != 0) {
					flagBit = LOAD8((uint32_t)entity + 144) & 64;
				}
				if (flagBit != 0) {
					STORE32(stack + 80, handleVtable);
					STORE32(stack + 84, 0);
					ctx.r10.u64 = flagBit;  // state the callee may pass on
					EntityHandle_SetTarget(ctx, base, stack + 80, entity);
					flags.ca = ctx.xer.ca;

					// insert before the list's end node: iterator {list, end node} at stack+88
					uint32_t endNode = LOAD32((uint32_t)entityListAddr + 4);
					STORE32(stack + 88, (uint32_t)entityListAddr);
					STORE32(stack + 92, endNode);
					List_InsertNodeWithCopyConstruct(ctx, base, entityListAddr, LOAD64(stack + 88), stack + 80);
					flags.ca = ctx.xer.ca;

					STORE32(stack + 80, handleVtable);
					EntityHandle_Release(ctx, base, stack + 80);
					r4State = ctx.r4.u64;
					flags.ca = ctx.xer.ca;
					STORE32(stack + 84, 0);
				}
				j = j + 1;
				offset = offset + 8;
			} while ((int32_t)j < (int32_t)secondCount);
		}
	}

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = r4State;
	ctx.xer.ca = flags.ca;
	uint64_t result = SharedHandle_Release(ctx, base, dataSlot);
	STORE32((uint32_t)dataSlot, 0);
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(62, sub_828B9408, 0x828B9408) { ctx.r3.u64 = CECTrigger_LoadTriggerData(ctx, base, ctx.r3.u64); }

uint64_t CECTrigger_InitializeDarkArea(CpuState& ctx, uint8_t* base, uint64_t triggerAddr) {
	constexpr int32_t str_TXT_820E0F10_B_ = int32_t(0x820E0F10);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(62, 0x828B96C8)) { ctx.r3.u64 = triggerAddr; __imp__sub_828B96C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B96C8);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t result = triggerAddr;
	if (trigger->m_41 == 0) {
		ctx.r1.u64 = stack;
		uint64_t idHolder = Component_GetId(ctx, base, (uint64_t)stack + 80, triggerAddr);
		uint64_t idRef = IdRef_Get(ctx, base, idHolder);
		result = GameDB_ReadBoolField_82303F38(ctx, base, idRef, (uint64_t)(int64_t)str_TXT_820E0F10_B_);
		if (((uint32_t)result & 0xFF) != 0) {
			uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
			uint32_t table = LOAD32(LOAD32(globalRoot + 12) + 88);
			uint32_t tableSlot = LOAD32(table + 4);
			uint32_t entityHandle = LOAD32(tableSlot);
			// state the callee may pass on
			ctx.r8.u64 = tableSlot;
			ctx.r9.u64 = table;
			uint64_t entity = EntityHandle_Get(ctx, base, entityHandle);
			result = CECTrigger_SetTargetEntity(ctx, base, triggerAddr, entity);
			if (trigger->m_41 != 1) {
				trigger->m_41 = uint8_t(1);
			}
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(62, sub_828B96C8, 0x828B96C8) { ctx.r3.u64 = CECTrigger_InitializeDarkArea(ctx, base, ctx.r3.u64); }

// Sets m_40 (and m_41 unless the byte at +65 is 1). A flagged target entity that HandleVector_Find does not
// find in the handle vector at +36 gets a handle, which goes to EntityHandleVector_PushBack with that vector.
uint64_t CECTrigger_SetTargetEntity(CpuState& ctx, uint8_t* base, uint64_t triggerAddr, uint64_t targetEntity) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(62, 0x828B9788)) { ctx.r3.u64 = triggerAddr; ctx.r4.u64 = targetEntity; __imp__sub_828B9788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B9788);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);
	stack = PushStackFrame(base, stack, 160);

	uint64_t result = triggerAddr;
	uint64_t callerR4 = targetEntity;
	uint64_t handleVector = triggerAddr + 36;

	STORE32(stack + 188, (uint32_t)targetEntity);
	trigger->m_40 = 1;

	if ((uint32_t)targetEntity != 0 && (LOAD8((uint32_t)targetEntity + 144) & 64) != 0) {
		uint32_t vectorEnd = trigger->m_2C;
		if (LOAD32((uint32_t)handleVector + 4) > vectorEnd) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
		if (LOAD32((uint32_t)handleVector + 4) > LOAD32((uint32_t)handleVector + 8)) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }

		uint32_t firstEntry = LOAD32((uint32_t)handleVector + 4);
		uint32_t lastEntry = LOAD32((uint32_t)handleVector + 8);
		STORE32(stack + 80, (uint32_t)handleVector);
		STORE32(stack + 84, lastEntry);
		if (firstEntry > lastEntry) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
		STORE32(stack + 88, (uint32_t)handleVector);
		STORE32(stack + 92, firstEntry);

		uint64_t beginIter = LOAD64(stack + 88);
		uint64_t endIter = LOAD64(stack + 80);

		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r9.u64 = lastEntry;
		result = HandleVector_Find(ctx, base, stack + 96, beginIter, endIter, stack + 188);
		callerR4 = ctx.r4.u64;

		uint32_t iterOwner = LOAD32((uint32_t)result);
		if (iterOwner == 0 || iterOwner != (uint32_t)handleVector) {
			ppc_trap(ctx, base, 22);
		}

		// the target is not in the vector yet
		if (LOAD32((uint32_t)result + 4) == vectorEnd) {
			uint64_t entityHandleVtable = g_820F1664;
			STORE32(stack + 84, 0);
			STORE32(stack + 80, (uint32_t)entityHandleVtable);
			ctx.r9.u64 = entityHandleVtable;
			EntityHandle_SetTarget(ctx, base, stack + 80, targetEntity);

			EntityHandleVector_PushBack(ctx, base, handleVector, stack + 80);

			// the same vtable address, rebuilt from its high half
			uint32_t releaseVtable = (uint32_t)((int64_t)g_820F0000 + 5732);
			STORE32(stack + 80, releaseVtable);
			result = EntityHandle_Release(ctx, base, stack + 80);
			callerR4 = ctx.r4.u64;
		}
	}

	if (LOAD8((uint32_t)triggerAddr + 65) != 1) {
		trigger->m_41 = 1;
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(62, sub_828B9788, 0x828B9788) { ctx.r3.u64 = CECTrigger_SetTargetEntity(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// For a flagged target, looks in the handle vector (m_28..m_2C) for a flagged entity whose words at +20/+24
// equal the target's, then returns 1 if that entity is found in the list at +52 (head node m_38), else 0.
uint64_t CECTrigger_IsTargetInList(CpuState& ctx, uint8_t* base, uint32_t triggerAddr, uint64_t targetEntity) {
	if (!UseLiftedCode(62, 0x828B9A40)) { ctx.r3.u64 = triggerAddr; ctx.r4.u64 = targetEntity; __imp__sub_828B9A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B9A40);
	uint32_t stack = ctx.r1.u64;
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);

	uint32_t target = (uint32_t)targetEntity;
	uint64_t callerR4 = targetEntity;
	uint8_t carry = ctx.xer.ca;
	stack = PushStackFrame(base, stack, 144);

	bool matchFound = false;
	if (target != 0 && (LOAD8(target + 144) & 64) != 0 &&
	    trigger->m_40 != 0 && trigger->m_41 != 0) {
		for (uint32_t index = 0;; ++index) {
			uint32_t handleArray = trigger->m_28;
			if (handleArray == 0) break;
			uint64_t arrayBytes = (uint64_t)(uint32_t)trigger->m_2C - handleArray;
			int32_t handleCount = (int32_t)arrayBytes >> 3;
			carry = (int32_t)arrayBytes < 0 && (arrayBytes & 7) != 0;
			if (index >= (uint32_t)handleCount) break;

			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r4.u64 = callerR4;
			ctx.r9.u64 = arrayBytes;
			ctx.r10.u64 = (uint64_t)(int64_t)handleCount;
			ctx.xer.ca = carry;
			uint32_t entity = EntityHandle_Get_825575C8(ctx, base, (uint64_t)index * 8 + handleArray);
			callerR4 = ctx.r4.u64;
			carry = ctx.xer.ca;
			STORE32(stack + 80, entity);
			if (entity != 0 && (LOAD8(entity + 144) & 64) != 0 &&
			    LOAD32(entity + 20) == LOAD32(target + 20) &&
			    LOAD32(entity + 24) == LOAD32(target + 24)) {
				matchFound = true;
				break;
			}
		}
	}

	if (!matchFound) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		// callers read r4 and the carry flag after the call
		ctx.r4.u64 = callerR4;
		ctx.xer.ca = carry;
		return 0;
	}

	uint32_t listHead = trigger->m_38;
	uint32_t listAddr = triggerAddr + 52;
	STORE32(stack + 88, listAddr);
	STORE32(stack + 92, listHead);
	uint32_t firstNode = LOAD32(listHead);
	STORE32(stack + 96, listAddr);
	STORE32(stack + 100, firstNode);

	uint64_t endIter = LOAD64(stack + 88);
	uint64_t beginIter = LOAD64(stack + 96);
	// state the callee may pass on
	ctx.r9.u64 = firstNode;
	uint32_t foundIter = List_FindValue(ctx, base, stack + 96, beginIter, endIter, stack + 80);

	uint32_t iterOwner = LOAD32(foundIter);
	if (iterOwner == 0 || iterOwner != listAddr) {
		ppc_trap(ctx, base, 22);
	}
	bool inList = LOAD32(foundIter + 4) != listHead;

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r8 after the call
	ctx.r8.u64 = inList ? 0 : 1;
	return inList ? 1 : 0;
}
PROMOTED_ENTRY(62, sub_828B9A40, 0x828B9A40) { ctx.r3.u64 = CECTrigger_IsTargetInList(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// When the trigger's game-database bool str_TXT_820E0F10_B_ is set: resolves the entity handle reached from the
// global object at 0x83496920 and, when CECTrigger_IsTargetInList reports a match for that entity, calls n_sub_828BA620.
uint64_t CECTrigger_ProcessDarkArea(CpuState& ctx, uint8_t* base, uint64_t triggerAddr) {
	constexpr int32_t str_TXT_820E0F10_B_ = int32_t(0x820E0F10);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(62, 0x828BA1B0)) { ctx.r3.u64 = triggerAddr; __imp__sub_828BA1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828BA1B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	uint64_t refSlot = Component_GetId(ctx, base, stack + 80, triggerAddr);
	uint64_t idRef = IdRef_Get(ctx, base, refSlot);
	uint64_t result = GameDB_ReadBoolField_82303F38(ctx, base, idRef, str_TXT_820E0F10_B_);
	if (uint32_t(result & 0xFF) != 0) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t handleOwner = LOAD32(LOAD32(globalRoot + 12) + 88);
		uint32_t handleSlot = LOAD32(handleOwner + 4);
		uint32_t handle = LOAD32(handleSlot);
		// state the callee may pass on
		ctx.r8.u64 = handleSlot;
		ctx.r9.u64 = handleOwner;
		uint64_t entityResult = EntityHandle_Get(ctx, base, handle);
		result = entityResult;
		uint32_t entity = (uint32_t)entityResult;
		if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
			// the full 64-bit result goes on to both calls, as in the original
			result = CECTrigger_IsTargetInList(ctx, base, triggerAddr, entityResult);
			if (uint32_t(result & 0xFF) != 0) {
				result = n_sub_828BA620(ctx, base, entityResult);
			}
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(62, sub_828BA1B0, 0x828BA1B0) { ctx.r3.u64 = CECTrigger_ProcessDarkArea(ctx, base, ctx.r3.u64); }

// Runs once (guard byte at 0x834BE89C): passes the 12-byte elements of the array at 0x8349C1F4 two at a time
// to C_820A64F4_Initialize as vectors, then passes a value read through the result of a virtual call on the global
// object at 0x83496920 to EffectManager_AddEffect and destroys the temporary C_820A64F4 object.
uint64_t n_sub_828BA278(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_8349C1F4 = int32_t(0x8349C1F4);
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	if (!UseLiftedCode(62, 0x828BA278)) { __imp__sub_828BA278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828BA278);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	uint64_t result = ctx.r3.u64;

	stack = PushStackFrame(base, stack, 208);

	uint32_t onceFlag = uint32_t(g_834C0000) - 5988;
	if (LOAD8(onceFlag) == 0) {
		uint32_t arrayDesc = uint32_t(g_8349C1F4);
		uint32_t begin = LOAD32(arrayDesc + 4);
		if (begin != 0) {
			uint32_t end = LOAD32(arrayDesc + 8);
			if ((int32_t)(end - begin) / 12 != 0) {
				uint64_t argR8 = g_820A0000;      // 0xFFFFFFFF820A0000
				uint64_t argR7 = 16;
				uint64_t argR6 = argR8 + 25844;   // 0xFFFFFFFF820A64F4
				float fillValue = LOAD_F32(0x820994B4u);
				uint32_t index = 0;
				uint32_t offset = 0;
				uint32_t fillPtr = stack + 80;
				// temporary C_820A64F4 object (vtable at +0), destroyed at the end
				uint32_t tempObject = stack + 96;

				STORE8(stack + 120, 0xFF);
				STORE8(stack + 121, 0xFF);
				STORE8(stack + 122, 0xFF);
				STORE8(stack + 123, 0xFF);
				STORE8(stack + 124, 0);
				STORE32(stack + 96, uint32_t(argR6));
				STORE32(stack + 100, uint32_t(argR7));
				STORE32(stack + 108, 0);
				STORE32(stack + 112, 0);
				STORE32(stack + 116, 0);

				PPCVRegister v1{}, v2{}, v12{}, v13{}, tmp{};

				while (begin != 0) {
					uint32_t count = uint32_t((int32_t)(end - begin) / 12);
					if (index >= count) break;

					// first element of the pair (index)
					uint32_t elemPtr = offset + begin;
					scratch.u32 = elemPtr;
					SET_V8(v1, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					ctx.fpscr.disableFlushMode();
					STORE_F32(stack + 80, fillValue);
					uint32_t nextIndex = index + 1;
					scratch.u32 = elemPtr + 4;
					SET_V8(tmp, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					scratch.u32 = elemPtr + 8;
					SET_V8(v13, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					SET_VF(v1, simde_mm_blend_ps(VF(v1), simde_mm_permute_ps(VF(tmp), 57), 4));
					scratch.u32 = fillPtr;
					SET_V8(v12, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					SET_VF(v13, simde_mm_blend_ps(VF(v13), simde_mm_permute_ps(VF(v12), 57), 4));
					SET_VF(v1, simde_mm_blend_ps(VF(v1), simde_mm_permute_ps(VF(v13), 78), 3));
					if (nextIndex >= count) {
						ctx.r1.u64 = stack;
						ppc_trap(ctx, base, 22);
					}

					// second element of the pair (index + 1)
					uint32_t nextElemPtr = elemPtr + 12;
					ctx.fpscr.disableFlushMode();
					STORE_F32(stack + 80, fillValue);
					scratch.u32 = fillPtr;
					SET_V8(tmp, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					scratch.u32 = nextElemPtr + 4;
					SET_V8(v13, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					scratch.u32 = nextElemPtr;
					SET_V8(v2, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					scratch.u32 = nextElemPtr + 8;
					SET_V8(v12, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					SET_VF(v2, simde_mm_blend_ps(VF(v2), simde_mm_permute_ps(VF(v13), 57), 4));
					SET_VF(v12, simde_mm_blend_ps(VF(v12), simde_mm_permute_ps(VF(tmp), 57), 4));
					SET_VF(v2, simde_mm_blend_ps(VF(v2), simde_mm_permute_ps(VF(v12), 78), 3));

					// state the callee may pass on
					ctx.r1.u64 = stack;
					ctx.v1 = v1;
					ctx.v2 = v2;
					ctx.v12 = v12;
					ctx.v13 = v13;
					C_820A64F4_Initialize(ctx, base, tempObject);
					argR6 = ctx.r6.u64;
					argR7 = ctx.r7.u64;
					argR8 = ctx.r8.u64;

					end = LOAD32(arrayDesc + 8);
					begin = LOAD32(arrayDesc + 4);
					index += 2;
					offset += 24;
				}

				// vtable slot 5 of the global object
				uint32_t globalObj = LOAD32(0x83496920u);
				uint32_t vtablePtr = LOAD32(globalObj);
				uint32_t vfunc = LOAD32(vtablePtr + 20);
				PPCRegister callTarget{};
				callTarget.u64 = uint64_t(vfunc);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = globalObj;
				ctx.r6.u64 = argR6;
				ctx.r7.u64 = argR7;
				ctx.r8.u64 = argR8;
				ctx.r9.u64 = vfunc;
				ctx.r10.u64 = vtablePtr;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				uint64_t callResult = ctx.r3.u64;
				uint32_t resultInner = LOAD32(uint32_t(callResult) + 4);
				uint32_t innerValue = LOAD32(resultInner);
				// state the callee may pass on
				ctx.r7.u64 = resultInner;
				ctx.r8.u64 = callResult;
				EffectManager_AddEffect(ctx, base, tempObject, innerValue, 1);
				result = C_820A64F4_Destructor(ctx, base, tempObject);
			}
		}
		STORE8(onceFlag, 1);
	}

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(62, sub_828BA278, 0x828BA278) { ctx.r3.u64 = n_sub_828BA278(ctx, base); }

// Passes a stack buffer to a virtual call (vtable +64) on the object at +124 of the entity at m_4, posts that
// buffer with MessageEvents_PostMessageEvent for the m_4 entity and the given entity, calls CECTrigger_AddEntityLightRef when
// the trigger's game-database bool str_TXT_820E0F10_B_ is set, and inserts a handle to the entity into the list at +52.
uint64_t CECTrigger_AddEntity(CpuState& ctx, uint8_t* base, uint64_t triggerAddr, uint64_t entity) {
	constexpr int32_t str_TXT_820E0F10_B_ = int32_t(0x820E0F10);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(62, 0x828BA3F8)) { ctx.r3.u64 = triggerAddr; ctx.r4.u64 = entity; __imp__sub_828BA3F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828BA3F8);
	uint32_t stack = ctx.r1.u64;

	PPCRegister callTarget{};
	CECTrigger* trigger = GameObject<CECTrigger>(base, triggerAddr);

	stack = PushStackFrame(base, stack, 160);
	uint32_t eventBuffer = stack + 96;

	uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t rootChild = LOAD32(globalRoot + 12);
	uint32_t handleOwner = LOAD32(rootChild + 88);
	uint32_t handleSlot = LOAD32(handleOwner + 4);
	uint32_t postTarget = LOAD32(handleSlot + 16);

	uint32_t ownerEntity = trigger->m_4;
	uint32_t ownerComponent = LOAD32(ownerEntity + 124);
	uint32_t componentVtable = LOAD32(ownerComponent);
	uint32_t method = LOAD32(componentVtable + 64);

	callTarget.u64 = (uint64_t)method;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = eventBuffer;
	ctx.r4.u64 = ownerComponent;
	ctx.r6.u64 = handleSlot;
	ctx.r7.u64 = method;
	ctx.r8.u64 = handleOwner;
	ctx.r9.u64 = componentVtable;
	ctx.r10.u64 = rootChild;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	MessageEvents_PostMessageEvent(ctx, base, postTarget, 26, eventBuffer, ownerEntity, entity, 101, 0);

	uint64_t refSlot = Component_GetId(ctx, base, stack + 88, triggerAddr);
	uint64_t idRef = IdRef_Get(ctx, base, refSlot);
	if (uint32_t(GameDB_ReadBoolField_82303F38(ctx, base, idRef, str_TXT_820E0F10_B_) & 0xFF) != 0) {
		// the original hands over the low 32 bits of the trigger address
		CECTrigger_AddEntityLightRef(ctx, base, (uint32_t)entity);
	}

	uint32_t tempHandle = stack + 80;
	uint64_t entityHandleVtable = g_820F1664;
	STORE32(stack + 84, 0);
	STORE32(stack + 80, uint32_t(entityHandleVtable));
	ctx.r9.u64 = entityHandleVtable;
	EntityHandle_SetTarget(ctx, base, tempHandle, entity);

	uint32_t listAddr = triggerAddr + 52;
	uint32_t listHead = trigger->m_38;
	STORE32(stack + 88, listAddr);
	STORE32(stack + 92, listHead);
	ctx.r8.u64 = listHead;
	List_InsertNodeWithCopyConstruct(ctx, base, listAddr, LOAD64(stack + 88), tempHandle);

	// the same vtable address, rebuilt from its high half
	uint32_t vtableHigh = uint32_t(g_820F0000);
	uint32_t releaseVtable = vtableHigh + 5732;
	STORE32(stack + 80, releaseVtable);
	uint64_t result = EntityHandle_Release(ctx, base, tempHandle);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(62, sub_828BA3F8, 0x828BA3F8) { ctx.r3.u64 = CECTrigger_AddEntity(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// When bit 1 of the word at +0x28 is set, passes Light_AddRef the value word of one of the entity's sorted
// 8-byte {key, value} records (+0x48..+0x4C): the one indexed by the byte at +0x21 of the object at +0x8C when
// that pointer is set, else the record with key 33 (with none, the word at end + 4 is read).
// Returns Light_AddRef's result, or the incoming r3 when the bit is clear.
uint32_t CECTrigger_AddEntityLightRef(CpuState& ctx, uint8_t* base, uint32_t entityAddr) {
	if (!UseLiftedCode(62, 0x828BA4F0)) { ctx.r4.u64 = entityAddr; __imp__sub_828BA4F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828BA4F0);
	uint32_t stack = ctx.r1.u64;
	uint32_t result = ctx.r3.u32;
	uint64_t r8Value = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 96);

	if ((LOAD32(entityAddr + 0x28) >> 1) & 1) {
		uint32_t recordsBegin = LOAD32(entityAddr + 0x48);
		uint32_t directLookup = LOAD32(entityAddr + 0x8C);
		uint32_t recordValue;
		if (directLookup != 0) {
			// the byte at +0x21 is the record's index
			uint32_t record = recordsBegin + (uint32_t)LOAD8(directLookup + 0x21) * 8;
			recordValue = LOAD32(record + 4);
		} else {
			// lower bound for key 33
			uint32_t recordsEnd = LOAD32(entityAddr + 0x4C);
			uint32_t record = recordsBegin;
			STORE32(stack + 84, recordsBegin);
			uint32_t byteCount = recordsEnd - recordsBegin;
			STORE32(stack + 80, 0u);
			flags.ca = ((int32_t)byteCount < 0) & ((byteCount & 7) != 0);
			int32_t remaining = (int32_t)byteCount >> 3;
			if (remaining > 0) {
				do {
					flags.ca = (remaining < 0) & ((remaining & 1) != 0);
					int32_t half = remaining >> 1;
					uint32_t halfOffset = (uint32_t)half << 3;
					r8Value = halfOffset;
					record += halfOffset;
					if ((int32_t)LOAD32(record) < 33) {
						remaining = remaining - half - 1;
						record += 8;
					} else {
						record -= halfOffset;
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, record);
			}
			if (record != recordsEnd && (int32_t)LOAD32(record) <= 33) {
				STORE64(stack + 80, LOAD64(stack + 80));
				recordValue = LOAD32(record + 4);
			} else {
				recordValue = LOAD32(recordsEnd + 4);
			}
		}

		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = Light_AddRef(ctx, base, recordValue);
		r8Value = ctx.r8.u64;
		flags.ca = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r8 and the carry flag after the call
	ctx.r8.u64 = r8Value;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(62, sub_828BA4F0, 0x828BA4F0) { ctx.r3.u64 = CECTrigger_AddEntityLightRef(ctx, base, ctx.r4.u32); }
