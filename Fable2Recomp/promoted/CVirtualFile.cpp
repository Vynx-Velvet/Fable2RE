// CVirtualFile (vtable 0x8200DE20): methods of the class as readable C++.
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

// sub_82B482A0  [36 bytes]
void CVirtualFile_Clear(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr) {
	if (!UseLiftedCode(83, 0x82B482A0)) { ctx.r3.u64 = virtualFileAddr; __imp__sub_82B482A0(ctx, base); return; }
	LiftedFrame frame(0x82B482A0);
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	virtualFile->vtable = 0;
	virtualFile->m_Path = 0;
	virtualFile->m_Source = 0;
	virtualFile->m_Stream = 0;
	virtualFile->m_10 = 0;
	virtualFile->m_14 = 0;
	virtualFile->m_18 = 0;
	return;
}
PROMOTED_ENTRY(83, sub_82B482A0, 0x82B482A0) { CVirtualFile_Clear(ctx, base, ctx.r3.u32); }

uint64_t CVirtualFile_CopyPath(CpuState& ctx, uint8_t* base, uint64_t dest, uint64_t source) {
	if (!UseLiftedCode(92, 0x82C62888)) { ctx.r3.u64 = dest; ctx.r4.u64 = source; __imp__sub_82C62888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62888);
	GameStackFrame stackFrame(ctx, base, 96);
	// The source object carries the string at offset 4; the copy is constructed at dest.
	CCharString_CopyConstruct(ctx, base, dest, source + 4);
	return dest;
}
PROMOTED_ENTRY(92, sub_82C62888, 0x82C62888) { ctx.r3.u64 = CVirtualFile_CopyPath(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CVirtualFile_ClearAll(CpuState& ctx, uint8_t* base, uint64_t file) {
	if (!UseLiftedCode(92, 0x82C628C0)) { ctx.r3.u64 = file; __imp__sub_82C628C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C628C0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t secondPart = (uint32_t)(file + 0x1C);
	uint32_t thirdPart = (uint32_t)(file + 0x38);

	CVirtualFile_Clear(ctx, base, file);
	CVirtualFile_Clear(ctx, base, secondPart);
	CVirtualFile_Clear(ctx, base, thirdPart);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return file;
}
PROMOTED_ENTRY(92, sub_82C628C0, 0x82C628C0) { ctx.r3.u64 = CVirtualFile_ClearAll(ctx, base, ctx.r3.u64); }

uint32_t CVirtualFile_Constructor(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr, uint64_t stream) {
	if (!UseLiftedCode(92, 0x82C62990)) { ctx.r3.u64 = virtualFileAddr; ctx.r4.u64 = stream; __imp__sub_82C62990(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C62990);
	uint32_t stack = ctx.r1.u64;
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	stack = PushStackFrame(base, stack, 112);
	virtualFile->vtable = 0x8200DE20u;
	ctx.r1.u64 = stack;
	RefCountedObject_Construct(ctx, base, virtualFileAddr + 4);
	virtualFile->m_Source = 0;
	virtualFile->m_Stream = (uint32_t)stream;
	if ((uint32_t)stream != 0) {
		uint32_t method = LOAD32(LOAD32((uint32_t)stream) + 4);
		ctx.r3.u64 = stream;
		ctx.r4.u64 = stream;
		ctx.r9.u64 = 0;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return virtualFileAddr;
}
PROMOTED_ENTRY(92, sub_82C62990, 0x82C62990) { ctx.r3.u64 = CVirtualFile_Constructor(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CVirtualFile_CloseStream(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr) {
	if (!UseLiftedCode(92, 0x82C62A88)) { ctx.r3.u64 = virtualFileAddr; __imp__sub_82C62A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62A88);
	uint32_t stack = ctx.r1.u64;
	uint64_t stream{};
	uint64_t r9Value = ctx.r9.u64;
	PPCRegister callTarget{};
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	stack = PushStackFrame(base, stack, 96);
	stream = virtualFile->m_Stream;
	if ((uint32_t)stream != 0) {
		uint32_t closeFunc = LOAD32(LOAD32((uint32_t)stream) + 8);
		callTarget.u64 = (uint64_t)closeFunc;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stream;
		ctx.r10.u64 = closeFunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		stream = ctx.r3.u64;
		r9Value = 0;
		virtualFile->m_Stream = (uint32_t)r9Value;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = r9Value;
	return stream;
}
PROMOTED_ENTRY(92, sub_82C62A88, 0x82C62A88) { ctx.r3.u64 = CVirtualFile_CloseStream(ctx, base, ctx.r3.u32); }

uint64_t CVirtualFile_ReadAt(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr, uint64_t offset, uint64_t buffer) {
	if (!UseLiftedCode(92, 0x82C62AD8)) { ctx.r3.u64 = virtualFileAddr; ctx.r4.u64 = offset; ctx.r5.u64 = buffer; __imp__sub_82C62AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62AD8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	stack = PushStackFrame(base, stack, 128);

	// r4 is live across the calls below: the value the last callee leaves in r4 is returned to the caller.
	uint64_t r4Value = offset;

	// Field 0xC holds an intrusive pointer to the file's reader, created from the source on first use.
	uint32_t readerFieldAddr = virtualFileAddr + 12;
	if (LOAD32(readerFieldAddr) == 0) {
		uint32_t source = virtualFile->m_Source;
		ctx.r1.u64 = stack;
		uint64_t newReader = CreateFileReader(ctx, base, stack + 80, source, 0, 65536);
		IntrusivePtr_Assign(ctx, base, readerFieldAddr, newReader);
		r4Value = ctx.r4.u64;

		uint32_t temp = LOAD32(stack + 80);
		if (temp != 0) {
			uint32_t release = LOAD32(LOAD32(temp) + 8);
			callTarget.u64 = release;
			ctx.r3.u64 = temp;
			ctx.r10.u64 = release;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r4Value = ctx.r4.u64;
		}
	}

	uint32_t reader = LOAD32(readerFieldAddr);
	uint64_t result = reader;
	if (reader != 0) {
		STORE32(stack + 88, (uint32_t)offset);
		STORE32(stack + 92, 0u);
		uint32_t method = LOAD32(LOAD32(reader) + 12);
		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = reader;
		ctx.r4.u64 = stack + 88;
		ctx.r5.u64 = buffer;
		ctx.r9.u64 = method;
		ctx.r10.u64 = LOAD32(reader);
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r4Value = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(92, sub_82C62AD8, 0x82C62AD8) { ctx.r3.u64 = CVirtualFile_ReadAt(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t CVirtualFile_WriteAt(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr, uint64_t offset, uint64_t buffer) {
	if (!UseLiftedCode(92, 0x82C62B70)) { ctx.r3.u64 = virtualFileAddr; ctx.r4.u64 = offset; ctx.r5.u64 = buffer; __imp__sub_82C62B70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62B70);
	uint32_t stack = ctx.r1.u64;
	uint32_t arg2Value = (uint32_t)offset;
	PPCRegister callTarget{};
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	stack = PushStackFrame(base, stack, 128);

	// r4 is live across the calls below: the value the last callee leaves in r4 is returned to the caller.
	uint64_t r4Value = offset;

	uint32_t fileDataAddr = virtualFileAddr + 12;
	if (LOAD32(fileDataAddr) == 0) {
		uint32_t source = virtualFile->m_Source;
		uint32_t holderAddr = stack + 80;
		ctx.r1.u64 = stack;
		uint32_t created = CreateFileReader(ctx, base, holderAddr, source, 0, 65536);
		IntrusivePtr_Assign(ctx, base, fileDataAddr, created);
		r4Value = ctx.r4.u64;
		uint32_t holder = LOAD32(stack + 80);
		if (holder != 0) {
			uint32_t releaseFn = LOAD32(LOAD32(holder) + 8);
			callTarget.u64 = releaseFn;
			ctx.r3.u64 = holder;
			ctx.r10.u64 = releaseFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r4Value = ctx.r4.u64;
		}
	}
	uint64_t result = LOAD32(fileDataAddr);
	if ((int32_t)result != 0) {
		STORE32(stack + 88, arg2Value);
		STORE32(stack + 92, 0u);
		uint32_t vtable = LOAD32((uint32_t)result);
		uint32_t readFn = LOAD32(vtable + 16);
		callTarget.u64 = readFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = result;
		ctx.r4.u64 = stack + 88;
		ctx.r5.u64 = buffer;
		ctx.r9.u64 = readFn;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r4Value = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(92, sub_82C62B70, 0x82C62B70) { ctx.r3.u64 = CVirtualFile_WriteAt(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t CVirtualFile_Seek(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr, uint64_t position) {
	if (!UseLiftedCode(92, 0x82C62C08)) { ctx.r3.u64 = virtualFileAddr; ctx.r4.u64 = position; __imp__sub_82C62C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62C08);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	stack = PushStackFrame(base, stack, 112);

	// r4 is live across the calls below: the value the last callee leaves in r4 is returned to the caller.
	uint64_t r4Value = position;

	uint32_t cachedObjectAddr = virtualFileAddr + 12;
	if (LOAD32(cachedObjectAddr) == 0) {
		uint32_t source = virtualFile->m_Source;
		uint32_t tempObjectAddr = stack + 80;
		ctx.r1.u64 = stack;
		uint64_t createdObject = CreateFileReader(ctx, base, tempObjectAddr, source, 0, 65536);
		IntrusivePtr_Assign(ctx, base, cachedObjectAddr, createdObject);
		r4Value = ctx.r4.u64;

		uint32_t tempObject = LOAD32(tempObjectAddr);
		if (tempObject != 0) {
			uint32_t releaseFn = LOAD32(LOAD32(tempObject) + 8);
			callTarget.u64 = (uint64_t)releaseFn;
			ctx.r3.u64 = tempObject;
			ctx.r10.u64 = releaseFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r4Value = ctx.r4.u64;
		}
	}

	uint32_t cachedObject = LOAD32(cachedObjectAddr);
	if (cachedObject != 0) {
		uint32_t method = LOAD32(LOAD32(cachedObject) + 20);
		callTarget.u64 = (uint64_t)method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = cachedObject;
		ctx.r4.s64 = (int32_t)position;
		ctx.r5.u64 = 0;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		cachedObject = ctx.r3.u64;
		r4Value = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return cachedObject;
}
PROMOTED_ENTRY(92, sub_82C62C08, 0x82C62C08) { ctx.r3.u64 = CVirtualFile_Seek(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CVirtualFile_SeekRelative(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr, uint64_t offset) {
	if (!UseLiftedCode(92, 0x82C62CA8)) { ctx.r3.u64 = virtualFileAddr; ctx.r4.u64 = offset; __imp__sub_82C62CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62CA8);
	uint32_t stack = ctx.r1.u64;
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	stack = PushStackFrame(base, stack, 112);

	// r4 is live across the calls below: the value the last callee leaves in r4 is returned to the caller.
	uint64_t r4Value = offset;

	int32_t readArg = (int32_t)offset;
	uint32_t bufferSlot = virtualFileAddr + 12;

	// First access: build the file's buffer from its source and release the temporary reference.
	if (LOAD32(bufferSlot) == 0) {
		uint32_t source = virtualFile->m_Source;
		uint32_t tempHolder = stack + 80;
		ctx.r1.u64 = stack;
		uint64_t newBuffer = CreateFileReader(ctx, base, tempHolder, source, 0, 65536);
		IntrusivePtr_Assign(ctx, base, bufferSlot, newBuffer);
		r4Value = ctx.r4.u64;

		uint32_t temp = LOAD32(tempHolder);
		if (temp != 0) {
			uint32_t release = LOAD32(LOAD32(temp) + 8);
			ctx.r3.u64 = temp;
			ctx.r10.u64 = release;
			REX_CALL_INDIRECT_FUNC(release);
			r4Value = ctx.r4.u64;
		}
	}

	uint32_t buffer = LOAD32(bufferSlot);
	uint64_t result = buffer;
	if ((int32_t)buffer != 0) {
		uint32_t read = LOAD32(LOAD32(buffer) + 20);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = buffer;
		ctx.r4.s64 = readArg;
		ctx.r5.u64 = 1;
		ctx.r10.u64 = read;
		REX_CALL_INDIRECT_FUNC(read);
		result = ctx.r3.u64;
		r4Value = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(92, sub_82C62CA8, 0x82C62CA8) { ctx.r3.u64 = CVirtualFile_SeekRelative(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_82C62D48  [80 bytes]
uint64_t CVirtualFile_Tell(CpuState& ctx, uint8_t* base, uint64_t virtualFile) {
	if (!UseLiftedCode(92, 0x82C62D48)) { ctx.r3.u64 = virtualFile; __imp__sub_82C62D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62D48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t target = LOAD32((uint32_t)virtualFile + 12);
	if (target != 0) {
		// virtual call: vtable[6] of the target object
		uint32_t virtualFn = LOAD32(LOAD32(target) + 24);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = target;
		ctx.r10.u64 = virtualFn;
		REX_CALL_INDIRECT_FUNC(virtualFn);
		uint32_t result = (uint32_t)ctx.r3.u64;
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return result;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C62D48, 0x82C62D48) { ctx.r3.u64 = CVirtualFile_Tell(ctx, base, ctx.r3.u64); }

uint64_t CVirtualFile_GetSize(CpuState& ctx, uint8_t* base, uint64_t virtualFile) {
	if (!UseLiftedCode(92, 0x82C62D98)) { ctx.r3.u64 = virtualFile; __imp__sub_82C62D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62D98);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 96);
	uint32_t stream = LOAD32((uint32_t)virtualFile + 8);
	if (stream != 0) {
		uint32_t getSizeFunc = LOAD32(LOAD32(stream) + 24);
		callTarget.u64 = (uint64_t)getSizeFunc;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stream;
		ctx.r10.u64 = getSizeFunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t size = (uint32_t)ctx.r3.u64;
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return size;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C62D98, 0x82C62D98) { ctx.r3.u64 = CVirtualFile_GetSize(ctx, base, ctx.r3.u64); }

// sub_82C62DE8  [20 bytes]
uint64_t CVirtualFile_HasSource(CpuState& ctx, uint8_t* base, uint32_t virtualFileAddr) {
	if (!UseLiftedCode(92, 0x82C62DE8)) { ctx.r3.u64 = virtualFileAddr; __imp__sub_82C62DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C62DE8);
	CVirtualFile* virtualFile = GameObject<CVirtualFile>(base, virtualFileAddr);
	uint32_t source = virtualFile->m_Source;
	uint32_t isNull = (uint32_t(source == 0 ? 32 : __builtin_clz(source)) >> 5) & 1;
	ctx.r9.u64 = isNull;
	ctx.r11.u64 = source;
	return (uint64_t)isNull ^ 1;
}
PROMOTED_ENTRY(92, sub_82C62DE8, 0x82C62DE8) { ctx.r3.u64 = CVirtualFile_HasSource(ctx, base, ctx.r3.u32); }

uint64_t CVirtualFile_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t virtualFile, uint64_t arg2) {
	if (!UseLiftedCode(92, 0x82C632D0)) { ctx.r3.u64 = virtualFile; ctx.r4.u64 = arg2; __imp__sub_82C632D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C632D0);
	uint32_t stack = ctx.r1.u64;
	uint32_t deleteFlags{};
	stack = PushStackFrame(base, stack, 112);
	deleteFlags = arg2;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	CVirtualFile_Destructor(ctx, base, virtualFile);
	uint64_t object = virtualFile;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, object);
		object = virtualFile;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(92, sub_82C632D0, 0x82C632D0) { ctx.r3.u64 = CVirtualFile_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CVirtualFile_SetPath(CpuState& ctx, uint8_t* base, uint64_t virtualFile, uint64_t rawPath, uint32_t accessMode) {
	constexpr int32_t str_TXT_8200DEB8_B_ = int32_t(0x8200DEB8);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820F8BB4_B_ = int32_t(0x820F8BB4);
	constexpr int32_t g_83330000 = int32_t(0x83330000);
	if (!UseLiftedCode(92, 0x82C635D8)) { ctx.r3.u64 = virtualFile; ctx.r4.u64 = rawPath; ctx.r5.u64 = accessMode; __imp__sub_82C635D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C635D8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 208);
	ctx.r1.u64 = stack;

	const uint32_t pathString = stack + 80;       // CCharString being normalised
	const uint32_t substringSlot = stack + 92;    // CCharString temporary
	const uint32_t newObjectSlot = stack + 96;    // intrusive pointer temporary
	const uint32_t resultSlot = stack + 100;      // intrusive pointer temporary
	const uint32_t queryString = stack + 112;     // string handed to the file system

	// A null CCharString reports this constant as its data pointer.
	const uint64_t emptyStringData = g_8209003F;
	auto charStringData = [&](uint32_t handle) -> uint64_t {
		uint32_t rep = LOAD32(handle);
		return rep == 0 ? emptyStringData : (uint64_t)LOAD32(rep);
	};
	auto charStringLength = [&](uint32_t handle) -> uint64_t {
		uint32_t rep = LOAD32(handle);
		return rep == 0 ? 0 : (uint64_t)LOAD32(rep + 4);
	};

	// Remember the requested path and store it on the file object.
	CCharString_CopyTransformed(ctx, base, pathString, rawPath);
	CCharString_Assign(ctx, base, virtualFile + 4, pathString);


	uint32_t gamePrefixString = stack + 84;
	CCharString_ConstructFromCStr(ctx, base, gamePrefixString, str_TXT_820F8BB4_B_, -1);
	uint32_t isGamePath = strncmp(ctx, base, charStringData(pathString), charStringData(gamePrefixString), charStringLength(gamePrefixString));
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, gamePrefixString);

	uint32_t schemeLength = 0;
	uint64_t pathLength = 0;
	bool stripScheme = false;
	if (isGamePath == 0) {
		schemeLength = 6;
		pathLength = charStringLength(pathString);
		stripScheme = true;
	} else {
		uint32_t cachePrefixString = stack + 88;
		CCharString_ConstructFromCStr(ctx, base, cachePrefixString, str_TXT_8200DEB8_B_, -1);
		uint32_t isCachePath = strncmp(ctx, base, charStringData(pathString), charStringData(cachePrefixString), charStringLength(cachePrefixString));
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, cachePrefixString);
		if (isCachePath == 0) {
			schemeLength = 7;
			pathLength = charStringLength(pathString);
			stripScheme = true;
		}
	}
	if (stripScheme) {
		uint64_t stripped = CCharString_ConstructSubstring(ctx, base, substringSlot, pathString, schemeLength, pathLength);
		CCharString_Assign(ctx, base, pathString, stripped);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, substringSlot);
	}

	// Strip the global mount prefix as well.
	uint32_t globalBase = (uint32_t)g_83330000;
	uint32_t globalPrefix = LOAD32(globalBase + 22472);
	uint64_t globalPrefixData = globalPrefix == 0 ? emptyStringData : (uint64_t)LOAD32(globalPrefix);
	uint64_t globalPrefixLength = globalPrefix == 0 ? 0 : (uint64_t)LOAD32(globalPrefix + 4);
	uint32_t lastStrcmpResult = strncmp(ctx, base, charStringData(pathString), globalPrefixData, globalPrefixLength);
	uint64_t savedR5 = globalPrefixLength;
	if ((int32_t)lastStrcmpResult == 0) {
		uint64_t remainingLength = charStringLength(pathString);
		uint32_t prefixLength = globalPrefix == 0 ? 0 : LOAD32(globalPrefix + 4);
		uint64_t stripped = CCharString_ConstructSubstring(ctx, base, substringSlot, pathString, prefixLength, remainingLength);
		CCharString_Assign(ctx, base, pathString, stripped);
		lastStrcmpResult = CCharString_ReleaseAndDecGlobalCountA(ctx, base, substringSlot);
		savedR5 = ctx.r5.u64;
	}

	// Map the requested access mode onto the file system's own mode value.
	uint32_t mappedAccess;
	if ((int32_t)accessMode >= 1 && (int32_t)accessMode <= 3) {
		mappedAccess = 1;
	} else if ((int32_t)accessMode == 4) {
		mappedAccess = 0;
	} else {
		mappedAccess = LOAD32(resultSlot);
	}

	ctx.r5.u64 = savedR5;
	uint32_t container = GetFileSystemSingleton(ctx, base);
	if (LOAD32(container) == 0) {
		uint64_t newObject = n_sub_82B3E0A8(ctx, base, newObjectSlot, ctx.r8.u64);
		IntrusivePtr_Assign(ctx, base, container, newObject);
		uint32_t object = LOAD32(newObjectSlot);
		if (object != 0) {
			uint64_t releaseFn = LOAD32(LOAD32(object) + 8);
			callTarget.u64 = releaseFn;
			ctx.r3.u64 = object;
			ctx.r10.u64 = releaseFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
	}

	CCharString_ConstructFromData(ctx, base, queryString, charStringData(pathString));
	uint32_t fileSystem = LOAD32(container);
	uint64_t openFn = LOAD32(LOAD32(fileSystem) + 16);
	callTarget.u64 = openFn;
	ctx.r3.u64 = resultSlot;
	ctx.r4.u64 = fileSystem;
	ctx.r5.u64 = queryString;
	ctx.r6.u64 = (uint64_t)mappedAccess;
	ctx.r10.u64 = openFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t openedFile = ctx.r3.u64;
	IntrusivePtr_Assign(ctx, base, virtualFile + 8, openedFile);

	uint32_t releasedObject = LOAD32(resultSlot);
	if (releasedObject != 0) {
		uint64_t releaseFn = LOAD32(LOAD32(releasedObject) + 8);
		callTarget.u64 = releaseFn;
		ctx.r3.u64 = releasedObject;
		ctx.r10.u64 = releaseFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	// Destroy the query string.
	if (LOAD32(stack + 136) >= 8) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 116));
	}
	STORE32(stack + 132, 0);
	STORE16(stack + 116, (uint16_t)0);
	STORE32(stack + 136, 7u);

	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, pathString);
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(92, sub_82C635D8, 0x82C635D8) { ctx.r3.u64 = CVirtualFile_SetPath(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }
