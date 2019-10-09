#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int n = str.size(), i = 0;
        int res = 0;
        bool flag = true;
        while(i < n && str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+') {flag = (str[i] == '+') ? true : false; i++;}
        for(; i < n; i++) {
            if (str[i] > '9' || str[i] < '0') break;
            int num = str[i] - '0';
            if (flag && ((res > INT_MAX / 10) || (res == INT_MAX / 10 && num > INT_MAX % 10))) return INT_MAX;
            if (!flag && ((-res < INT_MIN / 10) || (-res == INT_MIN / 10 && -num <= INT_MIN % 10))) return INT_MIN;
            res = res * 10 + num;  // 如果 flag = false， 负值的最大值在这里会溢出，所以使用 long long int 来存储 res
        }
        return (flag) ? res : -res;
    }

    int myAtoi_2(string str) {
        int n = str.size(), i = 0;
        long long int res = 0;
        bool flag = true;
        while(i < n && str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+') {flag = (str[i] == '+') ? true : false; i++;}
        for(; i < n; i++) {
            if (str[i] > '9' || str[i] < '0') break;
            int num = str[i] - '0';
//            if (flag && ((res > INT_MAX / 10) || (res == INT_MAX / 10 && num > INT_MAX % 10))) return INT_MAX;
//            if (!flag && ((-res < INT_MIN / 10) || (-res == INT_MIN / 10 && -num < INT_MIN % 10))) return INT_MIN;
            res = res * 10 + num;  // 如果 flag = false， 负值的最大值在这里会溢出，所以使用 long long int 来存储 res
            if (flag && res > INT_MAX) return INT_MAX;
            if (!flag && res - 1 > INT_MAX) return INT_MIN;
        }
        return (flag) ? res : -res;
    }

};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << endl;
        cout << solution->myAtoi(strs[i]) << endl;
    }

    return 0;
}
