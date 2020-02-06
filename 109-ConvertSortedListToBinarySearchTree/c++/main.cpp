#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 解法一：递归求解 时间复杂度 - O(nlogn), 空间复杂度 O(1)
    TreeNode* sortedListToBST_2(ListNode* head) {
        if (!head) return nullptr;
        int n = 0, mid;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        return loop(head, 0, n - 1);
    }
    TreeNode *loop(ListNode *head, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return new TreeNode(head->val);
        int mid = (start + end) / 2;
        ListNode *cur = head;
        for (int i = start; i < mid; i++) {
            cur = cur->next;
        }
        TreeNode *root = new TreeNode(cur->val);
        root->left = loop(head, start, mid - 1);
        root->right = loop(cur->next, mid + 1, end);
        return root;
    }
    // 解法二：变成数组 - 空间复杂度 O（N）， 时间复杂度 O(logN)
    // 解法三： 简化解法一的寻找中间点的做法， O(logn)
    TreeNode *sortedListToBST_3(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        ListNode *fast = head, *slow = head, *pslow = nullptr;
        while (fast->next) {
            pslow = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast->next) fast = fast->next;
        }
        pslow->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }  
    // 解法四: 使用中序遍历求解，链表的头结点一定是二叉树的最左边的结点。
    TreeNode *sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        return loop_2(head, 0, n - 1);
    }
    TreeNode *loop_2(ListNode *&head, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(0);
        root->left = loop_2(head, start, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = loop_2(head, mid + 1, end);
        return root;
    }
    
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ',', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    cout << "Please enter the number node from the end you want to remove: " << endl;
    TreeNode *root = solution->sortedListToBST(list1);
    levelOrder(root);
    return 0;
}
