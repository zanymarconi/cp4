#include <pddef.h>
#include <ufds.h>
using namespace std;

void printSet(UFDS &ufds, int N) {
    for (int i = 0; i < N; i++) {
        cout << "Element: " << i << ", Parent: " << ufds.findSet(i) << ", Size of Set: " << ufds.sizeOfSet(i) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); // Fast IO, use only when no C style IO is used
    cin.tie(0); // Unlinking cin and cout, so that flushing of cout is not done before every cin

    int N = 5;
    UFDS ufds(N); // Create 5 disjoint sets

    cout << "Number of disjoint sets: " << ufds.numDisjointSets() << "\n";
    printSet(ufds, N);

    ufds.unionSet(0, 1);
    ufds.unionSet(2, 3);
    ufds.unionSet(3, 4);

    cout << "\nAfter some union operations: (0, 1) (2, 3) (3, 4) \n";
    cout << "Number of disjoint sets: " << ufds.numDisjointSets() << "\n";
    printSet(ufds, N);

    cout << "\nCheck if 0 and 2 are in the same set: " << (ufds.isSameSet(0, 2) ? "Yes" : "No") << "\n";
    cout << "Check if 2 and 4 are in the same set: " << (ufds.isSameSet(2, 4) ? "Yes" : "No") << "\n";

    ufds.unionSet(0, 4);
    cout << "\nAfter union operation: (0, 4) \n";
    cout << "Number of disjoint sets: " << ufds.numDisjointSets() << "\n";
    printSet(ufds, N);

    return 0;
}