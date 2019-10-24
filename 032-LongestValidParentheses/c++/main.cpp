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
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (auto str : strs) {
        cout << str << endl;
        auto result = solution->longestValidParentheses(str);
        cout << result << endl;
    }
   
    return 0;
}
