#include <pddef.h>
using namespace std;

void create_permutation(const string &s) { 
    cout << "Permutations of \"" << s << "\":" << endl;

    // Store in vector characters
    vector<char> letters(s.begin(), s.end());
    
    // Sort the characters to ensure we start with the lexicographically smallest permutation
    sort(letters.begin(), letters.end());

    int count = 0; // To count the number of permutations
    do {
        // Print the current permutation
        for (char c : letters) {
            cout << c;
        }
        cout << endl;
        count++;
    } while (next_permutation(letters.begin(), letters.end())); // Generate the next permutation

    // 7!/(2!*2!) = 1260 permutations for "prakhar"
    cout << "Total permutations: " << count << endl;
}

int main() {
    create_permutation("prakhar");
    return 0;
}