#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "common/cpp_common.h"
#include <algorithm>
#include <map>
#include <climits>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/
// 这个问题使用栈来解决，最后判断栈是不是为空
class Solution {
public:
    Solution() {
        mymap[')'] = '(';
        mymap[']'] = '[';
        mymap['}'] = '{';
        myset.insert('(');
        myset.insert('[');
        myset.insert('{');
    }
    // 解法一， 使用了额外的 map 和 set 空间
    bool isValid(string s) {
        std::stack<char> mystack;
        for (int i = 0; i < s.length(); i++) {
            if (myset.find(s[i]) != myset.end()) mystack.push(s[i]);
            else {
                if (mystack.empty()) return false;
                char top = mystack.top();
                if (mymap[s[i]] != top) 
                    return false;
                else
                    mystack.pop();
            }
        }
        if (mystack.empty()) return true;
        else return false;
    }
    // 解法二： switch case 节省空间
    bool isValid_2(string s) {
        std::stack<char> mystack;
        for (int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case '(': mystack.push(']'); break;
                case '{': mystack.push('}'); break;
                case '[': mystack.push(']'); break;
                default:
                    if (mystack.empty() || mystack.top() != s[i]) return false;
                    else mystack.pop();
            }
        }
        return mystack.empty();
    }
private:
    std::map<char, char> mymap;
    std::set<char> myset;
};

int main() {
    std::vector<std::string> strs;
    std::string str;
    leetcode::common::get_string_from_file("./data1.txt", str);
    strs = leetcode::common::split(str,'\n');
    Solution *solution = new Solution(); 
    for (auto str : strs) {
        cout << str << endl;
        auto result = solution->isValid_2(str);
        cout << (result ? "True" : "False") << endl;
    }
   
    return 0;
}
