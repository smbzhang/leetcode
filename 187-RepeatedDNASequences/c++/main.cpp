#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/repeated-dna-sequences/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::unordered_map<string, int> mymap;
        int n = s.length();
        vector<string> result;
        for (int i = 0; i <= n - 10; i++) {
            string tmp(s.substr(i, 10));
            mymap[tmp]++;
        }
        for (const auto& pair : mymap) {
            if (pair.second > 1) result.push_back(pair.first);
        }
        return result;
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
        std::vector<string> result = solution->findRepeatedDnaSequences(strs[i]);
        for (auto tmp : result) {
            std::cout << tmp << std::endl;
        }
    }

    return 0;
}
