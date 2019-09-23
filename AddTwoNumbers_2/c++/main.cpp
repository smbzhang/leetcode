#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pcur1 = l1, *pcur2 = l2, *pcur = NULL, *ret = NULL;
        int carry = 0;
        while (pcur1 != NULL) {
            int num1 = pcur1->val;
            if (pcur2 != NULL) {
                int num2 = pcur2->val;
                    int mod = (num1 + num2 + carry) % 10;
                    if (pcur == NULL) {
                        pcur = new ListNode(mod);
                        ret = pcur;
                    }else {
                        ListNode *node = new ListNode(mod);
                        pcur->next = node;
                        pcur = node;
                    }
                    carry = (num1 + num2 + carry) / 10;
                    pcur2 = pcur2->next;
            }else
                break;
            pcur1 = pcur1->next;
        }
        while(pcur1 != NULL) {
            int mod = (pcur1->val + carry) % 10;
            carry = (pcur1->val + carry) / 10;
            ListNode *node = new ListNode(mod);
            pcur->next = node;
            pcur = node;
            pcur1 = pcur1->next;
        }
        while(pcur2 != NULL) {
            int mod = (pcur2->val + carry) % 10;
            carry = (pcur2->val + carry) / 10;
            ListNode *node = new ListNode(mod);
            pcur->next = node;
            pcur = node;
            pcur2 = pcur2->next;

        }

        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            pcur->next = node;
            pcur = node;
        }
        return ret;        
    }
    
    ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL, *pcur = NULL;
        int num1 = 0, num2 = 0, carry = 0;
        while (l1 != NULL || l2 != NULL) {
            num1 = (l1 == NULL) ? 0 : l1->val;
            num2 = (l2 == NULL) ? 0 : l2->val;
            int mod = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;
            ListNode *node = new ListNode(mod);
            if (pcur == NULL) {
                pcur = node;
                ret = pcur;
            } else {
                pcur->next = node;
                pcur = node;
            }
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            pcur->next = node;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1, *list2 = NULL;
    leetcode::common::get_list_from_file("list1.txt", ' ', &list1);
    leetcode::common::get_list_from_file("list2.txt", ' ', &list2);

    leetcode::common::print_list(list1);
    leetcode::common::print_list(list2);

    Solution *solution = new Solution();
    ListNode *ret = solution->addTwoNumbers_2(list1, list2);
    leetcode::common::print_list(ret);

    return 0;
}
