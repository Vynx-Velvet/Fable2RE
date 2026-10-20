// BasicString (vtable 0x820CCE94): methods of the class as readable C++.
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

uint64_t BasicString_AssignSubstr(CpuState& ctx, uint8_t* base, uint64_t dstStringAddr, uint64_t srcStringAddr, uint64_t startOffset, uint64_t requestedLength, uint64_t r8Value) {
	if (!UseLiftedCode(1, 0x8218EA38)) { ctx.r3.u64 = dstStringAddr; ctx.r4.u64 = srcStringAddr; ctx.r5.u64 = startOffset; ctx.r6.u64 = requestedLength; ctx.r8.u64 = r8Value; __imp__sub_8218EA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218EA38);
	uint32_t stack = ctx.r1.u64;
	BasicString* dstString = GameObject<BasicString>(base, dstStringAddr);
	stack = PushStackFrame(base, stack, 128);

	// r6 as the callees below receive it: requestedLength, or what the range-error handler left there
	uint64_t effectiveRequestedLength = requestedLength;
	if (LOAD32((uint32_t)srcStringAddr + 0x14) < (uint32_t)startOffset) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = dstStringAddr;
		ctx.r4.u64 = srcStringAddr;
		ctx.r6.u64 = requestedLength;
		n_sub_82CD12C8(ctx, base, r8Value);
		effectiveRequestedLength = ctx.r6.u64;
		r8Value = ctx.r8.u64;
	}

	uint64_t copyLength = (uint64_t)LOAD32((uint32_t)srcStringAddr + 0x14) - startOffset;
	if ((uint32_t)requestedLength < (uint32_t)copyLength) {
		copyLength = requestedLength;
	}

	if ((uint32_t)dstStringAddr == (uint32_t)srcStringAddr) {
		// Assigning part of the string to itself: erase what follows the range, then what precedes it.
		ctx.r1.u64 = stack;
		ctx.r6.u64 = effectiveRequestedLength;
		BasicString_Erase(ctx, base, dstStringAddr, copyLength + startOffset, -1, r8Value);
		BasicString_Erase(ctx, base, dstStringAddr, 0, startOffset, ctx.r8.u64);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return dstStringAddr;
	}

	ctx.r1.u64 = stack;
	ctx.r6.u64 = effectiveRequestedLength;
	uint32_t growResult = BasicString_Grow(ctx, base, dstStringAddr, copyLength, 0, r8Value);
	if ((growResult & 0xFF) != 0) {
		uint64_t srcData = (LOAD32((uint32_t)srcStringAddr + 0x18) >= 16)
			? (uint64_t)LOAD32((uint32_t)srcStringAddr + 4)
			: srcStringAddr + 4;
		uint32_t dstCapacity = dstString->capacity;
		uint64_t dstBufferSlot = dstStringAddr + 4;
		uint64_t dstData = (dstCapacity >= 16) ? (uint64_t)LOAD32((uint32_t)dstBufferSlot) : dstBufferSlot;
		memcpy_s_ZeroFillOnError(ctx, base, dstData, dstCapacity, srcData + startOffset, copyLength, ctx.r8.u64);
		uint32_t capacityAfterCopy = dstString->capacity;
		dstString->length = (uint32_t)copyLength;
		uint64_t terminatorBase = (capacityAfterCopy >= 16) ? (uint64_t)LOAD32((uint32_t)dstBufferSlot) : dstBufferSlot;
		STORE8((uint32_t)terminatorBase + (uint32_t)copyLength, uint8_t(0));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return dstStringAddr;
}
PROMOTED_ENTRY(1, sub_8218EA38, 0x8218EA38) { ctx.r3.u64 = BasicString_AssignSubstr(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint64_t BasicString_AssignPtrLen(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr, uint64_t sourceChars, uint64_t charCount, uint64_t r8Value) {
	if (!UseLiftedCode(2, 0x821A8F68)) { ctx.r3.u64 = basicStringAddr; ctx.r4.u64 = sourceChars; ctx.r5.u64 = charCount; ctx.r8.u64 = r8Value; __imp__sub_821A8F68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821A8F68);
	uint32_t stack = ctx.r1.u64;
	BasicString* basicString = GameObject<BasicString>(base, basicStringAddr);
	stack = PushStackFrame(base, stack, 128);

	// With a capacity of 16 or more the slot holds a pointer to heap characters; below that the
	// characters are stored in the slot itself.
	uint64_t bufferSlot = basicStringAddr + 4;
	uint32_t capacity = basicString->capacity;
	uint64_t data = (capacity >= 16) ? (uint64_t)LOAD32((uint32_t)bufferSlot) : bufferSlot;

	bool sourceIsInternal = false;
	if ((uint32_t)sourceChars >= (uint32_t)data) {
		uint32_t dataEnd = basicString->length + (uint32_t)data;
		sourceIsInternal = dataEnd > (uint32_t)sourceChars;
	}

	if (sourceIsInternal) {
		// The source lies inside this string's own characters: assign it as a substring of itself.
		ctx.r1.u64 = stack;
		ctx.r9.u64 = capacity;
		uint64_t assigned = BasicString_AssignSubstr(ctx, base, basicStringAddr, basicStringAddr, sourceChars - data, charCount, r8Value);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return assigned;
	}

	ctx.r1.u64 = stack;
	ctx.r9.u64 = capacity;
	uint32_t growResult = BasicString_Grow(ctx, base, basicStringAddr, charCount, 0, r8Value);
	if ((growResult & 0xFF) != 0) {
		uint32_t newCapacity = basicString->capacity;
		uint64_t newData = (newCapacity >= 16) ? (uint64_t)LOAD32((uint32_t)bufferSlot) : bufferSlot;
		memcpy_s_ZeroFillOnError(ctx, base, newData, newCapacity, sourceChars, charCount, ctx.r8.u64);
		uint32_t capacityAfterCopy = basicString->capacity;
		basicString->length = (uint32_t)charCount;
		uint32_t terminatorBase = (capacityAfterCopy >= 16) ? LOAD32((uint32_t)bufferSlot) : (uint32_t)bufferSlot;
		STORE8(terminatorBase + (uint32_t)charCount, uint8_t(0));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return basicStringAddr;
}
PROMOTED_ENTRY(2, sub_821A8F68, 0x821A8F68) { ctx.r3.u64 = BasicString_AssignPtrLen(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint32_t BasicString_Grow(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr, uint64_t requestedLength, uint32_t shrinkToInline, uint64_t r8Value) {
	if (!UseLiftedCode(2, 0x821A9090)) { ctx.r3.u64 = basicStringAddr; ctx.r4.u64 = requestedLength; ctx.r5.u64 = shrinkToInline; ctx.r8.u64 = r8Value; __imp__sub_821A9090(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821A9090);
	uint32_t stack = ctx.r1.u64;
	BasicString* basicString = GameObject<BasicString>(base, basicStringAddr);
	stack = PushStackFrame(base, stack, 128);

	// r4 handed back at the last return: requestedLength, or what the length-error handler left there
	uint64_t effectiveRequestedLength = requestedLength;
	if ((uint32_t)requestedLength > 0xFFFFFFFEu) {
		ctx.r1.u64 = stack;
		n_sub_82CD11D0(ctx, base, r8Value);
		effectiveRequestedLength = ctx.r4.u64;
		r8Value = ctx.r8.u64;
	}

	uint32_t capacity = basicString->capacity;
	if (capacity < (uint32_t)requestedLength) {
		ctx.r1.u64 = stack;
		BasicString_Reallocate(ctx, base, basicStringAddr, requestedLength, basicString->length, r8Value);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read the carry flag after the call: set when the requested length is zero
		ctx.xer.ca = (uint32_t)requestedLength == 0;
		return (uint32_t)requestedLength != 0;
	}

	// A request that fits the inline buffer switches the string to it, keeping at most requestedLength characters.
	if ((shrinkToInline & 0xFF) != 0 && (uint32_t)requestedLength < 16) {
		uint64_t keptLength = basicString->length;
		if ((uint32_t)requestedLength < (uint32_t)keptLength) {
			keptLength = requestedLength;
		}
		ctx.r1.u64 = stack;
		ctx.r10.u64 = shrinkToInline & 0xFF;
		BasicString_Assign(ctx, base, basicStringAddr, 1, keptLength, r8Value);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read the carry flag after the call: set when the requested length is zero
		ctx.xer.ca = (uint32_t)requestedLength == 0;
		return (uint32_t)requestedLength != 0;
	}

	if ((uint32_t)requestedLength == 0) {
		basicString->length = 0;
		uint32_t data = (capacity >= 16) ? LOAD32((uint32_t)basicStringAddr + 4) : (uint32_t)basicStringAddr + 4;
		STORE8(data, 0);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4, r8 and the carry flag (set when the requested length is zero) after the call
	ctx.r4.u64 = effectiveRequestedLength;
	ctx.r8.u64 = r8Value;
	ctx.xer.ca = (uint32_t)requestedLength == 0;
	return (uint32_t)requestedLength != 0;
}
PROMOTED_ENTRY(2, sub_821A9090, 0x821A9090) { ctx.r3.u64 = BasicString_Grow(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint32_t BasicString_Reallocate(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr, uint64_t requestedCapacity, uint64_t newLength, uint64_t r8Value) {
	if (!UseLiftedCode(2, 0x821A9170)) { ctx.r3.u64 = basicStringAddr; ctx.r4.u64 = requestedCapacity; ctx.r5.u64 = newLength; ctx.r8.u64 = r8Value; __imp__sub_821A9170(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821A9170);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	BasicString* basicString = GameObject<BasicString>(base, basicStringAddr);
	stack = PushStackFrame(base, stack, 128);

	// The request is rounded up so that capacity + 1 is a multiple of 16 (kept as is when that would
	// reach 0xFFFFFFFF). When the rounded request is below about 1.5x the old capacity, the new
	// capacity is the old one plus half of it, unless that sum would exceed 0xFFFFFFFE.
	uint64_t newCapacity = requestedCapacity | 15;
	if ((uint32_t)newCapacity > 0xFFFFFFFEu) {
		newCapacity = requestedCapacity;
	} else {
		uint32_t oldCapacity = basicString->capacity;
		uint32_t halfOldCapacity = oldCapacity >> 1;
		// the quotient stays in r8, which the allocation below receives
		r8Value = (uint32_t)newCapacity / 3;
		if ((uint32_t)r8Value < halfOldCapacity) {
			// carry from the overflow check; halfOldCapacity never exceeds 0x7FFFFFFF, so it is set
			flags.ca = 1;
			if (oldCapacity <= 0xFFFFFFFEu - halfOldCapacity) {
				newCapacity = (uint64_t)halfOldCapacity + oldCapacity;
			}
		}
	}

	uint64_t allocSize = newCapacity + 1;
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r5.u64 = newLength;
	ctx.xer.ca = flags.ca;
	uint64_t newData = Allocator_AllocateElements1(ctx, base, allocSize, r8Value);
	uint64_t result = newData;

	uint32_t bufferSlot = (uint32_t)basicStringAddr + 4;
	if ((uint32_t)newLength != 0) {
		uint64_t oldData = (basicString->capacity >= 16) ? (uint64_t)LOAD32(bufferSlot) : basicStringAddr + 4;
		result = memcpy_s_ZeroFillOnError(ctx, base, newData, allocSize, oldData, newLength, ctx.r8.u64);
	}
	if (basicString->capacity >= 16) {
		result = HandleTarget_Free(ctx, base, LOAD32(bufferSlot));
	}

	STORE8(bufferSlot, 0);
	STORE32(bufferSlot, (uint32_t)newData);
	basicString->capacity = (uint32_t)newCapacity;
	basicString->length = (uint32_t)newLength;
	uint32_t terminatorBase = ((uint32_t)newCapacity >= 16) ? (uint32_t)newData : bufferSlot;
	STORE8(terminatorBase + (uint32_t)newLength, 0);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(2, sub_821A9170, 0x821A9170) { ctx.r3.u64 = BasicString_Reallocate(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint32_t BasicString_Assign(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr, uint64_t releaseHeapBuffer, uint64_t newSize, uint64_t r8Value) {
	if (!UseLiftedCode(14, 0x822F1DB0)) { ctx.r3.u64 = basicStringAddr; ctx.r4.u64 = releaseHeapBuffer; ctx.r5.u64 = newSize; ctx.r8.u64 = r8Value; __imp__sub_822F1DB0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822F1DB0);
	uint32_t stack = ctx.r1.u64;
	BasicString* basicString = GameObject<BasicString>(base, basicStringAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t result = (uint32_t)basicStringAddr;
	// r4, r5 and r8 as callers see them after the call; the callees below may change them
	uint64_t r4Value = releaseHeapBuffer;
	uint64_t r5Value = newSize;

	// A string that still owns a heap buffer moves its first newSize characters into the inline
	// buffer and frees the heap buffer before switching to the short layout.
	if ((releaseHeapBuffer & 0xFF) != 0 && basicString->capacity >= 16) {
		uint32_t heapBuffer = LOAD32((uint32_t)basicStringAddr + 4);
		if ((uint32_t)newSize != 0) {
			ctx.r1.u64 = stack;
			memcpy_s_ZeroFillOnError(ctx, base, basicStringAddr + 4, 16, heapBuffer, newSize, r8Value);
			r4Value = ctx.r4.u64;
			r5Value = ctx.r5.u64;
			r8Value = ctx.r8.u64;
		}
		ctx.r1.u64 = stack;
		// state the callee may pass on
		result = HandleTarget_Free(ctx, base, heapBuffer);
		r4Value = ctx.r4.u64;
		r5Value = ctx.r5.u64;
		r8Value = ctx.r8.u64;
	}

	basicString->length = (uint32_t)newSize;
	basicString->capacity = 15u;
	STORE8((uint32_t)basicStringAddr + 4 + (uint32_t)newSize, 0);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4, r5, r8 and r9 after the call
	ctx.r4.u64 = r4Value;
	ctx.r5.u64 = r5Value;
	ctx.r8.u64 = r8Value;
	ctx.r9.u64 = 0;
	return result;
}
PROMOTED_ENTRY(14, sub_822F1DB0, 0x822F1DB0) { ctx.r3.u64 = BasicString_Assign(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint32_t BasicString_Erase(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr, uint64_t position, uint64_t count, uint64_t r8Value) {
	if (!UseLiftedCode(14, 0x822F1F60)) { ctx.r3.u64 = basicStringAddr; ctx.r4.u64 = position; ctx.r5.u64 = count; ctx.r8.u64 = r8Value; __imp__sub_822F1F60(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822F1F60);
	uint32_t stack = ctx.r1.u64;
	BasicString* basicString = GameObject<BasicString>(base, basicStringAddr);
	stack = PushStackFrame(base, stack, 128);

	if ((uint32_t)basicString->length < (uint32_t)position) {
		ctx.r1.u64 = stack;
		n_sub_82CD12C8(ctx, base, r8Value);
		r8Value = ctx.r8.u64;
	}

	uint64_t charsFromPosition = (uint64_t)basicString->length - position;
	uint64_t eraseCount = count;
	if ((uint32_t)charsFromPosition < (uint32_t)eraseCount) {
		eraseCount = charsFromPosition;
	}

	if ((uint32_t)eraseCount != 0) {
		uint32_t capacity = basicString->capacity;
		uint64_t bufferSlot = basicStringAddr + 4;
		uint64_t data = (capacity >= 16) ? (uint64_t)LOAD32((uint32_t)bufferSlot) : bufferSlot;
		uint64_t eraseStart = data + position;

		// Move the characters after the erased range down over it.
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r9.u64 = charsFromPosition;
		ctx.r10.u64 = data;
		memcpy_s(ctx, base, eraseStart, (uint64_t)capacity - position, eraseStart + eraseCount, charsFromPosition - eraseCount, capacity);
		r8Value = ctx.r8.u64;

		uint32_t newLength = basicString->length - (uint32_t)eraseCount;
		uint32_t capacityAfterMove = basicString->capacity;
		basicString->length = newLength;
		uint32_t terminatorBase = (capacityAfterMove >= 16) ? LOAD32((uint32_t)bufferSlot) : (uint32_t)bufferSlot;
		STORE8(terminatorBase + newLength, uint8_t(0));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r8 after the call
	ctx.r8.u64 = r8Value;
	return (uint32_t)basicStringAddr;
}
PROMOTED_ENTRY(14, sub_822F1F60, 0x822F1F60) { ctx.r3.u64 = BasicString_Erase(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint64_t BasicString_ConstructFromCStr(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr, uint64_t sourceText, uint64_t r8Value) {
	if (!UseLiftedCode(14, 0x822F2020)) { ctx.r3.u64 = basicStringAddr; ctx.r4.u64 = sourceText; ctx.r8.u64 = r8Value; __imp__sub_822F2020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822F2020);
	uint32_t stack = ctx.r1.u64;
	BasicString* basicString = GameObject<BasicString>(base, basicStringAddr);
	stack = PushStackFrame(base, stack, 96);
	basicString->length = 0;
	basicString->capacity = 15;
	STORE8((uint32_t)basicStringAddr + 4, 0);

	uint32_t charAddr = (uint32_t)sourceText;
	uint8_t character;
	do {
		character = LOAD8(charAddr);
		charAddr++;
	} while (character != 0);
	uint32_t textLength = charAddr - (uint32_t)sourceText - 1;

	ctx.r1.u64 = stack;
	// state the callee may pass on: the initial capacity and the terminating character
	BasicString_AssignPtrLen(ctx, base, basicStringAddr, sourceText, textLength, r8Value);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return basicStringAddr;
}
PROMOTED_ENTRY(14, sub_822F2020, 0x822F2020) { ctx.r3.u64 = BasicString_ConstructFromCStr(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint32_t BasicString_Destructor(CpuState& ctx, uint8_t* base, uint32_t basicStringAddr) {
	if (!UseLiftedCode(45, 0x826C2E98)) { ctx.r3.u64 = basicStringAddr; __imp__sub_826C2E98(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826C2E98);
	uint32_t stack = ctx.r1.u64;
	BasicString* basicString = GameObject<BasicString>(base, basicStringAddr);
	stack = PushStackFrame(base, stack, 96);
	basicString->vtable = 0x820CCE94u;
	uint32_t handle1 = basicString->m_8;
	ctx.r1.u64 = stack;
	HandleTarget_Free(ctx, base, handle1);
	uint32_t handle2 = basicString->m_10;
	HandleTarget_Free(ctx, base, handle2);
	uint32_t handle3 = basicString->length;
	uint32_t lastResult = HandleTarget_Free(ctx, base, handle3);
	basicString->vtable = 0x820EFB9Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return lastResult;
}
PROMOTED_ENTRY(45, sub_826C2E98, 0x826C2E98) { ctx.r3.u64 = BasicString_Destructor(ctx, base, ctx.r3.u32); }

uint64_t n_sub_826C2EF0(CpuState& ctx, uint8_t* base, uint64_t basicString) {
	if (!UseLiftedCode(45, 0x826C2EF0)) { ctx.r3.u64 = basicString; __imp__sub_826C2EF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C2EF0);
	return LOAD8((uint32_t)basicString + 12);
}
PROMOTED_ENTRY(45, sub_826C2EF0, 0x826C2EF0) { ctx.r3.u64 = n_sub_826C2EF0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_826C2EF8(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr) {
	if (!UseLiftedCode(45, 0x826C2EF8)) { ctx.r3.u64 = basicStringAddr; __imp__sub_826C2EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C2EF8);
	return LOAD8((uint32_t)basicStringAddr + 13);
}
PROMOTED_ENTRY(45, sub_826C2EF8, 0x826C2EF8) { ctx.r3.u64 = n_sub_826C2EF8(ctx, base, ctx.r3.u64); }

uint64_t BasicString_ConstructFromCStr8(CpuState& ctx, uint8_t* base, uint64_t resultString, uint64_t source, uint64_t arg3) {
	if (!UseLiftedCode(45, 0x826C2F00)) { ctx.r3.u64 = resultString; ctx.r4.u64 = source; ctx.r8.u64 = arg3; __imp__sub_826C2F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C2F00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t sourceCStr = LOAD32((uint32_t)source + 8);
	ctx.r1.u64 = stack;
	BasicString_ConstructFromCStr(ctx, base, resultString, sourceCStr, arg3);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return resultString;
}
PROMOTED_ENTRY(45, sub_826C2F00, 0x826C2F00) { ctx.r3.u64 = BasicString_ConstructFromCStr8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t BasicString_ConstructFromCStr16(CpuState& ctx, uint8_t* base, uint64_t resultString, uint64_t source, uint64_t arg3) {
	if (!UseLiftedCode(45, 0x826C2F38)) { ctx.r3.u64 = resultString; ctx.r4.u64 = source; ctx.r8.u64 = arg3; __imp__sub_826C2F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C2F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t sourceCStr = LOAD32((uint32_t)source + 16);
	ctx.r1.u64 = stack;
	BasicString_ConstructFromCStr(ctx, base, resultString, sourceCStr, arg3);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return resultString;
}
PROMOTED_ENTRY(45, sub_826C2F38, 0x826C2F38) { ctx.r3.u64 = BasicString_ConstructFromCStr16(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t BasicString_ConstructFromCStr20(CpuState& ctx, uint8_t* base, uint64_t resultString, uint64_t source, uint64_t arg3) {
	if (!UseLiftedCode(45, 0x826C2F70)) { ctx.r3.u64 = resultString; ctx.r4.u64 = source; ctx.r8.u64 = arg3; __imp__sub_826C2F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C2F70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t sourceCStr = LOAD32((uint32_t)source + 20);
	ctx.r1.u64 = stack;
	BasicString_ConstructFromCStr(ctx, base, resultString, sourceCStr, arg3);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return resultString;
}
PROMOTED_ENTRY(45, sub_826C2F70, 0x826C2F70) { ctx.r3.u64 = BasicString_ConstructFromCStr20(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

// Destroys the object (sub_826C2E98) and, when bit 0 of deleteFlags is set, also frees the object's own memory.
uint64_t BasicString_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t basicStringAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(45, 0x826C2FA8)) { ctx.r3.u64 = basicStringAddr; ctx.r4.u64 = deleteFlags; __imp__sub_826C2FA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C2FA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	BasicString_Destructor(ctx, base, basicStringAddr);
	if (deleteFlags & 0x1) {
		HandleTarget_Free(ctx, base, basicStringAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return basicStringAddr;
}
PROMOTED_ENTRY(45, sub_826C2FA8, 0x826C2FA8) { ctx.r3.u64 = BasicString_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
