// Fable II entity handles (see handle.h) - readable C++ replacing the recompiled functions.
#include "game/core/handle.h"

#include "generated/Fable2_init.h"
#include "game/rewrite.h"

namespace f2::game {

void EntityHandleRelease(uint32_t handle) {
  EntityHandle* h = f2::At<EntityHandle>(handle);
  HandleTarget* t = h->target.get();
  if (!t) return;
  t->refcount = t->refcount - 1;
  if (t->refcount == 0 && t->entity == 0) f2::Call<void>(sub_8221BE68, h->target.addr());  // free the target
  h->target.address = 0;
}

uint32_t EntityHandleGet(uint32_t handle) {
  EntityHandle* h = f2::At<EntityHandle>(handle);
  HandleTarget* t = h->target.get();
  if (!t) return 0;
  if (uint32_t entity = t->entity) return entity;
  EntityHandleRelease(handle);
  return 0;
}

F2_REWRITE("core.handle", sub_825575C8, EntityHandleGet)
F2_REWRITE("core.handle", sub_821940C8, EntityHandleRelease)

}  // namespace f2::game
