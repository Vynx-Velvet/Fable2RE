# Launch Fable2.exe for a bounded time, capture stdout/stderr, then kill it and
# everything it spawned (Job Object with kill-on-close).
#
# Usage:
#   tools/run_game.ps1                       # debug build, 60 s
#   tools/run_game.ps1 -Seconds 120 -Preset win-amd64-release
#   tools/run_game.ps1 -Tag baseline         # names the capture files run_baseline.*
#
# Captures land in out/build/<preset>/runs/run_<tag>.stderr.txt / .stdout.txt
param(
    [string]$Preset = 'win-amd64-debug',
    [int]$Seconds = 60,
    [string]$Tag = (Get-Date -Format 'yyyyMMdd_HHmmss'),
    [string[]]$GameArgs = @()
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$buildDir = Join-Path $root "Fable2Recomp/out/build/$Preset"
$exe = Join-Path $buildDir 'Fable2.exe'
if (-not (Test-Path $exe)) { throw "missing $exe" }
$runDir = Join-Path $buildDir 'runs'
New-Item -ItemType Directory -Force $runDir | Out-Null
$errFile = Join-Path $runDir "run_$Tag.stderr.txt"
$outFile = Join-Path $runDir "run_$Tag.stdout.txt"

Add-Type -Path (Join-Path $PSScriptRoot 'JobObject.cs')
[Fable2Job]::Create()

# Make sure no previous instance is still holding the log files / GPU.
Get-Process -Name Fable2 -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue

$psi = New-Object System.Diagnostics.ProcessStartInfo
$psi.FileName = $exe
$psi.Arguments = ($GameArgs -join ' ')
$psi.WorkingDirectory = $buildDir
$psi.UseShellExecute = $false
$psi.RedirectStandardOutput = $true
$psi.RedirectStandardError = $true
$p = New-Object System.Diagnostics.Process
$p.StartInfo = $psi
$start = Get-Date
$null = $p.Start()
if (-not [Fable2Job]::Assign($p)) { Write-Warning "could not assign Fable2.exe to job object" }
$outTask = $p.StandardOutput.ReadToEndAsync()
$errTask = $p.StandardError.ReadToEndAsync()

$exited = $p.WaitForExit($Seconds * 1000)
$elapsed = [int]((Get-Date) - $start).TotalSeconds
$status = if ($exited) { "exited code=$($p.ExitCode)" } else { "still running after ${Seconds}s -> closed" }
try {
    if (-not $exited) {
        # Ask the game to close first (OnClosing -> TerminateTitle) so a save in
        # progress can finish; a hard kill mid-write corrupts the autosave and
        # "Continue" then crashes on load. Fall back to the job kill after 8 s.
        try { $p.CloseMainWindow() | Out-Null } catch {}
        if (-not $p.WaitForExit(8000)) { $status += " (forced)" }
    }
    [Fable2Job]::KillAll()
    if (-not $exited) { $p.WaitForExit(5000) | Out-Null }
    $out = $outTask.Result; $err = $errTask.Result
    [IO.File]::WriteAllText($outFile, $out)
    [IO.File]::WriteAllText($errFile, $err)
}
finally {
    [Fable2Job]::Close()
    Get-Process -Name Fable2 -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
}
Write-Host "run_game: $status after ${elapsed}s"
Write-Host "  stderr: $errFile ($((Get-Item $errFile).Length) bytes)"
Write-Host "  stdout: $outFile ($((Get-Item $outFile).Length) bytes)"
Write-Host "  log:    $(Join-Path $buildDir 'fable2.log')"
