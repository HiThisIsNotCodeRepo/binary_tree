#include <vector>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverseTreeNode(TreeNode *root, vector<int> &vals) {
    if (root == NULL) {
        return;
    }
    traverseTreeNode(root->left, vals);
    vals.push_back(root->val);
    traverseTreeNode(root->right, vals);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverseTreeNode(root, ans);
        return ans;
    }
};

int main() {


    return 0;
}