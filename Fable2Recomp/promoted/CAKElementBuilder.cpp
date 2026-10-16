// CAKElementBuilder (vtable 0x820065E0): methods of the class as readable C++.
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

// sub_821CDF88  [8 bytes]
uint64_t n_sub_821CDF88(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(3, 0x821CDF88)) { ctx.r4.u64 = arg1; __imp__sub_821CDF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821CDF88);
	uint32_t value = LOAD32(arg1 + 8);
	return value;
}
PROMOTED_ENTRY(3, sub_821CDF88, 0x821CDF88) { ctx.r3.u64 = n_sub_821CDF88(ctx, base, ctx.r4.u32); }

// sub_821D2C58  [24 bytes]
// A CAKElementBuilder virtual: the builder (r3) is unused; the flags tested are the node's, passed in r4.
uint64_t CAKElementBuilder_HasFlag(CpuState& ctx, uint8_t* base, uint32_t node, uint32_t mask) {
	if (!UseLiftedCode(3, 0x821D2C58)) { ctx.r4.u64 = node; ctx.r5.u64 = mask; __imp__sub_821D2C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D2C58);
	uint32_t maskedFlags = LOAD16(node + 28) & mask;
	return maskedFlags != 0 ? 1 : 0;
}
PROMOTED_ENTRY(3, sub_821D2C58, 0x821D2C58) { ctx.r3.u64 = CAKElementBuilder_HasFlag(ctx, base, ctx.r4.u32, ctx.r5.u32); }

uint64_t CAKElementBuilder_GetField12(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(10, 0x82283EC8)) { ctx.r4.u64 = arg1; __imp__sub_82283EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82283EC8);
	uint32_t field12 = LOAD32(arg1 + 12);
	return field12;
}
PROMOTED_ENTRY(10, sub_82283EC8, 0x82283EC8) { ctx.r3.u64 = CAKElementBuilder_GetField12(ctx, base, ctx.r4.u32); }

// sub_82284200  [8 bytes]
// A CAKElementBuilder virtual: the builder (r3) is unused; the word read belongs to the node passed in r4.
uint64_t CAKElementBuilder_GetField24(CpuState& ctx, uint8_t* base, uint32_t node) {
	if (!UseLiftedCode(10, 0x82284200)) { ctx.r4.u64 = node; __imp__sub_82284200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82284200);
	return LOAD32(node + 24);
}
PROMOTED_ENTRY(10, sub_82284200, 0x82284200) { ctx.r3.u64 = CAKElementBuilder_GetField24(ctx, base, ctx.r4.u32); }

// sub_82284208  [12 bytes]
uint64_t CAKElementBuilder_IsFlag12Set(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(10, 0x82284208)) { ctx.r4.u64 = arg1; __imp__sub_82284208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82284208);
	uint16_t flags = LOAD16(arg1 + 0x1C);
	return (flags >> 12) & 1;
}
PROMOTED_ENTRY(10, sub_82284208, 0x82284208) { ctx.r3.u64 = CAKElementBuilder_IsFlag12Set(ctx, base, ctx.r4.u32); }

