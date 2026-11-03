# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-11-03 · Reviewed by (Scrum Master): Chum Sovanthavrak

## QAS-01 · Availability · written by Phorst Chan Sereywattana
| Part | Content |
|---|---|
| Source | Club administrator |
| Stimulus | A cloud server hosting Club Hub crashes during peak load on Friday evening |
| Environment | Friday 18:00, registration opens, 40 active clubs publishing events |
| Artifact | Core backend server and database cluster |
| Response | System automatically detects failure, switches to hot-standby replica, and restores database connections |
| Response measure | Downtime <= 30 seconds; 0 data loss for registered attendees; equivalent to <= 0.005% monthly downtime |

## QAS-02 · Performance of check-in at the door · written by Ty Vannavuth
| Part | Content |
|---|---|
| Source | Event organiser |
| Stimulus | Scans attendee QR codes at the door during heavy entry traffic |
| Environment | Friday 18:00, 200 arrivals in 10 minutes at one entrance with weak or overloaded Wi-Fi |
| Artifact | Check-in module and local check-in client cache |
| Response | Validates and records attendance locally or against server, displaying success confirmation on the organiser's phone |
| Response measure | Response time <= 1.5 seconds per scan under 200 arrivals / 10 min load |

## QAS-03 · Usability · written by Chum Sovanthavrak
| Part | Content |
|---|---|
| Source | Student user |
| Stimulus | Attempts to browse upcoming club events and register for a preferred club activity on mobile data |
| Environment | Normal runtime, mobile device (Android/iOS), casual browsing |
| Artifact | User interface / PWA mobile client screens |
| Response | System displays event details, requirements, and an intuitive one-tap registration button |
| Response measure | Registration completed successfully in <= 3 taps and <= 20 seconds without user training |

## QAS-04 · Security · written by Chum Sovanthavrak
| Part | Content |
|---|---|
| Source | Unauthorized external user / malicious student |
| Stimulus | Attempts to scrape or access private student phone numbers, student IDs, and attendance records via direct API manipulation |
| Environment | Runtime, public internet connection |
| Artifact | Authentication and authorization service, database access layer |
| Response | System rejects unauthorized requests, logs the security event, and blocks the IP address |
| Response measure | 0 unauthorized disclosures of personal data (student ID, phone number, email, attendance records); access blocked within <= 1 second |

## QAS-05 · Modifiability · written by Chum Sovanthavrak
| Part | Content |
|---|---|
| Source | A developer of the team |
| Stimulus | Adds the waiting list feature: a full event puts new registrations in status Waitlisted |
| Environment | Design time, after Sprint 1, core already tested |
| Artifact | RegistrationService, Registration (`include/clubhub/`) |
| Response | Change made in the core only; the CLI gains one column; existing behaviour unchanged |
| Response measure | Done in <= 2 person-days; <= 4 files changed under `include/` and `src/`; 0 changes in `src/cli/` other than display; all existing tests still pass |

## QAS-06 · Portability · written by Keng Kolpanha
| Part | Content |
|---|---|
| Source | System administrator / QA tester |
| Stimulus | Deploys and runs the Club Hub mobile application across different target mobile operating systems |
| Environment | Release time, tested on Android (version 12+) and iOS (version 15+) mobile devices |
| Artifact | Mobile client application package |
| Response | App renders correctly, adapts to varying screen resolutions, and successfully connects to the backend API |
| Response measure | 100% core UI views functional and responsive across tested Android and iOS devices; API communication verified via automated test suite |

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|---|---|---|---|---|
| QAS-01 | High | High | Administrators & Organisers | Yes |
| QAS-02 | High | High | Organisers & Students | Yes |
| QAS-03 | Medium | Low | Students | No |
| QAS-04 | High | Medium | Students (Personal Data) | No |
| QAS-05 | Medium | Low | Developers | No |
| QAS-06 | Medium | Low | Cross-platform Users | No |