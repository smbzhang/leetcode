#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>
#include <bitset>
#include <climits>

using namespace std;
// https://leetcode.com/problems/maximum-product-of-word-lengths/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        size_t n = words.size();
        std::vector<std::bitset<26>> bitset_vec(n, bitset<26>(0));
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = 0; j < words[i].size(); j++) {
                size_t shift = words[i][j] - 'a';
                bitset_vec[i] |= (1 << shift);
            }
        }
        int res = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                bitset<26> bb = bitset_vec[i] & bitset_vec[j];
                if (bb.to_ulong() == 0) {
                    int tmp = words[i].size() * words[j].size();
                    res = tmp > res ? tmp : res;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    cout << solution->maxProduct(strs) << endl;
     
    return 0;
}
