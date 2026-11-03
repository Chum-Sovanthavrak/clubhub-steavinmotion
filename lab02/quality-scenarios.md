# Lab-02 · Quality attribute scenarios for SteavInMotion
Version 1.0 · 2026-__-__ · Reviewed by (Scrum Master): __

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
...
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
|----------|---------------------|----------------|----------|--------|
| QAS-01   |                     |                |          |        |