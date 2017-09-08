#include <bits/stdc++.h>

using namespace std;

#define MAX_Vertice 200

vector<int> G[MAX_Vertice];
vector<pair<int, int >> edgeList;
vector<pair<int, int>> weight;
vector<int> parent(MAX_Vertice, -1);
vector<bool> used(MAX_Vertice, false);
vector<int> dist(MAX_Vertice, -1);
vector<int> inDegree(MAX_Vertice, 0);
vector<int> outDegree(MAX_Vertice, 0);

int noOfVertices = 0, noOfEdges = 0;

// Graph Creation Module
void makeGraph(int V, int E) {
    noOfVertices = V;
    noOfEdges = E;
    for (int i = 0; i < E; ++i) {
        int u, v, w;

        // Weighted
        cin >> u >> v >> w;
        G[u].push_back((int) i);
//        G[v].push_back((int) i);
        edgeList.push_back(make_pair(u, v));
        weight.push_back(make_pair(i, w));

        /*// Unweighted
        cin >> u >> v;
        G[u].push_back(i);
        G[v].push_back(i);
        edgeList.push_back(make_pair(u, v));
        weight.push_back(make_pair(i, 0));*/
    }
}

void printGraph() {
    cout << "Nodes" << endl;
    for (int i = 0; i < noOfVertices; i++) {
        cout << i << " : ";
        for (int j = 0; j < G[i].size(); j++) {
            int edgeId = G[i][j];
            auto item = edgeList[edgeId];
            int neighb = item.first ^item.second ^i;
            cout << neighb << " ";
        }
        cout << endl;
    }

    cout << endl << endl << "Edges";
    for (int i = 0; i < noOfEdges; i++) {
        auto item = edgeList[i];
        int u = item.first;
        int v = item.second;
        int w = weight[i].second;
        cout << "(" << u << "," << v << ") : " << w << endl;
    }
}

void ClearGraph() {
    fill(parent.begin(), parent.begin() + noOfVertices + 1, -1);
    fill(used.begin(), used.begin() + noOfVertices + 1, false);
    fill(dist.begin(), dist.begin() + noOfVertices + 1, -1);

    edgeList.clear();
    weight.clear();
    for (int i = 0; i <= noOfVertices; ++i) {
        G[i].clear();
    }

    noOfVertices = noOfEdges = 0;
}

int getAdjecent(int u, int i) {
    int edgeId = G[u][i];
    auto item = edgeList[edgeId];
    int adjecent = item.first ^item.second ^u;
    return adjecent;
}
// End:- Graph Creation Module

// Union Find Module Starts
void UnioFindInit(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int Find(int x) {
    if (parent[x] == x)
        return x;
    return Find(parent[x]);
}

void Union(int x, int y) {
    int parX, parY;
    parX = Find(x);
    parY = Find(y);
    parent[y] = parX;
}
//End:- Union Find Module Ends

// Graph Traversal Operations
vector<int> DFS(int u) {
    static vector<int> path;
    if (used[u]) {
        return path;
    }
    used[u] = true;
    path.push_back((int) u);

    for (int i = 0; i < G[u].size(); i++) {
        int edgeId = G[u][i];
        auto item = edgeList[edgeId];
        int v = item.first ^item.second ^u;

        if (used[v] == false) {
            DFS(v);
        }
    }
    return path;
}

vector<int> BFS(int u) {
    vector<int> bfsOrder;

    if (used[u])
        return bfsOrder;

    queue<int> q;
    used[u] = true;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        bfsOrder.push_back(u);
        for (int i = 0; i < G[u].size(); i++) {
            int edgeId = G[u][i];
            auto item = edgeList[edgeId];
            auto v = item.first ^item.second ^u;
            if (used[v] == false) {
                q.push(v);
                used[v] = true;
            }
        }
    }

    return bfsOrder;
}

