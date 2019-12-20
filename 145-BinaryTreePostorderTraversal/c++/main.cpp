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

// https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode *> mystack;
        vector<int> result;
        TreeNode *pre = nullptr;
        while (root || !mystack.empty()) {
            while (root) {
                mystack.push(root);
                root = root->left;
            }
            auto node = mystack.top();
            if (node->right && node->right != pre) {
                root = node->right;
            }else {
                result.push_back(node->val);
                pre = node;
                mystack.pop();
            }
        }
    return result;
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    vector<int> result = solution->postorderTraversal(root);

    return 0;
}
