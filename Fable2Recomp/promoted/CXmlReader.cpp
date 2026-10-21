// CXmlReader (vtable 0x8200A770): methods of the class as readable C++.
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

uint64_t CXmlReader_GetCurrentTagName(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outText) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	if (!UseLiftedCode(89, 0x82C00D08)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outText; __imp__sub_82C00D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C00D08);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	GameStackFrame stackFrame(ctx, base, 96);

	uint64_t valueForCaller = outText;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode != 0) {
			// A node holds its name at +0 and its text at +4.
			CCharString_Assign(ctx, base, outText, uint64_t(currentNode) + 4);
			return 1;
		}
		if (uint32_t(xmlReader->m_ErrorSink) != 0) {
			uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
			ctx.r3.u64 = xmlReaderAddr;
			ctx.r4.u64 = outText;
			ctx.r9.u64 = beginError;
			ctx.r10.s64 = messagePage;
			REX_CALL_INDIRECT_FUNC(beginError);
			uint64_t errorText = ctx.r3.u64;
			CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
			valueForCaller = ctx.r4.u64;
		}
	}
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C00D08, 0x82C00D08) { ctx.r3.u64 = CXmlReader_GetCurrentTagName(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlReader_BeginError(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t forwardedArg) {
	constexpr int32_t emptyCString = int32_t(0x82000C98);
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A450_B_ = int32_t(0x8200A450);
	constexpr int32_t str_TXT_8200A45C_B_ = int32_t(0x8200A45C);
	constexpr int32_t messageEnd = int32_t(0x8200A468);
	constexpr int32_t str_TXT_8200A470_B_ = int32_t(0x8200A470);
	if (!UseLiftedCode(89, 0x82C00DA0)) { ctx.r3.u64 = xmlReaderAddr; ctx.r6.u64 = forwardedArg; __imp__sub_82C00DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C00DA0);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	GameStackFrame stackFrame(ctx, base, 144);

	uint32_t errorSink = xmlReader->m_ErrorSink;
	if (errorSink == 0 || uint32_t(xmlReader->m_Document) == 0) {
		// Without an error sink or a document the message goes to the reader's own holder at +24.
		return xmlReaderAddr + 24;
	}
	ctx.r6.u64 = forwardedArg;
	CXmlReader_SetErrorMessage(ctx, base, errorSink, emptyCString);
	bool carry = ctx.xer.ca;
	uint32_t currentNode = LOAD32(uint32_t(xmlReader->m_Document) + 8);
	if (currentNode == 0) {
		STORE32(uint32_t(xmlReader->m_ErrorSink) + 8, 0u);
		return uint32_t(xmlReader->m_ErrorSink);
	}

	// Line and character of the node's offset (+16) in the reader's text (+32).
	STORE32(uint32_t(xmlReader->m_ErrorSink) + 8, LOAD32(currentNode + 16));
	uint32_t remaining = LOAD32(uint32_t(xmlReader->m_ErrorSink) + 8);
	uint32_t textPtr = CharString_GetCStr(ctx, base, uint32_t(xmlReaderAddr) + 32);
	uint64_t lineNumber = 1;
	uint64_t charNumber = 1;
	while (remaining != 0) {
		int8_t ch = int8_t(LOAD8(textPtr));
		if (ch == 13) {
			lineNumber++;
			charNumber = 1;
		} else if (ch != 10) {
			charNumber++;
		}
		// The count-down sets the carry, which the original still has in XER at the next call.
		carry = TXT_8200A63C_L_;
		remaining--;
		textPtr++;
	}

	uint32_t sinkForText = xmlReader->m_ErrorSink;
	uint32_t nodeForName = LOAD32(uint32_t(xmlReader->m_Document) + 8);
	ctx.r8.s64 = messagePage;
	ctx.xer.ca = carry;
	uint64_t withLinePrefix = CharStringHolder_ConstructFromCString(ctx, base, sinkForText, str_TXT_8200A470_B_);
	uint64_t withLine = CCharString_FormatInt(ctx, base, withLinePrefix, lineNumber, ctx.r6.u64);
	uint64_t withCharPrefix = CharStringHolder_ConstructFromCString(ctx, base, withLine, str_TXT_8200A450_B_);
	uint64_t withChar = CCharString_FormatInt(ctx, base, withCharPrefix, charNumber, ctx.r6.u64);
	uint64_t withTagPrefix = CharStringHolder_ConstructFromCString(ctx, base, withChar, str_TXT_8200A45C_B_);
	uint64_t withTagName = RefCountedStringHolder_Assign(ctx, base, withTagPrefix, nodeForName);
	CharStringHolder_ConstructFromCString(ctx, base, withTagName, messageEnd);
	return uint32_t(xmlReader->m_ErrorSink);
}
PROMOTED_ENTRY(89, sub_82C00DA0, 0x82C00DA0) { ctx.r3.u64 = CXmlReader_BeginError(ctx, base, ctx.r3.u64, ctx.r6.u64); }

uint64_t CXmlReader_ReadInt(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outValue, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3, uint64_t forwardedArg4) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A494_B_ = int32_t(0x8200A494);
	constexpr int32_t str_TXT_8200A4BC_B_ = int32_t(0x8200A4BC);
	constexpr int32_t str_TXT_8200A4C4_B_ = int32_t(0x8200A4C4);
	constexpr int32_t str_TXT_8200A4A8_B_ = int32_t(0x8200A4A8);
	if (!UseLiftedCode(89, 0x82C013C8)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outValue; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; ctx.r10.u64 = forwardedArg4; __imp__sub_82C013C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C013C8);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	const uint32_t trailingText = stack + 80;

	uint64_t valueForCaller = outValue;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode == 0) {
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
				valueForCaller = ctx.r4.u64;
			}
		} else {
			// A node holds its name at +0 and its text at +4.
			uint64_t nodeText = uint64_t(currentNode) + 4;
			uint32_t textData = LOAD32(currentNode + 4);
			if (textData != 0 && int32_t(LOAD32(textData + 4)) != 0) {
				ctx.r1.u64 = stack;
				uint64_t text = CharString_GetCStr(ctx, base, nodeText);
				// Exactly one field converted: nothing follows the number.
				uint32_t fieldsConverted = String_ScanFormatted(ctx, base, text, str_TXT_8200A4BC_B_, outValue, trailingText, forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4);
				uint64_t result = 1;
				if (int32_t(fieldsConverted) != 1) {
					result = 0;
					if (uint32_t(xmlReader->m_ErrorSink) != 0) {
						uint32_t nodeAfterScan = LOAD32(uint32_t(xmlReader->m_Document) + 8);
						uint32_t vtable = xmlReader->vtable;
						uint32_t beginError = LOAD32(vtable + 64);
						ctx.r3.u64 = xmlReaderAddr;
						ctx.r7.u64 = beginError;
						ctx.r8.s64 = messagePage;
						ctx.r9.u64 = vtable;
						ctx.r10.s64 = messagePage;
						REX_CALL_INDIRECT_FUNC(beginError);
						uint64_t errorText = ctx.r3.u64;
						uint64_t withPrefix = CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A494_B_);
						uint64_t withText = RefCountedStringHolder_Assign(ctx, base, withPrefix, uint64_t(nodeAfterScan) + 4);
						CharStringHolder_ConstructFromCString(ctx, base, withText, str_TXT_8200A4A8_B_);
					}
				}
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return result;
			}
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A4C4_B_);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C013C8, 0x82C013C8) { ctx.r3.u64 = CXmlReader_ReadInt(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t CXmlReader_ReadUInt16(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outValue, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3, uint64_t forwardedArg4) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A494_B_ = int32_t(0x8200A494);
	constexpr int32_t str_TXT_8200A510_B_ = int32_t(0x8200A510);
	constexpr int32_t str_TXT_8200A4C4_B_ = int32_t(0x8200A518);
	constexpr int32_t str_TXT_8200A4F4_B_ = int32_t(0x8200A4F4);
	if (!UseLiftedCode(89, 0x82C01518)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outValue; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; ctx.r10.u64 = forwardedArg4; __imp__sub_82C01518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C01518);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	const uint32_t trailingText = stack + 80;

	uint64_t valueForCaller = outValue;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode == 0) {
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
				valueForCaller = ctx.r4.u64;
			}
		} else {
			// A node holds its name at +0 and its text at +4.
			uint64_t nodeText = uint64_t(currentNode) + 4;
			uint32_t textData = LOAD32(currentNode + 4);
			if (textData != 0 && int32_t(LOAD32(textData + 4)) != 0) {
				ctx.r1.u64 = stack;
				uint64_t text = CharString_GetCStr(ctx, base, nodeText);
				// Exactly one field converted: nothing follows the number.
				uint32_t fieldsConverted = String_ScanFormatted(ctx, base, text, str_TXT_8200A510_B_, outValue, trailingText, forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4);
				uint64_t result = 1;
				if (int32_t(fieldsConverted) != 1) {
					result = 0;
					if (uint32_t(xmlReader->m_ErrorSink) != 0) {
						uint32_t nodeAfterScan = LOAD32(uint32_t(xmlReader->m_Document) + 8);
						uint32_t vtable = xmlReader->vtable;
						uint32_t beginError = LOAD32(vtable + 64);
						ctx.r3.u64 = xmlReaderAddr;
						ctx.r7.u64 = beginError;
						ctx.r8.s64 = messagePage;
						ctx.r9.u64 = vtable;
						ctx.r10.s64 = messagePage;
						REX_CALL_INDIRECT_FUNC(beginError);
						uint64_t errorText = ctx.r3.u64;
						uint64_t withPrefix = CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A494_B_);
						uint64_t withText = RefCountedStringHolder_Assign(ctx, base, withPrefix, uint64_t(nodeAfterScan) + 4);
						CharStringHolder_ConstructFromCString(ctx, base, withText, str_TXT_8200A4F4_B_);
					}
				}
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return result;
			}
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A4C4_B_);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C01518, 0x82C01518) { ctx.r3.u64 = CXmlReader_ReadUInt16(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t CXmlReader_ReadInt16(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outValue, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3, uint64_t forwardedArg4) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A494_B_ = int32_t(0x8200A494);
	constexpr int32_t str_TXT_8200A568_B_ = int32_t(0x8200A568);
	constexpr int32_t str_TXT_8200A4C4_B_ = int32_t(0x8200A570);
	constexpr int32_t str_TXT_8200A550_B_ = int32_t(0x8200A550);
	if (!UseLiftedCode(89, 0x82C01668)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outValue; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; ctx.r10.u64 = forwardedArg4; __imp__sub_82C01668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C01668);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	const uint32_t trailingText = stack + 80;

	uint64_t valueForCaller = outValue;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode == 0) {
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
				valueForCaller = ctx.r4.u64;
			}
		} else {
			// A node holds its name at +0 and its text at +4.
			uint64_t nodeText = uint64_t(currentNode) + 4;
			uint32_t textData = LOAD32(currentNode + 4);
			if (textData != 0 && int32_t(LOAD32(textData + 4)) != 0) {
				ctx.r1.u64 = stack;
				uint64_t text = CharString_GetCStr(ctx, base, nodeText);
				// Exactly one field converted: nothing follows the number.
				uint32_t fieldsConverted = String_ScanFormatted(ctx, base, text, str_TXT_8200A568_B_, outValue, trailingText, forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4);
				uint64_t result = 1;
				if (int32_t(fieldsConverted) != 1) {
					result = 0;
					if (uint32_t(xmlReader->m_ErrorSink) != 0) {
						uint32_t nodeAfterScan = LOAD32(uint32_t(xmlReader->m_Document) + 8);
						uint32_t vtable = xmlReader->vtable;
						uint32_t beginError = LOAD32(vtable + 64);
						ctx.r3.u64 = xmlReaderAddr;
						ctx.r7.u64 = beginError;
						ctx.r8.s64 = messagePage;
						ctx.r9.u64 = vtable;
						ctx.r10.s64 = messagePage;
						REX_CALL_INDIRECT_FUNC(beginError);
						uint64_t errorText = ctx.r3.u64;
						uint64_t withPrefix = CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A494_B_);
						uint64_t withText = RefCountedStringHolder_Assign(ctx, base, withPrefix, uint64_t(nodeAfterScan) + 4);
						CharStringHolder_ConstructFromCString(ctx, base, withText, str_TXT_8200A550_B_);
					}
				}
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return result;
			}
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A4C4_B_);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C01668, 0x82C01668) { ctx.r3.u64 = CXmlReader_ReadInt16(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint64_t CXmlReader_ReadUInt8(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outValue, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A494_B_ = int32_t(0x8200A494);
	constexpr int32_t str_TXT_8200A510_B_ = int32_t(0x8200A510);
	constexpr int32_t str_TXT_8200A4C4_B_ = int32_t(0x8200A570);
	constexpr int32_t str_TXT_8200A5A4_B_ = int32_t(0x8200A5A4);
	if (!UseLiftedCode(89, 0x82C017B8)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outValue; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82C017B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C017B8);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);
	const uint32_t parsedValueSlot = stack + 80;
	const uint32_t trailingText = stack + 82;

	uint64_t valueForCaller = outValue;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode == 0) {
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
				valueForCaller = ctx.r4.u64;
			}
		} else {
			// A node holds its name at +0 and its text at +4.
			uint32_t textData = LOAD32(currentNode + 4);
			if (textData != 0 && int32_t(LOAD32(textData + 4)) != 0) {
				STORE16(parsedValueSlot, 0);
				uint32_t nodeToParse = LOAD32(document + 8);
				ctx.r1.u64 = stack;
				uint64_t text = CharString_GetCStr(ctx, base, uint64_t(nodeToParse) + 4);
				// Exactly one field converted: nothing follows the number.
				uint32_t fieldsConverted = String_ScanFormatted(ctx, base, text, str_TXT_8200A510_B_, parsedValueSlot, trailingText, forwardedArg1, forwardedArg2, messagePage, 0);
				uint64_t result = 1;
				if (int32_t(fieldsConverted) != 1) {
					result = 0;
					if (uint32_t(xmlReader->m_ErrorSink) != 0) {
						uint32_t nodeAfterScan = LOAD32(uint32_t(xmlReader->m_Document) + 8);
						uint32_t vtable = xmlReader->vtable;
						uint32_t beginError = LOAD32(vtable + 64);
						ctx.r3.u64 = xmlReaderAddr;
						ctx.r7.u64 = beginError;
						ctx.r8.s64 = messagePage;
						ctx.r9.u64 = vtable;
						ctx.r10.s64 = messagePage;
						REX_CALL_INDIRECT_FUNC(beginError);
						uint64_t errorText = ctx.r3.u64;
						uint64_t withPrefix = CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A494_B_);
						uint64_t withText = RefCountedStringHolder_Assign(ctx, base, withPrefix, uint64_t(nodeAfterScan) + 4);
						CharStringHolder_ConstructFromCString(ctx, base, withText, str_TXT_8200A5A4_B_);
					}
				} else {
					uint32_t parsedValue = LOAD16(parsedValueSlot);
					if (parsedValue > 255)
						parsedValue = 255;
					STORE8(uint32_t(outValue), uint8_t(parsedValue));
				}
				stack = PopStackFrame(stack, 144);
				ctx.r1.u64 = stack;
				return result;
			}
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A4C4_B_);
				stack = PopStackFrame(stack, 144);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C017B8, 0x82C017B8) { ctx.r3.u64 = CXmlReader_ReadUInt8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CXmlReader_ReadFloat(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outValue, uint64_t forwardedArg) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A4C4_B_ = int32_t(0x8200A5BC);
	if (!UseLiftedCode(89, 0x82C01930)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outValue; ctx.r8.u64 = forwardedArg; __imp__sub_82C01930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C01930);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	GameStackFrame stackFrame(ctx, base, 96);

	uint64_t valueForCaller = outValue;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode == 0) {
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r8.u64 = forwardedArg;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
				valueForCaller = ctx.r4.u64;
			}
		} else {
			// A node holds its name at +0 and its text at +4.
			uint32_t nodeText = currentNode + 4;
			uint32_t textData = LOAD32(nodeText);
			uint32_t textLength = 0;
			if (textData != 0)
				textLength = LOAD32(textData + 4);
			if (int32_t(textLength) != 0) {
				uint64_t text = CharString_GetCStr(ctx, base, nodeText);
				ctx.r4.u64 = outValue;
				ctx.r10.u64 = textLength;
				String_ParseFloat(ctx, base, text, forwardedArg);
				double parsed = ctx.f1.f64;
				ctx.fpscr.disableFlushMode();
				STORE_F32(uint32_t(outValue), float(parsed));
				return 1;
			}
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r8.u64 = forwardedArg;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A4C4_B_);
				return 0;
			}
		}
	}
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C01930, 0x82C01930) { ctx.r3.u64 = CXmlReader_ReadFloat(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CXmlReader_ReadBool(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outValue) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t emptyCString = int32_t(0x8209003F);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A5E8_B_ = int32_t(0x8200A5E8);
	constexpr int32_t str_TXT_8200A5FC_B_ = int32_t(0x8200A5FC);
	constexpr int32_t str_TXT_8200A634_B_ = int32_t(0x8200A634);
	constexpr int32_t str_TXT_8200A63C_B_ = int32_t(0x8200A63C);
	constexpr int32_t str_TXT_8200A4C4_B_ = int32_t(0x8200A644);
	constexpr int32_t str_TXT_820E9E90_B_ = int32_t(0x820E9E90);
	constexpr int32_t str_TXT_820E9E94_B_ = int32_t(0x820E9E94);
	if (!UseLiftedCode(89, 0x82C01A30)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outValue; __imp__sub_82C01A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C01A30);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	GameStackFrame stackFrame(ctx, base, 128);

	uint64_t valueForCaller = outValue;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode == 0) {
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
				valueForCaller = ctx.r4.u64;
			}
		} else {
			// A node holds its name at +0 and its text at +4.
			uint64_t nodeText = uint64_t(currentNode) + 4;
			uint32_t textData = LOAD32(currentNode + 4);
			if (textData != 0 && int32_t(LOAD32(textData + 4)) != 0) {
				// The characters of the text (the empty C string when it has no data), read again before each comparison.
				auto textChars = [&]() -> uint64_t {
					uint32_t data = LOAD32(uint32_t(nodeText));
					return data != 0 ? uint64_t(LOAD32(data)) : uint64_t(int64_t(emptyCString));
				};
				if (int32_t(stricmp(ctx, base, textChars(), str_TXT_820E9E90_B_)) == 0 || int32_t(stricmp(ctx, base, textChars(), str_TXT_8200A63C_B_)) == 0) {
					STORE8(uint32_t(outValue), uint8_t(1));
					return 1;
				}
				if (int32_t(stricmp(ctx, base, textChars(), str_TXT_820E9E94_B_)) == 0 || int32_t(stricmp(ctx, base, textChars(), str_TXT_8200A634_B_)) == 0) {
					STORE8(uint32_t(outValue), uint8_t(0));
					return 1;
				}
				if (uint32_t(xmlReader->m_ErrorSink) != 0) {
					uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
					ctx.r3.u64 = xmlReaderAddr;
					ctx.r8.u64 = beginError;
					ctx.r9.s64 = messagePage;
					ctx.r10.s64 = messagePage;
					REX_CALL_INDIRECT_FUNC(beginError);
					uint64_t errorText = ctx.r3.u64;
					uint64_t withPrefix = CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A5E8_B_);
					uint64_t withText = RefCountedStringHolder_Assign(ctx, base, withPrefix, nodeText);
					CharStringHolder_ConstructFromCString(ctx, base, withText, str_TXT_8200A5FC_B_);
				}
				return 0;
			}
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A4C4_B_);
				return 0;
			}
		}
	}
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C01A30, 0x82C01A30) { ctx.r3.u64 = CXmlReader_ReadBool(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlReader_ReadUInt(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t outValue, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3, uint64_t forwardedArg4) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A494_B_ = int32_t(0x8200A494);
	constexpr int32_t str_TXT_8200A478_B_ = int32_t(0x8200A478);
	constexpr int32_t str_TXT_8200A4C4_B_ = int32_t(0x8200A4C4);
	constexpr int32_t str_TXT_8200A66C_B_ = int32_t(0x8200A66C);
	if (!UseLiftedCode(89, 0x82C01C10)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = outValue; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; ctx.r10.u64 = forwardedArg4; __imp__sub_82C01C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C01C10);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	const uint32_t trailingText = stack + 80;

	uint64_t valueForCaller = outValue;
	uint32_t document = xmlReader->m_Document;
	if (document != 0) {
		uint32_t currentNode = LOAD32(document + 8);
		if (currentNode == 0) {
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
				valueForCaller = ctx.r4.u64;
			}
		} else {
			// A node holds its name at +0 and its text at +4.
			uint64_t nodeText = uint64_t(currentNode) + 4;
			uint32_t textData = LOAD32(currentNode + 4);
			if (textData != 0 && int32_t(LOAD32(textData + 4)) != 0) {
				ctx.r1.u64 = stack;
				uint64_t text = CharString_GetCStr(ctx, base, nodeText);
				// Exactly one field converted: nothing follows the number.
				uint32_t fieldsConverted = String_ScanFormatted(ctx, base, text, str_TXT_8200A478_B_, outValue, trailingText, forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4);
				uint64_t result = 1;
				if (int32_t(fieldsConverted) != 1) {
					result = 0;
					if (uint32_t(xmlReader->m_ErrorSink) != 0) {
						uint32_t nodeAfterScan = LOAD32(uint32_t(xmlReader->m_Document) + 8);
						uint32_t vtable = xmlReader->vtable;
						uint32_t beginError = LOAD32(vtable + 64);
						ctx.r3.u64 = xmlReaderAddr;
						ctx.r7.u64 = beginError;
						ctx.r8.s64 = messagePage;
						ctx.r9.u64 = vtable;
						ctx.r10.s64 = messagePage;
						REX_CALL_INDIRECT_FUNC(beginError);
						uint64_t errorText = ctx.r3.u64;
						uint64_t withPrefix = CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A494_B_);
						uint64_t withText = RefCountedStringHolder_Assign(ctx, base, withPrefix, uint64_t(nodeAfterScan) + 4);
						CharStringHolder_ConstructFromCString(ctx, base, withText, str_TXT_8200A66C_B_);
					}
				}
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return result;
			}
			if (uint32_t(xmlReader->m_ErrorSink) != 0) {
				uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = xmlReaderAddr;
				ctx.r4.u64 = outValue;
				ctx.r7.u64 = forwardedArg1;
				ctx.r8.u64 = forwardedArg2;
				ctx.r9.u64 = beginError;
				ctx.r10.s64 = messagePage;
				REX_CALL_INDIRECT_FUNC(beginError);
				uint64_t errorText = ctx.r3.u64;
				CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A4C4_B_);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = valueForCaller;
	return 0;
}
PROMOTED_ENTRY(89, sub_82C01C10, 0x82C01C10) { ctx.r3.u64 = CXmlReader_ReadUInt(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.r10.u64); }

uint32_t CXmlReader_Dtor(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr) {
	constexpr uint32_t CXmlReader_vtable = 0x8200A770u;
	if (!UseLiftedCode(89, 0x82C02B20)) { ctx.r3.u64 = xmlReaderAddr; __imp__sub_82C02B20(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C02B20);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	GameStackFrame stackFrame(ctx, base, 96);

	uint32_t document = xmlReader->m_Document;
	xmlReader->vtable = CXmlReader_vtable;
	if (document != 0) {
		uint32_t documentVtable = LOAD32(document);
		uint32_t method = LOAD32(documentVtable + 16);
		ctx.r3.u64 = document;
		ctx.r4.u64 = 1;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		xmlReader->m_Document = 0u;
	}
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, xmlReaderAddr + 32);
	CharStringHolder_Destructor(ctx, base, xmlReaderAddr + 24);
	return C_8200A718_Dtor(ctx, base, xmlReaderAddr);
}
PROMOTED_ENTRY(89, sub_82C02B20, 0x82C02B20) { ctx.r3.u64 = CXmlReader_Dtor(ctx, base, ctx.r3.u64); }

uint64_t CXmlReader_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(89, 0x82C03300)) { ctx.r3.u64 = xmlReaderAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82C03300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C03300);
	GameStackFrame stackFrame(ctx, base, 112);

	ctx.r4.u64 = deleteFlags;
	CXmlReader_Dtor(ctx, base, xmlReaderAddr);
	if ((deleteFlags & 1) != 0)
		HandleTarget_FreeThunk(ctx, base, xmlReaderAddr);
	return xmlReaderAddr;
}
PROMOTED_ENTRY(89, sub_82C03300, 0x82C03300) { ctx.r3.u64 = CXmlReader_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CXmlReader_PopTag(CpuState& ctx, uint8_t* base, uint64_t xmlReaderAddr) {
	constexpr int32_t messagePage = int32_t(0x82010000);
	constexpr int32_t messageEndPage = int32_t(0x820E0000);
	constexpr int32_t str_TXT_8200A414_B_ = int32_t(0x8200A414);
	constexpr int32_t str_TXT_8200A880_B_ = int32_t(0x8200A880);
	constexpr int32_t messageEnd = int32_t(0x820DCDEC);
	if (!UseLiftedCode(89, 0x82C038F0)) { ctx.r3.u64 = xmlReaderAddr; __imp__sub_82C038F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C038F0);
	CXmlReader* xmlReader = GameObject<CXmlReader>(base, xmlReaderAddr);
	GameStackFrame stackFrame(ctx, base, 128);

	uint32_t document = xmlReader->m_Document;
	if (document == 0)
		return 0;
	uint32_t currentNode = LOAD32(document + 8);
	if (currentNode == 0) {
		if (uint32_t(xmlReader->m_ErrorSink) != 0) {
			uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
			ctx.r3.u64 = xmlReaderAddr;
			ctx.r9.u64 = beginError;
			ctx.r10.s64 = messagePage;
			REX_CALL_INDIRECT_FUNC(beginError);
			uint64_t errorText = ctx.r3.u64;
			CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A414_B_);
		}
		return 0;
	}

	// A node that still has children (its list at +32) is not left unless the reader allows it.
	if (xmlReader->m_AllowPopWithChildren == 0) {
		uint32_t childList = LOAD32(currentNode + 32);
		if (childList != 0) {
			uint32_t lastEntry = IntrusiveList_GetLast(ctx, base, childList + 4);
			if (lastEntry != 0 && LOAD32(lastEntry) != 0) {
				if (uint32_t(xmlReader->m_ErrorSink) != 0) {
					uint32_t lastEntryNow = IntrusiveList_GetLast(ctx, base, LOAD32(currentNode + 32) + 4);
					uint32_t lastChild = 0;
					if (lastEntryNow != 0)
						lastChild = LOAD32(lastEntryNow);
					uint32_t beginError = LOAD32(uint32_t(xmlReader->vtable) + 64);
					ctx.r3.u64 = xmlReaderAddr;
					ctx.r8.u64 = beginError;
					ctx.r9.s64 = messagePage;
					ctx.r10.s64 = messageEndPage;
					REX_CALL_INDIRECT_FUNC(beginError);
					uint64_t errorText = ctx.r3.u64;
					uint64_t withPrefix = CharStringHolder_ConstructFromCString(ctx, base, errorText, str_TXT_8200A880_B_);
					uint64_t withChildName = RefCountedStringHolder_Assign(ctx, base, withPrefix, lastChild);
					CharStringHolder_ConstructFromCString(ctx, base, withChildName, messageEnd);
				}
				return 0;
			}
		}
	}

	// Leave the tag: the current node becomes the node linked at its +12 (the one CXmlReader_PushTag entered it
	// from), the root at +4 is cleared when it is the node left, and the node left is destroyed.
	uint32_t documentNow = xmlReader->m_Document;
	uint32_t parentNode = LOAD32(LOAD32(documentNow + 8) + 12);
	STORE32(documentNow + 8, parentNode);
	uint32_t documentAfter = xmlReader->m_Document;
	uint32_t rootNode = LOAD32(documentAfter + 4);
	if (currentNode == rootNode)
		STORE32(documentAfter + 4, 0u);
	ctx.r7.u64 = rootNode;
	ctx.r8.u64 = documentAfter;
	ctx.r9.u64 = parentNode;
	CXmlNode_Dtor(ctx, base, currentNode);
	HandleTarget_FreeThunk(ctx, base, currentNode);
	return 1;
}
PROMOTED_ENTRY(89, sub_82C038F0, 0x82C038F0) { ctx.r3.u64 = CXmlReader_PopTag(ctx, base, ctx.r3.u64); }
