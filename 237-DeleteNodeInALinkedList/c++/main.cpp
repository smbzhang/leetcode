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
    // 删除直接清空链表元素的做法不对的，pre->next 依然指向 原来的那块内存，可能是一个随机值，必须置 pre->next = nullptr
    void deleteNode_error(ListNode* node) {
        auto fast = node->next;
        while (fast) {
            node->val = fast->val;
            fast = fast->next;
            node = node->next;
        }
        node = nullptr;
        free(node);
    }

    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        auto p = node->next;
        p = nullptr;
        delete p;
        node->next = node->next->next;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);
    leetcode::common::print_list(list1);
    Solution *solution = new Solution();
    solution->deleteNode(list1->next);
    leetcode::common::print_list(list1);

    return 0;
}
