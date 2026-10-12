// Fable II health component (Lua table "Health") - layout as used by the game code.
#pragma once

#include "game/core/entity.h"

namespace f2::game {

struct HealthComponent {
  rex::be<uint32_t> vtable;               // +0x00
  f2::gptr<Entity> owner;                 // +0x04
  f2::pad<0x14 - 0x08> unknown_08;
  rex::be<float> health;                  // +0x14 current
  rex::be<float> base_health;             // +0x18 (Health.GetBase)
  rex::be<float> max_health;              // +0x1C
  rex::be<float> max_health_cap;          // +0x20 Health.SetMax clamps to [0, this]
  rex::be<float> regeneration_delay;      // +0x24 (Health.SetRegeneration)
  rex::be<float> regeneration_rate;       // +0x28
  rex::be<uint32_t> over_time_begin;      // +0x2C changes queued by Health.ModifyOverTime
  rex::be<uint32_t> over_time_end;        // +0x30
  f2::pad<0x131 - 0x34> unknown_34;
  uint8_t invulnerable;                   // +0x131 (Health.SetAsInvulnerable)
  uint8_t unknown_132;
  uint8_t cant_die;                       // +0x133 (Health.SetCantDie)
  f2::pad<0x140 - 0x134> unknown_134;
  rex::be<float> delta_since_debug_draw;  // +0x140
  rex::be<uint32_t> frame_last_changed;   // +0x144
};
F2_OFFSET(HealthComponent, health, 0x14);
F2_OFFSET(HealthComponent, max_health_cap, 0x20);
F2_OFFSET(HealthComponent, invulnerable, 0x131);
F2_OFFSET(HealthComponent, cant_die, 0x133);
F2_OFFSET(HealthComponent, delta_since_debug_draw, 0x140);
F2_OFFSET(HealthComponent, frame_last_changed, 0x144);

}  // namespace f2::game
