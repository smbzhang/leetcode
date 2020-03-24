#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace leetcode{
namespace common{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {
            
        }
    };

    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node* child;
    };
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next;
        TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    };

    TreeNode *createTreeNode(const string& str);
    TreeNode *ConstructTree(const vector<string>& array); 
    vector<int> InorderTraversal(TreeNode* root); 
    void loop(TreeNode *root, vector<int> &result); 
    vector<vector<int> > levelOrder(TreeNode* root);
    vector<int> MirrosInorderTraversal(TreeNode *root);
}
}


#endif
