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
};
int main() {
    return 0;
}
