#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int result = INT_MAX, m = grid.size(), n = 0;
        if (m != 0) n = grid[0].size();
        if (m == 0 || n == 0) return 0;
        backtrace(grid, m, n, 0, 0, result, 0);
        return result;
    }
    void backtrace(vector<vector<int> >& grid, int m, int n, int i, int j, int &result, int records) {
        if (i >= m || j >= n) return;
        if (i == m - 1 && j == n - 1) {
            result = std::min(result, records + grid[i][j]);
            return;
        }
        records += grid[i][j];
        backtrace(grid, m , n, i + 1, j, result, records);
        backtrace(grid, m, n, i, j + 1, result, records);
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
    int result = solution->minPathSum(matrix);
    cout << result << endl;
    return 0;
}
