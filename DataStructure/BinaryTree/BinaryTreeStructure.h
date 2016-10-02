#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009


class Node {
 public:
    long val;
    Node *left;
    Node *right;
    bool visited;
    Node *par;


    Node(int v) {
        this->val = v;
        this->par = nullptr;
        this->right = nullptr;
        this->left = nullptr;
        this->visited = false;

    }
};

Node *root;
map<int, Node *> nodes;

void addNode(int s, int l, int r) {
    Node *S;
    if (nodes.find(s) == nodes.end()) {
        S = new Node(s);
    } else {
        S = nodes[s];
    }
    Node *left = new Node(l);
    Node *right = new Node(r);
    S->left = left;
    S->right = right;
}

