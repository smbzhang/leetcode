#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        // 从十位开始向更高位遍历，直到出现高位右边有大于高位数字的
        int n = nums.size(), i = n - 1;
        for (; i > 0; i--) {
            if (nums[i - 1] < nums[i]) break;
        }
        // 如果这个数是最大的那么 返回最小的值
        if (i <= 0) {
            std::sort(nums.begin(), nums.end());
        }else{
            int high = i - 1, low;
            // 找出高位后面恰好大于 高位的那个数
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[high]){
                    low = i;
                    break;
                }
            }

            int temp = nums[high];
            nums[high] = nums[low];
            nums[low] = temp;
            // 交换完之后，high 后面的需要在进行一次排序，从低到高，保证增加完高位之后，之后的位组成的数字是最小的，才能保证恰好大于
            // std::sort(nums.begin() + i, nums.end());
            // 其实不用专门排序，high 后面是降序的，只需要倒序一次就好了
            int start = i, end = n - 1;
            while (start < end) {
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    for (int i = 0; i < strs.size(); i++) {
        Solution *solution = new Solution();
        vector<string> words = leetcode::common::split(strs[i], ',');
        vector<int> nums;
        leetcode::common::strings_to_numbers(words, nums);
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        solution->nextPermutation(nums);
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
