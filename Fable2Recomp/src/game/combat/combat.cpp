// Fable II combat component (Lua "Combat") - readable C++ replacing the recompiled functions.
//
// Written from the recompiled PowerPC (`// insn` comments in generated/, ground truth) with the
// Ghidra output as a reading aid. Functions not here are still the recompiled originals (see
// research/catalog/functions.tsv, Lua_Combat_*): GetAmbush*, firing positions,
// HaveIBeenHitByEntityRecently / KnockedDown..., Override/RestoreCombatStyle, CanJumpNow,
// SetRegroupPoint (takes a vector register).
//
// Several of the tiny accessors are shared with other classes by the linker (identical code
// folding), e.g. the "lbz r3,0x59(r3)" behind GetCanFlee: replacing them with the same behaviour
// is safe for every user.
#include "game/combat/combat.h"

#include "generated/Fable2_init.h"
#include "game/rewrite.h"

#include <cmath>
#include <cstring>

namespace f2::game {
namespace {

constexpr uint32_t kWorldFrame = 0x8331950C;       // int: frame counter the game stamps events with
constexpr uint32_t kTicksPerSecond = 0x83319510;   // double: world frames per second
constexpr uint32_t kNeverHitTime = 0x82000BE0;     // float: FLT_MAX, "time since last hit" with no hits
constexpr uint32_t kDogMaulDamage = 0x83318D28;    // float[5]: Combat.SetDogMaulDamage(level 1..5, damage)
constexpr uint32_t kComponentAttackAnimation = 0x5B;  // told about SetIsAttacking (sub_82389A68)

CombatComponent* Self(uint32_t address) { return f2::At<CombatComponent>(address); }
int32_t Now() { return *f2::At<rex::be<int32_t>>(kWorldFrame); }
double TicksPerSecond() { return *f2::At<rex::be<double>>(kTicksPerSecond); }
// 32-bit wrapping arithmetic on frame numbers, as the PowerPC add/subf.
int32_t Add(int32_t a, int32_t b) { return int32_t(uint32_t(a) + uint32_t(b)); }
int32_t Sub(int32_t a, int32_t b) { return int32_t(uint32_t(a) - uint32_t(b)); }

// Seconds -> world frames, truncated like the game's fctiwz (saturating).
int32_t SecondsToFrames(float seconds) {
  double v = double(seconds) * TicksPerSecond();
  if (std::isnan(v)) return INT32_MIN;
  if (v >= 2147483647.0) return INT32_MAX;
  if (v <= -2147483648.0) return INT32_MIN;
  return int32_t(v);
}

// ---- Plain fields -------------------------------------------------------------------------------
uint32_t GetBaseLevel(uint32_t self) { return Self(self)->base_level; }
uint32_t GetCombatStyle(uint32_t self) { return self + 0x10; }  // address of the style block
float GetChaseRadius(uint32_t self) { return Self(self)->chase_radius; }
void SetChaseRadius(uint32_t self, float r) { Self(self)->chase_radius = r; }
float GetPatrolRadius(uint32_t self) { return Self(self)->patrol_radius; }
void SetPatrolRadius(uint32_t self, float r) { Self(self)->patrol_radius = r; }
void SetDamageMultiplier(uint32_t self, float m) { Self(self)->damage_multiplier = m; }
void SetActionSpeedMultiplier(uint32_t self, float m) { Self(self)->action_speed_multiplier = m; }
void SetCanFight(uint32_t self, uint32_t on) { Self(self)->can_fight = uint8_t(on); }
uint8_t GetCanFlee(uint32_t self) { return Self(self)->can_flee; }
void SetCanFlee(uint32_t self, uint32_t on) { Self(self)->can_flee = uint8_t(on); }
uint8_t GetForcedToCharge(uint32_t self) { return Self(self)->forced_to_charge; }
void SetForcedToCharge(uint32_t self, uint32_t on) { Self(self)->forced_to_charge = uint8_t(on); }
uint8_t GetFiringFromCover(uint32_t self) { return Self(self)->firing_from_cover; }
void SetFiringFromCover(uint32_t self, uint32_t on) { Self(self)->firing_from_cover = uint8_t(on); }
uint8_t GetCanBeAttacked(uint32_t self) { return Self(self)->can_be_attacked; }
void SetCanBeAttacked(uint32_t self, uint32_t on) { Self(self)->can_be_attacked = uint8_t(on); }
uint8_t IsInAllyWithLowHealth(uint32_t self) { return Self(self)->in_ally_with_low_health; }
void SetIsInAllyWithLowHealth(uint32_t self, uint32_t on) { Self(self)->in_ally_with_low_health = uint8_t(on); }
uint8_t GetUsePlayerAsRegroupPoint(uint32_t self) { return Self(self)->use_player_as_regroup_point; }
uint8_t IsEnraged(uint32_t self) { return Self(self)->enraged; }
uint32_t GetLastEnrageTick(uint32_t self) { return uint32_t(int32_t(Self(self)->last_enrage_frame)); }
float GetStartingChanceToHitWithFirearm(uint32_t self) { return Self(self)->starting_chance_to_hit_with_firearm; }
float GetMaxChanceToHitWithFirearmCap(uint32_t self) { return Self(self)->max_chance_to_hit_with_firearm_cap; }
void SetMaxChanceToHitWithFirearmCap(uint32_t self, float v) { Self(self)->max_chance_to_hit_with_firearm_cap = v; }
uint8_t IsSearchingForShootingPosition(uint32_t self) { return Self(self)->shooting_position_search != 0; }

// Combat.GetRegroupPoint: returned through a hidden out pointer (r3), component in r4.
uint32_t GetRegroupPoint(uint32_t out, uint32_t self) {
  std::memcpy(f2::HostPtr(out), Self(self)->regroup_point, 16);
  return out;
}

// ---- Regroup radii: the "player regroup" values are the defaults Reset goes back to -------------
void SetPlayerRegroupChaseRadius(uint32_t self, float chase, float patrol) {
  CombatComponent* c = Self(self);
  c->default_chase_radius = chase;
  c->chase_radius = chase;
  c->default_patrol_radius = patrol;
  c->patrol_radius = patrol;
}
void OverridePlayerRegroupChaseRadius(uint32_t self, float chase, float patrol) {
  Self(self)->chase_radius = chase;
  Self(self)->patrol_radius = patrol;
}
void ResetPlayerRegroupChaseRadius(uint32_t self) {
  CombatComponent* c = Self(self);
  c->chase_radius = float(c->default_chase_radius);
  c->patrol_radius = float(c->default_patrol_radius);
}

// ---- Enrage / engagement / counter attacks ------------------------------------------------------
void ClearEnrage(uint32_t self) {
  CombatComponent* c = Self(self);
  c->damage_multiplier = float(c->normal_damage_multiplier);
  c->action_speed_multiplier = float(c->normal_action_speed_multiplier);
  c->enraged = 0;
}

void EngagedByEnemyThisTick(uint32_t self) {
  CombatComponent* c = Self(self);
  if (c->first_engaged_frame == 0) c->first_engaged_frame = Now();
  c->engaged_frame = Now();
}

void LaunchedCounterAttack(uint32_t self) { Self(self)->counter_attack_frame = Now(); }

// Global: damage of a dog maul per level (1..5); other levels are ignored.
void SetDogMaulDamage(int32_t level, float damage) {
  if (level <= 0 || level > 5) return;
  f2::At<rex::be<float>>(kDogMaulDamage)[level - 1] = damage;
}

// ---- Can it fight now? Tethered creatures only fight near their regroup point --------------------
uint8_t GetCanFight(uint32_t self) {
  CombatComponent* c = Self(self);
  if (c->use_player_as_regroup_point) {
    // Owner position: virtual function 16 (+0x40) of the owner's object at +0x7C, returning a vector.
    uint32_t placement = *f2::At<rex::be<uint32_t>>(c->owner.addr() + 0x7C);
    uint32_t vtable = *f2::At<rex::be<uint32_t>>(placement);
    f2::GuestStackBuffer position(16);
    f2::CallAt<void>(*f2::At<rex::be<uint32_t>>(vtable + 0x40), position.address(), placement);
    const rex::be<float>* p = position.As<rex::be<float>>();
    // Horizontal distance (x, y), single precision like the vector unit.
    float dx = float(c->regroup_point[0]) - float(p[0]);
    float dy = float(c->regroup_point[1]) - float(p[1]);
    float distance_sq = dx * dx + dy * dy;
    float patrol = c->patrol_radius;
    if (distance_sq > patrol * patrol) return 0;
  }
  return c->can_fight;
}

// Combat.SetIsAttacking: stored here, and passed on to the attack-animation component if any.
uint32_t SetIsAttacking(uint32_t self, uint32_t on) {
  CombatComponent* c = Self(self);
  c->is_attacking = uint8_t(on);
  uint32_t component = c->owner->GetComponent(kComponentAttackAnimation);
  if (!component) return 0;
  return f2::Call<uint32_t>(sub_82389A68, component, on);
}

// Combat.IsChargingFlourishAttack: only players charge flourishes.
uint8_t IsChargingFlourishAttack(uint32_t self) {
  uint32_t owner = Self(self)->owner.addr();
  uint32_t root = *f2::At<rex::be<uint32_t>>(kGameRoot);
  uint32_t a = *f2::At<rex::be<uint32_t>>(root + 0xC);
  uint32_t b = *f2::At<rex::be<uint32_t>>(a + 0x58);
  uint32_t c = *f2::At<rex::be<uint32_t>>(b + 4);
  uint32_t players = *f2::At<rex::be<uint32_t>>(c);
  if (!uint8_t(f2::Call<uint32_t>(sub_82232748, players, owner))) return 0;  // is a player
  f2::GuestStackBuffer charging(16);
  *charging.As<uint8_t>() = 0;
  if (!uint8_t(f2::Call<uint32_t>(sub_82273008, owner, charging.address()))) return 0;
  return *charging.As<uint8_t>() != 0;
}

// ---- Waypoint -----------------------------------------------------------------------------------
uint32_t GetWaypoint(uint32_t self) { return EntityHandleGet(self + offsetof(CombatComponent, waypoint)); }

void ClearWaypoint(uint32_t self) {
  // Assigns an empty handle (built on the stack the way the game does).
  f2::GuestStackBuffer empty(sizeof(EntityHandle));
  EntityHandle* h = empty.As<EntityHandle>();
  h->vtable = kEntityHandleVtable;
  h->target.address = 0;
  EntityHandleRelease(empty.address());
  f2::Call<void>(sub_82978470, self + uint32_t(offsetof(CombatComponent, waypoint)), empty.address());  // assign
  h->vtable = kEntityHandleVtable;
  EntityHandleRelease(empty.address());
}

// ---- Hit history (newest first) -----------------------------------------------------------------
float GetTimeSinceIWasLastHit(uint32_t self) {
  const HitHistory& hits = Self(self)->hits;
  if (hits.count == 0) return *f2::At<rex::be<float>>(kNeverHitTime);
  int32_t frames = Sub(Now(), hits.At(0)->frame);
  return float(double(int64_t(frames)) / TicksPerSecond());
}

uint32_t GetLastEntityThatHitMe(uint32_t self) {
  const HitHistory& hits = Self(self)->hits;
  if (hits.count == 0) return 0;
  return EntityHandleGet(hits.AddressAt(0));  // the record starts with the attacker's handle
}

int32_t GetNumberOfHitsOfTypeInTime(uint32_t self, int32_t type, float seconds) {
  const HitHistory& hits = Self(self)->hits;
  int32_t window = SecondsToFrames(seconds), now = Now(), n = 0;
  for (uint32_t i = 0; i < hits.count; ++i) {
    const HitRecord* r = hits.At(i);
    if (r->type == type && Add(r->frame, window) > now) ++n;
  }
  return n;
}

// Hits since the last counter attack.
float HowMuchDamageOfTypeInTime(uint32_t self, int32_t type, float seconds) {
  const CombatComponent* c = Self(self);
  int32_t window = SecondsToFrames(seconds), now = Now();
  float total = 0.0f;
  for (uint32_t i = 0; i < c->hits.count; ++i) {
    const HitRecord* r = c->hits.At(i);
    if (r->type == type && Add(r->frame, window) > now && r->frame > c->counter_attack_frame)
      total = float(r->damage) + total;
  }
  return total;
}

// Hits in a row, each at most `seconds` after the next (counting back from now).
int32_t GetNumberOfSuccessiveHits(uint32_t self, float seconds) {
  const HitHistory& hits = Self(self)->hits;
  int32_t window = SecondsToFrames(seconds), previous = Now(), n = 0;
  for (uint32_t i = 0; i < hits.count; ++i) {
    int32_t frame = hits.At(i)->frame;
    if (Sub(previous, frame) > window) break;
    ++n;
    previous = frame;
  }
  return n;
}

}  // namespace

F2_REWRITE("combat.combat", sub_827942F8, GetBaseLevel)
F2_REWRITE("combat.combat", sub_8268A048, GetCombatStyle)
F2_REWRITE("combat.combat", sub_82794EF0, GetChaseRadius)
F2_REWRITE("combat.combat", sub_82794EE8, SetChaseRadius)
F2_REWRITE("combat.combat", sub_8249E9D8, GetPatrolRadius)
F2_REWRITE("combat.combat", sub_8251CF88, SetPatrolRadius)
F2_REWRITE("combat.combat", sub_826F97E0, SetDamageMultiplier)
F2_REWRITE("combat.combat", sub_82795030, SetActionSpeedMultiplier)
F2_REWRITE("combat.combat", sub_8274B7E8, SetCanFight)
F2_REWRITE("combat.combat", sub_82639A10, GetCanFlee)
F2_REWRITE("combat.combat", sub_82794300, SetCanFlee)
F2_REWRITE("combat.combat", sub_82794318, GetForcedToCharge)
F2_REWRITE("combat.combat", sub_82794320, SetForcedToCharge)
F2_REWRITE("combat.combat", sub_82794308, GetFiringFromCover)
F2_REWRITE("combat.combat", sub_82794310, SetFiringFromCover)
F2_REWRITE("combat.combat", sub_82794328, GetCanBeAttacked)
F2_REWRITE("combat.combat", sub_8237D4B8, SetCanBeAttacked)
F2_REWRITE("combat.combat", sub_82798F48, IsInAllyWithLowHealth)
F2_REWRITE("combat.combat", sub_82798F40, SetIsInAllyWithLowHealth)
F2_REWRITE("combat.combat", sub_82794FE8, GetUsePlayerAsRegroupPoint)
F2_REWRITE("combat.combat", sub_8228EFF8, IsEnraged)
F2_REWRITE("combat.combat", sub_82798F38, GetLastEnrageTick)
F2_REWRITE("combat.combat", sub_82798988, GetStartingChanceToHitWithFirearm)
F2_REWRITE("combat.combat", sub_82798980, GetMaxChanceToHitWithFirearmCap)
F2_REWRITE("combat.combat", sub_82798978, SetMaxChanceToHitWithFirearmCap)
F2_REWRITE("combat.combat", sub_82798550, IsSearchingForShootingPosition)
F2_REWRITE("combat.combat", sub_82794ED8, GetRegroupPoint)
F2_REWRITE("combat.combat", sub_82794FF0, SetPlayerRegroupChaseRadius)
F2_REWRITE("combat.combat", sub_82795008, OverridePlayerRegroupChaseRadius)
F2_REWRITE("combat.combat", sub_82795018, ResetPlayerRegroupChaseRadius)
F2_REWRITE("combat.combat", sub_82798F18, ClearEnrage)
F2_REWRITE("combat.combat", sub_821AE560, EngagedByEnemyThisTick)
F2_REWRITE("combat.combat", sub_82796A80, LaunchedCounterAttack)
F2_REWRITE("combat.combat", sub_827950D8, SetDogMaulDamage)
F2_REWRITE("combat.combat", sub_821B23F8, GetCanFight)
F2_REWRITE("combat.combat", sub_827977A0, SetIsAttacking)
F2_REWRITE("combat.combat", sub_822B5610, IsChargingFlourishAttack)
F2_REWRITE("combat.combat", sub_825561F0, GetWaypoint)
F2_REWRITE("combat.combat", sub_82798910, ClearWaypoint)
F2_REWRITE("combat.hits", sub_8218BC50, GetTimeSinceIWasLastHit)
F2_REWRITE("combat.hits", sub_82796A90, GetLastEntityThatHitMe)
F2_REWRITE("combat.hits", sub_821C7BB8, GetNumberOfHitsOfTypeInTime)
F2_REWRITE("combat.hits", sub_827970C8, HowMuchDamageOfTypeInTime)
F2_REWRITE("combat.hits", sub_82796AE8, GetNumberOfSuccessiveHits)

}  // namespace f2::game
