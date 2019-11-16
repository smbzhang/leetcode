#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;

// https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), i = n - 1;
        while (i >= 0 && s[i] == ' ') i--;
        n = i + 1;
        for (; i >= 0; i--) {
            if (s[i] == ' ') break;
        }
        return n - 1 - i - 1 + 1;
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
        cout << solution->lengthOfLastWord(strs[i]) << endl;
    }

    return 0;
}
