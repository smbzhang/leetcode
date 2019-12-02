#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include "datastruct/data_struct.h"
#include <algorithm>
#include <map>
#include <stack>
#include <climits>
using namespace std;
using namespace leetcode::common;

// https://leetcode.com/problems/recover-binary-search-tree/
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
    // 解法一： 空间复杂度，O(n)
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        int MIN = INT_MAX;
        vector<TreeNode *> records;
        stack<TreeNode *> mystack;
        while (root != nullptr || !mystack.empty()) {
            while (root != nullptr) {
                mystack.push(root);
                root = root->left;
            }
            root = mystack.top();
            records.push_back(root);
            mystack.pop();
            root = root->right;
        }
        int i;
        for (i = 0; i < (int)(records.size()) - 1; i++) {
            if (first == nullptr && records[i]->val > records[i + 1]->val) {
                first = records[i];
                break;
            }
        }
        for (; i < records.size(); i++) {
            if (first != nullptr && records[i]->val < MIN) {
                MIN = records[i]->val;
                second = records[i];
            }
        }
        if (first && second) {
            auto tmp = second->val;
            second->val = first->val;
            first->val = tmp;
        }
    }

    // 在in-order递归过程中，进行判断，虽然没用栈，但是还是使用了递归，使用递归控价复杂度就不是 O(1)
    void recoverTree_2(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        pre = nullptr;
        loop(root);
        if (first && second) std::swap(first->val, second->val);
    }
    void loop(TreeNode *root) {
        if (root == nullptr) return;
        loop(root->left);
        if (pre == nullptr) pre = root;
        else {
            if (first == nullptr && pre->val > root->val) first = pre;
            if (first != nullptr && pre->val > root->val) second = root;
        }
        pre = root;
        loop(root->right);
    }

private:
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    solution->recoverTree_2(root);
    

    return 0;
}
