#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    // 双重指针法 - O(logn)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), start = 0, end = n - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                return std::vector<int>{start + 1, end + 1};
            } else if (numbers[start] + numbers[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return std::vector<int>{};
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array, nums);
        cout << "Please enter the target: " << endl;
        int target = 0;
        cin >> target;
        auto result = solution->twoSum(nums, target);
        cout << result[0] << " " << result[1] << endl;  
    }
   
    return 0;
}
