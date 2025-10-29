#include "tennis_bookings.h"
using namespace std;

vector<Court> TennisBooking::assignCourts(const vector<BookingRecord>& bookingRecords) {
    // Pair of (time, ['s, 'f'])
    vector<tuple<int, char, int>> bookingTimes;
    for (auto record: bookingRecords) {
        bookingTimes.push_back({record.getStartTime(), 's', record.getBookingId()});
        bookingTimes.push_back({record.getFinishTime(), 'f', record.getBookingId()});
    }

    // Sort Times {time, type_of_event}
    sort(bookingTimes.begin(), bookingTimes.end(), 
        [](const auto& booking1, const auto& booking2){
            if (get<0>(booking1) != get<0>(booking2)) 
                return get<0>(booking1) < get<0>(booking2);
            return get<1>(booking1)> get<1>(booking2); // 'f' before 's'
        });

    
    int currentCount = -1;
    unordered_map<int, int> courtIdByBookingId;
    unordered_set<int> availableCourtIds;
    for (auto [time, eventType, bookingId]: bookingTimes) {
        if (eventType == 's') {
            ++currentCount;
            if (availableCourtIds.empty()) {
                courtIdByBookingId[bookingId] = currentCount;
            } else {
                int courtId = *availableCourtIds.begin();
                courtIdByBookingId[bookingId] = courtId;
                availableCourtIds.erase(courtId);
            }
        } else {
            // a booking has ended
            int releasedCourtId = courtIdByBookingId[bookingId];
            availableCourtIds.insert(releasedCourtId);
        }
    }

    // Create Courts map by courtId
    unordered_map<int, Court> courts;
    for (auto [bookingId, courtId]: courtIdByBookingId) {
        if (courts.find(courtId) == courts.end()) {
            
        }
    }

    // Minimum courts needed would be currentCount = sizeof(courts)
}

/*
* BookingRecords
*  0) 2 8
*  1) 5 6
*  2) 7 9
* BookingTimes// bookingId -> CourtID
*  {2, s, 0}  // 0 -> 0 (current)
*  {5, s, 1}  // 1 -> 1
*  {6, f, 1}  // available (1) 
*  {7, s, 2}  // 2 -> 1
*  {8, f, 0}
*  {9, f, 2}
*/