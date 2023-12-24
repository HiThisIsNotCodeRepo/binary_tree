#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int ret = maxDepth(root->left);
        ret = max(ret, maxDepth(root->right));
        return ret + 1;
    }
};