#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
        
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#endif
