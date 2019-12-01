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

// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        // 这个地方真是一个死坑，result.size() 返回的是一个uint， 0 - 1 并不是 -1 ！！！！
        //for (int i = 0; i < result.size() - 1; i++) {
        //    if (result[i] >= result[i + 1]) return false;
        //}
        for (int i = 1; i < result.size(); i++) {
            if (result[i - 1] >= result[i]) return false;
        }
        return true;
    }
    void inorder(TreeNode *root, vector<int> &result) {
        if (root == nullptr) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    cout << solution->isValidBST(nullptr) << endl;

    return 0;
}
