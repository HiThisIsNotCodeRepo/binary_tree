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
    int level;
public:
    int maxDepth(TreeNode *root) {
        recurse(root, 0);
        return level;
    }

    void recurse(TreeNode *node, int currentLevel) {
        if (node == nullptr) {
            level = max(currentLevel, level);
            return;
        }
        recurse(node->left, currentLevel + 1);
        recurse(node->right, currentLevel + 1);
    }
};