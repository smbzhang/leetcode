#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/single-number/
class Solution {
public:
    // 解法一：通用解法--建一个32的数组，存放每一位出现的次数
    int singleNumber_1(vector<int>& nums) {
        int records[32] = {0};
        for (int j = nums.size() - 1; j >= 0; j--) {
            for (int i = 0; i < 32; i++) {
                records[i] += (nums[j] & (1 << i)) == 0 ? 0 : 1;
            }
        }
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (records[i] % 3 != 0) {
                result += 1 << i;
            }
        }
        return result;
    }

    // 解法二：状态机求解 - 最终记录一个数字32位，初始位0，其中每一个位出现3次需要最后变成0。三进制的状态机，用两位来表示
    // int a , b = 0
    // nums[i] 记录为 c
    // a, b, c的每一位的状态机为
    // a b  
    // 0 0   一次 1
    // 0 1   两次 1
    // 1 0   三次 1
    // 0 0   四次 1
    //
    // a b c    a b 
    // 0 0 0    0 0
    // 0 1 0    0 1
    // 1 0 0    1 0
    // 0 0 1    0 1
    // 0 1 1    1 0
    // 1 0 1    0 0
    // new_a = a & ~b & ~c  +  ~a & b & c
    // new_b = ~a & b & ~c  +  ~a & ~b & c = ~a & (b ^ c)
    // https://juejin.im/post/5cb962dbf265da03761e8601
    int singleNumber_2(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto c : nums) {
            int new_a = (a & ~b & ~c) | (~a & b & c);
            b = ~a & (b ^ c);
            a = new_a;
        }
        return b;
    }

    // 解法三： 使用快排分类的方法求解
    int singleNumber(vector<int>& nums) {
        // ...
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
    for (auto str : strs) {
        cout << str << endl;
        std::vector<string> array_s  = leetcode::common::split(str,',');
        std::vector<int> nums;
        leetcode::common::strings_to_numbers<int>(array_s, nums);
        cout << solution->singleNumber(nums) << endl;;
    }
   
    return 0;
}
