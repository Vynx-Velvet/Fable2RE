// Fable II health component (Lua "Health") - readable C++ replacing the recompiled functions.
//
// Each function was written from the recompiled PowerPC (ground truth) with the Ghidra
// decompilation as a reading aid; where Ghidra disagreed with the instructions (it showed
// Health.SetAsInvulnerable as a much larger function) the instructions won. Calls into game code
// that is not rewritten yet go through f2::Call (game/rewrite.h).
#include "game/combat/health.h"

#include "generated/Fable2_init.h"
#include "game/rewrite.h"

#include <rex/hook.h>
#include <rex/ppc.h>

namespace f2::game {
namespace {



// Tuning switches (research/catalog/tuning.tsv).
constexpr uint32_t kHeroGodMode = 0x83496B27;
constexpr uint32_t kHenchmanGodMode = 0x83496B3C;
constexpr uint32_t kEnemyGodMode = 0x83496B3D;
constexpr uint32_t kWorldFrame = 0x8331950C;  // frame counter the game stamps changes with

// ETrackedStatType (data/scripts/miscellaneous/trackedstatsenum.lua).
constexpr int32_t STAT_DAMAGE_RECEIVED = 8;
constexpr int32_t STAT_HITS_RECEIVED = 13;

HealthComponent* Self(uint32_t address) { return f2::At<HealthComponent>(address); }
bool Byte(uint32_t address) { return *f2::At<uint8_t>(address) != 0; }

// ---- Getters (Lua Health.Get / GetBase / GetMax / IsInvulnerable / CantDie / ...) --------------
float Get(uint32_t self) { return Self(self)->health; }
float GetBase(uint32_t self) { return Self(self)->base_health; }
float GetMax(uint32_t self) { return Self(self)->max_health; }
uint8_t IsInvulnerable(uint32_t self) { return Self(self)->invulnerable; }
uint8_t CantDie(uint32_t self) { return Self(self)->cant_die; }
float GetDeltaSinceLastDebugDraw(uint32_t self) { return Self(self)->delta_since_debug_draw; }
uint32_t GetFrameLastChanged(uint32_t self) { return Self(self)->frame_last_changed; }
void DoneDebugDraw(uint32_t self) { Self(self)->delta_since_debug_draw = 0.0f; }

// ---- Health.SetAsInvulnerable(on) ----------------------------------------------------------------
void SetAsInvulnerable(uint32_t self, uint32_t on) {
  Self(self)->invulnerable = uint8_t(on);
  if (uint8_t(on)) f2::Call<void>(sub_824B7B40, Self(self)->owner.addr(), 0u);
}

// ---- Health.SetCantDie(on): the entity stays alive at 0 health ------------------------------------
void SetCantDie(uint32_t self, uint32_t on) {
  HealthComponent* h = Self(self);
  h->cant_die = uint8_t(on);
  if (uint8_t(on)) f2::Call<void>(sub_824B7B40, h->owner.addr(), 0u);
  Entity* owner = h->owner.get();
  if (uint32_t death = owner->GetComponent(kComponentDeathHandler)) {
    *f2::At<uint8_t>(death + 0xCC) = h->cant_die == 0;  // "can die"
    uint32_t root = *f2::At<rex::be<uint32_t>>(kGameRoot);
    uint32_t root_c = *f2::At<rex::be<uint32_t>>(root + 0xC);
    f2::Call<void>(sub_8231A9A8, uint32_t(*f2::At<rex::be<uint32_t>>(root_c + 0x8C)),
                              uint32_t(*f2::At<rex::be<uint32_t>>(death + 4)), uint32_t(*f2::At<uint8_t>(death + 0x18)));
  }
}

// ---- Health.Modify(amount, attacker): every heal and every hit goes through here -------------------
//   r3 = this component, f1 = amount (negative = damage), r5 = attacking entity (0 = none).
void Modify(uint32_t self_address, uint32_t /*unused r4*/, uint32_t attacker_address, float amount) {
  HealthComponent* self = Self(self_address);
  Entity* attacker = f2::At<Entity>(attacker_address);
  const float before = self->health;
  const bool attacker_in_combat = attacker && attacker->IsCombatant();

  // The entity's damage rules may refuse this attacker (Health.SetEntityAsDamageableByEntity...).
  if (attacker_in_combat && !f2::Call<uint8_t>(sub_8268DC60, self_address, attacker_address) &&
      amount < 0.0f)
    return;

  // Protected from damage: invulnerable, the matching god mode, or a damage shield.
  bool is_protected = self->invulnerable != 0;
  if (!is_protected) {
    const uint32_t owner = self->owner.addr();
    bool god;
    if (owner == HeroEntity()) god = Byte(kHeroGodMode);
    else if (owner == HenchmanEntity()) god = Byte(kHenchmanGodMode);
    else god = Byte(kEnemyGodMode);
    if (god) is_protected = true;
  }
  Entity* owner = self->owner.get();
  if (uint32_t shield = owner->GetComponent(kComponentDamageShield))
    if (f2::Call<uint8_t>(sub_825296E8, shield, 0u)) is_protected = true;

  if (amount > 0.0f || !is_protected) {
    // Clamped to [0, max]; (the game's branch-free selects: NaN health becomes 0).
    float h = amount + float(self->health);
    if (!(h >= 0.0f)) h = 0.0f;
    const float max = self->max_health;
    self->health = (h - max >= 0.0f) ? max : h;
  }

  if (float(self->health) == before) return;
  if (amount < 0.0f) {
    // Damage dealt by the hero's side is remembered on the victim (its damage tracker).
    if (uint32_t tracker = owner->GetComponent(kComponentDamageTracker)) {
      if (attacker_in_combat) {
        if (uint32_t source = attacker->GetComponent(kComponentAttackSource)) {
          if (f2::Call<int32_t>(sub_822040D0, source, HeroEntity()) == 2) {
            auto& dealt = *f2::At<rex::be<float>>(tracker + 0x34);
            dealt = float(dealt) - amount;
          }
        }
      }
    }
    if (uint32_t stats = owner->GetComponent(kComponentStats)) {
      int32_t received = int32_t(-(float(self->health) - before));
      f2::Call<void>(sub_822D9508, stats, STAT_DAMAGE_RECEIVED, received);  // Stats.ModifyTrackedStat
      f2::Call<void>(sub_822D9508, stats, STAT_HITS_RECEIVED, 1);
    }
    if (uint32_t listener = owner->GetComponent(kComponentDamageListener))
      f2::Call<void>(sub_825644E0, listener);
  }
  self->delta_since_debug_draw = float(self->delta_since_debug_draw) + amount;
  self->frame_last_changed = uint32_t(*f2::At<rex::be<uint32_t>>(kWorldFrame));
  f2::Call<void>(sub_8268E3A0, self_address, attacker_address);  // death / events
}

}  // namespace

F2_REWRITE("combat.health", sub_824B5498, Get)
F2_REWRITE("combat.health", sub_8228AB70, GetBase)
F2_REWRITE("combat.health", sub_82350F48, GetMax)
F2_REWRITE("combat.health", sub_824B5488, IsInvulnerable)
F2_REWRITE("combat.health", sub_824B5490, CantDie)
F2_REWRITE("combat.health", sub_8268A888, GetDeltaSinceLastDebugDraw)
F2_REWRITE("combat.health", sub_8268A890, GetFrameLastChanged)
F2_REWRITE("combat.health", sub_8268A898, DoneDebugDraw)
F2_REWRITE("combat.health", sub_8268F6F8, SetAsInvulnerable)
F2_REWRITE("combat.health", sub_8268F718, SetCantDie)
F2_REWRITE("combat.health", sub_8268BD90, Modify)

}  // namespace f2::game
