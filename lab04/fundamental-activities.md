# Fundamental activities · Team SteavInMotions · v1.0 (2026-11-13)

| Activity | What happens in Club Hub | Who leads (role, name) | Weeks | Artifact | Done when |
|---|---|---|---|---|---|
| Specification | Interview the client (TA) about club registration, event publishing and the register/cancel flow; write user stories for "register for an event" and "cancel a registration"; write the business rules (capacity, no duplicates, 24 h cancellation, no past events, approved clubs only) as testable requirements; prioritise the backlog with MoSCoW (waiting list = Should) | Product Owner, Phorst Chan Sereywattana | 5-6 (refined in 11 and 13) | lab05/srs.md, lab05/product-backlog.md | The TA approved the SRS by email and the backlog is prioritised and estimated, with all Must stories having acceptance criteria |
| Design and implementation | Model the domain (Club, Event, Student, Registration) in UML; define the interfaces EventRepository and RegistrationRepository with CSV implementations; implement RegistrationService::registerStudent, cancel and checkIn with the CLI front end; work in short-lived branches with pull requests | Developers, tech lead Ty Vannavuth (rotates by sprint) | 7 (design), 9-12 (Sprints 1-2), 13 (fixes) | lab06/uml/, include/clubhub/, src/, CMakeLists.txt | Every Must story of the sprint is merged to main through a reviewed pull request and runs in the CLI demo |
| Validation | Unit tests with GoogleTest for the capacity, duplicate and 24 h cancellation rules; peer review of every pull request; review of the SRS (week 6) and models (week 8 checkpoint) before coding; demo of the CLI to the client at each sprint review | Developers, test lead Keng Kolpanha (rotates) | 6, 8, 9-14 | tests/, .github/workflows/ci.yml, CI run history, lab09/review-notes.md | Every Must story has passing tests in CI and the TA accepted it at the sprint review |
| Evolution | Handle changes the client asks for after each sprint review (e.g. "seats left" in the event list, a waiting list); update backlog and tests; keep a changelog; fix defects found after delivery; after week 14 keep the project maintainable for later teams | Scrum Master (current sprint), Chum Sovanthavrak, with Product Owner deciding priority | 10-14 (and beyond) | CHANGELOG.md, GitHub issues labelled change-request, lab05/product-backlog.md (versions) | Each change request is recorded as an issue, prioritised by the PO, implemented with tests and listed in CHANGELOG.md for the next release |

## Sub-activities and ISO/IEC/IEEE 12207 processes
- **Specification:** elicitation (client interview), analysis (conflicts, priorities, MoSCoW), specification (SRS, user stories, acceptance criteria), validation of requirements (review with the TA).
  · 12207: Stakeholder needs and requirements definition; System/software requirements definition.
- **Design and implementation:** architecture and domain modelling, detailed design of RegistrationService and repositories, coding, integration of CSV storage and CLI.
  · 12207: Architecture definition; Design definition; Implementation; Integration.
- **Validation:** unit testing, code review, continuous integration, acceptance at sprint review.
  · 12207: Verification; Validation.
- **Evolution:** change-request handling, impact analysis, regression testing, release and changelog.
  · 12207: Maintenance; Transition (and Operation, if the client uses it).

## Overlaps and loops
1. Week 10: the Sprint 1 review shows the client wants "seats left" in the event list -> new story US-21 -> specification again in week 11 -> design, implementation and tests in Sprint 2 (Specification -> Evolution -> Specification -> Implementation).
2. Weeks 9-12: design, implementation and validation interleave daily: each pull request contains code and its tests and is reviewed before merge.
3. Week 8: the checkpoint review of the SRS and UML models may send us back to Specification (fix ambiguous rules such as "exactly 24 h") before any Sprint 1 code is written.