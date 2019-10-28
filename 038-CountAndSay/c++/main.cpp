#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        string result = "";
        int i = 0;
        while (i < str.size()) {
            char word = str[i];
            int num = 0;
            while(i < str.size() && str[i] == word) {
                num++;
                i++;
            }
            result += '0' + num;
            result += word;
        }
        return result;
    }
};

int main() {
    int n = 0;
    Solution *solution = new Solution();
    while(cin >> n) {
        cout << solution->countAndSay(n) << endl;
    }
       
    return 0;
}
