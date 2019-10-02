#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

//https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        std::map<string, int> records({
            {"M", 1000}, {"D", 500}, {"C", 100}, {"L", 50}, {"X", 10}, {"V", 5}, {"I", 1},
            {"CM", 900}, {"CD", 400}, {"XC", 90}, {"XL", 40}, {"IX", 9}, {"IV", 4}
        });
        int i = 0, n = s.length(), result = 0;
        while (i < n) {
            int j = i + 1;
            std::string str;
            if (j < n) {
                str += s[i];
                str += s[j];
                if (records.find(str) != records.end()) {
                    result += records[str];
                    i += 2;
                    continue;
                }
            }
            str.clear();
            str += s[i++];
            result += records[str];
        }
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
        int result = solution->romanToInt(str);
        cout << result << endl;
    }
   
    return 0;
}
