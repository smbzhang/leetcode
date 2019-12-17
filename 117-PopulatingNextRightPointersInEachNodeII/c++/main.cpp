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
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
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
                if (parent->right != nullptr) root->next = parent->right;
                else if (parent->next != nullptr) {
                    auto pcur = parent->next;
                    while (pcur != nullptr && pcur->left == nullptr && pcur->right == nullptr) {
                        pcur = pcur->next;
                    }
                    if (pcur == nullptr) root->next = nullptr;
                    else if (pcur->left != nullptr) root->next = pcur->left;
                    else root->next = pcur->right;
                }
                else {
                    root->next = nullptr;
                }
            }else {
                auto pcur = parent->next;
                while (pcur != nullptr && pcur->left == nullptr && pcur->right == nullptr) {
                    pcur = pcur->next;
                }
                if (pcur == nullptr) root->next = nullptr;
                else if (pcur->left != nullptr) root->next = pcur->left;
                else root->next = pcur->right;
            }
        }
        dfs(root->right, root);
        dfs(root->left, root);
    }
};

class Solution2 {
public:
    TreeNode* connect(TreeNode* root) {
        TreeNode *parent = nullptr;
        TreeNode *result = root;
        dfs(root, parent);
        return result;
    }

    void dfs(TreeNode *root, TreeNode *parent) {
        if (root == nullptr) return;
        if (parent == nullptr) root->next = nullptr;
        else {
            if (parent->val == 4) {
                std::cout << "fuck" << std::endl;
            }
            // 如果改节点是父节点的左孩子
            if (parent->left == root) {
                if (parent->right != nullptr) root->next = parent->right;
                else if (parent->next != nullptr) {
                    auto pcur = parent->next;
                    while (pcur != nullptr && pcur->left == nullptr && pcur->right == nullptr) {
                        pcur = pcur->next;
                    }
                    if (pcur == nullptr) root->next = nullptr;
                    else if (pcur->left != nullptr) root->next = pcur->left;
                    else root->next = pcur->right;
                }
                else {
                    root->next = nullptr;
                }
            }else {
                if (parent->val == 2) {
                    std::cout << "fuck" << std::endl;
                }
                auto pcur = parent->next;
                while (pcur != nullptr && pcur->left == nullptr && pcur->right == nullptr) {
                    pcur = pcur->next;
                }
                if (pcur == nullptr) root->next = nullptr;
                else if (pcur->left != nullptr) root->next = pcur->left;
                else root->next = pcur->right;
            }
        }
        dfs(root->right, root);
        dfs(root->left, root);
    }
};
int main() {   
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
 
    Solution2 *solution = new Solution2();
    
    solution->connect(root);

    while (root) {
        auto pcur = root;
        while (pcur) {
            std::cout << pcur->val << " ";
            pcur = pcur->next;
        }
        std::cout << std::endl;
        root = root->left;
    }

    return 0;
}
