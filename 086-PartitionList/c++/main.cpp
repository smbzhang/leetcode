#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
using namespace leetcode::common;

// https://leetcode.com/problems/partition-list/
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
    // 解法一： 使用快排的分类方法，slow 指向最后小于x的结点，head > x的时候，
    // 因为需要暴政稳定性，遇到小于x的就 slow 后面插，slow++， head++
    ListNode* partition_2(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(0), *slow;
        dummy->next = head;
        head = dummy;
        // 找到大于 x 的第一个元素，确定head
        while (head->next) {
            if (head->next->val >= x) {
                slow = head;
                head = head->next;
                break;
            }
            head = head->next;
        }
        // 快排分类
        while(head->next) {
            if (head->next->val < x) {
                ListNode *move = head->next;
                head->next = move->next;
                move->next = slow->next;
                slow->next = move;
                slow = slow->next;
                continue;
            }
            head = head->next;
        }
        return dummy->next;
    }

    // 解法二： 先找出 < x的结点，在找出 >= x的结点，然后串联起来
    ListNode *partition(ListNode *head, int x) {
        ListNode *l = new ListNode(0), *r = new ListNode(0), *ll = l, *rr = r;
        while (head) {
            if (head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                r->next = head;
                r= r->next;
            }
            head = head->next;
        }
        r->next = nullptr;
        l->next = rr->next;
        return ll->next;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    cout << "Please enter the number node from the end you want to remove: " << endl;
    int n;
    cin >> n;
    ListNode *ret = solution->partition(list1, n);
    leetcode::common::print_list(ret);

    return 0;
}
