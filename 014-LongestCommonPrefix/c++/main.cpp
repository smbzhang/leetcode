#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlen = 10000;
        if (strs.size() == 0) return "";
        string result = "";
        for (auto tmp : strs) {
            minlen = (tmp.size() < minlen) ? tmp.size() : minlen;
        }
        for (int i = 0; i < minlen; i++) {
            char s = strs[0][i];
            for (auto str : strs) {
                if (str[i] != s)
                goto ret;
            }
            result += s;
        }
ret:
        return result;
    }
};

int main() {
    vector<int> nums1; 
    vector<int> nums2;
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array  = leetcode::common::split(str,',');
        string result = solution->longestCommonPrefix(array);
        cout << result << endl;
    }
   
    return 0;
}
