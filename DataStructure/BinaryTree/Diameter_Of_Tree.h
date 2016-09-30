#include <BinaryTreeStructure.h>


///
/// \param r : Input Node
/// \param h : Height of a tree starting from node 'r'
/// \return : diameter of a tree
int _diameter(Node *r, int &h) {
    if (r == nullptr) {
        h = 0;
        return 0;
    }
    int lh, rh;
    int ld, rd;
    lh = rh = ld = rd = 0;
    ld = _diameter(r->left, lh);
    rd = _diameter(r->right, rh);

    h = max(lh, rh) + 1;

    return max(max(ld, rd), lh + rh + 1);

}

int diameter(Node *r) {
    int lh, rh;
    int ld, rd;
    lh = rh = ld = rd = 0;
    ld = _diameter(r->left, lh);
    rd = _diameter(r->right, rh);
    return max(max(ld, rd), lh + rh + 1);
}