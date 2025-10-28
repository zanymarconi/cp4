#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "875_koko_eating_bananas.cpp"
using namespace std;

TEST_CASE("Single large pile", "[edocteel][675]") {
    KokoBananas875 kokoTest;
    vector<int> piles = {312884470};
    REQUIRE(kokoTest.minEatingSpeed(piles, 312884469) == 2);
}

TEST_CASE("Small piles with zero", "[edocteel][675]") {
    KokoBananas875 kokoTest;
    vector<int> piles = {2, 0, 4};
    REQUIRE(kokoTest.minEatingSpeed(piles, 3) == 2);
}

TEST_CASE("Must eat max pile", "[edocteel][675]") {
    KokoBananas875 kokoTest;
    vector<int> piles = {3, 6, 7, 11};
    REQUIRE(kokoTest.minEatingSpeed(piles, 4) == 11);
}

TEST_CASE("More time available", "[edocteel][675]") {
    KokoBananas875 kokoTest;
    vector<int> piles = {3, 6, 7, 11};
    REQUIRE(kokoTest.minEatingSpeed(piles, 6) == 6);
}

TEST_CASE("Plenty of time", "[edocteel][675]") {
    KokoBananas875 kokoTest;
    vector<int> piles = {3, 6, 7, 11};
    REQUIRE(kokoTest.minEatingSpeed(piles, 8) == 4);
}

TEST_CASE("Empty piles", "[edocteel][675]") {
    KokoBananas875 kokoTest;
    vector<int> piles = {};
    REQUIRE(kokoTest.minEatingSpeed(piles, 42) == 0);
}

TEST_CASE("Not enough time", "[edocteel][675]") {
    KokoBananas875 kokoTest;
    vector<int> piles = {1, 1};
    REQUIRE(kokoTest.minEatingSpeed(piles, 1) == -1);
}

TEST_CASE("Load test", "[edocteel][675][benchmark]") {
    KokoBananas875 kokoTest;
    int size = 1e6 + 3;
    int pileMax = 1e9 + 7;
    vector<int> piles(size);
    srand(time(0));
    for (int i = 0; i < size; ++i)
        piles[i] = rand() % pileMax;
    int hoursAvailable = size + rand() % size;
    int minSpeed = kokoTest.minEatingSpeed(piles, hoursAvailable);
    printf("Load Test with %d piles within %d hours required at least %d /hr speed\n",
        size, hoursAvailable, minSpeed);
    REQUIRE(minSpeed > 1);
}