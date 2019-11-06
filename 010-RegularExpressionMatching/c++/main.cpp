#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;
// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    //解法一: 递归求解
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool first_match = !s.empty() && (p[0] == s[0] || p[0] == '.');
        if (p.length() > 1 && p[1] == '*') {
            return (isMatch(s, p.substr(2)) || \
                    (first_match && isMatch(s.substr(1), p)));
        }else{
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }

    // 解法二：动态规划求解
    

    bool isMatch_2(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, true));
        for (int i = n1; i >= 0; i--) {
            for (int j = n2; j >= 0; j--) {
                if(i == n1 && j == n2) continue;
                bool first_match = (i < n1 && j < n2) && (s[i] == p[j] || p[j] == '.');
                if (j + 2 <= n2 && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                }else{
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }

};

int main(int argc, char *argv[]) {

    Solution solution;
    cout << solution.isMatch_2("aaaaa", ".*aaaa") << endl;
    
    return 0;
}
