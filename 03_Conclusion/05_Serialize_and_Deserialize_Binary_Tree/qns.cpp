#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "";
        }
        queue<pair<TreeNode *, string>> q;
        q.push({root, "0:l"});
        int idx = 1;
        string serializeStr;
        while (q.empty() == false) {
            int noOfNodes = q.size();
            for (int i = 0; i < noOfNodes; i++) {
                auto front = q.front();
                q.pop();
                auto frontTreeNode = front.first;
                auto frontTreeParent = front.second;
                serializeStr.append(
                        frontTreeParent + ":" + to_string(idx) + ":" + to_string(frontTreeNode->val) +
                        ",");
                if (frontTreeNode->left != nullptr) {
                    q.push({frontTreeNode->left, to_string(idx) + ":l"});
                }
                if (frontTreeNode->right != nullptr) {
                    q.push({frontTreeNode->right, to_string(idx) + ":r"});
                }
                ++idx;
            }
            serializeStr.pop_back();
            serializeStr.push_back('=');
        }
        serializeStr.pop_back();
//        cout << serializeStr << endl;
        return serializeStr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        map<int, TreeNode *> tree;
        TreeNode *ans;
        stringstream levelSS(data);
        string level;
        while (!levelSS.eof()) {
            getline(levelSS, level, '=');
            stringstream nodeSS(level);
            string node;
            while (!nodeSS.eof()) {
                getline(nodeSS, node, ',');
                int parentIdx;
                bool isLeft;
                int nodeIdx;
                int val;
                int idx = 0;
                stringstream tmpSS(node);
                string tmp;
                while (!tmpSS.eof()) {
                    getline(tmpSS, tmp, ':');
                    if (idx == 0) {
                        parentIdx = stoi(tmp);
                    } else if (idx == 1) {
                        if (tmp == "l") {
                            isLeft = true;
                        } else {
                            isLeft = false;
                        }
                    } else if (idx == 2) {
                        nodeIdx = stoi(tmp);
                    } else if (idx == 3) {
                        val = stoi(tmp);
                    }
                    idx++;
                }
                TreeNode * tmpNode = new TreeNode(val);
                if (parentIdx == 0) {
                    ans = tmpNode;
                } else {
                    auto parentNode = tree[parentIdx];
                    if (isLeft) {
                        parentNode->left = tmpNode;
                    } else {
                        parentNode->right = tmpNode;
                    }
                }
                tree[nodeIdx] = tmpNode;
//                cout << "parentIdx->" << parentIdx << ",isLeft->" << isLeft << ",nodeIdx->" << nodeIdx << ",val->"
//                     << val << endl;
            }
        }
        return ans;
    }
};
