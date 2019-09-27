#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) {return "";}
        if (n == 1) {return s;}
        vector<vector<bool> > records(n, vector<bool>(n, false));
        int start = 0, max = 1;
        // 子串长度为1的回文长度是1，子串长度是2的，且两个字符相同的，回文长度是2
        for (int i = 0; i < n; i++) {
            records[i][i] = true;
            if (i < n  - 1 && s[i] == s[i + 1]) {
                records[i][i+1] = true;
                start = i;
                max = 2;
            }
        }
        // 子串长度从 3 - n
        // longestPalindrome(i, j) 以及 longestPalindrome(i + 1, j -1) 的关系
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                if (s[i] == s[i + len - 1] && records[i + 1][i + len - 1 - 1]) {
                    records[i][i + len - 1] = true;
                    start = i;
                    max = len;
                }
            }
        }
        return s.substr(start, max);
    }

    // 中心扩展法
    string longestPalindrome_2(string s) {
        int n = s.length();
        if (n < 2) {return s;}
        bool is_even = false;
        int center = 0;
        int max = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) { // 中心是偶数的情况
                int start = i;
                int end = i + 1;
                while(start >= 0 && end < n && s[start] == s[end]) {
                    int len = end - start + 1;
                    if (len > max) {
                        max = len;
                        is_even = true;
                        center = i;
                    }
                    start--;
                    end++;
                }
            }
            { // 中心是基数的情况, 基数和偶数并不是互斥的情况，基数是一定要考虑的
               int start = i, end = i; 
                while(start >= 0 && end < n && s[start] == s[end]) {
                    int len = end - start + 1;
                    if (len > max) {
                        max = len;
                        is_even = false;
                        center = i;
                    }
                    start--;
                    end++;
                }
            }
        }
        if (!is_even) {
            return s.substr(center - max/2, max);
        }else{
            return s.substr(center - max/2 + 1, max);
        }
    }


};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    // 解法一 (动态规划求解)
    Solution *solution = new Solution();
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << endl;
        cout << solution->longestPalindrome_2(strs[i]) << endl;
    }

    return 0;
}
