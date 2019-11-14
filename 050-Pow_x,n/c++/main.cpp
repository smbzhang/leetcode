#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_map>
#include <memory>
using namespace std;

// https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (n == 1 || n == -1) return n > 0 ? x : (1 / x);
        double result = 0;
        result = myPow(x, n / 2);
        result *= result;
        result *= myPow(x, n % 2);
        return result;
    }
};


int main() {
    cout << -9 / 2 << endl;
    double x;
    int n;
    std::shared_ptr<Solution> solution = std::make_shared<Solution>();
    while (cin >> x >> n) {
        cout << x << " " << n << endl;
        cout << solution->myPow(x, n) << endl;
    }

    return 0;
}
