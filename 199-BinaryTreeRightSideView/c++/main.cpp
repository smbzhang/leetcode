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

// https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        std::queue<TreeNode *> myqueue;
        myqueue.push(root);
        while (!myqueue.empty()) {
            int size = myqueue.size();
            for (int i = 0; i < size; i++) {
                root = myqueue.front();
                if (i == size - 1) result.push_back(root->val);
                if (root->left) myqueue.push(root->left);
                if (root->right) myqueue.push(root->right);
                myqueue.pop();
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
    vector<int> result = solution->rightSideView(root);
    for (auto tmp : result) {
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}
