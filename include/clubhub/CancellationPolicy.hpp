// include/clubhub/CancellationPolicy.hpp
#pragma once
#include <chrono>

namespace clubhub {
// REQ-12: cancellation closes 24 hours before the start of the event.
[[nodiscard]] constexpr bool canCancel(std::chrono::sys_seconds now,
                                       std::chrono::sys_seconds start) {
    using namespace std::chrono_literals;
    // TODO: confirm with the client that "exactly 24 h" is still allowed
    return start - now >= 24h;
}
}  // namespace clubhub