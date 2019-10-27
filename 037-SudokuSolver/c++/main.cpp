#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        back_trace(board);
    }
    bool back_trace(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int m = 1; m < 10; m++) {
                        if (isvaild(board, i, j, m + '0')) {
                            board[i][j] = '0' + m;
                            if (back_trace(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvaild(vector<vector<char> >& board, int row, int col, char m) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == m) 
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == m)
                return false;
        }

        row = row / 3 * 3;
        col = col / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[row + i][col + j] == m)
                    return false;
            }
        }

        return true;
    }
    // https://leetcode.com/problems/sudoku-solver/discuss/15748/Sharing-my-2ms-C%2B%2B-solution-with-comments-and-explanations.
    // 上面这个解法只需要2ms可以看一下
};
int main(int argc, char *argv[]) {
    std::vector<std::string> lines;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    lines = leetcode::common::split(str,'\n');
    vector<vector<char> > board;
    for (int i = 0; i < lines.size(); i++) {
        vector<string> words = leetcode::common::split(lines[i], ',');
        vector<char> tmp;
        for (int i = 0; i < words.size(); i++) {
            char c = words[i][0];
            tmp.push_back(c);
        }
        board.push_back(tmp);
    }
    
    Solution *solution = new Solution();
    solution->solveSudoku(board);

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
