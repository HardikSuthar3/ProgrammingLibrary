#include "BinaryTreeStructure.h"

bool isIdentical(Node *first, Node *second) {
    if (first == nullptr && second == nullptr)
        return true;
    else if ((first == nullptr && second != nullptr) || (first != nullptr && second == nullptr))
        return false;
    else if (first->val != second->val)
        return false;
    else
        return true;
}