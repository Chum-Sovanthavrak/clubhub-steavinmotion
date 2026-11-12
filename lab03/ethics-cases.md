# Ethics case analyses · ITC Club Hub
Version 1.0 · 2026-11-12 · Leads: A = Chum-Sovanthavrak, B = Ty-Vannavuth

## Scenario A: "Just a small report"

| Step | Analysis |
|------|----------|
| 1. Facts | **Facts:** The Robotics Club leader wants a cross-club attendee report visible only to club leaders to recruit active members from other clubs. The administrator supposedly "won't mind".<br>**Needs clarification:** Did students consent to cross-club tracking in the privacy policy? Is cross-club data sharing authorized under institutional policy? |
| 2. Stakeholders and harms | **Stakeholders:** Students attending club events, Robotics Club leaders, other club leaders, administrators, developers.<br>**Harms:** Violation of student privacy and expectations, function creep (data collected for attendance used for targeted recruitment), potential inter-club hostility, and breach of trust regarding data handling. |
| 3. Codes, law, policy | • **SE Code:** Principle 3.09 (Ensure proper and inclusive documentation) & 1.03 (Approve software only if they have a well-founded belief that it is safe, meets specifications, passes tests, and does not degrade quality of life, privacy or security).<br>• **ACM Code:** 1.2 (Avoid harm) and 1.6 (Respect privacy).<br>• **GDPR / Privacy:** Article 5(1)(b) (Purpose limitation — data collected for one purpose cannot be repurposed without explicit consent). |
| 4. Options | (a) Build the cross-club report as requested and give club leaders access.<br>(b) Refuse outright without explanation or alternative.<br>(c) Reject cross-club targeting, but provide an aggregate, anonymous popularity metric or suggest public general announcements via the normal event list. |
| 5. Tests | • **Harm test:** (a) causes privacy harm and function creep; (b) harms stakeholder relations without offering solutions; (c) avoids privacy violations while supporting outreach.<br>• **Rights test:** (a) violates student privacy rights; (c) respects data minimization and consent rights.<br>• **Fairness test:** (a) gives one club an unfair recruiting advantage using private data.<br>• **Publicity test:** (a) would look bad if published on campus news ("Club Hub secretly tracks which clubs you visit for rival recruiting"). |
| 6. Decision and action | **Decision:** Option (c). Reject the cross-club targeted member report. Propose aggregate stats or public announcements instead. Send the refusal message to the club leader and open a GitHub issue to enforce strict data isolation per club. |
| 7. Reflection | Developers must guard against administrative shortcuts and informal approvals ("administrator won't mind"). Technical convenience or a leader's charm does not override data privacy laws and ethical codes. |

**Message sent:** 
Hi Phorst Chan Sereywattana,

Thank you for reaching out with your recruitment idea. While we understand you want to grow the Robotics Club, our privacy policy and data governance rules restrict cross-club attendance tracking. Student attendance data is collected solely for individual club event management and fire safety/capacity limits, and repurposing it for targeted cross-club recruiting violates student privacy expectations and GDPR purpose limitation. 

Instead, we invite you to promote your open events through the public campus event list or coordinate joint showcases where students can opt-in to hear from multiple clubs. We'd be happy to help you set up public announcements!

Best regards,  
Chum Sovanthavrak/Team SteavInMotion

**Preventive change:** Implement strict club-scoped data isolation queries and database row-level security so club leaders can only query attendance for their own club's events. GitHub Issue #6.

## Scenario B: "Don't mention it in the demo"

| Step | Analysis |
|------|----------|
| 1. Facts | Facts: Two days before Sprint 1 review, a bug allows 24-hour window cancellations to be accepted, and monthly reports incorrectly count cancellations as attendance. The Scrum Master tells the developer to stay silent and fix it in Sprint 2.<br>Needs clarification: Can the bug be fixed safely before Thursday? Will the client actually check this report during the review? |
| 2. Stakeholders and harms | Stakeholders: The client/product owner, end-user students, development team, Scrum Master.<br>Harms: Loss of client trust, compromised software integrity, spreading misinformation in reports, and establishing a dishonest team culture. |
| 3. Codes, law, policy | • SE Code: Principle 3.04 (Ensure that quality is paramount...) & 6.12 (Be accurate and honest in all professional reports).<br>• ACM Code: 1.3 (Be honest and trustworthy) and 2.5 (Give comprehensive and thorough evaluations).<br>• Professional Integrity: Transparency in agile delivery over deceptive demos. |
| 4. Options | (a) Stay silent as instructed by the Scrum Master.<br>(b) Postpone the entire review until Sprint 2.<br>(c) Demo as planned and explicitly state the defect and its planned fix date under a "known issues" section.<br>(d) Fix the rule in the next two days and drop a lower-priority item from the demo if time is tight. |
| 5. Tests | • Harm test: (a) Risks severe client mistrust upon discovery; (c) and (d) maintain transparency and manage expectations.<br>• Rights test: Client has a right to truthful software evaluation and accurate metrics.<br>• Fairness test: Hiding known defects shifts the risk and surprise onto the client.<br>• Publicity test: Would you be proud to explain to management why you hid known calculation errors during a client review? No. |
| 6. Decision and action | Decision: Option (c), combined with Option (d) if the regression test is green by Thursday. The developer raises the issue respectfully with the Scrum Master (SE Code 6.12), ensuring transparency is brought to the Product Owner before the review agenda is finalized. |
| 7. Reflection | Pressure to deliver a flawless demo can compromise ethical transparency. True agile engineering embraces open collaboration and honest reporting of defects rather than hiding behind false perfection. |

Message sent: 
Hi Chum Sovanthavrak,

I've reviewed the cancellation and attendance counting bug we discussed. While I understand we want a smooth Sprint 1 demo, staying silent violates our professional commitment to honesty and risks damaging client trust if they inspect the reports. 

I propose we add this item to the "Known Issues" section for Thursday's review and present our planned fix for Sprint 2. If time permits, I'll attempt to patch the regression test today. Transparency now will build stronger client confidence in the long run.

Thanks,  
Ty Vannavuth / Team SteavInMotion

Preventive change: Establish a formal "Known Issues & Defect Disclosure" section template for all sprint reviews and add an automated regression test covering the 24-hour cancellation rule. GitHub Issue #7.