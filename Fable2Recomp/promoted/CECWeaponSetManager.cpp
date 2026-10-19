// CECWeaponSetManager (vtable 0x82004298): methods of the class as readable C++.
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

uint64_t CECWeaponSetManager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820B5498_B_ = int32_t(0x820B5498);
	if (!UseLiftedCode(27, 0x8248F7E8)) { ctx.r3.u64 = classNameString; __imp__sub_8248F7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8248F7E8);
	uint32_t stack = ctx.r1.u64;
	const uint64_t classNameCStr = str_TXT_820B5498_B_;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameCStr, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(27, sub_8248F7E8, 0x8248F7E8) { ctx.r3.u64 = CECWeaponSetManager_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_824914D8(CpuState& ctx, uint8_t* base, uint64_t weaponSetManagerAddr) {
	constexpr int32_t str_TXT_820A3760_B_ = int32_t(0x820A3760);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(27, 0x824914D8)) { ctx.r3.u64 = weaponSetManagerAddr; __imp__sub_824914D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824914D8);
	uint32_t stack = ctx.r1.u64;
	CECWeaponSetManager* weaponSetManager = GameObject<CECWeaponSetManager>(base, weaponSetManagerAddr);
	stack = PushStackFrame(base, stack, 288);

	const uint32_t managerAddr = (uint32_t)weaponSetManagerAddr;
	const uint32_t weaponSetAddr = managerAddr + 28;              // set of weapon keys already handled
	const uint32_t emptyEntityTag = uint32_t(g_820F1664);
	const uint64_t weaponName = (uint64_t)(int64_t)str_TXT_820A3760_B_;
	PPCRegister callTarget{};
	// return value: the parameter itself unless the walk runs, then the list iterator
	uint64_t result = weaponSetManagerAddr;

	if (LOAD32(managerAddr + 24) != 0) {
		uint32_t treeRoot = weaponSetManager->m_14;
		uint32_t node = LOAD32(treeRoot);
		if (node != treeRoot) {
			if (node == LOAD32(managerAddr + 20)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint32_t listHeader = LOAD32(node + 20);
			uint32_t listRefAddr = node + 16;
			uint32_t listRef = listRefAddr;
			STORE32(stack + 104, listRef);
			uint32_t current = LOAD32(listHeader);
			STORE32(stack + 108, current);

			for (;;) {
				if (listRef != listRefAddr) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				if (current == listHeader) break;
				if (current == LOAD32(listRef + 4)) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}

				uint32_t weaponKeyAddr = current + 12;
				ctx.r1.u64 = stack;
				n_sub_82496DE0(ctx, base, stack + 120, weaponSetAddr, weaponKeyAddr);

				uint32_t setEnd = weaponSetManager->m_20;
				uint32_t setOwner = LOAD32(stack + 120);
				if (setOwner != weaponSetAddr) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				uint32_t foundNode = LOAD32(stack + 124);

				// skip this weapon if the bound entity has flag 0x40
				bool skipIteration = false;
				if (foundNode != setEnd) {
					if (setOwner == 0 || foundNode == LOAD32(setOwner + 4)) {
						ctx.r1.u64 = stack;
						ppc_trap(ctx, base, 22);
					}
					uint32_t handleAddr = foundNode + 16;
					uint32_t handleTarget = LOAD32(handleAddr + 4);
					if (handleTarget != 0) {
						uint32_t targetFirst = LOAD32(handleTarget);
						if (targetFirst == 0) {
							ctx.r10.u64 = targetFirst;
							ctx.r1.u64 = stack;
							EntityHandle_Release(ctx, base, handleAddr);
						} else {
							ctx.r10.u64 = targetFirst;
							ctx.r1.u64 = stack;
							uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
							skipIteration = (LOAD8(entity + 144) & 64) != 0;
						}
					}
				}

				if (!skipIteration) {
					if (current == LOAD32(listRef + 4)) {
						ppc_trap(ctx, base, 22);
					}
					current = LOAD32(current + 16);
					ctx.r1.u64 = stack;
					CCharString_ConstructFromCStr(ctx, base, stack + 80, weaponName, -1);
					PPCVRegister vecState = ctx.v1;

					uint32_t vcallObject = LOAD32(uint32_t(weaponSetManager->m_4) + 124);
					uint32_t vtable = LOAD32(vcallObject);
					callTarget.u64 = LOAD32(vtable + 64);
					ctx.r3.u64 = stack + 160;
					ctx.r4.u64 = vcallObject;
					ctx.r9.u64 = callTarget.u64;
					ctx.r10.u64 = vtable;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);

					uint32_t outBufferAddr = stack + 160;
					SET_V8(vecState, VLOAD(outBufferAddr & ~0xF));
					ctx.r8.u64 = outBufferAddr;
					ctx.v1 = vecState;
					uint64_t newEntity = n_sub_8248FC78(ctx, base, current, stack + 80);

					ctx.r1.u64 = stack;
					CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
					uint32_t entityFlags = ctx.r10.u64;
					// only bind the new entity when it carries flag 0x40, otherwise leave the entry alone
					bool skipNewEntity = true;
					if ((uint32_t)newEntity != 0) {
						entityFlags = LOAD8((uint32_t)newEntity + 144) & 64;
						skipNewEntity = entityFlags == 0;
					}

					if (!skipNewEntity) {
						uint32_t setLast = LOAD32(weaponSetAddr + 4);
						if (setOwner == 0 || setOwner != weaponSetAddr) {
							ctx.r1.u64 = stack;
							ppc_trap(ctx, base, 22);
						}
						if (foundNode != setLast) {
							// reuse the slot that already exists for this weapon
							STORE32(stack + 88, emptyEntityTag);
							STORE32(stack + 92, 0);
							ctx.r10.u64 = entityFlags;
							ctx.r1.u64 = stack;
							EntityHandle_SetTarget(ctx, base, stack + 88, newEntity);
							if (setOwner == 0 || foundNode == LOAD32(setOwner + 4)) {
								ctx.r1.u64 = stack;
								ppc_trap(ctx, base, 22);
							}
							ctx.r1.u64 = stack;
							EntityHandle_Assign(ctx, base, foundNode + 16, stack + 88);
							STORE32(stack + 88, emptyEntityTag);
							ctx.r1.u64 = stack;
							EntityHandle_Release(ctx, base, stack + 88);
							STORE32(stack + 92, 0);
						} else {
							// no slot yet: add a new entry keyed by the weapon string
							uint64_t copiedWeaponKey = CCharString_CopyConstruct(ctx, base, stack + 84, weaponKeyAddr);
							ctx.r1.u64 = stack;
							CCharString_CopyConstruct(ctx, base, stack + 112, copiedWeaponKey);
							STORE32(stack + 116, (uint32_t)newEntity);
							ctx.r1.u64 = stack;
							CCharString_ReleaseAndDecGlobalCountA(ctx, base, copiedWeaponKey);
							ctx.r1.u64 = stack;
							n_sub_82498930(ctx, base, stack + 128, stack + 112);
							ctx.r1.u64 = stack;
							n_sub_82496C58(ctx, base, stack + 144, weaponSetAddr, stack + 128, ctx.r8.u64);
							ctx.r1.u64 = stack;
							n_sub_824917E8(ctx, base, stack + 128);
							ctx.r1.u64 = stack;
							CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 112);
						}
						STORE32(stack + 96, emptyEntityTag);
						STORE32(stack + 100, 0);
						ctx.r1.u64 = stack;
						EntityHandle_SetTarget(ctx, base, stack + 96, newEntity);
						ctx.r1.u64 = stack;
						n_sub_82366260(ctx, base, managerAddr + 40, stack + 96);
						STORE32(stack + 96, emptyEntityTag);
						ctx.r1.u64 = stack;
						EntityHandle_Release(ctx, base, stack + 96);
						STORE32(stack + 100, 0);
					}
				}

				result = (uint64_t)(uint32_t)(stack + 104);
				ctx.r1.u64 = stack;
				RbTree_IteratorIncrement(ctx, base, (uint32_t)result);
				current = LOAD32(stack + 108);
				listRef = LOAD32(stack + 104);
			}
		}
	}
	stack = PopStackFrame(stack, 288);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_824914D8, 0x824914D8) { ctx.r3.u64 = n_sub_824914D8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_824919A0(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(27, 0x824919A0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_824919A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824919A0);
	uint32_t stack = ctx.r1.u64;
	uint32_t flags = arg2;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	n_sub_824919F0(ctx, base, arg1);
	uint64_t object = arg1;
	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(27, sub_824919A0, 0x824919A0) { ctx.r3.u64 = n_sub_824919A0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_824919F0(CpuState& ctx, uint8_t* base, uint64_t weaponSetManagerAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(27, 0x824919F0)) { ctx.r3.u64 = weaponSetManagerAddr; __imp__sub_824919F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824919F0);
	uint32_t stack = ctx.r1.u64;
	CECWeaponSetManager* weaponSetManager = GameObject<CECWeaponSetManager>(base, weaponSetManagerAddr);
	uint32_t result;

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	weaponSetManager->m_88 = g_820F1664;
	EntityHandle_Release(ctx, base, weaponSetManagerAddr + 136);

	weaponSetManager->m_8C = 0;
	SharedHandle_Release(ctx, base, weaponSetManagerAddr + 128);

	C_820EFB9C_Destructor(ctx, base, weaponSetManagerAddr + 112);

	weaponSetManager->m_68 = g_820F1664;
	EntityHandle_Release(ctx, base, weaponSetManagerAddr + 104);

	weaponSetManager->m_6C = 0;

	uint32_t charStringPair = weaponSetManagerAddr + 56;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringPair + 24);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringPair + 20);
	n_sub_825D7858(ctx, base, charStringPair);

	uint32_t handleRange = weaponSetManager->m_2C;
	uint32_t handleBlock = weaponSetManagerAddr + 40;
	if (handleRange != 0) {
		uint32_t rangeEnd = LOAD32(handleBlock + 8);
		ctx.r3.u64 = handleBlock;
		HandleRange_ReleaseAll(ctx, base, handleRange, rangeEnd);
		HandleTarget_Free(ctx, base, LOAD32(handleBlock + 4));
	}
	STORE32(handleBlock + 4, 0);
	STORE32(handleBlock + 8, 0);
	STORE32(handleBlock + 12, 0);

	n_sub_82496BF0(ctx, base, weaponSetManagerAddr + 28);
	result = n_sub_82496A30(ctx, base, weaponSetManagerAddr + 16);

	uint32_t baseSubobject = ((uint32_t)weaponSetManagerAddr != 0) ? (uint32_t)(weaponSetManagerAddr + 12) : 0u;
	STORE32(baseSubobject, 0x820A8F74u);
	weaponSetManager->vtable = 0x820A8D10u;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_824919F0, 0x824919F0) { ctx.r3.u64 = n_sub_824919F0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82491AC8(CpuState& ctx, uint8_t* base, uint64_t weaponSetManagerAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t str_TXT_820B5534_B_ = int32_t(0x820B5534);
	if (!UseLiftedCode(27, 0x82491AC8)) { ctx.r3.u64 = weaponSetManagerAddr; ctx.r4.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_82491AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82491AC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// local3: comparison scratch that is handed on to the callee in r7
	uint64_t searchProbeR7 = ctx.r7.u64;
	bool carryCa = ctx.xer.ca;
	uint64_t weaponSetValue = 0;
	bool hasWeaponSetValue = false;

	if ((uint32_t)arg2 != 0) {
		ctx.r1.u64 = stack;
		n_sub_82491058(ctx, base, weaponSetManagerAddr, arg2, arg3);
		carryCa = ctx.xer.ca;
		GameDB_ReadBool(ctx, base, arg2, str_TXT_820B5534_B_, weaponSetManagerAddr + 125);
		arg2 = ctx.r4.u64;
		searchProbeR7 = ctx.r7.u64;
		arg3 = ctx.r8.u64;
	}

	uint32_t weaponSetNode = LOAD32(weaponSetManagerAddr + 4);
	if ((int32_t)LOAD32(weaponSetNode + 36) < 0) {
		uint32_t selectedSlot = LOAD32(weaponSetNode + 140);
		if (selectedSlot != 0) {
			uint32_t slotIndex = LOAD8(selectedSlot + 31);
			uint32_t entryBase = LOAD32(weaponSetNode + 72);
			weaponSetValue = LOAD32(entryBase + (slotIndex << 3) + 4);
		} else {
			uint32_t entryIt = LOAD32(weaponSetNode + 72);
			uint32_t entryEnd = LOAD32(weaponSetNode + 76);
			STORE32(stack + 80, 0);
			STORE32(stack + 84, entryIt);
			uint32_t entrySpan = entryEnd - entryIt;
			carryCa = ((int32_t)entrySpan < 0) && ((entrySpan & 7) != 0);
			int32_t remaining = (int32_t)entrySpan >> 3;
			if (remaining > 0) {
				do {
					carryCa = false;
					int32_t half = remaining >> 1;
					arg3 = (uint32_t)(half << 3);  // reused as the step size in bytes
					entryIt += (uint32_t)arg3;
					bool belowThreshold = (int32_t)LOAD32(entryIt) < 31;
					searchProbeR7 = belowThreshold ? 1 : 0;
					if (belowThreshold) {
						remaining = remaining - half - 1;
						entryIt = (uint32_t)((int32_t)entryIt + 8);
					} else {
						entryIt -= (uint32_t)arg3;
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, entryIt);
			}
			if (entryIt != entryEnd) {
				if ((int32_t)LOAD32(entryIt) > 31) {
					weaponSetValue = LOAD32(entryEnd + 4);
				} else {
					STORE64(stack + 80, LOAD64(stack + 80));
					uint32_t matched = LOAD32(stack + 84);
					weaponSetValue = LOAD32(matched + 4);
				}
			} else {
				weaponSetValue = LOAD32(entryEnd + 4);
			}
		}
		hasWeaponSetValue = true;
	}

	if (hasWeaponSetValue) {
		ctx.r1.u64 = stack;
		ctx.r7.u64 = searchProbeR7;
		ctx.r8.u64 = arg3;
		ctx.xer.ca = carryCa;
		weaponSetValue = n_sub_82483858(ctx, base, weaponSetValue, weaponSetManagerAddr + 112, weaponSetManagerAddr + 12, 20);
		arg2 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return weaponSetValue;
}
PROMOTED_ENTRY(27, sub_82491AC8, 0x82491AC8) { ctx.r3.u64 = n_sub_82491AC8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t n_sub_82492428(CpuState& ctx, uint8_t* base, uint64_t weaponSetManagerAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(27, 0x82492428)) { ctx.r3.u64 = weaponSetManagerAddr; __imp__sub_82492428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82492428);
	uint32_t stack = ctx.r1.u64;
	CECWeaponSetManager* weaponSetManager = GameObject<CECWeaponSetManager>(base, weaponSetManagerAddr);
	stack = PushStackFrame(base, stack, 224);

	const uint32_t emptyHandle = uint32_t(g_820F1664);
	const uint32_t entityManagerRoot = uint32_t(g_83490000);
	const uint32_t managerAddr = (uint32_t)weaponSetManagerAddr;
	const uint32_t containerSlot = managerAddr + 128; // &CECWeaponSetManager::m_80
	uint32_t container = weaponSetManager->m_80;
	uint64_t result = weaponSetManagerAddr;
	uint64_t r6Value = 0;
	uint64_t targetListSpan = 0;
	int32_t targetListCount = 0;

	if (container != 0) {
		int32_t entryCount = (int32_t)(LOAD32(container + 8) - LOAD32(container + 4)) / 12;
		r6Value = (uint64_t)(uint32_t)entryCount;

		uint32_t i = 0;
		if (entryCount != 0) {
			uint32_t entryOffset = 0;
			do {
				uint32_t entryAddr = LOAD32(container + 4) + entryOffset;
				uint32_t registry = LOAD32(LOAD32(LOAD32(entityManagerRoot + 26912) + 12) + 88);
				uint32_t lookupKey = LOAD32(LOAD32(registry + 4));
				ctx.r1.u64 = stack;
				ctx.r6.u64 = r6Value;
				ctx.r8.u64 = registry;
				uint32_t entity = (uint32_t)n_sub_82264448(ctx, base, lookupKey, entryAddr + 4);
				r6Value = ctx.r6.u64;

				if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
					uint64_t nameCopy = CCharString_CopyConstruct(ctx, base, stack + 80, entryAddr);
					CCharString_CopyConstruct(ctx, base, stack + 88, nameCopy);
					STORE32(stack + 92, entity);
					CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameCopy);
					n_sub_82498930(ctx, base, stack + 96, stack + 88);
					n_sub_82496C58(ctx, base, stack + 112, managerAddr + 28, stack + 96, ctx.r8.u64);
					STORE32(stack + 100, emptyHandle);
					EntityHandle_Release(ctx, base, stack + 100);
					STORE32(stack + 104, 0);
					CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 96);
					CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
					r6Value = ctx.r6.u64;
				}

				container = LOAD32(containerSlot);
				i++;
				entryOffset += 12;
				entryCount = (int32_t)(LOAD32(container + 8) - LOAD32(container + 4)) / 12;
			} while (i < (uint32_t)entryCount);
		}

		container = LOAD32(containerSlot);
		targetListSpan = (uint64_t)LOAD32(container + 24) - (uint64_t)LOAD32(container + 20);
		targetListCount = (int32_t)(uint32_t)targetListSpan >> 3;

		uint32_t j = 0;
		if (targetListCount != 0) {
			uint32_t entryOffset = 0;
			do {
				uint32_t entryAddr = LOAD32(container + 20) + entryOffset;
				uint32_t registry = LOAD32(LOAD32(LOAD32(entityManagerRoot + 26912) + 12) + 88);
				uint32_t lookupKey = LOAD32(LOAD32(registry + 4));
				ctx.r1.u64 = stack;
				ctx.r6.u64 = r6Value;
				ctx.r8.u64 = registry;
				uint32_t entity = (uint32_t)n_sub_82264448(ctx, base, lookupKey, entryAddr);
				r6Value = ctx.r6.u64;

				if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
					n_sub_8248F8D8(ctx, base, entity);
					STORE32(stack + 88, emptyHandle);
					STORE32(stack + 92, 0);
					EntityHandle_SetTarget(ctx, base, stack + 88, entity);
					n_sub_82366260(ctx, base, managerAddr + 40, stack + 88);
					STORE32(stack + 88, emptyHandle);
					EntityHandle_Release(ctx, base, stack + 88);
					r6Value = ctx.r6.u64;
					STORE32(stack + 92, 0);
				}

				container = LOAD32(containerSlot);
				j++;
				entryOffset += 8;
				targetListSpan = (uint64_t)LOAD32(container + 24) - (uint64_t)LOAD32(container + 20);
				targetListCount = (int32_t)(uint32_t)targetListSpan >> 3;
			} while ((uint32_t)j < (uint32_t)targetListCount);
		}

		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = (uint64_t)(int64_t)targetListCount;
		ctx.r8.u64 = targetListSpan;
		n_sub_824914D8(ctx, base, managerAddr);

		result = SharedHandle_Release(ctx, base, containerSlot);
		STORE32(containerSlot, 0);
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_82492428, 0x82492428) { ctx.r3.u64 = n_sub_82492428(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82492648(CpuState& ctx, uint8_t* base, uint64_t weaponSetManagerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(27, 0x82492648)) { ctx.r3.u64 = weaponSetManagerAddr; __imp__sub_82492648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82492648);
	uint32_t stack = ctx.r1.u64;
	CECWeaponSetManager* weaponSetManager = GameObject<CECWeaponSetManager>(base, weaponSetManagerAddr);
	stack = PushStackFrame(base, stack, 96);

	uint64_t result = weaponSetManagerAddr;

	if (weaponSetManager->m_7C != 0) {
		uint32_t registry = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t playerOwner = LOAD32(LOAD32(registry + 12) + 88);
		uint32_t playerSlot = LOAD32(playerOwner + 4);
		uint32_t playerEntity = LOAD32(playerSlot);
		uint32_t ownerEntity = weaponSetManager->m_4;

		ctx.r1.u64 = stack;
		ctx.r8.u64 = playerSlot;
		ctx.r9.u64 = playerOwner;
		uint32_t isPlayer = Players_IsPlayer(ctx, base, playerEntity, ownerEntity);

		if ((isPlayer & 0xFF) == 0) {
			if (((LOAD32(LOAD32((uint32_t)weaponSetManagerAddr + 4) + 48) >> 1) & 1) == 0) {
				n_sub_82495320(ctx, base, weaponSetManagerAddr);
			}
		}

		if (LOAD32((uint32_t)weaponSetManagerAddr + 72) == 0) {
			result = n_sub_824926F8(ctx, base, weaponSetManagerAddr, 1, 0);
		} else {
			result = n_sub_82492808(ctx, base, weaponSetManagerAddr, (uint32_t)weaponSetManagerAddr + 56, 0);
		}
	}

	weaponSetManager->m_7C = uint8_t(1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_82492648, 0x82492648) { ctx.r3.u64 = n_sub_82492648(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82495320(CpuState& ctx, uint8_t* base, uint64_t weaponSetManagerAddr) {
	constexpr int32_t str_TXT_820AED00_B_ = int32_t(0x820AED00);
	if (!UseLiftedCode(27, 0x82495320)) { ctx.r3.u64 = weaponSetManagerAddr; __imp__sub_82495320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82495320);
	uint32_t stack = ctx.r1.u64;

	CECWeaponSetManager* weaponSetManager = GameObject<CECWeaponSetManager>(base, weaponSetManagerAddr);

	// Values the code keeps in r4..r8 across calls; some callees still consume them.
	uint64_t reg4 = ctx.r4.u64;
	uint64_t reg5 = ctx.r5.u64;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;
	PPCCRRegister compare0{};

	uint32_t weaponItemList = 0;
	bool hasWeaponItemList = false;

	stack = PushStackFrame(base, stack, 256);

	uint32_t inventory = weaponSetManager->m_4;
	if ((LOAD32(inventory + 36) >> 13) & 1) {
		uint32_t slot = LOAD32(inventory + 140);
		if (slot != 0) {
			uint32_t entryOffset = LOAD8(slot + 13) << 3;
			uint32_t mapBase = LOAD32(inventory + 72);
			weaponItemList = LOAD32(uint32_t(entryOffset + mapBase) + 4);
			hasWeaponItemList = true;
		} else {
			// lower_bound over the (int key, ptr) map entries, looking for key 13
			uint32_t low = LOAD32(inventory + 72);
			uint32_t high = LOAD32(inventory + 76);
			uint32_t mapSpan = high - low;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, low);
			flags.ca = ((int32_t)mapSpan < 0) & ((mapSpan & 0x7) != 0);
			int32_t remaining = (int32_t)mapSpan >> 3;
			if (remaining > 0) {
				do {
					flags.ca = ((int32_t)remaining < 0) & (((uint32_t)remaining & 0x1) != 0);
					int32_t half = remaining >> 1;
					uint32_t step = (uint32_t)half << 3;
					uint32_t mid = low + step;
					reg7 = ((int32_t)LOAD32(mid) < 13) ? 1 : 0;
					reg8 = step;
					if (reg7 != 0) {
						low = mid + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, low);
			}
			if (low != high && (int32_t)LOAD32(low) <= 13) {
				STORE64(stack + 112, LOAD64(stack + 80));
				weaponItemList = LOAD32(LOAD32(stack + 116) + 4);
			} else {
				weaponItemList = LOAD32(high + 4);
			}
			hasWeaponItemList = true;
		}
	}

	if (hasWeaponItemList) {
		uint32_t meleeHandle = 0;
		uint32_t rangedHandle = 0;
		STORE32(stack + 156, 0);
		STORE32(stack + 148, 0);
		STORE32(stack + 172, 0);
		uint32_t itemIndex = 0;
		STORE32(stack + 152, 0);
		STORE32(stack + 164, 0);
		STORE32(stack + 168, 0);

		ctx.r1.u64 = stack;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.xer.ca = flags.ca;
		int32_t itemCount = ItemList_SumCount(ctx, base, weaponItemList);
		uint64_t rngQuotient = ctx.r7.u64;
		uint64_t rngDraw = ctx.r8.u64;

		if (itemCount > 0) {
			uint32_t TXT_820AED00_L_ = str_TXT_820AED00_B_;
			int32_t nextCount = 0;
			do {
				ctx.r5.s64 = -1;
				Inventory_SelectItemByWeight(ctx, base, stack + 128, weaponItemList, itemIndex);
				reg4 = ctx.r4.u64;
				reg5 = ctx.r5.u64;
				reg6 = ctx.r6.u64;
				flags.ca = ctx.xer.ca;

				uint32_t listHead = LOAD32(stack + 128);
				if (listHead != 0) {
					uint32_t entry = listHead + 4;
					uint32_t recordId = LOAD32(entry);
					if (recordId != 0) {
						uint32_t recordType = LOAD32(entry + 4);
						STORE32(stack + 88, recordId);
						STORE32(stack + 92, recordType);
						uint64_t idRef = IdRef_Get(ctx, base, stack + 88);
						uint64_t property = Region_GetProperty(ctx, base, idRef, TXT_820AED00_L_);
						reg5 = ctx.r5.u64;
						reg6 = ctx.r6.u64;
						reg4 = property;
						IdRef_ConstructFromId(ctx, base, stack + 96, property);

						uint32_t descriptorId = LOAD32(stack + 96);
						if (descriptorId != 0) {
							uint32_t descriptorType = LOAD32(stack + 100);
							STORE32(stack + 104, descriptorId);
							STORE32(stack + 108, descriptorType);
							ctx.r4.u64 = property;
							uint32_t isMelee = n_sub_8250BBC0(ctx, base, stack + 104);
							uint32_t pushTarget = 0;
							uint32_t weaponId = 0;
							if (isMelee & 0xFF) {
								uint32_t h = LOAD32(stack + 128);
								weaponId = (h != 0) ? LOAD32(h + 4) : 0;
								pushTarget = stack + 144;
							} else {
								STORE32(stack + 112, descriptorId);
								STORE32(stack + 116, descriptorType);
								uint32_t isRanged = n_sub_8250BC20(ctx, base, stack + 112);
								reg4 = ctx.r4.u64;
								reg5 = ctx.r5.u64;
								reg6 = ctx.r6.u64;
								if (isRanged & 0xFF) {
									uint32_t h = LOAD32(stack + 128);
									weaponId = (h != 0) ? LOAD32(h + 4) : 0;
									pushTarget = stack + 160;
								}
							}
							if (pushTarget != 0) {
								STORE32(stack + 80, weaponId);
								IntVector_PushBack(ctx, base, pushTarget, stack + 80);
								reg4 = ctx.r4.u64;
								reg5 = ctx.r5.u64;
								reg6 = ctx.r6.u64;
								flags.ca = ctx.xer.ca;
							}
						}
					}
				}

				uint32_t removable = LOAD32(stack + 128);
				if (removable != 0) {
					PtrList_RemoveAll(ctx, base, removable, stack + 128);
					reg4 = ctx.r4.u64;
					reg5 = ctx.r5.u64;
					reg6 = ctx.r6.u64;
					flags.ca = ctx.xer.ca;
				}

				STORE32(stack + 128, 0);
				itemIndex = itemIndex + 1;
				nextCount = ItemList_SumCount(ctx, base, weaponItemList);
				rngQuotient = ctx.r7.u64;
				rngDraw = ctx.r8.u64;
			} while ((int32_t)itemIndex < nextCount);

			meleeHandle = LOAD32(stack + 148);
			rangedHandle = LOAD32(stack + 164);
		}

		uint32_t meleeSpan = LOAD32(stack + 152) - meleeHandle;
		flags.ca = ((int32_t)meleeSpan < 0) & ((meleeSpan & 0x3) != 0);
		int32_t meleeWeaponCount = (int32_t)meleeSpan >> 2;
		uint32_t rngGlobal = LOAD32(0x83496920u);
		if (meleeWeaponCount != 0) {
			uint32_t rng = LOAD32(LOAD32(LOAD32(rngGlobal + 12) + 88) + 4);
			uint32_t roll = __builtin_rotateleft32(uint32_t((int64_t)((uint64_t)LOAD32(rng + 120) * 9377u) + 9439), 19);
			STORE32(rng + 120, roll);
			uint32_t pick = (uint32_t)((uint64_t)roll - (uint64_t)((int64_t)(int32_t)(roll / (uint32_t)meleeWeaponCount) * (int64_t)meleeWeaponCount));
			weaponSetManager->m_54 = LOAD32((pick << 2) + meleeHandle);

			uint32_t rng2 = LOAD32(LOAD32(LOAD32(rngGlobal + 12) + 88) + 4);
			uint64_t roll2 = __builtin_rotateleft32(uint32_t((int64_t)((uint64_t)LOAD32(rng2 + 120) * 9377u) + 9439), 19);
			rngDraw = roll2;
			rngQuotient = (uint32_t)roll2 / (uint32_t)meleeWeaponCount;
			STORE32(rng2 + 120, (uint32_t)roll2);
			reg6 = (uint64_t)((int64_t)(int32_t)(uint32_t)rngQuotient * (int64_t)meleeWeaponCount);
			reg5 = roll2 - reg6;
			reg4 = (uint32_t)reg5 << 2;
			weaponSetManager->m_5C = LOAD32((uint32_t)reg4 + meleeHandle);
		}

		uint32_t rangedSpan = LOAD32(stack + 168) - rangedHandle;
		flags.ca = ((int32_t)rangedSpan < 0) & ((rangedSpan & 0x3) != 0);
		int32_t rangedWeaponCount = (int32_t)rangedSpan >> 2;
		compare0.compare<int32_t>(rangedWeaponCount, 0, flags);
		if (rangedWeaponCount != 0) {
			uint32_t rng = LOAD32(LOAD32(LOAD32(rngGlobal + 12) + 88) + 4);
			rngDraw = LOAD32(rng + 120);
			rngQuotient = (uint64_t)(int64_t)((int64_t)(rngDraw * 9377u) + 9439);
			reg6 = __builtin_rotateleft32((uint32_t)rngQuotient, 19);
			reg5 = (uint32_t)reg6 / (uint32_t)rangedWeaponCount;
			STORE32(rng + 120, (uint32_t)reg6);
			reg4 = (uint64_t)((int64_t)(int32_t)(uint32_t)reg5 * (int64_t)rangedWeaponCount);
			uint32_t pick = (uint32_t)((uint32_t)reg6 - (uint32_t)reg4);
			weaponSetManager->m_58 = LOAD32((pick << 2) + rangedHandle);
		}

		ctx.r4.u64 = reg4;
		ctx.r5.u64 = reg5;
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = rngQuotient;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		WeaponSetManager_SelectWeaponsFromInventoryImpl(ctx, base, weaponItemList, rngDraw);
		reg8 = ctx.r8.u64;
		flags.ca = ctx.xer.ca;

		if (rangedHandle != 0) {
			HandleTarget_Free(ctx, base, rangedHandle);
			reg8 = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
		}
		if (meleeHandle != 0) {
			HandleTarget_Free(ctx, base, meleeHandle);
			reg8 = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
		}
	}

	ctx.r1.u64 = stack;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	uint64_t result = n_sub_82495FE8(ctx, base, weaponSetManagerAddr);
	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_82495320, 0x82495320) { ctx.r3.u64 = n_sub_82495320(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82495FE8(CpuState& ctx, uint8_t* base, uint32_t weaponSetManagerAddr) {
	if (!UseLiftedCode(27, 0x82495FE8)) { ctx.r3.u64 = weaponSetManagerAddr; __imp__sub_82495FE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82495FE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	CECWeaponSetManager* weaponSetManager = GameObject<CECWeaponSetManager>(base, weaponSetManagerAddr);
	uint64_t result = 0;
	uint64_t r8Result = ctx.r8.u64;
	uint32_t weaponSetData = weaponSetManager->m_4;

	if ((LOAD32(weaponSetData + 44) >> 27) & 1) {
		uint32_t ownerEntity = 0;
		uint32_t lookupTable = LOAD32(weaponSetData + 140);
		if (lookupTable != 0) {
			uint32_t index = LOAD8(lookupTable + 91);
			uint32_t entries = LOAD32(weaponSetData + 72);
			ownerEntity = LOAD32(entries + index * 8 + 4);
		} else {
			// lower_bound over the sorted (key, value) table, searching for key 91.
			uint32_t begin = LOAD32(weaponSetData + 72);
			uint32_t end = LOAD32(weaponSetData + 76);
			STORE32(stack + 80, 0);
			STORE32(stack + 84, begin);
			int32_t count = (int32_t)(end - begin) >> 3;
			while (count > 0) {
				int32_t half = count >> 1;
				// The lifted code holds the search stride in r8; it is still there at the
				// return when the replication check below is skipped.
				r8Result = (uint32_t)half << 3;
				uint32_t mid = begin + ((uint32_t)half << 3);
				if ((int32_t)LOAD32(mid) < 91) {
					count = count - half - 1;
					begin = mid + 8;
				} else {
					count = half;
				}
			}
			STORE32(stack + 84, begin);
			if (begin != end && (int32_t)LOAD32(begin) <= 91) {
				ownerEntity = LOAD32(begin + 4);
			} else {
				ownerEntity = LOAD32(end + 4);
			}
		}

		ctx.r1.u64 = stack;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, ownerEntity);
		if ((result & 0xFF) != 0) {
			uint32_t globalPtr = LOAD32(0x83496920u);
			uint32_t entitySource = LOAD32(LOAD32(LOAD32(LOAD32(globalPtr + 12) + 88) + 4));

			uint32_t primarySlot = weaponSetManager->m_54;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, primarySlot);
			ctx.r8.u64 = 0;
			uint32_t primaryEntity = n_sub_82264448(ctx, base, entitySource, stack + 80);

			uint32_t secondarySlot = weaponSetManager->m_58;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, secondarySlot);
			ctx.r8.u64 = 0;
			uint32_t secondaryEntity = n_sub_82264448(ctx, base, entitySource, stack + 80);

			// Replication message: type tag followed by the two weapon entity unique ids.
			STORE64(stack + 104, 0);
			STORE64(stack + 112, 0);
			STORE32(stack + 96, 0x820A4C10u);

			if (primaryEntity != 0 && (LOAD8(primaryEntity + 144) & 64) != 0) {
				STORE64(stack + 104, Entity_GetUniqueId(ctx, base, primaryEntity));
			} else {
				STORE64(stack + 104, 0);
			}

			if (secondaryEntity != 0 && (LOAD8(secondaryEntity + 144) & 64) != 0) {
				STORE64(stack + 112, Entity_GetUniqueId(ctx, base, secondaryEntity));
			} else {
				STORE64(stack + 112, 0);
			}

			uint32_t ownerObject = weaponSetManager->m_4;
			uint32_t targetTable = LOAD32(LOAD32(globalPtr + 12) + 140);
			uint64_t ownerId = Entity_GetUniqueId(ctx, base, ownerObject);
			result = n_sub_82498990(ctx, base, targetTable, stack + 96, ownerId);
			r8Result = ctx.r8.u64;
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = r8Result;
	return result;
}
PROMOTED_ENTRY(27, sub_82495FE8, 0x82495FE8) { ctx.r3.u64 = n_sub_82495FE8(ctx, base, ctx.r3.u32); }