// sub_82284300  [328 bytes]
// A CAKElementBuilder virtual. When the node has an entry for key whose value differs from newValue (or whose
// state bits, mask 28, equal 20): appends the node once to the list returned by a virtual call on the m_4
// object, stores newValue and sets entry bit 1, and, if node flag 64 is set, calls each callback of the node's
// record in the builder with (entry, previous value, newValue, callback argument).
uint64_t n_sub_82284300(CpuState& ctx, uint8_t* base, uint32_t aKElementBuilderAddr, uint64_t node, uint64_t key, uint64_t newValue) {
	if (!UseLiftedCode(10, 0x82284300)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = node; ctx.r5.u64 = key; ctx.r6.u64 = newValue; __imp__sub_82284300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82284300);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CAKElementBuilder* aKElementBuilder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);
	uint32_t nodeAddr = (uint32_t)node;
	stack = PushStackFrame(base, stack, 144);
	uint32_t nodeSlot = stack + 172;
	STORE32(nodeSlot, nodeAddr);
	// callers read r4 after the call: the key, or what the last call below left in r4
	uint64_t r4Value = key;

	ctx.r1.u64 = stack;
	uint64_t entry = CAKElementBuilder_FindByKey(ctx, base, node, key);
	uint32_t entryAddr = (uint32_t)entry;
	uint64_t result = entry;

	if (entryAddr != 0 &&
	    (LOAD32(entryAddr + 4) != (uint32_t)newValue || (LOAD32(entryAddr) & 28) == 20)) {
		// bit 15 of the node flags is set once the node has been appended to the list
		if ((LOAD16(nodeAddr + 28) & 0x8000) == 0) {
			uint32_t listProvider = aKElementBuilder->m_4;
			uint32_t getList = LOAD32(LOAD32(listProvider) + 116);
			callTarget.u64 = getList;
			// state the callee may read
			ctx.r3.u64 = listProvider;
			ctx.r4.u64 = key;
			ctx.r10.u64 = getList;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = n_sub_82284810(ctx, base, ctx.r3.u64, nodeSlot);
			r4Value = ctx.r4.u64;
			STORE16(nodeAddr + 28, uint16_t(LOAD16(nodeAddr + 28) | 0x8000));
		}

		uint32_t previousValue = LOAD32(entryAddr + 4);
		uint32_t entryWord = LOAD32(entryAddr) | 2;
		STORE32(entryAddr + 4, (uint32_t)newValue);
		STORE32(entryAddr, entryWord);

		uint16_t nodeFlags = LOAD16(nodeAddr + 28);
		if ((nodeFlags & 64) != 0) {
			// r8/r9/r10 keep the scratch values this function last computed in them; the callbacks get them
			uint64_t r8Value = nodeFlags & 64;
			uint64_t r9Value = nodeFlags;

			// find the node's record: m_38 is an array of m_40 record pointers, each record starting with its node
			uint32_t recordCount = aKElementBuilder->m_40;
			uint32_t recordCursor = aKElementBuilder->m_38;
			uint32_t recordEnd = recordCursor + (recordCount << 2);
			uint32_t recordBody = 0;
			while (recordCursor != recordEnd) {
				uint32_t record = LOAD32(recordCursor);
				uint32_t recordNode = LOAD32(record);
				r9Value = record;
				r8Value = recordNode;
				if (recordNode == nodeAddr) {
					recordBody = record + 4;
					break;
				}
				recordCursor += 4;
			}

			// recordBody + 32: array of (function, argument) pairs, recordBody + 40: their count
			// (recordBody stays 0 when no record matches, and these reads still happen, as in the original)
			uint32_t callbackCount = LOAD32(recordBody + 40);
			uint32_t callbacksBegin = LOAD32(recordBody + 32);
			uint64_t callbacksEnd = (callbackCount << 3) + uint64_t(callbacksBegin);
			uint64_t r10Value = callbacksEnd;
			uint32_t callbackCursor = callbacksBegin;
			while (callbackCursor != (uint32_t)callbacksEnd) {
				uint32_t callbackArg = LOAD32(callbackCursor + 4);
				callTarget.u64 = LOAD32(callbackCursor);
				ctx.r3.u64 = entry;
				ctx.r4.u64 = previousValue;
				ctx.r5.u64 = newValue;
				ctx.r6.u64 = callbackArg;
				ctx.r8.u64 = r8Value;
				ctx.r9.u64 = r9Value;
				ctx.r10.u64 = r10Value;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;
				r4Value = ctx.r4.u64;
				callbackCursor += 8;
				// start and count are re-read after every callback (the cursor is not rebased)
				callbackCount = LOAD32(recordBody + 40);
				callbacksBegin = LOAD32(recordBody + 32);
				callbacksEnd = (callbackCount << 3) + uint64_t(callbacksBegin);
				r9Value = callbackCount;
				r8Value = callbacksEnd;
				r10Value = callbacksBegin;
			}
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(10, sub_82284300, 0x82284300) { ctx.r3.u64 = n_sub_82284300(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_82284750  [188 bytes]
// A CAKElementBuilder virtual: sets (enable & 0xFF nonzero) or clears the mask bits in the node flags. When the
// mask includes bit 12 and the call changes bit 12, the node is first appended once to the list returned by a
// virtual call on the m_4 object, as in sub_82284300.
uint64_t n_sub_82284750(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint64_t node, uint64_t flagMask, uint64_t enable) {
	if (!UseLiftedCode(10, 0x82284750)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = node; ctx.r5.u64 = flagMask; ctx.r6.u64 = enable; __imp__sub_82284750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82284750);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t nodeAddr = (uint32_t)node;
	uint32_t mask = (uint32_t)flagMask;
	bool setBits = (enable & 0xFF) != 0;
	uint32_t nodeSlot = stack + 140;
	STORE32(nodeSlot, nodeAddr);
	uint64_t result = aKElementBuilderAddr;
	// callers read r4 after the call: the node, or what the calls below left in r4
	uint64_t r4Value = node;

	if ((mask & 0x1000) != 0) {
		uint16_t nodeFlags = LOAD16(nodeAddr + 28);
		bool bit12Set = (nodeFlags & 0x1000) != 0;
		// bit 15 of the node flags is set once the node has been appended to the list
		if ((nodeFlags & 0x8000) == 0 && bit12Set != setBits) {
			uint32_t listProvider = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr)->m_4;
			uint32_t getList = LOAD32(LOAD32(listProvider) + 116);
			PPCRegister callTarget{};
			callTarget.u64 = getList;
			// state the callee may read
			ctx.r1.u64 = stack;
			ctx.r3.u64 = listProvider;
			ctx.r4.u64 = node;
			ctx.r5.u64 = flagMask;
			ctx.r6.u64 = enable;
			ctx.r10.u64 = getList;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = n_sub_82284810(ctx, base, ctx.r3.u64, nodeSlot);
			r4Value = ctx.r4.u64;
			STORE16(nodeAddr + 28, uint16_t(LOAD16(nodeAddr + 28) | 0x8000));
		}
	}

	uint16_t nodeFlags = LOAD16(nodeAddr + 28);
	if (setBits) {
		STORE16(nodeAddr + 28, uint16_t(nodeFlags | mask));
	} else {
		STORE16(nodeAddr + 28, uint16_t(nodeFlags & ~mask));
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(10, sub_82284750, 0x82284750) { ctx.r3.u64 = n_sub_82284750(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_82BAC8A8  [108 bytes]
// A CAKElementBuilder virtual: looks up the node entry whose key is the word at keyAddr shifted right by 5;
// when found, stores its value at valueOutAddr and its whole key word at keyAddr. Returns whether it was found.
uint64_t n_sub_82BAC8A8(CpuState& ctx, uint8_t* base, uint64_t node, uint32_t keyAddr, uint32_t valueOutAddr) {
	if (!UseLiftedCode(86, 0x82BAC8A8)) { ctx.r4.u64 = node; ctx.r5.u64 = keyAddr; ctx.r6.u64 = valueOutAddr; __imp__sub_82BAC8A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAC8A8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 112);
	uint32_t key = LOAD32(keyAddr) >> 5;
	ctx.r1.u64 = stack;
	uint32_t entry = CAKElementBuilder_FindByKey(ctx, base, node, key);
	bool found = entry != 0;
	if (found) {
		STORE32(valueOutAddr, LOAD32(entry + 4));
		STORE32(keyAddr, LOAD32(entry));
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = key;  // callers read r4 after the call
	return found;
}
PROMOTED_ENTRY(86, sub_82BAC8A8, 0x82BAC8A8) { ctx.r3.u64 = n_sub_82BAC8A8(ctx, base, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32); }

// sub_82BAC918  [96 bytes]
// Looks up the element's entry with the given key; when found, stores the entry's value to outValueAddr
// and returns 1, otherwise returns 0.
uint64_t n_sub_82BAC918(CpuState& ctx, uint8_t* base, uint64_t element, uint64_t key, uint32_t outValueAddr) {
	if (!UseLiftedCode(86, 0x82BAC918)) { ctx.r4.u64 = element; ctx.r5.u64 = key; ctx.r6.u64 = outValueAddr; __imp__sub_82BAC918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAC918);
	uint32_t stack = ctx.r1.u32;

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t entry = CAKElementBuilder_FindByKey(ctx, base, element, key);
	if (entry != 0) {
		STORE32(outValueAddr, LOAD32(entry + 4));
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = key; // callers read r4 after the call
		return 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = key; // callers read r4 after the call
	return 0;
}
PROMOTED_ENTRY(86, sub_82BAC918, 0x82BAC918) { ctx.r3.u64 = n_sub_82BAC918(ctx, base, ctx.r4.u64, ctx.r5.u64, ctx.r6.u32); }

// sub_82BAC978  [8 bytes]
uint64_t n_sub_82BAC978(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(86, 0x82BAC978)) { ctx.r4.u64 = arg1; __imp__sub_82BAC978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAC978);
	return LOAD8(arg1 + 31);
}
PROMOTED_ENTRY(86, sub_82BAC978, 0x82BAC978) { ctx.r3.u64 = n_sub_82BAC978(ctx, base, ctx.r4.u32); }

// sub_82BAC980  [68 bytes]
// Reads entry `index` of the element's 8-byte entry array: the key (first word >> 5, the value
// CAKElementBuilder_FindByKey matches) and the value (second word).
void n_sub_82BAC980(CpuState& ctx, uint8_t* base, uint32_t element, uint32_t index, uint32_t outKeyAddr, uint32_t outValueAddr) {
	if (!UseLiftedCode(86, 0x82BAC980)) { ctx.r4.u64 = element; ctx.r5.u64 = index; ctx.r6.u64 = outKeyAddr; ctx.r7.u64 = outValueAddr; __imp__sub_82BAC980(ctx, base); return; }
	LiftedFrame frame(0x82BAC980);
	uint32_t entryAddr;
	if ((LOAD16(element + 28) & 0x1) != 0) {
		entryAddr = element + 68 + (index << 3);
	} else {
		entryAddr = element + 32 + (index << 3);
	}
	STORE32(outKeyAddr, LOAD32(entryAddr) >> 5);
	STORE32(outValueAddr, LOAD32(entryAddr + 4));
	return;
}
PROMOTED_ENTRY(86, sub_82BAC980, 0x82BAC980) { n_sub_82BAC980(ctx, base, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32); }

// sub_82BAC9C8  [24 bytes]
// Returns the element's first word, or 0x82000C98 (a zero word in the image's constant data) when it is null.
uint64_t n_sub_82BAC9C8(CpuState& ctx, uint8_t* base, uint32_t element) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	if (!UseLiftedCode(86, 0x82BAC9C8)) { ctx.r4.u64 = element; __imp__sub_82BAC9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAC9C8);
	uint32_t firstWord = LOAD32(element);
	if (firstWord != 0) return firstWord;
	return g_82000C98;
}
PROMOTED_ENTRY(86, sub_82BAC9C8, 0x82BAC9C8) { ctx.r3.u64 = n_sub_82BAC9C8(ctx, base, ctx.r4.u32); }

// sub_82BAC9E0  [8 bytes]
uint64_t n_sub_82BAC9E0(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	if (!UseLiftedCode(86, 0x82BAC9E0)) { ctx.r4.u64 = arg1; __imp__sub_82BAC9E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAC9E0);
	return LOAD32(arg1 + 4);
}
PROMOTED_ENTRY(86, sub_82BAC9E0, 0x82BAC9E0) { ctx.r3.u64 = n_sub_82BAC9E0(ctx, base, ctx.r4.u32); }

// sub_82BAC9E8  [8 bytes]
void n_sub_82BAC9E8(CpuState& ctx, uint8_t* base, uint32_t element, uint32_t value) {
	if (!UseLiftedCode(86, 0x82BAC9E8)) { ctx.r4.u64 = element; ctx.r5.u64 = value; __imp__sub_82BAC9E8(ctx, base); return; }
	LiftedFrame frame(0x82BAC9E8);
	STORE32(element + 4, value);
	return;
}
PROMOTED_ENTRY(86, sub_82BAC9E8, 0x82BAC9E8) { n_sub_82BAC9E8(ctx, base, ctx.r4.u32, ctx.r5.u32); }

// sub_82BAC9F0  [8 bytes]
uint64_t CAKElementBuilder_FindNodeById(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint64_t nodeId) {
	if (!UseLiftedCode(86, 0x82BAC9F0)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = nodeId; __imp__sub_82BAC9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAC9F0);
	CAKElementBuilder* aKElementBuilder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);
	uint32_t pRoot = aKElementBuilder->m_pRoot;
	uint64_t nodeByIdRecursive = CAKElementBuilder_FindNodeByIdRecursive(ctx, base, aKElementBuilderAddr, nodeId, pRoot);
	return nodeByIdRecursive;
}
PROMOTED_ENTRY(86, sub_82BAC9F0, 0x82BAC9F0) { ctx.r3.u64 = CAKElementBuilder_FindNodeById(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CAKElementBuilder_FindNodeByIdRecursive(CpuState& ctx, uint8_t* base, uint64_t elementBuilder, uint32_t nodeId, uint64_t currentNode) {
	if (!UseLiftedCode(86, 0x82BAC9F8)) { ctx.r3.u64 = elementBuilder; ctx.r4.u64 = nodeId; ctx.r5.u64 = currentNode; __imp__sub_82BAC9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAC9F8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 112);

	if (LOAD32((uint32_t)currentNode + 4) == nodeId) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return currentNode;
	}

	// Walk the 0x10-linked list of children starting at currentNode->m_14.
	uint64_t foundNode = 0;
	for (uint32_t childNode = LOAD32((uint32_t)currentNode + 20); childNode != 0 && (uint32_t)foundNode == 0; childNode = LOAD32(childNode + 16)) {
		ctx.r1.u64 = stack;
		foundNode = CAKElementBuilder_FindNodeByIdRecursive(ctx, base, elementBuilder, nodeId, childNode);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return foundNode;
}
PROMOTED_ENTRY(86, sub_82BAC9F8, 0x82BAC9F8) { ctx.r3.u64 = CAKElementBuilder_FindNodeByIdRecursive(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

// sub_82BACA60  [8 bytes]
// Virtual method: the builder (r3) is not used; it stores the 32-bit field at +8 of the node passed in r4.
void n_sub_82BACA60(CpuState& ctx, uint8_t* base, uint32_t node, uint32_t value) {
	if (!UseLiftedCode(86, 0x82BACA60)) { ctx.r4.u64 = node; ctx.r5.u64 = value; __imp__sub_82BACA60(ctx, base); return; }
	LiftedFrame frame(0x82BACA60);
	STORE32(node + 8, value);
}
PROMOTED_ENTRY(86, sub_82BACA60, 0x82BACA60) { n_sub_82BACA60(ctx, base, ctx.r4.u32, ctx.r5.u32); }

// sub_82BACA68  [8 bytes]
// Virtual method: the builder (r3) is not used; it reads the byte at +0x1E of the node passed in r4.
uint64_t n_sub_82BACA68(CpuState& ctx, uint8_t* base, uint32_t node) {
	if (!UseLiftedCode(86, 0x82BACA68)) { ctx.r4.u64 = node; __imp__sub_82BACA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BACA68);
	return LOAD8(node + 0x1E);
}
PROMOTED_ENTRY(86, sub_82BACA68, 0x82BACA68) { ctx.r3.u64 = n_sub_82BACA68(ctx, base, ctx.r4.u32); }

// sub_82BACA70  [8 bytes]
// Virtual method: the builder (r3) is not used; it stores the byte at +0x1E of the node passed in r4.
void n_sub_82BACA70(CpuState& ctx, uint8_t* base, uint32_t node, uint32_t value) {
	if (!UseLiftedCode(86, 0x82BACA70)) { ctx.r4.u64 = node; ctx.r5.u64 = value; __imp__sub_82BACA70(ctx, base); return; }
	LiftedFrame frame(0x82BACA70);
	STORE8(node + 0x1E, (uint8_t)value);
}
PROMOTED_ENTRY(86, sub_82BACA70, 0x82BACA70) { n_sub_82BACA70(ctx, base, ctx.r4.u32, ctx.r5.u32); }

// sub_82BACB20  [92 bytes]
// Calls sub_82BAF110 on the member at +0x18 with the node, then virtual slot 0x50 with (node, 0x40, 1); in
// the CAKElementBuilder vtable that slot is sub_82284750, which sets those bits in the node flags at +0x1C.
uint64_t n_sub_82BACB20(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint64_t node, uint32_t arg3, uint32_t arg4) {
	if (!UseLiftedCode(86, 0x82BACB20)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = node; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_82BACB20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BACB20);
	uint32_t stack = ctx.r1.u64;
	CAKElementBuilder* aKElementBuilder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_82BAF110(ctx, base, aKElementBuilderAddr + 24, node, arg3, arg4);

	uint32_t setFlagsFn = LOAD32(uint32_t(aKElementBuilder->vtable) + 80);
	ctx.r3.u64 = aKElementBuilderAddr;
	ctx.r4.u64 = node;
	ctx.r5.u64 = 0x40;
	ctx.r6.u64 = 1;
	ctx.r10.u64 = setFlagsFn;
	REX_CALL_INDIRECT_FUNC(setFlagsFn);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BACB20, 0x82BACB20) { ctx.r3.u64 = n_sub_82BACB20(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32); }

// sub_82BACB80  [100 bytes]
// Calls sub_82BAF318 on the member at +0x18 with the node and the address of a byte it may set; if the byte is
// set, calls virtual slot 0x50 with (node, 0x40, 0); in the CAKElementBuilder vtable that slot is sub_82284750,
// which clears those bits in the node flags at +0x1C. Returns what sub_82BAF318 returned.
uint64_t n_sub_82BACB80(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint64_t node, uint32_t arg3, uint32_t arg4) {
	if (!UseLiftedCode(86, 0x82BACB80)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = node; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_82BACB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BACB80);
	uint32_t stack = ctx.r1.u64;
	CAKElementBuilder* aKElementBuilder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);

	stack = PushStackFrame(base, stack, 128);
	uint32_t outFlagAddr = stack + 80;
	STORE8(outFlagAddr, uint8_t(0));

	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82BAF318(ctx, base, aKElementBuilderAddr + 24, node, arg3, arg4, outFlagAddr);

	uint8_t outFlag = LOAD8(outFlagAddr);
	if (outFlag != 0) {
		uint32_t setFlagsFn = LOAD32(uint32_t(aKElementBuilder->vtable) + 80);
		ctx.r3.u64 = aKElementBuilderAddr;
		ctx.r4.u64 = node;
		ctx.r5.u64 = 0x40;
		ctx.r6.u64 = 0;
		ctx.r9.u64 = outFlag;  // state the callee may pass on
		ctx.r10.u64 = setFlagsFn;
		REX_CALL_INDIRECT_FUNC(setFlagsFn);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(86, sub_82BACB80, 0x82BACB80) { ctx.r3.u64 = n_sub_82BACB80(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32); }

uint64_t n_sub_82BACC90(CpuState& ctx, uint8_t* base, uint32_t aKElementBuilderAddr, uint32_t searchValue, uint32_t startNode) {
	if (!UseLiftedCode(86, 0x82BACC90)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = searchValue; ctx.r5.u64 = startNode; __imp__sub_82BACC90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BACC90);
	CAKElementBuilder* builder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);
	uint32_t node = startNode;
	if (node == 0) {
		node = builder->m_pRoot;
		if (LOAD32(node) == searchValue) return node;
	}
	for (uint32_t child = LOAD32(node + 20); child != 0; child = LOAD32(child + 16)) {
		if (LOAD32(child) == searchValue) return child;
	}
	return 0;
}
PROMOTED_ENTRY(86, sub_82BACC90, 0x82BACC90) { ctx.r3.u64 = n_sub_82BACC90(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32); }

// sub_82BACCE0  [124 bytes]
// Appends to the pointer array outNodes (sub_82284810) every child of parentNode (first child at +0x14, next
// sibling at +0x10) for which virtual slot 4 returns a nonzero low byte, or every child when the low byte of
// includeAll is set. In the CAKElementBuilder vtable slot 4 is CAKElementBuilder_IsFlag12Set.
uint64_t n_sub_82BACCE0(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint64_t parentNode, uint64_t outNodes, uint64_t includeAll) {
	if (!UseLiftedCode(86, 0x82BACCE0)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = parentNode; ctx.r5.u64 = outNodes; ctx.r6.u64 = includeAll; __imp__sub_82BACCE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BACCE0);
	CAKElementBuilder* builder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// register values handed to each call and taken back from it; r4 also goes back to callers
	uint64_t r4Value = parentNode;
	uint64_t r5Value = outNodes;
	uint64_t r6Value = includeAll;
	uint64_t r9Value = ctx.r9.u64;
	uint64_t result = aKElementBuilderAddr;

	// the current child is kept in a stack slot: sub_82284810 takes the address of the value it appends
	uint32_t child = LOAD32((uint32_t)parentNode + 0x14);
	STORE32(stack + 0x50, child);
	while (child != 0) {
		uint32_t isFlag12SetFn = LOAD32(uint32_t(builder->vtable) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = aKElementBuilderAddr;
		ctx.r4.u64 = child;
		ctx.r5.u64 = r5Value;
		ctx.r6.u64 = r6Value;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = isFlag12SetFn;
		REX_CALL_INDIRECT_FUNC(isFlag12SetFn);
		result = ctx.r3.u64;
		r4Value = ctx.r4.u64;
		r5Value = ctx.r5.u64;
		r6Value = ctx.r6.u64;
		r9Value = result & 0xFF;
		if (r9Value != 0 || (includeAll & 0xFF) != 0) {
			ctx.r9.u64 = r9Value;
			result = n_sub_82284810(ctx, base, outNodes, stack + 0x50);
			r4Value = ctx.r4.u64;
			r5Value = ctx.r5.u64;
			r6Value = ctx.r6.u64;
			r9Value = ctx.r9.u64;
		}
		child = LOAD32(child + 0x10);
		STORE32(stack + 0x50, child);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(86, sub_82BACCE0, 0x82BACCE0) { ctx.r3.u64 = n_sub_82BACCE0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_82BACD60  [52 bytes]
// Whether ancestor is reached by following the parent links (+0xC) up from node: 0 for a null node, 1 when the
// parent is ancestor, otherwise virtual slot 0x60 on the parent, which in the CAKElementBuilder vtable is this
// function again.
uint64_t n_sub_82BACD60(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint64_t ancestor, uint64_t node) {
	if (!UseLiftedCode(86, 0x82BACD60)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = ancestor; ctx.r5.u64 = node; __imp__sub_82BACD60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BACD60);
	CAKElementBuilder* aKElementBuilder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);

	if ((uint32_t)node == 0) {
		ctx.r4.u64 = ancestor;  // callers read r4 after the call
		return 0;
	}
	uint32_t parent = LOAD32((uint32_t)node + 0xC);
	if (parent == (uint32_t)ancestor) {
		ctx.r4.u64 = ancestor;  // callers read r4 after the call
		return 1;
	}

	uint32_t isAncestorFn = LOAD32(uint32_t(aKElementBuilder->vtable) + 0x60);
	ctx.r3.u64 = aKElementBuilderAddr;
	ctx.r4.u64 = ancestor;
	ctx.r5.u64 = parent;
	ctx.r10.u64 = isAncestorFn;
	REX_CALL_INDIRECT_FUNC(isAncestorFn);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BACD60, 0x82BACD60) { ctx.r3.u64 = n_sub_82BACD60(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CAKElementBuilder_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(86, 0x82BACE60)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82BACE60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BACE60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;  // state the callee may pass on
	CAKElementBuilder_Destruct(ctx, base, aKElementBuilderAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, aKElementBuilderAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return aKElementBuilderAddr;
}
PROMOTED_ENTRY(86, sub_82BACE60, 0x82BACE60) { ctx.r3.u64 = CAKElementBuilder_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CAKElementBuilder_Destruct(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_820065E0 = int32_t(0x820065E0);
	if (!UseLiftedCode(86, 0x82BACF08)) { ctx.r3.u64 = aKElementBuilderAddr; __imp__sub_82BACF08(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BACF08);
	uint32_t stack = ctx.r1.u64;
	CAKElementBuilder* aKElementBuilder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);

	stack = PushStackFrame(base, stack, 128);

	// the destructor starts by re-pointing the vtable pointers at +0 and +0x4C
	const uint64_t primaryVtable = g_820065E0;
	const int32_t secondaryVtableBase = g_82000000;
	aKElementBuilder->vtable = (uint32_t)primaryVtable;
	aKElementBuilder->m_4C = (uint32_t)((int64_t)secondaryVtableBase + 12488);

	const uint32_t root = aKElementBuilder->m_pRoot;
	const uint64_t rootSize =
	    (uint64_t)((uint32_t)((uint64_t)(aKElementBuilder->m_58 << 2) + (uint64_t)aKElementBuilder->m_60) << 3)
	    + (uint64_t)aKElementBuilder->m_5C * 68;

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = aKElementBuilderAddr;
	ctx.r7.u64 = primaryVtable;
	ctx.r8.s64 = secondaryVtableBase;
	const uint64_t allocator = Allocator_GetInstance(ctx, base);
	n_sub_82BA9068(ctx, base, allocator, root, rootSize);

	// release the blocks chained on m_48 (+0: next block, +4: block size). r3 at each Allocator_GetInstance
	// is the chain head the first time, then what the previous release returned.
	uint64_t r3Value = aKElementBuilder->m_48;
	if ((uint32_t)r3Value != 0) {
		uint32_t nextBlock;
		do {
			const uint32_t block = aKElementBuilder->m_48;
			nextBlock = LOAD32(block);
			const uint32_t blockSize = LOAD32(block + 4);
			ctx.r3.u64 = r3Value;
			const uint64_t blockAllocator = Allocator_GetInstance(ctx, base);
			r3Value = n_sub_82BA9068(ctx, base, blockAllocator, block, blockSize);
			aKElementBuilder->m_48 = nextBlock;
		} while (nextBlock != 0);
	}

	const uint32_t result = n_sub_82BACEB0(ctx, base, aKElementBuilderAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(86, sub_82BACF08, 0x82BACF08) { ctx.r3.u64 = CAKElementBuilder_Destruct(ctx, base, ctx.r3.u64); }

// Copies the elements of sourceList (pointer array at +32, count at +40): each copy lives at +8 of a block
// from the allocator (+0: next block, +4: block size) and the blocks are chained onto m_48. The links of the
// copies at +12, +16 and +20 are then redirected from the originals to the copies (destList's array at +32),
// and the first copy is appended to the +20/+16 chain of parentElement, or of the first original's +12.
uint64_t n_sub_82BAD1D8(CpuState& ctx, uint8_t* base, uint64_t aKElementBuilderAddr, uint32_t sourceList, uint64_t destList, uint32_t firstWordOverride, uint64_t parentElement) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820FCEC0_B_ = int32_t(0x820FCEC0);
	constexpr int32_t str_TXT_820FCF40_B_ = int32_t(0x820FCF40);
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	if (!UseLiftedCode(86, 0x82BAD1D8)) { ctx.r3.u64 = aKElementBuilderAddr; ctx.r4.u64 = sourceList; ctx.r5.u64 = destList; ctx.r6.u64 = firstWordOverride; ctx.r7.u64 = parentElement; __imp__sub_82BAD1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAD1D8);
	PPCRegister callTarget{};
	PPCXERRegister flags = ctx.xer;
	uint32_t stack = ctx.r1.u64;
	CAKElementBuilder* elementBuilder = GameObject<CAKElementBuilder>(base, aKElementBuilderAddr);
	stack = PushStackFrame(base, stack, 272);

	// stack + 96: a local list of the copies' byte sizes (array at stack + 128, capacity at + 132, count at + 136);
	// stack + 80: the value slot handed to the list calls by address
	const uint64_t sizeList = (uint64_t)stack + 96;
	const uint32_t valueSlot = stack + 80;
	const uint32_t elementCount = LOAD32(sourceList + 40);

	ctx.fpscr.disableFlushMode();
	const double initialF1 = double(LOAD_F32(0x8209BF2Cu));
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.f1.f64 = initialF1;
	// r3/r4/r7/r8 as the original leaves them; later calls receive them
	uint64_t r3Value = n_sub_82BAE2E8(ctx, base, sizeList, elementCount, parentElement);
	uint64_t r4Value = ctx.r4.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	flags.ca = ctx.xer.ca;

	// size of each copy: 32 bytes, 8 per unit of the byte at +31, and 36 more when vfunc 76 returns true
	uint32_t elementPtr = LOAD32(sourceList + 32);
	uint64_t elementsEnd = (uint64_t)(LOAD32(sourceList + 40) << 2) + elementPtr;
	while (elementPtr != (uint32_t)elementsEnd) {
		const uint32_t element = LOAD32(elementPtr);
		const uint32_t method76 = LOAD32((uint32_t)elementBuilder->vtable + 76);
		callTarget.u64 = method76;
		ctx.r3.u64 = aKElementBuilderAddr;
		ctx.r4.u64 = element;
		ctx.r5.u64 = 1;
		ctx.r9.u64 = elementsEnd;
		ctx.r10.u64 = method76;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		const uint32_t addsExtra = ctx.r3.u32 & 0xFF;
		const uint32_t elementAfterCall = LOAD32(elementPtr);
		flags.ca = addsExtra == 0;
		STORE32(valueSlot, (addsExtra != 0 ? 36u : 0u) + 32u + (uint32_t)LOAD8(elementAfterCall + 31) * 8u);
		// state the callee may pass on
		ctx.r7.u64 = 0 - (uint64_t)addsExtra;
		ctx.r8.u64 = elementAfterCall;
		ctx.xer.ca = flags.ca;
		r3Value = n_sub_82BAE368(ctx, base, sizeList, valueSlot);
		r4Value = ctx.r4.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		flags.ca = ctx.xer.ca;
		elementPtr += 4;
		elementsEnd = (uint64_t)(LOAD32(sourceList + 40) << 2) + (uint64_t)LOAD32(sourceList + 32);
	}

	uint64_t lastBlock = 0;
	uint32_t firstBlock = 0;
	if ((int32_t)elementCount > 0) {
		// debug type name and source file recorded with each allocation (the original passes the file sign-extended)
		const uint32_t allocTypeName = (uint32_t)str_TXT_820FCF40_B_;
		const uint64_t allocSourceFile = str_TXT_820FCEC0_B_;
		uint32_t offset = 0;
		uint32_t remaining = elementCount;
		do {
			const uint32_t copySize = LOAD32(LOAD32(stack + 128) + offset);
			// state the callee may pass on
			ctx.r3.u64 = r3Value;
			ctx.xer.ca = flags.ca;
			const uint64_t allocator = Allocator_GetInstance(ctx, base);
			uint64_t block;
			if ((uint32_t)lastBlock != 0) {
				block = n_sub_82BA8F18(ctx, base, allocator, (uint64_t)copySize + 8, allocTypeName, allocSourceFile, 279);
				STORE32((uint32_t)lastBlock, (uint32_t)block);
			} else {
				block = n_sub_82BA8F18(ctx, base, allocator, (uint64_t)copySize + 8, allocTypeName, allocSourceFile, 284);
				firstBlock = (uint32_t)block;
			}
			lastBlock = block;

			const uint64_t copy = lastBlock + 8;
			const uint32_t sizeArray = LOAD32(stack + 128);
			STORE32(valueSlot, (uint32_t)copy);
			const uint32_t blockSize = LOAD32(sizeArray + offset) + 8;
			STORE32((uint32_t)lastBlock, 0);
			STORE32((uint32_t)lastBlock + 4, blockSize);

			const uint32_t sizeArrayAgain = LOAD32(stack + 128);
			const uint32_t byteCount = LOAD32(sizeArrayAgain + offset);
			const uint32_t original = LOAD32(LOAD32(sourceList + 32) + offset);
			ctx.r8.u64 = sizeArrayAgain;  // state the callee may pass on
			memcpy(ctx, base, copy, original, byteCount);

			const uint32_t vtable = (uint32_t)elementBuilder->vtable;
			callTarget.u64 = LOAD32(vtable + 80);
			ctx.r3.u64 = aKElementBuilderAddr;
			ctx.r4.u64 = copy;
			ctx.r5.u64 = 4;
			ctx.r6.u64 = 1;
			ctx.r7.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			n_sub_82BAD5B0(ctx, base, aKElementBuilderAddr, copy);
			r3Value = n_sub_82284810(ctx, base, destList, valueSlot);
			r4Value = ctx.r4.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
			flags.ca = remaining > 0;  // carry of the counter's decrement
			remaining -= 1;
			offset += 4;
		} while ((int32_t)remaining != 0);
	}

	uint32_t tailBlock = elementBuilder->m_48;
	if (tailBlock != 0) {
		while (LOAD32(tailBlock) != 0) {
			tailBlock = LOAD32(tailBlock);
		}
		STORE32(tailBlock, firstBlock);
	} else {
		elementBuilder->m_48 = firstBlock;
	}

	// redirect the copies' links: r7 holds the outer byte offset and r8 the inner countdown, as in the original
	const uint32_t copyCount = LOAD32(sourceList + 40);
	if ((int32_t)copyCount > 0) {
		r7Value = 0;
		uint32_t outerRemaining = copyCount;
		do {
			const uint32_t destArray = LOAD32((uint32_t)destList + 32);
			uint32_t innerOffset = 0;
			r8Value = copyCount;
			const uint32_t copyElement = LOAD32((uint32_t)r7Value + destArray);
			do {
				const uint32_t original = LOAD32(LOAD32(sourceList + 32) + innerOffset);
				if (LOAD32(copyElement + 12) == original) {
					r4Value = LOAD32(innerOffset + LOAD32((uint32_t)destList + 32));
					STORE32(copyElement + 12, (uint32_t)r4Value);
				} else if (LOAD32(copyElement + 20) == original) {
					r4Value = LOAD32(innerOffset + LOAD32((uint32_t)destList + 32));
					STORE32(copyElement + 20, (uint32_t)r4Value);
				} else {
					r4Value = LOAD32(copyElement + 16);
					if ((uint32_t)r4Value == original) {
						r4Value = LOAD32(innerOffset + LOAD32((uint32_t)destList + 32));
						STORE32(copyElement + 16, (uint32_t)r4Value);
					}
				}
				r8Value -= 1;
				innerOffset += 4;
			} while ((int32_t)r8Value != 0);
			flags.ca = outerRemaining > 0;  // carry of the counter's decrement
			outerRemaining -= 1;
			r7Value += 4;
		} while ((int32_t)outerRemaining != 0);
	}

	const uint32_t firstCopy = LOAD32(LOAD32((uint32_t)destList + 32));
	uint32_t parent;
	if ((uint32_t)parentElement != 0) {
		parent = (uint32_t)parentElement;
	} else {
		parent = LOAD32(LOAD32(LOAD32(sourceList + 32)) + 12);
	}
	if (parent != 0) {
		STORE32(firstCopy + 12, parent);
		uint32_t child = LOAD32(parent + 20);
		if (child == 0) {
			STORE32(parent + 20, firstCopy);
		} else {
			uint32_t lastChild;
			do {
				lastChild = child;
				child = LOAD32(child + 16);
			} while (child != 0);
			STORE32(lastChild + 16, firstCopy);
		}
	}
	STORE32(firstCopy + 16, 0);
	if (firstWordOverride != 0) {
		STORE32(firstCopy, firstWordOverride);
	}

	if ((int32_t)elementCount > 0) {
		const uint64_t fallbackValue = g_82000C98;  // sign-extended, as the original passes it
		uint32_t offset = 0;
		uint32_t remaining = elementCount;
		do {
			const uint32_t copyElement = LOAD32(offset + LOAD32((uint32_t)destList + 32));
			if (LOAD8(copyElement + 30) == 8) {
				r4Value = LOAD32((uint32_t)g_834C0000 - 7424);
				// state the callee may pass on
				ctx.r7.u64 = r7Value;
				ctx.r8.u64 = r8Value;
				ctx.xer.ca = flags.ca;
				r3Value = CAKElementBuilder_FindByKey(ctx, base, copyElement, (uint32_t)r4Value);
				r7Value = ctx.r7.u64;
				r8Value = ctx.r8.u64;
				const uint32_t found = (uint32_t)r3Value;
				if (found != 0) {
					const uint32_t m4Object = elementBuilder->m_4;
					const uint32_t m4Method20 = LOAD32(LOAD32(m4Object) + 20);
					callTarget.u64 = m4Method20;
					ctx.r3.u64 = m4Object;
					ctx.r4.u64 = r4Value;
					ctx.r10.u64 = m4Method20;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					const uint32_t objectForKey = ctx.r3.u32;

					uint64_t value = LOAD32(LOAD32(found + 4));
					if ((uint32_t)value == 0) {
						value = fallbackValue;
					}
					const uint32_t objectForKeyVtable = LOAD32(objectForKey);
					const uint32_t method8 = LOAD32(objectForKeyVtable + 8);
					callTarget.u64 = method8;
					ctx.r4.u64 = copyElement;
					ctx.r5.u64 = value;
					ctx.r9.u64 = method8;
					ctx.r10.u64 = objectForKeyVtable;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);

					const uint32_t m4ObjectAgain = elementBuilder->m_4;
					const uint32_t m4Vtable = LOAD32(m4ObjectAgain);
					const uint32_t m4Method20Again = LOAD32(m4Vtable + 20);
					callTarget.u64 = m4Method20Again;
					ctx.r3.u64 = m4ObjectAgain;
					ctx.r7.u64 = m4Method20Again;
					ctx.r8.u64 = m4Vtable;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					const uint32_t secondObject = ctx.r3.u32;

					const uint32_t secondObjectVtable = LOAD32(secondObject);
					callTarget.u64 = LOAD32(secondObjectVtable + 16);
					ctx.r4.u64 = aKElementBuilderAddr;
					ctx.r5.u64 = copyElement;
					ctx.r6.u64 = secondObjectVtable;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					r3Value = ctx.r3.u64;
					r4Value = ctx.r4.u64;
					r7Value = ctx.r7.u64;
					r8Value = ctx.r8.u64;
				}
			}
			flags.ca = remaining > 0;  // carry of the counter's decrement
			remaining -= 1;
			offset += 4;
		} while ((int32_t)remaining != 0);
	}

	// empty the size list and release its array
	STORE32(stack + 136, 0);
	const uint32_t sizeCapacity = LOAD32(stack + 132);
	const uint32_t sizeArray = LOAD32(stack + 128);
	// state the callee may pass on
	ctx.r3.u64 = r3Value;
	ctx.r4.u64 = r4Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.xer.ca = flags.ca;
	const uint64_t allocator = Allocator_GetInstance(ctx, base);
	const uint64_t result = n_sub_82BA9068(ctx, base, allocator, sizeArray, sizeCapacity << 2);
	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(86, sub_82BAD1D8, 0x82BAD1D8) { ctx.r3.u64 = n_sub_82BAD1D8(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64, ctx.r6.u32, ctx.r7.u64); }
