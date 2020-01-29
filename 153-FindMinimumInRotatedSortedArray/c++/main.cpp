#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = INT_MAX;
        int n = nums.size(), start = 0, end = n - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            // 1. 如果 start <= mid,那么前半部分升序
            if (nums[start] <= nums[mid]) {
                result = nums[start] < result ? nums[start] : result;
                start = mid + 1;
            }
            // 2. start > mid, 那么后半部分升序
            else {
                result = nums[mid] < result ? nums[mid] : result;
                end = mid - 1;
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
