// CECMentalist (vtable 0x820DE1A8): methods of the class as readable C++.
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

uint64_t CECMentalist_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C953C_B_ = int32_t(0x820C953C);
	if (!UseLiftedCode(59, 0x828606C8)) { ctx.r3.u64 = classNameString; __imp__sub_828606C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828606C8);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820C953C_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(59, sub_828606C8, 0x828606C8) { ctx.r3.u64 = CECMentalist_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82860708(CpuState& ctx, uint8_t* base, uint64_t mentalistAddr, uint64_t arg2) {
    constexpr int32_t g_820F1664 = int32_t(0x820F1664);
    if (!UseLiftedCode(59, 0x82860708)) { ctx.r3.u64 = mentalistAddr; ctx.r4.u64 = arg2; __imp__sub_82860708(ctx, base); return ctx.r3.u64; }
    LiftedFrame frame(0x82860708);
    CECMentalist* mentalist = GameObject<CECMentalist>(base, mentalistAddr);
    uint32_t stack = ctx.r1.u64;
    stack = PushStackFrame(base, stack, 112);
    uint32_t deleteFlag = (uint32_t)arg2;
    uint64_t subObjectAt52 = mentalistAddr + 52;
    ctx.r1.u64 = stack;
    ctx.r4.u64 = arg2;
    C_820EFB9C_Destructor(ctx, base, subObjectAt52);
    uint64_t charStringAt24 = mentalistAddr + 24;
    CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringAt24);
    uint64_t handleAt16 = mentalistAddr + 16;
    uint32_t field10Value = uint32_t(g_820F1664);
    mentalist->m_10 = field10Value;
    ctx.r10.u64 = field10Value;
    EntityHandle_Release(ctx, base, handleAt16);
    mentalist->m_14 = 0;
    uint32_t vtableSlotAddress = 0;
    if ((uint32_t)mentalistAddr != 0) {
        vtableSlotAddress = (uint32_t)mentalistAddr + 12;
    }
    STORE32(vtableSlotAddress, 0x820A8F74u);
    mentalist->vtable = 0x820A8D10u;
    uint64_t result = mentalistAddr;
    if ((deleteFlag & 1) != 0) {
        HandleTarget_Free(ctx, base, result);
        result = mentalistAddr;
    }
    stack = PopStackFrame(stack, 112);
    ctx.r1.u64 = stack;
    return result;
}
PROMOTED_ENTRY(59, sub_82860708, 0x82860708) { ctx.r3.u64 = n_sub_82860708(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828607A8(CpuState& ctx, uint8_t* base, uint64_t mentalistAddr, uint64_t arg2) {
	constexpr int32_t str_TXT_820DE114_B_ = int32_t(0x820DE114);
	constexpr int32_t str_TXT_820DE120_B_ = int32_t(0x820DE120);
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	if (!UseLiftedCode(59, 0x828607A8)) { ctx.r3.u64 = mentalistAddr; ctx.r4.u64 = arg2; __imp__sub_828607A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828607A8);
	uint32_t stack = ctx.r1.u64;
	uint64_t finalR7 = ctx.r7.u64;
	uint64_t finalR8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;
	CECMentalist* mentalist = GameObject<CECMentalist>(base, mentalistAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t resultValue = 0;
	uint32_t hasResult = 0;

	if ((uint32_t)arg2 != 0) {
		uint64_t entity = arg2;
		uint64_t TXT_820DE114_L_ = str_TXT_820DE114_B_;
		ctx.r1.u64 = stack;
		uint32_t property = Region_GetProperty(ctx, base, entity, TXT_820DE114_L_);
		uint32_t idRefAddr = stack + 80;
		IdRef_ConstructFromId(ctx, base, idRefAddr, property);
		STORE64((uint32_t)mentalistAddr + 28, LOAD64(stack + 80));

		uint64_t TXT_820DE120_L_ = str_TXT_820DE120_B_;
		property = Region_GetProperty(ctx, base, entity, TXT_820DE120_L_);
		IdRef_ConstructFromId(ctx, base, idRefAddr, property);
		uint64_t idRefValue = LOAD64(stack + 80);

		int32_t gValue = g_820E0000;
		uint64_t fuseDummyAddr = (int64_t)gValue - 7888;
		STORE64((uint32_t)mentalistAddr + 36, idRefValue);
		ctx.r7.u64 = idRefValue;
		ctx.r8.s64 = gValue;
		uint64_t charString = n_sub_82345978(ctx, base, entity, fuseDummyAddr);
		CCharString_AssignFromCStr(ctx, base, (int64_t)mentalistAddr + 24, charString);

		arg2 = ctx.r4.u64;
		finalR7 = ctx.r7.u64;
		finalR8 = ctx.r8.u64;
		flags.ca = ctx.xer.ca;
	}

	uint32_t componentAddr = mentalist->m_4;
	resultValue = 0;
	if (LOAD32(componentAddr + 36) & 0x80000000) {
		uint32_t indexPtr = LOAD32(componentAddr + 140);
		if (indexPtr != 0) {
			uint8_t index = LOAD8(indexPtr + 31);
			uint32_t begin = LOAD32(componentAddr + 72);
			uint32_t offset = __builtin_rotateleft32((uint32_t)index, 3);
			resultValue = LOAD32(begin + offset + 4);
			hasResult = 1;
		} else {
			uint32_t searchBegin = LOAD32(componentAddr + 72);
			uint32_t searchEnd = LOAD32(componentAddr + 76);
			STORE32(stack + 80, (uint32_t)resultValue);
			uint32_t diff = (uint32_t)((uint64_t)searchEnd - searchBegin);
			STORE32(stack + 84, searchBegin);
			flags.ca = ((int32_t)diff < 0) & ((diff & 0x7) != 0);
			uint32_t count = (uint32_t)((int32_t)diff >> 3);
			if ((int32_t)count > 0) {
				do {
					flags.ca = ((int32_t)count < 0) & ((count & 0x1) != 0);
					uint32_t mid = (uint32_t)((int32_t)count >> 1);
					uint64_t searchOffset = (uint64_t)((int32_t)mid << 3);
					finalR8 = searchOffset;
					searchBegin = (uint32_t)(searchOffset + searchBegin);
					bool lt = (int32_t)LOAD32(searchBegin) < 31;
					finalR7 = 1;
					if (!lt) finalR7 = resultValue;
					finalR7 &= 0xFF;
					if ((uint32_t)finalR7 != 0) {
						count = count - mid;
						searchBegin = (uint32_t)((int32_t)searchBegin + 8);
						count = (uint32_t)((int32_t)count - 1);
					} else {
						searchBegin = (uint32_t)(searchBegin - searchOffset);
						count = mid;
					}
				} while ((int32_t)count > 0);
				STORE32(stack + 84, searchBegin);
			}
			if (searchBegin == searchEnd || (int32_t)LOAD32(searchBegin) > 31) {
				resultValue = LOAD32(searchEnd + 4);
			} else {
				STORE64(stack + 80, LOAD64(stack + 80));
				resultValue = LOAD32(LOAD32(stack + 84) + 4);
			}
			hasResult = 1;
		}
	}

	hasResult = hasResult & 0xFF;
	if (hasResult != 0) {
		uint32_t size = 20;
		uint64_t addr1 = (int64_t)mentalistAddr + 52;
		uint64_t addr2 = (int64_t)mentalistAddr + 12;
		ctx.r1.u64 = stack;
		ctx.r7.u64 = finalR7;
		ctx.r8.u64 = finalR8;
		ctx.xer.ca = flags.ca;
		resultValue = n_sub_82483858(ctx, base, resultValue, addr1, addr2, size);
		arg2 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return resultValue;
}
PROMOTED_ENTRY(59, sub_828607A8, 0x828607A8) { ctx.r3.u64 = n_sub_828607A8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82860970(CpuState& ctx, uint8_t* base, uint64_t mentalistAddr, uint64_t serialiser, uint64_t flags) {
	constexpr int32_t str_TXT_820DE13C_B_ = int32_t(0x820DE13C);
	constexpr int32_t str_TXT_820DE148_B_ = int32_t(0x820DE148);
	constexpr int32_t strTable = int32_t(0x820E0000);
	constexpr int32_t str_TXT_820DE150_B_ = strTable - 7856;
	if (!UseLiftedCode(59, 0x82860970)) { ctx.r3.u64 = mentalistAddr; ctx.r4.u64 = serialiser; ctx.r6.u64 = flags; __imp__sub_82860970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82860970);
	uint32_t stack = ctx.r1.u64;
	CECMentalist* mentalist = GameObject<CECMentalist>(base, mentalistAddr);

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = flags;


	CCharString_ConstructFromCStr(ctx, base, stack + 84, str_TXT_820DE13C_B_, -1);
	n_sub_827D63A8(ctx, base, mentalistAddr + 44, serialiser, stack + 84);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);

	uint32_t TXT_820DE148_L_ = n_sub_82860D90(ctx, base, mentalistAddr);  // Lua_Mentalist_IsLit
	uint32_t isSploded = mentalist->m_30;
	STORE8(stack + 80, (uint8_t)TXT_820DE148_L_);
	STORE8(stack + 81, (uint8_t)isSploded);


	CCharString_ConstructFromCStr(ctx, base, stack + 84, str_TXT_820DE148_B_, -1);
	IStream_SerializeString(ctx, base, stack + 84, serialiser, stack + 80);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);


	ctx.r8.s64 = strTable;
	CCharString_ConstructFromCStr(ctx, base, stack + 84, str_TXT_820DE150_B_, -1);
	IStream_SerializeString(ctx, base, stack + 84, serialiser, stack + 81);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);

	uint64_t flagsLow = flags & 0xFF;
	if ((uint32_t)flagsLow == 0) {
		if (LOAD8(stack + 80) != 0) {
			ctx.r7.u64 = flagsLow;
			result = Mentalist_LightFuseImpl(ctx, base, mentalistAddr);
			flagsLow = ctx.r7.u64;
		}
		uint32_t splodedFlag = LOAD8(stack + 81);
		if (splodedFlag != 0) {
			ctx.r7.u64 = flagsLow;
			ctx.r10.u64 = splodedFlag;
			result = Mentalist_Explode(ctx, base, mentalistAddr);
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(59, sub_82860970, 0x82860970) { ctx.r3.u64 = n_sub_82860970(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

uint64_t Mentalist_LightFuseImpl(CpuState& ctx, uint8_t* base, uint64_t mentalistAddr) {
	constexpr int32_t str_TXT_820DE158_B_ = int32_t(0x820DE158);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(59, 0x82860A60)) { ctx.r3.u64 = mentalistAddr; __imp__sub_82860A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82860A60);
	uint32_t stack = ctx.r1.u64;
	CECMentalist* mentalist = GameObject<CECMentalist>(base, mentalistAddr);
	const uint32_t mentalistBase = (uint32_t)mentalistAddr;
	const uint32_t fuseHandleAddr = mentalistBase + 16;
	const uint32_t zero = 0;
	PPCVRegister savedV1 = ctx.v1;

	stack = PushStackFrame(base, stack, 224);
	ctx.r1.u64 = stack;

	uint64_t result = n_sub_82860D90(ctx, base, mentalistAddr);  // Lua_Mentalist_IsLit

	if ((uint32_t)(result & 0xFF) == 0) {
		if (LOAD32(mentalistBase + 28) != 0) {
			uint32_t stringAddr = stack + 96;
			CCharString_ConstructFromCStr(ctx, base, stringAddr, str_TXT_820DE158_B_, -1);

			uint32_t v4 = (uint32_t)mentalist->m_4;
			uint32_t nameBuf = stack + 112;
			uint32_t local27 = LOAD32(v4 + 124);
			uint32_t local48 = LOAD32(local27);
			uint32_t callTarget = LOAD32(local48 + 64);
			ctx.r3.u64 = nameBuf;
			ctx.r4.u64 = local27;
			ctx.r8.u64 = callTarget;
			ctx.r9.u64 = local48;
			ctx.r10.u64 = v4;
			REX_CALL_INDIRECT_FUNC(callTarget);

			uint32_t entityType = LOAD32(mentalistBase + 28);
			uint32_t handleOut = stack + 104;
			uint32_t namePtr = stack + 96;
			STORE32(stack + 108, zero);

			uint32_t local57 = LOAD32(0x83496920u);
			local57 = LOAD32(local57 + 12);
			uint32_t local44 = LOAD32(LOAD32(LOAD32(local57 + 88) + 4));
			uint32_t local58 = LOAD32(local44 + 4);
			uint64_t nextId = (uint64_t)local58 + 1;
			STORE32(local44 + 4, (uint32_t)nextId);
			STORE32(stack + 104, local58);

			SET_V8(savedV1, VLOAD((stack + 112) & ~0xF));
			ctx.r8.u64 = local44;
			ctx.r10.u64 = nextId;
			ctx.v1 = savedV1;
			uint64_t named = Entity_CreateNamed(ctx, base, entityType, handleOut, namePtr, 1, 0);

			uint64_t defaultHandle64 = (int64_t)g_820F0000 + 5732;
			uint32_t defaultHandle = (uint32_t)defaultHandle64;
			STORE32(stack + 108, zero);
			STORE32(stack + 104, defaultHandle);
			ctx.r8.u64 = defaultHandle64;
			ctx.r9.s64 = g_820F0000;
			EntityHandle_SetTarget(ctx, base, handleOut, named);

			EntityHandle_Assign(ctx, base, fuseHandleAddr, handleOut);

			STORE32(stack + 104, defaultHandle);
			ctx.r6.u64 = defaultHandle64;
			ctx.r7.s64 = g_820F0000;
			EntityHandle_Release(ctx, base, handleOut);

			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stringAddr);

			uint32_t handleObj = (uint32_t)mentalist->m_14;
			bool fuseIsLit = false;
			if (handleObj != 0) {
				uint32_t handleId = LOAD32(handleObj);
				if (handleId == 0) {
					ctx.r10.u64 = handleId;
					result = EntityHandle_Release(ctx, base, fuseHandleAddr);
				} else {
					ctx.r10.u64 = handleId;
					result = EntityHandle_Get_825575C8(ctx, base, fuseHandleAddr);
					if ((LOAD8((uint32_t)result + 144) & 64) != 0) {
						fuseIsLit = true;
					}
				}
			}

			if (fuseIsLit) {
				ctx.r10.u64 = 64;
				uint32_t fuseEntity = EntityHandle_Get_825575C8(ctx, base, fuseHandleAddr);
				uint64_t reg6 = ctx.r6.u64;
				uint64_t reg7 = ctx.r7.u64;
				uint64_t reg8 = ctx.r8.u64;
				uint64_t reg9 = ctx.r9.u64;
				bool hasEmitter = false;
				uint32_t emitterIndex = 0;

				if (((LOAD32(fuseEntity + 44) >> 21) & 1) != 0) {
					uint32_t altTable = LOAD32(fuseEntity + 140);
					if (altTable != 0) {
						uint32_t idx = LOAD8(altTable + 85);
						uint64_t entry = (uint64_t)(idx << 3) + LOAD32(fuseEntity + 72);
						emitterIndex = LOAD32((uint32_t)entry + 4);
						reg9 = entry;
						hasEmitter = true;
					} else {
						uint32_t start = LOAD32(fuseEntity + 72);
						uint32_t end = LOAD32(fuseEntity + 76);
						STORE32(stack + 104, zero);
						int32_t count = (int32_t)(end - start) >> 3;
						STORE32(stack + 108, start);
						uint32_t ptr = start;
						reg6 = end;
						if (count > 0) {
							int32_t n = count;
							do {
								int32_t half = n >> 1;
								uint32_t offset = (uint32_t)half << 3;
								uint32_t mid = ptr + offset;
								reg9 = (uint64_t)half;
								reg8 = (uint64_t)offset;
								bool less = (int32_t)LOAD32(mid) < 85;
								reg7 = less ? 1 : 0;
								if (less) {
									n = n - half - 1;
									ptr = mid + 8;
								} else {
									n = half;
								}
							} while (n > 0);
							STORE32(stack + 108, ptr);
						}
						if (ptr != end) {
							if ((int32_t)LOAD32(ptr) > 85) {
								emitterIndex = LOAD32(end + 4);
							} else {
								STORE64(stack + 104, LOAD64(stack + 104));
								emitterIndex = LOAD32(ptr + 4);
							}
							hasEmitter = true;
						} else {
							emitterIndex = LOAD32(end + 4);
							hasEmitter = true;
						}
					}
				}

				if (hasEmitter) {
					ctx.r6.u64 = reg6;
					ctx.r7.u64 = reg7;
					ctx.r8.u64 = reg8;
					Matrix_ConstructIdentity(ctx, base, stack + 128);
					uint32_t v42 = (uint32_t)mentalist->m_4;
					STORE8(stack + 87, (uint8_t)zero);
					ctx.fpscr.disableFlushMode();
					double attachParam = double(LOAD_F32(0x820994B4u));
					uint32_t field24 = mentalistBase + 24;
					ParticleEmitter_AttachToEntityImpl(ctx, base, emitterIndex, v42, field24, 0, 1, 1, 1, stack + 128, attachParam);
					reg6 = ctx.r6.u64;
					reg7 = ctx.r7.u64;
					reg8 = ctx.r8.u64;
					reg9 = ctx.r9.u64;
				}

				uint32_t v43 = (uint32_t)mentalist->m_4;
				ctx.r6.u64 = reg6;
				ctx.r7.u64 = reg7;
				ctx.r8.u64 = reg8;
				ctx.r9.u64 = reg9;
				result = n_sub_82392C88(ctx, base, v43, mentalistBase);
			}
		}
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(59, sub_82860A60, 0x82860A60) { ctx.r3.u64 = Mentalist_LightFuseImpl(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82860D90(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(59, 0x82860D90)) { ctx.r3.u64 = arg1; __imp__sub_82860D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82860D90);
	uint32_t stack = ctx.r1.u64;
	uint32_t local1 = ctx.r10.u32;
	uint32_t TXT_820DE148_L_ = 0;
	stack = PushStackFrame(base, stack, 96);

	// handle wrapper embedded in the mentalist object at +16
	arg1 = (int64_t)arg1 + 16;
	const uint32_t handleSlot = LOAD32((uint32_t)arg1 + 4);

	if (handleSlot != 0) {
		local1 = LOAD32(handleSlot);
		if (local1 == 0) {
			// empty handle: release the wrapper, result stays false
			ctx.r1.u64 = stack;
			ctx.r10.u64 = local1;
			EntityHandle_Release(ctx, base, arg1);
			local1 = ctx.r10.u32;
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			ctx.r10.u64 = local1;
			return 0;
		}

		ctx.r1.u64 = stack;
		ctx.r10.u64 = local1;
		const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, arg1);
		local1 = LOAD8(entity + 144) & 64;
		if (local1 != 0) {
			TXT_820DE148_L_ = 1;
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			ctx.r10.u64 = local1;
			return TXT_820DE148_L_;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r10.u64 = local1;
	return 0;
}
PROMOTED_ENTRY(59, sub_82860D90, 0x82860D90) { ctx.r3.u64 = n_sub_82860D90(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82860E00(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(59, 0x82860E00)) { ctx.r3.u64 = arg1; __imp__sub_82860E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82860E00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint64_t result = n_sub_82860D90(ctx, base, arg1);  // Lua_Mentalist_IsLit
	if ((static_cast<uint32_t>(result) & 0xFF) != 0) {
		uint64_t fuseAddress = arg1 + 44;
		result = Dog_CalculateExpressionStep(ctx, base, fuseAddress);
		if (static_cast<int32_t>(result) == 0) {
			result = n_sub_82860F38(ctx, base, arg1);  // Lua_Mentalist_GoBoom
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(59, sub_82860E00, 0x82860E00) { ctx.r3.u64 = n_sub_82860E00(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82860E50(CpuState& ctx, uint8_t* base, uint64_t mentalistAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(59, 0x82860E50)) { ctx.r3.u64 = mentalistAddr; __imp__sub_82860E50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82860E50);
	uint32_t stack = ctx.r1.u64;
	CECMentalist* mentalist = GameObject<CECMentalist>(base, mentalistAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	uint32_t fuseHandle = (uint32_t)mentalistAddr + 16;
	uint32_t fuseLink = mentalist->m_14;
	if (fuseLink != 0) {
		uint32_t handleValue = LOAD32(fuseLink);
		if (handleValue == 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = handleValue;
			EntityHandle_Release(ctx, base, fuseHandle);
		} else {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = handleValue;
			uint32_t testEntity = EntityHandle_Get_825575C8(ctx, base, fuseHandle);
			uint32_t mask = LOAD8(testEntity + 144) & 0x40;
			if (mask != 0) {
				ctx.r1.u64 = stack;
				ctx.r10.u64 = mask;
				uint32_t fuseEntity = EntityHandle_Get_825575C8(ctx, base, fuseHandle);
				Entity_DestroyImpl(ctx, base, fuseEntity);
			}
		}
	}

	// Replace the mentalist's fuse handle with an empty one, releasing both temporaries.
	uint32_t zero = 0;
	uint64_t emptyValue = (uint64_t)(int64_t)g_820F1664;
	STORE32(stack + 84, zero);
	STORE32(stack + 80, (uint32_t)emptyValue);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = emptyValue;
	ctx.r10.u64 = zero;
	EntityHandle_Release(ctx, base, stack + 80);

	EntityHandle_Assign(ctx, base, fuseHandle, stack + 80);

	uint64_t magicValue = (uint64_t)((int64_t)g_820F0000 + 5732);
	STORE32(stack + 80, (uint32_t)magicValue);
	ctx.r7.u64 = magicValue;
	ctx.r8.s64 = g_820F0000;
	EntityHandle_Release(ctx, base, stack + 80);

	uint64_t removeResult = Vector_RemoveByValue(ctx, base, mentalist->m_4, mentalistAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return removeResult;
}
PROMOTED_ENTRY(59, sub_82860E50, 0x82860E50) { ctx.r3.u64 = n_sub_82860E50(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82860F38(CpuState& ctx, uint8_t* base, uint64_t mentalistAddr) {
	constexpr int32_t str_TXT_820DE160_B_ = int32_t(0x820DE160);
	if (!UseLiftedCode(59, 0x82860F38)) { ctx.r3.u64 = mentalistAddr; __imp__sub_82860F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82860F38);
	uint32_t stack = ctx.r1.u64;
	CECMentalist* mentalist = GameObject<CECMentalist>(base, mentalistAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	uint32_t TXT_820DE148_L_ = n_sub_82860D90(ctx, base, mentalistAddr);
	uint32_t valueForExplode = ctx.r10.u32;
	PPCVRegister savedV1 = ctx.v1;

	if ((TXT_820DE148_L_ & 0xFF) != 0) {
		if (LOAD32((uint32_t)mentalistAddr + 36) != 0) {
			uint64_t TXT_820DE160_L_ = str_TXT_820DE160_B_;
			CCharString_ConstructFromCStr(ctx, base, (uint64_t)stack + 80, TXT_820DE160_L_, -1);

			uint32_t mentalistPart = mentalist->m_4;
			uint32_t manager = LOAD32(mentalistPart + 124);
			uint32_t vtable = LOAD32(manager);
			uint32_t virtualAddress = LOAD32(vtable + 64);
			PPCRegister callTarget{};
			callTarget.u64 = virtualAddress;
			ctx.r3.u64 = (uint64_t)stack + 96;
			ctx.r4.u64 = manager;
			ctx.r8.u64 = virtualAddress;
			ctx.r9.u64 = vtable;
			ctx.r10.u64 = mentalistPart;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint32_t owner = LOAD32((uint32_t)mentalistAddr + 36);
			uint32_t targetEntity = 0;
			uint32_t unusedZero = 0;
			STORE32(stack + 92, targetEntity);
			uint32_t one = 1;

			uint32_t global = LOAD32(0x83496920u);
			global = LOAD32(global + 12);
			uint32_t idManager = LOAD32(LOAD32(LOAD32(global + 88) + 4));
			uint32_t oldId = LOAD32(idManager + 4);
			uint32_t newId = oldId + 1;
			STORE32(idManager + 4, newId);
			STORE32(stack + 88, oldId);

			SET_V8(savedV1, VLOAD((uint32_t)((uint64_t)stack + 96) & ~0xF));
			ctx.r8.u64 = idManager;
			ctx.r10.u64 = newId;
			ctx.v1 = savedV1;
			uint32_t namedEntity = Entity_CreateNamed(ctx, base, owner, (uint64_t)stack + 88, (uint64_t)stack + 80, one, unusedZero);

			CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint64_t)stack + 80);
			uint64_t local26 = ctx.r6.u64;
			uint64_t local28 = ctx.r7.u64;
			uint64_t local31 = ctx.r8.u64;
			valueForExplode = ctx.r10.u32;

			if (namedEntity != 0) {
				valueForExplode = LOAD8(namedEntity + 144) & 64;
				if (valueForExplode != 0) {
					uint64_t local36 = (LOAD32(namedEntity + 52) >> 23) & 1;
					if (local36 != 0) {
						uint32_t componentArray = LOAD32(namedEntity + 140);
						if (componentArray != 0) {
							local36 = __builtin_rotateleft32((uint32_t)LOAD8(componentArray + 151), 3);
							targetEntity = LOAD32((uint32_t)(local36 + LOAD32(namedEntity + 72)) + 4);
						} else {
							local36 = LOAD32(namedEntity + 72);
							local26 = LOAD32(namedEntity + 76);
							STORE32(stack + 80, targetEntity);
							uint32_t diff = (uint32_t)local26 - (uint32_t)local36;
							STORE32(stack + 84, (uint32_t)local36);
							int32_t local41 = (int32_t)diff >> 3;
							if (local41 > 0) {
								do {
									int32_t local33 = local41 >> 1;
									local31 = (uint32_t)local33 << 3;
									local36 = local31 + local36;
									int32_t key = (int32_t)LOAD32((uint32_t)local36);
									local28 = (key < 151) ? 1u : 0u;
									if (local28 != 0) {
										local41 = local41 - local33;
										local36 = local36 + 8;
										local41 = local41 - 1;
									} else {
										local36 = local36 - local31;
										local41 = local33;
									}
								} while (local41 > 0);
								STORE32(stack + 84, (uint32_t)local36);
							}

							uint32_t found;
							if ((uint32_t)local36 != (uint32_t)local26) {
								int32_t key = (int32_t)LOAD32((uint32_t)local36);
								if (key > 151) {
									found = (uint32_t)local26;
								} else {
									STORE64(stack + 88, LOAD64(stack + 80));
									found = LOAD32(stack + 92);
								}
							} else {
								found = (uint32_t)local26;
							}
							targetEntity = LOAD32(found + 4);
						}
					}

					ctx.r6.u64 = local26;
					ctx.r7.u64 = local28;
					ctx.r8.u64 = local31;
					ctx.r10.u64 = local36;
					Mentalist_SetTarget(ctx, base, targetEntity, mentalist->m_4);
					EntityHandleList_AddUnique(ctx, base, targetEntity, mentalist->m_4);
					valueForExplode = ctx.r10.u32;
				}
			}
		}

		ctx.r10.u64 = valueForExplode;
		Mentalist_Explode(ctx, base, mentalistAddr);
	}

	uint32_t returnValue = mentalist->m_30;
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return returnValue;
}
PROMOTED_ENTRY(59, sub_82860F38, 0x82860F38) { ctx.r3.u64 = n_sub_82860F38(ctx, base, ctx.r3.u64); }

uint64_t Mentalist_Explode(CpuState& ctx, uint8_t* base, uint64_t mentalistAddr) {
	constexpr int32_t str_TXT_820DE16C_B_ = int32_t(0x820DE16C);
	if (!UseLiftedCode(59, 0x82861128)) { ctx.r3.u64 = mentalistAddr; __imp__sub_82861128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82861128);
	uint32_t stack = ctx.r1.u64;
	uint64_t local23{};
	uint64_t local24{};
	uint64_t idRef2{};
	uint64_t local25{};
	uint32_t local26{};
	uint32_t local27{};
	uint64_t local18{};
	uint32_t local28{};
	uint64_t local29{};
	uint32_t local30{};
	uint64_t local19{};
	uint64_t local20{};
	uint64_t idRef{};
	uint64_t property{};
	uint64_t local21{};
	uint32_t local22{};
	uint64_t local34{};
	uint64_t local35{};
	uint32_t local36{};
	uint64_t local37{};
	uint32_t v4{};
	uint32_t local31{};
	uint64_t local32{};
	uint64_t local33{};
	uint64_t local38{};
	uint64_t local39{};
	uint64_t local40{};
	uint64_t TXT_820DE16C_L_{};
	uint64_t local41{};
	uint32_t local43{};
	uint32_t local44{};
	uint32_t local45{};
	uint32_t local46{};
	uint32_t local42{};
	uint32_t local49{};
	uint32_t local50{};
	uint32_t local51{};
	uint32_t local52{};
	uint32_t local53{};
	uint32_t local47{};
	uint32_t local48{};
	uint32_t local58{};
	uint32_t local59{};
	uint32_t local60{};
	uint32_t local61{};
	uint32_t local62{};
	uint32_t local63{};
	uint32_t local64{};
	uint32_t local54{};
	uint32_t local65{};
	uint32_t local66{};
	uint32_t local67{};
	uint32_t local68{};
	uint32_t local55{};
	uint32_t local56{};
	uint32_t local57{};
	uint64_t local69{};
	uint32_t local70{};
	uint32_t local71{};
	uint32_t local72{};
	uint32_t local73{};
	uint32_t local74{};
	uint64_t local75{};
	uint32_t local76{};
	uint64_t local77{};
	PPCRegister callTarget{};
	CECMentalist* mentalist = GameObject<CECMentalist>(base, mentalistAddr);
	stack = PushStackFrame(base, stack, 176);
	ctx.r1.u64 = stack;
	local18 = n_sub_82860E50(ctx, base, mentalistAddr);  // Lua_Mentalist_ExtinguishFuse
	local39 = ctx.r6.u64;
	local40 = ctx.r7.u64;
	local41 = ctx.r8.u64;
	local54 = mentalist->m_4;
	local71 = 0;
	local70 = 1;
	local73 = (uint64_t)local71;
	if (uint32_t((LOAD32(local54 + 36) >> 17) & 1) != 0) {
		local47 = LOAD32(local54 + 140);
		if (local47 != 0) {
			local47 = LOAD8(local47 + 17);
			local54 = LOAD32(local54 + 72);
			local47 = __builtin_rotateleft32(local47, 3);
			local73 = (uint64_t)LOAD32(uint32_t(local47 + local54) + 4);
			local55 = (uint64_t)local70;
			goto loc_82861250;
		}
		local48 = LOAD32(local54 + 72);
		local39 = LOAD32(local54 + 76);
		STORE32(stack + 80, local71);
		local56 = local39 - local48;
		STORE32(stack + 84, local48);
		local56 = (int32_t)local56 >> 3;
		if ((int32_t)local56 > 0) {
			do {
				local42 = (int32_t)local56 >> 1;
				local41 = local42 << 3;
				local48 = local41 + local48;
				local40 = (uint64_t)local70;
				if (!((int32_t)LOAD32(local48) < 17)) {
					local40 = (uint64_t)local71;
				}
				local40 = (uint32_t)local40 & 0xFF;
				if ((uint32_t)local40 != 0) {
					local56 = local56 - local42;
					local48 = (int32_t)local48 + 8;
					local56 = (int32_t)local56 - 1;
				} else {
					local48 = local48 - local41;
					local56 = local42;
				}
			} while ((int32_t)local56 > 0);
			STORE32(stack + 84, local48);
		}
		if (local48 != (uint32_t)local39) {
			local57 = (uint64_t)local70;
			if (!((int32_t)LOAD32(local48) > 17)) {
				local57 = (uint64_t)local71;
			}
			local57 = local57 & 0xFF;
			if (local57 != 0) goto loc_82861238;
			STORE64(stack + 88, LOAD64(stack + 80));
			local58 = LOAD32(stack + 92);
			local58 = LOAD32(local58 + 4);
			local73 = (uint64_t)local58;
			local55 = (uint64_t)local70;
			goto loc_82861250;
		}
loc_82861238:
		local59 = local39;
		local59 = LOAD32(local59 + 4);
		local73 = (uint64_t)local59;
		local55 = (uint64_t)local70;
	} else {
		local55 = (uint64_t)local71;
	}
loc_82861250:
	local55 = local55 & 0xFF;
	if (local55 != 0) {
		local31 = (uint64_t)local73;
		local19 = (uint64_t)stack + 80;
		ctx.r6.u64 = local39;
		ctx.r8.u64 = local41;
		local20 = n_sub_821D9F40(ctx, base, local19, local31);
		TXT_820DE16C_L_ = str_TXT_820DE16C_B_;
		idRef = IdRef_Get(ctx, base, local20);
		local32 = TXT_820DE16C_L_;
		ctx.r7.u64 = TXT_820DE16C_L_;
		property = Region_GetProperty(ctx, base, idRef, local32);
		local39 = ctx.r6.u64;
		local33 = property;
		local21 = (uint64_t)stack + 88;
		local18 = IdRef_ConstructFromId(ctx, base, local21, local33);
		local40 = ctx.r7.u64;
		local41 = ctx.r8.u64;
		local72 = LOAD32(stack + 88);
		if (local72 == 0) goto loc_82861438;
		local60 = mentalist->m_4;
		local74 = (uint64_t)local71;
		if (uint32_t((LOAD32(local60 + 36) >> 3) & 1) != 0) {
			local49 = LOAD32(local60 + 140);
			if (local49 != 0) {
				local49 = LOAD8(local49 + 3);
				local60 = LOAD32(local60 + 72);
				local49 = __builtin_rotateleft32(local49, 3);
				local43 = local49 + local60;
				local61 = (uint64_t)local70;
				local74 = LOAD32(local43 + 4);
				goto loc_82861394;
			}
			local50 = LOAD32(local60 + 72);
			local39 = LOAD32(local60 + 76);
			STORE32(stack + 80, local71);
			local62 = local39 - local50;
			STORE32(stack + 84, local50);
			local62 = (int32_t)local62 >> 3;
			if ((int32_t)local62 > 0) {
				do {
					local44 = (int32_t)local62 >> 1;
					local41 = local44 << 3;
					local50 = local41 + local50;
					local40 = (uint64_t)local70;
					if (!((int32_t)LOAD32(local50) < 3)) {
						local40 = (uint64_t)local71;
					}
					local40 = (uint32_t)local40 & 0xFF;
					if ((uint32_t)local40 != 0) {
						local62 = local62 - local44;
						local50 = (int32_t)local50 + 8;
						local62 = (int32_t)local62 - 1;
					} else {
						local50 = local50 - local41;
						local62 = local44;
					}
				} while ((int32_t)local62 > 0);
				STORE32(stack + 84, local50);
			}
			if (local50 != (uint32_t)local39) {
				local63 = (uint64_t)local70;
				if (!((int32_t)LOAD32(local50) > 3)) {
					local63 = (uint64_t)local71;
				}
				local63 = local63 & 0xFF;
				if (local63 != 0) goto loc_82861380;
				STORE64(stack + 80, LOAD64(stack + 80));
				local74 = LOAD32(LOAD32(stack + 84) + 4);
				local61 = (uint64_t)local70;
				goto loc_82861394;
			}
loc_82861380:
			local74 = LOAD32(uint32_t(local39) + 4);
			local61 = (uint64_t)local70;
		} else {
			local61 = (uint64_t)local71;
		}
loc_82861394:
		local61 = local61 & 0xFF;
		if (local61 == 0) goto loc_82861438;
		local76 = (int64_t)(uint64_t)local73 + 12;
		if (local73 == 0) {
			local76 = (uint64_t)local71;
		}
		local22 = (uint64_t)local74;
		ctx.r4.u64 = local33;
		ctx.r6.u64 = local39;
		ctx.r7.u64 = local40;
		ctx.r8.u64 = local41;
		CECGraphicAppearance_ForEach(ctx, base, local22);
		STORE32(stack + 80, local76);
		local77 = (int64_t)(uint64_t)local74 + 12;
		local34 = (uint64_t)stack + 80;
		local23 = local77;
		List_RemoveAllMatchingValue(ctx, base, local23, local34);
		local24 = (uint64_t)stack + 88;
		idRef2 = IdRef_Get(ctx, base, local24);
		local64 = LOAD32(local73 + 12);
		local75 = (int64_t)(uint64_t)local73 + 12;
		STORE8(local73 + 179, (uint8_t)local70);
		local69 = idRef2;
		local25 = local75;
		local51 = LOAD32(local64 + 8);
		callTarget.u64 = (uint64_t)local51;
		ctx.r3.u64 = local25;
		ctx.r10.u64 = local51;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		local26 = (uint64_t)local73;
		n_sub_8246B3C0(ctx, base, local26);
		local35 = local69;
		local27 = (uint64_t)local73;
		Character_LoadModelDefinition(ctx, base, local27, local35, ctx.r6.u64, ctx.r8.u64);
		STORE32(local73 + 180, local72);
		local36 = 1;
		local28 = (uint64_t)local73;
		n_sub_8246B618(ctx, base, local28, local36);
		STORE32(stack + 80, (uint32_t)local75);
		local45 = LOAD32(local74 + 16);
		local38 = (uint64_t)stack + 80;
		local29 = local77;
		STORE32(stack + 88, (uint32_t)local77);
		STORE32(stack + 92, local45);
		local37 = LOAD64(stack + 88);
		local18 = List_InsertNodeCopyWord(ctx, base, local29, local37, local38);
		local39 = ctx.r6.u64;
		local40 = ctx.r7.u64;
		local41 = ctx.r8.u64;
	}
loc_82861438:
	v4 = mentalist->m_4;
	local65 = (uint64_t)local71;
	if (uint32_t((LOAD32(v4 + 36) >> 20) & 1) != 0) {
		local66 = LOAD32(v4 + 140);
		local52 = LOAD32(v4 + 72);
		if (local66 != 0) {
			local66 = LOAD8(local66 + 20);
			local66 = __builtin_rotateleft32(local66, 3);
			local52 = local66 + local52;
			local65 = LOAD32(local52 + 4);
			local53 = (uint64_t)local70;
			goto loc_82861534;
		}
		local39 = LOAD32(v4 + 76);
		STORE32(stack + 80, local71);
		local67 = local39 - local52;
		STORE32(stack + 84, local52);
		local67 = (int32_t)local67 >> 3;
		if ((int32_t)local67 > 0) {
			do {
				local46 = (int32_t)local67 >> 1;
				local41 = local46 << 3;
				local52 = local41 + local52;
				local40 = (uint64_t)local70;
				if (!((int32_t)LOAD32(local52) < 20)) {
					local40 = (uint64_t)local71;
				}
				local40 = (uint32_t)local40 & 0xFF;
				if ((uint32_t)local40 != 0) {
					local67 = local67 - local46;
					local52 = (int32_t)local52 + 8;
					local67 = (int32_t)local67 - 1;
				} else {
					local52 = local52 - local41;
					local67 = local46;
				}
			} while ((int32_t)local67 > 0);
			STORE32(stack + 84, local52);
		}
		if (local52 != (uint32_t)local39) {
			local68 = (uint64_t)local70;
			if (!((int32_t)LOAD32(local52) > 20)) {
				local68 = (uint64_t)local71;
			}
			local68 = local68 & 0xFF;
			if (local68 != 0) goto loc_82861520;
			local53 = (uint64_t)local70;
			STORE64(stack + 88, LOAD64(stack + 80));
			local65 = LOAD32(stack + 92);
			local65 = LOAD32(local65 + 4);
			goto loc_82861534;
		}
loc_82861520:
		local65 = local39;
		local53 = (uint64_t)local70;
		local65 = LOAD32(local65 + 4);
	} else {
		local53 = (uint64_t)local71;
	}
loc_82861534:
	local53 = local53 & 0xFF;
	if (local53 != 0) {
		if (LOAD8(local65 + 24) != 0) {
			local30 = (uint64_t)local65;
			ctx.r6.u64 = local39;
			ctx.r7.u64 = local40;
			local18 = n_sub_82433400(ctx, base, local30, v4, local41);
		}
	}
loc_82861554:
	mentalist->m_30 = (uint8_t)local70;
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return local18;
}
PROMOTED_ENTRY(59, sub_82861128, 0x82861128) { ctx.r3.u64 = Mentalist_Explode(ctx, base, ctx.r3.u64); }
