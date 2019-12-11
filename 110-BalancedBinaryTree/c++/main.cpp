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

// https://leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        // 判断当前结点的左右子树是不是平衡
        int lh = height(root->left), rh = height(root->right);
        // 判断当前结点的左右子树是不是都平衡
        return isBalanced(root->left) && isBalanced(root->right) && (std::abs(lh - rh) <= 1);
    }

    int height(TreeNode *root) {
        if (root == nullptr) return 0;
        return std::max(height(root->left) + 1, height(root->right) + 1);
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    cout << solution->isBalanced(root) << endl;

    return 0;
}
