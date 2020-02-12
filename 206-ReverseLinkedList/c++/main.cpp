#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

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
    // 解法一：递归
    ListNode* reverseList_1(ListNode* head) {
        if(!head || !head->next) return head;
        auto ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
    // 解法二：使用栈反转
    ListNode *reverseList_2(ListNode *head) {
        if(!head || !head->next) return head;
        std::stack<ListNode *> mystack;
        while (head) {
            mystack.push(head);
            head = head->next;
        }
        ListNode *ret = nullptr, *result = nullptr;
        while (!mystack.empty()) {
            auto node = mystack.top();
            if (!ret) {
                ret = node;
                result = node;
            }
            else {
                ret->next = node;
                ret = ret->next;
            }
            mystack.pop();
        }
        ret->next = nullptr;
        return result;
    }
    // 解法三：头插法求解
    ListNode *reverseList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = head, cur = head->next;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            pre->next = tmp;
            cur = tmp;
        }
        return dummy->next;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    ListNode *ret = solution->reverseList(list1);
    leetcode::common::print_list(ret);

    return 0;
}
