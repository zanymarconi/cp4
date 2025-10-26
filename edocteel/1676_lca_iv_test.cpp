#include "1676_lca_iv.cpp"
using namespace std;

class LcaIv1676Test: public LcaIv1676 {
public:
    void runTests() {
        vector<tuple<vector<int>, vector<int>, int>> cases = {
            { {MAXX, 3,5,1,6,2,0,8,MAXX,MAXX,7,4}, {4, 7}, 2 },
            { {MAXX, 3,5,1,6,2,0,8,MAXX,MAXX,7,4}, {1}, 1 },
            { {MAXX, 3,5,1,6,2,0,8,MAXX,MAXX,7,4}, {7, 6, 2, 4}, 5},
            { {MAXX, 3}, {5}, MAXX}
        };

        int tc = 0;
        for (auto [levelOrder, valList, expected]: cases) {
            TreeNode* root = buildTree(1, levelOrder);
            unordered_set<int> valSet(valList.begin(), valList.end());
            vector<TreeNode*> nodes;
            findNodes(root, valSet, nodes);
            TreeNode* lca = lowestCommonAncestor(root, nodes);
            // printf("Root val: %d, Nodes: [", root->val);
            // for (auto node: nodes) printf("%d, ", node->val); printf("] expected: %d, lca %d\n", expected, lca? lca->val: MAXX);
            // printTreeLO(root);
            printf("Test Case %d: %s\n", ++tc, ((!lca && expected == MAXX) || (lca && lca->val == expected))? "PASS": "FAIL");
        }
    }

private:
    int MAXX = 1e9 + 7;

    void printTreeLO(TreeNode *root) {
        printf("Tree:\n");
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({root, nullptr});
        while (!qu.empty()) {
            int levelSize = qu.size();
            for (int i = 0; i < levelSize; ++i) {
                auto [node, par] = qu.front(); qu.pop();
                if (node) {
                    printf("%d(%d) ", node->val, par? par->val: MAXX);
                    qu.push({node->left, node});
                    qu.push({node->right, node});
                }
            }
            printf("\n");
        } 
    }

    TreeNode* buildTree(int index, vector<int>& levelOrder) {
        TreeNode* node = nullptr;
        if (index >= levelOrder.size() || levelOrder[index] == MAXX) return node;
        
        node = new TreeNode(levelOrder[index]);
        node->left = buildTree(2*index, levelOrder);
        node->right = buildTree(2*index + 1, levelOrder);
        return node;
    }

    void findNodes(TreeNode* node, unordered_set<int>& values, vector<TreeNode*>& nodes) {
        if (!node) return;
        if (values.size() == nodes.size()) return;
        if (values.find(node->val) != values.end())
            nodes.push_back(node);
        findNodes(node->left, values, nodes);
        findNodes(node->right, values, nodes);
    }
};

int main() {
    LcaIv1676Test test;
    test.runTests();
    return 0;
}