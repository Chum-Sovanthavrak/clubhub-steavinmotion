// src/ConsoleOutput.cpp
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 <Steavinmotions>, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"

#include <cstdlib>

namespace clubhub {

std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered: return "REGISTERED";
        case RegistrationStatus::Cancelled:  return "CANCELLED";
        case RegistrationStatus::CheckedIn:  return "CHECKED IN";
        case RegistrationStatus::Waitlisted: return "WAITLISTED";
    }
    return "UNKNOWN";  // unreachable unless the enum grows
}

bool colourEnabled(bool noColorFlag) {
    if (noColorFlag) {
        return false;
    }
    // getenv returns nullptr when the variable does not exist.
    // (MSVC warns C4996 here; it is safe to ignore in this lab.)
    return std::getenv("NO_COLOR") == nullptr;
}

std::string formatStatus(RegistrationStatus s, bool colour) {
    // The word is ALWAYS present; colour only repeats it.
    std::string text = "[" + std::string(statusLabel(s)) + "]";
    if (!colour) {
        return text;
    }

    const char* code = "\x1b[0m";
    switch (s) {
        case RegistrationStatus::Registered: code = "\x1b[32m"; break;  // green
        case RegistrationStatus::Cancelled:  code = "\x1b[31m"; break;  // red
        case RegistrationStatus::CheckedIn:  code = "\x1b[32m"; break;  // green
        case RegistrationStatus::Waitlisted: code = "\x1b[33m"; break;  // yellow
    }
    return std::string(code) + text + "\x1b[0m";
}

std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next) {
    std::string out = "Error: ";
    out += what;
    out += ": ";
    out += why;
    out += ".\nNext step: ";
    out += next;
    return out;
}

}  // namespace clubhub