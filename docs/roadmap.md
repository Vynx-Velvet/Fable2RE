# Roadmap

The destination is a fully native PC port with readable C++ for the entire game, built from the user's own copy, with comprehensive mods and restored Lionhead debug functionality. Milestones below describe completion criteria, not release dates. See [status](status.md) for present evidence.

## 1. Reproducible local builds

Validate the ISO-to-build path on a clean Windows machine; pin source dependencies, toolchain versions, and analysis inputs; identify supported executables with full hashes; make failures and resume behavior reliable. Completion means another contributor can reproduce the reference build from a supported owned copy without undocumented local files. A graphical installer follows that foundation.

## 2. Readable whole-game C++

Recover names, types, layouts, and subsystem boundaries. Replace generated functions incrementally, compare behavior with the baseline, and track reviewed and tested coverage separately. Prioritize gameplay and performance work without narrowing the final goal to hot paths. Completion requires understandable game systems rather than automatically reformatted instruction translations.

## 3. Remove remaining console dependencies

Finish direct native rendering interfaces and resource ownership; move shader/texture conversion out of gameplay where practical; implement native audio, input, and frame pacing; replace remaining guest platform and middleware dependencies with suitable native implementations. Completion means the game no longer depends on a PPC register model, guest address space, or Xbox hardware compatibility layer. The [dated subsystem inventory](../research/findings/2026-10-01-native-roadmap.md) provides initial targets.

## 4. Restore Lionhead's debug tools

Catalog original commands, test surviving implementations, reconstruct missing functionality, and distinguish original behavior from project-added tools. Completion means a documented command-by-command result, including restored functionality and clearly explained exceptions, rather than assuming every displayed entry works.

## 5. Comprehensive modding

Strengthen Lua/data workflows, expand format coverage, document stable native interfaces, and make installation, conflicts, and removal predictable. Add versioned packages, dependencies, capability declarations, content validation, and save-compatibility rules. Completion means reproducible examples for modifying gameplay, UI, text, assets, and engine behavior with project-authored distributable content.

## 6. Custom quests and levels

Recover the world, navigation, encounter, quest, cutscene, localization, and asset pipelines needed for original content. Build editor/export and validation tools around documented project formats rather than requiring creators to edit opaque game data directly. Completion means an original quest and an original playable level can be authored, packaged, installed, removed, and tested without redistributing Fable II content.

## 7. Native online architecture

Document original cooperative behavior and separate it from retired platform services. Define versioned Fable2RE interfaces for identity, presence, discovery, invitations, sessions, state exchange, mod negotiation, privacy, moderation, and community-operated services. Completion means the preserved cooperative experience works through project-owned protocols with local test fixtures and no production credential requirement. See [online and expansion architecture](online-and-modding-architecture.md).

## 8. Player-ready distribution

Validate full playthroughs, save/load, cooperative play, DLC and supported revisions; record platform and performance coverage; finish accessible setup and troubleshooting. Review public artifact contents and license coverage. Broader edition and platform support follows explicit testing, not assumptions based on available build presets.
