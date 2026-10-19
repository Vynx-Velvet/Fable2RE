// CECLook (vtable 0x82004058): methods of the class as readable C++.
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

uint64_t n_sub_8223E6B8(CpuState& ctx, uint8_t* base, uint64_t lookAddr) {
	if (!UseLiftedCode(7, 0x8223E6B8)) { ctx.r3.u64 = lookAddr; __imp__sub_8223E6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8223E6B8);
	uint32_t stack = ctx.r1.u64;
	CECLook* look = GameObject<CECLook>(base, lookAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t lookA = (uint32_t)lookAddr;
	// r3 keeps whatever the last call (or explicit assignment) left in it.
	uint64_t result = lookAddr;

	if (LOAD8(0x8331930D) == 0) {
		// idle looking globally disabled: clear the flags on the look owner
		uint32_t lookOwner = look->m_70;
		STORE8(lookOwner + 33, 0);
		STORE8(lookOwner + 44, 0);
		STORE8(lookOwner + 34, 0);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return result;
	}

	if (LOAD8(lookA + 84) != 0 && LOAD8(lookA + 96) == 0) {
		ctx.r1.u64 = stack;
		n_sub_82240660(ctx, base, lookAddr);
	} else {
		ctx.r1.u64 = stack;
		n_sub_82704F20(ctx, base, lookAddr);  // Lua_Look_ClearIdleLooking
	}

	result = n_sub_82262AF0(ctx, base, lookAddr);
	if (LOAD32(lookA + 140) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return result;
	}

	uint32_t listAddr = lookA + 132;

	// release the handle currently held by the list, remove it, then release the reset handle
	uint32_t emptyHandle = 0x820F1664u;
	STORE32(stack + 84, 0);
	STORE32(stack + 80, emptyHandle);
	ctx.r10.u64 = emptyHandle;
	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, stack + 80);

	ctx.r1.u64 = stack;
	EntityHandleList_Remove(ctx, base, listAddr, stack + 80);

	uint32_t resetHandle = 0x820F0000u + 5732;
	STORE32(stack + 80, resetHandle);
	ctx.r8.u64 = resetHandle;
	ctx.r9.u64 = 0x820F0000u;
	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, stack + 80);

	uint32_t ownerLook = look->m_4;
	ctx.r1.u64 = stack;
	result = Entity_ShouldMoveWhenUnsheathing(ctx, base, 6, ownerLook);
	uint32_t moveResult = (uint32_t)result;
	bool clearFlags = (moveResult & 0xFF) == 0;
	uint32_t handleParam = moveResult & 0xFF;

	uint32_t node = LOAD32(LOAD32(listAddr + 4));
	for (;;) {
		uint32_t head = LOAD32(listAddr + 4);
		if (node == head) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return result;
		}

		uint32_t handle = LOAD32(node + 12);
		result = (uint64_t)node + 8;
		uint32_t target = 0;
		if (handle != 0) {
			uint32_t obj = LOAD32(handle);
			if (obj != 0) {
				target = obj;
			} else {
				ctx.r7.u64 = handleParam;
				ctx.r10.u64 = 0;
				ctx.r1.u64 = stack;
				result = EntityHandle_Release(ctx, base, node + 8);
				handleParam = ctx.r7.u32;
			}
		}
		if (clearFlags) {
			STORE8(target + 33, 0);
			STORE8(target + 44, 0);
		}
		node = LOAD32(node);
	}
}
PROMOTED_ENTRY(7, sub_8223E6B8, 0x8223E6B8) { ctx.r3.u64 = n_sub_8223E6B8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82262AF0(CpuState& ctx, uint8_t* base, uint32_t lookAddr) {
	if (!UseLiftedCode(9, 0x82262AF0)) { ctx.r3.u64 = lookAddr; __imp__sub_82262AF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82262AF0);
	uint32_t stack = ctx.r1.u64;
	CECLook* look = GameObject<CECLook>(base, lookAddr);
	stack = PushStackFrame(base, stack, 144);

	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = 0;
	uint32_t carry = ctx.xer.ca ? 1u : 0u;

	const uint32_t entryFlagsOffset = 1248;

	uint32_t entryValue = 0;    // payload of the entry keyed 97 ('a')
	uint32_t entryFound = 0;
	uint64_t handle = 0;        // look->m_58
	PPCVRegister vec = ctx.v1;
	PPCRegister callTarget{};

	uint32_t table = look->m_4;
	uint32_t lookupEnabled = (LOAD32(table + 48) >> 1) & 1;
	reg9 = lookupEnabled;
	if (lookupEnabled != 0) {
		uint32_t map = LOAD32(table + 140);
		if (map != 0) {
			uint32_t entries = LOAD32(table + 72);
			uint32_t entry = entries + LOAD8(map + 97) * 8;
			reg9 = entry;
			entryValue = LOAD32(entry + 4);
			entryFound = 1;
		} else {
			uint32_t begin = LOAD32(table + 72);
			uint32_t end = LOAD32(table + 76);
			reg6 = end;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, begin);
			uint32_t rawCount = end - begin;
			carry = ((int32_t)rawCount < 0 && (rawCount & 7) != 0) ? 1u : 0u;
			int32_t count = (int32_t)rawCount >> 3;
			bool enteredSearch = count > 0;
			while (count > 0) {
				carry = (count < 0 && (count & 1) != 0) ? 1u : 0u;
				int32_t half = count >> 1;
				uint32_t mid = begin + (uint32_t)half * 8;
				int32_t key = (int32_t)LOAD32(mid);
				reg9 = (uint32_t)half;
				reg8 = (uint32_t)half * 8;
				reg7 = key < 97;
				if (key < 97) {
					begin = mid + 8;
					count = (count - half) - 1;
				} else {
					count = half;
				}
			}
			if (enteredSearch) {
				STORE32(stack + 84, begin);
			}
			entryFound = 1;
			uint32_t found = (begin != end && (int32_t)LOAD32(begin) <= 97) ? begin : end;
			entryValue = LOAD32(found + 4);
		}
	}

	if (entryFound != 0) {
		SET_V8(vec, simde_mm_set1_epi32(0));
		VSTORE((entryValue + entryFlagsOffset) & ~0xF, V8(vec));
	}

	uint64_t result = 0;
	if (look->m_58 == 0) {
		uint32_t info = look->m_70;
		STORE8(info + 33, 0);
		STORE8(info + 44, 0);
	} else {
		handle = look->m_58;
		uint32_t target = LOAD32(LOAD32(handle) + 12);
		callTarget.u64 = target;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = handle;
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.r10.u64 = target;
		ctx.xer.ca = carry;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
		reg9 = ctx.r9.u64;
		carry = ctx.xer.ca ? 1u : 0u;

		if (((uint32_t)result & 0xFF) == 0) {
			uint32_t info = look->m_70;
			STORE8(info + 33, 0);
			STORE8(info + 44, 0);
		} else {
			handle = look->m_58;
			uint32_t buffer = stack + 80;
			target = LOAD32(LOAD32(handle) + 8);
			callTarget.u64 = target;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = buffer;
			ctx.r4.u64 = handle;
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = reg9;
			ctx.r10.u64 = target;
			ctx.xer.ca = carry;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			carry = ctx.xer.ca ? 1u : 0u;

			handle = look->m_58;
			uint64_t knownFlags = look->m_64;
			uint64_t handleFlags = LOAD32(handle + 12);
			uint64_t flagDiff = handleFlags & ~knownFlags;
			uint64_t newBits = (uint32_t)flagDiff & 8;
			if (newBits != 0) {
				uint32_t info = look->m_70;
				bool alreadyApplied = LOAD8(info + 33) != 0 && LOAD8(info + 34) != 0;
				if (!alreadyApplied) {
					SET_V8(vec, VLOAD((stack + 80) & ~0xF));
					ctx.r6.u64 = newBits;
					ctx.r7.u64 = handleFlags;
					ctx.r8.u64 = knownFlags;
					ctx.r9.u64 = handle;
					ctx.v1 = vec;
					n_sub_82704160(ctx, base, lookAddr);
					newBits = ctx.r6.u64;
					handleFlags = ctx.r7.u64;
					knownFlags = ctx.r8.u64;
					handle = ctx.r9.u64;
					carry = ctx.xer.ca ? 1u : 0u;
				}
				flagDiff -= 8;
			}

			uint32_t info = look->m_70;
			uint64_t diff = flagDiff;
			SET_V8(vec, VLOAD((stack + 80) & ~0xF));
			ctx.r6.u64 = newBits;
			ctx.r7.u64 = handleFlags;
			ctx.r8.u64 = knownFlags;
			ctx.r9.u64 = handle;
			ctx.v1 = vec;
			result = n_sub_822628B8(ctx, base, info, diff);
			reg8 = ctx.r8.u64;
			carry = ctx.xer.ca ? 1u : 0u;
			if (((uint32_t)result & 0xFF) != 0 && entryValue != 0) {
				SET_V8(vec, VLOAD((stack + 80) & ~0xF));
				VSTORE((entryValue + entryFlagsOffset) & ~0xF, V8(vec));
			}
		}
	}

	look->m_60 = 0;
	look->m_64 = 0;
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = carry;
	return result;
}
PROMOTED_ENTRY(9, sub_82262AF0, 0x82262AF0) { ctx.r3.u64 = n_sub_82262AF0(ctx, base, ctx.r3.u32); }

