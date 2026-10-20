// CECParticleEmitter (vtable 0x82003AD8): methods of the class as readable C++.
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

uint64_t CECParticleEmitter_UpdateTransform(CpuState& ctx, uint8_t* base, uint64_t particleEmitterAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(4, 0x821EC718)) { ctx.r3.u64 = particleEmitterAddr; __imp__sub_821EC718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821EC718);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vecArg12{};
	PPCVRegister vecArg13{};
	PPCVRegister vecTmp{};
	PPCVRegister vecResult{};
	uint32_t effectAddr = 0;
	uint32_t outStructAddr = 0;
	uint32_t outVectorAddr = 0;
	uint64_t argR5 = 0;
	uint64_t argR6 = 0;
	uint64_t argR8 = 0;
	uint64_t argR9 = 0;
	uint64_t argR10 = 0;
	bool carry = false;
	uint64_t result = 0;

	CECParticleEmitter* particleEmitter = GameObject<CECParticleEmitter>(base, particleEmitterAddr);
	stack = PushStackFrame(base, stack, 176);
	outStructAddr = stack + 96;
	outVectorAddr = stack + 128;

	uint64_t elementBytes = (uint64_t)particleEmitter->m_34 - (uint64_t)particleEmitter->m_30;
	carry = ((int32_t)elementBytes < 0) & (((uint32_t)elementBytes & 0x7) != 0);
	uint64_t elementCount = (uint64_t)(int64_t)((int32_t)elementBytes >> 3);

	if ((uint32_t)elementCount > 1) {
		ctx.r1.u64 = stack;
		ctx.r8.u64 = elementCount;
		ctx.r9.u64 = elementBytes;
		ctx.xer.ca = carry;
		result = CECParticleEmitter_UpdateMultipleRanges(ctx, base, particleEmitterAddr);
	} else {
		if (LOAD8((uint32_t)particleEmitterAddr + 0x43) != 0) {
			// Effect object exposes a pair of virtual accessors (vtable +0x44 / +0x40).
			effectAddr = LOAD32(uint32_t(particleEmitter->m_entity) + 124);
			uint32_t effectVtable = LOAD32(effectAddr);
			uint32_t firstAccessor = LOAD32(effectVtable + 68);

			callTarget.u64 = firstAccessor;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = stack + 112;
			ctx.r4.u64 = effectAddr;
			ctx.r8.u64 = elementCount;
			ctx.r9.u64 = firstAccessor;
			ctx.r10.u64 = effectVtable;
			ctx.xer.ca = carry;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			argR8 = ctx.r3.u64;
			argR9 = ctx.r9.u64;
			vecArg12 = ctx.v12;
			vecArg13 = ctx.v13;
			carry = ctx.xer.ca;
			argR6 = LOAD32(effectAddr);
			argR5 = LOAD64((uint32_t)argR8);
			uint64_t argR5High = LOAD64((uint32_t)argR8 + 8);
			argR10 = LOAD32((uint32_t)argR6 + 64);
			STORE64(outStructAddr, argR5);
			STORE64(outStructAddr + 8, argR5High);
			callTarget.u64 = argR10;
		} else {
			uint32_t entity = particleEmitter->m_entity;
			uint64_t constPage = (uint64_t)g_820A0000;
			uint64_t splatAddr = (uint64_t)stack + 80;

			argR9 = splatAddr;
			argR8 = constPage;
			argR6 = constPage - 28224;
			ctx.fpscr.disableFlushMode();
			effectAddr = LOAD32(entity + 124);
			STORE_F32(stack + 80, float(double(LOAD_F32(0x820994C0u))));

			scratch.u32 = (uint32_t)splatAddr;
			SET_V8(vecTmp, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_V8(vecArg13, simde_mm_shuffle_epi32(V8(vecTmp), 0xFF));
			SET_V8(vecTmp, VLOAD((uint32_t)argR6 & ~0xF));
			argR5 = LOAD32(effectAddr);
			SET_V8(vecArg12, simde_mm_and_si128(V8(vecArg13), V8(vecTmp)));
			argR10 = entity;
			uint32_t secondAccessor = LOAD32((uint32_t)argR5 + 64);
			VSTORE((uint32_t)outStructAddr & ~0xF, V8(vecArg12));
			callTarget.u64 = secondAccessor;
		}

		ctx.r1.u64 = stack;
		ctx.r3.u64 = outVectorAddr;
		ctx.r4.u64 = effectAddr;
		ctx.r5.u64 = argR5;
		ctx.r6.u64 = argR6;
		ctx.r7.u64 = outStructAddr;
		ctx.r8.u64 = argR8;
		ctx.r9.u64 = argR9;
		ctx.r10.u64 = argR10;
		ctx.v12 = vecArg12;
		ctx.v13 = vecArg13;
		ctx.xer.ca = carry;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t resultVectorAddr = ctx.r3.u32;
		carry = ctx.xer.ca;
		SET_V8(vecResult, VLOAD(resultVectorAddr & ~0xF));
		result = particleEmitter->m_emitter;
		if ((uint32_t)result != 0) {
			SET_V8(vecTmp, VLOAD(0x8349E230u & ~0xF));
			ctx.v1 = vecResult;
			ctx.v2 = vecTmp;
			ParticleEmitter_SetTransform(ctx, base, result);
			uint64_t hi = LOAD64(stack + 104);
			uint64_t lo = LOAD64(stack + 96);
			uint64_t emitter = particleEmitter->m_emitter;
			result = ParticleEmitter_SetParticleData(ctx, base, emitter, lo, hi);
		}
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(4, sub_821EC718, 0x821EC718) { ctx.r3.u64 = CECParticleEmitter_UpdateTransform(ctx, base, ctx.r3.u64); }

uint64_t CECParticleEmitter_UpdateIfType10(CpuState& ctx, uint8_t* base, uint64_t particleEmitterAddr, uint64_t entity) {
	if (!UseLiftedCode(4, 0x821EC840)) { ctx.r3.u64 = particleEmitterAddr; ctx.r4.u64 = entity; __imp__sub_821EC840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821EC840);
	uint32_t stack = ctx.r1.u64;

	stack = PushStackFrame(base, stack, 112);
	uint32_t object = (uint32_t)entity;
	uint32_t vtable = LOAD32(object);
	uint32_t getTypeFunction = LOAD32(vtable + 4);

	ctx.r1.u64 = stack;
	ctx.r3.u64 = entity;
	ctx.r4.u64 = entity;
	ctx.r10.u64 = getTypeFunction;
	REX_CALL_INDIRECT_FUNC(getTypeFunction);
	uint64_t result = ctx.r3.u64;

	if ((int32_t)result == 10) {
		ctx.r4.u64 = entity;
		result = CECParticleEmitter_UpdateTransform(ctx, base, particleEmitterAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(4, sub_821EC840, 0x821EC840) { ctx.r3.u64 = CECParticleEmitter_UpdateIfType10(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECParticleEmitter_GetClassName(CpuState& ctx, uint8_t* base, uint64_t result) {
	constexpr int32_t str_TXT_820B4DEC_B_ = int32_t(0x820B4DEC);
	if (!UseLiftedCode(27, 0x8247E558)) { ctx.r3.u64 = result; __imp__sub_8247E558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8247E558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t classNameCStr = uint64_t(str_TXT_820B4DEC_B_);
	int32_t classNameLength = -1;

	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, result, classNameCStr, classNameLength);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_8247E558, 0x8247E558) { ctx.r3.u64 = CECParticleEmitter_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECParticleEmitter_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t particleEmitterAddr, uint32_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(27, 0x8247E688)) { ctx.r3.u64 = particleEmitterAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8247E688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8247E688);
	uint32_t stack = ctx.r1.u64;
	CECParticleEmitter* particleEmitter = GameObject<CECParticleEmitter>(base, particleEmitterAddr);
	stack = PushStackFrame(base, stack, 128);

	// Range list at 0x2C: +0 count, +4 begin, +8 end, +0xC capacity.
	const uint32_t rangeListAddr = (uint32_t)particleEmitterAddr + 44;
	const uint32_t rangeBegin = LOAD32(rangeListAddr + 4);
	uint64_t rangeHandleValue = 0;
	if (rangeBegin != 0) {
		const uint32_t rangeEnd = LOAD32(rangeListAddr + 8);
		ctx.r1.u64 = stack;
		CharStringRange_Destroy(ctx, base, rangeBegin, rangeEnd);
		HandleTarget_Free(ctx, base, LOAD32(rangeListAddr + 4));
		rangeHandleValue = ctx.r4.u64;
	}

	const uint32_t invalidStringIndex = (uint32_t)g_820F1664;
	STORE32(rangeListAddr + 4, 0);
	STORE32(rangeListAddr + 8, 0);
	STORE32(rangeListAddr + 12, 0);
	particleEmitter->m_emitterName = invalidStringIndex;

	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, (uint32_t)particleEmitterAddr + 36);
	particleEmitter->m_28 = 0;

	particleEmitter->m_1C = invalidStringIndex;
	EntityHandle_Release(ctx, base, (uint32_t)particleEmitterAddr + 28);
	particleEmitter->m_20 = 0;

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint32_t)particleEmitterAddr + 24);
	SharedHandle_Release(ctx, base, (uint32_t)particleEmitterAddr + 16);

	uint32_t embeddedObjectAddr = 0;
	if ((uint32_t)particleEmitterAddr != 0) {
		embeddedObjectAddr = (uint32_t)particleEmitterAddr + 12;
	}
	STORE32(embeddedObjectAddr, 0x820FCC84u);
	particleEmitter->vtable = 0x820A8D10u;

	if (deleteFlags & 0x1) {
		HandleTarget_Free(ctx, base, particleEmitterAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return particleEmitterAddr;
}
PROMOTED_ENTRY(27, sub_8247E688, 0x8247E688) { ctx.r3.u64 = CECParticleEmitter_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CECParticleEmitter_CreateEmitter(CpuState& ctx, uint8_t* base, uint64_t particleEmitter) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(27, 0x8247E870)) { ctx.r3.u64 = particleEmitter; __imp__sub_8247E870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8247E870);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsr = ctx.r13.u64;
	stack = PushStackFrame(base, stack, 128);

	const uint32_t emitter = (uint32_t)particleEmitter;
	const uint32_t emitterHandleField = emitter + 16;   // shared handle owning the emitter object
	const uint32_t nameStringField = emitter + 24;      // CCharString name of the emitter
	const uint32_t tempString = stack + 80;             // stack temp reused for string then shared handle
	const uint32_t tempHandle = stack + 88;             // stack temp holding a copied shared handle

	if (LOAD32(emitterHandleField) != 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	ctx.r1.u64 = stack;
	CCharString_CopyTransformed(ctx, base, tempString, nameStringField);
	uint64_t definition = CCharString_GetHash(ctx, base, tempString);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempString);
	if ((uint32_t)definition == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	SharedHandle_AssignFromObject(ctx, base, tempString, definition);
	if (LOAD32(tempString) == 0) {
		SharedHandle_Release(ctx, base, tempString);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	uint64_t objectMemory = operator_new(ctx, base, 72);
	uint64_t newEmitter = 0;
	if ((uint32_t)objectMemory != 0) {
		newEmitter = ParticleEmitter_ConstructFromDefinition(ctx, base, objectMemory, tempString);
	}
	SharedPtr_ResetWithPointerE(ctx, base, emitterHandleField, newEmitter);

	STORE32(LOAD32(emitterHandleField) + 40, emitter + 12);
	STORE32(LOAD32(emitterHandleField) + 4, (uint32_t)definition);

	uint32_t handleObject = LOAD32(emitterHandleField);
	uint32_t refCount = LOAD32(emitterHandleField + 4);
	STORE32(stack + 92, refCount);
	STORE32(tempHandle, handleObject);

	// intrusive refcount acquire on the freshly stored handle
	if (refCount != 0) {
		for (;;) {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCount);
			uint32_t newCount = __builtin_bswap32(ctx.reserved.u32);
			newCount = (int32_t)newCount + 1;
			bool swapped = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCount)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
			if (swapped) break;
		}
	}

	ctx.r8.u64 = handleObject;
	SharedHandle_Destroy(ctx, base, tempHandle);

	uint32_t globalTable = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t manager = LOAD32(LOAD32(globalTable + 12) + 88);
	ParticleManager_AddEmitter(ctx, base, manager, emitterHandleField);

	CECParticleEmitter_PostParticleCreateEvent(ctx, base, emitter);
	SharedHandle_Release(ctx, base, tempString);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(27, sub_8247E870, 0x8247E870) { ctx.r3.u64 = CECParticleEmitter_CreateEmitter(ctx, base, ctx.r3.u64); }

uint32_t CECParticleEmitter_PostParticleCreateEvent(CpuState& ctx, uint8_t* base, uint64_t particleEmitterAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820B4E48_B_ = int32_t(0x820B4E48);
	if (!UseLiftedCode(27, 0x8247E998)) { ctx.r3.u64 = particleEmitterAddr; __imp__sub_8247E998(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8247E998);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	uint64_t savedR6 = ctx.r6.u64;
	uint64_t savedR8 = ctx.r8.u64;
	CECParticleEmitter* particleEmitter = GameObject<CECParticleEmitter>(base, particleEmitterAddr);
	stack = PushStackFrame(base, stack, 208);

	uint32_t eventId = 0;
	bool hasEvent = false;
	uint32_t entityAddr = particleEmitter->m_entity;
	if ((LOAD32(entityAddr + 52) >> 7) & 1) {
		uint32_t eventIndex = LOAD32(entityAddr + 140);
		if (eventIndex != 0) {
			uint32_t slot = LOAD8(eventIndex + 135);
			uint32_t eventTable = LOAD32(entityAddr + 72);
			eventId = LOAD32(eventTable + (slot << 3) + 4);
		} else {
			uint32_t eventsBegin = LOAD32(entityAddr + 72);
			uint32_t eventsEnd = LOAD32(entityAddr + 76);
			savedR6 = eventsEnd;
			STORE32(stack + 88, eventId);
			uint32_t byteDiff = eventsEnd - eventsBegin;
			STORE32(stack + 92, eventsBegin);
			flags.ca = ((int32_t)byteDiff < 0) && ((byteDiff & 7) != 0);
			int32_t remaining = (int32_t)byteDiff >> 3;
			uint32_t entry = eventsBegin;
			if (remaining > 0) {
				// binary search for the first entry whose key is not below 135
				do {
					int32_t half = remaining >> 1;
					uint32_t offset = (uint32_t)half << 3;
					uint32_t mid = entry + offset;
					savedR8 = offset;
					flags.ca = 0;  // remaining is positive here, so the lifted carry is clear
					if ((int32_t)LOAD32(mid) < 135) {
						entry = mid + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 92, entry);
			}
			if (entry != eventsEnd && (int32_t)LOAD32(entry) <= 135) {
				STORE64(stack + 88, LOAD64(stack + 88));  // search cursor is kept in the stack slot
				entry = LOAD32(stack + 92);
				eventId = LOAD32(entry + 4);
			} else {
				eventId = LOAD32(eventsEnd + 4);
			}
		}
		hasEvent = true;
	}

	if (hasEvent) {
		ctx.r1.u64 = stack;
		ctx.r6.u64 = savedR6;
		ctx.xer.ca = flags.ca;
		CCharString_ConstructFromCStr(ctx, base, stack + 88, g_82000C98, -1);
		flags.ca = ctx.xer.ca;
		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B4E48_B_, -1);
		flags.ca = ctx.xer.ca;
		RefCountedString_Assign(ctx, base, stack + 80, particleEmitterAddr + 24);
		flags.ca = ctx.xer.ca;
		EventArgument_ConstructFromString(ctx, base, stack + 112, stack + 80);
		flags.ca = ctx.xer.ca;
		EventManager_RaiseEvent(ctx, base, stack + 96, eventId, stack + 112, stack + 88);
		flags.ca = ctx.xer.ca;
		OwnedPtr_Reset(ctx, base, stack + 96);
		flags.ca = ctx.xer.ca;
		CCharString_ReleaseMember(ctx, base, stack + 112);
		flags.ca = ctx.xer.ca;
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		flags.ca = ctx.xer.ca;
		particleEmitterAddr = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
		flags.ca = ctx.xer.ca;
	}
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return particleEmitterAddr;
}
PROMOTED_ENTRY(27, sub_8247E998, 0x8247E998) { ctx.r3.u64 = CECParticleEmitter_PostParticleCreateEvent(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8247F750(CpuState& ctx, uint8_t* base, uint32_t particleEmitterAddr, uint64_t particleContainer) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(27, 0x8247F750)) { ctx.r3.u64 = particleEmitterAddr; ctx.r4.u64 = particleContainer; __imp__sub_8247F750(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8247F750);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	uint64_t local6 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;

	CECParticleEmitter* particleEmitter = GameObject<CECParticleEmitter>(base, particleEmitterAddr);
	stack = PushStackFrame(base, stack, 160);
	uint64_t containerPtr = particleContainer;
	uint64_t result = particleEmitter->m_emitter;

	if ((uint32_t)result != 0) {
		uint32_t beginPtr = LOAD32((uint32_t)containerPtr + 4);
		uint32_t byteSize = (uint32_t)((uint64_t)LOAD32((uint32_t)containerPtr + 8) - beginPtr) & 0xFFFFFFF0u;
		local6 = byteSize;
		if ((int32_t)byteSize != 0) {
			PPCVRegister beginVec{};
			PPCVRegister constVec{};
			SET_V8(beginVec, VLOAD(beginPtr & ~0xF));

			uint64_t floatScratchAddr = (uint64_t)stack + 80;
			int32_t constBase1 = g_820A0000;
			int32_t constBase2 = g_834A0000;
			uint64_t mask1Addr = (uint64_t)((int64_t)constBase1 - 28224);
			ctx.fpscr.disableFlushMode();
			uint64_t vecOutAddr = (uint64_t)stack + 96;
			STORE_F32(stack + 80, float(double(LOAD_F32(0x820994C0u))));
			uint64_t mask2Addr = (uint64_t)((int64_t)constBase2 - 7632);

			scratch.u32 = (uint32_t)floatScratchAddr;
			PPCVRegister vecTemp{};
			SET_V8(vecTemp, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			PPCVRegister vecSplat{};
			SET_V8(vecSplat, simde_mm_shuffle_epi32(V8(vecTemp), 0xFF));
			SET_V8(vecTemp, VLOAD((uint32_t)mask1Addr & ~0xF));
			PPCVRegister vecResult{};
			SET_V8(vecResult, simde_mm_and_si128(V8(vecSplat), V8(vecTemp)));
			SET_V8(constVec, VLOAD((uint32_t)mask2Addr & ~0xF));
			VSTORE((uint32_t)vecOutAddr & ~0xF, V8(vecResult));

			ctx.r1.u64 = stack;
			ctx.r4.u64 = vecOutAddr;
			ctx.r5.u64 = mask1Addr;
			ctx.r6.u64 = mask2Addr;
			ctx.r7.s64 = constBase1;
			ctx.r8.s64 = constBase2;
			ctx.r9.u64 = floatScratchAddr;
			ctx.v1 = beginVec;
			ctx.v2 = constVec;
			ParticleEmitter_SetTransform(ctx, base, result);

			uint64_t arg18 = LOAD64(stack + 96);
			uint32_t emitter = particleEmitter->m_emitter;
			uint64_t arg22 = LOAD64(stack + 104);
			ParticleEmitter_SetParticleData(ctx, base, emitter, arg18, arg22);

			uint32_t emitter2 = particleEmitter->m_emitter;
			STORE32(stack + 100, 0);
			STORE32(stack + 104, 0);
			STORE32(stack + 108, 0);
			ParticleEmitter_CollectParticles(ctx, base, emitter2, vecOutAddr);
			particleContainer = ctx.r4.u64;
			local6 = ctx.r8.u64;

			result = LOAD32(stack + 104);
			uint32_t freePtr = LOAD32(stack + 100);
			uint32_t byteDiff = (uint32_t)(result - (uint64_t)freePtr);
			flags.ca = ((int32_t)byteDiff < 0) & ((byteDiff & 0x3) != 0);
			uint32_t count = (uint32_t)((int32_t)byteDiff >> 2);
			if ((int32_t)count != 0) {
				uint32_t it = freePtr;
				do {
					uint32_t element = LOAD32(it);
					ctx.xer.ca = flags.ca;
					result = n_sub_8322AC90(ctx, base, element, containerPtr);
					particleContainer = ctx.r4.u64;
					local6 = ctx.r8.u64;
					flags.ca = count > 0;
					count--;
					it += 4;
				} while ((int32_t)count != 0);
			}
			if (freePtr != 0) {
				ctx.xer.ca = flags.ca;
				result = HandleTarget_Free(ctx, base, freePtr);
				particleContainer = ctx.r4.u64;
				local6 = ctx.r8.u64;
				flags.ca = ctx.xer.ca;
			}
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = particleContainer;
	ctx.r8.u64 = local6;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(27, sub_8247F750, 0x8247F750) { ctx.r3.u64 = n_sub_8247F750(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CECParticleEmitter_DestroyParticleList(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(27, 0x8247FB68)) { ctx.r3.u64 = arg1; __imp__sub_8247FB68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8247FB68);
	uint64_t particleList = LOAD32((uint32_t)arg1 + 16);
	if ((uint32_t)particleList == 0) return particleList;
	return Vector_DeletePointerElements(ctx, base, particleList);
}
PROMOTED_ENTRY(27, sub_8247FB68, 0x8247FB68) { ctx.r3.u64 = CECParticleEmitter_DestroyParticleList(ctx, base, ctx.r3.u64); }

uint64_t CECParticleEmitter_Destroy(CpuState& ctx, uint8_t* base, uint64_t particleEmitterAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820B4E5C_B_ = int32_t(0x820B4E5C);
	if (!UseLiftedCode(27, 0x8247FB80)) { ctx.r3.u64 = particleEmitterAddr; __imp__sub_8247FB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8247FB80);
	uint32_t stack = ctx.r1.u64;
	CECParticleEmitter* particleEmitter = GameObject<CECParticleEmitter>(base, particleEmitterAddr);
	stack = PushStackFrame(base, stack, 224);
	ctx.r1.u64 = stack;

	uint64_t result = CECParticleEmitter_AttachToEntity(ctx, base, particleEmitterAddr);
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;

	uint64_t handleAddr = particleEmitterAddr + 16;
	if (LOAD32(handleAddr) != 0) {
		uint32_t entity = particleEmitter->m_entity;
		uint32_t value = 0;
		bool hasValue = false;

		if ((LOAD32(entity + 52) >> 7) & 1) {
			uint32_t map = LOAD32(entity + 140);
			if (map != 0) {
				uint32_t index = LOAD8(map + 135);
				uint32_t array = LOAD32(entity + 72);
				value = LOAD32(array + (index << 3) + 4);
				hasValue = true;
			} else {
				uint32_t begin = LOAD32(entity + 72);
				uint32_t end = LOAD32(entity + 76);
				reg6 = end;
				STORE32(stack + 88, 0);
				STORE32(stack + 92, begin);
				int32_t count = (int32_t)(end - begin) >> 3;
				uint32_t pos = begin;
				if (count > 0) {
					do {
						int32_t half = count >> 1;
						uint32_t offset = (uint32_t)half << 3;
						pos += offset;
						bool below = (int32_t)LOAD32(pos) < 135;
						reg7 = below ? 1 : 0;
						reg8 = offset;
						if (below) {
							count = count - half;
							pos += 8;
							count -= 1;
						} else {
							pos -= offset;
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 92, pos);
				}
				if (pos != end && (int32_t)LOAD32(pos) <= 135) {
					value = LOAD32(pos + 4);
					hasValue = true;
				} else {
					value = LOAD32(end + 4);
					hasValue = true;
				}
			}
		}

		if (hasValue) {
			uint64_t emptyStringAddr = g_82000C98;
			uint64_t eventNameAddr = str_TXT_820B4E5C_B_;
			ctx.r6.u64 = reg6;
			CCharString_ConstructFromCStr(ctx, base, stack + 88, emptyStringAddr, -1);
			CCharString_ConstructFromCStr(ctx, base, stack + 80, eventNameAddr, -1);
			RefCountedString_Assign(ctx, base, stack + 80, particleEmitterAddr + 24);
			EventArgument_ConstructFromString(ctx, base, stack + 112, stack + 80);
			EventManager_RaiseEvent(ctx, base, stack + 96, (uint32_t)value, stack + 112, stack + 88);
			OwnedPtr_Reset(ctx, base, stack + 96);
			CCharString_ReleaseMember(ctx, base, stack + 112);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
		}

		uint32_t handleObject = LOAD32(handleAddr);
		STORE32(handleObject + 40, 0);
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		Vector_DeletePointerElements(ctx, base, handleObject);
		result = SharedHandle_Release(ctx, base, handleAddr);
		STORE32(handleAddr, 0);
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_8247FB80, 0x8247FB80) { ctx.r3.u64 = CECParticleEmitter_Destroy(ctx, base, ctx.r3.u64); }

uint64_t CECParticleEmitter_AttachToEntity(CpuState& ctx, uint8_t* base, uint64_t particleEmitterAddr) {
	constexpr uint32_t kEntitySlotKey = 22;
	constexpr uint32_t kInvalidHandlePtr = 0x820F1664;
	if (!UseLiftedCode(27, 0x8247FD58)) { ctx.r3.u64 = particleEmitterAddr; __imp__sub_8247FD58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8247FD58);
	uint32_t stack = ctx.r1.u64;
	CECParticleEmitter* particleEmitter = GameObject<CECParticleEmitter>(base, particleEmitterAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t handleAddr = (uint32_t)particleEmitterAddr + 28;
	uint32_t tempHandleAddr = stack + 80;

	uint32_t handleOwner = particleEmitter->m_20;
	bool hasEntity = false;
	if (handleOwner != 0) {
		if (LOAD32(handleOwner) == 0) {
			ctx.r1.u64 = stack;
			EntityHandle_Release(ctx, base, handleAddr);
		} else {
			ctx.r1.u64 = stack;
			uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			hasEntity = (LOAD8(entity + 0x90) & 0x40) != 0;
		}
	}

	if (hasEntity) {
		ctx.r1.u64 = stack;
		uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		uint32_t attachedEntity = 0;
		bool hasAttachedEntity = false;

		if ((LOAD32(entity + 0x24) >> 22) & 1) {
			uint32_t slotIndex = LOAD32(entity + 0x8C);
			if (slotIndex != 0) {
				uint32_t index = LOAD8(slotIndex + 0x16);
				uint32_t elementAddr = (index << 3) + LOAD32(entity + 0x48);
				attachedEntity = LOAD32(elementAddr + 4);
				hasAttachedEntity = true;
			} else {
				// lower_bound for key 22 in the sorted {key, value} table at +0x48
				uint32_t begin = LOAD32(entity + 0x48);
				uint32_t end = LOAD32(entity + 0x4C);
				STORE32(tempHandleAddr, 0);
				STORE32(tempHandleAddr + 4, begin);
				uint32_t pos = begin;
				int32_t count = (int32_t)(end - begin) >> 3;
				while (count > 0) {
					int32_t half = count >> 1;
					uint32_t halfBytes = (uint32_t)half << 3;
					pos += halfBytes;
					if ((int32_t)LOAD32(pos) < (int32_t)kEntitySlotKey) {
						count = count - half - 1;
						pos += 8;
					} else {
						pos -= halfBytes;
						count = half;
					}
				}
				STORE32(tempHandleAddr + 4, pos);
				if (pos == end || (int32_t)LOAD32(pos) > (int32_t)kEntitySlotKey) {
					attachedEntity = LOAD32(end + 4);
				} else {
					attachedEntity = LOAD32(pos + 4);
				}
				hasAttachedEntity = true;
			}
		}

		if (hasAttachedEntity) {
			uint32_t targetEntity = particleEmitter->m_entity;
			ctx.r1.u64 = stack;
			ParticleEmitter_AttachToEntityInternal(ctx, base, attachedEntity, targetEntity, 1);
		}

		STORE32(tempHandleAddr + 4, 0);
		STORE32(tempHandleAddr, kInvalidHandlePtr);
		ctx.r1.u64 = stack;
		EntityHandle_Release(ctx, base, tempHandleAddr);
		EntityHandle_Assign(ctx, base, handleAddr, tempHandleAddr);
		STORE32(tempHandleAddr, kInvalidHandlePtr);
		EntityHandle_Release(ctx, base, tempHandleAddr);
	}

	ctx.r1.u64 = stack;
	uint64_t result = CharStringRange_Clear(ctx, base, (uint32_t)particleEmitterAddr + 44);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(27, sub_8247FD58, 0x8247FD58) { ctx.r3.u64 = CECParticleEmitter_AttachToEntity(ctx, base, ctx.r3.u64); }
