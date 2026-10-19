// CXmlNodeWriter (vtable 0x82009308): methods of the class as readable C++.
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
#include "lifted/readable_support.h"

uint64_t CXmlNodeWriter_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(89, 0x82BF8E28)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82BF8E28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BF8E28);
	uint32_t stack = ctx.r1.u64;
	uint32_t deleteFlags = arg2;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	n_sub_82C87538(ctx, base, arg1);
	uint64_t self = arg1;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, self);
		self = arg1;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return self;
}
PROMOTED_ENTRY(89, sub_82BF8E28, 0x82BF8E28) { ctx.r3.u64 = CXmlNodeWriter_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C86988(CpuState& ctx, uint8_t* base, uint32_t xmlNodeWriterAddr, uint64_t node) {
	if (!UseLiftedCode(93, 0x82C86988)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = node; __imp__sub_82C86988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86988);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 112);
	if (xmlNodeWriter->m_8 == 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = node;
		uint64_t storage = n_sub_82C88628(ctx, base, 8);
		uint32_t nodeStore = (uint32_t)storage != 0 ? n_sub_82C88678(ctx, base, storage) : 0;
		xmlNodeWriter->m_8 = nodeStore;
	}
	uint32_t childList = LOAD32(uint32_t(xmlNodeWriter->m_8) + 4);
	ctx.r1.u64 = stack;
	uint64_t appendedNode = n_sub_82C89270(ctx, base, node, childList);
	uint32_t previousNode = xmlNodeWriter->m_C;
	uint64_t result = appendedNode;
	if (previousNode != 0) {
		n_sub_82C88D78(ctx, base, previousNode, result);
	} else {
		n_sub_82C88630(ctx, base, xmlNodeWriter->m_8, result);
		result = ctx.r4.u64;
	}
	xmlNodeWriter->m_C = (uint32_t)appendedNode;
	xmlNodeWriter->m_10 = 0u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = result;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86988, 0x82C86988) { ctx.r3.u64 = n_sub_82C86988(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_82C86A30  [16 bytes]
void n_sub_82C86A30(CpuState& ctx, uint8_t* base, uint32_t xmlNodeWriterAddr) {
	if (!UseLiftedCode(93, 0x82C86A30)) { ctx.r3.u64 = xmlNodeWriterAddr; __imp__sub_82C86A30(ctx, base); return; }
	LiftedFrame frame(0x82C86A30);
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	uint32_t nextNode = LOAD32(uint32_t(xmlNodeWriter->m_C) + 16);
	xmlNodeWriter->m_C = nextNode;
	ctx.r10.u64 = nextNode;
	return;
}
PROMOTED_ENTRY(93, sub_82C86A30, 0x82C86A30) { n_sub_82C86A30(ctx, base, ctx.r3.u32); }

// sub_82C86A40  [124 bytes]
uint32_t n_sub_82C86A40(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t arg2, uint64_t nodeType) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	if (!UseLiftedCode(93, 0x82C86A40)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = nodeType; __imp__sub_82C86A40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C86A40);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	n_sub_82C892C8(ctx, base, (uint32_t)nodeType);
	uint64_t nameArg = n_sub_82C892C8(ctx, base, nodeType);
	uint32_t nameBuffer = stack + 80;
	ctx.r5.u64 = nodeType;
	n_sub_82C823D8(ctx, base, nameBuffer, nameArg);
	if (LOAD8((uint32_t)xmlNodeWriterAddr + 20) != 0) {
		int32_t typeAttrName = str_TXT_820C0000_B_ - 9784;
		uint32_t writeTypeAttribute = LOAD32(uint32_t(xmlNodeWriter->vtable) + 40);
		ctx.r3.u64 = xmlNodeWriterAddr;
		ctx.r4.u64 = (int64_t)typeAttrName;
		ctx.r5.u64 = nameBuffer;
		ctx.r9.u64 = writeTypeAttribute;
		ctx.r10.s64 = str_TXT_820C0000_B_;
		REX_CALL_INDIRECT_FUNC(writeTypeAttribute);
	}
	uint32_t newNode = n_sub_82C88CF0(ctx, base, xmlNodeWriter->m_C, arg2);
	xmlNodeWriter->m_10 = xmlNodeWriter->m_C;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return newNode;
}
PROMOTED_ENTRY(93, sub_82C86A40, 0x82C86A40) { ctx.r3.u64 = n_sub_82C86A40(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82C86AC0(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t attributeName, uint64_t valuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint64_t arg7) {
	if (!UseLiftedCode(93, 0x82C86AC0)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valuePtr; ctx.r7.u64 = arg4; ctx.r8.u64 = arg5; ctx.r9.u64 = arg6; ctx.r10.u64 = arg7; __imp__sub_82C86AC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86AC0);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);
	uint64_t result = xmlNodeWriterAddr;
	if (LOAD32((uint32_t)xmlNodeWriterAddr + 12) != 0) {
		uint32_t stackWriter = stack + 80;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = valuePtr;
		ctx.r7.u64 = arg4;
		ctx.r8.u64 = arg5;
		ctx.r9.u64 = arg6;
		ctx.r10.u64 = arg7;
		XmlGlobalLock_Enter(ctx, base, stackWriter);

		uint32_t intValue = LOAD32((uint32_t)valuePtr);
		CXmlNodeWriter_EnsureBuffer(ctx, base, 16);

		uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);
		uint64_t decimalFormat = (uint64_t)(int64_t)-2113926352;
		n_sub_82CA3EB8(ctx, base, numberFormat, 16, decimalFormat, intValue, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);

		uint32_t vtable = xmlNodeWriter->vtable;
		uint64_t numberFormat2 = CXmlNode_GetNumberFormat(ctx, base);
		uint32_t writeProc = LOAD32(vtable + 88);
		callTarget.u64 = (uint64_t)writeProc;
		ctx.r3.u64 = xmlNodeWriterAddr;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = numberFormat2;
		ctx.r10.u64 = writeProc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		result = XmlGlobalLock_Leave(ctx, base);
		attributeName = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = attributeName;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86AC0, 0x82C86AC0) { ctx.r3.u64 = n_sub_82C86AC0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C86BE0(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t attributeName, uint64_t valuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(93, 0x82C86BE0)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valuePtr; ctx.r8.u64 = arg4; ctx.r9.u64 = arg5; ctx.r10.u64 = arg6; __imp__sub_82C86BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86BE0);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = xmlNodeWriterAddr;
	uint64_t r4ForCaller = attributeName;  // r4 the lock release leaves behind is forwarded to the caller

	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t lockBuffer = stack + 80;  // 48-byte lock/scratch buffer at the top of the frame

	if (LOAD32((uint32_t)xmlNodeWriterAddr + 12) != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = valuePtr;
		ctx.r8.u64 = arg4;
		ctx.r9.u64 = arg5;
		ctx.r10.u64 = arg6;
		uint64_t lock = XmlGlobalLock_Enter(ctx, base, lockBuffer);

		ctx.fpscr.disableFlushMode();
		double value = double(LOAD_F32((uint32_t)valuePtr));
		n_sub_82C868A8(ctx, base, lockBuffer, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64, value);

		uint32_t vtable = xmlNodeWriter->vtable;
		uint32_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)LOAD32(vtable + 88);
		ctx.r3.u64 = xmlNodeWriterAddr;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = numberFormat;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		result = XmlGlobalLock_Leave(ctx, base);
		r4ForCaller = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCaller;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86BE0, 0x82C86BE0) { ctx.r3.u64 = n_sub_82C86BE0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C86C50(CpuState& ctx, uint8_t* base, uint32_t self, uint64_t name, uint64_t value) {
	if (!UseLiftedCode(93, 0x82C86C50)) { ctx.r3.u64 = self; ctx.r4.u64 = name; ctx.r5.u64 = value; __imp__sub_82C86C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86C50);
	uint32_t node = LOAD32(self + 0xC);
	if (node == 0) {
		ctx.r4.u64 = name;
		return 0;
	}
	uint32_t owner = LOAD32(self + 0x8);
	uint32_t container = LOAD32(owner + 0x4);
	return n_sub_82C88E68(ctx, base, node, name, value, container);
}
PROMOTED_ENTRY(93, sub_82C86C50, 0x82C86C50) { ctx.r3.u64 = n_sub_82C86C50(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82C86C70(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t attributeName, uint64_t valueString) {
	if (!UseLiftedCode(93, 0x82C86C70)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valueString; __imp__sub_82C86C70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86C70);

	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t vtable2 = xmlNodeWriter->vtable;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = attributeName;
	ctx.r5.u64 = valueString;
	uint64_t stringTable = CStringTable_Find(ctx, base, valueString);

	uint32_t callTarget = LOAD32(vtable2 + 88);
	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = attributeName;
	ctx.r5.u64 = stringTable;
	REX_CALL_INDIRECT_FUNC(callTarget);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C86C70, 0x82C86C70) { ctx.r3.u64 = n_sub_82C86C70(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82C86CB0(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t attributeName, uint64_t valuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint64_t arg7, uint64_t arg8) {
	if (!UseLiftedCode(93, 0x82C86CB0)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valuePtr; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; ctx.r9.u64 = arg7; ctx.r10.u64 = arg8; __imp__sub_82C86CB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86CB0);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = xmlNodeWriterAddr;
	uint64_t r4ForCaller = attributeName;  // r4 the lock release leaves behind is forwarded to the caller
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 128);
	if (LOAD32((uint32_t)xmlNodeWriterAddr + 12) != 0) {
		uint32_t lockNode = stack + 80;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = valuePtr;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = arg5;
		ctx.r8.u64 = arg6;
		ctx.r9.u64 = arg7;
		ctx.r10.u64 = arg8;
		XmlGlobalLock_Enter(ctx, base, lockNode);
		uint8_t nodeType = LOAD8((uint32_t)valuePtr);
		n_sub_82C86918(ctx, base, nodeType, lockNode, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);
		uint32_t vtable = xmlNodeWriter->vtable;
		uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)LOAD32(vtable + 88);
		ctx.r3.u64 = xmlNodeWriterAddr;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = numberFormat;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = XmlGlobalLock_Leave(ctx, base);
		r4ForCaller = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCaller;
	return result;
}
PROMOTED_ENTRY(93, sub_82C86CB0, 0x82C86CB0) { ctx.r3.u64 = n_sub_82C86CB0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C86D20(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t arg2, uint64_t valuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint64_t arg7) {
	if (!UseLiftedCode(93, 0x82C86D20)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = valuePtr; ctx.r7.u64 = arg4; ctx.r8.u64 = arg5; ctx.r9.u64 = arg6; ctx.r10.u64 = arg7; __imp__sub_82C86D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86D20);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t attributeName = arg2;
	uint32_t intValuePtr = (uint32_t)valuePtr;
	uint64_t r4ForCaller = arg2;  // r4/r7/r8 the lock release leaves behind are forwarded to the caller
	uint64_t r7ForCaller = arg4;
	uint64_t r8ForCaller = arg5;

	if (LOAD32((uint32_t)xmlNodeWriterAddr + 12) != 0) {
		const uint32_t formatBuffer = stack + 80;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		ctx.r5.u64 = valuePtr;
		ctx.r7.u64 = arg4;
		ctx.r8.u64 = arg5;
		ctx.r9.u64 = arg6;
		ctx.r10.u64 = arg7;
		XmlGlobalLock_Enter(ctx, base, formatBuffer);

		uint32_t intValue = LOAD32(intValuePtr);
		CXmlNodeWriter_EnsureBuffer(ctx, base, 16);

		uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

		n_sub_82CA3EB8(ctx, base, numberFormat, 16, (uint64_t)(int64_t)-2113926352, intValue, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);

		uint32_t vtable = xmlNodeWriter->vtable;
		uint64_t formattedValue = CXmlNode_GetNumberFormat(ctx, base);
		uint32_t writeAttribute = LOAD32(vtable + 88);

		PPCRegister callTarget{};
		callTarget.u64 = writeAttribute;
		ctx.r3.u64 = xmlNodeWriterAddr;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = formattedValue;
		ctx.r10.u64 = writeAttribute;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		XmlGlobalLock_Leave(ctx, base);
		r4ForCaller = ctx.r4.u64;
		r7ForCaller = ctx.r7.u64;
		r8ForCaller = ctx.r8.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCaller;
	ctx.r7.u64 = r7ForCaller;
	ctx.r8.u64 = r8ForCaller;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86D20, 0x82C86D20) { ctx.r3.u64 = n_sub_82C86D20(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C86DB8(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t attributeName, uint64_t valuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint64_t arg7) {
	if (!UseLiftedCode(93, 0x82C86DB8)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valuePtr; ctx.r7.u64 = arg4; ctx.r8.u64 = arg5; ctx.r9.u64 = arg6; ctx.r10.u64 = arg7; __imp__sub_82C86DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86DB8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t buffer = stack + 80;
	if (LOAD32((uint32_t)xmlNodeWriterAddr + 12) != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = valuePtr;
		ctx.r7.u64 = arg4;
		ctx.r8.u64 = arg5;
		ctx.r9.u64 = arg6;
		ctx.r10.u64 = arg7;
		XmlGlobalLock_Enter(ctx, base, buffer);

		uint32_t value = LOAD32((uint32_t)valuePtr);
		CXmlNodeWriter_EnsureBuffer(ctx, base, 16);

		uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);
		n_sub_82CA3EB8(ctx, base, numberFormat, 16, (uint64_t)(int64_t)-2113243288, value, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);

		uint32_t vtable = xmlNodeWriter->vtable;
		uint64_t valueFormat = CXmlNode_GetNumberFormat(ctx, base);
		uint32_t writeValueFn = LOAD32(vtable + 88);
		callTarget.u64 = (uint64_t)writeValueFn;
		ctx.r3.u64 = xmlNodeWriterAddr;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = valueFormat;
		ctx.r10.u64 = writeValueFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		XmlGlobalLock_Leave(ctx, base);
		attributeName = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = attributeName;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86DB8, 0x82C86DB8) { ctx.r3.u64 = n_sub_82C86DB8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C86E50(CpuState& ctx, uint8_t* base, uint64_t writerAddr, uint64_t attributeName, uint64_t valuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(93, 0x82C86E50)) { ctx.r3.u64 = writerAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valuePtr; ctx.r8.u64 = arg4; ctx.r9.u64 = arg5; ctx.r10.u64 = arg6; __imp__sub_82C86E50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86E50);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, writerAddr);

	stack = PushStackFrame(base, stack, 128);
	if (LOAD32((uint32_t)writerAddr + 12) != 0) {
		uint32_t numberBuffer = stack + 80;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = valuePtr;
		ctx.r8.u64 = arg4;
		ctx.r9.u64 = arg5;
		ctx.r10.u64 = arg6;
		uint64_t globalLock = XmlGlobalLock_Enter(ctx, base, numberBuffer);

		ctx.fpscr.disableFlushMode();
		double number = double(LOAD_F32(uint32_t(valuePtr)));
		n_sub_82C868A8(ctx, base, numberBuffer, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64, number);

		uint32_t vtablePtr = xmlNodeWriter->vtable;
		uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);
		uint32_t writeNumberFn = LOAD32(vtablePtr + 88);
		ctx.r3.u64 = writerAddr;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = numberFormat;
		REX_CALL_INDIRECT_FUNC(writeNumberFn);

		XmlGlobalLock_Leave(ctx, base);
		attributeName = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = attributeName;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86E50, 0x82C86E50) { ctx.r3.u64 = n_sub_82C86E50(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C86EC0(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t attributeName, uint64_t valueString) {
	if (!UseLiftedCode(93, 0x82C86EC0)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valueString; __imp__sub_82C86EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86EC0);
	uint32_t stack = ctx.r1.u64;

	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);

	stack = PushStackFrame(base, stack, 112);

	// Write method slot from the node writer's vtable.
	uint32_t writeMethod = LOAD32(xmlNodeWriter->vtable + 88);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = attributeName;
	ctx.r5.u64 = valueString;
	uint64_t stringTable = CStringTable_Find(ctx, base, valueString);

	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = attributeName;
	ctx.r5.u64 = stringTable;
	REX_CALL_INDIRECT_FUNC(writeMethod);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86EC0, 0x82C86EC0) { ctx.r3.u64 = n_sub_82C86EC0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82C86F08(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t attributeName, uint64_t valuePtr, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint64_t arg7, uint64_t arg8) {
	if (!UseLiftedCode(93, 0x82C86F08)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = attributeName; ctx.r5.u64 = valuePtr; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; ctx.r9.u64 = arg7; ctx.r10.u64 = arg8; __imp__sub_82C86F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86F08);
	uint32_t stack = ctx.r1.u64;
	uint32_t vtable2{};
	uint64_t numberFormat{};
	PPCRegister callTarget{};
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 128);
	if (LOAD32((uint32_t)xmlNodeWriterAddr + 12) != 0) {
		uint64_t node = (uint64_t)stack + 80;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = valuePtr;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = arg5;
		ctx.r8.u64 = arg6;
		ctx.r9.u64 = arg7;
		ctx.r10.u64 = arg8;
		XmlGlobalLock_Enter(ctx, base, node);
		uint8_t nodeType = LOAD8((uint32_t)valuePtr);
		n_sub_82C86918(ctx, base, nodeType, node, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);
		vtable2 = xmlNodeWriter->vtable;
		numberFormat = CXmlNode_GetNumberFormat(ctx, base);
		callTarget.u64 = (uint64_t)LOAD32(vtable2 + 88);
		ctx.r3.u64 = xmlNodeWriterAddr;
		ctx.r4.u64 = attributeName;
		ctx.r5.u64 = numberFormat;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		XmlGlobalLock_Leave(ctx, base);
		attributeName = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = attributeName;
	return 1;
}
PROMOTED_ENTRY(93, sub_82C86F08, 0x82C86F08) { ctx.r3.u64 = n_sub_82C86F08(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C86F88(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint32_t arg2) {
	if (!UseLiftedCode(93, 0x82C86F88)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = arg2; __imp__sub_82C86F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86F88);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t vtable = xmlNodeWriter->vtable;
	uint32_t writeFunc = LOAD32(vtable + 84);
	uint32_t value = LOAD32(arg2);
	uint32_t valuePtr = stack + 80;
	STORE32(valuePtr, value);
	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)writeFunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = valuePtr;
	ctx.r8.u64 = writeFunc;
	ctx.r9.u64 = value;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C86F88, 0x82C86F88) { ctx.r3.u64 = n_sub_82C86F88(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_82C86FC8(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint32_t valuePtr) {
	if (!UseLiftedCode(93, 0x82C86FC8)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = valuePtr; __imp__sub_82C86FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C86FC8);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t value = LOAD32(valuePtr);
	uint32_t vtable = xmlNodeWriter->vtable;
	uint32_t callback = LOAD32(vtable + 0x50);
	STORE32(stack + 80, value);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = (int64_t)(uint64_t)stack + 80;
	ctx.r8.u64 = callback;
	ctx.r9.u64 = value;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callback);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C86FC8, 0x82C86FC8) { ctx.r3.u64 = n_sub_82C86FC8(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_82C87008(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint32_t valuePtr) {
	if (!UseLiftedCode(93, 0x82C87008)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = valuePtr; __imp__sub_82C87008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C87008);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 96);
	// Hand the float value to the callee by pointer through a stack temporary.
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(double(LOAD_F32(valuePtr))));
	uint32_t floatArgAddr = stack + 80;
	uint32_t virtualMethod = LOAD32(xmlNodeWriter->vtable + 76);
	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)virtualMethod;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = floatArgAddr;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C87008, 0x82C87008) { ctx.r3.u64 = n_sub_82C87008(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_82C87040(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t stringId) {
	if (!UseLiftedCode(93, 0x82C87040)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = stringId; __imp__sub_82C87040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C87040);
	GameStackFrame stackFrame(ctx, base, 96);
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	ctx.r4.u64 = stringId;
	uint64_t stringEntry = CStringTable_Find(ctx, base, stringId);
	uint32_t vtableAddress = xmlNodeWriter->vtable;
	uint32_t methodAddress = LOAD32(vtableAddress + 68);
	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = stringEntry;
	ctx.r10.u64 = methodAddress;
	REX_CALL_INDIRECT_FUNC(methodAddress);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C87040, 0x82C87040) { ctx.r3.u64 = n_sub_82C87040(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C87088(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint32_t bytePtr) {
	if (!UseLiftedCode(93, 0x82C87088)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = bytePtr; __imp__sub_82C87088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C87088);
	uint32_t stack = ctx.r1.u64;
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);

	stack = PushStackFrame(base, stack, 96);
	uint32_t vtable = xmlNodeWriter->vtable;
	uint32_t writeFunc = LOAD32(vtable + 64);
	uint8_t value = LOAD8(bytePtr);
	uint32_t valuePtr = stack + 80;
	STORE8(valuePtr, value);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = valuePtr;
	ctx.r8.u64 = writeFunc;
	ctx.r9.u64 = value;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(writeFunc);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C87088, 0x82C87088) { ctx.r3.u64 = n_sub_82C87088(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CXmlNodeWriter_WriteInt(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriter, uint64_t valuePtr, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(93, 0x82C870C8)) { ctx.r3.u64 = xmlNodeWriter; ctx.r4.u64 = valuePtr; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; ctx.r9.u64 = arg5; ctx.r10.u64 = arg6; __imp__sub_82C870C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C870C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Scratch text buffer inside the stack frame.
	uint32_t textBuffer = stack + 80;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = valuePtr;
	ctx.r7.u64 = arg3;
	ctx.r8.u64 = arg4;
	ctx.r9.u64 = arg5;
	ctx.r10.u64 = arg6;
	XmlGlobalLock_Enter(ctx, base, textBuffer);

	uint32_t value = LOAD32((uint32_t)valuePtr);

	CXmlNodeWriter_EnsureBuffer(ctx, base, 16);

	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	// Render the value into the scratch buffer as a decimal number.
	n_sub_82CA3EB8(ctx, base, numberFormat, 16, (uint64_t)(int64_t)-2113926352 /* "%d" */, value, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);

	uint64_t numberFormat2 = CXmlNode_GetNumberFormat(ctx, base);

	// Append the rendered number to the node.
	n_sub_82C86A40(ctx, base, xmlNodeWriter, numberFormat2, 1);

	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C870C8, 0x82C870C8) { ctx.r3.u64 = CXmlNodeWriter_WriteInt(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t CXmlNodeWriter_WriteUInt(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriter, uint64_t valuePtr, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(93, 0x82C87140)) { ctx.r3.u64 = xmlNodeWriter; ctx.r4.u64 = valuePtr; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; ctx.r9.u64 = arg5; ctx.r10.u64 = arg6; __imp__sub_82C87140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C87140);
	uint32_t stack = ctx.r1.u64;
	const uint64_t uintFormat = (uint64_t)(int64_t)-2113243288;

	stack = PushStackFrame(base, stack, 128);
	uint32_t numberWriter = stack + 80;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = valuePtr;
	ctx.r7.u64 = arg3;
	ctx.r8.u64 = arg4;
	ctx.r9.u64 = arg5;
	ctx.r10.u64 = arg6;
	XmlGlobalLock_Enter(ctx, base, numberWriter);

	uint32_t value = LOAD32((uint32_t)valuePtr);
	CXmlNodeWriter_EnsureBuffer(ctx, base, 16);

	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);
	n_sub_82CA3EB8(ctx, base, numberFormat, 16, uintFormat, value, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);

	uint64_t numberFormat2 = CXmlNode_GetNumberFormat(ctx, base);
	n_sub_82C86A40(ctx, base, xmlNodeWriter, numberFormat2, 2);

	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C87140, 0x82C87140) { ctx.r3.u64 = CXmlNodeWriter_WriteUInt(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t CXmlNodeWriter_WriteFloat(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriter, uint32_t valuePtr, uint64_t arg3, uint64_t arg4, uint64_t arg5) {
	if (!UseLiftedCode(93, 0x82C871B8)) { ctx.r3.u64 = xmlNodeWriter; ctx.r4.u64 = valuePtr; ctx.r8.u64 = arg3; ctx.r9.u64 = arg4; ctx.r10.u64 = arg5; __imp__sub_82C871B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C871B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Scratch number-formatting state living in this frame; the formatting helpers take it through r3.
	uint32_t formatState = stack + 80;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = valuePtr;
	ctx.r8.u64 = arg3;
	ctx.r9.u64 = arg4;
	ctx.r10.u64 = arg5;
	XmlGlobalLock_Enter(ctx, base, formatState);

	ctx.fpscr.disableFlushMode();
	float value = LOAD_F32(valuePtr);
	double valueAsDouble = value;
	STORE_F32(stack + 84, value);

	CXmlNodeWriter_EnsureBuffer(ctx, base, 128);

	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	ctx.fpscr.disableFlushMode();
	STORE_F64(stack + 40, valueAsDouble);
	uint64_t valueDoubleBits = LOAD64(stack + 40);
	uint32_t valueFloatBits = LOAD32(stack + 84);
	uint64_t formatString = (uint64_t)(int64_t)-2113869408;
	n_sub_82CA3EB8(ctx, base, numberFormat, 128, formatString, valueDoubleBits, valueFloatBits, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);

	uint64_t numberFormat2 = CXmlNode_GetNumberFormat(ctx, base);
	n_sub_82C86A40(ctx, base, xmlNodeWriter, numberFormat2, 3);

	uint64_t lockLeaveResult = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return lockLeaveResult;
}
PROMOTED_ENTRY(93, sub_82C871B8, 0x82C871B8) { ctx.r3.u64 = CXmlNodeWriter_WriteFloat(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C87260(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriterAddr, uint64_t stringId) {
	if (!UseLiftedCode(93, 0x82C87260)) { ctx.r3.u64 = xmlNodeWriterAddr; ctx.r4.u64 = stringId; __imp__sub_82C87260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C87260);
	uint32_t stack = ctx.r1.u64;
	uint32_t vtable{};
	PPCRegister callTarget{};
	CXmlNodeWriter* xmlNodeWriter = GameObject<CXmlNodeWriter>(base, xmlNodeWriterAddr);
	stack = PushStackFrame(base, stack, 112);
	vtable = xmlNodeWriter->vtable;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = stringId;
	uint64_t stringTable = CStringTable_Find(ctx, base, stringId);
	callTarget.u64 = (uint64_t)LOAD32(vtable + 68);
	ctx.r3.u64 = xmlNodeWriterAddr;
	ctx.r4.u64 = stringTable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(93, sub_82C87260, 0x82C87260) { ctx.r3.u64 = n_sub_82C87260(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlNodeWriter_WriteBool(CpuState& ctx, uint8_t* base, uint64_t xmlNodeWriter, uint32_t valuePtr, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint64_t arg7) {
	constexpr int32_t str_TXT_8200A634_B_ = int32_t(0x8200A634);
	constexpr int32_t str_TXT_8200A63C_B_ = int32_t(0x8200A63C);
	if (!UseLiftedCode(93, 0x82C872B0)) { ctx.r3.u64 = xmlNodeWriter; ctx.r4.u64 = valuePtr; ctx.r6.u64 = arg3; ctx.r7.u64 = arg4; ctx.r8.u64 = arg5; ctx.r9.u64 = arg6; ctx.r10.u64 = arg7; __imp__sub_82C872B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C872B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// The local text buffer object the writer helpers operate on sits at stack + 0x50.
	uint32_t textBuffer = stack + 80;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = valuePtr;
	ctx.r6.u64 = arg3;
	ctx.r7.u64 = arg4;
	ctx.r8.u64 = arg5;
	ctx.r9.u64 = arg6;
	ctx.r10.u64 = arg7;
	XmlGlobalLock_Enter(ctx, base, textBuffer);

	const bool value = LOAD8(valuePtr) != 0;

	CXmlNodeWriter_EnsureBuffer(ctx, base, 16);

	uint64_t numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	uint64_t boolText = value ? (uint64_t)str_TXT_8200A63C_B_ : (uint64_t)str_TXT_8200A634_B_;
	n_sub_82CA3EB8(ctx, base, numberFormat, 16, boolText, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64);

	uint64_t numberFormat2 = CXmlNode_GetNumberFormat(ctx, base);
	n_sub_82C86A40(ctx, base, xmlNodeWriter, numberFormat2, 5);

	uint64_t result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C872B0, 0x82C872B0) { ctx.r3.u64 = CXmlNodeWriter_WriteBool(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t n_sub_82C87598(CpuState& ctx, uint8_t* base, uint64_t nodeWriter, uint64_t source) {
	if (!UseLiftedCode(93, 0x82C87598)) { ctx.r3.u64 = nodeWriter; ctx.r4.u64 = source; __imp__sub_82C87598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C87598);
	uint32_t stack = ctx.r1.u64;
	uint32_t lock{};
	uint32_t node{};
	uint64_t numberFormat{};
	uint64_t result{};

	stack = PushStackFrame(base, stack, 112);
	lock = stack + 80;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = source;
	XmlGlobalLock_Enter(ctx, base, lock);

	node = stack + 84;
	n_sub_82C823D8(ctx, base, node, source);

	n_sub_82C87348(ctx, base, node, lock);

	// GetNumberFormat takes its receiver through r3.
	numberFormat = CXmlNode_GetNumberFormat(ctx, base);

	n_sub_82C86A40(ctx, base, nodeWriter, numberFormat, 4);

	result = XmlGlobalLock_Leave(ctx, base);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C87598, 0x82C87598) { ctx.r3.u64 = n_sub_82C87598(ctx, base, ctx.r3.u64, ctx.r4.u64); }
