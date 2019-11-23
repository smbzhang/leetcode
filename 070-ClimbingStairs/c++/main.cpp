#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <string>
using namespace std;

// https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main() {
    int x;
    Solution *solution = new Solution(); 
    while (cin >> x) {
        cout << solution->climbStairs(x) << endl;
    }
    return 0;
}
