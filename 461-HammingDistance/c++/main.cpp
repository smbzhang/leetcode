#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <bitset>

using namespace std;
// https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
        std::bitset<sizeof(int) * 8> a(x ^ y);
        return a.count();
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    int x, y;
    while (cin >> x >> y) {
        std::cout << solution->hammingDistance(x, y) << std::endl;
    }

    return 0;
}
