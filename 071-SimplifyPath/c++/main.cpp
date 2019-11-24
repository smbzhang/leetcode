#include <iostream>
#include <vector>
#include "common/cpp_common.h"
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;
// https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        std::stack<string> mystack;
        int n = path.size();
        mystack.push("/");
        for (int i = 0; i < path.size(); i++) {
            while (i < n && path[i] == '/') i++;
            if (i >= n) break;
            if (path[i] != '.') {
                int begin = i;
                while(i < n && path[i] != '/') i++;
                mystack.push(path.substr(begin, i - begin));
            }else {
                int begin = i;
                while (i < n && path[i] == '.') i++;
                if (i - begin == 2 && ( (i == n || (i < n && path[i] == '/')) )) {
                    if (mystack.size() == 1) continue;
                    else mystack.pop();
                }else if (i - begin == 1 && (i == n || (i < n && path[i] == '/'))){
                    continue;
                }else {
                    while (i < n && path[i] != '/') i++;
                    mystack.push(path.substr(begin, i - begin));
                }
            }
        }
        if (mystack.size() == 1) return "/";
        string result = "";
        while (mystack.size() != 1) {
            result = "/" + mystack.top() + result;
            mystack.pop();
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::string path;
    while (cin >> path) {
        Solution *solution = new Solution();
        cout << solution->simplifyPath(path) << endl;
    }

    return 0;
}
