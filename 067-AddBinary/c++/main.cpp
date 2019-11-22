#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <string>
using namespace std;

// https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length() - 1, n = b.length() - 1;
        int jinwei = 0;
        string result = "";
        while (m >= 0 || n >= 0) {
            if (m >= 0 && n >= 0) {
                result = static_cast<char>('0' + (a[m] - '0' + b[n] - '0' + jinwei) % 2) + result;
                jinwei = (a[m] - '0' + b[n] - '0' + jinwei) / 2;
                m--; n--;
            }
            else if (m < 0) {
                result = static_cast<char>('0' + (b[n] - '0' + jinwei) % 2) + result;
                jinwei = (b[n] - '0' + jinwei) / 2;
                n--;
            }else {
                result = static_cast<char>('0' + (a[m] - '0' + jinwei) % 2) + result;
                jinwei = (a[m] - '0' + jinwei) / 2;
                m--;
            }
        }
        if (jinwei) result = static_cast<char>('1') + result;
        return result;
    }
};

int main() {
    vector<int> nums1; 
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (int i = 0; i < strs.size(); i += 2) {
        cout << strs[i] << " + " << strs[i + 1] << endl;
        cout << solution->addBinary(strs[i], strs[i + 1]) << endl;
    }
    return 0;
}
