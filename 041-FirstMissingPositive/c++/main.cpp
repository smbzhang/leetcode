#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/first-missing-positive/
/**
 * 这种题其实一开始想的是 bitmap 来做，但是并不能使用 bitmap 来做
 * 其实本质就是使用一个 map 来做映射，然后进行查找
 */
class Solution {
public:
    // 解法一：利用数组的下标作为值,数组的值作为键
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while(i < n && nums[i] != i + 1 && nums[i] < n && nums[i] > 0 && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
    // 解法二：使用数组的下标作为key，数组值的符号作为value
    int firstMissingPositive_2(vector<int> &nums) {
        int n = nums.size();
        bool hasone = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                hasone = true;
                break;
            } 
        }
        if (!hasone) return 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 1 || nums[i] > n)
                nums[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            int pos = std::abs(nums[i]);
            nums[pos - 1] = nums[pos - 1] < 0 ? nums[pos - 1] : -nums[pos - 1];
        }
        for (int i= 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
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
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        int result = solution->firstMissingPositive_2(nums);
        cout << "result: " << result << endl;
    }
   
    return 0;
}
