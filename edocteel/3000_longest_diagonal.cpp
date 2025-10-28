#include "3000_longest_diagonal.h"
using namespace std;

int LongestDiagonal3000::areaOfMaxDiagonal(const vector<vector<int>>& dimensions) {
    if (dimensions.empty()) return 0;

    int index = -1;
    double longestDiagonal = -1;
    int current = 0;
    for (auto dimension: dimensions) {
        double diagonal = hypot(dimension[0], dimension[1]);
        if (diagonal > longestDiagonal + EPS) {
            longestDiagonal = diagonal;
            index = current;
        } else if (abs(diagonal - longestDiagonal) < EPS) {
            if ((dimensions[index][0] * dimensions[index][1])
                < (dimension[0] * dimension[1]))
                index = current;

        }
        ++current;
    }
    return dimensions[index][0] * dimensions[index][1];
}