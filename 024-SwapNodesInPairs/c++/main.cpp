#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>
#include <queue>

using namespace std;
// https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *n = new ListNode(0), *cur = n;
        n->next = head;
        while(cur->next && cur->next->next) {
            auto node1 = cur->next;
            auto node2 = cur->next->next;
            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1;
        }
        return n->next;
    }

    // 递归实现
    ListNode* swapPairs_2(ListNode* head) {        
        if (!head || !head->next) return head;
        ListNode *ret = swapPairs_2(head->next->next);
        auto node = head->next;
        head->next = ret;
        node->next = head;
        return node;
    }
};

int main(int argc, char *argv[]) {
    vector<ListNode *> lists = leetcode::common::get_lists_from_file("list1.txt", '\n', ',');
    Solution *solution = new Solution();
    for (int i = 0; i < lists.size(); i++) {
        leetcode::common::print_list(lists[i]);
        auto ret = solution->swapPairs_2(lists[i]);
        leetcode::common::print_list(ret);
    }

    return 0;
}
