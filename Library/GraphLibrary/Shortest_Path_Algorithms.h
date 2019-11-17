#include "Graph_Structure.h"


// Shortest Path Algorithms

vector<float> dijkastra(int src) {
    vector<int> q;

    vector<float> dist(V);
    fill(dist.begin(), dist.end(), FLT_MAX);
    dist[src] = 0;
    q.push_back(src);

    // Declare Comparator
    function<bool(int &, int &)> comparator(
            [&](int &a, int &b) -> bool {
                return dist[a] > dist[b];
            }
    );


    bool flag = false;
    while (!q.empty()) {
/*
        auto it = min_element(q.begin(), q.end(), comparator);
        int u = *it;
        q.erase(it);
*/

        pop_heap(q.begin(), q.end(), comparator);
        int u = q.back();
        q.pop_back();

        used[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            int eid = G[u][i];
            int adj = edges[eid].first ^edges[eid].second ^u;
            if (dist[adj] > dist[u] + W[eid].second) {
                dist[adj] = dist[u] + W[eid].second;
                q.push_back(adj);
                par[adj] = u;
                push_heap(q.begin(), q.end(), comparator);
            }
        }
    }

    return dist;
}

vector<float> bellmanFord(int src) {
    vector<float> dist(V);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            int eno = G[i][j];
            pair<int, int> p = edges[eno];
            int adj = p.first ^p.second ^i;
            float w = W[eno].second;
            if (dist[adj] > dist[i] + w) {
                dist[adj] = dist[i] + w;
            }
        }
    }
    return dist;
}


//All Pair shortest Path

float **floydWarshall() {
    float **dist = new float *[V];
    for (int i = 0; i < V; i++) {
        dist[i] = new float[V];
        fill(dist[i], dist[i] + V, FLT_MAX);
        dist[i][i] = 0;
    }
    for (int i = 0; i < edges.size(); i++) {
        pair<int, int> p = edges[i];
        int u = p.first;
        int v = p.second;
        dist[u][v] = W[i].second;
    }


    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            for (int k = 0; k < V; k++) {
                if (dist[u][v] > dist[u][k] + dist[k][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
    return dist;
}