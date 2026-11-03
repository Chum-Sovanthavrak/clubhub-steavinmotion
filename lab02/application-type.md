# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-11-03 · Status: Accepted (2026-11-03) · Deciders: Phorst Chan Sereywattana (Product Owner), Chum Sovanthavrak (Scrum master), Ty Vannavuth (Developer), Keng Kolpanha (Developer)

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students       |Own Android phone or iPhone|Anywhere: campus, home, on the move|Mobile data, often limited|A few times a week|Registering for an event without being double-booked or over capacity; receiving the reminder|
| Organisers     |1 or 2 phones per events|At the door of a room or hall|Weak or overloaded Wi-Fi|Per event (5 to 15 events a week)|Check-in must keep working when the network drops|
| Administrators |Desktop PC|Student affairs office|Stable office network|Monthly (reports) plus club approvals|Correct monthly report; only approved clubs publish
## Options
A. Native apps (Android + iOS) for students and organisers; a web page for administrators 
B. Cross-platform app (Flutter or React Native) for students and organisers; a web page for administrators  
C. PWA for students and organisers + the same web app for administrators (one codebase)  
D. Responsive web app only, no service worker (always online)

## Weighted comparison (score 1-5 x weight)
| Criterion (weight) | why this weight | A | B | C | D |
|--------------------|-----------------|---|---|---|---|
| Cost for our team in one semester (3) | 5 people, one semester, and the C++ core must also be built|	1 x 3 = 3|	3 x 3 = 9|	4 x 3 = 12|	5 x 3 = 15 |
| Reach (3)                             | 3,000 students on Android and iPhone, on mobile data; any install friction loses user|	3 x 3 = 9|	3 x 3 = 9|	4 x 3 = 12|	5 x 3 = 15 |
| Offline check-in at the door (3)      |Core use case; Wi-Fi at the door is weak and 200 arrive in 10 minutes|5 x 3 = 15|	4 x 3 = 12|	4 x 3 = 12|	1 x 3 = 3 |
| Reminders (2)                         | 	Important, but the e-mail service is a fallback on every option	|5 x 2 = 10	|4 x 2 = 8|	3 x 2 = 6	|2 x 2 = 4 |
| No install and easy report printing for administrators (1)             | Only 2 or 3 users, once a month|	1 x 1 = 1	|2 x 1 = 2|	5 x 1 = 5|	5 x 1 = 5|
| **Total**(max 60)                           | | 	3 + 9 + 15 + 10 + 1 = 38|9 + 9 + 12 + 8 + 2 = 40|12 + 12 + 12 + 6 + 5 = 47|	15 + 15 + 3 + 4 + 5 = 42 |

Deal-breaker check:Deal-breakers:(1) check-in must work without Wi-Fi; (2) no student may be registered twice or beyond capacity (this is enforced on the server, so it holds for every option); (3) no password stored by Club Hub (the ITC student directory handles identity).

- D (responsive web, 42) scores second but fails deal-breaker 1, so it is out.
- The winner C passes deal-breaker 1 only if we add an offline check-in queue (service worker + IndexedDB, synchronised when the network returns; see the challenge). We add this to the decision. Organisers must install the PWA to the Home Screen and open it once on good Wi-Fi before the event.
- C passes deal-breakers 2 and 3.

## Decision
We choose Option C: a PWA for students and organisers, and the same web app (a desktop layout) for administrators, with an offline check-in queue and e-mail as the fallback for reminders. One codebase serves all three user groups. The front ends are modelled only this semester; the C++ core and CLI are implemented.
## Consequences
+ One codebase for students, organisers and administrators; the team can finish within one semester.
+ No app-store review and no install needed to start: students open a link, which suits 3,000 users on mobile data.
+ Administrators need no software on the office PCs; the browser is enough.
+ The offline queue keeps check-in working when the Wi-Fi drops, and the server stays the single source of truth for registrations.
- iPhone users receive push reminders only after installing the PWA; e-mail reminders remain the fallback.
- Offline storage on iOS is limited and may be evicted, so we need an explicit sync step and a visible "pending" counter on the organiser's phone.
- Offline check-in creates sync conflicts (same student at two doors, cancelled registration) that need written rules and extra testing.
- The team needs service-worker and IndexedDB skills, and a browser compatibility matrix must be tested (see QAS-06).
## Rejected options
+ A. Native apps (Android + iOS): two front ends plus store review is too much for a 5-person team in one semester (score 38).
+ B. Cross-platform app: still requires an install and store publishing, and a new framework to learn, with no clear gain over C for this team (score 40).
+ D. Responsive web app only: fails the deal-breaker "check-in must work without Wi-Fi" (offline score 1).
+ Desktop application: students and organisers use phones, so it serves only 2 or 3 administrators and would cost extra work for them.
## How the front ends reach the C++ core
In production the core (include/clubhub/, src/) would sit behind an HTTP API, and the PWA would call it over HTTPS. In this course the PWA is only modelled, and the command-line interface (src/cli/) calls the core directly. Both front ends use the same clubhub_core library, so the business rules are written once.