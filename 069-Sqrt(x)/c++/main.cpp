#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <string>
#include <climits>
using namespace std;

// https://leetcode.com/problems/sqrtx/
class Solution {
public:
    // 时间复杂度 O(n)
    int mySqrt(int x) {
        int res = 0;
        for (int i = 1; i < INT_MAX; i++) {
            res = x / i;
            if (res == i) return res;
            if (res < i) return i - 1;
        }
        return res;
    }

    // binary serach algorithm
    int mySqrt_2(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid > x / mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x/(mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
    }
};

int main() {
    int x;
    Solution *solution = new Solution(); 
    while (cin >> x) {
        cout << "x is : " << x << endl;
        cout << solution->mySqrt_2(x) << endl;
    }
    return 0;
}
