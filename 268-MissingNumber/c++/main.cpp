#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/missing-number/
class Solution {
public:
    // 解法一： 把出现数字的下标置为负数 time O(N)  space O(1)
    int missingNumber_1(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        nums.push_back(1);
        for (int i = 0; i < nums.size() - 1; i++) {
            nums[abs(nums[i])] = 0 - abs(nums[abs(nums[i])]);
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return i;
            if (nums[i] == 0) res = i;
        }
        return res;
    }
    // 解法二： 求和，先求总和，然后减去现有的和就是缺的，注意溢出
    int missingNumber_2(vector<int>& nums) {
        unsigned int sum = 0, sum2 = 0;
        for (int i = 0; i <= nums.size(); i++) {
            sum = (sum + i) % INT_MAX;
        }
        for (int i = 0; i < nums.size(); i++) {
            sum2 = (sum2 + nums[i]) % INT_MAX;
        }
        return sum - sum2;
    }
    // 解法三：位运算 - 异或
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= nums[i] ^ i;
        }
        return res ^ n;
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
        int result = solution->missingNumber(nums);
        cout << result << endl;  
    }
   
    return 0;
}
