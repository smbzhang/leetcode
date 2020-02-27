#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;

// https://leetcode.com/problems/power-of-four/
class Solution {
public:
    // 遍历每个 1，3 ，5 ...的位
    bool isPowerOfFour_1(int num) {
        if (num < 0) return false;
        for (int i = 0; i < 31; i += 2) {
            if (abs(num) == 1 << i) {
                return true;
            }
        }
        return false;
    }
    // 使用内置函数 
    bool isPowerOfFour(int num) {
        return __builtin_popcount(num) == 1 && num & 0x55555555 && num > 0;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::cout << solution->isPowerOfFour(n) << std::endl;
    }

    return 0;
}
