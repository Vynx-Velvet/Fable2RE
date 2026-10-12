# FIRST-TIME / LIFTER-WIDE run on a machine that runs the differential tester: lift the whole game, test what
# changed, drop failures, build. For fixing some functions use tools/lift/update.ps1 -Funcs ... instead (seconds to
# minutes, not hours); for a fresh machine without a build or tester results use tools/setup_all.ps1.
#
#   powershell -ExecutionPolicy Bypass -File tools/lift/verify_and_build.ps1
#
# tools/setup_all.ps1 from its lift step on:
#   lift     renames not applied yet (apply_names.py), apply_names.py --init, lift.py --all (always), then
#            tools/lift/update.ps1: test every function whose lifted text changed since its last test (input
#            profiles 0, 2, 3), skip list, drop the failures
#   config   Fable2.toml and assets/game beside the exe   (only when missing)
#   build    tools/build.ps1 -Preset win-amd64-release -Target Fable2 (ninja compiles only the changed files)
# The class model (lift.py --facts, about 25 min, + classes.py) and the native declarations (native_gen.py) are
# NOT refreshed: a new class model rewrites the structs embedded in every lifted chunk, so a lifter change would
# grow into a whole-game retest and recompile. Refresh them on purpose, overnight:
#   powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -From classes -To build -Tested tester
# (runs classes and decls when their inputs changed; add -Force classes,decls to run them anyway).
# Log and records: tools/.setup/.
#
# Even here only work that is needed happens: chunk files are rewritten only when their text changed, the
# differential test only runs functions whose lifted text changed since their last test, and ninja only
# recompiles changed chunks. Ends with setup_all's exit code (run it in its own PowerShell process).
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $root 'tools/setup_all.ps1') -From lift -To build -Force lift -Tested tester
exit $LASTEXITCODE
