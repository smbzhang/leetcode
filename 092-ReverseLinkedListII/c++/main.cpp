#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>

using namespace std;
using namespace leetcode::common;

// https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 反转链表请见206 - 递归、头插、stack
        // 这里使用头插法 space: O(1) time: O(n)
        ListNode *dummy = new ListNode(INT_MAX);
        dummy->next = head;
        auto fast = head, pre = dummy;
        for (int i = 0; i <= n - m; i++) {
            fast = fast->next;
        }
        for (int i = 1; i < m; i++) {
            fast = fast->next;
            pre = head;
            head = head->next;
        }
        auto pre_head = head;
        head = head->next;
        while (head != fast) {
            auto tmp = head->next;
            head->next = pre->next;
            pre->next = head;
            pre_head->next = tmp;
            head = tmp;
        }
        return dummy->next;
    }
};
// 看下简洁的写法
class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
   }
};
int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ',', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    int m, n;
    cin >> m >> n;
    ListNode *ret = solution->reverseBetween(list1, m, n);
    leetcode::common::print_list(ret);

    return 0;
}
