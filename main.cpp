#include<bits/stdc++.h>

using namespace std;

int V;

bool BFS(vector<vector<int>> &res, int s, int t, vector<int> &par) {
    vector<bool> used(V + 1, false);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
//        cout << u << " ";
        q.pop();
        used[u] = true;
        for (int i = 1; i <= V; i++) {
            if (res[u][i] != 0 && used[i] == false) {
                q.push(i);
                par[i] = u;
            }
        }
    }
//    cout << endl;
    return used[t];
}

int main() {
//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    V = n;
    vector<vector<int>> G(n + 1, vector<int>(n + 1, 0));

    vector<vector<int>> res(G);
    //copy(G.begin(), G.end(), res.begin());

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x][y] += w;
        G[y][x] += w;
        res[x][y] += w;
        res[y][x] += w;
    }

    vector<int> par(n + 1, -1);


    bool flag = BFS(res, 1, n, par);

    int t = n;
    long long total = 0;
    while (BFS(res, 1, t, par)) {
        long long minflow = INT_MAX;
        for (int i = t; par[i] != -1; i = par[i]) {
            int u = par[i];
            minflow = min(minflow, (long long)res[u][i]);
        }

        total += minflow;

        for (int v = t; par[v] != -1; v = par[v]) {
            int u = par[v];
            res[u][v] -= minflow;
            res[v][u] += minflow;
        }
    }

    cout << total;
    return 0;
}
