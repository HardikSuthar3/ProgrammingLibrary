#include "../TEMPLATE.h"

#define btn BTNode*

class BTNode {
 public:
    int val;
    BTNode *l, *r;
    BTNode *par;
    bool used;
    BTNode(int v) {
        this->val = v;
        l = nullptr;
        r = nullptr;
        par = nullptr;
        used = false;
    }
};

class BT {
 private:
    int _diameter(btn root, int *h) {
        if (root == nullptr) {
            *h = 0;
            return 0;
        }

        int lh = 0, rh = 0;
        int ld = 0, rd = 0;
        ld = _diameter(root->l, &lh);
        rd = _diameter(root->r, &rh);
        *h = max(lh, rh) + 1;

        return max(lh + rh + 1, max(ld, rd));
    }
 public:
    map<int, btn> V;
    btn root;
    BT(int r) {
        root = new BTNode(r);
        V.insert(mp(r, root));
    }

    void Add(int root, int l, int r) {
        btn A;
        btn B;
        btn C;
        if (V.find(root) != V.end()) {
            B = V.at(root);
        } else {
            B = new BTNode(root);
            V.insert(mp(root, B));
        }
        if (V.find(l) != V.end()) {
            A = V.at(l);
        } else {
            if (l == -1)
                A = nullptr;
            else {
                A = new BTNode(l);
                V.insert(mp(l, A));
            }
        }

        if (V.find(r) != V.end()) {
            C = V.at(r);
        } else {
            if (r == -1)
                C = nullptr;
            else {
                C = new BTNode(r);
                V.insert(mp(r, C));
            }
        }
        B->l = A;
        B->r = C;
    }

    int Height(btn root) {
        if (root == nullptr)
            return 0;
        return (max(Height(root->l), Height(root->r)) + 1);
    }

    int Diameter(btn root) {
        int lh = 0, rh = 0;
        int ld = 0, rd = 0;
        ld = _diameter(root->l, &lh);
        rd = _diameter(root->r, &rh);
        return max(max(ld, rd), lh + rh + 1);
    }

    void inOrderWithThreadedBT() {
        if (root == nullptr)
            return;
        btn cur = root;
        while (cur != nullptr) {
            if (cur->l == nullptr) {
                cout << cur->val << " ";
                cur = cur->r;
            } else {
                btn pre = cur->l;
                while (pre->r != nullptr && pre->r != cur)
                    pre = pre->r;
                if (pre->r == nullptr) {
                    pre->r = cur;
                    cur = cur->l;
                } else {
                    pre->r = nullptr;
                    cout << cur->val << " ";
                    cur = cur->r;
                }

            }
        }
    }

    vector<int> DFS(btn root) {
        static vector<int> dfsst;
        if (root == nullptr)
            return dfsst;
        root->used = true;
        dfsst.push_back(root->val);
        if (root->l != nullptr && !root->l->used)
            DFS(root->l);
        if (root->r != nullptr && !root->r->used)
            DFS(root->r);

        return dfsst;
    }


    string inorder;
    queue<char> preorder;
    btn _tft(int i, int j) {
        if (i > j)
            return nullptr;
        char ch = preorder.front();
        preorder.pop();
        btn n = new BTNode(ch);
        int ind = inorder.find(ch);
        n->l = _tft(i, ind - 1);
        n->r = _tft(ind + 1, j);
        return n;
    }
    void TreeFromTraversals() {
        getline(cin, inorder);
        string po;
        getline(cin, po);
        REP(i, po.length()) {
            preorder.push(po[i]);
        }
        root = _tft(0, inorder.length() - 1);
        auto val = DFS(root);
        EACH(item, val) {
            cout << (char) item << " ";
        }
    }
};

