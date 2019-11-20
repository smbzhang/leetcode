#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int result = 0;
        backtrace(obstacleGrid, 0, 0, result);
        return result;
    }

    void backtrace(const vector<vector<int> >& obstacleGrid, int i, int j, int &result) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (i >= m || j >= n) return;
        if (i == m - 1 && j == n - 1) {
            if (obstacleGrid[i][j] != 1) result++;
            return;
        }
        if (obstacleGrid[i][j] == 1) return;
        if (i < m - 1 && obstacleGrid[i + 1][j] == 1);
        else backtrace(obstacleGrid, i + 1, j, result);
        if (j < n - 1 && obstacleGrid[i][j + 1] == 1);
        else backtrace(obstacleGrid, i, j + 1, result);
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
    int result = solution->uniquePathsWithObstacles(matrix);
    cout << result << endl;
    return 0;
}
