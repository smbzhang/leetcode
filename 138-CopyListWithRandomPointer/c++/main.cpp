#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
// https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    // 采用 hash_map 来实现
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        std::unordered_map<Node *, int> mp;
        mp[nullptr] = -1;
        std::vector<Node *> vec;
        int i = 0;
        auto _head = head;
        while(_head) {
            Node *tmp = new Node(_head->val);
            mp[_head] = i++;
            vec.push_back(tmp);
            _head = _head->next;
        }
        _head = head;
        i = 0;
        while(_head) {
            int pos = mp[_head->random];
            vec[i]->random = pos == -1 ? nullptr : vec[pos];
            vec[i]->next = i + 1 >= vec.size() ? nullptr : vec[i + 1];
            i++;
            _head = _head->next;
        }
        return vec[0];
    }
};
int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();

    return 0;
}
