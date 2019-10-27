#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> records;
        //find(candidates, target, records, result, 0);
        backtrace(candidates, target, records, result, 0);
        return result;
    }

    void find(vector<int>& candidates, int target, vector<int>& records, vector<vector<int> >& result, int start) {
        for (int i = start; i < candidates.size(); i++) {
            records.push_back(candidates[i]);
            if (target == candidates[i]) {
                result.push_back(records);
                records.pop_back();
                return;
            }
            if (target < candidates[i]) {
                records.pop_back();
            }else{
                target -= candidates[i];
                find(candidates, target, records, result, i);
                target += candidates[i];
                records.pop_back();
            }
        }
    }

    void backtrace(vector<int>& candidates, int target, vector<int>& records, vector<vector<int> >& result, int start) {
        if (target == 0) result.push_back(records);
        if (target < 0) return;
        for (int i = start; i < candidates.size(); i++) {
            records.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], records, result, i);
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
        auto result = solution->combinationSum(nums, target);
        for (auto array : result) {
            for (auto tmp : array) {
                cout << tmp << " ";
            }
            cout << endl;
        }
    }
   
    return 0;
}
