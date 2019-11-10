#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<vector<string> > result;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            if (this->m.find(tmp) == this->m.end()) {
                this->m.insert(std::make_pair(tmp, vector<int>(1, i)));
            }else{
                this->m[tmp].push_back(i);
            }
        }
        for (auto it = this->m.begin(); it != this->m.end(); it++) {
            vector<string> tmp;
            for (auto i : it->second) {
                tmp.push_back(strs[i]);
            }
            result.push_back(tmp);
        }
        return result;
    }
    // 优化排序算法，上面的排序时间复杂度是 O(nlogn), 鉴于是小写字符排序，可以进行时间优化
    vector<vector<string> > groupAnagrams_2(vector<string>& strs) {
        std::vector<vector<string> > result;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strsort(strs[i]);
            this->m[tmp].push_back(i);
        }
        for (auto it = this->m.begin(); it != this->m.end(); it++) {
            vector<string> tmp;
            for (auto i : it->second) {
                tmp.push_back(strs[i]);
            }
            result.push_back(tmp);
        }
        return result;
    }

    string strsort(const string &str) {
        int records[26] = {0};
        for (auto s : str) {
            records[s - 'a']++;
        }
        string result = "";
        for (int i = 0; i < 26; i++) {
            result += string(records[i], 'a' + i);
        }
        return result;
    }
    
private:
    unordered_map<string, vector<int> > m;
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    auto result = solution->groupAnagrams_2(strs);

    return 0;
}
