#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void insert_sort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) continue;
            auto tmp = nums[i];
            for (int j = i; j >= 0; j--) {
                if (j > 0 && nums[j - 1] > tmp) {
                    nums[j] = nums[j - 1];
                } else {
                    nums[j] = tmp;
                    break;
                }
            }
        }
    }

    void select_sort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX, pos = i;
            for (int j = i; j < n; j++) {
                if (nums[j] < mini) {
                    mini = nums[j];
                    pos = j;
                }
            }
            std::swap(nums[pos], nums[i]);
        }
    }
    // 普通冒泡排序
    void bubbo_sort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
    // 冒泡排序优化一：如果有一趟没有交换那么就是有序了
    // 适合部分有序的情况
    void bubbo_sort_1(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            bool flag = false;
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                    flag = true;
                }
            }
            if (!flag) break;
        }
    }
    // 冒泡排序优化二：优化一仅仅适用于连片有序而整体无序的数据(例如：1， 2，3 ，4 ，7，6，5)。
    // 但是对于前面大部分是无序而后边小半部分有序的数据(1，2，5，7，4，3，6，8，9，10)排序效率也不可观
    // 每次排序找到相应的最后一次交换的位置，那么后面的就是有序了，只需要遍历 前面到最后一次遍历的地方就可
    void bubbo_sort_3(std::vector<int>& nums) {
        int n = nums.size();
        int pos = n - 1;
        for (int i = pos; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                    pos = j;
                }
            }
        }
    }
    // 冒泡排序优化三：https://blog.csdn.net/hansionz/article/details/80822494
    
    // 归并排序
    void merge_sort(std::vector<int>& nums) {
        loop(nums, 0, nums.size() - 1);
    }
    void loop(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        loop(nums, start, mid);
        loop(nums, mid + 1, end);
        merge(nums, start, mid, mid + 1, end);
    }
    void merge(vector<int>& nums, int i, int j, int m, int n) {
        vector<int> a(nums.begin() + i, nums.begin() + j + 1), b(nums.begin() + m, nums.begin() + n + 1);
        a.push_back(INT_MAX); b.push_back(INT_MAX);
        int pa = 0, pb = 0;
        for (int s = i; s <= n; s++) {
            if (a[pa] <= b[pb]) {
                nums[s] = a[pa];
                pa++;
            } else {
                nums[s] = b[pb];
                pb++;
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
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        //solution->insert_sort(nums);
        //solution->select_sort(nums);
        //solution->bubbo_sort_3(nums);
        solution->merge_sort(nums);
        cout << endl;
        for (auto tmp : nums) {
            cout << tmp << " ";
        }
        cout << endl;
    }

    return 0;
}
