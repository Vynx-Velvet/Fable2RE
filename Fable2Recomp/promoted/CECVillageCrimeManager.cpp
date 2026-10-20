// CECVillageCrimeManager (vtable 0x820DDFA8): methods of the class as readable C++.
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

uint64_t CECVillageCrimeManager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C906C_B_ = int32_t(0x820C906C);
	if (!UseLiftedCode(58, 0x8284BA90)) { ctx.r3.u64 = classNameString; __imp__sub_8284BA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8284BA90);
	uint32_t stack = ctx.r1.u64;
	uint64_t className{};
	int32_t length{};
	stack = PushStackFrame(base, stack, 96);
	length = -1;
	className = str_TXT_820C906C_B_;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, className, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(58, sub_8284BA90, 0x8284BA90) { ctx.r3.u64 = CECVillageCrimeManager_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECVillageCrimeManager_Constructor(CpuState& ctx, uint8_t* base, uint64_t villageCrimeManagerAddr, uint64_t arg2) {
	if (!UseLiftedCode(58, 0x8284D4E8)) { ctx.r3.u64 = villageCrimeManagerAddr; ctx.r4.u64 = arg2; __imp__sub_8284D4E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8284D4E8);
	uint32_t stack = ctx.r1.u64;
	uint32_t manager = (uint32_t)villageCrimeManagerAddr;
	CECVillageCrimeManager* villageCrimeManager = GameObject<CECVillageCrimeManager>(base, villageCrimeManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	STORE32(manager + 4, (uint32_t)arg2);
	STORE8(manager + 8, 0);
	STORE32(manager, 0x820DDFA8u);
	STORE32(manager + 12, 0);
	STORE32(manager + 16, 0);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	List_InitEmpty(ctx, base, villageCrimeManagerAddr + 20);

	uint32_t sentinel = operator_new(ctx, base, 16);
	if (sentinel != 0) {
		STORE32(sentinel, sentinel);
	}
	STORE32(sentinel + 4, sentinel);
	STORE32(manager + 0x24, sentinel);
	STORE32(manager + 0x28, 0);

	List_InitEmpty(ctx, base, villageCrimeManagerAddr + 44);
	List_InitEmpty(ctx, base, villageCrimeManagerAddr + 56);
	List_InitEmpty(ctx, base, villageCrimeManagerAddr + 68);
	List_InitEmpty(ctx, base, villageCrimeManagerAddr + 80);
	List_InitEmpty(ctx, base, villageCrimeManagerAddr + 92);
	StdMap_Init_823D2790(ctx, base, villageCrimeManagerAddr + 104);

	STORE32(manager + 0x74, 0);
	STORE32(manager + 0x78, 0);
	STORE32(manager + 0x7C, 0);
	STORE8(manager + 0x80, 0);
	ctx.fpscr.disableFlushMode();
	const double defaultFloat = double(LOAD_F32(0x820994B4u));
	STORE8(manager + 0x81, 0);
	villageCrimeManager->m_8C = float(defaultFloat);
	STORE8(manager + 0x82, 0);
	STORE8(manager + 0x83, 0);
	STORE8(manager + 0x84, 0);
	STORE32(manager + 0x88, 5u);
	STORE32(manager + 0x90, 0);
	STORE32(manager + 0x94, 0);
	STORE32(manager + 0x98, 0);
	STORE32(manager + 0x9C, 0);
	STORE32(manager + 0xA0, 0);

	STORE32(manager + 160, 0);
	STORE32(manager + 156, 0);

	uint32_t ownerId = LOAD32(manager + 4);
	CECDoor_UpdateOpenStateForEntity(ctx, base, ownerId, villageCrimeManagerAddr);
	STORE8(0x83496B77u, 0);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return villageCrimeManagerAddr;
}
PROMOTED_ENTRY(58, sub_8284D4E8, 0x8284D4E8) { ctx.r3.u64 = CECVillageCrimeManager_Constructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECVillageCrimeManager_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t villageCrimeManager, uint64_t deleteFlags) {
	if (!UseLiftedCode(58, 0x8284D608)) { ctx.r3.u64 = villageCrimeManager; ctx.r4.u64 = deleteFlags; __imp__sub_8284D608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8284D608);
	GameStackFrame stackFrame(ctx, base, 112);

	ctx.r4.u64 = deleteFlags;
	CECVillageCrimeManager_Destructor(ctx, base, villageCrimeManager);

	if ((static_cast<uint32_t>(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, villageCrimeManager);
	}
	return villageCrimeManager;
}
PROMOTED_ENTRY(58, sub_8284D608, 0x8284D608) { ctx.r3.u64 = CECVillageCrimeManager_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECVillageCrimeManager_InitializeFromVillage(CpuState& ctx, uint8_t* base, uint64_t villageCrimeManagerAddr, uint64_t villageRecord) {
	constexpr int32_t str_TXT_820C47A8_B_ = int32_t(0x820C47A8);
	constexpr int32_t str_TXT_820DD954_B_ = int32_t(0x820DD954);
	constexpr int32_t str_TXT_820DD964_B_ = int32_t(0x820DD964);
	constexpr int32_t str_TXT_820DD978_B_ = int32_t(0x820DD978);
	constexpr int32_t str_TXT_820DD9BC_B_ = int32_t(0x820DD9BC);
	constexpr int32_t str_TXT_820DD9D0_B_ = int32_t(0x820DD9D0);
	if (!UseLiftedCode(58, 0x8284D740)) { ctx.r3.u64 = villageCrimeManagerAddr; ctx.r4.u64 = villageRecord; __imp__sub_8284D740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8284D740);
	uint32_t stack = ctx.r1.u64;

	CECVillageCrimeManager* villageCrimeManager = GameObject<CECVillageCrimeManager>(base, villageCrimeManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	if ((uint32_t)villageRecord != 0) {
		ctx.r1.u64 = stack;
		uint32_t isTXT_820DD954_B_ = GameDB_ReadBoolField_82303F38(ctx, base, villageRecord, str_TXT_820DD954_B_);
		villageCrimeManager->m_84 = (uint8_t)isTXT_820DD954_B_;

		uint64_t TXT_820DD964_L_ = str_TXT_820DD964_B_;
		uint64_t crimeHash = String_HashFnv1(ctx, base, TXT_820DD964_L_, 0xFFFFFFFF811C9DC5ULL);

		uint32_t fieldValue = GameDB_FindFieldValue(ctx, base, villageRecord, crimeHash, 6);
		uint32_t crimeId = (fieldValue != 0) ? LOAD32(fieldValue) : 0;

		// Build the crime IdRef into a stack temporary, then copy it into the manager.
		uint64_t idRefTmp = (uint64_t)stack + 80;
		IdRef_ConstructFromId(ctx, base, idRefTmp, crimeId);

		uint64_t idRefAddr = (int64_t)villageCrimeManagerAddr + 12;
		STORE64((uint32_t)villageCrimeManagerAddr + 12, LOAD64(idRefTmp));

		uint64_t crimeIdRef = IdRef_Get(ctx, base, idRefAddr);
		if ((uint32_t)crimeIdRef != 0) {
			uint32_t isTXT_820DD978_B_ = GameDB_ReadBoolField_82303F38(ctx, base, crimeIdRef, str_TXT_820DD978_B_);
			villageCrimeManager->m_83 = (uint8_t)isTXT_820DD978_B_;

			uint64_t idRef2 = IdRef_Get(ctx, base, idRefAddr);
			uint32_t harassmentThreshold = GameDB_GetIntByName(ctx, base, idRef2, 0xFFFFFFFF820DD98CULL);
			villageCrimeManager->m_88 = harassmentThreshold;

			uint64_t idRef3 = IdRef_Get(ctx, base, idRefAddr);
			GameDB_GetFloatByName(ctx, base, idRef3, 0xFFFFFFFF820DD9A0ULL);
			double floatValue = ctx.f1.f64;
			ctx.fpscr.disableFlushMode();
			villageCrimeManager->m_8C = (float)floatValue;
		}
	}

	ctx.r1.u64 = stack;
	uint64_t TXT_820C47A8_L_ = str_TXT_820C47A8_B_;
	uint64_t economyHash = String_HashFnv1(ctx, base, TXT_820C47A8_L_, 0xFFFFFFFF811C9DC5ULL);
	uint32_t economyGlobalsId = LOAD32(0x83496BD0u);
	uint64_t result = HashMap_FindByHash(ctx, base, economyGlobalsId, economyHash);

	if ((uint32_t)result != 0) {
		uint64_t pubDebtAddr = (int64_t)villageCrimeManagerAddr + 148;
		GameDB_ReadU32FieldByName(ctx, base, result, str_TXT_820DD9BC_B_, pubDebtAddr);

		uint64_t grossPubDebtAddr = (int64_t)villageCrimeManagerAddr + 144;
		result = GameDB_ReadU32FieldByName(ctx, base, result, str_TXT_820DD9D0_B_, grossPubDebtAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(58, sub_8284D740, 0x8284D740) { ctx.r3.u64 = CECVillageCrimeManager_InitializeFromVillage(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECVillageCrimeManager_ClearCrimeLists(CpuState& ctx, uint8_t* base, uint64_t villageCrimeManagerAddr) {
	if (!UseLiftedCode(58, 0x8284D888)) { ctx.r3.u64 = villageCrimeManagerAddr; __imp__sub_8284D888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8284D888);
	uint32_t stack = ctx.r1.u64;
	CECVillageCrimeManager* villageCrimeManager = GameObject<CECVillageCrimeManager>(base, villageCrimeManagerAddr);
	uint32_t managerAddr = (uint32_t)villageCrimeManagerAddr;
	uint64_t lastCalleeResult = villageCrimeManagerAddr;

	stack = PushStackFrame(base, stack, 112);

	// Each list is a circular intrusive list whose sentinel is stored in the manager.
	uint32_t listHead = managerAddr + 0x18;
	for (uint32_t entry = LOAD32(uint32_t(villageCrimeManager->m_18)); entry != LOAD32(listHead); entry = LOAD32(entry)) {
		ctx.r1.u64 = stack;
		lastCalleeResult = n_sub_8284C0B8(ctx, base, LOAD32(entry + 8));
		if (entry == LOAD32(listHead)) {
			ppc_trap(ctx, base, 22);
		}
	}

	listHead = managerAddr + 0x30;
	for (uint32_t entry = LOAD32(uint32_t(villageCrimeManager->m_30)); entry != LOAD32(listHead); entry = LOAD32(entry)) {
		ctx.r1.u64 = stack;
		lastCalleeResult = n_sub_8284C0B8(ctx, base, LOAD32(entry + 8));
		if (entry == LOAD32(listHead)) {
			ppc_trap(ctx, base, 22);
		}
	}

	listHead = managerAddr + 0x24;
	for (uint32_t entry = LOAD32(uint32_t(villageCrimeManager->m_24)); entry != LOAD32(listHead); entry = LOAD32(entry)) {
		ctx.r1.u64 = stack;
		lastCalleeResult = n_sub_8284D400(ctx, base, LOAD32(entry + 8));
		if (entry == LOAD32(listHead)) {
			ppc_trap(ctx, base, 22);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return lastCalleeResult;
}
PROMOTED_ENTRY(58, sub_8284D888, 0x8284D888) { ctx.r3.u64 = CECVillageCrimeManager_ClearCrimeLists(ctx, base, ctx.r3.u64); }

uint64_t CECVillageCrimeManager_Update(CpuState& ctx, uint8_t* base, uint64_t villageCrimeManagerAddr) {
	if (!UseLiftedCode(58, 0x8284F058)) { ctx.r3.u64 = villageCrimeManagerAddr; __imp__sub_8284F058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8284F058);
	uint32_t stack = ctx.r1.u64;
	CECVillageCrimeManager* villageCrimeManager = GameObject<CECVillageCrimeManager>(base, villageCrimeManagerAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	n_sub_82855578(ctx, base, villageCrimeManagerAddr);

	if (villageCrimeManager->m_80 != 0) {
		villageCrimeManager->m_80 = 0;
		CECVillageCrimeManager_SetTownAlarm(ctx, base, villageCrimeManagerAddr, 1);
	}

	uint64_t result = n_sub_82856F80(ctx, base, villageCrimeManagerAddr);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(58, sub_8284F058, 0x8284F058) { ctx.r3.u64 = CECVillageCrimeManager_Update(ctx, base, ctx.r3.u64); }

uint64_t CECVillageCrimeManager_ProcessActiveCrime(CpuState& ctx, uint8_t* base, uint32_t villageCrimeManagerAddr) {
	if (!UseLiftedCode(58, 0x82856338)) { ctx.r3.u64 = villageCrimeManagerAddr; __imp__sub_82856338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82856338);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	uint32_t hasEntry{};
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CECVillageCrimeManager* villageCrimeManager = GameObject<CECVillageCrimeManager>(base, villageCrimeManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	result = villageCrimeManager->m_9C;
	if ((int32_t)result != 0) {
		uint32_t getterAddr = LOAD32(LOAD32((uint32_t)result) + 28);
		callTarget.u64 = (uint64_t)getterAddr;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = result;
		ctx.r10.u64 = getterAddr;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		flags.ca = ctx.xer.ca;

		// Only resolve the queued crime entry while the game is in the matching state.
		if (int32_t(LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 284)) == 1) {
			uint32_t crimeGroup = villageCrimeManager->m_4;
			result = 0;
			hasEntry = 0;
			if (uint32_t((LOAD32(crimeGroup + 44) >> 27) & 1) != 0) {
				uint32_t indexSource = LOAD32(crimeGroup + 140);
				if (indexSource != 0) {
					uint32_t entryIndex = LOAD8(indexSource + 91);
					uint32_t entryArray = LOAD32(crimeGroup + 72);
					result = (uint64_t)LOAD32(entryArray + (entryIndex << 3) + 4);
					hasEntry = 1;
				} else {
					uint32_t entryBegin = LOAD32(crimeGroup + 72);
					uint32_t entryEnd = LOAD32(crimeGroup + 76);
					STORE32(stack + 80, 0);
					uint32_t byteCount = entryEnd - entryBegin;
					STORE32(stack + 84, entryBegin);
					flags.ca = ((int32_t)byteCount < 0) & ((byteCount & 7) != 0);
					int32_t remaining = (int32_t)byteCount >> 3;
					// lower_bound over the key-ordered entry array, looking for key 91
					while (remaining > 0) {
						flags.ca = ((int32_t)remaining < 0) & ((remaining & 1) != 0);
						int32_t half = remaining >> 1;
						uint32_t entry = entryBegin + ((uint32_t)half << 3);
						compare6.compare<int32_t>(int32_t(LOAD32(entry)), 91, flags);
						if (compare6.lt) {
							remaining = remaining - half - 1;
							entryBegin = entry + 8;
						} else {
							remaining = half;
						}
					}
					STORE32(stack + 84, entryBegin);
					if (entryBegin != entryEnd) {
						compare6.compare<int32_t>(int32_t(LOAD32(entryBegin)), 91, flags);
						if (compare6.gt) {
							result = (uint64_t)LOAD32(entryEnd + 4);
						} else {
							result = (uint64_t)LOAD32(entryBegin + 4);
						}
					} else {
						result = (uint64_t)LOAD32(entryEnd + 4);
					}
					hasEntry = 1;
				}
			}
			if (hasEntry != 0) {
				ctx.xer.ca = flags.ca;
				result = CECNetwork_ReplicateEntityEvent(ctx, base, result);
			}
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(58, sub_82856338, 0x82856338) { ctx.r3.u64 = CECVillageCrimeManager_ProcessActiveCrime(ctx, base, ctx.r3.u32); }
