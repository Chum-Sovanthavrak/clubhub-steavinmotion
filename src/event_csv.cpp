#include "clubhub/event_csv.hpp"
#include <sstream>
#include <stdexcept>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;

    // Skip CSV header line if present
    if (!std::getline(in, line)) {
        return result;
    }

    while (std::getline(in, line)) {
        ++lineNo;
        
        // Strip trailing carriage return if line has Windows CRLF line endings
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string id, title, startStr, location, capacityStr;

        if (!std::getline(ss, id, ',') ||
            !std::getline(ss, title, ',') ||
            !std::getline(ss, startStr, ',') ||
            !std::getline(ss, location, ',') ||
            !std::getline(ss, capacityStr, ',')) {
            result.errors.push_back({lineNo, "Invalid CSV format: missing required columns"});
            continue;
        }

        try {
            int capacity = std::stoi(capacityStr);
            TimePoint start = parseTimePoint(startStr);
            result.events.emplace_back(id, title, start, location, capacity);
        } catch (const std::exception& ex) {
            result.errors.push_back({lineNo, ex.what()});
        }
    }

    return result;
}

} // namespace clubhub