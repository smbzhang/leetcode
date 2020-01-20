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

// https://leetcode.com/problems/majority-element/
class Solution {
public:
    // 排序解 - 时间复杂度 O(nlgn) 空间复杂度 O(1)
    int majorityElement_1(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
    // hashmap解 - 时间复杂度 O(n) 空间复杂度 O(n)
    int majorityElement_2(vector<int>& nums) {
        std::unordered_map<int, int> _map;
        for (auto tmp : nums) {
            _map[tmp]++;
        }
        for (auto iter : _map) {
            if (iter.second > nums.size() / 2) return iter.first;
        }
        return 0;
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
        int result = solution->majorityElement(nums);
        cout << result << endl;  
    }
   
    return 0;
}
