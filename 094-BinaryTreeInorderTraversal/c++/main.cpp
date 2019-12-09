#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

// https://leetcode.com/problems/binary-tree-inorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 解法一： 递归（左根右）
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        loop(root, result);
        return result;
    }
    void loop(TreeNode *root, vector<int> &result) {
        if (root == nullptr) return;
        loop(root->left, result);
        result.push_back(root->val);
        loop(root->right, result);
    }
    // 栈实现 inorder 遍历
    vector<int> inorderTraversal_2(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> mystack;
        while (root != nullptr) {
            mystack.push(root);
            root = root->left;
        }
        while (!mystack.empty()) {
            root = mystack.top();
            mystack.pop();
            result.push_back(root->val);
            root = root->right;
            while(root != nullptr) {
                mystack.push(root);
                root = root->left;
            }
        }
        return result;
    }

    // 栈实现 inorder 遍历 - 再优雅一点
    vector<int> inorderTraversal_3(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> mystack;
        while (root != nullptr || !mystack.empty()) {
            while(root != nullptr) {
                mystack.push(root);
                root = root->left;
            }
            root = mystack.top();
            mystack.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }

    // Mirrors 中序遍历，实现 O(1)的空间复杂度，不使用递归，不实用额外的栈空间
    // 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
    // 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
    // 2.1 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
    // 2.2 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
    // 3. 重复以上1、2直到当前节点为空。
    vector<int> inorderTraversal_4(TreeNode *root) {
        vector<int> result;
        while (root) {
            if (root->left == nullptr) {
                result.push_back(root->val);
                root = root->right;
            }else {
                // 寻找前驱结点
                TreeNode *prenode = nullptr, *l = root->left;
                while (l->right != nullptr && l->right != root) {
                    l = l->right;
                }
                // 2.1
                if (l->right == nullptr) {
                    l->right = root;
                    root = root->left;
                }
                // 2.2
                else {
                    l->right = nullptr;
                    result.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return result;
    }
};
int main() {
    return 0;
}
