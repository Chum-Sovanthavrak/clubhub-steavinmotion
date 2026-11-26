# Reuse inventory · Team SteavInMotion · v1.0 (2026-11-25)

Decisions: **Reuse** (take an existing library or tool), **Build** (write it ourselves), **Defer** (decide later). Our repository licence is MIT (Lab-03). Release dates were read from the projects' GitHub release pages on 2026-11-25.

| Need | Options | Decision | Reason | Licence | Pinned version | Last release |
|------|---------|----------|--------|---------|----------------|--------------|
| Unit testing | GoogleTest; Catch2; doctest | Reuse GoogleTest | Chosen in Lab-03; works with CTest through `gtest_discover_tests`; the course uses it | BSD-3-Clause | v1.15.2 (kept from Lab-03) | Newest release v1.18.0, 10 Aug 2026 |
| File storage (CSV) | rapidcsv; our own parser (`src/event_csv.cpp` from an earlier lab) | Reuse rapidcsv | Lab-02 chose CSV files; header-only, one `FetchContent` entry, handles quoted cells. Our domain mapping stays ours. Sprint 1 planning decides whether `event_csv.cpp` switches to it | BSD-3-Clause | v9.07 | v9.07 on 15 Aug 2026; newest is v9.09 on 21 Nov 2026 |
| Date and time (24 h rule) | C++20 `std::chrono`; Howard Hinnant date library; our own integer arithmetic | Reuse the standard library | C++20 is already required; subtracting two `sys_seconds` values gives the 24 h check directly; nothing to download | none (standard library) | C++20 | - |
| CLI input handling | CLI11; cxxopts; our own `argv` parsing | Build | Only a few commands (list, register, cancel, check-in); a library can be added in Sprint 2 if the commands grow | ours (MIT) | - | - |
| Registration rules | none fits our rules | Build | Capacity, no duplicate, 24 h cancellation, no past events and approved clubs only are unique to Club Hub, graded and must be tested | ours (MIT) | - | - |
| Reminders | an SMS gateway or email service; a printed list of due reminders | Defer | Reminder is not a Must. It needs real SMS or email sending and the opt-in consent from Lab-03. Sprint 2, only if time remains | - | - | - |
| Monthly report | a spreadsheet export library; our own counting | Build | Only counts of checked-in students per club and month (counts only, as in our privacy notice); simple loops over the registrations | ours (MIT) | - | - |
| Logging | spdlog; `std::clog`; our own small wrapper | Build | Lab-03 rule: logs contain only `redacted()` output. A tiny wrapper over `std::clog` enforces this in one place. We may reconsider spdlog later | ours (MIT) | - | - |
| Continuous integration | GitHub Actions; running tests only on our own computers | Reuse GitHub Actions | The repository is on GitHub; a workflow builds and runs `ctest` on every pull request (`.github/workflows/ci.yml`) | service, our workflow file is MIT | action versions pinned when `ci.yml` is written | - |

## Licence check

Our repository is MIT.

- **GoogleTest (BSD-3-Clause):** compatible. We keep its copyright notice and licence text (`licenses/googletest-LICENSE.txt`). It is only used for tests and is not shipped.
- **rapidcsv (BSD-3-Clause):** compatible with an MIT repository. A BSD-3-Clause licence only asks us to keep the copyright notice and licence text, which are in `licenses/rapidcsv-LICENSE.txt` and `THIRD_PARTY_NOTICES.md`. If our program is shipped with rapidcsv compiled in, the notice must come with it, and we must not use the authors' names to promote our product.
- **`std::chrono`:** part of the C++ standard library, no extra licence to track.
- **What a GPL library would require:** if we linked a GPL-3.0 library into our program and shared the program, the whole program would have to be offered under GPL-3.0 with its source. That conflicts with our MIT choice unless the team changes the licence, so we avoid GPL libraries.

## Verification

Run from a clean build folder on the team computer, then paste the real output below. Delete the `build-mingw` folder first so that a stale cache cannot hide a missing dependency.

```text
Compiler: <for example GCC 15.2.0 MSYS2 UCRT64>
CMake:    <cmake --version>

<paste the output of:
 cmake -S . -B build-mingw -G "MinGW Makefiles"
 cmake --build build-mingw
 ctest --test-dir build-mingw --output-on-failure>
```