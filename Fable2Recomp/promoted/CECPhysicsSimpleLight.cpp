// CECPhysicsSimpleLight (vtable 0x82006FA8): methods of the class as readable C++.
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

uint64_t CECPhysicsSimpleLight_SetColour(CpuState& ctx, uint8_t* base, uint32_t physicsSimpleLightAddr) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(3, 0x821CB1B0)) { ctx.r3.u64 = physicsSimpleLightAddr; __imp__sub_821CB1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821CB1B0);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister savedVector = ctx.v1;
	CECPhysicsSimpleLight* physicsSimpleLight = GameObject<CECPhysicsSimpleLight>(base, physicsSimpleLightAddr);

	stack = PushStackFrame(base, stack, 96);

	uint32_t zero = 0;
	uint64_t lightDesc = (int64_t)g_82000000 + 3988;

	STORE8(stack + 84, (uint8_t)zero);

	uint32_t stackArgAddr = stack + 80;
	STORE32(stack + 80, (uint32_t)lightDesc);

	VSTORE((physicsSimpleLightAddr + 32u) & ~0xF, V8(savedVector));

	uint32_t linkedObject = physicsSimpleLight->m_4;

	ctx.r1.u64 = stack;
	ctx.r7.u64 = lightDesc;
	ctx.r8.u64 = zero;

	uint64_t result = Entity_NotifyEvent(ctx, base, linkedObject, stackArgAddr);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;

	return result;
}
PROMOTED_ENTRY(3, sub_821CB1B0, 0x821CB1B0) { ctx.r3.u64 = CECPhysicsSimpleLight_SetColour(ctx, base, ctx.r3.u32); }

