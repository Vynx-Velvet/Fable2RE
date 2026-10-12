# Fable2RE documentation

[Project overview](../README.md) · [Contributing](../CONTRIBUTING.md)

## Start here

| Document | Purpose |
|---|---|
| [Project direction](project-direction.md) | Native-port goals, OpenGOAL inspiration, FlyX experience, AI workflow, and comparison with other projects |
| [Current status](status.md) | Implemented work, recorded validation, and known gaps |
| [Build guide](building.md) | Owned-copy inputs, Windows toolchain, setup, build, and run |
| [Roadmap](roadmap.md) | Milestones and completion criteria |
| [Architecture](architecture.md) | Source layout and transition from generated code to readable C++ |
| [Contributor workflows](contributor-workflows.md) | Contribution lanes, naming dictionary workflow, validation levels, and repository boundaries |

## Modding and development

| Document | Purpose |
|---|---|
| [Making mods](making-mods.md) | Lua, data, text, tuning, and native plugins |
| [Online and expansion architecture](online-and-modding-architecture.md) | Direction for community online services, complete preservation, custom quests, and levels |
| [Debug menu](debug-menu.md) | F2 tools, original Lionhead menu, and restoration limits |
| [C++ conversion](conversion-guide.md) | Understand, rewrite, compare, and record game functions |
| [Lifted code](lifted-code.md) | Automatic transformations and fallback controls |
| [Hooking and profiling](modding-guide.md) | Developer instrumentation and dated performance observations |
| [Installer plan](installer-plan.md) | The one-command setup (`tools/setup_all.ps1`) and the planned installer |
| [Settings reference](settings.md) | `Fable2.toml` keys, shipped defaults, verification status, known issues |
| [Promoted code](promoted-code.md) | Model-written readable functions: checks, review, publication |
| [Parallel work](parallel-work.md) | Running rewrite and naming workers alongside development |
| [Initial-commit audit](initial-commit-audit.md) | What the repository may contain, release blockers, validation commands |
| [Publishing](publishing.md) | Publishing progress in one command (`tools/publish.py`) and its checks |
| [Ghidra tooling](../tools/ghidra/README.md) | Local analysis and decompiler exports |

## Research and history

[Research index](../research/README.md) links the dated findings. Findings are evidence from particular builds, not a promise about every later build. [Current status](status.md) is the maintained overview; the runtime's [legacy porting log](../Fable2Recomp/PORTING_STATUS.md) preserves early history.

Keep user instructions here, implementation details beside code where useful, and dated observations under `research/findings/`. Link to the canonical guide instead of duplicating commands or feature claims. Update status when validation changes, and distinguish **implemented**, **tested in a stated scenario**, and **planned**.
