"""Validate public Fable2RE dictionaries and research metadata.

This check intentionally needs only the files committed to the umbrella repository. It does
not read a game executable, generated code, decompiler output, or either source submodule.
"""

from __future__ import annotations

import csv
import gzip
import json
import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
HEX_ADDRESS = re.compile(r"[0-9A-F]{8}\Z")
HEX_OFFSET = re.compile(r"[0-9A-F]{1,8}\Z")
IDENTIFIER = re.compile(r"[A-Za-z_][A-Za-z0-9_]*\Z")
CONFIDENCE = {"low", "medium", "high"}

NAME_TABLES = {
    "functions.tsv": (["address", "name", "confidence", "basis"], ("address",)),
    "classes.tsv": (["vtable", "name", "confidence", "basis"], ("vtable",)),
    "fields.tsv": (["vtable", "offset", "name", "confidence", "basis"], ("vtable", "offset")),
    "globals.tsv": (["address", "name", "text", "basis"], ("address",)),
    "locals.tsv": (["function", "variable", "name", "confidence", "basis"], ("function", "variable")),
}

CATALOG_TABLES = {
    "converted.tsv": (["address", "name", "status", "module"], ("address",)),
    "functions.tsv": (
        ["address", "name", "name_source", "size", "library", "lua", "callers", "callees", "decomp", "status"],
        ("address",),
    ),
    "names_manual.tsv": (["address", "name"], ("address",)),
    "scope.tsv": (["start", "end", "category", "what", "confidence", "evidence"], ("start", "end")),
    "tuning.tsv": (["name", "address", "type", "setter", "lua"], ("name",)),
}


def read_tsv(path: Path, expected: list[str], key_columns: tuple[str, ...], errors: list[str]) -> list[dict[str, str]]:
    try:
        with path.open(encoding="utf-8", newline="") as stream:
            reader = csv.DictReader(stream, delimiter="\t")
            if reader.fieldnames != expected:
                errors.append(f"{path.relative_to(ROOT)}: expected header {expected!r}, found {reader.fieldnames!r}")
                return []
            rows = list(reader)
    except (OSError, UnicodeError, csv.Error) as exc:
        errors.append(f"{path.relative_to(ROOT)}: cannot read TSV: {exc}")
        return []

    seen: dict[tuple[str, ...], int] = {}
    for line_number, row in enumerate(rows, 2):
        if None in row:
            errors.append(f"{path.relative_to(ROOT)}:{line_number}: too many columns")
            continue
        if any(value is None for value in row.values()):
            errors.append(f"{path.relative_to(ROOT)}:{line_number}: too few columns")
            continue
        key = tuple(row[column] for column in key_columns)
        if key in seen:
            errors.append(
                f"{path.relative_to(ROOT)}:{line_number}: duplicate key {key!r}; first used on line {seen[key]}"
            )
        else:
            seen[key] = line_number
    # Do not pass malformed records to validators that expect string values.
    # Reject the table as a whole so subsequent diagnostics retain real line numbers.
    if any(None in row or any(value is None for value in row.values()) for row in rows):
        return []
    return rows


def check_address(value: str, location: str, errors: list[str]) -> None:
    if not HEX_ADDRESS.fullmatch(value):
        errors.append(f"{location}: address must be eight uppercase hexadecimal digits, found {value!r}")


