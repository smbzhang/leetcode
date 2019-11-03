#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, n = height.size();
        for (int i = 1; i < n; i++) {
            int lmax = 0, rmax = 0;
            for (int m = 0; m < i; m++) {
                lmax = height[m] > lmax ? height[m] : lmax;
            }
            for (int m = i + 1; m < n; m++) {
                rmax = height[m] > rmax ? height[m] : rmax;
            }
            if (lmax > height[i] && rmax > height[i]) result += ((rmax < lmax) ? rmax : lmax) - height[i];
        }
        return result;
    } 

    // 解法二，优化求解左边最大值和右边最大值
    int trap_2(vector<int>& a){
        int n = a.size(), result = 0;
        vector<int> lmax(n, 0), rmax(n, 0);
        for (int i = 1; i < n; i++) {
            lmax[i] = a[i - 1] > lmax[i - 1] ? a[i - 1] : lmax[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = a[i + 1] > rmax[i + 1] ? a[i + 1] : rmax[i + 1];
        }
        for (int i = 1; i < n; i++) {
            int l = lmax[i], r = rmax[i];
            if (a[i] < l && a[i] < r) {
                result += std::min(l, r) - a[i];
            }
        }
        return result;
    }

    // 神级别解法
    int trap_3(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
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
        int result = solution->trap_2(nums);
        cout << "result: " << result << endl;
    }
   
    return 0;
}
