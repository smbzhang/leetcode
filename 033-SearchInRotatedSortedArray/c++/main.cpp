#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            if (start == end && nums[start] == target) {
                return start;
            }
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            // 左边是有有序的
            if (nums[mid] >= nums[start]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                    continue;
                }else{
                    start = mid + 1;
                    continue;
                }
            }else{
                if (target <= nums[end] && target > nums[mid]) {
                    start = mid + 1;
                    continue;
                }else{
                    end = mid - 1;
                    continue;
                }
           }
        }
        return result; 
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
        int target;
        cout << "Please enter the target: " << endl;
        cin >> target;
        int result = solution->search(nums, target);
        cout << result << endl;
    }
   
    return 0;
}