def validate_names(errors: list[str]) -> None:
    directory = ROOT / "research" / "names"
    used_names: dict[str, dict[str, str]] = {"functions.tsv": {}, "classes.tsv": {}}
    table_rows: dict[str, list[dict[str, str]]] = {}
    for filename, (header, key) in NAME_TABLES.items():
        path = directory / filename
        rows = read_tsv(path, header, key, errors)
        table_rows[filename] = rows
        scoped_names: dict[tuple[str, str], str] = {}
        for line_number, row in enumerate(rows, 2):
            location = f"{path.relative_to(ROOT)}:{line_number}"
            for column in ("address", "vtable", "function"):
                if column in row:
                    check_address(row[column], location, errors)
            if "offset" in row and not HEX_OFFSET.fullmatch(row["offset"]):
                errors.append(f"{location}: offset must be uppercase hexadecimal without 0x, found {row['offset']!r}")
            if not IDENTIFIER.fullmatch(row["name"]):
                errors.append(f"{location}: invalid C++ identifier {row['name']!r}")
            if "confidence" in row and row["confidence"] not in CONFIDENCE:
                errors.append(f"{location}: confidence must be low, medium, or high")
            if "basis" in row:
                if not row["basis"].strip() or "\n" in row["basis"] or "\r" in row["basis"]:
                    errors.append(f"{location}: basis must be one non-empty line")
                elif len(row["basis"]) > 300:
                    errors.append(f"{location}: basis must be at most 300 characters")

            if filename in used_names:
                previous = used_names[filename].get(row["name"])
                current = "/".join(row[column] for column in key)
                if previous is not None and previous != current:
                    errors.append(f"{location}: name {row['name']!r} is already used for {previous}")
                used_names[filename][row["name"]] = current

            scope = row.get("vtable") if filename == "fields.tsv" else row.get("function")
            if scope is not None:
                scoped_key = (scope, row["name"])
                current = "/".join(row[column] for column in key)
                previous = scoped_names.get(scoped_key)
                if previous is not None and previous != current:
                    errors.append(f"{location}: name {row['name']!r} is already used in {scope} for {previous}")
                scoped_names[scoped_key] = current

    func_db_path = ROOT / "research" / "symbols" / "func_db.json"
    try:
        function_db = json.loads(func_db_path.read_text(encoding="utf-8"))
        if not isinstance(function_db, dict):
            errors.append("research/symbols/func_db.json: top level must be an object")
        else:
            for address in function_db:
                check_address(address, "research/symbols/func_db.json", errors)
            known_functions = set(function_db)
            for filename, column in (("functions.tsv", "address"), ("locals.tsv", "function")):
                for line_number, row in enumerate(table_rows.get(filename, []), 2):
                    if row[column] not in known_functions:
                        errors.append(
                            f"research/names/{filename}:{line_number}: {row[column]} is not in research/symbols/func_db.json"
                        )
    except (OSError, UnicodeError, json.JSONDecodeError) as exc:
        errors.append(f"research/symbols/func_db.json: invalid JSON: {exc}")

    summary_path = ROOT / "research" / "lift" / "summaries.json.gz"
    try:
        with gzip.open(summary_path, "rt", encoding="utf-8") as stream:
            summary = json.load(stream)
        source = (ROOT / "tools/lift/summarize.py").read_text(encoding="utf-8")
        version = re.search(r"^ANALYSIS_VERSION\s*=\s*(\d+)", source, re.MULTILINE)
        if not isinstance(summary, dict) or summary.get("format") != "fable2re-lift-summaries":
            errors.append("research/lift/summaries.json.gz: invalid summary format")
        elif version is None or summary.get("analysis_version") != int(version.group(1)):
            errors.append("research/lift/summaries.json.gz: analysis version differs from summarize.py; regenerate and validate the analysis")
    except (OSError, UnicodeError, json.JSONDecodeError) as exc:
        errors.append(f"research/lift/summaries.json.gz: invalid compressed JSON: {exc}")


def validate_catalog(errors: list[str]) -> None:
    directory = ROOT / "research" / "catalog"
    for filename, (header, key) in CATALOG_TABLES.items():
        path = directory / filename
        rows = read_tsv(path, header, key, errors)
        for line_number, row in enumerate(rows, 2):
            location = f"{path.relative_to(ROOT)}:{line_number}"
            for column in ("address", "setter", "start", "end"):
                value = row.get(column, "")
                if value:
                    check_address(value, location, errors)
            if "confidence" in row and row["confidence"] not in CONFIDENCE:
                errors.append(f"{location}: confidence must be low, medium, or high")


def main() -> int:
    errors: list[str] = []
    validate_names(errors)
    validate_catalog(errors)
    if errors:
        print("metadata validation failed:", file=sys.stderr)
        for error in errors:
            print(f"  - {error}", file=sys.stderr)
        return 1
    print("metadata validation passed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
