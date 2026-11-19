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

    // Header row expected by lab specification
    std::cout << std::left << std::setw(18) << "START"
              << std::setw(22) << "TITLE"
              << std::setw(13) << "LOCATION"
              << "CAPACITY\n";

    // Data rows
    for (const auto& event : result.events) {
        std::cout << std::left << std::setw(18) << clubhub::formatTimePoint(event.start())
                  << std::setw(22) << event.title()
                  << std::setw(13) << event.location()
                  << event.capacity() << '\n';
    }

    // Event count summary line
    std::cout << result.events.size() << " event(s)\n";

    // Print errors/warnings to stderr if any exist
    if (!result.errors.empty()) {
        for (const auto& err : result.errors) {
            std::cerr << "Line " << err.line << ": " << err.message << '\n';
        }
    }

    return 1;
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