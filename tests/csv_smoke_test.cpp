// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team SteavInMotion, ITC Club Hub contributors
// tests/csv_smoke_test.cpp
// Proves that the reused CSV library is fetched, built and linked.
#include <gtest/gtest.h>
#include <rapidcsv.h>

#include <string>
#include <vector>

TEST(CsvSmokeTest, ReadsEventTitlesAndCapacities) {
    // the path is relative to WORKING_DIRECTORY (the repository root)
    rapidcsv::Document doc("tests/data/events.csv");

    const std::vector<std::string> titles =
        doc.GetColumn<std::string>("title");
    const std::vector<int> capacities = doc.GetColumn<int>("capacity");

    ASSERT_EQ(titles.size(), 2U);
    EXPECT_EQ(titles.at(0), "Robotics Workshop");
    EXPECT_EQ(capacities.at(1), 30);
}