#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <climits>
using namespace std;
using namespace leetcode::common;

//https://leetcode.com/problems/insertion-sort-list/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        head = head->next;
        while (head) {
            auto tmp = dummy->next, pre = dummy;
            while (tmp->val < head->val) {
                pre = tmp;
                tmp = tmp->next;
            }
            if (tmp == head) {
                head = head->next;
                continue;
            }
            auto head_pre = dummy;
            while (head_pre->next != head) head_pre = head_pre->next;
            pre->next = head;
            auto next = head->next;
            head->next = tmp;
            head_pre->next = next;
            head = next;

            leetcode::common::print_list(dummy);
        }
        return dummy->next;
    }
};


int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list1.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    ListNode *ret = solution->insertionSortList(list1);
    leetcode::common::print_list(ret);

    return 0;
}

