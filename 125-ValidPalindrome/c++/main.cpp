#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;
// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    // 双指针法求解是否回文子串
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
        while (start <= end) {
            if (!valid(s[start])) start++;
            else if (!valid(s[end])) end--;
            else if (s[start] == s[end]) {
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }
    inline bool valid(char c) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
            return true;
        }
        return false;
    }
};
int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << endl;
        cout << solution->isPalindrome(strs[i]) << endl;
    }

    return 0;
}
