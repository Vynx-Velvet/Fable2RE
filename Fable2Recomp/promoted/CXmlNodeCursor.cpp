// CXmlNodeCursor (vtable 0x8200E948): methods of the class as readable C++.
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

uint32_t n_sub_82C85DC0(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr, uint32_t arg2, uint64_t arg3) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	if (!UseLiftedCode(93, 0x82C85DC0)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82C85DC0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C85DC0);

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t writer = arg2;
	uint32_t resultPtr = (uint32_t)arg3;

	int32_t ntfailedFull = str_TXT_820C0000_B_;
	uint64_t typeName = (int64_t)ntfailedFull - 9784;
	uint64_t attrSource = g_82000C98;

	// temporary string object holding the attribute value
	uint32_t attrString = stack + 80;
	ctx.r1.u64 = stack;
	ctx.r5.u64 = arg3;
	n_sub_82C823D8(ctx, base, attrString, attrSource);

	uint32_t vtable = xmlNodeCursor->vtable;
	uint32_t setAttribute = LOAD32(vtable + 40);
	PPCRegister callTarget{};
	callTarget.u64 = setAttribute;
	ctx.r3.u64 = xmlNodeCursorAddr;
	ctx.r4.u64 = typeName;
	ctx.r5.u64 = attrString;
	ctx.r8.u64 = setAttribute;
	ctx.r9.u64 = vtable;
	ctx.r10.s64 = ntfailedFull;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t typeValue = CStringTable_Find(ctx, base, attrString);
	uint32_t value = n_sub_82C892E0(ctx, base, typeValue, ctx.r8.u64);
	STORE32(resultPtr, value);

	// length of the cursor's current node name, including the terminator
	uint32_t nameStart = CStringTable_Find(ctx, base, xmlNodeCursor->m_currentNode + 12);
	uint32_t nameEnd = nameStart;
	uint8_t nameByte;
	do {
		nameByte = LOAD8(nameEnd);
		nameEnd++;
	} while (nameByte != 0);
	uint32_t bufferSize = nameEnd - nameStart;

	ctx.r3.u64 = writer;
	ctx.r10.u64 = nameByte;
	CXmlNodeWriter_EnsureBuffer(ctx, base, bufferSize);

	ctx.r3.u64 = writer;
	uint32_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	// copy the node name into the number-format buffer
	uint32_t nodeName = CStringTable_Find(ctx, base, xmlNodeCursor->m_currentNode + 12);
	uint32_t dst = numberFormat;
	uint8_t ch;
	do {
		ch = LOAD8(nodeName);
		nodeName++;
		STORE8(dst, ch);
		dst++;
	} while (ch != 0);

	ctx.r10.u64 = ch;
	n_sub_82C85C98(ctx, base, numberFormat);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return numberFormat;
}
PROMOTED_ENTRY(93, sub_82C85DC0, 0x82C85DC0) { ctx.r3.u64 = n_sub_82C85DC0(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint64_t n_sub_82C85E98(CpuState& ctx, uint8_t* base, uint32_t xmlNodeCursorAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(93, 0x82C85E98)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = arg2; ctx.r6.u64 = arg3; ctx.r7.u64 = arg4; __imp__sub_82C85E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C85E98);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t savedArg2 = arg2;
	uint32_t firstNode = xmlNodeCursor->m_firstNode;
	if (firstNode != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		ctx.r6.u64 = arg3;
		ctx.r7.u64 = arg4;
		n_sub_82C88A58(ctx, base, firstNode);
		n_sub_82CA29E8(ctx, base, firstNode);
		arg2 = ctx.r4.u64;
		arg3 = ctx.r6.u64;
		arg4 = ctx.r7.u64;
	}
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	ctx.r6.u64 = arg3;
	ctx.r7.u64 = arg4;
	uint64_t node = n_sub_82C88628(ctx, base, 8);
	uint64_t newFirstNode = ((uint32_t)node != 0) ? n_sub_82C88678(ctx, base, node) : 0;
	xmlNodeCursor->m_firstNode = (uint32_t)newFirstNode;
	uint32_t cursorKind = xmlNodeCursor->m_4;
	uint64_t result = n_sub_82C88B38(ctx, base, newFirstNode, savedArg2, cursorKind, ctx.r6.u64, ctx.r7.u64);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C85E98, 0x82C85E98) { ctx.r3.u64 = n_sub_82C85E98(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r6.u64, ctx.r7.u64); }

uint64_t CXmlNodeCursor_ReadInt(CpuState& ctx, uint8_t* base, uint64_t xmlCursor, uint32_t outInt) {
	if (!UseLiftedCode(93, 0x82C85FD0)) { ctx.r3.u64 = xmlCursor; ctx.r4.u64 = outInt; __imp__sub_82C85FD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C85FD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t cursorSlot = stack + 80;
	uint32_t valueSlot = stack + 84;
	STORE32(valueSlot, 0u);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = outInt;
	XmlGlobalLock_Enter(ctx, base, cursorSlot);

	n_sub_82C85DC0(ctx, base, xmlCursor, cursorSlot, valueSlot);

	ctx.r3.u64 = cursorSlot;
	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);
	uint32_t value = n_sub_82CA3B30(ctx, base, numberFormat, ctx.r8.u64);
	STORE32(outInt, value);

	ctx.r3.u64 = cursorSlot;
	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C85FD0, 0x82C85FD0) { ctx.r3.u64 = CXmlNodeCursor_ReadInt(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_82C86040(CpuState& ctx, uint8_t* base, uint64_t arg1, uint32_t arg2) {
	if (!UseLiftedCode(93, 0x82C86040)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82C86040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t xmlLock = stack + 80;
	uint32_t valueOut = stack + 84;
	STORE32(valueOut, 0u);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	XmlGlobalLock_Enter(ctx, base, xmlLock);
	n_sub_82C85DC0(ctx, base, arg1, xmlLock, valueOut);

	ctx.r3.u64 = xmlLock;
	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	uint32_t value = n_sub_82C85B88(ctx, base, numberFormat, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
	STORE32(arg2, value);

	ctx.r3.u64 = xmlLock;
	uint64_t leaveResult = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return leaveResult;
}
PROMOTED_ENTRY(93, sub_82C86040, 0x82C86040) { ctx.r3.u64 = n_sub_82C86040(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CXmlNodeCursor_ReadFloat(CpuState& ctx, uint8_t* base, uint64_t xmlCursor, uint32_t outFloat) {
	if (!UseLiftedCode(93, 0x82C860B0)) { ctx.r3.u64 = xmlCursor; ctx.r4.u64 = outFloat; __imp__sub_82C860B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C860B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Scratch area used by the global lock: parsed value at +80, flag/error word at +84.
	uint32_t valueBuffer = stack + 80;
	uint32_t errorFlag = stack + 84;
	STORE32(errorFlag, 0u);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = outFloat;
	XmlGlobalLock_Enter(ctx, base, valueBuffer);

	n_sub_82C85DC0(ctx, base, xmlCursor, valueBuffer, errorFlag);

	ctx.r3.u64 = valueBuffer;
	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	n_sub_82C85C20(ctx, base, numberFormat, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r10.u64);

	ctx.fpscr.disableFlushMode();
	STORE_F32(outFloat, float(ctx.f1.f64));

	ctx.r3.u64 = valueBuffer;
	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C860B0, 0x82C860B0) { ctx.r3.u64 = CXmlNodeCursor_ReadFloat(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_82C86120(CpuState& ctx, uint8_t* base, uint64_t cursor, uint64_t node) {
	if (!UseLiftedCode(93, 0x82C86120)) { ctx.r3.u64 = cursor; ctx.r4.u64 = node; __imp__sub_82C86120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86120);
	uint32_t stack = ctx.r1.u64;
	uint64_t numberFormat = 0;
	uint64_t result = 0;

	stack = PushStackFrame(base, stack, 112);

	// Scratch object on the game stack, held under the XML global lock.
	uint32_t localNode = stack + 80;
	STORE32(stack + 84, 0u);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = node;
	XmlGlobalLock_Enter(ctx, base, localNode);

	n_sub_82C85DC0(ctx, base, cursor, localNode, stack + 84);

	ctx.r3.u64 = localNode;
	numberFormat = CXmlNode_GetNumberFormat(ctx, base);
	n_sub_82C825A0(ctx, base, node, numberFormat);

	ctx.r3.u64 = localNode;
	result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86120, 0x82C86120) { ctx.r3.u64 = n_sub_82C86120(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlNodeCursor_ReadBool(CpuState& ctx, uint8_t* base, uint64_t cursor, uint32_t outValue) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(93, 0x82C86190)) { ctx.r3.u64 = cursor; ctx.r4.u64 = outValue; __imp__sub_82C86190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86190);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Scratch reader state (stack+80) and the error slot (stack+84) it fills in.
	uint32_t readerState = stack + 80;
	uint32_t errorSlot = stack + 84;
	STORE32(errorSlot, 0u);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = outValue;
	XmlGlobalLock_Enter(ctx, base, readerState);

	n_sub_82C85DC0(ctx, base, cursor, readerState, errorSlot);

	ctx.r3.u64 = readerState;
	uint64_t text = CXmlNode_GetNumberFormat(ctx, base);

	uint64_t trueText = (int64_t)g_82000000 + 3900;
	ctx.r10.s64 = g_82000000;
	uint32_t compare = n_sub_82CAAF80(ctx, base, text, trueText, ctx.r8.u64);

	bool isTrue = (compare == 0);
	STORE8(outValue, (uint8_t)isTrue);

	ctx.r3.u64 = readerState;
	ctx.r8.u64 = isTrue;
	ctx.r9.u64 = isTrue ? 32 : __builtin_clz(compare);
	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86190, 0x82C86190) { ctx.r3.u64 = CXmlNodeCursor_ReadBool(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_82C86210(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr) {
	if (!UseLiftedCode(93, 0x82C86210)) { ctx.r3.u64 = xmlNodeCursorAddr; __imp__sub_82C86210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86210);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t vtable = xmlNodeCursor->vtable;
	uint32_t initFunc = LOAD32(vtable + 76);
	callTarget.u64 = initFunc;
	ctx.r3.u64 = xmlNodeCursorAddr;
	ctx.r10.u64 = initFunc;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	vtable = xmlNodeCursor->vtable;
	uint32_t resetFunc = LOAD32(vtable + 68);
	callTarget.u64 = resetFunc;
	ctx.r3.u64 = xmlNodeCursorAddr;
	ctx.r8.u64 = resetFunc;
	ctx.r9.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C86210, 0x82C86210) { ctx.r3.u64 = n_sub_82C86210(ctx, base, ctx.r3.u64); }

uint64_t CXmlNodeCursor_FindByName(CpuState& ctx, uint8_t* base, uint32_t xmlNodeCursorAddr, uint64_t nodeName, uint64_t startNode, uint64_t searchFlags) {
	if (!UseLiftedCode(93, 0x82C863E8)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = nodeName; ctx.r5.u64 = startNode; ctx.r6.u64 = searchFlags; __imp__sub_82C863E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C863E8);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t savedName = nodeName;

	uint32_t cursorNode = xmlNodeCursor->m_currentNode;
	if (cursorNode == 0) {
		// Cursor has no current position: try to start over from the head of the list.
		if (((uint32_t)searchFlags & 0xFF) == 0 && LOAD8(xmlNodeCursorAddr + 20) != 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return 0;
		}
		uint32_t headNode = LOAD32(uint32_t(xmlNodeCursor->m_firstNode));
		if (headNode == 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return 0;
		}
		uint64_t headNameEntry = (uint64_t)headNode + 8;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = nodeName;
		ctx.r5.u64 = startNode;
		ctx.r6.u64 = searchFlags;
		uint64_t headName = CStringTable_Find(ctx, base, headNameEntry);
		uint32_t headMatch = n_sub_82CAAF08(ctx, base, headName, savedName, ctx.r8.u64);
		if ((int32_t)headMatch != 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return 0;
		}
		xmlNodeCursor->m_currentNode = headNode;
		xmlNodeCursor->m_nextNode = LOAD32(headNode + 20);
		xmlNodeCursor->m_startedFromHead = uint8_t(1);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 1;
	}

	uint32_t flag = (uint32_t)searchFlags & 0xFF;
	uint32_t searchStart = (uint32_t)startNode;
	if (flag != 0 && searchStart == 0) {
		searchStart = LOAD32(cursorNode + 20);
	}
	if (searchStart == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	uint32_t node = searchStart;
	do {
		uint64_t nodeNameEntry = (uint64_t)node + 8;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = nodeName;
		ctx.r5.u64 = startNode;
		ctx.r6.u64 = searchFlags;
		uint64_t nameHandle = CStringTable_Find(ctx, base, nodeNameEntry);
		uint32_t match = n_sub_82CAAF08(ctx, base, nameHandle, savedName, ctx.r8.u64);
		nodeName = ctx.r4.u64;
		startNode = ctx.r5.u64;
		searchFlags = ctx.r6.u64;
		if ((int32_t)match == 0) {
			xmlNodeCursor->m_currentNode = node;
			xmlNodeCursor->m_nextNode = LOAD32(node + 20);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return 1;
		}
		node = LOAD32(node + 4);
		if (node == 0) {
			if (flag == 0) break;
			node = LOAD32(uint32_t(xmlNodeCursor->m_currentNode) + 20);
		}
	} while (node != searchStart);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C863E8, 0x82C863E8) { ctx.r3.u64 = CXmlNodeCursor_FindByName(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

void n_sub_82C864F0(CpuState& ctx, uint8_t* base, uint32_t xmlNodeCursorAddr) {
	if (!UseLiftedCode(93, 0x82C864F0)) { ctx.r3.u64 = xmlNodeCursorAddr; __imp__sub_82C864F0(ctx, base); return; }
	LiftedFrame frame(0x82C864F0);
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t currentNode = xmlNodeCursor->m_currentNode;
	xmlNodeCursor->m_nextNode = LOAD32(currentNode + 4);
	xmlNodeCursor->m_currentNode = LOAD32(currentNode + 16);
	return;
}
PROMOTED_ENTRY(93, sub_82C864F0, 0x82C864F0) { n_sub_82C864F0(ctx, base, ctx.r3.u32); }

uint64_t CXmlNodeCursor_TryGetInt(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursor, uint64_t attributeName, uint32_t outValue, uint64_t arg4) {
	if (!UseLiftedCode(93, 0x82C86508)) { ctx.r3.u64 = xmlNodeCursor; ctx.r4.u64 = attributeName; ctx.r5.u64 = outValue; ctx.r8.u64 = arg4; __imp__sub_82C86508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	uint32_t node = LOAD32((uint32_t)xmlNodeCursor + 12);
	if (node == 0) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		return 0;
	}

	ctx.r1.u64 = stack;
	ctx.r5.u64 = outValue;
	ctx.r8.u64 = arg4;
	uint32_t attributeNode = n_sub_82C88EE8(ctx, base, node, attributeName);
	attributeName = ctx.r4.u64;
	if (attributeNode == 0) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		return 0;
	}

	uint32_t value = n_sub_82CA3B30(ctx, base, attributeNode, ctx.r8.u64);
	STORE32(outValue, value);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86508, 0x82C86508) { ctx.r3.u64 = CXmlNodeCursor_TryGetInt(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint64_t n_sub_82C86570(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, uint32_t outValuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(93, 0x82C86570)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.r5.u64 = outValuePtr; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_82C86570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86570);
	uint32_t stack = ctx.r1.u64;
	uint32_t storedValue;
	uint32_t result = 0;
	stack = PushStackFrame(base, stack, 96);
	uint32_t child = LOAD32((uint32_t)arg1 + 12);
	if (child != 0) {
		ctx.r1.u64 = stack;
		ctx.r5.u64 = outValuePtr;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = arg5;
		ctx.r8.u64 = arg6;
		uint64_t entity = n_sub_82C88EE8(ctx, base, child, arg2);
		arg2 = ctx.r4.u64;
		if ((uint32_t)entity != 0) {
			storedValue = n_sub_82C85B88(ctx, base, entity, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
			STORE32(outValuePtr, storedValue);
			result = 1;
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return result;
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86570, 0x82C86570) { ctx.r3.u64 = n_sub_82C86570(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }
