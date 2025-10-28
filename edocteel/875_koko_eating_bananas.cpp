#include <bits/stdc++.h>
using namespace std;

class KokoBananas875 {
private:
    optional<reference_wrapper<const vector<int>>> pilesOpt;
    int hoursAvailable;

    int getHoursAtSpeed(int speed) {
        int hours = 0;
        for (int pile: pilesOpt->get()) {
            hours += ceil((double)pile/speed);
        }
        return hours;
    }

    int bsearch(int left, int right) {
        while (left < right) {
            int mid = left + (right - left)/2;
            int hoursTaken = getHoursAtSpeed(mid);
            if (hoursTaken > hoursAvailable) 
                left = mid + 1;
            else 
                right = mid; // ok
        }
        return right; // ok
    }

public:
    // O(N * log(MAX(pile)))
    int minEatingSpeed(const vector<int>& piles, int hoursAvailable) {
        if (piles.empty()) return 0;
        if (piles.size() > hoursAvailable) return -1; // negative energy required!

        int right = *max_element(piles.begin(), piles.end());
        this->hoursAvailable = hoursAvailable;
        pilesOpt = cref(piles);
        return bsearch(1, right);
    }

    // Run as many Times
    // Answer is always 997010 ;)
    void magicLoadTest() {
        // srand(time(0)); // Use this line for random numbers before calling magicLoadTest
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
};