// CECInventory (vtable 0x82004118): methods of the class as readable C++.
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

uint64_t CECInventory_HandleMessage(CpuState& ctx, uint8_t* base, uint64_t inventoryAddr, uint64_t message) {
	if (!UseLiftedCode(7, 0x822382F8)) { ctx.r3.u64 = inventoryAddr; ctx.r4.u64 = message; __imp__sub_822382F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822382F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t handler = LOAD32(LOAD32((uint32_t)message) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = message;
	ctx.r4.u64 = message;
	ctx.r10.u64 = handler;
	REX_CALL_INDIRECT_FUNC(handler);
	uint64_t result = ctx.r3.u64;
	if ((int32_t)result == 8) {
		result = CECInventory_OnDeath(ctx, base, inventoryAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_822382F8, 0x822382F8) { ctx.r3.u64 = CECInventory_HandleMessage(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECInventory_GetName(CpuState& ctx, uint8_t* base, uint64_t resultString) {
	constexpr int32_t str_TXT_820C7234_B_ = int32_t(0x820C7234);
	if (!UseLiftedCode(40, 0x82618A90)) { ctx.r3.u64 = resultString; __imp__sub_82618A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82618A90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t nameString = str_TXT_820C7234_B_;
	CCharString_ConstructFromCStr(ctx, base, resultString, nameString, -1);
	return resultString;
}
PROMOTED_ENTRY(40, sub_82618A90, 0x82618A90) { ctx.r3.u64 = CECInventory_GetName(ctx, base, ctx.r3.u64); }

uint64_t CECInventory_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t inventoryAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(40, 0x82618BB8)) { ctx.r3.u64 = inventoryAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82618BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82618BB8);
	uint32_t stack = ctx.r1.u64;
	CECInventory* inventory = GameObject<CECInventory>(base, inventoryAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t vectorToDestroy = inventoryAddr + 28;
	uint64_t handleListToClear = inventoryAddr + 12;
	uint64_t result = inventoryAddr;

	inventory->vtable = 0x82004118u;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	PtrVector8_ClearAndFree(ctx, base, vectorToDestroy);
	SharedHandleList_Clear_825E4F68(ctx, base, handleListToClear);

	inventory->vtable = 0x820A8D10u;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, result);
		result = inventoryAddr;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_82618BB8, 0x82618BB8) { ctx.r3.u64 = CECInventory_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECInventory_Serialize(CpuState& ctx, uint8_t* base, uint64_t inventoryAddr, uint64_t archive, uint32_t arg3, uint64_t isSaving) {
	constexpr int32_t g_82090000 = int32_t(0x82090000);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820A84F0_B_ = int32_t(0x820A84F0);
	constexpr int32_t str_TXT_820C725C_B_ = int32_t(0x820C725C);
	constexpr int32_t str_TXT_820C7270_B_ = int32_t(0x820C7270);
	constexpr int32_t str_TXT_820C7288_B_ = int32_t(0x820C7288);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(40, 0x82618D98)) { ctx.r3.u64 = inventoryAddr; ctx.r4.u64 = archive; ctx.r5.u64 = arg3; ctx.r6.u64 = isSaving; __imp__sub_82618D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82618D98);

	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECInventory* inventory = GameObject<CECInventory>(base, inventoryAddr);

	stack = PushStackFrame(base, stack, 240);
	ctx.r1.u64 = stack;

	const int32_t stringLength = -1;
	const uint64_t defaultRecordId = (uint64_t)(int64_t)g_8209003F;           // 0xFFFFFFFF8209003F
	const uint64_t recordIdRefCountAddr = (uint64_t)(int64_t)g_83490000 + 28344;  // 0xFFFFFFFF83496EB8
	const uint32_t allocFailureHandler = (uint32_t)g_83490000 + 28060;        // 0x83496D9C

	ctx.r6.u64 = isSaving;
	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820C725C_B_, stringLength);
	IStream_SerializeString(ctx, base, stack + 80, archive, inventoryAddr + 24);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820C7270_B_, stringLength);
	IStream_SerializeString(ctx, base, stack + 80, archive, inventoryAddr + 25);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	uint64_t isSavingValue = ctx.r6.u64;

	if ((uint32_t)isSaving & 0xFF) {
		uint64_t reg8 = (uint64_t)(int64_t)g_82090000;
		uint64_t reg9 = (uint64_t)(int64_t)g_83490000;

		uint32_t listSentinel = inventoryAddr + 12;
		uint32_t itemListHeadPtr = inventory->m_10;
		STORE32(stack + 96, listSentinel);
		STORE32(stack + 100, LOAD32(itemListHeadPtr));
		STORE64(stack + 96, LOAD64(stack + 96));
		uint32_t curNode = LOAD32(stack + 100);

		for (;;) {
			if (curNode == LOAD32(listSentinel + 4)) {
				stack = PopStackFrame(stack, 240);
				ctx.r1.u64 = stack;
				return result;
			}

			uint32_t item = LOAD32(curNode + 8);
			uint32_t beginSerialize = LOAD32(LOAD32((uint32_t)archive) + 4);
			callTarget.u64 = beginSerialize;
			ctx.r3.u64 = archive;
			ctx.r4.u64 = str_TXT_820C7288_B_;
			ctx.r6.u64 = isSavingValue;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = reg9;
			ctx.r10.u64 = beginSerialize;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			STORE32(stack + 88, LOAD32(item + 4));
			CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820A84F0_B_, stringLength);
			uint32_t recordIdString = LOAD32(stack + 80);
			ctx.r4.u64 = (recordIdString != 0) ? (uint64_t)LOAD32(recordIdString) : defaultRecordId;
			IStream_SerializeId(ctx, base, archive, stack + 88);
			CCharString_Release(ctx, base, stack + 80);
			STORE32((uint32_t)g_83496EB8, LOAD32((uint32_t)g_83496EB8) - 1);

			STORE32(stack + 80, 0);
			InventoryItem_SerializeData(ctx, base, item, archive, isSaving);

			uint32_t endSerializeVtbl = LOAD32((uint32_t)archive);
			uint32_t endSerialize = LOAD32(endSerializeVtbl + 12);
			callTarget.u64 = endSerialize;
			ctx.r3.u64 = archive;
			ctx.r7.u64 = endSerialize;
			ctx.r8.u64 = endSerializeVtbl;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			result = ctx.r3.u64;
			reg8 = ctx.r8.u64;
			reg9 = ctx.r9.u64;
			isSavingValue = LOAD32(listSentinel + 4);
			if (curNode == isSavingValue) ppc_trap(ctx, base, 22);
			curNode = LOAD32(curNode);
		}
	}

	uint32_t readVtbl = LOAD32((uint32_t)archive);
	uint32_t beginRead = LOAD32(readVtbl + 8);
	callTarget.u64 = beginRead;
	ctx.r3.u64 = archive;
	ctx.r4.u64 = str_TXT_820C7288_B_;
	ctx.r9.u64 = beginRead;
	ctx.r10.u64 = readVtbl;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	result = ctx.r3.u64;
	uint32_t nextItemFlag = (uint32_t)result & 0xFF;

	if (nextItemFlag != 0) {
		uint32_t listSentinel = inventoryAddr + 12;
		STORE32(stack + 104, listSentinel);
		do {
			STORE32(stack + 84, 0);
			CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820A84F0_B_, stringLength);
			uint32_t recordIdString = LOAD32(stack + 80);
			ctx.r4.u64 = (recordIdString != 0) ? (uint64_t)LOAD32(recordIdString) : defaultRecordId;
			IStream_SerializeId(ctx, base, archive, stack + 84);
			CCharString_Release(ctx, base, stack + 80);
			STORE32((uint32_t)g_83496EB8, LOAD32((uint32_t)g_83496EB8) - 1);

			STORE32(stack + 80, 0);
			uint64_t item = 0;
			uint64_t itemHandle = Heap_Alloc(ctx, base, 52);
			if ((uint32_t)itemHandle != 0) {
				uint32_t itemId = LOAD32(stack + 84);
				item = InventoryItem_Construct(ctx, base, itemHandle, inventoryAddr, itemId);
			} else {
				uint32_t handler = LOAD32(allocFailureHandler);
				if (handler != 0) {
					callTarget.u64 = handler;
					ctx.r3.u64 = itemHandle;
					ctx.r4.u64 = 0;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					itemHandle = ctx.r3.u64;
				}
				ctx.r3.u64 = itemHandle;
				ThrowBadAlloc(ctx, base);
			}

			STORE32(stack + 96, (uint32_t)item);
			if ((uint32_t)item != 0) {
				uint64_t sharedHandle = Heap_Alloc(ctx, base, 12);
				if ((uint32_t)sharedHandle != 0) {
					STORE32((uint32_t)sharedHandle + 8, (uint32_t)item);
					STORE32(stack + 100, (uint32_t)sharedHandle);
					STORE32((uint32_t)sharedHandle, 1);
					STORE32((uint32_t)sharedHandle + 4, 0x8261E4B8u);
				} else {
					uint32_t handler = LOAD32(allocFailureHandler);
					if (handler != 0) {
						callTarget.u64 = handler;
						ctx.r3.u64 = sharedHandle;
						ctx.r4.u64 = 0;
						REX_CALL_INDIRECT_FUNC(callTarget.u32);
						sharedHandle = ctx.r3.u64;
					}
					ctx.r3.u64 = sharedHandle;
					ThrowBadAlloc(ctx, base);
					STORE32(stack + 100, 0);
				}
			} else {
				STORE32(stack + 100, 0);
			}

			InventoryItem_SerializeData(ctx, base, item, archive, isSaving);
			STORE32(stack + 108, LOAD32(listSentinel + 4));
			uint64_t listKey = LOAD64(stack + 104);
			List_InsertNodeCopyRefCountedPair(ctx, base, listSentinel, listKey, stack + 96);
			STORE32(stack + 112, (uint32_t)item);
			STORE32(stack + 116, 0);
			STORE32(stack + 120, 0);
			STORE32(stack + 124, 0);
			if ((uint32_t)item != 0) {
				IdList_AddUnique(ctx, base, item, stack + 112);
			}
			CECInventory_ApplyItemEffects(ctx, base, inventoryAddr, stack + 112);
			uint32_t addedHandle = LOAD32(stack + 112);
			if (addedHandle != 0) {
				PtrList_RemoveAll(ctx, base, addedHandle, stack + 112);
			}

			uint32_t endItemVtbl = LOAD32((uint32_t)archive);
			STORE32(stack + 112, 0);
			uint32_t endItem = LOAD32(endItemVtbl + 12);
			callTarget.u64 = endItem;
			ctx.r3.u64 = archive;
			ctx.r10.u64 = endItem;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			SharedHandle_Release(ctx, base, stack + 96);

			uint32_t nextVtbl = LOAD32((uint32_t)archive);
			uint32_t nextItem = LOAD32(nextVtbl + 8);
			callTarget.u64 = nextItem;
			ctx.r3.u64 = archive;
			ctx.r4.u64 = str_TXT_820C7288_B_;
			ctx.r8.u64 = nextItem;
			ctx.r9.u64 = nextVtbl;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			nextItemFlag = ctx.r8.u64;
		} while (((uint32_t)result & 0xFF) != 0);
	}

	if ((int32_t)arg3 == 1) {
		inventory->m_1A = (uint8_t)1;
	}

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_82618D98, 0x82618D98) { ctx.r3.u64 = CECInventory_Serialize(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64); }

uint64_t CECInventory_SelectWeightedItem(CpuState& ctx, uint8_t* base, uint64_t sourceList, uint64_t level) {
	constexpr int32_t str_TXT_820B0E64_B_ = int32_t(0x820B0E64);
	constexpr int32_t str_TXT_820B3308_B_ = int32_t(0x820B3308);
	constexpr int32_t str_TXT_820B331C_B_ = int32_t(0x820B331C);
	constexpr int32_t str_TXT_820C7348_B_ = int32_t(0x820C7348);
	constexpr int32_t str_TXT_820C735C_B_ = int32_t(0x820C735C);
	constexpr int32_t str_TXT_820C7370_B_ = int32_t(0x820C7370);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(40, 0x826198A0)) { ctx.r4.u64 = sourceList; ctx.r5.u64 = level; __imp__sub_826198A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826198A0);

	uint32_t stack = (uint32_t)ctx.r1.u64;
	uint32_t r6Arg = (uint32_t)ctx.r6.u64;
	double f1Value = ctx.f1.f64;
	double f13Value = ctx.f13.f64;
	bool ca = ctx.xer.ca;

	stack = PushStackFrame(base, stack, 320);

	const uint32_t globalBase = (uint32_t)g_83490000;
	uint32_t result = 0;
	int32_t levelPlusOne = (int32_t)(uint32_t)level + 1;

	ctx.fpscr.disableFlushMode();
	double baseWeight = double(LOAD_F32(0x820994B4u));
	double chapterProgress = baseWeight;

	uint32_t p2 = LOAD32(LOAD32(globalBase + 26912) + 12);
	uint32_t p3 = LOAD32(p2 + 88);
	uint32_t p4 = LOAD32(p3 + 4);
	uint32_t p5 = LOAD32(p4);
	uint32_t handlePtr = p5 + 104;
	uint32_t p6 = LOAD32(p5 + 108);

	uint32_t temp63 = p3;
	uint32_t itemId = 0;
	bool valid = false;

	if (p6 != 0) {
		uint32_t id = LOAD32(p6);
		if (id == 0) {
			ctx.r1.u64 = stack;
			EntityHandle_Release(ctx, base, handlePtr);
			level = ctx.r5.u64;
			r6Arg = (uint32_t)ctx.r6.u64;
			temp63 = (uint32_t)ctx.r8.u64;
			f1Value = ctx.f1.f64;
			f13Value = ctx.f13.f64;
			ca = ctx.xer.ca;
		} else {
			itemId = id;
			valid = (LOAD8(itemId + 144) & 0x40) != 0;
		}
	}

	if (valid) {
		uint32_t itemData = 0;
		bool useProgress = false;

		temp63 = (LOAD32(itemId + 40) >> 25) & 1;
		if (temp63 != 0) {
			uint32_t listPtr = LOAD32(itemId + 140);
			if (listPtr != 0) {
				uint32_t idx = LOAD8(listPtr + 57);
				uint32_t arr = LOAD32(itemId + 72);
				itemData = LOAD32((idx << 3) + arr + 4);
				useProgress = true;
			} else {
				uint32_t pos = LOAD32(itemId + 72);
				uint32_t end = LOAD32(itemId + 76);
				r6Arg = end;
				STORE32(stack + 80, 0);
				STORE32(stack + 84, pos);

				uint32_t diff = end - pos;
				ca = ((int32_t)diff < 0) && ((diff & 0x7) != 0);
				int32_t count = (int32_t)diff >> 3;
				if (count > 0) {
					do {
						ca = ((int32_t)count < 0) && (((uint32_t)count & 1) != 0);
						int32_t half = count >> 1;
						temp63 = (uint32_t)(half << 3);
						uint32_t mid = temp63 + pos;
						if (!((int32_t)LOAD32(mid) < 57)) {
							pos = mid - temp63;
							count = half;
						} else {
							count = count - half - 1;
							pos = mid + 8;
						}
					} while (count > 0);
					STORE32(stack + 84, pos);
				}

				if (pos != end && !((int32_t)LOAD32(pos) > 57)) {
					STORE64(stack + 88, LOAD64(stack + 80));
					uint32_t tmp = LOAD32(stack + 92);
					itemData = LOAD32(tmp + 4);
				} else {
					itemData = LOAD32(end + 4);
				}
				useProgress = true;
			}
		}
		if (useProgress) {
			ctx.fpscr.disableFlushMode();
			chapterProgress = double(LOAD_F32(itemData + 88));
		}
	}

	if ((uint32_t)sourceList != 0) {
		ctx.r1.u64 = stack;
		ctx.r5.u64 = level;
		ctx.r6.u64 = r6Arg;
		ctx.xer.ca = ca;
		GameDB_GetArrayField(ctx, base, stack + 104, sourceList, temp63);
		f1Value = ctx.f1.f64;
		f13Value = ctx.f13.f64;
		ca = ctx.xer.ca;
		ctx.fpscr.disableFlushMode();
		double totalWeight = baseWeight;

		STORE32(stack + 132, 0);
		STORE32(stack + 136, 0);
		STORE32(stack + 140, 0);

		uint32_t itemCount = LOAD32(stack + 108);
		if (itemCount != 0) {
			uint32_t i = LOAD32(stack + 112);
			int32_t remaining = (int32_t)itemCount;

			do {
				if (i != itemCount) {
					ctx.xer.ca = ca;
					uint32_t candidate = (uint32_t)ItemEntryList_GetNext(ctx, base, stack + 104);
					if (candidate != 0) {
						uint64_t value2 = HashMapU32_FindValue(ctx, base, LOAD32(globalBase + 27600), candidate);
						uint32_t record = (uint32_t)value2;
						if (record != 0) {
							GameDB_GetFloatByName(ctx, base, value2, str_TXT_820B3308_B_);
							f1Value = ctx.f1.f64;
							ctx.fpscr.disableFlushMode();
							if (!(chapterProgress < f1Value)) {
								GameDB_GetFloatByName(ctx, base, value2, str_TXT_820B331C_B_);
								f1Value = ctx.f1.f64;
								ctx.fpscr.disableFlushMode();
								if (!(chapterProgress > f1Value)) {
									int32_t minFurniture = (int32_t)GameDB_GetIntByName(ctx, base, value2, str_TXT_820C7348_B_);
									if (levelPlusOne >= minFurniture) {
										int32_t maxFurniture = (int32_t)GameDB_GetIntByName(ctx, base, value2, str_TXT_820C735C_B_);
										if (levelPlusOne <= maxFurniture) {
											GameDB_GetFloatByName(ctx, base, value2, str_TXT_820B0E64_B_);
											f1Value = ctx.f1.f64;
											ctx.fpscr.disableFlushMode();
											double itemWeight = f1Value;
											if (itemWeight > baseWeight) {
												IdRef_ConstructFromId(ctx, base, stack + 80, candidate);
												if (LOAD32(stack + 80) != 0) {
													uint64_t idRef = IdRef_Get(ctx, base, stack + 80);
													uint32_t property = Region_GetProperty(ctx, base, idRef, str_TXT_820C7370_B_);
													IdRef_ConstructFromId(ctx, base, stack + 96, property);
													if (LOAD32(stack + 96) != 0) {
														STORE32(stack + 88, property);
														ctx.fpscr.disableFlushMode();
														STORE_F32(stack + 92, (float)itemWeight);
														totalWeight = (double)(float)(itemWeight + totalWeight);
														Vector_PushBack_82296D48(ctx, base, stack + 128, stack + 88);
														f1Value = ctx.f1.f64;
														f13Value = ctx.f13.f64;
													} else {
														ca = (uint32_t)remaining > 0;
														remaining--;
														continue;
													}
												}
											}
										}
									}
								}
							}
						}
					}
					i = (uint32_t)((int32_t)i + 1);
					STORE32(stack + 112, i);
				}
				ca = (uint32_t)remaining > 0;
				remaining--;
			} while (remaining != 0);

			uint32_t begin = LOAD32(stack + 132);
			if (begin != 0) {
				uint32_t end = LOAD32(stack + 136);
				uint32_t diff = end - begin;
				ca = ((int32_t)diff < 0) && ((diff & 0x7) != 0);
				if (((int32_t)diff >> 3) != 0) {
					uint32_t a = LOAD32(globalBase + 26912);
					uint32_t b = LOAD32(a + 12);
					uint32_t c = LOAD32(b + 88);
					uint32_t rng = LOAD32(c + 4) + 120;

					ctx.fpscr.disableFlushMode();
					ctx.xer.ca = ca;
					f1Value = Rng_NextScaledFloat(ctx, base, rng, totalWeight);
					f13Value = ctx.f13.f64;
					ca = ctx.xer.ca;

					begin = LOAD32(stack + 132);
					end = LOAD32(stack + 136);
					ctx.fpscr.disableFlushMode();
					double cumulative = baseWeight;
					uint32_t ptr = begin;

					if (begin > end) {
						ppc_trap(ctx, base, 22);
					}
					for (;;) {
						if (begin > end) {
							ppc_trap(ctx, base, 22);
						}
						if (ptr == end) {
							break;
						}
						if (ptr >= end) {
							ppc_trap(ctx, base, 22);
						}
						ctx.fpscr.disableFlushMode();
						bool aboveOld = f1Value > cumulative;
						STORE64(stack + 88, LOAD64(ptr));
						f13Value = double(LOAD_F32(stack + 92));
						cumulative = (double)(float)(f13Value + cumulative);
						if (aboveOld && !(f1Value > cumulative)) {
							uint32_t selected = LOAD32(stack + 88);
							if (selected != 0) {
								result = selected;
							}
							break;
						}
						if (ptr >= end) {
							ppc_trap(ctx, base, 22);
						}
						ptr += 8;
					}
				}

				ctx.f1.f64 = f1Value;
				ctx.f13.f64 = f13Value;
				ctx.xer.ca = ca;
				HandleTarget_Free(ctx, base, begin);
				f1Value = ctx.f1.f64;
				f13Value = ctx.f13.f64;
				ca = ctx.xer.ca;
			}
		}

		STORE32(stack + 132, 0);
		STORE32(stack + 136, 0);
		STORE32(stack + 140, 0);
		uint32_t handle2 = LOAD32(stack + 104);
		ctx.f1.f64 = f1Value;
		ctx.f13.f64 = f13Value;
		ctx.xer.ca = ca;
		HandleTarget_Free(ctx, base, handle2);
		f1Value = ctx.f1.f64;
		ca = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 320);
	ctx.r1.u64 = stack;
	ctx.xer.ca = ca;
	return result;
}
PROMOTED_ENTRY(40, sub_826198A0, 0x826198A0) { ctx.r3.u64 = CECInventory_SelectWeightedItem(ctx, base, ctx.r4.u64, ctx.r5.u64); }

