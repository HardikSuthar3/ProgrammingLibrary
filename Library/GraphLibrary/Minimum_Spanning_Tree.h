#include "Graph_Structure.h"

// Minimum Spanning Tree

vector<int> primMst(int r) {
    vector<int> dist(V);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[r] = 0;

    function<bool(int &, int &)> compare([&](int &u, int &v) -> bool { return (dist[u] > dist[v]); });

    priority_queue<int, vector<int>, decltype(compare)> ind(compare);

    ind.push(r);

    long total_distance = 0;

    used[root] = true;
    while (!ind.empty()) {
        int u = ind.top();
        ind.pop();

        total_distance += dist[u];
        for (int i = 0; i < G[u].size(); ++i) {
            int eno = G[u][i];
            pair<int, int> p = edges[eno];
            int adj = p.first ^p.second ^u;
            float w = W[eno].second;
            if (dist[adj] > dist[u] + w) {
                dist[adj] = w;
                if (used[adj] == false) {
                    ind.push(adj);
                    used[adj] = true;
                }
            }
        }
    }
    return dist;
}

void krushkalsMst() {
    function<bool(pair<int, float> &, pair<int, float> &)>
            compare([](pair<int, float> &x, pair<int, float> &y) -> bool { return (x.second < y.second); });


    UFinit(V);

    sort(W.begin(), W.end(), compare);
    int vc = 0;
    int i = 0; // Number of Edges in solution

    vector<pair<int, int>> op;
    vector<float> we;
    while (i < V) {
        int eid = W[i].first;
        if (Find(edges[eid].first) != Find(edges[eid].second)) {
            Union(edges[eid].first, edges[eid].second);
            op.push_back(edges[eid]);
            we.push_back(W[i].second);
            if (used[edges[eid].first] == false) {
                vc++;
                used[edges[eid].first] = true;
            }
            if (used[edges[eid].second] == false) {
                vc++;
                used[edges[eid].second] = true;
            }
        }
        i++;

    }

    for (int i = 0; i < op.size(); i++) {
        cout << op[i].first << " " << op[i].second << ": " << we[i] << endl;
    }
}
