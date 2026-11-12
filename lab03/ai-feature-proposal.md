# AI feature proposal: "Recommended for you"
Version 0.1 · 2026-11-12 · Authors: Chum-Sovanthavrak, Ty-Vannavuth, kengkolpanha-design, Phorst-Chan-Sereywattana

## 1. Problem and non-personalised baseline

* **User Problem:** Students face information overload when browsing dozens of weekly campus events across different clubs, making it hard to discover relevant activities without checking every club page manually.
* **Non-personalised Baseline:** A hybrid feed combining **"Popular this week"** (events with highest campus-wide registrations) and **"Events of my clubs"** (chronological upcoming events from clubs the student has already joined). This solves discovery without collecting behavioral tracking data or personal profiles.

## 2. Data needed

| Field | Source | In inventory? | New purpose / consent? | Minimisation |
|-------|--------|---------------|------------------------|--------------|
| Club memberships | Student profile | Yes | No | Restricted to active memberships only |
| Event attendance history | Event check-ins | Yes | **Yes** (Requires new opt-in consent) | Limited to last 12 months; timestamps and categories only |
| Event category tags | Event metadata | Yes | No | Public tags only |
| Student major / year | Student profile | Yes | **Yes** (Optional opt-in) | Aggregated broad faculty level; no phone, email, or free-text |

* **Task 1 Inventory Changes:** Adding recommendations requires updating `lab03/data-inventory.md` to add a new processing purpose ("personalised event recommendations") and adding an opt-in consent flag (`recommendationsConsent`) to the `Student` model.

## 3. Bias risks

| Risk | Who is harmed | Mitigation | Fairness check (metric, threshold) |
|------|---------------|------------|------------------------------------|
| **Cold-start / New student loop** | First-year students without past attendance history | Seed new profiles with campus-wide popular events and broad orientation tags. | Share of recommendations served to first-year students >= 20% of total recommendations (+/- 5% of student body share). |
| **Popularity feedback loop** | Small or newly formed clubs | Reserve at least 2 of 5 recommendation slots for events from clubs the student has never attended. | Monthly exposure check: clubs with fewer than 20 members receive at least 80% of their fair share of recommendations. |
| **Attendance as a proxy for time/money** | Commuting or working students who attend fewer in-person events | Weight explicit club memberships and voluntary interest tags higher than raw historical counts. | Recommendation diversity score parity (<= 10% variance) between high- and low-frequency attendees. |
| **Major / Faculty silo effect** | Students limited to events strictly tied to their academic department | Include cross-disciplinary and general interest cultural/sports tags in scoring weights. | Inter-faculty recommendation ratio: at least 30% of suggested events originate outside the student's home faculty. |

## 4. Transparency

"Why am I seeing this?" example:
> **Recommended Event:** Intro to Robotics Workshop  
> **Why am I seeing this?** You attended 2 events hosted by the Robotics Club in the last 12 months, and you are a member of the Engineering Student Society.

* **Published Ranking Inputs:** The clubs office will publish a summary explaining that the 5 slots use three rules: past attendance in the last 12 months (40% weight), active club memberships (40%), and exploration slots for smaller/unvisited clubs (20%). No black-box machine learning models or third-party AI APIs are used.

## 5. Opt-out design

* **Switch Location & Default:** **Opt-in, off by default** to satisfy privacy-by-design. Located at `My profile > Privacy & Personalisation > Recommendations switch`.
* **Derived Data Handling:** When switched off, the consent flag is revoked, all derived preference profiles are permanently deleted within **24 hours**, and the feed reverts to the non-personalised baseline.

~~~mermaid
flowchart TD
  A["My profile: Recommendations switch"] --> B{"Switched off?"}
  B -- Yes --> C["Revoke recommendation consent flag"]
  C --> D["Delete derived student profile within 24 hours"]
  D --> E["Serve non-personalised baseline (Popular & My Clubs)"]
  B -- No --> F["Generate 5 explainable event recommendations"]
~~~

## 6. Recommendation
Decision: GO WITH CONDITIONS, not before Sprint 2, and only after the baseline
has been live for one month.
<br>
Conditions:
 1. Opt-in, off by default; switching off deletes the student's derived profile
    within 24 hours.
 2. Uses only attendance of the last 12 months and club memberships; no phone,
    no email, no free-text data.
 3. At least 2 of the 5 slots show events from clubs the student has never
    attended (exploration against the feedback loop).
 4. Monthly exposure check: clubs with fewer than 20 members receive at least
    80 % of their fair share of recommendations; owner: clubs office.