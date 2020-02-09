#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    // 解法一： 空间 O(n + m) 时间 O(m + n)
    void merge_2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> array;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i >= m) {
                array.push_back(nums2[j++]);
            } else if (j >= n) {
                array.push_back(nums1[i++]);
            } else {
                if (nums1[i] <= nums2[j]) array.push_back(nums1[i++]);
                else array.push_back(nums2[j++]);
            }
        }
        nums1 = array;
    }

    // 解法二: 空间 O(1), 时间 O(m + n)
    // 两个指针从 m,n开始遍历，填入数据从 nums1 的尾部开始插入
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, pos = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                nums1[pos--] = nums2[j--];
            } else if (j < 0) {
                nums1[pos--] = nums1[i--];
            } else {
                nums1[pos--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
            }
        }
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (int i = 0; i < strs.size(); i += 2) {
        cout << strs[i] << endl;
        cout << strs[i + 1] << endl;
        std::vector<string> array  = leetcode::common::split(strs[i],',');
        std::vector<int> nums1, nums2;
        leetcode::common::strings_to_numbers<int>(array, nums1);
        array = leetcode::common::split(strs[i + 1],',');
        leetcode::common::strings_to_numbers<int>(array, nums2);
        solution->merge(nums1, nums1.size(), nums2, nums2.size());
        for (auto tmp : nums1) {
            cout << tmp << " ";
        } 
        cout << endl;
    }
   
    return 0;
}
