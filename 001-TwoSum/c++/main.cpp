#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        std::unordered_map<int, int> hmap;
        for (int i = 0; i < nums.size(); i++) {
            hmap[nums[i]] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            int sub = target - nums[i];
            auto iter = hmap.find(sub);
            if (iter != hmap.end() && iter->second != i) {
                result.emplace_back(i);
                result.emplace_back(iter->second);
                break;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');

    std::vector<int> array;
    leetcode::common::strings_to_numbers(strs, array);
    // 解法一
    Solution *solution = new Solution();
    vector<int> result = solution->twoSum(array, 9);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    // 解法二
    Solution2 *solution2 = new Solution2();
    vector<int> result2 = solution2->twoSum(array, 9);

    for(int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}
