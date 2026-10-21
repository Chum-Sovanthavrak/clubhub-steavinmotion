# Problem statement · ITC Club Hub (v0.1, 2026-10-21)

## Problem
The issue of fragmented communication, manual tracking and a total lack of control over event sign-ups in the Telegram/chat groups is a real one for ITC students, club heads and institute admin. The result of this is overcrowded rooms, unreliable attendance records, event sign-ups going missing and a massive amount of admin overhead. A good solution would be to have a centralized system for club discovery, automate the registration and room capacity tracking and provide clear attendance records.

## Vision
For ITC students and club organizers who struggle with chaotic event coordination and room management, ITC Club Hub is a centralized club management platform that streamlines event registration, attendance logging, and venue allocations. Unlike informal chat groups and physical paper sign-up sheets, our product offers real-time capacity checks and direct attendance records tailored to ITC campus workflows.

## Today's workaround
Currently, club leaders create public polls or sign-up links in Telegram chat groups, manually count registrations to avoid exceeding room capacity, and record attendance on paper sheets or Google Forms during the event. Students miss announcements in busy group chats, and administrators receive no structured reporting on club activity or room utilization.

## Scope
- **Built in C++ this semester:** Core backend logic (user authentication state, registration validation algorithm, room capacity checking engine, attendance logger, file based data persistence/JSON parser).
- **Modelled only (web and mobile):** UI mockups for student event feed, club manager dashboard, QR-code attendance scanner screen, and room allocation interface.
- **Out of scope:** Live payment gateway for event fees, automated integration with third-party university LMS, hardware QR scanners, and video streaming for virtual events.