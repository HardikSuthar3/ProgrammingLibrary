#include "Graph_Structure.h"

vector<int> bfs(int r) {

    queue<int> q;
    q.push(r);

    vector<int> res;
    used[r] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (int i = 0; i < G[v].size(); i++) {
            int eno = G[v][i];
            int adj = edges[eno].first ^edges[eno].second ^v;
            if (used[adj] == false) {
                used[adj] = true;
                q.push(adj);
            }
        }
    }

    return res;
}