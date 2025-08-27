#include <pddef.h>
using namespace std;

#pragma once

// Union-Find Disjoint Sets (UFDS) implementation
class UFDS
{
private:
    vi p, rank, setSize;
    int numSets;

public:
    UFDS(int N)
    {
        p.assign(N, 0);
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
        for (int i = 0; int& x: p) x = i++;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); } // O(1) amortized by path compression
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // Optional: any feature of the set can be added

    void unionSet(int i, int j) // O(1) amortized by union by rank heuristic
    {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        setSize[y] += setSize[x];
        numSets--;
    }
};