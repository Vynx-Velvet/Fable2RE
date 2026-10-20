// CECCombat (vtable 0x82003F58): methods of the class as readable C++.
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

uint64_t CECCombat_HandleEvent(CpuState& ctx, uint8_t* base, uint64_t combatAddr, uint64_t event, uint64_t arg3) {
	if (!UseLiftedCode(7, 0x82238358)) { ctx.r3.u64 = combatAddr; ctx.r4.u64 = event; ctx.r8.u64 = arg3; __imp__sub_82238358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82238358);
	GameStackFrame stackFrame(ctx, base, 96);

	// event's virtual slot 1 returns a code; only code 8 continues below.
	uint32_t arg2Vtable = LOAD32((uint32_t)event);
	uint32_t codeFn = LOAD32(arg2Vtable + 4);
	ctx.r3.u64 = event;
	ctx.r4.u64 = event;
	ctx.r8.u64 = arg3;
	ctx.r10.u64 = codeFn;
	REX_CALL_INDIRECT_FUNC(codeFn);
	uint64_t result = ctx.r3.u64;

	if ((int32_t)result == 8) {
		Combat_ClearFiringPosition(ctx, base, combatAddr);

		uint32_t combatVtable = LOAD32((uint32_t)combatAddr);
		STORE8((uint32_t)combatAddr + 0x6D, uint8_t(1));
		uint32_t componentTypeFn = LOAD32(combatVtable + 16);
		uint32_t ownerEntity = LOAD32((uint32_t)combatAddr + 4);

		// virtual slot 4 of the combat object gives the component type to remove from its owner
		ctx.r3.u64 = combatAddr;
		ctx.r9.u64 = componentTypeFn;
		ctx.r10.u64 = combatVtable;
		REX_CALL_INDIRECT_FUNC(componentTypeFn);
		uint64_t componentType = ctx.r3.u64;

		result = Entity_RemoveComponentByType(ctx, base, ownerEntity, componentType, ctx.r8.u64);
	}
	return result;
}
PROMOTED_ENTRY(7, sub_82238358, 0x82238358) { ctx.r3.u64 = CECCombat_HandleEvent(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t n_sub_827512B0(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(50, 0x827512B0)) { __imp__sub_827512B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827512B0);
	uint32_t stack = ctx.r1.u32;
	ctx.fpscr.disableFlushMode();

	double product = LOAD_F64(0x83319510u) * LOAD_F64(0x821004A0u);

	// double -> int32 as the PowerPC truncating conversion does it: toward zero, out-of-range
	// values saturate to INT_MIN / INT_MAX, NaN gives INT_MIN. The result goes through the
	// stack slot below the frame and its low word is returned.
	union { int64_t s64; double f64; } converted;
	converted.s64 = std::isnan(product) ? int64_t(0x80000000u)
	              : product > double(INT_MAX) ? INT_MAX
	              : simde_mm_cvttsd_si32(simde_mm_load_sd(&product));

	STORE_F64(stack - 16, converted.f64);
	return LOAD32(stack - 12);
}
PROMOTED_ENTRY(50, sub_827512B0, 0x827512B0) { ctx.r3.u64 = n_sub_827512B0(ctx, base); }

uint64_t CECCombat_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8ED8_B_ = int32_t(0x820C8ED8);
	if (!UseLiftedCode(52, 0x827942B8)) { ctx.r3.u64 = classNameString; __imp__sub_827942B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827942B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t className = str_TXT_820C8ED8_B_;
	int32_t nameLength = -1;  // -1: length taken from the NUL terminator
	CCharString_ConstructFromCStr(ctx, base, classNameString, className, nameLength);
	return classNameString;
}
PROMOTED_ENTRY(52, sub_827942B8, 0x827942B8) { ctx.r3.u64 = CECCombat_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECCombat_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t combatAddr, uint64_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(52, 0x827944D8)) { ctx.r3.u64 = combatAddr; ctx.r4.u64 = deleteFlags; __imp__sub_827944D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827944D8);
	uint32_t stack = ctx.r1.u64;
	CECCombat* combat = GameObject<CECCombat>(base, combatAddr);
	// 0x820F1664 is the EntityHandle vtable; each handle member gets it back before it is released.
	const uint32_t entityHandleVtable = (uint32_t)g_820F1664;

	stack = PushStackFrame(base, stack, 128);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;  // state the callee may pass on
	HandleList_Clear_82799248(ctx, base, combatAddr + 276);

	List_ClearFreeNodes(ctx, base, combatAddr + 256);

	uint32_t pointer104 = combat->m_104;
	HandleTarget_Free(ctx, base, pointer104);
	combat->m_104 = 0;

	combat->m_E0 = entityHandleVtable;
	EntityHandle_Release(ctx, base, combatAddr + 224);
	combat->m_E4 = 0;

	combat->m_D8 = entityHandleVtable;
	EntityHandle_Release(ctx, base, combatAddr + 216);
	combat->m_DC = 0;

	C_820EFB9C_Destructor(ctx, base, combatAddr + 72);

	combat->m_14 = entityHandleVtable;
	EntityHandle_Release(ctx, base, combatAddr + 20);
	combat->m_18 = 0;

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, combatAddr + 16);

	// The vtable pointers at +12 and +0 get the C_820A8F74 and C_820A8D10 vtables; the +12
	// address is computed as 0 for a null object, as the original code does.
	uint32_t secondVtableSlot = 0;
	if ((uint32_t)combatAddr != 0) {
		secondVtableSlot = (uint32_t)combatAddr + 12;
	}
	STORE32(secondVtableSlot, 0x820A8F74u);
	combat->vtable = 0x820A8D10u;

	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, combatAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return combatAddr;
}
PROMOTED_ENTRY(52, sub_827944D8, 0x827944D8) { ctx.r3.u64 = CECCombat_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECCombat_LoadProperties(CpuState& ctx, uint8_t* base, uint64_t combatAddr, uint64_t propertyDef) {
	// Field-name addresses. The original code built most of them from the high halves
	// 0x820D0000 and 0x820B0000 and left those halves in r6-r9 for the callees.
	constexpr int32_t namesHigh_820D0000 = int32_t(0x820D0000);
	constexpr int32_t namesHigh_820B0000 = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820D4B7C_B_ = int32_t(0x820D4B7C);
	constexpr int32_t str_TXT_820BE994_B_ = int32_t(0x820BE994);
	constexpr int32_t str_TXT_820D4B88_B_ = int32_t(0x820D4B88);
	constexpr int32_t str_TXT_820D4B94_B_ = int32_t(0x820D4B94);
	constexpr int32_t str_TXT_820D4B9C_B_ = int32_t(0x820D4B9C);
	constexpr int32_t str_TXT_820A88C0_B_ = int32_t(0x820A88C0);
	constexpr int32_t str_TXT_820D4BAC_B_ = int32_t(0x820D4BAC);
	constexpr int32_t str_TXT_820D4BD0_B_ = int32_t(0x820D4BD0);
	if (!UseLiftedCode(52, 0x82794598)) { ctx.r3.u64 = combatAddr; ctx.r4.u64 = propertyDef; __imp__sub_82794598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82794598);
	uint32_t stack = ctx.r1.u64;
	// Register values the later calls hand on: r4 starts as the parameter, r6-r8 as on entry;
	// calls and the search below update them.
	uint64_t stateR4 = propertyDef;
	uint64_t stateR6 = ctx.r6.u64;
	uint64_t stateR7 = ctx.r7.u64;
	uint64_t stateR8 = ctx.r8.u64;
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	CECCombat* combat = GameObject<CECCombat>(base, combatAddr);

	stack = PushStackFrame(base, stack, 112);

	// Read the properties from the GameDB into the combat component.
	if ((uint32_t)propertyDef != 0) {
		ctx.r1.u64 = stack;
		GameDB_ReadStringFieldByName(ctx, base, propertyDef, uint64_t(str_TXT_820D4B7C_B_), combatAddr + 16);
		flags.ca = ctx.xer.ca;
		GameDB_ReadU32FieldByName(ctx, base, propertyDef, uint64_t(str_TXT_820BE994_B_), combatAddr + 84);
		ctx.r9.s64 = namesHigh_820D0000;  // state the callee may pass on
		GameDB_ReadBool(ctx, base, propertyDef, uint64_t(str_TXT_820D4B88_B_), combatAddr + 88);
		ctx.r8.s64 = namesHigh_820D0000;  // state the callee may pass on
		GameDB_ReadBool(ctx, base, propertyDef, uint64_t(str_TXT_820D4B94_B_), combatAddr + 89);
		ctx.r7.s64 = namesHigh_820D0000;  // state the callee may pass on
		GameDB_ReadBool(ctx, base, propertyDef, uint64_t(str_TXT_820D4B9C_B_), combatAddr + 101);
		ctx.r6.s64 = namesHigh_820B0000;  // state the callee may pass on
		GameDB_ReadFloatField(ctx, base, propertyDef, uint64_t(str_TXT_820A88C0_B_), combatAddr + 56);
		GameDB_ReadFloatField(ctx, base, propertyDef, uint64_t(str_TXT_820D4BAC_B_), combatAddr + 64);
		GameDB_ReadFloatField(ctx, base, propertyDef, uint64_t(str_TXT_820D4BD0_B_), combatAddr + 68);
		CECCombat_LoadShootingBalanceData(ctx, base, combatAddr, ctx.r6.u64, ctx.r7.u64);
		stateR4 = ctx.r4.u64;
		stateR6 = ctx.r6.u64;
		stateR7 = ctx.r7.u64;
		stateR8 = ctx.r8.u64;
		flags.ca = ctx.xer.ca;
	}

	// When bit 31 of the owner's word at +36 is set, look up the value stored under key 31 in
	// the owner's table of 8-byte (key, value) entries sorted by key: through the owner's
	// slot-index table at +140 when there is one, otherwise by a lower-bound binary search.
	uint32_t owner = combat->m_owner;
	uint32_t foundValue = 0;
	bool found = false;

	if ((LOAD32(owner + 36) >> 31) != 0) {
		uint32_t slotIndexTable = LOAD32(owner + 140);
		if (slotIndexTable != 0) {
			uint32_t slot = LOAD8(slotIndexTable + 31);
			uint32_t entries = LOAD32(owner + 72);
			foundValue = LOAD32(slot * 8 + entries + 4);
			found = true;
		} else {
			uint32_t first = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			stateR6 = end;
			STORE32(stack + 80, 0u);
			int32_t byteCount = (int32_t)(end - first);
			STORE32(stack + 84, first);
			flags.ca = byteCount < 0 & (byteCount & 0x7) != 0;
			int32_t count = byteCount >> 3;
			if (count > 0) {
				do {
					flags.ca = count < 0 & (count & 0x1) != 0;
					int32_t half = count >> 1;
					stateR8 = uint32_t(half) << 3;
					uint32_t mid = first + (uint32_t)stateR8;
					compare6.compare<int32_t>((int32_t)LOAD32(mid), 31, flags);
					stateR7 = compare6.lt ? 1 : 0;
					if (compare6.lt) {
						first = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, first);
			}
			if (first != end) {
				compare6.compare<int32_t>((int32_t)LOAD32(first), 31, flags);
				if (compare6.gt) {
					// key 31 is absent: the value comes from the end position
					foundValue = LOAD32(end + 4);
				} else {
					STORE64(stack + 80, LOAD64(stack + 80));
					uint32_t lowerBound = LOAD32(stack + 84);
					foundValue = LOAD32(lowerBound + 4);
				}
			} else {
				foundValue = LOAD32(end + 4);
			}
			found = true;
		}
	}

	if (found) {
		ctx.r1.u64 = stack;
		ctx.r7.u64 = stateR7;  // state the callee may pass on
		ctx.r8.u64 = stateR8;
		ctx.xer.ca = flags.ca;
		n_sub_82483858(ctx, base, foundValue, combatAddr + 72, combatAddr + 12, 30);
		stateR4 = ctx.r4.u64;
		stateR6 = ctx.r6.u64;
		flags.ca = ctx.xer.ca;
	}
	ctx.r1.u64 = stack;
	ctx.r4.u64 = stateR4;  // state the callee may pass on
	ctx.r6.u64 = stateR6;
	ctx.xer.ca = flags.ca;
	uint64_t result = HandleList_Clear_82799248(ctx, base, combatAddr + 276);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_82794598, 0x82794598) { ctx.r3.u64 = CECCombat_LoadProperties(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECCombat_SerializeProperties(CpuState& ctx, uint8_t* base, uint64_t combatComponent, uint64_t stateStream, uint32_t includePlayerRegroupFields) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820D4B7C_B_ = int32_t(0x820D4B7C);
	constexpr int32_t str_TXT_820D4B88_B_ = int32_t(0x820D4B88);
	constexpr int32_t str_TXT_820D4B94_B_ = int32_t(0x820D4B94);
	constexpr int32_t str_TXT_820D4B9C_B_ = int32_t(0x820D4B9C);
	constexpr int32_t str_TXT_820D4BAC_B_ = int32_t(0x820D4BAC);
	constexpr int32_t str_TXT_820D4BD0_B_ = int32_t(0x820D4BD0);
	constexpr int32_t str_TXT_820D4BF4_B_ = int32_t(0x820D4BF4);
	constexpr int32_t str_TXT_820D4C04_B_ = int32_t(0x820D4C04);
	constexpr int32_t str_TXT_820D4C14_B_ = int32_t(0x820D4C14);
	constexpr int32_t str_TXT_820D4C2C_B_ = int32_t(0x820D4C2C);
	constexpr int32_t str_TXT_820D4C40_B_ = int32_t(0x820D4C40);
	constexpr int32_t str_TXT_820D4C58_B_ = int32_t(0x820D4C58);
	constexpr int32_t str_TXT_820D4C74_B_ = int32_t(0x820D4C74);
	constexpr int32_t str_TXT_820D4C90_B_ = int32_t(0x820D4C90);
	constexpr int32_t str_TXT_820D4C9C_B_ = int32_t(0x820D4C9C);
	if (!UseLiftedCode(52, 0x827947B0)) { ctx.r3.u64 = combatComponent; ctx.r4.u64 = stateStream; ctx.r5.u64 = includePlayerRegroupFields; __imp__sub_827947B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827947B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Each field is serialised under a temporary name string built at stack+80.
	const uint32_t nameBuffer = stack + 80;
	const uint64_t noDataWord = (int64_t)g_8209003F;
	uint64_t result{};

	// The numeric serialisers take a value derived from the name in r4: the first word of
	// the name string's data block, or the address 0x8209003F when it has no data block.
	auto nameDataWord = [&]() -> uint64_t {
		uint32_t data = LOAD32(nameBuffer);
		return data != 0 ? LOAD32(data) : noDataWord;
	};

	ctx.r1.u64 = stack;

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4B88_B_, -1);
	IStream_SerializeString(ctx, base, nameBuffer, stateStream, combatComponent + 88);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4B94_B_, -1);
	IStream_SerializeString(ctx, base, nameBuffer, stateStream, combatComponent + 89);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4B7C_B_, -1);
	IStream_SerializeCCharString(ctx, base, nameBuffer, stateStream, combatComponent + 16);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4B9C_B_, -1);
	IStream_SerializeString(ctx, base, nameBuffer, stateStream, combatComponent + 101);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4BF4_B_, -1);
	ctx.r4.u64 = nameDataWord();
	IStream_SerializeU32(ctx, base, stateStream, combatComponent + 104);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C04_B_, -1);
	ctx.r4.u64 = nameDataWord();
	IStream_SerializeFloat(ctx, base, stateStream, combatComponent + 184);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4BAC_B_, -1);
	ctx.r4.u64 = nameDataWord();
	IStream_SerializeFloat(ctx, base, stateStream, combatComponent + 64);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4BD0_B_, -1);
	ctx.r4.u64 = nameDataWord();
	IStream_SerializeFloat(ctx, base, stateStream, combatComponent + 68);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C14_B_, -1);
	IStream_SerializeString(ctx, base, nameBuffer, stateStream, combatComponent + 132);
	result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	if (includePlayerRegroupFields == 1) {
		CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C2C_B_, -1);
		IStream_SerializeString(ctx, base, nameBuffer, stateStream, combatComponent + 91);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

		CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C40_B_, -1);
		IStream_SerializeString(ctx, base, nameBuffer, stateStream, combatComponent + 133);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

		CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C58_B_, -1);
		ctx.r4.u64 = nameDataWord();
		IStream_SerializeFloat(ctx, base, stateStream, combatComponent + 136);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

		CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C74_B_, -1);
		ctx.r4.u64 = nameDataWord();
		IStream_SerializeFloat(ctx, base, stateStream, combatComponent + 140);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

		CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C90_B_, -1);
		ctx.r4.u64 = nameDataWord();
		IStream_SerializeFloat(ctx, base, stateStream, combatComponent + 48);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

		CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820D4C9C_B_, -1);
		ctx.r4.u64 = nameDataWord();
		IStream_SerializeFloat(ctx, base, stateStream, combatComponent + 52);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_827947B0, 0x827947B0) { ctx.r3.u64 = CECCombat_SerializeProperties(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CECCombat_UpdateRegroupPoint(CpuState& ctx, uint8_t* base, uint64_t combatAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x82794AF8)) { ctx.r3.u64 = combatAddr; __imp__sub_82794AF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82794AF8);
	uint32_t stack = ctx.r1.u64;
	CECCombat* combat = GameObject<CECCombat>(base, combatAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = combatAddr;

	if (LOAD8((uint32_t)combatAddr + 133) != 0) {
		uint32_t owner = combat->m_owner;
		ctx.r1.u64 = stack;
		CECDoor_UpdateOpenStateForEntity(ctx, base, owner, combatAddr);

		// Resolve the handle held by the first entry of the list reached from the global at
		// 0x83496920.
		uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t list = LOAD32(LOAD32(globalObject + 12) + 88);
		uint32_t firstEntry = LOAD32(list + 4);
		uint32_t handle = LOAD32(firstEntry);
		ctx.r8.u64 = firstEntry;  // state the callee may pass on
		ctx.r9.u64 = list;
		result = EntityHandle_Get(ctx, base, handle);

		// If the entity exists and has bit 0x40 set at +144, its component at +124 writes a
		// 16-byte vector to stack+80 through virtual slot 16, which is copied to +32 here.
		uint32_t entity = (uint32_t)result;
		if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
			uint32_t component = LOAD32(entity + 124);
			uint32_t vectorBuffer = stack + 80;
			uint32_t getVectorFn = LOAD32(LOAD32(component) + 64);
			ctx.r3.u64 = vectorBuffer;
			ctx.r4.u64 = component;
			ctx.r10.u64 = getVectorFn;
			REX_CALL_INDIRECT_FUNC(getVectorFn);
			result = ctx.r3.u64;

			PPCVRegister vec{};
			SET_V8(vec, VLOAD(vectorBuffer & ~0xF));
			VSTORE(((uint32_t)combatAddr + 32u) & ~0xF, V8(vec));
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_82794AF8, 0x82794AF8) { ctx.r3.u64 = CECCombat_UpdateRegroupPoint(ctx, base, ctx.r3.u64); }

uint64_t CECCombat_OverrideCombatStyle(CpuState& ctx, uint8_t* base, uint64_t combatAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x82794BA8)) { ctx.r3.u64 = combatAddr; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_82794BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82794BA8);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vec{};
	PPCRegister callTarget{};
	CECCombat* combat = GameObject<CECCombat>(base, combatAddr);
	stack = PushStackFrame(base, stack, 208);

	// double -> int32 as the PowerPC truncating conversion does it (out-of-range values
	// saturate, NaN gives INT_MIN); the result sits in the low word of the register.
	auto truncateToInt32 = [](double value) {
		PPCRegister converted{};
		converted.s64 = std::isnan(value) ? int64_t(0x80000000U) : value > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&value));
		return converted;
	};

	if (LOAD8((uint32_t)combatAddr + 133) == 0) {
		// The owner's component at +124 writes a 16-byte vector to stack+128 through virtual
		// slot 16; it is copied to stack+144 and to the combat object's vector at +32.
		uint32_t ownerComponent = LOAD32(uint32_t(combat->m_owner) + 124);
		uint32_t ownerComponentVtable = LOAD32(ownerComponent);
		uint32_t getVectorFn = LOAD32(ownerComponentVtable + 64);
		callTarget.u64 = getVectorFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stack + 128;
		ctx.r4.u64 = ownerComponent;
		ctx.r7.u64 = arg2;
		ctx.r8.u64 = arg3;
		ctx.r9.u64 = getVectorFn;
		ctx.r10.u64 = ownerComponentVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t combatVector = (uint32_t)combatAddr + 32;
		SET_V8(vec, VLOAD((stack + 128) & ~0xF));
		VSTORE((stack + 144) & ~0xF, V8(vec));
		VSTORE(combatVector & ~0xF, V8(vec));

		// Integer box around the vector's first two components: each side lies halfSize away.
		ctx.fpscr.disableFlushMode();
		double halfSize = LOAD_F64(0x82100520u);
		uint32_t owner = combat->m_owner;
		halfSize = ceil(ctx, base, halfSize);
		ctx.fpscr.disableFlushMode();
		double halfSizeSingle = double(float(halfSize));
		SET_V8(vec, VLOAD(combatVector & ~0xF));
		uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
		VSTORE((stack + 112) & ~0xF, V8(vec));

		double y = double(LOAD_F32(stack + 116));
		PPCRegister yInt = truncateToInt32(y);
		uint32_t globalChild = LOAD32(globalObject + 12);
		STORE_F64(stack + 96, yInt.f64);
		uint32_t yValue = LOAD32(stack + 100);
		VSTORE((stack + 112) & ~0xF, V8(vec));

		PPCRegister halfSizeInt = truncateToInt32(halfSizeSingle);
		double x = double(LOAD_F32(stack + 112));
		STORE_F64(stack + 96, halfSizeInt.f64);
		uint32_t halfSizeValue = LOAD32(stack + 100);

		PPCRegister xInt = truncateToInt32(x);
		STORE_F64(stack + 96, xInt.f64);
		uint32_t list = LOAD32(globalChild + 88);
		uint32_t xValue = LOAD32(stack + 100);
		uint32_t firstEntry = LOAD32(list + 4);

		// The sums are kept 64-bit: they also go to the callee in r7 and r8.
		uint64_t maxX = (uint64_t)xValue + (uint64_t)halfSizeValue;
		STORE32(stack + 96, 3u);
		uint64_t minY = (uint64_t)yValue - (uint64_t)halfSizeValue;
		STORE32(stack + 112, uint32_t((uint64_t)xValue - (uint64_t)halfSizeValue));
		STORE32(stack + 116, (uint32_t)minY);
		STORE32(stack + 120, (uint32_t)maxX);
		uint32_t firstEntryWord12 = LOAD32(firstEntry + 12);
		STORE32(stack + 124, uint32_t((uint64_t)yValue + (uint64_t)halfSizeValue));

		ctx.r7.u64 = maxX;  // state the callee may pass on
		n_sub_82464918(ctx, base, stack + 80, owner);

		// Block at stack+96 for n_sub_8279D718: { 3, stack+80, stack+144, result slot }.
		STORE32(stack + 100, stack + 80);
		STORE32(stack + 104, stack + 144);
		STORE32(stack + 108, 0u);

		ctx.f1.f64 = halfSize;  // state the callee may pass on
		ctx.f9 = halfSizeInt;
		ctx.f10 = xInt;
		ctx.f11.f64 = x;
		ctx.f12 = yInt;
		ctx.f13.f64 = y;
		n_sub_8279D718(ctx, base, firstEntryWord12, stack + 112, stack + 96);
		arg2 = ctx.r7.u64;
		arg3 = ctx.r8.u64;

		// When n_sub_8279D718 left an object in the result slot whose byte at +144 has bit 0x40
		// set, that object's component at +124 writes a vector the same way, and it replaces
		// the combat object's vector at +32.
		uint32_t foundObject = LOAD32(stack + 108);
		if (foundObject != 0) {
			uint32_t flagBit = LOAD8(foundObject + 144) & 64;
			if (flagBit != 0) {
				uint32_t foundComponent = LOAD32(foundObject + 124);
				uint32_t foundGetVectorFn = LOAD32(LOAD32(foundComponent) + 64);
				callTarget.u64 = foundGetVectorFn;
				ctx.r3.u64 = stack + 160;
				ctx.r4.u64 = foundComponent;
				ctx.r9.u64 = flagBit;
				ctx.r10.u64 = foundGetVectorFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				arg2 = ctx.r7.u64;
				arg3 = ctx.r8.u64;
				SET_V8(vec, VLOAD((stack + 160) & ~0xF));
				VSTORE(combatVector & ~0xF, V8(vec));
			}
		}
	}

	ctx.r1.u64 = stack;
	uint64_t result = Combat_OverrideCombatStyle_Impl(ctx, base, combatAddr, 0, arg2, arg3);
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_82794BA8, 0x82794BA8) { ctx.r3.u64 = CECCombat_OverrideCombatStyle(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

// sub_82794D28  [4 bytes]
uint64_t CECCombat_RestoreCombatStyleThunk(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(52, 0x82794D28)) { ctx.r3.u64 = arg1; ctx.r7.u64 = arg2; __imp__sub_82794D28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82794D28);
	return CECCombat_RestoreCombatStyle(ctx, base, arg1, arg2);
}
PROMOTED_ENTRY(52, sub_82794D28, 0x82794D28) { ctx.r3.u64 = CECCombat_RestoreCombatStyleThunk(ctx, base, ctx.r3.u64, ctx.r7.u64); }

// sub_827967E0  [152 bytes]
uint64_t Combat_OverrideCombatStyle_Impl(CpuState& ctx, uint8_t* base, uint64_t combatAddr, uint32_t luaFlag, uint64_t arg3, uint64_t arg4) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x827967E0)) { ctx.r3.u64 = combatAddr; ctx.r4.u64 = luaFlag; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; __imp__sub_827967E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827967E0);
	uint32_t stack = ctx.r1.u64;
	uint64_t r9ForCaller = ctx.r9.u64;
	uint64_t result = combatAddr;
	CECCombat* combat = GameObject<CECCombat>(base, combatAddr);
	stack = PushStackFrame(base, stack, 112);

	if (combat->m_styleOverridePending == 0) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 0x6920);
		uint32_t rootChild = LOAD32(globalRoot + 0x0C);
		uint32_t flagBlock = LOAD32(rootChild + 0x8C);
		uint8_t flag34 = LOAD8(flagBlock + 0x34);
		r9ForCaller = flag34;
		bool skipLuaCall = flag34 != 0 && LOAD8(flagBlock + 0x36) != 0;
		if (!skipLuaCall) {
			// The callee reads this byte through its address and hands it to Lua as a boolean.
			STORE8(stack + 80, (uint8_t)luaFlag);
			uint64_t luaFlagAddr = (uint64_t)stack + 80;
			// Holds Lua references at +0xE0 and +0xE8 (read by the callee).
			uint32_t scriptObj = LOAD32(LOAD32(rootChild + 0x78) + 4);
			uint32_t owner = combat->m_owner;
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r9.u64 = r9ForCaller;
			result = Combat_CallLuaOverrideCombatStyle(ctx, base, (uint64_t)scriptObj + 0xE8, (uint64_t)scriptObj + 0xE0, owner, luaFlagAddr, arg3, arg4);
			arg3 = ctx.r7.u64;
			arg4 = ctx.r8.u64;
			r9ForCaller = ctx.r9.u64;
			combat->m_styleOverridePending = uint8_t(1);
		}
	}
	stack = PopStackFrame(stack, 112);
	// callers read r7-r9 after the call
	ctx.r1.u64 = stack;
	ctx.r7.u64 = arg3;
	ctx.r8.u64 = arg4;
	ctx.r9.u64 = r9ForCaller;
	return result;
}
PROMOTED_ENTRY(52, sub_827967E0, 0x827967E0) { ctx.r3.u64 = Combat_OverrideCombatStyle_Impl(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r7.u64, ctx.r8.u64); }

