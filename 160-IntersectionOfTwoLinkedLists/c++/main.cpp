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
    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        auto curA = headA, curB = headB;
        int lenA = 1, lenB = 1;
        while (curA->next) {
            lenA++;
            curA = curA->next;
        }
        while (curB->next) {
            lenB++;
            curB = curB->next;
        }
        if (curA != curB) return nullptr;
        if (lenB > lenA) {
            curA = headA;
            headA = headB;
            headB = curA;
        }
        for (int i = 0; i < abs(lenA - lenB); i++) {
            headA = headA->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    // 解法二： 超级简洁
    // 把两个链表相同的部分记为c，相交节点记为*, 则第一个链表记为 a * c, 第二个链表记为b * c
    //两个虚拟链表AB, BA可以记为：
    //a * c b * c
    //b * c a * c
    //a, b长度不一定同，但是第二个 * 之前两个链表的长度相同，由此两个虚拟链表走相同步数可以到第二个 * 处
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto curA = headA, curB = headB;
        while (curA != curB) {
            curA = (curA == nullptr) ? curA = headB : curA = curA->next;
            curB = (curB == nullptr) ? curB = headA : curB = curB->next;
        }
        return curA;
    }
};

