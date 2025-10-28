#include <bits/stdc++.h>
using namespace std;

class FlowerPlace605 {
public:
    bool canPlaceFlowers(const vector<int>& flowerbed, int n) {
        if (n <= 0) return true;
        if (flowerbed.empty()) return false;

        flowerBedOpt = cref(flowerbed);
        return maximumFlowersPut() >= n;
    } 
private:
    optional<reference_wrapper<const vector<int>>> flowerBedOpt;
    static constexpr int MIN = -1e9;

    int maximumFlowersPut() {
        int size = flowerBedOpt->get().size();
        int currentFlowers = 0;
        // can improve space complexity if only next is required
        vector<vector<int>> maxFlowersAtPos(2, vector<int>(size+1, MIN));
        maxFlowersAtPos[0][size] = 0;
        for (int i = size-1; i >= 0; --i) {
            if (flowerBedOpt->get()[i] == 1) {
                ++currentFlowers;
                maxFlowersAtPos[1][i] = 1 + maxFlowersAtPos[0][i+1];
                continue;
            }
            // current 0 (unchanged): possible 00 01
            // current 1 (changed): possible 10
            maxFlowersAtPos[0][i] = max(maxFlowersAtPos[0][i+1], maxFlowersAtPos[1][i+1]);
            maxFlowersAtPos[1][i] = max(maxFlowersAtPos[0][i], 1 + maxFlowersAtPos[0][i+1]); 
        }
        return max(maxFlowersAtPos[0][0], maxFlowersAtPos[1][0]) - currentFlowers;
    }
};