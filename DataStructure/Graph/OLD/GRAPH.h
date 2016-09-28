#include "../../../Library/TEMPLATE.h"

class Edge;


class Node {

 public:
    int val;
    int col;
    float d;


    bool used;

    vector<Node *> adjNode;
    vector<Edge *> adje; // Adjcent Edge


    Node *par;
    Node *upar;

    bool operator==(const Node &rhs) const {
        return this->val == rhs.val;
    }
    bool operator!=(const Node &rhs) const {
        return this->val != rhs.val;
    }
    Node(int value) {
        this->val = value;
        this->used = false;
        this->par = nullptr;
        this->d = 0;
        this->upar = this;
    }

};

class Edge {
 public:
    float w;
    Node *first, *second;
    bool used;
    Edge(Node *from, Node *to, float weight) {
        this->first = from;
        this->second = to;
        this->w = weight;
        this->used = false;
    }

};

class Graph {
 private:

    VI par;

 public:

    vector<Edge *> E;
    map<int, Node *> V;
    map<string, Edge *> edgeMap;


    stack<int> topologicalStack;


    Node *addNode(int val) {
        Node *n = new Node(val);
        if (V.find(val) != V.end()) {
            V[val] = n;
        } else {
            V.insert(mp(val, n));
        }
        return n;
    }


    void addEdge(int src, int dst) {
        addEdge(src, dst, 0);
    }
    void addEdge(int src, int dst, float weight) {

        Node *source, *dest;
        if (V.find(src) == V.end()) {
            source = addNode(src);
        } else {
            source = V.at(src);
        }

        if (V.find(dst) == V.end()) {
            dest = addNode(dst);
        } else {
            dest = V.at(dst);
        }

        Edge *edge = new Edge(source, dest, weight);
        E.pb(edge);
        source->adjNode.pb(dest);
        source->adje.pb(edge);
        edgeMap.insert(mp(to_string(source->val) + "," + to_string(dest->val), edge));
    }

    void addUndirectedEdge(int src, int dst, float weight) {

        Node *source, *dest;
        if (V.find(src) == V.end()) {
            source = addNode(src);
        } else {
            source = V.at(src);
        }

        if (V.find(dst) == V.end()) {
            dest = addNode(dst);
        } else {
            dest = V.at(dst);
        }

        Edge *edge = new Edge(source, dest, weight);
        E.pb(edge);
        source->adjNode.pb(dest);
        dest->adjNode.pb(source);
        edgeMap.insert(mp(to_string(source->val) + "," + to_string(dest->val), edge));
    }

    Edge *getEdge(Node *&a, Node *&b) {
        return edgeMap.at(to_string(a->val) + to_string(b->val));
    }

    Edge *getEdge(int a, int b) {
        return edgeMap.at(to_string(a) + to_string(b));
    }


    Node *Find(Node *x) {
        if (x->upar->val != x->val) {
            x->upar = Find(x->upar);
        }
        return x->upar;
    }

    void Union(Node *x, Node *y) {
        Node *xpar, *ypar;
        xpar = Find(x);
        ypar = Find(y);
        if (xpar->d > ypar->d) {
            ypar->upar = xpar;
        } else if (ypar->d > xpar->d) {
            xpar->upar = ypar;
        } else {
            ypar->upar = xpar;
            xpar->d++;
        }
    }

    /*void DFS(Node *root) {
        if (root == nullptr)
            return;
        root->used = true;
        cout << root->val << endl;
        FORIT(item, root->adjNode) {
            if ((*item)->used == false) {
                DFS(*item);
            }
        }
    }*/

    /*void BFS(Node *root) {
        queue<Node *, deque<Node * >> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()) {
            Node *u = bfsQueue.front();
            bfsQueue.pop();

            cout << u->val << endl;

            FORIT(item, u->adjNode) {
                (*item)->par = u;
                if ((*item)->used == false) {
                    (*item)->used = true;
                    (*item)->d = u->d + 1;
                    bfsQueue.push((*item));
                }

            }
        }
    }*/

    /*void ShortestPathBFS(Node *root, int val) {
        Node *node = _ShortestPathBFS(root, val);
        if (node != nullptr) {
            vector<int> path;
            while (node != nullptr) {
                path.pb(node->val);
                node = node->par;
            }
            reverse(path.begin(), path.end());
            cout << path;
        } else {
            cout << "NA";
        }
        cout << endl;
    }*/


};
