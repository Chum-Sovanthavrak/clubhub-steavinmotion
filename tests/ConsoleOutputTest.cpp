// tests/ConsoleOutputTest.cpp
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SteavInMotion, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"

#include <gtest/gtest.h>

#include <string>

using clubhub::colourEnabled;
using clubhub::formatError;
using clubhub::formatStatus;
using clubhub::RegistrationStatus;
using clubhub::statusLabel;

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    EXPECT_EQ(formatStatus(RegistrationStatus::Cancelled, false), "[CANCELLED]");
    EXPECT_EQ(formatStatus(RegistrationStatus::CheckedIn, false), "[CHECKED IN]");
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheWord) {
    const std::string out = formatStatus(RegistrationStatus::Cancelled, true);
    EXPECT_NE(out.find("[CANCELLED]"), std::string::npos);  // word still there
    EXPECT_NE(out.find("\x1b["), std::string::npos);        // colour added
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    const std::string e = formatError("cannot register for E-017",
                                      "the event is full (40 of 40 seats)",
                                      "clubhub waitlist E-017");
    EXPECT_EQ(e,
              "Error: cannot register for E-017: the event is full "
              "(40 of 40 seats).\nNext step: clubhub waitlist E-017");
    EXPECT_NE(e.find("Next step:"), std::string::npos);
}

TEST(ConsoleOutput, NoColorFlagDisablesColour) {
    EXPECT_FALSE(colourEnabled(true));
}

TEST(ConsoleOutput, EveryStatusHasAUniqueWord) {
    EXPECT_EQ(statusLabel(RegistrationStatus::Registered), "REGISTERED");
    EXPECT_EQ(statusLabel(RegistrationStatus::Cancelled), "CANCELLED");
    EXPECT_EQ(statusLabel(RegistrationStatus::CheckedIn), "CHECKED IN");
    EXPECT_EQ(statusLabel(RegistrationStatus::Waitlisted), "WAITLISTED");
}