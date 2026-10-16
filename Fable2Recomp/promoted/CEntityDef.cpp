// CEntityDef (vtable 0x82002660): methods of the class as readable C++.
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

// Stores the rotation (four floats passed by value in r4/r5) in m_10/m_18 and rebuilds the matrix at +32
// from that rotation, the position vector at +80 and a constant uniform scale.
uint32_t n_sub_82A0B288(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr, uint64_t rotationLo, uint64_t rotationHi) {
	if (!UseLiftedCode(72, 0x82A0B288)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = rotationLo; ctx.r5.u64 = rotationHi; __imp__sub_82A0B288(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A0B288);
	uint32_t stack = ctx.r1.u32;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);

	stack = PushStackFrame(base, stack, 112);

	// the rotation is spilled to its parameter home slots and read back from there after the matrix is built
	uint32_t savedRotationAddr = stack + 144;
	STORE64(savedRotationAddr, rotationLo);
	STORE64(savedRotationAddr + 8, rotationHi);

	uint32_t transformAddr = entityDefAddr + 32;

	// Broadcast the constant uniform scale into a vector for the matrix builder.
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, LOAD_F32(0x820994C0u));
	const uint32_t scaleAddr = stack + 80;
	PPCVRegister packedScale;
	SET_V8(packedScale, simde_mm_shuffle_epi8(
		simde_mm_load_si128((simde__m128i*)RAW(scaleAddr & ~0xF)),
		simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scaleAddr & 0xF) * 16])));
	PPCVRegister scaleVector;
	SET_V8(scaleVector, simde_mm_shuffle_epi32(V8(packedScale), 0xFF));

	PPCVRegister position;
	SET_V8(position, VLOAD((entityDefAddr + 80u) & ~0xF));

	ctx.r1.u64 = stack;
	ctx.v1 = position;
	ctx.v2 = scaleVector;
	Math_BuildOrthonormalMatrix(ctx, base, transformAddr, rotationLo, rotationHi);

	entityDef->m_AC = entityDef->m_AC + 1;
	uint64_t storedRotationLo = LOAD64(savedRotationAddr);
	uint64_t storedRotationHi = LOAD64(savedRotationAddr + 8);
	entityDef->m_10 = storedRotationLo;
	entityDef->m_18 = storedRotationHi;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = storedRotationLo; // callers read r6 after the call
	return transformAddr;
}
PROMOTED_ENTRY(72, sub_82A0B288, 0x82A0B288) { ctx.r3.u64 = n_sub_82A0B288(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t CEntityDef_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t entityDefAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(73, 0x82A10950)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82A10950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A10950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	const uint32_t vector32Addr = uint32_t(entityDefAddr + 140);
	const uint32_t vector16Addr = uint32_t(entityDefAddr + 96);

	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags; // state the callee may pass on
	OwnedPtrVector32_Destroy(ctx, base, vector32Addr);
	OwnedPtrVector16_Destroy(ctx, base, vector16Addr);
	entityDef->vtable = 0x820F1A5Cu;
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, entityDefAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return entityDefAddr;
}
PROMOTED_ENTRY(73, sub_82A10950, 0x82A10950) { ctx.r3.u64 = CEntityDef_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_83216518(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(141, 0x83216518)) { ctx.r3.u64 = entityDefAddr; __imp__sub_83216518(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83216518);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t vector32Addr = (int32_t)entityDefAddr + 140;
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, vector32Addr);
	uint32_t vector16Addr = (int32_t)entityDefAddr + 96;
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, vector16Addr);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_83216518, 0x83216518) { ctx.r3.u64 = n_sub_83216518(ctx, base, ctx.r3.u32); }

uint32_t n_sub_83217058(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(141, 0x83217058)) { ctx.r3.u64 = entityDefAddr; __imp__sub_83217058(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83217058);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, entityDefAddr + 140);
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, entityDefAddr + 96);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_83217058, 0x83217058) { ctx.r3.u64 = n_sub_83217058(ctx, base, ctx.r3.u32); }

