#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/permutation-sequence/
class Solution {
public:
    // 解法一： 这样是不能够保证结构式拍序好的,所以这个方法失败
    string getPermutation(int n, int k) {
        string str = "", result = "";
        for (int i = 1; i <= n; i++) {
            str += '0' + i;
        }
        int records = 0, pos = 0;
        backtrace(str, pos, k, records, result);
        return result;
    }

    void backtrace(string &str, int pos, int k, int& records, string& result) {
        if (pos == str.size()) {
            records++;
            if (records == k) result = str;
            return;
        }
        for (int i = pos; i < str.size(); i++) {
            std::swap(str[pos], str[i]);
            backtrace(str, pos + 1, k, records, result);
            if (result != "") return;
            std::swap(str[pos], str[i]);
        }
    }
    // 解法二：先排列再拍序, 果然超时了，dfs复杂度加拍序复杂度
    string getPermutation_2(int n, int k) {
        string str = "";
        for (int i = 1; i <= n; i++) {
            str += '0' + i;
        }
        int pos = 0;
        vector<string> results;
        backtrace(str, pos, results);
        std::sort(results.begin(), results.end());
        return results[k - 1];
    }

    void backtrace(string &str, int pos, vector<string>& results) {
        if (pos == str.size()) {
            results.push_back(str);
            return;
        }
        for (int i = pos; i < str.size(); i++) {
            std::swap(str[pos], str[i]);
            backtrace(str, pos + 1, results);
            std::swap(str[pos], str[i]);
        }
    }
    // 解法三： 找规律
    string getPermutation_3(int n, int k) {
        vector<int> records(n, 1);
        int tmp = 1;
        string result = "";
        for (int i = 1; i < n; i++) {
            tmp *= i;
            records[i] = tmp;
        }
        string str = "";
        for (int i = 1; i <= n; i++) {
            str += '0' + i;
        }
        while (n != 0) {
            int tmp = (k - 1) / records[n - 1];
            result += str[tmp];
            str.erase(tmp, 1);
            tmp = k % records[n - 1];
            k = tmp == 0 ? records[n - 1] : tmp;
            n--;
        }

        return result;
    }



};

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    cout << "Please enter the numRows." << endl;
    int n, k;
    cin >> n >> k;
    cout << solution->getPermutation_3(n, k) << endl;;
  
    return 0;
}
