# Retention rules · ITC Club Hub
Version 1.0 · 2026-11-10 · Authors: <Ty Vannavuth>

One row for every field with a `Keep`, `Keep optional`, `Mask` or `Aggregate` decision in `lab03/data-inventory.md`. "Graduation" means the date the registrar marks the student as graduated or withdrawn. `clubhub purge` is a future administrator command that runs monthly.

| Field | Trigger | Action | Who or what runs it | How to verify |
|-------|---------|--------|---------------------|---------------|
| studentId | Student deletes the account, or 6 months after graduation | Delete the row in `data/students.csv`. In `data/registrations.csv` replace the ID with an anonymous token, so counts stay correct | `clubhub purge`, monthly. Account deletion runs it for that student at once | Unit test: after purge the ID is not found in either file. Monthly checklist item with date and signature of the administrator |
| name | Same as studentId | Delete with the student's row | `clubhub purge` | Same test as studentId: no row, no name left in any CSV |
| email | Same as studentId | Delete with the student's row | `clubhub purge` | Same test as studentId; `git grep` and a file search find no email outside `example.edu` test data |
| phone | Student withdraws SMS consent (immediate), or 6 months after graduation | Erase the number: `withdrawSmsConsent()` resets the optional value, and the CSV cell is emptied | `withdrawSmsConsent()` at once; `clubhub purge` for the graduation case | Unit test `WithdrawingSmsConsentErasesPhone`. After a purge test, no phone column has a value for graduated students |
| clubMemberships | Student leaves the club, deletes the account, or 6 months after graduation | Delete the membership rows in `data/memberships.csv` | Club leader or student for leaving (at once); `clubhub purge` for the other cases | Unit test: after purge no membership row refers to the student. Monthly checklist item |
| attendance | 3 months after the event | Aggregate: keep one count per event and month, delete the identified rows (no studentId left) | `clubhub purge`, monthly | Test: totals before and after purge are equal and the aggregated file has no studentId column. Monthly checklist item with date and signature |

## Monthly purge checklist

| Month | Purge run by | Date | Signature | Rows removed or aggregated |
|-------|--------------|------|-----------|----------------------------|
| 2026-MM | TODO | TODO | TODO | TODO |