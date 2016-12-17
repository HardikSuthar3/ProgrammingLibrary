#include <bits/stdc++.h>
using namespace std;
vector<int> G[100];
vector<pair<int, pair<int, int>>> edges;
vector<int> par(100);
vector<bool> used(100);
int V;

int find(int x) {
    if(par[x] == x) {
        return x;
    } else {
        return (par[x] = find(par[x]));
    }
}

void Union(int x, int y) {
    int xpar = find(x);
    int ypar = find(y);
    par[y] = xpar;
}

void MakeGraph(int n, int m) {
    V = n;
    for(int i = 0; i <= V; i++) {
        par[i] = i;
    }
    fill(used.begin(), used.begin() + V, false);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        auto edge = make_pair(w, make_pair(u, v));
        edges.push_back(edge);
        G[u].push_back(i);
        G[v].push_back(i);
    }
}

void BFS(int s) {
    vector<int> bfsOrder;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        bfsOrder.push_back(u);
        q.pop();
        used[u] = true;
        for(int i = 0; i < G[u].size(); i++) {
            int E = G[u][i];
            auto edge = edges[E];
            int v = edge.second.first ^edge.second.second ^u;
            if(!used[v]) {
                q.push(v);
            }
        }
    }
    for(auto &item : bfsOrder) {
        cout << item << " ";
    }
}

void DFS_util(int s, vector<int> &dfsOrder) {
    if(used[s]) {
        return;
    }
    used[s] = true;
    dfsOrder.push_back(s);
    for(int i = 0; i < G[s].size(); i++) {
        int E = G[s][i];
        auto item = edges[E];
        int v = item.second.first ^item.second.second ^s;
        DFS_util(v, dfsOrder);
    }
}

void DFS(int s) {
    vector<int> dfsOrder;
    for(int i = 0; i < V; i++) {
        if(!used[i]) {
            DFS_util(i, dfsOrder);
        }
    }
    for(auto &&item : dfsOrder) {
        cout << item << " ";
    }
}

void top_util(int s, vector<int> &topOrder) {
    if(used[s]) {
        return;
    }
    used[s] = true;
    for(int i = 0; i < G[s].size(); i++) {
        top_util(s, topOrder);
    }
    topOrder.push_back(s);
}

void topologicalSort() {
    vector<int> topOrder;
    for(int i = 0; i < V; i++) {
        if(!used[i]) {
            top_util(i, topOrder);
        }
    }
    reverse(topOrder.begin(), topOrder.end());
}

int main() {
    int n;
    n = 1e3;
    cout << n << endl;
    return 0;
}
