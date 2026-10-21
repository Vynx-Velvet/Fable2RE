// CMemoryFile (vtable 0x820ABCC0): methods of the class as readable C++.
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

uint64_t CMemoryFile_Dtor(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr, uint64_t forwardedArg) {
	constexpr int32_t CMemoryFile_vtable = int32_t(0x820ABCC0);
	constexpr int32_t baseClassVtable = int32_t(0x820A6A08);
	if (!UseLiftedCode(20, 0x823A5340)) { ctx.r3.u64 = memoryFileAddr; ctx.r8.u64 = forwardedArg; __imp__sub_823A5340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823A5340);
	GameStackFrame stackFrame(ctx, base, 112);
	CMemoryFile* memoryFile = GameObject<CMemoryFile>(base, memoryFileAddr);

	memoryFile->vtable = (uint32_t)CMemoryFile_vtable;
	CMemoryFile_Close(ctx, base, memoryFileAddr, forwardedArg);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, memoryFileAddr + 36);

	uint64_t dataBegin = memoryFile->m_dataBegin;
	uint64_t result = dataBegin;
	if ((uint32_t)dataBegin != 0) {
		result = HandleTarget_Free(ctx, base, dataBegin);
	}
	memoryFile->m_dataBegin = 0;
	memoryFile->m_18 = 0;
	memoryFile->m_1C = 0;
	memoryFile->vtable = (uint32_t)baseClassVtable;

	ctx.r9.u64 = (uint64_t)(int64_t)baseClassVtable;
	return result;
}
PROMOTED_ENTRY(20, sub_823A5340, 0x823A5340) { ctx.r3.u64 = CMemoryFile_Dtor(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t CMemoryFile_GetName(CpuState& ctx, uint8_t* base, uint64_t nameOut, uint64_t memoryFileAddr) {
	if (!UseLiftedCode(20, 0x823A53B8)) { ctx.r3.u64 = nameOut; ctx.r4.u64 = memoryFileAddr; __imp__sub_823A53B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823A53B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t fileName = memoryFileAddr + 36;
	CCharString_CopyConstruct(ctx, base, nameOut, fileName);
	return nameOut;
}
PROMOTED_ENTRY(20, sub_823A53B8, 0x823A53B8) { ctx.r3.u64 = CMemoryFile_GetName(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CMemoryFile_DeletingDtor(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr, uint64_t deleteFlags, uint64_t forwardedArg) {
	if (!UseLiftedCode(20, 0x823A53F0)) { ctx.r3.u64 = memoryFileAddr; ctx.r4.u64 = deleteFlags; ctx.r8.u64 = forwardedArg; __imp__sub_823A53F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823A53F0);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CMemoryFile_Dtor(ctx, base, memoryFileAddr, forwardedArg);
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, memoryFileAddr);
	}
	return memoryFileAddr;
}
PROMOTED_ENTRY(20, sub_823A53F0, 0x823A53F0) { ctx.r3.u64 = CMemoryFile_DeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CMemoryFile_IsOpen(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr) {
	if (!UseLiftedCode(47, 0x826F97C0)) { ctx.r3.u64 = memoryFileAddr; __imp__sub_826F97C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826F97C0);
	return GameObject<CMemoryFile>(base, memoryFileAddr)->m_isOpen;
}
PROMOTED_ENTRY(47, sub_826F97C0, 0x826F97C0) { ctx.r3.u64 = CMemoryFile_IsOpen(ctx, base, ctx.r3.u64); }

uint64_t CMemoryFile_Open(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr, uint64_t fileName, uint64_t openMode, uint64_t openFlags) {
	constexpr int32_t str_TXT_820F8F48_B_ = int32_t(0x820F8F48);
	constexpr int32_t errorThrowInfo = int32_t(0x8210A938);
	if (!UseLiftedCode(83, 0x82B4A230)) { ctx.r3.u64 = memoryFileAddr; ctx.r4.u64 = fileName; ctx.r5.u64 = openMode; ctx.r6.u64 = openFlags; __imp__sub_82B4A230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B4A230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 176);
	const uint32_t fillByte = stack + 80;
	const uint32_t fullPath = stack + 84;
	const uint32_t rootPath = stack + 88;
	const uint32_t errorRecord = stack + 88;
	const uint32_t errorMessage = stack + 92;
	const uint32_t bufferedFileAddr = stack + 96;
	CMemoryFile* memoryFile = GameObject<CMemoryFile>(base, memoryFileAddr);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = fileName;
	ctx.r6.u64 = openFlags;
	uint64_t gameRoot = GetGameRootPath(ctx, base, rootPath);
	BuildGameFilePath(ctx, base, fullPath, fileName, gameRoot);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, rootPath);
	uint8_t fileExists = (uint8_t)FileExists(ctx, base, fullPath, ctx.r8.u64);

	uint64_t targetAddr = memoryFileAddr;
	if (fileExists != 0) {
		CMemoryFile_Construct_82B3FCF8(ctx, base, bufferedFileAddr, fileName, openMode, openFlags);
		STORE8(fillByte, 0);
		uint32_t fileLength = GameObject<CBufferedFile>(base, bufferedFileAddr)->m_Length;
		memoryFile->m_size = fileLength;
		Vector_Resize(ctx, base, memoryFileAddr + 16, fileLength, fillByte, ctx.r8.u64);
		if ((int32_t)memoryFile->m_size > 0) {
			CBufferedFile_Read(ctx, base, bufferedFileAddr, memoryFile->m_dataBegin, fileLength);
		}
		memoryFile->m_mode = (uint32_t)openMode;
		CMemoryFile_Destruct(ctx, base, bufferedFileAddr);
	} else {
		if ((int32_t)openMode == 1) {
			memoryFile->m_position = 0;
			memoryFile->m_size = 0;
			memoryFile->m_isOpen = 0;
			// From here on the original addresses the path temporary at stack + 84 instead of the object.
			targetAddr = fullPath;
			uint64_t prefix = CCharString_ConstructFromCStr(ctx, base, errorRecord, str_TXT_820F8F48_B_, -1);
			LocalisedString_Assign(ctx, base, errorMessage, prefix, fullPath);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, errorRecord);
			STORE32(errorRecord, 10u);
			RaiseError(ctx, base, errorRecord, errorThrowInfo);
		}
		GameObject<CMemoryFile>(base, targetAddr)->m_mode = (uint32_t)openMode;
	}

	CMemoryFile* target = GameObject<CMemoryFile>(base, targetAddr);
	CCharString_Assign(ctx, base, targetAddr + 36, fileName);
	target->m_position = 0;
	target->m_size = target->m_18 - target->m_dataBegin;
	target->m_isOpen = 1;
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, fullPath);

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B4A230, 0x82B4A230) { ctx.r3.u64 = CMemoryFile_Open(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CMemoryFile_Close(CpuState& ctx, uint8_t* base, uint32_t memoryFileAddr, uint64_t forwardedArg) {
	if (!UseLiftedCode(83, 0x82B4A380)) { ctx.r3.u64 = memoryFileAddr; ctx.r8.u64 = forwardedArg; __imp__sub_82B4A380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B4A380);
	GameStackFrame stackFrame(ctx, base, 112);
	CMemoryFile* memoryFile = GameObject<CMemoryFile>(base, memoryFileAddr);

	memoryFile->m_isOpen = 0;
	CMemoryFile_Clear(ctx, base, memoryFileAddr + 16, forwardedArg);

	uint64_t dataBegin = memoryFile->m_dataBegin;
	memoryFile->m_dataBegin = 0;
	memoryFile->m_18 = 0;
	memoryFile->m_1C = 0;
	if ((uint32_t)dataBegin != 0) {
		return HandleTarget_Free(ctx, base, dataBegin);
	}
	return dataBegin;
}
PROMOTED_ENTRY(83, sub_82B4A380, 0x82B4A380) { ctx.r3.u64 = CMemoryFile_Close(ctx, base, ctx.r3.u32, ctx.r8.u64); }

uint64_t CMemoryFile_Read(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr, uint64_t destBuffer, uint32_t byteCount) {
	constexpr int32_t emptyCStringPage = int32_t(0x82000000);
	constexpr int32_t emptyCString = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820F8C14_B_ = int32_t(0x820F8C14);
	constexpr int32_t str_TXT_820F8F60_B_ = int32_t(0x820F8F60);
	constexpr int32_t errorThrowInfo = int32_t(0x8210A938);
	if (!UseLiftedCode(83, 0x82B4A3E0)) { ctx.r3.u64 = memoryFileAddr; ctx.r4.u64 = destBuffer; ctx.r5.u64 = byteCount; __imp__sub_82B4A3E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B4A3E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	const uint32_t stringSlot = stack + 80;
	const uint32_t errorRecord = stack + 84;

	// Should RaiseError come back, the original goes on with the values it leaves in the registers.
	uint64_t fileAddr = memoryFileAddr;
	uint64_t destForCaller = destBuffer;
	uint32_t writeAddr = (uint32_t)destBuffer;
	uint32_t remaining = byteCount;

	if (writeAddr == 0) {
		ctx.r1.u64 = stack;
		ctx.r11.s64 = emptyCStringPage;
		uint64_t emptyText = CCharString_ConstructFromCStr(ctx, base, errorRecord, emptyCString, -1);
		CCharString_CopyConstruct(ctx, base, stringSlot, emptyText);
		CCharString_AssignCString(ctx, base, stringSlot, str_TXT_820F8C14_B_);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, errorRecord);
		STORE32(errorRecord, 1u);
		ctx.r9.u64 = 1;
		fileAddr = RaiseError(ctx, base, errorRecord, errorThrowInfo);
		destForCaller = ctx.r4.u64;
		writeAddr = ctx.r9.u32;
		remaining = ctx.r11.u32;
	}
	if ((int32_t)remaining != 0) {
		uint32_t fileSize = GameObject<CMemoryFile>(base, fileAddr)->m_size;
		uint32_t position = GameObject<CMemoryFile>(base, fileAddr)->m_position;
		if ((int32_t)(position + remaining) > (int32_t)fileSize) {
			ctx.r1.u64 = stack;
			ctx.r8.u64 = fileSize;
			ctx.r11.s64 = emptyCStringPage;
			uint64_t emptyText = CCharString_ConstructFromCStr(ctx, base, stringSlot, emptyCString, -1);
			CCharString_CopyConstruct(ctx, base, errorRecord, emptyText);
			CCharString_AssignCString(ctx, base, errorRecord, str_TXT_820F8F60_B_);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stringSlot);
			STORE32(errorRecord, 3u);
			ctx.r9.u64 = 3;
			fileAddr = RaiseError(ctx, base, errorRecord, errorThrowInfo);
			destForCaller = ctx.r4.u64;
			writeAddr = ctx.r9.u32;
			remaining = ctx.r11.u32;
		}
		if ((int32_t)remaining > 0) {
			CMemoryFile* memoryFile = GameObject<CMemoryFile>(base, fileAddr);
			for (uint32_t left = remaining; left != 0; --left) {
				uint32_t readPosition = memoryFile->m_position;
				uint32_t data = memoryFile->m_dataBegin;
				memoryFile->m_position = readPosition + 1;
				STORE8(writeAddr, LOAD8(data + readPosition));
				++writeAddr;
			}
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = destForCaller;
	return fileAddr;
}
PROMOTED_ENTRY(83, sub_82B4A3E0, 0x82B4A3E0) { ctx.r3.u64 = CMemoryFile_Read(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CMemoryFile_SeekAbsolute(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr, uint64_t seekPosition) {
	constexpr int32_t emptyCString = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820F8C98_B_ = int32_t(0x820F8C98);
	constexpr int32_t errorThrowInfo = int32_t(0x8210A938);
	if (!UseLiftedCode(83, 0x82B4A630)) { ctx.r3.u64 = memoryFileAddr; ctx.r4.u64 = seekPosition; __imp__sub_82B4A630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B4A630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	const uint32_t stringSlot = stack + 80;
	const uint32_t errorRecord = stack + 84;

	// Should RaiseError come back, the original goes on with the values it leaves in the registers.
	uint64_t fileAddr = memoryFileAddr;
	uint64_t newPosition = seekPosition;
	if ((int32_t)seekPosition > (int32_t)GameObject<CMemoryFile>(base, memoryFileAddr)->m_size) {
		ctx.r1.u64 = stack;
		uint64_t emptyText = CCharString_ConstructFromCStr(ctx, base, errorRecord, emptyCString, -1);
		CCharString_CopyConstruct(ctx, base, stringSlot, emptyText);
		CCharString_AssignCString(ctx, base, stringSlot, str_TXT_820F8C98_B_);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, errorRecord);
		STORE32(errorRecord, 11u);
		fileAddr = RaiseError(ctx, base, errorRecord, errorThrowInfo);
		newPosition = ctx.r4.u64;
	}
	GameObject<CMemoryFile>(base, fileAddr)->m_position = (uint32_t)newPosition;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = newPosition;
	return fileAddr;
}
PROMOTED_ENTRY(83, sub_82B4A630, 0x82B4A630) { ctx.r3.u64 = CMemoryFile_SeekAbsolute(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CMemoryFile_SeekRelative(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr, uint64_t byteOffset) {
	constexpr int32_t emptyCStringPage = int32_t(0x82000000);
	constexpr int32_t emptyCString = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820F8C98_B_ = int32_t(0x820F8C98);
	constexpr int32_t str_TXT_820F8CB8_B_ = int32_t(0x820F8CB8);
	constexpr int32_t errorThrowInfoPage = int32_t(0x82110000);
	constexpr int32_t errorThrowInfo = int32_t(0x8210A938);
	if (!UseLiftedCode(83, 0x82B4A6B0)) { ctx.r3.u64 = memoryFileAddr; ctx.r4.u64 = byteOffset; __imp__sub_82B4A6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B4A6B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	const uint32_t stringSlot = stack + 80;
	const uint32_t errorRecord = stack + 84;

	// Should RaiseError come back, the original goes on with the values it leaves in the registers.
	uint64_t fileAddr = memoryFileAddr;
	uint64_t offsetForCaller = byteOffset;
	uint32_t newPosition = GameObject<CMemoryFile>(base, memoryFileAddr)->m_position + (uint32_t)byteOffset;

	if ((int32_t)newPosition < 0) {
		ctx.r1.u64 = stack;
		ctx.r11.s64 = emptyCStringPage;
		uint64_t emptyText = CCharString_ConstructFromCStr(ctx, base, errorRecord, emptyCString, -1);
		CCharString_CopyConstruct(ctx, base, stringSlot, emptyText);
		CCharString_AssignCString(ctx, base, stringSlot, str_TXT_820F8CB8_B_);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, errorRecord);
		STORE32(errorRecord, 11u);
		ctx.r8.s64 = errorThrowInfoPage;
		fileAddr = RaiseError(ctx, base, errorRecord, errorThrowInfo);
		offsetForCaller = ctx.r4.u64;
		newPosition = ctx.r11.u32;
	}
	if ((int32_t)newPosition > (int32_t)GameObject<CMemoryFile>(base, fileAddr)->m_size) {
		ctx.r1.u64 = stack;
		ctx.r11.s64 = emptyCStringPage;
		uint64_t emptyText = CCharString_ConstructFromCStr(ctx, base, stringSlot, emptyCString, -1);
		CCharString_CopyConstruct(ctx, base, errorRecord, emptyText);
		CCharString_AssignCString(ctx, base, errorRecord, str_TXT_820F8C98_B_);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stringSlot);
		STORE32(errorRecord, 11u);
		fileAddr = RaiseError(ctx, base, errorRecord, errorThrowInfo);
		offsetForCaller = ctx.r4.u64;
		newPosition = ctx.r11.u32;
	}
	GameObject<CMemoryFile>(base, fileAddr)->m_position = newPosition;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = offsetForCaller;
	return fileAddr;
}
PROMOTED_ENTRY(83, sub_82B4A6B0, 0x82B4A6B0) { ctx.r3.u64 = CMemoryFile_SeekRelative(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CMemoryFile_SetSize(CpuState& ctx, uint8_t* base, uint64_t memoryFileAddr, uint64_t newSize, uint64_t forwardedArg) {
	if (!UseLiftedCode(83, 0x82B4A788)) { ctx.r3.u64 = memoryFileAddr; ctx.r4.u64 = newSize; ctx.r8.u64 = forwardedArg; __imp__sub_82B4A788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B4A788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	const uint32_t fillByte = stack + 80;
	CMemoryFile* memoryFile = GameObject<CMemoryFile>(base, memoryFileAddr);

	uint64_t result = memoryFileAddr;
	uint64_t sizeForCaller = newSize;
	if ((int32_t)newSize >= (int32_t)memoryFile->m_size) {
		memoryFile->m_size = (uint32_t)newSize;
		STORE8(fillByte, 0);
		ctx.r1.u64 = stack;
		result = Vector_Resize(ctx, base, memoryFileAddr + 16, newSize, fillByte, forwardedArg);
		sizeForCaller = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = sizeForCaller;
	return result;
}
PROMOTED_ENTRY(83, sub_82B4A788, 0x82B4A788) { ctx.r3.u64 = CMemoryFile_SetSize(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CMemoryFile_Create(CpuState& ctx, uint8_t* base, uint64_t source) {
	if (!UseLiftedCode(83, 0x82B4A848)) { ctx.r3.u64 = source; __imp__sub_82B4A848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B4A848);
	GameStackFrame stackFrame(ctx, base, 96);
	uint32_t allocSize = 40;
	uint64_t newObject = operator_new(ctx, base, allocSize);
	uint64_t result;
	if ((uint32_t)newObject != 0) {
		result = CMemoryFile_Constructor(ctx, base, newObject, source);
	} else {
		result = 0;
	}
	return result;
}
PROMOTED_ENTRY(83, sub_82B4A848, 0x82B4A848) { ctx.r3.u64 = CMemoryFile_Create(ctx, base, ctx.r3.u64); }
