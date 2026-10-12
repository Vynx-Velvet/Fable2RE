#!/usr/bin/env python3
"""Per-area performance summary of one game session (native renderer build).

Splits the log at area changes (data\\audio\\atmos_<area>.bnk reads and Debug.LoadLevel
commands from the Lua bridge) and summarises, per area, the 5-second lines:
  native renderer perf: <fps> fps | per frame: wall, in hooks, GPU wait, texture decode, draws
  native renderer perf: renderer thread busy <ms> per frame: draw/clear/resolve/.../gpu-sync
  Thread CPU 5s ... | <thread> <pct>% ...
  native renderer hitch: frame N took / renderer ...

Usage: python tools/area_perf.py <fable2.log> [--from-line N] [--timeline]
  --from-line: start of the session (default: last "Game directory:" line)
"""
import re
import statistics
import sys
from collections import defaultdict

TS = re.compile(r'^\[(\d{4}-\d\d-\d\d (\d\d:\d\d:\d\d))\.\d+\]')
FPS = re.compile(r'native renderer perf: ([\d.]+) fps \| per frame: wall ([\d.]+) ms, in hooks ([\d.]+) ms, '
                 r'GPU wait ([\d.]+) ms.*?uploads (\d+) KB, texture decode ([\d.]+) ms.*?draws (\d+)')
BUSY = re.compile(r'renderer thread busy ([\d.]+) ms per frame: draw ([\d.]+) clear ([\d.]+) resolve ([\d.]+) '
                  r'const ([\d.]+) fetch ([\d.]+) shaders ([\d.]+) gpu-sync ([\d.]+) frame/other ([\d.]+)')
CPU = re.compile(r'Thread CPU 5s \(100% = one core, process total (\d+)%\): (.*)')
ATMOS = re.compile(r'atmos_([A-Za-z0-9_]+)\.bnk')
LOADLEVEL = re.compile(r"lua_bridge: \[site [^\]]*\] Debug\.LoadLevel\('[^']*', '([^']*)'")
HITCH = re.compile(r'native renderer hitch: frame \d+ (?:took ([\d.]+) ms but the renderer only|renderer ([\d.]+) ms)')


def pct(vals, p):
    vals = sorted(vals)
    if not vals:
        return float('nan')
    k = (len(vals) - 1) * p / 100
    lo = int(k)
    hi = min(lo + 1, len(vals) - 1)
    return vals[lo] + (vals[hi] - vals[lo]) * (k - lo)


def main(argv):
    path = argv[0]
    lines = open(path, encoding='utf-8', errors='replace').read().split('\n')
    start = 0
    if '--from-line' in argv:
        start = int(argv[argv.index('--from-line') + 1]) - 1
    else:
        for i, l in enumerate(lines):
            if 'Game directory:' in l:
                start = i
    area = 'boot/front end'
    order = [area]
    data = defaultdict(lambda: defaultdict(list))
    span = {}
    timeline = []
    for l in lines[start:]:
        m = TS.match(l)
        if not m:
            continue
        t = m.group(2)
        a = ATMOS.search(l) if 'File reads 5s' in l else None
        ll = LOADLEVEL.search(l)
        new = None
        if ll:
            new = 'LoadLevel ' + ll.group(1)
        elif a:
            new = a.group(1)
        if new and new != area and not (area.startswith('LoadLevel') and a):
            area = new
            order.append(area)
        elif new and area.startswith('LoadLevel') and a:
            # first atmos bank after a LoadLevel names the level
            area = f"{area} -> {a.group(1)}"
            order[-1] = area
        span.setdefault(area, [t, t])[1] = t
        d = data[area]
        if (m2 := FPS.search(l)):
            fps, wall, hooks, gpuw, up, dec, draws = map(float, m2.groups())
            d['fps'].append(fps); d['wall'].append(wall); d['hooks'].append(hooks)
            d['gpuwait'].append(gpuw); d['upload_kb'].append(up); d['decode'].append(dec); d['draws'].append(draws)
            timeline.append((t, area, fps, wall, draws, dec))
        elif (m2 := BUSY.search(l)):
            for k, v in zip(('busy', 'b_draw', 'b_clear', 'b_resolve', 'b_const', 'b_fetch', 'b_shaders',
                             'b_gpusync', 'b_other'), m2.groups()):
                d[k].append(float(v))
        elif (m2 := CPU.search(l)):
            d['proc_cpu'].append(float(m2.group(1)))
            for name, p in re.findall(r'\| ([^|]+?) (\d+)%', ' ' + m2.group(2)):
                d['cpu:' + re.sub(r' \([0-9A-F]+\)', '', name.strip())].append(float(p))
        elif (m2 := HITCH.search(l)):
            d['hitch_game' if m2.group(1) else 'hitch_render'].append(float(m2.group(1) or m2.group(2)))

    for area in order:
        d = data[area]
        if not d.get('fps'):
            continue
        n = len(d['fps'])
        print(f"== {area}  [{span[area][0]} - {span[area][1]}, {n} samples of 5 s]")
        print(f"   fps     median {statistics.median(d['fps']):5.1f}  p10 {pct(d['fps'], 10):5.1f}  "
              f"min {min(d['fps']):5.1f}  max {max(d['fps']):5.1f}")
        print(f"   frame   wall {statistics.median(d['wall']):5.1f} ms | in renderer hooks (game thread blocked) "
              f"{statistics.median(d['hooks']):5.1f} ms | GPU wait {statistics.median(d['gpuwait']):4.1f} ms")
        print(f"   draws/frame median {statistics.median(d['draws']):6.0f}  max {max(d['draws']):6.0f} | "
              f"texture decode {statistics.median(d['decode']):5.1f} ms/frame (max {max(d['decode']):5.1f}) | "
              f"uploads {statistics.median(d['upload_kb']):6.0f} KB/frame")
        if d.get('busy'):
            parts = ' '.join(f"{k[2:]} {statistics.median(d[k]):.1f}" for k in
                             ('b_draw', 'b_clear', 'b_resolve', 'b_const', 'b_fetch', 'b_shaders', 'b_gpusync', 'b_other'))
            print(f"   renderer thread busy {statistics.median(d['busy']):5.1f} ms/frame: {parts}")
        cpus = sorted(((statistics.median(v), k[4:]) for k, v in d.items() if k.startswith('cpu:')), reverse=True)[:5]
        if cpus:
            print(f"   CPU (median % of one core, process {statistics.median(d['proc_cpu']):.0f}%): " +
                  ', '.join(f"{name} {v:.0f}" for v, name in cpus))
        hg, hr = d.get('hitch_game', []), d.get('hitch_render', [])
        if hg or hr:
            print(f"   hitches: {len(hg)} game-side (max {max(hg) if hg else 0:.0f} ms), "
                  f"{len(hr)} renderer-side (max {max(hr) if hr else 0:.0f} ms)")
    if '--timeline' in argv:
        for row in timeline:
            print('%s %-40s fps %5.1f wall %5.1f draws %5.0f decode %5.1f' % row)


if __name__ == '__main__':
    main(sys.argv[1:])
