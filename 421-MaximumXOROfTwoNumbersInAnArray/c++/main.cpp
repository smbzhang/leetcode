#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <climits>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Solution {
public:
    // 解法一： 暴力法：time: O(n^2) space: O(1)
    int findMaximumXOR_1(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = nums[i] ^ nums[j];
                res = tmp > res ? tmp : res;
            }
        }
        return res;
    }
    // 解法二： std::vector<unorderd_set<int>> array(31, )
    int findMaximumXOR(vector<int> &nums) {
        std::vector<std::unordered_set<int>> array(31, std::unordered_set<int>());
        for (int i = 0; nums.size(); i++) {
            for (int j = 0; j < 31; j++) {
                if (nums[i] & (1 << j)) array[j].emplace(nums[i]);
            }
        }
        for ()
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    for (int i = 0; i < strs.size(); i++) {
        std::vector<string> strings = leetcode::common::split(strs[i], ',');
        vector<int> nums; 
        leetcode::common::strings_to_numbers(strings, nums);
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        Solution solution;
        int ret = solution.findMaximumXOR(nums);
        cout << ret << endl;
    }
    
    return 0;
}
