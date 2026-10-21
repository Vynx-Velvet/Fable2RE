// CVirtualFileSystem (vtable 0x8200E17C): methods of the class as readable C++.
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

uint64_t CVirtualFileSystem_AddRef(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(92, 0x82C700F0)) { ctx.r3.u64 = arg1; __imp__sub_82C700F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C700F0);
	// CVirtualFileSystem::AddRef: atomically increment the reference count word at offset 0x0C.
	uint32_t* refCountWord = reinterpret_cast<uint32_t*>(RAW(arg1 + 12));
	uint32_t oldWord = 0;
	uint64_t newRefCount = 0;
	do {
		oldWord = *refCountWord;
		newRefCount = (uint64_t)__builtin_bswap32(oldWord) + 1;
	} while (!__sync_bool_compare_and_swap(refCountWord, oldWord, __builtin_bswap32((uint32_t)newRefCount)));
	return newRefCount;
}
PROMOTED_ENTRY(92, sub_82C700F0, 0x82C700F0) { ctx.r3.u64 = CVirtualFileSystem_AddRef(ctx, base, ctx.r3.u32); }

// sub_82C70118  [40 bytes]
uint64_t CVirtualFileSystem_ReleaseRefCount(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(92, 0x82C70118)) { ctx.r3.u64 = object; __imp__sub_82C70118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C70118);
	uint32_t refCountAddr = object + 12;
	uint32_t savedMsr = ctx.r13.u32;
	uint64_t newCount{};
	uint32_t lockToken{};
	PPCCRRegister compare0{};
	PPCXERRegister flags{};
	flags.so = ctx.xer.so;
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		lockToken = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
		newCount = (int64_t)__builtin_bswap32(ctx.reserved.u32) - 1;
		compare0.lt = 0;
		compare0.gt = 0;
		compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
		compare0.so = flags.so;
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = lockToken & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!compare0.eq);
	return newCount;
}
PROMOTED_ENTRY(92, sub_82C70118, 0x82C70118) { ctx.r3.u64 = CVirtualFileSystem_ReleaseRefCount(ctx, base, ctx.r3.u32); }

