"""Check staged paths and source dependencies before a commit.

Reads the Git index of this repository (the runtime lives in Fable2Recomp/) and of the initialized rexglue-sdk
submodule, which must stay at the public ReXGlue release patches/rexglue-sdk.patch is made for
(tools/sdk_patch.py). This is a packaging check, not a copyright/provenance audit or proof of build
reproducibility.
"""
import subprocess
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
RUNTIME = "Fable2Recomp/"   # the runtime tree (a folder of this repository since 2026-10-11, before: a submodule)
REQUIRED = {
    ".": {RUNTIME + p for p in ("lifted/lifted.h", "sdk/include/fable2/sdk.h",
                                "sdk/include/fable2/mod_api.h", "sdk/include/fable2/verify.h")},
}


def sdk_base():
    """The public ReXGlue commit the rexglue-sdk submodule must point at (tools/sdk_patch.py BASE)."""
    m = re.search(r"^BASE = '([0-9a-f]{40})'", (ROOT / "tools" / "sdk_patch.py").read_text(encoding="utf-8"), re.M)
    return m.group(1) if m else None


def runtime_path(label, path):
    """The path inside the runtime tree, or None for paths outside it."""
    if label == "Fable2Recomp":
        return path
    if label == "." and path.startswith(RUNTIME):
        return path[len(RUNTIME):]
    return None
BLOCKED_SUFFIXES = {".iso", ".xex", ".bnk", ".dmp", ".exe", ".dll", ".pdb"}
# Game data formats and decompiler output: refused anywhere in the tree.
DERIVED_SUFFIXES = {".babel": "game text (book.babel)", ".vfsconfig": "game data configuration",
                    ".src.lua": "decompiled game script (bnk.py --decompile output)"}
# A mod folder's top level holds authored files (README, tuning.toml, plugin sources). Below it, every
# folder but native/ mirrors the user's game (tools/mods.py): data/ = loose data files, text/ =
# exported game text lines, any other name = files inside data/<name>.bnk (decompiled scripts).
MOD_AUTHORED_FOLDERS = {"native"}


def mod_material(path):
    """Why a staged path holds game-derived material, or None."""
    lower = path.lower()
    for suffix, what in DERIVED_SUFFIXES.items():
        if lower.endswith(suffix):
            return what
    parts = lower.split("/")
    if parts[0] != "mods" or len(parts) < 4 or parts[2] in MOD_AUTHORED_FOLDERS:
        return None
    if parts[2] == "data":
        return "game data file in a mod (mods/<Mod>/data/)"
    if parts[2] == "text":
        return "exported game text in a mod (mods/<Mod>/text/)"
    return f"file inside the game's {parts[2]}.bnk in a mod (decompiled or modified game script)"


def git(repo, *args):
    return subprocess.check_output(["git", "-C", str(repo), *args], text=True, encoding="utf-8")


PROMOTED = "src/game/promoted/"
PROMOTED_REVIEW = PROMOTED + "REVIEW.tsv"
PROMOTED_HEADERS = ("Promoted from model rewrites", "Promoted from verified model rewrites")
ENTRY = re.compile(r"^PROMOTED_ENTRY\(\d+, (sub_[0-9A-F]{8}), 0x[0-9A-F]{8}\)", re.M)
DECOMPILER_NAMES = re.compile(r"\b(?:uVar\d+|iVar\d+|puVar\d+|undefined\d?|param_\d+|in_r\d+|extraout_\w+)\b")
# Names the lifter makes from the game's own text (tools/lift/readable.py): a string constant after its text
# (str_PieceName; the address form str_820E0F10 is fine) and a global after the text it is built from (the
# local table research/decomp/global_names.tsv). Game text stays out of the repository (2026-10-12).
TEXT_CONSTANT_NAME = re.compile(r"\bstr_[A-Za-z]\w*")
GLOBAL_NAME = re.compile(r"\bg_\w+")
_TEXT_GLOBALS = None


def text_global_names():
    """Names in the local table of globals named after game text (empty without it)."""
    global _TEXT_GLOBALS
    if _TEXT_GLOBALS is None:
        table = ROOT / "research" / "decomp" / "global_names.tsv"
        _TEXT_GLOBALS = set()
        if table.is_file():
            for line in table.read_text(encoding="utf-8").splitlines()[1:]:
                cells = line.split("\t")
                if len(cells) > 1 and not re.fullmatch(r"g_[0-9A-F]{8}", cells[1]):
                    _TEXT_GLOBALS.add(cells[1])
    return _TEXT_GLOBALS