// sub_82796878  [140 bytes]
uint64_t CECCombat_RestoreCombatStyle(CpuState& ctx, uint8_t* base, uint64_t combatAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x82796878)) { ctx.r3.u64 = combatAddr; ctx.r7.u64 = arg2; __imp__sub_82796878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82796878);
	uint32_t stack = ctx.r1.u64;
	CECCombat* combat = GameObject<CECCombat>(base, combatAddr);

	stack = PushStackFrame(base, stack, 112);

	// Zero the 16 bytes at +0xF0, then clear the node list at +0x100.
	PPCVRegister zeroVec{};
	SET_V8(zeroVec, simde_mm_set1_epi32(0));
	VSTORE(((uint32_t)combatAddr + 240u) & ~0xF, V8(zeroVec));

	// state the callee may pass on
	ctx.r1.u64 = stack;
	uint64_t result = List_ClearFreeNodes(ctx, base, combatAddr + 256);

	uint8_t styleOverridePending = combat->m_styleOverridePending;
	uint64_t r7ForCaller = ctx.r7.u64;
	uint64_t r9ForCaller = styleOverridePending;

	ctx.fpscr.disableFlushMode();
	combat->m_10C = LOAD_F32(0x820994B4u);

	if (styleOverridePending != 0) {
		uint32_t owner = combat->m_owner;
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 0x6920);
		// The callee reads this byte through its address and hands it to Lua as a boolean.
		uint64_t luaFlagAddr = (uint64_t)stack + 80;
		STORE8(stack + 80, uint8_t(combat->m_6D));

		uint32_t rootChild = LOAD32(globalRoot + 0x0C);
		uint32_t scriptObjHolder = LOAD32(rootChild + 0x78);
		// Holds Lua references at +0xE0 and +0xF4 (read by the callee).
		uint32_t scriptObj = LOAD32(scriptObjHolder + 4);

		// state the callee may pass on
		ctx.r9.u64 = rootChild;
		result = Combat_CallLuaOverrideCombatStyle(ctx, base, (uint64_t)scriptObj + 0xF4, (uint64_t)scriptObj + 0xE0, owner, luaFlagAddr, ctx.r7.u64, scriptObjHolder);
		r9ForCaller = ctx.r9.u64;

		r7ForCaller = 0;
		combat->m_styleOverridePending = 0;
	}

	stack = PopStackFrame(stack, 112);
	// callers read r7 and r9 after the call
	ctx.r1.u64 = stack;
	ctx.r7.u64 = r7ForCaller;
	ctx.r9.u64 = r9ForCaller;
	return result;
}
PROMOTED_ENTRY(52, sub_82796878, 0x82796878) { ctx.r3.u64 = CECCombat_RestoreCombatStyle(ctx, base, ctx.r3.u64, ctx.r7.u64); }

