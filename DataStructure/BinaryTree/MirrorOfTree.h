#include "BinaryTreeStructure.h"

void mirror(Node *r) {
    if (r == nullptr)
        return;
    mirror(r->left);
    mirror(r->right);
    swap(r->left, r->right);
}