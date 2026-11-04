// include/clubhub/event.hpp
#pragma once
#include <chrono>
#include <string>

namespace clubhub {

// Minute precision is enough for club events. Times are ITC local
// time (Asia/Phnom_Penh); this lab does no time-zone conversion.
using TimePoint = std::chrono::sys_time<std::chrono::minutes>;

class Event {
public:
    // Throws std::invalid_argument when a field breaks a rule.
    Event(std::string id, std::string title, TimePoint start,
          std::string location, int capacity);

    const std::string& id() const noexcept { return id_; }
    const std::string& title() const noexcept { return title_; }
    TimePoint start() const noexcept { return start_; }
    const std::string& location() const noexcept { return location_; }
    int capacity() const noexcept { return capacity_; }

    // Business rule: events in the past cannot be registered for.
    bool hasStarted(TimePoint now) const noexcept { return start_ <= now; }

private:
    std::string id_;
    std::string title_;
    TimePoint start_;
    std::string location_;
    int capacity_;
};

// "2026-10-14 14:00" -> TimePoint; throws std::invalid_argument
TimePoint parseTimePoint(const std::string& text);

// TimePoint -> "2026-10-14 14:00"
std::string formatTimePoint(TimePoint t);

} // namespace clubhub

// include/clubhub/event_csv.hpp
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

// Reads "id,title,start,location,capacity" rows after one header line.
// A bad row goes to errors; the good rows are still returned.
EventLoadResult loadEventsCsv(std::istream& in);

} // namespace clubhub