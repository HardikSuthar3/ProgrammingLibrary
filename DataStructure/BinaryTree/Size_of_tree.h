#include <BinaryTreeStructure.h>

int size(Node *r) {
    if (r == nullptr)
        return 0;
    return 1 + size(r->left) + size(r->right);

}