#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        int n = matrix.size(), m = matrix[0].size();
        if (m == 0) return result;
        int up = 0, down = n - 1, left = 0, right = m - 1;
        while (up < down && left < right) {
            for (int i = left; i < right; i++) result.push_back(matrix[up][i]);
            for (int i = up; i < down; i++) result.push_back(matrix[i][right]);
            for (int i = right; i > left; i--) result.push_back(matrix[down][i]);
            for (int i = down; i > up; i--) result.push_back(matrix[i][left]);
            up++;right--;down--;left++;
        }
        if (up == down) for (int i = left; i <= right; i++) result.push_back(matrix[up][i]);
        else if (left == right) for (int i = up; i <= down; i++) result.push_back(matrix[i][left]);
        else;
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
    vector<int> result = solution->spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
