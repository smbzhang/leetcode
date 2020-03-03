#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;
// https://leetcode.com/problems/binary-watch/
//       8 4 2 1
// 32 16 8 4 2 1
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> rs;
        for (int h = 0; h < 12; h++)
        for (int m = 0; m < 60; m++)
            if (bitset<10>(h << 6 | m).count() == num)
                rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        return rs;
    }   
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::vector<string> res = solution->readBinaryWatch(n);
        for (auto tmp : res) {
            cout << tmp << " ";
        }
        cout << endl;
    }

    return 0;
}
