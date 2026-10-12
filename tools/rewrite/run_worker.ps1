# Keeps a rewrite or naming worker running on a CLI that runs one-shot sessions: starts a new session with the
# same instruction whenever the previous one ends, until the queue is done.
#
#   powershell -ExecutionPolicy Bypass -File tools/rewrite/run_worker.ps1 `
#       -Cli claude -Model <model> -Task rewrite
#
# -Cli        the command of the CLI to run ("claude" if it is on PATH under that name)
# -Model      passed as --model (leave empty if the CLI picks the model itself)
# -ConfigDir  CLAUDE_CONFIG_DIR for this worker (default ~/.claude-worker): its own login, settings and
#             session history, so it never touches the main session's login in ~/.claude
# -Task       rewrite (tools/rewrite/AGENT.md) or naming (tools/naming/AGENT.md)
# -ExtraArgs  anything else the CLI needs, as one string
#
# The work itself is stateless between sessions: next_packet.py hands out the next packet from the files on
# disk, and a packet whose session died is offered again after 90 minutes without new files.
param(
    [string]$Cli = 'claude',
    [string]$Model = '',
    [string]$ConfigDir = "$env:USERPROFILE\.claude-worker",
    [ValidateSet('rewrite', 'naming')][string]$Task = 'rewrite',
    [string]$ExtraArgs = '',
    [int]$RestartDelaySeconds = 30
)
$root = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
Set-Location $root
$env:CLAUDE_CONFIG_DIR = $ConfigDir
New-Item -ItemType Directory -Force $ConfigDir | Out-Null
$instructions = if ($Task -eq 'rewrite') { 'tools/rewrite/AGENT.md' } else { 'tools/naming/AGENT.md' }
$next = if ($Task -eq 'rewrite') { 'tools/rewrite/next_packet.py' } else { 'tools/naming/next_batch.py' }
$prompt = "Read $instructions and follow it until it prints DONE. Work only inside this repository."
# What the worker may do without asking: read and write files, and run the project's own scripts.
$allowed = 'Read,Write,Edit,Glob,Grep,Bash(python tools/rewrite/*),Bash(python tools/naming/*),Bash(python tools/lift/difftest/run.py*)'
$log = Join-Path $root "build\worker_$Task.log"
while ($true) {
    $left = (python $next --status 2>&1 | Out-String).Trim()
    "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') starting session; queue: $left" | Tee-Object -FilePath $log -Append
    if ($left -match ' 0 waiting' -and $left -match ' 0 in progress') { 'queue done'; break }
    $args = @('-p', $prompt, '--allowedTools', $allowed)
    if ($Model) { $args += @('--model', $Model) }
    if ($ExtraArgs) { $args += $ExtraArgs.Split(' ') }
    & $Cli @args 2>&1 | Tee-Object -FilePath $log -Append
    "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') session ended (exit $LASTEXITCODE); restarting in $RestartDelaySeconds s" |
        Tee-Object -FilePath $log -Append
    Start-Sleep $RestartDelaySeconds
}
