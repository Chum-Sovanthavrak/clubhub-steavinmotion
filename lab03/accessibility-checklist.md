# Accessibility checklist · ITC Club Hub (planned web and mobile UI)
Target: WCAG 2.2 level AA · Version 1.0 · 2026-11-12 · Authors: Phorst Chan Sereywattana

| SC | Name | Level | Screen | How we meet it | How we test it |
|----|------|-------|--------|----------------|----------------|
| 1.1.1 | Non-text Content | A | event list | Club logos have alt text with the club name | Screen reader reads the club name |
| 1.4.1 | Use of Color | A | event list | Status badge shows text "Full" / "Cancelled", not just colour | View in greyscale |
| 1.4.3 | Contrast (Minimum) | AA | all screens | Text 4.5:1, large text and UI 3:1 | WebAIM Contrast Checker |
| 1.4.4 | Resize Text | AA | registration form | Layout uses relative units | Zoom to 200 %, nothing is cut off |
| 2.1.1 | Keyboard | A | registration form | Every control reachable and usable with Tab/Enter | Unplug the mouse and complete a registration |
| 2.4.7 | Focus Visible | AA | event list | Visible focus outline on cards and buttons | Tab through the page |
| 2.4.11 | Focus Not Obscured (Minimum) | AA | registration form | Sticky header never covers the focused field | Tab to the last field, check it is visible |
| 2.5.7 | Dragging Movements | AA | event list | Re-ordering/filtering has buttons, no drag-only action | Complete every task with taps/clicks only |
| 2.5.8 | Target Size (Minimum) | AA | registration form | Buttons at least 24×24 CSS px | Measure in browser dev tools; test on a phone |
| 3.2.6 | Consistent Help | A | all screens | "Contact clubs office" link in the same footer place | Compare footer on three screens |
| 3.3.1 | Error Identification | A | registration form | Error text names the field and the problem | Submit an empty form |
| 3.3.7 | Redundant Entry | A | registration form | Name/email prefilled from the profile | Register for two events; nothing is retyped |
| 3.3.8 | Accessible Authentication (Minimum) | AA | login | Password paste allowed; no puzzle or memory test | Log in using a password manager |
| 4.1.2 | Name, Role, Value | A | registration form | Inputs have labels; buttons have names | Screen reader (NVDA / TalkBack) announces each control |

## Screen decisions and contrast

### Event list
1. Status shown as text ("Full", "Cancelled") plus colour.
2. Each event card is reachable and openable with the keyboard.
3. Dates written as `2026-10-14 17:30`.

### Registration form
1. Every field has a visible label and a clear error message.
2. Optional consents (email/SMS) are separate checkboxes, off by default.
3. Submit button is at least 44×44 px with a visible focus outline.

| Pair | Foreground | Background | Ratio | Needed | Result |
|------|-----------|------------|-------|--------|--------|
| Body text | #111827 | #FFFFFF | ≈ 17.7:1 | 4.5:1 | Pass |
| Button text | #FFFFFF | #0B5ED7 | ≈ 5.8:1 | 4.5:1 | Pass |