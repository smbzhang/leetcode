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

// Definition for a Node.
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        dfs(root, result, 0);
        return result;
    }

    void dfs(TreeNode *root, int &result, int record) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            result += record * 10 + root->val;
        }
        dfs(root->left, result, record * 10 + root->val);
        dfs(root->right, result, record * 10 + root->val);
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,',');
    TreeNode *root = leetcode::common::ConstructTree(strs);
    
    Solution *solution = new Solution();
    cout << solution->sumNumbers(root) << endl;

    return 0;
}
