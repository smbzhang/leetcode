#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, n = nums.size(), end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return true;
            // 判断哪一部分是有序的，只要这个可以判断的话下面就是正常的二分查找算法了
            if (nums[mid] > nums[start]) {
                // 前半部分有序
                if(target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] == nums[start]) {
                start++;
            } else {
                // 后半部分有序
                if (target > nums[mid] && nums[end] >= target) start = mid + 1;
                else end = mid - 1;
            }
        }
        return false;
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
        int target;
        std::cin >> target;
        bool result = solution->search(nums, target);
        cout << result << endl;
    }
   
    return 0;
}
