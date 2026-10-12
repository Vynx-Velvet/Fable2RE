# Poor-man's sampling profiler for one thread of a running Fable2.exe.
# Every -IntervalMs it attaches cdb non-invasively, dumps the target thread's
# stack, detaches, and appends the stack to <OutFile> in `~*kb` shape so
# tools/aggregate_stacks.py can histogram it. Each attach pauses the game for
# roughly the symbol-load time (fast when no PDB is present, ~1-2 s with one).
#
# Usage:
#   tools/sample_thread.ps1 -ThreadName "GPU Commands" -Samples 60 -IntervalMs 1000 [-DelaySeconds 180] -OutFile runs/samples_gpu.txt
param(
    [string]$ThreadName = 'GPU Commands',
    [int]$Samples = 60,
    [int]$IntervalMs = 1000,
    [int]$Frames = 20,
    [string]$OutFile = '',
    [int]$DelaySeconds = 0,
    [switch]$AllThreads      # dump every thread each sample (~*kb) instead of one thread
)
$ErrorActionPreference = 'Stop'
if ($DelaySeconds -gt 0) { Write-Host "sample_thread: waiting ${DelaySeconds}s"; Start-Sleep -Seconds $DelaySeconds }
$gp = Get-Process -Name Fable2 -ErrorAction SilentlyContinue | Select-Object -First 1
if (-not $gp) { throw "Fable2.exe is not running" }
if (-not $OutFile) { $OutFile = Join-Path (Split-Path $gp.Path) ("runs\samples_" + ($ThreadName -replace '[^A-Za-z0-9]', '') + "_" + (Get-Date -Format 'HHmmss') + ".txt") }
New-Item -ItemType Directory -Force (Split-Path $OutFile) | Out-Null
$cdb = 'C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\cdb.exe'

function Invoke-Cdb([string]$commands) {
    # One-shot attach: run the commands, detach, return stdout as text.
    $psi = New-Object System.Diagnostics.ProcessStartInfo
    $psi.FileName = $cdb
    $psi.Arguments = "-p $($gp.Id) -pv -lines -c `"$commands; qd`""
    $psi.UseShellExecute = $false
    $psi.RedirectStandardOutput = $true
    $psi.RedirectStandardError = $true
    $p = New-Object System.Diagnostics.Process
    $p.StartInfo = $psi
    $null = $p.Start()
    $text = $p.StandardOutput.ReadToEnd()
    $null = $p.StandardError.ReadToEnd()
    if (-not $p.WaitForExit(60000)) { try { $p.Kill() } catch {} }
    return $text
}

# Find the target thread id by its description once (unless dumping all threads).
$tid = 'all'
if (-not $AllThreads) {
    $listing = Invoke-Cdb '~'
    $line = ($listing -split "`n") | Where-Object { $_ -match [regex]::Escape($ThreadName) } | Select-Object -First 1
    if (-not $line -or $line -notmatch 'Id:\s*[0-9a-f]+\.([0-9a-f]+)') { throw "thread '$ThreadName' not found in cdb thread list" }
    $tid = $matches[1]
}
Write-Host "sample_thread: pid $($gp.Id) thread '$ThreadName' tid 0x$tid -> $OutFile"
$sb = New-Object System.Text.StringBuilder
$got = 0
for ($i = 0; $i -lt $Samples; $i++) {
    if ($gp.HasExited) { break }
    if ($AllThreads) {
        $text = Invoke-Cdb "~*kb $Frames"
        [void]$sb.AppendLine("=== SAMPLE $i ===")
        [void]$sb.AppendLine($text)
    } else {
        $text = Invoke-Cdb "~~[0x$tid]kb $Frames"
        # Keep only the stack part (after the "Child-SP" header) for aggregation.
        $idx = $text.IndexOf('Child-SP')
        if ($idx -lt 0) { $idx = $text.IndexOf(' # Child') }
        $stack = if ($idx -ge 0) { $text.Substring($idx) } else { $text }
        [void]$sb.AppendLine("   0  Id: $($gp.Id).$tid Suspend: 1 Teb: 0 Unfrozen `"$ThreadName`"")
        [void]$sb.AppendLine($stack)
    }
    $got++
    Start-Sleep -Milliseconds $IntervalMs
}
[IO.File]::WriteAllText($OutFile, $sb.ToString())
Write-Host "sample_thread: $got samples -> $OutFile"
