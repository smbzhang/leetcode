#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    // 121 题的解法的升级， O(n*n)
    int maxProfit(vector<int> &n) {
        int ret1 = 0, ret2 = 0, ret3 = 0, ret = 0;
        int low = INT_MAX, lowp = INT_MAX;
        int p1 = 0, p2 = 0, tp1 = 0;
        // 第一趟
        for (int i = 0; i < n.size(); i++) {
            if (n[i] < low) {
                low = n[i];
                tp1 = i;
            } 
            if (n[i] - low > ret1) {
                ret1 = n[i] - low;
                p2 = i;
                p1 = tp1;        
                // 第二趟 前半段  0 - p1
                lowp = INT_MAX; ret2 = 0;
                for (int i = 0; i < p1; i++) {
                    lowp = n[i] < lowp ? n[i] : lowp;
                    ret2 = n[i] - lowp > ret2 ? n[i] - lowp : ret2;
                }
                lowp = INT_MAX; ret3 = 0;
                // 第二趟后半段  p2 - end
                for (int i = p2 + 1; i < n.size(); i++) {
                    lowp = n[i] < lowp ? n[i] : lowp;
                    ret3 = n[i] - lowp > ret3 ? n[i] - lowp : ret3;
                }
                ret = ret1 + std::max(ret2, ret3) > ret ? ret1 + std::max(ret2, ret3) : ret;
            }
        }

        return ret;
    }
};

int main() {
    vector<int> nums1; 
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
        cout <<  solution->maxProfit(nums) << endl;
    }
   
    return 0;
}
