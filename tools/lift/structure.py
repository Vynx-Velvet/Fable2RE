"""Turns gotos into if / else / while / do-while in a lifted function's item list (emit.py).

Compiled code is laid out in mostly structured order, so a few patterns recover the source
structure; whatever does not match stays a goto (legal C++ here: every local variable is declared
at the top of the function).

  if (c) goto L; A... L:                       ->  if (!c) { A }
  if (c) goto L1; A... goto L2; L1: B... L2:   ->  if (!c) { A } else { B }
  L: A... if (c) goto L;                       ->  do { A } while (c);
  L: if (c) goto E; A... goto L; E:            ->  while (!c) { A }
  L: A... goto L;                              ->  for (;;) { A }
  goto L  where L: is just "return"            ->  the return itself
Inside loops, gotos to the loop head become `continue` (while/for) and gotos to the label after
the loop become `break`.
"""
from cparse import Goto, If, Return, Unary, Binary, Name, Member, Call, walk, Switch
from passes import _sobj

_NEG = {'<': '>=', '>': '<=', '==': '!=', '!=': '==', '<=': '>', '>=': '<'}


def _is_float_expr(e):
    for x in walk(e):
        if type(x) is Name and len(x.id) > 1 and x.id[0] == 'f' and x.id[1:].isdigit():
            return True
        if type(x) is Call and type(x.func) is Name and x.func.id in ('double', 'float'):
            return True
    return False


def negate(c):
    if type(c) is Unary and c.op == '!':
        return c.x
    if type(c) is Binary and c.op in ('==', '!='):
        return Binary(_NEG[c.op], c.a, c.b)
    if type(c) is Binary and c.op in _NEG and not _is_float_expr(c):
        return Binary(_NEG[c.op], c.a, c.b)
    if type(c) is Binary and c.op == '&&':
        return Binary('||', negate(c.a), negate(c.b))
    if type(c) is Binary and c.op == '||':
        return Binary('&&', negate(c.a), negate(c.b))
    return Unary('!', c)


# ---------------------------------------------------------------------------------------------

def _goto_of(it):
    """(cond or None, label) for goto items."""
    if it[0] == 'stmt':
        st = it[1]
        if type(st) is Goto:
            return None, st.label
        if type(st) is If and type(st.body) is Goto:
            return st.cond, st.body.label
    return None


def _refs(items, acc=None):
    """label -> number of gotos referencing it (anywhere in items, nested too)."""
    if acc is None:
        acc = {}
    for it in items:
        g = _goto_of(it)
        if g:
            acc[g[1]] = acc.get(g[1], 0) + 1
        k = it[0]
        if k == 'stmt' and type(it[1]) is Switch:
            for _, l in it[1].cases:
                acc[l] = acc.get(l, 0) + 1
            if it[1].default is not None and type(it[1].default) is Goto:
                acc[it[1].default.label] = acc.get(it[1].default.label, 0) + 1
        for sub in _children(it):
            _refs(sub, acc)
    return acc


def _children(it):
    k = it[0]
    if k == 'if':
        return [it[2]]
    if k == 'ifelse':
        return [it[2], it[3]]
    if k in ('dowhile', 'while', 'loop'):
        return [it[2]]
    return []


def _labels_in(items):
    out = set()
    for it in items:
        if it[0] == 'label':
            out.add(it[1])
        for sub in _children(it):
            out |= _labels_in(sub)
    return out


def _refs_from(items):
    return _refs(items, {})


def _terminates(items):
    """Does control never fall off the end of this list?"""
    for it in reversed(items):
        if it[0] in ('asm',):
            continue
        if it[0] == 'ret':
            return True
        if it[0] == 'stmt' and type(it[1]) is Goto:
            return True
        if it[0] in ('break', 'continue'):
            return True
        return False
    return False


def _return_tail(items, k):
    """If the code at label index k is only write-backs and a return, those items."""
    out = []
    j = k + 1
    while j < len(items):
        it = items[j]
        if it[0] in ('flush', 'asm'):
            out.append(it)
            j += 1
            continue
        if it[0] == 'ret':
            out.append(it)
            return out
        return None
    return None


def structure(items):
    _tail_returns(items)
    _structure_list(items)
    _drop_unused_labels(items)
    return items


