// CECCarrying (vtable 0x82004320): methods of the class as readable C++.
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

uint64_t CECCarrying_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820BBD8C_B_ = int32_t(0x820BBD8C);
	if (!UseLiftedCode(31, 0x824FE470)) { ctx.r3.u64 = classNameString; __imp__sub_824FE470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824FE470);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820BBD8C_B_, -1);
	return classNameString;
}
PROMOTED_ENTRY(31, sub_824FE470, 0x824FE470) { ctx.r3.u64 = CECCarrying_GetClassName(ctx, base, ctx.r3.u64); }

uint32_t CECCarrying_AddEntry(CpuState& ctx, uint8_t* base, uint64_t carryingAddr, uint64_t nameString) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(31, 0x824FE4B0)) { ctx.r3.u64 = carryingAddr; ctx.r4.u64 = nameString; __imp__sub_824FE4B0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824FE4B0);
	uint32_t stack = ctx.r1.u64;
	CECCarrying* carrying = GameObject<CECCarrying>(base, carryingAddr);
	// The carried entry array: begin at [entryList+4], end at [entryList+8], capacity end at [entryList+12].
	uint64_t entryListAddr = carryingAddr + 12;

	stack = PushStackFrame(base, stack, 176);
	ctx.r1.u64 = stack;

	uint32_t entryKey = String_HashCrc32(ctx, base, nameString);

	// Build the entry {key, EntityHandle}: key at stack+96, handle at stack+100, scratch handle at stack+80.
	STORE32(stack + 84, 0);
	STORE32(stack + 80, (uint32_t)g_820F1664);
	ctx.r10.u64 = (uint64_t)(int64_t)g_820F1664;
	EntityHandle_SetTarget(ctx, base, stack + 80, 0);
	STORE32(stack + 96, entryKey);
	EntityHandle_CopyConstruct(ctx, base, stack + 100, stack + 80);

	// r8 is handed to the calls below: the capacity in bytes, or what the copy left in r8 when the array is empty
	uint64_t capacityBytes = ctx.r8.u64;
	uint32_t begin = carrying->m_10;
	uint32_t capacityCount = 0;
	if (begin != 0) {
		capacityBytes = (uint64_t)LOAD32((uint32_t)entryListAddr + 12) - begin;
		capacityCount = uint32_t((int32_t)capacityBytes / 12);
	}
	uint32_t end = LOAD32((uint32_t)entryListAddr + 8);
	uint32_t count = uint32_t((int32_t)(end - begin) / 12);

	if (count < capacityCount) {
		if (end != 0) {
			STORE32(end, LOAD32(stack + 96));
			ctx.r8.u64 = capacityBytes;
			ctx.r9.u64 = count;
			ctx.r10.u64 = capacityCount;
			EntityHandle_CopyConstruct(ctx, base, end + 4, stack + 100);
			capacityBytes = ctx.r8.u64;
			count = ctx.r9.u32;
			capacityCount = ctx.r10.u32;
		}
		STORE32((uint32_t)entryListAddr + 8, end + 12);
	} else {
		STORE32(stack + 92, end);
		STORE32(stack + 88, 0);
		ctx.r5.u64 = 1;
		ctx.r8.u64 = capacityBytes;
		ctx.r9.u64 = count;
		ctx.r10.u64 = capacityCount;
		Vector_InsertEntry(ctx, base, entryListAddr, LOAD64(stack + 88), stack + 96);
		capacityBytes = ctx.r8.u64;
		count = ctx.r9.u32;
		capacityCount = ctx.r10.u32;
	}

	STORE32(stack + 100, (uint32_t)g_820F1664);
	ctx.r8.u64 = capacityBytes;
	ctx.r9.u64 = count;
	ctx.r10.u64 = capacityCount;
	EntityHandle_Release(ctx, base, stack + 100);
	STORE32(stack + 80, (uint32_t)g_820F1664);
	STORE8((uint32_t)entryListAddr + 17, 1);
	EntityHandle_Release(ctx, base, stack + 80);

	STORE32(stack + 80, entryKey);
	CCharString_CopyConstruct(ctx, base, stack + 84, nameString);
	Vector_InsertPair(ctx, base, carryingAddr + 0x20, stack + 80);
	uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);
	carrying->m_31 = 1;

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_824FE4B0, 0x824FE4B0) { ctx.r3.u64 = CECCarrying_AddEntry(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECCarrying_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t objectPtr, uint64_t flags) {
	if (!UseLiftedCode(31, 0x824FE5E0)) { ctx.r3.u64 = objectPtr; ctx.r4.u64 = flags; __imp__sub_824FE5E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824FE5E0);
	GameStackFrame stackFrame(ctx, base, 112);
	// state the callee may pass on
	ctx.r4.u64 = flags;
	CECCarrying_Destructor(ctx, base, objectPtr);
	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, objectPtr);
	}
	return objectPtr;
}
PROMOTED_ENTRY(31, sub_824FE5E0, 0x824FE5E0) { ctx.r3.u64 = CECCarrying_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECCarrying_FindKeyValue(CpuState& ctx, uint8_t* base, uint32_t carryingAddr, uint32_t key) {
	constexpr int32_t g_834A5B6C = int32_t(0x834A5B6C);
	if (!UseLiftedCode(31, 0x824FEA18)) { ctx.r3.u64 = carryingAddr; ctx.r4.u64 = key; __imp__sub_824FEA18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824FEA18);
	uint32_t stack = ctx.r1.u32;
	CECCarrying* carrying = GameObject<CECCarrying>(base, carryingAddr);
	// r6 and r8 keep the caller's values unless the search loop runs
	uint64_t probedKey = ctx.r6.u64;
	uint64_t probeOffset = ctx.r8.u64;
	uint64_t it = carrying->m_24;
	uint32_t end = carrying->m_28;

	STORE32(stack - 16, 0u);
	uint32_t byteSize = end - (uint32_t)it;
	STORE32(stack - 12, (uint32_t)it);

	// carry of the arithmetic shift below, left in xer.ca for callers
	bool carry = (int32_t)byteSize < 0 && (byteSize & 0x7) != 0;
	// lower_bound over the array of 8-byte entries, ordered by their first (key) word
	int32_t remaining = (int32_t)byteSize >> 3;
	if (remaining > 0) {
		do {
			int32_t half = remaining >> 1;
			probeOffset = (uint32_t)half << 3;
			it += probeOffset;
			probedKey = LOAD32((uint32_t)it);
			if ((uint32_t)probedKey < key) {
				it += 8;
				remaining = remaining - half - 1;
			} else {
				it -= probeOffset;
				remaining = half;
			}
		} while (remaining > 0);
		STORE32(stack - 12, (uint32_t)it);
	}

	uint32_t found = end;
	if ((uint32_t)it != end && !(key < LOAD32((uint32_t)it))) {
		STORE64(stack - 16, LOAD64(stack - 16));
		found = (uint32_t)it;
	}

	// callers read r6-r9 and the carry after the call
	ctx.r6.u64 = probedKey;
	ctx.r7.u64 = end;
	ctx.r8.u64 = probeOffset;
	ctx.r9.u64 = it;
	ctx.xer.ca = carry;
	if (found == carrying->m_28) {
		return g_834A5B6C;
	}
	return (uint64_t)found + 4;
}
PROMOTED_ENTRY(31, sub_824FEA18, 0x824FEA18) { ctx.r3.u64 = CECCarrying_FindKeyValue(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CECCarrying_ReleaseHandleArray(CpuState& ctx, uint8_t* base, uint64_t self) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(31, 0x824FEF28)) { ctx.r3.u64 = self; __imp__sub_824FEF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824FEF28);
	uint32_t stack = ctx.r1.u64;
	// r5, r7 and r8 as the loop leaves them are handed to SharedHandle_Release
	uint64_t reg5 = ctx.r5.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t result = self;
	uint64_t handleSlot = self + 52;

	stack = PushStackFrame(base, stack, 144);
	if (LOAD32((uint32_t)handleSlot) != 0) {
		// Walk the 12-byte elements of the array the handle refers to (begin at +4, end at +8),
		// re-reading the array for every element.
		uint32_t index = 0;
		uint32_t elementOffset = 0;
		for (;;) {
			uint32_t array = LOAD32((uint32_t)handleSlot);
			uint32_t begin = LOAD32(array + 4);
			if (begin == 0) break;
			uint32_t end = LOAD32(array + 8);
			reg8 = (uint64_t)end - begin;
			uint32_t count = (uint32_t)((int32_t)reg8 / 12);
			reg7 = count;
			if (index >= count) break;

			uint32_t element = begin + elementOffset;
			uint32_t table = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
			uint32_t tableEntry = LOAD32(table + 88);
			uint32_t objectSlot = LOAD32(tableEntry + 4);
			uint32_t lookupObject = LOAD32(objectSlot);

			ctx.r1.u64 = stack;
			// state the callee may pass on
			uint64_t entity = EntityManager_LookupEntity(ctx, base, lookupObject, element + 4);
			reg5 = entity;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;

			if ((uint32_t)entity != 0 && (LOAD8((uint32_t)entity + 0x90) & 0x40) != 0) {
				uint32_t array2 = LOAD32((uint32_t)handleSlot);
				uint32_t begin2 = LOAD32(array2 + 4);
				bool inRange = false;
				if (begin2 != 0) {
					reg8 = (uint32_t)((int32_t)(LOAD32(array2 + 8) - begin2) / 12);
					inRange = index < (uint32_t)reg8;
				}
				if (!inRange) {
					ppc_trap(ctx, base, 22);
				}
				n_sub_82500DA0(ctx, base, self, begin2 + elementOffset, reg5, reg8);
				reg5 = ctx.r5.u64;
				reg7 = ctx.r7.u64;
				reg8 = ctx.r8.u64;
			}

			index++;
			elementOffset += 12;
		}

		ctx.r1.u64 = stack;
		ctx.r5.u64 = reg5;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		result = SharedHandle_Release(ctx, base, handleSlot);
		STORE32((uint32_t)handleSlot, 0u);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_824FEF28, 0x824FEF28) { ctx.r3.u64 = CECCarrying_ReleaseHandleArray(ctx, base, ctx.r3.u64); }

// The original is a single branch to sub_824FF1A0.
uint64_t CECCarrying_CleanupCarriedEntities(CpuState& ctx, uint8_t* base, uint64_t self) {
	if (!UseLiftedCode(31, 0x824FF048)) { ctx.r3.u64 = self; __imp__sub_824FF048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824FF048);
	return CECCarrying_CleanupCarriedEntitiesImpl(ctx, base, self);
}
PROMOTED_ENTRY(31, sub_824FF048, 0x824FF048) { ctx.r3.u64 = CECCarrying_CleanupCarriedEntities(ctx, base, ctx.r3.u64); }

uint32_t CECCarrying_ShouldReplicate(CpuState& ctx, uint8_t* base, uint32_t carryingAddr) {
	if (!UseLiftedCode(31, 0x824FF050)) { ctx.r3.u64 = carryingAddr; __imp__sub_824FF050(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824FF050);
	uint32_t stack = ctx.r1.u32;
	// Register state left for callers: the incoming values unless a path below changes them.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	PPCCRRegister cr0 = ctx.cr0;
	PPCXERRegister xer = ctx.xer;
	CECCarrying* carrying = GameObject<CECCarrying>(base, carryingAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t ownerAddr = carrying->m_4;
	uint32_t ownerFlags = LOAD32(ownerAddr + 0x2C);
	uint64_t reg10 = ownerFlags;
	uint64_t reg9 = (ownerFlags >> 27) & 1;

	bool shouldReplicate = true;
	if (reg9 != 0) {
		// The value stored under key 0x5B in the owner's {key, value} 8-byte entries at [+0x48, +0x4C).
		uint32_t component;
		uint32_t indexMap = LOAD32(ownerAddr + 0x8C);
		if (indexMap != 0) {
			// the map's byte at +0x5B is the entry index
			reg10 = (uint32_t)LOAD8(indexMap + 0x5B) << 3;
			reg9 = reg10 + LOAD32(ownerAddr + 0x48);
			component = LOAD32((uint32_t)reg9 + 4);
		} else {
			// lower_bound for key 0x5B over the entries, ordered by their signed key word
			uint32_t begin = LOAD32(ownerAddr + 0x48);
			uint32_t end = LOAD32(ownerAddr + 0x4C);
			reg6 = end;
			STORE32(stack + 80, 0);
			uint32_t byteSize = end - begin;
			STORE32(stack + 84, begin);
			xer.ca = (int32_t)byteSize < 0 && (byteSize & 0x7) != 0;
			int32_t remaining = (int32_t)byteSize >> 3;
			cr0.compare<int32_t>(remaining, 0, xer);
			uint64_t cursor = begin;
			if (remaining > 0) {
				do {
					int32_t half = remaining >> 1;
					reg9 = half;
					reg8 = (uint32_t)half << 3;
					cursor += reg8;
					bool keyBelow = (int32_t)LOAD32((uint32_t)cursor) < 0x5B;
					reg7 = keyBelow;
					if (keyBelow) {
						cursor += 8;
						remaining = remaining - half - 1;
					} else {
						cursor -= reg8;
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, (uint32_t)cursor);
			}
			reg10 = cursor;
			if ((uint32_t)cursor != end && (int32_t)LOAD32((uint32_t)cursor) <= 0x5B) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}

		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.xer.ca = xer.ca;
		shouldReplicate = (CECNetwork_ShouldReplicateEntity(ctx, base, component) & 0xFF) != 0;
		reg9 = ctx.r9.u64;
		reg10 = ctx.r10.u64;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r6-r10, cr0 and the carry after the call
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = reg9;
	ctx.r10.u64 = reg10;
	ctx.cr0.lt = cr0.lt;
	ctx.cr0.gt = cr0.gt;
	ctx.cr0.eq = cr0.eq;
	ctx.cr0.so = cr0.so;
	ctx.xer.ca = xer.ca;
	return shouldReplicate ? 1 : 0;
}
PROMOTED_ENTRY(31, sub_824FF050, 0x824FF050) { ctx.r3.u64 = CECCarrying_ShouldReplicate(ctx, base, ctx.r3.u32); }

uint64_t CECCarrying_CleanupCarriedEntitiesImpl(CpuState& ctx, uint8_t* base, uint64_t carryingAddr) {
	if (!UseLiftedCode(31, 0x824FF1A0)) { ctx.r3.u64 = carryingAddr; __imp__sub_824FF1A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824FF1A0);
	uint32_t stack = ctx.r1.u64;
	CECCarrying* carrying = GameObject<CECCarrying>(base, carryingAddr);

	stack = PushStackFrame(base, stack, 144);

	// Walk the 12-byte entries in [m_10, m_14) (handle at +4, its holder at +8), re-reading the array
	// after every entry: a handle whose holder no longer points at an entity is released, and an
	// entity with flag 0x40 at +0x90 is destroyed.
	uint64_t result = carryingAddr;
	uint32_t index = 0;
	uint32_t entryOffset = 0;
	uint32_t byteSize = carrying->m_14 - carrying->m_10;
	uint32_t entryCount = (uint32_t)((int32_t)byteSize / 12);
	while (index < entryCount) {
		uint32_t entryAddr = carrying->m_10 + entryOffset;
		uint32_t holderAddr = LOAD32(entryAddr + 8);
		if (holderAddr != 0) {
			uint32_t entityAddr = LOAD32(holderAddr);
			if (entityAddr == 0) {
				ctx.r1.u64 = stack;
				// state the callee may pass on
				result = EntityHandle_Release(ctx, base, entryAddr + 4);
			} else if ((LOAD8(entityAddr + 0x90) & 0x40) != 0) {
				ctx.r1.u64 = stack;
				result = Entity_DestroyImpl(ctx, base, entityAddr);
			}
		}

		++index;
		entryOffset += 12;
		byteSize = carrying->m_14 - carrying->m_10;
		entryCount = (uint32_t)((int32_t)byteSize / 12);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_824FF1A0, 0x824FF1A0) { ctx.r3.u64 = CECCarrying_CleanupCarriedEntitiesImpl(ctx, base, ctx.r3.u64); }

// Returns 1 when the carrying has an entry for the name's hash whose entity is missing or lacks flag 0x40, else 0.
uint32_t CECCarrying_IsEntryInvalid(CpuState& ctx, uint8_t* base, uint32_t carryingAddr, uint64_t nameString) {
	if (!UseLiftedCode(31, 0x824FF290)) { ctx.r3.u64 = carryingAddr; ctx.r4.u64 = nameString; __imp__sub_824FF290(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824FF290);
	uint32_t stack = ctx.r1.u64;
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	CECCarrying* carrying = GameObject<CECCarrying>(base, carryingAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = nameString;  // state the callee may pass on
	uint32_t nameHash = String_HashCrc32(ctx, base, (uint32_t)nameString);
	// r6 as the original holds it: what the hash call left, then the last entry hash the search read
	uint64_t r6Value = ctx.r6.u64;

	// lower-bound search over the 12-byte entries [m_10, m_14), ordered by the hash in their first word
	uint64_t cursor = carrying->m_10;
	uint32_t entriesEnd = carrying->m_14;
	uint64_t offset = (uint64_t)entriesEnd - cursor;
	STORE32(stack + 80, 0u);
	uint32_t count = (uint32_t)((int32_t)offset / 12);
	compare0.compare<int32_t>((int32_t)count, 0, flags);
	STORE32(stack + 84, (uint32_t)cursor);
	if ((int32_t)count > 0) {
		do {
			flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
			uint64_t half = (int32_t)count >> 1;
			offset = (uint32_t)half * 12;
			cursor = offset + cursor;
			uint32_t entryHash = LOAD32((uint32_t)cursor);
			r6Value = entryHash;
			if (entryHash < nameHash) {
				cursor += 12;
				count = (uint32_t)((int64_t)(count - half) - 1);
			} else {
				cursor = cursor - offset;
				count = (uint32_t)half;
			}
		} while ((int32_t)count > 0);
		STORE32(stack + 84, (uint32_t)cursor);
	}
	uint32_t found;
	if ((uint32_t)cursor == entriesEnd || nameHash < LOAD32((uint32_t)cursor)) {
		found = entriesEnd;
	} else {
		STORE64(stack + 80, LOAD64(stack + 80));
		found = LOAD32(stack + 84);
	}

	uint32_t entriesEndReload = carrying->m_14;
	if (found == entriesEndReload) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		// callers read r6-r8, cr0 and ca after the call
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = entriesEnd;
		ctx.r8.u64 = offset;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		return 0;
	}

	// state the callee may pass on
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = entriesEnd;
	ctx.r8.u64 = offset;
	ctx.r9.u64 = cursor;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	uint32_t entity = EntityHandle_Get_825575C8(ctx, base, (uint64_t)found + 4);

	bool entityValid = entity != 0 && (LOAD8(entity + 144) & 64) != 0;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return entityValid ? 0 : 1;
}
PROMOTED_ENTRY(31, sub_824FF290, 0x824FF290) { ctx.r3.u64 = CECCarrying_IsEntryInvalid(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// Walks the carrying's 12-byte entries: releases handles whose entity is gone, and for each valid entity
// (flag 0x40) with bit 18 of +0x2C set appends the 16-byte elements of its key-82 object to destVector.
uint32_t CECCarrying_CollectElements(CpuState& ctx, uint8_t* base, uint32_t carryingAddr, uint64_t destVector) {
	if (!UseLiftedCode(31, 0x824FF650)) { ctx.r3.u64 = carryingAddr; ctx.r4.u64 = destVector; __imp__sub_824FF650(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824FF650);
	uint32_t stack = ctx.r1.u64;
	uint32_t result = carryingAddr;
	// r4, r6 and r7 as the original holds them: all three are handed to EntityHandle_Release, r6 and r7
	// also back to callers
	uint64_t savedR4 = destVector;
	uint64_t savedR6 = ctx.r6.u64;
	uint64_t savedR7 = ctx.r7.u64;
	PPCXERRegister flags = ctx.xer;
	CECCarrying* carrying = GameObject<CECCarrying>(base, carryingAddr);
	stack = PushStackFrame(base, stack, 192);

	uint32_t vectorBytes = (uint32_t)carrying->m_14 - (uint32_t)carrying->m_10;
	uint32_t elementCount = (uint32_t)((int32_t)vectorBytes / 12);
	if ((int32_t)elementCount != 0) {
		uint64_t elementOffset = 0;
		uint32_t i = 0;
		do {
			uint64_t elementAddr = (uint64_t)carrying->m_10 + elementOffset;
			uint64_t handleAddr = elementAddr + 4;
			uint32_t handlePtr = LOAD32((uint32_t)elementAddr + 8);
			uint32_t entity = 0;
			bool entityValid = false;
			if (handlePtr != 0) {
				entity = LOAD32(handlePtr);
				if (entity == 0) {
					// stale handle: release it and skip this entry
					ctx.r1.u64 = stack;
					// state the callee may pass on
					ctx.xer.ca = flags.ca;
					result = EntityHandle_Release(ctx, base, handleAddr);
					savedR4 = ctx.r4.u64;
					savedR6 = ctx.r6.u64;
					savedR7 = ctx.r7.u64;
					flags.ca = ctx.xer.ca;
				} else {
					entityValid = (LOAD8(entity + 0x90) & 0x40) != 0;
				}
			}
			if (entityValid) {
				uint32_t key82Object = 0;
				bool haveObject = false;
				if ((LOAD32(entity + 0x2C) >> 18) & 1) {
					// the entity's sorted 8-byte (key, value) entries run from [+0x48] to [+0x4C]; when the byte
					// table at [+0x8C] exists, its byte 82 is the index of key 82's entry
					uint32_t slotTable = LOAD32(entity + 0x8C);
					if (slotTable != 0) {
						uint32_t slotAddr = (LOAD8(slotTable + 0x52) << 3) + LOAD32(entity + 0x48);
						key82Object = LOAD32(slotAddr + 4);
						haveObject = true;
					} else {
						// lower-bound search of the sorted entries for key 82
						uint32_t searchBegin = LOAD32(entity + 0x48);
						uint32_t searchEnd = LOAD32(entity + 0x4C);
						uint32_t pos = searchBegin;
						STORE32(stack + 80, 0);
						STORE32(stack + 84, searchBegin);
						uint32_t searchBytes = searchEnd - searchBegin;
						flags.ca = ((int32_t)searchBytes < 0) && ((searchBytes & 0x7) != 0);
						int32_t remaining = (int32_t)searchBytes >> 3;
						if (remaining > 0) {
							do {
								flags.ca = (remaining < 0) && ((remaining & 0x1) != 0);
								int32_t half = remaining >> 1;
								uint32_t mid = pos + (uint32_t)(half << 3);
								if ((int32_t)LOAD32(mid) < 82) {
									pos = mid + 8;
									remaining = remaining - half - 1;
								} else {
									remaining = half;
								}
							} while (remaining > 0);
							STORE32(stack + 84, pos);
						}
						if (pos != searchEnd && (int32_t)LOAD32(pos) <= 82) {
							STORE64(stack + 96, LOAD64(stack + 80));
							key82Object = LOAD32(LOAD32(stack + 100) + 4);
						} else {
							key82Object = LOAD32(searchEnd + 4);
						}
						haveObject = true;
					}
				}
				if (haveObject) {
					uint32_t sourceBegin = LOAD32(key82Object + 0x10);
					uint32_t sourceEnd = LOAD32(key82Object + 0x14);
					uint64_t destBytes = (uint64_t)LOAD32((uint32_t)destVector + 8) - (uint64_t)LOAD32((uint32_t)destVector + 4);
					uint64_t sourceBytes = (uint64_t)sourceEnd - (uint64_t)sourceBegin;
					flags.ca = ((int32_t)sourceBytes < 0) && ((sourceBytes & 0xF) != 0);
					uint64_t totalCount = (uint64_t)(int64_t)((int32_t)destBytes >> 4) + (uint64_t)(int64_t)((int32_t)sourceBytes >> 4);
					ctx.r1.u64 = stack;
					// state the callee may pass on
					ctx.r5.u64 = sourceBytes;
					ctx.r6.u64 = destBytes;
					ctx.r7.u64 = sourceBegin;
					ctx.xer.ca = flags.ca;
					result = Vector16_Reserve(ctx, base, destVector, totalCount, sourceEnd);
					savedR6 = ctx.r6.u64;
					savedR7 = ctx.r7.u64;
					flags.ca = ctx.xer.ca;
					uint32_t copyBegin = LOAD32(key82Object + 0x10);
					STORE32(stack + 88, 0);
					STORE32(stack + 92, copyBegin);
					savedR4 = LOAD64(stack + 88);
					STORE64(stack + 96, savedR4);
					uint32_t copyEnd = LOAD32(key82Object + 0x14);
					if (copyBegin != copyEnd) {
						uint64_t src = LOAD32(stack + 100);
						do {
							result = Vector16_PushBack(ctx, base, destVector, src);
							savedR4 = ctx.r4.u64;
							savedR6 = ctx.r6.u64;
							savedR7 = ctx.r7.u64;
							flags.ca = ctx.xer.ca;
							src += 16;
						} while ((uint32_t)src != copyEnd);
					}
				}
			}
			i++;
			elementOffset += 12;
			vectorBytes = (uint32_t)carrying->m_14 - (uint32_t)carrying->m_10;
			elementCount = (uint32_t)((int32_t)vectorBytes / 12);
		} while (i < elementCount);
	}
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	// callers read r6-r8 and ca after the call
	ctx.r6.u64 = savedR6;
	ctx.r7.u64 = savedR7;
	ctx.r8.u64 = elementCount;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(31, sub_824FF650, 0x824FF650) { ctx.r3.u64 = CECCarrying_CollectElements(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// Rebuilds the map at +72: gathers 16-byte entries with sub_824FF650, empties the map, then per entry inserts
// sub_82545AF0's result when the id at +0 has a non-zero GameDB field, and that field when the id at +8 has one.
uint32_t CECCarrying_RebuildPropertyMap(CpuState& ctx, uint8_t* base, uint64_t carryingAddr) {
	if (!UseLiftedCode(31, 0x824FF8B8)) { ctx.r3.u64 = carryingAddr; __imp__sub_824FF8B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824FF8B8);
	uint32_t stack = ctx.r1.u64;
	PPCCRRegister compare0{};
	PPCXERRegister flags{};
	flags.so = ctx.xer.so;
	flags.ov = ctx.xer.ov;
	CECCarrying* carrying = GameObject<CECCarrying>(base, carryingAddr);

	stack = PushStackFrame(base, stack, 192);

	// sub_824FF650 appends 16-byte entries to the empty vector at stack+112 (begin at +116, end at +120)
	STORE32(stack + 116, 0);
	STORE32(stack + 120, 0);
	STORE32(stack + 124, 0);
	ctx.r1.u64 = stack;
	CECCarrying_CollectElements(ctx, base, carryingAddr, stack + 112);

	uint64_t propertyMap = carryingAddr + 72;
	uint32_t result = PropertyMap_EraseSubtree(ctx, base, propertyMap, LOAD32((uint32_t)carrying->m_4C + 4));

	// empty the map: the head node's links point back at the head and the count is zeroed. The head pointer
	// is re-read after each store as in the original; the three reads are what r8, r7 and r6 hold.
	uint64_t savedR8 = carrying->m_4C;
	uint32_t entriesBegin = LOAD32(stack + 116);
	uint32_t entriesBytes = LOAD32(stack + 120) - entriesBegin;
	STORE32((uint32_t)savedR8 + 4, (uint32_t)savedR8);
	uint64_t savedR7 = carrying->m_4C;
	flags.ca = (int32_t)entriesBytes < 0 & (entriesBytes & 0xF) != 0;
	uint32_t remaining = (int32_t)entriesBytes >> 4;
	compare0.compare<int32_t>((int32_t)remaining, 0, flags);
	carrying->m_50 = 0;
	STORE32((uint32_t)savedR7, (uint32_t)savedR7);
	uint64_t savedR6 = carrying->m_4C;
	STORE32((uint32_t)savedR6 + 8, (uint32_t)savedR6);

	if ((int32_t)remaining != 0) {
		uint64_t entry = entriesBegin;
		do {
			uint32_t firstId = LOAD32((uint32_t)entry);
			STORE32(stack + 80, 0);
			if (firstId != 0) {
				// state the callees may pass on
				ctx.xer.ca = flags.ca;
				uint64_t idRef = IdRef_Get(ctx, base, entry);
				result = GameDB_TryGetTypeField(ctx, base, idRef, stack + 80);
				savedR6 = ctx.r6.u64;
				savedR7 = ctx.r7.u64;
				savedR8 = ctx.r8.u64;
				if (LOAD32(stack + 80) != 0) {
					uint32_t insertValue = GameDB_GetTypeForIdRef(ctx, base, entry);
					STORE32(stack + 80, insertValue);
					ctx.cr0.lt = compare0.lt;
					ctx.cr0.gt = compare0.gt;
					ctx.cr0.eq = compare0.eq;
					ctx.cr0.so = compare0.so;
					result = Map_InsertUnique(ctx, base, stack + 88, propertyMap, stack + 80, ctx.r8.u64);
					savedR6 = ctx.r6.u64;
					savedR7 = ctx.r7.u64;
					savedR8 = ctx.r8.u64;
					compare0.lt = ctx.cr0.lt;
					compare0.gt = ctx.cr0.gt;
					compare0.eq = ctx.cr0.eq;
					compare0.so = ctx.cr0.so;
					flags.ca = ctx.xer.ca;
				}
			}

			uint32_t secondId = LOAD32((uint32_t)entry + 8);
			STORE32(stack + 80, 0);
			if (secondId != 0) {
				// state the callees may pass on
				ctx.xer.ca = flags.ca;
				uint64_t idRef = IdRef_Get(ctx, base, entry + 8);
				result = GameDB_TryGetTypeField(ctx, base, idRef, stack + 80);
				savedR6 = ctx.r6.u64;
				savedR7 = ctx.r7.u64;
				savedR8 = ctx.r8.u64;
				if (LOAD32(stack + 80) != 0) {
					// look the field up again and insert its value
					STORE32(stack + 80, 0);
					uint64_t idRefAgain = IdRef_Get(ctx, base, entry + 8);
					GameDB_TryGetTypeField(ctx, base, idRefAgain, stack + 80);
					STORE32(stack + 84, LOAD32(stack + 80));
					ctx.cr0.lt = compare0.lt;
					ctx.cr0.gt = compare0.gt;
					ctx.cr0.eq = compare0.eq;
					ctx.cr0.so = compare0.so;
					result = Map_InsertUnique(ctx, base, stack + 112, propertyMap, stack + 84, ctx.r8.u64);
					savedR6 = ctx.r6.u64;
					savedR7 = ctx.r7.u64;
					savedR8 = ctx.r8.u64;
				}
			}

			flags.ca = remaining != 0;
			remaining -= 1;
			compare0.compare<int32_t>((int32_t)remaining, 0, flags);
			entry += 16;
		} while ((int32_t)remaining != 0);
	}

	if (entriesBegin != 0) {
		// state the callee may pass on
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		result = HandleTarget_Free(ctx, base, entriesBegin);
		savedR6 = ctx.r6.u64;
		savedR7 = ctx.r7.u64;
		savedR8 = ctx.r8.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	// callers read r6-r8, cr0 and ca after the call
	ctx.r6.u64 = savedR6;
	ctx.r7.u64 = savedR7;
	ctx.r8.u64 = savedR8;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(31, sub_824FF8B8, 0x824FF8B8) { ctx.r3.u64 = CECCarrying_RebuildPropertyMap(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82503338(CpuState& ctx, uint8_t* base, uint64_t carryingAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(31, 0x82503338)) { ctx.r3.u64 = carryingAddr; ctx.r4.u64 = arg2; __imp__sub_82503338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82503338);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t entity = n_sub_825022E8(ctx, base, carryingAddr, arg2);

	uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t flagsBlock = LOAD32(LOAD32(globalRoot + 12) + 140);
	bool bothFlagsSet = LOAD8(flagsBlock + 52) != 0 && LOAD8(flagsBlock + 53) != 0;

	// with both flag bytes set, a valid entity (flag 0x40 at +144) is destroyed
	if (bothFlagsSet && (uint32_t)entity != 0 && (LOAD8((uint32_t)entity + 144) & 64) != 0) {
		entity = Entity_DestroyImpl(ctx, base, entity);
	}
	return entity;
}
PROMOTED_ENTRY(31, sub_82503338, 0x82503338) { ctx.r3.u64 = n_sub_82503338(ctx, base, ctx.r3.u64, ctx.r4.u64); }
