#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
using namespace std;

// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (i < nums.size() && nums[i] == val) i++;
            if (i >= nums.size()) break;
            nums[pos++] = nums[i];
            ret++;
        }
        return ret;
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
        cout << "plese enter the number you want to remove: " << endl;
        int val;
        cin >> val;
        int ret = solution.removeElement(nums, val);
        cout << ret << endl;
        for (int i = 0; i < ret; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
