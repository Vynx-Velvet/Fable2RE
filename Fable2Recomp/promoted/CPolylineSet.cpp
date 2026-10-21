// CPolylineSet (vtable 0x820F1948): methods of the class as readable C++.
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

uint64_t CPolylineSet_DeletingDtor(CpuState& ctx, uint8_t* base, uint64_t polylineSetAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(73, 0x82A10B78)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82A10B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A10B78);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CPolylineSet_Dtor(ctx, base, polylineSetAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, polylineSetAddr);
	}
	return polylineSetAddr;
}
PROMOTED_ENTRY(73, sub_82A10B78, 0x82A10B78) { ctx.r3.u64 = CPolylineSet_DeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPolylineSet_WriteBinary(CpuState& ctx, uint8_t* base, uint32_t polylineSetAddr, uint64_t outStream) {
	if (!UseLiftedCode(142, 0x832375A8)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = outStream; __imp__sub_832375A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832375A8);
	uint32_t stack = ctx.r1.u64;
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	stack = PushStackFrame(base, stack, 176);
	const uint32_t stream = (uint32_t)outStream;
	const uint32_t flagSlot = stack + 80;
	const uint32_t entryMemberSlot = stack + 84;
	const uint32_t wordSlot = stack + 88;
	const uint32_t pointCountCopySlot = stack + 92;

	// Every value goes out from a stack slot through the stream's write method (vtable slot 4: stream, data,
	// size); a stream whose byte at +8 is set takes the bytes reversed. With each write the original code also
	// hands the method two values it happens to hold; after a reversal they are bytes 2 and 3 of the value.
	auto storeInStreamOrder = [&](uint32_t slot, uint32_t value) -> uint8_t {
		const uint8_t reverseBytes = LOAD8(stream + 8);
		STORE32(slot, reverseBytes != 0 ? __builtin_bswap32(value) : value);
		return reverseBytes;
	};
	auto callWrite = [&](uint32_t slot, uint64_t sixthArg, uint64_t seventhArg) {
		const uint32_t writeMethod = LOAD32(LOAD32(stream) + 16);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = outStream;
		ctx.r4.u64 = slot;
		ctx.r5.u64 = 4;
		ctx.r8.u64 = sixthArg;
		ctx.r9.u64 = seventhArg;
		ctx.r10.u64 = writeMethod;
		REX_CALL_INDIRECT_FUNC(writeMethod);
	};
	auto writeWord = [&](uint32_t slot, uint32_t value, uint64_t sixthArg, uint64_t seventhArg) {
		if (storeInStreamOrder(slot, value) != 0) {
			sixthArg = (value >> 8) & 0xFF;
			seventhArg = value & 0xFF;
		}
		callWrite(slot, sixthArg, seventhArg);
	};

	// One byte: whether m_flag is set (the method also gets the steps of that test).
	const uint32_t flag = polylineSet->m_flag;
	const uint32_t streamVtable = LOAD32(stream);
	const uint32_t leadingZeros = flag == 0 ? 32 : __builtin_clz(flag);
	const uint32_t flagClear = flag == 0;
	const uint32_t flagSet = flag != 0;
	const uint32_t firstWriteMethod = LOAD32(streamVtable + 16);
	STORE8(flagSlot, (uint8_t)flagSet);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = outStream;
	ctx.r4.u64 = flagSlot;
	ctx.r5.u64 = 1;
	ctx.r6.u64 = firstWriteMethod;
	ctx.r7.u64 = flagSet;
	ctx.r8.u64 = flagClear;
	ctx.r9.u64 = leadingZeros;
	ctx.r10.u64 = streamVtable;
	REX_CALL_INDIRECT_FUNC(firstWriteMethod);

	BinaryStream_WriteUInt32(ctx, base, outStream, polylineSet->m_version);
	const uint64_t entryBytes = (uint64_t)polylineSet->m_entriesEnd - (uint64_t)polylineSet->m_entriesBegin;
	const int32_t entryCount = (int32_t)entryBytes / 20;
	BinaryStream_WriteUInt32(ctx, base, outStream, (uint32_t)entryCount);
	uint64_t carriedArg6 = ctx.r8.u64;
	uint64_t carriedArg7 = ctx.r9.u64;

	// Per 20-byte entry: its word at +16, its point count, then the three words of each 12-byte point.
	uint64_t entryOffset = 0;
	for (int32_t entryIndex = 0; entryIndex < entryCount; ++entryIndex, entryOffset += 20) {
		const uint64_t entryAddr = entryOffset + (uint64_t)polylineSet->m_entriesBegin;
		const uint32_t entryMember = LOAD32((uint32_t)entryAddr + 16);
		writeWord(entryMemberSlot, entryMember, entryMember, entryAddr);

		const uint32_t countEntry = (uint32_t)entryOffset + uint32_t(polylineSet->m_entriesBegin);
		const uint32_t pointsEnd = LOAD32(countEntry + 8);
		const uint32_t pointsBegin = LOAD32(countEntry + 4);
		const uint64_t pointBytes = (uint64_t)pointsEnd - (uint64_t)pointsBegin;
		const int32_t pointCount = (int32_t)pointBytes / 12;
		STORE32(pointCountCopySlot, (uint32_t)pointCount);
		const uint8_t reverseBytes = storeInStreamOrder(wordSlot, (uint32_t)pointCount);
		uint64_t countSixthArg = pointsBegin;
		uint64_t countSeventhArg = pointsEnd;
		if (reverseBytes != 0) {
			countSixthArg = (uint32_t)pointCount >> 24;
			countSeventhArg = (uint32_t)pointCount & 0xFF;
		}
		ctx.r6.u64 = pointBytes;
		ctx.r7.u64 = reverseBytes;
		callWrite(wordSlot, countSixthArg, countSeventhArg);
		carriedArg6 = ctx.r8.u64;
		carriedArg7 = ctx.r9.u64;

		uint32_t pointOffset = 0;
		for (int32_t pointIndex = 0; pointIndex < pointCount; ++pointIndex, pointOffset += 12) {
			const uint64_t pointEntryAddr = entryOffset + (uint64_t)polylineSet->m_entriesBegin;
			const uint32_t pointAddr = LOAD32((uint32_t)pointEntryAddr + 4) + pointOffset;
			const uint32_t firstWord = LOAD32(pointAddr);
			writeWord(wordSlot, firstWord, firstWord, pointEntryAddr);
			const uint32_t secondWord = LOAD32(pointAddr + 4);
			writeWord(wordSlot, secondWord, 0, secondWord);
			const uint32_t thirdWord = LOAD32(pointAddr + 8);
			writeWord(wordSlot, thirdWord, 0, thirdWord);
			carriedArg6 = ctx.r8.u64;
			carriedArg7 = ctx.r9.u64;
		}
	}

	writeWord(wordSlot, uint32_t(polylineSet->m_id), carriedArg6, carriedArg7);
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_832375A8, 0x832375A8) { ctx.r3.u64 = CPolylineSet_WriteBinary(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPolylineSet_Write(CpuState& ctx, uint8_t* base, uint64_t polylineSetAddr, uint64_t stream) {
	if (!UseLiftedCode(142, 0x832379B0)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = stream; __imp__sub_832379B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832379B0);
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	BinaryStream_WriteUInt32(ctx, base, stream, polylineSet->m_id);
	// vtable slot 7: the class's binary writer (CPolylineSet_WriteBinary for this class).
	const uint32_t writeBinaryMethod = LOAD32(uint32_t(polylineSet->vtable) + 28);
	ctx.r3.u64 = polylineSetAddr;
	ctx.r4.u64 = stream;
	ctx.r10.u64 = writeBinaryMethod;
	REX_CALL_INDIRECT_FUNC(writeBinaryMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_832379B0, 0x832379B0) { ctx.r3.u64 = CPolylineSet_Write(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPolylineSet_Save(CpuState& ctx, uint8_t* base, uint64_t polylineSetAddr, uint64_t serializer, uint64_t ownBlock) {
	constexpr int32_t defaultNameText = int32_t(0x8209003F);
	constexpr uint32_t blockNameSlot = 0x8349E5DC;
	if (!UseLiftedCode(142, 0x83237A08)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = serializer; ctx.r5.u64 = ownBlock; __imp__sub_83237A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83237A08);
	uint32_t stack = ctx.r1.u64;
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	stack = PushStackFrame(base, stack, 128);
	const uint32_t idSlot = stack + 80;

	// With ownBlock set, the id and the data go between the serializer's begin method (vtable slot 1, given the
	// text of the name at blockNameSlot) and its end method (slot 3), and only when begin succeeds. The values
	// each call leaves as second and third argument are handed on to the next one; the last second one is
	// handed back to the caller (r4).
	const bool inBlock = ((uint32_t)ownBlock & 0xFF) != 0;
	uint64_t result = 1;
	uint64_t carriedArg2 = serializer;
	uint64_t carriedArg3 = ownBlock;
	if (inBlock) {
		const uint32_t nameData = LOAD32(blockNameSlot);
		const uint64_t nameText = nameData != 0 ? uint64_t(LOAD32(nameData)) : uint64_t(int64_t(defaultNameText));
		const uint32_t beginMethod = LOAD32(LOAD32((uint32_t)serializer) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = serializer;
		ctx.r4.u64 = nameText;
		ctx.r5.u64 = carriedArg3;
		ctx.r10.u64 = beginMethod;
		REX_CALL_INDIRECT_FUNC(beginMethod);
		result = ctx.r3.u64;
		carriedArg2 = ctx.r4.u64;
		carriedArg3 = ctx.r5.u64;
	}

	if (((uint32_t)result & 0xFF) != 0) {
		STORE32(idSlot, uint32_t(polylineSet->m_id));
		ctx.r1.u64 = stack;
		ctx.r5.u64 = carriedArg3;
		Serializer_SerializeId(ctx, base, serializer, idSlot);

		// vtable slot 9: the class's named writer (CPolylineSet_WriteNamed for this class).
		const uint32_t polylineSetVtable = polylineSet->vtable;
		const uint32_t writeNamedMethod = LOAD32(polylineSetVtable + 36);
		ctx.r3.u64 = polylineSetAddr;
		ctx.r4.u64 = serializer;
		ctx.r9.u64 = writeNamedMethod;
		ctx.r10.u64 = polylineSetVtable;
		REX_CALL_INDIRECT_FUNC(writeNamedMethod);
		result = ctx.r3.u64;
		carriedArg2 = ctx.r4.u64;
		carriedArg3 = ctx.r5.u64;
	}

	if (inBlock) {
		const uint32_t endMethod = LOAD32(LOAD32((uint32_t)serializer) + 12);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = serializer;
		ctx.r4.u64 = carriedArg2;
		ctx.r5.u64 = carriedArg3;
		ctx.r10.u64 = endMethod;
		REX_CALL_INDIRECT_FUNC(endMethod);
		result = ctx.r3.u64;
		carriedArg2 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = carriedArg2;
	return result;
}
PROMOTED_ENTRY(142, sub_83237A08, 0x83237A08) { ctx.r3.u64 = CPolylineSet_Save(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CPolylineSet_Render(CpuState& ctx, uint8_t* base, uint64_t polylineSetAddr, uint64_t serializer, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t ownBlock) {
	constexpr int32_t defaultNameText = int32_t(0x8209003F);
	constexpr uint32_t blockNameSlot = 0x8349E5DC;
	if (!UseLiftedCode(142, 0x83237AC0)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = serializer; ctx.r5.u64 = forwardedArg1; ctx.r6.u64 = forwardedArg2; ctx.r7.u64 = ownBlock; __imp__sub_83237AC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83237AC0);
	uint32_t stack = ctx.r1.u64;
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	stack = PushStackFrame(base, stack, 144);
	const uint32_t idSlot = stack + 80;

	// The loading counterpart of CPolylineSet_Save (vtable slot 2): with ownBlock set, the id and the data are
	// read between the serializer's begin method (vtable slot 1, given the text of the name at blockNameSlot) and
	// its end method (slot 3), and only when begin succeeds. The values each call leaves as second to fifth
	// argument are handed on to the next one; the last second one is handed back to the caller (r4).
	const bool inBlock = ((uint32_t)ownBlock & 0xFF) != 0;
	uint64_t result = 1;
	uint64_t carriedArg2 = serializer;
	uint64_t carriedArg3 = forwardedArg1;
	uint64_t carriedArg4 = forwardedArg2;
	uint64_t carriedArg5 = ownBlock;
	if (inBlock) {
		const uint32_t nameData = LOAD32(blockNameSlot);
		const uint64_t nameText = nameData != 0 ? uint64_t(LOAD32(nameData)) : uint64_t(int64_t(defaultNameText));
		const uint32_t beginMethod = LOAD32(LOAD32((uint32_t)serializer) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = serializer;
		ctx.r4.u64 = nameText;
		ctx.r5.u64 = carriedArg3;
		ctx.r6.u64 = carriedArg4;
		ctx.r7.u64 = carriedArg5;
		ctx.r10.u64 = beginMethod;
		REX_CALL_INDIRECT_FUNC(beginMethod);
		result = ctx.r3.u64;
		carriedArg2 = ctx.r4.u64;
		carriedArg3 = ctx.r5.u64;
		carriedArg4 = ctx.r6.u64;
		carriedArg5 = ctx.r7.u64;
	}

	if (((uint32_t)result & 0xFF) != 0) {
		// The id is read into a stack slot and not kept.
		ctx.r1.u64 = stack;
		ctx.r5.u64 = carriedArg3;
		ctx.r6.u64 = carriedArg4;
		ctx.r7.u64 = carriedArg5;
		Renderer_SetState(ctx, base, serializer, idSlot);

		// vtable slot 8: the class's named reader (CPolylineSet_ReadNamed for this class).
		const uint32_t readNamedMethod = LOAD32(uint32_t(polylineSet->vtable) + 32);
		ctx.r3.u64 = polylineSetAddr;
		ctx.r4.u64 = serializer;
		ctx.r5.u64 = forwardedArg1;
		ctx.r6.u64 = forwardedArg2;
		ctx.r10.u64 = readNamedMethod;
		REX_CALL_INDIRECT_FUNC(readNamedMethod);
		result = ctx.r3.u64;
		carriedArg2 = ctx.r4.u64;
		carriedArg3 = ctx.r5.u64;
		carriedArg4 = ctx.r6.u64;
		carriedArg5 = ctx.r7.u64;
	}

	if (inBlock) {
		const uint32_t endMethod = LOAD32(LOAD32((uint32_t)serializer) + 12);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = serializer;
		ctx.r4.u64 = carriedArg2;
		ctx.r5.u64 = carriedArg3;
		ctx.r6.u64 = carriedArg4;
		ctx.r7.u64 = carriedArg5;
		ctx.r10.u64 = endMethod;
		REX_CALL_INDIRECT_FUNC(endMethod);
		result = ctx.r3.u64;
		carriedArg2 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = carriedArg2;
	return result;
}
PROMOTED_ENTRY(142, sub_83237AC0, 0x83237AC0) { ctx.r3.u64 = CPolylineSet_Render(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

uint64_t CPolylineSet_WriteNamed(CpuState& ctx, uint8_t* base, uint64_t polylineSetAddr, uint64_t serializer) {
	constexpr int32_t defaultNameText = int32_t(0x8209003F);
	constexpr int32_t TXT_8349E5FC_G_ = int32_t(0x8349E5FC);
	constexpr uint32_t objectNameSlot = 0x8349E5E8;
	constexpr uint32_t versionNameSlot = 0x8349E600;
	constexpr uint32_t entryCountNameSlot = 0x8349E5EC;
	constexpr uint32_t entryMemberNameSlot = 0x8349E5F4;
	constexpr uint32_t pointNameSlot = 0x8349E5F0;
	if (!UseLiftedCode(142, 0x83237B80)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = serializer; __imp__sub_83237B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83237B80);
	uint32_t stack = ctx.r1.u64;
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	stack = PushStackFrame(base, stack, 192);
	const uint32_t pointCountSlot = stack + 80;
	const uint32_t entryCountSlot = stack + 84;
	const uint32_t versionSlot = stack + 88;

	// Each field is serialized under a name: the first word of the data a name slot points to, or
	// defaultNameText when the slot is empty. The serializer methods take it as their second argument (r4).
	auto nameText = [&](uint32_t nameSlot) -> uint64_t {
		const uint32_t nameData = LOAD32(nameSlot);
		return nameData != 0 ? uint64_t(LOAD32(nameData)) : uint64_t(int64_t(defaultNameText));
	};

	// The serializer's begin method (vtable slot 1); everything else happens only when it succeeds.
	const uint32_t beginMethod = LOAD32(LOAD32((uint32_t)serializer) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = serializer;
	ctx.r4.u64 = nameText(objectNameSlot);
	ctx.r10.u64 = beginMethod;
	REX_CALL_INDIRECT_FUNC(beginMethod);
	const uint32_t begun = (uint32_t)ctx.r3.u64 & 0xFF;
	if (begun != 0) {
		ctx.r9.u64 = begun;
		CProperty_ProcessValue(ctx, base, (uint32_t)TXT_8349E5FC_G_, serializer, polylineSetAddr + 28);

		STORE32(versionSlot, 0);
		ctx.r4.u64 = nameText(versionNameSlot);
		ctx.r9.u64 = 0;
		IStream_SerializeId(ctx, base, serializer, versionSlot);
		const uint32_t version = LOAD32(versionSlot);
		polylineSet->m_version = version;

		const uint32_t entriesEnd = polylineSet->m_entriesEnd;
		const uint32_t entriesBegin = polylineSet->m_entriesBegin;
		const uint64_t entryBytes = (uint64_t)entriesEnd - (uint64_t)entriesBegin;
		STORE32(entryCountSlot, (uint32_t)((int32_t)entryBytes / 20));
		ctx.r4.u64 = nameText(entryCountNameSlot);
		ctx.r6.u64 = entryBytes;
		ctx.r7.u64 = entriesBegin;
		ctx.r8.u64 = entriesEnd;
		ctx.r9.u64 = version;
		IStream_SerializeU32(ctx, base, serializer, entryCountSlot);

		// Per 20-byte entry: its word at +16, its point count, then the three words of each 12-byte point.
		uint64_t entryOffset = 0;
		for (int32_t entryIndex = 0; entryIndex < (int32_t)LOAD32(entryCountSlot); ++entryIndex, entryOffset += 20) {
			const uint64_t entryAddr = (uint64_t)polylineSet->m_entriesBegin + entryOffset;
			ctx.r4.u64 = nameText(entryMemberNameSlot);
			IStream_SerializeU32(ctx, base, serializer, entryAddr + 16);

			const uint32_t countEntry = uint32_t(polylineSet->m_entriesBegin) + (uint32_t)entryOffset;
			const uint32_t pointsEnd = LOAD32(countEntry + 8);
			const uint32_t pointsBegin = LOAD32(countEntry + 4);
			const uint64_t pointBytes = (uint64_t)pointsEnd - (uint64_t)pointsBegin;
			const uint64_t pointCount = uint32_t((int32_t)pointBytes / 12);
			STORE32(pointCountSlot, (uint32_t)pointCount);
			ctx.r4.u64 = nameText(pointNameSlot);
			ctx.r6.u64 = pointCount;
			ctx.r7.u64 = pointBytes;
			ctx.r8.u64 = pointsBegin;
			ctx.r9.u64 = pointsEnd;
			IStream_SerializeU32(ctx, base, serializer, pointCountSlot);

			uint64_t pointOffset = 0;
			for (int32_t pointIndex = 0; pointIndex < (int32_t)LOAD32(pointCountSlot); ++pointIndex, pointOffset += 12) {
				const uint32_t pointEntry = uint32_t(polylineSet->m_entriesBegin) + (uint32_t)entryOffset;
				const uint64_t pointAddr = (uint64_t)LOAD32(pointEntry + 4) + pointOffset;
				for (uint32_t wordOffset = 0; wordOffset < 12; wordOffset += 4) {
					ctx.r4.u64 = nameText(pointNameSlot);
					IStream_SerializeId(ctx, base, serializer, pointAddr + wordOffset);
				}
			}
		}

		ctx.r5.u64 = 0;
		CRegistrableThing_SaveId(ctx, base, polylineSetAddr, serializer);

		// The serializer's end method (vtable slot 3).
		const uint32_t endMethod = LOAD32(LOAD32((uint32_t)serializer) + 12);
		ctx.r3.u64 = serializer;
		ctx.r10.u64 = endMethod;
		REX_CALL_INDIRECT_FUNC(endMethod);
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_83237B80, 0x83237B80) { ctx.r3.u64 = CPolylineSet_WriteNamed(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPolylineSet_Read(CpuState& ctx, uint8_t* base, uint64_t polylineSetAddr, uint64_t stream, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3) {
	if (!UseLiftedCode(142, 0x83237E98)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = stream; ctx.r5.u64 = forwardedArg1; ctx.r6.u64 = forwardedArg2; ctx.r8.u64 = forwardedArg3; __imp__sub_83237E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83237E98);
	uint32_t stack = ctx.r1.u64;
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	stack = PushStackFrame(base, stack, 144);
	// The first word (where CPolylineSet_Write puts the id) is read into a stack slot and not kept.
	const uint32_t idSlot = stack + 80;
	ctx.r1.u64 = stack;
	ctx.r6.u64 = forwardedArg2;
	ctx.r8.u64 = forwardedArg3;
	BinaryStream_ReadUInt32(ctx, base, stream, idSlot);

	// vtable slot 6: the class's binary reader (CPolylineSet_ReadBinary for this class). The value that came in
	// as sixth argument goes on as its fifth.
	const uint32_t readBinaryMethod = LOAD32(uint32_t(polylineSet->vtable) + 24);
	ctx.r3.u64 = polylineSetAddr;
	ctx.r4.u64 = stream;
	ctx.r5.u64 = forwardedArg1;
	ctx.r6.u64 = forwardedArg2;
	ctx.r7.u64 = forwardedArg3;
	ctx.r10.u64 = readBinaryMethod;
	REX_CALL_INDIRECT_FUNC(readBinaryMethod);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_83237E98, 0x83237E98) { ctx.r3.u64 = CPolylineSet_Read(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint32_t CPolylineSet_Dtor(CpuState& ctx, uint8_t* base, uint32_t polylineSetAddr) {
	constexpr uint32_t CPolylineSet_vtable = 0x820F1948;
	constexpr uint32_t CRegistrableThing_vtable = 0x820F1A5C;
	if (!UseLiftedCode(142, 0x83237EF0)) { ctx.r3.u64 = polylineSetAddr; __imp__sub_83237EF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83237EF0);
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	// HandleArray20_DestroyRange is a method of the entry vector at +12, which it gets besides the range.
	const uint32_t entryVector = polylineSetAddr + 12;
	uint32_t result = polylineSetAddr;
	polylineSet->vtable = CPolylineSet_vtable;
	const uint32_t entriesBegin = polylineSet->m_entriesBegin;
	if (entriesBegin != 0) {
		const uint32_t entriesEnd = polylineSet->m_entriesEnd;
		ctx.r3.u64 = entryVector;
		HandleArray20_DestroyRange(ctx, base, entriesBegin, entriesEnd);
		const uint32_t entries = polylineSet->m_entriesBegin;
		result = HandleTarget_Free(ctx, base, entries);
	}
	polylineSet->m_entriesBegin = 0;
	polylineSet->m_entriesEnd = 0;
	polylineSet->m_18 = 0;
	polylineSet->vtable = CRegistrableThing_vtable;
	return result;
}
PROMOTED_ENTRY(142, sub_83237EF0, 0x83237EF0) { ctx.r3.u64 = CPolylineSet_Dtor(ctx, base, ctx.r3.u32); }

void CPolylineSet_Ctor(CpuState& ctx, uint8_t* base, uint32_t polylineSetAddr, uint32_t polylineSetId) {
	constexpr uint32_t CPolylineSet_vtable = 0x820F1948;
	if (!UseLiftedCode(142, 0x83237F70)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = polylineSetId; __imp__sub_83237F70(ctx, base); return; }
	LiftedFrame frame(0x83237F70);
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	polylineSet->m_id = polylineSetId;
	polylineSet->m_8 = 0;
	polylineSet->vtable = CPolylineSet_vtable;
	polylineSet->m_entriesBegin = 0;
	polylineSet->m_entriesEnd = 0;
	polylineSet->m_18 = 0;
	polylineSet->m_flag = 0;
	polylineSet->m_version = 0;
}
PROMOTED_ENTRY(142, sub_83237F70, 0x83237F70) { CPolylineSet_Ctor(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CPolylineSet_ReadNamed(CpuState& ctx, uint8_t* base, uint64_t polylineSetAddr, uint64_t serializer, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr int32_t defaultNameText = int32_t(0x8209003F);
	constexpr int32_t TXT_8349E5FC_G_ = int32_t(0x8349E5FC);
	constexpr uint32_t objectNameSlot = 0x8349E5E8;
	constexpr uint32_t versionNameSlot = 0x8349E600;
	constexpr uint32_t entryCountNameSlot = 0x8349E5EC;
	constexpr uint32_t entryMemberNameSlot = 0x8349E5F4;
	constexpr uint32_t pointNameSlot = 0x8349E5F0;
	if (!UseLiftedCode(142, 0x83238600)) { ctx.r3.u64 = polylineSetAddr; ctx.r4.u64 = serializer; ctx.r5.u64 = forwardedArg1; ctx.r6.u64 = forwardedArg2; __imp__sub_83238600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83238600);
	uint32_t stack = ctx.r1.u64;
	CPolylineSet* polylineSet = GameObject<CPolylineSet>(base, polylineSetAddr);
	stack = PushStackFrame(base, stack, 224);
	const uint32_t pointCountSlot = stack + 80;
	const uint32_t entryCountSlot = stack + 84;
	const uint32_t versionSlot = stack + 88;
	const uint32_t pointSlot = stack + 96;

	// Each field is serialized under a name: the first word of the data a name slot points to, or
	// defaultNameText when the slot is empty. The serializer methods take it as their second argument (r4).
	auto nameText = [&](uint32_t nameSlot) -> uint64_t {
		const uint32_t nameData = LOAD32(nameSlot);
		return nameData != 0 ? uint64_t(LOAD32(nameData)) : uint64_t(int64_t(defaultNameText));
	};

	// The serializer's begin method (vtable slot 1); everything else happens only when it succeeds.
	const uint32_t beginMethod = LOAD32(LOAD32((uint32_t)serializer) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = serializer;
	ctx.r4.u64 = nameText(objectNameSlot);
	ctx.r5.u64 = forwardedArg1;
	ctx.r6.u64 = forwardedArg2;
	ctx.r10.u64 = beginMethod;
	REX_CALL_INDIRECT_FUNC(beginMethod);
	const uint32_t begun = (uint32_t)ctx.r3.u64 & 0xFF;
	if (begun != 0) {
		ctx.r9.u64 = begun;
		CProperty_ProcessValue(ctx, base, (uint32_t)TXT_8349E5FC_G_, serializer, polylineSetAddr + 28);

		// The version goes through a stack slot and is not stored back.
		const uint32_t version = polylineSet->m_version;
		STORE32(versionSlot, version);
		ctx.r4.u64 = nameText(versionNameSlot);
		ctx.r9.u64 = version;
		IStream_SerializeId(ctx, base, serializer, versionSlot);

		STORE32(entryCountSlot, 0);
		ctx.r4.u64 = nameText(entryCountNameSlot);
		IStream_SerializeU32(ctx, base, serializer, entryCountSlot);
		Vector_Resize20(ctx, base, (uint32_t)polylineSetAddr + 12, LOAD32(entryCountSlot));

		// Four further values the original code hands to the first serializer call of each entry and of each
		// point, as it holds them: what the last resize left, and after a point its count, third word, address
		// and second word.
		uint64_t carriedArg4 = ctx.r6.u64;
		uint64_t carriedArg5 = ctx.r7.u64;
		uint64_t carriedArg6 = ctx.r8.u64;
		uint64_t carriedArg7 = ctx.r9.u64;

		// Per 20-byte entry: its word at +16 and its point count (the points vector is resized to it), then the
		// three words of each 12-byte point.
		uint64_t entryOffset = 0;
		for (int32_t entryIndex = 0; entryIndex < (int32_t)LOAD32(entryCountSlot); ++entryIndex, entryOffset += 20) {
			const uint64_t entryAddr = (uint64_t)polylineSet->m_entriesBegin + entryOffset;
			ctx.r4.u64 = nameText(entryMemberNameSlot);
			ctx.r6.u64 = carriedArg4;
			ctx.r7.u64 = carriedArg5;
			ctx.r8.u64 = carriedArg6;
			ctx.r9.u64 = carriedArg7;
			IStream_SerializeU32(ctx, base, serializer, entryAddr + 16);

			STORE32(pointCountSlot, 0);
			ctx.r4.u64 = nameText(pointNameSlot);
			IStream_SerializeU32(ctx, base, serializer, pointCountSlot);
			const uint32_t pointCount = LOAD32(pointCountSlot);
			Vector_Resize12(ctx, base, uint32_t(polylineSet->m_entriesBegin) + (uint32_t)entryOffset, pointCount);
			carriedArg4 = ctx.r6.u64;
			carriedArg5 = ctx.r7.u64;
			carriedArg6 = ctx.r8.u64;
			carriedArg7 = ctx.r9.u64;

			uint64_t pointOffset = 0;
			for (int32_t pointIndex = 0; pointIndex < (int32_t)LOAD32(pointCountSlot); ++pointIndex, pointOffset += 12) {
				STORE32(pointSlot, 0);
				STORE32(pointSlot + 4, 0);
				STORE32(pointSlot + 8, 0);
				ctx.r4.u64 = nameText(pointNameSlot);
				ctx.r6.u64 = carriedArg4;
				ctx.r7.u64 = carriedArg5;
				ctx.r8.u64 = carriedArg6;
				ctx.r9.u64 = carriedArg7;
				IStream_SerializeId(ctx, base, serializer, pointSlot);
				ctx.r4.u64 = nameText(pointNameSlot);
				IStream_SerializeId(ctx, base, serializer, pointSlot + 4);
				ctx.r4.u64 = nameText(pointNameSlot);
				IStream_SerializeId(ctx, base, serializer, pointSlot + 8);

				const uint32_t pointEntry = uint32_t(polylineSet->m_entriesBegin) + (uint32_t)entryOffset;
				const uint32_t secondWord = LOAD32(pointSlot + 4);
				const uint32_t thirdWord = LOAD32(pointSlot + 8);
				const uint64_t pointAddr = (uint64_t)LOAD32(pointEntry + 4) + pointOffset;
				STORE32((uint32_t)pointAddr, LOAD32(pointSlot));
				STORE32((uint32_t)pointAddr + 4, secondWord);
				STORE32((uint32_t)pointAddr + 8, thirdWord);
				carriedArg4 = LOAD32(pointCountSlot);
				carriedArg5 = thirdWord;
				carriedArg6 = pointAddr;
				carriedArg7 = secondWord;
			}
		}

		ctx.r5.u64 = forwardedArg1;
		ctx.r6.u64 = forwardedArg2;
		ctx.r7.u64 = 0;
		ctx.r8.u64 = carriedArg6;
		CRegistrableThing_LoadId(ctx, base, polylineSetAddr, serializer);

		// The serializer's end method (vtable slot 3).
		const uint32_t endMethod = LOAD32(LOAD32((uint32_t)serializer) + 12);
		ctx.r3.u64 = serializer;
		ctx.r10.u64 = endMethod;
		REX_CALL_INDIRECT_FUNC(endMethod);
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_83238600, 0x83238600) { ctx.r3.u64 = CPolylineSet_ReadNamed(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }
