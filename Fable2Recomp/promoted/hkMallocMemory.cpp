// hkMallocMemory (vtable 0x82006AD8): methods of the class as readable C++.
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

uint64_t hkMallocMemory_BlockAllocBatch(CpuState& ctx, uint8_t* base, uint64_t memory, uint64_t blockPointerArray, uint32_t blockCount, uint64_t blockSize) {
	if (!UseLiftedCode(38, 0x825EF4A0)) { ctx.r3.u64 = memory; ctx.r4.u64 = blockPointerArray; ctx.r5.u64 = blockCount; ctx.r6.u64 = blockSize; __imp__sub_825EF4A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF4A0);
	GameStackFrame stackFrame(ctx, base, 128);

	uint64_t lastBlock = memory;
	uint64_t secondResult = blockPointerArray;
	uint64_t carriedArg4 = blockSize;
	uint32_t outBlockPointer = (uint32_t)blockPointerArray;
	for (int32_t remaining = (int32_t)blockCount; remaining > 0; --remaining) {
		const uint32_t vtable = LOAD32((uint32_t)memory);
		const uint32_t allocateMethod = LOAD32(vtable + 12);
		ctx.r3.u64 = memory;
		ctx.r4.u64 = blockSize;
		ctx.r5.u64 = 0;
		ctx.r6.u64 = carriedArg4;
		ctx.r10.u64 = allocateMethod;
		REX_CALL_INDIRECT_FUNC(allocateMethod);
		lastBlock = ctx.r3.u64;
		secondResult = ctx.r4.u64;
		carriedArg4 = ctx.r6.u64;
		STORE32(outBlockPointer, (uint32_t)lastBlock);
		outBlockPointer += 4;
	}
	ctx.r4.u64 = secondResult;
	return lastBlock;
}
PROMOTED_ENTRY(38, sub_825EF4A0, 0x825EF4A0) { ctx.r3.u64 = hkMallocMemory_BlockAllocBatch(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64); }

