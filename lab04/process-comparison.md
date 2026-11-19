# Process comparison · Team SteavInMotion · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion              | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability |     20 |         2 |           4 |           5 | Requirements evolve through Week 6 SRS, Week 7 UML models, and sprint reviews, fitting short sprints best. |
| Client availability    |     15 |         3 |           3 |           4 | The client/TA gives ~30 minutes per week, which suits reviewing small working increments every sprint. |
| Team experience        |     20 |         4 |           4 |           3 | Our team knows plan-then-build workflows well, whereas Scrum ceremonies and rotating Scrum Master take practice. |
| Deadline (week 14)     |     25 |         2 |           4 |           4 | Two sprints (Weeks 9–12) plus Week 13 hardening keep a working CLI demo ready for Week 14. |
| Risk                   |     20 |         2 |           4 |           4 | Early testing and reviews catch capacity, duplicate-registration, and 24-hour cancellation bugs before late integration. |
| **Weighted score**       |    100 |      2.55 |        3.85 |        4.00 |                               |

## Why these weights
- Requirements stability (20): In Week 4 the client interview and SRS (Weeks 5–6) have not happened yet, and features like waiting lists and reminders remain open to refinement.
- Client availability (15): The instructor/TA is available about 30 minutes per week rather than daily, making structured periodic check-ins essential.
- Team experience (20): Our 4-person team is building a C++20 CLI core with CSV/JSON storage while learning Git branching, CMake, and agile roles.
- Deadline (week 14) (25): Project submission and demo happen in Week 14 right after Week 13 hardening, making schedule reliability our top priority.
- Risk (20): Enforcing core business rules (capacity limits, duplicate prevention, 24-hour cancellation cutoff, club approval) requires early verification.

## Calculation for one model
Scrum-style weighted score:
(20×5 + 15×4 + 20×3 + 25×4 + 20×4) / 100 = (100 + 60 + 60 + 100 + 80) / 100 = 400 / 100 = 4.00

## Sensitivity check
Moving 10 points from Deadline (25 → 15) to Client availability (15 → 25) keeps Scrum-style in first place (4.00 vs. Incremental 3.75 and Waterfall 2.65), so the winner does not change.

## Conclusion
Scrum-style iterative development scores highest (4.00 vs. Incremental 3.85 and Waterfall 2.55) because it adapts well to evolving requirements after each client review while keeping a demonstrable C++ CLI on track for Week 14. To manage its main weakness—our team's limited experience with Scrum ceremonies and Git/CMake coordination—we will keep sprint backlogs small, use clear `lab-*` branches, and run short weekly check-ins. Combining upfront specification and UML modeling in Weeks 5–8 with two focused sprints (Weeks 9–12) and a Week 13 hardening buffer gives us a strong hybrid structure that fits our 15-week semester even better than pure Scrum alone.