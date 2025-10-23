#include <pddef.h>
#include <io_redirect.h>
using namespace std;

void evaluate_sum() {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        double sum = 0.0;
        double num;
        while (iss >> num) {
            sum += num;
        }
        cout << sum << endl;
    }
}

int main() {
    #ifdef IO_REDIRECT_H
        redirect_input_output(__FILE__);
    #endif 

    evaluate_sum();
    return 0;
}