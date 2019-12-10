#include "data_struct.h"

namespace leetcode{
namespace common{
TreeNode *createTreeNode(const string& str) {
    if (str == "null") return nullptr;
    int val = atoi(str.c_str());
    TreeNode *root = new TreeNode(val);
    return root;
}

TreeNode *ConstructTree(const vector<string>& array) {
    if (array.size() <= 0) return nullptr;
    TreeNode *root = createTreeNode(array[0]);
    TreeNode *result = root;
    std::queue<TreeNode *> myqueue;
    myqueue.push(root);
    for (int i = 1; i < array.size();) {
        TreeNode *root = myqueue.front();
        myqueue.pop();
        root->left = createTreeNode(array[i++]);
        if (i < array.size()) root->right = createTreeNode(array[i++]);
        myqueue.push(root->left);
        myqueue.push(root->right);
    }
    return result;
}

vector<int> InorderTraversal(TreeNode* root) {
    vector<int> result;
    loop(root, result);
    std::cout << "inorderTraversal result: " << std::endl;
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << endl;
    return result;
}
void loop(TreeNode *root, vector<int> &result) {
    if (root == nullptr) return;
    loop(root->left, result);
    result.push_back(root->val);
    loop(root->right, result);
}


// Mirros 实现中旭遍历， 空间复杂度只有 O(1), 利用叶子结点来代替栈
// Mirrors 中序遍历，实现 O(1)的空间复杂度，不使用递归，不实用额外的栈空间
// 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
// 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
// 2.1 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
// 2.2 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
// 3. 重复以上1、2直到当前节点为空。
vector<int> MirrosInorderTraversal(TreeNode *root) {
    vector<int> result;
    while (root) {
        if (root->left == nullptr) {
            std::cout << root->val << " ";
            result.push_back(root->val);
            root = root->right;
            continue;
        }
        // 寻找前驱结点
        TreeNode *prenode = root->left;
        // 当前结点的右孩子不等于nullptr，并且不等于 当前结点root
        while (prenode->right != nullptr && prenode->right != root) {
            prenode = prenode->right;
        }
        // 2.1 如果前驱节点的右孩子为空
        if (prenode->right == nullptr) {
            prenode->right = root;
            root = root->left;
        }
        // 2.2 如果前驱节点的右孩子为当前节点
        else {
            // 输出当前结点，恢复树的形状
            std::cout << root->val << " ";
            result.push_back(root->val);
            prenode->right = nullptr;
            root = root->right;
        }
    }
    return result;
}

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > result;
    std::queue<TreeNode *> myqueue;
    std::cout << "levelOrder: " << std::endl;
    while (!myqueue.empty() || root != nullptr) {
        if (myqueue.empty() && root != nullptr) {
            myqueue.push(root);
            continue;
        }else {
            int size = myqueue.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                root = myqueue.front();
                myqueue.pop();
                if (root != nullptr) {
                    tmp.push_back(root->val);
                    std::cout << root->val << " ";
                    myqueue.push(root->left);
                    myqueue.push(root->right);
                }
            }
            if(tmp.size() > 0) result.push_back(tmp);
        }
    }
    std::cout << std::endl;
    return result;
}

}
}

