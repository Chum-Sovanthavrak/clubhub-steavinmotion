// src/Student.cpp
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 <team name>, ITC Club Hub contributors
#include "clubhub/Student.h"

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <utility>

namespace clubhub {

// Error messages never contain the rejected value: it may be personal data.
Student::Student(std::string id, std::string name, std::string email)
    : id_(std::move(id)), name_(std::move(name)), email_(std::move(email)) {
    if (id_.empty()) {
        throw std::invalid_argument("student id must not be empty");
    }
    if (name_.empty()) {
        throw std::invalid_argument("student name must not be empty");
    }
    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("student email must contain '@'");
    }
}

void Student::giveSmsConsent(std::string phone) {
    // Validate first, so a rejected number leaves the old state untouched.
    const bool onlyAllowedChars = std::all_of(
        phone.begin(), phone.end(), [](char c) {
            const auto u = static_cast<unsigned char>(c);
            return (u >= '0' && u <= '9') || u == '+' || u == ' ';
        });
    const bool hasDigit = std::any_of(phone.begin(), phone.end(), [](char c) {
        return c >= '0' && c <= '9';
    });
    if (!onlyAllowedChars || !hasDigit) {
        throw std::invalid_argument(
            "phone must contain digits, '+' and spaces only");
    }
    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept { phone_.reset(); }

std::string Student::redacted() const {
    return "Student{id=" + maskId(id_) + "}";
}

std::string maskId(std::string_view id) {
    if (id.size() <= 3) {
        return std::string(id.size(), '*');
    }
    std::string masked(id);
    // Keep the first two and the last character.
    for (std::size_t i = 2; i + 1 < masked.size(); ++i) {
        masked[i] = '*';
    }
    return masked;
}

}  // namespace clubhub