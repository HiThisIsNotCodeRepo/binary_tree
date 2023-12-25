#include <vector>
#include <queue>
#include <iostream>

using namespace std;


class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int noOfNodes = q.size();
            vector<Node *> arr;
            for (int i = 0; i < noOfNodes; i++) {
                auto top = q.front();
                arr.push_back(top);
                q.pop();
                if (top != nullptr && top->left != nullptr) {
                    q.push(top->left);
                }
                if (top != nullptr && top->right != nullptr) {
                    q.push(top->right);
                }
            }
            for (int i = 0; i < noOfNodes - 1; i++) {
                arr[i]->next = arr[i + 1];
            }
        }
        return root;
    }
};
