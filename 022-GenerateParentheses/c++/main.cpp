#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/ 
class Solution {
public:
    // 暴力搜索，时间复杂度太高了，需要列举每个位置上的所有的两种情况
    
    vector<string> generateParenthesis(int n) {
        int pos = 0;
        vector<string> result;
        string cur(2*n, ' ');
        generateAll(n, pos, cur, result);
        return result;
    }

    void generateAll(int n, int pos, string cur, vector<string> &result) {
        // 判断当前结果是不是符合规则
        if (pos == n * 2) {
            int record = 0;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] == '(') record++;
                else{
                    record--;
                    if (record < 0) break;
                }
            }
            if (record == 0) result.push_back(cur);
            return;
        }
        cur[pos] = '(';
        generateAll(n, pos+1, cur, result);
        cur[pos] = ')';
        generateAll(n, pos+1, cur, result);
    }

    // 优化判断条件不要在最后进行合法性的判断，进行剪枝
    vector<string> generateParenthesis_2(int n) {
        int pos = 0;
        vector<string> result;
        string cur(2*n, ' ');
        int right = 0, left = 0;
        generateAll(n, pos, cur, result, left, right);
        return result;
    }

    void generateAll(int n, int pos, string cur, vector<string> &result, int left, int right) {
        if (pos == 2 * n) {
            result.push_back(cur);
            return;
        }
        if (left < n) {
            cur[pos] = '(';
            generateAll(n, pos+1, cur, result, left + 1, right);  
        }
        if (right < left) {
            cur[pos] = ')';
            generateAll(n, pos+1, cur, result, left, right + 1);  
        }
    }
};

int main() {
    Solution *solution = new Solution();
    std::vector<std::string> strs;
    cout << "Please entern the number of (), entern '-1' to quit." << endl;
    int n;
    while (cin >> n) {
        if (n < 0) break;
        strs = solution->generateParenthesis_2(n);
        for (int i = 0; i < strs.size(); i++) {
            cout << strs[i] << endl;
        }
    }

    return 0;
}
