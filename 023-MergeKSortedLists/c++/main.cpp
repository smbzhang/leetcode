#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>
#include <climits>
#include <queue>

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

    // 使用递归实现
    ListNode* mergeKLists_2(vector<ListNode *>& lists) {
        ListNode *ret = merge(lists, 0);
        return ret;
    } 
    ListNode* merge(vector<ListNode *> &lists, int pos) {
        if (pos == lists.size()) return NULL;
        if (pos == lists.size() - 1) return lists[pos];
        ListNode *cur = new ListNode(0);
        ListNode *ret = cur;
        ListNode *list1 = lists[pos];
        ListNode *list2 = merge(lists, pos+1);
        while (list1 || list2) {
            if (!list1) {
                cur->next = list2;
                break;
            }
            if (!list2) {
                cur->next = list1;
                break;
            }
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        return ret->next;
    }

    // 使用优先队列实现
    class cmp {
    public:
        bool operator()(const ListNode *l1, const ListNode *l2) {
            return l1->val > l2->val;
        }
    };
    ListNode *mergeKLists_3(vector<ListNode *>& lists) {
        std::priority_queue<ListNode *, vector<ListNode *>, cmp> myqueue;
        ListNode *cur = new ListNode(0), *ret = cur;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) myqueue.push(lists[i]);
        }
        while (!myqueue.empty()) {
            ListNode * node = myqueue.top();
            cur->next = node;
            cur = cur->next;
            node = node->next;
            myqueue.pop();
            if (node != NULL) {
                myqueue.push(node);
            }
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
    ListNode *ret = solution->mergeKLists_3(lists);
    leetcode::common::print_list(ret);

    return 0;
}
