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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            auto top = stack.back();
            stack.pop_back();
            ans.push_back(top->val);
            if (top->right != nullptr) {
                stack.push_back(top->right);
            }
            if (top->left != nullptr) {
                stack.push_back(top->left);
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}