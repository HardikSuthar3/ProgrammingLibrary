#include "Graph_Structure.h"

vector<int> dfs(int v)
{
    static vector<int> path;
    if (used[v])
    {
        return path;
    }
    used[v] = true;
    path.push_back(v);
    for (int i = 0; i < G[v].size(); i++)
    {
        int edgeNo = G[v][i];
        int x = edges[edgeNo].first;
        int y = edges[edgeNo].second ^ v;
        //        int adjV = edges[edgeNo].first ^edges[edgeNo].second ^i;

        int adjV = x ^ y;
        if (!used[adjV])
        {
            dfs(adjV);
        }
    }
    return path;
}