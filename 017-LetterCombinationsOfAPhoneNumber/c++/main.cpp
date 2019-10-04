#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// 很明显这是一个排列组合题， 列出所有的组合可能，使用深度优先遍历算法 DFS
class Solution {
public:
    Solution() {
        records['2'] = "abc";
        records['3'] = "def";
        records['4'] = "ghi";
        records['5'] = "jkl";
        records['6'] = "mno";
        records['7'] = "pqrs";
        records['8'] = "tuv";
        records['9'] = "wxyz";   
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) {
            // 边界处理这个地方，必须返回一个 “” string， 不能直接返回一个空的 result, 否则结果为空
            // result.push_back("");
            return result;
        }
        if (digits.length() == 1) {
            for (int i = 0; i < records[digits[0]].length(); i++) {
                result.push_back(records[digits[0]].substr(i,1));
            }
            return result;
        }
        auto tmp = letterCombinations(digits.substr(1));
        for (int i = 0; i < records[digits[0]].length(); i++) {
            for (int j = 0; j < tmp.size(); j++) {
                result.push_back(records[digits[0]][i] + tmp[j]);
            }
        }
        return result;
    }

    // 补充一个 BFS 的解法
private:
    unordered_map<char, string> records;
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
        auto result = solution->letterCombinations(str);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
   
    return 0;
}
