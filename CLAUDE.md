# Fable2RE development context

Fable2RE aims to reconstruct Fable II as readable C++ and a fully native PC port built from the user's own Xbox 360 copy. Comprehensive modding and fully functional restoration of Lionhead's original debug menu are goals. The current implementation still uses generated/lifted game code and ReXGlue services alongside native replacements.

## Canonical documentation

- [Overview](README.md), [direction](docs/project-direction.md), and [status](docs/status.md).
- [Build/run workflow](docs/building.md) and [architecture](docs/architecture.md).
- [Contributing](CONTRIBUTING.md), [conversion](docs/conversion-guide.md), and [research](research/README.md).

## Working conventions

- Match surrounding code; the runtime currently requests C++23.
- Active codegen input: `Fable2Recomp/Fable2_config.toml`. Do not reintroduce foreign-build symbols or stale `Fable-2_config.toml` instructions.
- Use the build/run wrappers described in the build guide. Build wrappers use `exit`; invoke them in separate PowerShell processes when composing scripts.
- One repository: `Fable2Recomp/` is a folder of it. `rexglue-sdk/` is the public ReXGlue v0.8.0 submodule with `patches/rexglue-sdk.patch` applied to its working tree: keep SDK changes in that patch (`python tools/sdk_patch.py export`), never commit the submodule at another revision. Preserve existing modifications.
- Validate decompiler and AI output against instructions and behavior. Distinguish implemented, built, and runtime-verified work.
- Keep extracted assets, generated translations, lifted output, and decompiler exports local. Review scaffolds for pasted reference code before publication.
- Record investigations under `research/findings/`; update maintained status and guides when conclusions change.
- Credit upstream work. Static recompilation, readable source reconstruction, and removal of runtime compatibility layers are separate milestones.
- Describe Fable2RE and Himdo's project as separate projects sharing ReXGlue. Our verified source ancestry is Fable2Recomp/Fable2Recomp; do not infer a fork relationship from folder names or generated code, or claim unverified ancestry for another project.
