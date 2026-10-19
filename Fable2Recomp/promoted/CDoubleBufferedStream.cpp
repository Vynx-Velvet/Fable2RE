// CDoubleBufferedStream (vtable 0x820F8F0C): methods of the class as readable C++.
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

uint64_t CDoubleBufferedStream_Construct(CpuState& ctx, uint8_t* base, uint64_t doubleBufferedStreamAddr, uint64_t sourceStream, uint64_t startPosition, uint64_t totalBufferSize) {
	if (!UseLiftedCode(83, 0x82B48EB8)) { ctx.r3.u64 = doubleBufferedStreamAddr; ctx.r4.u64 = sourceStream; ctx.r5.u64 = startPosition; ctx.r6.u64 = totalBufferSize; __imp__sub_82B48EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B48EB8);
	uint32_t stack = ctx.r1.u64;
	CDoubleBufferedStream* doubleBufferedStream = GameObject<CDoubleBufferedStream>(base, doubleBufferedStreamAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t initialPosition = startPosition;
	uint64_t initialTotalBufferSize = totalBufferSize;

	doubleBufferedStream->m_4 = 0;
	doubleBufferedStream->vtable = 0x820F8F0Cu;
	doubleBufferedStream->m_stream = (uint32_t)sourceStream;
	if ((uint32_t)sourceStream != 0) {
		uint32_t virtualFunction = LOAD32(LOAD32((uint32_t)sourceStream) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = sourceStream;
		ctx.r4.u64 = sourceStream;
		ctx.r5.u64 = startPosition;
		ctx.r6.u64 = totalBufferSize;
		ctx.r10.u64 = virtualFunction;
		REX_CALL_INDIRECT_FUNC(virtualFunction);
		sourceStream = ctx.r4.u64;
		startPosition = ctx.r5.u64;
		totalBufferSize = ctx.r6.u64;
	}

	doubleBufferedStream->m_18 = 0;
	doubleBufferedStream->m_position = initialPosition;
	doubleBufferedStream->m_bufferSize = (uint32_t)(initialTotalBufferSize >> 1);
	doubleBufferedStream->m_currentBuffer = 0;

	uint32_t descriptorAddr = (uint32_t)doubleBufferedStreamAddr + 40;
	for (int i = 0; i < 2; ++i) {
		STORE64(descriptorAddr, 0xFFFFFFFFFFFFFFFFULL);
		STORE32(descriptorAddr + 8, 0);
		STORE32(descriptorAddr + 12, 0);
		STORE32(descriptorAddr + 16, 0);
		STORE8(descriptorAddr + 20, 0);
		descriptorAddr += 32;
	}

	uint32_t bufferSize = doubleBufferedStream->m_bufferSize;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = sourceStream;
	ctx.r5.u64 = startPosition;
	ctx.r6.u64 = totalBufferSize;
	uint32_t bufferA = operator_new(ctx, base, bufferSize);
	STORE32(stack + 80, bufferA);
	STORE32(stack + 84, 0);
	doubleBufferedStream->m_bufferA = LOAD64(stack + 80);

	uint32_t bufferSize2 = doubleBufferedStream->m_bufferSize;
	uint32_t bufferB = operator_new(ctx, base, bufferSize2);
	STORE32(stack + 80, bufferB);
	STORE32(stack + 84, 0);
	doubleBufferedStream->m_bufferB = LOAD64(stack + 80);

	uint64_t position = doubleBufferedStream->m_position;
	CDoubleBufferedStream_Reposition(ctx, base, doubleBufferedStreamAddr, position);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return doubleBufferedStreamAddr;
}
PROMOTED_ENTRY(83, sub_82B48EB8, 0x82B48EB8) { ctx.r3.u64 = CDoubleBufferedStream_Construct(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CDoubleBufferedStream_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(83, 0x82B48F90)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82B48F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B48F90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t deleteFlags = static_cast<uint32_t>(arg2);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;

	CDoubleBufferedStream_Destructor(ctx, base, arg1);

	uint64_t result = arg1;
	if ((deleteFlags & 0x1u) != 0) {
		HandleTarget_Free(ctx, base, result);
		result = arg1;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B48F90, 0x82B48F90) { ctx.r3.u64 = CDoubleBufferedStream_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CDoubleBufferedStream_Read(CpuState& ctx, uint8_t* base, uint64_t doubleBufferedStreamAddr, uint64_t destBuffer, uint64_t byteCount) {
	constexpr int32_t g_83317024 = int32_t(0x83317024);
	if (!UseLiftedCode(83, 0x82B49110)) { ctx.r3.u64 = doubleBufferedStreamAddr; ctx.r4.u64 = destBuffer; ctx.r5.u64 = byteCount; __imp__sub_82B49110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B49110);
	uint32_t stack = ctx.r1.u64;
	CDoubleBufferedStream* doubleBufferedStream = GameObject<CDoubleBufferedStream>(base, doubleBufferedStreamAddr);

	stack = PushStackFrame(base, stack, 176);

	auto fail = [&]() -> uint64_t {
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	};

	uint64_t remainingBytes = byteCount;
	uint64_t position = doubleBufferedStream->m_position;
	uint32_t bufferSize = doubleBufferedStream->m_bufferSize;
	uint64_t readWatermark = doubleBufferedStream->m_18;
	uint32_t streamObj = doubleBufferedStream->m_stream;

	// Two 0x20-byte buffers live at +0x28 of the stream object; select the active one.
	uint32_t bufferBase = (uint32_t)((doubleBufferedStream->m_currentBuffer << 5) + doubleBufferedStreamAddr);
	uint32_t bufferDesc = bufferBase + 40;
	uint64_t bufferStart = LOAD64(bufferDesc);
	uint32_t streamVtable = LOAD32(streamObj);
	uint64_t offsetInBuffer = position - bufferStart;
	uint64_t availableInBuffer = (uint64_t)bufferSize - offsetInBuffer;

	uint32_t checkFn = LOAD32(streamVtable + 24);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = streamObj;
	ctx.r4.u64 = bufferStart;
	ctx.r5.u64 = byteCount;
	ctx.r6.u64 = streamVtable;
	ctx.r7.u64 = position;
	ctx.r8.u64 = bufferSize;
	REX_CALL_INDIRECT_FUNC(checkFn);
	uint32_t availableRead = ctx.r3.u32;

	uint32_t maxThreshold = availableRead;
	if (maxThreshold < (uint32_t)readWatermark) maxThreshold = (uint32_t)readWatermark;

	uint64_t positionAfter = doubleBufferedStream->m_position + (uint32_t)remainingBytes;
	if (positionAfter <= (uint64_t)maxThreshold) {
		uint32_t totalCapacity = doubleBufferedStream->m_bufferSize + (uint32_t)availableInBuffer;
		if ((uint32_t)remainingBytes <= totalCapacity) {
			// Enough room in the active buffer: hand out its expected data directly.
			uint32_t zero = 0;
			STORE64(stack + 80, LOAD64((uint32_t)destBuffer));
			uint32_t destObj = LOAD32(stack + 80);
			uint32_t destIndex = LOAD32(stack + 84);
			uint32_t copyTable = (uint32_t)g_83317024;

			for (;;) {
				uint32_t pending = LOAD32(bufferDesc + 16);
				if (pending != 0) {
					uint32_t releaseFn = LOAD32(LOAD32(pending) + 16);
					ctx.r3.u64 = pending;
					ctx.r10.u64 = releaseFn;
					REX_CALL_INDIRECT_FUNC(releaseFn);
					uint32_t releaseResult = ctx.r3.u32;

					uint32_t obj = LOAD32(bufferDesc + 16);
					if (obj != 0) {
						uint32_t objVtable = LOAD32(obj);
						uint32_t freeFn = LOAD32(objVtable + 8);
						ctx.r3.u64 = obj;
						ctx.r9.u64 = freeFn;
						ctx.r10.u64 = objVtable;
						REX_CALL_INDIRECT_FUNC(freeFn);
						STORE32(bufferDesc + 16, zero);
					}
					if ((int32_t)releaseResult != 1) return fail();
				}

				uint64_t chunk = availableInBuffer;
				if ((uint32_t)remainingBytes < (uint32_t)chunk) chunk = remainingBytes;

				uint32_t tableOffset = destIndex << 2;
				uint32_t tableEntry = LOAD32((uint32_t)(tableOffset + copyTable));
				uint64_t srcAddr = (uint64_t)LOAD32(bufferDesc + 8) + offsetInBuffer;
				ctx.r3.u64 = destObj;
				ctx.r4.u64 = srcAddr;
				ctx.r5.u64 = chunk;
				ctx.r9.u64 = tableEntry;
				ctx.r10.u64 = tableOffset;
				REX_CALL_INDIRECT_FUNC(tableEntry);

				remainingBytes -= chunk;
				doubleBufferedStream->m_position = (uint32_t)chunk + doubleBufferedStream->m_position;

				if ((int32_t)remainingBytes != 0) {
					uint32_t swapResult = CDoubleBufferedStream_SwapBuffers(ctx, base, doubleBufferedStreamAddr);
					if ((swapResult & 0xFF) == 0) return fail();

					destObj += (uint32_t)chunk;
					availableInBuffer = (uint64_t)doubleBufferedStream->m_bufferSize;
					offsetInBuffer = 0;
					bufferBase = (uint32_t)((doubleBufferedStream->m_currentBuffer << 5) + doubleBufferedStreamAddr);
					bufferDesc = bufferBase + 40;
					continue;
				}

				stack = PopStackFrame(stack, 176);
				ctx.r1.u64 = stack;
				return 0;
			}
		}

		// Not enough room: flush both buffers and read straight into the destination.
		uint32_t flushResult = CDoubleBufferedStream_FlushBuffer(ctx, base, doubleBufferedStreamAddr, 0);
		if ((flushResult & 0xFF) == 0) return fail();
		flushResult = CDoubleBufferedStream_FlushBuffer(ctx, base, doubleBufferedStreamAddr, 1);
		if ((flushResult & 0xFF) == 0) return fail();

		uint32_t readerVtable = LOAD32(doubleBufferedStream->m_stream);
		uint32_t readFn = LOAD32(readerVtable + 12);
		ctx.r3.u64 = doubleBufferedStream->m_stream;
		ctx.r4.u64 = destBuffer;
		ctx.r5.u64 = doubleBufferedStream->m_position;
		ctx.r6.u64 = remainingBytes;
		ctx.r7.u64 = 0;
		ctx.r10.u64 = readFn;
		REX_CALL_INDIRECT_FUNC(readFn);
		uint32_t readResult = ctx.r3.u32;
		if ((int32_t)readResult < 0) return fail();

		uint32_t streamVtablePtr = doubleBufferedStream->vtable;
		uint64_t seekTarget = doubleBufferedStream->m_position + (uint32_t)remainingBytes;
		uint32_t seekFn = LOAD32(streamVtablePtr + 20);
		ctx.r3.u64 = doubleBufferedStreamAddr;
		ctx.r4.u64 = seekTarget;
		ctx.r5.u64 = 0;
		ctx.r9.u64 = seekFn;
		ctx.r10.u64 = streamVtablePtr;
		REX_CALL_INDIRECT_FUNC(seekFn);

		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		return ctx.r3.u64;
	}

	return fail();
}
PROMOTED_ENTRY(83, sub_82B49110, 0x82B49110) { ctx.r3.u64 = CDoubleBufferedStream_Read(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CDoubleBufferedStream_Write(CpuState& ctx, uint8_t* base, uint64_t doubleBufferedStreamAddr, uint64_t sourceBuffer, uint64_t byteCount) {
	constexpr int32_t g_83317024 = int32_t(0x83317024);
	if (!UseLiftedCode(83, 0x82B49320)) { ctx.r3.u64 = doubleBufferedStreamAddr; ctx.r4.u64 = sourceBuffer; ctx.r5.u64 = byteCount; __imp__sub_82B49320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B49320);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	CDoubleBufferedStream* doubleBufferedStream = GameObject<CDoubleBufferedStream>(base, doubleBufferedStreamAddr);
	stack = PushStackFrame(base, stack, 176);

	uint64_t remainingBytes = byteCount;
	uint32_t sourcePtr = (uint32_t)sourceBuffer;

	uint64_t streamPosition = doubleBufferedStream->m_position;
	uint32_t bufferBlock = ((uint32_t)doubleBufferedStream->m_currentBuffer << 5) + (uint32_t)doubleBufferedStreamAddr + 40;
	uint32_t bufferSize = doubleBufferedStream->m_bufferSize;
	uint64_t bufferBase = LOAD64(bufferBlock);
	uint64_t bufferOffset = streamPosition - bufferBase;
	uint64_t spaceInBuffer = (uint64_t)bufferSize - bufferOffset;
	uint64_t flushThreshold = (uint64_t)bufferSize + spaceInBuffer;

	if ((uint32_t)remainingBytes >= (uint32_t)flushThreshold) {
		// Too big for the double buffer: flush both halves and hand the whole block to the underlying stream.
		ctx.r1.u64 = stack;
		CDoubleBufferedStream_FlushBuffer(ctx, base, doubleBufferedStreamAddr, 0);
		CDoubleBufferedStream_FlushBuffer(ctx, base, doubleBufferedStreamAddr, 1);

		uint32_t sourceWord = LOAD32(sourcePtr);
		uint32_t stream = doubleBufferedStream->m_stream;
		uint64_t streamPos = doubleBufferedStream->m_position;
		STORE32(stack + 84, 0u);
		uint64_t byteBlock = (uint64_t)stack + 80;
		STORE32(stack + 80, sourceWord);
		uint32_t streamVtable = LOAD32(stream);
		uint32_t writeMethod = LOAD32(streamVtable + 20);
		callTarget.u64 = writeMethod;
		ctx.r3.u64 = stream;
		ctx.r4.u64 = byteBlock;
		ctx.r5.u64 = streamPos;
		ctx.r6.u64 = remainingBytes;
		ctx.r8.u64 = writeMethod;
		ctx.r9.u64 = streamVtable;
		ctx.r10.u64 = sourceWord;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		if ((int32_t)ctx.r3.u32 < 0) {
			stack = PopStackFrame(stack, 176);
			ctx.r1.u64 = stack;
			return 0xFFFFFFFF80004005ull;
		}

		uint32_t ownVtable = doubleBufferedStream->vtable;
		uint64_t seekBase = doubleBufferedStream->m_position;
		uint64_t seekTarget = (remainingBytes & 0xFFFFFFFF) + seekBase;
		uint32_t seekMethod = LOAD32(ownVtable + 20);
		callTarget.u64 = seekMethod;
		ctx.r3.u64 = doubleBufferedStreamAddr;
		ctx.r4.u64 = seekTarget;
		ctx.r5.u64 = 0;
		ctx.r8.u64 = seekMethod;
		ctx.r9.u64 = ownVtable;
		ctx.r10.u64 = seekBase;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		return ctx.r3.u64;
	}

	uint32_t zeroValue = 0;
	uint32_t oneValue = 1;
	STORE64(stack + 80, LOAD64(sourcePtr));
	uint32_t copyKind = LOAD32(stack + 84);
	uint64_t sourceData = LOAD32(stack + 80);
	uint32_t copyRoutines = uint32_t(g_83317024);

	for (;;) {
		uint32_t pendingOp = LOAD32(bufferBlock + 16);
		if (pendingOp != 0) {
			uint32_t prepareMethod = LOAD32(LOAD32(pendingOp) + 16);
			callTarget.u64 = prepareMethod;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = pendingOp;
			ctx.r4.u64 = sourceBuffer;
			ctx.r5.u64 = flushThreshold;
			ctx.r6.u64 = bufferBase;
			ctx.r8.u64 = streamPosition;
			ctx.r10.u64 = prepareMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			int32_t prepareResult = (int32_t)ctx.r3.u32;
			bufferBase = ctx.r6.u64;
			streamPosition = ctx.r8.u64;
			if (prepareResult < 0) break;

			uint32_t op = LOAD32(bufferBlock + 16);
			if (op != 0) {
				uint32_t releaseMethod = LOAD32(LOAD32(op) + 8);
				callTarget.u64 = releaseMethod;
				ctx.r3.u64 = op;
				ctx.r10.u64 = releaseMethod;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				bufferBase = ctx.r6.u64;
				streamPosition = ctx.r8.u64;
				STORE32(bufferBlock + 16, zeroValue);
			}
		}

		if ((uint32_t)spaceInBuffer >= (uint32_t)remainingBytes) {
			spaceInBuffer = remainingBytes;
		}
		uint64_t copyLength = spaceInBuffer;
		uint64_t destination = (uint64_t)LOAD32(bufferBlock + 8) + bufferOffset;
		uint64_t source = sourceData;
		uint32_t routineIndex = copyKind + (copyKind << 1);
		routineIndex = routineIndex + LOAD32(bufferBlock + 12);
		uint32_t routineOffset = routineIndex << 2;
		uint32_t copyRoutine = LOAD32(routineOffset + copyRoutines);
		callTarget.u64 = copyRoutine;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = destination;
		ctx.r4.u64 = source;
		ctx.r5.u64 = copyLength;
		ctx.r6.u64 = bufferBase;
		ctx.r8.u64 = streamPosition;
		ctx.r9.u64 = copyRoutine;
		ctx.r10.u64 = routineOffset;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t writtenCount = LOAD32(bufferBlock + 24);
		STORE8(bufferBlock + 20, (uint8_t)oneValue);
		if (writtenCount >= (uint32_t)bufferOffset) {
			writtenCount = (uint32_t)bufferOffset;
		}
		STORE32(bufferBlock + 24, writtenCount);

		uint64_t bufferEnd = spaceInBuffer + bufferOffset;
		uint32_t maxEnd = LOAD32(bufferBlock + 28);
		if (maxEnd >= (uint32_t)bufferEnd) {
			bufferEnd = (uint64_t)maxEnd;
		}
		STORE32(bufferBlock + 28, (uint32_t)bufferEnd);

		uint64_t absolutePosition = (bufferEnd & 0xFFFFFFFF) + LOAD64(bufferBlock);
		remainingBytes = remainingBytes - spaceInBuffer;
		doubleBufferedStream->m_18 = absolutePosition;
		uint64_t newPosition = (spaceInBuffer & 0xFFFFFFFF) + doubleBufferedStream->m_position;
		doubleBufferedStream->m_position = newPosition;
		if ((int32_t)remainingBytes == 0) {
			stack = PopStackFrame(stack, 176);
			ctx.r1.u64 = stack;
			return 0;
		}

		ctx.r8.u64 = newPosition;
		ctx.r9.u64 = absolutePosition;
		uint32_t swapped = CDoubleBufferedStream_SwapBuffers(ctx, base, doubleBufferedStreamAddr);
		sourceBuffer = ctx.r4.u64;
		flushThreshold = ctx.r5.u64;
		bufferBase = ctx.r6.u64;
		streamPosition = ctx.r8.u64;
		if ((swapped & 0xFF) == 0) break;

		uint32_t nextBuffer = doubleBufferedStream->m_currentBuffer;
		sourceData = sourceData + spaceInBuffer;
		spaceInBuffer = doubleBufferedStream->m_bufferSize;
		bufferOffset = 0;
		bufferBlock = ((nextBuffer << 5) + (uint32_t)doubleBufferedStreamAddr) + 40;
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return 0xFFFFFFFF80004005ull;
}
PROMOTED_ENTRY(83, sub_82B49320, 0x82B49320) { ctx.r3.u64 = CDoubleBufferedStream_Write(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CDoubleBufferedStream_Seek(CpuState& ctx, uint8_t* base, uint64_t doubleBufferedStreamAddr, uint64_t seekOffset, uint64_t seekOrigin) {
	if (!UseLiftedCode(83, 0x82B49530)) { ctx.r3.u64 = doubleBufferedStreamAddr; ctx.r4.u64 = seekOffset; ctx.r5.u64 = seekOrigin; __imp__sub_82B49530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B49530);
	uint32_t stack = ctx.r1.u64;
	CDoubleBufferedStream* doubleBufferedStream = GameObject<CDoubleBufferedStream>(base, doubleBufferedStreamAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t origin = (uint32_t)seekOrigin;
	uint32_t stream = doubleBufferedStream->m_stream;
	uint64_t capacity = doubleBufferedStream->m_18;

	// Ask the underlying stream for its length through its vtable (slot 6) and clamp it to the buffer capacity.
	uint32_t vtable = LOAD32(stream);
	uint32_t getLength = LOAD32(vtable + 24);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = stream;
	ctx.r4.u64 = seekOffset;
	ctx.r5.u64 = seekOrigin;
	ctx.r9.u64 = getLength;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(getLength);
	uint64_t streamLength = ctx.r3.u32;
	if ((uint32_t)streamLength < (uint32_t)capacity) {
		streamLength = capacity;
	}
	streamLength &= 0xFFFFFFFF;

	const uint64_t seekFailed = 0xFFFFFFFF80004005ULL;
	uint64_t newPosition = 0;
	bool seekAllowed;
	if (origin == 0) {
		seekAllowed = seekOffset <= streamLength;
		newPosition = seekOffset;
	} else if (origin == 1) {
		newPosition = doubleBufferedStream->m_position + seekOffset;
		seekAllowed = newPosition <= streamLength;
	} else if (origin == 2) {
		newPosition = streamLength + seekOffset;
		seekAllowed = newPosition <= streamLength;
	} else {
		seekAllowed = false;
	}
	if (!seekAllowed) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return seekFailed;
	}
	doubleBufferedStream->m_position = newPosition;

	uint64_t position = doubleBufferedStream->m_position;
	uint32_t repositionResult = CDoubleBufferedStream_Reposition(ctx, base, doubleBufferedStreamAddr, position);
	if ((repositionResult & 0xFF) != 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return seekFailed;
}
PROMOTED_ENTRY(83, sub_82B49530, 0x82B49530) { ctx.r3.u64 = CDoubleBufferedStream_Seek(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CDoubleBufferedStream_Flush(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(83, 0x82B49600)) { ctx.r3.u64 = arg1; __imp__sub_82B49600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B49600);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint64_t result = 0xFFFFFFFF80004005ull; // E_FAIL
	if (CDoubleBufferedStream_FlushBuffer(ctx, base, arg1, 0) & 0xFF) {
		if (CDoubleBufferedStream_FlushBuffer(ctx, base, arg1, 1) & 0xFF) {
			result = 0;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B49600, 0x82B49600) { ctx.r3.u64 = CDoubleBufferedStream_Flush(ctx, base, ctx.r3.u64); }

uint32_t CDoubleBufferedStream_FlushBuffer(CpuState& ctx, uint8_t* base, uint64_t streamPtr, uint64_t bufferIndex) {
	if (!UseLiftedCode(83, 0x82B49678)) { ctx.r3.u64 = streamPtr; ctx.r4.u64 = bufferIndex; __imp__sub_82B49678(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B49678);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	uint32_t streamAddress = (uint32_t)streamPtr;
	uint32_t slotAddress = streamAddress + (((LOAD32(streamAddress + 0x24) ^ (uint32_t)bufferIndex) << 5));
	uint32_t entryAddress = slotAddress + 0x28;

	if (LOAD8(slotAddress + 0x3C) == 1) {
		uint32_t tempAddress = stack + 0x50;
		uint32_t entryField0C = LOAD32(entryAddress + 0x0C);
		uint32_t underlyingStream = LOAD32(streamAddress + 0x08);
		uint64_t total = (uint64_t)LOAD32(entryAddress + 0x18) + (uint64_t)LOAD32(entryAddress + 0x08);
		STORE32(tempAddress, (uint32_t)total);
		STORE32(tempAddress + 0x04, entryField0C);

		uint64_t bufferBase = LOAD64(entryAddress);
		uint32_t bufferOffset = LOAD32(entryAddress + 0x18);
		uint64_t bufferLength = (uint64_t)LOAD32(entryAddress + 0x1C) - (uint64_t)bufferOffset;
		uint32_t method = LOAD32(LOAD32(underlyingStream) + 0x14);
		uint64_t bufferPointer = (uint64_t)bufferOffset + bufferBase;

		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = underlyingStream;
		ctx.r4.u64 = tempAddress;
		ctx.r5.u64 = bufferPointer;
		ctx.r6.u64 = bufferLength;
		ctx.r7.u64 = bufferOffset;
		ctx.r8.u64 = total;
		ctx.r9.u64 = method;
		ctx.r10.u64 = bufferBase;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		int32_t result = (int32_t)ctx.r3.u32;
		bufferIndex = ctx.r4.u64;
		if (result < 0) {
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 0;
		}
		STORE8(entryAddress + 0x14, 0);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = bufferIndex;
	return 1;
}
PROMOTED_ENTRY(83, sub_82B49678, 0x82B49678) { ctx.r3.u64 = CDoubleBufferedStream_FlushBuffer(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CDoubleBufferedStream_SwapBuffers(CpuState& ctx, uint8_t* base, uint64_t doubleBufferedStreamAddr) {
	if (!UseLiftedCode(83, 0x82B49730)) { ctx.r3.u64 = doubleBufferedStreamAddr; __imp__sub_82B49730(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B49730);
	uint32_t stack = ctx.r1.u64;
	CDoubleBufferedStream* doubleBufferedStream = GameObject<CDoubleBufferedStream>(base, doubleBufferedStreamAddr);
	stack = PushStackFrame(base, stack, 96);

	// Flip to the other buffer before flushing the one that was active.
	uint32_t currentBuffer = doubleBufferedStream->m_currentBuffer;
	doubleBufferedStream->m_currentBuffer = currentBuffer ^ 1;

	ctx.r1.u64 = stack;
	uint32_t flushed = CDoubleBufferedStream_FlushBuffer(ctx, base, doubleBufferedStreamAddr, 0);
	uint64_t r9Value = flushed & 0xFF;

	bool swapped = false;
	if ((flushed & 0xFF) != 0) {
		uint32_t newBuffer = doubleBufferedStream->m_currentBuffer;
		uint32_t bufferSize = doubleBufferedStream->m_bufferSize;
		uint32_t bufferSlotAddress = (newBuffer << 5) + (uint32_t)doubleBufferedStreamAddr;
		uint64_t bufferEnd = LOAD64(bufferSlotAddress + 40);
		uint64_t writePosition = (uint64_t)bufferSize + bufferEnd;
		ctx.r9.u64 = bufferSize;
		uint32_t loaded = CDoubleBufferedStream_LoadBuffer(ctx, base, doubleBufferedStreamAddr, 1, writePosition);
		r9Value = ctx.r9.u64;
		swapped = (loaded & 0xFF) != 0;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = r9Value;
	return swapped ? 1 : 0;
}
PROMOTED_ENTRY(83, sub_82B49730, 0x82B49730) { ctx.r3.u64 = CDoubleBufferedStream_SwapBuffers(ctx, base, ctx.r3.u64); }

uint32_t CDoubleBufferedStream_LoadBuffer(CpuState& ctx, uint8_t* base, uint64_t doubleBufferedStreamAddr, uint64_t bufferIndex, uint64_t streamOffset) {
	if (!UseLiftedCode(83, 0x82B497B8)) { ctx.r3.u64 = doubleBufferedStreamAddr; ctx.r4.u64 = bufferIndex; ctx.r5.u64 = streamOffset; __imp__sub_82B497B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B497B8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CDoubleBufferedStream* doubleBufferedStream = GameObject<CDoubleBufferedStream>(base, doubleBufferedStreamAddr);
	stack = PushStackFrame(base, stack, 128);

	// Buffer slot for (currentBuffer ^ buffer): 32-byte records, each starting 40 bytes into the object.
	uint64_t bufferSlot = ((uint32_t)((uint64_t)doubleBufferedStream->m_currentBuffer ^ bufferIndex)) << 5;
	uint64_t elementAddr64 = bufferSlot + doubleBufferedStreamAddr + 40;
	uint32_t elementAddr = (uint32_t)elementAddr64;

	// The requested offset is already loaded in this buffer.
	if (LOAD64(elementAddr) == streamOffset) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 1;
	}

	ctx.r1.u64 = stack;
	uint32_t flushResult = CDoubleBufferedStream_FlushBuffer(ctx, base, doubleBufferedStreamAddr, bufferIndex);
	if ((flushResult & 0xFF) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	uint32_t handleFieldAddr = (uint32_t)(elementAddr64 + 16);
	uint32_t oldHandle = LOAD32(handleFieldAddr);
	if ((int32_t)oldHandle != 0) {
		callTarget.u64 = LOAD32(LOAD32(oldHandle) + 16);
		ctx.r3.u64 = oldHandle;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		if ((int32_t)ctx.r3.u32 < 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return 0;
		}
		SmartPtr_Reset(ctx, base, handleFieldAddr);
	}

	STORE64(elementAddr, streamOffset);
	STORE8(elementAddr + 20, 0);
	STORE32(elementAddr + 24, 0);
	STORE32(elementAddr + 28, 0);

	uint32_t sourceStream = doubleBufferedStream->m_stream;
	callTarget.u64 = LOAD32(LOAD32(sourceStream) + 24);
	ctx.r3.u64 = sourceStream;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t streamLength = ctx.r3.u64;

	if (streamOffset > streamLength) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 1;
	}

	uint64_t remaining = (uint64_t)(uint32_t)streamLength - (uint64_t)(uint32_t)streamOffset;
	uint64_t sizeToRead = doubleBufferedStream->m_bufferSize;
	if ((uint32_t)sizeToRead >= (uint32_t)remaining) {
		sizeToRead = remaining;
	}

	uint32_t destStream = doubleBufferedStream->m_stream;
	callTarget.u64 = LOAD32(LOAD32(destStream) + 16);
	uint64_t handleField64 = elementAddr64 + 8;
	ctx.r3.u64 = (uint64_t)stack + 80;
	ctx.r4.u64 = destStream;
	ctx.r5.u64 = handleField64;
	ctx.r6.u64 = streamOffset;
	ctx.r7.u64 = sizeToRead;
	ctx.r8.u64 = 1;
	ctx.r9.u64 = 0;
	ctx.r10.u64 = 0;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t newHandle = ctx.r3.u64;

	IntrusivePtr_Assign(ctx, base, handleFieldAddr, newHandle);

	uint32_t tempHandle = LOAD32(stack + 80);
	if (tempHandle != 0) {
		callTarget.u64 = LOAD32(LOAD32(tempHandle) + 8);
		ctx.r3.u64 = tempHandle;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	uint32_t finalHandle = LOAD32(handleFieldAddr);
	uint32_t result = (finalHandle != 0) ? 1 : 0;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B497B8, 0x82B497B8) { ctx.r3.u64 = CDoubleBufferedStream_LoadBuffer(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t CDoubleBufferedStream_Reposition(CpuState& ctx, uint8_t* base, uint64_t doubleBufferedStreamAddr, uint64_t streamPosition) {
	if (!UseLiftedCode(83, 0x82B49908)) { ctx.r3.u64 = doubleBufferedStreamAddr; ctx.r4.u64 = streamPosition; __imp__sub_82B49908(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B49908);
	uint32_t stack = ctx.r1.u64;
	CDoubleBufferedStream* doubleBufferedStream = GameObject<CDoubleBufferedStream>(base, doubleBufferedStreamAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	uint32_t bufferSize = doubleBufferedStream->m_bufferSize;
	uint64_t alignedPosition = bufferSize != 0
		? (streamPosition / bufferSize) * (uint64_t)bufferSize
		: 0;

	uint32_t result = 0;
	uint32_t buffer = CDoubleBufferedStream_LoadBuffer(ctx, base, doubleBufferedStreamAddr, 0, alignedPosition);
	if ((buffer & 0xFF) != 0) {
		uint32_t nextBuffer = CDoubleBufferedStream_LoadBuffer(ctx, base, doubleBufferedStreamAddr, 1, alignedPosition + (uint64_t)bufferSize);
		result = (nextBuffer & 0xFF) != 0 ? 1 : 0;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B49908, 0x82B49908) { ctx.r3.u64 = CDoubleBufferedStream_Reposition(ctx, base, ctx.r3.u64, ctx.r4.u64); }
