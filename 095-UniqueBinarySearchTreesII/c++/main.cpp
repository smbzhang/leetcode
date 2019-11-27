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

// https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> result;
        if (n == 0) return result;
        result = loop(1, n);
        return result;
    }

    vector<TreeNode *> loop(int m, int n) {
        vector<TreeNode *> result;
        if (m > n) {
            result.push_back(nullptr);
            return result;
        }
        if (m == n) {
            result.push_back(new TreeNode(m));
            return result;
        }
        for (int i = m; i <= n; i++) {
            vector<TreeNode *> lres = loop(m, i - 1);
            vector<TreeNode *> rres = loop(i + 1, n);
            for (int k = 0; k < lres.size(); k++) {
                for (int l = 0; l < rres.size(); l++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lres[k];
                    root->right = rres[l];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    solution.generateTrees(3);
    return 0;
}
