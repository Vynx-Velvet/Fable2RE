# Security policy

Fable2RE is pre-release reverse-engineering and modding software. No build should currently be treated as hardened for untrusted mods, content, saves, peers, or public network exposure.

Report a vulnerability privately through the repository's **Security** tab (**Report a vulnerability**). Include the affected revision, impact, reproduction conditions, and a minimal proof of concept that does not contain copyrighted game data or credentials. Do not open a public issue for an unpatched vulnerability that could affect other users.

Security-sensitive work should keep parsers bounded, validate all file and network input, avoid embedding secrets, separate service identity from gameplay state, and provide local deterministic tests. Online protocols and mod packages must be versioned and capability-aware before they are considered stable for untrusted use.
