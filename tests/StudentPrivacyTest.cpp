// tests/StudentPrivacyTest.cpp
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 <team name>, ITC Club Hub contributors
#include "clubhub/Student.h"

#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

using clubhub::maskId;
using clubhub::Student;

// Invented test data only: never real students.
TEST(StudentPrivacy, RedactedHidesPersonalData) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("012 345 678");
    const std::string r = s.redacted();
    EXPECT_EQ(r, "Student{id=e2******7}");
    EXPECT_EQ(r.find("Test"), std::string::npos);
    EXPECT_EQ(r.find("example.edu"), std::string::npos);
    EXPECT_EQ(r.find("345"), std::string::npos);
}

TEST(StudentPrivacy, OptionalConsentsStartOff) {
    const Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_FALSE(s.phone().has_value());  // no SMS consent given yet
}

TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("+855 12 345 678");
    ASSERT_TRUE(s.phone().has_value());
    EXPECT_EQ(*s.phone(), "+855 12 345 678");
    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student{"e20990417", "A", "no-at-sign"}),
                 std::invalid_argument);
}

TEST(StudentPrivacy, RejectsPhoneWithLetters) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_THROW(s.giveSmsConsent("012 abc 678"), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());

    // A rejected number must leave an earlier valid number untouched.
    s.giveSmsConsent("012 345 678");
    EXPECT_THROW(s.giveSmsConsent("call me"), std::invalid_argument);
    ASSERT_TRUE(s.phone().has_value());
    EXPECT_EQ(*s.phone(), "012 345 678");
}

TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) {
    EXPECT_EQ(maskId("abc"), "***");
    EXPECT_EQ(maskId("ab"), "**");
    EXPECT_EQ(maskId("a"), "*");
    EXPECT_EQ(maskId(""), "");
    EXPECT_EQ(maskId("e20990417"), "e2******7");
}

TEST(StudentPrivacy, RejectsEmptyIdOrName) {
    EXPECT_THROW((Student{"", "A", "a@example.edu"}), std::invalid_argument);
    EXPECT_THROW((Student{"e20990417", "", "a@example.edu"}),
                 std::invalid_argument);
}