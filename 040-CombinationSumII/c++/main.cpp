#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> records;
        backtrace(candidates, target, result, 0, records);

        return result; 
    }

    void backtrace(vector<int>& candidates, int target, vector<vector<int> >& result, int pos, vector<int>& records) {
        if (target == 0) {
            result.push_back(records);
            return;
        }
        if (pos >= candidates.size()) return;
        if (target < candidates[pos]) return;
        for (int i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i - 1]) continue;
            records.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], result, i + 1, records);
            records.pop_back();
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
        int target;
        cout << "Please enter the target: " << endl;
        cin >> target;
        auto result = solution->combinationSum2(nums, target);
        for (auto array : result) {
            for (auto tmp : array) {
                cout << tmp << " ";
            }
            cout << endl;
        }
    }
   
    return 0;
}
