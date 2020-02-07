#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 时间复杂度 O(m + n)， 空间复杂度 O(1)
        // 从左下角开始
        int m = matrix.size(), n = matrix[0].size(), l = m - 1, r = 0;
        bool result = false;
        while (l >= 0 && r < n) {
            if (matrix[l][r] == target)
                return true;
            if (matrix[l][r] < target) {
                r++;
            } else {
                l--;
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
    int target;
    cout << "Please input target: " << endl;
    cin >> target;
    bool result = solution->searchMatrix(matrix, target);
    cout << result << endl;
    return 0;
}
