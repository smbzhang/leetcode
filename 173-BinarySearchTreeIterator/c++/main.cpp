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

// https://leetcode.com/problems/binary-search-tree-iterator/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
    }

    /** @return the next smallest number */
    int next() {
        if (!this->hasNext()) return 0;
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        int result = root->val;
        root = root->right;
        mystack.pop();
        return result;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return root || !mystack.empty();
    }
private:
    std::stack<TreeNode *> mystack;
    TreeNode *root;
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);

    BSTIterator biter(root);
    while (biter.hasNext()) {
        cout << biter.next() << " ";
    }
    cout << endl;

    return 0;
}
