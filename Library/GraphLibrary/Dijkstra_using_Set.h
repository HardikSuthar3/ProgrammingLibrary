#include <bits/stdc++.h>

using namespace std;

#define  MAX 1000000000

vector<int> G[3001];
vector<pair<int, pair<int, int>>> edges;
vector<bool> used(3001, false);
int V = 10;

void MakeGraph(int n, int m) {
    V = n;
    fill(used.begin(), used.begin() + V, false);

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        auto p = make_pair(x, y);
        auto item = make_pair(w, p);
        edges.push_back(item);
        G[x].push_back(i);
        G[y].push_back(i);
    }
}

void dijkstra(int s) {
    vector<long> dist(V + 1, INT_MAX);
    dist[s] = 0;
    set<pair<long, int>> q;
    q.insert(make_pair(dist[s], s));

    while (!q.empty()) {
        auto it = *(q.begin());
        int u = it.second;
        q.erase(q.begin());

        if (used[u]) {
            continue;
        }
        used[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            int E = G[u][i];
            auto item = edges[E];
            auto p = item.second;

            int v = p.first ^p.second ^u;
            if (v == 4) {
                int t = 0;
            }

            if (dist[v] > dist[u] + item.first) {
                auto tmp = pair<int, int>(dist[v], v);
                q.erase(tmp);
                dist[v] = dist[u] + item.first;

                tmp.first = dist[v];
                q.insert(tmp);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (i == s) {
            continue;
        }
        if (dist[i] == INT_MAX) {
            cout << -1 << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
}

void clearGraph() {
    fill(used.begin(), used.begin() + V + 1, false);
    for (int i = 0; i <= V; i++) {
        G[i].clear();
    }
    edges.clear();
}

void PrintGraph() {
    cout << "Nodes" << endl;
    for (int i = 0; i <= V; i++) {
        cout << i << " : ";
        for (int j = 0; j < G[i].size(); j++) {
            int eid = G[i][j];
            auto x = edges[eid].second;
            int adj = x.first ^x.second ^i;
            cout << adj << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "Edges" << endl;
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].second.first << " " << edges[i].second.second << ": " << edges[i].first << endl;
    }
}

int main2() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        MakeGraph(n, m);
        int s;
        std::cin >> s;
        dijkstra(s);
        cout << endl;
        clearGraph();
    }
    return 0;
}

