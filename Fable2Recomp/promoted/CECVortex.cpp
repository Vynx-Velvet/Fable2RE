// CECVortex (vtable 0x820D0A70): methods of the class as readable C++.
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

uint64_t CECVortex_GetClassName(CpuState& ctx, uint8_t* base, uint64_t outName) {
	constexpr int32_t str_TXT_820C8EB8_B_ = int32_t(0x820C8EB8);
	if (!UseLiftedCode(49, 0x8272F040)) { ctx.r3.u64 = outName; __imp__sub_8272F040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8272F040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	// the string object is constructed in place at outName (the caller's result slot)
	const uint64_t classNameCStr = str_TXT_820C8EB8_B_;
	const int32_t length = -1;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, outName, classNameCStr, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return outName;
}
PROMOTED_ENTRY(49, sub_8272F040, 0x8272F040) { ctx.r3.u64 = CECVortex_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECVortex_GetEntity(CpuState& ctx, uint8_t* base, uint64_t vortexAddr) {
	if (!UseLiftedCode(49, 0x8272F080)) { ctx.r3.u64 = vortexAddr; __imp__sub_8272F080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8272F080);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	// EntityHandle at +352: its word at +4 points at the cell holding the entity
	const uint64_t handleAddr = vortexAddr + 352;
	const uint32_t target = LOAD32((uint32_t)handleAddr + 4);
	if (target != 0) {
		const uint32_t entity = LOAD32(target);
		if (entity != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return entity;
		}
		// the cell is empty: release the handle
		ctx.r1.u64 = stack;
		ctx.r10.u64 = 0;  // state the callee may pass on
		EntityHandle_Release(ctx, base, handleAddr);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(49, sub_8272F080, 0x8272F080) { ctx.r3.u64 = CECVortex_GetEntity(ctx, base, ctx.r3.u64); }

// sub_8272F330  [80 bytes]
uint64_t n_sub_8272F330(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t flags) {
	if (!UseLiftedCode(49, 0x8272F330)) { ctx.r3.u64 = object; ctx.r4.u64 = flags; __imp__sub_8272F330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8272F330);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flags;  // state the callee may pass on
	n_sub_8272F380(ctx, base, object);
	// bit 0 set: the object's memory is freed as well
	if ((uint32_t(flags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(49, sub_8272F330, 0x8272F330) { ctx.r3.u64 = n_sub_8272F330(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_8272FFD8  [508 bytes]
uint64_t n_sub_8272FFD8(CpuState& ctx, uint8_t* base, uint64_t vortexAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(49, 0x8272FFD8)) { ctx.r3.u64 = vortexAddr; __imp__sub_8272FFD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8272FFD8);
	PPCVRegister savedV127 = ctx.v127;  // (restored on return)
	uint32_t stack = ctx.r1.u64;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	VSTORE((stack + 0xFFFFFF80u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 288);

	const uint32_t floatConstAddr = uint32_t(g_820A0000) - 25888;  // 0x82099AE0
	const uint32_t tempHandleAddr = stack + 144;
	uint64_t result = vortexAddr;

	// n_sub_82264448 maps the 8-byte value at keyAddr to an entity; the result goes into the
	// EntityHandle at handleAddr through a temporary handle at stack+144.
	auto assignHandleFromKey = [&](uint64_t keyAddr, uint64_t handleAddr) {
		uint32_t root = LOAD32(uint32_t(g_83490000) + 26912);
		root = LOAD32(root + 12);
		const uint32_t lookupObject = LOAD32(LOAD32(LOAD32(root + 88) + 4));
		ctx.r1.u64 = stack;
		const uint64_t entity = n_sub_82264448(ctx, base, lookupObject, keyAddr);
		STORE32(tempHandleAddr, uint32_t(g_820F1664));
		STORE32(tempHandleAddr + 4, 0);
		EntityHandle_SetTarget(ctx, base, (uint64_t)stack + 144, entity);
		EntityHandle_Assign(ctx, base, handleAddr, (uint64_t)stack + 144);
		STORE32(tempHandleAddr, uint32_t(g_820F1664));
		EntityHandle_Release(ctx, base, (uint64_t)stack + 144);
	};

	if (LOAD8((uint32_t)vortexAddr + 228) != 0) {
		// a key whose two words are both zero is skipped
		const uint64_t key1Addr = vortexAddr + 408;
		if (LOAD32((uint32_t)key1Addr) != 0 || LOAD32((uint32_t)key1Addr + 4) != 0) {
			assignHandleFromKey(key1Addr, vortexAddr + 352);
		}
		const uint64_t key2Addr = vortexAddr + 416;
		uint64_t r4ForGet = key2Addr;  // r4 handed to the first EntityHandle_Get_825575C8 below
		if (LOAD32((uint32_t)key2Addr) != 0 || LOAD32((uint32_t)key2Addr + 4) != 0) {
			assignHandleFromKey(key2Addr, vortexAddr + 360);
			r4ForGet = ctx.r4.u64;
		}

		// normalised direction from the vector at +272 to the vector at +288, stored at stack+144
		const uint32_t directionAddr = stack + 144;
		PPCVRegister from{};
		SET_V8(from, VLOAD(((uint32_t)vortexAddr + 272) & ~0xF));
		PPCVRegister to{};
		SET_V8(to, VLOAD(((uint32_t)vortexAddr + 288) & ~0xF));
		ctx.fpscr.enableFlushMode();
		PPCVRegister delta{};
		SET_VF(delta, simde_mm_sub_ps(VF(to), VF(from)));
		ctx.fpscr.disableFlushModeUnconditional();
		const double threshold = double(LOAD_F32(floatConstAddr));
		VSTORE(directionAddr & ~0xF, V8(delta));
		ctx.r1.u64 = stack;
		const double distance = Vec4_NormalizeInPlace_ReturnLength(ctx, base, directionAddr, threshold);

		ctx.fpscr.disableFlushMode();
		const double m60 = vortex->m_60;
		const uint32_t m24 = vortex->m_24;
		const double m5C = vortex->m_5C;
		const uint32_t m14 = vortex->m_14;
		const double m38 = vortex->m_38;
		const uint32_t mE3 = vortex->m_E3;
		const double m34 = vortex->m_34;
		const uint32_t m18 = vortex->m_18;
		const double m30 = vortex->m_30;

		// state the callee may pass on
		ctx.r4.u64 = r4ForGet;
		ctx.f1.f64 = distance;
		const uint64_t entity360 = EntityHandle_Get_825575C8(ctx, base, vortexAddr + 360);
		const uint64_t entity352 = EntityHandle_Get_825575C8(ctx, base, vortexAddr + 352);
		ctx.fpscr.disableFlushMode();
		STORE32(stack + 124, m24);

		// state the callee may pass on: v1 = start vector, v2 = direction, v127 = start vector
		ctx.v1 = from;
		SET_V8(ctx.v2, VLOAD(directionAddr & ~0xF));
		ctx.v127 = from;
		result = n_sub_827301D8(ctx, base, vortexAddr, entity352, entity360,
		                        m18, mE3, m14, m30, m34, m38, m5C, m60);
	}
	ctx.fpscr.disableFlushMode();
	const double m40Value = double(LOAD_F32(floatConstAddr));
	ctx.fpscr.disableFlushMode();
	vortex->m_40 = float(m40Value);

	stack = PopStackFrame(stack, 288);
	ctx.r1.u64 = stack;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(49, sub_8272FFD8, 0x8272FFD8) { ctx.r3.u64 = n_sub_8272FFD8(ctx, base, ctx.r3.u64); }

// sub_82730978  [328 bytes]
uint64_t n_sub_82730978(CpuState& ctx, uint8_t* base, uint64_t vortexAddr, uint64_t r8Value) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(49, 0x82730978)) { ctx.r3.u64 = vortexAddr; ctx.r8.u64 = r8Value; __imp__sub_82730978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82730978);
	uint32_t stack = ctx.r1.u64;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	// r9, cr0 and xer.ca are handed to the calls of the handle loop and EntityHandleVector_Clear
	PPCXERRegister flags = ctx.xer;
	PPCCRRegister compare0{};
	stack = PushStackFrame(base, stack, 128);

	for (uint64_t index = 0; index < 4; ++index) {
		ctx.r1.u64 = stack;
		ctx.r8.u64 = r8Value;  // state the callee may pass on
		n_sub_82731F28(ctx, base, vortexAddr, index, 0);
		r8Value = ctx.r8.u64;
	}
	n_sub_827323E8(ctx, base, vortexAddr);
	uint64_t r9Value = ctx.r9.u64;
	flags.ca = ctx.xer.ca;

	// vector of 8-byte EntityHandles at +0x1B0 (begin at +4, end at +8): pass each handle's
	// entity (0 when gone; a stale handle is released) to n_sub_82734508, then clear the vector
	const uint64_t handleVectorAddr = vortexAddr + 432;
	const uint32_t firstBegin = vortex->m_1B4;
	if (firstBegin != 0) {
		r9Value = (uint64_t)LOAD32((uint32_t)handleVectorAddr + 8) - (uint64_t)firstBegin;
		flags.ca = (int32_t)r9Value < 0 && ((uint32_t)r9Value & 0x7) != 0;  // carry of the shift
		const int32_t handleCount = (int32_t)r9Value >> 3;
		compare0.compare<int32_t>(handleCount, 0, flags);
		uint64_t elementOffset = 0;
		for (int32_t i = 0; i < handleCount; ++i) {
			// bounds check of the index against the current size
			const uint32_t begin = LOAD32((uint32_t)handleVectorAddr + 4);
			if (begin != 0) {
				r9Value = (uint64_t)LOAD32((uint32_t)handleVectorAddr + 8) - (uint64_t)begin;
				flags.ca = (int32_t)r9Value < 0 && ((uint32_t)r9Value & 0x7) != 0;
				if ((uint32_t)i >= uint32_t((int32_t)r9Value >> 3)) {
					ppc_trap(ctx, base, 22);
				}
			} else {
				ppc_trap(ctx, base, 22);
			}

			const uint64_t handleAddr = elementOffset + (uint64_t)begin;
			const uint32_t target = LOAD32((uint32_t)handleAddr + 4);
			uint64_t entity = 0;
			if (target != 0) {
				const uint32_t entityPtr = LOAD32(target);
				if (entityPtr != 0) {
					entity = entityPtr;
				} else {
					// state the callee may pass on
					ctx.r9.u64 = r9Value;
					ctx.r10.u64 = 0;
					ctx.cr0 = compare0;
					ctx.xer.ca = flags.ca;
					EntityHandle_Release(ctx, base, handleAddr);
					r9Value = ctx.r9.u64;
					compare0 = ctx.cr0;
					flags.ca = ctx.xer.ca;
				}
			}

			// state the callee may pass on
			ctx.r9.u64 = r9Value;
			ctx.cr0 = compare0;
			ctx.xer.ca = flags.ca;
			n_sub_82734508(ctx, base, vortexAddr, entity, ctx.r8.u64);
			r9Value = ctx.r9.u64;
			compare0 = ctx.cr0;
			flags.ca = ctx.xer.ca;
			elementOffset += 8;
		}
	}
	// state the callee may pass on
	ctx.r9.u64 = r9Value;
	ctx.xer.ca = flags.ca;
	EntityHandleVector_Clear(ctx, base, handleVectorAddr);

	// entity of the EntityHandle at +352 (0 when gone; a stale handle is released)
	uint64_t linkedEntity = 0;
	const uint32_t linkedTarget = vortex->m_164;
	if (linkedTarget != 0) {
		const uint32_t entityPtr = LOAD32(linkedTarget);
		if (entityPtr != 0) {
			linkedEntity = entityPtr;
		} else {
			ctx.r10.u64 = 0;  // state the callee may pass on
			EntityHandle_Release(ctx, base, vortexAddr + 352);
		}
	}

	// decrement, if positive, one of two counters at +16 / +20 of an object reached from
	// 0x83496920: +16 when the entity of the handle at +352 is the hero entity, +20 otherwise
	const uint32_t root = LOAD32(uint32_t(g_83490000) + 26912);
	const uint32_t counters = LOAD32(LOAD32(LOAD32(LOAD32(root + 12) + 88) + 4) + 56);
	const uint64_t isHeroEntity = Entity_IsHeroEntity(ctx, base, linkedEntity);
	const uint32_t counterOffset = (((uint32_t)isHeroEntity & 0xFF) == 0 ? 20 : 16);
	const uint32_t count = LOAD32(counterOffset + counters);
	if ((int32_t)count > 0) {
		STORE32(counterOffset + counters, count - 1);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return isHeroEntity;
}
PROMOTED_ENTRY(49, sub_82730978, 0x82730978) { ctx.r3.u64 = n_sub_82730978(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_82730AC0(CpuState& ctx, uint8_t* base, uint64_t vortexAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(49, 0x82730AC0)) { ctx.r3.u64 = vortexAddr; __imp__sub_82730AC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82730AC0);
	uint32_t stack = ctx.r1.u64;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	PPCXERRegister flags = ctx.xer;  // xer.ca and cr0 are handed to some callees below
	stack = PushStackFrame(base, stack, 144);

	const uint32_t floorAddr = uint32_t(g_820A0000) - 27468;  // 0x820994B4
	const uint64_t skipCountdown = vortex->m_E3;
	const double floorValue = double(LOAD_F32(floorAddr));

	// m_4C counts down by n_sub_824BB4D8(owner) unless m_E3 is set; when it reaches the floor
	// value it is clamped there and the owner (m_4) is destroyed.
	double ownerStep = ctx.f1.f64;  // f1 stays as the caller left it when the countdown is skipped
	uint64_t r10Value = skipCountdown;
	bool expired = false;
	if (skipCountdown == 0) {
		const uint32_t owner = vortex->m_4;
		ctx.r1.u64 = stack;
		ctx.r10.u64 = r10Value;  // state the callee may pass on
		ownerStep = n_sub_824BB4D8(ctx, base, owner);
		r10Value = ctx.r10.u32;
		ctx.fpscr.disableFlushMode();
		double countdown = double(vortex->m_4C);
		if (countdown > floorValue) {
			countdown = double(float(countdown - ownerStep));
			vortex->m_4C = float(countdown);
			if (!(countdown > floorValue)) {
				vortex->m_4C = float(floorValue);
				expired = true;
			}
		}
	}

	if (expired) {
		const uint32_t owner = vortex->m_4;
		ctx.r1.u64 = stack;
		ctx.f1.f64 = ownerStep;  // state the callee may pass on
		const uint64_t result = Entity_DestroyImpl(ctx, base, owner);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r5.u64 = 0;
	ctx.r10.u64 = r10Value;
	ctx.f1.f64 = ownerStep;
	const uint32_t target = EntityHandle_Get_825575C8(ctx, base, vortexAddr + 352);
	const double targetStep = n_sub_824BB4D8(ctx, base, target);
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = targetStep;  // state the callee may pass on
	n_sub_82731A60(ctx, base, vortexAddr);

	const uint32_t owner = vortex->m_4;
	const double ownerStepNow = n_sub_824BB4D8(ctx, base, owner);
	ctx.fpscr.disableFlushMode();
	// m_68 rises by ownerStepNow * (float at 0x820994CC) up to m_6C
	const double limit6C = double(vortex->m_6C);
	double value68 = double(vortex->m_68);
	if (value68 < limit6C) {
		value68 = double(float(std::fma(ownerStepNow, double(LOAD_F32(floorAddr + 24)), value68)));
		vortex->m_68 = float(value68);
		if (value68 > limit6C) {
			vortex->m_68 = float(limit6C);
		}
	}

	ctx.f1.f64 = ownerStepNow;  // state the callee may pass on
	n_sub_82730D28(ctx, base, vortexAddr);
	n_sub_827311C0(ctx, base, vortexAddr);
	n_sub_827325C8(ctx, base, vortexAddr, ctx.r8.u64);
	n_sub_82733878(ctx, base, vortexAddr);
	flags.ca = ctx.xer.ca;

	// m_54 and m_58 count down by targetStep and are clamped at the floor value
	ctx.fpscr.disableFlushMode();
	double countdown54 = double(vortex->m_54);
	if (countdown54 > floorValue) {
		countdown54 = double(float(countdown54 - targetStep));
		vortex->m_54 = float(countdown54);
		if (!(countdown54 > floorValue)) {
			vortex->m_54 = float(floorValue);
		}
	}
	ctx.fpscr.disableFlushMode();
	double countdown58 = double(vortex->m_58);
	if (countdown58 > floorValue) {
		countdown58 = double(float(countdown58 - targetStep));
		vortex->m_58 = float(countdown58);
		if (!(countdown58 > floorValue)) {
			vortex->m_58 = float(floorValue);
		}
	}

	// four EntityHandles from +368: release the ones whose entity cell is empty, pass the
	// others' entity to n_sub_824B8938 with the vector at +320 in v1
	uint64_t targetWordAddr = vortexAddr + 372;
	uint32_t handlesLeft = 4;
	do {
		const uint32_t handleTarget = LOAD32((uint32_t)targetWordAddr);
		if (handleTarget != 0) {
			const uint32_t entity = LOAD32(handleTarget);
			if (entity == 0) {
				// state the callee may pass on
				ctx.r10.u64 = 0;
				ctx.xer.ca = flags.ca;
				EntityHandle_Release(ctx, base, targetWordAddr - 4);
			} else {
				SET_V8(ctx.v1, VLOAD(((uint32_t)vortexAddr + 320) & ~0xF));
				ctx.xer.ca = flags.ca;  // state the callee may pass on
				n_sub_824B8938(ctx, base, entity);
			}
		}
		flags.ca = handlesLeft != 0;  // carry of the decrement
		handlesLeft = handlesLeft - 1;
		targetWordAddr = targetWordAddr + 8;
	} while (handlesLeft != 0);

	// state the callee may pass on: cr0 and xer.ca as the loop's last decrement left them
	ctx.cr0.compare<int32_t>(int32_t(handlesLeft), 0, flags);
	ctx.xer.ca = flags.ca;
	n_sub_827320F0(ctx, base, vortexAddr);
	const uint64_t result = n_sub_82731308(ctx, base, vortexAddr, 0);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(49, sub_82730AC0, 0x82730AC0) { ctx.r3.u64 = n_sub_82730AC0(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82730C78(CpuState& ctx, uint8_t* base, uint32_t vortexAddr, uint32_t value) {
	if (!UseLiftedCode(49, 0x82730C78)) { ctx.r3.u64 = vortexAddr; ctx.r4.u64 = value; __imp__sub_82730C78(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82730C78);
	uint32_t stack = ctx.r1.u64;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	// Returns 0 when HandleVector_Find, searching the handle vector at +0x1B0 (begin at +4, end at +8)
	// for value, stops at the end, else 1. Iterators are {vector address, element pointer} pairs;
	// inconsistent ones trap.
	const uint32_t vectorAddr = vortexAddr + 432;
	stack = PushStackFrame(base, stack, 144);

	const uint32_t vectorEnd = vortex->m_1B8;
	const uint32_t vectorBegin = vortex->m_1B4;
	STORE32(stack + 172, value);  // the searched value, in the caller's parameter save slot
	if (vectorBegin > vectorEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	// end iterator at stack+80
	const uint32_t endPtr = LOAD32(vectorAddr + 8);
	if (LOAD32(vectorAddr + 4) > endPtr) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	const uint32_t beginPtr = LOAD32(vectorAddr + 4);
	const uint32_t endPtrReread = LOAD32(vectorAddr + 8);
	STORE32(stack + 80, vectorAddr);
	STORE32(stack + 84, endPtr);

	// begin iterator at stack+88
	if (beginPtr > endPtrReread) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	STORE32(stack + 92, beginPtr);
	STORE32(stack + 88, vectorAddr);
	const uint64_t endIterator = LOAD64(stack + 80);
	const uint64_t beginIterator = LOAD64(stack + 88);

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r9.u64 = endPtrReread;
	ctx.r10.u64 = endPtr;
	const uint32_t foundIterator = HandleVector_Find(ctx, base, (uint64_t)stack + 96, beginIterator, endIterator, (uint64_t)stack + 172);

	const uint32_t foundVector = LOAD32(foundIterator);
	if (foundVector == 0 || foundVector != vectorAddr) {
		ppc_trap(ctx, base, 22);
	}
	const uint32_t foundPtr = LOAD32(foundIterator + 4);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return foundPtr == vectorEnd ? 0 : 1;
}
PROMOTED_ENTRY(49, sub_82730C78, 0x82730C78) { ctx.r3.u64 = n_sub_82730C78(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t n_sub_82730D28(CpuState& ctx, uint8_t* base, uint64_t vortexAddr) {
	constexpr int32_t g_820991F0 = int32_t(0x820991F0);
	constexpr int32_t g_8209B4E0 = int32_t(0x8209B4E0);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(49, 0x82730D28)) { ctx.r3.u64 = vortexAddr; __imp__sub_82730D28(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82730D28);
	PPCRegister scratch{};
	PPCVRegister savedV126 = ctx.v126;  // (restored on return)
	PPCVRegister savedV127 = ctx.v127;  // (restored on return)
	uint32_t stack = ctx.r1.u64;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	const uint32_t constTable = uint32_t(g_8209B4E0);
	const uint32_t maskTable = uint32_t(g_820991F0);
	uint32_t result = (uint32_t)vortexAddr;
	PPCVRegister v12Value = ctx.v12;  // callers read v12 after the call
	VSTORE((stack + 0xFFFFFF90u) & ~0xF, V8(savedV126));
	VSTORE((stack + 0xFFFFFFA0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 272);

	if (LOAD8((uint32_t)vortexAddr + 227) != 0) {
		const uint32_t owner = vortex->m_4;
		ctx.r1.u64 = stack;
		const double step = n_sub_824BB4D8(ctx, base, owner);
		const uint64_t targetHandleAddr = vortexAddr + 360;
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 96, float(step));

		// Refresh the vector at +288 from the entity of the handle at +360 when that entity has
		// bit 0x40 set in its byte at +144; otherwise empty the handle.
		ctx.f1.f64 = step;  // state the callee may pass on
		const uint32_t target = EntityHandle_Get_825575C8(ctx, base, targetHandleAddr);
		uint32_t targetFlag = 0;
		if (target != 0) {
			targetFlag = LOAD8(target + 144) & 64;
		}
		if (targetFlag != 0) {
			ctx.r10.u64 = targetFlag;  // state the callee may pass on
			const uint32_t targetEntity = EntityHandle_Get_825575C8(ctx, base, targetHandleAddr);
			// virtual call (vtable slot 16) on the object at +124 of the entity; it writes a
			// vector to stack+128
			const uint32_t component = LOAD32(targetEntity + 124);
			const uint32_t vtable = LOAD32(component);
			const uint32_t method = LOAD32(vtable + 64);
			PPCRegister callTarget{};
			callTarget.u64 = method;
			ctx.r3.u64 = (uint64_t)stack + 128;
			ctx.r4.u64 = component;
			ctx.r9.u64 = method;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			const uint64_t outVecAddr = (uint64_t)stack + 128;
			PPCVRegister outVec{};
			SET_V8(outVec, VLOAD((uint32_t)outVecAddr & ~0xF));
			VSTORE(((uint32_t)vortexAddr + 288) & ~0xF, V8(outVec));
			ctx.r8.u64 = outVecAddr;  // state the callee may pass on
			n_sub_82736998(ctx, base, (uint32_t)vortexAddr + 288);
		} else {
			// assign an empty handle built at stack+88 to the handle at +360
			const uint64_t emptyHandleAddr = (uint64_t)stack + 88;
			STORE32(stack + 92, 0);
			const uint64_t handleVtable = g_820F1664;
			STORE32(stack + 88, (uint32_t)handleVtable);
			ctx.r10.u64 = handleVtable;  // state the callee may pass on
			EntityHandle_Release(ctx, base, emptyHandleAddr);
			EntityHandle_Assign(ctx, base, targetHandleAddr, emptyHandleAddr);
			const uint64_t handleVtableAgain = (int64_t)g_820F0000 + 5732;
			STORE32(stack + 88, (uint32_t)handleVtableAgain);
			// state the callee may pass on
			ctx.r8.u64 = handleVtableAgain;
			ctx.r9.s64 = g_820F0000;
			EntityHandle_Release(ctx, base, emptyHandleAddr);
		}
		// v8-v10 as the calls above left them; n_sub_82736998 receives them further down
		PPCVRegister v8Value = ctx.v8;
		PPCVRegister v9Value = ctx.v9;
		PPCVRegister v10Value = ctx.v10;

		// Move the vector at +304 toward the vector at +288.
		const uint32_t vec120Addr = (uint32_t)vortexAddr + 288;
		const uint32_t vec130Addr = (uint32_t)vortexAddr + 304;
		STORE8(stack + 80, 0);
		PPCVRegister vec130{};
		SET_V8(vec130, VLOAD(vec130Addr & ~0xF));
		PPCVRegister vec120{};
		SET_V8(vec120, VLOAD(vec120Addr & ~0xF));
		ctx.fpscr.enableFlushMode();
		PPCVRegister delta{};
		SET_VF(delta, simde_mm_sub_ps(VF(vec120), VF(vec130)));
		ctx.fpscr.disableFlushModeUnconditional();
		const double floorValue = double(LOAD_F32(constTable - 8236));
		PPCVRegister mask{};
		SET_V8(mask, VLOAD(maskTable & ~0xF));
		bool settle = false;
		// the difference, merged with v12 (floorValue loaded from stack+88) through the permute
		// mask at 0x820991F0, normalised in place at stack+112
		STORE_F32(stack + 88, float(floorValue));
		scratch.u32 = stack + 88;
		SET_V8(v12Value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		double length = double(LOAD_F32(0x82099AE0u));
		PPCVRegister v11Value{};
		SET_V8(v11Value, rex::ppc::simde_mm_perm_epi8_(V8(delta), V8(v12Value), V8(mask)));
		VSTORE((stack + 112) & ~0xF, V8(v11Value));
		ctx.v11 = v11Value;
		ctx.v12 = v12Value;
		length = Vec4_NormalizeInPlace_ReturnLength(ctx, base, stack + 112, length);
		v11Value = ctx.v11;
		v12Value = ctx.v12;
		ctx.fpscr.disableFlushMode();
		const double rate = double(LOAD_F32(constTable - 8108));
		const double maxMove = double(float(step * rate));
		if (length > maxMove) {
			STORE_F32(stack + 88, float(rate));
			scratch.u32 = stack + 88;
			PPCVRegister rateVec{};
			SET_V8(rateVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			PPCVRegister rateSplat{};
			SET_V8(rateSplat, simde_mm_shuffle_epi32(V8(rateVec), 0xFF));
			SET_V8(v12Value, VLOAD((stack + 112) & ~0xF));
			ctx.fpscr.enableFlushModeUnconditional();
			PPCVRegister scaledDirection{};
			SET_VF(scaledDirection, simde_mm_mul_ps(VF(v12Value), VF(rateSplat)));
			// state the callee may pass on
			ctx.f1.f64 = length;
			ctx.v1 = vec130;
			ctx.v2 = scaledDirection;
			ctx.v12 = v12Value;
			ctx.v126 = vec120;
			ctx.v127 = vec130;
			const uint32_t moveVecAddr = n_sub_827315F8(ctx, base, stack + 144, vortexAddr, stack + 80);
			length = ctx.f1.f64;
			v12Value = ctx.v12;
			// vector at +304 += moveVec * step (step was stored at stack+96)
			PPCVRegister moveVec{};
			SET_V8(moveVec, VLOAD(moveVecAddr & ~0xF));
			SET_V8(v11Value, VLOAD(vec130Addr & ~0xF));
			scratch.u32 = stack + 96;
			SET_V8(v10Value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_V8(v9Value, simde_mm_shuffle_epi32(V8(v10Value), 0xFF));
			ctx.fpscr.enableFlushMode();
			SET_VF(v8Value, simde_mm_add_ps(simde_mm_mul_ps(VF(moveVec), VF(v9Value)), VF(v11Value)));
			VSTORE(vec130Addr & ~0xF, V8(v8Value));
		} else {
			// within reach: take the vector at +288
			settle = true;
			VSTORE(vec130Addr & ~0xF, V8(vec120));
		}
		// state the callee may pass on
		ctx.f1.f64 = length;
		ctx.v8 = v8Value;
		ctx.v9 = v9Value;
		ctx.v10 = v10Value;
		ctx.v11 = v11Value;
		ctx.v126 = vec120;
		ctx.v127 = vec130;
		result = n_sub_82736998(ctx, base, vec130Addr);
		v12Value = ctx.v12;
		if ((result & 0xFF) == 0) {
			// the word at offset 8 of the vector at +304, lowered by step * (float at 0x8209B4CC),
			// is merged back through the permute mask at 0x820991F0
			PPCVRegister current{};
			SET_V8(current, VLOAD(vec130Addr & ~0xF));
			ctx.fpscr.disableFlushMode();
			const double drop = double(LOAD_F32(constTable - 20));
			SET_V8(v12Value, V8(current));
			PPCVRegister laneMask{};
			SET_V8(laneMask, VLOAD(maskTable & ~0xF));
			VSTORE((stack + 112) & ~0xF, V8(current));
			const double lane2 = double(LOAD_F32(stack + 120));
			const double lowered = double(float(-std::fma(step, drop, -lane2)));
			STORE_F32(stack + 96, float(lowered));
			scratch.u32 = stack + 96;
			PPCVRegister loweredVec{};
			SET_V8(loweredVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			PPCVRegister updated{};
			SET_V8(updated, rex::ppc::simde_mm_perm_epi8_(V8(v12Value), V8(loweredVec), V8(laneMask)));
			VSTORE(vec130Addr & ~0xF, V8(updated));
		}

		// m_50 counts down by step; reaching the floor value also copies +304 into +288
		ctx.fpscr.disableFlushMode();
		double countdown50 = double(vortex->m_50);
		bool countdown50Ended = false;
		if (countdown50 > floorValue) {
			countdown50 = double(float(countdown50 - step));
			vortex->m_50 = float(countdown50);
			if (!(countdown50 > floorValue)) {
				vortex->m_50 = float(floorValue);
				countdown50Ended = true;
			}
		}
		if (countdown50Ended) {
			PPCVRegister copied{};
			SET_V8(copied, VLOAD(vec130Addr & ~0xF));
			settle = true;
			VSTORE(vec120Addr & ~0xF, V8(copied));
		}

		// m_A8 counts down by step. When the byte at stack+80 (passed to n_sub_827315F8) is set,
		// m_A8 is reloaded from 0x820994CC and m_2C counts up; otherwise m_2C resets once m_A8
		// is at the floor value.
		ctx.fpscr.disableFlushMode();
		double countdownA8 = double(vortex->m_A8);
		if (countdownA8 > floorValue) {
			countdownA8 = double(float(countdownA8 - step));
			vortex->m_A8 = float(countdownA8);
			if (!(countdownA8 > floorValue)) {
				vortex->m_A8 = float(floorValue);
			}
		}
		if (LOAD8(stack + 80) != 0) {
			const uint32_t count = vortex->m_2C;
			ctx.fpscr.disableFlushMode();
			const double reload = double(LOAD_F32(constTable - 8212));
			vortex->m_A8 = float(reload);
			vortex->m_2C = count + 1;
		} else {
			ctx.fpscr.disableFlushMode();
			if (!(double(vortex->m_A8) > floorValue)) {
				vortex->m_2C = 0;
			}
		}
		if (int32_t(vortex->m_2C) > 12) {
			PPCVRegister copied{};
			SET_V8(copied, VLOAD(vec130Addr & ~0xF));
			settle = true;
			VSTORE(vec120Addr & ~0xF, V8(copied));
		}

		if (settle) {
			// m_70 = m_B0, m_78..m_90 = m_B4..m_CC, m_94..m_9C = m_D0..m_D8, m_A4 = m_DC,
			// m_74 = m_B0 + (float at 0x8209B4E0)
			ctx.fpscr.disableFlushMode();
			const double b0 = double(vortex->m_B0);
			vortex->m_E3 = 0;
			const double offset74 = double(LOAD_F32(constTable));
			const double b4 = double(vortex->m_B4);
			const double b8 = double(vortex->m_B8);
			const double bc = double(vortex->m_BC);
			const double c0 = double(vortex->m_C0);
			const double c4 = double(vortex->m_C4);
			const double c8 = double(vortex->m_C8);
			const double cc = double(vortex->m_CC);
			const double d0 = double(vortex->m_D0);
			const double d4 = double(vortex->m_D4);
			const double d8 = double(vortex->m_D8);
			const double dc = double(vortex->m_DC);
			vortex->m_70 = float(b0);
			vortex->m_78 = float(b4);
			vortex->m_7C = float(b8);
			vortex->m_80 = float(bc);
			vortex->m_84 = float(c0);
			vortex->m_88 = float(c4);
			vortex->m_8C = float(c8);
			vortex->m_90 = float(cc);
			vortex->m_94 = float(d0);
			vortex->m_98 = float(d4);
			vortex->m_9C = float(d8);
			vortex->m_A4 = float(dc);
			vortex->m_74 = float(double(float(b0 + offset74)));
			// state the callee may pass on
			ctx.f1.f64 = dc;
			ctx.f2.f64 = d8;
			ctx.f3.f64 = d4;
			ctx.f4.f64 = d0;
			ctx.v12 = v12Value;
			result = n_sub_82731090(ctx, base, vortexAddr);
			v12Value = ctx.v12;
			PPCVRegister settled{};
			SET_V8(settled, VLOAD(vec130Addr & ~0xF));
			vortex->m_E2 = 0;
			vortex->m_E1 = 1;
			VSTORE(((uint32_t)vortexAddr + 240) & ~0xF, V8(settled));
		}
	}
	stack = PopStackFrame(stack, 272);
	// callers read r0 and v12 after the call
	ctx.r0.u64 = uint32_t(0xFFFFFFA0);
	ctx.r1.u64 = stack;
	ctx.v12 = v12Value;
	ctx.v126 = savedV126;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(49, sub_82730D28, 0x82730D28) { ctx.r3.u64 = n_sub_82730D28(ctx, base, ctx.r3.u64); }

// When m_9C is above the float at 0x820994B4: builds a vector at stack+96 from that float and m_9C and passes it
// to n_sub_824B6920 with a random value from Rng_NextScaledFloat. That vector plus the vector at +240, minus the
// vector at +304, is normalized at stack+112; m_A0 becomes its length times the float at 0x8209B4E0, raised to at
// least the float at 0x8209B650, and the vector at +256 becomes the normalized vector times the float at 0x82099334.
// Returns stack+112 in that case, else the vortex address.
uint32_t n_sub_82731090(CpuState& ctx, uint8_t* base, uint32_t vortexAddr) {
	constexpr int32_t g_8209B650 = int32_t(0x8209B650);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(49, 0x82731090)) { ctx.r3.u64 = vortexAddr; __imp__sub_82731090(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82731090);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	// registers left for callers; they keep their incoming values unless the branch below changes them
	uint64_t r8Value = ctx.r8.u64;
	double f1Value = ctx.f1.f64;
	PPCVRegister v8Value = ctx.v8;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	stack = PushStackFrame(base, stack, 160);
	uint32_t result = vortexAddr;
	uint32_t floatBase = uint32_t(g_8209B650);
	ctx.fpscr.disableFlushMode();
	float value9C = vortex->m_9C;
	float threshold = LOAD_F32(floatBase - 8604);
	if (double(value9C) > double(threshold)) {
		PPCVRegister fromVortex{}, fromStack80{}, fromStack84{}, seed{};
		STORE_F32(stack + 88, threshold);
		uint32_t globalBase = uint32_t(g_83490000);
		scratch.u32 = vortexAddr + 156;
		SET_V8(fromVortex, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		STORE_F32(stack + 80, threshold);
		STORE_F32(stack + 84, threshold);
		scratch.u32 = stack + 88;
		SET_V8(seed, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		scratch.u32 = stack + 80;
		SET_V8(fromStack80, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		scratch.u32 = stack + 84;
		SET_V8(fromStack84, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_VF(fromStack84, simde_mm_blend_ps(VF(fromStack84), simde_mm_permute_ps(VF(fromStack80), 57), 4));
		SET_VF(seed, simde_mm_blend_ps(VF(seed), simde_mm_permute_ps(VF(fromVortex), 57), 4));
		f1Value = double(LOAD_F32(0x820990A4u));
		SET_VF(seed, simde_mm_blend_ps(VF(seed), simde_mm_permute_ps(VF(fromStack84), 78), 3));
		uint32_t rngObject = LOAD32(LOAD32(LOAD32(globalBase + 26912) + 12) + 88);
		VSTORE((stack + 96) & ~0xF, V8(seed));
		uint64_t rngState = uint64_t(LOAD32(rngObject + 4)) + 120;
		ctx.r1.u64 = stack;
		ctx.r8.u64 = globalBase;  // state the callee may pass on
		f1Value = Rng_NextScaledFloat(ctx, base, rngState, f1Value);
		ctx.r4.u64 = rngState;  // state the callee may pass on
		n_sub_824B6920(ctx, base, stack + 96, f1Value);

		PPCVRegister seedOut{}, vec240{}, vec304{}, offset{};
		r8Value = uint64_t(stack) + 112;  // the original leaves the buffer address in r8
		uint32_t normalizeAddr = stack + 112;
		SET_V8(seedOut, VLOAD((stack + 96) & ~0xF));
		SET_V8(vec240, VLOAD((vortexAddr + 240u) & ~0xF));
		ctx.fpscr.enableFlushMode();
		SET_VF(v8Value, simde_mm_add_ps(VF(seedOut), VF(vec240)));
		SET_V8(vec304, VLOAD((vortexAddr + 304u) & ~0xF));
		ctx.fpscr.disableFlushModeUnconditional();
		f1Value = double(LOAD_F32(0x82099AE0u));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(offset, simde_mm_sub_ps(VF(v8Value), VF(vec304)));
		VSTORE(normalizeAddr & ~0xF, V8(offset));
		f1Value = Vec4_NormalizeInPlace_ReturnLength(ctx, base, normalizeAddr, f1Value);
		ctx.fpscr.disableFlushMode();
		float scaledLength = float(f1Value * double(LOAD_F32(floatBase - 368)));
		float floorValue = LOAD_F32(floatBase);
		vortex->m_A0 = scaledLength;
		if (scaledLength < floorValue) {
			vortex->m_A0 = floorValue;
		}

		PPCVRegister factorLoad{}, factorSplat{}, direction{}, scaledDirection{};
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 88, LOAD_F32(floatBase - 8988));
		scratch.u32 = stack + 88;
		SET_V8(factorLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(factorSplat, simde_mm_shuffle_epi32(V8(factorLoad), 0xFF));
		SET_V8(direction, VLOAD((stack + 112) & ~0xF));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(scaledDirection, simde_mm_mul_ps(VF(direction), VF(factorSplat)));
		VSTORE((vortexAddr + 256u) & ~0xF, V8(scaledDirection));
		result = normalizeAddr;
	}
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r8.u64 = r8Value;
	ctx.f1.f64 = f1Value;
	ctx.v8 = v8Value;
	return result;
}
PROMOTED_ENTRY(49, sub_82731090, 0x82731090) { ctx.r3.u64 = n_sub_82731090(ctx, base, ctx.r3.u32); }

// While byte +227 is clear and m_9C is above the float at 0x820994B4: with step = n_sub_824BB4D8(m_4), stores
// the vector at the address n_sub_827315F8 returns at +256 and adds step times it to the vector at +304. When
// n_sub_82736998 returns 0 for the result, the vector at +304 gets (its third float - step * the float at
// 0x8209B4CC) merged in through the permute mask at 0x820991F0. Then m_A0 counts down by step; when it reaches
// the limit it is clamped there and n_sub_82731090 is called. Returns the result of the last call made, or the
// vortex address.
uint32_t n_sub_827311C0(CpuState& ctx, uint8_t* base, uint64_t vortexAddr) {
	constexpr int32_t g_820991F0 = int32_t(0x820991F0);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(49, 0x827311C0)) { ctx.r3.u64 = vortexAddr; __imp__sub_827311C0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827311C0);
	PPCRegister scratch{};
	PPCVRegister savedV127 = ctx.v127;
	uint32_t stack = ctx.r1.u64;
	// registers handed to the calls and left for callers
	uint64_t r8Value = ctx.r8.u64;
	PPCVRegister v12Value = ctx.v12;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	uint32_t result = uint32_t(vortexAddr);

	VSTORE((stack + 0xFFFFFFB0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 208);

	if (vortex->m_E3 == 0) {
		uint32_t constBase = uint32_t(g_820A0000);
		double value9C = double(vortex->m_9C);
		double limit = double(LOAD_F32(constBase - 27468));
		if (value9C > limit) {
			ctx.r1.u64 = stack;
			double step = n_sub_824BB4D8(ctx, base, vortex->m_4);
			uint32_t addr304 = uint32_t(vortexAddr) + 304;
			ctx.fpscr.disableFlushMode();
			uint32_t addr256 = uint32_t(vortexAddr) + 256;
			STORE_F32(stack + 80, float(step));

			PPCVRegister vec304{}, vec256{};
			SET_V8(vec304, VLOAD(addr304 & ~0xF));
			SET_V8(vec256, VLOAD(addr256 & ~0xF));
			// state the callee may pass on
			ctx.f1.f64 = step;
			ctx.v1 = vec304;
			ctx.v2 = vec256;
			ctx.v127 = vec304;
			uint32_t directionAddr = n_sub_827315F8(ctx, base, stack + 112, vortexAddr, 0);
			v12Value = ctx.v12;

			PPCVRegister stepLoad{}, stepSplat{}, direction{}, moved{};
			scratch.u32 = stack + 80;
			SET_V8(stepLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_V8(stepSplat, simde_mm_shuffle_epi32(V8(stepLoad), 0xFF));
			SET_V8(direction, VLOAD(directionAddr & ~0xF));
			VSTORE(addr256 & ~0xF, V8(direction));
			ctx.fpscr.enableFlushMode();
			SET_VF(moved, simde_mm_add_ps(simde_mm_mul_ps(VF(stepSplat), VF(direction)), VF(vec304)));
			VSTORE((stack + 96) & ~0xF, V8(moved));
			VSTORE(addr304 & ~0xF, V8(moved));

			result = n_sub_82736998(ctx, base, stack + 96);
			v12Value = ctx.v12;
			r8Value = result & 0xFF;

			if (uint32_t(r8Value) == 0) {
				PPCVRegister current{}, mask{}, merged{};
				SET_V8(current, VLOAD(addr304 & ~0xF));
				ctx.fpscr.disableFlushMode();
				double factor = double(LOAD_F32(uint32_t(int32_t(constBase) - 27468) + 8216));
				r8Value = g_820991F0;  // the original leaves the mask address in r8
				VSTORE((stack + 96) & ~0xF, V8(current));
				SET_V8(mask, VLOAD(uint32_t(r8Value) & ~0xF));
				STORE_F32(stack + 80, float(double(float(-std::fma(step, factor, -double(LOAD_F32(stack + 104)))))));
				scratch.u32 = stack + 80;
				SET_V8(v12Value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
				SET_V8(merged, rex::ppc::simde_mm_perm_epi8_(V8(current), V8(v12Value), V8(mask)));
				VSTORE(addr304 & ~0xF, V8(merged));
			}

			ctx.fpscr.disableFlushMode();
			double valueA0 = double(vortex->m_A0);
			bool reachedLimit = false;
			if (valueA0 > limit) {
				valueA0 = double(float(valueA0 - step));
				vortex->m_A0 = float(valueA0);
				if (!(valueA0 > limit)) {
					vortex->m_A0 = float(limit);
					reachedLimit = true;
				}
			}
			if (reachedLimit) {
				// state the callee may pass on
				ctx.r8.u64 = r8Value;
				ctx.v12 = v12Value;
				result = n_sub_82731090(ctx, base, uint32_t(vortexAddr));
				r8Value = ctx.r8.u64;
				v12Value = ctx.v12;
			}
		}
	}

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r0.u64 = 0xFFFFFFB0u;
	ctx.r8.u64 = r8Value;
	ctx.v12 = v12Value;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(49, sub_827311C0, 0x827311C0) { ctx.r3.u64 = n_sub_827311C0(ctx, base, ctx.r3.u64); }

// scale = the float at 0x820994C0; when byte +227 is set it becomes scale - (scale - p) * the float at 0x820994CC,
// p being the product of the floats at +132 and +128 of the object reached from 0x83496920 (raised to at least the
// float at 0x82099338), unless p was not raised and is not below scale.
// *outVector = the vector at +320 with (its third float + the float at 0x8209B948) merged in through the permute
// mask at 0x820991F0. When bytes +226 and +227 are both set, the +256 vector with the float at 0x820994B4 merged in
// the same way is normalized at stack+96 and added to *outVector times (k - scale * k), k being the float at
// 0x8209BA08; the function then returns stack+96 and leaves the length in f1 (else it returns the vortex address).
// *outA and *outB get m_70 * scale times the floats at 0x8209BF50 and 0x8209B948 (byte +226 set) or at 0x8209DDA4
// and 0x8209B710.
uint32_t n_sub_82731BF0(CpuState& ctx, uint8_t* base, uint32_t vortexAddr, uint32_t outVector, uint32_t outA, uint32_t outB) {
	constexpr uint32_t g_8209B710 = 0x8209B710u;
	constexpr uint32_t g_820A0000 = 0x820A0000u;
	constexpr uint32_t g_83490000 = 0x83490000u;
	if (!UseLiftedCode(49, 0x82731BF0)) { ctx.r3.u64 = vortexAddr; ctx.r4.u64 = outVector; ctx.r5.u64 = outA; ctx.r6.u64 = outB; __imp__sub_82731BF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82731BF0);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u32;
	uint32_t result = vortexAddr;
	// f1 is left for callers: unchanged unless the normalization below sets it to the length
	double f1Value = ctx.f1.f64;
	PPCVRegister savedV127 = ctx.v127;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);

	VSTORE((stack + 0xFFFFFFB0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 192);

	double scale = double(LOAD_F32(g_8209B710 - 8784));
	if (vortex->m_E3 != 0) {
		double minProduct = double(LOAD_F32(g_8209B710 - 9176));
		uint32_t source = LOAD32(LOAD32(LOAD32(LOAD32(g_83490000 + 26912) + 12) + 88) + 4);
		double product = double(float(double(LOAD_F32(source + 132)) * double(LOAD_F32(source + 128))));
		bool pullTowardProduct = true;
		if (product < minProduct) {
			product = minProduct;
		} else {
			ctx.fpscr.disableFlushMode();
			pullTowardProduct = product < scale;
		}
		if (pullTowardProduct) {
			ctx.fpscr.disableFlushMode();
			double gap = double(float(scale - product));
			double factor = double(LOAD_F32(g_8209B710 - 8772));
			scale = double(float(-std::fma(gap, factor, -scale)));
		}
	}

	bool flagE2 = vortex->m_E2 != 0;
	ctx.fpscr.disableFlushMode();
	double offset568 = double(LOAD_F32(g_8209B710 + 568));
	uint32_t maskAddr = g_820A0000 - 28176;
	PPCVRegister vec320{}, mask{}, raisedLoad{}, outVec{};
	SET_V8(vec320, VLOAD((vortexAddr + 320u) & ~0xF));
	VSTORE((stack + 96) & ~0xF, V8(vec320));
	double raisedThird = double(float(double(LOAD_F32(stack + 104)) + offset568));
	VSTORE(outVector & ~0xF, V8(vec320));
	STORE_F32(stack + 80, float(raisedThird));
	SET_V8(mask, VLOAD(maskAddr & ~0xF));
	scratch.u32 = stack + 80;
	SET_V8(raisedLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_V8(outVec, rex::ppc::simde_mm_perm_epi8_(V8(vec320), V8(raisedLoad), V8(mask)));
	VSTORE(outVector & ~0xF, V8(outVec));

	if (flagE2) {
		if (vortex->m_E3 != 0) {
			PPCVRegister vec256{}, fillLoad{}, merged256{}, weightLoad{}, weightSplat{}, normalized{};
			double fill = double(LOAD_F32(g_8209B710 - 8796));
			STORE_F32(stack + 80, float(fill));
			result = stack + 96;
			SET_V8(vec256, VLOAD((vortexAddr + 256u) & ~0xF));
			scratch.u32 = stack + 80;
			SET_V8(fillLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_V8(merged256, rex::ppc::simde_mm_perm_epi8_(V8(vec256), V8(fillLoad), V8(mask)));
			VSTORE((stack + 96) & ~0xF, V8(merged256));
			f1Value = double(LOAD_F32(0x82099AE0u));
			ctx.r1.u64 = stack;
			f1Value = Vec3_NormalizeMasked_ReturnLength(ctx, base, result, f1Value);
			ctx.fpscr.disableFlushMode();
			double k = double(LOAD_F32(g_8209B710 + 760));
			double weight = double(float(-std::fma(scale, k, -k)));
			STORE_F32(stack + 80, float(weight));
			scratch.u32 = stack + 80;
			SET_V8(weightLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_V8(weightSplat, simde_mm_shuffle_epi32(V8(weightLoad), 0xFF));
			SET_V8(normalized, VLOAD((stack + 96) & ~0xF));
			ctx.fpscr.enableFlushModeUnconditional();
			SET_VF(outVec, simde_mm_add_ps(simde_mm_mul_ps(VF(normalized), VF(weightSplat)), VF(outVec)));
			VSTORE(outVector & ~0xF, V8(outVec));
		}
		ctx.fpscr.disableFlushMode();
		double scaled70 = double(float(double(vortex->m_70) * scale));
		STORE_F32(outA, float(double(float(scaled70 * double(LOAD_F32(g_8209B710 + 2112))))));
		STORE_F32(outB, float(double(float(scaled70 * offset568))));
	} else {
		double scaled70 = double(float(double(vortex->m_70) * scale));
		STORE_F32(outA, float(double(float(scaled70 * double(LOAD_F32(g_8209B710 + 9876))))));
		STORE_F32(outB, float(double(float(scaled70 * double(LOAD_F32(g_8209B710))))));
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r0.u64 = 0xFFFFFFB0u;
	ctx.f1.f64 = f1Value;
	return result;
}
PROMOTED_ENTRY(49, sub_82731BF0, 0x82731BF0) { ctx.r3.u64 = n_sub_82731BF0(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32); }

// Calls n_sub_82731F28(vortex, 0, 1). When m_1AC is set: builds a name string at stack+88 (from str_TXT_820D0A3C_B_,
// then RefCountedString_Assign with a temporary string set to str_TXT_820D0A68_B_), hashes its characters with FNV-1, passes
// the hash, m_1AC and the float at 0x820994C0 to n_sub_824B8428 (the vector at +320 in v1), and assigns a handle to
// the result to the handle at +368. Returns the last string release result, or n_sub_82731F28's.
uint64_t n_sub_82731DC8(CpuState& ctx, uint8_t* base, uint64_t vortexAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820D0A3C_B_ = int32_t(0x820D0A3C);
	constexpr int32_t str_TXT_820D0A68_B_ = int32_t(0x820D0A68);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(49, 0x82731DC8)) { ctx.r3.u64 = vortexAddr; __imp__sub_82731DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82731DC8);
	PPCRegister scratch{};
	PPCVRegister savedV127 = ctx.v127;  // (restored on return)
	uint32_t stack = ctx.r1.u64;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	uint64_t result = n_sub_82731F28(ctx, base, vortexAddr, 0, 1);

	if (vortex->m_1AC != 0) {
		const uint64_t tempString = uint64_t(stack) + 80;
		const uint64_t nameString = uint64_t(stack) + 88;
		CCharString_ConstructFromCStr(ctx, base, tempString, g_82000C98, -1);
		CCharString_AssignFromCStr(ctx, base, tempString, str_TXT_820D0A68_B_);
		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820D0A3C_B_, -1);
		RefCountedString_Assign(ctx, base, nameString, tempString);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempString);

		uint32_t nameRep = LOAD32(stack + 88);
		ctx.fpscr.disableFlushMode();
		double scale = double(LOAD_F32(uint32_t(g_820A0000) - 27456));
		STORE_F32(stack + 80, float(scale));
		PPCVRegister scaleLoad{}, scaleSplat{}, mask{}, maskedScale{};
		scratch.u32 = stack + 80;
		SET_V8(scaleLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(scaleSplat, simde_mm_shuffle_epi32(V8(scaleLoad), 0xFF));
		SET_V8(mask, VLOAD(0x820991B0u & ~0xF));
		SET_V8(maskedScale, simde_mm_and_si128(V8(scaleSplat), V8(mask)));

		uint64_t nameChars;
		if (nameRep == 0) {
			nameChars = g_8209003F;
		} else {
			nameChars = LOAD32(nameRep);
		}
		ctx.r8.s64 = g_820A0000;  // state the callee may pass on
		uint64_t nameHash = String_HashFnv1(ctx, base, nameChars, 0xFFFFFFFF811C9DC5ull);

		ctx.fpscr.disableFlushMode();
		PPCVRegister vec320{};
		SET_V8(vec320, VLOAD((uint32_t(vortexAddr) + 320u) & ~0xF));
		// state the callee may pass on
		ctx.v1 = vec320;
		ctx.v2 = maskedScale;
		ctx.v13 = scaleSplat;
		ctx.v127 = maskedScale;
		uint64_t entity = n_sub_824B8428(ctx, base, vortex->m_1AC, nameHash, 0, scale);

		// a temporary handle at stack+80 targets the result and is assigned to the handle at +368
		const uint64_t tempHandle = uint64_t(stack) + 80;
		int64_t handleVtable = int64_t(g_820F0000) + 5732;
		STORE32(stack + 84, 0);
		STORE32(stack + 80, uint32_t(handleVtable));
		// state the callee may pass on
		ctx.r8.u64 = uint64_t(handleVtable);
		ctx.r9.u64 = 0;
		ctx.r10.s64 = g_820F0000;
		EntityHandle_SetTarget(ctx, base, tempHandle, entity);

		EntityHandle_Assign(ctx, base, vortexAddr + 368, tempHandle);

		uint32_t handleVtableWord = uint32_t(g_820F0000) + 5732;
		STORE32(stack + 80, handleVtableWord);
		// state the callee may pass on
		ctx.r6.u64 = handleVtableWord;
		ctx.r7.u64 = uint32_t(g_820F0000);
		EntityHandle_Release(ctx, base, tempHandle);

		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r0.u64 = 0xFFFFFFD0u;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(49, sub_82731DC8, 0x82731DC8) { ctx.r3.u64 = n_sub_82731DC8(ctx, base, ctx.r3.u64); }

// Clears the entity handle at owner + (slotIndex + 46) * 8; does nothing (returns owner) when the handle has no
// data, and only releases it (returning that result) when its data holds no target. Otherwise, when bit 21 of the
// entity's +44 word is set, its element for key 85 is looked up: through the byte at +85 of its +140 object, or
// else by a lower-bound search of the {key, value} pairs from +72 to +76 (without an exact match the word at
// end + 4 is used). A non-null element gets byte +65 set to 1 with flag 0 (then n_sub_8247EB68 is called on it
// with the float at 0x82099568) or to 0 otherwise; with a non-zero flag n_sub_824B8500 is called on the handle's
// current target. Then a temporary handle {0x820F1664, 0} at stack+80 is released, assigned to the slot and
// released again; the last release result is returned.
uint64_t n_sub_82731F28(CpuState& ctx, uint8_t* base, uint64_t ownerAddr, uint64_t slotIndex, uint64_t flag) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(49, 0x82731F28)) { ctx.r3.u64 = ownerAddr; ctx.r4.u64 = slotIndex; ctx.r5.u64 = flag; __imp__sub_82731F28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82731F28);
	uint32_t stack = ctx.r1.u64;
	// condition and carry bits the original hands to its calls
	PPCCRRegister cr0 = ctx.cr0;
	PPCXERRegister xer = ctx.xer;
	stack = PushStackFrame(base, stack, 128);

	uint64_t handleSlot = uint64_t(uint32_t(slotIndex + 46) << 3) + ownerAddr;
	uint64_t result = ownerAddr;
	uint64_t r4Value = slotIndex;

	uint32_t handleData = LOAD32(uint32_t(handleSlot) + 4);
	if (handleData != 0) {
		uint32_t target = LOAD32(handleData);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = slotIndex;
		ctx.r5.u64 = flag;
		ctx.r10.u64 = target;
		if (target == 0) {
			uint64_t released = EntityHandle_Release(ctx, base, handleSlot);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return released;
		}

		uint32_t entity = uint32_t(EntityHandle_Get_825575C8(ctx, base, handleSlot));
		// r6-r10 as the code leaves them; they are handed on to the calls below
		uint64_t reg6 = ctx.r6.u64;
		uint64_t reg7 = ctx.r7.u64;
		uint64_t reg8 = ctx.r8.u64;
		uint64_t reg9 = ctx.r9.u64;
		cr0 = ctx.cr0;
		xer.ca = ctx.xer.ca;

		uint64_t reg10 = (LOAD32(entity + 44) >> 21) & 1;
		uint32_t element = 0;
		if (reg10 != 0) {
			uint32_t keyMap = LOAD32(entity + 140);
			if (keyMap != 0) {
				reg10 = uint32_t(LOAD8(keyMap + 85)) << 3;
				reg9 = reg10 + uint64_t(LOAD32(entity + 72));
				element = LOAD32(uint32_t(reg9) + 4);
			} else {
				// reg10 walks the pairs; the iterator {0, position} is kept at stack+80
				reg10 = LOAD32(entity + 72);
				reg6 = LOAD32(entity + 76);
				STORE32(stack + 80, 0);
				uint32_t byteLength = uint32_t(reg6 - reg10);
				STORE32(stack + 84, uint32_t(reg10));
				xer.ca = int32_t(byteLength) < 0 && (byteLength & 0x7) != 0;
				int32_t count = int32_t(byteLength) >> 3;
				cr0.compare<int32_t>(count, 0, xer);
				if (count > 0) {
					do {
						xer.ca = count < 0 && (count & 0x1) != 0;
						int32_t half = count >> 1;
						reg9 = uint64_t(int64_t(half));
						reg8 = uint32_t(half) << 3;
						reg10 = reg8 + reg10;
						bool keyBelow = int32_t(LOAD32(uint32_t(reg10))) < 85;
						reg7 = keyBelow ? 1 : 0;
						if (keyBelow) {
							count = count - half - 1;
							reg10 = reg10 + 8;
						} else {
							reg10 = reg10 - reg8;
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, uint32_t(reg10));
				}
				uint32_t pairAddr;
				if (uint32_t(reg10) != uint32_t(reg6) && !(int32_t(LOAD32(uint32_t(reg10))) > 85)) {
					STORE64(stack + 80, LOAD64(stack + 80));
					pairAddr = LOAD32(stack + 84);
				} else {
					pairAddr = uint32_t(reg6);
				}
				element = LOAD32(pairAddr + 4);
			}
		}

		if (uint8_t(flag) == 0) {
			if (element != 0) {
				STORE8(element + 65, uint8_t(1));
				ctx.fpscr.disableFlushMode();
				double fadeOutTime = double(LOAD_F32(0x82099568u));
				// state the callee may pass on
				ctx.r6.u64 = reg6;
				ctx.r7.u64 = reg7;
				ctx.r8.u64 = reg8;
				ctx.r9.u64 = reg9;
				ctx.cr0 = cr0;
				ctx.xer.ca = xer.ca;
				n_sub_8247EB68(ctx, base, element, fadeOutTime);  // Lua_ParticleEmitter_KillParticleWithFadeOut
				reg6 = ctx.r6.u64;
				reg7 = ctx.r7.u64;
				reg8 = ctx.r8.u64;
				reg9 = ctx.r9.u64;
				cr0 = ctx.cr0;
				xer.ca = ctx.xer.ca;
			}
		} else {
			if (element != 0) {
				STORE8(element + 65, uint8_t(0));
			}
			// state the callee may pass on
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = reg9;
			ctx.r10.u64 = reg10;
			ctx.cr0 = cr0;
			ctx.xer.ca = xer.ca;
			uint64_t currentTarget = EntityHandle_Get_825575C8(ctx, base, handleSlot);
			n_sub_824B8500(ctx, base, currentTarget);
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			reg9 = ctx.r9.u64;
			cr0 = ctx.cr0;
			xer.ca = ctx.xer.ca;
		}

		const uint64_t tempHandle = uint64_t(stack) + 80;
		STORE32(stack + 84, 0);
		STORE32(stack + 80, uint32_t(g_820F1664));
		// state the callee may pass on
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.r10.u64 = uint64_t(int64_t(g_820F1664));
		ctx.cr0 = cr0;
		ctx.xer.ca = xer.ca;
		EntityHandle_Release(ctx, base, tempHandle);

		EntityHandle_Assign(ctx, base, handleSlot, tempHandle);

		int64_t handleVtable = int64_t(g_820F0000) + 5732;
		STORE32(stack + 80, uint32_t(handleVtable));
		// state the callee may pass on
		ctx.r8.u64 = uint64_t(handleVtable);
		ctx.r9.s64 = g_820F0000;
		result = EntityHandle_Release(ctx, base, tempHandle);
		r4Value = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(49, sub_82731F28, 0x82731F28) { ctx.r3.u64 = n_sub_82731F28(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// Clears the entity handle at owner+400 when its target has bit 0x40 of byte +144 set; when the handle's data holds
// no target the handle is only released (that result is returned), and without data nothing happens (returns
// owner). When bit 21 of the entity's +44 word is set, its element for key 85 (through the byte at +85 of its +140
// object, or else by a lower-bound search of the {key, value} pairs from +72 to +76; without an exact match the word
// at end + 4 is used) gets byte +65 set to 1 and n_sub_8247EB68 is called on it with the float at 0x8209B4E0. Then a
// temporary handle {0x820F1664, 0} at stack+80 is released, assigned to the slot and released again; the last
// release result is returned.
uint32_t n_sub_827323E8(CpuState& ctx, uint8_t* base, uint64_t ownerAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(49, 0x827323E8)) { ctx.r3.u64 = ownerAddr; __imp__sub_827323E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827323E8);
	uint32_t stack = ctx.r1.u64;
	// carry bit the original hands to its calls
	PPCXERRegister xer = ctx.xer;
	stack = PushStackFrame(base, stack, 128);

	uint32_t result = uint32_t(ownerAddr);
	uint32_t handleData = LOAD32(uint32_t(ownerAddr) + 404);
	uint64_t handleAddr = ownerAddr + 400;
	uint32_t targetBit = 0;
	if (handleData != 0) {
		uint32_t target = LOAD32(handleData);
		if (target == 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r10.u64 = target;
			result = uint32_t(EntityHandle_Release(ctx, base, handleAddr));
		} else {
			targetBit = LOAD8(target + 144) & 0x40;
		}
	}

	if (targetBit != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r10.u64 = targetBit;
		uint32_t entity = uint32_t(EntityHandle_Get_825575C8(ctx, base, handleAddr));
		// r6-r9 as the code leaves them; they are handed on to the calls below
		uint64_t reg6 = ctx.r6.u64;
		uint64_t reg7 = ctx.r7.u64;
		uint64_t reg8 = ctx.r8.u64;
		uint64_t reg9 = ctx.r9.u64;
		xer.ca = ctx.xer.ca;

		bool hasElement = false;
		uint32_t element = 0;
		if ((LOAD32(entity + 44) >> 21) & 1) {
			hasElement = true;
			uint32_t keyMap = LOAD32(entity + 140);
			if (keyMap != 0) {
				uint64_t pairOffset = uint32_t(LOAD8(keyMap + 85)) << 3;
				reg9 = pairOffset + uint64_t(LOAD32(entity + 72));
				element = LOAD32(uint32_t(reg9) + 4);
			} else {
				// the iterator {0, position} is kept at stack+80
				uint32_t position = LOAD32(entity + 72);
				reg6 = LOAD32(entity + 76);
				STORE32(stack + 80, 0);
				uint32_t byteLength = uint32_t(reg6) - position;
				STORE32(stack + 84, position);
				xer.ca = int32_t(byteLength) < 0 && (byteLength & 0x7) != 0;
				int32_t count = int32_t(byteLength) >> 3;
				if (count > 0) {
					do {
						xer.ca = count < 0 && (count & 0x1) != 0;
						int32_t half = count >> 1;
						reg9 = uint64_t(int64_t(half));
						reg8 = uint32_t(half) << 3;
						position = uint32_t(reg8) + position;
						bool keyBelow = int32_t(LOAD32(position)) < 85;
						reg7 = keyBelow ? 1 : 0;
						if (keyBelow) {
							count = count - half - 1;
							position = position + 8;
						} else {
							position = position - uint32_t(reg8);
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, position);
				}
				if (position != uint32_t(reg6) && !(int32_t(LOAD32(position)) > 85)) {
					STORE64(stack + 80, LOAD64(stack + 80));
					element = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					element = LOAD32(uint32_t(reg6) + 4);
				}
			}
		}

		if (hasElement) {
			STORE8(element + 65, uint8_t(1));
			ctx.fpscr.disableFlushMode();
			double fadeOutTime = double(LOAD_F32(0x8209B4E0u));
			// state the callee may pass on
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = reg9;
			ctx.xer.ca = xer.ca;
			n_sub_8247EB68(ctx, base, element, fadeOutTime);  // Lua_ParticleEmitter_KillParticleWithFadeOut
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			reg9 = ctx.r9.u64;
			xer.ca = ctx.xer.ca;
		}

		const uint64_t tempHandle = uint64_t(stack) + 80;
		STORE32(stack + 84, 0);
		STORE32(stack + 80, uint32_t(g_820F1664));
		// state the callee may pass on
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.r10.u64 = uint64_t(int64_t(g_820F1664));
		ctx.xer.ca = xer.ca;
		EntityHandle_Release(ctx, base, tempHandle);

		EntityHandle_Assign(ctx, base, handleAddr, tempHandle);

		int64_t handleVtable = int64_t(g_820F0000) + 5732;
		STORE32(stack + 80, uint32_t(handleVtable));
		// state the callee may pass on
		ctx.r8.u64 = uint64_t(handleVtable);
		ctx.r9.s64 = g_820F0000;
		result = uint32_t(EntityHandle_Release(ctx, base, tempHandle));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(49, sub_827323E8, 0x827323E8) { ctx.r3.u64 = n_sub_827323E8(ctx, base, ctx.r3.u64); }

// Counts m_48 down by the step from n_sub_824BB4D8(m_4). When it reaches the floor at 0x820994B4 it is clamped
// there, n_sub_824BADB8 is called with the target of the handle at +352, m_18, 4, m_14, 0x8000, the floor and m_70
// (the vector at +320 in v1), and m_48 is reset to the float at 0x8209BF2C. Returns that call's result, else m_4.
uint32_t n_sub_82733878(CpuState& ctx, uint8_t* base, uint64_t vortexAddr) {
	constexpr int32_t g_820994B4 = int32_t(0x820994B4);
	if (!UseLiftedCode(49, 0x82733878)) { ctx.r3.u64 = vortexAddr; __imp__sub_82733878(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82733878);
	PPCVRegister savedV127 = ctx.v127;  // (restored on return)
	uint32_t stack = ctx.r1.u64;
	CECVortex* vortex = GameObject<CECVortex>(base, vortexAddr);

	VSTORE((stack + 0xFFFFFFB0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 176);

	uint32_t result = vortex->m_4;
	ctx.r1.u64 = stack;
	double step = n_sub_824BB4D8(ctx, base, result);
	// f1 is left for callers: the step, or what n_sub_824BADB8 leaves in f1
	double f1Value = step;
	ctx.fpscr.disableFlushMode();

	const uint32_t floorAddr = uint32_t(g_820994B4);
	double timer = double(vortex->m_48);
	double floorValue = double(LOAD_F32(floorAddr));
	bool reachedFloor = false;
	if (timer > floorValue) {
		timer = double(float(timer - step));
		vortex->m_48 = float(timer);
		if (!(timer > floorValue)) {
			vortex->m_48 = float(floorValue);
			reachedFloor = true;
		}
	}

	if (reachedFloor) {
		uint32_t value14 = vortex->m_14;
		uint32_t value18 = vortex->m_18;
		uint64_t handleAddr = vortexAddr + 352;
		ctx.fpscr.disableFlushMode();
		double value70 = double(vortex->m_70);
		PPCVRegister vec320{};
		SET_V8(vec320, VLOAD((uint32_t(vortexAddr) + 320u) & ~0xF));
		// state the callee may pass on
		ctx.r10.u64 = 0;
		ctx.f1.f64 = step;
		uint64_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		ctx.fpscr.disableFlushMode();
		// state the callee may pass on
		ctx.v1 = vec320;
		ctx.v127 = vec320;
		result = uint32_t(n_sub_824BADB8(ctx, base, target, value18, 4u, value14, 32768u, floorValue, value70));
		f1Value = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		vortex->m_48 = LOAD_F32(floorAddr + 10872);
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r0.u64 = 0xFFFFFFB0u;
	ctx.f1.f64 = f1Value;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(49, sub_82733878, 0x82733878) { ctx.r3.u64 = n_sub_82733878(ctx, base, ctx.r3.u64); }
