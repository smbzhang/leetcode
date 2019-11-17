#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;
// https://leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n, 0));
        int up = 0, down = n - 1, left = 0, right = n - 1, num = 1, i;
        while (up <= down) {
            i = left; while(i < right) {result[up][i++] = num++;}
            i = up; while(i < down) {result[i++][right] = num++;}
            i = right; while(i > left) {result[down][i--] = num++;}
            i = down; while(i > up) {result[i--][left] = num++;}
            up++; down--; left++; right--;
        }
        if (n % 2) result[n / 2][n / 2] = n * n;
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    cout << "Please enter the numRows." << endl;
    int numRows;
    cin >> numRows;
    vector<vector<int> > result = solution->generateMatrix(numRows);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