// sub_82798DC0  [344 bytes]
uint64_t CECCombat_LoadShootingBalanceData(CpuState& ctx, uint8_t* base, uint64_t combatAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t stringTableBase = int32_t(0x820D0000);
	constexpr int32_t str_TXT_820D538C_B_ = int32_t(0x820D538C);
	constexpr int32_t str_TXT_820D53A0_B_ = int32_t(0x820D53A0);
	constexpr int32_t str_TXT_820D53C0_B_ = stringTableBase + 21440;
	constexpr int32_t str_TXT_820D53E0_B_ = stringTableBase + 21472;
	constexpr int32_t str_TXT_820D5404_B_ = stringTableBase + 21508;
	constexpr int32_t str_TXT_820D5420_B_ = stringTableBase + 21536;
	constexpr int32_t str_TXT_820D5444_W_ = stringTableBase + 21572;
	constexpr int32_t str_TXT_820D5474_B_ = stringTableBase + 21620;
	constexpr int32_t str_TXT_820D54A0_W_ = int32_t(0x820D54A0);
	constexpr int32_t str_TXT_820D54D0_B_ = int32_t(0x820D54D0);
	if (!UseLiftedCode(52, 0x82798DC0)) { ctx.r3.u64 = combatAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_82798DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82798DC0);
	uint32_t stack = ctx.r1.u64;
	CECCombat* combat = GameObject<CECCombat>(base, combatAddr);

	stack = PushStackFrame(base, stack, 128);
	uint64_t styleTableRef = (uint64_t)stack + 88;
	uint64_t balanceDataRef = (uint64_t)stack + 80;
	ctx.r1.u64 = stack;

	CombatStyles_GetStyleTableRef(ctx, base, styleTableRef, combatAddr, arg2, arg3);
	if (LOAD32(styleTableRef) != 0) {
		LuaTableRef_GetField(ctx, base, balanceDataRef, styleTableRef, str_TXT_820D538C_B_);
		if (LOAD32(balanceDataRef) != 0) {
			ctx.fpscr.disableFlushMode();
			double defaultValue = double(LOAD_F32(0x820994B4u));

			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D53A0_B_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_startingChanceToHitWithFirearm = float(ctx.f1.f64);

			// The original leaves the string-table base in r9, r8, r7, r6 and r5 before the next five
			// calls; kept as state the callees may pass on.
			ctx.r9.s64 = stringTableBase;
			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D53C0_B_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_maxChanceToHitWithFirearmCap = float(ctx.f1.f64);

			ctx.r8.s64 = stringTableBase;
			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D53E0_B_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_chanceToHitModBonusRangeDistance = float(ctx.f1.f64);

			ctx.r7.s64 = stringTableBase;
			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D5404_B_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_C0 = float(ctx.f1.f64);

			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D5420_B_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_C4 = float(ctx.f1.f64);

			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D5444_W_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_C8 = float(ctx.f1.f64);

			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D5474_B_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_CC = float(ctx.f1.f64);

			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D54A0_W_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_D0 = float(ctx.f1.f64);

			LuaRef_GetNumberField(ctx, base, balanceDataRef, str_TXT_820D54D0_B_, defaultValue);
			ctx.fpscr.disableFlushMode();
			combat->m_D4 = float(ctx.f1.f64);
		}
		SharedHandle_Release(ctx, base, balanceDataRef);
	}

	uint64_t releaseResult = SharedHandle_Release(ctx, base, styleTableRef);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return releaseResult;
}
PROMOTED_ENTRY(52, sub_82798DC0, 0x82798DC0) { ctx.r3.u64 = CECCombat_LoadShootingBalanceData(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64); }
