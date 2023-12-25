#include <vector>
#include <queue>
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
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int noOfNodes = q.size();
            vector<TreeNode *> tmp;
            for (int i = 0; i < noOfNodes; i++) {
                auto frontNode = q.front();
                tmp.push_back(frontNode);
                q.pop();
                if (frontNode != nullptr){
                    q.push(frontNode->left);
                    q.push(frontNode->right);
                }
            }
            int leftIdx = 0;
            int rightIdx = tmp.size() - 1;
            while (leftIdx < rightIdx) {
                auto leftNode = tmp[leftIdx];
                auto rightNode = tmp[rightIdx];
                if (leftNode != nullptr && rightNode != nullptr) {
                    if (leftNode->val != rightNode->val) {
                        return false;
                    }
                } else if (!(leftNode == nullptr && rightNode == nullptr)) {
                    return false;
                }
                leftIdx++;
                rightIdx--;
            }
        }
        return true;
    }
};
