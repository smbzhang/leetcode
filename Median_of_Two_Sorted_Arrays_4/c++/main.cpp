#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
using namespace std;

class Solution {
public:
    // 不创建数组存放所有的排序结果,这样处理偶数的时候会非常麻烦
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n1 = nums1.size(), n2=nums2.size(), target = (n1 + n2 - 1) / 2, cur = 0;
        bool is_odd = (n1 + n2) % 2 ? true : false;
        while (i < n1 || j < n2) {
            if (i == n1) {
                if (cur == target && is_odd) return nums2[j];
                if (cur == target && !is_odd) return ((nums2[j] + nums2[j + 1]) * 1.0)/ 2;     
                j++;
                cur++;
                continue;
            }        
            if (j == n2) {
                if (cur == target && is_odd) return nums1[i];
                if (cur == target && !is_odd) return ((nums1[i] + nums1[i + 1]) * 1.0)/ 2;              
                i++;
                cur++;
                continue; 
            }
            if (cur == target) {
                if (is_odd) {return nums1[i] <= nums2[j] ? nums1[i] : nums2[j];}
                else{
                    double res = 0.0;
                    if (nums1[i] <= nums2[j]) {res += nums1[i++];}
                    else {res += nums2[j++];}

                    if (i == n1) {res += nums2[j];}
                    else if (j == n2) {res += nums1[i];}
                    else {
                        if (nums1[i] <= nums2[j]) {res += nums1[i];}
                        else {res += nums2[j];}
                    }
                    return res / 2;
                }
            }else {
                if (nums1[i] <= nums2[j]) {
                    i++;
                    cur++;
                }else{
                    j++;
                    cur++;
                }
            }
        }
        return 0;
    }

    // 创建一个数组存放排好序的结果，类似于归并排序的处理
    double findMedianSortedArrays_2(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), i = 0, j = 0, cur = 0;
        bool is_odd = (n1 + n2) % 2 ? true : false;
        vector<int> array(n1 + n2, 0);
        while(i < n1 || j < n2) {
            if (i == n1) {
                while(j < n2) {
                    array[cur++] = nums2[j++];
                }
            }
            else if (j == n2) {
                while(i < n1) {
                    array[cur++] = nums1[i++];
                }
            }
            else {
                if (nums1[i] <= nums2[j]) {
                    array[cur++] = nums1[i++];
                }else {
                    array[cur++] = nums2[j++];
                }
            }
        }
        int target = (n1 + n2 - 1) / 2;
        if (is_odd) return array[target];
        return ((array[target] + array[target + 1]) * 1.0) / 2;
    }

    // 使用二分法来进行查找
    double findMedianSortedArrays_3(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), imax = nums1.size(), imin = 0;
        if (m > n) {
            return findMedianSortedArrays_3(nums2, nums1);
        }
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = (m + n + 1) / 2 - i;
            if (j != 0 && i != m && nums2[j - 1] > nums1[i]) {
                imin = i + 1;
            }
            else if (j != n && i != 0 && nums1[i -1] > nums2[j]) {
                imax = i - 1;
            }
            else {
                // 奇数的情况
                int maxLeft = 0;
                if (i == 0) {maxLeft = nums2[j - 1];}
                else if (j == 0) {maxLeft = nums1[i - 1];}
                else {maxLeft = std::max<int>(nums1[i - 1], nums2[j - 1]);}
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }
                // 偶数的情况
                int minRight = 0;
                if (i == m) {minRight = nums2[j];}
                else if (j == n) {minRight = nums1[i];}
                else {minRight = std::min(nums1[i], nums2[j]);}
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
 
};

int main() {
    vector<int> nums1; 
    vector<int> nums2;
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    cout << strs[0] << endl;
    cout << strs[1] << endl;
    std::vector<string> strs1 = leetcode::common::split(strs[0], ',');
    std::vector<string> strs2 = leetcode::common::split(strs[1], ',');
    leetcode::common::strings_to_numbers(strs1, nums1);
    leetcode::common::strings_to_numbers(strs2, nums2);
    
    double ret = Solution().findMedianSortedArrays_3(nums1, nums2);
    cout << ret << endl;

    return 0;
}
