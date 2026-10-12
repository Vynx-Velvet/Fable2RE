# Publishing progress

`tools/publish.py` puts the project's progress into the hosted repository in one command, with every check the
initial commit went through. Progress means what may be published and grows between sessions:

- research data under `research/`: the naming dictionary, the catalog, findings, and the shipped analysis, class
  model and verification manifest (`research/lift/`)
- documentation under `docs/`
- promoted modules (`Fable2Recomp/src/game/promoted/`) whose every function has an OK record in `REVIEW.tsv`
  ([promoted code](promoted-code.md)). Modules not fully reviewed are listed as held back.

Changes anywhere else (tools, runtime code, the SDK patch) are listed and left out: commit those yourself, with a
message that explains them. Game-derived files never qualify ([contributing](../CONTRIBUTING.md)).

## Commands

```powershell
python tools/publish.py                    # what would be published, the commit message and every check
python tools/publish.py --refresh          # first export the verification manifest and the class model again
python tools/publish.py --commit           # commit on main, locally
python tools/publish.py --publish          # commit, push, wait for CI, move main
python tools/publish.py --publish --no-merge
```

Without `--commit` or `--publish` nothing is committed: the script stages the progress, runs the checks, prints
the message and puts the index back as it was.

`--publish` pushes the commit to a `progress/<date>` branch and opens a pull request (GitHub CLI `gh`). It waits
for the CI on that pull request and, when it passes, moves `main` to the commit as a fast-forward: no merge commit,
and GitHub shows the pull request as merged. When the CI fails, `main` stays where it was and the pull request
stays open; fix the problem and run `--publish` again (the earlier commit goes along). `--no-merge` leaves the pull
request open for review: merge it on GitHub with **Create a merge commit**, then `git pull`.

`--note TEXT` adds a paragraph to the commit message; `--trailer LINE` adds a trailer such as `Co-Authored-By:`.
The message summarises the change: names added and renamed per dictionary file, promoted modules and their
functions, the manifest's verified count, the class model, new findings by title.

## Checks

All must pass before a commit.

| Check | What it guards |
|---|---|
| Commit identity, staged changes | None of the strings in `.git/info/publish-private` (one per line: your e-mail addresses, names, machine paths; case and slash direction ignored). The file lives in `.git` and is never committed. |
| Branch | `main`, not behind `origin/main` (unpushed local commits go along) |
| `tools/validate_metadata.py` | the dictionary and catalog formats |
| `tools/validate_commit.py` | game material, user folders (`C:\Users\<name>`, `/home/<name>`), promoted modules without review records, the SDK submodule at its release |
| `git diff --check` | whitespace |
| Unit tests | `tools/tests`, `tools/test_commit_validation.py` |
| `tools/sdk_patch.py status` | the SDK working tree matches `patches/rexglue-sdk.patch` |
| `tools/lift/bundle.py check` | the shipped analysis fits this `default.xex` (when there is one) |
| `classes.py --verify` | the shipped class model is the one in `tools/lift/cache/classes.json` |
| `make_skip.py --manifest` | every function the manifest records lifts here to exactly the tested text |

The last two run only on a machine with a lift. They keep the shipped model and manifest a pair that a new setup
reproduces ([lifted code](lifted-code.md#the-shipped-class-model)). When either is published, a mismatch fails;
when both are published unchanged, it is a warning: run the tester, then publish with `--refresh`.

## After a class-model refresh

A refresh of the class model on the development machine (`setup_all.ps1 -From classes -To build -Tested tester`,
overnight) changes the lifted text of many functions. When it has lifted and tested,
`python tools/publish.py --refresh --publish` exports the manifest from the tester results and the model from the
facts, checks that both match this lift, and publishes them together.