uint64_t n_sub_8321E9E0(CpuState& ctx, uint8_t* base, uint64_t entityDefAddr, uint64_t stream) {
	if (!UseLiftedCode(141, 0x8321E9E0)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = stream; __imp__sub_8321E9E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8321E9E0);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 128);

	PPCRegister callTarget{};
	uint32_t fn{};

	fn = LOAD32(uint32_t(entityDef->vtable) + 20);
	callTarget.u64 = (uint64_t)fn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = entityDefAddr;
	ctx.r4.u64 = stream;
	ctx.r10.u64 = fn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t flags = ctx.r3.u32;

	uint32_t id = entityDef->m_id;

	uint32_t extraId = 0;
	if ((int32_t)flags == 0) {
		fn = LOAD32(uint32_t(entityDef->vtable) + 60);
		callTarget.u64 = (uint64_t)fn;
		ctx.r3.u64 = entityDefAddr;
		ctx.r10.u64 = fn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		extraId = ctx.r3.u32;
	}

	BinaryStream_WriteUInt32(ctx, base, stream, flags);
	BinaryStream_WriteUInt32(ctx, base, stream, id);
	BinaryStream_WriteUInt32(ctx, base, stream, extraId);

	fn = LOAD32(uint32_t(entityDef->vtable) + 32);
	callTarget.u64 = (uint64_t)fn;
	ctx.r3.u64 = entityDefAddr;
	ctx.r4.u64 = stream;
	ctx.r10.u64 = fn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_8321E9E0, 0x8321E9E0) { ctx.r3.u64 = n_sub_8321E9E0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8321EA78(CpuState& ctx, uint8_t* base, uint64_t entityDefAddr, uint64_t stream, uint64_t flags) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(141, 0x8321EA78)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = stream; ctx.r5.u64 = flags; __imp__sub_8321EA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8321EA78);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 128);

	// A nonzero low byte of flags wraps the body in calls to stream vtable slots 1 and 3; slot 1's result gates the body.
	const bool wrapped = ((uint32_t)flags & 0xFF) != 0;
	// r4/r5 as the previous call left them; the next stream or entity call receives them
	uint64_t liveR4 = stream;
	uint64_t liveR5 = flags;
	uint64_t result = 1;

	if (wrapped) {
		uint32_t globalSlot = LOAD32((uint32_t)g_834A0000 - 7088);
		uint64_t globalValue = (globalSlot == 0) ? (uint64_t)g_8209003F : (uint64_t)LOAD32(globalSlot);
		uint32_t streamFn4 = LOAD32(LOAD32((uint32_t)stream) + 4);
		callTarget.u64 = streamFn4;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stream;
		ctx.r4.u64 = globalValue;
		ctx.r5.u64 = flags;
		ctx.r10.u64 = streamFn4;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		liveR4 = ctx.r4.u64;
		liveR5 = ctx.r5.u64;
	}

	if (((uint32_t)result & 0xFF) != 0) {
		uint32_t entityFn20 = LOAD32(uint32_t(entityDef->vtable) + 20);
		callTarget.u64 = entityFn20;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = entityDefAddr;
		ctx.r4.u64 = liveR4;
		ctx.r5.u64 = liveR5;
		ctx.r10.u64 = entityFn20;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t state = ctx.r3.u32;

		// three-word header for n_sub_8321E8E8: state, id, and the slot-15 value when state is zero
		uint32_t headerAddr = stack + 80;
		uint32_t entityId = entityDef->m_id;
		STORE32(headerAddr, state);
		STORE32(headerAddr + 4, entityId);

		// r9 for n_sub_8321E8E8: the id, or what the slot-15 call left in r9
		uint64_t liveR9 = entityId;
		if ((int32_t)state == 0) {
			uint32_t entityFn60 = LOAD32(uint32_t(entityDef->vtable) + 60);
			callTarget.u64 = entityFn60;
			ctx.r3.u64 = entityDefAddr;
			ctx.r9.u64 = entityId;
			ctx.r10.u64 = entityFn60;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t extra = ctx.r3.u32;
			liveR9 = ctx.r9.u64;
			STORE32(headerAddr + 8, extra);
		} else {
			STORE32(headerAddr + 8, 0u);
		}

		ctx.r9.u64 = liveR9; // state the callee may pass on
		n_sub_8321E8E8(ctx, base, stream, headerAddr);

		uint32_t entityFn40 = LOAD32(uint32_t(entityDef->vtable) + 40);
		callTarget.u64 = entityFn40;
		ctx.r3.u64 = entityDefAddr;
		ctx.r4.u64 = stream;
		ctx.r10.u64 = entityFn40;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		liveR4 = ctx.r4.u64;
		liveR5 = ctx.r5.u64;
	}

	if (wrapped) {
		uint32_t streamFn12 = LOAD32(LOAD32((uint32_t)stream) + 12);
		callTarget.u64 = streamFn12;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stream;
		ctx.r4.u64 = liveR4;
		ctx.r5.u64 = liveR5;
		ctx.r10.u64 = streamFn12;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		liveR4 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = liveR4; // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(141, sub_8321EA78, 0x8321EA78) { ctx.r3.u64 = n_sub_8321EA78(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_8321EB70(CpuState& ctx, uint8_t* base, uint64_t entityDefAddr, uint64_t stream, uint64_t forwardedArg3, uint64_t forwardedArg4, uint64_t flags) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(141, 0x8321EB70)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = stream; ctx.r5.u64 = forwardedArg3; ctx.r6.u64 = forwardedArg4; ctx.r7.u64 = flags; __imp__sub_8321EB70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8321EB70);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);

	stack = PushStackFrame(base, stack, 144);

	// A nonzero low byte of flags wraps the body in calls to stream vtable slots 1 and 3; slot 1's result gates the body.
	const bool wrapped = ((uint32_t)flags & 0xFF) != 0;
	// r4-r7 as the previous call left them; later calls receive them
	uint64_t liveR4 = stream;
	uint64_t liveR5 = forwardedArg3;
	uint64_t liveR6 = forwardedArg4;
	uint64_t liveR7 = flags;
	uint64_t result = 1;

	if (wrapped) {
		uint32_t globalSlot = LOAD32((uint32_t)g_834A0000 - 7088);
		uint64_t globalValue = (globalSlot == 0) ? (uint64_t)g_8209003F : (uint64_t)LOAD32(globalSlot);
		uint32_t streamFn4 = LOAD32(LOAD32((uint32_t)stream) + 4);
		callTarget.u64 = streamFn4;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stream;
		ctx.r4.u64 = globalValue;
		ctx.r5.u64 = forwardedArg3;
		ctx.r6.u64 = forwardedArg4;
		ctx.r7.u64 = flags;
		ctx.r10.u64 = streamFn4;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		liveR4 = ctx.r4.u64;
		liveR5 = ctx.r5.u64;
		liveR6 = ctx.r6.u64;
		liveR7 = ctx.r7.u64;
	}

	if (((uint32_t)result & 0xFF) != 0) {
		// n_sub_8321E7F0 reads the three-word header from the stream into stack + 80
		uint64_t headerAddr = (uint64_t)stack + 80;
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r5.u64 = liveR5;
		ctx.r6.u64 = liveR6;
		ctx.r7.u64 = liveR7;
		n_sub_8321E7F0(ctx, base, stream, headerAddr);

		uint32_t entityFn36 = LOAD32(uint32_t(entityDef->vtable) + 36);
		callTarget.u64 = entityFn36;
		ctx.r3.u64 = entityDefAddr;
		ctx.r4.u64 = stream;
		ctx.r5.u64 = forwardedArg3;
		ctx.r6.u64 = forwardedArg4;
		ctx.r10.u64 = entityFn36;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		liveR4 = ctx.r4.u64;
		liveR5 = ctx.r5.u64;
		liveR6 = ctx.r6.u64;
		liveR7 = ctx.r7.u64;
	}

	if (wrapped) {
		uint32_t streamFn12 = LOAD32(LOAD32((uint32_t)stream) + 12);
		callTarget.u64 = streamFn12;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stream;
		ctx.r4.u64 = liveR4;
		ctx.r5.u64 = liveR5;
		ctx.r6.u64 = liveR6;
		ctx.r7.u64 = liveR7;
		ctx.r10.u64 = streamFn12;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		liveR4 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = liveR4; // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(141, sub_8321EB70, 0x8321EB70) { ctx.r3.u64 = n_sub_8321EB70(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_8321EC30(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr, uint64_t stream) {
	if (!UseLiftedCode(141, 0x8321EC30)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = stream; __imp__sub_8321EC30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8321EC30);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);

	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	BinaryStream_WriteUInt32(ctx, base, stream, 1);

	PPCVRegister position{};
	SET_V8(position, VLOAD((entityDefAddr + 80u) & ~0xF));
	ctx.v1 = position;
	Stream_WriteVector3(ctx, base, stream);

	// the four rotation floats at m_10..m_1F are copied to the stack and written one by one
	uint64_t rotationLo = entityDef->m_10;
	uint64_t rotationHi = entityDef->m_18;
	STORE64(stack + 96, rotationLo);
	STORE64(stack + 104, rotationHi);

	ctx.fpscr.disableFlushMode();
	// state the callee may pass on
	ctx.r8.u64 = rotationHi;
	ctx.r9.u64 = rotationLo;
	Stream_WriteFloat(ctx, base, stream, double(LOAD_F32(stack + 96)));
	ctx.fpscr.disableFlushMode();
	Stream_WriteFloat(ctx, base, stream, double(LOAD_F32(stack + 100)));
	ctx.fpscr.disableFlushMode();
	Stream_WriteFloat(ctx, base, stream, double(LOAD_F32(stack + 104)));
	ctx.fpscr.disableFlushMode();
	Stream_WriteFloat(ctx, base, stream, double(LOAD_F32(stack + 108)));

	// m_A0 is written as one bool byte through the stream's raw write method (vtable slot 4)
	uint32_t a0Byte = entityDef->m_A0;
	uint32_t a0IsZero = (a0Byte == 0);
	uint32_t a0IsSet = a0IsZero ^ 1;
	uint32_t streamVtable = LOAD32((uint32_t)stream);
	uint32_t writeBytesFn = LOAD32(streamVtable + 16);
	STORE8(stack + 80, (uint8_t)a0IsSet);

	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)writeBytesFn;
	ctx.r3.u64 = stream;
	ctx.r4.u64 = (uint64_t)stack + 80;
	ctx.r5.u64 = 1;
	// state the callee may pass on
	ctx.r6.u64 = streamVtable;
	ctx.r7.u64 = a0Byte;
	ctx.r8.u64 = writeBytesFn;
	ctx.r9.u64 = a0IsSet;
	ctx.r10.u64 = a0IsZero;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	BinaryStream_WriteUInt32(ctx, base, stream, entityDef->m_A4);

	ctx.fpscr.disableFlushMode();
	Stream_WriteFloat(ctx, base, stream, double(entityDef->m_A8));

	uint64_t result = BinaryStream_WriteUInt32(ctx, base, stream, entityDef->m_id);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_8321EC30, 0x8321EC30) { ctx.r3.u64 = n_sub_8321EC30(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_8321ED18  [664 bytes]
// Serializes the definition through a stream: id, the Position vector stored at +80, four floats for the
// matrix built by sub_82A0B288, the UseLife flag (m_A0), a scaled count (m_A4) and a float (m_A8).
uint64_t n_sub_8321ED18(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr, uint64_t stream, uint64_t arg3, uint64_t arg4) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_8335EFF4 = int32_t(0x8335EFF4);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t TXT_8349E468_G_ = int32_t(0x8349E468);
	constexpr int32_t TXT_8349E470_G_ = int32_t(0x8349E470);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(141, 0x8321ED18)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = stream; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_8321ED18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8321ED18);
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 208);

	// Most stream calls get a key (r4) read through a global slot; this constant replaces a null slot.
	const uint64_t defaultKey = g_8209003F;

	// stream->vtbl[1] begins a block and stream->vtbl[3] ends it; a zero result skips the block.
	uint32_t blockKeySlot = LOAD32(0x8349E464u);
	uint64_t blockKey = defaultKey;
	if (blockKeySlot != 0) blockKey = LOAD32(blockKeySlot);
	uint32_t beginFn = LOAD32(LOAD32((uint32_t)stream) + 4);
	callTarget.u64 = beginFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = stream;
	ctx.r4.u64 = blockKey;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r10.u64 = beginFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t blockBegun = ctx.r3.u32 & 0xFF;
	if (blockBegun != 0) {
		// id into stack+88
		STORE32(stack + 88, 0u);
		uint64_t idKey = defaultKey;
		uint32_t idKeySlot = LOAD32(0x8349E47Cu);
		if (idKeySlot != 0) idKey = LOAD32(idKeySlot);
		ctx.r4.u64 = idKey;
		ctx.r9.u64 = blockBegun;
		IStream_SerializeId(ctx, base, stream, (uint64_t)(stack + 88));

		// Position property value into a zeroed vector at stack+128
		PPCVRegister zeroVec{};
		SET_V8(zeroVec, simde_mm_set1_epi32(0));
		VSTORE((stack + 128) & ~0xF, V8(zeroVec));
		n_sub_8322EC98(ctx, base, uint32_t(TXT_8349E468_G_), stream, (uint64_t)(stack + 128));

		// Permute the float constant at 0x820994C0 into the position vector (mask at 0x82099200)
		// and store the result at entityDef+80.
		PPCVRegister positionVec{}, maskVec{}, constantVec{}, mergedVec{};
		PPCRegister scratch{};
		const int32_t constBase = g_820A0000;
		uint32_t positionAddr = stack + 128;
		uint64_t maskAddr = (int64_t)constBase - 28160;
		uint32_t constantSlot = stack + 96;
		uint64_t constantAddr = (int64_t)constBase - 27456;
		ctx.fpscr.disableFlushMode();
		double mergedFloat = double(LOAD_F32((uint32_t)constantAddr));
		uint32_t vectorOffset = 80;
		SET_V8(positionVec, VLOAD(positionAddr & ~0xF));
		SET_V8(maskVec, VLOAD((uint32_t)maskAddr & ~0xF));
		STORE_F32(stack + 96, float(mergedFloat));
		scratch.u32 = constantSlot;
		SET_V8(constantVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(mergedVec, rex::ppc::simde_mm_perm_epi8_(V8(positionVec), V8(constantVec), V8(maskVec)));
		uint32_t oldB0 = entityDef->m_B0;
		VSTORE((entityDefAddr + vectorOffset) & ~0xF, V8(mergedVec));
		entityDef->m_B0 = uint32_t(int32_t(oldB0) + 1);

		// Inner block holding four floats at stack+112..124.
		uint64_t innerKey = defaultKey;
		uint32_t innerKeySlot = LOAD32(0x8349E46Cu);
		if (innerKeySlot != 0) innerKey = LOAD32(innerKeySlot);
		uint32_t innerBeginFn = LOAD32(LOAD32((uint32_t)stream) + 4);
		callTarget.u64 = innerBeginFn;
		// state the callee may pass on
		ctx.r3.u64 = stream;
		ctx.r4.u64 = innerKey;
		ctx.r5.u64 = vectorOffset;
		ctx.r6.u64 = constantSlot;
		ctx.r7.u64 = maskAddr;
		ctx.r8.u64 = positionAddr;
		ctx.r9.s64 = constBase;
		ctx.r10.u64 = innerBeginFn;
		ctx.v11 = mergedVec;
		ctx.v12 = positionVec;
		ctx.v13 = constantVec;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t innerBegun = ctx.r3.u32 & 0xFF;
		if (innerBegun != 0) {
			// r4 = per-float key address; r9 is handed over to the first call only.
			uint64_t floatKeyAddr = (int64_t)constantAddr + 6024;
			ctx.r4.u64 = floatKeyAddr;
			ctx.r9.u64 = innerBegun;
			IStream_SerializeFloat(ctx, base, stream, (uint64_t)(stack + 112));
			floatKeyAddr = (int64_t)constantAddr + 6028;
			ctx.r4.u64 = floatKeyAddr;
			IStream_SerializeFloat(ctx, base, stream, (uint64_t)(stack + 116));
			floatKeyAddr = (int64_t)constantAddr + 6032;
			ctx.r4.u64 = floatKeyAddr;
			IStream_SerializeFloat(ctx, base, stream, (uint64_t)(stack + 120));
			floatKeyAddr = (int64_t)constantAddr + 6036;
			ctx.r4.u64 = floatKeyAddr;
			IStream_SerializeFloat(ctx, base, stream, (uint64_t)(stack + 124));
			uint32_t innerEndFn = LOAD32(LOAD32((uint32_t)stream) + 12);
			callTarget.u64 = innerEndFn;
			ctx.r3.u64 = stream;
			ctx.r10.u64 = innerEndFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}

		// matrix at entityDef+32 from the vector at +80 and the four floats
		n_sub_82A0B288(ctx, base, entityDefAddr, LOAD64(stack + 112), LOAD64(stack + 120));

		CProperty_ProcessValue(ctx, base, uint32_t(TXT_8349E470_G_), stream, (uint64_t)(stack + 80));
		uint32_t useLife = LOAD8(stack + 80);
		entityDef->m_A0 = uint8_t(useLife);
		uint64_t countKey = defaultKey;
		uint32_t countKeySlot = LOAD32(0x8349E474u);
		if (countKeySlot != 0) countKey = LOAD32(countKeySlot);
		ctx.r4.u64 = countKey;
		ctx.r9.u64 = useLife;
		IStream_SerializeU32(ctx, base, stream, (uint64_t)(stack + 104));

		// m_A4 = int(table[index] * table[9] * count): floats at 0x8335EFF4, index read from 0x83496C00.
		uint32_t tableIndex = LOAD32(uint32_t(g_83490000) + 27648);
		ctx.fpscr.disableFlushMode();
		double defaultA8 = double(LOAD_F32((uint32_t)constantAddr + 5992));
		int32_t serializedCount = int32_t(LOAD32(stack + 104));
		STORE_F32(stack + 84, float(defaultA8));
		STORE64(stack + 96, (uint64_t)(int64_t)serializedCount);
		PPCRegister countBits{};
		countBits.f64 = LOAD_F64(stack + 96);
		double countAsDouble = double(countBits.s64);
		uint64_t floatTable = g_8335EFF4;
		uint32_t tableOffset = tableIndex << 2;
		double tableValue = double(LOAD_F32(tableOffset + (uint32_t)floatTable));
		double tableProduct = double(float(tableValue * double(LOAD_F32((uint32_t)floatTable + 36))));
		double scaledCount = double(float(tableProduct * double(float(countAsDouble))));
		PPCRegister converted{};
		converted.s64 = std::isnan(scaledCount) ? int64_t(0x80000000U) : scaledCount > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&scaledCount));
		STORE32(entityDefAddr + 164, converted.u32);

		// float into stack+84, preset to the constant at 0x8209AC28
		uint64_t floatKey = defaultKey;
		uint32_t floatKeySlot = LOAD32(0x8349E478u);
		if (floatKeySlot != 0) floatKey = LOAD32(floatKeySlot);
		// state the callee may pass on
		ctx.r4.u64 = floatKey;
		ctx.r6.u64 = tableOffset;
		ctx.r7.s64 = g_834A0000;
		ctx.r8.u64 = floatTable;
		ctx.r9.u64 = 164;
		ctx.f7 = converted;
		ctx.f8.f64 = scaledCount;
		ctx.f9.f64 = double(float(countAsDouble));
		ctx.f10.f64 = countAsDouble;
		ctx.f11 = countBits;
		ctx.f12.f64 = tableProduct;
		ctx.f13.f64 = tableValue;
		IStream_SerializeFloat(ctx, base, stream, (uint64_t)(stack + 84));
		double handoverF13 = ctx.f13.f64;
		// With a zero id the float is capped at that same constant.
		if (LOAD32(stack + 88) == 0) {
			ctx.fpscr.disableFlushMode();
			double capA8 = double(LOAD_F32((uint32_t)constantAddr + 5992));
			handoverF13 = double(LOAD_F32(stack + 84));
			if (handoverF13 > capA8) {
				STORE_F32(stack + 84, float(capA8));
			}
		}
		ctx.fpscr.disableFlushMode();
		double valueA8 = double(LOAD_F32(stack + 84));
		entityDef->m_A8 = float(valueA8);
		// state the callee may pass on
		ctx.r5.u64 = arg3;
		ctx.r6.u64 = arg4;
		ctx.r7.u64 = 0;
		ctx.f13.f64 = handoverF13;
		CRegistrableThing_LoadId(ctx, base, entityDefAddr, stream);
		uint32_t endFn = LOAD32(LOAD32((uint32_t)stream) + 12);
		callTarget.u64 = endFn;
		ctx.r3.u64 = stream;
		ctx.r10.u64 = endFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(141, sub_8321ED18, 0x8321ED18) { ctx.r3.u64 = n_sub_8321ED18(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_8321F548  [80 bytes]
// Reads one record from the stream into a local buffer that is not used afterwards, then calls
// entityDef->vtbl[7](entityDef, stream, arg3, arg4).
uint64_t n_sub_8321F548(CpuState& ctx, uint8_t* base, uint64_t entityDefAddr, uint64_t stream, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(141, 0x8321F548)) { ctx.r3.u64 = entityDefAddr; ctx.r4.u64 = stream; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_8321F548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8321F548);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);

	stack = PushStackFrame(base, stack, 144);
	uint32_t discardBuffer = stack + 80;
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;  // state the callee may pass on
	n_sub_8321F328(ctx, base, stream, discardBuffer);

	uint32_t virtualMethod = LOAD32(uint32_t(entityDef->vtable) + 28);
	ctx.r3.u64 = entityDefAddr;
	ctx.r4.u64 = stream;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(141, sub_8321F548, 0x8321F548) { ctx.r3.u64 = n_sub_8321F548(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_8321F618  [80 bytes]
uint32_t n_sub_8321F618(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(141, 0x8321F618)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8321F618(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8321F618);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t vector32Addr = entityDefAddr + 140;
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, vector32Addr);
	uint32_t vector16Addr = entityDefAddr + 96;
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, vector16Addr);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(141, sub_8321F618, 0x8321F618) { ctx.r3.u64 = n_sub_8321F618(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8323A908(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(142, 0x8323A908)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8323A908(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323A908);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, entityDefAddr + 140);
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, entityDefAddr + 96);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323A908, 0x8323A908) { ctx.r3.u64 = n_sub_8323A908(ctx, base, ctx.r3.u32); }

// sub_8323B040  [80 bytes]
uint32_t n_sub_8323B040(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(142, 0x8323B040)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8323B040(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323B040);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, entityDefAddr + 140);
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, entityDefAddr + 96);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323B040, 0x8323B040) { ctx.r3.u64 = n_sub_8323B040(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8323BAC8(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(142, 0x8323BAC8)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8323BAC8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323BAC8);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, entityDefAddr + 140);
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, entityDefAddr + 96);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323BAC8, 0x8323BAC8) { ctx.r3.u64 = n_sub_8323BAC8(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8323C5C0(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(142, 0x8323C5C0)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8323C5C0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323C5C0);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, entityDefAddr + 140);
	uint32_t destroyResult = OwnedPtrVector16_Destroy(ctx, base, entityDefAddr + 96);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return destroyResult;
}
PROMOTED_ENTRY(142, sub_8323C5C0, 0x8323C5C0) { ctx.r3.u64 = n_sub_8323C5C0(ctx, base, ctx.r3.u32); }

