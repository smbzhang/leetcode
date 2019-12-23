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

// https://leetcode.com/problems/count-complete-tree-nodes/
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
    // 解法一：遍历二叉树
    int countNodes_3(TreeNode* root) {
        result = 0 ;
        loop(root);
        return result;
    }
    void loop(TreeNode *root) {
        if (root == nullptr) return;
        result++;
        loop(root->left);
        loop(root->right);
    }
    int result = 0;

    // 解法二: 递归求解
    int countNodes_2(TreeNode *root) {
        if (root == nullptr) return 0;
        return 1 + countNodes_2(root->left) + countNodes_2(root->right);
    }
    // 解法三: 利用完全二叉树的特性来进行递归
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int left = countLevel(root->left);
        int right = countLevel(root->right);
        // left == right 左子树是一个完美二叉树
        if (left == right) {
            return (1 << left) + countNodes(root->right);
        }
        // 否则,右子树的倒数第二层是满二叉树，可以直接得到 右子树的结点书
        return countNodes(root->left) + (1 << right);
    }
    int countLevel(TreeNode * root) {
        int ans = 0;
        while (root) {
            ans++;
            root = root->left;
        }
        return ans;
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    cout << solution->countNodes(root) << endl;

    return 0;
}
