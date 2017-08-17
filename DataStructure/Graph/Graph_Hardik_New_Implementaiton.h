#include <bits/stdc++.h>
using namespace std;

#define MAX_Vertice 100

vector<long> G[MAX_Vertice];
vector<pair<long, long >> edgeList;
vector<pair<long, long>> weight;

vector<long> parent(MAX_Vertice, -1);
vector<bool> used(MAX_Vertice, false);
vector<long> dist(MAX_Vertice, -1);

int noOfVertices = 0, noOfEdges = 0;

// Graph Creation Module
void makeGraph(int V, int E) {
    noOfVertices = V;
    noOfEdges = E;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back((long) i);
        G[v].push_back((long) i);

        edgeList.push_back(make_pair(u, v));
        weight.push_back(make_pair(i, w));
    }
}

void printGraph() {
    cout << "Nodes" << endl;
    for (int i = 1; i <= noOfVertices; i++) {
        cout << i << " : ";
        for (int j = 0; j < G[i].size(); j++) {
            int edgeId = G[i][j];
            auto item = edgeList[edgeId];
            int neighb = item.first ^item.second ^i;
            cout << neighb << " ";
        }
        cout << endl;
    }

    cout << endl << endl << "Edges";
    for (int i = 0; i < noOfEdges; i++) {
        auto item = edgeList[i];
        int u = item.first;
        int v = item.second;
        int w = weight[i].second;
        cout << "(" << u << "," << v << ") : " << w << endl;
    }
}

void ClearGraph() {
    fill(parent.begin(), parent.begin() + noOfVertices + 1, -1);
    fill(used.begin(), used.begin() + noOfVertices + 1, false);
    fill(dist.begin(), dist.begin() + noOfVertices + 1, -1);

    edgeList.clear();
    weight.clear();
    for (int i = 0; i < noOfVertices; ++i) {
        G[i].clear();
    }

    noOfVertices = noOfEdges = 0;
}
// End:- Graph Creation Module

// Union Find Module Starts
void UnioFindInit(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int Find(int x) {
    if (parent[x] == x)
        return x;
    return Find(parent[x]);
}

void Union(int x, int y) {
    int parX, parY;
    parX = Find(x);
    parY = Find(y);
    parent[y] = parX;
}
//End:- Union Find Module Ends


// Graph Traversal Operations
vector<long> DFS(long u) {
    static vector<long> path;
    if (used[u]) {
        return path;
    }
    used[u] = true;
    path.push_back((long) u);

    for (int i = 0; i < G[u].size(); i++) {
        int edgeId = G[u][i];
        auto item = edgeList[edgeId];
        int v = item.first ^item.second ^u;

        if (used[v] == false) {
            DFS(v);
        }
    }
    return path;
}

vector<long> BFS(long u) {
    vector<long> bfsOrder;

    if (used[u])
        return bfsOrder;

    queue<long> q;
    used[u] = true;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        bfsOrder.push_back(u);
        for (int i = 0; i < G[u].size(); i++) {
            long edgeId = G[u][i];
            auto item = edgeList[edgeId];
            auto v = item.first ^item.second ^u;
            if (used[v] == false) {
                q.push(v);
                used[v] = true;
            }
        }
    }

    return bfsOrder;
}
// End:- Graph Traversal Operations
