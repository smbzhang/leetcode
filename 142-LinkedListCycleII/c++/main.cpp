#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <unordered_set>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/linked-list-cycle-ii/
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
    // 解法一：使用 set, 双复杂度 O(n)
    ListNode *detectCycle_1(ListNode *head) {
        std::unordered_set<ListNode *> myset;
        while (head) {
            if (myset.find(head) == myset.end()) {
                myset.insert(head);
                head = head->next;
            } else {
                return head;
            }
        }
        return nullptr;
    }

    // 解法二：使用双指针，空间复杂度 O(1),时间 O(n)
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head, *record = nullptr;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                record = slow;
                break;
            }
        }
        if (record == nullptr) return nullptr;
        int step = 0;
        fast = fast->next;
        while (fast != slow) {
            step++;
            fast = fast->next;
        }
        slow = head, fast = head;
        for (int i = 0; i <= step; i++) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);
    list1->next->next->next = list1->next;

    Solution *solution = new Solution();
    ListNode *ret = solution->detectCycle(list1);
    std::cout << ret->val << std::endl;
    return 0;
}
