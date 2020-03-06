#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;
// https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits_2(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 31; i >= 0; i--) {
            // 计算 n 的第 i 位
            uint32_t tmp = (1 << i) & n;
            // 确定 ret 的第 31 - i 位
            ret |= tmp > 0 ? 1 << (31 - i) : 0;
        }
        return ret;
    }

    uint32_t reverseBits(uint32_t n) {
        std::bitset<32> bit_set{n};
        // 交换 bit_set 的前后两个部分
        int l = 0, r = 31;
        while(l < r) {
            bool tmp = bit_set[l];
            bit_set[l++] = bit_set[r];
            bit_set[r--] = tmp;
        }
        return bit_set.to_ulong();
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::cout << solution->reverseBits(n) << std::endl;
    }

    return 0;
}
