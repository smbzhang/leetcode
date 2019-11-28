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
        vector<vector<int> > records(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            records[i][i] = 1;
        }
        return loop(1, n, records);
    }
    int loop (int i, int j, vector<vector<int> >&records) {
        if (i >= j) return 1;
        if (records[i][j] != 0) return records[i][j];
        int result = 0;
        for (int m = i; m <= j; m++) {
            int lnum = loop(i, m - 1, records);
            int rnum = loop(m + 1, j, records);
            result += lnum * rnum;
        }
        records[i][j] = result;
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
