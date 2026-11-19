// include/clubhub/banner.hpp
#pragma once

#include <string>
#include <string_view>

namespace clubhub {

// The team name printed at start-up.
inline constexpr std::string_view kTeamName = "SteavInMotion";

// Returns the start-up banner, one line per row, ending in '\n'.
[[nodiscard]] std::string banner(std::string_view teamName);

} // namespace clubhub