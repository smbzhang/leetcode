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

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    // 解法一： dfs (preorder)
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        dfs(root, 0, result);
        std::reverse(result.begin(), result.end());
        return result;
    }

    void dfs(TreeNode *root, int level, vector<vector<int> >&result) {
        if (root == nullptr) return;
        //if (result.size() == 0) result.push_back(vector<int>());
        if (result.size() <= level) result.push_back(vector<int>());
        result[level].push_back(root->val);
        dfs(root->left, level + 1, result);
        dfs(root->right, level + 1, result);
    }

    // 解法二： BFS
    vector<vector<int> > levelOrderBottom_2(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr) return result;
        std::queue<TreeNode *> myqueue;
        myqueue.push(root);
        int level = 0;
        while (!myqueue.empty()) {
            int size = myqueue.size();
            for (int i = 0; i < size; i++) {
                if (result.size() <= level) result.push_back(vector<int>());
                root = myqueue.front();
                result[level].push_back(root->val);
                myqueue.pop();
                if (root->left) myqueue.push(root->left);
                if (root->right) myqueue.push(root->right);
            }
            level++;
        }
        std::reverse(result.begin(), result.end());
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
    vector<vector<int> > result = solution->levelOrderBottom_2(root);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
