#ifndef KOKO_EATING_BANANAS_875_H
#define KOKO_EATING_BANANAS_875_H

#include <bits/stdc++.h>
using namespace std;

class KokoBananas875 {
public:
    int minEatingSpeed(const vector<int>& piles, int hoursAvailable);

private:
    optional<reference_wrapper<const vector<int>>> pilesOpt;
    int hoursAvailable;

    int getHoursAtSpeed(int speed);
    int bsearch(int left, int right);
};

#endif