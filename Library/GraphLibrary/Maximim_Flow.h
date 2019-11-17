#include "Graph_Structure.h"


// Maximum Flow Graph

int **graph2Mat() {
    int **mat = new int *[V];
    for (int i = 0; i < V; i++) {
        mat[i] = new int[V];
        fill(mat[i], mat[i] + V, 0);
    }

    for (int i = 0; i < edges.size(); ++i) {
        pair<int, int> p = edges.at(i);
        mat[p.first][p.second] = W[i].second;
    }
    return mat;
}

bool bfsMaxFlow(int **res, int s, int t) {
    par = new int[V];
    fill(par, par + V, -1);
    used = new bool[V];
    fill(used, used + V, false);
    used[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < V; i++) {
            if (i == u)
                continue;
            if (used[i] == false && res[u][i] > 0) {
                par[i] = u;
                used[i] = true;
                q.push(i);
            }
        }
    }
    return (used[t] == true);
}

int maxFlow() {
    int **mat = graph2Mat();
    int **res = new int *[V];
    for (int i = 0; i < V; i++) {
        res[i] = new int[V];
        for (int j = 0; j < V; j++) {
            res[i][j] = mat[i][j];
        }
    }

    int max_flow = 0;
    int s = 0, t = 5;

    while (bfsMaxFlow(res, s, t)) {
        int mincost = INT_MAX;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            mincost = min(mincost, res[u][v]);
        }
        max_flow += mincost;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            res[u][v] -= mincost;
            res[v][u] += mincost;
        }
    }

    return max_flow;
}