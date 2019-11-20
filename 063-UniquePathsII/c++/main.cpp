#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int result = 0;
        backtrace(obstacleGrid, 0, 0, result);
        return result;
    }
    // 回溯，又超时了
    void backtrace(const vector<vector<int> >& obstacleGrid, int i, int j, int &result) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (i >= m || j >= n) return;
        if (i == m - 1 && j == n - 1) {
            if (obstacleGrid[i][j] != 1) result++;
            return;
        }
        if (obstacleGrid[i][j] == 1) return;
        backtrace(obstacleGrid, i + 1, j, result);
        backtrace(obstacleGrid, i, j + 1, result);
    }
    
    // dp
    int uniquePathsWithObstacles_2(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (m == 0 || n == 0) return 1;
        // 防止 dp 溢出，采用 long long int
        vector<vector<long long int> > dp(m, vector<long long int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            if (n > 0 && obstacleGrid[i][n - 1] != 1) dp[i][n - 1] = 1;
            else break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (m > 0 && obstacleGrid[m - 1][i] != 1) dp[m - 1][i] = 1;
            else break;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                // 这里会溢出，注意
                if (obstacleGrid[i][j] != 1) dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                else  dp[i][j] = 0;
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
    int result = solution->uniquePathsWithObstacles_2(matrix);
    cout << result << endl;
    return 0;
}
