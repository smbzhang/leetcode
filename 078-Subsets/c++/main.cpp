#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/subsets/
class Solution {
public:
    // 解法一：遍历法
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret(1, vector<int>{});
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto result = ret;
            for (auto tmp : result) {
                if (tmp.empty()) continue;
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
            ret.push_back(vector<int>(1,nums[i]));
        }
        return ret;
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
        int result = solution->jump_2(nums);
        cout << result << endl;  
    }
   
    return 0;
}
