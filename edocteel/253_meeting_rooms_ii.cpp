#include <bits/stdc++.h>
using namespace std;

class MeetingRoomsII253 {
public:

    // Function to determine the minimum number of meeting rooms required
    //
    // Time Complexity: O(N log N), where N is the number of intervals
    // Space Complexity: O(N)
    int minMeetingRooms(const vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        vector<pair<int, char>> events;
        for (const auto& interval : intervals) {
            events.emplace_back(interval[0], 's'); // start event
            events.emplace_back(interval[1], 'e'); // end event
        }

        sort(events.begin(), events.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            if (a.first == b.first) return a.second < b.second; // end event before start event
            return a.first < b.first;
        });

        int currentRooms = 0;
        int maxRooms = 0;
        for (const auto& event : events) {
            if (event.second == 's') {
                currentRooms++;
                maxRooms = max(maxRooms, currentRooms);
            } else {
                currentRooms--;
            }
        }
        return maxRooms;
    }
};