#pragma once

#include <chrono>
#include <optional>
#include <string>
#include <vector>

namespace clubhub {

enum class SyncState { Pending, Sent, Accepted, Rejected };

// One check-in recorded on an organiser's phone while offline.
struct QueuedCheckIn {
    std::string localId;    // Idempotency key: unique UUID generated on device per scan
    std::string deviceId;   // Identifies which organiser's phone recorded the check-in
    std::string eventId;    // The event being checked into
    std::string studentId;  // The student being checked in
    std::chrono::sys_seconds scannedAt; // Device clock timestamp
    SyncState state{SyncState::Pending};
    std::optional<std::string> rejectReason; // Reason if rejected by server
};

/*
 * EXPLANATION OF IDEMPOTENCY:
 * The `localId` UUID acts as the idempotency key[cite: 7]. Because network timeouts 
 * can cause an HTTP POST request to be retried even when the server successfully 
 * applied it on the first attempt, the server tracks a set of already-applied 
 * localIds[cite: 3, 7]. When a retry arrives with a duplicate localId, the server safely 
 * returns "accepted" without creating a duplicate database record[cite: 3, 7].
 */

class CheckInQueue {
public:
    // false if this student is already queued for this event
    bool enqueue(QueuedCheckIn item) {
        for (const auto& existing : items_) {
            if (existing.eventId == item.eventId && existing.studentId == item.studentId) {
                return false;
            }
        }
        items_.push_back(std::move(item));
        return true;
    }

    // oldest first; what the next sync attempt uploads
    std::vector<QueuedCheckIn> pending() const {
        std::vector<QueuedCheckIn> result;
        for (const auto& item : items_) {
            if (item.state == SyncState::Pending) {
                result.push_back(item);
            }
        }
        return result;
    }

    void markAccepted(const std::string& localId) {
        for (auto& item : items_) {
            if (item.localId == localId) {
                item.state = SyncState::Accepted;
            }
        }
    }

    void markRejected(const std::string& localId, std::string reason) {
        for (auto& item : items_) {
            if (item.localId == localId) {
                item.state = SyncState::Rejected;
                item.rejectReason = std::move(reason);
            }
        }
    }

private:
    std::vector<QueuedCheckIn> items_;
};

} // namespace clubhub