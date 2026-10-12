// Fable II combat component (Lua table "Combat") - layout as used by the game code.
//
// Field meanings come from the Lua methods that read/write them (Combat.GetChaseRadius -> +0x30,
// ...); the Lua scripts in gamescripts/scripts show how they are used. Unknown ranges are padding.
#pragma once

#include "game/core/entity.h"
#include "game/core/handle.h"

namespace f2::game {

// One hit the owner took (Combat hit history, newest first).
struct HitRecord {
  EntityHandle attacker;         // +0x00 (Combat.GetLastEntityThatHitMe)
  rex::be<int32_t> frame;        // +0x08 world frame of the hit
  f2::pad<0x14 - 0x0C> unknown_0c;
  rex::be<float> damage;         // +0x14 (Combat.HowMuchDamageOfTypeInTime)
  rex::be<int32_t> type;         // +0x18 hit type (Combat.GetNumberOfHitsOfTypeInTime)
};
F2_OFFSET(HitRecord, frame, 0x08);
F2_OFFSET(HitRecord, damage, 0x14);
F2_OFFSET(HitRecord, type, 0x18);

// Ring buffer of HitRecord pointers.
struct HitHistory {
  rex::be<uint32_t> unknown_00;
  f2::gptr<rex::be<uint32_t>> records;  // +0x04 capacity pointers
  rex::be<uint32_t> capacity;           // +0x08
  rex::be<uint32_t> head;               // +0x0C index of the newest record
  rex::be<uint32_t> count;              // +0x10
  // The i-th record from the newest (i < count).
  HitRecord* At(uint32_t i) const {
    uint32_t index = head + i;
    if (index >= capacity) index -= capacity;
    return f2::At<HitRecord>(records.get()[index]);
  }
  uint32_t AddressAt(uint32_t i) const {
    uint32_t index = head + i;
    if (index >= capacity) index -= capacity;
    return records.get()[index];
  }
};
F2_SIZE(HitHistory, 0x14);

struct CombatComponent {
  rex::be<uint32_t> vtable;                       // +0x00
  f2::gptr<Entity> owner;                         // +0x04
  f2::pad<0x10 - 0x08> unknown_08;
  f2::pad<0x10> combat_style;                     // +0x10 (Combat.GetCombatStyle returns its address)
  rex::be<float> regroup_point[4];                // +0x20 (Combat.Get/SetRegroupPoint, 16-byte vector)
  rex::be<float> chase_radius;                    // +0x30 (Combat.Get/SetChaseRadius)
  rex::be<float> patrol_radius;                   // +0x34 (Combat.Get/SetPatrolRadius)
  rex::be<float> damage_multiplier;               // +0x38 (Combat.SetDamageMultiplier; enrage changes it)
  rex::be<float> action_speed_multiplier;         // +0x3C (Combat.SetActionSpeedMultiplier)
  f2::pad<0x54 - 0x40> unknown_40;
  rex::be<uint32_t> base_level;                   // +0x54 (Combat.GetBaseLevel)
  uint8_t can_fight;                              // +0x58 (Combat.Get/SetCanFight)
  uint8_t can_flee;                               // +0x59
  uint8_t forced_to_charge;                       // +0x5A
  uint8_t unknown_5b;
  rex::be<int32_t> engaged_frame;                 // +0x5C last frame an enemy engaged us (EngagedByEnemyThisTick)
  rex::be<int32_t> first_engaged_frame;           // +0x60 first such frame (0: never)
  uint8_t firing_from_cover;                      // +0x64
  uint8_t can_be_attacked;                        // +0x65
  f2::pad<0x6C - 0x66> unknown_66;
  uint8_t is_attacking;                           // +0x6C (Combat.SetIsAttacking)
  f2::pad<0x84 - 0x6D> unknown_6d;
  uint8_t in_ally_with_low_health;                // +0x84
  uint8_t use_player_as_regroup_point;            // +0x85 (fights only within patrol_radius of regroup_point)
  f2::pad<0x88 - 0x86> unknown_86;
  rex::be<float> default_chase_radius;            // +0x88 (Combat.SetPlayerRegroupChaseRadius / Reset...)
  rex::be<float> default_patrol_radius;           // +0x8C
  f2::pad<0xA4 - 0x90> unknown_90;
  uint8_t enraged;                                // +0xA4 (Combat.IsEnraged / ClearEnrage)
  f2::pad<0xA8 - 0xA5> unknown_a5;
  rex::be<float> normal_damage_multiplier;        // +0xA8 restored by ClearEnrage
  rex::be<float> normal_action_speed_multiplier;  // +0xAC restored by ClearEnrage
  rex::be<int32_t> last_enrage_frame;             // +0xB0 (Combat.GetLastEnrageTick)
  rex::be<float> starting_chance_to_hit_with_firearm;  // +0xB4
  rex::be<float> max_chance_to_hit_with_firearm_cap;   // +0xB8
  f2::pad<0xE0 - 0xBC> unknown_bc;
  EntityHandle waypoint;                          // +0xE0 (Combat.GetWaypoint / ClearWaypoint)
  f2::pad<0x108 - 0xE8> unknown_e8;
  rex::be<uint32_t> shooting_position_search;     // +0x108 non-zero while searching (IsSearchingForShootingPosition)
  f2::pad<0x110 - 0x10C> unknown_10c;
  rex::be<int32_t> counter_attack_frame;          // +0x110 (Combat.LaunchedCounterAttack); older hits do not count
  HitHistory hits;                                // +0x114
};
F2_OFFSET(CombatComponent, regroup_point, 0x20);
F2_OFFSET(CombatComponent, chase_radius, 0x30);
F2_OFFSET(CombatComponent, base_level, 0x54);
F2_OFFSET(CombatComponent, can_fight, 0x58);
F2_OFFSET(CombatComponent, engaged_frame, 0x5C);
F2_OFFSET(CombatComponent, can_be_attacked, 0x65);
F2_OFFSET(CombatComponent, is_attacking, 0x6C);
F2_OFFSET(CombatComponent, in_ally_with_low_health, 0x84);
F2_OFFSET(CombatComponent, default_chase_radius, 0x88);
F2_OFFSET(CombatComponent, enraged, 0xA4);
F2_OFFSET(CombatComponent, last_enrage_frame, 0xB0);
F2_OFFSET(CombatComponent, max_chance_to_hit_with_firearm_cap, 0xB8);
F2_OFFSET(CombatComponent, waypoint, 0xE0);
F2_OFFSET(CombatComponent, shooting_position_search, 0x108);
F2_OFFSET(CombatComponent, counter_attack_frame, 0x110);
F2_OFFSET(CombatComponent, hits, 0x114);

}  // namespace f2::game
