#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    // 暴力搜索 O(n2)
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = j - i;
                int h = std::min(height[i], height[j]);
                int con = w * h;
                max = con > max ? con : max;
            }
        }
        return max;
    }
    // https://leetcode.wang/leetCode-11-Container-With-Most-Water.html O(n)的时间复杂度
    int maxArea_2(vector<int>& height) {
        int n = height.size();
        int start = 0, end = n - 1;
        int max = 0;
        while(start < end) {
            int con = std::min(height[start], height[end]) * (end - start);
            max = (con > max) ? con : max;
            if (height[start] < height[end]) {
                start++;
            }else{
                end--;
            }
        }
        return max;
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
    for (std::string str : strs) {
        std::cout << str << std::endl;
        std::vector<string> str_heights = leetcode::common::split(str, ',');
        std::vector<int> height;
        leetcode::common::strings_to_numbers(str_heights, height);
        int container = solution->maxArea(height);
        std::cout << "The max container is: " << container << std::endl;
    }
   
    return 0;
}