def promoted_problems(path, text, reviewed):
    """Content rules for a promoted module (docs/promoted-code.md): provenance header, no quoted game text and no
    names made from it, no lifter markers or decompiler output, and an OK review record for every function."""
    errors = []
    if not any(h in text for h in PROMOTED_HEADERS):
        errors.append(f"{path}: provenance header missing")
    for number, line in enumerate(text.split("\n"), 1):
        comment = line.find("//")
        if comment >= 0 and '"' in line[comment:]:
            errors.append(f"{path}:{number}: comment quotes text")
        if line.startswith("// @lift"):
            errors.append(f"{path}:{number}: lifter marker")
    if DECOMPILER_NAMES.search(text):
        errors.append(f"{path}: decompiler-style names")
    text_names = set(TEXT_CONSTANT_NAME.findall(text)) | (set(GLOBAL_NAME.findall(text)) & text_global_names())
    if text_names:
        errors.append(f"{path}: {len(text_names)} name(s) made from game text (str_<text>, or g_<text> from "
                      "research/decomp/global_names.tsv); publish their address form")
    for name in ENTRY.findall(text):
        if reviewed.get(name) != "OK":
            errors.append(f"{path}: {name} has no OK review record in {PROMOTED_REVIEW}")
    return errors


def review_records(repo, prefix=""):
    """function -> verdict from the staged review record of the promoted modules."""
    try:
        text = git(repo, "show", f":{prefix}{PROMOTED_REVIEW}")
    except subprocess.CalledProcessError:
        return {}
    rows = {}
    for line in text.splitlines()[1:]:
        cells = line.split("\t")
        if len(cells) >= 3:
            rows[cells[1]] = cells[2]
    return rows


_BINUTILS = None


def binutils_baseline():
    """{path: blob id} of the SDK-supplied GNU binutils (tools/binutils_baseline.tsv: the tree of the public ReXGlue
    v0.8.0 release the submodule points at)."""
    global _BINUTILS
    if _BINUTILS is None:
        _BINUTILS = {}
        p = ROOT / "tools" / "binutils_baseline.tsv"
        if p.exists():
            for line in p.read_text(encoding="utf-8").splitlines():
                if line and not line.startswith("#") and "\t" in line:
                    path, oid = line.split("\t", 1)
                    _BINUTILS[path] = oid.strip()
    return _BINUTILS


def audit(repo, label="."):
    errors = []
    records = git(repo, "ls-files", "--stage", "-z").split("\0")
    paths = set()
    reviewed = None
    for record in filter(None, records):
        metadata, path = record.split("\t", 1)
        mode, oid, stage = metadata.split()
        paths.add(path)
        location = f"{label}/{path}"
        if stage != "0":
            errors.append(f"{location}: unresolved index conflict")
        if mode == "160000":
            child = repo / path
            if not (child / ".git").exists():
                errors.append(f"{location}: submodule unavailable for inspection")
                continue
            if path == "rexglue-sdk" and oid != sdk_base():
                errors.append(f"{location}: points at {oid[:12]}, not the public ReXGlue release the SDK patch is "
                              f"made for ({str(sdk_base())[:12]}): keep SDK changes in patches/rexglue-sdk.patch "
                              f"(python tools/sdk_patch.py export)")
            if git(child, "rev-parse", "HEAD").strip() != oid:
                errors.append(f"{location}: staged gitlink differs from checkout")
            if git(child, "diff", "--cached", "--name-only").strip():
                errors.append(f"{location}: staged child changes are absent from the gitlink commit")
            if path == "Fable2Recomp":
                historical = git(child, "rev-list", "--objects", oid).splitlines()
                matches = [entry for entry in historical if re.search(
                    r" (?:.*\/)?(?:ppc_recomp\.[^/]+\.cpp|[^/]+\.(?:xex|iso|bnk))$", entry)]
                if matches:
                    errors.append(f"{location}: {len(matches)} historical game/code objects reachable; use a reviewed source-only snapshot")
            if path in REQUIRED or path == "rexglue-sdk":
                errors.extend(audit(child, path))
            continue
        parts = path.lower().split("/")
        # These are SDK-supplied GNU tools, not game executables. Only exempt
        # the exact baseline blobs; a replacement binary still requires review.
        if label == "rexglue-sdk" and path.startswith("tools/binutils/"):
            if binutils_baseline().get(path) == oid:
                continue
        rpath = runtime_path(label, path)
        forbidden = (Path(path).suffix.lower() in BLOCKED_SUFFIXES
                     or any(p in {"decomp", "rewritten", "iso", "extracted"} for p in parts)
                     or any(p.startswith("generated") for p in parts[:-1])
                     or (rpath is not None and rpath.split("/")[0] == "lifted" and rpath != "lifted/lifted.h"))
        derived = mod_material(path)
        if label == "." and path == "research/names/globals.tsv":
            derived = ("names of global string objects made from the game's text: tools/naming/global_strings.py "
                       "writes them locally (research/decomp/global_names.tsv)")
        if forbidden:
            errors.append(f"{location}: local game/build material must not be staged")
        elif derived:
            errors.append(f"{location}: {derived} - game-derived, keep it local")
        elif rpath is not None and rpath.startswith(PROMOTED) and path.endswith(".cpp"):
            if reviewed is None:
                reviewed = review_records(repo, path[:len(path) - len(rpath)])
            errors.extend(f"{label}/{e}" for e in promoted_problems(path, git(repo, "show", f":{path}"), reviewed))
    for path in REQUIRED.get(label, set()) - paths:
        errors.append(f"{label}/{path}: required authored header missing from index")
    return errors


