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
    // 解法二：每次填一个Q就判断一次，剪枝
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

    // 解法三： 继续优化上面的 isvaild 的判断，使用 bitmask, 直接 4ms
    vector<vector<string> > solveNQueens_3(int n) {
        vector<vector<string> > result;
        vector<string> records(n, string(n, '.'));
        vector<bool> tmp45(n + 2 * (n - 1), false);
        vector<bool> tmp135(n + 2 * (n - 1), false);
        vector<bool> tmpj(n, false);
        backtrace_3(n, 0, records, result, tmpj, tmp45, tmp135);
        return result;
    }

    void backtrace_3(int n, int row, vector<string>& records, vector<vector<string> >& result, vector<bool>& tmpj, vector<bool>& tmp45, vector<bool>& tmp135) {
        if (row == n) {
            result.push_back(records);
            return;
        }
        int i = row;
        for (int j = 0; j < n; j++) {
            if (!tmpj[j] && !tmp45[j + (n - 1 - i) + n - 1] && !tmp135[j - (n - 1 - i) + n - 1]){
                tmpj[j] = true; tmp45[j + (n - 1 - i) + n - 1] = true; tmp135[j - (n - 1 - i) + n - 1] = true;
                records[row][j] = 'Q';
                backtrace_3(n, row + 1, records, result, tmpj, tmp45, tmp135);
                records[row][j] = '.';
                tmpj[j] = false; tmp45[j + (n - 1 - i) + n - 1] = false; tmp135[j - (n - 1 - i) + n - 1] = false;
            }
        }
    }

};

int main(int argc, char *argv[]) {
    int n = 0;
    Solution *solution = new Solution();
    while (cin >> n) {
        vector<vector<string> > res = solution->solveNQueens_3(n);
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j] << endl;
            }
            cout << endl;
        }
    }
    
    return 0;
}
