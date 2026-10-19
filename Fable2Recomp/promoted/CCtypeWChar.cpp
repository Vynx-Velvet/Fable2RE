// CCtypeWChar (vtable 0x8200E258): methods of the class as readable C++.
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

uint64_t CCtypeWChar_Is(CpuState& ctx, uint8_t* base, uint64_t ctypeThis, uint32_t classMask, uint32_t character) {
	if (!UseLiftedCode(92, 0x82C741D8)) { ctx.r3.u64 = ctypeThis; ctx.r4.u64 = classMask; ctx.r5.u64 = character; __imp__sub_82C741D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C741D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	uint32_t classFlags = n_sub_82CD2040(ctx, base, character);

	// Only the low 16 bits of the masked flags decide membership.
	uint16_t maskedClass = (uint16_t)(classFlags & classMask);
	uint64_t isMember = maskedClass != 0 ? 1 : 0;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return isMember;
}
PROMOTED_ENTRY(92, sub_82C741D8, 0x82C741D8) { ctx.r3.u64 = CCtypeWChar_Is(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32); }

uint64_t n_sub_82C74220(CpuState& ctx, uint8_t* base, uint32_t ctype, uint64_t source, uint64_t sourceEnd, uint32_t destination) {
	if (!UseLiftedCode(92, 0x82C74220)) { ctx.r3.u64 = ctype; ctx.r4.u64 = source; ctx.r5.u64 = sourceEnd; ctx.r6.u64 = destination; __imp__sub_82C74220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74220);
	return n_sub_82CD2068(ctx, base, source, sourceEnd, destination);
}
PROMOTED_ENTRY(92, sub_82C74220, 0x82C74220) { ctx.r3.u64 = n_sub_82C74220(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u32); }

uint64_t CCtypeWChar_ScanIs(CpuState& ctx, uint8_t* base, uint64_t ctypeWCharAddr, uint64_t ctypeMask, uint64_t rangeBegin, uint64_t rangeEnd) {
	if (!UseLiftedCode(92, 0x82C74238)) { ctx.r3.u64 = ctypeWCharAddr; ctx.r4.u64 = ctypeMask; ctx.r5.u64 = rangeBegin; ctx.r6.u64 = rangeEnd; __imp__sub_82C74238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74238);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CCtypeWChar* ctypeWChar = GameObject<CCtypeWChar>(base, ctypeWCharAddr);
	// r6 and r9 carry what each handler call leaves in them into the next call.
	uint64_t r6Value = rangeEnd;
	uint64_t r9Value = ctx.r9.u64;
	// r4 left for callers: the mask if no call ran, else what the last call left.
	uint64_t r4Value = ctypeMask;
	uint64_t scanCursor = rangeBegin;
	stack = PushStackFrame(base, stack, 128);
	while ((uint32_t)scanCursor != (uint32_t)rangeEnd) {
		uint32_t character = LOAD16((uint32_t)scanCursor);
		uint32_t handler = LOAD32((uint32_t)ctypeWChar->vtable + 8);
		callTarget.u64 = (uint64_t)handler;
		// the indirect call reads its arguments (this, mask, character) and the carried state from ctx
		ctx.r1.u64 = stack;
		ctx.r3.u64 = ctypeWCharAddr;
		ctx.r4.u64 = ctypeMask;
		ctx.r5.u64 = character;
		ctx.r6.u64 = r6Value;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = handler;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		r4Value = ctx.r4.u64;
		r6Value = ctx.r6.u64;
		r9Value = ctx.r3.u32 & 0xFF;
		if ((uint32_t)r9Value != 0) break;
		scanCursor = scanCursor + 2;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Value;
	return scanCursor;
}
PROMOTED_ENTRY(92, sub_82C74238, 0x82C74238) { ctx.r3.u64 = CCtypeWChar_ScanIs(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CCtypeWChar_ToUpper(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t character) {
	if (!UseLiftedCode(92, 0x82C74308)) { ctx.r3.u64 = self; ctx.r4.u64 = character; __imp__sub_82C74308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74308);
	uint64_t localeInfo = self + 8;
	uint64_t converted = CRT_WcToUpperCLocale(ctx, base, character, localeInfo);
	// callers read r4 after the call
	ctx.r4.u64 = localeInfo;
	return converted;
}
PROMOTED_ENTRY(92, sub_82C74308, 0x82C74308) { ctx.r3.u64 = CCtypeWChar_ToUpper(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CCtypeWChar_ToUpperRange(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t rangeBegin, uint32_t rangeEnd) {
	if (!UseLiftedCode(92, 0x82C74318)) { ctx.r3.u64 = self; ctx.r4.u64 = rangeBegin; ctx.r5.u64 = rangeEnd; __imp__sub_82C74318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74318);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 112);
	uint64_t localeInfo = self + 8;
	uint64_t cursor = rangeBegin;
	while ((uint32_t)cursor != rangeEnd) {
		uint16_t wideChar = LOAD16((uint32_t)cursor);
		ctx.r1.u64 = stack;
		uint32_t converted = CRT_WcToUpperCLocale(ctx, base, wideChar, localeInfo);
		STORE16((uint32_t)cursor, (uint16_t)converted);
		cursor = cursor + 2;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call: the locale info if the range was not empty
	ctx.r4.u64 = (uint32_t)rangeBegin != rangeEnd ? localeInfo : rangeBegin;
	return cursor;
}
PROMOTED_ENTRY(92, sub_82C74318, 0x82C74318) { ctx.r3.u64 = CCtypeWChar_ToUpperRange(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CCtypeWChar_ToLower(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t character) {
	if (!UseLiftedCode(92, 0x82C74360)) { ctx.r3.u64 = self; ctx.r4.u64 = character; __imp__sub_82C74360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74360);
	uint64_t localeInfo = self + 8;
	uint64_t converted = CRT_WcToLowerCLocale(ctx, base, character, localeInfo);
	// callers read r4 after the call
	ctx.r4.u64 = localeInfo;
	return converted;
}
PROMOTED_ENTRY(92, sub_82C74360, 0x82C74360) { ctx.r3.u64 = CCtypeWChar_ToLower(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CCtypeWChar_ToLowerRange(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t rangeBegin, uint32_t rangeEnd) {
	if (!UseLiftedCode(92, 0x82C74370)) { ctx.r3.u64 = self; ctx.r4.u64 = rangeBegin; ctx.r5.u64 = rangeEnd; __imp__sub_82C74370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74370);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 112);
	uint64_t localeInfo = self + 8;
	uint64_t cursor = rangeBegin;
	while ((uint32_t)cursor != rangeEnd) {
		uint32_t wideChar = LOAD16((uint32_t)cursor);
		ctx.r1.u64 = stack;
		uint32_t converted = CRT_WcToLowerCLocale(ctx, base, wideChar, localeInfo);
		STORE16((uint32_t)cursor, (uint16_t)converted);
		cursor = cursor + 2;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call: the locale info if the range was not empty
	ctx.r4.u64 = (uint32_t)rangeBegin != rangeEnd ? localeInfo : rangeBegin;
	return cursor;
}
PROMOTED_ENTRY(92, sub_82C74370, 0x82C74370) { ctx.r3.u64 = CCtypeWChar_ToLowerRange(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CCtypeWChar_Widen(CpuState& ctx, uint8_t* base, uint32_t self, uint32_t narrowChar) {
	if (!UseLiftedCode(92, 0x82C743B8)) { ctx.r3.u64 = self; ctx.r4.u64 = narrowChar; __imp__sub_82C743B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C743B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t narrowPtr = stack + 80;
	uint32_t widePtr = stack + 82;
	STORE8(narrowPtr, (uint8_t)narrowChar);
	STORE32(stack + 84, 0u);
	ctx.r1.u64 = stack;
	int32_t converted = CRT_MbToWcSingleByte(ctx, base, widePtr, narrowPtr, 1);
	int64_t wideChar = -1;
	if (converted >= 0) {
		wideChar = LOAD16(widePtr);
	}
	// callers read r4 after the call: the narrow buffer address, summed in 64 bits
	ctx.r4.u64 = (uint64_t)stack + 80;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return wideChar;
}
PROMOTED_ENTRY(92, sub_82C743B8, 0x82C743B8) { ctx.r3.u64 = CCtypeWChar_Widen(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82C74408(CpuState& ctx, uint8_t* base, uint64_t ctypeWCharAddr, uint64_t rangeBegin, uint64_t rangeEnd) {
	if (!UseLiftedCode(92, 0x82C74408)) { ctx.r3.u64 = ctypeWCharAddr; ctx.r4.u64 = rangeBegin; ctx.r5.u64 = rangeEnd; __imp__sub_82C74408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74408);
	CCtypeWChar* ctypeWChar = GameObject<CCtypeWChar>(base, ctypeWCharAddr);
	uint32_t virtualMethod = LOAD32(uint32_t(ctypeWChar->vtable) + 44);
	uint64_t rangeLength = rangeEnd - rangeBegin;
	ctx.r3.u64 = ctypeWCharAddr;
	ctx.r4.u64 = rangeBegin;
	ctx.r5.u64 = rangeEnd;
	ctx.r7.u64 = rangeLength;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(92, sub_82C74408, 0x82C74408) { ctx.r3.u64 = n_sub_82C74408(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CCtypeWChar_WidenRange(CpuState& ctx, uint8_t* base, uint32_t self, uint64_t source, uint32_t sourceEnd, uint32_t dest, uint32_t destCapacity) {
	if (!UseLiftedCode(92, 0x82C74420)) { ctx.r3.u64 = self; ctx.r4.u64 = source; ctx.r5.u64 = sourceEnd; ctx.r6.u64 = dest; ctx.r7.u64 = destCapacity; __imp__sub_82C74420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74420);
	uint32_t stack = ctx.r1.u64;
	uint64_t sourceCursor = source;
	uint32_t destCursor = dest;
	stack = PushStackFrame(base, stack, 144);
	const uint32_t inputByte = stack + 80;    // the byte being converted
	const uint32_t outputChar = stack + 82;   // wide char produced by the conversion

	// dest must be able to hold one wide char per remaining source byte
	if (destCapacity < uint32_t(sourceEnd - sourceCursor)) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	// callers read r4 after the call: the input byte's address once a conversion ran, else source
	uint64_t r4Value = source;
	while ((uint32_t)sourceCursor != sourceEnd) {
		uint8_t sourceByte = LOAD8((uint32_t)sourceCursor);
		STORE32(stack + 84, 0);
		STORE8(inputByte, sourceByte);
		ctx.r1.u64 = stack;
		uint64_t status = CRT_MbToWcSingleByte(ctx, base, outputChar, inputByte, 1);
		r4Value = inputByte;
		uint16_t wideChar = 0xFFFF; // WEOF on conversion failure
		if ((int32_t)status >= 0) {
			wideChar = LOAD16(outputChar);
		}
		sourceCursor += 1;
		STORE16(destCursor, wideChar);
		destCursor += 2;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return sourceCursor;
}
PROMOTED_ENTRY(92, sub_82C74420, 0x82C74420) { ctx.r3.u64 = CCtypeWChar_WidenRange(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32); }

uint64_t CCtypeWChar_Narrow(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t wideChar, uint64_t defaultChar, uint64_t r8Value) {
	if (!UseLiftedCode(92, 0x82C744B0)) { ctx.r3.u64 = self; ctx.r4.u64 = wideChar; ctx.r5.u64 = defaultChar; ctx.r8.u64 = r8Value; __imp__sub_82C744B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C744B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	const uint32_t conversionState = stack + 80;  // zeroed before the conversion
	const uint32_t convertedByte = stack + 84;    // byte produced by the conversion

	STORE32(conversionState, 0u);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r6.u64 = self + 24;
	uint32_t conversionResult = CRT_WcToMbSingleByte(ctx, base, convertedByte, wideChar, r8Value);

	uint64_t narrowChar = defaultChar;
	if (conversionResult == 1) {
		narrowChar = LOAD8(convertedByte);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return narrowChar;
}
PROMOTED_ENTRY(92, sub_82C744B0, 0x82C744B0) { ctx.r3.u64 = CCtypeWChar_Narrow(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint64_t n_sub_82C74500(CpuState& ctx, uint8_t* base, uint64_t ctypeWCharAddr, uint64_t rangeStart, uint64_t rangeEnd) {
	if (!UseLiftedCode(92, 0x82C74500)) { ctx.r3.u64 = ctypeWCharAddr; ctx.r4.u64 = rangeStart; ctx.r5.u64 = rangeEnd; __imp__sub_82C74500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74500);
	CCtypeWChar* ctypeWChar = GameObject<CCtypeWChar>(base, ctypeWCharAddr);
	uint64_t range = rangeEnd - rangeStart;
	int32_t halfRange = (int32_t)range >> 1;
	uint32_t callee = LOAD32(uint32_t(ctypeWChar->vtable) + 56);

	ctx.r3.u64 = ctypeWCharAddr;
	ctx.r4.u64 = rangeStart;
	ctx.r5.u64 = rangeEnd;
	ctx.r8.u64 = (uint64_t)(int64_t)halfRange;
	ctx.r9.u64 = callee;
	ctx.r10.u64 = range;
	REX_CALL_INDIRECT_FUNC(callee);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(92, sub_82C74500, 0x82C74500) { ctx.r3.u64 = n_sub_82C74500(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CCtypeWChar_NarrowRange(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t sourceBegin, uint32_t sourceEnd, uint32_t defaultChar, uint64_t destBegin, uint64_t destCapacity) {
	if (!UseLiftedCode(92, 0x82C74518)) { ctx.r3.u64 = self; ctx.r4.u64 = sourceBegin; ctx.r5.u64 = sourceEnd; ctx.r6.u64 = defaultChar; ctx.r7.u64 = destBegin; ctx.r8.u64 = destCapacity; __imp__sub_82C74518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C74518);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	const uint32_t conversionState = stack + 80;    // zeroed before each character
	const uint32_t convertedByte = stack + 84;      // byte produced by the conversion

	uint64_t sourceCursor = sourceBegin;
	uint32_t destCursor = (uint32_t)destBegin;
	const uint32_t sourceByteCount = sourceEnd - (uint32_t)sourceCursor;
	uint32_t carry = ((int32_t)sourceByteCount < 0) & ((sourceByteCount & 1) != 0);

	// dest must be able to hold one byte per source wide char
	if ((uint32_t)destCapacity < (uint32_t)((int32_t)sourceByteCount >> 1)) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	// r4, r7, r8 and the carry flag as the conversion helper leaves them: r7, r8 and the carry
	// go into the next call, callers read r4 after this call
	uint64_t r4Value = sourceBegin;
	uint64_t r7Value = destBegin;
	uint64_t r8Value = destCapacity;
	while ((uint32_t)sourceCursor != sourceEnd) {
		STORE32(conversionState, 0);
		const uint16_t wideChar = LOAD16((uint32_t)sourceCursor);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r5.u64 = conversionState;
		ctx.r6.u64 = self + 24;
		ctx.r7.u64 = r7Value;
		ctx.xer.ca = carry;
		const uint32_t narrowed = CRT_WcToMbSingleByte(ctx, base, convertedByte, wideChar, r8Value);
		r4Value = ctx.r4.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		carry = ctx.xer.ca;
		const uint8_t narrowChar = (narrowed == 1) ? LOAD8(convertedByte) : (uint8_t)defaultChar;
		sourceCursor += 2;
		STORE8(destCursor, narrowChar);
		destCursor += 1;
	}
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return sourceCursor;
}
PROMOTED_ENTRY(92, sub_82C74518, 0x82C74518) { ctx.r3.u64 = CCtypeWChar_NarrowRange(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32, ctx.r7.u64, ctx.r8.u64); }
