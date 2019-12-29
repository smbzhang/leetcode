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

// https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        loop(root, result, "");
        return result;
    }
    void loop(TreeNode *root, vector<string> &result, std::string str) {
        if (root == nullptr) return;
        if (!root->left && !root->right) {
            str += std::to_string(root->val);
            result.push_back(str);
            return;
        }
        str += std::to_string(root->val) + string("->");
        loop(root->left, result, str);
        loop(root->right, result, str);
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    solution->binaryTreePaths(root);

    return 0;
}
