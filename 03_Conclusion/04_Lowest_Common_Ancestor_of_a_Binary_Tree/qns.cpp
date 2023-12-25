#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *ret = nullptr;
        if (root->val == p->val || root->val == q->val) {
            ret = root;
        }
        TreeNode *tmpLeft = nullptr;
        if (root->left != nullptr) {
            tmpLeft = lowestCommonAncestor(root->left, p, q);
        }
        TreeNode *tmpRight = nullptr;
        if (root->right != nullptr) {
            tmpRight = lowestCommonAncestor(root->right, p, q);
        }
        if (ret != nullptr) {
            return ret;
        }
        if (tmpLeft != nullptr && tmpRight != nullptr) {
            return root;
        }
        if (tmpRight != nullptr) {
            return tmpRight;
        }
        if (tmpLeft != nullptr) {
            return tmpLeft;
        }
        return nullptr;
    }
};