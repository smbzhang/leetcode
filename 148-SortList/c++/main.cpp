#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>

using namespace std;
using namespace leetcode::common;
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
    int listLen(ListNode *head) {
        int ret = 0;
        while (head) {
            ret++;
            head = head->next;
        }
        return ret;
    }
    ListNode* sortList(ListNode* head) {
        return loop(head);
    }
    ListNode *loop(ListNode *head) {
        int len = listLen(head), i = 0;
        if (len <= 1) return head;
        ListNode *head2 = head, *pre = nullptr;
        for (; i < len / 2; i++) {
            pre = head2;
            head2 = head2->next;
        }
        pre->next = nullptr;
        head = loop(head);
        head2 = loop(head2);
        auto ret = merge(head, head2);
        return ret;
    }
    ListNode *merge(ListNode *head, ListNode *head2) {
        ListNode *dummy = new ListNode(INT_MIN), *pre = dummy;
        dummy->next = head;
        while (head && head2) {
            if (head->val <= head2->val) {
                pre = head;
                head = head->next;
            } else {
                auto tmp = head2->next;
                head2->next = head;
                pre->next = head2;
                pre = head2;
                head2 = tmp;
            }
        }
        if (head) {
            while (head->next) {
                head = head->next;
            }
            head->next = head2;
        }        
        else pre->next = head2;
        return dummy->next;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);


    ListNode *node0 = new ListNode(4);
    ListNode *node1 = new ListNode(1);
    
    Solution *solution = new Solution();
    auto tmp = solution->merge(node0, node1);
    leetcode::common::print_list(tmp);

    ListNode *ret = solution->sortList(list1);
    leetcode::common::print_list(ret);
    return 0;
}
