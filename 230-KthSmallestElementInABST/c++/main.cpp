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

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    // 解法一： 中旭遍历
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        loop(root, k, result);
        return result;
    }
    void loop (TreeNode *root, int &k, int& result) {
        if (root == nullptr) return;
        loop (root->left, k, result);
        if (--k == 0) {
            result = root->val;
            return;
        }
        loop (root->right, k, result);
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    cout << solution->kthSmallest(root, 3) << endl;

    return 0;
}
