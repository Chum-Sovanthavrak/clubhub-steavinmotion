# Lab-04 · Software Development Processes · Team SteavInMotion

## Files of this lab
| File                                                  | Task      | Description                                                                 |
|-------------------------------------------------------|-----------|-----------------------------------------------------------------------------|
| fundamental-activities.md                             | 1         | The four activities in Club Hub with leads, weeks, artifacts and loops      |
| scores/*.md                                           | 2         | Individual scores, one file per member                                      |
| process-comparison.md                                 | 2         | Weighted comparison of waterfall, incremental and Scrum-style (Scrum 4.00)  |
| process-decision.md, process.mmd                      | 3         | PDR-001 (hybrid with two Scrum-style sprints) and the process diagram       |
| iteration-plan.md                                     | 4         | Gantt chart for weeks 5-14, iteration goals and sprint capacity             |
| reuse-inventory.md                                    | 5         | Make-or-reuse table, licence check and CTest verification                   |
| ../CMakeLists.txt                                     | 5         | FetchContent: googletest v1.15.2, rapidcsv v9.07                            |
| ../tests/csv_smoke_test.cpp, ../tests/data/events.csv | 5         | Smoke test that reads two events through rapidcsv                           |
| v-model-trace.md                                      | Challenge | V-model trace for REQ-12 (24-hour cancellation) across four levels, with boundary values and two Gherkin scenarios |
| cmmi-reflection.md                                    | Challenge | CMMI reflection: team's current maturity level with evidence, one practice area to adopt, three actions and a measurable target |

## Inputs reused
| Input               | File                       | Version (commit) |
|---------------------|----------------------------|------------------|
| Team charter        | lab01/team-charter.md      | a808f1d           |
| Problem statement   | lab01/problem-statement.md | f2774f8           |
| Application type    | lab02/application-type.md  | b01040b           |
| Repository licence  | LICENSE                    | 01e43f2           |

## Dependencies added
| Library    | Version | Licence      | Purpose                         |
|------------|---------|--------------|---------------------------------|
| GoogleTest | v1.15.2 | BSD-3-Clause | Unit-test framework (from Lab-03) |
| rapidcsv   | v9.07   | BSD-3-Clause | Header-only CSV reader          |

## Change log
| Date       | Change                                                                                  | By                       |
|------------|-----------------------------------------------------------------------------------------|--------------------------|
| 2026-11-19 | Lab-04: PDR-001 | Phorst Chan Sereywattana |
| 2026-11-19 | PR #9 merged by mistake, reverted in PR #10. Work remains on branch lab-04  | Phorst Chan Sereywattana |
| 2026-11-25 | Iteration plan, reuse inventory, FetchContent dependencies, smoke test | Ty Vannavuth |
| 2026-11-26 | Challenge: V-model trace for REQ-12, CMMI reflection<, cancellation rule and tests> | Chum Sovanthavrak |