#include "Graph_Structure.h"


vector<int> dfs(int v) {
    static vector<int> path;
    if (used[v]) {
        return path;
    }
    used[v] = true;
    path.push_back(v);
    for (int i = 0; i < G[v].size(); i++) {
        int edgeNo = G[v][i];
        int x = edges[edgeNo].first;
        int y = edges[edgeNo].second ^v;
        //        int adjV = edges[edgeNo].first ^edges[edgeNo].second ^i;

        int adjV = x ^y;
        if (!used[adjV]) {
            dfs(adjV);
        }
    }
    return path;
}

void topologicalDfs(int v, vector<int> &topst) {
    if (used[v]) {
        return;
    }
    used[v] = true;

    for (int i = 0; i < G[v].size(); i++) {
        int edgeNo = G[v][i];
        int x = edges[edgeNo].first;
        int y = edges[edgeNo].second ^v;
        //        int adjV = edges[edgeNo].first ^edges[edgeNo].second ^i;
        int adjV = x ^y;

        if (!used[adjV]) {
            topologicalDfs(adjV, topst);
        }
    }
    topst.push_back(v);

    return;
}
vector<int> topologicalSort(int r) {
    vector<int> topOrder;
    for (int i = 0; i < V; i++) {
        if (used[i] == false) {
            topologicalDfs(i, topOrder);
        }
    }
    reverse(topOrder.begin(), topOrder.end());
    return topOrder;
}

vector<int> connectedComponents() {
    vector<int> top = topologicalSort(0);
    TransposeGraph();
    fill(used, used + V, false);
    vector<int> comp;
    for (int i = 0; i < V; i++) {
        int u = top[i];
        if (used[u] == false) {
            dfs(u);
            comp.push_back(u);
        }
    }
    return comp;
}