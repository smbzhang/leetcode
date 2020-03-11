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
    // 快慢指针求解
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        auto pre = dummy, fast = head->next, slow = head;
        while (fast && slow) {
            if (fast->val != slow->val) {
                pre = slow;
                slow = fast;
                fast = fast->next;
                continue;
            }
            while (fast && fast->val == slow->val) {
                fast = fast->next;
            }
            if (fast == nullptr) {
                pre->next = nullptr;
                break;
            }
            pre->next = fast;
            slow = fast;
            fast = fast->next;
        }
        return dummy->next;
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
