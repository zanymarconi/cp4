#include <pddef.h>
using namespace std;

#pragma once

class SegmentTree
{
private:
    int N;
    vi st, lazy;
    const vi &A;

    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = A[L];
        else
        {
            int mid = (L + R) / 2;
            build(left(p), L, mid);
            build(right(p), mid + 1, R);
            st[p] = min(st[left(p)], st[right(p)]);
        }
    }

    int rmq(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L)
            return INT_MAX; // Current segment outside query range

        propagate(p, L, R); // Ensure all propagation is done at p
        if (L >= i && R <= j)
            return st[p]; // Current segment inside query range
        int mid = (L + R) / 2;
        return min(rmq(left(p), L, mid, i, j), rmq(right(p), mid + 1, R, i, j)); // Query left and right child
    }

    void propagate(int p, int L, int R)
    {
        if (lazy[p] != -1)
        {
            st[p] = lazy[p]; // Update it
            if (L != R)
            { // Not a leaf node
                lazy[left(p)] = lazy[p];   // Mark child as lazy
                lazy[right(p)] = lazy[p];  // Mark child as lazy
            }
            lazy[p] = -1; // Reset it
        }
    }

    void update(int p, int L, int R, int i, int j, int val)
    {
        propagate(p, L, R); // Ensure all propagation is done at p
        if (i > R || j < L)
            return; // Current segment outside update range
        if (L >= i && R <= j)
        { // Current segment inside update range
            lazy[p] = val; // Mark it as lazy
            propagate(p, L, R);
        }
        else
        { // Segment partially in update range
            int mid = (L + R) / 2;
            update(left(p), L, mid, i, j, val);
            update(right(p), mid + 1, R, i, j, val);
            st[p] = min(st[left(p)], st[right(p)]); // Update this node with the results of children
        }
    }

public:
    SegmentTree(const vi &_A) : A(_A)
    {
        N = (int)A.size();
        st.assign(4 * N, -1); // 4*N > 2ˆceil(log2(N))
        lazy.assign(4 * N, -1);
        build(1, 0, N - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, N - 1, i, j); } // O(log N)

    void update(int i, int j, int val) { update(1, 0, N - 1, i, j, val); } // O(log N) w/ lazy propagation
};