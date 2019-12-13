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
    // 注意： root 结点不是叶子结点(【1，2】，1  返回false ！！！)
    bool hasPathSum(TreeNode* root, int sum) {
        // DFS 深搜
        return dfs(root, 0, sum);
    }

    bool dfs(TreeNode *root, int num, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return num + root->val == sum;
        num += root->val;
        bool retl = dfs(root->left, num, sum);
        bool retr = dfs(root->right, num, sum);
        return retl || retr;
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    cout << solution->hasPathSum(root, 22) << endl;

    return 0;
}
