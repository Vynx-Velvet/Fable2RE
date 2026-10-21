// CMeshResource (vtable 0x820F7EE8): methods of the class as readable C++.
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

uint64_t CMeshResource_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t meshResourceAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(78, 0x82AB4588)) { ctx.r3.u64 = meshResourceAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82AB4588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82AB4588);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CMeshResource_Destruct(ctx, base, meshResourceAddr);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, meshResourceAddr);
	}
	return meshResourceAddr;
}
PROMOTED_ENTRY(78, sub_82AB4588, 0x82AB4588) { ctx.r3.u64 = CMeshResource_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CMeshResource_Destruct(CpuState& ctx, uint8_t* base, uint64_t meshResourceAddr) {
	constexpr uint32_t CMeshResource_vtable = 0x820F7EE8u;
	constexpr uint32_t C_820F1ED0_vtable = 0x820F1ED0u;
	constexpr uint32_t CObjectBase_vtable = 0x820F3A24u;
	constexpr uint32_t globalResourceList = 0x8331A988u;
	if (!UseLiftedCode(78, 0x82AB45D8)) { ctx.r3.u64 = meshResourceAddr; __imp__sub_82AB45D8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82AB45D8);
	const uint32_t msrForUpdate = uint32_t(ctx.r13.u64);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);
	GameStackFrame stackFrame(ctx, base, 112);

	meshResource->vtable = CMeshResource_vtable;
	CMeshResource_Clear(ctx, base, uint32_t(meshResourceAddr));
	List_RemoveNode(ctx, base, globalResourceList, uint32_t(meshResourceAddr));
	ctx.r4.u64 = meshResourceAddr;
	HandleLink_Release(ctx, base, meshResourceAddr + 220);
	SharedHandle_Release(ctx, base, meshResourceAddr + 212);

	// the block at +0xC8 freed, then the three words from +0xC8 cleared
	const uint32_t block = meshResource->m_C8;
	if (block != 0) {
		HandleTarget_Free(ctx, base, block);
	}
	STORE32(uint32_t(meshResourceAddr) + 0xC8, 0);
	STORE32(uint32_t(meshResourceAddr) + 0xCC, 0);
	STORE32(uint32_t(meshResourceAddr) + 0xD0, 0);

	// the mesh builder: its reference count at +4 goes down by one, atomically as in the original (a reserved
	// load and a conditional store under the global lock, with the msr bits it sets around them); at 0 the
	// method in vtable slot 1 (+4) runs
	const uint32_t meshBuilder = meshResource->m_6C;
	if (meshBuilder != 0) {
		const uint64_t refCountAddr = uint64_t(meshBuilder) + 4;
		uint32_t* refCount = reinterpret_cast<uint32_t*>(RAW(uint32_t(refCountAddr)));
		uint32_t remaining = 0;
		bool stored = false;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			const uint32_t savedMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = msrForUpdate & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *refCount;
			remaining = __builtin_bswap32(ctx.reserved.u32) - 1;
			stored = __sync_bool_compare_and_swap(refCount, ctx.reserved.u32, __builtin_bswap32(remaining));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		if (remaining == 0) {
			const uint32_t vtable = LOAD32(meshBuilder);
			const uint32_t method = LOAD32(vtable + 4);
			ctx.r3.u64 = meshBuilder;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
		}
		meshResource->m_6C = 0;
	}

	Vector_DestroyAndFree(ctx, base, uint32_t(meshResourceAddr) + 72);

	// the base class part: unlinked from the owner list it is in
	const uint32_t ownerList = meshResource->m_8;
	meshResource->vtable = C_820F1ED0_vtable;
	if (ownerList != 0) {
		List_RemoveNode(ctx, base, ownerList, uint32_t(meshResourceAddr));
	}
	meshResource->vtable = CObjectBase_vtable;
	return ownerList;
}
PROMOTED_ENTRY(78, sub_82AB45D8, 0x82AB45D8) { ctx.r3.u64 = CMeshResource_Destruct(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82AB6478(CpuState& ctx, uint8_t* base, uint64_t meshResourceAddr, uint64_t forwardedArg) {
	if (!UseLiftedCode(78, 0x82AB6478)) { ctx.r3.u64 = meshResourceAddr; ctx.r4.u64 = forwardedArg; __imp__sub_82AB6478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82AB6478);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);

	// the method in vtable slot 7 (+28) of the object at +0x1C, called with this resource and the forwarded argument
	uint32_t object = meshResource->m_1C;
	uint32_t vtable = LOAD32(object);
	uint32_t method = LOAD32(vtable + 28);
	ctx.r3.u64 = object;
	ctx.r4.u64 = meshResourceAddr;
	ctx.r5.u64 = forwardedArg;
	ctx.r9.u64 = method;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(78, sub_82AB6478, 0x82AB6478) { ctx.r3.u64 = n_sub_82AB6478(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CMeshResource_AppendSkinnedPartMaterials(CpuState& ctx, uint8_t* base, uint64_t meshResourceAddr) {
	constexpr uint32_t fallbackMaterialGlobal = 0x834A5518u;
	if (!UseLiftedCode(78, 0x82AB6498)) { ctx.r3.u64 = meshResourceAddr; __imp__sub_82AB6498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82AB6498);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);
	// handed to the material's method with it: the offset of the material's slot in the array; the original keeps
	// there what the caller, and later the free of the old array, left when the index is negative
	uint64_t materialSlotOffset = ctx.r9.u64;
	uint64_t result = meshResourceAddr;
	GameStackFrame stackFrame(ctx, base, 192);

	for (int32_t partIndex = 0; partIndex < int32_t(meshResource->m_SkinnedPartCount); ++partIndex) {
		const uint32_t skinnedPart = uint32_t(meshResource->m_SkinnedParts) + uint32_t(partIndex) * 156;
		// the part's material record: the material index at +0, the index of the appended material stored at +20
		const uint32_t materialRecord = LOAD32(skinnedPart + 148);
		if (materialRecord == 0) {
			continue;
		}
		const uint32_t materialIndex = LOAD32(materialRecord);
		uint32_t material;
		if (int32_t(materialIndex) >= 0) {
			materialSlotOffset = materialIndex << 2;
			material = LOAD32(uint32_t(materialSlotOffset) + uint32_t(meshResource->m_Materials));
		} else {
			material = LOAD32(fallbackMaterialGlobal);
		}

		// the method in vtable slot 1 (+4) of the material returns the material to append
		const uint32_t vtable = LOAD32(material);
		const uint32_t method = LOAD32(vtable + 4);
		ctx.r3.u64 = material;
		ctx.r9.u64 = materialSlotOffset;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		const uint32_t newMaterial = ctx.r3.u32;

		// its byte at +8 set, then its method in vtable slot 12 (+48), called on it as the first call returned it
		const uint32_t newVtable = LOAD32(newMaterial);
		STORE8(newMaterial + 8, 1);
		const uint32_t newMethod = LOAD32(newVtable + 48);
		ctx.r8.u64 = newMethod;
		ctx.r9.u64 = newVtable;
		REX_CALL_INDIRECT_FUNC(newMethod);

		// the material array grows by one: copied into a new block, the new material at the end
		const uint32_t materialCount = meshResource->m_MaterialCount;
		const uint32_t newCount = materialCount + 1;
		const uint64_t newArrayBytes = newCount <= 0x3FFFFFFFu ? uint64_t(newCount << 2) : UINT64_MAX;
		const uint32_t newMaterials = operator_new(ctx, base, newArrayBytes);
		uint64_t copiedMaterial = ctx.r8.u64;
		uint64_t oldArray = ctx.r9.u64;
		for (uint32_t i = 0; i < materialCount; ++i) {
			oldArray = meshResource->m_Materials;
			copiedMaterial = LOAD32(i * 4 + uint32_t(oldArray));
			STORE32(newMaterials + i * 4, uint32_t(copiedMaterial));
		}
		STORE32(newMaterials + materialCount * 4, newMaterial);
		const uint32_t oldMaterials = meshResource->m_Materials;
		ctx.r8.u64 = copiedMaterial;
		ctx.r9.u64 = oldArray;
		result = HandleTarget_Free(ctx, base, oldMaterials);
		materialSlotOffset = ctx.r9.u64;
		meshResource->m_Materials = newMaterials;
		meshResource->m_MaterialCount = newCount;
		STORE32(materialRecord + 20, materialCount);
	}
	return result;
}
PROMOTED_ENTRY(78, sub_82AB6498, 0x82AB6498) { ctx.r3.u64 = CMeshResource_AppendSkinnedPartMaterials(ctx, base, ctx.r3.u64); }

uint32_t CMeshResource_BuildMeshData(CpuState& ctx, uint8_t* base, uint32_t meshResourceAddr, uint64_t sourceMesh) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t C_820BE3B0_vtable = int32_t(0x820BE3B0);
	if (!UseLiftedCode(78, 0x82AB65B0)) { ctx.r3.u64 = meshResourceAddr; ctx.r4.u64 = sourceMesh; __imp__sub_82AB65B0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82AB65B0);
	uint32_t stack = ctx.r1.u64;
	const uint32_t msrForUpdate = uint32_t(ctx.r13.u64);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);
	stack = PushStackFrame(base, stack, 272);

	// a mesh builder of 156 bytes on the stack (vtable 0x820BE3B0): the word at +4 set to 1, the others cleared
	// (all but +0x28)
	const uint32_t stackBuilder = stack + 80;
	STORE32(stackBuilder + 0x00, uint32_t(C_820BE3B0_vtable));
	STORE32(stackBuilder + 0x04, 1);
	STORE32(stackBuilder + 0x08, 0);
	STORE32(stackBuilder + 0x0C, 0);
	STORE32(stackBuilder + 0x10, 0);
	STORE32(stackBuilder + 0x14, 0);
	STORE32(stackBuilder + 0x18, 0);
	STORE32(stackBuilder + 0x1C, 0);
	STORE32(stackBuilder + 0x20, 0);
	STORE32(stackBuilder + 0x24, 0);
	STORE32(stackBuilder + 0x2C, 0);
	STORE32(stackBuilder + 0x30, 0);
	STORE32(stackBuilder + 0x34, 0);
	STORE8(stackBuilder + 0x38, 0);
	STORE8(stackBuilder + 0x39, 0);
	STORE8(stackBuilder + 0x3A, 0);
	STORE8(stackBuilder + 0x68, 0);
	STORE8(stackBuilder + 0x69, 0);
	STORE32(stackBuilder + 0x90, 0);
	STORE32(stackBuilder + 0x94, 0);
	STORE32(stackBuilder + 0x98, 0);

	ctx.r1.u64 = stack;
	ctx.r7.u64 = uint64_t(int64_t(C_820BE3B0_vtable));
	ctx.r8.s64 = str_TXT_820C0000_B_;
	ctx.r9.u64 = stack + 104;
	n_sub_82B714A0(ctx, base, stackBuilder, sourceMesh);

	// the builder's 8-byte entries lie between the words at +0x2C and +0x30; the end is handed on to
	// MeshBuilder_Destruct, or what the calls below leave in its place
	const uint32_t entriesBegin = LOAD32(stackBuilder + 0x2C);
	uint64_t entriesEnd = LOAD32(stackBuilder + 0x30);
	const uint64_t entryBytes = entriesEnd - entriesBegin;
	if (int32_t(uint32_t(entryBytes) & 0xFFFFFFF8) > 0) {
		ctx.r4.u64 = entryBytes;
		ctx.r5.u64 = entriesBegin;
		ctx.r6.u64 = entriesEnd;
		const uint64_t allocation = operator_new(ctx, base, 156);
		entriesEnd = ctx.r6.u64;
		uint32_t newBuilder = 0;
		if (uint32_t(allocation) != 0) {
			newBuilder = MeshBuilder_ConstructCopy(ctx, base, allocation, stackBuilder);
			entriesEnd = ctx.r6.u64;
		}

		// the builder held at +0x6C: its reference count at +4 goes down by one, atomically as in the original (a
		// reserved load and a conditional store under the global lock, with the msr bits it sets around them); at 0
		// the method in vtable slot 1 (+4) runs; then the copy takes its place
		const uint32_t oldBuilder = meshResource->m_6C;
		if (oldBuilder != 0) {
			const uint64_t refCountAddr = uint64_t(oldBuilder) + 4;
			uint32_t* refCount = reinterpret_cast<uint32_t*>(RAW(uint32_t(refCountAddr)));
			uint32_t remaining = 0;
			bool stored = false;
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				const uint32_t savedMsr = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrForUpdate & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *refCount;
				remaining = __builtin_bswap32(ctx.reserved.u32) - 1;
				stored = __sync_bool_compare_and_swap(refCount, ctx.reserved.u32, __builtin_bswap32(remaining));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!stored);
			if (remaining == 0) {
				const uint32_t vtable = LOAD32(oldBuilder);
				const uint32_t method = LOAD32(vtable + 4);
				ctx.r3.u64 = oldBuilder;
				ctx.r9.u64 = refCountAddr;
				ctx.r10.u64 = method;
				REX_CALL_INDIRECT_FUNC(method);
				entriesEnd = ctx.r6.u64;
			}
			meshResource->m_6C = 0;
		}
		meshResource->m_6C = newBuilder;
	}

	ctx.r6.u64 = entriesEnd;
	const uint32_t result = MeshBuilder_Destruct(ctx, base, stackBuilder);
	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(78, sub_82AB65B0, 0x82AB65B0) { ctx.r3.u64 = CMeshResource_BuildMeshData(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t CMeshResource_Clear(CpuState& ctx, uint8_t* base, uint32_t meshResourceAddr) {
	if (!UseLiftedCode(78, 0x82AB66D0)) { ctx.r3.u64 = meshResourceAddr; __imp__sub_82AB66D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82AB66D0);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);
	GameStackFrame stackFrame(ctx, base, 128);

	// an array allocated behind a header of headerSize bytes whose first word is the element count: with
	// elements, their deleting destructor (vtable slot 0) runs with flags 3 (array, free); else only the block
	// is freed
	auto deleteArray = [&](uint32_t array, uint32_t headerSize) {
		const uint64_t block = uint64_t(array) - headerSize;
		if (LOAD32(array - headerSize) != 0) {
			const uint32_t vtable = LOAD32(array);
			const uint32_t deletingDestructor = LOAD32(vtable);
			ctx.r3.u64 = array;
			ctx.r4.u64 = 3;
			ctx.r9.u64 = deletingDestructor;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(deletingDestructor);
		} else {
			HandleTarget_Free(ctx, base, block);
		}
	};

	// each material: its deleting destructor (vtable slot 0) with delete flags 1; then the array is freed
	for (int32_t i = 0; i < int32_t(meshResource->m_MaterialCount); ++i) {
		const uint32_t material = LOAD32(uint32_t(meshResource->m_Materials) + uint32_t(i) * 4);
		if (material != 0) {
			const uint32_t deletingDestructor = LOAD32(LOAD32(material));
			ctx.r3.u64 = material;
			ctx.r4.u64 = 1;
			ctx.r10.u64 = deletingDestructor;
			REX_CALL_INDIRECT_FUNC(deletingDestructor);
		}
	}
	const uint32_t materials = meshResource->m_Materials;
	HandleTarget_Free(ctx, base, materials);

	const uint32_t meshParts = meshResource->m_MeshParts;
	meshResource->m_Materials = 0;
	if (meshParts != 0) {
		deleteArray(meshParts, 16);
	}

	const uint32_t skinnedParts = meshResource->m_SkinnedParts;
	meshResource->m_MeshParts = 0;
	if (skinnedParts != 0) {
		deleteArray(skinnedParts, 4);
	}

	// 52-byte entries, their count in the word before them, from the last one: the resources referenced at +40
	// and +28 are released and cleared; the count is handed to the first release, each later release gets what
	// the one before left in its place
	const uint32_t resourceEntries = meshResource->m_64;
	meshResource->m_SkinnedParts = 0;
	if (resourceEntries != 0) {
		const uint32_t entryCount = LOAD32(resourceEntries - 4);
		uint64_t releaseHandOver = entryCount;
		for (uint32_t index = entryCount - 1; int32_t(index) >= 0; --index) {
			const uint32_t entry = resourceEntries + index * 52;
			const uint32_t resource40 = LOAD32(entry + 40);
			if (resource40 != 0) {
				ctx.r9.u64 = releaseHandOver;
				CBaseResource_Release(ctx, base, resource40);
				releaseHandOver = ctx.r9.u64;
				STORE32(entry + 40, 0);
			}
			const uint32_t resource28 = LOAD32(entry + 28);
			if (resource28 != 0) {
				ctx.r9.u64 = releaseHandOver;
				CBaseResource_Release(ctx, base, resource28);
				releaseHandOver = ctx.r9.u64;
				STORE32(entry + 28, 0);
			}
		}
		HandleTarget_Free(ctx, base, uint64_t(resourceEntries) - 4);
	}

	const uint32_t member68 = meshResource->m_68;
	meshResource->m_64 = 0;
	if (member68 != 0) {
		deleteArray(member68, 16);
	}
	meshResource->m_68 = 0;

	const uint32_t buckets = meshResource->m_70;
	const uint32_t result = uint32_t(HandleTarget_Free(ctx, base, buckets));
	meshResource->m_70 = 0;

	meshResource->m_MaterialCount = 0;
	meshResource->m_MeshPartCount = 0;
	meshResource->m_SkinnedPartCount = 0;
	meshResource->m_34 = 0;
	meshResource->m_38 = 0;
	meshResource->m_74 = 0;
	return result;
}
PROMOTED_ENTRY(78, sub_82AB66D0, 0x82AB66D0) { ctx.r3.u64 = CMeshResource_Clear(ctx, base, ctx.r3.u32); }

void CMeshResource_UpdateMemoryUsage(CpuState& ctx, uint8_t* base, uint32_t meshResourceAddr) {
	if (!UseLiftedCode(78, 0x82AB6890)) { ctx.r3.u64 = meshResourceAddr; __imp__sub_82AB6890(ctx, base); return; }
	LiftedFrame frame(0x82AB6890);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);

	// bytes per vertex by the first kind of part the resource has: mesh parts, skinned parts, then the kinds
	// counted at +0x34 and +0x38
	uint32_t bytesPerVertex = 0;
	if (uint32_t(meshResource->m_MeshPartCount) != 0) {
		bytesPerVertex = 20;
	} else if (uint32_t(meshResource->m_SkinnedPartCount) != 0) {
		bytesPerVertex = 28;
	} else if (uint32_t(meshResource->m_34) != 0) {
		bytesPerVertex = 24;
	} else if (uint32_t(meshResource->m_38) != 0) {
		bytesPerVertex = 36;
	}

	const uint32_t vertexCount = meshResource->m_TotalVertexCount;
	// left out when both the word at +0x20 and the byte at +0x46 are set
	uint32_t partVertexBytes = 0;
	if (uint32_t(meshResource->m_20) == 0 || meshResource->m_46 == 0) {
		partVertexBytes = vertexCount * bytesPerVertex;
	}
	const uint32_t elementBytes = vertexCount * (uint32_t(meshResource->m_C0) << 4);
	const uint32_t indexBytes = uint32_t(meshResource->m_TotalIndexCount) << 1;
	uint32_t totalBytes = elementBytes + indexBytes + partVertexBytes;

	const uint32_t extraBlock = meshResource->m_D4;
	if (extraBlock != 0) {
		totalBytes += LOAD32(extraBlock + 4);
	}

	// the owner's total at +36: the old usage taken out, the new one added (the owner is read again after the first store)
	uint32_t ownerList = meshResource->m_8;
	if (ownerList != 0) {
		STORE32(ownerList + 36, LOAD32(ownerList + 36) - uint32_t(meshResource->m_MemoryUsage));
		ownerList = meshResource->m_8;
		STORE32(ownerList + 36, LOAD32(ownerList + 36) + totalBytes);
	}
	meshResource->m_MemoryUsage = totalBytes;
}
PROMOTED_ENTRY(78, sub_82AB6890, 0x82AB6890) { CMeshResource_UpdateMemoryUsage(ctx, base, ctx.r3.u32); }

uint32_t CMeshResource_BuildSubmeshBuckets(CpuState& ctx, uint8_t* base, uint32_t meshResourceAddr) {
	if (!UseLiftedCode(78, 0x82AB6970)) { ctx.r3.u64 = meshResourceAddr; __imp__sub_82AB6970(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82AB6970);
	uint32_t stack = ctx.r1.u64;
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);
	stack = PushStackFrame(base, stack, 144);
	uint32_t result = meshResourceAddr;

	const uint32_t meshBuilder = meshResource->m_6C;
	if (meshBuilder != 0) {
		// the builder's 8-byte entries (between its words at +0x2C and +0x30), one 48-byte bucket record each
		constexpr uint32_t kMaxBucketCount = 0x05555555u;
		const uint32_t entryBytes = LOAD32(meshBuilder + 48) - LOAD32(meshBuilder + 44);
		const int32_t entryCount = int32_t(entryBytes) >> 3;
		const uint64_t bucketBytes = uint32_t(entryCount) <= kMaxBucketCount ? uint64_t(uint32_t(entryCount) * 48u) : UINT64_MAX;

		ctx.r1.u64 = stack;
		ctx.r8.u64 = kMaxBucketCount;
		const uint32_t buckets = operator_new(ctx, base, bucketBytes);
		meshResource->m_70 = buckets;
		ctx.r11.u64 = buckets;
		SubmeshBuckets_Initialize(ctx, base, meshBuilder, buckets);

		// a vector of entryCount words at stack+96, each set from the 0 at stack+80; its data pointer at stack+100
		STORE32(stack + 80, 0);
		UIntVector_Construct(ctx, base, stack + 96, uint64_t(int64_t(entryCount)), stack + 80, ctx.r8.u64);
		const uint32_t indexCounts = LOAD32(stack + 100);
		result = indexCounts;

		// how many entries name each index (the first word of an entry; -1 names none)
		for (int32_t i = 0; i < entryCount; ++i) {
			const uint32_t entryIndex = LOAD32(LOAD32(meshBuilder + 44) + uint32_t(i) * 8);
			if (int32_t(entryIndex) != -1) {
				const uint32_t countAddr = indexCounts + (entryIndex << 2);
				STORE32(countAddr, LOAD32(countAddr) + 1);
			}
		}

		// m_74: the first index named more than once (the last index when there is none)
		for (int32_t index = 0; index < entryCount; ++index) {
			meshResource->m_74 = uint32_t(index);
			if (int32_t(LOAD32(indexCounts + uint32_t(index) * 4)) > 1) {
				break;
			}
		}

		if (indexCounts != 0) {
			result = uint32_t(HandleTarget_Free(ctx, base, indexCounts));
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(78, sub_82AB6970, 0x82AB6970) { ctx.r3.u64 = CMeshResource_BuildSubmeshBuckets(ctx, base, ctx.r3.u32); }

void CMeshResource_ComputeTotals(CpuState& ctx, uint8_t* base, uint32_t meshResourceAddr) {
	if (!UseLiftedCode(78, 0x82AB6A78)) { ctx.r3.u64 = meshResourceAddr; __imp__sub_82AB6A78(ctx, base); return; }
	LiftedFrame frame(0x82AB6A78);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);

	// adds one part's vertex and index counts to the totals (the index count is read after the vertex total is stored)
	auto addPartCounts = [&](uint32_t vertexCountAddr, uint32_t indexCountAddr) {
		const uint32_t indexTotal = meshResource->m_TotalIndexCount;
		meshResource->m_TotalVertexCount = LOAD32(vertexCountAddr) + uint32_t(meshResource->m_TotalVertexCount);
		meshResource->m_TotalIndexCount = LOAD32(indexCountAddr) + indexTotal;
	};

	const int32_t meshPartCount = int32_t(meshResource->m_MeshPartCount);
	meshResource->m_TotalVertexCount = 0;
	meshResource->m_TotalIndexCount = 0;
	meshResource->m_44 = 0;
	meshResource->m_45 = 0;

	// mesh parts, 224 bytes: m_44 set when the word at +64 is not 0; vertex count at +132, index count at +128
	if (meshPartCount > 0) {
		const uint32_t meshParts = meshResource->m_MeshParts;
		int32_t index = 0;
		do {
			const uint32_t part = meshParts + uint32_t(index) * 224;
			if (LOAD32(part + 64) != 0) {
				meshResource->m_44 = 1;
			}
			addPartCounts(part + 132, part + 128);
			index++;
		} while (index < int32_t(meshResource->m_MeshPartCount));
	}

	// skinned parts, 156 bytes: m_44 set when the word at +64 is not 0, m_45 when the one at +148 is not 0;
	// vertex count at +124, index count at +128
	if (int32_t(meshResource->m_SkinnedPartCount) > 0) {
		const uint32_t skinnedParts = meshResource->m_SkinnedParts;
		int32_t index = 0;
		do {
			const uint32_t part = skinnedParts + uint32_t(index) * 156;
			if (LOAD32(part + 64) != 0) {
				meshResource->m_44 = 1;
			}
			if (LOAD32(part + 148) != 0) {
				meshResource->m_45 = 1;
			}
			addPartCounts(part + 124, part + 128);
			index++;
		} while (index < int32_t(meshResource->m_SkinnedPartCount));
	}

	// the m_38 records of 240 bytes at m_68: vertex count at +132, index count at +128
	if (int32_t(meshResource->m_38) <= 0) {
		return;
	}
	const uint32_t records = meshResource->m_68;
	int32_t index = 0;
	do {
		const uint32_t record = records + uint32_t(index) * 240;
		addPartCounts(record + 132, record + 128);
		index++;
	} while (index < int32_t(meshResource->m_38));
}
PROMOTED_ENTRY(78, sub_82AB6A78, 0x82AB6A78) { CMeshResource_ComputeTotals(ctx, base, ctx.r3.u32); }

uint32_t CMeshResource_ApplyPartMaterials(CpuState& ctx, uint8_t* base, uint32_t meshResourceAddr) {
	constexpr uint32_t fallbackMaterialGlobal = 0x834A5518u;
	if (!UseLiftedCode(78, 0x82AB6BA8)) { ctx.r3.u64 = meshResourceAddr; __imp__sub_82AB6BA8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82AB6BA8);
	CMeshResource* meshResource = GameObject<CMeshResource>(base, meshResourceAddr);
	GameStackFrame stackFrame(ctx, base, 144);
	uint32_t result = meshResourceAddr;

	// a part's material: the entry of the material array named by the index at +60 of the part, or the fallback
	// material for a negative index; it goes into material slots 1 and 2 (+28 and +44 of the part) of the
	// part's object at +12 (the part address is kept 64-bit as the original adds it)
	auto assignPartMaterial = [&](uint64_t part) {
		const int32_t materialIndex = int32_t(LOAD32(uint32_t(part) + 60));
		const uint32_t material = materialIndex >= 0
			? LOAD32(uint32_t(meshResource->m_Materials) + (uint32_t(materialIndex) << 2))
			: LOAD32(fallbackMaterialGlobal);
		const uint64_t partObject = part + 12;
		MeshPart_AssignMaterial(ctx, base, uint32_t(partObject), partObject + 16, 1, material);
		result = MeshPart_AssignMaterial(ctx, base, uint32_t(partObject), partObject + 32, 2, material);
	};

	// mesh parts of 224 bytes, then skinned parts of 156 bytes
	for (int32_t i = 0; i < int32_t(meshResource->m_MeshPartCount); ++i) {
		assignPartMaterial(uint64_t(uint32_t(meshResource->m_MeshParts)) + uint64_t(i) * 224);
	}
	for (int32_t i = 0; i < int32_t(meshResource->m_SkinnedPartCount); ++i) {
		assignPartMaterial(uint64_t(uint32_t(meshResource->m_SkinnedParts)) + uint64_t(i) * 156);
	}
	return result;
}
PROMOTED_ENTRY(78, sub_82AB6BA8, 0x82AB6BA8) { ctx.r3.u64 = CMeshResource_ApplyPartMaterials(ctx, base, ctx.r3.u32); }

uint32_t CMeshResource_ReadFromStream(CpuState& ctx, uint8_t* base, uint64_t streamAddr, uint64_t recordAddr) {
	if (!UseLiftedCode(78, 0x82AB6CC0)) { ctx.r4.u64 = streamAddr; ctx.r5.u64 = recordAddr; __imp__sub_82AB6CC0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82AB6CC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);
	// the stream's fields (CBufferedReadStream: m_bytesRead, m_cursor, m_bytesRemaining, m_swapBytes), addressed
	// with 32-bit arithmetic as the original does
	const uint32_t bytesReadAddr = uint32_t(streamAddr) + 4;
	const uint32_t cursorAddr = uint32_t(streamAddr) + 12;
	const uint32_t bytesRemainingAddr = uint32_t(streamAddr) + 20;
	const uint32_t swapBytesAddr = uint32_t(streamAddr) + 24;
	// the record (at +0xB0 of the mesh resource for the one caller): five words, then a float vector at +20 whose
	// data pointer is at +24
	const uint32_t record = uint32_t(recordAddr);
	const uint64_t floatVector = recordAddr + 20;
	// each value read is copied here and byte-swapped when the stream says so
	const uint32_t value = stack + 80;

	// What a read leaves behind, which the original hands on to every later call: the stream's new byte count,
	// its new cursor, the slot address and the bytes left in the buffer (after a byte swap two of the swapped bytes
	// take the place of the last two), and in the float loop the second byte read; after a call, what the call
	// left. Until the first read they hold what the caller left.
	uint64_t leftBytesRead = ctx.r6.u64;
	uint64_t leftCursor = ctx.r7.u64;
	uint64_t leftSlot = ctx.r8.u64;
	uint64_t leftBytesInBuffer = ctx.r9.u64;
	uint64_t leftSecondByte = 0;
	auto handOverLeftovers = [&]() {
		ctx.r6.u64 = leftBytesRead;
		ctx.r7.u64 = leftCursor;
		ctx.r8.u64 = leftSlot;
		ctx.r9.u64 = leftBytesInBuffer;
	};
	auto takeLeftovers = [&]() {
		leftBytesRead = ctx.r6.u64;
		leftCursor = ctx.r7.u64;
		leftSlot = ctx.r8.u64;
		leftBytesInBuffer = ctx.r9.u64;
	};

	// one word from the stream into a slot of the frame: copied from the buffer while it holds 4 bytes, else read
	// through CBufferedReadStream_Read; returned byte-swapped when the stream says so
	auto readWord = [&](uint32_t slot) -> uint32_t {
		const uint32_t bytesInBuffer = LOAD32(bytesRemainingAddr);
		if (int32_t(bytesInBuffer) >= 4) {
			const uint32_t cursor = LOAD32(cursorAddr);
			leftBytesInBuffer = uint64_t(bytesInBuffer) - 4;
			leftSlot = slot;
			leftCursor = uint64_t(cursor) + 4;
			leftBytesRead = uint64_t(LOAD32(bytesReadAddr)) + 4;
			STORE8(slot + 0, LOAD8(cursor + 0));
			STORE8(slot + 1, LOAD8(cursor + 1));
			STORE8(slot + 2, LOAD8(cursor + 2));
			STORE8(slot + 3, LOAD8(cursor + 3));
			STORE32(cursorAddr, uint32_t(leftCursor));
			STORE32(bytesRemainingAddr, uint32_t(leftBytesInBuffer));
			STORE32(bytesReadAddr, uint32_t(leftBytesRead));
		} else {
			ctx.r1.u64 = stack;
			handOverLeftovers();
			CBufferedReadStream_Read(ctx, base, streamAddr, slot, 4);
			takeLeftovers();
		}
		const uint8_t swapBytes = LOAD8(swapBytesAddr);
		STORE32(value, LOAD32(slot));
		if (swapBytes != 0) {
			const uint8_t byte2 = LOAD8(value + 2);
			leftBytesInBuffer = LOAD8(slot + 3);
			leftSlot = LOAD8(slot + 0);
			STORE8(value + 2, LOAD8(value + 1));
			STORE8(value + 1, byte2);
			STORE8(value + 0, uint8_t(leftBytesInBuffer));
			STORE8(value + 3, uint8_t(leftSlot));
		}
		return LOAD32(value);
	};

	for (uint32_t i = 0; i < 5; ++i) {
		STORE32(record + i * 4, readWord(stack + 84 + i * 4));
	}
	const uint32_t floatCount = readWord(stack + 104);

	ctx.r1.u64 = stack;
	handOverLeftovers();
	uint32_t result = FloatVector_Resize(ctx, base, floatVector, floatCount);
	leftSecondByte = ctx.r4.u64;
	takeLeftovers();

	// the floats, each read like a word into the slot at stack+108, then stored at the vector's data
	const uint32_t slot = stack + 108;
	for (int32_t i = 0; i < int32_t(floatCount); ++i) {
		const uint32_t bytesInBuffer = LOAD32(bytesRemainingAddr);
		if (int32_t(bytesInBuffer) >= 4) {
			const uint32_t cursor = LOAD32(cursorAddr);
			leftBytesInBuffer = uint64_t(bytesInBuffer) - 4;
			leftSlot = slot;
			leftCursor = uint64_t(cursor) + 4;
			leftBytesRead = uint64_t(LOAD32(bytesReadAddr)) + 4;
			STORE8(slot + 0, LOAD8(cursor + 0));
			leftSecondByte = LOAD8(cursor + 1);
			STORE8(slot + 1, uint8_t(leftSecondByte));
			result = LOAD8(cursor + 2);
			STORE8(slot + 2, uint8_t(result));
			const uint8_t lastByte = LOAD8(cursor + 3);
			STORE32(cursorAddr, uint32_t(leftCursor));
			STORE32(bytesRemainingAddr, uint32_t(leftBytesInBuffer));
			STORE32(bytesReadAddr, uint32_t(leftBytesRead));
			STORE8(slot + 3, lastByte);
		} else {
			handOverLeftovers();
			result = uint32_t(CBufferedReadStream_Read(ctx, base, streamAddr, slot, 4));
			leftSecondByte = ctx.r4.u64;
			takeLeftovers();
		}
		const uint8_t swapBytes = LOAD8(swapBytesAddr);
		ctx.fpscr.disableFlushMode();
		STORE_F32(value, float(double(LOAD_F32(slot))));
		if (swapBytes != 0) {
			const uint8_t byte1 = LOAD8(value + 1);
			leftBytesInBuffer = LOAD8(value + 3);
			leftSlot = LOAD8(value + 2);
			STORE8(value + 3, LOAD8(value + 0));
			STORE8(value + 2, byte1);
			STORE8(value + 0, uint8_t(leftBytesInBuffer));
			STORE8(value + 1, uint8_t(leftSlot));
		}
		ctx.fpscr.disableFlushMode();
		const float floatValue = float(double(LOAD_F32(value)));
		const uint32_t floatData = LOAD32(uint32_t(floatVector) + 4);
		STORE_F32(floatData + uint32_t(i) * 4, floatValue);
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = leftSecondByte;
	ctx.r6.u64 = leftBytesRead;
	ctx.r7.u64 = leftCursor;
	ctx.r8.u64 = leftSlot;
	return result;
}
PROMOTED_ENTRY(78, sub_82AB6CC0, 0x82AB6CC0) { ctx.r3.u64 = CMeshResource_ReadFromStream(ctx, base, ctx.r4.u64, ctx.r5.u64); }
