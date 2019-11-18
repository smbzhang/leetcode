#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
// https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *fast = head, *low = head;
        int n = 0;
        while (fast != NULL) {
            n++;
            fast = fast->next;
        }
        if (n <= 1) return head;
        fast = head; k = k % n;
        if (k == 0) return head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            low = low->next;
        }
        ListNode *result = low->next;
        low->next = NULL;
        fast->next = head;
        return result;
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
    ListNode *ret = solution->rotateRight(list1, n);
    leetcode::common::print_list(ret);

    return 0;
}
