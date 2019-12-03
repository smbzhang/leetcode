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

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        std::queue<TreeNode *> myqueue;
        int flag = 1;
        while (root || !myqueue.empty()) {
            if (myqueue.empty() && root != nullptr) {
                myqueue.push(root);
                continue;
            }
            int size = myqueue.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                root = myqueue.front();
                myqueue.pop();
                if (root != nullptr) {
                    if (flag % 2) tmp.push_back(root->val);
                    else tmp.insert(tmp.begin(), root->val);
                    myqueue.push(root->left);
                    myqueue.push(root->right);
                }
            }
            if (tmp.size() > 0) result.push_back(tmp);
            flag++;
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
    auto result = solution->zigzagLevelOrder(root);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
