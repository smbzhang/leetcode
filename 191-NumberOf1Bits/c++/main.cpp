#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;
// https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    // 解法一： 按位与
    int hammingWeight_1(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            ret += (n & (1 << i)) == 0 ? 0 : 1;
        }
        return ret;
    }
    // 解法二：按照 n 和 n - 1 的二进制, n & n - 1 会使得 n 的最后一个是1的位变成0
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n != 0) {
            ret++;
            n &= n - 1;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::cout << solution->hammingWeight(n) << std::endl;
    }

    return 0;
}
