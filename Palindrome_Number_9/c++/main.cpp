#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    // 解法一, 通过求余存储每个值，从右到左，然后对vector进行对称检验
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> array;
        while(x) {
            int mod = x % 10;
            array.push_back(mod);
            x /= 10;
        }
        int i = 0, j = array.size() - 1;
        while(i < j) {
            if (array[i++] != array[j--]) return false;
        }
        return true;
    }

    // 解法二, 计算出反向的值直接进行比较, 这里不判断溢出
    bool isPalindrome_2(int x) {
        if (x < 0) return false;
        long long int num = 0, init = x;
        while(x){
            int mod = x % 10;
            num = num * 10 + mod;
            x /= 10;
        }
        return (num == init);
    }

};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    vector<int> array;
    leetcode::common::strings_to_numbers<int>(strs, array);

    Solution *solution = new Solution();
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
        cout << solution->isPalindrome_2(array[i]) << endl;
    }

    
    return 0;
}
