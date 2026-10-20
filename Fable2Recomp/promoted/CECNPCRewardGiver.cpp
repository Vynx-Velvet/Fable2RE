

// CECNPCRewardGiver (vtable 0x82004760): methods of the class as readable C++.
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

// Returns 1 when m_20 is set, the global state reached from 0x83496920 has byte +75 clear and +73 set,
// and an entry of the list at +12 whose object has byte +13 clear answers nonzero from vtable slot 2.
uint64_t CECNPCRewardGiver_HasAvailableReward(CpuState& ctx, uint8_t* base, uint32_t nPCRewardGiverAddr) {
	if (!UseLiftedCode(3, 0x821C74E8)) { ctx.r3.u64 = nPCRewardGiverAddr; __imp__sub_821C74E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821C74E8);
	uint32_t stack = ctx.r1.u64;
	// r7-r10 are handed to the virtual calls below and back to the caller at the return.
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = ctx.r9.u64;
	uint32_t reg10 = ctx.r10.u32;
	PPCRegister callTarget{};
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t hasReward = 0;
	if (nPCRewardGiver->m_20 != 0) {
		uint32_t manager = LOAD32(0x83496920);
		reg10 = LOAD32(manager + 12);
		reg9 = LOAD32(reg10 + 88);
		reg8 = LOAD32((uint32_t)reg9 + 4);
		uint32_t rewardState = LOAD32((uint32_t)reg8 + 104);
		reg7 = LOAD8(rewardState + 75);
		bool rewardsActive = ((uint32_t)reg7 == 0) && (LOAD8(rewardState + 73) != 0);
		if (rewardsActive) {
			// The list head (m_10) is re-read on every step: the virtual call may change it.
			uint32_t entry = LOAD32(nPCRewardGiver->m_10);
			while (entry != nPCRewardGiver->m_10) {
				uint32_t TXT_820B36C0_L_ = LOAD32(entry + 8);
				if (LOAD8(TXT_820B36C0_L_ + 13) == 0) {
					uint32_t isAvailableFn = LOAD32(LOAD32(TXT_820B36C0_L_) + 8);
					callTarget.u64 = isAvailableFn;
					ctx.r1.u64 = stack;
					ctx.r3.u64 = TXT_820B36C0_L_;
					ctx.r7.u64 = reg7;
					ctx.r8.u64 = reg8;
					ctx.r9.u64 = reg9;
					ctx.r10.u64 = isAvailableFn;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					reg7 = ctx.r7.u64;
					reg8 = ctx.r8.u64;
					reg10 = ctx.r10.u32;
					reg9 = ctx.r3.u32 & 0xFF;
					if ((uint32_t)reg9 != 0) {
						hasReward = 1;
						break;
					}
				}
				// iterator check of the original: stepping from the list head traps
				if (entry == nPCRewardGiver->m_10) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				entry = LOAD32(entry);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r7-r10 after the call
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = reg9;
	ctx.r10.u64 = reg10;
	return hasReward;
}
PROMOTED_ENTRY(3, sub_821C74E8, 0x821C74E8) { ctx.r3.u64 = CECNPCRewardGiver_HasAvailableReward(ctx, base, ctx.r3.u32); }

uint32_t CECNPCRewardGiver_CanGiveReward(CpuState& ctx, uint8_t* base, uint32_t nPCRewardGiverAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(3, 0x821C75E0)) { ctx.r3.u64 = nPCRewardGiverAddr; __imp__sub_821C75E0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821C75E0);
	uint32_t stack = ctx.r1.u64;
	// r6-r8 and the carry flag are carried from callee to callee, handed to the last call and back to
	// the caller on the early returns; the entry search below also uses r6-r8 as scratch.
	uint64_t reg6{};
	uint64_t reg7{};
	uint64_t reg8{};
	PPCXERRegister flags = ctx.xer;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	auto giveUp = [&]() -> uint32_t {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r6-r8 and the carry flag after the call
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.xer.ca = flags.ca;
		return 0;
	};

	uint32_t hasAvailableReward = CECNPCRewardGiver_HasAvailableReward(ctx, base, nPCRewardGiverAddr);
	reg6 = ctx.r6.u64;
	reg7 = ctx.r7.u64;
	reg8 = ctx.r8.u64;
	flags.ca = ctx.xer.ca;
	if ((hasAvailableReward & 0xFF) == 0) return giveUp();
	if (nPCRewardGiver->m_20 == 0) return giveUp();

	uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t recordHolder = LOAD32(LOAD32(manager + 12) + 88);
	uint32_t handleRecord = LOAD32(recordHolder + 4);
	uint32_t recordState = LOAD32(handleRecord + 104);
	reg8 = LOAD8(recordState + 75);
	bool entryAllowed = (uint32_t)reg8 == 0 && LOAD8(recordState + 73) != 0;
	if (!entryAllowed) return giveUp();

	// state the callee may pass on
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = recordHolder;
	uint32_t entity = EntityHandle_Get(ctx, base, LOAD32(handleRecord));
	reg6 = ctx.r6.u64;
	reg7 = ctx.r7.u64;
	reg8 = ctx.r8.u64;
	flags.ca = ctx.xer.ca;
	if (entity == 0 || (LOAD8(entity + 144) & 64) == 0) return giveUp();

	uint32_t rewardGiverOwner = nPCRewardGiver->m_4;
	uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26788);
	uint32_t globalEntity = EntityHandle_GetEntity_822C7350(ctx, base, LOAD32(globalObject + 32));
	reg6 = ctx.r6.u64;
	reg7 = ctx.r7.u64;
	reg8 = ctx.r8.u64;
	flags.ca = ctx.xer.ca;
	if (globalEntity == rewardGiverOwner) return giveUp();

	if (((LOAD32(entity + 52) >> 5) & 1) == 0) return giveUp();

	// Value stored under key 133 in the entity's sorted 8-byte (key, value) entries at +72..+76;
	// a table at +140 gives the entry index directly when present.
	uint32_t entryValue;
	uint32_t slotTable = LOAD32(entity + 140);
	if (slotTable != 0) {
		uint32_t slot = LOAD8(slotTable + 133);
		entryValue = LOAD32((slot << 3) + LOAD32(entity + 72) + 4);
	} else {
		// lower bound of key 133
		uint32_t entryIt = LOAD32(entity + 72);
		uint32_t entryEnd = LOAD32(entity + 76);
		reg6 = entryEnd;
		STORE32(stack + 80, 0u);
		uint32_t entryBytes = entryEnd - entryIt;
		STORE32(stack + 84, entryIt);
		flags.ca = (int32_t)entryBytes < 0 & (entryBytes & 0x7) != 0;
		int32_t entryCount = (int32_t)entryBytes >> 3;
		if (entryCount > 0) {
			do {
				flags.ca = entryCount < 0 & (entryCount & 0x1) != 0;
				int32_t halfCount = entryCount >> 1;
				uint32_t step = (uint32_t)halfCount << 3;
				reg8 = step;
				entryIt += step;
				reg7 = (int32_t)LOAD32(entryIt) < 133 ? 1 : 0;
				if (reg7 != 0) {
					entryIt += 8;
					entryCount = entryCount - halfCount - 1;
				} else {
					entryIt -= step;
					entryCount = halfCount;
				}
			} while (entryCount > 0);
			STORE32(stack + 84, entryIt);
		}
		if (entryIt != entryEnd && (int32_t)LOAD32(entryIt) <= 133) {
			// the original copies the search result at stack+80 onto itself and reads the entry back from it
			STORE64(stack + 80, LOAD64(stack + 80));
			entryValue = LOAD32(LOAD32(stack + 84) + 4);
		} else {
			// key 133 not found: the word after the end position is read
			entryValue = LOAD32(entryEnd + 4);
		}
	}

	// state the callee may pass on
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	uint32_t queryResult = n_sub_822040D0(ctx, base, entryValue, nPCRewardGiver->m_4);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return queryResult != 4 ? 1 : 0;
}
PROMOTED_ENTRY(3, sub_821C75E0, 0x821C75E0) { ctx.r3.u64 = CECNPCRewardGiver_CanGiveReward(ctx, base, ctx.r3.u32); }

uint64_t CECNPCRewardGiver_Update(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_82000AF4 = int32_t(0x82000AF4);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(3, 0x821C77D8)) { ctx.r3.u64 = nPCRewardGiverAddr; __imp__sub_821C77D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821C77D8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	uint32_t rewardReady = CECNPCRewardGiver_CanGiveReward(ctx, base, nPCRewardGiverAddr);
	// r8 is carried from callee to callee and handed to CECNPCRewardGiver_HasAvailableReward below.
	uint64_t reg8 = ctx.r8.u64;
	uint32_t player = LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 168);

	if ((rewardReady & 0xFF) != 0) {
		uint32_t itemFound = CECNPCRewardGiver_HasMatchingReward(ctx, base, nPCRewardGiverAddr);
		reg8 = ((itemFound & 0xFF) == 0) ? 1 : 0;
		uint32_t wantedModifier = (uint32_t)(reg8 ^ 1) + 50;
		if (nPCRewardGiver->m_1C != wantedModifier) {
			// state the callee may pass on
			uint32_t itemFoundAgain = CECNPCRewardGiver_HasMatchingReward(ctx, base, nPCRewardGiverAddr);
			nPCRewardGiver->m_1C = ((itemFoundAgain & 0xFF) != 0 ? 1u : 0u) + 50;

			BuildRewardString(ctx, base, stack + 80, nPCRewardGiverAddr);

			uint32_t globalRef = LOAD32(LOAD32(uint32_t(g_83490000) + 26788) + 32);
			uint32_t owner = nPCRewardGiver->m_4;
			uint32_t statsTarget = LOAD32(globalRef + 28);
			// state the callee may pass on
			ctx.r6.u64 = globalRef;
			CCharString_AssignFromWideStr(ctx, base, stack + 88, uint64_t(g_82000AF4));

			Stats_ApplyModifierIfAllowed(ctx, base, statsTarget, stack + 80, owner, stack + 88, nPCRewardGiver->m_1C);

			CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 88);
			CCharString_ConstructFromCStr(ctx, base, stack + 88, uint64_t(g_82000000) + 3224, -1);

			// state the callee may pass on
			n_sub_823B6C00(ctx, base, owner, stack + 80, stack + 88, nPCRewardGiver->m_1C, ctx.r8.u64);

			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
			reg8 = ctx.r8.u64;
		}
	} else if (nPCRewardGiver->m_1C != 0) {
		CECNPCRewardGiver_GiveReward(ctx, base, nPCRewardGiverAddr);
		reg8 = ctx.r8.u64;
	}

	// state the callee may pass on
	uint64_t result = CECNPCRewardGiver_HasAvailableReward(ctx, base, nPCRewardGiverAddr);
	// r4 is handed back to the caller; r6-r8 and the carry flag are handed to CECTargeted_CanInteract.
	uint64_t retR4 = ctx.r4.u64;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	flags.ca = ctx.xer.ca;
	if ((result & 0xFF) != 0) {
		retR4 = 226;
		result = Player_HasSafetyMode(ctx, base, player, 226);
		reg8 = ctx.r8.u64;
		if ((result & 0xFF) == 0) {
			uint32_t owner = nPCRewardGiver->m_4;
			result = 0;
			if (((LOAD32(owner + 36) >> 23) & 1) != 0) {
				// Value stored under key 23 in the owner's sorted 8-byte (key, value) entries at +72..+76;
				// a table at +140 gives the entry index directly when present.
				uint32_t entryValue;
				uint32_t slotTable = LOAD32(owner + 140);
				if (slotTable != 0) {
					uint32_t slot = LOAD8(slotTable + 23);
					entryValue = LOAD32((slot << 3) + LOAD32(owner + 72) + 4);
				} else {
					// lower bound of key 23
					uint32_t entryIt = LOAD32(owner + 72);
					uint32_t entryEnd = LOAD32(owner + 76);
					reg6 = entryEnd;
					STORE32(stack + 88, 0u);
					uint32_t entryBytes = entryEnd - entryIt;
					STORE32(stack + 92, entryIt);
					flags.ca = (int32_t)entryBytes < 0 & (entryBytes & 0x7) != 0;
					int32_t entryCount = (int32_t)entryBytes >> 3;
					if (entryCount > 0) {
						do {
							flags.ca = entryCount < 0 & (entryCount & 0x1) != 0;
							int32_t halfCount = entryCount >> 1;
							uint32_t step = (uint32_t)halfCount << 3;
							reg8 = step;
							entryIt += step;
							reg7 = (int32_t)LOAD32(entryIt) < 23 ? 1 : 0;
							if (reg7 != 0) {
								entryIt += 8;
								entryCount = entryCount - halfCount - 1;
							} else {
								entryIt -= step;
								entryCount = halfCount;
							}
						} while (entryCount > 0);
						STORE32(stack + 92, entryIt);
					}
					if (entryIt != entryEnd && (int32_t)LOAD32(entryIt) <= 23) {
						// the original copies the search result at stack+88 onto itself and reads the entry back from it
						STORE64(stack + 88, LOAD64(stack + 88));
						entryValue = LOAD32(LOAD32(stack + 92) + 4);
					} else {
						// key 23 not found: the word after the end position is read
						entryValue = LOAD32(entryEnd + 4);
					}
				}

				// state the callee may pass on
				ctx.r4.u64 = retR4;
				ctx.r6.u64 = reg6;
				ctx.r7.u64 = reg7;
				ctx.xer.ca = flags.ca;
				result = CECTargeted_CanInteract(ctx, base, entryValue);
				retR4 = ctx.r4.u64;
				if ((result & 0xFF) != 0) {
					result = Player_IsActionActive(ctx, base, LOAD32(player + 4), 226);
					retR4 = ctx.r4.u64;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = retR4;
	return result;
}
PROMOTED_ENTRY(3, sub_821C77D8, 0x821C77D8) { ctx.r3.u64 = CECNPCRewardGiver_Update(ctx, base, ctx.r3.u64); }

// Asks rewardEvent for its kind (vtable slot 1): kind 8 goes to CECNPCRewardGiver_ApplyReward; on kind 9 the giver runs
// CECNPCRewardGiver_GiveReward, then the component of the type its own vtable slot 4 returns is removed from m_4.
uint64_t CECNPCRewardGiver_OnEvent(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr, uint64_t rewardEvent) {
	if (!UseLiftedCode(7, 0x82232A60)) { ctx.r3.u64 = nPCRewardGiverAddr; ctx.r4.u64 = rewardEvent; __imp__sub_82232A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82232A60);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	PPCRegister callTarget{};
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t getKindFn = LOAD32(LOAD32((uint32_t)rewardEvent) + 4);
	callTarget.u64 = getKindFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = rewardEvent;
	ctx.r4.u64 = rewardEvent;
	ctx.r10.u64 = getKindFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	int32_t kind = ctx.r3.u32;

	if (kind == 8) {
		result = CECNPCRewardGiver_ApplyReward(ctx, base, nPCRewardGiverAddr, rewardEvent);
	} else {
		// the kind is asked for again
		getKindFn = LOAD32(LOAD32((uint32_t)rewardEvent) + 4);
		callTarget.u64 = getKindFn;
		ctx.r3.u64 = rewardEvent;
		ctx.r10.u64 = getKindFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		if ((int32_t)result == 9) {
			CECNPCRewardGiver_GiveReward(ctx, base, nPCRewardGiverAddr);
			uint32_t getComponentTypeFn = LOAD32((uint32_t)nPCRewardGiver->vtable + 16);
			uint32_t owner = nPCRewardGiver->m_4;
			callTarget.u64 = getComponentTypeFn;
			ctx.r3.u64 = nPCRewardGiverAddr;
			ctx.r10.u64 = getComponentTypeFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t componentType = ctx.r3.u64;
			result = Entity_RemoveComponentByType(ctx, base, owner, componentType, ctx.r8.u64);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_82232A60, 0x82232A60) { ctx.r3.u64 = CECNPCRewardGiver_OnEvent(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECNPCRewardGiver_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820B32DC_B_ = int32_t(0x820B32DC);
	if (!UseLiftedCode(25, 0x8244FF98)) { ctx.r3.u64 = classNameString; __imp__sub_8244FF98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8244FF98);
	uint32_t stack = ctx.r1.u64;
	const int32_t length = -1;

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820B32DC_B_, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;

	return classNameString;
}
PROMOTED_ENTRY(25, sub_8244FF98, 0x8244FF98) { ctx.r3.u64 = CECNPCRewardGiver_GetClassName(ctx, base, ctx.r3.u64); }

// Constructor: owner in m_4 and an empty list at +12; the first construction also fills the table at
// 0x83497F2C and sorts it.
uint64_t CECNPCRewardGiver_Constructor(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr, uint64_t owner) {
	if (!UseLiftedCode(25, 0x82450038)) { ctx.r3.u64 = nPCRewardGiverAddr; ctx.r4.u64 = owner; __imp__sub_82450038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82450038);
	uint32_t stack = ctx.r1.u64;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 144);

	nPCRewardGiver->m_4 = (uint32_t)owner;
	nPCRewardGiver->m_8 = 0;
	nPCRewardGiver->vtable = 0x82004760u;

	// The list's sentinel node links to itself at +0 and +4.
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = owner;
	uint32_t node = operator_new(ctx, base, 16);
	if (node != 0) {
		STORE32(node, node);
	}
	// carry out of node + 4; handed to the first registration call below
	uint8_t nodeCarry = node > 0xFFFFFFFBu;
	uint32_t nodeSecondLink = node + 4;
	if (nodeSecondLink != 0) {
		STORE32(nodeSecondLink, node);
	}

	nPCRewardGiver->m_10 = node;
	nPCRewardGiver->m_14 = 0;
	nPCRewardGiver->m_19 = 0;
	nPCRewardGiver->m_18 = 1;
	nPCRewardGiver->m_1A = 0;
	bool handlersRegistered = LOAD8(0x834969F6) != 0;
	nPCRewardGiver->m_1C = 0;
	nPCRewardGiver->m_20 = 1;
	nPCRewardGiver->m_24 = 0xFFFFFFECu;
	nPCRewardGiver->m_28 = 0;
	nPCRewardGiver->m_2C = 0;

	if (!handlersRegistered) {
		// Each call adds an 8-byte (id, function) entry to the table at 0x83497F2C and sets its byte +17;
		// r3 is handed from call to call, starting with the node.
		ctx.r3.u64 = node;
		ctx.xer.ca = nodeCarry;
		uint32_t carried = CECNPCRewardGiver_RegisterRewardType1(ctx, base);
		ctx.r3.u64 = carried;
		carried = CECNPCRewardGiver_RegisterRewardType2(ctx, base);
		ctx.r3.u64 = carried;
		carried = CECNPCRewardGiver_RegisterRewardType3(ctx, base);
		ctx.r3.u64 = carried;
		carried = CECNPCRewardGiver_RegisterRewardType7(ctx, base);
		ctx.r3.u64 = carried;
		CECNPCRewardGiver_RegisterRewardType5(ctx, base);

		uint32_t handlerTable = 0x83497F2C;
		if (LOAD8(handlerTable + 17) != 0) {
			uint32_t entriesEnd = LOAD32(handlerTable + 8);
			uint32_t entriesBegin = LOAD32(handlerTable + 4);
			STORE32(stack + 80, 0u);
			STORE32(stack + 88, 0u);
			uint32_t sortPredicate = LOAD8(handlerTable + 16);
			uint64_t entryCount = (int32_t)(entriesEnd - entriesBegin) >> 3;
			// the range ends as 8-byte (0, pointer) pairs: end at stack+80, begin at stack+88
			STORE32(stack + 84, entriesEnd);
			STORE32(stack + 92, entriesBegin);
			uint64_t rangeLast = LOAD64(stack + 80);
			uint64_t rangeFirst = LOAD64(stack + 88);
			StdSort_IntroLoop_Elem8(ctx, base, rangeFirst, rangeLast, entryCount, sortPredicate);
			STORE8(handlerTable + 17, 0);
		}
		STORE8(0x834969F6, 1);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return nPCRewardGiverAddr;
}
PROMOTED_ENTRY(25, sub_82450038, 0x82450038) { ctx.r3.u64 = CECNPCRewardGiver_Constructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Deleting destructor: runs the destructor and frees the object when bit 0 of the flags is set.
uint64_t CECNPCRewardGiver_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(25, 0x82450130)) { ctx.r3.u64 = nPCRewardGiverAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82450130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82450130);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = deleteFlags;
	CECNPCRewardGiver_Destructor(ctx, base, nPCRewardGiverAddr);
	if (((uint32_t)deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, nPCRewardGiverAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return nPCRewardGiverAddr;
}
PROMOTED_ENTRY(25, sub_82450130, 0x82450130) { ctx.r3.u64 = CECNPCRewardGiver_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Destructor: empties the list at +12, frees its sentinel node (m_10), then installs vtable 0x820A8D10.
uint32_t CECNPCRewardGiver_Destructor(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr) {
	if (!UseLiftedCode(25, 0x82450180)) { ctx.r3.u64 = nPCRewardGiverAddr; __imp__sub_82450180(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82450180);
	uint32_t stack = ctx.r1.u64;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 96);
	uint64_t listAddr = nPCRewardGiverAddr + 12;
	nPCRewardGiver->vtable = 0x82004760u;
	ctx.r1.u64 = stack;
	SharedHandleList_Clear(ctx, base, listAddr);
	uint32_t sentinelNode = nPCRewardGiver->m_10;
	uint32_t freeResult = HandleTarget_Free(ctx, base, sentinelNode);
	nPCRewardGiver->m_10 = 0u;
	nPCRewardGiver->vtable = 0x820A8D10u;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return freeResult;
}
PROMOTED_ENTRY(25, sub_82450180, 0x82450180) { ctx.r3.u64 = CECNPCRewardGiver_Destructor(ctx, base, ctx.r3.u64); }

// sub_824501D8  [4 bytes]
uint64_t CECNPCRewardGiver_GiveRewardThunk(CpuState& ctx, uint8_t* base, uint64_t rewardGiver) {
	if (!UseLiftedCode(25, 0x824501D8)) { ctx.r3.u64 = rewardGiver; __imp__sub_824501D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824501D8);
	return CECNPCRewardGiver_GiveReward(ctx, base, rewardGiver);
}
PROMOTED_ENTRY(25, sub_824501D8, 0x824501D8) { ctx.r3.u64 = CECNPCRewardGiver_GiveRewardThunk(ctx, base, ctx.r3.u64); }

// Calls CECDoor_UpdateOpenStateForEntity with the owner (m_4). Given a GameDB record and no skip flag, it then clears m_20 when the
// record's TXT_820B32F0_B_ equals the float at 0x820994B4, and sets the rewards up from the record
// (CECNPCRewardGiver_TryGiveReward).
uint64_t CECNPCRewardGiver_LoadFromRecord(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr, uint64_t record, uint64_t skipRewardSetup) {
	constexpr int32_t str_TXT_820B32F0_B_ = int32_t(0x820B32F0);
	if (!UseLiftedCode(25, 0x824501E0)) { ctx.r3.u64 = nPCRewardGiverAddr; ctx.r4.u64 = record; ctx.r5.u64 = skipRewardSetup; __imp__sub_824501E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824501E0);
	uint32_t stack = ctx.r1.u64;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t owner = nPCRewardGiver->m_4;
	ctx.r1.u64 = stack;
	ctx.r5.u64 = skipRewardSetup; // state the callee may pass on
	uint64_t result = CECDoor_UpdateOpenStateForEntity(ctx, base, owner, nPCRewardGiverAddr);
	if ((uint32_t)record != 0 && (int32_t)skipRewardSetup == 0) {
		GameDB_GetFloatByName(ctx, base, record, str_TXT_820B32F0_B_);
		double TXT_820B32F0_L_ = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		if (TXT_820B32F0_L_ == double(LOAD_F32(0x820994B4u))) {
			nPCRewardGiver->m_20 = uint8_t(0);
		}
		result = CECNPCRewardGiver_TryGiveReward(ctx, base, nPCRewardGiverAddr, record);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_824501E0, 0x824501E0) { ctx.r3.u64 = CECNPCRewardGiver_LoadFromRecord(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// With a GameDB record and m_20 set: unless a random roll (Rng_NextScaledFloat on the generator at +120 of the
// object reached through the global at 0x83496920) exceeds the record's TXT_820B32F0_B_, picks a reward from
// the record's TXT_820B3330_B_ list (CECNPCRewardGiver_SelectRandomReward), resolves it, and hands it to CECNPCRewardGiver_AddReward unless m_1A excludes
// reward type 2 or m_19 excludes reward type 7.
uint64_t CECNPCRewardGiver_TryGiveReward(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr, uint64_t record) {
	constexpr int32_t str_TXT_820B32F0_B_ = int32_t(0x820B32F0);
	constexpr int32_t str_TXT_820B3330_B_ = int32_t(0x820B3330);
	constexpr int32_t str_TXT_820B333C_B_ = int32_t(0x820B333C);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x824505A8)) { ctx.r3.u64 = nPCRewardGiverAddr; ctx.r4.u64 = record; __imp__sub_824505A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824505A8);
	uint32_t stack = ctx.r1.u64;
	double f1 = ctx.f1.f64; // f1 as the original leaves it for the callers
	uint64_t result = nPCRewardGiverAddr;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 128);
	if ((uint32_t)record != 0 && nPCRewardGiver->m_20 != 0) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t slot = LOAD32(LOAD32(globalRoot + 12) + 88);
		uint32_t holder = LOAD32(slot + 4);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = slot; // state the callees may pass on (CECNPCRewardGiver_SelectRandomReward below takes ctx.r8 as its second argument)
		result = GameDB_GetFloatByName(ctx, base, record, str_TXT_820B32F0_B_);
		double TXT_820B32F0_L_ = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		uint32_t rng = holder + 120;
		f1 = Rng_NextScaledFloat(ctx, base, rng, double(LOAD_F32(0x820994C0u)));
		ctx.fpscr.disableFlushMode();
		if (!(f1 > TXT_820B32F0_L_)) {
			result = GameDB_ReadU32Field(ctx, base, record, str_TXT_820B3330_B_);
			if ((uint32_t)result != 0) {
				uint32_t idRef = stack + 80;
				// state the callee may pass on
				ctx.f1.f64 = f1;
				uint32_t rewardId = (uint32_t)CECNPCRewardGiver_SelectRandomReward(ctx, base, result, ctx.r8.u64);
				f1 = ctx.f1.f64;
				IdRef_ConstructFromId(ctx, base, idRef, rewardId);
				result = IdRef_Get(ctx, base, idRef);
				uint64_t rewardRecord = result;
				if ((uint32_t)rewardRecord != 0) {
					result = GameDB_GetIntByName(ctx, base, rewardRecord, str_TXT_820B333C_B_);
					int32_t TXT_820B333C_L_ = (int32_t)result;
					bool excluded = (nPCRewardGiver->m_1A != 0 && TXT_820B333C_L_ == 2) ||
					                (nPCRewardGiver->m_19 != 0 && TXT_820B333C_L_ == 7);
					if (!excluded) {
						result = CECNPCRewardGiver_AddReward(ctx, base, nPCRewardGiverAddr, rewardRecord);
						f1 = ctx.f1.f64;
					}
				}
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = f1; // callers read f1 after the call
	return result;
}
PROMOTED_ENTRY(25, sub_824505A8, 0x824505A8) { ctx.r3.u64 = CECNPCRewardGiver_TryGiveReward(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Builds a string on the stack: str_TXT_820B36C0_B_ with the string at +128 of the owner m_4 appended (RefCountedString_Assign
// appends to a non-empty string). Passes it with the owner to InteractionManager_RemoveText and n_sub_823B6CE0, clears m_1C and
// releases the string.
uint64_t CECNPCRewardGiver_GiveReward(CpuState& ctx, uint8_t* base, uint32_t nPCRewardGiverAddr) {
	constexpr int32_t str_TXT_820B36C0_B_ = int32_t(0x820B36C0);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x824506A8)) { ctx.r3.u64 = nPCRewardGiverAddr; __imp__sub_824506A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824506A8);
	uint32_t stack = ctx.r1.u64;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26788);
	uint32_t owner = nPCRewardGiver->m_4;
	uint32_t target = LOAD32(LOAD32(globalObject + 32) + 28);
	uint32_t text = stack + 80;

	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, text, str_TXT_820B36C0_B_, -1);
	RefCountedString_Assign(ctx, base, text, (uint64_t)nPCRewardGiver->m_4 + 128); // m_4 read again, as the original does
	InteractionManager_RemoveText(ctx, base, target, owner, text);
	ctx.r3.u64 = target; // state the callee may pass on
	n_sub_823B6CE0(ctx, base, owner, text, ctx.r8.u64);

	nPCRewardGiver->m_1C = 0;
	ctx.r8.u64 = 0; // state the callee may pass on
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, text);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_824506A8, 0x824506A8) { ctx.r3.u64 = CECNPCRewardGiver_GiveReward(ctx, base, ctx.r3.u32); }

// Returns 1 when m_20 is set, the flags at +75 (clear) and +73 (set) of the state object reached through the
// global at 0x83496920 allow it, and some listed reward that NPCReward_IsAvailableToOwner matches with the owner (m_4) reports
// a value other than 3 from its first virtual function; 0 otherwise.
uint64_t CECNPCRewardGiver_HasMatchingReward(CpuState& ctx, uint8_t* base, uint32_t nPCRewardGiverAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x82450BD8)) { ctx.r3.u64 = nPCRewardGiverAddr; __imp__sub_82450BD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82450BD8);
	uint32_t stack = ctx.r1.u64;
	// r7-r9 as the original has them: the lookups below leave values in them, they are handed to
	// NPCReward_IsAvailableToOwner, read back after the calls and left for the callers at the return.
	uint64_t r7 = ctx.r7.u64;
	uint64_t r8 = ctx.r8.u64;
	uint64_t r9 = ctx.r9.u64;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t result = 0;
	if (nPCRewardGiver->m_20 != 0) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		r9 = LOAD32(LOAD32(globalRoot + 12) + 88);
		r8 = LOAD32((uint32_t)r9 + 4);
		uint32_t state = LOAD32((uint32_t)r8 + 104);
		r7 = LOAD8(state + 75);
		bool enabled = (uint32_t)r7 == 0 && LOAD8(state + 73) != 0;

		if (enabled) {
			// m_10 is the end node of the list at +12. The original reads it again at every check; its iterator checks
			// (ppc_trap) fire when the current node is the end node.
			uint32_t node = LOAD32(uint32_t(nPCRewardGiver->m_10));
			while (node != nPCRewardGiver->m_10) {
				if (node == nPCRewardGiver->m_10) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				uint32_t TXT_820B36C0_L_ = LOAD32(node + 8);
				uint32_t owner = nPCRewardGiver->m_4;
				ctx.r1.u64 = stack;
				ctx.r7.u64 = r7;
				ctx.r8.u64 = r8;
				ctx.r9.u64 = r9;
				uint64_t matched = NPCReward_IsAvailableToOwner(ctx, base, TXT_820B36C0_L_, owner);
				r7 = ctx.r7.u64;
				r8 = ctx.r8.u64;
				r9 = ctx.r9.u64;
				if ((matched & 0xFF) != 0) {
					uint32_t stateFn = LOAD32(LOAD32(TXT_820B36C0_L_));
					ctx.r3.u64 = TXT_820B36C0_L_;
					ctx.r10.u64 = stateFn;
					REX_CALL_INDIRECT_FUNC(stateFn);
					uint32_t rewardState = ctx.r3.u32;
					r7 = ctx.r7.u64;
					r8 = ctx.r8.u64;
					r9 = ctx.r9.u64;
					if ((int32_t)rewardState != 3) {
						result = 1;
						break;
					}
				}
				if (node == nPCRewardGiver->m_10) {
					ppc_trap(ctx, base, 22);
				}
				node = LOAD32(node);
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r7-r9 after the call
	ctx.r7.u64 = r7;
	ctx.r8.u64 = r8;
	ctx.r9.u64 = r9;
	return result;
}
PROMOTED_ENTRY(25, sub_82450BD8, 0x82450BD8) { ctx.r3.u64 = CECNPCRewardGiver_HasMatchingReward(ctx, base, ctx.r3.u32); }

// When m_20 is set: looks the reward record's TXT_820B333C_B_ up in the sorted table of 8-byte {type, factory} entries
// whose begin and end pointers are at +4 and +8 of 0x83497F2C. When the type is there, its factory makes a reward
// object from the owner (m_4) and the record, and the object, held through a shared handle, is inserted at the end
// position of the list at +12 (m_10 is its end node). For reward type 3, m_18 is then set from the record's
// TXT_820B33D4_B_ field.
uint64_t CECNPCRewardGiver_AddReward(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr, uint64_t rewardRecord) {
	constexpr int32_t str_TXT_820B333C_B_ = int32_t(0x820B333C);
	constexpr int32_t str_TXT_820B33D4_B_ = int32_t(0x820B33D4);
	constexpr int32_t g_83497F2C = int32_t(0x83497F2C);
	if (!UseLiftedCode(25, 0x824511C0)) { ctx.r3.u64 = nPCRewardGiverAddr; ctx.r4.u64 = rewardRecord; __imp__sub_824511C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824511C0);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer; // xer.ca as the original has it: handed to the calls and left for the callers
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 128);
	uint64_t result = nPCRewardGiverAddr;

	if (nPCRewardGiver->m_20 != 0) {
		ctx.r1.u64 = stack;
		result = GameDB_GetIntByName(ctx, base, rewardRecord, str_TXT_820B333C_B_);
		int32_t TXT_820B333C_L_ = (int32_t)result;

		// Lower-bound binary search. r7-r10 keep the search's scratch values (the original's 64-bit registers),
		// which the original hands to the factory call together with the table end in r6.
		uint64_t r7 = ctx.r7.u64;
		uint64_t r9 = g_83497F2C; // sign-extended, as the original's register holds the address
		uint64_t entry = LOAD32(uint32_t(g_83497F2C) + 4);
		uint32_t tableEnd = LOAD32(uint32_t(g_83497F2C) + 8);
		uint64_t r8 = (uint64_t)tableEnd - entry;
		flags.ca = (int32_t)r8 < 0 && (r8 & 7) != 0;
		int32_t remaining = (int32_t)r8 >> 3;
		while (remaining > 0) {
			flags.ca = 0; // halving a positive count carries nothing
			int32_t half = remaining >> 1;
			uint32_t offset = (uint32_t)half << 3;
			r9 = (uint64_t)half;
			r8 = offset;
			uint64_t middle = entry + offset;
			r7 = (int32_t)LOAD32((uint32_t)middle) < TXT_820B333C_L_;
			if (r7 != 0) {
				entry = middle + 8;
				remaining = remaining - half - 1;
			} else {
				remaining = half;
			}
		}

		if ((uint32_t)entry != tableEnd && TXT_820B333C_L_ >= (int32_t)LOAD32((uint32_t)entry)) {
			uint32_t owner = nPCRewardGiver->m_4;
			uint32_t factory = LOAD32((uint32_t)entry + 4);
			// the factory's arguments, then the search state the original leaves in the registers
			ctx.r3.u64 = owner;
			ctx.r4.u64 = rewardRecord;
			ctx.r6.u64 = tableEnd;
			ctx.r7.u64 = r7;
			ctx.r8.u64 = r8;
			ctx.r9.u64 = r9;
			ctx.r10.u64 = entry;
			ctx.xer.ca = flags.ca;
			REX_CALL_INDIRECT_FUNC(factory);
			uint32_t rewardObject = ctx.r3.u32;
			flags.ca = ctx.xer.ca;

			uint32_t handle = stack + 80; // {object, control block}
			STORE32(handle, rewardObject);
			uint64_t source;
			if (rewardObject != 0) {
				source = SharedHandle_CreateFromObject(ctx, base, handle);
				flags.ca = ctx.xer.ca;
			} else {
				source = handle;
				STORE32(stack + 84, 0);
			}

			// insertion position: the {list, node} pair for the list's end node
			uint32_t endNode = nPCRewardGiver->m_10;
			uint32_t list = (uint32_t)nPCRewardGiverAddr + 12;
			STORE32(stack + 88, list);
			STORE32(stack + 92, endNode);
			List_InsertNodeCopyRefCountedPair(ctx, base, list, LOAD64(stack + 88), source);
			flags.ca = ctx.xer.ca;

			result = SharedHandle_Release(ctx, base, handle);
			flags.ca = ctx.xer.ca;
		}

		if (TXT_820B333C_L_ == 3) {
			ctx.xer.ca = flags.ca;
			result = GameDB_ReadBoolField_82303F38(ctx, base, rewardRecord, str_TXT_820B33D4_B_);
			nPCRewardGiver->m_18 = (uint8_t)result;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca; // callers read xer.ca after the call
	return result;
}
PROMOTED_ENTRY(25, sub_824511C0, 0x824511C0) { ctx.r3.u64 = CECNPCRewardGiver_AddReward(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Calls CECNPCRewardGiver_GiveReward. Then, when the flags at +75 (clear) and +73 (set) of the state object (+104 of the holder
// reached through the global at 0x83496920) allow it, the entity the holder's handle (its first word) resolves to
// and the entity at +4 of `info` both have bit 0x40 of byte +144 set, and Players_IsPlayer accepts the holder's
// handle with the latter: the first listed reward whose virtual function at +16 accepts is given the entity
// through its virtual function at +20 and marked (byte +13).
// Finally removes from the owner (m_4) the component of the type this object's virtual function at +16 returns.
uint64_t CECNPCRewardGiver_ApplyReward(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr, uint64_t info) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x82451308)) { ctx.r3.u64 = nPCRewardGiverAddr; ctx.r4.u64 = info; __imp__sub_82451308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82451308);
	uint32_t stack = ctx.r1.u64;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t infoAddr = (uint32_t)info;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = info; // state the callee may pass on
	CECNPCRewardGiver_GiveReward(ctx, base, nPCRewardGiverAddr);
	// r4, r8 and r9 as the original has them: read back after the calls and handed to the virtual calls.
	uint64_t r4 = ctx.r4.u64;
	uint64_t r8 = ctx.r8.u64;

	uint32_t holder = LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4);
	uint32_t state = LOAD32(holder + 104);
	uint64_t r9 = LOAD8(state + 75);
	bool enabled = (uint32_t)r9 == 0 && LOAD8(state + 73) != 0;

	if (enabled) {
		ctx.r9.u64 = r9; // state the callee may pass on
		uint64_t entity = EntityHandle_Get(ctx, base, LOAD32(holder));
		r4 = ctx.r4.u64;
		r8 = ctx.r8.u64;
		r9 = ctx.r9.u64;
		bool entityFlagged = (uint32_t)entity != 0 && (LOAD8((uint32_t)entity + 144) & 64) != 0;
		if (entityFlagged) {
			r4 = LOAD32(infoAddr + 4);
			bool otherFlagged = (uint32_t)r4 != 0 && (LOAD8((uint32_t)r4 + 144) & 64) != 0;
			if (otherFlagged) {
				// the same chain, read again as the original does
				uint32_t holderAgain = LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4);
				uint32_t holderHandle = LOAD32(holderAgain);
				ctx.r9.u64 = holderAgain; // state the callee may pass on
				uint32_t isPlayer = (uint32_t)Players_IsPlayer(ctx, base, holderHandle, r4);
				r4 = ctx.r4.u64;
				r9 = ctx.r9.u64;
				r8 = isPlayer & 0xFF;
				if ((uint32_t)r8 != 0) {
					// m_10 is the end node of the list at +12. The original reads it again at every check; its iterator checks
					// (ppc_trap) fire when the current node is the end node.
					uint32_t node = LOAD32(uint32_t(nPCRewardGiver->m_10));
					while (node != nPCRewardGiver->m_10) {
						if (node == nPCRewardGiver->m_10) {
							ppc_trap(ctx, base, 22);
						}
						uint32_t TXT_820B36C0_L_ = LOAD32(node + 8);
						uint32_t acceptsFn = LOAD32(LOAD32(TXT_820B36C0_L_) + 16);
						ctx.r3.u64 = TXT_820B36C0_L_;
						ctx.r8.u64 = r8;
						ctx.r9.u64 = r9;
						ctx.r10.u64 = acceptsFn;
						REX_CALL_INDIRECT_FUNC(acceptsFn);
						uint32_t accepted = ctx.r3.u32;
						r4 = ctx.r4.u64;
						r8 = ctx.r8.u64;
						r9 = accepted & 0xFF;
						if ((uint32_t)r9 != 0) {
							uint32_t giveFn = LOAD32(LOAD32(TXT_820B36C0_L_) + 20); // vtable read again after the call
							ctx.r3.u64 = TXT_820B36C0_L_;
							ctx.r4.u64 = entity;
							ctx.r9.u64 = r9;
							ctx.r10.u64 = giveFn;
							REX_CALL_INDIRECT_FUNC(giveFn);
							r4 = ctx.r4.u64;
							r8 = ctx.r8.u64;
							r9 = 1;
							STORE8(TXT_820B36C0_L_ + 13, 1);
							break;
						}
						if (node == nPCRewardGiver->m_10) {
							ppc_trap(ctx, base, 22);
						}
						node = LOAD32(node);
					}
				}
			}
		}
	}

	uint32_t owner = nPCRewardGiver->m_4;
	uint32_t componentTypeFn = LOAD32(uint32_t(nPCRewardGiver->vtable) + 16);
	ctx.r3.u64 = nPCRewardGiverAddr;
	ctx.r4.u64 = r4;
	ctx.r8.u64 = r8;
	ctx.r9.u64 = r9;
	ctx.r10.u64 = componentTypeFn;
	REX_CALL_INDIRECT_FUNC(componentTypeFn);
	uint64_t componentType = ctx.r3.u64;
	uint64_t result = Entity_RemoveComponentByType(ctx, base, owner, componentType, ctx.r8.u64);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_82451308, 0x82451308) { ctx.r3.u64 = CECNPCRewardGiver_ApplyReward(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Calls the first virtual function of every reward in the list at +12 and sets byte +28 of those for which it
// returns 3; then sets m_18. Returns what the last call returned (the object address when the list is empty).
uint64_t CECNPCRewardGiver_UpdateRewardAvailability(CpuState& ctx, uint8_t* base, uint64_t nPCRewardGiverAddr) {
	if (!UseLiftedCode(25, 0x824514A8)) { ctx.r3.u64 = nPCRewardGiverAddr; __imp__sub_824514A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824514A8);
	uint32_t stack = ctx.r1.u64;
	CECNPCRewardGiver* nPCRewardGiver = GameObject<CECNPCRewardGiver>(base, nPCRewardGiverAddr);
	stack = PushStackFrame(base, stack, 128);
	uint64_t result = nPCRewardGiverAddr;

	// m_10 is the end node of the list at +12. The original reads it again at every check; its iterator checks
	// (ppc_trap) fire when the current node is the end node.
	uint32_t node = LOAD32(uint32_t(nPCRewardGiver->m_10));
	while (node != nPCRewardGiver->m_10) {
		if (node == nPCRewardGiver->m_10) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t TXT_820B36C0_L_ = LOAD32(node + 8);
		uint32_t stateFn = LOAD32(LOAD32(TXT_820B36C0_L_));
		ctx.r1.u64 = stack;
		ctx.r3.u64 = TXT_820B36C0_L_;
		ctx.r10.u64 = stateFn;
		REX_CALL_INDIRECT_FUNC(stateFn);
		result = ctx.r3.u64;
		if ((int32_t)result == 3) {
			STORE8(TXT_820B36C0_L_ + 28, 1);
		}
		if (node == nPCRewardGiver->m_10) {
			ppc_trap(ctx, base, 22);
		}
		node = LOAD32(node);
	}

	nPCRewardGiver->m_18 = 1;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_824514A8, 0x824514A8) { ctx.r3.u64 = CECNPCRewardGiver_UpdateRewardAvailability(ctx, base, ctx.r3.u64); }
