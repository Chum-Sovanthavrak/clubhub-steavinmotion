# V-Model Trace · REQ-12 (Cancellation Deadline) · Team SteavInMotion

## Requirement (REQ-12)
**REQ-12:** A student can cancel a registration until 24 hours before the start of the event.

## V-Model Traceability Matrix

| V-Model Level | Left Side (Defines / Decomposes) | Right Side (Verifies / Tests) |
|---------------|------------------------------------|-------------------------------|
| **Requirement ↔ Acceptance Test** | **REQ-12**: A student can cancel a registration until 24 hours before the event start (`2026-11-07 14:00`). | **AT-12**: Gherkin acceptance scenarios run at sprint review: allowed at `2026-11-06 14:00` (24h prior) and rejected at `2026-11-06 14:00:01` (1s past deadline). |
| **System Specification ↔ System Test** | **SYS-REQ-12**: System cancellation command/flow checks event start timestamp against current time before mutating registration state and seat counts. | **ST-12**: End-to-end CLI/application flow test: student `S001` cancels `E001` at `2026-11-06 14:00` -> status becomes `Cancelled`, available seats increment by 1; at `2026-11-06 14:00:01` -> rejected with deadline message, status remains `Registered`, seats unchanged. |
| **Architecture Design ↔ Integration Test** | **ARCH-12**: `RegistrationService::cancel` (`src/RegistrationService.cpp`) coordinates domain rule evaluation and persistent storage update via the repository/CSV layer. | **IT-12**: Integration test combining `RegistrationService::cancel` with a temporary CSV repository file: cancelling `S001` on `E001` at `2026-11-06 14:00` persists `Cancelled` when reloaded from disk; cancelling at `2026-11-06 14:00:01` leaves persisted status unchanged. |
| **Module Design ↔ Unit Test** | **MOD-12**: `clubhub::canCancel(now, start)` in `include/clubhub/CancellationPolicy.hpp` using `std::chrono::sys_seconds` (`start - now >= 24h`). | **UT-12**: GoogleTest unit tests in `tests/cancellation_rule_test.cpp`: `UT-12a`: `now = start - 24h` -> `true` (exact boundary); `UT-12b`: `now = start - 24h + 1s` -> `false` (1s past deadline); `UT-12c`: `now = start - 168h` (1 week before) -> `true`; `UT-12d`: `now = start + 1h` (after event start) -> `false`. |

## Acceptance Tests (Gherkin · AT-12)

```gherkin
Feature: Cancel a registration (REQ-12, acceptance test AT-12)

  Background:
    Given the event "Robotics Workshop" starts on 2026-11-07 at 14:00
    And student "S001" is registered for "Robotics Workshop"

  Scenario: Cancellation exactly 24 hours before the start is allowed
    Given the current time is 2026-11-06 14:00
    When student "S001" cancels the registration
    Then the registration status is "Cancelled"
    And one seat becomes free

  Scenario: Cancellation less than 24 hours before the start is rejected
    Given the current time is 2026-11-06 14:00:01
    When student "S001" cancels the registration
    Then the cancellation is rejected with a deadline notice
    And the registration status remains "Registered"
    And no seat becomes free