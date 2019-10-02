#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;
        vector<string> records(numRows, "");
        int n = s.length();
        bool down = true; // 方向
        int row = 0;
        for (int i = 0; i < n; i++) {
            if (down) {
                records[row] += s[i];
                row++;
                if (row == numRows - 1) {
                    down = false;
                }
            }else {
                records[row] += s[i];
                row--;
                if (row == 0) {
                    down = true;
                }
            }
        }
        string ret;
        for (int i = 0; i < numRows; i++) {
            ret += records[i];
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    cout << "Please enter the numRows." << endl;
    int numRows;
    cin >> numRows;
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << endl;
        cout << solution->convert(strs[i], numRows) << endl;
    }

    return 0;
}
