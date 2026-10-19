// CECVillager (vtable 0x82004258): methods of the class as readable C++.
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
#include "lifted/readable_support.h"

uint64_t n_sub_821B1F00(CpuState& ctx, uint8_t* base, uint64_t villagerAddr) {
	if (!UseLiftedCode(2, 0x821B1F00)) { ctx.r3.u64 = villagerAddr; __imp__sub_821B1F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821B1F00);
	uint32_t stack = ctx.r1.u64;
	CECVillager* villager = GameObject<CECVillager>(base, villagerAddr);
	stack = PushStackFrame(base, stack, 144);

	// The result is what the last of the calls returned (the argument when none is made).
	uint64_t result = villagerAddr;
	const uint64_t handleAddr = villagerAddr + 0x14;

	// The villager's entity handle counts only when it resolves to an entity with bit 0x40 of byte +0x90 set;
	// a handle whose target word is zero is released instead.
	uint32_t usableFlag = 0;
	const uint32_t handleTarget = villager->m_18;
	if (handleTarget != 0) {
		const uint32_t target = LOAD32(handleTarget);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r10.u64 = target;
		if (target == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			usableFlag = LOAD8((uint32_t)result + 0x90) & 0x40;
		}
	}

	if (usableFlag != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		const uint32_t entity = (uint32_t)result;
		// r5-r8 and xer.ca as this call left them: the calls below receive them as the search and the list walks
		// update them (r5 ends as the last list position)
		uint64_t position = ctx.r5.u64;
		uint64_t stateR6 = ctx.r6.u64;
		uint64_t stateR7 = ctx.r7.u64;
		uint64_t stateR8 = ctx.r8.u64;
		uint8_t carry = ctx.xer.ca;

		// Type 170: bit 10 of the word at +0x38 says the entity has an entry of that type. The byte table at +0x8C,
		// when present, gives its index among the (type, value) pairs at +0x48..+0x4C; otherwise they are searched.
		if (((LOAD32(entity + 0x38) >> 10) & 1) != 0) {
			uint32_t entry;
			const uint32_t indexTable = LOAD32(entity + 0x8C);
			if (indexTable != 0) {
				const uint32_t index = LOAD8(indexTable + 170);
				entry = LOAD32(index * 8 + LOAD32(entity + 0x48) + 4);
			} else {
				const uint32_t begin = LOAD32(entity + 0x48);
				const uint32_t end = LOAD32(entity + 0x4C);
				// stack + 80 holds the search's (0, position) pair
				STORE32(stack + 80, 0u);
				const uint32_t byteCount = end - begin;
				STORE32(stack + 84, begin);
				stateR6 = end;
				carry = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
				int32_t count = (int32_t)byteCount >> 3;
				uint32_t it = begin;
				// lower_bound for type 170 (keys compare signed)
				if (count > 0) {
					// halving a positive count clears the carry
					carry = 0;
					do {
						const int32_t half = count >> 1;
						const uint32_t step = (uint32_t)half << 3;
						const uint32_t mid = it + step;
						const bool below = (int32_t)LOAD32(mid) < 170;
						stateR7 = below ? 1 : 0;
						stateR8 = step;
						if (below) {
							it = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, it);
				}
				// a missing type reads the pair at `end`
				entry = (it != end && (int32_t)LOAD32(it) <= 170) ? LOAD32(it + 4) : LOAD32(end + 4);
			}

			if (entry != 0) {
				// The lists at +0xC0, +0xD0, +0xE0 and +0xF0 (begin at +4, end at +8) are walked with the (list,
				// position) iterator at stack + 80. An element for which n_sub_828513B8 returns false goes to
				// n_sub_82637B40, which writes the iterator to continue from at stack + 88 and returns its address.
				constexpr uint32_t kListOffsets[] = {0xC0, 0xD0, 0xE0, 0xF0};
				const uint32_t iterAddr = stack + 80;
				const uint64_t nextIterAddr = (uint64_t)stack + 88;
				for (const uint32_t listOffset : kListOffsets) {
					const uint32_t listAddr = (uint32_t)villagerAddr + listOffset;
					const uint32_t first = LOAD32(listAddr + 4);
					if (first == 0) continue;
					const uint32_t listEnd = LOAD32(listAddr + 8);
					const uint32_t listBytes = listEnd - first;
					carry = (int32_t)listBytes < 0 && (listBytes & 3) != 0;
					if (((int32_t)listBytes >> 2) == 0) continue;
					position = first;
					if (first > listEnd) ppc_trap(ctx, base, 22);
					uint32_t list = listAddr;
					STORE32(iterAddr, list);
					STORE32(iterAddr + 4, first);
					for (;;) {
						const uint32_t end = LOAD32(listAddr + 8);
						if (LOAD32(listAddr + 4) > end) ppc_trap(ctx, base, 22);
						if (list == 0 || list != listAddr) ppc_trap(ctx, base, 22);
						if ((uint32_t)position == end) break;
						if (list == 0) ppc_trap(ctx, base, 22);
						if ((uint32_t)position >= LOAD32(list + 8)) ppc_trap(ctx, base, 22);
						const uint32_t element = LOAD32((uint32_t)position);
						// state the callee may pass on
						ctx.xer.ca = carry;
						const bool passes = (n_sub_828513B8(ctx, base, entry, element) & 0xFF) != 0;
						stateR6 = ctx.r6.u64;
						stateR7 = ctx.r7.u64;
						stateR8 = ctx.r8.u64;
						if (!passes) {
							const uint32_t nextIter =
							    (uint32_t)n_sub_82637B40(ctx, base, nextIterAddr, listAddr, LOAD64(iterAddr), ctx.r8.u64);
							stateR6 = ctx.r6.u64;
							stateR7 = ctx.r7.u64;
							stateR8 = ctx.r8.u64;
							carry = ctx.xer.ca;
							STORE64(iterAddr, LOAD64(nextIter));
							list = LOAD32(iterAddr);
							position = LOAD32(iterAddr + 4);
							continue;
						}
						if ((uint32_t)position >= LOAD32(list + 8)) ppc_trap(ctx, base, 22);
						position += 4;
						STORE32(iterAddr + 4, (uint32_t)position);
					}
				}

				// state the callee may pass on
				ctx.xer.ca = carry;
				result = n_sub_82193AD8(ctx, base, entry, villager->m_4);
			}
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(2, sub_821B1F00, 0x821B1F00) { ctx.r3.u64 = n_sub_821B1F00(ctx, base, ctx.r3.u64); }

uint64_t n_sub_821FE988(CpuState& ctx, uint8_t* base, uint64_t villagerAddr, uint64_t objectAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(5, 0x821FE988)) { ctx.r3.u64 = villagerAddr; ctx.r4.u64 = objectAddr; __imp__sub_821FE988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821FE988);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	uint64_t result{};
	stack = PushStackFrame(base, stack, 112);

	// virtual slot 1 of the object, asked twice: 8 the first time hands the object to n_sub_827A0220
	uint32_t vtableEntry = LOAD32(LOAD32((uint32_t)objectAddr) + 4);
	callTarget.u64 = (uint64_t)vtableEntry;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = objectAddr;
	ctx.r4.u64 = objectAddr;
	ctx.r10.u64 = vtableEntry;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t status = ctx.r3.u32;

	if ((int32_t)status == 8) {
		result = n_sub_827A0220(ctx, base, villagerAddr, objectAddr);
	} else {
		vtableEntry = LOAD32(LOAD32((uint32_t)objectAddr) + 4);
		callTarget.u64 = (uint64_t)vtableEntry;
		ctx.r3.u64 = objectAddr;
		ctx.r10.u64 = vtableEntry;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;

		if ((int32_t)result == 9
		    && LOAD8((uint32_t)objectAddr + 4) == 0
		    && LOAD8((uint32_t)villagerAddr + 172) == 0) {
			uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
			if (LOAD8(LOAD32(globalRoot + 12) + 256) == 0) {
				result = n_sub_827A0318(ctx, base, villagerAddr, 0);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(5, sub_821FE988, 0x821FE988) { ctx.r3.u64 = n_sub_821FE988(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECVillager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8E00_B_ = int32_t(0x820C8E00);
	if (!UseLiftedCode(52, 0x8279DE48)) { ctx.r3.u64 = classNameString; __imp__sub_8279DE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8279DE48);
	uint32_t stack = ctx.r1.u64;
	const uint64_t classNameText = str_TXT_820C8E00_B_;  // sign-extended 32-bit address
	const int32_t length = -1;

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameText, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(52, sub_8279DE48, 0x8279DE48) { ctx.r3.u64 = CECVillager_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8279E038(CpuState& ctx, uint8_t* base, uint64_t villagerAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(52, 0x8279E038)) { ctx.r3.u64 = villagerAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8279E038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8279E038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	n_sub_8279E088(ctx, base, villagerAddr);
	// bit 0: also free the object
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, villagerAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return villagerAddr;
}
PROMOTED_ENTRY(52, sub_8279E038, 0x8279E038) { ctx.r3.u64 = n_sub_8279E038(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8279E260(CpuState& ctx, uint8_t* base, uint64_t villagerAddr, uint64_t dbRecord) {
	constexpr int32_t str_TXT_820C4790_B_ = int32_t(0x820C4790);
	constexpr int32_t str_TXT_820C48F4_B_ = int32_t(0x820C48F4);
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t str_TXT_820D558C_B_ = int32_t(0x820D558C);
	constexpr int32_t str_TXT_820D55A4_B_ = int32_t(0x820D55A4);
	constexpr int32_t str_TXT_820D55AC_B_ = int32_t(0x820D55AC);
	if (!UseLiftedCode(52, 0x8279E260)) { ctx.r3.u64 = villagerAddr; ctx.r4.u64 = dbRecord; __imp__sub_8279E260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8279E260);

	constexpr uint64_t kHashSeed = 0xFFFFFFFF811C9DC5ull;  // FNV offset basis, sign-extended: the field-name hash seed
	// the original code builds this string's address from the 0x820D0000 base
	constexpr int32_t str_TXT_820D559C_B_ = str_TXT_820D0000_B_ + 21916;

	uint32_t stack = ctx.r1.u64;
	CECVillager* villager = GameObject<CECVillager>(base, villagerAddr);
	// The result is what the last of the calls returned (the argument when none is made). Callers read r4 after
	// the call: the record unless a call below replaces it.
	uint64_t result = villagerAddr;
	uint64_t r4Value = dbRecord;

	stack = PushStackFrame(base, stack, 144);
	if ((uint32_t)dbRecord != 0) {
		const uint32_t jobTypeAddr = (uint32_t)villagerAddr + 0x9C;
		const uint32_t valueAddr = stack + 80;

		ctx.r1.u64 = stack;
		const uint64_t jobTypeHash = String_HashFnv1(ctx, base, str_TXT_820C4790_B_, kHashSeed);
		GameDB_TryGetIntFieldByHash(ctx, base, dbRecord, jobTypeHash, jobTypeAddr);

		villager->m_A4 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, dbRecord, str_TXT_820D558C_B_);
		// state the callee may pass on
		ctx.r8.s64 = str_TXT_820D0000_B_;
		villager->m_A6 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, dbRecord, str_TXT_820D559C_B_);

		const uint64_t jobTagHash = String_HashFnv1(ctx, base, str_TXT_820D55A4_B_, kHashSeed);
		// the field's address as a 64-bit sum, as the original register held it
		n_sub_8239E0D8(ctx, base, dbRecord, jobTagHash, villagerAddr + 0xA0);

		STORE32(valueAddr, 0u);
		const uint64_t routineHash = String_HashFnv1(ctx, base, str_TXT_820D55AC_B_, kHashSeed);
		result = GameDB_ReadMappedU32Field(ctx, base, dbRecord, routineHash, valueAddr);
		r4Value = ctx.r4.u64;
		const uint32_t routine = LOAD32(valueAddr);
		if (routine != 0) {
			STORE32(valueAddr, 0u);
			const uint64_t timesHash = String_HashFnv1(ctx, base, str_TXT_820C48F4_B_, kHashSeed);
			result = GameDB_ReadMappedU32Field(ctx, base, routine, timesHash, valueAddr);
			const uint32_t TXT_820C48F4_L_ = LOAD32(valueAddr);
			r4Value = TXT_820C48F4_L_;
			if (TXT_820C48F4_L_ != 0) {
				villager->m_A9 = 1;
				result = n_sub_827A1AB8(ctx, base, villagerAddr, TXT_820C48F4_L_);
				r4Value = ctx.r4.u64;
			}
		}

		if (LOAD32(jobTypeAddr) == 41) {
			villager->m_A8 = 0;
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(52, sub_8279E260, 0x8279E260) { ctx.r3.u64 = n_sub_8279E260(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8279F158(CpuState& ctx, uint8_t* base, uint64_t villagerAddr) {
	constexpr int32_t str_TXT_820D56B8_B_ = int32_t(0x820D56B8);
	constexpr int32_t str_TXT_820D56C4_B_ = int32_t(0x820D56C4);
	constexpr int32_t str_TXT_820D56CC_B_ = int32_t(0x820D56CC);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x8279F158)) { ctx.r3.u64 = villagerAddr; __imp__sub_8279F158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8279F158);

	constexpr uint64_t kHashSeed = 0xFFFFFFFF811C9DC5ull;  // FNV offset basis, sign-extended
	constexpr uint32_t kFieldType = 6;

	CECVillager* villager = GameObject<CECVillager>(base, villagerAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);
	const uint32_t idRefAddr = stack + 80;
	const uint32_t idKeyAddr = stack + 88;  // the (0, id) pair handed to n_sub_82264448

	ctx.r1.u64 = stack;
	n_sub_821D9F40(ctx, base, idRefAddr, villagerAddr);

	// The address of the value of the field with this name (hashed) in the record the IdRef at stack + 80 refers
	// to; 0 when it has none.
	auto findField = [&](int32_t fieldName) -> uint64_t {
		const uint64_t nameHash = String_HashFnv1(ctx, base, fieldName, kHashSeed);
		// state the callee may pass on
		const uint64_t record = IdRef_Get(ctx, base, idRefAddr);
		return GameDB_FindFieldValue(ctx, base, record, nameHash, kFieldType);
	};
	// The entity n_sub_82264448 finds for an id, asked of the first object of the list reached from the
	// global at 0x83496920.
	auto findEntity = [&](uint32_t id) -> uint64_t {
		const uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		STORE32(idKeyAddr + 4, id);
		STORE32(idKeyAddr, 0u);
		const uint32_t list = LOAD32(LOAD32(globalRoot + 12) + 88);
		const uint32_t firstObject = LOAD32(LOAD32(list + 4));
		// state the callee may pass on
		return n_sub_82264448(ctx, base, firstObject, idKeyAddr);
	};
	// a found entity is used only when bit 0x40 of its byte +0x90 is set
	auto isUsable = [&](uint64_t entity) {
		return (uint32_t)entity != 0 && (LOAD8((uint32_t)entity + 0x90) & 0x40) != 0;
	};

	const uint32_t villageField = (uint32_t)findField(str_TXT_820D56B8_B_);
	const uint32_t villageId = villageField != 0 ? LOAD32(villageField) : 0;
	if (villageId != 0) {
		const uint64_t village = findEntity(villageId);
		if (isUsable(village)) {
			n_sub_827A0E00(ctx, base, villagerAddr, village);
		}
	}

	const uint32_t homeField = (uint32_t)findField(str_TXT_820D56C4_B_);
	const uint32_t homeId = homeField != 0 ? LOAD32(homeField) : 0;
	if (homeId != 0 && villager->m_A5 == 0) {
		const uint64_t home = findEntity(homeId);
		if (isUsable(home)) {
			n_sub_827A0738(ctx, base, villagerAddr, home);
		}
	}

	// The result is what the last of the calls below returned. r4 for callers (and for n_sub_8279F5C0) is what
	// the field lookup left in it, then the entity the workplace lookup found, then what a later call leaves.
	uint64_t result = findField(str_TXT_820D56CC_B_);
	uint64_t r4Value = ctx.r4.u64;
	const uint32_t workplaceId = (uint32_t)result != 0 ? LOAD32((uint32_t)result) : 0;
	if (workplaceId != 0) {
		result = findEntity(workplaceId);
		r4Value = result;
		if (isUsable(result)) {
			result = n_sub_827A1170(ctx, base, villagerAddr, result);
			r4Value = ctx.r4.u64;
		}
	}

	if (villager->m_AE != 0) {
		// state the callee may pass on
		result = n_sub_8279F5C0(ctx, base, villagerAddr);
		r4Value = ctx.r4.u64;
	}

	villager->m_AF = 1;
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(52, sub_8279F158, 0x8279F158) { ctx.r3.u64 = n_sub_8279F158(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8279F398(CpuState& ctx, uint8_t* base, uint64_t villagerAddr) {
	if (!UseLiftedCode(52, 0x8279F398)) { ctx.r3.u64 = villagerAddr; __imp__sub_8279F398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8279F398);
	uint32_t stack = ctx.r1.u64;
	CECVillager* villager = GameObject<CECVillager>(base, villagerAddr);
	stack = PushStackFrame(base, stack, 128);

	// The result is what the last of the calls returned (the argument when none is made).
	uint64_t result = villagerAddr;
	if (villager->m_AF == 0) {
		ctx.r1.u64 = stack;
		result = n_sub_8279F5C0(ctx, base, villagerAddr);

		// An entity handle counts only when it resolves to an entity with bit 0x40 of byte +0x90 set; a handle
		// whose target word is zero is released instead. The second handle is looked at only when the first counts.
		const uint64_t firstHandleAddr = villagerAddr + 0x14;
		const uint64_t secondHandleAddr = villagerAddr + 0x1C;
		auto usableFlag = [&](uint32_t handleTarget, uint64_t handleAddr) -> uint32_t {
			if (handleTarget == 0) return 0;
			const uint32_t target = LOAD32(handleTarget);
			// state the callee may pass on
			ctx.r10.u64 = target;
			if (target == 0) {
				result = EntityHandle_Release(ctx, base, handleAddr);
				return 0;
			}
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			return LOAD8((uint32_t)result + 0x90) & 0x40;
		};
		const uint32_t firstFlag = usableFlag(villager->m_18, firstHandleAddr);
		const uint32_t secondFlag = firstFlag != 0 ? usableFlag(villager->m_20, secondHandleAddr) : 0;

		if (secondFlag != 0) {
			// state the callee may pass on
			result = EntityHandle_Get_825575C8(ctx, base, firstHandleAddr);
			const uint32_t firstEntity = (uint32_t)result;
			// r6-r10 and xer.ca as this call left them: the last handle lookup receives them as the lookup below
			// updates them
			uint64_t stateR6 = ctx.r6.u64;
			uint64_t stateR7 = ctx.r7.u64;
			uint64_t stateR8 = ctx.r8.u64;
			uint64_t stateR9 = ctx.r9.u64;
			uint64_t stateR10;
			uint8_t carry = ctx.xer.ca;

			// Type 65: bit 1 of the word at +0x2C says the entity has an entry of that type. The byte table at +0x8C,
			// when present, gives its index among the (type, value) pairs at +0x48..+0x4C; otherwise they are searched.
			if (((LOAD32(firstEntity + 0x2C) >> 1) & 1) != 0) {
				uint32_t entry;
				const uint32_t indexTable = LOAD32(firstEntity + 0x8C);
				if (indexTable != 0) {
					const uint64_t pairOffset = (uint64_t)LOAD8(indexTable + 65) * 8;
					stateR10 = pairOffset;
					// the pair's address as a 64-bit sum, as the register held it
					stateR9 = pairOffset + LOAD32(firstEntity + 0x48);
					entry = LOAD32((uint32_t)stateR9 + 4);
				} else {
					const uint32_t begin = LOAD32(firstEntity + 0x48);
					const uint32_t end = LOAD32(firstEntity + 0x4C);
					// stack + 80 holds the search's (0, position) pair
					STORE32(stack + 80, 0u);
					const uint32_t byteCount = end - begin;
					STORE32(stack + 84, begin);
					stateR6 = end;
					carry = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
					int32_t count = (int32_t)byteCount >> 3;
					// the position is kept in 64 bits, as the register (r10) held it
					uint64_t it = begin;
					// lower_bound for type 65 (keys compare signed)
					if (count > 0) {
						// halving a positive count clears the carry
						carry = 0;
						do {
							const int32_t half = count >> 1;
							const uint32_t step = (uint32_t)half << 3;
							const uint64_t mid = it + step;
							const bool below = (int32_t)LOAD32((uint32_t)mid) < 65;
							stateR7 = below ? 1 : 0;
							stateR8 = step;
							stateR9 = (uint32_t)half;
							if (below) {
								it = mid + 8;
								count = count - half - 1;
							} else {
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 84, (uint32_t)it);
					}
					stateR10 = it;
					// a missing type reads the pair at `end`
					entry = ((uint32_t)it != end && (int32_t)LOAD32((uint32_t)it) <= 65) ? LOAD32((uint32_t)it + 4)
					                                                                       : LOAD32(end + 4);
				}

				// state the callee may pass on
				ctx.xer.ca = carry;
				const uint32_t secondEntity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, secondHandleAddr);
				const uint32_t TXT_820C4790_L_ = villager->m_9C;
				result = n_sub_825DD550(ctx, base, entry, TXT_820C4790_L_, secondEntity);
			}
		}
	}

	villager->m_AF = 0;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_8279F398, 0x8279F398) { ctx.r3.u64 = n_sub_8279F398(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827A0220(CpuState& ctx, uint8_t* base, uint64_t villagerAddr, uint64_t objectAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x827A0220)) { ctx.r3.u64 = villagerAddr; ctx.r4.u64 = objectAddr; __imp__sub_827A0220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827A0220);
	uint32_t stack = ctx.r1.u64;
	// r7 handed to n_sub_827A0318: the caller's value unless a step below replaces it
	uint64_t r7Value = ctx.r7.u64;
	stack = PushStackFrame(base, stack, 128);

	// The first object of the list reached from the global at 0x83496920 has an entity handle at +104, whose word
	// at +108 points to the target's address. The handle counts only when the target has bit 0x40 of byte +0x90
	// set; a handle whose target address is zero is released instead.
	const uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
	const uint64_t listBegin = LOAD32(LOAD32(LOAD32(globalRoot + 12) + 88) + 4);
	const uint32_t firstObject = LOAD32((uint32_t)listBegin);
	const uint64_t handleAddr = (uint64_t)firstObject + 104;
	const uint32_t handleTarget = LOAD32(firstObject + 108);

	bool handleUsable = false;
	if (handleTarget != 0) {
		const uint32_t target = LOAD32(handleTarget);
		if (target == 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			EntityHandle_Release(ctx, base, handleAddr);
			r7Value = ctx.r7.u64;
		} else {
			handleUsable = (LOAD8(target + 0x90) & 0x40) != 0;
		}
	}

	// 1 when the object's reference at +4 names the same (+20, +24) id pair as that entity
	uint32_t sameEntity = 0;
	if (handleUsable && LOAD32((uint32_t)objectAddr + 4) != 0) {
		// the original reads the list's first object again
		const uint32_t listBeginAgain = LOAD32(LOAD32(LOAD32(globalRoot + 12) + 88) + 4);
		const uint32_t firstObjectAgain = LOAD32(listBeginAgain);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = objectAddr;
		const uint32_t entity = (uint32_t)EntityHandle_Get(ctx, base, firstObjectAgain);
		const uint32_t referenced = LOAD32((uint32_t)objectAddr + 4);
		r7Value = LOAD32(entity + 20);
		if (LOAD32(referenced + 20) == (uint32_t)r7Value && LOAD32(referenced + 24) == LOAD32(entity + 24)) {
			sameEntity = 1;
		}
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	const uint64_t result = n_sub_827A0318(ctx, base, villagerAddr, sameEntity);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_827A0220, 0x827A0220) { ctx.r3.u64 = n_sub_827A0220(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_827A0E00(CpuState& ctx, uint8_t* base, uint64_t villagerAddr, uint64_t target) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(52, 0x827A0E00)) { ctx.r3.u64 = villagerAddr; ctx.r4.u64 = target; __imp__sub_827A0E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827A0E00);
	uint32_t stack = ctx.r1.u64;
	const PPCXERRegister entryXer = ctx.xer;  // its summary-overflow bit is the one the searches put in cr0
	CECVillager* villager = GameObject<CECVillager>(base, villagerAddr);
	stack = PushStackFrame(base, stack, 144);

	// Value of the entry with key 65 in an entity's sorted array of 8-byte (key, value) entries [+72, +76).
	// The byte table at +140, when there is one, holds each key's entry index; otherwise the array is
	// binary-searched with its cursor kept in the stack temporary at +80. Like the game's code, the lookup
	// leaves r6-r9, cr0 and the carry for the call that follows (state the callee may pass on).
	auto valueOfKey65 = [&](uint32_t entity) -> uint32_t {
		const uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			const uint64_t entryAddr = (uint64_t)LOAD8(indexTable + 65) * 8 + LOAD32(entity + 72);
			ctx.r9.u64 = entryAddr;
			return LOAD32((uint32_t)entryAddr + 4);
		}
		uint32_t cursor = LOAD32(entity + 72);
		const uint32_t end = LOAD32(entity + 76);
		STORE32(stack + 80, 0);
		STORE32(stack + 84, cursor);
		const uint32_t byteSize = end - cursor;
		int32_t count = (int32_t)byteSize >> 3;
		ctx.r6.u64 = end;
		ctx.xer.ca = (int32_t)byteSize < 0 && (byteSize & 7) != 0;
		ctx.cr0.compare<int32_t>(count, 0, entryXer);
		if (count > 0) {
			do {
				const int32_t half = count >> 1;
				const uint32_t mid = cursor + ((uint32_t)half << 3);
				const bool keyBelow = (int32_t)LOAD32(mid) < 65;
				ctx.r7.u64 = keyBelow;
				ctx.r8.u64 = (uint32_t)half << 3;
				ctx.r9.s64 = half;
				ctx.xer.ca = 0;
				if (keyBelow) {
					cursor = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, cursor);
		}
		if (cursor == end || (int32_t)LOAD32(cursor) > 65) {
			return LOAD32(end + 4);
		}
		STORE64(stack + 80, LOAD64(stack + 80));  // the game copies the temporary onto itself
		return LOAD32(cursor + 4);
	};

	// The EntityHandle at +20; m_18 is its record word (+4). Nothing changes when it already targets `target`.
	const uint64_t targetHandle = villagerAddr + 20;
	ctx.r1.u64 = stack;
	uint64_t result = EntityHandle_IsNotTarget(ctx, base, targetHandle, target);
	if ((result & 0xFF) == 0) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	// Old target: when the handle resolves to an entity with bit 0x40 of byte +144 set, its key-65 value
	// goes to n_sub_825DD0E0. A handle whose record no longer holds an object is released.
	bool oldTargetFlagged = false;
	const uint32_t oldRecord = villager->m_18;
	if (oldRecord != 0) {
		const uint32_t oldObject = LOAD32(oldRecord);
		ctx.r10.u64 = oldObject;  // state the callee may pass on
		if (oldObject == 0) {
			EntityHandle_Release(ctx, base, targetHandle);
		} else {
			const uint32_t oldEntity = EntityHandle_Get_825575C8(ctx, base, targetHandle);
			oldTargetFlagged = (LOAD8(oldEntity + 144) & 0x40) != 0;
		}
	}
	if (oldTargetFlagged) {
		ctx.r10.u64 = 0x40;  // state the callee may pass on: the bit just tested
		const uint32_t oldEntity = EntityHandle_Get_825575C8(ctx, base, targetHandle);
		uint32_t oldValue = 0;
		if ((LOAD32(oldEntity + 44) >> 1) & 1) {
			oldValue = valueOfKey65(oldEntity);
		}
		n_sub_825DD0E0(ctx, base, oldValue, villager->m_4);
	}

	// Retarget through a temporary EntityHandle on the game stack.
	const uint64_t handleVtable = g_820F1664;
	const uint64_t tempHandle = (uint64_t)stack + 80;
	STORE32(stack + 84, 0);
	STORE32(stack + 80, (uint32_t)handleVtable);
	ctx.r10.u64 = handleVtable;  // state the callee may pass on
	EntityHandle_SetTarget(ctx, base, tempHandle, target);
	EntityHandle_Assign(ctx, base, targetHandle, tempHandle);
	STORE32(stack + 80, (uint32_t)handleVtable);
	// state the callee may pass on
	result = EntityHandle_Release(ctx, base, tempHandle);

	// New target: the same check. Without a flagged entity m_2C / m_30 are cleared.
	bool newTargetFlagged = false;
	const uint32_t newRecord = villager->m_18;
	if (newRecord != 0) {
		const uint32_t newObject = LOAD32(newRecord);
		ctx.r10.u64 = newObject;  // state the callee may pass on
		if (newObject == 0) {
			result = EntityHandle_Release(ctx, base, targetHandle);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, targetHandle);
			newTargetFlagged = (LOAD8((uint32_t)result + 144) & 0x40) != 0;
		}
	}
	if (!newTargetFlagged) {
		villager->m_2C = 0;
		villager->m_30 = 0;
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	// m_2C / m_30 take words +20 / +24 of the new target entity.
	ctx.r10.u64 = 0x40;  // state the callee may pass on: the bit just tested
	const uint32_t newEntity = EntityHandle_Get_825575C8(ctx, base, targetHandle);
	const uint32_t entityWord20 = LOAD32(newEntity + 20);
	villager->m_2C = entityWord20;
	const uint32_t entityWord24 = LOAD32(newEntity + 24);
	villager->m_30 = entityWord24;
	// state the callee may pass on
	const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, targetHandle);
	const uint32_t entityFlags = LOAD32(entity + 44);
	const uint32_t lookupEnabled = (entityFlags >> 1) & 1;
	// state the callee may pass on (a search in the lookup replaces r7 / r8)
	ctx.r7.u64 = lookupEnabled;
	ctx.r8.u64 = entityFlags;
	uint32_t newValue = 0;
	if (lookupEnabled != 0) {
		newValue = valueOfKey65(entity);
	}
	result = n_sub_825DCE70(ctx, base, newValue, villager->m_4);
	if (villager->m_A9 == 0) {
		const uint64_t scheduleArg = n_sub_825DE450(ctx, base, newValue, villager->m_9C);
		result = n_sub_827A1AB8(ctx, base, villagerAddr, scheduleArg);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_827A0E00, 0x827A0E00) { ctx.r3.u64 = n_sub_827A0E00(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_827A1AB8  [624 bytes]
uint64_t n_sub_827A1AB8(CpuState& ctx, uint8_t* base, uint64_t villagerAddr, uint64_t jobSchedule) {
	constexpr int32_t str_TXT_820D56D8_B_ = int32_t(0x820D56D8);
	constexpr int32_t str_TXT_820D56E4_B_ = int32_t(0x820D56E4);
	constexpr int32_t str_TXT_820D56F0_B_ = int32_t(0x820D56F0);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_8349E164 = int32_t(0x8349E164);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(53, 0x827A1AB8)) { ctx.r3.u64 = villagerAddr; ctx.r4.u64 = jobSchedule; __imp__sub_827A1AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827A1AB8);
	constexpr uint64_t kHashSeed = 0xFFFFFFFF811C9DC5ull;  // FNV offset basis, sign-extended as the game loads it
	uint32_t stack = ctx.r1.u64;
	uint64_t result = villagerAddr;
	stack = PushStackFrame(base, stack, 256);

	// Vector of 12-byte (job phase, start time, finish time) entries at +0x8C: begin +0x90, end +0x94,
	// capacity end +0x98. It is emptied first.
	const uint64_t schedule = villagerAddr + 0x8C;
	const uint32_t scheduleBegin = LOAD32(schedule + 4);
	if (scheduleBegin != LOAD32(schedule + 8)) {
		STORE32(schedule + 8, scheduleBegin);
	}

	if ((uint32_t)jobSchedule != 0) {
		ctx.r1.u64 = stack;
		n_sub_829FBC40(ctx, base, stack + 96, jobSchedule, scheduleBegin);
		double f13 = ctx.f13.f64;  // f13 as the calls below are handed it
		// the words n_sub_829FBC40 left at +96: entry array, end index, first index
		const uint32_t entries = LOAD32(stack + 96);
		const uint32_t endIndex = LOAD32(stack + 100);
		uint32_t index = LOAD32(stack + 104);
		if (index != endIndex) {
			ctx.fpscr.disableFlushMode();
			const double defaultTime = double(LOAD_F32(0x820994B4u));
			const uint32_t matchKeyAddr = uint32_t(g_834A0000) - 7848;
			do {
				const uint32_t entry = index * 12 + entries;
				uint32_t keyAddr = LOAD32(entry + 8);
				// a type-4 entry whose key equals the one at matchKeyAddr uses the key at g_8349E164 instead
				if (LOAD32(entry) == 4 && LOAD32(keyAddr) == LOAD32(matchKeyAddr)) {
					keyAddr = uint32_t(g_8349E164);
				}
				const uint32_t recordMap = LOAD32(uint32_t(g_83490000) + 27600);
				const uint64_t record = HashMapU32_FindValue(ctx, base, recordMap, LOAD32(keyAddr));
				ctx.fpscr.disableFlushMode();
				STORE_F32(stack + 80, float(defaultTime));
				STORE_F32(stack + 84, float(defaultTime));
				if ((GameDB_ReadFloatField(ctx, base, record, str_TXT_820D56D8_B_, stack + 80) & 0xFF) != 0 &&
				    (GameDB_ReadFloatField(ctx, base, record, str_TXT_820D56E4_B_, stack + 84) & 0xFF) != 0) {
					const uint64_t phaseHash = String_HashFnv1(ctx, base, str_TXT_820D56F0_B_, kHashSeed);
					const uint32_t phaseField = GameDB_FindFieldValue(ctx, base, record, phaseHash, 2);
					if (phaseField != 0) {
						const uint32_t TXT_820D56F0_L_ = LOAD32(phaseField);
						const uint32_t vecBegin = LOAD32(schedule + 4);
						ctx.fpscr.disableFlushMode();
						const double TXT_820D56D8_L_ = double(LOAD_F32(stack + 80));
						f13 = double(LOAD_F32(stack + 84));  // the finish time
						// the new entry, built in the temporary at +96
						STORE32(stack + 96, TXT_820D56F0_L_);
						STORE_F32(stack + 100, float(TXT_820D56D8_L_));
						STORE_F32(stack + 104, float(f13));
						uint32_t capacity = 0;
						if (vecBegin != 0) {
							capacity = uint32_t((int32_t)(LOAD32(schedule + 12) - vecBegin) / 12);
						}
						const uint32_t vecEnd = LOAD32(schedule + 8);
						const uint32_t size = uint32_t((int32_t)(vecEnd - vecBegin) / 12);
						if (size < capacity) {
							if (vecEnd != 0) {
								const uint32_t startBits = LOAD32(stack + 100);
								const uint32_t finishBits = LOAD32(stack + 104);
								STORE32(vecEnd, TXT_820D56F0_L_);
								STORE32(vecEnd + 4, startBits);
								STORE32(vecEnd + 8, finishBits);
							}
							STORE32(schedule + 8, vecEnd + 12);
						} else {
							// insert at the end: the position goes over as the 64-bit value built at +88
							STORE32(stack + 92, vecEnd);
							STORE32(stack + 88, 0);
							// state the callee may pass on
							n_sub_823955A8(ctx, base, schedule, LOAD64(stack + 88), stack + 96);
							f13 = ctx.f13.f64;
						}
					}
				}
				index = index + 1;
			} while (index != endIndex);
		}
		ctx.f13.f64 = f13;  // state the callee may pass on
		result = HandleTarget_Free(ctx, base, entries);
	}
	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(53, sub_827A1AB8, 0x827A1AB8) { ctx.r3.u64 = n_sub_827A1AB8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_827A1D28(CpuState& ctx, uint8_t* base, uint64_t villagerAddr, uint64_t target) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(53, 0x827A1D28)) { ctx.r3.u64 = villagerAddr; ctx.r4.u64 = target; __imp__sub_827A1D28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827A1D28);
	uint32_t stack = ctx.r1.u64;
	CECVillager* villager = GameObject<CECVillager>(base, villagerAddr);
	stack = PushStackFrame(base, stack, 128);

	// Point a temporary EntityHandle on the game stack at the target, copy it into the villager's handle
	// at +60, then release the temporary.
	const uint64_t handleVtable = g_820F1664;
	const uint64_t tempHandle = (uint64_t)stack + 80;
	STORE32(stack + 84, 0);
	STORE32(stack + 80, (uint32_t)handleVtable);
	ctx.r1.u64 = stack;
	ctx.r10.u64 = handleVtable;  // state the callee may pass on
	EntityHandle_SetTarget(ctx, base, tempHandle, target);
	const uint64_t villagerHandle = villagerAddr + 60;
	EntityHandle_Assign(ctx, base, villagerHandle, tempHandle);
	STORE32(stack + 80, (uint32_t)handleVtable);
	// state the callee may pass on
	uint64_t result = EntityHandle_Release(ctx, base, tempHandle);

	// m_64 / m_68 take words +20 / +24 of the entity the handle now refers to, or zero. A handle whose
	// record (its word at +4, m_40) no longer holds an object is released.
	const uint32_t handleRecord = villager->m_40;
	if (handleRecord != 0) {
		const uint32_t recordObject = LOAD32(handleRecord);
		ctx.r10.u64 = recordObject;  // state the callee may pass on
		if (recordObject != 0) {
			const uint64_t entity = EntityHandle_Get_825575C8(ctx, base, villagerHandle);
			villager->m_64 = LOAD32((uint32_t)entity + 20);
			villager->m_68 = LOAD32((uint32_t)entity + 24);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return entity;
		}
		result = EntityHandle_Release(ctx, base, villagerHandle);
	}
	villager->m_64 = 0;
	villager->m_68 = 0;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(53, sub_827A1D28, 0x827A1D28) { ctx.r3.u64 = n_sub_827A1D28(ctx, base, ctx.r3.u64, ctx.r4.u64); }
