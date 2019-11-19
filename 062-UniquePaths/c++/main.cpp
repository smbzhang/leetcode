#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
// https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 0;
        backtrace(m , n, 0, 0, result);
        return result;
    }

    void backtrace(int m, int n, int i, int j, int &result) {
        if (i >= m || j >= n) return;
        if (i == m - 1 && j == n - 1) {
            result++;
            return;
        }
        backtrace(m, n, i + 1, j, result);
        backtrace(m, n, i, j + 1, result);
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    int m, n;
    cin >> m >> n;
    cout << solution->uniquePaths(m, n) << endl;

    return 0;
}
