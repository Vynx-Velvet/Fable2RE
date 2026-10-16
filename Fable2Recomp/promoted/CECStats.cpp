// CECStats (vtable 0x820B6FF8): methods of the class as readable C++.
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

uint32_t n_sub_82174F10(CpuState& ctx, uint8_t* base, uint64_t statsAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(0, 0x82174F10)) { ctx.r3.u64 = statsAddr; __imp__sub_82174F10(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82174F10);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 144);

	// Walk the tree at stats+0x9C and expire the entries whose time (+0x18) the global clock
	// has passed; an expired entry has its bonus cleared and is erased from the tree.
	const uint32_t treeAddr = uint32_t(statsAddr) + 0x9C;
	const uint32_t clockAddr = uint32_t(g_83320000) - 27380;
	const uint32_t iterAddr = stack + 80;   // iterator {owner tree, node}

	// Iterator checks of the original code: a failed check logs a trap and execution goes on.
	auto trapIf = [&](bool failed) {
		if (failed) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
	};

	// begin(): the head node sits at tree+4, the first node is *head.
	STORE32(iterAddr, treeAddr);
	STORE32(iterAddr + 4, LOAD32(uint32_t(stats->m_A0)));
	STORE64(iterAddr, LOAD64(iterAddr));

	uint64_t result = statsAddr;
	for (;;) {
		const uint32_t owner = LOAD32(iterAddr);
		const uint32_t head = LOAD32(treeAddr + 4);
		trapIf(owner == 0 || owner != treeAddr);
		const uint32_t node = LOAD32(iterAddr + 4);
		if (node == head) break;   // end()

		trapIf(owner == 0);
		const uint32_t ownerHead = LOAD32(owner + 4);
		trapIf(node == ownerHead);
		if (LOAD8(node + 0x10) != 0) {
			trapIf(node == ownerHead);
			const uint32_t entryTime = LOAD32(node + 0x18);
			if (int32_t(LOAD32(clockAddr)) > int32_t(entryTime)) {
				STORE8(node + 0x10, 0);
			}
			if (LOAD8(node + 0x10) == 0) {
				const uint32_t currentHead = LOAD32(owner + 4);
				trapIf(node == currentHead);
				ctx.fpscr.disableFlushMode();
				const double value = double(LOAD_F32(node + 0x14));
				trapIf(node == currentHead);
				const uint32_t bonusId = LOAD32(node + 0x0C);
				ctx.r1.u64 = stack;
				ctx.r8.u64 = entryTime;   // state the callee may pass on
				CECStats_ClearBonus(ctx, base, uint32_t(statsAddr), bonusId, value);

				// erase(): the helper returns the address of the iterator to continue from.
				const uint64_t nextIterAddr = n_sub_824AE5C8(ctx, base, uint64_t(stack) + 88, statsAddr + 0x9C, LOAD64(iterAddr), ctx.r8.u64);
				result = nextIterAddr;
				STORE64(iterAddr, LOAD64(uint32_t(nextIterAddr)));
				continue;
			}
		}
		result = uint64_t(stack) + 80;
		ctx.r1.u64 = stack;
		RbTreeIterator_Increment(ctx, base, iterAddr);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return uint32_t(result);
}
PROMOTED_ENTRY(0, sub_82174F10, 0x82174F10) { ctx.r3.u64 = n_sub_82174F10(ctx, base, ctx.r3.u64); }

uint32_t CECStats_RemoveExpiredPartyAnimalEntries(CpuState& ctx, uint8_t* base, uint32_t statsAddr) {
	constexpr int32_t str_TXT_82002478_B_ = int32_t(0x82002478);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(1, 0x8219C8A8)) { ctx.r3.u64 = statsAddr; __imp__sub_8219C8A8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8219C8A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	// Time limit: the balancing value scaled by the double at 0x83319510, rounded up and
	// truncated to an integer.
	const uint32_t keyString = stack + 80;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, keyString, (uint64_t)(int64_t)str_TXT_82002478_B_, -1);
	ctx.fpscr.disableFlushMode();
	const double scaleFactor = LOAD_F64(0x83319510u);
	Achievements_GetBalancingValue(ctx, base, keyString);
	const double balancingValue = ctx.f1.f64;
	ctx.fpscr.disableFlushMode();
	const double scaledValue = double(float(balancingValue * scaleFactor));
	const double roundedValue = ceil(ctx, base, scaledValue);
	ctx.fpscr.disableFlushMode();
	double roundedAsFloat = double(float(roundedValue));
	PPCRegister asInt{};
	asInt.s64 = std::isnan(roundedAsFloat) ? int64_t(0x80000000U) : roundedAsFloat > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&roundedAsFloat));
	STORE_F64(stack + 88, asInt.f64);
	const uint32_t timeLimit = LOAD32(stack + 92);
	// state the callee may pass on
	ctx.f1.f64 = roundedValue;
	ctx.f12 = asInt;
	ctx.f13.f64 = roundedAsFloat;
	uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, keyString);

	// Values the original code keeps in r7-r9 and hands to EntityHandle_Release.
	uint32_t r7Value = ctx.r7.u32;
	const uint32_t headNode = stats->m_B8;
	uint32_t r8Value = headNode;
	uint32_t r9Value = uint32_t(g_83320000);

	// Sweep the entry list at stats+0xB4 (head node at +4, entry count at +8). An entry stays
	// while its time (+8) is within the limit and its handle (+12, target at +16) refers to an
	// entity with bit 0x40 set at +144; every other entry is unlinked and freed.
	const uint32_t list = statsAddr + 0xB4;
	const uint32_t iterAddr = stack + 80;   // iterator {owner list, node}
	STORE32(iterAddr, list);
	const uint32_t cutoff = LOAD32(uint32_t(g_83320000) - 27380) - timeLimit;
	const uint32_t handleMarker = uint32_t(g_820F1664);
	uint32_t owner = list;
	uint32_t node = LOAD32(headNode);
	STORE32(iterAddr + 4, node);

	for (;;) {
		const uint32_t head = LOAD32(list + 4);
		if (owner == 0 || owner != list) ppc_trap(ctx, base, 22);
		if (node == head) break;   // end()
		if (owner == 0) ppc_trap(ctx, base, 22);
		const uint32_t ownerHead = LOAD32(owner + 4);
		if (node == ownerHead) ppc_trap(ctx, base, 22);

		bool keep = false;
		if ((int32_t)LOAD32(node + 8) >= (int32_t)cutoff) {
			if (node == ownerHead) ppc_trap(ctx, base, 22);
			const uint32_t handleTarget = LOAD32(node + 16);
			result = node + 12;
			if (handleTarget != 0) {
				const uint32_t entity = LOAD32(handleTarget);
				if (entity == 0) {
					// state the callee may pass on
					ctx.r7.u64 = r7Value;
					ctx.r8.u64 = r8Value;
					ctx.r9.u64 = r9Value;
					ctx.r10.u64 = entity;
					result = EntityHandle_Release(ctx, base, node + 12);
					r7Value = ctx.r7.u32;
					r8Value = ctx.r8.u32;
					r9Value = ctx.r9.u32;
				} else {
					keep = (LOAD8(entity + 144) & 0x40) != 0;
				}
			}
		}

		if (keep) {
			if (node == LOAD32(owner + 4)) ppc_trap(ctx, base, 22);
			node = LOAD32(node);
			STORE32(iterAddr + 4, node);
			continue;
		}

		// erase(): step the iterator to the next node, then unlink and free this one.
		const uint32_t ownerHeadNow = LOAD32(owner + 4);
		STORE64(iterAddr, LOAD64(iterAddr));
		if (node == ownerHeadNow) ppc_trap(ctx, base, 22);
		const uint32_t next = LOAD32(node);
		const uint32_t currentHead = LOAD32(list + 4);
		STORE32(iterAddr + 4, next);
		if (node != currentHead) {
			const uint32_t prev = LOAD32(node + 4);
			STORE32(prev, next);
			// the links are read again after the first store, as in the original code
			const uint32_t nextLink = LOAD32(node);
			const uint32_t prevLink = LOAD32(node + 4);
			STORE32(nextLink + 4, prevLink);
			STORE32(node + 12, handleMarker);
			// state the callee may pass on
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = prevLink;
			ctx.r9.u64 = nextLink;
			ctx.r10.u64 = prev;
			EntityHandle_Release(ctx, base, node + 12);
			STORE32(node + 16, 0);
			result = HandleTarget_Free(ctx, base, node);
			r8Value = ctx.r8.u32;
			r9Value = ctx.r9.u32;
			r7Value = LOAD32(list + 8) - 1;
			STORE32(list + 8, r7Value);
		}
		STORE64(iterAddr, LOAD64(iterAddr));
		node = LOAD32(iterAddr + 4);
		owner = LOAD32(iterAddr);
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_8219C8A8, 0x8219C8A8) { ctx.r3.u64 = CECStats_RemoveExpiredPartyAnimalEntries(ctx, base, ctx.r3.u32); }

uint64_t n_sub_822385C0(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint32_t bonusId) {
	if (!UseLiftedCode(7, 0x822385C0)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = bonusId; __imp__sub_822385C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822385C0);
	uint32_t stack = ctx.r1.u32;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	stack = PushStackFrame(base, stack, 112);
	const uint32_t keySlot = stack + 140;
	const uint32_t findResult = stack + 80;                  // {owning map, found node} filled in by the lookups
	const uint64_t bonusTree = statsAddr + 132;
	const uint64_t overrideTree = statsAddr + 156;
	uint64_t searchedTree = bonusTree;

	STORE32(keySlot, bonusId);

	ctx.r1.u64 = stack;
	RbTreeIntMap_Find_Flag21(ctx, base, findResult, bonusTree, keySlot);

	// A returned iterator that does not belong to the searched map logs a trap.
	uint32_t ownerMap = LOAD32(findResult);
	const uint32_t bonusTreeEnd = stats->m_88;
	if (ownerMap == 0 || ownerMap != uint32_t(bonusTree)) {
		ppc_trap(ctx, base, 22);
	}

	uint32_t isActive;
	if (LOAD32(findResult + 4) != bonusTreeEnd) {
		isActive = 1;
	} else {
		searchedTree = overrideTree;
		RbTreeIntMap_Find(ctx, base, findResult, overrideTree, keySlot);

		ownerMap = LOAD32(findResult);
		const uint32_t overrideTreeEnd = stats->m_A0;
		if (ownerMap == 0 || ownerMap != uint32_t(overrideTree)) {
			ppc_trap(ctx, base, 22);
		}
		const uint32_t foundNode = LOAD32(findResult + 4);
		if (foundNode != overrideTreeEnd) {
			if (ownerMap == 0) {
				ppc_trap(ctx, base, 22);
			}
			if (foundNode == LOAD32(ownerMap + 4)) {
				ppc_trap(ctx, base, 22);
			}
			isActive = LOAD8(foundNode + 16) != 0;
		} else {
			isActive = 0;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = searchedTree;                              // callers read r4 after the call
	return isActive;
}
PROMOTED_ENTRY(7, sub_822385C0, 0x822385C0) { ctx.r3.u64 = n_sub_822385C0(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// Lua_Stats_GetMorality: the morality value is returned in f1.
uint64_t n_sub_8223D308(CpuState& ctx, uint8_t* base, uint64_t statsAddr) {
	constexpr int32_t str_TXT_820B5ABC_B_ = int32_t(0x820B5ABC);
	constexpr int32_t str_TXT_820B5AD4_B_ = int32_t(0x820B5AD4);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(7, 0x8223D308)) { ctx.r3.u64 = statsAddr; __imp__sub_8223D308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8223D308);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	// Register state of the original code: handed to n_sub_8223D5E0 and left for callers.
	uint64_t r6Value = ctx.r6.u64;
	uint32_t r7Value = ctx.r7.u32;
	uint32_t r9Value = 0;
	uint32_t r10Value = 0;
	PPCCRRegister cr[8] = {ctx.cr0, ctx.cr1, ctx.cr2, ctx.cr3, ctx.cr4, ctx.cr5, {}, ctx.cr7};
	PPCXERRegister xer = ctx.xer;
	// The condition register as one word (mfcr), cr0 in the top four bits.
	auto conditionWord = [&cr]() {
		uint32_t word = 0;
		for (const PPCCRRegister& field : cr) {
			word = (word << 4) | (field.lt ? 8u : 0u) | (field.gt ? 4u : 0u) | (field.eq ? 2u : 0u) | (field.so ? 1u : 0u);
		}
		return word;
	};
	stack = PushStackFrame(base, stack, 128);

	double morality = double(stats->m_10);
	ctx.r1.u64 = stack;
	const uint32_t bonusActive = n_sub_822385C0(ctx, base, statsAddr, 11);  // Lua_Stats_IsBonusActive
	uint32_t r8Value = ctx.r8.u32;
	if (uint32_t(bonusActive & 0xFF) != 0) {
		CECStats_GetStatValue(ctx, base, uint32_t(statsAddr), 11);
		r8Value = ctx.r8.u32;
		ctx.fpscr.disableFlushMode();
		morality = double(float(ctx.f1.f64 + morality));
	}

	// When bit 20 of the flags word at +36 of the object at stats+4 is set, take the value stored
	// under key 20 in its table of 8-byte {key, value} entries: from the cached entry when there
	// is one, otherwise through a lower-bound binary search.
	const uint32_t container = stats->m_4;
	uint32_t augment = 0;
	bool hasAugment = false;
	if (((LOAD32(container + 36) >> 20) & 1) != 0) {
		hasAugment = true;
		const uint32_t cachedEntry = LOAD32(container + 140);
		if (cachedEntry != 0) {
			const uint32_t entryOffset = uint32_t(LOAD8(cachedEntry + 20)) << 3;
			const uint32_t entry = entryOffset + LOAD32(container + 72);
			augment = LOAD32(entry + 4);
			r9Value = entry;
			r10Value = entryOffset;
		} else {
			const uint32_t first = LOAD32(container + 72);
			const uint32_t end = LOAD32(container + 76);
			r6Value = end;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, first);
			const uint32_t byteCount = end - first;
			xer.ca = ((int32_t)byteCount < 0) & ((byteCount & 0x7) != 0);
			int32_t count = (int32_t)byteCount >> 3;
			cr[0].compare<int32_t>(count, 0, xer);
			uint32_t entry = first;
			r9Value = 1;   // the flag bit tested above
			if (count > 0) {
				xer.ca = 0;   // count stays positive inside the loop
				do {
					const int32_t half = count >> 1;
					const uint32_t halfBytes = uint32_t(half) << 3;
					entry += halfBytes;
					const bool keyBelow = (int32_t)LOAD32(entry) < 20;
					r7Value = keyBelow ? 1 : 0;
					r8Value = halfBytes;
					r9Value = uint32_t(half);
					if (keyBelow) {
						entry += 8;
						count = count - half - 1;
					} else {
						entry -= halfBytes;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, entry);
			}
			r10Value = entry;
			if (entry != end && !((int32_t)LOAD32(entry) > 20)) {
				STORE64(stack + 80, LOAD64(stack + 80));
				augment = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				augment = LOAD32(end + 4);
			}
		}
	}

	if (hasAugment) {
		// state the callee may pass on
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = r10Value;
		ctx.cr0 = cr[0];
		ctx.xer.ca = xer.ca;
		const uint32_t hasEvilAddition = n_sub_8223D5E0(ctx, base, augment, 7);
		cr[0] = ctx.cr0;
		xer.ca = ctx.xer.ca;
		if (uint32_t(hasEvilAddition & 0xFF) != 0) {
			CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, (uint64_t)(int64_t)str_TXT_820B5ABC_B_, -1);
			BalancingAugmentations_GetFloat(ctx, base, stack + 80);
			ctx.fpscr.disableFlushMode();
			morality = double(float(ctx.f1.f64 + morality));
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 80);
			cr[0] = ctx.cr0;
			cr[1] = ctx.cr1;
			cr[5] = ctx.cr5;
			cr[7] = ctx.cr7;
			xer.ca = ctx.xer.ca;
		}
		const uint32_t hasHolyAddition = n_sub_8223D5E0(ctx, base, augment, 6);
		cr[0] = ctx.cr0;
		xer.ca = ctx.xer.ca;
		if (uint32_t(hasHolyAddition & 0xFF) != 0) {
			CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, (uint64_t)(int64_t)str_TXT_820B5AD4_B_, -1);
			BalancingAugmentations_GetFloat(ctx, base, stack + 80);
			ctx.fpscr.disableFlushMode();
			morality = double(float(ctx.f1.f64 + morality));
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 80);
			cr[0] = ctx.cr0;
			cr[1] = ctx.cr1;
			cr[5] = ctx.cr5;
			cr[7] = ctx.cr7;
			xer.ca = ctx.xer.ca;
		}
	}

	// Two branch-free selects against m_14 and m_18: each difference is compared with the float
	// at 0x820994B4, and the cr6 lt/unordered bits pick a float of the table at 0x82100170 whose
	// sign chooses between the two candidates.
	ctx.fpscr.disableFlushMode();
	const double lowerBound = double(stats->m_14);
	const double belowLower = double(float(morality - lowerBound));
	const double upperBound = double(stats->m_18);
	const uint64_t selectTable = uint64_t(int64_t(g_82100170));
	const double compareLimit = double(LOAD_F32(0x820994B4u));
	cr[6].compare(belowLower, compareLimit);
	const uint32_t conditionAfterLower = conditionWord();
	const uint32_t lowerLtIndex = (conditionAfterLower >> 5) & 4;   // cr6.lt
	const uint32_t lowerUnIndex = (conditionAfterLower >> 2) & 4;   // cr6.un
	const uint64_t lowerIndex = uint64_t(lowerLtIndex) | uint64_t(lowerUnIndex);
	const double lowerSelector = double(LOAD_F32(uint32_t(selectTable) + uint32_t(lowerIndex)));
	const double afterLower = lowerSelector >= 0.0 ? morality : lowerBound;
	const double aboveUpper = double(float(afterLower - upperBound));
	cr[6].compare(aboveUpper, compareLimit);
	const uint32_t conditionAfterUpper = conditionWord();
	const uint32_t upperLtIndex = (conditionAfterUpper >> 5) & 4;
	const uint64_t upperIndex = uint64_t(upperLtIndex) | uint64_t((conditionAfterUpper >> 2) & 4);
	const double upperSelector = double(LOAD_F32(uint32_t(selectTable) + uint32_t(upperIndex)));
	const double result = upperSelector >= 0.0 ? upperBound : afterLower;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = conditionAfterUpper;
	ctx.r5.u64 = lowerIndex;
	ctx.r6.u64 = lowerUnIndex;
	ctx.r7.u64 = lowerLtIndex;
	ctx.r8.u64 = conditionAfterLower;
	ctx.r9.u64 = selectTable;
	ctx.r10.u64 = upperIndex;
	ctx.f1.f64 = result;
	ctx.f7.f64 = upperSelector;
	ctx.f8.f64 = aboveUpper;
	ctx.f9.f64 = afterLower;
	ctx.f10.f64 = lowerSelector;
	ctx.f11.f64 = upperBound;
	ctx.f12.f64 = belowLower;
	ctx.f13.f64 = lowerBound;
	ctx.cr0 = cr[0];
	ctx.xer.ca = xer.ca;
	return upperLtIndex;
}
PROMOTED_ENTRY(7, sub_8223D308, 0x8223D308) { ctx.r3.u64 = n_sub_8223D308(ctx, base, ctx.r3.u64); }

