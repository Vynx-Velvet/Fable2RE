// CBufferedFile (vtable 0x820A6A48): methods of the class as readable C++.
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

// sub_823547D0  [52 bytes]
uint64_t CBufferedFile_GetFileName(CpuState& ctx, uint8_t* base, uint64_t resultString, uint64_t bufferedFileAddr) {
	if (!UseLiftedCode(17, 0x823547D0)) { ctx.r3.u64 = resultString; ctx.r4.u64 = bufferedFileAddr; __imp__sub_823547D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823547D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t fileNameAddr = bufferedFileAddr + 24;  // m_FileName
	ctx.r1.u64 = stack;
	CCharString_CopyConstruct(ctx, base, resultString, fileNameAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return resultString;
}
PROMOTED_ENTRY(17, sub_823547D0, 0x823547D0) { ctx.r3.u64 = CBufferedFile_GetFileName(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBufferedFile_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr, uint64_t deleteFlags) {
	constexpr int32_t g_820A6A48 = int32_t(0x820A6A48);
	if (!UseLiftedCode(17, 0x82354808)) { ctx.r3.u64 = bufferedFileAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82354808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82354808);
	uint32_t stack = ctx.r1.u64;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 112);

	bufferedFile->vtable = (uint32_t)g_820A6A48;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	CBufferedFile_Close(ctx, base, bufferedFileAddr);

	bufferedFile->m_Handle = 0u;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, bufferedFileAddr + 24);
	bufferedFile->vtable = 0x820A6A08u;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, bufferedFileAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return bufferedFileAddr;
}
PROMOTED_ENTRY(17, sub_82354808, 0x82354808) { ctx.r3.u64 = CBufferedFile_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_826F8E88  [8 bytes]
uint64_t CBufferedFile_IsOpen(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr) {
	if (!UseLiftedCode(47, 0x826F8E88)) { ctx.r3.u64 = bufferedFileAddr; __imp__sub_826F8E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826F8E88);
	// the open flag: set by CBufferedFile_Open on success, cleared by CBufferedFile_Close
	return LOAD8((uint32_t)bufferedFileAddr + 0x14);
}
PROMOTED_ENTRY(47, sub_826F8E88, 0x826F8E88) { ctx.r3.u64 = CBufferedFile_IsOpen(ctx, base, ctx.r3.u64); }

uint64_t CBufferedFile_Open(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr, uint64_t fileName, uint64_t openMode, uint64_t openFlags, uint64_t arg5) {
	constexpr int32_t g_820A6298 = int32_t(0x820A6298);
	constexpr int32_t str_TXT_820F8BE4_B_ = int32_t(0x820F8BE4);
	constexpr int32_t str_TXT_820F8BF4_B_ = int32_t(0x820F8BF4);
	constexpr int32_t str_TXT_820F8C00_B_ = int32_t(0x820F8C00);
	constexpr int32_t g_82B40000 = int32_t(0x82B40000);
	if (!UseLiftedCode(83, 0x82B3FD68)) { ctx.r3.u64 = bufferedFileAddr; ctx.r4.u64 = fileName; ctx.r5.u64 = openMode; ctx.r6.u64 = openFlags; ctx.r8.u64 = arg5; __imp__sub_82B3FD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B3FD68);
	uint32_t stack = ctx.r1.u64;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 176);

	// state the callee may pass on; r8 is read again by the calls below
	ctx.r1.u64 = stack;
	CCharString_Assign(ctx, base, bufferedFileAddr + 24, fileName);
	bufferedFile->m_Handle = 0;
	uint32_t createFlags = 0;
	if ((openFlags & 2) != 0) {
		createFlags = 0x08000000;
	}

	n_sub_82B3AEA0(ctx, base, stack + 80, fileName, ctx.r8.u64);
	uint64_t r0 = ctx.r0.u64;  // r0 as the original code leaves it; handed on to the calls below
	uint32_t stringData = LOAD32(stack + 80);
	if (stringData == 0 || (int32_t)LOAD32(stringData + 4) <= 0) {
		CCharString_ConstructFromCStr(ctx, base, stack + 88, (uint64_t)str_TXT_820F8BE4_B_, -1);
		RefCountedString_Assign(ctx, base, stack + 88, stack + 80);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
		uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		return result;
	}

	uint64_t accessFlags = 0;
	uint64_t shareMode = 0;
	uint32_t disposition = 0;
	uint32_t modeIndex = (uint32_t)openMode - 1;
	if (modeIndex <= 3) {
		// the original code leaves the jump-table entry in r0
		r0 = LOAD32((uint32_t)g_82B40000 - 460 + (modeIndex << 2));
		switch (modeIndex) {
		case 0:
			accessFlags = 0xFFFFFFFF80000000ull;
			bufferedFile->m_Mode = (uint32_t)openMode;
			shareMode = 1;
			disposition = 3;
			break;
		case 1:
			ctx.r0.u64 = r0;
			n_sub_82B3CB18(ctx, base, stack + 80);
			r0 = ctx.r0.u64;
			bufferedFile->m_Mode = (uint32_t)openMode;
			accessFlags = 0xFFFFFFFFC0000000ull;
			shareMode = 1;
			disposition = 3;
			break;
		case 2:
			ctx.r0.u64 = r0;
			n_sub_82B3CB18(ctx, base, stack + 80);
			r0 = ctx.r0.u64;
			bufferedFile->m_Mode = 2u;
			accessFlags = 0xFFFFFFFFC0000000ull;
			disposition = 4;
			break;
		case 3:
			ctx.r0.u64 = r0;
			n_sub_82B3CB18(ctx, base, stack + 80);
			n_sub_82B3C4F8(ctx, base, stack + 80, ctx.r8.u64);
			r0 = ctx.r0.u64;
			bufferedFile->m_Mode = 2u;
			accessFlags = 0xFFFFFFFFC0000000ull;
			disposition = 2;
			break;
		}
	}

	n_sub_82CC0750(ctx, base, 0x10000001u);
	// state the callee may pass on
	uint64_t fileHandle = n_sub_82CBCC00(ctx, base, LOAD32(stringData), accessFlags, shareMode, disposition, createFlags);
	uint64_t status = n_sub_82CC0758(ctx, base);

	if ((int32_t)fileHandle == -1 || ((uint32_t)status & 0x10000000) != 0) {
		uint64_t errorCode = n_sub_82CC0758(ctx, base);
		CCharString_ConstructFromCStr(ctx, base, stack + 88, (uint64_t)str_TXT_820F8C00_B_, -1);
		RefCountedString_Assign(ctx, base, stack + 88, stack + 80);
		CCharString_CopyConstruct(ctx, base, stack + 84, stack + 88);
		CCharString_AssignCString(ctx, base, stack + 84, (uint64_t)str_TXT_820F8BF4_B_);
		uint64_t formattedInt = CCharString_ConstructFormatInt(ctx, base, stack + 100, errorCode);
		uint64_t localised = LocalisedString_Assign(ctx, base, stack + 96, stack + 84, formattedInt);
		CCharString_CopyConstruct(ctx, base, stack + 92, localised);
		CCharString_AssignCString(ctx, base, stack + 92, (uint64_t)g_820A6298);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 96);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 100);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 92);
		uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		return result;
	}

	bufferedFile->m_Length = (uint32_t)n_sub_82CBD6F8(ctx, base, fileHandle, 0);
	n_sub_82CC0FC0(ctx, base, fileHandle, 0, 0, 0);
	bufferedFile->m_Handle = (uint32_t)fileHandle;
	bufferedFile->m_Position = 0;
	STORE8((uint32_t)bufferedFileAddr + 0x14, uint8_t(1));  // the open flag
	n_sub_82CC0FC0(ctx, base, fileHandle, 0, 0, 1);

	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B3FD68, 0x82B3FD68) { ctx.r3.u64 = CBufferedFile_Open(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint64_t CBufferedFile_Close(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr) {
	if (!UseLiftedCode(83, 0x82B40000)) { ctx.r3.u64 = bufferedFileAddr; __imp__sub_82B40000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B40000);
	uint32_t stack = ctx.r1.u64;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 96);
	uint64_t result = bufferedFileAddr;
	if (LOAD8((uint32_t)bufferedFileAddr + 0x14) != 0) {  // the open flag
		ctx.r1.u64 = stack;
		n_sub_82CC0FC0(ctx, base, bufferedFile->m_Handle, 0, 0, 1);
		File_FlushBuffers(ctx, base, bufferedFile->m_Handle);
		result = n_sub_82CBBF60(ctx, base, bufferedFile->m_Handle);
	}
	STORE8((uint32_t)bufferedFileAddr + 0x14, uint8_t(0));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B40000, 0x82B40000) { ctx.r3.u64 = CBufferedFile_Close(ctx, base, ctx.r3.u64); }

uint64_t CBufferedFile_Read(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr, uint64_t destBuffer, uint64_t byteCount) {
	constexpr int32_t str_TXT_820F8C14_B_ = int32_t(0x820F8C14);
	constexpr int32_t g_820F8C28 = int32_t(0x820F8C28);
	constexpr int32_t str_TXT_820F8C2C_B_ = int32_t(0x820F8C2C);
	constexpr int32_t str_TXT_820F8C4C_B_ = int32_t(0x820F8C4C);
	if (!UseLiftedCode(83, 0x82B40060)) { ctx.r3.u64 = bufferedFileAddr; ctx.r4.u64 = destBuffer; ctx.r5.u64 = byteCount; __imp__sub_82B40060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B40060);
	uint32_t stack = ctx.r1.u64;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 112);
	const uint32_t bytesReadAddr = stack + 88;  // ReadFile's count of bytes read
	STORE32(bytesReadAddr, 0u);

	if ((uint32_t)destBuffer == 0) {
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, stack + 84, str_TXT_820F8C14_B_, -1);
		uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return result;
	}

	// Builds the error message naming this file in two string temporaries, releases them and returns
	// what the last release returns.
	auto reportError = [&](uint64_t errorText) {
		CCharString_ConstructFromCStr(ctx, base, stack + 80, errorText, -1);
		RefCountedString_Assign(ctx, base, stack + 80, bufferedFileAddr + 24);
		CCharString_CopyConstruct(ctx, base, stack + 84, stack + 80);
		CCharString_AssignCString(ctx, base, stack + 84, g_820F8C28);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		return CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);
	};

	uint64_t result = bufferedFileAddr;
	uint64_t r4ForCaller = destBuffer;
	if ((int32_t)byteCount != 0) {
		if ((uint32_t)bufferedFile->m_Position == (uint32_t)bufferedFile->m_Length) {
			ctx.r1.u64 = stack;
			result = reportError(str_TXT_820F8C2C_B_);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return result;
		}

		ctx.r1.u64 = stack;
		result = ReadFile(ctx, base, bufferedFile->m_Handle, destBuffer, byteCount, bytesReadAddr, 0);
		r4ForCaller = ctx.r4.u64;
		if ((int32_t)result == 0) {
			result = reportError(str_TXT_820F8C4C_B_);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return result;
		}

		bufferedFile->m_Position = bufferedFile->m_Position + LOAD32(bytesReadAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4ForCaller;
	return result;
}
PROMOTED_ENTRY(83, sub_82B40060, 0x82B40060) { ctx.r3.u64 = CBufferedFile_Read(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CBufferedFile_Write(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr, uint64_t sourceBuffer, uint64_t byteCount) {
	constexpr int32_t str_TXT_820F8C14_B_ = int32_t(0x820F8C14);
	constexpr int32_t g_820F8C28 = int32_t(0x820F8C28);
	constexpr int32_t str_TXT_820F8C60_B_ = int32_t(0x820F8C60);
	constexpr int32_t str_TXT_820F8C80_B_ = int32_t(0x820F8C80);
	if (!UseLiftedCode(83, 0x82B401C8)) { ctx.r3.u64 = bufferedFileAddr; ctx.r4.u64 = sourceBuffer; ctx.r5.u64 = byteCount; __imp__sub_82B401C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B401C8);
	uint32_t stack = ctx.r1.u64;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint64_t message = (uint64_t)stack + 80;           // CCharString temporary
	const uint64_t fullMessage = (uint64_t)stack + 84;       // CCharString temporary
	const uint64_t bytesWrittenAddr = (uint64_t)stack + 88;  // WriteFile's count of bytes written

	// Builds the error message naming this file in fullMessage and releases the intermediate
	// string; fullMessage is released at the end.
	auto reportError = [&](uint64_t errorText) {
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, message, errorText, -1);
		RefCountedString_Assign(ctx, base, message, bufferedFileAddr + 24);
		CCharString_CopyConstruct(ctx, base, fullMessage, message);
		CCharString_AssignCString(ctx, base, fullMessage, g_820F8C28);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, message);
	};

	uint64_t result = bufferedFileAddr;
	uint64_t r4ForCaller = sourceBuffer;
	bool releaseFullMessage = false;
	if ((uint32_t)sourceBuffer == 0) {
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, fullMessage, str_TXT_820F8C14_B_, -1);
		releaseFullMessage = true;
	} else if ((int32_t)byteCount != 0) {
		bool openForWriting = (uint32_t)bufferedFile->m_Mode == 2;
		uint32_t handle = bufferedFile->m_Handle;
		if (!openForWriting || (int32_t)handle == -1 || handle == 0) {
			reportError(str_TXT_820F8C60_B_);
			releaseFullMessage = true;
		} else {
			ctx.r1.u64 = stack;
			uint64_t written = WriteFile(ctx, base, handle, sourceBuffer, byteCount, bytesWrittenAddr, 0);
			r4ForCaller = ctx.r4.u64;
			if ((int32_t)written == 0) {
				reportError(str_TXT_820F8C80_B_);
				releaseFullMessage = true;
			} else {
				uint32_t newPosition = (uint32_t)bufferedFile->m_Position + (uint32_t)byteCount;
				uint32_t length = bufferedFile->m_Length;
				bufferedFile->m_Position = newPosition;
				if ((int32_t)newPosition > (int32_t)length) {
					bufferedFile->m_Length = newPosition;
				}
				result = written;
			}
		}
	}

	if (releaseFullMessage) {
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, fullMessage);
		r4ForCaller = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4ForCaller;
	return result;
}
PROMOTED_ENTRY(83, sub_82B401C8, 0x82B401C8) { ctx.r3.u64 = CBufferedFile_Write(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CBufferedFile_GetPosition(CpuState& ctx, uint8_t* base, uint32_t bufferedFileAddr) {
	if (!UseLiftedCode(83, 0x82B402D8)) { ctx.r3.u64 = bufferedFileAddr; __imp__sub_82B402D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B402D8);
	uint32_t stack = ctx.r1.u64;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t handle = bufferedFile->m_Handle;
	ctx.r1.u64 = stack;
	n_sub_82CC0FC0(ctx, base, handle, 0, 0, 1);
	uint32_t position = bufferedFile->m_Position;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return position;
}
PROMOTED_ENTRY(83, sub_82B402D8, 0x82B402D8) { ctx.r3.u64 = CBufferedFile_GetPosition(ctx, base, ctx.r3.u32); }

uint64_t CBufferedFile_SeekTo(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr, uint64_t seekPosition) {
	constexpr int32_t str_TXT_820F8C98_B_ = int32_t(0x820F8C98);
	if (!UseLiftedCode(83, 0x82B40318)) { ctx.r3.u64 = bufferedFileAddr; ctx.r4.u64 = seekPosition; __imp__sub_82B40318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B40318);
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t newPosition = (uint32_t)seekPosition;
	uint64_t result = bufferedFileAddr;
	// callers read r4 after the call: the position when nothing moved, else what the last call left there
	uint64_t callerR4 = seekPosition;
	if ((int32_t)bufferedFile->m_Position != (int32_t)newPosition) {
		ctx.r1.u64 = stack;
		n_sub_82CC0FC0(ctx, base, bufferedFile->m_Handle, 0, 0, 1);
		if ((int32_t)newPosition > (int32_t)bufferedFile->m_Length) {
			uint64_t message = (uint64_t)stack + 80;
			CCharString_ConstructFromCStr(ctx, base, message, str_TXT_820F8C98_B_, -1);
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, message);
		} else {
			bufferedFile->m_Position = newPosition;
			result = n_sub_82CC0FC0(ctx, base, bufferedFile->m_Handle, seekPosition, 0, 0);
		}
		callerR4 = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(83, sub_82B40318, 0x82B40318) { ctx.r3.u64 = CBufferedFile_SeekTo(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBufferedFile_SeekRelative(CpuState& ctx, uint8_t* base, uint32_t bufferedFileAddr, uint32_t byteOffset) {
	constexpr int32_t str_TXT_820F8C98_B_ = int32_t(0x820F8C98);
	constexpr int32_t str_TXT_820F8CB8_B_ = int32_t(0x820F8CB8);
	if (!UseLiftedCode(83, 0x82B403B0)) { ctx.r3.u64 = bufferedFileAddr; ctx.r4.u64 = byteOffset; __imp__sub_82B403B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B403B0);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = 0;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_82CC0FC0(ctx, base, bufferedFile->m_Handle, 0, 0, 1);
	uint32_t newPosition = bufferedFile->m_Position + byteOffset;
	if ((int32_t)newPosition < 0) {
		uint64_t message = (uint64_t)stack + 80;
		CCharString_ConstructFromCStr(ctx, base, message, str_TXT_820F8CB8_B_, -1);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, message);
	} else {
		uint32_t length = bufferedFile->m_Length;
		if ((int32_t)newPosition > (int32_t)length) {
			uint64_t message = (uint64_t)stack + 80;
			CCharString_ConstructFromCStr(ctx, base, message, str_TXT_820F8C98_B_, -1);
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, message);
		} else {
			bufferedFile->m_Position = newPosition;
			ctx.r10.u64 = length;  // state the callee may pass on
			File_FlushBuffers(ctx, base, bufferedFile->m_Handle);
			result = n_sub_82CC0FC0(ctx, base, bufferedFile->m_Handle, bufferedFile->m_Position, 0, 0);
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B403B0, 0x82B403B0) { ctx.r3.u64 = CBufferedFile_SeekRelative(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CBufferedFile_GrowLength(CpuState& ctx, uint8_t* base, uint64_t bufferedFileAddr, uint64_t newLength) {
	if (!UseLiftedCode(83, 0x82B40470)) { ctx.r3.u64 = bufferedFileAddr; ctx.r4.u64 = newLength; __imp__sub_82B40470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B40470);
	uint32_t stack = ctx.r1.u64;
	CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, bufferedFileAddr);
	stack = PushStackFrame(base, stack, 96);
	uint64_t result = bufferedFileAddr;
	// callers read r4 after the call: the new length when nothing changed, else what the last call left there
	uint64_t callerR4 = newLength;
	if ((int32_t)newLength > (int32_t)bufferedFile->m_Length) {
		bufferedFile->m_Length = (uint32_t)newLength;
		ctx.r1.u64 = stack;
		n_sub_82CC0FC0(ctx, base, bufferedFile->m_Handle, newLength, 0, 0);
		result = n_sub_82CC0FC0(ctx, base, bufferedFile->m_Handle, bufferedFile->m_Position, 0, 0);
		callerR4 = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(83, sub_82B40470, 0x82B40470) { ctx.r3.u64 = CBufferedFile_GrowLength(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Creates a CBufferedFile and opens it on the file name held at +24 of sourceAddr (the offset where a
// CBufferedFile keeps m_FileName).
uint64_t n_sub_82B40660(CpuState& ctx, uint8_t* base, uint64_t sourceAddr) {
	constexpr int32_t g_820A6A48 = int32_t(0x820A6A48);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(83, 0x82B40660)) { ctx.r3.u64 = sourceAddr; __imp__sub_82B40660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B40660);
	uint32_t stack = ctx.r1.u64;
	// MSR bits taken from r13 while the counter below is updated
	uint32_t lockedMsr = ctx.r13.u64;

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	uint64_t newObject = operator_new(ctx, base, 28);
	uint64_t result = 0;
	if ((uint32_t)newObject != 0) {
		const uint64_t vtableAddr = g_820A6A48;
		CBufferedFile* bufferedFile = GameObject<CBufferedFile>(base, (uint32_t)newObject);
		bufferedFile->vtable = (uint32_t)vtableAddr;
		bufferedFile->m_Length = 0;
		bufferedFile->m_Handle = 0;
		STORE8((uint32_t)newObject + 20, 0);
		bufferedFile->m_FileName = 0;

		// Atomically increment the global count at 0x83496EB8.
		const uint32_t counterAddr = uint32_t(g_83496EB8);
		uint64_t previousMsr = 0;
		uint64_t newCount = 0;
		bool stored = false;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			previousMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(counterAddr);
			newCount = (uint64_t)__builtin_bswap32(ctx.reserved.u32) + 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(counterAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)previousMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);

		// state the callee may pass on
		ctx.r7.u64 = vtableAddr;
		ctx.r9.u64 = newCount;
		// the last argument is the MSR value still in r8 from the loop
		CBufferedFile_Open(ctx, base, newObject, (int64_t)sourceAddr + 24, 1, 2, previousMsr);
		result = newObject;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B40660, 0x82B40660) { ctx.r3.u64 = n_sub_82B40660(ctx, base, ctx.r3.u64); }

// Converts the FILETIME at fileTimeAddr and stores its year, month, day, hour, minute, second and
// millisecond as seven 32-bit values at destAddr (the day of the week is not copied).
uint32_t SystemTime_FromFileTime(CpuState& ctx, uint8_t* base, uint32_t destAddr, uint32_t fileTimeAddr) {
	if (!UseLiftedCode(83, 0x82B482C8)) { ctx.r3.u64 = destAddr; ctx.r4.u64 = fileTimeAddr; __imp__sub_82B482C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B482C8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 112);
	// SYSTEMTIME on the stack: 16-bit year, month, day of week, day, hour, minute, second, millisecond
	uint32_t systemTime = stack + 80;
	ctx.r1.u64 = stack;
	uint32_t result = FileTimeToSystemTime(ctx, base, fileTimeAddr, systemTime);

	uint32_t year = LOAD16(systemTime + 0);
	uint32_t month = LOAD16(systemTime + 2);
	uint32_t day = LOAD16(systemTime + 6);
	uint32_t hour = LOAD16(systemTime + 8);
	uint32_t minute = LOAD16(systemTime + 10);
	uint32_t second = LOAD16(systemTime + 12);
	uint32_t millisecond = LOAD16(systemTime + 14);

	STORE32(destAddr + 0, year);
	STORE32(destAddr + 4, month);
	STORE32(destAddr + 8, day);
	STORE32(destAddr + 12, hour);
	STORE32(destAddr + 16, minute);
	STORE32(destAddr + 20, second);
	STORE32(destAddr + 24, millisecond);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B482C8, 0x82B482C8) { ctx.r3.u64 = SystemTime_FromFileTime(ctx, base, ctx.r3.u32, ctx.r4.u32); }
