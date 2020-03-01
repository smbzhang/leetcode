#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            // 非进位结果
            int c = a ^ b;
            // 进位值 : leetcode 不支持负数 左移
            b = static_cast<unsigned int>(a & b) << 1;
            a = c;
        }
        return a; 
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    uint32_t a, b;
    while (cin >> a >> b) {
        std::cout << solution->getSum(a, b) << std::endl;
    }

    return 0;
}
