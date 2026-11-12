// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SteavInMotion, ITC Club Hub contributors
#include "clubhub/event.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace clubhub {

Event::Event(std::string id, std::string title, TimePoint start,
             std::string location, int capacity)
    : id_{std::move(id)}, title_{std::move(title)}, start_{start},
      location_{std::move(location)}, capacity_{capacity} {
    if (id_.empty()) {
        throw std::invalid_argument("Event ID cannot be empty");
    }
    if (title_.empty()) {
        throw std::invalid_argument("Event title cannot be empty");
    }
    if (capacity_ <= 0) {
        throw std::invalid_argument("Capacity must be positive");
    }
}

TimePoint parseTimePoint(const std::string& text) {
    using namespace std::chrono;
    std::istringstream in{text};
    int y{}, mo{}, d{}, h{}, mi{};
    char dash1{}, dash2{}, colon{};
    
    in >> y >> dash1 >> mo >> dash2 >> d >> h >> colon >> mi;
    
    if (!in || dash1 != '-' || dash2 != '-' || colon != ':') {
        throw std::invalid_argument("Invalid time format, expected YYYY-MM-DD HH:MM");
    }
    
    const year year_val{y};
    const month month_val{static_cast<unsigned>(mo)};
    const day day_val{static_cast<unsigned>(d)};
    
    const year_month_day ymd{year_val, month_val, day_val};
    if (!ymd.ok()) {
        throw std::invalid_argument("Invalid calendar date");
    }
    
    if (h < 0 || h > 23 || mi < 0 || mi > 59) {
        throw std::invalid_argument("Invalid hour or minute values");
    }
    
    return sys_days{ymd} + hours{h} + minutes{mi};
}

std::string formatTimePoint(TimePoint t) {
    using namespace std::chrono;
    const auto midnight = floor<days>(t);
    const year_month_day date{midnight};
    const hh_mm_ss time{t - midnight};
    std::ostringstream out;
    out << std::setfill('0') << static_cast<int>(date.year()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.month()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.day()) << ' '
        << std::setw(2) << time.hours().count() << ':'
        << std::setw(2) << time.minutes().count();
    return out.str();
}

} // namespace clubhub