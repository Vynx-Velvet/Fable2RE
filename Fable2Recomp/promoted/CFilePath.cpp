// CFilePath (vtable 0x82007B3C): methods of the class as readable C++.
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

uint64_t CFilePath_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t filePathAddr, uint64_t deleteFlags, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr uint32_t CFilePath_vtable = 0x82007B3C;
	if (!UseLiftedCode(88, 0x82BEB8A8)) { ctx.r3.u64 = filePathAddr; ctx.r4.u64 = deleteFlags; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82BEB8A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BEB8A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CFilePath* filePath = GameObject<CFilePath>(base, filePathAddr);
	filePath->vtable = CFilePath_vtable;
	if ((uint32_t(deleteFlags) & 1) != 0) {
		ctx.r4.u64 = deleteFlags;
		CFilePath_FreeThunk(ctx, base, filePathAddr, forwardedArg1, forwardedArg2);
		deleteFlags = ctx.r4.u64;
	}
	ctx.r4.u64 = deleteFlags;
	return filePathAddr;
}
PROMOTED_ENTRY(88, sub_82BEB8A8, 0x82BEB8A8) { ctx.r3.u64 = CFilePath_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CFilePath_Free(CpuState& ctx, uint8_t* base, uint64_t filePathAddr, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr int32_t imagePage0 = int32_t(0x82000000);
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008DEC);
	constexpr int32_t assertMessageNullPointer = int32_t(0x82008E08);
	constexpr uint32_t freeGlobalsPage = 0x83330000;
	constexpr uint32_t skipFree_address = freeGlobalsPage + 18484;
	constexpr uint32_t freeHook_address = freeGlobalsPage + 18500;
	if (!UseLiftedCode(88, 0x82BF2158)) { ctx.r3.u64 = filePathAddr; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82BF2158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF2158);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t result = filePathAddr;
	if ((uint32_t)filePathAddr == 0) {
		result = Assert_Fail(ctx, base, assertFile, assertFunction, 154, assertMessageNullPointer, forwardedArg1, forwardedArg2, imagePage0, imagePage1);
		forwardedArg1 = ctx.r7.u64;
		forwardedArg2 = ctx.r8.u64;
	}
	// nothing is freed while the word at skipFree_address is set; an installed hook replaces FreeMemory
	if (LOAD32(skipFree_address) == 0) {
		uint32_t freeHook = LOAD32(freeHook_address);
		if (freeHook != 0) {
			ctx.r3.u64 = filePathAddr;
			ctx.r7.u64 = forwardedArg1;
			ctx.r8.u64 = forwardedArg2;
			ctx.r10.u64 = freeHook;
			REX_CALL_INDIRECT_FUNC(freeHook);
			result = ctx.r3.u64;
			forwardedArg1 = ctx.r7.u64;
			forwardedArg2 = ctx.r8.u64;
		} else {
			ctx.r7.u64 = forwardedArg1;
			ctx.r10.u64 = freeHook;
			ctx.r11.u64 = freeGlobalsPage;
			result = FreeMemory(ctx, base, filePathAddr, forwardedArg2);
			forwardedArg1 = ctx.r7.u64;
			forwardedArg2 = ctx.r8.u64;
		}
	}
	ctx.r7.u64 = forwardedArg1;
	ctx.r8.u64 = forwardedArg2;
	return result;
}
PROMOTED_ENTRY(88, sub_82BF2158, 0x82BF2158) { ctx.r3.u64 = CFilePath_Free(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

uint32_t CFilePath_FreeThunk(CpuState& ctx, uint8_t* base, uint64_t filePathAddr, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	if (!UseLiftedCode(88, 0x82BF2DA8)) { ctx.r3.u64 = filePathAddr; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82BF2DA8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BF2DA8);
	return uint32_t(CFilePath_Free(ctx, base, filePathAddr, forwardedArg1, forwardedArg2));
}
PROMOTED_ENTRY(88, sub_82BF2DA8, 0x82BF2DA8) { ctx.r3.u64 = CFilePath_FreeThunk(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CFilePath_IsDirectory(CpuState& ctx, uint8_t* base, uint32_t filePath) {
	if (!UseLiftedCode(88, 0x82BF2DB0)) { ctx.r3.u64 = filePath; __imp__sub_82BF2DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF2DB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint32_t pathString = filePath + 12;

	uint64_t lastChar = 0;
	uint32_t i = pathString;
	do {
		lastChar = LOAD8(i);
		i = i + 1;
	} while ((uint32_t)lastChar != 0);
	uint32_t length = (i - pathString) - 1;

	uint32_t isDirectory = 0;
	if (length == 0) {
		SetLastError(ctx, base, 5023);
	} else {
		ctx.r10.u64 = lastChar;
		uint32_t fileAttributes = GetFileAttributesA(ctx, base, pathString);
		lastChar = ctx.r10.u64;
		if ((int32_t)fileAttributes != -1) {
			if ((fileAttributes & 16) != 0) {
				isDirectory = 1;
			} else {
				SetLastError(ctx, base, 123);
			}
		}
	}
	ctx.r10.u64 = lastChar;
	return isDirectory;
}
PROMOTED_ENTRY(88, sub_82BF2DB0, 0x82BF2DB0) { ctx.r3.u64 = CFilePath_IsDirectory(ctx, base, ctx.r3.u32); }

uint64_t CFilePath_LoadLanguageIds(CpuState& ctx, uint8_t* base, uint64_t filePath, uint64_t languageName, uint32_t outFirstId, uint32_t outSecondId, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr int32_t imagePage0 = int32_t(0x82000000);
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008EE0);
	constexpr int32_t assertMessageEmptyPath = int32_t(0x82008F60);
	constexpr int32_t assertMessageFormat = int32_t(0x82008C48);
	constexpr int32_t str_TXT_82008F44_B_ = int32_t(0x82008F44);
	constexpr int32_t str_TXT_82008F50_B_ = int32_t(0x82008F50);
	constexpr uint32_t pathTextOffset = 12;
	constexpr uint32_t maxPath = 260;
	constexpr uint32_t errorFileNotFound = 2;
	constexpr uint32_t errorInvalidParameter = 87;
	constexpr uint32_t errorBadPathname = 161;
	constexpr uint32_t errorInternalError = 1359;
	constexpr uint32_t errorInvalidState = 5023;
	if (!UseLiftedCode(88, 0x82BF3010)) { ctx.r3.u64 = filePath; ctx.r4.u64 = languageName; ctx.r5.u64 = outFirstId; ctx.r6.u64 = outSecondId; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82BF3010(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF3010);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 384);
	const uint32_t firstIdSlot = stack + 80;
	const uint32_t secondIdSlot = stack + 82;
	const uint32_t iniPath = stack + 96;
	const uint64_t pathString = filePath + pathTextOffset;
	uint64_t secondResult = languageName;
	uint32_t errorCode = 0;
	uint32_t result = 0;

	if ((uint32_t)languageName == 0 || outFirstId == 0 || outSecondId == 0) {
		errorCode = errorInvalidParameter;
	} else {
		uint32_t pathLength = 0;
		while (LOAD8(uint32_t(pathString) + pathLength) != 0)
			++pathLength;
		if (pathLength == 0) {
			ctx.r1.u64 = stack;
			Assert_Fail(ctx, base, assertFile, assertFunction, 385, assertMessageEmptyPath, forwardedArg1, forwardedArg2, imagePage0, imagePage1);
			secondResult = ctx.r4.u64;
			errorCode = errorInvalidState;
		} else {
			uint32_t languageLength = 0;
			while (LOAD8(uint32_t(languageName) + languageLength) != 0)
				++languageLength;
			if (languageLength + pathLength + 11 > maxPath) {
				errorCode = errorBadPathname;
			} else {
				ctx.r1.u64 = stack;
				int32_t formattedLength = (int32_t)String_Format_82BF2EC8(ctx, base, iniPath, str_TXT_82008F44_B_, pathString, languageName, str_TXT_82008F50_B_, 0, languageName, imagePage1);
				if (formattedLength <= 0) {
					Assert_Fail(ctx, base, assertFile, assertFunction, 401, assertMessageFormat, ctx.r7.u64, ctx.r8.u64, imagePage0, imagePage1);
					secondResult = ctx.r4.u64;
					errorCode = errorInternalError;
				} else {
					STORE16(firstIdSlot, 1);
					STORE16(secondIdSlot, 1);
					uint32_t readResult = n_sub_82BEC9E0(ctx, base, iniPath, firstIdSlot, ctx.r7.u64, ctx.r8.u64);
					secondResult = ctx.r4.u64;
					// a missing file keeps the defaults (1, 1); any other failure returns 0 without them
					bool haveIds = true;
					if ((int32_t)readResult < 0) {
						ctx.r3.u64 = readResult;
						haveIds = uint32_t(GetLastError(ctx, base)) == errorFileNotFound;
					}
					if (haveIds) {
						uint16_t secondId = LOAD16(secondIdSlot);
						STORE16(outFirstId, LOAD16(firstIdSlot));
						STORE16(outSecondId, secondId);
						result = 1;
					}
				}
			}
		}
	}

	if (errorCode != 0) {
		ctx.r1.u64 = stack;
		SetLastError(ctx, base, errorCode);
	}
	stack = PopStackFrame(stack, 384);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(88, sub_82BF3010, 0x82BF3010) { ctx.r3.u64 = CFilePath_LoadLanguageIds(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32, ctx.r7.u64, ctx.r8.u64); }

uint64_t CFilePath_IsEqual(CpuState& ctx, uint8_t* base, uint64_t filePathAddr, uint64_t otherPath, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3) {
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008EE0);
	constexpr int32_t assertMessageNullPath = int32_t(0x82008FF8);
	constexpr int32_t assertMessagePrefix = int32_t(0x82008FBC);
	constexpr uint32_t pathTextOffset = 12;
	if (!UseLiftedCode(88, 0x82BF31A8)) { ctx.r3.u64 = filePathAddr; ctx.r4.u64 = otherPath; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; __imp__sub_82BF31A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF31A8);
	GameStackFrame stackFrame(ctx, base, 128);
	uint64_t secondResult = otherPath;
	uint64_t forwardedArg4 = imagePage1;
	if ((uint32_t)otherPath == 0) {
		Assert_Fail(ctx, base, assertFile, assertFunction, 446, assertMessageNullPath, forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4);
		secondResult = ctx.r4.u64;
		forwardedArg1 = ctx.r7.u64;
		forwardedArg2 = ctx.r8.u64;
		forwardedArg3 = ctx.r9.u64;
		forwardedArg4 = ctx.r10.u64;
	}
	ctx.r7.u64 = forwardedArg1;
	ctx.r8.u64 = forwardedArg2;
	ctx.r9.u64 = forwardedArg3;
	ctx.r10.u64 = forwardedArg4;
	if (CFilePath_HasPrefix(ctx, base, otherPath) != 0) {
		Assert_Fail(ctx, base, assertFile, assertFunction, 447, assertMessagePrefix, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);
		secondResult = ctx.r4.u64;
	}
	uint32_t isEqual = 0;
	if ((uint32_t)otherPath != 0 && CFilePath_HasPrefix(ctx, base, otherPath) != 0) {
		uint32_t comparison = (uint32_t)stricmp(ctx, base, filePathAddr + pathTextOffset, otherPath + pathTextOffset);
		secondResult = ctx.r4.u64;
		isEqual = comparison == 0 ? 1 : 0;
	}
	ctx.r4.u64 = secondResult;
	return isEqual;
}
PROMOTED_ENTRY(88, sub_82BF31A8, 0x82BF31A8) { ctx.r3.u64 = CFilePath_IsEqual(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t CFilePath_Assign(CpuState& ctx, uint8_t* base, uint64_t destPath, uint64_t sourcePath, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr int32_t imagePage0 = int32_t(0x82000000);
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008EE0);
	constexpr int32_t assertMessagePrefix = int32_t(0x82008F10);
	constexpr uint32_t pathTextOffset = 12;
	constexpr uint32_t maxPath = 260;
	if (!UseLiftedCode(88, 0x82BF3250)) { ctx.r3.u64 = destPath; ctx.r4.u64 = sourcePath; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82BF3250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF3250);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r7.u64 = forwardedArg1;
	ctx.r8.u64 = forwardedArg2;
	if (CFilePath_HasPrefix(ctx, base, sourcePath) == 0) {
		Assert_Fail(ctx, base, assertFile, assertFunction, 466, assertMessagePrefix, ctx.r7.u64, ctx.r8.u64, imagePage0, imagePage1);
	}
	strcpy_s(ctx, base, destPath + pathTextOffset, maxPath, sourcePath + pathTextOffset, ctx.r8.u64);
	return destPath;
}
PROMOTED_ENTRY(88, sub_82BF3250, 0x82BF3250) { ctx.r3.u64 = CFilePath_Assign(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CFilePath_CountSubDirectories(CpuState& ctx, uint8_t* base, uint64_t filePath, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3, uint64_t forwardedArg4) {
	constexpr int32_t imagePage0 = int32_t(0x82000000);
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008EE0);
	constexpr int32_t assertMessageEmptyPath = int32_t(0x82008F60);
	constexpr int32_t assertMessageFormat = int32_t(0x82009018);
	constexpr int32_t searchPatternFormat = int32_t(0x82009024);
	constexpr uint32_t FindHandleHolder_vtable = 0x82007B2C;
	constexpr uint32_t pathTextOffset = 12;
	constexpr uint32_t fileAttributeDirectory = 16;
	constexpr uint32_t directoryEntryFilter = 3;
	constexpr uint32_t errorInternalError = 1359;
	constexpr uint32_t errorInvalidState = 5023;
	if (!UseLiftedCode(88, 0x82BF32C8)) { ctx.r3.u64 = filePath; ctx.r6.u64 = forwardedArg1; ctx.r7.u64 = forwardedArg2; ctx.r8.u64 = forwardedArg3; ctx.r9.u64 = forwardedArg4; __imp__sub_82BF32C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF32C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 704);
	// a find-handle holder on the stack: its vtable, then the handle
	const uint32_t findHandleHolder = stack + 80;
	const uint32_t findHandle = stack + 84;
	const uint32_t newFindHandle = stack + 88;
	const uint32_t findData = stack + 96;
	const uint32_t foundName = stack + 140;
	const uint32_t searchPattern = stack + 416;
	const uint64_t pathString = filePath + pathTextOffset;

	uint32_t pathLength = 0;
	while (LOAD8(uint32_t(pathString) + pathLength) != 0)
		++pathLength;
	if (pathLength == 0) {
		ctx.r1.u64 = stack;
		Assert_Fail(ctx, base, assertFile, assertFunction, 86, assertMessageEmptyPath, forwardedArg2, forwardedArg3, imagePage0, imagePage1);
		SetLastError(ctx, base, errorInvalidState);
		stack = PopStackFrame(stack, 704);
		ctx.r1.u64 = stack;
		return uint64_t(-1);
	}

	uint64_t subDirectoryCount = 0;
	STORE32(findHandle, 0);
	STORE32(findHandleHolder, FindHandleHolder_vtable);
	ctx.r1.u64 = stack;
	int32_t patternLength = (int32_t)String_Format_82BF2EC8(ctx, base, searchPattern, searchPatternFormat, pathString, forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4, 0);
	if (patternLength <= 0) {
		Assert_Fail(ctx, base, assertFile, assertFunction, 97, assertMessageFormat, ctx.r7.u64, ctx.r8.u64, imagePage0, imagePage1);
		SetLastError(ctx, base, errorInternalError);
		subDirectoryCount = uint64_t(-1);
	} else {
		STORE32(newFindHandle, (uint32_t)FindFirstFile(ctx, base, searchPattern, findData));
		CFilePath_Assign_82BF2E78(ctx, base, findHandleHolder, newFindHandle);
		if ((int32_t)LOAD32(findHandle) == -1) {
			subDirectoryCount = uint64_t(-1);
		} else {
			do {
				if ((LOAD32(findData) & fileAttributeDirectory) != 0) {
					if (CFilePath_IsValidDirectoryEntry(ctx, base, foundName, directoryEntryFilter, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64) != 0)
						++subDirectoryCount;
				}
			} while ((uint32_t)FindNextFile(ctx, base, LOAD32(findHandle), findData) != 0);
		}
	}
	STORE32(findHandleHolder, FindHandleHolder_vtable);
	FindHandle_Close(ctx, base, findHandle);
	stack = PopStackFrame(stack, 704);
	ctx.r1.u64 = stack;
	return subDirectoryCount;
}
PROMOTED_ENTRY(88, sub_82BF32C8, 0x82BF32C8) { ctx.r3.u64 = CFilePath_CountSubDirectories(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t CFilePath_GetSubDirectoryName(CpuState& ctx, uint8_t* base, uint64_t filePath, uint64_t index, uint64_t outName, uint64_t outNameSize, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3) {
	constexpr int32_t imagePage0 = int32_t(0x82000000);
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008EE0);
	constexpr int32_t assertMessageEmptyPath = int32_t(0x82008F60);
	constexpr int32_t assertMessageFormat = int32_t(0x82009018);
	constexpr int32_t assertMessageCopy = int32_t(0x82008120);
	constexpr int32_t assertMessageIndex = int32_t(0x8200902C);
	constexpr int32_t searchPatternFormat = int32_t(0x82009024);
	constexpr uint32_t FindHandleHolder_vtable = 0x82007B2C;
	constexpr uint32_t pathTextOffset = 12;
	constexpr uint32_t fileAttributeDirectory = 16;
	constexpr uint32_t directoryEntryFilter = 3;
	constexpr uint32_t maxPath = 260;
	constexpr uint32_t errorInvalidParameter = 87;
	constexpr uint32_t errorInsufficientBuffer = 122;
	constexpr uint32_t errorInternalError = 1359;
	constexpr uint32_t errorInvalidIndex = 1413;
	constexpr uint32_t errorInvalidState = 5023;
	if (!UseLiftedCode(88, 0x82BF3428)) { ctx.r3.u64 = filePath; ctx.r4.u64 = index; ctx.r5.u64 = outName; ctx.r6.u64 = outNameSize; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; __imp__sub_82BF3428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF3428);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 752);
	// a find-handle holder on the stack: its vtable, then the handle
	const uint32_t findHandleHolder = stack + 80;
	const uint32_t findHandle = stack + 84;
	const uint32_t newFindHandle = stack + 88;
	const uint32_t findData = stack + 96;
	const uint32_t foundName = stack + 140;
	const uint32_t searchPattern = stack + 416;
	const uint64_t pathString = filePath + pathTextOffset;
	const int32_t wantedIndex = (int32_t)index;
	uint64_t secondResult = index;
	uint64_t result = uint64_t(-1);

	bool invalidArguments = wantedIndex < 0;
	if (!invalidArguments)
		invalidArguments = (uint32_t)outName == 0 ? (int32_t)outNameSize != 0 : (int32_t)outNameSize <= 0;
	if (invalidArguments) {
		ctx.r1.u64 = stack;
		SetLastError(ctx, base, errorInvalidParameter);
	} else {
		uint32_t pathLength = 0;
		while (LOAD8(uint32_t(pathString) + pathLength) != 0)
			++pathLength;
		if (pathLength == 0) {
			ctx.r1.u64 = stack;
			Assert_Fail(ctx, base, assertFile, assertFunction, 151, assertMessageEmptyPath, forwardedArg1, forwardedArg2, imagePage0, imagePage1);
			secondResult = ctx.r4.u64;
			ctx.r1.u64 = stack;
			SetLastError(ctx, base, errorInvalidState);
		} else {
			STORE32(findHandle, 0);
			STORE32(findHandleHolder, FindHandleHolder_vtable);
			// carriedA / carriedB: the two values the original keeps in argument registers across the enumeration
			// calls; it hands them to each call and takes them back after it
			uint64_t carriedA;
			uint64_t carriedB;
			uint32_t errorCode = 0;
			ctx.r1.u64 = stack;
			int32_t patternLength = (int32_t)String_Format_82BF2EC8(ctx, base, searchPattern, searchPatternFormat, pathString, outNameSize, forwardedArg1, forwardedArg2, forwardedArg3, 0);
			if (patternLength <= 0) {
				Assert_Fail(ctx, base, assertFile, assertFunction, 162, assertMessageFormat, ctx.r7.u64, ctx.r8.u64, imagePage0, imagePage1);
				carriedA = ctx.r9.u64;
				carriedB = ctx.r10.u64;
				errorCode = errorInternalError;
			} else {
				STORE32(newFindHandle, (uint32_t)FindFirstFile(ctx, base, searchPattern, findData));
				CFilePath_Assign_82BF2E78(ctx, base, findHandleHolder, newFindHandle);
				carriedA = ctx.r9.u64;
				carriedB = ctx.r10.u64;
				if ((int32_t)LOAD32(findHandle) != -1) {
					carriedA = imagePage1;
					carriedB = imagePage0;
					int32_t matchIndex = 0;
					bool found = false;
					for (;;) {
						if ((LOAD32(findData) & fileAttributeDirectory) != 0) {
							ctx.r9.u64 = carriedA;
							ctx.r10.u64 = carriedB;
							String_Copy(ctx, base, foundName, maxPath, ctx.r8.u64);
							uint32_t isValid = CFilePath_IsValidDirectoryEntry(ctx, base, foundName, directoryEntryFilter, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64);
							carriedA = ctx.r9.u64;
							carriedB = ctx.r10.u64;
							if (isValid != 0) {
								if (matchIndex == wantedIndex) {
									found = true;
									break;
								}
								if (matchIndex >= wantedIndex) {
									Assert_Fail(ctx, base, assertFile, assertFunction, 214, assertMessageIndex, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);
									carriedA = ctx.r9.u64;
									carriedB = ctx.r10.u64;
								}
								++matchIndex;
							}
						}
						ctx.r9.u64 = carriedA;
						ctx.r10.u64 = carriedB;
						uint32_t more = (uint32_t)FindNextFile(ctx, base, LOAD32(findHandle), findData);
						carriedA = ctx.r9.u64;
						carriedB = ctx.r10.u64;
						if (more == 0)
							break;
					}
					if (!found) {
						errorCode = errorInvalidIndex;
					} else {
						uint32_t nameLength = 0;
						while (LOAD8(foundName + nameLength) != 0)
							++nameLength;
						// the original leaves the scan's last byte (0) and the name's address in the carried registers
						carriedA = 0;
						carriedB = foundName;
						if ((uint32_t)outName == 0) {
							result = (uint64_t)nameLength + 1;
						} else if ((int32_t)outNameSize <= (int32_t)nameLength) {
							errorCode = errorInsufficientBuffer;
						} else {
							ctx.r9.u64 = carriedA;
							ctx.r10.u64 = carriedB;
							uint32_t copyResult = (uint32_t)strcpy_s(ctx, base, outName, outNameSize, foundName, ctx.r8.u64);
							uint64_t afterCopyA = ctx.r9.u64;
							uint64_t afterCopyB = ctx.r10.u64;
							if ((int32_t)copyResult != 0) {
								Assert_Fail(ctx, base, assertFile, assertFunction, 200, assertMessageCopy, ctx.r7.u64, ctx.r8.u64, afterCopyA, afterCopyB);
								carriedA = ctx.r9.u64;
								carriedB = ctx.r10.u64;
								errorCode = errorInternalError;
							} else {
								uint32_t copiedLength = 0;
								while (LOAD8(uint32_t(outName) + copiedLength) != 0)
									++copiedLength;
								carriedA = afterCopyA;
								carriedB = 0;
								result = (uint64_t)copiedLength + 1;
							}
						}
					}
				}
			}
			if (errorCode != 0)
				SetLastError(ctx, base, errorCode);
			STORE32(findHandleHolder, FindHandleHolder_vtable);
			ctx.r9.u64 = carriedA;
			ctx.r10.u64 = carriedB;
			FindHandle_Close(ctx, base, findHandle);
			secondResult = ctx.r4.u64;
		}
	}

	stack = PopStackFrame(stack, 752);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(88, sub_82BF3428, 0x82BF3428) { ctx.r3.u64 = CFilePath_GetSubDirectoryName(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t CFilePath_FileExists(CpuState& ctx, uint8_t* base, uint64_t filePath, uint64_t fileName, uint64_t subDirectoryName) {
	constexpr int32_t imagePage0 = int32_t(0x82000000);
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008EE0);
	constexpr int32_t assertMessageFormat = int32_t(0x82008C48);
	constexpr int32_t str_TXT_82008F44_B_ = int32_t(0x82008F44);
	constexpr uint32_t FindHandleHolder_vtable = 0x82007B2C;
	constexpr uint32_t pathTextOffset = 12;
	constexpr uint32_t maxPath = 260;
	constexpr uint32_t errorInvalidParameter = 87;
	constexpr uint32_t errorBadPathname = 161;
	constexpr uint32_t errorNotFound = 1168;
	constexpr uint32_t errorInternalError = 1359;
	constexpr uint32_t errorInvalidState = 5023;
	if (!UseLiftedCode(88, 0x82BF3690)) { ctx.r3.u64 = filePath; ctx.r4.u64 = fileName; ctx.r5.u64 = subDirectoryName; __imp__sub_82BF3690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF3690);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 704);
	// a find-handle holder on the stack: its vtable, then the handle
	const uint32_t findHandleHolder = stack + 80;
	const uint32_t findHandle = stack + 84;
	const uint32_t fullPath = stack + 96;
	const uint32_t findData = stack + 368;
	const uint64_t pathString = filePath + pathTextOffset;
	uint64_t secondResult = fileName;
	uint32_t errorCode = 0;
	uint32_t exists = 0;

	if ((uint32_t)fileName == 0 || (uint32_t)subDirectoryName == 0) {
		errorCode = errorInvalidParameter;
	} else {
		uint32_t pathLength = 0;
		while (LOAD8(uint32_t(pathString) + pathLength) != 0)
			++pathLength;
		if (pathLength == 0) {
			errorCode = errorInvalidState;
		} else {
			uint32_t fileNameLength = 0;
			while (LOAD8(uint32_t(fileName) + fileNameLength) != 0)
				++fileNameLength;
			uint32_t subDirectoryLength = 0;
			while (LOAD8(uint32_t(subDirectoryName) + subDirectoryLength) != 0)
				++subDirectoryLength;
			if (subDirectoryLength + fileNameLength + pathLength + 3 > maxPath) {
				errorCode = errorBadPathname;
			} else {
				ctx.r1.u64 = stack;
				int32_t formattedLength = (int32_t)String_Format_82BF2EC8(ctx, base, fullPath, str_TXT_82008F44_B_, pathString, subDirectoryName, fileName, 0, pathLength, fileNameLength);
				if (formattedLength <= 0) {
					Assert_Fail(ctx, base, assertFile, assertFunction, 255, assertMessageFormat, ctx.r7.u64, ctx.r8.u64, imagePage0, imagePage1);
					secondResult = ctx.r4.u64;
					errorCode = errorInternalError;
				} else if ((uint32_t)strchr(ctx, base, fileName, '*') == 0) {
					ctx.r4.u64 = '*';
					uint32_t attributes = (uint32_t)GetFileAttributesA(ctx, base, fullPath);
					secondResult = ctx.r4.u64;
					if ((int32_t)attributes == -1)
						errorCode = errorNotFound;
					else
						exists = 1;
				} else {
					uint32_t newHandle = (uint32_t)FindFirstFile(ctx, base, fullPath, findData);
					STORE32(findHandle, newHandle);
					STORE32(findHandleHolder, FindHandleHolder_vtable);
					FindHandle_Close(ctx, base, findHandle);
					secondResult = ctx.r4.u64;
					if ((int32_t)newHandle == -1)
						errorCode = errorNotFound;
					else
						exists = 1;
				}
			}
		}
	}

	if (errorCode != 0) {
		ctx.r1.u64 = stack;
		SetLastError(ctx, base, errorCode);
	}
	stack = PopStackFrame(stack, 704);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return exists;
}
PROMOTED_ENTRY(88, sub_82BF3690, 0x82BF3690) { ctx.r3.u64 = CFilePath_FileExists(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CFilePath_GetPath(CpuState& ctx, uint8_t* base, uint64_t filePath, uint64_t fileName, uint64_t subDirectoryName, uint64_t outFilePath, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3) {
	constexpr int32_t imagePage1 = int32_t(0x82010000);
	constexpr int32_t assertFile = int32_t(0x82007A58);
	constexpr int32_t assertFunction = int32_t(0x82008EE0);
	constexpr int32_t assertMessagePrefix = int32_t(0x82009080);
	constexpr int32_t assertMessageFormat = int32_t(0x82008C48);
	constexpr int32_t assertMessageSeparator = int32_t(0x8200905C);
	constexpr int32_t str_TXT_82008F44_B_ = int32_t(0x82008F44);
	constexpr uint32_t FindHandleHolder_vtable = 0x82007B2C;
	constexpr uint32_t pathTextOffset = 12;
	constexpr uint32_t outPrefixLength = 8;
	constexpr uint32_t maxPath = 260;
	constexpr uint32_t errorInvalidParameter = 87;
	constexpr uint32_t errorBadPathname = 161;
	constexpr uint32_t errorNotFound = 1168;
	constexpr uint32_t errorInternalError = 1359;
	constexpr uint32_t errorInvalidState = 5023;
	if (!UseLiftedCode(88, 0x82BF3830)) { ctx.r3.u64 = filePath; ctx.r4.u64 = fileName; ctx.r5.u64 = subDirectoryName; ctx.r6.u64 = outFilePath; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; __imp__sub_82BF3830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF3830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 752);
	// a find-handle holder on the stack: its vtable, then the handle
	const uint32_t findHandleHolder = stack + 80;
	const uint32_t findHandle = stack + 84;
	const uint32_t fullPath = stack + 96;
	const uint32_t findData = stack + 368;
	const uint64_t pathString = filePath + pathTextOffset;
	const uint64_t outPathText = outFilePath + outPrefixLength;
	uint64_t secondResult = fileName;
	uint32_t errorCode = 0;
	uint32_t found = 0;

	if ((uint32_t)fileName == 0 || (uint32_t)subDirectoryName == 0 || (uint32_t)outFilePath == 0) {
		errorCode = errorInvalidParameter;
	} else {
		ctx.r1.u64 = stack;
		ctx.r7.u64 = forwardedArg1;
		ctx.r8.u64 = forwardedArg2;
		ctx.r9.u64 = forwardedArg3;
		if (String_HasPrefix8(ctx, base, outFilePath) == 0) {
			Assert_Fail(ctx, base, assertFile, assertFunction, 307, assertMessagePrefix, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, imagePage1);
			secondResult = ctx.r4.u64;
		}
		uint32_t pathLength = 0;
		while (LOAD8(uint32_t(pathString) + pathLength) != 0)
			++pathLength;
		if (pathLength == 0) {
			errorCode = errorInvalidState;
		} else {
			uint32_t fileNameLength = 0;
			while (LOAD8(uint32_t(fileName) + fileNameLength) != 0)
				++fileNameLength;
			uint32_t subDirectoryLength = 0;
			while (LOAD8(uint32_t(subDirectoryName) + subDirectoryLength) != 0)
				++subDirectoryLength;
			if (subDirectoryLength + fileNameLength + pathLength + 3 > maxPath) {
				errorCode = errorBadPathname;
			} else {
				int32_t formattedLength = (int32_t)String_Format_82BF2EC8(ctx, base, fullPath, str_TXT_82008F44_B_, pathString, subDirectoryName, fileName, 0, pathLength, fileNameLength);
				if (formattedLength <= 0) {
					Assert_Fail(ctx, base, assertFile, assertFunction, 325, assertMessageFormat, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);
					secondResult = ctx.r4.u64;
					errorCode = errorInternalError;
				} else if ((uint32_t)strchr(ctx, base, fileName, '*') == 0) {
					ctx.r4.u64 = '*';
					uint32_t attributes = (uint32_t)GetFileAttributesA(ctx, base, fullPath);
					secondResult = ctx.r4.u64;
					if ((int32_t)attributes == -1) {
						errorCode = errorNotFound;
					} else {
						strcpy_s(ctx, base, outPathText, maxPath, fullPath, ctx.r8.u64);
						secondResult = ctx.r4.u64;
						found = 1;
					}
				} else {
					// a wildcard name: the output is the directory of the first match
					uint32_t newHandle = (uint32_t)FindFirstFile(ctx, base, fullPath, findData);
					STORE32(findHandle, newHandle);
					STORE32(findHandleHolder, FindHandleHolder_vtable);
					if ((int32_t)newHandle != -1) {
						uint32_t lastSeparator = (uint32_t)String_LastChar(ctx, base, fullPath, '\\');
						if (lastSeparator == 0)
							Assert_Fail(ctx, base, assertFile, assertFunction, 349, assertMessageSeparator, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);
						STORE8(lastSeparator, 0);
						strcpy_s(ctx, base, outPathText, maxPath, fullPath, ctx.r8.u64);
						found = 1;
					} else {
						errorCode = errorNotFound;
					}
					STORE32(findHandleHolder, FindHandleHolder_vtable);
					FindHandle_Close(ctx, base, findHandle);
					secondResult = ctx.r4.u64;
				}
			}
		}
	}

	if (errorCode != 0) {
		ctx.r1.u64 = stack;
		SetLastError(ctx, base, errorCode);
	}
	stack = PopStackFrame(stack, 752);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return found;
}
PROMOTED_ENTRY(88, sub_82BF3830, 0x82BF3830) { ctx.r3.u64 = CFilePath_GetPath(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }
