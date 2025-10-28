#include "875_koko_eating_bananas.h"
using namespace std;

int KokoBananas875::minEatingSpeed(const vector<int>& piles, int hoursAvailable) {
    if (piles.empty()) return 0;
    if (piles.size() > hoursAvailable) return -1;  // negative energy required!

    int right = *max_element(piles.begin(), piles.end());
    this->hoursAvailable = hoursAvailable;
    pilesOpt = cref(piles);
    return bsearch(1, right);
}

int KokoBananas875::getHoursAtSpeed(int speed) {
    int hours = 0;
    for (int pile : pilesOpt->get()) {
        hours += ceil((double)pile / speed);
    }
    return hours;
}

int KokoBananas875::bsearch(int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        int hoursTaken = getHoursAtSpeed(mid);
        if (hoursTaken > hoursAvailable)
            left = mid + 1;
        else
            right = mid;  // ok
    }
    return right;  // ok
}