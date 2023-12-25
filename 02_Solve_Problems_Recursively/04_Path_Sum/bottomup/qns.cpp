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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return hasPathSumR(root, targetSum);
    }

    bool hasPathSumR(TreeNode *root, int targetSum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                return true;
            }
            return false;
        }
        bool ret;
        if (root->left != nullptr) {
            ret = hasPathSumR(root->left, targetSum - root->val);
            if (ret) {
                return ret;
            }
        }
        if (root->right != nullptr) {
            ret = hasPathSumR(root->right, targetSum - root->val);
            if (ret) {
                return ret;
            }
        }
        return false;
    }
};