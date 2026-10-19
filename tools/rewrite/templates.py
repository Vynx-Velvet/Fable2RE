"""Readable rewrites of whole families of small functions, written from one reviewed template each.

Some families of the game's functions are hundreds or thousands of copies of one tiny shape that differs only in
its values (a string, a global's address). For such a family a template is reviewed once and each member's
rewrite is written from the member's own lifted code: the lifted text has to have the family's shape exactly
(values abstracted), or the member is left out. Every rewrite then takes the strict check like any model answer
(tools/rewrite/check.py --outputs, profiles 0-5) and is promoted the usual way (apply.py, promote.py build).

Families:

  name-hash   start-up functions that hash one name and keep the hash in a global:
              FNV-1 (String_HashFnv1 from the FNV offset basis; Fable2Recomp/lifted/readable_support.h
              HashNameFnv1) or String_HashLimited100 (stored with or without its top bit)
                  uint64_t HashName_<Name>(CpuState& ctx, uint8_t* base) {
                      GameStackFrame stackFrame(ctx, base, 96);
                      uint64_t hash = HashNameFnv1(ctx, base, str_<Name>);
                      STORE32(g_HashOf_<Name>, (uint32_t)hash);
                      return hash;
                  }
              <Name> is the lifter's name of the string constant (the game's text: the published modules hold
              a reference instead, tools/rewrite/promoted_text.py)

    python tools/rewrite/templates.py name-hash [--limit N]      answers -> build/rewrite/answers/template_<family>/
Then: python tools/rewrite/check.py --dir build/rewrite/answers/template_<family> --outputs --profiles 0,1,2,3,4,5
"""
import argparse
import collections
import glob
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import promote  # noqa: E402
import promoted_text  # noqa: E402

ANSWERS = os.path.join(ROOT, 'build', 'rewrite', 'answers')


def lifted_blocks():
    out = {}
    for f in glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'lifted.*.cpp')):
        for b in open(f, encoding='utf-8').read().split('// @lift ')[1:]:
            n = b.split('\n', 1)[0].strip()
            if re.fullmatch(r'sub_[0-9A-F]{8}', n):
                out[n] = b.split('\n', 1)[1]
    return out


def code(block):
    """The lifted function's lines without comments and blank lines."""
    return [re.sub(r'\s*//.*$', '', l) for l in block.split('\n') if l.strip() and not l.lstrip().startswith('//')]


FNV = [r'uint64_t n_(sub_[0-9A-F]{8})\(CpuState& ctx, uint8_t\* base\) \{',
       r'\tconstexpr int32_t (str_\w+) = int32_t\((0x[0-9A-F]{8})\);',
       r'\t(if \(!UseLiftedCode\(\d+, 0x[0-9A-F]{8}\)\) \{ sub_[0-9A-F]{8}_original\(ctx, base\); return ctx\.r3\.u64; \})',
       r'\t(LiftedFrame frame\(0x[0-9A-F]{8}\);)',
       r'\tuint32_t stack = ctx\.r1\.u32;',
       r'\tuint64_t (\w+)\{\};', r'\tuint64_t (\w+)\{\};', r'\tuint64_t (\w+)\{\};',
       r'\tstack = PushStackFrame\(base, stack, (\d+)\);',
       r'\t(\w+) = -2128871424;',
       r'\t(\w+) = (str_\w+);',
       r'\t(\w+) = \1 \| 40389;'.replace(r'\1', r'(\w+)'),
       r'\tctx\.r1\.u64 = stack;',
       r'\t(\w+) = String_HashFnv1\(ctx, base, (\w+), (\w+)\);',
       r'\tSTORE32\((0x[0-9A-F]{8})u, \(uint32_t\)(\w+)\);',
       r'\tstack = PopStackFrame\(stack, \d+\);',
       r'\tctx\.r1\.u64 = stack;',
       r'\tctx\.r4\.u64 = (\w+);',
       r'\treturn (\w+);', r'\}',
       r'CPU_STATE_ENTRY\((sub_[0-9A-F]{8}), (0x[0-9A-F]{8})\) \{ ctx\.r3\.u64 = n_sub_[0-9A-F]{8}\(ctx, base\); \}']
LIMITED = [FNV[0], FNV[1], FNV[2], FNV[3], FNV[4], r'\tuint64_t (\w+)\{\};', r'\tuint64_t (\w+)\{\};', FNV[8],
           r'\t(\w+) = (str_\w+);', FNV[12],
           r'\t(\w+) = String_HashLimited100\(ctx, base, (\w+)\);',
           r'\tSTORE32\((0x[0-9A-F]{8})u, (uint32_t\(\(uint32_t\)(\w+) & 0x7FFFFFFF\)|\(uint32_t\)(\w+))\);',
           FNV[15], FNV[16], FNV[18], FNV[19], FNV[20]]


def match(lines, pattern):
    """The groups of every line when the lines are the pattern exactly, else None."""
    if len(lines) != len(pattern):
        return None
    groups = []
    for line, p in zip(lines, pattern):
        m = re.fullmatch(p, line)
        if not m:
            return None
        groups.append(m.groups())
    return groups


