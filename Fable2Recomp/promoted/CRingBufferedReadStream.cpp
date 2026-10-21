// CRingBufferedReadStream (vtable 0x8200E4B8): methods of the class as readable C++.
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

uint64_t CRingBufferedReadStream_GetRemainingLength(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr, uint32_t remainingLengthOut) {
	if (!UseLiftedCode(93, 0x82C7CC28)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = remainingLengthOut; __imp__sub_82C7CC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7CC28);
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	uint32_t stream = ringBufferedReadStream->m_Stream;
	uint32_t remainingBytes = MemoryFile_GetRemainingBytes(ctx, base, stream);
	STORE32(remainingLengthOut, remainingBytes);
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7CC28, 0x82C7CC28) { ctx.r3.u64 = CRingBufferedReadStream_GetRemainingLength(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CRingBufferedReadStream_GetBufferedBytesRead(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr, uint32_t bufferedBytesReadOut) {
	if (!UseLiftedCode(93, 0x82C7CC60)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = bufferedBytesReadOut; __imp__sub_82C7CC60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7CC60);
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	STORE64(bufferedBytesReadOut, ringBufferedReadStream->m_BufferedBytesRead);
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7CC60, 0x82C7CC60) { ctx.r3.u64 = CRingBufferedReadStream_GetBufferedBytesRead(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CRingBufferedReadStream_GetDirectBytesRead(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr, uint32_t directBytesReadOut) {
	if (!UseLiftedCode(93, 0x82C7CC70)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = directBytesReadOut; __imp__sub_82C7CC70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7CC70);
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	uint64_t directBytesRead = ringBufferedReadStream->m_DirectBytesRead;
	STORE64(directBytesReadOut, directBytesRead);
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7CC70, 0x82C7CC70) { ctx.r3.u64 = CRingBufferedReadStream_GetDirectBytesRead(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CRingBufferedReadStream_IsOpen(CpuState& ctx, uint8_t* base, uint64_t ringBufferedReadStreamAddr, uint32_t isOpenOut) {
	if (!UseLiftedCode(93, 0x82C7CC80)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = isOpenOut; __imp__sub_82C7CC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7CC80);
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, uint32_t(ringBufferedReadStreamAddr));
	GameStackFrame stackFrame(ctx, base, 96);
	uint32_t stream = ringBufferedReadStream->m_Stream;
	uint32_t isOpen = CMemoryFile_IsOpen(ctx, base, stream);
	STORE32(isOpenOut, (isOpen & 0xFF) != 0 ? 1u : 0u);
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7CC80, 0x82C7CC80) { ctx.r3.u64 = CRingBufferedReadStream_IsOpen(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CRingBufferedReadStream_ReadDirect(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr, uint64_t buffer, uint32_t sizePtr, uint32_t flags) {
	if (!UseLiftedCode(93, 0x82C7CCC8)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = buffer; ctx.r5.u64 = sizePtr; ctx.r6.u64 = flags; __imp__sub_82C7CCC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7CCC8);
	constexpr uint64_t kResultFail = 0xFFFFFFFF80004005ull;   // E_FAIL, sign-extended
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	GameStackFrame stackFrame(ctx, base, 128);

	uint32_t isOpen = CMemoryFile_IsOpen(ctx, base, ringBufferedReadStream->m_Stream);
	if ((isOpen & 0xFF) == 0) {
		ctx.r4.u64 = buffer;
		return kResultFail;
	}

	uint32_t requestedBytes = LOAD32(sizePtr);
	// flags 0: the memory file keeps reading until the whole request has come
	uint32_t readWholeRequest = flags == 0 ? 1u : 0u;
	uint64_t bytesRead = MemoryFile_Read(ctx, base, ringBufferedReadStream->m_Stream, buffer, requestedBytes, readWholeRequest);
	if ((int32_t)bytesRead == -1) {
		STORE32(sizePtr, 0u);
		return kResultFail;
	}

	ringBufferedReadStream->m_DirectBytesRead = (bytesRead & 0xFFFFFFFF) + ringBufferedReadStream->m_DirectBytesRead;
	STORE32(sizePtr, (uint32_t)bytesRead);
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7CCC8, 0x82C7CCC8) { ctx.r3.u64 = CRingBufferedReadStream_ReadDirect(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32); }

uint64_t CRingBufferedReadStream_Close(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr) {
	if (!UseLiftedCode(93, 0x82C7CD68)) { ctx.r3.u64 = ringBufferedReadStreamAddr; __imp__sub_82C7CD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7CD68);
	uint32_t stack = ctx.r1.u32;
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t stream = ringBufferedReadStream->m_Stream;
	if (stream != 0) {
		ctx.r1.u64 = stack;
		uint32_t isOpen = CMemoryFile_IsOpen(ctx, base, stream);
		if ((isOpen & 0xFF) != 0) {
			uint32_t stream2 = ringBufferedReadStream->m_Stream;
			MemoryFile_Close(ctx, base, stream2);
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7CD68, 0x82C7CD68) { ctx.r3.u64 = CRingBufferedReadStream_Close(ctx, base, ctx.r3.u32); }

uint32_t CRingBufferedReadStream_Destructor(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr) {
	constexpr int32_t CRingBufferedReadStream_vtable = int32_t(0x8200E4B8);
	if (!UseLiftedCode(93, 0x82C7CDB8)) { ctx.r3.u64 = ringBufferedReadStreamAddr; __imp__sub_82C7CDB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C7CDB8);
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	uint32_t stream = ringBufferedReadStream->m_Stream;
	ringBufferedReadStream->vtable = uint32_t(CRingBufferedReadStream_vtable);
	if (stream != 0) {
		ctx.r10.u64 = uint64_t(int64_t(CRingBufferedReadStream_vtable));
		MemoryFile_Destructor(ctx, base, stream);
		HandleTarget_FreeThunk(ctx, base, stream);
	}
	uint32_t ring = ringBufferedReadStream->m_Ring;
	HandleTarget_FreeThunk(ctx, base, ring);
	uint32_t bufferMemory = ringBufferedReadStream->m_BufferMemory;
	HandleTarget_FreeThunk(ctx, base, bufferMemory);
	CBinaryDataStream_Destructor(ctx, base, ringBufferedReadStreamAddr);
	return ringBufferedReadStreamAddr;
}
PROMOTED_ENTRY(93, sub_82C7CDB8, 0x82C7CDB8) { ctx.r3.u64 = CRingBufferedReadStream_Destructor(ctx, base, ctx.r3.u32); }

uint64_t CRingBufferedReadStream_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t ringBufferedReadStreamAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(93, 0x82C7CF20)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82C7CF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7CF20);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CRingBufferedReadStream_Destructor(ctx, base, ringBufferedReadStreamAddr);
	if ((deleteFlags & 1) != 0) {
		HandleTarget_FreeThunk(ctx, base, ringBufferedReadStreamAddr);
	}
	return ringBufferedReadStreamAddr;
}
PROMOTED_ENTRY(93, sub_82C7CF20, 0x82C7CF20) { ctx.r3.u64 = CRingBufferedReadStream_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CRingBufferedReadStream_FillBuffer(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr) {
	if (!UseLiftedCode(93, 0x82C7CF70)) { ctx.r3.u64 = ringBufferedReadStreamAddr; __imp__sub_82C7CF70(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C7CF70);
	uint32_t stack = ctx.r1.u64;
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	stack = PushStackFrame(base, stack, 128);

	// The ring's block: +0 capacity, +4 write offset, +12 bytes stored, the data from +16.
	uint32_t totalBytesRead = 0;
	for (;;) {
		uint32_t ring = ringBufferedReadStream->m_Ring;
		uint32_t block = LOAD32(ring);
		uint32_t capacity = LOAD32(block);
		uint32_t storedBytes = LOAD32(block + 12);
		uint32_t writeOffset = LOAD32(block + 4);
		uint32_t freeBytes = capacity - storedBytes;
		uint32_t bytesToEnd = capacity - writeOffset;
		STORE32(stack + 80, freeBytes);
		STORE32(stack + 84, bytesToEnd);
		uint32_t readSize = (int32_t)freeBytes < (int32_t)bytesToEnd ? freeBytes : bytesToEnd;
		uint32_t writePosition = block + writeOffset + 16;
		uint32_t stream = ringBufferedReadStream->m_Stream;

		ctx.r1.u64 = stack;
		ctx.r7.u64 = writeOffset;
		ctx.r8.u64 = storedBytes;
		ctx.r9.u64 = bytesToEnd;
		uint32_t bytesRead = n_sub_82C7D700(ctx, base, stream, writePosition, readSize, 0);
		if ((int32_t)bytesRead == -1) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return 0xFFFFFFFF;
		}
		if (bytesRead == 0) {
			// nothing came: read one byte, the memory file looping until it has come
			stream = ringBufferedReadStream->m_Stream;
			bytesRead = n_sub_82C7D700(ctx, base, stream, writePosition, 1, 1);
		}

		ring = ringBufferedReadStream->m_Ring;
		totalBytesRead += bytesRead;
		block = LOAD32(ring);
		uint32_t newWriteOffset = LOAD32(block + 4) + bytesRead;
		if ((int32_t)newWriteOffset > (int32_t)LOAD32(block)) {
			ppc_trap(ctx, base, 22);
		}
		capacity = LOAD32(block);
		STORE32(block + 4, (int32_t)newWriteOffset == (int32_t)capacity ? 0u : newWriteOffset);
		block = LOAD32(ring);
		STORE32(block + 12, LOAD32(block + 12) + bytesRead);

		if (totalBytesRead != 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			ctx.r8.u64 = capacity;
			ctx.r9.u64 = ring;
			return totalBytesRead;
		}
	}
}
PROMOTED_ENTRY(93, sub_82C7CF70, 0x82C7CF70) { ctx.r3.u64 = CRingBufferedReadStream_FillBuffer(ctx, base, ctx.r3.u32); }

uint64_t CRingBufferedReadStream_GetAvailableBytes(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr, uint64_t availableBytesOut) {
	if (!UseLiftedCode(93, 0x82C7D078)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = availableBytesOut; __imp__sub_82C7D078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7D078);
	constexpr uint64_t kResultFail = 0xFFFFFFFF80004005ull;   // E_FAIL, sign-extended
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	uint32_t availableBytesOutAddr = (uint32_t)availableBytesOut;
	GameStackFrame stackFrame(ctx, base, 112);

	// +12 of the ring's block: the bytes stored and not yet read
	uint32_t storedBytes = LOAD32(LOAD32(uint32_t(ringBufferedReadStream->m_Ring)) + 12);
	if (storedBytes == 0) {
		uint32_t stream = ringBufferedReadStream->m_Stream;
		uint32_t position = MemoryFile_GetPosition(ctx, base, stream);
		if (position != 0) {
			ctx.r4.u64 = availableBytesOut;
			uint32_t fillResult = CRingBufferedReadStream_FillBuffer(ctx, base, ringBufferedReadStreamAddr);
			if ((int32_t)fillResult == -1) {
				STORE32(availableBytesOutAddr, 0u);
				return kResultFail;
			}
			STORE32(availableBytesOutAddr, LOAD32(LOAD32(uint32_t(ringBufferedReadStream->m_Ring)) + 12));
			return 0;
		}
	}

	STORE32(availableBytesOutAddr, storedBytes);
	ctx.r4.u64 = availableBytesOut;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7D078, 0x82C7D078) { ctx.r3.u64 = CRingBufferedReadStream_GetAvailableBytes(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CRingBufferedReadStream_Read(CpuState& ctx, uint8_t* base, uint32_t ringBufferedReadStreamAddr, uint64_t buffer, uint32_t sizePtr, uint32_t flags) {
	if (!UseLiftedCode(93, 0x82C7D108)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = buffer; ctx.r5.u64 = sizePtr; ctx.r6.u64 = flags; __imp__sub_82C7D108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7D108);
	constexpr uint64_t kResultFail = 0xFFFFFFFF80004005ull;   // E_FAIL, sign-extended
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	GameStackFrame stackFrame(ctx, base, 128);

	auto fail = [&]() -> uint64_t {
		STORE32(sizePtr, 0u);
		return kResultFail;
	};

	uint32_t stream = ringBufferedReadStream->m_Stream;
	uint32_t isOpen = CMemoryFile_IsOpen(ctx, base, stream);
	if ((isOpen & 0xFF) == 0) {
		ctx.r4.u64 = buffer;
		return fail();
	}

	// +12 of the ring's block: the bytes stored and not yet read
	uint32_t storedBytes = LOAD32(LOAD32(uint32_t(ringBufferedReadStream->m_Ring)) + 12);
	// r6 and r9 at the first ring read: the flags and the stored byte count, or what the fill left there
	uint32_t handOverFlags = flags;
	uint32_t handOverStoredBytes = storedBytes;
	if ((int32_t)storedBytes == 0) {
		ctx.r4.u64 = buffer;
		ctx.r6.u64 = flags;
		ctx.r9.u64 = storedBytes;
		uint32_t fillResult = CRingBufferedReadStream_FillBuffer(ctx, base, ringBufferedReadStreamAddr);
		handOverFlags = ctx.r6.u32;
		handOverStoredBytes = ctx.r9.u32;
		if ((int32_t)fillResult == -1)
			return fail();
	}

	uint32_t requestedBytes = LOAD32(sizePtr);
	uint32_t ring = ringBufferedReadStream->m_Ring;
	ctx.r6.u64 = handOverFlags;
	ctx.r9.u64 = handOverStoredBytes;
	uint64_t bytesRead = RingBuffer_Read_82C7CE28(ctx, base, ring, (uint32_t)buffer, requestedBytes);

	// flags 0: refill and read until the whole request has been copied
	if (flags == 0 && (uint32_t)bytesRead < LOAD32(sizePtr)) {
		uint64_t destination = bytesRead + buffer;
		do {
			uint32_t remainingBytes = (uint32_t)((uint64_t)LOAD32(sizePtr) - bytesRead);
			uint32_t fillResult = CRingBufferedReadStream_FillBuffer(ctx, base, ringBufferedReadStreamAddr);
			if ((int32_t)fillResult == -1)
				return fail();
			ring = ringBufferedReadStream->m_Ring;
			uint64_t chunkRead = RingBuffer_Read_82C7CE28(ctx, base, ring, (uint32_t)destination, remainingBytes);
			if ((int32_t)chunkRead == -1)
				return fail();
			bytesRead = chunkRead + bytesRead;
			destination = chunkRead + destination;
		} while ((uint32_t)bytesRead < LOAD32(sizePtr));
	}

	ringBufferedReadStream->m_BufferedBytesRead = (bytesRead & 0xFFFFFFFF) + ringBufferedReadStream->m_BufferedBytesRead;
	STORE32(sizePtr, (uint32_t)bytesRead);
	return 0;
}
PROMOTED_ENTRY(93, sub_82C7D108, 0x82C7D108) { ctx.r3.u64 = CRingBufferedReadStream_Read(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32); }

uint64_t CRingBufferedReadStream_Constructor(CpuState& ctx, uint8_t* base, uint64_t ringBufferedReadStreamAddr, uint64_t sourceStream) {
	if (!UseLiftedCode(93, 0x82C7D208)) { ctx.r3.u64 = ringBufferedReadStreamAddr; ctx.r4.u64 = sourceStream; __imp__sub_82C7D208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C7D208);
	constexpr uint32_t CRingBufferedReadStream_vtable = 0x8200E4B8u;
	CRingBufferedReadStream* ringBufferedReadStream = GameObject<CRingBufferedReadStream>(base, ringBufferedReadStreamAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	ringBufferedReadStream->m_4 = 0u;
	ringBufferedReadStream->vtable = CRingBufferedReadStream_vtable;
	ringBufferedReadStream->m_Stream = (uint32_t)sourceStream;
	ringBufferedReadStream->m_DirectBytesRead = 0;
	ringBufferedReadStream->m_BufferedBytesRead = 0;

	ctx.r4.u64 = sourceStream;
	uint32_t bufferMemory = operator_new(ctx, base, 0x20000u);
	ringBufferedReadStream->m_BufferMemory = bufferMemory;

	// The ring: a word pointing at its block (the buffer memory), whose header the stores below set up.
	uint32_t ring = operator_new(ctx, base, 8u);
	if (ring != 0) {
		uint32_t block = ringBufferedReadStream->m_BufferMemory;
		STORE32(ring, block);
		STORE32(block, 0x1FFF0u);   // capacity: the 128 KiB block less its 16-byte header
		STORE32(LOAD32(ring) + 12, 0u);
		STORE32(LOAD32(ring) + 8, 0u);
		STORE32(LOAD32(ring) + 4, 0u);
	}
	ringBufferedReadStream->m_Ring = ring;
	return ringBufferedReadStreamAddr;
}
PROMOTED_ENTRY(93, sub_82C7D208, 0x82C7D208) { ctx.r3.u64 = CRingBufferedReadStream_Constructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
