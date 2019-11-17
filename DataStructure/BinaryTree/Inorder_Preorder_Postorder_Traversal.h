#include "BinaryTreeStructure.h"


vector<int> pre;
void preorder(Node *r) {
    if (r == nullptr)
        return;
    pre.push_back(r->val);
    preorder(r->left);
    preorder(r->right);
}

vector<int> in;
void inorder(Node *r) {
    if (r == nullptr)
        return;
    inorder(r->left);
    in.push_back(r->val);
    inorder(r->right);
}


vector<int> post;
void postorder(Node *r) {
    if (r == nullptr)
        return;
    postorder(r->left);
    postorder(r->right);
    post.push_back(r->val);
}