#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "2235_add_two_integers.cpp"
using namespace std;

TEST_CASE("BothPositive", "[edocteel][2235]") {
    AddTwoIntegers2235 test;
    int actual = test.sum(2, 3);
    REQUIRE(actual == 5);
}

TEST_CASE("PositiveAndNegativeLimits", "[edocteel][2235]") {
    AddTwoIntegers2235 test;
    int actual = test.sum(INT_MAX, INT_MIN);
    REQUIRE(actual == -1);
}

TEST_CASE("RecursiveSum", "[edocteel][2235]") {
    AddTwoIntegers2235 test;
    int actual = test.sum(-1, test.sum(2, 3));
    REQUIRE(actual == 4);
}