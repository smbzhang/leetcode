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

    // Mirros 中旭遍历，空间复杂度 O（1）
    // Mirrors 中序遍历，实现 O(1)的空间复杂度，不使用递归，不实用额外的栈空间
    // 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
    // 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
    // 2.1 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
    // 2.2 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
    // 3. 重复以上1、2直到当前节点为空。
    void recoverTree_3(TreeNode *root) {
        while (root) {
            if (root->left == nullptr) {
                if (pre == nullptr) pre = root;
                else {
                    if (first == nullptr && pre->val > root->val) first = pre;
                    if (first != nullptr && pre->val > root->val) {
                        second = root;
                    }
                    pre = root;
                }
                root = root->right;
            }
            else {
                TreeNode *l = root->left;
                while (l->right != nullptr && l->right != root) {
                    l = l->right;
                }
                if (l->right == nullptr) {
                    l->right = root;
                    root = root->left;
                }else {
                    l->right = nullptr;
                    if (pre == nullptr) pre = root;
                    else {
                        if (first == nullptr && pre->val > root->val) first = pre;
                        if (first != nullptr && pre->val > root->val) {
                            second = root;
                        }
                        pre = root;
                    }
                    root = root->right;
                }
            }
        }
        if (first && second) std::swap(first->val, second->val);
        cout << first->val << " " << second->val << endl;
    }
private:
    TreeNode *pre = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    solution->recoverTree_3(root);
    

    return 0;
}