uint64_t CECPhysicsSimpleLight_UpdateTransform(CpuState& ctx, uint8_t* base, uint64_t physicsSimpleLight, uint64_t sourceTransform) {
	if (!UseLiftedCode(3, 0x821DB4B0)) { ctx.r3.u64 = physicsSimpleLight; ctx.r4.u64 = sourceTransform; __imp__sub_821DB4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821DB4B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	uint32_t self = (uint32_t)physicsSimpleLight;
	uint32_t src = (uint32_t)sourceTransform;

	// first row (16 bytes) of the source rotation block at src + 48
	PPCVRegister srcRow;
	SET_V8(srcRow, VLOAD((src + 48) & ~0xFu));

	uint32_t data = LOAD32(self);
	uint32_t updateFn = LOAD32(data + 100);

	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimpleLight;
	ctx.r4.u64 = sourceTransform;
	ctx.r9.u64 = updateFn;
	ctx.r10.u64 = 48;
	ctx.v1 = srcRow;
	REX_CALL_INDIRECT_FUNC(updateFn);

	uint32_t quatOut = stack + 80;
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = (double)LOAD_F32(0x82099AE0u);
	double quat = Quat_FromMatrix3x3(ctx, base, quatOut, src);

	data = LOAD32(self);
	uint32_t applyFn = LOAD32(data + 104);
	uint64_t quatLo = LOAD64(stack + 80);
	uint64_t quatHi = LOAD64(stack + 88);

	ctx.r3.u64 = physicsSimpleLight;
	ctx.r4.u64 = quatLo;
	ctx.r5.u64 = quatHi;
	ctx.r6.u64 = applyFn;
	ctx.r7.u64 = data;
	ctx.f1.f64 = quat;
	REX_CALL_INDIRECT_FUNC(applyFn);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(3, sub_821DB4B0, 0x821DB4B0) { ctx.r3.u64 = CECPhysicsSimpleLight_UpdateTransform(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECPhysicsSimpleLight_Disable(CpuState& ctx, uint8_t* base, uint64_t physicsSimpleLight) {
	constexpr int32_t g_82000F94 = int32_t(0x82000F94);
	if (!UseLiftedCode(5, 0x821FEEC0)) { ctx.r3.u64 = physicsSimpleLight; __imp__sub_821FEEC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821FEEC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t linkedObject = LOAD32((uint32_t)physicsSimpleLight + 4);
	STORE32(stack + 80, (uint32_t)g_82000F94);
	STORE8(stack + 84, 0);
	uint32_t descriptor = stack + 80;
	ctx.r1.u64 = stack;
	uint64_t result = Entity_NotifyEvent(ctx, base, linkedObject, descriptor);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(5, sub_821FEEC0, 0x821FEEC0) { ctx.r3.u64 = CECPhysicsSimpleLight_Disable(ctx, base, ctx.r3.u64); }

uint64_t CECPhysicsSimpleLight_Enable(CpuState& ctx, uint8_t* base, uint32_t physicsSimpleLightAddr) {
	constexpr int32_t g_82000F94 = int32_t(0x82000F94);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(11, 0x8229B070)) { ctx.r3.u64 = physicsSimpleLightAddr; __imp__sub_8229B070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229B070);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimpleLight* physicsSimpleLight = GameObject<CECPhysicsSimpleLight>(base, physicsSimpleLightAddr);

	stack = PushStackFrame(base, stack, 112);

	STORE8(stack + 84, uint8_t(1));
	STORE32(stack + 80, (uint32_t)g_82000F94);

	uint32_t entityBefore = physicsSimpleLight->m_4;
	ctx.r1.u64 = stack;
	Entity_NotifyEvent(ctx, base, entityBefore, stack + 80);

	uint64_t r9AfterFirstCall = ctx.r9.u64;
	uint32_t carry = ctx.xer.ca;

	uint32_t entityAddr = physicsSimpleLight->m_4;
	uint64_t globalBase = (uint64_t)(int64_t)g_820F0000;
	uint64_t descriptor = globalBase - 1124;
	STORE32(stack + 80, (uint32_t)descriptor);

	uint64_t result = 0;
	uint32_t entityFlags = LOAD32(entityAddr + 36);
	uint32_t flagBit = (entityFlags >> 3) & 1;

	uint32_t r6 = entityFlags;
	uint64_t r7 = descriptor;
	uint64_t r8 = globalBase;
	uint64_t r9 = r9AfterFirstCall;

	if (flagBit != 0) {
		uint32_t currentPtr = LOAD32(entityAddr + 140);
		if (currentPtr != 0) {
			uint32_t index = LOAD8(currentPtr + 3);
			uint32_t arrayBase = LOAD32(entityAddr + 72);
			uint32_t elementOffset = index << 3;
			uint64_t elementPtr = (uint64_t)arrayBase + (uint64_t)elementOffset;
			r9 = elementPtr;
			result = LOAD32((uint32_t)elementPtr + 4);
		} else {
			uint32_t begin = LOAD32(entityAddr + 72);
			uint32_t end = LOAD32(entityAddr + 76);
			r6 = end;
			STORE32(stack + 88, (uint32_t)result);
			STORE32(stack + 92, begin);

			uint32_t diff = end - begin;
			int32_t remaining = (int32_t)diff >> 3;
			if (remaining <= 0) {
				carry = ((int32_t)diff < 0 && (diff & 0x7) != 0) ? 1 : 0;
			} else {
				carry = 0;
			}

			uint32_t it = begin;
			if (remaining > 0) {
				do {
					// At the start of each iteration remaining is positive, so the lifter's carry is 0.
					int32_t half = remaining >> 1;
					uint32_t halfShift = (uint32_t)half << 3;
					uint32_t mid = it + halfShift;
					bool lessThan3 = (int32_t)LOAD32(mid) < 3;
					r7 = lessThan3 ? 1 : 0;
					r8 = halfShift;
					r9 = (uint64_t)(int64_t)half;
					if (lessThan3) {
						it = mid + 8;
						remaining = remaining - half - 1;
					} else {
						it = mid - halfShift;
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 92, it);
			}

			if (it != end && (int32_t)LOAD32(it) <= 3) {
				result = LOAD32(it + 4);
			} else {
				result = LOAD32(end + 4);
			}
		}

		ctx.r5.u64 = (uint64_t)flagBit;
		ctx.r6.u64 = (uint64_t)r6;
		ctx.r7.u64 = r7;
		ctx.r8.u64 = r8;
		ctx.r9.u64 = r9;
		ctx.xer.ca = carry;
		result = C_82001100_UpdateTransform(ctx, base, result);
		carry = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.xer.ca = carry;
	return result;
}
PROMOTED_ENTRY(11, sub_8229B070, 0x8229B070) { ctx.r3.u64 = CECPhysicsSimpleLight_Enable(ctx, base, ctx.r3.u32); }

double CECPhysicsSimpleLight_GetRadius(CpuState& ctx, uint8_t* base, uint32_t physicsSimpleLight) {
	if (!UseLiftedCode(29, 0x824D2880)) { ctx.r3.u64 = physicsSimpleLight; __imp__sub_824D2880(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x824D2880);
	ctx.fpscr.disableFlushMode();
	return double(LOAD_F32(physicsSimpleLight + 12));
}
PROMOTED_ENTRY(29, sub_824D2880, 0x824D2880) { ctx.f1.f64 = CECPhysicsSimpleLight_GetRadius(ctx, base, ctx.r3.u32); }

uint64_t CECPhysicsSimpleLight_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C88D8_B_ = int32_t(0x820C88D8);
	if (!UseLiftedCode(41, 0x82644EF0)) { ctx.r3.u64 = classNameString; __imp__sub_82644EF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82644EF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t classNameCStr = str_TXT_820C88D8_B_;
	int32_t terminator = -1;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameCStr, terminator);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(41, sub_82644EF0, 0x82644EF0) { ctx.r3.u64 = CECPhysicsSimpleLight_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECPhysicsSimpleLight_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t physicsSimpleLight, uint64_t deleteFlags) {
	if (!UseLiftedCode(41, 0x82647688)) { ctx.r3.u64 = physicsSimpleLight; ctx.r4.u64 = deleteFlags; __imp__sub_82647688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82647688);
	uint32_t stack = ctx.r1.u64;
	uint64_t object = physicsSimpleLight;
	uint32_t flags = deleteFlags;

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	C_820A8D10_Destructor_824C2360(ctx, base, physicsSimpleLight);

	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(41, sub_82647688, 0x82647688) { ctx.r3.u64 = CECPhysicsSimpleLight_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

void CECPhysicsSimpleLight_Constructor(CpuState& ctx, uint8_t* base, uint32_t physicsSimpleLightAddr) {
	if (!UseLiftedCode(50, 0x82749370)) { ctx.r3.u64 = physicsSimpleLightAddr; __imp__sub_82749370(ctx, base); return; }
	LiftedFrame frame(0x82749370);
	CECPhysicsSimpleLight* physicsSimpleLight = GameObject<CECPhysicsSimpleLight>(base, physicsSimpleLightAddr);
	// Copy the 16-byte constant pair at 0x8349B360/0x8349B368 into the object.
	const uint32_t stateSource = 0x834A0000 - 19616;
	uint64_t secondQword = LOAD64(stateSource + 8);
	STORE64(physicsSimpleLightAddr, LOAD64(stateSource));
	physicsSimpleLight->m_8 = secondQword;
	return;
}
PROMOTED_ENTRY(50, sub_82749370, 0x82749370) { CECPhysicsSimpleLight_Constructor(ctx, base, ctx.r3.u32); }

void CECPhysicsSimpleLight_SetRadius(CpuState& ctx, uint8_t* base, uint32_t physicsSimpleLight, uint32_t radiusSource) {
	if (!UseLiftedCode(50, 0x82749390)) { ctx.r3.u64 = physicsSimpleLight; ctx.r4.u64 = radiusSource; __imp__sub_82749390(ctx, base); return; }
	LiftedFrame frame(0x82749390);
	ctx.fpscr.disableFlushMode();
	STORE_F32(physicsSimpleLight + 12, float(double(LOAD_F32(radiusSource))));
	return;
}
PROMOTED_ENTRY(50, sub_82749390, 0x82749390) { CECPhysicsSimpleLight_SetRadius(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CECPhysicsSimpleLight_Translate(CpuState& ctx, uint8_t* base, uint64_t physicsSimpleLight) {
	if (!UseLiftedCode(50, 0x827493A0)) { ctx.r3.u64 = physicsSimpleLight; __imp__sub_827493A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827493A0);
	uint32_t stack = ctx.r1.u64;
	const uint32_t self = (uint32_t)physicsSimpleLight;
	PPCVRegister savedV127{};
	PPCVRegister inputVector = ctx.v1;

	SET_V8(savedV127, V8(ctx.v127));
	VSTORE((stack + 0xFFFFFFE0u) & ~0xF, V8(savedV127));

	stack = PushStackFrame(base, stack, 128);

	uint32_t scratch = stack + 80;

	uint32_t getTransformFn = LOAD32(LOAD32(self) + 64);
	PPCRegister callTarget{};
	callTarget.u64 = getTransformFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = scratch;
	ctx.r4.u64 = physicsSimpleLight;
	ctx.r10.u64 = getTransformFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t transformPtr = ctx.r3.u64;

	uint32_t typeInfo = LOAD32(self);
	PPCVRegister loadedVector{};
	SET_V8(loadedVector, VLOAD((uint32_t)transformPtr & ~0xF));
	uint32_t applyFn = LOAD32(typeInfo + 100);

	PPCVRegister sumVector{};
	ctx.fpscr.enableFlushMode();
	SET_VF(sumVector, simde_mm_add_ps(VF(loadedVector), VF(inputVector)));

	callTarget.u64 = applyFn;
	ctx.r3.u64 = physicsSimpleLight;
	ctx.r7.u64 = applyFn;
	ctx.r8.u64 = typeInfo;
	ctx.r9.u64 = transformPtr;
	ctx.v1 = sumVector;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 128);
	SET_V8(savedV127, VLOAD((stack + 0xFFFFFFE0u) & ~0xF));
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(50, sub_827493A0, 0x827493A0) { ctx.r3.u64 = CECPhysicsSimpleLight_Translate(ctx, base, ctx.r3.u64); }
