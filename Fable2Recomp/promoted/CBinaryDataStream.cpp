// CBinaryDataStream (vtable 0x8200E3C0): methods of the class as readable C++.
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

// sub_82C79530  [16 bytes]
void CBinaryDataStream_Destructor(CpuState& ctx, uint8_t* base, uint32_t binaryDataStreamAddr) {
	if (!UseLiftedCode(92, 0x82C79530)) { ctx.r3.u64 = binaryDataStreamAddr; __imp__sub_82C79530(ctx, base); return; }
	LiftedFrame frame(0x82C79530);
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	binaryDataStream->vtable = 0x8200E3C0u;
	return;
}
PROMOTED_ENTRY(92, sub_82C79530, 0x82C79530) { CBinaryDataStream_Destructor(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82C79540(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t flags) {
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
PROMOTED_ENTRY(92, sub_82C79540, 0x82C79540) { ctx.r3.u64 = n_sub_82C79540(ctx, base, ctx.r3.u64, ctx.r4.u64); }

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
			// state the callee may pass on: what the matching compare left in r7-r9
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

uint64_t n_sub_82C79870(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t stringAddr) {
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
	uint32_t storedLength = n_sub_82B4DB10(ctx, base, stringAddr);
	STORE32(lengthAddr, storedLength);
	n_sub_82B4DB28(ctx, base, stringAddr);

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
PROMOTED_ENTRY(92, sub_82C79870, 0x82C79870) { ctx.r3.u64 = n_sub_82C79870(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C79910(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t sourceString, uint64_t arg3) {
	if (!UseLiftedCode(92, 0x82C79910)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = sourceString; ctx.r8.u64 = arg3; __imp__sub_82C79910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C79910);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	// The string goes through n_sub_82CA9D30 into a temporary buffer (length + 1 bytes), which is
	// written through the WriteString slot (+48) and freed; the result is the WriteString result.
	uint64_t sourceLength = n_sub_82B4DB28(ctx, base, sourceString);
	uint64_t bufferSize = sourceLength + 1;
	// state the callee may pass on; n_sub_82CA9D30 then gets r8 as operator_new leaves it
	ctx.r4.u64 = sourceString;
	ctx.r8.u64 = arg3;
	uint64_t buffer = operator_new(ctx, base, bufferSize);
	n_sub_82CA9D30(ctx, base, buffer, sourceString, bufferSize, ctx.r8.u64);

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
PROMOTED_ENTRY(92, sub_82C79910, 0x82C79910) { ctx.r3.u64 = n_sub_82C79910(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

// Reads a narrow string through the virtual ReadString and stores a length-prefixed wide copy of it.
uint64_t n_sub_82C79978(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outWideString) {
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
		n_sub_82CA3970(ctx, base, wideBuffer, LOAD32(narrowStringSlot), (uint64_t)charCount + 1, ctx.r8.u64);
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
PROMOTED_ENTRY(92, sub_82C79978, 0x82C79978) { ctx.r3.u64 = n_sub_82C79978(ctx, base, ctx.r3.u64, ctx.r4.u32); }

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

// Turns the pairs of a source object into one text for the stream. A wide string stream on the game stack
// receives the pair count and ':' (58), then for each pair the key's length, ':', the key, the value's
// length, ':', the value; a length-prefixed copy of the finished text goes to the stream's method at
// vtable +56, whose result is returned. n_sub_82C7C830 parses text of this layout.
uint64_t n_sub_82C7C4C0(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint64_t source) {
	constexpr int32_t g_8200E480 = int32_t(0x8200E480);
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_820CCFBC = int32_t(0x820CCFBC);
	if (!UseLiftedCode(93, 0x82C7C4C0)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = source; __imp__sub_82C7C4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7C4C0);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 384);

	// the string stream: object at stack+144, its buffer at +148, its virtual base at +220
	const uint32_t textStream = stack + 144;
	const uint32_t textBuffer = stack + 148;
	const uint32_t textStreamBase = stack + 220;
	const uint64_t firstBaseVtable = g_8200E480;                       // 0xFFFFFFFF8200E480
	const uint64_t streamBaseVtable = (int64_t)g_82010000 - 7036;      // 0xFFFFFFFF8200E484
	const uint64_t lastBaseVtable = g_820CCFBC;                        // 0xFFFFFFFF820CCFBC

	STORE32(textStream, 0x820CCE8Cu);
	STORE32(textStreamBase, (uint32_t)firstBaseVtable);
	ctx.r1.u64 = stack;
	n_sub_82C75760(ctx, base, textStreamBase, textBuffer, 0, firstBaseVtable);

	// the virtual base is found through the offset at +4 of the object's vtable
	STORE32(LOAD32(LOAD32(textStream) + 4) + textStream, (uint32_t)streamBaseVtable);
	// state the callee may pass on
	n_sub_82C7A0E0(ctx, base, textBuffer, 2, ctx.r8.u64);

	// the source's method at +24 puts an enumerator object at stack+80
	uint32_t sourceVtable = LOAD32((uint32_t)source);
	uint32_t enumerateMethod = LOAD32(sourceVtable + 24);
	ctx.r3.u64 = source;
	ctx.r4.u64 = stack + 80;
	ctx.r8.u64 = enumerateMethod;
	ctx.r9.u64 = sourceVtable;
	REX_CALL_INDIRECT_FUNC(enumerateMethod);

	auto destroyBaseAndFail = [&]() -> uint64_t {
		n_sub_82C7A060(ctx, base, textStreamBase);
		STORE32(textStreamBase, (uint32_t)lastBaseVtable);
		ctx.r10.u64 = lastBaseVtable;  // state the callee may pass on
		n_sub_82CD1E78(ctx, base, textStreamBase);
		stack = PopStackFrame(stack, 384);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	};
	auto destroyStreamAndFail = [&]() -> uint64_t {
		n_sub_82C7A178(ctx, base, textStream);
		stack = PopStackFrame(stack, 384);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	};

	if ((int32_t)ctx.r3.u32 < 0) return destroyBaseAndFail();

	uint32_t enumerator = LOAD32(stack + 80);
	uint32_t countMethod = LOAD32(LOAD32(enumerator) + 20);
	ctx.r3.u64 = enumerator;
	ctx.r4.u64 = stack + 84;
	ctx.r10.u64 = countMethod;
	REX_CALL_INDIRECT_FUNC(countMethod);
	if ((int32_t)ctx.r3.u32 < 0) return destroyStreamAndFail();

	uint64_t countChain = n_sub_82C7BDE0(ctx, base, textStream, LOAD32(stack + 84), ctx.r8.u64);
	n_sub_82C7B808(ctx, base, countChain, 58, ctx.r8.u64);

	enumerator = LOAD32(stack + 80);
	uint32_t resetMethod = LOAD32(LOAD32(enumerator) + 12);
	ctx.r3.u64 = enumerator;
	ctx.r10.u64 = resetMethod;
	REX_CALL_INDIRECT_FUNC(resetMethod);

	uint32_t pairCount = LOAD32(stack + 84);
	// r9 for the calls below: the pair count first, then what the previous pair left in it
	uint64_t nextR9 = pairCount;
	if (pairCount != 0) {
		uint32_t pairIndex = 0;
		do {
			enumerator = LOAD32(stack + 80);
			uint32_t nextMethod = LOAD32(LOAD32(enumerator) + 16);
			ctx.r3.u64 = enumerator;
			ctx.r4.u64 = stack + 96;
			ctx.r9.u64 = nextR9;
			ctx.r10.u64 = nextMethod;
			REX_CALL_INDIRECT_FUNC(nextMethod);
			if ((int32_t)ctx.r3.u32 < 0) return destroyBaseAndFail();
			if (LOAD32(stack + 96) == 0) return destroyBaseAndFail();

			enumerator = LOAD32(stack + 80);
			uint32_t keyMethod = LOAD32(LOAD32(enumerator) + 24);
			ctx.r3.u64 = enumerator;
			ctx.r4.u64 = stack + 88;
			ctx.r10.u64 = keyMethod;
			REX_CALL_INDIRECT_FUNC(keyMethod);
			if ((int32_t)ctx.r3.u32 < 0) return destroyStreamAndFail();

			enumerator = LOAD32(stack + 80);
			uint32_t valueMethod = LOAD32(LOAD32(enumerator) + 28);
			ctx.r3.u64 = enumerator;
			ctx.r4.u64 = stack + 92;
			ctx.r10.u64 = valueMethod;
			REX_CALL_INDIRECT_FUNC(valueMethod);
			if ((int32_t)ctx.r3.u32 < 0) {
				n_sub_82B4DAF8(ctx, base, LOAD32(stack + 88));
				return destroyStreamAndFail();
			}

			// key and value as strings at stack+304 and stack+272 (their lengths at +20)
			BasicWString_ConstructFromWideCStr(ctx, base, stack + 304, LOAD32(stack + 88), ctx.r8.u64);
			BasicWString_ConstructFromWideCStr(ctx, base, stack + 272, LOAD32(stack + 92), ctx.r8.u64);

			uint64_t keyChain = n_sub_82C7BDE0(ctx, base, textStream, LOAD32(stack + 324), ctx.r8.u64);
			keyChain = n_sub_82C7B808(ctx, base, keyChain, 58, ctx.r8.u64);
			n_sub_82C7BAD0(ctx, base, keyChain, stack + 304, ctx.r8.u64);

			uint64_t valueChain = n_sub_82C7BDE0(ctx, base, textStream, LOAD32(stack + 292), ctx.r8.u64);
			valueChain = n_sub_82C7B808(ctx, base, valueChain, 58, ctx.r8.u64);
			n_sub_82C7BAD0(ctx, base, valueChain, stack + 272, ctx.r8.u64);

			n_sub_82B4DAF8(ctx, base, LOAD32(stack + 88));
			n_sub_82B4DAF8(ctx, base, LOAD32(stack + 92));
			WString_Tidy(ctx, base, stack + 272);
			WString_Tidy(ctx, base, stack + 304);
			nextR9 = ctx.r9.u64;
			++pairIndex;
		} while (pairIndex < LOAD32(stack + 84));
	}

	ctx.r9.u64 = nextR9;  // state the callee may pass on
	n_sub_82C7A220(ctx, base, stack + 112, textBuffer, ctx.r8.u64);

	// the finished text, a string at stack+112: characters inline at +116 while the capacity at +136 is below 8
	uint32_t text = LOAD32(stack + 116);
	if (LOAD32(stack + 136) < 8) text = stack + 116;
	uint64_t textCopy = WString_DuplicateWithLengthPrefix(ctx, base, text);

	uint32_t writeMethod = LOAD32(uint32_t(binaryDataStream->vtable) + 56);
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = textCopy;
	ctx.r10.u64 = writeMethod;
	REX_CALL_INDIRECT_FUNC(writeMethod);
	uint64_t result = ctx.r3.u64;

	n_sub_82B4DAF8(ctx, base, textCopy);
	if (LOAD32(stack + 136) >= 8) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 116));
	}
	STORE32(stack + 132, 0);
	STORE16(stack + 116, 0);
	STORE32(stack + 136, 7);

	n_sub_82C7A060(ctx, base, textStreamBase);
	STORE32(textStreamBase, (uint32_t)lastBaseVtable);
	// state the callee may pass on
	n_sub_82CD1E78(ctx, base, textStreamBase);

	stack = PopStackFrame(stack, 384);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C7C4C0, 0x82C7C4C0) { ctx.r3.u64 = n_sub_82C7C4C0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Reads characters from a wide stream into a buffer of length + 1 characters allocated on the game stack
// (the delimiter is '\n' as n_sub_82C75438 converts it for the stream), then assigns the first `length`
// characters of the buffer to the string at outString through a temporary string.
uint32_t n_sub_82C7C778(CpuState& ctx, uint8_t* base, uint64_t stream, uint64_t outString, uint64_t length) {
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
	n_sub_82C7A9B0(ctx, base, stream, buffer, length, delimiter, ctx.r8.u64);

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
PROMOTED_ENTRY(93, sub_82C7C778, 0x82C7C778) { ctx.r3.u64 = n_sub_82C7C778(ctx, base, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// Reads a text from the stream (its method at vtable +60) and parses it in a wide string stream on the game
// stack: the pair count, then for each pair the key's length, the key, the value's length, the value (each
// number is followed by one separator character, skipped by n_sub_82C77878). A new object receives the pairs
// through its method at vtable +16 and is stored at outObjectPtr; on a parse or add failure it is released
// through its method at +8 instead and E_FAIL is returned. n_sub_82C7C4C0 writes text of this layout.
uint64_t n_sub_82C7C830(CpuState& ctx, uint8_t* base, uint64_t binaryDataStreamAddr, uint32_t outObjectPtr, uint64_t callerR8) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_820CCFBC = int32_t(0x820CCFBC);
	if (!UseLiftedCode(93, 0x82C7C830)) { ctx.r3.u64 = binaryDataStreamAddr; ctx.r4.u64 = outObjectPtr; ctx.r8.u64 = callerR8; __imp__sub_82C7C830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7C830);
	uint32_t stack = ctx.r1.u64;
	CBinaryDataStream* binaryDataStream = GameObject<CBinaryDataStream>(base, binaryDataStreamAddr);
	stack = PushStackFrame(base, stack, 416);

	STORE32(outObjectPtr, 0);

	uint32_t readMethod = LOAD32(uint32_t(binaryDataStream->vtable) + 60);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = binaryDataStreamAddr;
	ctx.r4.u64 = stack + 148;
	ctx.r8.u64 = callerR8;
	ctx.r10.u64 = readMethod;
	REX_CALL_INDIRECT_FUNC(readMethod);
	if ((int32_t)ctx.r3.u32 < 0) {
		stack = PopStackFrame(stack, 416);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	}

	uint64_t allocation = operator_new(ctx, base, 52);
	uint64_t resultObject = (uint32_t)allocation != 0 ? n_sub_82C80900(ctx, base, allocation) : 0;

	uint32_t initFn = LOAD32(LOAD32((uint32_t)resultObject) + 4);
	ctx.r3.u64 = resultObject;
	ctx.r10.u64 = initFn;
	REX_CALL_INDIRECT_FUNC(initFn);

	// strings on the game stack: characters inline at +4 (a heap pointer there once the capacity at +24
	// is 8 or more), length at +20
	auto makeEmpty = [&](uint32_t stringAddr) {
		STORE32(stringAddr + 24, 7);
		STORE32(stringAddr + 20, 0);
		STORE16(stringAddr + 4, 0);
	};
	auto destroyString = [&](uint32_t stringAddr) {
		if (LOAD32(stringAddr + 24) >= 8) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(stringAddr + 4));
		}
		makeEmpty(stringAddr);
	};
	auto charactersOf = [&](uint32_t stringAddr) -> uint32_t {
		return LOAD32(stringAddr + 24) < 8 ? stringAddr + 4 : LOAD32(stringAddr + 4);
	};

	// the string stream: object at stack+192, its buffer at +200, its virtual base at +272
	const uint32_t textStream = stack + 192;
	const uint64_t lastBaseVtable = g_820CCFBC;  // 0xFFFFFFFF820CCFBC

	auto releaseAndFail = [&]() -> uint64_t {
		uint32_t destroyFn = LOAD32(LOAD32((uint32_t)resultObject) + 8);
		ctx.r3.u64 = resultObject;
		ctx.r10.u64 = destroyFn;
		REX_CALL_INDIRECT_FUNC(destroyFn);
		destroyString(stack + 80);
		destroyString(stack + 112);
		n_sub_82C73F18(ctx, base, stack + 272);
		STORE32(stack + 272, (uint32_t)lastBaseVtable);
		ctx.r10.u64 = lastBaseVtable;  // state the callee may pass on
		n_sub_82CD1E78(ctx, base, stack + 272);
		stack = PopStackFrame(stack, 416);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	};

	BasicWString_ConstructFromWideCStr(ctx, base, stack + 160, LOAD32(stack + 148), ctx.r8.u64);
	n_sub_82C779E8(ctx, base, textStream, stack + 160, 1, 1);

	// destroy the string at stack+160; r9 for n_sub_82C77700: its capacity, or what the free left in it
	uint64_t nextR9 = LOAD32(stack + 184);
	if ((uint32_t)nextR9 >= 8) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 164));
		nextR9 = ctx.r9.u64;
	}
	makeEmpty(stack + 160);
	ctx.r9.u64 = nextR9;  // state the callee may pass on
	n_sub_82C77700(ctx, base, textStream, stack + 140, ctx.r8.u64);
	ctx.r11.u64 = 0;  // state the callee may pass on
	n_sub_82C77878(ctx, base, textStream, 1, 0xFFFF, ctx.r8.u64);

	// r11 for each n_sub_82C77700 in the loop: what n_sub_82C77878 left in it, then the pair count
	uint32_t nextR11 = ctx.r11.u32;
	uint32_t pairCount = LOAD32(stack + 140);
	if (pairCount != 0) {
		uint32_t pairIndex = 0;
		do {
			// the key at stack+112 and the value at stack+80, their lengths read into stack+152 and stack+144
			makeEmpty(stack + 112);
			makeEmpty(stack + 80);
			ctx.r11.u64 = nextR11;  // state the callee may pass on
			n_sub_82C77700(ctx, base, textStream, stack + 152, ctx.r8.u64);
			n_sub_82C77878(ctx, base, textStream, 1, 0xFFFF, ctx.r8.u64);
			ctx.r3.u64 = (uint32_t)binaryDataStreamAddr;  // state the callee may pass on
			n_sub_82C7C778(ctx, base, textStream, stack + 112, LOAD32(stack + 152));
			n_sub_82C77700(ctx, base, textStream, stack + 144, ctx.r8.u64);
			n_sub_82C77878(ctx, base, textStream, 1, 0xFFFF, ctx.r8.u64);
			ctx.r3.u64 = (uint32_t)binaryDataStreamAddr;  // state the callee may pass on
			n_sub_82C7C778(ctx, base, textStream, stack + 80, LOAD32(stack + 144));

			// state word at +8 of the stream's virtual base (found through the offset at +4 of its vtable);
			// a state with 2 or 4 set (mask 6) means the parse failed
			uint32_t virtualBaseOffset = LOAD32(LOAD32(textStream) + 4);
			uint32_t streamState = LOAD32(virtualBaseOffset + stack + 200);
			uint32_t errorBits = streamState & 6;
			if (errorBits != 0) {
				// state the callee may pass on
				return releaseAndFail();
			}

			ctx.r8.u64 = streamState;  // state the callee may pass on
			uint64_t keyCopy = WString_DuplicateWithLengthPrefix(ctx, base, charactersOf(stack + 112));
			uint64_t valueCopy = WString_DuplicateWithLengthPrefix(ctx, base, charactersOf(stack + 80));

			uint32_t addFn = LOAD32(LOAD32((uint32_t)resultObject) + 16);
			ctx.r3.u64 = resultObject;
			ctx.r4.u64 = keyCopy;
			ctx.r5.u64 = valueCopy;
			ctx.r10.u64 = addFn;
			REX_CALL_INDIRECT_FUNC(addFn);
			uint32_t addStatus = ctx.r3.u32;
			n_sub_82B4DAF8(ctx, base, keyCopy);
			n_sub_82B4DAF8(ctx, base, valueCopy);
			if ((int32_t)addStatus < 0) return releaseAndFail();

			destroyString(stack + 80);
			destroyString(stack + 112);
			pairCount = LOAD32(stack + 140);
			nextR11 = pairCount;
			++pairIndex;
		} while (pairIndex < pairCount);
	}

	uint32_t streamVtable = LOAD32(textStream);
	STORE32(outObjectPtr, (uint32_t)resultObject);
	STORE32(LOAD32(streamVtable + 4) + textStream, 0x8200E254u);
	STORE32(stack + 200, 0x8200E21Cu);
	n_sub_82C73068(ctx, base, stack + 200);

	// r4 as handed on through the calls below
	uint64_t nextR4 = (uint64_t)(int64_t)g_82010000;
	// the object the buffer holds at +56: release what it points to, then free it
	uint32_t heldObject = LOAD32(stack + 256);
	STORE32(stack + 200, uint32_t((int64_t)g_82010000 - 7708));  // 0x8200E1E4
	if (heldObject != 0) {
		uint32_t inner = LOAD32(heldObject);
		if (inner != 0) {
			uint64_t releasedObject = n_sub_826C4B38(ctx, base, inner);
			nextR4 = ctx.r4.u64;
			if ((uint32_t)releasedObject != 0) {
				uint32_t destroyMethod = LOAD32(LOAD32((uint32_t)releasedObject));
				ctx.r3.u64 = releasedObject;
				ctx.r4.u64 = 1;
				ctx.r10.u64 = destroyMethod;
				REX_CALL_INDIRECT_FUNC(destroyMethod);
				nextR4 = ctx.r4.u64;
			}
		}
		HandleTarget_FreeThunk(ctx, base, heldObject);
		nextR4 = ctx.r4.u64;
	}
	n_sub_82CD1D00(ctx, base, stack + 204);

	streamVtable = LOAD32(textStream);
	uint64_t streamBaseVtable = (int64_t)g_82010000 - 7716;  // 0xFFFFFFFF8200E1DC
	STORE32(LOAD32(streamVtable + 4) + textStream, (uint32_t)streamBaseVtable);
	STORE32(stack + 272, (uint32_t)lastBaseVtable);
	// state the callee may pass on
	n_sub_82CD1E78(ctx, base, stack + 272);

	stack = PopStackFrame(stack, 416);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7C830, 0x82C7C830) { ctx.r3.u64 = n_sub_82C7C830(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r8.u64); }
