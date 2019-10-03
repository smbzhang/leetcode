#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    // 暴力搜索，嘿，没有超时！
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int result = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        // 1. 先确定第一个数
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 2. 确定第二个数
            for (int j = n - 1; j > i; j--) {
                if (j < (n - 1) && nums[j] == nums[j + 1]) continue;
                // 3. 确定第三个数
                for (int k = i + 1; k < j; k++) {
                    int diff = std::abs((nums[k] + nums[i] + nums[j]) - target);
                    result = diff < min_diff ? (nums[k] + nums[i] + nums[j]) : result;
                    min_diff = diff < min_diff ? diff : min_diff;
                }
            }
        }
        return result;
    }
    // 优化一下上面找第二个和第三个数的算法，上面是循环遍历找，这里使用两个指针进行查找
    int threeSumClosest_2(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        int min_diff = INT_MAX;
        // 1. 先确定第一个数
        for (int i = 0; i < N - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 2. 定义前后两个指针，往中间移动
            int m = i + 1, n = N -1;
            while (m < n) {
                int sum = nums[i] + nums[m] + nums[n];
                int diff = std::abs(sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    result = sum;
                }
                if (sum < target) {
                    m++;
                }else {
                    n--;
                }
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
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        int result = solution->threeSumClosest_2(nums, 100);
        cout << result << endl;
    }
   
    return 0;
}
