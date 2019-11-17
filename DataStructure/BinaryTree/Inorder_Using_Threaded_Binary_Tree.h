#include "BinaryTreeStructure.h"

void inorderOnThreadedTree(Node *cur) {
    if (cur == nullptr)
        return;
    Node *tmp;
    while (cur != nullptr) {
        if (cur->left != nullptr) {
            tmp = cur->left;
            while (tmp->right != nullptr)
                tmp = tmp->right;
            tmp->right = cur;
            cur = cur->left;
        } else {
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
}