#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
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
};
int main() {
    return 0;
}
