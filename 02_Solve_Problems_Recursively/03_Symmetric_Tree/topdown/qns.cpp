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
        return check(root->left, root->right);
    }

    bool check(TreeNode *left, TreeNode *right) {
        if (left != nullptr && right != nullptr) {
            return isSymmetricR(left, right);
        } else if (!(left == nullptr && right == nullptr)) {
            return false;
        }
        return true;
    }

    bool isSymmetricR(TreeNode *left, TreeNode *right) {
        if (left->val != right->val) {
            return false;
        }
        bool ret = check(left->left,right->right);
        if (ret == false) {
            return ret;
        }
        ret = check(left->right,right->left);
        if (ret == false) {
            return ret;
        }
        return true;
    }
};