vector<int> shortestPathBFS(int from, int to) {
    vector<int> path;
    if (from == to) {
        return path;
    }

    queue<int> q;
    q.push(from);
    used[from] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        path.push_back(u);
        for (int i = 0; i < G[u].size(); i++) {
            int edgeId = G[u][i];
            auto item = edgeList[edgeId];
            int v = item.first ^item.second ^u;

            if (used[v] == false) {
                used[v] = true;
                q.push(v);
            }
            if (v == to) {
                path.push_back(v);
                return path;
            }
        }
    }
    return vector<int>();
}

void topologicalUtil(int from, vector<int> &path) {
    if (used[from])
        return;

    used[from] = true;
    int u = from;

    for (int i = 0; i < G[u].size(); i++) {
        /*int edgeId = G[u][i];
        auto item = edgeList[edgeId];
        int v = item.first ^item.second ^u;*/

        int v = getAdjecent(u, i);

        if (used[v] == false) {
            topologicalUtil(v, path);
        }
    }
    path.push_back(from);
    return;
}

vector<int> TopologicalSort(int from) {
    static vector<int> path;
    topologicalUtil(from, path);
    for (int i = 1; i < noOfVertices; i++) {
        if (used[i] == false) {
            topologicalUtil(i, path);
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

/// Topological sort for Directed Acyclic Graph
/// \param from Starting Vertice
/// \return Toplogical ordering
vector<int> TopologicalSort2(int from) {
    fill(inDegree.begin(), inDegree.begin() + noOfVertices + 1, 0);
    queue<int> processed;
    vector<int> result;

    // Mark the indegree
    for (int j = 0; j < noOfVertices; j++) {
        for (int i = 0; i < G[j].size(); i++) {
            int adj = getAdjecent(j, i);
            inDegree[adj]++;
        }
    }


    // Toplogical Order

    int processedCount = 0;

    for (int i = 0; i < noOfVertices; ++i) {
        if (inDegree[i] == 0) {
            processed.push(i);
            used[i] = true;
        }
    }

    while (!processed.empty()) {
        int u = processed.front();
        processed.pop();
        result.push_back(u);

        for (int i = 0; i < G[u].size(); i++) {
            int adj = getAdjecent(u, i);
            inDegree[adj]--;
            if (inDegree[adj] == 0 && used[adj] == false) {
                processed.push(adj);
                used[adj] = true;
            }
        }
    }

    return result;
}

vector<pair<int, int>> LongestDistanceInDirectedAcyclicGraph(int start) {
    auto topologicalPath = TopologicalSort(start);
    fill(dist.begin(), dist.begin() + noOfVertices + 1, -1);
    dist[start] = 0;
    for (auto &u : topologicalPath) {
        for (int i = 0; i < G[u].size(); i++) {
            int edgeId = G[u][i];
            auto item = edgeList[edgeId];
            int v = item.first ^item.second ^u;

            int w = weight[edgeId].second;
            dist[v] = max(dist[v], dist[u] + w);
        }
    }

    vector<pair<int, int>> result;

    for (auto &u:topologicalPath) {
        result.push_back(make_pair(u, dist[u]));
    }

    return result;
}

// End:- Graph Traversal Operations

/// Detect Cycle for Undirected Graph
/// \return Boolean Value
bool isCyclePresent() {
    UnioFindInit(noOfVertices);

    for (auto &item:edgeList) {
        int u = item.first;
        int v = item.second;

        if (Find(u) == Find(v)) {
            return true;
        }
        Union(u, v);
    }

    return false;
}

int main() {
    freopen("C:\\Users\\hasuthar\\CLionProjects\\ProgrammingLibrary\\input.txt",
            "r", stdin);
    freopen("C:\\Users\\hasuthar\\CLionProjects\\ProgrammingLibrary\\output.txt",
            "w", stdout);
    int n, m;
    cin >> n >> m;
    makeGraph(n, m);

    return 0;
}