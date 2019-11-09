#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/rotate-image/
class Solution {
public:
    // 先转置，然后再反转每一行
    void rotate(vector<vector<int> >& a) {
        int n = a.size();
        // 转置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                std::swap(a[i][j], a[j][i]);
            }
        }
        // 反转每一行
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                std::swap(a[i][j], a[i][n - 1 - j]);
            }
        }
    }

    // https://leetcode.com/problems/rotate-image/discuss/18895/Clear-Java-solution 一圈一圈的操作
    void rotate_2(vector<vector<int> >& a) {
        int n = a.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int tmp = a[i][j];
                a[i][j] = a[n - j - 1][i];
                a[n - j - 1][i] = a[n - i - 1][n - j - 1];
                a[n - i - 1][n - j - 1] = a[j][n - i - 1];
                a[j][n - i - 1] = tmp;
            }
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
    vector<vector<int> > matrix;
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        matrix.push_back(nums);
    }
    solution->rotate_2(matrix);
    for (auto tmps : matrix) {
        for (auto tmp : tmps) {
            cout << tmp << " ";
        }
        cout << endl;
    }
   
    return 0;
}
