#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

    // 解法一超时
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        words = permutation(words);
        for (int i = 0; i < words.size(); i++) {
            int pos = 0;
            pos = s.find(words[i], pos);
            while (pos != string::npos) {
                result.push_back(pos); 
                pos = s.find(words[i], pos + 1);
            }
        }
        return result;
    }


    vector<string> permutation(vector<string> &strs) {
        vector<string> result;
        if (strs.size() == 0) {
            return result;
        }
        range(strs, 0, result);
        return result;
    }

    void range(vector<string> &strs, int start, vector<string> &result) {
        if (start == strs.size()) {
            string str;
            str.clear();
            for (int i = 0; i < strs.size(); i++) {
                str += strs[i];
            }
            // 使用 hashmap 去重
            if (this->records.find(str) == this->records.end()) {
                this->records.insert(str);
                result.push_back(str);
            }
            return;
        }
        for (int i = start; i < strs.size(); i++) {
            // 去重
            //bool flag = true;
            //for (int j = start; j < i; j++) {
            //    if (strs[j] == strs[start]) flag == false;
            //} 
            //if (!flag) continue;
            swap(strs, start, i);
            range(strs, start + 1, result);
            swap(strs, start, i);
        }
    }

    void swap(vector<string> &strs, int i, int j) {
        string str = strs[i];
        strs[i] = strs[j];
        strs[j] = str;
    }

    std::unordered_set<string> records;
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    for (int i = 0; i < strs.size(); i += 2) {
        cout << strs[i] << endl;
        vector<string> words = leetcode::common::split(strs[i + 1], ',');
        for (int i = 0; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << endl;
        vector<int> ret = solution->findSubstring(strs[i], words);
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
