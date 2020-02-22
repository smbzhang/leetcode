#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;

// https://leetcode.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        int num = 0;
        for (int i = 0; i < 31; i++) {
            if ((1 << i) & n) {
                num++;
            }            
        }
        if (num != 1) return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::cout << solution->isPowerOfTwo(n) << std::endl;
    }

    return 0;
}
