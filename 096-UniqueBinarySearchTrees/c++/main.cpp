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

// https://leetcode.com/problems/unique-binary-search-trees/
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
    int numTrees(int n) {
        if (n <= 0) return 0;
        return loop(1, n);
    }
    int loop (int i, int j) {
        if (i >= j) return 1;
        int result = 0;
        for (int m = i; m <= j; m++) {
            int lnum = loop(i, m - 1);
            int rnum = loop(m + 1, j);
            result += lnum * rnum;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int num;
    while (cin >> num) {
        cout << solution.numTrees(num) << endl; 
    }
    return 0;
}
