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
private:
    int ans;
public:
    int countUnivalSubtrees(TreeNode *root) {
        ans = 0;
        if (root == nullptr) {
            return ans;
        }
        int left = -1001;
        int right = -1001;
        if (root->left != nullptr) {
            left = countUnivalSubtreesR(root->left);
        }
        if (root->right != nullptr) {
            right = countUnivalSubtreesR(root->right);
        }

        if (left == -1001 && right == -1001) {
            ans++;
        } else if (left == -1001 && right == root->val) {
            ans++;
        } else if (right == -1001 && left == root->val) {
            ans++;
        } else if (left == root->val && right == root->val) {
            ans++;
        }

        return ans;
    }

    int countUnivalSubtreesR(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            ans++;
            return root->val;
        }

        int left = -1001;
        int right = -1001;
        if (root->left != nullptr) {
            left = countUnivalSubtreesR(root->left);
        }
        if (root->right != nullptr) {
            right = countUnivalSubtreesR(root->right);
        }
        int oldAns = ans;
        if (left == -1001 && right == root->val) {
            ans++;
        } else if (right == -1001 && left == root->val) {
            ans++;
        } else if (left == root->val && right == root->val) {
            ans++;
        }
        if (oldAns < ans) {
            return root->val;
        }
        return 1001;
    }
};