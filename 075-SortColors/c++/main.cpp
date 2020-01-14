#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos0 = 0, pos2 = nums.size(), i = 0;
        while (i < pos2) {
            if (nums[i] == 2) {
                std::swap(nums[--pos2], nums[i]);
            }
            else if (nums[i] == 0) {
                std::swap(nums[i], nums[pos0]);
                pos0++;
                i++;
            } else {
                i++;
            }
        }
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
        solution->sortColors(nums);
    }
   
    return 0;
}
