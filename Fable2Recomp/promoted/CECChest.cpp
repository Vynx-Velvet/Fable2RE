// CECChest (vtable 0x820037D8): methods of the class as readable C++.
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

uint64_t n_sub_82295920(CpuState& ctx, uint8_t* base, uint64_t chestAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(11, 0x82295920)) { ctx.r3.u64 = chestAddr; __imp__sub_82295920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82295920);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECChest* chest = GameObject<CECChest>(base, chestAddr);
	uint64_t result = chestAddr;

	stack = PushStackFrame(base, stack, 128);

	if (LOAD8((uint32_t)chestAddr + 15) != 0) {
		uint32_t target = chest->m_10;
		if (target == 0) {
			result = 0;
		} else {
			double curveInput = double(LOAD_F32(target + 40));
			ctx.r1.u64 = stack;
			Curve_EvaluateLinear(ctx, base, target, curveInput);
			double curveResult = ctx.f1.f64;
			ctx.fpscr.disableFlushMode();
			double threshold = double(float(curveResult - double(LOAD_F32(0x82100728u))));
			if (LOAD8((uint32_t)chestAddr + 12) != 0) {
				uint32_t curTarget = chest->m_10;
				uint32_t fn = LOAD32(LOAD32(curTarget) + 28);
				callTarget.u64 = (uint64_t)fn;
				ctx.r3.u64 = curTarget;
				ctx.r10.u64 = fn;
				ctx.f1.f64 = threshold;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = n_sub_8253DC80(ctx, base, chestAddr);
			} else {
				uint32_t global = LOAD32(uint32_t(g_83490000) + 26912u);
				uint32_t a = LOAD32(LOAD32(global + 12) + 88);
				uint32_t b = LOAD32(a + 4);
				uint32_t c = LOAD32(b);
				ctx.r8.u64 = b;
				ctx.r9.u64 = a;
				uint32_t handle = EntityHandle_Get(ctx, base, c);
				double value = n_sub_82207928(ctx, base, handle);
				uint32_t curTarget = chest->m_10;
				ctx.fpscr.disableFlushMode();
				double divisor = LOAD_F64(uint32_t(g_83320000) - 27376u);
				double ratio = value / divisor;
				double baseF = double(LOAD_F32(curTarget + 32));
				double ratioF = double(float(ratio));
				double candidate = double(float(baseF + ratioF));
				if (!(candidate < threshold)) {
					chest->m_C = 1;
					uint32_t fn = LOAD32(LOAD32(curTarget) + 28);
					callTarget.u64 = (uint64_t)fn;
					ctx.r3.u64 = curTarget;
					ctx.r7.s64 = g_83320000;
					ctx.r10.u64 = fn;
					ctx.f1.f64 = threshold;
					ctx.f12.f64 = ratioF;
					ctx.f13.f64 = baseF;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					result = n_sub_8253DC80(ctx, base, chestAddr);
				} else {
					uint32_t fn = LOAD32(LOAD32(curTarget) + 20);
					callTarget.u64 = (uint64_t)fn;
					ctx.r3.u64 = curTarget;
					ctx.r7.s64 = g_83320000;
					ctx.r10.u64 = fn;
					ctx.f1.f64 = candidate;
					ctx.f12.f64 = ratioF;
					ctx.f13.f64 = baseF;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					result = ctx.r3.u64;
				}
			}
		}
	}

	uint32_t owner = chest->m_4;

	// std::map lookup on the owner's container (key is the map's int key, value read at node + 4).
	auto mapLookup = [&](uint32_t mapOwner, int32_t key) -> uint32_t {
		uint32_t hint = LOAD32(mapOwner + 140);
		if (hint != 0) {
			uint32_t idx = uint32_t(LOAD8(hint + uint32_t(key))) * 8u;
			return LOAD32(LOAD32(mapOwner + 72) + idx + 4);
		}
		uint32_t begin = LOAD32(mapOwner + 72);
		uint32_t end = LOAD32(mapOwner + 76);
		STORE32(stack + 80, 0u);
		int32_t count = int32_t(end - begin) >> 3;
		STORE32(stack + 84, begin);
		uint32_t found = begin;
		if (count > 0) {
			int32_t remaining = count;
			do {
				int32_t step = remaining >> 1;
				uint32_t midOffset = uint32_t(step) * 8u;
				found = found + midOffset;
				if (int32_t(LOAD32(found)) < key) {
					remaining = remaining - step - 1;
					found = found + 8u;
				} else {
					found = found - midOffset;
					remaining = step;
				}
			} while (remaining > 0);
			STORE32(stack + 84, found);
		}
		if (found != end && int32_t(LOAD32(found)) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(found + 4);
		}
		return LOAD32(end + 4);
	};

	bool haveEntity = false;
	uint32_t entityNode = 0;
	if (((LOAD32(owner + 36) >> 23) & 1) != 0) {
		entityNode = mapLookup(owner, 23);
		haveEntity = true;
	}

	if (haveEntity) {
		bool haveToggler = false;
		uint32_t toggler = 0;
		if (((LOAD32(owner + 36) >> 13) & 1) != 0) {
			toggler = mapLookup(owner, 13);
			haveToggler = true;
		}
		bool setOn = haveToggler && (LOAD32(toggler + 20) != 0);
		if (setOn) {
			if (LOAD8(entityNode + 35) != 1) STORE8(entityNode + 35, 1);
		} else {
			if (LOAD8(entityNode + 35) != 0) STORE8(entityNode + 35, 0);
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = 0;
	return result;
}
PROMOTED_ENTRY(11, sub_82295920, 0x82295920) { ctx.r3.u64 = n_sub_82295920(ctx, base, ctx.r3.u64); }

uint64_t CECChest_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820BDC28_B_ = int32_t(0x820BDC28);
	if (!UseLiftedCode(33, 0x8253D100)) { ctx.r3.u64 = classNameString; __imp__sub_8253D100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253D100);
	uint32_t stack = ctx.r1.u64;
	uint64_t classString{};
	int32_t length{};
	stack = PushStackFrame(base, stack, 96);
	length = -1;
	classString = str_TXT_820BDC28_B_;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classString, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(33, sub_8253D100, 0x8253D100) { ctx.r3.u64 = CECChest_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8253D218(CpuState& ctx, uint8_t* base, uint64_t chestAddr) {
	if (!UseLiftedCode(33, 0x8253D218)) { ctx.r3.u64 = chestAddr; __imp__sub_8253D218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253D218);
	CECChest* chest = GameObject<CECChest>(base, chestAddr);

	uint32_t manager = LOAD32(0x83496920);
	uint32_t managerObject = LOAD32(LOAD32(manager + 12) + 140);
	uint32_t flagA = LOAD8(managerObject + 52);

	// Only when both flags on the manager object are set does the chest short-circuit.
	bool isInactive = flagA != 0 && LOAD8(managerObject + 54) != 0;
	if (isInactive) {
		ctx.r4.u64 = chestAddr;
		return chestAddr;
	}

	uint32_t chestOwner = chest->m_4;
	ctx.r9.u64 = flagA;
	return n_sub_82392C88(ctx, base, chestOwner, chestAddr);
}
PROMOTED_ENTRY(33, sub_8253D218, 0x8253D218) { ctx.r3.u64 = n_sub_8253D218(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8253D268(CpuState& ctx, uint8_t* base, uint64_t chestAddr, uint64_t stream, uint64_t flags) {
	constexpr int32_t str_TXT_820ADDD8_B_ = int32_t(0x820ADDD8);
	constexpr int32_t str_TXT_820BCDBC_B_ = int32_t(0x820BCDBC);
	constexpr int32_t str_TXT_820BDC34_B_ = int32_t(0x820BDC34);
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	if (!UseLiftedCode(33, 0x8253D268)) { ctx.r3.u64 = chestAddr; ctx.r4.u64 = stream; ctx.r6.u64 = flags; __imp__sub_8253D268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253D268);
	uint32_t stack = ctx.r1.u64;
	CECChest* chest = GameObject<CECChest>(base, chestAddr);

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// one CCharString temporary is reused (at the same stack slot) for every serialized field
	uint32_t nameString = stack + 80;

	auto serializeField = [&](uint64_t fieldName, uint32_t fieldOffset) -> uint64_t {
		CCharString_ConstructFromCStr(ctx, base, nameString, fieldName, -1);
		IStream_SerializeString(ctx, base, nameString, stream, chestAddr + fieldOffset);
		return CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);
	};

	ctx.r6.u64 = flags;
	serializeField((uint64_t)str_TXT_820BCDBC_B_, 12);
	serializeField((uint64_t)str_TXT_820ADDD8_B_, 13);
	serializeField((uint64_t)str_TXT_820BDC34_B_, 15);

	int32_t stringBase = str_TXT_820C0000_B_;
	uint64_t messageName = (int64_t)stringBase - 12444;
	ctx.r8.s64 = stringBase;
	uint64_t result = serializeField(messageName, 14);

	uint32_t isOpen = chest->m_C;
	if (isOpen != 0 && (flags & 0xFF) == 0) {
		ctx.r7.u64 = isOpen;
		result = n_sub_8253DC80(ctx, base, chestAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_8253D268, 0x8253D268) { ctx.r3.u64 = n_sub_8253D268(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

uint32_t n_sub_8253D758(CpuState& ctx, uint8_t* base, uint32_t chestAddr) {
	if (!UseLiftedCode(33, 0x8253D758)) { ctx.r3.u64 = chestAddr; __imp__sub_8253D758(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8253D758);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECChest* chest = GameObject<CECChest>(base, chestAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t handleList = LOAD32(uint32_t(chest->m_4) + 124);
	uint32_t handleVtable = LOAD32(handleList);
	uint32_t firstFn = LOAD32(handleVtable + 92);

	callTarget.u64 = (uint64_t)firstFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = handleList;
	ctx.r9.u64 = firstFn;
	ctx.r10.u64 = handleVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t result = ctx.r3.u32;
	if (result != 0) {
		uint32_t foundHandleAddr = stack + 80;
		STORE32(foundHandleAddr, 0u);
		result = SharedHandleList_FindFirstMatching(ctx, base, result, foundHandleAddr);
		if ((result & 0xFF) != 0) {
			uint32_t foundHandle = LOAD32(foundHandleAddr);
			uint32_t setFn = LOAD32(LOAD32(foundHandle) + 84);
			callTarget.u64 = (uint64_t)setFn;
			ctx.r3.u64 = foundHandle;
			ctx.r4.u64 = 1;
			ctx.r10.u64 = setFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u32;
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_8253D758, 0x8253D758) { ctx.r3.u64 = n_sub_8253D758(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8253D7C8(CpuState& ctx, uint8_t* base, uint32_t chestAddr, uint64_t arg2, uint32_t arg3) {
	if (!UseLiftedCode(33, 0x8253D7C8)) { ctx.r3.u64 = chestAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_8253D7C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8253D7C8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECChest* chest = GameObject<CECChest>(base, chestAddr);
	stack = PushStackFrame(base, stack, 192);

	// Registers left over from the caller, handed on to the component lookups.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;

	// Lower-bound lookup of component type 19 in the chest's rooted object.
	uint32_t rootObject = chest->m_4;
	uint32_t component = 0;
	bool hasComponent = false;
	if ((LOAD32(rootObject + 36) >> 19) & 1) {
		uint32_t indexArray = LOAD32(rootObject + 0x8C);
		if (indexArray != 0) {
			component = LOAD32(LOAD32(rootObject + 0x48) + (uint32_t(LOAD8(indexArray + 19)) << 3) + 4);
		} else {
			uint32_t begin = LOAD32(rootObject + 0x48);
			uint32_t end = LOAD32(rootObject + 0x4C);
			reg6 = end;
			STORE32(stack + 96, 0);
			STORE32(stack + 100, begin);
			uint32_t countBytes = end - begin;
			flags.ca = ((int32_t)countBytes < 0) & ((countBytes & 0x7) != 0);
			int32_t remaining = (int32_t)countBytes >> 3;
			if (remaining > 0) {
				do {
					flags.ca = ((int32_t)remaining < 0) & (((uint32_t)remaining & 0x1) != 0);
					int32_t half = remaining >> 1;
					reg8 = uint32_t(half) << 3;
					begin += (uint32_t)reg8;
					reg7 = ((int32_t)LOAD32(begin) < 19) ? 1 : 0;
					if ((uint32_t)reg7 != 0) {
						remaining = remaining - half - 1;
						begin += 8;
					} else {
						begin -= (uint32_t)reg8;
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 100, begin);
			}
			if (begin != end) {
				if ((int32_t)LOAD32(begin) > 19) {
					component = LOAD32(end + 4);
				} else {
					STORE64(stack + 96, LOAD64(stack + 96));
					component = LOAD32(LOAD32(stack + 100) + 4);
				}
			} else {
				component = LOAD32(end + 4);
			}
		}
		hasComponent = true;
	}

	if (hasComponent) {
		ctx.r1.u64 = stack;
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.xer.ca = flags.ca;
		chestAddr = n_sub_822A1A50(ctx, base, stack + 80, component, arg2);
		arg2 = ctx.r4.u64;
		uint64_t local40 = ctx.r6.u64;
		uint64_t local44 = ctx.r7.u64;
		uint64_t local47 = ctx.r8.u64;
		uint32_t firstObject = LOAD32(stack + 80);
		if (firstObject != 0) {
			// Lower-bound lookup of component type 6 in the same object.
			uint32_t mapObject = chest->m_4;
			uint32_t otherComponent = 0;
			bool foundOther = false;
			uint64_t local60 = LOAD32(mapObject + 36);
			uint64_t local53 = ((uint32_t)local60 >> 6) & 1;
			if ((uint32_t)local53 != 0) {
				local60 = LOAD32(mapObject + 0x8C);
				if ((uint32_t)local60 != 0) {
					local60 = LOAD8((uint32_t)local60 + 6);
					mapObject = LOAD32(mapObject + 0x48);
					local60 = (uint32_t)local60 << 3;
					local53 = (uint32_t)local60 + mapObject;
					otherComponent = LOAD32((uint32_t)local53 + 4);
					foundOther = true;
				} else {
					local60 = LOAD32(mapObject + 0x48);
					local40 = LOAD32(mapObject + 0x4C);
					STORE32(stack + 96, 0);
					STORE32(stack + 100, (uint32_t)local60);
					uint32_t countBytes = (uint32_t)local40 - (uint32_t)local60;
					flags.ca = ((int32_t)countBytes < 0) & ((countBytes & 0x7) != 0);
					int32_t remaining = (int32_t)countBytes >> 3;
					if (remaining > 0) {
						do {
							flags.ca = ((int32_t)remaining < 0) & (((uint32_t)remaining & 0x1) != 0);
							local53 = remaining >> 1;
							local47 = (uint32_t)local53 << 3;
							local60 = local47 + local60;
							local44 = ((int32_t)LOAD32((uint32_t)local60) < 6) ? 1 : 0;
							if ((uint32_t)local44 != 0) {
								remaining = remaining - (int32_t)local53;
								local60 = local60 + 8;
								remaining = remaining - 1;
							} else {
								local60 = local60 - local47;
								remaining = (int32_t)local53;
							}
						} while (remaining > 0);
						STORE32(stack + 100, (uint32_t)local60);
					}
					if ((uint32_t)local60 != (uint32_t)local40) {
						if ((int32_t)LOAD32((uint32_t)local60) > 6) {
							otherComponent = LOAD32((uint32_t)local40 + 4);
						} else {
							STORE64(stack + 96, LOAD64(stack + 96));
							otherComponent = LOAD32(LOAD32(stack + 100) + 4);
						}
					} else {
						otherComponent = LOAD32((uint32_t)local40 + 4);
					}
					foundOther = true;
				}
			}

			if (foundOther) {
				STORE32(stack + 96, firstObject);
				STORE32(stack + 80, 0);
				uint32_t componentData = LOAD32(otherComponent + 0x94);
				ctx.r6.u64 = local40;
				ctx.r7.u64 = local44;
				ctx.r8.u64 = local47;
				ctx.r9.u64 = local53;
				ctx.r10.u64 = local60;
				ctx.xer.ca = flags.ca;
				chestAddr = n_sub_822001F8(ctx, base, stack + 96, stack + 80);
				arg2 = ctx.r4.u64;
				flags.ca = ctx.xer.ca;
				uint64_t countArg = ctx.r8.u64;
				uint32_t secondObject = LOAD32(stack + 80);
				if (chestAddr & 0xFF) {
					double amount;
					if ((int32_t)arg3 == 0) {
						ctx.fpscr.disableFlushMode();
						amount = (double)LOAD_F32(0x820994B4u);
					} else {
						ctx.fpscr.disableFlushMode();
						double divisor = (double)LOAD_F32(secondObject + 52);
						countArg = (uint64_t)(int64_t)(int32_t)(LOAD32(secondObject + 56) - 1);
						STORE64(stack + 96, countArg);
						double numerator = (double)(float)(double)(int64_t)countArg;
						double quotient = (double)(float)(numerator / divisor);
						amount = (double)(float)(quotient - (double)LOAD_F32(0x82100728u));
					}
					uint32_t elementBytes = LOAD32(componentData + 0x30) - LOAD32(componentData + 0x2C);
					flags.ca = ((int32_t)elementBytes < 0) & ((elementBytes & 0x7) != 0);
					ctx.xer.ca = flags.ca;
					n_sub_821719D0(ctx, base, stack + 96,
					               (int32_t)elementBytes >> 3,
					               countArg);
					flags.ca = ctx.xer.ca;
					uint32_t element = LOAD32(stack + 100);
					int32_t elementCount = (int32_t)(LOAD32(stack + 104) - element) / 48;
					PPCCRRegister compare0{};
					compare0.compare<int32_t>(elementCount, 0, flags);
					if (elementCount == 0)
						element = stack + 96;
					ctx.fpscr.disableFlushMode();
					ctx.cr0.lt = compare0.lt;
					ctx.cr0.gt = compare0.gt;
					ctx.cr0.eq = compare0.eq;
					ctx.cr0.so = compare0.so;
					n_sub_822351F0(ctx, base, secondObject, element, componentData, 3, 0, 0, amount);
					flags.ca = ctx.xer.ca;
					n_sub_8254F4E8(ctx, base, otherComponent, stack + 96);
					flags.ca = ctx.xer.ca;
					n_sub_82B6F5A0(ctx, base, component + 24, stack + 96, ctx.r8.u64);
					flags.ca = ctx.xer.ca;
					chestAddr = Vector_FreeAndReset(ctx, base, stack + 96);
					arg2 = ctx.r4.u64;
					flags.ca = ctx.xer.ca;
				}
				if (secondObject != 0) {
					uint32_t* refCount = reinterpret_cast<uint32_t*>(RAW(secondObject + 4));
					uint32_t newCount;
					do {
						ctx.reserved.u32 = *refCount;
						newCount = __builtin_bswap32(ctx.reserved.u32) - 1;
					} while (!__sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(secondObject + 4)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount)));
					if ((int32_t)newCount == 0) {
						uint32_t destructor = LOAD32(LOAD32(secondObject) + 4);
						ctx.r3.u64 = secondObject;
						REX_CALL_INDIRECT_FUNC(destructor);
						chestAddr = ctx.r3.u32;
						arg2 = ctx.r4.u64;
						flags.ca = ctx.xer.ca;
					}
				}
			}

			// Lower-bound lookup of component type 3, then mark it as used.
			uint32_t lastObject = chest->m_4;
			uint32_t component3 = 0;
			bool hasThird = false;
			if ((LOAD32(lastObject + 36) >> 3) & 1) {
				uint32_t indexArray = LOAD32(lastObject + 0x8C);
				if (indexArray != 0) {
					component3 = LOAD32((uint32_t(LOAD8(indexArray + 3)) << 3) + LOAD32(lastObject + 0x48) + 4);
				} else {
					uint32_t begin = LOAD32(lastObject + 0x48);
					uint32_t end = LOAD32(lastObject + 0x4C);
					STORE32(stack + 96, 0);
					STORE32(stack + 100, begin);
					uint32_t countBytes = end - begin;
					flags.ca = ((int32_t)countBytes < 0) & ((countBytes & 0x7) != 0);
					int32_t remaining = (int32_t)countBytes >> 3;
					if (remaining > 0) {
						do {
							flags.ca = ((int32_t)remaining < 0) & (((uint32_t)remaining & 0x1) != 0);
							int32_t half = remaining >> 1;
							uint32_t shifted = (uint32_t)half << 3;
							begin += shifted;
							bool lower = (int32_t)LOAD32(begin) < 3;
							if (lower) {
								remaining = remaining - half - 1;
								begin += 8;
							} else {
								begin -= shifted;
								remaining = half;
							}
						} while (remaining > 0);
						STORE32(stack + 100, begin);
					}
					if (begin != end) {
						if ((int32_t)LOAD32(begin) > 3) {
							component3 = LOAD32(end + 4);
						} else {
							STORE64(stack + 96, LOAD64(stack + 96));
							component3 = LOAD32(LOAD32(stack + 100) + 4);
						}
					} else {
						component3 = LOAD32(end + 4);
					}
				}
				hasThird = true;
			}
			if (hasThird)
				STORE8(component3 + 132, 1);
		}
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	ctx.xer.ca = flags.ca;
	return chestAddr;
}
PROMOTED_ENTRY(33, sub_8253D7C8, 0x8253D7C8) { ctx.r3.u64 = n_sub_8253D7C8(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint64_t n_sub_8253DC80(CpuState& ctx, uint8_t* base, uint64_t chestAddr) {
	constexpr int32_t str_TXT_820BCDBC_B_ = int32_t(0x820BCDBC);
	if (!UseLiftedCode(33, 0x8253DC80)) { ctx.r3.u64 = chestAddr; __imp__sub_8253DC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253DC80);
	uint32_t stack = ctx.r1.u64;
	uint64_t openStatus{};
	CECChest* chest = GameObject<CECChest>(base, chestAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_8253DD60(ctx, base, chestAddr);
	n_sub_8253D758(ctx, base, chestAddr);
	uint64_t actionName = (uint64_t)stack + 80;
	CCharString_ConstructFromCStr(ctx, base, actionName, str_TXT_820BCDBC_B_, -1);
	n_sub_8253D7C8(ctx, base, chestAddr, actionName, 1);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, actionName);
	chest->m_C = uint8_t(1);
	openStatus = n_sub_8253DF30(ctx, base, chestAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return openStatus;
}
PROMOTED_ENTRY(33, sub_8253DC80, 0x8253DC80) { ctx.r3.u64 = n_sub_8253DC80(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8253DD60(CpuState& ctx, uint8_t* base, uint64_t chestAddr) {
	if (!UseLiftedCode(33, 0x8253DD60)) { ctx.r3.u64 = chestAddr; __imp__sub_8253DD60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253DD60);
	uint32_t stack = ctx.r1.u64;
	CECChest* chest = GameObject<CECChest>(base, chestAddr);
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};

	uint64_t lookupResult = 0;
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR7 = ctx.r7.u64;
	uint64_t passR8 = ctx.r8.u64;
	uint64_t passR9 = 0;
	uint64_t handle = 0;
	bool hasResult = false;

	stack = PushStackFrame(base, stack, 112);

	handle = chest->m_18;
	if ((uint32_t)handle != 0) {
		uint32_t container = chest->m_4;
		uint32_t isIndexed = (LOAD32(container + 36) >> 19) & 1;
		passR9 = isIndexed;
		if (isIndexed != 0) {
			uint32_t index = LOAD32(container + 140);
			if (index != 0) {
				uint32_t entry = LOAD32(container + 72) + (__builtin_rotateleft32(LOAD8(index + 19), 3) & 0xFFFFFFFFu);
				passR9 = entry;
				lookupResult = LOAD32(entry + 4);
				hasResult = true;
			} else {
				// lower_bound over the 8-byte entries, key 19
				uint32_t begin = LOAD32(container + 72);
				uint32_t end = LOAD32(container + 76);
				passR6 = end;
				uint32_t count = end - begin;
				STORE32(stack + 80, 0);
				STORE32(stack + 84, begin);
				count = (uint32_t)((int32_t)count >> 3);
				if ((int32_t)count > 0) {
					do {
						int32_t half = (int32_t)count >> 1;
						uint32_t entrySize = (uint32_t)half << 3;
						passR9 = (uint32_t)half;
						passR8 = entrySize;
						begin += entrySize;
						bool beforeKey = (int32_t)LOAD32(begin) < 19;
						passR7 = beforeKey ? 1 : 0;
						if (beforeKey) {
							count = count - (uint32_t)half;
							begin += 8;
							count = (uint32_t)((int32_t)count - 1);
						} else {
							begin -= entrySize;
							count = (uint32_t)half;
						}
					} while ((int32_t)count > 0);
					STORE32(stack + 84, begin);
				}
				if (begin != end && (int32_t)LOAD32(begin) <= 19) {
					STORE64(stack + 80, LOAD64(stack + 80));
					lookupResult = LOAD32(begin + 4);
				} else {
					lookupResult = LOAD32(end + 4);
				}
				hasResult = true;
			}
		}
		if (hasResult) {
			ctx.r1.u64 = stack;
			ctx.r5.u64 = 0;
			ctx.r6.u64 = passR6;
			ctx.r7.u64 = passR7;
			ctx.r8.u64 = passR8;
			ctx.r9.u64 = passR9;
			ctx.xer.ca = flags.ca;
			n_sub_822ADE58(ctx, base, lookupResult, handle);
			passR6 = ctx.r6.u64;
			passR7 = ctx.r7.u64;
			passR8 = ctx.r8.u64;
			passR9 = ctx.r9.u64;
		}
		uint32_t object = chest->m_18;
		if (object != 0) {
			passR9 = object + 4;
			uint32_t refCount = LOAD32(object + 4) - 1;
			STORE32(object + 4, refCount);
			if (refCount == 0) {
				uint32_t destructor = LOAD32(LOAD32(object) + 4);
				callTarget.u64 = destructor;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = object;
				ctx.r4.u64 = handle;
				ctx.r6.u64 = passR6;
				ctx.r7.u64 = passR7;
				ctx.r8.u64 = passR8;
				ctx.r9.u64 = passR9;
				ctx.r10.u64 = destructor;
				ctx.xer.ca = flags.ca;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				handle = ctx.r4.u64;
				passR6 = ctx.r6.u64;
				passR7 = ctx.r7.u64;
				passR8 = ctx.r8.u64;
				passR9 = ctx.r9.u64;
				flags.ca = ctx.xer.ca;
			}
			chest->m_18 = 0;
		}
		chest->m_18 = 0;
		uint32_t listener = chest->m_10;
		uint32_t releaseFn = LOAD32(LOAD32(listener) + 8);
		callTarget.u64 = releaseFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = listener;
		ctx.r4.u64 = handle;
		ctx.r6.u64 = passR6;
		ctx.r7.u64 = passR7;
		ctx.r8.u64 = passR8;
		ctx.r9.u64 = passR9;
		ctx.r10.u64 = releaseFn;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		handle = ctx.r4.u64;
		flags.ca = ctx.xer.ca;
	}

	uint64_t handleAddr = chestAddr + 16;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = handle;
	uint64_t released = SharedHandle_Release(ctx, base, handleAddr);
	chest->m_10 = 0;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return released;
}
PROMOTED_ENTRY(33, sub_8253DD60, 0x8253DD60) { ctx.r3.u64 = n_sub_8253DD60(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8253DF30(CpuState& ctx, uint8_t* base, uint64_t chestAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(33, 0x8253DF30)) { ctx.r3.u64 = chestAddr; __imp__sub_8253DF30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253DF30);
	uint32_t stack = ctx.r1.u64;
	CECChest* chest = GameObject<CECChest>(base, chestAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t result = chestAddr;
	if (LOAD8(chestAddr + 15) == 0) {
		uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t managerData = LOAD32(manager + 12);
		uint32_t handleSlot = LOAD32(LOAD32(managerData + 88) + 4);
		uint32_t handle = LOAD32(handleSlot);

		ctx.r1.u64 = stack;
		ctx.r9.u64 = handleSlot;
		uint64_t entityHandle = EntityHandle_Get(ctx, base, handle);
		result = entityHandle;
		uint32_t entity = uint32_t(entityHandle);

		bool canGiveItem = entity != 0 && (LOAD8(entity + 144) & 64) != 0;
		if (canGiveItem) {
			bool haveItem = false;
			uint32_t itemId = 0;

			if (((LOAD32(entity + 64) >> 26) & 1) != 0) {
				uint32_t itemTable = LOAD32(entity + 140);
				if (itemTable != 0) {
					uint32_t tableOffset = uint32_t(LOAD8(itemTable + 250)) << 3;
					itemId = LOAD32(LOAD32(entity + 72) + tableOffset + 4);
					haveItem = true;
				} else {
					uint32_t begin = LOAD32(entity + 72);
					uint32_t end = LOAD32(entity + 76);
					STORE32(stack + 80, 0);
					STORE32(stack + 84, begin);

					// lower_bound over 8-byte entries keyed by their first word, looking for 250
					uint32_t it = begin;
					int32_t remaining = int32_t(end - begin) >> 3;
					while (remaining > 0) {
						int32_t half = remaining >> 1;
						uint32_t mid = it + uint32_t(half << 3);
						if (int32_t(LOAD32(mid)) < 250) {
							it = mid + 8;
							remaining = remaining - half - 1;
						} else {
							remaining = half;
						}
					}
					STORE32(stack + 84, it);

					if (it != end && int32_t(LOAD32(it)) <= 250) {
						itemId = LOAD32(it + 4);
					} else {
						itemId = LOAD32(end + 4);
					}
					haveItem = true;
				}
			}

			if (haveItem) {
				uint32_t chain = LOAD32(uint32_t(g_83490000) + 26912);
				chain = LOAD32(chain + 12);
				chain = LOAD32(chain + 88);
				chain = LOAD32(chain + 4);
				chain = LOAD32(chain + 8);
				chain = LOAD32(chain + 4);
				chain = LOAD32(chain + 36);
				uint32_t owner = LOAD32(chain + 4);
				uint64_t ownerField = uint64_t(owner) + 172;
				uint32_t container = LOAD32(owner + 172);
				if (container != 0 && LOAD32(container + 4) != 0) {
					ctx.r3.u64 = itemId;
					uint64_t reward = n_sub_828924A8(ctx, base, ownerField);
					uint32_t slot = uint32_t(n_sub_828923B8(ctx, base, itemId, ownerField));
					STORE32(stack + 80, slot);
					uint64_t arg = n_sub_82892960(ctx, base, uint64_t(itemId) + 60, uint64_t(stack) + 80);
					result = n_sub_8288D768(ctx, base, arg, uint32_t(reward));
				}
			}
		}
	}

	chest->m_F = uint8_t(1);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_8253DF30, 0x8253DF30) { ctx.r3.u64 = n_sub_8253DF30(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8253E168(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(33, 0x8253E168)) { ctx.r3.u64 = arg1; __imp__sub_8253E168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8253E168);
	return n_sub_8253DD60(ctx, base, arg1);
}
PROMOTED_ENTRY(33, sub_8253E168, 0x8253E168) { ctx.r3.u64 = n_sub_8253E168(ctx, base, ctx.r3.u64); }
