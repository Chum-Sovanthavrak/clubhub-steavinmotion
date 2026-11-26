// tests/cancellation_rule_test.cpp · UT-12 verifies REQ-12 (module level)
#include <gtest/gtest.h>
#include "clubhub/CancellationPolicy.hpp"

using namespace std::chrono;
using clubhub::canCancel;

namespace {
// Robotics Workshop starts on 2026-11-07 at 14:00 (UTC)
constexpr sys_seconds kStart = sys_days{2026y / November / 7} + 14h;
}  // namespace

TEST(CancellationPolicyTest, AllowsExactly24HoursBefore) {
    EXPECT_TRUE(canCancel(kStart - 24h, kStart));
}

TEST(CancellationPolicyTest, RejectsOneSecondTooLate) {
    EXPECT_FALSE(canCancel(kStart - 24h + 1s, kStart));
}

TEST(CancellationPolicyTest, AllowsOneWeekBefore) {
    EXPECT_TRUE(canCancel(kStart - 168h, kStart));
}

TEST(CancellationPolicyTest, RejectsAfterStart) {
    EXPECT_FALSE(canCancel(kStart + 1h, kStart));
}