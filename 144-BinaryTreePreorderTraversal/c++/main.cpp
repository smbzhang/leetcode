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

// https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> mystack;
        vector<int> result;
        while (root || !mystack.empty()) {
            while (root) {
                result.push_back(root->val);
                mystack.push(root);
                root = root->left;
            }
            root = mystack.top();
            mystack.pop();
            root = root->right;
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
    vector<int> result = solution->preorderTraversal(root);
    for (auto tmp : result) {
        cout << tmp << " ";
    }
    cout << endl;

    return 0;
}
