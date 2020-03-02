#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>
#include <climits>

using namespace std;
// https://leetcode.com/problems/integer-replacement/
class Solution {
public:
    // 解法一： dp 解法
    int integerReplacement(int n) {
        if (n <= 2) return abs(n - 1);
        int res = INT_MAX;
        // odd
        if (n & 1) {
            if (n == INT_MAX) return integerReplacement(n - 1);
            return 1 + std::min(integerReplacement(n - 1), integerReplacement(n + 1));
        }
        // even
        else {
            return 1 + integerReplacement(n >> 1);
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::cout << solution->integerReplacement(n) << std::endl;
    }

    return 0;
}
