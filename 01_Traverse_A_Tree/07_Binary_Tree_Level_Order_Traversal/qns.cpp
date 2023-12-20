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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> tmp;
            int noOfNodes = q.size();
            for (int i = 0; i < noOfNodes; i++) {
                auto tmpNode = q.front();
                q.pop();
                tmp.push_back(tmpNode->val);
                if (tmpNode->left != nullptr) {
                    q.push(tmpNode->left);
                }
                if (tmpNode->right != nullptr) {
                    q.push(tmpNode->right);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {


    return 0;
}