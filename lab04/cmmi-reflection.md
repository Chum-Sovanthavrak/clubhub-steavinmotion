# CMMI reflection · Team SteavInMotion

## Where we are today (level 1) and the evidence
Today our team is at **CMMI Maturity Level 1 (Initial)**. We have defined a Scrum-style process and sprint schedule in `process-decision.md` and `iteration-plan.md`, and set up CMake with GoogleTest, yet our day-to-day execution has so far relied on ad hoc coordination rather than consistent team-wide routines. Evidence in our Lab-04 Git history shows commits concentrated among part of the team, informal commit messages on early drafts, and merges happening without a consistent peer-review habit. Because we are balancing coursework and exams alongside project work, relying on informal coordination risks logic bugs and last-minute integration issues once Sprint 1 coding starts.

## The practice area we adopt now and why
We choose to adopt **Peer Reviews** (supported by basic **Configuration Management** discipline on pull requests) starting in Sprint 1. In a four-person C++ team building Club Hub over two 2-week sprints, requiring a teammate's review before merging catches business-rule boundary errors (such as the 24-hour cancellation deadline), missing tests, and build breaks early while helping every member understand the full codebase.

## Three actions (who, from when)
1. **Require at least one teammate approval before merging any pull request into `main`**: All four team members (acting as both authors and reviewers), starting **from Sprint 1 planning (Week 9)** onward.
2. **Verify business-rule boundaries, passing CTest suites, and clean builds on every code PR**: Every PR author and reviewer, starting **with the first Sprint 1 feature PR in Week 9**.
3. **Keep PRs small and scoped to a single user story or task** so teammates can review them within 24 hours: All four team members, starting **at the beginning of Sprint 1 (Week 9)**.

## How we measure it (metric, target) and when we check
* **Metric:** Number of pull requests merged into `main` without at least one documented teammate review, counted directly from Git and pull-request history.
* **Target:** **0 unreviewed merges** during Sprint 1 (100% of code PRs reviewed before merge).
* **When we check:** Together at the **Sprint 1 retrospective** at the end of Week 10, where we will inspect PR history and adjust our review turnaround habit before Sprint 2 begins.