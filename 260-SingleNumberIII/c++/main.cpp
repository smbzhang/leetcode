#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;
//https://leetcode.com/problems/single-number-iii/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        // 找出最终结果中的最左边的1，分成两组，分别找出
        int pos = 0;
        for (pos = 0; pos < 32; pos++) {
            if (res & (1 << pos)) {
                break;
            }
        }
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & (1 << pos)) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return vector<int>{a, b};
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    int a = -2;
    cout << -a << endl;
    return 0;
}
