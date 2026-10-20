// CECAppearanceModifierManager (vtable 0x82003048): methods of the class as readable C++.
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

uint64_t CECAppearanceModifierManager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820BEF74_B_ = int32_t(0x820BEF74);
	if (!UseLiftedCode(34, 0x8256E938)) { ctx.r3.u64 = classNameString; __imp__sub_8256E938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8256E938);
	GameStackFrame stackFrame(ctx, base, 96);
	// Fill the caller-supplied CCharString with our class name; -1 = derive length from the C string.
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820BEF74_B_, -1);
	return classNameString;
}
PROMOTED_ENTRY(34, sub_8256E938, 0x8256E938) { ctx.r3.u64 = CECAppearanceModifierManager_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECAppearanceModifierManager_Constructor(CpuState& ctx, uint8_t* base, uint64_t appearanceModifierManagerAddr, uint64_t ownerEntity) {
	if (!UseLiftedCode(34, 0x8256E9D0)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = ownerEntity; __imp__sub_8256E9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8256E9D0);
	uint32_t stack = ctx.r1.u64;
	CECAppearanceModifierManager* appearanceModifierManager = GameObject<CECAppearanceModifierManager>(base, appearanceModifierManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	appearanceModifierManager->m_4 = (uint32_t)ownerEntity;
	appearanceModifierManager->m_8 = 0;
	appearanceModifierManager->vtable = 0x82003048u;
	appearanceModifierManager->m_10 = 0;
	appearanceModifierManager->m_14 = 0;
	appearanceModifierManager->m_18 = 0;
	appearanceModifierManager->m_20 = 0;
	appearanceModifierManager->m_24 = 0;
	appearanceModifierManager->m_28 = 0;
	appearanceModifierManager->m_30 = 0;
	appearanceModifierManager->m_34 = 0;
	appearanceModifierManager->m_38 = 0;
	appearanceModifierManager->m_3C = 0;
	appearanceModifierManager->m_3D = 1;
	appearanceModifierManager->m_3E = 0;
	appearanceModifierManager->m_3F = 0;
	appearanceModifierManager->m_40 = 0;
	appearanceModifierManager->m_48 = 0;
	appearanceModifierManager->m_4C = 0;
	appearanceModifierManager->m_50 = 0;

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = ownerEntity;
	RbTree_InitHeaderNode20(ctx, base, (uint32_t)(appearanceModifierManagerAddr + 84));

	appearanceModifierManager->m_60 = 0;
	appearanceModifierManager->m_64 = 0;
	appearanceModifierManager->m_68 = 0;

	RbTree_InitHeaderNode20(ctx, base, (uint32_t)(appearanceModifierManagerAddr + 108));

	// m_78..m_9C: five pairs of floats, all set to the constant at 0x820994B4.
	ctx.fpscr.disableFlushMode();
	double defaultValue = double(LOAD_F32(0x820994B4u));
	uint32_t pairAddr = (uint32_t)(appearanceModifierManagerAddr + 124);
	for (int i = 0; i < 5; ++i) {
		ctx.fpscr.disableFlushMode();
		STORE_F32(pairAddr - 4, float(defaultValue));
		STORE_F32(pairAddr, float(defaultValue));
		pairAddr += 8;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return appearanceModifierManagerAddr;
}
PROMOTED_ENTRY(34, sub_8256E9D0, 0x8256E9D0) { ctx.r3.u64 = CECAppearanceModifierManager_Constructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECAppearanceModifierManager_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(34, 0x8256EAA8)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_8256EAA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8256EAA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	CECAppearanceModifierManager_Destructor(ctx, base, object);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(34, sub_8256EAA8, 0x8256EAA8) { ctx.r3.u64 = CECAppearanceModifierManager_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// While the stream's slot +8 call accepts elementName, serializes a u32 field named by str_TXT_820BF0BC_B_ into a
// local (default -1), appends it to the u32 vector indexVector, and advances the stream (slot +12).
uint32_t CECAppearanceModifierManager_ReadInventoryIndices(CpuState& ctx, uint8_t* base, uint64_t indexVector, uint64_t elementName, uint64_t stream) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820BF0BC_B_ = int32_t(0x820BF0BC);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(34, 0x8256F678)) { ctx.r4.u64 = indexVector; ctx.r5.u64 = elementName; ctx.r6.u64 = stream; __imp__sub_8256F678(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8256F678);
	uint32_t stack = ctx.r1.u64;
	const uint32_t reservationMsr = (uint32_t)ctx.r13.u64;  // MSR bits (from r13) in force during the reservation
	const uint64_t inventoryIndexName = str_TXT_820BF0BC_B_;
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 160);
	uint32_t vtable = LOAD32((uint32_t)stream);
	ctx.r1.u64 = stack;

	uint32_t nameCStr = CharString_GetCStr(ctx, base, elementName);
	uint32_t findEntryFn = LOAD32(vtable + 8);
	callTarget.u64 = findEntryFn;
	ctx.r3.u64 = stream;
	ctx.r4.u64 = nameCStr;
	ctx.r5.u64 = elementName;
	ctx.r6.u64 = stream;
	ctx.r9.u64 = findEntryFn;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	if ((ctx.r3.u32 & 0xFF) != 0) {
		do {
			// scratch: stack +84 = the value read (default -1), stack +80 = a temporary CCharString holding the field name
			STORE32(stack + 84, 0xFFFFFFFF);
			CCharString_ConstructFromCStr(ctx, base, stack + 80, inventoryIndexName, -1);

			uint64_t fieldNameCStr = g_8209003F;  // fallback when the CCharString has no data
			uint32_t stringData = LOAD32(stack + 80);
			if (stringData != 0) {
				fieldNameCStr = LOAD32(stringData);
			}
			// state the callee may pass on: the field name goes in r4, which is not a native parameter
			ctx.r4.u64 = fieldNameCStr;
			IStream_SerializeU32(ctx, base, stream, stack + 84);
			CCharString_Release(ctx, base, stack + 80);

			// Atomically decrement the big-endian global counter at 0x83496EB8 (reservation loop).
			uint32_t counterAddr = (uint32_t)g_83496EB8;
			PPCCRRegister compare{};
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				uint32_t previousMsr = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = reservationMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(counterAddr);
				int32_t newCount = (int32_t)__builtin_bswap32(ctx.reserved.u32) - 1;
				compare.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(counterAddr)), ctx.reserved.s32, __builtin_bswap32(newCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = previousMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare.eq);

			STORE32(stack + 80, 0);
			Vector_U32_PushBack(ctx, base, indexVector, stack + 84);

			uint32_t nextVtable = LOAD32((uint32_t)stream);
			uint32_t nextFn = LOAD32(nextVtable + 12);
			callTarget.u64 = nextFn;
			ctx.r3.u64 = stream;
			ctx.r7.u64 = nextFn;
			ctx.r8.u64 = nextVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint32_t findVtable = LOAD32((uint32_t)stream);
			uint32_t nextNameCStr = CharString_GetCStr(ctx, base, elementName);
			uint32_t nextFindEntryFn = LOAD32(findVtable + 8);
			callTarget.u64 = nextFindEntryFn;
			ctx.r3.u64 = stream;
			ctx.r4.u64 = nextNameCStr;
			ctx.r5.u64 = nextFindEntryFn;
			ctx.r6.u64 = findVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		} while ((ctx.r3.u32 & 0xFF) != 0);
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return ctx.r3.u32;
}
PROMOTED_ENTRY(34, sub_8256F678, 0x8256F678) { ctx.r3.u64 = CECAppearanceModifierManager_ReadInventoryIndices(ctx, base, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CECAppearanceModifierManager_AddWornItem(CpuState& ctx, uint8_t* base, uint64_t appearanceModifierManagerAddr, uint64_t modifierRefAddr, uint64_t arg3) {
	constexpr int32_t str_TXT_820A9080_B_ = int32_t(0x820A9080);
	constexpr int32_t str_TXT_820BF0E0_B_ = int32_t(0x820BF0E0);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(34, 0x8256F910)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = modifierRefAddr; ctx.r8.u64 = arg3; __imp__sub_8256F910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8256F910);
	uint32_t stack = ctx.r1.u64;
	CECAppearanceModifierManager* appearanceModifierManager = GameObject<CECAppearanceModifierManager>(base, appearanceModifierManagerAddr);
	stack = PushStackFrame(base, stack, 176);

	if (LOAD32((uint32_t)modifierRefAddr) == 0) {
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		// callers read r4 and r8 after the call
		ctx.r4.u64 = modifierRefAddr;
		ctx.r8.u64 = arg3;
		return appearanceModifierManagerAddr;
	}

	ctx.r1.u64 = stack;
	uint64_t result = CECAppearanceModifierManager_GetBodyAreasCovered(ctx, base, appearanceModifierManagerAddr, modifierRefAddr, arg3);
	if (uint32_t((uint64_t)LOAD32((uint32_t)appearanceModifierManagerAddr + 96) & result) != 0) {
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		// callers read r4 after the call: a copy of the result (r8 is as the call left it)
		ctx.r4.u64 = result;
		return result;
	}

	// m_3C is 1 only for the duration of this call.
	uint8_t savedFlag3C = appearanceModifierManager->m_3C;
	appearanceModifierManager->m_3C = uint8_t(1);
	uint32_t modifierWord16 = LOAD32(LOAD32((uint32_t)modifierRefAddr) + 16);
	result = CECAppearanceModifierManager_ApplyModifier(ctx, base, appearanceModifierManagerAddr, result, modifierWord16);
	appearanceModifierManager->m_3C = savedFlag3C;
	if (uint32_t((uint32_t)result & 0xFF) == 0) {
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		return result;
	}

	// Id ref at stack +80: words +4 / +8 of the modifier object, or zero when there is none.
	uint32_t modifier = LOAD32((uint32_t)modifierRefAddr);
	if (modifier != 0) {
		uint32_t secondWord = LOAD32(modifier + 8);
		STORE32(stack + 80, LOAD32(modifier + 4));
		STORE32(stack + 84, secondWord);
	} else {
		STORE32(stack + 80, 0);
		STORE32(stack + 84, 0);
	}

	const uint64_t inventoryItemComponentName = str_TXT_820A9080_B_;
	uint64_t idRef = IdRef_Get(ctx, base, stack + 80);
	// state the callee may pass on
	uint64_t itemComponent = GameDB_ReadU32Field(ctx, base, idRef, inventoryItemComponentName);
	if ((uint32_t)itemComponent != 0) {
		const uint64_t isStyleRemovalName = str_TXT_820BF0E0_B_;
		uint32_t TXT_820BF0E0_L_ = GameDB_ReadBoolField_82303F38(ctx, base, itemComponent, isStyleRemovalName);
		if (uint32_t(TXT_820BF0E0_L_ & 0xFF) == 0) {
			HeroWornItem_Construct(ctx, base, stack + 80, modifierRefAddr);
			const uint64_t wornItemsAddr = appearanceModifierManagerAddr + 12;
			Vector24_PushBack(ctx, base, wornItemsAddr, stack + 80);
			HeroClothing_ClearClothingItems(ctx, base, stack + 80);
			uint64_t wornItemList = Vector24_Back(ctx, base, wornItemsAddr);
			CECAppearanceModifierManager_ApplyWornItem(ctx, base, appearanceModifierManagerAddr, wornItemList);
		}
	}

	STORE32(stack + 80, 0);
	STORE32(stack + 84, 0);
	STORE32(stack + 88, 0);
	STORE32(stack + 92, 0);
	IdRef_Assign(ctx, base, stack + 80, modifierRefAddr);
	result = HeroWornItemHandle_Release(ctx, base, appearanceModifierManagerAddr, stack + 80);
	if (appearanceModifierManager->m_3C != 0) {
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		return result;
	}

	CECAppearanceModifierManager_RefreshClothing(ctx, base, appearanceModifierManagerAddr);
	HeroClothing_CheckClothingAchievements(ctx, base, appearanceModifierManagerAddr);
	CECAppearanceModifierManager_UpdateOpinionEffects(ctx, base, appearanceModifierManagerAddr, ctx.r8.u64);
	CECAppearanceModifierManager_RebuildPropertyMap(ctx, base, appearanceModifierManagerAddr);

	// r6-r9 are threaded through the calls below: the key lookup overwrites some of them and every call hands them on.
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	uint64_t r9Value;

	// Value of key 3 in the owner's sorted {key, value} table at +72 / +76, when bit 3 of owner +36 is set.
	uint32_t owner = appearanceModifierManager->m_4;
	uint32_t key3Object = 0;
	bool haveKey3Object = false;
	r9Value = (LOAD32(owner + 36) >> 3) & 1;
	if ((uint32_t)r9Value != 0) {
		haveKey3Object = true;
		uint32_t indexTable = LOAD32(owner + 140);
		if (indexTable != 0) {
			// byte 3 of the index table is the entry number of key 3
			r9Value = (uint64_t)(LOAD8(indexTable + 3) << 3) + LOAD32(owner + 72);
			key3Object = LOAD32((uint32_t)r9Value + 4);
		} else {
			// lower_bound over the 8-byte entries: first entry whose key is >= 3
			uint32_t begin = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			r6Value = end;
			STORE32(stack + 80, 0);
			int32_t count = (int32_t)(end - begin) >> 3;
			STORE32(stack + 84, begin);
			uint32_t it = begin;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t halfBytes = (uint32_t)half << 3;
					r9Value = (uint64_t)half;
					r8Value = halfBytes;
					it += halfBytes;
					r7Value = ((int32_t)LOAD32(it) < 3) ? 1 : 0;
					if (r7Value != 0) {
						it += 8;
						count = count - half - 1;
					} else {
						it -= halfBytes;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, it);
			}
			if (it != end && (int32_t)LOAD32(it) <= 3) {
				STORE64(stack + 80, LOAD64(stack + 80));
				key3Object = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				key3Object = LOAD32(end + 4);
			}
		}
	}

	if (haveKey3Object) {
		uint32_t oldFlags = LOAD32(key3Object + 144);
		if (uint32_t(oldFlags & 128) == 0) {
			// state the callee may pass on
			ctx.r6.u64 = r6Value;
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = r8Value;
			CECGraphicAppearance_ForEach(ctx, base, key3Object);
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
			r9Value = ctx.r9.u64;
		}
		STORE32(key3Object + 144, LOAD32(key3Object + 144) | 128);
		if (oldFlags == 0) {
			uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t key3ObjectId = LOAD32(key3Object + 4);
			uint32_t globalChild = LOAD32(globalObject + 12);
			uint32_t handleListPtr = LOAD32(LOAD32(globalChild + 88) + 4);
			uint32_t handleList = LOAD32(handleListPtr);
			// state the callee may pass on: r9 holds the list pointer just loaded
			ctx.r6.u64 = r6Value;
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = r8Value;
			EntityHandleList_PushBackEntity(ctx, base, handleList, key3ObjectId);
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
			r9Value = ctx.r9.u64;
		}
	}

	// Virtual call (vtable +64) on the object at owner +124, given the stack +112 buffer that the message below carries.
	uint32_t messageOwner = appearanceModifierManager->m_4;
	uint32_t messageSource = LOAD32(messageOwner + 124);
	uint32_t messageFn = LOAD32(LOAD32(messageSource) + 64);
	PPCRegister callTarget{};
	callTarget.u64 = messageFn;
	ctx.r3.u64 = stack + 112;
	ctx.r4.u64 = messageSource;
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.r9.u64 = r9Value;
	ctx.r10.u64 = messageFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t eventTarget = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4) + 16);
	result = MessageEvents_PostMessageEvent(ctx, base, eventTarget, 47, stack + 112, messageOwner, 0, 101, 0);

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_8256F910, 0x8256F910) { ctx.r3.u64 = CECAppearanceModifierManager_AddWornItem(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CECAppearanceModifierManager_AddModifierByName(CpuState& ctx, uint8_t* base, uint64_t appearanceModifierManagerAddr, uint64_t nameString) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	if (!UseLiftedCode(34, 0x8256FC10)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = nameString; __imp__sub_8256FC10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8256FC10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	uint64_t result = CCharString_NotEqualsEmptyOrLiteral(ctx, base, nameString, g_82000C98);
	if (((uint32_t)result & 0xFF) != 0) {
		result = GameDBRecordRef_Construct(ctx, base, stack + 80, (uint32_t)nameString);
		uint32_t recordId = LOAD32(stack + 80);
		if (recordId != 0) {
			result = CECAppearanceModifierManager_AddModifierById(ctx, base, appearanceModifierManagerAddr, recordId);
		} else {
			// callers read r4 after the call: the zero id
			ctx.r4.u64 = 0;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_8256FC10, 0x8256FC10) { ctx.r3.u64 = CECAppearanceModifierManager_AddModifierByName(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECAppearanceModifierManager_AddModifierById(CpuState& ctx, uint8_t* base, uint64_t managerAddr, uint64_t id) {
	if (!UseLiftedCode(34, 0x8256FC80)) { ctx.r3.u64 = managerAddr; ctx.r4.u64 = id; __imp__sub_8256FC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8256FC80);
	uint32_t stack = ctx.r1.u64;
	CECAppearanceModifierManager* manager = GameObject<CECAppearanceModifierManager>(base, managerAddr);
	// cr0 and the XER flags as they were on entry: handed on, and left for callers on the early returns
	PPCCRRegister cr0Flags = ctx.cr0;
	PPCXERRegister xerFlags = ctx.xer;

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	uint64_t result = IdRef_ConstructFromId(ctx, base, stack + 80, id);

	if (LOAD32(stack + 80) != 0) {
		uint32_t owner = manager->m_4;
		if ((LOAD32(owner + 36) >> 13) & 1) {
			// Value of key 13 in the owner's sorted {key, value} table at +72 / +76.
			uint32_t value;
			uint64_t lookupByteOffset;  // what the lookup leaves in r8; handed on below
			uint32_t indexTable = LOAD32(owner + 140);
			if (indexTable != 0) {
				// byte 13 of the index table is the entry number of key 13
				lookupByteOffset = (uint64_t)(LOAD8(indexTable + 13) << 3) + LOAD32(owner + 72);
				value = LOAD32((uint32_t)lookupByteOffset + 4);
			} else {
				// lower_bound over the 8-byte entries: first entry whose key is >= 13
				uint32_t begin = LOAD32(owner + 72);
				uint32_t end = LOAD32(owner + 76);
				STORE32(stack + 80, 0u);
				lookupByteOffset = (uint64_t)end - begin;
				STORE32(stack + 84, begin);
				int32_t count = (int32_t)(uint32_t)lookupByteOffset >> 3;
				// the count shift sets the carry and cr0, both handed on below
				xerFlags.ca = (int32_t)(uint32_t)lookupByteOffset < 0 && (lookupByteOffset & 0x7) != 0;
				cr0Flags.compare<int32_t>(count, 0, xerFlags);
				uint32_t it = begin;
				if (count > 0) {
					xerFlags.ca = 0;  // the halving shifts below only see positive counts
					do {
						int32_t half = count >> 1;
						lookupByteOffset = (uint32_t)half << 3;
						it += (uint32_t)lookupByteOffset;
						if ((int32_t)LOAD32(it) < 13) {
							it += 8;
							count = count - half - 1;
						} else {
							it -= (uint32_t)lookupByteOffset;
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, it);
				}
				if (it != end && (int32_t)LOAD32(it) <= 13) {
					STORE64(stack + 80, LOAD64(stack + 80));
					value = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					value = LOAD32(end + 4);
				}
			}

			// state the callee may pass on
			ctx.cr0.lt = cr0Flags.lt;
			ctx.cr0.gt = cr0Flags.gt;
			ctx.cr0.eq = cr0Flags.eq;
			ctx.cr0.so = cr0Flags.so;
			ctx.xer.ca = xerFlags.ca;
			result = WeaponSetManager_FindWeaponRecord(ctx, base, stack + 96, value, id);
			if (LOAD32(stack + 96) != 0) {
				CECAppearanceModifierManager_AddWornItem(ctx, base, managerAddr, stack + 96, ctx.r8.u64);
				uint32_t record = LOAD32(stack + 96);
				result = record;
				if (record != 0) {
					result = PtrList_RemoveAll(ctx, base, record, stack + 96);
				}
			}
			// r4, r8, cr0 and the carry stay as the last call left them
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return result;
		}
		// callers read r8 after the call: the clear flag bit
		ctx.r8.u64 = 0;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4, cr0 and the carry after the call: the id and the entry flags
	ctx.r4.u64 = id;
	ctx.cr0.lt = cr0Flags.lt;
	ctx.cr0.gt = cr0Flags.gt;
	ctx.cr0.eq = cr0Flags.eq;
	ctx.cr0.so = cr0Flags.so;
	ctx.xer.ca = xerFlags.ca;
	return result;
}
PROMOTED_ENTRY(34, sub_8256FC80, 0x8256FC80) { ctx.r3.u64 = CECAppearanceModifierManager_AddModifierById(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t HeroWornItems_RemoveItemByKey(CpuState& ctx, uint8_t* base, uint64_t appearanceModifierManagerAddr, uint64_t keyAddr) {
	if (!UseLiftedCode(34, 0x8256FE20)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = keyAddr; __imp__sub_8256FE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8256FE20);
	uint32_t stack = ctx.r1.u64;
	CECAppearanceModifierManager* appearanceModifierManager = GameObject<CECAppearanceModifierManager>(base, appearanceModifierManagerAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	// The vector at +12 holds 24-byte entries from m_10 to m_14; find the first whose two leading words equal the key.
	const uint64_t entriesAddr = appearanceModifierManagerAddr + 12;
	const uint32_t begin = appearanceModifierManager->m_10;
	const uint32_t end = appearanceModifierManager->m_14;
	uint64_t entry = begin;
	uint64_t lastKeyWord = ctx.r6.u64;  // the key word compared last, left in r6

	// The ppc_trap calls are the original's iterator range checks.
	if (begin > end) {
		ppc_trap(ctx, base, 22);
	}
	for (;;) {
		if (begin > end) {
			ppc_trap(ctx, base, 22);
		}
		if ((uint32_t)entry == end) {
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			// callers read r4 and r6-r8 after the call
			ctx.r4.u64 = keyAddr;
			ctx.r6.u64 = lastKeyWord;
			ctx.r7.u64 = begin;
			ctx.r8.u64 = end;
			return appearanceModifierManagerAddr;
		}
		if ((uint32_t)entry >= end) {
			ppc_trap(ctx, base, 22);
		}
		lastKeyWord = LOAD32((uint32_t)keyAddr);
		bool matches = false;
		if (LOAD32((uint32_t)entry) == (uint32_t)lastKeyWord) {
			lastKeyWord = LOAD32((uint32_t)keyAddr + 4);
			matches = LOAD32((uint32_t)entry + 4) == (uint32_t)lastKeyWord;
		}
		if (matches) {
			break;
		}
		if ((uint32_t)entry >= end) {
			ppc_trap(ctx, base, 22);
		}
		entry += 24;
	}

	// Copy the entry to stack +80 and pass it on, then erase it: move the later entries down, destroy the last one, shrink m_14.
	STORE32(stack + 80, 0);
	STORE32(stack + 84, 0);
	STORE32(stack + 88, 0);
	STORE32(stack + 92, 0);
	// state the callee may pass on
	ctx.r6.u64 = lastKeyWord;
	IdRef_Assign(ctx, base, stack + 80, entry);
	HeroWornItemHandle_ReleaseSimple(ctx, base, appearanceModifierManagerAddr, stack + 80);
	if ((uint32_t)entry >= appearanceModifierManager->m_14) {
		ppc_trap(ctx, base, 22);
	}
	AppearanceModifierManager_ReleaseEntryHandle(ctx, base, appearanceModifierManagerAddr, entry);
	Vector24_MoveElements(ctx, base, entry + 24, appearanceModifierManager->m_14, entry);
	uint32_t entriesEnd = appearanceModifierManager->m_14;
	// state the callee may pass on: r3 = the entry vector
	uint64_t result = HeroWornItem_DestroyRange(ctx, base, (uint64_t)entriesEnd - 24, entriesEnd);
	appearanceModifierManager->m_14 = appearanceModifierManager->m_14 - 24;

	if (appearanceModifierManager->m_3C == 0) {
		CECAppearanceModifierManager_RefreshClothing(ctx, base, appearanceModifierManagerAddr);
		HeroClothing_CheckClothingAchievements(ctx, base, appearanceModifierManagerAddr);
		CECAppearanceModifierManager_UpdateOpinionEffects(ctx, base, appearanceModifierManagerAddr, ctx.r8.u64);
		CECAppearanceModifierManager_RebuildPropertyMap(ctx, base, appearanceModifierManagerAddr);

		// Virtual call (vtable +64) on the object at owner +124, given the stack +96 buffer that the message below carries.
		uint32_t owner = appearanceModifierManager->m_4;
		uint32_t messageSource = LOAD32(owner + 124);
		uint32_t messageFn = LOAD32(LOAD32(messageSource) + 64);
		PPCRegister callTarget{};
		callTarget.u64 = messageFn;
		ctx.r3.u64 = stack + 96;
		ctx.r4.u64 = messageSource;
		ctx.r10.u64 = messageFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t eventTarget = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 88) + 4) + 16);
		result = MessageEvents_PostMessageEvent(ctx, base, eventTarget, 47, stack + 96, owner, 0, 101, 0);
	}

	// r4 and r6-r8 stay as the last call left them
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_8256FE20, 0x8256FE20) { ctx.r3.u64 = HeroWornItems_RemoveItemByKey(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t HeroWornItems_RemoveItemById(CpuState& ctx, uint8_t* base, uint64_t appearanceModifierManagerAddr, uint32_t itemId) {
	if (!UseLiftedCode(34, 0x82570000)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = itemId; __imp__sub_82570000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82570000);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	uint32_t wantedIdRefAddr = stack + 88;
	uint64_t result = IdRef_ConstructFromId(ctx, base, wantedIdRefAddr, itemId);

	uint32_t managerAddr = (uint32_t)appearanceModifierManagerAddr;
	uint64_t wornItemList = appearanceModifierManagerAddr + 12;
	uint32_t itemsBegin = LOAD32(managerAddr + 0x10);
	uint32_t itemsEnd = LOAD32(managerAddr + 0x14);
	if (itemsBegin > itemsEnd) {
		ppc_trap(ctx, base, 22);
	}

	// Checked iterator {owning list, position} staged in a stack slot.
	STORE32(stack + 80, (uint32_t)wornItemList);
	STORE32(stack + 84, itemsBegin);
	STORE64(stack + 80, LOAD64(stack + 80));

	uint32_t wantedId = LOAD32(wantedIdRefAddr);
	uint32_t checkedList = LOAD32(stack + 80);
	uint64_t position = LOAD32(stack + 84);

	// The iterator checks run on every pass, including the one that reaches the end.
	while (true) {
		if (itemsBegin > itemsEnd) {
			ppc_trap(ctx, base, 22);
		}
		if (checkedList == 0 || checkedList != (uint32_t)wornItemList) {
			ppc_trap(ctx, base, 22);
		}
		if ((uint32_t)position == itemsEnd) {
			break;
		}
		if (checkedList == 0) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t listEnd = LOAD32(checkedList + 8);
		if ((uint32_t)position >= listEnd) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t node = LOAD32((uint32_t)position);
		uint32_t nodeId = (node != 0) ? LOAD32(node + 4) : 0;
		if (nodeId == wantedId) {
			break;
		}
		if ((uint32_t)position >= listEnd) {
			ppc_trap(ctx, base, 22);
		}
		position += 24;
	}

	// state the callee may pass on; callers read r6-r8 after the call, also when nothing was removed
	ctx.r6.u64 = wantedId;
	ctx.r7.u64 = itemsEnd;
	ctx.r8.u64 = wornItemList;
	if ((uint32_t)position != itemsEnd) {
		result = HeroWornItems_RemoveItemByKey(ctx, base, appearanceModifierManagerAddr, position);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_82570000, 0x82570000) { ctx.r3.u64 = HeroWornItems_RemoveItemById(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint32_t AppearanceModifierManager_CollectMatchingEntries(CpuState& ctx, uint8_t* base, uint32_t appearanceModifierManagerAddr, uint64_t matchesVectorAddr) {
	if (!UseLiftedCode(34, 0x82570C58)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = matchesVectorAddr; __imp__sub_82570C58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82570C58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Vector of 24-byte entries; each entry starts with a pointer to an object.
	uint32_t entryVector = appearanceModifierManagerAddr + 12;
	uint32_t entriesBegin = LOAD32(entryVector + 4);
	uint32_t entriesEnd = LOAD32(entryVector + 8);
	if (entriesBegin > entriesEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	uint32_t result = appearanceModifierManagerAddr;
	uint32_t entry = entriesBegin;
	while (true) {
		uint32_t currentEnd = LOAD32(entryVector + 8);
		if (LOAD32(entryVector + 4) > currentEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (entry == currentEnd) break;
		if (entry >= entriesEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t entryObject = LOAD32(entry);
		result = entryObject;
		if (entryObject != 0) {
			ctx.r1.u64 = stack;
			uint32_t resolved = GameObject_FindComponentByType(ctx, base, entryObject, 2);
			result = resolved;
			if (resolved != 0) {
				// collect the entry's object when either check reports true
				result = (uint32_t)n_sub_826182A0(ctx, base, resolved);
				if ((result & 0xFF) == 0) {
					result = (uint32_t)n_sub_82618320(ctx, base, resolved);
				}
				if ((result & 0xFF) != 0) {
					STORE32(stack + 80, LOAD32(entry));
					result = (uint32_t)Vector_PushBackU32(ctx, base, matchesVectorAddr, stack + 80);
				}
			}
		}

		entriesEnd = LOAD32(entryVector + 8);
		if (entry >= entriesEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		entry += 24;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_82570C58, 0x82570C58) { ctx.r3.u64 = AppearanceModifierManager_CollectMatchingEntries(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t AppearanceModifierManager_HandleMatchesGroup(CpuState& ctx, uint8_t* base, uint64_t handleAddr, uint64_t checkFirstGroup) {
	if (!UseLiftedCode(34, 0x82570D68)) { ctx.r4.u64 = handleAddr; ctx.r5.u64 = checkFirstGroup; __imp__sub_82570D68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82570D68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t handleObject = LOAD32((uint32_t)handleAddr);
	if (handleObject == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		// callers read r4 after the call
		ctx.r4.u64 = handleAddr;
		return 0;
	}

	STORE32(stack + 80, 0u);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r5.u64 = checkFirstGroup;
	uint32_t found = FindType2Component(ctx, base, handleObject, stack + 80);

	// Past this call r4 is left as the callees leave it, which is what callers read.
	uint64_t result = 0;
	if ((found & 0xFF) != 0) {
		uint32_t foundObject = LOAD32(stack + 80);
		result = ((uint32_t)checkFirstGroup & 0xFF) != 0
			? n_sub_826182A0(ctx, base, foundObject)
			: n_sub_82618320(ctx, base, foundObject);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_82570D68, 0x82570D68) { ctx.r3.u64 = AppearanceModifierManager_HandleMatchesGroup(ctx, base, ctx.r4.u64, ctx.r5.u64); }

uint32_t AppearanceModifierManager_CollectInventoryItemEntries(CpuState& ctx, uint8_t* base, uint32_t appearanceModifierManager, uint64_t itemList) {
	constexpr int32_t str_TXT_820A9080_B_ = int32_t(0x820A9080);
	if (!UseLiftedCode(34, 0x82571080)) { ctx.r3.u64 = appearanceModifierManager; ctx.r4.u64 = itemList; __imp__sub_82571080(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82571080);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	// Vector of 24-byte entries; each entry starts with a pointer to an object.
	uint32_t entryVector = appearanceModifierManager + 12;
	uint32_t entriesBegin = LOAD32(appearanceModifierManager + 16);
	uint32_t entriesEnd = LOAD32(appearanceModifierManager + 20);
	if (entriesBegin > entriesEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	uint32_t entry = entriesBegin;
	uint64_t result = appearanceModifierManager;
	const uint64_t fieldName = str_TXT_820A9080_B_;

	while (true) {
		uint32_t currentEnd = LOAD32(entryVector + 8);
		if (LOAD32(entryVector + 4) > currentEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (entry == currentEnd)
			break;
		if (entry >= entriesEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t entryObject = LOAD32(entry);
		if (entryObject != 0) {
			uint32_t idRefAddr = stack + 88;
			STORE32(idRefAddr, LOAD32(entryObject + 4));
			STORE32(idRefAddr + 4, LOAD32(entryObject + 8));
			ctx.r1.u64 = stack;
			uint64_t idRef = IdRef_Get(ctx, base, idRefAddr);
			result = GameDB_ReadU32Field(ctx, base, idRef, fieldName);
			if ((uint32_t)result != 0) {
				STORE32(stack + 80, 0);
				result = GameDB_TryGetCategoryValue(ctx, base, result, stack + 80);
				if (int32_t(LOAD32(stack + 80)) == 12) {
					STORE32(stack + 80, entryObject);
					result = Vector_PushBackU32(ctx, base, itemList, stack + 80);
				}
			}
		}

		entriesEnd = LOAD32(entryVector + 8);
		if (entry >= entriesEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		entry += 24;
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_82571080, 0x82571080) { ctx.r3.u64 = AppearanceModifierManager_CollectInventoryItemEntries(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t AppearanceModifierManager_ReleaseEntryHandle(CpuState& ctx, uint8_t* base, uint32_t manager, uint64_t entryAddr) {
	if (!UseLiftedCode(34, 0x82571470)) { ctx.r3.u64 = manager; ctx.r4.u64 = entryAddr; __imp__sub_82571470(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82571470);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 112);

	uint64_t handleSlot = entryAddr + 16;
	uint32_t handleValue = LOAD32((uint32_t)handleSlot);
	uint32_t result = manager;
	if (handleValue != 0) {
		result = 0;
		uint32_t owner = LOAD32(manager + 4);
		if (((LOAD32(owner + 36) >> 14) & 1) != 0) {
			uint32_t value = 0;
			uint32_t indexSlot = LOAD32(owner + 140);
			if (indexSlot != 0) {
				// The pair address is a 64-bit sum; the original hands it on in r8.
				uint64_t pairAddr = (uint64_t)(LOAD8(indexSlot + 14) << 3) + (uint64_t)LOAD32(owner + 72);
				value = LOAD32((uint32_t)pairAddr + 4);
				ctx.r8.u64 = pairAddr;
			} else {
				// Lower bound of key 14 in the sorted 8-byte {int32 key, value} pairs.
				uint32_t begin = LOAD32(owner + 72);
				uint32_t end = LOAD32(owner + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, begin);
				uint32_t byteSpan = end - begin;
				int32_t remaining = (int32_t)byteSpan >> 3;
				// state the callee may pass on: r6, cr0 and xer.ca as the count computation leaves them
				ctx.r6.u64 = end;
				ctx.xer.ca = (int32_t)byteSpan < 0 && (byteSpan & 7) != 0;
				ctx.cr0.compare<int32_t>(remaining, 0, ctx.xer);
				uint32_t entry = begin;
				if (remaining > 0) {
					bool below = false;
					uint32_t halfBytes = 0;
					do {
						int32_t half = remaining >> 1;
						halfBytes = (uint32_t)half << 3;
						uint32_t mid = entry + halfBytes;
						below = (int32_t)LOAD32(mid) < 14;
						if (below) {
							entry = mid + 8;
							remaining = remaining - half - 1;
						} else {
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 84, entry);
					// state the callee may pass on: r7/r8 as the last search step leaves them
					ctx.r7.u64 = below ? 1 : 0;
					ctx.r8.u64 = halfBytes;
				}
				if (entry != end && (int32_t)LOAD32(entry) <= 14) {
					// the original stores the search pair back unchanged
					STORE64(stack + 80, LOAD64(stack + 80));
					value = LOAD32(entry + 4);
				} else {
					value = LOAD32(end + 4);
				}
			}
			ctx.r1.u64 = stack;
			n_sub_82628F28(ctx, base, value, handleValue);
			result = (uint32_t)SharedHandle_Release(ctx, base, handleSlot);
			STORE32((uint32_t)handleSlot, 0);
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(34, sub_82571470, 0x82571470) { ctx.r3.u64 = AppearanceModifierManager_ReleaseEntryHandle(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CECAppearanceModifierManager_GetBodyAreasCovered(CpuState& ctx, uint8_t* base, uint32_t appearanceModifierManagerAddr, uint32_t modifierRefAddr, uint64_t forwardedR8) {
	constexpr int32_t str_TXT_820A94F0_B_ = int32_t(0x820A94F0);
	constexpr int32_t str_TXT_820B3F5C_B_ = int32_t(0x820B3F5C);
	constexpr int32_t str_TXT_820BF180_B_ = int32_t(0x820BF180);
	if (!UseLiftedCode(34, 0x82571B60)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = modifierRefAddr; ctx.r8.u64 = forwardedR8; __imp__sub_82571B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82571B60);
	uint32_t stack = ctx.r1.u64;

	stack = PushStackFrame(base, stack, 128);

	// Build the id-ref key from the referenced object, or an all-zero key if there is none.
	uint32_t keySource = LOAD32(modifierRefAddr);
	if (keySource != 0) {
		STORE32(stack + 80, LOAD32(keySource + 4));
		STORE32(stack + 84, LOAD32(keySource + 8));
	} else {
		STORE32(stack + 80, 0);
		STORE32(stack + 84, 0);
	}
	uint64_t keyAddr = (uint64_t)stack + 80;

	ctx.r1.u64 = stack;
	// state the callees may pass on
	uint64_t idRef = IdRef_Get(ctx, base, keyAddr);

	uint64_t appearanceModifier = GameDB_ReadU32Field(ctx, base, idRef, str_TXT_820A94F0_B_);
	if ((uint32_t)appearanceModifier == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	// The last argument is whatever r8 holds at each call, as in the original.
	uint64_t TXT_820B3F5C_L_ = GameDB_ReadMappedU32FieldByName(ctx, base, appearanceModifier, str_TXT_820B3F5C_B_, ctx.r8.u64);
	if (((uint32_t)TXT_820B3F5C_L_ & 2048) != 0 && LOAD8(appearanceModifierManagerAddr + 61) != 0) {
		uint64_t TXT_820BF180_L_ = GameDB_ReadMappedU32FieldByName(ctx, base, appearanceModifier, str_TXT_820BF180_B_, ctx.r8.u64);
		if ((uint32_t)TXT_820BF180_L_ != 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return TXT_820BF180_L_;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return TXT_820B3F5C_L_;
}
PROMOTED_ENTRY(34, sub_82571B60, 0x82571B60) { ctx.r3.u64 = CECAppearanceModifierManager_GetBodyAreasCovered(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r8.u64); }

uint32_t AppearanceModifierManager_AdjustModifierValue(CpuState& ctx, uint8_t* base, uint64_t manager, uint32_t modifierId, double deltaValue) {
	if (!UseLiftedCode(35, 0x82572AF8)) { ctx.r3.u64 = manager; ctx.r4.u64 = modifierId; ctx.f1.f64 = deltaValue; __imp__sub_82572AF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82572AF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	constexpr uint32_t kEntryListBegin  = 48;          // CECAppearanceModifierManager list head (m_30)
	constexpr uint32_t kEntryListEnd    = 52;          // CECAppearanceModifierManager list tail (m_34)
	constexpr uint32_t kSelectTableAddr = 0x82100170u; // {+1.0f, -1.0f} markers used by the branchless selects
	constexpr uint32_t kClampLowerAddr  = 0x8209DE04u;
	constexpr uint32_t kClampUpperAddr  = 0x820994C0u;
	constexpr uint32_t kZeroAddr        = 0x820994B4u; // 0.0f: start value of a new entry and the compare reference

	// Look up the { id, value } entry belonging to modifierId.
	uint32_t entry = LOAD32((uint32_t)manager + kEntryListBegin);
	const uint32_t entryEnd = LOAD32((uint32_t)manager + kEntryListEnd);
	while (entry != entryEnd && LOAD32(entry) != modifierId)
		entry += 8;

	if (entry == entryEnd) {
		// Unknown modifier: register a fresh entry holding 0.0.
		STORE32(stack + 80, modifierId);
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 84, LOAD_F32(kZeroAddr));
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.f1.f64 = deltaValue;
		const uint32_t insertResult = Vector_PushBackPair(ctx, base, manager + 44, (uint64_t)(stack + 80));
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return insertResult;
	}

	// Accumulate the delta and clamp the result into the allowed range.
	ctx.fpscr.disableFlushMode();
	const float oldValue = LOAD_F32(entry + 4);
	const float newValue = (float)((double)oldValue + deltaValue);
	STORE_F32(entry + 4, newValue);

	const double clampLower = LOAD_F32(kClampLowerAddr);
	const double clampUpper = LOAD_F32(kClampUpperAddr);
	const double zero = LOAD_F32(kZeroAddr);

	PPCCRRegister cr{};
	cr.compare((double)(float)((double)newValue - clampLower), zero);
	const uint32_t unorderedFlag = cr.so ? 4u : 0u;
	uint32_t selectIndex = unorderedFlag | (cr.lt ? 4u : 0u);
	const double lowerClamped = LOAD_F32(kSelectTableAddr + selectIndex) >= 0.0f ? (double)newValue : clampLower;

	cr.compare((double)(float)(lowerClamped - clampUpper), zero);
	const uint32_t lessFlag = cr.lt ? 4u : 0u;
	selectIndex = lessFlag | (cr.so ? 4u : 0u);
	const double upperClamped = LOAD_F32(kSelectTableAddr + selectIndex) >= 0.0f ? clampUpper : lowerClamped;

	STORE_F32(entry + 4, (float)upperClamped);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r5, r8 and f1 after the call
	ctx.r5.u64 = selectIndex;
	ctx.r8.u64 = lessFlag;
	ctx.f1.f64 = deltaValue;
	return unorderedFlag;
}
PROMOTED_ENTRY(35, sub_82572AF8, 0x82572AF8) { ctx.r3.u64 = AppearanceModifierManager_AdjustModifierValue(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.f1.f64); }

uint64_t AppearanceModifierManager_RemoveByRecordName(CpuState& ctx, uint8_t* base, uint64_t appearanceModifierManagerAddr, uint32_t recordNameAddr) {
	if (!UseLiftedCode(35, 0x82574F38)) { ctx.r3.u64 = appearanceModifierManagerAddr; ctx.r4.u64 = recordNameAddr; __imp__sub_82574F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82574F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// Look the record up by its name (a CCharString); the reference's first word is the record id, 0 if none.
	uint32_t recordRef = stack + 80;
	ctx.r1.u64 = stack;
	GameDBRecordRef_Construct(ctx, base, recordRef, recordNameAddr);
	uint32_t recordId = LOAD32(recordRef);
	uint64_t result = 0;
	if (recordId != 0) {
		result = AppearanceModifierManager_RemoveEntryByRecordId(ctx, base, appearanceModifierManagerAddr, recordId);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = recordId;
	return result;
}
PROMOTED_ENTRY(35, sub_82574F38, 0x82574F38) { ctx.r3.u64 = AppearanceModifierManager_RemoveByRecordName(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// Walks the 24-byte entries of the vector at +12 and appends the 16-byte elements of the object that
// GameObject_FindComponentByType finds for each entry (type 1) to outList. Returns the last value the original left in r3.
uint32_t AppearanceModifierManager_CollectEntryElements(CpuState& ctx, uint8_t* base, uint32_t manager, uint64_t outList) {
	if (!UseLiftedCode(35, 0x82575268)) { ctx.r3.u64 = manager; ctx.r4.u64 = outList; __imp__sub_82575268(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82575268);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	uint32_t listStart = LOAD32(manager + 16);
	uint32_t listEnd = LOAD32(manager + 20);
	uint32_t list = manager + 12;
	if (listStart > listEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	uint32_t cursor = listStart;
	uint32_t result = manager;
	for (;;) {
		uint32_t currentEnd = LOAD32(list + 8);
		if (LOAD32(list + 4) > currentEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (cursor == currentEnd) break;
		if (cursor >= listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t entry = LOAD32(cursor);
		result = entry;
		if (entry != 0) {
			ctx.r1.u64 = stack;
			result = GameObject_FindComponentByType(ctx, base, entry, 1);
			if (result != 0) {
				uint32_t source = result;
				uint32_t srcEnd = LOAD32(source + 12);
				uint32_t srcBegin = LOAD32(source + 8);
				uint64_t dstBytes = (uint64_t)LOAD32((uint32_t)outList + 8) - (uint64_t)LOAD32((uint32_t)outList + 4);
				uint64_t srcBytes = (uint64_t)srcEnd - (uint64_t)srcBegin;
				uint64_t newCount = (uint64_t)(int64_t)((int32_t)dstBytes >> 4) + (uint64_t)(int64_t)((int32_t)srcBytes >> 4);

				// state the callee may pass on
				ctx.r5.u64 = srcBytes;
				ctx.r6.u64 = dstBytes;
				ctx.r7.u64 = srcBegin;
				ctx.xer.ca = ((int32_t)srcBytes < 0) & (((uint32_t)srcBytes & 0xF) != 0);
				// reserve room for both ranges (srcEnd goes in r8)
				result = Vector16_Reserve(ctx, base, outList, newCount, srcEnd);

				// the original builds the begin iterator on the stack and reads the pointer back from the copy
				uint32_t first = LOAD32(source + 8);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, first);
				STORE64(stack + 88, LOAD64(stack + 80));
				uint32_t last = LOAD32(source + 12);
				if (first != last) {
					uint32_t it = LOAD32(stack + 92);
					do {
						result = Vector16_PushBack(ctx, base, outList, it);
						it += 16;
					} while (it != last);
				}
			}
		}

		listEnd = LOAD32(list + 8);
		if (cursor >= listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		cursor += 24;
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(35, sub_82575268, 0x82575268) { ctx.r3.u64 = AppearanceModifierManager_CollectEntryElements(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CECAppearanceModifierManager_RebuildPropertyMap(CpuState& ctx, uint8_t* base, uint64_t appearanceModifierManagerAddr) {
	constexpr int32_t str_TXT_82000EB4_B_ = int32_t(0x82000EB4);
	if (!UseLiftedCode(35, 0x82575398)) { ctx.r3.u64 = appearanceModifierManagerAddr; __imp__sub_82575398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82575398);
	uint32_t stack = ctx.r1.u64;
	CECAppearanceModifierManager* appearanceModifierManager = GameObject<CECAppearanceModifierManager>(base, appearanceModifierManagerAddr);

	stack = PushStackFrame(base, stack, 192);
	uint32_t gathered = stack + 112;        // vector of 16-byte elements filled by AppearanceModifierManager_CollectEntryElements
	uint32_t fieldValue = stack + 80;
	uint32_t fieldCopy = stack + 84;
	uint32_t insertResult = stack + 88;
	STORE32(gathered + 4, 0);
	STORE32(gathered + 8, 0);
	STORE32(gathered + 12, 0);
	ctx.r1.u64 = stack;
	AppearanceModifierManager_CollectEntryElements(ctx, base, appearanceModifierManagerAddr, gathered);

	uint64_t propertyMap = appearanceModifierManagerAddr + 108;
	uint32_t root = LOAD32((uint32_t)appearanceModifierManager->m_70 + 4);
	uint64_t result = PropertyMap_EraseSubtree(ctx, base, propertyMap, root);

	// Empty the map: its header node (m_70) links back to itself and its size (m_74) becomes 0. The header
	// pointer is re-read after each store, as in the original; the three reads are what r8, r7 and r6 carry.
	uint64_t reg8 = appearanceModifierManager->m_70;
	uint32_t listBegin = LOAD32(gathered + 4);
	uint32_t listByteSize = LOAD32(gathered + 8) - listBegin;
	STORE32((uint32_t)reg8 + 4, (uint32_t)reg8);
	uint64_t reg7 = appearanceModifierManager->m_70;
	appearanceModifierManager->m_74 = 0;
	STORE32((uint32_t)reg7, (uint32_t)reg7);
	uint64_t reg6 = appearanceModifierManager->m_70;
	STORE32((uint32_t)reg6 + 8, (uint32_t)reg6);

	// the XER carry as the original leaves it; IdRef_Get, HandleTarget_Free and the callers get it
	uint8_t carry = ((int32_t)listByteSize < 0) & ((listByteSize & 0xF) != 0);
	uint32_t elementCount = (int32_t)listByteSize >> 4;
	const uint64_t typeName = str_TXT_82000EB4_B_;
	if (elementCount != 0) {
		// each element holds two 8-byte references, at +0 and +8
		uint32_t remaining = elementCount;
		uint32_t secondRefAddr = listBegin + 8;
		do {
			uint32_t firstRefAddr = secondRefAddr - 8;
			uint32_t firstRef = LOAD32(firstRefAddr);
			STORE32(fieldValue, 0);
			if (firstRef != 0) {
				// state the callees may pass on
				ctx.xer.ca = carry;
				uint64_t record = IdRef_Get(ctx, base, firstRefAddr);
				result = GameDB_TryGetTypeField(ctx, base, record, fieldValue);
				reg6 = ctx.r6.u64;
				reg7 = ctx.r7.u64;
				reg8 = ctx.r8.u64;
				if (LOAD32(fieldValue) != 0) {
					STORE32(fieldValue, GameDB_GetTypeForIdRef(ctx, base, firstRefAddr));
					result = Map_InsertUnique(ctx, base, insertResult, propertyMap, fieldValue, ctx.r8.u64);
					reg6 = ctx.r6.u64;
					reg7 = ctx.r7.u64;
					reg8 = ctx.r8.u64;
					carry = ctx.xer.ca;
				}
			}

			uint32_t secondRef = LOAD32(secondRefAddr);
			STORE32(fieldValue, 0);
			if (secondRef != 0) {
				// state the callees may pass on
				ctx.xer.ca = carry;
				uint64_t record = IdRef_Get(ctx, base, secondRefAddr);
				result = GameDB_TryGetTypeField(ctx, base, record, fieldValue);
				reg6 = ctx.r6.u64;
				reg7 = ctx.r7.u64;
				reg8 = ctx.r8.u64;
				if (LOAD32(fieldValue) != 0) {
					STORE32(fieldValue, 0);
					uint64_t recordAgain = IdRef_Get(ctx, base, secondRefAddr);
					GameDB_TryGetTypeField(ctx, base, recordAgain, fieldValue);
					STORE32(fieldCopy, LOAD32(fieldValue));
					// the result slot is the gathered vector's header; its begin was read above
					result = Map_InsertUnique(ctx, base, gathered, propertyMap, fieldCopy, ctx.r8.u64);
					reg6 = ctx.r6.u64;
					reg7 = ctx.r7.u64;
					reg8 = ctx.r8.u64;
				}
			}

			carry = remaining != 0;      // carry out of the counter decrement
			remaining = remaining - 1;
			secondRefAddr = secondRefAddr + 16;
		} while (remaining != 0);
	}

	if (listBegin != 0) {
		// state the callee may pass on
		ctx.xer.ca = carry;
		result = HandleTarget_Free(ctx, base, listBegin);
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
		carry = ctx.xer.ca;
	}
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	// callers read r6-r8 and the carry after the call
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = carry;
	return result;
}
PROMOTED_ENTRY(35, sub_82575398, 0x82575398) { ctx.r3.u64 = CECAppearanceModifierManager_RebuildPropertyMap(ctx, base, ctx.r3.u64); }

// sub_82576140  [496 bytes]
// When the global message queue has bytes +52 and +53 set and the wornItemHandle's target has a nonzero word at +4,
// queues a message carrying that word, then up to two more built from the target's type-2 object (each
// gated by AppearanceModifierManager_HandleMatchesGroup). The wornItemHandle is then removed from its target's pointer list (if any) and cleared.
uint64_t HeroWornItemHandle_Release(CpuState& ctx, uint8_t* base, uint64_t managerAddr, uint64_t wornItemHandle) {
	constexpr int32_t g_820A2BB8 = int32_t(0x820A2BB8);
	constexpr int32_t g_820A4964 = int32_t(0x820A4964);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(35, 0x82576140)) { ctx.r3.u64 = managerAddr; ctx.r4.u64 = wornItemHandle; __imp__sub_82576140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82576140);
	uint32_t stack = ctx.r1.u64;
	CECAppearanceModifierManager* appearanceModifierManager = GameObject<CECAppearanceModifierManager>(base, managerAddr);
	stack = PushStackFrame(base, stack, 224);

	uint32_t handleAddr = uint32_t(wornItemHandle);
	uint32_t globalBase = uint32_t(g_83490000);
	uint32_t queueOwner = LOAD32(LOAD32(globalBase + 26912) + 12);
	uint32_t messageQueue = LOAD32(queueOwner + 140);
	bool queueEnabled = LOAD8(messageQueue + 52) != 0 && LOAD8(messageQueue + 53) != 0;

	uint64_t result = managerAddr;
	uint64_t r4ForCallers = wornItemHandle;     // r4 at the return: the wornItemHandle, or what the later calls leave in r4
	bool targetWasNull = false;
	if (queueEnabled) {
		uint32_t target = LOAD32(handleAddr);
		if (target == 0) {
			targetWasNull = true;
		} else {
			uint32_t targetWord = LOAD32(target + 4);
			if (targetWord != 0) {
				// message object at stack+88: vtable, then the target's word
				STORE32(stack + 92, targetWord);
				uint32_t ownerEntity = appearanceModifierManager->m_4;
				STORE32(stack + 88, 0x820A4958u);
				uint32_t queueA = LOAD32(queueOwner + 140);
				ctx.r1.u64 = stack;
				uint64_t uniqueId = Entity_GetUniqueId(ctx, base, ownerEntity);
				MessageQueue_PostMessage(ctx, base, uint64_t(queueA), stack + 88, uniqueId);

				// each message object gets its vtable before the send and the base vtable after it
				uint32_t messageVtable = uint32_t(g_820A4964);
				uint32_t baseVtable = uint32_t(g_820A2BB8);

				ctx.r3.u64 = uint32_t(managerAddr);     // state the callee may pass on
				uint32_t firstCheck = AppearanceModifierManager_HandleMatchesGroup(ctx, base, wornItemHandle, 0);
				uint64_t partCheckResult = firstCheck & 0xFF;      // r8 handed from call to call below
				if (partCheckResult != 0) {
					STORE32(stack + 80, 0);
					uint32_t firstTarget = LOAD32(handleAddr);
					ctx.r8.u64 = partCheckResult;
					uint32_t found = FindType2Component(ctx, base, firstTarget, stack + 80);
					partCheckResult = ctx.r8.u64;
					if ((found & 0xFF) != 0) {
						uint32_t source = LOAD32(stack + 80);
						STORE32(stack + 96, messageVtable);
						STORE32(stack + 100, targetWord);
						uint32_t ownerEntity2 = appearanceModifierManager->m_4;
						uint8_t b13 = LOAD8(source + 13);
						uint8_t b12 = LOAD8(source + 12);
						uint8_t b14 = LOAD8(source + 14);
						STORE8(stack + 104, b14);
						STORE8(stack + 105, b13);
						STORE8(stack + 106, b12);
						ctx.fpscr.disableFlushMode();
						double sourceValue = double(LOAD_F32(source + 16));
						STORE_F32(stack + 108, float(sourceValue));
						STORE8(stack + 112, 0);
						uint32_t queueOwnerB = LOAD32(LOAD32(globalBase + 26912) + 12);
						uint32_t queueB = LOAD32(queueOwnerB + 140);
						// state the callees may pass on
						uint64_t uniqueId2 = Entity_GetUniqueId(ctx, base, ownerEntity2);
						n_sub_82577A88(ctx, base, uint64_t(queueB), stack + 96, uniqueId2);
						partCheckResult = ctx.r8.u64;
						STORE32(stack + 96, baseVtable);
					}
				}

				// state the callee may pass on
				ctx.r8.u64 = partCheckResult;
				uint32_t secondCheck = AppearanceModifierManager_HandleMatchesGroup(ctx, base, wornItemHandle, 1);
				r4ForCallers = ctx.r4.u64;
				if ((secondCheck & 0xFF) != 0) {
					STORE32(stack + 80, 0);
					uint32_t secondTarget = LOAD32(handleAddr);
					uint32_t found2 = FindType2Component(ctx, base, secondTarget, stack + 80);
					r4ForCallers = ctx.r4.u64;
					if ((found2 & 0xFF) != 0) {
						STORE32(stack + 128, messageVtable);
						uint32_t source2 = LOAD32(stack + 80);
						STORE32(stack + 132, targetWord);
						uint32_t globalRoot = LOAD32(globalBase + 26912);
						uint32_t ownerEntity3 = appearanceModifierManager->m_4;
						uint8_t b4 = LOAD8(source2 + 4);
						uint8_t b6 = LOAD8(source2 + 6);
						uint8_t b5 = LOAD8(source2 + 5);
						STORE8(stack + 136, b6);
						STORE8(stack + 137, b5);
						STORE8(stack + 138, b4);
						ctx.fpscr.disableFlushMode();
						double sourceValue2 = double(LOAD_F32(source2 + 8));
						STORE8(stack + 144, 1);
						STORE_F32(stack + 140, float(sourceValue2));
						uint32_t queueC = LOAD32(LOAD32(globalRoot + 12) + 140);
						// state the callees may pass on
						uint64_t uniqueId3 = Entity_GetUniqueId(ctx, base, ownerEntity3);
						n_sub_82577A88(ctx, base, uint64_t(queueC), stack + 128, uniqueId3);
						r4ForCallers = ctx.r4.u64;
						STORE32(stack + 128, baseVtable);
					}
				}
				STORE32(stack + 88, baseVtable);
			}
		}
	}
	if (!targetWasNull) {
		uint32_t target = LOAD32(handleAddr);
		result = target;
		if (target != 0) {
			ctx.r1.u64 = stack;
			result = PtrList_RemoveAll(ctx, base, target, wornItemHandle);
			r4ForCallers = ctx.r4.u64;
		}
	}
	STORE32(handleAddr, 0);
	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCallers;     // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(35, sub_82576140, 0x82576140) { ctx.r3.u64 = HeroWornItemHandle_Release(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// When the global message queue has bytes +52 and +53 set and the wornItemHandle's target has a nonzero word at +4,
// queues a message carrying that word. The wornItemHandle is then removed from its target's pointer list (if any)
// and cleared.
uint32_t HeroWornItemHandle_ReleaseSimple(CpuState& ctx, uint8_t* base, uint64_t managerAddr, uint64_t wornItemHandle) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_820A4970 = int32_t(0x820A4970);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(35, 0x82576960)) { ctx.r3.u64 = managerAddr; ctx.r4.u64 = wornItemHandle; __imp__sub_82576960(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82576960);
	uint32_t stack = ctx.r1.u64;
	// r6/r7 go on to PtrList_RemoveAll and back to the callers
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	stack = PushStackFrame(base, stack, 128);

	uint32_t queueOwner = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t messageQueue = LOAD32(queueOwner + 140);
	bool queueEnabled = LOAD8(messageQueue + 52) != 0 && LOAD8(messageQueue + 53) != 0;

	uint32_t result = (uint32_t)managerAddr;
	bool targetWasNull = false;
	if (queueEnabled) {
		uint32_t target = LOAD32((uint32_t)wornItemHandle);
		if (target == 0) {
			targetWasNull = true;
		} else {
			uint32_t targetWord = LOAD32(target + 4);
			if (targetWord != 0) {
				// message object at stack+80: vtable, then the target's word
				STORE32(stack + 84, targetWord);
				uint32_t ownerEntity = LOAD32((uint32_t)managerAddr + 4);
				uint64_t messageVtable = g_820A4970;
				STORE32(stack + 80, (uint32_t)messageVtable);
				uint32_t queue = LOAD32(queueOwner + 140);
				ctx.r1.u64 = stack;
				ctx.r8.u64 = messageVtable;     // state the callee may pass on
				uint64_t uniqueId = Entity_GetUniqueId(ctx, base, ownerEntity);
				MessageQueue_PostMessage(ctx, base, queue, stack + 80, uniqueId);
				// after the send the message gets the base vtable g_820A2BB8, built in r6 from r7
				reg7 = g_820A0000;
				reg6 = reg7 + 0x2BB8;
				STORE32(stack + 80, (uint32_t)reg6);
			}
		}
	}
	if (!targetWasNull) {
		uint32_t target = LOAD32((uint32_t)wornItemHandle);
		result = target;
		if (target != 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			result = PtrList_RemoveAll(ctx, base, target, wornItemHandle);
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
		}
	}
	STORE32((uint32_t)wornItemHandle, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r6/r7 after the call
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	return result;
}
PROMOTED_ENTRY(35, sub_82576960, 0x82576960) { ctx.r3.u64 = HeroWornItemHandle_ReleaseSimple(ctx, base, ctx.r3.u64, ctx.r4.u64); }
