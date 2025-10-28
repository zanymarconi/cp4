#include "875_koko_eating_bananas.cpp"
using namespace std;

class KokoBananas875Test: public KokoBananas875 {
public:
    void runTests() {
        string line;
        istringstream iss(scenarios);
        int testCase = 0, size;
        while(iss >> size) {
            vector<int> piles;
            int pile;
            while (size > 0) { 
                iss >> pile;
                piles.push_back(pile);
                --size;
            }
            int hoursAvailable, expectedMinSpeed;
            iss >> hoursAvailable >> expectedMinSpeed;
            int calculatedSpeed = minEatingSpeed(piles, hoursAvailable);

            // Debugging
            // printf("Piles: "); for (auto p: piles) printf("%d ", p); 
            // printf("\nHours Available: %d\n", hoursAvailable);
            // printf("Actual %d and expected %d\n", calculatedSpeed, expectedMinSpeed);

            printf("Test %d: %s\n", ++testCase, 
                (expectedMinSpeed == calculatedSpeed)? "PASS": "FAIL");
            assert(expectedMinSpeed == calculatedSpeed);
        }
        printf("All Tests Scenarios Passed!\n\n");
    }

    // N * log(MAX(pile))
    void loadTest() {
        int size = 1e6 + 3;
        int pileMax = 1e9 + 7;
        vector<int> piles(size);
        for (int i = 0; i < size; ++i)
            piles[i] = pileMax % size;
        int hoursAvailable = size + rand() % size;
        int calculatedSpeed = minEatingSpeed(piles, hoursAvailable);

        printf("Calculated speed %d for %d banans in %d hours\n", 
            calculatedSpeed, size, hoursAvailable);
            printf("Load Test Passed!\n");
        assert(calculatedSpeed == 997010); // MAGIC!
    }

private:
    string scenarios = R"(
        1
        312884470
        312884469
        2

        3
        2 0 4
        3
        2

        4
        3 6 7 11
        4
        11

        4
        3 6 7 11
        6
        6

        4
        3 6 7 11
        8
        4

        0
        42
        0

        2
        1 1
        1
        -1
    )";
};

int main() {
    KokoBananas875Test test;
    test.runTests();
    srand(time(0));
    for (int i = 0; i < 5; ++i)
        test.loadTest();
    return 0;
}