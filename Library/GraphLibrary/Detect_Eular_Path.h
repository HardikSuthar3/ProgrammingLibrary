#include "Graph_Structure.h"

void eularPath() {
    bool flag = true;
    // Check each vertice is of even degree
    vector<int> vertice;
    for (int i = 0; i < V; i++) {
        /*    if (G[i].size() % 2 == 1)
                flag = false;
            else {
                if (G[i].size() > 0) {
                    vertice.push_back(i);
                }
            }*/

        if (G[i].size() > 0) {
            vertice.push_back(i);
        }
    }

    int u = vertice.front();
    dfs(u);
    int c = 0;
    for (int i = 0; i < vertice.size(); i++) {
        u = vertice[i];
        if (used[u] == false) {
            c++;
        }
    }
    if (c > 0)
        cout << "Eular Path Does Not Exist";
    else {
        cout << "Eular Path Does Exist";
    }
}