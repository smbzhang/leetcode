#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > results;
        int pos = 0;
        loop (nums, results, 0);
        return results;
    }
    void loop(vector<int> &nums, vector<vector<int> >&results, int pos) {
        if (pos >= nums.size()) return;
        if (pos == nums.size() - 1) {
            results.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            // 这个地方不能这么去重，考虑这样一种情况，00012,和2交换之后20010，这个时候后面就不是排序的顺序了
            if (i != pos && nums[i] == nums[i - 1]) continue;
            std::swap(nums[pos], nums[i]);
            // 交换之后需要保证pos后面的数据是 排序好的
            int j = pos + 1;
            for (; j < i; j++) {
                if (nums[j] > nums[i]) break;
            }
            if (pos != i) std::swap(nums[i], nums[j]);
            loop(nums, results, pos + 1);
            if (pos != i) std::swap(nums[i], nums[j]);
            std::swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique_2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > results;
        int pos = 0;
        loop_2 (nums, results, 0);
        return results;
    }

    void loop_2(vector<int> &nums, vector<vector<int> >&results, int pos) {
        if (pos >= nums.size()) return;
        if (pos == nums.size() - 1) {
            if (!isrepeate(nums)) results.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            std::swap(nums[pos], nums[i]);
            loop_2(nums, results, pos + 1);
            std::swap(nums[pos], nums[i]);
        }
    }

    bool isrepeate(const vector<int> &nums) {
        string str = "";
        for (auto i : nums) {
            str += i + '0';
        }
        if (v.find(str) == v.end()) {
            v.insert(str);
            return false;
        }
        return true;
    }

private:
    std::unordered_set<string> v;

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
        vector<vector<int> > result = solution->permuteUnique(nums);
        for (auto tmps : result) {
            for (auto tmp : tmps) {
                cout << tmp << " ";
            }
            cout << endl;
        }
    }
   
    return 0;
}
