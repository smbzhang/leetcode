#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;
// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    //解法一: 递归求解， 严重超时，跑主函数的case跑了一份多种，在我的虚拟机上面
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[0] != '*')  return !s.empty() && (s[0] == p[0] || p[0] == '?') && isMatch(s.substr(1), p.substr(1));
        // 如果p[0] == '*', 需要考虑匹配 0 次和多次的情况
        return isMatch(s, p.substr(1)) || (!s.empty() && isMatch(s.substr(1), p));
    }

    // 解法三：迭代法，上面的递归，回溯的分支太多，这里通过迭代进行优化
    bool isMatch_3(string s, string p) {
        int i = 0, j = 0, record = -1, ss = 0;
        while (i < s.length()) {
            if (j < p.length() && (s[i] == p[j] || p[j] == '?')) {
                i++; j++;
            }
            else if (j < p.length() && p[j] == '*') {
                ss = i;
                record = j;
                j++;
            }
            else if (record != -1) {
                i = ss++;
                j = record + 1;
            }
            else
                return false;
        }
        while (j < p.length() && p[j] == '*') {
            j++;
        }
        return j == p.length();
    }
    
    // 解法二：动态规划求解
    bool isMatch_2(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        vector<vector<bool> >dp(n1 + 1, vector<bool>(n2 + 1, true));
        for (int i = n1; i >= 0; i--) {
            for (int j = n2; j >= 0; j--) {
                if (i == n1 && j == n2) continue;
                if (j < n2 && p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] || (i < n1 && dp[i + 1][j]);
                }
                else {
                    dp[i][j] = (i < n1 && j < n2) && (s[i] == p[j] || p[j] == '?') && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char *argv[]) {

    Solution solution;
    cout << solution.isMatch_3("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;
    cout << solution.isMatch_3("aaa", "*a") << endl;

    return 0;
}
