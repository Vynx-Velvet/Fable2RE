// CECTalk (vtable 0x820039D8): methods of the class as readable C++.
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

uint64_t CECTalk_UpdateTalking(CpuState& ctx, uint8_t* base, uint64_t talkAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t TXT_83497E9C_G_ = int32_t(0x83497E9C);
	if (!UseLiftedCode(4, 0x821E8540)) { ctx.r3.u64 = talkAddr; __imp__sub_821E8540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E8540);
	uint32_t stack = ctx.r1.u64;
	const uint32_t talkBase = (uint32_t)talkAddr;
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t r3Value = talkAddr;
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	uint64_t r10Value = 0;
	PPCXERRegister flags = ctx.xer;

	if (LOAD32(talkBase + 16) != 0) {
		if ((int32_t)LOAD32(talkBase + 24) > 0) {
			PPCRegister callTarget{};
			callTarget.u64 = LOAD32((uint32_t)talk->vtable + 4);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = talkAddr;
			ctx.r10.u64 = callTarget.u64;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r3Value = ctx.r3.u64;
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			flags.ca = ctx.xer.ca;
			uint64_t elapsed = (uint64_t)talk->m_18 - r3Value;
			talk->m_18 = (int32_t)(uint32_t)elapsed;
			r8Value = elapsed;
		}
		if (LOAD8(talkBase + 28) != 0) {
			uint32_t currentLine = 0;
			bool haveLine = false;
			uint32_t list = (uint32_t)talk->m_4;
			r10Value = (LOAD32(list + 52) >> 7) & 1;
			if ((uint32_t)r10Value != 0) {
				uint32_t selection = LOAD32(list + 140);
				if (selection != 0) {
					uint32_t index = LOAD8(selection + 135);
					uint32_t entries = LOAD32(list + 72);
					uint32_t offset = __builtin_rotateleft32(index, 3);
					uint32_t entry = offset + entries;
					currentLine = LOAD32(entry + 4);
					haveLine = true;
				} else {
					uint32_t begin = LOAD32(list + 72);
					uint32_t end = LOAD32(list + 76);
					r6Value = end;
					STORE32(stack + 80, 0);
					uint32_t span = end - begin;
					r10Value = span;
					STORE32(stack + 84, begin);
					flags.ca = ((int32_t)span < 0) & ((span & 0x7) != 0);
					int32_t remaining = (int32_t)span >> 3;
					uint32_t iter = begin;
					if (remaining > 0) {
						do {
							flags.ca = (remaining < 0) & ((remaining & 0x1) != 0);
							int32_t half = remaining >> 1;
							r10Value = (uint32_t)half << 3;
							uint32_t mid = iter + (uint32_t)r10Value;
							bool below = (int32_t)LOAD32(mid) < 135;
							r7Value = below ? 1 : 0;
							if (below) {
								remaining = remaining - half - 1;
								iter = mid + 8;
							} else {
								remaining = half;
							}
						} while (remaining > 0);
						STORE32(stack + 84, iter);
					}
					if (iter != end) {
						bool above = (int32_t)LOAD32(iter) > 135;
						if (!above) {
							currentLine = LOAD32(LOAD32(stack + 84) + 4);
						} else {
							currentLine = LOAD32(end + 4);
						}
					} else {
						currentLine = LOAD32(end + 4);
					}
					haveLine = true;
				}
			}
			if (haveLine) {
				uint32_t soundCategory = LOAD32(currentLine + 44);
				if (soundCategory != 0) {
					ctx.r1.u64 = stack;
					ctx.xer.ca = flags.ca;
					r3Value = SoundCategory_IsPlayingByName(ctx, base, soundCategory, TXT_83497E9C_G_);
					r6Value = ctx.r6.u64;
					r7Value = ctx.r7.u64;
					r10Value = ctx.r8.u64;
					flags.ca = ctx.xer.ca;
				} else {
					r3Value = 0;
				}
				if ((uint8_t)r3Value != 0) {
					stack = PopStackFrame(stack, 112);
					ctx.r1.u64 = stack;
					return r3Value;
				}
				ctx.r1.u64 = stack;
				ctx.xer.ca = flags.ca;
				uint64_t stopped = n_sub_8244A6F8(ctx, base, talkAddr, 0);
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return stopped;
			}
		} else {
			if ((int32_t)LOAD32((uint32_t)g_83320000 - 27380) > (int32_t)LOAD32(talkBase + 20)) {
				ctx.r1.u64 = stack;
				uint64_t stopped = n_sub_8244A6F8(ctx, base, talkAddr, 0);
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return stopped;
			}
		}
	} else {
		talk->m_14 = 0u;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return r3Value;
}
PROMOTED_ENTRY(4, sub_821E8540, 0x821E8540) { ctx.r3.u64 = CECTalk_UpdateTalking(ctx, base, ctx.r3.u64); }

uint64_t CECTalk_RemoveComponent(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(4, 0x821F7000)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_821F7000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821F7000);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 96);

	uint32_t talkEntity = (uint32_t)arg1;
	uint32_t component = (uint32_t)arg2;

	// Ask the component for its type id (virtual slot 1).
	uint32_t getTypeFn = LOAD32(LOAD32(component) + 4);
	callTarget.u64 = (uint64_t)getTypeFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = component;
	ctx.r4.u64 = component;
	ctx.r8.u64 = arg3;
	ctx.r10.u64 = getTypeFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;

	if ((int32_t)result == 8) {
		if (LOAD32(talkEntity + 0x10) != 0) {
			n_sub_8244A6F8(ctx, base, talkEntity, 0);  // Lua_Talk_StopTalking
		}
		uint32_t talkVtable = LOAD32(talkEntity + 0x00);
		uint32_t targetEntity = LOAD32(talkEntity + 0x04);
		uint32_t getEntityFn = LOAD32(talkVtable + 0x10);
		callTarget.u64 = (uint64_t)getEntityFn;
		ctx.r3.u64 = talkEntity;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t entity = ctx.r3.u64;
		result = Entity_RemoveComponentByType(ctx, base, targetEntity, entity, ctx.r8.u64);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(4, sub_821F7000, 0x821F7000) { ctx.r3.u64 = CECTalk_RemoveComponent(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CECTalk_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820A759C_B_ = int32_t(0x820A759C);
	if (!UseLiftedCode(25, 0x824480A0)) { ctx.r3.u64 = classNameString; __imp__sub_824480A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824480A0);
	uint32_t stack = ctx.r1.u64;
	uint64_t nameCStr = str_TXT_820A759C_B_;
	int32_t nameLength = -1;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, nameCStr, nameLength);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(25, sub_824480A0, 0x824480A0) { ctx.r3.u64 = CECTalk_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_824480E8(CpuState& ctx, uint8_t* base, uint64_t talkAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(25, 0x824480E8)) { ctx.r3.u64 = talkAddr; ctx.r4.u64 = deleteFlags; __imp__sub_824480E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824480E8);
	uint32_t stack = ctx.r1.u64;
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t flags = deleteFlags;
	ctx.r1.u64 = stack;
	C_820EFB9C_Destructor(ctx, base, talkAddr + 68);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, talkAddr + 64);
	uint32_t component = talk->m_3C;
	if (component != 0) {
		uint32_t componentDtor = LOAD32(LOAD32(component) + 4);
		PPCRegister callTarget{};
		callTarget.u64 = componentDtor;
		ctx.r3.u64 = component;
		ctx.r10.u64 = componentDtor;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}
	uint32_t countAddr = (int64_t)talkAddr + 56;
	STORE32(countAddr + 4, 0);
	STORE32(countAddr, 0);
	uint32_t subobjectAddr = 0;
	if ((uint32_t)talkAddr != 0) {
		subobjectAddr = (int64_t)talkAddr + 12;
	}
	STORE32(subobjectAddr, 0x820A8F64u);
	talk->vtable = 0x820A8D10u;
	uint64_t result = talkAddr;
	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, result);
		result = talkAddr;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_824480E8, 0x824480E8) { ctx.r3.u64 = n_sub_824480E8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8244A6F8(CpuState& ctx, uint8_t* base, uint32_t talkAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t TXT_83497E9C_G_ = int32_t(0x83497E9C);
	if (!UseLiftedCode(25, 0x8244A6F8)) { ctx.r3.u64 = talkAddr; ctx.r4.u64 = arg2; __imp__sub_8244A6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8244A6F8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);

	uint64_t result = 0;          // r3 value left by the last call
	uint64_t ret5 = arg2;         // r5
	uint64_t ret6 = ctx.r6.u64;   // r6
	uint64_t ret7 = ctx.r7.u64;   // r7
	uint64_t ret8 = ctx.r8.u64;   // r8
	uint32_t ret9 = 0;            // r9
	uint32_t ret10 = 0;           // r10
	uint32_t soundId = 0;
	bool haveSound = false;

	stack = PushStackFrame(base, stack, 128);

	uint32_t owner = talk->m_4;
	ret10 = LOAD32(owner + 52);
	ret9 = (ret10 >> 7) & 1;
	if (ret9 != 0) {
		ret10 = LOAD32(owner + 140);
		if (ret10 != 0) {
			uint8_t slot = LOAD8(ret10 + 135);
			uint32_t table = LOAD32(owner + 72);
			ret10 = __builtin_rotateleft32(slot, 3);
			ret9 = ret10 + table;
			soundId = LOAD32(ret9 + 4);
			haveSound = true;
		} else {
			// lower_bound(135) over the sound table
			ret10 = LOAD32(owner + 72);
			ret6 = LOAD32(owner + 76);
			STORE32(stack + 80, 0);
			uint32_t span = (uint32_t)ret6 - ret10;
			STORE32(stack + 84, ret10);
			flags.ca = ((int32_t)span < 0) & ((span & 0x7) != 0);
			span = (int32_t)span >> 3;
			if ((int32_t)span > 0) {
				do {
					flags.ca = ((int32_t)span < 0) & ((span & 0x1) != 0);
					ret9 = (int32_t)span >> 1;
					ret8 = (uint32_t)ret9 << 3;
					ret10 = (uint32_t)ret8 + ret10;
					bool belowKey = (int32_t)LOAD32(ret10) < 135;
					ret7 = belowKey ? 1 : 0;
					if (belowKey) {
						span = span - ret9;
						ret10 = ret10 + 8;
						span = (int32_t)span - 1;
					} else {
						ret10 = ret10 - (uint32_t)ret8;
						span = ret9;
					}
				} while ((int32_t)span > 0);
				STORE32(stack + 84, ret10);
			}
			if (ret10 != (uint32_t)ret6 && (int32_t)LOAD32(ret10) <= 135) {
				soundId = LOAD32(LOAD32(stack + 84) + 4);
				haveSound = true;
			} else {
				soundId = LOAD32((uint32_t)ret6 + 4);
				haveSound = true;
			}
		}
	}

	if (haveSound) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		n_sub_823A0938(ctx, base, (uint64_t)soundId, (uint64_t)(int64_t)TXT_83497E9C_G_, ret5);
		arg2 = ctx.r4.u64;
		ret5 = ctx.r5.u64;
		ret6 = ctx.r6.u64;
		ret7 = ctx.r7.u64;
		ret8 = ctx.r8.u64;
		ret9 = (uint32_t)ctx.r9.u64;
		flags.ca = ctx.xer.ca;
	}

	result = talk->m_3C;
	uint32_t childFieldAddr = talkAddr + 56;
	if ((uint32_t)result != 0) {
		uint32_t callback = LOAD32(LOAD32((uint32_t)result) + 4);
		callTarget.u64 = (uint64_t)callback;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = result;
		ctx.r4.u64 = arg2;
		ctx.r5.u64 = ret5;
		ctx.r6.u64 = ret6;
		ctx.r7.u64 = ret7;
		ctx.r8.u64 = ret8;
		ctx.r9.u64 = ret9;
		ctx.r10.u64 = (uint64_t)callback;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		arg2 = ctx.r4.u64;
		ret5 = ctx.r5.u64;
		ret6 = ctx.r6.u64;
		ret7 = ctx.r7.u64;
		ret8 = ctx.r8.u64;
		ret9 = (uint32_t)ctx.r9.u64;
		flags.ca = ctx.xer.ca;
	}
	STORE32(childFieldAddr + 4, 0);
	STORE32(childFieldAddr, 0);

	if (LOAD8(talkAddr + 52) != 0) {
		uint32_t speechObj = talk->m_10;
		uint32_t manager = LOAD32((uint32_t)g_83490000 + 26788);
		uint32_t list = LOAD32(LOAD32(manager + 32) + 68);
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = PtrList_RemoveValue(ctx, base, list, speechObj);
		arg2 = ctx.r4.u64;
		ret5 = ctx.r5.u64;
		ret6 = ctx.r6.u64;
		ret7 = ctx.r7.u64;
		ret8 = ctx.r8.u64;
		ret9 = (uint32_t)ctx.r9.u64;
		flags.ca = ctx.xer.ca;
	}

	talk->m_10 = 0;
	talk->m_14 = 0;
	STORE8(stack + 83, 255);
	STORE8(stack + 82, 255);
	STORE8(stack + 81, 255);
	STORE8(stack + 80, 255);
	talk->m_30 = LOAD32(stack + 80);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = ret5;
	ctx.r6.u64 = ret6;
	ctx.r7.u64 = ret7;
	ctx.r8.u64 = ret8;
	ctx.r9.u64 = ret9;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(25, sub_8244A6F8, 0x8244A6F8) { ctx.r3.u64 = n_sub_8244A6F8(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t n_sub_8244AD28(CpuState& ctx, uint8_t* base, uint64_t talkAddr, uint64_t speakerEntity, uint64_t arg3) {
	if (!UseLiftedCode(25, 0x8244AD28)) { ctx.r3.u64 = talkAddr; ctx.r4.u64 = speakerEntity; ctx.r8.u64 = arg3; __imp__sub_8244AD28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8244AD28);
	constexpr int32_t kStrRoperMinimap = int32_t(0x820B0000);
	constexpr int32_t kStrTXT_820B2F64_B_ = int32_t(0x820B2F64);
	constexpr int32_t kStrWeight = int32_t(0x820B0E64);
	constexpr uint64_t kFnvSeed = 0xFFFFFFFF811C9DC5ULL;

	uint32_t stack = ctx.r1.u64;
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);
	stack = PushStackFrame(base, stack, 256);

	uint32_t animObj = talk->m_4;
	ctx.r1.u64 = stack;
	ctx.r8.u64 = arg3;
	n_sub_82392C88(ctx, base, animObj, talkAddr);

	uint64_t result = n_sub_8244B518(ctx, base, talkAddr, 1, ctx.r8.u64);

	if ((uint32_t)speakerEntity != 0) {
		uint64_t TXT_820B2F64_L_ = kStrTXT_820B2F64_B_;
		STORE32(stack + 80, 0u);
		uint64_t voiceHash = String_HashFnv1(ctx, base, TXT_820B2F64_L_, kFnvSeed);
		GameDB_ReadMappedU32Field(ctx, base, speakerEntity, voiceHash, stack + 80);

		ctx.r8.s64 = kStrRoperMinimap;
		uint64_t narratorName = n_sub_82345978(ctx, base, speakerEntity, (int64_t)kStrRoperMinimap + 12144);
		CCharString_AssignFromCStr(ctx, base, talkAddr + 64, narratorName);

		uint32_t mappedValue = LOAD32(stack + 80);
		ctx.fpscr.disableFlushMode();
		double defaultWeight = double(LOAD_F32(0x820994B4u));
		double totalWeight = defaultWeight;
		n_sub_829FBC40(ctx, base, stack + 88, mappedValue, ctx.r8.u64);

		uint32_t i = LOAD32(stack + 96);
		uint32_t end1 = LOAD32(stack + 92);
		uint32_t firstArray = LOAD32(stack + 88);

		if (i != end1) {
			uint32_t mapPtr = LOAD32(0x83496BD0u);       // g_83490000 + 27600
			uint32_t compareKey = LOAD32(0x8349E158u);   // g_834A0000 - 7848
			constexpr uint32_t kOverrideKeyPtr = 0x8349E164u;

			do {
				uint32_t elemAddr = i * 12u + firstArray;
				uint32_t dataPtr = LOAD32(elemAddr + 8);
				uint32_t elemType = LOAD32(elemAddr);
				uint32_t elemData = dataPtr;
				if (elemType == 4 && LOAD32(dataPtr) == compareKey)
					elemData = kOverrideKeyPtr;

				ctx.fpscr.disableFlushMode();
				uint64_t weightHash = String_HashFnv1(ctx, base, (uint64_t)kStrWeight, kFnvSeed);
				uint32_t mapValue = HashMapU32_FindValue(ctx, base, mapPtr, LOAD32(elemData));
				uint32_t weightPtr = n_sub_821E55C8(ctx, base, mapValue, weightHash, stack + 80);

				double weight = defaultWeight;
				if (weightPtr != 0) {
					ctx.fpscr.disableFlushMode();
					weight = double(LOAD_F32(weightPtr));
				}
				i++;
				ctx.fpscr.disableFlushMode();
				totalWeight = double(float(weight + totalWeight));
			} while (i != end1);

			double eps = double(LOAD_F32(0x82099AE0u));
			if (totalWeight > eps) {
				uint32_t rngObj = talk->m_4;
				uint32_t rngState = LOAD32(rngObj + 24) | LOAD32(rngObj + 20);
				STORE32(stack + 80, rngState);
				ctx.r8.u64 = rngState;
				double rngResult = Rng_NextScaledFloat(ctx, base, stack + 80, totalWeight);
				double remaining = rngResult;

				ctx.fpscr.disableFlushMode();
				ctx.f1.f64 = rngResult;
				n_sub_829FBC40(ctx, base, stack + 88, mappedValue, ctx.r8.u64);

				uint32_t j = LOAD32(stack + 96);
				uint32_t end2 = LOAD32(stack + 92);
				uint32_t secondArray = LOAD32(stack + 88);
				double lastF13 = ctx.f13.f64;

				uint32_t mapPtr2 = LOAD32(0x83496BD0u);
				uint32_t compareKey2 = LOAD32(0x8349E158u);
				uint32_t lastMapValue = 0;
				bool found = false;

				if (j != end2) {
					do {
						uint32_t elemAddr = j * 12u + secondArray;
						uint32_t dataPtr = LOAD32(elemAddr + 8);
						uint32_t elemType = LOAD32(elemAddr);
						uint32_t elemData = dataPtr;
						if (elemType == 4 && LOAD32(dataPtr) == compareKey2)
							elemData = kOverrideKeyPtr;

						lastMapValue = HashMapU32_FindValue(ctx, base, mapPtr2, LOAD32(elemData));
						ctx.fpscr.disableFlushMode();
						STORE_F32(stack + 80, float(defaultWeight));
						GameDB_ReadFloatField(ctx, base, lastMapValue, (uint64_t)kStrWeight, stack + 80);

						ctx.fpscr.disableFlushMode();
						double loadedWeight = double(LOAD_F32(stack + 80));
						lastF13 = loadedWeight;
						if (loadedWeight > eps) {
							remaining = double(float(remaining - loadedWeight));
							if (remaining < eps) { found = true; break; }
						}
						j++;
					} while (j != end2);
				}

				if (found) {
					uint64_t breakHash = String_HashFnv1(ctx, base, TXT_820B2F64_L_, kFnvSeed);
					uint32_t fieldValue = GameDB_FindFieldValue(ctx, base, lastMapValue, breakHash, 2);
					if (fieldValue != 0)
						talk->m_20 = LOAD32(fieldValue);
				}

				ctx.f13.f64 = lastF13;
				HandleTarget_Free(ctx, base, secondArray);
			}
		}

		result = HandleTarget_Free(ctx, base, firstArray);
	}

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_8244AD28, 0x8244AD28) { ctx.r3.u64 = n_sub_8244AD28(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t n_sub_8244AFE0(CpuState& ctx, uint8_t* base, uint64_t talkAddr, uint64_t stream) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820B2F64_B_ = int32_t(0x820B2F64);
	constexpr int32_t str_TXT_820B2F70_B_ = int32_t(0x820B2F70);
	constexpr int32_t str_TXT_820B2F7C_B_ = int32_t(0x820B2F7C);
	if (!UseLiftedCode(25, 0x8244AFE0)) { ctx.r3.u64 = talkAddr; ctx.r4.u64 = stream; __imp__sub_8244AFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8244AFE0);
	uint32_t stack = ctx.r1.u64;
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);

	stack = PushStackFrame(base, stack, 112);
	const uint32_t nameTemp = stack + 80;   // CCharString holding the serialized field's name
	const uint32_t valueTemp = stack + 84;  // value read back from the stream


	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, nameTemp, str_TXT_820B2F64_B_, -1);
	uint32_t voiceTypeName = LOAD32(nameTemp);
	STORE32(valueTemp, uint32_t(talk->m_20));
	uint64_t fieldName = (voiceTypeName == 0) ? (uint64_t)(int64_t)g_8209003F : (uint64_t)LOAD32(voiceTypeName);
	IStream_SerializeU32(ctx, base, stream, valueTemp);
	talk->m_20 = LOAD32(valueTemp);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameTemp);


	CCharString_ConstructFromCStr(ctx, base, nameTemp, str_TXT_820B2F7C_B_, -1);
	IStream_SerializeString(ctx, base, nameTemp, stream, talkAddr + 38);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameTemp);


	CCharString_ConstructFromCStr(ctx, base, nameTemp, str_TXT_820B2F70_B_, -1);
	n_sub_82A16EC0(ctx, base, nameTemp, stream, talkAddr + 64);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameTemp);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_8244AFE0, 0x8244AFE0) { ctx.r3.u64 = n_sub_8244AFE0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8244B0C0(CpuState& ctx, uint8_t* base, uint64_t talkAddr) {
	constexpr int32_t str_TXT_820B2EDC_B_ = int32_t(0x820B2EDC);
	constexpr int32_t str_TXT_820B2EEC_B_ = int32_t(0x820B2EEC);
	if (!UseLiftedCode(25, 0x8244B0C0)) { ctx.r3.u64 = talkAddr; __imp__sub_8244B0C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8244B0C0);
	uint32_t stack = ctx.r1.u64;
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);

	uint64_t r6Value = ctx.r6.u64;
	uint64_t r8Value = ctx.r8.u64;
	uint32_t speechHandle = 0;
	bool foundSpeechHandle = false;

	stack = PushStackFrame(base, stack, 144);

	uint32_t talkData = talk->m_4;
	if ((LOAD32(talkData + 36) >> 21) & 1) {
		uint32_t indexObject = LOAD32(talkData + 140);
		if (indexObject != 0) {
			uint32_t index = LOAD8(indexObject + 21);
			uint32_t arrayBase = LOAD32(talkData + 72);
			speechHandle = LOAD32(arrayBase + (index << 3) + 4);
			foundSpeechHandle = true;
		} else {
			uint32_t begin = LOAD32(talkData + 72);
			uint32_t end = LOAD32(talkData + 76);
			r6Value = end;
			STORE32(stack + 104, 0);
			STORE32(stack + 108, begin);

			int32_t count = (int32_t)(end - begin) >> 3;
			uint32_t p = begin;
			if (count > 0) {
				do {
					int32_t mid = count >> 1;
					uint32_t offset = (uint32_t)mid << 3;
					uint32_t q = p + offset;
					r8Value = offset;
					if ((int32_t)LOAD32(q) < 21) {
						count = count - mid - 1;
						p = q + 8;
					} else {
						count = mid;
					}
				} while (count > 0);
				STORE32(stack + 108, p);
			}

			if (p != end) {
				if ((int32_t)LOAD32(p) > 21) {
					speechHandle = LOAD32(end + 4);
				} else {
					STORE64(stack + 104, LOAD64(stack + 104));
					uint32_t matched = LOAD32(stack + 108);
					speechHandle = LOAD32(matched + 4);
				}
			} else {
				speechHandle = LOAD32(end + 4);
			}
			foundSpeechHandle = true;
		}
	}

	if (foundSpeechHandle) {
		STORE32(stack + 104, 0);
		STORE32(stack + 108, 0);
		STORE32(stack + 96, 0);
		STORE32(stack + 100, 0);

		uint64_t TXT_820B2EDC_L_ = str_TXT_820B2EDC_B_;
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, stack + 84, TXT_820B2EDC_L_, -1);

		STORE32(stack + 80, 0);
		n_sub_822838A0(ctx, base, speechHandle, stack + 80, stack + 84, 0, 0);
		SharedPtr_ResetWithPointerE(ctx, base, stack + 104, LOAD32(stack + 80));
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);

		uint64_t TXT_820B2EEC_L_ = str_TXT_820B2EEC_B_;
		CCharString_ConstructFromCStr(ctx, base, stack + 88, TXT_820B2EEC_L_, -1);

		STORE32(stack + 80, 0);
		n_sub_822838A0(ctx, base, speechHandle, stack + 80, stack + 88, 0, 0);
		SharedPtr_ResetWithPointerE(ctx, base, stack + 96, LOAD32(stack + 80));
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);

		if (LOAD32(stack + 104) != 0 && LOAD32(stack + 96) != 0) {
			talk->m_24 = uint8_t(1);
		}

		SharedHandle_Release(ctx, base, stack + 96);
		talkAddr = SharedHandle_Release(ctx, base, stack + 104);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return talkAddr;
}
PROMOTED_ENTRY(25, sub_8244B0C0, 0x8244B0C0) { ctx.r3.u64 = n_sub_8244B0C0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8244B2C0(CpuState& ctx, uint8_t* base, uint64_t talkAddr) {
	if (!UseLiftedCode(25, 0x8244B2C0)) { ctx.r3.u64 = talkAddr; __imp__sub_8244B2C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8244B2C0);
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);
	if (talk->m_10 == 0) {
		return talkAddr;
	}
	return n_sub_8244A6F8(ctx, base, talkAddr, 0);
}
PROMOTED_ENTRY(25, sub_8244B2C0, 0x8244B2C0) { ctx.r3.u64 = n_sub_8244B2C0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8244B518(CpuState& ctx, uint8_t* base, uint64_t talkAddr, uint64_t isEnabled, uint64_t arg3) {
	constexpr int32_t str_TXT_820B2DB0_B_ = int32_t(0x820B2DB0);
	if (!UseLiftedCode(25, 0x8244B518)) { ctx.r3.u64 = talkAddr; ctx.r4.u64 = isEnabled; ctx.r8.u64 = arg3; __imp__sub_8244B518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8244B518);
	uint32_t stack = ctx.r1.u64;
	CECTalk* talk = GameObject<CECTalk>(base, talkAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t returnValue = talkAddr;
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint32_t speechEvent = 0;
	bool hasEvent = false;
	uint32_t container = talk->m_4;

	if ((LOAD32(container + 36) >> 19) & 1) {
		uint32_t entries = LOAD32(container + 140);
		if (entries != 0) {
			uint32_t index = LOAD8(entries + 19);
			uint32_t table = LOAD32(container + 72);
			speechEvent = LOAD32(table + (index << 3) + 4);
			hasEvent = true;
		} else {
			uint32_t begin = LOAD32(container + 72);
			uint32_t end = LOAD32(container + 76);
			r6Value = end;
			STORE32(stack + 80, speechEvent);
			STORE32(stack + 84, begin);
			uint32_t pos = begin;
			int32_t remaining = (int32_t)(end - begin) >> 3;
			if (remaining > 0) {
				// lower_bound of key 19; arg3 (r8) is used as scratch here and
				// whatever it ends up holding is what the original forwards later
				do {
					int32_t half = remaining >> 1;
					uint32_t offset = (uint32_t)half << 3;
					uint32_t mid = pos + offset;
					arg3 = uint64_t(offset);
					int32_t midValue = (int32_t)LOAD32(mid);
					r7Value = (midValue < 19) ? 1 : 0;
					if (midValue < 19) {
						remaining = remaining - half - 1;
						pos = mid + 8;
					} else {
						remaining = half;
						pos = mid - offset;
					}
				} while (remaining > 0);
				STORE32(stack + 84, pos);
			}
			if (pos != end && (int32_t)LOAD32(pos) <= 19) {
				// the original copies the located pair onto itself before reading it
				STORE64(stack + 80, LOAD64(stack + 80));
				speechEvent = LOAD32(pos + 4);
			} else {
				speechEvent = LOAD32(end + 4);
			}
			hasEvent = true;
		}
	}

	if (hasEvent) {
		if ((uint32_t)isEnabled & 0xFF) {
			ctx.r1.u64 = stack;
			CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, str_TXT_820B2DB0_B_, -1);
			n_sub_8223E410(ctx, base, speechEvent, talkAddr + 12, talkAddr + 68, uint64_t(stack) + 80);
			returnValue = CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 80);
			isEnabled = ctx.r4.u64;
		} else {
			ctx.r1.u64 = stack;
			returnValue = n_sub_82516210(ctx, base, speechEvent, talkAddr + 68, arg3);
			isEnabled = ctx.r4.u64;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = isEnabled;
	return returnValue;
}
PROMOTED_ENTRY(25, sub_8244B518, 0x8244B518) { ctx.r3.u64 = n_sub_8244B518(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }
