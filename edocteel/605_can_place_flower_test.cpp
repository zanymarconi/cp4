#include "605_can_place_flower.cpp"
using namespace std;

class FlowerPlace605Test: public FlowerPlace605 {
public:
    void runTests() {
        istringstream ss(scenarios);
        int size, tc = 0;
        ss >> boolalpha;
        while (ss >> size) {
            vector<int> flowerBed;
            int flower, N;
            bool expected;
            while (size > 0) {
                ss >> flower;
                flowerBed.push_back(flower);
                --size;
            }
            ss >> N >> expected;

            printf("Test %d = %s\n", ++tc, 
                (canPlaceFlowers(flowerBed, N) == expected)? "PASS": "FAIL");
        }
    }

private: 
    string scenarios = R"(
        1
        0
        1
        true

        1
        1
        1
        false

        4
        1 1 1 1
        1
        false

        4
        1 0 0 1
        1
        false

        4
        0 0 0 0
        2
        true

        5
        0 0 0 0 0
        3
        true
        
        6
        0 1 0 0 1 0
        1
        false
    )";
};

int main() {
    FlowerPlace605Test test;
    test.runTests();
    return 0;
}