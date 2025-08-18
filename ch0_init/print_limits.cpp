#include <pddef.h>
#include <iostream>
using namespace std;

void print_limits() {
    cout << "Integer limits: " << endl;
    cout << "Maximum integer value (_INF): " << _INF << endl;
    cout << "Minimum integer value (_MINF): " << _MINF << endl;

    cout << "Long long limits: " << endl;
    cout << "Maximum long long value (_LLINF): " << _LLINF << endl;
    cout << "Minimum long long value (_LLMINF): " << _LLMINF << endl;

    cout << "Double limits: " << endl;
    cout << "Machine epsilon for double (_EPS): " << _EPS << endl;
}

int main() {
    cout << "Hey, CP4!" << endl;
    print_limits();
    cout << "Program completed successfully!" << endl; 
    return 0;   
}