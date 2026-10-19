// CECPlayer (vtable 0x82003188): methods of the class as readable C++.
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

uint32_t n_sub_821A3658(CpuState& ctx, uint8_t* base, uint32_t playerAddr, uint64_t entityAddr) {
	if (!UseLiftedCode(1, 0x821A3658)) { ctx.r3.u64 = playerAddr; ctx.r4.u64 = entityAddr; __imp__sub_821A3658(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821A3658);
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t entity = (uint32_t)entityAddr;

	// r4, r6-r10, cr0 and xer.ca as the original leaves them for the calls below and for callers
	uint64_t callerR4 = entityAddr;
	uint64_t callerR6 = ctx.r6.u64;
	uint64_t callerR7 = ctx.r7.u64;
	uint64_t callerR8 = ctx.r8.u64;
	uint64_t callerR9 = ctx.r9.u64;
	uint64_t callerR10 = 0;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	auto storeCallerState = [&]() {
		ctx.r6.u64 = callerR6;
		ctx.r7.u64 = callerR7;
		ctx.r8.u64 = callerR8;
		ctx.r9.u64 = callerR9;
		ctx.r10.u64 = callerR10;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
	};
	auto loadCallerState = [&]() {
		callerR6 = ctx.r6.u64;
		callerR7 = ctx.r7.u64;
		callerR8 = ctx.r8.u64;
		callerR9 = ctx.r9.u64;
		callerR10 = ctx.r10.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
	};
	auto leave = [&](uint32_t result) -> uint32_t {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// the exits that return 0 also leave r4
		if (result == 0)
			ctx.r4.u64 = callerR4;
		storeCallerState();
		return result;
	};

	// Component of type `type` from the object's sorted (type, component) pairs at +72..+76, found
	// with a lower bound on signed types. The final search position is left in searchPos (64-bit, as
	// the original keeps it); the search sets r6-r9, cr0 and xer.ca as the original does.
	uint64_t searchPos = 0;
	auto searchComponent = [&](uint32_t object, int32_t type) -> uint32_t {
		uint32_t begin = LOAD32(object + 72);
		uint32_t end = LOAD32(object + 76);
		callerR6 = end;
		STORE32(stack + 80, 0);
		uint32_t byteCount = end - begin;
		STORE32(stack + 84, begin);
		flags.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
		int32_t count = (int32_t)byteCount >> 3;
		compare0.compare<int32_t>(count, 0, flags);
		uint64_t pos = begin;
		if (count > 0) {
			// halving a positive count clears the carry
			flags.ca = 0;
			do {
				int32_t half = count >> 1;
				uint32_t step = (uint32_t)half << 3;
				pos += step;
				bool below = (int32_t)LOAD32((uint32_t)pos) < type;
				callerR7 = below ? 1 : 0;
				callerR8 = step;
				callerR9 = (uint32_t)half;
				if (below) {
					count = count - half - 1;
					pos += 8;
				} else {
					pos -= step;
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, (uint32_t)pos);
		}
		searchPos = pos;
		if ((uint32_t)pos != end && (int32_t)LOAD32((uint32_t)pos) <= type) {
			STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the iterator pair in place
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	callerR10 = (LOAD32(entity + 48) >> 1) & 1;
	if (callerR10 != 0)
		return leave(0);

	uint32_t gameContext = LOAD32(0x83496920u);
	uint32_t contextData = LOAD32(gameContext + 12);
	uint32_t arrayHolder = LOAD32(contextData + 88);
	uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	uint32_t players = LOAD32(arrayBegin);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	uint32_t isPlayer = (uint32_t)Players_IsPlayer(ctx, base, players, entityAddr) & 0xFF;
	callerR4 = ctx.r4.u64;
	loadCallerState();
	callerR7 = isPlayer;
	if (isPlayer != 0)
		return leave(0);

	// When the entity has a component of type 122 (bit 26 of its mask word at +48) that n_sub_821C2C18
	// reports as 1, the player's entity must have one for which it reports 1 as well.
	if ((LOAD32(entity + 48) >> 26) & 1) {
		uint32_t entityComponent;
		uint32_t entitySlots = LOAD32(entity + 140);
		if (entitySlots != 0) {
			uint64_t pairAddr = uint64_t((uint32_t)LOAD8(entitySlots + 122) << 3) + LOAD32(entity + 72);
			callerR9 = pairAddr;
			entityComponent = LOAD32((uint32_t)pairAddr + 4);
		} else {
			entityComponent = searchComponent(entity, 122);
		}
		callerR10 = 1;
		if ((uint32_t)n_sub_821C2C18(ctx, base, entityComponent) == 1) {
			uint32_t playerEntity = player->m_4;
			uint32_t playerMask = LOAD32(playerEntity + 48);
			callerR10 = playerMask;
			callerR9 = (playerMask >> 26) & 1;
			if (callerR9 == 0)
				return leave(0);
			uint32_t playerComponent;
			uint32_t playerSlots = LOAD32(playerEntity + 140);
			if (playerSlots != 0) {
				uint32_t pairOffset = (uint32_t)LOAD8(playerSlots + 122) << 3;
				uint64_t pairAddr = uint64_t(pairOffset) + LOAD32(playerEntity + 72);
				callerR10 = pairOffset;
				callerR9 = pairAddr;
				playerComponent = LOAD32((uint32_t)pairAddr + 4);
			} else {
				playerComponent = searchComponent(playerEntity, 122);
				callerR10 = searchPos;
			}
			if ((uint32_t)n_sub_821C2C18(ctx, base, playerComponent) != 1)
				return leave(0);
		}
	} else {
		callerR10 = 0;
	}

	storeCallerState();  // state the callee may pass on
	uint64_t entityCheck = n_sub_822C6310(ctx, base, entityAddr, player->m_4);
	callerR4 = ctx.r4.u64;
	loadCallerState();
	if ((entityCheck & 0xFF) == 0)
		return leave(0);

	uint64_t safetyModeEnabled = n_sub_821EE210(ctx, base, playerAddr);  // Lua_Player_IsSafetyModeEnabled
	loadCallerState();
	if ((safetyModeEnabled & 0xFF) == 0)
		return leave(1);

	// With safety mode on, the result is 0 only when the player's entity has a component of type 133
	// (bit 5 of its mask word at +52) for which n_sub_822040D0 with the entity does not return 4.
	uint32_t playerEntity = player->m_4;
	uint32_t playerMask = LOAD32(playerEntity + 52);
	callerR10 = playerMask;
	callerR9 = (playerMask >> 5) & 1;
	if (callerR9 == 0)
		return leave(1);
	uint32_t component133;
	uint32_t playerSlots = LOAD32(playerEntity + 140);
	if (playerSlots != 0) {
		uint32_t index = LOAD8(playerSlots + 133);
		uint32_t pairs = LOAD32(playerEntity + 72);
		uint64_t pairAddr = uint64_t(index << 3) + pairs;
		callerR8 = pairAddr;
		callerR9 = index;
		callerR10 = pairs;
		component133 = LOAD32((uint32_t)pairAddr + 4);
	} else {
		component133 = searchComponent(playerEntity, 133);
		callerR10 = searchPos;
	}

	storeCallerState();  // state the callee may pass on
	uint32_t component133Check = (uint32_t)n_sub_822040D0(ctx, base, component133, entityAddr);
	callerR4 = ctx.r4.u64;
	loadCallerState();
	return leave(component133Check == 4 ? 1 : 0);
}
PROMOTED_ENTRY(1, sub_821A3658, 0x821A3658) { ctx.r3.u64 = n_sub_821A3658(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_821B8960  [100 bytes]
uint64_t n_sub_821B8960(CpuState& ctx, uint8_t* base, uint32_t playerAddr) {
	if (!UseLiftedCode(2, 0x821B8960)) { ctx.r3.u64 = playerAddr; __imp__sub_821B8960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821B8960);
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t linkedObject = player->m_14;
	uint64_t result = 0;
	if (linkedObject != 0) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = linkedObject;  // n_sub_821C7E70 takes its argument in r3
		if ((n_sub_821C7E70(ctx, base) & 0xFF) != 0)
			result = n_sub_821C7CB8(ctx, base, player->m_14);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(2, sub_821B8960, 0x821B8960) { ctx.r3.u64 = n_sub_821B8960(ctx, base, ctx.r3.u32); }

// sub_821EE210 = Lua_Player_IsSafetyModeEnabled (Lua Player.IsSafetyModeEnabled)  [552 bytes]
uint64_t n_sub_821EE210(CpuState& ctx, uint8_t* base, uint32_t playerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(4, 0x821EE210)) { ctx.r3.u64 = playerAddr; __imp__sub_821EE210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821EE210);
	uint32_t stack = ctx.r1.u64;
	constexpr uint32_t kGameContextSlot = uint32_t(g_83490000) + 26912;
	stack = PushStackFrame(base, stack, 144);

	// r4 and r6-r9, cr0 and xer.ca as the original leaves them for the calls below and for callers
	// (r5 is gameContext and r10 is set at the end)
	uint64_t callerR4 = ctx.r4.u64;
	uint64_t callerR6 = ctx.r6.u64;
	uint64_t callerR7 = ctx.r7.u64;
	uint64_t callerR8 = ctx.r8.u64;
	uint64_t callerR9 = 0;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	uint32_t gameContext = LOAD32(kGameContextSlot);

	// The Players object (first element of the array behind +88 of the context's object at +12) holds
	// two entity handles, at +104 and +112, each with its control block pointer 4 bytes further.
	// Returns the entity the handle at handleOffset refers to, or 0; a handle whose control block
	// refers to nothing is released.
	auto entityFromHandle = [&](uint32_t handleOffset) -> uint32_t {
		uint32_t arrayBegin = LOAD32(LOAD32(LOAD32(gameContext + 12) + 88) + 4);
		callerR9 = arrayBegin;
		uint32_t players = LOAD32(arrayBegin);
		uint32_t control = LOAD32(players + handleOffset + 4);
		if (control == 0)
			return 0;
		uint32_t target = LOAD32(control);
		if (target != 0)
			return target;
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = callerR4;
		ctx.r5.u64 = gameContext;
		ctx.r6.u64 = callerR6;
		ctx.r7.u64 = callerR7;
		ctx.r8.u64 = callerR8;
		ctx.r9.u64 = arrayBegin;
		ctx.r10.u64 = 0;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		EntityHandle_Release(ctx, base, uint64_t(players) + handleOffset);
		callerR4 = ctx.r4.u64;
		callerR6 = ctx.r6.u64;
		callerR7 = ctx.r7.u64;
		callerR8 = ctx.r8.u64;
		callerR9 = ctx.r9.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
		gameContext = LOAD32(kGameContextSlot);
		return 0;
	};

	// `current` is an object with its entity at +4: the player, or, while the checks below pass, the
	// component of type 33 of the first handle's entity.
	uint32_t current = playerAddr;
	uint32_t firstEntity;
	uint32_t secondEntity;
	while (true) {
		firstEntity = entityFromHandle(104);
		secondEntity = entityFromHandle(112);
		callerR4 = secondEntity;

		if (int32_t(LOAD32(LOAD32(gameContext + 12) + 284)) != 2)
			break;
		if (LOAD32(current + 4) != secondEntity)
			break;
		if (firstEntity == 0 || (LOAD8(firstEntity + 144) & 64) == 0)
			break;
		if (((LOAD32(firstEntity + 40) >> 1) & 1) == 0)
			break;

		// Component of type 33 from the entity's sorted (type, component) pairs at +72..+76: the byte
		// table at +140, when present, gives its index; otherwise a lower bound on signed types finds it.
		uint32_t next;
		uint32_t pairs = LOAD32(firstEntity + 72);
		uint32_t slots = LOAD32(firstEntity + 140);
		if (slots != 0) {
			next = LOAD32(pairs + ((uint32_t)LOAD8(slots + 33) << 3) + 4);
		} else {
			uint32_t end = LOAD32(firstEntity + 76);
			callerR6 = end;
			STORE32(stack + 80, 0);
			uint32_t byteCount = end - pairs;
			STORE32(stack + 84, pairs);
			flags.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			int32_t count = (int32_t)byteCount >> 3;
			compare0.compare<int32_t>(count, 0, flags);
			uint32_t pos = pairs;
			if (count > 0) {
				// halving a positive count clears the carry
				flags.ca = 0;
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					pos += step;
					bool below = (int32_t)LOAD32(pos) < 33;
					callerR7 = below ? 1 : 0;
					callerR8 = step;
					callerR9 = (uint32_t)half;
					if (below) {
						count = count - half - 1;
						pos += 8;
					} else {
						pos -= step;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, pos);
			}
			uint32_t match;
			if (pos != end && (int32_t)LOAD32(pos) <= 33) {
				STORE64(stack + 88, LOAD64(stack + 80));
				match = LOAD32(stack + 92);
			} else {
				match = end;
			}
			next = LOAD32(match + 4);
		}
		if (next == 0)
			break;
		current = next;
	}

	uint64_t result = 0;
	uint32_t entity = LOAD32(current + 4);
	if (entity != 0) {
		uint32_t entityPlayerFlag = LOAD8(entity + 144) & 64;
		callerR9 = entityPlayerFlag;
		if (entityPlayerFlag != 0 && (entity == firstEntity || entity == secondEntity))
			result = LOAD8(current + 25);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r4-r10, cr0 and xer.ca after the call
	ctx.r4.u64 = callerR4;
	ctx.r5.u64 = gameContext;
	ctx.r6.u64 = callerR6;
	ctx.r7.u64 = callerR7;
	ctx.r8.u64 = callerR8;
	ctx.r9.u64 = callerR9;
	ctx.r10.u64 = entity;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(4, sub_821EE210, 0x821EE210) { ctx.r3.u64 = n_sub_821EE210(ctx, base, ctx.r3.u32); }

uint64_t CECPlayer_GetClassName(CpuState& ctx, uint8_t* base, uint64_t outName) {
	constexpr int32_t str_TXT_820A84C8_B_ = int32_t(0x820A84C8);
	if (!UseLiftedCode(20, 0x823BE790)) { ctx.r3.u64 = outName; __imp__sub_823BE790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823BE790);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, outName, str_TXT_820A84C8_B_, -1);
	return outName;
}
PROMOTED_ENTRY(20, sub_823BE790, 0x823BE790) { ctx.r3.u64 = CECPlayer_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_823BEE20(CpuState& ctx, uint8_t* base, uint64_t playerAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(21, 0x823BEE20)) { ctx.r3.u64 = playerAddr; ctx.r4.u64 = deleteFlags; __imp__sub_823BEE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823BEE20);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;  // state the callee may pass on
	n_sub_823BEE70(ctx, base, playerAddr);
	if (deleteFlags & 0x1)
		HandleTarget_Free(ctx, base, playerAddr);
	return playerAddr;
}
PROMOTED_ENTRY(21, sub_823BEE20, 0x823BEE20) { ctx.r3.u64 = n_sub_823BEE20(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_823BF518  [128 bytes]
uint32_t CECPlayer_GetFlag1A(CpuState& ctx, uint8_t* base, uint32_t playerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823BF518)) { ctx.r3.u64 = playerAddr; __imp__sub_823BF518(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823BF518);
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 96);

	// The Players object (first element of the array behind +88 of the context's object at +12) holds
	// its second entity handle at +112, with the handle's control block pointer at +116.
	uint32_t gameContext = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t arrayHolder = LOAD32(LOAD32(gameContext + 12) + 88);
	uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	uint32_t players = LOAD32(arrayBegin);
	uint32_t control = LOAD32(players + 116);

	uint64_t callerR8 = arrayBegin;  // callers read r8 after the call
	uint32_t secondEntity = 0;
	if (control != 0) {
		secondEntity = LOAD32(control);
		if (secondEntity == 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			EntityHandle_Release(ctx, base, uint64_t(players) + 112);
			callerR8 = ctx.r8.u64;
		}
	}

	uint32_t result = 0;
	if (player->m_4 != secondEntity)
		result = player->m_1A;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = callerR8;
	return result;
}
PROMOTED_ENTRY(21, sub_823BF518, 0x823BF518) { ctx.r3.u64 = CECPlayer_GetFlag1A(ctx, base, ctx.r3.u32); }

uint64_t n_sub_823C0E78(CpuState& ctx, uint8_t* base, uint64_t playerAddr, uint64_t forwardedArg) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823C0E78)) { ctx.r3.u64 = playerAddr; ctx.r6.u64 = forwardedArg; __imp__sub_823C0E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C0E78);
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint64_t abilityFlags = CECPlayer_GetCombinedAbilityFlags(ctx, base, playerAddr);

	uint32_t gameContext = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t contextData = LOAD32(gameContext + 12);
	uint32_t contextMode = LOAD32(contextData + 284);

	// The same choice as CECPlayer_GetCombinedAbilityFlags makes: m_20 set, or, in context mode 1, m_21 set.
	bool useSecond = player->m_20 != 0 || ((int32_t)contextMode == 1 && player->m_21 != 0);
	uint32_t selectedValue = useSecond ? player->m_84 : player->m_80;

	// state the callee may pass on
	ctx.r8.u64 = contextMode;
	uint64_t result = n_sub_823C01F8(ctx, base, playerAddr, selectedValue, abilityFlags, forwardedArg);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823C0E78, 0x823C0E78) { ctx.r3.u64 = n_sub_823C0E78(ctx, base, ctx.r3.u64, ctx.r6.u64); }

uint64_t CECPlayer_GetCombinedAbilityFlags(CpuState& ctx, uint8_t* base, uint32_t playerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823C0F08)) { ctx.r3.u64 = playerAddr; __imp__sub_823C0F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C0F08);
	uint32_t stack = ctx.r1.u32;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);

	stack = PushStackFrame(base, stack, 112);

	// The tree at +172 is walked when m_20 is set, or, in context mode 1, when m_21 is set; otherwise
	// the tree at +160.
	uint32_t gameContext = LOAD32(uint32_t(g_83490000) + 26912);
	int32_t contextMode = int32_t(LOAD32(LOAD32(gameContext + 12) + 284));
	bool useSecondTree = player->m_20 != 0 || (contextMode == 1 && player->m_21 != 0);
	uint32_t tree = useSecondTree ? playerAddr + 172 : playerAddr + 160;

	// Red-black tree iterator at stack+80: the tree it belongs to, then its current node. The tree's head
	// node is at +4; the head's first link is the first node.
	uint32_t head = LOAD32(tree + 4);
	uint32_t iteratorTree = tree;
	STORE32(stack + 80, iteratorTree);
	uint32_t node = LOAD32(head);
	STORE32(stack + 84, node);

	uint64_t combinedFlags = 0;
	for (;;) {
		uint32_t end = LOAD32(tree + 4);
		// iterator checks: it must belong to this tree, and must not be dereferenced at the head
		if (iteratorTree == 0 || iteratorTree != tree) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == end)
			break;

		if (iteratorTree == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(iteratorTree + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		combinedFlags |= LOAD32(node + 16);
		ctx.r1.u64 = stack;
		RbTree_IteratorIncrement(ctx, base, stack + 80);
		node = LOAD32(stack + 84);
		iteratorTree = LOAD32(stack + 80);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return combinedFlags;
}
PROMOTED_ENTRY(21, sub_823C0F08, 0x823C0F08) { ctx.r3.u64 = CECPlayer_GetCombinedAbilityFlags(ctx, base, ctx.r3.u32); }

uint64_t n_sub_823C1C70(CpuState& ctx, uint8_t* base, uint64_t playerAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(21, 0x823C1C70)) { ctx.r3.u64 = playerAddr; ctx.r5.u64 = arg2; ctx.r6.u64 = arg3; __imp__sub_823C1C70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C1C70);
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t componentBefore = player->m_4;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r5.u64 = arg2;
	ctx.r6.u64 = arg3;
	n_sub_82392C88(ctx, base, componentBefore, playerAddr);

	// r6, r7 and xer.ca as the calls leave them are handed on to n_sub_823C8620
	uint64_t r6Value = ctx.r6.u64;
	PPCXERRegister flags = ctx.xer;

	uint32_t component = player->m_4;
	STORE8(component + 144, (uint8_t)(LOAD8(component + 144) & 0xFB));
	// the original reads m_4 again after the byte store
	component = player->m_4;

	// r7/r8 as the type-31 lookup below leaves them; n_sub_82483858 receives both
	uint32_t r8Value = LOAD32(component + 36);
	uint64_t r7Value = r8Value >> 31;
	if (r7Value != 0) {
		// component+72 is a sorted array of {int32_t type; uint32_t value;} pairs; the byte table at
		// component+140, when present, maps a type straight to its slot.
		uint32_t value;
		uint32_t slotTable = LOAD32(component + 140);
		if (slotTable != 0) {
			uint32_t slot = LOAD8(slotTable + 31);
			value = LOAD32(LOAD32(component + 72) + (slot << 3) + 4);
		} else {
			uint32_t entry = LOAD32(component + 72);
			uint32_t end = LOAD32(component + 76);
			STORE32(stack + 80, 0);
			int32_t remaining = (int32_t)(end - entry);
			STORE32(stack + 84, entry);
			flags.ca = (remaining < 0) & ((remaining & 0x7) != 0);
			remaining >>= 3;

			if (remaining > 0) {
				do {
					flags.ca = (remaining < 0) & ((remaining & 0x1) != 0);
					int32_t half = remaining >> 1;
					uint32_t midOffset = (uint32_t)half << 3;
					uint32_t mid = entry + midOffset;
					r8Value = midOffset;
					r7Value = ((int32_t)LOAD32(mid) < 31) ? 1 : 0;
					if (r7Value != 0) {
						entry = mid + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, entry);
			}

			if (entry != end && (int32_t)LOAD32(entry) <= 31) {
				// the original re-stores the spilled iterator pair unchanged
				STORE64(stack + 80, LOAD64(stack + 80));
				value = LOAD32(entry + 4);
			} else {
				value = LOAD32(end + 4);
			}
		}

		// state the callee may pass on
		ctx.r8.u64 = r8Value;
		ctx.xer.ca = flags.ca;
		n_sub_82483858(ctx, base, value, playerAddr + 356, playerAddr + 12, 0);
		r6Value = ctx.r6.u64;
		r7Value = ctx.r7.u64;
		flags.ca = ctx.xer.ca;
	}

	ctx.xer.ca = flags.ca;
	uint64_t result = n_sub_823C8620(ctx, base, playerAddr, r6Value, r7Value);
	if ((uint32_t)arg2 != 0) {
		player->m_2C = uint8_t(1);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823C1C70, 0x823C1C70) { ctx.r3.u64 = n_sub_823C1C70(ctx, base, ctx.r3.u64, ctx.r5.u64, ctx.r6.u64); }

uint32_t n_sub_823C2610(CpuState& ctx, uint8_t* base, uint32_t playerAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_8349B180 = int32_t(0x8349B180);
	if (!UseLiftedCode(21, 0x823C2610)) { ctx.r3.u64 = playerAddr; __imp__sub_823C2610(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823C2610);
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;

	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 304);
	ctx.r1.u64 = stack;

	uint32_t entity = player->m_4;

	// Register state the lookups leave behind: r5/r6 the array end loaded by the type-24/type-49
	// search, r7/r8 a search's last comparison and step, cr0 the sign of its element count.
	// n_sub_822C6940 receives it, and the early returns leave it for callers.
	uint64_t r5Value = ctx.r5.u64;
	uint64_t r6Value = entity;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	PPCCRRegister cr0Value = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	auto putLookupState = [&]() {
		ctx.r5.u64 = r5Value;
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.cr0 = cr0Value;
		ctx.xer.ca = flags.ca;
	};

	STORE32(stack + 80, 0);

	// entity+72 is a sorted flat array of {int32_t type; uint32_t value;} pairs. When the
	// table at entity+140 exists, it maps a type straight to the array slot instead.
	auto findComponent = [&](int32_t type, uint64_t& endRegister) -> uint32_t {
		uint32_t typeTable = LOAD32(entity + 140);
		if (typeTable != 0) {
			uint32_t index = (uint32_t)LOAD8(typeTable + (uint32_t)type) << 3;
			return LOAD32(LOAD32(entity + 72) + index + 4);
		}
		uint32_t first = LOAD32(entity + 72);
		uint32_t last = LOAD32(entity + 76);
		endRegister = last;
		STORE32(stack + 80, 0);
		STORE32(stack + 84, first);
		int32_t span = (int32_t)(last - first);
		flags.ca = (span < 0) & ((span & 0x7) != 0);
		int32_t count = span >> 3;
		cr0Value.compare<int32_t>(count, 0, flags);
		if (count > 0) {
			// shifting a positive count leaves no carry
			flags.ca = 0;
			do {
				int32_t step = count >> 1;
				uint32_t stepBytes = (uint32_t)step << 3;
				uint32_t mid = first + stepBytes;
				r8Value = stepBytes;
				r7Value = ((int32_t)LOAD32(mid) < type) ? 1 : 0;
				if (r7Value != 0) {
					first = mid + 8;
					count = count - step - 1;
				} else {
					count = step;
				}
			} while (count > 0);
			STORE32(stack + 84, first);
		}
		if (first != last && (int32_t)LOAD32(first) <= type) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(last + 4);
	};

	uint32_t result = 0;
	bool haveBoth = false;
	uint32_t value49 = 0;
	if (LOAD8(entity + 36) & 1) {
		result = findComponent(24, r5Value);
		if ((LOAD32(entity + 40) >> 17) & 1) {
			value49 = findComponent(49, r6Value);
			haveBoth = true;
		}
	}
	if (!haveBoth) {
		stack = PopStackFrame(stack, 304);
		ctx.r1.u64 = stack;
		// callers read these registers after the call
		putLookupState();
		return result;
	}

	STORE32(stack + 80, 0);
	// state the callee may pass on
	putLookupState();
	result = n_sub_822C6940(ctx, base, result, g_8349B180);

	bool hasHandle = (result & 0xFF) == 0;
	bool proceed = true;
	// r9 at the vtable+72 call: 0, or what EntityHandle_Release left
	uint64_t r9Value = 0;
	if (hasHandle) {
		uint32_t target112 = LOAD32(LOAD32(value49) + 112);
		callTarget.u64 = target112;
		ctx.r3.u64 = stack + 88;
		ctx.r4.u64 = value49;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = n_sub_827E7968(ctx, base, ctx.r3.u64, stack + 80);
		proceed = (result & 0xFF) != 0;

		STORE32(stack + 88, g_820F1664);
		// state the callee may pass on
		result = EntityHandle_Release(ctx, base, stack + 88);
		r9Value = ctx.r9.u64;
		STORE32(stack + 92, 0);
	}

	if (proceed) {
		uint32_t target72 = LOAD32(LOAD32(value49) + 72);
		callTarget.u64 = target72;
		ctx.r3.u64 = value49;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// the vtable pointer is read again after the call
		uint32_t value49Vtable = LOAD32(value49);
		ctx.r4.u64 = uint32_t(g_8349B180);  // state the callee may pass on
		uint64_t holder = n_sub_827DBA50(ctx, base, stack + 128, 1);

		uint32_t target64 = LOAD32(value49Vtable + 64);
		callTarget.u64 = target64;
		ctx.r3.u64 = stack + 104;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		STORE32(stack + 104, g_820F1664);
		EntityHandle_Release(ctx, base, stack + 104);
		STORE32(stack + 108, 0);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 240);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 236);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 212);
		result = HandleHolder_Dtor(ctx, base, stack + 128);
	}

	stack = PopStackFrame(stack, 304);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823C2610, 0x823C2610) { ctx.r3.u64 = n_sub_823C2610(ctx, base, ctx.r3.u32); }

uint64_t SharedHandleList_EraseMatching(CpuState& ctx, uint8_t* base, uint64_t ownerAddr, uint64_t handleIdAddr) {
	if (!UseLiftedCode(21, 0x823C4D58)) { ctx.r3.u64 = ownerAddr; ctx.r4.u64 = handleIdAddr; __imp__sub_823C4D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C4D58);
	uint32_t stack = ctx.r1.u64;
	// r4 and r7-r9 as the loop leaves them: each erase call receives r7-r9, and callers read all four
	uint64_t result = ownerAddr;
	uint64_t r4Value = handleIdAddr;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t iterContainer = ctx.r8.u64;
	uint64_t iterEnd = ctx.r9.u64;
	stack = PushStackFrame(base, stack, 128);

	uint32_t handleIdPtr = (uint32_t)handleIdAddr;
	if (LOAD32(handleIdPtr) != 0) {
		uint64_t handleList = ownerAddr + 272;
		uint32_t node = LOAD32((uint32_t)ownerAddr + 276);
		uint64_t iterator;
		iterContainer = handleList;
		STORE32(stack + 80, (uint32_t)iterContainer);

	advance_iterator:
		node = LOAD32(node);
		STORE32(stack + 84, node);
		iterator = LOAD64(stack + 80);
		for (;;) {
			uint32_t listEnd = LOAD32((uint32_t)handleList + 4);
			if ((uint32_t)iterContainer == 0 || (uint32_t)iterContainer != (uint32_t)handleList) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == listEnd) break;
			if ((uint32_t)iterContainer == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			iterEnd = LOAD32((uint32_t)iterContainer + 4);
			if (node == (uint32_t)iterEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint32_t entry = LOAD32(node + 8);
			uint32_t handle = LOAD32(entry + 4);
			// entries with a null handle are erased too, through a different result slot
			uint32_t eraseResultSlot = stack + 96;
			if (handle != 0) {
				r7Value = LOAD32(handleIdPtr);
				if (handle != (uint32_t)r7Value) {
					if (node == (uint32_t)iterEnd) {
						ctx.r1.u64 = stack;
						ppc_trap(ctx, base, 22);
					}
					goto advance_iterator;
				}
				eraseResultSlot = stack + 88;
			}

			// state the callee may pass on
			ctx.r1.u64 = stack;
			result = SharedHandleList_Erase(ctx, base, eraseResultSlot, handleList, iterator);
			r4Value = ctx.r4.u64;
			r7Value = ctx.r7.u64;
			iterEnd = ctx.r9.u64;
			iterator = LOAD64((uint32_t)result);
			STORE64(stack + 80, iterator);
			node = LOAD32(stack + 84);
			iterContainer = LOAD32(stack + 80);
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = r4Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = iterContainer;
	ctx.r9.u64 = iterEnd;
	return result;
}
PROMOTED_ENTRY(21, sub_823C4D58, 0x823C4D58) { ctx.r3.u64 = SharedHandleList_EraseMatching(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_823C5D18(CpuState& ctx, uint8_t* base, uint32_t playerAddr, uint64_t expressionId) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823C5D18)) { ctx.r3.u64 = playerAddr; ctx.r4.u64 = expressionId; __imp__sub_823C5D18(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823C5D18);
	uint32_t stack = ctx.r1.u64;
	// r4 and r6-r8 as this function leaves them; callers read them after the call
	uint64_t r4Value = expressionId;
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t result = 1;
	if ((int32_t)expressionId >= 4 && (int32_t)expressionId <= 12) {
		result = 0;

		uint32_t managerObj = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
		uint32_t holder = LOAD32(LOAD32(LOAD32(managerObj + 88) + 4) + 8);
		uint32_t holderInner = LOAD32(holder + 4);
		uint32_t target = LOAD32(holderInner + 12);

		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = expressionId;
		uint32_t checkResult = n_sub_82607090(ctx, base, target);
		r4Value = ctx.r4.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		r6Value = checkResult & 0xFF;

		if (r6Value != 0) {
			// the same chain is read again after the call
			uint32_t managerObj2 = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
			r8Value = LOAD32(LOAD32(LOAD32(managerObj2 + 88) + 4) + 8);
			r7Value = LOAD32((uint32_t)r8Value + 4);
			uint32_t node = LOAD32(LOAD32((uint32_t)r7Value + 12) + 28);

			bool blocked = node != 0 && LOAD32(node + 4) != 0;
			if (!blocked) {
				uint32_t link = player->m_14;
				uint32_t handle = (link != 0) ? LOAD32(link + 36) : 0xFFFFFFFFu;

				// state the callee may pass on
				uint32_t check2 = n_sub_823023E0(ctx, base, handle);
				r4Value = ctx.r4.u64;
				r6Value = ctx.r6.u64;
				r7Value = ctx.r7.u64;
				r8Value = ctx.r8.u64;

				if ((check2 & 0xFF) == 0) {
					result = (player->m_24 != 0) ? 1u : 0u;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = r4Value;
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	return result;
}
PROMOTED_ENTRY(21, sub_823C5D18, 0x823C5D18) { ctx.r3.u64 = n_sub_823C5D18(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t n_sub_823C8620(CpuState& ctx, uint8_t* base, uint64_t playerAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823C8620)) { ctx.r3.u64 = playerAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_823C8620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C8620);
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t globalBase = uint32_t(g_83490000);
	uint32_t globalManager = LOAD32(globalBase + 26912);
	uint32_t managerObj = LOAD32(globalManager + 12);
	uint32_t luaState = LOAD32(managerObj + 120);
	uint32_t luaThread = LOAD32(luaState + 4);
	uint32_t luaValue = LOAD32(luaThread);

	uint32_t globalTableRef = stack + 88;
	ctx.r1.u64 = stack;
	ctx.r8.u64 = luaThread;
	ctx.r9.u64 = luaState;
	LuaRef_GetGlobalTable(ctx, base, globalTableRef, luaValue, arg2, arg3);

	uint32_t fieldRef = stack + 80;
	ctx.r7.s64 = str_TXT_820B0000_B_;
	LuaTableRef_GetField(ctx, base, fieldRef, globalTableRef, int64_t(str_TXT_820B0000_B_) - 12332);

	uint64_t mapTree = 0;
	uint64_t allocated = operator_new(ctx, base, 24);
	if ((uint32_t)allocated != 0) {
		mapTree = MapTree_InitEmpty(ctx, base, allocated);
	}

	SharedPtr_ResetWithPointerF(ctx, base, playerAddr + 340, mapTree);

	HeroCombatBalance_ParseLuaTable(ctx, base, player->m_154, fieldRef);

	SharedHandle_Release(ctx, base, fieldRef);
	uint64_t result = SharedHandle_Release(ctx, base, globalTableRef);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823C8620, 0x823C8620) { ctx.r3.u64 = n_sub_823C8620(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_823C8810(CpuState& ctx, uint8_t* base, uint32_t playerAddr, uint64_t handlePtr) {
	if (!UseLiftedCode(21, 0x823C8810)) { ctx.r3.u64 = playerAddr; ctx.r4.u64 = handlePtr; __imp__sub_823C8810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C8810);
	uint32_t stack = ctx.r1.u64;
	const uint32_t msrBits = ctx.r13.u32;
	// r9, r10 and cr0 as the reference-taking loop leaves them; n_sub_8238F350 receives them
	uint64_t lockState = ctx.r9.u64;
	PPCCRRegister storeResult = ctx.cr0;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	stack = PushStackFrame(base, stack, 112);

	// Copy the shared handle (value, reference counter address) into the frame and take a reference.
	uint32_t refCountAddr = LOAD32((uint32_t)handlePtr + 4);
	uint32_t handleValue = LOAD32((uint32_t)handlePtr);
	uint64_t r10Value = handleValue;
	STORE32(stack + 84, refCountAddr);
	STORE32(stack + 80, handleValue);
	if (refCountAddr != 0) {
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = msrBits & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
			r10Value = (uint64_t)__builtin_bswap32(ctx.reserved.u32) + 1;
			storeResult.lt = 0;
			storeResult.gt = 0;
			storeResult.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)r10Value));
			storeResult.so = ctx.xer.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!storeResult.eq);
	}

	uint32_t linkedObject = player->m_14;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.cr0 = storeResult;
	n_sub_8238F350(ctx, base, linkedObject, stack + 80);
	uint64_t result = SharedHandle_Release(ctx, base, handlePtr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823C8810, 0x823C8810) { ctx.r3.u64 = n_sub_823C8810(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t n_sub_823C88F0(CpuState& ctx, uint8_t* base, uint64_t playerAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823C88F0)) { ctx.r3.u64 = playerAddr; ctx.r4.u64 = arg2; __imp__sub_823C88F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C88F0);

	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	uint32_t playerEntity = player->m_14;
	if (playerEntity == 0) {
		// callers read these registers after the call
		ctx.r4.u64 = arg2;
		ctx.r5.u64 = arg2;
		ctx.r10.u64 = 0;
		return playerAddr;
	}

	uint32_t manager = LOAD32(0x83496920u);
	uint32_t globalFlag = 0;
	if (manager != 0) {
		globalFlag = LOAD8(uint32_t(g_83490000) + 26821);
	}
	if (globalFlag == 0) {
		// callers read these registers after the call
		ctx.r4.u64 = arg2;
		ctx.r5.u64 = arg2;
		ctx.r9.u64 = manager;
		ctx.r10.u64 = playerEntity;
		return playerAddr;
	}

	uint32_t entityParam = LOAD32(playerEntity + 36);
	uint32_t managerHandle = LOAD32(LOAD32(manager + 12) + 128);
	// state the callee may pass on
	return n_sub_8233A810(ctx, base, managerHandle, entityParam, arg2);
}
PROMOTED_ENTRY(21, sub_823C88F0, 0x823C88F0) { ctx.r3.u64 = n_sub_823C88F0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_823CC6F8(CpuState& ctx, uint8_t* base, uint64_t playerAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820A8B7C_B_ = int32_t(0x820A8B7C);
	constexpr int32_t str_TXT_820A8B98_B_ = int32_t(0x820A8B98);
	constexpr int32_t str_TXT_820A8BB4_B_ = int32_t(0x820A8BB4);
	constexpr int32_t str_TXT_820A8BD0_B_ = int32_t(0x820A8BD0);
	constexpr int32_t str_TXT_820A8BEC_B_ = int32_t(0x820A8BEC);
	constexpr int32_t str_TXT_820AD538_B_ = int32_t(0x820AD538);
	constexpr int32_t str_TXT_820AD544_B_ = int32_t(0x820AD544);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t TXT_8349783C_G_ = int32_t(0x8349783C);
	if (!UseLiftedCode(21, 0x823CC6F8)) { ctx.r3.u64 = playerAddr; __imp__sub_823CC6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823CC6F8);
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);

	stack = PushStackFrame(base, stack, 128);

	// the sub-object at player+16, or 0 for a null player (a base-class cast)
	uint64_t playerSubobject = (uint32_t)playerAddr == 0 ? 0 : playerAddr + 16;
	uint32_t component = LOAD32(uint32_t(player->m_4) + 124);
	ctx.r1.u64 = stack;
	n_sub_8229E750(ctx, base, component, playerAddr + 368, playerSubobject);

	// m_36 is cleared only when the hash reached through holderInner+36 equals the hash of the
	// Marcus Memorial demon-door path.
	player->m_36 = uint8_t(1);
	uint32_t globalBase = uint32_t(g_83490000);
	uint32_t manager = LOAD32(LOAD32(globalBase + 26912) + 12);
	uint32_t holder = LOAD32(LOAD32(LOAD32(manager + 88) + 4) + 8);
	// r6 at the first string construction below
	uint32_t r6Value = holder;
	if (LOAD32(LOAD32(holder + 4) + 36) != 0) {
		uint32_t holderInner = LOAD32(holder + 4);
		ctx.r3.u64 = holderInner;  // state the callee may pass on
		uint32_t memorialHash = Path_NormalizeAndHash(ctx, base, holderInner + 20, TXT_8349783C_G_);

		// the chain is read again after the call
		uint32_t managerAfter = LOAD32(LOAD32(globalBase + 26912) + 12);
		r6Value = managerAfter;
		uint32_t holderInnerAfter = LOAD32(LOAD32(LOAD32(LOAD32(managerAfter + 88) + 4) + 8) + 4);
		uint32_t currentHash = LOAD32(LOAD32(LOAD32(holderInnerAfter + 36) + 4) + 180);
		if (currentHash == memorialHash) {
			player->m_36 = uint8_t(0);
		}
	}

	// m_90, m_94 and m_98 start from two constants of the game data
	ctx.fpscr.disableFlushMode();
	double initialM90 = double(LOAD_F32(uint32_t(g_820A0000) - 27456));
	player->m_90 = float(initialM90);
	double initialM98 = double(LOAD_F32(uint32_t(g_820A0000) - 27456 - 12));
	player->m_98 = float(initialM98);
	player->m_94 = float(initialM98);

	uint32_t tempCharString = stack + 80;
	uint32_t tempRecordRef = stack + 88;

	// n_sub_82297F88 gets str_TXT_820AD538_B_ with m_98, then str_TXT_820AD544_B_ with the initial m_90 minus m_98
	ctx.r6.u64 = r6Value;  // state the callee may pass on
	CCharString_ConstructFromCStr(ctx, base, tempCharString, str_TXT_820AD538_B_, -1);
	ctx.fpscr.disableFlushMode();
	n_sub_82297F88(ctx, base, LOAD32(globalBase + 27596), tempCharString, double(player->m_98));
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempCharString);

	CCharString_ConstructFromCStr(ctx, base, tempCharString, str_TXT_820AD544_B_, -1);
	ctx.fpscr.disableFlushMode();
	n_sub_82297F88(ctx, base, LOAD32(globalBase + 27596), tempCharString,
	               double(float(initialM90 - double(player->m_98))));
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempCharString);

	// For each of these dog command and item names whose game-database record exists, erase the
	// matching entries from the player's shared-handle list.
	constexpr int32_t dogItemNames[] = {
		str_TXT_820A8B7C_B_,
		str_TXT_820A8B98_B_,
		str_TXT_820A8BB4_B_,
		str_TXT_820A8BD0_B_,
		str_TXT_820A8BEC_B_,
	};
	uint64_t result = 0;
	bool firstItem = true;
	for (int32_t itemName : dogItemNames) {
		CCharString_ConstructFromCStr(ctx, base, tempCharString, itemName, -1);
		GameDBRecordRef_Construct(ctx, base, tempRecordRef, tempCharString);
		uint32_t record = LOAD32(tempRecordRef);
		if (record != 0) {
			// the original also hands the record to the first erase in r6
			if (firstItem) {
				ctx.r6.u64 = record;
			}
			SharedHandleList_EraseMatching(ctx, base, playerAddr, tempRecordRef);
		}
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempCharString);
		firstItem = false;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823CC6F8, 0x823CC6F8) { ctx.r3.u64 = n_sub_823CC6F8(ctx, base, ctx.r3.u64); }

// sub_823CC998  [16 bytes]
uint64_t n_sub_823CC998(CpuState& ctx, uint8_t* base, uint64_t playerAddr) {
	if (!UseLiftedCode(21, 0x823CC998)) { ctx.r3.u64 = playerAddr; __imp__sub_823CC998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823CC998);
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);
	uint32_t physicsCharacter = LOAD32((uint32_t)player->m_4 + 124);
	return n_sub_8229E5F8(ctx, base, physicsCharacter, playerAddr + 368);
}
PROMOTED_ENTRY(21, sub_823CC998, 0x823CC998) { ctx.r3.u64 = n_sub_823CC998(ctx, base, ctx.r3.u64); }

uint64_t n_sub_823CC9A8(CpuState& ctx, uint8_t* base, uint64_t playerAddr, uint64_t forwardedArg) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823CC9A8)) { ctx.r3.u64 = playerAddr; ctx.r6.u64 = forwardedArg; __imp__sub_823CC9A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823CC9A8);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CECPlayer* player = GameObject<CECPlayer>(base, playerAddr);

	stack = PushStackFrame(base, stack, 160);

	if (player->m_37 != 0) {
		ctx.r1.u64 = stack;
		n_sub_823C0E78(ctx, base, playerAddr, forwardedArg);
		forwardedArg = ctx.r6.u64;
		player->m_37 = uint8_t(0);
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r6.u64 = forwardedArg;
	CECPlayer_PruneEntityList(ctx, base, playerAddr);

	n_sub_823CD340(ctx, base, playerAddr);
	n_sub_823CDD28(ctx, base, playerAddr);
	n_sub_823CEA38(ctx, base, playerAddr);

	if (player->m_15C != 0) {
		// The first virtual call is handed the stack block at +80. Its 16 bytes are copied to +112, and a byte
		// rearrangement of them (permute masks at tableBase - 28192 and tableBase - 28176) is written back to
		// +80; the second virtual call gets +112 as its argument and +80 in r9.
		int32_t tableBase = g_820A0000;
		uint64_t argBlockA = (int64_t)(uint64_t)stack + 80;
		uint32_t physicsCharacter = LOAD32(uint32_t(player->m_4) + 124);
		uint32_t physicsVtable = LOAD32(physicsCharacter);
		uint32_t physicsFn = LOAD32(physicsVtable + 64);

		callTarget.u64 = (uint64_t)physicsFn;
		ctx.r3.u64 = argBlockA;
		ctx.r4.u64 = physicsCharacter;
		ctx.r9.u64 = physicsFn;
		ctx.r10.u64 = physicsVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		PPCVRegister vecWork{};
		PPCVRegister vecResult{};
		PPCVRegister vecMask{};
		PPCVRegister vecPerm{};
		PPCVRegister vecShiftHi{};
		PPCVRegister vecShiftLo{};

		uint64_t argBlockB = (int64_t)(uint64_t)stack + 112;
		uint64_t permTable = (int64_t)tableBase - 28176;

		SET_V8(vecWork, VLOAD(uint32_t((int64_t)(uint64_t)stack + 80) & ~0xF));
		VSTORE(uint32_t((int64_t)(uint64_t)stack + 96) & ~0xF, V8(vecWork));

		scratch.u32 = uint32_t((int64_t)(uint64_t)stack + 100);
		SET_V8(vecShiftLo, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));

		VSTORE((uint32_t)argBlockB & ~0xF, V8(vecWork));

		SET_V8(vecMask, VLOAD(uint32_t((int64_t)tableBase - 28192) & ~0xF));

		scratch.u32 = uint32_t((int64_t)(uint64_t)stack + 120);
		SET_V8(vecShiftHi, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));

		SET_V8(vecPerm, rex::ppc::simde_mm_perm_epi8_(V8(vecWork), V8(vecShiftHi), V8(vecMask)));

		SET_V8(vecWork, VLOAD((uint32_t)permTable & ~0xF));

		uint32_t target = player->m_15C;
		SET_V8(vecResult, rex::ppc::simde_mm_perm_epi8_(V8(vecPerm), V8(vecShiftLo), V8(vecWork)));
		VSTORE((uint32_t)argBlockA & ~0xF, V8(vecResult));

		uint32_t targetVtable = LOAD32(target);
		uint32_t targetFn = LOAD32(targetVtable);

		callTarget.u64 = (uint64_t)targetFn;
		ctx.r3.u64 = target;
		ctx.r4.u64 = argBlockB;
		ctx.r5.s64 = tableBase;
		ctx.r6.u64 = targetFn;
		ctx.r7.u64 = targetVtable;
		ctx.r8.u64 = permTable;
		ctx.r9.u64 = argBlockA;
		ctx.r10.s64 = tableBase;
		ctx.v1 = vecResult;
		ctx.v7 = vecMask;
		ctx.v11 = vecPerm;
		ctx.v12 = vecShiftHi;
		ctx.v13 = vecShiftLo;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	CECPlayer_UpdateRangedWeaponsAutoHeal(ctx, base, playerAddr);

	n_sub_823D1830(ctx, base, playerAddr);

	// Resolve the entity handle at +104 of the first entry of the player list (the same steps as
	// EntityHandle_Get) and compare it with this player's entity (m_4).
	uint32_t globals = uint32_t(g_83490000);
	uint32_t playerHolder = LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 88);
	uint64_t playerList = LOAD32(playerHolder + 4);
	uint32_t playerEntity = player->m_4;
	uint32_t firstPlayer = LOAD32((uint32_t)playerList);
	// n_sub_82525EF0 at the end takes r3 from the state: this handle's address unless a later call's result replaces it
	uint64_t lastR3 = (int64_t)(uint64_t)firstPlayer + 104;
	// r8 handed to n_sub_823CCD48: the player list, or what EntityHandle_Release left in r8
	uint64_t r8Value = playerList;
	uint32_t controlBlock = LOAD32(firstPlayer + 108);

	uint32_t firstPlayerEntity = 0;
	if (controlBlock != 0) {
		uint32_t entity = LOAD32(controlBlock);
		if (entity != 0) {
			firstPlayerEntity = entity;
		} else {
			// state the callee may pass on
			ctx.r8.u64 = r8Value;
			ctx.r9.u64 = playerHolder;
			ctx.r10.u64 = entity;
			lastR3 = EntityHandle_Release(ctx, base, lastR3);
			r8Value = ctx.r8.u64;
		}
	}

	if (playerEntity == firstPlayerEntity) {
		ctx.r8.u64 = r8Value;
		n_sub_823CCD48(ctx, base, playerAddr);

		n_sub_823CE660(ctx, base, playerAddr, ctx.r8.u64);

		lastR3 = n_sub_823CF1E8(ctx, base, playerAddr, ctx.r8.u64);
	}

	// The value m_3C caches: 1 while m_3B is set or the world frame has not passed m_40 + 10.
	auto m3CValue = [&](uint32_t m3B, uint32_t worldFrame) -> uint32_t {
		if (m3B != 0)
			return 1;
		return worldFrame > (uint32_t)player->m_40 + 10 ? 0 : 1;
	};

	constexpr uint32_t kWorldFrameAddr = uint32_t(g_83320000) - 27380;
	uint32_t m3B = player->m_3B;
	uint32_t worldFrame = LOAD32(kWorldFrameAddr);

	// r7 handed to the calls below: the cached value, or what n_sub_823228C0 left in r7
	uint64_t r7Value = m3CValue(m3B, worldFrame);
	if ((uint32_t)r7Value != player->m_3C) {
		uint32_t newValue = m3CValue(m3B, worldFrame);
		uint32_t handler = LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 140);
		ctx.r7.u64 = r7Value;
		lastR3 = n_sub_823228C0(ctx, base, handler, newValue);
		r7Value = ctx.r7.u64;
		worldFrame = LOAD32(kWorldFrameAddr);
	}

	player->m_3C = (uint8_t)m3CValue(player->m_3B, worldFrame);

	ctx.r3.u64 = lastR3;
	ctx.r7.u64 = r7Value;
	uint64_t result = n_sub_82525EF0(ctx, base);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823CC9A8, 0x823CC9A8) { ctx.r3.u64 = n_sub_823CC9A8(ctx, base, ctx.r3.u64, ctx.r6.u64); }

