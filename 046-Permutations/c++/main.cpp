#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/permutations/
class Solution {
public:
    // 回溯法，代码写的比较丑陋
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> >result;
        if (nums.empty()) return result;
        if (nums.size() == 1) {
            result.push_back(vector<int>(1, nums[0]));
        } 
        for (int i = 0; i < nums.size(); i++) {
            std::swap(nums[i], nums[0]);
            vector<int>tmp(nums.begin() + 1, nums.end());
            vector<vector<int> > ret = permute(tmp);
            for (int i = 0; i < ret.size(); i++) {
                ret[i].insert(ret[i].begin(), nums[0]);
                result.push_back(ret[i]);
            }
            std::swap(nums[i], nums[0]);
        }
        return result;
    }
    
    vector<vector<int> > permute_2(vector<int>& nums) {
        vector<vector<int> > results;
        loop(nums, results, 0);
        return results;
    }
    void loop(vector<int>& nums, vector<vector<int> >& results, int pos) {
        if (pos >= nums.size()) return;
        if (pos == nums.size() - 1) {
            results.push_back(nums);
        }
        for (int i = pos; i < nums.size(); i++) {
            std::swap(nums[pos], nums[i]);
            loop(nums, results, pos + 1);
            std::swap(nums[pos], nums[i]);
        }
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
        vector<vector<int> > result = solution->permute_2(nums);
        for (auto tmps : result) {
            for (auto tmp : tmps) {
                cout << tmp << " ";
            }
            cout << endl;
        }
    }
   
    return 0;
}
