// CStdStreamBuf (vtable 0x820CCE50): methods of the class as readable C++.
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

uint64_t CStdStreamBuf_Pbackfail(CpuState& ctx, uint8_t* base, uint32_t stdStreamBufAddr, uint64_t putbackChar) {
	if (!UseLiftedCode(45, 0x826C1018)) { ctx.r3.u64 = stdStreamBufAddr; ctx.r4.u64 = putbackChar; __imp__sub_826C1018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C1018);
	constexpr int32_t endOfFile = -1;
	// With this state flag set, only the character already in front of the read position can be put back.
	constexpr uint32_t constantFlag = 2;
	CStdStreamBuf* stdStreamBuf = GameObject<CStdStreamBuf>(base, stdStreamBufAddr);

	uint32_t readPosition = LOAD32(stdStreamBuf->m_getNextPtrPtr);
	bool isEndOfFile = int32_t(putbackChar) == endOfFile;
	bool canPutBack = readPosition != 0 && readPosition > LOAD32(stdStreamBuf->m_getAreaBasePtr) &&
		(isEndOfFile || int8_t(putbackChar) == int8_t(LOAD8(readPosition - 1)) || (stdStreamBuf->m_stateFlags & constantFlag) == 0);
	if (!canPutBack) {
		ctx.r4.u64 = putbackChar;
		return uint64_t(int64_t(endOfFile));
	}

	uint32_t getCountPtr = stdStreamBuf->m_getCountPtr;
	STORE32(getCountPtr, LOAD32(getCountPtr) + 1);
	uint32_t getNextPtrPtr = stdStreamBuf->m_getNextPtrPtr;
	STORE32(getNextPtrPtr, LOAD32(getNextPtrPtr) - 1);
	if (isEndOfFile) {
		ctx.r4.u64 = 0;
		return 0;
	}
	STORE8(LOAD32(stdStreamBuf->m_getNextPtrPtr), uint8_t(putbackChar));
	ctx.r4.u64 = putbackChar;
	return putbackChar;
}
PROMOTED_ENTRY(45, sub_826C1018, 0x826C1018) { ctx.r3.u64 = CStdStreamBuf_Pbackfail(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CStdStreamBuf_Underflow(CpuState& ctx, uint8_t* base, uint32_t stdStreamBufAddr) {
	if (!UseLiftedCode(45, 0x826C10B8)) { ctx.r3.u64 = stdStreamBufAddr; __imp__sub_826C10B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C10B8);
	constexpr uint64_t endOfFile = ~uint64_t(0);
	constexpr uint32_t noReadFlag = 4;
	CStdStreamBuf* stdStreamBuf = GameObject<CStdStreamBuf>(base, stdStreamBufAddr);

	uint32_t getNextPtrPtr = stdStreamBuf->m_getNextPtrPtr;
	uint32_t readPosition = LOAD32(getNextPtrPtr);
	if (readPosition == 0)
		return endOfFile;
	uint32_t getCountPtr = stdStreamBuf->m_getCountPtr;
	if (readPosition < readPosition + LOAD32(getCountPtr))
		return LOAD8(readPosition);

	// The read area is used up: it grows to the high-water mark of what has been written.
	if ((stdStreamBuf->m_stateFlags & noReadFlag) != 0)
		return endOfFile;
	uint32_t writePosition = LOAD32(stdStreamBuf->m_putNextPtrPtr);
	if (writePosition == 0)
		return endOfFile;
	if (writePosition <= readPosition && stdStreamBuf->m_seekHigh <= readPosition)
		return endOfFile;
	if (stdStreamBuf->m_seekHigh < writePosition)
		stdStreamBuf->m_seekHigh = writePosition;
	STORE32(getCountPtr, stdStreamBuf->m_seekHigh - LOAD32(getNextPtrPtr));
	return LOAD8(LOAD32(stdStreamBuf->m_getNextPtrPtr));
}
PROMOTED_ENTRY(45, sub_826C10B8, 0x826C10B8) { ctx.r3.u64 = CStdStreamBuf_Underflow(ctx, base, ctx.r3.u32); }

void CStdStreamBuf_Seekoff(CpuState& ctx, uint8_t* base, uint32_t resultAddr, uint64_t streamBufAddr, uint64_t seekOffset, uint32_t seekOrigin, uint32_t openModeFlags) {
	if (!UseLiftedCode(45, 0x826C1158)) { ctx.r3.u64 = resultAddr; ctx.r4.u64 = streamBufAddr; ctx.r5.u64 = seekOffset; ctx.r6.u64 = seekOrigin; ctx.r7.u64 = openModeFlags; __imp__sub_826C1158(ctx, base); return; }
	LiftedFrame frame(0x826C1158);
	// The offset value that marks an invalid stream position.
	constexpr uint32_t invalidOffsetAddress = 0x82013B88u;
	constexpr uint32_t readMode = 1;
	constexpr uint32_t writeMode = 2;
	constexpr int32_t fromStart = 0;
	constexpr int32_t fromCurrent = 1;
	constexpr int32_t fromEnd = 2;
	CStdStreamBuf* streamBuf = GameObject<CStdStreamBuf>(base, uint32_t(streamBufAddr));
	// The result, returned through the first argument, is a stream position: the offset (+0), a 64-bit file
	// position (+8) and a conversion state (+16).
	uint64_t position = seekOffset;
	uint32_t resultOffset = 0;
	uint64_t handBack = streamBufAddr;   // (what the original leaves in r4)

	// The high-water mark keeps up with the write position; positions count from the start of the read area up to it.
	uint32_t putNextPtrPtr = streamBuf->m_putNextPtrPtr;
	uint32_t writePosition = LOAD32(putNextPtrPtr);
	if (writePosition != 0 && streamBuf->m_seekHigh < writePosition)
		streamBuf->m_seekHigh = writePosition;

	uint32_t readPosition = (openModeFlags & readMode) != 0 ? LOAD32(streamBuf->m_getNextPtrPtr) : 0;
	if (readPosition == 0)
		writePosition = (openModeFlags & writeMode) != 0 ? LOAD32(putNextPtrPtr) : 0;

	if (readPosition != 0) {
		// Move the read position; with the write mode too, the write area then starts at the new read position.
		uint32_t invalidOffset = LOAD32(invalidOffsetAddress);
		if (int32_t(seekOrigin) == fromEnd)
			position = uint64_t(streamBuf->m_seekHigh) - uint64_t(LOAD32(streamBuf->m_getAreaBasePtr)) + position;
		else if (int32_t(seekOrigin) == fromCurrent && (openModeFlags & writeMode) == 0)
			position = uint64_t(readPosition) - uint64_t(LOAD32(streamBuf->m_getAreaBasePtr)) + position;
		else if (int32_t(seekOrigin) != fromStart)
			position = invalidOffset;
		resultOffset = invalidOffset;
		if (int32_t(position) >= 0) {
			uint32_t getAreaBase = LOAD32(streamBuf->m_getAreaBasePtr);
			if (int32_t(position) <= int32_t(streamBuf->m_seekHigh - getAreaBase)) {
				resultOffset = uint32_t(position);
				uint32_t distance = getAreaBase - readPosition + uint32_t(position);
				uint32_t getCountPtr = streamBuf->m_getCountPtr;
				STORE32(getCountPtr, LOAD32(getCountPtr) - distance);
				uint32_t getNextPtrPtr = streamBuf->m_getNextPtrPtr;
				STORE32(getNextPtrPtr, LOAD32(getNextPtrPtr) + distance);
				if ((openModeFlags & writeMode) != 0) {
					uint32_t currentPutNextPtrPtr = streamBuf->m_putNextPtrPtr;
					uint32_t currentWritePosition = LOAD32(currentPutNextPtrPtr);
					if (currentWritePosition != 0) {
						uint32_t newReadPosition = LOAD32(streamBuf->m_getNextPtrPtr);
						uint32_t writeEnd = LOAD32(streamBuf->m_putCountPtr) + currentWritePosition;
						STORE32(currentPutNextPtrPtr, newReadPosition);
						uint32_t putCountPtr = streamBuf->m_putCountPtr;
						STORE32(putCountPtr, writeEnd - newReadPosition);
						handBack = putCountPtr;
					}
				}
			}
		}
	} else if (writePosition != 0) {
		// Move the write position.
		uint32_t invalidOffset = LOAD32(invalidOffsetAddress);
		if (int32_t(seekOrigin) == fromEnd)
			position = uint64_t(streamBuf->m_seekHigh) - uint64_t(LOAD32(streamBuf->m_getAreaBasePtr)) + position;
		else if (int32_t(seekOrigin) == fromCurrent)
			position = uint64_t(writePosition) - uint64_t(LOAD32(streamBuf->m_getAreaBasePtr)) + position;
		else if (int32_t(seekOrigin) != fromStart)
			position = invalidOffset;
		resultOffset = invalidOffset;
		if (int32_t(position) >= 0) {
			uint32_t getAreaBase = LOAD32(streamBuf->m_getAreaBasePtr);
			if (int32_t(position) <= int32_t(streamBuf->m_seekHigh - getAreaBase)) {
				resultOffset = uint32_t(position);
				// (64-bit: the new write position goes back to the caller whole in r4)
				uint64_t distance = uint64_t(getAreaBase) - uint64_t(writePosition) + position;
				uint32_t putCountPtr = streamBuf->m_putCountPtr;
				STORE32(putCountPtr, uint32_t(LOAD32(putCountPtr) - distance));
				uint32_t currentPutNextPtrPtr = streamBuf->m_putNextPtrPtr;
				uint64_t newWritePosition = LOAD32(currentPutNextPtrPtr) + distance;
				STORE32(currentPutNextPtrPtr, uint32_t(newWritePosition));
				handBack = newWritePosition;
			}
		}
	} else {
		resultOffset = LOAD32(invalidOffsetAddress);
	}

	STORE32(resultAddr, resultOffset);
	STORE64(resultAddr + 8, 0);
	STORE32(resultAddr + 16, 0);
	ctx.r4.u64 = handBack;
}
PROMOTED_ENTRY(45, sub_826C1158, 0x826C1158) { CStdStreamBuf_Seekoff(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u32, ctx.r7.u32); }

void CStdStreamBuf_Seekpos(CpuState& ctx, uint8_t* base, uint32_t resultAddr, uint64_t streamBufAddr, uint64_t positionOffsetWord, uint32_t positionFileOffset, uint64_t positionStateWord, uint32_t openModeFlags) {
	if (!UseLiftedCode(45, 0x826C13A0)) { ctx.r3.u64 = resultAddr; ctx.r4.u64 = streamBufAddr; ctx.r5.u64 = positionOffsetWord; ctx.r6.u64 = positionFileOffset; ctx.r7.u64 = positionStateWord; ctx.r8.u64 = openModeFlags; __imp__sub_826C13A0(ctx, base); return; }
	LiftedFrame frame(0x826C13A0);
	// The offset value that marks an invalid stream position.
	constexpr uint32_t invalidOffsetAddress = 0x82013B88u;
	constexpr uint32_t readMode = 1;
	constexpr uint32_t writeMode = 2;
	uint32_t callerStack = ctx.r1.u32;
	CStdStreamBuf* streamBuf = GameObject<CStdStreamBuf>(base, uint32_t(streamBufAddr));
	// The position comes by value in three doublewords, laid out like the result (returned through the first
	// argument): the offset in the high word of the first, a 64-bit file position, a conversion state. The first
	// and the third are stored into the frame of the caller.
	STORE64(callerStack + 48, positionStateWord);
	uint32_t putNextPtrPtr = streamBuf->m_putNextPtrPtr;
	STORE64(callerStack + 32, positionOffsetWord);
	// (64-bit: the new write position goes back to the caller whole in r4)
	uint64_t position = uint64_t(uint32_t(positionOffsetWord >> 32)) + uint64_t(int64_t(int32_t(positionFileOffset)));

	// The high-water mark keeps up with the write position; positions count from the start of the read area up to it.
	uint32_t writePosition = LOAD32(putNextPtrPtr);
	if (writePosition != 0 && streamBuf->m_seekHigh < writePosition)
		streamBuf->m_seekHigh = writePosition;

	uint32_t invalidOffset = LOAD32(invalidOffsetAddress);
	uint32_t resultOffset = uint32_t(position);
	uint64_t handBack = streamBufAddr;   // (what the original leaves in r4)
	if (int32_t(position) != int32_t(invalidOffset)) {
		resultOffset = invalidOffset;
		uint32_t readPosition = (openModeFlags & readMode) != 0 ? LOAD32(streamBuf->m_getNextPtrPtr) : 0;
		if (readPosition != 0) {
			// Move the read position; with the write mode too, the write area then starts at the new read position.
			if (int32_t(position) >= 0) {
				uint32_t getAreaBase = LOAD32(streamBuf->m_getAreaBasePtr);
				if (int32_t(position) <= int32_t(streamBuf->m_seekHigh - getAreaBase)) {
					resultOffset = uint32_t(position);
					uint32_t distance = getAreaBase - readPosition + uint32_t(position);
					uint32_t getCountPtr = streamBuf->m_getCountPtr;
					STORE32(getCountPtr, LOAD32(getCountPtr) - distance);
					uint32_t getNextPtrPtr = streamBuf->m_getNextPtrPtr;
					STORE32(getNextPtrPtr, LOAD32(getNextPtrPtr) + distance);
					if ((openModeFlags & writeMode) != 0) {
						uint32_t currentPutNextPtrPtr = streamBuf->m_putNextPtrPtr;
						uint32_t currentWritePosition = LOAD32(currentPutNextPtrPtr);
						if (currentWritePosition != 0) {
							uint32_t newReadPosition = LOAD32(streamBuf->m_getNextPtrPtr);
							uint32_t writeEnd = LOAD32(streamBuf->m_putCountPtr) + currentWritePosition;
							STORE32(currentPutNextPtrPtr, newReadPosition);
							uint32_t putCountPtr = streamBuf->m_putCountPtr;
							STORE32(putCountPtr, writeEnd - newReadPosition);
							handBack = putCountPtr;
						}
					}
				}
			}
		} else if ((openModeFlags & writeMode) != 0) {
			// Move the write position.
			uint32_t currentWritePosition = LOAD32(putNextPtrPtr);
			if (currentWritePosition != 0 && int32_t(position) >= 0) {
				uint32_t getAreaBase = LOAD32(streamBuf->m_getAreaBasePtr);
				if (int32_t(position) <= int32_t(streamBuf->m_seekHigh - getAreaBase)) {
					resultOffset = uint32_t(position);
					uint64_t distance = uint64_t(getAreaBase) - uint64_t(currentWritePosition) + position;
					uint32_t putCountPtr = streamBuf->m_putCountPtr;
					STORE32(putCountPtr, uint32_t(LOAD32(putCountPtr) - distance));
					uint32_t currentPutNextPtrPtr = streamBuf->m_putNextPtrPtr;
					uint64_t newWritePosition = distance + LOAD32(currentPutNextPtrPtr);
					STORE32(currentPutNextPtrPtr, uint32_t(newWritePosition));
					handBack = newWritePosition;
				}
			}
		}
	}

	STORE32(resultAddr, resultOffset);
	STORE64(resultAddr + 8, 0);
	STORE32(resultAddr + 16, 0);
	ctx.r4.u64 = handBack;
}
PROMOTED_ENTRY(45, sub_826C13A0, 0x826C13A0) { CStdStreamBuf_Seekpos(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u32, ctx.r7.u64, ctx.r8.u32); }

uint64_t CStdStreamBuf_Xsputn(CpuState& ctx, uint8_t* base, uint64_t stdStreamBufAddr, uint64_t sourceBuffer, uint64_t byteCount, uint64_t forwardedArgument) {
	if (!UseLiftedCode(45, 0x826C3B30)) { ctx.r3.u64 = stdStreamBufAddr; ctx.r4.u64 = sourceBuffer; ctx.r5.u64 = byteCount; ctx.r8.u64 = forwardedArgument; __imp__sub_826C3B30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C3B30);
	CStdStreamBuf* stdStreamBuf = GameObject<CStdStreamBuf>(base, stdStreamBufAddr);
	// Values the original keeps in its argument registers from call to call and hands on to memcpy_s and to the
	// overflow method (and r4 back to its caller): first the caller's, after a block copy the copy's own (the new
	// write position, the address of the write pointer, the new and the old free count), after an overflow call
	// what that call left.
	uint64_t forwardedSource = sourceBuffer;
	uint64_t forwardedCount = byteCount;
	uint64_t forwardedPosition = ctx.r6.u64;
	uint64_t forwardedPointerAddress = ctx.r7.u64;
	uint64_t forwardedNewCount = forwardedArgument;
	uint64_t forwardedOldCount = ctx.r9.u64;
	GameStackFrame stackFrame(ctx, base, 128);

	uint64_t source = sourceBuffer;
	uint64_t remainingCount = byteCount;
	uint64_t writtenCount = 0;
	while (int32_t(remainingCount) > 0) {
		uint64_t freeCount = CStdStreamBuf_PutAvailable(ctx, base, stdStreamBufAddr);
		if (int32_t(freeCount) > 0) {
			// Copy as much as fits into the write area.
			uint64_t copyCount = int32_t(remainingCount) < int32_t(freeCount) ? remainingCount : freeCount;
			uint32_t writePosition = LOAD32(stdStreamBuf->m_putNextPtrPtr);
			ctx.r7.u64 = forwardedPointerAddress;
			ctx.r9.u64 = forwardedOldCount;
			memcpy_s_ZeroFillOnError(ctx, base, writePosition, freeCount, source, copyCount, forwardedNewCount);
			forwardedSource = ctx.r4.u64;
			forwardedCount = ctx.r5.u64;
			uint32_t putCountPtr = stdStreamBuf->m_putCountPtr;
			source += copyCount;
			writtenCount += copyCount;
			remainingCount -= copyCount;
			forwardedOldCount = LOAD32(putCountPtr);
			forwardedNewCount = forwardedOldCount - copyCount;
			STORE32(putCountPtr, uint32_t(forwardedNewCount));
			forwardedPointerAddress = stdStreamBuf->m_putNextPtrPtr;
			forwardedPosition = LOAD32(uint32_t(forwardedPointerAddress)) + copyCount;
			STORE32(uint32_t(forwardedPointerAddress), uint32_t(forwardedPosition));
		} else {
			// The write area is full: the overflow method takes the next character.
			uint32_t character = LOAD8(uint32_t(source));
			uint32_t vtable = stdStreamBuf->vtable;
			uint32_t overflowMethod = LOAD32(vtable + 4);
			ctx.r3.u64 = stdStreamBufAddr;
			ctx.r4.u64 = character;
			ctx.r5.u64 = forwardedCount;
			ctx.r6.u64 = forwardedPosition;
			ctx.r7.u64 = forwardedPointerAddress;
			ctx.r8.u64 = forwardedNewCount;
			ctx.r9.u64 = forwardedOldCount;
			ctx.r10.u64 = overflowMethod;
			REX_CALL_INDIRECT_FUNC(overflowMethod);
			uint32_t overflowResult = ctx.r3.u32;
			forwardedSource = ctx.r4.u64;
			forwardedCount = ctx.r5.u64;
			forwardedPosition = ctx.r6.u64;
			forwardedPointerAddress = ctx.r7.u64;
			forwardedNewCount = ctx.r8.u64;
			forwardedOldCount = ctx.r9.u64;
			if (int32_t(overflowResult) == -1)
				break;
			source += 1;
			writtenCount += 1;
			remainingCount -= 1;
		}
	}
	ctx.r4.u64 = forwardedSource;
	return writtenCount;
}
PROMOTED_ENTRY(45, sub_826C3B30, 0x826C3B30) { ctx.r3.u64 = CStdStreamBuf_Xsputn(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint64_t CStdStreamBuf_Xsgetn(CpuState& ctx, uint8_t* base, uint64_t stdStreamBufAddr, uint64_t destinationBuffer, uint64_t destinationSize, uint64_t byteCount, uint64_t forwardedArgument) {
	if (!UseLiftedCode(45, 0x826C3C00)) { ctx.r3.u64 = stdStreamBufAddr; ctx.r4.u64 = destinationBuffer; ctx.r5.u64 = destinationSize; ctx.r6.u64 = byteCount; ctx.r8.u64 = forwardedArgument; __imp__sub_826C3C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C3C00);
	CStdStreamBuf* stdStreamBuf = GameObject<CStdStreamBuf>(base, stdStreamBufAddr);
	// Values the original keeps in its argument registers from call to call and hands on to memcpy_s and to the
	// uflow method (and r4 back to its caller): first the caller's, after a block copy the copy's own (the new
	// read position, the address of the read pointer, the new and the old readable count), after a uflow call
	// what that call left.
	uint64_t forwardedDestination = destinationBuffer;
	uint64_t forwardedSize = destinationSize;
	uint64_t forwardedPosition = byteCount;
	uint64_t forwardedPointerAddress = ctx.r7.u64;
	uint64_t forwardedNewCount = forwardedArgument;
	uint64_t forwardedOldCount = ctx.r9.u64;
	GameStackFrame stackFrame(ctx, base, 144);

	uint64_t destination = destinationBuffer;
	uint64_t remainingCount = byteCount;
	uint64_t readCount = 0;
	while (int32_t(remainingCount) > 0) {
		uint64_t availableCount = CStdStreamBuf_GetAvailable(ctx, base, stdStreamBufAddr);
		if (int32_t(availableCount) > 0) {
			// Copy as much as the read area holds (memcpy_s gets the whole destination size each time).
			uint64_t copyCount = int32_t(remainingCount) < int32_t(availableCount) ? remainingCount : availableCount;
			uint32_t readPosition = LOAD32(stdStreamBuf->m_getNextPtrPtr);
			ctx.r7.u64 = forwardedPointerAddress;
			ctx.r9.u64 = forwardedOldCount;
			memcpy_s_ZeroFillOnError(ctx, base, destination, destinationSize, readPosition, copyCount, forwardedNewCount);
			forwardedDestination = ctx.r4.u64;
			forwardedSize = ctx.r5.u64;
			uint32_t getCountPtr = stdStreamBuf->m_getCountPtr;
			destination += copyCount;
			readCount += copyCount;
			remainingCount -= copyCount;
			forwardedOldCount = LOAD32(getCountPtr);
			forwardedNewCount = forwardedOldCount - copyCount;
			STORE32(getCountPtr, uint32_t(forwardedNewCount));
			forwardedPointerAddress = stdStreamBuf->m_getNextPtrPtr;
			forwardedPosition = LOAD32(uint32_t(forwardedPointerAddress)) + copyCount;
			STORE32(uint32_t(forwardedPointerAddress), uint32_t(forwardedPosition));
		} else {
			// The read area is empty: the uflow method gives the next character.
			uint32_t vtable = stdStreamBuf->vtable;
			uint32_t uflowMethod = LOAD32(vtable + 20);
			ctx.r3.u64 = stdStreamBufAddr;
			ctx.r4.u64 = forwardedDestination;
			ctx.r5.u64 = forwardedSize;
			ctx.r6.u64 = forwardedPosition;
			ctx.r7.u64 = forwardedPointerAddress;
			ctx.r8.u64 = forwardedNewCount;
			ctx.r9.u64 = forwardedOldCount;
			ctx.r10.u64 = uflowMethod;
			REX_CALL_INDIRECT_FUNC(uflowMethod);
			uint32_t character = ctx.r3.u32;
			forwardedDestination = ctx.r4.u64;
			forwardedSize = ctx.r5.u64;
			forwardedPosition = ctx.r6.u64;
			forwardedPointerAddress = ctx.r7.u64;
			forwardedNewCount = ctx.r8.u64;
			forwardedOldCount = ctx.r9.u64;
			if (int32_t(character) == -1)
				break;
			STORE8(uint32_t(destination), uint8_t(character));
			readCount += 1;
			destination += 1;
			remainingCount -= 1;
		}
	}
	ctx.r4.u64 = forwardedDestination;
	return readCount;
}
PROMOTED_ENTRY(45, sub_826C3C00, 0x826C3C00) { ctx.r3.u64 = CStdStreamBuf_Xsgetn(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint64_t CStdStreamBuf_Uflow(CpuState& ctx, uint8_t* base, uint64_t stdStreamBufAddr) {
	if (!UseLiftedCode(45, 0x826C3CE8)) { ctx.r3.u64 = stdStreamBufAddr; __imp__sub_826C3CE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826C3CE8);
	CStdStreamBuf* stdStreamBuf = GameObject<CStdStreamBuf>(base, stdStreamBufAddr);
	GameStackFrame stackFrame(ctx, base, 96);

	uint32_t vtable = stdStreamBuf->vtable;
	uint32_t underflowMethod = LOAD32(vtable + 16);
	ctx.r3.u64 = stdStreamBufAddr;
	ctx.r10.u64 = underflowMethod;
	REX_CALL_INDIRECT_FUNC(underflowMethod);
	uint64_t underflowResult = ctx.r3.u64;
	if (int32_t(underflowResult) == -1)
		return underflowResult;

	// Take the character at the read position and step past it.
	uint32_t getCountPtr = stdStreamBuf->m_getCountPtr;
	STORE32(getCountPtr, LOAD32(getCountPtr) - 1);
	uint32_t getNextPtrPtr = stdStreamBuf->m_getNextPtrPtr;
	uint32_t readPosition = LOAD32(getNextPtrPtr);
	STORE32(getNextPtrPtr, readPosition + 1);
	return LOAD8(readPosition);
}
PROMOTED_ENTRY(45, sub_826C3CE8, 0x826C3CE8) { ctx.r3.u64 = CStdStreamBuf_Uflow(ctx, base, ctx.r3.u64); }

uint64_t CStdStreamBuf_GetAvailable(CpuState& ctx, uint8_t* base, uint32_t stdStreamBufAddr) {
	if (!UseLiftedCode(92, 0x82C72DE0)) { ctx.r3.u64 = stdStreamBufAddr; __imp__sub_82C72DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C72DE0);
	CStdStreamBuf* stdStreamBuf = GameObject<CStdStreamBuf>(base, stdStreamBufAddr);
	if (LOAD32(stdStreamBuf->m_getNextPtrPtr) == 0)
		return 0;
	return LOAD32(stdStreamBuf->m_getCountPtr);
}
PROMOTED_ENTRY(92, sub_82C72DE0, 0x82C72DE0) { ctx.r3.u64 = CStdStreamBuf_GetAvailable(ctx, base, ctx.r3.u32); }

uint64_t CStdStreamBuf_PutAvailable(CpuState& ctx, uint8_t* base, uint32_t stdStreamBufAddr) {
	if (!UseLiftedCode(92, 0x82C72EF8)) { ctx.r3.u64 = stdStreamBufAddr; __imp__sub_82C72EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C72EF8);
	CStdStreamBuf* stdStreamBuf = GameObject<CStdStreamBuf>(base, stdStreamBufAddr);
	if (LOAD32(stdStreamBuf->m_putNextPtrPtr) == 0)
		return 0;
	return LOAD32(stdStreamBuf->m_putCountPtr);
}
PROMOTED_ENTRY(92, sub_82C72EF8, 0x82C72EF8) { ctx.r3.u64 = CStdStreamBuf_PutAvailable(ctx, base, ctx.r3.u32); }
