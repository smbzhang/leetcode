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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> record;
        dfs(root, sum, result, record);
        return result;
    }
    
    void dfs(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> &record) {
        if (root == nullptr) return;
        sum -= root->val;
        record.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == 0) {
                result.push_back(record);
            }
        }else {
            dfs(root->left, sum, result, record);
            dfs(root->right, sum, result, record);   
        }
        sum += root->val;
        record.pop_back();
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    solution->pathSum(root, 22);

    return 0;
}
