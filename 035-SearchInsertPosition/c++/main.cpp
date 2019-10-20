#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(const vector<int>& nums, const int &target, int start, int end) {
        if (start == end) {
            if (target > nums[start]) return start + 1;
            return start;
        }
        if (start + 1 == end) {
            if (target == nums[end]) return end;
            if (target > nums[end]) return end + 1;
            if (target <= nums[start]) return start;
            return end;
        }
        int mid = (start + end) / 2;
        if (target == nums[mid]) return mid;
        int ret;
        if (target < nums[mid]) ret = search(nums, target, start, mid - 1);
        if (target > nums[mid]) ret = search(nums, target, mid + 1, end);
        return ret;
    }

    int searchInsert_2(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] == target) return mid;
            else {
                end = mid - 1;
            }
        }
        return start;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> lines;
    std::string content;
    leetcode::common::get_string_from_file("./data1.txt", content);
    lines = leetcode::common::split(content,'\n');
    for (int i = 0; i < lines.size(); i++) {
        vector<string> words = leetcode::common::split(lines[i], ',');
        std::vector<int> array;
        leetcode::common::strings_to_numbers(words, array);
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "please enter the target :" << endl;
        int target;
        cin >> target;
        Solution *solution = new Solution();
        int result = solution->searchInsert_2(array, target);
        cout << "The result is: " << result << endl;
    }
    return 0;
}
