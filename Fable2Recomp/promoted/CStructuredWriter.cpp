// CStructuredWriter (vtable 0x8200E898): methods of the class as readable C++.
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

uint64_t CStructuredWriter_EndElement(CpuState& ctx, uint8_t* base, uint64_t structuredWriterAddr) {
	if (!UseLiftedCode(93, 0x82C829F0)) { ctx.r3.u64 = structuredWriterAddr; __imp__sub_82C829F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C829F0);
	uint32_t stack = ctx.r1.u64;
	CStructuredWriter* writer = GameObject<CStructuredWriter>(base, structuredWriterAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t writerAddr = (uint32_t)structuredWriterAddr;
	const uint32_t isOpenAddr = writerAddr + 20;
	uint64_t result = structuredWriterAddr;

	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	if (writer->m_depth != 0) {
		const uint64_t nodeAddr = structuredWriterAddr + 16;
		const uint8_t endTag = 1;

		if (LOAD8(isOpenAddr) != 0) {
			STORE8(stack + 80, endTag);
			ctx.r1.u64 = stack;
			result = CStructuredWriter_Write(ctx, base, nodeAddr, (uint64_t)(stack + 80));
			STORE8(isOpenAddr, (uint8_t)result);
		}

		const uint32_t depth = writer->m_depth;
		flags.ca = depth > 0;
		const int32_t newDepth = (int32_t)depth - 1;
		compare0.compare<int32_t>(newDepth, 0, flags);
		writer->m_inElement = 0;
		writer->m_depth = newDepth;

		if (newDepth == 0) {
			if (LOAD8(isOpenAddr) != 0) {
				STORE8(stack + 81, 5);
				ctx.r1.u64 = stack;
				ctx.cr0.lt = compare0.lt;
				ctx.cr0.gt = compare0.gt;
				ctx.cr0.eq = compare0.eq;
				ctx.cr0.so = compare0.so;
				ctx.xer.ca = flags.ca;
				result = CStructuredWriter_Write(ctx, base, nodeAddr, (uint64_t)(stack + 81));
				compare0.lt = ctx.cr0.lt;
				compare0.gt = ctx.cr0.gt;
				compare0.eq = ctx.cr0.eq;
				compare0.so = ctx.cr0.so;
				flags.ca = ctx.xer.ca;
				STORE8(isOpenAddr, (uint8_t)result);
			}
			writer->m_9 = endTag;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(93, sub_82C829F0, 0x82C829F0) { ctx.r3.u64 = CStructuredWriter_EndElement(ctx, base, ctx.r3.u64); }

uint64_t CStructuredWriter_Destroy(CpuState& ctx, uint8_t* base, uint64_t structuredWriterAddr, uint64_t arg2) {
	if (!UseLiftedCode(93, 0x82C831B0)) { ctx.r3.u64 = structuredWriterAddr; ctx.r4.u64 = arg2; __imp__sub_82C831B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C831B0);
	uint32_t stack = ctx.r1.u64;
	uint32_t deletionFlags = arg2;
	CStructuredWriter* structuredWriter = GameObject<CStructuredWriter>(base, structuredWriterAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t listAddr = structuredWriterAddr + 24;
	structuredWriter->vtable = 0x8200E898u;
	ctx.r1.u64 = stack;
	Container_Destruct(ctx, base, listAddr);
	uint32_t referencedObject = structuredWriter->m_10;
	if (referencedObject != 0) {
		uint32_t destroyFn = LOAD32(LOAD32(referencedObject) + 8);
		ctx.r3.u64 = referencedObject;
		ctx.r10.u64 = destroyFn;
		REX_CALL_INDIRECT_FUNC(destroyFn);
	}
	C_8200E9A8_Destruct(ctx, base, structuredWriterAddr);
	if ((deletionFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, structuredWriterAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return structuredWriterAddr;
}
PROMOTED_ENTRY(93, sub_82C831B0, 0x82C831B0) { ctx.r3.u64 = CStructuredWriter_Destroy(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CStructuredWriter_BeginElement(CpuState& ctx, uint8_t* base, uint64_t structuredWriterAddr, uint64_t elementName, uint64_t arg3) {
	if (!UseLiftedCode(93, 0x82C835E8)) { ctx.r3.u64 = structuredWriterAddr; ctx.r4.u64 = elementName; ctx.r8.u64 = arg3; __imp__sub_82C835E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C835E8);
	uint32_t stack = ctx.r1.u64;
	CStructuredWriter* structuredWriter = GameObject<CStructuredWriter>(base, structuredWriterAddr);
	stack = PushStackFrame(base, stack, 208);

	// The low-level element writer lives inside the structured writer at +0x10.
	uint64_t writerAddr = structuredWriterAddr + 16;

	if (structuredWriter->m_result != 0) {
		STORE8(stack + 80, 0);
		ctx.r1.u64 = stack;
		uint32_t writeResult = CStructuredWriter_Write(ctx, base, writerAddr, (uint64_t)stack + 80);
		arg3 = ctx.r8.u64;
		structuredWriter->m_result = (uint8_t)writeResult;
	}

	uint32_t nameLength = 0;
	for (uint32_t cursor = (uint32_t)elementName; LOAD8(cursor) != 0; ++cursor)
		++nameLength;

	// Two temporary strings are built in the frame: the one at stack+128 is filled
	// with elementName, the one at stack+96 becomes a copy of it. Layout:
	// {buffer/pointer at +4, length at +20, capacity at +24}.
	STORE32(stack + 148, 0);
	STORE8(stack + 132, 0);
	STORE32(stack + 152, 15);
	ctx.r1.u64 = stack;
	BasicString_AssignPtrLen(ctx, base, (uint64_t)stack + 128, elementName, nameLength, arg3);

	STORE32(stack + 120, 15);
	STORE32(stack + 116, 0);
	STORE8(stack + 100, 0);
	BasicString_AssignSubstr(ctx, base, (uint64_t)stack + 96, (uint64_t)stack + 128, 0, -1, ctx.r8.u64);

	if (structuredWriter->m_result != 0) {
		uint32_t writeResult = CStructuredWriter_WriteString(ctx, base, (uint64_t)stack + 96, writerAddr, ctx.r8.u64);
		structuredWriter->m_result = (uint8_t)writeResult;
	}

	if (LOAD32(stack + 120) >= 16)
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 100));

	uint32_t copyCapacity = LOAD32(stack + 152);
	STORE32(stack + 120, 15);
	STORE32(stack + 116, 0);
	STORE8(stack + 100, 0);
	if (copyCapacity >= 16)
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 132));

	uint64_t result = structuredWriter->m_result;
	uint32_t newDepth = structuredWriter->m_depth + 1;
	structuredWriter->m_inElement = 1;
	structuredWriter->m_depth = newDepth;

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C835E8, 0x82C835E8) { ctx.r3.u64 = CStructuredWriter_BeginElement(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CStructuredWriter_WriteInt32(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint32_t valuePtr) {
	if (!UseLiftedCode(93, 0x82C83780)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valuePtr; __imp__sub_82C83780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83780);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	stack = PushStackFrame(base, stack, 128);

	const uint32_t intValue = LOAD32(valuePtr);
	const uint32_t typeTag = 3;
	const uint32_t valueObject = stack + 80;

	// Temporary value object: type tag, embedded empty string, int32 payload.
	STORE32(valueObject + 24, 0u);
	STORE32(valueObject + 28, 15u);
	STORE8(valueObject + 8, 0);
	STORE32(valueObject + 32, intValue);
	STORE32(valueObject + 0, typeTag);

	ctx.r1.u64 = stack;
	result = CStructuredWriter_WriteValue(ctx, base, structuredWriter, valueObject, typeTag);
	if (LOAD32(valueObject + 28) >= 16) {
		const uint32_t heapBuffer = LOAD32(valueObject + 8);
		result = HandleTarget_FreeThunk(ctx, base, heapBuffer);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83780, 0x82C83780) { ctx.r3.u64 = CStructuredWriter_WriteInt32(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CStructuredWriter_WriteUInt32(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint32_t valuePtr) {
	if (!UseLiftedCode(93, 0x82C837E0)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valuePtr; __imp__sub_82C837E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C837E0);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	stack = PushStackFrame(base, stack, 128);
	uint32_t value = LOAD32(valuePtr);
	STORE32(stack + 104, 0);
	STORE32(stack + 108, 15u);
	uint64_t valueObject = (uint64_t)stack + 80;
	STORE8(stack + 88, 0);
	STORE32(stack + 112, value);
	STORE32(stack + 80, 2);
	ctx.r1.u64 = stack;
	result = CStructuredWriter_WriteValue(ctx, base, structuredWriter, valueObject, 2);
	if (LOAD32(stack + 108) >= 16) {
		uint32_t heapBuffer = LOAD32(stack + 88);
		result = HandleTarget_FreeThunk(ctx, base, heapBuffer);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C837E0, 0x82C837E0) { ctx.r3.u64 = CStructuredWriter_WriteUInt32(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CStructuredWriter_WriteBool(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint32_t valuePtr) {
	if (!UseLiftedCode(93, 0x82C83840)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valuePtr; __imp__sub_82C83840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83840);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	uint32_t scratchPtr{};
	uint32_t valueBox{};
	uint32_t typeTag{};
	uint32_t boolValue{};

	stack = PushStackFrame(base, stack, 128);

	boolValue = LOAD8(valuePtr);
	typeTag = 5;

	// Build a small tagged value box (type 5 = bool) on the stack.
	STORE32(stack + 104, 0);
	STORE32(stack + 108, 15u);
	valueBox = stack + 80;
	STORE8(stack + 88, 0);
	STORE8(stack + 112, (uint8_t)boolValue);
	STORE32(stack + 80, typeTag);

	ctx.r1.u64 = stack;
	result = CStructuredWriter_WriteValue(ctx, base, structuredWriter, valueBox, typeTag);

	if (LOAD32(stack + 108) >= 16) {
		scratchPtr = LOAD32(stack + 88);
		result = HandleTarget_FreeThunk(ctx, base, scratchPtr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83840, 0x82C83840) { ctx.r3.u64 = CStructuredWriter_WriteBool(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CStructuredWriter_WriteFloat(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint32_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(93, 0x82C838A0)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_82C838A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C838A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.fpscr.disableFlushMode();

	// Tagged value: type tag 4, a default-constructed (empty, SSO) string, and the float payload.
	uint64_t valuePtr = (int64_t)(uint64_t)stack + 80;

	STORE_F32(stack + 112, float(double(LOAD_F32(arg2))));
	STORE32(stack + 104, 0);
	STORE32(stack + 108, 15u);
	STORE8(stack + 88, 0);
	STORE32(stack + 80, 4u);

	ctx.r1.u64 = stack;
	uint64_t result = CStructuredWriter_WriteValue(ctx, base, structuredWriter, valuePtr, arg3);
	if (LOAD32(stack + 108) >= 16) {
		uint32_t stringBuffer = LOAD32(stack + 88);
		result = HandleTarget_FreeThunk(ctx, base, stringBuffer);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C838A0, 0x82C838A0) { ctx.r3.u64 = CStructuredWriter_WriteFloat(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r8.u64); }

uint64_t CStructuredWriter_WriteStringValue(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint64_t stringValue) {
	if (!UseLiftedCode(93, 0x82C83900)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = stringValue; __imp__sub_82C83900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83900);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = stringValue;

	uint64_t sourceString = CStringTable_Find(ctx, base, stringValue);

	const uint32_t emptyLength = 0;
	const uint32_t smallStringCapacity = 15;

	// Temporary copy of the looked-up string at stack+80.
	uint64_t tempString = stack + 80;
	STORE32(stack + 100, emptyLength);          // length
	STORE32(stack + 104, smallStringCapacity);  // capacity
	STORE8(stack + 84, (uint8_t)emptyLength);   // inline buffer

	uint32_t scan = (uint32_t)sourceString;
	uint8_t ch;
	do {
		ch = LOAD8(scan);
		scan += 1;
	} while (ch != 0);
	uint32_t sourceLength = scan - (uint32_t)sourceString - 1;

	BasicString_AssignPtrLen(ctx, base, tempString, sourceString, sourceLength, ctx.r8.u64);

	// The value written out: a string tag at stack+112 and the string at stack+116.
	uint64_t valueTag = stack + 112;
	uint64_t valueString = stack + 116;
	STORE32(stack + 140, smallStringCapacity);  // capacity
	STORE32(stack + 136, emptyLength);          // length
	STORE8(stack + 120, (uint8_t)emptyLength);  // inline buffer
	STORE32(stack + 112, 1u);                   // value tag: string
	BasicString_AssignSubstr(ctx, base, valueString, tempString, 0u, -1, ctx.r8.u64);

	uint64_t result = CStructuredWriter_WriteValue(ctx, base, structuredWriter, valueTag, ctx.r8.u64);

	if (LOAD32(stack + 140) >= 16) {
		uint32_t heapBuffer = LOAD32(stack + 120);
		result = HandleTarget_FreeThunk(ctx, base, heapBuffer);
	}

	uint32_t tempCapacity = LOAD32(stack + 104);
	STORE32(stack + 140, smallStringCapacity);
	STORE32(stack + 136, emptyLength);
	STORE8(stack + 120, (uint8_t)emptyLength);
	if (tempCapacity >= 16) {
		uint32_t heapBuffer = LOAD32(stack + 84);
		result = HandleTarget_FreeThunk(ctx, base, heapBuffer);
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83900, 0x82C83900) { ctx.r3.u64 = CStructuredWriter_WriteStringValue(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82C83A38  [140 bytes]
uint64_t CStructuredWriter_WriteNamedValue(CpuState& ctx, uint8_t* base, uint64_t structuredWriterAddr, uint64_t namedValue, uint64_t arg3) {
	if (!UseLiftedCode(93, 0x82C83A38)) { ctx.r3.u64 = structuredWriterAddr; ctx.r4.u64 = namedValue; ctx.r8.u64 = arg3; __imp__sub_82C83A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83A38);
	uint32_t stack = ctx.r1.u64;
	CStructuredWriter* structuredWriter = GameObject<CStructuredWriter>(base, structuredWriterAddr);
	stack = PushStackFrame(base, stack, 128);

	if (LOAD32((uint32_t)structuredWriterAddr + 12) == 0 || LOAD8((uint32_t)structuredWriterAddr + 8) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 0;
	}

	// nested writer object embedded at structuredWriter + 16; its byte at +4 is the per-write ok flag
	uint32_t nestedWriterAddr = (uint32_t)structuredWriterAddr + 16;
	if (LOAD8(nestedWriterAddr + 4) != 0) {
		uint32_t valueTypeAddr = stack + 80;
		STORE8(valueTypeAddr, uint8_t(3));
		ctx.r1.u64 = stack;
		uint32_t writeResult = CStructuredWriter_Write(ctx, base, nestedWriterAddr, valueTypeAddr);
		arg3 = ctx.r8.u64;
		STORE8(nestedWriterAddr + 4, (uint8_t)writeResult);
	}
	if (LOAD8(nestedWriterAddr + 4) != 0) {
		uint32_t valueAddr = stack + 81;
		ctx.r1.u64 = stack;
		uint32_t writeResult = CStructuredWriter_WriteNameAndValue(ctx, base, namedValue, nestedWriterAddr, arg3);
		STORE8(nestedWriterAddr + 4, (uint8_t)writeResult);
	}

	uint32_t result = structuredWriter->m_result;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83A38, 0x82C83A38) { ctx.r3.u64 = CStructuredWriter_WriteNamedValue(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CStructuredWriter_WriteNamedInt32(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint64_t valueName, uint32_t valuePtr, uint64_t arg4) {
	if (!UseLiftedCode(93, 0x82C83AC8)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valueName; ctx.r5.u64 = valuePtr; ctx.r8.u64 = arg4; __imp__sub_82C83AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83AC8);
	uint32_t stack = ctx.r1.u64;

	stack = PushStackFrame(base, stack, 256);

	const uint32_t intValue = LOAD32(valuePtr);

	// Game-stack temporaries. A plain game string keeps its character data at +0x04
	// (heap pointer once the capacity reaches 16, inline bytes otherwise), its length
	// at +0x14 and its capacity at +0x18. A structured value prefixes a type tag and
	// an int payload at +0x20, which shifts its embedded string to +0x08/+0x18/+0x1C.
	const uint32_t name                = stack + 80;   // the requested name
	const uint32_t nameCopy            = stack + 160;  // a copy of the requested name
	const uint32_t structuredValue     = stack + 112;  // the int32 wrapped in a structured value
	const uint32_t structuredValueCopy = stack + 188;  // a copy of that value

	STORE32(structuredValue + 0x00, 3u);          // type tag: int32
	STORE8 (structuredValue + 0x08, 0);           // embedded string: empty
	STORE32(structuredValue + 0x18, 0);           //   ... length
	STORE32(structuredValue + 0x1C, 15);          //   ... capacity
	STORE32(structuredValue + 0x20, intValue);    // payload

	STORE8 (name + 0x04, 0);                      // name string: empty until filled below
	STORE32(name + 0x14, 0);
	STORE32(name + 0x18, 15);

	uint32_t nameLength = 0;
	while (LOAD8((uint32_t)valueName + nameLength) != 0)
		++nameLength;

	ctx.r1.u64 = stack;
	BasicString_AssignPtrLen(ctx, base, name, valueName, nameLength, arg4);

	STORE8 (nameCopy + 0x04, 0);
	STORE32(nameCopy + 0x14, 0);
	STORE32(nameCopy + 0x18, 15);
	BasicString_AssignSubstr(ctx, base, nameCopy, name, 0, -1, ctx.r8.u64);

	StructuredValue_CopyConstruct(ctx, base, structuredValueCopy, structuredValue, ctx.r8.u64);

	const uint64_t result = CStructuredWriter_WriteNamedValue(ctx, base, structuredWriter, nameCopy, ctx.r8.u64);

	// Tear the temporaries down, freeing the heap buffer before the inline byte that
	// shares its address is cleared.
	if (LOAD32(structuredValueCopy + 0x1C) >= 16)
		HandleTarget_FreeThunk(ctx, base, LOAD32(structuredValueCopy + 0x08));
	STORE8 (structuredValueCopy + 0x08, 0);
	STORE32(structuredValueCopy + 0x18, 0);
	STORE32(structuredValueCopy + 0x1C, 15);

	if (LOAD32(nameCopy + 0x18) >= 16)
		HandleTarget_FreeThunk(ctx, base, LOAD32(nameCopy + 0x04));
	STORE8 (nameCopy + 0x04, 0);
	STORE32(nameCopy + 0x14, 0);
	STORE32(nameCopy + 0x18, 15);

	if (LOAD32(name + 0x18) >= 16)
		HandleTarget_FreeThunk(ctx, base, LOAD32(name + 0x04));
	STORE8 (name + 0x04, 0);
	STORE32(name + 0x14, 0);
	STORE32(name + 0x18, 15);

	if (LOAD32(structuredValue + 0x1C) >= 16)
		HandleTarget_FreeThunk(ctx, base, LOAD32(structuredValue + 0x08));

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83AC8, 0x82C83AC8) { ctx.r3.u64 = CStructuredWriter_WriteNamedInt32(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint64_t CStructuredWriter_WriteNamedUInt32(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint64_t valueName, uint32_t valuePtr, uint64_t arg4) {
	if (!UseLiftedCode(93, 0x82C83BF0)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valueName; ctx.r5.u64 = valuePtr; ctx.r8.u64 = arg4; __imp__sub_82C83BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83BF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 256);

	const uint32_t uintValue = LOAD32(valuePtr);

	// Layout: standalone string (buffer at +4, size +0x14, capacity +0x18);
	// structured value (type +0, embedded string buffer +8, size +0x18, cap +0x1C, payload +0x20).
	const uint32_t nameString = stack + 80;
	const uint32_t structuredValue = stack + 112;
	const uint32_t namedValue = stack + 160;
	const uint32_t structuredValueCopy = stack + 188;

	// Empty name string in small-string mode.
	STORE8(nameString + 4, 0);
	STORE32(nameString + 0x14, 0);
	STORE32(nameString + 0x18, 15);

	// Structured value of type 2 wrapping the uint32.
	STORE32(structuredValue + 0x00, 2u);
	STORE8(structuredValue + 0x08, 0);
	STORE32(structuredValue + 0x18, 0);
	STORE32(structuredValue + 0x1C, 15);
	STORE32(structuredValue + 0x20, uintValue);

	// The named-value pair is handed an empty name string.
	STORE8(namedValue + 4, 0);
	STORE32(namedValue + 0x14, 0);
	STORE32(namedValue + 0x18, 15);

	uint32_t cursor = (uint32_t)valueName;
	uint8_t character;
	do { character = LOAD8(cursor); cursor++; } while (character != 0);
	const uint64_t nameLength = cursor - (uint32_t)valueName - 1;

	ctx.r1.u64 = stack;
	BasicString_AssignPtrLen(ctx, base, nameString, valueName, nameLength, arg4);
	BasicString_AssignSubstr(ctx, base, namedValue, nameString, 0, -1, ctx.r8.u64);
	StructuredValue_CopyConstruct(ctx, base, structuredValueCopy, structuredValue, ctx.r8.u64);

	uint64_t result = CStructuredWriter_WriteNamedValue(ctx, base, structuredWriter, namedValue, ctx.r8.u64);

	if (LOAD32(structuredValueCopy + 0x1C) >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(structuredValueCopy + 0x08));
	}
	STORE32(structuredValueCopy + 0x18, 0);
	STORE32(structuredValueCopy + 0x1C, 15);
	STORE8(structuredValueCopy + 0x08, 0);

	if (LOAD32(namedValue + 0x18) >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(namedValue + 4));
	}
	STORE32(namedValue + 0x14, 0);
	STORE32(namedValue + 0x18, 15);
	STORE8(namedValue + 4, 0);

	if (LOAD32(nameString + 0x18) >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(nameString + 4));
	}
	STORE32(nameString + 0x14, 0);
	STORE32(nameString + 0x18, 15);
	STORE8(nameString + 4, 0);

	if (LOAD32(structuredValue + 0x1C) >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(structuredValue + 0x08));
	}

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83BF0, 0x82C83BF0) { ctx.r3.u64 = CStructuredWriter_WriteNamedUInt32(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint64_t CStructuredWriter_WriteNamedBool(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint64_t valueName, uint32_t valuePtr, uint64_t arg4) {
	if (!UseLiftedCode(93, 0x82C83D18)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valueName; ctx.r5.u64 = valuePtr; ctx.r8.u64 = arg4; __imp__sub_82C83D18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83D18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 256);

	// BasicString layout: +0x04 inline buffer / heap pointer, +0x14 size, +0x18 capacity.
	const uint32_t nameString = stack + 80;          // field name, built from valueName
	const uint32_t valueNode = stack + 112;          // structured value describing the bool
	const uint32_t valueNodeString = valueNode + 4;
	const uint32_t namedValue = stack + 160;         // { name, value } handed to the writer
	const uint32_t namedValueValue = namedValue + 28;
	const uint32_t namedValueString = namedValueValue + 4;

	auto initEmptyString = [&](uint32_t str) {
		STORE32(str + 0x14, 0);
		STORE32(str + 0x18, 15);
		STORE8(str + 4, 0);
	};
	auto destroyString = [&](uint32_t str) {
		if (LOAD32(str + 0x18) >= 16) {
			HandleTarget_FreeThunk(ctx, base, LOAD32(str + 4));
		}
		STORE32(str + 0x18, 15);
		STORE32(str + 0x14, 0);
		STORE8(str + 4, 0);
	};

	uint8_t boolValue = LOAD8(valuePtr);

	initEmptyString(nameString);
	initEmptyString(valueNodeString);
	STORE32(valueNode, 5);                  // value kind
	STORE8(valueNode + 0x20, boolValue);    // the bool itself

	uint32_t nameLength = 0;
	while (LOAD8((uint32_t)valueName + nameLength) != 0) {
		nameLength++;
	}

	ctx.r1.u64 = stack;
	BasicString_AssignPtrLen(ctx, base, nameString, valueName, nameLength, arg4);

	BasicString_AssignSubstr(ctx, base, namedValue, nameString, 0, -1, ctx.r8.u64);

	StructuredValue_CopyConstruct(ctx, base, namedValueValue, valueNode, ctx.r8.u64);

	uint64_t result = CStructuredWriter_WriteNamedValue(ctx, base, structuredWriter, namedValue, ctx.r8.u64);

	destroyString(namedValueString);
	destroyString(namedValue);
	destroyString(nameString);
	destroyString(valueNodeString);

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83D18, 0x82C83D18) { ctx.r3.u64 = CStructuredWriter_WriteNamedBool(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint64_t CStructuredWriter_WriteNamedFloat(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint64_t valueName, uint32_t valuePtr, uint64_t allocator) {
	if (!UseLiftedCode(93, 0x82C83E40)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valueName; ctx.r5.u64 = valuePtr; ctx.r8.u64 = allocator; __imp__sub_82C83E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83E40);
	uint32_t stack = ctx.r1.u64;

	const uint32_t zero = 0;
	const uint32_t ssoCapacity = 15;

	stack = PushStackFrame(base, stack, 256);
	ctx.fpscr.disableFlushMode();

	// Float-value temporary at stack+112 (kind 4, float payload at +32).
	STORE_F32(stack + 144, LOAD_F32(valuePtr));
	STORE32(stack + 136, zero);
	STORE32(stack + 140, ssoCapacity);
	STORE8(stack + 120, (uint8_t)zero);
	STORE32(stack + 112, 4u);

	// Name-string temporary at stack+80.
	STORE32(stack + 104, ssoCapacity);
	STORE32(stack + 100, zero);
	STORE8(stack + 84, (uint8_t)zero);

	uint32_t nameEnd = (uint32_t)valueName;
	uint8_t nameChar;
	do {
		nameChar = LOAD8(nameEnd);
		nameEnd += 1;
	} while (nameChar != 0);
	uint32_t nameLength = nameEnd - (uint32_t)valueName - 1;

	ctx.r1.u64 = stack;
	BasicString_AssignPtrLen(ctx, base, stack + 80, valueName, nameLength, allocator);

	// Second string temporary at stack+160.
	STORE32(stack + 184, ssoCapacity);
	STORE32(stack + 180, zero);
	STORE8(stack + 164, (uint8_t)zero);

	BasicString_AssignSubstr(ctx, base, stack + 160, stack + 80, 0, -1, ctx.r8.u64);
	StructuredValue_CopyConstruct(ctx, base, stack + 188, stack + 112, ctx.r8.u64);
	uint64_t result = CStructuredWriter_WriteNamedValue(ctx, base, structuredWriter, stack + 160, ctx.r8.u64);

	// Destroy the temporaries: free heap buffers of any non-SSO string and reset them.
	if (LOAD32(stack + 216) >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 196));
	}
	uint32_t capacity184 = LOAD32(stack + 184);
	STORE32(stack + 216, ssoCapacity);
	STORE32(stack + 212, zero);
	STORE8(stack + 196, (uint8_t)zero);
	if (capacity184 >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 164));
	}
	uint32_t capacity104 = LOAD32(stack + 104);
	STORE32(stack + 184, ssoCapacity);
	STORE32(stack + 180, zero);
	STORE8(stack + 164, (uint8_t)zero);
	if (capacity104 >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 84));
	}
	uint32_t capacity140 = LOAD32(stack + 140);
	STORE32(stack + 104, ssoCapacity);
	STORE32(stack + 100, zero);
	STORE8(stack + 84, (uint8_t)zero);
	if (capacity140 >= 16) {
		HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 120));
	}

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83E40, 0x82C83E40) { ctx.r3.u64 = CStructuredWriter_WriteNamedFloat(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }

uint64_t CStructuredWriter_WriteNamedString(CpuState& ctx, uint8_t* base, uint64_t structuredWriter, uint64_t valueName, uint64_t stringValue) {
	if (!UseLiftedCode(93, 0x82C83F68)) { ctx.r3.u64 = structuredWriter; ctx.r4.u64 = valueName; ctx.r5.u64 = stringValue; __imp__sub_82C83F68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C83F68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 304);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = valueName;
	ctx.r5.u64 = stringValue;

	uint64_t resolvedString = CStringTable_Find(ctx, base, stringValue);

	// Stack locals. std::string: inline storage/heap pointer at +4, size at +20, capacity at +24.
	// Structured value: kind tag at +0, its string at +4.
	uint32_t resolvedStringCopy = stack + 160;
	uint32_t valueNameCopy = stack + 80;
	uint32_t stringValueStruct = stack + 112;
	uint32_t writeNameString = stack + 192;
	uint32_t valueStructCopy = stack + 220;
	uint32_t valueString = stringValueStruct + 4;
	uint32_t copiedString = valueStructCopy + 4;

	auto resetString = [&](uint32_t str) {
		STORE32(str + 20, 0);
		STORE32(str + 24, 15);
		STORE8(str + 4, 0);
	};
	auto freeString = [&](uint32_t str) {
		if (LOAD32(str + 24) >= 16) HandleTarget_FreeThunk(ctx, base, LOAD32(str + 4));
	};
	auto destroyString = [&](uint32_t str) {
		freeString(str);
		resetString(str);
	};
	auto stringLength = [&](uint64_t str) {
		uint32_t length = 0;
		while (LOAD8((uint32_t)str + length) != 0) ++length;
		return length;
	};

	resetString(resolvedStringCopy);
	BasicString_AssignPtrLen(ctx, base, resolvedStringCopy, resolvedString, stringLength(resolvedString), ctx.r8.u64);

	resetString(valueString);
	STORE32(stringValueStruct, 1);   // the structured value holds a string
	BasicString_AssignSubstr(ctx, base, valueString, resolvedStringCopy, 0, (uint64_t)(int64_t)-1, ctx.r8.u64);

	resetString(valueNameCopy);
	BasicString_AssignPtrLen(ctx, base, valueNameCopy, valueName, stringLength(valueName), ctx.r8.u64);

	resetString(writeNameString);
	BasicString_AssignSubstr(ctx, base, writeNameString, valueNameCopy, 0, (uint64_t)(int64_t)-1, ctx.r8.u64);

	StructuredValue_CopyConstruct(ctx, base, valueStructCopy, stringValueStruct, ctx.r8.u64);
	uint64_t result = CStructuredWriter_WriteNamedValue(ctx, base, structuredWriter, writeNameString, ctx.r8.u64);

	destroyString(copiedString);
	destroyString(writeNameString);
	destroyString(valueNameCopy);
	destroyString(valueString);
	freeString(resolvedStringCopy);   // not reset: the frame is dropped next

	stack = PopStackFrame(stack, 304);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(93, sub_82C83F68, 0x82C83F68) { ctx.r3.u64 = CStructuredWriter_WriteNamedString(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }
