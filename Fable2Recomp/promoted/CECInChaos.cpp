// CECInChaos (vtable 0x820DFDE8): methods of the class as readable C++.
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

// sub_82894D18  [60 bytes]
uint64_t CECInChaos_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8E74_B_ = int32_t(0x820C8E74);
	if (!UseLiftedCode(60, 0x82894D18)) { ctx.r3.u64 = classNameString; __imp__sub_82894D18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82894D18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820C8E74_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(60, sub_82894D18, 0x82894D18) { ctx.r3.u64 = CECInChaos_GetClassName(ctx, base, ctx.r3.u64); }

// Tears the object down: releases the three EntityHandle members, sets the vtable to 0x820A8D10 (C_820A8D10)
// and frees the object when bit 0 of flags is set.
uint64_t n_sub_82894E68(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr, uint64_t flags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(60, 0x82894E68)) { ctx.r3.u64 = inChaosAddr; ctx.r4.u64 = flags; __imp__sub_82894E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82894E68);
	uint32_t stack = ctx.r1.u64;
	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);

	stack = PushStackFrame(base, stack, 128);

	// Each handle (+116, +108, +100) gets the EntityHandle vtable 0x820F1664 back, is released, then has its second word cleared.
	inChaos->m_74 = uint32_t(g_820F1664);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flags;
	EntityHandle_Release(ctx, base, inChaosAddr + 116);
	inChaos->m_78 = 0;
	inChaos->m_6C = uint32_t(g_820F1664);
	EntityHandle_Release(ctx, base, inChaosAddr + 108);
	inChaos->m_70 = 0;
	inChaos->m_64 = uint32_t(g_820F1664);
	EntityHandle_Release(ctx, base, inChaosAddr + 100);
	inChaos->m_68 = 0;

	inChaos->vtable = 0x820A8D10u;

	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, inChaosAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return inChaosAddr;
}
PROMOTED_ENTRY(60, sub_82894E68, 0x82894E68) { ctx.r3.u64 = n_sub_82894E68(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Serializes the floats at +72 and +76, the value at +68 and the entity UID at +92 by property name through
// the stream, then sets m_41 to 1 if the low byte of arg3 is zero and to 0 otherwise.
uint64_t n_sub_82894FD8(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr, uint64_t stream, uint64_t arg3) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820D0A08_B_ = int32_t(0x820D0A08);
	constexpr int32_t str_TXT_820DFD40_B_ = int32_t(0x820DFD40);
	constexpr int32_t str_TXT_820DFD50_B_ = int32_t(0x820DFD50);
	constexpr int32_t str_TXT_820DFD74_B_ = int32_t(0x820DFD74);
	if (!UseLiftedCode(60, 0x82894FD8)) { ctx.r3.u64 = inChaosAddr; ctx.r4.u64 = stream; ctx.r6.u64 = arg3; __imp__sub_82894FD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82894FD8);
	uint32_t stack = ctx.r1.u64;
	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);
	stack = PushStackFrame(base, stack, 128);

	// one scratch CCharString at stack+80, rebuilt for each property name
	const uint64_t scratchString = (uint64_t)stack + 80;
	// The float serializer receives the name in r4: the first word of the string's data,
	// or the sign-extended 0x8209003F when the string has no data.
	auto scratchNameText = [&]() -> uint64_t {
		const uint32_t nameData = LOAD32(scratchString);
		return nameData != 0 ? uint64_t(LOAD32(nameData)) : uint64_t(int64_t(g_8209003F));
	};

	// state the callees may pass on
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg3;

	CCharString_ConstructFromCStr(ctx, base, scratchString, str_TXT_820DFD40_B_, -1);
	ctx.r4.u64 = scratchNameText();
	IStream_SerializeFloat(ctx, base, stream, inChaosAddr + 72);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchString);

	CCharString_ConstructFromCStr(ctx, base, scratchString, str_TXT_820DFD50_B_, -1);
	ctx.r4.u64 = scratchNameText();
	IStream_SerializeFloat(ctx, base, stream, inChaosAddr + 76);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchString);

	CCharString_ConstructFromCStr(ctx, base, scratchString, str_TXT_820DFD74_B_, -1);
	IStream_SerializeString(ctx, base, scratchString, stream, inChaosAddr + 68);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchString);

	CCharString_ConstructFromCStr(ctx, base, scratchString, str_TXT_820D0A08_B_, -1);
	n_sub_8244DAE0(ctx, base, inChaosAddr + 92, scratchString, stream);
	const uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchString);

	inChaos->m_41 = uint8_t((arg3 & 0xFF) == 0);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_82894FD8, 0x82894FD8) { ctx.r3.u64 = n_sub_82894FD8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

// When m_41 is set: points the EntityHandle at +100 at the entity looked up by the UID at +92 (if the UID is
// nonzero), clears m_41 and m_40 and runs sub_82895338; then, when m_44 is set and m_46 clear, copies m_50 to
// m_1C, sets m_46 and runs sub_82895690.
uint64_t n_sub_828950E0(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr, uint64_t r8Value) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x828950E0)) { ctx.r3.u64 = inChaosAddr; ctx.r8.u64 = r8Value; __imp__sub_828950E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828950E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);
	uint64_t result = inChaosAddr;

	if (inChaos->m_41 != 0) {
		// the UID at +92 is two words; it is set when either word is nonzero
		const uint64_t uidAddr = inChaosAddr + 92;
		// r4 for sub_82895338: the UID address, or what the handle release below leaves in r4
		uint64_t r4ForUpdate = uidAddr;

		if (LOAD32((uint32_t)uidAddr) != 0 || LOAD32((uint32_t)uidAddr + 4) != 0) {
			const uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
			const uint32_t container = LOAD32(LOAD32(globalRoot + 12) + 88);
			const uint32_t containerData = LOAD32(container + 4);
			const uint32_t firstWord = LOAD32(containerData);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r8.u64 = containerData;
			ctx.r9.u64 = container;
			const uint64_t entity = n_sub_82264448(ctx, base, firstWord, uidAddr);

			// A temporary EntityHandle at stack+80 (vtable 0x820F1664, second word 0) is aimed at the entity,
			// assigned to the handle at +100, then released.
			const uint64_t tempHandle = (uint64_t)stack + 80;
			const uint64_t handleVtable = (int64_t)g_820F0000 + 5732;
			STORE32(stack + 84, 0);
			STORE32(stack + 80, (uint32_t)handleVtable);
			// state the callee may pass on
			ctx.r6.u64 = handleVtable;
			ctx.r7.s64 = g_820F0000;
			EntityHandle_SetTarget(ctx, base, tempHandle, entity);
			EntityHandle_Assign(ctx, base, inChaosAddr + 100, tempHandle);
			STORE32(stack + 80, (uint32_t)handleVtable);
			// state the callee may pass on
			ctx.r4.u64 = handleVtable;
			ctx.r5.s64 = g_820F0000;
			EntityHandle_Release(ctx, base, tempHandle);
			r4ForUpdate = ctx.r4.u64;
			r8Value = ctx.r8.u64;
		}

		inChaos->m_41 = 0;
		inChaos->m_40 = 0;

		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = r4ForUpdate;
		result = n_sub_82895338(ctx, base, inChaosAddr, r8Value);

		if (inChaos->m_44 != 0 && inChaos->m_46 == 0) {
			ctx.fpscr.disableFlushMode();
			inChaos->m_1C = float(double(inChaos->m_50));
			inChaos->m_46 = 1;
			result = n_sub_82895690(ctx, base, inChaosAddr, 1);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_828950E0, 0x828950E0) { ctx.r3.u64 = n_sub_828950E0(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_828951F0(CpuState& ctx, uint8_t* base, uint64_t chaos) {
	if (!UseLiftedCode(60, 0x828951F0)) { ctx.r3.u64 = chaos; __imp__sub_828951F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828951F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	n_sub_828955A0(ctx, base, chaos);
	uint64_t result = n_sub_828953C8(ctx, base, chaos);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_828951F0, 0x828951F0) { ctx.r3.u64 = n_sub_828951F0(ctx, base, ctx.r3.u64); }

// Clears the byte at +66 and runs sub_82896518 and sub_82895D30; when the owner (m_4) has bit 0x40 of its byte
// at +144 set, also runs sub_827178B8, sub_8271BAA8 and sub_824B7D48(3, owner, 5, 0) on it.
uint64_t n_sub_82895338(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr, uint64_t r8Value) {
	if (!UseLiftedCode(60, 0x82895338)) { ctx.r3.u64 = inChaosAddr; ctx.r8.u64 = r8Value; __imp__sub_82895338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82895338);
	uint32_t stack = ctx.r1.u64;
	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);
	stack = PushStackFrame(base, stack, 96);

	STORE8((uint32_t)inChaosAddr + 66, uint8_t(0));

	// state the callees may pass on; sub_8271BAA8 below takes r8 as the calls before it leave it
	ctx.r1.u64 = stack;
	ctx.r8.u64 = r8Value;
	n_sub_82896518(ctx, base, inChaosAddr);
	uint64_t result = n_sub_82895D30(ctx, base, inChaosAddr);

	const uint32_t owner = inChaos->m_4;
	if (owner != 0 && (LOAD8(owner + 144) & 64) != 0) {
		n_sub_827178B8(ctx, base, owner);
		n_sub_8271BAA8(ctx, base, owner, ctx.r8.u64);
		result = n_sub_824B7D48(ctx, base, 3, owner, 5, 0);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_82895338, 0x82895338) { ctx.r3.u64 = n_sub_82895338(ctx, base, ctx.r3.u64, ctx.r8.u64); }

// Runs sub_82895F68, then empties the EntityHandle at +116 (destroying the entity it refers to). When the owner
// (m_4) has the flag bits tested below and m_43 is set, finds the owner's entry with key 49 and calls the virtual
// function at slot +72 of the object stored there.
uint64_t n_sub_828953C8(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(60, 0x828953C8)) { ctx.r3.u64 = inChaosAddr; __imp__sub_828953C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828953C8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister xer = ctx.xer;
	PPCRegister callTarget{};
	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	// r6-r9 and the carry are tracked: the virtual call below receives them and callers read them back.
	uint64_t result = n_sub_82895F68(ctx, base, inChaosAddr);
	uint64_t outR6 = ctx.r6.u64;
	uint64_t outR7 = ctx.r7.u64;
	uint64_t outR8 = ctx.r8.u64;
	uint64_t outR9 = ctx.r9.u64;
	xer.ca = ctx.xer.ca;

	// The handle at +116 is {m_74, m_78}; m_78 points at an entry whose first word is the referenced object (0 once it is gone).
	const uint64_t handleAddr = inChaosAddr + 116;
	const uint32_t handleEntry = inChaos->m_78;
	if (handleEntry != 0) {
		uint32_t r10Value = LOAD32(handleEntry);
		uint64_t releaseAddr;
		if (r10Value != 0) {
			// Destroy the entity, then empty the handle by assigning it a temporary EntityHandle
			// (vtable 0x820F1664, second word 0) built at stack+80, which is released afterwards.
			ctx.r10.u64 = r10Value;
			const uint64_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			xer.ca = ctx.xer.ca;
			Entity_DestroyImpl(ctx, base, entity);
			xer.ca = ctx.xer.ca;
			const uint64_t tempHandle = (uint64_t)stack + 80;
			const uint64_t handleVtable = g_820F1664;
			STORE32(stack + 84, 0);
			STORE32(stack + 80, (uint32_t)handleVtable);
			ctx.r10.u64 = handleVtable;
			EntityHandle_Release(ctx, base, tempHandle);
			xer.ca = ctx.xer.ca;
			EntityHandle_Assign(ctx, base, handleAddr, tempHandle);
			r10Value = ctx.r10.u32;
			xer.ca = ctx.xer.ca;
			outR9 = g_820F0000;
			outR8 = handleVtable;
			STORE32(stack + 80, (uint32_t)handleVtable);
			releaseAddr = tempHandle;
		} else {
			// the entity is gone: release the handle itself
			releaseAddr = handleAddr;
		}
		// state the callee may pass on
		ctx.r8.u64 = outR8;
		ctx.r9.u64 = outR9;
		ctx.r10.u64 = r10Value;
		result = EntityHandle_Release(ctx, base, releaseAddr);
		outR6 = ctx.r6.u64;
		outR7 = ctx.r7.u64;
		outR8 = ctx.r8.u64;
		xer.ca = ctx.xer.ca;
	}

	const uint32_t owner = inChaos->m_4;
	bool callEntry = false;
	// r9 for the virtual call and for callers: the last flag bit tested, replaced by the entry address (index path)
	// or by the last half count (search loop)
	uint64_t r9Value = (LOAD32(owner + 52) >> 30) & 1;
	if (r9Value != 0 && inChaos->m_43 != 0) {
		result = 0;
		r9Value = (LOAD32(owner + 40) >> 17) & 1;
		if (r9Value != 0) {
			const uint32_t indexTable = LOAD32(owner + 140);
			if (indexTable != 0) {
				// the byte at +49 of the index table is the position of key 49 in the {key, value} pairs at +72
				const uint32_t position = LOAD8(indexTable + 49);
				r9Value = uint64_t(position << 3) + LOAD32(owner + 72);
				result = LOAD32((uint32_t)r9Value + 4);
			} else {
				// Lower bound of key 49 in the sorted 8-byte {key, value} pairs [entry, end) at +72/+76;
				// stack+80 holds {0, entry}. A missing key reads the word at end + 4.
				uint32_t entry = LOAD32(owner + 72);
				const uint32_t end = LOAD32(owner + 76);
				outR6 = end;
				STORE32(stack + 80, 0);
				uint32_t count = end - entry;
				STORE32(stack + 84, entry);
				xer.ca = ((int32_t)count < 0) & ((count & 0x7) != 0);
				count = (int32_t)count >> 3;
				if ((int32_t)count > 0) {
					do {
						xer.ca = ((int32_t)count < 0) & ((count & 0x1) != 0);
						const uint32_t half = (int32_t)count >> 1;
						const uint32_t halfBytes = half << 3;
						const uint32_t mid = entry + halfBytes;
						r9Value = half;
						outR8 = halfBytes;
						outR7 = int32_t(LOAD32(mid)) < 49 ? 1 : 0;
						if (outR7 != 0) {
							entry = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while ((int32_t)count > 0);
					STORE32(stack + 84, entry);
				}
				if (entry != end && int32_t(LOAD32(entry)) <= 49) {
					// the {0, entry} pair at stack+80 is copied onto itself
					STORE64(stack + 80, LOAD64(stack + 80));
					result = LOAD32(entry + 4);
				} else {
					result = LOAD32(end + 4);
				}
			}
			callEntry = true;
		}
	}

	if (callEntry) {
		const uint32_t method = LOAD32(LOAD32((uint32_t)result) + 72);
		callTarget.u64 = method;
		ctx.r3.u64 = result;
		ctx.r6.u64 = outR6;
		ctx.r7.u64 = outR7;
		ctx.r8.u64 = outR8;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = method;
		ctx.xer.ca = xer.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		outR6 = ctx.r6.u64;
		outR7 = ctx.r7.u64;
		outR8 = ctx.r8.u64;
		r9Value = ctx.r9.u64;
		xer.ca = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r6-r9 and the carry after the call
	ctx.r6.u64 = outR6;
	ctx.r7.u64 = outR7;
	ctx.r8.u64 = outR8;
	ctx.r9.u64 = r9Value;
	ctx.xer.ca = xer.ca;
	return result;
}
PROMOTED_ENTRY(60, sub_828953C8, 0x828953C8) { ctx.r3.u64 = n_sub_828953C8(ctx, base, ctx.r3.u64); }

// When m_46 is set: clears it, sets m_1C from the float at 0x820994B4 + 120 and runs sub_82895690(.., 0). Then, if
// bytes +52 and +53 of the object at root+12 -> +140 are both set, gets a vector from virtual slot +64 of the owner's
// object at +124 and another from sub_821F5A90, and passes both (v1, v2) to sub_824BA2C0 for the owner.
uint32_t n_sub_828955A0(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr) {
	constexpr int32_t g_820994B4 = int32_t(0x820994B4);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x828955A0)) { ctx.r3.u64 = inChaosAddr; __imp__sub_828955A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828955A0);
	uint32_t stack = ctx.r1.u64;
	// callers read r9 after the call
	uint64_t r9Value = ctx.r9.u64;
	PPCRegister callTarget{};
	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);
	stack = PushStackFrame(base, stack, 224);

	uint64_t result = inChaosAddr;
	if (inChaos->m_46 != 0) {
		inChaos->m_46 = 0;
		ctx.fpscr.disableFlushMode();
		inChaos->m_1C = float(double(LOAD_F32(g_820994B4 + 120)));
		ctx.r1.u64 = stack;
		result = n_sub_82895690(ctx, base, inChaosAddr, 0);

		const uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
		const uint32_t gateObject = LOAD32(LOAD32(globalRoot + 12) + 140);
		r9Value = LOAD8(gateObject + 52);
		if (r9Value != 0 && LOAD8(gateObject + 53) != 0) {
			const uint32_t ownerPart = LOAD32(LOAD32((uint32_t)inChaosAddr + 4) + 124);
			const uint32_t vtable = LOAD32(ownerPart);
			const uint32_t method = LOAD32(vtable + 64);
			// virtual call: r3 = 16-byte result buffer at stack+144, r4 = the object
			callTarget.u64 = method;
			ctx.r3.u64 = (uint64_t)stack + 144;
			ctx.r4.u64 = ownerPart;
			ctx.r9.u64 = method;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			const uint32_t owner = inChaos->m_4;
			const uint32_t secondVectorAddr = n_sub_821F5A90(ctx, base, (uint64_t)stack + 160, ownerPart);
			PPCVRegister secondVector{};
			SET_V8(secondVector, VLOAD(secondVectorAddr & ~0xFu));
			ctx.fpscr.disableFlushMode();
			const double floatConst = double(LOAD_F32(g_820994B4));
			STORE8(stack + 127, 0);
			STORE8(stack + 135, 1);
			PPCVRegister firstVector{};
			SET_V8(firstVector, VLOAD((stack + 144) & ~0xFu));
			// the vectors go to the callee in v1 and v2
			ctx.v1 = firstVector;
			ctx.v2 = secondVector;
			result = n_sub_824BA2C0(ctx, base, owner, owner, 0, 5, -1, 65536, floatConst, floatConst);
			r9Value = ctx.r9.u64;
		}
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	// callers read r9 after the call
	ctx.r9.u64 = r9Value;
	return result;
}
PROMOTED_ENTRY(60, sub_828955A0, 0x828955A0) { ctx.r3.u64 = n_sub_828955A0(ctx, base, ctx.r3.u64); }

// When the new state differs from the byte at +0x40 and bit 5 of the data flags (+0x34) is set: stores it at +12
// of the entry for key 133, runs sub_82895800 and then records it at +0x40.
uint64_t n_sub_82895690(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr, uint64_t newStateArg) {
	if (!UseLiftedCode(60, 0x82895690)) { ctx.r3.u64 = inChaosAddr; ctx.r4.u64 = newStateArg; __imp__sub_82895690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82895690);
	uint32_t stack = ctx.r1.u64;

	const uint8_t newState = (uint8_t)newStateArg;
	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = inChaosAddr;
	if (newState != inChaos->m_40) {
		const uint32_t chaosData = inChaos->m_4;

		if (((LOAD32(chaosData + 0x34) >> 5) & 1) != 0) {
			// r6-r8, cr0 and the carry as the original leaves them for the callee: entry values unless the lookup
			// changes them
			uint64_t calleeR6 = ctx.r6.u64;
			uint64_t calleeR7 = ctx.r7.u64;
			uint64_t calleeR8;
			PPCCRRegister compare0 = ctx.cr0;
			PPCXERRegister flags = ctx.xer;
			uint32_t node;
			const uint32_t indexOwner = LOAD32(chaosData + 0x8C);
			if (indexOwner != 0) {
				// slot of key 133 from the owner's byte table; the original adds in 64 bits
				calleeR8 = (uint64_t)LOAD32(chaosData + 0x48) + LOAD8(indexOwner + 0x85) * 8;
				node = LOAD32((uint32_t)calleeR8 + 4);
			} else {
				// binary search for key 133 in the sorted 8-byte entries [+0x48, +0x4C); not found gives the end
				uint32_t first = LOAD32(chaosData + 0x48);
				const uint32_t last = LOAD32(chaosData + 0x4C);
				calleeR6 = last;
				STORE32(stack + 80, 0);
				calleeR8 = (uint64_t)last - first;
				STORE32(stack + 84, first);
				const uint32_t span = (uint32_t)calleeR8;
				flags.ca = (int32_t)span < 0 && (span & 0x7) != 0;
				int32_t count = (int32_t)span >> 3;
				compare0.compare<int32_t>(count, 0, flags);
				if (count > 0) {
					do {
						const int32_t half = count >> 1;
						const uint32_t mid = first + half * 8;
						const bool belowKey = (int32_t)LOAD32(mid) < 133;
						calleeR7 = belowKey;
						calleeR8 = (uint32_t)(half * 8);
						if (belowKey) {
							first = mid + 8;
							count -= half + 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, first);
				}
				if (first != last && (int32_t)LOAD32(first) <= 133) {
					STORE64(stack + 80, LOAD64(stack + 80));
					node = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					node = LOAD32(last + 4);
				}
			}

			STORE8(node + 12, newState);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r4.u64 = newStateArg;
			ctx.r6.u64 = calleeR6;
			ctx.r7.u64 = calleeR7;
			ctx.r8.u64 = calleeR8;
			ctx.cr0.lt = compare0.lt;
			ctx.cr0.gt = compare0.gt;
			ctx.cr0.eq = compare0.eq;
			ctx.cr0.so = compare0.so;
			ctx.xer.ca = flags.ca;
			result = n_sub_82895800(ctx, base, inChaosAddr);
			inChaos->m_40 = newState;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_82895690, 0x82895690) { ctx.r3.u64 = n_sub_82895690(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// When bit 13 of the flags at +0x2C of the object at +4 is set: finds its entry for key 77 (slot cached at +0x4D
// of the object at +0x8C, else a binary search) and calls virtuals +0x48 and +0x8C on it.
uint64_t n_sub_82895800(CpuState& ctx, uint8_t* base, uint64_t self) {
	if (!UseLiftedCode(60, 0x82895800)) { ctx.r3.u64 = self; __imp__sub_82895800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82895800);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	const uint32_t holder = LOAD32((uint32_t)self + 4);
	if ((LOAD32(holder + 0x2C) >> 13) & 1) {
		// r6-r9 as the original leaves them for the first virtual call: entry values unless the lookup changes them
		uint64_t reg6 = ctx.r6.u64;
		uint64_t reg7 = ctx.r7.u64;
		uint64_t reg8 = ctx.r8.u64;
		uint64_t reg9;
		uint32_t node;
		const uint32_t companion = LOAD32(holder + 0x8C);
		if (companion != 0) {
			// The companion object caches the slot index of the entry.
			const uint32_t index = LOAD8(companion + 0x4D);
			reg9 = (uint64_t)index * 8 + LOAD32(holder + 0x48);
			node = LOAD32((uint32_t)reg9 + 4);
		} else {
			// Lower-bound search for key 77 over the sorted 8-byte entries [0x48,0x4C).
			uint32_t first = LOAD32(holder + 0x48);
			const uint32_t end = LOAD32(holder + 0x4C);
			reg6 = end;
			reg9 = 1;  // r9 still holds the tested flag bit unless the search loop runs
			STORE32(stack + 80, 0);
			int32_t count = (int32_t)(end - first) >> 3;
			STORE32(stack + 84, first);
			if (count > 0) {
				do {
					const int32_t half = count >> 1;
					const uint32_t mid = first + (uint32_t)half * 8;
					const bool keyLess = (int32_t)LOAD32(mid) < 77;
					reg9 = (uint64_t)half;
					reg8 = (uint64_t)((uint32_t)half << 3);
					reg7 = keyLess ? 1u : 0u;
					if (keyLess) {
						first = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, first);
			}
			if (first != end && (int32_t)LOAD32(first) <= 77) {
				STORE64(stack + 80, LOAD64(stack + 80));
				node = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				node = LOAD32(end + 4);
			}
		}

		callTarget.u64 = LOAD32(LOAD32(node) + 0x48);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = node;
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		const uint32_t vtable = LOAD32(node);
		callTarget.u64 = LOAD32(vtable + 0x8C);
		ctx.r3.u64 = node;
		ctx.r8.u64 = callTarget.u64;
		ctx.r9.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		self = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return self;
}
PROMOTED_ENTRY(60, sub_82895800, 0x82895800) { ctx.r3.u64 = n_sub_82895800(ctx, base, ctx.r3.u64); }

// Calls sub_82895C68, sub_82896128 and sub_828968B0, counts the timers at +0x4C and +0x48 down, feeds the +0x48
// timer to the entity behind the handle at +0x6C, removes component type 206 from the owner when that timer runs
// out or sub_824BCE78 returns 0, and formats the timer as text for sub_824B54A0 when the byte at 0x8349699D is set.
uint64_t n_sub_82895968(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820DFD88_B_ = int32_t(0x820DFD88);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x82895968)) { ctx.r3.u64 = arg1; ctx.r6.u64 = arg2; __imp__sub_82895968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82895968);
	PPCRegister scratch{};
	PPCVRegister savedV127 = ctx.v127;  // (restored on return)
	uint32_t stack = ctx.r1.u64;

	const uint32_t self = (uint32_t)arg1;
	PPCRegister callTarget{};

	// the original saves the non-volatile v127 below its frame
	VSTORE((stack + 0xFFFFFFA0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 352);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg2;
	n_sub_82895C68(ctx, base, arg1);
	n_sub_82896128(ctx, base, arg1);
	n_sub_828968B0(ctx, base, arg1);

	// f1Val / f13Val follow the original's f1 and f13: handed to calls below, f1 also left for the caller
	double f1Val = n_sub_82207928(ctx, base, LOAD32(self + 4));
	double f13Val = ctx.f13.f64;

	const uint32_t globalPtr = LOAD32(uint32_t(g_83490000) + 26912);
	ctx.fpscr.disableFlushMode();
	const double elapsed = double(float(f1Val / LOAD_F64(0x83319510u)));
	const uint32_t subObj = LOAD32(globalPtr + 12);
	const uint32_t flagObj = LOAD32(subObj + 140);
	const uint32_t flagByte = LOAD8(flagObj + 52);
	const bool active = flagByte != 0 && LOAD8(flagObj + 53) != 0;

	// values the original keeps in r8-r10 and hands to the calls below
	uint64_t r8Val = flagByte;
	uint64_t r9Val = subObj;
	uint64_t r10Val = uint32_t(g_820A0000);

	const uint32_t rodata = uint32_t(g_820A0000) - 27456;  // 0x820994C0
	ctx.fpscr.disableFlushMode();
	const double lowerLimit = double(LOAD_F32(rodata - 12));

	if (active && LOAD8(self + 68) != 0) {
		double timer = double(LOAD_F32(self + 76));
		bool expired = false;
		if (timer > lowerLimit) {
			timer = double(float(timer - elapsed));
			STORE_F32(self + 76, float(timer));
			if (!(timer > lowerLimit)) {
				STORE_F32(self + 76, float(lowerLimit));
				expired = true;
			}
		}
		if (expired) {
			// state the callee may pass on
			ctx.r8.u64 = r8Val;
			ctx.r9.u64 = r9Val;
			ctx.r10.u64 = r10Val;
			ctx.f1.f64 = f1Val;
			n_sub_82896D08(ctx, base, arg1);
			r8Val = ctx.r8.u64;
			r9Val = ctx.r9.u64;
			r10Val = ctx.r10.u32;
			f1Val = ctx.f1.f64;
			f13Val = ctx.f13.f64;
		}
	}

	ctx.fpscr.disableFlushMode();
	double timer2 = double(LOAD_F32(self + 72));
	bool removeComponent = false;
	if (timer2 > lowerLimit) {
		timer2 = double(float(timer2 - elapsed));
		STORE_F32(self + 72, float(timer2));
		if (!(timer2 > lowerLimit)) {
			STORE_F32(self + 72, float(lowerLimit));
			removeComponent = true;
		}
	}

	if (LOAD8(self + 66) == 0) {
		ctx.fpscr.disableFlushMode();
		f13Val = double(LOAD_F32(self + 72));
		if (!(f13Val > double(LOAD_F32(rodata - 396)))) {
			STORE8(self + 66, 1);
		}
	}

	// float constant at rodata + 0x2020: multiplies the +0x48 timer into the blend below and is added to the debug text vector
	ctx.fpscr.disableFlushMode();
	const double kRodata2020 = double(LOAD_F32(rodata + 8224));

	if (LOAD8(self + 66) != 0) {
		const uint64_t handleAddr = arg1 + 108;
		// state the callee may pass on
		ctx.r8.u64 = r8Val;
		ctx.r9.u64 = r9Val;
		ctx.r10.u64 = r10Val;
		ctx.f1.f64 = f1Val;
		ctx.f13.f64 = f13Val;
		const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		r8Val = ctx.r8.u64;
		r9Val = ctx.r9.u64;
		f1Val = ctx.f1.f64;
		f13Val = ctx.f13.f64;

		const uint32_t entityBit = entity != 0 ? (LOAD8(entity + 144) & 64) : 0;
		if (entityBit != 0) {
			ctx.fpscr.disableFlushMode();
			const double timeLeft = double(LOAD_F32(self + 72));
			if (!(timeLeft < lowerLimit)) {
				double blend = double(float(timeLeft * kRodata2020));
				if (blend < lowerLimit) {
					blend = lowerLimit;
				} else {
					ctx.fpscr.disableFlushMode();
					const double upperLimit = double(LOAD_F32(rodata));
					if (blend > upperLimit) {
						blend = upperLimit;
					}
				}

				ctx.fpscr.disableFlushMode();
				const double offsetBlend = double(float(blend + double(LOAD_F32(rodata + 108))));
				ctx.r10.u64 = entityBit;  // state the callee may pass on
				const uint32_t entityA = EntityHandle_Get_825575C8(ctx, base, handleAddr);
				ctx.fpscr.disableFlushMode();
				n_sub_824B8678(ctx, base, entityA, offsetBlend);

				ctx.fpscr.disableFlushMode();
				const double scaledBlend = double(float(blend * double(LOAD_F32(rodata + 18748))));
				const uint64_t entityB = EntityHandle_Get_825575C8(ctx, base, handleAddr);
				ctx.fpscr.disableFlushMode();
				n_sub_824B87D8(ctx, base, entityB, scaledBlend);
				r8Val = ctx.r8.u64;
				r9Val = ctx.r9.u64;
				f1Val = ctx.f1.f64;
				f13Val = ctx.f13.f64;
			}
		}
	}

	// state the callee may pass on
	ctx.r8.u64 = r8Val;
	ctx.r9.u64 = r9Val;
	uint64_t result = n_sub_824BCE78(ctx, base, LOAD32(self + 4));
	if ((uint32_t(result) & 0xFF) == 0) {
		removeComponent = true;
	}
	if (removeComponent) {
		STORE8(self + 67, 1);
		// state the callee may pass on
		ctx.f1.f64 = f1Val;
		ctx.f13.f64 = f13Val;
		n_sub_828955A0(ctx, base, arg1);
		n_sub_828953C8(ctx, base, arg1);
		result = Entity_RemoveComponentByType(ctx, base, LOAD32(self + 4), 206, ctx.r8.u64);
		f1Val = ctx.f1.f64;
		f13Val = ctx.f13.f64;
	}

	const uint32_t debugTextEnabled = LOAD8(0x8349699Du);
	if (debugTextEnabled != 0) {
		ctx.fpscr.disableFlushMode();
		f1Val = double(LOAD_F32(self + 72));
		STORE_F64(stack + 32, f1Val);
		const uint64_t textBuf = (uint64_t)stack + 128;
		// state the callee may pass on
		ctx.f1.f64 = f1Val;
		ctx.f13.f64 = f13Val;
		sprintf(ctx, base, textBuf, str_TXT_820DFD88_B_, LOAD64(stack + 32), ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, debugTextEnabled);

		const uint32_t owner = LOAD32(self + 4);
		const uint64_t text = CCharString_ConstructFromCStr(ctx, base, (uint64_t)stack + 84, textBuf, -1);

		// virtual +0x40 of the owner's component at +0x7C writes a vector to stack + 96
		const uint32_t component = LOAD32(owner + 124);
		const uint32_t vtable = LOAD32(component);
		callTarget.u64 = LOAD32(vtable + 64);
		ctx.r3.u64 = (uint64_t)stack + 96;
		ctx.r4.u64 = component;
		ctx.r9.u64 = callTarget.u64;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		PPCVRegister vec{};
		SET_V8(vec, VLOAD(uint32_t(stack + 96) & ~0xF));
		VSTORE(uint32_t(stack + 112) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		f13Val = double(float(double(LOAD_F32(stack + 120)) + kRodata2020));
		// merge the adjusted value into the vector with the permute mask at 0x820991F0
		PPCVRegister permMask{};
		PPCVRegister loaded{};
		SET_V8(permMask, VLOAD(0x820991F0u & ~0xF));
		STORE_F32(stack + 80, float(f13Val));
		scratch.u32 = uint32_t(stack + 80);
		SET_V8(loaded, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(vec, rex::ppc::simde_mm_perm_epi8_(V8(vec), V8(loaded), V8(permMask)));
		VSTORE(uint32_t(stack + 96) & ~0xF, V8(vec));
		// state the callee may pass on
		ctx.r8.u64 = (uint64_t)stack + 96;
		ctx.f13.f64 = f13Val;
		ctx.v7 = permMask;
		ctx.v13 = loaded;
		const uint64_t textCopy = CCharString_CopyConstruct(ctx, base, (uint64_t)stack + 80, text);
		ctx.v1 = vec;
		ctx.v127 = vec;
		n_sub_824B54A0(ctx, base, textCopy);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, text);
		f1Val = ctx.f1.f64;
	}

	stack = PopStackFrame(stack, 352);
	ctx.r1.u64 = stack;
	// callers read f1 after the call
	ctx.f1.f64 = f1Val;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(60, sub_82895968, 0x82895968) { ctx.r3.u64 = n_sub_82895968(ctx, base, ctx.r3.u64, ctx.r6.u64); }

// Counts the timer at +0x58 down. When it reaches the lower limit: with the flag at +0x45 set and +0x46 clear it
// copies +0x50 to +0x1C, sets +0x46 and switches the state to 1 (sub_82895690); with the flag clear and +0x46 set
// it calls sub_828955A0.
uint32_t n_sub_82895C68(CpuState& ctx, uint8_t* base, uint64_t inChaosAddr) {
	if (!UseLiftedCode(60, 0x82895C68)) { ctx.r3.u64 = inChaosAddr; __imp__sub_82895C68(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82895C68);
	uint32_t stack = ctx.r1.u64;
	CECInChaos* inChaos = GameObject<CECInChaos>(base, inChaosAddr);

	stack = PushStackFrame(base, stack, 96);
	const uint32_t chaosData = inChaos->m_4;
	ctx.r1.u64 = stack;
	const double rawStep = n_sub_82207928(ctx, base, chaosData);

	ctx.fpscr.disableFlushMode();
	double timer = double(LOAD_F32((uint32_t)inChaosAddr + 88));
	const double timeStep = double(float(rawStep / LOAD_F64(0x83319510u)));
	const double lowerLimit = double(LOAD_F32(0x820994B4u));

	bool expired = false;
	if (timer > lowerLimit) {
		timer = double(float(timer - timeStep));
		STORE_F32((uint32_t)inChaosAddr + 88, float(timer));
		if (!(timer > lowerLimit)) {
			STORE_F32((uint32_t)inChaosAddr + 88, float(lowerLimit));
			expired = true;
		}
	}

	if (expired) {
		const bool stateFlag = LOAD8((uint32_t)inChaosAddr + 69) != 0;
		const bool alreadyActive = inChaos->m_46 != 0;
		if (stateFlag && !alreadyActive) {
			ctx.fpscr.disableFlushMode();
			inChaos->m_1C = float(double(inChaos->m_50));
			inChaos->m_46 = uint8_t(1);
			// state the callee may pass on
			ctx.r5.u64 = inChaosAddr;
			ctx.f1.f64 = rawStep;
			ctx.f12.f64 = timeStep;
			ctx.f13.f64 = timer;
			const uint32_t callResult = n_sub_82895690(ctx, base, inChaosAddr, 1);
			// f1 and f13 stay as the callee left them
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return callResult;
		}
		if (!stateFlag && alreadyActive) {
			// state the callee may pass on
			ctx.r5.u64 = inChaosAddr;
			ctx.f1.f64 = rawStep;
			ctx.f12.f64 = timeStep;
			ctx.f13.f64 = timer;
			const uint32_t callResult = n_sub_828955A0(ctx, base, inChaosAddr);
			// f1 and f13 stay as the callee left them
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return callResult;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read f1 and f13 after the call
	ctx.f1.f64 = rawStep;
	ctx.f13.f64 = timer;
	return chaosData;
}
PROMOTED_ENTRY(60, sub_82895C68, 0x82895C68) { ctx.r3.u64 = n_sub_82895C68(ctx, base, ctx.r3.u64); }
