// CGiftReward (vtable 0x82002320): methods of the class as readable C++.
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

uint64_t CGiftReward_IsMoneyGift(CpuState& ctx, uint8_t* base, uint64_t giftRewardAddr) {
	if (!UseLiftedCode(27, 0x8248D4B0)) { ctx.r3.u64 = giftRewardAddr; __imp__sub_8248D4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8248D4B0);
	return GameObject<CGiftReward>(base, giftRewardAddr)->m_isMoneyGift;
}
PROMOTED_ENTRY(27, sub_8248D4B0, 0x8248D4B0) { ctx.r3.u64 = CGiftReward_IsMoneyGift(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82787B98(CpuState& ctx, uint8_t* base, uint64_t giftReward) {
	if (!UseLiftedCode(52, 0x82787B98)) { ctx.r3.u64 = giftReward; __imp__sub_82787B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82787B98);
	return LOAD8((uint32_t)giftReward + 15);
}
PROMOTED_ENTRY(52, sub_82787B98, 0x82787B98) { ctx.r3.u64 = n_sub_82787B98(ctx, base, ctx.r3.u64); }

uint32_t CGiftReward_ConstructBase(CpuState& ctx, uint8_t* base, uint64_t giftRewardAddr, uint64_t ownerEntity, uint64_t rewardDefinition) {
	constexpr int32_t str_TXT_820C389C_B_ = int32_t(0x820C389C);
	constexpr int32_t str_TXT_820D5C08_B_ = int32_t(0x820D5C08);
	constexpr int32_t str_TXT_820D5C18_B_ = int32_t(0x820D5C18);
	constexpr int32_t str_TXT_820D5C3C_B_ = int32_t(0x820D5C3C);
	constexpr int32_t str_TXT_820D5C54_B_ = int32_t(0x820D5C54);
	constexpr int32_t giftRewardBase_vtable = int32_t(0x820D5DE8);
	constexpr int32_t EntityHandle_vtable = int32_t(0x820F1664);
	constexpr uint32_t floatZero_address = 0x820994B4u;
	if (!UseLiftedCode(53, 0x827AD1E0)) { ctx.r3.u64 = giftRewardAddr; ctx.r4.u64 = ownerEntity; ctx.r5.u64 = rewardDefinition; __imp__sub_827AD1E0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827AD1E0);
	GameStackFrame stackFrame(ctx, base, 128);
	CGiftReward* giftReward = GameObject<CGiftReward>(base, giftRewardAddr);
	const double defaultOpinionStrength = double(LOAD_F32(floatZero_address));

	giftReward->m_targetOpinionStrength = float(defaultOpinionStrength);
	giftReward->m_opinionAxis = 0;
	giftReward->vtable = (uint32_t)giftRewardBase_vtable;
	giftReward->m_C = 1;
	giftReward->m_D = 0;
	giftReward->m_E = 0;
	giftReward->m_F = 1;
	giftReward->m_10 = 0;
	// an empty EntityHandle at +20, then pointed at the owner
	giftReward->m_14 = (uint32_t)EntityHandle_vtable;
	giftReward->m_18 = 0;
	ctx.r5.u64 = rewardDefinition;
	ctx.r8.u64 = (int64_t)giftRewardBase_vtable;
	EntityHandle_SetTarget(ctx, base, giftRewardAddr + 20, ownerEntity);

	if ((uint32_t)rewardDefinition == 0) {
		ctx.fpscr.disableFlushMode();
		giftReward->m_targetOpinionStrength = float(defaultOpinionStrength);
		giftReward->m_opinionAxis = 0;
		giftReward->m_C = 1;
		giftReward->m_E = 1;
		return (uint32_t)giftRewardAddr;
	}

	uint32_t isRandomRewardFlag = (uint32_t)GameDB_ReadBoolField_82303F38(ctx, base, rewardDefinition, str_TXT_820D5C08_B_);
	giftReward->m_F = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, rewardDefinition, str_TXT_820D5C18_B_);
	if ((isRandomRewardFlag & 0xFF) != 0) {
		CGiftReward_ParseRandomRewardAxes(ctx, base, (uint32_t)giftRewardAddr, rewardDefinition);
		return (uint32_t)giftRewardAddr;
	}

	giftReward->m_opinionAxis = (uint32_t)GameDB_GetIntByName(ctx, base, rewardDefinition, str_TXT_820C389C_B_);
	GameDB_GetFloatByName(ctx, base, rewardDefinition, str_TXT_820D5C3C_B_);
	ctx.fpscr.disableFlushMode();
	giftReward->m_targetOpinionStrength = float(ctx.f1.f64);
	giftReward->m_C = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, rewardDefinition, str_TXT_820D5C54_B_);
	return (uint32_t)giftRewardAddr;
}
PROMOTED_ENTRY(53, sub_827AD1E0, 0x827AD1E0) { ctx.r3.u64 = CGiftReward_ConstructBase(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CGiftReward_SerializeBase(CpuState& ctx, uint8_t* base, uint64_t giftRewardAddr, uint64_t serializer, uint64_t derivedSerializeArg3, uint64_t derivedSerializeArg4) {
	constexpr int32_t emptyCString = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820D5C6C_B_ = int32_t(0x820D5C6C);
	constexpr int32_t str_TXT_820D5C74_B_ = int32_t(0x820D5C74);
	constexpr int32_t str_TXT_820D5C84_B_ = int32_t(0x820D5C84);
	constexpr int32_t str_TXT_820D5C90_B_ = int32_t(0x820D5C90);
	constexpr int32_t str_TXT_820D5C98_B_ = int32_t(0x820D5C98);
	constexpr int32_t str_TXT_820D5CA8_B_ = int32_t(0x820D5CA8);
	if (!UseLiftedCode(53, 0x827AD728)) { ctx.r3.u64 = giftRewardAddr; ctx.r4.u64 = serializer; ctx.r5.u64 = derivedSerializeArg3; ctx.r6.u64 = derivedSerializeArg4; __imp__sub_827AD728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827AD728);
	uint32_t stack = ctx.r1.u64;
	CGiftReward* giftReward = GameObject<CGiftReward>(base, giftRewardAddr);
	stack = PushStackFrame(base, stack, 144);
	const uint32_t fieldName = stack + 80;   // CCharString holding the name of the field being serialized
	const uint32_t axisValue = stack + 84;
	// The value serializers take the name's text with them: the first word of the string's data, or the
	// sign-extended address of an empty C string when the string has no data.
	auto fieldNameText = [&]() -> uint64_t {
		uint32_t nameData = LOAD32(fieldName);
		if (nameData != 0) {
			return LOAD32(nameData);
		}
		return uint64_t(int64_t(emptyCString));
	};

	ctx.r1.u64 = stack;
	ctx.r6.u64 = derivedSerializeArg4;
	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820D5C6C_B_, -1);
	STORE32(axisValue, uint32_t(giftReward->m_opinionAxis));
	ctx.r4.u64 = fieldNameText();
	IStream_SerializeU32(ctx, base, serializer, axisValue);
	giftReward->m_opinionAxis = LOAD32(axisValue);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820D5C74_B_, -1);
	ctx.r4.u64 = fieldNameText();
	IStream_SerializeFloat(ctx, base, serializer, giftRewardAddr + 8);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820D5C84_B_, -1);
	IStream_SerializeString(ctx, base, fieldName, serializer, giftRewardAddr + 12);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820D5C90_B_, -1);
	IStream_SerializeString(ctx, base, fieldName, serializer, giftRewardAddr + 13);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820D5C98_B_, -1);
	IStream_SerializeString(ctx, base, fieldName, serializer, giftRewardAddr + 14);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820D5CA8_B_, -1);
	ctx.r4.u64 = fieldNameText();
	IStream_SerializeU32(ctx, base, serializer, giftRewardAddr + 16);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	// the derived class serializes its own part (vtable slot 6)
	uint32_t vtable = giftReward->vtable;
	uint32_t serializeMethod = LOAD32(vtable + 24);
	ctx.r3.u64 = giftRewardAddr;
	ctx.r4.u64 = serializer;
	ctx.r5.u64 = derivedSerializeArg3;
	ctx.r6.u64 = derivedSerializeArg4;
	ctx.r10.u64 = serializeMethod;
	REX_CALL_INDIRECT_FUNC(serializeMethod);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(53, sub_827AD728, 0x827AD728) { ctx.r3.u64 = CGiftReward_SerializeBase(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint32_t CGiftReward_ParseRandomRewardAxes(CpuState& ctx, uint8_t* base, uint32_t giftRewardAddr, uint64_t rewardDefinition) {
	constexpr int32_t str_TXT_8200262C_B_ = int32_t(0x8200262C);
	constexpr int32_t str_TXT_820A89C4_B_ = int32_t(0x820A89C4);
	constexpr int32_t str_TXT_820A8AD4_B_ = int32_t(0x820A8AD4);
	constexpr int32_t str_TXT_820A8AE4_B_ = int32_t(0x820A8AE4);
	constexpr int32_t str_TXT_820A8AEC_B_ = int32_t(0x820A8AEC);
	constexpr int32_t str_TXT_820A8AF8_B_ = int32_t(0x820A8AF8);
	constexpr int32_t str_TXT_820CAA54_B_ = int32_t(0x820CAA54);
	constexpr int32_t str_TXT_820D1774_B_ = int32_t(0x820D1774);
	constexpr int32_t str_TXT_820D2DF4_B_ = int32_t(0x820D2DF4);
	constexpr int32_t str_TXT_820D5CB4_B_ = int32_t(0x820D5CB4);
	constexpr int32_t str_TXT_820D5CC8_B_ = int32_t(0x820D5CC8);
	constexpr int32_t str_TXT_820D5CD4_B_ = int32_t(0x820D5CD4);
	constexpr int32_t str_TXT_820D5CF4_B_ = int32_t(0x820D5CF4);
	constexpr uint32_t globalRoot_address = 0x83496920u;
	if (!UseLiftedCode(53, 0x827AD8D0)) { ctx.r3.u64 = giftRewardAddr; ctx.r4.u64 = rewardDefinition; __imp__sub_827AD8D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827AD8D0);
	uint32_t stack = ctx.r1.u64;
	CGiftReward* giftReward = GameObject<CGiftReward>(base, giftRewardAddr);
	// the float the function leaves for its caller: the caller's own when there are no random axes
	double floatResult = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 176);
	// a vector of (axis, positive) candidates at +96 (begin at +100, end at +104), filled through a record at +80
	const uint32_t candidates = stack + 96;
	const uint32_t candidate = stack + 80;
	STORE32(stack + 108, 0);
	STORE32(stack + 100, 0);
	STORE32(stack + 104, 0);

	ctx.r1.u64 = stack;
	uint64_t result = GameDB_ReadU32Field(ctx, base, rewardDefinition, str_TXT_820D5CB4_B_);
	const uint64_t randomAxesNode = result;
	if ((uint32_t)randomAxesNode != 0) {
		// each axis has two names: the positive one and the negative one
		struct AxisPole { int32_t name; uint32_t TXT_820D5C6C_L_; uint8_t positive; };
		const AxisPole poles[] = {
			{str_TXT_8200262C_B_, 0, 1}, {str_TXT_820A8AE4_B_, 0, 0}, {str_TXT_820A89C4_B_, 1, 1}, {str_TXT_820A8AD4_B_, 1, 0}, {str_TXT_820A8AEC_B_, 2, 1},
			{str_TXT_820A8AF8_B_, 2, 0}, {str_TXT_820D2DF4_B_, 3, 1}, {str_TXT_820CAA54_B_, 3, 0}, {str_TXT_820D5CC8_B_, 4, 1}, {str_TXT_820D1774_B_, 4, 0},
		};
		for (const AxisPole& pole : poles) {
			if ((GameDB_ReadBoolField_82303F38(ctx, base, randomAxesNode, pole.name) & 0xFF) != 0) {
				STORE32(candidate, pole.TXT_820D5C6C_L_);
				STORE8(candidate + 4, pole.positive);
				Vector_PushBackPair(ctx, base, candidates, candidate);
			}
		}

		uint32_t candidateAxisArray = LOAD32(stack + 100);
		uint32_t candidateBytes = LOAD32(stack + 104) - candidateAxisArray;
		int32_t candidateAxisCount = (int32_t)candidateBytes >> 3;

		// advance the random state at +120 of the object the global root leads to
		uint32_t globalRoot = LOAD32(globalRoot_address);
		uint32_t rngOwner = LOAD32(LOAD32(LOAD32(globalRoot + 12) + 88) + 4);
		uint32_t rngStateAddr = rngOwner + 120;
		uint32_t rngState = __builtin_rotateleft32(LOAD32(rngStateAddr) * 9377u + 9439u, 19);
		STORE32(rngStateAddr, rngState);

		uint32_t pick = 0;
		if (candidateAxisCount != 0) {
			pick = rngState % (uint32_t)candidateAxisCount;
		}
		uint32_t chosen = candidateAxisArray + (pick << 3);
		giftReward->m_opinionAxis = LOAD32(chosen);
		giftReward->m_C = LOAD8(chosen + 4);

		GameDB_GetFloatByName(ctx, base, rewardDefinition, str_TXT_820D5CD4_B_);
		double minOpinionStrength = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		result = GameDB_GetFloatByName(ctx, base, rewardDefinition, str_TXT_820D5CF4_B_);
		double maxOpinionStrength = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		double strengthRange = double(float(maxOpinionStrength - minOpinionStrength));
		floatResult = Rng_NextScaledFloat(ctx, base, rngStateAddr, strengthRange);

		// the target strength is negative for the negative name of the axis
		uint8_t positive = giftReward->m_C;
		ctx.fpscr.disableFlushMode();
		double targetStrength = double(float(floatResult + minOpinionStrength));
		giftReward->m_targetOpinionStrength = float(targetStrength);
		if (positive == 0) {
			giftReward->m_targetOpinionStrength = float(-targetStrength);
		}

		if (candidateAxisArray != 0) {
			ctx.f1.f64 = floatResult;
			result = HandleTarget_Free(ctx, base, candidateAxisArray);
			floatResult = ctx.f1.f64;
		}
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = floatResult;
	return (uint32_t)result;
}
PROMOTED_ENTRY(53, sub_827AD8D0, 0x827AD8D0) { ctx.r3.u64 = CGiftReward_ParseRandomRewardAxes(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CGiftReward_Construct(CpuState& ctx, uint8_t* base, uint64_t giftRewardAddr, uint64_t ownerEntity, uint64_t rewardDefinition) {
	constexpr int32_t str_TXT_820A8D64_B_ = int32_t(0x820A8D64);
	constexpr int32_t str_TXT_820D5C08_B_ = int32_t(0x820D5C08);
	constexpr int32_t str_TXT_820D5D14_B_ = int32_t(0x820D5D14);
	constexpr int32_t str_TXT_820D5D20_B_ = int32_t(0x820D5D20);
	constexpr uint32_t CGiftReward_vtable = 0x82002320u;
	constexpr int32_t fnvOffsetBasis = int32_t(0x811C9DC5u);
	if (!UseLiftedCode(53, 0x827ADBD8)) { ctx.r3.u64 = giftRewardAddr; ctx.r4.u64 = ownerEntity; ctx.r5.u64 = rewardDefinition; __imp__sub_827ADBD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827ADBD8);
	GameStackFrame stackFrame(ctx, base, 112);
	CGiftReward* giftReward = GameObject<CGiftReward>(base, giftRewardAddr);
	CGiftReward_ConstructBase(ctx, base, giftRewardAddr, ownerEntity, rewardDefinition);
	giftReward->m_giftItemId = 0;
	giftReward->m_moneyAmount = 0;
	giftReward->vtable = CGiftReward_vtable;
	giftReward->m_isMoneyGift = 1;

	if ((uint32_t)rewardDefinition == 0) {
		giftReward->m_isMoneyGift = 1;
		giftReward->m_moneyAmount = 1;
		return giftRewardAddr;
	}

	uint32_t isRandomRewardFlag = (uint32_t)GameDB_ReadBoolField_82303F38(ctx, base, rewardDefinition, str_TXT_820D5C08_B_);
	if ((isRandomRewardFlag & 0xFF) != 0) {
		CGiftReward_ChooseRandomGift(ctx, base, giftRewardAddr, rewardDefinition);
		return giftRewardAddr;
	}

	uint32_t moneyGiftFlag = (uint32_t)GameDB_ReadBoolField_82303F38(ctx, base, rewardDefinition, str_TXT_820D5D14_B_);
	giftReward->m_isMoneyGift = (uint8_t)moneyGiftFlag;
	if ((moneyGiftFlag & 0xFF) != 0) {
		giftReward->m_moneyAmount = (uint32_t)GameDB_GetIntByName(ctx, base, rewardDefinition, str_TXT_820A8D64_B_);
		return giftRewardAddr;
	}

	// the item id is the value of the type-6 field whose name hashes (FNV-1) like str_TXT_820D5D20_B_
	uint64_t itemFieldHash = String_HashFnv1(ctx, base, str_TXT_820D5D20_B_, uint64_t(int64_t(fnvOffsetBasis)));
	uint32_t itemIdValue = (uint32_t)GameDB_FindFieldValue(ctx, base, rewardDefinition, itemFieldHash, 6);
	if (itemIdValue != 0) {
		giftReward->m_giftItemId = LOAD32(itemIdValue);
	} else {
		giftReward->m_giftItemId = 0;
	}
	return giftRewardAddr;
}
PROMOTED_ENTRY(53, sub_827ADBD8, 0x827ADBD8) { ctx.r3.u64 = CGiftReward_Construct(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CGiftReward_Apply(CpuState& ctx, uint8_t* base, uint64_t giftRewardAddr, uint64_t receivingEntity, uint64_t forwardedValue) {
	constexpr uint32_t gameGlobal_address = 0x834968A4u;
	if (!UseLiftedCode(53, 0x827ADCF8)) { ctx.r3.u64 = giftRewardAddr; ctx.r4.u64 = receivingEntity; ctx.r8.u64 = forwardedValue; __imp__sub_827ADCF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827ADCF8);
	uint32_t stack = ctx.r1.u64;
	CGiftReward* giftReward = GameObject<CGiftReward>(base, giftRewardAddr);
	const uint32_t entity = (uint32_t)receivingEntity;
	// The component lookups' working values, which the original leaves in registers for the calls that follow and
	// which are handed over as it leaves them: the search's last comparison, its last step in bytes and its last
	// step (the presence bit when it makes no step; a lookup through the slot table leaves the slot and its entry).
	uint64_t lookupLess = ctx.r7.u64;
	uint64_t lookupOffset = forwardedValue;
	uint64_t lookupStep = 0;
	stack = PushStackFrame(base, stack, 112);

	// Lower bound of componentType in the entity's sorted (type id, component) array between +72 and +76, its
	// position kept at stack+84: the component of the matching entry, else the end entry's.
	auto searchComponent = [&](int32_t componentType) -> uint32_t {
		uint32_t entry = LOAD32(entity + 72);
		uint32_t end = LOAD32(entity + 76);
		STORE32(stack + 80, 0);
		STORE32(stack + 84, entry);
		int32_t count = (int32_t)(end - entry) >> 3;
		if (count > 0) {
			while (count > 0) {
				int32_t step = count >> 1;
				lookupStep = (uint64_t)(int64_t)step;
				lookupOffset = (uint32_t)step << 3;
				entry += (uint32_t)lookupOffset;
				lookupLess = (int32_t)LOAD32(entry) < componentType ? 1 : 0;
				if (lookupLess != 0) {
					entry += 8;
					count = count - step - 1;
				} else {
					entry -= (uint32_t)lookupOffset;
					count = step;
				}
			}
			STORE32(stack + 84, entry);
		}
		if (entry != end && (int32_t)LOAD32(entry) <= componentType) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	uint64_t result = giftRewardAddr;
	uint64_t secondResult = 0;   // left for the caller with the result
	if (giftReward->m_isMoneyGift != 0) {
		result = 0;
		uint32_t hasComponent81 = (LOAD32(entity + 44) >> 17) & 1;
		if (hasComponent81 != 0) {
			lookupStep = hasComponent81;
			uint32_t playerComponent;
			uint32_t slotTable = LOAD32(entity + 140);
			if (slotTable != 0) {
				lookupStep = ((uint64_t)LOAD8(slotTable + 81) << 3) + LOAD32(entity + 72);
				playerComponent = LOAD32((uint32_t)lookupStep + 4);
			} else {
				playerComponent = searchComponent(81);
			}
			ctx.r1.u64 = stack;
			ctx.r8.u64 = lookupOffset;
			ctx.r9.u64 = lookupStep;
			Player_ModifyMoney(ctx, base, playerComponent, giftReward->m_moneyAmount, 0, 1, 0);
			uint32_t gameGlobal = LOAD32(gameGlobal_address);
			uint32_t gui = LOAD32(LOAD32(gameGlobal + 28) + 48);
			result = GUI_ShowReceivedMoneyMessage(ctx, base, gui, giftReward->m_moneyAmount);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return result;
		}
	} else {
		uint32_t hasComponent13 = (LOAD32(entity + 36) >> 13) & 1;
		if (hasComponent13 != 0) {
			lookupStep = hasComponent13;
			uint32_t inventoryComponent;
			uint32_t slotTable = LOAD32(entity + 140);
			if (slotTable != 0) {
				uint32_t slot = LOAD8(slotTable + 13);
				lookupStep = slot;
				lookupOffset = ((uint64_t)slot << 3) + LOAD32(entity + 72);
				inventoryComponent = LOAD32((uint32_t)lookupOffset + 4);
			} else {
				inventoryComponent = searchComponent(13);
			}
			const uint32_t addResult = stack + 80;   // record Inventory_AddItem fills in
			ctx.r1.u64 = stack;
			ctx.r7.u64 = lookupLess;
			ctx.r8.u64 = lookupOffset;
			ctx.r9.u64 = lookupStep;
			result = Inventory_AddItem(ctx, base, addResult, inventoryComponent, giftReward->m_giftItemId, 1);
			secondResult = ctx.r4.u64;
			if (LOAD32(addResult) != 0) {
				uint32_t gameGlobal = LOAD32(gameGlobal_address);
				uint32_t gui = LOAD32(LOAD32(gameGlobal + 28) + 48);
				GUI_ShowReceivedItemMessage(ctx, base, gui, addResult, ctx.r8.u64);
				secondResult = ctx.r4.u64;
				result = LOAD32(addResult);
				if ((uint32_t)result != 0) {
					result = PtrList_RemoveAll(ctx, base, result, addResult);
					secondResult = ctx.r4.u64;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(53, sub_827ADCF8, 0x827ADCF8) { ctx.r3.u64 = CGiftReward_Apply(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CGiftReward_Serialize(CpuState& ctx, uint8_t* base, uint64_t giftRewardAddr, uint64_t serializer) {
	constexpr int32_t emptyCString = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820A8D64_B_ = int32_t(0x820A8D64);
	constexpr int32_t str_TXT_820AD524_B_ = int32_t(0x820AD524);
	constexpr int32_t str_TXT_820D5D14_B_ = int32_t(0x820D5D14);
	if (!UseLiftedCode(53, 0x827ADFE0)) { ctx.r3.u64 = giftRewardAddr; ctx.r4.u64 = serializer; __imp__sub_827ADFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827ADFE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	const uint32_t fieldName = stack + 80;   // CCharString holding the name of the field being serialized
	// The value serializers take the name's text with them: the first word of the string's data, or the
	// sign-extended address of an empty C string when the string has no data.
	auto fieldNameText = [&]() -> uint64_t {
		uint32_t nameData = LOAD32(fieldName);
		if (nameData != 0) {
			return LOAD32(nameData);
		}
		return uint64_t(int64_t(emptyCString));
	};

	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820AD524_B_, -1);
	ctx.r4.u64 = fieldNameText();
	IStream_SerializeId(ctx, base, serializer, giftRewardAddr + 28);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820A8D64_B_, -1);
	ctx.r4.u64 = fieldNameText();
	IStream_SerializeU32(ctx, base, serializer, giftRewardAddr + 32);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	CCharString_ConstructFromCStr(ctx, base, fieldName, str_TXT_820D5D14_B_, -1);
	IStream_SerializeString(ctx, base, fieldName, serializer, giftRewardAddr + 36);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldName);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(53, sub_827ADFE0, 0x827ADFE0) { ctx.r3.u64 = CGiftReward_Serialize(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CGiftReward_SetupIconGraphic(CpuState& ctx, uint8_t* base, uint64_t resultAddr, uint64_t giftRewardAddr) {
	constexpr int32_t str_TXT_820ADE60_B_ = int32_t(0x820ADE60);
	constexpr int32_t str_TXT_820AEE30_B_ = int32_t(0x820AEE30);
	constexpr int32_t str_TXT_820A9080_B_ = int32_t(0x820A9080);
	constexpr uint32_t moneyGiftGraphic_address = 0x8349B528u;
	if (!UseLiftedCode(53, 0x827AE0A8)) { ctx.r3.u64 = resultAddr; ctx.r4.u64 = giftRewardAddr; __imp__sub_827AE0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827AE0A8);
	// The graphic is returned through the record at resultAddr (one word); the gift reward is the second argument.
	uint32_t stack = ctx.r1.u64;
	CGiftReward* giftReward = GameObject<CGiftReward>(base, giftRewardAddr);
	stack = PushStackFrame(base, stack, 128);

	if (giftReward->m_isMoneyGift != 0) {
		STORE32(resultAddr, LOAD32(moneyGiftGraphic_address));
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = giftRewardAddr;
		return resultAddr;
	}

	const uint32_t itemRef = stack + 80;   // IdRef of the gift item, then a CCharString
	uint64_t itemId = giftReward->m_giftItemId;
	uint64_t secondResult = itemId;   // left for the caller with the result
	uint32_t TXT_820AEE30_L_ = 0;
	ctx.r1.u64 = stack;
	IdRef_ConstructFromId(ctx, base, itemRef, (uint32_t)itemId);
	if (LOAD32(itemRef) != 0) {
		ctx.r4.u64 = itemId;
		uint64_t itemDefinition = IdRef_Get(ctx, base, itemRef);
		uint64_t itemComponentRecord = GameDB_ReadU32Field(ctx, base, itemDefinition, str_TXT_820A9080_B_);
		secondResult = ctx.r4.u64;
		if ((uint32_t)itemComponentRecord != 0) {
			uint32_t graphicProperty = (uint32_t)GameDB_GetPropertyByName(ctx, base, itemRef, itemComponentRecord, str_TXT_820AEE30_B_);
			secondResult = ctx.r4.u64;
			TXT_820AEE30_L_ = LOAD32(graphicProperty);
			if (TXT_820AEE30_L_ == 0) {
				uint64_t stringField = GameDB_GetStringField(ctx, base, itemComponentRecord, str_TXT_820ADE60_B_);
				CCharString_ConstructFromCStr(ctx, base, itemRef, stringField, -1);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, itemRef);
				secondResult = ctx.r4.u64;
			}
		}
	}

	STORE32(resultAddr, TXT_820AEE30_L_);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return resultAddr;
}
PROMOTED_ENTRY(53, sub_827AE0A8, 0x827AE0A8) { ctx.r3.u64 = CGiftReward_SetupIconGraphic(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t EntityHandleHolder_GetEntity(CpuState& ctx, uint8_t* base, uint64_t handleHolder) {
	if (!UseLiftedCode(68, 0x8298D8E0)) { ctx.r3.u64 = handleHolder; __imp__sub_8298D8E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8298D8E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t handleAddr = handleHolder + 20;
	uint32_t controlBlock = GameObject<EntityHandle>(base, handleAddr)->m_4;
	if (controlBlock == 0) {
		return 0;
	}
	uint32_t entity = LOAD32(controlBlock);
	ctx.r10.u64 = entity;
	if (entity != 0) {
		return entity;
	}
	// the control block no longer points at an entity: release the handle
	EntityHandle_Release(ctx, base, handleAddr);
	return 0;
}
PROMOTED_ENTRY(68, sub_8298D8E0, 0x8298D8E0) { ctx.r3.u64 = EntityHandleHolder_GetEntity(ctx, base, ctx.r3.u64); }
