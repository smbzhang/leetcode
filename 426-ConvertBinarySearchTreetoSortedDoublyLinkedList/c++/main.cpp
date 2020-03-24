#include <iostream>
#include "datastruct/data_struct.h"
#include "common/cpp_common.h"
#include <stack>

using namespace std;
using namespace leetcode::common;
// https://leetcode.com/problems/palindrome-linked-list/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        auto res = head;
        while (head) {
            while (head && head->child == nullptr) {
                head = head->next;
            }
            if (head) {
                auto ret = flatten(head->child);
                auto tmp = head->next;
                head->next = ret;
                head->child = nullptr;
                while (ret->next) {
                    ret = ret->next;
                }
                ret->next = tmp;
                head = tmp;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
