#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
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

// only following two headers are required for OST
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

int main() {
    ost tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    // print tree elements in sorted order
    cout << "Elements in the tree: ";
    for (int i = 0; i < tree.size(); i++) {
        cout << *tree.find_by_order(i) << " ";  
    }
    cout << endl;

    cout << "3rd smallest element: " << *tree.find_by_order(2) << endl;  // 0-based indexing
    cout << "Number of elements less than 5: " << tree.order_of_key(5) << endl;    

    tree.erase(3); // works only when using less<int>, and not with less_equal<int>
    tree.insert(1); // Duplicate insert, will not be ignored with less_equal<int> instead of less<int>
    tree.insert(9);

    // print tree elements in sorted order after modifications
    cout << "Elements in the tree after modifications: ";
    for (int i = 0; i < tree.size(); i++) {
        cout << *tree.find_by_order(i) << " ";  
    }
    cout << endl;

    cout << "3rd smallest element after deletion: " << *tree.find_by_order(2) << endl;  // O(log n) select operation
    cout << "Number of elements less than 5: " << tree.order_of_key(5) << endl;         // O(log n) rank operation
    cout << "Number of elements less than 8: " << tree.order_of_key(8) << endl;  

    return 0;
}