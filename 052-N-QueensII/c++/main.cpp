#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;

// https://leetcode.com/problems/n-queens-ii/
class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<vector<char> > records(n, vector<char>(n, '.'));
        backtrace(n, 0, records, result);
        return result;
    }

    void backtrace(int n, int row, vector<vector<char> >& records, int &result) {
        if (row == n) {
            result++;
            return;
        }
        for (int i = 0; i < n; i++) {
            records[row][i] = 'Q';
            if (isvalid(records, row, n)) backtrace(n, row + 1, records, result);
            records[row][i] = '.';
        }
    }

    bool isvalid(const vector<vector<char> >& records, int row, int n) {
        // 检查列
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j <= row; j++) {
                if (records[j][i] == 'Q') num++;
                if (num > 1) return false;
            }
        }
        // 45°  i + 1, j + 1 && i - 1, j - 1
        for (int i = 0; i <= row; i++) {
            for (int j = 0; j < n; j++) {
                if (records[i][j] == 'Q') {
                    int p = i, q = j;
                    while(p + 1 <= row && q + 1 < n) {
                        if (records[p + 1][q + 1] == 'Q') return false;
                        p++; q++;
                    }
                }
            }
        }
        // 135° i + 1, j - 1
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < n; j++) {
                if (records[i][j] == 'Q') {
                    int p = i, q = j;
                    while(p + 1 <= row && q - 1 >= 0) {
                        if (records[p + 1][q - 1] == 'Q') return false;
                        p++; q--;
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    int n = 0;
    Solution *solution = new Solution();
    while (cin >> n) {
        int res = solution->totalNQueens(n);
        cout << res << endl;
    }
    
    return 0;
}
