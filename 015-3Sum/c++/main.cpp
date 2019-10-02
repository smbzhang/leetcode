#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/3sum/
class Solution {
public:
    // 暴力搜索，超时！
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        // 1. 先确定第一个数
        for (int i = 0; i < n - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 2. 确定第二个数
            for (int j = n - 1; j > i; j--) {
                if (j < (n - 1) && nums[j] == nums[j + 1]) continue;
                int num = 0 - (nums[i] + nums[j]);
                // 3. 确定第三个数
                for (int k = i + 1; k < j; k++) {
                    if (nums[k] == num) {
                        result.push_back(std::vector<int>{nums[i], nums[k], nums[j]});
                        break;
                    }
                }
            }
        }
        return result;
    }
    // 优化一下上面找第二个和第三个数的算法，上面是循环遍历找，这里使用两个指针进行查找
    vector<vector<int>> threeSum_2(vector<int>& nums) {
        vector<vector<int> > result;
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        // 1. 先确定第一个数
        for (int i = 0; i < N - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int num = 0 - nums[i];
            // 2. 定义前后两个指针，往中间移动
            int m = i + 1, n = N -1;
            while (m < n) {
                if (nums[m] + nums[n] == num) {
                    result.push_back(std::vector<int>{nums[i], nums[m], nums[n]});
                    while(m < n && nums[m] == nums[m + 1]) m++;
                    while(m < n && nums[n] == nums[n - 1]) n--;
                    m++;
                    n--;
                }else if (nums[m] + nums[n] < num) {
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
        vector<vector<int> > result = solution->threeSum_2(nums);
        for (auto tmps : result) {
            for (auto tmp : tmps) {
                cout << tmp << " ";
            }
            cout << endl;
        }
    }
   
    return 0;
}
