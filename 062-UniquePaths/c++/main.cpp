#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
// https://leetcode.com/problems/unique-paths/
class Solution {
public:
    // 解法一：回溯法，超时
    int uniquePaths(int m, int n) {
        int result = 0;
        backtrace(m , n, 0, 0, result);
        return result;
    }

    void backtrace(int m, int n, int i, int j, int &result) {
        if (i >= m || j >= n) return;
        if (i == m - 1 && j == n - 1) {
            result++;
            return;
        }
        backtrace(m, n, i + 1, j, result);
        backtrace(m, n, i, j + 1, result);
    }

    // 解法二： 动态规划 dp[m][n] = dp[m - 1][n] + dp[m][n - 1]
    int uniquePaths_2(int m, int n) {
        int result = 0;
        vector<vector<int> > dp(m,vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    int m, n;
    cin >> m >> n;
    cout << solution->uniquePaths_2(m, n) << endl;

    return 0;
}
