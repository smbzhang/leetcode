#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
using namespace leetcode::common;

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        auto head = root;
        std::vector<ListNode *> result;
        while (root) {
            len++;
            root = root->next;
        }
        int n = len % k, m = len / k;
        for (int i = 0; i < k; i++) {
            // 多加一个结点 m+1
            if (i < n) {
                result.push_back(head);
                int j = 1;
                while (j < m + 1 && head->next) {
                    head = head->next;
                    j++;
                }
                if (head->next == nullptr) {
                    head = nullptr;
                } else {
                    auto tmp = head->next;
                    head->next = nullptr;
                    head = tmp;
                }
            } else {
                // m 个结点
                if (head == nullptr) result.push_back(head);
                else {
                    result.push_back(head);
                    int j = 1;
                    while (j < m && head->next) {
                        head = head->next;
                        j++;
                    }
                    if (head->next == nullptr) {
                        head = nullptr;
                    } else {
                        auto tmp = head->next;
                        head->next = nullptr;
                        head = tmp;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = NULL;
    leetcode::common::get_list_from_file("list.txt", ' ', &list1);

    leetcode::common::print_list(list1);

    Solution *solution = new Solution();
    int k;
    while (cin >> k) {
        vector<ListNode *> ret = solution->splitListToParts(list1, k);
        for (int i = 0; i < ret.size(); i++) {
            print_list(ret[i]);
        }
    }

    return 0;
}

