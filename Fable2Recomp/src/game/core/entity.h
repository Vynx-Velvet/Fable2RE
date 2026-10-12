// Fable II entities - the game object every creature, item and prop is, as laid out in game memory.
//
// An entity owns components (Health, Stats, Combat, Talk, ...). It records which component types it
// has in a bit set and keeps (type, component) pairs sorted by type; an optional per-entity byte
// table maps a type straight to its slot. Reconstructed from the many inlined lookups in the game
// code (e.g. Health.Modify, sub_8268BD90); offsets are verified by F2_OFFSET below.
#pragma once

#include <fable2/sdk.h>

#include <cstdint>

namespace f2::game {

// Component type ids (the game's own numbering; names are ours, from how the code uses them).
// research/symbols/components.tsv collects the evidence.
enum ComponentType : uint32_t {
  kComponentDeathHandler = 0x14,     // consulted when health reaches 0 (SetCantDie writes +0xCC)
  kComponentDamageTracker = 0x23,    // accumulates damage dealt by the hero (+0x34)
  kComponentBreakable = 0x25,        // Breakable.Break when destroyed
  kComponentStats = 0x39,            // tracked stats (Stats.ModifyTrackedStat)
  kComponentDamageShield = 0x4C,     // can make the owner immune (sub_825296E8)
  kComponentAttackSource = 0x85,     // on attackers: who they fight for (sub_822040D0)
  kComponentDamageListener = 0x9F,   // told when the owner was damaged (sub_825644E0)
  kComponentDeathRules = 0xDF,       // custom death handling (sub_82898288)
};

struct ComponentSlot {
  rex::be<int32_t> type;
  rex::be<uint32_t> component;  // guest address
};
F2_SIZE(ComponentSlot, 8);

struct Entity {
  f2::pad<0x24> unknown_00;
  rex::be<uint32_t> component_bits[7];  // +0x24: bit (type & 31) of word (type >> 5) = has component
  f2::pad<0x48 - 0x40> unknown_40;
  f2::gptr<ComponentSlot> components;      // +0x48: sorted by type
  f2::gptr<ComponentSlot> components_end;  // +0x4C
  f2::pad<0x8C - 0x50> unknown_50;
  f2::gptr<uint8_t> component_index;       // +0x8C: optional slot index per type
  uint8_t flags_90;                        // +0x90: 0x40 = takes part in combat

  bool HasComponent(uint32_t type) const { return (component_bits[type >> 5] >> (type & 31)) & 1; }
  bool IsCombatant() const { return (flags_90 & 0x40) != 0; }

  // Guest address of the component of `type`, or 0 when the entity has none - the lookup the game
  // inlines everywhere (lower_bound over the sorted slots, or the index table when present).
  uint32_t GetComponent(uint32_t type) const {
    if (!HasComponent(type)) return 0;
    const ComponentSlot* slots = components.get();
    if (component_index) return slots[component_index.get()[type]].component;
    const ComponentSlot* first = slots;
    const ComponentSlot* last = components_end.get();
    int32_t count = int32_t(last - first);
    while (count > 0) {
      int32_t half = count >> 1;
      if (first[half].type < int32_t(type)) {
        first += half + 1;
        count -= half + 1;
      } else {
        count = half;
      }
    }
    // (The game reads the end slot's component when the type is missing; it never is, given the bit.)
    if (first == last || first->type > int32_t(type)) return last->component;
    return first->component;
  }
  template <class T>
  T* Component(uint32_t type) const {
    return f2::At<T>(GetComponent(type));
  }
};
F2_OFFSET(Entity, component_bits, 0x24);
F2_OFFSET(Entity, components, 0x48);
F2_OFFSET(Entity, components_end, 0x4C);
F2_OFFSET(Entity, component_index, 0x8C);
F2_OFFSET(Entity, flags_90, 0x90);

// The game's root object (*0x83496920) and the player pair it leads to.
constexpr uint32_t kGameRoot = 0x83496920;
uint32_t HeroEntity();      // sub_8222C210(players)
uint32_t HenchmanEntity();  // sub_828BEEC0(players) - the co-op henchman

}  // namespace f2::game
