#include "Graph_Structure.h"

vector<int> shortestPathBFS(int r, int to) {
    queue<int> q;
    q.push(r);

    fill(par, par + 1000, -1);
    used[r] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int eno = G[v][i];
            int adj = edges[eno].first ^edges[eno].second ^v;

            par[adj] = v;

            if (adj == to) {
                queue<int> empty;
                swap(q, empty);
//                while (!q.empty()) q.pop();
                break;
            }

            if (used[adj] == false) {
                used[adj] = true;
                q.push(adj);
            }
        }
    }
    vector<int> res;
    while (to != -1) {
        res.push_back(to);
        to = par[to];
    }
    reverse(res.begin(), res.end());
    return res;
}