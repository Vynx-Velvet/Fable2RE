// CECTargetingDog (vtable 0x82007490): methods of the class as readable C++.
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

uint64_t n_sub_821A3158(CpuState& ctx, uint8_t* base, uint64_t targetingDogAddr) {
	if (!UseLiftedCode(1, 0x821A3158)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_821A3158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821A3158);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	uint32_t targetFunction = LOAD32(uint32_t(targetingDog->vtable) + 140);
	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)targetFunction;
	ctx.r3.u64 = targetingDogAddr;
	ctx.r10.u64 = targetFunction;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(1, sub_821A3158, 0x821A3158) { ctx.r3.u64 = n_sub_821A3158(ctx, base, ctx.r3.u64); }


// sub_821D8228  [20 bytes]
// The object is the second argument; the first is the 16-byte slot that receives the vector
// (a 16-byte store at the object's own start would overwrite its vtable).
void CECTargetingDog_SetVectorFromObject(CpuState& ctx, uint8_t* base, uint32_t outVectorAddr, uint32_t targetingDogAddr) {
	if (!UseLiftedCode(3, 0x821D8228)) { ctx.r3.u64 = outVectorAddr; ctx.r4.u64 = targetingDogAddr; __imp__sub_821D8228(ctx, base); return; }
	LiftedFrame frame(0x821D8228);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	// Copies the 16-byte vector at offset 32 of the m_C object.
	uint32_t targetInfoAddr = targetingDog->m_C;
	PPCVRegister vector{};
	SET_V8(vector, VLOAD((targetInfoAddr + 32u) & ~0xFu));
	VSTORE(outVectorAddr & ~0xFu, V8(vector));
	return;
}
PROMOTED_ENTRY(3, sub_821D8228, 0x821D8228) { CECTargetingDog_SetVectorFromObject(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CECTargetingDog_GetTarget(CpuState& ctx, uint8_t* base, uint32_t targetingDogAddr) {
	if (!UseLiftedCode(4, 0x821E62B0)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_821E62B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E62B0);
	uint32_t stack = ctx.r1.u64;
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	stack = PushStackFrame(base, stack, 96);
	// The m_C object holds an entity handle at +0x18; the handle's second word points to the slot
	// that holds the entity.
	uint32_t targetInfoAddr = targetingDog->m_C;
	uint64_t handleAddr = uint64_t(targetInfoAddr) + 0x18;
	uint32_t targetSlot = LOAD32(targetInfoAddr + 0x1C);
	if (targetSlot != 0) {
		uint32_t target = LOAD32(targetSlot);
		if (target != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return target;
		}
		// The slot is empty: the handle is released.
		ctx.r1.u64 = stack;
		ctx.r10.u64 = target;   // state the callee may pass on
		EntityHandle_Release(ctx, base, handleAddr);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(4, sub_821E62B0, 0x821E62B0) { ctx.r3.u64 = CECTargetingDog_GetTarget(ctx, base, ctx.r3.u32); }

uint64_t CECTargetingDog_CallTargetInfoMethod(CpuState& ctx, uint8_t* base, uint64_t targetingDogAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(11, 0x82299978)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_82299978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82299978);

	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	uint32_t targetInfo = targetingDog->m_C;
	uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t globalField = LOAD32(globalObject + 12);
	uint32_t targetInfoVtable = LOAD32(targetInfo);
	uint32_t virtualMethod = LOAD32(targetInfoVtable);
	uint32_t subObject = LOAD32(globalField + 88);
	uint32_t subObjectEntry = LOAD32(subObject + 4);
	uint32_t callArgument = LOAD32(subObjectEntry + 12);

	// Calls the first virtual method of the m_C object with (m_C, this, callArgument).
	PPCRegister callTarget{};
	callTarget.u64 = virtualMethod;
	ctx.r3.u64 = targetInfo;
	ctx.r4.u64 = targetingDogAddr;
	ctx.r5.u64 = callArgument;
	// state the callee may pass on
	ctx.r6.u64 = subObject;
	ctx.r7.u64 = virtualMethod;
	ctx.r8.u64 = globalField;
	ctx.r9.u64 = targetInfoVtable;
	ctx.r10.u64 = targetInfo;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(11, sub_82299978, 0x82299978) { ctx.r3.u64 = CECTargetingDog_CallTargetInfoMethod(ctx, base, ctx.r3.u64); }

// sub_82436330  [8 bytes]
uint64_t n_sub_82436330(CpuState& ctx, uint8_t* base, uint64_t targetingDogAddr) {
	if (!UseLiftedCode(24, 0x82436330)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_82436330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82436330);
	return GameObject<CECTargetingDog>(base, targetingDogAddr)->m_1D;
}
PROMOTED_ENTRY(24, sub_82436330, 0x82436330) { ctx.r3.u64 = n_sub_82436330(ctx, base, ctx.r3.u64); }

// sub_82788E48 = Lua_Player_SetWearingCondom (Lua Player.SetWearingCondom)  [8 bytes]
void Lua_Player_SetWearingCondom(CpuState& ctx, uint8_t* base, uint32_t targetingDogAddr, uint32_t isWearingCondom) {
	if (!UseLiftedCode(52, 0x82788E48)) { ctx.r3.u64 = targetingDogAddr; ctx.r4.u64 = isWearingCondom; __imp__sub_82788E48(ctx, base); return; }
	LiftedFrame frame(0x82788E48);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	targetingDog->m_1C = (uint8_t)isWearingCondom;
	return;
}
PROMOTED_ENTRY(52, sub_82788E48, 0x82788E48) { Lua_Player_SetWearingCondom(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CECTargetingDog_GetClassName(CpuState& ctx, uint8_t* base, uint64_t result) {
	constexpr int32_t str_TXT_820C8A04_B_ = int32_t(0x820C8A04);
	if (!UseLiftedCode(66, 0x82956390)) { ctx.r3.u64 = result; __imp__sub_82956390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82956390);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, result, uint64_t(str_TXT_820C8A04_B_), -1);
	return result;
}
PROMOTED_ENTRY(66, sub_82956390, 0x82956390) { ctx.r3.u64 = CECTargetingDog_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_829565F0(CpuState& ctx, uint8_t* base, uint64_t targetingDogAddr) {
	if (!UseLiftedCode(67, 0x829565F0)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_829565F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829565F0);
	uint32_t stack = ctx.r1.u64;
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);

	stack = PushStackFrame(base, stack, 112);
	uint32_t entity = targetingDog->m_pEntity;
	ctx.r1.u64 = stack;
	uint64_t result = CECDoor_UpdateOpenStateForEntity(ctx, base, entity, targetingDogAddr);

	entity = targetingDog->m_pEntity;
	if ((LOAD32(entity + 40) >> 12) & 1) {
		const int32_t key = 44;
		uint32_t entry = 0;
		uint32_t slotDesc = LOAD32(entity + 140);
		if (slotDesc != 0) {
			uint32_t slotIndex = LOAD8(slotDesc + 44);
			uint32_t tableBegin = LOAD32(entity + 72);
			entry = LOAD32(tableBegin + slotIndex * 8 + 4);
		} else {
			uint32_t tableBegin = LOAD32(entity + 72);
			uint32_t tableEnd = LOAD32(entity + 76);
			STORE32(stack + 80, 0u);
			STORE32(stack + 84, tableBegin);
			uint32_t it = tableBegin;
			int32_t remaining = (int32_t)(tableEnd - tableBegin) >> 3;
			if (remaining > 0) {
				do {
					int32_t half = remaining >> 1;
					uint32_t middle = it + (half << 3);
					if ((int32_t)LOAD32(middle) < key) {
						it = middle + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, it);
			}
			if (it != tableEnd && (int32_t)LOAD32(it) <= key) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entry = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry = LOAD32(tableEnd + 4);
			}
		}
		STORE32(entry + 80, LOAD32(entry + 80) | 6);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_829565F0, 0x829565F0) { ctx.r3.u64 = n_sub_829565F0(ctx, base, ctx.r3.u64); }


// sub_82986148  [20 bytes]
// Copies the 16-byte value at m_C + 48 (the one CECTargetingDog_SetTargetInfoVector48 stores) into the caller's result buffer.
void n_sub_82986148(CpuState& ctx, uint8_t* base, uint32_t resultAddr, uint32_t targetingDogAddr) {
	if (!UseLiftedCode(68, 0x82986148)) { ctx.r3.u64 = resultAddr; ctx.r4.u64 = targetingDogAddr; __imp__sub_82986148(ctx, base); return; }
	LiftedFrame frame(0x82986148);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	PPCVRegister value{};
	SET_V8(value, VLOAD((uint32_t(targetingDog->m_C) + 48u) & ~0xF));
	VSTORE(resultAddr & ~0xF, V8(value));
	return;
}
PROMOTED_ENTRY(68, sub_82986148, 0x82986148) { n_sub_82986148(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82986160(CpuState& ctx, uint8_t* base, uint32_t targetingDogAddr) {
	if (!UseLiftedCode(68, 0x82986160)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_82986160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82986160);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	return LOAD32(targetingDog->m_C + 64);
}
PROMOTED_ENTRY(68, sub_82986160, 0x82986160) { ctx.r3.u64 = n_sub_82986160(ctx, base, ctx.r3.u32); }


// TargetInfo_Reset resets the entity handle at m_C + 24 and zeroes the vector at m_C + 32.
uint64_t CECTargetingDog_ResetTargetInfo(CpuState& ctx, uint8_t* base, uint64_t targetingDogAddr) {
	if (!UseLiftedCode(68, 0x82986170)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_82986170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82986170);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	return TargetInfo_Reset(ctx, base, uint32_t(targetingDog->m_C));
}
PROMOTED_ENTRY(68, sub_82986170, 0x82986170) { ctx.r3.u64 = CECTargetingDog_ResetTargetInfo(ctx, base, ctx.r3.u64); }

uint64_t CECTargetingDog_SetTargetEntity(CpuState& ctx, uint8_t* base, uint32_t targetingDogAddr, uint64_t targetEntity) {
	if (!UseLiftedCode(68, 0x82986178)) { ctx.r3.u64 = targetingDogAddr; ctx.r4.u64 = targetEntity; __imp__sub_82986178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82986178);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	uint64_t targetHandleAddr = (uint64_t)targetingDog->m_C + 24;
	return EntityHandle_SetTarget(ctx, base, targetHandleAddr, targetEntity);
}
PROMOTED_ENTRY(68, sub_82986178, 0x82986178) { ctx.r3.u64 = CECTargetingDog_SetTargetEntity(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_82986188  [16 bytes]
void CECTargetingDog_SetTargetInfoVector32(CpuState& ctx, uint8_t* base, uint32_t targetingDogAddr) {
	if (!UseLiftedCode(68, 0x82986188)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_82986188(ctx, base); return; }
	LiftedFrame frame(0x82986188);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	uint32_t storeAddr = (uint32_t(targetingDog->m_C) + 32u) & ~0xFu;
	VSTORE(storeAddr, V8(ctx.v1));
	return;
}
PROMOTED_ENTRY(68, sub_82986188, 0x82986188) { CECTargetingDog_SetTargetInfoVector32(ctx, base, ctx.r3.u32); }

// sub_82986198  [16 bytes]
void CECTargetingDog_SetTargetInfoVector48(CpuState& ctx, uint8_t* base, uint32_t targetingDogAddr) {
	if (!UseLiftedCode(68, 0x82986198)) { ctx.r3.u64 = targetingDogAddr; __imp__sub_82986198(ctx, base); return; }
	LiftedFrame frame(0x82986198);
	PPCVRegister valueToStore = ctx.v1;
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	uint32_t storeAddress = (uint32_t(targetingDog->m_C) + 48u) & ~0xFu;
	VSTORE(storeAddress, V8(valueToStore));
	return;
}
PROMOTED_ENTRY(68, sub_82986198, 0x82986198) { CECTargetingDog_SetTargetInfoVector48(ctx, base, ctx.r3.u32); }

// sub_829862A8  [12 bytes]
void n_sub_829862A8(CpuState& ctx, uint8_t* base, uint32_t targetingDogAddr, uint32_t targetValue) {
	if (!UseLiftedCode(68, 0x829862A8)) { ctx.r3.u64 = targetingDogAddr; ctx.r4.u64 = targetValue; __imp__sub_829862A8(ctx, base); return; }
	LiftedFrame frame(0x829862A8);
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	STORE32(uint32_t(targetingDog->m_C) + 64, targetValue);
	return;
}
PROMOTED_ENTRY(68, sub_829862A8, 0x829862A8) { n_sub_829862A8(ctx, base, ctx.r3.u32, ctx.r4.u32); }


// Writes Quat_MultiplyAndReturn of the rotation reported by the dog entity's component into the caller's
// result buffer and returns that buffer.
uint64_t CECTargetingDog_GetRotation(CpuState& ctx, uint8_t* base, uint64_t resultAddr, uint32_t targetingDogAddr) {
	if (!UseLiftedCode(68, 0x829862B8)) { ctx.r3.u64 = resultAddr; ctx.r4.u64 = targetingDogAddr; __imp__sub_829862B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829862B8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	stack = PushStackFrame(base, stack, 112);

	// The component at +0x7C of the entity returns the rotation through a result buffer (virtual +0x44).
	uint64_t rotationBuffer = (uint64_t)stack + 80;
	uint32_t component = LOAD32(uint32_t(targetingDog->m_pEntity) + 124);
	uint32_t componentVtable = LOAD32(component);
	uint32_t getRotationFn = LOAD32(componentVtable + 68);

	// state the callee may pass on
	callTarget.u64 = (uint64_t)getRotationFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = rotationBuffer;
	ctx.r4.u64 = component;
	ctx.r9.u64 = getRotationFn;
	ctx.r10.u64 = componentVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t rotationAddr = ctx.r3.u32;
	uint64_t rotationFirstHalf = LOAD64(rotationAddr);
	uint64_t rotationSecondHalf = LOAD64(rotationAddr + 8);
	Quat_MultiplyAndReturn(ctx, base, rotationFirstHalf, rotationSecondHalf);

	// the result comes back in v1
	VSTORE((uint32_t)resultAddr & ~0xF, V8(ctx.v1));

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return resultAddr;
}
PROMOTED_ENTRY(68, sub_829862B8, 0x829862B8) { ctx.r3.u64 = CECTargetingDog_GetRotation(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// sub_82986318  [136 bytes]
uint64_t CECTargetingDog_SetTargetingFlag(CpuState& ctx, uint8_t* base, uint64_t targetingDogAddr, uint64_t targetingFlag) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(68, 0x82986318)) { ctx.r3.u64 = targetingDogAddr; ctx.r4.u64 = targetingFlag; __imp__sub_82986318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82986318);
	uint32_t stack = ctx.r1.u64;
	CECTargetingDog* targetingDog = GameObject<CECTargetingDog>(base, targetingDogAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t manager = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t messageQueue = LOAD32(manager + 140);

	uint64_t result = targetingDogAddr;
	uint64_t callerR4 = targetingFlag;
	if (LOAD8(messageQueue + 0x34) != 0 && LOAD8(messageQueue + 0x35) != 0) {
		// message object on the stack: vtable at +80, targetingFlag byte at +84
		STORE8(stack + 84, (uint8_t)targetingFlag);
		uint32_t entity = targetingDog->m_pEntity;
		STORE32(stack + 80, 0x820A4760u);
		ctx.r1.u64 = stack;
		uint64_t uniqueId = Entity_GetUniqueId(ctx, base, entity);
		result = Entity_PostFlagMessage(ctx, base, messageQueue, (uint64_t)(stack + 80), uniqueId);
		callerR4 = ctx.r4.u64;
	}
	targetingDog->m_1D = (uint8_t)targetingFlag;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(68, sub_82986318, 0x82986318) { ctx.r3.u64 = CECTargetingDog_SetTargetingFlag(ctx, base, ctx.r3.u64, ctx.r4.u64); }


// sub_829863A0  [112 bytes]
// Pushes a new empty Lua table and hands it to SharedPtr_CreateInventoryItem, which stores a registry
// reference to it, under the name string, in the smart pointer at sharedPtrOut.
uint64_t CECTargetingDog_CreateLuaTableSharedPtr(CpuState& ctx, uint8_t* base, uint64_t sharedPtrOut, uint64_t passThroughR6, uint64_t passThroughR7) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(68, 0x829863A0)) { ctx.r3.u64 = sharedPtrOut; ctx.r6.u64 = passThroughR6; ctx.r7.u64 = passThroughR7; __imp__sub_829863A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829863A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t manager = LOAD32(LOAD32(g_83490000 + 26912) + 12);
	uint32_t luaStateSlot = LOAD32(LOAD32(manager + 120) + 4);
	uint32_t luaState = LOAD32(luaStateSlot);

	ctx.r1.u64 = stack;
	lua_createtable(ctx, base, luaState, 0, 0, passThroughR6, passThroughR7, luaStateSlot);

	uint64_t returnValuesName = (int64_t)str_TXT_820C0000_B_ + 19528;
	SharedPtr_CreateInventoryItem(ctx, base, sharedPtrOut, luaState, returnValuesName, ctx.r6.u64, str_TXT_820C0000_B_);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return sharedPtrOut;
}
PROMOTED_ENTRY(68, sub_829863A0, 0x829863A0) { ctx.r3.u64 = CECTargetingDog_CreateLuaTableSharedPtr(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64); }
