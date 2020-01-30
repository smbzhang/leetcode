#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    // 这个题和153唯一的区别就是，排序数组的元素允许重复
    int findMin(vector<int>& nums) {
        int result = INT_MAX;
        int start = 0, end = nums.size() - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            // 1. 前半部分是有序的
            if (nums[start] < nums[mid]) {
                result = nums[start] < result ? nums[start] : result;
                start = mid + 1;
            }
            // 2. 后半部分是有序的
            else if (nums[start] > nums[mid]) {
                result = nums[mid] < result ? nums[mid] : result;
                end = mid - 1;
            }
            // 3. 不能确定是否有序的情况
            else {
                result = nums[start] < result ? nums[start] : result;
                start++;
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
        int result = solution->findMin(nums);
        cout << result << endl;  
    }
   
    return 0;
}
