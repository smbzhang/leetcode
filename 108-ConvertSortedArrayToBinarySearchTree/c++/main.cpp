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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *result = loop(nums, 0, nums.size() - 1);
        return result;
    }

    TreeNode *loop(vector<int>& nums, int i, int j) {
        if (i > j) return nullptr;
        int mid = (i + j) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = loop(nums, i, mid - 1);
        root->right = loop(nums, mid + 1, j);
        return root;
    }
};

int main() {
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    std::vector<string> array_s  = leetcode::common::split(str,',');
    std::vector<int> nums;
    leetcode::common::strings_to_numbers<int>(array_s, nums);
    
    Solution *solution = new Solution();
    auto root = solution->sortedArrayToBST(nums);

    leetcode::common::MirrosInorderTraversal(root);

    return 0;
}
