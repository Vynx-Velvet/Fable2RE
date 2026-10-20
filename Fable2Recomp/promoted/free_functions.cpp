// Functions of no known class, as readable C++.
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

// sub_82172998 = Lua_Player_SetCloseToCombat (Lua Player.SetCloseToCombat)  [8 bytes]
void Lua_Player_SetCloseToCombat(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isCloseToCombat) {
	if (!UseLiftedCode(0, 0x82172998)) { ctx.r3.u64 = player; ctx.r4.u64 = isCloseToCombat; __imp__sub_82172998(ctx, base); return; }
	LiftedFrame frame(0x82172998);
	STORE8(player + 140, (uint8_t)isCloseToCombat);
	return;
}
PROMOTED_ENTRY(0, sub_82172998, 0x82172998) { Lua_Player_SetCloseToCombat(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void NullFunction(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(0, 0x82172EE0)) { __imp__sub_82172EE0(ctx, base); return; }
	LiftedFrame frame(0x82172EE0);
	return;
}
PROMOTED_ENTRY(0, sub_82172EE0, 0x82172EE0) { NullFunction(ctx, base); }

// sub_821742A0  [64 bytes]
uint64_t GetFlag40_17(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(0, 0x821742A0)) { ctx.r4.u64 = entity; __imp__sub_821742A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821742A0);
	// Bit 17 of the word at +40, read only when bit 6 of the byte at +144 is set.
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 40) >> 17) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(0, sub_821742A0, 0x821742A0) { ctx.r3.u64 = GetFlag40_17(ctx, base, ctx.r4.u32); }

uint64_t GetFlag44_25(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(0, 0x821742E0)) { ctx.r4.u64 = entity; __imp__sub_821742E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821742E0);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 44) >> 25) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(0, sub_821742E0, 0x821742E0) { ctx.r3.u64 = GetFlag44_25(ctx, base, ctx.r4.u32); }

uint64_t GetFlag36_21(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(0, 0x82174320)) { ctx.r4.u64 = entity; __imp__sub_82174320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82174320);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 36) >> 21) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(0, sub_82174320, 0x82174320) { ctx.r3.u64 = GetFlag36_21(ctx, base, ctx.r4.u32); }

uint64_t GetFlag40_28(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(0, 0x82174360)) { ctx.r4.u64 = entity; __imp__sub_82174360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82174360);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 40) >> 28) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(0, sub_82174360, 0x82174360) { ctx.r3.u64 = GetFlag40_28(ctx, base, ctx.r4.u32); }

uint64_t GetFlag40_25(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(0, 0x821743E0)) { ctx.r4.u64 = entity; __imp__sub_821743E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821743E0);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 40) >> 25) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(0, sub_821743E0, 0x821743E0) { ctx.r3.u64 = GetFlag40_25(ctx, base, ctx.r4.u32); }

uint64_t GetFlag48_15(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(0, 0x82174420)) { ctx.r4.u64 = entity; __imp__sub_82174420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82174420);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 48) >> 15) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(0, sub_82174420, 0x82174420) { ctx.r3.u64 = GetFlag48_15(ctx, base, ctx.r4.u32); }

// sub_8218AA50  [56 bytes]
uint64_t LuaTrampoline_8228E598(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(0, 0x8218AA50)) { ctx.r3.u64 = luaState; __imp__sub_8218AA50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218AA50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	uint64_t result = LuaInvokeUserdataMethod_8228E598(ctx, base, self, function, luaState);
	return result;
}
PROMOTED_ENTRY(0, sub_8218AA50, 0x8218AA50) { ctx.r3.u64 = LuaTrampoline_8228E598(ctx, base, ctx.r3.u64); }

uint64_t LuaTrampoline_8228B7B0(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(0, 0x8218AA88)) { ctx.r3.u64 = luaState; __imp__sub_8218AA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218AA88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return LuaInvokeUserdataMethod_8228B7B0(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(0, sub_8218AA88, 0x8218AA88) { ctx.r3.u64 = LuaTrampoline_8228B7B0(ctx, base, ctx.r3.u64); }

void CECBloodAlcohol_Noop(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(0, 0x8218AC78)) { __imp__sub_8218AC78(ctx, base); return; }
	LiftedFrame frame(0x8218AC78);
	return;
}
PROMOTED_ENTRY(0, sub_8218AC78, 0x8218AC78) { CECBloodAlcohol_Noop(ctx, base); }

uint64_t GetFlag56Bit21(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(2, 0x821AF1D8)) { ctx.r4.u64 = entity; __imp__sub_821AF1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821AF1D8);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 56) >> 21) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(2, sub_821AF1D8, 0x821AF1D8) { ctx.r3.u64 = GetFlag56Bit21(ctx, base, ctx.r4.u32); }

uint64_t GetFlag52Bit9(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(2, 0x821AF218)) { ctx.r4.u64 = entity; __imp__sub_821AF218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821AF218);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 52) >> 9) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(2, sub_821AF218, 0x821AF218) { ctx.r3.u64 = GetFlag52Bit9(ctx, base, ctx.r4.u32); }

uint64_t GetFlag36Bit28(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(2, 0x821AF258)) { ctx.r4.u64 = entity; __imp__sub_821AF258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821AF258);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 36) >> 28) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(2, sub_821AF258, 0x821AF258) { ctx.r3.u64 = GetFlag36Bit28(ctx, base, ctx.r4.u32); }

uint64_t Entity_IsValidForComponents(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(2, 0x821C0730)) { ctx.r4.u64 = entity; __imp__sub_821C0730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821C0730);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 48) >> 26) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(2, sub_821C0730, 0x821C0730) { ctx.r3.u64 = Entity_IsValidForComponents(ctx, base, ctx.r4.u32); }

uint64_t CCharString_Constructor(CpuState& ctx, uint8_t* base, uint64_t charString) {
	if (!UseLiftedCode(3, 0x821D5BA0)) { ctx.r3.u64 = charString; __imp__sub_821D5BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D5BA0);
	uint32_t refCountedObjectAddr{};
	GameStackFrame stackFrame(ctx, base, 96);
	refCountedObjectAddr = (int64_t)charString + 4;
	RefCountedObject_Construct(ctx, base, refCountedObjectAddr);
	CStringStruct_Constructor(ctx, base, charString);
	return charString;
}
PROMOTED_ENTRY(3, sub_821D5BA0, 0x821D5BA0) { ctx.r3.u64 = CCharString_Constructor(ctx, base, ctx.r3.u64); }

void NoOp(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(3, 0x821D98E0)) { __imp__sub_821D98E0(ctx, base); return; }
	LiftedFrame frame(0x821D98E0);
	return;
}
PROMOTED_ENTRY(3, sub_821D98E0, 0x821D98E0) { NoOp(ctx, base); }

uint64_t CCharString_ConstructFromStringAndCStr(CpuState& ctx, uint8_t* base, uint64_t resultString, uint64_t sourceString, uint64_t cString) {
	if (!UseLiftedCode(3, 0x821DA508)) { ctx.r3.u64 = resultString; ctx.r4.u64 = sourceString; ctx.r5.u64 = cString; __imp__sub_821DA508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821DA508);
	GameStackFrame stackFrame(ctx, base, 112);
	CCharString_CopyConstruct(ctx, base, resultString, sourceString);
	CCharString_AssignCString(ctx, base, resultString, cString);
	return resultString;
}
PROMOTED_ENTRY(3, sub_821DA508, 0x821DA508) { ctx.r3.u64 = CCharString_ConstructFromStringAndCStr(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CheckFlagAndBit(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(3, 0x821DB130)) { ctx.r4.u64 = entity; __imp__sub_821DB130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821DB130);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 40) >> 1) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(3, sub_821DB130, 0x821DB130) { ctx.r3.u64 = CheckFlagAndBit(ctx, base, ctx.r4.u32); }

uint64_t C_Allocator_GetAllocationSize(CpuState& ctx, uint8_t* base, uint64_t allocation) {
	if (!UseLiftedCode(6, 0x8221F3E8)) { ctx.r3.u64 = allocation; __imp__sub_8221F3E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8221F3E8);
	uint64_t allocationSize{};
	allocationSize = Heap_GetAllocationSize(ctx, base, allocation);
	return allocationSize;
}
PROMOTED_ENTRY(6, sub_8221F3E8, 0x8221F3E8) { ctx.r3.u64 = C_Allocator_GetAllocationSize(ctx, base, ctx.r3.u64); }

uint64_t GetFlag56Bit19(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(11, 0x8229BD18)) { ctx.r4.u64 = entity; __imp__sub_8229BD18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229BD18);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 56) >> 19) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(11, sub_8229BD18, 0x8229BD18) { ctx.r3.u64 = GetFlag56Bit19(ctx, base, ctx.r4.u32); }

uint64_t GetFlag52Bit4(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(11, 0x8229BD58)) { ctx.r4.u64 = entity; __imp__sub_8229BD58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229BD58);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 52) >> 4) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(11, sub_8229BD58, 0x8229BD58) { ctx.r3.u64 = GetFlag52Bit4(ctx, base, ctx.r4.u32); }

