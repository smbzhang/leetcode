#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
using namespace leetcode::common;
// https://leetcode-cn.com/problems/add-two-numbers-ii/
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
    // 解法一：反转链表 依次相加（反转链表有三个做法 - 头插、递归、stack）
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse_list(l1);
        l2 = reverse_list(l2);
        int len1 = len_list(l1), len2 = len_list(l2);
        if (len2 > len1) {
            auto tmp = l1;
            l1 = l2;
            l2 = tmp;
            std::swap(len2, len1);
        }
        auto head = l1;
        int carry = 0;
        while (l2 && l1) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
            l1 = l1->next;
        }
        l1 = reverse_list(head);
        if (carry) {
            ListNode *node = new ListNode(carry);
            node->next = l1;
            return node;
        }
        return l1;
    }

    ListNode* reverse_list(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto tmp = head->next;
        ListNode* ret = reverse_list(head->next);
        tmp->next = head;
        head->next = nullptr;
        return ret;
    }

    int len_list(ListNode *head) {
        int ret = 0;
        while (head) {
            ret++;
            head = head->next;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL, *list2 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);
    leetcode::common::get_list_from_file("list1.txt", ' ', &list2);

    leetcode::common::print_list(list1);
    leetcode::common::print_list(list2);

    Solution *solution = new Solution();
    list1 = solution->addTwoNumbers(list1, list2);
    cout << endl;
    leetcode::common::print_list(list1);

    return 0;
}
