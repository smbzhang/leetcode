#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <unordered_set>
#include <math.h>

using namespace std;
// https://leetcode.com/problems/happy-number/
class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> set;
        bool ret = false;
        while (true) {
            int m = 0;
            while (n > 0) {
                m += pow(n % 10, 2);
                n = n / 10;
            }
            if (m == 1) {
                ret = true;
            }
            if (set.find(m) != set.end()) {
                break;
            } else {
                set.insert(m);
            }
            n = m;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n;
    while (cin >> n) {
        cout << solution.isHappy(n) << endl;
    }

    return 0;
}
