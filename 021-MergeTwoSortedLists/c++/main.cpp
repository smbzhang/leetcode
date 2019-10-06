#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>

using namespace std;
// https://leetcode.com/problems/merge-two-sorted-lists/
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
        // 解法一， 头指针的确定很繁琐，条件很多
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *head = NULL, *pcur = NULL;
            while(l1 && l2) {
                if (pcur == NULL) {
                    pcur = (l1->val <= l2->val) ? l1 : l2;
                    head = pcur;
                    if (l1->val <= l2->val) l1 = l1->next;
                    else l2 = l2->next;
                    continue;
                }
                if (l1->val <= l2->val) {
                    pcur->next = l1;
                    l1 = l1->next;
                    pcur = pcur->next;
                }else{
                    pcur->next = l2;
                    l2 = l2->next;
                    pcur = pcur->next;
                }
            }
            if (pcur == NULL) head = l1 ? l1 : l2;
            else pcur->next = l1 ? l1 : l2;
            return head;
        }    
        // 解法二，使用类似带头结点的链表来实现，头结点存放 INT_MIN，这样返回的时候只需要返回头结点的next，不需要判断第一个结点是l1还是l2
        ListNode* mergeTwoLists_2(ListNode* l1, ListNode* l2) {
            ListNode *head = new ListNode(INT_MIN), *pcur = head;
            while (l1 && l2) {
                if (l1->val <= l2->val) {
                    pcur->next = l1;
                    l1 = l1->next;
                    pcur= pcur->next;
                }else{
                    pcur->next = l2;
                    l2 = l2->next;
                    pcur= pcur->next;
                }
            }
            pcur->next = l1 ? l1 : l2;
            return head->next;
        }
};
int main(int argc, char *argv[]) {
    ListNode *list1 = NULL, *list2 = NULL;
    leetcode::common::get_list_from_file("list1.txt", ' ', &list1);
    leetcode::common::get_list_from_file("list2.txt", ' ', &list2);

    leetcode::common::print_list(list1);
    leetcode::common::print_list(list2);

    Solution *solution = new Solution();
    ListNode *ret = solution->mergeTwoLists(list1, list2);
    leetcode::common::print_list(ret);

    return 0;
}