// Lua_Stats_GetPurity: the purity value is returned in f1.
uint64_t n_sub_8223D8F8(CpuState& ctx, uint8_t* base, uint64_t statsAddr) {
	constexpr int32_t str_TXT_820B5BBC_B_ = int32_t(0x820B5BBC);
	constexpr int32_t str_TXT_820B5BD0_B_ = int32_t(0x820B5BD0);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(7, 0x8223D8F8)) { ctx.r3.u64 = statsAddr; __imp__sub_8223D8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8223D8F8);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	// Register state of the original code: handed to n_sub_8223D5E0 and left for callers.
	uint64_t r6Value = ctx.r6.u64;
	uint32_t r7Value = ctx.r7.u32;
	PPCCRRegister cr[8] = {ctx.cr0, ctx.cr1, ctx.cr2, ctx.cr3, ctx.cr4, ctx.cr5, {}, ctx.cr7};
	PPCXERRegister xer = ctx.xer;
	// The condition register as one word (mfcr), cr0 in the top four bits.
	auto conditionWord = [&cr]() {
		uint32_t word = 0;
		for (const PPCCRRegister& field : cr) {
			word = (word << 4) | (field.lt ? 8u : 0u) | (field.gt ? 4u : 0u) | (field.eq ? 2u : 0u) | (field.so ? 1u : 0u);
		}
		return word;
	};
	stack = PushStackFrame(base, stack, 128);

	double purity = double(stats->m_24);
	ctx.r1.u64 = stack;
	const uint32_t bonusActive = n_sub_822385C0(ctx, base, statsAddr, 12);  // Lua_Stats_IsBonusActive
	uint32_t r8Value = ctx.r8.u32;
	if (uint32_t(bonusActive & 0xFF) != 0) {
		CECStats_GetStatValue(ctx, base, uint32_t(statsAddr), 12);
		r8Value = ctx.r8.u32;
		ctx.fpscr.disableFlushMode();
		purity = double(float(ctx.f1.f64 + purity));
	}

	// When bit 20 of the flags word at +36 of the object at stats+4 is set, take the value stored
	// under key 20 in its table of 8-byte {key, value} entries: from the cached entry when there
	// is one, otherwise through a lower-bound binary search.
	const uint32_t container = stats->m_4;
	uint32_t augment = 0;
	bool hasAugment = false;
	if (((LOAD32(container + 36) >> 20) & 1) != 0) {
		hasAugment = true;
		const uint32_t cachedEntry = LOAD32(container + 140);
		if (cachedEntry != 0) {
			const uint32_t entryOffset = uint32_t(LOAD8(cachedEntry + 20)) << 3;
			augment = LOAD32(entryOffset + LOAD32(container + 72) + 4);
		} else {
			const uint32_t first = LOAD32(container + 72);
			const uint32_t end = LOAD32(container + 76);
			r6Value = end;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, first);
			const uint32_t byteCount = end - first;
			xer.ca = ((int32_t)byteCount < 0) & ((byteCount & 0x7) != 0);
			int32_t count = (int32_t)byteCount >> 3;
			cr[0].compare<int32_t>(count, 0, xer);
			uint32_t entry = first;
			if (count > 0) {
				xer.ca = 0;   // count stays positive inside the loop
				do {
					const int32_t half = count >> 1;
					const uint32_t halfBytes = uint32_t(half) << 3;
					entry += halfBytes;
					const bool keyBelow = (int32_t)LOAD32(entry) < 20;
					r7Value = keyBelow ? 1 : 0;
					r8Value = halfBytes;
					if (keyBelow) {
						entry += 8;
						count = count - half - 1;
					} else {
						entry -= halfBytes;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, entry);
			}
			if (entry != end && !((int32_t)LOAD32(entry) > 20)) {
				STORE64(stack + 80, LOAD64(stack + 80));
				augment = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				augment = LOAD32(end + 4);
			}
		}
	}

	if (hasAugment) {
		// state the callee may pass on
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.cr0 = cr[0];
		ctx.xer.ca = xer.ca;
		const uint32_t hasEvilAddition = n_sub_8223D5E0(ctx, base, augment, 7);
		cr[0] = ctx.cr0;
		xer.ca = ctx.xer.ca;
		if (uint32_t(hasEvilAddition & 0xFF) != 0) {
			CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, (uint64_t)(int64_t)str_TXT_820B5BBC_B_, -1);
			BalancingAugmentations_GetFloat(ctx, base, stack + 80);
			ctx.fpscr.disableFlushMode();
			purity = double(float(ctx.f1.f64 + purity));
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 80);
			cr[0] = ctx.cr0;
			cr[1] = ctx.cr1;
			cr[5] = ctx.cr5;
			cr[7] = ctx.cr7;
			xer.ca = ctx.xer.ca;
		}
		const uint32_t hasHolyAddition = n_sub_8223D5E0(ctx, base, augment, 6);
		cr[0] = ctx.cr0;
		xer.ca = ctx.xer.ca;
		if (uint32_t(hasHolyAddition & 0xFF) != 0) {
			CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, (uint64_t)(int64_t)str_TXT_820B5BD0_B_, -1);
			BalancingAugmentations_GetFloat(ctx, base, stack + 80);
			ctx.fpscr.disableFlushMode();
			purity = double(float(ctx.f1.f64 + purity));
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 80);
			cr[0] = ctx.cr0;
			cr[1] = ctx.cr1;
			cr[5] = ctx.cr5;
			cr[7] = ctx.cr7;
			xer.ca = ctx.xer.ca;
		}
	}

	// Two branch-free selects against m_28 and m_2C: each difference is compared with the float
	// at 0x820994B4, and the cr6 lt/unordered bits pick a float of the table at 0x82100170 whose
	// sign chooses between the two candidates.
	ctx.fpscr.disableFlushMode();
	const double lowerBound = double(stats->m_28);
	const double belowLower = double(float(purity - lowerBound));
	const double upperBound = double(stats->m_2C);
	const uint32_t selectTable = uint32_t(g_82100170);
	const double compareLimit = double(LOAD_F32(0x820994B4u));
	cr[6].compare(belowLower, compareLimit);
	const uint32_t conditionAfterLower = conditionWord();
	const uint32_t lowerLtIndex = (conditionAfterLower >> 5) & 4;   // cr6.lt
	const uint32_t lowerUnIndex = (conditionAfterLower >> 2) & 4;   // cr6.un
	const uint64_t lowerIndex = uint64_t(lowerLtIndex) | uint64_t(lowerUnIndex);
	const double lowerSelector = double(LOAD_F32(selectTable + uint32_t(lowerIndex)));
	const double afterLower = lowerSelector >= 0.0 ? purity : lowerBound;
	cr[6].compare(double(float(afterLower - upperBound)), compareLimit);
	const uint32_t conditionAfterUpper = conditionWord();
	const uint32_t upperLtIndex = (conditionAfterUpper >> 5) & 4;
	const uint32_t upperIndex = upperLtIndex | ((conditionAfterUpper >> 2) & 4);
	const double result = double(LOAD_F32(selectTable + upperIndex)) >= 0.0 ? upperBound : afterLower;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = conditionAfterUpper;
	ctx.r5.u64 = lowerIndex;
	ctx.r6.u64 = lowerUnIndex;
	ctx.r7.u64 = lowerLtIndex;
	ctx.r8.u64 = conditionAfterLower;
	ctx.f1.f64 = result;
	ctx.f9.f64 = afterLower;
	ctx.f10.f64 = lowerSelector;
	ctx.f11.f64 = upperBound;
	ctx.f12.f64 = belowLower;
	ctx.f13.f64 = lowerBound;
	ctx.cr0 = cr[0];
	ctx.xer.ca = xer.ca;
	return upperLtIndex;
}
PROMOTED_ENTRY(7, sub_8223D8F8, 0x8223D8F8) { ctx.r3.u64 = n_sub_8223D8F8(ctx, base, ctx.r3.u64); }

