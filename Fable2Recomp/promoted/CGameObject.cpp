// CGameObject (vtable 0x82003E58): methods of the class as readable C++.
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

// CGameObject vtable slot 4. Its own slots +0x30 and +0x2C hold sub_82188720 and C_82003E58_Update
// in CGameObject's own vtable.
uint64_t C_82003E58_Reset(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr) {
	if (!UseLiftedCode(0, 0x821854A8)) { ctx.r3.u64 = gameObjectAddr; __imp__sub_821854A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821854A8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t primary = gameObject->m_4;
	uint32_t primaryFn68 = LOAD32(LOAD32(primary) + 0x68);
	callTarget.u64 = (uint64_t)primaryFn68;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = primary;
	ctx.r10.u64 = primaryFn68;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;
	uint64_t r4Out = ctx.r4.u64;

	uint32_t primaryByte = (uint32_t)result & 0xFF;
	if (primaryByte == 0) {
		uint32_t ownFn30 = LOAD32(uint32_t(gameObject->vtable) + 0x30);
		callTarget.u64 = (uint64_t)ownFn30;
		ctx.r3.u64 = gameObjectAddr;
		ctx.r9.u64 = primaryByte;
		ctx.r10.u64 = ownFn30;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		flags.ca = ctx.xer.ca;

		gameObject->m_6BC = 0;

		// Eight 204-byte groups from +92. Each zeroes its first word and clears four arrays,
		// at +44, +92, +140 and +188, each an array pointer, an element count and a word
		// that is reset to 0; the 32-bit elements are zeroed with memset.
		uint32_t group = (uint32_t)gameObjectAddr + 92;
		uint32_t remainingGroups = 8;
		uint32_t count3 = 0;
		uint32_t count4 = 0;
		do {
			STORE32(group, 0);
			uint32_t array1 = LOAD32(group + 44);
			uint32_t count1 = LOAD32(group + 48);
			STORE32(group + 52, 0);
			// carry the callee may read
			ctx.xer.ca = flags.ca;
			memset(ctx, base, array1, 0, count1 << 2);

			uint32_t array2 = LOAD32(group + 92);
			uint32_t count2 = LOAD32(group + 96);
			STORE32(group + 100, 0);
			memset(ctx, base, array2, 0, count2 << 2);

			count3 = LOAD32(group + 144);
			uint32_t array3 = LOAD32(group + 140);
			STORE32(group + 148, 0);
			memset(ctx, base, array3, 0, count3 << 2);

			count4 = LOAD32(group + 192);
			uint32_t array4 = LOAD32(group + 188);
			STORE32(group + 196, 0);
			memset(ctx, base, array4, 0, count4 << 2);
			// the last group's fourth array pointer is returned when the slot +0x2C call is skipped
			result = array4;

			flags.ca = remainingGroups > 0;
			remainingGroups = remainingGroups - 1;
			group = group + 204;
		} while (remainingGroups != 0);

		uint32_t tertiary = gameObject->m_C;
		r4Out = tertiary;
		if (LOAD8(tertiary + 8) != 0) {
			uint32_t ownFn2C = LOAD32(uint32_t(gameObject->vtable) + 0x2C);
			callTarget.u64 = (uint64_t)ownFn2C;
			ctx.r3.u64 = gameObjectAddr;
			ctx.r4.u64 = tertiary;
			// state the callee may pass on
			ctx.r8.u64 = count4;
			ctx.r9.u64 = count3;
			ctx.r10.u64 = ownFn2C;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Out = ctx.r4.u64;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Out;
	return result;
}
PROMOTED_ENTRY(0, sub_821854A8, 0x821854A8) { ctx.r3.u64 = C_82003E58_Reset(ctx, base, ctx.r3.u64); }

// CGameObject vtable slot 12. Hands a descriptor from the m_4 object to the m_8 object, passes each
// element of the array at +0x6E0 to n_sub_82284810 and empties the array, then hands every item of
// the m_4 object's list to its own slot +0x34 and to the m_8 object.
uint64_t n_sub_82188720(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr) {
	if (!UseLiftedCode(0, 0x82188720)) { ctx.r3.u64 = gameObjectAddr; __imp__sub_82188720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82188720);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);
	stack = PushStackFrame(base, stack, 160);

	// Slot +0x50 of the m_4 object fills a buffer on this frame and returns a pointer to the descriptor.
	// The m_8 object's vtable is read before that call; m_8 itself is read again after it.
	uint32_t primary = gameObject->m_4;
	uint32_t primaryVtable = LOAD32(primary);
	uint32_t secondaryVtable = LOAD32(gameObject->m_8);

	uint32_t primaryFn50 = LOAD32(primaryVtable + 0x50);
	callTarget.u64 = primaryFn50;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = (uint64_t)stack + 80;
	ctx.r4.u64 = primary;
	ctx.r9.u64 = primaryFn50;
	ctx.r10.u64 = primaryVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t descriptor = ctx.r3.u64;

	// Slot +0x48 of the m_8 object receives the descriptor's first eight bytes and its word at +8.
	uint32_t secondary = gameObject->m_8;
	uint32_t secondaryFn48 = LOAD32(secondaryVtable + 0x48);
	uint32_t descriptorWord8 = LOAD32((uint32_t)descriptor + 8);
	uint64_t descriptorFirst8 = LOAD64((uint32_t)descriptor);
	callTarget.u64 = secondaryFn48;
	ctx.r3.u64 = secondary;
	ctx.r4.u64 = descriptorFirst8;
	ctx.r5.u64 = (uint64_t)descriptorWord8 << 32;
	ctx.r6.u64 = descriptorWord8;
	ctx.r7.u64 = secondaryFn48;
	ctx.r8.u64 = descriptor;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// Slot +0x74 of the m_4 object returns a list: element pointers at +32, element count at +40.
	uint32_t primaryAgain = gameObject->m_4;
	uint32_t primaryVtableAgain = LOAD32(primaryAgain);
	uint32_t primaryFn74 = LOAD32(primaryVtableAgain + 0x74);
	callTarget.u64 = primaryFn74;
	ctx.r3.u64 = primaryAgain;
	ctx.r4.u64 = primaryFn74;
	ctx.r5.u64 = primaryVtableAgain;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t list = ctx.r3.u64;
	uint64_t result = list;

	// The array at +0x6E0 has its capacity at +0x6E4 and its element count at +0x6E8.
	uint32_t arrayHeader = (uint32_t)gameObjectAddr + 0x6C0;
	uint32_t elementCount = gameObject->m_6E8;
	if ((int32_t)elementCount > 0) {
		uint32_t cursor = gameObject->m_6E0;
		uint32_t end = cursor + (elementCount << 2);
		if (cursor != end) {
			// the end is recomputed from the array after every call
			do {
				result = n_sub_82284810(ctx, base, list, cursor);
				cursor += 4;
			} while (cursor != LOAD32(arrayHeader + 0x20) + (LOAD32(arrayHeader + 0x28) << 2));
		}
		STORE32(arrayHeader + 0x28, 0);
		uint32_t storage = LOAD32(arrayHeader + 0x20);
		uint32_t capacity = LOAD32(arrayHeader + 0x24);
		// state the callee may pass on
		ctx.r3.u64 = result;
		uint64_t allocator = Allocator_GetInstance(ctx, base);
		result = n_sub_82BA9068(ctx, base, allocator, storage, capacity << 2);
		STORE32(arrayHeader + 0x24, 0);
		STORE32(arrayHeader + 0x20, 0);
	}

	if ((int32_t)LOAD32((uint32_t)list + 40) > 0) {
		int32_t index = 0;
		uint32_t offset = 0;
		do {
			uint32_t item = LOAD32(LOAD32(offset + LOAD32((uint32_t)list + 32)) + 4);
			if (item != 0) {
				// Byte +8 keeps bit 12 of the halfword at +28 of the item's property list (at +4);
				// when that bit turns on for an item whose byte +9 is set, flags 0x80 and 0x20 go into +251.
				if (LOAD8(item + 9) != 0 && LOAD8(item + 8) == 0 &&
				    ((LOAD16(LOAD32(item + 4) + 28) >> 12) & 1) != 0) {
					STORE8(item + 251, (uint8_t)(LOAD8(item + 251) | 0xA0));
				}
				uint32_t listFlags = LOAD16(LOAD32(item + 4) + 28);
				uint32_t flagBit12 = (listFlags >> 12) & 1;
				STORE8(item + 8, (uint8_t)flagBit12);

				// Own slot +0x34 (C_82003E58_ApplyPropertyList in CGameObject's own vtable) with the item.
				uint32_t objectVtable = gameObject->vtable;
				uint32_t applyPropertyList = LOAD32(objectVtable + 0x34);
				callTarget.u64 = applyPropertyList;
				ctx.r3.u64 = gameObjectAddr;
				ctx.r4.u64 = item;
				ctx.r7.u64 = applyPropertyList;
				ctx.r8.u64 = objectVtable;
				ctx.r9.u64 = flagBit12;
				ctx.r10.u64 = listFlags;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				// Slot +0x10 of the m_8 object with the item.
				uint32_t secondaryAgain = gameObject->m_8;
				uint32_t secondaryVtableAgain = LOAD32(secondaryAgain);
				uint32_t secondaryFn10 = LOAD32(secondaryVtableAgain + 0x10);
				callTarget.u64 = secondaryFn10;
				ctx.r3.u64 = secondaryAgain;
				ctx.r4.u64 = item;
				ctx.r5.u64 = secondaryFn10;
				ctx.r6.u64 = secondaryVtableAgain;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;
			}
			index = index + 1;
			offset = offset + 4;
		} while (index < (int32_t)LOAD32((uint32_t)list + 40));
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(0, sub_82188720, 0x82188720) { ctx.r3.u64 = n_sub_82188720(ctx, base, ctx.r3.u64); }

// CGameObject vtable slot 13, called by sub_82188720 for each item of its list (this, in r3, is unused).
// Copies the values of the item's property list (at +4) into the item's fields and marks each change
// in the flags at +251. Returns 0 when every entry's id is recognised, 1 when one is not or when
// byte +9 of the item is clear.
uint64_t C_82003E58_ApplyPropertyList(CpuState& ctx, uint8_t* base, uint32_t item) {
	if (!UseLiftedCode(0, 0x821888C0)) { ctx.r4.u64 = item; __imp__sub_821888C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821888C0);

	if (LOAD8(item + 9) == 0)
		return 1;

	uint32_t propertyList = LOAD32(item + 4);
	if (LOAD8(propertyList + 31) == 0)
		return 0;

	ctx.fpscr.disableFlushMode();
	float field0Scale = LOAD_F32(0x8209F48Cu);

	// Recognised property ids, in the order they are tested, and the item field each one sets:
	// fields 0-12 are floats, 13 and 14 single bytes.
	uint32_t propertyIds[15];
	for (uint32_t i = 0; i < 15; i++)
		propertyIds[i] = LOAD32(0x834BE200u + i * 4);

	const uint32_t kFieldOffset[15] = {
		0xE0,
		0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38,
		0xF9, 0xF8,
	};

	uint64_t result = 0;
	// The entry count (byte +31) and the layout bit (halfword +28) are read again for every entry.
	for (uint32_t i = 0; (int32_t)i < (int32_t)LOAD8(propertyList + 31); i++) {
		// 8-byte entries (id in the top 27 bits of the first word, then the value) start at +32,
		// or at +68 when bit 0 of the halfword at +28 is set.
		uint32_t entryBias = (LOAD16(propertyList + 28) & 1) != 0 ? 36u : 0u;
		uint32_t entry = propertyList + 32 + entryBias + i * 8;
		uint32_t propertyId = LOAD32(entry) >> 5;
		ctx.fpscr.disableFlushMode();
		float value = LOAD_F32(entry + 4);

		int32_t field = -1;
		for (int32_t candidate = 0; candidate < 15; candidate++) {
			if (propertyIds[candidate] == propertyId) {
				field = candidate;
				break;
			}
		}
		if (field < 0) {
			result = 1;
			continue;
		}

		if (field == 0) {
			// Field 0 is scaled by a global factor and marked with flag 0x80 instead of 0x20.
			STORE_F32(item + 0xE0, value * field0Scale);
		} else if (field < 13) {
			STORE_F32(item + kFieldOffset[field], value);
		} else {
			// A byte field takes the low byte of the value word; an unchanged byte is not marked.
			uint8_t byteValue = uint8_t(LOAD32(entry + 4) & 0xFF);
			if (byteValue == LOAD8(item + kFieldOffset[field]))
				continue;
			STORE8(item + kFieldOffset[field], byteValue);
		}
		STORE8(item + 0xFB, uint8_t(LOAD8(item + 0xFB) | (field == 0 ? 0x80 : 0x20)));
	}

	return result;
}
PROMOTED_ENTRY(0, sub_821888C0, 0x821888C0) { ctx.r3.u64 = C_82003E58_ApplyPropertyList(ctx, base, ctx.r4.u32); }

// CGameObject vtable slot 14. The second argument uses the layout of the items that
// C_82003E58_ApplyPropertyList fills in (fields +12..+59, bytes +248/+249, flags +251).
uint64_t n_sub_8229DFE8(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr, uint64_t itemAddr) {
	if (!UseLiftedCode(11, 0x8229DFE8)) { ctx.r3.u64 = gameObjectAddr; ctx.r4.u64 = itemAddr; __imp__sub_8229DFE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229DFE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	const uint32_t item = (uint32_t)itemAddr;

	// C_82003E58_ApplyPropertyList sets flag 0x20 at +251 when it changes the floats at +12..+59
	// or the bytes at +248/+249.
	if (LOAD8(item + 251) & 0x20) {
		ctx.r1.u64 = stack;
		n_sub_8229E148(ctx, base, itemAddr + 60, item + 12, item + 24, item + 36, item + 48,
		               LOAD8(item + 249), LOAD8(item + 248));
	}

	ctx.r1.u64 = stack;
	n_sub_8229DEE0(ctx, base, gameObjectAddr + 44, itemAddr);

	ctx.fpscr.disableFlushMode();
	const double valueE4 = double(LOAD_F32(item + 0xE4));
	const uint32_t belowLimitOrFlagged =
	    (valueE4 < double(LOAD_F32(0x8209B710u)) || (LOAD8(item + 251) & 2) != 0) ? 1u : 0u;

	// state the callee may pass on
	ctx.f13.f64 = valueE4;
	const uint64_t result = n_sub_822D8AA0(ctx, base, gameObjectAddr + 92, itemAddr, belowLimitOrFlagged);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(11, sub_8229DFE8, 0x8229DFE8) { ctx.r3.u64 = n_sub_8229DFE8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_8229E130  [20 bytes]
void C_82003E58_Release(CpuState& ctx, uint8_t* base, uint32_t gameObjectAddr) {
	if (!UseLiftedCode(11, 0x8229E130)) { ctx.r3.u64 = gameObjectAddr; __imp__sub_8229E130(ctx, base); return; }
	LiftedFrame frame(0x8229E130);
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);
	gameObject->m_refCount = gameObject->m_refCount - 1;
	return;
}
PROMOTED_ENTRY(11, sub_8229E130, 0x8229E130) { C_82003E58_Release(ctx, base, ctx.r3.u32); }

// CGameObject vtable slot 5.
uint64_t C_82003E58_Initialize(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr, uint64_t arg2) {
	if (!UseLiftedCode(13, 0x822CD890)) { ctx.r3.u64 = gameObjectAddr; ctx.r4.u64 = arg2; __imp__sub_822CD890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822CD890);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t primary = gameObject->m_4;
	uint32_t primaryFn60 = LOAD32(LOAD32(primary) + 0x60);
	callTarget.u64 = primaryFn60;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = primary;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = primaryFn60;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t primaryResult = ctx.r3.u64;

	if ((primaryResult & 0xFF) == 0) {
		// the eight array groups C_82003E58_Reset clears
		uint64_t groupsAddr = gameObjectAddr + 92;
		STORE32((uint32_t)arg2 + 204, uint32_t(gameObject->m_4));

		uint32_t secondary = gameObject->m_8;
		uint32_t secondaryVtable = LOAD32(secondary);
		uint32_t secondaryFn50 = LOAD32(secondaryVtable + 0x50);
		callTarget.u64 = secondaryFn50;
		ctx.r3.u64 = secondary;
		ctx.r4.u64 = groupsAddr;
		ctx.r9.u64 = secondaryFn50;
		ctx.r10.u64 = secondaryVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t byte161 = LOAD8((uint32_t)arg2 + 161);
		if (byte161 != 0) {
			uint32_t secondaryAgain = gameObject->m_8;
			uint32_t secondaryFn58 = LOAD32(LOAD32(secondaryAgain) + 0x58);
			callTarget.u64 = secondaryFn58;
			ctx.r3.u64 = secondaryAgain;
			ctx.r4.u64 = groupsAddr;
			ctx.r5.u64 = arg2;
			ctx.r8.u64 = byte161;
			ctx.r10.u64 = secondaryFn58;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// what the last call left in r3
	return ctx.r3.u64;
}
PROMOTED_ENTRY(13, sub_822CD890, 0x822CD890) { ctx.r3.u64 = C_82003E58_Initialize(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// CGameObject vtable slot 0: runs n_sub_82BC3398 and frees the object when bit 0 of the flags is set.
uint64_t n_sub_82BC3348(CpuState& ctx, uint8_t* base, uint64_t objectAddress, uint64_t destructorFlags) {
	if (!UseLiftedCode(87, 0x82BC3348)) { ctx.r3.u64 = objectAddress; ctx.r4.u64 = destructorFlags; __imp__sub_82BC3348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BC3348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = destructorFlags;
	n_sub_82BC3398(ctx, base, objectAddress);
	if ((uint32_t(destructorFlags) & 1) != 0) {
		HandleTarget_Free(ctx, base, objectAddress);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectAddress;
}
PROMOTED_ENTRY(87, sub_82BC3348, 0x82BC3348) { ctx.r3.u64 = n_sub_82BC3348(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// CGameObject destructor body; vtable slot 0 (n_sub_82BC3348) calls it and then frees the object when
// asked. It puts CGameObject's own vtable back first and leaves vtable 0x820FEA2C installed at the end.
uint32_t n_sub_82BC3398(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr) {
	constexpr int32_t g_82003E58 = int32_t(0x82003E58);
	if (!UseLiftedCode(87, 0x82BC3398)) { ctx.r3.u64 = gameObjectAddr; __imp__sub_82BC3398(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BC3398);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);

	stack = PushStackFrame(base, stack, 128);

	// r10 receives the vtable address sign-extended, as the original leaves it.
	uint64_t ownVtable = g_82003E58;
	uint32_t secondary = gameObject->m_8;
	gameObject->vtable = (uint32_t)ownVtable;

	// Slot +0xC of the m_8 object, with this object as the second argument.
	uint32_t secondaryVtable = LOAD32(secondary);
	uint32_t secondaryFnC = LOAD32(secondaryVtable + 0xC);
	callTarget.u64 = secondaryFnC;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = secondary;
	ctx.r4.u64 = gameObjectAddr;
	ctx.r8.u64 = secondaryFnC;
	ctx.r9.u64 = secondaryVtable;
	ctx.r10.u64 = ownVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	n_sub_823F9A78(ctx, base, gameObjectAddr + 0x6C0, 1);
	// the eight array groups C_82003E58_Reset clears
	uint64_t groupsResult = n_sub_82BC4610(ctx, base, gameObjectAddr + 92);

	gameObject->m_refCount = 0;

	// The buffer at m_4C holds m_50 elements of 72 bytes; it goes to n_sub_82BA9068 with the
	// allocator and both fields are cleared.
	uint32_t elementCount = gameObject->m_50;
	uint32_t buffer = gameObject->m_4C;
	// state the callee may pass on
	ctx.r3.u64 = groupsResult;
	uint64_t allocator = Allocator_GetInstance(ctx, base);
	n_sub_82BA9068(ctx, base, allocator, buffer, elementCount * 72);
	gameObject->m_50 = 0;
	gameObject->m_4C = 0;

	uint32_t result = n_sub_82BC3FB0(ctx, base, gameObjectAddr + 16);

	gameObject->vtable = 0x820FEA2Cu;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(87, sub_82BC3398, 0x82BC3398) { ctx.r3.u64 = n_sub_82BC3398(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82BC3430(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr, uint64_t arg2) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	if (!UseLiftedCode(87, 0x82BC3430)) { ctx.r3.u64 = gameObjectAddr; ctx.r7.u64 = arg2; __imp__sub_82BC3430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BC3430);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	constexpr uint64_t str_TXT_820FEA28_R_ = (uint64_t)(int64_t)-2112886232;
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);

	stack = PushStackFrame(base, stack, 224);

	const uint32_t streamAddr = stack + 96;  // CEndianFileStream
	const uint32_t nameAddr = stack + 80;    // string: data pointer + two uint16 counters
	const uint32_t labelAddr = stack + 88;   // string filled in by the object at m_4
	uint32_t success = 0;

	ctx.r1.u64 = stack;
	CEndianFileStream_Construct(ctx, base, streamAddr, arg2);

	uint32_t source = gameObject->m_4;
	uint32_t sourceVtable = LOAD32(source);
	uint32_t readLabelFn = LOAD32(sourceVtable + 0x4C);
	callTarget.u64 = readLabelFn;
	ctx.r3.u64 = labelAddr;
	ctx.r4.u64 = source;
	ctx.r9.u64 = readLabelFn;
	ctx.r10.u64 = sourceVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t bsgEntry = n_sub_82BAA3D0(ctx, base, ctx.r3.u64, str_TXT_820FEA28_R_);
	// char pointer; the fallback is passed on sign-extended, as the original does
	uint64_t bsgText = LOAD32(bsgEntry);
	if ((uint32_t)bsgText == 0) {
		bsgText = g_82000C98;
	}

	STORE16(nameAddr + 6, 0);
	STORE16(nameAddr + 4, 0);
	STORE32(nameAddr, 0);
	if ((uint32_t)bsgText != 0) {
		n_sub_82BA8850(ctx, base, nameAddr, bsgText, -1);
	}
	uint32_t nameData = LOAD32(nameAddr);

	uint64_t loadResult = n_sub_82BC4978(ctx, base, streamAddr, nameAddr, gameObjectAddr + 16, gameObjectAddr + 12);
	bool loaded = (loadResult & 0xFF) != 0;
	uint64_t lastResult = loadResult;

	if (nameData != 0) {
		uint64_t nameSize = (uint64_t)LOAD16(nameAddr + 6) + 1;
		// state the callee may pass on
		ctx.r3.u64 = lastResult;
		uint64_t allocator = Allocator_GetInstance(ctx, base);
		lastResult = n_sub_82BA9068(ctx, base, allocator, nameData, nameSize);
	}

	uint32_t labelData = LOAD32(labelAddr);
	if (labelData != 0) {
		uint64_t labelSize = (uint64_t)LOAD16(labelAddr + 6) + 1;
		// state the callee may pass on
		ctx.r3.u64 = lastResult;
		uint64_t allocator = Allocator_GetInstance(ctx, base);
		n_sub_82BA9068(ctx, base, allocator, labelData, labelSize);
		STORE16(labelAddr + 6, 0);
		STORE16(labelAddr + 4, 0);
		STORE32(labelAddr, 0);
	}

	if (loaded) {
		uint32_t target = gameObject->m_8;
		uint32_t applyFn = LOAD32(LOAD32(target) + 4);
		callTarget.u64 = applyFn;
		ctx.r3.u64 = target;
		ctx.r4.u64 = gameObjectAddr;
		ctx.r10.u64 = applyFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t applied = ctx.r3.u32 & 0xFF;
		if (applied != 0) {
			success = 1;
		}
		// state the destructor may pass on
		ctx.r9.u64 = applied;
	}

	CEndianFileStream_Destruct(ctx, base, streamAddr);
	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return success;
}
PROMOTED_ENTRY(87, sub_82BC3430, 0x82BC3430) { ctx.r3.u64 = n_sub_82BC3430(ctx, base, ctx.r3.u64, ctx.r7.u64); }

uint64_t n_sub_82BC3568(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr, uint32_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(87, 0x82BC3568)) { ctx.r3.u64 = gameObjectAddr; ctx.r4.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_82BC3568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BC3568);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);

	stack = PushStackFrame(base, stack, 208);

	uint32_t entryCount = arg2 + 1;
	uint32_t setupBuffer = stack + 96;

	ctx.fpscr.disableFlushMode();
	ctx.r1.u64 = stack;
	ctx.r6.u64 = 0;
	ctx.f1.f64 = double(LOAD_F32(0x8209BF2Cu));
	n_sub_82BAE2E8(ctx, base, setupBuffer, entryCount, arg3);

	// r6-r9 as the first indirect call receives them: the setup call's values (r9: m_20)
	// unless the loop below runs
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	uint32_t r9Value = gameObject->m_20;
	flags.ca = ctx.xer.ca;

	// Index every entry of the list at m_24 in the table the setup call built at stack+128.
	uint32_t entryTotal = r9Value + (uint32_t)gameObject->m_18;
	uint32_t cursor = gameObject->m_24;
	if ((int32_t)entryTotal > 0) {
		do {
			uint32_t entryId = LOAD32(cursor);
			r9Value = entryId;
			r8Value = LOAD32(stack + 128);
			r7Value = entryId << 2;
			STORE32((uint32_t)r7Value + (uint32_t)r8Value, cursor);
			r6Value = LOAD8(cursor + 9);
			if ((uint32_t)r6Value != 0) {
				cursor += 256;
			} else {
				cursor += 12;
			}
			flags.ca = entryTotal > 0;
			entryTotal -= 1;
		} while ((int32_t)entryTotal != 0);
	}

	uint32_t objectA = gameObject->m_4;
	uint32_t methodA = LOAD32(LOAD32(objectA) + 32);
	callTarget.u64 = (uint64_t)methodA;
	ctx.r3.u64 = objectA;
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.r9.u64 = r9Value;
	ctx.r10.u64 = methodA;
	ctx.xer.ca = flags.ca;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t objectB = ctx.r3.u64;

	uint32_t vtableB = LOAD32((uint32_t)objectB);
	uint32_t methodB = LOAD32(vtableB + 56);
	callTarget.u64 = (uint64_t)methodB;
	ctx.r4.u64 = setupBuffer;
	ctx.r8.u64 = methodB;
	ctx.r9.u64 = vtableB;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t workR7 = ctx.r7.u64;
	uint64_t workR8 = ctx.r8.u64;
	flags.ca = ctx.xer.ca;

	uint64_t entryTotal3 = (uint64_t)(uint32_t)gameObject->m_20 + (uint32_t)gameObject->m_18;
	uint32_t tableCount = LOAD32(stack + 132);
	uint32_t cursor3 = gameObject->m_24;
	if ((int32_t)entryTotal3 > 0) {
		workR8 = entryTotal3;
		do {
			uint32_t id = LOAD32(cursor3);
			if ((int32_t)id < (int32_t)tableCount) {
				workR7 = LOAD32(stack + 128);
				STORE32(cursor3 + 4, LOAD32((uint32_t)(id << 2) + (uint32_t)workR7));
			}
			if (LOAD8(cursor3 + 9) != 0) {
				cursor3 += 256;
			} else {
				cursor3 += 12;
			}
			flags.ca = (uint32_t)workR8 > 0;
			workR8 = (int64_t)workR8 - 1;
		} while ((int32_t)workR8 != 0);
	}

	STORE32(stack + 84, entryCount);
	STORE32(stack + 80, 0);
	uint32_t allocSize = entryCount << 4;
	ctx.r7.u64 = workR7;
	ctx.r8.u64 = workR8;
	ctx.xer.ca = flags.ca;
	uint64_t instanceA = Allocator_GetInstance(ctx, base);

	uint64_t idBuffer = n_sub_82BA8F18(ctx, base, instanceA, (uint64_t)allocSize,
	                                   (uint64_t)(int64_t)-2112891072, (uint64_t)(int64_t)-2112891192, 46);
	STORE32(stack + 80, (uint32_t)idBuffer);
	memset(ctx, base, idBuffer, 0, (uint64_t)allocSize);

	uint32_t objectC = gameObject->m_8;
	uint32_t vtableC = LOAD32(objectC);
	uint32_t methodC = LOAD32(vtableC + 8);
	callTarget.u64 = (uint64_t)methodC;
	ctx.r3.u64 = objectC;
	ctx.r4.u64 = gameObjectAddr;
	ctx.r5.u64 = stack + 80;
	ctx.r7.u64 = methodC;
	ctx.r8.u64 = vtableC;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t scratchR3 = ctx.r3.u64;
	uint32_t scratchR4 = ctx.r4.u32;
	uint64_t scratchR8 = ctx.r8.u64;
	flags.ca = ctx.xer.ca;

	uint32_t entryTotal4 = (uint32_t)gameObject->m_20 + (uint32_t)gameObject->m_18;
	uint32_t idLimit = LOAD32(stack + 84);
	uint64_t cursor4 = gameObject->m_24;  // 64-bit: r7 hands it over below
	if ((int32_t)entryTotal4 > 0) {
		uint32_t remaining4 = entryTotal4;
		do {
			uint32_t id = LOAD32((uint32_t)cursor4);
			if ((int32_t)id < (int32_t)idLimit) {
				scratchR8 = LOAD32((uint32_t)(id << 2) + LOAD32(stack + 80));
				STORE32((uint32_t)cursor4, (uint32_t)scratchR8);
			}
			if (LOAD8((uint32_t)cursor4 + 9) != 0) {
				uint64_t k = 0;
				scratchR8 = (uint64_t)id + (uint64_t)(id << 1);
				uint32_t dest = (uint32_t)cursor4 + 236;
				do {
					uint32_t count = LOAD32(stack + 84);
					scratchR4 = LOAD32(stack + 80);
					scratchR3 = (scratchR8 + count) + k;
					uint32_t value = LOAD32(((uint32_t)scratchR3 << 2) + scratchR4);
					if (value == 0) break;
					k += 1;
					STORE32(dest, value);
					dest += 4;
				} while ((int32_t)k < 3);
			}
			if (LOAD8((uint32_t)cursor4 + 9) != 0) {
				cursor4 += 256;
			} else {
				cursor4 += 12;
			}
			flags.ca = remaining4 > 0;
			remaining4 -= 1;
		} while ((int32_t)remaining4 != 0);
	}

	uint32_t idCount = LOAD32(stack + 84);
	uint32_t idTable = LOAD32(stack + 80);
	ctx.r3.u64 = scratchR3;
	ctx.r4.u64 = scratchR4;
	ctx.r7.u64 = cursor4;
	ctx.r8.u64 = scratchR8;
	ctx.xer.ca = flags.ca;
	uint64_t instanceB = Allocator_GetInstance(ctx, base);

	uint64_t freeResult = n_sub_82BA9068(ctx, base, instanceB, (uint64_t)idTable, (uint64_t)(idCount << 4));

	STORE32(stack + 136, 0);
	uint32_t entryTableCount = LOAD32(stack + 132);
	uint32_t entryTable = LOAD32(stack + 128);
	ctx.r3.u64 = freeResult;
	uint64_t instanceC = Allocator_GetInstance(ctx, base);

	uint64_t result = n_sub_82BA9068(ctx, base, instanceC, (uint64_t)entryTable, (uint64_t)(entryTableCount << 2));
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(87, sub_82BC3568, 0x82BC3568) { ctx.r3.u64 = n_sub_82BC3568(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r7.u64); }

// sub_82BC37A8  [8 bytes]
void n_sub_82BC37A8(CpuState& ctx, uint8_t* base, uint32_t gameObjectAddr, uint32_t arg2) {
	if (!UseLiftedCode(87, 0x82BC37A8)) { ctx.r3.u64 = gameObjectAddr; ctx.r4.u64 = arg2; __imp__sub_82BC37A8(ctx, base); return; }
	LiftedFrame frame(0x82BC37A8);
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);
	gameObject->m_6F0 = arg2;
	return;
}
PROMOTED_ENTRY(87, sub_82BC37A8, 0x82BC37A8) { n_sub_82BC37A8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82BC37B0(CpuState& ctx, uint8_t* base, uint64_t objectAddr) {
	if (!UseLiftedCode(87, 0x82BC37B0)) { ctx.r3.u64 = objectAddr; __imp__sub_82BC37B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BC37B0);
	return LOAD32((uint32_t)objectAddr + 0x6F0);
}
PROMOTED_ENTRY(87, sub_82BC37B0, 0x82BC37B0) { ctx.r3.u64 = n_sub_82BC37B0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82BC37B8(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint64_t arg5) {
	if (!UseLiftedCode(87, 0x82BC37B8)) { ctx.r3.u64 = gameObjectAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82BC37B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BC37B8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);

	stack = PushStackFrame(base, stack, 272);

	// blocks set up by n_sub_82BAE2E8: data pointer at +32, count at +36
	uint32_t blockA = stack + 96;
	uint32_t blockB = stack + 144;
	uint32_t entryCount = LOAD32(arg2 + 40);
	double initialValue = double(LOAD_F32(0x8209BF2Cu));

	ctx.r1.u64 = stack;
	ctx.f1.f64 = initialValue;
	n_sub_82BAE2E8(ctx, base, blockB, entryCount, arg5);
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = initialValue;
	n_sub_82BAE2E8(ctx, base, blockA, entryCount, ctx.r7.u64);

	if ((int32_t)entryCount > 0) {
		uint32_t offset = 0;
		int32_t remaining = (int32_t)entryCount;
		do {
			STORE32(stack + 80, LOAD32(LOAD32(LOAD32(arg2 + 32) + offset) + 4));
			n_sub_82BAE368(ctx, base, blockB, stack + 80);
			// the loop's count-down leaves the carry set; the next call sees it
			ctx.xer.ca = 1;
			offset += 4;
			remaining -= 1;
		} while (remaining != 0);
	}

	uint32_t arg4Value = 0;
	if (arg4 != 0) {
		arg4Value = LOAD32(arg4 + 4);
	}
	n_sub_82BC4040(ctx, base, (uint32_t)gameObjectAddr + 16, blockB, blockA, arg4Value, ctx.r7.u64);

	if ((int32_t)entryCount > 0) {
		uint32_t offset = 0;
		int32_t remaining = (int32_t)entryCount;
		do {
			uint32_t blockBEntry = LOAD32(LOAD32(blockB + 32) + offset);
			uint32_t arg3Entry = LOAD32(LOAD32(arg3 + 32) + offset);
			if (blockBEntry != 0 && (int32_t)LOAD32(arg3Entry + 4) == (int32_t)blockBEntry) {
				uint32_t source = gameObject->m_4;
				uint32_t sourceVtable = LOAD32(source);
				uint32_t blockAEntry = LOAD32(LOAD32(blockA + 32) + offset);
				uint32_t sourceMethod = LOAD32(sourceVtable + 32);
				callTarget.u64 = sourceMethod;
				ctx.r3.u64 = source;
				ctx.r9.u64 = sourceMethod;
				ctx.r10.u64 = sourceVtable;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				// r3 still holds the returned object for the next call
				uint32_t resolved = ctx.r3.u32;
				uint32_t resolvedVtable = LOAD32(resolved);
				uint32_t resolvedMethod = LOAD32(resolvedVtable + 32);
				callTarget.u64 = resolvedMethod;
				ctx.r4.u64 = arg3Entry;
				ctx.r5.u64 = blockAEntry;
				ctx.r7.u64 = resolvedMethod;
				ctx.r8.u64 = resolvedVtable;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				STORE32(blockAEntry + 4, arg3Entry);
			}
			offset += 4;
			remaining -= 1;
		} while (remaining != 0);
	}

	uint32_t dispatcher = gameObject->m_8;
	uint32_t dispatchMethod = LOAD32(LOAD32(dispatcher) + 60);
	callTarget.u64 = dispatchMethod;
	ctx.r3.u64 = dispatcher;
	ctx.r4.u64 = gameObjectAddr;
	ctx.r5.u64 = blockA;
	ctx.r10.u64 = dispatchMethod;
	if ((int32_t)entryCount > 0) {
		ctx.xer.ca = 1;  // carry left by the second loop's count-down
	}
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t lastResult = ctx.r3.u64;

	uint32_t element = LOAD32(arg3 + 32);
	// r8 is handed to each call below: the array end at first, then what the previous call left
	uint64_t r8Value = (uint64_t)(LOAD32(arg3 + 40) << 2) + element;
	if (element != (uint32_t)r8Value) {
		uint64_t memberAddr = gameObjectAddr + 1728;
		do {
			ctx.r8.u64 = r8Value;
			lastResult = n_sub_82284810(ctx, base, memberAddr, element);
			r8Value = ctx.r8.u64;
			element += 4;
		} while (element != (LOAD32(arg3 + 40) << 2) + LOAD32(arg3 + 32));
	}

	STORE32(blockA + 40, 0);
	uint32_t blockACount = LOAD32(blockA + 36);
	uint32_t blockAData = LOAD32(blockA + 32);
	ctx.r3.u64 = lastResult;
	ctx.r8.u64 = r8Value;
	uint64_t allocator = Allocator_GetInstance(ctx, base);
	uint64_t freeResult = n_sub_82BA9068(ctx, base, allocator, blockAData, blockACount << 2);

	STORE32(blockA + 36, 0);
	STORE32(blockA + 32, 0);
	STORE32(blockB + 40, 0);
	uint32_t blockBCount = LOAD32(blockB + 36);
	uint32_t blockBData = LOAD32(blockB + 32);
	ctx.r3.u64 = freeResult;
	uint64_t allocator2 = Allocator_GetInstance(ctx, base);
	uint64_t result = n_sub_82BA9068(ctx, base, allocator2, blockBData, blockBCount << 2);

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(87, sub_82BC37B8, 0x82BC37B8) { ctx.r3.u64 = n_sub_82BC37B8(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u64); }

uint64_t n_sub_82BC3990(CpuState& ctx, uint8_t* base, uint64_t gameObjectAddr, uint64_t ownerAddr, uint64_t transformAddr) {
	if (!UseLiftedCode(87, 0x82BC3990)) { ctx.r3.u64 = gameObjectAddr; ctx.r4.u64 = ownerAddr; ctx.r5.u64 = transformAddr; __imp__sub_82BC3990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BC3990);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	CGameObject* gameObject = GameObject<CGameObject>(base, gameObjectAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = gameObjectAddr;
	uint64_t originalTransform = transformAddr;
	uint32_t objectId = LOAD32((uint32_t)ownerAddr + 12);
	// what callers read back in r4: the id, or what the last call below left there
	uint64_t r4Out = objectId;

	if (objectId != 0) {
		uint32_t method = LOAD32(uint32_t(gameObject->vtable) + 40);
		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = gameObjectAddr;
		ctx.r4.u64 = objectId;
		ctx.r5.u64 = transformAddr;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r4Out = ctx.r4.u64;
		transformAddr = ctx.r5.u64;
	}

	uint32_t linkedBody = LOAD32((uint32_t)ownerAddr + 4);
	if (linkedBody != 0 && LOAD8(linkedBody + 9) != 0) {
		uint32_t method = LOAD32(uint32_t(gameObject->vtable) + 52);
		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = gameObjectAddr;
		ctx.r4.u64 = linkedBody;
		ctx.r5.u64 = transformAddr;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		if ((LOAD8(linkedBody + 0xFB) & 0x20) != 0) {
			n_sub_8229E148(ctx, base,
				(uint64_t)linkedBody + 60,
				linkedBody + 12,
				linkedBody + 24,
				linkedBody + 36,
				linkedBody + 48,
				LOAD8(linkedBody + 0xF9),
				LOAD8(linkedBody + 0xF8));
		}

		result = Matrix4x4_Multiply_8229DBD8(ctx, base, originalTransform, (uint64_t)linkedBody + 60);
		r4Out = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(87, sub_82BC3990, 0x82BC3990) { ctx.r3.u64 = n_sub_82BC3990(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82BC3A38(CpuState& ctx, uint8_t* base, uint64_t objectAddr) {
	if (!UseLiftedCode(87, 0x82BC3A38)) { ctx.r3.u64 = objectAddr; __imp__sub_82BC3A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BC3A38);
	PPCRegister callTarget{};
	uint32_t target = LOAD32((uint32_t)objectAddr + 8);
	uint32_t method = LOAD32(LOAD32(target) + 68);
	callTarget.u64 = method;
	ctx.r3.u64 = target;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(87, sub_82BC3A38, 0x82BC3A38) { ctx.r3.u64 = n_sub_82BC3A38(ctx, base, ctx.r3.u64); }
