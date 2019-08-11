#include <bits/stdc++.h>

using namespace std;

// Graph Structure
int V, E, root;
vector<int> G[1001];
vector<pair<int, int>> edges;
vector<pair<int, float>> W;
int *par;
bool *used;
// End Structure

// Common Function

void UFinit(int n)
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
    }
}

void MakeGraph(int n, int m)
{
    V = n;
    E = m;

    par = new int[n];
    used = new bool[n];
    fill(par, par + n + 1, -1);
    fill(used, used + n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(i);

        //         comment below to make directed graph
        //        G[v].push_back(i);

        edges.push_back(make_pair(u, v));
        W.push_back(make_pair(i, w));
    }
}

void PrintGraph()
{
    cout << "Nodes" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < G[i].size(); j++)
        {
            int eid = G[i][j];
            auto x = edges[eid];
            int adj = x.first ^ x.second ^ i;
            cout << adj << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    cout << "Edges" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].first << " " << edges[i].second << ": " << W[i].second << endl;
    }
}

void ClearGraph()
{
    delete[] par;
    delete[] used;
    for (int i = 0; i < V; i++)
    {
        G[i].clear();
    }
    edges.clear();
    W.clear();
    V = E = root = -1;
}

void TransposeGraph()
{
    for (int i = 0; i < V; i++)
    {
        G[i].clear();
    }
    for (int i = 0; i < E; i++)
    {
        swap(edges[i].first, edges[i].second);
        G[edges[i].first].push_back(i);

        // Uncommnet if Undirected Graph
        G[edges[i].second].push_back(i);
    }
}

int Find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    int xp, yp;
    xp = Find(x);
    yp = Find(y);
    par[yp] = xp;
}

// Common Function End