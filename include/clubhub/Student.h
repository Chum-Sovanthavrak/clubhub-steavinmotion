// include/clubhub/Student.h
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SteavInMotion, ITC Club Hub contributors
#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace clubhub {

// Stores only the fields allowed by lab03/data-inventory.md.
class Student {
public:
    // Throws std::invalid_argument for an empty id or name,
    // or an email without '@'.
    Student(std::string id, std::string name, std::string email);

    const std::string& id() const noexcept { return id_; }
    const std::string& name() const noexcept { return name_; }
    const std::string& email() const noexcept { return email_; }
    const std::optional<std::string>& phone() const noexcept {
        return phone_;
    }

    // Consent is explicit, separate and can be withdrawn.
    // Throws std::invalid_argument if the number is empty or contains
    // anything except digits, '+' and ' '. On error the old state is kept.
    void giveSmsConsent(std::string phone);
    // Erases the stored number.
    void withdrawSmsConsent() noexcept;

    // Safe for logs: "Student{id=e2******7}", nothing else.
    std::string redacted() const;

private:
    std::string id_;
    std::string name_;
    std::string email_;
    std::optional<std::string> phone_;  // only with SMS consent
    // Add a member ONLY if it has a Keep row in the inventory.
};

// "e20990417" -> "e2******7"; 3 characters or fewer -> all '*'
std::string maskId(std::string_view id);

}  // namespace clubhub