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

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        auto tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        auto pcur = root;
        while (pcur->right) {
            pcur = pcur->right;
        }
        pcur->right = tmp;
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    solution->flatten(root);

    leetcode::common::MirrosInorderTraversal(root);
    cout << endl;
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;

    return 0;
}
