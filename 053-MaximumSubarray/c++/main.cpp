#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    // 解法一： 动态规划实现
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), max = INT_MIN;
        vector<int> records(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                records[i] = nums[i];
                max = std::max(max, records[i]);
            }            
            else {
                if (records[i + 1] > 0) {
                    records[i] = nums[i] + records[i + 1];
                    max = std::max(max, records[i]);
                }else{
                    records[i] = nums[i];
                    max = std::max(max, records[i]);
                }
            }
        }
        return max;
    }
    // 解法二： 贪心算法
    int maxSubArray_2(vector<int>& nums) {
        int n = nums.size(), sum = 0, max = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            max = std::max(sum, max);
            sum = std::max(0, sum);
        }
        return max;
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
        int result = solution->maxSubArray_2(nums);
        cout << result << endl;   
    }

    return 0;
}
