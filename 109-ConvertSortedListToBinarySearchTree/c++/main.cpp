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
    TreeNode* sortedListToBST(ListNode* head) {
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
    // 解法三： 中序遍历解法
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
