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

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return looper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode *looper(vector<int> &inorder, int i, int j, vector<int> &postorder, int m, int n) {
        if (i > j || m > n) return nullptr;
        TreeNode *root = new TreeNode(postorder[n]);
        if (i == j && m == n) return root;
        int mid = std::find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        root->left = looper(inorder, i, mid - 1, postorder, m, m + mid - i - 1);
        root->right = looper(inorder, mid + 1, j, postorder, m + mid - i, n - 1);
        return root;
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    //solution->buildTree(root);

    return 0;
}
