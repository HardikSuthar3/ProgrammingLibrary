#include <bits/stdc++.h>
using namespace std;

// Graph Structure
int V, E, root;
vector<int> G[10001];
vector<pair<int, int> > edges;
vector<pair<int, int> > W;
int *par;
bool *used;
// End Structure




// Common Function

void UFinit(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
}

void MakeGraph(int n, int m) {
    V = n;
    E = m;

    par = new int[n];
    used = new bool[n];
    fill(par, par + n + 1, -1);
    fill(used, used + n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v, w, x;
        cin >> u >> v >> x;
        G[u].push_back(i);

//         comment below to make directed graph
        G[v].push_back(i);

        edges.push_back(make_pair(u, v));
        if (x == 1) {
            cin >> w;

        } else {
            w = 0;
        }
        W.push_back(make_pair(i, w));
    }
}

void ClearGraph() {
    delete[]par;
    delete[] used;
    for (int i = 0; i < V; i++) {
        G[i].clear();

    }
    edges.clear();
    W.clear();
    V = E = root = -1;
}

int Find(int x) {
    if (par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y) {
    int xp, yp;
    xp = Find(x);
    yp = Find(y);
    par[yp] = xp;
}

// Common Function End


/*bool compare(pair<int, float> &x, pair<int, float> &y) {
    return (x.second < y.second);
}*/



class Comparator {
 public:
    bool operator()(int &u, int &v) {
        return (dist[u] > dist[v]);
    }
} comparator;



int main() {
    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/input.txt", "r", stdin);


    // Input Begin
        int n, m;
        cin >> n >> m;
        MakeGraph(n + 1, m);
    // Input End


    // Sol Begin
    primMst(1);
    // Sol End



    return 0;

}