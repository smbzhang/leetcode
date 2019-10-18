#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>
#include <queue>

using namespace std;
// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head;
        while(cur) {n++; cur = cur->next;}
        if (n < k || k <= 1) return head;
        cur = head;
        for (int i = 0; i < k; i++) {
            cur = cur->next;
        }
        auto ret = reverseList(head, k);
        head->next = reverseKGroup(cur, k);
        return ret;
    }

    ListNode *reverseList(ListNode* head, int k) {
        if (k <= 1 || head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *tail = reverseList(head->next, k - 1);
        head->next->next = head;
        head->next = NULL;
        return tail;
    }
};

int main(int argc, char *argv[]) {
    vector<ListNode *> lists = leetcode::common::get_lists_from_file("list1.txt", '\n', ',');
    for (int i = 0; i < lists.size(); i++) {
        leetcode::common::print_list(lists[i]);
    }
    Solution *solution = new Solution();
    int k;
    cout << "please enter k: " << endl;
    cin >> k;
    //ListNode *ret = solution->reverseKGroup(lists, k);
    ListNode *ret = solution->reverseKGroup(lists[0], k);
    leetcode::common::print_list(ret);

    return 0;
}
