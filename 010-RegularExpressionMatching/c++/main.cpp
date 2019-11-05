#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;
// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
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
};

int main(int argc, char *argv[]) {

    Solution solution;
    cout << solution.isMatch("aaaaa", ".*aaaa") << endl;
    
    return 0;
}
