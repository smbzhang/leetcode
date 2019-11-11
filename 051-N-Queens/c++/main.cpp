#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;

// https://leetcode.com/problems/n-queens/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string line(n, '.');
        vector<vector<string> > result;
        vector<string> records(n, line);
        backtrace(n, 0, result, records);

        return result;
    }
    // 解法一：先DFS遍历完然后在最后进行合法性检查，这样的话会超时。
    void backtrace(int n, int row, vector<vector<string> >& result, vector<string>& records) {
        if (row == n) {
            // 判断每一列有没有两个及其以上的 Q 出现
            for (int i = 0; i < n; i++) {
                int num = 0;
                for (int j = 0; j < n; j++) {
                    if (records[j][i] == 'Q') {
                        num++;
                        if (num > 1) return;
                    }
                }
            }
            // 判断对角线, 45和135度
            // 45° i + 1, j + 1 && i - 1, j - 1
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (records[i][j] == 'Q') {
                        int p = i, q = j;
                        while(p + 1 < n && q + 1 < n) {
                            if (records[p + 1][q + 1] == 'Q') return;
                            p++; q++;
                        }
                    }
                }
            }
            // 135° i-1, j+1  && i+1, j-1
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (records[i][j] == 'Q') {
                        int p = i, q = j;
                        while(p + 1 < n && q - 1 >= 0) {
                            if (records[p + 1][q - 1] == 'Q') return;
                            p++; q--;
                        }
                    }
                }
            }

            result.push_back(records);
            return;
        }
        for (int j = 0; j < n; j++) {
            records[row][j] = 'Q';
            backtrace(n, row + 1, result, records);
            records[row][j] = '.';
        }
    }

    bool isvalid(vector<string> &records, int n) {
       // 判断每一列有没有两个及其以上的 Q 出现
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (records[j][i] == 'Q') {
                    num++;
                    if (num > 1) return false;
                }
            }
        }
        // 判断对角线, 45和135度
        // 45° i + 1, j + 1 && i - 1, j - 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (records[i][j] == 'Q') {
                    int p = i, q = j;
                    while(p + 1 < n && q + 1 < n) {
                        if (records[p + 1][q + 1] == 'Q') return false;
                        p++; q++;
                    }
                }
            }
        }
        // 135° i-1, j+1  && i+1, j-1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (records[i][j] == 'Q') {
                    int p = i, q = j;
                    while(p + 1 < n && q - 1 >= 0) {
                        if (records[p + 1][q - 1] == 'Q') return false;
                        p++; q--;
                    }
                }
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens_2(int n) {
        string line(n, '.');
        vector<vector<string> > result;
        vector<string> records(n, line);
        backtrace_2(n, 0, result, records);

        return result;
    }

    void backtrace_2(int n, int row, vector<vector<string> >& result, vector<string>& records) {
        if (row == n) {
            result.push_back(records);
            return;
        }
        for (int i = 0; i < n; i++) {
            records[row][i] = 'Q';
            if (isvalid(records, n)) backtrace_2(n, row + 1, result, records);
            records[row][i] = '.';
        }
    }
};

int main(int argc, char *argv[]) {
    int n = 0;
    Solution *solution = new Solution();
    while (cin >> n) {
        vector<vector<string> > res = solution->solveNQueens_2(n);
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j] << endl;
            }
            cout << endl;
        }
    }
    
    return 0;
}
