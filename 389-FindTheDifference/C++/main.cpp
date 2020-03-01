#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;

// https://leetcode.com/problems/find-the-difference/
class Solution {
public:
    // 解法一： 使用bitset
    char findTheDifference_1(string s, string t) {
        std::bitset<26> ss{0};
        std::bitset<26> tt{0};
        for (char c : s) {
            ss.flip(c - 'a');
        }
        for (char c : t) {
            tt.flip(c - 'a');
        }
        unsigned int tmp = ss.to_ulong() ^ tt.to_ulong();
        for (int i = 0; i < 26; i ++) {
            if ((1 << i) & tmp) {
                return 'a' + i;
            }
        }
        return 'a';
    }
    // 解法二：全部异或
    char findTheDifference(string s, string t) {
        char c = 0;
        for (const char& cc : s) {
            c ^= cc;
        }
        for (const char& cc : t) {
            c ^= cc;
        }
        return c;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    string s, t;
    while (cin >> s >> t) {
        std::cout << solution->findTheDifference(s, t) << std::endl;
    }

    return 0;
}
