#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;
// https://leetcode.com/problems/number-complement/
class Solution {
public:
    int findComplement(int num) {
        // 因为 num > 0 所以去掉符号位
        std::bitset<31> a(num);
        int i = 30;
        while (i >=0 && a[i] == 0) {
            i--;
        }
        for (; i >= 0; i--) {
            a[i] = a[i] ? 0 : 1;
        }
        return static_cast<int>(a.to_ulong());
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t n;
    while (cin >> n) {
        std::cout << solution->findComplement(n) << std::endl;
    }

    return 0;
}
