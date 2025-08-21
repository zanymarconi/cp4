#include <pddef.h>
using namespace std;

void create_permutation(const string &s) {
    string str = s;
    sort(str.begin(), str.end()); // Sort the string to start with the smallest permutation
    
    cout << "Permutations of \"" << s << "\":" << endl;
}

int main() {
    create_permutation("prakhar");
    return 0;
}