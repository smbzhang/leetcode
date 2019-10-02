#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
using namespace std;

//https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    // 把所有的 能用到的拼接字符全部存入 map 中
    string intToRoman(int num) {
        std::map<int, string> records({
                {3000, "MMM"}, {2000, "MM"}, {1000, "M"},
                {900, "CM"},   {800, "DCCC"},{700, "DCC"},{600, "DC"},{500, "D"},{400, "CD"},{300, "CCC"},{200, "CC"},{100, "C"},
                {90, "XC"},    {80, "LXXX"}, {70, "LXX"}, {60, "LX"}, {50, "L"}, {40, "XL"}, {30, "XXX"}, {20, "XX"}, {10, "X"},
                {9, "IX"},     {8, "VIII"},  {7, "VII"},  {6, "VI"},  {5, "V"},  {4, "IV"},  {3, "III"},  {2, "II"},  {1, "I"}
        });
        int j = 1000;
        std:string result = "";
        while(j > 0) {
            int quot = num / j;
            num %= j;
            if (quot)
                result += records[quot * j];
            j /= 10;
        }
        return result;
    }
    // 不使用 map 使用数组来实现，借助数组的下标，这个人很秀，我还是太lj了~
    string intToRoman_2(int num) {
        static const string s[4][10]= 
        { 
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"},
        };
        
        return s[3][num/1000%10] + s[2][num/100%10] + s[1][num/10%10] + s[0][num%10];
    }
};

int main() {
    vector<int> nums1; 
    vector<int> nums2;
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    std::vector<int> array;
    leetcode::common::strings_to_numbers(strs, array);
    for (auto num : array) {
        cout << num << endl;
        string result = solution->intToRoman_2(num);
        cout << result << endl;
    }
   
    return 0;
}