// sub_82C70140  [204 bytes]
uint64_t CVirtualFileSystem_QueryInterface(CpuState& ctx, uint8_t* base, uint64_t virtualFileSystemAddr, uint64_t interfaceId, uint64_t interfaceOut) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(92, 0x82C70140)) { ctx.r3.u64 = virtualFileSystemAddr; ctx.r4.u64 = interfaceId; ctx.r5.u64 = interfaceOut; __imp__sub_82C70140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C70140);
	uint32_t stack = ctx.r1.u64;
	uint32_t result{};
	uint64_t lastNameByte{};
	uint32_t typeNameByte{};
	uint64_t nameDiff{};
	PPCRegister callTarget{};
	const uint32_t nameAddr = (uint32_t)interfaceId;
	const uint32_t nameEnd = (uint32_t)interfaceId + 16;
	CVirtualFileSystem* virtualFileSystem = GameObject<CVirtualFileSystem>(base, virtualFileSystemAddr);
	stack = PushStackFrame(base, stack, 96);

	const uint64_t errorNoInterface = 0xFFFFFFFF80004002ull;

	STORE32((uint32_t)interfaceOut, 0u);

	// The 16-byte name must match one of the two registered type names.
	uint32_t i = (uint32_t)(g_820A0000 + 32256);
	uint32_t k = nameAddr;
	do {
		lastNameByte = LOAD8(k);
		typeNameByte = LOAD8(i);
		nameDiff = lastNameByte - (uint64_t)typeNameByte;
		if ((int32_t)nameDiff != 0) break;
		k++;
		i++;
	} while (k != nameEnd);

	if ((int32_t)nameDiff != 0) {
		uint32_t j = (uint32_t)(g_82010000 - 25472);
		uint32_t n = nameAddr;
		do {
			lastNameByte = LOAD8(n);
			typeNameByte = LOAD8(j);
			nameDiff = lastNameByte - (uint64_t)typeNameByte;
			if ((int32_t)nameDiff != 0) break;
			n++;
			j++;
		} while (n != nameEnd);
		if ((int32_t)nameDiff != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			ctx.r4.u64 = interfaceId;
			return errorNoInterface;
		}
	}

	STORE32((uint32_t)interfaceOut, (uint32_t)virtualFileSystemAddr);
	if ((uint32_t)virtualFileSystemAddr == 0) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = interfaceId;
		return errorNoInterface;
	}

	uint32_t vtableMethod = LOAD32((uint32_t)virtualFileSystem->vtable + 4);
	callTarget.u64 = (uint64_t)vtableMethod;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = virtualFileSystemAddr;
	ctx.r4.u64 = interfaceId;
	ctx.r5.u64 = interfaceOut;
	ctx.r7.u64 = lastNameByte;
	ctx.r8.u64 = (uint64_t)nameEnd;
	ctx.r9.u64 = nameDiff;
	ctx.r10.u64 = vtableMethod;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	result = 0;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(92, sub_82C70140, 0x82C70140) { ctx.r3.u64 = CVirtualFileSystem_QueryInterface(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CVirtualFileSystem_AcquireVolumeA(CpuState& ctx, uint8_t* base, uint64_t virtualFileSystemAddr) {
	if (!UseLiftedCode(92, 0x82C70210)) { ctx.r3.u64 = virtualFileSystemAddr; __imp__sub_82C70210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C70210);
	uint32_t stack = ctx.r1.u64;
	CVirtualFileSystem* virtualFileSystem = GameObject<CVirtualFileSystem>(base, virtualFileSystemAddr);

	stack = PushStackFrame(base, stack, 112);
	uint32_t lockGuard = stack + 80;
	ctx.r1.u64 = stack;
	uint64_t lockGuardPtr = String_Construct(ctx, base, lockGuard, virtualFileSystemAddr + 16, 0);

	if (virtualFileSystem->m_VolumeARefCount == 0) {
		uint8_t created = CVirtualFileSystem_EnsureInitialized(ctx, base) & 0xFF;
		if (created == 0) {
			CriticalSectionGuard_Release(ctx, base, lockGuard);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 0xFFFFFFFF80004005ull;
		}

		uint32_t volumeStorage = operator_new(ctx, base, 296);
		uint32_t newVolume;
		if (volumeStorage != 0) {
			newVolume = VolumeA_Constructor(ctx, base, volumeStorage, virtualFileSystemAddr);
		} else {
			newVolume = 0;
		}
		virtualFileSystem->m_VolumeA = newVolume;

		uint8_t initialized = VolumeA_Initialize(ctx, base, newVolume) & 0xFF;
		uint32_t volumeA = virtualFileSystem->m_VolumeA;
		if (initialized == 0) {
			if (volumeA != 0) {
				uint32_t vtable = LOAD32(volumeA);
				uint32_t destroyFn = LOAD32(vtable);
				PPCRegister callTarget{};
				callTarget.u64 = (uint64_t)destroyFn;
				ctx.r3.u64 = volumeA;
				ctx.r4.u64 = 1;
				ctx.r10.u64 = (uint64_t)destroyFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
			}
			virtualFileSystem->m_VolumeA = 0u;
			CriticalSectionGuard_Release(ctx, base, lockGuard);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 0xFFFFFFFF80004005ull;
		}

		Volume_Activate(ctx, base, volumeA);
	}

	uint32_t oldRefCount = virtualFileSystem->m_VolumeARefCount;
	virtualFileSystem->m_VolumeARefCount = oldRefCount + 1;
	CriticalSectionGuard_Release(ctx, base, lockGuard);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C70210, 0x82C70210) { ctx.r3.u64 = CVirtualFileSystem_AcquireVolumeA(ctx, base, ctx.r3.u64); }

uint64_t CVirtualFileSystem_ReleaseVolumeA(CpuState& ctx, uint8_t* base, uint64_t virtualFileSystemAddr) {
	if (!UseLiftedCode(92, 0x82C70328)) { ctx.r3.u64 = virtualFileSystemAddr; __imp__sub_82C70328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C70328);
	CVirtualFileSystem* virtualFileSystem = GameObject<CVirtualFileSystem>(base, virtualFileSystemAddr);

	PPCXERRegister flags{};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint64_t guardAddr = (uint64_t)stack + 80;

	ctx.r1.u64 = stack;
	String_Construct(ctx, base, guardAddr, virtualFileSystemAddr + 16, 0);

	uint32_t refCount = virtualFileSystem->m_VolumeARefCount;
	flags.ca = refCount > 0;
	refCount = (int32_t)refCount - 1;
	virtualFileSystem->m_VolumeARefCount = refCount;

	if ((int32_t)refCount == 0) {
		uint32_t volumeA = virtualFileSystem->m_VolumeA;
		virtualFileSystem->m_VolumeA = 0u;
		ctx.xer.ca = flags.ca;
		CriticalSectionGuard_Release(ctx, base, guardAddr);
		flags.ca = ctx.xer.ca;

		uint32_t vtable = LOAD32(volumeA);
		uint32_t closeFn = LOAD32(vtable + 8);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)closeFn;
		ctx.r3.u64 = (uint64_t)volumeA;
		ctx.r9.u64 = (uint64_t)closeFn;
		ctx.r10.u64 = (uint64_t)vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		flags.ca = ctx.xer.ca;

		uint32_t vtable2 = LOAD32(volumeA);
		uint32_t destroyFn = LOAD32(vtable2);
		callTarget.u64 = (uint64_t)destroyFn;
		ctx.r3.u64 = (uint64_t)volumeA;
		ctx.r4.u64 = 1;
		ctx.r7.u64 = (uint64_t)destroyFn;
		ctx.r8.u64 = (uint64_t)vtable2;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		flags.ca = ctx.xer.ca;

		n_sub_82C72B38(ctx, base);
		flags.ca = ctx.xer.ca;
	}

	ctx.xer.ca = flags.ca;
	CriticalSectionGuard_Release(ctx, base, guardAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C70328, 0x82C70328) { ctx.r3.u64 = CVirtualFileSystem_ReleaseVolumeA(ctx, base, ctx.r3.u64); }

// sub_82C703C8  [276 bytes]
uint64_t CVirtualFileSystem_AcquireVolumeB(CpuState& ctx, uint8_t* base, uint64_t virtualFileSystemAddr) {
	if (!UseLiftedCode(92, 0x82C703C8)) { ctx.r3.u64 = virtualFileSystemAddr; __imp__sub_82C703C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C703C8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CVirtualFileSystem* virtualFileSystem = GameObject<CVirtualFileSystem>(base, virtualFileSystemAddr);

	stack = PushStackFrame(base, stack, 112);
	uint32_t guardAddr = stack + 80;
	ctx.r1.u64 = stack;
	uint64_t guard = String_Construct(ctx, base, guardAddr, virtualFileSystemAddr + 16, 0);

	if (virtualFileSystem->m_VolumeBRefCount == 0) {
		uint32_t vfsReady = CVirtualFileSystem_EnsureInitialized(ctx, base);
		if ((vfsReady & 0xFF) == 0) {
			CriticalSectionGuard_Release(ctx, base, guardAddr);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 0xFFFFFFFF80004005ull;
		}

		uint32_t volumeStorage = operator_new(ctx, base, 292);
		uint32_t volumeB;
		if (volumeStorage != 0) {
			volumeB = VolumeB_Constructor(ctx, base, volumeStorage, virtualFileSystemAddr);
		} else {
			volumeB = 0;
		}
		virtualFileSystem->m_VolumeB = volumeB;

		uint32_t volumeInitOk = VolumeB_Initialize(ctx, base, volumeB);
		volumeB = virtualFileSystem->m_VolumeB;
		if ((volumeInitOk & 0xFF) == 0) {
			if (volumeB != 0) {
				uint32_t vtable = LOAD32(volumeB);
				callTarget.u64 = vtable;
				ctx.r3.u64 = volumeB;
				ctx.r4.u64 = 1;
				ctx.r10.u64 = vtable;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
			}
			virtualFileSystem->m_VolumeB = 0u;
			CriticalSectionGuard_Release(ctx, base, guardAddr);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 0xFFFFFFFF80004005ull;
		}
		Volume_Activate(ctx, base, volumeB);
	}

	uint32_t refCount = virtualFileSystem->m_VolumeBRefCount;
	refCount = refCount + 1;
	virtualFileSystem->m_VolumeBRefCount = refCount;
	CriticalSectionGuard_Release(ctx, base, guardAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C703C8, 0x82C703C8) { ctx.r3.u64 = CVirtualFileSystem_AcquireVolumeB(ctx, base, ctx.r3.u64); }

// sub_82C704E0  [108 bytes]
uint64_t CVirtualFileSystem_ReleaseVolumeB(CpuState& ctx, uint8_t* base, uint64_t virtualFileSystemAddr) {
	if (!UseLiftedCode(92, 0x82C704E0)) { ctx.r3.u64 = virtualFileSystemAddr; __imp__sub_82C704E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C704E0);
	uint32_t stack = ctx.r1.u64;
	uint32_t refCount{};
	PPCXERRegister flags{};
	PPCRegister callTarget{};
	CVirtualFileSystem* virtualFileSystem = GameObject<CVirtualFileSystem>(base, virtualFileSystemAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	uint32_t guardString = stack + 80;
	String_Construct(ctx, base, guardString, virtualFileSystemAddr + 16, 0);

	refCount = virtualFileSystem->m_VolumeBRefCount;
	flags.ca = refCount > 0;
	refCount = (int32_t)refCount - 1;
	virtualFileSystem->m_VolumeBRefCount = refCount;
	if ((int32_t)refCount == 0) {
		uint32_t volumeB = virtualFileSystem->m_VolumeB;
		uint32_t releaseFn = LOAD32(LOAD32(volumeB) + 8);
		callTarget.u64 = releaseFn;
		ctx.r3.u64 = volumeB;
		ctx.r10.u64 = releaseFn;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		flags.ca = ctx.xer.ca;
		n_sub_82C72B38(ctx, base);
		flags.ca = ctx.xer.ca;
	}

	ctx.xer.ca = flags.ca;
	CriticalSectionGuard_Release(ctx, base, guardString);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C704E0, 0x82C704E0) { ctx.r3.u64 = CVirtualFileSystem_ReleaseVolumeB(ctx, base, ctx.r3.u64); }

uint64_t CVirtualFileSystem_SetTimeoutSeconds(CpuState& ctx, uint8_t* base, uint32_t virtualFileSystemAddr, uint32_t timeoutSeconds) {
	if (!UseLiftedCode(92, 0x82C70550)) { ctx.r3.u64 = virtualFileSystemAddr; ctx.r4.u64 = timeoutSeconds; __imp__sub_82C70550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C70550);
	CVirtualFileSystem* virtualFileSystem = GameObject<CVirtualFileSystem>(base, virtualFileSystemAddr);
	virtualFileSystem->m_TimeoutSeconds = timeoutSeconds;
	return 0;
}
PROMOTED_ENTRY(92, sub_82C70550, 0x82C70550) { ctx.r3.u64 = CVirtualFileSystem_SetTimeoutSeconds(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CVirtualFileSystem_AddFile(CpuState& ctx, uint8_t* base, uint32_t virtualFileSystem, uint64_t widePath, uint64_t wideStrSource, uint64_t lookupArg, uint64_t flags) {
	if (!UseLiftedCode(92, 0x82C71398)) { ctx.r3.u64 = virtualFileSystem; ctx.r4.u64 = widePath; ctx.r5.u64 = wideStrSource; ctx.r6.u64 = lookupArg; ctx.r8.u64 = flags; __imp__sub_82C71398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C71398);
	uint32_t stack = ctx.r1.u64;
	__savegprlr_27(ctx, base);
	uint32_t frameBase = stack - 192;
	stack = PushStackFrame(base, stack, 192);

	if (int32_t(LOAD32(virtualFileSystem + 8)) != 0) {
		ctx.r1.u64 = stack;
		uint64_t charCount = wcslen(ctx, base, widePath) + 1;
		uint32_t allocSize = static_cast<uint32_t>(-charCount) & 0xFFFFFFF0u;
		alloca_probe(ctx, base, allocSize);

		uint32_t savedLink = LOAD32(stack);
		uint32_t allocBase = stack + allocSize;
		STORE32(allocBase, savedLink);
		stack = allocBase;

		uint32_t textBuffer = stack + 80;
		ctx.r1.u64 = stack;
		ctx.r10.u64 = savedLink;
		WString_ToNarrowString(ctx, base, textBuffer, widePath, charCount, flags);

		ctx.r3.u64 = textBuffer;
		uint64_t textHash = NetDll_inet_addr(ctx, base);

		uint32_t sourceStr = frameBase + 112;
		BasicWString_ConstructFromWideCStr(ctx, base, sourceStr, wideStrSource, ctx.r8.u64);

		if (int32_t(textHash) != -1) {
			STORE32(frameBase + 100, 0u);
			STORE32(frameBase + 104, 7u);
			STORE16(frameBase + 84, 0);
			uint32_t searchStr = frameBase + 80;
			BasicWString_AssignSubstr(ctx, base, searchStr, sourceStr, 0, -1, ctx.r8.u64);
			uint32_t found = CVirtualFileSystem_AddFileEntry(ctx, base, virtualFileSystem, textHash, searchStr, lookupArg);
			if ((found & 0xFF) != 0) {
				WString_Tidy(ctx, base, sourceStr);
				ctx.r1.u64 = frameBase + 192;
				__restgprlr_27(ctx, base);
				return 0;
			}
		}
		WString_Tidy(ctx, base, sourceStr);
		widePath = ctx.r4.u64;
	}

	// E_FAIL (0x80004005) sign-extended into the 64-bit return value
	uint64_t result = 0xFFFFFFFF80004005ull;
	ctx.r1.u64 = frameBase + 192;
	__restgprlr_27(ctx, base);
	ctx.r4.u64 = widePath;
	return result;
}
PROMOTED_ENTRY(92, sub_82C71398, 0x82C71398) { ctx.r3.u64 = CVirtualFileSystem_AddFile(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint64_t CVirtualFileSystem_RemoveFile(CpuState& ctx, uint8_t* base, uint64_t virtualFileSystem, uint64_t file, uint64_t flags) {
	if (!UseLiftedCode(92, 0x82C71D68)) { ctx.r3.u64 = virtualFileSystem; ctx.r4.u64 = file; ctx.r8.u64 = flags; __imp__sub_82C71D68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C71D68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 224);

	uint32_t vfs = (uint32_t)virtualFileSystem;
	uint32_t lockGuard = stack + 96;    // scope guard on vfs+0x10, owns a path string (+16)
	uint32_t guardPath = stack + 112;   // that path string
	uint32_t tempPath = stack + 144;    // scratch string built from the wide name
	uint32_t wideNameOut = stack + 80;  // out slot of the virtual call below
	uint32_t foundEntry = stack + 88;   // find() result (owner, node)
	PPCRegister callTarget{};

	// Frees the guard string's heap buffer, resets it to the empty inline buffer and unlocks.
	auto releaseGuard = [&](uint32_t guard) {
		if (LOAD32(guard + 40) >= 8) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(guard + 20));
		}
		STORE32(guard + 40, 7);
		STORE32(guard + 36, 0);
		STORE16(guard + 20, 0);
		CriticalSectionGuard_Release(ctx, base, guard);
	};

	ctx.r1.u64 = stack;
	ctx.r8.u64 = flags;
	String_Construct(ctx, base, lockGuard, vfs + 16, 0);

	STORE32(guardPath + 20, 0);
	STORE32(guardPath + 24, 7);
	STORE16(guardPath + 4, 0);

	uint32_t vtable = LOAD32((uint32_t)file);
	uint32_t getWideName = LOAD32(vtable + 16);
	ctx.r3.u64 = file;
	ctx.r4.u64 = wideNameOut;
	ctx.r10.u64 = getWideName;
	callTarget.u64 = getWideName;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	int32_t status = ctx.r3.u32;
	if (status < 0) {
		releaseGuard(lockGuard);
		stack = PopStackFrame(stack, 224);
		ctx.r1.u64 = stack;
		return 0xFFFFFFFF80004005ull;
	}

	uint32_t wideNamePtr = LOAD32(wideNameOut);
	uint64_t wideName = BasicWString_ConstructFromWideCStr(ctx, base, tempPath, wideNamePtr, ctx.r8.u64);

	BasicWString_AssignSubstr(ctx, base, guardPath, wideName, 0, -1, ctx.r8.u64);
	if (LOAD32(tempPath + 24) >= 8) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(tempPath + 4));
	}
	STORE32(tempPath + 24, 7);
	STORE32(tempPath + 20, 0);
	STORE16(tempPath + 4, 0);

	uint32_t fileMap = vfs + 52;
	CVirtualFileSystem_FindFile(ctx, base, foundEntry, fileMap, guardPath, ctx.r8.u64);

	uint32_t entryOwner = LOAD32(foundEntry);
	uint32_t endNode = LOAD32(fileMap + 4);
	uint64_t result = 0;
	if (entryOwner == 0 || entryOwner != fileMap) {
		ppc_trap(ctx, base, 22);
	}
	uint32_t node = LOAD32(foundEntry + 4);
	if (node == endNode) {
		result = 0xFFFFFFFF80004005ull;
	} else {
		if (entryOwner == 0) {
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(entryOwner + 4)) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t fileObject = LOAD32(node + 40);
		FileMap_Erase(ctx, base, foundEntry, fileMap, LOAD64(foundEntry), ctx.r8.u64);
		uint32_t dispose = LOAD32(LOAD32(fileObject) + 8);
		ctx.r3.u64 = fileObject;
		ctx.r10.u64 = dispose;
		callTarget.u64 = dispose;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	releaseGuard(lockGuard);
	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(92, sub_82C71D68, 0x82C71D68) { ctx.r3.u64 = CVirtualFileSystem_RemoveFile(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CVirtualFileSystem_Destructor(CpuState& ctx, uint8_t* base, uint64_t virtualFileSystemAddr) {
	if (!UseLiftedCode(92, 0x82C725A8)) { ctx.r3.u64 = virtualFileSystemAddr; __imp__sub_82C725A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C725A8);
	uint32_t stack = ctx.r1.u64;
	CVirtualFileSystem* virtualFileSystem = GameObject<CVirtualFileSystem>(base, virtualFileSystemAddr);
	stack = PushStackFrame(base, stack, 128);

	virtualFileSystem->vtable = 0x8200E17Cu;

	ctx.r1.u64 = stack;
	List_Clear(ctx, base, (uint32_t)virtualFileSystemAddr + 0x40);

	HandleTarget_FreeThunk(ctx, base, virtualFileSystem->m_44);
	virtualFileSystem->m_44 = 0;

	uint32_t listSentinelAddr = (uint32_t)virtualFileSystemAddr + 0x34;
	uint32_t listHead = virtualFileSystem->m_38;
	uint32_t listHeadNext = LOAD32(listHead);

	// the callee takes two 8-byte list iterators by value and an out slot on the stack
	STORE32(stack + 80, listSentinelAddr);
	STORE32(stack + 84, listHead);
	STORE32(stack + 88, listSentinelAddr);
	STORE32(stack + 92, listHeadNext);

	uint64_t firstIterator = LOAD64(stack + 88);
	uint64_t secondIterator = LOAD64(stack + 80);
	FileMap_EraseRange(ctx, base, stack + 88, listSentinelAddr, firstIterator, secondIterator);

	HandleTarget_FreeThunk(ctx, base, virtualFileSystem->m_38);
	virtualFileSystem->m_38 = 0;
	virtualFileSystem->m_3C = 0;

	n_sub_829CE870(ctx, base);

	uint64_t result = virtualFileSystemAddr + 0x10;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(92, sub_82C725A8, 0x82C725A8) { ctx.r3.u64 = CVirtualFileSystem_Destructor(ctx, base, ctx.r3.u64); }
