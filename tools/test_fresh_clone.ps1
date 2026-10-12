# End-to-end release test: a fresh clone of the COMMITTED state, set up from a disc image by tools/setup_all.ps1
# alone, as a new user would (docs/initial-commit-audit.md, blocker 4). Takes hours (codegen, whole-game lift,
# a full build) and pins the CPU: run it overnight.
#
#   powershell -ExecutionPolicy Bypass -File tools/test_fresh_clone.ps1 -Iso "D:\path\Fable 2.iso" [-Dest D:\f2_fresh]
#
# -To <step> stops after that setup step (-To stage: disc identification, extraction and staging take minutes and
# can run during the day); -Reuse continues in the same clone later without running finished steps again.
#
# The clone is made from this machine's repository (committed files only: uncommitted work is not tested); its
# submodules come from their public URLs in .gitmodules (ReXGlue, extract-xiso and the SDK's libraries), as for
# any user. Writes the log to <Dest>\fresh_test.log and leaves the clone in place for inspection.
param(
    [Parameter(Mandatory = $true)][string]$Iso,
    [string]$Dest = '',
    [int]$Jobs = 0,
    [string]$To = '',
    [switch]$NoCheck,
    [switch]$Reuse
)
$ErrorActionPreference = 'Stop'
$Root = Split-Path -Parent $PSScriptRoot
$IsoFull = (Resolve-Path -LiteralPath $Iso).Path
if (-not $Dest) { $Dest = Join-Path (Split-Path -Parent $Root) 'Fable2RE_fresh_test' }
$Log = Join-Path $Dest 'fresh_test.log'

function Say([string]$m) {
    $line = "$(Get-Date -Format s)  $m"
    Write-Host $line
    # a log another program holds open (a viewer following it) must not end a test of several hours
    if (Test-Path -LiteralPath $Dest) {
        try { Add-Content -LiteralPath $Log -Value $line -Encoding utf8 -ErrorAction Stop }
        catch { Write-Warning "could not write to ${Log}: $($_.Exception.Message)" }
    }
}
function Run-Git([string[]]$a) {
    & git @a
    if ($LASTEXITCODE -ne 0) { throw "git $($a -join ' ') failed ($LASTEXITCODE)" }
}

# uncommitted work is not part of the test: say so instead of silently testing something else (rexglue-sdk's own
# working tree always differs from its commit: the patch is applied there)
$dirty = & git -C $Root status --porcelain --untracked-files=no --ignore-submodules=dirty 2>$null
if ($dirty) { Write-Warning "$Root has uncommitted changes; the test uses its last commit only" }

if ((Test-Path -LiteralPath $Dest) -and -not $Reuse) {
    throw "$Dest exists: remove it, choose another -Dest, or pass -Reuse to continue a previous test"
}
if (-not (Test-Path -LiteralPath $Dest)) {
    Run-Git @('clone', '--no-local', $Root, $Dest)
    Say "cloned $Root at $(& git -C $Dest rev-parse --short HEAD)"
    Run-Git @('-C', $Dest, 'submodule', 'update', '--init', '--recursive')
    Say 'submodules checked out from their public URLs'
}

# a full system drive breaks compilers and Python temp files: keep temporary files next to the clone
$tmp = Join-Path $Dest '.tmp'
New-Item -ItemType Directory -Force $tmp | Out-Null
$env:TEMP = $tmp
$env:TMP = $tmp

$setup = Join-Path $Dest 'tools/setup_all.ps1'
$a = @('-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', $setup, '-Iso', $IsoFull)
if ($Jobs -gt 0) { $a += @('-Jobs', "$Jobs") }
if (-not $NoCheck) { $a += '-Check' }
if ($To) { $a += @('-To', $To) }
Say "running: powershell $($a -join ' ')"
$t0 = Get-Date
# Tee-Object in Windows PowerShell 5.1 appends UTF-16 to the UTF-8 log: write the lines as UTF-8 here instead, shared
# so that a viewer can follow the log
$fs = [System.IO.File]::Open($Log, [System.IO.FileMode]::Append, [System.IO.FileAccess]::Write, [System.IO.FileShare]::ReadWrite)
$w = New-Object System.IO.StreamWriter($fs, (New-Object System.Text.UTF8Encoding($false)))
$w.AutoFlush = $true
try {
    & powershell @a *>&1 | ForEach-Object { $_ | Out-String -Stream } | ForEach-Object { Write-Host $_; $w.WriteLine($_) }
    $rc = $LASTEXITCODE
} finally { $w.Dispose() }
Say ("setup_all.ps1 finished with exit code {0} after {1:N1} h" -f $rc, ((Get-Date) - $t0).TotalHours)
if ($rc -ne 0) { Say 'RESULT: FAILED (see the log above; resume with -Reuse after a fix)'; exit 1 }
if ($To) { Say "RESULT: OK through step $To (later steps not run)" } else { Say 'RESULT: OK' }
