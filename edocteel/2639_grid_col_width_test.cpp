#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "2639_grid_col_width.cpp"
using namespace std;

TEST_CASE("SingleColumn", "[edocteel][2639]") {
    GridColWidth2639 test;
    vector<vector<int>> grid = {
        {1},{22},{333}
    };
    vector<int> computed = test.findColumnWidth(grid);
    REQUIRE(computed.size() == 1);
    REQUIRE(computed[0] == 3);
}

TEST_CASE("MultiColumn", "[edocteel][2639]") {
    GridColWidth2639 test;
    vector<vector<int>> grid = {
        {-15, 1, 3},
        {15, 7, 12},
        {5, 6, -2}
    };
    vector<int> computed = test.findColumnWidth(grid);
    REQUIRE(computed.size() == 3);
    REQUIRE(computed == vector<int>({3, 1, 2}));
}

