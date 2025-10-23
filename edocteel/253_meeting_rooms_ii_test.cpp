#include "253_meeting_rooms_ii.cpp"
using namespace std;

class MeetingRoomsII253Test : public MeetingRoomsII253 {
public:
    int runTest(vector<vector<int>>& intervals) {
        return minMeetingRooms(intervals);
    }

    void runTests() {
        vector<pair<vector<vector<int>>, int>> cases;

        cases = {
            {{ {0,30}, {5,10}, {15,20} }, 2},
            {{ {7,10}, {2,4} }, 1},
            {{ {1,5}, {2,6}, {3,7}, {4,8} }, 4},
            {{}, 0}, // empty intervals
            {{ {1,1}, {2,2}, {3,3} }, 0}, // zero-length intervals
            {{ {1,2}, {2,3}, {3,4} }, 1}
        };

        for (auto& testCase : cases) {
            vector<vector<int>>& intervals = testCase.first;
            int expected = testCase.second;
            int result = runTest(intervals);
            printf("Intervals: ");
            for (const auto& interval : intervals) {
                printf("[%d,%d] ", interval[0], interval[1]);
            }
            printf("\n=> Expected: %d, Got: %d\n\n", expected, result);
            assert(result == expected);
        }
        printf("All sample test cases passed!\n");
    }

    void loadTest() {
        srand(time(0));
        vector<vector<int>> largeIntervals;
        const int N = 1e5 + 3;
        for (int i = 0; i < N; ++i) {
            int start = rand() % 100003;
            int end = start + (rand() % 1000) + 1; // ensure end > start
            largeIntervals.push_back({start, end});
        }

        int result = runTest(largeIntervals);
        printf("\nLarge test with %d intervals => Minimum Meeting Rooms: %d\n", N, result);
    }
};

int main() {
    MeetingRoomsII253Test test;
    test.runTests();
    test.loadTest();
    return 0;
}