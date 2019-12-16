#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include "datastruct/data_struct.h"
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using namespace leetcode::common;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node *parent = nullptr;
        Node *result = root;
        dfs(root, parent);
        return result;
    }

    void dfs(Node *root, Node *parent) {
        if (root == nullptr) return;
        if (parent == nullptr) root->next = nullptr;
        else {
            // 如果改节点是父节点的左孩子
            if (parent->left == root) {
                root->next = parent->right;
            }else {
                if (parent->next == nullptr) root->next = nullptr;
                else root->next = parent->next->left;
            }
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }

};

int main() {    
    Solution *solution = new Solution();
    return 0;
}
