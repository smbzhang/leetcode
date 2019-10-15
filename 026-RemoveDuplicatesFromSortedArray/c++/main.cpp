#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int total = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) total = 1;
            else if (nums[i] != nums[i - 1]) total++;
            else;
        }
        ret = total;
        int pos = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) nums[pos++] = nums[i];
        }
        return ret;
    }

    int removeDuplicates_2(vector<int>& A) {
        int count = 0, n = A.size();
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return n-count;
    }
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    for (int i = 0; i < strs.size(); i++) {
        std::vector<string> strings = leetcode::common::split(strs[i], ',');
        vector<int> nums; 
        leetcode::common::strings_to_numbers(strings, nums);
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        Solution solution;
        int ret = solution.removeDuplicates_2(nums);
        cout << ret << endl;
        for (int i = 0; i < ret; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
