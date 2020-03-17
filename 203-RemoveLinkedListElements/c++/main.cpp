#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(INT_MAX);
        auto pre = dummy;
        dummy->next = head;
        while (head) {
            if (head->val == val) {
                pre->next = head->next;
                head = head->next;
                continue;
            }
            pre = head;
            head = head->next;
        }
        pre = dummy->next;
        delete dummy;
        return pre;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    ListNode *ret = solution->removeElements(list1, 6);
    leetcode::common::print_list(ret);

    return 0;
}
