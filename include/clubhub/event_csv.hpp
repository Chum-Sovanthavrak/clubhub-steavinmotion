#pragma once
#include <istream>
#include <string>
#include <vector>
#include "clubhub/event.hpp"

namespace clubhub {

struct CsvError {
    int line;
    std::string message;
};

struct EventLoadResult {
    std::vector<Event> events;
    std::vector<CsvError> errors;
};

EventLoadResult loadEventsCsv(std::istream& in);

} // namespace clubhub