uint64_t hkMallocMemory_BlockFreeBatch(CpuState& ctx, uint8_t* base, uint64_t memory, uint64_t blockPointerArray, uint32_t blockCount, uint64_t blockSize) {
	if (!UseLiftedCode(38, 0x825EF4F8)) { ctx.r3.u64 = memory; ctx.r4.u64 = blockPointerArray; ctx.r5.u64 = blockCount; ctx.r6.u64 = blockSize; __imp__sub_825EF4F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF4F8);
	GameStackFrame stackFrame(ctx, base, 128);

	uint64_t result = memory;
	uint64_t secondResult = blockPointerArray;
	uint32_t blockPointer = (uint32_t)blockPointerArray;
	for (int32_t remaining = (int32_t)blockCount; remaining > 0; --remaining) {
		const uint32_t block = LOAD32(blockPointer);
		const uint32_t vtable = LOAD32((uint32_t)memory);
		const uint32_t freeMethod = LOAD32(vtable + 16);
		ctx.r3.u64 = memory;
		ctx.r4.u64 = block;
		ctx.r5.u64 = blockSize;
		ctx.r6.u64 = 0;
		ctx.r10.u64 = freeMethod;
		REX_CALL_INDIRECT_FUNC(freeMethod);
		result = ctx.r3.u64;
		secondResult = ctx.r4.u64;
		blockPointer += 4;
	}
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(38, sub_825EF4F8, 0x825EF4F8) { ctx.r3.u64 = hkMallocMemory_BlockFreeBatch(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64); }

uint64_t hkMallocMemory_Allocate(CpuState& ctx, uint8_t* base, uint64_t size) {
	constexpr uint32_t allocateFunctionGlobal = 0x832F6C24;
	if (!UseLiftedCode(38, 0x825EF550)) { ctx.r4.u64 = size; __imp__sub_825EF550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF550);
	const uint32_t allocateFunction = LOAD32(allocateFunctionGlobal);
	ctx.r3.u64 = size;
	ctx.r4.u64 = 16;
	ctx.r10.u64 = allocateFunction;
	REX_CALL_INDIRECT_FUNC(allocateFunction);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(38, sub_825EF550, 0x825EF550) { ctx.r3.u64 = hkMallocMemory_Allocate(ctx, base, ctx.r4.u64); }

uint64_t hkMallocMemory_Deallocate(CpuState& ctx, uint8_t* base, uint64_t memoryBlock) {
	constexpr uint32_t freeFunctionGlobal = 0x832F6C28;
	if (!UseLiftedCode(38, 0x825EF568)) { ctx.r4.u64 = memoryBlock; __imp__sub_825EF568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF568);
	if ((uint32_t)memoryBlock == 0) {
		ctx.r4.u64 = memoryBlock;
		return ctx.r3.u64;
	}
	const uint32_t freeFunction = LOAD32(freeFunctionGlobal);
	ctx.r3.u64 = memoryBlock;
	ctx.r4.u64 = memoryBlock;
	ctx.r10.u64 = freeFunction;
	REX_CALL_INDIRECT_FUNC(freeFunction);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(38, sub_825EF568, 0x825EF568) { ctx.r3.u64 = hkMallocMemory_Deallocate(ctx, base, ctx.r4.u64); }

uint64_t n_sub_825EF588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820C5540_B_ = int32_t(0x820C5540);
	constexpr int32_t str_TXT_820C5578_B_ = int32_t(0x820C5578);
	constexpr uint32_t errorHandlerGlobal = 0x83337460;
	if (!UseLiftedCode(38, 0x825EF588)) { __imp__sub_825EF588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 624);
	ctx.r1.u64 = stack;

	const uint32_t errStream = stack + 80;
	const uint32_t messageBuffer = stack + 96;
	hkErrStream_ConstructWithBuffer(ctx, base, errStream, messageBuffer, 512);
	hkErrStream_WriteString(ctx, base, errStream, str_TXT_820C5540_B_);

	const uint32_t errorHandler = LOAD32(errorHandlerGlobal);
	const uint32_t handlerVtable = LOAD32(errorHandler);
	const uint32_t reportMethod = LOAD32(handlerVtable + 12);
	ctx.r3.u64 = errorHandler;
	ctx.r4.u64 = 1;
	ctx.r5.u64 = 0xFFFFFFFFAF55AD00ull;
	ctx.r6.u64 = messageBuffer;
	ctx.r7.u64 = (int64_t)str_TXT_820C5578_B_;
	ctx.r8.u64 = 58;
	ctx.r9.s64 = str_TXT_820C0000_B_;
	ctx.r10.u64 = reportMethod;
	REX_CALL_INDIRECT_FUNC(reportMethod);

	const uint64_t result = hkErrStream_Destructor(ctx, base, errStream);
	stack = PopStackFrame(stack, 624);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(38, sub_825EF588, 0x825EF588) { ctx.r3.u64 = n_sub_825EF588(ctx, base); }

uint64_t hkMallocMemory_AllocateAligned(CpuState& ctx, uint8_t* base, uint64_t memory, uint64_t size, uint64_t alignment) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820C55CC_B_ = int32_t(0x820C55CC);
	constexpr int32_t str_TXT_820C5578_B_ = int32_t(0x820C5578);
	constexpr uint32_t errorHandlerGlobal = 0x83337460;
	if (!UseLiftedCode(38, 0x825EF600)) { ctx.r3.u64 = memory; ctx.r4.u64 = size; ctx.r5.u64 = alignment; __imp__sub_825EF600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF600);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 640);
	ctx.r1.u64 = stack;

	const uint32_t errStream = stack + 80;
	const uint32_t messageBuffer = stack + 96;
	hkErrStream_ConstructWithBuffer(ctx, base, errStream, messageBuffer, 512);
	hkErrStream_WriteString(ctx, base, errStream, str_TXT_820C55CC_B_);

	const uint32_t errorHandler = LOAD32(errorHandlerGlobal);
	const uint32_t handlerVtable = LOAD32(errorHandler);
	const uint32_t reportMethod = LOAD32(handlerVtable + 12);
	ctx.r3.u64 = errorHandler;
	ctx.r4.u64 = 1;
	ctx.r5.u64 = 0xFFFFFFFFAF55AD01ull;
	ctx.r6.u64 = messageBuffer;
	ctx.r7.u64 = (int64_t)str_TXT_820C5578_B_;
	ctx.r8.u64 = 63;
	ctx.r9.s64 = str_TXT_820C0000_B_;
	ctx.r10.u64 = reportMethod;
	REX_CALL_INDIRECT_FUNC(reportMethod);

	hkErrStream_Destructor(ctx, base, errStream);

	const uint32_t memoryVtable = LOAD32((uint32_t)memory);
	const uint32_t allocateMethod = LOAD32(memoryVtable + 12);
	ctx.r3.u64 = memory;
	ctx.r4.u64 = size;
	ctx.r5.u64 = alignment;
	ctx.r8.u64 = allocateMethod;
	ctx.r9.u64 = memoryVtable;
	REX_CALL_INDIRECT_FUNC(allocateMethod);

	stack = PopStackFrame(stack, 640);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(38, sub_825EF600, 0x825EF600) { ctx.r3.u64 = hkMallocMemory_AllocateAligned(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t hkMallocMemory_DeallocateAligned(CpuState& ctx, uint8_t* base, uint64_t memory, uint64_t memoryBlock, uint64_t size, uint64_t alignment) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820C55CC_B_ = int32_t(0x820C55CC);
	constexpr int32_t str_TXT_820C5578_B_ = int32_t(0x820C5578);
	constexpr uint32_t errorHandlerGlobal = 0x83337460;
	if (!UseLiftedCode(38, 0x825EF698)) { ctx.r3.u64 = memory; ctx.r4.u64 = memoryBlock; ctx.r5.u64 = size; ctx.r6.u64 = alignment; __imp__sub_825EF698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF698);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 656);
	ctx.r1.u64 = stack;

	const uint32_t errStream = stack + 80;
	const uint32_t messageBuffer = stack + 96;
	hkErrStream_ConstructWithBuffer(ctx, base, errStream, messageBuffer, 512);
	hkErrStream_WriteString(ctx, base, errStream, str_TXT_820C55CC_B_);

	const uint32_t errorHandler = LOAD32(errorHandlerGlobal);
	const uint32_t handlerVtable = LOAD32(errorHandler);
	const uint32_t reportMethod = LOAD32(handlerVtable + 12);
	ctx.r3.u64 = errorHandler;
	ctx.r4.u64 = 1;
	ctx.r5.u64 = 0xFFFFFFFFAF55AD02ull;
	ctx.r6.u64 = messageBuffer;
	ctx.r7.u64 = (int64_t)str_TXT_820C5578_B_;
	ctx.r8.u64 = 70;
	ctx.r9.s64 = str_TXT_820C0000_B_;
	ctx.r10.u64 = reportMethod;
	REX_CALL_INDIRECT_FUNC(reportMethod);

	hkErrStream_Destructor(ctx, base, errStream);

	const uint32_t memoryVtable = LOAD32((uint32_t)memory);
	const uint32_t freeMethod = LOAD32(memoryVtable + 16);
	ctx.r3.u64 = memory;
	ctx.r4.u64 = memoryBlock;
	ctx.r5.u64 = size;
	ctx.r6.u64 = alignment;
	ctx.r8.u64 = freeMethod;
	ctx.r9.u64 = memoryVtable;
	REX_CALL_INDIRECT_FUNC(freeMethod);

	stack = PopStackFrame(stack, 656);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(38, sub_825EF698, 0x825EF698) { ctx.r3.u64 = hkMallocMemory_DeallocateAligned(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t n_sub_825EF738(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820C5540_B_ = int32_t(0x820C5540);
	constexpr int32_t str_TXT_820C5578_B_ = int32_t(0x820C5578);
	constexpr uint32_t errorHandlerGlobal = 0x83337460;
	if (!UseLiftedCode(38, 0x825EF738)) { __imp__sub_825EF738(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF738);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 624);
	ctx.r1.u64 = stack;

	const uint32_t errStream = stack + 80;
	const uint32_t messageBuffer = stack + 96;
	hkErrStream_ConstructWithBuffer(ctx, base, errStream, messageBuffer, 512);
	hkErrStream_WriteString(ctx, base, errStream, str_TXT_820C5540_B_);

	const uint32_t errorHandler = LOAD32(errorHandlerGlobal);
	const uint32_t handlerVtable = LOAD32(errorHandler);
	const uint32_t reportMethod = LOAD32(handlerVtable + 12);
	ctx.r3.u64 = errorHandler;
	ctx.r4.u64 = 1;
	ctx.r5.u64 = 0xFFFFFFFFAF55AD03ull;
	ctx.r6.u64 = messageBuffer;
	ctx.r7.u64 = (int64_t)str_TXT_820C5578_B_;
	ctx.r8.u64 = 76;
	ctx.r9.s64 = str_TXT_820C0000_B_;
	ctx.r10.u64 = reportMethod;
	REX_CALL_INDIRECT_FUNC(reportMethod);

	const uint64_t result = hkErrStream_Destructor(ctx, base, errStream);
	stack = PopStackFrame(stack, 624);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(38, sub_825EF738, 0x825EF738) { ctx.r3.u64 = n_sub_825EF738(ctx, base); }

uint64_t n_sub_825EF7B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820C5540_B_ = int32_t(0x820C5540);
	constexpr int32_t str_TXT_820C5578_B_ = int32_t(0x820C5578);
	constexpr uint32_t errorHandlerGlobal = 0x83337460;
	if (!UseLiftedCode(38, 0x825EF7B0)) { __imp__sub_825EF7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EF7B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 624);
	ctx.r1.u64 = stack;

	const uint32_t errStream = stack + 80;
	const uint32_t messageBuffer = stack + 96;
	hkErrStream_ConstructWithBuffer(ctx, base, errStream, messageBuffer, 512);
	hkErrStream_WriteString(ctx, base, errStream, str_TXT_820C5540_B_);

	const uint32_t errorHandler = LOAD32(errorHandlerGlobal);
	const uint32_t handlerVtable = LOAD32(errorHandler);
	const uint32_t reportMethod = LOAD32(handlerVtable + 12);
	ctx.r3.u64 = errorHandler;
	ctx.r4.u64 = 1;
	ctx.r5.u64 = 0xFFFFFFFFAF55AD03ull;
	ctx.r6.u64 = messageBuffer;
	ctx.r7.u64 = (int64_t)str_TXT_820C5578_B_;
	ctx.r8.u64 = 81;
	ctx.r9.s64 = str_TXT_820C0000_B_;
	ctx.r10.u64 = reportMethod;
	REX_CALL_INDIRECT_FUNC(reportMethod);

	const uint64_t result = hkErrStream_Destructor(ctx, base, errStream);
	stack = PopStackFrame(stack, 624);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(38, sub_825EF7B0, 0x825EF7B0) { ctx.r3.u64 = n_sub_825EF7B0(ctx, base); }

uint64_t hkMallocMemory_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t memory, uint64_t deleteFlags) {
	constexpr uint32_t freeFunctionGlobal = 0x832F6C28;
	if (!UseLiftedCode(38, 0x825F07D0)) { ctx.r3.u64 = memory; ctx.r4.u64 = deleteFlags; __imp__sub_825F07D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825F07D0);
	GameStackFrame stackFrame(ctx, base, 112);

	hkMemory_BaseConstructor(ctx, base, memory);

	uint64_t secondResult = deleteFlags;
	if ((uint32_t(deleteFlags) & 1) != 0) {
		const uint32_t freeFunction = LOAD32(freeFunctionGlobal);
		ctx.r3.u64 = memory;
		ctx.r4.u64 = deleteFlags;
		ctx.r10.u64 = freeFunction;
		REX_CALL_INDIRECT_FUNC(freeFunction);
		secondResult = ctx.r4.u64;
	}
	ctx.r4.u64 = secondResult;
	return memory;
}
PROMOTED_ENTRY(38, sub_825F07D0, 0x825F07D0) { ctx.r3.u64 = hkMallocMemory_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
