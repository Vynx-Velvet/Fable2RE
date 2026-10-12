# Per-thread CPU usage of the running Fable2.exe over a window: samples each
# thread's kernel+user time twice, -Seconds apart, and prints the threads that
# consumed the most CPU (as % of one core) with their names (SetThreadDescription).
#
# Usage:
#   tools/thread_cpu.ps1 -Seconds 10 [-DelaySeconds 180] [-Top 15]
param(
    [int]$Seconds = 10,
    [int]$DelaySeconds = 0,
    [int]$Top = 15
)
$ErrorActionPreference = 'Stop'
Add-Type @"
using System;
using System.Runtime.InteropServices;
public static class Win32Thr {
  [DllImport("kernel32.dll", SetLastError=true)] public static extern IntPtr OpenThread(uint access, bool inherit, uint tid);
  [DllImport("kernel32.dll")] public static extern bool CloseHandle(IntPtr h);
  [DllImport("kernel32.dll", CharSet=CharSet.Unicode)] public static extern int GetThreadDescription(IntPtr h, out IntPtr desc);
  [DllImport("kernel32.dll")] public static extern IntPtr LocalFree(IntPtr h);
  public static string Describe(uint tid) {
    IntPtr h = OpenThread(0x0040, false, tid); // THREAD_QUERY_LIMITED_INFORMATION
    if (h == IntPtr.Zero) return "";
    IntPtr p; string s = "";
    if (GetThreadDescription(h, out p) >= 0 && p != IntPtr.Zero) { s = Marshal.PtrToStringUni(p); LocalFree(p); }
    CloseHandle(h);
    return s;
  }
}
"@
if ($DelaySeconds -gt 0) { Start-Sleep -Seconds $DelaySeconds }
$gp = Get-Process -Name Fable2 -ErrorAction SilentlyContinue | Select-Object -First 1
if (-not $gp) { throw "Fable2.exe is not running" }
function Snap() {
    $p = Get-Process -Id $gp.Id
    $m = @{}
    foreach ($t in $p.Threads) { $m[[uint32]$t.Id] = @($t.TotalProcessorTime.TotalMilliseconds, $t.PrivilegedProcessorTime.TotalMilliseconds) }
    return @{ threads = $m; total = $p.TotalProcessorTime.TotalMilliseconds }
}
$a = Snap
Start-Sleep -Seconds $Seconds
$b = Snap
$rows = @()
foreach ($tid in $b.threads.Keys) {
    $prev = if ($a.threads.ContainsKey($tid)) { $a.threads[$tid] } else { @(0, 0) }
    $d = $b.threads[$tid][0] - $prev[0]
    $dk = $b.threads[$tid][1] - $prev[1]
    if ($d -le 0) { continue }
    $rows += [pscustomobject]@{ tid = ('{0:x}' -f $tid); core_pct = [math]::Round(100.0 * $d / ($Seconds * 1000.0), 1); kernel_pct = [math]::Round(100.0 * $dk / ($Seconds * 1000.0), 1); name = [Win32Thr]::Describe($tid) }
}
$totalPct = [math]::Round(100.0 * ($b.total - $a.total) / ($Seconds * 1000.0), 1)
"process total: ${totalPct}% of one core over ${Seconds}s (logical CPUs: $env:NUMBER_OF_PROCESSORS)"
$rows | Sort-Object core_pct -Descending | Select-Object -First $Top | Format-Table -AutoSize | Out-String -Width 160
