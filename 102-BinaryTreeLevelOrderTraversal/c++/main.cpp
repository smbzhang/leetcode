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

// https://leetcode.com/problems/same-tree/
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
    // 解法一: 使用 BFS 广搜
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        std::queue<TreeNode *> myqueue;
        while (!myqueue.empty() || root != nullptr) {
            if (myqueue.empty() && root != nullptr) {
                myqueue.push(root);
                continue;
            }else {
                int size = myqueue.size();
                vector<int> tmp;
                for (int i = 0; i < size; i++) {
                    root = myqueue.front();
                    myqueue.pop();
                    if (root != nullptr) {
                        tmp.push_back(root->val);
                        myqueue.push(root->left);
                        myqueue.push(root->right);
                    }
                }
                if(tmp.size() > 0) result.push_back(tmp);
            }
        }
        return result;
    }

    // 解法二: preorder 前序遍历解决 (深度优先搜索)
    vector<vector<int> > levelOrder_2(TreeNode *root) {
        int dep = depth(root);
        vector<vector<int> > result(dep, vector<int>());
        dfs(root, 0, result);
        return result;
    }

    int depth(TreeNode *root) {
        if (root == nullptr) return 0;
        return std::max(depth(root->left) + 1, depth(root->right) + 1);
    }

    void dfs(TreeNode *root, int level, vector<vector<int> >& result) {
        if (root == nullptr) return;
        result[level].push_back(root->val);
        dfs(root->left, level + 1, result);
        dfs(root->right, level + 1, result);
    }
    
};
int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    solution->levelOrder(root);

    return 0;
}
