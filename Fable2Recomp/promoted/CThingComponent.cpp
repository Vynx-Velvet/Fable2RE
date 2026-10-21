// CThingComponent (vtable 0x820F8150): methods of the class as readable C++.
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

uint32_t CThingComponent_ClearLookupKey(CpuState& ctx, uint8_t* base, uint32_t lookupKey) {
	constexpr uint32_t globalVector = 0x834A548Cu;
	if (!UseLiftedCode(11, 0x822A0EB8)) { ctx.r3.u64 = lookupKey; __imp__sub_822A0EB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822A0EB8);
	GameStackFrame stackFrame(ctx, base, 144);

	auto resetEntry = [&](uint32_t entry) {
		const uint32_t entryBits = LOAD32(entry);
		STORE32(entry + 8, 0);
		STORE32(entry, (entryBits & 0x9FFFFFFFu) | 0x40000000u);
	};

	// Begin and end are read again on every pass: the searches may change the vector.
	uint32_t result = lookupKey;
	for (uint32_t index = 0;; index++) {
		const uint32_t elementsBegin = LOAD32(globalVector + 4);
		if (elementsBegin == 0) break;
		const uint32_t elementCount = uint32_t(int32_t(LOAD32(globalVector + 8) - elementsBegin) >> 2);
		if (index >= elementCount) break;
		const uint32_t element = LOAD32(elementsBegin + 4 * index);

		const uint32_t firstEntry = Vector_FindByKey(ctx, base, element + 4, lookupKey);
		if (firstEntry != 0) {
			resetEntry(firstEntry);
		}
		const uint32_t secondEntry = Vector_FindByKey(ctx, base, element + 64, lookupKey);
		if (secondEntry != 0) {
			resetEntry(secondEntry);
		}
		result = secondEntry;
	}
	return result;
}
PROMOTED_ENTRY(11, sub_822A0EB8, 0x822A0EB8) { ctx.r3.u64 = CThingComponent_ClearLookupKey(ctx, base, ctx.r3.u32); }

