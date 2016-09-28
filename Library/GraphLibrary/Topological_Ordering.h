#include "Graph_Structure.h"

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