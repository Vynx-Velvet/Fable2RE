# Online and expansion architecture

The long-term target has two compatible modes: preservation of the original single-player and cooperative experience, and opt-in expansion through project-owned interfaces. The current project has not completed this architecture; this document defines the direction and boundaries contributors should design toward.

## Preservation first

The original game rules, quests, simulation, saves, world transitions, combat, AI, UI, and cooperative behavior need readable implementations and regression coverage. Native replacements should preserve observable behavior by default. Compatibility fixes and optional improvements should be configurable so the preservation path remains testable.

## Project-owned online services

Online support should depend on documented Fable2RE protocols and replaceable service interfaces rather than private platform services. The intended boundaries are:

- identity and profiles that can work locally and with community-operated services;
- session discovery, invitations, presence, and cooperative connection setup;
- an authoritative, validated exchange of player/session state appropriate to the reconstructed simulation;
- version and mod-manifest negotiation before joining a session;
- explicit save ownership, migration, privacy, moderation, and server-operator controls;
- transport and service implementations that can evolve without coupling gameplay code to one provider.

Protocol schemas, compatibility rules, and security assumptions must be versioned and testable. No contributor should need production credentials or access to a private service to test the core interfaces; local loopback and deterministic fixtures should cover the base protocol.

## Expansion and mod support

The mod system should grow from file replacement and hooks into documented authoring interfaces for gameplay, quests, worlds, UI, audio, localization, and native extensions. Custom quests and levels require more than loading loose assets. The project needs stable identifiers, dependency manifests, packaging, conflict diagnostics, content validation, save compatibility rules, and editor/export tooling.

Original game content remains supplied by each user. Distributable mods contain original material or transformations applied locally. A mod manifest should eventually declare required game revision, Fable2RE API version, dependencies, conflicts, load order, capabilities, content hashes, and online compatibility.

## Contribution sequence

Work can proceed incrementally:

1. Document formats, system boundaries, and original behavior with factual metadata.
2. Extract readable interfaces from address-based and guest-memory implementations.
3. Add deterministic local tests for serialization, state transitions, and content validation.
4. Implement native services and authoring tools behind those interfaces.
5. Validate preservation behavior, then expose stable extension points.
6. Publish original examples, including a small quest and level, before declaring an authoring API stable.

This separation lets preservation, native-online, and creator-tool work reinforce each other without making unfinished experimental interfaces permanent.