def name_hash(n, block):
    """(name stem, rewrite text) of one member of the name-hash family, or None."""
    lines = code(block)
    g = match(lines, FNV)
    if g:
        strname, addr = g[1]
        uselifted, frameline, size = g[2][0], g[3][0], g[8][0]
        seed_var, (text_var, text_const), store, ret = g[9][0], g[10], g[14][0], g[18][0]
        call_text, call_seed, result = g[13][1], g[13][2], g[13][0]
        if not (text_const == strname and call_text == text_var and call_seed == seed_var and g[11][0] == seed_var
                and g[14][1] == result and ret == result and g[17][0] == seed_var):
            return None
        hash_line = f'\tuint64_t hash = HashNameFnv1(ctx, base, {strname});'
        store_line = '(uint32_t)hash'
    else:
        g = match(lines, LIMITED)
        if not g:
            return None
        strname, addr = g[1]
        uselifted, frameline, size = g[2][0], g[3][0], g[7][0]
        text_var, text_const = g[8]
        result, call_text = g[10]
        store, expr, masked_var, plain_var = g[11]
        if not (text_const == strname and call_text == text_var and g[14][0] == result
                and (masked_var or plain_var) == result):
            return None
        hash_line = f'\tuint64_t hash = String_HashLimited100(ctx, base, {strname});'
        store_line = 'uint32_t((uint32_t)hash & 0x7FFFFFFF)' if masked_var else '(uint32_t)hash'
    stem = strname[4:]
    entry = g[-1]
    text = '\n'.join([
        f'uint64_t HashName_{stem}(CpuState& ctx, uint8_t* base) {{',
        f'\tconstexpr int32_t {strname} = int32_t({addr});',
        f'\tconstexpr uint32_t g_HashOf_{stem} = {store}u;',
        f'\t{uselifted}',
        f'\t{frameline}',
        f'\tGameStackFrame stackFrame(ctx, base, {size});',
        hash_line,
        f'\tSTORE32(g_HashOf_{stem}, {store_line});',
        '\treturn hash;',
        '}',
        f'CPU_STATE_ENTRY({entry[0]}, {entry[1]}) {{ ctx.r3.u64 = HashName_{stem}(ctx, base); }}'])
    return stem, text


_RANGES = None


def lifted_named(n, block):
    """The lifter's own exact text with the mechanical readable form (tools/rewrite/readable_form.py), when that is
    readable C++ with every name (tools/rewrite/readability.py on its published form), or None. The names come from
    the dictionary (research/names), applied to the lifted code by tools/lift/apply_names.py."""
    import readability
    import readable_form
    global _RANGES
    if _RANGES is None:
        import scope
        _RANGES = [(lo, hi) for lo, hi, area, _ in scope.ranges() if area in ('game', 'game-static')]
    a = int(n[4:], 16)
    if not any(lo <= a < hi for lo, hi in _RANGES):
        return None   # (Lionhead's code only: libraries are to be replaced, not reconstructed)
    lines = block.split('\n')
    text = '\n'.join(l for l in lines if not l.startswith('// '))
    new, _ = readable_form.transform(n, text, {})
    form = promote.module_form(n, new)
    try:
        pub = promoted_text.encode(form)
    except promoted_text.TextError:
        return None
    fs = readability.functions(pub)
    if len(fs) != 1 or readability.level(readability.issues(fs[0][1], fs[0][2])) != 'named':
        return None
    return None, new


FAMILIES = {'name-hash': name_hash, 'lifted-named': lifted_named}


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('family', choices=sorted(FAMILIES))
    ap.add_argument('--limit', type=int, default=0)
    a = ap.parse_args()
    promoted = set(promote.module_functions())
    taken = set(re.findall(r'\b[A-Za-z_]\w*\b', ' '.join(
        promote.DEF_RE.search(t).group(1) for _, t in promote.module_functions().values() if promote.DEF_RE.search(t))))
    taken |= promoted_text.dictionary_names()
    made, skipped = {}, collections.Counter()
    for n, block in sorted(lifted_blocks().items()):
        if n in promoted:
            continue
        r = FAMILIES[a.family](n, block)
        if not r:
            continue
        stem, text = r
        if stem is None:   # (the function keeps the name it has)
            made[n] = text
            if a.limit and len(made) >= a.limit:
                break
            continue
        name = f'HashName_{stem}'
        k = 2
        while name in taken:   # (a second function for the same name: numbered)
            name = f'HashName_{stem}_{k}'
            k += 1
        text = text.replace(f'HashName_{stem}(', f'{name}(').replace(f'g_HashOf_{stem} ', f'g_HashOf_{name[9:]} ') \
                   .replace(f'g_HashOf_{stem},', f'g_HashOf_{name[9:]},')
        try:   # (the published form must hold the name as a reference: refused names are left out)
            check = promoted_text.encode(promote.module_form(n, text))
            if promoted_text.leftovers(check):
                raise promoted_text.TextError('leftover text')
        except promoted_text.TextError:
            skipped['name not publishable'] += 1
            continue
        taken.add(name)
        made[n] = text
        if a.limit and len(made) >= a.limit:
            break
    out = os.path.join(ANSWERS, f'template_{a.family.replace("-", "")}')
    shutil.rmtree(out, ignore_errors=True)
    os.makedirs(out)
    for n, text in made.items():
        with open(os.path.join(out, n + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
            f.write(text + '\n')
    print(f'{len(made)} rewrites -> {os.path.relpath(out, ROOT)}; skipped: {dict(skipped)}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
