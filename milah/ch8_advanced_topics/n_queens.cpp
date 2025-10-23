#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Place N queens on an N x N chessboard so that no two queens
// threaten each other. A queen can attack horizontally, vertically,
// and diagonally.

int N, solutions;
int rw, ld, rd; // bitmasks for columns and diagonals
int ALL; // all N columns filled

// This implementation uses bitmasks and runs in O(N!!) time.
void backtrack(int rw, int ld, int rd) {
    if (rw == ALL) { solutions++; return; } // all N queens placed in each column

    int pos = ALL & ~(rw | ld | rd); // rows available for placing a queen in this column
    while (pos) {
        int p = pos & -pos; // rightmost available row
        pos = pos ^ p; 
        backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1); // place queen and recurse to next column
    }
}

int main() {
    int maxN = 16; // max N should be less than 32 for bitmasking to work

    for(int i = 1; i <= maxN; i++) {
        N = i; solutions = 0; ALL = (1 << N) - 1;
        rw = ld = rd = 0; // no columns or diagonals occupied
        auto start = high_resolution_clock::now();

        // Symmetry breaking: place first queen in first half of the rows in first column
        int half = N >> 1;
        for (int r = 0; r < half; r++) {
            int p = 1 << r; // place queen at row r in first column
            backtrack(p, p << 1, p >> 1);
        }
        solutions *= 2; // mirror solutions for second half of rows
        if (N & 1) { // if N is odd, place first queen in the middle row
            int p = 1 << half;
            backtrack(p, p << 1, p >> 1);
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        printf("Backtrack Time %.3f s; Number of solutions for %2d-Queens: %d\n", duration.count() / 1000.0, N, solutions);
        fflush(stdout);
    }
}