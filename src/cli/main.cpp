#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "clubhub/event.hpp"
#include "clubhub/event_csv.hpp"

namespace {

int listEvents(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "error: could not open file " << path << '\n';
        return 1;
    }

    auto result = clubhub::loadEventsCsv(file);

    // Sort events chronologically by start time
    std::sort(result.events.begin(), result.events.end(), [](const auto& a, const auto& b) {
        return a.start() < b.start();
    });

    // Print successfully loaded events
    std::cout << "--- ITC Club Hub Events ---\n";
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(25) << "Title"
              << std::setw(20) << "Start Time"
              << std::setw(15) << "Location"
              << std::setw(10) << "Capacity" << '\n';
    std::cout << std::string(80, '-') << '\n';

    for (const auto& event : result.events) {
        std::cout << std::left << std::setw(10) << event.id()
                  << std::setw(25) << event.title()
                  << std::setw(20) << clubhub::formatTimePoint(event.start())
                  << std::setw(15) << event.location()
                  << std::setw(10) << event.capacity() << '\n';
    }

    // Print any parsing errors encountered
    if (!result.errors.empty()) {
        std::cerr << "\nWarnings/Errors encountered during loading:\n";
        for (const auto& err : result.errors) {
            std::cerr << "Line " << err.line << ": " << err.message << '\n';
        }
    }

    return 0;
}

void printUsage() {
    std::cerr << "usage: clubhub list-events [events.csv]\n";
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 2;
    }
    const std::string command{argv[1]};
    if (command == "list-events") {
        return listEvents(argc > 2 ? argv[2] : "data/events.csv");
    }
    std::cerr << "unknown command: " << command << '\n';
    printUsage();
    return 2;
}