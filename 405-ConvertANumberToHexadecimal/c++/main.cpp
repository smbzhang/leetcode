#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;

//https://leetcode.com/problems/convert-a-number-to-hexadecimal/
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        std::string res;
        res.clear();
        for (int i = 0; i < 10; i++)
            records[i] = i + '0';
        for (int i = 10; i < 16; i++)
            records[i] = 'a' + (i - 10);
        unsigned int tmp = 0xf0000000;
        for (int i = 7; i >= 0; i--) {
            int m = (tmp & num) >> (i * 4);
            res += records[m];
            tmp >>= 4;
        }
        return std::string(res.begin() + res.find_first_not_of('0'), res.end());
    }
private:
    std::unordered_map<int, string> records;
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::cout << solution->toHex(n) << std::endl;
    }

    return 0;
}
