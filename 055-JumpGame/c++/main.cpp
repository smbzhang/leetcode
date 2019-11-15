#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/jump-game/
class Solution {
public:
    // 解法一：自底向上的动态规划，超时, 有一个case过不 这种的时间复杂度就是 O(n^2)了
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return true;
        vector<bool> dp(n, false);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {dp[i] = true; continue;}
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                if (dp[i + j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }

    // 解法二： 优化上面的自底向上动态规划，实现贪心算法
    // 上面循环当我们找到最左边的某个位置的true的时候，记录下来，当
    // 从右向左遍历，当前 i + nums[i] >= pos 更新pos
    bool canJump_2(vector<int>& nums) {
        int n = nums.size(), pos = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= pos) {
                pos = i;
            }
        }
        return pos == 0;
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
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        bool result = solution->canJump_2(nums);
        cout << result << endl;
    }
   
    return 0;
}
