#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <deque>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/reorder-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        std::deque<ListNode *> mydeque;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while (head) {
            mydeque.emplace_back(head);
            head = head->next;
        }
        head = dummy->next;
        while (!mydeque.empty()) {
            dummy->next = mydeque.front();
            mydeque.pop_front();
            dummy = dummy->next;
            if (mydeque.empty()) break;
            dummy->next = mydeque.back();
            mydeque.pop_back();
            dummy = dummy->next;
        }
        dummy->next = nullptr;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    solution->reorderList(list1);
    leetcode::common::print_list(list1);

    return 0;
}
