#include<bits/stdc++.h>
using namespace std;

/*
 * All nodes val in the tree are unique(?)
 * Number of nodes in the tree < 1e5 
*/

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {}
};

class LcaIv1676 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        lca = nullptr;
        if (nodes.empty()) return lca;

        nodeSet.clear();
        nodeSet.insert(nodes.begin(), nodes.end());
        nodeSetSize = nodeSet.size();
        dfs(root);
        return lca;
    }

private:
    TreeNode* lca;
    unordered_set<TreeNode*> nodeSet;
    int nodeSetSize;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        if (lca != nullptr) return 0;
        int mid = nodeSet.find(node) != nodeSet.end()? 1: 0;
        int cleft = dfs(node->left);
        int cright = dfs(node->right);
        // printf("\t debug node val: mid %d(%d), left %d(%d), right %d(%d)\n", node->val, mid, node->left?node->left->val: -1, cleft, node->right? node->right->val: -1, cright);
        // printf("\t nodesetsize %d, mid+l+r %d\n", nodeSetSize, mid+cleft+cright);
        if (mid+cleft+cright == nodeSetSize) {
            lca = node;
            return 0;
        }
        return mid+cleft+cright;
    }
};