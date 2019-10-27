#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                if (!isvaild(board, row, col, board[row][col]))
                    return false;
            }
        }
        return true;
    }

    bool isvaild(vector<vector<char> >& board, int row, int col, char m) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == m && i != col) 
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == m && i != row)
                return false;
        }
        
        int pre_row = row, pre_col = col;
        row = row / 3 * 3;
        col = col / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (row + i == pre_row && col + j == pre_col)
                    continue;
                if (board[row + i][col + j] == m)
                    return false;
            }
        }

        return true;
    }
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
    cout << (solution->isValidSudoku(board) ? "true" : "false") << endl;

    return 0;
}
