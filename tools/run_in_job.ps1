# Run any executable for a bounded time inside a kill-on-close Job Object and
# capture its stdout/stderr. Used for debugger sessions (cdb) and one-off tools
# so nothing outlives the tool call that started it.
#
# Usage:
#   tools/run_in_job.ps1 -Exe cdb.exe -Arguments '-g -G -o Fable2.exe' -Cwd <dir> -Seconds 120 -Tag cdb1
param(
    [Parameter(Mandatory = $true)][string]$Exe,
    [string]$Arguments = '',
    [string]$Cwd = (Get-Location).Path,
    [int]$Seconds = 120,
    [string]$Tag = (Get-Date -Format 'yyyyMMdd_HHmmss'),
    [string]$OutDir = ''
)

$ErrorActionPreference = 'Stop'
if (-not $OutDir) { $OutDir = Join-Path $Cwd 'runs' }
New-Item -ItemType Directory -Force $OutDir | Out-Null
$errFile = Join-Path $OutDir "job_$Tag.stderr.txt"
$outFile = Join-Path $OutDir "job_$Tag.stdout.txt"

Add-Type -Path (Join-Path $PSScriptRoot 'JobObject.cs')
[Fable2Job]::Create()

$psi = New-Object System.Diagnostics.ProcessStartInfo
$psi.FileName = $Exe
$psi.Arguments = $Arguments
$psi.WorkingDirectory = $Cwd
$psi.UseShellExecute = $false
$psi.RedirectStandardOutput = $true
$psi.RedirectStandardError = $true
$psi.RedirectStandardInput = $true
$p = New-Object System.Diagnostics.Process
$p.StartInfo = $psi
$start = Get-Date
$null = $p.Start()
if (-not [Fable2Job]::Assign($p)) { Write-Warning "could not assign $Exe to job object" }
$outTask = $p.StandardOutput.ReadToEndAsync()
$errTask = $p.StandardError.ReadToEndAsync()

$exited = $p.WaitForExit($Seconds * 1000)
$elapsed = [int]((Get-Date) - $start).TotalSeconds
$status = if ($exited) { "exited code=$($p.ExitCode)" } else { "still running after ${Seconds}s -> killed" }
try {
    [Fable2Job]::KillAll()
    if (-not $exited) { $p.WaitForExit(5000) | Out-Null }
    [IO.File]::WriteAllText($outFile, $outTask.Result)
    [IO.File]::WriteAllText($errFile, $errTask.Result)
}
finally {
    [Fable2Job]::Close()
}
Write-Host "run_in_job: $Exe $status after ${elapsed}s"
Write-Host "  stdout: $outFile ($((Get-Item $outFile).Length) bytes)"
Write-Host "  stderr: $errFile ($((Get-Item $errFile).Length) bytes)"
