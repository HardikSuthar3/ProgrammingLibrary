#include <BinaryTreeStructure.h>

vector<int> in;
vector<int> pre;
vector<int> post;

void preorder(Node *r) {
    if (r == nullptr)
        return;
    pre.push_back(r->val);
    inorder(r->left);
    inorder(r->right);
}


void inorder(Node *r) {
    if (r == nullptr)
        return;
    inorder(r->left);
    in.push_back(r->val);
    inorder(r->right);
}

void postorder(Node *r) {
    if (r == nullptr)
        return;
    inorder(r->left);
    inorder(r->right);
    post.push_back(r->val);
}