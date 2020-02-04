#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/dungeon-game/
class Solution {
public:
    // 解法一： DFS 深搜解法  通过41/45，后面的超时了
    // 遍历所有的路径，并且记录下每个路径经过的时候的最小值
    // 一条路静到达终点的时候，进行结算，找到每个路径图中最小值中的最大值，如果最大值>0，返回1，最大值小于0，返回 -max + 1
    // 下面 max 表示最终的max， min：每条路径中所经过的最小的瞬间值， cur：表示当前经过的路径中的和
    int calculateMinimumHP_2(vector<vector<int>>& nums) {
        int cur = 0, m = nums.size(), n = nums[0].size();
        int max = INT_MIN, min = INT_MAX;
        backtrace(nums, 0, 0, cur, max, min, m, n);
        return max > 0 ? max : -max + 1;
    }
    void backtrace(vector<vector<int>> &nums, int i, int j, int cur, int &max, int min, int m, int n) {
        if (i >= m || j >= n) return;
        cur += nums[i][j];
        min = cur < min ? cur : min;
        if (i == m - 1 && n - 1 == j) {
            max = min > max ? min : max;
        }
        backtrace(nums, i + 1, j, cur, max, min, m, n);
        backtrace(nums, i, j + 1, cur, max, min, m, n);
    }

    // 解法二： DP
    // dp[i][j] 代表这个点需要的最小血量 dp[m - 1][n - 1] = nums[m - 1][n - 1] > 0 ? 1 : 1 - nums[m - 1][n - 1]
    // tmp = min(dp[i + 1][j], dp[i][j + 1]) - nums[i][j]
    // dp[i][j] = tmp <= 0 ? 1 : tmp
    int calculateMinimumHP(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int tmp = std::min(dp[i + 1][j], dp[i][j + 1]) - nums[i][j];
                dp[i][j] = tmp <= 0 ? 1 : tmp;
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
    int result = solution->calculateMinimumHP(matrix);
    cout << result << endl;
    return 0;
}
