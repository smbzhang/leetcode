#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// https://leetcode.com/problems/gray-code/
// 格雷码
class Solution {
public:
    // 解法一：动态规划法
    // dp[n][i] = 0,dp[n - 1][i]      ; 0 <= i < N / 2  (N： 当前格雷码的总个数)
    //          = 1,dp[n][N - i - 1]  ; N / 2 <= i < N
    vector<int> grayCode_1(int n) {
        records.push_back(0);
        for (int i = 1; i <= n; i++) {
            int N = 1 << i;
            for (int j = N / 2; j < N; j++) {
                int num = records[N - j - 1] + (1 << (i - 1));
                records.push_back(num);
            }
        }
        return records;
    }

    // 解法二: 镜像法求解
    
private:
    std::vector<int> records;
};

int main() {
    int n = 0;
    while (std::cin >> n) {
        Solution solution;
        std::vector<int> res = solution.grayCode(n);
        for (auto tmp : res) {
            std::cout << tmp << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
