#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/palindrome-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        auto odd = head, even = head->next, list2 = even;
        // 拼凑odd链表
        while (even && even->next) {
            auto tmp = even->next;
            odd->next = tmp;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = list2;
        return head;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ',', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    list1 = solution->oddEvenList(list1);
    leetcode::common::print_list(list1);


    return 0;
}
