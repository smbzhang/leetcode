#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include "datastruct/data_struct.h"
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
using namespace leetcode::common;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    // 递归实现
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    cout << solution->maxDepth(root) << endl;

    return 0;
}
