#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int result = INT_MAX, m = grid.size(), n = 0;
        if (m != 0) n = grid[0].size();
        if (m == 0 || n == 0) return 0;
        backtrace(grid, m, n, 0, 0, result, 0);
        return result;
    }
    // 回溯法超时
    void backtrace(vector<vector<int> >& grid, int m, int n, int i, int j, int &result, int records) {
        if (i >= m || j >= n) return;
        if (i == m - 1 && j == n - 1) {
            result = std::min(result, records + grid[i][j]);
            return;
        }
        records += grid[i][j];
        backtrace(grid, m , n, i + 1, j, result, records);
        backtrace(grid, m, n, i, j + 1, result, records);
    }

    // DP algorithm  O(m * n)
    int minPathSum_2(vector<vector<int> >& grid) {
        int m = grid.size(), n = 0;
        if (m != 0) n = grid[0].size();
        if (m == 0 || n == 0) return 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[m - 1][i] = grid[m - 1][i] + dp[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + std::min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};

int main() {
    vector<int> nums1; 
    vector<int> nums2;
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    vector<vector<int> > matrix;
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        matrix.push_back(nums);
    }
    int result = solution->minPathSum(matrix);
    cout << result << endl;
    return 0;
}
