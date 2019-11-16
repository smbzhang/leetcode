#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/merge-intervals/

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int> > result;
        int n = intervals.size();
        vector<int> records(2, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) records = intervals[i];
            //if (i + 1 < n && ((records[1] >= intervals[i + 1][0] && records[1] <= intervals[i + 1][1])
            //                   || records[1] >= intervals[i + 1][0] && records[1] >= intervals[i + 1][1])) {
            //    records[1] = intervals[i + 1][1];
            //}
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
    vector<vector<int> > result = solution->merge(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << "," << result[i][1] << "  "; 
    }
    cout << endl;
    return 0;
}
