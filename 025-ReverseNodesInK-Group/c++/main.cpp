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

    // 使用递归实现单链表的反转
    ListNode *reverseList(ListNode* head, int k) {
        if (k <= 1 || head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *tail = reverseList(head->next, k - 1);
        head->next->next = head;
        head->next = NULL;
        return tail;
    }
    // 使用头插法实现 O(n) 非递归的单链表反转，找到 head，然后遍历中的每一个元素都插入到head的前面。
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
    ListNode *ret = solution->reverseKGroup_2(lists[0], k);
    leetcode::common::print_list(ret);

    return 0;
}