uint64_t CECInventory_FillFromInitialItems(CpuState& ctx, uint8_t* base, uint64_t inventoryAddr) {
	constexpr uint32_t kGlobals8349 = 0x83490000;
	constexpr uint32_t kStringRefCount = 0x83496EB8;
	if (!UseLiftedCode(40, 0x82619CB0)) { ctx.r3.u64 = inventoryAddr; __imp__sub_82619CB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82619CB0);

	CECInventory* inventory = GameObject<CECInventory>(base, inventoryAddr);

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 240);
	ctx.r1.u64 = stack;

	// Scratch slot reused for an id-ref / item-name CCharString.
	uint32_t itemNameSlot = stack + 80;

	uint64_t idHandle = Component_GetId(ctx, base, itemNameSlot, inventoryAddr);
	uint64_t idRef = IdRef_Get(ctx, base, idHandle);
	uint64_t initialItemsList = GameDB_ReadU32Field(ctx, base, idRef, -2113113216);

	uint64_t result = initialItemsList;
	uint64_t r4Out = 0;
	if (initialItemsList != 0) {
		uint32_t itemListSlot = stack + 88;
		GameDB_GetArrayField(ctx, base, itemListSlot, initialItemsList, ctx.r8.u64);

		uint32_t entries = LOAD32(stack + 88);
		uint32_t entryEnd = LOAD32(stack + 92);
		uint32_t entryIndex = LOAD32(stack + 96);

		while (entryIndex != entryEnd) {
			uint32_t entryAddr = entries + entryIndex * 12;
			uint32_t entryKind = LOAD32(entryAddr);

			if (entryKind == 4) {
				uint32_t itemRecord = LOAD32(entryAddr + 8);
				uint32_t hashTableGlobal = LOAD32(kGlobals8349 + 27600);
				uint32_t hashTable = LOAD32(LOAD32(hashTableGlobal) + 12);
				uint64_t itemKey = LOAD32(itemRecord);
				uint64_t itemName = HashTable_FindValuePtr(ctx, base, hashTable, itemKey);

				CCharString_ConstructFromCStr(ctx, base, itemNameSlot, itemName, -1);

				uint32_t nameObj = LOAD32(itemNameSlot);
				if (nameObj != 0 && LOAD32(nameObj + 4) != 0) {
					RandomItem_GenerateFromNamedRecord(ctx, base, stack + 112, inventoryAddr, itemNameSlot, ctx.r8.u64);
					uint32_t namedList = LOAD32(stack + 112);
					if (namedList != 0) {
						PtrList_RemoveAll(ctx, base, namedList, stack + 112);
					}
					STORE32(stack + 112, 0);
				}

				inventory->m_filledFromInitialItems = 1;
				CCharString_Release(ctx, base, itemNameSlot);
				STORE32(kStringRefCount, LOAD32(kStringRefCount) - 1);
				STORE32(itemNameSlot, 0);
			} else if (entryKind == 7) {
				uint32_t tableEntry = LOAD32(entryAddr + 8);
				uint32_t tableId = LOAD32(tableEntry);
				if (tableId != 0) {
					RandomItem_GenerateFromTableEntry(ctx, base, stack + 128, inventoryAddr, tableId, ctx.r8.u64);
					uint32_t tableList = LOAD32(stack + 128);
					if (tableList != 0) {
						PtrList_RemoveAll(ctx, base, tableList, stack + 128);
					}
					STORE32(stack + 128, 0);
				}
				inventory->m_filledFromInitialItems = 1;
			}

			++entryIndex;
		}

		result = HandleTarget_Free(ctx, base, entries);
		r4Out = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	return result;
}
PROMOTED_ENTRY(40, sub_82619CB0, 0x82619CB0) { ctx.r3.u64 = CECInventory_FillFromInitialItems(ctx, base, ctx.r3.u64); }

