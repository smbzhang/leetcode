#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;
// https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            // 奇数: 比上一个偶数多一个1
            if (i & 1) {
                res[i] = res[i - 1] + 1;
            }
            // 偶数：偶数和除以二之后的偶数的尾数是相同的
            else {
                res[i] = res[i >> 1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        solution->countBits(n);
    }

    return 0;
}
