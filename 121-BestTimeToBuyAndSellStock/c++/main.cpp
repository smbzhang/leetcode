#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    // 暴力法
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > ret) {
                    ret = prices[j] - prices[i];
                }
            }
        }
        return ret;
    }
    // 一次遍历
    
    // DP
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