void CECInventory_SyncItemViewedFlag(CpuState& ctx, uint8_t* base, uint32_t inventoryAddr) {
	if (!UseLiftedCode(40, 0x8261A3B8)) { ctx.r3.u64 = inventoryAddr; __imp__sub_8261A3B8(ctx, base); return; }
	LiftedFrame frame(0x8261A3B8);
	uint32_t stack = ctx.r1.u32;
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r8Value = ctx.r8.u64;
	bool ca = ctx.xer.ca;
	CECInventory* inventory = GameObject<CECInventory>(base, inventoryAddr);
	uint32_t owner = inventory->m_owner;

	if (((LOAD32(owner + 36) >> 23) & 1) == 0) {
		ctx.r6.u64 = r6Value;
		ctx.r8.u64 = r8Value;
		ctx.xer.ca = ca;
		return;
	}

	uint32_t entryValue;
	uint32_t indexedEntry = LOAD32(owner + 140);
	if (indexedEntry != 0) {
		uint32_t table = LOAD32(owner + 72);
		uint32_t index = LOAD8(indexedEntry + 23);
		entryValue = LOAD32(table + (index << 3) + 4);
	} else {
		uint32_t begin = LOAD32(owner + 72);
		uint32_t end = LOAD32(owner + 76);
		r6Value = end;
		STORE32(stack - 16, 0);
		STORE32(stack - 12, begin);
		uint32_t low = begin;
		uint32_t diff = end - begin;
		ca = ((int32_t)diff < 0) && ((diff & 0x7) != 0);
		int32_t count = (int32_t)diff >> 3;
		if (count > 0) {
			do {
				ca = (count < 0) && ((count & 1) != 0);
				int32_t mid = count >> 1;
				uint32_t midOffset = (uint32_t)mid << 3;
				low += midOffset;
				r8Value = midOffset;
				if ((int32_t)LOAD32(low) < 23) {
					count = count - mid - 1;
					low += 8;
				} else {
					low -= midOffset;
					count = mid;
				}
			} while (count > 0);
			STORE32(stack - 12, low);
		}
		if (low != end && (int32_t)LOAD32(low) <= 23) {
			STORE64(stack - 16, LOAD64(stack - 16));
			entryValue = LOAD32(low + 4);
		} else {
			entryValue = LOAD32(end + 4);
		}
	}

	if (((LOAD32(owner + 44) >> 14) & 1) == 0) {
		ctx.r6.u64 = r6Value;
		ctx.r8.u64 = r8Value;
		ctx.xer.ca = ca;
		return;
	}

	uint8_t current = LOAD8(entryValue + 35);
	uint8_t desired = (inventory->m_14 != 0) ? 1 : 0;
	if (current != desired) {
		STORE8(entryValue + 35, desired);
	}
	ctx.r6.u64 = r6Value;
	ctx.r8.u64 = r8Value;
	ctx.xer.ca = ca;
}
PROMOTED_ENTRY(40, sub_8261A3B8, 0x8261A3B8) { CECInventory_SyncItemViewedFlag(ctx, base, ctx.r3.u32); }

