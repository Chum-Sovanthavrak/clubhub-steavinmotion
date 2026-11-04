cmake_minimum_required(VERSION 3.28)
project(clubhub LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(clubhub_core src/event.cpp src/event_csv.cpp)
target_include_directories(clubhub_core PUBLIC include)

add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)