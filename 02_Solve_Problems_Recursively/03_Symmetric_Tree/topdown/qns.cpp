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
    bool isSymmetric(TreeNode *root) {
        if (root->left != nullptr && root->right != nullptr) {
            return isSymmetricR(root->left, root->right);
        } else if (!(root->left == nullptr && root->right == nullptr)) {
            return false;
        }
        return true;
    }

    bool isSymmetricR(TreeNode *root, TreeNode *mir) {
        if (root->val != mir->val) {
            return false;
        }
        bool ret;
        if (root->left != nullptr && mir->right != nullptr) {
            ret = isSymmetricR(root->left, mir->right);
            if (ret == false) {
                return ret;
            }
        } else if (!(root->left == nullptr && mir->right == nullptr)) {
            return false;
        }
        if (root->right != nullptr && mir->left != nullptr) {
            ret = isSymmetricR(root->right, mir->left);
            if (ret == false) {
                return ret;
            }
        } else if (!(root->right == nullptr && mir->left == nullptr)) {
            return false;
        }
        return true;
    }
};