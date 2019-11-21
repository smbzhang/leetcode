#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), jinwei = 0;
        vector<int> result(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                int sum = digits[i] + jinwei + 1;
                result[i] += sum % 10;
                jinwei = sum / 10;
            }
            else {
                int sum = digits[i] + jinwei;
                result[i] += sum % 10;
                jinwei = sum / 10;
            }
        }
        if (jinwei != 0) result.insert(result.begin(), 1);
        return result;
    }
};
int main() {
    vector<int> nums1; 
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
        vector<int> result = solution->plusOne(nums);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
