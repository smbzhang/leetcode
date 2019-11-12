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
   
    int totalNQueens_2(int n) {
        int result = 0;
        vector<vector<char> > records(n, vector<char>(n, '.'));
        backtrace_2(n, 0, records, result);
        return result;
    }

    void backtrace_2(int n, int row, vector<vector<char> >& records, int &result) {
        if (row == n) {
            result++;
            return;
        }
        for (int i = 0; i < n; i++) {
            records[row][i] = 'Q';
            if (isvalid_2(records, row, n)) backtrace_2(n, row + 1, records, result);
            records[row][i] = '.';
        }
    }

    bool isvalid_2(const vector<vector<char> >& records, int row, int n) {
        vector<bool> tmp45(n + 2 * (n - 1), false);
        vector<bool> tmp135(n + 2 * (n - 1), false);
        vector<bool> tmpj(n, false);
        for (int i = 0; i <= row; i++) {
            for (int j = 0; j < n; j++) {
                if (records[i][j] == 'Q') {
                    if (tmpj[j] || tmp45[j + (n - 1 - i) + n - 1] || tmp135[j - (n - 1 - i) + n - 1]) return false;
                    else {
                        tmpj[j] = true; tmp45[j + (n - 1 - i) + n - 1] = true; tmp135[j - (n - 1 - i) + n - 1] = true;
                    }
                }
            }
        }
        return true;
    }

    int totalNQueens_3(int n) {
        int result = 0;
        vector<vector<char> > records(n, vector<char>(n, '.'));
        vector<bool> tmp45(n + 2 * (n - 1), false);
        vector<bool> tmp135(n + 2 * (n - 1), false);
        vector<bool> tmpj(n, false);
        backtrace_3(n, 0, records, result, tmpj, tmp45, tmp135);
        return result;
    }

    void backtrace_3(int n, int row, vector<vector<char> >& records, int &result, vector<bool>& tmpj, vector<bool>& tmp45, vector<bool>& tmp135) {
        if (row == n) {
            result++;
            return;
        }
        int i = row;
        for (int j = 0; j < n; j++) {
            if (!tmpj[j] && !tmp45[j + (n - 1 - i) + n - 1] && !tmp135[j - (n - 1 - i) + n - 1]){
                tmpj[j] = true; tmp45[j + (n - 1 - i) + n - 1] = true; tmp135[j - (n - 1 - i) + n - 1] = true;
                records[row][i] = 'Q';
                backtrace_3(n, row + 1, records, result, tmpj, tmp45, tmp135);
                records[row][i] = '.';
                tmpj[j] = false; tmp45[j + (n - 1 - i) + n - 1] = false; tmp135[j - (n - 1 - i) + n - 1] = false;
            }
        }
    }
    
};

int main(int argc, char *argv[]) {
    int n = 0;
    vector<vector<char> > records(4, vector<char>(4, '.'));
    records[0][1] = 'Q';
    records[1][3] = 'Q';
    records[2][0] = 'Q';
    records[3][2] = 'Q';
    Solution *solution = new Solution();
    cout << solution->isvalid_2(records, 3, 4);
    while (cin >> n) {
        int res = solution->totalNQueens_3(n);
        cout << res << endl;
    }
    
    return 0;
}
