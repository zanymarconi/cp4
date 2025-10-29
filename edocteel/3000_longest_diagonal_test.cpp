#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "3000_longest_diagonal.cpp"
using namespace std;

TEST_CASE("SkewedRectange", "[edocteel][3000]") {
    LongestDiagonal3000 test;
    vector<vector<int>> dimensions = {
        {5, 5},
        {3, 4},
        {1, 10}
    };
    int area = test.areaOfMaxDiagonal(dimensions);
    REQUIRE(area == 10);
}
/*
This is based on Fermat's theorem on sums of two squares. The number of ways an 
integer K can be written as a sum of two squares depends on its prime factors.
Specifically, it depends on the prime factors of the form 4k+1 (like 5, 13, 17, 29, 37...).

Let's watch the set size grow by picking $K$ as a product of these "special" primes.
Smallest Example: 
    Let K = 65 = 5 * 13 
    65 = 1^2 + 8^2
    65 = 4^2 + 7^2
    The set of pairs is {(1, 8), (4, 7)}. Set size: 2
Bigger Example: 
    Let K = 1105 = 5 * 13 * 17
    1105 = 4^2 + 33^2
    1105 = 9^2 + 32^2
    1105 = 12^2 + 31^2
    1105 = 23^2 + 24^2$
*/
TEST_CASE("TiedDiagonals", "[edocteel][3000]") {
    LongestDiagonal3000 test;
    vector<vector<int>> dimensions = {
        {4, 33},  // 132 (diag sqrt(1105))
        {9, 32},  // 288 (diag sqrt(1105))
        {12, 31}, // 372 (diag sqrt(1105))
        {23, 24}  // 552 (diag sqrt(1105))
    };
    int area = test.areaOfMaxDiagonal(dimensions);
    REQUIRE(area == 552); // returns largest area
}

TEST_CASE("EmptyDimensions", "[edocteel][3000]") {
    LongestDiagonal3000 test;
    vector<vector<int>> dimensions;
    int area = test.areaOfMaxDiagonal(dimensions);
    REQUIRE(area == 0);
}