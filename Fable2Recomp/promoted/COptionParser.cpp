// COptionParser (vtable 0x8200E8E0): methods of the class as readable C++.
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

void n_sub_82C84108(CpuState& ctx, uint8_t* base, uint32_t optionParserAddr, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C84108)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = outValue; __imp__sub_82C84108(ctx, base); return; }
	LiftedFrame frame(0x82C84108);
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	uint32_t currentNode = optionParser->m_currentNode;
	if (LOAD32(currentNode) != 3) return;
	STORE32(outValue, LOAD32(currentNode + 0x20));
}
PROMOTED_ENTRY(93, sub_82C84108, 0x82C84108) { n_sub_82C84108(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_82C84128  [28 bytes]
void n_sub_82C84128(CpuState& ctx, uint8_t* base, uint32_t optionParserAddr, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C84128)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = outValue; __imp__sub_82C84128(ctx, base); return; }
	LiftedFrame frame(0x82C84128);
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	uint32_t currentNode = optionParser->m_currentNode;
	if (LOAD32(currentNode) != 2) return;
	STORE32(outValue, LOAD32(currentNode + 0x20));
}
PROMOTED_ENTRY(93, sub_82C84128, 0x82C84128) { n_sub_82C84128(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_82C84148  [28 bytes]
void COptionParser_GetBoolValue(CpuState& ctx, uint8_t* base, uint32_t optionParserAddr, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C84148)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = outValue; __imp__sub_82C84148(ctx, base); return; }
	LiftedFrame frame(0x82C84148);
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	uint32_t currentNode = optionParser->m_currentNode;
	if (LOAD32(currentNode) != 5) return;
	STORE8(outValue, LOAD8(currentNode + 0x20));
}
PROMOTED_ENTRY(93, sub_82C84148, 0x82C84148) { COptionParser_GetBoolValue(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void COptionParser_GetFloatValue(CpuState& ctx, uint8_t* base, uint32_t optionParserAddr, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C84168)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = outValue; __imp__sub_82C84168(ctx, base); return; }
	LiftedFrame frame(0x82C84168);
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	uint32_t currentNode = optionParser->m_currentNode;
	if (LOAD32(currentNode) != 4) return;
	// FPU mode switch the lifted code makes before the float copy; it stays set for callers
	ctx.fpscr.disableFlushMode();
	STORE_F32(outValue, LOAD_F32(currentNode + 0x20));
}
PROMOTED_ENTRY(93, sub_82C84168, 0x82C84168) { COptionParser_GetFloatValue(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t COptionParser_GetStringValue(CpuState& ctx, uint8_t* base, uint64_t optionParserAddr, uint64_t outString) {
	if (!UseLiftedCode(93, 0x82C843A0)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = outString; __imp__sub_82C843A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C843A0);
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	uint32_t currentNode = optionParser->m_currentNode;
	if (LOAD32(currentNode) != 1) {
		ctx.r4.u64 = outString;	// callers read r4 after the call
		return optionParserAddr;
	}
	// The node's string object starts at +4: its text sits inline at +8 while the capacity
	// at +0x1C is below 16, otherwise +8 holds a pointer to the text.
	uint32_t capacity = LOAD32(currentNode + 0x1C);
	uint64_t text = capacity >= 16 ? (uint64_t)LOAD32(currentNode + 8) : (uint64_t)currentNode + 8;
	// state the callee may pass on
	ctx.r9.u64 = capacity;
	ctx.r10.u64 = outString;
	return n_sub_82C825A0(ctx, base, outString, text);
}
PROMOTED_ENTRY(93, sub_82C843A0, 0x82C843A0) { ctx.r3.u64 = COptionParser_GetStringValue(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t COptionParser_FindNodeByName(CpuState& ctx, uint8_t* base, uint32_t optionParserAddr, uint64_t nodeName) {
	if (!UseLiftedCode(93, 0x82C84540)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = nodeName; __imp__sub_82C84540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C84540);
	uint32_t stack = ctx.r1.u64;
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	stack = PushStackFrame(base, stack, 128);
	// Handed back in r8 when no node matches: the list's first node once the loop has run.
	uint64_t firstNode = ctx.r8.u64;

	if (LOAD32(optionParserAddr + 8) != 0) {
		uint32_t nodeList = optionParser->m_nodeList;
		if (nodeList != 0) {
			// Nodes are 64 bytes apart. The traps are the original's bounds and same-list checks;
			// boundsEnd is the end used by the bounds checks, re-read only after a node did not match.
			uint64_t currentNode = LOAD32(nodeList + 4);
			uint32_t boundsEnd = LOAD32(nodeList + 8);
			if ((uint32_t)currentNode > boundsEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			for (;;) {
				uint32_t list = optionParser->m_nodeList;
				uint32_t listEnd = LOAD32(list + 8);
				firstNode = LOAD32(list + 4);
				if ((uint32_t)firstNode > listEnd) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				if (nodeList != list) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				if ((uint32_t)currentNode == listEnd) break;
				if ((uint32_t)currentNode >= boundsEnd) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				ctx.r1.u64 = stack;
				uint32_t matches = n_sub_82C843E0(ctx, base, currentNode, nodeName, firstNode);
				if ((matches & 0xFF) == 0) {
					boundsEnd = LOAD32(nodeList + 8);
					if ((uint32_t)currentNode >= boundsEnd) ppc_trap(ctx, base, 22);
					currentNode += 64;
					continue;
				}
				if ((uint32_t)currentNode >= LOAD32(nodeList + 8)) ppc_trap(ctx, base, 22);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return currentNode;
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = firstNode;	// callers read r8 after the call
	return 0;
}
PROMOTED_ENTRY(93, sub_82C84540, 0x82C84540) { ctx.r3.u64 = COptionParser_FindNodeByName(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t n_sub_82C84610(CpuState& ctx, uint8_t* base, uint32_t optionParser, uint64_t nodeName, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C84610)) { ctx.r3.u64 = optionParser; ctx.r4.u64 = nodeName; ctx.r5.u64 = outValue; __imp__sub_82C84610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C84610);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t node = COptionParser_FindNodeByName(ctx, base, optionParser, nodeName);

	if (node != 0 && int32_t(LOAD32(node + 28)) == 3) {
		uint32_t value = LOAD32(node + 60);
		STORE32(outValue, value);
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C84610, 0x82C84610) { ctx.r3.u64 = n_sub_82C84610(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint64_t n_sub_82C84678(CpuState& ctx, uint8_t* base, uint32_t optionParserAddr, uint64_t nodeName, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C84678)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = nodeName; ctx.r5.u64 = outValue; __imp__sub_82C84678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C84678);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t node = COptionParser_FindNodeByName(ctx, base, optionParserAddr, nodeName);
	uint64_t hasValue = 0;
	if (node != 0 && LOAD32(node + 0x1C) == 2) {
		STORE32(outValue, LOAD32(node + 0x3C));
		hasValue = 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return hasValue;
}
PROMOTED_ENTRY(93, sub_82C84678, 0x82C84678) { ctx.r3.u64 = n_sub_82C84678(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

// sub_82C846E0  [100 bytes]
uint64_t COptionParser_GetBoolByName(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t optionName, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C846E0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = optionName; ctx.r5.u64 = outValue; __imp__sub_82C846E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C846E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t nodeByName = COptionParser_FindNodeByName(ctx, base, arg1, optionName);
	if (nodeByName != 0 && int32_t(LOAD32(nodeByName + 0x1C)) == 5) {
		uint8_t boolValue = LOAD8(nodeByName + 0x3C);
		STORE8(outValue, boolValue);
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C846E0, 0x82C846E0) { ctx.r3.u64 = COptionParser_GetBoolByName(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint64_t COptionParser_GetFloatByName(CpuState& ctx, uint8_t* base, uint32_t arg1, uint64_t optionName, uint32_t outValue) {
	if (!UseLiftedCode(93, 0x82C84748)) { ctx.r3.u64 = arg1; ctx.r4.u64 = optionName; ctx.r5.u64 = outValue; __imp__sub_82C84748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C84748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t node = COptionParser_FindNodeByName(ctx, base, arg1, optionName);

	if (node != 0 && LOAD32(node + 0x1C) == 4) {
		// the lifted float hand-off widens to double with host flushing off
		ctx.fpscr.disableFlushMode();
		double value = double(LOAD_F32(node + 0x3C));
		STORE_F32(outValue, float(value));
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C84748, 0x82C84748) { ctx.r3.u64 = COptionParser_GetFloatByName(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint64_t COptionParser_GetStringByName(CpuState& ctx, uint8_t* base, uint64_t optionParser, uint64_t optionName, uint64_t outString) {
	if (!UseLiftedCode(93, 0x82C847B0)) { ctx.r3.u64 = optionParser; ctx.r4.u64 = optionName; ctx.r5.u64 = outString; __imp__sub_82C847B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C847B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t node = (uint32_t)COptionParser_FindNodeByName(ctx, base, optionParser, optionName);
	// Only option nodes tagged with type 1 carry a string value.
	if (node == 0 || (int32_t)LOAD32(node + 0x1C) != 1) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return 0;
	}

	uint32_t value = node + 0x20;
	uint32_t length = LOAD32(value + 0x18);
	uint64_t stringData = (length >= 16)
		? (uint64_t)LOAD32(value + 0x04)   // long string: buffer held behind a pointer
		: (uint64_t)(value + 0x04);        // short string: buffer stored inline

	n_sub_82C825A0(ctx, base, outString, stringData);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C847B0, 0x82C847B0) { ctx.r3.u64 = COptionParser_GetStringByName(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t COptionParser_Dtor(CpuState& ctx, uint8_t* base, uint64_t optionParserAddr) {
	if (!UseLiftedCode(93, 0x82C84DF8)) { ctx.r3.u64 = optionParserAddr; __imp__sub_82C84DF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C84DF8);
	uint32_t stack = ctx.r1.u64;
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	stack = PushStackFrame(base, stack, 144);
	uint32_t obj = (uint32_t)optionParserAddr;
	const uint32_t kSmallCapacity = 15;

	optionParser->vtable = 0x8200E8E0u;

	// destroy the string-array member (pointer at +0x94, length at +0x98)
	uint32_t stringArray = optionParser->m_94;
	if (stringArray != 0) {
		ctx.r1.u64 = stack;
		StringArray_Destruct(ctx, base, stringArray, LOAD32(obj + 152));
		HandleTarget_FreeThunk(ctx, base, LOAD32(obj + 148));
	}

	// clear the vector member at +144
	STORE32(obj + 156, 0);
	STORE32(obj + 148, 0);
	STORE32(obj + 152, 0);

	// string member at +112
	if (LOAD32(obj + 136) >= 16) {
		ctx.r1.u64 = stack;
		HandleTarget_FreeThunk(ctx, base, LOAD32(obj + 116));
	}
	STORE32(obj + 132, 0);
	STORE32(obj + 136, kSmallCapacity);
	STORE8(obj + 116, 0);

	// string member at +80
	if (LOAD32(obj + 104) >= 16) {
		ctx.r1.u64 = stack;
		HandleTarget_FreeThunk(ctx, base, LOAD32(obj + 84));
	}
	STORE32(obj + 104, kSmallCapacity);
	STORE32(obj + 100, 0);
	STORE8(obj + 84, 0);

	// string member at +52
	if (LOAD32(obj + 76) >= 16) {
		ctx.r1.u64 = stack;
		HandleTarget_FreeThunk(ctx, base, LOAD32(obj + 56));
	}
	STORE32(obj + 76, kSmallCapacity);
	STORE32(obj + 72, 0);
	STORE8(obj + 56, 0);

	ctx.r1.u64 = stack;
	n_sub_8235E680(ctx, base, obj + 20);

	// release the option object owned by the parser
	uint32_t option = optionParser->m_C;
	if (option != 0) {
		PPCRegister callTarget{};
		callTarget.u64 = LOAD32(LOAD32(option) + 8);
		ctx.r3.u64 = option;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	uint32_t result = n_sub_82C81BF8(ctx, base, optionParserAddr);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C84DF8, 0x82C84DF8) { ctx.r3.u64 = COptionParser_Dtor(ctx, base, ctx.r3.u64); }

uint64_t COptionParser_DeletingDtor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(93, 0x82C85338)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C85338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C85338);
	uint32_t stack = ctx.r1.u64;
	uint32_t deleteFlags;

	stack = PushStackFrame(base, stack, 112);
	deleteFlags = arg2;
	ctx.r1.u64 = stack;
	COptionParser_Dtor(ctx, base, arg1);

	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, arg1);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return arg1;
}
PROMOTED_ENTRY(93, sub_82C85338, 0x82C85338) { ctx.r3.u64 = COptionParser_DeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82C85658(CpuState& ctx, uint8_t* base, uint64_t optionParserAddr, uint64_t arg2) {
	if (!UseLiftedCode(93, 0x82C85658)) { ctx.r3.u64 = optionParserAddr; ctx.r8.u64 = arg2; __imp__sub_82C85658(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C85658);
	uint32_t stack = ctx.r1.u64;
	uint32_t parserAddr = (uint32_t)optionParserAddr;
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	uint32_t entryAddr = parserAddr + 12;
	uint32_t result;
	stack = PushStackFrame(base, stack, 112);
	if (LOAD32(parserAddr + 32) == 2) {
		if (LOAD8(parserAddr + 16) != 0) {
			ctx.r1.u64 = stack;
			uint32_t flag = n_sub_82C85538(ctx, base, parserAddr + 108, entryAddr, arg2);
			arg2 = ctx.r8.u64;
			STORE8(parserAddr + 16, (uint8_t)flag);
		}
		uint64_t workBufferAddr = (uint64_t)stack + 80;
		ctx.r1.u64 = stack;
		ctx.r8.u64 = arg2;
		uint32_t value = n_sub_82C84838(ctx, base, workBufferAddr, entryAddr);
		arg2 = ctx.r8.u64;
		optionParser->m_20 = LOAD32(value);
		result = parserAddr + 108;
	} else {
		result = 0;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = arg2;
	return result;
}
PROMOTED_ENTRY(93, sub_82C85658, 0x82C85658) { ctx.r3.u64 = n_sub_82C85658(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_82C856D8(CpuState& ctx, uint8_t* base, uint64_t optionParserAddr, uint64_t arg2) {
	if (!UseLiftedCode(93, 0x82C856D8)) { ctx.r3.u64 = optionParserAddr; ctx.r8.u64 = arg2; __imp__sub_82C856D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C856D8);
	uint32_t stack = ctx.r1.u64;
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);

	stack = PushStackFrame(base, stack, 112);

	uint64_t result;
	if (LOAD32((uint32_t)optionParserAddr + 32) != 0) {
		result = 0;
	} else {
		uint64_t entry = optionParserAddr + 12;
		if (LOAD8((uint32_t)optionParserAddr + 16) != 0) {
			ctx.r1.u64 = stack;
			uint32_t parsed = n_sub_82C85250(ctx, base, optionParserAddr + 80, entry, arg2);
			STORE8((uint32_t)optionParserAddr + 16, (uint8_t)parsed);
		}
		ctx.r1.u64 = stack;
		uint32_t valuePtr = n_sub_82C84838(ctx, base, (uint64_t)stack + 80, entry);
		optionParser->m_20 = LOAD32(valuePtr);
		result = optionParserAddr + 80;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C856D8, 0x82C856D8) { ctx.r3.u64 = n_sub_82C856D8(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint32_t COptionParser_BuildNodeList(CpuState& ctx, uint8_t* base, uint64_t optionParserAddr, uint64_t arg2) {
	if (!UseLiftedCode(93, 0x82C85860)) { ctx.r3.u64 = optionParserAddr; ctx.r8.u64 = arg2; __imp__sub_82C85860(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C85860);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	stack = PushStackFrame(base, stack, 224);

	if (int32_t(optionParser->m_20) != 3) {
		stack = PopStackFrame(stack, 224);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = arg2;
		return 0;
	}

	uint32_t nodeListHead = (uint32_t)optionParserAddr + 144;
	uint32_t nodeAddr = (uint32_t)optionParserAddr + 12;
	uint64_t callState = 0;

	ctx.r1.u64 = stack;
	ctx.r8.u64 = arg2;
	n_sub_82C84EF8(ctx, base, nodeListHead);
	callState = ctx.r8.u64;

	uint32_t state;
	do {
		bool nodeActive = LOAD8(nodeAddr + 4) != 0;

		STORE32(stack + 136, 15);
		STORE32(stack + 132, 0);
		STORE8(stack + 116, 0);
		STORE32(stack + 168, 15);
		STORE32(stack + 164, 0);
		STORE8(stack + 148, 0);
		STORE32(stack + 140, 0);

		if (nodeActive) {
			uint32_t writeResult = n_sub_82C85250(ctx, base, (uint64_t)stack + 112, nodeAddr, callState);
			callState = ctx.r8.u64;
			STORE8(nodeAddr + 4, (uint8_t)writeResult);

			if (LOAD8(nodeAddr + 4) != 0) {
				writeResult = n_sub_82C85538(ctx, base, (uint64_t)stack + 140, nodeAddr, callState);
				callState = ctx.r8.u64;
				STORE8(nodeAddr + 4, (uint8_t)writeResult);
			}
		}

		n_sub_82C85468(ctx, base, nodeListHead, (uint64_t)stack + 112, callState);
		callState = ctx.r8.u64;

		uint32_t value = 4;
		if (LOAD8(nodeAddr + 4) != 0) {
			uint8_t extra = LOAD8(nodeAddr + 5);
			uint32_t source = LOAD32(nodeAddr);
			uint32_t lz = extra == 0 ? 32 : __builtin_clz(extra);
			uint64_t flag = (uint64_t)((lz >> 5) & 1) ^ 1;
			uint32_t flagByte = (uint32_t)flag & 0xFF;

			uint64_t bufferDesc;
			if (flagByte != 0) {
				STORE32(stack + 92, 0);
				bufferDesc = (uint64_t)stack + 88;
				STORE32(stack + 88, (uint64_t)stack + 80);
			} else {
				STORE32(stack + 100, 0);
				bufferDesc = (uint64_t)stack + 96;
				STORE32(stack + 96, (uint64_t)stack + 80);
			}

			uint32_t vtable = LOAD32(source);
			uint32_t method = LOAD32(vtable + 12);
			callTarget.u64 = method;
			ctx.r3.u64 = source;
			ctx.r4.u64 = bufferDesc;
			ctx.r5.u64 = 1;
			ctx.r7.u64 = flagByte;
			ctx.r8.u64 = flag;
			ctx.r9.u64 = method;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint32_t callResult = ctx.r3.u32;
			callState = callResult == 0 ? 32 : __builtin_clz(callResult);
			value = LOAD8(stack + 80);
			STORE8(nodeAddr + 4, (uint8_t)((uint32_t)callState >> 5 & 1));
		}

		uint32_t cap1 = LOAD32(stack + 168);
		optionParser->m_20 = value;
		if (cap1 >= 16) {
			uint32_t ptr1 = LOAD32(stack + 148);
			ctx.r8.u64 = callState;
			HandleTarget_FreeThunk(ctx, base, ptr1);
			callState = ctx.r8.u64;
		}

		uint32_t cap2 = LOAD32(stack + 136);
		STORE32(stack + 168, 15);
		STORE32(stack + 164, 0);
		STORE8(stack + 148, 0);
		if (cap2 >= 16) {
			uint32_t ptr2 = LOAD32(stack + 116);
			ctx.r8.u64 = callState;
			HandleTarget_FreeThunk(ctx, base, ptr2);
			callState = ctx.r8.u64;
		}

		state = optionParser->m_20;

		STORE32(stack + 136, 15);
		STORE32(stack + 132, 0);
		STORE8(stack + 116, 0);
	} while ((int32_t)state == 3);

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = callState;
	return nodeListHead;
}
PROMOTED_ENTRY(93, sub_82C85860, 0x82C85860) { ctx.r3.u64 = COptionParser_BuildNodeList(ctx, base, ctx.r3.u64, ctx.r8.u64); }

// Returns 0 when m_24 holds no string, or when name is given and the string at m_24 differs from it.
// Otherwise increments m_8, copies that string into the string object at +52 (its address goes to m_28),
// stores new m_nodeList, m_currentNode and m_24 values and returns 1.
uint64_t n_sub_82C859E0(CpuState& ctx, uint8_t* base, uint64_t optionParserAddr, uint64_t name, uint64_t r8State) {
	if (!UseLiftedCode(93, 0x82C859E0)) { ctx.r3.u64 = optionParserAddr; ctx.r4.u64 = name; ctx.r8.u64 = r8State; __imp__sub_82C859E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C859E0);
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint64_t r4Out = name;
	uint32_t result = 0;
	uint32_t currentString = optionParser->m_24;
	if (currentString != 0) {
		bool nameDiffers = false;
		if ((uint32_t)name != 0) {
			ctx.r1.u64 = stack;
			uint32_t differs = n_sub_82C84490(ctx, base, currentString, name, r8State);
			r4Out = ctx.r4.u64;
			r8State = ctx.r8.u64;
			nameDiffers = (differs & 0xFF) != 0;
		}

		if (!nameDiffers) {
			uint32_t depth = optionParser->m_8;
			uint32_t sourceString = optionParser->m_24;
			optionParser->m_8 = depth + 1;

			uint64_t r4State = sourceString;
			uint64_t stringCopyAddr = 0;
			if (sourceString != 0) {
				stringCopyAddr = optionParserAddr + 52;
				ctx.r1.u64 = stack;
				BasicString_AssignSubstr(ctx, base, stringCopyAddr, sourceString, 0, -1, r8State);
				r4State = ctx.r4.u64;
				r8State = ctx.r8.u64;
			}
			optionParser->m_28 = (uint32_t)stringCopyAddr;

			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r4.u64 = r4State;
			optionParser->m_nodeList = COptionParser_BuildNodeList(ctx, base, optionParserAddr, r8State);
			optionParser->m_currentNode = n_sub_82C85658(ctx, base, optionParserAddr, ctx.r8.u64);

			uint32_t nextString = n_sub_82C856D8(ctx, base, optionParserAddr, ctx.r8.u64);
			r4Out = ctx.r4.u64;
			r8State = ctx.r8.u64;
			optionParser->m_24 = nextString;

			result = 1;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 and r8 after the call
	ctx.r4.u64 = r4Out;
	ctx.r8.u64 = r8State;
	return result;
}
PROMOTED_ENTRY(93, sub_82C859E0, 0x82C859E0) { ctx.r3.u64 = n_sub_82C859E0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

// Acts only when m_8 is nonzero: calls the virtual at vtable + 12 for as long as the virtual at vtable + 8
// (second argument 0) returns a nonzero byte, then decrements m_8 and, unless it reached 0, sets a new m_24.
uint64_t n_sub_82C85AA0(CpuState& ctx, uint8_t* base, uint64_t optionParserAddr, uint64_t r8State) {
	if (!UseLiftedCode(93, 0x82C85AA0)) { ctx.r3.u64 = optionParserAddr; ctx.r8.u64 = r8State; __imp__sub_82C85AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C85AA0);
	uint32_t stack = ctx.r1.u64;
	COptionParser* optionParser = GameObject<COptionParser>(base, optionParserAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = optionParserAddr;
	uint64_t r9Out = ctx.r9.u64;

	if (optionParser->m_8 != 0) {
		optionParser->m_28 = 0u;
		ctx.r1.u64 = stack;
		optionParser->m_nodeList = COptionParser_BuildNodeList(ctx, base, optionParserAddr, r8State);
		optionParser->m_currentNode = n_sub_82C85658(ctx, base, optionParserAddr, ctx.r8.u64);

		PPCRegister callTarget{};
		uint32_t vtable = optionParser->vtable;
		uint32_t vfunc8 = LOAD32(vtable + 8);
		callTarget.u64 = vfunc8;
		ctx.r3.u64 = optionParserAddr;
		ctx.r4.u64 = 0;
		ctx.r9.u64 = vfunc8;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t resultByte = ctx.r3.u32 & 0xFF;
		// values r7 and r8 are handed before the next calls (the original reuses them for the result byte)
		uint64_t r7State = ctx.r7.u64;
		r8State = resultByte;
		while (resultByte != 0) {
			uint32_t vfunc12 = LOAD32((uint32_t)optionParser->vtable + 12);
			callTarget.u64 = vfunc12;
			ctx.r3.u64 = optionParserAddr;
			ctx.r7.u64 = r7State;
			ctx.r8.u64 = r8State;
			ctx.r10.u64 = vfunc12;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			vtable = optionParser->vtable;
			vfunc8 = LOAD32(vtable + 8);
			callTarget.u64 = vfunc8;
			ctx.r3.u64 = optionParserAddr;
			ctx.r4.u64 = 0;
			ctx.r8.u64 = vfunc8;
			ctx.r9.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			resultByte = ctx.r3.u32 & 0xFF;
			r7State = resultByte;
			r8State = ctx.r8.u64;
		}

		uint32_t depth = optionParser->m_8;
		optionParser->m_8 = depth - 1;
		// state the callee may pass on
		ctx.r7.u64 = r7State;
		ctx.r8.u64 = r8State;
		result = n_sub_82C84838(ctx, base, (uint64_t)stack + 80, optionParserAddr + 12);
		r8State = ctx.r8.u64;
		r9Out = optionParser->m_8;
		optionParser->m_20 = LOAD32((uint32_t)result);
		if ((uint32_t)r9Out != 0) {
			ctx.r9.u64 = r9Out;
			result = n_sub_82C856D8(ctx, base, optionParserAddr, ctx.r8.u64);
			r8State = ctx.r8.u64;
			r9Out = ctx.r9.u64;
			optionParser->m_24 = (uint32_t)result;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r8 and r9 after the call
	ctx.r8.u64 = r8State;
	ctx.r9.u64 = r9Out;
	return result;
}
PROMOTED_ENTRY(93, sub_82C85AA0, 0x82C85AA0) { ctx.r3.u64 = n_sub_82C85AA0(ctx, base, ctx.r3.u64, ctx.r8.u64); }