def _tail_returns(items):
    pos = {it[1]: i for i, it in enumerate(items) if it[0] == 'label'}
    tails = {}
    for l, k in pos.items():
        t = _return_tail(items, k)
        if t is not None and len([x for x in t if x[0] == 'flush']) <= 1:
            tails[l] = t
    if not tails:
        return

    def rewrite(lst):
        out = []
        for it in lst:
            g = _goto_of(it)
            if g and g[1] in tails:
                cond, l = g
                body = [x for x in tails[l] if x[0] != 'asm']
                if cond is None:
                    out.extend(body)
                else:
                    out.append(('if', cond, list(body)) + tuple(it[2:]))
                continue
            for sub in _children(it):
                sub[:] = rewrite(sub)
            out.append(it)
        return out
    items[:] = rewrite(items)


def _drop_unused_labels(items, refs=None):
    if refs is None:
        refs = _refs(items)
    items[:] = [it for it in items if not (it[0] == 'label' and not refs.get(it[1]))]
    for it in items:
        for sub in _children(it):
            _drop_unused_labels(sub, refs)


def _structure_list(items):
    changed = True
    while changed:
        changed = False
        refs = _refs(items)
        pos = {it[1]: i for i, it in enumerate(items) if it[0] == 'label'}
        for i, it in enumerate(items):
            g = _goto_of(it)
            if not g:
                continue
            cond, L = g
            k = pos.get(L)
            if k is None:
                continue
            if k > i and cond is not None:
                if _try_if(items, i, k, cond, L, refs, pos):
                    changed = True
                    break
            elif k < i:
                if _try_loop(items, k, i, cond, L, refs, pos):
                    changed = True
                    break
    for it in items:
        for sub in _children(it):
            _structure_list(sub)


def _inner_ok(items, a, b, refs):
    """No label inside items[a:b] is the target of a goto from outside that range."""
    inner = items[a:b]
    inside_refs = _refs_from(inner)
    for l in _labels_in(inner):
        if refs.get(l, 0) != inside_refs.get(l, 0):
            return False
    return True


def _try_if(items, i, k, cond, L, refs, pos):
    # if (cond) goto L; A (items i+1..k-1); L:
    if not _inner_ok(items, i + 1, k, refs):
        return False
    then = items[i + 1:k]
    # else form: A ends with 'goto L2' (L2 after L) and B = items k+1 .. pos[L2]-1
    last = next((x for x in reversed(then) if x[0] != 'asm'), None)
    g2 = _goto_of(last) if last else None
    if g2 and g2[0] is None and g2[1] in pos and pos[g2[1]] > k and refs.get(L, 0) == 1:
        L2 = g2[1]
        m = pos[L2]
        if _inner_ok(items, k + 1, m, refs):
            then_items = [x for x in then if x is not last]
            else_items = items[k + 1:m]
            new = ('ifelse', negate(cond), then_items, else_items)
            label_keep = [] if refs.get(L, 0) == 1 else [items[k]]
            items[i:m] = [new] + label_keep
            return True
    new = ('if', negate(cond), then)
    items[i:k] = [new]
    return True


def _try_loop(items, k, i, cond, L, refs, pos):
    # L: (items k) ... goto L (item i)
    body = items[k + 1:i]
    if not _inner_ok(items, k + 1, i, refs):
        return False
    other = refs.get(L, 0) - 1 - _refs_from(body).get(L, 0)
    if other:
        return False  # jumped to from outside the loop too
    exit_label = items[i + 1][1] if i + 1 < len(items) and items[i + 1][0] == 'label' else None
    # (inner structure first, so break/continue below bind to this loop)
    if cond is not None:
        new_body = list(body)
        _structure_list(new_body)
        _breaks(new_body, exit_label, None)  # (no continue in do-while: it would skip to the condition)
        new = ('dowhile', cond, new_body)
    else:
        first = next((j for j, x in enumerate(body) if x[0] != 'asm'), None)
        g = _goto_of(body[first]) if first is not None else None
        if g and g[0] is not None and exit_label is not None and g[1] == exit_label:
            wbody = body[first + 1:]
            _structure_list(wbody)
            _breaks(wbody, exit_label, L)
            new = ('while', negate(g[0]), wbody)
        else:
            lbody = list(body)
            _structure_list(lbody)
            _breaks(lbody, exit_label, L)
            new = ('loop', None, lbody)
    items[k:i + 1] = [items[k], new]
    return True


def _breaks(items, exit_label, head_label):
    """Gotos to the loop exit -> break, to the loop head -> continue (not inside nested loops)."""
    for j, it in enumerate(items):
        g = _goto_of(it)
        if g:
            cond, l = g
            repl = None
            if exit_label is not None and l == exit_label:
                repl = ('break',)
            elif head_label is not None and l == head_label:
                repl = ('continue',)
            if repl:
                items[j] = repl if cond is None else ('if', cond, [repl])
                continue
        if it[0] in ('if', 'ifelse'):
            for sub in _children(it):
                _breaks(sub, exit_label, head_label)
