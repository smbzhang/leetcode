#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    // 动态规划：超时 时间复杂度 O(n^2)
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                dp[i] = 0;
                continue;
            }
            int step = nums[i], min = INT_MAX;
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j >= n) {
                    dp[i] = 1;
                    break;
                }
                min = min < dp[i + j] + 1 ? min : dp[i + j] + 1;
            }
            dp[i] = min;
        }
        return dp[0];
    }

    // 贪心算法： 时间复杂度 O(n)
    int jump_2(vector<int> nums) {
        int end = 0, result = 0, max = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            max = std::max(max, nums[i] + i);
            if (i == end) {
                result++;
                end = max;
            }
        }
        return result;
    }
    
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array, nums);
        int result = solution->jump_2(nums);
        cout << result << endl;  
    }
   
    return 0;
}