# A machine's own user folder in a published file: personal data, and a path no other machine has. Placeholders
# (C:\Users\<you>, %USERPROFILE%, $HOME, ~) do not match.
PROFILE_PATH = r"[A-Za-z]:[\\/]+Users[\\/]+[A-Za-z0-9._-]+|/home/[A-Za-z0-9._-]+|/Users/[A-Za-z0-9._-]+"
NOT_PERSONAL = {"runner", "user", "username", "you", "your-name", "name", "me", "public", "default", "example",
                "shared"}


def profile_path_problems(grep_output):
    """Errors for `git grep -n -o` lines (path:line:match) that name a real user folder."""
    errors = []
    for line in grep_output.splitlines():
        path, number, match = line.split(":", 2)
        user = re.split(r"[\\/]+", match.rstrip("\\/"))[-1]
        if user.lower() not in NOT_PERSONAL:
            errors.append(f"./{path}:{number}: a user folder ({match}): personal data, and a path only one machine has")
    return errors


def profile_paths(repo):
    """Staged text files of this repository (not the SDK's) that name a user folder."""
    try:
        out = git(repo, "grep", "--cached", "-I", "-n", "-o", "-i", "-E", PROFILE_PATH)
    except subprocess.CalledProcessError:   # (exit status 1: nothing found)
        return []
    return profile_path_problems(out)


# An API key in a published file works for anyone who reads it. The usual providers' keys start with sk- (DeepSeek,
# OpenRouter sk-or-..., OpenAI, Anthropic sk-ant-...); tools/api_keys.py keeps keys outside the repository.
API_KEY = r"\bsk-[A-Za-z0-9_-]{20,}"


def api_key_problems(grep_output):
    """Errors for `git grep -n -o` lines (path:line:match) holding something shaped like an API key (not repeated)."""
    errors = []
    for line in grep_output.splitlines():
        path, number, _ = line.split(":", 2)
        errors.append(f"./{path}:{number}: something shaped like an API key (sk-...): keep keys out of the "
                      "repository (python tools/api_keys.py set <name>)")
    return errors


def api_keys_staged(repo):
    """Staged text files of this repository that hold something shaped like an API key."""
    try:
        out = git(repo, "grep", "--cached", "-I", "-n", "-o", "-E", API_KEY)
    except subprocess.CalledProcessError:   # (exit status 1: nothing found)
        return []
    return api_key_problems(out)


if __name__ == "__main__":
    problems = audit(ROOT) + profile_paths(ROOT) + api_keys_staged(ROOT)
    for problem in problems:
        print(f"FAIL: {problem}")
    print(f"Staged packaging audit: {len(problems)} blocker(s).")
    raise SystemExit(bool(problems))
