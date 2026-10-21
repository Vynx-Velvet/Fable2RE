// CBinaryDataStream (vtable 0x8200E3C0): methods of the class as readable C++.
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

// sub_82C79530  [16 bytes]
void CBinaryDataStream_Destructor(CpuState& ctx, uint8_t* base, uint32_t binaryDataStreamAddr) {
	if (!UseLiftedCode(92, 0x82C79530)) { ctx.r3.u64 = binaryDataStreamAddr; __imp__sub_82C79530(ctx, base); return; }
	LiftedFrame frame(0x82C79530);
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	binaryDataStream->vtable = 0x8200E3C0u;
	return;
}
PROMOTED_ENTRY(92, sub_82C79530, 0x82C79530) { CBinaryDataStream_Destructor(ctx, base, ctx.r3.u32); }

uint64_t CBinaryDataStream_Destructor_82C79540(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t flags) {
	if (!UseLiftedCode(92, 0x82C79540)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = flags; __imp__sub_82C79540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79540);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 96);
	binaryDataStream->vtable = 0x8200E3C0u;
	// r4 = flags: handed to the free call, and callers read r4 after the return
	// (flags, or what the free call left there)
	ctx.r4.u64 = flags;
	if ((flags & 1) != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_FreeThunk(ctx, base, binaryDataStreamAddr);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return binaryDataStreamAddr;
}
PROMOTED_ENTRY(92, sub_82C79540, 0x82C79540) { ctx.r3.u64 = CBinaryDataStream_Destructor_82C79540(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBinaryDataStream_Release(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr) {
	if (!UseLiftedCode(92, 0x82C79588)) { ctx.r3.u64 = binaryDataStreamAddr; __imp__sub_82C79588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79588);
	uint32_t stack = ctx.r1.u64;
	// MSR bits taken from r13 while the reserved update runs; the MSR read before it is restored after.
	uint32_t updateMsr = ctx.r13.u64;
	PPCRegister callTarget{};
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 96);

	// Atomic decrement of the reference count at +4, retried until the conditional store succeeds.
	uint32_t refCountAddr = (uint32_t)binaryDataStreamAddr + 4;
	uint64_t savedMsr = 0;
	uint64_t newRefCount = 0;
	bool stored;
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		savedMsr = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = updateMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
		newRefCount = (uint64_t)__builtin_bswap32(ctx.reserved.u32) - 1;
		stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = (uint32_t)savedMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!stored);

	// Last reference gone: the virtual destructor slot (+156, sub_82C79540 in this class) with flags 1.
	if ((int32_t)newRefCount == 0 && (uint32_t)binaryDataStreamAddr != 0) {
		uint32_t destroyFn = LOAD32((uint32_t)binaryDataStream->vtable + 156);
		callTarget.u64 = (uint64_t)destroyFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = binaryDataStreamAddr;
		ctx.r4.u64 = 1;
		ctx.r9.u64 = savedMsr;
		ctx.r10.u64 = destroyFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return newRefCount;
}
PROMOTED_ENTRY(92, sub_82C79588, 0x82C79588) { ctx.r3.u64 = CBinaryDataStream_Release(ctx, base, ctx.r3.u64); }

uint64_t CBinaryDataStream_QueryInterface(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t interfaceId, uint64_t outInterface) {
	if (!UseLiftedCode(92, 0x82C795F8)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = interfaceId; ctx.r5.u64 = outInterface; __imp__sub_82C795F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C795F8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);

	stack = PushStackFrame(base, stack, 96);

	STORE32((uint32_t)outInterface, 0u);

	// Byte-wise compare of the 16-byte requested id with a known GUID. The last GUID byte read
	// is kept: the AddRef call below receives it in r7.
	const uint32_t iidAddress = (uint32_t)interfaceId;
	uint8_t lastGuidByte = 0;
	auto iidMatches = [&](uint32_t guidAddress) -> bool {
		for (uint32_t offset = 0; offset < 16; ++offset) {
			uint8_t iidByte = LOAD8(iidAddress + offset);
			lastGuidByte = LOAD8(guidAddress + offset);
			if (iidByte != lastGuidByte) return false;
		}
		return true;
	};

	// The stream exposes any of three interface GUIDs.
	const bool interfaceSupported =
		iidMatches(0x820A7E00u) ||
		iidMatches(0x8200E470u) ||
		iidMatches(0x8200E460u);

	if (interfaceSupported) {
		STORE32((uint32_t)outInterface, (uint32_t)binaryDataStreamAddr);
		if ((uint32_t)binaryDataStreamAddr != 0) {
			uint32_t addRefFn = LOAD32((uint32_t)binaryDataStream->vtable + 4);
			callTarget.u64 = addRefFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = binaryDataStreamAddr;
			ctx.r4.u64 = interfaceId;
			ctx.r5.u64 = outInterface;
			// state the callee may pass on: what the matching compare left in r7-r9
			ctx.r7.u64 = lastGuidByte;
			ctx.r8.u64 = interfaceId + 16;
			ctx.r9.u64 = 0;
			ctx.r10.u64 = addRefFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return 0;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = interfaceId;  // callers read r4 after the call
	return 0xFFFFFFFF80004002ull;  // E_NOINTERFACE
}
PROMOTED_ENTRY(92, sub_82C795F8, 0x82C795F8) { ctx.r3.u64 = CBinaryDataStream_QueryInterface(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CBinaryDataStream_WriteString(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t text) {
	if (!UseLiftedCode(92, 0x82C79708)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = text; __imp__sub_82C79708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79708);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 112);

	// strlen(text)
	uint64_t textCursor = text;
	uint8_t ch;
	do {
		ch = LOAD8((uint32_t)textCursor);
		textCursor += 1;
	} while (ch != 0);

	uint64_t textLength = (textCursor - text) - 1;
	uint32_t textLength32 = (uint32_t)textLength;

	// The length goes out first through the WriteInt32 slot (+88), then the characters.
	uint32_t vtable = binaryDataStream->vtable;
	uint32_t writeInt32Fn = LOAD32(vtable + 88);
	STORE32(stack + 80, textLength32);
	callTarget.u64 = (uint64_t)writeInt32Fn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = (uint64_t)textLength32;
	ctx.r8.u64 = (uint64_t)writeInt32Fn;
	ctx.r9.u64 = textLength;
	ctx.r10.u64 = (uint64_t)vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	int32_t lengthResult = (int32_t)ctx.r3.u32;

	uint64_t result;
	if (lengthResult >= 0) {
		uint32_t writeFn = LOAD32((uint32_t)binaryDataStream->vtable + 148);
		callTarget.u64 = (uint64_t)writeFn;
		ctx.r3.u64 = binaryDataStreamAddr;
		ctx.r4.u64 = text;
		ctx.r5.u64 = (uint64_t)(stack + 80);
		ctx.r6.u64 = 0;
		ctx.r10.u64 = (uint64_t)writeFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ((int32_t)ctx.r3.u32 < 0) ? 0xFFFFFFFF80004005ULL : 0;
	} else {
		result = 0xFFFFFFFF80004005ULL;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(92, sub_82C79708, 0x82C79708) { ctx.r3.u64 = CBinaryDataStream_WriteString(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBinaryDataStream_ReadString(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outString) {
	if (!UseLiftedCode(92, 0x82C797B8)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outString; __imp__sub_82C797B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C797B8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);

	stack = PushStackFrame(base, stack, 128);
	uint32_t lengthAddr = stack + 80;
	STORE32(lengthAddr, 0);

	// virtual: read the string length into the local, returning an HRESULT
	uint32_t readLengthFunc = LOAD32(binaryDataStream->vtable + 96);
	callTarget.u64 = readLengthFunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = lengthAddr;
	ctx.r10.u64 = readLengthFunc;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t result = ctx.r3.u32;
	if ((int32_t)result < 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005;
	}

	// 64-bit sum: a length of 0xFFFFFFFF asks for 0x100000000 bytes, not 0
	uint64_t bufferSize = (uint64_t)LOAD32(lengthAddr) + 1;
	uint64_t stringBuffer = operator_new(ctx, base, bufferSize);

	// virtual: copy the string into the freshly allocated buffer
	uint32_t vtable = binaryDataStream->vtable;
	uint32_t readStringFunc = LOAD32(vtable + 152);
	callTarget.u64 = readStringFunc;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = stringBuffer;
	ctx.r5.u64 = lengthAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = readStringFunc;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	result = ctx.r3.u32;
	if ((int32_t)result < 0) {
		HandleTarget_FreeThunk(ctx, base, stringBuffer);
		STORE32(outString, 0);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005;
	}

	STORE8((uint32_t)stringBuffer + LOAD32(lengthAddr), 0);
	STORE32(outString, (uint32_t)stringBuffer);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C797B8, 0x82C797B8) { ctx.r3.u64 = CBinaryDataStream_ReadString(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_WriteLengthPrefixedString(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t stringAddr) {
	if (!UseLiftedCode(92, 0x82C79870)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = stringAddr; __imp__sub_82C79870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79870);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	// The 32-bit length stored just before the string goes out through the WriteInt32 slot (+88),
	// then the string data with a pointer to that length.
	uint32_t lengthAddr = stack + 80;
	uint32_t storedLength = String_GetLengthPrefix(ctx, base, stringAddr);
	STORE32(lengthAddr, storedLength);
	WString_GetByteSize(ctx, base, stringAddr);

	uint32_t writeInt32Fn = LOAD32(uint32_t(binaryDataStream->vtable) + 88);
	callTarget.u64 = (uint64_t)writeInt32Fn;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = storedLength;
	ctx.r10.u64 = writeInt32Fn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint64_t hr;
	if ((int32_t)ctx.r3.u32 >= 0) {
		uint32_t writeFn = LOAD32(uint32_t(binaryDataStream->vtable) + 148);
		callTarget.u64 = (uint64_t)writeFn;
		ctx.r3.u64 = binaryDataStreamAddr;
		ctx.r4.u64 = stringAddr;
		ctx.r5.u64 = lengthAddr;
		ctx.r6.u64 = 0;
		ctx.r10.u64 = writeFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		// E_FAIL on failure, S_OK otherwise
		hr = ((int32_t)ctx.r3.u32 < 0) ? 0xFFFFFFFF80004005ull : 0;
	} else {
		hr = 0xFFFFFFFF80004005ull;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return hr;
}
PROMOTED_ENTRY(92, sub_82C79870, 0x82C79870) { ctx.r3.u64 = CBinaryDataStream_WriteLengthPrefixedString(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBinaryDataStream_WriteWideString(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t sourceString, uint64_t arg3) {
	if (!UseLiftedCode(92, 0x82C79910)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = sourceString; ctx.r8.u64 = arg3; __imp__sub_82C79910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79910);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	// The string goes through WString_ToNarrowString into a temporary buffer (length + 1 bytes), which is
	// written through the WriteString slot (+48) and freed; the result is the WriteString result.
	uint64_t sourceLength = WString_GetByteSize(ctx, base, sourceString);
	uint64_t bufferSize = sourceLength + 1;
	// state the callee may pass on; WString_ToNarrowString then gets r8 as operator_new leaves it
	ctx.r4.u64 = sourceString;
	ctx.r8.u64 = arg3;
	uint64_t buffer = operator_new(ctx, base, bufferSize);
	WString_ToNarrowString(ctx, base, buffer, sourceString, bufferSize, ctx.r8.u64);

	uint32_t writeStringFn = LOAD32(uint32_t(binaryDataStream->vtable) + 48);
	callTarget.u64 = (uint64_t)writeStringFn;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = buffer;
	ctx.r10.u64 = writeStringFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;

	HandleTarget_FreeThunk(ctx, base, buffer);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(92, sub_82C79910, 0x82C79910) { ctx.r3.u64 = CBinaryDataStream_WriteWideString(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

// Reads a narrow string through the virtual ReadString and stores a length-prefixed wide copy of it.
uint64_t CBinaryDataStream_ReadStringAsWideString(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outWideString) {
	if (!UseLiftedCode(92, 0x82C79978)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outWideString; __imp__sub_82C79978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79978);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 144);

	// Stack slot the virtual ReadString (vtable +52) fills with a newly allocated narrow string.
	uint32_t narrowStringSlot = stack + 80;
	STORE32(narrowStringSlot, 0);

	uint32_t readStringFunc = LOAD32(binaryDataStream->vtable + 52);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = narrowStringSlot;
	ctx.r10.u64 = readStringFunc;
	REX_CALL_INDIRECT_FUNC(readStringFunc);
	uint64_t result = ctx.r3.u64;

	if ((int32_t)result >= 0) {
		uint32_t narrowString = LOAD32(narrowStringSlot);

		// strlen: scan to the terminating NUL.
		uint32_t scan = narrowString;
		uint32_t ch;
		do {
			ch = LOAD8(scan);
			scan = scan + 1;
		} while (ch != 0);
		uint32_t charCount = (scan - narrowString) - 1;

		// Wide buffer of charCount + 1 characters; a count too large to double requests an all-ones size.
		uint32_t elementCount = charCount + 1;
		uint64_t allocSize = elementCount << 1;
		if (elementCount > 0x7FFFFFFFu) {
			allocSize = ~0ull;
		}
		ctx.r8.u64 = 0x7FFFFFFF; // state the callee may pass on
		uint64_t wideBuffer = operator_new(ctx, base, allocSize);

		// mbstowcs wrapper: widen the narrow string into the buffer, then NUL-terminate it.
		// The original passes the count as a 64-bit charCount + 1 (no 32-bit wrap).
		NarrowString_ToWString(ctx, base, wideBuffer, LOAD32(narrowStringSlot), (uint64_t)charCount + 1, ctx.r8.u64);
		STORE16((charCount << 1) + (uint32_t)wideBuffer, 0);

		uint32_t duplicate = WString_DuplicateWithLengthPrefix(ctx, base, wideBuffer);
		STORE32(outWideString, duplicate);

		HandleTarget_FreeThunk(ctx, base, wideBuffer);
		HandleTarget_FreeThunk(ctx, base, LOAD32(narrowStringSlot));
		result = 0;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(92, sub_82C79978, 0x82C79978) { ctx.r3.u64 = CBinaryDataStream_ReadStringAsWideString(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_WriteInt64(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t value) {
	if (!UseLiftedCode(92, 0x82C79A30)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = value; __imp__sub_82C79A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79A30);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 96);

	// Stage the 64-bit value and its byte count on the game stack for the virtual write (vtable +148).
	uint32_t byteCount = 8;
	uint32_t valueAddr = stack + 120;
	uint32_t byteCountAddr = stack + 80;
	STORE64(valueAddr, value);
	STORE32(byteCountAddr, byteCount);

	uint32_t writeFunc = LOAD32(binaryDataStream->vtable + 148);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = valueAddr;
	ctx.r5.u64 = byteCountAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = writeFunc;
	ctx.r10.u64 = byteCount;
	REX_CALL_INDIRECT_FUNC(writeFunc);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(92, sub_82C79A30, 0x82C79A30) { ctx.r3.u64 = CBinaryDataStream_WriteInt64(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBinaryDataStream_WriteInt32(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t value) {
	if (!UseLiftedCode(92, 0x82C79A78)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = value; __imp__sub_82C79A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79A78);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);

	stack = PushStackFrame(base, stack, 96);

	// Stage the 32-bit value and its byte count on the game stack for the virtual write (vtable +148).
	uint32_t byteCount = 4;
	uint32_t valueAddr = stack + 124;
	uint32_t byteCountAddr = stack + 80;
	uint32_t writeFunc = LOAD32(binaryDataStream->vtable + 148);

	STORE32(valueAddr, value);
	STORE32(byteCountAddr, byteCount);

	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = valueAddr;
	ctx.r5.u64 = byteCountAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = writeFunc;
	ctx.r10.u64 = byteCount;
	REX_CALL_INDIRECT_FUNC(writeFunc);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(92, sub_82C79A78, 0x82C79A78) { ctx.r3.u64 = CBinaryDataStream_WriteInt32(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_WriteInt16(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t value) {
	if (!UseLiftedCode(92, 0x82C79AC0)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = value; __imp__sub_82C79AC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79AC0);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 96);

	// Stage the 16-bit value and its byte count on the game stack for the virtual write (vtable +148).
	uint32_t vtable = binaryDataStream->vtable;
	uint32_t byteCount = 2;
	uint32_t valueAddr = stack + 126;
	uint32_t byteCountAddr = stack + 80;
	STORE16(valueAddr, (uint16_t)value);
	STORE32(byteCountAddr, byteCount);

	uint32_t writeFunc = LOAD32(vtable + 148);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = valueAddr;
	ctx.r5.u64 = byteCountAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = writeFunc;
	ctx.r10.u64 = byteCount;
	REX_CALL_INDIRECT_FUNC(writeFunc);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(92, sub_82C79AC0, 0x82C79AC0) { ctx.r3.u64 = CBinaryDataStream_WriteInt16(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_WriteByte(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t value) {
	if (!UseLiftedCode(92, 0x82C79B08)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = value; __imp__sub_82C79B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79B08);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t vtable = binaryDataStream->vtable;
	STORE8(stack + 127, (uint8_t)value);
	STORE32(stack + 80, 1u);
	uint32_t writeFunc = LOAD32(vtable + 148);
	PPCRegister callTarget{};
	callTarget.u64 = writeFunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = stack + 127;
	ctx.r5.u64 = stack + 80;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = writeFunc;
	ctx.r10.u64 = 1;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(92, sub_82C79B08, 0x82C79B08) { ctx.r3.u64 = CBinaryDataStream_WriteByte(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_ReadByte(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr) {
	if (!UseLiftedCode(92, 0x82C79B50)) { ctx.r3.u64 = binaryDataStreamAddr; __imp__sub_82C79B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79B50);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t byteCount = 1;
	uint32_t byteCountAddr = stack + 80;
	STORE32(byteCountAddr, byteCount);
	uint32_t readFunc = LOAD32(binaryDataStream->vtable + 152);
	// Virtual read (vtable +152) of one byte; the destination is the caller's r4, which passes through untouched.
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r5.u64 = byteCountAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = readFunc;
	ctx.r10.u64 = byteCount;
	REX_CALL_INDIRECT_FUNC(readFunc);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(92, sub_82C79B50, 0x82C79B50) { ctx.r3.u64 = CBinaryDataStream_ReadByte(ctx, base, ctx.r3.u64); }

// sub_82C79B90  [100 bytes]
uint64_t CBinaryDataStream_SwapInt64(CpuState& ctx, uint8_t* base, uint32_t binaryDataStreamAddr, uint64_t inputValue) {
	if (!UseLiftedCode(92, 0x82C79B90)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = inputValue; __imp__sub_82C79B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79B90);
	uint32_t stack = ctx.r1.u32;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	uint32_t nativeByteOrder = binaryDataStream->m_nativeByteOrder;
	uint32_t streamByteOrder = binaryDataStream->m_streamByteOrder;
	STORE64(stack + 24, inputValue);
	if ((int32_t)nativeByteOrder == (int32_t)streamByteOrder) {
		return inputValue;
	}
	// Stream byte order differs from host: store the value byte-reversed.
	STORE8(stack - 16, uint8_t(inputValue >> 0));
	STORE8(stack - 15, uint8_t(inputValue >> 8));
	STORE8(stack - 14, uint8_t(inputValue >> 16));
	STORE8(stack - 13, uint8_t(inputValue >> 24));
	STORE8(stack - 12, uint8_t(inputValue >> 32));
	STORE8(stack - 11, uint8_t(inputValue >> 40));
	STORE8(stack - 10, uint8_t(inputValue >> 48));
	STORE8(stack - 9, uint8_t(inputValue >> 56));
	return LOAD64(stack - 16);
}
PROMOTED_ENTRY(92, sub_82C79B90, 0x82C79B90) { ctx.r3.u64 = CBinaryDataStream_SwapInt64(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CBinaryDataStream_ReadWideString(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outString) {
	if (!UseLiftedCode(93, 0x82C79C68)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outString; __imp__sub_82C79C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79C68);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 144);
	uint32_t byteCountSlot = stack + 84;
	STORE32(outString, 0);

	// Virtual ReadInt32 (vtable +96): the length in bytes of the string that follows.
	callTarget.u64 = LOAD32(uint32_t(binaryDataStream->vtable) + 96);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = byteCountSlot;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t status = ctx.r3.u32;

	if ((int32_t)status >= 0) {
		uint32_t charCount = LOAD32(byteCountSlot) >> 1;
		uint32_t allocChars = charCount + 1;
		uint64_t allocSize = allocChars << 1;
		if (allocChars > 0x7FFFFFFFu) {
			allocSize = ~0ull;
		}
		uint64_t wideBuffer = operator_new(ctx, base, allocSize);

		// Virtual read (vtable +152) of the string bytes into the new buffer.
		callTarget.u64 = LOAD32(uint32_t(binaryDataStream->vtable) + 152);
		ctx.r3.u64 = binaryDataStreamAddr;
		ctx.r4.u64 = wideBuffer;
		ctx.r5.u64 = byteCountSlot;
		ctx.r6.u64 = 0;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t readStatus = ctx.r3.u32;
		// r8 and the carry as the original code hands them to the duplicate call below.
		uint64_t r8Value = ctx.r8.u64;
		PPCXERRegister xer = ctx.xer;

		if ((int32_t)readStatus >= 0) {
			if (binaryDataStream->m_nativeByteOrder != binaryDataStream->m_streamByteOrder) {
				// Byte-swap each character in place through the scratch bytes at stack + 80..83.
				uint32_t charAddr = (uint32_t)wideBuffer;
				for (uint32_t remaining = charCount; remaining != 0; remaining--) {
					uint32_t charValue = LOAD16(charAddr);
					uint32_t nativeByteOrder = binaryDataStream->m_nativeByteOrder;
					uint32_t streamByteOrder = binaryDataStream->m_streamByteOrder;
					STORE16(stack + 80, (uint16_t)charValue);
					r8Value = nativeByteOrder;
					if ((int32_t)nativeByteOrder != (int32_t)streamByteOrder) {
						uint32_t highByte = LOAD8(stack + 80);
						STORE8(stack + 82, LOAD8(stack + 81));
						STORE8(stack + 83, (uint8_t)highByte);
						charValue = LOAD16(stack + 82);
						r8Value = highByte;
					}
					STORE16(charAddr, (uint16_t)charValue);
					xer.ca = remaining > 0;
					charAddr += 2;
				}
			}
			STORE16(uint32_t(charCount << 1) + (uint32_t)wideBuffer, 0);
			// state the callee may read
			ctx.r8.u64 = r8Value;
			ctx.xer.ca = xer.ca;
			uint32_t duplicate = WString_DuplicateWithLengthPrefix(ctx, base, wideBuffer);
			STORE32(outString, duplicate);
			HandleTarget_FreeThunk(ctx, base, wideBuffer);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return 0;
		}
		HandleTarget_FreeThunk(ctx, base, wideBuffer);
	}
	STORE32(outString, 0);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// E_FAIL, sign-extended to 64 bits as the original leaves it in r3.
	return 0xFFFFFFFF80004005ull;
}
PROMOTED_ENTRY(93, sub_82C79C68, 0x82C79C68) { ctx.r3.u64 = CBinaryDataStream_ReadWideString(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_ReadInt64(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C79D98)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outValue; __imp__sub_82C79D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79D98);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t byteCountAddr = stack + 80;
	uint32_t valueBuffer = stack + 88;
	STORE32(byteCountAddr, 8);

	uint32_t readFunc = LOAD32(uint32_t(binaryDataStream->vtable) + 152);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = valueBuffer;
	ctx.r5.u64 = byteCountAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = readFunc;
	ctx.r10.u64 = 8;
	REX_CALL_INDIRECT_FUNC(readFunc);

	uint64_t result;
	if ((int32_t)ctx.r3.u32 < 0) {
		result = 0xFFFFFFFF80004005ull;
	} else {
		uint64_t rawValue = LOAD64(valueBuffer);
		STORE64(outValue, CBinaryDataStream_SwapInt64(ctx, base, binaryDataStreamAddr, rawValue));
		result = 0;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C79D98, 0x82C79D98) { ctx.r3.u64 = CBinaryDataStream_ReadInt64(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_ReadInt32(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C79E18)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outValue; __imp__sub_82C79E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79E18);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t valueBuffer = stack + 80;
	uint32_t byteCountAddr = stack + 84;
	STORE32(byteCountAddr, 4);

	uint32_t readFunc = LOAD32(uint32_t(binaryDataStream->vtable) + 152);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = valueBuffer;
	ctx.r5.u64 = byteCountAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = readFunc;
	ctx.r10.u64 = 4;
	REX_CALL_INDIRECT_FUNC(readFunc);

	uint64_t result;
	if ((int32_t)ctx.r3.u32 < 0) {
		result = 0xFFFFFFFF80004005ull;
	} else {
		uint32_t value = LOAD32(valueBuffer);
		if (binaryDataStream->m_nativeByteOrder != binaryDataStream->m_streamByteOrder) {
			uint8_t b0 = LOAD8(valueBuffer);
			uint8_t b1 = LOAD8(valueBuffer + 1);
			uint8_t b2 = LOAD8(valueBuffer + 2);
			uint8_t b3 = LOAD8(valueBuffer + 3);
			STORE8(valueBuffer, b3);
			STORE8(valueBuffer + 1, b2);
			STORE8(valueBuffer + 2, b1);
			STORE8(valueBuffer + 3, b0);
			value = LOAD32(valueBuffer);
		}
		STORE32(outValue, value);
		result = 0;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C79E18, 0x82C79E18) { ctx.r3.u64 = CBinaryDataStream_ReadInt32(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CBinaryDataStream_ReadInt16(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C79EC8)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outValue; __imp__sub_82C79EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79EC8);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t valueBuffer = stack + 80;
	uint32_t byteCountAddr = stack + 84;
	STORE32(byteCountAddr, 2);

	uint32_t readFunc = LOAD32(uint32_t(binaryDataStream->vtable) + 152);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = valueBuffer;
	ctx.r5.u64 = byteCountAddr;
	ctx.r6.u64 = 0;
	ctx.r9.u64 = readFunc;
	ctx.r10.u64 = 2;
	REX_CALL_INDIRECT_FUNC(readFunc);

	uint64_t result;
	if ((int32_t)ctx.r3.u32 < 0) {
		result = 0xFFFFFFFF80004005ull;
	} else {
		uint16_t value = LOAD16(valueBuffer);
		if (binaryDataStream->m_nativeByteOrder != binaryDataStream->m_streamByteOrder) {
			uint8_t firstByte = LOAD8(valueBuffer);
			STORE8(valueBuffer, LOAD8(valueBuffer + 1));
			STORE8(valueBuffer + 1, firstByte);
			value = LOAD16(valueBuffer);
		}
		STORE16(outValue, value);
		result = 0;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C79EC8, 0x82C79EC8) { ctx.r3.u64 = CBinaryDataStream_ReadInt16(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// sub_82C7C4C0  [692 bytes]
uint64_t CBinaryDataStream_WriteStringPairMap(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t arg2) {
	constexpr int32_t g_8200E480 = int32_t(0x8200E480);
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_820CCFBC = int32_t(0x820CCFBC);
	if (!UseLiftedCode(93, 0x82C7C4C0)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = arg2; __imp__sub_82C7C4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7C4C0);
	uint32_t stack = ctx.r1.u64;

	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 384);

	// game-stack objects: the key table at stack+220, the string builder at stack+144
	const uint64_t tableVtable = g_8200E480;                              // 0xFFFFFFFF8200E480
	STORE32(stack + 144, 0x820CCE8Cu);
	STORE32(stack + 220, (uint32_t)tableVtable);
	ctx.r1.u64 = stack;
	WStringStream_ConstructWithBuffer(ctx, base, stack + 220, stack + 148, 0, tableVtable);

	const int32_t builderBase = g_82010000;                              // 0xFFFFFFFF82010000
	const uint64_t builderVtable = (uint64_t)(int64_t)builderBase - 7036;  // 0xFFFFFFFF8200E484
	STORE32(LOAD32(LOAD32(stack + 144) + 4) + stack + 144, (uint32_t)builderVtable);
	ctx.r5.u64 = builderVtable;
	ctx.r6.s64 = builderBase;
	WStringStream_SetModeFlags(ctx, base, stack + 148, 2, ctx.r8.u64);

	uint32_t sourceVtable = LOAD32((uint32_t)arg2);
	uint32_t sourceMethod = LOAD32(sourceVtable + 24);
	callTarget.u64 = sourceMethod;
	ctx.r3.u64 = arg2;
	ctx.r4.u64 = stack + 80;
	ctx.r8.u64 = sourceMethod;
	ctx.r9.u64 = sourceVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	auto failNow = [&]() -> uint64_t {
		WStringStreamBase_Destructor(ctx, base, stack + 220);
		const uint64_t cleanupVtable = g_820CCFBC;                       // 0xFFFFFFFF820CCFBC
		STORE32(stack + 220, (uint32_t)cleanupVtable);
		ctx.r10.u64 = cleanupVtable;
		RefCountedObject_Release(ctx, base, stack + 220);
		stack = PopStackFrame(stack, 384);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	};
	auto failTidyBuilder = [&]() -> uint64_t {
		WStringStream_Destructor(ctx, base, stack + 144);
		stack = PopStackFrame(stack, 384);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	};

	if ((int32_t)ctx.r3.u32 < 0) return failNow();

	uint32_t rowSource = LOAD32(stack + 80);
	uint32_t countMethod = LOAD32(LOAD32(rowSource) + 20);
	callTarget.u64 = countMethod;
	ctx.r3.u64 = rowSource;
	ctx.r4.u64 = stack + 84;
	ctx.r10.u64 = countMethod;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	if ((int32_t)ctx.r3.u32 < 0) return failTidyBuilder();

	uint64_t bucket = WStringStream_WriteInteger(ctx, base, stack + 144, LOAD32(stack + 84), ctx.r8.u64);
	WStringStream_WriteChar(ctx, base, bucket, 58, ctx.r8.u64);

	uint32_t rowSource2 = LOAD32(stack + 80);
	uint32_t resetMethod = LOAD32(LOAD32(rowSource2) + 12);
	callTarget.u64 = resetMethod;
	ctx.r3.u64 = rowSource2;
	ctx.r10.u64 = resetMethod;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t rowCount = LOAD32(stack + 84);
	uint32_t carriedR9 = rowCount;
	uint32_t i = 0;
	if (rowCount != 0) {
		do {
			uint32_t row = LOAD32(stack + 80);
			uint32_t nextMethod = LOAD32(LOAD32(row) + 16);
			callTarget.u64 = nextMethod;
			ctx.r3.u64 = row;
			ctx.r4.u64 = stack + 96;
			ctx.r9.u64 = carriedR9;
			ctx.r10.u64 = nextMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((int32_t)ctx.r3.u32 < 0) return failNow();
			if (LOAD32(stack + 96) == 0) return failNow();

			uint32_t keyRow = LOAD32(stack + 80);
			uint32_t keyMethod = LOAD32(LOAD32(keyRow) + 24);
			callTarget.u64 = keyMethod;
			ctx.r3.u64 = keyRow;
			ctx.r4.u64 = stack + 88;
			ctx.r10.u64 = keyMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((int32_t)ctx.r3.u32 < 0) return failTidyBuilder();

			uint32_t valueRow = LOAD32(stack + 80);
			uint32_t valueMethod = LOAD32(LOAD32(valueRow) + 28);
			callTarget.u64 = valueMethod;
			ctx.r3.u64 = valueRow;
			ctx.r4.u64 = stack + 92;
			ctx.r10.u64 = valueMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((int32_t)ctx.r3.u32 < 0) {
				FreeLengthPrefixedBlock(ctx, base, LOAD32(stack + 88));
				return failTidyBuilder();
			}

			BasicWString_ConstructFromWideCStr(ctx, base, stack + 304, LOAD32(stack + 88), ctx.r8.u64);
			BasicWString_ConstructFromWideCStr(ctx, base, stack + 272, LOAD32(stack + 92), ctx.r8.u64);

			uint64_t keyBucket = WStringStream_WriteInteger(ctx, base, stack + 144, LOAD32(stack + 324), ctx.r8.u64);
			uint64_t keyEntry = WStringStream_WriteChar(ctx, base, keyBucket, 58, ctx.r8.u64);
			WStringStream_WriteString(ctx, base, keyEntry, stack + 304, ctx.r8.u64);

			uint64_t valueBucket = WStringStream_WriteInteger(ctx, base, stack + 144, LOAD32(stack + 292), ctx.r8.u64);
			uint64_t valueEntry = WStringStream_WriteChar(ctx, base, valueBucket, 58, ctx.r8.u64);
			WStringStream_WriteString(ctx, base, valueEntry, stack + 272, ctx.r8.u64);

			FreeLengthPrefixedBlock(ctx, base, LOAD32(stack + 88));
			FreeLengthPrefixedBlock(ctx, base, LOAD32(stack + 92));
			WString_Tidy(ctx, base, stack + 272);
			WString_Tidy(ctx, base, stack + 304);

			carriedR9 = ctx.r9.u64;
			++i;
		} while (i < LOAD32(stack + 84));
	}

	ctx.r9.u64 = carriedR9;
	WStringStream_GetString(ctx, base, stack + 112, stack + 148, ctx.r8.u64);

	uint32_t lookupName = LOAD32(stack + 116);
	if (LOAD32(stack + 136) < 8) lookupName = stack + 116;
	uint64_t nameCopy = WString_DuplicateWithLengthPrefix(ctx, base, lookupName);

	uint32_t saveMethod = LOAD32(uint32_t(binaryDataStream->vtable) + 56);
	callTarget.u64 = saveMethod;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = nameCopy;
	ctx.r10.u64 = saveMethod;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t saveResult = ctx.r3.u64;

	FreeLengthPrefixedBlock(ctx, base, nameCopy);
	if (LOAD32(stack + 136) >= 8) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 116));
	}

	STORE32(stack + 132, 0u);
	STORE16(stack + 116, (uint16_t)0);
	STORE32(stack + 136, 7u);

	WStringStreamBase_Destructor(ctx, base, stack + 220);
	const uint64_t zapVtable = (uint64_t)g_820CCFBC;                     // 0xFFFFFFFF820CCFBC
	STORE32(stack + 220, (uint32_t)zapVtable);
	ctx.r9.u64 = zapVtable;
	RefCountedObject_Release(ctx, base, stack + 220);

	stack = PopStackFrame(stack, 384);
	ctx.r1.u64 = stack;
	return saveResult;
}
PROMOTED_ENTRY(93, sub_82C7C4C0, 0x82C7C4C0) { ctx.r3.u64 = CBinaryDataStream_WriteStringPairMap(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Reads characters from a wide stream into a buffer of length + 1 characters allocated on the game stack
// (the delimiter is '\n' as n_sub_82C75438 converts it for the stream), then assigns the first `length`
// characters of the buffer to the string at outString through a temporary string.
uint32_t CBinaryDataStream_ReadDelimitedString(CpuState& ctx, uint8_t* base, uint64_t stream, uint64_t outString, uint64_t length) {
	if (!UseLiftedCode(93, 0x82C7C778)) { ctx.r4.u64 = stream; ctx.r5.u64 = outString; ctx.r6.u64 = length; __imp__sub_82C7C778(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C7C778);
	uint32_t stack = ctx.r1.u64;
	__savegprlr_27(ctx, base);

	uint32_t frameBase = stack - 160;
	stack = PushStackFrame(base, stack, 160);

	// the buffer: length + 1 two-byte characters, the allocation rounded to 16 bytes
	uint32_t bufferChars = (uint32_t)(length + 1);
	uint32_t allocOffset = (-(bufferChars << 1)) & 0xFFFFFFF0u;
	ctx.r1.u64 = stack;
	ctx.r11.u64 = bufferChars;
	alloca_probe(ctx, base, allocOffset);

	uint32_t streamVtable = LOAD32((uint32_t)stream);
	uint32_t backChain = LOAD32(stack);
	uint32_t virtualBaseOffset = LOAD32(streamVtable + 4);
	stack += allocOffset;
	STORE32(stack, backChain);

	uint64_t streamBase = (uint64_t)virtualBaseOffset + stream;
	uint32_t buffer = stack + 80;
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r5.u64 = outString;
	ctx.r6.u64 = length;
	ctx.r7.u64 = backChain;
	ctx.r11.u64 = virtualBaseOffset;
	uint64_t delimiter = n_sub_82C75438(ctx, base, streamBase, 10, streamVtable);
	WStringStream_ReadUntilDelimiter(ctx, base, stream, buffer, length, delimiter, ctx.r8.u64);

	// an empty temporary string at frameBase+80: length 0 at +20, inline capacity 7 at +24
	uint32_t tempString = frameBase + 80;
	STORE32(frameBase + 100, 0);
	STORE32(frameBase + 104, 7);
	STORE16(frameBase + 84, 0);
	// state the callee may pass on
	ctx.r6.u64 = 7;
	ctx.r11.u64 = 0;
	BasicWString_AssignPtrLen(ctx, base, tempString, buffer, length, ctx.r8.u64);

	const int32_t wholeString = -1;
	uint32_t result = BasicWString_AssignSubstr(ctx, base, outString, tempString, 0, wholeString, ctx.r8.u64);

	if (LOAD32(frameBase + 104) >= 8) {
		result = HandleTarget_FreeThunk(ctx, base, LOAD32(frameBase + 84));
	}

	ctx.r1.u64 = frameBase + 160;
	__restgprlr_27(ctx, base);
	return result;
}
PROMOTED_ENTRY(93, sub_82C7C778, 0x82C7C778) { ctx.r3.u64 = CBinaryDataStream_ReadDelimitedString(ctx, base, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CBinaryDataStream_ReadStringPairMap(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outObjectPtr, uint64_t arg3) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_820CCFBC = int32_t(0x820CCFBC);
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	if (!UseLiftedCode(93, 0x82C7C830)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outObjectPtr; ctx.r8.u64 = arg3; __imp__sub_82C7C830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7C830);
	uint32_t stack = ctx.r1.u64;

	const uint32_t zero = 0;
	const uint32_t stringCapacity = 7;
	const uint64_t delimiter = 0xFFFFull;

	PPCRegister callTarget{};
	CBinaryDataStream* stream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	uint32_t streamAddr = binaryDataStreamAddr;
	uint64_t resultObject = 0;
	uint64_t basePtr = (uint64_t)g_82010000;
	uint32_t entryFlags = 0;
	uint32_t entryVtable = 0;
	uint32_t trackFlags = 0;
	uint32_t lineCount = 0;
	uint32_t eventIndex = 0;

	stack = PushStackFrame(base, stack, 416);

	STORE32(outObjectPtr, zero);

	uint32_t readFn = LOAD32(uint32_t(stream->vtable) + 60);
	callTarget.u64 = (uint64_t)readFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = stack + 148;
	ctx.r8.u64 = arg3;
	ctx.r10.u64 = readFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t readStatus = ctx.r3.u32;

	if ((int32_t)readStatus >= 0) {
		uint64_t allocation = operator_new(ctx, base, 52);
		if ((uint32_t)allocation != 0) {
			resultObject = StringPairMap_Constructor(ctx, base, allocation);
		} else {
			resultObject = zero;
		}

		uint32_t initFn = LOAD32(LOAD32((uint32_t)resultObject) + 4);
		callTarget.u64 = (uint64_t)initFn;
		ctx.r3.u64 = resultObject;
		ctx.r10.u64 = initFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t wideName = LOAD32(stack + 148);
		BasicWString_ConstructFromWideCStr(ctx, base, stack + 160, wideName, ctx.r8.u64);

		WStringStream_InitFromString(ctx, base, stack + 192, stack + 160, 1, 1);

		uint32_t nameCapacity = LOAD32(stack + 184);
		if (nameCapacity >= 8) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 164));
			nameCapacity = ctx.r9.u32;
		}
		STORE32(stack + 180, zero);
		STORE16(stack + 164, (uint16_t)zero);
		STORE32(stack + 184, stringCapacity);

		ctx.r9.u64 = nameCapacity;
		WStringStream_ReadInteger(ctx, base, stack + 192, stack + 140, ctx.r8.u64);

		WStringStream_SkipSeparator(ctx, base, stack + 192, 1, delimiter, ctx.r8.u64);
		lineCount = ctx.r11.u32;

		eventIndex = zero;
		if (LOAD32(stack + 140) != 0) {
			do {
				STORE32(stack + 136, stringCapacity);
				STORE32(stack + 132, zero);
				STORE16(stack + 116, (uint16_t)zero);
				STORE32(stack + 104, stringCapacity);
				STORE32(stack + 100, zero);
				STORE16(stack + 84, (uint16_t)zero);

				WStringStream_ReadInteger(ctx, base, stack + 192, stack + 152, ctx.r8.u64);
				WStringStream_SkipSeparator(ctx, base, stack + 192, 1, delimiter, ctx.r8.u64);

				CBinaryDataStream_ReadDelimitedString(ctx, base, stack + 192, stack + 112, LOAD32(stack + 152));

				WStringStream_ReadInteger(ctx, base, stack + 192, stack + 144, ctx.r8.u64);
				WStringStream_SkipSeparator(ctx, base, stack + 192, 1, delimiter, ctx.r8.u64);

				CBinaryDataStream_ReadDelimitedString(ctx, base, stack + 192, stack + 80, LOAD32(stack + 144));

				entryVtable = LOAD32(LOAD32(stack + 192) + 4);
				entryFlags = LOAD32(entryVtable + uint32_t(stack + 200));
				trackFlags = entryFlags & 6;
				if ((int32_t)trackFlags != 0) goto loc_82C7CB28;

				uint32_t firstText = LOAD32(stack + 116);
				if (LOAD32(stack + 136) < 8) {
					firstText = stack + 116;
				}
				ctx.r8.u64 = entryFlags;
				uint64_t firstCopy = WString_DuplicateWithLengthPrefix(ctx, base, firstText);

				uint32_t secondText = LOAD32(stack + 84);
				if (LOAD32(stack + 104) < 8) {
					secondText = stack + 84;
				}
				uint64_t secondCopy = WString_DuplicateWithLengthPrefix(ctx, base, secondText);

				uint32_t addFn = LOAD32(LOAD32((uint32_t)resultObject) + 16);
				callTarget.u64 = (uint64_t)addFn;
				ctx.r3.u64 = resultObject;
				ctx.r4.u64 = firstCopy;
				ctx.r5.u64 = secondCopy;
				ctx.r10.u64 = addFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				uint32_t addStatus = ctx.r3.u32;

				FreeLengthPrefixedBlock(ctx, base, firstCopy);
				FreeLengthPrefixedBlock(ctx, base, secondCopy);

				if ((int32_t)addStatus < 0) goto loc_82C7CBA8;

				if (LOAD32(stack + 104) >= 8) {
					HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 84));
				}
				STORE32(stack + 104, stringCapacity);
				STORE32(stack + 100, zero);
				STORE16(stack + 84, (uint16_t)zero);
				if (LOAD32(stack + 136) >= 8) {
					HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 116));
				}
				lineCount = LOAD32(stack + 140);
				eventIndex = (int32_t)eventIndex + 1;
				STORE32(stack + 136, stringCapacity);
				STORE32(stack + 132, zero);
				STORE16(stack + 116, (uint16_t)zero);
			} while (eventIndex < lineCount);
		}

		uint32_t trackerVtable = LOAD32(stack + 192);
		STORE32(outObjectPtr, (uint32_t)resultObject);
		STORE32(LOAD32(trackerVtable + 4) + uint32_t(stack + 192), 0x8200E254u);
		STORE32(stack + 200, 0x8200E21Cu);
		WStringStream_Reset(ctx, base, stack + 200);

		uint32_t listener = LOAD32(stack + 256);
		STORE32(stack + 200, (uint32_t)((int64_t)basePtr - 7708));
		if (listener != 0) {
			uint32_t listenerInner = LOAD32(listener);
			if (listenerInner != 0) {
				uint64_t released = n_sub_826C4B38(ctx, base, listenerInner);
				basePtr = ctx.r4.u64;
				if ((uint32_t)released == 0) goto loc_82C7CAE0;
				uint32_t releaseFn = LOAD32(LOAD32((uint32_t)released));
				callTarget.u64 = (uint64_t)releaseFn;
				ctx.r3.u64 = released;
				ctx.r4.u64 = 1;
				ctx.r10.u64 = releaseFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				basePtr = ctx.r4.u64;
			}
loc_82C7CAE0:
			HandleTarget_FreeThunk(ctx, base, (uint64_t)listener);
			basePtr = ctx.r4.u64;
		}

		n_sub_82CD1D00(ctx, base, stack + 204);

		uint32_t eventVtable = LOAD32(stack + 192);
		uint64_t vtableSlot = (uint64_t)((int64_t)g_82010000 - 7716);
		uint64_t eventSlot = (uint64_t)((int64_t)str_TXT_820D0000_B_ - 12356);
		STORE32(LOAD32(eventVtable + 4) + uint32_t(stack + 192), (uint32_t)vtableSlot);
		STORE32(stack + 272, (uint32_t)eventSlot);
		ctx.r6.u64 = eventVtable;
		ctx.r7.u64 = eventSlot;
		ctx.r8.u64 = vtableSlot;
		RefCountedObject_Release(ctx, base, stack + 272);
	}

	stack = PopStackFrame(stack, 416);
	ctx.r1.u64 = stack;
	return 0;

loc_82C7CB28:
	{
		uint32_t destroyFn = LOAD32(LOAD32((uint32_t)resultObject) + 8);
		callTarget.u64 = (uint64_t)destroyFn;
		ctx.r3.u64 = resultObject;
		ctx.r7.u64 = trackFlags;
		ctx.r8.u64 = entryFlags;
		ctx.r9.u64 = entryVtable;
		ctx.r10.u64 = destroyFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		if (LOAD32(stack + 104) >= 8) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 84));
		}
		STORE32(stack + 104, stringCapacity);
		STORE32(stack + 100, zero);
		STORE16(stack + 84, (uint16_t)zero);
		if (LOAD32(stack + 136) >= 8) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 116));
		}
		STORE32(stack + 136, stringCapacity);
		STORE32(stack + 132, zero);
		STORE16(stack + 116, (uint16_t)zero);

		n_sub_82C73F18(ctx, base, stack + 272);
		uint64_t ccfbcSlot = (uint64_t)g_820CCFBC;
		STORE32(stack + 272, (uint32_t)ccfbcSlot);
		ctx.r10.u64 = ccfbcSlot;
		RefCountedObject_Release(ctx, base, stack + 272);
	}
	stack = PopStackFrame(stack, 416);
	ctx.r1.u64 = stack;
	return 0xFFFFFFFF80004005ull;

loc_82C7CBA8:
	{
		uint32_t destroyFn = LOAD32(LOAD32((uint32_t)resultObject) + 8);
		callTarget.u64 = (uint64_t)destroyFn;
		ctx.r3.u64 = resultObject;
		ctx.r10.u64 = destroyFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		if (LOAD32(stack + 104) >= 8) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 84));
		}
		STORE32(stack + 104, stringCapacity);
		STORE32(stack + 100, zero);
		STORE16(stack + 84, (uint16_t)zero);
		if (LOAD32(stack + 136) >= 8) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 116));
		}
		STORE32(stack + 136, stringCapacity);
		STORE32(stack + 132, zero);
		STORE16(stack + 116, (uint16_t)zero);

		n_sub_82C73F18(ctx, base, stack + 272);
		uint64_t ccfbcSlot = (uint64_t)g_820CCFBC;
		STORE32(stack + 272, (uint32_t)ccfbcSlot);
		ctx.r10.u64 = ccfbcSlot;
		RefCountedObject_Release(ctx, base, stack + 272);
	}
	stack = PopStackFrame(stack, 416);
	ctx.r1.u64 = stack;
	return 0xFFFFFFFF80004005ull;
}
PROMOTED_ENTRY(93, sub_82C7C830, 0x82C7C830) { ctx.r3.u64 = CBinaryDataStream_ReadStringPairMap(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r8.u64); }
