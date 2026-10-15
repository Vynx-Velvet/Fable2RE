# Naming pipeline

Produces the naming dictionary (`research/names/`) with a language model of your choice. The pipeline is
file-based: it writes prompt files and reads answer files, so any model or service can do the naming.

```
python tools/naming/make_batches.py --limit 2000        # prompts -> build/naming/batches/batch_NNNN.md
python tools/naming/run_local.py --model <name>           # a local model answers -> build/naming/answers/
python tools/naming/merge.py --dry-run                   # check the answers
python tools/naming/merge.py                             # add them to research/names/*.tsv
python tools/validate_metadata.py                        # public schema, keys, names, and JSON/gzip checks
python tools/lift/names.py                               # validate the dictionary
python tools/lift/apply_names.py                        # re-lift only what the new names affect
powershell -File tools/lift/update.ps1 -Build            # test those functions, compile only their files
```

Two ways to have a model answer the batches:
- **An agent CLI** (for example a Claude CLI pointed at an OpenRouter model): give it `tools/naming/AGENT.md` as
  its task. It loops over `next_batch.py`, reads each batch and writes the answer file.
- **Direct API calls**, one request per batch, no agent overhead: `run_local.py` with a local server, or
  `run_local.py --url https://openrouter.ai/api/v1 --allow-remote --model <provider/model>` with the key stored
  once by `python tools/api_keys.py set openrouter` (without a stored key: `OPENROUTER_API_KEY`); for DeepSeek,
  `--url https://api.deepseek.com` and `set deepseek`. See [API keys](../../docs/parallel-work.md#api-keys).

- One batch is about 6,000 tokens of input (`--tokens`); the answer is a few lines per function.
- Work in rounds. `make_batches.py` offers functions bottom-up (functions whose callees are already named
  first, best-connected first); after `merge.py` the next round sees the new names. `--anchors-only` limits
  a round to functions called from already named code, where names are most reliable.
- The prompt (in `make_batches.py`, `PROMPT`) asks for tab-separated lines: `F address name confidence basis`
  for functions, `C` for classes, `M` for fields. `merge.py` rejects malformed lines, invalid or duplicate
  identifiers, unknown addresses, and answers that would replace an entry of equal or higher confidence;
  see `build/naming/rejected.txt`.
- Applying names is incremental (`tools/lift/apply_names.py`): a function name re-lifts that function and its
  callers; a class or field name re-lifts the methods of that class. Each lifted file carries the prototypes
  and struct definitions it uses, so only those files recompile. `--dry-run` shows the size of a change.
- A wrong name cannot break the build or the game: names are labels (`tools/lift/names.py`), the generated
  code is the same and is tested as before. A bad name only misleads readers; fix it by editing the TSV.
- The batches contain lifted game code. They stay in `build/` (not committed). With a hosted model (an agent
  CLI on OpenRouter, or `run_local.py --allow-remote`) that code is sent to the provider; with a server on
  this machine it does not leave it. Both paths skip batches that already have an answer.
- Only the dictionary is published. Its `basis` column must be a plain sentence, never code.
