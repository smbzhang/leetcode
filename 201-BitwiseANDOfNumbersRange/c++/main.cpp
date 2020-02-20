#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>
#include <climits>

using namespace std;
// https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/
class Solution {
public:
    // 解法一：遍历全部 m 到 n 并进行按位与, 时间复杂度 O(n)
    int rangeBitwiseAnd(int m, int n) {
        int res = INT_MAX | 1 << 31;
        for (int i = m; i <= n; i++) {
            res &= i;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    int m, n;
    while (cin >> m >> n) {
        std::cout << solution->rangeBitwiseAnd(m, n) << std::endl;
    }

    return 0;
}
