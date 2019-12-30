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
    // 解法一: 使用 hash table
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        mp.clear();
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto tmp : mp) {
            if (tmp.second == 1) return tmp.first;
        }
        return 0;
    }
    // 解法二: 使用 XOR 异或 - a ^ a = 0
    int singleNumber_2(vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
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
        cout << solution->singleNumber_2(nums) << endl;;
    }
   
    return 0;
}
