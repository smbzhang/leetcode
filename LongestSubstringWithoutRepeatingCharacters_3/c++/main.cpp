#include <iostream>
#include "common/cpp_common.h"
#include <string>
using namespace std;
/*
//动态规划递归求解, Memory Limit Exceeded
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for (int i = 0 ; i < s.length(); i++) {
            int len = lengthOfTheFirstSub(s, i);
            max = (len > max) ? len : max;
        }
        return max;
    }

    int lengthOfTheFirstSub(string str, int index) {
        string s = str.substr(index);
        if (s.length() <= 1) return s.length();
        if (s[0] == s[1]) {
            return 1;
        } else {
            int len = lengthOfTheFirstSub(str, index + 1);
            int n = s.substr(1, len).find(s[0]);
            if (n != string::npos) {
                return n + 1;
            } else {
                return len + 1;
            }
        }
    }
};
*/
/* 
//加入记录数组，提升查找速度, Memory Limit Exceeded 这解决不了内存的问题，递归层数太深了
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        std::vector<int> records(s.length(), -1);
        for (int i = 0 ; i < s.length(); i++) {
            int len = lengthOfTheFirstSub(s, i, records);
            max = (len > max) ? len : max;
        }
        return max;
    }

    int lengthOfTheFirstSub(string str, int index, std::vector<int> &records) {
        if (records[index] != -1) {return records[index];}
        string s = str.substr(index);
        if (s.length() <= 1) {
            records[index] = s.length();
            return s.length();
        }
        if (s[0] == s[1]) {
            records[index] = 1;
            return 1;
        } else {
            int len = lengthOfTheFirstSub(str, index + 1, records);
            int n = s.substr(1, len).find(s[0]);
            if (n != string::npos) {
                records[index] = n + 1;
                return n + 1;
            } else {
                records[index] = len + 1;
                return len + 1;
            }
        }
    }
};
*/

// 改成递推求解，减少栈内存消耗
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        std::vector<int> records(n, 0);
        if (n <= 1) {return n;}
        records[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == s[i + 1]) {
                records[i] = 1;
            }else{
                int index = s.substr(i + 1, records[i + 1]).find(s[i]);
                if (index == string::npos) {
                    records[i] = records[i + 1] + 1;
                }else {
                    records[i] = index + 1;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < records.size(); i++) {
            if (records[i] > max) {
                max = records[i];
            }
        }
        return max;
    }
};




int main(int argc, char *argv[]) {

    std::string content;
    leetcode::common::get_string_from_file("string.txt", content);
    std::vector<string> strs = leetcode::common::split(content, '\n');

    Solution *solution = new (Solution);
    for (auto str : strs) {
        cout << str << endl;
        int len = solution->lengthOfLongestSubstring(str);
        cout << len << endl;
    }

   
    return 0;
}
