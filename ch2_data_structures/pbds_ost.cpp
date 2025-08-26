#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Order Statistic Tree (OST) definition
// Policy-based data structure (PBDS) that supports order statistics
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ost;

int main() {
    ost tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    // Find the 2nd smallest element (0-based index)
    cout << "2nd smallest element: " << *tree.find_by_order(2) << endl;

    tree.erase(3);
    tree.insert(9);

    // Count elements less than 5
    cout << "Number of elements less than 5: " << tree.order_of_key(5) << endl;
    cout << "2nd smallest element after deletion: " << *tree.find_by_order(2) << endl;

    return 0;
}