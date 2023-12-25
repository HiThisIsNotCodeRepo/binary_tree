#include <vector>
#include <string>
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

//void displayVector(vector<int> &arr, string fnName) {
//    cout << fnName << endl;
//    for (int i = 0; i < arr.size(); i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}

vector<vector<int>> getLeftAndRightInOrder(vector<int> &inorder, int target) {
    vector<int> left;
    vector<int> right;
    bool fillLeft = true;
    for (int i = 0; i < inorder.size(); i++) {
        int tmpNode = inorder[i];
        if (fillLeft == true) {
            if (tmpNode != target) {
                left.push_back(tmpNode);
            } else {
                fillLeft = false;
            }
            continue;
        }
        right.push_back(tmpNode);
    }
//    displayVector(left, "getLeftAndRightInOrder-left");
//    displayVector(right, "getLeftAndRightInOrder-right");
    return {left, right};
}


vector<vector<int>> getLeftAndRightPostOrder(vector<int> &postorder, int leftCount, int rightCount) {
    vector<int> left;
    vector<int> right;
    int idx;
    for (idx = 0; idx < leftCount; idx++) {
        left.push_back(postorder[idx]);
    }
    for (; idx < leftCount + rightCount; idx++) {
        right.push_back(postorder[idx]);
    }
//    displayVector(left, "getLeftAndRightPostOrder-left");
//    displayVector(right, "getLeftAndRightPostOrder-right");
    return {left, right};
}

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int headNodeVal = postorder[postorder.size() - 1];
        auto *headNode = new TreeNode(headNodeVal);

        auto leftAndRightInorder = getLeftAndRightInOrder(inorder, headNodeVal);
        vector<int> leftInOrder = leftAndRightInorder[0];
        vector<int> rightInOrder = leftAndRightInorder[1];

        auto leftAndRightPostorder = getLeftAndRightPostOrder(postorder, leftInOrder.size(), rightInOrder.size());

        vector<int> leftPostOrder = leftAndRightPostorder[0];
        vector<int> rightPostOrder = leftAndRightPostorder[1];

        if (leftPostOrder.size() != 0) {
            build(leftInOrder, leftPostOrder, headNode, true);
        }
        if (rightPostOrder.size() != 0) {
            build(rightInOrder, rightPostOrder, headNode, false);
        }
        return headNode;
    }

    void build(vector<int> &inorder, vector<int> &postorder, TreeNode *parent, bool isLeft) {
        int tmpHeadNodeVal = postorder[postorder.size() - 1];
        auto *tmpHeadNode = new TreeNode(tmpHeadNodeVal);

        if (isLeft == true) {
            parent->left = tmpHeadNode;
        } else {
            parent->right = tmpHeadNode;
        }
        auto leftAndRightInorder = getLeftAndRightInOrder(inorder, tmpHeadNodeVal);
        vector<int> leftInOrder = leftAndRightInorder[0];
        vector<int> rightInOrder = leftAndRightInorder[1];

        auto leftAndRightPostorder = getLeftAndRightPostOrder(postorder, leftInOrder.size(), rightInOrder.size());

        vector<int> leftPostOrder = leftAndRightPostorder[0];
        vector<int> rightPostOrder = leftAndRightPostorder[1];

        if (leftPostOrder.size() != 0) {
            build(leftInOrder, leftPostOrder, tmpHeadNode, true);
        }
        if (rightPostOrder.size() != 0) {
            build(rightInOrder, rightPostOrder, tmpHeadNode, false);
        }
    }
};