uint32_t n_sub_823D1830(CpuState& ctx, uint8_t* base, uint64_t playerAddr) {
	if (!UseLiftedCode(21, 0x823D1830)) { ctx.r3.u64 = playerAddr; __imp__sub_823D1830(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823D1830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	uint32_t player = (uint32_t)playerAddr;
	uint64_t eraseResult = playerAddr;
	uint32_t entity = LOAD32(player + 4);
	uint32_t worldFrame = LOAD32(0x8331950Cu);
	bool hasComponent13 = ((LOAD32(entity + 36) >> 13) & 1) != 0;

	if (hasComponent13) {
		// Component type 13 of the entity: through the index table at +140 when there is one, else by a
		// binary search of the sorted 8-byte (type, component) pairs between the pointers at +72 and +76
		// (a miss reads the word after the end pointer).
		uint64_t component13;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t slot = LOAD8(indexTable + 13);
			uint32_t pairs = LOAD32(entity + 72);
			component13 = LOAD32(pairs + slot * 8 + 4);
		} else {
			uint32_t pairs = LOAD32(entity + 72);
			uint32_t pairsEnd = LOAD32(entity + 76);
			uint32_t byteCount = pairsEnd - pairs;
			uint32_t cursor = pairs;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, cursor);
			// carry the original's arithmetic shifts leave behind (callers and the first call below see it)
			ctx.xer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			int32_t count = (int32_t)byteCount >> 3;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					cursor += (uint32_t)(half * 8);
					if ((int32_t)LOAD32(cursor) < 13) {
						count = count - half - 1;
						cursor += 8;
					} else {
						cursor -= (uint32_t)(half * 8);
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, cursor);
			}
			if (cursor != pairsEnd && (int32_t)LOAD32(cursor) <= 13) {
				STORE64(stack + 80, LOAD64(stack + 80));  // unchanged copy of the search eraseResult pair
				component13 = LOAD32(cursor + 4);
			} else {
				component13 = LOAD32(pairsEnd + 4);
			}
		}

		// Walk the list at player + 260 with a checked iterator (list, node) kept at stack + 80 / + 84; the
		// trap calls are that iterator's checks. Each node whose frame at +12 is at or before the current
		// world frame is handed to n_sub_8261A508 with the component and then erased.
		auto iteratorTrap = [&] {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		};
		uint64_t listAddr = playerAddr + 260;
		uint32_t list = (uint32_t)listAddr;
		uint32_t iterList = list;
		uint32_t head = LOAD32(list + 4);
		STORE32(stack + 80, iterList);
		uint32_t node = LOAD32(head);
		STORE32(stack + 84, node);
		for (;;) {
			uint32_t listHead = LOAD32(list + 4);
			if (iterList == 0 || iterList != list)
				iteratorTrap();
			if (node == listHead)
				break;
			if (iterList == 0)
				iteratorTrap();
			uint32_t iterHead = LOAD32(iterList + 4);
			if (node == iterHead)
				iteratorTrap();
			if ((int32_t)LOAD32(node + 12) <= (int32_t)worldFrame) {
				if (node == iterHead)
					iteratorTrap();
				ctx.r1.u64 = stack;
				n_sub_8261A508(ctx, base, stack + 96, component13, LOAD32(node + 8), 1);
				uint32_t created = LOAD32(stack + 96);
				if (created != 0)
					PtrList_RemoveAll(ctx, base, created, stack + 96);
				STORE32(stack + 96, 0);
				eraseResult = PtrList_Erase(ctx, base, stack + 88, listAddr, LOAD64(stack + 80));
				STORE64(stack + 80, LOAD64((uint32_t)eraseResult));
				node = LOAD32(stack + 84);
				iterList = LOAD32(stack + 80);
			} else {
				if (node == iterHead)
					iteratorTrap();
				node = LOAD32(node);
				STORE32(stack + 84, node);
			}
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return (uint32_t)eraseResult;
}
PROMOTED_ENTRY(21, sub_823D1830, 0x823D1830) { ctx.r3.u64 = n_sub_823D1830(ctx, base, ctx.r3.u64); }

uint64_t n_sub_823D20A0(CpuState& ctx, uint8_t* base, uint64_t player, uint32_t microphoneIndex, uint64_t forwardedArg) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(21, 0x823D20A0)) { ctx.r3.u64 = player; ctx.r4.u64 = microphoneIndex; ctx.r8.u64 = forwardedArg; __imp__sub_823D20A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823D20A0);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	PPCVRegister savedMicrophonePosition = ctx.v1;
	uint32_t stack = ctx.r1.u64;

	stack = PushStackFrame(base, stack, 160);
	STORE32(stack + 80, microphoneIndex);
	VSTORE(uint32_t(stack + 192) & ~0xF, V8(savedMicrophonePosition));

	uint32_t globalRoot = uint32_t(g_83490000);
	uint32_t refSource = LOAD32(globalRoot + 27596);
	// state the callee may pass on (r8 then goes on to n_sub_823D2820)
	ctx.r1.u64 = stack;
	ctx.r8.u64 = forwardedArg;
	uint64_t createdRef = n_sub_829F86A0(ctx, base, stack + 88, refSource);

	uint64_t microphoneSlot = n_sub_823D2820(ctx, base, player + 184, stack + 80, ctx.r8.u64);
	RefPtr_Assign(ctx, base, microphoneSlot, createdRef);

	uint64_t result = LOAD32(stack + 92);
	if ((uint32_t)result != 0) {
		uint32_t releaseFunc = LOAD32(LOAD32((uint32_t)result) + 4);
		callTarget.u64 = (uint64_t)releaseFunc;
		ctx.r3.u64 = result;
		ctx.r10.u64 = releaseFunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
	}
	STORE32(stack + 92, 0);
	STORE32(stack + 88, 0);

	uint32_t world = LOAD32(LOAD32(globalRoot + 26912) + 12);
	uint32_t sender = LOAD32(world + 140);
	uint32_t senderFlag52 = LOAD8(sender + 52);
	bool senderFlagsSet = senderFlag52 != 0 && LOAD8(sender + 53) != 0;

	if (senderFlagsSet) {
		uint32_t playerEntity = LOAD32((uint32_t)player + 4);
		uint32_t firstPlayer = LOAD32(LOAD32(LOAD32(world + 88) + 4));
		ctx.r9.u64 = senderFlag52;  // state the callee may pass on
		result = EntityHandle_Get(ctx, base, firstPlayer);

		if (playerEntity == (uint32_t)result) {
			uint32_t playerList = LOAD32(LOAD32(LOAD32(LOAD32(globalRoot + 26912) + 12) + 88) + 4);
			uint32_t firstPlayerNow = LOAD32(playerList);
			ctx.r9.u64 = playerList;  // state the callee may pass on
			result = SpellShot_GetOwner(ctx, base, firstPlayerNow);
			uint64_t ownerEntity = result;

			if ((uint32_t)ownerEntity != 0 && (LOAD8((uint32_t)ownerEntity + 144) & 64) != 0) {
				// The net message is built at stack + 96: vtable at +0, the index from stack + 80 at +4 and a
				// position at +16 (stack + 112). The position is first filled from the float constant at
				// 0x820994B4 through the stack slots at +80 / +84, then Player_ComputeCutsceneMicrophonePosition
				// merges in the v1 this function received (saved at stack + 192).
				uint32_t messageIndex = LOAD32(stack + 80);
				uint32_t slot84Addr = stack + 84;
				ctx.fpscr.disableFlushMode();
				double fillValue = double(LOAD_F32(0x820994B4u));
				uint32_t messageVtable = uint32_t(g_820A0000) + 18020;

				STORE_F32(stack + 80, float(fillValue));
				STORE_F32(stack + 84, float(fillValue));

				PPCVRegister vecFrom84{};
				PPCVRegister vecFrom80{};
				PPCVRegister vecFrom84Late{};
				PPCVRegister positionVec{};

				scratch.u32 = uint32_t(stack + 84);
				SET_V8(vecFrom84, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));

				STORE32(stack + 100, messageIndex);
				STORE_F32(stack + 84, float(fillValue));
				STORE32(stack + 96, messageVtable);

				scratch.u32 = uint32_t(stack + 80);
				SET_V8(vecFrom80, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));

				STORE_F32(stack + 80, float(fillValue));
				SET_VF(vecFrom84, simde_mm_blend_ps(VF(vecFrom84), simde_mm_permute_ps(VF(vecFrom80), 57), 4));

				scratch.u32 = slot84Addr;
				SET_V8(vecFrom84Late, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));

				scratch.u32 = uint32_t(stack + 80);
				SET_V8(positionVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
				SET_VF(positionVec, simde_mm_blend_ps(VF(positionVec), simde_mm_permute_ps(VF(vecFrom84Late), 57), 4));
				SET_VF(positionVec, simde_mm_blend_ps(VF(positionVec), simde_mm_permute_ps(VF(vecFrom84), 78), 3));
				VSTORE(uint32_t(stack + 112) & ~0xF, V8(positionVec));

				// state the callee may pass on
				Player_ComputeCutsceneMicrophonePosition(ctx, base, stack + 112, stack + 192);

				uint32_t senderNow = LOAD32(LOAD32(LOAD32(globalRoot + 26912) + 12) + 140);
				uint64_t ownerUniqueId = Entity_GetUniqueId(ctx, base, ownerEntity);
				result = Player_SendCutsceneMicrophoneNetMessage(ctx, base, senderNow, stack + 96, ownerUniqueId);
			}
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823D20A0, 0x823D20A0) { ctx.r3.u64 = n_sub_823D20A0(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r8.u64); }
