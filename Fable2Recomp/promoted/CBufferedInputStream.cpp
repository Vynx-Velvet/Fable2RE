// CBufferedInputStream (vtable 0x820F1E60): methods of the class as readable C++.
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

void CBufferedInputStream_SeekTo(CpuState& ctx, uint8_t* base, uint32_t bufferedInputStreamAddr, uint64_t targetPosition) {
	if (!UseLiftedCode(0, 0x82175DE0)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = targetPosition; __imp__sub_82175DE0(ctx, base); return; }
	LiftedFrame frame(0x82175DE0);
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);

	uint32_t cursor = bufferedInputStream->m_cursor;
	uint32_t targetLow = (uint32_t)targetPosition;

	if (cursor != 0 && targetLow >= (uint32_t)bufferedInputStream->m_10) {
		// Range covered by the buffered window: [streamPos, streamPos + bytesRemaining]
		uint64_t bufferStart = (uint64_t)(int64_t)bufferedInputStream->m_streamPos;
		uint32_t bufferEnd = (uint32_t)(bufferStart + (uint32_t)bufferedInputStream->m_bytesRemaining);

		if (targetLow <= bufferEnd) {
			uint64_t offsetInBuffer = (uint64_t)cursor - bufferStart;
			uint64_t newCursor = offsetInBuffer + targetPosition;

			bufferedInputStream->m_streamPos = targetLow;
			bufferedInputStream->m_bytesRemaining = (uint32_t)(bufferEnd - targetPosition);
			bufferedInputStream->m_cursor = (uint32_t)newCursor;
			ctx.r9.u64 = newCursor;
			return;
		}
	}

	// Target outside the buffered window: drop the buffer and reposition the stream.
	bufferedInputStream->m_streamPos = targetLow;
	bufferedInputStream->m_cursor = 0;
	bufferedInputStream->m_10 = 0;
	bufferedInputStream->m_bytesRemaining = 0;
	ctx.r9.u64 = cursor;
}
PROMOTED_ENTRY(0, sub_82175DE0, 0x82175DE0) { CBufferedInputStream_SeekTo(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t CBufferedInputStream_ReadChar(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr, uint64_t character) {
	if (!UseLiftedCode(1, 0x82197488)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = character; __imp__sub_82197488(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82197488);
	uint32_t stack = ctx.r1.u64;
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t characterValue = (uint32_t)character;

	if (bufferedInputStream->m_string != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = character;
		CCharString_MakeUnique(ctx, base, bufferedInputStreamAddr);
		uint32_t charString = bufferedInputStream->m_string;
		ctx.r5.u64 = 1;
		CCharString_AppendChar(ctx, base, charString, characterValue);
		uint32_t result = (uint32_t)bufferedInputStreamAddr;
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return result;
	}

	STORE8(stack + 80, (uint8_t)characterValue);
	STORE8(stack + 81, 0);

	uint32_t newString = 0;
	if ((int8_t)characterValue != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = character;
		uint32_t newStringAddr = operator_new(ctx, base, 16);
		if (newStringAddr != 0) {
			STORE32(newStringAddr, 0);
			STORE32(newStringAddr + 4, 0);
			STORE32(newStringAddr + 8, 0);
			uint32_t length = 0;
			if (LOAD8(stack + 80) != 0) {
				uint32_t cursor = stack + 80;
				do {
					cursor = cursor + 1;
					length = length + 1;
				} while (LOAD8(cursor) != 0);
			}
			CCharString_AssignBytes(ctx, base, newStringAddr, stack + 80, length);
			newString = newStringAddr;
			STORE32(newStringAddr + 12, 1u);
		}
	}

	if (bufferedInputStream->m_string != 0) {
		ctx.r1.u64 = stack;
		CCharString_Release(ctx, base, bufferedInputStreamAddr);
	}
	if (newString != 0) {
		bufferedInputStream->m_string = newString;
	}

	uint32_t result = (uint32_t)bufferedInputStreamAddr;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_82197488, 0x82197488) { ctx.r3.u64 = CBufferedInputStream_ReadChar(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBufferedInputStream_ReadCharString(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr, uint64_t sourceStream) {
	if (!UseLiftedCode(73, 0x82A1B988)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = sourceStream; __imp__sub_82A1B988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A1B988);

	constexpr uint32_t g_83496EB8 = 0x83496EB8;

	uint32_t stack = ctx.r1.u64;
	uint32_t entryR13 = (uint32_t)ctx.r13.u64;
	stack = PushStackFrame(base, stack, 112);

	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	bufferedInputStream->m_string = 0;

	// Bump the global reference counter. It is a big-endian 32-bit value.
	uint64_t lockR9 = 0;
	{
		uint32_t* counter = reinterpret_cast<uint32_t*>(RAW(g_83496EB8));
		bool incremented = false;
		while (!incremented) {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockR9 = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = entryR13 & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			uint32_t rawOld = *counter;
			ctx.reserved.u32 = rawOld;
			uint32_t oldValue = __builtin_bswap32(rawOld);
			uint32_t newValue = oldValue + 1;
			uint32_t rawNew = __builtin_bswap32(newValue);
			incremented = __sync_bool_compare_and_swap(counter, rawOld, rawNew);
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)lockR9 & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		}
	}

	uint64_t lockR7 = (uint64_t)(int64_t)(int32_t)g_83496EB8;
	uint64_t lockR8 = 0;

	// Registers handed to the next callee, carried across loop iterations.
	uint64_t regR5 = 0, regR6 = 0, regR7 = 0, regR8 = 0, regR9 = 0;

	uint32_t charAddr = stack + 80;
	uint32_t currentChar = 0;

	for (;;) {
		int32_t remaining = (int32_t)LOAD32(sourceStream + 20);
		if (remaining >= 1) {
			uint32_t readPtr = LOAD32(sourceStream + 12);
			uint32_t consumed = LOAD32(sourceStream + 4);
			uint8_t c = LOAD8(readPtr);
			regR5 = (uint64_t)consumed + 1;
			regR6 = (uint64_t)readPtr + 1;
			regR7 = (uint64_t)(uint32_t)remaining - 1;
			regR8 = charAddr;
			regR9 = consumed;
			STORE32(sourceStream + 12, (uint32_t)regR6);
			STORE32(sourceStream + 20, (uint32_t)regR7);
			STORE32(sourceStream + 4, (uint32_t)regR5);
			STORE8(charAddr, c);
		} else {
			ctx.r1.u64 = stack;
			ctx.r7.u64 = lockR7;
			ctx.r8.u64 = lockR8;
			ctx.r9.u64 = lockR9;
			CBufferedReadStream_Read(ctx, base, sourceStream, charAddr, 1);
			regR5 = ctx.r5.u64;
			regR6 = ctx.r6.u64;
			regR7 = ctx.r7.u64;
			regR8 = ctx.r8.u64;
			regR9 = ctx.r9.u64;
		}

		currentChar = LOAD8(charAddr);
		if (currentChar == 0) {
			break;
		}

		ctx.r1.u64 = stack;
		ctx.r5.u64 = regR5;
		ctx.r6.u64 = regR6;
		ctx.r7.u64 = regR7;
		ctx.r8.u64 = regR8;
		ctx.r9.u64 = regR9;
		CBufferedInputStream_ReadChar(ctx, base, bufferedInputStreamAddr, currentChar);
		lockR7 = ctx.r7.u64;
		lockR8 = ctx.r8.u64;
		lockR9 = ctx.r9.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = currentChar;
	return bufferedInputStreamAddr;
}
PROMOTED_ENTRY(73, sub_82A1B988, 0x82A1B988) { ctx.r3.u64 = CBufferedInputStream_ReadCharString(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBufferedInputStream_ReadWideString(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr, uint64_t sourceStream) {
	constexpr int32_t g_83496EB4 = int32_t(0x83496EB4);
	if (!UseLiftedCode(73, 0x82A1BA50)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = sourceStream; __imp__sub_82A1BA50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A1BA50);
	uint32_t stack = ctx.r1.u64;
	uint32_t entryR13 = (uint32_t)ctx.r13.u64;
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	stack = PushStackFrame(base, stack, 112);

	bufferedInputStream->m_string = 0;

	// Claim one more reference on the shared big-endian counter.
	uint64_t lockR9 = 0;
	{
		uint32_t* counter = reinterpret_cast<uint32_t*>(RAW((uint32_t)g_83496EB4));
		bool incremented = false;
		while (!incremented) {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockR9 = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = entryR13 & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			uint32_t rawOld = *counter;
			ctx.reserved.u32 = rawOld;
			uint32_t oldValue = __builtin_bswap32(rawOld);
			uint32_t newValue = oldValue + 1;
			uint32_t rawNew = __builtin_bswap32(newValue);
			incremented = __sync_bool_compare_and_swap(counter, rawOld, rawNew);
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)lockR9 & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		}
	}

	const uint32_t streamReadOff = 4;      // total bytes consumed
	const uint32_t streamCursorOff = 12;   // pointer to the next buffered byte
	const uint32_t streamPendingOff = 20;  // bytes still buffered
	const uint32_t streamSwapOff = 24;     // wide chars stored big-endian

	uint64_t appendR5 = 0, appendR6 = 0, appendR7 = 0, appendR8 = 0, appendR9 = 0;
	uint64_t readArg7 = (int64_t)g_83496EB4;
	uint64_t readArg8 = 0;
	uint64_t readArg9 = lockR9;

	const uint32_t wideCharBuffer = stack + 80;
	uint32_t currentWideChar;

	for (;;) {
		uint32_t pendingBytes = LOAD32((uint32_t)sourceStream + streamPendingOff);
		if ((int32_t)pendingBytes >= 2) {
			uint32_t cursor = LOAD32((uint32_t)sourceStream + streamCursorOff);
			uint32_t bytesRead = LOAD32((uint32_t)sourceStream + streamReadOff);
			appendR8 = wideCharBuffer;
			appendR9 = bytesRead;
			appendR7 = pendingBytes - 2;
			appendR6 = (uint64_t)cursor + 2;
			appendR5 = (uint64_t)bytesRead + 2;
			STORE8(wideCharBuffer, LOAD8(cursor));
			STORE8(wideCharBuffer + 1, LOAD8(cursor + 1));
			STORE32((uint32_t)sourceStream + streamCursorOff, cursor + 2);
			STORE32((uint32_t)sourceStream + streamPendingOff, pendingBytes - 2);
			STORE32((uint32_t)sourceStream + streamReadOff, bytesRead + 2);
		} else {
			ctx.r1.u64 = stack;
			ctx.r7.u64 = readArg7;
			ctx.r8.u64 = readArg8;
			ctx.r9.u64 = readArg9;
			CBufferedReadStream_Read(ctx, base, sourceStream, wideCharBuffer, 2);
			appendR5 = ctx.r5.u64;
			appendR6 = ctx.r6.u64;
			appendR7 = ctx.r7.u64;
			appendR8 = ctx.r8.u64;
			appendR9 = ctx.r9.u64;
		}

		currentWideChar = LOAD16(wideCharBuffer);
		uint32_t needsByteSwap = LOAD8((uint32_t)sourceStream + streamSwapOff);
		STORE16(wideCharBuffer + 2, (uint16_t)currentWideChar);
		if (needsByteSwap != 0) {
			uint8_t lowByte = LOAD8(wideCharBuffer);
			STORE8(wideCharBuffer + 2, LOAD8(wideCharBuffer + 1));
			STORE8(wideCharBuffer + 3, lowByte);
			currentWideChar = LOAD16(wideCharBuffer + 2);
		}

		if (currentWideChar == 0) {
			break;
		}

		ctx.r1.u64 = stack;
		ctx.r5.u64 = appendR5;
		ctx.r6.u64 = appendR6;
		ctx.r7.u64 = appendR7;
		ctx.r8.u64 = appendR8;
		ctx.r9.u64 = appendR9;
		CWideString_AppendChar(ctx, base, bufferedInputStreamAddr, currentWideChar);
		readArg7 = ctx.r7.u64;
		readArg8 = ctx.r8.u64;
		readArg9 = ctx.r9.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = currentWideChar;
	return bufferedInputStreamAddr;
}
PROMOTED_ENTRY(73, sub_82A1BA50, 0x82A1BA50) { ctx.r3.u64 = CBufferedInputStream_ReadWideString(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBufferedInputStream_Dtor(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr, uint64_t arg2) {
	if (!UseLiftedCode(73, 0x82A1CE88)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = arg2; __imp__sub_82A1CE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A1CE88);
	uint32_t stack = ctx.r1.u64;
	uint32_t deleteFlags = arg2;
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	stack = PushStackFrame(base, stack, 112);
	bufferedInputStream->m_string = 0x820F1E60u;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	CBufferedInputStream_Reset(ctx, base, bufferedInputStreamAddr);
	bufferedInputStream->m_string = 0x820EFB9Cu;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, bufferedInputStreamAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return bufferedInputStreamAddr;
}
PROMOTED_ENTRY(73, sub_82A1CE88, 0x82A1CE88) { ctx.r3.u64 = CBufferedInputStream_Dtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBufferedInputStream_Reset(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr) {
	if (!UseLiftedCode(73, 0x82A1CEF0)) { ctx.r3.u64 = bufferedInputStreamAddr; __imp__sub_82A1CEF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A1CEF0);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedR9 = ctx.r9.u64;
	PPCRegister callTarget{};
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t buffer = bufferedInputStream->m_buffer;
	if (buffer != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, buffer);
		savedR9 = ctx.r9.u64;
		bufferedInputStream->m_buffer = 0;
		bufferedInputStream->m_bufferSize = 0;
	}

	uint64_t result = bufferedInputStream->m_stream;
	uint32_t stream = (uint32_t)result;
	if (stream != 0) {
		uint32_t canReadFn = LOAD32(LOAD32(stream) + 40);
		callTarget.u64 = canReadFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stream;
		ctx.r10.u64 = canReadFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		uint32_t canRead = (uint32_t)result & 0xFF;
		savedR9 = canRead;
		if (canRead != 0) {
			uint32_t stringPtr = bufferedInputStream->m_string;
			uint32_t streamVtable = LOAD32((uint32_t)bufferedInputStream->m_stream);
			uint32_t getHandleFn = LOAD32(stringPtr + 8);
			callTarget.u64 = getHandleFn;
			ctx.r3.u64 = bufferedInputStreamAddr;
			ctx.r9.u64 = getHandleFn;
			ctx.r10.u64 = stringPtr;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t handle = ctx.r3.u64;

			uint32_t streamPtr = bufferedInputStream->m_stream;
			uint32_t setStreamFn = LOAD32(streamVtable + 20);
			callTarget.u64 = setStreamFn;
			ctx.r3.u64 = streamPtr;
			ctx.r4.u64 = handle;
			ctx.r8.u64 = setStreamFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			savedR9 = ctx.r9.u64;
		}
	}

	bufferedInputStream->m_stream = 0;
	bufferedInputStream->m_streamPos = 0;
	bufferedInputStream->m_8 = 0;
	bufferedInputStream->m_10 = 0;
	bufferedInputStream->m_bytesRemaining = 0;
	bufferedInputStream->m_cursor = 0;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = savedR9;
	return result;
}
PROMOTED_ENTRY(73, sub_82A1CEF0, 0x82A1CEF0) { ctx.r3.u64 = CBufferedInputStream_Reset(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82A1CF98(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(73, 0x82A1CF98)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82A1CF98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A1CF98);
	uint32_t stack = ctx.r1.u64;
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);

	stack = PushStackFrame(base, stack, 128);

	// call the function pointer at offset 8 of the string object (indirect calls take their arguments via ctx)
	uint32_t resetFn = LOAD32(uint32_t(bufferedInputStream->m_string) + 8);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = bufferedInputStreamAddr;
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = arg3;
	ctx.r10.u64 = resetFn;
	REX_CALL_INDIRECT_FUNC(resetFn);

	uint64_t skipResult = ctx.r3.u64;
	uint32_t bufferSize = bufferedInputStream->m_bufferSize;

	uint32_t remaining = (uint32_t)bufferedInputStream->m_8 - (uint32_t)skipResult;
	STORE32(stack + 80, remaining);

	uint32_t countAddr = uint32_t(bufferedInputStreamAddr) + 36; // address of the field at 0x24
	if ((int32_t)remaining < (int32_t)bufferSize) {
		countAddr = stack + 80;
	}
	uint32_t count = LOAD32(countAddr);
	STORE32((uint32_t)arg3, count);

	uint32_t stream = bufferedInputStream->m_stream;
	uint32_t streamVtable = LOAD32(stream);
	uint32_t seekFn = LOAD32(streamVtable + 20);
	ctx.r3.u64 = stream;
	ctx.r4.u64 = skipResult;
	ctx.r8.u64 = bufferSize;
	ctx.r9.u64 = seekFn;
	ctx.r10.u64 = streamVtable;
	REX_CALL_INDIRECT_FUNC(seekFn);

	uint32_t stream2 = bufferedInputStream->m_stream;
	count = LOAD32((uint32_t)arg3);
	uint32_t buffer = bufferedInputStream->m_buffer;
	uint32_t stream2Vtable = LOAD32(stream2);
	uint32_t readFn = LOAD32(stream2Vtable + 12);
	ctx.r3.u64 = stream2;
	ctx.r4.u64 = buffer;
	ctx.r5.u64 = count;
	ctx.r6.u64 = 0;
	ctx.r7.u64 = readFn;
	ctx.r8.u64 = stream2Vtable;
	REX_CALL_INDIRECT_FUNC(readFn);

	STORE32((uint32_t)arg2, uint32_t(bufferedInputStream->m_buffer));

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(73, sub_82A1CF98, 0x82A1CF98) { ctx.r3.u64 = n_sub_82A1CF98(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82A1D030(CpuState& ctx, uint8_t* base, uint32_t bufferedInputStreamAddr, uint32_t arg2) {
	if (!UseLiftedCode(73, 0x82A1D030)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = arg2; __imp__sub_82A1D030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A1D030);
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	return (int32_t)arg2 < (int32_t)bufferedInputStream->m_bufferSize ? 1 : 0;
}
PROMOTED_ENTRY(73, sub_82A1D030, 0x82A1D030) { ctx.r3.u64 = n_sub_82A1D030(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82A1D050(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(73, 0x82A1D050)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82A1D050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A1D050);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	stack = PushStackFrame(base, stack, 112);

	// Call the function pointer at offset 8 of the object referenced by the string field.
	uint32_t openFunc = LOAD32((uint32_t)bufferedInputStream->m_string + 8);
	callTarget.u64 = (uint64_t)openFunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = bufferedInputStreamAddr;
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = arg3;
	ctx.r10.u64 = openFunc;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t handle = ctx.r3.u64;

	// stream->vtable[5](stream, handle)
	uint32_t stream = bufferedInputStream->m_stream;
	uint32_t streamVtable = LOAD32(stream);
	uint32_t seekFunc = LOAD32(streamVtable + 20);
	callTarget.u64 = (uint64_t)seekFunc;
	ctx.r3.u64 = stream;
	ctx.r4.u64 = handle;
	ctx.r7.u64 = seekFunc;
	ctx.r8.u64 = streamVtable;
	ctx.r9.u64 = stream;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// stream->vtable[3](stream, arg2, arg3, 0)
	uint32_t stream2 = bufferedInputStream->m_stream;
	uint32_t readFunc = LOAD32(LOAD32(stream2) + 12);
	callTarget.u64 = (uint64_t)readFunc;
	ctx.r3.u64 = stream2;
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = 0;
	ctx.r10.u64 = readFunc;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(73, sub_82A1D050, 0x82A1D050) { ctx.r3.u64 = n_sub_82A1D050(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t CWideString_AppendChar(CpuState& ctx, uint8_t* base, uint64_t bufferedInputStreamAddr, uint64_t appendedChar) {
	if (!UseLiftedCode(83, 0x82B39010)) { ctx.r3.u64 = bufferedInputStreamAddr; ctx.r4.u64 = appendedChar; __imp__sub_82B39010(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B39010);
	uint32_t stack = ctx.r1.u64;
	CBufferedInputStream* bufferedInputStream = GameObject<CBufferedInputStream>(base, bufferedInputStreamAddr);
	uint32_t streamAddr = (uint32_t)bufferedInputStreamAddr;
	uint32_t charValue = (uint32_t)appendedChar;
	stack = PushStackFrame(base, stack, 128);

	if (bufferedInputStream->m_string != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = appendedChar;
		CWideString_MakeUnique(ctx, base, bufferedInputStreamAddr);

		uint32_t string = bufferedInputStream->m_string;
		CWideString_Reserve(ctx, base, string, (uint64_t)LOAD32(string + 4) + 1);

		STORE16((uint32_t)(LOAD32(string + 4) << 1) + LOAD32(string), (uint16_t)charValue);

		uint32_t bufferBase = LOAD32(string);
		uint32_t newLength = LOAD32(string + 4) + 1;
		uint32_t terminatorOffset = newLength << 1;
		STORE32(string + 4, newLength);
		STORE16(terminatorOffset + bufferBase, 0);

		uint32_t tailOffset = (LOAD32(string + 4) + 1) << 1;
		uint32_t alignedEnd = (tailOffset + 3) & 0xFFFFFFFC;
		uint32_t zeroAddress = LOAD32(string) + tailOffset;
		uint64_t zeroSize = (uint64_t)alignedEnd - (uint64_t)tailOffset;
		ctx.r6.u64 = terminatorOffset;
		memset(ctx, base, zeroAddress, 0, zeroSize);

		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.r7.u64 = bufferBase;
		ctx.r8.u64 = alignedEnd;
		ctx.r9.u64 = (uint64_t)tailOffset + 3;
		return streamAddr;
	}

	uint32_t newString = 0;
	STORE16(stack + 80, (uint16_t)charValue);
	STORE16(stack + 82, 0);
	if ((charValue & 0xFFFF) != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = appendedChar;
		uint64_t allocated = operator_new(ctx, base, 16);
		if (allocated != 0) {
			uint32_t allocatedAddr = (uint32_t)allocated;
			STORE32(allocatedAddr, 0);
			STORE32(allocatedAddr + 4, 0);
			STORE32(allocatedAddr + 8, 0);

			uint32_t scanPtr = stack + 80;
			uint32_t charCount = 0;
			uint32_t firstChar = LOAD16(stack + 80);
			if (firstChar != 0) {
				do {
					scanPtr += 2;
					charCount++;
				} while (LOAD16(scanPtr) != 0);
			}

			ctx.r9.u64 = firstChar;
			CWideString_AssignN(ctx, base, allocated, stack + 80, charCount);
			newString = allocatedAddr;
			STORE32(allocatedAddr + 12, 1u);
		}
	}

	if (LOAD32(streamAddr) != 0) {
		ctx.r1.u64 = stack;
		CCharString_Release(ctx, base, bufferedInputStreamAddr);
	}
	if (newString != 0) {
		bufferedInputStream->m_string = newString;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return streamAddr;
}
PROMOTED_ENTRY(83, sub_82B39010, 0x82B39010) { ctx.r3.u64 = CWideString_AppendChar(ctx, base, ctx.r3.u64, ctx.r4.u64); }