uint64_t CECStats_ApplyPurityBalancing(CpuState& ctx, uint8_t* base, uint64_t statsAddr) {
	constexpr int32_t str_TXT_82001440_B_ = int32_t(0x82001440);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(12, 0x822BCDD0)) { ctx.r3.u64 = statsAddr; __imp__sub_822BCDD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822BCDD0);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.fpscr.disableFlushMode();

	// Object reached from the global at 0x83496920 through the pointers at +12, +88, +4 and +20.
	const uint32_t record = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4) + 20);
	const double offsetConstant = double(LOAD_F32(0x820994C0u));
	const double storedValue = double(stats->m_PurityBalancingValue);
	const double recordFloat = double(LOAD_F32(record + 4));

	// The int at record+8 is converted to float through a 64-bit stack temporary.
	STORE64(stack + 88, uint64_t(int64_t(int32_t(LOAD32(record + 8)))));
	PPCRegister recordIntBits{};
	recordIntBits.f64 = LOAD_F64(stack + 88);
	const double recordIntAsDouble = double(recordIntBits.s64);
	const double recordIntAsFloat = double(float(recordIntAsDouble));
	const double total = double(float(recordIntAsFloat + recordFloat));
	const double adjustedTotal = double(float(total - offsetConstant));

	uint64_t result = statsAddr;
	if (!(adjustedTotal < storedValue)) {
		const double threshold = double(stats->m_PurityBalancingThreshold);
		const double newValue = double(float(adjustedTotal + offsetConstant));
		stats->m_PurityBalancingValue = float(newValue);
		if (!(adjustedTotal < threshold)) {
			const uint64_t nameString = uint64_t(stack) + 80;
			const uint64_t recordRef = uint64_t(stack) + 88;
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r6.u64 = record;
			ctx.f7.f64 = total;
			ctx.f8.f64 = recordIntAsFloat;
			ctx.f9.f64 = recordIntAsDouble;
			ctx.f10 = recordIntBits;
			ctx.f11.f64 = newValue;
			ctx.f12.f64 = threshold;
			ctx.f13.f64 = offsetConstant;
			CCharString_ConstructFromCStr(ctx, base, nameString, uint64_t(str_TXT_82001440_B_), -1);
			GameDBRecordRef_Construct(ctx, base, recordRef, uint32_t(stack) + 80);
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);
			if (LOAD32(stack + 88) != 0) {
				const uint64_t id = IdRef_Get(ctx, base, recordRef);
				GameDB_GetFloatByName(ctx, base, id, uint64_t(int64_t(-2113184140)));
				result = n_sub_8249DD50(ctx, base, statsAddr, ctx.f1.f64);  // Lua_Stats_ModifyPurity
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(12, sub_822BCDD0, 0x822BCDD0) { ctx.r3.u64 = CECStats_ApplyPurityBalancing(ctx, base, ctx.r3.u64); }

// sub_822D9508 = Lua_Stats_ModifyTrackedStat (Lua Stats.ModifyTrackedStat)  [388 bytes]
uint64_t n_sub_822D9508(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint64_t statId, uint64_t amountDelta) {
	constexpr int32_t str_TXT_820B5C84_B_ = int32_t(0x820B5C84);
	constexpr int32_t str_TXT_820B5DCC_B_ = int32_t(0x820B5DCC);
	constexpr int32_t str_TXT_820B5DEC_B_ = int32_t(0x820B5DEC);
	constexpr int32_t g_822E0000 = int32_t(0x822E0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(13, 0x822D9508)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = statId; ctx.r5.u64 = amountDelta; __imp__sub_822D9508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D9508);

	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	// Only stats whose owner entity (m_4) is a player are changed. The players object sits at the end
	// of a pointer chain that starts at the global 0x83496920.
	const uint32_t ownerEntity = stats->m_4;
	const uint32_t link1 = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	const uint32_t link2 = LOAD32(link1 + 88);
	const uint32_t link3 = LOAD32(link2 + 4);
	const uint32_t players = LOAD32(link3);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r5.u64 = amountDelta;
	ctx.r8.u64 = link3;
	ctx.r9.u64 = link2;
	ctx.r10.u64 = link1;
	uint64_t result = Players_IsPlayer(ctx, base, players, ownerEntity);
	const uint64_t isPlayer = (uint32_t)result & 0xFF;
	// Registers handed on to later calls and back to callers.
	uint64_t savedR0 = ctx.r0.u64;
	uint64_t savedR6 = ctx.r6.u64;
	uint64_t savedR7 = isPlayer;
	uint64_t savedR10 = ctx.r10.u64;
	double savedF13 = ctx.f13.f64;

	if (isPlayer != 0) {
		const uint32_t tableIndex = (uint32_t)statId - 20;
		if (tableIndex <= 78) {
			// the original dispatches through a jump table and leaves the loaded entry in r0
			savedR0 = LOAD32(uint32_t(g_822E0000) - 27280 + (tableIndex << 2));
			// A few tracked stats are assigned outright instead of being accumulated.
			const bool assignOutright = (tableIndex == 0 || tableIndex == 30 || tableIndex == 61 || tableIndex == 63 ||
			                             tableIndex == 76 || tableIndex == 77 || tableIndex == 78);
			if (assignOutright) {
				// state the callee may pass on
				ctx.r0.u64 = savedR0;
				ctx.r7.u64 = savedR7;
				const uint64_t setResult = n_sub_824A0030(ctx, base, statsAddr, statId, amountDelta);  // Lua_Stats_SetTrackedStat
				stack = PopStackFrame(stack, 144);
				ctx.r1.u64 = stack;
				return setResult;
			}
		}

		if ((uint32_t)amountDelta != 0) {
			// Add the delta to this stat's counter in the stats object (stat N's counter is at 4 * (N + 87)).
			const uint32_t counterAddr = (((uint32_t)statId + 87) << 2) + (uint32_t)statsAddr;
			savedR10 = LOAD32(counterAddr) + amountDelta;
			STORE32(counterAddr, (uint32_t)savedR10);

			if ((uint32_t)statId <= 122) {
				ctx.r0.u64 = savedR0;  // state the callee may pass on
				const uint64_t trackedStatIndex = Stats_MapTrackedStatIndex(ctx, base, statId);
				savedR0 = ctx.r0.u64;
				result = trackedStatIndex;
				if ((int32_t)trackedStatIndex > 0) {
					// state the callee may pass on
					ctx.r3.u64 = trackedStatIndex;
					ctx.r7.u64 = savedR7;
					ctx.r10.u64 = savedR10;
					const uint64_t trackedStats = n_sub_8217E3F8(ctx, base);
					savedF13 = ctx.f13.f64;
					result = TrackedStats_AddValue(ctx, base, trackedStats, trackedStatIndex, amountDelta);
					savedR0 = ctx.r0.u64;
					savedR6 = ctx.r6.u64;
					savedR7 = ctx.r7.u64;
					savedR10 = ctx.r10.u64;
					savedF13 = ctx.f13.f64;
				}
			}

			if ((int32_t)statId == 80) {
				// Stat 80 (counter m_29C): once m_58 is at least 2.0f, the hero-title record names the count
				// that makes the matching inventory title free to buy.
				ctx.fpscr.disableFlushMode();
				savedF13 = double(stats->m_58);
				if (!(savedF13 < double(LOAD_F32(0x8209B4E0u)))) {
					const uint32_t nameAddr = stack + 80;
					const uint32_t recordRefAddr = stack + 88;
					// state the callee may pass on
					ctx.r0.u64 = savedR0;
					ctx.r7.u64 = savedR7;
					ctx.r10.u64 = savedR10;
					ctx.f13.f64 = savedF13;
					CCharString_ConstructFromCStr(ctx, base, nameAddr, str_TXT_820B5C84_B_, -1);
					savedF13 = ctx.f13.f64;
					GameDBRecordRef_Construct(ctx, base, recordRefAddr, nameAddr);
					result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameAddr);
					savedR0 = ctx.r0.u64;
					savedR6 = ctx.r6.u64;
					savedR7 = ctx.r7.u64;
					savedF13 = ctx.f13.f64;
					const uint32_t record = LOAD32(recordRefAddr);
					savedR10 = record;
					if (record != 0) {
						ctx.r10.u64 = savedR10;  // state the callee may pass on
						const uint64_t recordId = IdRef_Get(ctx, base, recordRefAddr);
						const uint64_t countFieldName = str_TXT_820B5DCC_B_;
						ctx.r7.u64 = countFieldName;  // state the callee may pass on
						result = GameDB_GetIntByName(ctx, base, recordId, countFieldName);
						savedR7 = ctx.r7.u64;
						savedR10 = ctx.r10.u64;
						savedR6 = stats->m_29C;
						if ((int32_t)savedR6 >= (int32_t)result) {
							ctx.r6.u64 = savedR6;  // state the callee may pass on
							CCharString_ConstructFromCStr(ctx, base, nameAddr, str_TXT_820B5DEC_B_, -1);
							savedF13 = ctx.f13.f64;
							const uint64_t isFreeToBuy = n_sub_8249FB20(ctx, base, statsAddr, nameAddr) & 0xFF;  // Lua_Stats_IsTitleFreeToBuy
							savedR10 = isFreeToBuy;
							if (isFreeToBuy == 0) {
								ctx.r10.u64 = savedR10;  // state the callee may pass on
								n_sub_8249F8A0(ctx, base, statsAddr, nameAddr, ctx.r8.u64);  // Lua_Stats_SetTitleAsFreeToBuy
								savedR10 = ctx.r10.u64;
								savedF13 = ctx.f13.f64;
							}
							ctx.r10.u64 = savedR10;  // state the callee may pass on
							result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameAddr);
							savedR0 = ctx.r0.u64;
							savedR6 = ctx.r6.u64;
							savedR7 = ctx.r7.u64;
							savedR10 = ctx.r10.u64;
							savedF13 = ctx.f13.f64;
						}
					}
				}
			}
		}
	}

	stack = PopStackFrame(stack, 144);
	// callers read these registers after the call
	ctx.r0.u64 = savedR0;
	ctx.r1.u64 = stack;
	ctx.r6.u64 = savedR6;
	ctx.r7.u64 = savedR7;
	ctx.r10.u64 = savedR10;
	ctx.f13.f64 = savedF13;
	return result;
}
PROMOTED_ENTRY(13, sub_822D9508, 0x822D9508) { ctx.r3.u64 = n_sub_822D9508(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// sub_8249C528  [60 bytes]
uint64_t CECStats_GetClassName(CpuState& ctx, uint8_t* base, uint64_t outClassName) {
	constexpr int32_t str_TXT_820B59D0_B_ = int32_t(0x820B59D0);
	if (!UseLiftedCode(28, 0x8249C528)) { ctx.r3.u64 = outClassName; __imp__sub_8249C528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249C528);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, outClassName, str_TXT_820B59D0_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return outClassName;
}
PROMOTED_ENTRY(28, sub_8249C528, 0x8249C528) { ctx.r3.u64 = CECStats_GetClassName(ctx, base, ctx.r3.u64); }

// Deleting destructor: destroys the stats object and frees its memory when bit 0 of the flags is set.
uint64_t n_sub_8249CAC8(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(28, 0x8249CAC8)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8249CAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249CAC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	n_sub_8249CB18(ctx, base, statsAddr);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, statsAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return statsAddr;
}
PROMOTED_ENTRY(28, sub_8249CAC8, 0x8249CAC8) { ctx.r3.u64 = n_sub_8249CAC8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Destructor: releases the members of the stats object and resets its vtables to the base classes' ones.
uint32_t n_sub_8249CB18(CpuState& ctx, uint8_t* base, uint64_t statsAddr) {
	if (!UseLiftedCode(28, 0x8249CB18)) { ctx.r3.u64 = statsAddr; __imp__sub_8249CB18(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8249CB18);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	const uint32_t stats32 = (uint32_t)statsAddr;

	stack = PushStackFrame(base, stack, 128);

	ctx.r1.u64 = stack;
	n_sub_8233DD70(ctx, base, statsAddr + 2176);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, statsAddr + 2160);
	n_sub_82EE1CA8(ctx, base, statsAddr + 1280, ctx.r7.u64, ctx.r8.u64);

	// Each handle slot: free the handle it holds, if any, then clear it and the two words after it.
	auto releaseHandleSlot = [&](uint32_t handle, uint32_t slotAddr) {
		if (handle != 0) {
			HandleTarget_Free(ctx, base, handle);
		}
		STORE32(slotAddr, 0u);
		STORE32(slotAddr + 4, 0u);
		STORE32(slotAddr + 8, 0u);
	};
	releaseHandleSlot(stats->m_150, stats32 + 0x150);
	releaseHandleSlot(stats->m_100, stats32 + 0x100);
	releaseHandleSlot(stats->m_F0, stats32 + 0xF0);
	releaseHandleSlot(stats->m_E0, stats32 + 0xE0);
	releaseHandleSlot(stats->m_D0, stats32 + 0xD0);

	n_sub_8233DD70(ctx, base, statsAddr + 192);
	n_sub_824AEB00(ctx, base, statsAddr + 180);
	n_sub_823FB150(ctx, base, statsAddr + 168);
	n_sub_824AE560(ctx, base, statsAddr + 156);
	n_sub_82308D08(ctx, base, statsAddr + 144);
	n_sub_823FB150(ctx, base, statsAddr + 132);
	Vector_DestroyAndFree(ctx, base, statsAddr + 116);
	const uint32_t result = Vector_DestroyAndFree(ctx, base, statsAddr + 100);

	// The subobject at +12 has its own vtable pointer; a null object maps it to address 0, as in the original.
	const uint32_t subobjectVtableAddr = stats32 != 0 ? stats32 + 12 : 0;
	STORE32(subobjectVtableAddr, 0x820A2BC4u);
	stats->vtable = 0x820A8D10u;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(28, sub_8249CB18, 0x8249CB18) { ctx.r3.u64 = n_sub_8249CB18(ctx, base, ctx.r3.u64); }

// sub_8249EBE0 = Lua_Stats_TXT_820B5CE4_B_ (Lua Stats.TXT_820B5CE4_B_)  [332 bytes]
uint64_t n_sub_8249EBE0(CpuState& ctx, uint8_t* base, uint64_t statsAddr, double delta) {
	constexpr int32_t g_8209BE60 = int32_t(0x8209BE60);
	constexpr int32_t str_TXT_820B5CE4_B_ = int32_t(0x820B5CE4);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(28, 0x8249EBE0)) { ctx.r3.u64 = statsAddr; ctx.f1.f64 = delta; __imp__sub_8249EBE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249EBE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	const uint32_t floatPool = uint32_t(g_8209BE60);    // 100.0f; the other constants are addressed from it
	const uint32_t selectTable = uint32_t(g_82100170);  // { 1.0f, -1.0f }
	const uint32_t stats32 = (uint32_t)statsAddr;
	PPCRegister heightDelta{};
	heightDelta.f64 = delta;

	// Add the delta to the height (offset 60), then clamp it to [-1, 1] with the compiler's branchless
	// select: compare with zero, index the select table with the lt/unordered bits, and keep the first
	// operand when the entry is not negative.
	const double oldHeight = double(LOAD_F32(stats32 + 60));
	const double minusOne = double(LOAD_F32(floatPool + 8100));  // the lowest height
	const double zero = double(LOAD_F32(floatPool - 10668));
	PPCRegister newHeight{};
	newHeight.f64 = double(float(heightDelta.f64 + oldHeight));
	const double one = double(LOAD_F32(floatPool - 10656));      // the highest height
	STORE_F32(stats32 + 60, float(newHeight.f64));

	const double aboveMin = double(float(newHeight.f64 - minusOne));
	PPCCRRegister compare6{};
	compare6.compare(aboveMin, zero);
	const uint32_t lowSoBit = compare6.so ? 4u : 0u;
	const uint64_t lowIndex = (compare6.lt ? 4u : 0u) | lowSoBit;
	const double lowSelector = double(LOAD_F32(selectTable + uint32_t(lowIndex)));
	const double atLeastMin = lowSelector >= 0.0 ? newHeight.f64 : minusOne;

	const double aboveMax = double(float(atLeastMin - one));
	compare6.compare(aboveMax, zero);
	const uint32_t highLtBit = compare6.lt ? 4u : 0u;
	const double highSelector = double(LOAD_F32(selectTable + (highLtBit | (compare6.so ? 4u : 0u))));
	const double clampedHeight = highSelector >= 0.0 ? one : atLeastMin;
	STORE_F32(stats32 + 60, float(clampedHeight));

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = highLtBit;
	ctx.r6.u64 = lowIndex;
	ctx.r7.u64 = lowSoBit;
	ctx.f1.f64 = delta;
	ctx.f6.f64 = clampedHeight;
	ctx.f7.f64 = highSelector;
	ctx.f8.f64 = aboveMax;
	ctx.f9.f64 = atLeastMin;
	ctx.f10.f64 = lowSelector;
	ctx.f11.f64 = aboveMin;
	ctx.f12.f64 = newHeight.f64;
	ctx.f13 = newHeight;
	uint64_t result = HeroStats_NotifyStatModified(ctx, base, statsAddr);

	// When the flag at offset 995 is set, a change larger than 1e-4 is reported as a stat modifier:
	// type 42 for a rise, 43 for a drop, with the value as an integer of 100 times the (positive) change.
	const uint32_t reportModifiers = LOAD8(stats32 + 995);
	if (reportModifiers != 0) {
		ctx.fpscr.disableFlushMode();
		PPCRegister deltaMagnitude{};
		deltaMagnitude.u64 = heightDelta.u64 & ~0x8000000000000000ULL;
		const double minReportedDelta = double(LOAD_F32(0x82099AE0u));
		if (deltaMagnitude.f64 > minReportedDelta) {
			uint32_t modifierType = 42;
			if (heightDelta.f64 < zero) {
				modifierType = 43;
				heightDelta.f64 = double(float(heightDelta.f64 * minusOne));
			}

			const uint32_t modifierName = stack + 80;
			// state the callee may pass on
			ctx.r8.u64 = reportModifiers;
			ctx.f13 = deltaMagnitude;
			CCharString_ConstructFromCStr(ctx, base, modifierName, str_TXT_820B5CE4_B_, -1);

			ctx.fpscr.disableFlushMode();
			const double deltaScale = double(LOAD_F32(floatPool));
			double scaledDelta = double(float(heightDelta.f64 * deltaScale));
			const uint32_t valueString = stack + 88;
			const uint32_t statsGlobals = LOAD32(0x834968A4u);
			// convert to int32 through the stack, as the original does
			PPCRegister scaledDeltaInt{};
			scaledDeltaInt.s64 = std::isnan(scaledDelta) ? int64_t(0x80000000U) : scaledDelta > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&scaledDelta));
			STORE_F64(stack + 88, scaledDeltaInt.f64);
			const uint32_t scaledDeltaLow = LOAD32(stack + 92);
			const uint32_t ownerEntity = LOAD32(stats32 + 4);
			const uint32_t globalsEntry = LOAD32(LOAD32(statsGlobals + 32) + 28);
			ctx.f13 = scaledDeltaInt;  // state the callee may pass on
			const uint64_t modifierValue = n_sub_82303F98(ctx, base, valueString, scaledDeltaLow);

			Stats_ApplyModifierIfAllowed(ctx, base, globalsEntry, modifierName, ownerEntity, modifierValue, modifierType);

			CCharString_ReleaseAndDecGlobalCountB(ctx, base, valueString);
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, modifierName);
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(28, sub_8249EBE0, 0x8249EBE0) { ctx.r3.u64 = n_sub_8249EBE0(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// Sets m_3C (the field Lua Stats.TXT_820B5CE4_B_ adds to) to the value clamped to [-1, 1] and notifies the stat system.
uint64_t CECStats_ModifyStat(CpuState& ctx, uint8_t* base, uint64_t statsAddr, double statValue) {
	constexpr int32_t g_82100170 = int32_t(0x82100170);  // select table { 1.0f, -1.0f }
	constexpr uint32_t kMinusOne = 0x8209DE04;  // -1.0f, the lower bound
	constexpr uint32_t kOne = 0x820994C0;       // 1.0f, the upper bound
	constexpr uint32_t kZero = 0x820994B4;      // 0.0f
	if (!UseLiftedCode(28, 0x8249ED38)) { ctx.r3.u64 = statsAddr; ctx.f1.f64 = statValue; __imp__sub_8249ED38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249ED38);

	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	ctx.fpscr.disableFlushMode();
	stats->m_3C = float(statValue);

	const double maxValue = double(LOAD_F32(kOne));
	const double minValue = double(LOAD_F32(kMinusOne));
	const double zero = double(LOAD_F32(kZero));

	// The compiler's branchless select: compare with zero, index the select table with the lt/unordered
	// bits, and keep the first operand when the entry is not negative.
	const double aboveMin = double(float(statValue - minValue));
	PPCCRRegister compare6{};
	compare6.compare(aboveMin, zero);
	const uint32_t lowIndex = (compare6.lt ? 4u : 0u) | (compare6.so ? 4u : 0u);
	const double lowSelector = double(LOAD_F32(uint32_t(g_82100170) + lowIndex));
	const double atLeastMin = lowSelector >= 0.0 ? statValue : minValue;

	const double aboveMax = double(float(atLeastMin - maxValue));
	compare6.compare(aboveMax, zero);
	const uint64_t highIndex = (compare6.lt ? 4u : 0u) | (compare6.so ? 4u : 0u);
	const double highSelector = double(LOAD_F32(uint32_t(g_82100170) + uint32_t(highIndex)));
	const double clamped = highSelector >= 0.0 ? maxValue : atLeastMin;
	stats->m_3C = float(clamped);

	// state the callee may pass on
	ctx.r6.u64 = highIndex;
	ctx.r7.u64 = uint64_t(int64_t(g_82100170));  // the table address as the original's lis leaves it (sign-extended)
	ctx.f1.f64 = statValue;
	ctx.f5.f64 = clamped;
	ctx.f6.f64 = highSelector;
	ctx.f7.f64 = aboveMax;
	ctx.f8.f64 = atLeastMin;
	ctx.f9.f64 = lowSelector;
	ctx.f10.f64 = aboveMin;
	ctx.f11.f64 = statValue;
	ctx.f12.f64 = maxValue;
	ctx.f13.f64 = zero;
	return HeroStats_NotifyStatModified(ctx, base, statsAddr);
}
PROMOTED_ENTRY(28, sub_8249ED38, 0x8249ED38) { ctx.r3.u64 = CECStats_ModifyStat(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// sub_8249EDA8 = Lua_Stats_TXT_820B5CF4_B_ (Lua Stats.TXT_820B5CF4_B_)  [320 bytes]
uint64_t n_sub_8249EDA8(CpuState& ctx, uint8_t* base, uint64_t heroStats, double delta) {
	constexpr int32_t g_8209BE60 = int32_t(0x8209BE60);
	constexpr int32_t str_TXT_820B5CF4_B_ = int32_t(0x820B5CF4);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(28, 0x8249EDA8)) { ctx.r3.u64 = heroStats; ctx.f1.f64 = delta; __imp__sub_8249EDA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249EDA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	const uint32_t floatPool = uint32_t(g_8209BE60);    // 100.0f; the other constants are addressed from it
	const uint32_t selectTable = uint32_t(g_82100170);  // { 1.0f, -1.0f }
	const uint32_t stats32 = (uint32_t)heroStats;
	PPCRegister strengthDelta{};
	strengthDelta.f64 = delta;

	// Add the delta to the strength (offset 64), then clamp it to [0, 1] with the compiler's branchless
	// select: compare with zero, index the select table with the lt/unordered bits, and keep the first
	// operand when the entry is not negative.
	const double oldStrength = double(LOAD_F32(stats32 + 64));
	const double zero = double(LOAD_F32(floatPool - 10668));  // also the lowest strength
	PPCRegister newStrength{};
	newStrength.f64 = double(float(strengthDelta.f64 + oldStrength));
	const double one = double(LOAD_F32(floatPool - 10656));   // the highest strength
	STORE_F32(stats32 + 64, float(newStrength.f64));

	PPCCRRegister compare6{};
	compare6.compare(newStrength.f64, zero);
	const uint32_t lowLtBit = compare6.lt ? 4u : 0u;
	const uint32_t lowSoBit = compare6.so ? 4u : 0u;
	const uint64_t lowIndex = lowLtBit | lowSoBit;
	const double lowSelector = double(LOAD_F32(selectTable + uint32_t(lowIndex)));
	const double atLeastZero = lowSelector >= 0.0 ? newStrength.f64 : zero;

	const double aboveOne = double(float(atLeastZero - one));
	compare6.compare(aboveOne, zero);
	const uint32_t highLtBit = compare6.lt ? 4u : 0u;
	const double highSelector = double(LOAD_F32(selectTable + (highLtBit | (compare6.so ? 4u : 0u))));
	const double clampedStrength = highSelector >= 0.0 ? one : atLeastZero;
	STORE_F32(stats32 + 64, float(clampedStrength));

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = highLtBit;
	ctx.r6.u64 = lowIndex;
	ctx.r7.u64 = lowSoBit;
	ctx.r8.u64 = lowLtBit;
	ctx.f1.f64 = delta;
	ctx.f7.f64 = clampedStrength;
	ctx.f8.f64 = highSelector;
	ctx.f9.f64 = aboveOne;
	ctx.f10.f64 = atLeastZero;
	ctx.f11.f64 = lowSelector;
	ctx.f12.f64 = newStrength.f64;
	ctx.f13 = newStrength;
	uint64_t result = HeroStats_NotifyStatModified(ctx, base, heroStats);
	// Registers callers read after the call.
	PPCRegister savedF13 = ctx.f13;

	// When the flag at offset 995 is set, a change larger than 1e-4 is passed on as a stat modifier:
	// type 44 for a gain, 45 for a loss, with the value as an integer of 100 times the (positive) change.
	const uint64_t reportModifiers = LOAD8(stats32 + 995);
	uint64_t savedR8 = reportModifiers;
	if ((uint32_t)reportModifiers != 0) {
		ctx.fpscr.disableFlushMode();
		PPCRegister deltaMagnitude{};
		deltaMagnitude.u64 = strengthDelta.u64 & ~0x8000000000000000ULL;
		savedF13 = deltaMagnitude;
		const double minReportedDelta = double(LOAD_F32(0x82099AE0u));
		if (deltaMagnitude.f64 > minReportedDelta) {
			uint32_t modifierType = 44;
			if (strengthDelta.f64 < zero) {
				const double minusOne = double(LOAD_F32(floatPool + 8100));
				modifierType = 45;
				strengthDelta.f64 = double(float(strengthDelta.f64 * minusOne));
			}

			const uint32_t modifierName = stack + 80;
			// state the callee may pass on
			ctx.r8.u64 = reportModifiers;
			ctx.f13 = deltaMagnitude;
			CCharString_ConstructFromCStr(ctx, base, modifierName, str_TXT_820B5CF4_B_, -1);

			ctx.fpscr.disableFlushMode();
			const double deltaScale = double(LOAD_F32(floatPool));
			double scaledDelta = double(float(strengthDelta.f64 * deltaScale));
			const uint32_t valueString = stack + 88;
			const uint32_t statsGlobals = LOAD32(0x834968A4u);
			// convert to int32 through the stack, as the original does
			PPCRegister scaledDeltaInt{};
			scaledDeltaInt.s64 = std::isnan(scaledDelta) ? int64_t(0x80000000U) : scaledDelta > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&scaledDelta));
			STORE_F64(stack + 88, scaledDeltaInt.f64);
			const uint32_t scaledDeltaLow = LOAD32(stack + 92);
			const uint32_t ownerEntity = LOAD32(stats32 + 4);
			const uint32_t globalsEntry = LOAD32(LOAD32(statsGlobals + 32) + 28);
			ctx.f13 = scaledDeltaInt;  // state the callee may pass on
			const uint64_t modifierValue = n_sub_82303F98(ctx, base, valueString, scaledDeltaLow);

			Stats_ApplyModifierIfAllowed(ctx, base, globalsEntry, modifierName, ownerEntity, modifierValue, modifierType);

			CCharString_ReleaseAndDecGlobalCountB(ctx, base, valueString);
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, modifierName);
			savedR8 = ctx.r8.u64;
			savedF13 = ctx.f13;
		}
	}

	stack = PopStackFrame(stack, 144);
	// callers read these registers after the call
	ctx.r1.u64 = stack;
	ctx.r8.u64 = savedR8;
	ctx.f13 = savedF13;
	return result;
}
PROMOTED_ENTRY(28, sub_8249EDA8, 0x8249EDA8) { ctx.r3.u64 = n_sub_8249EDA8(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// sub_8249EEF0 = Lua_Stats_ModifySkill (Lua Stats.ModifySkill)  [512 bytes]
uint64_t n_sub_8249EEF0(CpuState& ctx, uint8_t* base, uint64_t statsAddr, double delta) {
	constexpr int32_t g_82100170 = int32_t(0x82100170);  // select table { 1.0f, -1.0f }
	if (!UseLiftedCode(28, 0x8249EEF0)) { ctx.r3.u64 = statsAddr; ctx.f1.f64 = delta; __imp__sub_8249EEF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249EEF0);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	// The xer so bit at entry ends up in cr0 through the count comparison below.
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 128);

	// Add the delta to the skill (m_44), then clamp it to [0, 1] with the compiler's branchless select:
	// compare with zero, index the select table with the lt/unordered bits, and keep the first operand
	// when the entry is not negative.
	const uint32_t selectTable = uint32_t(g_82100170);
	const double newSkill = double(float(delta + double(stats->m_44)));
	const double one = double(LOAD_F32(0x820994C0u));   // the highest skill
	stats->m_44 = float(newSkill);
	const double zero = double(LOAD_F32(0x820994B4u));  // also the lowest skill

	PPCCRRegister compare6{};
	compare6.compare(newSkill, zero);
	const uint32_t lowLtBit = compare6.lt ? 4u : 0u;
	const uint64_t lowIndex = lowLtBit | (compare6.so ? 4u : 0u);
	const double lowSelector = double(LOAD_F32(selectTable + uint32_t(lowIndex)));
	const double atLeastZero = lowSelector >= 0.0 ? newSkill : zero;

	const double aboveOne = double(float(atLeastZero - one));
	compare6.compare(aboveOne, zero);
	const uint64_t highIndex = (compare6.lt ? 4u : 0u) | (compare6.so ? 4u : 0u);
	const double highSelector = double(LOAD_F32(selectTable + uint32_t(highIndex)));
	const double clampedSkill = highSelector >= 0.0 ? one : atLeastZero;
	stats->m_44 = float(clampedSkill);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = lowIndex;
	ctx.r6.u64 = lowLtBit;
	ctx.r7.u64 = highIndex;
	ctx.r8.u64 = uint64_t(int64_t(g_82100170));  // the table address as the original's lis leaves it (sign-extended)
	ctx.f1.f64 = delta;
	ctx.f7.f64 = clampedSkill;
	ctx.f8.f64 = highSelector;
	ctx.f9.f64 = aboveOne;
	ctx.f10.f64 = atLeastZero;
	ctx.f11.f64 = lowSelector;
	ctx.f12.f64 = newSkill;
	ctx.f13.f64 = newSkill;
	uint64_t result = HeroStats_NotifyStatModified(ctx, base, statsAddr);

	// Registers handed on to the later calls and back to callers.
	uint64_t savedR7 = ctx.r7.u64;
	uint64_t savedR8 = ctx.r8.u64;
	PPCCRRegister compare0 = ctx.cr0;
	flags.ca = ctx.xer.ca;
	const uint32_t container = stats->m_4;
	uint64_t savedR6 = LOAD32(container + 40);
	auto handOverState = [&] {
		ctx.r6.u64 = savedR6;
		ctx.r7.u64 = savedR7;
		ctx.r8.u64 = savedR8;
		ctx.cr0 = compare0;
		ctx.xer.ca = flags.ca;
	};
	auto takeBackState = [&] {
		savedR6 = ctx.r6.u64;
		savedR7 = ctx.r7.u64;
		savedR8 = ctx.r8.u64;
		compare0 = ctx.cr0;
		flags.ca = ctx.xer.ca;
	};

	// Look up the entry stored under key 33 in the owner's key/value container (m_4): bit 1 of the word
	// at +40 says whether key 33 is present. With a slot table at +140 the slot is read directly;
	// otherwise the sorted {key, value} pairs from +72 to +76 are binary searched (lower bound), and a
	// lookup that finds no pair with key 33 uses the value word after the end pointer.
	const uint32_t hasKey33 = (uint32_t)savedR6 >> 1 & 1;
	if (hasKey33 != 0) {
		uint32_t entry;
		const uint32_t slotTable = LOAD32(container + 140);
		if (slotTable != 0) {
			const uint32_t slotOffset = uint32_t(LOAD8(slotTable + 33)) << 3;
			entry = LOAD32(LOAD32(container + 72) + slotOffset + 4);
		} else {
			uint32_t node = LOAD32(container + 72);
			const uint32_t end = LOAD32(container + 76);
			savedR6 = end;
			STORE32(stack + 80, 0u);
			savedR8 = uint64_t(end) - uint64_t(node);
			STORE32(stack + 84, node);
			flags.ca = (int32_t)savedR8 < 0 & ((uint32_t)savedR8 & 0x7) != 0;
			int32_t remaining = (int32_t)savedR8 >> 3;
			compare0.compare<int32_t>(remaining, 0, flags);
			if (remaining > 0) {
				do {
					flags.ca = remaining < 0 & (remaining & 0x1) != 0;
					const int32_t half = remaining >> 1;
					savedR8 = uint32_t(half) << 3;
					node += uint32_t(savedR8);
					savedR7 = int32_t(LOAD32(node)) < 33 ? 1 : 0;
					if (savedR7 != 0) {
						remaining = remaining - half - 1;
						node += 8;
					} else {
						node -= uint32_t(savedR8);
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, node);
			}
			if (node != end && !(int32_t(LOAD32(node)) > 33)) {
				// the original copies its {0, node} result pair in place and reads the node back from it
				STORE64(stack + 80, LOAD64(stack + 80));
				entry = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry = LOAD32(end + 4);
			}
		}

		const uint32_t component = LOAD32(entry + 20);
		if (component != 0) {
			// state the callee may pass on
			ctx.r5.u64 = hasKey33;
			handOverState();
			result = n_sub_821E8870(ctx, base, component, 9);
			takeBackState();
		} else {
			result = 0;
		}
		if ((uint32_t(result) & 0xFF) != 0) {
			ctx.fpscr.disableFlushMode();
			handOverState();  // state the callee may pass on
			result = CECStats_ModifyStat(ctx, base, statsAddr, zero);
			takeBackState();
			STORE8(entry + 392, 1);
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	handOverState();  // callers read r6, r7, r8, cr0 and xer.ca after the call
	return result;
}
PROMOTED_ENTRY(28, sub_8249EEF0, 0x8249EEF0) { ctx.r3.u64 = n_sub_8249EEF0(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// Lua Stats.ModifyWill: adds the delta to the will value (m_48), clamps it between the two global
// bounds and notifies the stats object.
uint64_t n_sub_8249F0F8(CpuState& ctx, uint8_t* base, uint64_t statsAddr, double willDelta) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(28, 0x8249F0F8)) { ctx.r3.u64 = statsAddr; ctx.f1.f64 = willDelta; __imp__sub_8249F0F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249F0F8);
	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	constexpr uint32_t upperBoundAddr = uint32_t(g_820A0000) - 27456;   // 0x820994C0
	constexpr uint32_t lowerBoundAddr = upperBoundAddr - 12;            // 0x820994B4

	// or unordered, the first otherwise; a non-negative entry keeps the unclamped operand.
	constexpr uint32_t selectTableAddr = uint32_t(g_82100170);

	ctx.fpscr.disableFlushMode();

	const double newWill = double(float(willDelta + double(stats->m_48)));
	stats->m_48 = float(newWill);

	const double lowerBound = double(LOAD_F32(lowerBoundAddr));
	const double upperBound = double(LOAD_F32(upperBoundAddr));

	// The original builds each table offset from the lt and unordered bits of its cr6 comparison.
	PPCCRRegister compare{};
	compare.compare(newWill, lowerBound);
	const uint32_t lowUnorderedBit = compare.un ? 4u : 0u;
	const uint32_t lowSelectOffset = (compare.lt ? 4u : 0u) | lowUnorderedBit;
	const double lowSelector = double(LOAD_F32(selectTableAddr + lowSelectOffset));
	const double atLeastLower = lowSelector >= 0.0 ? newWill : lowerBound;

	// The excess over the upper bound is compared against the lower-bound constant as well.
	const double excessOverUpper = double(float(atLeastLower - upperBound));
	compare.compare(excessOverUpper, lowerBound);
	const uint32_t highUnorderedBit = compare.un ? 4u : 0u;
	const uint32_t highSelectOffset = (compare.lt ? 4u : 0u) | highUnorderedBit;
	const double highSelector = double(LOAD_F32(selectTableAddr + highSelectOffset));
	const double clampedWill = highSelector >= 0.0 ? upperBound : atLeastLower;

	stats->m_48 = float(clampedWill);

	// State the callee may pass on (r7 holds the table address sign-extended).
	ctx.r4.u64 = lowUnorderedBit;
	ctx.r6.u64 = highSelectOffset;
	ctx.r7.u64 = uint64_t(int64_t(g_82100170));
	ctx.r8.u64 = highUnorderedBit;
	ctx.f1.f64 = willDelta;
	ctx.f7.f64 = clampedWill;
	ctx.f8.f64 = highSelector;
	ctx.f9.f64 = excessOverUpper;
	ctx.f10.f64 = atLeastLower;
	ctx.f11.f64 = lowSelector;
	ctx.f12.f64 = newWill;
	ctx.f13.f64 = upperBound;
	return HeroStats_NotifyStatModified(ctx, base, statsAddr);
}
PROMOTED_ENTRY(28, sub_8249F0F8, 0x8249F0F8) { ctx.r3.u64 = n_sub_8249F0F8(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// Lua Stats.SetAsBerserk: when set, stores in m_4C the time counter advanced by the record's
// multiplier in time-scale units, and raises strength and height by the bonuses (m_50, m_54) that
// bring them to the target constant; when cleared, zeroes m_4C and takes the stored bonuses back
// off. Both paths then store a constant into m_874.
uint64_t n_sub_8249F170(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint64_t isBerserk) {
	constexpr int32_t str_TXT_820B5D04_B_ = int32_t(0x820B5D04);
	constexpr int32_t str_TXT_820B5D14_B_ = int32_t(0x820B5D14);
	constexpr uint32_t kResetValueAddr = 0x820994B4;   // stored into m_874 on both paths
	constexpr uint32_t kStatTargetAddr = 0x820994C0;   // berserk raises strength and height to this value
	constexpr uint32_t kTimeCounter = 0x8331950C;
	constexpr uint32_t kTimeScale = 0x83319510;
	if (!UseLiftedCode(28, 0x8249F170)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = isBerserk; __imp__sub_8249F170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249F170);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t result;
	double resetValue;
	if ((uint32_t(isBerserk) & 0xFF) != 0) {
		// Multiplier from the game-database record named by str_TXT_820B5D04_B_.
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B5D04_B_, -1);
		GameDBRecordRef_Construct(ctx, base, stack + 88, stack + 80);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		const uint64_t berserkRecord = IdRef_Get(ctx, base, stack + 88);
		GameDB_GetFloatByName(ctx, base, berserkRecord, str_TXT_820B5D14_B_);
		const double multiplier = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();

		const double strength = double(stats->m_40);
		const double timeScale = LOAD_F64(kTimeScale);
		// The original converts the counter to double through a stack slot and keeps the slot's
		// bits in f12.
		const int64_t timeCounter = int32_t(LOAD32(kTimeCounter));
		STORE64(stack + 88, uint64_t(timeCounter));
		PPCRegister counterSlot{};
		counterSlot.f64 = LOAD_F64(stack + 88);
		const double counter = double(counterSlot.s64);
		const double statTarget = double(LOAD_F32(kStatTargetAddr));
		const double berserkEnd = std::fma(multiplier, timeScale, counter);

		const double strengthBonus = double(float(statTarget - strength));
		stats->m_50 = float(strengthBonus);

		// Saturating truncation to int32 (NaN gives 0x80000000), as the original converts.
		const int64_t berserkEndWord = std::isnan(berserkEnd) ? int64_t(0x80000000U)
		                             : berserkEnd >= double(INT32_MAX) ? int64_t(INT32_MAX)
		                             : berserkEnd <= double(INT32_MIN) ? int64_t(INT32_MIN)
		                             : int64_t(int32_t(berserkEnd));
		stats->m_4C = uint32_t(berserkEndWord);

		// State the callee may pass on (r4 still holds the offset of m_4C).
		ctx.r4.u64 = 76;
		ctx.f9.s64 = berserkEndWord;
		ctx.f10.f64 = berserkEnd;
		ctx.f11.f64 = counter;
		ctx.f12.f64 = counterSlot.f64;
		n_sub_8249EDA8(ctx, base, statsAddr, strengthBonus);
		ctx.fpscr.disableFlushMode();

		const double heightBonus = double(float(statTarget - double(stats->m_3C)));
		stats->m_54 = float(heightBonus);
		result = n_sub_8249EBE0(ctx, base, statsAddr, heightBonus);
		ctx.fpscr.disableFlushMode();
		resetValue = double(LOAD_F32(kResetValueAddr));
	} else {
		ctx.fpscr.disableFlushMode();
		const double strengthBonus = double(stats->m_50);
		stats->m_4C = 0u;
		// State the callee may pass on.
		ctx.r1.u64 = stack;
		ctx.r4.u64 = isBerserk;
		n_sub_8249EDA8(ctx, base, statsAddr, -strengthBonus);
		ctx.fpscr.disableFlushMode();

		const double heightBonus = double(stats->m_54);
		result = n_sub_8249EBE0(ctx, base, statsAddr, -heightBonus);
		ctx.fpscr.disableFlushMode();
		resetValue = double(LOAD_F32(kResetValueAddr));
	}

	ctx.fpscr.disableFlushMode();
	stats->m_874 = float(resetValue);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(28, sub_8249F170, 0x8249F170) { ctx.r3.u64 = n_sub_8249F170(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Lua Stats.SetTitleAsFreeToBuy: when m_58 is not below the global threshold and the stats owner
// (m_4) is not the entity stored under key 2, adds the title to the free-to-buy list (vector at
// +0x74, begin m_78, end m_7C) unless it is listed already, checks the completionist achievement
// and, when the title record has message text, shows it in a message box.
uint64_t n_sub_8249F8A0(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint64_t titleRecordName, uint64_t callerR8) {
	constexpr int32_t str_TXT_820B2E78_B_ = int32_t(0x820B2E78);
	constexpr int32_t str_TXT_820B5D84_B_ = int32_t(0x820B5D84);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t TXT_83498164_G_ = int32_t(0x83498164);
	if (!UseLiftedCode(28, 0x8249F8A0)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = titleRecordName; ctx.r8.u64 = callerR8; __imp__sub_8249F8A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249F8A0);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 160);

	// r4, r8 and f13 as the original leaves them for its callers: the entry values, then what the
	// calls below leave there.
	uint64_t r4Out = titleRecordName;
	uint64_t r8Out = callerR8;
	ctx.fpscr.disableFlushMode();
	const double field58 = double(stats->m_58);
	double f13Out = field58;
	uint64_t result = statsAddr;

	if (!(field58 < double(LOAD_F32(0x8209B4E0u)))) {
		const uint32_t world = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
		if (int32_t(LOAD32(world + 284)) >= 1) {
			// State the callee may pass on.
			ctx.r1.u64 = stack;
			ctx.r8.u64 = r8Out;
			const uint64_t handle = SortedArray_FindValueByKey(ctx, base, LOAD32(world + 156), 2);
			r8Out = ctx.r8.u64;
			if (uint32_t(handle) != 0) {
				// State the callee may pass on: r4 still holds the key.
				ctx.r4.u64 = 2;
				ctx.f13.f64 = f13Out;
				result = EntityHandle_GetEntity(ctx, base, handle);
				r4Out = ctx.r4.u64;
				r8Out = ctx.r8.u64;
				f13Out = ctx.f13.f64;
				// The owner is that entity (same words at +20 and +24): nothing to do.
				const uint32_t entity = uint32_t(result);
				const uint32_t owner = stats->m_4;
				if (LOAD32(entity + 20) == LOAD32(owner + 20) && LOAD32(entity + 24) == LOAD32(owner + 24)) goto done;
			}
		}

		// State the callee may pass on.
		ctx.r1.u64 = stack;
		ctx.r8.u64 = r8Out;
		result = GameDBRecordRef_Construct(ctx, base, uint64_t(stack) + 88, titleRecordName);
		r4Out = ctx.r4.u64;
		r8Out = ctx.r8.u64;
		if (LOAD32(stack + 88) == 0) goto done;   // no such record

		// Search the list for the title; the iterator {0, begin} goes through the slot at +96.
		const uint32_t titlesBegin = stats->m_78;
		const uint32_t titlesEnd = stats->m_7C;
		STORE32(stack + 96, 0u);
		STORE32(stack + 100, titlesBegin);
		STORE64(stack + 96, LOAD64(stack + 96));
		uint32_t it = LOAD32(stack + 100);
		if (titlesBegin != titlesEnd) {
			const uint32_t wantedName = LOAD32(uint32_t(titleRecordName));
			do {
				const uint32_t listedName = LOAD32(it);
				if (listedName == wantedName) {
					result = 1;
				} else if (listedName != 0 && wantedName != 0) {
					result = CCharString_Equals(ctx, base, listedName, wantedName);
					r4Out = ctx.r4.u64;
				} else {
					result = 0;
				}
				if ((uint32_t(result) & 0xFF) != 0) break;
				it += 4;
			} while (it != titlesEnd);
		}
		if (it != titlesEnd) goto done;   // already listed

		ctx.f13.f64 = f13Out;   // state the callee may pass on
		StringVector_PushBack(ctx, base, statsAddr + 116, titleRecordName);
		Stats_CheckCompletionistAchievement(ctx, base, statsAddr, ctx.r8.u64);
		f13Out = ctx.f13.f64;

		const uint64_t record = IdRef_Get(ctx, base, uint64_t(stack) + 88);
		ctx.r7.u64 = uint64_t(int64_t(str_TXT_820B2E78_B_));   // state the callee may pass on
		result = GameDB_ReadU32Field(ctx, base, record, str_TXT_820B2E78_B_);
		r4Out = ctx.r4.u64;
		r8Out = ctx.r8.u64;
		if (uint32_t(result) == 0) goto done;

		const uint64_t textKey = n_sub_82345978(ctx, base, result, str_TXT_820B5D84_B_);
		CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, textKey, -1);
		const uint32_t textData = LOAD32(stack + 80);
		if (textData != 0 && int32_t(LOAD32(textData + 4)) != 0) {
			const uint32_t displayRoot = LOAD32(uint32_t(g_83490000) + 26788);
			const uint32_t boxList = LOAD32(LOAD32(displayRoot + 28) + 52);
			const uint64_t keyCopy = CCharString_CopyConstruct(ctx, base, uint64_t(stack) + 96, uint64_t(stack) + 80);
			LocalisedText_InitFromKey(ctx, base, uint64_t(stack) + 88, keyCopy);
			const uint64_t boxMemory = operator_new(ctx, base, 48);
			if (uint32_t(boxMemory) != 0) {
				const uint32_t box = uint32_t(GuiMessageBox_Init(ctx, base, boxMemory, uint64_t(int64_t(TXT_83498164_G_)), uint64_t(stack) + 88, -1, 0));
				if (box != 0) {
					STORE32(stack + 96, box);
					const uint64_t controlBlock = SharedPtr_CreateControlBlock(ctx, base, uint64_t(stack) + 96);
					GUIDisplayBoxList_AddBox(ctx, base, uint64_t(boxList) + 4, controlBlock);
				}
			}
			CCharString_ReleaseAndDecGlobalCountB(ctx, base, uint64_t(stack) + 88);
		}
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 80);
		r4Out = ctx.r4.u64;
		r8Out = ctx.r8.u64;
		f13Out = ctx.f13.f64;
	}

done:
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read r4, r8 and f13 after the call
	ctx.r4.u64 = r4Out;
	ctx.r8.u64 = r8Out;
	ctx.f13.f64 = f13Out;
	return result;
}
PROMOTED_ENTRY(28, sub_8249F8A0, 0x8249F8A0) { ctx.r3.u64 = n_sub_8249F8A0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

// Lua Stats.IsTitleFreeToBuy: 1 when the title is in the free-to-buy list (m_78..m_7C), else 0.
uint64_t n_sub_8249FB20(CpuState& ctx, uint8_t* base, uint32_t statsAddr, uint32_t titleName) {
	if (!UseLiftedCode(28, 0x8249FB20)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = titleName; __imp__sub_8249FB20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249FB20);
	uint32_t stack = ctx.r1.u32;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 112);

	const uint32_t titlesEnd = stats->m_7C;
	const uint32_t titlesBegin = stats->m_78;

	// Iterators {0, begin} at +80 and {0, end} at +88, passed by value; the search writes the
	// iterator it stops at over the one at +88.
	STORE32(stack + 88, 0u);
	STORE32(stack + 80, 0u);
	STORE32(stack + 92, titlesEnd);
	STORE32(stack + 84, titlesBegin);
	const uint64_t searchBegin = LOAD64(stack + 80);
	const uint64_t searchEnd = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	StringPtrArray_FindByName(ctx, base, stack + 88, searchBegin, searchEnd, titleName);


	const uint64_t endMinusFound = uint64_t(titlesEnd) - uint64_t(LOAD32(stack + 92));
	const uint64_t leadingZeros = uint32_t(endMinusFound) == 0 ? 32 : __builtin_clz(uint32_t(endMinusFound));
	const uint32_t stoppedAtEnd = (uint32_t(leadingZeros) >> 5) & 1;
	const uint64_t isFreeToBuy = uint64_t(stoppedAtEnd) ^ 1;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r6, r7 and r8 after the call
	ctx.r6.u64 = stoppedAtEnd;
	ctx.r7.u64 = leadingZeros;
	ctx.r8.u64 = endMinusFound;
	return isFreeToBuy;
}
PROMOTED_ENTRY(28, sub_8249FB20, 0x8249FB20) { ctx.r3.u64 = n_sub_8249FB20(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// Lua Stats.SetTrackedStat: when the stats owner (m_4) is one of the players, stores the value in
// the tracked-stat array at +0x15C and, for indices up to 122 that map to a positive tracked-stat
// id, also sets it in the tracked stats.
uint64_t n_sub_824A0030(CpuState& ctx, uint8_t* base, uint32_t statsAddr, uint64_t trackedStatIndex, uint64_t statValue) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(28, 0x824A0030)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = trackedStatIndex; ctx.r5.u64 = statValue; __imp__sub_824A0030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824A0030);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 112);

	const uint32_t world = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	const uint32_t ownerEntity = stats->m_4;
	const uint32_t playersRef = LOAD32(world + 88);
	const uint32_t playersSlot = LOAD32(playersRef + 4);
	const uint32_t players = LOAD32(playersSlot);

	// State the callee may pass on.
	ctx.r1.u64 = stack;
	ctx.r5.u64 = statValue;
	ctx.r8.u64 = playersSlot;
	ctx.r9.u64 = playersRef;
	uint64_t result = Players_IsPlayer(ctx, base, players, ownerEntity);
	// r7 for the callers: the is-player byte, or what the tracked-stats update leaves there.
	uint64_t r7Out = uint32_t(result) & 0xFF;
	if (r7Out != 0) {
		STORE32(statsAddr + ((uint32_t(trackedStatIndex) + 87) << 2), uint32_t(statValue));

		if (uint32_t(trackedStatIndex) <= 122) {
			const uint64_t trackedStatId = Stats_MapTrackedStatIndex(ctx, base, trackedStatIndex);
			result = trackedStatId;
			if (int32_t(trackedStatId) > 0) {
				// State the callee may pass on.
				ctx.r3.u64 = trackedStatId;
				ctx.r7.u64 = r7Out;
				const uint64_t trackedStats = n_sub_8217E3F8(ctx, base);
				result = TrackedStats_SetValue(ctx, base, trackedStats, trackedStatId, statValue, 1);
				r7Out = ctx.r7.u64;
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r7.u64 = r7Out;   // callers read r7 after the call
	return result;
}
PROMOTED_ENTRY(28, sub_824A0030, 0x824A0030) { ctx.r3.u64 = n_sub_824A0030(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

// Lua Stats.UnlockAchievement: for ids 1-50, when the stats owner (m_4) is one of the players and
// the byte at +2091 of the world's +148 object is set, unlocks the achievement on the key-57
// component of each player entity (handles at players+104 and players+112) whose flags allow it.
uint64_t n_sub_824A0100(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint64_t achievementId) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(28, 0x824A0100)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = achievementId; __imp__sub_824A0100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824A0100);
	uint32_t stack = ctx.r1.u64;
	// xer as at entry: the component searches take their cr0.so from it.
	const PPCXERRegister entryXer = ctx.xer;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 128);

	// The world object is loaded again after each call, as the original does.
	const auto loadWorld = [&]() -> uint32_t { return LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12); };

	// Result of the key-57 component search, with the original's working registers r7-r10, cr0 and
	// xer.ca as the search leaves them (registers it does not change keep their current values).
	struct ComponentSearch {
		uint32_t component;
		uint64_t r7, r8, r9, r10;
		PPCCRRegister cr0;
		uint8_t ca;
	};
	// Finds an entity's component with key 57: through the entity's sparse index when it has one,
	// else by binary search of its sorted 8-byte {key, component} array (+72 begin, +76 end).
	// Addresses are summed in 64 bits as in the original's second search; the first truncates them.
	const auto findComponent57 = [&](uint32_t entity) -> ComponentSearch {
		// r9 still holds the tested flag bit (1).
		ComponentSearch search{0, ctx.r7.u64, ctx.r8.u64, 1, 0, ctx.cr0, ctx.xer.ca};
		const uint32_t sparseIndex = LOAD32(entity + 140);
		if (sparseIndex != 0) {
			const uint32_t offset = uint32_t(LOAD8(sparseIndex + 57)) << 3;
			search.r9 = uint64_t(offset) + LOAD32(entity + 72);   // the {key, component} pair
			search.r10 = offset;
			search.component = LOAD32(uint32_t(search.r9) + 4);
			return search;
		}
		const uint32_t begin = LOAD32(entity + 72);
		const uint32_t end = LOAD32(entity + 76);
		STORE32(stack + 80, 0u);
		const uint32_t byteCount = end - begin;
		STORE32(stack + 84, begin);
		search.ca = int32_t(byteCount) < 0 && (byteCount & 0x7) != 0;
		int32_t remaining = int32_t(byteCount) >> 3;
		search.cr0.compare<int32_t>(remaining, 0, entryXer);
		uint64_t it = begin;
		if (remaining > 0) {
			do {
				const int32_t half = remaining >> 1;
				const uint32_t step = uint32_t(half) << 3;
				const uint64_t probe = it + step;
				const bool below = int32_t(LOAD32(uint32_t(probe))) < 57;
				search.r7 = below ? 1 : 0;
				search.r8 = step;
				search.r9 = uint32_t(half);
				if (below) {
					it = probe + 8;
					remaining = remaining - half - 1;
				} else {
					remaining = half;
				}
			} while (remaining > 0);
			STORE32(stack + 84, uint32_t(it));
			search.ca = 0;   // halving a positive count leaves the carry clear
		}
		search.r10 = it;
		if (uint32_t(it) != end && int32_t(LOAD32(uint32_t(it))) <= 57) {
			STORE64(stack + 80, LOAD64(stack + 80));
			search.component = LOAD32(LOAD32(stack + 84) + 4);
		} else {
			search.component = LOAD32(end + 4);
		}
		return search;
	};

	if (int32_t(achievementId) == 0 || int32_t(achievementId) >= 51) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = achievementId;   // callers read r4 after the call
		return statsAddr;
	}

	const uint32_t ownerEntity = stats->m_4;
	uint32_t world = loadWorld();
	uint32_t playersRef = LOAD32(world + 88);
	uint32_t playersSlot = LOAD32(playersRef + 4);
	// State the callee may pass on.
	ctx.r1.u64 = stack;
	ctx.r9.u64 = playersSlot;
	ctx.r10.u64 = playersRef;
	const uint64_t isPlayerResult = Players_IsPlayer(ctx, base, LOAD32(playersSlot), ownerEntity);
	const uint32_t isPlayer = uint32_t(isPlayerResult) & 0xFF;
	if (isPlayer == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = 0;   // callers read r8 (the is-player byte) after the call
		return isPlayerResult;
	}

	world = loadWorld();
	const uint32_t unlocksAllowed = LOAD8(LOAD32(world + 148) + 2091);
	if (unlocksAllowed == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r8-r10 after the call
		ctx.r8.u64 = isPlayer;
		ctx.r9.u64 = 0;
		ctx.r10.u64 = world;
		return isPlayerResult;
	}

	const uint64_t achievementSlot = int64_t(achievementId) - 1;
	const uint64_t achievementIndex = uint32_t(achievementSlot) <= 49
		? Stats_MapAchievementIndex(ctx, base, achievementSlot)
		: uint64_t(-1);

	// First player: the handle at players+104.
	playersSlot = LOAD32(LOAD32(world + 88) + 4);
	// State the callee may pass on.
	ctx.r8.u64 = isPlayer;
	ctx.r9.u64 = unlocksAllowed;
	ctx.r10.u64 = playersSlot;
	const uint32_t firstPlayer = uint32_t(EntityHandle_Get(ctx, base, LOAD32(playersSlot)));
	if (firstPlayer != 0 && (LOAD8(firstPlayer + 144) & 64) != 0 && ((LOAD32(firstPlayer + 40) >> 25) & 1) != 0) {
		const ComponentSearch search = findComponent57(firstPlayer);
		// State the callee may pass on; this search keeps 32-bit values.
		ctx.r7.u64 = search.r7;
		ctx.r8.u64 = search.r8;
		ctx.r9.u64 = uint32_t(search.r9);
		ctx.r10.u64 = uint32_t(search.r10);
		ctx.cr0 = search.cr0;
		ctx.xer.ca = search.ca;
		Achievements_UnlockForHero(ctx, base, search.component, achievementId, achievementIndex, 0);
	}

	// Second player: the handle at players+112.
	world = loadWorld();
	playersRef = LOAD32(world + 88);
	playersSlot = LOAD32(playersRef + 4);
	// State the callee may pass on.
	ctx.r9.u64 = playersSlot;
	ctx.r10.u64 = playersRef;
	const uint64_t secondPlayerResult = SpellShot_GetOwner(ctx, base, LOAD32(playersSlot));
	const uint32_t secondPlayer = uint32_t(secondPlayerResult);
	if (secondPlayer == 0 || (LOAD8(secondPlayer + 144) & 64) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r9 (the tested flag byte, when there is a player) and r10 after the call
		if (secondPlayer != 0) ctx.r9.u64 = 0;
		ctx.r10.u64 = 0;
		return secondPlayerResult;
	}
	const uint32_t flagWord = LOAD32(secondPlayer + 40);
	if (((flagWord >> 25) & 1) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r9 and r10 after the call
		ctx.r9.u64 = 0;
		ctx.r10.u64 = flagWord;
		return 0;
	}
	const ComponentSearch search = findComponent57(secondPlayer);
	// State the callee may pass on.
	ctx.r7.u64 = search.r7;
	ctx.r8.u64 = search.r8;
	ctx.r9.u64 = search.r9;
	ctx.r10.u64 = search.r10;
	ctx.cr0 = search.cr0;
	ctx.xer.ca = search.ca;
	const uint64_t result = Achievements_UnlockForHero(ctx, base, search.component, achievementId, achievementIndex, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(28, sub_824A0100, 0x824A0100) { ctx.r3.u64 = n_sub_824A0100(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// When the owner entity (word at +4) has bit 12 of its word at +36 set, finds its component with
// key 12 (through its sparse index, else by binary search of its sorted 8-byte {key, component}
// array); if that component's word at +12 is 1, calls n_sub_82EE2040 on statsAddr+1280 with 1 and
// returns statsAddr+1280. Otherwise returns statsAddr.
uint64_t n_sub_824A5638(CpuState& ctx, uint8_t* base, uint64_t statsAddr) {
	if (!UseLiftedCode(28, 0x824A5638)) { ctx.r3.u64 = statsAddr; __imp__sub_824A5638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824A5638);
	uint32_t stack = ctx.r1.u32;
	// The original's xer.ca: the entry value, changed by the array search; handed to the callee.
	uint8_t carry = ctx.xer.ca;
	stack = PushStackFrame(base, stack, 96);

	const uint32_t entity = LOAD32(uint32_t(statsAddr) + 4);
	if (((LOAD32(entity + 36) >> 12) & 1) != 0) {
		uint32_t component;
		const uint32_t sparseIndex = LOAD32(entity + 140);
		if (sparseIndex != 0) {
			component = LOAD32((uint32_t(LOAD8(sparseIndex + 12)) << 3) + LOAD32(entity + 72) + 4);
		} else {
			const uint32_t begin = LOAD32(entity + 72);
			const uint32_t end = LOAD32(entity + 76);
			STORE32(stack + 80, 0u);
			const uint32_t byteCount = end - begin;
			STORE32(stack + 84, begin);
			carry = int32_t(byteCount) < 0 && (byteCount & 0x7) != 0;
			int32_t remaining = int32_t(byteCount) >> 3;
			uint32_t it = begin;
			if (remaining > 0) {
				do {
					const int32_t half = remaining >> 1;
					const uint32_t probe = it + (uint32_t(half) << 3);
					if (int32_t(LOAD32(probe)) < 12) {
						it = probe + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, it);
				carry = 0;   // halving a positive count leaves the carry clear
			}
			if (it != end && int32_t(LOAD32(it)) <= 12) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}

		if (int32_t(LOAD32(component + 12)) == 1) {
			const uint64_t target = statsAddr + 1280;
			// State the callee may pass on.
			ctx.r1.u64 = stack;
			ctx.xer.ca = carry;
			n_sub_82EE2040(ctx, base, target, 1);
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			ctx.r4.u64 = 1;   // callers read r4 after the call
			return target;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return statsAddr;
}
PROMOTED_ENTRY(28, sub_824A5638, 0x824A5638) { ctx.r3.u64 = n_sub_824A5638(ctx, base, ctx.r3.u64); }

// When the value is not below m_424 it becomes the new m_424; if it has also risen above m_42C by
// more than a threshold, m_42C becomes floor(value * scale) * step. Then the new m_424 goes to
// n_sub_82389100 on the owner's key-91 component when that component's byte at +107 is clear.
// When the value is below m_424, the current m_424 goes to that call instead, if the component's
// byte at +107 is set and two world flag bytes are set.
uint32_t n_sub_824A6E00(CpuState& ctx, uint8_t* base, uint32_t statsAddr, double value) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(28, 0x824A6E00)) { ctx.r3.u64 = statsAddr; ctx.f1.f64 = value; __imp__sub_824A6E00(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824A6E00);
	uint32_t stack = ctx.r1.u64;
	// The original's r6-r8, cr0 and xer.ca: the entry values, changed by the component search;
	// handed to the callee and left for the callers.
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	PPCCRRegister cr0Value = ctx.cr0;
	PPCXERRegister xerValue = ctx.xer;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.fpscr.disableFlushMode();

	// The owner's component with key 91, when the owner has bit 27 of its word at +44 set.
	uint32_t component = 0;
	const uint32_t owner = stats->m_4;
	if (((LOAD32(owner + 44) >> 27) & 1) != 0) {
		const uint32_t sparseIndex = LOAD32(owner + 140);
		if (sparseIndex != 0) {
			component = LOAD32((uint32_t(LOAD8(sparseIndex + 91)) << 3) + LOAD32(owner + 72) + 4);
		} else {
			// Binary search of the sorted 8-byte {key, component} array; r6 holds its end and r8
			// the byte count, then the step. Addresses are summed in 64 bits as in the original.
			uint64_t it = LOAD32(owner + 72);
			r6Value = LOAD32(owner + 76);
			STORE32(stack + 80, 0u);
			r8Value = r6Value - it;
			STORE32(stack + 84, uint32_t(it));
			xerValue.ca = int32_t(r8Value) < 0 && (uint32_t(r8Value) & 0x7) != 0;
			int32_t remaining = int32_t(r8Value) >> 3;
			cr0Value.compare<int32_t>(remaining, 0, xerValue);
			if (remaining > 0) {
				do {
					const int32_t half = remaining >> 1;
					r8Value = uint32_t(half) << 3;
					const uint64_t probe = it + r8Value;
					r7Value = int32_t(LOAD32(uint32_t(probe))) < 91 ? 1 : 0;
					if (r7Value != 0) {
						it = probe + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, uint32_t(it));
				xerValue.ca = 0;   // halving a positive count leaves the carry clear
			}
			uint32_t pairAddr = uint32_t(r6Value);
			if (uint32_t(it) != uint32_t(r6Value) && int32_t(LOAD32(uint32_t(it))) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				pairAddr = LOAD32(stack + 84);
			}
			component = LOAD32(pairAddr + 4);
		}
	}

	ctx.fpscr.disableFlushMode();
	// The old m_424, left in f1 for the callers unless the floor call replaces it.
	double f1Value = double(stats->m_424);
	if (!(value < f1Value)) {
		const uint32_t thresholdAddr = uint32_t(g_820A0000) - 27992;   // 0x820992A8
		const uint32_t stepAddr = thresholdAddr + 22736;              // 0x8209EB78
		const double rise = double(float(value - double(stats->m_42C)));
		stats->m_424 = float(value);
		if (rise > double(LOAD_F32(thresholdAddr))) {
			const double scaled = double(float(double(LOAD_F32(0x83319B00u)) * value));
			ctx.r1.u64 = stack;
			f1Value = floor(ctx, base, scaled);
			ctx.fpscr.disableFlushMode();
			const double floored = double(float(f1Value));
			stats->m_42C = float(floored * double(LOAD_F32(stepAddr)));
		}
		if (component != 0 && LOAD8(component + 107) == 0) {
			ctx.fpscr.disableFlushMode();
			const double newMaximum = double(stats->m_424);
			// State the callee may pass on.
			ctx.r1.u64 = stack;
			ctx.r6.u64 = r6Value;
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = r8Value;
			ctx.cr0 = cr0Value;
			ctx.xer.ca = xerValue.ca;
			const uint32_t callResult = n_sub_82389100(ctx, base, component, newMaximum);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return callResult;
		}
	} else if (component != 0 && LOAD8(component + 107) != 0) {
		const uint32_t worldFlags = LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 140);
		if (LOAD8(worldFlags + 52) != 0 && LOAD8(worldFlags + 54) != 0) {
			// State the callee may pass on.
			ctx.r1.u64 = stack;
			ctx.r6.u64 = r6Value;
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = r8Value;
			ctx.cr0 = cr0Value;
			ctx.xer.ca = xerValue.ca;
			const uint32_t callResult = n_sub_82389100(ctx, base, component, f1Value);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return callResult;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read these after the call
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.f1.f64 = f1Value;
	ctx.cr0 = cr0Value;
	ctx.xer.ca = xerValue.ca;
	return statsAddr;
}
PROMOTED_ENTRY(28, sub_824A6E00, 0x824A6E00) { ctx.r3.u64 = n_sub_824A6E00(ctx, base, ctx.r3.u32, ctx.f1.f64); }

// Scans the levels in order until one's minimum minutes exceeds the scaled m_424 and adds the
// gold-per-minute value of the last level passed to the running total in m_428; passes the whole
// part with the owner's key-81 entry data to n_sub_8239E698, keeps the fraction in m_428 and
// copies m_424 to m_42C.
uint32_t n_sub_824A6FD8(CpuState& ctx, uint8_t* base, uint32_t statsAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_820B0000 = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820B64E0_B_ = int32_t(0x820B64E0);
	constexpr int32_t str_TXT_820B650C_B_ = int32_t(0x820B650C);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_8349E164 = int32_t(0x8349E164);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(28, 0x824A6FD8)) { ctx.r3.u64 = statsAddr; __imp__sub_824A6FD8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824A6FD8);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	const PPCXERRegister entryXer = ctx.xer;
	stack = PushStackFrame(base, stack, 240);
	const uint32_t scratch = stack + 80;
	const uint64_t hashSeed = 0xFFFFFFFF811C9DC5ull;
	const uint32_t floatConstants = uint32_t(g_820A0000) - 27468;

	ctx.fpscr.disableFlushMode();
	// the starting gold per minute, and the minimum for a level that has none
	const double defaultValue = double(LOAD_F32(floatConstants));
	const double playTime = double(stats->m_424);
	const double minutesPlayed = double(float(playTime * double(LOAD_F32(floatConstants + 20056))));
	double goldPerMinute = defaultValue;

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r8.s64 = g_820B0000;
	const uint64_t levelListHash = String_HashFnv1(ctx, base, uint64_t(int64_t(g_820B0000) + 25804), hashSeed);
	const uint64_t levelList = n_sub_829FB108(ctx, base, LOAD32(uint32_t(g_83490000 + 27600)), levelListHash);
	// f13 holds m_424 for the calls below, as in the original
	ctx.f13.f64 = playTime;
	if ((uint32_t)levelList != 0) {
		// leaves the 12-byte level entries at +80, the end index at +84 and the first index at +88
		n_sub_829FBC40(ctx, base, scratch, levelList, ctx.r8.u64);
		uint32_t index = LOAD32(stack + 88);
		const uint32_t endIndex = LOAD32(stack + 84);
		const uint32_t levels = LOAD32(stack + 80);
		if (index != endIndex) {
			// r8 for the lookups as the original leaves it: 0x834A0000, then what the calls leave
			uint64_t lookupR8 = uint64_t(int64_t(g_834A0000));
			const uint32_t recordMap = LOAD32(uint32_t(g_83490000 + 27600));
			const uint32_t markerKeyAddr = uint32_t(g_8349E164);
			const uint32_t markerValue = LOAD32(uint32_t(g_834A0000) - 7848);
			do {
				// entry: type at +0, address of the record key at +8
				const uint32_t levelEntry = levels + index * 12;
				uint32_t keyAddr = LOAD32(levelEntry + 8);
				const uint32_t entryType = LOAD32(levelEntry);
				// a type-4 entry whose key is the marker value uses the key at 0x8349E164 instead
				if (entryType == 4 && LOAD32(keyAddr) == markerValue) {
					keyAddr = markerKeyAddr;
				}
				ctx.r8.u64 = lookupR8;  // state the callee may pass on
				const uint64_t record = HashMapU32_FindValue(ctx, base, recordMap, LOAD32(keyAddr));
				lookupR8 = ctx.r8.u64;
				if ((uint32_t)record != 0) {
					ctx.fpscr.disableFlushMode();
					double minMinutes = defaultValue;
					const uint64_t minMinutesHash = String_HashFnv1(ctx, base, uint64_t(int64_t(str_TXT_820B64E0_B_)), hashSeed);
					const uint32_t minMinutesAddr = n_sub_821E55C8(ctx, base, record, minMinutesHash, scratch);
					if (minMinutesAddr != 0) {
						ctx.fpscr.disableFlushMode();
						minMinutes = double(LOAD_F32(minMinutesAddr));
					}
					ctx.fpscr.disableFlushMode();
					if (minutesPlayed < minMinutes) break;
					GameDB_GetFloatByName(ctx, base, record, uint64_t(int64_t(str_TXT_820B650C_B_)));
					lookupR8 = ctx.r8.u64;
					ctx.fpscr.disableFlushMode();
					goldPerMinute = ctx.f1.f64;
				}
				index = index + 1;
			} while (index != endIndex);
		}
		HandleTarget_Free(ctx, base, levels);
	}

	// r6-r8, cr0 and xer.ca as the last call above leaves them; n_sub_8239E698 receives r8, cr0 and
	// xer.ca (after the key-81 lookup changes some) and callers read all of them after the call
	uint64_t r6State = ctx.r6.u64;
	uint64_t r7State = ctx.r7.u64;
	uint64_t r8State = ctx.r8.u64;
	PPCCRRegister cr0State = ctx.cr0;
	uint8_t caState = ctx.xer.ca;

	ctx.fpscr.disableFlushMode();
	const double pendingGold = double(float(double(stats->m_428) + goldPerMinute));
	stats->m_428 = float(pendingGold);
	const double flooredGold = floor(ctx, base, pendingGold);
	double f1State = flooredGold;
	ctx.fpscr.disableFlushMode();
	const double flooredGoldSingle = double(float(flooredGold));

	const uint32_t owner = stats->m_4;
	// presence bit of key 81
	const bool hasKey81 = ((LOAD32(owner + 44) >> 17) & 1) != 0;
	PPCRegister wholeGoldBits{};
	wholeGoldBits.s64 = std::isnan(flooredGoldSingle) ? int64_t(0x80000000U) : flooredGoldSingle > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&flooredGoldSingle));
	STORE_F64(scratch, wholeGoldBits.f64);
	const uint32_t wholeGold = LOAD32(stack + 84);

	uint32_t result = 0;
	if (hasKey81) {
		uint32_t entryData;
		const uint32_t indexMap = LOAD32(owner + 140);
		if (indexMap != 0) {
			r8State = uint64_t(uint32_t(LOAD8(indexMap + 81)) << 3) + LOAD32(owner + 72);
			entryData = LOAD32(uint32_t(r8State) + 4);
		} else {
			// lower_bound for key 81 over the owner's 8-byte (key, data) entries, sorted by key
			uint32_t first = LOAD32(owner + 72);
			const uint32_t last = LOAD32(owner + 76);
			STORE32(scratch, 0);
			STORE32(stack + 84, first);
			const uint32_t spanBytes = last - first;
			int32_t count = int32_t(spanBytes) >> 3;
			cr0State.compare<int32_t>(count, 0, entryXer);
			// the shifts in the loop leave xer.ca clear, as this one does whenever the loop runs
			caState = int32_t(spanBytes) < 0 && (spanBytes & 7) != 0;
			if (count > 0) {
				do {
					const int32_t half = count >> 1;
					const uint32_t stepBytes = uint32_t(half) << 3;
					const uint32_t mid = first + stepBytes;
					r8State = stepBytes;
					if ((int32_t)LOAD32(mid) < 81) {
						count = count - half - 1;
						first = mid + 8;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, first);
			}
			if (first != last && (int32_t)LOAD32(first) <= 81) {
				STORE64(scratch, LOAD64(scratch));
				entryData = LOAD32(first + 4);
			} else {
				entryData = LOAD32(last + 4);
			}
		}
		// state the callee may pass on
		ctx.r8.u64 = r8State;
		ctx.f1.f64 = flooredGold;
		ctx.f12 = wholeGoldBits;
		ctx.f13.f64 = flooredGoldSingle;
		ctx.cr0 = cr0State;
		ctx.xer.ca = caState;
		result = n_sub_8239E698(ctx, base, entryData, wholeGold, 1, 1, 0);
		r6State = ctx.r6.u64;
		r7State = ctx.r7.u64;
		r8State = ctx.r8.u64;
		f1State = ctx.f1.f64;
		cr0State = ctx.cr0;
		caState = ctx.xer.ca;
	}

	ctx.fpscr.disableFlushMode();
	const double accumulatedGold = double(stats->m_428);
	const double playTimeNow = double(stats->m_424);
	STORE64(scratch, (uint64_t)(int64_t)(int32_t)wholeGold);
	wholeGoldBits.f64 = LOAD_F64(scratch);
	const double wholeGoldValue = double(wholeGoldBits.s64);
	stats->m_42C = float(playTimeNow);
	stats->m_428 = float(double(float(accumulatedGold - double(float(wholeGoldValue)))));

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r6.u64 = r6State;
	ctx.r7.u64 = r7State;
	ctx.r8.u64 = r8State;
	ctx.f1.f64 = f1State;
	ctx.f11.f64 = wholeGoldValue;
	ctx.f12 = wholeGoldBits;
	ctx.f13.f64 = playTimeNow;
	ctx.cr0 = cr0State;
	ctx.xer.ca = caState;
	return result;
}
PROMOTED_ENTRY(28, sub_824A6FD8, 0x824A6FD8) { ctx.r3.u64 = n_sub_824A6FD8(ctx, base, ctx.r3.u32); }

uint64_t HeroStats_NotifyStatModified(CpuState& ctx, uint8_t* base, uint32_t statsAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(28, 0x824A72B0)) { ctx.r3.u64 = statsAddr; __imp__sub_824A72B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824A72B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	CECStats* stats = GameObject<CECStats>(base, statsAddr);

	// r6-r9, cr0 and xer.ca as the original leaves them: the caller's, then what the key searches
	// and calls below leave; the calls receive them and callers read r7, r8, cr0 and xer.ca
	uint64_t r6State = ctx.r6.u64;
	uint64_t r7State = ctx.r7.u64;
	uint64_t r8State = ctx.r8.u32;
	uint64_t r9State = 0;
	PPCCRRegister cr0State = ctx.cr0;
	uint8_t caState = ctx.xer.ca;
	const PPCXERRegister entryXer = ctx.xer;

	// lower_bound over the owner's 8-byte (key, data) entries (begin/end at +72/+76), used when it
	// has no index cache at +140; returns the key's data, or the end entry's when the key is absent
	// (r9 matters only for the last search)
	auto searchEntryData = [&](uint32_t owner, int32_t key) -> uint32_t {
		uint32_t first = LOAD32(owner + 72);
		const uint32_t last = LOAD32(owner + 76);
		r6State = last;
		STORE32(stack + 80, 0);
		STORE32(stack + 84, first);
		const uint32_t spanBytes = last - first;
		int32_t count = int32_t(spanBytes) >> 3;
		cr0State.compare<int32_t>(count, 0, entryXer);
		// the shifts in the loop leave xer.ca clear, as this one does whenever the loop runs
		caState = int32_t(spanBytes) < 0 && (spanBytes & 7) != 0;
		if (count > 0) {
			do {
				const int32_t half = count >> 1;
				const uint32_t stepBytes = uint32_t(half) << 3;
				const uint32_t mid = first + stepBytes;
				const bool below = (int32_t)LOAD32(mid) < key;
				if (below) {
					count = count - half - 1;
					first = mid + 8;
				} else {
					count = half;
				}
				r7State = below;
				r8State = stepBytes;
				r9State = uint64_t(half);
			} while (count > 0);
			STORE32(stack + 84, first);
		}
		if (first != last && (int32_t)LOAD32(first) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(first + 4);
		}
		return LOAD32(last + 4);
	};

	// key 116 (presence bit 20 of the word at +48)
	uint32_t owner = stats->m_4;
	if (((LOAD32(owner + 48) >> 20) & 1) != 0) {
		const uint32_t cache = LOAD32(owner + 140);
		const uint32_t key116Data = cache != 0
			? LOAD32(LOAD32(owner + 72) + (uint32_t(LOAD8(cache + 116)) << 3) + 4)
			: searchEntryData(owner, 116);
		STORE8(key116Data + 16, 1);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6State;
		ctx.r7.u64 = r7State;
		ctx.r8.u64 = r8State;
		ctx.cr0 = cr0State;
		ctx.xer.ca = caState;
		HeroStats_PublishStatsSnapshot(ctx, base, key116Data, 1);
		r6State = ctx.r6.u64;
		r7State = ctx.r7.u64;
		cr0State = ctx.cr0;
		caState = ctx.xer.ca;
	}

	// key 15 (presence bit 15 of the word at +36; the original leaves the bit in r8)
	owner = stats->m_4;
	r8State = (LOAD32(owner + 36) >> 15) & 1;
	if (r8State != 0) {
		uint32_t key15Data;
		const uint32_t cache = LOAD32(owner + 140);
		if (cache != 0) {
			r8State = uint64_t(uint32_t(LOAD8(cache + 15)) << 3) + LOAD32(owner + 72);
			key15Data = LOAD32(uint32_t(r8State) + 4);
		} else {
			key15Data = searchEntryData(owner, 15);
		}
		const uint32_t statClockAddr = uint32_t(g_83320000) - 27380;
		STORE32(key15Data + 100, LOAD32(statClockAddr));
		STORE32(key15Data + 104, LOAD32(statClockAddr));
	}

	// key 21 (presence bit 21 of the word at +36; the original leaves the bit in r9)
	uint64_t result = 0;
	owner = stats->m_4;
	r9State = (LOAD32(owner + 36) >> 21) & 1;
	if (r9State != 0) {
		uint32_t key21Data;
		const uint32_t cache = LOAD32(owner + 140);
		if (cache != 0) {
			r9State = LOAD8(cache + 21);
			r8State = uint64_t(uint32_t(r9State) << 3) + LOAD32(owner + 72);
			key21Data = LOAD32(uint32_t(r8State) + 4);
		} else {
			key21Data = searchEntryData(owner, 21);
		}
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6State;
		ctx.r7.u64 = r7State;
		ctx.r8.u64 = r8State;
		ctx.r9.u64 = r9State;
		ctx.cr0 = cr0State;
		ctx.xer.ca = caState;
		result = n_sub_823F23B0(ctx, base, key21Data);
		r7State = ctx.r7.u64;
		r8State = ctx.r8.u64;
		cr0State = ctx.cr0;
		caState = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r7, r8, cr0 and xer.ca after the call
	ctx.r7.u64 = r7State;
	ctx.r8.u64 = r8State;
	ctx.cr0 = cr0State;
	ctx.xer.ca = caState;
	return result;
}
PROMOTED_ENTRY(28, sub_824A72B0, 0x824A72B0) { ctx.r3.u64 = HeroStats_NotifyStatModified(ctx, base, ctx.r3.u32); }

// For a player owner: stores the level (2 down to 0, -1 for none) reached by the summed xp floats at
// +420 of the owner's key-56 entry and, when it changed and the key-91 network check allows it,
// calls n_sub_821B5478 with 238.
uint64_t Stats_RecomputeMagicXPLevel(CpuState& ctx, uint8_t* base, uint64_t statsAddr) {
	constexpr uint32_t levelThresholds = 0x83319238;
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(28, 0x824A7648)) { ctx.r3.u64 = statsAddr; __imp__sub_824A7648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824A7648);
	uint32_t stack = ctx.r1.u64;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 144);
	const uint32_t globals = uint32_t(g_83490000);
	const uint32_t owner = stats->m_4;

	// r4-r8, f6-f13 and xer.ca as the original leaves them: the caller's, then what Players_IsPlayer
	// and the code below leave; n_sub_821B5478 receives r5-r8, f6-f13 and xer.ca, and callers read
	// r4-r7, f6-f13 and xer.ca after the call
	uint64_t r4State = owner;
	uint64_t r5State = ctx.r5.u64;
	uint64_t r6State = ctx.r6.u64;
	uint64_t r7State = ctx.r7.u64;
	uint64_t r8State = 0;
	double f6State = ctx.f6.f64;
	double f7State = ctx.f7.f64;
	double f8State = ctx.f8.f64;
	double f9State = ctx.f9.f64;
	double f10State = ctx.f10.f64;
	double f11State = ctx.f11.f64;
	double f12State = ctx.f12.f64;
	double f13State = ctx.f13.f64;
	uint8_t caState = ctx.xer.ca;

	// after Players_IsPlayer and n_sub_821B5478 the original keeps what they leave in r4-r7,
	// f6-f13 and xer.ca
	auto keepCalleeRegisters = [&]() {
		r4State = ctx.r4.u64;
		r5State = ctx.r5.u64;
		r6State = ctx.r6.u64;
		r7State = ctx.r7.u64;
		f6State = ctx.f6.f64;
		f7State = ctx.f7.f64;
		f8State = ctx.f8.f64;
		f9State = ctx.f9.f64;
		f10State = ctx.f10.f64;
		f11State = ctx.f11.f64;
		f12State = ctx.f12.f64;
		f13State = ctx.f13.f64;
		caState = ctx.xer.ca;
	};

	// lower_bound over an entity's 8-byte (key, data) entries (begin/end at +72/+76), used when it
	// has no index cache at +140; returns the key's data, or the end entry's when the key is absent
	auto searchEntryData = [&](uint32_t entity, int32_t key) -> uint32_t {
		uint32_t first = LOAD32(entity + 72);
		const uint32_t last = LOAD32(entity + 76);
		r6State = last;
		STORE32(stack + 80, 0);
		STORE32(stack + 84, first);
		const uint32_t spanBytes = last - first;
		int32_t count = int32_t(spanBytes) >> 3;
		// the shifts in the loop leave xer.ca clear, as this one does whenever the loop runs
		caState = int32_t(spanBytes) < 0 && (spanBytes & 7) != 0;
		if (count > 0) {
			do {
				const int32_t half = count >> 1;
				const uint32_t stepBytes = uint32_t(half) << 3;
				const uint32_t mid = first + stepBytes;
				const bool below = (int32_t)LOAD32(mid) < key;
				if (below) {
					count = count - half - 1;
					first = mid + 8;
				} else {
					count = half;
				}
				r7State = below;
				r8State = stepBytes;
			} while (count > 0);
			STORE32(stack + 84, first);
		}
		if (first != last && (int32_t)LOAD32(first) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(first + 4);
		}
		return LOAD32(last + 4);
	};

	uint64_t result = 0;
	if (owner != 0 && (LOAD8(owner + 144) & 0x40) != 0) {
		const uint32_t players = LOAD32(LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 88) + 4);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r9.u64 = players;
		result = Players_IsPlayer(ctx, base, LOAD32(players), owner);
		keepCalleeRegisters();
	}

	if (((uint32_t)result & 0xFF) != 0) {
		const uint32_t entity = stats->m_4;
		r4State = 0;
		// key 56 (presence bit 24 of the word at +40)
		if ((LOAD8(entity + 40) & 1) != 0) {
			uint32_t magicComponent;
			const uint32_t cache = LOAD32(entity + 140);
			if (cache != 0) {
				magicComponent = LOAD32(LOAD32(entity + 72) + (uint32_t(LOAD8(cache + 56)) << 3) + 4);
			} else {
				magicComponent = searchEntryData(entity, 56);
			}

			// total xp: 8 groups, group g with a count at +300 + 4*g and its floats from +1072 + 20*g
			ctx.fpscr.disableFlushMode();
			const double baseThreshold = double(LOAD_F32(0x820994B4u));
			f12State = baseThreshold;
			double totalXp = baseThreshold;
			uint64_t groupValues = statsAddr + 1076;  // one past the group's first float
			uint32_t groupCountAddr = uint32_t(statsAddr) + 300;
			for (int group = 0; group < 8; group++) {
				const uint32_t count = LOAD32(groupCountAddr);
				uint32_t summed = 0;
				if ((int32_t)count >= 4) {
					// four floats per step
					uint32_t steps = ((count - 4) >> 2) + 1;
					summed = steps << 2;
					uint32_t value = uint32_t(groupValues);
					do {
						ctx.fpscr.disableFlushMode();
						const double x0 = double(LOAD_F32(value - 4));
						caState = steps != 0;
						steps = steps - 1;
						const double sum0 = double(float(x0 + totalXp));
						const double x1 = double(LOAD_F32(value));
						const double x2 = double(LOAD_F32(value + 4));
						const double x3 = double(LOAD_F32(value + 8));
						value = value + 16;
						const double sum1 = double(float(sum0 + x1));
						const double sum2 = double(float(sum1 + x2));
						totalXp = double(float(sum2 + x3));
						// the original leaves these in f6-f11 and f13
						f6State = sum2;
						f7State = sum1;
						f8State = x3;
						f9State = x2;
						f10State = x1;
						f11State = sum0;
						f13State = x0;
					} while (steps != 0);
				}
				if ((int32_t)summed < (int32_t)count) {
					uint32_t left = count - summed;
					uint32_t value = uint32_t(groupValues) - 4 + (summed << 2);
					do {
						ctx.fpscr.disableFlushMode();
						const double x = double(LOAD_F32(value));
						caState = left != 0;
						left = left - 1;
						totalXp = double(float(x + totalXp));
						value = value + 4;
						f13State = x;
					} while (left != 0);
				}
				groupCountAddr = groupCountAddr + 4;
				groupValues = groupValues + 20;
			}
			r6State = groupValues;

			// highest level, 2 down to 0, whose threshold the total reaches; -1 when none
			// (the original leaves the table flag in r7 and r8 and the last threshold in f13)
			const uint32_t thresholdsLoaded = LOAD8(globals + 27102);
			r8State = thresholdsLoaded;
			uint32_t newMagicLevel = 0xFFFFFFFF;
			for (int32_t level = 2; level >= 0; level--) {
				ctx.fpscr.disableFlushMode();
				double threshold = baseThreshold;
				r7State = thresholdsLoaded;
				if (thresholdsLoaded != 0) {
					ctx.fpscr.disableFlushMode();
					threshold = double(LOAD_F32(uint32_t(level) * 44 + levelThresholds));
				}
				ctx.fpscr.disableFlushMode();
				f13State = threshold;
				if (!(totalXp < threshold)) {
					newMagicLevel = uint32_t(level);
					break;
				}
				caState = level != 0;
			}
			const uint32_t oldMagicLevel = LOAD32(magicComponent + 420);
			STORE32(magicComponent + 420, newMagicLevel);

			const uint32_t globalState = LOAD32(LOAD32(globals + 26912) + 12);
			r4State = globalState;
			bool notifyLevelChange = true;
			if ((int32_t)LOAD32(globalState + 284) == 1) {
				const uint32_t networkEntity = stats->m_4;
				result = 0;
				// key 91 (presence bit 27 of the word at +44)
				if (((LOAD32(networkEntity + 44) >> 27) & 1) != 0) {
					uint32_t networkComponent;
					const uint32_t networkCache = LOAD32(networkEntity + 140);
					if (networkCache != 0) {
						r8State = uint64_t(uint32_t(LOAD8(networkCache + 91)) << 3) + LOAD32(networkEntity + 72);
						networkComponent = LOAD32(uint32_t(r8State) + 4);
					} else {
						networkComponent = searchEntryData(networkEntity, 91);
					}
					// the original returns the component unless a call below replaces it
					result = networkComponent;
					notifyLevelChange = false;
					if (LOAD8(networkComponent + 107) == 0) {
						// state the callee may pass on
						ctx.r1.u64 = stack;
						ctx.xer.ca = caState;
						result = CECNetwork_ShouldReplicateEntity(ctx, base, networkComponent);
						notifyLevelChange = ((uint32_t)result & 0xFF) != 0;
					}
				}
			}
			r5State = notifyLevelChange;
			if (notifyLevelChange && (int32_t)oldMagicLevel != (int32_t)newMagicLevel) {
				const uint32_t notifyTarget = LOAD32(LOAD32(globalState + 168) + 4);
				// state the callee may pass on
				ctx.r1.u64 = stack;
				ctx.r5.u64 = r5State;
				ctx.r6.u64 = r6State;
				ctx.r7.u64 = r7State;
				ctx.r8.u64 = r8State;
				ctx.f6.f64 = f6State;
				ctx.f7.f64 = f7State;
				ctx.f8.f64 = f8State;
				ctx.f9.f64 = f9State;
				ctx.f10.f64 = f10State;
				ctx.f11.f64 = f11State;
				ctx.f12.f64 = f12State;
				ctx.f13.f64 = f13State;
				ctx.xer.ca = caState;
				result = n_sub_821B5478(ctx, base, notifyTarget, 238);
				keepCalleeRegisters();
			}
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = r4State;
	ctx.r5.u64 = r5State;
	ctx.r6.u64 = r6State;
	ctx.r7.u64 = r7State;
	ctx.f6.f64 = f6State;
	ctx.f7.f64 = f7State;
	ctx.f8.f64 = f8State;
	ctx.f9.f64 = f9State;
	ctx.f10.f64 = f10State;
	ctx.f11.f64 = f11State;
	ctx.f12.f64 = f12State;
	ctx.f13.f64 = f13State;
	ctx.xer.ca = caState;
	return result;
}
PROMOTED_ENTRY(28, sub_824A7648, 0x824A7648) { ctx.r3.u64 = Stats_RecomputeMagicXPLevel(ctx, base, ctx.r3.u64); }

// Integer stat value: the key's float in the map at +132 truncated to an integer (0 when absent),
// plus the key's float at +20 in the map at +156 when that entry's flag byte at +16 is set,
// truncated again.
uint64_t CECStats_GetStatValue_824A8250(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint32_t statKey) {
	if (!UseLiftedCode(28, 0x824A8250)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = statKey; __imp__sub_824A8250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824A8250);
	uint32_t stack = ctx.r1.u32;
	// callers read f13 after the call: the caller's value unless a conversion below replaces it
	PPCRegister f13State = ctx.f13;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 128);

	// the key and the (map, node) pair a lookup returns live on the game stack
	const uint32_t keyAddr = stack + 156;
	const uint32_t findResult = stack + 80;
	const uint32_t firstMap = uint32_t(statsAddr + 132);
	const uint64_t secondMap = statsAddr + 156;
	STORE32(keyAddr, statKey);

	uint32_t total = 0;
	ctx.r1.u64 = stack;
	RbTreeIntMap_Find_Flag21(ctx, base, findResult, firstMap, keyAddr);
	uint32_t map = LOAD32(findResult);
	// m_88 is the first map's head node: a node equal to it means the key is absent
	const uint32_t firstHead = stats->m_88;
	if (map == 0 || map != firstMap) {
		ppc_trap(ctx, base, 22);
	}
	uint32_t node = LOAD32(findResult + 4);
	if (node != firstHead) {
		if (map == 0) {
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(map + 4)) {
			ppc_trap(ctx, base, 22);
		}
		ctx.fpscr.disableFlushMode();
		const double firstValue = double(LOAD_F32(node + 16));
		f13State.s64 = std::isnan(firstValue) ? int64_t(0x80000000U) : firstValue > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&firstValue));
		STORE_F64(findResult, f13State.f64);
		total = LOAD32(stack + 84);
	}

	RbTreeIntMap_Find(ctx, base, findResult, uint32_t(secondMap), keyAddr);
	map = LOAD32(findResult);
	// m_A0 is the second map's head node
	const uint32_t secondHead = stats->m_A0;
	if (map == 0 || map != uint32_t(secondMap)) {
		ppc_trap(ctx, base, 22);
	}
	node = LOAD32(findResult + 4);
	if (node != secondHead) {
		if (map == 0) {
			ppc_trap(ctx, base, 22);
		}
		const uint32_t head = LOAD32(map + 4);
		if (node == head) {
			ppc_trap(ctx, base, 22);
		}
		if (LOAD8(node + 16) != 0) {
			if (node == head) {
				ppc_trap(ctx, base, 22);
			}
			ctx.fpscr.disableFlushMode();
			const double secondValue = double(LOAD_F32(node + 20));
			STORE64(findResult, (uint64_t)(int64_t)(int32_t)total);
			f13State.f64 = LOAD_F64(findResult);
			const double totalValue = double(f13State.s64);
			const double totalSingle = double(float(totalValue));
			const double sum = double(float(secondValue + totalSingle));
			PPCRegister sumBits{};
			sumBits.s64 = std::isnan(sum) ? int64_t(0x80000000U) : sum > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&sum));
			STORE_F64(findResult, sumBits.f64);
			const uint32_t result = LOAD32(stack + 84);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			// callers read r4 and f9-f13 after the call
			ctx.r4.u64 = secondMap;
			ctx.f9 = sumBits;
			ctx.f10.f64 = sum;
			ctx.f11.f64 = totalSingle;
			ctx.f12.f64 = totalValue;
			ctx.f13 = f13State;
			return result;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 and f13 after the call
	ctx.r4.u64 = secondMap;
	ctx.f13 = f13State;
	return total;
}
PROMOTED_ENTRY(28, sub_824A8250, 0x824A8250) { ctx.r3.u64 = CECStats_GetStatValue_824A8250(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// Returns in f1 the key's float in the map at +132 (the constant at 0x820994B4 when absent), plus the
// key's float at +20 in the map at +156 when that entry's flag byte at +16 is set; r3 gets the stack
// address of the lookup result, as in the original.
uint32_t CECStats_GetStatValue(CpuState& ctx, uint8_t* base, uint32_t statsAddr, uint32_t statKey) {
	if (!UseLiftedCode(28, 0x824A8380)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = statKey; __imp__sub_824A8380(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824A8380);
	uint32_t stack = ctx.r1.u32;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 128);

	// the key and the (map, node) pair a lookup returns live on the game stack
	const uint32_t keyAddr = stack + 156;
	const uint32_t findResult = stack + 80;
	const uint32_t firstMap = statsAddr + 132;
	const uint32_t secondMap = statsAddr + 156;
	STORE32(keyAddr, statKey);

	double value = double(LOAD_F32(0x820994B4u));
	ctx.r1.u64 = stack;
	RbTreeIntMap_Find_Flag21(ctx, base, findResult, firstMap, keyAddr);
	uint32_t map = LOAD32(findResult);
	// m_88 is the first map's head node: a node equal to it means the key is absent
	const uint32_t firstHead = stats->m_88;
	if (map == 0 || map != firstMap) {
		ppc_trap(ctx, base, 22);
	}
	uint32_t node = LOAD32(findResult + 4);
	if (node != firstHead) {
		if (map == 0) {
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(map + 4)) {
			ppc_trap(ctx, base, 22);
		}
		ctx.fpscr.disableFlushMode();
		value = double(LOAD_F32(node + 16));
	}

	RbTreeIntMap_Find(ctx, base, findResult, secondMap, keyAddr);
	map = LOAD32(findResult);
	// m_A0 is the second map's head node
	const uint32_t secondHead = stats->m_A0;
	if (map == 0 || map != secondMap) {
		ppc_trap(ctx, base, 22);
	}
	node = LOAD32(findResult + 4);
	bool addsSecondValue = false;
	if (node != secondHead) {
		if (map == 0) {
			ppc_trap(ctx, base, 22);
		}
		const uint32_t head = LOAD32(map + 4);
		if (node == head) {
			ppc_trap(ctx, base, 22);
		}
		if (LOAD8(node + 16) != 0) {
			if (node == head) {
				ppc_trap(ctx, base, 22);
			}
			addsSecondValue = true;
		}
	}
	ctx.fpscr.disableFlushMode();
	const double result = addsSecondValue ? double(float(double(LOAD_F32(node + 20)) + value)) : value;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read the value from f1
	ctx.f1.f64 = result;
	return findResult;
}
PROMOTED_ENTRY(28, sub_824A8380, 0x824A8380) { ctx.r3.u64 = CECStats_GetStatValue(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t CECStats_ClearBonus(CpuState& ctx, uint8_t* base, uint32_t statsAddr, uint32_t bonusType, double amount) {
	constexpr int32_t g_824B0000 = int32_t(0x824B0000);
	if (!UseLiftedCode(28, 0x824A9080)) { ctx.r3.u64 = statsAddr; ctx.r4.u64 = bonusType; ctx.f1.f64 = amount; __imp__sub_824A9080(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824A9080);
	uint32_t stack = ctx.r1.u64;
	// Registers the compiled code leaves for callers (and hands to the callee in
	// case 0); the record lookup below updates r8, cr0 and xer.ca.
	uint64_t r0Value = ctx.r0.u64;
	uint64_t r8Value = ctx.r8.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	uint32_t result = statsAddr;
	stack = PushStackFrame(base, stack, 96);

	// Looks up the record for `key` in the stats data's sorted array of 8-byte
	// (key, record) entries: an index table, when present, gives the entry
	// directly, otherwise a binary search finds it. Case 3's compiled code keeps
	// the indexed entry's address in r8.
	auto findStatRecord = [&](uint32_t statsData, int32_t key, bool indexedEntryInR8) -> uint32_t {
		uint32_t indexTable = LOAD32(statsData + 0x8C);
		if (indexTable != 0) {
			uint32_t index = LOAD8(indexTable + key);
			uint64_t entry = (uint64_t)(index << 3) + LOAD32(statsData + 0x48);
			if (indexedEntryInR8) {
				r8Value = entry;
			}
			return LOAD32((uint32_t)entry + 4);
		}
		uint32_t first = LOAD32(statsData + 0x48);
		uint32_t last = LOAD32(statsData + 0x4C);
		STORE32(stack + 80, 0u);
		uint32_t byteSpan = last - first;
		STORE32(stack + 84, first);
		flags.ca = (int32_t)byteSpan < 0 & (byteSpan & 0x7) != 0;
		int32_t count = (int32_t)byteSpan >> 3;
		compare0.compare<int32_t>(count, 0, flags);
		uint32_t entry = first;
		if (count > 0) {
			do {
				int32_t half = count >> 1;
				uint32_t offset = (uint32_t)half << 3;
				r8Value = offset;
				uint32_t mid = entry + offset;
				if ((int32_t)LOAD32(mid) < key) {
					entry = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			flags.ca = 0;  // shifting a positive count right leaves no carry
			STORE32(stack + 84, entry);
		}
		if (entry != last && (int32_t)LOAD32(entry) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(last + 4);
	};

	if (bonusType <= 3) {
		// r0 keeps the jump-table entry the compiled switch loads
		r0Value = LOAD32(uint32_t(g_824B0000 - 28500) + bonusType * 4);
	}
	switch (bonusType) {
	case 0: {
		uint32_t statsData = LOAD32(statsAddr + 4);
		result = 0;
		if ((LOAD32(statsData + 0x28) >> 4) & 1) {
			uint32_t record = findStatRecord(statsData, 36, false);
			ctx.fpscr.disableFlushMode();
			double reducedValue = double(float(double(LOAD_F32(record + 0x1C)) - amount));
			// state the callee may pass on
			ctx.r0.u64 = r0Value;
			ctx.r1.u64 = stack;
			ctx.r8.u64 = r8Value;
			ctx.cr0.lt = compare0.lt;
			ctx.cr0.gt = compare0.gt;
			ctx.cr0.eq = compare0.eq;
			ctx.cr0.so = compare0.so;
			ctx.xer.ca = flags.ca;
			result = n_sub_8268F5B8(ctx, base, record, reducedValue);  // Lua_Health_SetMax
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return result;
		}
		break;
	}
	case 1:
		STORE32(statsAddr + 0x10C, 0u);
		break;
	case 2: {
		uint32_t statsData = LOAD32(statsAddr + 4);
		result = 0;
		uint32_t hasStat = (LOAD32(statsData + 0x2C) >> 29) & 1;
		r8Value = hasStat;
		if (hasStat != 0) {
			uint32_t record = findStatRecord(statsData, 93, false);
			uint32_t currentValue = LOAD32(record + 0x14);
			ctx.fpscr.disableFlushMode();
			PPCRegister converted{};
			converted.s64 = std::isnan(amount) ? int64_t(0x80000000U) : amount > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&amount));
			STORE_F64(stack + 80, converted.f64);
			uint32_t delta = LOAD32(stack + 84);
			r8Value = delta;
			uint32_t newValue = currentValue - delta;
			if ((int32_t)newValue != (int32_t)currentValue) {
				STORE32(record + 0x14, newValue);
				r8Value = newValue;
				// Branch-free clamp of the new value: below at 0, above at the
				// value at +0x18.
				uint32_t clampedAtZero = newValue - ((uint32_t)((int32_t)newValue >> 31) & newValue);
				uint32_t headroom = LOAD32(record + 0x18) - clampedAtZero;
				flags.ca = (int32_t)headroom < 0 & (headroom & 0x7FFFFFFF) != 0;
				result = ((uint32_t)((int32_t)headroom >> 31) & headroom) + clampedAtZero;
				STORE32(record + 0x14, result);
				STORE32(record + 0x28, LOAD32(record + 0x24));
			}
		}
		break;
	}
	case 3: {
		uint32_t statsData = LOAD32(statsAddr + 4);
		result = 0;
		uint32_t hasStat = (LOAD32(statsData + 0x2C) >> 29) & 1;
		r8Value = hasStat;
		if (hasStat != 0) {
			uint32_t record = findStatRecord(statsData, 93, true);
			STORE32(record + 0x1C, 1u);
		}
		break;
	}
	default:
		break;
	}

	stack = PopStackFrame(stack, 96);
	// callers may read these registers after the call
	ctx.r0.u64 = r0Value;
	ctx.r1.u64 = stack;
	ctx.r8.u64 = r8Value;
	ctx.f1.f64 = amount;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(28, sub_824A9080, 0x824A9080) { ctx.r3.u64 = CECStats_ClearBonus(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.f1.f64); }

uint64_t n_sub_824A94B0(CpuState& ctx, uint8_t* base, uint64_t stats, uint64_t abilityIndex, uint64_t incomingR8) {
	if (!UseLiftedCode(28, 0x824A94B0)) { ctx.r3.u64 = stats; ctx.r4.u64 = abilityIndex; ctx.r8.u64 = incomingR8; __imp__sub_824A94B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824A94B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t abilityKey = stack + 80;

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = stats;
	ctx.r8.u64 = incomingR8;
	Stats_GetAbilityBaseKeyByIndex(ctx, base, abilityKey, abilityIndex);

	if (LOAD32(stack + 80) != 0) {
		uint64_t idRef = IdRef_Get(ctx, base, abilityKey);
		uint64_t fieldValue = GameDB_ReadU32Field(ctx, base, idRef, (uint64_t)(int64_t)-2113182264);
		if ((uint32_t)fieldValue != 0) {
			n_sub_829FBC40(ctx, base, abilityKey, fieldValue, ctx.r8.u64);
			HandleTarget_Free(ctx, base, LOAD32(stack + 80));
			uint32_t maximumLevel = LOAD32(stack + 84);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return maximumLevel;
		}
		// callers read r4 after the call
		ctx.r4.u64 = fieldValue;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(28, sub_824A94B0, 0x824A94B0) { ctx.r3.u64 = n_sub_824A94B0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t Stats_CheckCompletionistAchievement(CpuState& ctx, uint8_t* base, uint64_t statsAddr, uint64_t incomingR8) {
	constexpr int32_t str_TXT_820B6AB8_B_ = int32_t(0x820B6AB8);
	if (!UseLiftedCode(28, 0x824AC560)) { ctx.r3.u64 = statsAddr; ctx.r8.u64 = incomingR8; __imp__sub_824AC560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824AC560);
	uint32_t stack = ctx.r1.u64;
	// r8, cr0 and xer.ca as callers see them after the call
	uint64_t r8Value = incomingR8;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	CECStats* stats = GameObject<CECStats>(base, statsAddr);
	stack = PushStackFrame(base, stack, 144);

	uint64_t result = statsAddr;
	if (LOAD8((uint32_t)statsAddr + 994) != 0) {
		// Stops unless abilities 1..14 have all reached their maximum level
		// (their levels are stored from +276 on).
		uint64_t abilityIndex = 1;
		uint32_t abilityLevelAddr = (uint32_t)statsAddr + 276;
		do {
			ctx.r1.u64 = stack;
			result = n_sub_824A94B0(ctx, base, statsAddr, abilityIndex, r8Value);  // Lua_Stats_GetHeroAbilityMaximumLevel
			r8Value = ctx.r8.u64;
			compare0.lt = ctx.cr0.lt;
			compare0.gt = ctx.cr0.gt;
			compare0.eq = ctx.cr0.eq;
			compare0.so = ctx.cr0.so;
			flags.ca = ctx.xer.ca;
			if ((int32_t)LOAD32(abilityLevelAddr) < (int32_t)result) goto finished;
			++abilityIndex;
			abilityLevelAddr += 4;
		} while (abilityIndex < 15);

		// Looks up the record for key 154 in the stats data's sorted array of
		// 8-byte (key, record) entries: an index table, when present, gives the
		// entry directly, otherwise a binary search finds it.
		uint64_t r6Value = ctx.r6.u64;  // r6 as the last call left it
		uint32_t statsData = stats->m_4;
		if (((LOAD32(statsData + 52) >> 26) & 1) == 0) goto finished;
		uint32_t record;
		uint32_t indexTable = LOAD32(statsData + 140);
		if (indexTable != 0) {
			uint32_t entryOffset = LOAD8(indexTable + 154) << 3;
			record = LOAD32(entryOffset + LOAD32(statsData + 72) + 4);
		} else {
			uint32_t first = LOAD32(statsData + 72);
			uint32_t last = LOAD32(statsData + 76);
			STORE32(stack + 80, 0u);
			r8Value = (uint64_t)last - first;
			STORE32(stack + 84, first);
			flags.ca = (int32_t)r8Value < 0 & ((uint32_t)r8Value & 0x7) != 0;
			int32_t count = (int32_t)r8Value >> 3;
			compare0.compare<int32_t>(count, 0, flags);
			uint32_t entry = first;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t offset = (uint32_t)half << 3;
					r8Value = offset;
					uint32_t mid = entry + offset;
					if ((int32_t)LOAD32(mid) < 154) {
						entry = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				flags.ca = 0;  // shifting a positive count right leaves no carry
				STORE32(stack + 84, entry);
			}
			if (entry != last && (int32_t)LOAD32(entry) <= 154) {
				STORE64(stack + 80, LOAD64(stack + 80));
				record = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				record = LOAD32(last + 4);
			}
			r6Value = last;
		}

		uint64_t balancingKey = (uint64_t)stack + 80;  // a CCharString on the stack
		// state the callee may pass on
		ctx.r6.u64 = r6Value;
		ctx.r8.u64 = r8Value;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		CCharString_ConstructFromCStr(ctx, base, balancingKey, str_TXT_820B6AB8_B_, -1);

		uint32_t rangeStart = LOAD32(record + 136);
		uint32_t rangeEnd = LOAD32(record + 140);
		int32_t stepCount = (int32_t)(rangeEnd - rangeStart) / 20;
		STORE64(stack + 88, (uint64_t)(int64_t)stepCount);
		ctx.fpscr.disableFlushMode();
		PPCRegister stepCountBits{};
		stepCountBits.f64 = LOAD_F64(stack + 88);
		double stepCountDouble = double(stepCountBits.s64);
		double stepCountSingle = double(float(stepCountDouble));
		// state the callee may pass on
		ctx.r6.u64 = (uint32_t)stepCount;
		ctx.r8.u64 = rangeStart;
		ctx.f13.f64 = stepCountDouble;
		Achievements_GetBalancingValue(ctx, base, balancingKey);
		double requiredCount = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		bool belowRequired = stepCountSingle < requiredCount;
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, balancingKey);
		r8Value = ctx.r8.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
		if (belowRequired) goto finished;
		result = n_sub_824A0100(ctx, base, statsAddr, 12);  // Lua_Stats_UnlockAchievement
		r8Value = ctx.r8.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
	}
finished:
	stack = PopStackFrame(stack, 144);
	// callers read these registers after the call
	ctx.r1.u64 = stack;
	ctx.r8.u64 = r8Value;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(28, sub_824AC560, 0x824AC560) { ctx.r3.u64 = Stats_CheckCompletionistAchievement(ctx, base, ctx.r3.u64, ctx.r8.u64); }
