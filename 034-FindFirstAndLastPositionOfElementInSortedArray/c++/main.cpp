#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int retstart = INT_MAX, retend = INT_MIN;
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            if (start == end && nums[start] == target) {
                retstart = start < retstart ? start : retstart;
                break;
            }
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                retstart = mid < retstart ? mid : retstart;
                end = mid - 1;
                continue;
            }
            if (target < nums[mid]) {
                end = mid - 1;
                continue;
            }else{
                start = mid + 1;
                continue;
            }
        }
        start = 0;
        end = nums.size() - 1;
        while (start <= end) {
            if (start == end && target == nums[start]) {
                retend = start > retend ? start : retend;
                break;
            }
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                retend = mid > retend ? mid : retend;
                start = mid + 1;
                continue;
            }
            if (target < nums[mid]) {
                end = mid - 1;
                continue;
            }else{
                start = mid + 1;
                continue;
            }
        }
        return vector<int>{retstart == INT_MAX ? -1 : retstart, retend == INT_MIN ? -1 : retend};
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
        auto result = solution->searchRange(nums, target);
        cout << result[0] << " : " << result[1] << endl;
    }
   
    return 0;
}
