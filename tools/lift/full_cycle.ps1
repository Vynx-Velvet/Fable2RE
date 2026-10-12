# Whole-game cycle after a change of the lifter's output form (hours; for single fixes use update.ps1):
# lift everything, test every function whose text changed (plus the extra input profiles for the ones the
# normal inputs cannot compare), drop failures, regenerate the native bridges, build, run the game checks.
# Any step that fails (non-zero exit code, game checks included) stops the cycle.
#
#   powershell -ExecutionPolicy Bypass -File tools/lift/full_cycle.ps1 [-Jobs 6]
param([int]$Jobs = 6)
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
    Step 'native declarations and bridges' { python native_gen.py }
    if (Test-Path cache/facts) { Step 'class model (classes.h)' { python classes.py --facts } }
    Step 'lift (all functions)' { python lift.py --all --skip overridden.txt }
    Step 'test (changed functions)' { python difftest/run.py --jobs $Jobs }
    foreach ($p in 2, 3) {
        Step "test (input profile $p for functions not compared yet)" { python difftest/run.py --profile $p --only-untested --jobs $Jobs }
    }
    Step 'skip list' { python difftest/make_skip.py }
    Step 'drop failing functions from the lifted output' { python lift.py --funcs skip.txt --skip skip.txt }
    $env:REXSDK = Join-Path $root 'rexglue-sdk'
    Step 'build' { powershell -ExecutionPolicy Bypass -File (Join-Path $root 'tools/build.ps1') -Preset win-amd64-release -Target Fable2 }
    # Game checks (tools/autotest.py exit codes: 0 = OK or OK_EXIT_CRASH, 1 = a check failed or the game did not
    # start, 2 = could not run, e.g. no golden save). The cycle stops at the first check that does not exit 0;
    # every run is also recorded in build/validation/ledger.jsonl.
    foreach ($s in 'menu', 'load', 'play') {
        Step "game check: $s" { python (Join-Path $root 'tools/autotest.py') --scenario $s --tag "cycle_$s" }
    }
} finally { Pop-Location }
Write-Host "=== done $(Get-Date -Format HH:mm:ss)"
