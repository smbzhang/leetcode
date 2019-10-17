#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;

// https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        int ret = -1;
        for (int i = 0; i <= n - m; i++) {
            int l = i, k = 0;
            while(l < n && k < m && haystack[l++] == needle[k]) k++;
            if (k == m) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    for (int i = 0; i < strs.size(); i++) {
        cout << "Please enter the substr: " << endl;
        string needle;
        cin >> needle;
        cout << strs[i] << endl;
        cout << solution->strStr(strs[i], needle) << endl;
    }

    return 0;
}
