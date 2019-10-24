#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    // 解法一： 时间复杂度 O(n!), 虽然 leetcode 没有提示超时，但是只击败了 5.x% 的用户，时间复杂度上面
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        int result = 0;
        // 这个地方注意，当s.length() = 0 的时候， 0 - 1 会溢出，所以要在一开始就把边界条件判断一下。
        for (int i = 0; i < s.length() - 1; i++) {
            int record = 0, len = 0;
            for (int j = i; j < s.length(); j++) {
                if (s[j] == '(') {
                    record++;        
                }else{
                    record--;
                    if (record == 0) {
                        len = (j - i + 1) > len ? (j - i + 1) : len;
                    }
                    if (record < 0) {
                        break;
                    }
                }
            }
            result = len > result ? len : result;
        }
        return result;
    }
    // 解法二：在计算 record 的过程中，我们一直在加，其实这个地方可以做一个快速失败，如果'('的个数大于当前判断的子串的一半，就直接失败就好了
    // 时间节省了一半，但是还是只超过了 5.x% ........
    int longestValidParentheses_2(string s) {
        if (s.length() <= 1) return 0;
        int result = 0;
        // 这个地方注意，当s.length() = 0 的时候， 0 - 1 会溢出，所以要在一开始就把边界条件判断一下。
        for (int i = 0; i < s.length() - 1; i++) {
            int record = 0, len = 0, leftlen = s.length() - i;
            for (int j = i; j < s.length(); j++) {
                if (s[j] == '(') {
                    record++;
                    // 做一个快速失败
                    if (record > leftlen / 2) break;
                }else{
                    record--;
                    if (record == 0) {
                        len = (j - i + 1) > len ? (j - i + 1) : len;
                        leftlen = s.length() - i - len;
                    }
                    if (record < 0) {
                        break;
                    }
                }
            }
            result = len > result ? len : result;
        }
        return result;
    }

};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (auto str : strs) {
        cout << str << endl;
        auto result = solution->longestValidParentheses_2(str);
        cout << result << endl;
    }
   
    return 0;
}
