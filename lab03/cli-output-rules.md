# CLI output rules · ITC Club Hub
Version 1.0 · 2026-11-12 · Authors: <Phorst Chan Sereywattana>

| # | Rule | Bad | Good |
|---|------|-----|------|
| 1 | Never use colour alone | `E-017  Git Workshop` (shown in red) | `E-017  Git Workshop  [CANCELLED]` |
| 2 | Honour `NO_COLOR` and `--no-color` | Always prints ANSI codes, even into a file | No colour codes when the flag is set or `NO_COLOR` exists |
| 3 | Errors say what failed, why, and the next step | `ERR_CAP` | `Error: cannot register for E-017: the event is full (40 of 40 seats).` / `Next step: clubhub waitlist E-017` |
| 4 | Non-zero exit code on error | Prints an error, exits with 0 | Prints the error, exits with 1, so scripts can detect it |
| 5 | Prompts state the expected format | `Date:` | `Date (YYYY-MM-DD HH:MM):` |
| 6 | Unambiguous dates | `10/11/26` (10 Nov or 11 Oct?) | `2026-10-14 17:30` |
| 7 | Plain words, no cryptic codes | `Status: 3` | `Status: [CHECKED IN]` |