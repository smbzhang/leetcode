#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <climits>

// https://leetcode.com/problems/divide-two-integers/
using namespace std;
class Solution {
public:
    // O(dividend) 使用了 long long int， 来判断边界，不符合题目要求
    int divide(int dividend_, int divisor_) {
        long long int dividend = dividend_, divisor = divisor_;
        if (divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        long long int ret = 0;
        bool flag = true;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) flag = false;
        dividend = (dividend < 0) ? -dividend : dividend;
        divisor = (divisor < 0) ? -divisor : divisor;
        long long int sum = 0;
        for (; sum < dividend; sum += divisor) {
            ret++;
        }
        if (sum == dividend) ret = flag ? ret : -ret;
        else {
            ret = flag ? ret - 1 : -(ret - 1);
        }
        if (ret > INT_MAX) return INT_MAX;
        return ret;
    }
    // 使用负数进行计算的好处是不用判断 a = INT_MIN 的情况，这种情况下，正数很难处理
    int divide_3(int dividend, int divisor) {
        int ret = 0;
        bool sign = (dividend > 0) ^ (divisor < 0);
        /*
         * 如果转换成正数来做的话，这个边界处理起来很困难，-214748364-21474836488, 一转换就要超 32 bit
        if (dividend < 0) {
            if (dividend == INT_MIN) 特殊处理
        } 
        */
        if (dividend > 0) dividend = 0 - dividend;
        if (divisor > 0) divisor = 0 - divisor;
        while(dividend <= divisor) {
            int i = 0;
            // 如果直接判断 dividend <= divisor << i, divisor << i 会溢出，-2147483648， 1 这个例子就会一直死循环
            // for (; dividend <= divisor << i; i++);
            for (; dividend <= static_cast<unsigned int>(divisor) << i; i++) {
                if ((static_cast<unsigned int>(divisor) << i) < (1 << 31 | 1 << 30)) {
                    i++;
                    break;
                }
            }
            
            // ret = ret - 1 << (i - 1)   其中 ret 可能会溢出， 当 i == 32 的时候, 也就是 dividend == INT_MIN && divisor == 1 或者 -1 的时候
            if (i == 32) return sign ? INT_MAX : INT_MIN;
            ret -= 1 << (i - 1);
            dividend -= static_cast<unsigned int>(divisor) << (i - 1);
        }
        if (ret <= INT_MIN) return INT_MAX;
        if (!sign) {
            return ret;
        }
        return 0 - ret;
    }
         
    int divide_2(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        bool sign = (dividend < 0) ^ (divisor < 0);
        int ret = 0, sum = 0;
        if (divisor > 0) divisor = 0 - divisor;
        if (dividend > 0) dividend = 0 - dividend;
        for (; sum > dividend - divisor; sum += divisor) {
            ret++;
        }
        if (sum == dividend - divisor) 
        {
            if (ret == INT_MAX) return INT_MAX;
            else ret += 1;
        }
        if (sign) {
            if (ret <= INT_MIN) return INT_MAX;
            ret = 0 - (ret);
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    cout << abs(INT_MIN) << endl;
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    std::vector<int> array;
    leetcode::common::strings_to_numbers(strs, array);
    
    Solution *solution = new Solution();
    for (int i = 0; i < array.size(); i += 2) {
        int dividend = array[i];
        int divisor = array[i + 1];
        cout << dividend << " " << divisor << endl;
        int ret = solution->divide_2(dividend, divisor);
        cout << ret << endl;
    }

      
    return 0;
}
