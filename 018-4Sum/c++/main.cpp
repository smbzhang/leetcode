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

// https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int> > result;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                // 这里必须保证 j - 1 > i 比如 0,0,0,0 这个例子
                if (j - 1 > i && nums[j] == nums[j - 1]) continue;
                // 构造两个指针前后夹击求解，这样就能将内层的 O(n2) 降到 O(n)
                int pstart = j + 1, pend = n - 1;
                while (pstart < pend) {
                    int diff = target - nums[i] - nums[j] - nums[pstart] - nums[pend];
                    if (diff == 0) {
                        result.push_back(std::vector<int>{nums[i], nums[j], nums[pstart], nums[pend]});
                        while (pstart < pend && nums[pstart] == nums[pstart + 1]) pstart++;
                        while (pstart < pend && nums[pend] == nums[pend - 1]) pend--;
                        pstart++;
                        pend--;
                    }else if (diff > 0) {
                        pstart++;
                    }else {
                        pend--;
                    }
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
        int target;
        cout << "Please input the target :";
        cin >> target;
        vector<vector<int> > result = solution->fourSum(nums, target);
        for (auto tmps : result) {
            for (auto tmp : tmps) {
                cout << tmp << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