uint64_t CThingComponent_DeletingDestructor_82006C68(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint64_t deleteFlags, uint64_t passThroughA, uint64_t passThroughB) {
	constexpr uint32_t C_82006C68_vtable = 0x82006C68u;
	if (!UseLiftedCode(75, 0x82A606B8)) { ctx.r3.u64 = thingComponentAddr; ctx.r4.u64 = deleteFlags; ctx.r7.u64 = passThroughA; ctx.r8.u64 = passThroughB; __imp__sub_82A606B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A606B8);
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	thingComponent->vtable = C_82006C68_vtable;
	ctx.r4.u64 = deleteFlags;
	CThingComponent_Destruct(ctx, base, thingComponentAddr, passThroughA, passThroughB);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, thingComponentAddr);
	}
	return thingComponentAddr;
}
PROMOTED_ENTRY(75, sub_82A606B8, 0x82A606B8) { ctx.r3.u64 = CThingComponent_DeletingDestructor_82006C68(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CThingComponent_ConstructType10WithChildren(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint64_t sourceRecord) {
	constexpr uint32_t C_82006568_vtable = 0x82006568u;
	constexpr uint32_t managerPointer = 0x8349F6C4u;
	constexpr uint32_t firstChildParams = 0x8331D940u;
	constexpr uint32_t secondChildParams = 0x8331D964u;
	if (!UseLiftedCode(75, 0x82A60718)) { ctx.r3.u64 = thingComponentAddr; ctx.r4.u64 = sourceRecord; __imp__sub_82A60718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A60718);
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	CThingComponent_Construct(ctx, base, thingComponentAddr, 10, sourceRecord);
	const uint8_t member150 = thingComponent->m_150;
	thingComponent->vtable = C_82006568_vtable;
	if (member150 != 0 && thingComponent->m_152 == 0) {
		uint32_t firstChild = 0;
		const uint64_t firstAllocation = operator_new(ctx, base, 608);
		if (uint32_t(firstAllocation) != 0) {
			ctx.r4.u64 = LOAD32(managerPointer);
			firstChild = DirectionalLightRenderer_Construct(ctx, base, firstAllocation, thingComponentAddr, firstChildParams, 1);
		}
		thingComponent->m_B0 = firstChild;

		uint32_t secondChild = 0;
		const uint64_t secondAllocation = operator_new(ctx, base, 608);
		if (uint32_t(secondAllocation) != 0) {
			secondChild = DirectionalLightRenderer_Construct(ctx, base, secondAllocation, thingComponentAddr, secondChildParams, 0);
		}

		// The two children point at each other: +604 of the first, +600 of the second.
		const uint32_t storedFirstChild = thingComponent->m_B0;
		thingComponent->m_B4 = secondChild;
		STORE32(storedFirstChild + 604, secondChild);
		STORE32(uint32_t(thingComponent->m_B4) + 600, uint32_t(thingComponent->m_B0));
	}
	return thingComponentAddr;
}
PROMOTED_ENTRY(75, sub_82A60718, 0x82A60718) { ctx.r3.u64 = CThingComponent_ConstructType10WithChildren(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CThingComponent_ConstructType9WithPositionChild(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint64_t sourceRecord) {
	constexpr uint32_t C_82006900_vtable = 0x82006900u;
	constexpr uint32_t floatZero = 0x820994B4u;
	if (!UseLiftedCode(75, 0x82A67210)) { ctx.r3.u64 = thingComponentAddr; ctx.r4.u64 = sourceRecord; __imp__sub_82A67210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A67210);
	uint32_t stack = ctx.r1.u64;
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;
	CThingComponent_Construct(ctx, base, thingComponentAddr, 9, sourceRecord);
	thingComponent->vtable = C_82006900_vtable;
	thingComponent->m_330 = 0;

	if (thingComponent->m_150 != 0 && thingComponent->m_152 == 0) {
		ctx.fpscr.disableFlushMode();
		// The child's construction parameters, a 36-byte record in this frame.
		const uint32_t childParams = stack + 80;
		const double vectorX = thingComponent->m_108;
		const double vectorY = thingComponent->m_10C;
		const double vectorZ = thingComponent->m_110;
		const double zero = LOAD_F32(floatZero);
		STORE32(childParams + 0, 0);
		STORE32(childParams + 4, 1);
		STORE32(childParams + 8, 512);
		STORE_F32(childParams + 12, float(zero));
		STORE_F32(childParams + 16, float(zero));
		STORE_F32(childParams + 20, float(zero));
		STORE_F32(childParams + 24, float(vectorX));
		STORE_F32(childParams + 28, float(vectorY));
		STORE_F32(childParams + 32, float(vectorZ));

		ctx.f12.f64 = vectorZ;
		ctx.f13.f64 = vectorY;
		const uint64_t allocation = operator_new(ctx, base, 608);
		uint32_t child = 0;
		if (uint32_t(allocation) != 0) {
			child = DirectionalLightRenderer_Construct(ctx, base, allocation, thingComponentAddr, childParams, 0);
		}
		thingComponent->m_B0 = child;
		thingComponent->m_B4 = 0;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return thingComponentAddr;
}
PROMOTED_ENTRY(75, sub_82A67210, 0x82A67210) { ctx.r3.u64 = CThingComponent_ConstructType9WithPositionChild(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CThingComponent_DeletingDestructor_82006900(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint64_t deleteFlags, uint64_t passThroughA, uint64_t passThroughB) {
	constexpr uint32_t C_82006900_vtable = 0x82006900u;
	if (!UseLiftedCode(75, 0x82A67308)) { ctx.r3.u64 = thingComponentAddr; ctx.r4.u64 = deleteFlags; ctx.r7.u64 = passThroughA; ctx.r8.u64 = passThroughB; __imp__sub_82A67308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A67308);
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	thingComponent->vtable = C_82006900_vtable;
	ctx.r4.u64 = deleteFlags;
	CThingComponent_Destruct(ctx, base, thingComponentAddr, passThroughA, passThroughB);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, thingComponentAddr);
	}
	return thingComponentAddr;
}
PROMOTED_ENTRY(75, sub_82A67308, 0x82A67308) { ctx.r3.u64 = CThingComponent_DeletingDestructor_82006900(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CThingComponent_DeletingDestructor_820064A8(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint64_t deleteFlags, uint64_t passThroughA, uint64_t passThroughB) {
	constexpr uint32_t C_820064A8_vtable = 0x820064A8u;
	if (!UseLiftedCode(76, 0x82A78B88)) { ctx.r3.u64 = thingComponentAddr; ctx.r4.u64 = deleteFlags; ctx.r7.u64 = passThroughA; ctx.r8.u64 = passThroughB; __imp__sub_82A78B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A78B88);
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	thingComponent->vtable = C_820064A8_vtable;
	ctx.r4.u64 = deleteFlags;
	CThingComponent_Destruct(ctx, base, thingComponentAddr, passThroughA, passThroughB);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, thingComponentAddr);
	}
	return thingComponentAddr;
}
PROMOTED_ENTRY(76, sub_82A78B88, 0x82A78B88) { ctx.r3.u64 = CThingComponent_DeletingDestructor_820064A8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint32_t CThingComponent_Destruct_82B15910(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr) {
	constexpr uint32_t thingComponentBaseVtable = 0x820F8090u;
	if (!UseLiftedCode(81, 0x82B15910)) { ctx.r3.u64 = thingComponentAddr; __imp__sub_82B15910(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B15910);
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	thingComponent->vtable = thingComponentBaseVtable;
	if (int32_t(uint32_t(thingComponent->m_9C)) != -1 || int32_t(uint32_t(thingComponent->m_A0)) != -1) {
		CThingComponent_ClearLookupKey(ctx, base, uint32_t(thingComponentAddr));
	}
	return C_820F63C8_Destructor(ctx, base, thingComponentAddr);
}
PROMOTED_ENTRY(81, sub_82B15910, 0x82B15910) { ctx.r3.u64 = CThingComponent_Destruct_82B15910(ctx, base, ctx.r3.u64); }

uint32_t CThingComponent_Construct(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint32_t componentType, uint64_t sourceRecord) {
	constexpr uint32_t CThingComponent_vtable = 0x820F8150u;
	constexpr uint32_t floatZero = 0x820994B4u;
	constexpr uint32_t floatOne = 0x820994C0u;
	constexpr uint32_t floatThousand = 0x8209BAACu;
	constexpr int32_t doubleZeroPage = int32_t(0x82000000);
	if (!UseLiftedCode(81, 0x82B16A08)) { ctx.r3.u64 = thingComponentAddr; ctx.r4.u64 = componentType; ctx.r5.u64 = sourceRecord; __imp__sub_82B16A08(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B16A08);
	uint32_t stack = ctx.r1.u64;
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;
	CThingComponent_ConstructBase(ctx, base, thingComponentAddr, componentType, 1);
	thingComponent->vtable = CThingComponent_vtable;
	// The record is copied into the member at +192 (its vector at +96 is this object's +288).
	CThingComponent_CopyConstruct(ctx, base, thingComponentAddr + 192, sourceRecord);

	const uint64_t vectorCopy = uint64_t(stack) + 80;
	thingComponent->m_1CC = 0;
	ctx.fpscr.disableFlushMode();
	const double thousand = LOAD_F32(floatThousand);
	const double zero = LOAD_F32(floatZero);
	thingComponent->m_1D0 = 1;
	const double one = LOAD_F32(floatOne);
	thingComponent->m_1D8 = 0;
	thingComponent->m_1DC = 0;
	thingComponent->m_1E0 = 0;
	PPCVRegister recordVector;
	SET_V8(recordVector, VLOAD((uint32_t(thingComponentAddr) + 288) & ~0xFu));
	const double doubleZero = LOAD_F64(uint32_t(doubleZeroPage) + 3376);
	thingComponent->m_B0 = 0;
	thingComponent->m_1C8 = float(zero);
	thingComponent->m_B4 = 0;
	thingComponent->m_1C0 = float(one);
	thingComponent->m_1E4 = 0;
	thingComponent->m_1C4 = float(one);
	thingComponent->m_1BC = float(zero);

	// Elements 0 and 1 of the vector, read through two copies of it in this frame.
	VSTORE(uint32_t(vectorCopy) & ~0xFu, V8(recordVector));
	VSTORE((stack + 96) & ~0xFu, V8(recordVector));
	const double element0 = LOAD_F32(stack + 80);
	const double element1 = LOAD_F32(stack + 100);
	thingComponent->m_1B0 = doubleZero;
	const double elementSum = double(float(element1 + element0));
	const double scaledSum = double(float(elementSum * thousand));
	const int64_t truncated = std::isnan(scaledSum) ? int64_t(0x8000000000000000ULL)
		: scaledSum > double(LLONG_MAX) ? LLONG_MAX
		: simde_mm_cvttsd_si64(simde_mm_load_sd(&scaledSum));
	thingComponent->m_1B8 = uint32_t(truncated);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.s64 = doubleZeroPage;
	ctx.r8.u64 = vectorCopy;
	return uint32_t(thingComponentAddr);
}
PROMOTED_ENTRY(81, sub_82B16A08, 0x82B16A08) { ctx.r3.u64 = CThingComponent_Construct(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint64_t CThingComponent_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint64_t deleteFlags, uint64_t passThroughA, uint64_t passThroughB) {
	if (!UseLiftedCode(81, 0x82B16AF0)) { ctx.r3.u64 = thingComponentAddr; ctx.r4.u64 = deleteFlags; ctx.r7.u64 = passThroughA; ctx.r8.u64 = passThroughB; __imp__sub_82B16AF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B16AF0);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CThingComponent_Destruct(ctx, base, thingComponentAddr, passThroughA, passThroughB);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, thingComponentAddr);
	}
	return thingComponentAddr;
}
PROMOTED_ENTRY(81, sub_82B16AF0, 0x82B16AF0) { ctx.r3.u64 = CThingComponent_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint32_t CThingComponent_Destruct(CpuState& ctx, uint8_t* base, uint64_t thingComponentAddr, uint64_t passThroughA, uint64_t passThroughB) {
	constexpr uint32_t CThingComponent_vtable = 0x820F8150u;
	constexpr uint32_t managerPointer = 0x8349F6C4u;
	if (!UseLiftedCode(81, 0x82B16B40)) { ctx.r3.u64 = thingComponentAddr; ctx.r7.u64 = passThroughA; ctx.r8.u64 = passThroughB; __imp__sub_82B16B40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B16B40);
	const uint32_t lockedMsrBits = uint32_t(ctx.r13.u64);
	CThingComponent* thingComponent = GameObject<CThingComponent>(base, thingComponentAddr);
	GameStackFrame stackFrame(ctx, base, 128);

	// An owned child is unregistered first; if the slot still holds one afterwards, it is released and freed.
	auto releaseChild = [&](BigEndian<uint32_t>& childSlot) {
		const uint32_t child = childSlot;
		if (child == 0) {
			return;
		}
		const uint32_t manager = LOAD32(managerPointer);
		const uint32_t ownerThing = LOAD32(uint32_t(thingComponent->m_14) + 8);
		ctx.r7.u64 = passThroughA;
		n_sub_82A95370(ctx, base, manager, ownerThing, child, passThroughB);
		passThroughA = ctx.r7.u64;
		passThroughB = ctx.r8.u64;
		const uint32_t remainingChild = childSlot;
		if (remainingChild != 0) {
			n_sub_82A95790(ctx, base, remainingChild, passThroughA, passThroughB);
			HandleTarget_Free(ctx, base, remainingChild);
			passThroughA = ctx.r7.u64;
			passThroughB = ctx.r8.u64;
		}
		childSlot = 0u;
	};
	thingComponent->vtable = CThingComponent_vtable;
	releaseChild(thingComponent->m_B0);
	releaseChild(thingComponent->m_B4);

	// The container at +3684 of the object at m_14 holds 32-byte entries; the one whose word at +16 is this
	// component is removed.
	uint64_t entryIndex = 0;
	const uint32_t componentContainer = LOAD32(uint32_t(thingComponent->m_14) + 3684);
	const uint32_t entriesBegin = LOAD32(componentContainer + 8);
	const uint64_t entryCount = uint64_t(int64_t(int32_t(LOAD32(componentContainer + 12) - entriesBegin) >> 5));
	for (uint32_t entry = entriesBegin + 16; int32_t(entryIndex) < int32_t(entryCount); entry += 32) {
		const uint32_t entryOwner = LOAD32(entry);
		if (entryOwner == uint32_t(thingComponentAddr)) {
			ctx.r7.u64 = passThroughA;
			ctx.r9.u64 = entryOwner;
			ctx.r10.u64 = entryCount;
			ComponentContainer_RemoveEntry(ctx, base, componentContainer, thingComponentAddr, entryIndex, passThroughB);
			entryIndex = ctx.r5.u64;
			passThroughA = ctx.r7.u64;
			passThroughB = ctx.r8.u64;
			break;
		}
		entryIndex++;
	}

	const uint32_t ownedStorage = thingComponent->m_1D8;
	if (ownedStorage != 0) {
		ctx.r5.u64 = entryIndex;
		ctx.r7.u64 = passThroughA;
		ctx.r8.u64 = passThroughB;
		HandleTarget_Free(ctx, base, ownedStorage);
		entryIndex = ctx.r5.u64;
		passThroughA = ctx.r7.u64;
		passThroughB = ctx.r8.u64;
	}
	thingComponent->m_1D8 = 0u;
	thingComponent->m_1DC = 0u;
	thingComponent->m_1E0 = 0u;

	// Drop the reference held on the object at m_1CC (count at +4); the last one calls its virtual method at +4.
	const uint32_t sharedObject = thingComponent->m_1CC;
	if (sharedObject != 0) {
		const uint64_t refCountAddr = uint64_t(sharedObject) + 4;
		uint32_t newCount;
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			const uint32_t lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockedMsrBits & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(uint32_t(refCountAddr));
			newCount = __builtin_bswap32(ctx.reserved.u32) - 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(uint32_t(refCountAddr))), ctx.reserved.s32, __builtin_bswap32(newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		if (newCount == 0) {
			const uint32_t vtable = LOAD32(sharedObject);
			const uint32_t method = LOAD32(vtable + 4);
			ctx.r3.u64 = sharedObject;
			ctx.r5.u64 = entryIndex;
			ctx.r7.u64 = passThroughA;
			ctx.r8.u64 = passThroughB;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
		}
		thingComponent->m_1CC = 0u;
	}

	return CThingComponent_Destruct_82B15910(ctx, base, thingComponentAddr);
}
PROMOTED_ENTRY(81, sub_82B16B40, 0x82B16B40) { ctx.r3.u64 = CThingComponent_Destruct(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }
