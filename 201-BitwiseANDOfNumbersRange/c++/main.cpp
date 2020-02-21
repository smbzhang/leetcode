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
    int rangeBitwiseAnd_1(int m, int n) {
        int res = INT_MAX | 1 << 31;
        for (int i = m; i <= n; i++) {
            res &= i;
        }
        return res;
    }
    // 解法二：中间遇到 0  就退出
    int rangeBitwiseAnd_2(int m, int n) {
        int res = INT_MAX | 1 << 31;
        for (unsigned int i = m; i <= (unsigned int) n; i++) {
            res &= i;
            if (res == 0) return 0;
        }
        return res;
    }
    // 解法三：取巧解法 - 前面两个解法只需要注意溢出就好了 时间复杂度 O(1)
    // m - n 之间我们只需要找出最高位全部相同的就可以了，后面的与完之后都变成0
    int rangeBitwiseAnd_3(int m, int n) {
        int shift_num = 0;
        while (m < n) {
            shift_num++;
            m >>= 1;
            n >>= 1;
        }
        return m << shift_num;
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
