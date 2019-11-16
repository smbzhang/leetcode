#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/insert-interval/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        if (i == intervals.size()) intervals.push_back(newInterval);
        vector<vector<int> > result;
        int n = intervals.size();
        vector<int> records(2, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) records = intervals[i];
            if (i + 1 < n && intervals[i + 1][0] <= records[1]) {
                records[1] = std::max(records[1], intervals[i + 1][1]);
            }
            else {
                result.push_back(records);
                if (i + 1 < n) records = intervals[i + 1];
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
    vector<vector<int> > matrix;
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        matrix.push_back(nums);
    }
    std::vector<int> newInterval = {4, 8};
    vector<vector<int> > result = solution->insert(matrix, newInterval);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << "," << result[i][1] << "  "; 
    }
    cout << endl;
    return 0;
}