// sub_8323D6D0  [152 bytes]
uint32_t n_sub_8323D6D0(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(142, 0x8323D6D0)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8323D6D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323D6D0);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 112);
	entityDef->vtable = 0x820F1908u;
	entityDef->m_F8 = 0x820F1B74u;
	uint32_t handleTarget = entityDef->m_100;
	if (handleTarget != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, handleTarget);
	}
	// clear the three words at +0x100..+0x108
	entityDef->m_100 = 0u;
	STORE32(entityDefAddr + 260, 0u);
	STORE32(entityDefAddr + 264, 0u);

	// then the CEntityDef part (vtable 0x82002660)
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, entityDefAddr + 140);
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, entityDefAddr + 96);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323D6D0, 0x8323D6D0) { ctx.r3.u64 = n_sub_8323D6D0(ctx, base, ctx.r3.u32); }

// sub_8323E5D8  [80 bytes]
uint32_t n_sub_8323E5D8(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(142, 0x8323E5D8)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8323E5D8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323E5D8);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t vector32Addr = entityDefAddr + 140;
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, vector32Addr);
	uint32_t vector16Addr = entityDefAddr + 96;
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, vector16Addr);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323E5D8, 0x8323E5D8) { ctx.r3.u64 = n_sub_8323E5D8(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8323F120(CpuState& ctx, uint8_t* base, uint32_t entityDefAddr) {
	if (!UseLiftedCode(142, 0x8323F120)) { ctx.r3.u64 = entityDefAddr; __imp__sub_8323F120(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323F120);
	uint32_t stack = ctx.r1.u64;
	CEntityDef* entityDef = GameObject<CEntityDef>(base, entityDefAddr);
	stack = PushStackFrame(base, stack, 112);
	entityDef->vtable = 0x820F1890u;
	entityDef->m_C4 = 0x820F1B74u;
	uint32_t targetHandle = entityDef->m_CC;
	if (targetHandle != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, targetHandle);
	}
	entityDef->m_CC = 0;
	STORE32(entityDefAddr + 0xD0, 0);
	STORE32(entityDefAddr + 0xD4, 0);
	entityDef->vtable = 0x82002660u;
	ctx.r1.u64 = stack;
	OwnedPtrVector32_Destroy(ctx, base, entityDefAddr + 140);
	uint32_t result = OwnedPtrVector16_Destroy(ctx, base, entityDefAddr + 96);
	entityDef->vtable = 0x820F1A5Cu;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323F120, 0x8323F120) { ctx.r3.u64 = n_sub_8323F120(ctx, base, ctx.r3.u32); }
