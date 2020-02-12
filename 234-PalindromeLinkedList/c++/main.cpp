#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/palindrome-linked-list/
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
    // 解法一： 使用数组存储链表结点，然后使用双指针求解
    // 时间复杂度 O(n), 空间复杂度 O(n)
    bool isPalindrome_1(ListNode* head) {
        std::vector<int> array;
        while (head) {
            array.push_back(head->val);
            head = head->next;
        }
        int start = 0, end = array.size() - 1;
        while (start <= end) {
            if (array[start++] != array[end--]) {
                return false;
            }
        }
        return true;
    }
    // 方法二： 反转后半部分的链表，两个链表进行对比
    // 时间复杂度 O(n) 空间复杂度 O(1)
    bool isPalindrome(ListNode *head) {
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            n++;
        }
        if (n <= 1) return true;
        cur = head;
        for (int i = 0; i < n / 2; i++) {
            cur = cur->next;
        }
        if (n % 2) cur = cur->next;
        // 反转链表
        cur = reverse_list_2(cur);
        while (head && cur) {
            if (head->val != cur->val) return false;
            head = head->next;
            cur = cur->next;
        }
        return true;
    }
    ListNode *reverse_list(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto cur = reverse_list(head->next);
        auto ret = cur;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        head->next = nullptr;
        return ret;
    }
    // 头插法求解
    ListNode *reverse_list_2(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *ret = new ListNode(0);
        ret->next = head;
        auto pre = head;
        head = head->next;
        while (head) {
            auto tmp = head->next;
            head->next = ret->next;
            pre->next = tmp;
            ret->next = head;
            head = tmp;
        }
        return ret->next;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    list1 = solution->reverse_list_2(list1);
    leetcode::common::print_list(list1);
    cout << solution->isPalindrome(list1) << endl;;


    return 0;
}
