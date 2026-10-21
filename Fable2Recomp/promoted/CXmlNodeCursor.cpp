// CXmlNodeCursor (vtable 0x8200E948): methods of the class as readable C++.
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

uint32_t CXmlNodeCursor_ReadValue(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr, uint32_t arg2, uint64_t arg3) {
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
	String_Construct_82C823D8(ctx, base, attrString, attrSource);

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
	uint32_t value = CXmlNodeType_FromString(ctx, base, typeValue, ctx.r8.u64);
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

	CXmlNodeWriter_EnsureBuffer(ctx, base, bufferSize);

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

	String_Trim(ctx, base, numberFormat);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return numberFormat;
}
PROMOTED_ENTRY(93, sub_82C85DC0, 0x82C85DC0) { ctx.r3.u64 = CXmlNodeCursor_ReadValue(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint64_t CXmlNodeCursor_Reset(CpuState& ctx, uint8_t* base, uint32_t xmlNodeCursorAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(93, 0x82C85E98)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = arg2; ctx.r6.u64 = arg3; ctx.r7.u64 = arg4; __imp__sub_82C85E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C85E98);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t savedArg2 = arg2;
	uint32_t firstNode = xmlNodeCursor->m_firstNode;
	if (firstNode != 0) {
		ctx.r1.u64 = stack;
		CXmlNode_FreeList(ctx, base, firstNode);
		Memory_Free(ctx, base, firstNode);
		arg2 = ctx.r4.u64;
		arg3 = ctx.r6.u64;
		arg4 = ctx.r7.u64;
	}
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	ctx.r6.u64 = arg3;
	uint64_t node = Memory_Alloc(ctx, base, 8);
	uint64_t newFirstNode = ((uint32_t)node != 0) ? CXmlNodeList_Init(ctx, base, node) : 0;
	xmlNodeCursor->m_firstNode = (uint32_t)newFirstNode;
	uint32_t cursorKind = xmlNodeCursor->m_4;
	uint64_t result = CXmlNodeCursor_InitRoot(ctx, base, newFirstNode, savedArg2, cursorKind, ctx.r6.u64, ctx.r7.u64);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C85E98, 0x82C85E98) { ctx.r3.u64 = CXmlNodeCursor_Reset(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r6.u64, ctx.r7.u64); }

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

	CXmlNodeCursor_ReadValue(ctx, base, xmlCursor, cursorSlot, valueSlot);

	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);
	uint32_t value = String_ParseInt(ctx, base, numberFormat, ctx.r8.u64);
	STORE32(outInt, value);

	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C85FD0, 0x82C85FD0) { ctx.r3.u64 = CXmlNodeCursor_ReadInt(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CXmlNodeCursor_ReadIntAutoBase(CpuState& ctx, uint8_t* base, uint64_t xmlCursor, uint32_t outInt) {
	if (!UseLiftedCode(93, 0x82C86040)) { ctx.r3.u64 = xmlCursor; ctx.r4.u64 = outInt; __imp__sub_82C86040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t xmlLock = stack + 80;
	uint32_t valueOut = stack + 84;
	STORE32(valueOut, 0u);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = outInt;
	XmlGlobalLock_Enter(ctx, base, xmlLock);
	CXmlNodeCursor_ReadValue(ctx, base, xmlCursor, xmlLock, valueOut);

	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	uint32_t value = String_ParseIntAutoBase(ctx, base, numberFormat, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
	STORE32(outInt, value);

	uint64_t leaveResult = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return leaveResult;
}
PROMOTED_ENTRY(93, sub_82C86040, 0x82C86040) { ctx.r3.u64 = CXmlNodeCursor_ReadIntAutoBase(ctx, base, ctx.r3.u64, ctx.r4.u32); }

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

	CXmlNodeCursor_ReadValue(ctx, base, xmlCursor, valueBuffer, errorFlag);

	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	String_ParseFloat_82C85C20(ctx, base, numberFormat, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r10.u64);

	ctx.fpscr.disableFlushMode();
	STORE_F32(outFloat, float(ctx.f1.f64));

	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C860B0, 0x82C860B0) { ctx.r3.u64 = CXmlNodeCursor_ReadFloat(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CXmlNodeCursor_ReadString(CpuState& ctx, uint8_t* base, uint64_t cursor, uint64_t outString) {
	if (!UseLiftedCode(93, 0x82C86120)) { ctx.r3.u64 = cursor; ctx.r4.u64 = outString; __imp__sub_82C86120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86120);
	uint32_t stack = ctx.r1.u64;
	uint64_t numberFormat = 0;
	uint64_t result = 0;

	stack = PushStackFrame(base, stack, 112);

	// Scratch object on the game stack, held under the XML global lock.
	uint32_t scratchString = stack + 80;
	STORE32(stack + 84, 0u);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = outString;
	XmlGlobalLock_Enter(ctx, base, scratchString);

	CXmlNodeCursor_ReadValue(ctx, base, cursor, scratchString, stack + 84);

	numberFormat = CXmlNode_GetNumberFormat(ctx, base);
	String_Assign(ctx, base, outString, numberFormat);

	result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86120, 0x82C86120) { ctx.r3.u64 = CXmlNodeCursor_ReadString(ctx, base, ctx.r3.u64, ctx.r4.u64); }

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

	CXmlNodeCursor_ReadValue(ctx, base, cursor, readerState, errorSlot);

	uint64_t text = CXmlNode_GetNumberFormat(ctx, base);

	uint64_t trueText = (int64_t)g_82000000 + 3900;
	uint32_t compare = String_Equals(ctx, base, text, trueText, ctx.r8.u64);

	bool isTrue = (compare == 0);
	STORE8(outValue, (uint8_t)isTrue);

	ctx.r8.u64 = isTrue;
	ctx.r9.u64 = isTrue ? 32 : __builtin_clz(compare);
	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86190, 0x82C86190) { ctx.r3.u64 = CXmlNodeCursor_ReadBool(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CXmlNodeCursor_Init(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr) {
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
PROMOTED_ENTRY(93, sub_82C86210, 0x82C86210) { ctx.r3.u64 = CXmlNodeCursor_Init(ctx, base, ctx.r3.u64); }

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
		uint32_t headMatch = String_EqualsIgnoreCase(ctx, base, headName, savedName, ctx.r8.u64);
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
		uint32_t match = String_EqualsIgnoreCase(ctx, base, nameHandle, savedName, ctx.r8.u64);
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

void CXmlNodeCursor_EnterFirstChild(CpuState& ctx, uint8_t* base, uint32_t xmlNodeCursorAddr) {
	if (!UseLiftedCode(93, 0x82C864F0)) { ctx.r3.u64 = xmlNodeCursorAddr; __imp__sub_82C864F0(ctx, base); return; }
	LiftedFrame frame(0x82C864F0);
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t currentNode = xmlNodeCursor->m_currentNode;
	xmlNodeCursor->m_nextNode = LOAD32(currentNode + 4);
	xmlNodeCursor->m_currentNode = LOAD32(currentNode + 16);
	return;
}
PROMOTED_ENTRY(93, sub_82C864F0, 0x82C864F0) { CXmlNodeCursor_EnterFirstChild(ctx, base, ctx.r3.u32); }

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
	uint32_t attributeNode = CXmlNode_FindChildByName(ctx, base, node, attributeName);
	attributeName = ctx.r4.u64;
	if (attributeNode == 0) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		return 0;
	}

	uint32_t value = String_ParseInt(ctx, base, attributeNode, ctx.r8.u64);
	STORE32(outValue, value);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86508, 0x82C86508) { ctx.r3.u64 = CXmlNodeCursor_TryGetInt(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint64_t CXmlNodeCursor_TryGetIntAutoBase(CpuState& ctx, uint8_t* base, uint64_t xmlCursor, uint64_t attributeName, uint32_t outValuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(93, 0x82C86570)) { ctx.r3.u64 = xmlCursor; ctx.r4.u64 = attributeName; ctx.r5.u64 = outValuePtr; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_82C86570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86570);
	uint32_t stack = ctx.r1.u64;
	uint32_t storedValue;
	uint32_t result = 0;
	stack = PushStackFrame(base, stack, 96);
	uint32_t child = LOAD32((uint32_t)xmlCursor + 12);
	if (child != 0) {
		ctx.r1.u64 = stack;
		ctx.r5.u64 = outValuePtr;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = arg5;
		ctx.r8.u64 = arg6;
		uint64_t entity = CXmlNode_FindChildByName(ctx, base, child, attributeName);
		attributeName = ctx.r4.u64;
		if ((uint32_t)entity != 0) {
			storedValue = String_ParseIntAutoBase(ctx, base, entity, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
			STORE32(outValuePtr, storedValue);
			result = 1;
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return result;
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = attributeName;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86570, 0x82C86570) { ctx.r3.u64 = CXmlNodeCursor_TryGetIntAutoBase(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CXmlNodeCursor_TryGetFloat(CpuState& ctx, uint8_t* base, uint64_t xmlCursor, uint64_t attributeName, uint32_t outFloat, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3, uint64_t forwardedArg4) {
	if (!UseLiftedCode(93, 0x82C865D8)) { ctx.r3.u64 = xmlCursor; ctx.r4.u64 = attributeName; ctx.r5.u64 = outFloat; ctx.r6.u64 = forwardedArg1; ctx.r7.u64 = forwardedArg2; ctx.r8.u64 = forwardedArg3; ctx.r10.u64 = forwardedArg4; __imp__sub_82C865D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C865D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CXmlNodeCursor* cursor = GameObject<CXmlNodeCursor>(base, xmlCursor);
	uint32_t currentNode = cursor->m_currentNode;
	if (currentNode == 0) {
		ctx.r4.u64 = attributeName;
		return 0;
	}

	ctx.r5.u64 = outFloat;
	ctx.r6.u64 = forwardedArg1;
	ctx.r7.u64 = forwardedArg2;
	ctx.r8.u64 = forwardedArg3;
	ctx.r10.u64 = forwardedArg4;
	uint64_t attributeText = CXmlNode_FindChildByName(ctx, base, currentNode, attributeName);
	if ((uint32_t)attributeText == 0) return 0;

	String_ParseFloat_82C85C20(ctx, base, attributeText, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r10.u64);
	double value = ctx.f1.f64;
	ctx.fpscr.disableFlushMode();
	STORE_F32(outFloat, float(value));
	return 1;
}
PROMOTED_ENTRY(93, sub_82C865D8, 0x82C865D8) { ctx.r3.u64 = CXmlNodeCursor_TryGetFloat(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r10.u64); }

uint64_t CXmlNodeCursor_TryGetBool(CpuState& ctx, uint8_t* base, uint64_t xmlCursor, uint64_t attributeName, uint32_t outBool, uint64_t forwardedArg) {
	constexpr int32_t str_TXT_82000F3C_B_ = int32_t(0x82000F3C);
	if (!UseLiftedCode(93, 0x82C86640)) { ctx.r3.u64 = xmlCursor; ctx.r4.u64 = attributeName; ctx.r5.u64 = outBool; ctx.r8.u64 = forwardedArg; __imp__sub_82C86640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86640);
	GameStackFrame stackFrame(ctx, base, 96);
	CXmlNodeCursor* cursor = GameObject<CXmlNodeCursor>(base, xmlCursor);
	uint32_t currentNode = cursor->m_currentNode;
	if (currentNode == 0) {
		ctx.r4.u64 = attributeName;
		return 0;
	}

	ctx.r5.u64 = outBool;
	ctx.r8.u64 = forwardedArg;
	uint64_t attributeText = CXmlNode_FindChildByName(ctx, base, currentNode, attributeName);
	if ((uint32_t)attributeText == 0) return 0;

	uint32_t compareResult = String_Equals(ctx, base, attributeText, str_TXT_82000F3C_B_, ctx.r8.u64);
	STORE8(outBool, uint8_t(compareResult == 0));
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86640, 0x82C86640) { ctx.r3.u64 = CXmlNodeCursor_TryGetBool(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint64_t CXmlNodeCursor_TryGetString(CpuState& ctx, uint8_t* base, uint64_t xmlCursor, uint64_t attributeName, uint64_t outString) {
	if (!UseLiftedCode(93, 0x82C866B8)) { ctx.r3.u64 = xmlCursor; ctx.r4.u64 = attributeName; ctx.r5.u64 = outString; __imp__sub_82C866B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C866B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	CXmlNodeCursor* cursor = GameObject<CXmlNodeCursor>(base, xmlCursor);

	// Left in r4 for the caller on failure: the name, or the failed lookup's result.
	uint64_t handedBack = attributeName;
	uint32_t currentNode = cursor->m_currentNode;
	if (currentNode != 0) {
		ctx.r1.u64 = stack;
		ctx.r5.u64 = outString;
		uint64_t attributeText = CXmlNode_FindChildByName(ctx, base, currentNode, attributeName);
		if ((uint32_t)attributeText != 0) {
			uint32_t valueString = stack + 80;
			String_Construct_82C823D8(ctx, base, valueString, attributeText);
			STORE32((uint32_t)outString, LOAD32(valueString));
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 1;
		}
		handedBack = attributeText;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = handedBack;
	return 0;
}
PROMOTED_ENTRY(93, sub_82C866B8, 0x82C866B8) { ctx.r3.u64 = CXmlNodeCursor_TryGetString(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CXmlNodeCursor_Advance(CpuState& ctx, uint8_t* base, uint32_t xmlNodeCursorAddr, uint32_t wrap) {
	if (!UseLiftedCode(93, 0x82C86728)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = wrap; __imp__sub_82C86728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86728);
	CXmlNodeCursor* cursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	// Handed on to CStringTable_Find in r8: the head node when the cursor restarts from it, else the caller's r8.
	uint32_t headNode = ctx.r8.u32;
	bool wrapAllowed = (wrap & 0xFF) != 0;
	uint32_t currentNode = cursor->m_currentNode;
	if (currentNode != 0) {
		uint32_t nextNode = cursor->m_nextNode;
		if (nextNode != 0) {
			cursor->m_currentNode = nextNode;
		} else {
			if (!wrapAllowed) return 0;
			uint32_t firstChild = LOAD32(currentNode + 20);
			if (firstChild == 0) return 0;
			cursor->m_currentNode = firstChild;
		}
	} else if (wrapAllowed || cursor->m_startedFromHead == 0) {
		headNode = LOAD32(uint32_t(cursor->m_firstNode));
		cursor->m_startedFromHead = uint8_t(1);
		cursor->m_currentNode = headNode;
	}

	uint32_t node = cursor->m_currentNode;
	if (node == 0) return 0;
	uint32_t nodeFirstChild = LOAD32(node + 20);
	cursor->m_nextNode = nodeFirstChild;
	ctx.r4.u64 = wrap;
	ctx.r8.u64 = headNode;
	ctx.r9.u64 = nodeFirstChild;
	ctx.r10.u64 = node;
	return CStringTable_Find(ctx, base, node + 8);
}
PROMOTED_ENTRY(93, sub_82C86728, 0x82C86728) { ctx.r3.u64 = CXmlNodeCursor_Advance(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CXmlNodeCursor_FindNextByName(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr, uint64_t nodeName) {
	if (!UseLiftedCode(93, 0x82C867C0)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = nodeName; __imp__sub_82C867C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C867C0);
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t currentNode = xmlNodeCursor->m_currentNode;
	uint32_t searchStart = (currentNode != 0) ? LOAD32(currentNode + 20) : 0;
	return CXmlNodeCursor_FindByName(ctx, base, xmlNodeCursorAddr, nodeName, searchStart, 0);
}
PROMOTED_ENTRY(93, sub_82C867C0, 0x82C867C0) { ctx.r3.u64 = CXmlNodeCursor_FindNextByName(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlNodeCursor_AdvanceNoWrap(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr) {
	if (!UseLiftedCode(93, 0x82C867E0)) { ctx.r3.u64 = xmlNodeCursorAddr; __imp__sub_82C867E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C867E0);
	return CXmlNodeCursor_Advance(ctx, base, xmlNodeCursorAddr, 0);
}
PROMOTED_ENTRY(93, sub_82C867E0, 0x82C867E0) { ctx.r3.u64 = CXmlNodeCursor_AdvanceNoWrap(ctx, base, ctx.r3.u64); }

uint64_t CXmlNodeCursor_FindByNameFromNext(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr, uint64_t nodeName) {
	if (!UseLiftedCode(93, 0x82C867E8)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = nodeName; __imp__sub_82C867E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C867E8);
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t nextNode = xmlNodeCursor->m_nextNode;
	return CXmlNodeCursor_FindByName(ctx, base, xmlNodeCursorAddr, nodeName, nextNode, 0);
}
PROMOTED_ENTRY(93, sub_82C867E8, 0x82C867E8) { ctx.r3.u64 = CXmlNodeCursor_FindByNameFromNext(ctx, base, ctx.r3.u64, ctx.r4.u64); }

void CXmlNodeCursor_SaveNext(CpuState& ctx, uint8_t* base, uint32_t xmlNodeCursorAddr) {
	if (!UseLiftedCode(93, 0x82C86810)) { ctx.r3.u64 = xmlNodeCursorAddr; __imp__sub_82C86810(ctx, base); return; }
	LiftedFrame frame(0x82C86810);
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t currentNode = xmlNodeCursor->m_currentNode;
	if (currentNode == 0) return;
	xmlNodeCursor->m_nextNode = LOAD32(currentNode + 0x14);
}
PROMOTED_ENTRY(93, sub_82C86810, 0x82C86810) { CXmlNodeCursor_SaveNext(ctx, base, ctx.r3.u32); }

uint64_t CXmlNodeCursor_Dtor(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr, uint64_t deleteFlags) {
	constexpr uint32_t CXmlNodeCursor_vtable = 0x8200E948u;
	if (!UseLiftedCode(93, 0x82C86828)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82C86828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86828);
	GameStackFrame stackFrame(ctx, base, 112);
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t nodeList = xmlNodeCursor->m_firstNode;
	xmlNodeCursor->vtable = CXmlNodeCursor_vtable;
	// Handed to the base destructor in r4: the delete flags, or what Memory_Free leaves there.
	uint64_t forwardedValue = deleteFlags;
	if (nodeList != 0) {
		ctx.r4.u64 = deleteFlags;
		CXmlNode_FreeList(ctx, base, nodeList);
		Memory_Free(ctx, base, nodeList);
		forwardedValue = ctx.r4.u64;
	}
	ctx.r4.u64 = forwardedValue;
	C_8200E9A8_Destruct(ctx, base, xmlNodeCursorAddr);
	if ((uint32_t(deleteFlags) & 1) != 0) {
		HandleTarget_FreeThunk(ctx, base, xmlNodeCursorAddr);
	}
	return xmlNodeCursorAddr;
}
PROMOTED_ENTRY(93, sub_82C86828, 0x82C86828) { ctx.r3.u64 = CXmlNodeCursor_Dtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlNodeCursor_FindByNameFromNextWrap(CpuState& ctx, uint8_t* base, uint64_t xmlNodeCursorAddr, uint64_t nodeName) {
	if (!UseLiftedCode(93, 0x82C86890)) { ctx.r3.u64 = xmlNodeCursorAddr; ctx.r4.u64 = nodeName; __imp__sub_82C86890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86890);
	CXmlNodeCursor* xmlNodeCursor = GameObject<CXmlNodeCursor>(base, xmlNodeCursorAddr);
	uint32_t nextNode = xmlNodeCursor->m_nextNode;
	return CXmlNodeCursor_FindByName(ctx, base, xmlNodeCursorAddr, nodeName, nextNode, 1);
}
PROMOTED_ENTRY(93, sub_82C86890, 0x82C86890) { ctx.r3.u64 = CXmlNodeCursor_FindByNameFromNextWrap(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlNodeCursor_AdvanceWrap(CpuState& ctx, uint8_t* base, uint64_t cursor) {
	if (!UseLiftedCode(93, 0x82C868A0)) { ctx.r3.u64 = cursor; __imp__sub_82C868A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C868A0);
	return CXmlNodeCursor_Advance(ctx, base, cursor, 1);
}
PROMOTED_ENTRY(93, sub_82C868A0, 0x82C868A0) { ctx.r3.u64 = CXmlNodeCursor_AdvanceWrap(ctx, base, ctx.r3.u64); }
