#include "BinaryTreeStructure.h"

int height(Node *r) {
    if (r == nullptr)
        return 0;
    else
        return 1 + max(height(r->left), height(r->right));
}