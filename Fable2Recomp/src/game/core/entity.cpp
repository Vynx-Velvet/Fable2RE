// Fable II entities - helpers shared by the hand-written game code (see entity.h).
#include "game/core/entity.h"

#include "generated/Fable2_init.h"

#include <rex/ppc.h>

#include "game/rewrite.h"

namespace f2::game {

namespace {
// The players object: *(*(*(*(root + 0xC) + 0x58) + 4) + 0), as every caller of the hero / henchman
// lookups computes it.
uint32_t Players() {
  uint32_t root = *f2::At<rex::be<uint32_t>>(kGameRoot);
  uint32_t a = *f2::At<rex::be<uint32_t>>(root + 0xC);
  uint32_t b = *f2::At<rex::be<uint32_t>>(a + 0x58);
  uint32_t c = *f2::At<rex::be<uint32_t>>(b + 4);
  return *f2::At<rex::be<uint32_t>>(c);
}
}  // namespace

uint32_t HeroEntity() { return f2::Call<uint32_t>(sub_8222C210, Players()); }
uint32_t HenchmanEntity() { return f2::Call<uint32_t>(sub_828BEEC0, Players()); }

}  // namespace f2::game
