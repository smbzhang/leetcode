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

// https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    // 解法一： DFS
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr) return 1 + minDepth(root->right);
        if (root->right == nullptr) return 1 + minDepth(root->left);
        return std::min(minDepth(root->left) + 1, minDepth(root->right) + 1);
    }

    // 解法二： BFS
    int minDepth_2(TreeNode *root) {
        if (root == nullptr) return 0;
        int result = 0;
        std::queue<TreeNode *> myqueue;
        myqueue.push(root);
        while (!myqueue.empty()) {
            int size = myqueue.size();
            result++;
            for (int i = 0; i < size; i++) {
                root = myqueue.front();
                myqueue.pop();
                if (root->left == nullptr && root->right == nullptr) return result;
                if (root->left) myqueue.push(root->left);
                if (root->right) myqueue.push(root->right);
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
    cout << solution->minDepth_2(root) << endl;

    return 0;
}
