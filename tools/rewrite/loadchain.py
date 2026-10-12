"""Depth of the deepest chain of dependent memory loads in a function's text.

A chain is a load whose address comes from another load: LOAD32(LOAD32(p + 88) + 4) is two deep, and so is
    mgr = LOAD32(p + 88);  list = LOAD32(mgr + 4);
through the variable. A typed field access obj->m_X counts as a load through the address obj was made from
(`T* obj = GameObject<T>(base, addr)`). Both rewrite mistakes found in the game so far collapsed such a chain
by one load, on paths the synthetic tests did not reach; the rewrite's deepest chain must be at least as deep
as the lifted code's (tools/rewrite/check.py).
"""
import re

_LOAD = re.compile(r'\b(?:LOAD(?:8|16|32|64|_F32|_F64)|GameObject<[\w:]+>)\s*\(')
_IDENT = re.compile(r'\b[A-Za-z_]\w*\b')
_ASSIGN = re.compile(r'^\s*(?:[\w:<>]+\*?\s+)?(\w+)\s*=\s*(.+);\s*(?://.*)?$')
_VIEW = re.compile(r'^\s*[\w:]+\*\s+(\w+)\s*=\s*GameObject<[\w:]+>\s*\(\s*base\s*,\s*(.+)\)\s*;')


def _strip_comments(text):
    text = re.sub(r'//[^\n]*', '', text)
    return re.sub(r'/\*.*?\*/', '', text, flags=re.S)


def _balanced(s, start):
    """Index just past the ')' matching the '(' at s[start]."""
    depth = 0
    for i in range(start, len(s)):
        if s[i] == '(':
            depth += 1
        elif s[i] == ')':
            depth -= 1
            if depth == 0:
                return i + 1
    return len(s)


class Chains:
    def __init__(self):
        self.var = {}    # variable -> depth of the load chain its value comes from

    def expr(self, e):
        """Depth of the deepest load chain inside an expression."""
        best = 0
        pos = 0
        while True:
            m = _LOAD.search(e, pos)
            if m is None:
                break
            end = _balanced(e, m.end() - 1)
            inner = e[m.end():end - 1]
            if m.group(0).startswith('GameObject'):
                inner = inner.split(',', 1)[1] if ',' in inner else inner
            best = max(best, 1 + self.expr(inner))
            pos = end
        # variables in the expression (outside the loads already counted the loads' own variables too, fine)
        for w in _IDENT.findall(e):
            d = self.var.get(w)
            if d:
                best = max(best, d)
        return best

    def member(self, e):
        """obj->m_X accesses: one load through obj."""
        best = 0
        for m in re.finditer(r'\b(\w+)\s*->\s*m_\w+', e):
            best = max(best, 1 + self.var.get(m.group(1), 0))
        return best


def deepest(text):
    c = Chains()
    best = 0
    for line in _strip_comments(text).split('\n'):
        m = _VIEW.match(line)
        if m:
            c.var[m.group(1)] = c.expr(m.group(2))
            continue
        d = max(c.expr(line), c.member(line))
        best = max(best, d)
        a = _ASSIGN.match(line)
        if a and 'GameObject<' not in line:
            c.var[a.group(1)] = max(c.var.get(a.group(1), 0), d) if a.group(1) in c.var else d
    return best


if __name__ == '__main__':
    import sys
    for p in sys.argv[1:]:
        print(p, deepest(open(p, encoding='utf-8', errors='replace').read()))
