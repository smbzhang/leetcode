#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    // 解法一：一次遍历法 时间复杂度 O(n)
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int pre = INT_MIN;
        nums.push_back(INT_MIN);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > pre && nums[i] > nums[i + 1]) {
                return i;
            }
            pre = nums[i];
        }
        return 0;
    }
    
    // 解法二：二分法求解 时间复杂度 O(logn)
    int findPeakElement_2(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, mid, result = 0;
        while (start < end) {
            mid = (start + end) / 2;
            // 因为 nums[-1] = nums[n] = -∞ 所以 nums[mid] < nums[mid + 1] 那么峰值一定在 mid + 1 和 end 之间
            if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
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
        int result = solution->findPeakElement(nums);
        cout << result << endl;  
    }
   
    return 0;
}
