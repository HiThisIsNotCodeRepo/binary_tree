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
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            auto top = stack.back();
            if (top->left == nullptr) {
                if (top->right != nullptr) {
                    stack.push_back(top->right);
                    top->right = nullptr;
                } else {
                    stack.pop_back();
                    ans.push_back(top->val);
                }
            } else {
                stack.push_back(top->left);
                top->left = nullptr;
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}