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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        int size1 = preorder.size(), size2 = inorder.size();
        if (size1 == 0) return nullptr;
        if (size1 != size2) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        if (size1 == 1) return root;
        auto pos = find(inorder.begin(), inorder.end(), preorder[0]);
        int diff = pos - inorder.begin();
        root->left = buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + 1 + diff),\
                vector<int>(inorder.begin(), pos));
        root->right = buildTree(vector<int>(preorder.begin() + diff + 1, preorder.end()),\
                vector<int>(pos + 1, inorder.end()));

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
