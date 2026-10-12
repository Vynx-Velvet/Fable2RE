// Fable II entity handles - weak references to entities, shared through a ref-counted target.
//
// A handle object (8 bytes, has a vtable) points at a shared target {entity, refcount}. When the
// entity dies its target's entity pointer becomes 0; the next Get() on a handle then drops the
// handle's reference and frees the target once nothing refers to it. Reconstructed from
// sub_825575C8 (Get, 699 callers) and sub_821940C8 (Release, 2320 callers).
#pragma once

#include <fable2/sdk.h>

#include <cstdint>

namespace f2::game {

struct HandleTarget {
  rex::be<uint32_t> entity;    // +0x00 guest address of the entity, 0 once it is gone
  rex::be<uint32_t> refcount;  // +0x04 handles pointing here
};
F2_SIZE(HandleTarget, 8);

struct EntityHandle {
  rex::be<uint32_t> vtable;        // +0x00
  f2::gptr<HandleTarget> target;   // +0x04 (0: empty handle)
};
F2_SIZE(EntityHandle, 8);

// Default vtable of an EntityHandle built on the stack (e.g. Combat.ClearWaypoint).
constexpr uint32_t kEntityHandleVtable = 0x820F1664;

// The entity a handle refers to, or 0 (releasing the handle when its entity is gone) - sub_825575C8.
uint32_t EntityHandleGet(uint32_t handle);
// Drops the handle's reference; the target is freed when unused and dead - sub_821940C8.
void EntityHandleRelease(uint32_t handle);

}  // namespace f2::game
