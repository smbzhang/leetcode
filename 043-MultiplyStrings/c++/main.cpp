#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string result = "";
        if (n1 == 0 || n2 == 0) return result;
        if (num1 == "0" || num2 == "0") return "0";
        std::vector<int> array1(n1 + n2, 0);
        int pos1 = n1 + n2, pos2 = n1 + n2 - 1;
        for (int i = n1 - 1; i >= 0; i--) {
            pos1--; pos2--;
            int m = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                int a = num1[i] - '0', b = num2[j] - '0';
                array1[pos1 - m] += (a * b) % 10;
                array1[pos2 - m] += (a * b) / 10;
                m++;
            }
        }
        int high = 0;
        for (int i = n1 + n2 - 1; i >= 0; i--) {
            int sum = array1[i] + high;
            array1[i] = sum % 10;
            high = sum / 10;
        }
        int i = 0;
        while (array1[i] == 0) {
            i++;
        }
        for (; i < n1 + n2; i++) {
            result += array1[i] + '0';
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    Solution *solution = new Solution();
    for (int i = 0; i < strs.size(); i += 2) {
        cout << strs[i] << " x " << strs[i + 1] << ": ";
        cout << solution->multiply(strs[i], strs[i + 1]);
        cout << endl;
    }

    return 0;
}
