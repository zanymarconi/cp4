#include "2933_high_access_employee.cpp"
using namespace std;

class HighAccessEmployee2933Test: public HighAccessEmployee2933 {

    string scenarios = R"(
        5
        a 0549  b 0457  a 0532  a 0621  b 0540
        1
        a
        8
        d 0002  c 0808  c 0829  e 0215  d 1508  d 1444  d 1410  c 0809
        2
        c   d
        6
        cd 1025 ab 1025 cd 1046 cd 1055 ab 1124 ab 1120
        2
        ab  cd
        5
        a 0001  a 0200  a 1100  a 2200  a 2350
        0
        3
        ff 1508 ff 1510 ff 1508
        1
        ff
    )";

public:
    void runTests() {
        int tc = 0;
        istringstream ss(scenarios);
        vector<vector<string>> logins;
        int N;
        while (ss >> N) {
            logins.assign(N, vector<string>());
            for (int i = 0; i < N; ++i) {
                string emp, log;
                ss >> emp >> log;
                logins[i] = {emp, log};
            }
            int M;
            ss >> M;
            set<string> expected;
            for (int i = 0 ; i < M; ++i) {
                string e;
                ss >> e;
                expected.insert(e);
            }
            vector<string> hae = findHighAccessEmployees(logins);
            set<string> actual(hae.begin(), hae.end());

            // printf("\t Debug: Logins %d Expected %d Actual %d\n", N, M, actual.size());
            printf("Test %d: %s\n", ++tc, actual == expected? "PASS": "FAIL");
        }
    }

};

int main() {
    HighAccessEmployee2933Test test;
    test.runTests();
    return 0;
}