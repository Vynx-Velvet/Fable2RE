// CEmitterGroup (vtable 0x8200C37C): methods of the class as readable C++.
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

// sub_8220A608  [12 bytes]
void CEmitterGroup_SetPosition(CpuState& ctx, uint8_t* base, uint32_t emitterGroupAddr) {
	if (!UseLiftedCode(5, 0x8220A608)) { ctx.r3.u64 = emitterGroupAddr; __imp__sub_8220A608(ctx, base); return; }
	LiftedFrame frame(0x8220A608);
	PPCVRegister position = ctx.v1;
	VSTORE((emitterGroupAddr + 80u) & ~0xF, V8(position));
	return;
}
PROMOTED_ENTRY(5, sub_8220A608, 0x8220A608) { CEmitterGroup_SetPosition(ctx, base, ctx.r3.u32); }

// Copies m_24 and the vector at +80 (the one CEmitterGroup_SetPosition stores) to the two output addresses.
void n_sub_82C3E008(CpuState& ctx, uint8_t* base, uint32_t emitterGroupAddr, uint32_t outM24Addr, uint32_t outPositionAddr) {
	if (!UseLiftedCode(91, 0x82C3E008)) { ctx.r3.u64 = emitterGroupAddr; ctx.r4.u64 = outM24Addr; ctx.r5.u64 = outPositionAddr; __imp__sub_82C3E008(ctx, base); return; }
	LiftedFrame frame(0x82C3E008);
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);
	STORE32(outM24Addr, uint32_t(emitterGroup->m_24));
	PPCVRegister position{};
	SET_V8(position, VLOAD((emitterGroupAddr + 80u) & ~0xF));
	VSTORE(outPositionAddr & ~0xF, V8(position));
}
PROMOTED_ENTRY(91, sub_82C3E008, 0x82C3E008) { n_sub_82C3E008(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32); }

// Polar method: draws u and v as 2 * rand / 32767 - 1 until s = u*u + v*v lies strictly between the threshold
// at 0x820990B0 (1e-4) and 1 and Math_IsNaN(s) is zero, then returns
// mean + stdDev * u * sqrt(-2 ln s / s) / (2 pi) in f1. The integer result is Math_IsNaN's zero.
// The constants are read from the image (1.0, 2.0, 1/32767, -2.0, 2 pi).
// randR8 is r8 as the caller left it: CRT_Rand only forwards r8 down to _getptd.
uint32_t Random_Gaussian(CpuState& ctx, uint8_t* base, uint64_t randR8, double mean, double stdDev) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(91, 0x82C3E020)) { ctx.r8.u64 = randR8; ctx.f1.f64 = mean; ctx.f2.f64 = stdDev; __imp__sub_82C3E020(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C3E020);
	uint32_t stack = ctx.r1.u64;

	// Registers handed to the first CRT_Rand of every round: their entry values in the first round, later what
	// the previous round left in them (f5-f10 hold its v terms).
	uint64_t r3Carry = ctx.r3.u64;
	uint64_t r9Carry = uint64_t(int64_t(g_82000000));
	uint64_t r10Carry = uint64_t(int64_t(g_82000000));
	double f1Carry = mean;
	double f2Carry = stdDev;
	double v = ctx.f5.f64;
	double vUnit = ctx.f6.f64;
	double rand2Float = ctx.f7.f64;
	double rand2Double = ctx.f8.f64;
	PPCRegister rand2Bits = ctx.f9;
	double uSquared = ctx.f10.f64;
	double u{};
	double s{};

	stack = PushStackFrame(base, stack, 176);
	ctx.fpscr.disableFlushMode();
	const double one = double(LOAD_F32(0x82000C08u));
	const double two = double(LOAD_F32(0x82000C44u));
	const double invRandMax = double(LOAD_F32(0x82000C14u));

	for (;;) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = r3Carry;
		ctx.r9.u64 = r9Carry;
		ctx.r10.u64 = r10Carry;
		ctx.f1.f64 = f1Carry;
		ctx.f2.f64 = f2Carry;
		ctx.f5.f64 = v;
		ctx.f6.f64 = vUnit;
		ctx.f7.f64 = rand2Float;
		ctx.f8.f64 = rand2Double;
		ctx.f9 = rand2Bits;
		ctx.f10.f64 = uSquared;
		uint64_t rand1 = CRT_Rand(ctx, base, randR8);
		f1Carry = ctx.f1.f64;
		f2Carry = ctx.f2.f64;
		STORE64(stack + 80, (uint64_t)(int64_t)(int32_t)rand1);
		ctx.fpscr.disableFlushMode();
		PPCRegister rand1Bits{};
		rand1Bits.f64 = LOAD_F64(stack + 80);
		double rand1Double = double(rand1Bits.s64);
		double rand1Float = double(float(rand1Double));
		double uUnit = double(float(rand1Float * invRandMax));
		u = double(float(std::fma(uUnit, two, -one)));

		// state the callee may pass on
		ctx.r3.u64 = rand1;
		ctx.f11.f64 = uUnit;
		ctx.f12.f64 = rand1Float;
		ctx.f13.f64 = rand1Double;
		uint64_t rand2 = CRT_Rand(ctx, base, ctx.r8.u64);
		r3Carry = rand2;
		randR8 = ctx.r8.u64;
		r9Carry = ctx.r9.u64;
		f1Carry = ctx.f1.f64;
		f2Carry = ctx.f2.f64;
		r10Carry = (int32_t)rand2;
		ctx.fpscr.disableFlushMode();
		uSquared = double(float(u * u));
		STORE64(stack + 88, r10Carry);
		rand2Bits.f64 = LOAD_F64(stack + 88);
		rand2Double = double(rand2Bits.s64);
		rand2Float = double(float(rand2Double));
		vUnit = double(float(rand2Float * invRandMax));
		v = double(float(std::fma(vUnit, two, -one)));
		s = double(float(std::fma(v, v, uSquared)));
		if (!(s < one)) continue;
		if (!(s > double(LOAD_F32(0x820990B0u)))) continue;

		f1Carry = s;
		// state the callee may pass on
		ctx.r3.u64 = r3Carry;
		ctx.r10.u64 = r10Carry;
		r3Carry = Math_IsNaN(ctx, base, s);
		r10Carry = ctx.r10.u64;
		if ((int32_t)r3Carry == 0) break;
	}

	ctx.fpscr.disableFlushMode();
	double logS = log(ctx, base, s);
	ctx.fpscr.disableFlushMode();
	double logSFloat = double(float(logS));
	double minusTwo = double(LOAD_F32(0x82000C60u));
	double twoPi = double(LOAD_F32(0x820990A4u));
	double minusTwoLogS = double(float(logSFloat * minusTwo));
	double ratio = double(float(minusTwoLogS / s));
	double factor = double(float(sqrt(ratio)));
	double gaussian = double(float(factor * u));
	double gaussianOverTwoPi = double(float(gaussian / twoPi));
	double sample = double(float(std::fma(gaussianOverTwoPi, stdDev, mean)));
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = sample;   // the sample is returned in f1
	return 0;
}
PROMOTED_ENTRY(91, sub_82C3E020, 0x82C3E020) { ctx.r3.u64 = Random_Gaussian(ctx, base, ctx.r8.u64, ctx.f1.f64, ctx.f2.f64); }

