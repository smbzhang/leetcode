#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int records[31] = {0};
        for (int j = nums.size(); j >= 0; j--) {
            for (int i = 0; i < 31; i++) {
                records[i] += nums[j] & (1 << i) == 0 ? 0 : 1;
            }
        }
        int result = 0;
        for (int i = 0; i < 31; i++) {
            if (records[i] % 3 != 0) {
                result += 1 << i;
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
        cout << solution->singleNumber(nums) << endl;;
    }
   
    return 0;
}
