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

