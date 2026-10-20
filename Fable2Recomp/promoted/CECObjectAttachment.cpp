// CECObjectAttachment (vtable 0x82003C18): methods of the class as readable C++.
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

uint64_t CECObjectAttachment_AttachTarget(CpuState& ctx, uint8_t* base, uint64_t attachment, uint64_t target) {
	if (!UseLiftedCode(5, 0x82204D70)) { ctx.r3.u64 = attachment; ctx.r4.u64 = target; __imp__sub_82204D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82204D70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// The target reports its own kind through virtual slot 1; the result picks the handler.
	auto targetType = [&]() -> int32_t {
		uint32_t fn = LOAD32(LOAD32((uint32_t)target) + 4);
		PPCRegister callTarget{};
		callTarget.u64 = fn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = target;
		ctx.r10.u64 = fn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		return (int32_t)ctx.r3.u32;
	};

	uint64_t result{};

	ctx.r4.u64 = target; // state the first virtual call may pass on
	if (targetType() == 7) {
		result = n_sub_8250F910(ctx, base, attachment, target);
	} else if (targetType() == 11) {
		result = n_sub_8250FD70(ctx, base, attachment, target);
	} else if (targetType() == 1) {
		result = n_sub_8250FE70(ctx, base, attachment, target);
	} else if (targetType() == 2) {
		result = n_sub_8250FF68(ctx, base, attachment, target);
	} else if (targetType() == 3) {
		ctx.r4.u64 = target; // state the callee may pass on
		result = CECObjectAttachment_ApplyAppearanceToEntities(ctx, base, attachment);
	} else if (targetType() == 4) {
		ctx.r4.u64 = target; // state the callee may pass on
		result = CECObjectAttachment_SyncEntityAppearances(ctx, base, attachment);
	} else {
		int32_t finalType = targetType();
		result = ctx.r3.u64;
		if (finalType == 10 && LOAD8((uint32_t)target + 4) != 0) {
			result = CECObjectAttachment_UpdateTransform(ctx, base, attachment);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(5, sub_82204D70, 0x82204D70) { ctx.r3.u64 = CECObjectAttachment_AttachTarget(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CECObjectAttachment_GetMatrix(CpuState& ctx, uint8_t* base, uint32_t objectAttachmentAddr, uint64_t outMatrix, uint64_t entity) {
	if (!UseLiftedCode(7, 0x822374D0)) { ctx.r3.u64 = objectAttachmentAddr; ctx.r4.u64 = outMatrix; ctx.r5.u64 = entity; __imp__sub_822374D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822374D0);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECObjectAttachment* objectAttachment = GameObject<CECObjectAttachment>(base, objectAttachmentAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t owner = objectAttachment->m_4;

	// Handed to SharedHandle_GetRaw: the caller's r6/r7/r8 unless the scans below replace them.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;

	if (((LOAD32(owner + 36) >> 3) & 1) == 0) {
		ctx.r1.u64 = stack;
		Matrix_ConstructIdentity(ctx, base, (uint32_t)outMatrix);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return (uint32_t)outMatrix;
	}

	if (LOAD32(owner + 140) == 0) {
		// Lower-bound search for key 3 over the owner's sorted 8-byte entries; its position is not used,
		// only the r7/r8 scratch and the carry survive it.
		uint32_t it = LOAD32(owner + 72);
		uint32_t count = LOAD32(owner + 76) - it;
		flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
		count = (int32_t)count >> 3;
		while ((int32_t)count > 0) {
			flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
			uint32_t half = (int32_t)count >> 1;
			uint32_t offset = half << 3;
			reg8 = offset;
			it = offset + it;
			reg7 = (int32_t)LOAD32(it) < 3 ? 1 : 0;
			if (reg7 != 0) {
				count = count - half - 1;
				it = it + 8;
			} else {
				it = it - offset;
				count = half;
			}
		}
	}

	if (((LOAD32(owner + 36) >> 6) & 1) == 0) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		uint32_t result = n_sub_8250F3D0(ctx, base, (uint32_t)outMatrix, owner, entity);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return result;
	}

	// The handle stored under key 6: byte 6 of the index at +140 gives its entry directly; without an index,
	// a lower-bound search over the sorted 8-byte {key, value} entries (a missing key reads the word at end + 4).
	uint32_t handleId;
	uint32_t keyIndex = LOAD32(owner + 140);
	if (keyIndex != 0) {
		uint32_t entry = ((uint32_t)LOAD8(keyIndex + 6) << 3) + LOAD32(owner + 72);
		handleId = LOAD32(entry + 4);
	} else {
		uint32_t it = LOAD32(owner + 72);
		reg6 = LOAD32(owner + 76);
		STORE32(stack + 80, 0u);
		STORE32(stack + 84, it);
		uint32_t count = (uint32_t)reg6 - it;
		flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
		count = (int32_t)count >> 3;
		if ((int32_t)count > 0) {
			do {
				flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
				uint32_t half = (int32_t)count >> 1;
				uint32_t offset = half << 3;
				reg8 = offset;
				it = offset + it;
				reg7 = (int32_t)LOAD32(it) < 6 ? 1 : 0;
				if (reg7 != 0) {
					count = count - half - 1;
					it = it + 8;
				} else {
					it = it - offset;
					count = half;
				}
			} while ((int32_t)count > 0);
			STORE32(stack + 84, it);
		}
		if (it != (uint32_t)reg6 && (int32_t)LOAD32(it) <= 6) {
			STORE64(stack + 80, LOAD64(stack + 80));
			handleId = LOAD32(LOAD32(stack + 84) + 4);
		} else {
			handleId = LOAD32((uint32_t)reg6 + 4);
		}
	}

	ctx.r1.u64 = stack;
	// state SharedHandle_GetRaw may pass on
	ctx.r4.u64 = outMatrix;
	ctx.r5.u64 = entity;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	uint64_t rawHandle = SharedHandle_GetRaw(ctx, base, handleId);
	uint32_t result = n_sub_82235CE8(ctx, base, (uint32_t)outMatrix, owner, entity, rawHandle);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_822374D0, 0x822374D0) { ctx.r3.u64 = CECObjectAttachment_GetMatrix(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t CECObjectAttachment_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820B7094_B_ = int32_t(0x820B7094);
	if (!UseLiftedCode(31, 0x8250C6E0)) { ctx.r3.u64 = classNameString; __imp__sub_8250C6E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8250C6E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t classNameCStr = str_TXT_820B7094_B_;
	int32_t cstrLength = -1;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameCStr, cstrLength);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(31, sub_8250C6E0, 0x8250C6E0) { ctx.r3.u64 = CECObjectAttachment_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECObjectAttachment_Destructor(CpuState& ctx, uint8_t* base, uint64_t objectAttachmentAddr, uint64_t deletingFlags) {
	if (!UseLiftedCode(31, 0x8250C720)) { ctx.r3.u64 = objectAttachmentAddr; ctx.r4.u64 = deletingFlags; __imp__sub_8250C720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8250C720);
	uint32_t stack = ctx.r1.u64;
	CECObjectAttachment* objectAttachment = GameObject<CECObjectAttachment>(base, objectAttachmentAddr);

	stack = PushStackFrame(base, stack, 112);

	ctx.r1.u64 = stack;
	ctx.r4.u64 = deletingFlags; // state the callee may pass on
	SharedHandle_Release(ctx, base, objectAttachmentAddr + 36);

	IntrusiveList_Init(ctx, base, objectAttachmentAddr + 24);

	HandleTarget_Free(ctx, base, objectAttachment->m_1C);
	objectAttachment->m_1C = 0;

	SharedHandleList_Clear_825E4F68(ctx, base, objectAttachmentAddr + 12);

	objectAttachment->vtable = 0x820A8D10u;

	if ((deletingFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, objectAttachmentAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectAttachmentAddr;
}
PROMOTED_ENTRY(31, sub_8250C720, 0x8250C720) { ctx.r3.u64 = CECObjectAttachment_Destructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECObjectAttachment_UpdateTransform(CpuState& ctx, uint8_t* base, uint64_t objectAttachmentAddr) {
	if (!UseLiftedCode(31, 0x8250DD60)) { ctx.r3.u64 = objectAttachmentAddr; __imp__sub_8250DD60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8250DD60);
	uint32_t stack = ctx.r1.u64;
	CECObjectAttachment* objectAttachment = GameObject<CECObjectAttachment>(base, objectAttachmentAddr);
	stack = PushStackFrame(base, stack, 208);

	uint32_t positionBuffer = stack + 80;
	uint32_t rotationBuffer = stack + 96;
	uint32_t matrixBuffer = stack + 112;

	// attachment sub-object and its virtual table
	uint32_t attachmentData = LOAD32(uint32_t(objectAttachment->m_4) + 124);
	uint32_t vtable = LOAD32(attachmentData);
	uint32_t getPositionFn = LOAD32(vtable + 64);

	PPCRegister callTarget{};
	callTarget.u64 = getPositionFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = positionBuffer;
	ctx.r4.u64 = attachmentData;
	ctx.r9.u64 = getPositionFn;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t reloadedVtable = LOAD32(attachmentData);
	uint32_t getRotationFn = LOAD32(reloadedVtable + 68);
	callTarget.u64 = getRotationFn;
	ctx.r3.u64 = rotationBuffer;
	ctx.r4.u64 = attachmentData;
	ctx.r7.u64 = getRotationFn;
	ctx.r8.u64 = reloadedVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t quatPtr = ctx.r3.u64;
	uint64_t quatLo = LOAD64(quatPtr);
	uint64_t quatHi = LOAD64(quatPtr + 8);
	PPCVRegister positionVector{};
	SET_V8(positionVector, VLOAD(positionBuffer & ~0xF));
	ctx.r6.u64 = positionBuffer; // state the callee may pass on
	ctx.v1 = positionVector;
	// the next call receives f1 as the conversion leaves it
	ctx.f1.f64 = Quat_ToMatrix4x4(ctx, base, matrixBuffer, quatLo, quatHi);
	uint64_t result = CECObjectAttachment_SetMatrix(ctx, base, objectAttachmentAddr, matrixBuffer);

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_8250DD60, 0x8250DD60) { ctx.r3.u64 = CECObjectAttachment_UpdateTransform(ctx, base, ctx.r3.u64); }

uint64_t CECObjectAttachment_EnsureProperty(CpuState& ctx, uint8_t* base, uint64_t objectAttachmentAddr, uint64_t key, uint64_t nameString, uint64_t expectedValue) {
	if (!UseLiftedCode(31, 0x8250E9F8)) { ctx.r3.u64 = objectAttachmentAddr; ctx.r4.u64 = key; ctx.r5.u64 = nameString; ctx.r6.u64 = expectedValue; __imp__sub_8250E9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8250E9F8);
	uint32_t stack = ctx.r1.u64;

	CECObjectAttachment* objectAttachment = GameObject<CECObjectAttachment>(base, objectAttachmentAddr);
	stack = PushStackFrame(base, stack, 208);

	ctx.r1.u64 = stack;
	ctx.r6.u64 = expectedValue; // state the callee may pass on
	uint32_t iteratorAddr = EntityHandleMap_Find(ctx, base, stack + 88, objectAttachmentAddr, key);
	uint32_t listEnd = objectAttachment->m_10;

	// The returned iterator {list, node} is copied to stack + 80; it must belong to the list at +12.
	STORE64(stack + 80, LOAD64(iteratorAddr));
	uint32_t iteratorList = LOAD32(stack + 80);
	if (iteratorList == 0 || iteratorList != (uint32_t)objectAttachmentAddr + 12) {
		ppc_trap(ctx, base, 22);
	}

	// r4, r9 and r10 are left for callers on return; r9 and r10 are also handed to n_sub_8250D0D0.
	uint64_t reg4 = 0;
	uint64_t reg9 = listEnd;
	uint64_t reg10 = iteratorList;

	uint64_t result = 0;
	bool entryMatches = false;
	uint32_t foundNode = LOAD32(stack + 84);
	if (foundNode != listEnd) {
		if (iteratorList == 0) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t end = LOAD32(iteratorList + 4);
		reg10 = end;
		if (foundNode == end) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t record = LOAD32(foundNode + 8);
		uint32_t name = LOAD32((uint32_t)nameString);
		reg4 = name;
		uint32_t recordName = LOAD32(record + 8);
		if (recordName == name) {
			result = 1;
		} else if (recordName != 0 && name != 0) {
			ctx.r10.u64 = reg10; // state the callee may pass on
			result = CCharString_Equals(ctx, base, recordName, name);
			reg4 = ctx.r4.u64;
			reg10 = ctx.r10.u64;
		} else {
			result = 0;
		}
		entryMatches = (result & 0xFF) != 0 && (int32_t)LOAD32(record + 12) == (int32_t)expectedValue;
	}

	if (!entryMatches) {
		n_sub_8250D0D0(ctx, base, stack + 96, (uint32_t)key, (uint32_t)nameString);
		result = n_sub_8250DF18(ctx, base, objectAttachmentAddr, key, nameString, expectedValue, stack + 96, 1);
		reg4 = ctx.r4.u64;
		reg9 = ctx.r9.u64;
		reg10 = ctx.r10.u64;
	}

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	// callers read r4, r9 and r10 after the call
	ctx.r4.u64 = reg4;
	ctx.r9.u64 = reg9;
	ctx.r10.u64 = reg10;
	return result;
}
PROMOTED_ENTRY(31, sub_8250E9F8, 0x8250E9F8) { ctx.r3.u64 = CECObjectAttachment_EnsureProperty(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint32_t CECObjectAttachment_GetComposedMatrix(CpuState& ctx, uint8_t* base, uint32_t attachment, uint32_t outMatrix, uint64_t parentTransform, uint64_t localTransform) {
	if (!UseLiftedCode(31, 0x8250F5F0)) { ctx.r3.u64 = attachment; ctx.r4.u64 = outMatrix; ctx.r5.u64 = parentTransform; ctx.r6.u64 = localTransform; __imp__sub_8250F5F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8250F5F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 240);

	uint32_t matrix = stack + 80;                                   // composed matrix
	uint32_t scratch = stack + 144;                                 // temporary
	uint32_t parentMatrix = (uint32_t)parentTransform + 80;

	ctx.r1.u64 = stack;
	ctx.r6.u64 = localTransform; // the callee hands r6 on
	CECObjectAttachment_GetMatrix(ctx, base, attachment, matrix, parentTransform);

	Matrix4x4_Multiply(ctx, base, scratch, parentMatrix, matrix);
	Matrix4x4_Multiply(ctx, base, matrix, scratch, localTransform);

	uint64_t lastQword = 0;
	for (int i = 0; i < 8; ++i) {
		lastQword = LOAD64(matrix + i * 8);
		STORE64(outMatrix + i * 8, lastQword);
	}

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	// callers read r5 and r9 (the last copied 8 bytes) after the call
	ctx.r5.u64 = localTransform;
	ctx.r9.u64 = lastQword;
	return matrix;
}
PROMOTED_ENTRY(31, sub_8250F5F0, 0x8250F5F0) { ctx.r3.u64 = CECObjectAttachment_GetComposedMatrix(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u64, ctx.r6.u64); }

// Only when the owner (+4) has bit 3 of its word at +36 set: walks the element handles in the list at +12.
// A handle whose control block (at +4) starts with zero is released; for an entity with bit 0x40 of its byte
// at +144 and bit 3 of its word at +36 set, CECGraphicAppearance_SetSaturationMask receives the entity's key-3 value and the byte
// at +196 of the owner's key-3 value. Returns the last element or call result of the walk, else the argument.
uint64_t CECObjectAttachment_ApplyAppearanceToEntities(CpuState& ctx, uint8_t* base, uint64_t attachmentAddr) {
	if (!UseLiftedCode(31, 0x825102F0)) { ctx.r3.u64 = attachmentAddr; __imp__sub_825102F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825102F0);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;

	// The calls in the list walk receive r6-r10 and the carry through the CPU state; the walk keeps what they
	// leave in r6-r9 and the carry. The caller's r6-r8 are the starting values.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = 0;
	uint32_t reg10 = 0;
	auto handOver = [&]() {
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.r10.u64 = reg10;
		ctx.xer.ca = flags.ca;
	};
	auto readBack = [&]() {
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
		reg9 = ctx.r9.u64;
		flags.ca = ctx.xer.ca;
	};

	stack = PushStackFrame(base, stack, 160);

	// Lower-bound search for key 3 over sorted 8-byte {key, value} entries [pos, end). It leaves its last
	// comparison, offset and half count in reg7, reg8 and reg9 and the carry in flags.
	auto searchKey3 = [&](uint32_t& pos, uint32_t end) {
		uint32_t count = end - pos;
		flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
		count = (int32_t)count >> 3;
		if ((int32_t)count <= 0) {
			return;
		}
		do {
			flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
			uint32_t half = (int32_t)count >> 1;
			reg9 = half;
			reg8 = half << 3;
			pos = pos + (uint32_t)reg8;
			reg7 = (int32_t)LOAD32(pos) < 3 ? 1 : 0;
			if (reg7 != 0) {
				count = count - half - 1;
				pos = pos + 8;
			} else {
				pos = pos - (uint32_t)reg8;
				count = half;
			}
		} while ((int32_t)count > 0);
		STORE32(stack + 84, pos);
	};

	uint64_t result = attachmentAddr;
	uint32_t owner = LOAD32((uint32_t)attachmentAddr + 4);
	if (((LOAD32(owner + 36) >> 3) & 1) != 0) {
		// The owner's value under key 3: byte 3 of the index at +140 gives its entry directly; without an index,
		// a search of the entries at +72..+76 (a missing key reads the word at end + 4).
		uint32_t ownerKey3Value;
		uint32_t ownerIndex = LOAD32(owner + 140);
		if (ownerIndex != 0) {
			ownerKey3Value = LOAD32(((uint32_t)LOAD8(ownerIndex + 3) << 3) + LOAD32(owner + 72) + 4);
		} else {
			uint32_t pos = LOAD32(owner + 72);
			reg6 = LOAD32(owner + 76);
			STORE32(stack + 80, 0u);
			STORE32(stack + 84, pos);
			searchKey3(pos, (uint32_t)reg6);
			if (pos != (uint32_t)reg6 && (int32_t)LOAD32(pos) <= 3) {
				STORE64(stack + 80, LOAD64(stack + 80));
				ownerKey3Value = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				ownerKey3Value = LOAD32((uint32_t)reg6 + 4);
			}
		}

		// Checked iterator {list, node} over the list at +12, built at stack + 80; a node holds the next node at +0
		// and its element at +8.
		uint32_t listAddr = (uint32_t)attachmentAddr + 12;
		uint32_t sentinel = LOAD32((uint32_t)attachmentAddr + 16);
		STORE32(stack + 80, listAddr);
		reg10 = LOAD32(sentinel); // first node
		STORE32(stack + 84, reg10);
		reg9 = LOAD64(stack + 80);
		STORE64(stack + 80, reg9);
		uint32_t iteratorList = LOAD32(stack + 80);
		uint32_t node = LOAD32(stack + 84);
		for (;;) {
			uint32_t listEnd = LOAD32(listAddr + 4);
			if (iteratorList == 0 || iteratorList != listAddr) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == listEnd) {
				break;
			}
			if (iteratorList == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == LOAD32(iteratorList + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			result = LOAD32(node + 8);
			bool entityFlagged = false;
			uint32_t control = LOAD32((uint32_t)result + 4);
			if (control != 0) {
				reg10 = LOAD32(control);
				if (reg10 == 0) {
					ctx.r1.u64 = stack;
					handOver();
					result = EntityHandle_Release(ctx, base, result);
					readBack();
					reg10 = ctx.r10.u32;
				} else {
					ctx.r1.u64 = stack;
					handOver();
					result = EntityHandle_Get_825575C8(ctx, base, result);
					readBack();
					reg10 = LOAD8((uint32_t)result + 144) & 64;
					entityFlagged = reg10 != 0;
				}
			}

			if (entityFlagged) {
				uint32_t element = LOAD32(node + 8);
				ctx.r1.u64 = stack;
				handOver();
				result = EntityHandle_Get_825575C8(ctx, base, element);
				readBack();
				uint32_t entity = (uint32_t)result;
				reg10 = (LOAD32(entity + 36) >> 3) & 1;
				if (reg10 != 0) {
					// The entity's value under key 3, found the same way as the owner's.
					uint32_t entityKey3Value;
					uint32_t entityIndex = LOAD32(entity + 140);
					reg10 = LOAD32(entity + 72);
					if (entityIndex != 0) {
						reg10 = ((uint32_t)LOAD8(entityIndex + 3) << 3) + reg10;
						entityKey3Value = LOAD32(reg10 + 4);
					} else {
						reg6 = LOAD32(entity + 76);
						STORE32(stack + 80, 0u);
						STORE32(stack + 84, reg10);
						searchKey3(reg10, (uint32_t)reg6);
						if (reg10 != (uint32_t)reg6 && (int32_t)LOAD32(reg10) <= 3) {
							STORE64(stack + 88, LOAD64(stack + 80));
							entityKey3Value = LOAD32(LOAD32(stack + 92) + 4);
						} else {
							entityKey3Value = LOAD32((uint32_t)reg6 + 4);
						}
					}
					uint32_t ownerByte = LOAD8(ownerKey3Value + 196);
					handOver();
					result = CECGraphicAppearance_SetSaturationMask(ctx, base, entityKey3Value, ownerByte);
					readBack();
					reg10 = ctx.r10.u32;
				}
			}

			if (node == LOAD32(iteratorList + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			node = LOAD32(node);
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_825102F0, 0x825102F0) { ctx.r3.u64 = CECObjectAttachment_ApplyAppearanceToEntities(ctx, base, ctx.r3.u64); }

// Only when the owner (+4) has bit 3 of its word at +36 set: walks the entity handles in the list at +12.
// A handle whose slot (pointed to by its +4) holds zero is released; for an entity with bit 0x40 of its byte
// at +144 and bit 3 of its word at +36 set, CECGraphicAppearance_SetTintBlock receives the entity's key-3 value and the owner's
// key-3 value plus 96. Returns the last handle or call result of the walk, else the argument.
uint64_t CECObjectAttachment_SyncEntityAppearances(CpuState& ctx, uint8_t* base, uint64_t attachment) {
	if (!UseLiftedCode(31, 0x82510618)) { ctx.r3.u64 = attachment; __imp__sub_82510618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82510618);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;

	// The calls in the list walk receive r6-r10 and the carry through the CPU state, and the walk keeps what
	// they leave there. The caller's r6-r8 are the starting values.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = 0;
	uint64_t reg10 = 0;
	auto handOver = [&]() {
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.r10.u64 = reg10;
		ctx.xer.ca = flags.ca;
	};
	auto readBack = [&]() {
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
		reg9 = ctx.r9.u64;
		reg10 = ctx.r10.u64;
		flags.ca = ctx.xer.ca;
	};

	stack = PushStackFrame(base, stack, 144);

	// Lower-bound search for key 3 over the sorted 8-byte {key, value} entries [begin, end), with the iterator
	// {0, position} at stack + 80. Leaves end in reg6, the position in reg10, its last comparison, offset and
	// half count in reg7, reg8 and reg9, and the carry in flags. True when the entry found has key 3.
	auto findKey3 = [&](uint32_t begin, uint32_t end) -> bool {
		reg6 = end;
		reg10 = begin;
		STORE32(stack + 80, 0u);
		STORE32(stack + 84, begin);
		uint32_t byteCount = end - begin;
		flags.ca = (int32_t)byteCount < 0 && (byteCount & 0x7) != 0;
		int32_t remaining = (int32_t)byteCount >> 3;
		if (remaining > 0) {
			flags.ca = 0; // halving a positive count leaves no carry
			do {
				int32_t half = remaining >> 1;
				reg9 = (uint64_t)half;
				reg8 = (uint32_t)half << 3;
				reg10 = reg10 + reg8;
				reg7 = (int32_t)LOAD32((uint32_t)reg10) < 3 ? 1 : 0;
				if (reg7 != 0) {
					remaining = remaining - half - 1;
					reg10 = reg10 + 8;
				} else {
					reg10 = reg10 - reg8;
					remaining = half;
				}
			} while (remaining > 0);
			STORE32(stack + 84, (uint32_t)reg10);
		}
		return (uint32_t)reg10 != end && (int32_t)LOAD32((uint32_t)reg10) <= 3;
	};

	uint64_t result = attachment;
	uint32_t owner = LOAD32((uint32_t)attachment + 4);
	if (((LOAD32(owner + 36) >> 3) & 1) != 0) {
		reg9 = 1; // the bit just tested is left in r9

		// The owner's value under key 3: byte 3 of the index at +140 gives its entry directly; without an index,
		// a search of the entries at +72..+76 (a missing key reads the word at end + 4).
		uint32_t ownerKey3Value;
		uint32_t ownerIndex = LOAD32(owner + 140);
		if (ownerIndex != 0) {
			reg10 = (uint32_t)LOAD8(ownerIndex + 3) << 3;
			reg9 = reg10 + LOAD32(owner + 72);
			ownerKey3Value = LOAD32((uint32_t)reg9 + 4);
		} else if (findKey3(LOAD32(owner + 72), LOAD32(owner + 76))) {
			STORE64(stack + 80, LOAD64(stack + 80)); // the result iterator shares the search iterator's slot
			ownerKey3Value = LOAD32(LOAD32(stack + 84) + 4);
		} else {
			ownerKey3Value = LOAD32((uint32_t)reg6 + 4);
		}

		// List nodes hold the next node at +0 and an EntityHandle address at +8; the word at +16 points at the
		// list's sentinel node.
		uint32_t listAddr = (uint32_t)attachment + 12;
		uint32_t node = LOAD32(LOAD32(listAddr + 4));
		while (node != LOAD32(listAddr + 4)) {
			uint32_t handle = LOAD32(node + 8);
			result = handle;
			bool entityFlagged = false;
			uint32_t handleSlot = LOAD32(handle + 4);
			if (handleSlot != 0) {
				reg10 = LOAD32(handleSlot);
				if (reg10 == 0) {
					ctx.r1.u64 = stack;
					handOver();
					result = EntityHandle_Release(ctx, base, handle);
					readBack();
				} else {
					ctx.r1.u64 = stack;
					handOver();
					result = EntityHandle_Get_825575C8(ctx, base, handle);
					readBack();
					reg10 = LOAD8((uint32_t)result + 144) & 64;
					entityFlagged = reg10 != 0;
				}
			}

			if (entityFlagged) {
				uint32_t handleAgain = LOAD32(node + 8); // read from the node again, as the original does
				ctx.r1.u64 = stack;
				handOver();
				result = EntityHandle_Get_825575C8(ctx, base, handleAgain);
				readBack();
				uint32_t entity = (uint32_t)result;
				reg10 = (LOAD32(entity + 36) >> 3) & 1;
				if (reg10 != 0) {
					// The entity's value under key 3, found the same way as the owner's.
					uint32_t entityKey3Value;
					uint32_t entityIndex = LOAD32(entity + 140);
					reg10 = LOAD32(entity + 72);
					if (entityIndex != 0) {
						reg10 = reg10 + ((uint32_t)LOAD8(entityIndex + 3) << 3);
						entityKey3Value = LOAD32((uint32_t)reg10 + 4);
					} else if (findKey3((uint32_t)reg10, LOAD32(entity + 76))) {
						STORE64(stack + 88, LOAD64(stack + 80));
						entityKey3Value = LOAD32(LOAD32(stack + 92) + 4);
					} else {
						entityKey3Value = LOAD32((uint32_t)reg6 + 4);
					}
					handOver();
					result = CECGraphicAppearance_SetTintBlock(ctx, base, entityKey3Value, (uint64_t)ownerKey3Value + 96);
					readBack();
				}
			}

			// Iterator check of the original: the node must not have become the sentinel.
			if (node == LOAD32(listAddr + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			node = LOAD32(node);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_82510618, 0x82510618) { ctx.r3.u64 = CECObjectAttachment_SyncEntityAppearances(ctx, base, ctx.r3.u64); }

uint64_t CECObjectAttachment_Update(CpuState& ctx, uint8_t* base, uint64_t attachment) {
	if (!UseLiftedCode(31, 0x825112C0)) { ctx.r3.u64 = attachment; __imp__sub_825112C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825112C0);
	CECObjectAttachment* objectAttachment = GameObject<CECObjectAttachment>(base, attachment);
	if (objectAttachment->m_31 == 0) {
		uint32_t owner = objectAttachment->m_4;
		return Vector_RemoveByValue(ctx, base, owner, attachment);
	}
	return CECObjectAttachment_UpdateTransform(ctx, base, attachment);
}
PROMOTED_ENTRY(31, sub_825112C0, 0x825112C0) { ctx.r3.u64 = CECObjectAttachment_Update(ctx, base, ctx.r3.u64); }

uint64_t CECObjectAttachment_AttachParticleEmittersToEntities(CpuState& ctx, uint8_t* base, uint64_t objectAttachmentAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(31, 0x825112E0)) { ctx.r3.u64 = objectAttachmentAddr; __imp__sub_825112E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825112E0);
	uint32_t stack = ctx.r1.u64;

	CECObjectAttachment* objectAttachment = GameObject<CECObjectAttachment>(base, objectAttachmentAddr);
	stack = PushStackFrame(base, stack, 144);

	// The list at +12 holds entity handles: m_10 (at +16) is its sentinel node, whose first field points at
	// the first node and which points at itself when the list is empty. The iterator {list, node} is kept
	// at stack + 80.
	uint32_t listAddr = (uint32_t)objectAttachmentAddr + 12;
	uint32_t sentinelNode = objectAttachment->m_10;
	uint32_t currentNode = LOAD32(sentinelNode);

	STORE32(stack + 80, listAddr);
	STORE32(stack + 84, currentNode);
	uint64_t iterator = LOAD64(stack + 80);

	while (currentNode != LOAD32(listAddr + 4)) {
		uint32_t handle = LOAD32(currentNode + 8);
		uint32_t handleSlot = LOAD32(handle + 4);
		uint32_t entity = handleSlot != 0 ? LOAD32(handleSlot) : 0;
		if (entity != 0) {
			ctx.r1.u64 = stack;
			ParticleEmitter_AttachToEntityInternal(ctx, base, objectAttachmentAddr, entity, 1);
		} else {
			// A handle without an entity is released (when it has a slot) and its node erased.
			if (handleSlot != 0) {
				ctx.r1.u64 = stack;
				EntityHandle_Release(ctx, base, handle);
			}
			ctx.r1.u64 = stack;
			SharedHandleList_Erase(ctx, base, (uint64_t)stack + 96, objectAttachmentAddr + 12, iterator);
		}

		// Start again from the list's first node.
		uint32_t sentinel = LOAD32(listAddr + 4);
		STORE32(stack + 88, listAddr);
		STORE32(stack + 92, LOAD32(sentinel));
		iterator = LOAD64(stack + 88);
		STORE64(stack + 80, iterator);
		currentNode = LOAD32(stack + 84);
	}

	// A temporary EntityHandle at stack + 80 is pointed at the target entity (m_4); every entry equal to it is
	// erased from the global handle list at 0x834A0000 - 31440, and the temporary handle is then released.
	uint32_t targetEntity = objectAttachment->m_4;
	uint64_t entityHandleVtable = g_820F1664;
	STORE32(stack + 84, 0);
	STORE32(stack + 80, (uint32_t)entityHandleVtable);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = entityHandleVtable;
	EntityHandle_SetTarget(ctx, base, (uint64_t)stack + 80, targetEntity);

	ctx.r8.s64 = g_834A0000;
	EntityHandleList_Remove_822A8BC8(ctx, base, (uint64_t)((int64_t)g_834A0000 - 31440), (uint64_t)stack + 80);

	// The EntityHandle vtable is written again (as 0x820F0000 + 0x1664) before the release.
	uint32_t vtableAgain = uint32_t(g_820F0000) + 5732u;
	STORE32(stack + 80, vtableAgain);
	uint64_t result = EntityHandle_Release(ctx, base, (uint64_t)stack + 80);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_825112E0, 0x825112E0) { ctx.r3.u64 = CECObjectAttachment_AttachParticleEmittersToEntities(ctx, base, ctx.r3.u64); }