uint64_t FindChildByMask(CpuState& ctx, uint8_t* base, uint64_t container, uint64_t mask) {
	if (!UseLiftedCode(11, 0x8229D748)) { ctx.r3.u64 = container; ctx.r4.u64 = mask; __imp__sub_8229D748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229D748);
	uint64_t found{};
	found = Container_FindByMask(ctx, base, container, mask);
	return found;
}
PROMOTED_ENTRY(11, sub_8229D748, 0x8229D748) { ctx.r3.u64 = FindChildByMask(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t LuaTrampoline_InvokeEntityVectorVectorFloatVector(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(12, 0x822BF1D0)) { ctx.r3.u64 = luaState; __imp__sub_822BF1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822BF1D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return Lua_InvokeEntityVectorVectorFloatVector(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(12, sub_822BF1D0, 0x822BF1D0) { ctx.r3.u64 = LuaTrampoline_InvokeEntityVectorVectorFloatVector(ctx, base, ctx.r3.u64); }

uint64_t BasicWString_GetHash(CpuState& ctx, uint8_t* base, uint64_t string, uint64_t seed) {
	if (!UseLiftedCode(12, 0x822C88A8)) { ctx.r3.u64 = string; ctx.r8.u64 = seed; __imp__sub_822C88A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822C88A8);
	uint64_t hash{};
	hash = BasicWString_GetCachedHash(ctx, base, string, seed);
	return hash;
}
PROMOTED_ENTRY(12, sub_822C88A8, 0x822C88A8) { ctx.r3.u64 = BasicWString_GetHash(ctx, base, ctx.r3.u64, ctx.r8.u64); }

// sub_822D0F08  [8 bytes]
void SetByteAt92(CpuState& ctx, uint8_t* base, uint32_t targetObject, uint32_t value) {
	if (!UseLiftedCode(13, 0x822D0F08)) { ctx.r3.u64 = targetObject; ctx.r4.u64 = value; __imp__sub_822D0F08(ctx, base); return; }
	LiftedFrame frame(0x822D0F08);
	STORE8(targetObject + 92, (uint8_t)value);
}
PROMOTED_ENTRY(13, sub_822D0F08, 0x822D0F08) { SetByteAt92(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CThing_IsFlag48Bit4(CpuState& ctx, uint8_t* base, uint32_t thing) {
	if (!UseLiftedCode(13, 0x822D3C38)) { ctx.r4.u64 = thing; __imp__sub_822D3C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3C38);
	uint64_t result = 0;
	if (thing != 0) {
		uint32_t componentFlag = LOAD8(thing + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(thing + 48) >> 4) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(13, sub_822D3C38, 0x822D3C38) { ctx.r3.u64 = CThing_IsFlag48Bit4(ctx, base, ctx.r4.u32); }

uint64_t CThing_IsFlag52Bit18(CpuState& ctx, uint8_t* base, uint32_t thing) {
	if (!UseLiftedCode(13, 0x822D3C78)) { ctx.r4.u64 = thing; __imp__sub_822D3C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3C78);
	uint64_t result = 0;
	if (thing != 0) {
		uint32_t componentFlag = LOAD8(thing + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(thing + 52) >> 18) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(13, sub_822D3C78, 0x822D3C78) { ctx.r3.u64 = CThing_IsFlag52Bit18(ctx, base, ctx.r4.u32); }

uint64_t CThing_IsFlag40Bit2(CpuState& ctx, uint8_t* base, uint32_t thing) {
	if (!UseLiftedCode(13, 0x822D3CF8)) { ctx.r4.u64 = thing; __imp__sub_822D3CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3CF8);
	uint64_t result = 0;
	if (thing != 0) {
		uint32_t componentFlag = LOAD8(thing + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(thing + 40) >> 2) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(13, sub_822D3CF8, 0x822D3CF8) { ctx.r3.u64 = CThing_IsFlag40Bit2(ctx, base, ctx.r4.u32); }

// sub_822F0808  [112 bytes]
uint64_t LinkedList_Destroy(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834970D8 = int32_t(0x834970D8);
	if (!UseLiftedCode(14, 0x822F0808)) { __imp__sub_822F0808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822F0808);
	// Passes the range from (container, first node) to (container, head node) to LinkedList_ClearRange_822F15B8 as two
	// stack pairs, then frees the head node and zeroes +4 and +8 of the container.
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834970D8;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_822F15B8(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(14, sub_822F0808, 0x822F0808) { ctx.r3.u64 = LinkedList_Destroy(ctx, base); }

void Stub_Return(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(14, 0x822F2504)) { __imp__sub_822F2504(ctx, base); return; }
	LiftedFrame frame(0x822F2504);
	return;
}
PROMOTED_ENTRY(14, sub_822F2504, 0x822F2504) { Stub_Return(ctx, base); }

// sub_822F5718  [104 bytes]
uint32_t LinkedList_Destroy_822F5718(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(14, 0x822F5718)) { ctx.r3.u64 = listContainer; __imp__sub_822F5718(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822F5718);
	// Passes the range from (listContainer, first node) to (listContainer, head node) to LinkedList_ClearRange_822F71A8 as two stack pairs,
	// then frees the head node and zeroes +4 and +8 of listContainer.
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_822F71A8(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(14, sub_822F5718, 0x822F5718) { ctx.r3.u64 = LinkedList_Destroy_822F5718(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_822F6660(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(14, 0x822F6660)) { ctx.r3.u64 = listContainer; __imp__sub_822F6660(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822F6660);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_822F6F58(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(14, sub_822F6660, 0x822F6660) { ctx.r3.u64 = LinkedList_Destroy_822F6660(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_822F6990(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(14, 0x822F6990)) { ctx.r3.u64 = listContainer; __imp__sub_822F6990(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822F6990);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_82B4CC70(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(14, sub_822F6990, 0x822F6990) { ctx.r3.u64 = LinkedList_Destroy_822F6990(ctx, base, ctx.r3.u64); }

void EmptyFunction(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(14, 0x822FCD78)) { __imp__sub_822FCD78(ctx, base); return; }
	LiftedFrame frame(0x822FCD78);
	return;
}
PROMOTED_ENTRY(14, sub_822FCD78, 0x822FCD78) { EmptyFunction(ctx, base); }

uint32_t LinkedList_Destroy_82307120(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(15, 0x82307120)) { ctx.r3.u64 = listContainer; __imp__sub_82307120(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82307120);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_82308A38(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(15, sub_82307120, 0x82307120) { ctx.r3.u64 = LinkedList_Destroy_82307120(ctx, base, ctx.r3.u64); }

void SetByteAt245(CpuState& ctx, uint8_t* base, uint32_t targetObject, uint32_t value) {
	if (!UseLiftedCode(15, 0x8230F700)) { ctx.r3.u64 = targetObject; ctx.r4.u64 = value; __imp__sub_8230F700(ctx, base); return; }
	LiftedFrame frame(0x8230F700);
	STORE8(targetObject + 245, (uint8_t)value);
}
PROMOTED_ENTRY(15, sub_8230F700, 0x8230F700) { SetByteAt245(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void SetByteAt222(CpuState& ctx, uint8_t* base, uint32_t targetObject, uint32_t value) {
	if (!UseLiftedCode(15, 0x8231EC50)) { ctx.r3.u64 = targetObject; ctx.r4.u64 = value; __imp__sub_8231EC50(ctx, base); return; }
	LiftedFrame frame(0x8231EC50);
	STORE8(targetObject + 222, (uint8_t)value);
}
PROMOTED_ENTRY(15, sub_8231EC50, 0x8231EC50) { SetByteAt222(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t LinkedList_Destroy_823234E8(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(15, 0x823234E8)) { ctx.r3.u64 = listContainer; __imp__sub_823234E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823234E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_82324B98(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(15, sub_823234E8, 0x823234E8) { ctx.r3.u64 = LinkedList_Destroy_823234E8(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_8233D940(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(16, 0x8233D940)) { ctx.r3.u64 = listContainer; __imp__sub_8233D940(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8233D940);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_8233DC88(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(16, sub_8233D940, 0x8233D940) { ctx.r3.u64 = LinkedList_Destroy_8233D940(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_82343AA8(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(16, 0x82343AA8)) { ctx.r3.u64 = listContainer; __imp__sub_82343AA8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82343AA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_823449B8(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(16, sub_82343AA8, 0x82343AA8) { ctx.r3.u64 = LinkedList_Destroy_82343AA8(ctx, base, ctx.r3.u64); }

void Lua_GraphicAppearanceMorph_SetRealTimeTextureMorphing(CpuState& ctx, uint8_t* base, uint32_t graphicAppearanceMorph, uint32_t isRealTimeMorphingEnabled) {
	if (!UseLiftedCode(17, 0x8234B5C8)) { ctx.r3.u64 = graphicAppearanceMorph; ctx.r4.u64 = isRealTimeMorphingEnabled; __imp__sub_8234B5C8(ctx, base); return; }
	LiftedFrame frame(0x8234B5C8);
	STORE8(graphicAppearanceMorph + 178, (uint8_t)isRealTimeMorphingEnabled);
	return;
}
PROMOTED_ENTRY(17, sub_8234B5C8, 0x8234B5C8) { Lua_GraphicAppearanceMorph_SetRealTimeTextureMorphing(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t LinkedList_Destroy_8234B7B8(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(17, 0x8234B7B8)) { ctx.r3.u64 = listContainer; __imp__sub_8234B7B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8234B7B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_8234C768(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(17, sub_8234B7B8, 0x8234B7B8) { ctx.r3.u64 = LinkedList_Destroy_8234B7B8(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_8234B820(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(17, 0x8234B820)) { ctx.r3.u64 = listContainer; __imp__sub_8234B820(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8234B820);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_8234C878(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(17, sub_8234B820, 0x8234B820) { ctx.r3.u64 = LinkedList_Destroy_8234B820(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_8234C620(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(17, 0x8234C620)) { ctx.r3.u64 = listContainer; __imp__sub_8234C620(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8234C620);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_8234D2E0(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(17, sub_8234C620, 0x8234C620) { ctx.r3.u64 = LinkedList_Destroy_8234C620(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_8234C700(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(17, 0x8234C700)) { ctx.r3.u64 = listContainer; __imp__sub_8234C700(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8234C700);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_8234D3F0(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(17, sub_8234C700, 0x8234C700) { ctx.r3.u64 = LinkedList_Destroy_8234C700(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetApplicationName(CpuState& ctx, uint8_t* base, uint64_t applicationName) {
	constexpr int32_t TXT_83497398_G_ = int32_t(0x83497398);
	if (!UseLiftedCode(17, 0x82357228)) { ctx.r3.u64 = applicationName; __imp__sub_82357228(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357228);
	uint64_t applicationNameSetting{};
	uint64_t result{};
	applicationNameSetting = TXT_83497398_G_;
	result = CCharString_Assign(ctx, base, applicationNameSetting, applicationName);
	return result;
}
PROMOTED_ENTRY(17, sub_82357228, 0x82357228) { ctx.r3.u64 = Lua_Inventory_SetApplicationName(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetInitialWorldName(CpuState& ctx, uint8_t* base, uint64_t initialWorldName) {
	constexpr int32_t TXT_834973AC_G_ = int32_t(0x834973AC);
	if (!UseLiftedCode(17, 0x82357258)) { ctx.r3.u64 = initialWorldName; __imp__sub_82357258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357258);
	uint64_t initialWorldNameSetting{};
	uint64_t result{};
	initialWorldNameSetting = TXT_834973AC_G_;
	result = CCharString_Assign(ctx, base, initialWorldNameSetting, initialWorldName);
	return result;
}
PROMOTED_ENTRY(17, sub_82357258, 0x82357258) { ctx.r3.u64 = Lua_Inventory_SetInitialWorldName(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetInitialLevelName(CpuState& ctx, uint8_t* base, uint64_t initialLevelName) {
	constexpr int32_t TXT_834973B0_G_ = int32_t(0x834973B0);
	if (!UseLiftedCode(17, 0x82357268)) { ctx.r3.u64 = initialLevelName; __imp__sub_82357268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357268);
	uint64_t initialLevelNameSetting{};
	uint64_t result{};
	initialLevelNameSetting = TXT_834973B0_G_;
	result = CCharString_Assign(ctx, base, initialLevelNameSetting, initialLevelName);
	return result;
}
PROMOTED_ENTRY(17, sub_82357268, 0x82357268) { ctx.r3.u64 = Lua_Inventory_SetInitialLevelName(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetGameflowLevelName(CpuState& ctx, uint8_t* base, uint64_t gameflowLevelName) {
	constexpr int32_t TXT_834973C4_G_ = int32_t(0x834973C4);
	if (!UseLiftedCode(17, 0x823572B8)) { ctx.r3.u64 = gameflowLevelName; __imp__sub_823572B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823572B8);
	uint64_t gameflowLevelNameSetting{};
	uint64_t result{};
	gameflowLevelNameSetting = TXT_834973C4_G_;
	result = CCharString_Assign(ctx, base, gameflowLevelNameSetting, gameflowLevelName);
	return result;
}
PROMOTED_ENTRY(17, sub_823572B8, 0x823572B8) { ctx.r3.u64 = Lua_Inventory_SetGameflowLevelName(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetInitialHeroModelName(CpuState& ctx, uint8_t* base, uint64_t initialHeroModelName) {
	constexpr int32_t TXT_834973CC_G_ = int32_t(0x834973CC);
	if (!UseLiftedCode(17, 0x823572F8)) { ctx.r3.u64 = initialHeroModelName; __imp__sub_823572F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823572F8);
	uint64_t initialHeroModelNameSetting{};
	uint64_t result{};
	initialHeroModelNameSetting = TXT_834973CC_G_;
	result = CCharString_Assign(ctx, base, initialHeroModelNameSetting, initialHeroModelName);
	return result;
}
PROMOTED_ENTRY(17, sub_823572F8, 0x823572F8) { ctx.r3.u64 = Lua_Inventory_SetInitialHeroModelName(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetInitialHenchmanModelName(CpuState& ctx, uint8_t* base, uint64_t initialHenchmanModelName) {
	constexpr int32_t TXT_834973D0_G_ = int32_t(0x834973D0);
	if (!UseLiftedCode(17, 0x82357308)) { ctx.r3.u64 = initialHenchmanModelName; __imp__sub_82357308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357308);
	uint64_t initialHenchmanModelNameSetting{};
	uint64_t result{};
	initialHenchmanModelNameSetting = TXT_834973D0_G_;
	result = CCharString_Assign(ctx, base, initialHenchmanModelNameSetting, initialHenchmanModelName);
	return result;
}
PROMOTED_ENTRY(17, sub_82357308, 0x82357308) { ctx.r3.u64 = Lua_Inventory_SetInitialHenchmanModelName(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetInitialHeroMeleeWeapon(CpuState& ctx, uint8_t* base, uint64_t initialHeroMeleeWeapon) {
	constexpr int32_t TXT_834973D4_G_ = int32_t(0x834973D4);
	if (!UseLiftedCode(17, 0x82357318)) { ctx.r3.u64 = initialHeroMeleeWeapon; __imp__sub_82357318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357318);
	uint64_t initialHeroMeleeWeaponSetting{};
	uint64_t result{};
	initialHeroMeleeWeaponSetting = TXT_834973D4_G_;
	result = CCharString_Assign(ctx, base, initialHeroMeleeWeaponSetting, initialHeroMeleeWeapon);
	return result;
}
PROMOTED_ENTRY(17, sub_82357318, 0x82357318) { ctx.r3.u64 = Lua_Inventory_SetInitialHeroMeleeWeapon(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_SetInitialHeroRangedWeapon(CpuState& ctx, uint8_t* base, uint64_t initialHeroRangedWeapon) {
	constexpr int32_t TXT_834973D8_G_ = int32_t(0x834973D8);
	if (!UseLiftedCode(17, 0x82357328)) { ctx.r3.u64 = initialHeroRangedWeapon; __imp__sub_82357328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357328);
	uint64_t initialHeroRangedWeaponSetting{};
	uint64_t result{};
	initialHeroRangedWeaponSetting = TXT_834973D8_G_;
	result = CCharString_Assign(ctx, base, initialHeroRangedWeaponSetting, initialHeroRangedWeapon);
	return result;
}
PROMOTED_ENTRY(17, sub_82357328, 0x82357328) { ctx.r3.u64 = Lua_Inventory_SetInitialHeroRangedWeapon(ctx, base, ctx.r3.u64); }

uint64_t Lua_Inventory_GetApplicationName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497398_G_ = int32_t(0x83497398);
	if (!UseLiftedCode(17, 0x82357358)) { __imp__sub_82357358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357358);
	return TXT_83497398_G_;
}
PROMOTED_ENTRY(17, sub_82357358, 0x82357358) { ctx.r3.u64 = Lua_Inventory_GetApplicationName(ctx, base); }

uint64_t Lua_Inventory_GetAIScriptName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349739C_G_ = int32_t(0x8349739C);
	if (!UseLiftedCode(17, 0x82357388)) { __imp__sub_82357388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357388);
	return TXT_8349739C_G_;
}
PROMOTED_ENTRY(17, sub_82357388, 0x82357388) { ctx.r3.u64 = Lua_Inventory_GetAIScriptName(ctx, base); }

uint64_t Lua_Inventory_GetCameraScriptName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973A0_G_ = int32_t(0x834973A0);
	if (!UseLiftedCode(17, 0x82357398)) { __imp__sub_82357398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357398);
	return TXT_834973A0_G_;
}
PROMOTED_ENTRY(17, sub_82357398, 0x82357398) { ctx.r3.u64 = Lua_Inventory_GetCameraScriptName(ctx, base); }

uint64_t Lua_Inventory_GetQuestScriptName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973A4_G_ = int32_t(0x834973A4);
	if (!UseLiftedCode(17, 0x823573A8)) { __imp__sub_823573A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823573A8);
	return TXT_834973A4_G_;
}
PROMOTED_ENTRY(17, sub_823573A8, 0x823573A8) { ctx.r3.u64 = Lua_Inventory_GetQuestScriptName(ctx, base); }

uint64_t Lua_Inventory_GetGeneralSetupScriptName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973A8_G_ = int32_t(0x834973A8);
	if (!UseLiftedCode(17, 0x823573B8)) { __imp__sub_823573B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823573B8);
	return TXT_834973A8_G_;
}
PROMOTED_ENTRY(17, sub_823573B8, 0x823573B8) { ctx.r3.u64 = Lua_Inventory_GetGeneralSetupScriptName(ctx, base); }

uint64_t Lua_Inventory_GetInitialWorldName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973AC_G_ = int32_t(0x834973AC);
	if (!UseLiftedCode(17, 0x823573C8)) { __imp__sub_823573C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823573C8);
	return TXT_834973AC_G_;
}
PROMOTED_ENTRY(17, sub_823573C8, 0x823573C8) { ctx.r3.u64 = Lua_Inventory_GetInitialWorldName(ctx, base); }

uint64_t Lua_Inventory_GetInitialLevelName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973B0_G_ = int32_t(0x834973B0);
	if (!UseLiftedCode(17, 0x823573D8)) { __imp__sub_823573D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823573D8);
	return TXT_834973B0_G_;
}
PROMOTED_ENTRY(17, sub_823573D8, 0x823573D8) { ctx.r3.u64 = Lua_Inventory_GetInitialLevelName(ctx, base); }

uint64_t Lua_Inventory_GetInitialScenarioName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834973B4 = int32_t(0x834973B4);
	if (!UseLiftedCode(17, 0x823573E8)) { __imp__sub_823573E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823573E8);
	return g_834973B4;
}
PROMOTED_ENTRY(17, sub_823573E8, 0x823573E8) { ctx.r3.u64 = Lua_Inventory_GetInitialScenarioName(ctx, base); }

uint64_t Lua_Inventory_GetInitialStartPointName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834973B8 = int32_t(0x834973B8);
	if (!UseLiftedCode(17, 0x823573F8)) { __imp__sub_823573F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823573F8);
	return g_834973B8;
}
PROMOTED_ENTRY(17, sub_823573F8, 0x823573F8) { ctx.r3.u64 = Lua_Inventory_GetInitialStartPointName(ctx, base); }

uint64_t Lua_Inventory_GetInitialSaveGameName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834973BC = int32_t(0x834973BC);
	if (!UseLiftedCode(17, 0x82357408)) { __imp__sub_82357408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357408);
	return g_834973BC;
}
PROMOTED_ENTRY(17, sub_82357408, 0x82357408) { ctx.r3.u64 = Lua_Inventory_GetInitialSaveGameName(ctx, base); }

uint64_t Lua_Inventory_GetGameflowWorldName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973C0_G_ = int32_t(0x834973C0);
	if (!UseLiftedCode(17, 0x82357418)) { __imp__sub_82357418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357418);
	return TXT_834973C0_G_;
}
PROMOTED_ENTRY(17, sub_82357418, 0x82357418) { ctx.r3.u64 = Lua_Inventory_GetGameflowWorldName(ctx, base); }

uint64_t Lua_Inventory_GetGameflowLevelName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973C4_G_ = int32_t(0x834973C4);
	if (!UseLiftedCode(17, 0x82357428)) { __imp__sub_82357428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357428);
	return TXT_834973C4_G_;
}
PROMOTED_ENTRY(17, sub_82357428, 0x82357428) { ctx.r3.u64 = Lua_Inventory_GetGameflowLevelName(ctx, base); }

uint64_t Lua_Inventory_GetControlSystemRecordName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973C8_G_ = int32_t(0x834973C8);
	if (!UseLiftedCode(17, 0x82357438)) { __imp__sub_82357438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357438);
	return TXT_834973C8_G_;
}
PROMOTED_ENTRY(17, sub_82357438, 0x82357438) { ctx.r3.u64 = Lua_Inventory_GetControlSystemRecordName(ctx, base); }

uint64_t Lua_Inventory_GetInitialHeroModelName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973CC_G_ = int32_t(0x834973CC);
	if (!UseLiftedCode(17, 0x82357448)) { __imp__sub_82357448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357448);
	return TXT_834973CC_G_;
}
PROMOTED_ENTRY(17, sub_82357448, 0x82357448) { ctx.r3.u64 = Lua_Inventory_GetInitialHeroModelName(ctx, base); }

uint64_t Lua_Inventory_GetInitialHenchmanModelName(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973D0_G_ = int32_t(0x834973D0);
	if (!UseLiftedCode(17, 0x82357458)) { __imp__sub_82357458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357458);
	return TXT_834973D0_G_;
}
PROMOTED_ENTRY(17, sub_82357458, 0x82357458) { ctx.r3.u64 = Lua_Inventory_GetInitialHenchmanModelName(ctx, base); }

uint64_t Lua_Inventory_GetInitialHenchmanMeleeWeapon(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973DC_G_ = int32_t(0x834973DC);
	if (!UseLiftedCode(17, 0x82357468)) { __imp__sub_82357468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357468);
	return TXT_834973DC_G_;
}
PROMOTED_ENTRY(17, sub_82357468, 0x82357468) { ctx.r3.u64 = Lua_Inventory_GetInitialHenchmanMeleeWeapon(ctx, base); }

uint64_t Lua_Inventory_GetInitialHenchmanRangedWeapon(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973E0_G_ = int32_t(0x834973E0);
	if (!UseLiftedCode(17, 0x82357478)) { __imp__sub_82357478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357478);
	return TXT_834973E0_G_;
}
PROMOTED_ENTRY(17, sub_82357478, 0x82357478) { ctx.r3.u64 = Lua_Inventory_GetInitialHenchmanRangedWeapon(ctx, base); }

uint64_t Lua_Inventory_GetMillisecondsToWaitForLuaDebugger(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(17, 0x82357488)) { __imp__sub_82357488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82357488);
	uint32_t millisecondsToWait{};
	millisecondsToWait = 4000;
	return millisecondsToWait;
}
PROMOTED_ENTRY(17, sub_82357488, 0x82357488) { ctx.r3.u64 = Lua_Inventory_GetMillisecondsToWaitForLuaDebugger(ctx, base); }

uint32_t LinkedList_Destroy_82365890(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(18, 0x82365890)) { ctx.r3.u64 = listContainer; __imp__sub_82365890(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82365890);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_82367898(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(18, sub_82365890, 0x82365890) { ctx.r3.u64 = LinkedList_Destroy_82365890(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_82366470(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(18, 0x82366470)) { ctx.r3.u64 = listContainer; __imp__sub_82366470(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82366470);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_82367980(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(18, sub_82366470, 0x82366470) { ctx.r3.u64 = LinkedList_Destroy_82366470(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_8236A750(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(18, 0x8236A750)) { ctx.r3.u64 = listContainer; __imp__sub_8236A750(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8236A750);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_8236B138(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(18, sub_8236A750, 0x8236A750) { ctx.r3.u64 = LinkedList_Destroy_8236A750(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_82376980(CpuState& ctx, uint8_t* base, uint64_t listContainer) {
	if (!UseLiftedCode(18, 0x82376980)) { ctx.r3.u64 = listContainer; __imp__sub_82376980(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82376980);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)listContainer);
	STORE32(stack + 80, (uint32_t)listContainer);
	uint32_t headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_82376898(ctx, base, (int64_t)(uint64_t)stack + 88, listContainer, beginPair, endPair);
	headNode = LOAD32((uint32_t)listContainer + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)listContainer + 4, 0u);
	STORE32((uint32_t)listContainer + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(18, sub_82376980, 0x82376980) { ctx.r3.u64 = LinkedList_Destroy_82376980(ctx, base, ctx.r3.u64); }

void Vector_SetSplat(CpuState& ctx, uint8_t* base, uint32_t destinationVector, uint32_t value2) {
	if (!UseLiftedCode(18, 0x8237D248)) { ctx.r3.u64 = destinationVector; ctx.r4.u64 = value2; __imp__sub_8237D248(ctx, base); return; }
	LiftedFrame frame(0x8237D248);
	PPCRegister scratch{};
	PPCVRegister expandedValue{};
	PPCVRegister splatValue{};
	scratch.u32 = value2;
	SET_V8(expandedValue, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_V8(splatValue, simde_mm_shuffle_epi32(V8(expandedValue), 0xFF));
	VSTORE(destinationVector & ~0xF, V8(splatValue));
	return;
}
PROMOTED_ENTRY(18, sub_8237D248, 0x8237D248) { Vector_SetSplat(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Stats_SetCanDisplayWorldIconsOnStatChanges(CpuState& ctx, uint8_t* base, uint32_t stats, uint32_t canDisplayIcons) {
	if (!UseLiftedCode(18, 0x8237D360)) { ctx.r3.u64 = stats; ctx.r4.u64 = canDisplayIcons; __imp__sub_8237D360(ctx, base); return; }
	LiftedFrame frame(0x8237D360);
	STORE8(stats + 995, (uint8_t)canDisplayIcons);
	return;
}
PROMOTED_ENTRY(18, sub_8237D360, 0x8237D360) { Lua_Stats_SetCanDisplayWorldIconsOnStatChanges(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t LinkedList_DestroyGlobal_82394830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83497688 = int32_t(0x83497688);
	if (!UseLiftedCode(19, 0x82394830)) { __imp__sub_82394830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82394830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_83497688;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_ClearRange_82394CB8(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(19, sub_82394830, 0x82394830) { ctx.r3.u64 = LinkedList_DestroyGlobal_82394830(ctx, base); }

uint64_t Object_IsFlag23Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(19, 0x8239DAB8)) { ctx.r4.u64 = object; __imp__sub_8239DAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8239DAB8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t componentFlag = LOAD8(object + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(object + 36) >> 23) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(19, sub_8239DAB8, 0x8239DAB8) { ctx.r3.u64 = Object_IsFlag23Set(ctx, base, ctx.r4.u32); }

uint64_t Object_IsFlag17Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(20, 0x8239F670)) { ctx.r4.u64 = object; __imp__sub_8239F670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8239F670);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t componentFlag = LOAD8(object + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(object + 44) >> 17) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(20, sub_8239F670, 0x8239F670) { ctx.r3.u64 = Object_IsFlag17Set(ctx, base, ctx.r4.u32); }

uint64_t Lua_Sound_SoundEventTracingClearFilters(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834976F8 = int32_t(0x834976F8);
	if (!UseLiftedCode(20, 0x823A1970)) { __imp__sub_823A1970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823A1970);
	return StringVector_Clear(ctx, base, g_834976F8);
}
PROMOTED_ENTRY(20, sub_823A1970, 0x823A1970) { ctx.r3.u64 = Lua_Sound_SoundEventTracingClearFilters(ctx, base); }

uint64_t Entity_IsScriptable(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(20, 0x823A2E10)) { ctx.r4.u64 = entity; __imp__sub_823A2E10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823A2E10);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 52) >> 7) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(20, sub_823A2E10, 0x823A2E10) { ctx.r3.u64 = Entity_IsScriptable(ctx, base, ctx.r4.u32); }

void Lua_FootPlanting_SetFootLockingEnabled(CpuState& ctx, uint8_t* base, uint32_t footPlanting, uint32_t isFootLockingEnabled) {
	if (!UseLiftedCode(20, 0x823A5480)) { ctx.r3.u64 = footPlanting; ctx.r4.u64 = isFootLockingEnabled; __imp__sub_823A5480(ctx, base); return; }
	LiftedFrame frame(0x823A5480);
	STORE8(footPlanting + 52, (uint8_t)isFootLockingEnabled);
	return;
}
PROMOTED_ENTRY(20, sub_823A5480, 0x823A5480) { Lua_FootPlanting_SetFootLockingEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void SetGlobalArrayElementSubByte(CpuState& ctx, uint8_t* base, uint64_t recordIndex, uint32_t elementIndex, uint32_t value2) {
	if (!UseLiftedCode(20, 0x823ABF18)) { ctx.r3.u64 = recordIndex; ctx.r4.u64 = elementIndex; ctx.r5.u64 = value2; __imp__sub_823ABF18(ctx, base); return; }
	LiftedFrame frame(0x823ABF18);
	uint32_t elementOffset{};
	elementOffset = elementIndex + (uint64_t)(elementIndex << 2);
	elementOffset = elementOffset << 4;
	STORE8(uint32_t((uint64_t)(int64_t)static_cast<int64_t>(recordIndex * static_cast<uint64_t>(176)) + elementOffset) + uint32_t((int64_t)-2092324264 + 28), (uint8_t)value2);
	return;
}
PROMOTED_ENTRY(20, sub_823ABF18, 0x823ABF18) { SetGlobalArrayElementSubByte(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32); }

// sub_823B1450  [148 bytes]
uint32_t n_sub_823B1450(CpuState& ctx, uint8_t* base, uint32_t luaRef, uint64_t fieldKey, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B1CE0 = int32_t(0x823B1CE0);
	if (!UseLiftedCode(20, 0x823B1450)) { ctx.r3.u64 = luaRef; ctx.r4.u64 = fieldKey; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B1450(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B1450);
	// Pushes the registry entry *luaRef refers to, wraps fieldValue in a new userdata and stores it in that entry under
	// the field key fieldKey (lua_setfield), then pops the entry; r9 hands back the new stack top.
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaRef;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B1CE0, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaRef = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaRef;
}
PROMOTED_ENTRY(20, sub_823B1450, 0x823B1450) { ctx.r3.u64 = n_sub_823B1450(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B14E8(CpuState& ctx, uint8_t* base, uint32_t luaRef, uint64_t fieldKey, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B1E90 = int32_t(0x823B1E90);
	if (!UseLiftedCode(20, 0x823B14E8)) { ctx.r3.u64 = luaRef; ctx.r4.u64 = fieldKey; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B14E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B14E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaRef;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B1E90, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaRef = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaRef;
}
PROMOTED_ENTRY(20, sub_823B14E8, 0x823B14E8) { ctx.r3.u64 = n_sub_823B14E8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B1580(CpuState& ctx, uint8_t* base, uint32_t luaRef, uint64_t fieldKey, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B1F70 = int32_t(0x823B1F70);
	if (!UseLiftedCode(20, 0x823B1580)) { ctx.r3.u64 = luaRef; ctx.r4.u64 = fieldKey; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B1580(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B1580);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaRef;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B1F70, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaRef = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaRef;
}
PROMOTED_ENTRY(20, sub_823B1580, 0x823B1580) { ctx.r3.u64 = n_sub_823B1580(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B16B0(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B2260 = int32_t(0x823B2260);
	if (!UseLiftedCode(20, 0x823B16B0)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B16B0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B16B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B2260, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(20, sub_823B16B0, 0x823B16B0) { ctx.r3.u64 = n_sub_823B16B0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B1748(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B23A0 = int32_t(0x823B23A0);
	if (!UseLiftedCode(20, 0x823B1748)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B1748(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B1748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B23A0, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(20, sub_823B1748, 0x823B1748) { ctx.r3.u64 = n_sub_823B1748(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B17E0(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B2478 = int32_t(0x823B2478);
	if (!UseLiftedCode(20, 0x823B17E0)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B17E0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B17E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B2478, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(20, sub_823B17E0, 0x823B17E0) { ctx.r3.u64 = n_sub_823B17E0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B1878(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B2508 = int32_t(0x823B2508);
	if (!UseLiftedCode(20, 0x823B1878)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B1878(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B1878);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B2508, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(20, sub_823B1878, 0x823B1878) { ctx.r3.u64 = n_sub_823B1878(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B1910(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_823B2660 = int32_t(0x823B2660);
	if (!UseLiftedCode(20, 0x823B1910)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B1910(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B1910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_823B2660, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(20, sub_823B1910, 0x823B1910) { ctx.r3.u64 = n_sub_823B1910(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_823B1A40(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82198208 = int32_t(0x82198208);
	if (!UseLiftedCode(20, 0x823B1A40)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_823B1A40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823B1A40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82198208, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(20, sub_823B1A40, 0x823B1A40) { ctx.r3.u64 = n_sub_823B1A40(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t GetFlag36Bit12(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(20, 0x823B38D8)) { ctx.r4.u64 = entity; __imp__sub_823B38D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823B38D8);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 36) >> 12) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(20, sub_823B38D8, 0x823B38D8) { ctx.r3.u64 = GetFlag36Bit12(ctx, base, ctx.r4.u32); }

void Lua_Player_SetPlayerMovementSpeedOverridden(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isOverridden) {
	if (!UseLiftedCode(20, 0x823BE7D0)) { ctx.r3.u64 = player; ctx.r4.u64 = isOverridden; __imp__sub_823BE7D0(ctx, base); return; }
	LiftedFrame frame(0x823BE7D0);
	STORE8(player + 30, (uint8_t)isOverridden);
	return;
}
PROMOTED_ENTRY(20, sub_823BE7D0, 0x823BE7D0) { Lua_Player_SetPlayerMovementSpeedOverridden(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetFastTravelStopActivationAsEnabled(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isEnabled) {
	if (!UseLiftedCode(21, 0x823C2140)) { ctx.r3.u64 = player; ctx.r4.u64 = isEnabled; __imp__sub_823C2140(ctx, base); return; }
	LiftedFrame frame(0x823C2140);
	STORE8(player + 39, (uint8_t)isEnabled);
	return;
}
PROMOTED_ENTRY(21, sub_823C2140, 0x823C2140) { Lua_Player_SetFastTravelStopActivationAsEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetTimeSpellBuyable(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isBuyable) {
	if (!UseLiftedCode(21, 0x823C25B8)) { ctx.r3.u64 = player; ctx.r4.u64 = isBuyable; __imp__sub_823C25B8(ctx, base); return; }
	LiftedFrame frame(0x823C25B8);
	STORE8(player + 47, (uint8_t)isBuyable);
	return;
}
PROMOTED_ENTRY(21, sub_823C25B8, 0x823C25B8) { Lua_Player_SetTimeSpellBuyable(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetRaiseDeadSpellBuyable(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isBuyable) {
	if (!UseLiftedCode(21, 0x823C25C8)) { ctx.r3.u64 = player; ctx.r4.u64 = isBuyable; __imp__sub_823C25C8(ctx, base); return; }
	LiftedFrame frame(0x823C25C8);
	STORE8(player + 48, (uint8_t)isBuyable);
	return;
}
PROMOTED_ENTRY(21, sub_823C25C8, 0x823C25C8) { Lua_Player_SetRaiseDeadSpellBuyable(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetExperienceBarAsEnabled(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isEnabled) {
	if (!UseLiftedCode(21, 0x823C25D8)) { ctx.r3.u64 = player; ctx.r4.u64 = isEnabled; __imp__sub_823C25D8(ctx, base); return; }
	LiftedFrame frame(0x823C25D8);
	STORE8(player + 49, (uint8_t)isEnabled);
	return;
}
PROMOTED_ENTRY(21, sub_823C25D8, 0x823C25D8) { Lua_Player_SetExperienceBarAsEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetInterestingHighlightingAsEnabled(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isEnabled) {
	if (!UseLiftedCode(21, 0x823C25E8)) { ctx.r3.u64 = player; ctx.r4.u64 = isEnabled; __imp__sub_823C25E8(ctx, base); return; }
	LiftedFrame frame(0x823C25E8);
	STORE8(player + 50, (uint8_t)isEnabled);
	return;
}
PROMOTED_ENTRY(21, sub_823C25E8, 0x823C25E8) { Lua_Player_SetInterestingHighlightingAsEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetInventoryScreenAsEnabled(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isEnabled) {
	if (!UseLiftedCode(21, 0x823C25F8)) { ctx.r3.u64 = player; ctx.r4.u64 = isEnabled; __imp__sub_823C25F8(ctx, base); return; }
	LiftedFrame frame(0x823C25F8);
	STORE8(player + 51, (uint8_t)isEnabled);
	return;
}
PROMOTED_ENTRY(21, sub_823C25F8, 0x823C25F8) { Lua_Player_SetInventoryScreenAsEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetPauseMenuInfoPageAsEnabled(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isEnabled) {
	if (!UseLiftedCode(21, 0x823C2608)) { ctx.r3.u64 = player; ctx.r4.u64 = isEnabled; __imp__sub_823C2608(ctx, base); return; }
	LiftedFrame frame(0x823C2608);
	STORE8(player + 53, (uint8_t)isEnabled);
	return;
}
PROMOTED_ENTRY(21, sub_823C2608, 0x823C2608) { Lua_Player_SetPauseMenuInfoPageAsEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetAbleToCollectExperienceOrbs(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t canCollect) {
	if (!UseLiftedCode(21, 0x823C5E90)) { ctx.r3.u64 = player; ctx.r4.u64 = canCollect; __imp__sub_823C5E90(ctx, base); return; }
	LiftedFrame frame(0x823C5E90);
	STORE8(player + 29, (uint8_t)canCollect);
	return;
}
PROMOTED_ENTRY(21, sub_823C5E90, 0x823C5E90) { Lua_Player_SetAbleToCollectExperienceOrbs(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t Lua_Player_StartRumbleEvent(CpuState& ctx, uint8_t* base, uint64_t player, uint64_t rumbleEventId) {
	if (!UseLiftedCode(21, 0x823C84D8)) { ctx.r3.u64 = player; ctx.r4.u64 = rumbleEventId; __imp__sub_823C84D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823C84D8);
	uint64_t startResult{};
	uint32_t eventFlags{};
	eventFlags = 1;
	startResult = Rumble_StartEventById(ctx, base, player, rumbleEventId, eventFlags);
	return startResult;
}
PROMOTED_ENTRY(21, sub_823C84D8, 0x823C84D8) { ctx.r3.u64 = Lua_Player_StartRumbleEvent(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t List_Destructor_823D2918(CpuState& ctx, uint8_t* base, uint64_t container) {
	if (!UseLiftedCode(21, 0x823D2918)) { ctx.r3.u64 = container; __imp__sub_823D2918(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823D2918);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)container);
	STORE32(stack + 80, (uint32_t)container);
	uint32_t headNode = LOAD32((uint32_t)container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_DestroyRange_823D3080(ctx, base, (int64_t)(uint64_t)stack + 88, container, beginPair, endPair);
	headNode = LOAD32((uint32_t)container + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)container + 4, 0u);
	STORE32((uint32_t)container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823D2918, 0x823D2918) { ctx.r3.u64 = List_Destructor_823D2918(ctx, base, ctx.r3.u64); }

uint64_t List_DestroyGlobal_83497840(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83497840 = int32_t(0x83497840);
	if (!UseLiftedCode(21, 0x823D2B90)) { __imp__sub_823D2B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823D2B90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_83497840;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_DestroyRange_823D4030(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823D2B90, 0x823D2B90) { ctx.r3.u64 = List_DestroyGlobal_83497840(ctx, base); }

uint32_t List_Destructor_823D2D70(CpuState& ctx, uint8_t* base, uint64_t container) {
	if (!UseLiftedCode(21, 0x823D2D70)) { ctx.r3.u64 = container; __imp__sub_823D2D70(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823D2D70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)container);
	STORE32(stack + 80, (uint32_t)container);
	uint32_t headNode = LOAD32((uint32_t)container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_DestroyRange_823D46F8(ctx, base, (int64_t)(uint64_t)stack + 88, container, beginPair, endPair);
	headNode = LOAD32((uint32_t)container + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)container + 4, 0u);
	STORE32((uint32_t)container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(21, sub_823D2D70, 0x823D2D70) { ctx.r3.u64 = List_Destructor_823D2D70(ctx, base, ctx.r3.u64); }

uint64_t LuaTrampoline_InvokeEntityInt4FloatsBool(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(21, 0x823DB0E8)) { ctx.r3.u64 = luaState; __imp__sub_823DB0E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823DB0E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return LuaInvoke_Entity_Int4FloatsBool(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(21, sub_823DB0E8, 0x823DB0E8) { ctx.r3.u64 = LuaTrampoline_InvokeEntityInt4FloatsBool(ctx, base, ctx.r3.u64); }

void CECVaulting_SetField6D(CpuState& ctx, uint8_t* base, uint32_t vaulting, uint32_t value) {
	if (!UseLiftedCode(22, 0x823E2538)) { ctx.r3.u64 = vaulting; ctx.r4.u64 = value; __imp__sub_823E2538(ctx, base); return; }
	LiftedFrame frame(0x823E2538);
	STORE8(vaulting + 109, (uint8_t)value);
}
PROMOTED_ENTRY(22, sub_823E2538, 0x823E2538) { CECVaulting_SetField6D(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t Entity_IsBit26Set(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(22, 0x823ECC00)) { ctx.r4.u64 = entity; __imp__sub_823ECC00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823ECC00);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 52) >> 26) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(22, sub_823ECC00, 0x823ECC00) { ctx.r3.u64 = Entity_IsBit26Set(ctx, base, ctx.r4.u32); }

uint64_t List_DestroyGlobal_83497870(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83497870 = int32_t(0x83497870);
	if (!UseLiftedCode(22, 0x823F4870)) { __imp__sub_823F4870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F4870);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_83497870;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_DestroyRange_823F5210(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(22, sub_823F4870, 0x823F4870) { ctx.r3.u64 = List_DestroyGlobal_83497870(ctx, base); }

uint32_t List_Destructor_82413C40(CpuState& ctx, uint8_t* base, uint64_t container) {
	if (!UseLiftedCode(23, 0x82413C40)) { ctx.r3.u64 = container; __imp__sub_82413C40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82413C40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)container);
	STORE32(stack + 80, (uint32_t)container);
	uint32_t headNode = LOAD32((uint32_t)container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_DestroyRange_82414140(ctx, base, (int64_t)(uint64_t)stack + 88, container, beginPair, endPair);
	headNode = LOAD32((uint32_t)container + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)container + 4, 0u);
	STORE32((uint32_t)container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(23, sub_82413C40, 0x82413C40) { ctx.r3.u64 = List_Destructor_82413C40(ctx, base, ctx.r3.u64); }

uint64_t List_DestroyGlobal_83497DA4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83497DA4 = int32_t(0x83497DA4);
	if (!UseLiftedCode(23, 0x8241C228)) { __imp__sub_8241C228(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8241C228);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_83497DA4;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_DestroyRange_8241C700(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(23, sub_8241C228, 0x8241C228) { ctx.r3.u64 = List_DestroyGlobal_83497DA4(ctx, base); }

void SetByteAt70(CpuState& ctx, uint8_t* base, uint32_t targetObject, uint32_t value) {
	if (!UseLiftedCode(24, 0x8241F1A0)) { ctx.r3.u64 = targetObject; ctx.r4.u64 = value; __imp__sub_8241F1A0(ctx, base); return; }
	LiftedFrame frame(0x8241F1A0);
	STORE8(targetObject + 70, (uint8_t)value);
}
PROMOTED_ENTRY(24, sub_8241F1A0, 0x8241F1A0) { SetByteAt70(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t LuaTrampoline_82421EC0(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(24, 0x82421C18)) { ctx.r3.u64 = luaState; __imp__sub_82421C18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82421C18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return LuaInvokeUserdataMethod_82421EC0(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(24, sub_82421C18, 0x82421C18) { ctx.r3.u64 = LuaTrampoline_82421EC0(ctx, base, ctx.r3.u64); }

uint64_t LuaTrampoline_82421F98(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(24, 0x82421C50)) { ctx.r3.u64 = luaState; __imp__sub_82421C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82421C50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return LuaInvokeUserdataMethod_82421F98(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(24, sub_82421C50, 0x82421C50) { ctx.r3.u64 = LuaTrampoline_82421F98(ctx, base, ctx.r3.u64); }

uint64_t LuaTrampoline_82422900(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(24, 0x82422858)) { ctx.r3.u64 = luaState; __imp__sub_82422858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82422858);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return LuaInvokeUserdataMethod_82422900(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(24, sub_82422858, 0x82422858) { ctx.r3.u64 = LuaTrampoline_82422900(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8242FCF8(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82430C98 = int32_t(0x82430C98);
	if (!UseLiftedCode(24, 0x8242FCF8)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8242FCF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242FCF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82430C98, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(24, sub_8242FCF8, 0x8242FCF8) { ctx.r3.u64 = n_sub_8242FCF8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8242FEC0(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82430E48 = int32_t(0x82430E48);
	if (!UseLiftedCode(24, 0x8242FEC0)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8242FEC0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242FEC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82430E48, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(24, sub_8242FEC0, 0x8242FEC0) { ctx.r3.u64 = n_sub_8242FEC0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8242FF58(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82431018 = int32_t(0x82431018);
	if (!UseLiftedCode(24, 0x8242FF58)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8242FF58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242FF58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82431018, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(24, sub_8242FF58, 0x8242FF58) { ctx.r3.u64 = n_sub_8242FF58(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8242FFF0(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82430ED8 = int32_t(0x82430ED8);
	if (!UseLiftedCode(24, 0x8242FFF0)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8242FFF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242FFF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82430ED8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(24, sub_8242FFF0, 0x8242FFF0) { ctx.r3.u64 = n_sub_8242FFF0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_82430088(CpuState& ctx, uint8_t* base, uint32_t luaBinding, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_824310A0 = int32_t(0x824310A0);
	if (!UseLiftedCode(24, 0x82430088)) { ctx.r3.u64 = luaBinding; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82430088(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82430088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaBinding;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_824310A0, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaBinding = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaBinding;
}
PROMOTED_ENTRY(24, sub_82430088, 0x82430088) { ctx.r3.u64 = n_sub_82430088(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t LuaBinding_SetUserdataField(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_824311B8 = int32_t(0x824311B8);
	if (!UseLiftedCode(24, 0x82430120)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82430120(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82430120);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_824311B8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(24, sub_82430120, 0x82430120) { ctx.r3.u64 = LuaBinding_SetUserdataField(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t LuaBinding_SetUserdataField_824301B8(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82430F68 = int32_t(0x82430F68);
	if (!UseLiftedCode(24, 0x824301B8)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_824301B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824301B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82430F68, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(24, sub_824301B8, 0x824301B8) { ctx.r3.u64 = LuaBinding_SetUserdataField_824301B8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t LuaBinding_SetUserdataField_82430250(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82431338 = int32_t(0x82431338);
	if (!UseLiftedCode(24, 0x82430250)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82430250(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82430250);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82431338, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(24, sub_82430250, 0x82430250) { ctx.r3.u64 = LuaBinding_SetUserdataField_82430250(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t LuaBinding_SetUserdataField_824302E8(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_824313D8 = int32_t(0x824313D8);
	if (!UseLiftedCode(24, 0x824302E8)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_824302E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824302E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_824313D8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(24, sub_824302E8, 0x824302E8) { ctx.r3.u64 = LuaBinding_SetUserdataField_824302E8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t GetFlag36Bit20(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(25, 0x8243DCD8)) { ctx.r4.u64 = entity; __imp__sub_8243DCD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8243DCD8);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 36) >> 20) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(25, sub_8243DCD8, 0x8243DCD8) { ctx.r3.u64 = GetFlag36Bit20(ctx, base, ctx.r4.u32); }

uint32_t LinkedList_Destroy_82442A10(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(25, 0x82442A10)) { ctx.r3.u64 = list; __imp__sub_82442A10(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82442A10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_82442A10, 0x82442A10) { ctx.r3.u64 = LinkedList_Destroy_82442A10(ctx, base, ctx.r3.u64); }

uint64_t GetFlag44Bit23(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(25, 0x82446C60)) { ctx.r4.u64 = entity; __imp__sub_82446C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82446C60);
	uint64_t result = 0;
	if (entity != 0) {
		uint32_t componentFlag = LOAD8(entity + 144) & 64;
		if (componentFlag != 0) {
			result = (LOAD32(entity + 44) >> 23) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(25, sub_82446C60, 0x82446C60) { ctx.r3.u64 = GetFlag44Bit23(ctx, base, ctx.r4.u32); }

uint64_t LuaTrampoline_82447D08(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(25, 0x82447BB0)) { ctx.r3.u64 = luaState; __imp__sub_82447BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82447BB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return LuaInvokeUserdataMethod_82447D08(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(25, sub_82447BB0, 0x82447BB0) { ctx.r3.u64 = LuaTrampoline_82447D08(ctx, base, ctx.r3.u64); }

uint64_t LuaUserdata_Invoke_82447BE8(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(25, 0x82447BE8)) { ctx.r3.u64 = luaState; __imp__sub_82447BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82447BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_82447DF0(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(25, sub_82447BE8, 0x82447BE8) { ctx.r3.u64 = LuaUserdata_Invoke_82447BE8(ctx, base, ctx.r3.u64); }

uint64_t IsObjectBit52_3Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(25, 0x82454B50)) { ctx.r4.u64 = object; __imp__sub_82454B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82454B50);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 52) >> 3) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(25, sub_82454B50, 0x82454B50) { ctx.r3.u64 = IsObjectBit52_3Set(ctx, base, ctx.r4.u32); }

uint64_t LuaUserdata_Invoke_82455B30(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(25, 0x82455B30)) { ctx.r3.u64 = luaState; __imp__sub_82455B30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82455B30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_82455C88(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(25, sub_82455B30, 0x82455B30) { ctx.r3.u64 = LuaUserdata_Invoke_82455B30(ctx, base, ctx.r3.u64); }

uint64_t LuaUserdata_Invoke_82455B68(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(25, 0x82455B68)) { ctx.r3.u64 = luaState; __imp__sub_82455B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82455B68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_82455D60(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(25, sub_82455B68, 0x82455B68) { ctx.r3.u64 = LuaUserdata_Invoke_82455B68(ctx, base, ctx.r3.u64); }

uint64_t IsObjectBit44_30Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(25, 0x8245B220)) { ctx.r4.u64 = object; __imp__sub_8245B220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8245B220);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 44) >> 30) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(25, sub_8245B220, 0x8245B220) { ctx.r3.u64 = IsObjectBit44_30Set(ctx, base, ctx.r4.u32); }

uint32_t LinkedList_Destroy_8246CDB8(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(26, 0x8246CDB8)) { ctx.r3.u64 = list; __imp__sub_8246CDB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8246CDB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_8246F268(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(26, sub_8246CDB8, 0x8246CDB8) { ctx.r3.u64 = LinkedList_Destroy_8246CDB8(ctx, base, ctx.r3.u64); }

uint64_t IsObjectBit36_17Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(26, 0x82471940)) { ctx.r4.u64 = object; __imp__sub_82471940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82471940);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 36) >> 17) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(26, sub_82471940, 0x82471940) { ctx.r3.u64 = IsObjectBit36_17Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit44_21Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(27, 0x82481AD8)) { ctx.r4.u64 = object; __imp__sub_82481AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82481AD8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 44) >> 21) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(27, sub_82481AD8, 0x82481AD8) { ctx.r3.u64 = IsObjectBit44_21Set(ctx, base, ctx.r4.u32); }

uint32_t LuaBinding_SetUserdataField_824894F0(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82489FB8 = int32_t(0x82489FB8);
	if (!UseLiftedCode(27, 0x824894F0)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_824894F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824894F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82489FB8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(27, sub_824894F0, 0x824894F0) { ctx.r3.u64 = LuaBinding_SetUserdataField_824894F0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t IsObjectBit48_20Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(27, 0x8248CF28)) { ctx.r4.u64 = object; __imp__sub_8248CF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8248CF28);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 48) >> 20) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(27, sub_8248CF28, 0x8248CF28) { ctx.r3.u64 = IsObjectBit48_20Set(ctx, base, ctx.r4.u32); }

uint64_t Lua_Stats_GetWarriorBaseCombatMultiplier(CpuState& ctx, uint8_t* base, uint64_t stats) {
	if (!UseLiftedCode(28, 0x8249E160)) { ctx.r3.u64 = stats; __imp__sub_8249E160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8249E160);
	uint64_t warriorBaseCombatMultiplier{};
	warriorBaseCombatMultiplier = Stats_GetWarriorBaseCombatMultiplier(ctx, base, stats);
	return warriorBaseCombatMultiplier;
}
PROMOTED_ENTRY(28, sub_8249E160, 0x8249E160) { ctx.r3.u64 = Lua_Stats_GetWarriorBaseCombatMultiplier(ctx, base, ctx.r3.u64); }

// sub_824AAAA0  [8 bytes]
uint32_t ReturnTrue(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(28, 0x824AAAA0)) { __imp__sub_824AAAA0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824AAAA0);
	return 1;
}
PROMOTED_ENTRY(28, sub_824AAAA0, 0x824AAAA0) { ctx.r3.u64 = ReturnTrue(ctx, base); }

void Lua_Stats_DEBUG_SetAsCollectorsEdition(CpuState& ctx, uint8_t* base, uint32_t stats, uint32_t isCollectorsEdition) {
	if (!UseLiftedCode(28, 0x824ACAE8)) { ctx.r3.u64 = stats; ctx.r4.u64 = isCollectorsEdition; __imp__sub_824ACAE8(ctx, base); return; }
	LiftedFrame frame(0x824ACAE8);
	STORE8(stats + 993, (uint8_t)isCollectorsEdition);
	return;
}
PROMOTED_ENTRY(28, sub_824ACAE8, 0x824ACAE8) { Lua_Stats_DEBUG_SetAsCollectorsEdition(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t IntrusiveList_DestroyC(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(28, 0x824AE560)) { ctx.r3.u64 = list; __imp__sub_824AE560(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824AE560);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_824AF338(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(28, sub_824AE560, 0x824AE560) { ctx.r3.u64 = IntrusiveList_DestroyC(ctx, base, ctx.r3.u64); }

void Lua_PhysicsCharacter_SetUseSliding(CpuState& ctx, uint8_t* base, uint32_t physicsCharacter, uint32_t isSlidingEnabled) {
	if (!UseLiftedCode(29, 0x824C38E8)) { ctx.r3.u64 = physicsCharacter; ctx.r4.u64 = isSlidingEnabled; __imp__sub_824C38E8(ctx, base); return; }
	LiftedFrame frame(0x824C38E8);
	STORE8(physicsCharacter + 216, (uint8_t)isSlidingEnabled);
	return;
}
PROMOTED_ENTRY(29, sub_824C38E8, 0x824C38E8) { Lua_PhysicsCharacter_SetUseSliding(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_PhysicsCharacter_SetForceCharactersToUseFullPhysicsWhenPushed(CpuState& ctx, uint8_t* base, uint32_t physicsCharacter, uint32_t isForced) {
	if (!UseLiftedCode(29, 0x824C38F0)) { ctx.r3.u64 = physicsCharacter; ctx.r4.u64 = isForced; __imp__sub_824C38F0(ctx, base); return; }
	LiftedFrame frame(0x824C38F0);
	STORE8(physicsCharacter + 269, (uint8_t)isForced);
	return;
}
PROMOTED_ENTRY(29, sub_824C38F0, 0x824C38F0) { Lua_PhysicsCharacter_SetForceCharactersToUseFullPhysicsWhenPushed(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_PhysicsCharacter_SetUseImpassability(CpuState& ctx, uint8_t* base, uint32_t physicsCharacter, uint32_t isImpassabilityEnabled) {
	if (!UseLiftedCode(29, 0x824C6408)) { ctx.r3.u64 = physicsCharacter; ctx.r4.u64 = isImpassabilityEnabled; __imp__sub_824C6408(ctx, base); return; }
	LiftedFrame frame(0x824C6408);
	STORE8(physicsCharacter + 168, (uint8_t)isImpassabilityEnabled);
	return;
}
PROMOTED_ENTRY(29, sub_824C6408, 0x824C6408) { Lua_PhysicsCharacter_SetUseImpassability(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t LuaUserdata_Invoke_824D23F0(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(29, 0x824D23F0)) { ctx.r3.u64 = luaState; __imp__sub_824D23F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824D23F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_824D25B0(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(29, sub_824D23F0, 0x824D23F0) { ctx.r3.u64 = LuaUserdata_Invoke_824D23F0(ctx, base, ctx.r3.u64); }

void n_sub_824D45D0(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(29, 0x824D45D0)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_824D45D0(ctx, base); return; }
	LiftedFrame frame(0x824D45D0);
	STORE8(object + 660, (uint8_t)value);
}
PROMOTED_ENTRY(29, sub_824D45D0, 0x824D45D0) { n_sub_824D45D0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t LuaBinding_SetUserdataField_824E21D0(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_824E2BB0 = int32_t(0x824E2BB0);
	if (!UseLiftedCode(30, 0x824E21D0)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_824E21D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824E21D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_824E2BB0, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(30, sub_824E21D0, 0x824E21D0) { ctx.r3.u64 = LuaBinding_SetUserdataField_824E21D0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t IsObjectBit56_2Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(30, 0x824E2590)) { ctx.r4.u64 = object; __imp__sub_824E2590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824E2590);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 56) >> 2) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(30, sub_824E2590, 0x824E2590) { ctx.r3.u64 = IsObjectBit56_2Set(ctx, base, ctx.r4.u32); }

void n_sub_824EC748(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(30, 0x824EC748)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_824EC748(ctx, base); return; }
	LiftedFrame frame(0x824EC748);
	STORE8(object + 2093, (uint8_t)value);
}
PROMOTED_ENTRY(30, sub_824EC748, 0x824EC748) { n_sub_824EC748(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t IsObjectBit48_23Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(31, 0x824F68C8)) { ctx.r4.u64 = object; __imp__sub_824F68C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824F68C8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 48) >> 23) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(31, sub_824F68C8, 0x824F68C8) { ctx.r3.u64 = IsObjectBit48_23Set(ctx, base, ctx.r4.u32); }

uint64_t LuaUserdata_Invoke_824F7140(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(31, 0x824F7140)) { ctx.r3.u64 = luaState; __imp__sub_824F7140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824F7140);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_824F72C8(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(31, sub_824F7140, 0x824F7140) { ctx.r3.u64 = LuaUserdata_Invoke_824F7140(ctx, base, ctx.r3.u64); }

uint64_t IsObjectBit36_22Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(31, 0x82513880)) { ctx.r4.u64 = object; __imp__sub_82513880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82513880);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 36) >> 22) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(31, sub_82513880, 0x82513880) { ctx.r3.u64 = IsObjectBit36_22Set(ctx, base, ctx.r4.u32); }

uint32_t LinkedList_Destroy_82517EF0(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(32, 0x82517EF0)) { ctx.r3.u64 = list; __imp__sub_82517EF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82517EF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_82518198(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82517EF0, 0x82517EF0) { ctx.r3.u64 = LinkedList_Destroy_82517EF0(ctx, base, ctx.r3.u64); }

uint64_t IsObjectBit36_19Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(32, 0x82518EA8)) { ctx.r4.u64 = object; __imp__sub_82518EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82518EA8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 36) >> 19) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(32, sub_82518EA8, 0x82518EA8) { ctx.r3.u64 = IsObjectBit36_19Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit56_4Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(32, 0x8251ECD8)) { ctx.r4.u64 = object; __imp__sub_8251ECD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8251ECD8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 56) >> 4) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(32, sub_8251ECD8, 0x8251ECD8) { ctx.r3.u64 = IsObjectBit56_4Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit52_6Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(32, 0x825272C0)) { ctx.r4.u64 = object; __imp__sub_825272C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825272C0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 52) >> 6) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(32, sub_825272C0, 0x825272C0) { ctx.r3.u64 = IsObjectBit52_6Set(ctx, base, ctx.r4.u32); }

uint64_t LuaUserdata_Invoke_82527898(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(32, 0x82527898)) { ctx.r3.u64 = luaState; __imp__sub_82527898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82527898);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_825278D0(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(32, sub_82527898, 0x82527898) { ctx.r3.u64 = LuaUserdata_Invoke_82527898(ctx, base, ctx.r3.u64); }

uint64_t IsObjectBit44_12Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(32, 0x8252CF38)) { ctx.r4.u64 = object; __imp__sub_8252CF38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252CF38);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 44) >> 12) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(32, sub_8252CF38, 0x8252CF38) { ctx.r3.u64 = IsObjectBit44_12Set(ctx, base, ctx.r4.u32); }

void Lua_Breakable_SetKillPieces(CpuState& ctx, uint8_t* base, uint32_t breakable, uint32_t shouldKillPieces) {
	if (!UseLiftedCode(32, 0x82530DE0)) { ctx.r3.u64 = breakable; ctx.r4.u64 = shouldKillPieces; __imp__sub_82530DE0(ctx, base); return; }
	LiftedFrame frame(0x82530DE0);
	STORE8(breakable + 125, (uint8_t)shouldKillPieces);
	return;
}
PROMOTED_ENTRY(32, sub_82530DE0, 0x82530DE0) { Lua_Breakable_SetKillPieces(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Breakable_SetBreakOnCollide(CpuState& ctx, uint8_t* base, uint32_t breakable, uint32_t shouldBreakOnCollide) {
	if (!UseLiftedCode(32, 0x825320E8)) { ctx.r3.u64 = breakable; ctx.r4.u64 = shouldBreakOnCollide; __imp__sub_825320E8(ctx, base); return; }
	LiftedFrame frame(0x825320E8);
	STORE8(breakable + 172, (uint8_t)shouldBreakOnCollide);
	return;
}
PROMOTED_ENTRY(32, sub_825320E8, 0x825320E8) { Lua_Breakable_SetBreakOnCollide(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t IsObjectBit40_5Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(32, 0x82533230)) { ctx.r4.u64 = object; __imp__sub_82533230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82533230);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 40) >> 5) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(32, sub_82533230, 0x82533230) { ctx.r3.u64 = IsObjectBit40_5Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit40_18Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(33, 0x82539C00)) { ctx.r4.u64 = object; __imp__sub_82539C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82539C00);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 40) >> 18) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(33, sub_82539C00, 0x82539C00) { ctx.r3.u64 = IsObjectBit40_18Set(ctx, base, ctx.r4.u32); }

uint32_t LuaBinding_SetUserdataField_8253CEB0(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_827F0160 = int32_t(0x827F0160);
	if (!UseLiftedCode(33, 0x8253CEB0)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8253CEB0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8253CEB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_827F0160, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(33, sub_8253CEB0, 0x8253CEB0) { ctx.r3.u64 = LuaBinding_SetUserdataField_8253CEB0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t IsObjectBit40_8Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(33, 0x8253F058)) { ctx.r4.u64 = object; __imp__sub_8253F058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253F058);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 40) >> 8) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(33, sub_8253F058, 0x8253F058) { ctx.r3.u64 = IsObjectBit40_8Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit52_5Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(33, 0x82542048)) { ctx.r4.u64 = object; __imp__sub_82542048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82542048);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 52) >> 5) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(33, sub_82542048, 0x82542048) { ctx.r3.u64 = IsObjectBit52_5Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit36_7Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(33, 0x825439E8)) { ctx.r4.u64 = object; __imp__sub_825439E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825439E8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 36) >> 7) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(33, sub_825439E8, 0x825439E8) { ctx.r3.u64 = IsObjectBit36_7Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit44_18Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(33, 0x825467A0)) { ctx.r4.u64 = object; __imp__sub_825467A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825467A0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 44) >> 18) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(33, sub_825467A0, 0x825467A0) { ctx.r3.u64 = IsObjectBit44_18Set(ctx, base, ctx.r4.u32); }

void n_sub_82546998(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(33, 0x82546998)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82546998(ctx, base); return; }
	LiftedFrame frame(0x82546998);
	STORE8(object + 202, (uint8_t)value);
}
PROMOTED_ENTRY(33, sub_82546998, 0x82546998) { n_sub_82546998(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82548210(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(33, 0x82548210)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82548210(ctx, base); return; }
	LiftedFrame frame(0x82548210);
	STORE8(object + 198, (uint8_t)value);
}
PROMOTED_ENTRY(33, sub_82548210, 0x82548210) { n_sub_82548210(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t IsObjectBit36_3Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(33, 0x8254C450)) { ctx.r4.u64 = object; __imp__sub_8254C450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8254C450);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 36) >> 3) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(33, sub_8254C450, 0x8254C450) { ctx.r3.u64 = IsObjectBit36_3Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit36_8Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(34, 0x82560378)) { ctx.r4.u64 = object; __imp__sub_82560378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82560378);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 36) >> 8) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(34, sub_82560378, 0x82560378) { ctx.r3.u64 = IsObjectBit36_8Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit44_4Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(34, 0x82562CE0)) { ctx.r4.u64 = object; __imp__sub_82562CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82562CE0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 44) >> 4) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(34, sub_82562CE0, 0x82562CE0) { ctx.r3.u64 = IsObjectBit44_4Set(ctx, base, ctx.r4.u32); }

uint64_t IsObjectBit52_30Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(34, 0x82569660)) { ctx.r4.u64 = object; __imp__sub_82569660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82569660);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 52) >> 30) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(34, sub_82569660, 0x82569660) { ctx.r3.u64 = IsObjectBit52_30Set(ctx, base, ctx.r4.u32); }

uint64_t FindType2Component(CpuState& ctx, uint8_t* base, uint32_t gameObject, uint32_t componentOut) {
	if (!UseLiftedCode(35, 0x82577A30)) { ctx.r3.u64 = gameObject; ctx.r4.u64 = componentOut; __imp__sub_82577A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82577A30);
	uint32_t foundComponent{};
	uint32_t found{};
	uint32_t notFound{};
	uint32_t componentType{};
	GameStackFrame stackFrame(ctx, base, 96);
	componentType = 2;
	foundComponent = GameObject_FindComponentByType(ctx, base, gameObject, componentType);
	if (foundComponent != 0) {
		STORE32(componentOut, foundComponent);
		found = 1;
		return found;
	}
	notFound = 0;
	return notFound;
}
PROMOTED_ENTRY(35, sub_82577A30, 0x82577A30) { ctx.r3.u64 = FindType2Component(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t IsObjectBit36_15Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(35, 0x82579AC8)) { ctx.r4.u64 = object; __imp__sub_82579AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82579AC8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 36) >> 15) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(35, sub_82579AC8, 0x82579AC8) { ctx.r3.u64 = IsObjectBit36_15Set(ctx, base, ctx.r4.u32); }

uint64_t LuaUserdata_Invoke_8257A9F8(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(35, 0x8257A9F8)) { ctx.r3.u64 = luaState; __imp__sub_8257A9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8257A9F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_8257AA30(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(35, sub_8257A9F8, 0x8257A9F8) { ctx.r3.u64 = LuaUserdata_Invoke_8257A9F8(ctx, base, ctx.r3.u64); }

uint32_t ReturnFalse_8259FF68(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(36, 0x8259FF68)) { __imp__sub_8259FF68(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8259FF68);
	return 0;
}
PROMOTED_ENTRY(36, sub_8259FF68, 0x8259FF68) { ctx.r3.u64 = ReturnFalse_8259FF68(ctx, base); }

uint32_t StdMap_ClearAndFreeHead(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(36, 0x825A52B0)) { ctx.r3.u64 = list; __imp__sub_825A52B0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A52B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_825A5318(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(36, sub_825A52B0, 0x825A52B0) { ctx.r3.u64 = StdMap_ClearAndFreeHead(ctx, base, ctx.r3.u64); }

uint32_t ReturnFalse_825A8334(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(36, 0x825A8334)) { __imp__sub_825A8334(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A8334);
	return 0;
}
PROMOTED_ENTRY(36, sub_825A8334, 0x825A8334) { ctx.r3.u64 = ReturnFalse_825A8334(ctx, base); }

uint32_t ReturnFalse_825A83AC(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(36, 0x825A83AC)) { __imp__sub_825A83AC(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A83AC);
	return 0;
}
PROMOTED_ENTRY(36, sub_825A83AC, 0x825A83AC) { ctx.r3.u64 = ReturnFalse_825A83AC(ctx, base); }

void n_sub_825B2B60(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(37, 0x825B2B60)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825B2B60(ctx, base); return; }
	LiftedFrame frame(0x825B2B60);
	STORE8(object + 384, (uint8_t)value);
}
PROMOTED_ENTRY(37, sub_825B2B60, 0x825B2B60) { n_sub_825B2B60(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825B2B68(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(37, 0x825B2B68)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825B2B68(ctx, base); return; }
	LiftedFrame frame(0x825B2B68);
	STORE8(object + 385, (uint8_t)value);
}
PROMOTED_ENTRY(37, sub_825B2B68, 0x825B2B68) { n_sub_825B2B68(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825B2B70(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(37, 0x825B2B70)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825B2B70(ctx, base); return; }
	LiftedFrame frame(0x825B2B70);
	STORE8(object + 388, (uint8_t)value);
}
PROMOTED_ENTRY(37, sub_825B2B70, 0x825B2B70) { n_sub_825B2B70(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825B2B78(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(37, 0x825B2B78)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825B2B78(ctx, base); return; }
	LiftedFrame frame(0x825B2B78);
	STORE8(object + 386, (uint8_t)value);
}
PROMOTED_ENTRY(37, sub_825B2B78, 0x825B2B78) { n_sub_825B2B78(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825B2B80(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(37, 0x825B2B80)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825B2B80(ctx, base); return; }
	LiftedFrame frame(0x825B2B80);
	STORE8(object + 387, (uint8_t)value);
}
PROMOTED_ENTRY(37, sub_825B2B80, 0x825B2B80) { n_sub_825B2B80(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t IsObjectBit48_1Set(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(37, 0x825B41C8)) { ctx.r4.u64 = object; __imp__sub_825B41C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825B41C8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t validFlag = LOAD8(object + 144) & 64;
		if (validFlag != 0) {
			result = (LOAD32(object + 48) >> 1) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(37, sub_825B41C8, 0x825B41C8) { ctx.r3.u64 = IsObjectBit48_1Set(ctx, base, ctx.r4.u32); }

uint32_t LinkedList_Destroy_825B5180(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(37, 0x825B5180)) { ctx.r3.u64 = list; __imp__sub_825B5180(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825B5180);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_825B66E0(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(37, sub_825B5180, 0x825B5180) { ctx.r3.u64 = LinkedList_Destroy_825B5180(ctx, base, ctx.r3.u64); }

uint32_t LuaBinding_SetUserdataField_825BEA60(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8290B4F0 = int32_t(0x8290B4F0);
	if (!UseLiftedCode(37, 0x825BEA60)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825BEA60(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825BEA60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8290B4F0, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(37, sub_825BEA60, 0x825BEA60) { ctx.r3.u64 = LuaBinding_SetUserdataField_825BEA60(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t LuaBinding_SetUserdataField_825BEAF8(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82227750 = int32_t(0x82227750);
	if (!UseLiftedCode(37, 0x825BEAF8)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825BEAF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825BEAF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82227750, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(37, sub_825BEAF8, 0x825BEAF8) { ctx.r3.u64 = LuaBinding_SetUserdataField_825BEAF8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t LuaBinding_SetUserdataField_825BEB90(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8290B570 = int32_t(0x8290B570);
	if (!UseLiftedCode(37, 0x825BEB90)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825BEB90(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825BEB90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8290B570, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(37, sub_825BEB90, 0x825BEB90) { ctx.r3.u64 = LuaBinding_SetUserdataField_825BEB90(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t LuaBinding_SetUserdataField_825BEC28(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldKey, uint32_t value, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_827FA2A0 = int32_t(0x827FA2A0);
	if (!UseLiftedCode(37, 0x825BEC28)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldKey; ctx.r5.u64 = value; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825BEC28(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825BEC28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, value);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_827FA2A0, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldKey, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldKey);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(37, sub_825BEC28, 0x825BEC28) { ctx.r3.u64 = LuaBinding_SetUserdataField_825BEC28(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_825CBC18(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_825CC0C8 = int32_t(0x825CC0C8);
	if (!UseLiftedCode(37, 0x825CBC18)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825CBC18(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825CBC18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_825CC0C8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(37, sub_825CBC18, 0x825CBC18) { ctx.r3.u64 = n_sub_825CBC18(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_825CBCB0(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_825CC150 = int32_t(0x825CC150);
	if (!UseLiftedCode(37, 0x825CBCB0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825CBCB0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825CBCB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_825CC150, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(37, sub_825CBCB0, 0x825CBCB0) { ctx.r3.u64 = n_sub_825CBCB0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_825CBD48(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_825CC1E8 = int32_t(0x825CC1E8);
	if (!UseLiftedCode(37, 0x825CBD48)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825CBD48(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825CBD48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_825CC1E8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(37, sub_825CBD48, 0x825CBD48) { ctx.r3.u64 = n_sub_825CBD48(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_825CBDE0(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_825CC2A8 = int32_t(0x825CC2A8);
	if (!UseLiftedCode(37, 0x825CBDE0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_825CBDE0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825CBDE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_825CC2A8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(37, sub_825CBDE0, 0x825CBDE0) { ctx.r3.u64 = n_sub_825CBDE0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

void n_sub_825DA308(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(38, 0x825DA308)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825DA308(ctx, base); return; }
	LiftedFrame frame(0x825DA308);
	STORE8(object + 313, (uint8_t)value);
}
PROMOTED_ENTRY(38, sub_825DA308, 0x825DA308) { n_sub_825DA308(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825DA328(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(38, 0x825DA328)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825DA328(ctx, base); return; }
	LiftedFrame frame(0x825DA328);
	STORE8(object + 317, (uint8_t)value);
}
PROMOTED_ENTRY(38, sub_825DA328, 0x825DA328) { n_sub_825DA328(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825DE440(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(38, 0x825DE440)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825DE440(ctx, base); return; }
	LiftedFrame frame(0x825DE440);
	STORE8(object + 272, (uint8_t)value);
}
PROMOTED_ENTRY(38, sub_825DE440, 0x825DE440) { n_sub_825DE440(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825DFF10(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(38, 0x825DFF10)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825DFF10(ctx, base); return; }
	LiftedFrame frame(0x825DFF10);
	STORE8(object + 274, (uint8_t)value);
}
PROMOTED_ENTRY(38, sub_825DFF10, 0x825DFF10) { n_sub_825DFF10(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_825E2C18(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(38, 0x825E2C18)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_825E2C18(ctx, base); return; }
	LiftedFrame frame(0x825E2C18);
	STORE8(object + 312, (uint8_t)value);
}
PROMOTED_ENTRY(38, sub_825E2C18, 0x825E2C18) { n_sub_825E2C18(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_825E9330(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(38, 0x825E9330)) { ctx.r4.u64 = object; __imp__sub_825E9330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825E9330);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 44) >> 1) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(38, sub_825E9330, 0x825E9330) { ctx.r3.u64 = n_sub_825E9330(ctx, base, ctx.r4.u32); }

uint64_t Lua_CallUserdataMethod_825EC5A0(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(38, 0x825EC5A0)) { ctx.r3.u64 = luaState; __imp__sub_825EC5A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EC5A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_825ED340(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(38, sub_825EC5A0, 0x825EC5A0) { ctx.r3.u64 = Lua_CallUserdataMethod_825EC5A0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_825EEF68(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(38, 0x825EEF68)) { ctx.r4.u64 = object; __imp__sub_825EEF68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825EEF68);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 56) >> 22) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(38, sub_825EEF68, 0x825EEF68) { ctx.r3.u64 = n_sub_825EEF68(ctx, base, ctx.r4.u32); }

uint64_t List_DestroyGlobal_83498F68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83498F68 = int32_t(0x83498F68);
	if (!UseLiftedCode(39, 0x825F2198)) { __imp__sub_825F2198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825F2198);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_83498F68;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_EraseRange_83498F68(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(39, sub_825F2198, 0x825F2198) { ctx.r3.u64 = List_DestroyGlobal_83498F68(ctx, base); }

uint64_t GetGlobal_834A5B6C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5B6C = int32_t(0x834A5B6C);
	if (!UseLiftedCode(39, 0x825F6AD8)) { __imp__sub_825F6AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825F6AD8);
	return g_834A5B6C;
}
PROMOTED_ENTRY(39, sub_825F6AD8, 0x825F6AD8) { ctx.r3.u64 = GetGlobal_834A5B6C(ctx, base); }

uint64_t n_sub_82604FB8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(39, 0x82604FB8)) { ctx.r4.u64 = object; __imp__sub_82604FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82604FB8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 6) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(39, sub_82604FB8, 0x82604FB8) { ctx.r3.u64 = n_sub_82604FB8(ctx, base, ctx.r4.u32); }

uint64_t Lua_CallUserdataMethod_82606B58(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(39, 0x82606B58)) { ctx.r3.u64 = luaState; __imp__sub_82606B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82606B58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_82606D48(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(39, sub_82606B58, 0x82606B58) { ctx.r3.u64 = Lua_CallUserdataMethod_82606B58(ctx, base, ctx.r3.u64); }

void Lua_Player_SetLookingDuringInteractionMode(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t lookingMode) {
	if (!UseLiftedCode(39, 0x82607258)) { ctx.r3.u64 = player; ctx.r4.u64 = lookingMode; __imp__sub_82607258(ctx, base); return; }
	LiftedFrame frame(0x82607258);
	STORE8(player + 24, (uint8_t)lookingMode);
	return;
}
PROMOTED_ENTRY(39, sub_82607258, 0x82607258) { Lua_Player_SetLookingDuringInteractionMode(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t n_sub_8260CF40(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8260D310 = int32_t(0x8260D310);
	if (!UseLiftedCode(39, 0x8260CF40)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8260CF40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8260CF40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8260D310, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(39, sub_8260CF40, 0x8260CF40) { ctx.r3.u64 = n_sub_8260CF40(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8260D020(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82229468 = int32_t(0x82229468);
	if (!UseLiftedCode(39, 0x8260D020)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8260D020(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8260D020);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82229468, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(39, sub_8260D020, 0x8260D020) { ctx.r3.u64 = n_sub_8260D020(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8260D0B8(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8222CFB8 = int32_t(0x8222CFB8);
	if (!UseLiftedCode(39, 0x8260D0B8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8260D0B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8260D0B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8222CFB8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(39, sub_8260D0B8, 0x8260D0B8) { ctx.r3.u64 = n_sub_8260D0B8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8260D150(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8223CBE8 = int32_t(0x8223CBE8);
	if (!UseLiftedCode(39, 0x8260D150)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8260D150(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8260D150);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8223CBE8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(39, sub_8260D150, 0x8260D150) { ctx.r3.u64 = n_sub_8260D150(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8260D230(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82903D68 = int32_t(0x82903D68);
	if (!UseLiftedCode(39, 0x8260D230)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8260D230(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8260D230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82903D68, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(39, sub_8260D230, 0x8260D230) { ctx.r3.u64 = n_sub_8260D230(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_82610CE8(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82610D80 = int32_t(0x82610D80);
	if (!UseLiftedCode(39, 0x82610CE8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82610CE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82610CE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82610D80, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(39, sub_82610CE8, 0x82610CE8) { ctx.r3.u64 = n_sub_82610CE8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_826142B8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(40, 0x826142B8)) { ctx.r4.u64 = object; __imp__sub_826142B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826142B8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 22) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(40, sub_826142B8, 0x826142B8) { ctx.r3.u64 = n_sub_826142B8(ctx, base, ctx.r4.u32); }

void n_sub_82614780(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(40, 0x82614780)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82614780(ctx, base); return; }
	LiftedFrame frame(0x82614780);
	STORE8(object + 76, (uint8_t)value);
}
PROMOTED_ENTRY(40, sub_82614780, 0x82614780) { n_sub_82614780(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82614788(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(40, 0x82614788)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82614788(ctx, base); return; }
	LiftedFrame frame(0x82614788);
	STORE8(object + 72, (uint8_t)value);
}
PROMOTED_ENTRY(40, sub_82614788, 0x82614788) { n_sub_82614788(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82614790(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(40, 0x82614790)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82614790(ctx, base); return; }
	LiftedFrame frame(0x82614790);
	STORE8(object + 73, (uint8_t)value);
}
PROMOTED_ENTRY(40, sub_82614790, 0x82614790) { n_sub_82614790(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82614798(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(40, 0x82614798)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82614798(ctx, base); return; }
	LiftedFrame frame(0x82614798);
	STORE8(object + 74, (uint8_t)value);
}
PROMOTED_ENTRY(40, sub_82614798, 0x82614798) { n_sub_82614798(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t Lua_Inventory_GetInitialHeroMeleeWeapon(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973D4_G_ = int32_t(0x834973D4);
	if (!UseLiftedCode(40, 0x8261C7C0)) { __imp__sub_8261C7C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8261C7C0);
	return TXT_834973D4_G_;
}
PROMOTED_ENTRY(40, sub_8261C7C0, 0x8261C7C0) { ctx.r3.u64 = Lua_Inventory_GetInitialHeroMeleeWeapon(ctx, base); }

uint64_t Lua_Inventory_GetInitialHeroRangedWeapon(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973D8_G_ = int32_t(0x834973D8);
	if (!UseLiftedCode(40, 0x8261C7D0)) { __imp__sub_8261C7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8261C7D0);
	return TXT_834973D8_G_;
}
PROMOTED_ENTRY(40, sub_8261C7D0, 0x8261C7D0) { ctx.r3.u64 = Lua_Inventory_GetInitialHeroRangedWeapon(ctx, base); }

void Lua_Player_SetSheathingUnsheathingEnabled(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isEnabled) {
	if (!UseLiftedCode(40, 0x8261CED8)) { ctx.r3.u64 = player; ctx.r4.u64 = isEnabled; __imp__sub_8261CED8(ctx, base); return; }
	LiftedFrame frame(0x8261CED8);
	STORE8(player + 27, (uint8_t)isEnabled);
	return;
}
PROMOTED_ENTRY(40, sub_8261CED8, 0x8261CED8) { Lua_Player_SetSheathingUnsheathingEnabled(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82620B08(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(40, 0x82620B08)) { ctx.r4.u64 = object; __imp__sub_82620B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82620B08);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 36) >> 13) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(40, sub_82620B08, 0x82620B08) { ctx.r3.u64 = n_sub_82620B08(ctx, base, ctx.r4.u32); }

uint64_t Lua_CallUserdataMethod_82621D40(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(40, 0x82621D40)) { ctx.r3.u64 = luaState; __imp__sub_82621D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82621D40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_82622200(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(40, sub_82621D40, 0x82621D40) { ctx.r3.u64 = Lua_CallUserdataMethod_82621D40(ctx, base, ctx.r3.u64); }

uint64_t List_DestroyGlobal_8349912C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349912C = int32_t(0x8349912C);
	if (!UseLiftedCode(40, 0x82629830)) { __imp__sub_82629830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82629830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349912C;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_EraseRange_8349912C(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_82629830, 0x82629830) { ctx.r3.u64 = List_DestroyGlobal_8349912C(ctx, base); }

uint64_t n_sub_8262B828(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(40, 0x8262B828)) { ctx.r4.u64 = object; __imp__sub_8262B828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8262B828);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 36) >> 14) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(40, sub_8262B828, 0x8262B828) { ctx.r3.u64 = n_sub_8262B828(ctx, base, ctx.r4.u32); }

uint32_t n_sub_8262D430(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8262D560 = int32_t(0x8262D560);
	if (!UseLiftedCode(40, 0x8262D430)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8262D430(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8262D430);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8262D560, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(40, sub_8262D430, 0x8262D430) { ctx.r3.u64 = n_sub_8262D430(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8262D4C8(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8262D5E8 = int32_t(0x8262D5E8);
	if (!UseLiftedCode(40, 0x8262D4C8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8262D4C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8262D4C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8262D5E8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(40, sub_8262D4C8, 0x8262D4C8) { ctx.r3.u64 = n_sub_8262D4C8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t List_DestroyGlobal_8349A09C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349A09C = int32_t(0x8349A09C);
	if (!UseLiftedCode(41, 0x8263FA78)) { __imp__sub_8263FA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8263FA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349A09C;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	List_EraseRange_8349A09C(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(41, sub_8263FA78, 0x8263FA78) { ctx.r3.u64 = List_DestroyGlobal_8349A09C(ctx, base); }

void SetByteAtOffset_BB(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(43, 0x82671610)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82671610(ctx, base); return; }
	LiftedFrame frame(0x82671610);
	STORE8(object + 187, (uint8_t)value);
}
PROMOTED_ENTRY(43, sub_82671610, 0x82671610) { SetByteAtOffset_BB(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82677908(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(43, 0x82677908)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82677908(ctx, base); return; }
	LiftedFrame frame(0x82677908);
	STORE8(object + 617, (uint8_t)value);
}
PROMOTED_ENTRY(43, sub_82677908, 0x82677908) { n_sub_82677908(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_826779A8(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(43, 0x826779A8)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_826779A8(ctx, base); return; }
	LiftedFrame frame(0x826779A8);
	STORE8(object + 644, (uint8_t)value);
}
PROMOTED_ENTRY(43, sub_826779A8, 0x826779A8) { n_sub_826779A8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t n_sub_8267BC68(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8218A838 = int32_t(0x8218A838);
	if (!UseLiftedCode(43, 0x8267BC68)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8267BC68(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8267BC68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8218A838, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(43, sub_8267BC68, 0x8267BC68) { ctx.r3.u64 = n_sub_8267BC68(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t Lua_CallUserdataMethod_8267CF80(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(43, 0x8267CF80)) { ctx.r3.u64 = luaState; __imp__sub_8267CF80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8267CF80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_8267D448(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(43, sub_8267CF80, 0x8267CF80) { ctx.r3.u64 = Lua_CallUserdataMethod_8267CF80(ctx, base, ctx.r3.u64); }

uint64_t Lua_CallUserdataMethod_8267D308(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(43, 0x8267D308)) { ctx.r3.u64 = luaState; __imp__sub_8267D308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8267D308);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_8267D658(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(43, sub_8267D308, 0x8267D308) { ctx.r3.u64 = Lua_CallUserdataMethod_8267D308(ctx, base, ctx.r3.u64); }

uint64_t List_DestroyGlobal_8349AD9C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349AD9C = int32_t(0x8349AD9C);
	if (!UseLiftedCode(43, 0x8267E478)) { __imp__sub_8267E478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8267E478);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349AD9C;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_8267E478, 0x8267E478) { ctx.r3.u64 = List_DestroyGlobal_8349AD9C(ctx, base); }

uint64_t List_DestroyGlobal_8349ADA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349ADA8 = int32_t(0x8349ADA8);
	if (!UseLiftedCode(43, 0x8267E788)) { __imp__sub_8267E788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8267E788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349ADA8;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_8267F188(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_8267E788, 0x8267E788) { ctx.r3.u64 = List_DestroyGlobal_8349ADA8(ctx, base); }

uint64_t List_DestroyGlobal_8349ADB4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349ADB4 = int32_t(0x8349ADB4);
	if (!UseLiftedCode(43, 0x82684190)) { __imp__sub_82684190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82684190);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349ADB4;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_82684818(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82684190, 0x82684190) { ctx.r3.u64 = List_DestroyGlobal_8349ADB4(ctx, base); }

uint64_t n_sub_82686288(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(43, 0x82686288)) { ctx.r4.u64 = object; __imp__sub_82686288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82686288);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 27) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(43, sub_82686288, 0x82686288) { ctx.r3.u64 = n_sub_82686288(ctx, base, ctx.r4.u32); }

uint64_t Lua_CallUserdataMethod_82686788(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(43, 0x82686788)) { ctx.r3.u64 = luaState; __imp__sub_82686788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82686788);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_826867C0(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(43, sub_82686788, 0x82686788) { ctx.r3.u64 = Lua_CallUserdataMethod_82686788(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82690F90(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(44, 0x82690F90)) { ctx.r4.u64 = object; __imp__sub_82690F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82690F90);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 4) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(44, sub_82690F90, 0x82690F90) { ctx.r3.u64 = n_sub_82690F90(ctx, base, ctx.r4.u32); }

void Lua_Player_SetWorldMapHUDSuggestionAsValid(CpuState& ctx, uint8_t* base, uint32_t player, uint32_t isValid) {
	if (!UseLiftedCode(45, 0x826B9478)) { ctx.r3.u64 = player; ctx.r4.u64 = isValid; __imp__sub_826B9478(ctx, base); return; }
	LiftedFrame frame(0x826B9478);
	STORE8(player + 36, (uint8_t)isValid);
	return;
}
PROMOTED_ENTRY(45, sub_826B9478, 0x826B9478) { Lua_Player_SetWorldMapHUDSuggestionAsValid(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t Lua_CallUserdataMethod_826BD4F0(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(45, 0x826BD4F0)) { ctx.r3.u64 = luaState; __imp__sub_826BD4F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826BD4F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_826BD560(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(45, sub_826BD4F0, 0x826BD4F0) { ctx.r3.u64 = Lua_CallUserdataMethod_826BD4F0(ctx, base, ctx.r3.u64); }

uint64_t Lua_CallUserdataMethod_826BD528(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(45, 0x826BD528)) { ctx.r3.u64 = luaState; __imp__sub_826BD528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826BD528);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_826BD680(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(45, sub_826BD528, 0x826BD528) { ctx.r3.u64 = Lua_CallUserdataMethod_826BD528(ctx, base, ctx.r3.u64); }

uint32_t LinkedList_Destroy_826EC9D8(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(47, 0x826EC9D8)) { ctx.r3.u64 = list; __imp__sub_826EC9D8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826EC9D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_826ED490(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(47, sub_826EC9D8, 0x826EC9D8) { ctx.r3.u64 = LinkedList_Destroy_826EC9D8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_826EEA40(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(47, 0x826EEA40)) { ctx.r4.u64 = object; __imp__sub_826EEA40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826EEA40);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 36) >> 18) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(47, sub_826EEA40, 0x826EEA40) { ctx.r3.u64 = n_sub_826EEA40(ctx, base, ctx.r4.u32); }

void n_sub_826F05A8(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(47, 0x826F05A8)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_826F05A8(ctx, base); return; }
	LiftedFrame frame(0x826F05A8);
	STORE8(object + 13, (uint8_t)value);
}
PROMOTED_ENTRY(47, sub_826F05A8, 0x826F05A8) { n_sub_826F05A8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_826F0F50(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(47, 0x826F0F50)) { ctx.r4.u64 = object; __imp__sub_826F0F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826F0F50);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 27) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(47, sub_826F0F50, 0x826F0F50) { ctx.r3.u64 = n_sub_826F0F50(ctx, base, ctx.r4.u32); }

uint64_t n_sub_826FC7E8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(47, 0x826FC7E8)) { ctx.r4.u64 = object; __imp__sub_826FC7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826FC7E8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 8) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(47, sub_826FC7E8, 0x826FC7E8) { ctx.r3.u64 = n_sub_826FC7E8(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82701500(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(47, 0x82701500)) { ctx.r4.u64 = object; __imp__sub_82701500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82701500);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 52) >> 12) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(47, sub_82701500, 0x82701500) { ctx.r3.u64 = n_sub_82701500(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82706308(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(47, 0x82706308)) { ctx.r4.u64 = object; __imp__sub_82706308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82706308);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 12) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(47, sub_82706308, 0x82706308) { ctx.r3.u64 = n_sub_82706308(ctx, base, ctx.r4.u32); }

uint64_t Lua_CallUserdataMethod_82706EB8(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(47, 0x82706EB8)) { ctx.r3.u64 = luaState; __imp__sub_82706EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82706EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t method = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_82706FA0(ctx, base, self, method, luaState);
}
PROMOTED_ENTRY(47, sub_82706EB8, 0x82706EB8) { ctx.r3.u64 = Lua_CallUserdataMethod_82706EB8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82723220(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(48, 0x82723220)) { ctx.r4.u64 = object; __imp__sub_82723220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82723220);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 3) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(48, sub_82723220, 0x82723220) { ctx.r3.u64 = n_sub_82723220(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82725C20(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(48, 0x82725C20)) { ctx.r4.u64 = object; __imp__sub_82725C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82725C20);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 4) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(48, sub_82725C20, 0x82725C20) { ctx.r3.u64 = n_sub_82725C20(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82729358(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(49, 0x82729358)) { ctx.r4.u64 = object; __imp__sub_82729358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82729358);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(49, sub_82729358, 0x82729358) { ctx.r3.u64 = n_sub_82729358(ctx, base, ctx.r4.u32); }

uint64_t n_sub_827384F0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(49, 0x827384F0)) { ctx.r4.u64 = object; __imp__sub_827384F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827384F0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 2) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(49, sub_827384F0, 0x827384F0) { ctx.r3.u64 = n_sub_827384F0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8273D118(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(49, 0x8273D118)) { ctx.r4.u64 = object; __imp__sub_8273D118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8273D118);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 56) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(49, sub_8273D118, 0x8273D118) { ctx.r3.u64 = n_sub_8273D118(ctx, base, ctx.r4.u32); }

uint64_t HandleList_Clear_8349B314(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349B314 = int32_t(0x8349B314);
	if (!UseLiftedCode(49, 0x8273E9A8)) { __imp__sub_8273E9A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8273E9A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349B314;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_8273EC88(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(49, sub_8273E9A8, 0x8273E9A8) { ctx.r3.u64 = HandleList_Clear_8349B314(ctx, base); }

uint64_t HandleList_Clear_8349B320(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349B320 = int32_t(0x8349B320);
	if (!UseLiftedCode(49, 0x8273EAE8)) { __imp__sub_8273EAE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8273EAE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349B320;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_8273ED78(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(49, sub_8273EAE8, 0x8273EAE8) { ctx.r3.u64 = HandleList_Clear_8349B320(ctx, base); }

uint64_t n_sub_8274AF90(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(50, 0x8274AF90)) { ctx.r4.u64 = object; __imp__sub_8274AF90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8274AF90);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 36) >> 2) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(50, sub_8274AF90, 0x8274AF90) { ctx.r3.u64 = n_sub_8274AF90(ctx, base, ctx.r4.u32); }

void n_sub_8274D148(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(50, 0x8274D148)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_8274D148(ctx, base); return; }
	LiftedFrame frame(0x8274D148);
	STORE8(object + 82, (uint8_t)value);
}
PROMOTED_ENTRY(50, sub_8274D148, 0x8274D148) { n_sub_8274D148(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82752A58(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(50, 0x82752A58)) { ctx.r4.u64 = object; __imp__sub_82752A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82752A58);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 44) >> 3) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(50, sub_82752A58, 0x82752A58) { ctx.r3.u64 = n_sub_82752A58(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82755B20(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(50, 0x82755B20)) { ctx.r4.u64 = object; __imp__sub_82755B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82755B20);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 44) >> 14) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(50, sub_82755B20, 0x82755B20) { ctx.r3.u64 = n_sub_82755B20(ctx, base, ctx.r4.u32); }

void n_sub_82755F08(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(50, 0x82755F08)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82755F08(ctx, base); return; }
	LiftedFrame frame(0x82755F08);
	STORE8(object + 783, (uint8_t)value);
}
PROMOTED_ENTRY(50, sub_82755F08, 0x82755F08) { n_sub_82755F08(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82755F10(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(50, 0x82755F10)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82755F10(ctx, base); return; }
	LiftedFrame frame(0x82755F10);
	STORE8(object + 776, (uint8_t)value);
}
PROMOTED_ENTRY(50, sub_82755F10, 0x82755F10) { n_sub_82755F10(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82755F80(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(50, 0x82755F80)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82755F80(ctx, base); return; }
	LiftedFrame frame(0x82755F80);
	STORE8(object + 774, (uint8_t)value);
}
PROMOTED_ENTRY(50, sub_82755F80, 0x82755F80) { n_sub_82755F80(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82755F90(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(50, 0x82755F90)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82755F90(ctx, base); return; }
	LiftedFrame frame(0x82755F90);
	STORE8(object + 779, (uint8_t)value);
}
PROMOTED_ENTRY(50, sub_82755F90, 0x82755F90) { n_sub_82755F90(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82755FA0(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(50, 0x82755FA0)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82755FA0(ctx, base); return; }
	LiftedFrame frame(0x82755FA0);
	STORE8(object + 775, (uint8_t)value);
}
PROMOTED_ENTRY(50, sub_82755FA0, 0x82755FA0) { n_sub_82755FA0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82777310(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(51, 0x82777310)) { ctx.r4.u64 = object; __imp__sub_82777310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82777310);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 15) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(51, sub_82777310, 0x82777310) { ctx.r3.u64 = n_sub_82777310(ctx, base, ctx.r4.u32); }

uint64_t Lua_InvokeUserdataMethod_82778668(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(51, 0x82778668)) { ctx.r3.u64 = luaState; __imp__sub_82778668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82778668);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return Lua_ExecuteUserdataMethod_82778AA8(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(51, sub_82778668, 0x82778668) { ctx.r3.u64 = Lua_InvokeUserdataMethod_82778668(ctx, base, ctx.r3.u64); }

void n_sub_82788310(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(52, 0x82788310)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_82788310(ctx, base); return; }
	LiftedFrame frame(0x82788310);
	STORE8(arg1 + 14, (uint8_t)value);
}
PROMOTED_ENTRY(52, sub_82788310, 0x82788310) { n_sub_82788310(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82788318(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(52, 0x82788318)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_82788318(ctx, base); return; }
	LiftedFrame frame(0x82788318);
	STORE8(arg1 + 17, (uint8_t)value);
}
PROMOTED_ENTRY(52, sub_82788318, 0x82788318) { n_sub_82788318(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82788970(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(52, 0x82788970)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_82788970(ctx, base); return; }
	LiftedFrame frame(0x82788970);
	STORE8(arg1 + 18, (uint8_t)value);
}
PROMOTED_ENTRY(52, sub_82788970, 0x82788970) { n_sub_82788970(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetSafetyModeSuggestable(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t isSuggestable) {
	if (!UseLiftedCode(52, 0x82788D08)) { ctx.r3.u64 = arg1; ctx.r4.u64 = isSuggestable; __imp__sub_82788D08(ctx, base); return; }
	LiftedFrame frame(0x82788D08);
	STORE8(arg1 + 26, (uint8_t)isSuggestable);
	return;
}
PROMOTED_ENTRY(52, sub_82788D08, 0x82788D08) { Lua_Player_SetSafetyModeSuggestable(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Door_SetLockedForPlayer(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t isLocked) {
	if (!UseLiftedCode(52, 0x8278B1E0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = isLocked; __imp__sub_8278B1E0(ctx, base); return; }
	LiftedFrame frame(0x8278B1E0);
	STORE8(arg1 + 34, (uint8_t)isLocked);
	return;
}
PROMOTED_ENTRY(52, sub_8278B1E0, 0x8278B1E0) { Lua_Door_SetLockedForPlayer(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Door_SetToDisplayMessageIfLocked(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t shouldDisplayMessage) {
	if (!UseLiftedCode(52, 0x8278B200)) { ctx.r3.u64 = arg1; ctx.r4.u64 = shouldDisplayMessage; __imp__sub_8278B200(ctx, base); return; }
	LiftedFrame frame(0x8278B200);
	STORE8(arg1 + 35, (uint8_t)shouldDisplayMessage);
	return;
}
PROMOTED_ENTRY(52, sub_8278B200, 0x8278B200) { Lua_Door_SetToDisplayMessageIfLocked(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetLevelUpHUDSuggestionAsAutoRemoving(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t isAutoRemoving) {
	if (!UseLiftedCode(52, 0x8278B250)) { ctx.r3.u64 = arg1; ctx.r4.u64 = isAutoRemoving; __imp__sub_8278B250(ctx, base); return; }
	LiftedFrame frame(0x8278B250);
	STORE8(arg1 + 37, (uint8_t)isAutoRemoving);
	return;
}
PROMOTED_ENTRY(52, sub_8278B250, 0x8278B250) { Lua_Player_SetLevelUpHUDSuggestionAsAutoRemoving(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetPlayerSprintingAllowed(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t isSprintingAllowed) {
	if (!UseLiftedCode(52, 0x8278B260)) { ctx.r3.u64 = arg1; ctx.r4.u64 = isSprintingAllowed; __imp__sub_8278B260(ctx, base); return; }
	LiftedFrame frame(0x8278B260);
	STORE8(arg1 + 31, (uint8_t)isSprintingAllowed);
	return;
}
PROMOTED_ENTRY(52, sub_8278B260, 0x8278B260) { Lua_Player_SetPlayerSprintingAllowed(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Door_SetCanBeKnocked(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t canBeKnocked) {
	if (!UseLiftedCode(52, 0x8278B8E8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = canBeKnocked; __imp__sub_8278B8E8(ctx, base); return; }
	LiftedFrame frame(0x8278B8E8);
	STORE8(arg1 + 41, (uint8_t)canBeKnocked);
	return;
}
PROMOTED_ENTRY(52, sub_8278B8E8, 0x8278B8E8) { Lua_Door_SetCanBeKnocked(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_8278B8F0(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(52, 0x8278B8F0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_8278B8F0(ctx, base); return; }
	LiftedFrame frame(0x8278B8F0);
	STORE8(arg1 + 38, (uint8_t)value);
}
PROMOTED_ENTRY(52, sub_8278B8F0, 0x8278B8F0) { n_sub_8278B8F0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t LinkedList_Destroy_8278BEA0(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(52, 0x8278BEA0)) { ctx.r3.u64 = list; __imp__sub_8278BEA0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8278BEA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_8278C9F0(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_8278BEA0, 0x8278BEA0) { ctx.r3.u64 = LinkedList_Destroy_8278BEA0(ctx, base, ctx.r3.u64); }

void n_sub_8279DEB8(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(52, 0x8279DEB8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_8279DEB8(ctx, base); return; }
	LiftedFrame frame(0x8279DEB8);
	STORE8(arg1 + 170, (uint8_t)value);
}
PROMOTED_ENTRY(52, sub_8279DEB8, 0x8279DEB8) { n_sub_8279DEB8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_8279DEC8(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(52, 0x8279DEC8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_8279DEC8(ctx, base); return; }
	LiftedFrame frame(0x8279DEC8);
	STORE8(arg1 + 173, (uint8_t)value);
}
PROMOTED_ENTRY(52, sub_8279DEC8, 0x8279DEC8) { n_sub_8279DEC8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_827A5B80(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(53, 0x827A5B80)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_827A5B80(ctx, base); return; }
	LiftedFrame frame(0x827A5B80);
	STORE8(arg1 + 171, (uint8_t)value);
}
PROMOTED_ENTRY(53, sub_827A5B80, 0x827A5B80) { n_sub_827A5B80(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_827A8990(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(53, 0x827A8990)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_827A8990(ctx, base); return; }
	LiftedFrame frame(0x827A8990);
	STORE8(arg1 + 256, (uint8_t)value);
}
PROMOTED_ENTRY(53, sub_827A8990, 0x827A8990) { n_sub_827A8990(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t GetObjectBit36Bit26(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(53, 0x827AC050)) { ctx.r4.u64 = arg1; __imp__sub_827AC050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827AC050);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 36) >> 26) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(53, sub_827AC050, 0x827AC050) { ctx.r3.u64 = GetObjectBit36Bit26(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit36Bit27(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(53, 0x827B1BE0)) { ctx.r4.u64 = arg1; __imp__sub_827B1BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827B1BE0);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 36) >> 27) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(53, sub_827B1BE0, 0x827B1BE0) { ctx.r3.u64 = GetObjectBit36Bit27(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit44Bit10(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(53, 0x827BDF20)) { ctx.r4.u64 = arg1; __imp__sub_827BDF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827BDF20);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 44) >> 10) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(53, sub_827BDF20, 0x827BDF20) { ctx.r3.u64 = GetObjectBit44Bit10(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit44Bit29(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(53, 0x827BF4C0)) { ctx.r4.u64 = arg1; __imp__sub_827BF4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827BF4C0);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 44) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(53, sub_827BF4C0, 0x827BF4C0) { ctx.r3.u64 = GetObjectBit44Bit29(ctx, base, ctx.r4.u32); }

uint64_t HandleList_Clear_8349B538(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349B538 = int32_t(0x8349B538);
	if (!UseLiftedCode(54, 0x827C57D8)) { __imp__sub_827C57D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827C57D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349B538;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_827C60B0(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(54, sub_827C57D8, 0x827C57D8) { ctx.r3.u64 = HandleList_Clear_8349B538(ctx, base); }

uint64_t GetObjectBit60Bit23(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(54, 0x827CFBE0)) { ctx.r4.u64 = arg1; __imp__sub_827CFBE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827CFBE0);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 60) >> 23) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(54, sub_827CFBE0, 0x827CFBE0) { ctx.r3.u64 = GetObjectBit60Bit23(ctx, base, ctx.r4.u32); }

void n_sub_827D3BC8(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(54, 0x827D3BC8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_827D3BC8(ctx, base); return; }
	LiftedFrame frame(0x827D3BC8);
	STORE8(arg1 + 80, (uint8_t)value);
}
PROMOTED_ENTRY(54, sub_827D3BC8, 0x827D3BC8) { n_sub_827D3BC8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t GetObjectBit48Bit18(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(54, 0x827D56D0)) { ctx.r4.u64 = arg1; __imp__sub_827D56D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D56D0);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 48) >> 18) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(54, sub_827D56D0, 0x827D56D0) { ctx.r3.u64 = GetObjectBit48Bit18(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit40Bit26(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(54, 0x827D8C20)) { ctx.r4.u64 = arg1; __imp__sub_827D8C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D8C20);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 40) >> 26) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(54, sub_827D8C20, 0x827D8C20) { ctx.r3.u64 = GetObjectBit40Bit26(ctx, base, ctx.r4.u32); }

uint64_t Container_8349BBFC_ClearAndFree(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349BBFC = int32_t(0x8349BBFC);
	if (!UseLiftedCode(55, 0x827DF9A8)) { __imp__sub_827DF9A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827DF9A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349BBFC;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_827E0058(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(55, sub_827DF9A8, 0x827DF9A8) { ctx.r3.u64 = Container_8349BBFC_ClearAndFree(ctx, base); }

uint64_t GetObjectBit52Bit20(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(55, 0x827E3770)) { ctx.r4.u64 = arg1; __imp__sub_827E3770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827E3770);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 52) >> 20) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(55, sub_827E3770, 0x827E3770) { ctx.r3.u64 = GetObjectBit52Bit20(ctx, base, ctx.r4.u32); }

void n_sub_827E7AF0(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(55, 0x827E7AF0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_827E7AF0(ctx, base); return; }
	LiftedFrame frame(0x827E7AF0);
	STORE8(arg1 + 19, (uint8_t)value);
}
PROMOTED_ENTRY(55, sub_827E7AF0, 0x827E7AF0) { n_sub_827E7AF0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void Lua_Player_SetCanSleep(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t canSleep) {
	if (!UseLiftedCode(55, 0x827EA5E8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = canSleep; __imp__sub_827EA5E8(ctx, base); return; }
	LiftedFrame frame(0x827EA5E8);
	STORE8(arg1 + 56, (uint8_t)canSleep);
	return;
}
PROMOTED_ENTRY(55, sub_827EA5E8, 0x827EA5E8) { Lua_Player_SetCanSleep(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t GetObjectBit44Bit15(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(55, 0x827EC650)) { ctx.r4.u64 = arg1; __imp__sub_827EC650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EC650);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 44) >> 15) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(55, sub_827EC650, 0x827EC650) { ctx.r3.u64 = GetObjectBit44Bit15(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit48Bit14(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(55, 0x827EE528)) { ctx.r4.u64 = arg1; __imp__sub_827EE528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EE528);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 48) >> 14) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(55, sub_827EE528, 0x827EE528) { ctx.r3.u64 = GetObjectBit48Bit14(ctx, base, ctx.r4.u32); }

void CopyUInt32(CpuState& ctx, uint8_t* base, uint32_t destination, uint32_t source) {
	if (!UseLiftedCode(55, 0x827F85E8)) { ctx.r3.u64 = destination; ctx.r4.u64 = source; __imp__sub_827F85E8(ctx, base); return; }
	LiftedFrame frame(0x827F85E8);
	STORE32(destination, LOAD32(source));
	return;
}
PROMOTED_ENTRY(55, sub_827F85E8, 0x827F85E8) { CopyUInt32(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t Lua_RegisterEnumValue(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_827F9E78 = int32_t(0x827F9E78);
	if (!UseLiftedCode(55, 0x827F9CF8)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_827F9CF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827F9CF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_827F9E78, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(55, sub_827F9CF8, 0x827F9CF8) { ctx.r3.u64 = Lua_RegisterEnumValue(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t GetGlobal8349BD30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349BD30 = int32_t(0x8349BD30);
	if (!UseLiftedCode(56, 0x82805120)) { __imp__sub_82805120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82805120);
	return g_8349BD30;
}
PROMOTED_ENTRY(56, sub_82805120, 0x82805120) { ctx.r3.u64 = GetGlobal8349BD30(ctx, base); }

uint64_t GetObjectBit52Bit8(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(57, 0x82832348)) { ctx.r4.u64 = arg1; __imp__sub_82832348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82832348);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 52) >> 8) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(57, sub_82832348, 0x82832348) { ctx.r3.u64 = GetObjectBit52Bit8(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit48Bit3(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(58, 0x8284B5C8)) { ctx.r4.u64 = arg1; __imp__sub_8284B5C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8284B5C8);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 48) >> 3) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(58, sub_8284B5C8, 0x8284B5C8) { ctx.r3.u64 = GetObjectBit48Bit3(ctx, base, ctx.r4.u32); }

void n_sub_828559C0(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(58, 0x828559C0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_828559C0(ctx, base); return; }
	LiftedFrame frame(0x828559C0);
	STORE8(arg1 + 130, (uint8_t)value);
}
PROMOTED_ENTRY(58, sub_828559C0, 0x828559C0) { n_sub_828559C0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t LinkedList_Destroy_828582F0(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(58, 0x828582F0)) { ctx.r3.u64 = list; __imp__sub_828582F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828582F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_82859010(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(58, sub_828582F0, 0x828582F0) { ctx.r3.u64 = LinkedList_Destroy_828582F0(ctx, base, ctx.r3.u64); }

uint64_t GetObjectBit56Bit10(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(59, 0x8285B940)) { ctx.r4.u64 = arg1; __imp__sub_8285B940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8285B940);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 56) >> 10) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(59, sub_8285B940, 0x8285B940) { ctx.r3.u64 = GetObjectBit56Bit10(ctx, base, ctx.r4.u32); }

uint64_t Lua_InvokeUserdataMethod_8285C888(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(59, 0x8285C888)) { ctx.r3.u64 = luaState; __imp__sub_8285C888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8285C888);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return Lua_ExecuteUserdataMethod_8285CAD8(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(59, sub_8285C888, 0x8285C888) { ctx.r3.u64 = Lua_InvokeUserdataMethod_8285C888(ctx, base, ctx.r3.u64); }

uint64_t GetObjectBit44Bit22(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(59, 0x828601A8)) { ctx.r4.u64 = arg1; __imp__sub_828601A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828601A8);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 44) >> 22) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(59, sub_828601A8, 0x828601A8) { ctx.r3.u64 = GetObjectBit44Bit22(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit64Bit25(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(59, 0x828622B8)) { ctx.r4.u64 = arg1; __imp__sub_828622B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828622B8);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 64) >> 25) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(59, sub_828622B8, 0x828622B8) { ctx.r3.u64 = GetObjectBit64Bit25(ctx, base, ctx.r4.u32); }

void Lua_ExperienceReward_SetToGenerateExperience(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t shouldGenerateExperience) {
	if (!UseLiftedCode(59, 0x82864BA0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = shouldGenerateExperience; __imp__sub_82864BA0(ctx, base); return; }
	LiftedFrame frame(0x82864BA0);
	STORE8(arg1 + 60, (uint8_t)shouldGenerateExperience);
	return;
}
PROMOTED_ENTRY(59, sub_82864BA0, 0x82864BA0) { Lua_ExperienceReward_SetToGenerateExperience(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t GetObjectBit40Bit3(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(59, 0x82865EC0)) { ctx.r4.u64 = arg1; __imp__sub_82865EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82865EC0);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 40) >> 3) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(59, sub_82865EC0, 0x82865EC0) { ctx.r3.u64 = GetObjectBit40Bit3(ctx, base, ctx.r4.u32); }

uint64_t Lua_InvokeUserdataMethod_82866680(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(59, 0x82866680)) { ctx.r3.u64 = luaState; __imp__sub_82866680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82866680);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return Lua_ExecuteUserdataMethod_828666B8(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(59, sub_82866680, 0x82866680) { ctx.r3.u64 = Lua_InvokeUserdataMethod_82866680(ctx, base, ctx.r3.u64); }

uint64_t GetObjectBit40Bit19(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(59, 0x82875D60)) { ctx.r4.u64 = arg1; __imp__sub_82875D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82875D60);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 40) >> 19) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(59, sub_82875D60, 0x82875D60) { ctx.r3.u64 = GetObjectBit40Bit19(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit60Bit9(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(59, 0x828781B8)) { ctx.r4.u64 = arg1; __imp__sub_828781B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828781B8);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 60) >> 9) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(59, sub_828781B8, 0x828781B8) { ctx.r3.u64 = GetObjectBit60Bit9(ctx, base, ctx.r4.u32); }

void n_sub_8287A200(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t value) {
	if (!UseLiftedCode(60, 0x8287A200)) { ctx.r3.u64 = arg1; ctx.r4.u64 = value; __imp__sub_8287A200(ctx, base); return; }
	LiftedFrame frame(0x8287A200);
	STORE8(arg1 + 21, (uint8_t)value);
}
PROMOTED_ENTRY(60, sub_8287A200, 0x8287A200) { n_sub_8287A200(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t GetObjectBit48Bit5(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(60, 0x8287BE50)) { ctx.r4.u64 = arg1; __imp__sub_8287BE50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8287BE50);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 48) >> 5) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(60, sub_8287BE50, 0x8287BE50) { ctx.r3.u64 = GetObjectBit48Bit5(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit40Bit29(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(60, 0x82880020)) { ctx.r4.u64 = arg1; __imp__sub_82880020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82880020);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 40) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(60, sub_82880020, 0x82880020) { ctx.r3.u64 = GetObjectBit40Bit29(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit64Bit5(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(60, 0x82882978)) { ctx.r4.u64 = arg1; __imp__sub_82882978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82882978);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 64) >> 5) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(60, sub_82882978, 0x82882978) { ctx.r3.u64 = GetObjectBit64Bit5(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit64Bit26(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(60, 0x82894A00)) { ctx.r4.u64 = arg1; __imp__sub_82894A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82894A00);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 64) >> 26) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(60, sub_82894A00, 0x82894A00) { ctx.r3.u64 = GetObjectBit64Bit26(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit60Bit14(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(60, 0x82897228)) { ctx.r4.u64 = arg1; __imp__sub_82897228(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82897228);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 60) >> 14) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(60, sub_82897228, 0x82897228) { ctx.r3.u64 = GetObjectBit60Bit14(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit60Bit15(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(61, 0x8289AFD0)) { ctx.r4.u64 = arg1; __imp__sub_8289AFD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289AFD0);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 60) >> 15) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(61, sub_8289AFD0, 0x8289AFD0) { ctx.r3.u64 = GetObjectBit60Bit15(ctx, base, ctx.r4.u32); }

uint64_t Container_8349C1DC_ClearAndFree(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349C1DC = int32_t(0x8349C1DC);
	if (!UseLiftedCode(61, 0x828A33B0)) { __imp__sub_828A33B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A33B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349C1DC;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_828A3B48(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A33B0, 0x828A33B0) { ctx.r3.u64 = Container_8349C1DC_ClearAndFree(ctx, base); }

uint64_t Container_8349C1E8_ClearAndFree(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349C1E8 = int32_t(0x8349C1E8);
	if (!UseLiftedCode(61, 0x828A3420)) { __imp__sub_828A3420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A3420);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349C1E8;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_828A4580(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A3420, 0x828A3420) { ctx.r3.u64 = Container_8349C1E8_ClearAndFree(ctx, base); }

uint64_t GetObjectBit60Bit7(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(61, 0x828A72B8)) { ctx.r4.u64 = arg1; __imp__sub_828A72B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A72B8);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 60) >> 7) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(61, sub_828A72B8, 0x828A72B8) { ctx.r3.u64 = GetObjectBit60Bit7(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit44Bit19(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(61, 0x828AA7E0)) { ctx.r4.u64 = arg1; __imp__sub_828AA7E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828AA7E0);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 44) >> 19) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(61, sub_828AA7E0, 0x828AA7E0) { ctx.r3.u64 = GetObjectBit44Bit19(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit44Bit5(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(61, 0x828B6A00)) { ctx.r4.u64 = arg1; __imp__sub_828B6A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B6A00);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 44) >> 5) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(61, sub_828B6A00, 0x828B6A00) { ctx.r3.u64 = GetObjectBit44Bit5(ctx, base, ctx.r4.u32); }

uint64_t GetObjectBit60Bit22(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(62, 0x828B7540)) { ctx.r4.u64 = arg1; __imp__sub_828B7540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B7540);
	uint64_t result = 0;
	if (arg1 != 0) {
		uint32_t objectFlagMask = LOAD8(arg1 + 144) & 64;
		if (objectFlagMask != 0) {
			result = (LOAD32(arg1 + 60) >> 22) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(62, sub_828B7540, 0x828B7540) { ctx.r3.u64 = GetObjectBit60Bit22(ctx, base, ctx.r4.u32); }

uint64_t n_sub_828B84A8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(62, 0x828B84A8)) { ctx.r4.u64 = object; __imp__sub_828B84A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828B84A8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 52) >> 25) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(62, sub_828B84A8, 0x828B84A8) { ctx.r3.u64 = n_sub_828B84A8(ctx, base, ctx.r4.u32); }

uint64_t n_sub_828BC740(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(62, 0x828BC740)) { ctx.r4.u64 = object; __imp__sub_828BC740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828BC740);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 44) >> 28) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(62, sub_828BC740, 0x828BC740) { ctx.r3.u64 = n_sub_828BC740(ctx, base, ctx.r4.u32); }

uint64_t n_sub_828BDEA8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(62, 0x828BDEA8)) { ctx.r4.u64 = object; __imp__sub_828BDEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828BDEA8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 5) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(62, sub_828BDEA8, 0x828BDEA8) { ctx.r3.u64 = n_sub_828BDEA8(ctx, base, ctx.r4.u32); }

uint64_t n_sub_828F1040(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(63, 0x828F1040)) { ctx.r4.u64 = object; __imp__sub_828F1040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828F1040);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 52) >> 14) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(63, sub_828F1040, 0x828F1040) { ctx.r3.u64 = n_sub_828F1040(ctx, base, ctx.r4.u32); }

uint32_t Lua_RegisterEnumValue_82903AB8(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_825BEEE8 = int32_t(0x825BEEE8);
	if (!UseLiftedCode(64, 0x82903AB8)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82903AB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82903AB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_825BEEE8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(64, sub_82903AB8, 0x82903AB8) { ctx.r3.u64 = Lua_RegisterEnumValue_82903AB8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t Lua_RegisterEnumValue_82903C38(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82903E78 = int32_t(0x82903E78);
	if (!UseLiftedCode(64, 0x82903C38)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82903C38(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82903C38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82903E78, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(64, sub_82903C38, 0x82903C38) { ctx.r3.u64 = Lua_RegisterEnumValue_82903C38(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t Lua_RegisterEnumValue_82903CD0(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_82903EF0 = int32_t(0x82903EF0);
	if (!UseLiftedCode(64, 0x82903CD0)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82903CD0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82903CD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_82903EF0, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(64, sub_82903CD0, 0x82903CD0) { ctx.r3.u64 = Lua_RegisterEnumValue_82903CD0(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t Lua_GUI_SetLoadingScreenTextTagGroupName(CpuState& ctx, uint8_t* base, uint64_t textTagGroupName) {
	constexpr int32_t TXT_834973E8_G_ = int32_t(0x834973E8);
	if (!UseLiftedCode(64, 0x82908DE8)) { ctx.r3.u64 = textTagGroupName; __imp__sub_82908DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82908DE8);
	uint64_t loadingTipsString{};
	uint64_t assignResult{};
	loadingTipsString = TXT_834973E8_G_;
	assignResult = CCharString_Assign(ctx, base, loadingTipsString, textTagGroupName);
	return assignResult;
}
PROMOTED_ENTRY(64, sub_82908DE8, 0x82908DE8) { ctx.r3.u64 = Lua_GUI_SetLoadingScreenTextTagGroupName(ctx, base, ctx.r3.u64); }

uint32_t Lua_RegisterEnumValue_8290A1F8(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8290A8A8 = int32_t(0x8290A8A8);
	if (!UseLiftedCode(64, 0x8290A1F8)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_8290A1F8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8290A1F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_8290A8A8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(64, sub_8290A1F8, 0x8290A1F8) { ctx.r3.u64 = Lua_RegisterEnumValue_8290A1F8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t LookAtHandle_IsValidThunk(CpuState& ctx, uint8_t* base, uint64_t lookAtHandle) {
	if (!UseLiftedCode(64, 0x8290AED8)) { ctx.r3.u64 = lookAtHandle; __imp__sub_8290AED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8290AED8);
	uint64_t isValid{};
	isValid = LookAtHandle_IsValid(ctx, base, lookAtHandle);
	return isValid;
}
PROMOTED_ENTRY(64, sub_8290AED8, 0x8290AED8) { ctx.r3.u64 = LookAtHandle_IsValidThunk(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82913188(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(64, 0x82913188)) { ctx.r4.u64 = object; __imp__sub_82913188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82913188);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 44) >> 7) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(64, sub_82913188, 0x82913188) { ctx.r3.u64 = n_sub_82913188(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82920948(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(65, 0x82920948)) { ctx.r4.u64 = object; __imp__sub_82920948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82920948);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 52) >> 27) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(65, sub_82920948, 0x82920948) { ctx.r3.u64 = n_sub_82920948(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82928A58(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(65, 0x82928A58)) { ctx.r4.u64 = object; __imp__sub_82928A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82928A58);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 10) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(65, sub_82928A58, 0x82928A58) { ctx.r3.u64 = n_sub_82928A58(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8292A248(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(65, 0x8292A248)) { ctx.r3.u64 = luaState; __imp__sub_8292A248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8292A248);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_8292AB80(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(65, sub_8292A248, 0x8292A248) { ctx.r3.u64 = n_sub_8292A248(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8292A958(CpuState& ctx, uint8_t* base, uint64_t luaState) {
	if (!UseLiftedCode(65, 0x8292A958)) { ctx.r3.u64 = luaState; __imp__sub_8292A958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8292A958);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t userdata = lua_touserdata(ctx, base, luaState, -10003);
	uint32_t function = LOAD32((uint32_t)userdata + 4);
	uint64_t self = LOAD32((uint32_t)userdata);
	return n_sub_8292AC60(ctx, base, self, function, luaState);
}
PROMOTED_ENTRY(65, sub_8292A958, 0x8292A958) { ctx.r3.u64 = n_sub_8292A958(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8292EAB8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(65, 0x8292EAB8)) { ctx.r4.u64 = object; __imp__sub_8292EAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8292EAB8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 56) >> 20) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(65, sub_8292EAB8, 0x8292EAB8) { ctx.r3.u64 = n_sub_8292EAB8(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8293D918(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x8293D918)) { ctx.r4.u64 = object; __imp__sub_8293D918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8293D918);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 19) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_8293D918, 0x8293D918) { ctx.r3.u64 = n_sub_8293D918(ctx, base, ctx.r4.u32); }

void n_sub_8293E170(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(66, 0x8293E170)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_8293E170(ctx, base); return; }
	LiftedFrame frame(0x8293E170);
	STORE8(object + 16, (uint8_t)value);
}
PROMOTED_ENTRY(66, sub_8293E170, 0x8293E170) { n_sub_8293E170(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_8293F970(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x8293F970)) { ctx.r4.u64 = object; __imp__sub_8293F970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8293F970);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 8) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_8293F970, 0x8293F970) { ctx.r3.u64 = n_sub_8293F970(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82940A88(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82940A88)) { ctx.r4.u64 = object; __imp__sub_82940A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82940A88);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 27) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82940A88, 0x82940A88) { ctx.r3.u64 = n_sub_82940A88(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82941F30(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82941F30)) { ctx.r4.u64 = object; __imp__sub_82941F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82941F30);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 52) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82941F30, 0x82941F30) { ctx.r3.u64 = n_sub_82941F30(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82943188(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82943188)) { ctx.r4.u64 = object; __imp__sub_82943188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82943188);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 2) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82943188, 0x82943188) { ctx.r3.u64 = n_sub_82943188(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82944570(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82944570)) { ctx.r4.u64 = object; __imp__sub_82944570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82944570);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 20) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82944570, 0x82944570) { ctx.r3.u64 = n_sub_82944570(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82945E30(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82945E30)) { ctx.r4.u64 = object; __imp__sub_82945E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82945E30);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82945E30, 0x82945E30) { ctx.r3.u64 = n_sub_82945E30(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82947A10(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82947A10)) { ctx.r4.u64 = object; __imp__sub_82947A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82947A10);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 2) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82947A10, 0x82947A10) { ctx.r3.u64 = n_sub_82947A10(ctx, base, ctx.r4.u32); }

void n_sub_82948428(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(66, 0x82948428)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82948428(ctx, base); return; }
	LiftedFrame frame(0x82948428);
	STORE8(object + 25, (uint8_t)value);
}
PROMOTED_ENTRY(66, sub_82948428, 0x82948428) { n_sub_82948428(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_829499D8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x829499D8)) { ctx.r4.u64 = object; __imp__sub_829499D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829499D8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 30) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_829499D8, 0x829499D8) { ctx.r3.u64 = n_sub_829499D8(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8294F428(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x8294F428)) { ctx.r4.u64 = object; __imp__sub_8294F428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8294F428);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 20) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_8294F428, 0x8294F428) { ctx.r3.u64 = n_sub_8294F428(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8294FE38(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x8294FE38)) { ctx.r4.u64 = object; __imp__sub_8294FE38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8294FE38);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 21) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_8294FE38, 0x8294FE38) { ctx.r3.u64 = n_sub_8294FE38(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82950A20(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82950A20)) { ctx.r4.u64 = object; __imp__sub_82950A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82950A20);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 52) >> 1) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82950A20, 0x82950A20) { ctx.r3.u64 = n_sub_82950A20(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82952960(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82952960)) { ctx.r4.u64 = object; __imp__sub_82952960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82952960);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 6) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82952960, 0x82952960) { ctx.r3.u64 = n_sub_82952960(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82955870(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(66, 0x82955870)) { ctx.r4.u64 = object; __imp__sub_82955870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82955870);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 6) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(66, sub_82955870, 0x82955870) { ctx.r3.u64 = n_sub_82955870(ctx, base, ctx.r4.u32); }

uint64_t n_sub_829577D8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x829577D8)) { ctx.r4.u64 = object; __imp__sub_829577D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829577D8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 22) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_829577D8, 0x829577D8) { ctx.r3.u64 = n_sub_829577D8(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82958820(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x82958820)) { ctx.r4.u64 = object; __imp__sub_82958820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82958820);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 7) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_82958820, 0x82958820) { ctx.r3.u64 = n_sub_82958820(ctx, base, ctx.r4.u32); }

void n_sub_82959EF0(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value) {
	if (!UseLiftedCode(67, 0x82959EF0)) { ctx.r3.u64 = object; ctx.r4.u64 = value; __imp__sub_82959EF0(ctx, base); return; }
	LiftedFrame frame(0x82959EF0);
	STORE8(object + 40, (uint8_t)value);
}
PROMOTED_ENTRY(67, sub_82959EF0, 0x82959EF0) { n_sub_82959EF0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_8295AE18(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x8295AE18)) { ctx.r4.u64 = object; __imp__sub_8295AE18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8295AE18);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 23) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_8295AE18, 0x8295AE18) { ctx.r3.u64 = n_sub_8295AE18(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8295C1B0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x8295C1B0)) { ctx.r4.u64 = object; __imp__sub_8295C1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8295C1B0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 52) >> 10) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_8295C1B0, 0x8295C1B0) { ctx.r3.u64 = n_sub_8295C1B0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8295EC88(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x8295EC88)) { ctx.r4.u64 = object; __imp__sub_8295EC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8295EC88);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 9) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_8295EC88, 0x8295EC88) { ctx.r3.u64 = n_sub_8295EC88(ctx, base, ctx.r4.u32); }

uint64_t n_sub_829614D0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x829614D0)) { ctx.r4.u64 = object; __imp__sub_829614D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829614D0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 30) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_829614D0, 0x829614D0) { ctx.r3.u64 = n_sub_829614D0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82966308(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x82966308)) { ctx.r4.u64 = object; __imp__sub_82966308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82966308);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 36) >> 25) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_82966308, 0x82966308) { ctx.r3.u64 = n_sub_82966308(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82967EA0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x82967EA0)) { ctx.r4.u64 = object; __imp__sub_82967EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82967EA0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 10) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_82967EA0, 0x82967EA0) { ctx.r3.u64 = n_sub_82967EA0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82969320(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x82969320)) { ctx.r4.u64 = object; __imp__sub_82969320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82969320);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 13) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_82969320, 0x82969320) { ctx.r3.u64 = n_sub_82969320(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8296ABE0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x8296ABE0)) { ctx.r4.u64 = object; __imp__sub_8296ABE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8296ABE0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 17) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_8296ABE0, 0x8296ABE0) { ctx.r3.u64 = n_sub_8296ABE0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8296C268(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x8296C268)) { ctx.r4.u64 = object; __imp__sub_8296C268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8296C268);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 56) >> 1) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_8296C268, 0x8296C268) { ctx.r3.u64 = n_sub_8296C268(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8296D0D0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x8296D0D0)) { ctx.r4.u64 = object; __imp__sub_8296D0D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8296D0D0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 28) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_8296D0D0, 0x8296D0D0) { ctx.r3.u64 = n_sub_8296D0D0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8296F8B0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x8296F8B0)) { ctx.r4.u64 = object; __imp__sub_8296F8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8296F8B0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 6) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_8296F8B0, 0x8296F8B0) { ctx.r3.u64 = n_sub_8296F8B0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82971CD8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x82971CD8)) { ctx.r4.u64 = object; __imp__sub_82971CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82971CD8);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 60) >> 11) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_82971CD8, 0x82971CD8) { ctx.r3.u64 = n_sub_82971CD8(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82974920(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x82974920)) { ctx.r4.u64 = object; __imp__sub_82974920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82974920);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 36) >> 30) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_82974920, 0x82974920) { ctx.r3.u64 = n_sub_82974920(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82975680(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(67, 0x82975680)) { ctx.r4.u64 = object; __imp__sub_82975680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82975680);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 64) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(67, sub_82975680, 0x82975680) { ctx.r3.u64 = n_sub_82975680(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82979E40(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x82979E40)) { ctx.r4.u64 = object; __imp__sub_82979E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82979E40);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 7) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_82979E40, 0x82979E40) { ctx.r3.u64 = n_sub_82979E40(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8297A9B0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8297A9B0)) { ctx.r4.u64 = object; __imp__sub_8297A9B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297A9B0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 56) >> 3) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8297A9B0, 0x8297A9B0) { ctx.r3.u64 = n_sub_8297A9B0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8297B088(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8297B088)) { ctx.r4.u64 = object; __imp__sub_8297B088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297B088);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 48) >> 8) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8297B088, 0x8297B088) { ctx.r3.u64 = n_sub_8297B088(ctx, base, ctx.r4.u32); }

uint64_t n_sub_8297F6F0(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8297F6F0)) { ctx.r4.u64 = object; __imp__sub_8297F6F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297F6F0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 44) >> 2) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8297F6F0, 0x8297F6F0) { ctx.r3.u64 = n_sub_8297F6F0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82980890(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x82980890)) { ctx.r4.u64 = object; __imp__sub_82980890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82980890);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 56) >> 6) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_82980890, 0x82980890) { ctx.r3.u64 = n_sub_82980890(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82983220(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x82983220)) { ctx.r4.u64 = object; __imp__sub_82983220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82983220);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t flag144 = LOAD8(object + 144) & 64;
		if (flag144 != 0) {
			result = (LOAD32(object + 40) >> 22) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_82983220, 0x82983220) { ctx.r3.u64 = n_sub_82983220(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField40Bit9(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x829849D0)) { ctx.r4.u64 = object; __imp__sub_829849D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829849D0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 40) >> 9) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_829849D0, 0x829849D0) { ctx.r3.u64 = GetObjectField40Bit9(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField60Bit28(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x82985F30)) { ctx.r4.u64 = object; __imp__sub_82985F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82985F30);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 60) >> 28) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_82985F30, 0x82985F30) { ctx.r3.u64 = GetObjectField60Bit28(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField44Bit13(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x829886B0)) { ctx.r4.u64 = object; __imp__sub_829886B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829886B0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 44) >> 13) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_829886B0, 0x829886B0) { ctx.r3.u64 = GetObjectField44Bit13(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField40Bit23(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8298AFE0)) { ctx.r4.u64 = object; __imp__sub_8298AFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8298AFE0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 40) >> 23) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8298AFE0, 0x8298AFE0) { ctx.r3.u64 = GetObjectField40Bit23(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField44Bit26(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8298B918)) { ctx.r4.u64 = object; __imp__sub_8298B918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8298B918);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 44) >> 26) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8298B918, 0x8298B918) { ctx.r3.u64 = GetObjectField44Bit26(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField36Bit29(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8298CB78)) { ctx.r4.u64 = object; __imp__sub_8298CB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8298CB78);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 36) >> 29) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8298CB78, 0x8298CB78) { ctx.r3.u64 = GetObjectField36Bit29(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField56Bit8(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8298E200)) { ctx.r4.u64 = object; __imp__sub_8298E200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8298E200);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 56) >> 8) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8298E200, 0x8298E200) { ctx.r3.u64 = GetObjectField56Bit8(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField56Bit9(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x8298F118)) { ctx.r4.u64 = object; __imp__sub_8298F118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8298F118);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 56) >> 9) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_8298F118, 0x8298F118) { ctx.r3.u64 = GetObjectField56Bit9(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField56Bit12(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x82990D98)) { ctx.r4.u64 = object; __imp__sub_82990D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82990D98);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 56) >> 12) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_82990D98, 0x82990D98) { ctx.r3.u64 = GetObjectField56Bit12(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField48Bit13(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(68, 0x829959C0)) { ctx.r4.u64 = object; __imp__sub_829959C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829959C0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 48) >> 13) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(68, sub_829959C0, 0x829959C0) { ctx.r3.u64 = GetObjectField48Bit13(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField48Bit17(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(69, 0x82996C50)) { ctx.r4.u64 = object; __imp__sub_82996C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82996C50);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 48) >> 17) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(69, sub_82996C50, 0x82996C50) { ctx.r3.u64 = GetObjectField48Bit17(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField56Bit27(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(69, 0x82997680)) { ctx.r4.u64 = object; __imp__sub_82997680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82997680);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 56) >> 27) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(69, sub_82997680, 0x82997680) { ctx.r3.u64 = GetObjectField56Bit27(ctx, base, ctx.r4.u32); }

uint64_t GetObjectField60Bit1(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(69, 0x829986D0)) { ctx.r4.u64 = object; __imp__sub_829986D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829986D0);
	uint64_t result = 0;
	if (object != 0) {
		uint32_t objectFlags = LOAD8(object + 144) & 64;
		if (objectFlags != 0) {
			result = (LOAD32(object + 60) >> 1) & 1;
		}
	}
	return result;
}
PROMOTED_ENTRY(69, sub_829986D0, 0x829986D0) { ctx.r3.u64 = GetObjectField60Bit1(ctx, base, ctx.r4.u32); }

uint64_t Container_8349E010_ClearAndFree(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349E010 = int32_t(0x8349E010);
	if (!UseLiftedCode(70, 0x829C6C30)) { __imp__sub_829C6C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829C6C30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349E010;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_DestroyRange_829C6CA0(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(70, sub_829C6C30, 0x829C6C30) { ctx.r3.u64 = Container_8349E010_ClearAndFree(ctx, base); }

uint32_t Lua_RegisterEnumValue_829E10F8(CpuState& ctx, uint8_t* base, uint32_t luaObject, uint64_t fieldName, uint32_t fieldValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_829E35C8 = int32_t(0x829E35C8);
	if (!UseLiftedCode(71, 0x829E10F8)) { ctx.r3.u64 = luaObject; ctx.r4.u64 = fieldName; ctx.r5.u64 = fieldValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_829E10F8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x829E10F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = luaObject;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, fieldValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_829E35C8, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		luaObject = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return luaObject;
}
PROMOTED_ENTRY(71, sub_829E10F8, 0x829E10F8) { ctx.r3.u64 = Lua_RegisterEnumValue_829E10F8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_829E1190(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t intValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_829E3288 = int32_t(0x829E3288);
	if (!UseLiftedCode(71, 0x829E1190)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = intValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_829E1190(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x829E1190);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, intValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_829E3288, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(71, sub_829E1190, 0x829E1190) { ctx.r3.u64 = n_sub_829E1190(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_829E1228(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t intValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_829E3438 = int32_t(0x829E3438);
	if (!UseLiftedCode(71, 0x829E1228)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = intValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_829E1228(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x829E1228);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, intValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_829E3438, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(71, sub_829E1228, 0x829E1228) { ctx.r3.u64 = n_sub_829E1228(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_829E1358(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t fieldName, uint32_t intValue, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_829E3550 = int32_t(0x829E3550);
	if (!UseLiftedCode(71, 0x829E1358)) { ctx.r3.u64 = arg1; ctx.r4.u64 = fieldName; ctx.r5.u64 = intValue; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_829E1358(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x829E1358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint64_t newTop = ctx.r9.u64;
	uint32_t self = arg1;
	uint32_t refSlot = LOAD32(self);
	if (refSlot != 0) {
		uint32_t state = LOAD32(refSlot);
		uint32_t registryRef = LOAD32(refSlot + 4);
		ctx.r1.u64 = stack;
		lua_rawgeti(ctx, base, (uint64_t)state, -10000, registryRef);
		uint32_t userdata = lua_newuserdata(ctx, base, (uint64_t)state, 4, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		STORE32(userdata, intValue);
		n_sub_8219AB28(ctx, base, (uint64_t)state, (uint32_t)g_829E3550, 1, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_824EF160(ctx, base, (uint64_t)self, (uint64_t)state, fieldName, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		arg1 = lua_setfield(ctx, base, (uint64_t)state, -2, fieldName);
		arg4 = ctx.r6.u64;
		arg5 = ctx.r7.u64;
		newTop = (int64_t)(uint64_t)LOAD32(state + 8) - 8;
		STORE32(state + 8, (uint32_t)newTop);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r9.u64 = newTop;
	return arg1;
}
PROMOTED_ENTRY(71, sub_829E1358, 0x829E1358) { ctx.r3.u64 = n_sub_829E1358(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t ClearGlobalList_8349E1F4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349E1F4 = int32_t(0x8349E1F4);
	if (!UseLiftedCode(72, 0x829FDA08)) { __imp__sub_829FDA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829FDA08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349E1F4;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	DestroyGlobalListNodes_8349E1F4(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(72, sub_829FDA08, 0x829FDA08) { ctx.r3.u64 = ClearGlobalList_8349E1F4(ctx, base); }

uint64_t ClearGlobalList_834C1780(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834C1780 = int32_t(0x834C1780);
	if (!UseLiftedCode(72, 0x829FDA78)) { __imp__sub_829FDA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829FDA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834C1780;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	DestroyGlobalListNodes_834C1780(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(72, sub_829FDA78, 0x829FDA78) { ctx.r3.u64 = ClearGlobalList_834C1780(ctx, base); }

uint32_t ClearLinkedList(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(73, 0x82A12668)) { ctx.r3.u64 = list; __imp__sub_82A12668(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A12668);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	DestroyListNodes(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(73, sub_82A12668, 0x82A12668) { ctx.r3.u64 = ClearLinkedList(ctx, base, ctx.r3.u64); }

// sub_82A27598  [88 bytes]
uint64_t Lua_Math_Sin(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27598)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27598);
	// Checks the first Lua stack argument is a number and stores sin(value) into the value buffer
	// kept at luaState, advancing the buffer's write cursor by 8: a float word and a type tag of 3.
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Sin(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27598, 0x82A27598) { ctx.r3.u64 = Lua_Math_Sin(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_SinApprox(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27648)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27648);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_SinApprox(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27648, 0x82A27648) { ctx.r3.u64 = Lua_Math_SinApprox(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Tan(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A276F8)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A276F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A276F8);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = tan(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A276F8, 0x82A276F8) { ctx.r3.u64 = Lua_Math_Tan(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Cos(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27750)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27750);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Cos(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27750, 0x82A27750) { ctx.r3.u64 = Lua_Math_Cos(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Asin(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A277A8)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A277A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A277A8);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Asin(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A277A8, 0x82A277A8) { ctx.r3.u64 = Lua_Math_Asin(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Acos(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27800)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27800);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Acos(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27800, 0x82A27800) { ctx.r3.u64 = Lua_Math_Acos(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Atan(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27858)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27858);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = atan(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27858, 0x82A27858) { ctx.r3.u64 = Lua_Math_Atan(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Ceil(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27928)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27928);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = ceil(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27928, 0x82A27928) { ctx.r3.u64 = Lua_Math_Ceil(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Floor(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27980)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27980);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = floor(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27980, 0x82A27980) { ctx.r3.u64 = Lua_Math_Floor(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Log(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27BA8)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27BA8);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = log(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27BA8, 0x82A27BA8) { ctx.r3.u64 = Lua_Math_Log(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Log10(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27C00)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27C00);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = log10f(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27C00, 0x82A27C00) { ctx.r3.u64 = Lua_Math_Log10(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Exp(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(73, 0x82A27C58)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82A27C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A27C58);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	luaL_checknumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Exp(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(73, sub_82A27C58, 0x82A27C58) { ctx.r3.u64 = Lua_Math_Exp(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t ClearGlobalList_8349F7BC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349F7BC = int32_t(0x8349F7BC);
	if (!UseLiftedCode(75, 0x82A51AC0)) { __imp__sub_82A51AC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A51AC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349F7BC;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	DestroyGlobalListNodes_8349F7BC(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(75, sub_82A51AC0, 0x82A51AC0) { ctx.r3.u64 = ClearGlobalList_8349F7BC(ctx, base); }

uint64_t ClearGlobalList_8349F848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8349F848 = int32_t(0x8349F848);
	if (!UseLiftedCode(75, 0x82A581D0)) { __imp__sub_82A581D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A581D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_8349F848;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	DestroyGlobalListNodes_8349F848(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(75, sub_82A581D0, 0x82A581D0) { ctx.r3.u64 = ClearGlobalList_8349F848(ctx, base); }

uint64_t ClearGlobalList_834A4CF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A4CF8 = int32_t(0x834A4CF8);
	if (!UseLiftedCode(77, 0x82A8DD30)) { __imp__sub_82A8DD30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A8DD30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A4CF8;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	DestroyGlobalListNodes_834A4CF8(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A8DD30, 0x82A8DD30) { ctx.r3.u64 = ClearGlobalList_834A4CF8(ctx, base); }

uint64_t LinkedList_Destroy_834A4D04(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A4D04 = int32_t(0x834A4D04);
	if (!UseLiftedCode(77, 0x82A8DEE0)) { __imp__sub_82A8DEE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A8DEE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A4D04;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A4D04(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A8DEE0, 0x82A8DEE0) { ctx.r3.u64 = LinkedList_Destroy_834A4D04(ctx, base); }

uint64_t LinkedList_Destroy_834A4D10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A4D10 = int32_t(0x834A4D10);
	if (!UseLiftedCode(77, 0x82A8E090)) { __imp__sub_82A8E090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A8E090);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A4D10;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A4D10(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A8E090, 0x82A8E090) { ctx.r3.u64 = LinkedList_Destroy_834A4D10(ctx, base); }

uint64_t LinkedList_Destroy_834A4D1C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A4D1C = int32_t(0x834A4D1C);
	if (!UseLiftedCode(77, 0x82A8E240)) { __imp__sub_82A8E240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A8E240);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A4D1C;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A4D1C(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A8E240, 0x82A8E240) { ctx.r3.u64 = LinkedList_Destroy_834A4D1C(ctx, base); }

uint64_t LinkedList_Destroy_834A4D28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A4D28 = int32_t(0x834A4D28);
	if (!UseLiftedCode(77, 0x82A8E3F0)) { __imp__sub_82A8E3F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A8E3F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A4D28;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A4D28(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A8E3F0, 0x82A8E3F0) { ctx.r3.u64 = LinkedList_Destroy_834A4D28(ctx, base); }

uint64_t n_sub_82AA2880(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A57C8 = int32_t(0x834A57C8);
	if (!UseLiftedCode(78, 0x82AA2880)) { __imp__sub_82AA2880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82AA2880);
	return PrintRenderedPrimStats(ctx, base, g_834A57C8);
}
PROMOTED_ENTRY(78, sub_82AA2880, 0x82AA2880) { ctx.r3.u64 = n_sub_82AA2880(ctx, base); }

uint64_t LinkedList_Destroy_834A542C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A542C = int32_t(0x834A542C);
	if (!UseLiftedCode(78, 0x82AA7B20)) { __imp__sub_82AA7B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82AA7B20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A542C;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A542C(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(78, sub_82AA7B20, 0x82AA7B20) { ctx.r3.u64 = LinkedList_Destroy_834A542C(ctx, base); }

uint64_t LinkedList_Destroy_834A5440(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5440 = int32_t(0x834A5440);
	if (!UseLiftedCode(78, 0x82AA8C38)) { __imp__sub_82AA8C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82AA8C38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A5440;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A5440(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(78, sub_82AA8C38, 0x82AA8C38) { ctx.r3.u64 = LinkedList_Destroy_834A5440(ctx, base); }

uint64_t LinkedList_Destroy_834A54A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A54A0 = int32_t(0x834A54A0);
	if (!UseLiftedCode(78, 0x82AB0B80)) { __imp__sub_82AB0B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82AB0B80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A54A0;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A54A0(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(78, sub_82AB0B80, 0x82AB0B80) { ctx.r3.u64 = LinkedList_Destroy_834A54A0(ctx, base); }

uint64_t ReleaseContainer_834A5B74(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5B74 = int32_t(0x834A5B74);
	if (!UseLiftedCode(83, 0x82B3CBC8)) { __imp__sub_82B3CBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B3CBC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A5B74;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A5B74(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(83, sub_82B3CBC8, 0x82B3CBC8) { ctx.r3.u64 = ReleaseContainer_834A5B74(ctx, base); }

void SwapUInt32(CpuState& ctx, uint8_t* base, uint32_t firstValue, uint32_t secondValue) {
	if (!UseLiftedCode(83, 0x82B4A8A0)) { ctx.r3.u64 = firstValue; ctx.r4.u64 = secondValue; __imp__sub_82B4A8A0(ctx, base); return; }
	LiftedFrame frame(0x82B4A8A0);
	uint32_t tempValue{};
	tempValue = LOAD32(firstValue);
	STORE32(firstValue, LOAD32(secondValue));
	STORE32(secondValue, tempValue);
	return;
}
PROMOTED_ENTRY(83, sub_82B4A8A0, 0x82B4A8A0) { SwapUInt32(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t ReleaseContainer_834A5B8C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5B8C = int32_t(0x834A5B8C);
	if (!UseLiftedCode(84, 0x82B5BE58)) { __imp__sub_82B5BE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B5BE58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A5B8C;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A5B8C(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(84, sub_82B5BE58, 0x82B5BE58) { ctx.r3.u64 = ReleaseContainer_834A5B8C(ctx, base); }

uint64_t ReleaseContainer_834A5C38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5C38 = int32_t(0x834A5C38);
	if (!UseLiftedCode(84, 0x82B5D780)) { __imp__sub_82B5D780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B5D780);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A5C38;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A5C38(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(84, sub_82B5D780, 0x82B5D780) { ctx.r3.u64 = ReleaseContainer_834A5C38(ctx, base); }

uint64_t ReleaseContainer_834A5C44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5C44 = int32_t(0x834A5C44);
	if (!UseLiftedCode(84, 0x82B5DEC8)) { __imp__sub_82B5DEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B5DEC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A5C44;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A5C44(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(84, sub_82B5DEC8, 0x82B5DEC8) { ctx.r3.u64 = ReleaseContainer_834A5C44(ctx, base); }

uint64_t ReleaseContainer_834A5C50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5C50 = int32_t(0x834A5C50);
	if (!UseLiftedCode(84, 0x82B5E178)) { __imp__sub_82B5E178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B5E178);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A5C50;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A5C50(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(84, sub_82B5E178, 0x82B5E178) { ctx.r3.u64 = ReleaseContainer_834A5C50(ctx, base); }

uint32_t LinkedList_Destroy_82B63BD0(CpuState& ctx, uint8_t* base, uint64_t list) {
	if (!UseLiftedCode(84, 0x82B63BD0)) { ctx.r3.u64 = list; __imp__sub_82B63BD0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B63BD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 88, (uint32_t)list);
	STORE32(stack + 80, (uint32_t)list);
	uint32_t headNode = LOAD32((uint32_t)list + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_82B64388(ctx, base, (int64_t)(uint64_t)stack + 88, list, beginPair, endPair);
	headNode = LOAD32((uint32_t)list + 4);
	uint32_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32((uint32_t)list + 4, 0u);
	STORE32((uint32_t)list + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(84, sub_82B63BD0, 0x82B63BD0) { ctx.r3.u64 = LinkedList_Destroy_82B63BD0(ctx, base, ctx.r3.u64); }

uint64_t ReleaseContainer_834A5D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A5D48 = int32_t(0x834A5D48);
	if (!UseLiftedCode(84, 0x82B6A018)) { __imp__sub_82B6A018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B6A018);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A5D48;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A5D48(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(84, sub_82B6A018, 0x82B6A018) { ctx.r3.u64 = ReleaseContainer_834A5D48(ctx, base); }

uint64_t ReleaseContainer_834A601C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834A601C = int32_t(0x834A601C);
	if (!UseLiftedCode(84, 0x82B6BEB0)) { __imp__sub_82B6BEB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B6BEB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t container = (uint32_t)g_834A601C;
	STORE32(stack + 88, container);
	STORE32(stack + 80, container);
	uint32_t headNode = LOAD32(container + 4);
	uint32_t firstNode = LOAD32(headNode);
	STORE32(stack + 84, headNode);
	uint64_t endPair = LOAD64(stack + 80);
	STORE32(stack + 92, firstNode);
	uint64_t beginPair = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	LinkedList_EraseRange_834A601C(ctx, base, (int64_t)(uint64_t)stack + 88, beginPair, endPair);
	headNode = LOAD32(container + 4);
	uint64_t result = HandleTarget_Free(ctx, base, headNode);
	STORE32(container + 4, 0u);
	STORE32(container + 8, 0u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(84, sub_82B6BEB0, 0x82B6BEB0) { ctx.r3.u64 = ReleaseContainer_834A601C(ctx, base); }

// sub_82B90720  [12 bytes]
uint64_t GetObjectField10568Bits3To10(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90720)) { ctx.r3.u64 = object; __imp__sub_82B90720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90720);
	return (LOAD32(object + 10568) >> 3) & 255;
}
PROMOTED_ENTRY(85, sub_82B90720, 0x82B90720) { ctx.r3.u64 = GetObjectField10568Bits3To10(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10556Bit3(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90730)) { ctx.r3.u64 = object; __imp__sub_82B90730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90730);
	return (LOAD32(object + 10556) >> 3) & 1;
}
PROMOTED_ENTRY(85, sub_82B90730, 0x82B90730) { ctx.r3.u64 = GetObjectField10556Bit3(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField11848Bits5To7(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90750)) { ctx.r3.u64 = object; __imp__sub_82B90750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90750);
	return (LOAD32(object + 11848) >> 5) & 7;
}
PROMOTED_ENTRY(85, sub_82B90750, 0x82B90750) { ctx.r3.u64 = GetObjectField11848Bits5To7(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField11848Bits8To12(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90770)) { ctx.r3.u64 = object; __imp__sub_82B90770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90770);
	return (LOAD32(object + 11848) >> 8) & 31;
}
PROMOTED_ENTRY(85, sub_82B90770, 0x82B90770) { ctx.r3.u64 = GetObjectField11848Bits8To12(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField11848Bits21To23(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B907E0)) { ctx.r3.u64 = object; __imp__sub_82B907E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B907E0);
	return (LOAD32(object + 11848) >> 21) & 7;
}
PROMOTED_ENTRY(85, sub_82B907E0, 0x82B907E0) { ctx.r3.u64 = GetObjectField11848Bits21To23(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField11852Bit30(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90958)) { ctx.r3.u64 = object; __imp__sub_82B90958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90958);
	return (LOAD32(object + 11852) >> 30) & 1;
}
PROMOTED_ENTRY(85, sub_82B90958, 0x82B90958) { ctx.r3.u64 = GetObjectField11852Bit30(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10680Bit10(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90A38)) { ctx.r3.u64 = object; __imp__sub_82B90A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90A38);
	return (LOAD32(object + 10680) >> 10) & 1;
}
PROMOTED_ENTRY(85, sub_82B90A38, 0x82B90A38) { ctx.r3.u64 = GetObjectField10680Bit10(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bit2(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90AF0)) { ctx.r3.u64 = object; __imp__sub_82B90AF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90AF0);
	return (LOAD32(object + 10548) >> 2) & 1;
}
PROMOTED_ENTRY(85, sub_82B90AF0, 0x82B90AF0) { ctx.r3.u64 = GetObjectField10548Bit2(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits4To6(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90B00)) { ctx.r3.u64 = object; __imp__sub_82B90B00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90B00);
	return (LOAD32(object + 10548) >> 4) & 7;
}
PROMOTED_ENTRY(85, sub_82B90B00, 0x82B90B00) { ctx.r3.u64 = GetObjectField10548Bits4To6(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bit7(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90B40)) { ctx.r3.u64 = object; __imp__sub_82B90B40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90B40);
	return (LOAD32(object + 10548) >> 7) & 1;
}
PROMOTED_ENTRY(85, sub_82B90B40, 0x82B90B40) { ctx.r3.u64 = GetObjectField10548Bit7(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits8To10(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90B50)) { ctx.r3.u64 = object; __imp__sub_82B90B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90B50);
	return (LOAD32(object + 10548) >> 8) & 7;
}
PROMOTED_ENTRY(85, sub_82B90B50, 0x82B90B50) { ctx.r3.u64 = GetObjectField10548Bits8To10(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits11To13(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90B60)) { ctx.r3.u64 = object; __imp__sub_82B90B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90B60);
	return (LOAD32(object + 10548) >> 11) & 7;
}
PROMOTED_ENTRY(85, sub_82B90B60, 0x82B90B60) { ctx.r3.u64 = GetObjectField10548Bits11To13(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits17To19(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90B70)) { ctx.r3.u64 = object; __imp__sub_82B90B70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90B70);
	return (LOAD32(object + 10548) >> 17) & 7;
}
PROMOTED_ENTRY(85, sub_82B90B70, 0x82B90B70) { ctx.r3.u64 = GetObjectField10548Bits17To19(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits14To16(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90B80)) { ctx.r3.u64 = object; __imp__sub_82B90B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90B80);
	return (LOAD32(object + 10548) >> 14) & 7;
}
PROMOTED_ENTRY(85, sub_82B90B80, 0x82B90B80) { ctx.r3.u64 = GetObjectField10548Bits14To16(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits20To22(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90BB0)) { ctx.r3.u64 = object; __imp__sub_82B90BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90BB0);
	return (LOAD32(object + 10548) >> 20) & 7;
}
PROMOTED_ENTRY(85, sub_82B90BB0, 0x82B90BB0) { ctx.r3.u64 = GetObjectField10548Bits20To22(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits23To25(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90BE8)) { ctx.r3.u64 = object; __imp__sub_82B90BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90BE8);
	return (LOAD32(object + 10548) >> 23) & 7;
}
PROMOTED_ENTRY(85, sub_82B90BE8, 0x82B90BE8) { ctx.r3.u64 = GetObjectField10548Bits23To25(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10548Bits26To28(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90C50)) { ctx.r3.u64 = object; __imp__sub_82B90C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90C50);
	return (LOAD32(object + 10548) >> 26) & 7;
}
PROMOTED_ENTRY(85, sub_82B90C50, 0x82B90C50) { ctx.r3.u64 = GetObjectField10548Bits26To28(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10568Bit15(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90D90)) { ctx.r3.u64 = object; __imp__sub_82B90D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90D90);
	return (LOAD32(object + 10568) >> 15) & 1;
}
PROMOTED_ENTRY(85, sub_82B90D90, 0x82B90D90) { ctx.r3.u64 = GetObjectField10568Bit15(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10540Bits4To7(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90ED0)) { ctx.r3.u64 = object; __imp__sub_82B90ED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90ED0);
	return (LOAD32(object + 10540) >> 4) & 15;
}
PROMOTED_ENTRY(85, sub_82B90ED0, 0x82B90ED0) { ctx.r3.u64 = GetObjectField10540Bits4To7(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10540Bits8To11(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90EE0)) { ctx.r3.u64 = object; __imp__sub_82B90EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90EE0);
	return (LOAD32(object + 10540) >> 8) & 15;
}
PROMOTED_ENTRY(85, sub_82B90EE0, 0x82B90EE0) { ctx.r3.u64 = GetObjectField10540Bits8To11(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10540Bits12To15(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90EF0)) { ctx.r3.u64 = object; __imp__sub_82B90EF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90EF0);
	return (LOAD32(object + 10540) >> 12) & 15;
}
PROMOTED_ENTRY(85, sub_82B90EF0, 0x82B90EF0) { ctx.r3.u64 = GetObjectField10540Bits12To15(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10540Bits20To23(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90F10)) { ctx.r3.u64 = object; __imp__sub_82B90F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90F10);
	return (LOAD32(object + 10540) >> 20) & 15;
}
PROMOTED_ENTRY(85, sub_82B90F10, 0x82B90F10) { ctx.r3.u64 = GetObjectField10540Bits20To23(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10544Bits4To7(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90F50)) { ctx.r3.u64 = object; __imp__sub_82B90F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90F50);
	return (LOAD32(object + 10544) >> 4) & 15;
}
PROMOTED_ENTRY(85, sub_82B90F50, 0x82B90F50) { ctx.r3.u64 = GetObjectField10544Bits4To7(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10544Bits8To11(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90F60)) { ctx.r3.u64 = object; __imp__sub_82B90F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90F60);
	return (LOAD32(object + 10544) >> 8) & 15;
}
PROMOTED_ENTRY(85, sub_82B90F60, 0x82B90F60) { ctx.r3.u64 = GetObjectField10544Bits8To11(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10544Bits12To15(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90F70)) { ctx.r3.u64 = object; __imp__sub_82B90F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90F70);
	return (LOAD32(object + 10544) >> 12) & 15;
}
PROMOTED_ENTRY(85, sub_82B90F70, 0x82B90F70) { ctx.r3.u64 = GetObjectField10544Bits12To15(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10544Bits20To23(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B90F90)) { ctx.r3.u64 = object; __imp__sub_82B90F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B90F90);
	return (LOAD32(object + 10544) >> 20) & 15;
}
PROMOTED_ENTRY(85, sub_82B90F90, 0x82B90F90) { ctx.r3.u64 = GetObjectField10544Bits20To23(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10568Bit21(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B91268)) { ctx.r3.u64 = object; __imp__sub_82B91268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B91268);
	return (LOAD32(object + 10568) >> 21) & 1;
}
PROMOTED_ENTRY(85, sub_82B91268, 0x82B91268) { ctx.r3.u64 = GetObjectField10568Bit21(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10556Bit4(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B912A0)) { ctx.r3.u64 = object; __imp__sub_82B912A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B912A0);
	return (LOAD32(object + 10556) >> 4) & 1;
}
PROMOTED_ENTRY(85, sub_82B912A0, 0x82B912A0) { ctx.r3.u64 = GetObjectField10556Bit4(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField11852Bits20To22(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B91380)) { ctx.r3.u64 = object; __imp__sub_82B91380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B91380);
	return (LOAD32(object + 11852) >> 20) & 7;
}
PROMOTED_ENTRY(85, sub_82B91380, 0x82B91380) { ctx.r3.u64 = GetObjectField11852Bits20To22(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField11852Bits17To19(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B91390)) { ctx.r3.u64 = object; __imp__sub_82B91390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B91390);
	return (LOAD32(object + 11852) >> 17) & 7;
}
PROMOTED_ENTRY(85, sub_82B91390, 0x82B91390) { ctx.r3.u64 = GetObjectField11852Bits17To19(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10560Bit3(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B913A0)) { ctx.r3.u64 = object; __imp__sub_82B913A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B913A0);
	return (LOAD32(object + 10560) >> 3) & 1;
}
PROMOTED_ENTRY(85, sub_82B913A0, 0x82B913A0) { ctx.r3.u64 = GetObjectField10560Bit3(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10560Bit2(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B913B0)) { ctx.r3.u64 = object; __imp__sub_82B913B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B913B0);
	return (LOAD32(object + 10560) >> 2) & 1;
}
PROMOTED_ENTRY(85, sub_82B913B0, 0x82B913B0) { ctx.r3.u64 = GetObjectField10560Bit2(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField10560Bit5(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B913C0)) { ctx.r3.u64 = object; __imp__sub_82B913C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B913C0);
	return (LOAD32(object + 10560) >> 5) & 1;
}
PROMOTED_ENTRY(85, sub_82B913C0, 0x82B913C0) { ctx.r3.u64 = GetObjectField10560Bit5(ctx, base, ctx.r3.u32); }

uint64_t GetObjectField11852Bits23To29(CpuState& ctx, uint8_t* base, uint32_t object) {
	if (!UseLiftedCode(85, 0x82B913F8)) { ctx.r3.u64 = object; __imp__sub_82B913F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B913F8);
	return (LOAD32(object + 11852) >> 23) & 127;
}
PROMOTED_ENTRY(85, sub_82B913F8, 0x82B913F8) { ctx.r3.u64 = GetObjectField11852Bits23To29(ctx, base, ctx.r3.u32); }

uint64_t CompareBytes(CpuState& ctx, uint8_t* base, uint32_t leftBytePointer, uint32_t rightBytePointer) {
	if (!UseLiftedCode(85, 0x82B93140)) { ctx.r3.u64 = leftBytePointer; ctx.r4.u64 = rightBytePointer; __imp__sub_82B93140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B93140);
	uint64_t byteDifference{};
	byteDifference = (uint64_t)LOAD8(leftBytePointer) - (uint64_t)LOAD8(rightBytePointer);
	return byteDifference;
}
PROMOTED_ENTRY(85, sub_82B93140, 0x82B93140) { ctx.r3.u64 = CompareBytes(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t Lua_Math_Sin_82BD11E0(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD11E0)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD11E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD11E0);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Sin(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD11E0, 0x82BD11E0) { ctx.r3.u64 = Lua_Math_Sin_82BD11E0(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_SinApprox_82BD1290(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD1290)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD1290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD1290);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_SinApprox(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD1290, 0x82BD1290) { ctx.r3.u64 = Lua_Math_SinApprox_82BD1290(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Tan_82BD1340(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD1340)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD1340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD1340);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = tan(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD1340, 0x82BD1340) { ctx.r3.u64 = Lua_Math_Tan_82BD1340(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Cos_82BD1398(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD1398)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD1398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD1398);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Cos(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD1398, 0x82BD1398) { ctx.r3.u64 = Lua_Math_Cos_82BD1398(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Asin_82BD13F0(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD13F0)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD13F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD13F0);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Asin(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD13F0, 0x82BD13F0) { ctx.r3.u64 = Lua_Math_Asin_82BD13F0(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Acos_82BD1448(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD1448)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD1448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD1448);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Acos(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD1448, 0x82BD1448) { ctx.r3.u64 = Lua_Math_Acos_82BD1448(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Atan_82BD14A0(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD14A0)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD14A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD14A0);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = atan(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD14A0, 0x82BD14A0) { ctx.r3.u64 = Lua_Math_Atan_82BD14A0(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Ceil_82BD1570(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD1570)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD1570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD1570);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = ceil(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD1570, 0x82BD1570) { ctx.r3.u64 = Lua_Math_Ceil_82BD1570(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Floor_82BD15C8(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD15C8)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD15C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD15C8);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = floor(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD15C8, 0x82BD15C8) { ctx.r3.u64 = Lua_Math_Floor_82BD15C8(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Log_82BD17F0(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD17F0)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD17F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD17F0);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = log(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD17F0, 0x82BD17F0) { ctx.r3.u64 = Lua_Math_Log_82BD17F0(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Log10_82BD1848(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD1848)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD1848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD1848);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = log10f(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD1848, 0x82BD1848) { ctx.r3.u64 = Lua_Math_Log10_82BD1848(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_Math_Exp_82BD18A0(CpuState& ctx, uint8_t* base, uint64_t luaState, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(87, 0x82BD18A0)) { ctx.r3.u64 = luaState; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; __imp__sub_82BD18A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BD18A0);
	uint32_t stack = ctx.r1.u64;
	double value = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	Lua_CheckNumber(ctx, base, luaState, 1, arg2, arg3, arg4);
	value = ctx.f1.f64;
	value = Math_Exp(ctx, base, ctx.f1.f64);
	uint32_t buffer = LOAD32((uint32_t)luaState + 8);
	ctx.fpscr.disableFlushMode();
	STORE_F32(buffer, float(double(float(value))));
	STORE32(buffer + 4, 3u);
	STORE32((uint32_t)luaState + 8, uint32_t((int64_t)(uint64_t)LOAD32((uint32_t)luaState + 8) + 8));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = value;
	return 1;
}
PROMOTED_ENTRY(87, sub_82BD18A0, 0x82BD18A0) { ctx.r3.u64 = Lua_Math_Exp_82BD18A0(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t Lua_GetState(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_833348A8 = int32_t(0x833348A8);
	if (!UseLiftedCode(89, 0x82BF6218)) { __imp__sub_82BF6218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF6218);
	return g_833348A8;
}
PROMOTED_ENTRY(89, sub_82BF6218, 0x82BF6218) { ctx.r3.u64 = Lua_GetState(ctx, base); }

uint32_t ReturnOne82BF8FA8(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(89, 0x82BF8FA8)) { __imp__sub_82BF8FA8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BF8FA8);
	return 1;
}
PROMOTED_ENTRY(89, sub_82BF8FA8, 0x82BF8FA8) { ctx.r3.u64 = ReturnOne82BF8FA8(ctx, base); }

uint32_t ReturnZero82BF9188(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(89, 0x82BF9188)) { __imp__sub_82BF9188(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BF9188);
	return 0;
}
PROMOTED_ENTRY(89, sub_82BF9188, 0x82BF9188) { ctx.r3.u64 = ReturnZero82BF9188(ctx, base); }

uint32_t ReturnZero82BF9190(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(89, 0x82BF9190)) { __imp__sub_82BF9190(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BF9190);
	return 0;
}
PROMOTED_ENTRY(89, sub_82BF9190, 0x82BF9190) { ctx.r3.u64 = ReturnZero82BF9190(ctx, base); }

uint64_t GetGlobalAddress832D5FE4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832D5FE4 = int32_t(0x832D5FE4);
	if (!UseLiftedCode(89, 0x82BFCB58)) { __imp__sub_82BFCB58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BFCB58);
	return g_832D5FE4;
}
PROMOTED_ENTRY(89, sub_82BFCB58, 0x82BFCB58) { ctx.r3.u64 = GetGlobalAddress832D5FE4(ctx, base); }

uint32_t InitializeGlobalManager(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(89, 0x82BFFB08)) { __imp__sub_82BFFB08(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BFFB08);
	uint32_t result{};
	result = EnsureGlobalManagerInitialized(ctx, base);
	return result;
}
PROMOTED_ENTRY(89, sub_82BFFB08, 0x82BFFB08) { ctx.r3.u64 = InitializeGlobalManager(ctx, base); }

uint32_t IsGlobalManagerReady(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(89, 0x82BFFB38)) { __imp__sub_82BFFB38(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BFFB38);
	uint32_t result{};
	result = IsGlobalManagerInitialized(ctx, base);
	return result;
}
PROMOTED_ENTRY(89, sub_82BFFB38, 0x82BFFB38) { ctx.r3.u64 = IsGlobalManagerReady(ctx, base); }

// sub_82C021B8  [148 bytes]
uint32_t n_sub_82C021B8(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(89, 0x82C021B8)) { ctx.r3.u64 = arg1; ctx.r5.u64 = arg2; __imp__sub_82C021B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C021B8);
	// Returns 1 only when the virtual method at +24, n_sub_82C01ED0 and the virtual method at +28 all return a
	// non-zero low byte, each called only when the one before did.
	GameStackFrame stackFrame(ctx, base, 112);
	uint32_t result = 0;
	PPCRegister callTarget;
	uint32_t method24 = LOAD32(LOAD32((uint32_t)arg1) + 24);
	callTarget.u64 = (uint64_t)method24;
	ctx.r3.u64 = arg1;
	ctx.r5.u64 = arg2;
	ctx.r10.u64 = method24;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t firstResult = ctx.r3.u32 & 0xFF;
	if (firstResult != 0) {
		ctx.r9.u64 = firstResult;
		uint32_t secondResult = n_sub_82C01ED0(ctx, base, arg1, arg2) & 0xFF;
		if (secondResult != 0) {
			uint32_t method28 = LOAD32(LOAD32((uint32_t)arg1) + 28);
			callTarget.u64 = (uint64_t)method28;
			ctx.r3.u64 = arg1;
			ctx.r10.u64 = method28;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((ctx.r3.u32 & 0xFF) != 0) {
				result = 1;
			}
		}
	}
	return result;
}
PROMOTED_ENTRY(89, sub_82C021B8, 0x82C021B8) { ctx.r3.u64 = n_sub_82C021B8(ctx, base, ctx.r3.u64, ctx.r5.u64); }

uint64_t CMusicalNote_CopyString96(CpuState& ctx, uint8_t* base, uint64_t destString, uint64_t record) {
	if (!UseLiftedCode(89, 0x82C0B360)) { ctx.r3.u64 = destString; ctx.r4.u64 = record; __imp__sub_82C0B360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0B360);
	GameStackFrame stackFrame(ctx, base, 96);
	record = (int64_t)record + 96;
	CCharString_CopyConstruct(ctx, base, destString, record);
	return destString;
}
PROMOTED_ENTRY(89, sub_82C0B360, 0x82C0B360) { ctx.r3.u64 = CMusicalNote_CopyString96(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CMusicalNote_CopyString60(CpuState& ctx, uint8_t* base, uint64_t destString, uint64_t record) {
	if (!UseLiftedCode(89, 0x82C0B3A0)) { ctx.r3.u64 = destString; ctx.r4.u64 = record; __imp__sub_82C0B3A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0B3A0);
	GameStackFrame stackFrame(ctx, base, 96);
	record = (int64_t)record + 60;
	CCharString_CopyConstruct(ctx, base, destString, record);
	return destString;
}
PROMOTED_ENTRY(89, sub_82C0B3A0, 0x82C0B3A0) { ctx.r3.u64 = CMusicalNote_CopyString60(ctx, base, ctx.r3.u64, ctx.r4.u64); }

void SetIsZeroFlag(CpuState& ctx, uint8_t* base, uint32_t object, uint32_t value2) {
	if (!UseLiftedCode(92, 0x82C61680)) { ctx.r3.u64 = object; ctx.r4.u64 = value2; __imp__sub_82C61680(ctx, base); return; }
	LiftedFrame frame(0x82C61680);
	uint32_t isZero{};
	isZero = (uint32_t(value2 == 0 ? 32 : __builtin_clz(value2)) >> 5) & 1;
	StoreBoolFlag(ctx, base, object, isZero);
	return;
}
PROMOTED_ENTRY(92, sub_82C61680, 0x82C61680) { SetIsZeroFlag(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CreateSocket(CpuState& ctx, uint8_t* base, uint64_t socketType) {
	if (!UseLiftedCode(92, 0x82C72BD0)) { ctx.r3.u64 = socketType; __imp__sub_82C72BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C72BD0);
	uint32_t addressFamily{};
	uint64_t socketHandle{};
	uint32_t protocol{};
	protocol = 0;
	addressFamily = 2;
	socketHandle = socket(ctx, base, addressFamily, socketType, protocol);
	return socketHandle;
}
PROMOTED_ENTRY(92, sub_82C72BD0, 0x82C72BD0) { ctx.r3.u64 = CreateSocket(ctx, base, ctx.r3.u64); }

uint64_t CBinaryStreaming_GetBuffer(CpuState& ctx, uint8_t* base, uint64_t bufferObject) {
	if (!UseLiftedCode(93, 0x82C816E0)) { ctx.r3.u64 = bufferObject; __imp__sub_82C816E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C816E0);
	bufferObject = LOAD32((uint32_t)bufferObject);
	return bufferObject;
}
PROMOTED_ENTRY(93, sub_82C816E0, 0x82C816E0) { ctx.r3.u64 = CBinaryStreaming_GetBuffer(ctx, base, ctx.r3.u64); }

void StoreU32(CpuState& ctx, uint8_t* base, uint32_t address, uint32_t value2) {
	if (!UseLiftedCode(93, 0x82C816E8)) { ctx.r3.u64 = address; ctx.r4.u64 = value2; __imp__sub_82C816E8(ctx, base); return; }
	LiftedFrame frame(0x82C816E8);
	STORE32(address, value2);
	return;
}
PROMOTED_ENTRY(93, sub_82C816E8, 0x82C816E8) { StoreU32(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t Memory_Alloc(CpuState& ctx, uint8_t* base, uint64_t size) {
	if (!UseLiftedCode(93, 0x82C88628)) { ctx.r3.u64 = size; __imp__sub_82C88628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C88628);
	uint64_t allocation{};
	allocation = AllocateWithCounter(ctx, base, size);
	return allocation;
}
PROMOTED_ENTRY(93, sub_82C88628, 0x82C88628) { ctx.r3.u64 = Memory_Alloc(ctx, base, ctx.r3.u64); }

uint32_t XmlNode_AddAttribute(CpuState& ctx, uint8_t* base, uint64_t node, uint64_t attribute) {
	if (!UseLiftedCode(93, 0x82C88CF0)) { ctx.r3.u64 = node; ctx.r4.u64 = attribute; __imp__sub_82C88CF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C88CF0);
	uint32_t result{};
	node = (int64_t)node + 12;
	result = String_Assign(ctx, base, node, attribute);
	return result;
}
PROMOTED_ENTRY(93, sub_82C88CF0, 0x82C88CF0) { ctx.r3.u64 = XmlNode_AddAttribute(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CStringTable_FindFromMember(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t stringKey) {
	if (!UseLiftedCode(93, 0x82C88CF8)) { ctx.r3.u64 = object; ctx.r4.u64 = stringKey; __imp__sub_82C88CF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C88CF8);
	uint32_t result{};
	object = (int64_t)object + 12;
	result = CStringTable_FindLocked(ctx, base, object, stringKey);
	return result;
}
PROMOTED_ENTRY(93, sub_82C88CF8, 0x82C88CF8) { ctx.r3.u64 = CStringTable_FindFromMember(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t StoreUInt32(CpuState& ctx, uint8_t* base, uint32_t destination, uint32_t value2) {
	if (!UseLiftedCode(123, 0x82FFAE68)) { ctx.r3.u64 = destination; ctx.r4.u64 = value2; __imp__sub_82FFAE68(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82FFAE68);
	uint32_t bytesWritten{};
	STORE32(destination, value2);
	bytesWritten = 4;
	return bytesWritten;
}
PROMOTED_ENTRY(123, sub_82FFAE68, 0x82FFAE68) { ctx.r3.u64 = StoreUInt32(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t ReturnOne83211B20(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211B20)) { __imp__sub_83211B20(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211B20);
	return 1;
}
PROMOTED_ENTRY(141, sub_83211B20, 0x83211B20) { ctx.r3.u64 = ReturnOne83211B20(ctx, base); }

uint32_t ReturnOne83211B28(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211B28)) { __imp__sub_83211B28(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211B28);
	return 1;
}
PROMOTED_ENTRY(141, sub_83211B28, 0x83211B28) { ctx.r3.u64 = ReturnOne83211B28(ctx, base); }

uint32_t ReturnOne83211B48(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211B48)) { __imp__sub_83211B48(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211B48);
	return 1;
}
PROMOTED_ENTRY(141, sub_83211B48, 0x83211B48) { ctx.r3.u64 = ReturnOne83211B48(ctx, base); }

uint32_t ReturnZero83211B60(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211B60)) { __imp__sub_83211B60(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211B60);
	return 0;
}
PROMOTED_ENTRY(141, sub_83211B60, 0x83211B60) { ctx.r3.u64 = ReturnZero83211B60(ctx, base); }

uint32_t ReturnZero83211B88(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211B88)) { __imp__sub_83211B88(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211B88);
	return 0;
}
PROMOTED_ENTRY(141, sub_83211B88, 0x83211B88) { ctx.r3.u64 = ReturnZero83211B88(ctx, base); }

uint32_t ReturnFive83211B90(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211B90)) { __imp__sub_83211B90(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211B90);
	return 5;
}
PROMOTED_ENTRY(141, sub_83211B90, 0x83211B90) { ctx.r3.u64 = ReturnFive83211B90(ctx, base); }

uint32_t ReturnOne83211B98(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211B98)) { __imp__sub_83211B98(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211B98);
	return 1;
}
PROMOTED_ENTRY(141, sub_83211B98, 0x83211B98) { ctx.r3.u64 = ReturnOne83211B98(ctx, base); }

uint32_t ReturnFour83211BA0(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211BA0)) { __imp__sub_83211BA0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211BA0);
	return 4;
}
PROMOTED_ENTRY(141, sub_83211BA0, 0x83211BA0) { ctx.r3.u64 = ReturnFour83211BA0(ctx, base); }

uint32_t ReturnZero83211BB8(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211BB8)) { __imp__sub_83211BB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211BB8);
	return 0;
}
PROMOTED_ENTRY(141, sub_83211BB8, 0x83211BB8) { ctx.r3.u64 = ReturnZero83211BB8(ctx, base); }

uint32_t ReturnZero83211BC0(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211BC0)) { __imp__sub_83211BC0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211BC0);
	return 0;
}
PROMOTED_ENTRY(141, sub_83211BC0, 0x83211BC0) { ctx.r3.u64 = ReturnZero83211BC0(ctx, base); }

uint32_t ReturnZero83211BD8(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211BD8)) { __imp__sub_83211BD8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211BD8);
	return 0;
}
PROMOTED_ENTRY(141, sub_83211BD8, 0x83211BD8) { ctx.r3.u64 = ReturnZero83211BD8(ctx, base); }

uint32_t ReturnOne83211BE0(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211BE0)) { __imp__sub_83211BE0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211BE0);
	return 1;
}
PROMOTED_ENTRY(141, sub_83211BE0, 0x83211BE0) { ctx.r3.u64 = ReturnOne83211BE0(ctx, base); }

uint32_t ReturnOne83211BE8(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(141, 0x83211BE8)) { __imp__sub_83211BE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83211BE8);
	return 1;
}
PROMOTED_ENTRY(141, sub_83211BE8, 0x83211BE8) { ctx.r3.u64 = ReturnOne83211BE8(ctx, base); }

uint32_t n_sub_83227750(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(142, 0x83227750)) { __imp__sub_83227750(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83227750);
	return 9;
}
PROMOTED_ENTRY(142, sub_83227750, 0x83227750) { ctx.r3.u64 = n_sub_83227750(ctx, base); }

uint32_t n_sub_83228E10(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(142, 0x83228E10)) { __imp__sub_83228E10(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83228E10);
	return 0;
}
PROMOTED_ENTRY(142, sub_83228E10, 0x83228E10) { ctx.r3.u64 = n_sub_83228E10(ctx, base); }

uint32_t n_sub_8322A450(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(142, 0x8322A450)) { __imp__sub_8322A450(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8322A450);
	return 5;
}
PROMOTED_ENTRY(142, sub_8322A450, 0x8322A450) { ctx.r3.u64 = n_sub_8322A450(ctx, base); }

uint32_t VirtualFreeDecommit(CpuState& ctx, uint8_t* base, uint32_t address, uint32_t size) {
	if (!UseLiftedCode(142, 0x8322FCA8)) { ctx.r3.u64 = address; ctx.r4.u64 = size; __imp__sub_8322FCA8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8322FCA8);
	uint32_t result{};
	uint32_t freeType{};
	freeType = 16384;
	result = VirtualFree(ctx, base, address, size, freeType);
	return result;
}
PROMOTED_ENTRY(142, sub_8322FCA8, 0x8322FCA8) { ctx.r3.u64 = VirtualFreeDecommit(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t VirtualFreeRelease(CpuState& ctx, uint8_t* base, uint32_t address) {
	if (!UseLiftedCode(142, 0x8322FD00)) { ctx.r3.u64 = address; __imp__sub_8322FD00(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8322FD00);
	uint32_t result{};
	uint32_t size{};
	uint32_t freeType{};
	freeType = 0;
	size = 0;
	freeType = freeType | 32768;
	result = VirtualFree(ctx, base, address, size, freeType);
	return result;
}
PROMOTED_ENTRY(142, sub_8322FD00, 0x8322FD00) { ctx.r3.u64 = VirtualFreeRelease(ctx, base, ctx.r3.u32); }
