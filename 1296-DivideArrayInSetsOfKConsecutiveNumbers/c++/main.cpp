#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
class Solution {
public:
    // 1. 循环法，超时
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k) return false;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n / k; i++) {
            vector<int> tmp(k, 0);
            for (int j = 0; j < k; j++) {
                for (int m = 0; m < n; m++) {
                    if (nums[m] != 0 && (j == 0 || (j > 0 &&nums[m] > tmp[j - 1])) ) {
                        tmp[j] = nums[m];
                        nums[m] = 0;
                        break;
                    }
                }
            }
            for (int j = 0; j < tmp.size(); j++) {
                if (j > 0 && tmp[j] - tmp[j - 1] != 1) return false;
            }
        }
        return true;
    }
    // hashmap 解法
    bool isPossibleDivide_2(vector<int> &nums, int k) {
        int n = nums.size();
        if (n % k) return false;
        std::sort(nums.begin(), nums.end());
        std::unordered_map<int, int> mp;
        mp.clear();
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] == 0) continue;
            mp[nums[i]]--;
            for (int j = 1; j < k; j++) {
                if (mp[nums[i] + j] == 0) return false;
                mp[nums[i] + j]--;
            }
            time++;
            if (time == n / k) return true;
        }
        return true;
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
        cout << solution->isPossibleDivide_2(nums, 4) << endl;;
    }
   
    return 0;
}