uint32_t CECLook_CanLookAt(CpuState& ctx, uint8_t* base, uint32_t lookAddr, uint64_t arg2) {
	if (!UseLiftedCode(9, 0x822643B0)) { ctx.r3.u64 = lookAddr; ctx.r4.u64 = arg2; __imp__sub_822643B0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822643B0);
	CECLook* look = GameObject<CECLook>(base, lookAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	const uint32_t timeValue = (uint32_t)arg2;
	uint32_t canLook = 0;
	uint32_t carry = ctx.xer.ca ? 1u : 0u;

	if (LOAD8(0x83318EACu) != 0) {
		uint32_t target = look->m_58;
		if (target != 0) {
			uint32_t isValidFunc = LOAD32(LOAD32(target) + 12);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = target;
			ctx.r4.u64 = arg2;
			ctx.r10.u64 = isValidFunc;
			REX_CALL_INDIRECT_FUNC(isValidFunc);
			target = ctx.r3.u32;
			arg2 = ctx.r4.u64;
			carry = ctx.xer.ca ? 1u : 0u;
		}
		// The target is acceptable when it is unset, or when its range does not
		// already reach the requested time.
		if ((target & 0xFF) == 0 || LOAD32(LOAD32(lookAddr + 88) + 8) < timeValue) {
			uint32_t maxRange = look->m_68;
			canLook = (timeValue >= maxRange) ? 1u : 0u;
			carry = canLook;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	ctx.xer.ca = carry;
	return canLook;
}
PROMOTED_ENTRY(9, sub_822643B0, 0x822643B0) { ctx.r3.u64 = CECLook_CanLookAt(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CECLook_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820A7680_B_ = int32_t(0x820A7680);
	if (!UseLiftedCode(47, 0x82702C00)) { ctx.r3.u64 = classNameString; __imp__sub_82702C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82702C00);
	uint32_t stack = ctx.r1.u64;
	uint64_t classNameCStr = str_TXT_820A7680_B_;
	int32_t length = -1;

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameCStr, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(47, sub_82702C00, 0x82702C00) { ctx.r3.u64 = CECLook_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82703478(CpuState& ctx, uint8_t* base, uint64_t lookAddr, uint32_t arg2) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(47, 0x82703478)) { ctx.r3.u64 = lookAddr; ctx.r4.u64 = arg2; __imp__sub_82703478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82703478);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	CECLook* look = GameObject<CECLook>(base, lookAddr);

	look->m_4 = arg2;
	look->m_8 = 0;
	look->m_C = 0x820834B0u;
	look->vtable = 0x82004058u;
	look->m_C = 0x82000E04u;
	look->m_10 = 0x820F1664u;
	look->m_14 = 0;
	look->m_18 = 0;
	look->m_1C = 0;
	look->m_20 = 0;

	// increment the global counter at 0x83496EB8
	const uint32_t counterAddr = uint32_t(g_83490000) + 28344;
	STORE32(counterAddr, LOAD32(counterAddr) + 1);

	look->m_24 = 0;
	look->m_28 = 0;
	STORE32(uint32_t(lookAddr) + 44, 0);
	look->m_30 = 0;
	look->m_50 = 0;

	const uint32_t globalAddr = uint32_t(g_83490000);
	uint32_t globalCount = LOAD32(globalAddr + 27288) + 1;

	look->m_54 = 1;
	look->m_58 = 0;
	look->m_5C = 0;
	look->m_60 = 0;
	look->m_64 = 0;
	look->m_68 = 0;
	look->m_6C = 0xFFFFFFFFu;
	look->m_70 = 0;
	look->m_74 = 0;
	look->m_78 = uint32_t(int64_t(str_TXT_820B0000_B_) - 32268);
	look->m_7C = 0;
	look->m_80 = 0;
	STORE32(globalAddr + 27288, globalCount);

	const uint32_t allocSize = 16;
	ctx.r1.u64 = stack;
	ctx.r4.s64 = int64_t(str_TXT_820B0000_B_);
	ctx.r5.u64 = 1;
	ctx.r6.s64 = int64_t(g_83490000);
	ctx.r8.s64 = int64_t(g_83490000);
	uint32_t node = operator_new(ctx, base, allocSize);

	if (node != 0) {
		STORE32(node, node);
	}
	uint32_t nodeTail = node + 4;
	if (nodeTail != 0) {
		STORE32(nodeTail, node);
	}
	look->m_88 = node;
	look->m_8C = 0;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return lookAddr;
}
PROMOTED_ENTRY(47, sub_82703478, 0x82703478) { ctx.r3.u64 = n_sub_82703478(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_827035B0(CpuState& ctx, uint8_t* base, uint64_t lookAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(47, 0x827035B0)) { ctx.r3.u64 = lookAddr; ctx.r4.u64 = deleteFlags; __imp__sub_827035B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827035B0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECLook* look = GameObject<CECLook>(base, lookAddr);

	stack = PushStackFrame(base, stack, 112);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	n_sub_824C6480(ctx, base, (uint32_t)(lookAddr + 132));
	C_820EFB9C_Destructor(ctx, base, (uint32_t)(lookAddr + 120));
	SharedHandle_Release(ctx, base, (uint32_t)(lookAddr + 112));

	uint32_t handleTarget = look->m_58;
	if (handleTarget != 0) {
		callTarget.u64 = LOAD32(LOAD32(handleTarget));
		ctx.r3.u64 = handleTarget;
		ctx.r4.u64 = 1;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	look->m_58 = 0u;
	LookAtHandle_Destruct(ctx, base, (uint32_t)(lookAddr + 16));
	look->vtable = 0x820A8D10u;

	uint64_t result = lookAddr;
	if (uint32_t(deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, lookAddr);
		result = lookAddr;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(47, sub_827035B0, 0x827035B0) { ctx.r3.u64 = n_sub_827035B0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82703650(CpuState& ctx, uint8_t* base, uint64_t lookAddr, uint64_t arg2) {
	constexpr int32_t str_TXT_820CF300_B_ = int32_t(0x820CF300);
	constexpr int32_t g_82970000 = int32_t(0x82970000);
	if (!UseLiftedCode(47, 0x82703650)) { ctx.r3.u64 = lookAddr; ctx.r4.u64 = arg2; __imp__sub_82703650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82703650);
	uint32_t stack = ctx.r1.u64;
	uint32_t lookValue = 0;
	uint32_t applied = 0;
	uint64_t carryR6 = 0, carryR7 = 0, carryR8 = 0, carryR9a = 0, carryR9b = 0;
	PPCRegister callTarget{};
	CECLook* look = GameObject<CECLook>(base, lookAddr);
	stack = PushStackFrame(base, stack, 128);

	if ((uint32_t)arg2 != 0) {
		ctx.r1.u64 = stack;
		GameDB_ReadBool(ctx, base, arg2, (uint64_t)(int64_t)str_TXT_820CF300_B_, lookAddr + 84);
		arg2 = ctx.r4.u64;
	}

	uint32_t TXT_820A76B4_L_ = look->m_4;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	uint32_t component = n_sub_827031D0(ctx, base, TXT_820A76B4_L_);

	uint32_t handleAddr = (uint32_t)(lookAddr + 112);
	SharedHandle_Release(ctx, base, lookAddr + 112);
	carryR6 = ctx.r6.u64;
	carryR7 = ctx.r7.u64;
	carryR8 = ctx.r8.u64;
	carryR9a = ctx.r9.u64;

	look->m_70 = component;

	if (component != 0) {
		uint32_t alloc = (uint32_t)operator_new(ctx, base, 12);
		carryR6 = ctx.r6.u64;
		carryR7 = ctx.r7.u64;
		carryR8 = ctx.r8.u64;
		carryR9a = ctx.r9.u64;
		uint32_t newHandle;
		if (alloc != 0) {
			uint32_t existing = LOAD32(handleAddr);
			carryR9a = (uint64_t)g_82970000;
			carryR8 = 1;
			carryR7 = (int64_t)carryR9a - 32320;
			STORE32(alloc, (uint32_t)carryR8);
			newHandle = alloc;
			STORE32(alloc + 4, (uint32_t)carryR7);
			STORE32(alloc + 8, existing);
		} else {
			newHandle = 0;
		}
		STORE32(handleAddr + 4, newHandle);
	}

	if (LOAD32(handleAddr) == 0) {
		uint32_t TXT_820A76B4_L_2 = look->m_4;
		uint32_t vfunc = LOAD32((uint32_t)look->vtable + 16);
		callTarget.u64 = (uint64_t)vfunc;
		ctx.r3.u64 = lookAddr;
		ctx.r7.u64 = carryR7;
		ctx.r8.u64 = carryR8;
		ctx.r9.u64 = carryR9a;
		ctx.r10.u64 = vfunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t componentId = ctx.r3.u64;
		uint64_t removed = Entity_RemoveComponentByType(ctx, base, (uint64_t)TXT_820A76B4_L_2, componentId, ctx.r8.u64);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return removed;
	}

	uint32_t obj = look->m_4;
	lookValue = 0;
	uint32_t hasMap = (LOAD32(obj + 36) >> 6) & 1;
	carryR9b = hasMap;
	if (hasMap != 0) {
		uint32_t p140 = LOAD32(obj + 140);
		if (p140 != 0) {
			uint32_t index8 = __builtin_rotateleft32((uint32_t)LOAD8(p140 + 6), 3);
			uint32_t tableBase = LOAD32(obj + 72);
			carryR9b = (uint64_t)index8 + (uint64_t)tableBase;
			lookValue = LOAD32((uint32_t)carryR9b + 4);
			applied = 1;
		} else {
			uint32_t begin = LOAD32(obj + 72);
			carryR9b = 0;
			uint32_t endPtr = LOAD32(obj + 76);
			STORE32(stack + 80, 0);
			carryR8 = (uint64_t)endPtr - (uint64_t)begin;
			STORE32(stack + 84, begin);
			int32_t count = (int32_t)((uint32_t)endPtr - (uint32_t)begin) >> 3;
			if (count > 0) {
				do {
					uint32_t half = (uint32_t)(count >> 1);
					carryR9b = half;
					carryR8 = (uint64_t)(half << 3);
					uint32_t mid = (uint32_t)carryR8 + begin;
					bool lessThan6 = (int32_t)LOAD32(mid) < 6;
					carryR7 = lessThan6 ? 1 : 0;
					if (lessThan6) {
						count = count - (int32_t)half;
						begin = mid + 8;
						count = count - 1;
					} else {
						begin = mid - (uint32_t)carryR8;
						count = (int32_t)half;
					}
				} while (count > 0);
				STORE32(stack + 84, begin);
			}
			if (begin != endPtr) {
				bool greaterThan6 = (int32_t)LOAD32(begin) > 6;
				if (!greaterThan6) {
					STORE64(stack + 80, LOAD64(stack + 80));
					lookValue = LOAD32(begin + 4);
					applied = 1;
				} else {
					lookValue = LOAD32(endPtr + 4);
					applied = 1;
				}
			} else {
				lookValue = LOAD32(endPtr + 4);
				applied = 1;
			}
		}
	} else {
		applied = 0;
	}

	if (applied != 0) {
		ctx.r7.u64 = carryR7;
		ctx.r8.u64 = carryR8;
		ctx.r9.u64 = carryR9b;
		n_sub_8254F608(ctx, base, lookValue, lookAddr + 120, 3, lookAddr + 12);
		carryR6 = ctx.r6.u64;
		carryR7 = ctx.r7.u64;
		carryR8 = ctx.r8.u64;
		carryR9b = ctx.r9.u64;
	}

	uint32_t TXT_820A76B4_L_3 = look->m_4;
	ctx.r6.u64 = carryR6;
	ctx.r7.u64 = carryR7;
	ctx.r8.u64 = carryR8;
	ctx.r9.u64 = carryR9b;
	uint64_t result = n_sub_82392C88(ctx, base, TXT_820A76B4_L_3, lookAddr);
	look->m_50 = look->m_50 | 1;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(47, sub_82703650, 0x82703650) { ctx.r3.u64 = n_sub_82703650(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82703860(CpuState& ctx, uint8_t* base, uint64_t lookAddr, uint64_t stream, uint64_t lookAtKind, uint64_t loadFlag) {
	constexpr int32_t g_82001C44 = int32_t(0x82001C44);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820A76B4_B_ = int32_t(0x820A76B4);
	constexpr int32_t str_TXT_820CF30C_B_ = int32_t(0x820CF30C);
	constexpr int32_t str_TXT_820CF318_B_ = int32_t(0x820CF318);
	constexpr int32_t str_TXT_820CF328_B_ = int32_t(0x820CF328);
	constexpr int32_t str_TXT_820CF334_B_ = int32_t(0x820CF334);
	constexpr int32_t str_TXT_820CF350_B_ = int32_t(0x820CF350);
	constexpr int32_t str_TXT_820DF968_B_ = int32_t(0x820DF968);
	constexpr int32_t g_820DF9BC = int32_t(0x820DF9BC);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(47, 0x82703860)) { ctx.r3.u64 = lookAddr; ctx.r4.u64 = stream; ctx.r5.u64 = lookAtKind; ctx.r6.u64 = loadFlag; __imp__sub_82703860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82703860);
	PPCRegister callTarget{};
	PPCVRegister zeroVec{};
	uint32_t stack = ctx.r1.u64;
	CECLook* look = GameObject<CECLook>(base, lookAddr);
	stack = PushStackFrame(base, stack, 160);

	uint64_t result = lookAddr;
	uint64_t streamReg = stream;
	uint64_t r5Val = 0;
	uint64_t r6Val = 0;
	uint64_t r7Val = 0;
	uint64_t r8Val = 0;
	uint64_t r9Val = 0;

	if ((int32_t)lookAtKind == 1) {
		const uint64_t initialLoadFlag = loadFlag;
		uint32_t lookState = look->m_58;
		uint32_t canSerialize = 0;
		if (lookState != 0) {
			uint32_t fn = LOAD32(LOAD32(lookState) + 12);
			callTarget.u64 = fn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = lookState;
			ctx.r4.u64 = stream;
			ctx.r5.u64 = lookAtKind;
			ctx.r6.u64 = loadFlag;
			ctx.r10.u64 = fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			canSerialize = ctx.r3.u32;
			streamReg = ctx.r4.u64;
			lookAtKind = ctx.r5.u64;
			loadFlag = ctx.r6.u64;
		}
		uint32_t lookAtTypeValue = 0;
		if ((canSerialize & 0xFF) != 0) {
			uint32_t state = look->m_58;
			uint32_t fn = LOAD32(LOAD32(state) + 20);
			callTarget.u64 = fn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = state;
			ctx.r4.u64 = streamReg;
			ctx.r5.u64 = lookAtKind;
			ctx.r6.u64 = loadFlag;
			ctx.r10.u64 = fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			lookAtTypeValue = ctx.r3.u32;
			loadFlag = ctx.r6.u64;
		}
		STORE32(stack + 84, lookAtTypeValue);

		ctx.r1.u64 = stack;
		ctx.r6.u64 = loadFlag;
		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820CF30C_B_, -1);
		uint32_t nameBuffer = LOAD32(stack + 80);
		uint64_t nameLength = g_8209003F;
		if (nameBuffer != 0) nameLength = LOAD32(nameBuffer);
		ctx.r4.u64 = nameLength;
		IStream_SerializeU32(ctx, base, stream, stack + 84);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820CF318_B_, -1);
		nameBuffer = LOAD32(stack + 80);
		nameLength = g_8209003F;
		if (nameBuffer != 0) nameLength = LOAD32(nameBuffer);
		ctx.r4.u64 = nameLength;
		IStream_SerializeId(ctx, base, stream, lookAddr + 92);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

		r5Val = ctx.r5.u64;
		r6Val = ctx.r6.u64;
		r7Val = ctx.r7.u64;
		r8Val = ctx.r8.u64;
		r9Val = ctx.r9.u64;

		uint32_t lookType = LOAD32(stack + 84);
		bool replaceState = false;
		bool callStateInit = false;
		uint32_t newState = 0;

		if (lookType == 1) {
			if ((initialLoadFlag & 0xFF) != 0) {
				callStateInit = true;
			} else {
				uint32_t obj = operator_new(ctx, base, 32);
				r5Val = ctx.r5.u64;
				r6Val = ctx.r6.u64;
				r7Val = ctx.r7.u64;
				r8Val = ctx.r8.u64;
				r9Val = ctx.r9.u64;
				if (obj != 0) {
					SET_V8(zeroVec, simde_mm_set1_epi32(0));
					STORE32(obj + 4, 0);
					r9Val = g_820DF9BC;
					STORE32(obj + 8, 0);
					STORE32(obj + 12, 0);
					newState = obj;
					STORE32(obj, (uint32_t)g_820DF9BC);
					VSTORE((obj + 16u) & ~0xF, V8(zeroVec));
				}
				replaceState = true;
			}
		} else if (lookType == 2) {
			if ((initialLoadFlag & 0xFF) != 0) {
				callStateInit = true;
			} else {
				uint32_t obj = operator_new(ctx, base, 40);
				r5Val = ctx.r5.u64;
				r6Val = ctx.r6.u64;
				r7Val = ctx.r7.u64;
				r8Val = ctx.r8.u64;
				r9Val = ctx.r9.u64;
				if (obj != 0) {
					STORE32(obj + 4, 0);
					r9Val = g_820F0000;
					STORE32(obj + 8, 0);
					r7Val = g_82001C44;
					STORE32(obj + 12, 0);
					r6Val = (uint64_t)((int64_t)r9Val + 5732);
					STORE32(obj, (uint32_t)r7Val);
					r5Val = g_83490000;
					STORE32(obj + 16, (uint32_t)r6Val);
					STORE32(obj + 20, 0);
					STORE32(obj + 24, 0);
					STORE32(obj + 28, 0);
					STORE32(obj + 32, 0);
					STORE32(0x83490000 + 28344, LOAD32(0x83490000 + 28344) + 1);
					STORE8(obj + 36, 0);
					newState = obj;
					uint32_t refCounter = 0x83490000 + 27288;
					STORE32(refCounter, LOAD32(refCounter) + 1);
				}
				replaceState = true;
			}
		}

		if (replaceState) {
			uint32_t oldState = look->m_58;
			if (oldState != 0) {
				uint32_t fn = LOAD32(LOAD32(oldState));
				callTarget.u64 = fn;
				ctx.r3.u64 = oldState;
				ctx.r4.u64 = 1;
				ctx.r5.u64 = r5Val;
				ctx.r6.u64 = r6Val;
				ctx.r7.u64 = r7Val;
				ctx.r8.u64 = r8Val;
				ctx.r9.u64 = r9Val;
				ctx.r10.u64 = fn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				r5Val = ctx.r5.u64;
				r6Val = ctx.r6.u64;
				r7Val = ctx.r7.u64;
				r8Val = ctx.r8.u64;
				r9Val = ctx.r9.u64;
			}
			look->m_58 = newState;
			callStateInit = true;
		}

		if (callStateInit) {
			uint32_t state = look->m_58;
			uint32_t fn = LOAD32(LOAD32(state) + 16);
			callTarget.u64 = fn;
			ctx.r3.u64 = state;
			ctx.r4.u64 = stream;
			ctx.r5.u64 = r5Val;
			ctx.r6.u64 = r6Val;
			ctx.r7.u64 = r7Val;
			ctx.r8.u64 = r8Val;
			ctx.r9.u64 = r9Val;
			ctx.r10.u64 = fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}

		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, stack + 88, str_TXT_820CF328_B_, -1);
		uint32_t idleNameBuffer = LOAD32(stack + 88);
		uint64_t idleName = g_8209003F;
		if (idleNameBuffer != 0) idleName = LOAD32(idleNameBuffer);
		{
			uint32_t fn = LOAD32(LOAD32((uint32_t)stream) + 4);
			callTarget.u64 = fn;
			ctx.r3.u64 = stream;
			ctx.r4.u64 = idleName;
			ctx.r10.u64 = fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}

		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820A76B4_B_, -1);
		n_sub_825BC3B0(ctx, base, lookAddr + 16, stack + 80, stream);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820DF968_B_, -1);
		uint32_t lookAtIdBuffer = LOAD32(stack + 80);
		uint64_t lookAtIdName = g_8209003F;
		if (lookAtIdBuffer != 0) lookAtIdName = LOAD32(lookAtIdBuffer);
		ctx.r4.u64 = lookAtIdName;
		IStream_SerializeId(ctx, base, stream, lookAddr + 40);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		{
			uint32_t fn = LOAD32(LOAD32((uint32_t)stream) + 12);
			callTarget.u64 = fn;
			ctx.r3.u64 = stream;
			ctx.r10.u64 = fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);

		CCharString_ConstructFromCStr(ctx, base, stack + 88, str_TXT_820CF334_B_, -1);
		n_sub_8244DAE0(ctx, base, lookAddr + 44, stack + 88, stream);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);

		CCharString_ConstructFromCStr(ctx, base, stack + 88, str_TXT_820CF350_B_, -1);
		n_sub_82A17080(ctx, base, stack + 88, stream, lookAddr + 64);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);

		CCharString_ConstructFromCStr(ctx, base, stack + 88, str_TXT_820CF318_B_, -1);
		uint32_t currentIdBuffer = LOAD32(stack + 88);
		uint64_t currentIdName = g_8209003F;
		if (currentIdBuffer != 0) currentIdName = LOAD32(currentIdBuffer);
		ctx.r4.u64 = currentIdName;
		IStream_SerializeU32(ctx, base, stream, lookAddr + 80);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
		streamReg = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = streamReg;
	return result;
}
PROMOTED_ENTRY(47, sub_82703860, 0x82703860) { ctx.r3.u64 = n_sub_82703860(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_82703BE8  [132 bytes]
uint64_t n_sub_82703BE8(CpuState& ctx, uint8_t* base, uint32_t lookAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(47, 0x82703BE8)) { ctx.r3.u64 = lookAddr; __imp__sub_82703BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82703BE8);
	uint32_t stack = ctx.r1.u64;
	CECLook* look = GameObject<CECLook>(base, lookAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t globalTable = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t lookEntity = look->m_4;
	uint32_t manager = LOAD32(globalTable + 12);
	uint32_t field88 = LOAD32(manager + 88);
	uint32_t field4 = LOAD32(field88 + 4);
	uint32_t playerEntity = LOAD32(field4);

	ctx.r1.u64 = stack;
	ctx.r8.u64 = field4;
	ctx.r9.u64 = field88;
	uint32_t isPlayer = Players_IsPlayer(ctx, base, playerEntity, lookEntity);
	if ((isPlayer & 0xFF) != 0) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return 2;
	}

	uint32_t flag = (LOAD32(look->m_4 + 48) >> 1) & 1;
	uint32_t result = (flag == 0) ? 2 : 1;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(47, sub_82703BE8, 0x82703BE8) { ctx.r3.u64 = n_sub_82703BE8(ctx, base, ctx.r3.u32); }

uint64_t n_sub_827045B8(CpuState& ctx, uint8_t* base, uint64_t lookAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83497770 = int32_t(0x83497770);
	constexpr int32_t g_8349B1B4 = int32_t(0x8349B1B4);
	constexpr int32_t g_8349B1B8 = int32_t(0x8349B1B8);
	constexpr int32_t g_834F0000 = int32_t(0x834F0000);
	if (!UseLiftedCode(47, 0x827045B8)) { ctx.r3.u64 = lookAddr; __imp__sub_827045B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827045B8);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CECLook* look = GameObject<CECLook>(base, lookAddr);

	PPCVRegister savedV127 = ctx.v127;
	PPCVRegister vecV1{}, vecV2{};
	PPCVRegister vecV10{}, vecV11{}, vecV12{}, vecV13{};
	PPCVRegister vecA{}, vecB{};

	VSTORE((stack + 0xFFFFFFA0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 288);

	uint64_t result = lookAddr;

	if (LOAD8(0x834BE858u) != 0) {
		uint32_t owner = look->m_58;
		if (owner == 0) {
			result = 0;
		} else {
			uint32_t getEntity = LOAD32(LOAD32(owner) + 12);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = owner;
			ctx.r10.u64 = getEntity;
			callTarget.u64 = getEntity;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
		}

		if (((uint32_t)result & 0xFF) != 0) {
			uint32_t managerSlot = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t helper = LOAD32(managerSlot + 12);
			uint64_t trollTable = (uint64_t)g_83497770;

			ctx.r1.u64 = stack;
			ctx.r10.u64 = helper;
			n_sub_821F5B90(ctx, base, stack + 88, LOAD32(helper + 96), trollTable);

			uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t managerVtable = LOAD32(manager);
			uint32_t getActorFn = LOAD32(managerVtable + 20);
			ctx.r3.u64 = manager;
			ctx.r8.u64 = getActorFn;
			ctx.r9.u64 = managerVtable;
			callTarget.u64 = getActorFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t actor = ctx.r3.u64;

			uint32_t lookObj = look->m_4;
			uint32_t slotPtr = LOAD32(actor + 4);
			uint32_t actorId = LOAD32(slotPtr);
			uint32_t boundsPtr = LOAD32(lookObj + 124);
			uint32_t getBoundsFn = LOAD32(LOAD32(boundsPtr) + 64);
			ctx.r3.u64 = stack + 96;
			ctx.r4.u64 = boundsPtr;
			ctx.r5.u64 = slotPtr;
			ctx.r6.u64 = actor;
			ctx.r7.u64 = lookObj;
			ctx.r10.u64 = getBoundsFn;
			callTarget.u64 = getBoundsFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint32_t owner2 = look->m_58;
			uint32_t ownerVtable = LOAD32(owner2);
			uint32_t getPosFn = LOAD32(ownerVtable + 8);
			ctx.r3.u64 = stack + 112;
			ctx.r4.u64 = owner2;
			ctx.r8.u64 = getPosFn;
			ctx.r9.u64 = ownerVtable;
			callTarget.u64 = getPosFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t getPosR8 = ctx.r8.u64;
			uint32_t getPosR9 = ctx.r9.u64;
			vecV10 = ctx.v10;
			vecV11 = ctx.v11;
			vecV12 = ctx.v12;
			vecV13 = ctx.v13;
			PPCXERRegister flags = ctx.xer;

			// Pick the weak-spot target: either the direct slot, or a lookup in the
			// sorted list of (id, target) pairs for id == 3 (lower_bound).
			uint32_t targetId = 0;
			bool hasTarget = false;

			// Registers handed to the weak-spot checks through the CPU state.
			uint32_t weakSpotR6 = 0;
			uint32_t weakSpotR7 = 0;
			uint32_t weakSpotR8 = 0;
			uint32_t weakSpotR9 = 0;

			uint32_t lookFlags = LOAD32(look->m_4 + 36);
			weakSpotR6 = (lookFlags >> 3) & 1;
			weakSpotR7 = lookFlags;
			weakSpotR8 = getPosR8;
			weakSpotR9 = getPosR9;
			if (weakSpotR6 != 0) {
				uint32_t directSlot = LOAD32(look->m_4 + 140);
				if (directSlot != 0) {
					uint32_t index = LOAD8(directSlot + 3);
					uint32_t arrayBase = LOAD32(look->m_4 + 72);
					uint32_t entry = arrayBase + (index << 3);
					targetId = LOAD32(entry + 4);
					hasTarget = true;
					weakSpotR9 = entry;
				} else {
					uint32_t begin = LOAD32(look->m_4 + 72);
					uint32_t end = LOAD32(look->m_4 + 76);
					weakSpotR6 = end;
					STORE32(stack + 80, 0);
					STORE32(stack + 84, begin);

					int32_t count = (int32_t)(uint32_t)(end - begin) >> 3;
					if (count > 0) {
						do {
							int32_t half = count >> 1;
							uint32_t offset = (uint32_t)half << 3;
							begin += offset;
							weakSpotR9 = (uint32_t)half;
							weakSpotR8 = offset;
							bool lessThan3 = (int32_t)LOAD32(begin) < 3;
							weakSpotR7 = lessThan3 ? 1 : 0;
							if (lessThan3) {
								count = count - half - 1;
								begin += 8;
							} else {
								begin -= offset;
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 84, begin);
					}

					if (begin != end && (int32_t)LOAD32(begin) <= 3) {
						STORE64(stack + 80, LOAD64(stack + 80));
						targetId = LOAD32(LOAD32(stack + 84) + 4);
					} else {
						targetId = LOAD32(end + 4);
					}
					hasTarget = true;
				}
			}

			if (hasTarget) {
				uint64_t tblA = (uint64_t)g_8349B1B8;
				uint64_t tblB = (uint64_t)g_8349B1B4;

				ctx.r6.u64 = weakSpotR6;
				ctx.r7.u64 = weakSpotR7;
				ctx.r8.u64 = weakSpotR8;
				ctx.r9.u64 = weakSpotR9;
				ctx.xer.ca = flags.ca;
				uint32_t ws1 = CECTroll_HasWeakSpot(ctx, base, targetId, tblA);
				vecV10 = ctx.v10;
				vecV11 = ctx.v11;
				vecV12 = ctx.v12;
				vecV13 = ctx.v13;
				flags.ca = ctx.xer.ca;
				if ((ws1 & 0xFF) != 0) {
					uint32_t ws2 = CECTroll_HasWeakSpot(ctx, base, targetId, tblB);
					vecV10 = ctx.v10;
					vecV11 = ctx.v11;
					vecV12 = ctx.v12;
					vecV13 = ctx.v13;
					flags.ca = ctx.xer.ca;
					if ((ws2 & 0xFF) != 0) {
						uint32_t posA = n_sub_825490A8(ctx, base, stack + 128, targetId, tblB, 0);
						flags.ca = ctx.xer.ca;
						ctx.fpscr.disableFlushMode();
						SET_V8(vecA, VLOAD(posA & ~0xF));
						STORE_F32(stack + 80, float(double(LOAD_F32(0x82099334u))));
						uint32_t posB = n_sub_825490A8(ctx, base, stack + 144, targetId, tblA, 0);
						flags.ca = ctx.xer.ca;
						SET_V8(vecB, VLOAD(posB & ~0xF));
						ctx.fpscr.enableFlushMode();

						SET_VF(vecV13, simde_mm_add_ps(VF(vecB), VF(vecA)));
						scratch.u32 = stack + 80;
						SET_V8(vecV12, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						SET_V8(vecV11, simde_mm_shuffle_epi32(V8(vecV12), 0xFF));
						SET_VF(vecV10, simde_mm_mul_ps(VF(vecV13), VF(vecV11)));
						VSTORE((stack + 96) & ~0xF, V8(vecV10));
					}
				}
			}

			// Lazily copy the three per-variant 4-byte colour entries into the
			// shared table at 0x834F71C0.
			uint32_t gfxTable = uint32_t(g_834F0000) + 29120;
			uint32_t gfxInitFlag = uint32_t(g_834F0000) + 29132;
			uint32_t initFlag = LOAD32(gfxInitFlag);
			if ((initFlag & 1) == 0) {
				uint32_t srcA = uint32_t(g_83320000) - 20468;
				uint32_t srcB = uint32_t(g_83320000) - 20460;
				uint32_t srcC = uint32_t(g_83320000) - 20464;
				STORE32(gfxInitFlag, initFlag | 1);
				STORE8(gfxTable + 0, LOAD8(srcA + 0));
				STORE8(gfxTable + 1, LOAD8(srcA + 1));
				STORE8(gfxTable + 2, LOAD8(srcA + 2));
				STORE8(gfxTable + 3, LOAD8(srcA + 3));
				STORE8(gfxTable + 4, LOAD8(srcB + 0));
				STORE8(gfxTable + 5, LOAD8(srcB + 1));
				STORE8(gfxTable + 6, LOAD8(srcB + 2));
				STORE8(gfxTable + 7, LOAD8(srcB + 3));
				STORE8(gfxTable + 8, LOAD8(srcC + 0));
				STORE8(gfxTable + 9, LOAD8(srcC + 1));
				STORE8(gfxTable + 10, LOAD8(srcC + 2));
				STORE8(gfxTable + 11, LOAD8(srcC + 3));
			}

			uint32_t variant = LOAD32(look->m_58 + 8);
			uint32_t entryAddr = gfxTable + (variant << 2);

			SET_V8(vecV1, VLOAD((stack + 96) & ~0xF));
			SET_V8(vecV2, VLOAD((stack + 112) & ~0xF));

			STORE32(stack + 160, 0x820A64F4u);
			STORE32(stack + 164, 0x10004u);
			STORE32(stack + 172, 0);
			STORE32(stack + 176, 0);
			STORE32(stack + 180, 0);
			STORE8(stack + 188, 0);
			STORE8(stack + 184, LOAD8(entryAddr + 0));
			STORE8(stack + 185, LOAD8(entryAddr + 1));
			STORE8(stack + 186, LOAD8(entryAddr + 2));
			STORE8(stack + 187, LOAD8(entryAddr + 3));

			ctx.r4.u64 = variant;
			ctx.v1 = vecV1;
			ctx.v2 = vecV2;
			ctx.v10 = vecV10;
			ctx.v11 = vecV11;
			ctx.v12 = vecV12;
			ctx.v13 = vecV13;
			ctx.xer.ca = flags.ca;
			n_sub_82A3A508(ctx, base, stack + 160);

			n_sub_821DDE30(ctx, base, stack + 160, actorId, 1);

			C_820A64F4_Destructor(ctx, base, stack + 160);

			result = RefCountedPtr_ReleaseAtomic(ctx, base, stack + 88);
		}
	}

	stack = PopStackFrame(stack, 288);
	SET_V8(savedV127, VLOAD((stack + 0xFFFFFFA0u) & ~0xF));
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(47, sub_827045B8, 0x827045B8) { ctx.r3.u64 = n_sub_827045B8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82704F20(CpuState& ctx, uint8_t* base, uint64_t lookAddr) {
	if (!UseLiftedCode(47, 0x82704F20)) { ctx.r3.u64 = lookAddr; __imp__sub_82704F20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82704F20);
	CECLook* look = GameObject<CECLook>(base, lookAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint64_t result = LookAt_ClearLooking(ctx, base, lookAddr + 16);

	PPCVRegister zeroVector;
	SET_V8(zeroVector, simde_mm_set1_epi32(0));

	STORE32((uint32_t)lookAddr + 44, 0);
	look->m_30 = 0;
	// Clear the 16-byte aligned block at look + 0x40.
	VSTORE(((uint32_t)lookAddr + 64u) & ~0xF, V8(zeroVector));

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(47, sub_82704F20, 0x82704F20) { ctx.r3.u64 = n_sub_82704F20(ctx, base, ctx.r3.u64); }
