# Incremental lift cycle: only touches what changed.
#
#   powershell -ExecutionPolicy Bypass -File tools/lift/update.ps1 -Funcs sub_82B4D300,sub_821DCC90
#   powershell -ExecutionPolicy Bypass -File tools/lift/update.ps1 -Funcs fixlist.txt -Build
#
#   1. re-lift just these functions (rewrites only their chunk files, and only if the text changed)
#   2. differential-test every lifted function whose text changed since its last test
#   2b. timeouts get the other input profiles (2, 3)
#   3. functions that fail (or are untested) are dropped from the lifted output - they stay recompiled
#   4. -Build: ninja recompiles only the chunk files that changed
#
# Without -Funcs it skips step 1 (e.g. after editing chunks by hand or a lifter-wide change already applied).
param([string]$Funcs = '', [switch]$Build)
$ErrorActionPreference = 'Stop'
# Run below normal priority (the compilers and test programs started from here inherit it), so the
# machine stays usable while this works.
[System.Diagnostics.Process]::GetCurrentProcess().PriorityClass = 'BelowNormal'
$lift = $PSScriptRoot
$root = Split-Path -Parent (Split-Path -Parent $lift)
function Step([string]$what, [scriptblock]$body) {
    Write-Host "=== $what ($(Get-Date -Format HH:mm:ss))"
    & $body
    if ($LASTEXITCODE -ne 0) { throw "$what failed (exit $LASTEXITCODE)" }
}
Push-Location $lift
try {
    if ($Funcs) { Step 'lift (only the given functions)' { python lift.py --funcs $Funcs --skip overridden.txt } }
    Step 'test (only changed functions)' { python difftest/run.py }
    # functions the normal inputs could not compare (timeouts): the other input profiles, before they are dropped
    foreach ($p in 2, 3) {
        Step "test (input profile $p for functions not compared yet)" { python difftest/run.py --profile $p --only-untested }
    }
    Step 'skip list' { python difftest/make_skip.py }
    Step 'drop failing functions from the lifted output' { python lift.py --funcs skip.txt --skip skip.txt }
    if ($Build) {
        $env:REXSDK = Join-Path $root 'rexglue-sdk'
        Step 'build (changed chunks only)' { & (Join-Path $root 'tools/build.ps1') -Preset win-amd64-release -Target Fable2 }
    }
} finally { Pop-Location }
Write-Host "=== done $(Get-Date -Format HH:mm:ss)"
