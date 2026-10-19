// CECTargetingPlayer (vtable 0x82007620): methods of the class as readable C++.
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

uint64_t CECTargetingPlayer_HasTarget(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr) {
	if (!UseLiftedCode(0, 0x82173E48)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_82173E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82173E48);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	uint32_t incremented = targetingPlayer->m_74 + 1;

	return incremented != 0 ? 1 : 0;
}
PROMOTED_ENTRY(0, sub_82173E48, 0x82173E48) { ctx.r3.u64 = CECTargetingPlayer_HasTarget(ctx, base, ctx.r3.u32); }

uint32_t n_sub_82183058(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr) {
	if (!UseLiftedCode(0, 0x82183058)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_82183058(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82183058);
	uint32_t stack = ctx.r1.u64;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	stack = PushStackFrame(base, stack, 112);

	// r6-r8 and xer.ca as the original code leaves them: handed to the n_sub_821E8870 calls below
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR7 = ctx.r7.u64;
	uint64_t passR8 = ctx.r8.u64;
	uint8_t carry = ctx.xer.ca;

	// Component 33: bit 1 of the mask word at +40 says the entity has one. The byte table at +140, when present,
	// gives its index in the (type, component) pairs at +72..+76; otherwise the pairs are searched.
	uint32_t entity = targetingPlayer->m_4;
	if (((LOAD32(entity + 40) >> 1) & 1) == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return 1;
	}

	uint32_t component;
	uint32_t indexTable = LOAD32(entity + 140);
	if (indexTable != 0) {
		uint32_t index = LOAD8(indexTable + 33);
		component = LOAD32(index * 8 + LOAD32(entity + 72) + 4);
	} else {
		uint32_t begin = LOAD32(entity + 72);
		uint32_t end = LOAD32(entity + 76);
		STORE32(stack + 80, 0u);
		STORE32(stack + 84, begin);
		passR6 = end;
		passR8 = (uint64_t)end - begin;
		uint32_t byteCount = (uint32_t)passR8;
		carry = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
		int32_t count = (int32_t)byteCount >> 3;

		// lower_bound for type 33 (types compare signed)
		uint32_t it = begin;
		if (count > 0) {
			// halving a positive count clears the carry
			carry = 0;
			do {
				int32_t half = count >> 1;
				uint32_t step = (uint32_t)half << 3;
				uint32_t mid = it + step;
				bool below = (int32_t)LOAD32(mid) < 33;
				passR7 = below ? 1 : 0;
				passR8 = step;
				if (below) {
					it = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, it);
		}
		// a missing type reads the pair at the end
		if (it != end && (int32_t)LOAD32(it) <= 33) {
			STORE64(stack + 80, LOAD64(stack + 80));
			component = LOAD32(it + 4);
		} else {
			component = LOAD32(end + 4);
		}
	}

	// the object at +20 of the component is queried with ids 18 and 17, then 4
	uint32_t linked = LOAD32(component + 20);
	uint8_t answer = 0;
	if (linked != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = carry;
		answer = (uint8_t)n_sub_821E8870(ctx, base, linked, 18);
		passR6 = ctx.r6.u64;
		passR7 = ctx.r7.u64;
		passR8 = ctx.r8.u64;
		carry = ctx.xer.ca;
	}
	if (answer != 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return 0;
	}

	linked = LOAD32(component + 20);
	if (linked != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = carry;
		answer = (uint8_t)n_sub_821E8870(ctx, base, linked, 17);
		passR6 = ctx.r6.u64;
		passR7 = ctx.r7.u64;
		carry = ctx.xer.ca;
	}
	if (answer != 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return 0;
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.xer.ca = carry;
	uint8_t lookAtButtonDown = (uint8_t)n_sub_822AD108(ctx, base, component);
	if (lookAtButtonDown == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		// callers read xer.ca as it was before the n_sub_822AD108 call
		ctx.xer.ca = carry;
		return 1;
	}

	linked = LOAD32(component + 20);
	answer = 0;
	if (linked != 0) {
		// state the callee may pass on
		answer = (uint8_t)n_sub_821E8870(ctx, base, linked, 4);
		carry = ctx.xer.ca;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read xer.ca after the call
	ctx.xer.ca = carry;
	return answer != 0 ? 1 : 0;
}
PROMOTED_ENTRY(0, sub_82183058, 0x82183058) { ctx.r3.u64 = n_sub_82183058(ctx, base, ctx.r3.u32); }

// sub_8218B9C0  [4 bytes]
uint64_t n_sub_8218B9C0(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(0, 0x8218B9C0)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8218B9C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218B9C0);
	return CECTargetingDog_GetTarget(ctx, base, targetingPlayerAddr);
}
PROMOTED_ENTRY(0, sub_8218B9C0, 0x8218B9C0) { ctx.r3.u64 = n_sub_8218B9C0(ctx, base, ctx.r3.u64); }

// sub_821966B8  [508 bytes]
uint32_t n_sub_821966B8(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4, double deltaTime) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(1, 0x821966B8)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; ctx.f1.f64 = deltaTime; __imp__sub_821966B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821966B8);
	uint32_t stack = ctx.r1.u64;
	// xer.so as on entry: the target-list count below copies it into cr0
	const PPCXERRegister entryXer = ctx.xer;
	PPCRegister callTarget{};
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	const uint32_t entityHandleVtable = uint32_t(g_820F1664);
	const uint32_t targetListAddr = uint32_t(targetingPlayerAddr) + 120;
	const uint64_t handleSlotAddr = targetingPlayerAddr + 156;

	stack = PushStackFrame(base, stack, 160);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg2;
	ctx.r7.u64 = arg3;
	ctx.f1.f64 = deltaTime;
	n_sub_8227F590(ctx, base, targetingPlayerAddr, arg4);

	uint32_t getTargetFn = LOAD32(uint32_t(targetingPlayer->vtable) + 68);
	callTarget.u64 = getTargetFn;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r10.u64 = getTargetFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t currentTarget = ctx.r3.u32;

	uint32_t targetFlag40Set = 0;
	if (currentTarget != 0 && (LOAD8(currentTarget + 144) & 0x40) != 0) {
		targetFlag40Set = 1;
	}

	// r9 and r10 as the original code leaves them: handed to EntityHandle_Release and n_sub_822B7118 below
	uint64_t pendingR9 = targetFlag40Set;
	uint64_t pendingR10 = (uint64_t)(int64_t)g_820F0000;

	if (targetFlag40Set != 0) {
		uint32_t getTargetFn2 = LOAD32(uint32_t(targetingPlayer->vtable) + 68);
		callTarget.u64 = getTargetFn2;
		ctx.r3.u64 = targetingPlayerAddr;
		ctx.r9.u64 = targetFlag40Set;
		ctx.r10.u64 = getTargetFn2;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t TXT_82000EAC_L_ = ctx.r3.u32;

		// the target is looked up in the handle list at +120; the iterators on the stack are { list, position }
		uint32_t listEnd = targetingPlayer->m_80;
		uint32_t listBegin = targetingPlayer->m_7C;
		STORE32(stack + 80, TXT_82000EAC_L_);
		if (listBegin > listEnd) ppc_trap(ctx, base, 22);
		uint32_t listBegin2 = LOAD32(targetListAddr + 4);
		uint32_t listEnd2 = LOAD32(targetListAddr + 8);
		STORE32(stack + 88, targetListAddr);
		STORE32(stack + 92, listEnd);
		if (listBegin2 > listEnd2) ppc_trap(ctx, base, 22);
		STORE32(stack + 100, listBegin2);
		STORE32(stack + 96, targetListAddr);
		uint64_t rangeEnd = LOAD64(stack + 88);
		uint64_t rangeBegin = LOAD64(stack + 96);
		// state the callee may pass on
		ctx.r9.u64 = listEnd2;
		uint32_t foundPos = HandleVector_Find(ctx, base, (uint64_t)stack + 104, rangeBegin, rangeEnd, (uint64_t)stack + 80);

		uint32_t listEnd3 = LOAD32(targetListAddr + 8);
		pendingR9 = LOAD32(targetListAddr + 4);
		STORE64(stack + 96, LOAD64(foundPos));
		if ((uint32_t)pendingR9 > listEnd3) ppc_trap(ctx, base, 22);
		uint32_t foundOwner = LOAD32(stack + 96);
		if (foundOwner == 0 || foundOwner != targetListAddr) ppc_trap(ctx, base, 22);
		pendingR10 = LOAD32(stack + 100);
		if (pendingR10 != listEnd3) {
			uint32_t getTargetFn3 = LOAD32(uint32_t(targetingPlayer->vtable) + 68);
			callTarget.u64 = getTargetFn3;
			ctx.r3.u64 = targetingPlayerAddr;
			ctx.r9.u64 = pendingR9;
			ctx.r10.u64 = getTargetFn3;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t handleTarget = ctx.r3.u64;

			STORE32(stack + 80, entityHandleVtable);
			STORE32(stack + 84, 0);
			EntityHandle_SetTarget(ctx, base, (uint64_t)stack + 80, handleTarget);
			EntityHandle_Assign(ctx, base, handleSlotAddr, (uint64_t)stack + 80);
			STORE32(stack + 80, entityHandleVtable);
			EntityHandle_Release(ctx, base, (uint64_t)stack + 80);
			pendingR9 = ctx.r9.u64;
			pendingR10 = ctx.r10.u64;
		}
	}

	bool targetListEmpty = true;
	uint32_t listBegin3 = targetingPlayer->m_7C;
	if (listBegin3 != 0) {
		pendingR10 = targetingPlayer->m_80;
		pendingR9 = pendingR10 - listBegin3;
		uint32_t byteCount = (uint32_t)pendingR9;
		int32_t elementCount = (int32_t)byteCount >> 3;
		// state the callee may pass on: the count leaves xer.ca and cr0
		ctx.xer.ca = (int32_t)byteCount < 0 && (byteCount & 0x7) != 0;
		ctx.cr0.compare<int32_t>(elementCount, 0, entryXer);
		targetListEmpty = (elementCount == 0);
	}

	if (targetListEmpty) {
		STORE32(stack + 80, entityHandleVtable);
		STORE32(stack + 84, 0);
		// state the callee may pass on
		ctx.r9.u64 = pendingR9;
		ctx.r10.u64 = pendingR10;
		EntityHandle_Release(ctx, base, (uint64_t)stack + 80);
		EntityHandle_Assign(ctx, base, handleSlotAddr, (uint64_t)stack + 80);
		STORE32(stack + 80, entityHandleVtable);
		EntityHandle_Release(ctx, base, (uint64_t)stack + 80);
		pendingR9 = ctx.r9.u64;
		pendingR10 = ctx.r10.u64;
	}

	// state the callee may pass on
	ctx.r9.u64 = pendingR9;
	ctx.r10.u64 = pendingR10;
	n_sub_822B7118(ctx, base, targetingPlayerAddr, ctx.f1.f64);
	n_sub_82188088(ctx, base, targetingPlayerAddr, ctx.f1.f64);
	uint32_t probeResult = n_sub_821AA3F0(ctx, base, (uint32_t)targetingPlayerAddr);

	uint32_t result;
	if ((probeResult & 0xFF) == 0) {
		result = n_sub_822C8608(ctx, base, targetingPlayerAddr);
		if ((result & 0xFF) != 0) {
			result = n_sub_8277A9E8(ctx, base, targetingPlayerAddr, ctx.r6.u64, ctx.r7.u64);
		}
	} else {
		result = n_sub_8277A900(ctx, base, targetingPlayerAddr);
		if ((result & 0xFF) != 0) {
			result = n_sub_8277AB68(ctx, base, targetingPlayerAddr, ctx.r6.u64, ctx.r7.u64);
		}
	}
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_821966B8, 0x821966B8) { ctx.r3.u64 = n_sub_821966B8(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.f1.f64); }

// sub_821AA3F0  [364 bytes]
uint32_t n_sub_821AA3F0(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr) {
	if (!UseLiftedCode(2, 0x821AA3F0)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_821AA3F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821AA3F0);
	uint32_t stack = ctx.r1.u64;
	// xer.so as on entry: the search below copies it into cr0
	PPCXERRegister passXer = ctx.xer;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	stack = PushStackFrame(base, stack, 112);

	ctx.r1.u64 = stack;
	uint32_t resultObject = n_sub_821AA560(ctx, base, targetingPlayer->m_4);
	if (resultObject != 0) {
		uint32_t result = LOAD8(resultObject + 29);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return result;
	}

	// r6-r10, cr0 and xer.ca as the original code leaves them: handed to n_sub_821E8870 below, and left for
	// callers on the paths that return 0
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR7 = ctx.r7.u64;
	uint64_t passR8 = ctx.r8.u64;
	PPCCRRegister passCr0 = ctx.cr0;
	passXer.ca = ctx.xer.ca;

	// Component 33: bit 1 of the mask word at +40 says the entity has one. The byte table at +140, when present,
	// gives its index in the (type, component) pairs at +72..+76; otherwise the pairs are searched.
	uint32_t entityAddr = targetingPlayer->m_4;
	uint32_t maskWord = LOAD32(entityAddr + 40);
	uint64_t passR9 = (maskWord >> 1) & 1;
	uint64_t passR10 = maskWord;
	if (passR9 != 0) {
		uint32_t component;
		uint32_t indexTable = LOAD32(entityAddr + 140);
		if (indexTable != 0) {
			uint32_t pairOffset = LOAD8(indexTable + 33) * 8;
			passR10 = pairOffset;
			passR9 = (uint64_t)pairOffset + LOAD32(entityAddr + 72);
			component = LOAD32((uint32_t)passR9 + 4);
		} else {
			uint32_t begin = LOAD32(entityAddr + 72);
			uint32_t end = LOAD32(entityAddr + 76);
			STORE32(stack + 80, 0);
			STORE32(stack + 84, begin);
			passR6 = end;
			passR8 = (uint64_t)end - begin;
			passR9 = 0;
			uint32_t byteCount = (uint32_t)passR8;
			passXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			int32_t count = (int32_t)byteCount >> 3;
			passCr0.compare<int32_t>(count, 0, passXer);

			// lower_bound for type 33 (types compare signed); the cursor stays 64-bit like the r10 it is left in
			uint64_t cursor = begin;
			if (count > 0) {
				// halving a positive count clears the carry
				passXer.ca = 0;
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					passR9 = (uint32_t)half;
					passR8 = step;
					cursor += step;
					bool below = (int32_t)LOAD32((uint32_t)cursor) < 33;
					passR7 = below ? 1 : 0;
					if (below) {
						cursor += 8;
						count = count - half - 1;
					} else {
						cursor -= step;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, (uint32_t)cursor);
			}
			passR10 = cursor;
			// a missing type reads the pair at the end
			if ((uint32_t)cursor != end && (int32_t)LOAD32((uint32_t)cursor) <= 33) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component = LOAD32((uint32_t)cursor + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}

		if (component != 0) {
			uint32_t linked = LOAD32(component + 20);
			if (linked != 0) {
				// state the callee may pass on
				ctx.cr0 = passCr0;
				ctx.xer.ca = passXer.ca;
				uint32_t result = (uint32_t)n_sub_821E8870(ctx, base, linked, 21);
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return result;
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read these after the call
	ctx.r6.u64 = passR6;
	ctx.r7.u64 = passR7;
	ctx.r8.u64 = passR8;
	ctx.r9.u64 = passR9;
	ctx.r10.u64 = passR10;
	ctx.cr0 = passCr0;
	ctx.xer.ca = passXer.ca;
	return 0;
}
PROMOTED_ENTRY(2, sub_821AA3F0, 0x821AA3F0) { ctx.r3.u64 = n_sub_821AA3F0(ctx, base, ctx.r3.u32); }

// sub_82224690  [8 bytes]
uint64_t CECTargetingPlayer_GetTarget(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(6, 0x82224690)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_82224690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82224690);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	return targetingPlayer->m_Target;
}
PROMOTED_ENTRY(6, sub_82224690, 0x82224690) { ctx.r3.u64 = CECTargetingPlayer_GetTarget(ctx, base, ctx.r3.u64); }

uint64_t SharedPtr_CreateInventoryItem(CpuState& ctx, uint8_t* base, uint64_t sharedPtrAddr, uint64_t itemType, uint64_t itemName, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_821A0000 = int32_t(0x821A0000);
	constexpr int32_t n_sub_821981B0_address = int32_t(0x821981B0);
	if (!UseLiftedCode(12, 0x822B9510)) { ctx.r3.u64 = sharedPtrAddr; ctx.r4.u64 = itemType; ctx.r5.u64 = itemName; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_822B9510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B9510);
	uint32_t stack = ctx.r1.u64;
	// a two-word smart pointer: the managed object at +0 (the class view's vtable field) and its control block at +4
	CECTargetingPlayer* sharedPtr = GameObject<CECTargetingPlayer>(base, sharedPtrAddr);

	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on; n_sub_822B95B0 below takes r6 and r7 as the allocation leaves them
	ctx.r1.u64 = stack;
	ctx.r4.u64 = itemType;
	ctx.r5.u64 = itemName;
	ctx.r6.u64 = arg4;
	uint64_t itemStorage = operator_new(ctx, base, 16);

	uint32_t item = 0;
	if ((uint32_t)itemStorage != 0) {
		item = n_sub_822B95B0(ctx, base, itemStorage, itemType, itemName, ctx.r6.u64, ctx.r7.u64);
	}
	sharedPtr->vtable = item;

	if (item != 0) {
		uint32_t controlBlock = (uint32_t)operator_new(ctx, base, 12);
		if (controlBlock != 0) {
			// SharedPtr control block: { refCount = 1, deleter, managed item }
			uint32_t managedItem = sharedPtr->vtable;
			uint64_t deleter = (uint64_t)(n_sub_821981B0_address);
			STORE32(controlBlock, 1);
			STORE32(controlBlock + 4, (uint32_t)deleter);
			STORE32(controlBlock + 8, managedItem);
			sharedPtr->m_4 = controlBlock;

			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			// callers read r7-r10 after the call
			ctx.r7.u64 = deleter;
			ctx.r8.u64 = 1;
			ctx.r9.s64 = g_821A0000;
			ctx.r10.u64 = managedItem;
			return sharedPtrAddr;
		}
	}

	sharedPtr->m_4 = 0u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return sharedPtrAddr;
}
PROMOTED_ENTRY(12, sub_822B9510, 0x822B9510) { ctx.r3.u64 = SharedPtr_CreateInventoryItem(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_822C80A8(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr) {
	constexpr int32_t g_8349B180 = int32_t(0x8349B180);
	if (!UseLiftedCode(12, 0x822C80A8)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_822C80A8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822C80A8);
	uint32_t stack = ctx.r1.u64;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	stack = PushStackFrame(base, stack, 128);

	// xer.ca as the original code leaves it: handed to the calls below and left for callers at every return
	uint8_t carry = ctx.xer.ca;
	auto finish = [&](uint32_t result) -> uint32_t {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.xer.ca = carry;
		return result;
	};

	if (LOAD8(0x83319483u) == 0) {
		return finish(1);
	}

	ctx.r1.u64 = stack;
	uint32_t firstCheck = (uint32_t)n_sub_822C7F38(ctx, base, targetingPlayer->m_4);
	// r7 and r8 as the call leaves them; with r6 and r9 (set further down) they are handed to the calls below
	uint64_t passR7 = ctx.r7.u64;
	uint64_t passR8 = ctx.r8.u64;
	carry = ctx.xer.ca;
	if (firstCheck != 0) {
		return finish(1);
	}

	// The entity's components: a bit per type in the mask words from +36 says it has one; the byte table at +140,
	// when present, gives the type's index in the (type, component) pairs at +72..+76. Without the table the pairs
	// are searched (lower_bound through the cursor at stack+84, types compare signed) and a missing type reads the
	// pair at the end. The search leaves its last step in r7 and r8, and sets xer.ca.
	struct PairSearch {
		uint32_t component;
		uint32_t end;
		bool stepped;  // the halving loop ran
		int32_t lastHalf;
	};
	auto searchPairs = [&](uint32_t entity, int32_t type) -> PairSearch {
		PairSearch search{};
		uint32_t it = LOAD32(entity + 72);
		search.end = LOAD32(entity + 76);
		STORE32(stack + 80, 0);
		STORE32(stack + 84, it);
		uint32_t byteCount = search.end - it;
		carry = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
		int32_t count = (int32_t)byteCount >> 3;
		if (count > 0) {
			// halving a positive count clears the carry
			carry = 0;
			do {
				int32_t half = count >> 1;
				uint32_t step = (uint32_t)half << 3;
				uint32_t mid = it + step;
				bool below = (int32_t)LOAD32(mid) < type;
				passR7 = below ? 1 : 0;
				passR8 = step;
				search.lastHalf = half;
				if (below) {
					it = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			search.stepped = true;
			STORE32(stack + 84, it);
		}
		if (it != search.end && (int32_t)LOAD32(it) <= type) {
			STORE64(stack + 80, LOAD64(stack + 80));
			search.component = LOAD32(it + 4);
		} else {
			search.component = LOAD32(search.end + 4);
		}
		return search;
	};

	uint32_t entity = targetingPlayer->m_4;
	uint64_t passR6 = entity;

	// type 146: bit 18 of the word at +52; a nonzero byte at +36 of its component returns 1
	if ((LOAD32(entity + 52) >> 18) & 1) {
		uint32_t component;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t index = LOAD8(indexTable + 146);
			component = LOAD32(index * 8 + LOAD32(entity + 72) + 4);
		} else {
			component = searchPairs(entity, 146).component;
		}
		if (LOAD8(component + 36) != 0) {
			return finish(1);
		}
	}

	// type 24: bit 24 of the word at +36 (the low bit of its first byte); no component passes 0
	uint32_t component24 = 0;
	if (LOAD8(entity + 36) & 0x1) {
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t index = LOAD8(indexTable + 24);
			component24 = LOAD32(index * 8 + LOAD32(entity + 72) + 4);
		} else {
			PairSearch search = searchPairs(entity, 24);
			passR6 = search.end;
			component24 = search.component;
		}
	}
	// state the callee may pass on
	ctx.xer.ca = carry;
	uint8_t checkResult = (uint8_t)n_sub_822C6940(ctx, base, component24, g_8349B180);
	passR6 = ctx.r6.u64;
	passR7 = ctx.r7.u64;
	passR8 = ctx.r8.u64;
	carry = ctx.xer.ca;
	if (checkResult == 0) {
		return finish(1);
	}

	// type 33: bit 1 of the word at +40; the object at +20 of its component is queried with ids 11, 13, 17, 18
	entity = targetingPlayer->m_4;
	if ((LOAD32(entity + 40) >> 1) & 1) {
		uint32_t component;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t pairOffset = LOAD8(indexTable + 33) * 8;
			passR8 = (uint64_t)pairOffset + LOAD32(entity + 72);
			component = LOAD32((uint32_t)passR8 + 4);
		} else {
			PairSearch search = searchPairs(entity, 33);
			passR6 = search.end;
			component = search.component;
		}
		for (uint32_t queryId : { 11u, 13u, 17u, 18u }) {
			uint32_t linked = LOAD32(component + 20);
			if (linked == 0) {
				continue;
			}
			// state the callee may pass on
			ctx.xer.ca = carry;
			uint8_t answer = (uint8_t)n_sub_821E8870(ctx, base, linked, queryId);
			passR6 = ctx.r6.u64;
			passR7 = ctx.r7.u64;
			passR8 = ctx.r8.u64;
			carry = ctx.xer.ca;
			if (answer != 0) {
				return finish(1);
			}
		}
	}

	// type 21: bit 21 of the word at +36; its component is checked for modes 6 and 7
	entity = targetingPlayer->m_4;
	uint64_t passR9 = (LOAD32(entity + 36) >> 21) & 1;
	if (passR9 != 0) {
		uint32_t component;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			passR9 = LOAD8(indexTable + 21);
			passR8 = (uint64_t)((uint32_t)passR9 * 8) + LOAD32(entity + 72);
			component = LOAD32((uint32_t)passR8 + 4);
		} else {
			PairSearch search = searchPairs(entity, 21);
			passR6 = search.end;
			if (search.stepped) {
				passR9 = (uint64_t)(int64_t)search.lastHalf;
			}
			component = search.component;
		}
		// state the callee may pass on
		ctx.xer.ca = carry;
		uint8_t hasMode = (uint8_t)CECEntityModeManager_HasMode(ctx, base, component, 6);
		carry = ctx.xer.ca;
		if (hasMode != 0) {
			return finish(1);
		}
		hasMode = (uint8_t)CECEntityModeManager_HasMode(ctx, base, component, 7);
		carry = ctx.xer.ca;
		if (hasMode != 0) {
			return finish(1);
		}
	}

	return finish(0);
}
PROMOTED_ENTRY(12, sub_822C80A8, 0x822C80A8) { ctx.r3.u64 = n_sub_822C80A8(ctx, base, ctx.r3.u32); }

uint32_t n_sub_822C8608(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(12, 0x822C8608)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_822C8608(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822C8608);
	uint32_t stack = ctx.r1.u64;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	// v126/v127 are saved below the caller's stack pointer because the vectors below use them;
	// the callers' copies in ctx are never changed
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(ctx.v126));
	VSTORE((stack + 0xFFFFFFE0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 208);
	ctx.r1.u64 = stack;

	// register state the lifted code hands to callees and leaves for callers
	PPCXERRegister flags = ctx.xer;
	uint32_t firstCheck = n_sub_822C80A8(ctx, base, targetingPlayerAddr);
	uint64_t regR4 = ctx.r4.u64;
	uint64_t regR6 = ctx.r6.u64;
	uint64_t regR7 = ctx.r7.u64;
	uint64_t regR8 = ctx.r8.u64;
	PPCVRegister regV12 = ctx.v12;
	PPCCRRegister cond = ctx.cr0;
	flags.ca = ctx.xer.ca;

	// callers read r0, r4, r6-r8, v12, cr0 and the carry after the call
	auto finish = [&](uint32_t result) -> uint32_t {
		stack = PopStackFrame(stack, 208);
		ctx.r0.u64 = 0xFFFFFFE0u;  // offset of the v127 restore
		ctx.r1.u64 = stack;
		ctx.r4.u64 = regR4;
		ctx.r6.u64 = regR6;
		ctx.r7.u64 = regR7;
		ctx.r8.u64 = regR8;
		ctx.v12 = regV12;
		ctx.cr0.lt = cond.lt; ctx.cr0.gt = cond.gt; ctx.cr0.eq = cond.eq; ctx.cr0.so = cond.so;
		ctx.xer.ca = flags.ca;
		return result;
	};

	if ((firstCheck & 0xFF) != 0)
		return finish(0);

	uint32_t secondCheck = n_sub_8277A330(ctx, base, targetingPlayerAddr);
	regR4 = ctx.r4.u64;
	regR6 = ctx.r6.u64;
	regR7 = ctx.r7.u64;
	regR8 = ctx.r8.u64;
	regV12 = ctx.v12;
	cond.lt = ctx.cr0.lt; cond.gt = ctx.cr0.gt; cond.eq = ctx.cr0.eq; cond.so = ctx.cr0.so;
	flags.ca = ctx.xer.ca;
	if ((secondCheck & 0xFF) != 0)
		return finish(1);

	// m_7C .. m_80 holds 8-byte entries; without any the result is 0
	uint32_t entriesBegin = targetingPlayer->m_7C;
	if (entriesBegin == 0)
		return finish(0);
	uint32_t entriesBytes = (uint32_t)targetingPlayer->m_80 - entriesBegin;
	flags.ca = (int32_t)entriesBytes < 0 && (entriesBytes & 7) != 0;
	int32_t entryCount = (int32_t)entriesBytes >> 3;
	cond.compare<int32_t>(entryCount, 0, flags);
	if (entryCount == 0)
		return finish(0);

	uint32_t objectAt88 = targetingPlayer->m_88;
	if (objectAt88 != 0) {
		// the vector stored at the start of the m_88 object is compared with vectors obtained
		// from the object at owner+124
		uint32_t owner = targetingPlayer->m_4;
		PPCVRegister vectorAt88;
		SET_V8(vectorAt88, VLOAD(objectAt88 & ~0xF));
		uint64_t methodVectorAddr = (uint64_t)stack + 96;
		uint32_t ownerObject = LOAD32(owner + 124);
		uint32_t vtable = LOAD32(ownerObject);
		uint32_t method = LOAD32(vtable + 64);
		// state the callee may pass on
		ctx.r3.u64 = methodVectorAddr;
		ctx.r4.u64 = ownerObject;
		ctx.cr0.lt = cond.lt; ctx.cr0.gt = cond.gt; ctx.cr0.eq = cond.eq; ctx.cr0.so = cond.so;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(method);
		cond.lt = ctx.cr0.lt; cond.gt = ctx.cr0.gt; cond.eq = ctx.cr0.eq; cond.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;

		uint32_t ownerAgain = targetingPlayer->m_4;
		uint64_t helperVectorAddr = (uint64_t)stack + 80;
		uint32_t ownerObjectAgain = LOAD32(ownerAgain + 124);
		PPCVRegister methodVector;
		SET_V8(methodVector, VLOAD((uint32_t)methodVectorAddr & ~0xF));
		// state the callee may pass on
		n_sub_82268BE0(ctx, base, helperVectorAddr, ownerObjectAgain);
		regR6 = ctx.r6.u64;
		regR7 = ctx.r7.u64;
		regR8 = ctx.r8.u64;
		cond.lt = ctx.cr0.lt; cond.gt = ctx.cr0.gt; cond.eq = ctx.cr0.eq; cond.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;

		// three-component dot product of the masked difference with the vector at stack+80;
		// below the threshold the result is 0
		ctx.fpscr.enableFlushMode();
		PPCVRegister difference;
		SET_VF(difference, simde_mm_sub_ps(VF(vectorAt88), VF(methodVector)));
		regR4 = helperVectorAddr;
		PPCVRegister helperVector;
		SET_V8(helperVector, VLOAD((uint32_t)regR4 & ~0xF));
		PPCVRegister mask;
		SET_V8(mask, VLOAD(0x82099150u & ~0xF));
		ctx.fpscr.disableFlushModeUnconditional();
		double threshold = double(LOAD_F32(0x820994B4u));
		SET_V8(regV12, simde_mm_and_si128(V8(difference), V8(mask)));
		ctx.fpscr.enableFlushModeUnconditional();
		PPCVRegister dot;
		SET_VF(dot, simde_mm_dp_ps(VF(regV12), VF(helperVector), 0xEF));
		VSTORE((stack + 80) & ~0xF, V8(dot));
		ctx.fpscr.disableFlushModeUnconditional();
		if (double(LOAD_F32(stack + 80)) < threshold)
			return finish(0);
	}

	// keyed entry 146 of the owner; bit 18 of owner+52 gates the lookup
	uint32_t tableOwner = targetingPlayer->m_4;
	regR8 = (LOAD32(tableOwner + 52) >> 18) & 1;
	if (regR8 != 0) {
		uint32_t entry146;
		uint32_t indexTable = LOAD32(tableOwner + 140);
		if (indexTable != 0) {
			uint32_t index = LOAD8(indexTable + 146);
			uint32_t table = LOAD32(tableOwner + 72);
			entry146 = LOAD32((index << 3) + table + 4);
		} else {
			// binary search over the sorted (int32 key, value) pairs from owner+72 to owner+76
			uint32_t cursor = LOAD32(tableOwner + 72);
			regR6 = LOAD32(tableOwner + 76);
			uint32_t end = (uint32_t)regR6;
			STORE32(stack + 80, 0u);
			regR8 = regR6 - cursor;
			STORE32(stack + 84, cursor);
			flags.ca = (int32_t)regR8 < 0 && ((uint32_t)regR8 & 7) != 0;
			int32_t remaining = (int32_t)regR8 >> 3;
			cond.compare<int32_t>(remaining, 0, flags);
			if (remaining > 0) {
				do {
					flags.ca = 0;  // the halving shift sets the carry only for negative counts
					int32_t half = remaining >> 1;
					regR8 = (uint32_t)half << 3;
					uint32_t middle = cursor + (uint32_t)regR8;
					regR7 = (int32_t)LOAD32(middle) < 146 ? 1 : 0;
					if (regR7 != 0) {
						remaining = remaining - half - 1;
						cursor = middle + 8;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, cursor);
			}
			// the entry the search stopped on, unless it is the end or has a larger key;
			// otherwise the entry at the end pointer
			if (cursor != end && (int32_t)LOAD32(cursor) <= 146) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entry146 = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry146 = LOAD32(end + 4);
			}
		}
		if (LOAD8(entry146 + 36) != 0)
			return finish(0);
	}

	objectAt88 = targetingPlayer->m_88;
	if (objectAt88 == 0)
		return finish(0);
	regR4 = targetingPlayer->m_90;
	if ((uint32_t)regR4 == 0)
		return finish(0);
	// state the callee may pass on
	ctx.v12 = regV12;
	ctx.cr0.lt = cond.lt; ctx.cr0.gt = cond.gt; ctx.cr0.eq = cond.eq; ctx.cr0.so = cond.so;
	uint32_t pairCheck = n_sub_8289F5A0(ctx, base, objectAt88, (uint32_t)regR4, stack + 112);
	regR4 = ctx.r4.u64;
	regR6 = ctx.r6.u64;
	regR7 = ctx.r7.u64;
	regR8 = ctx.r8.u64;
	regV12 = ctx.v12;
	if ((pairCheck & 0xFF) != 0)
		return finish(1);

	// the pair is checked again in both orders; the r4 argument stays the r4 left for callers
	uint32_t objectAt90 = targetingPlayer->m_90;
	objectAt88 = targetingPlayer->m_88;
	regR4 = objectAt90;
	uint32_t forwardCheck = n_sub_8289F548(ctx, base, objectAt88, objectAt90);
	regV12 = ctx.v12;
	if ((forwardCheck & 0xFF) != 0)
		return finish(1);
	regR4 = objectAt88;
	uint32_t backwardCheck = n_sub_8289F548(ctx, base, objectAt90, objectAt88);
	regV12 = ctx.v12;
	if ((backwardCheck & 0xFF) != 0)
		return finish(1);
	return finish(0);
}
PROMOTED_ENTRY(12, sub_822C8608, 0x822C8608) { ctx.r3.u64 = n_sub_822C8608(ctx, base, ctx.r3.u64); }

uint64_t CECTargetingPlayer_GetTarget_822D3EC0(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(13, 0x822D3EC0)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_822D3EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3EC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	// The target handle at +0xB0 reaches the target through the cell its second word points to;
	// a handle whose cell is empty is released and no target is returned.
	uint64_t targetHandleAddr = targetingPlayerAddr + 0xB0;
	uint32_t targetCell = LOAD32((uint32_t)targetHandleAddr + 4);
	if (targetCell != 0) {
		uint32_t TXT_82000EAC_L_ = LOAD32(targetCell);
		if (TXT_82000EAC_L_ != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return TXT_82000EAC_L_;
		}
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r10.u64 = 0;  // the empty cell's value
		EntityHandle_Release(ctx, base, targetHandleAddr);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(13, sub_822D3EC0, 0x822D3EC0) { ctx.r3.u64 = CECTargetingPlayer_GetTarget_822D3EC0(ctx, base, ctx.r3.u64); }

uint32_t n_sub_822D9A98(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr) {
	constexpr int32_t g_822E0000 = int32_t(0x822E0000);
	if (!UseLiftedCode(13, 0x822D9A98)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_822D9A98(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822D9A98);
	uint32_t stack = ctx.r1.u64;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	stack = PushStackFrame(base, stack, 128);

	// register state the lifted code hands to callees and leaves for callers
	uint64_t regR0 = ctx.r0.u64;
	uint64_t regR6 = ctx.r6.u64;
	uint64_t regR7 = ctx.r7.u64;
	uint64_t regR8 = ctx.r8.u64;
	uint64_t regR9 = 0;
	PPCXERRegister flags = ctx.xer;

	// state the callee may pass on
	auto handOverState = [&]() {
		ctx.r1.u64 = stack;
		ctx.r6.u64 = regR6;
		ctx.r7.u64 = regR7;
		ctx.r8.u64 = regR8;
		ctx.r9.u64 = regR9;
		ctx.xer.ca = flags.ca;
	};
	auto readBackState = [&]() {
		regR0 = ctx.r0.u64;
		regR6 = ctx.r6.u64;
		regR7 = ctx.r7.u64;
		regR8 = ctx.r8.u64;
		regR9 = ctx.r9.u64;
		flags.ca = ctx.xer.ca;
	};
	// callers read r0 after the call
	auto returnFalse = [&]() -> uint32_t {
		stack = PopStackFrame(stack, 128);
		ctx.r0.u64 = regR0;
		ctx.r1.u64 = stack;
		return 0;
	};
	// callers read r0, r6-r9 and the carry after the call
	auto returnTrue = [&]() -> uint32_t {
		stack = PopStackFrame(stack, 128);
		ctx.r0.u64 = regR0;
		ctx.r1.u64 = stack;
		ctx.r6.u64 = regR6;
		ctx.r7.u64 = regR7;
		ctx.r8.u64 = regR8;
		ctx.r9.u64 = regR9;
		ctx.xer.ca = flags.ca;
		return 1;
	};

	// Binary search for `key` over the owner's sorted (int32 key, value) pairs from owner+72 to
	// owner+76. Yields the value of the entry the search stops on, unless that is the end or has
	// a larger key; otherwise the value of the entry at the end pointer.
	auto searchKeyedTable = [&](uint32_t owner, int32_t key) -> uint32_t {
		uint32_t cursor = LOAD32(owner + 72);
		regR6 = LOAD32(owner + 76);
		uint32_t end = (uint32_t)regR6;
		STORE32(stack + 80, 0u);
		uint32_t tableBytes = end - cursor;
		STORE32(stack + 84, cursor);
		flags.ca = (int32_t)tableBytes < 0 && (tableBytes & 7) != 0;
		int32_t remaining = (int32_t)tableBytes >> 3;
		if (remaining > 0) {
			do {
				flags.ca = 0;  // the halving shift sets the carry only for negative counts
				int32_t half = remaining >> 1;
				regR9 = (uint32_t)half;
				regR8 = (uint32_t)half << 3;
				uint32_t middle = cursor + (uint32_t)regR8;
				regR7 = (int32_t)LOAD32(middle) < key ? 1 : 0;
				if (regR7 != 0) {
					remaining = remaining - half - 1;
					cursor = middle + 8;
				} else {
					remaining = half;
				}
			} while (remaining > 0);
			STORE32(stack + 84, cursor);
		}
		if (cursor != end && (int32_t)LOAD32(cursor) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	// keyed entry 33 of the owner (m_4); bit 1 of owner+40 gates the lookup, without it the result is 1
	uint32_t owner = targetingPlayer->m_4;
	regR9 = (LOAD32(owner + 40) >> 1) & 1;
	if (regR9 == 0)
		return returnTrue();
	uint32_t entry33;
	uint32_t indexTable = LOAD32(owner + 140);
	if (indexTable != 0) {
		uint32_t index = LOAD8(indexTable + 33);
		uint32_t table = LOAD32(owner + 72);
		regR9 = uint64_t(index << 3) + table;
		entry33 = LOAD32((uint32_t)regR9 + 4);
	} else {
		entry33 = searchKeyedTable(owner, 33);
	}

	// asks n_sub_821E8870 about `id` for the object at entry33+20 (false when there is none)
	auto queryLinked = [&](uint32_t id) -> bool {
		uint32_t linked = LOAD32(entry33 + 20);
		if (linked == 0)
			return false;
		handOverState();
		uint32_t answer = n_sub_821E8870(ctx, base, linked, id);
		readBackState();
		return (answer & 0xFF) != 0;
	};
	if (queryLinked(4))
		return returnTrue();
	if (queryLinked(23))
		return returnTrue();
	if (queryLinked(22)) {
		handOverState();
		uint32_t answer = n_sub_821AA3F0(ctx, base, targetingPlayerAddr);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return (answer & 0xFF) == 0 ? 1 : 0;
	}

	// keyed entry 154; bit 26 of owner+52 gates the lookup
	uint32_t ownerAgain = targetingPlayer->m_4;
	regR9 = LOAD32(ownerAgain + 52);
	regR8 = ((uint32_t)regR9 >> 26) & 1;
	if (regR8 != 0) {
		uint32_t entry154;
		uint32_t indexTable154 = LOAD32(ownerAgain + 140);
		if (indexTable154 != 0) {
			regR9 = LOAD8(indexTable154 + 154);
			regR8 = uint64_t((uint32_t)regR9 << 3) + LOAD32(ownerAgain + 72);
			entry154 = LOAD32((uint32_t)regR8 + 4);
		} else {
			entry154 = searchKeyedTable(ownerAgain, 154);
		}
		if (LOAD8(entry154 + 12) != 0)
			return returnTrue();
	}

	handOverState();
	uint64_t linkedObject = n_sub_821B8960(ctx, base, entry33);
	regR0 = ctx.r0.u64;
	if ((uint32_t)linkedObject == 0)
		return returnFalse();
	uint32_t method = LOAD32(LOAD32((uint32_t)linkedObject) + 32);
	// state the callee may pass on
	ctx.r3.u64 = linkedObject;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	uint32_t code = ctx.r3.u32;
	readBackState();
	// codes 1, 5, 20 and 23 give 1, every other code gives 0
	uint32_t caseIndex = code - 1;
	if (caseIndex > 22)
		return returnFalse();
	// r0 keeps the jump-table entry the original switch loads
	regR0 = LOAD32(uint32_t(g_822E0000) - 25152 + (caseIndex << 2));
	switch (caseIndex) {
	case 0:
	case 4:
	case 19:
	case 22:
		return returnTrue();
	default:
		return returnFalse();
	}
}
PROMOTED_ENTRY(13, sub_822D9A98, 0x822D9A98) { ctx.r3.u64 = n_sub_822D9A98(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8253CD60(CpuState& ctx, uint8_t* base, uint32_t luaTableRef, uint64_t fieldName, uint64_t luaObject, uint64_t passedR6, uint64_t passedR7) {
	if (!UseLiftedCode(33, 0x8253CD60)) { ctx.r3.u64 = luaTableRef; ctx.r4.u64 = fieldName; ctx.r5.u64 = luaObject; ctx.r6.u64 = passedR6; ctx.r7.u64 = passedR7; __imp__sub_8253CD60(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8253CD60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// without a script binding the first argument is returned and r4/r6/r7 keep their incoming values
	uint32_t result = luaTableRef;
	uint64_t r4Out = fieldName;
	uint64_t r6Out = passedR6;
	uint64_t r7Out = passedR7;
	uint32_t scriptBinding = LOAD32(luaTableRef);
	if (scriptBinding != 0) {
		// the binding holds the Lua state and a registry reference
		uint32_t luaState = LOAD32(scriptBinding);
		uint32_t registryRef = LOAD32(scriptBinding + 4);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, luaState, -10000, registryRef);
		Lua_PushObjectUserdata(ctx, base, luaState, luaObject, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		result = lua_setfield(ctx, base, luaState, -2, fieldName);
		r4Out = ctx.r4.u64;
		r6Out = ctx.r6.u64;
		r7Out = ctx.r7.u64;
		// pop the value lua_rawgeti pushed (one 8-byte slot below the stack top at +8)
		STORE32(luaState + 8, LOAD32(luaState + 8) - 8);
	}
	stack = PopStackFrame(stack, 112);
	// callers read r4, r6 and r7 after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	ctx.r6.u64 = r6Out;
	ctx.r7.u64 = r7Out;
	return result;
}
PROMOTED_ENTRY(33, sub_8253CD60, 0x8253CD60) { ctx.r3.u64 = n_sub_8253CD60(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

uint64_t CECTargetingPlayer_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8A14_B_ = int32_t(0x820C8A14);
	if (!UseLiftedCode(51, 0x82778CB8)) { ctx.r3.u64 = classNameString; __imp__sub_82778CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82778CB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	const int32_t length = -1;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820C8A14_B_, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(51, sub_82778CB8, 0x82778CB8) { ctx.r3.u64 = CECTargetingPlayer_GetClassName(ctx, base, ctx.r3.u64); }

void n_sub_82778CF8(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr, uint32_t byteValue) {
	if (!UseLiftedCode(51, 0x82778CF8)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r4.u64 = byteValue; __imp__sub_82778CF8(ctx, base); return; }
	LiftedFrame frame(0x82778CF8);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	targetingPlayer->m_CC = (uint8_t)byteValue;
}
PROMOTED_ENTRY(51, sub_82778CF8, 0x82778CF8) { n_sub_82778CF8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82778D00(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x82778D00)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_82778D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82778D00);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	return targetingPlayer->m_CC;
}
PROMOTED_ENTRY(51, sub_82778D00, 0x82778D00) { ctx.r3.u64 = n_sub_82778D00(ctx, base, ctx.r3.u64); }

void n_sub_82778D08(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr, uint32_t byteValue) {
	if (!UseLiftedCode(51, 0x82778D08)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r4.u64 = byteValue; __imp__sub_82778D08(ctx, base); return; }
	LiftedFrame frame(0x82778D08);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	targetingPlayer->m_CD = (uint8_t)byteValue;
}
PROMOTED_ENTRY(51, sub_82778D08, 0x82778D08) { n_sub_82778D08(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82778D10(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x82778D10)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_82778D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82778D10);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	return targetingPlayer->m_CD;
}
PROMOTED_ENTRY(51, sub_82778D10, 0x82778D10) { ctx.r3.u64 = n_sub_82778D10(ctx, base, ctx.r3.u64); }

void n_sub_82778D18(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr, uint32_t fieldValue) {
	if (!UseLiftedCode(51, 0x82778D18)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r4.u64 = fieldValue; __imp__sub_82778D18(ctx, base); return; }
	LiftedFrame frame(0x82778D18);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	targetingPlayer->m_D0 = fieldValue;
}
PROMOTED_ENTRY(51, sub_82778D18, 0x82778D18) { n_sub_82778D18(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82778D20(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x82778D20)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_82778D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82778D20);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	return targetingPlayer->m_D0;
}
PROMOTED_ENTRY(51, sub_82778D20, 0x82778D20) { ctx.r3.u64 = n_sub_82778D20(ctx, base, ctx.r3.u64); }

// sub_82779510  [80 bytes]
uint64_t n_sub_82779510(CpuState& ctx, uint8_t* base, uint64_t targetPtr, uint64_t flags) {
	if (!UseLiftedCode(51, 0x82779510)) { ctx.r3.u64 = targetPtr; ctx.r4.u64 = flags; __imp__sub_82779510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82779510);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = flags;  // state the callee may pass on
	n_sub_82779560(ctx, base, targetPtr);
	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, targetPtr);
	}
	return targetPtr;
}
PROMOTED_ENTRY(51, sub_82779510, 0x82779510) { ctx.r3.u64 = n_sub_82779510(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82779B90(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(51, 0x82779B90)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_82779B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82779B90);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	stack = PushStackFrame(base, stack, 128);

	// Look up the record for key 33 in the table of m_4. reg6-reg9 and carry follow what the original
	// code leaves in r6-r9 and xer.ca on the way.
	uint32_t recordSet = targetingPlayer->m_4;
	uint32_t setFlags = LOAD32(recordSet + 40);
	bool haveRecord = ((setFlags >> 1) & 1) != 0;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = haveRecord ? 1 : 0;
	uint64_t reg9 = setFlags;
	uint8_t carry = ctx.xer.ca;
	uint32_t recordAddr = 0;
	if (haveRecord) {
		uint32_t slotHandle = LOAD32(recordSet + 140);
		if (slotHandle != 0) {
			reg9 = (uint64_t)LOAD32(recordSet + 72) + (uint64_t)LOAD8(slotHandle + 33) * 8;
			recordAddr = LOAD32((uint32_t)reg9 + 4);
		} else {
			uint32_t begin = LOAD32(recordSet + 72);
			uint32_t end = LOAD32(recordSet + 76);
			reg6 = end;
			reg8 = (uint64_t)end - (uint64_t)begin;
			reg9 = 0;
			carry = (int32_t)reg8 < 0 && (reg8 & 0x7) != 0;
			// std::lower_bound for key 33 over the 8-byte {key, record} entries.
			uint32_t it = begin;
			int32_t count = (int32_t)reg8 >> 3;
			while (count > 0) {
				int32_t step = count >> 1;
				reg9 = (uint32_t)step;
				reg8 = (uint32_t)step << 3;
				uint32_t mid = it + (uint32_t)reg8;
				reg7 = (int32_t)LOAD32(mid) < 33 ? 1 : 0;
				if (reg7 != 0) {
					it = mid + 8;
					count -= step + 1;
				} else {
					count = step;
				}
			}
			if (it != end && (int32_t)LOAD32(it) <= 33) {
				recordAddr = LOAD32(it + 4);
			} else {
				recordAddr = LOAD32(end + 4);
			}
		}
	}
	// State the calls below may pass on: the first call made receives these values, each later one
	// what the previous call left (the original hands the same registers on unchanged).
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = reg9;
	ctx.xer.ca = carry;

	if (haveRecord) {
		uint32_t TXT_82000EAC_L_ = LOAD32(recordAddr + 20);
		if (TXT_82000EAC_L_ != 0) {
			ctx.r1.u64 = stack;
			if ((n_sub_821E8870(ctx, base, TXT_82000EAC_L_, 4) & 0xFF) != 0) {
				uint32_t method = LOAD32((uint32_t)targetingPlayer->vtable + 68);
				callTarget.u64 = method;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = targetingPlayerAddr;
				ctx.r10.u64 = method;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				uint32_t currentTarget = ctx.r3.u32;
				if (currentTarget != 0 && (LOAD8(currentTarget + 144) & 64) != 0) {
					method = LOAD32((uint32_t)targetingPlayer->vtable + 68);
					callTarget.u64 = method;
					ctx.r3.u64 = targetingPlayerAddr;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					stack = PopStackFrame(stack, 128);
					ctx.r1.u64 = stack;
					return ctx.r3.u64;
				}
			}
		}
	}

	uint32_t globalBlock = (uint32_t)g_83320000;
	if ((int32_t)targetingPlayer->m_B8 > 0) {
		ctx.r1.u64 = stack;
		uint32_t candidate = (uint32_t)CECTargetingPlayer_GetTarget_822D3EC0(ctx, base, targetingPlayerAddr);
		if (candidate != 0 && (LOAD8(candidate + 144) & 64) != 0) {
			ctx.fpscr.disableFlushMode();
			double timeScale = LOAD_F64(globalBlock - 27376);
			uint64_t tickDelta = (uint64_t)LOAD32(globalBlock - 27380) - (uint64_t)(uint32_t)targetingPlayer->m_B8;
			int32_t ticks = (int32_t)tickDelta;
			double ticksAsDouble = double(ticks);
			double exactElapsed = ticksAsDouble / timeScale;
			double elapsed = double(float(exactElapsed));
			double minElapsed = double(LOAD_F32(globalBlock - 27528));
			PPCRegister lowerLimit{};
			lowerLimit.f64 = double(LOAD_F32(0x820994B4u));
			if (elapsed > minElapsed && !(minElapsed < lowerLimit.f64)) {
				// state the callee may pass on
				ctx.f12 = lowerLimit;
				uint64_t result = CECTargetingPlayer_GetTarget_822D3EC0(ctx, base, targetingPlayerAddr);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return result;
			}
		}
	}

	ctx.fpscr.disableFlushMode();
	double timeScale = LOAD_F64(globalBlock - 27376);
	uint64_t tickDelta = (uint64_t)LOAD32(globalBlock - 27380) - (uint64_t)(uint32_t)targetingPlayer->m_AC;
	int32_t ticks = (int32_t)tickDelta;
	double ticksAsDouble = double(ticks);
	double exactElapsed = ticksAsDouble / timeScale;
	double elapsed = double(float(exactElapsed));
	// The original leaves these in registers from here on: the calls below receive them (each later
	// call what the previous one left) and callers read r9 after the final return.
	ctx.r7.s64 = ticks;
	ctx.r8.u64 = tickDelta;
	ctx.r9.s64 = g_83320000;
	ctx.f9.f64 = elapsed;
	ctx.f10.f64 = exactElapsed;
	ctx.f11.f64 = ticksAsDouble;
	ctx.f12.s64 = ticks;
	ctx.f13.f64 = timeScale;

	if (elapsed < double(LOAD_F32(globalBlock - 27572))) {
		uint64_t handleAddr = targetingPlayerAddr + 164;
		uint32_t handleOwner = targetingPlayer->m_A8;
		if (handleOwner != 0) {
			uint32_t handleValue = LOAD32(handleOwner);
			ctx.r1.u64 = stack;
			ctx.r10.u64 = handleValue;  // state the callee may pass on
			if (handleValue == 0) {
				EntityHandle_Release(ctx, base, handleAddr);
			} else {
				uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
				if ((LOAD8(entity + 144) & 64) != 0) {
					ctx.r1.u64 = stack;
					ctx.r10.u64 = 64;  // state the callee may pass on
					uint64_t result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
					stack = PopStackFrame(stack, 128);
					ctx.r1.u64 = stack;
					return result;
				}
			}
		}
	}

	uint32_t fallbackEnabled = LOAD8(0x833193FEu);
	if (fallbackEnabled != 0) {
		uint64_t handleAddr = targetingPlayerAddr + 156;
		ctx.r1.u64 = stack;
		ctx.r10.u64 = fallbackEnabled;  // state the callee may pass on
		uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
		if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = 64;  // state the callee may pass on
			uint64_t result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return result;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// r9 and xer.ca already hold what callers read: set above or left by the last call.
	return 0;
}
PROMOTED_ENTRY(51, sub_82779B90, 0x82779B90) { ctx.r3.u64 = n_sub_82779B90(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8277A078(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x8277A078)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277A078(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8277A078);
	uint32_t stack = ctx.r1.u64;

	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	// fctiwz: truncate toward zero to a 32-bit integer (NaN gives 0x80000000, too large values INT_MAX).
	// The code reads the integer back as the low word of the stored double.
	auto truncateToInt = [](double value) -> int64_t {
		return std::isnan(value) ? int64_t(0x80000000U)
		     : value > double(INT_MAX) ? int64_t(INT_MAX)
		     : int64_t(simde_mm_cvttsd_si32(simde_mm_load_sd(&value)));
	};

	uint64_t entityHandlesAddr = targetingPlayerAddr + 120;
	double radius = double(LOAD_F32(0x83319450u));

	stack = PushStackFrame(base, stack, 320);
	ctx.r1.u64 = stack;
	EntityHandleVector_Clear(ctx, base, entityHandlesAddr);

	uint32_t owner = targetingPlayer->m_4;
	uint32_t ownerPart = LOAD32(owner + 124);
	uint32_t ownerPartVtable = LOAD32(ownerPart);
	uint32_t getVectorFn = LOAD32(ownerPartVtable + 64);

	PPCRegister callTarget{};
	PPCVRegister vec{};
	PPCRegister xIntReg{};
	PPCRegister yIntReg{};

	uint32_t result;
	if (LOAD8(0x833193FDu) != 0) {
		// Read the vector, truncate its x/y to integers, read the vector again, then fill the query
		// blocks with an integer box of +-radius around the truncated (x, y).
		uint32_t firstVec = stack + 192;
		callTarget.u64 = (uint64_t)getVectorFn;
		ctx.r3.u64 = firstVec;
		ctx.r4.u64 = ownerPart;
		ctx.r9.u64 = getVectorFn;
		ctx.r10.u64 = ownerPartVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t owner2 = targetingPlayer->m_4;
		uint32_t ownerPart2 = LOAD32(owner2 + 124);
		uint32_t localVec = stack + 96;
		uint32_t secondVec = stack + 240;
		SET_V8(vec, VLOAD(firstVec & ~0xF));
		VSTORE(localVec & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		double x = double(LOAD_F32(stack + 96));
		xIntReg.s64 = truncateToInt(x);
		uint32_t ownerPartVtable2 = LOAD32(ownerPart2);
		VSTORE(localVec & ~0xF, V8(vec));
		double y = double(LOAD_F32(stack + 100));
		yIntReg.s64 = truncateToInt(y);
		STORE_F64(stack + 80, xIntReg.f64);
		uint32_t xInt = LOAD32(stack + 84);
		STORE_F64(stack + 80, yIntReg.f64);
		uint32_t yInt = LOAD32(stack + 84);
		uint32_t getVectorFn2 = LOAD32(ownerPartVtable2 + 64);
		callTarget.u64 = (uint64_t)getVectorFn2;
		// state the callee may pass on
		ctx.r3.u64 = secondVec;
		ctx.r4.u64 = ownerPart2;
		ctx.r5.u64 = owner2;
		ctx.r6.u64 = localVec;
		ctx.r7.u64 = localVec;
		ctx.r8.u64 = firstVec;
		ctx.r10.u64 = getVectorFn2;
		ctx.f11 = xIntReg;
		ctx.f12 = yIntReg;
		ctx.f13.f64 = y;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		ctx.fpscr.disableFlushMode();

		PPCRegister radiusIntReg{};
		radiusIntReg.s64 = truncateToInt(radius);
		STORE_F64(stack + 80, radiusIntReg.f64);
		uint32_t radiusInt = LOAD32(stack + 84);
		PPCRegister radiusSq{};
		radiusSq.f64 = double(float(radius * radius));
		STORE_F32(stack + 172, float(radiusSq.f64));
		SET_V8(vec, VLOAD((stack + 240) & ~0xF));
		VSTORE((stack + 80) & ~0xF, V8(vec));
		double vecZ = double(LOAD_F32(stack + 88));
		uint32_t owner3 = targetingPlayer->m_4;
		VSTORE((stack + 96) & ~0xF, V8(vec));
		STORE32(stack + 136, stack + 160);
		double vecY = double(LOAD_F32(stack + 100));
		VSTORE((stack + 96) & ~0xF, V8(vec));
		uint64_t maxX = (uint64_t)radiusInt + (uint64_t)xInt;
		double vecX = double(LOAD_F32(stack + 96));
		STORE_F32(stack + 160, float(vecX));
		STORE32(stack + 120, owner3);
		STORE32(stack + 128, stack + 120);
		STORE32(stack + 132, stack + 113);
		STORE_F32(stack + 164, float(vecY));
		STORE32(stack + 96, 8u);
		STORE_F32(stack + 168, float(vecZ));
		STORE32(stack + 92, (uint32_t)(yInt + radiusInt));
		STORE32(stack + 80, (uint32_t)(xInt - radiusInt));
		STORE32(stack + 104, (uint32_t)entityHandlesAddr);
		uint32_t queryBlock = stack + 96;
		STORE32(stack + 84, (uint32_t)(yInt - radiusInt));
		uint32_t boxBlock = stack + 80;
		STORE32(stack + 88, (uint32_t)maxX);
		STORE32(stack + 100, stack + 128);
		uint32_t root = LOAD32(0x83496920u);
		uint32_t receiver = LOAD32(LOAD32(LOAD32(LOAD32(root + 12) + 88) + 4) + 12);
		// state the callee may pass on
		ctx.f9 = radiusSq;
		ctx.f10 = radiusIntReg;
		result = n_sub_8277C5D8(ctx, base, receiver, boxBlock, queryBlock);
	} else {
		uint32_t firstVec = stack + 208;
		callTarget.u64 = (uint64_t)getVectorFn;
		ctx.r3.u64 = firstVec;
		ctx.r4.u64 = ownerPart;
		ctx.r9.u64 = getVectorFn;
		ctx.r10.u64 = ownerPartVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t localVec = stack + 96;
		uint32_t owner2 = targetingPlayer->m_4;
		uint32_t otherVec = stack + 80;
		uint32_t secondVec = stack + 224;
		SET_V8(vec, VLOAD(firstVec & ~0xF));
		VSTORE(localVec & ~0xF, V8(vec));
		uint32_t ownerPart2 = LOAD32(owner2 + 124);
		VSTORE(otherVec & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		double x = double(LOAD_F32(stack + 80));
		xIntReg.s64 = truncateToInt(x);
		uint32_t ownerPartVtable2 = LOAD32(ownerPart2);
		double y = double(LOAD_F32(stack + 100));
		yIntReg.s64 = truncateToInt(y);
		STORE_F64(stack + 96, xIntReg.f64);
		STORE_F64(stack + 80, yIntReg.f64);
		uint32_t xInt = LOAD32(stack + 100);
		uint32_t yInt = LOAD32(stack + 84);
		uint32_t getVectorFn2 = LOAD32(ownerPartVtable2 + 64);
		callTarget.u64 = (uint64_t)getVectorFn2;
		// state the callee may pass on
		ctx.r3.u64 = secondVec;
		ctx.r4.u64 = ownerPart2;
		ctx.r5.u64 = owner2;
		ctx.r6.u64 = localVec;
		ctx.r7.u64 = otherVec;
		ctx.r8.u64 = firstVec;
		ctx.r10.u64 = getVectorFn2;
		ctx.f11 = xIntReg;
		ctx.f12.f64 = x;
		ctx.f13 = yIntReg;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		ctx.fpscr.disableFlushMode();

		PPCRegister radiusIntReg{};
		radiusIntReg.s64 = truncateToInt(radius);
		PPCRegister radiusSq{};
		radiusSq.f64 = double(float(radius * radius));
		STORE_F32(stack + 156, float(radiusSq.f64));
		SET_V8(vec, VLOAD((stack + 224) & ~0xF));
		VSTORE((stack + 80) & ~0xF, V8(vec));
		STORE32(stack + 184, stack + 112);
		VSTORE((stack + 96) & ~0xF, V8(vec));
		VSTORE((stack + 256) & ~0xF, V8(vec));
		double vecZ = double(LOAD_F32(stack + 104));
		STORE32(stack + 180, stack + 124);
		double vecX = double(LOAD_F32(stack + 80));
		STORE32(stack + 188, stack + 144);
		double vecY = double(LOAD_F32(stack + 260));
		STORE_F64(stack + 96, radiusIntReg.f64);
		uint32_t radiusInt = LOAD32(stack + 100);
		STORE32(stack + 116, 6u);
		STORE32(stack + 104, (uint32_t)entityHandlesAddr);
		uint32_t owner3 = targetingPlayer->m_4;
		STORE32(stack + 176, stack + 116);
		uint32_t maxX = xInt + radiusInt;
		uint32_t minX = xInt - radiusInt;
		uint32_t maxY = yInt + radiusInt;
		uint32_t minY = yInt - radiusInt;
		STORE_F32(stack + 152, float(vecZ));
		STORE_F32(stack + 144, float(vecX));
		STORE_F32(stack + 148, float(vecY));
		STORE32(stack + 124, owner3);
		STORE32(stack + 88, maxX);
		STORE32(stack + 84, minY);
		STORE32(stack + 96, 8u);
		STORE32(stack + 80, minX);
		STORE32(stack + 92, maxY);
		STORE32(stack + 100, stack + 176);
		uint32_t root = LOAD32(0x83496920u);
		uint32_t level1 = LOAD32(root + 12);
		uint32_t level2 = LOAD32(level1 + 88);
		uint32_t receiver = LOAD32(LOAD32(level2 + 4) + 12);
		// state the callee may pass on
		ctx.f9 = radiusIntReg;
		ctx.f10 = radiusSq;
		result = n_sub_8277C768(ctx, base, receiver, stack + 80, stack + 96);
	}
	stack = PopStackFrame(stack, 320);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_8277A078, 0x8277A078) { ctx.r3.u64 = n_sub_8277A078(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8277A330(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x8277A330)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277A330(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8277A330);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	stack = PushStackFrame(base, stack, 128);
	uint32_t outA = stack + 80;
	uint32_t outB = stack + 96;

	// Look up the record for key 33 in the table of m_4. reg6-reg9 follow what the original code
	// leaves in r6-r9 on the way; the first call below receives them.
	uint32_t owner = targetingPlayer->m_4;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = 0;
	uint32_t entry = 0;
	if (((LOAD32(owner + 40) >> 1) & 1) != 0) {
		uint32_t sparseIndex = LOAD32(owner + 140);
		if (sparseIndex != 0) {
			reg9 = (uint64_t)LOAD32(owner + 72) + (uint64_t)LOAD8(sparseIndex + 33) * 8;
			entry = LOAD32((uint32_t)reg9 + 4);
		} else {
			uint32_t begin = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			reg6 = end;
			reg8 = (uint64_t)end - (uint64_t)begin;
			STORE32(outA, 0);
			STORE32(outA + 4, begin);
			// xer.ca from the count shift: the first call below and callers read it.
			ctx.xer.ca = (int32_t)reg8 < 0 && (reg8 & 0x7) != 0;
			// std::lower_bound for key 33 over the 8-byte {key, record} entries.
			int32_t remaining = (int32_t)reg8 >> 3;
			uint32_t found = begin;
			if (remaining > 0) {
				do {
					int32_t step = remaining >> 1;
					reg9 = (uint32_t)step;
					reg8 = (uint32_t)step << 3;
					uint32_t mid = found + (uint32_t)reg8;
					reg7 = (int32_t)LOAD32(mid) < 33 ? 1 : 0;
					if (reg7 != 0) {
						remaining = remaining - step - 1;
						found = mid + 8;
					} else {
						remaining = step;
					}
				} while (remaining > 0);
				STORE32(outA + 4, found);
			}
			if (found != end && (int32_t)LOAD32(found) <= 33) {
				entry = LOAD32(found + 4);
			} else {
				entry = LOAD32(end + 4);
			}
		}
	}

	// Later calls receive r6-r9 and xer.ca as the previous call left them, as in the original.
	bool targetIsValid = false;
	if (entry != 0) {
		uint32_t sub = LOAD32(entry + 20);
		if (sub != 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			if ((n_sub_821E8870(ctx, base, sub, 4) & 0xFF) != 0) {
				uint32_t method = LOAD32((uint32_t)targetingPlayer->vtable + 68);
				callTarget.u64 = method;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = targetingPlayerAddr;
				ctx.r10.u64 = method;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				uint32_t TXT_82000EAC_L_ = ctx.r3.u32;
				targetIsValid = TXT_82000EAC_L_ != 0 && (LOAD8(TXT_82000EAC_L_ + 144) & 64) != 0;
			}
		}
	}

	uint32_t result = 0;
	if (targetIsValid) {
		uint32_t method = LOAD32((uint32_t)targetingPlayer->vtable + 68);
		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = targetingPlayerAddr;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t TXT_82000EAC_L_ = ctx.r3.u32;
		if (TXT_82000EAC_L_ != 0 && (LOAD8(TXT_82000EAC_L_ + 144) & 64) != 0) {
			method = LOAD32((uint32_t)targetingPlayer->vtable + 68);
			callTarget.u64 = method;
			ctx.r3.u64 = targetingPlayerAddr;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t obj = ctx.r3.u64;

			uint32_t handlerA = LOAD32((uint32_t)obj + 124);
			uint32_t vtblA = LOAD32(handlerA);
			uint32_t methodA = LOAD32(vtblA + 64);
			callTarget.u64 = methodA;
			// state the callee may pass on
			ctx.r7.u64 = methodA;
			ctx.r8.u64 = vtblA;
			ctx.r9.u64 = obj;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint32_t owner2 = targetingPlayer->m_4;
			uint32_t handlerB = LOAD32(owner2 + 124);
			uint32_t vtblB = LOAD32(handlerB);
			callTarget.u64 = LOAD32(vtblB + 64);
			// state the callee may pass on
			ctx.r3.u64 = outB;
			ctx.r4.u64 = handlerB;
			ctx.r5.u64 = vtblB;
			ctx.r6.u64 = owner2;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			// Squared length of (outA - outB) over the components the mask keeps, against the
			// square of the limit at 0x83319474.
			PPCVRegister outAVec{};
			PPCVRegister outBVec{};
			PPCVRegister diff{};
			PPCVRegister componentMask{};
			PPCVRegister maskedDiff{};
			PPCVRegister dotResult{};
			SET_V8(outBVec, VLOAD(outB & ~0xFu));
			SET_V8(outAVec, VLOAD(outA & ~0xFu));
			ctx.fpscr.enableFlushMode();
			SET_VF(diff, simde_mm_sub_ps(VF(outAVec), VF(outBVec)));
			ctx.fpscr.disableFlushModeUnconditional();
			double limit = double(LOAD_F32(0x83319474u));
			SET_V8(componentMask, VLOAD(0x82099150u & ~0xFu));
			double limitSquared = double(float(limit * limit));
			SET_V8(maskedDiff, simde_mm_and_si128(V8(diff), V8(componentMask)));
			ctx.fpscr.enableFlushModeUnconditional();
			SET_VF(dotResult, simde_mm_dp_ps(VF(maskedDiff), VF(diff), 0xEF));
			VSTORE(outB & ~0xFu, V8(dotResult));
			ctx.fpscr.disableFlushModeUnconditional();
			result = double(LOAD_F32(outB)) < limitSquared ? 1 : 0;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// xer.ca already holds what callers read: set above or left by the last call.
	return result;
}
PROMOTED_ENTRY(51, sub_8277A330, 0x8277A330) { ctx.r3.u64 = n_sub_8277A330(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8277A900(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x8277A900)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277A900(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8277A900);
	uint32_t stack = ctx.r1.u64;
	const PPCXERRegister entryXer = ctx.xer;  // its summary-overflow bit goes into cr0 below
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;
	auto leave = [&](uint32_t result) -> uint32_t {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	};

	if ((n_sub_822C80A8(ctx, base, targetingPlayerAddr) & 0xFF) != 0) {
		return leave(1);
	}
	if ((n_sub_8277A330(ctx, base, targetingPlayerAddr) & 0xFF) != 0) {
		return leave(0);
	}
	uint32_t listBegin = targetingPlayer->m_7C;
	if (listBegin == 0) {
		return leave(1);
	}

	// Callers read xer.ca, cr0 and r4 after this function. From here on the original leaves xer.ca =
	// carry of the count shift on every return and cr0 = the count compared with 0 on the returns of 1.
	uint32_t listBytes = targetingPlayer->m_80 - listBegin;
	int32_t listCount = (int32_t)listBytes >> 3;
	uint8_t countCarry = (int32_t)listBytes < 0 && (listBytes & 0x7) != 0;
	PPCCRRegister countCompare{};
	countCompare.compare<int32_t>(listCount, 0, entryXer);
	ctx.cr0 = countCompare;  // also state the first callee below may pass on

	uint32_t objectA = targetingPlayer->m_88;
	if (listCount == 0 || objectA == 0) {
		ctx.xer.ca = countCarry;
		return leave(1);
	}
	uint32_t objectB = targetingPlayer->m_90;
	if (objectB == 0) {
		ctx.r4.u64 = objectB;
		ctx.xer.ca = countCarry;
		return leave(1);
	}
	if ((n_sub_8289F5A0(ctx, base, objectA, objectB, stack + 80) & 0xFF) != 0) {
		ctx.xer.ca = countCarry;
		return leave(0);
	}
	// Read again: the call above may have changed them.
	objectB = targetingPlayer->m_90;
	objectA = targetingPlayer->m_88;
	if ((n_sub_8289F548(ctx, base, objectA, objectB) & 0xFF) != 0) {
		ctx.r4.u64 = objectB;
		ctx.xer.ca = countCarry;
		return leave(0);
	}
	if ((n_sub_8289F548(ctx, base, objectB, objectA) & 0xFF) != 0) {
		ctx.r4.u64 = objectA;
		ctx.xer.ca = countCarry;
		return leave(0);
	}
	ctx.r4.u64 = objectA;
	ctx.cr0 = countCompare;
	ctx.xer.ca = countCarry;
	return leave(1);
}
PROMOTED_ENTRY(51, sub_8277A900, 0x8277A900) { ctx.r3.u64 = n_sub_8277A900(ctx, base, ctx.r3.u64); }

// sub_8277A9E8  [384 bytes]
uint32_t n_sub_8277A9E8(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(51, 0x8277A9E8)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_8277A9E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8277A9E8);
	uint32_t stack = ctx.r1.u64;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// state the callee may pass on; n_sub_827B20A8 below gets r6/r7 as this call leaves them
	ctx.r6.u64 = arg2;
	ctx.r7.u64 = arg3;
	uint64_t existing = n_sub_821AA560(ctx, base, targetingPlayer->m_4);
	if ((uint32_t)existing != 0) {
		uint32_t updateResult = n_sub_827B20A8(ctx, base, existing, 1, ctx.r6.u64, ctx.r7.u64);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return updateResult;
	}

	// r6, r8 and xer.ca as operator_new receives them; the table search below changes them
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;

	uint32_t result = 0;
	uint32_t owner = targetingPlayer->m_4;
	if (((LOAD32(owner + 40) >> 1) & 1) != 0) {
		// The owner's component under key 33: from the cached index table when there is one,
		// otherwise by a lower_bound search of the sorted 8-byte (key, component) entries.
		uint32_t keyedComponent;
		uint32_t indexCache = LOAD32(owner + 140);
		if (indexCache != 0) {
			uint32_t index = LOAD8(indexCache + 33);
			keyedComponent = LOAD32(LOAD32(owner + 72) + index * 8 + 4);
		} else {
			uint32_t entry = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			passR6 = end;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, entry);
			int32_t byteCount = (int32_t)(end - entry);
			int32_t count = byteCount >> 3;
			flags.ca = byteCount < 0 && (byteCount & 0x7) != 0;
			if (count > 0) {
				flags.ca = 0;  // halving a positive count leaves carry clear
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					passR8 = step;
					uint32_t mid = entry + step;
					if ((int32_t)LOAD32(mid) < 33) {
						entry = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, entry);
			}
			uint32_t found = end;
			if (entry != end && (int32_t)LOAD32(entry) <= 33) {
				STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the 8-byte result unchanged
				found = entry;
			}
			keyedComponent = LOAD32(found + 4);
		}

		if (keyedComponent != 0) {
			// state the callee may pass on
			ctx.r6.u64 = passR6;
			ctx.r8.u64 = passR8;
			ctx.xer.ca = flags.ca;
			uint64_t memory = operator_new(ctx, base, 84);
			uint32_t lookAt = 0;
			if ((uint32_t)memory != 0) {
				lookAt = CLookAtComponent_Ctor(ctx, base, memory, targetingPlayer->m_4);
			}
			// stack+80 holds a shared pointer: the new component, then its control block
			STORE32(stack + 80, lookAt);
			if (lookAt != 0) {
				uint64_t sharedPtr = SharedPtr_CreateControlBlock(ctx, base, (uint64_t)stack + 80);
				uint32_t attachResult = n_sub_823C8880(ctx, base, keyedComponent, sharedPtr);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return attachResult;
			}
			STORE32(stack + 84, 0);
			result = n_sub_823C8880(ctx, base, keyedComponent, (uint64_t)stack + 80);
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_8277A9E8, 0x8277A9E8) { ctx.r3.u64 = n_sub_8277A9E8(ctx, base, ctx.r3.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8277AB68(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(51, 0x8277AB68)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_8277AB68(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8277AB68);
	uint32_t stack = ctx.r1.u64;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	// r6, r7, r8, cr0 and xer.ca as the calls below receive them; the table search and each call change them
	uint64_t passR6 = arg2;
	uint64_t passR7 = arg3;
	uint64_t passR8 = ctx.r8.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	auto handOverState = [&]() {
		ctx.r1.u64 = stack;
		ctx.r6.u64 = passR6;
		ctx.r7.u64 = passR7;
		ctx.r8.u64 = passR8;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
	};
	auto takeBackState = [&]() {
		passR6 = ctx.r6.u64;
		passR7 = ctx.r7.u64;
		passR8 = ctx.r8.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
	};

	stack = PushStackFrame(base, stack, 112);
	uint32_t owner = targetingPlayer->m_4;
	if (((LOAD32(owner + 40) >> 1) & 1) != 0) {
		// The owner's component under key 33: from the cached index table when there is one,
		// otherwise by a lower_bound search of the sorted 8-byte (key, component) entries.
		uint32_t keyedComponent;
		uint32_t indexCache = LOAD32(owner + 140);
		if (indexCache != 0) {
			uint32_t index = LOAD8(indexCache + 33);
			keyedComponent = LOAD32(LOAD32(owner + 72) + index * 8 + 4);
		} else {
			uint32_t entry = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			STORE32(stack + 80, 0u);
			STORE32(stack + 84, entry);
			uint64_t byteCount = (uint64_t)end - entry;
			int32_t count = (int32_t)byteCount >> 3;
			flags.ca = (int32_t)byteCount < 0 && ((uint32_t)byteCount & 0x7) != 0;
			compare0.compare<int32_t>(count, 0, flags);
			passR6 = end;
			passR8 = byteCount;
			if (count > 0) {
				flags.ca = 0;  // halving a positive count leaves carry clear
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					uint32_t mid = entry + step;
					bool below = (int32_t)LOAD32(mid) < 33;
					passR7 = below;
					passR8 = step;
					if (below) {
						entry = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, entry);
			}
			uint32_t found = end;
			if (entry != end && (int32_t)LOAD32(entry) <= 33) {
				STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the 8-byte result unchanged
				found = entry;
			}
			keyedComponent = LOAD32(found + 4);
		}

		if (keyedComponent != 0) {
			uint32_t linked = LOAD32(keyedComponent + 20);
			bool passed = false;
			if (linked != 0) {
				handOverState();
				passed = (n_sub_821E8870(ctx, base, linked, 21) & 0xFF) != 0;
				takeBackState();
			}
			if (passed) {
				uint32_t linkedNow = LOAD32(keyedComponent + 20);
				handOverState();
				n_sub_8238F4A0(ctx, base, linkedNow, 21);
				takeBackState();
			}
		}
	}

	handOverState();
	uint64_t result = n_sub_821AA560(ctx, base, targetingPlayer->m_4);
	if ((uint32_t)result != 0) {
		result = n_sub_827B20A8(ctx, base, result, 0, ctx.r6.u64, ctx.r7.u64);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(51, sub_8277AB68, 0x8277AB68) { ctx.r3.u64 = n_sub_8277AB68(ctx, base, ctx.r3.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_8277B2B0(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(51, 0x8277B2B0)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277B2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277B2B0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	stack = PushStackFrame(base, stack, 144);

	// virtual slot 68 returns an entity in r3
	uint32_t slotFn = LOAD32(uint32_t(targetingPlayer->vtable) + 68);
	callTarget.u64 = slotFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r10.u64 = slotFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t entityBefore = ctx.r3.u32;

	// r6-r9 and xer.ca as the calls below receive them; each call and table search changes them
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR7 = ctx.r7.u64;
	uint64_t passR8 = 0;
	uint64_t passR9 = 0;
	PPCXERRegister flags = ctx.xer;
	auto handOverState = [&]() {
		ctx.r6.u64 = passR6;
		ctx.r7.u64 = passR7;
		ctx.r8.u64 = passR8;
		ctx.r9.u64 = passR9;
		ctx.xer.ca = flags.ca;
	};
	auto takeBackState = [&]() {
		passR6 = ctx.r6.u64;
		passR7 = ctx.r7.u64;
		passR8 = ctx.r8.u64;
		passR9 = ctx.r9.u64;
		flags.ca = ctx.xer.ca;
	};
	auto isActive = [&](uint32_t entity) {
		return entity != 0 && (LOAD8(entity + 144) & 64) != 0;
	};
	// The entity's component under the given key: from its cached index table when there is one,
	// otherwise by a lower_bound search of its sorted 8-byte (key, component) entries with
	// stack+80 as scratch. Sets r6-r9 and xer.ca as the original search does.
	auto findComponent = [&](uint32_t entity, int32_t key) -> uint32_t {
		uint32_t indexCache = LOAD32(entity + 140);
		if (indexCache != 0) {
			uint32_t index = LOAD8(indexCache + key);
			passR9 = (uint64_t)(index * 8) + LOAD32(entity + 72);
			return LOAD32((uint32_t)passR9 + 4);
		}
		uint32_t entry = LOAD32(entity + 72);
		uint32_t end = LOAD32(entity + 76);
		passR6 = end;
		STORE32(stack + 80, 0);
		STORE32(stack + 84, entry);
		int32_t byteCount = (int32_t)(end - entry);
		int32_t count = byteCount >> 3;
		flags.ca = byteCount < 0 && (byteCount & 0x7) != 0;
		if (count > 0) {
			flags.ca = 0;  // halving a positive count leaves carry clear
			do {
				int32_t half = count >> 1;
				uint32_t step = (uint32_t)half << 3;
				uint32_t mid = entry + step;
				bool below = (int32_t)LOAD32(mid) < key;
				passR7 = below;
				passR8 = step;
				passR9 = (uint64_t)half;
				if (below) {
					entry = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, entry);
		}
		if (entry != end && (int32_t)LOAD32(entry) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the 8-byte result unchanged
			return LOAD32(entry + 4);
		}
		return LOAD32(end + 4);
	};

	// together with whether entityBefore is still active, these decide whether the m_C call below runs
	bool forceCall = true;
	bool holdCall = false;

	uint32_t owner = targetingPlayer->m_4;
	uint32_t ownerFlags = LOAD32(owner + 40);
	passR9 = ownerFlags;
	passR8 = (ownerFlags >> 1) & 1;
	if (passR8 != 0) {
		uint32_t component = findComponent(owner, 33);
		uint32_t linked = LOAD32(component + 20);
		bool passed4 = false;
		if (linked != 0) {
			handOverState();
			passed4 = (n_sub_821E8870(ctx, base, linked, 4) & 0xFF) != 0;
			takeBackState();
		}

		bool checkEntityBefore = passed4;
		if (!passed4) {
			uint32_t settings = LOAD32(uint32_t(g_83490000) + 26788);
			passR9 = LOAD8(LOAD32(settings + 28) + 34);
			checkEntityBefore = passR9 != 0;
			if (!checkEntityBefore) {
				targetingPlayer->m_D4 = 0;
				uint32_t linkedNow = LOAD32(component + 20);
				bool passed23 = false;
				if (linkedNow != 0) {
					handOverState();
					passed23 = (n_sub_821E8870(ctx, base, linkedNow, 23) & 0xFF) != 0;
					takeBackState();
				}
				if (passed23) {
					forceCall = false;
					holdCall = true;
				}
			}
		}

		if (checkEntityBefore) {
			forceCall = false;
			if (isActive(entityBefore)) {
				passR9 = (LOAD32(entityBefore + 36) >> 20) & 1;
				if (passR9 != 0) {
					uint32_t entityComponent = findComponent(entityBefore, 20);
					if (LOAD8(entityComponent + 24) == 0) {
						// virtual slot 112 with r4 = 1
						forceCall = true;
						slotFn = LOAD32(uint32_t(targetingPlayer->vtable) + 112);
						callTarget.u64 = slotFn;
						ctx.r3.u64 = targetingPlayerAddr;
						ctx.r4.u64 = 1;
						handOverState();
						ctx.r10.u64 = slotFn;
						REX_CALL_INDIRECT_FUNC(callTarget.u32);
						takeBackState();
					}
				}
				// virtual slot 124
				slotFn = LOAD32(uint32_t(targetingPlayer->vtable) + 124);
				callTarget.u64 = slotFn;
				ctx.r3.u64 = targetingPlayerAddr;
				handOverState();
				ctx.r10.u64 = slotFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				uint32_t slot124Result = ctx.r3.u32;
				takeBackState();
				if (slot124Result != 0) {
					forceCall = true;
				}
			} else if (targetingPlayer->m_D4 != 0) {
				// virtual slot 112 with r4 = 1
				forceCall = true;
				slotFn = LOAD32(uint32_t(targetingPlayer->vtable) + 112);
				callTarget.u64 = slotFn;
				ctx.r3.u64 = targetingPlayerAddr;
				ctx.r4.u64 = 1;
				handOverState();
				ctx.r10.u64 = slotFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				takeBackState();
			} else {
				handOverState();
				uint32_t handleEntity = (uint32_t)EntityHandle_Get_316(ctx, base, component);
				takeBackState();
				if (isActive(handleEntity)) {
					holdCall = true;
				}
			}
		}
	}

	if (targetingPlayer->m_15 != 0) {
		forceCall = false;
		holdCall = true;
	}
	bool entityBeforeActive = isActive(entityBefore);
	if (forceCall || (!entityBeforeActive && !holdCall)) {
		// first virtual function of the m_C object, called with this object
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t objectC = targetingPlayer->m_C;
		uint32_t rootChild = LOAD32(globalRoot + 12);
		uint32_t objectCVtable = LOAD32(objectC);
		uint32_t rootChild88 = LOAD32(rootChild + 88);
		uint32_t objectCFn = LOAD32(objectCVtable);
		uint32_t playerData = LOAD32(rootChild88 + 4);
		uint32_t playerData12 = LOAD32(playerData + 12);
		callTarget.u64 = objectCFn;
		ctx.r3.u64 = objectC;
		ctx.r4.u64 = targetingPlayerAddr;
		ctx.r5.u64 = playerData12;
		ctx.r6.u64 = passR6;
		// state the callee may pass on
		ctx.r7.u64 = playerData;
		ctx.r8.u64 = objectCFn;
		ctx.r9.u64 = rootChild88;
		ctx.r10.u64 = objectCVtable;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		takeBackState();
	}

	// virtual slot 68 again; when the entity changed and the owner is a player, m_20 takes the
	// global at 0x8331948C
	slotFn = LOAD32(uint32_t(targetingPlayer->vtable) + 68);
	callTarget.u64 = slotFn;
	ctx.r3.u64 = targetingPlayerAddr;
	handOverState();
	ctx.r10.u64 = slotFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t entityAfter = ctx.r3.u32;
	passR8 = ctx.r8.u64;
	if (entityBefore != entityAfter) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t playerData = LOAD32(LOAD32(LOAD32(globalRoot + 12) + 88) + 4);
		ctx.r9.u64 = playerData;  // state the callee may pass on
		uint32_t isPlayer = (uint32_t)Players_IsPlayer(ctx, base, LOAD32(playerData), targetingPlayer->m_4);
		passR8 = isPlayer & 0xFF;
		if (passR8 != 0) {
			targetingPlayer->m_20 = LOAD32(uint32_t(g_83320000) - 27380);
		}
	}

	// virtual slot 112 with r4 = 0; r8 as set above, the other registers as the last call left them
	slotFn = LOAD32(uint32_t(targetingPlayer->vtable) + 112);
	callTarget.u64 = slotFn;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r4.u64 = 0;
	ctx.r8.u64 = passR8;
	ctx.r10.u64 = slotFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(51, sub_8277B2B0, 0x8277B2B0) { ctx.r3.u64 = n_sub_8277B2B0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8277B760(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr, uint64_t arg2) {
	if (!UseLiftedCode(51, 0x8277B760)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r4.u64 = arg2; __imp__sub_8277B760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277B760);
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	PPCVRegister ownerPosition{};
	PPCVRegister entityPosition{};
	PPCVRegister direction{};
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	stack = PushStackFrame(base, stack, 144);

	// virtual slot 68 returns an entity in r3
	callTarget.u64 = LOAD32(uint32_t(targetingPlayer->vtable) + 68);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t entityBefore = ctx.r3.u64;
	// r5, r6 and f1 as the first slot 120 call below receives them
	uint64_t passR5 = ctx.r5.u64;
	uint64_t passR6 = ctx.r6.u64;
	double passF1 = ctx.f1.f64;

	bool entityBeforeActive =
		(uint32_t)entityBefore != 0 && (LOAD8((uint32_t)entityBefore + 144) & 64) != 0;

	if (entityBeforeActive) {
		// Positions of the owner (m_4) and of the entity: slot 64 of the object each holds at +124
		// writes one into stack+80 and stack+96.
		uint32_t ownerObj = LOAD32(uint32_t(targetingPlayer->m_4) + 124);
		uint32_t ownerObjVtable = LOAD32(ownerObj);
		uint32_t ownerPositionFn = LOAD32(ownerObjVtable + 64);
		callTarget.u64 = ownerPositionFn;
		ctx.r3.u64 = (uint64_t)stack + 80;
		ctx.r4.u64 = ownerObj;
		ctx.r9.u64 = ownerPositionFn;
		ctx.r10.u64 = ownerObjVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t entityObj = LOAD32((uint32_t)entityBefore + 124);
		uint32_t entityObjVtable = LOAD32(entityObj);
		uint32_t entityPositionFn = LOAD32(entityObjVtable + 64);
		callTarget.u64 = entityPositionFn;
		ctx.r3.u64 = (uint64_t)stack + 96;
		ctx.r4.u64 = entityObj;
		ctx.r7.u64 = entityPositionFn;
		ctx.r8.u64 = entityObjVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// this+48 = the normalized vector from the owner's position to the entity's; f1 = its length
		uint32_t directionAddr = targetingPlayerAddr + 48;
		SET_V8(ownerPosition, VLOAD(((uint32_t)stack + 80) & ~0xF));
		SET_V8(entityPosition, VLOAD(((uint32_t)stack + 96) & ~0xF));
		ctx.fpscr.enableFlushMode();
		SET_VF(direction, simde_mm_sub_ps(VF(entityPosition), VF(ownerPosition)));
		ctx.fpscr.disableFlushModeUnconditional();
		double normalizeParam = double(LOAD_F32(0x82099AE0u));
		VSTORE(directionAddr & ~0xF, V8(direction));
		passF1 = Vec4_NormalizeInPlace_ReturnLength(ctx, base, directionAddr, normalizeParam);

		passR5 = (uint64_t)stack + 96;
		passR6 = (uint64_t)stack + 80;
	}

	// Virtual slot 120 with r4 = 0xFFFFFFFF when the low byte of arg2 is set and 1 otherwise;
	// r8, r9 and xer.ca hold what the original branch-free select left in them.
	uint32_t arg2Low = arg2 & 0xFF;
	uint32_t selfVtable = targetingPlayer->vtable;
	uint32_t slot120Fn = LOAD32(selfVtable + 120);
	callTarget.u64 = slot120Fn;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r4.u64 = (arg2Low != 0) ? 0xFFFFFFFFu : 1u;
	ctx.r5.u64 = passR5;
	ctx.r6.u64 = passR6;
	ctx.r7.u64 = slot120Fn;
	ctx.r8.u64 = (arg2Low != 0) ? ~0ULL : 0ULL;
	ctx.r9.u64 = (uint64_t)0 - (uint64_t)arg2Low;
	ctx.r10.u64 = selfVtable;
	ctx.f1.f64 = passF1;
	ctx.xer.ca = (arg2Low == 0);
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// virtual slot 140
	selfVtable = targetingPlayer->vtable;
	uint32_t slot140Fn = LOAD32(selfVtable + 140);
	callTarget.u64 = slot140Fn;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r5.u64 = slot140Fn;
	ctx.r6.u64 = selfVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// virtual slot 120 again, with r4 = 0
	slot120Fn = LOAD32(uint32_t(targetingPlayer->vtable) + 120);
	callTarget.u64 = slot120Fn;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r4.u64 = 0;
	ctx.r10.u64 = slot120Fn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// virtual slot 68 again
	selfVtable = targetingPlayer->vtable;
	uint32_t slot68Fn = LOAD32(selfVtable + 68);
	callTarget.u64 = slot68Fn;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r8.u64 = slot68Fn;
	ctx.r9.u64 = selfVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t entityAfter = ctx.r3.u64;

	bool entityAfterActive =
		(uint32_t)entityAfter != 0 && (LOAD8((uint32_t)entityAfter + 144) & 64) != 0;

	// Virtual slot 76 with the earlier entity when the entity now returned is not active but the
	// earlier one still is.
	if (!entityAfterActive) {
		if ((uint32_t)entityBefore != 0 && (LOAD8((uint32_t)entityBefore + 144) & 64) != 0) {
			uint32_t slot76Fn = LOAD32(uint32_t(targetingPlayer->vtable) + 76);
			callTarget.u64 = slot76Fn;
			ctx.r3.u64 = targetingPlayerAddr;
			ctx.r4.u64 = entityBefore;
			ctx.r10.u64 = slot76Fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(51, sub_8277B760, 0x8277B760) { ctx.r3.u64 = n_sub_8277B760(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8277B8F0(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr, uint64_t arg2) {
	if (!UseLiftedCode(51, 0x8277B8F0)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r6.u64 = arg2; __imp__sub_8277B8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277B8F0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	stack = PushStackFrame(base, stack, 128);

	// virtual slot 68 returns an entity in r3
	uint32_t getEntityFn = LOAD32(uint32_t(targetingPlayer->vtable) + 68);
	callTarget.u64 = getEntityFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = targetingPlayerAddr;
	ctx.r6.u64 = arg2;
	ctx.r10.u64 = getEntityFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t entity = ctx.r3.u64;
	// r6, r7, r8 and xer.ca as n_sub_82397DA8 receives them; the table search below changes them
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR7 = ctx.r7.u64;
	uint64_t passR8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;

	uint32_t entityAddr = (uint32_t)entity;
	if (entityAddr != 0 && (LOAD8(entityAddr + 144) & 64) != 0 && ((LOAD32(entityAddr + 36) >> 23) & 1) != 0) {
		// The entity's component under key 23: from the cached index table when there is one,
		// otherwise by a lower_bound search of the sorted 8-byte (key, component) entries.
		uint32_t keyedComponent;
		uint32_t indexCache = LOAD32(entityAddr + 140);
		uint32_t entry = LOAD32(entityAddr + 72);
		if (indexCache != 0) {
			uint32_t index = LOAD8(indexCache + 23);
			keyedComponent = LOAD32(entry + index * 8 + 4);
		} else {
			uint32_t end = LOAD32(entityAddr + 76);
			passR6 = end;
			STORE32(stack + 84, entry);
			STORE32(stack + 80, 0u);
			int32_t byteCount = (int32_t)(end - entry);
			int32_t count = byteCount >> 3;
			flags.ca = byteCount < 0 && (byteCount & 0x7) != 0;
			if (count > 0) {
				flags.ca = 0;  // halving a positive count leaves carry clear
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					uint32_t mid = entry + step;
					bool below = (int32_t)LOAD32(mid) < 23;
					passR7 = below;
					passR8 = step;
					if (below) {
						entry = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, entry);
			}
			uint32_t found = end;
			if (entry != end && (int32_t)LOAD32(entry) <= 23) {
				STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the 8-byte result unchanged
				found = entry;
			}
			keyedComponent = LOAD32(found + 4);
		}

		// state the callee may pass on
		ctx.xer.ca = flags.ca;
		n_sub_82397DA8(ctx, base, keyedComponent, 0, targetingPlayer->m_4, passR6);
		uint64_t handleAddr = targetingPlayerAddr + 188;
		if ((n_sub_82488F30(ctx, base, handleAddr, entity) & 0xFF) != 0) {
			EntityHandle_Release(ctx, base, handleAddr);
		}
	}

	// r6, r7, r8 and xer.ca reach this call as the last call left them
	uint64_t result = n_sub_82778C48(ctx, base, targetingPlayer->m_C);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_8277B8F0, 0x8277B8F0) { ctx.r3.u64 = n_sub_8277B8F0(ctx, base, ctx.r3.u64, ctx.r6.u64); }

uint64_t n_sub_8277BD20(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr, uint64_t luaState) {
	constexpr int32_t str_TXT_82000EAC_B_ = int32_t(0x82000EAC);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t str_TXT_820D3558_B_ = int32_t(0x820D3558);
	constexpr int32_t str_TXT_820D3578_B_ = int32_t(0x820D3578);
	constexpr int32_t str_TXT_820D357C_B_ = int32_t(0x820D357C);
	constexpr int32_t str_TXT_820D3598_B_ = int32_t(0x820D3598);
	constexpr int32_t str_TXT_820D35B0_B_ = int32_t(0x820D35B0);
	if (!UseLiftedCode(51, 0x8277BD20)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r4.u64 = luaState; __imp__sub_8277BD20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277BD20);
	uint32_t stack = ctx.r1.u64;
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);

	stack = PushStackFrame(base, stack, 128);

	// target / source entity handles live at +0x40 and +0x48
	uint64_t targetHandleAddr = targetingPlayerAddr + 64;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = luaState;  // state the callee may pass on
	n_sub_8277BCA8(ctx, base, targetHandleAddr);

	uint64_t targetEntity = Lua_GetRegistryFieldEntity(ctx, base, luaState, uint64_t(str_TXT_82000EAC_B_), 0);
	EntityHandle_SetTarget(ctx, base, targetHandleAddr, targetEntity);

	uint64_t sourceHandleAddr = targetingPlayerAddr + 72;
	uint64_t sourceEntity = Lua_GetRegistryFieldEntity(ctx, base, luaState, uint64_t(str_TXT_820D3558_B_), targetingPlayer->m_4);
	EntityHandle_SetTarget(ctx, base, sourceHandleAddr, sourceEntity);

	// base address of the float constants used as defaults for the number fields
	uint32_t floatDefaults = uint32_t(g_820A0000) - 27852;

	// Some field names are addressed from a nearby string's base address; that base is left in
	// r9, r8 or r7 as state the callee may pass on.
	uint64_t percentTowardsTargetName = (int64_t)str_TXT_820D0000_B_ + 13664;
	ctx.fpscr.disableFlushMode();
	double defaultValue = double(LOAD_F32(floatDefaults + 9748));
	ctx.r9.s64 = str_TXT_820D0000_B_;
	LuaRef_GetNumberField(ctx, base, luaState, percentTowardsTargetName, defaultValue);
	ctx.fpscr.disableFlushMode();
	targetingPlayer->m_50 = float(ctx.f1.f64);

	uint64_t minDistanceName = (int64_t)str_TXT_820D0000_B_ - 9616;
	defaultValue = double(LOAD_F32(floatDefaults + 384));
	ctx.r8.s64 = str_TXT_820D0000_B_;
	LuaRef_GetNumberField(ctx, base, luaState, minDistanceName, defaultValue);
	ctx.fpscr.disableFlushMode();
	targetingPlayer->m_54 = float(ctx.f1.f64);

	uint64_t maxDistanceName = (int64_t)str_TXT_820C0000_B_ + 30936;
	defaultValue = double(LOAD_F32(floatDefaults + 19152));
	ctx.r7.s64 = str_TXT_820C0000_B_;
	LuaRef_GetNumberField(ctx, base, luaState, maxDistanceName, defaultValue);
	ctx.fpscr.disableFlushMode();
	targetingPlayer->m_58 = float(ctx.f1.f64);

	defaultValue = double(LOAD_F32(floatDefaults + 21784));
	LuaRef_GetNumberField(ctx, base, luaState, uint64_t(str_TXT_820D3578_B_), defaultValue);
	ctx.fpscr.disableFlushMode();
	targetingPlayer->m_5C = float(ctx.f1.f64);

	defaultValue = double(LOAD_F32(floatDefaults + 25676));
	LuaRef_GetNumberField(ctx, base, luaState, uint64_t(str_TXT_820D357C_B_), defaultValue);
	ctx.fpscr.disableFlushMode();
	targetingPlayer->m_60 = float(ctx.f1.f64);

	uint64_t focalOffsetName = (int64_t)str_TXT_820D0000_B_ + 13708;
	defaultValue = double(LOAD_F32(floatDefaults));
	LuaRef_GetNumberField(ctx, base, luaState, focalOffsetName, defaultValue);
	ctx.fpscr.disableFlushMode();
	targetingPlayer->m_64 = float(ctx.f1.f64);

	uint32_t TXT_820D3598_L_ = LuaRef_GetBoolField(ctx, base, luaState, uint64_t(str_TXT_820D3598_B_), 0);
	targetingPlayer->m_68 = (uint8_t)TXT_820D3598_L_;

	uint64_t importanceValue = LuaTableRef_GetNumberField(ctx, base, luaState, uint64_t(str_TXT_820D35B0_B_), 0);
	targetingPlayer->m_Target = (uint32_t)importanceValue;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return importanceValue;
}
PROMOTED_ENTRY(51, sub_8277BD20, 0x8277BD20) { ctx.r3.u64 = n_sub_8277BD20(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_8277BE50  [8 bytes]
void n_sub_8277BE50(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr, uint32_t targetId) {
	if (!UseLiftedCode(51, 0x8277BE50)) { ctx.r3.u64 = targetingPlayerAddr; ctx.r4.u64 = targetId; __imp__sub_8277BE50(ctx, base); return; }
	LiftedFrame frame(0x8277BE50);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	targetingPlayer->m_74 = targetId;
}
PROMOTED_ENTRY(51, sub_8277BE50, 0x8277BE50) { n_sub_8277BE50(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_8277BE58  [8 bytes]
uint64_t n_sub_8277BE58(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x8277BE58)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277BE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277BE58);
	uint32_t self = (uint32_t)targetingPlayerAddr;
	return LOAD32(self + 116);
}
PROMOTED_ENTRY(51, sub_8277BE58, 0x8277BE58) { ctx.r3.u64 = n_sub_8277BE58(ctx, base, ctx.r3.u64); }

void n_sub_8277BE60(CpuState& ctx, uint8_t* base, uint32_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x8277BE60)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277BE60(ctx, base); return; }
	LiftedFrame frame(0x8277BE60);
	CECTargetingPlayer* targetingPlayer = GameObject<CECTargetingPlayer>(base, targetingPlayerAddr);
	targetingPlayer->m_74 = 0xFFFFFFFFu;
	return;
}
PROMOTED_ENTRY(51, sub_8277BE60, 0x8277BE60) { n_sub_8277BE60(ctx, base, ctx.r3.u32); }

uint64_t n_sub_8277BE70(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x8277BE70)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277BE70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277BE70);
	uint64_t subObject = targetingPlayerAddr + 64;
	return n_sub_8277BCA8(ctx, base, subObject);
}
PROMOTED_ENTRY(51, sub_8277BE70, 0x8277BE70) { ctx.r3.u64 = n_sub_8277BE70(ctx, base, ctx.r3.u64); }

// Returns the entity the handle at +72 refers to, or 0; an empty handle is released.
uint64_t n_sub_8277BE78(CpuState& ctx, uint8_t* base, uint64_t targetingPlayer) {
	if (!UseLiftedCode(51, 0x8277BE78)) { ctx.r3.u64 = targetingPlayer; __imp__sub_8277BE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277BE78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	uint64_t entityHandle = targetingPlayer + 72;
	uint32_t entitySlot = LOAD32(uint32_t(entityHandle) + 4);
	if (entitySlot != 0) {
		uint32_t entity = LOAD32(entitySlot);
		if (entity != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return entity;
		}
		// state the callee may pass on
		ctx.r1.u64 = stack;
		EntityHandle_Release(ctx, base, entityHandle);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(51, sub_8277BE78, 0x8277BE78) { ctx.r3.u64 = n_sub_8277BE78(ctx, base, ctx.r3.u64); }

// sub_8277BED0  [8 bytes]
uint64_t n_sub_8277BED0(CpuState& ctx, uint8_t* base, uint64_t targetingPlayerAddr) {
	if (!UseLiftedCode(51, 0x8277BED0)) { ctx.r3.u64 = targetingPlayerAddr; __imp__sub_8277BED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277BED0);
	uint32_t self = (uint32_t)targetingPlayerAddr;
	return LOAD8(self + 104);
}
PROMOTED_ENTRY(51, sub_8277BED0, 0x8277BED0) { ctx.r3.u64 = n_sub_8277BED0(ctx, base, ctx.r3.u64); }

// Creates a Lua table held by the shared pointer at luaTableRef and copies the object's fields into it:
// the entities behind the handles at +64 and +72, the floats at +80..+100 and the byte at +104.
uint64_t n_sub_8277BED8(CpuState& ctx, uint8_t* base, uint64_t luaTableRef, uint64_t targetingPlayer, uint64_t arg3, uint64_t arg4) {
	constexpr int32_t str_TXT_82000EAC_B_ = int32_t(0x82000EAC);
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820C78D8_B_ = int32_t(0x820C78D8);
	constexpr int32_t str_TXT_820CDA70_B_ = int32_t(0x820CDA70);
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t str_TXT_820D3558_B_ = int32_t(0x820D3558);
	constexpr int32_t str_TXT_820D3560_B_ = int32_t(0x820D3560);
	constexpr int32_t str_TXT_820D358C_B_ = int32_t(0x820D358C);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(51, 0x8277BED8)) { ctx.r3.u64 = luaTableRef; ctx.r4.u64 = targetingPlayer; ctx.r6.u64 = arg3; ctx.r7.u64 = arg4; __imp__sub_8277BED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277BED8);

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t gameRoot = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t rootSystems = LOAD32(gameRoot + 12);
	uint32_t luaContext = LOAD32(rootSystems + 120);
	uint32_t luaStateRef = LOAD32(luaContext + 4);
	uint32_t L = LOAD32(luaStateRef);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	lua_createtable(ctx, base, L, 0, 0, arg3, arg4, luaStateRef);

	uint64_t refName = uint64_t(int64_t(str_TXT_820C0000_B_) + 19528);
	SharedPtr_CreateInventoryItem(ctx, base, luaTableRef, L, refName, ctx.r6.u64, str_TXT_820C0000_B_);

	// The target entity is stored only when its handle resolves and bit 0x40 of the entity's byte at +144 is set.
	uint64_t targetHandle = targetingPlayer + 64;
	uint32_t targetFlag = 0;
	uint32_t targetSlot = LOAD32(uint32_t(targetingPlayer) + 68);
	if (targetSlot != 0) {
		uint32_t targetObject = LOAD32(targetSlot);
		if (targetObject == 0) {
			EntityHandle_Release(ctx, base, targetHandle);
		} else {
			uint32_t targetEntity = EntityHandle_Get_825575C8(ctx, base, targetHandle);
			targetFlag = LOAD8(targetEntity + 144) & 64;
		}
	}
	if (targetFlag != 0) {
		uint64_t targetEntity = EntityHandle_Get_825575C8(ctx, base, targetHandle);
		n_sub_8253CD60(ctx, base, luaTableRef, str_TXT_82000EAC_B_, targetEntity, ctx.r6.u64, ctx.r7.u64);
	}

	// The source entity, under the same condition.
	uint64_t sourceHandle = targetingPlayer + 72;
	uint32_t sourceFlag = 0;
	uint32_t sourceSlot = LOAD32(uint32_t(targetingPlayer) + 76);
	if (sourceSlot != 0) {
		uint32_t sourceObject = LOAD32(sourceSlot);
		if (sourceObject == 0) {
			EntityHandle_Release(ctx, base, sourceHandle);
		} else {
			uint32_t sourceEntity = EntityHandle_Get_825575C8(ctx, base, sourceHandle);
			sourceFlag = LOAD8(sourceEntity + 144) & 64;
		}
	}
	if (sourceFlag != 0) {
		uint64_t sourceEntity = EntityHandle_Get_825575C8(ctx, base, sourceHandle);
		n_sub_8253CD60(ctx, base, luaTableRef, str_TXT_820D3558_B_, sourceEntity, ctx.r6.u64, ctx.r7.u64);
	}

	ctx.fpscr.disableFlushMode();
	n_sub_8277C120(ctx, base, luaTableRef, uint64_t(str_TXT_820D3560_B_), double(LOAD_F32(uint32_t(targetingPlayer) + 80)));
	ctx.fpscr.disableFlushMode();
	n_sub_8277C120(ctx, base, luaTableRef, uint64_t(str_TXT_820CDA70_B_), double(LOAD_F32(uint32_t(targetingPlayer) + 84)));
	ctx.fpscr.disableFlushMode();
	n_sub_8277C120(ctx, base, luaTableRef, uint64_t(str_TXT_820C78D8_B_), double(LOAD_F32(uint32_t(targetingPlayer) + 88)));

	// r8 and r7 still hold the high half of the field-name addresses (state the callee may pass on).
	ctx.fpscr.disableFlushMode();
	ctx.r8.s64 = str_TXT_820D0000_B_;
	n_sub_8277C120(ctx, base, luaTableRef, uint64_t(int64_t(str_TXT_820D0000_B_) + 13688), double(LOAD_F32(uint32_t(targetingPlayer) + 92)));
	ctx.fpscr.disableFlushMode();
	ctx.r7.s64 = str_TXT_820D0000_B_;
	n_sub_8277C120(ctx, base, luaTableRef, uint64_t(int64_t(str_TXT_820D0000_B_) + 13692), double(LOAD_F32(uint32_t(targetingPlayer) + 96)));

	ctx.fpscr.disableFlushMode();
	n_sub_8277C120(ctx, base, luaTableRef, uint64_t(str_TXT_820D358C_B_), double(LOAD_F32(uint32_t(targetingPlayer) + 100)));

	n_sub_825E5A00(ctx, base, luaTableRef, uint64_t(int64_t(str_TXT_820D0000_B_) + 13720), LOAD8(uint32_t(targetingPlayer) + 104));

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return luaTableRef;
}
PROMOTED_ENTRY(51, sub_8277BED8, 0x8277BED8) { ctx.r3.u64 = n_sub_8277BED8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64, ctx.r7.u64); }

// Sets table[luaFieldName] = fieldValue on the Lua table referenced by the shared pointer at luaTableRef.
uint32_t n_sub_8277C120(CpuState& ctx, uint8_t* base, uint32_t luaTableRef, uint64_t luaFieldName, double fieldValue) {
	if (!UseLiftedCode(51, 0x8277C120)) { ctx.r3.u64 = luaTableRef; ctx.r4.u64 = luaFieldName; ctx.f1.f64 = fieldValue; __imp__sub_8277C120(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8277C120);
	uint32_t stack = ctx.r1.u64;
	// Values callers read in r3, r4, r8 and f1 after the call; unchanged when there is no table.
	uint32_t result = luaTableRef;
	uint64_t r4Out = luaFieldName;
	uint64_t r8Out = ctx.r8.u64;
	double f1Out = fieldValue;
	stack = PushStackFrame(base, stack, 112);

	uint32_t luaRef = LOAD32(luaTableRef);
	if (luaRef != 0) {
		// Push registry[ref].
		uint32_t L = LOAD32(luaRef);
		uint32_t refKey = LOAD32(luaRef + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, L, -10000, refKey);

		// Push the number directly into the top stack slot (fieldValue, type tag 3).
		uint32_t valueSlot = LOAD32(L + 8);
		ctx.fpscr.disableFlushMode();
		STORE_F32(valueSlot, float(fieldValue));
		STORE32(valueSlot + 4, 3u);
		uint64_t pushedTop = uint64_t(LOAD32(L + 8)) + 8;
		STORE32(L + 8, uint32_t(pushedTop));
		// state the callee may pass on
		ctx.r9.u64 = pushedTop;
		ctx.f1.f64 = fieldValue;
		result = lua_setfield(ctx, base, L, -2, luaFieldName);
		r4Out = ctx.r4.u64;
		f1Out = ctx.f1.f64;

		// Pop the table.
		uint64_t poppedTop = uint64_t(LOAD32(L + 8)) - 8;
		STORE32(L + 8, uint32_t(poppedTop));
		r8Out = poppedTop;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	ctx.r8.u64 = r8Out;
	ctx.f1.f64 = f1Out;
	return result;
}
PROMOTED_ENTRY(51, sub_8277C120, 0x8277C120) { ctx.r3.u64 = n_sub_8277C120(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.f1.f64); }