// Picks a random point in a ring around the origin in the XZ plane: angle = m_64 + m_60 * (rand / 32767 - 0.5),
// radius uniform between the floats at radiusRangeAddr + 8 and + 12. Stores (cos * radius, c, sin * radius, c) to
// outVecAddr, c being the constant at 0x82000C0C (0.0). Returns its z stack slot address (left in r3), sin in f1.
// randR8 is r8 as the caller left it: CRT_Rand only forwards r8 down to _getptd.
uint32_t n_sub_82C3E118(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr, uint64_t outVecAddr, uint64_t radiusRangeAddr, uint64_t randR8) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(91, 0x82C3E118)) { ctx.r3.u64 = emitterGroupAddr; ctx.r4.u64 = outVecAddr; ctx.r5.u64 = radiusRangeAddr; ctx.r8.u64 = randR8; __imp__sub_82C3E118(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C3E118);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vecAt80{};
	PPCVRegister vecAt84{};
	PPCVRegister vecAt88{};
	PPCVRegister vecAt96{};
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);
	stack = PushStackFrame(base, stack, 160);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = emitterGroupAddr;
	ctx.r4.u64 = outVecAddr;
	ctx.r5.u64 = radiusRangeAddr;
	uint64_t randAngle = CRT_Rand(ctx, base, randR8);
	ctx.fpscr.disableFlushMode();
	double angleSpread = double(emitterGroup->m_60);
	double angleCenter = double(emitterGroup->m_64);
	STORE64(stack + 96, (uint64_t)(int64_t)(int32_t)randAngle);
	PPCRegister randAngleBits;
	randAngleBits.f64 = LOAD_F64(stack + 96);
	double randAngleDouble = double(randAngleBits.s64);
	double randAngleFloat = double(float(randAngleDouble));
	double half = double(LOAD_F32(0x82000BF0u));
	double invRandMax = double(LOAD_F32(0x82000C14u));
	double halfSpread = double(float(angleSpread * half));
	double randAngleUnit = double(float(randAngleFloat * invRandMax));
	double angleOffset = double(float(std::fma(angleSpread, randAngleUnit, -halfSpread)));
	double angle = double(float(angleOffset + angleCenter));

	// state the callee may pass on
	ctx.r3.u64 = randAngle;
	ctx.r9.s64 = g_82000000;
	ctx.r10.s64 = g_82000000;
	ctx.f6.f64 = angleOffset;
	ctx.f7.f64 = randAngleUnit;
	ctx.f8.f64 = angleCenter;
	ctx.f9.f64 = halfSpread;
	ctx.f10.f64 = randAngleFloat;
	ctx.f11.f64 = randAngleDouble;
	ctx.f12 = randAngleBits;
	ctx.f13.f64 = angleSpread;
	uint32_t randRadius = CRT_Rand(ctx, base, ctx.r8.u64);
	int32_t randRadiusInt = (int32_t)randRadius;
	ctx.fpscr.disableFlushMode();
	double radiusMin = double(LOAD_F32((uint32_t)radiusRangeAddr + 8));
	double radiusMax = double(LOAD_F32((uint32_t)radiusRangeAddr + 12));
	STORE64(stack + 96, (uint64_t)(int64_t)randRadiusInt);
	PPCRegister randRadiusBits;
	randRadiusBits.f64 = LOAD_F64(stack + 96);
	double randRadiusDouble = double(randRadiusBits.s64);
	double randRadiusFloat = double(float(randRadiusDouble));
	double radiusSpan = double(float(radiusMax - radiusMin));
	double randRadiusUnit = double(float(randRadiusFloat * invRandMax));
	double radius = double(float(std::fma(radiusSpan, randRadiusUnit, radiusMin)));

	// state the callee may pass on
	ctx.r8.s64 = randRadiusInt;
	ctx.f2.f64 = randRadiusDouble;
	ctx.f3 = randRadiusBits;
	ctx.f4.f64 = radiusMax;
	// Math_SinApprox adds pi/2 to |angle| before its sine polynomial, so this is cos(angle).
	double cosAngle = Math_SinApprox(ctx, base, angle);
	ctx.fpscr.disableFlushMode();
	double cosAngleFloat = double(float(cosAngle));
	double yAndW = double(LOAD_F32(0x82000C0Cu));
	STORE_F32(stack + 88, float(yAndW));
	STORE_F32(stack + 80, float(cosAngleFloat * radius));
	double sinAngle = Math_Sin(ctx, base, angle);
	ctx.fpscr.disableFlushMode();
	double sinAngleFloat = double(float(sinAngle));
	STORE_F32(stack + 84, float(yAndW));
	uint32_t zSlotAddr = stack + 96;

	// Assemble the output from the floats at stack+80 (x), +84 and +88 (c) and +96 (z): lvlx loads put each
	// float in element 0, the blends insert y from +84, then z and w from +96 and +88.
	scratch.u32 = stack + 80;
	SET_V8(vecAt80, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = stack + 88;
	SET_V8(vecAt88, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = stack + 84;
	SET_V8(vecAt84, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(vecAt80, simde_mm_blend_ps(VF(vecAt80), simde_mm_permute_ps(VF(vecAt84), 57), 4));
	STORE_F32(stack + 96, float(sinAngleFloat * radius));
	scratch.u32 = zSlotAddr;
	SET_V8(vecAt96, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(vecAt96, simde_mm_blend_ps(VF(vecAt96), simde_mm_permute_ps(VF(vecAt88), 57), 4));
	SET_VF(vecAt80, simde_mm_blend_ps(VF(vecAt80), simde_mm_permute_ps(VF(vecAt96), 78), 3));
	VSTORE(((uint32_t)outVecAddr) & ~0xF, V8(vecAt80));
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = sinAngle;   // callers read f1 after the call
	return zSlotAddr;
}
PROMOTED_ENTRY(91, sub_82C3E118, 0x82C3E118) { ctx.r3.u64 = n_sub_82C3E118(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

// sub_82C3E498  [212 bytes]
// Builds a layer entry from target's first word, has the factory (virtual at +12) create an object into a temporary
// reference, assigns it to the reference at target + 4 and, if one was created, passes that reference to
// n_sub_82C50130 together with the group's +56 member.
uint32_t n_sub_82C3E498(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr, uint64_t factory, uint64_t target) {
	if (!UseLiftedCode(91, 0x82C3E498)) { ctx.r3.u64 = emitterGroupAddr; ctx.r4.u64 = factory; ctx.r5.u64 = target; __imp__sub_82C3E498(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C3E498);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);

	stack = PushStackFrame(base, stack, 208);
	uint32_t layerEntry = stack + 96;
	uint32_t tempRef = stack + 80;   // two words: the pointer, then an object released through its virtual at +4

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = factory;
	ctx.r5.u64 = target;
	n_sub_821D5BA0(ctx, base, layerEntry);

	LayerEntry_SetValues(ctx, base, layerEntry, 0, LOAD32((uint32_t)target));
	LayerEntry_SetField32(ctx, base, layerEntry, 5);
	n_sub_82BFC8F0(ctx, base, layerEntry);
	if (emitterGroup->m_enabled != 0) {
		LayerEntry_SetBit14(ctx, base, layerEntry);
	}

	uint32_t targetRef = (uint32_t)target + 4;

	uint32_t createFn = LOAD32(LOAD32((uint32_t)factory) + 12);
	callTarget.u64 = createFn;
	ctx.r3.u64 = tempRef;
	ctx.r4.u64 = factory;
	ctx.r5.u64 = layerEntry;
	ctx.r10.u64 = createFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint64_t createdRef = ctx.r3.u64;
	RefPtr_Assign(ctx, base, targetRef, createdRef);

	uint32_t tempRefRelease = LOAD32(stack + 84);
	if (tempRefRelease != 0) {
		uint32_t releaseFn = LOAD32(LOAD32(tempRefRelease) + 4);
		callTarget.u64 = releaseFn;
		ctx.r3.u64 = tempRefRelease;
		ctx.r10.u64 = releaseFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	uint32_t assignedPtr = LOAD32(targetRef);
	STORE32(stack + 84, 0);
	STORE32(stack + 80, 0);
	if (assignedPtr != 0) {
		n_sub_82C50130(ctx, base, emitterGroupAddr + 56, targetRef);
	}

	uint32_t result = CCharString_ReleaseMember(ctx, base, layerEntry);
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(91, sub_82C3E498, 0x82C3E498) { ctx.r3.u64 = n_sub_82C3E498(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// sub_82C3E570  [312 bytes]
// Stores a truncated Random_Gaussian sample (mean and deviation both the float at request + 4) at request + 24.
// When m_duration is not below the double at 0x820990B8 (1e-4): gets a point from n_sub_82C3E118, sets up a layer
// entry (handing the point to n_sub_82BFC910 in v1), has the factory (virtual at +12) create an object for it into
// the reference at request + 16 and, if one was created, passes that reference to n_sub_82C50130 with the group's
// +56 member and calls the object's virtual at +12 with m_duration in f1. Returns 1 when an object was created.
// randR8 is r8 as the caller left it, handed on to Random_Gaussian.
uint64_t n_sub_82C3E570(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr, uint64_t factory, uint64_t request, uint64_t randR8) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(91, 0x82C3E570)) { ctx.r3.u64 = emitterGroupAddr; ctx.r4.u64 = factory; ctx.r5.u64 = request; ctx.r8.u64 = randR8; __imp__sub_82C3E570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3E570);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);

	stack = PushStackFrame(base, stack, 224);
	uint32_t requestAddr = (uint32_t)request;
	uint32_t pointSlot = stack + 96;
	uint32_t tempRef = stack + 80;   // two words: the pointer, then an object released through its virtual at +4
	uint32_t layerEntry = stack + 112;

	ctx.fpscr.disableFlushMode();
	double gaussianParam = double(LOAD_F32(requestAddr + 4));
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = emitterGroupAddr;
	ctx.r4.u64 = factory;
	ctx.r5.u64 = request;
	Random_Gaussian(ctx, base, randR8, gaussianParam, gaussianParam);

	double sample = ctx.f1.f64;   // Random_Gaussian returns the sample in f1
	ctx.fpscr.disableFlushMode();
	uint32_t truncatedSample = std::isnan(sample) ? uint32_t(0x80000000U) :
	                           sample > double(INT_MAX) ? uint32_t(INT_MAX) :
	                           uint32_t(simde_mm_cvttsd_si32(simde_mm_load_sd(&sample)));
	STORE32(requestAddr + 24, truncatedSample);

	double minDuration = LOAD_F64(0x820990B8u);
	double duration = double(emitterGroup->m_duration);
	if (duration < minDuration) {
		stack = PopStackFrame(stack, 224);
		ctx.r1.u64 = stack;
		ctx.f13.f64 = duration;   // callers read f13 after the call
		return 0;
	}

	// state the callee may pass on
	ctx.r10.s64 = g_820A0000;
	ctx.f13.f64 = duration;
	n_sub_82C3E118(ctx, base, emitterGroupAddr, pointSlot, request, ctx.r8.u64);

	n_sub_821D5BA0(ctx, base, layerEntry);
	LayerEntry_SetValues(ctx, base, layerEntry, 0, LOAD32(requestAddr));
	LayerEntry_SetField32(ctx, base, layerEntry, 2);
	PPCVRegister point{};
	SET_V8(point, VLOAD(pointSlot & ~0xF));
	ctx.v1 = point;   // handed to n_sub_82BFC910 in v1
	n_sub_82BFC910(ctx, base, layerEntry);

	uint32_t factoryVtable = LOAD32((uint32_t)factory);
	uint32_t createFn = LOAD32(factoryVtable + 12);
	uint32_t requestRef = requestAddr + 16;
	callTarget.u64 = createFn;
	ctx.r3.u64 = tempRef;
	ctx.r4.u64 = factory;
	ctx.r5.u64 = layerEntry;
	ctx.r9.u64 = createFn;
	ctx.r10.u64 = factoryVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t createdRef = ctx.r3.u64;
	RefPtr_Assign(ctx, base, requestRef, createdRef);

	uint32_t tempRefRelease = LOAD32(stack + 84);
	if (tempRefRelease != 0) {
		uint32_t releaseFn = LOAD32(LOAD32(tempRefRelease) + 4);
		callTarget.u64 = releaseFn;
		ctx.r3.u64 = tempRefRelease;
		ctx.r10.u64 = releaseFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	uint32_t assignedPtr = LOAD32(requestRef);
	STORE32(stack + 84, 0);
	STORE32(stack + 80, 0);
	if (assignedPtr == 0) {
		CCharString_ReleaseMember(ctx, base, layerEntry);
		stack = PopStackFrame(stack, 224);
		ctx.r1.u64 = stack;
		return 0;
	}

	n_sub_82C50130(ctx, base, emitterGroupAddr + 56, requestRef);

	uint32_t created = LOAD32(requestRef);
	ctx.fpscr.disableFlushMode();
	uint32_t createdVfunc12 = LOAD32(LOAD32(created) + 12);
	callTarget.u64 = createdVfunc12;
	ctx.r3.u64 = created;
	ctx.r5.u64 = 0;
	ctx.r10.u64 = createdVfunc12;
	ctx.f1.f64 = double(emitterGroup->m_duration);
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	CCharString_ReleaseMember(ctx, base, layerEntry);
	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(91, sub_82C3E570, 0x82C3E570) { ctx.r3.u64 = n_sub_82C3E570(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

// sub_82C3E6A8  [332 bytes]
uint64_t CEmitterGroup_AreAllChildrenFinished(CpuState& ctx, uint8_t* base, uint32_t emitterGroupAddr) {
	if (!UseLiftedCode(91, 0x82C3E6A8)) { ctx.r3.u64 = emitterGroupAddr; __imp__sub_82C3E6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3E6A8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);
	stack = PushStackFrame(base, stack, 112);

	if (LOAD8(emitterGroupAddr + 0x6D) == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return 0;
	}

	// Plain child list: 12-byte entries holding the child pointer at +4.
	uint32_t childEnd = emitterGroup->m_emitterListEnd;
	uint32_t childIt = emitterGroup->m_emitterListBegin;
	if (childIt > childEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	while (true) {
		uint32_t childBegin = emitterGroup->m_emitterListBegin;
		uint32_t childLimit = emitterGroup->m_emitterListEnd;
		if (childBegin > childLimit) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (childIt == childLimit) break;
		if (childIt >= childEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t child = LOAD32(childIt + 4);
		if (child != 0) {
			uint32_t checkFinished = LOAD32(LOAD32(child));
			callTarget.u64 = checkFinished;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = child;
			ctx.r9.u64 = childBegin;
			ctx.r10.u64 = checkFinished;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((ctx.r3.u32 & 0xFF) == 0) {
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
		childEnd = emitterGroup->m_emitterListEnd;
		if (childIt >= childEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		childIt += 12;
	}

	// Timed child list: 28-byte entries holding the child pointer at +0x10.
	uint32_t timedEnd = emitterGroup->m_timedListEnd;
	uint32_t timedIt = emitterGroup->m_timedListBegin;
	if (timedIt > timedEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	while (true) {
		uint32_t timedBegin = emitterGroup->m_timedListBegin;
		uint32_t timedLimit = emitterGroup->m_timedListEnd;
		if (timedBegin > timedLimit) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (timedIt == timedLimit) break;
		if (timedIt >= timedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t child = LOAD32(timedIt + 16);
		if (child != 0) {
			uint32_t checkFinished = LOAD32(LOAD32(child));
			callTarget.u64 = checkFinished;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = child;
			ctx.r9.u64 = timedBegin;
			ctx.r10.u64 = checkFinished;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((ctx.r3.u32 & 0xFF) == 0) {
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
		timedEnd = emitterGroup->m_timedListEnd;
		if (timedIt >= timedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		timedIt += 28;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(91, sub_82C3E6A8, 0x82C3E6A8) { ctx.r3.u64 = CEmitterGroup_AreAllChildrenFinished(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82C3EA10(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr) {
	if (!UseLiftedCode(91, 0x82C3EA10)) { ctx.r3.u64 = emitterGroupAddr; __imp__sub_82C3EA10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3EA10);
	uint32_t stack = ctx.r1.u64;
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);
	uint64_t result = emitterGroupAddr;
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 112);

	if (emitterGroup->m_6D == 0) {
		emitterGroup->m_6D = uint8_t(1);

		// Emitter list: 12-byte entries, each holding the emitter pointer at +4.
		uint32_t it = emitterGroup->m_emitterListBegin;
		uint32_t end = emitterGroup->m_emitterListEnd;
		if (it > end) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
		for (;;) {
			uint32_t listBegin = emitterGroup->m_emitterListBegin;
			uint32_t listEnd = emitterGroup->m_emitterListEnd;
			if (listBegin > listEnd) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
			if (it == listEnd) break;
			if (it >= end) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }

			uint32_t emitterPtr = LOAD32(it + 4);
			result = emitterPtr;
			if (emitterPtr != 0) {
				uint32_t fn = LOAD32(LOAD32(emitterPtr));
				callTarget.u64 = fn;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = emitterPtr;
				ctx.r9.u64 = listBegin;
				ctx.r10.u64 = fn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;
				if (((uint32_t)result & 0xFF) == 0) {
					uint32_t emitterPtr2 = LOAD32(it + 4);
					uint32_t fn2 = LOAD32(LOAD32(emitterPtr2) + 28);
					callTarget.u64 = fn2;
					ctx.r3.u64 = emitterPtr2;
					ctx.r9.u64 = 0;
					ctx.r10.u64 = fn2;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					result = ctx.r3.u64;
				}
			}

			end = emitterGroup->m_emitterListEnd;
			if (it >= end) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
			it += 12;
		}

		// Timed emitter list: 28-byte entries, each holding the emitter pointer at +16.
		uint32_t itTimed = emitterGroup->m_timedListBegin;
		uint32_t endTimed = emitterGroup->m_timedListEnd;
		if (itTimed > endTimed) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
		for (;;) {
			uint32_t listBegin = emitterGroup->m_timedListBegin;
			uint32_t listEnd = emitterGroup->m_timedListEnd;
			if (listBegin > listEnd) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
			if (itTimed == listEnd) break;
			if (itTimed >= endTimed) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }

			uint32_t emitterPtr = LOAD32(itTimed + 16);
			result = emitterPtr;
			if (emitterPtr != 0) {
				uint32_t fn = LOAD32(LOAD32(emitterPtr));
				callTarget.u64 = fn;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = emitterPtr;
				ctx.r9.u64 = listBegin;
				ctx.r10.u64 = fn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;
				if (((uint32_t)result & 0xFF) == 0) {
					uint32_t emitterPtr2 = LOAD32(itTimed + 16);
					uint32_t fn2 = LOAD32(LOAD32(emitterPtr2) + 28);
					callTarget.u64 = fn2;
					ctx.r3.u64 = emitterPtr2;
					ctx.r9.u64 = 0;
					ctx.r10.u64 = fn2;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					result = ctx.r3.u64;
				}
			}

			endTimed = emitterGroup->m_timedListEnd;
			if (itTimed >= endTimed) { ctx.r1.u64 = stack; ppc_trap(ctx, base, 22); }
			itTimed += 28;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(91, sub_82C3EA10, 0x82C3EA10) { ctx.r3.u64 = n_sub_82C3EA10(ctx, base, ctx.r3.u64); }

// sub_82C3EB80  [476 bytes]
// Runs once per group (byte 0x6D guards it): asks every emitter in both lists whether it stays (vtable slot 0)
// and, when it answers false, calls its slot 8 with the second argument, releases the reference control
// object kept next to it and clears that {emitter, control} pair. The list walks keep the checked-iterator traps.
uint64_t n_sub_82C3EB80(CpuState& ctx, uint8_t* base, uint64_t groupAddr, uint64_t callbackArg) {
	if (!UseLiftedCode(91, 0x82C3EB80)) { ctx.r3.u64 = groupAddr; ctx.r4.u64 = callbackArg; __imp__sub_82C3EB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3EB80);
	uint32_t stack = ctx.r1.u64;
	CEmitterGroup* group = GameObject<CEmitterGroup>(base, groupAddr);
	stack = PushStackFrame(base, stack, 144);

	uint32_t groupAddress = (uint32_t)groupAddr;
	// The return value is what r3 last held: the group, the last emitter slot loaded or the last call's result.
	uint64_t result = groupAddr;
	// r4 as the callbacks leave it; callers read it after the call.
	uint64_t r4Value = callbackArg;

	if (LOAD8(groupAddress + 0x6D) == 0) {
		group->m_6D = uint8_t(1);

		uint32_t emitterList = groupAddress + 4;
		uint32_t node = group->m_emitterListBegin;
		uint32_t checkedEnd = group->m_emitterListEnd;
		if (node > checkedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		for (;;) {
			uint32_t listEnd = LOAD32(emitterList + 8);
			uint32_t listBegin = LOAD32(emitterList + 4);
			if (listBegin > listEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == listEnd) break;
			if (node >= checkedEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			uint32_t emitterRef = node + 4;
			uint32_t emitter = LOAD32(emitterRef);
			result = emitter;
			if (emitter != 0) {
				uint32_t shouldKeepFn = LOAD32(LOAD32(emitter));
				ctx.r1.u64 = stack;
				ctx.r3.u64 = emitter;
				ctx.r4.u64 = r4Value;
				ctx.r9.u64 = listBegin;
				ctx.r10.u64 = shouldKeepFn;
				REX_CALL_INDIRECT_FUNC(shouldKeepFn);
				result = ctx.r3.u64;
				r4Value = ctx.r4.u64;

				if ((result & 0xFF) == 0) {
					uint32_t removedEmitter = LOAD32(emitterRef);
					uint32_t onRemoveFn = LOAD32(LOAD32(removedEmitter) + 32);
					ctx.r3.u64 = removedEmitter;
					ctx.r4.u64 = callbackArg;
					ctx.r5.u64 = 0;
					ctx.r9.u64 = 0;
					ctx.r10.u64 = onRemoveFn;
					REX_CALL_INDIRECT_FUNC(onRemoveFn);
					r4Value = ctx.r4.u64;

					uint32_t refControl = LOAD32(emitterRef + 4);
					result = refControl;
					if (refControl != 0) {
						uint32_t releaseRefFn = LOAD32(LOAD32(refControl) + 4);
						ctx.r3.u64 = refControl;
						ctx.r10.u64 = releaseRefFn;
						REX_CALL_INDIRECT_FUNC(releaseRefFn);
						result = ctx.r3.u64;
						r4Value = ctx.r4.u64;
					}
					STORE32(emitterRef + 4, 0);
					STORE32(emitterRef, 0);
				}
			}

			checkedEnd = LOAD32(emitterList + 8);
			if (node >= checkedEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			node += 12;
		}

		uint32_t timedList = groupAddress + 20;
		node = group->m_timedListBegin;
		checkedEnd = group->m_timedListEnd;
		if (node > checkedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		for (;;) {
			uint32_t listEnd = LOAD32(timedList + 8);
			uint32_t listBegin = LOAD32(timedList + 4);
			if (listBegin > listEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == listEnd) break;
			if (node >= checkedEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			uint32_t emitterRef = node + 16;
			uint32_t emitter = LOAD32(emitterRef);
			result = emitter;
			if (emitter != 0) {
				uint32_t shouldKeepFn = LOAD32(LOAD32(emitter));
				ctx.r1.u64 = stack;
				ctx.r3.u64 = emitter;
				ctx.r4.u64 = r4Value;
				ctx.r9.u64 = listBegin;
				ctx.r10.u64 = shouldKeepFn;
				REX_CALL_INDIRECT_FUNC(shouldKeepFn);
				result = ctx.r3.u64;
				r4Value = ctx.r4.u64;

				if ((result & 0xFF) == 0) {
					uint32_t removedEmitter = LOAD32(emitterRef);
					uint32_t onRemoveFn = LOAD32(LOAD32(removedEmitter) + 32);
					ctx.r3.u64 = removedEmitter;
					ctx.r4.u64 = callbackArg;
					ctx.r5.u64 = 0;
					ctx.r9.u64 = 0;
					ctx.r10.u64 = onRemoveFn;
					REX_CALL_INDIRECT_FUNC(onRemoveFn);
					r4Value = ctx.r4.u64;

					uint32_t refControl = LOAD32(emitterRef + 4);
					result = refControl;
					if (refControl != 0) {
						uint32_t releaseRefFn = LOAD32(LOAD32(refControl) + 4);
						ctx.r3.u64 = refControl;
						ctx.r10.u64 = releaseRefFn;
						REX_CALL_INDIRECT_FUNC(releaseRefFn);
						result = ctx.r3.u64;
						r4Value = ctx.r4.u64;
					}
					STORE32(emitterRef + 4, 0);
					STORE32(emitterRef, 0);
				}
			}

			checkedEnd = LOAD32(timedList + 8);
			if (node >= checkedEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			node += 28;
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(91, sub_82C3EB80, 0x82C3EB80) { ctx.r3.u64 = n_sub_82C3EB80(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82C3EE90  [300 bytes]
// Calls n_sub_82C505E8 on the member at +56, then vtable slot 2 of every emitter in both lists with the second
// argument. The callbacks may change the lists, so the end is re-read every step (checked-iterator traps kept).
uint64_t n_sub_82C3EE90(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr, uint64_t contextArg) {
	if (!UseLiftedCode(91, 0x82C3EE90)) { ctx.r3.u64 = emitterGroupAddr; ctx.r4.u64 = contextArg; __imp__sub_82C3EE90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3EE90);
	uint32_t stack = ctx.r1.u64;
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	uint64_t result = n_sub_82C505E8(ctx, base, emitterGroupAddr + 56, contextArg);

	uint32_t emitterNode = emitterGroup->m_emitterListBegin;
	uint32_t checkedEnd = emitterGroup->m_emitterListEnd;
	if (emitterNode > checkedEnd) {
		ppc_trap(ctx, base, 22);
	}
	for (;;) {
		uint32_t listEnd = emitterGroup->m_emitterListEnd;
		uint32_t listBegin = emitterGroup->m_emitterListBegin;
		if (listBegin > listEnd) {
			ppc_trap(ctx, base, 22);
		}
		if (emitterNode == listEnd) break;
		if (emitterNode >= checkedEnd) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t emitter = LOAD32(emitterNode + 4);
		result = emitter;
		if (emitter != 0) {
			uint32_t slot2Fn = LOAD32(LOAD32(emitter) + 8);
			ctx.r3.u64 = emitter;
			ctx.r4.u64 = contextArg;
			ctx.r9.u64 = listBegin;
			ctx.r10.u64 = slot2Fn;
			REX_CALL_INDIRECT_FUNC(slot2Fn);
			result = ctx.r3.u64;
		}
		checkedEnd = emitterGroup->m_emitterListEnd;
		if (emitterNode >= checkedEnd) {
			ppc_trap(ctx, base, 22);
		}
		emitterNode += 12;
	}

	uint32_t timedNode = emitterGroup->m_timedListBegin;
	checkedEnd = emitterGroup->m_timedListEnd;
	if (timedNode > checkedEnd) {
		ppc_trap(ctx, base, 22);
	}
	for (;;) {
		uint32_t listEnd = emitterGroup->m_timedListEnd;
		uint32_t listBegin = emitterGroup->m_timedListBegin;
		if (listBegin > listEnd) {
			ppc_trap(ctx, base, 22);
		}
		if (timedNode == listEnd) break;
		if (timedNode >= checkedEnd) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t timedEmitter = LOAD32(timedNode + 16);
		result = timedEmitter;
		if (timedEmitter != 0) {
			uint32_t slot2Fn = LOAD32(LOAD32(timedEmitter) + 8);
			ctx.r3.u64 = timedEmitter;
			ctx.r4.u64 = contextArg;
			ctx.r9.u64 = listBegin;
			ctx.r10.u64 = slot2Fn;
			REX_CALL_INDIRECT_FUNC(slot2Fn);
			result = ctx.r3.u64;
		}
		checkedEnd = emitterGroup->m_timedListEnd;
		if (timedNode >= checkedEnd) {
			ppc_trap(ctx, base, 22);
		}
		timedNode += 28;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(91, sub_82C3EE90, 0x82C3EE90) { ctx.r3.u64 = n_sub_82C3EE90(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82C3EFC0  [220 bytes]
// For every node of the emitter list: when the slot is empty or the emitter's vtable slot 0 returns non-zero,
// n_sub_82C3E498 fills the node's slot anew; then the emitter now in the slot gets vtable slot 3 called with
// the group's duration. Returns the last value r3 held (the group when the list is empty).
uint32_t n_sub_82C3EFC0(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr, uint64_t emitterFactory) {
	if (!UseLiftedCode(91, 0x82C3EFC0)) { ctx.r3.u64 = emitterGroupAddr; ctx.r4.u64 = emitterFactory; __imp__sub_82C3EFC0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C3EFC0);
	uint32_t stack = ctx.r1.u64;
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);
	stack = PushStackFrame(base, stack, 128);

	// r4 as the previous call left it; the slot 0 call receives it.
	uint64_t r4Value = emitterFactory;
	uint32_t node = emitterGroup->m_emitterListBegin;
	uint32_t checkedEnd = emitterGroup->m_emitterListEnd;
	uint32_t result = (uint32_t)emitterGroupAddr;

	if (node > checkedEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	for (;;) {
		uint32_t listEnd = emitterGroup->m_emitterListEnd;
		uint32_t listBegin = emitterGroup->m_emitterListBegin;
		if (listBegin > listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == listEnd) break;
		if (node >= checkedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t emitter = LOAD32(node + 4);
		// r9 carries the list begin, the slot 0 result or what n_sub_82C3E498 left into the next call.
		uint64_t r9Value = listBegin;
		bool refill = true;
		if (emitter != 0) {
			uint32_t checkFn = LOAD32(LOAD32(emitter));
			ctx.r1.u64 = stack;
			ctx.r3.u64 = emitter;
			ctx.r4.u64 = r4Value;
			ctx.r9.u64 = r9Value;
			ctx.r10.u64 = checkFn;
			REX_CALL_INDIRECT_FUNC(checkFn);
			r4Value = ctx.r4.u64;
			r9Value = ctx.r3.u32 & 0xFF;
			refill = (r9Value != 0);
		}
		if (refill) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			n_sub_82C3E498(ctx, base, emitterGroupAddr, emitterFactory, node);
			r4Value = ctx.r4.u64;
			r9Value = ctx.r9.u64;
		}

		emitter = LOAD32(node + 4);
		if (emitter != 0) {
			ctx.fpscr.disableFlushMode();
			double duration = double(emitterGroup->m_duration);
			uint32_t updateFn = LOAD32(LOAD32(emitter) + 12);
			ctx.r3.u64 = emitter;
			ctx.r5.u64 = 0;
			ctx.r9.u64 = r9Value;
			ctx.r10.u64 = updateFn;
			ctx.f1.f64 = duration;
			REX_CALL_INDIRECT_FUNC(updateFn);
			emitter = ctx.r3.u32;
			r4Value = ctx.r4.u64;
		}
		result = emitter;

		checkedEnd = emitterGroup->m_emitterListEnd;
		if (node >= checkedEnd) {
			ppc_trap(ctx, base, 22);
		}
		node += 12;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(91, sub_82C3EFC0, 0x82C3EFC0) { ctx.r3.u64 = n_sub_82C3EFC0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82C3F1E0  [92 bytes]
// The second argument is an object (n_sub_82C3E228 makes virtual calls on it), passed unchanged to all
// three steps.
uint64_t CEmitterGroup_Update(CpuState& ctx, uint8_t* base, uint64_t emitterGroup, uint64_t contextObject, uint64_t arg3) {
	if (!UseLiftedCode(91, 0x82C3F1E0)) { ctx.r3.u64 = emitterGroup; ctx.r4.u64 = contextObject; ctx.r8.u64 = arg3; __imp__sub_82C3F1E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3F1E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = emitterGroup;
	uint64_t r4Value = contextObject;
	if (LOAD8((uint32_t)emitterGroup + 0x6D) == 0) {
		// state the callees may pass on; the third pass takes r8 as the first two leave it
		ctx.r1.u64 = stack;
		ctx.r8.u64 = arg3;
		n_sub_82C3E228(ctx, base, emitterGroup, contextObject);
		n_sub_82C3EFC0(ctx, base, emitterGroup, contextObject);
		result = n_sub_82C3F0A0(ctx, base, emitterGroup, contextObject, ctx.r8.u64);
		r4Value = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(91, sub_82C3F1E0, 0x82C3F1E0) { ctx.r3.u64 = CEmitterGroup_Update(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

// sub_82C3F240  [160 bytes]
uint32_t CEmitterGroup_Destruct(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr) {
	if (!UseLiftedCode(91, 0x82C3F240)) { ctx.r3.u64 = emitterGroupAddr; __imp__sub_82C3F240(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C3F240);
	uint32_t stack = ctx.r1.u64;
	CEmitterGroup* emitterGroup = GameObject<CEmitterGroup>(base, emitterGroupAddr);
	uint32_t emitterListRoot = (uint32_t)emitterGroupAddr + 4;
	uint32_t timedListRoot = (uint32_t)emitterGroupAddr + 20;

	stack = PushStackFrame(base, stack, 128);
	emitterGroup->vtable = 0x8200C37Cu;
	ctx.r1.u64 = stack;
	n_sub_82C502D8(ctx, base, (int64_t)emitterGroupAddr + 56);

	uint32_t timedListBegin = emitterGroup->m_timedListBegin;
	if (timedListBegin != 0) {
		uint32_t timedListEnd = LOAD32(timedListRoot + 8);
		// state the callee may pass on: the list root and a byte of this frame the function never writes
		ctx.r6.u64 = LOAD8(stack + 80);
		ReleaseRefRange_Stride28(ctx, base, timedListBegin, timedListEnd);
		HandleTarget_FreeThunk(ctx, base, LOAD32(timedListRoot + 4));
	}
	STORE32(timedListRoot + 4, 0);
	STORE32(timedListRoot + 8, 0);
	STORE32(timedListRoot + 12, 0);

	uint32_t emitterListBegin = emitterGroup->m_emitterListBegin;
	if (emitterListBegin != 0) {
		uint32_t emitterListEnd = LOAD32(emitterListRoot + 8);
		// state the callee may pass on
		ctx.r6.u64 = LOAD8(stack + 80);
		ReleaseRefRange_Stride12(ctx, base, emitterListBegin, emitterListEnd);
		HandleTarget_FreeThunk(ctx, base, LOAD32(emitterListRoot + 4));
	}
	STORE32(emitterListRoot + 4, 0);
	STORE32(emitterListRoot + 8, 0);
	STORE32(emitterListRoot + 12, 0);

	C_8200A34C_Destructor(ctx, base, (uint32_t)emitterGroupAddr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)emitterGroupAddr;
}
PROMOTED_ENTRY(91, sub_82C3F240, 0x82C3F240) { ctx.r3.u64 = CEmitterGroup_Destruct(ctx, base, ctx.r3.u64); }

// sub_82C3F2E0  [80 bytes]
uint64_t CEmitterGroup_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t emitterGroupAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(91, 0x82C3F2E0)) { ctx.r3.u64 = emitterGroupAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82C3F2E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3F2E0);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;  // state the callee may pass on
	CEmitterGroup_Destruct(ctx, base, emitterGroupAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, emitterGroupAddr);
	}
	return emitterGroupAddr;
}
PROMOTED_ENTRY(91, sub_82C3F2E0, 0x82C3F2E0) { ctx.r3.u64 = CEmitterGroup_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