uint64_t ItemList_SumCount(CpuState& ctx, uint8_t* base, uint32_t inventoryAddr) {
	if (!UseLiftedCode(40, 0x8261C0B8)) { ctx.r3.u64 = inventoryAddr; __imp__sub_8261C0B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8261C0B8);
	CECInventory* inventory = GameObject<CECInventory>(base, inventoryAddr);

	// m_10 is the end/sentinel node of the circular list; walk it from next to next.
	uint32_t endNode = inventory->m_10;
	uint32_t node = endNode;
	uint64_t lastItem = ctx.r7.u64;
	uint64_t totalCount = 0;

	for (;;) {
		node = LOAD32(node);
		if (node == endNode) {
			ctx.r7.u64 = lastItem;
			ctx.r8.u64 = endNode;
			return totalCount;
		}
		lastItem = LOAD32(node + 8);
		totalCount += LOAD32((uint32_t)lastItem + 12);
	}
}
PROMOTED_ENTRY(40, sub_8261C0B8, 0x8261C0B8) { ctx.r3.u64 = ItemList_SumCount(ctx, base, ctx.r3.u32); }

uint32_t CECInventory_ApplyItemEffects(CpuState& ctx, uint8_t* base, uint64_t inventory, uint64_t itemSource) {
	constexpr int32_t str_TXT_82000F7C_B_ = int32_t(0x82000F7C);
	constexpr int32_t str_TXT_820AC354_B_ = int32_t(0x820AC354);
	constexpr int32_t str_TXT_820AC364_B_ = int32_t(0x820AC364);
	constexpr int32_t str_TXT_820C7570_B_ = int32_t(0x820C7570);
	constexpr int32_t str_TXT_820C7580_B_ = int32_t(0x820C7580);
	constexpr int32_t str_TXT_820C75A0_B_ = int32_t(0x820C75A0);
	constexpr int32_t str_TXT_820C75AC_B_ = int32_t(0x820C75AC);
	constexpr int32_t str_TXT_820C75B8_B_ = int32_t(0x820C75B8);
	constexpr int32_t str_TXT_820C75D0_B_ = int32_t(0x820C75D0);
	constexpr int32_t str_TXT_820A9080_B_ = int32_t(0x820A9080);
	constexpr uint64_t kExpressionNameHashSeed = 0xFFFFFFFF811C9DC5ull;  // FNV-1 offset basis
	if (!UseLiftedCode(40, 0x8261D8E8)) { ctx.r3.u64 = inventory; ctx.r4.u64 = itemSource; __imp__sub_8261D8E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8261D8E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 208);

	// The original keeps the item argument in r4 across the whole body and
	// publishes it (updated by the callees) again on the failure exit.
	uint64_t itemSourceRegister = itemSource;

	// GameDB float fields are truncated to int with cvttsd2si semantics.
	auto floatToInt = [&](double value) -> int32_t {
		ctx.fpscr.disableFlushMode();
		if (std::isnan(value)) return INT32_MIN;
		if (value > (double)INT32_MAX) return INT32_MAX;
		if (value < (double)INT32_MIN) return INT32_MIN;
		return (int32_t)value;
	};

	// Builds the effect object described by the item and appends it to the
	// inventory's effect list.
	auto addEffect = [&]() -> uint32_t {
		uint32_t sourceEntity = LOAD32((uint32_t)itemSource);
		if (sourceEntity == 0) {
			ctx.r4.u64 = itemSourceRegister;
			return (uint32_t)inventory;
		}
		int32_t entityType = (int32_t)LOAD32(sourceEntity + 16);

		if (entityType != 5 && entityType != 6) {
			if (entityType != 16) {
				ctx.r4.u64 = itemSourceRegister;
				return (uint32_t)inventory;
			}

			// Weapon/expression items: raise a dog training level or unlock an expression.
			ctx.r1.u64 = stack;
			uint64_t itemComponentRef = IdRef_Get(ctx, base, (uint64_t)sourceEntity + 4);
			uint32_t itemComponent = GameDB_ReadU32Field(ctx, base, itemComponentRef, str_TXT_820A9080_B_);
			itemSourceRegister = ctx.r4.u64;
			if (itemComponent == 0) {
				ctx.r4.u64 = itemSourceRegister;
				return 0;
			}
			uint32_t TXT_820AC354_L_ = GameDB_ReadU32Field(ctx, base, itemComponent, str_TXT_820AC354_B_);
			itemSourceRegister = ctx.r4.u64;
			if (TXT_820AC354_L_ == 0) {
				ctx.r4.u64 = itemSourceRegister;
				return 0;
			}

			int32_t dogCombatLevel = (int32_t)GameDB_GetIntByName(ctx, base, TXT_820AC354_L_, str_TXT_820C75B8_B_);
			itemSourceRegister = ctx.r4.u64;
			if (dogCombatLevel <= 0) {
				int32_t dogSniffingLevel = (int32_t)GameDB_GetIntByName(ctx, base, TXT_820AC354_L_, str_TXT_820C75D0_B_);
				itemSourceRegister = ctx.r4.u64;
				if (dogSniffingLevel <= 0) {
					uint32_t expressionNameHash = String_HashFnv1(ctx, base, str_TXT_820AC364_B_, kExpressionNameHashSeed);
					uint32_t expression = GameDB_LookupMappedValueByField(ctx, base, TXT_820AC354_L_, expressionNameHash);
					itemSourceRegister = ctx.r4.u64;
					if (expression == 0) {
						ctx.r4.u64 = itemSourceRegister;
						return 0;
					}
					STORE32(stack + 80, 0);
					uint32_t category = GameDB_GetExpressionCategory(ctx, base, expression, stack + 80);
					itemSourceRegister = ctx.r4.u64;
					if (LOAD32(stack + 80) != 7) {
						ctx.r4.u64 = itemSourceRegister;
						return category;
					}
				}
			}

			uint32_t TXT_820C7580_L_ = GameDB_ReadU32Field(ctx, base, itemComponent, str_TXT_820C7580_B_);
			itemSourceRegister = ctx.r4.u64;
			if (TXT_820C7580_L_ == 0) {
				ctx.r4.u64 = itemSourceRegister;
				return 0;
			}

			STORE32(stack + 80, 0);
			uint32_t setButtonResult = GameDB_GetDpadButton(ctx, base, TXT_820C7580_L_, stack + 80);
			itemSourceRegister = ctx.r4.u64;
			uint32_t dpadButton = LOAD32(stack + 80);
			if (dpadButton == 0) {
				ctx.r4.u64 = itemSourceRegister;
				return setButtonResult;
			}
			int32_t TXT_82000F7C_L_ = (int32_t)GameDB_GetIntByName(ctx, base, TXT_820C7580_L_, str_TXT_82000F7C_B_);

			uint32_t effect = (uint32_t)operator_new(ctx, base, 36);
			if (effect != 0) {
				for (uint32_t offset = 0; offset < 36; offset += 4) STORE32(effect + offset, 0);
			}

			STORE32(stack + 112, 0);
			STORE32(stack + 116, 0);
			STORE32(stack + 120, 0);
			STORE32(stack + 124, 0);
			IdRef_Assign(ctx, base, stack + 112, itemSource);
			if (effect != stack + 112) {
				IdRef_Assign(ctx, base, effect, stack + 112);
			}
			uint32_t tempOwner = LOAD32(stack + 112);
			if (tempOwner != 0) {
				PtrList_RemoveAll(ctx, base, tempOwner, stack + 112);
			}

			uint32_t ownerEntity = LOAD32((uint32_t)itemSource);
			STORE32(stack + 112, 0);
			if (ownerEntity != 0) {
				ownerEntity = LOAD32(ownerEntity + 4);
			}
			STORE32(effect + 16, ownerEntity);
			STORE32(effect + 20, dpadButton);
			STORE32(effect + 24, (uint32_t)TXT_82000F7C_L_);
			STORE32(effect + 28, 0);
			STORE32(effect + 32, 0);

			STORE32(stack + 88, effect);
			uint32_t handle = SharedHandle_Create(ctx, base, stack + 88);
			PtrList_PushBack(ctx, base, inventory + 28, handle);
			return SharedHandle_Release(ctx, base, stack + 88);
		}

		// Potion/health items: only ones with a positive health modifier.
		ctx.r1.u64 = stack;
		uint64_t itemComponentRef = IdRef_Get(ctx, base, (uint64_t)sourceEntity + 4);
		uint32_t itemComponent = GameDB_ReadU32Field(ctx, base, itemComponentRef, str_TXT_820A9080_B_);
		itemSourceRegister = ctx.r4.u64;
		if (itemComponent == 0) {
			ctx.r4.u64 = itemSourceRegister;
			return 0;
		}
		uint32_t TXT_820AC354_L_ = GameDB_ReadU32Field(ctx, base, itemComponent, str_TXT_820AC354_B_);
		itemSourceRegister = ctx.r4.u64;
		if (TXT_820AC354_L_ == 0) {
			ctx.r4.u64 = itemSourceRegister;
			return 0;
		}
		int32_t TXT_820C7570_L_ = (int32_t)GameDB_GetIntByName(ctx, base, TXT_820AC354_L_, str_TXT_820C7570_B_);
		itemSourceRegister = ctx.r4.u64;
		if (TXT_820C7570_L_ <= 0) {
			ctx.r4.u64 = itemSourceRegister;
			return (uint32_t)TXT_820C7570_L_;
		}
		uint32_t TXT_820C7580_L_ = GameDB_ReadU32Field(ctx, base, itemComponent, str_TXT_820C7580_B_);
		itemSourceRegister = ctx.r4.u64;
		if (TXT_820C7580_L_ == 0) {
			ctx.r4.u64 = itemSourceRegister;
			return 0;
		}

		STORE32(stack + 80, 0);
		uint32_t setButtonResult = GameDB_GetDpadButton(ctx, base, TXT_820C7580_L_, stack + 80);
		itemSourceRegister = ctx.r4.u64;
		uint32_t dpadButton = LOAD32(stack + 80);
		if (dpadButton == 0) {
			ctx.r4.u64 = itemSourceRegister;
			return setButtonResult;
		}
		int32_t TXT_82000F7C_L_ = (int32_t)GameDB_GetIntByName(ctx, base, TXT_820C7580_L_, str_TXT_82000F7C_B_);

		uint32_t effect = (uint32_t)operator_new(ctx, base, 36);
		if (effect != 0) {
			for (uint32_t offset = 0; offset < 36; offset += 4) STORE32(effect + offset, 0);
		}

		STORE32(stack + 128, 0);
		STORE32(stack + 132, 0);
		STORE32(stack + 136, 0);
		STORE32(stack + 140, 0);
		IdRef_Assign(ctx, base, stack + 128, itemSource);
		if (effect != stack + 128) {
			IdRef_Assign(ctx, base, effect, stack + 128);
		}
		uint32_t tempOwner = LOAD32(stack + 128);
		if (tempOwner != 0) {
			PtrList_RemoveAll(ctx, base, tempOwner, stack + 128);
		}

		uint32_t ownerEntity = LOAD32((uint32_t)itemSource);
		STORE32(stack + 128, 0);
		if (ownerEntity != 0) {
			ownerEntity = LOAD32(ownerEntity + 4);
		}
		STORE32(effect + 16, ownerEntity);
		STORE32(effect + 20, dpadButton);
		STORE32(effect + 24, (uint32_t)TXT_82000F7C_L_);

		GameDB_GetFloatByName(ctx, base, TXT_820C7580_L_, str_TXT_820C75A0_B_);
		STORE32(effect + 28, (uint32_t)floatToInt(ctx.f1.f64));
		GameDB_GetFloatByName(ctx, base, TXT_820C7580_L_, str_TXT_820C75AC_B_);
		STORE32(effect + 32, (uint32_t)floatToInt(ctx.f1.f64));

		STORE32(stack + 96, effect);
		uint32_t handle = SharedHandle_Create(ctx, base, stack + 96);
		PtrList_PushBack(ctx, base, inventory + 28, handle);
		return SharedHandle_Release(ctx, base, stack + 96);
	};

	uint32_t returnValue = addEffect();
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return returnValue;
}
PROMOTED_ENTRY(40, sub_8261D8E8, 0x8261D8E8) { ctx.r3.u64 = CECInventory_ApplyItemEffects(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECInventory_OnDeath(CpuState& ctx, uint8_t* base, uint64_t inventoryAddr) {
	constexpr int32_t str_TXT_820C75E8_B_ = int32_t(0x820C75E8);
	if (!UseLiftedCode(40, 0x8261DDB0)) { ctx.r3.u64 = inventoryAddr; __imp__sub_8261DDB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8261DDB0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECInventory* inventory = GameObject<CECInventory>(base, inventoryAddr);

	stack = PushStackFrame(base, stack, 160);
	ctx.r1.u64 = stack;

	uint64_t idSource = Component_GetId(ctx, base, (int64_t)(uint64_t)stack + 80, inventoryAddr);
	uint64_t idRef = IdRef_Get(ctx, base, idSource);
	uint64_t TXT_820C75E8_L_ = str_TXT_820C75E8_B_;
	uint32_t shouldDropAll = GameDB_ReadBoolField_82303F38(ctx, base, idRef, TXT_820C75E8_L_);

	if (uint32_t(shouldDropAll & 0xFF) != 0) {
		uint32_t itemCount = ItemList_SumCount(ctx, base, inventoryAddr);

		// hand the whole item list over to whatever the owner points at
		uint32_t itemHolder = LOAD32(uint32_t(inventory->m_owner) + 124);
		uint32_t itemHolderVtable = LOAD32(itemHolder);
		uint32_t giveItemsFn = LOAD32(itemHolderVtable + 64);
		callTarget.u64 = (uint64_t)giveItemsFn;
		ctx.r3.u64 = (int64_t)(uint64_t)stack + 80;
		ctx.r4.u64 = itemHolder;
		ctx.r9.u64 = giveItemsFn;
		ctx.r10.u64 = itemHolderVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		for (int32_t itemIndex = 0; itemIndex < (int32_t)itemCount; ++itemIndex) {
			Inventory_SelectItemByWeight(ctx, base, (int64_t)(uint64_t)stack + 96, inventoryAddr, (uint64_t)itemIndex);
			uint32_t item = LOAD32(stack + 96);
			if (item != 0) {
				PtrList_RemoveAll(ctx, base, item, (int64_t)(uint64_t)stack + 96);
			}
			STORE32(stack + 96, 0);
		}
	}

	uint32_t owner = inventory->m_owner;
	uint32_t componentTypeFn = LOAD32(uint32_t(inventory->vtable) + 16);
	callTarget.u64 = (uint64_t)componentTypeFn;
	ctx.r3.u64 = inventoryAddr;
	ctx.r10.u64 = componentTypeFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t componentType = ctx.r3.u64;

	uint64_t removed = Entity_RemoveComponentByType(ctx, base, (uint64_t)owner, componentType, ctx.r8.u64);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return removed;
}
PROMOTED_ENTRY(40, sub_8261DDB0, 0x8261DDB0) { ctx.r3.u64 = CECInventory_OnDeath(ctx, base, ctx.r3.u64); }
