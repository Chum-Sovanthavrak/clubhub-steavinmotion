cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.4.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(clubhub_core
  src/event.cpp
  src/event_csv.cpp
  src/Student.cpp
  src/ConsoleOutput.cpp)
target_include_directories(clubhub_core PUBLIC include)

add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)

include(FetchContent)

# Reuse 1: GoogleTest v1.15.2 (BSD-3-Clause), unit-test framework (from Lab-03).
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
# Windows/MSVC: use the same runtime library as the project
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Reuse 2: rapidcsv v9.07 (BSD-3-Clause), header-only CSV reader.
FetchContent_Declare(rapidcsv
  GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
  GIT_TAG        v9.07
  GIT_SHALLOW    TRUE)

FetchContent_MakeAvailable(googletest rapidcsv)

enable_testing()
include(GoogleTest)

add_executable(clubhub_tests
  tests/StudentPrivacyTest.cpp
  tests/ConsoleOutputTest.cpp)
target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)
gtest_discover_tests(clubhub_tests)

# Smoke test: proves that the reused library is fetched, built and linked
add_executable(csv_smoke_test tests/csv_smoke_test.cpp)
target_link_libraries(csv_smoke_test PRIVATE rapidcsv GTest::gtest_main)
gtest_discover_tests(csv_smoke_test
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})