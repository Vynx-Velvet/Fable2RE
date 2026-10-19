// CECCreatureGenerator (vtable 0x820DF288): methods of the class as readable C++.
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

uint64_t CECCreatureGenerator_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8C80_B_ = int32_t(0x820C8C80);
	if (!UseLiftedCode(59, 0x8286FD80)) { ctx.r3.u64 = classNameString; __imp__sub_8286FD80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8286FD80);
	uint32_t stack = ctx.r1.u64;
	uint64_t classNameCStr = str_TXT_820C8C80_B_;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameCStr, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(59, sub_8286FD80, 0x8286FD80) { ctx.r3.u64 = CECCreatureGenerator_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82870A20(CpuState& ctx, uint8_t* base, uint64_t creatureGeneratorAddr, uint64_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(59, 0x82870A20)) { ctx.r3.u64 = creatureGeneratorAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82870A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82870A20);
	uint32_t stack = ctx.r1.u64;
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, creatureGeneratorAddr + 56);
	List_Destroy(ctx, base, creatureGeneratorAddr + 44);

	uint32_t defaultHandle = uint32_t(g_820F1664);
	creatureGenerator->m_24 = defaultHandle;
	EntityHandle_Release(ctx, base, creatureGeneratorAddr + 36);

	const uint32_t nullHandle = 0;
	creatureGenerator->m_28 = nullHandle;
	List_ClearRefCountedHandleNodes(ctx, base, creatureGeneratorAddr + 24);

	uint32_t handleAt1C = creatureGenerator->m_1C;
	HandleTarget_Free(ctx, base, handleAt1C);
	creatureGenerator->m_1C = nullHandle;

	List_ClearFreeNodes(ctx, base, creatureGeneratorAddr + 12);

	uint32_t handleAt10 = creatureGenerator->m_10;
	HandleTarget_Free(ctx, base, handleAt10);
	creatureGenerator->m_10 = nullHandle;

	creatureGenerator->vtable = 0x820A8D10u;

	uint64_t result = creatureGeneratorAddr;
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, result);
		result = creatureGeneratorAddr;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(59, sub_82870A20, 0x82870A20) { ctx.r3.u64 = n_sub_82870A20(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82870AB8(CpuState& ctx, uint8_t* base, uint64_t creatureGeneratorAddr, uint64_t arg2) {
	constexpr int32_t str_TXT_820D4C90_B_ = int32_t(0x820D4C90);
	constexpr int32_t str_TXT_820D4C9C_B_ = int32_t(0x820D4C9C);
	constexpr int32_t str_TXT_820DEEE8_B_ = int32_t(0x820DEEE8);
	constexpr int32_t str_TXT_820DEEFC_B_ = int32_t(0x820DEEFC);
	constexpr int32_t str_TXT_820DEF08_B_ = int32_t(0x820DEF08);
	constexpr int32_t str_TXT_820DEF20_B_ = int32_t(0x820DEF20);
	constexpr int32_t str_TXT_820DEF30_B_ = int32_t(0x820DEF30);
	constexpr int32_t str_TXT_820DEF44_B_ = int32_t(0x820DEF44);
	constexpr int32_t str_TXT_820DEF58_B_ = int32_t(0x820DEF58);
	constexpr int32_t str_TXT_820DEF70_B_ = int32_t(0x820DEF70);
	constexpr int32_t str_TXT_820DEF84_B_ = int32_t(0x820DEF84);
	constexpr int32_t str_TXT_820DEFA0_B_ = int32_t(0x820DEFA0);
	constexpr int32_t str_TXT_820DEFD8_B_ = int32_t(0x820DEFD8);
	constexpr int32_t str_TXT_820DEFF4_B_ = int32_t(0x820DEFF4);
	constexpr int32_t str_TXT_820DF004_B_ = int32_t(0x820DF004);
	constexpr int32_t str_TXT_820DF010_B_ = int32_t(0x820DF010);
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	if (!UseLiftedCode(59, 0x82870AB8)) { ctx.r3.u64 = creatureGeneratorAddr; ctx.r4.u64 = arg2; __imp__sub_82870AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82870AB8);
	uint32_t stack = ctx.r1.u64;
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);
	stack = PushStackFrame(base, stack, 192);
	ctx.r1.u64 = stack;

	uint64_t spawnedName = n_sub_82345978(ctx, base, arg2, str_TXT_820DEEE8_B_);
	CCharString_AssignFromCStr(ctx, base, creatureGeneratorAddr + 56, spawnedName);

	uint32_t TXT_820DEEFC_L_ = GameDB_ReadBoolField_82303F38(ctx, base, arg2, str_TXT_820DEEFC_B_);
	creatureGenerator->m_3C = (uint8_t)TXT_820DEEFC_L_;

	GameDB_GetFloatByName(ctx, base, arg2, str_TXT_820D4C90_B_);
	creatureGenerator->m_70 = float(ctx.f1.f64);
	GameDB_GetFloatByName(ctx, base, arg2, str_TXT_820DEF08_B_);
	creatureGenerator->m_78 = float(ctx.f1.f64);
	GameDB_GetFloatByName(ctx, base, arg2, str_TXT_820D4C9C_B_);
	creatureGenerator->m_74 = float(ctx.f1.f64);

	uint32_t TXT_820DEF20_L_ = GameDB_GetIntByName(ctx, base, arg2, str_TXT_820DEF20_B_);
	creatureGenerator->m_68 = TXT_820DEF20_L_;

	// patrol radius must sit between the minimum radius and the chase radius
	float minRadius = LOAD_F32(0x820994B4);
	if (creatureGenerator->m_74 > creatureGenerator->m_70
	    && creatureGenerator->m_70 > minRadius
	    && creatureGenerator->m_74 > minRadius) {
		creatureGenerator->m_74 = creatureGenerator->m_70 * LOAD_F32(0x82099334);
	}

	uint32_t isDynamic = GameDB_ReadBoolField_82303F38(ctx, base, arg2, str_TXT_820DEF30_B_);
	creatureGenerator->m_3F = (uint8_t)isDynamic;
	if ((isDynamic & 0xFF) != 0) {
		GameDB_GetFloatByName(ctx, base, arg2, str_TXT_820DEF44_B_);
		creatureGenerator->m_40 = float(ctx.f1.f64);
		GameDB_GetFloatByName(ctx, base, arg2, str_TXT_820DEF58_B_);
		creatureGenerator->m_44 = float(ctx.f1.f64);
		uint32_t spawnLimit = GameDB_GetIntByName(ctx, base, arg2, str_TXT_820DEF70_B_);
		float createRadius = creatureGenerator->m_40;
		creatureGenerator->m_48 = spawnLimit;
		if (createRadius == minRadius) {
			creatureGenerator->m_40 = creatureGenerator->m_70;
		}
		if (creatureGenerator->m_44 == minRadius) {
			creatureGenerator->m_44 = creatureGenerator->m_40 * LOAD_F32(0x8209DA4C);
		}
	}

	GameDB_GetFloatByName(ctx, base, arg2, str_TXT_820DEF84_B_);
	creatureGenerator->m_4C = float(ctx.f1.f64);

	uint32_t forceFaceHero = GameDB_ReadBoolField_82303F38(ctx, base, arg2, str_TXT_820DEFA0_B_);
	creatureGenerator->m_51 = (uint8_t)forceFaceHero;

	uint64_t hashSeed = 0xFFFFFFFF811C9DC5ULL;
	ctx.r8.s64 = g_820E0000;
	uint64_t willGetReinforcementsKey = String_HashFnv1(ctx, base, (uint64_t)((int64_t)g_820E0000 - 4160), hashSeed);
	GameDB_ReadBoolField(ctx, base, arg2, willGetReinforcementsKey, creatureGeneratorAddr + 61);

	uint64_t teleportSpawnedCreaturesInKey = String_HashFnv1(ctx, base, str_TXT_820DEFD8_B_, hashSeed);
	GameDB_ReadBoolField(ctx, base, arg2, teleportSpawnedCreaturesInKey, creatureGeneratorAddr + 80);

	uint64_t teleportTypeKey = String_HashFnv1(ctx, base, str_TXT_820DEFF4_B_, hashSeed);
	uint32_t teleportTypeField = GameDB_FindFieldValue(ctx, base, arg2, teleportTypeKey, 2);
	if (teleportTypeField != 0) {
		creatureGenerator->m_54 = LOAD32(teleportTypeField);
	}

	uint64_t familiesValue = GameDB_ReadU32Field(ctx, base, arg2, str_TXT_820DF004_B_);
	n_sub_829FBC40(ctx, base, stack + 88, familiesValue, ctx.r8.u64);

	uint32_t idx = LOAD32(stack + 96);
	uint32_t endCount = LOAD32(stack + 92);
	uint32_t arrayBase = LOAD32(stack + 88);
	if (idx != endCount) {
		uint32_t listHead = (uint32_t)(creatureGeneratorAddr + 12);
		STORE32(stack + 88, listHead);
		uint32_t alternateTarget = 0x8349E164;
		do {
			uint32_t itemAddr = arrayBase + idx * 12;
			uint32_t payloadPtr = LOAD32(itemAddr + 8);
			uint32_t entryType = LOAD32(itemAddr);
			if (entryType == 4 && LOAD32(payloadPtr) == LOAD32(0x8349E158)) {
				payloadPtr = alternateTarget;
			}
			uint32_t familyValue = LOAD32(payloadPtr);
			STORE32(stack + 80, familyValue);
			uint32_t nodeValue = LOAD32(listHead + 4);
			STORE32(stack + 92, nodeValue);
			uint64_t token = ((uint64_t)listHead << 32) | nodeValue;
			List_InsertAfter12(ctx, base, listHead, token, stack + 80);
			idx = idx + 1;
		} while (idx != endCount);
	}
	HandleTarget_Free(ctx, base, arrayBase);

	uint64_t disableLevelSavingKey = String_HashFnv1(ctx, base, str_TXT_820DF010_B_, hashSeed);
	uint64_t disableLevelSavingField = n_sub_821E55C8(ctx, base, arg2, disableLevelSavingKey, stack + 80);
	uint32_t levelSavingDisabled = 0;
	if ((uint32_t)disableLevelSavingField != 0) {
		uint32_t fieldValue = LOAD32((uint32_t)disableLevelSavingField);
		levelSavingDisabled = (fieldValue != 0) ? 1 : 0;
	}
	if (levelSavingDisabled == 0) {
		uint32_t v4 = creatureGenerator->m_4;
		STORE8(v4 + 144, (uint8_t)((uint64_t)LOAD8(v4 + 144) | 2));
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return disableLevelSavingField;
}
PROMOTED_ENTRY(59, sub_82870AB8, 0x82870AB8) { ctx.r3.u64 = n_sub_82870AB8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82872D70(CpuState& ctx, uint8_t* base, uint64_t creatureGeneratorAddr, uint64_t arg2) {
	if (!UseLiftedCode(59, 0x82872D70)) { ctx.r3.u64 = creatureGeneratorAddr; ctx.r4.u64 = arg2; __imp__sub_82872D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82872D70);
	uint32_t stack = ctx.r1.u64;
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);
	stack = PushStackFrame(base, stack, 224);

	const uint32_t generatorAddr = (uint32_t)creatureGeneratorAddr;
	uint64_t result = creatureGeneratorAddr;
	uint64_t reg7 = 0, reg8 = 0, reg9 = 0;

	if (LOAD32(generatorAddr + 20) != 0 && LOAD32(generatorAddr + 32) != 0) {
		ctx.r1.u64 = stack;
		result = n_sub_82871AF8(ctx, base, stack + 88, generatorAddr, arg2);
		if (LOAD32(stack + 88) != 0) {
			n_sub_828702E0(ctx, base, stack + 128, stack + 88);
			const uint32_t entryValid = n_sub_82870460(ctx, base, stack + 128, ctx.r8.u64);
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			reg9 = ctx.r9.u64;

			bool ranOffListEnd = false;
			if ((entryValid & 0xFF) != 0) {
				const uint32_t container = generatorAddr + 24;
				uint32_t node = LOAD32(creatureGenerator->m_1C);
				STORE32(stack + 96, container);
				STORE32(stack + 88, 0);
				STORE32(stack + 80, 0);
				STORE32(stack + 100, node);

				for (;;) {
					if (node == LOAD32(container + 4))
						break;
					ctx.r7.u64 = reg7; ctx.r8.u64 = reg8; ctx.r9.u64 = reg9;
					const uint32_t found = n_sub_828705E0(ctx, base, stack + 128, stack + 88, stack + 80);
					reg7 = ctx.r7.u64; reg8 = ctx.r8.u64; reg9 = ctx.r9.u64;
					if ((found & 0xFF) == 0)
						break;

					const uint32_t wantedKey = LOAD32(stack + 88);
					reg8 = wantedKey;
					reg9 = LOAD32(container + 4);

					// walk forward over nodes with a larger key until one is in range
					bool advancedOffEnd = false;
					while ((int32_t)LOAD32(node + 16) > (int32_t)wantedKey) {
						node = LOAD32(node);
						if (node == LOAD32(container + 4)) {
							advancedOffEnd = true;
							break;
						}
					}
					if (advancedOffEnd) {
						ranOffListEnd = true;
						break;
					}

					const uint32_t nodeKey = LOAD32(node + 16);
					const bool compatible = (wantedKey == nodeKey)
						|| ((int32_t)wantedKey != 3 && (int32_t)nodeKey == 0)
						|| ((int32_t)wantedKey == 4 && (int32_t)nodeKey == 1);
					if (compatible) {
						const uint32_t handleOwner = LOAD32(node + 12);
						const uint32_t handleAddr = node + 8;
						bool allowed = false;
						if (handleOwner != 0) {
							const uint32_t handleId = LOAD32(handleOwner);
							if (handleId == 0) {
								ctx.r7.u64 = reg7; ctx.r8.u64 = reg8; ctx.r9.u64 = reg9; ctx.r10.u64 = handleId;
								EntityHandle_Release(ctx, base, handleAddr);
								reg7 = ctx.r7.u64; reg8 = ctx.r8.u64; reg9 = ctx.r9.u64;
							} else {
								ctx.r7.u64 = reg7; ctx.r8.u64 = reg8; ctx.r9.u64 = reg9; ctx.r10.u64 = handleId;
								const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
								reg7 = ctx.r7.u64; reg8 = ctx.r8.u64; reg9 = ctx.r9.u64;
								allowed = (LOAD8(entity + 144) & 64) != 0;
							}
						}
						if (allowed) {
							const uint32_t check = n_sub_828736C0(ctx, base, generatorAddr);
							if ((check & 0xFF) == 0) {
								ctx.r7.u64 = reg7; ctx.r8.u64 = reg8; ctx.r9.u64 = reg9;
								const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
								const uint32_t listKey = creatureGenerator->m_30;
								const uint32_t entryKey = LOAD32(stack + 80);
								const uint64_t entityData = LOAD64(entity + 20);
								const uint32_t mapAddr = generatorAddr + 44;
								STORE32(stack + 124, 0);
								STORE32(stack + 100, listKey);
								STORE32(stack + 112, entryKey);
								STORE32(stack + 96, mapAddr);
								STORE64(stack + 116, entityData);
								ctx.r9.u64 = listKey;
								n_sub_82874570(ctx, base, mapAddr, LOAD64(stack + 96), stack + 112);
								reg7 = ctx.r7.u64;
								reg9 = ctx.r9.u64;
								const uint32_t newCount = creatureGenerator->m_5C + 1;
								creatureGenerator->m_5C = newCount;
								reg8 = newCount;
							} else {
								ctx.r7.u64 = reg7; ctx.r8.u64 = reg8; ctx.r9.u64 = reg9;
								const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
								n_sub_82871DD8(ctx, base, generatorAddr, entity, LOAD32(stack + 80), arg2);
								reg7 = ctx.r7.u64; reg8 = ctx.r8.u64; reg9 = ctx.r9.u64;
							}
						}
					}
					node = LOAD32(node);
				}

				if (!ranOffListEnd && LOAD32(generatorAddr + 52) != 0) {
					ctx.r7.u64 = reg7; ctx.r8.u64 = reg8; ctx.r9.u64 = reg9;
					n_sub_82392C88(ctx, base, creatureGenerator->m_4, generatorAddr);
				}
			}

			List_ClearFreeNodes(ctx, base, stack + 128);
			result = HandleTarget_Free(ctx, base, LOAD32(stack + 132));
		}
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(59, sub_82872D70, 0x82872D70) { ctx.r3.u64 = n_sub_82872D70(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82873060(CpuState& ctx, uint8_t* base, uint64_t creatureGeneratorAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(59, 0x82873060)) { ctx.r3.u64 = creatureGeneratorAddr; __imp__sub_82873060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82873060);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;

	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);
	uint64_t generatorAddr = creatureGeneratorAddr;
	uint64_t result = creatureGeneratorAddr;
	stack = PushStackFrame(base, stack, 112);

	uint32_t state = creatureGenerator->m_64;
	if (state != 0) {
		if (state == 0xFFFFFFFFu) {
			creatureGenerator->m_64 = 3u;
		}

		// Resolve the currently selected creature from the global manager.
		uint32_t globalMgr = LOAD32((uint32_t)g_83490000 + 26912);
		uint32_t selection = LOAD32(LOAD32(globalMgr + 12) + 88);
		uint32_t selectionData = LOAD32(selection + 4);
		uint32_t handle = LOAD32(selectionData);

		ctx.r1.u64 = stack;
		ctx.r8.u64 = selectionData;
		ctx.r9.u64 = selection;
		result = EntityHandle_Get(ctx, base, handle);
		flags.ca = ctx.xer.ca;
		uint32_t targetEntity = (uint32_t)result;

		bool hasTarget = targetEntity != 0 && (LOAD8(targetEntity + 144) & 64) != 0;
		if (hasTarget && ((LOAD32(targetEntity + 40) >> 1) & 1) != 0) {
			uint32_t entryValue;
			uint32_t hashTable = LOAD32(targetEntity + 140);
			if (hashTable != 0) {
				uint32_t slotIndex = __builtin_rotateleft32(LOAD8(hashTable + 33), 3);
				uint32_t slot = slotIndex + LOAD32(targetEntity + 72);
				entryValue = LOAD32(slot + 4);
			} else {
				uint32_t begin = LOAD32(targetEntity + 72);
				uint32_t end = LOAD32(targetEntity + 76);
				STORE32(stack + 80, 0u);
				STORE32(stack + 84, begin);

				// lower_bound: first entry whose (signed) key is >= 33
				uint32_t iter = begin;
				int32_t remaining = ((int32_t)(end - begin)) >> 3;
				if (remaining > 0) {
					do {
						int32_t half = remaining >> 1;
						uint32_t mid = iter + ((uint32_t)half << 3);
						if ((int32_t)LOAD32(mid) < 33) {
							iter = mid + 8;
							remaining = remaining - half - 1;
						} else {
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 84, iter);
				}

				if (iter != end && (int32_t)LOAD32(iter) <= 33) {
					entryValue = LOAD32(iter + 4);
				} else {
					entryValue = LOAD32(end + 4);
				}
			}

			uint32_t weight = LOAD32(entryValue + 84);
			uint32_t tableEntry = LOAD32(uint32_t(creatureGenerator->m_64 << 2) + uint32_t((int64_t)g_820A0000 - 18036));
			uint64_t total = (uint64_t)tableEntry + weight + (uint64_t)creatureGenerator->m_68;

			uint64_t minusOne = total - 1;
			uint64_t clampedToMin = total - ((uint64_t)(int64_t)((int32_t)minusOne >> 31) & minusOne);
			uint64_t overTen = (uint64_t)10 - clampedToMin;
			flags.ca = ((int32_t)overTen < 0) & (((uint32_t)overTen & 0x7FFFFFFF) != 0);
			overTen = (uint64_t)(int64_t)((int32_t)overTen >> 31) & overTen;
			uint64_t amount = overTen + clampedToMin;

			ctx.r8.s64 = g_820A0000;
			ctx.xer.ca = flags.ca;
			result = n_sub_82872D70(ctx, base, generatorAddr, amount);
			flags.ca = ctx.xer.ca;
		}
	}
	creatureGenerator->m_3E = 1;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(59, sub_82873060, 0x82873060) { ctx.r3.u64 = n_sub_82873060(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82873658(CpuState& ctx, uint8_t* base, uint32_t creatureGeneratorAddr) {
	if (!UseLiftedCode(59, 0x82873658)) { ctx.r3.u64 = creatureGeneratorAddr; __imp__sub_82873658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82873658);
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);
	int32_t value = (int32_t)creatureGenerator->m_48;
	if (value > 0) return 5;
	return 15;
}
PROMOTED_ENTRY(59, sub_82873658, 0x82873658) { ctx.r3.u64 = n_sub_82873658(ctx, base, ctx.r3.u32); }

uint64_t n_sub_828736C0(CpuState& ctx, uint8_t* base, uint32_t creatureGeneratorAddr) {
	if (!UseLiftedCode(59, 0x828736C0)) { ctx.r3.u64 = creatureGeneratorAddr; __imp__sub_828736C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828736C0);
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);

	int32_t limit = creatureGenerator->m_48;
	if (limit == 0) {
		return 1;
	}

	int32_t value = creatureGenerator->m_60;
	if (value < limit) {
		return 1;
	}
	return 0;
}
PROMOTED_ENTRY(59, sub_828736C0, 0x828736C0) { ctx.r3.u64 = n_sub_828736C0(ctx, base, ctx.r3.u32); }

uint64_t n_sub_828736F0(CpuState& ctx, uint8_t* base, uint32_t creatureGeneratorAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(59, 0x828736F0)) { ctx.r3.u64 = creatureGeneratorAddr; __imp__sub_828736F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828736F0);
	uint32_t stack = ctx.r1.u64;
	uint64_t r4Out = ctx.r4.u64;
	PPCVRegister v12 = ctx.v12;
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);
	stack = PushStackFrame(base, stack, 144);

	uint32_t result = 1;
	if (LOAD8(creatureGeneratorAddr + 63) != 0) {
		int32_t currentCount = (int32_t)creatureGenerator->m_48;
		if (currentCount == 0 || (int32_t)creatureGenerator->m_60 < currentCount) {
			uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t registry = LOAD32(LOAD32(manager + 12) + 88);
			uint32_t handleOwner = LOAD32(registry + 4);
			uint32_t handle = LOAD32(handleOwner);

			ctx.r1.u64 = stack;
			ctx.r8.u64 = handleOwner;
			ctx.r9.u64 = registry;
			uint32_t entity = (uint32_t)EntityHandle_Get(ctx, base, handle);
			r4Out = ctx.r4.u64;
			v12 = ctx.v12;

			bool inside = false;
			if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
				uint32_t entityComponent = LOAD32(entity + 124);
				ctx.fpscr.disableFlushMode();
				float radius = creatureGenerator->m_40;
				double radiusSquared = double(float(double(radius) * double(radius)));

				uint32_t entityPos = stack + 80;
				uint32_t generatorPos = stack + 96;

				uint32_t readEntityPos = LOAD32(LOAD32(entityComponent) + 64);
				ctx.r3.u64 = entityPos;
				ctx.r4.u64 = entityComponent;
				ctx.r10.u64 = readEntityPos;
				REX_CALL_INDIRECT_FUNC(readEntityPos);

				uint32_t otherGenerator = creatureGenerator->m_4;
				uint32_t otherComponent = LOAD32(otherGenerator + 124);
				uint32_t otherVtblOwner = LOAD32(otherComponent);
				uint32_t readGeneratorPos = LOAD32(otherVtblOwner + 64);
				ctx.r3.u64 = generatorPos;
				ctx.r4.u64 = otherComponent;
				ctx.r7.u64 = readGeneratorPos;
				ctx.r8.u64 = otherVtblOwner;
				ctx.r9.u64 = otherGenerator;
				REX_CALL_INDIRECT_FUNC(readGeneratorPos);

				r4Out = (uint64_t)generatorPos;

				PPCVRegister vecA{};
				PPCVRegister vecB{};
				PPCVRegister dot{};
				SET_V8(vecB, VLOAD(generatorPos & ~0xFu));
				SET_V8(vecA, VLOAD(entityPos & ~0xFu));
				ctx.fpscr.enableFlushMode();
				SET_VF(v12, simde_mm_sub_ps(VF(vecA), VF(vecB)));
				SET_VF(dot, simde_mm_dp_ps(VF(v12), VF(v12), 0xEF));
				VSTORE(generatorPos & ~0xFu, V8(dot));
				ctx.fpscr.disableFlushModeUnconditional();

				inside = double(LOAD_F32(stack + 96)) < radiusSquared;
			}
			result = inside ? 1 : 0;
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	ctx.v12 = v12;
	return result;
}
PROMOTED_ENTRY(59, sub_828736F0, 0x828736F0) { ctx.r3.u64 = n_sub_828736F0(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82873918(CpuState& ctx, uint8_t* base, uint64_t creatureGeneratorAddr) {
	if (!UseLiftedCode(59, 0x82873918)) { ctx.r3.u64 = creatureGeneratorAddr; __imp__sub_82873918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82873918);
	uint32_t stack = ctx.r1.u64;
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint64_t result = n_sub_828736F0(ctx, base, creatureGeneratorAddr);
	if (((uint32_t)result & 0xFF) != 0) {
		if (creatureGenerator->m_3E != 0) {
			result = n_sub_82873988(ctx, base, creatureGeneratorAddr);
		} else {
			result = n_sub_82873060(ctx, base, creatureGeneratorAddr);
		}
		if (creatureGenerator->m_34 == 0) {
			uint32_t generatorList = creatureGenerator->m_4;
			result = Vector_RemoveByValue(ctx, base, generatorList, creatureGeneratorAddr);
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(59, sub_82873918, 0x82873918) { ctx.r3.u64 = n_sub_82873918(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82873988(CpuState& ctx, uint8_t* base, uint64_t creatureGeneratorAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(59, 0x82873988)) { ctx.r3.u64 = creatureGeneratorAddr; __imp__sub_82873988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82873988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	CECCreatureGenerator* creatureGenerator = GameObject<CECCreatureGenerator>(base, creatureGeneratorAddr);
	uint32_t saved5C = creatureGenerator->m_5C;
	uint64_t result = creatureGeneratorAddr;

	while (LOAD32((uint32_t)creatureGeneratorAddr + 52) != 0) {
		ctx.r1.u64 = stack;
		result = n_sub_828736C0(ctx, base, creatureGeneratorAddr);
		if (((uint32_t)result & 0xFF) == 0) break;

		// front node of the pending-target list (sentinel lives at m_30)
		uint32_t sentinel = creatureGenerator->m_30;
		uint32_t firstNode = LOAD32(sentinel);
		if (firstNode == sentinel) {
			ppc_trap(ctx, base, 22);
		}

		uint64_t nodeDataAddr = (uint64_t)firstNode + 8;
		uint64_t targetKeyAddr = nodeDataAddr + 4;

		// manager singleton rooted at global 0x83496920
		uint32_t lookup = LOAD32((uint32_t)g_83490000 + 26912);
		lookup = LOAD32(lookup + 12);
		lookup = LOAD32(lookup + 88);
		lookup = LOAD32(lookup + 4);
		uint32_t manager = LOAD32(lookup);

		result = n_sub_82264448(ctx, base, manager, targetKeyAddr);
		uint64_t targetEntity = result;
		if ((uint32_t)targetEntity != 0 && (LOAD8((uint32_t)targetEntity + 144) & 64) != 0) {
			uint32_t targetId = LOAD32((uint32_t)nodeDataAddr);
			uint32_t targetSubId = LOAD32((uint32_t)nodeDataAddr + 12);
			result = n_sub_82871DD8(ctx, base, creatureGeneratorAddr, targetEntity, targetId, targetSubId);
		}

		uint32_t sentinel2 = creatureGenerator->m_30;
		uint32_t head = LOAD32(sentinel2);
		if (head == sentinel2) {
			ppc_trap(ctx, base, 22);
		}
		if (head != sentinel2) {
			STORE32(LOAD32(head + 4), LOAD32(head));
			STORE32(LOAD32(head) + 4, LOAD32(head + 4));
			result = HandleTarget_Free(ctx, base, head);
			STORE32((uint32_t)creatureGeneratorAddr + 52, LOAD32((uint32_t)creatureGeneratorAddr + 52) - 1);
		}
	}

	creatureGenerator->m_5C = saved5C;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(59, sub_82873988, 0x82873988) { ctx.r3.u64 = n_sub_82873988(ctx, base, ctx.r3.u64); }
