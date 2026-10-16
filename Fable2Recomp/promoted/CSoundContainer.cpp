// CSoundContainer (vtable 0x8200B578): methods of the class as readable C++.
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

// sub_82C20CC0  [24 bytes]
void n_sub_82C20CC0(CpuState& ctx, uint8_t* base, uint32_t soundContainerAddr, uint32_t arg2, uint32_t arg3) {
	if (!UseLiftedCode(90, 0x82C20CC0)) { ctx.r3.u64 = soundContainerAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82C20CC0(ctx, base); return; }
	LiftedFrame frame(0x82C20CC0);
	PPCVRegister vectorData{};
	CSoundContainer* soundContainer = GameObject<CSoundContainer>(base, soundContainerAddr);
	STORE32(arg2, uint32_t(soundContainer->m_C));
	SET_V8(vectorData, VLOAD((soundContainerAddr + 16u) & ~0xF));
	VSTORE(arg3 & ~0xF, V8(vectorData));
	return;
}
PROMOTED_ENTRY(90, sub_82C20CC0, 0x82C20CC0) { n_sub_82C20CC0(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32); }

// sub_82C20CD8  [304 bytes]
uint64_t n_sub_82C20CD8(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(90, 0x82C20CD8)) { ctx.r4.u64 = arg1; ctx.r5.u64 = arg2; __imp__sub_82C20CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C20CD8);
	uint32_t stack = ctx.r1.u64;
	uint32_t soundParams = (uint32_t)arg2;   // T166637: parameter block (handle at +0x14, +0x18)
	uint64_t container = arg1;               // CSoundContainer
	// r4/r5/r9 as the caller must see them after the return; the callees overwrite
	// them, so the values are tracked here.
	uint64_t callerR4 = arg1;
	uint64_t callerR5 = arg2;
	uint64_t callerR9 = ctx.r9.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);
	if (LOAD32(soundParams) != 0) {
		double defaultValue = double(LOAD_F32(0x82000C08u));
		uint32_t handleLow = LOAD32(soundParams + 0x14);
		if (handleLow != 0) {
			uint32_t containerImpl = LOAD32((uint32_t)container);
			STORE_F32(stack + 80, float(defaultValue));
			uint32_t getValueFn = LOAD32(containerImpl + 0x38);
			callTarget.u64 = getValueFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = container;
			ctx.r4.u64 = handleLow;
			ctx.r5.u64 = (uint64_t)stack + 80;
			ctx.r10.u64 = getValueFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t gotValue = ctx.r3.u64;
			callerR5 = ctx.r5.u64;
			callerR9 = (uint32_t)gotValue & 0xFF;
			if ((uint32_t)callerR9 != 0) {
				ctx.fpscr.disableFlushMode();
				double value = double(LOAD_F32(stack + 80));
				PPCRegister negValue{};
				negValue.f64 = value;
				negValue.u64 ^= 0x8000000000000000ull;
				uint32_t paramsOwner = LOAD32(soundParams);
				double minValue = double(LOAD_F32(0x82000C0Cu));
				double lower = negValue.f64 >= 0.0 ? minValue : value;
				double diff = double(float(defaultValue - lower));
				double clamped = diff >= 0.0 ? lower : defaultValue;
				STORE_F32(stack + 80, float(clamped));
				uint32_t paramsVtable = LOAD32(paramsOwner);
				uint32_t applyFn = LOAD32(paramsVtable + 0x0C);
				callTarget.u64 = applyFn;
				ctx.r3.u64 = paramsOwner;
				ctx.r5.u64 = 0;
				ctx.r9.u64 = applyFn;
				ctx.r10.u64 = paramsVtable;
				ctx.f1.f64 = clamped;
				ctx.f10.f64 = diff;
				ctx.f11.f64 = lower;
				ctx.f12 = negValue;
				ctx.f13.f64 = minValue;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				callerR5 = ctx.r5.u64;
				callerR9 = ctx.r9.u64;
			}
		}
		callerR4 = LOAD32(soundParams + 0x18);
		if ((uint32_t)callerR4 != 0) {
			uint32_t containerImpl = LOAD32((uint32_t)container);
			ctx.fpscr.disableFlushMode();
			STORE_F32(stack + 80, float(defaultValue));
			uint32_t getValueFn = LOAD32(containerImpl + 0x38);
			callTarget.u64 = getValueFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = container;
			ctx.r4.u64 = callerR4;
			ctx.r5.u64 = (uint64_t)stack + 80;
			ctx.r9.u64 = callerR9;
			ctx.r10.u64 = getValueFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t gotValue = ctx.r3.u64;
			callerR4 = ctx.r4.u64;
			callerR5 = ctx.r5.u64;
			callerR9 = (uint32_t)gotValue & 0xFF;
			if ((uint32_t)callerR9 != 0) {
				ctx.fpscr.disableFlushMode();
				PPCRegister valueReg{};
				valueReg.f64 = double(LOAD_F32(stack + 80));
				uint32_t paramsOwner = LOAD32(soundParams);
				double rangeMin = double(LOAD_F32(0x82000BECu));
				double diffLow = double(float(rangeMin - valueReg.f64));
				double rangeMax = double(LOAD_F32((uint32_t)g_82000000 + 3140));
				double lower = diffLow >= 0.0 ? rangeMin : valueReg.f64;
				double diffHigh = double(float(rangeMax - lower));
				double clamped = diffHigh >= 0.0 ? lower : rangeMax;
				STORE_F32(stack + 80, float(clamped));
				uint32_t paramsVtable = LOAD32(paramsOwner);
				uint32_t applyFn = LOAD32(paramsVtable + 0x10);
				callTarget.u64 = applyFn;
				ctx.r3.u64 = paramsOwner;
				ctx.r5.u64 = 0;
				ctx.r8.u64 = applyFn;
				ctx.r9.u64 = paramsVtable;
				ctx.r10.s64 = g_82000000;
				ctx.f1.f64 = clamped;
				ctx.f9.f64 = diffHigh;
				ctx.f10.f64 = lower;
				ctx.f11.f64 = diffLow;
				ctx.f12 = valueReg;
				ctx.f13.f64 = rangeMax;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				callerR4 = ctx.r4.u64;
				callerR5 = ctx.r5.u64;
				callerR9 = ctx.r9.u64;
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	ctx.r5.u64 = callerR5;
	ctx.r9.u64 = callerR9;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(90, sub_82C20CD8, 0x82C20CD8) { ctx.r3.u64 = n_sub_82C20CD8(ctx, base, ctx.r4.u64, ctx.r5.u64); }

// sub_82C20E08  [116 bytes]
uint64_t n_sub_82C20E08(CpuState& ctx, uint8_t* base, uint64_t soundContainer, uint64_t callbackUserData) {
	if (!UseLiftedCode(90, 0x82C20E08)) { ctx.r3.u64 = soundContainer; ctx.r4.u64 = callbackUserData; __imp__sub_82C20E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C20E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Walk the container's chain of iterator nodes whose owner link points back at &m_firstIterator.
	uint32_t ownerAnchor = (uint32_t)soundContainer + 4;
	uint32_t iterator = LOAD32((uint32_t)soundContainer + 4);
	uint64_t result = soundContainer;
	uint64_t callerR4 = callbackUserData;

	while (iterator != 0) {
		result = LOAD32(iterator);
		uint32_t entry = (uint32_t)result;
		if (entry != 0) {
			uint32_t callback = LOAD32(LOAD32(entry) + 20);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = entry;
			ctx.r4.u64 = callbackUserData;
			ctx.r10.u64 = callback;
			REX_CALL_INDIRECT_FUNC(callback);
			result = ctx.r3.u64;
			callerR4 = ctx.r4.u64;
		}
		if (LOAD32(iterator + 16) != ownerAnchor) break;
		iterator = LOAD32(iterator + 8);
		if (iterator == 0) break;
		if (LOAD32(iterator + 16) != ownerAnchor) break;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(90, sub_82C20E08, 0x82C20E08) { ctx.r3.u64 = n_sub_82C20E08(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C20E80(CpuState& ctx, uint8_t* base, uint64_t soundContainer, uint64_t callArg) {
	if (!UseLiftedCode(90, 0x82C20E80)) { ctx.r3.u64 = soundContainer; ctx.r4.u64 = callArg; __imp__sub_82C20E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C20E80);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	// Walk the intrusive list rooted at soundContainer+4; each node points to a
	// sound item whose virtual handler (slot 3) is invoked, while the node's
	// owner field matches the list root.
	const uint32_t listOwner = (uint32_t)soundContainer + 4;
	const uint64_t handlerArg = callArg;
	uint32_t node = LOAD32(listOwner);
	uint64_t result = soundContainer;

	while (node != 0) {
		result = LOAD32(node);
		if ((uint32_t)result != 0) {
			uint32_t vtableMethod = LOAD32(LOAD32((uint32_t)result) + 24);
			callTarget.u64 = vtableMethod;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = result;
			ctx.r4.u64 = handlerArg;
			ctx.r10.u64 = vtableMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			callArg = ctx.r4.u64;
		}
		if (LOAD32(node + 16) != listOwner) break;
		node = LOAD32(node + 8);
		if (node == 0) break;
		if (LOAD32(node + 16) != listOwner) break;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callArg;
	return result;
}
PROMOTED_ENTRY(90, sub_82C20E80, 0x82C20E80) { ctx.r3.u64 = n_sub_82C20E80(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C20EF8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(90, 0x82C20EF8)) { ctx.r3.u64 = arg1; __imp__sub_82C20EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C20EF8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	const uint32_t container = (uint32_t)arg1;
	const uint32_t headAddr = container + 4;   // address of the list head field (end-of-list marker)
	uint32_t node = LOAD32(headAddr);
	uint64_t result = arg1;

	if (node != 0) {
		while (true) {
			const uint32_t payload = LOAD32(node);
			result = payload;
			if (payload != 0) {
				const uint32_t method = LOAD32(LOAD32(payload) + 28);
				callTarget.u64 = (uint64_t)method;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = payload;
				ctx.r10.u64 = method;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;
			}
			if (LOAD32(node + 16) != headAddr) break;
			node = LOAD32(node + 8);
			if (node == 0) break;
			if (LOAD32(node + 16) != headAddr) break;
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C20EF8, 0x82C20EF8) { ctx.r3.u64 = n_sub_82C20EF8(ctx, base, ctx.r3.u64); }

// sub_82C20F80  [164 bytes]
uint64_t n_sub_82C20F80(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(90, 0x82C20F80)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82C20F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C20F80);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);

	uint64_t current = arg1;
	uint32_t node = LOAD32((uint32_t)current + 4);
	const uint32_t ownerTag = (uint32_t)current + 4;
	const uint64_t arg2Frozen = arg2;

	// Tear down the intrusive list hanging off the container, clearing each node's two payloads.
	while (node != 0) {
		current = LOAD32(node);
		if ((uint32_t)current != 0) {
			uint32_t primaryMethod = LOAD32(LOAD32((uint32_t)current) + 32);
			callTarget.u64 = primaryMethod;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = current;
			ctx.r4.u64 = arg2Frozen;
			ctx.r5.u64 = arg3;
			ctx.r10.u64 = primaryMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			arg2 = ctx.r4.u64;

			current = LOAD32(node + 4);
			if ((uint32_t)current != 0) {
				uint32_t secondaryMethod = LOAD32(LOAD32((uint32_t)current) + 4);
				callTarget.u64 = secondaryMethod;
				ctx.r3.u64 = current;
				ctx.r10.u64 = secondaryMethod;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				current = ctx.r3.u64;
				arg2 = ctx.r4.u64;
			}
			STORE32(node + 4, 0);
			STORE32(node, 0);
		}
		if (LOAD32(node + 16) != ownerTag) break;
		node = LOAD32(node + 8);
		if (node == 0) break;
		if (LOAD32(node + 16) != ownerTag) break;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return current;
}
PROMOTED_ENTRY(90, sub_82C20F80, 0x82C20F80) { ctx.r3.u64 = n_sub_82C20F80(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// sub_82C21028  [116 bytes]
uint64_t n_sub_82C21028(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C21028)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C21028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C21028);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	uint64_t result = arg1;
	uint64_t r4Out = arg2;
	stack = PushStackFrame(base, stack, 112);
	// linked list of entries hanging off the container at offset 4; each entry
	// records the address of that list field at +0x10 so ownership can be checked.
	uint32_t listAddress = (uint32_t)arg1 + 4;
	uint32_t node = LOAD32(listAddress);
	while (node != 0) {
		uint32_t item = LOAD32(node);
		result = item;
		if (item != 0) {
			uint32_t method = LOAD32(LOAD32(item) + 4);
			callTarget.u64 = method;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = item;
			ctx.r4.u64 = arg2;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Out = ctx.r4.u64;
		}
		if (LOAD32(node + 16) != listAddress) break;
		node = LOAD32(node + 8);
		if (node == 0) break;
		if (LOAD32(node + 16) != listAddress) break;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	return result;
}
PROMOTED_ENTRY(90, sub_82C21028, 0x82C21028) { ctx.r3.u64 = n_sub_82C21028(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C210A0(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C210A0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C210A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C210A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t listRoot = (uint32_t)arg1 + 4;
	uint32_t node = LOAD32(listRoot);
	uint64_t callArg = arg2;
	uint64_t r4Out = arg2;
	uint64_t result = arg1;

	while (node != 0) {
		uint32_t listener = LOAD32(node);
		result = listener;
		if (listener != 0) {
			uint32_t method = LOAD32(LOAD32(listener) + 8);
			PPCRegister callTarget{};
			callTarget.u64 = method;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = listener;
			ctx.r4.u64 = callArg;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Out = ctx.r4.u64;
		}
		if (LOAD32(node + 16) != listRoot) break;
		uint32_t next = LOAD32(node + 8);
		if (next == 0) break;
		if (LOAD32(next + 16) != listRoot) break;
		node = next;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	return result;
}
PROMOTED_ENTRY(90, sub_82C210A0, 0x82C210A0) { ctx.r3.u64 = n_sub_82C210A0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C21118(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C21118)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C21118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C21118);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t containerAddr = (uint32_t)arg1;
	uint32_t listHeadAddr = containerAddr + 4;
	uint32_t node = LOAD32(listHeadAddr);
	uint64_t current = arg1;
	uint64_t callArg = arg2;

	STORE32(containerAddr + 12, (uint32_t)arg2);

	while (node != 0) {
		current = LOAD32(node);
		if ((uint32_t)current != 0) {
			uint32_t callback = LOAD32(LOAD32((uint32_t)current) + 40);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = current;
			ctx.r4.u64 = callArg;
			ctx.r10.u64 = callback;
			REX_CALL_INDIRECT_FUNC(callback);
			current = ctx.r3.u64;
			arg2 = ctx.r4.u64;
		}
		if (LOAD32(node + 16) != listHeadAddr) break;
		node = LOAD32(node + 8);
		if (node == 0) break;
		if (LOAD32(node + 16) != listHeadAddr) break;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return current;
}
PROMOTED_ENTRY(90, sub_82C21118, 0x82C21118) { ctx.r3.u64 = n_sub_82C21118(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82C21238  [444 bytes]
uint64_t CSoundContainer_WriteXml(CpuState& ctx, uint8_t* base, uint32_t soundContainerAddr, uint64_t xmlWriter) {
	constexpr int32_t g_82000C80 = int32_t(0x82000C80);
	constexpr int32_t str_TXT_8200B5AC_B_2 = int32_t(0x8200B5AC);
	constexpr int32_t str_TXT_8200B5BC_B_2 = int32_t(0x8200B5BC);
	constexpr int32_t str_TXT_8200B5BC_B_ = int32_t(0x8200B5C8);
	constexpr int32_t str_TXT_8200B5AC_B_ = int32_t(0x8200B5D4);
	if (!UseLiftedCode(90, 0x82C21238)) { ctx.r3.u64 = soundContainerAddr; ctx.r4.u64 = xmlWriter; __imp__sub_82C21238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C21238);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSoundContainer* soundContainer = GameObject<CSoundContainer>(base, soundContainerAddr);

	stack = PushStackFrame(base, stack, 160);
	ctx.r1.u64 = stack;
	uint32_t tagHolder = stack + 80;        // CharStringHolder for an opening tag
	uint32_t closeTagHolder = stack + 88;   // CharStringHolder for a closing tag


	n_sub_82BFF710(ctx, base, tagHolder);
	CharStringHolder_ConstructFromCString(ctx, base, tagHolder, str_TXT_8200B5AC_B_);
	CharStringHolder_ConstructFromCString(ctx, base, tagHolder, g_82000C80);
	uint64_t openingText = CharStringHolder_GetCStr(ctx, base, tagHolder);
	callTarget.u64 = (uint64_t)LOAD32(LOAD32((uint32_t)xmlWriter) + 8);
	ctx.r3.u64 = xmlWriter;
	ctx.r4.u64 = openingText;
	ctx.r10.u64 = callTarget.u32;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	CharStringHolder_Destructor(ctx, base, tagHolder);

	// Walk the sub-sound list hanging off the container.
	uint32_t listHeadAddr = soundContainerAddr + 4;
	uint32_t node = soundContainer->m_4;
	while (node != 0) {
		if (LOAD32(node) != 0) {

			n_sub_82BFF710(ctx, base, tagHolder);
			CharStringHolder_ConstructFromCString(ctx, base, tagHolder, str_TXT_8200B5BC_B_2);
			CharStringHolder_ConstructFromCString(ctx, base, tagHolder, g_82000C80);
			uint64_t subSoundOpenText = CharStringHolder_GetCStr(ctx, base, tagHolder);
			callTarget.u64 = (uint64_t)LOAD32(LOAD32((uint32_t)xmlWriter) + 8);
			ctx.r3.u64 = xmlWriter;
			ctx.r4.u64 = subSoundOpenText;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			CharStringHolder_Destructor(ctx, base, tagHolder);

			// Let the sub-sound write its own body.
			uint32_t TXT_8200B5BC_L_ = LOAD32(node);
			uint32_t subSoundVtable = LOAD32(TXT_8200B5BC_L_);
			uint32_t writeFn = LOAD32(subSoundVtable + 36);
			callTarget.u64 = (uint64_t)writeFn;
			ctx.r3.u64 = TXT_8200B5BC_L_;
			ctx.r4.u64 = xmlWriter;
			ctx.r9.u64 = writeFn;
			ctx.r10.u64 = subSoundVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);


			n_sub_82BFF710(ctx, base, closeTagHolder);
			CharStringHolder_ConstructFromCString(ctx, base, closeTagHolder, str_TXT_8200B5BC_B_);
			CharStringHolder_ConstructFromCString(ctx, base, closeTagHolder, g_82000C80);
			uint64_t subSoundCloseText = CharStringHolder_GetCStr(ctx, base, closeTagHolder);
			callTarget.u64 = (uint64_t)LOAD32(LOAD32((uint32_t)xmlWriter) + 8);
			ctx.r3.u64 = xmlWriter;
			ctx.r4.u64 = subSoundCloseText;
			ctx.r8.u64 = callTarget.u32;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			CharStringHolder_Destructor(ctx, base, closeTagHolder);
		}
		if (LOAD32(node + 16) != listHeadAddr) break;
		node = LOAD32(node + 8);
		if (node == 0) break;
		if (LOAD32(node + 16) != listHeadAddr) break;
	}


	n_sub_82BFF710(ctx, base, closeTagHolder);
	CharStringHolder_ConstructFromCString(ctx, base, closeTagHolder, str_TXT_8200B5AC_B_2);
	CharStringHolder_ConstructFromCString(ctx, base, closeTagHolder, g_82000C80);
	uint64_t closingText = CharStringHolder_GetCStr(ctx, base, closeTagHolder);
	callTarget.u64 = (uint64_t)LOAD32(LOAD32((uint32_t)xmlWriter) + 8);
	ctx.r3.u64 = xmlWriter;
	ctx.r4.u64 = closingText;
	ctx.r10.u64 = callTarget.u32;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = CharStringHolder_Destructor(ctx, base, closeTagHolder);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C21238, 0x82C21238) { ctx.r3.u64 = CSoundContainer_WriteXml(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t CSoundContainer_Dtor(CpuState& ctx, uint8_t* base, uint32_t soundContainerAddr) {
	if (!UseLiftedCode(90, 0x82C22EC8)) { ctx.r3.u64 = soundContainerAddr; __imp__sub_82C22EC8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C22EC8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSoundContainer* soundContainer = GameObject<CSoundContainer>(base, soundContainerAddr);
	stack = PushStackFrame(base, stack, 128);
	const uint32_t listAddr = soundContainerAddr + 4;  // head pointer at +0, tail pointer at +4
	uint32_t node = soundContainer->m_4;
	soundContainer->vtable = 0x8200B578u;
	while (node != 0) {
		const uint32_t nodeLinkAddr = node + 8;
		if (LOAD32(node + 16) == listAddr) {  // node belongs to this container's list
			uint32_t prev = LOAD32(node + 12);
			uint32_t next = LOAD32(node + 8);
			if (prev == 0) {
				if (next == 0) {
					STORE32(listAddr, 0);
					STORE32(listAddr + 4, 0);
				} else {
					STORE32(listAddr, next);
					STORE32(next + 12, 0);
				}
			} else if (next == 0) {
				STORE32(listAddr + 4, prev);
				STORE32(prev + 8, 0);
			} else {
				STORE32(prev + 8, next);
				STORE32(next + 12, prev);
			}
			STORE32(node + 12, 0);
			STORE32(node + 8, 0);
			STORE32(node + 16, 0);
		}
		uint32_t handle = LOAD32(node + 4);
		if (handle != 0) {
			uint32_t destroyFn = LOAD32(LOAD32(handle) + 4);
			callTarget.u64 = (uint64_t)destroyFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = handle;
			ctx.r9.u64 = nodeLinkAddr;
			ctx.r10.u64 = destroyFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		STORE32(node + 4, 0);
		uint32_t nodeToFree = node;
		STORE32(node, 0);
		ctx.r1.u64 = stack;
		HandleTarget_FreeThunk(ctx, base, nodeToFree);
		node = LOAD32(listAddr);
	}
	ctx.r1.u64 = stack;
	C_8200A34C_Destructor(ctx, base, soundContainerAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return soundContainerAddr;
}
PROMOTED_ENTRY(90, sub_82C22EC8, 0x82C22EC8) { ctx.r3.u64 = CSoundContainer_Dtor(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82C22FB0(CpuState& ctx, uint8_t* base, uint64_t soundContainerAddr, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C22FB0)) { ctx.r3.u64 = soundContainerAddr; ctx.r4.u64 = arg2; __imp__sub_82C22FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C22FB0);
	uint32_t stack = ctx.r1.u64;
	uint64_t containerAddr = soundContainerAddr;
	uint64_t savedArg2 = arg2;
	uint64_t flag = ctx.r9.u64;
	uint64_t result = soundContainerAddr;
	uint32_t listHeadAddr = (uint32_t)containerAddr + 4;
	PPCRegister callTarget{};
	CSoundContainer* soundContainer = GameObject<CSoundContainer>(base, soundContainerAddr);
	stack = PushStackFrame(base, stack, 144);

	uint32_t node = soundContainer->m_4;
	while (node != 0) {
		uint32_t linkAddr = node + 8;
		uint32_t nextToVisit;
		if (LOAD32(node + 16) != listHeadAddr) {
			nextToVisit = 0;
		} else {
			// keep walking the list only while the next node still belongs to this container
			uint32_t candidate = LOAD32(linkAddr);
			nextToVisit = candidate;
			if (candidate != 0 && LOAD32(candidate + 16) != listHeadAddr) {
				nextToVisit = 0;
			}
		}

		uint32_t objectPtr = LOAD32(node);
		if (objectPtr != 0) {
			uint32_t vtableFn = LOAD32(LOAD32(objectPtr));
			callTarget.u64 = vtableFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = objectPtr;
			ctx.r4.u64 = arg2;
			ctx.r10.u64 = vtableFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t vtableResult = ctx.r3.u32;
			arg2 = ctx.r4.u64;
			flag = vtableResult & 0xFF;
			if (flag == 0) {
				ctx.r3.u64 = containerAddr;
				ctx.r9.u64 = flag;
				result = n_sub_82C20CD8(ctx, base, savedArg2, node);
				arg2 = ctx.r4.u64;
				flag = ctx.r9.u64;
				node = nextToVisit;
				continue;
			}
		}

		if (LOAD32(linkAddr + 8) == listHeadAddr) {
			uint32_t prevNode = LOAD32(linkAddr + 4);
			uint32_t nextNode = LOAD32(linkAddr);
			if (prevNode == 0) {
				if (nextNode == 0) {
					STORE32(listHeadAddr, 0);
					STORE32(listHeadAddr + 4, 0);
				} else {
					STORE32(listHeadAddr, nextNode);
					STORE32(nextNode + 12, 0);
				}
			} else if (nextNode == 0) {
				STORE32(listHeadAddr + 4, prevNode);
				STORE32(prevNode + 8, 0);
			} else {
				STORE32(prevNode + 8, nextNode);
				STORE32(nextNode + 12, prevNode);
			}
			STORE32(linkAddr + 4, 0);
			STORE32(linkAddr, 0);
			STORE32(linkAddr + 8, 0);
		}

		uint32_t objectPtr2 = LOAD32(node + 4);
		if (objectPtr2 != 0) {
			uint32_t vtableFn2 = LOAD32(LOAD32(objectPtr2) + 4);
			callTarget.u64 = vtableFn2;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = objectPtr2;
			ctx.r4.u64 = arg2;
			ctx.r9.u64 = flag;
			ctx.r10.u64 = vtableFn2;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			arg2 = ctx.r4.u64;
			flag = ctx.r9.u64;
		}

		STORE32(node + 4, 0);
		STORE32(node, 0);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		ctx.r9.u64 = flag;
		result = HandleTarget_FreeThunk(ctx, base, node);
		arg2 = ctx.r4.u64;
		flag = ctx.r9.u64;

		node = nextToVisit;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return result;
}
PROMOTED_ENTRY(90, sub_82C22FB0, 0x82C22FB0) { ctx.r3.u64 = n_sub_82C22FB0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CSoundContainer_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(90, 0x82C23198)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C23198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C23198);
	uint32_t stack = ctx.r1.u64;
	uint32_t deleteFlags = arg2;

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	ctx.r4.u64 = arg2;
	CSoundContainer_Dtor(ctx, base, arg1);

	uint64_t thisPtr = arg1;
	if (deleteFlags & 0x1) {
		HandleTarget_FreeThunk(ctx, base, thisPtr);
		thisPtr = arg1;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return thisPtr;
}
PROMOTED_ENTRY(90, sub_82C23198, 0x82C23198) { ctx.r3.u64 = CSoundContainer_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
