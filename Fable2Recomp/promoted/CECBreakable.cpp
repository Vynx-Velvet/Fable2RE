// CECBreakable (vtable 0x820BD1E8): methods of the class as readable C++.
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

uint64_t CECBreakable_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820BD02C_B_ = int32_t(0x820BD02C);
	if (!UseLiftedCode(32, 0x8252DBB0)) { ctx.r3.u64 = classNameString; __imp__sub_8252DBB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252DBB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820BD02C_B_, -1);
	return classNameString;
}
PROMOTED_ENTRY(32, sub_8252DBB0, 0x8252DBB0) { ctx.r3.u64 = CECBreakable_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECBreakable_Destructor(CpuState& ctx, uint8_t* base, uint64_t breakableAddr, uint64_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(32, 0x8252DD08)) { ctx.r3.u64 = breakableAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8252DD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252DD08);
	uint32_t stack = ctx.r1.u64;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t objAddr = (uint32_t)breakableAddr;
	uint32_t handleListAddr = objAddr + 132;
	uint32_t resetHandleValue = uint32_t(g_820F1664);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	SharedPtrPairVector_Clear(ctx, base, objAddr + 156);
	SharedHandle_Release(ctx, base, objAddr + 148);

	uint32_t pendingHandle = breakable->m_88;

	if (pendingHandle != 0) {
		HandleRange_ReleaseAll(ctx, base, pendingHandle, LOAD32(handleListAddr + 8));
		HandleTarget_Free(ctx, base, LOAD32(handleListAddr + 4));
		pendingHandle = ctx.r4.u64;
	}

	STORE32(handleListAddr + 4, 0);
	STORE32(handleListAddr + 8, 0);
	STORE32(handleListAddr + 12, 0);
	breakable->m_50 = resetHandleValue;

	EntityHandle_Release(ctx, base, objAddr + 80);
	breakable->m_54 = 0;

	C_820EFB9C_Destructor(ctx, base, objAddr + 32);

	uint32_t targetHandle = breakable->m_14;
	if (targetHandle != 0) {
		HandleTarget_Free(ctx, base, targetHandle);
	}
	STORE32(objAddr + 20, 0);
	STORE32(objAddr + 24, 0);
	STORE32(objAddr + 28, 0);

	uint32_t secondaryVtableSlot = 0;
	if ((uint32_t)breakableAddr != 0) {
		secondaryVtableSlot = objAddr + 12;
	}
	STORE32(secondaryVtableSlot, 0x820A8F74u);
	breakable->vtable = 0x820A8D10u;

	if ((uint32_t)(deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, breakableAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return breakableAddr;
}
PROMOTED_ENTRY(32, sub_8252DD08, 0x8252DD08) { ctx.r3.u64 = CECBreakable_Destructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECBreakable_SerializeState(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t serializer, uint64_t arg3) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820A76D8_B_ = int32_t(0x820A76D8);
	constexpr int32_t str_TXT_820BCE08_B_ = int32_t(0x820BCE08);
	constexpr int32_t str_TXT_820BD0C4_B_ = int32_t(0x820BD0C4);
	constexpr int32_t str_TXT_820BD0F0_B_ = int32_t(0x820BD0F0);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(32, 0x8252E3A0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = serializer; ctx.r6.u64 = arg3; __imp__sub_8252E3A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252E3A0);
	PPCRegister callTarget{};

	uint32_t stack = ctx.r1.u64;
	const uint32_t breakable = (uint32_t)arg1;
	const uint32_t isSaving = (uint32_t)arg3 & 0xFF;
	const uint32_t entryMsr = ctx.r13.u64;

	stack = PushStackFrame(base, stack, 192);
	ctx.r1.u64 = stack;

	// TXT_820BD0F0_B_: default from the property-name block, or a global when the name is empty
	ctx.r6.u64 = arg3;
	CCharString_ConstructFromCStr(ctx, base, (uint64_t)(stack + 80), (uint64_t)str_TXT_820BD0F0_B_, (int64_t)-1);
	uint32_t nameData = LOAD32(stack + 80);
	uint64_t defaultValue = (nameData == 0) ? (uint64_t)(int64_t)g_8209003F : (uint64_t)LOAD32(nameData);
	IStream_SerializeFloat(ctx, base, serializer, arg1 + 88);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint64_t)(stack + 80));

	// TXT_820BD0C4_B_
	CCharString_ConstructFromCStr(ctx, base, (uint64_t)(stack + 80), (uint64_t)str_TXT_820BD0C4_B_, (int64_t)-1);
	IStream_SerializeString(ctx, base, (uint64_t)(stack + 80), serializer, arg1 + 172);
	uint64_t releaseResult = CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint64_t)(stack + 80));

	if (isSaving == 0) {
		// load: rebuild the referenced-entity list from the stream
		uint64_t controlBlock = operator_new(ctx, base, 16);
		uint64_t sharedHandle = 0;
		if ((uint32_t)controlBlock != 0) {
			sharedHandle = controlBlock;
			STORE32((uint32_t)controlBlock + 4, 0);
			STORE32((uint32_t)controlBlock + 8, 0);
			STORE32((uint32_t)controlBlock + 12, 0);
		}
		SharedHandle_Assign_82979160(ctx, base, (uint64_t)(uint32_t)(arg1 + 148), sharedHandle);

		const uint64_t openEntityName = (uint64_t)str_TXT_820BCE08_B_;
		const uint64_t uidName = (uint64_t)str_TXT_820A76D8_B_;
		const uint64_t refCountGlobal = (uint64_t)(int64_t)g_83496EB8;

		uint32_t openSlot = LOAD32(LOAD32((uint32_t)serializer) + 8);
		callTarget.u64 = (uint64_t)openSlot;
		ctx.r3.u64 = serializer;
		ctx.r4.u64 = openEntityName;
		ctx.r10.u64 = (uint64_t)openSlot;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t streamStatus = ctx.r3.u64;

		if ((streamStatus & 0xFF) != 0) {
			do {
				STORE32(stack + 88, 0);
				STORE32(stack + 92, 0);
				CCharString_ConstructFromCStr(ctx, base, (uint64_t)(stack + 80), uidName, (int64_t)-1);
				n_sub_8244DAE0(ctx, base, (uint64_t)(stack + 88), (uint64_t)(stack + 80), serializer);
				CCharString_Release(ctx, base, (uint64_t)(stack + 80));

				// atomic decrement of the global UID reference count
				uint64_t refCount = refCountGlobal;
				for (;;) {
					std::atomic_thread_fence(std::memory_order_seq_cst);
					uint32_t savedMsr = (uint32_t)REX_CHECK_GLOBAL_LOCK();
					std::atomic_thread_fence(std::memory_order_seq_cst);
					ctx.msr = entryMsr & 0x8020 | ctx.msr & ~0x8020;
					REX_ENTER_GLOBAL_LOCK();
					ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)refCount);
					uint32_t decremented = (uint32_t)((int32_t)__builtin_bswap32(ctx.reserved.u32) - 1);
					bool swapped = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)refCount)), ctx.reserved.s32, __builtin_bswap32((int32_t)decremented));
					std::atomic_thread_fence(std::memory_order_seq_cst);
					ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
					REX_LEAVE_GLOBAL_LOCK();
					if (swapped) break;
				}

				uint64_t uidLow = (uint64_t)LOAD32(stack + 88);
				STORE32(stack + 80, 0);
				if (uidLow != 0 || LOAD32(stack + 92) != 0) {
					VectorPair32_PushBack(ctx, base, (uint64_t)LOAD32(breakable + 148), (uint64_t)(stack + 88));
					uidLow = ctx.r8.u64;
					refCount = ctx.r9.u64;
				}

				uint32_t streamVtable = LOAD32((uint32_t)serializer);
				uint32_t closeSlot = LOAD32(streamVtable + 12);
				callTarget.u64 = (uint64_t)closeSlot;
				ctx.r3.u64 = serializer;
				ctx.r8.u64 = uidLow;
				ctx.r9.u64 = refCount;
				ctx.r10.u64 = (uint64_t)closeSlot;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				uint32_t reopenVtable = LOAD32((uint32_t)serializer);
				uint32_t reopenSlot = LOAD32(reopenVtable + 8);
				callTarget.u64 = (uint64_t)reopenSlot;
				ctx.r3.u64 = serializer;
				ctx.r4.u64 = openEntityName;
				ctx.r8.u64 = (uint64_t)reopenSlot;
				ctx.r9.u64 = (uint64_t)reopenVtable;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				streamStatus = ctx.r3.u64;
			} while ((streamStatus & 0xFF) != 0);
		}

		stack = PopStackFrame(stack, 192);
		ctx.r1.u64 = stack;
		return streamStatus;
	}

	// save: write one TXT_820BCE08_B_ record per live referenced entity
	uint64_t byteSize = (uint64_t)LOAD32(breakable + 140) - (uint64_t)LOAD32(breakable + 136);
	int32_t entryCount = (int32_t)byteSize >> 3;
	if (entryCount == 0) {
		stack = PopStackFrame(stack, 192);
		ctx.r1.u64 = stack;
		return releaseResult;
	}

	const uint64_t uidName = (uint64_t)str_TXT_820A76D8_B_;
	const uint64_t openEntityName = (uint64_t)str_TXT_820BCE08_B_;
	uint64_t elementAddr = 0;
	uint32_t index = 0;
	uint64_t elementOffset = 0;
	do {
		elementAddr = elementOffset + (uint64_t)LOAD32(breakable + 136);
		uint32_t entityHandle = LOAD32((uint32_t)elementAddr + 4);
		uint32_t entity = 0;
		bool shouldSerialize = false;
		if (entityHandle != 0) {
			entity = LOAD32(entityHandle);
			if (entity == 0) {
				elementAddr = EntityHandle_Release(ctx, base, elementAddr);
				byteSize = ctx.r9.u64;
			} else {
				shouldSerialize = (LOAD8(entity + 144) & 0x40) != 0;
			}
		}
		if (shouldSerialize) {
			uint32_t openSlot = LOAD32(LOAD32((uint32_t)serializer) + 4);
			callTarget.u64 = (uint64_t)openSlot;
			ctx.r3.u64 = serializer;
			ctx.r4.u64 = openEntityName;
			ctx.r8.u64 = (uint64_t)(int64_t)entryCount;
			ctx.r9.u64 = byteSize;
			ctx.r10.u64 = (uint64_t)openSlot;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			STORE64(stack + 96, LOAD64(entity + 20));
			CCharString_ConstructFromCStr(ctx, base, (uint64_t)(stack + 80), uidName, (int64_t)-1);
			n_sub_8244DAE0(ctx, base, (uint64_t)(stack + 96), (uint64_t)(stack + 80), serializer);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint64_t)(stack + 80));

			uint32_t streamVtable = LOAD32((uint32_t)serializer);
			uint32_t closeSlot = LOAD32(streamVtable + 12);
			callTarget.u64 = (uint64_t)closeSlot;
			ctx.r3.u64 = serializer;
			ctx.r7.u64 = (uint64_t)closeSlot;
			ctx.r8.u64 = (uint64_t)streamVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			elementAddr = ctx.r3.u64;
		}
		index++;
		elementOffset += 8;
		byteSize = (uint64_t)LOAD32(breakable + 140) - (uint64_t)LOAD32(breakable + 136);
		entryCount = (int32_t)byteSize >> 3;
	} while (index < (uint32_t)entryCount);

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return elementAddr;
}
PROMOTED_ENTRY(32, sub_8252E3A0, 0x8252E3A0) { ctx.r3.u64 = CECBreakable_SerializeState(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

uint64_t CECBreakable_ApplyPendingOpenEntities(CpuState& ctx, uint8_t* base, uint64_t breakableAddr) {
	if (!UseLiftedCode(32, 0x8252E688)) { ctx.r3.u64 = breakableAddr; __imp__sub_8252E688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252E688);
	uint32_t stack = ctx.r1.u64;
	uint64_t entity = ctx.r4.u64;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t pendingListAddr = (uint32_t)breakableAddr + 148;
	uint32_t pendingList = breakable->m_94;
	if (pendingList != 0) {
		uint64_t pendingBytes = (uint64_t)LOAD32(pendingList + 8) - (uint64_t)LOAD32(pendingList + 4);
		int32_t count = (int32_t)pendingBytes >> 3;
		for (uint32_t i = 0; i < (uint32_t)count; i++) {
			uint32_t entryAddr = LOAD32(pendingList + 4) + i * 8;
			uint32_t manager = LOAD32(0x83496920);
			uint32_t entityList = LOAD32(LOAD32(manager + 12) + 88);
			uint32_t handle = LOAD32(LOAD32(entityList + 4));
			ctx.r1.u64 = stack;
			entity = n_sub_82264448(ctx, base, handle, entryAddr);
			if (entity != 0) {
				uint32_t breakFlag = LOAD8((uint32_t)entity + 144) & 64;
				if (breakFlag != 0) {
					n_sub_82530DE8(ctx, base, breakableAddr, entity, 1);  // Lua_Breakable_SetOpenForEntity
					entity = ctx.r4.u64;
				}
			}
			pendingList = LOAD32(pendingListAddr);
			pendingBytes = (uint64_t)LOAD32(pendingList + 8) - (uint64_t)LOAD32(pendingList + 4);
			count = (int32_t)pendingBytes >> 3;
		}
		ctx.r1.u64 = stack;
		breakableAddr = SharedHandle_Release(ctx, base, pendingListAddr);
		STORE32(pendingListAddr, 0u);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return breakableAddr;
}
PROMOTED_ENTRY(32, sub_8252E688, 0x8252E688) { ctx.r3.u64 = CECBreakable_ApplyPendingOpenEntities(ctx, base, ctx.r3.u64); }

uint64_t CECBreakable_ResetPieces(CpuState& ctx, uint8_t* base, uint64_t breakableAddr) {
	constexpr int32_t TXT_834985B0_G_ = int32_t(0x834985B0);
	constexpr int32_t TXT_834985B4_G_ = int32_t(0x834985B4);
	if (!UseLiftedCode(32, 0x8252E760)) { ctx.r3.u64 = breakableAddr; __imp__sub_8252E760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252E760);
	uint32_t stack = ctx.r1.u64;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t pieceAddr = breakableAddr + 116;

	uint32_t flags = LOAD32(uint32_t(breakable->m_4) + 48);
	uint32_t isVaultable = (flags >> 17) & 1;
	uint64_t pieceType = (isVaultable != 0) ? (uint64_t)TXT_834985B4_G_ : (uint64_t)TXT_834985B0_G_;

	ctx.r1.u64 = stack;
	n_sub_82682EE0(ctx, base, pieceAddr);

	STORE32((uint32_t)pieceAddr, 0u);
	CECBreakable_ReleasePhysicsHandle(ctx, base, breakableAddr);
	uint64_t result = BreakablePieceList_Clear(ctx, base, breakableAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_8252E760, 0x8252E760) { ctx.r3.u64 = CECBreakable_ResetPieces(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82530CC0(CpuState& ctx, uint8_t* base, uint64_t breakableAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(32, 0x82530CC0)) { ctx.r3.u64 = breakableAddr; __imp__sub_82530CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82530CC0);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t engineTime = LOAD32(0x8331950Cu);
	const uint32_t motionOffset = 96;

	// ask the object hanging off the breakable whether it is currently busy
	uint32_t owner = LOAD32(uint32_t(breakable->m_4) + 124);
	uint32_t ownerVtable = LOAD32(owner);
	uint32_t isBusyFn = LOAD32(ownerVtable + 88);
	callTarget.u64 = isBusyFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = owner;
	ctx.r8.u64 = isBusyFn;
	ctx.r9.u64 = ownerVtable;
	ctx.r10.s64 = g_83320000;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint64_t result = ctx.r3.u64;
	uint32_t busy = (uint32_t)result & 0xFF;
	PPCVRegister scaledMotion = ctx.v10;

	if (busy == 0) {
		// integrate the piece transform: pos +/- vel * scale
		PPCVRegister motion, velocity, scaleSplat, scaleTmp, newMotion;
		bool addMotion = (engineTime & 1) != 0;
		SET_V8(motion, VLOAD((uint32_t)breakableAddr + motionOffset & ~0xF));
		ctx.fpscr.disableFlushMode();
		double scale = double(LOAD_F32(0x821001E8u));
		STORE_F32(stack + 80, float(scale));
		scratch.u32 = uint32_t((int64_t)(uint64_t)stack + 80);
		SET_V8(scaleTmp, simde_mm_shuffle_epi8(
			simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
			simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(scaleSplat, simde_mm_shuffle_epi32(V8(scaleTmp), 0xFF));
		SET_V8(velocity, VLOAD((uint32_t)breakableAddr + 48u & ~0xF));
		if (addMotion) {
			ctx.fpscr.enableFlushModeUnconditional();
			SET_VF(newMotion, simde_mm_add_ps(simde_mm_mul_ps(VF(velocity), VF(scaleSplat)), VF(motion)));
		} else {
			ctx.fpscr.enableFlushMode();
			SET_VF(scaledMotion, simde_mm_mul_ps(VF(velocity), VF(scaleSplat)));
			SET_VF(newMotion, simde_mm_sub_ps(VF(motion), VF(scaledMotion)));
		}

		uint32_t owner2 = LOAD32(uint32_t(breakable->m_4) + 124);
		uint32_t ownerVtable2 = LOAD32(owner2);
		uint32_t setMotionFn = LOAD32(ownerVtable2 + 100);
		callTarget.u64 = setMotionFn;
		ctx.r3.u64 = owner2;
		ctx.r7.u64 = busy;
		ctx.r9.u64 = setMotionFn;
		ctx.r10.u64 = ownerVtable2;
		ctx.v1 = newMotion;
		ctx.v10 = scaledMotion;
		ctx.v11 = velocity;
		ctx.v12 = scaleSplat;
		ctx.v13 = scaleTmp;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
	}

	uint64_t age = (uint64_t)engineTime - (uint64_t)breakable->m_70;
	int32_t ageTicks = (int32_t)age;
	ctx.fpscr.disableFlushMode();
	double lifetime = LOAD_F64(0x83319510u) * LOAD_F64(0x82100618u);
	STORE64(stack + 80, (uint64_t)(int64_t)ageTicks);
	double ageRawBits = LOAD_F64(stack + 80);
	double ageValue = double((int64_t)LOAD64(stack + 80));

	if (ageValue > lifetime) {
		uint32_t owner3 = LOAD32(uint32_t(breakable->m_4) + 124);
		uint32_t ownerVtable3 = LOAD32(owner3);
		uint32_t isDoneFn = LOAD32(ownerVtable3 + 88);
		callTarget.u64 = isDoneFn;
		ctx.r3.u64 = owner3;
		ctx.r7.s64 = ageTicks;
		ctx.r8.u64 = age;
		ctx.r9.u64 = isDoneFn;
		ctx.r10.u64 = ownerVtable3;
		ctx.f12.f64 = ageValue;
		ctx.f13.f64 = ageRawBits;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t busy2 = ctx.r3.u32 & 0xFF;
		if (busy2 == 0) {
			PPCVRegister motion2;
			SET_V8(motion2, VLOAD((uint32_t)breakableAddr + motionOffset & ~0xF));
			uint32_t owner4 = LOAD32(uint32_t(breakable->m_4) + 124);
			uint32_t ownerVtable4 = LOAD32(owner4);
			uint32_t setMotionFn2 = LOAD32(ownerVtable4 + 100);
			callTarget.u64 = setMotionFn2;
			ctx.r3.u64 = owner4;
			ctx.r8.u64 = busy2;
			ctx.r9.u64 = setMotionFn2;
			ctx.r10.u64 = ownerVtable4;
			ctx.v1 = motion2;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		result = Vector_RemoveByValue(ctx, base, uint32_t(breakable->m_4), breakableAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82530CC0, 0x82530CC0) { ctx.r3.u64 = n_sub_82530CC0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82530DE8(CpuState& ctx, uint8_t* base, uint64_t breakableAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(32, 0x82530DE8)) { ctx.r3.u64 = breakableAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82530DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82530DE8);
	uint32_t stack = ctx.r1.u64;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);
	uint32_t breakableEntity = (uint32_t)breakableAddr;
	uint64_t targetEntity = arg2;
	const uint32_t handleTag = uint32_t(g_820F1664);
	uint64_t returnValue = breakableAddr;

	stack = PushStackFrame(base, stack, 176);
	const uint32_t searchHandle = stack + 80;
	const uint32_t findHandle   = stack + 88;
	const uint32_t rangeTmp     = stack + 96;
	const uint32_t listAddr     = breakableEntity + 132;

	STORE32(searchHandle, 0);

	uint32_t targetFlags = 0;
	bool validTarget = false;
	if ((uint32_t)targetEntity != 0) {
		targetFlags = LOAD8((uint32_t)targetEntity + 144) & 64;
		if (targetFlags != 0)
			validTarget = true;
	}

	if (validTarget) {
		bool shouldOpen = ((uint32_t)arg3 & 0xFF) != 0;
		bool foundOpen = false;
		bool foundClose = false;
		bool searchArmed = false;
		bool closeArmed = false;
		uint64_t releaseR9 = 0;
		uint64_t releaseR10 = 0;
		uint64_t findR9 = 0;
		uint64_t closeReleaseR9 = 0;
		uint64_t closeReleaseR10 = 0;

		if (shouldOpen) {
			STORE32(searchHandle, handleTag);
			STORE32(searchHandle + 4, 0);
			ctx.r1.u64 = stack;
			ctx.r5.u64 = arg3;
			EntityHandle_SetTarget(ctx, base, searchHandle, targetEntity);
			uint32_t owner = breakable->m_8C;
			returnValue = EntityHandleList_Find(ctx, base, findHandle, listAddr, searchHandle);
			arg2 = ctx.r4.u64;
			arg3 = ctx.r5.u64;
			searchArmed = true;
			foundOpen = (LOAD32((uint32_t)returnValue + 4) == owner);
		}

		if (searchArmed) {
			STORE32(searchHandle, handleTag);
			ctx.r1.u64 = stack;
			returnValue = EntityHandle_Release(ctx, base, searchHandle);
			arg2 = ctx.r4.u64;
			arg3 = ctx.r5.u64;
			releaseR9 = ctx.r9.u64;
			releaseR10 = ctx.r10.u64;
		}

		if (foundOpen) {
			STORE32(searchHandle, handleTag);
			STORE32(searchHandle + 4, 0);
			ctx.r1.u64 = stack;
			ctx.r5.u64 = arg3;
			EntityHandle_SetTarget(ctx, base, searchHandle, targetEntity);
			Vector8_PushBack(ctx, base, listAddr, searchHandle);
			STORE32(searchHandle, handleTag);
			EntityHandle_Release(ctx, base, searchHandle);
			returnValue = Breakable_PostSetOpenForEntityMessage(ctx, base, breakableAddr, targetEntity, 1);
			stack = PopStackFrame(stack, 176);
			ctx.r1.u64 = stack;
			return returnValue;
		}

		if (!shouldOpen) {
			STORE32(searchHandle, handleTag);
			STORE32(searchHandle + 4, 0);
			ctx.r1.u64 = stack;
			ctx.r5.u64 = arg3;
			EntityHandle_SetTarget(ctx, base, searchHandle, targetEntity);
			uint32_t owner = breakable->m_8C;
			returnValue = EntityHandleList_Find(ctx, base, findHandle, listAddr, searchHandle);
			arg2 = ctx.r4.u64;
			arg3 = ctx.r5.u64;
			findR9 = ctx.r9.u64;
			closeArmed = true;
			foundClose = (LOAD32((uint32_t)returnValue + 4) != owner);
		}

		if (closeArmed) {
			STORE32(searchHandle, handleTag);
			ctx.r1.u64 = stack;
			returnValue = EntityHandle_Release(ctx, base, searchHandle);
			arg2 = ctx.r4.u64;
			arg3 = ctx.r5.u64;
			closeReleaseR9 = ctx.r9.u64;
			closeReleaseR10 = ctx.r10.u64;
		}

		if (foundClose) {
			STORE32(searchHandle, handleTag);
			STORE32(searchHandle + 4, 0);
			ctx.r1.u64 = stack;
			ctx.r5.u64 = arg3;
			EntityHandle_SetTarget(ctx, base, searchHandle, targetEntity);
			uint32_t findResult = EntityHandleList_Find(ctx, base, findHandle, listAddr, searchHandle);
			uint64_t foundValue = LOAD64(findResult);
			HandleRange_PopBack(ctx, base, rangeTmp, listAddr, foundValue);
			STORE32(searchHandle, handleTag);
			EntityHandle_Release(ctx, base, searchHandle);
			returnValue = Breakable_PostSetOpenForEntityMessage(ctx, base, breakableAddr, targetEntity, 0);
			arg2 = ctx.r4.u64;
			arg3 = ctx.r5.u64;
		}
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = arg3;
	return returnValue;
}
PROMOTED_ENTRY(32, sub_82530DE8, 0x82530DE8) { ctx.r3.u64 = n_sub_82530DE8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t Breakable_PostSetOpenForEntityMessage(CpuState& ctx, uint8_t* base, uint32_t breakableAddr, uint64_t targetEntity, uint64_t isOpen) {
	if (!UseLiftedCode(32, 0x82531230)) { ctx.r3.u64 = breakableAddr; ctx.r4.u64 = targetEntity; ctx.r5.u64 = isOpen; __imp__sub_82531230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82531230);
	uint32_t stack = ctx.r1.u64;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t container = breakable->m_4;
	uint64_t entityId = 0;
	bool hasEntity = false;

	if (uint32_t((LOAD32(container + 44) >> 27) & 1) != 0) {
		uint32_t indexTable = LOAD32(container + 140);
		if (indexTable != 0) {
			// direct slot lookup: index stored as a byte in the table
			uint32_t slotOffset = __builtin_rotateleft32(LOAD8(indexTable + 91), 3);
			uint32_t begin = LOAD32(container + 72);
			entityId = LOAD32(uint32_t(slotOffset + begin) + 4);
			hasEntity = true;
		} else {
			// lower_bound over the sorted (key, entity) table for key 91
			uint32_t begin = LOAD32(container + 72);
			reg6 = LOAD32(container + 76);
			uint32_t it = begin;
			uint32_t remaining = reg6 - begin;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, it);
			flags.ca = (int32_t)remaining < 0 & (remaining & 0x7) != 0;
			remaining = (int32_t)remaining >> 3;
			if ((int32_t)remaining > 0) {
				do {
					flags.ca = (int32_t)remaining < 0 & (remaining & 0x1) != 0;
					uint32_t half = (int32_t)remaining >> 1;
					uint32_t offset = half << 3;
					it = offset + it;
					compare6.compare<int32_t>(int32_t(LOAD32(it)), 91, flags);
					reg7 = 1;
					if (!compare6.lt) reg7 = 0;
					reg7 = (uint32_t)reg7 & 0xFF;
					if ((uint32_t)reg7 != 0) {
						remaining = remaining - half;
						it = (int32_t)it + 8;
						remaining = (int32_t)remaining - 1;
					} else {
						it = it - offset;
						remaining = half;
					}
				} while ((int32_t)remaining > 0);
				STORE32(stack + 84, it);
			}
			uint32_t record = (uint32_t)reg6;
			if (it != (uint32_t)reg6) {
				compare6.compare<int32_t>(int32_t(LOAD32(it)), 91, flags);
				uint32_t isAboveKey = 1;
				if (!compare6.gt) isAboveKey = 0;
				if (isAboveKey == 0) record = it;
			}
			entityId = LOAD32(record + 4);
			hasEntity = true;
		}
	}

	if (hasEntity) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		entityId = CECNetwork_ShouldReplicateEntity(ctx, base, entityId);
		if ((uint32_t(entityId) & 0xFF) != 0) {
			STORE8(stack + 84, (uint8_t)isOpen);
			STORE64(stack + 88, 0);
			STORE32(stack + 80, 0x820A43F4u);
			uint64_t messageId = Entity_GetUniqueId(ctx, base, targetEntity);
			flags.ca = ctx.xer.ca;
			STORE64(stack + 88, messageId);
			uint32_t senderEntity = breakable->m_4;
			uint32_t hittable = LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 140);
			uint64_t senderId = Entity_GetUniqueId(ctx, base, senderEntity);
			flags.ca = ctx.xer.ca;
			entityId = Hittable_PostSetOnlyHittableByEntity(ctx, base, hittable, stack + 80, senderId);
			targetEntity = ctx.r4.u64;
			isOpen = ctx.r5.u64;
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = targetEntity;
	ctx.r5.u64 = isOpen;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	return entityId;
}
PROMOTED_ENTRY(32, sub_82531230, 0x82531230) { ctx.r3.u64 = Breakable_PostSetOpenForEntityMessage(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t CECBreakable_InitPhysicsSimulation(CpuState& ctx, uint8_t* base, uint64_t breakableAddr) {
	constexpr int32_t str_TXT_820BD03C_B_ = int32_t(0x820BD03C);
	if (!UseLiftedCode(32, 0x82531608)) { ctx.r3.u64 = breakableAddr; __imp__sub_82531608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82531608);
	uint32_t stack = ctx.r1.u64;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);
	uint32_t breakablePtr = (uint32_t)breakableAddr;
	stack = PushStackFrame(base, stack, 128);

	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t r9Value = 0;
	uint32_t isDynamicSimulation = 0;
	PPCXERRegister flags = ctx.xer;

	uint32_t container = breakable->m_4;
	if (((LOAD32(container + 44) >> 12) & 1) == 0) {
		uint32_t hasSimConfig = (LOAD32(container + 36) >> 2) & 1;
		if (hasSimConfig != 0) {
			uint32_t simEntryPtr;
			uint32_t indexPtr = LOAD32(container + 140);
			uint32_t tableBegin = LOAD32(container + 72);
			if (indexPtr != 0) {
				uint32_t index = LOAD8(indexPtr + 2);
				simEntryPtr = tableBegin + index * 8;
			} else {
				uint32_t tableEnd = LOAD32(container + 76);
				STORE32(stack + 88, 0u);
				STORE32(stack + 92, tableBegin);
				uint32_t pos = tableBegin;
				reg6 = tableEnd;
				reg8 = (uint64_t)tableEnd - (uint64_t)tableBegin;
				flags.ca = ((int32_t)(uint32_t)reg8 < 0) & (((uint32_t)reg8 & 0x7) != 0);
				int32_t remaining = ((int32_t)(uint32_t)reg8) >> 3;
				if (remaining > 0) {
					do {
						flags.ca = (remaining < 0) & ((remaining & 0x1) != 0);
						int32_t half = remaining >> 1;
						uint32_t byteHalf = (uint32_t)half << 3;
						reg8 = byteHalf;
						pos = pos + byteHalf;
						bool isLess = (int32_t)LOAD32(pos) < 2;
						reg7 = isLess ? 1 : 0;
						reg7 = (uint32_t)reg7 & 0xFF;
						if (isLess) {
							remaining = remaining - half - 1;
							pos = pos + 8;
						} else {
							pos = pos - byteHalf;
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 92, pos);
				}
				uint32_t entry;
				if (pos != tableEnd) {
					if ((int32_t)LOAD32(pos) > 2) {
						entry = tableEnd;
					} else {
						STORE64(stack + 88, LOAD64(stack + 88));
						entry = pos;
					}
				} else {
					entry = tableEnd;
				}
				simEntryPtr = entry;
			}
			uint32_t simEntry = LOAD32(simEntryPtr + 4);

			ctx.r1.u64 = stack;
			ctx.xer.ca = flags.ca;
			CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820BD03C_B_, -1);

			uint32_t vtable = LOAD32(simEntry);
			uint32_t getter = LOAD32(vtable + 20);
			PPCRegister callTarget{};
			callTarget.u64 = getter;
			ctx.r3.u64 = stack + 88;
			ctx.r4.u64 = simEntry;
			ctx.r9.u64 = getter;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t objectSimName = LOAD32(ctx.r3.u32);
			uint32_t dynamicName = LOAD32(stack + 80);
			if (objectSimName == dynamicName) {
				isDynamicSimulation = 1;
				ctx.r4.u64 = dynamicName;
			} else if (objectSimName != 0 && dynamicName != 0) {
				isDynamicSimulation = CCharString_Equals(ctx, base, objectSimName, dynamicName);
			} else {
				isDynamicSimulation = 0;
				ctx.r4.u64 = dynamicName;
			}
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
			breakableAddr = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
			r9Value = ctx.r9.u64;
		} else {
			isDynamicSimulation = 0;
			r9Value = 0;
		}
		if ((isDynamicSimulation & 0xFF) == 0 && LOAD32(breakablePtr + 128) == 0xFFFFFFFF) {
			uint32_t container2 = breakable->m_4;
			ctx.r1.u64 = stack;
			breakableAddr = n_sub_82639C30(ctx, base, container2);
			STORE32(breakablePtr + 128, (uint32_t)breakableAddr);   // breakable->m_80
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return breakableAddr;
}
PROMOTED_ENTRY(32, sub_82531608, 0x82531608) { ctx.r3.u64 = CECBreakable_InitPhysicsSimulation(ctx, base, ctx.r3.u64); }

uint64_t CECBreakable_ReleasePhysicsHandle(CpuState& ctx, uint8_t* base, uint32_t breakableAddr) {
	if (!UseLiftedCode(32, 0x825317F0)) { ctx.r3.u64 = breakableAddr; __imp__sub_825317F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825317F0);
	uint32_t stack = ctx.r1.u64;
	uint64_t savedR8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;
	CECBreakable* breakable = GameObject<CECBreakable>(base, breakableAddr);

	stack = PushStackFrame(base, stack, 112);

	uint32_t subObj = breakable->m_4;
	uint32_t recordAddr = 0;
	bool found = false;

	if ((LOAD32(subObj + 44) >> 12) & 1) {
		uint32_t slotIndex = LOAD32(subObj + 140);
		if (slotIndex != 0) {
			uint64_t entryAddr = (uint64_t)__builtin_rotateleft32(LOAD8(slotIndex + 76), 3) + (uint64_t)LOAD32(subObj + 72);
			savedR8 = entryAddr;
			recordAddr = LOAD32((uint32_t)entryAddr + 4);
			found = true;
		} else {
			uint32_t begin = LOAD32(subObj + 72);
			uint32_t end = LOAD32(subObj + 76);
			uint32_t byteCount = end - begin;
			uint32_t pos = begin;

			STORE32(stack + 80, 0);
			STORE32(stack + 84, begin);
			flags.ca = ((int32_t)byteCount < 0) & ((byteCount & 7) != 0);

			// lower_bound by key 76 over the sorted (key, record) pairs
			int32_t count = (int32_t)byteCount >> 3;
			if (count > 0) {
				do {
					flags.ca = 0;
					int32_t half = count >> 1;
					uint32_t offset = (uint32_t)(half << 3);
					pos = offset + pos;
					savedR8 = offset;
					if ((int32_t)LOAD32(pos) < 76) {
						pos = pos + 8;
						count = count - half - 1;
					} else {
						pos = pos - offset;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, pos);
			}

			if (pos != end && (int32_t)LOAD32(pos) <= 76) {
				STORE64(stack + 80, LOAD64(stack + 80));
				recordAddr = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				recordAddr = LOAD32(end + 4);
			}
			found = true;
		}
	}

	uint64_t handleId = 0;
	if (found) {
		handleId = LOAD32(recordAddr + 60);
		if ((int32_t)handleId != -1) {
			ctx.r1.u64 = stack;
			ctx.xer.ca = flags.ca;
			handleId = n_sub_8263A788(ctx, base, handleId, 4);
			savedR8 = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
			STORE32(recordAddr + 60, 0xFFFFFFFFu);
		}
	} else {
		handleId = breakable->m_80;
		if ((int32_t)handleId != -1) {
			ctx.r1.u64 = stack;
			ctx.xer.ca = flags.ca;
			handleId = n_sub_8263A788(ctx, base, handleId, 4);
			savedR8 = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
			breakable->m_80 = 0xFFFFFFFFu;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = savedR8;
	ctx.xer.ca = flags.ca;
	return handleId;
}
PROMOTED_ENTRY(32, sub_825317F0, 0x825317F0) { ctx.r3.u64 = CECBreakable_ReleasePhysicsHandle(ctx, base, ctx.r3.u32); }

uint64_t BreakablePieceList_Clear(CpuState& ctx, uint8_t* base, uint64_t breakable) {
	if (!UseLiftedCode(32, 0x82531F48)) { ctx.r3.u64 = breakable; __imp__sub_82531F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82531F48);
	uint32_t stack = ctx.r1.u64;
	uint64_t savedR8 = ctx.r8.u64;
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	// piece list: vector of 12-byte slots {ref-counted piece, shared handle}
	const uint32_t listAddr = (uint32_t)breakable + 156;
	uint32_t slot = LOAD32((uint32_t)breakable + 160);
	const uint32_t listEnd = LOAD32((uint32_t)breakable + 164);
	if (slot > listEnd) {
		ppc_trap(ctx, base, 22);
	}
	if (LOAD32(listAddr + 4) > listEnd) {
		ppc_trap(ctx, base, 22);
	}

	uint64_t result = breakable;

	while (slot != listEnd) {
		if (slot >= LOAD32(listAddr + 8)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t handleAddr = slot + 4;
		const uint32_t pieceManager = LOAD32(LOAD32(LOAD32(0x83496920) + 12) + 88);
		const uint32_t pieceId = LOAD32(pieceManager + 4);
		ctx.r1.u64 = stack;
		BreakablePieceList_RemoveById(ctx, base, pieceId, handleAddr);

		if (slot >= LOAD32(listAddr + 8)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t piece = LOAD32(slot);
		if (piece != 0) {
			const uint32_t refCountAddr = piece + 4;
			const uint32_t remainingRefs = LOAD32(refCountAddr) - 1;
			STORE32(refCountAddr, remainingRefs);
			if (remainingRefs == 0) {
				const uint32_t releaseFn = LOAD32(LOAD32(piece) + 4);
				PPCRegister callTarget{};
				callTarget.u64 = releaseFn;
				ctx.r3.u64 = piece;
				ctx.r9.u64 = refCountAddr;
				ctx.r10.u64 = releaseFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
			}
			STORE32(slot, 0);
		}
		STORE32(slot, 0);

		if (slot >= LOAD32(listAddr + 8)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		ctx.r1.u64 = stack;
		result = SharedHandle_Release(ctx, base, handleAddr);
		savedR8 = ctx.r8.u64;
		STORE32(handleAddr, 0);

		if (slot >= LOAD32(listAddr + 8)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		slot += 12;
	}

	// release whatever is still in the list, then drop it to empty
	const uint32_t liveBegin = LOAD32(listAddr + 4);
	const uint32_t liveEnd = LOAD32(listAddr + 8);
	if (liveBegin > liveEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	if (liveBegin != liveEnd) {
		for (uint32_t resetSlot = liveBegin; resetSlot != liveEnd; resetSlot += 12) {
			ctx.r1.u64 = stack;
			result = SharedPtrPair_Reset(ctx, base, resetSlot);
			savedR8 = ctx.r8.u64;
		}
		STORE32(listAddr + 8, liveBegin);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = savedR8;
	return result;
}
PROMOTED_ENTRY(32, sub_82531F48, 0x82531F48) { ctx.r3.u64 = BreakablePieceList_Clear(ctx, base, ctx.r3.u64); }
