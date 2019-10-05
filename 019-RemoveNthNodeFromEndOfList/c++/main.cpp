#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 采用快慢指针的解法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n == 0) return head;
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++) {
            if (fast != NULL)
                fast = fast->next;
            else
                return head;
        }
        // 删除 头 的情况
        if (!fast) return head->next;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
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
    ListNode *ret = solution->removeNthFromEnd(list1, n);
    leetcode::common::print_list(ret);

    return 0;
}
