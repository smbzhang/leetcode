#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result = false;
        int m = matrix.size(); if (m == 0) return false;
        int n = matrix[0].size(); if (n == 0) return false;
        // 1. 先确定所在行 
        int row = -1;
        for (int i = 0; i < m; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                row = i;
                break;
            }
        }
        if (row == -1) return false;
        // 2. 确定所在列
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (target == matrix[row][mid]) return true;
            else if (target > matrix[row][mid]) l = mid + 1;
            else r = mid - 1;
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
    int target;
    cout << "Please input target: " << endl;
    cin >> target;
    bool result = solution->searchMatrix(matrix, target);
    cout << result << endl;
    return 0;
}
