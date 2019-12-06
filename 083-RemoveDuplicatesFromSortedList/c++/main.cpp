#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>
#include <queue>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (slow) {
            while (fast && fast->val == slow->val) {
                fast = fast->next;
            }
            slow->next = fast;
            slow = fast;
        }
        return head;
    }
};
int main(int argc, char *argv[]) {
    vector<ListNode *> lists = leetcode::common::get_lists_from_file("list1.txt", '\n', ',');
    for (int i = 0; i < lists.size(); i++) {
        leetcode::common::print_list(lists[i]);
        Solution *solution = new Solution();
        ListNode *ret = solution->deleteDuplicates(lists[i]);
        leetcode::common::print_list(ret);
    }

    return 0;
}
