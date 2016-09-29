#include <BinaryTreeStructure.h>


vector<int> dfs(Node *r) {
    static vector<int> dfsOrder;
    if (r == nullptr)
        return dfsOrder;
    dfsOrder.push_back(r->val);
    dfs(r->left);
    dfs(r->right);
    return dfsOrder;
}

vector<int> bfs(Node *r) {
    vector<int> bfsOrder;
    queue<Node *> q;
    if (r == nullptr)
        return bfsOrder;

    q.push(r);

    r->visited = true;
    while (!q.empty()) {
        Node *u = q.front();
        q.pop();
        if (u->left != nullptr && !u->left->visited) {
            q.push(u->left);
            u->left->visited = true;
        }
        if (u->right != nullptr && !u->right->visited) {
            q.push(u->right);
            u->right->visited = true;
        }
    }

    return bfOrder;
}