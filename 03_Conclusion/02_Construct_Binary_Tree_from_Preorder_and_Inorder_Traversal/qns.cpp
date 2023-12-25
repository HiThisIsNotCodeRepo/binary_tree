#include <vector>
#include <map>
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
private:
    map<int, int> inorderMap;
    vector<int> preOrderArr;
    vector<int> inOrderArr;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        preOrderArr = preorder;
        inOrderArr = inorder;

        int headNodeVal = preorder[0];
        auto *headNode = new TreeNode(headNodeVal);

        int leftCount = inorderMap[headNodeVal];
        int rightCount = inorder.size() - 1 - leftCount;

        int leftInOrderStart = 0;
        int leftInOrderEnd = leftCount;

        int rightInOrderStart = leftInOrderEnd + 1;
        int rightInOrderEnd = rightInOrderStart + rightCount;

//        cout << "leftCount->" << leftCount << ",rightCount->" << rightCount << endl;
//        cout<<endl;
        if (leftCount != 0) {
            build(headNode, true, 1, leftInOrderStart, leftInOrderEnd);
        }
        if (rightCount != 0) {
            build(headNode, false, leftCount + 1, rightInOrderStart, rightInOrderEnd);
        }
        return headNode;
    }

    void build(TreeNode *parent, bool isLeft, int nextValIdx, int inOrderStart, int inOrderEnd) {
//        cout << "nextValIdx->" << nextValIdx << ",inOrderStart->" << inOrderStart << ",inOrderEnd->" << inOrderEnd
//             << endl;
        int tmpHeadNodeVal = preOrderArr[nextValIdx];
        auto *tmpHeadNode = new TreeNode(tmpHeadNodeVal);

        if (isLeft == true) {
            parent->left = tmpHeadNode;
        } else {
            parent->right = tmpHeadNode;
        }

        int leftCount = inorderMap[tmpHeadNodeVal] - inOrderStart;
        int rightCount = inOrderEnd - inorderMap[tmpHeadNodeVal] - 1;


        int leftInOrderStart = inOrderStart;
        int leftInOrderEnd = inOrderStart + leftCount;

        int rightInOrderStart = leftInOrderEnd + 1;
        int rightPreOrderEnd = inOrderEnd;
//        cout << "leftCount->" << leftCount << ",rightCount->" << rightCount << endl;
        if (leftCount != 0) {
            build(tmpHeadNode, true, nextValIdx + 1, leftInOrderStart, leftInOrderEnd);
        }
        if (rightCount != 0) {
            build(tmpHeadNode, false, nextValIdx + leftCount + 1, rightInOrderStart, rightPreOrderEnd);
        }
    }
};
