#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>

using namespace std;
// https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *ret = head;
        while(1) {
            int min = INT_MAX;
            ListNode *cur = NULL;
            int pos = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    if (lists[i]->val < min) {cur = lists[i]; min = lists[i]->val; pos = i;}
                }
            }
            if (!cur) break;
            lists[pos] = lists[pos]->next;
            head->next = cur;
            head = head->next;
        }
        return ret->next;
    }
};

int main(int argc, char *argv[]) {
    vector<ListNode *> lists = leetcode::common::get_lists_from_file("list1.txt", '\n', ',');
    for (int i = 0; i < lists.size(); i++) {
        leetcode::common::print_list(lists[i]);
    }
    Solution *solution = new Solution();
    ListNode *ret = solution->mergeKLists(lists);
    leetcode::common::print_list(ret);

    return 0;
}
