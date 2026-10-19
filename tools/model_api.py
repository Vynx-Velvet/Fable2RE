"""Request options shared by the tools that call a model over the OpenAI chat-completions protocol
(tools/rewrite/run_api.py, tools/rewrite/review_api.py, tools/naming/run_local.py).

--effort sets how much the model thinks before it answers. DeepSeek's models think by default, at high effort,
and the hidden reasoning is billed as output: in the 2026-10-16/17 rewrite round about 95% of the output tokens
paid for were reasoning, not code. The fields (api-docs.deepseek.com, Thinking Mode, read 2026-10-17):

    none            {"thinking": {"type": "disabled"}}
    low, high, max  {"thinking": {"type": "enabled"}, "reasoning_effort": <effort>}

Without --effort nothing is sent and the provider's default applies (DeepSeek: thinking, high effort). Without
thinking, DeepSeek limits an answer to 8K tokens unless the request asks for more, which a long function can
exceed: with --effort none the tools ask for NO_THINKING_LIMIT unless --max-tokens names a limit. Thinking mode
ignores the temperature; without thinking the tools' temperature applies.

The token counts (count, describe) add the reasoning tokens and the prompt tokens served from the provider's
context cache (much cheaper than the rest) when the provider reports them.
"""
EFFORTS = ('none', 'low', 'high', 'max')
NO_THINKING_LIMIT = 32768


def add_effort_arg(ap):
    ap.add_argument('--effort', choices=EFFORTS,
                    help='how much the model thinks before answering (none: no thinking; default: the '
                         'provider\'s own, for DeepSeek high)')


def effort_fields(effort):
    """The request fields for a thinking effort (None: none, the provider's default applies)."""
    if not effort:
        return {}
    if effort == 'none':
        return {'thinking': {'type': 'disabled'}}
    return {'thinking': {'type': 'enabled'}, 'reasoning_effort': effort}


def output_limit(effort, max_tokens=0):
    """The max_tokens to send (0: none, the provider's own limit applies)."""
    return max_tokens or (NO_THINKING_LIMIT if effort == 'none' else 0)


def request_fields(effort, max_tokens=0):
    """effort_fields plus max_tokens where one applies."""
    fields = effort_fields(effort)
    limit = output_limit(effort, max_tokens)
    if limit:
        fields['max_tokens'] = limit
    return fields


def count(totals, usage):
    """Adds a reply's usage to totals (prompt, cached, completion, reasoning, requests; missing keys start at 0)."""
    usage = usage or {}
    cached = usage.get('prompt_cache_hit_tokens', (usage.get('prompt_tokens_details') or {}).get('cached_tokens', 0))
    for k, v in (('prompt', usage.get('prompt_tokens', 0)), ('cached', cached or 0),
                 ('completion', usage.get('completion_tokens', 0)),
                 ('reasoning', (usage.get('completion_tokens_details') or {}).get('reasoning_tokens', 0) or 0),
                 ('requests', 1)):
        totals[k] = totals.get(k, 0) + v


def describe(totals):
    """'P in (C cached) / O out (R reasoning) in N requests', the parts the provider reported."""
    t = lambda k: f'{totals.get(k, 0):,}'
    return (f'{t("prompt")} in' + (f' ({t("cached")} cached)' if totals.get('cached') else '') +
            f' / {t("completion")} out' + (f' ({t("reasoning")} reasoning)' if totals.get('reasoning') else '') +
            f' in {t("requests")} requests')
