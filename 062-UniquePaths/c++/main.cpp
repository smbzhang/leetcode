#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/unique-paths/
int factorial(int m) {
    if (m <= 1) return 1;
    return m * factorial(m - 1);
}
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

    // 解法三：因为向下的步数是一定的，向右的步数也是一定的，总步数是 m + n - 2, 向下的步数是： n - 1。 所以结果是：Combination(n - 1, m + n - 2)
    // Combination(k, n) = n!/(k!(n - k)!)
    int uniquePaths_3(int m, int n) {
        // 这样不可以， 首先 factorial 会溢出。还要相乘，更要溢出了
        return factorial(m + n - 2) / (factorial(n - 1) * factorial(m - 1));
    }

    // 分析上面的排列式子，做相消处理
    int uniquePaths_4(int m, int n) {
        long long int result = 1;
        int N = m + n - 2;
        int K = m - 1;
        for (int i = 1; i <= K; i++) {
            result = result * (N - K + i) / i;
        }
        return static_cast<int>(result);
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    int m, n;
    cin >> m >> n;
    cout << solution->uniquePaths_4(m, n) << endl;

    return 0;
}
