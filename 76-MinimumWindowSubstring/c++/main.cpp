#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <climits>

using namespace std;

// https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    // 滑动窗口解法 - 使用hashmap计数
    string minWindow(string s, string t) {
        std::unordered_map<char, int> mp;
        for (auto c : t) mp[c]++;
        string result = "";
        int l = 0, r = 0, n = s.size(), m = t.size(), minlen = INT_MAX;
        while(r < n) {
            if (mp.find(s[r]) != mp.end()) {
                mp[s[r]]--;
                // 判断是不是包含了所有 t 的字符
                while(match(mp)) {
                    // 记录最小值
                    if (minlen > r - l + 1) {
                        minlen = r - l + 1;
                        result = s.substr(l, r - l + 1);
                    }
                    // 缩小滑动窗口
                    if (mp.find(s[l]) != mp.end()) {
                        mp[s[l]]++;
                    }
                    l++;
                }
            }
            // 扩大滑动窗口
            r++;
        }
        return result;
    }
    bool match(unordered_map<char, int> &mp) {
        // 判断是不是包含了所有 t 的字符
        bool flag = true;
        for (auto item : mp) {
            if(item.second > 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    for (int i = 0; i < strs.size(); i+=2) {
        cout << strs[i] << " " << strs[i+1]<< endl;
        cout << solution->minWindow(strs[i], strs[i+1]) << endl;
    }

    return 0;
}

