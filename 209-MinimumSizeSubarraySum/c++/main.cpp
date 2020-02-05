#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    // 解法一： 暴力法 O(n^2)
    int minSubArrayLen_1(int s, vector<int>& nums) {
        int n = nums.size(), result = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0, j = i;
            while (sum < s && j < n) {
                sum += nums[j++];
            }
            if (j >= n && sum < s) break;
            int tmp = j - i;
            result = result < tmp ? result : tmp;
        }
        return result == INT_MAX ? 0 : result;
    }
   // 解法二: 双指针法 时间复杂度 O(n)
    int minSubArrayLen_2(int s, vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int n = nums.size(), start = 0, end = 0, result = INT_MAX, sum = nums[0];
        while (start < n && end < n) {
            if (sum < s) {
                end++;
                if (end >= n) break;
                sum += nums[end];
            } else {
                int tmp = end - start + 1;
                result = tmp < result ? tmp : result;
                sum -= nums[start++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }

    // 解法三：二分法时间复杂度 O(nlogn) 题目要求
    // 既然看到时间复杂度的要求有 logn 选项，那么就直到要使用 二分法，但是二分的话需要是有序数组
    // 怎么构造有序数组呢，重新建一个数组，array[i]代表0 - i的和
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int n = nums.size(), result = INT_MAX;
        vector<int> array(nums.begin(), nums.end());
        // 构造有序数组
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int target = nums[i] + (s - array[i]), start = i, end = n -1;
            while (start < n && start <= end) {
                int mid = (start + end) / 2;
                if (nums[mid] == target || start == end) {
                    if (start == end && nums[mid] < target) break;
                    int tmp = mid - i + 1;
                    result = result < tmp ? result : tmp;
                    break;
                } else if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return result == INT_MAX ? 0 : result;
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
        int s;
        cout << "Please enter s: " << endl;
        cin >> s;
        int result = solution->minSubArrayLen(s, nums);
        cout << result << endl;  
    }
   
    return 0;
}
